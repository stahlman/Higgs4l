// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------
#ifndef D3PDREADER_EventInfoD3PDObject_H
#define D3PDREADER_EventInfoD3PDObject_H

#include <map>

#include <TObject.h>
#include <TString.h>

#include "D3PDObjectBase.h"
#include "D3PDReadStats.h"
#include "VarHandle.h"

class TTree;

namespace D3PDReader {

   /**
    * Code generated by CodeGenerator_v2 on:
    *  host = pc-penn-d-01
    *  OS   = Linux / 2.6.18-308.8.2.el5
    *  user = stahlman
    *  time = Fri Jun 29 14:28:44 2012
    */
   class EventInfoD3PDObject : public D3PDObjectBase {

   public:
      /// Constructor used when reading from a TTree
      EventInfoD3PDObject( const ::Long64_t& master, const char* prefix = "" );
      /// Constructor when the object is only used for writing data out
      EventInfoD3PDObject( const char* prefix = "" );

      /// Get the currently configured prefix value
      virtual const char* GetPrefix() const;
      /// Set the prefix for the variables
      virtual void SetPrefix( const char* prefix );

      /// Connect the object to an input TTree
      virtual void ReadFrom( ::TTree* tree );
      /// Connect the object to an output TTree
      virtual void WriteTo( ::TTree* tree );

      /// Turn (selected) branches either on or off
      virtual void SetActive( ::Bool_t active = kTRUE,
                              const ::TString& pattern = ".*" );
      /// Read in all the variables that we need to write out as well
      virtual void ReadAllActive();

      /// Get the D3PD reading statistics
      virtual D3PDReadStats GetStatistics() const;

      /// Set the contents of the object according to another object
      EventInfoD3PDObject& Set( const EventInfoD3PDObject& parent );

      /// Event number
      VarHandle< unsigned int > EventNumber;
      /// Run number
      VarHandle< unsigned int > RunNumber;
      /// Interactions per crossing for the current BCID - for in-time pile-up
      VarHandle< float > actualIntPerXing;
      /// Interactions per crossing for all BCIDs - for out-of-time pile-up
      VarHandle< float > averageIntPerXing;
      /// Bunch crossing ID
      VarHandle< unsigned int > bcid;
      VarHandle< unsigned int > coreError;
      VarHandle< unsigned int > coreFlags;
      /// Detector mask 0
      VarHandle< unsigned int > detmask0;
      /// Detector mask 1
      VarHandle< unsigned int > detmask1;
      VarHandle< unsigned int > fwdError;
      VarHandle< unsigned int > fwdFlags;
      /// True if this is a calibration data event
      VarHandle< bool > isCalibration;
      /// True if the event comes from MC simulation
      VarHandle< bool > isSimulation;
      /// True if the event was recorded at a test-beam
      VarHandle< bool > isTestBeam;
      VarHandle< unsigned int > larError;
      VarHandle< unsigned int > larFlags;
      /// Luminosity block number
      VarHandle< unsigned int > lbn;
      /// MC generator channel number; was used as run number for generator events
      VarHandle< unsigned int > mc_channel_number;
      /// MC generator event number
      VarHandle< unsigned int > mc_event_number;
      /// MC weight, coming from the EventType object
      VarHandle< float > mc_event_weight;
      VarHandle< unsigned int > muonError;
      VarHandle< unsigned int > muonFlags;
      VarHandle< unsigned int > pixelError;
      VarHandle< unsigned int > pixelFlags;
      VarHandle< unsigned int > sctError;
      VarHandle< unsigned int > sctFlags;
      VarHandle< unsigned int > tileError;
      VarHandle< unsigned int > tileFlags;
      /// Timestamp, in seconds
      VarHandle< unsigned int > timestamp;
      /// Timestamp offset from last whole second, in ns
      VarHandle< unsigned int > timestamp_ns;
      VarHandle< unsigned int > trtError;
      VarHandle< unsigned int > trtFlags;

   private:
      std::map< ::TString, VarHandleBase* > fHandles; ///< Book-keeper of the VarHandle members
      const ::Bool_t fFromInput; ///< Flag specifying if object is used for D3PD reading
      ::TString fPrefix; ///< Prefix to the branch names

      ClassDef( EventInfoD3PDObject, 0 )

   }; // class EventInfoD3PDObject

} // namespace D3PDReader

#endif // D3PDREADER_EventInfoD3PDObject_H
