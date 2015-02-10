// $Id: TriggerSelector.cxx 25608 2013-12-08 18:38:30Z brendlin $

// Local include(s):
#include "../include/TriggerSelector.h"

//SFrameUtils include(s):
#include "Electron.h"
#include "MuonStaco.h"
#include "Quadruplet.h"

//RootCore include(s):
#include "TrigMuonEfficiency/MuonTriggerMatching.h"
#include "TrigMuonEfficiency/ElectronTriggerMatching.h"
#include "TrigMuonEfficiency/TriggerNavigationVariables.h"


ClassImp( TriggerSelector );

TriggerSelector::TriggerSelector(SCycleBase* parent, const char* name)
:   ToolBase( parent, name ),
    m_recoTreeName(""),
    m_StrawMenus14TeV("")
{

  DeclareProperty( "RecoTreeString", m_recoTreeName = "physics");
  DeclareProperty( "StrawMenus14TeV", m_StrawMenus14TeV = "");
  DeclareProperty( "BypassTriggerInCutflow", m_BypassTrigger= false);
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
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_el_Et", 						m_EF_el_Et );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_el_eta", 						m_EF_el_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_el_phi", 						m_EF_el_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_Muon_ROI", 					m_RoI_EF_mu_Muon_ROI );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_TrigMuonEFInfoContainer", 			m_RoI_EF_mu_TrigMuonEFInfoContainer );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_TrigMuonEFInfoContainerStatus", 		m_RoI_EF_mu_TrigMuonEFInfoContainerStatus );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_L2_mu_CombinedMuonFeature", 			m_RoI_L2_mu_CombinedMuonFeature );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_L2_mu_CombinedMuonFeatureStatus", 			m_RoI_L2_mu_CombinedMuonFeatureStatus );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_L2_mu_MuonFeature", 				m_RoI_L2_mu_MuonFeature );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_L2_mu_Muon_ROI", 					m_RoI_L2_mu_Muon_ROI );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_MuonType",				m_EF_trigmuonef_track_MuonType );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_CB_pt", 				m_EF_trigmuonef_track_CB_pt );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_CB_eta", 				m_EF_trigmuonef_track_CB_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_CB_phi", 				m_EF_trigmuonef_track_CB_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_SA_pt", 				m_EF_trigmuonef_track_SA_pt );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_SA_eta", 				m_EF_trigmuonef_track_SA_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_track_SA_phi", 				m_EF_trigmuonef_track_SA_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmugirl_track_CB_pt", 				m_EF_trigmugirl_track_CB_pt );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmugirl_track_CB_eta", 				m_EF_trigmugirl_track_CB_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmugirl_track_CB_phi",				m_EF_trigmugirl_track_CB_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L2_combmuonfeature_eta", 				m_L2_combmuonfeature_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L2_combmuonfeature_phi", 				m_L2_combmuonfeature_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L2_muonfeature_eta", 					m_L2_muonfeature_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L2_muonfeature_phi", 					m_L2_muonfeature_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L1_mu_eta", 						m_L1_mu_eta );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L1_mu_phi", 						m_L1_mu_phi );
  ConnectVariable( m_recoTreeName.c_str(), "trig_L1_mu_thrName", 					m_L1_mu_thrName );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_TrigMuonEFIsolationContainer", 		m_RoI_EF_mu_TrigMuonEFIsolationContainer );
  ConnectVariable( m_recoTreeName.c_str(), "trig_RoI_EF_mu_TrigMuonEFIsolationContainerStatus", 	m_RoI_EF_mu_TrigMuonEFIsolationContainerStatus ) ;

  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_EF_mu4T",                                 m_trig_EF_trigmuonef_EF_mu4T ) ;
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_EF_mu6",                                  m_trig_EF_trigmuonef_EF_mu6 ) ;
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_EF_mu10",                                 m_trig_EF_trigmuonef_EF_mu10 ) ;
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_trigmuonef_EF_mu13",                                 m_trig_EF_trigmuonef_EF_mu13 ) ;

  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_el_EF_e7T_medium1",                                 m_trig_EF_el_EF_e7T_medium1 ) ;
  ConnectVariable( m_recoTreeName.c_str(), "trig_EF_el_EF_e12Tvh_medium1",                              m_trig_EF_el_EF_e12Tvh_medium1 ) ;


  triggerNavigationVariables = new TriggerNavigationVariables();
  triggerNavigationVariables->set_trig_DB_SMK(m_DB_SMK);

  triggerNavigationVariables->set_trig_Nav_n(m_Nav_n);
  triggerNavigationVariables->set_trig_Nav_chain_ChainId(m_Nav_chain_ChainId);
  triggerNavigationVariables->set_trig_Nav_chain_RoIType(m_Nav_chain_RoIType);
  triggerNavigationVariables->set_trig_Nav_chain_RoIIndex(m_Nav_chain_RoIIndex);

  //electron
  triggerNavigationVariables->set_trig_RoI_EF_e_egammaContainer_egamma_Electrons(m_RoI_EF_e_egammaContainer_egamma_Electrons);
  triggerNavigationVariables->set_trig_RoI_EF_e_egammaContainer_egamma_ElectronsStatus(m_RoI_EF_e_egammaContainer_egamma_ElectronsStatus);

  triggerNavigationVariables->set_trig_EF_el_n(m_EF_el_n);
  triggerNavigationVariables->set_trig_EF_el_Et(m_EF_el_Et);
  triggerNavigationVariables->set_trig_EF_el_eta(m_EF_el_eta);
  triggerNavigationVariables->set_trig_EF_el_phi(m_EF_el_phi);

  // muon 
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

  // Uncomment for trigger studies!
