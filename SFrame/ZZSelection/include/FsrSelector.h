// Dear emacs, this is -*- c++ -*-
// $Id: FsrSelector.h 26117 2014-02-04 21:06:31Z stahlman $
#ifndef FsrSelector_H
#define FsrSelector_H

#include <string>

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Quadruplet.h"
#include "Photon.h"

// D3PDObjects
#include "ElectronD3PDObject.h"
#include "PhotonD3PDObject.h"
#include "EventInfoD3PDObject.h"

/**
 *   @short Class to select FSR
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 26117 $
 */
class FsrSelector : public ToolBase {

public:
   /// Default constructor
   FsrSelector( SCycleBase* parent, const char* name = "FSR" );
   
   /// Default destructor
   ~FsrSelector();

   virtual void BeginInputFile( const SInputData& ) throw( SError );

   void SelectFsr( Quadruplet* quad , D3PDReader::ElectronD3PDObject* m_electron_d3pdobject, D3PDReader::PhotonD3PDObject* m_photon_d3pdobject, D3PDReader::EventInfoD3PDObject* m_event_d3pdobject);


private:
   //
   // Put all your private variables here
   //

   std::string m_recoTreeName;
   bool m_doFarFSRCorrection;

   // Macro adding the functions for dictionary generation
   ClassDef( FsrSelector, 0 );

}; // class FsrSelector

#endif // FsrSelector_H
