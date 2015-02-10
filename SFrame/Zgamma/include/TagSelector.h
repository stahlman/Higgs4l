// Dear emacs, this is -*- c++ -*-
// $Id: TagSelector.h 18120 2012-09-16 14:35:37Z sheim $
#ifndef TagSelector_H
#define TagSelector_H

// SFrame include(s):
//#include "plug-ins/include/SSummedVar.h"

// D3PDObjects
#include "ElectronD3PDObject.h"
#include "EventInfoD3PDObject.h"

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Electron.h"
#include "Muon.h"

//RootCore
#include "egammaAnalysisUtils/EnergyRescaler.h"

//
//#include "ElectronLikelihoodTool.h"


/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 18120 $
 */
class TagSelector : public ToolBase {

public:
   /// Default constructor
   TagSelector(SCycleBase* parent, const char* name);
   /// Default destructor
   ~TagSelector();
   
   virtual void BeginMasterInputData( const SInputData& ) throw( SError );
   virtual void EndMasterInputData( const SInputData& ) throw( SError );

  void SelectElectrons( std::vector<Electron*> &sel_electrons, const D3PDReader::ElectronD3PDObject* m_electron_d3pdobject, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, int n_vertices);

  

private:
   //
   // Put all your private variables here
   //
   bool m_doSmear;
   bool m_doCalibration;
   bool m_vetoCrack;
   bool m_doLikelihood;
   std::string m_likelihoodOP;
   bool m_ptcutLikelihood;
   bool m_doTruthMatchEleZ;

   int cf_preselect;
   int cf_author;    
   int cf_electronid;
   int cf_eta;	    
   int cf_et;	    
   int cf_oq;	    
   int cf_z0;	    
   int cf_trigger; 

  //ElectronLikelihoodToolLocal * m_likelihoodtool;

  double DeltaR(double eta1, double phi1, double eta2, double phi2);
   
   // Macro adding the functions for dictionary generation
   ClassDef( TagSelector, 0 );

}; // class TagSelector

#endif // TagSelector_H