//   triggerNavigationVariables->set_trig_EF_trigmuonef_EF_mu4T(m_trig_EF_trigmuonef_EF_mu4T);
//   triggerNavigationVariables->set_trig_EF_trigmuonef_EF_mu6 (m_trig_EF_trigmuonef_EF_mu6 );
//   triggerNavigationVariables->set_trig_EF_trigmuonef_EF_mu10(m_trig_EF_trigmuonef_EF_mu10);
//   triggerNavigationVariables->set_trig_EF_trigmuonef_EF_mu13(m_trig_EF_trigmuonef_EF_mu13);

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

  muonTriggerMatchTool = new MuonTriggerMatching(triggerNavigationVariables);
  electronTriggerMatchTool = new ElectronTriggerMatching(triggerNavigationVariables);

//   if (m_StrawMenus14TeV == "")
//     m_logger << ALWAYS  << "m_StrawMenus14TeV is off. " << SLogger::endmsg;
//   else if (m_StrawMenus14TeV == "current")
//     m_logger << ALWAYS  << "m_StrawMenus14TeV is set to current " << m_StrawMenus14TeV << SLogger::endmsg;
//   else if (m_StrawMenus14TeV == "1e34")
//     m_logger << ALWAYS  << "m_StrawMenus14TeV is set to 1e34 " << m_StrawMenus14TeV << SLogger::endmsg;
//   else if (m_StrawMenus14TeV == "2e34A")
//     m_logger << ALWAYS  << "m_StrawMenus14TeV is set to 2e34A " << m_StrawMenus14TeV << SLogger::endmsg;
//   else if (m_StrawMenus14TeV == "2e34B")
//     m_logger << ALWAYS  << "m_StrawMenus14TeV is set to 2e34B " << m_StrawMenus14TeV << SLogger::endmsg;
//   else if (m_StrawMenus14TeV == "3e34")
//     m_logger << ALWAYS  << "m_StrawMenus14TeV is set to 3e34 " << m_StrawMenus14TeV << SLogger::endmsg;
//   else 
//     m_logger << ALWAYS  << "m_StrawMenus14TeV is set to something: " << m_StrawMenus14TeV << SLogger::endmsg;

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

  // Override trigger selection in cutflow! (for trigger studies)
  if (m_BypassTrigger) return true;

  if ( PassSingleLeptonTriggers(m_trigger_d3pdobject) ) return true;

  //dielectron
  if ( m_trigger_d3pdobject->EF_2e12Tvh_loose1() 	== 1) return true;

  //dimuon
  if ( m_trigger_d3pdobject->EF_2mu13()          	== 1) return true;
  if ( m_trigger_d3pdobject->EF_mu18_tight_mu8_EFFS()   == 1) return true;

  //electron-muon
  if ( m_trigger_d3pdobject->EF_e12Tvh_medium1_mu8()    == 1) return true;
  if ( m_trigger_d3pdobject->EF_e24vhi_loose1_mu8()     == 1) return true;
    
  return false;
}

bool TriggerSelector::PassSingleLeptonTriggers( const D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject ) {
  
  //single electron
  if ( m_trigger_d3pdobject->EF_e24vhi_medium1() 	== 1) return true;
  if ( m_trigger_d3pdobject->EF_e60_medium1()    	== 1) return true;

  //single muon
  if ( m_trigger_d3pdobject->EF_mu24i_tight()    	== 1) return true;
  if ( m_trigger_d3pdobject->EF_mu36_tight()      	== 1) return true;

  return false;
}

