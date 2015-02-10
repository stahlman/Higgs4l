// Dear emacs, this is -*- c++ -*-
// $Id: XSelector.h 23506 2013-05-29 15:07:20Z sheim $
#ifndef XSelector_H
#define XSelector_H

// SFrame include(s):
//#include "plug-ins/include/SSummedVar.h"

// D3PDObjects
#include "MuonD3PDObject.h"
#include "ElectronD3PDObject.h"
#include "EventInfoD3PDObject.h"

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Muon.h"
#include "Electron.h"

//RootCore include(s):
#include "MuonMomentumCorrections/SmearingClass.h"


/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 23506 $
 */
class XSelector : public ToolBase {

public:
   /// Default constructor
   XSelector(SCycleBase* parent, const char* name);
   /// Default destructor
   ~XSelector();

   virtual void BeginMasterInputData( const SInputData& ) throw( SError );
   virtual void EndMasterInputData( const SInputData& ) throw( SError );

   // enumerate bitmask here 
   enum XType {

     PassTrkIso             = 0x1 << 1,
     //PassOptTrkIso          = 0x1 << 2,
     PassLooseLikelihood = 0x1 << 2,
     PassCaloIso            = 0x1 << 3,
     //PassOptCaloIso         = 0x1 << 4,
     PassLoose_BL_PixLowLikelihood    = 0x1 << 4,
     PassD0                 = 0x1 << 5,
     PassLikelihood         = 0x1 << 6,
     //PassLooseLikelihood    = 0x1 << 7,
     //PassMediumLikelihood   = 0x1 << 8,
     PassLoose_BL_PixMedLikelihood    = 0x1 << 7,
     PassLoose_BL_PixHighLikelihood    = 0x1 << 8,
     PassML                 = 0x1 << 9,  
     PassML_HCP             = 0x1 << 10,  
     PassBLayer             = 0x1 << 11,  
 
     Pass3_5LooseLikelihood = 0x1 << 12,
     PassVeryLooseLikelihood = 0x1 << 13,

     PassD0Significance     = 0x1 << 14,
 
     PassMLRelaxed           = 0x1 << 15,
    
     PassTRTrphif1           = 0x1 << 16

//     PassLoose_BL_PixLikelihood    = 0x1 << 17,
//     PassLoose_BL_PixLowLikelihood    = 0x1 << 18,
//     PassLoose_BL_PixMedLikelihood    = 0x1 << 19,
//     PassLoose_BL_PixHighLikelihood    = 0x1 << 20

   };



   void SelectXMuons( std::vector<Muon*>& sel_muons, const D3PDReader::MuonD3PDObject* m_muon_staco_d3pdobject,const D3PDReader::MuonD3PDObject* m_muon_calo_d3pdobject, unsigned int evt_number );
   void SelectXElectrons( std::vector<Electron*> &sel_electrons, const D3PDReader::ElectronD3PDObject* m_electron_d3pdobject,  const D3PDReader::EventInfoD3PDObject* m_evt_d3pdobject, int n_vertices);

   //void SelectXMuons( std::vector<Muon*>& sel_muons, const D3PDReader::MuonD3PDObject* m_muon_staco_d3pdobject,const D3PDReader::MuonD3PDObject* m_muon_calo_d3pdobject, unsigned int evt_number );
   //void SelectXElectrons( std::vector<Electron*> &sel_electrons, const D3PDReader::ElectronD3PDObject* m_electron_d3pdobject,  const D3PDReader::EventInfoD3PDObject* m_evt_d3pdobject, int n_vertices);

 
private:
   //
   // Put all your private variables here
   //
   
  double MuonDeltaR(Muon* m1, Muon m2, int track_params);
  double DeltaR(double eta1, double phi1, double eta2, double phi2);      

  bool m_selectCombinedMuons;
  bool m_selectSegmentTaggedMuons;
  bool m_selectStandAloneMuons;
  bool m_selectCaloMuons;

  bool m_doSmear;
  
  bool m_doBlayer;

  bool m_doElectronID;
  bool m_doML;
  bool m_doML_HCP;
  bool m_doLikelihood;
  bool m_doLikelihoodMedium;
  bool m_doLikelihoodLoose;
  std::string m_ID_OP;

  bool m_doTruthMatchEleZ;
  bool m_doCalibration;
  bool m_doElectronIDCut;
  bool m_vetoCrack;
  bool m_ptcutLikelihood;
  
  bool m_doTrkIso;
  bool m_doCaloIso;
  bool m_doD0;
  
  bool m_doMuTrkIso;
  bool m_doMuCaloIso;
  bool m_doMuD0;
  bool m_doMuD0Significance;

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
  int cf_isolation;
  int cf_electronid;
  int cf_et;
  int cf_oq;
  int cf_z0;
  int cf_cl_overlap;
  int cf_mu_overlap;
  
  // Macro adding the functions for dictionary generation
  ClassDef( XSelector, 0 );

}; // class XSelector

#endif // XSelector_H
