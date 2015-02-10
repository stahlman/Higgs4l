// $Id: TriggerSelector.cxx 18741 2012-10-06 17:11:47Z stahlman $

// Local include(s):
#include "../include/TriggerSelector.h"

//SFrameUtils include(s):
#include "Electron.h"


//RootCore include(s):
#include "TrigMuonEfficiency/ElectronTriggerMatching.h"
#include "TrigMuonEfficiency/TriggerNavigationVariables.h"


ClassImp( TriggerSelector );

TriggerSelector::TriggerSelector(SCycleBase* parent, const char* name)
:   ToolBase( parent, name ),
    m_recoTreeName("")
{

  DeclareProperty( "RecoTreeString", m_recoTreeName );

  return;
  
}

TriggerSelector::~TriggerSelector() {

 return;

}

void TriggerSelector::BeginInputFile( const SInputData& ) throw( SError ){

  //Connect all variables
  ConnectVariable( m_recoTreeName.c_str(), "trig_L1_TAV", 						m_trig_L1_TAV );
  ConnectVariable( m_recoTreeName.c_str(), "trig_DB_SMK", 						m_DB_SMK );
  ConnectVariable( m_recoTreeName.c_str(), "trig_Nav_n",  						m_Nav_n );
  ConnectVariable( m_recoTreeName.c_str(), "trig_Nav_chain_ChainId", 					m_Nav_chain_ChainId );
  ConnectVariable( m_recoTreeName.c_str(), "trig_Nav_chain_RoIType", 					m_Nav_chain_RoIType );
  ConnectVariable( m_recoTreeName.c_str(), "trig_Nav_chain_RoIIndex", 					m_Nav_chain_RoIIndex );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_e_egammaContainer_egamma_Electrons", 		m_RoI_EF_e_egammaContainer_egamma_Electrons );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_e_egammaContainer_egamma_ElectronsStatus", 	m_RoI_EF_e_egammaContainer_egamma_ElectronsStatus );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_el_n", 						m_EF_el_n );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_el_eta", 						m_EF_el_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_el_phi", 						m_EF_el_phi );
  //muons otherwise the code is complaining
   ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_Muon_ROI",                                   m_RoI_EF_mu_Muon_ROI );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_TrigMuonEFInfoContainer",                    m_RoI_EF_mu_TrigMuonEFInfoContainer );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_TrigMuonEFInfoContainerStatus",              m_RoI_EF_mu_TrigMuonEFInfoContainerStatus );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_L2_mu_CombinedMuonFeature",                        m_RoI_L2_mu_CombinedMuonFeature );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_L2_mu_CombinedMuonFeatureStatus",                  m_RoI_L2_mu_CombinedMuonFeatureStatus );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_L2_mu_MuonFeature",                                m_RoI_L2_mu_MuonFeature );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_L2_mu_Muon_ROI",                                   m_RoI_L2_mu_Muon_ROI );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_MuonType",                         m_EF_trigmuonef_track_MuonType );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_CB_pt",                            m_EF_trigmuonef_track_CB_pt );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_CB_eta",                           m_EF_trigmuonef_track_CB_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_CB_phi",                           m_EF_trigmuonef_track_CB_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_SA_pt",                            m_EF_trigmuonef_track_SA_pt );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_SA_eta",                           m_EF_trigmuonef_track_SA_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_SA_phi",                           m_EF_trigmuonef_track_SA_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmugirl_track_CB_pt",                            m_EF_trigmugirl_track_CB_pt );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmugirl_track_CB_eta",                           m_EF_trigmugirl_track_CB_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmugirl_track_CB_phi",                           m_EF_trigmugirl_track_CB_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L2_combmuonfeature_eta",                               m_L2_combmuonfeature_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L2_combmuonfeature_phi",                               m_L2_combmuonfeature_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L2_muonfeature_eta",                                   m_L2_muonfeature_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L2_muonfeature_phi",                                   m_L2_muonfeature_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L1_mu_eta",                                            m_L1_mu_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L1_mu_phi",                                            m_L1_mu_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L1_mu_thrName",                                        m_L1_mu_thrName );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_TrigMuonEFIsolationContainer",               m_RoI_EF_mu_TrigMuonEFIsolationContainer );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_TrigMuonEFIsolationContainerStatus",         m_RoI_EF_mu_TrigMuonEFIsolationContainerStatus ) ;


  triggerNavigationVariables = new TriggerNavigationVariables();
  //triggerNavigationVariables->set_trig_L1_TAV(trig_L1_TAV);
  triggerNavigationVariables->set_trig_DB_SMK(m_DB_SMK);

  triggerNavigationVariables->set_trig_Nav_n(m_Nav_n);
  triggerNavigationVariables->set_trig_Nav_chain_ChainId(m_Nav_chain_ChainId);
  triggerNavigationVariables->set_trig_Nav_chain_RoIType(m_Nav_chain_RoIType);
  triggerNavigationVariables->set_trig_Nav_chain_RoIIndex(m_Nav_chain_RoIIndex);

  //electron
  triggerNavigationVariables->set_trig_RoI_EF_e_egammaContainer_egamma_Electrons(m_RoI_EF_e_egammaContainer_egamma_Electrons);
  triggerNavigationVariables->set_trig_RoI_EF_e_egammaContainer_egamma_ElectronsStatus(m_RoI_EF_e_egammaContainer_egamma_ElectronsStatus);

  triggerNavigationVariables->set_trig_EF_el_n(m_EF_el_n);
  triggerNavigationVariables->set_trig_EF_el_eta(m_EF_el_eta);
  triggerNavigationVariables->set_trig_EF_el_phi(m_EF_el_phi);

  //muons/otherwise the code is complaing
   triggerNavigationVariables->set_trig_RoI_EF_mu_Muon_ROI(m_RoI_EF_mu_Muon_ROI);
  triggerNavigationVariables->set_trig_RoI_EF_mu_TrigMuonEFInfoContainer(m_RoI_EF_mu_TrigMuonEFInfoContainer);
  triggerNavigationVariables->set_trig_RoI_EF_mu_TrigMuonEFInfoContainerStatus(m_RoI_EF_mu_TrigMuonEFInfoContainerStatus);

  triggerNavigationVariables->set_trig_RoI_L2_mu_CombinedMuonFeature(m_RoI_L2_mu_CombinedMuonFeature);
  triggerNavigationVariables->set_trig_RoI_L2_mu_CombinedMuonFeatureStatus(m_RoI_L2_mu_CombinedMuonFeatureStatus);
  triggerNavigationVariables->set_trig_RoI_L2_mu_MuonFeature(m_RoI_L2_mu_MuonFeature);
  triggerNavigationVariables->set_trig_RoI_L2_mu_Muon_ROI(m_RoI_L2_mu_Muon_ROI);

  triggerNavigationVariables->set_trig_EF_trigmuonef_track_MuonType(m_EF_trigmuonef_track_MuonType);
  triggerNavigationVariables->set_trig_EF_trigmuonef_track_CB_pt(m_EF_trigmuonef_track_CB_pt);
  triggerNavigationVariables->set_trig_EF_trigmuonef_track_CB_eta(m_EF_trigmuonef_track_CB_eta);
  triggerNavigationVariables->set_trig_EF_trigmuonef_track_CB_phi(m_EF_trigmuonef_track_CB_phi);
  triggerNavigationVariables->set_trig_EF_trigmuonef_track_SA_pt(m_EF_trigmuonef_track_SA_pt);
  triggerNavigationVariables->set_trig_EF_trigmuonef_track_SA_eta(m_EF_trigmuonef_track_SA_eta);
  triggerNavigationVariables->set_trig_EF_trigmuonef_track_SA_phi(m_EF_trigmuonef_track_SA_phi);

  triggerNavigationVariables->set_trig_EF_trigmugirl_track_CB_pt(m_EF_trigmugirl_track_CB_pt);
  triggerNavigationVariables->set_trig_EF_trigmugirl_track_CB_eta(m_EF_trigmugirl_track_CB_eta);
  triggerNavigationVariables->set_trig_EF_trigmugirl_track_CB_phi(m_EF_trigmugirl_track_CB_phi);

  triggerNavigationVariables->set_trig_L2_combmuonfeature_eta(m_L2_combmuonfeature_eta);
  triggerNavigationVariables->set_trig_L2_combmuonfeature_phi(m_L2_combmuonfeature_phi);
  triggerNavigationVariables->set_trig_L2_muonfeature_eta(m_L2_muonfeature_eta);
  triggerNavigationVariables->set_trig_L2_muonfeature_phi(m_L2_muonfeature_phi);

  triggerNavigationVariables->set_trig_L1_mu_eta(m_L1_mu_eta);
  triggerNavigationVariables->set_trig_L1_mu_phi(m_L1_mu_phi);
  triggerNavigationVariables->set_trig_L1_mu_thrName(m_L1_mu_thrName);

  triggerNavigationVariables->set_trig_RoI_EF_mu_TrigMuonEFIsolationContainer(m_RoI_EF_mu_TrigMuonEFIsolationContainer); // for 2012 isolated trigger
  triggerNavigationVariables->set_trig_RoI_EF_mu_TrigMuonEFIsolationContainerStatus(m_RoI_EF_mu_TrigMuonEFIsolationContainerStatus); // for 2012 isolated trigger



  if (!triggerNavigationVariables->isValid()) {
    m_logger << WARNING  << "TriggerSelector(): VARIABLES NOT CORRECTLY SET"<<  SLogger::endmsg;
  }

  electronTriggerMatchTool = new ElectronTriggerMatching(triggerNavigationVariables);

  return;

}