int TriggerSelector::FillTriggerBitword(Quadruplet* quad,const D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject){
  // Temporarily disable the bypass
  if(!m_BypassTrigger) return 0;
  bool BypassTrigger_store = m_BypassTrigger;
  m_BypassTrigger = false;

  int bitword = (0x1 << 0); // 1
  if (SelectTriggers(m_trigger_d3pdobject) && MatchTriggers(quad)) bitword = bitword | (0x1 <<  1); // the nominal trigger selection
  if (MatchTriggers(quad))                                         bitword = bitword | (0x1 <<  2); // No trigger firing required (as a test)
  if (Match_e60medium1(quad))                                      bitword = bitword | (0x1 <<  3); // e60_medium1
  if (Match_mu50tight(quad))                                       bitword = bitword | (0x1 <<  4); // mu50_tight
  if (Match_mu24_mu8_EFFS(quad))                                   bitword = bitword | (0x1 <<  5); // mu24_mu8_EFFS
  if (Match_mu24i_mu8_EFFS(quad))                                  bitword = bitword | (0x1 <<  6); // mu24_mu8_EFFS
  if (Match_e17Tvh_loose1_NoL1(quad))                              bitword = bitword | (0x1 <<  7); // e17Tvh_loose1
  if (Match_e25Tvh_loose1_NoL1(quad))                              bitword = bitword | (0x1 <<  8); // e25Tvh_loose1 for reference from march
  if (Match_e17Tvh_medium1_mu12(quad))                             bitword = bitword | (0x1 <<  9); // e17_medium_mu12
  if (Match_3mu6(quad))                                            bitword = bitword | (0x1 << 10); // Match_3mu6
  if (Match_mu18_mu8_EFFS(quad))                                   bitword = bitword | (0x1 << 11); // Support - looking at L1 muon ineff
  if (Match_e17Tvh_loose1_NoL1_20ofl(quad))                        bitword = bitword | (0x1 << 12); // e17Tvh_loose1 + 20 GeV ofl cutoff
  if (Match_2e12Tvh_medium1_mu12(quad))                            bitword = bitword | (0x1 << 13); // 2e12Tvh_medium1_mu12
  if (Match_e12_medium1_2mu8(quad))                                bitword = bitword | (0x1 << 14); // e12_medium1_2mu8
  if (Match_mu14i_2mu14(quad))                                     bitword = bitword | (0x1 << 15); // mu14i_2mu14
  if (Match_mu24_e7_medium(quad))                                  bitword = bitword | (0x1 << 16); // mu24_e7_medium
  if (Match_mu24_2mu4FS(quad))                                     bitword = bitword | (0x1 << 17); // mu24_2mu4FS
  if (Match_ThreeElectronTrigger(quad))                            bitword = bitword | (0x1 << 18); // ThreeElectronTrigger (40,20,12)
  if (Match_ThreeElectronTrigger302012(quad))                      bitword = bitword | (0x1 << 19); // ThreeElectronTrigger (30,20,12)
  if (Match_ThreeElectronTrigger301212(quad))                      bitword = bitword | (0x1 << 20); // ThreeElectronTrigger (30,12,12)
  //
  if (Match_mu24_mu8_EFFS(quad,0.04))                              bitword = bitword | (0x1 << 21); // mu24_mu8_EFFS etcone < 0.04
  if (Match_mu24_mu8_EFFS(quad,0.03))                              bitword = bitword | (0x1 << 22); // mu24_mu8_EFFS etcone < 0.03
  if (Match_mu24_mu8_EFFS(quad,0.02))                              bitword = bitword | (0x1 << 23); // mu24_mu8_EFFS etcone < 0.02
  if (Match_mu24_mu8_EFFS(quad,0.01))                              bitword = bitword | (0x1 << 24); // mu24_mu8_EFFS etcone < 0.01
  //
  if (Match_mu24_mu8_EFFS(quad,0.05,26000.))                       bitword = bitword | (0x1 << 25); // mu25_mu8_EFFS etcone < 0.05
  if (Match_mu24_mu8_EFFS(quad,0.05,28000.))                       bitword = bitword | (0x1 << 26); // mu26_mu8_EFFS etcone < 0.05
  if (Match_mu24_mu8_EFFS(quad,0.05,30000.))                       bitword = bitword | (0x1 << 27); // mu27_mu8_EFFS etcone < 0.05
  if (Match_mu24_mu8_EFFS(quad,0.05,32000.))                       bitword = bitword | (0x1 << 28); // mu28_mu8_EFFS etcone < 0.05
  if (Match_mu24_mu8_EFFS(quad,0.05,34000.))                       bitword = bitword | (0x1 << 29); // mu29_mu8_EFFS etcone < 0.05
  if (Match_mu24_mu8_EFFS(quad,0.05,36000.))                       bitword = bitword | (0x1 << 30); // mu30_mu8_EFFS etcone < 0.05

  // Then re-enable it.
  m_BypassTrigger = BypassTrigger_store;
  return bitword;
}

bool TriggerSelector::Match_e60medium1(Quadruplet* quad){
  std::vector<TLorentzVector*> electrons;
  quad->GetElectronTLVs(electrons);
  for (unsigned int i = 0; i < electrons.size(); i++){
    if( electronTriggerMatchTool->match(electrons.at(i)->Eta(), electrons.at(i)->Phi(), "EF_e60_medium1")    && (electrons.at(i)->Pt() > 1000.*60.)) return true;
  }
  return false;
}

bool TriggerSelector::Match_mu50tight(Quadruplet* quad){
  std::vector<TLorentzVector*> muons;
  quad->GetMuonTLVs(muons);
  for (unsigned int i = 0; i < muons.size(); i++){ 
    if( muonTriggerMatchTool->match(muons.at(i)->Eta(), muons.at(i)->Phi(), "EF_mu36_tight") && (muons.at(i)->Pt() > 1000.*50.)) return true;
  }
  return false;
}

