// $Id: QuadSelector.cxx 26135 2014-02-05 21:17:19Z stahlman $

// Local include(s):
#include "../include/QuadSelector.h"
#include "../include/TriggerSelector.h"
#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Electron.h"
#include "Muon.h"
#include "Quadruplet.h"
#include "ParticleElementBuilder.h"

//CommonTools
#include "IDTool.h"

const float M_Z = 91187.6;
const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( QuadSelector );

QuadSelector::QuadSelector(SCycleBase* parent, const char* name)
  : ToolBase( parent, name ),
    cf_preselect(0),
    cf_SFOS(0),
    cf_kinematics(0),
    cf_trigger(0),
    cf_z1_mass(0),
    cf_z2_mass(0),
    cf_deltaR(0),
    cf_jpsi(0),
    cf_track_iso(0),
    cf_calo_iso(0),
    cf_d0_sig(0),
    cf_outside_blind(0)
{
  DeclareProperty( "DoFourMuon", 		m_doFourMuon = true );
  DeclareProperty( "DoFourElectron", 		m_doFourElectron = true );
  DeclareProperty( "DoTwoMuonTwoElectron", 	m_doTwoMuonTwoElectron = true );
  DeclareProperty( "DoTwoElectronTwoMuon", 	m_doTwoElectronTwoMuon = true );

  DeclareProperty( "DoTrkIsoCut",               m_doTrkIsoCut = true);

  DeclareProperty( "MuonTrkIsoConeSize",        m_muonTrkIsoConeSize = 20);
  DeclareProperty( "ElectronTrkIsoConeSize",    m_electronTrkIsoConeSize = 20);

  DeclareProperty( "MuonTrkIsoCut",	        m_muonTrkIsoCut = 0.15);
  DeclareProperty( "ElectronTrkIsoCut",         m_electronTrkIsoCut = 0.15);

  DeclareProperty( "DoCaloIsoCut",              m_doCaloIsoCut = true);

  DeclareProperty( "MuonCaloIsoConeSize",       m_muonCaloIsoConeSize = 20);
  DeclareProperty( "ElectronCaloIsoConeSize",   m_electronCaloIsoConeSize = 20);
  DeclareProperty( "ElectronCaloIsoSubConeSize",m_electronCaloIsoSubConeSize = 18);

  DeclareProperty( "MuonCaloIsoCut",	        m_muonCaloIsoCut = 0.30);
  DeclareProperty( "StandaloneMuonCaloIsoCut",  m_standaloneMuonCaloIsoCut = 0.15);
  DeclareProperty( "ElectronCaloIsoCut",        m_electronCaloIsoCut = 0.20);

  DeclareProperty( "DoD0SigCut",                m_doD0SigCut = true);

  DeclareProperty( "BlindSignalRegion",         m_doBlindSignalRegion = false);

  //Properties for Jet background studies
  DeclareProperty( "DoSecondPairSS",            m_doSecondPairSS = false);
  DeclareProperty( "DoSecondPairIso",           m_doSecondPairIso = true);
  DeclareProperty( "DoSecondPairDzero",         m_doSecondPairDzero = true);
  DeclareProperty( "DoSecondPairPassLikelihood", m_doSecondPairPassLikelihood = false);
  DeclareProperty( "DoOneOfSecondPairPassLikelihoodLoose", m_doOneOfSecondPairPassLikelihoodLoose = false);  
  DeclareProperty( "DoOneOfSecondPairPassLikelihoodLoose_BL_Pix", m_doOneOfSecondPairPassLikelihoodLoose_BL_Pix = false);
  DeclareProperty( "DoOneOfSecondPairPassLikelihoodLoose_BL_PixLow", m_doOneOfSecondPairPassLikelihoodLoose_BL_PixLow = false);
  DeclareProperty( "DoOneOfSecondPairPassLikelihoodLoose_BL_PixMed", m_doOneOfSecondPairPassLikelihoodLoose_BL_PixMed = false);
  DeclareProperty( "DoOneOfSecondPairPassLikelihoodLoose_BL_PixHigh", m_doOneOfSecondPairPassLikelihoodLoose_BL_PixHigh = false);
  DeclareProperty( "DoOneOfSecondPairPassLikelihood", m_doOneOfSecondPairPassLikelihood = false);
  DeclareProperty( "SecondPairLikelihood_OP",    m_SecondPairLikelihood_OP = "Loose");
  DeclareProperty( "DoSecondPairPassML",         m_doSecondPairPassML = false);
  DeclareProperty( "DoOneOfSecondPairPassML",         m_doOneOfSecondPairPassML = false);
  DeclareProperty( "SecondPairML_OP",            m_SecondPairML_OP = "Loose");
 
  DeclareProperty( "DoFirstPairPassID", m_doFirstPairPassID = false );
  DeclareProperty( "DoFirstPairPassML", m_doFirstPairPassML = false );
  DeclareProperty( "DoFirstPairPassML_HCP", m_doFirstPairPassML_HCP = false );
  DeclareProperty( "DoFirstPairLikelihoodMedium", m_doFirstPairPassLikelihoodMedium = false );
  DeclareProperty( "DoFirstPairLikelihoodLoose", m_doFirstPairPassLikelihoodLoose = false );
  DeclareProperty( "DoFirstPairPassLikelihoodLoose_BL_Pix", m_doFirstPairPassLikelihoodLoose_BL_Pix = false );
  DeclareProperty( "DoFirstPairPassLikelihoodLoose_BL_PixLow", m_doFirstPairPassLikelihoodLoose_BL_PixLow = false );
  DeclareProperty( "DoFirstPairPassLikelihoodLoose_BL_PixMed", m_doFirstPairPassLikelihoodLoose_BL_PixMed = false );
  DeclareProperty( "DoFirstPairPassLikelihoodLoose_BL_PixHigh", m_doFirstPairPassLikelihoodLoose_BL_PixHigh = false );
  DeclareProperty( "DoFirstPairPassLikelihood",  m_doFirstPairPassLikelihood = false);
  DeclareProperty( "FirstPairLikelihood_OP",     m_FirstPairLikelihood_OP = "Loose");

//other bools
  DeclareProperty( "DoBestBefore",     m_doBestBefore = true);
  DeclareProperty( "Pt3Cut",     m_pt3Cut = 10);
  DeclareProperty( "M34Cut",     m_M34Cut = 17.5);
  DeclareProperty( "M12Cut",     m_M12Cut = 50);
 
  static const double m34cut_m34_relaxed[] = { 12000,  30000,  35000,  40000,  50000 };
  //static const double m34cut_m34[] = { 17500,  30000,  35000,  40000,  50000 };
  //static const double m34cut_m4l[] = { 140000, 160000, 165000, 180000, 190000 };

  static const double m34cut_m34[] = {  12000,  50000 };
  static const double m34cut_m4l[] = { 140000, 190000 };
  
  v_m34cut_m34_relaxed = vector<double>(m34cut_m34_relaxed, m34cut_m34_relaxed + sizeof(m34cut_m34_relaxed) / sizeof(m34cut_m34_relaxed[0]) );
  v_m34cut_m34 = vector<double>(m34cut_m34, m34cut_m34 + sizeof(m34cut_m34) / sizeof(m34cut_m34[0]) );
  v_m34cut_m4l = vector<double>(m34cut_m4l, m34cut_m4l + sizeof(m34cut_m4l) / sizeof(m34cut_m4l[0]) );
  
  
  return;  
}