bool TriggerSelector::hasMCTriggerInfo() {

    m_logger << DEBUG << "MC Trigger Bug Cut " << SLogger::endmsg;
    
    unsigned int trig_word = ( *m_trig_L1_TAV )[0];
    
    m_logger << DEBUG << "trigger word: "<< trig_word << SLogger::endmsg;
    
    if( ! ( (trig_word >> 17 ) & 0x1 ) ) return false;
  
  return true;
}

bool TriggerSelector::SelectTriggers( const D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject ) {

  //single electron
  if ( m_trigger_d3pdobject->EF_e24vhi_medium1() 	== 1) return true;
  if ( m_trigger_d3pdobject->EF_e60_medium1()    	== 1) return true;

  return false;
}


bool TriggerSelector::MatchTriggers( Electron& electron ) {

  
  //check electron triggers
      
    bool isMatchedElectron = false;
    
    if( electronTriggerMatchTool->match(electron.tracketa(), electron.trackphi(), "EF_e24vhi_medium1")){
 	   isMatchedElectron = true;
    }

    if( electronTriggerMatchTool->match(electron.tracketa(), electron.trackphi(), "EF_e60_medium1")){
        isMatchedElectron = true;
    }
  
  
   //no triggers matched, return false
  return isMatchedElectron;
}