bool TriggerSelector::Match_mu24_mu8_EFFS(Quadruplet* quad,double trkiso,double ptcut){
  std::vector<TLorentzVector*> muons;
  std::vector<Muon*> muons_muons;
  quad->GetMuonTLVs(muons);
  quad->GetMuons(muons_muons);
  
  std::pair<bool, bool> result1, result2;
  for (unsigned int i = 0; i < muons.size(); i++){
    for (unsigned int j = 0; j < muons.size(); j++){
      if (i >= j) continue;
      
      double pt1 = muons.at(i)->Pt();
      double pt2 = muons.at(j)->Pt();
      
      bool m1_passtrk = trkiso ? muons_muons.at(i)->ptcone(30)/muons_muons.at(i)->Pt() < trkiso : true;
      bool m2_passtrk = trkiso ? muons_muons.at(j)->ptcone(30)/muons_muons.at(j)->Pt() < trkiso : true;

      //
      // Need to understand the logic! Not symmetric!
      // Group by scenario! result1 == first input muon, result1.second == first input muon, in flipped scenario... etc.
      //
      muonTriggerMatchTool->matchDimuon(*(muons.at(i)), *(muons.at(j)), "EF_mu18_tight_mu8_EFFS", result1, result2);
      if (result1.first && result2.second && pt1 > ptcut && m1_passtrk && pt2 > 1000.*8.) return true;
      if (result2.first && result1.second && pt2 > ptcut && m1_passtrk && pt1 > 1000.*8.) return true;
    }
  }
  return false;
}

bool TriggerSelector::Match_mu18_mu8_EFFS(Quadruplet* quad){
  std::vector<TLorentzVector*> muons;
  quad->GetMuonTLVs(muons);
  
  std::pair<bool, bool> result1, result2;
  for (unsigned int i = 0; i < muons.size(); i++){
    for (unsigned int j = 0; j < muons.size(); j++){
      if (i >= j) continue;
      //
      // Need to understand the logic! Not symmetric!
      // Group by scenario! result1 == first input muon, result1.second == first input muon, in flipped scenario... etc.
      //
      muonTriggerMatchTool->matchDimuon(*(muons.at(i)), *(muons.at(j)), "EF_mu18_tight_mu8_EFFS", result1, result2);
      if (result1.first && result2.second) return true;
      if (result2.first && result1.second) return true;
    }
  }
  return false;
}

bool TriggerSelector::Match_3mu6(Quadruplet* quad){
  std::vector<TLorentzVector*> muons;
  quad->GetMuonTLVs(muons);

  int n_pass = 0;
  for (unsigned int i = 0; i < muons.size(); i++){
    if( muonTriggerMatchTool->match(muons.at(i)->Eta(), muons.at(i)->Phi(), "EF_mu6")) n_pass++;
  }
  return n_pass > 2;
}   

bool TriggerSelector::Match_e17Tvh_loose1_NoL1(Quadruplet* quad,double threshold){
  std::vector<TLorentzVector*> electrons;
  quad->GetElectronTLVs(electrons);
  
  bool result1, result2;	
  for (unsigned int i = 0; i < electrons.size(); i++){
    for (unsigned int j = 0; j < electrons.size(); j++){
      if (i >= j) continue;
      
      double pt1 = electrons.at(i)->Pt();
      double pt2 = electrons.at(j)->Pt();
      
      electronTriggerMatchTool->matchDielectron(*(electrons.at(i)), *(electrons.at(j)), "EF_2e12Tvh_loose1", result1, result2);
      if (result1 && result2 && pt1 > threshold && pt2 > threshold) return true;
    }
  }        
  
  return false;
}

bool TriggerSelector::Match_e17Tvh_medium1_mu12(Quadruplet* quad){
  std::vector<TLorentzVector*> electrons;
  quad->GetElectronTLVs(electrons);
  std::vector<TLorentzVector*> muons;
  quad->GetMuonTLVs(muons);

  for (unsigned int i = 0; i < electrons.size(); i++){
    for (unsigned int j = 0; j < muons.size(); j++){
      
      double pte = electrons.at(i)->Pt();
      double ptmu = muons.at(j)->Pt();
      
      bool ptThreshs = (pte > 17000. && ptmu > 12000.);
      bool matchemu  = electronTriggerMatchTool->matchElectronMuon(*(electrons.at(i)), *(muons.at(j)), "EF_e12Tvh_medium1_mu8");
      // mu10 for proper L1
      bool mu10      = muonTriggerMatchTool->match(muons.at(j)->Eta(), muons.at(j)->Phi(), "EF_mu10");
      if(matchemu && mu10 && ptThreshs) return true;
    }
  }     
  return false;
}

