// $Id: ZMassStudy.cxx 19791 2012-11-14 13:01:11Z stahlman $

#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Muon.h"
#include "Electron.h"
#include "Quadruplet.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "EnergyRescalerTool.h"

//ZZSelection
#include "MuonSelector.h"

//local
#include "../include/ZMassStudy.h"


const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( ZMassStudy );

ZMassStudy::ZMassStudy()
  : CycleBase()

{

   SetLogName( GetName() );
   DeclareProperty( "RecoTreeString", m_recoTreeName );
   DeclareProperty( "TrigTreeString", m_trigTreeName );
   DeclareProperty( "OutputTreeString", c_output_tree_name = "output");   
   
   DeclareProperty("output_event_branches_regex", c_output_event_branches_regex = ".*");
   DeclareProperty("output_mcevt_branches_regex", c_output_mcevt_branches_regex = ".*");
   DeclareProperty("output_electron_trigger_branches_regex", c_output_electron_trigger_branches_regex = ".*");
   DeclareProperty("output_muon_trigger_branches_regex", c_output_muon_trigger_branches_regex = ".*");
   DeclareProperty("output_trigger_branches_regex", c_output_trigger_branches_regex = ".*");
   DeclareProperty("output_vxp_branchegs_regex", c_output_vxp_branches_regex = ".*");
   DeclareProperty("output_electron_branches_regex", c_output_electron_branches_regex = ".*");
   DeclareProperty("output_muon_branches_regex", c_output_muon_branches_regex = ".*");
   DeclareProperty("output_jet_branches_regex", c_output_jet_branches_regex = ".*");
   DeclareProperty("output_met_branches_regex", c_output_met_branches_regex = ".*");
   DeclareProperty("output_truth_branches_regex", c_output_truth_branches_regex = ".*");
   //DeclareProperty("output_photon_branches_regex", c_output_photon_branches_regex = ".*");
   
   DECLARE_TOOL(EnergyRescalerTool, "EnergyRescalerTool");
   DECLARE_TOOL(MuonSelector,       "MuonSelector");

   //mass_tool = new InvMassTool();

   gRand = new TRandom3();
   gRand->SetSeed(0);

   char *m_path = "/../MuonMomentumCorrections/share/";
   char *rc_path = getenv ("ROOTCOREDIR");
   char *path = new char[strlen(rc_path)+strlen(m_path)];
   sprintf(path,"%s%s",rc_path, m_path);

   m_muResolution = new MuonSmear::SmearingClass("Data12","staco","pT","Rel17.2_preliminary",path);
   m_muResolution->UseScale(1);
   m_muResolution->UseImprovedCombine();
   delete path;

}

ZMassStudy::~ZMassStudy() {

  gRand->Delete();
  delete m_muResolution;
}

void ZMassStudy::BeginCycleImp() throw( SError ) {  
  

  return;

}

void ZMassStudy::EndCycleImp() throw( SError ) {

   return;

}

