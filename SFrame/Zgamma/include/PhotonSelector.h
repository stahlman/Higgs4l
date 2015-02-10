// Dear emacs, this is -*- c++ -*-
// $Id: PhotonSelector.h 18120 2012-09-16 14:35:37Z sheim $
#ifndef PhotonSelector_H
#define PhotonSelector_H

// SFrame include(s):
//#include "plug-ins/include/SSummedVar.h"

// D3PDObjects
#include "PhotonD3PDObject.h"
#include "EventInfoD3PDObject.h"

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Electron.h"
#include "Photon.h"


//RootCore
#include "egammaAnalysisUtils/EnergyRescaler.h"




/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 18120 $
 */
class PhotonSelector : public ToolBase {

public:
   /// Default constructor
   PhotonSelector(SCycleBase* parent, const char* name);
   /// Default destructor
   ~PhotonSelector();
   
   virtual void BeginMasterInputData( const SInputData& ) throw( SError );
   virtual void EndMasterInputData( const SInputData& ) throw( SError );

  void SelectPhotons( std::vector<Photon*> &sel_photons, const D3PDReader::PhotonD3PDObject* m_photon_d3pdobject, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject);

  //void RemoveElectronPhotonOverlap(std::vector<Photon*> &sel_photons,std::vector<Electron*> &sel_electrons, double Radius);

  template <class T> void RemoveElectronPhotonOverlap(std::vector<Photon*> &sel_photons,std::vector<T*> &sel_electrons, double Radius);


private:
   //
   // Put all your private variables here
   //
   bool m_doSmear;
   bool m_doCalibration;
   bool m_vetoCrack;
   bool m_doTruthMatchPhoton;

   int cf_preselect;
   int cf_author;    
   int cf_photonid;
   int cf_eta;	    
   int cf_et;	    
   int cf_oq;	    
   int cf_iso;	 
  

 

  double DeltaR(double eta1, double phi1, double eta2, double phi2);
   
   // Macro adding the functions for dictionary generation
   ClassDef( PhotonSelector, 0 );

}; // class PhotonSelector

#endif // PhotonSelector_H