bool TriggerSelector::Match_2e12Tvh_medium1_mu12(Quadruplet* quad){
  std::vector<TLorentzVector*> electrons;
  quad->GetElectronTLVs(electrons);
  std::vector<TLorentzVector*> muons;
  quad->GetMuonTLVs(muons);
  
  for (unsigned int i = 0; i < electrons.size(); i++){
    for (unsigned int j = 0; j < electrons.size(); j++){
      if (i==j) continue;
      for (unsigned int k = 0; k < muons.size(); k++){

	double pte1 = electrons.at(i)->Pt();
	double pte2 = electrons.at(j)->Pt();
	double ptmu = muons.at(k)->Pt();
	bool ptThreshs = (ptmu > 12000.);
	bool matchemu = electronTriggerMatchTool->matchElectronMuon(*(electrons.at(i)), *(muons.at(k)), "EF_e12Tvh_medium1_mu8");
	bool othere   = matchesToEFTriggerEle(electrons.at(j),*m_trig_EF_el_EF_e12Tvh_medium1);
	if(ptThreshs && matchemu && othere) return true;
      }
    }   
  }  
  return false;
}

bool TriggerSelector::Match_ThreeElectronTrigger(Quadruplet* quad,double pt1,double pt2,double pt3){
  std::vector<TLorentzVector*> electrons;
  quad->GetElectronTLVs(electrons);

  for (unsigned int i = 0; i < electrons.size(); i++){
    for (unsigned int j = 0; j < electrons.size(); j++){
      if (i==j) continue;
      for (unsigned int k = 0; k < electrons.size(); k++){
	if (j==k) continue;
	if (i==k) continue;

	double pte1 = electrons.at(i)->Pt();
	double pte2 = electrons.at(j)->Pt();
	double pte3 = electrons.at(k)->Pt();
	
	bool ptThreshs = (pte1 > pt1 && pte2 > pt2 && pte3 > pt3);
	bool matche1 = electronTriggerMatchTool->match(electrons.at(i)->Eta(), electrons.at(i)->Phi(), "EF_e24vhi_medium1");
	bool matche2 = matchesToEFTriggerEle(electrons.at(j),*m_trig_EF_el_EF_e12Tvh_medium1);
	bool matche3 = matchesToEFTriggerEle(electrons.at(k),*m_trig_EF_el_EF_e12Tvh_medium1);
	if(ptThreshs && matche1 && matche2 && matche3) return true;
      }
    }   
  }  
  return false;
}

bool TriggerSelector::Match_e12_medium1_2mu8(Quadruplet* quad){
  std::vector<TLorentzVector*> electrons;
  quad->GetElectronTLVs(electrons);
  std::vector<TLorentzVector*> muons;
  quad->GetMuonTLVs(muons);
  
  for (unsigned int i = 0; i < electrons.size(); i++){
    for (unsigned int j = 0; j < muons.size(); j++){
      for (unsigned int k = 0; k < muons.size(); k++){
	if (j==k) continue;
	
	bool matchemu = electronTriggerMatchTool->matchElectronMuon(*(electrons.at(i)), *(muons.at(j)), "EF_e12Tvh_medium1_mu8");
	bool othermu  = muonTriggerMatchTool->match(muons.at(k)->Eta(), muons.at(k)->Phi(), "EF_mu8");
	if(matchemu && othermu) return true;
      }
    }   
  }  
  return false;
}

bool TriggerSelector::Match_mu24_e7_medium(Quadruplet* quad){
  std::vector<TLorentzVector*> electrons;
  quad->GetElectronTLVs(electrons);
  std::vector<TLorentzVector*> muons;
  quad->GetMuonTLVs(muons);
  
  for (unsigned int i = 0; i < muons.size(); i++){
    for (unsigned int j = 0; j < electrons.size(); j++){
      
      bool matchmu = muonTriggerMatchTool->match(muons.at(i)->Eta(), muons.at(i)->Phi(), "EF_mu24_tight");
      bool matche  = matchesToEFTriggerEle(electrons.at(j),*m_trig_EF_el_EF_e7T_medium1);
      if(matchmu && matche) return true;
    }
  }   
  return false;
}

bool TriggerSelector::Match_mu14i_2mu14(Quadruplet* quad){
  std::vector<TLorentzVector*> muons;
  std::vector<Muon*> muons_muons;
  quad->GetMuonTLVs(muons);
  quad->GetMuons(muons_muons);  
  
  for (unsigned int i = 0; i < muons.size(); i++){
    for (unsigned int j = 0; j < muons.size(); j++){
      if (i==j) continue;
      for (unsigned int k = 0; k < muons.size(); k++){
	if (j==k) continue;
	if (i==k) continue;
	
	double pt1 = muons.at(i)->Pt();
	double pt2 = muons.at(j)->Pt();
	double pt3 = muons.at(k)->Pt();
	
	bool p_pt1 = (pt1 > 14000.);
	bool p_pt2 = (pt2 > 14000.);
	bool p_pt3 = (pt3 > 14000.);
	
	bool m1_passtrk = muons_muons.at(i)->ptcone(30)/muons_muons.at(i)->Pt() < 0.05;
	
	bool match1 = muonTriggerMatchTool->match(muons.at(i)->Eta(), muons.at(i)->Phi(), "EF_mu13");
	bool match2 = muonTriggerMatchTool->match(muons.at(j)->Eta(), muons.at(j)->Phi(), "EF_mu13");
	bool match3 = muonTriggerMatchTool->match(muons.at(k)->Eta(), muons.at(k)->Phi(), "EF_mu13");
	if(p_pt1 && p_pt2 && p_pt3 && m1_passtrk && match1 && match2 && match3) return true;
      }
    }   
  }  
  return false;
}

