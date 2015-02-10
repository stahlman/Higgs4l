// Dear emacs, this is -*- c++ -*-
// $Id: ZZ_Selection.h 16390 2012-07-09 13:40:47Z stahlman $
#ifndef ZZ_Selection_H
#define ZZ_Selection_H

// SFrame include(s):
#include "plug-ins/include/SSummedVar.h"

// AtlasSFrameUtils
#include "CycleBase.h"

//Common tools
//#include "GoodRunsListTool.h"
//#include "PileupReweightingTool.h"
//#include "ZPtReweightingTool.h"

// D3PDObjects
#include "EventInfoD3PDObject.h"
//#include "MCEvtD3PDObject.h"
//#include "TriggerD3PDObject.h"
//#include "TrigEFelD3PDObject.h"
#include "PrimaryVertexD3PDObject.h"
//#include "ElectronD3PDObject.h"
//#include "PhotonD3PDObject.h"
#include "MuonStacoD3PDObject.h"
//#include "JetD3PDObject.h"
#include "METD3PDObject.h"
//#include "TruthD3PDObject.h"

#include "TRandom3.h"
#include "TLorentzVector.h"
#include <list>

/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 16390 $
 */
class ZZ_Selection : public CycleBase {

public:
   /// Default constructor
   ZZ_Selection();
   /// Default destructor
   ~ZZ_Selection();

   /// Function called at the beginning of the cycle
   virtual void BeginCycleImp() throw( SError );
   /// Function called at the end of the cycle
   virtual void EndCycleImp() throw( SError );

   /// Function called at the beginning of a new input data
   virtual void BeginInputDataImp( const SInputData& ) throw( SError );
   /// Function called after finishing to process an input data
   virtual void EndInputDataImp  ( const SInputData& ) throw( SError );

  virtual void BeginMasterInputDataImp( const SInputData& ) throw( SError );
  virtual void EndMasterInputDataImp( const SInputData& ) throw( SError );

   /// Function called after opening each new input file
   virtual void BeginInputFileImp( const SInputData& ) throw( SError );

   /// Function called for every event
   virtual void ExecuteEventImp( const SInputData&, Double_t ) throw( SError );

private:
   //
   // Put all your private variables here
   //

  bool m_doGRL;
  bool isMC;
  bool m_doSmear;
  bool m_doTrig;
  bool m_doVert;
  bool m_doZ;
  bool m_doZWindow;

  std::string m_puDataRootFileName;
  std::string m_puMCRootFileName;
  std::string m_puMCRootHistName;

  std::string m_recoTreeName;
  std::string m_trigTreeName;
  std::string c_jet_container;

  TRandom3* gRand_Calo;

  //SmearMuonPt* mcp_smear;			
  //SmearMuonPt mcp_smear;
  
  SSummedVar< Int_t > cf_preselect;
  SSummedVar< Int_t > cf_grl;
  SSummedVar< Int_t > cf_trigger;
  SSummedVar< Int_t > cf_vertex;
  SSummedVar< Int_t > cf_jetcleaning;
  SSummedVar< Int_t > cf_two_comb_mu;
  SSummedVar< Int_t > cf_eta;
  SSummedVar< Int_t > cf_pt;
  SSummedVar< Int_t > cf_id_hits;
  SSummedVar< Int_t > cf_MS_hits;
  SSummedVar< Int_t > cf_d0;
  SSummedVar< Int_t > cf_z0;
  SSummedVar< Int_t > cf_isolation;
  SSummedVar< Int_t > cf_charge;
  SSummedVar< Int_t > cf_mass_mumu;
  SSummedVar< Float_t > cf_weight;
  //SSummedVar< Int_t > cf_good_ele;
  //SSummedVar< Int_t > cf_two_ele;
  //SSummedVar< Int_t > cf_second_good_ele;
  //SSummedVar< Int_t > cf_mass_ee;

  // D3PDReader objects for input/output
  D3PDReader::EventInfoD3PDObject* m_event_d3pdobject;
  //D3PDReader::MCEvtD3PDObject* m_mcevt_d3pdobject;
  //D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject;
  //D3PDReader::TrigEFelD3PDObject* m_trigEFel_d3pdobject;
  D3PDReader::METD3PDObject* m_met_d3pdobject;
  D3PDReader::PrimaryVertexD3PDObject* m_vxp_d3pdobject;
  //D3PDReader::ElectronD3PDObject* m_in_electron_d3pdobject;
  //D3PDReader::PhotonD3PDObject* m_in_photon_d3pdobject;
  D3PDReader::MuonStacoD3PDObject* m_muon_d3pdobject;
  //D3PDReader::JetD3PDObject* m_jet_d3pdobject;
  //D3PDReader::TruthD3PDObject* m_truth_d3pdobject;

  std::string c_output_event_branches_regex;
  std::string c_output_mcevt_branches_regex;
  //std::string c_output_trigger_branches_regex;
  //std::string c_output_trigEFel_branches_regex;
  std::string c_output_vxp_branches_regex;
  //std::string c_output_electron_branches_regex;
  //std::string c_output_photon_branches_regex;
  std::string c_output_muon_branches_regex;
  std::string c_output_jet_branches_regex;
  std::string c_output_met_branches_regex;
  std::string c_output_truth_branches_regex;


