// Dear emacs, this is -*- c++ -*-
// $Id: ZXCutflow.h 19801 2012-11-14 15:30:24Z stahlman $
#ifndef ZXCutflow_H
#define ZXCutflow_H

// SFrame include(s):
#include "plug-ins/include/SSummedVar.h"

// AtlasSFrameUtils
#include "CycleBase.h"

//Common tools
//#include "GoodRunsListTool.h"
//#include "PileupReweightingTool.h"
//#include "ZPtReweightingTool.h"
#include "InvMassTool.h"
#include "PdtPdg.h"

// D3PDObjects
#include "EventInfoD3PDObject.h"
#include "MCEvtD3PDObject.h"
//#include "TrigMuonEFInfoD3PDObject.h"
//#include "TrigElectronD3PDObject.h"
#include "TriggerD3PDObject.h"
#include "PrimaryVertexD3PDObject.h"
#include "ElectronD3PDObject.h"
//#include "PhotonD3PDObject.h"
#include "MuonD3PDObject.h"
#include "JetD3PDObject.h"
#include "METD3PDObject.h"
#include "TruthParticleD3PDObject.h"

// AtlasSFrameUtils
#include "Muon.h"
#include "Electron.h"
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
 * @version $Revision: 19801 $
 */
class ZXCutflow : public CycleBase {

public:
   /// Default constructor
   ZXCutflow();
   /// Default destructor
   ~ZXCutflow();

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

  double DeltaR(double eta1, double phi1, double eta2, double phi2);

  bool m_doGRL;
  bool m_doLarError;
  bool m_doTileError;
  bool m_doDaqError;
  bool m_doTrig;
  bool m_doVert;
  std::string m_ProdType;
  //bool m_doVH;
  bool m_reqExtraMuon;

  bool DoLeptonSF;
  bool DoTriggerSF;
  bool DoPileupSF;
  bool DoVertexSF;

  std::string m_recoTreeName;
  std::string c_jet_container;

  TRandom3* gRand_Calo;
  
  SSummedVar< Int_t > cf_preselect;
  SSummedVar< Int_t > cf_el_preselect;
  SSummedVar< Int_t > cf_mu_preselect;
  SSummedVar< Int_t > cf_grl;
  SSummedVar< Int_t > cf_larerror;
  SSummedVar< Int_t > cf_tileerror;
  SSummedVar< Int_t > cf_daqerror;
  SSummedVar< Int_t > cf_trigger;
  SSummedVar< Int_t > cf_el_trigger;
  SSummedVar< Int_t > cf_mu_trigger;
  SSummedVar< Int_t > cf_vertex;
  SSummedVar< Int_t > cf_el_vertex;
  SSummedVar< Int_t > cf_mu_vertex;
  SSummedVar< Int_t > cf_leptons;
  SSummedVar< Int_t > cf_two_mu;
  SSummedVar< Int_t > cf_two_el;
  SSummedVar< Int_t > cf_mass_cut;

  SSummedVar< double > cf_weighted_final;
    
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

  D3PDReader::METD3PDObject* m_met_d3pdobject;
  //D3PDReader::PhotonD3PDObject* m_in_photon_d3pdobject;

  std::string c_output_event_branches_regex;
  std::string c_output_mcevt_branches_regex;
  std::string c_output_trigger_branches_regex;
  std::string c_output_muon_trigger_branches_regex;
  std::string c_output_electron_trigger_branches_regex;
  std::string c_output_vxp_branches_regex;
  std::string c_output_electron_branches_regex;
  //std::string c_output_photon_branches_regex;
  std::string c_output_muon_branches_regex;
  //std::string c_output_jet_branches_regex;
  std::string c_output_met_branches_regex;
  std::string c_output_truth_branches_regex;

  std::string c_output_tree_name;

  long m_mc_channel_number;

  std::vector<Muon*> sel_muons;
  std::vector<Muon*> x_muons;
  std::vector<Electron*> sel_electrons;
  std::vector<Electron*> x_electrons;
  std::vector<Jet*> sel_jets;

  //InvMassTool* mass_tool;
  
  int n_vertices;
  int n_x_el;
  int n_x_mu;
  
  double z_mass;
  int z_type;

  double evt_weight;
  double lepton_sf;
  double trigger_sf;
  double pileup_sf;
  double vertex_sf;
  
  int m_debugRun;
  int m_debugEvent;
  
  std::vector<int> x_index;
  std::vector<int> x_bitmask;

  std::vector<double> x_pt;
  std::vector<double> x_eta;
  std::vector<double> x_phi;
 
  std::vector<double> x_trk_iso20;
  std::vector<double> x_trk_iso30;
  std::vector<double> x_trk_iso40;
  
  std::vector<double> x_calo_iso20;
  std::vector<double> x_calo_iso30;
  std::vector<double> x_calo_iso40;

  std::vector<double> x_matched_jet_deltaR;
  std::vector<double> x_matched_jet_btagweight;
  std::vector<double> x_jet_btagged_deltaR;
  


  std::vector<int> x_mu_index;
  std::vector<int> x_mu_bitmask;

  std::vector<double> x_mu_pt;
  std::vector<double> x_mu_eta;
  std::vector<double> x_mu_phi;
 
  std::vector<double> x_mu_trk_iso20;
  std::vector<double> x_mu_trk_iso30;
  std::vector<double> x_mu_trk_iso40;
  
  std::vector<double> x_mu_calo_iso20;
  std::vector<double> x_mu_calo_iso30;
  std::vector<double> x_mu_calo_iso40;


   double mc_event_weight;

  // Macro adding the functions for dictionary generation
  ClassDef( ZXCutflow, 0 );

}; // class ZXCutflow

#endif // ZXCutflow_H