void ZMassStudy::BeginInputDataImp( const SInputData& ) throw( SError ) {


  //Declare output variables:  
  DeclareVariable( m_2l,       "m_2l");
  DeclareVariable( m_2l_truth, "m_2l_truth");
  DeclareVariable( m_2l_smeared_truth, "m_2l_smeared_truth");
  DeclareVariable( delta_p_pos, "delta_p_pos");
  DeclareVariable( delta_p_neg, "delta_p_neg");
  DeclareVariable( delta_pt_pos, "delta_pt_pos");
  DeclareVariable( delta_pt_neg, "delta_pt_neg");
  DeclareVariable( delta_r_pos, "delta_r_pos");
  DeclareVariable( delta_r_neg, "delta_r_neg");
  DeclareVariable( resolution_pos, "resolution_pos");
  DeclareVariable( resolution_neg, "resolution_neg");
  DeclareVariable( pull_p_pos,  "pull_p_pos");
  DeclareVariable( pull_p_neg,  "pull_p_neg");
  DeclareVariable( pull_pt_pos,  "pull_pt_pos");
  DeclareVariable( pull_pt_neg,  "pull_pt_neg");

  // -----------------------------------------------------------------
  // ---------------- D3PD Reader constuctors ------------------------
  
  // inputs/outputs
  m_event_d3pdobject = new D3PDReader::EventInfoD3PDObject( m_entry_number );
  m_trigger_d3pdobject = new D3PDReader::TriggerD3PDObject( m_entry_number );
  m_vxp_d3pdobject = new D3PDReader::PrimaryVertexD3PDObject( m_entry_number );

  m_electron_d3pdobject = new D3PDReader::ElectronD3PDObject( m_entry_number, "el_" );
  m_muon_staco_d3pdobject = new D3PDReader::MuonD3PDObject( m_entry_number, "mu_staco_" );
  m_muon_calo_d3pdobject = new D3PDReader::MuonD3PDObject( m_entry_number, "mu_calo_" );

  m_truth_d3pdobject = new D3PDReader::TruthParticleD3PDObject( m_entry_number );
   
  // -------------------------------------------------------------
  // ---------------- Activating branches ------------------------

  // control what is read out by setting those branches Active
  // - all branches are Not Active by default
  m_event_d3pdobject->SetActive(kTRUE,c_output_event_branches_regex);
  m_trigger_d3pdobject->SetActive(kTRUE,c_output_trigger_branches_regex);
  m_vxp_d3pdobject->SetActive(kTRUE,c_output_vxp_branches_regex);

  m_electron_d3pdobject->SetActive(kTRUE,c_output_electron_branches_regex);
  m_muon_staco_d3pdobject->SetActive(kTRUE,c_output_muon_branches_regex);
  m_muon_calo_d3pdobject->SetActive(kTRUE,c_output_muon_branches_regex);

  m_truth_d3pdobject->SetActive(kTRUE,c_output_truth_branches_regex);

   return;

}

void ZMassStudy::EndInputDataImp( const SInputData& ) throw( SError ) {

   // inputs/outputs
    delete m_event_d3pdobject;
    delete m_trigger_d3pdobject;
    delete m_vxp_d3pdobject;

    delete m_electron_d3pdobject;
    delete m_muon_staco_d3pdobject;
    delete m_muon_calo_d3pdobject;

    delete m_truth_d3pdobject;

   return;

}

void ZMassStudy::BeginInputFileImp( const SInputData& ) throw( SError ) {

    m_logger << DEBUG  << "BeginInputFileImp " << SLogger::endmsg;

    m_event_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_trigger_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_vxp_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_electron_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_staco_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_calo_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_truth_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

   return;

}

