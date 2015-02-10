// Dear emacs, this is -*- c++ -*-
// $Id: FiducialCutflow.h 27398 2014-06-11 15:30:03Z stahlman $
#ifndef FiducialCutflow_H
#define FiducialCutflow_H

// SFrame include(s):
#include "plug-ins/include/SSummedVar.h"

// AtlasSFrameUtils
#include "CycleBase.h"

//Common tools
#include "PdtPdg.h"

//RootCore
#include "HiggsZZ4lUtils/BRCorrection.h"

// D3PDObjects
#include "EventInfoD3PDObject.h"
#include "MCEvtD3PDObject.h"
#include "TriggerD3PDObject.h"
#include "PrimaryVertexD3PDObject.h"
#include "ElectronD3PDObject.h"
//#include "PhotonD3PDObject.h"
#include "MuonD3PDObject.h"
#include "JetD3PDObject.h"
//#include "METD3PDObject.h"
#include "TruthParticleD3PDObject.h"

// AtlasSFrameUtils
#include "Muon.h"
#include "Jet.h"

#include "TRandom3.h"
#include "TLorentzVector.h"
#include <list>

/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 27398 $
 */
class FiducialCutflow : public CycleBase {

public:
   /// Default constructor
   FiducialCutflow();
   /// Default destructor
   ~FiducialCutflow();

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

  void DressLeptons( std::vector<TruthParticle*> &tparts );

  void GetFinalStateLeptons( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &leptons, bool dress_electrons = true, bool dress_muons = false );

  void GetBornLeptons_Powheg( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &leptons );
  void GetBornLeptons_Prophecy4f( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &leptons );
  void GetBornLeptons_JHU( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &leptons );

  void FillHiggsVariables_Powheg( std::vector<TruthParticle*> &tparts, std::vector<Jet> &all_jets);
  void FillHiggsVariables_Prophecy4f( std::vector<TruthParticle*> &tparts, std::vector<Jet> &all_jets);
  void FillHiggsVariables_JHU( std::vector<TruthParticle*> &tparts, std::vector<Jet> &all_jets);
    
  bool PairLeptons(std::vector<TruthParticle*> &input_leptons, std::vector<TruthParticle*> &paired_leptons, bool dress_electrons, bool dress_muons);

  void GetBornTruthQuad( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &quad );
  TruthParticle* GetTruthZ(      int index, std::vector<TruthParticle*> &tparts );
  TruthParticle* GetTruthLepton( int index, std::vector<TruthParticle*> &tparts );
 
  int ClassifyQuad( std::vector<TruthParticle*> &quad );
  
  double interpolate(double mass);

  int findStableChildren(TruthParticle* mother, std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &stablechildren);
  int findLastHiggs(int higgs_index, std::vector<TruthParticle*> &tparts);

  std::string m_TreeName;
  std::string m_trigTreeName;
  std::string c_jet_container;
  std::string m_MCGenerator;

  std::vector<TruthParticle*> truth_parts;
  
  TTree* gen_tree;
      
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

  BRCorrection* br_tool;

  TH1F* m_ggF_HpT_weight_01jets;  
  TH1F* m_ggF_HpT_weight_geq2jets;	


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

  bool b_dress_electrons;
  bool b_dress_muons;
  bool b_allow_mispairing;

  SSummedVar< Int_t > cf_preselect;
  SSummedVar< Int_t > cf_higgs;
  SSummedVar< Int_t > cf_zs;
  SSummedVar< Int_t > cf_leptons;
  SSummedVar< Int_t > cf_sfos;
  SSummedVar< Int_t > cf_pt;
  SSummedVar< Int_t > cf_eta;
  SSummedVar< Int_t > cf_m12;
  SSummedVar< Int_t > cf_m34;
  SSummedVar< Int_t > cf_deltar;
  SSummedVar< Int_t > cf_jpsi;
  
  double n_4mu;
  double n_2mu2e;
  double n_2e2mu;
  double n_4e;
  double n_taus;
  double n_other;

  double n_pass_4mu;
  double n_pass_2mu2e;
  double n_pass_2e2mu;
  double n_pass_4e;
  
  double evt_weight;
  double pileup_sf;
  double vertex_sf;
  double mc_event_weight;
  std::vector<double> qcd_scale_weights;
  std::vector<double> pdf_weights;
  double weight_brcorrection;
  double weight_higgspt;

