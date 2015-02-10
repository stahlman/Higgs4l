// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/MCEvtD3PDObject.h"

ClassImp( D3PDReader::MCEvtD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   MCEvtD3PDObject::MCEvtD3PDObject( const ::Long64_t& master, const char* prefix )
      : TObject(),
        mc_channel_number( this, ::TString( prefix ) + "mc_channel_number", &master ),
        mc_event_number( this, ::TString( prefix ) + "mc_event_number", &master ),
        mc_event_weight( this, ::TString( prefix ) + "mc_event_weight", &master ),
        mcevt_n( this, ::TString( prefix ) + "mcevt_n", &master ),
        mcevt_signal_process_id( this, ::TString( prefix ) + "mcevt_signal_process_id", &master ),
        mcevt_event_number( this, ::TString( prefix ) + "mcevt_event_number", &master ),
        mcevt_event_scale( this, ::TString( prefix ) + "mcevt_event_scale", &master ),
        mcevt_alphaQCD( this, ::TString( prefix ) + "mcevt_alphaQCD", &master ),
        mcevt_alphaQED( this, ::TString( prefix ) + "mcevt_alphaQED", &master ),
        mcevt_pdf_id1( this, ::TString( prefix ) + "mcevt_pdf_id1", &master ),
        mcevt_pdf_id2( this, ::TString( prefix ) + "mcevt_pdf_id2", &master ),
        mcevt_pdf_x1( this, ::TString( prefix ) + "mcevt_pdf_x1", &master ),
        mcevt_pdf_x2( this, ::TString( prefix ) + "mcevt_pdf_x2", &master ),
        mcevt_pdf_scale( this, ::TString( prefix ) + "mcevt_pdf_scale", &master ),
        mcevt_pdf1( this, ::TString( prefix ) + "mcevt_pdf1", &master ),
        mcevt_pdf2( this, ::TString( prefix ) + "mcevt_pdf2", &master ),
        mcevt_weight( this, ::TString( prefix ) + "mcevt_weight", &master ),
        mcevt_nparticle( this, ::TString( prefix ) + "mcevt_nparticle", &master ),
        mcevt_pileUpType( this, ::TString( prefix ) + "mcevt_pileUpType", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "mc_channel_number" ] = &mc_channel_number;
      fHandles[ "mc_event_number" ] = &mc_event_number;
      fHandles[ "mc_event_weight" ] = &mc_event_weight;
      fHandles[ "mcevt_n" ] = &mcevt_n;
      fHandles[ "mcevt_signal_process_id" ] = &mcevt_signal_process_id;
      fHandles[ "mcevt_event_number" ] = &mcevt_event_number;
      fHandles[ "mcevt_event_scale" ] = &mcevt_event_scale;
      fHandles[ "mcevt_alphaQCD" ] = &mcevt_alphaQCD;
      fHandles[ "mcevt_alphaQED" ] = &mcevt_alphaQED;
      fHandles[ "mcevt_pdf_id1" ] = &mcevt_pdf_id1;
      fHandles[ "mcevt_pdf_id2" ] = &mcevt_pdf_id2;
      fHandles[ "mcevt_pdf_x1" ] = &mcevt_pdf_x1;
      fHandles[ "mcevt_pdf_x2" ] = &mcevt_pdf_x2;
      fHandles[ "mcevt_pdf_scale" ] = &mcevt_pdf_scale;
      fHandles[ "mcevt_pdf1" ] = &mcevt_pdf1;
      fHandles[ "mcevt_pdf2" ] = &mcevt_pdf2;
      fHandles[ "mcevt_weight" ] = &mcevt_weight;
      fHandles[ "mcevt_nparticle" ] = &mcevt_nparticle;
      fHandles[ "mcevt_pileUpType" ] = &mcevt_pileUpType;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   MCEvtD3PDObject::MCEvtD3PDObject( const char* prefix )
      : TObject(),
        mc_channel_number( this, ::TString( prefix ) + "mc_channel_number", 0 ),
        mc_event_number( this, ::TString( prefix ) + "mc_event_number", 0 ),
        mc_event_weight( this, ::TString( prefix ) + "mc_event_weight", 0 ),
        mcevt_n( this, ::TString( prefix ) + "mcevt_n", 0 ),
        mcevt_signal_process_id( this, ::TString( prefix ) + "mcevt_signal_process_id", 0 ),
        mcevt_event_number( this, ::TString( prefix ) + "mcevt_event_number", 0 ),
        mcevt_event_scale( this, ::TString( prefix ) + "mcevt_event_scale", 0 ),
        mcevt_alphaQCD( this, ::TString( prefix ) + "mcevt_alphaQCD", 0 ),
        mcevt_alphaQED( this, ::TString( prefix ) + "mcevt_alphaQED", 0 ),
        mcevt_pdf_id1( this, ::TString( prefix ) + "mcevt_pdf_id1", 0 ),
        mcevt_pdf_id2( this, ::TString( prefix ) + "mcevt_pdf_id2", 0 ),
        mcevt_pdf_x1( this, ::TString( prefix ) + "mcevt_pdf_x1", 0 ),
        mcevt_pdf_x2( this, ::TString( prefix ) + "mcevt_pdf_x2", 0 ),
        mcevt_pdf_scale( this, ::TString( prefix ) + "mcevt_pdf_scale", 0 ),
        mcevt_pdf1( this, ::TString( prefix ) + "mcevt_pdf1", 0 ),
        mcevt_pdf2( this, ::TString( prefix ) + "mcevt_pdf2", 0 ),
        mcevt_weight( this, ::TString( prefix ) + "mcevt_weight", 0 ),
        mcevt_nparticle( this, ::TString( prefix ) + "mcevt_nparticle", 0 ),
        mcevt_pileUpType( this, ::TString( prefix ) + "mcevt_pileUpType", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "mc_channel_number" ] = &mc_channel_number;
      fHandles[ "mc_event_number" ] = &mc_event_number;
      fHandles[ "mc_event_weight" ] = &mc_event_weight;
      fHandles[ "mcevt_n" ] = &mcevt_n;
      fHandles[ "mcevt_signal_process_id" ] = &mcevt_signal_process_id;
      fHandles[ "mcevt_event_number" ] = &mcevt_event_number;
      fHandles[ "mcevt_event_scale" ] = &mcevt_event_scale;
      fHandles[ "mcevt_alphaQCD" ] = &mcevt_alphaQCD;
      fHandles[ "mcevt_alphaQED" ] = &mcevt_alphaQED;
      fHandles[ "mcevt_pdf_id1" ] = &mcevt_pdf_id1;
      fHandles[ "mcevt_pdf_id2" ] = &mcevt_pdf_id2;
      fHandles[ "mcevt_pdf_x1" ] = &mcevt_pdf_x1;
      fHandles[ "mcevt_pdf_x2" ] = &mcevt_pdf_x2;
      fHandles[ "mcevt_pdf_scale" ] = &mcevt_pdf_scale;
      fHandles[ "mcevt_pdf1" ] = &mcevt_pdf1;
      fHandles[ "mcevt_pdf2" ] = &mcevt_pdf2;
      fHandles[ "mcevt_weight" ] = &mcevt_weight;
      fHandles[ "mcevt_nparticle" ] = &mcevt_nparticle;
      fHandles[ "mcevt_pileUpType" ] = &mcevt_pileUpType;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* MCEvtD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void MCEvtD3PDObject::SetPrefix( const char* prefix ) {

      mc_channel_number.SetName( ::TString( prefix ) + "mc_channel_number" );
      mc_event_number.SetName( ::TString( prefix ) + "mc_event_number" );
      mc_event_weight.SetName( ::TString( prefix ) + "mc_event_weight" );
      mcevt_n.SetName( ::TString( prefix ) + "mcevt_n" );
      mcevt_signal_process_id.SetName( ::TString( prefix ) + "mcevt_signal_process_id" );
      mcevt_event_number.SetName( ::TString( prefix ) + "mcevt_event_number" );
      mcevt_event_scale.SetName( ::TString( prefix ) + "mcevt_event_scale" );
      mcevt_alphaQCD.SetName( ::TString( prefix ) + "mcevt_alphaQCD" );
      mcevt_alphaQED.SetName( ::TString( prefix ) + "mcevt_alphaQED" );
      mcevt_pdf_id1.SetName( ::TString( prefix ) + "mcevt_pdf_id1" );
      mcevt_pdf_id2.SetName( ::TString( prefix ) + "mcevt_pdf_id2" );
      mcevt_pdf_x1.SetName( ::TString( prefix ) + "mcevt_pdf_x1" );
      mcevt_pdf_x2.SetName( ::TString( prefix ) + "mcevt_pdf_x2" );
      mcevt_pdf_scale.SetName( ::TString( prefix ) + "mcevt_pdf_scale" );
      mcevt_pdf1.SetName( ::TString( prefix ) + "mcevt_pdf1" );
      mcevt_pdf2.SetName( ::TString( prefix ) + "mcevt_pdf2" );
      mcevt_weight.SetName( ::TString( prefix ) + "mcevt_weight" );
      mcevt_nparticle.SetName( ::TString( prefix ) + "mcevt_nparticle" );
      mcevt_pileUpType.SetName( ::TString( prefix ) + "mcevt_pileUpType" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void MCEvtD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      mc_channel_number.ReadFrom( tree );
      mc_event_number.ReadFrom( tree );
      mc_event_weight.ReadFrom( tree );
      mcevt_n.ReadFrom( tree );
      mcevt_signal_process_id.ReadFrom( tree );
      mcevt_event_number.ReadFrom( tree );
      mcevt_event_scale.ReadFrom( tree );
      mcevt_alphaQCD.ReadFrom( tree );
      mcevt_alphaQED.ReadFrom( tree );
      mcevt_pdf_id1.ReadFrom( tree );
      mcevt_pdf_id2.ReadFrom( tree );
      mcevt_pdf_x1.ReadFrom( tree );
      mcevt_pdf_x2.ReadFrom( tree );
      mcevt_pdf_scale.ReadFrom( tree );
      mcevt_pdf1.ReadFrom( tree );
      mcevt_pdf2.ReadFrom( tree );
      mcevt_weight.ReadFrom( tree );
      mcevt_nparticle.ReadFrom( tree );
      mcevt_pileUpType.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void MCEvtD3PDObject::WriteTo( TTree* tree ) {

      mc_channel_number.WriteTo( tree );
      mc_event_number.WriteTo( tree );
      mc_event_weight.WriteTo( tree );
      mcevt_n.WriteTo( tree );
      mcevt_signal_process_id.WriteTo( tree );
      mcevt_event_number.WriteTo( tree );
      mcevt_event_scale.WriteTo( tree );
      mcevt_alphaQCD.WriteTo( tree );
      mcevt_alphaQED.WriteTo( tree );
      mcevt_pdf_id1.WriteTo( tree );
      mcevt_pdf_id2.WriteTo( tree );
      mcevt_pdf_x1.WriteTo( tree );
      mcevt_pdf_x2.WriteTo( tree );
      mcevt_pdf_scale.WriteTo( tree );
      mcevt_pdf1.WriteTo( tree );
      mcevt_pdf2.WriteTo( tree );
      mcevt_weight.WriteTo( tree );
      mcevt_nparticle.WriteTo( tree );
      mcevt_pileUpType.WriteTo( tree );

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
   void MCEvtD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void MCEvtD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( mc_channel_number.IsActive() ) mc_channel_number();
      if( mc_event_number.IsActive() ) mc_event_number();
      if( mc_event_weight.IsActive() ) mc_event_weight();
      if( mcevt_n.IsActive() ) mcevt_n();
      if( mcevt_signal_process_id.IsActive() ) mcevt_signal_process_id();
      if( mcevt_event_number.IsActive() ) mcevt_event_number();
      if( mcevt_event_scale.IsActive() ) mcevt_event_scale();
      if( mcevt_alphaQCD.IsActive() ) mcevt_alphaQCD();
      if( mcevt_alphaQED.IsActive() ) mcevt_alphaQED();
      if( mcevt_pdf_id1.IsActive() ) mcevt_pdf_id1();
      if( mcevt_pdf_id2.IsActive() ) mcevt_pdf_id2();
      if( mcevt_pdf_x1.IsActive() ) mcevt_pdf_x1();
      if( mcevt_pdf_x2.IsActive() ) mcevt_pdf_x2();
      if( mcevt_pdf_scale.IsActive() ) mcevt_pdf_scale();
      if( mcevt_pdf1.IsActive() ) mcevt_pdf1();
      if( mcevt_pdf2.IsActive() ) mcevt_pdf2();
      if( mcevt_weight.IsActive() ) mcevt_weight();
      if( mcevt_nparticle.IsActive() ) mcevt_nparticle();
      if( mcevt_pileUpType.IsActive() ) mcevt_pileUpType();

      return;
   }

} // namespace D3PDReader