void ZMassStudy::BeginMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZMassStudy::EndMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZMassStudy::ExecuteEventImp( const SInputData&, Double_t ) throw( SError ) {
  
  //clear out memory
  for (unsigned int i = 0; i <sel_muons.size(); i++)delete sel_muons.at(i);
  sel_muons.clear();

  //build muon collections
  std::vector<Muon> all_muons;
  ParticleElementBuilder::build( all_muons, (*m_muon_staco_d3pdobject) );

  std::vector<Muon> all_calo_muons;
  ParticleElementBuilder::build( all_calo_muons, (*m_muon_calo_d3pdobject) );
  
  m_logger << DEBUG  << "Lepton collections built" << SLogger::endmsg;

  //select Muons
  GET_TOOL(mu_select, MuonSelector, "MuonSelector");
  mu_select->SelectMuons(sel_muons, m_muon_staco_d3pdobject, m_muon_calo_d3pdobject, m_event_d3pdobject->EventNumber()); 

  //select candidate Z
  std::vector<Muon*> sel_muons_pos;
  std::vector<Muon*> sel_muons_neg;
  
  for (unsigned int i = 0; i < sel_muons.size(); i++){
    if (sel_muons.at(i)->charge() == +1){
      sel_muons_pos.push_back(sel_muons.at(i));
    } else if (sel_muons.at(i)->charge() == -1){
      sel_muons_neg.push_back(sel_muons.at(i));
    }
  }
  
  double mass_diff = -1;
  int index_pos = -1;
  int index_neg = -1;
  
  for (unsigned int i =0; i < sel_muons_pos.size(); i++) {
      for (unsigned int j =0; j < sel_muons_neg.size(); j++) {
	  TLorentzVector tlv_pos; tlv_pos.SetPtEtaPhiM(sel_muons_pos[i]->Pt(), sel_muons_pos[i]->eta(), sel_muons_pos[i]->phi(), sel_muons_pos[i]->m());
	  TLorentzVector tlv_neg; tlv_neg.SetPtEtaPhiM(sel_muons_neg[j]->Pt(), sel_muons_neg[j]->eta(), sel_muons_neg[j]->phi(), sel_muons_neg[j]->m());
	  double m_diff = fabs(91187.6 - (tlv_pos + tlv_neg).M());
	  if (mass_diff == -1 || m_diff < mass_diff) {
	     mass_diff = m_diff;
	     index_pos = i;
	     index_neg = j;
	  }
     }   
  }

  if (index_pos == -1 || index_neg == -1) {
    m_logger << DEBUG  << "No reconstructed Z candidate found - Skipping event" << SLogger::endmsg;
    throw SError( SError::SkipEvent );  
  }

  Muon* mu_pos = sel_muons_pos[index_pos];
  Muon* mu_neg = sel_muons_neg[index_neg];

  //find truth particles
  vector<TruthParticle> truth_Z;
  vector<TruthParticle> truth_leptons;

  std::vector<TruthParticle> tparts;
  ParticleElementBuilder::build(tparts, (*m_truth_d3pdobject));

  m_logger << DEBUG  << "Number of Truth Particles: "<< tparts.size() << SLogger::endmsg;

  for (unsigned int i = 0; i < tparts.size(); i++) {
     if (tparts[i].pdgId() == PDG::Z0 && tparts[i].status() == 62) {
	m_logger << DEBUG << "Found Z boson Truth Particle"<<tparts[i].status() << SLogger::endmsg;  
	truth_Z.push_back( tparts[i] );

        for (unsigned int j = 0; j < tparts[i].child_index().size(); j++) {
           int l_index = tparts[i].child_index()[j];	                	        
	   //Only look for muons.... 
	   if (( tparts[l_index].pdgId() == PDG::mu_minus || tparts[l_index].pdgId() == PDG::mu_plus )) {
   	       m_logger << DEBUG << "Found lepton from Z->ll decay! " << tparts[l_index].pdgId() << " "<< tparts[l_index].status() << SLogger::endmsg;  
   	       if(tparts[l_index].status() == 1) truth_leptons.push_back( tparts[l_index] );			 
	   }
	}
     }
  }

  if (truth_Z.size() != 1)       { 
    m_logger << WARNING << "Found "<< truth_Z.size() << " Z boson truth particles! Skipping event" << SLogger::endmsg;  
    throw SError( SError::SkipEvent ); 
  }
  if (truth_leptons.size() != 2) { 
    m_logger << WARNING << "Found "<< truth_leptons.size() << " lepton truth particles! Skipping event" << SLogger::endmsg;  
    throw SError( SError::SkipEvent ); 
  }
      
  //assign l1 positive and l2 negative
  int index_l1 = truth_leptons[0].charge() > 0 ? 0 : 1;
  int index_l2 = truth_leptons[0].charge() > 0 ? 1 : 0;
  
  //truth 4-vectors
  TLorentzVector tlv_truth_pos; tlv_truth_pos.SetPtEtaPhiM(truth_leptons[index_l1].pt(), truth_leptons[index_l1].eta(), truth_leptons[index_l1].phi(), truth_leptons[index_l1].m());
  TLorentzVector tlv_truth_neg; tlv_truth_neg.SetPtEtaPhiM(truth_leptons[index_l2].pt(), truth_leptons[index_l2].eta(), truth_leptons[index_l2].phi(), truth_leptons[index_l2].m());
  
  double smeared_pt_pos = SmearMomentum(tlv_truth_pos,0);
  double smeared_pt_neg = SmearMomentum(tlv_truth_neg,1);
  
  TLorentzVector tlv_smeared_truth_pos; tlv_smeared_truth_pos.SetPtEtaPhiM(smeared_pt_pos, truth_leptons[index_l1].eta(), truth_leptons[index_l1].phi(), truth_leptons[index_l1].m());
  TLorentzVector tlv_smeared_truth_neg; tlv_smeared_truth_neg.SetPtEtaPhiM(smeared_pt_neg, truth_leptons[index_l2].eta(), truth_leptons[index_l2].phi(), truth_leptons[index_l2].m());
  
  //reconstructed 4-vectors
  TLorentzVector tlv_reco_pos; tlv_reco_pos.SetPtEtaPhiM(mu_pos->Pt(), mu_pos->eta(), mu_pos->phi(), mu_pos->m());
  TLorentzVector tlv_reco_neg; tlv_reco_neg.SetPtEtaPhiM(mu_neg->Pt(), mu_neg->eta(), mu_neg->phi(), mu_neg->m());

  
  //derived quantities

  delta_r_pos = tlv_reco_pos.DeltaR(tlv_truth_pos);
  delta_r_neg = tlv_reco_neg.DeltaR(tlv_truth_neg);  
  
  if (delta_r_pos > 0.2 || delta_r_neg > 0.2){
    m_logger << DEBUG << "Large Delta R. Skipping Event" << SLogger::endmsg;  
    throw SError( SError::SkipEvent );   
  }

  resolution_pos = GetMuonResolution(mu_pos);
  resolution_neg = GetMuonResolution(mu_neg);

  //fill output variables
  m_2l       = (tlv_reco_pos+tlv_reco_neg).M();
  m_2l_truth = (tlv_truth_pos+tlv_truth_neg).M();
  m_2l_smeared_truth = (tlv_smeared_truth_pos+tlv_smeared_truth_neg).M();
  
  delta_pt_pos = tlv_reco_pos.Pt() - tlv_truth_pos.Pt();
  delta_pt_neg = tlv_reco_neg.Pt() - tlv_truth_neg.Pt();  
  
  pull_pt_pos = delta_pt_pos / (resolution_pos*tlv_reco_pos.Pt());
  pull_pt_neg = delta_pt_neg / (resolution_neg*tlv_reco_neg.Pt());

  delta_p_pos = tlv_reco_pos.P() - tlv_truth_pos.P();
  delta_p_neg = tlv_reco_neg.P() - tlv_truth_neg.P();  
  
  pull_p_pos = delta_p_pos / (resolution_pos*tlv_reco_pos.P());
  pull_p_neg = delta_p_neg / (resolution_neg*tlv_reco_neg.P());
  

 return;

}



