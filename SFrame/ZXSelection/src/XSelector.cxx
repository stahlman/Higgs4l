// $Id: XSelector.cxx 24814 2013-09-19 09:18:13Z brendlin $

// Local include(s):
#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "EnergyRescalerTool.h"
#include "IDTool.h"

//RootCore
#include "egammaAnalysisUtils/CaloIsoCorrection.h"

#include "../include/XSelector.h"

const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( XSelector );

XSelector::XSelector(SCycleBase* parent, const char* name)
  : ToolBase( parent, name ),
    cf_preselect(0),
    cf_author(0),
    cf_momentum(0),
    cf_eta(0),
    cf_blayer(0),
    cf_pixel(0),
    cf_sct(0),
    cf_holes(0),
    cf_trt(0),
    cf_d0z0(0),
    cf_overlap(0),
    cf_isolation(0)

{
  DeclareProperty( "SelectCombinedMuons", 	m_selectCombinedMuons = true );
  DeclareProperty( "SelectSegmentTaggedMuons", 	m_selectSegmentTaggedMuons = true );
  DeclareProperty( "SelectStandAloneMuons", 	m_selectStandAloneMuons = true );
  DeclareProperty( "SelectCaloMuons", 		m_selectCaloMuons = true );

  DeclareProperty( "IsolationConeSize", m_cone_size = 20 );

  DeclareProperty( "DoSmear", m_doSmear = true);
  DeclareProperty( "DoCalibration", m_doCalibration = true);
  DeclareProperty( "VetoCrack", m_vetoCrack = false);
  DeclareProperty( "PTCutLikelihood", m_ptcutLikelihood = 0);
  DeclareProperty( "DoTruthMatchEleZ", m_doTruthMatchEleZ = false);

  DeclareProperty( "DoElectronID", m_doElectronID = true );
  DeclareProperty( "DoML", m_doML = false );
  DeclareProperty( "DoML_HCP", m_doML_HCP = false );
  DeclareProperty( "DoLikelihood", m_doLikelihood = true );
  DeclareProperty( "DoLikelihoodMedium", m_doLikelihoodMedium = false );
  DeclareProperty( "DoLikelihoodLoose", m_doLikelihoodLoose = false );
  DeclareProperty( "ID_OP", m_ID_OP = "Loose");


  DeclareProperty( "DoBlayer", m_doBlayer = false );

  DeclareProperty( "DoTrackIsolation", m_doTrkIso = false );
  DeclareProperty( "DoCaloIsolation",  m_doCaloIso = false );
  DeclareProperty( "DoD0",  m_doD0 = false );

  DeclareProperty( "DoMuTrackIsolation", m_doMuTrkIso = false );
  DeclareProperty( "DoMuCaloIsolation",  m_doMuCaloIso = false );
  DeclareProperty( "DoMuD0",             m_doMuD0 = false );
  DeclareProperty( "DoMuD0Significance", m_doMuD0Significance = false );

  return;
  
}

XSelector::~XSelector() {

 return;

}

void XSelector::BeginMasterInputData( const SInputData& ) throw( SError ){

  
  return;
  
}

