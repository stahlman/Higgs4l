// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/TruthParticleD3PDObject.h"

ClassImp( D3PDReader::TruthParticleD3PDObjectElement )
ClassImp( D3PDReader::TruthParticleD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class TruthParticleD3PDObject.
    */
   TruthParticleD3PDObjectElement::TruthParticleD3PDObjectElement( size_t index, const TruthParticleD3PDObject& parent )
      : barcode( parent.barcode, index, this ),
        charge( parent.charge, index, this ),
        child_index( parent.child_index, index, this ),
        children( parent.children, index, this ),
        eta( parent.eta, index, this ),
        m( parent.m, index, this ),
        parent_index( parent.parent_index, index, this ),
        parents( parent.parents, index, this ),
        pdgId( parent.pdgId, index, this ),
        phi( parent.phi, index, this ),
        pt( parent.pt, index, this ),
        status( parent.status, index, this ),
        vx_barcode( parent.vx_barcode, index, this ),
        vx_x( parent.vx_x, index, this ),
        vx_y( parent.vx_y, index, this ),
        vx_z( parent.vx_z, index, this ),
        fParent( &parent ), fIndex( index ) {

   }

   /**
    * This constructor is useful for creating copies of proxy objects.
    * Such objects are fairly cheap to copy, so the user is allowed to have
    * his/her containers of them inside an analysis code. (To select and
    * sort objects according to some criteria for instance.)
    *
    * @param parent The proxy object that should be copied
    */
   TruthParticleD3PDObjectElement::TruthParticleD3PDObjectElement( const TruthParticleD3PDObjectElement& parent )
      : TObject( parent ),
        barcode( parent.barcode ),
        charge( parent.charge ),
        child_index( parent.child_index ),
        children( parent.children ),
        eta( parent.eta ),
        m( parent.m ),
        parent_index( parent.parent_index ),
        parents( parent.parents ),
        pdgId( parent.pdgId ),
        phi( parent.phi ),
        pt( parent.pt ),
        status( parent.status ),
        vx_barcode( parent.vx_barcode ),
        vx_x( parent.vx_x ),
        vx_y( parent.vx_y ),
        vx_z( parent.vx_z ),
        fParent( parent.fParent ), fIndex( parent.fIndex ) {

   }

   /**
    * This function can be used to access the parent object of this
    * proxy object. It can come in handy when optimizing an analysis code.
    *
    * @returns A reference to this object's parent
    */
   const TruthParticleD3PDObject* TruthParticleD3PDObjectElement::GetParent() const {

      return fParent;
   }

   /**
    * This function can be used to access the index of this proxy object
    * inside the parent container. It can come in handy when optimizing an
    * analysis code.
    *
    * @returns The index of the proxy in the object's parent
    */
   size_t TruthParticleD3PDObjectElement::GetIndex() const {

      return fIndex;
   }

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   TruthParticleD3PDObject::TruthParticleD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "barcode" ] = &barcode;
      fHandles[ "charge" ] = &charge;
      fHandles[ "child_index" ] = &child_index;
      fHandles[ "children" ] = &children;
      fHandles[ "eta" ] = &eta;
      fHandles[ "m" ] = &m;
      fHandles[ "n" ] = &n;
      fHandles[ "parent_index" ] = &parent_index;
      fHandles[ "parents" ] = &parents;
      fHandles[ "pdgId" ] = &pdgId;
      fHandles[ "phi" ] = &phi;
      fHandles[ "pt" ] = &pt;
      fHandles[ "status" ] = &status;
      fHandles[ "vx_barcode" ] = &vx_barcode;
      fHandles[ "vx_x" ] = &vx_x;
      fHandles[ "vx_y" ] = &vx_y;
      fHandles[ "vx_z" ] = &vx_z;

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
   TruthParticleD3PDObject::TruthParticleD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "barcode" ] = &barcode;
      fHandles[ "charge" ] = &charge;
      fHandles[ "child_index" ] = &child_index;
      fHandles[ "children" ] = &children;
      fHandles[ "eta" ] = &eta;
      fHandles[ "m" ] = &m;
      fHandles[ "n" ] = &n;
      fHandles[ "parent_index" ] = &parent_index;
      fHandles[ "parents" ] = &parents;
      fHandles[ "pdgId" ] = &pdgId;
      fHandles[ "phi" ] = &phi;
      fHandles[ "pt" ] = &pt;
      fHandles[ "status" ] = &status;
      fHandles[ "vx_barcode" ] = &vx_barcode;
      fHandles[ "vx_x" ] = &vx_x;
      fHandles[ "vx_y" ] = &vx_y;
      fHandles[ "vx_z" ] = &vx_z;

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
    * The destructor needs to delete all the allocated objects.
    */
   TruthParticleD3PDObject::~TruthParticleD3PDObject() {

      for( size_t i = 0; i < fProxies.size(); ++i ) {
         delete fProxies[ i ];
      }
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TruthParticleD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TruthParticleD3PDObject::SetPrefix( const char* prefix ) {

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
   void TruthParticleD3PDObject::ReadFrom( TTree* tree ) {

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
   void TruthParticleD3PDObject::WriteTo( TTree* tree ) {

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
   void TruthParticleD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void TruthParticleD3PDObject::ReadAllActive() {

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

   D3PDReadStats TruthParticleD3PDObject::GetStatistics() const {

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
   TruthParticleD3PDObject& TruthParticleD3PDObject::Set( const TruthParticleD3PDObject& parent ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Set", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( parent.barcode.IsAvailable() ) {
         *( barcode() ) = *( parent.barcode() );
      } else {
         barcode()->clear();
      }
      if( parent.charge.IsAvailable() ) {
         *( charge() ) = *( parent.charge() );
      } else {
         charge()->clear();
      }
      if( parent.child_index.IsAvailable() ) {
         *( child_index() ) = *( parent.child_index() );
      } else {
         child_index()->clear();
      }
      if( parent.children.IsAvailable() ) {
         *( children() ) = *( parent.children() );
      } else {
         children()->clear();
      }
      if( parent.eta.IsAvailable() ) {
         *( eta() ) = *( parent.eta() );
      } else {
         eta()->clear();
      }
      if( parent.m.IsAvailable() ) {
         *( m() ) = *( parent.m() );
      } else {
         m()->clear();
      }
      if( parent.n.IsAvailable() ) {
         n() = parent.n();
      } else {
         n() = 0;
      }
      if( parent.parent_index.IsAvailable() ) {
         *( parent_index() ) = *( parent.parent_index() );
      } else {
         parent_index()->clear();
      }
      if( parent.parents.IsAvailable() ) {
         *( parents() ) = *( parent.parents() );
      } else {
         parents()->clear();
      }
      if( parent.pdgId.IsAvailable() ) {
         *( pdgId() ) = *( parent.pdgId() );
      } else {
         pdgId()->clear();
      }
      if( parent.phi.IsAvailable() ) {
         *( phi() ) = *( parent.phi() );
      } else {
         phi()->clear();
      }
      if( parent.pt.IsAvailable() ) {
         *( pt() ) = *( parent.pt() );
      } else {
         pt()->clear();
      }
      if( parent.status.IsAvailable() ) {
         *( status() ) = *( parent.status() );
      } else {
         status()->clear();
      }
      if( parent.vx_barcode.IsAvailable() ) {
         *( vx_barcode() ) = *( parent.vx_barcode() );
      } else {
         vx_barcode()->clear();
      }
      if( parent.vx_x.IsAvailable() ) {
         *( vx_x() ) = *( parent.vx_x() );
      } else {
         vx_x()->clear();
      }
      if( parent.vx_y.IsAvailable() ) {
         *( vx_y() ) = *( parent.vx_y() );
      } else {
         vx_y()->clear();
      }
      if( parent.vx_z.IsAvailable() ) {
         *( vx_z() ) = *( parent.vx_z() );
      } else {
         vx_z()->clear();
      }

      return *this;
   }

   /**
    * This function makes it easier to clear out the object completely.
    * It cleares all the vector variables, and sets the element number
    * variable to 0. Very useful when performing object selection.
    * The option argument is not used at the moment for anything.
    * It's only there because the <code>Clear</code> function defined in
    * TObject has this parameter as well.
    *
    * @param option Ignored at the moment
    */
   void TruthParticleD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      // Clear each variable:
      std::map< ::TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< ::TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->Clear();
      }

      return;
   }

   /**
    * This function can be used to easily add an 'element' describing one
    * object to an output collection. Comes in very handy when performing
    * object selection.
    *
    * Note that variables which are not available from the input, will be
    * filled with dummy values.
    *
    * @param el The 'element' that should be added to the collection
    */
   TruthParticleD3PDObject& TruthParticleD3PDObject::Add( const TruthParticleD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( el.barcode.IsAvailable() ) {
         barcode()->push_back( el.barcode() );
      } else {
         barcode()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.charge.IsAvailable() ) {
         charge()->push_back( el.charge() );
      } else {
         charge()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.child_index.IsAvailable() ) {
         child_index()->push_back( el.child_index() );
      } else {
         child_index()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.children.IsAvailable() ) {
         children()->push_back( el.children() );
      } else {
         children()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.eta.IsAvailable() ) {
         eta()->push_back( el.eta() );
      } else {
         eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
      }
      ++( n() );
      if( el.parent_index.IsAvailable() ) {
         parent_index()->push_back( el.parent_index() );
      } else {
         parent_index()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.parents.IsAvailable() ) {
         parents()->push_back( el.parents() );
      } else {
         parents()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.pdgId.IsAvailable() ) {
         pdgId()->push_back( el.pdgId() );
      } else {
         pdgId()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.phi.IsAvailable() ) {
         phi()->push_back( el.phi() );
      } else {
         phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pt.IsAvailable() ) {
         pt()->push_back( el.pt() );
      } else {
         pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.status.IsAvailable() ) {
         status()->push_back( el.status() );
      } else {
         status()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.vx_barcode.IsAvailable() ) {
         vx_barcode()->push_back( el.vx_barcode() );
      } else {
         vx_barcode()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.vx_x.IsAvailable() ) {
         vx_x()->push_back( el.vx_x() );
      } else {
         vx_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.vx_y.IsAvailable() ) {
         vx_y()->push_back( el.vx_y() );
      } else {
         vx_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.vx_z.IsAvailable() ) {
         vx_z()->push_back( el.vx_z() );
      } else {
         vx_z()->push_back( std::numeric_limits< float >::min() );
      }
      return *this;
   }

   /**
    * This operator can be used to get access to one element in the
    * collection. This element can then be passed around between parts
    * of the analysis code easily.
    *
    * This version is useful when modifying the variable contents through
    * the proxy objects.
    *
    * @param index Index of the element inside the collection
    */
   TruthParticleD3PDObjectElement& TruthParticleD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new TruthParticleD3PDObjectElement( fProxies.size(), *this ) );
      }
      return *fProxies[ index ];
   }

   /**
    * This operator can be used to get access to one element in the
    * collection. This element can then be passed around between parts
    * of the analysis code easily.
    *
    * This version is useful when only reading the variables.
    *
    * @param index Index of the element inside the collection
    */
   const TruthParticleD3PDObjectElement& TruthParticleD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new TruthParticleD3PDObjectElement( fProxies.size(), *this ) );
      }
      return *fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   TruthParticleD3PDObject& TruthParticleD3PDObject::operator+=( const TruthParticleD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