QuadSelector::~QuadSelector() {

 return;
}

void QuadSelector::EndMasterInputData( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                  H -> ZZ Quadruplet Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of quadruplets passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Events Before Cuts..........:"<<cf_preselect  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After SFOS...........:"<<cf_SFOS       <<" ("<<((double)cf_SFOS)/((double)cf_preselect)*100 <<"%)"  <<" ("<<((double)cf_SFOS)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After kinematics.....:"<<cf_kinematics <<" ("<<((double)cf_kinematics)/((double)cf_SFOS)*100 <<"%)"  <<" ("<<((double)cf_kinematics)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After trigger........:"<<cf_trigger    <<" ("<<((double)cf_trigger)/((double)cf_kinematics)*100 <<"%)"	<<" ("<<((double)cf_trigger)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Z1 Mass........:"<<cf_z1_mass    <<" ("<<((double)cf_z1_mass)/((double)cf_trigger)*100 <<"%)" <<" ("<<((double)cf_z1_mass)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Z2 Mass........:"<<cf_z2_mass    <<" ("<<((double)cf_z2_mass)/((double)cf_z1_mass)*100 <<"%)" <<" ("<<((double)cf_z2_mass)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After DeltaR.........:"<<cf_deltaR     <<" ("<<((double)cf_deltaR)/((double)cf_z2_mass)*100 <<"%)"  <<" ("<<((double)cf_deltaR)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After J/Psi..........:"<<cf_jpsi       <<" ("<<((double)cf_jpsi)/((double)cf_deltaR)*100 <<"%)"  <<" ("<<((double)cf_jpsi)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Track Iso......:"<<cf_track_iso  <<" ("<<((double)cf_track_iso)/((double)cf_jpsi)*100 <<"%)"  <<" ("<<((double)cf_track_iso)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Calo Iso.......:"<<cf_calo_iso   <<" ("<<((double)cf_calo_iso)/((double)cf_track_iso)*100 <<"%)"  <<" ("<<((double)cf_calo_iso)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After D0 Sig.........:"<<cf_d0_sig     <<" ("<<((double)cf_d0_sig)/((double)cf_calo_iso)*100 <<"%)"  <<" ("<<((double)cf_d0_sig)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  //m_logger << ALWAYS <<"Events After Blinding.......:"<<cf_outside_blind<<" ("<<((double)cf_outside_blind)/((double)cf_d0_sig)*100 <<"%)"  <<" ("<<((double)cf_outside_blind)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;

  return;

}

void QuadSelector::MakeQuadruplets( std::vector<Electron*> sel_electrons, std::vector<Muon*> sel_muons, std::vector<Quadruplet*> &all_quads ) {

  std::vector<Electron*> sel_electrons_pos;
  std::vector<Electron*> sel_electrons_neg;
  std::vector<Muon*> sel_muons_pos;
  std::vector<Muon*> sel_muons_neg;
  
  //seperate muons/electrons by charge
  for (unsigned int i = 0; i < sel_electrons.size(); i++){
    if (sel_electrons.at(i)->charge() == +1){
      sel_electrons_pos.push_back(sel_electrons.at(i));
    } else if (sel_electrons.at(i)->charge() == -1){
      sel_electrons_neg.push_back(sel_electrons.at(i));
    }
  }

  for (unsigned int i = 0; i < sel_muons.size(); i++){
    if (sel_muons.at(i)->charge() == +1){
      sel_muons_pos.push_back(sel_muons.at(i));
    } else if (sel_muons.at(i)->charge() == -1){
      sel_muons_neg.push_back(sel_muons.at(i));
    }
  }

  if(m_doSecondPairSS == false){

  //case: 4 electrons
  if (sel_electrons_pos.size() >= 2 && sel_electrons_neg.size() >= 2){
    cf_preselect++;
    for (unsigned int i =0; i < sel_electrons_pos.size(); i++) {
    for (unsigned int j =0; j < sel_electrons_pos.size(); j++) {
       if (i==j) continue;
       for (unsigned int k =0; k < sel_electrons_neg.size(); k++) {
       for (unsigned int l =0; l < sel_electrons_neg.size(); l++) {
          if (k==l) continue;
          m_logger << DEBUG  << "QuadSelector::MakeQuadruplets(): Making FourElectron quadruplet" << SLogger::endmsg;
	  all_quads.push_back( new Quadruplet(sel_electrons_pos.at(i),sel_electrons_neg.at(k),sel_electrons_pos.at(j),sel_electrons_neg.at(l)) );	  
       }}    
    }}
  }

  //case: 4 muons
  if (sel_muons_pos.size() >= 2 && sel_muons_neg.size() >= 2){
    cf_preselect++;
    for (unsigned int i =0; i < sel_muons_pos.size(); i++) {
    for (unsigned int j =0; j < sel_muons_pos.size(); j++) {
       if (i==j) continue;
       for (unsigned int k =0; k < sel_muons_neg.size(); k++) {
       for (unsigned int l =0; l < sel_muons_neg.size(); l++) {
          if (k==l) continue;
          m_logger << DEBUG  << "QuadSelector::MakeQuadruplets(): Making FourMuon quadruplet" << SLogger::endmsg;
	  all_quads.push_back( new Quadruplet(sel_muons_pos.at(i),sel_muons_neg.at(k),sel_muons_pos.at(j),sel_muons_neg.at(l)) );
       }}    
    }}
  }

  //case: 2 muons, 2 electrons
  if (sel_muons_pos.size() >= 1 && sel_muons_neg.size() >= 1 && sel_electrons_neg.size() >= 1 && sel_electrons_neg.size() >= 1 ){
    cf_preselect++;
    for (unsigned int i =0; i < sel_muons_pos.size(); i++) {
    for (unsigned int j =0; j < sel_muons_neg.size(); j++) {
       for (unsigned int k =0; k < sel_electrons_pos.size(); k++) {
       for (unsigned int l =0; l < sel_electrons_neg.size(); l++) {
          m_logger << DEBUG  << "QuadSelector::MakeQuadruplets(): Making TwoMuonTwoElectron quadruplets" << SLogger::endmsg;
	  all_quads.push_back( new Quadruplet(sel_muons_pos.at(i),sel_muons_neg.at(j),sel_electrons_pos.at(k),sel_electrons_neg.at(l)) );
	  all_quads.push_back( new Quadruplet(sel_electrons_pos.at(k),sel_electrons_neg.at(l),sel_muons_pos.at(i),sel_muons_neg.at(j)) );
       }}    
    }}
  }
}
if(m_doSecondPairSS == true){
//so far only implemented for electrons!
 //case: 4 electrons
  if ((sel_electrons_pos.size() >= 3 && sel_electrons_neg.size() >= 1) || (sel_electrons_neg.size() >= 3 && sel_electrons_pos.size() >= 1)){
    cf_preselect++;
    for (unsigned int i =0; i < sel_electrons_pos.size(); i++) {
    for (unsigned int j =0; j < sel_electrons_neg.size(); j++) {
       for (unsigned int k =0; k < sel_electrons_pos.size(); k++) {
       for (unsigned int l =0; l < sel_electrons_pos.size(); l++) {
         if (k==l || k==i || l==i) continue;
          m_logger << DEBUG  << "QuadSelectorZjets::MakeQuadruplets(): Making FourElectron quadruplet" << SLogger::endmsg;
          all_quads.push_back( new Quadruplet(sel_electrons_pos.at(i),sel_electrons_neg.at(j),sel_electrons_pos.at(k),sel_electrons_pos.at(l)) );

       }}
       for (unsigned int k =0; k < sel_electrons_neg.size(); k++) {
       for (unsigned int l =0; l < sel_electrons_neg.size(); l++) {
         if (k==l || k==j || l==j) continue;
         m_logger << DEBUG  << "QuadSelectorZjets::MakeQuadruplets(): Making FourElectron quadruplet" << SLogger::endmsg;
         all_quads.push_back( new Quadruplet(sel_electrons_pos.at(i),sel_electrons_neg.at(j),sel_electrons_neg.at(k),sel_electrons_neg.at(l)) );

       }}
    }}
  }
 //case: 4 muons
  if ((sel_muons_pos.size() >= 3 && sel_muons_neg.size() >= 1) || (sel_muons_neg.size() >= 3 && sel_muons_pos.size() >= 1)){
    cf_preselect++;
      for (unsigned int i =0; i < sel_muons_pos.size(); i++) {
      for (unsigned int j =0; j < sel_muons_neg.size(); j++) {
       for (unsigned int k =0; k < sel_muons_pos.size(); k++) {
       for (unsigned int l =0; l < sel_muons_pos.size(); l++) {
         if (k==l || k==i || l==i) continue;
          m_logger << DEBUG  << "QuadSelectorZjets::MakeQuadruplets(): Making FourMuon quadruplet" << SLogger::endmsg;
          all_quads.push_back( new Quadruplet(sel_muons_pos.at(i),sel_muons_neg.at(j),sel_muons_pos.at(k),sel_muons_pos.at(l)) );

       }}
       for (unsigned int k =0; k < sel_muons_neg.size(); k++) {
       for (unsigned int l =0; l < sel_muons_neg.size(); l++) {
         if (k==l || k==j || l==j) continue;
         m_logger << DEBUG  << "QuadSelectorZjets::MakeQuadruplets(): Making FourMuon quadruplet" << SLogger::endmsg;
         all_quads.push_back( new Quadruplet(sel_muons_pos.at(i),sel_muons_neg.at(j),sel_muons_neg.at(k),sel_muons_neg.at(l)) );

       }}
    }}
}

//case: 2 muons, 2 electrons
 if (sel_muons_pos.size() >= 1 && sel_muons_neg.size() >= 1 && (sel_electrons_neg.size() >= 2 || sel_electrons_pos.size() >= 2) ){
    cf_preselect++;
    for (unsigned int i =0; i < sel_muons_pos.size(); i++) {
    for (unsigned int j =0; j < sel_muons_neg.size(); j++) {
       for (unsigned int k =0; k < sel_electrons_pos.size(); k++) {
       for (unsigned int l =0; l < sel_electrons_pos.size(); l++) {
         if (k==l) continue;
          m_logger << DEBUG  << "QuadSelectorZjets::MakeQuadruplets(): Making TwoMuonTwoElectron quadruplets" << SLogger::endmsg;
          all_quads.push_back( new Quadruplet(sel_muons_pos.at(i),sel_muons_neg.at(j),sel_electrons_pos.at(k),sel_electrons_pos.at(l)) );
       }}
       for (unsigned int k =0; k < sel_electrons_neg.size(); k++) {
       for (unsigned int l =0; l < sel_electrons_neg.size(); l++) {
        if (k==l) continue;
         m_logger << DEBUG  << "QuadSelectorZjets::MakeQuadruplets(): Making TwoMuonTwoElectron quadruplets" << SLogger::endmsg;
         all_quads.push_back( new Quadruplet(sel_muons_pos.at(i),sel_muons_neg.at(j),sel_electrons_neg.at(k),sel_electrons_neg.at(l)) );
       }}
    }}
  }
if (sel_electrons_pos.size() >= 1 && sel_electrons_neg.size() >= 1 && (sel_muons_neg.size() >= 2 || sel_muons_pos.size() >= 2) ){
    cf_preselect++;
    for (unsigned int i =0; i < sel_electrons_pos.size(); i++) {
    for (unsigned int j =0; j < sel_electrons_neg.size(); j++) {
       for (unsigned int k =0; k < sel_muons_pos.size(); k++) {
       for (unsigned int l =0; l < sel_muons_pos.size(); l++) {
         if (k==l) continue;
          m_logger << DEBUG  << "QuadSelectorZjets::MakeQuadruplets(): Making TwoElectronTwoMuon quadruplets" << SLogger::endmsg;
          all_quads.push_back( new Quadruplet(sel_electrons_pos.at(i),sel_electrons_neg.at(j),sel_muons_pos.at(k),sel_muons_pos.at(l)) );
       }}
       for (unsigned int k =0; k < sel_muons_neg.size(); k++) {
       for (unsigned int l =0; l < sel_muons_neg.size(); l++) {
         if (k==l) continue;
         m_logger << DEBUG  << "QuadSelectorZjets::MakeQuadruplets(): Making TwoElectronTwoMuon quadruplets" << SLogger::endmsg;
         all_quads.push_back( new Quadruplet(sel_electrons_pos.at(i),sel_electrons_neg.at(j),sel_muons_neg.at(k),sel_muons_neg.at(l)) );
       }}
    }}
  }
}//end of m_doSecondPairSS == true 



  m_logger << DEBUG << "Number of quadruplets in event: " << all_quads.size() << SLogger::endmsg;
  				    
  return;

}

void QuadSelector::SelectQuadruplets( std::vector<Quadruplet*> &all_quads, std::vector<Quadruplet*> &sel_quads, int n_vertices ) {
  
//   m_logger << ALWAYS << "Muons: " << m_doFourMuon           << SLogger::endmsg;
//   m_logger << ALWAYS << "elecs: " << m_doFourElectron       << SLogger::endmsg;
//   m_logger << ALWAYS << "2mu2e: " << m_doTwoMuonTwoElectron << SLogger::endmsg;
//   m_logger << ALWAYS << "2e2mu: " << m_doTwoElectronTwoMuon << SLogger::endmsg;

  b_SFOS = false;
  b_trigger = false;
  b_kinematics = false;
  bool b_z1_mass = false;
  bool b_z2_mass = false;
  bool b_deltaR = false;
  bool b_jpsi = false;
  
  if ( all_quads.size() < 1) {
    m_logger << DEBUG  << "QuadSelector::SelectQuadruplets(): No input quadruplets" << SLogger::endmsg;
    return;
  }
  
  for(std::vector<Quadruplet*>::iterator itr = all_quads.begin(); itr != all_quads.end(); ++itr) { 

    if(!m_doFourMuon           && (*itr)->Type() == Quadruplet::FourMuon          ) continue;
    if(!m_doFourElectron       && (*itr)->Type() == Quadruplet::FourElectron      ) continue;
    if(!m_doTwoMuonTwoElectron && (*itr)->Type() == Quadruplet::TwoMuonTwoElectron) continue;
    if(!m_doTwoElectronTwoMuon && (*itr)->Type() == Quadruplet::TwoElectronTwoMuon) continue;
    
    //remove duplicate quads by requiring m12 closer to Z mass than m34
    if ( fabs((*itr)->M12() - M_Z) > fabs((*itr)->M34() - M_Z) ) continue;  
    
    //max 1 standalone or 1 calo muon 
    if ((*itr)->n_StandAloneMuons() + (*itr)->n_CaloTagMuons() > 1) continue;
    b_SFOS = true;
    
    //pt cut on top 3 leptons
    std::vector<double> pt_leptons;
    (*itr)->LeptonPt( pt_leptons );
    
    //sort pT of leptons
    std::sort(pt_leptons.begin(), pt_leptons.end(), std::greater<double>());
    
    m_logger << DEBUG  << "mu1: "<<pt_leptons.at(0) << ", "<<pt_leptons.at(1) <<", "<< pt_leptons.at(2) << SLogger::endmsg;
    if(m_pt3Cut == 7){
	if (!(pt_leptons.at(0) > 20000 && pt_leptons.at(1) > 15000)) continue;
	}
    else{
	if(!(pt_leptons.at(0) > 20000 && pt_leptons.at(1) > 15000 && pt_leptons.at(2) > 10000)) continue;
	}
    b_kinematics = true;
    
    //trigger matching
    GET_TOOL(trig_select, TriggerSelector, "TriggerSelector");
    bool trigger_pass = trig_select->MatchTriggers( *itr );
    if (!trigger_pass) continue;
    b_trigger = true;

    if(m_doBestBefore == false){ 
      //primary di-lepton mass
      if ( (*itr)->M12() <= m_M12Cut*1000 || (*itr)->M12() >= 106000 ) continue;
      b_z1_mass = true;

      //secondary di-lepton mass
      if (!((*itr)->M34() < 115000 )) continue;
      double cut_mass = 0;
      if (m_M34Cut == 12) cut_mass = interpolate(v_m34cut_m4l, v_m34cut_m34_relaxed,(*itr)->M4l() );
      else cut_mass = interpolate(v_m34cut_m4l, v_m34cut_m34,(*itr)->M4l() );
      m_logger << DEBUG  << "M34 cut: M4l = "<< (*itr)->M4l() << " M34 = " << (*itr)->M34() << " cut mass = " << cut_mass << SLogger::endmsg;
      if (!( (*itr)->M34() > cut_mass )) continue;
      b_z2_mass = true;

      //delta R cuts
      if ( (*itr)->MinDeltaRSF() <= 0.1 ) continue;
      if ( (*itr)->MinDeltaROF() <= 0.2 ) continue;
      b_deltaR = true;

      //J/Psi Veto 
      if ( (*itr)->Type() == Quadruplet::FourMuon || (*itr)->Type() == Quadruplet::FourElectron ) {
	if ( (*itr)->M14() <= 5000 || (*itr)->M23() <= 5000 ) continue;
      }
      b_jpsi=true;

    }//end if doBestBefore == false

    std::vector<Electron*>  q_electrons;
    (*itr)->GetElectrons( q_electrons );

    ///////These are additional ID cuts that are only called if requested////////////////
    //require first electron pair to pass likelihood, if requested//this is for consistency, since some skims require ML as first pair
   if(m_doFirstPairPassID && ((*itr)->Type() == Quadruplet::FourElectron || (*itr)->Type() == Quadruplet::TwoElectronTwoMuon)){
      GET_TOOL(id, IDTool, "IDTool");
      bool pass_electronID_single = true;
      for(int i = 0; i < 2; i++){
       bool pass_electronID = false;
       if(m_doFirstPairPassLikelihood){
           if(id->passLikelihood(*q_electrons.at(i),m_FirstPairLikelihood_OP,n_vertices)) pass_electronID = true;
        }
       if(m_doFirstPairPassLikelihoodMedium){
           if(id->passLikelihood(*q_electrons.at(i),LikeEnum::Medium,n_vertices)) pass_electronID = true;
        }
       if(m_doFirstPairPassLikelihoodLoose){
           if(id->passLikelihood(*q_electrons.at(i),LikeEnum::Loose,n_vertices)) pass_electronID = true;
        }
       // if(m_doFirstPairPassLikelihoodLoose_BL_Pix){
       //    if(id->passLikelihood(*q_electrons.at(i),LikeEnum::Loose_BL_Pix,n_vertices)) pass_electronID = true;
       // }
        if(m_doFirstPairPassLikelihoodLoose_BL_PixLow){
	  m_logger << ALWAYS << "Error! Loose_BL_PixLow DEPRECATED! Defaulting to Loose LH" << SLogger::endmsg;
           if(id->passLikelihood(*q_electrons.at(i),LikeEnum::Loose,n_vertices)) pass_electronID = true;
        }
        if(m_doFirstPairPassLikelihoodLoose_BL_PixMed){
	  m_logger << ALWAYS << "Error! Loose_BL_PixMed DEPRECATED! Defaulting to Loose LH" << SLogger::endmsg;
	  if(id->passLikelihood(*q_electrons.at(i),LikeEnum::Loose,n_vertices)) pass_electronID = true;
        }
	if(m_doFirstPairPassLikelihoodLoose_BL_PixHigh){
	  m_logger << ALWAYS << "Error! Loose_BL_PixHigh DEPRECATED! Defaulting to Loose LH" << SLogger::endmsg;
	  if(id->passLikelihood(*q_electrons.at(i),LikeEnum::Loose,n_vertices)) pass_electronID = true;
        }
	if(m_doFirstPairPassML){
           if(id->passML(*q_electrons.at(i),"")) pass_electronID = true;
       }
       if(m_doFirstPairPassML_HCP){
           if(id->passML_HCP(*q_electrons.at(i),"")) pass_electronID = true;
       }
       if (!pass_electronID) pass_electronID_single = false;
     } //end loop over first two electrons
 
     if(pass_electronID_single == false) continue;

    }//end if firstpairpassid


    if(m_doSecondPairPassLikelihood || m_doSecondPairPassML){
    GET_TOOL(id, IDTool, "IDTool");
    bool passSecondPairID = 1; 
    if((*itr)->Type() == Quadruplet::FourElectron){
       for(int i = 2; i < 4; i++){
                  if (m_doSecondPairPassLikelihood && !(id->passLikelihood((*q_electrons.at(i)),m_SecondPairLikelihood_OP,n_vertices))) passSecondPairID = 0;
                  if (m_doSecondPairPassML && !(id->passML((*q_electrons.at(i)),m_SecondPairML_OP))) passSecondPairID = 0;
      }
   }//4 ele case
   else if((*itr)->Type() == Quadruplet::TwoMuonTwoElectron){
      for(int i = 0; i < 2; i++){
                  if (m_doSecondPairPassLikelihood && !(id->passLikelihood((*q_electrons.at(i)),m_SecondPairLikelihood_OP,n_vertices))) passSecondPairID = 0;
                  if (m_doSecondPairPassML && !(id->passML((*q_electrons.at(i)),m_SecondPairML_OP))) passSecondPairID = 0;
      }
  }//2 ele case
    if(!passSecondPairID) continue;
   }//end ID criteria


    if(m_doOneOfSecondPairPassLikelihood || m_doOneOfSecondPairPassML || m_doOneOfSecondPairPassLikelihoodLoose || m_doOneOfSecondPairPassLikelihoodLoose_BL_Pix || m_doOneOfSecondPairPassLikelihoodLoose_BL_PixLow || m_doOneOfSecondPairPassLikelihoodLoose_BL_PixMed || m_doOneOfSecondPairPassLikelihoodLoose_BL_PixHigh ){
    GET_TOOL(id, IDTool, "IDTool");
    bool passSecondPairID = 0; 
    if((*itr)->Type() == Quadruplet::FourElectron){
       for(int i = 2; i < 4; i++){
                  if (m_doOneOfSecondPairPassLikelihood && (id->passLikelihood((*q_electrons.at(i)),m_SecondPairLikelihood_OP,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassML && (id->passML((*q_electrons.at(i)),m_SecondPairML_OP))) passSecondPairID = 1;
                  //if (m_doOneOfSecondPairPassLikelihoodLoose_BL_Pix && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose_BL_Pix,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassLikelihoodLoose && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassLikelihoodLoose_BL_PixLow && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassLikelihoodLoose_BL_PixMed && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassLikelihoodLoose_BL_PixHigh && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose,n_vertices))) passSecondPairID = 1;

      }
   }//4 ele case
   else if((*itr)->Type() == Quadruplet::TwoMuonTwoElectron){
      for(int i = 0; i < 2; i++){
                  if (m_doOneOfSecondPairPassLikelihood && (id->passLikelihood((*q_electrons.at(i)),m_SecondPairLikelihood_OP,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassML && (id->passML((*q_electrons.at(i)),m_SecondPairML_OP))) passSecondPairID = 1;
                  //if (m_doOneOfSecondPairPassLikelihoodLoose_BL_Pix && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose_BL_Pix,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassLikelihoodLoose && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassLikelihoodLoose_BL_PixLow && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassLikelihoodLoose_BL_PixMed && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose,n_vertices))) passSecondPairID = 1;
                  if (m_doOneOfSecondPairPassLikelihoodLoose_BL_PixHigh && (id->passLikelihood((*q_electrons.at(i)),LikeEnum::Loose,n_vertices))) passSecondPairID = 1;
  

    }
  }//2 ele case
    if(!passSecondPairID) continue;
   }//end ID criteria





   //////////////////////////////////////////
        
    sel_quads.push_back(*itr); 
    
  }
  
  if(b_SFOS)  	   cf_SFOS++;
  if(b_trigger)    cf_trigger++;
  if(b_kinematics) cf_kinematics++;
  if(b_z1_mass)    cf_z1_mass++;
  if(b_z2_mass)    cf_z2_mass++;
  if(b_deltaR)     cf_deltaR++;
  if(b_jpsi) 	   cf_jpsi++;

     
  m_logger << DEBUG  << "Number of selected quadruplets: " << sel_quads.size() <<  SLogger::endmsg;
			    
  return;

}

bool QuadSelector::IsBlinded( Quadruplet* quad ){
  if (m_doBlindSignalRegion && 110000. < quad->M4l() && quad->M4l() < 140000.) return true;
  return false;
}

void QuadSelector::ResetFinalQuadCuts() {

  b_fq_z1_mass = false;  
  b_fq_z2_mass = false;  
  b_fq_deltaR = false;   
  b_fq_jpsi = false;     
  b_fq_track_iso = false;
  b_fq_calo_iso = false; 
  b_fq_d0_sig = false;   
  //b_fq_outside_blind = false;   

  return;
}

bool QuadSelector::FinalQuadCuts( Quadruplet* quad , bool count) {

  if (!quad) return false;
  
  m_logger << DEBUG << "Beginning final cuts for quad type "<<quad->Type() << " with m4l= " << quad->M4l() <<SLogger::endmsg;
			     
  //select type of quadruplet
  bool foundSelectedQuadType = 0;

  if(m_doFourMuon           && quad->Type() == Quadruplet::FourMuon          ) foundSelectedQuadType = 1;
  if(m_doFourElectron       && quad->Type() == Quadruplet::FourElectron      ) foundSelectedQuadType = 1;
  if(m_doTwoMuonTwoElectron && quad->Type() == Quadruplet::TwoMuonTwoElectron) foundSelectedQuadType = 1;
  if(m_doTwoElectronTwoMuon && quad->Type() == Quadruplet::TwoElectronTwoMuon) foundSelectedQuadType = 1;

  if(foundSelectedQuadType == 0) return false;
 
  //M34 cut
  if(m_doBestBefore){ 

      //primary di-lepton mass
      if ( quad->M12() <= m_M12Cut*1000 || quad->M12() >= 106000 ) return false;
      if (count) cf_z1_mass++;
      if (count) b_fq_z1_mass = true;
    
      //secondary di-lepton mass
      if (!(quad->M34() < 115000 )) return false;
      double cut_mass = 0;
      if (m_M34Cut == 12) cut_mass = interpolate(v_m34cut_m4l, v_m34cut_m34_relaxed,quad->M4l() );
      else cut_mass = interpolate(v_m34cut_m4l, v_m34cut_m34,quad->M4l() );
      m_logger << DEBUG  << "M34 cut: M4l = "<< quad->M4l() << " M34 = " << quad->M34() << " cut mass = " << cut_mass << SLogger::endmsg;
      if (!( quad->M34() > cut_mass )) return false;
      if (count) cf_z2_mass++;
      if (count) b_fq_z2_mass = true;

      //delta R cuts
      if ( quad->MinDeltaRSF() <= 0.1 ) return false;
      if ( quad->MinDeltaROF() <= 0.2 ) return false;
      if (count) cf_deltaR++;
      if (count) b_fq_deltaR = true;

      //J/Psi Veto 
      if ( quad->Type() == Quadruplet::FourMuon || quad->Type() == Quadruplet::FourElectron ) {
	if ( quad->M14() <= 5000 || quad->M23() <= 5000 ) return false;
      }
      if (count) cf_jpsi++;
      if (count) b_fq_jpsi = true;
  }
 

  //track isolation 
  if (m_doTrkIsoCut) {
    bool passed_trk_iso = TrkIsolationCut(quad);
    if (!passed_trk_iso) {
      m_logger << DEBUG << "Failed track isolation cut" << SLogger::endmsg;      
      return false;    
    }
  }
  if (count) cf_track_iso++;
  if (count) b_fq_track_iso = true;

  //calo isolation
  if (m_doCaloIsoCut) {
    bool passed_calo_iso = CaloIsolationCut(quad);
    if (!passed_calo_iso) {
      m_logger << DEBUG << "Failed calo isolation cut" <<SLogger::endmsg;
      return false;    
    }
  }
  if (count) cf_calo_iso++;
  if (count) b_fq_calo_iso = true;

  //impact parameter significance 
  if (m_doD0SigCut) {
    bool passed_ip = D0SignificanceCut(quad); 
    if (!passed_ip) {
      m_logger << DEBUG <<"Failed lepton d0 cut" << SLogger::endmsg;
      return false;
    }    
  }
  if (count) cf_d0_sig++;
  if (count) b_fq_d0_sig = true;

  m_logger << DEBUG  << "Passed all final Quadruplet cuts" <<  SLogger::endmsg;
			    
  return true;

}

// std::vector<Quadruplet*> FourMuonQuads(std::vector<Quadruplet*> quads) {
//   std::vector<Quadruplet*> out_quads;
//   for(std::vector<Quadruplet*>::iterator itr = quads.begin(); itr != quads.end(); ++itr) {
//     if((*itr)->Type() == Quadruplet::FourMuon) out_quads.push_back(*itr);
//   }
//   return out_quads;
// }

Quadruplet* QuadSelector::SelectFinalQuadruplet( std::vector<Quadruplet*> &quads, Quadruplet::QuadType quad_type ) {

  m_logger << DEBUG << "SelectFinalQuadruplet for quad type: "<< quad_type << SLogger::endmsg;

  // Split into just one quad type
  std::vector<Quadruplet*> sel_quads;
  for(std::vector<Quadruplet*>::iterator itr = quads.begin(); itr != quads.end(); ++itr) {
    if( (*itr)->Type() == quad_type ) sel_quads.push_back(*itr);
  }

  if (sel_quads.size() == 0) {
    //m_logger << ERROR  << "Shouldn't pass a vector here with zero quads! " <<  SLogger::endmsg;  
      return 0;
  } 

  if (sel_quads.size() == 1) {
    m_logger << DEBUG << "SelectFinalQuadruplet - only one quad!" << SLogger::endmsg;
    return sel_quads.at(0);
  }     

  if (sel_quads.size() > 1) {
    m_logger << DEBUG << "SelectFinalQuadruplet - more than one 1 quad: " << sel_quads.size() << SLogger::endmsg;
    //Select m12 closest to z mass
    
    //find smallest m12 difference
    double smallest_m12_diff = -1;
    for(unsigned int i = 0; i < sel_quads.size(); ++i) { 
      double mass_diff = fabs(sel_quads[i]->M12() - M_Z);
      if ( mass_diff < smallest_m12_diff || i == 0) {
        smallest_m12_diff = mass_diff;   
      }        
    }

    m_logger << DEBUG  << "smallest_m12_diff: "<< smallest_m12_diff <<  SLogger::endmsg;  
    
    std::vector<Quadruplet*> sel_quads2;
    //find all quads with smallest m12 difference
    for(std::vector<Quadruplet*>::iterator itr = sel_quads.begin(); itr != sel_quads.end(); ++itr) { 
      double mass_diff = fabs((*itr)->M12() - M_Z);
      //m_logger << INFO  << "mass_diff: "<< mass_diff << "smallest_m12_diff: " << smallest_m12_diff << SLogger::endmsg;  
      //if ( mass_diff == smallest_m12_diff) sel_quads2.push_back(*itr);           
      if ( fabs(mass_diff - smallest_m12_diff) < 0.1) sel_quads2.push_back(*itr);
    }
    
    m_logger <<DEBUG  << "sel_quads2.size(): "<< sel_quads2.size() <<  SLogger::endmsg;  

    //choose quad with smallest m34-(Z PDG) difference
    double smallest_m34_diff = -1;
    double sel_quad_index = -1;
    for(unsigned int i = 0; i < sel_quads2.size(); ++i) { 
      double mass_diff = fabs(sel_quads2[i]->M34() - M_Z);
      if ( mass_diff < smallest_m34_diff || i == 0) {
	smallest_m34_diff = mass_diff;
        sel_quad_index = i;         
      }  
    }
    
    m_logger << DEBUG  << "smallest_m34_diff: "<< smallest_m34_diff << " " << sel_quad_index << SLogger::endmsg;  
    
    m_logger << DEBUG << "SelectFinalQuadruplet - quad index " << sel_quad_index <<" quad mass: " <<sel_quads2[sel_quad_index]->M4l() << SLogger::endmsg;
    return sel_quads2[sel_quad_index];
  }
  
  //shouldn't get here...
  m_logger << ERROR  << "QuadSelector::SelectFinalQuadruplet(): Shouldn't get here! size:"<< sel_quads.size()  <<  SLogger::endmsg;  
  return 0;
}


bool QuadSelector::TrkIsolationCut(Quadruplet* quad){

  m_logger << DEBUG  << "Entering TrkIsolationCut()" <<  SLogger::endmsg;  

  std::vector<double> trk_iso;
  quad->LeptonTrkIsolation(trk_iso, m_muonTrkIsoConeSize, m_electronTrkIsoConeSize);  
   
  m_logger << DEBUG  << "TrkIsolationCut(): size of trk_iso: "<<trk_iso.size() <<  SLogger::endmsg;  
    
  bool passed = true;  
  if (quad->Type() == Quadruplet::FourMuon){      
    for (unsigned int i = 0; i < trk_iso.size(); i++){
      if (trk_iso.at(i) >= m_muonTrkIsoCut)  passed = false;       
    }
  }
 
  if (quad->Type() == Quadruplet::FourElectron){      
    for (unsigned int i = 0; i < 2; i++){
      if (trk_iso.at(i) >= m_electronTrkIsoCut)  passed = false;       
    }
    for (unsigned int i = 2; i < 4; i++){
      if (m_doSecondPairIso && trk_iso.at(i) >= m_electronTrkIsoCut)  passed = false;
    }
  }
  
  if (quad->Type() == Quadruplet::TwoElectronTwoMuon){      
    for (unsigned int i = 2; i < 4; i++){
      if (trk_iso.at(i) >= m_muonTrkIsoCut)  passed = false;       
    }
    for (unsigned int i = 0; i < 2; i++){
      if (trk_iso.at(i) >= m_electronTrkIsoCut)  passed = false;       
    }
  }

  if (quad->Type() == Quadruplet::TwoMuonTwoElectron){      
    for (unsigned int i = 0; i < 2; i++){
      if (trk_iso.at(i) >= m_muonTrkIsoCut)  passed = false;       
    }
    for (unsigned int i = 2; i < 4; i++){
      if (m_doSecondPairIso && trk_iso.at(i) >= m_electronTrkIsoCut)  passed = false;       
    }
  }
  
  if (!passed){
    m_logger << DEBUG << "Failed track isolation cut.  Iso values are: " << trk_iso[0] << " " << trk_iso[1] << " "<< trk_iso[2] << " "<< trk_iso[3] << SLogger::endmsg;
  }
  
  return passed;
}


bool QuadSelector::CaloIsolationCut(Quadruplet* quad){
  
  
  m_logger << DEBUG  << "Entering CaloIsolationCut()" <<  SLogger::endmsg;  

  std::vector<Muon*> q_muons;
  quad->GetMuons( q_muons );

  std::vector<double> calo_iso;
  quad->LeptonCaloIsolation(calo_iso, !is_data(), m_muonCaloIsoConeSize, m_electronCaloIsoConeSize,m_electronCaloIsoSubConeSize);  
   
  bool passed = true;  
  if (quad->Type() == Quadruplet::FourMuon){      
    for (unsigned int i = 0; i < calo_iso.size(); i++){
      if ( q_muons.at(i)->isStandAloneMuon() ){ 
	if (calo_iso.at(i) >= m_standaloneMuonCaloIsoCut)  passed = false; 
      } else {
	if (calo_iso.at(i) >= m_muonCaloIsoCut)  passed = false;       
      }
    }
  }
 
  if (quad->Type() == Quadruplet::FourElectron){      
    for (unsigned int i = 0; i < 2; i++){
	if (calo_iso.at(i) >= m_electronCaloIsoCut)  passed = false;       
    }
    for (unsigned int i = 2; i < 4; i++){
        if (m_doSecondPairIso && calo_iso.at(i) >= m_electronCaloIsoCut)  passed = false;
    }
  }


  if (quad->Type() == Quadruplet::TwoElectronTwoMuon){      
    for (unsigned int i = 0; i < 2; i++){
	if (calo_iso.at(i) >= m_electronCaloIsoCut)  passed = false;       
    }
    for (unsigned int i = 2; i < 4; i++){
      if ( q_muons.at(i-2)->isStandAloneMuon() ){ 
	if (calo_iso.at(i) >= m_standaloneMuonCaloIsoCut)  passed = false; 
      } else {
	if (calo_iso.at(i) >= m_muonCaloIsoCut)  passed = false;       
      }
    }
  }


  if (quad->Type() == Quadruplet::TwoMuonTwoElectron){      
    for (unsigned int i = 0; i < 2; i++){
      if ( q_muons.at(i)->isStandAloneMuon() ){ 
	if (calo_iso.at(i) >= m_standaloneMuonCaloIsoCut)  passed = false; 
      } else {
	if (calo_iso.at(i) >= m_muonCaloIsoCut)  passed = false;       
      }
    }
    for (unsigned int i = 2; i < 4; i++){
	if (m_doSecondPairIso && calo_iso.at(i) >= m_electronCaloIsoCut)  passed = false;       
    }
  }

  if (!passed){
    m_logger << DEBUG << "Failed track isolation cut.  Iso values are: " << calo_iso[0] << " " << calo_iso[1] << " "<< calo_iso[2] << " "<< calo_iso[3] << SLogger::endmsg;
  }
  
  return passed;  
}


bool QuadSelector::D0SignificanceCut(Quadruplet* quad){
  
  
  m_logger << DEBUG  << "Entering D0SignificanceCut()" <<  SLogger::endmsg;  

  std::vector<double> d0_sig;
  quad->LeptonD0Significance(d0_sig, !is_data());  
   
  if (quad->Type() == Quadruplet::FourMuon){      
    for (unsigned int i = 0; i < d0_sig.size(); i++){
      if (d0_sig.at(i) >= 3.5)  return false;       
    }
  }
 
  if (quad->Type() == Quadruplet::FourElectron){      
    for (unsigned int i = 0; i < 2; i++){
      if (d0_sig.at(i) >= 6.5)  return false;       
    }
    for (unsigned int i = 2; i < 4; i++){
      if ( m_doSecondPairDzero && d0_sig.at(i) >= 6.5)  return false;
    }
  }

  if (quad->Type() == Quadruplet::TwoElectronTwoMuon){      
    for (unsigned int i = 0; i < 2; i++){
      if (d0_sig.at(i) >= 6.5)  return false;       
    }
    for (unsigned int i = 2; i < 4; i++){
      if (d0_sig.at(i) >= 3.5)  return false;            
    }
  }

  if (quad->Type() == Quadruplet::TwoMuonTwoElectron){      
    for (unsigned int i = 0; i < 2; i++){
      if (d0_sig.at(i) >= 3.5)  return false;             
    }
    for (unsigned int i = 2; i < 4; i++){
      if ( m_doSecondPairDzero && d0_sig.at(i) >= 6.5)  return false;       
    }
  }
  
  return true;  
}


double QuadSelector::interpolate(const std::vector<double>& x,  const std::vector<double>& y, double mass)
{

  m_logger << DEBUG  << "QuadSelector::interpolate(): input mass: " << mass << SLogger::endmsg;
  
  double result = 0.;
  unsigned int i = 0;
  while(i < x.size()){
    if(x[i] >= mass) break;
    i++;
  }
  
  if (i==0) return y[i];
  if (i==x.size()) return y[x.size() - 1];
  
  result = y[i-1] + (y[i] - y[i-1])/(x[i] - x[i-1])*(mass - x[i-1]);
  return result;
}

double QuadSelector::DeltaR(double eta1, double phi1, double eta2, double phi2) {      
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  double delta_eta = eta1 - eta2;  
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}