bool TriggerSelector::Match_mu24_2mu4FS(Quadruplet* quad){
  std::vector<TLorentzVector*> muons;
  quad->GetMuonTLVs(muons);
  
  for (unsigned int i = 0; i < muons.size(); i++){
    for (unsigned int j = 0; j < muons.size(); j++){
      if (i==j) continue;
      for (unsigned int k = 0; k < muons.size(); k++){
	if (j==k) continue;
	if (i==k) continue;

	bool match1 = muonTriggerMatchTool->match(muons.at(i)->Eta(), muons.at(i)->Phi(), "EF_mu24_tight");
	bool match2 = muonTriggerMatchTool->match(muons.at(j)->Eta(), muons.at(j)->Phi(), "EF_mu4T");
	bool match3 = muonTriggerMatchTool->match(muons.at(k)->Eta(), muons.at(k)->Phi(), "EF_mu4T");
	if(match1 && match2 && match3) return true;
      }
    }   
  }  
  return false;
}

bool TriggerSelector::MatchTriggers( Quadruplet* quad ) {

  if (m_BypassTrigger) return true;

  std::vector<TLorentzVector*> muons;
  std::vector<TLorentzVector*> electrons;

  quad->GetMuonTLVs(muons);  
  quad->GetElectronTLVs(electrons);  

  double single_e_threshold_14TeV = 0;
  double di_e_threshold_1_14TeV = 0;
  double di_e_threshold_2_14TeV = 0;   
  double single_mu_threshold_14TeV = 0;
  double di_mu_threshold_1_14TeV = 0;
  double di_mu_threshold_2_14TeV = 0;
  double mue_threshold_e_14TeV = 0; 
  double mue_threshold_mu_14TeV = 0;

  if (m_StrawMenus14TeV == "1e34") {
    single_e_threshold_14TeV = 28; 
    di_e_threshold_1_14TeV = 20;   
    di_e_threshold_2_14TeV = 15;   
    single_mu_threshold_14TeV =25;
    di_mu_threshold_1_14TeV = 13;  
    di_mu_threshold_2_14TeV = 13;  
    mue_threshold_e_14TeV = 20; 
    mue_threshold_mu_14TeV = 8;
  } else if (m_StrawMenus14TeV == "2e34A") {
    single_e_threshold_14TeV = 33; 
    di_e_threshold_1_14TeV = 20;   
    di_e_threshold_2_14TeV = 20;   
    single_mu_threshold_14TeV =25;
    di_mu_threshold_1_14TeV = 13;  
    di_mu_threshold_2_14TeV = 13;  
    mue_threshold_e_14TeV = 20; 
    mue_threshold_mu_14TeV = 12;
  } else if (m_StrawMenus14TeV == "2e34B") { // COMMANDERED
    single_e_threshold_14TeV = 10000;//45; 
    di_e_threshold_1_14TeV = 17;//20;   
    di_e_threshold_2_14TeV = 17;//20;   
    single_mu_threshold_14TeV =25;
    di_mu_threshold_1_14TeV = 13;  
    di_mu_threshold_2_14TeV = 13;  
    mue_threshold_e_14TeV = 20; 
    mue_threshold_mu_14TeV = 12;
  } else if (m_StrawMenus14TeV == "3e34") {
    single_e_threshold_14TeV = 60; 
    di_e_threshold_1_14TeV = 25;   
    di_e_threshold_2_14TeV = 25;   
    single_mu_threshold_14TeV =25;
    di_mu_threshold_1_14TeV = 13;  
    di_mu_threshold_2_14TeV = 13;  
    mue_threshold_e_14TeV = 25; 
    mue_threshold_mu_14TeV = 12;
  } 

  //bool passes_trigger = false;

  bool pass_single_mu = false;
  bool pass_di_mu     = false;
  bool pass_single_e  = false;
  bool pass_di_e      = false;
  bool pass_mue       = false;

  //check muon triggers
  if (quad->Type() == Quadruplet::FourMuon || quad->Type() == Quadruplet::TwoMuonTwoElectron || quad->Type() == Quadruplet::TwoElectronTwoMuon ) {
            
    for (unsigned int i = 0; i < muons.size(); i++){
      if( muonTriggerMatchTool->match(muons.at(i)->Eta(), muons.at(i)->Phi(), "EF_mu24i_tight") && (muons.at(i)->Pt() > 1000.*single_mu_threshold_14TeV)) pass_single_mu = true;
      if( muonTriggerMatchTool->match(muons.at(i)->Eta(), muons.at(i)->Phi(), "EF_mu36_tight")  && (muons.at(i)->Pt() > 1000.*single_mu_threshold_14TeV)) pass_single_mu =  true;
    }  
        
    std::pair<bool, bool> result1, result2;	
    for (unsigned int i = 0; i < muons.size(); i++){
      for (unsigned int j = 0; j < muons.size(); j++){
	if (i >= j) continue;

	double pt1 = muons.at(i)->Pt();
	double pt2 = muons.at(j)->Pt();

	muonTriggerMatchTool->matchDimuon(*(muons.at(i)), *(muons.at(j)), "EF_2mu13", result1, result2);
        if (result1.first && result2.first && pt1 > 1000*di_mu_threshold_1_14TeV && pt2 > di_mu_threshold_2_14TeV) pass_di_mu =  true;

	// Don't need to worry about pt threshold logic here since the new pt thresholds are symmetric. A simplification.
	muonTriggerMatchTool->matchDimuon(*(muons.at(i)), *(muons.at(j)), "EF_mu18_tight_mu8_EFFS", result1, result2);
        if (((result1.first && result2.second) || (result2.first && result1.second)) && pt1 > 1000.*di_mu_threshold_1_14TeV && pt2 > di_mu_threshold_2_14TeV) pass_di_mu = true;
	
	//bool ismatched_and_passptthreshold =  (  ( result1.first && result2.second && ( muons.at(i)->Pt() > 19000.0 ) && ( muons.at(j)->Pt() > 9000.0 ) )
        //                                           || ( result2.first && result1.second && ( muons.at(i)->Pt() > 9000.0 ) && ( muons.at(j)->Pt() > 19000.0 ) ) ); 
      }
    }
  } 
  
  //check electron triggers
  if (quad->Type() == Quadruplet::FourElectron || quad->Type() == Quadruplet::TwoMuonTwoElectron || quad->Type() == Quadruplet::TwoElectronTwoMuon ) {
        
    for (unsigned int i = 0; i < electrons.size(); i++){
      if( electronTriggerMatchTool->match(electrons.at(i)->Eta(), electrons.at(i)->Phi(), "EF_e24vhi_medium1") && (electrons.at(i)->Pt() > 1000.*single_e_threshold_14TeV)) pass_single_e = true;
      if( electronTriggerMatchTool->match(electrons.at(i)->Eta(), electrons.at(i)->Phi(), "EF_e60_medium1")    && (electrons.at(i)->Pt() > 1000.*single_e_threshold_14TeV)) pass_single_e = true;
    }
          
    bool result1, result2;	
    for (unsigned int i = 0; i < electrons.size(); i++){
      for (unsigned int j = 0; j < electrons.size(); j++){
	if (i >= j) continue;

	double pt1 = electrons.at(i)->Pt();
	double pt2 = electrons.at(j)->Pt();
	
	electronTriggerMatchTool->matchDielectron(*(electrons.at(i)), *(electrons.at(j)), "EF_2e12Tvh_loose1", result1, result2);
	bool ptThresholdsSatisfied = ((pt1 > 1000.*di_e_threshold_1_14TeV && pt2 > 1000.*di_e_threshold_2_14TeV)
				      || (pt2 > 1000.*di_e_threshold_1_14TeV && pt1 > 1000.*di_e_threshold_2_14TeV));
        if (result1 && result2 && ptThresholdsSatisfied) pass_di_e = true;
      }
    }        
  }

  //check electron muon triggers

  if (quad->Type() == Quadruplet::TwoMuonTwoElectron || quad->Type() == Quadruplet::TwoElectronTwoMuon ) {
    
    for (unsigned int i = 0; i < electrons.size(); i++){
      for (unsigned int j = 0; j < muons.size(); j++){
	
	double pte = electrons.at(i)->Pt();
	double ptmu = muons.at(j)->Pt();

	bool ptThresholdsSatisfied = (pte > 1000.*mue_threshold_e_14TeV && ptmu > 1000.*mue_threshold_mu_14TeV);

	if( electronTriggerMatchTool->matchElectronMuon(*(electrons.at(i)), *(muons.at(j)), "EF_e12Tvh_medium1_mu8") && ptThresholdsSatisfied) pass_mue = true;
	if( electronTriggerMatchTool->matchElectronMuon(*(electrons.at(i)), *(muons.at(j)), "EF_e24vhi_loose1_mu8") && ptThresholdsSatisfied) pass_mue = true;
      }
    }     
  }

  bool passed_trigger = false;
  if (pass_single_mu) passed_trigger = true;
  if (pass_di_mu    ) passed_trigger = true;
  if (pass_single_e ) passed_trigger = true;
  if (pass_di_e     ) passed_trigger = true;
  if (pass_mue      ) passed_trigger = true;

  // fill trigger info per event
  quad->setPassedTrigger(passed_trigger);
  
  return passed_trigger;
  // OVERRIDE!
  //return true;
}


