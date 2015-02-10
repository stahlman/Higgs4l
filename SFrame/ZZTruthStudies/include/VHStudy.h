// Dear emacs, this is -*- c++ -*-
// $Id: VHStudy.h 16921 2012-08-07 08:23:39Z stahlman $
#ifndef VHStudy_H
#define VHStudy_H

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
//#include "MCEvtD3PDObject.h"
#include "TriggerD3PDObject.h"
#include "PrimaryVertexD3PDObject.h"
#include "ElectronD3PDObject.h"
//#include "PhotonD3PDObject.h"
#include "MuonD3PDObject.h"
//#include "JetD3PDObject.h"
//#include "METD3PDObject.h"
#include "TruthParticleD3PDObject.h"

// AtlasSFrameUtils
#include "Muon.h"

#include "TRandom3.h"
#include "TLorentzVector.h"
#include <list>

/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 16921 $
 */
class VHStudy : public CycleBase {

public:
   /// Default constructor
   VHStudy();
   /// Default destructor
   ~VHStudy();

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

  std::string m_recoTreeName;
  std::string m_trigTreeName;
  std::string c_jet_container;
      
  // D3PDReader objects for input/output
  D3PDReader::EventInfoD3PDObject* m_event_d3pdobject;
  D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject;
  D3PDReader::PrimaryVertexD3PDObject* m_vxp_d3pdobject;

  D3PDReader::ElectronD3PDObject* m_electron_d3pdobject;
  D3PDReader::MuonD3PDObject* m_muon_staco_d3pdobject;
  D3PDReader::MuonD3PDObject* m_muon_calo_d3pdobject;

  D3PDReader::TruthParticleD3PDObject* m_truth_d3pdobject;

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

  InvMassTool* mass_tool;
  
  int n_vertices;
  
  double delta_eta;
  double delta_phi;
  double delta_r;

  double delta_eta_quark;
  double delta_phi_quark;
  double delta_r_quark; 
  
  double pt_higgs;
  double pt_z; 
  double delta_pt;

  double truth_m_Z;

  double m_12;
  double m_34;
  double m_4l;

  double truth_m_H; 
  double truth_m_Z1;
  double truth_m_Z2;

  double truth_m_4l;
  double truth_m_4l_gamma;
  double truth_m_12;
  double truth_m_34;

  double delta_m_4l_truth_m_4l;
  double delta_m_4l_truth_m_4l_gamma;
  double delta_m_4l_truth_m_H;
  double m4l_sigma;
  double m4l_pull;

  int quad_type;
  std::vector<int>* lepton_type;
  std::vector<int>* lepton_index;

   // Macro adding the functions for dictionary generation
   ClassDef( VHStudy, 0 );

}; // class VHStudy

#endif // VHStudy_H
