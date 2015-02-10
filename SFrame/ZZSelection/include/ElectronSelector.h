// Dear emacs, this is -*- c++ -*-
// $Id: ElectronSelector.h 23506 2013-05-29 15:07:20Z sheim $
#ifndef ElectronSelector_H
#define ElectronSelector_H

// SFrame include(s):
//#include "plug-ins/include/SSummedVar.h"

// D3PDObjects
#include "ElectronD3PDObject.h"
#include "EventInfoD3PDObject.h"

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Electron.h"
#include "Muon.h"
#include "Quadruplet.h"

//RootCore


/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 23506 $
 */
class ElectronSelector : public ToolBase {

public:
   /// Default constructor
   ElectronSelector(SCycleBase* parent, const char* name);
   /// Default destructor
   ~ElectronSelector();
   
   virtual void BeginMasterInputData( const SInputData& ) throw( SError );
   virtual void EndMasterInputData( const SInputData& ) throw( SError );

   void SelectElectrons( std::vector<Electron*> &sel_electrons, const D3PDReader::ElectronD3PDObject* m_electron_d3pdobject,  const D3PDReader::EventInfoD3PDObject* m_evt_d3pdobject, int n_vertices);
   void RemoveElectronMuonOverlap( std::vector<Muon*> &sel_muons, std::vector<Electron*> &sel_electrons);
   int NumberAdditionalElectrons( Quadruplet* quad, std::vector<Electron*> &sel_electrons);

private:
   //
   // Put all your private variables here
   //
   bool m_doElectronIDCut;
   
   bool m_doSmear;
   bool m_doCalibration;
   bool m_vetoCrack;
   bool m_doTruthMatchEleZ;
   bool m_ptcutZ;  
 
   bool m_doBlayer;
  
   bool m_doML;
   bool m_doML_HCP;
   bool m_doLikelihood;
   bool m_doLikelihoodMedium;
   bool m_doLikelihoodLoose;
   bool m_doLikelihoodLoose_BL_Pix;
   bool m_doLikelihoodLoose_BL_PixLow;
   bool m_doLikelihoodLoose_BL_PixMed;
   bool m_doLikelihoodLoose_BL_PixHigh;
   bool m_doSiTrack;
   std::string m_LH_OP;
   std::string m_ML_OP;
   
   bool m_doTrkIso;
   bool m_doCaloIso;
   bool m_doD0;
   
   int cf_preselect;
   int cf_author;    
   int cf_electronid;
   int cf_eta;	    
   int cf_et;	    
   int cf_oq;	    
   int cf_z0;	    
   int cf_overlap;
   int cf_cl_overlap;
   int cf_mu_overlap;

   int m_cone_size;


  double DeltaR(double eta1, double phi1, double eta2, double phi2);
   
   // Macro adding the functions for dictionary generation
   ClassDef( ElectronSelector, 0 );

}; // class ElectronSelector

#endif // ElectronSelector_H