bool TriggerSelector::MatchTriggers( Muon * muon1, Muon * muon2 ) {

  std::vector<TLorentzVector*> muons;

  TLorentzVector* muon1_TLV=new TLorentzVector();
  TLorentzVector* muon2_TLV=new TLorentzVector();

  muon1->FillTLV(muon1_TLV);
  muon2->FillTLV(muon2_TLV);

  muons.push_back(muon1_TLV);
  muons.push_back(muon2_TLV);


  //check muon triggers
    for (unsigned int i = 0; i < muons.size(); i++){ 

      if( muonTriggerMatchTool->match(muons.at(i)->Eta(), muons.at(i)->Phi(), "EF_mu24i_tight")) return true;
      
      if( muonTriggerMatchTool->match(muons.at(i)->Eta(), muons.at(i)->Phi(), "EF_mu36_tight")) return true;
   }

    std::pair<bool, bool> result1, result2;
    for (unsigned int i = 0; i < muons.size(); i++){
      for (unsigned int j = 0; j < muons.size(); j++){
        if (i >= j) continue;

        muonTriggerMatchTool->matchDimuon(*(muons.at(i)), *(muons.at(j)), "EF_2mu13", result1, result2);
        if (result1.first && result2.first) return true;

        muonTriggerMatchTool->matchDimuon(*(muons.at(i)), *(muons.at(j)), "EF_mu18_tight_mu8_EFFS", result1, result2);
        if ((result1.first && result2.second) || (result2.first && result1.second)) return true;
      }
    }
 //no triggers matched, return false
  return false;
}