  int n_vertices;
  
  double higgs_m; 
  double higgs_pt;
  double higgs_eta;
  double higgs_rapidity;

  float higgs_cthstr;
  //float higgs_phi1;
  //float higgs_cth1;
  //float higgs_cth2;
  //float higgs_phi;

  double Z1_m;
  double Z1_pt;
  double Z1_eta;

  double Z2_m;
  double Z2_pt;
  double Z2_eta;

  double born_higgslep4_m; 
  double born_higgslep4_pt;
  double born_higgslep4_eta;
  double born_higgslep4_y;

  float born_higgslep4_cthstr;
  float born_higgslep4_phi1;
  float born_higgslep4_cth1;
  float born_higgslep4_cth2;
  float born_higgslep4_phi;

  double born_higgslep12_m;
  double born_higgslep12_pt;
  double born_higgslep12_eta;

  double born_higgslep34_m;
  double born_higgslep34_pt;
  double born_higgslep34_eta;

  double born_paired_higgslep4_m; 
  double born_paired_higgslep4_pt;
  double born_paired_higgslep4_eta;
  double born_paired_higgslep4_y;

  float born_paired_higgslep4_cthstr;
  float born_paired_higgslep4_phi1;
  float born_paired_higgslep4_cth1;
  float born_paired_higgslep4_cth2;
  float born_paired_higgslep4_phi;

  double born_paired_higgslep12_m;
  double born_paired_higgslep12_pt;
  double born_paired_higgslep12_eta;

  double born_paired_higgslep34_m;
  double born_paired_higgslep34_pt;
  double born_paired_higgslep34_eta;

  double lep4_m;
  double lep4_pt; 
  double lep4_eta;
  double lep4_y;

  float lep4_cthstr;
  float lep4_phi1;
  float lep4_cth1;
  float lep4_cth2;
  float lep4_phi;

  double lep12_m; 
  double lep12_pt;
  double lep12_eta;

  double lep34_m; 
  double lep34_pt;
  double lep34_eta;

  double dressed_lep4_m;
  double dressed_lep4_pt; 
  double dressed_lep4_eta;
  double dressed_lep4_y;

  float dressed_lep4_cthstr;
  float dressed_lep4_phi1;
  float dressed_lep4_cth1;
  float dressed_lep4_cth2;
  float dressed_lep4_phi;

  double dressed_lep12_m; 
  double dressed_lep12_pt;
  double dressed_lep12_eta;

  double dressed_lep34_m; 
  double dressed_lep34_pt;
  double dressed_lep34_eta;

  double born_lep4_m;
  double born_lep4_pt; 
  double born_lep4_eta;
  double born_lep4_y;

  float born_lep4_cthstr;
  float born_lep4_phi1;
  float born_lep4_cth1;
  float born_lep4_cth2;
  float born_lep4_phi;

  double born_lep12_m; 
  double born_lep12_pt;
  double born_lep12_eta;

  double born_lep34_m; 
  double born_lep34_pt;
  double born_lep34_eta;

  std::vector<double> born_higgslep_pt;
  std::vector<double> born_higgslep_eta;

  std::vector<double> lep_pt;
  std::vector<double> lep_eta;

  std::vector<double> dressed_lep_pt;
  std::vector<double> dressed_lep_eta;

  std::vector<double> born_lep_pt;
  std::vector<double> born_lep_eta;

  std::vector<int> lep_mother_pdgid;

  int event;
  int run;
  int mc_channel_number;
  int event_type_truth;
  int quad_type;
  bool mispaired;
  bool swapped;
  bool paired_leptons_are_from_higgs;
  std::vector<int>* lepton_type;
  std::vector<int>* lepton_index;

  unsigned int n_electrons;
  unsigned int n_muons;

  unsigned int n_jets_truth;	 
  unsigned int n_jets_truth_fid;
  unsigned int n_jets_truth_rew;	 
  double pt_leadingjet;   
  double pt_leadingjet_fid;
  
  unsigned int n_jets_removed;
  
  static const double m34cut_m34[2];
  static const double m34cut_m4l[2];
  static const string channel_names[6];

  int debug_event;

   // Macro adding the functions for dictionary generation
   ClassDef( FiducialCutflow, 0 );

}; // class FiducialCutflow

#endif // FiducialCutflow_H
