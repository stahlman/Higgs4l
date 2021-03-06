// Dear emacs, this is -*- c++ -*-
// $Id: ZSelector.h 19791 2012-11-14 13:01:11Z stahlman $
#ifndef ZSelector_H
#define ZSelector_H

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

//RootCore
#include "MuonMomentumCorrections/SmearingClass.h"

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
 * @version $Revision: 19791 $
 */
class ZSelector : public CycleBase {

public:
   /// Default constructor
   ZSelector();
   /// Default destructor
   ~ZSelector();

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

 
   double GetMuonResolution( Muon* muon );
   double SmearMomentum( TLorentzVector muon, int num );

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

  MuonSmear::SmearingClass* m_muResolution;
  //InvMassTool* mass_tool;
  
  TRandom3* gRand;

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
    
  std::vector<Muon*> sel_muons;
  
  double m_runNumber; 
  double m_evtNumber; 
  double m_lumi_block;

  double m_negative_px;
  double m_negative_py;
  double m_negative_pz;
  double m_negative_z0;
  double m_negative_d0;

  double m_positive_px;
  double m_positive_py;
  double m_positive_pz;
  double m_positive_z0;
  double m_positive_d0;


   // Macro adding the functions for dictionary generation
   ClassDef( ZSelector, 0 );

}; // class ZSelector

#endif // ZSelector_H
