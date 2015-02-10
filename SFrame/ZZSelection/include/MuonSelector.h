// Dear emacs, this is -*- c++ -*-
// $Id: MuonSelector.h 26089 2014-01-31 23:14:19Z stahlman $
#ifndef MuonSelector_H
#define MuonSelector_H

// SFrame include(s):
//#include "plug-ins/include/SSummedVar.h"

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Muon.h"
#include "Quadruplet.h"

// D3PDObjects
#include "MuonD3PDObject.h"

//RootCore include(s):
#include "MuonMomentumCorrections/SmearingClass.h"


/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 26089 $
 */
class MuonSelector : public ToolBase {

public:
   /// Default constructor
   MuonSelector(SCycleBase* parent, const char* name);
   /// Default destructor
   ~MuonSelector();

   virtual void BeginMasterInputData( const SInputData& ) throw( SError );
   virtual void EndMasterInputData( const SInputData& ) throw( SError );

   void SelectMuons( std::vector<Muon*>& sel_muons, const D3PDReader::MuonD3PDObject* m_muon_staco_d3pdobject,const D3PDReader::MuonD3PDObject* m_muon_calo_d3pdobject, unsigned int evt_number );
   void RemoveElectronMuonOverlap( std::vector<Muon*> &sel_muons, std::vector<Electron*> &sel_electrons);
   void RemoveJetMuonOverlap(std::vector<Muon*> &sel_muons, std::vector<Jet*> &sel_jets);
   int NumberAdditionalMuons( Quadruplet* quad, std::vector<Muon*> &sel_muons);

private:
   //
   // Put all your private variables here
   //

  double CalculateDeltaR(Muon* m1, Muon m2, int track_params);
  double DeltaR(double eta1, double phi1, double eta2, double phi2);      

  bool m_selectCombinedMuons;
  bool m_selectSegmentTaggedMuons;
  bool m_selectStandAloneMuons;
  bool m_selectCaloMuons;

  bool m_doBLayerCut;

  bool m_doSmear;

  bool m_doTrkIso;
  bool m_doCaloIso;
  bool m_doD0;

  int m_cone_size;

  int cf_preselect;
  int cf_author;
  int cf_momentum;
  int cf_eta;
  int cf_blayer;
  int cf_pixel;
  int cf_sct;
  int cf_holes;
  int cf_trt;
  int cf_d0z0;
  int cf_overlap;
  int cf_emu_overlap;
  int cf_jetmu_overlap;
  int cf_isolation;

  // Macro adding the functions for dictionary generation
  ClassDef( MuonSelector, 0 );

}; // class MuonSelector

#endif // MuonSelector_H