  float pileupEventWeight;
  float scaledMuPileupEventWeight1;
  float scaledMuPileupEventWeight2;
  float zPtEventWeight;
  float evt_actualIntPerXing;
  float evt_averageIntPerXing;
  int n_vertices;
  int n_jetspt20;
  int run_number;
  int evt_number;
  int lb_number;
  int bcid;
  int bunch_config_id;
  float mt;

  vector<unsigned int> v_runs;
  vector<unsigned int> v_evts;
  vector<double>       v_mass;

  double m_12;
  double m_34;
  double m_4l;

  double m_ll;
  double pt_ll;
  double phi_ll;
  double eta_ll;

  double l_pt;
  double l_phi;
  double l_eta;
  double l_d0;
  double l_z0;
  double l_eloss;

  double sl_pt;
  double sl_phi;
  double sl_eta;
  double sl_d0;
  double sl_z0;
  double sl_eloss;

  float met_lochadtopo_ex;
  float met_lochadtopo_ey;
  float met_lochadtopo_et;
  float met_lochadtopo_phi;
  float met_lochadtopo_sumet;
  
  float met_reffinal_ex;
  float met_reffinal_ey;
  float met_reffinal_et;
  float met_reffinal_phi;
  float met_reffinal_sumet;

  float met_refgamma_ex;
  float met_refgamma_ey;
  float met_refgamma_et;
  float met_refgamma_phi;
  float met_refgamma_sumet;
  
  float met_reftau_ex;
  float met_reftau_ey;
  float met_reftau_et;
  float met_reftau_phi;
  float met_reftau_sumet;

  float met_refele_ex;
  float met_refele_ey;
  float met_refele_et;
  float met_refele_phi;
  float met_refele_sumet;
  
  float met_refjet_ex;
  float met_refjet_ey;
  float met_refjet_et;
  float met_refjet_phi;
  float met_refjet_sumet;

  float met_muonboy_ex;
  float met_muonboy_ey;
  float met_muonboy_et;
  float met_muonboy_phi;
  float met_muonboy_sumet;

  float met_refmuon_ex;
  float met_refmuon_ey;
  float met_refmuon_et;
  float met_refmuon_phi;
  float met_refmuon_sumet;

  float met_cellout_ex;
  float met_cellout_ey;
  float met_cellout_et;
  float met_cellout_phi;
  float met_cellout_sumet;

  float met_cellout_eflow_ex;
  float met_cellout_eflow_ey;
  float met_cellout_eflow_et;
  float met_cellout_eflow_phi;
  float met_cellout_eflow_sumet;

  float met_softjets_ex;
  float met_softjets_ey;
  float met_softjets_et;
  float met_softjets_phi;
  float met_softjets_sumet;

  float met_reffinal_em_ex;
  float met_reffinal_em_ey;
  float met_reffinal_em_et;
  float met_reffinal_em_phi;
  float met_reffinal_em_sumet;

  float met_refgamma_em_ex;
  float met_refgamma_em_ey;
  float met_refgamma_em_et;
  float met_refgamma_em_phi;
  float met_refgamma_em_sumet;

  float met_reftau_em_ex;
  float met_reftau_em_ey;
  float met_reftau_em_et;
  float met_reftau_em_phi;
  float met_reftau_em_sumet;
  
  float met_refele_em_ex;
  float met_refele_em_ey;
  float met_refele_em_et;
  float met_refele_em_phi;
  float met_refele_em_sumet;
  
  float met_refjet_em_ex;
  float met_refjet_em_ey;
  float met_refjet_em_et;
  float met_refjet_em_phi;
  float met_refjet_em_sumet;

//  float met_muonboy_em_ex;
//  float met_muonboy_em_ey;
//  float met_muonboy_em_et;
//  float met_muonboy_em_phi;
//  float met_muonboy_em_sumet;

  float met_refmuon_em_ex;
  float met_refmuon_em_ey;
  float met_refmuon_em_et;
  float met_refmuon_em_phi;
  float met_refmuon_em_sumet;

  float met_cellout_em_ex;
  float met_cellout_em_ey;
  float met_cellout_em_et;
  float met_cellout_em_phi;
  float met_cellout_em_sumet;

  float met_softjets_em_ex;
  float met_softjets_em_ey;
  float met_softjets_em_et;
  float met_softjets_em_phi;
  float met_softjets_em_sumet;

  float met_truth_nonint_ex;
  float met_truth_nonint_ey;
  float met_truth_nonint_et;
  float met_truth_nonint_phi;
  float met_truth_nonint_sumet;
  
  float muon_pt;
  float muon_phi;
  float muon_eta;
  float muon_eloss;
  float muon_pz;
/*
  float sMET_calo_ex ;
  float sMET_calo_ey ;
  float sMET_calo_et ;

  float sfinal_met_ex;
  float sfinal_met_ey;
  float sfinal_met_et;
  float smuon_pt;
  float smuon_phi;
  float smuon_eta;
  float smuon_eloss;
  float smuon_pz;
*/
   // Macro adding the functions for dictionary generation
   ClassDef( ZZ_Selection, 0 );

}; // class ZZ_Selection

#endif // ZZ_Selection_H