void XSelector::EndMasterInputData( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                        X Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of muons passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons Before Cuts..........:"<<cf_preselect  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Author..........:"<<cf_author     <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)"  <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Momentum........:"<<cf_momentum   <<" ("<<((double)cf_momentum)/((double)cf_author)*100 <<"%)"  <<" ("<<((double)cf_momentum)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Eta.............:"<<cf_eta	   <<" ("<<((double)cf_eta)/((double)cf_momentum)*100 <<"%)"	 <<" ("<<((double)cf_eta)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After B-Layer.........:"<<cf_blayer     <<" ("<<((double)cf_blayer)/((double)cf_eta)*100 <<"%)" <<" ("<<((double)cf_blayer)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Pixel...........:"<<cf_pixel	   <<" ("<<((double)cf_pixel)/((double)cf_blayer)*100 <<"%)" <<" ("<<((double)cf_pixel)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After SCT.............:"<<cf_sct	   <<" ("<<((double)cf_sct)/((double)cf_pixel)*100 <<"%)"  <<" ("<<((double)cf_sct)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Si Holes........:"<<cf_holes	   <<" ("<<((double)cf_holes)/((double)cf_sct)*100 <<"%)"  <<" ("<<((double)cf_holes)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After TRT Hits........:"<<cf_trt	   <<" ("<<((double)cf_trt)/((double)cf_holes)*100 <<"%)"  <<" ("<<((double)cf_trt)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After D0/Z0...........:"<<cf_d0z0	   <<" ("<<((double)cf_d0z0)/((double)cf_trt)*100 <<"%)"  <<" ("<<((double)cf_d0z0)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Overlap Removal.:"<<cf_overlap    <<" ("<<((double)cf_overlap)/((double)cf_d0z0)*100 <<"%)"  <<" ("<<((double)cf_overlap)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Isolation.......:"<<cf_isolation    <<" ("<<((double)cf_isolation)/((double)cf_overlap)*100 <<"%)"  <<" ("<<((double)cf_isolation)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;


  return;

}


void XSelector::SelectXElectrons( std::vector<Electron*> &sel_electrons, const D3PDReader::ElectronD3PDObject* m_electron_d3pdobject, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, int n_vertices ) {

  //electron selection
   m_logger << DEBUG << "Electron Selection " << SLogger::endmsg;

  std::vector<Electron> all_eles;  
  ParticleElementBuilder::build( all_eles, (*m_electron_d3pdobject) );

  m_logger << DEBUG << "Number of electrons in event: " << all_eles.size() << SLogger::endmsg;

  for(std::vector<Electron>::iterator itr = all_eles.begin(); itr != all_eles.end(); ++itr) { 
    
    //truthmatch
    if(!is_data() && m_doTruthMatchEleZ  && !(fabs((*itr).truth_type()) == 11 && (*itr).truth_matched() && (*itr).truth_mothertype() == 23) ) {
      continue;
    }
    if(!is_data() && m_doTruthMatchEleZ) m_logger << DEBUG << "truthtype: " << fabs((*itr).truth_type()) << ", truthmatched: " <<(*itr).truth_matched() << ", truthmothertype: " << (*itr).truth_mothertype()<< SLogger::endmsg;
    cf_preselect++;

    //author
    m_logger << DEBUG << "Author cut" << SLogger::endmsg;
    if(!((*itr).author() == 1 || (*itr).author() == 3)) continue;
    cf_author++;

    //energy correction
    if (m_doSmear || m_doCalibration) {
        GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
        energy_rescaler->ApplyEnergyRescaler( (*itr), m_event_d3pdobject->EventNumber(), m_event_d3pdobject->RunNumber());         
    }
    
    int xBitMask = 0;
    //electron ID
    GET_TOOL(id, IDTool, "IDTool");
    bool pass_electronID = false;

    if(id->passLikelihood((*itr),m_ID_OP,n_vertices)) {       
      if(m_doLikelihood) pass_electronID = true; 
      xBitMask = xBitMask | XSelector::PassLikelihood;       
    }
/*
    if(id->passLikelihood((*itr),"Medium",n_vertices)) { 
       if(m_doLikelihoodMedium)pass_electronID = true;
       xBitMask = xBitMask | XSelector::PassMediumLikelihood;       
    }

    if(id->passLikelihood((*itr),"Loose",n_vertices)) { 
       if(m_doLikelihoodLoose) pass_electronID = true;
       xBitMask = xBitMask | XSelector::PassLooseLikelihood;               
    }
*/
   if(id->passLikelihood((*itr),LikeEnum::Loose,n_vertices)) {
       xBitMask = xBitMask | XSelector::PassLooseLikelihood;
    }

//    if(id->passLikelihood((*itr),LLikeEnum::Loose_BL_PixLow,n_vertices)) {
//        xBitMask = xBitMask | XSelector::PassLoose_BL_PixLowLikelihood;
//     }

//    if(id->passLikelihood((*itr),LLikeEnum::Loose_BL_PixMed,n_vertices)) {
//        xBitMask = xBitMask | XSelector::PassLoose_BL_PixMedLikelihood;
//     }

//    if(id->passLikelihood((*itr),LLikeEnum::Loose_BL_PixHigh,n_vertices)) {
//        xBitMask = xBitMask | XSelector::PassLoose_BL_PixHighLikelihood;
//     }

    if(id->passML((*itr),m_ID_OP)) {
       if(m_doML) pass_electronID = true; 
       xBitMask = xBitMask | XSelector::PassML;                      
    }

    if(id->passML_HCP((*itr),m_ID_OP)) {
       if(m_doML_HCP) pass_electronID = true;
       xBitMask = xBitMask | XSelector::PassML_HCP;                      
    }
    if(id->passLikelihood((*itr),"Very_Loose",n_vertices)) {
       //if(m_doLikelihoodVeryLoose) pass_electronID = true;
       xBitMask = xBitMask | XSelector::PassVeryLooseLikelihood;
    }
    if(id->passLikelihood((*itr),"ControlRegion_3_5X",n_vertices)) {
       //if(m_doLikelihood3_5Loose) pass_electronID = true;
       xBitMask = xBitMask | XSelector::Pass3_5LooseLikelihood;
    }
    if(id->passML((*itr),"Relaxed")) {
       xBitMask = xBitMask | XSelector::PassMLRelaxed;
    }

    if (m_doElectronID && !pass_electronID) continue;
        

    //Blayer (should be in new Multilepton ID anyways, and in some likelihoods, here the option to require in additionally)    
    bool passBLayer = true;
    if((*itr).expectHitInBLayer()){
         if((*itr).nBLHits() < 1 || ((*itr).nPixHits()+(*itr).nPixelDeadSensors()) < 2) passBLayer = false;
    } else {
          if((*itr).nPixHits()+(*itr).nPixelDeadSensors() < 2) passBLayer = false;
    }

    if(m_doBlayer && !passBLayer) continue;
    if (passBLayer) xBitMask = xBitMask | XSelector::PassBLayer;
    cf_electronid++;
    
    //eta cuts 
    m_logger << DEBUG << "Eta cut" << SLogger::endmsg;
    if(!(fabs((*itr).cl_eta()) < 2.47)) continue;
    m_logger << DEBUG << "m_vetoCrack " <<m_vetoCrack << SLogger::endmsg;
    if(m_vetoCrack && fabs((*itr).cl_eta())<1.52 && fabs((*itr).cl_eta())>1.37) continue;
    cf_eta++;

     //et cuts 7 GeV
    m_logger << DEBUG << "Et cut" << SLogger::endmsg;
    if(!((*itr).cl_Et() > 7000.)) continue;
    if(m_ptcutLikelihood && ((*itr).cl_Et() < 10000.)) continue;
    cf_et++;

    //object quality
    m_logger << DEBUG << "OQ cut" << SLogger::endmsg;
    if(!(((*itr).OQ()&1446) == 0)) continue;
    cf_oq++;

    //z0 cut
    m_logger << DEBUG << "Z0 cut" << SLogger::endmsg;
    if(!(fabs((*itr).trackz0pvunbiased()) < 10.)) continue;
    cf_z0++;

    //overlap removal
    m_logger << DEBUG << "overlap removal" << SLogger::endmsg;
    bool passed_overlap = true;
    for(unsigned int i = 0; i < sel_electrons.size(); ++i) { 
       if ( ((*itr).Unrefittedtrack_d0()     == sel_electrons.at(i)->Unrefittedtrack_d0())
      	 && ((*itr).Unrefittedtrack_z0()     == sel_electrons.at(i)->Unrefittedtrack_z0())
      	 && ((*itr).Unrefittedtrack_theta()  == sel_electrons.at(i)->Unrefittedtrack_theta())
      	 && ((*itr).Unrefittedtrack_phi()    == sel_electrons.at(i)->Unrefittedtrack_phi())
      	 && ((*itr).Unrefittedtrack_qoverp() == sel_electrons.at(i)->Unrefittedtrack_qoverp()) ){
	 
	   if ((*itr).cl_E_cal() > sel_electrons.at(i)->cl_E_cal()) {
             //m_logger << WARNING << "Removing Electron" << SLogger::endmsg;
       	     sel_electrons.erase(sel_electrons.begin()+i); 
	     i--;//subtract one from i to keep counting consistent
	     cf_overlap--;//remove one electron from cutflow
   	   } else { passed_overlap = false; }
       }
    }
    if (!passed_overlap) continue;    
    cf_overlap++;

    bool passed_cl_overlap = true;
    double delta_phi = 0;
    for(unsigned int i = 0; i < sel_electrons.size(); ++i) { 
      delta_phi = (fabs((*itr).cl_phi() - sel_electrons.at(i)->cl_phi()) > TMath::Pi()) ? 2*TMath::Pi()-fabs((*itr).cl_phi() - sel_electrons.at(i)->cl_phi()) : fabs((*itr).cl_phi() - sel_electrons.at(i)->cl_phi());

       if ( (fabs((*itr).cl_eta() - sel_electrons.at(i)->cl_eta()) < 3*0.025)
	    //&& (fabs((*itr).cl_phi() - sel_electrons.at(i)->cl_phi()) < 5*0.025) ){
	    && (delta_phi < 5*0.025) ){

 	   if ((*itr).cl_E_cal() > sel_electrons.at(i)->cl_E_cal()) {
             //m_logger << WARNING << "Removing Electron" << SLogger::endmsg;
       	     sel_electrons.erase(sel_electrons.begin()+i); 
	     i--;//subtract one from i to keep counting consistent
	     cf_cl_overlap--;//remove one electron from cutflow
   	   } else { passed_cl_overlap = false; }
       }
    }
    if (!passed_cl_overlap) continue;    
    cf_cl_overlap++;

    //isolation cuts
    m_logger << DEBUG << "isolation cut" << SLogger::endmsg;
    bool passTrkIso = ((*itr).ptcone(m_cone_size)/(*itr).cl_Et() < 0.15);
    if (m_doTrkIso && !passTrkIso) continue;
    if (passTrkIso) xBitMask = xBitMask | XSelector::PassTrkIso;

    //bool passOptTrkIso = ((*itr).ptcone(30)/(*itr).cl_Et() < 0.20);
    //if (passOptTrkIso) xBitMask = xBitMask | XSelector::PassOptTrkIso;

    bool passCaloIso = ((*itr).etcone(m_cone_size, !is_data())/(*itr).cl_Et() < 0.20);
    if (m_doCaloIso && !passCaloIso) continue;
    if (passCaloIso) xBitMask = xBitMask | XSelector::PassCaloIso;

    //bool passOptCaloIso = ((*itr).etcone(30, !is_data())/(*itr).cl_Et() < 0.35);
    //if (passOptCaloIso) xBitMask = xBitMask | XSelector::PassOptCaloIso;
        
    //d0 cut
    m_logger << DEBUG << "d0 significance cut" << SLogger::endmsg;
    bool passD0 = (fabs((*itr).D0())/(*itr).tracksigd0pvunbiased() < 6.5);
    if (m_doD0 && !passD0) continue;
    if (passD0) xBitMask = xBitMask | XSelector::PassD0;

    //TRTrphif1
    m_logger << DEBUG << "TRTrphif1" << SLogger::endmsg;
    bool passTRTrphif1 = 0;

    double eta = (*itr).tracketa();
    double TRTHighTOutliersRatio = (*itr).TRTHighTOutliersRatio();
    int nTRTTotal = (*itr).nTRTHits()+(*itr).nTRTOutliers();

    bool passf1=((*itr).f1()>0.1);
    bool passrphi=((*itr).rphi()>0.9);
    //
    int ibin_eta_TRT = -1;
    double CutTR[6] = {0.09, 0.105, 0.11, 0.125, 0.145, 0.16};
    double CutBinEta_TRT[6] = {0.1, 0.625, 1.07, 1.304, 1.752, 2.0};
    //Find eta bin
    for (unsigned int ibinEta=0;ibinEta<6;ibinEta++) {
      if ( ibinEta == 0 ){
        if ( fabs(eta) < CutBinEta_TRT[ibinEta] ) {
          ibin_eta_TRT = ibinEta;
        }
      }
      else {
        if ( fabs(eta) >= CutBinEta_TRT[ibinEta-1] && fabs(eta) < CutBinEta_TRT[ibinEta] ) {
          ibin_eta_TRT = ibinEta;
       }
      }
  }
  //
  bool passTR=false;
  if (ibin_eta_TRT >= 0) {//apply the cut 
    passTR= (TRTHighTOutliersRatio > CutTR[ibin_eta_TRT]) ;
  }
  if(fabs(eta)<2.0 || nTRTTotal>=10 ){
     if(passTR&&passf1) passTRTrphif1 = 1;
  }
  else{
      if(passf1&&passrphi) passTRTrphif1 = 1;
  }
  if (passTRTrphif1) xBitMask = xBitMask | XSelector::PassTRTrphif1;
  

   //Set Bitmask  
   (*itr).SetXBitMask(xBitMask);
    
    sel_electrons.push_back( new Electron(*itr));

  }
  
  m_logger << DEBUG << "Number of selected electrons in event: " << sel_electrons.size() << SLogger::endmsg;

				    
  return;
}

void XSelector::SelectXMuons( std::vector<Muon*>& sel_muons, const D3PDReader::MuonD3PDObject* m_muon_d3pdobject, const D3PDReader::MuonD3PDObject* m_muon_calo_d3pdobject, unsigned int evt_number ) {

  //Muon Selection
  m_logger << DEBUG << "Muon Selection " << SLogger::endmsg;
  
  // select muons 
  std::vector<Muon> all_muons;
  ParticleElementBuilder::build( all_muons, (*m_muon_d3pdobject) );

  std::vector<Muon> all_calo_muons;
  if(m_selectCaloMuons) ParticleElementBuilder::build( all_calo_muons, (*m_muon_calo_d3pdobject) );
  
  m_logger << DEBUG << "Number of muons in event: " << all_muons.size() + all_calo_muons.size()<< SLogger::endmsg;
  
  
  // select CB+ST muons first (for overlap removal later)
  for(std::vector<Muon>::iterator itr = all_muons.begin(); itr != all_muons.end(); ++itr) {  
 
     cf_preselect++;
     
     //Staco CB+ST muons      
     if (!(((*itr).author() == 6 || (*itr).author() == 7)  && ((*itr).isStandAloneMuon() == 0))) continue;      
     
     if ((*itr).author() == 6 && m_selectCombinedMuons == false) continue;
     if ((*itr).author() == 7 && m_selectSegmentTaggedMuons == false) continue;
     cf_author++;
     
     //smear momentum (MC only)
     if (m_doSmear && !is_data()) {
       GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
       energy_rescaler->ApplyEnergyRescaler( (*itr), evt_number);          
     }
     
     //pt cut
     if(!((*itr).Pt() > 6000.0 )) continue;     
     cf_momentum++;

     //eta cut
     if(!( fabs((*itr).eta()) < 2.7)) continue;        
     cf_eta++;
	 
     bool id_pass = false;
     //ID hit cuts
     if( !((*itr).expectBLayerHit()) || ((*itr).nBLHits() > 0 ) ){
     cf_blayer++;
     if( (*itr).nPixHits() + (*itr).nPixelDeadSensors() > 0 ){
     cf_pixel++;
     if( (*itr).nSCTHits() + (*itr).nSCTDeadSensors() > 4 ){
     cf_sct++;
     if( (*itr).nPixHoles()+ (*itr).nSCTHoles() < 3 ){	   
     cf_holes++;
	int ntrt = (*itr).nTRTHits() + (*itr).nTRTOutliers();
	if ( (fabs((*itr).eta()) > 0.1) && (fabs((*itr).eta()) < 1.9) ){
	  if ((ntrt > 5.0) && ((*itr).nTRTOutliers() < 0.9*ntrt) ) id_pass = true;
	} else if ( ntrt > 5 ) {
	  if ( (*itr).nTRTOutliers() < 0.9*ntrt ) id_pass = true;
	} else { id_pass = true; }	
     }}}}//ID Cuts

     if (!id_pass) continue;
     cf_trt++;
     	      
     int xBitMask = 0;
 
     //d0 cut
     bool passD0 = (fabs((*itr).D0()) < 1.0 );
     if (m_doMuD0 && !passD0) continue;
     if (passD0) xBitMask |= XSelector::PassD0;
          
     //z0 cut
     if (!(fabs((*itr).Z0()) < 10.0 )) continue;
     cf_d0z0++;
     
     //no overlap removal		  
     cf_overlap++;

     //isolation cuts
     bool passTrkIso = ((*itr).ptcone(m_cone_size)/(*itr).Pt() < 0.15);
     if (m_doTrkIso && !passTrkIso) continue;
     if (passTrkIso) xBitMask |= XSelector::PassTrkIso;

     bool passCaloIso = ((*itr).etcone(m_cone_size)/(*itr).Pt() < 0.30);
     if (m_doCaloIso && !passCaloIso) continue;
     if (passCaloIso) xBitMask |= XSelector::PassCaloIso;

     cf_isolation++;

     //d0 significance cut
     bool passDoSignificance = ((*itr).D0Significance() < 3.5);
     if (m_doMuD0Significance && !passDoSignificance) continue;
     if (passDoSignificance) xBitMask |= XSelector::PassD0Significance;

    (*itr).SetXBitMask(xBitMask);
     //Good muon!
    (*itr).SetXBitMask(xBitMask);
     sel_muons.push_back( new Muon(*itr) );

  }// loop over muons
  
  //CaloTag Muons  
  for(std::vector<Muon>::iterator itr = all_calo_muons.begin(); itr != all_calo_muons.end(); ++itr) {  

     cf_preselect++;

     //select CaloTag muons       
     if (!( ((*itr).isCaloMuon()) && ((*itr).caloMuonIdTag() > 10 || (*itr).caloLRLikelihood() > 0.9 ))) continue;
     cf_author++;
     
     //smear momentum (MC only)
     if (m_doSmear && !is_data()) {
       GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
       energy_rescaler->ApplyEnergyRescaler( (*itr), evt_number);          
     }
     
     //pt cut
     if (!((*itr).Pt() > 15000)) continue;
     cf_momentum++;
     
     //eta cut
     if (!(fabs((*itr).eta()) < 0.1)) continue;	 
     cf_eta++;
	 
     //ID hit cuts
     bool id_pass = false;
     if( !((*itr).expectBLayerHit()) || ((*itr).nBLHits() > 0 ) ){
     cf_blayer++;
     if( (*itr).nPixHits() + (*itr).nPixelDeadSensors() > 0 ){
     cf_pixel++;
     if( (*itr).nSCTHits() + (*itr).nSCTDeadSensors() > 4 ){
     cf_sct++;
     if( (*itr).nPixHoles()+ (*itr).nSCTHoles() < 3 ){	   
     cf_holes++;
	int ntrt = (*itr).nTRTHits() + (*itr).nTRTOutliers();
	if ( (ntrt < 6) || ((*itr).nTRTOutliers() < 0.9*ntrt) ){
          cf_trt++;
 	  id_pass = true;
	}
     }}}}//ID Cuts

     if (!id_pass) continue;
     
     int xBitMask = 0;
 
     //d0 cut
     bool passD0 = (fabs((*itr).D0()) < 1.0 );
     if (m_doMuD0 && !passD0) continue;
     if (passD0) xBitMask |= XSelector::PassD0;
       
     //z0
     if (!(fabs((*itr).Z0()) < 10.0 )) continue;
     cf_d0z0++;
     
     //overlap removal
     bool overlap_pass = true;
     for (unsigned int i = 0; i < sel_muons.size(); i++){
	if (MuonDeltaR(sel_muons.at(i),(*itr),1) < 0.1) overlap_pass = false;
     }
     if (!overlap_pass) continue;
     cf_overlap++;

     //isolation cuts
     bool passTrkIso = ((*itr).ptcone(m_cone_size)/(*itr).Pt() < 0.15);
     if (m_doTrkIso && !passTrkIso) continue;
     if (passTrkIso) xBitMask |= XSelector::PassTrkIso;

     bool passCaloIso = ((*itr).etcone(m_cone_size)/(*itr).Pt() < 0.30);
     if (m_doCaloIso && !passCaloIso) continue;
     if (passCaloIso) xBitMask |= XSelector::PassCaloIso;

     cf_isolation++;

     //d0 significance cut
     bool passDoSignificance = ((*itr).D0Significance() < 3.5);
     if (m_doMuD0Significance && !passDoSignificance) continue;
     if (passDoSignificance) xBitMask |= XSelector::PassD0Significance;

     //Good Muon!
    (*itr).SetXBitMask(xBitMask);
     sel_muons.push_back( new Muon(*itr) );
  }
  
  //Standalone muons
  for(std::vector<Muon>::iterator itr = all_muons.begin(); itr != all_muons.end(); ++itr) {  
      
     if(m_selectStandAloneMuons == false) continue; 
      
     //Staco StandAlone muons      
     if (!(((*itr).author() == 6)  && ((*itr).isStandAloneMuon() == 1))) continue;        
     cf_author++;

     //smear momentum (MC only)
     if (m_doSmear && !is_data()) {
       GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
       energy_rescaler->ApplyEnergyRescaler( (*itr), evt_number);          
     }

     //pt cut
     if(!((*itr).Pt() > 6000)) continue;
     cf_momentum++;

     //eta cuts
     if(!((fabs((*itr).eta()) > 2.5) && (fabs((*itr).eta()) < 2.7))) continue;	 
     cf_eta++;


     //MS hits cut
     if (!(((*itr).nCSCEtaHits() + (*itr).nCSCPhiHits() > 0) && ((*itr).nMDTEMHits() > 0) && ((*itr).nMDTEOHits() > 0))) continue;
     cf_blayer++;
     cf_pixel++;
     cf_sct++;
     cf_holes++;
     cf_trt++;
     cf_d0z0++;

     //overlap removal
     bool overlap_pass = true;
     for (unsigned int i = 0; i < sel_muons.size(); i++){
	if ((sel_muons.at(i)->author() == 7) && (MuonDeltaR(sel_muons.at(i),(*itr), 0) < 0.2)) overlap_pass = false;
     }

     if (!overlap_pass) continue;
     cf_overlap++;
    
     int xBitMask = 0;
     //no d0 cut
     xBitMask |= XSelector::PassD0;
    
     //isolation cuts
     bool passTrkIso = ((*itr).ptcone(m_cone_size)/(*itr).Pt() < 0.15);
     if (m_doTrkIso && !passTrkIso) continue;
     if (passTrkIso) xBitMask |= XSelector::PassTrkIso;

     bool passCaloIso = ((*itr).etcone(m_cone_size)/(*itr).Pt() < 0.15);
     if (m_doCaloIso && !passCaloIso) continue;
     if (passCaloIso) xBitMask |= XSelector::PassCaloIso;

     cf_isolation++;
    
     // no d0 significance cut for standalone muons
     xBitMask |= XSelector::PassD0Significance;

     //Good Muon!
    (*itr).SetXBitMask(xBitMask);
     sel_muons.push_back( new Muon(*itr) );

  }//loop over muons
 
  m_logger << DEBUG << "Number of selected muons in event: " << sel_muons.size() << SLogger::endmsg;
  
  return;


}


double XSelector::MuonDeltaR(Muon* m1, Muon m2, int track_params) {  
  
  if (track_params == 0){ //combined
    return DeltaR(m1->eta(),m1->phi() ,m2.eta(),m2.phi());
  }

  if (track_params == 1){ //id
    return DeltaR(-log(tan(m1->id_theta()/2)),m1->id_phi() ,-log(tan(m2.id_theta()/2)),m2.id_phi());
  }
  
  m_logger << WARNING << "XSelector::MuonDeltaR(): Unknown track parameters.  Returning 0" << SLogger::endmsg;
  return 0;
}

double XSelector::DeltaR(double eta1, double phi1, double eta2, double phi2) {      
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  double delta_eta = eta1 - eta2;  
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}

