// Dear emacs, this is -*- c++ -*-
// $Id: TriggerSelector.h 18741 2012-10-06 17:11:47Z stahlman $
#ifndef TriggerSelector_H
#define TriggerSelector_H

#include <string>

// D3PDObjects
#include "TriggerD3PDObject.h"

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Electron.h"

//RootCore include(s):
#include "TrigMuonEfficiency/ElectronTriggerMatching.h"
#include "TrigMuonEfficiency/TriggerNavigationVariables.h"

/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 18741 $
 */
class TriggerSelector : public ToolBase {

public:
   /// Default constructor
   TriggerSelector( SCycleBase* parent, const char* name = "Trigger" );
   
   /// Default destructor
   ~TriggerSelector();

   virtual void BeginInputFile( const SInputData& ) throw( SError );

   bool hasMCTriggerInfo();
   bool SelectTriggers( const D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject );
   bool MatchTriggers( Electron& el );

private:
   //
   // Put all your private variables here
   //

   TriggerNavigationVariables* triggerNavigationVariables;
   ElectronTriggerMatching *electronTriggerMatchTool;
   
   std::string m_recoTreeName;
   
   std::vector< unsigned int >* m_trig_L1_TAV;
   unsigned int m_DB_SMK;
   int m_Nav_n;
   std::vector<short>* m_Nav_chain_ChainId;
   std::vector<std::vector<int> >* m_Nav_chain_RoIType;
   std::vector<std::vector<int> >* m_Nav_chain_RoIIndex;
   std::vector<std::vector<int> >* m_RoI_EF_e_egammaContainer_egamma_Electrons;
   std::vector<std::vector<int> >* m_RoI_EF_e_egammaContainer_egamma_ElectronsStatus;
   int m_EF_el_n;
   std::vector<float>* m_EF_el_eta;
   std::vector<float>* m_EF_el_phi;
   //muons - otherwise the code is complaining
   std::vector<int>* m_RoI_EF_mu_Muon_ROI;
   std::vector<std::vector<int> >*  m_RoI_EF_mu_TrigMuonEFInfoContainer;
   std::vector<std::vector<int> >*  m_RoI_EF_mu_TrigMuonEFInfoContainerStatus;
   std::vector<int>* m_RoI_L2_mu_CombinedMuonFeature;
   std::vector<int>* m_RoI_L2_mu_CombinedMuonFeatureStatus;
   std::vector<int>* m_RoI_L2_mu_MuonFeature;
   std::vector<int>* m_RoI_L2_mu_Muon_ROI;
   std::vector<std::vector<int> >* m_EF_trigmuonef_track_MuonType;
   std::vector<std::vector<float> >* m_EF_trigmuonef_track_CB_pt;
   std::vector<std::vector<float> >* m_EF_trigmuonef_track_CB_eta;
   std::vector<std::vector<float> >* m_EF_trigmuonef_track_CB_phi;
   std::vector<std::vector<float> >* m_EF_trigmuonef_track_SA_pt;
   std::vector<std::vector<float> >* m_EF_trigmuonef_track_SA_eta;
   std::vector<std::vector<float> >* m_EF_trigmuonef_track_SA_phi;
   std::vector<std::vector<float> >* m_EF_trigmugirl_track_CB_pt;
   std::vector<std::vector<float> >* m_EF_trigmugirl_track_CB_eta;
   std::vector<std::vector<float> >* m_EF_trigmugirl_track_CB_phi;
   std::vector<float>* m_L2_combmuonfeature_eta;
   std::vector<float>* m_L2_combmuonfeature_phi;
   std::vector<float>* m_L2_muonfeature_eta;
   std::vector<float>* m_L2_muonfeature_phi;
   std::vector<float>* m_L1_mu_eta;
   std::vector<float>* m_L1_mu_phi;
   std::vector<std::string>*  m_L1_mu_thrName;
   std::vector<std::vector<int> >* m_RoI_EF_mu_TrigMuonEFIsolationContainer;
   std::vector<std::vector<int> >* m_RoI_EF_mu_TrigMuonEFIsolationContainerStatus;




   // Macro adding the functions for dictionary generation
   ClassDef( TriggerSelector, 0 );

}; // class TriggerSelector

#endif // TriggerSelector_H
