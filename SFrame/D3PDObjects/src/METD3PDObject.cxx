// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/METD3PDObject.h"

ClassImp( D3PDReader::METD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   METD3PDObject::METD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "et" ] = &et;
      //fHandles[ "etx" ] = &etx;
      fHandles[ "etx_CentralReg" ] = &etx_CentralReg;
      fHandles[ "etx_EndcapRegion" ] = &etx_EndcapRegion;
      fHandles[ "etx_ForwardReg" ] = &etx_ForwardReg;
      //fHandles[ "ety" ] = &ety;
      fHandles[ "ety_CentralReg" ] = &ety_CentralReg;
      fHandles[ "ety_EndcapRegion" ] = &ety_EndcapRegion;
      fHandles[ "ety_ForwardReg" ] = &ety_ForwardReg;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phi_CentralReg" ] = &phi_CentralReg;
      fHandles[ "phi_EndcapRegion" ] = &phi_EndcapRegion;
      fHandles[ "phi_ForwardReg" ] = &phi_ForwardReg;
      fHandles[ "sumet" ] = &sumet;
      fHandles[ "sumet_CentralReg" ] = &sumet_CentralReg;
      fHandles[ "sumet_EndcapRegion" ] = &sumet_EndcapRegion;
      fHandles[ "sumet_ForwardReg" ] = &sumet_ForwardReg;

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
   METD3PDObject::METD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "et" ] = &et;
      //fHandles[ "etx" ] = &etx;
      fHandles[ "etx_CentralReg" ] = &etx_CentralReg;
      fHandles[ "etx_EndcapRegion" ] = &etx_EndcapRegion;
      fHandles[ "etx_ForwardReg" ] = &etx_ForwardReg;
      //fHandles[ "ety" ] = &ety;
      fHandles[ "ety_CentralReg" ] = &ety_CentralReg;
      fHandles[ "ety_EndcapRegion" ] = &ety_EndcapRegion;
      fHandles[ "ety_ForwardReg" ] = &ety_ForwardReg;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phi_CentralReg" ] = &phi_CentralReg;
      fHandles[ "phi_EndcapRegion" ] = &phi_EndcapRegion;
      fHandles[ "phi_ForwardReg" ] = &phi_ForwardReg;
      fHandles[ "sumet" ] = &sumet;
      fHandles[ "sumet_CentralReg" ] = &sumet_CentralReg;
      fHandles[ "sumet_EndcapRegion" ] = &sumet_EndcapRegion;
      fHandles[ "sumet_ForwardReg" ] = &sumet_ForwardReg;

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
   const char* METD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void METD3PDObject::SetPrefix( const char* prefix ) {

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
   void METD3PDObject::ReadFrom( TTree* tree ) {

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
   void METD3PDObject::WriteTo( TTree* tree ) {

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
   void METD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void METD3PDObject::ReadAllActive() {

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

   D3PDReadStats METD3PDObject::GetStatistics() const {

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
   METD3PDObject& METD3PDObject::Set( const METD3PDObject& parent ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Set", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( parent.et.IsAvailable() ) {
         et() = parent.et();
      } else {
         et() = 0;
      }
     //  if( parent.etx.IsAvailable() ) {
//          etx() = parent.etx();
//       } else {
//          etx() = 0;
//       }
      if( parent.etx_CentralReg.IsAvailable() ) {
         etx_CentralReg() = parent.etx_CentralReg();
      } else {
         etx_CentralReg() = 0;
      }
      if( parent.etx_EndcapRegion.IsAvailable() ) {
         etx_EndcapRegion() = parent.etx_EndcapRegion();
      } else {
         etx_EndcapRegion() = 0;
      }
      if( parent.etx_ForwardReg.IsAvailable() ) {
         etx_ForwardReg() = parent.etx_ForwardReg();
      } else {
         etx_ForwardReg() = 0;
      }
   //    if( parent.ety.IsAvailable() ) {
//          ety() = parent.ety();
//       } else {
//          ety() = 0;
//       }
      if( parent.ety_CentralReg.IsAvailable() ) {
         ety_CentralReg() = parent.ety_CentralReg();
      } else {
         ety_CentralReg() = 0;
      }
      if( parent.ety_EndcapRegion.IsAvailable() ) {
         ety_EndcapRegion() = parent.ety_EndcapRegion();
      } else {
         ety_EndcapRegion() = 0;
      }
      if( parent.ety_ForwardReg.IsAvailable() ) {
         ety_ForwardReg() = parent.ety_ForwardReg();
      } else {
         ety_ForwardReg() = 0;
      }
      if( parent.phi.IsAvailable() ) {
         phi() = parent.phi();
      } else {
         phi() = 0;
      }
      if( parent.phi_CentralReg.IsAvailable() ) {
         phi_CentralReg() = parent.phi_CentralReg();
      } else {
         phi_CentralReg() = 0;
      }
      if( parent.phi_EndcapRegion.IsAvailable() ) {
         phi_EndcapRegion() = parent.phi_EndcapRegion();
      } else {
         phi_EndcapRegion() = 0;
      }
      if( parent.phi_ForwardReg.IsAvailable() ) {
         phi_ForwardReg() = parent.phi_ForwardReg();
      } else {
         phi_ForwardReg() = 0;
      }
      if( parent.sumet.IsAvailable() ) {
         sumet() = parent.sumet();
      } else {
         sumet() = 0;
      }
      if( parent.sumet_CentralReg.IsAvailable() ) {
         sumet_CentralReg() = parent.sumet_CentralReg();
      } else {
         sumet_CentralReg() = 0;
      }
      if( parent.sumet_EndcapRegion.IsAvailable() ) {
         sumet_EndcapRegion() = parent.sumet_EndcapRegion();
      } else {
         sumet_EndcapRegion() = 0;
      }
      if( parent.sumet_ForwardReg.IsAvailable() ) {
         sumet_ForwardReg() = parent.sumet_ForwardReg();
      } else {
         sumet_ForwardReg() = 0;
      }

      return *this;
   }

} // namespace D3PDReader
