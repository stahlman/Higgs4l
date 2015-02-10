// Dear emacs, this is -*- c++ -*-
// $Id: ZZCutFlow.h 27180 2014-05-27 13:55:11Z stahlman $
#ifndef ZZCutFlow_H
#define ZZCutFlow_H

// SFrame include(s):
#include "plug-ins/include/SSummedVar.h"

// AtlasSFrameUtils
#include "CycleBase.h"

//RootCore
//#include "TileTripReader/TTileTripReader.h" 
#include "CategoriesMVA/CategoriesMVA.h"
#include "HiggsZZ4lUtils/BRCorrection.h"

// D3PDObjects
#include "EventInfoD3PDObject.h"
#include "MCEvtD3PDObject.h"
//#include "TrigMuonEFInfoD3PDObject.h"
//#include "TrigElectronD3PDObject.h"
#include "TriggerD3PDObject.h"
#include "PrimaryVertexD3PDObject.h"
#include "ElectronD3PDObject.h"
#include "PhotonD3PDObject.h"
#include "MuonD3PDObject.h"
#include "JetD3PDObject.h"
#include "METD3PDObject.h"
#include "TruthParticleD3PDObject.h"

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Muon.h"
#include "Electron.h"
#include "Jet.h"
#include "Quadruplet.h"
#include "ParticleElementBuilder.h"

//CommonTools
#include "ZZPtSystTool.h"

#include "TRandom3.h"
#include "TLorentzVector.h"
#include <list>

/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 27180 $
 */
class ZZCutFlow : public CycleBase {

public:
   /// Default constructor
   ZZCutFlow();
   /// Default destructor
   ~ZZCutFlow();

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
  bool m_doLarError;
  bool m_doTileError;
  bool m_doDaqError;
  bool m_doTrig;
  bool m_doVert;

  bool DoLeptonSF;
  bool DoTriggerSF;
  bool DoPileupSF;
  bool DoVertexSF;

  std::string m_recoTreeName;
  std::string m_trigTreeName;
  std::string c_jet_container;

  TRandom3* gRand_Calo;
  
  SSummedVar< Int_t > cf_preselect;
  SSummedVar< Int_t > cf_el_preselect;
  SSummedVar< Int_t > cf_mu_preselect;
  SSummedVar< Int_t > cf_jet_preselect;
  SSummedVar< Int_t > cf_grl;
  SSummedVar< Int_t > cf_larerror;
  SSummedVar< Int_t > cf_tileerror;
  SSummedVar< Int_t > cf_daqerror;
  SSummedVar< Int_t > cf_trigger;
  SSummedVar< Int_t > cf_el_trigger;
  SSummedVar< Int_t > cf_mu_trigger;
  SSummedVar< Int_t > cf_jet_trigger; 
  SSummedVar< Int_t > cf_vertex;
  SSummedVar< Int_t > cf_el_vertex;
  SSummedVar< Int_t > cf_mu_vertex;
  SSummedVar< Int_t > cf_jet_vertex;
  SSummedVar< Int_t > cf_leptons;
  SSummedVar< Int_t > cf_quads;
  SSummedVar< Int_t > cf_four_mu;
  SSummedVar< Int_t > cf_four_el;
  SSummedVar< Int_t > cf_two_mu_two_el;
  SSummedVar< Int_t > cf_jetcuts;
  SSummedVar< Int_t > cf_addleptoncut;
  SSummedVar< Int_t > cf_vbf;
  SSummedVar< Int_t > cf_vh_hadronic;
  SSummedVar< Int_t > cf_vh_leptonic;
  SSummedVar< Int_t > cf_ggf;

  SSummedVar< double > cf_weighted_final;
  SSummedVar< double > cf_signal_final;
  SSummedVar< double > cf_signal_weighted_final;
    
  // D3PDReader objects for input/output
  D3PDReader::EventInfoD3PDObject* m_event_d3pdobject;
  D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject;
  D3PDReader::PrimaryVertexD3PDObject* m_vxp_d3pdobject;

  D3PDReader::ElectronD3PDObject* m_electron_d3pdobject;
  D3PDReader::MuonD3PDObject* m_muon_staco_d3pdobject;
  D3PDReader::MuonD3PDObject* m_muon_calo_d3pdobject;
  D3PDReader::JetD3PDObject* m_jet_d3pdobject;

  D3PDReader::MCEvtD3PDObject* m_mcevt_d3pdobject;
  D3PDReader::TruthParticleD3PDObject* m_truth_d3pdobject;
  D3PDReader::JetD3PDObject* m_truthjet_d3pdobject;

  D3PDReader::METD3PDObject* m_met_d3pdobject;
  D3PDReader::PhotonD3PDObject* m_photon_d3pdobject;

  std::string c_output_event_branches_regex;
  std::string c_output_mcevt_branches_regex;
  std::string c_output_trigger_branches_regex;
  std::string c_output_muon_trigger_branches_regex;
  std::string c_output_electron_trigger_branches_regex;
  std::string c_output_vxp_branches_regex;
  std::string c_output_electron_branches_regex;
  //std::string c_output_photon_branches_regex;
  std::string c_output_muon_branches_regex;
  std::string c_output_jet_branches_regex;
  std::string c_output_met_branches_regex;
  std::string c_output_truth_branches_regex;