double ZMassStudy::GetMuonResolution( Muon* muon ) {

  double resolution = -1;

  if (muon->isCombinedMuon() == 1 ) { //combined muon
    
    m_muResolution->Event(muon->ms_Pt(), muon->id_Pt(), muon->Pt(), muon->eta()); 
    //resolution = 1/fabs(muon->qoverp_exPV())*m_muResolution->ExpectedResolution("CB",!is_data());
    resolution = m_muResolution->ExpectedResolution("CB",!is_data());
    
  } else if (muon->isCaloMuon() || muon->isSegmentTaggedMuon()) { //ID track only
      
    m_muResolution->Event(muon->id_Pt(),muon->eta(), "ID"); 
    //resolution = 1/fabs(muon->qoverp_exPV())*m_muResolution->ExpectedResolution("ID",!is_data());
    resolution = m_muResolution->ExpectedResolution("ID",!is_data());
    
  } else if (muon->isStandAloneMuon()) { //standalone
    
    m_muResolution->Event(muon->ms_Pt(), muon->eta(), "MS"); 
    //resolution = 1/fabs(muon->qoverp_exPV())*m_muResolution->ExpectedResolution("MS",!is_data());
    resolution = m_muResolution->ExpectedResolution("MS",!is_data());
  }
  
  if ( resolution == -1){
    m_logger << WARNING << "GetMuonResolution(): Undefined type of muon" << SLogger::endmsg;    
  }
  
  /*
  if (resolution > 2) {
    m_logger << WARNING << "GetMuonResolution(): Large Resolution" << SLogger::endmsg;    
    m_logger << WARNING << "GetMuonResolution(): Muon - pT: "<< muon->Pt() << " " << muon->ms_Pt()<< " "<< muon->id_Pt() << SLogger::endmsg;    
    m_logger << WARNING << "GetMuonResolution(): Muon - eta: "<< muon->eta() << SLogger::endmsg;    
    m_logger << WARNING << "GetMuonResolution(): Muon - resolution: "<< resolution << SLogger::endmsg;    
  
  }
  */
  return resolution;
}

double ZMassStudy::SmearMomentum( TLorentzVector muon, int num ) {

  
  gRand->SetSeed(m_event_d3pdobject->EventNumber() + 100*num);
  
  m_muResolution->Event(muon.Pt(), muon.Pt(),muon.Pt(), muon.Eta()); 
  
  double resolution = m_muResolution->ExpectedResolution("CB",!is_data());  

  double g1 = gRand->Gaus(0,1); 
  
  double smear_pt = muon.Pt()*(1+g1*resolution);

  return smear_pt;
}
