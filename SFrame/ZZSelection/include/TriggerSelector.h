// Dear emacs, this is -*- c++ -*-
// $Id: TriggerSelector.h 25608 2013-12-08 18:38:30Z brendlin $
#ifndef TriggerSelector_H
#define TriggerSelector_H

#include <string>

// D3PDObjects
#include "TriggerD3PDObject.h"

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Quadruplet.h"

//RootCore include(s):
#include "TrigMuonEfficiency/MuonTriggerMatching.h"
#include "TrigMuonEfficiency/ElectronTriggerMatching.h"
#include "TrigMuonEfficiency/TriggerNavigationVariables.h"

/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 25608 $
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
   bool PassSingleLeptonTriggers( const D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject );
   bool MatchTriggers( Quadruplet* quad );
   bool MatchTriggers( Muon *muon1, Muon* muon2 );
   bool MatchTriggers( Electron *electron1, Electron* electron2 );
  int FillTriggerBitword(Quadruplet* quad,const D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject);

  // triggers
  bool Match_e60medium1(Quadruplet* quad);
  bool Match_mu50tight(Quadruplet* quad);
  bool Match_mu24_mu8_EFFS(Quadruplet* quad,double trkiso=0.,double ptcut=24000.);
  bool Match_mu24i_mu8_EFFS(Quadruplet* quad){return Match_mu24_mu8_EFFS(quad,0.05);};
  bool Match_e17Tvh_loose1_NoL1(Quadruplet* quad,double threshold=17000.);
  bool Match_e25Tvh_loose1_NoL1(Quadruplet* quad){return Match_e17Tvh_loose1_NoL1(quad,25000.);}; // 
  bool Match_e17Tvh_medium1_mu12(Quadruplet* quad);
  bool Match_3mu6(Quadruplet* quad);
  bool Match_mu18_mu8_EFFS(Quadruplet* quad);
  bool Match_e17Tvh_loose1_NoL1_20ofl(Quadruplet* quad){return Match_e17Tvh_loose1_NoL1(quad,20000.);}; // 
  bool Match_2e12Tvh_medium1_mu12(Quadruplet* quad);
  bool Match_e12_medium1_2mu8(Quadruplet* quad);
  bool Match_mu14i_2mu14(Quadruplet* quad);
  bool Match_mu24_e7_medium(Quadruplet* quad);
  bool Match_mu24_2mu4FS(Quadruplet* quad);
  bool Match_ThreeElectronTrigger      (Quadruplet* quad,double pt1=40000.,double pt2=20000.,double pt3=12000.);
  bool Match_ThreeElectronTrigger302012(Quadruplet* quad){return Match_ThreeElectronTrigger(quad,30000.,20000.,12000.);};
  bool Match_ThreeElectronTrigger301212(Quadruplet* quad){return Match_ThreeElectronTrigger(quad,30000.,12000.,12000.);};

  bool matchesToEFTriggerEle(TLorentzVector* ele
			     ,std::vector<int>& EF
			     ,double EF_thresh=-1.
			     ,double deltar=0.15
			     );

  double GetDeltaR(double eta1,double phi1,double eta2,double phi2){
    double d1 = eta1-eta2;
    double d2 = TVector2::Phi_mpi_pi(phi1-phi2);
    return sqrt(d1*d1+d2*d2);
  };

private:
   //
   // Put all your private variables here
   //

   TriggerNavigationVariables* triggerNavigationVariables;
   MuonTriggerMatching *muonTriggerMatchTool;
   ElectronTriggerMatching *electronTriggerMatchTool;
   
   std::string m_recoTreeName;
   std::string m_StrawMenus14TeV;

  bool m_BypassTrigger;
   
   std::vector< unsigned int >* m_trig_L1_TAV;
   unsigned int m_DB_SMK;
   int m_Nav_n;
   std::vector<short>* m_Nav_chain_ChainId;
   std::vector<std::vector<int> >* m_Nav_chain_RoIType;
   std::vector<std::vector<int> >* m_Nav_chain_RoIIndex;
   std::vector<std::vector<int> >* m_RoI_EF_e_egammaContainer_egamma_Electrons;
   std::vector<std::vector<int> >* m_RoI_EF_e_egammaContainer_egamma_ElectronsStatus;
   int m_EF_el_n;
   std::vector<float>* m_EF_el_Et;
   std::vector<float>* m_EF_el_eta;
   std::vector<float>* m_EF_el_phi;
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

  std::vector<int>* m_trig_EF_trigmuonef_EF_mu4T;
  std::vector<int>* m_trig_EF_trigmuonef_EF_mu6;
  std::vector<int>* m_trig_EF_trigmuonef_EF_mu10;
  std::vector<int>* m_trig_EF_trigmuonef_EF_mu13;

  std::vector<int>* m_trig_EF_el_EF_e7T_medium1;
  std::vector<int>* m_trig_EF_el_EF_e12Tvh_medium1;

   // Macro adding the functions for dictionary generation
   ClassDef( TriggerSelector, 0 );

}; // class TriggerSelector

#endif // TriggerSelector_H