  std::string c_output_tree_name;
  
  //Root::TTileTripReader* m_treader;
  CategoriesMVA* m_CategoriesDiscriminantTool;
  BRCorrection* br_tool;
  //ZZPtSystTool* m_ZZPtSystTool;

  long m_mc_channel_number;

  std::vector<Muon*> sel_muons;
  std::vector<Electron*> sel_electrons;
  std::vector<Quadruplet*> all_quads;
  std::vector<Jet*> sel_jets;
  std::vector<Jet*> sel_jets_fid;

  int n_verts;
  double mu;

  double m_4l;
  double m_12;
  double m_34;
  double m_4l_fsr;
  double m_12_fsr;
  double m_34_fsr;
  double m_4l_constrained;
  double m_12_constrained;
  double m_34_constrained;
  
  double m_4l_err;
  double m_4l_err_fsr;
  double m_4l_err_constrained;
  
  //double m4l_pull;

  double m_4l_id;

  double pt_4l;
  double pt_Z1;
  double pt_Z2;
  double pt_4l_constrained;
  double pt_Z1_constrained;
  double pt_Z2_constrained;
  double pt_4l_fsr;
  double pt_Z1_fsr;
  double pt_Z2_fsr;

  double eta_4l;
  double eta_4l_constrained;
  double eta_4l_fsr;

  double y_4l_unconstrained;
  double y_4l_unconstrained_mH;
  double y_4l_constrained;
  double y_4l_fsr;

  float cthstr;
  float phi1;
  float cth1; 
  float cth2; 
  float phi;
      
  unsigned int n_quads;
  unsigned int n_jets;
  float m_jj;
  float deltaeta_jj;
  float pt_leadingjet;
  float eta_leadingjet;
  float pt_subleadingjet;
  float eta_subleadingjet;

  unsigned int n_jets_fid;
  float pt_leadingjet_fid;
  float eta_leadingjet_fid;
  std::vector<unsigned int> n_jets_fid_syst;
  std::vector<double> pt_leadingjet_fid_syst;
  std::vector<double> eta_leadingjet_fid_syst;

  float VBF_discriminant;  
  float HadVH_discriminant; 

  double evt_weight;
  double lepton_sf;
  double trigger_sf;
  double pileup_sf;
  double vertex_sf;
  double mc_event_weight;
  double mc_event_reweight;
  double weight_brcorrection;
  double weight_higgspt;

  double lepton_sf_ElectronRecoLow;   
  double lepton_sf_ElectronRecoHigh;  
  double lepton_sf_ElectronIDLow;     
  double lepton_sf_ElectronIDStatHigh;
  double lepton_sf_ElectronStat15;    
  double lepton_sf_ElectronStat10;    
  double lepton_sf_ElectronStat7;     
  double lepton_sf_MuonSyst;  
  double trigger_sf_ElectronSyst;
  double trigger_sf_MuonSyst;
  double isolationip_sf_ElectronSyst;
  std::vector<double> qcd_scale_weights;
  std::vector<double> pdf_weights;
  //std::vector<double> zz_scale_weight;
  //std::vector<double> zz_pdf_weight;
  double weight_pt_ZZPdfUp;  
  double weight_pt_ZZPdfDn;  
  double weight_pt_ZZScaleUp;
  double weight_pt_ZZScaleDn;
  double weight_rapidity_ZZPdfUp;  
  double weight_rapidity_ZZPdfDn;  
  double weight_rapidity_ZZScaleUp;
  double weight_rapidity_ZZScaleDn;
  double weight_m34_ZZPdfUp;  
  double weight_m34_ZZPdfDn;  
  double weight_m34_ZZScaleUp;
  double weight_m34_ZZScaleDn;
  double weight_costhetastar_ZZPdfUp;  
  double weight_costhetastar_ZZPdfDn;  
  double weight_costhetastar_ZZScaleUp;
  double weight_costhetastar_ZZScaleDn;

  unsigned int evt_category;

  int event_type_truth;
  bool mispaired;
  bool reco_higgs_quad;

  double m_higgs_truth;
  double pt_higgs_truth;
  double eta_higgs_truth;
  double y_higgs_truth;

  double m_Z1_truth;
  double m_Z2_truth;
  
  double pt_Z1_truth;
  double pt_Z2_truth;

  double m_4l_truth;
  double m_l12_truth;
  double m_l34_truth;

  double pt_4l_truth;
  double pt_l12_truth;
  double pt_l34_truth;

  double m4l_truth_paired_bare;
  double m12_truth_paired_bare;
  double m34_truth_paired_bare;

  double m4l_truth_paired_dressed;
  double m12_truth_paired_dressed;
  double m34_truth_paired_dressed;
  
  double m4l_truth_matched_bare;
  double m12_truth_matched_bare;
  double m34_truth_matched_bare;

  double m4l_truth_matched_dressed;
  double m12_truth_matched_dressed;
  double m34_truth_matched_dressed;

