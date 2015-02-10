// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/EventInfoD3PDObject.h"

ClassImp( D3PDReader::EventInfoD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   EventInfoD3PDObject::EventInfoD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "EventNumber" ] = &EventNumber;
      fHandles[ "RunNumber" ] = &RunNumber;
      fHandles[ "actualIntPerXing" ] = &actualIntPerXing;
      fHandles[ "averageIntPerXing" ] = &averageIntPerXing;
      fHandles[ "bcid" ] = &bcid;
      fHandles[ "coreError" ] = &coreError;
      fHandles[ "coreFlags" ] = &coreFlags;
      fHandles[ "detmask0" ] = &detmask0;
      fHandles[ "detmask1" ] = &detmask1;
      fHandles[ "fwdError" ] = &fwdError;
      fHandles[ "fwdFlags" ] = &fwdFlags;
      fHandles[ "isCalibration" ] = &isCalibration;
      fHandles[ "isSimulation" ] = &isSimulation;
      fHandles[ "isTestBeam" ] = &isTestBeam;
      fHandles[ "larError" ] = &larError;
      fHandles[ "larFlags" ] = &larFlags;
      fHandles[ "lbn" ] = &lbn;
      fHandles[ "mc_channel_number" ] = &mc_channel_number;
      fHandles[ "mc_event_number" ] = &mc_event_number;
      fHandles[ "mc_event_weight" ] = &mc_event_weight;
      fHandles[ "muonError" ] = &muonError;
      fHandles[ "muonFlags" ] = &muonFlags;
      fHandles[ "pixelError" ] = &pixelError;
      fHandles[ "pixelFlags" ] = &pixelFlags;
      fHandles[ "sctError" ] = &sctError;
      fHandles[ "sctFlags" ] = &sctFlags;
      fHandles[ "tileError" ] = &tileError;
      fHandles[ "tileFlags" ] = &tileFlags;
      fHandles[ "timestamp" ] = &timestamp;
      fHandles[ "timestamp_ns" ] = &timestamp_ns;
      fHandles[ "trtError" ] = &trtError;
      fHandles[ "trtFlags" ] = &trtFlags;

      // Configure all variables in a loop:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->SetParent( this );
         itr->second->SetName( fPrefix + itr->first );
         itr->second->SetMaster( &master );
      }
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   EventInfoD3PDObject::EventInfoD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "EventNumber" ] = &EventNumber;
      fHandles[ "RunNumber" ] = &RunNumber;
      fHandles[ "actualIntPerXing" ] = &actualIntPerXing;
      fHandles[ "averageIntPerXing" ] = &averageIntPerXing;
      fHandles[ "bcid" ] = &bcid;
      fHandles[ "coreError" ] = &coreError;
      fHandles[ "coreFlags" ] = &coreFlags;
      fHandles[ "detmask0" ] = &detmask0;
      fHandles[ "detmask1" ] = &detmask1;
      fHandles[ "fwdError" ] = &fwdError;
      fHandles[ "fwdFlags" ] = &fwdFlags;
      fHandles[ "isCalibration" ] = &isCalibration;
      fHandles[ "isSimulation" ] = &isSimulation;
      fHandles[ "isTestBeam" ] = &isTestBeam;
      fHandles[ "larError" ] = &larError;
      fHandles[ "larFlags" ] = &larFlags;
      fHandles[ "lbn" ] = &lbn;
      fHandles[ "mc_channel_number" ] = &mc_channel_number;
      fHandles[ "mc_event_number" ] = &mc_event_number;
      fHandles[ "mc_event_weight" ] = &mc_event_weight;
      fHandles[ "muonError" ] = &muonError;
      fHandles[ "muonFlags" ] = &muonFlags;
      fHandles[ "pixelError" ] = &pixelError;
      fHandles[ "pixelFlags" ] = &pixelFlags;
      fHandles[ "sctError" ] = &sctError;
      fHandles[ "sctFlags" ] = &sctFlags;
      fHandles[ "tileError" ] = &tileError;
      fHandles[ "tileFlags" ] = &tileFlags;
      fHandles[ "timestamp" ] = &timestamp;
      fHandles[ "timestamp_ns" ] = &timestamp_ns;
      fHandles[ "trtError" ] = &trtError;
      fHandles[ "trtFlags" ] = &trtFlags;

      // Configure all variables in a loop:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->SetParent( this );
         itr->second->SetName( fPrefix + itr->first );
         itr->second->SetMaster( 0 );
      }
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* EventInfoD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void EventInfoD3PDObject::SetPrefix( const char* prefix ) {

      fPrefix = prefix;

      // Set all the variable names:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->SetName( ::TString( prefix ) + itr->first );
      }

      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void EventInfoD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      // Call ReadFrom(...) on all the variables:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->ReadFrom( tree );
      }

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void EventInfoD3PDObject::WriteTo( TTree* tree ) {

      // Call WriteTo(...) on all the variables:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->WriteTo( tree );
      }

      return;
   }

   /**
    * This is a convenience function for turning the branches active or
    * inactive conveniently. If the parameter is set to <code>kTRUE</code>
    * then the branches available from the input which match the given
    * pattern are turned active.
    * When it's set to <code>kFALSE</code> then all the variables matching
    * the pattern are turned inactive.
    *
    * @param active Flag behaving as explained above
    * @param pattern Regular expression specifying which branches to modify
    */
   void EventInfoD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

      ::TPRegexp re( pattern );

      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         if( ! re.Match( itr->first ) ) continue;
         if( active ) {
            if( itr->second->IsAvailable() ) itr->second->SetActive( active );
         } else {
            itr->second->SetActive( active );
         }
      }

      return;
   }

   /**
    * This function can be used to read in all the branches from the input
    * TTree which are set active for writing out. This can simplify writing
    * event selector codes immensely. Remember to set the desired variable
    * active before calling this function.
    */
   void EventInfoD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      // Read in the current entry for each active variable:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         if( ! itr->second->IsActive() ) continue;
         itr->second->ReadCurrentEntry();
      }

      return;
   }

   D3PDReadStats EventInfoD3PDObject::GetStatistics() const {

      // The result object:
      D3PDReadStats result;

      // Add the statistics from each variable to the result:
      std::map< ::TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< ::TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         result.AddVariable( itr->second->GetStatistics() );
      }

      return result;
   }

   /**
    * This function can be used to copy the contents of the entire object
    * for a given event. This can be useful for instance when the user
    * wants to copy all information to an output file, and modify it a bit,
    * and only then write it out.
    *
    * @param parent The object to copy the information from
    * @returns This same object, for convenience reasons
    */
   EventInfoD3PDObject& EventInfoD3PDObject::Set( const EventInfoD3PDObject& parent ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Set", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( parent.EventNumber.IsAvailable() ) {
         EventNumber() = parent.EventNumber();
      } else {
         EventNumber() = 0;
      }
      if( parent.RunNumber.IsAvailable() ) {
         RunNumber() = parent.RunNumber();
      } else {
         RunNumber() = 0;
      }
      if( parent.actualIntPerXing.IsAvailable() ) {
         actualIntPerXing() = parent.actualIntPerXing();
      } else {
         actualIntPerXing() = 0;
      }
      if( parent.averageIntPerXing.IsAvailable() ) {
         averageIntPerXing() = parent.averageIntPerXing();
      } else {
         averageIntPerXing() = 0;
      }
      if( parent.bcid.IsAvailable() ) {
         bcid() = parent.bcid();
      } else {
         bcid() = 0;
      }
      if( parent.coreError.IsAvailable() ) {
         coreError() = parent.coreError();
      } else {
         coreError() = 0;
      }
      if( parent.coreFlags.IsAvailable() ) {
         coreFlags() = parent.coreFlags();
      } else {
         coreFlags() = 0;
      }
      if( parent.detmask0.IsAvailable() ) {
         detmask0() = parent.detmask0();
      } else {
         detmask0() = 0;
      }
      if( parent.detmask1.IsAvailable() ) {
         detmask1() = parent.detmask1();
      } else {
         detmask1() = 0;
      }
      if( parent.fwdError.IsAvailable() ) {
         fwdError() = parent.fwdError();
      } else {
         fwdError() = 0;
      }
      if( parent.fwdFlags.IsAvailable() ) {
         fwdFlags() = parent.fwdFlags();
      } else {
         fwdFlags() = 0;
      }
      if( parent.isCalibration.IsAvailable() ) {
         isCalibration() = parent.isCalibration();
      } else {
         isCalibration() = 0;
      }
      if( parent.isSimulation.IsAvailable() ) {
         isSimulation() = parent.isSimulation();
      } else {
         isSimulation() = 0;
      }
      if( parent.isTestBeam.IsAvailable() ) {
         isTestBeam() = parent.isTestBeam();
      } else {
         isTestBeam() = 0;
      }
      if( parent.larError.IsAvailable() ) {
         larError() = parent.larError();
      } else {
         larError() = 0;
      }
      if( parent.larFlags.IsAvailable() ) {
         larFlags() = parent.larFlags();
      } else {
         larFlags() = 0;
      }
      if( parent.lbn.IsAvailable() ) {
         lbn() = parent.lbn();
      } else {
         lbn() = 0;
      }
      if( parent.mc_channel_number.IsAvailable() ) {
         mc_channel_number() = parent.mc_channel_number();
      } else {
         mc_channel_number() = 0;
      }
      if( parent.mc_event_number.IsAvailable() ) {
         mc_event_number() = parent.mc_event_number();
      } else {
         mc_event_number() = 0;
      }
      if( parent.mc_event_weight.IsAvailable() ) {
         mc_event_weight() = parent.mc_event_weight();
      } else {
         mc_event_weight() = 0;
      }
      if( parent.muonError.IsAvailable() ) {
         muonError() = parent.muonError();
      } else {
         muonError() = 0;
      }
      if( parent.muonFlags.IsAvailable() ) {
         muonFlags() = parent.muonFlags();
      } else {
         muonFlags() = 0;
      }
      if( parent.pixelError.IsAvailable() ) {
         pixelError() = parent.pixelError();
      } else {
         pixelError() = 0;
      }
      if( parent.pixelFlags.IsAvailable() ) {
         pixelFlags() = parent.pixelFlags();
      } else {
         pixelFlags() = 0;
      }
      if( parent.sctError.IsAvailable() ) {
         sctError() = parent.sctError();
      } else {
         sctError() = 0;
      }
      if( parent.sctFlags.IsAvailable() ) {
         sctFlags() = parent.sctFlags();
      } else {
         sctFlags() = 0;
      }
      if( parent.tileError.IsAvailable() ) {
         tileError() = parent.tileError();
      } else {
         tileError() = 0;
      }
      if( parent.tileFlags.IsAvailable() ) {
         tileFlags() = parent.tileFlags();
      } else {
         tileFlags() = 0;
      }
      if( parent.timestamp.IsAvailable() ) {
         timestamp() = parent.timestamp();
      } else {
         timestamp() = 0;
      }
      if( parent.timestamp_ns.IsAvailable() ) {
         timestamp_ns() = parent.timestamp_ns();
      } else {
         timestamp_ns() = 0;
      }
      if( parent.trtError.IsAvailable() ) {
         trtError() = parent.trtError();
      } else {
         trtError() = 0;
      }
      if( parent.trtFlags.IsAvailable() ) {
         trtFlags() = parent.trtFlags();
      } else {
         trtFlags() = 0;
      }

      return *this;
   }

} // namespace D3PDReader