bool TriggerSelector::MatchTriggers( Electron * electron1, Electron * electron2 ) {

  std::vector<TLorentzVector*> electrons;

  TLorentzVector* electron1_TLV=new TLorentzVector();
  TLorentzVector* electron2_TLV=new TLorentzVector();

  electron1->FillTLV(electron1_TLV);
  electron2->FillTLV(electron2_TLV);

  electrons.push_back(electron1_TLV);
  electrons.push_back(electron2_TLV);

   for (unsigned int i = 0; i < electrons.size(); i++){
      if( electronTriggerMatchTool->match(electrons.at(i)->Eta(), electrons.at(i)->Phi(), "EF_e24vhi_medium1")) return true;
      if( electronTriggerMatchTool->match(electrons.at(i)->Eta(), electrons.at(i)->Phi(), "EF_e60_medium1")) return true;
    }

    bool result1, result2;
    for (unsigned int i = 0; i < electrons.size(); i++){
      for (unsigned int j = 0; j < electrons.size(); j++){
        if (i >= j) continue;

        electronTriggerMatchTool->matchDielectron(*(electrons.at(i)), *(electrons.at(j)), "EF_2e12Tvh_loose1", result1, result2);
        if (result1 && result2) return true;
      }
    }
  
  //no triggers matched, return false
  return false;
}

bool TriggerSelector::matchesToEFTriggerEle(TLorentzVector* ele
					    ,std::vector<int>& EF
					    ,double EF_thresh
					    //,bool EF_I=false
					    //,double EF_Ival=0.1
					    ,double deltar
					    ){
  
  //
  // Et threshold
  //
  if (EF_thresh >= 0.){
    m_logger << DEBUG << "Checking Et " << ele->Pt() << " against " << 1000.*EF_thresh << SLogger::endmsg;
    if (ele->Pt() < 1000.*EF_thresh) return false;
    }
  
//   //
//   // Isolation threshold
//   //
//   if (EF_I){
//     m_logger << DEBUG << "Checking iso " << el_ptcone20->at(i)/el_pt->at(i) << " against " << EF_Ival << SLogger::endmsg;
//     if (el_ptcone20->at(i)/el_pt->at(i) > EF_Ival) return false;
//   }
    
  //
  // DeltaR matching - do last! (In case some branches are missing or something.)
  //
  if (!EF.size() && m_EF_el_n) {
    m_logger << DEBUG << "Skipping DeltaR trigger matching! (Passs EF!) Branch missing?" << SLogger::endmsg;
    return true;
  }
  
  int iEF = -1;
  double tmpdeltaR;
  double DRmin=999.;
  
  for (int j=0;j<m_EF_el_n;j++){
    if (!EF.at(j)) continue;
    tmpdeltaR = GetDeltaR(ele->Eta(),ele->Phi(),m_EF_el_eta->at(j),m_EF_el_phi->at(j));
    m_logger << DEBUG << "tmpdeltaR " << tmpdeltaR << SLogger::endmsg;
    if (tmpdeltaR < DRmin){
      DRmin = tmpdeltaR;
      iEF = j;
    }
  }
  m_logger << DEBUG << "Checking DRmin " << DRmin << " against " << deltar << SLogger::endmsg;
  if(DRmin > deltar) return false;
  
  m_logger << DEBUG << "Passes EF!" << SLogger::endmsg;
  return true;
}