  double m4l_truth_matched_born;
  double m12_truth_matched_born;
  double m34_truth_matched_born;

  bool evt_passLikelihood;
  bool evt_passVeryLooseLikelihood;
  bool evt_passLooseRelaxedLikelihood;
  bool evt_passLooseLikelihood;
  bool evt_passLooseBLPixLikelihood;
  bool evt_passLooseBLPixLowLikelihood;
  bool evt_passLooseBLPixMedLikelihood;
  bool evt_passLooseBLPixHighLikelihood;
  bool evt_passMediumLikelihood;
  bool evt_passML;
  bool evt_passML_HCP;
  bool evt_passML_Relaxed;
  
  int m_debugRun;
  int m_debugEvent;
  int m_debugRun1;
  int m_debugEvent1;
  int m_debugRun2;
  int m_debugEvent2;
  int m_debugRun3;
  int m_debugEvent3;
  int m_debugRun4;
  int m_debugEvent4;
  int m_debugRun5;
  int m_debugEvent5;
  
  int quad_type;
  bool quad_passLikelihood;
  bool quad_passLooseRelaxedLikelihood;
  bool quad_passVeryLooseLikelihood;
  bool quad_passLooseLikelihood;
  bool quad_passLooseBLPixLikelihood; 
  bool quad_passLooseBLPixLowLikelihood; 
  bool quad_passLooseBLPixMedLikelihood; 
  bool quad_passLooseBLPixHighLikelihood; 
  bool quad_passMediumLikelihood;

  bool quad_passTrigger;

  bool quad_passML;
  bool quad_passML_HCP;
  bool quad_passML_Relaxed;
  
  bool quad_passTrkIso;
  bool quad_passCaloIso;

  bool quad_hasStandaloneMuon;
  bool quad_hasCaloMuon;
  
  int quad_TriggerBitword;

  std::vector<int> lepton_type;
  std::vector<int> lepton_index;

  std::vector<double> lepton_sf_recoid;

  std::vector<double> lepton_pt;
  std::vector<double> lepton_eta;
  std::vector<double> lepton_phi;
  std::vector<double> lepton_m;

  std::vector<double> lepton_cov_mom;

  std::vector<double> lepton_pt_id;
  std::vector<double> lepton_eta_id;
  std::vector<double> lepton_phi_id;

  std::vector<double> lepton_pt_truth_born;
  std::vector<double> lepton_eta_truth_born;
  std::vector<double> lepton_phi_truth_born;
  std::vector<double> lepton_m_truth_born;

  std::vector<double> lepton_pt_truth_paired_bare;
  std::vector<double> lepton_eta_truth_paired_bare;
  std::vector<double> lepton_phi_truth_paired_bare;
  std::vector<double> lepton_m_truth_paired_bare;

  std::vector<double> lepton_pt_truth_paired_dressed;
  std::vector<double> lepton_eta_truth_paired_dressed;
  std::vector<double> lepton_phi_truth_paired_dressed;
  std::vector<double> lepton_m_truth_paired_dressed;

  std::vector<double> lepton_pt_truth_matched_bare;
  std::vector<double> lepton_eta_truth_matched_bare;
  std::vector<double> lepton_phi_truth_matched_bare;
  std::vector<double> lepton_m_truth_matched_bare;

  std::vector<double> lepton_pt_truth_matched_dressed;
  std::vector<double> lepton_eta_truth_matched_dressed;
  std::vector<double> lepton_phi_truth_matched_dressed;
  std::vector<double> lepton_m_truth_matched_dressed;

  std::vector<double> lepton_pt_truth_matched_born;
  std::vector<double> lepton_eta_truth_matched_born;
  std::vector<double> lepton_phi_truth_matched_born;
  std::vector<double> lepton_m_truth_matched_born;

  std::vector<double> lepton_trk_iso20;
  std::vector<double> lepton_trk_iso30;
  std::vector<double> lepton_trk_iso40;
  
  std::vector<double> lepton_calo_iso20;
  std::vector<double> lepton_calo_iso30;
  std::vector<double> lepton_calo_iso40;

  std::vector<double> lepton_d0_significance;

  std::vector<double> lepton_dR_jet;

  std::vector<int> lepton_passML;
  std::vector<int> lepton_passML_HCP;
  std::vector<int> lepton_passML_Relaxed;
  std::vector<int> lepton_passLooseRelaxedLikelihood;
  std::vector<int> lepton_passVeryLooseLikelihood;
  std::vector<int> lepton_passLikelihood;
  std::vector<int> lepton_passLooseLikelihood;
  std::vector<int> lepton_passLooseBLPixLikelihood;
  std::vector<int> lepton_passMediumLikelihood;

  std::vector<int> lepton_passLooseBLPixLowLikelihood;
  std::vector<int> lepton_passLooseBLPixMedLikelihood;
  std::vector<int> lepton_passLooseBLPixHighLikelihood;

  // Macro adding the functions for dictionary generation
  ClassDef( ZZCutFlow, 0 );

}; // class ZZCutFlow

#endif // ZZCutFlow_H
