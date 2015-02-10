// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/PrimaryVertexD3PDObject.h"

ClassImp( D3PDReader::PrimaryVertexD3PDObjectElement )
ClassImp( D3PDReader::PrimaryVertexD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class PrimaryVertexD3PDObject.
    */
   PrimaryVertexD3PDObjectElement::PrimaryVertexD3PDObjectElement( size_t index, const PrimaryVertexD3PDObject& parent )
      : E( parent.E, index, this ),
        chi2( parent.chi2, index, this ),
        cov_x( parent.cov_x, index, this ),
        cov_xy( parent.cov_xy, index, this ),
        cov_xz( parent.cov_xz, index, this ),
        cov_y( parent.cov_y, index, this ),
        cov_yz( parent.cov_yz, index, this ),
        cov_z( parent.cov_z, index, this ),
        m( parent.m, index, this ),
        nTracks( parent.nTracks, index, this ),
        ndof( parent.ndof, index, this ),
        px( parent.px, index, this ),
        py( parent.py, index, this ),
        pz( parent.pz, index, this ),
        sumPt( parent.sumPt, index, this ),
        trk_index( parent.trk_index, index, this ),
        trk_n( parent.trk_n, index, this ),
        trk_weight( parent.trk_weight, index, this ),
        type( parent.type, index, this ),
        x( parent.x, index, this ),
        y( parent.y, index, this ),
        z( parent.z, index, this ),
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
   PrimaryVertexD3PDObjectElement::PrimaryVertexD3PDObjectElement( const PrimaryVertexD3PDObjectElement& parent )
      : TObject( parent ),
        E( parent.E ),
        chi2( parent.chi2 ),
        cov_x( parent.cov_x ),
        cov_xy( parent.cov_xy ),
        cov_xz( parent.cov_xz ),
        cov_y( parent.cov_y ),
        cov_yz( parent.cov_yz ),
        cov_z( parent.cov_z ),
        m( parent.m ),
        nTracks( parent.nTracks ),
        ndof( parent.ndof ),
        px( parent.px ),
        py( parent.py ),
        pz( parent.pz ),
        sumPt( parent.sumPt ),
        trk_index( parent.trk_index ),
        trk_n( parent.trk_n ),
        trk_weight( parent.trk_weight ),
        type( parent.type ),
        x( parent.x ),
        y( parent.y ),
        z( parent.z ),
        fParent( parent.fParent ), fIndex( parent.fIndex ) {

   }

   /**
    * This function can be used to access the parent object of this
    * proxy object. It can come in handy when optimizing an analysis code.
    *
    * @returns A reference to this object's parent
    */
   const PrimaryVertexD3PDObject* PrimaryVertexD3PDObjectElement::GetParent() const {

      return fParent;
   }

   /**
    * This function can be used to access the index of this proxy object
    * inside the parent container. It can come in handy when optimizing an
    * analysis code.
    *
    * @returns The index of the proxy in the object's parent
    */
   size_t PrimaryVertexD3PDObjectElement::GetIndex() const {

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
   PrimaryVertexD3PDObject::PrimaryVertexD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "E" ] = &E;
      fHandles[ "chi2" ] = &chi2;
      fHandles[ "cov_x" ] = &cov_x;
      fHandles[ "cov_xy" ] = &cov_xy;
      fHandles[ "cov_xz" ] = &cov_xz;
      fHandles[ "cov_y" ] = &cov_y;
      fHandles[ "cov_yz" ] = &cov_yz;
      fHandles[ "cov_z" ] = &cov_z;
      fHandles[ "m" ] = &m;
      fHandles[ "n" ] = &n;
      fHandles[ "nTracks" ] = &nTracks;
      fHandles[ "ndof" ] = &ndof;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "sumPt" ] = &sumPt;
      fHandles[ "trk_index" ] = &trk_index;
      fHandles[ "trk_n" ] = &trk_n;
      fHandles[ "trk_weight" ] = &trk_weight;
      fHandles[ "type" ] = &type;
      fHandles[ "x" ] = &x;
      fHandles[ "y" ] = &y;
      fHandles[ "z" ] = &z;

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
   PrimaryVertexD3PDObject::PrimaryVertexD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "E" ] = &E;
      fHandles[ "chi2" ] = &chi2;
      fHandles[ "cov_x" ] = &cov_x;
      fHandles[ "cov_xy" ] = &cov_xy;
      fHandles[ "cov_xz" ] = &cov_xz;
      fHandles[ "cov_y" ] = &cov_y;
      fHandles[ "cov_yz" ] = &cov_yz;
      fHandles[ "cov_z" ] = &cov_z;
      fHandles[ "m" ] = &m;
      fHandles[ "n" ] = &n;
      fHandles[ "nTracks" ] = &nTracks;
      fHandles[ "ndof" ] = &ndof;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "sumPt" ] = &sumPt;
      fHandles[ "trk_index" ] = &trk_index;
      fHandles[ "trk_n" ] = &trk_n;
      fHandles[ "trk_weight" ] = &trk_weight;
      fHandles[ "type" ] = &type;
      fHandles[ "x" ] = &x;
      fHandles[ "y" ] = &y;
      fHandles[ "z" ] = &z;

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
   PrimaryVertexD3PDObject::~PrimaryVertexD3PDObject() {

      for( size_t i = 0; i < fProxies.size(); ++i ) {
         delete fProxies[ i ];
      }
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* PrimaryVertexD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void PrimaryVertexD3PDObject::SetPrefix( const char* prefix ) {

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
   void PrimaryVertexD3PDObject::ReadFrom( TTree* tree ) {

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
   void PrimaryVertexD3PDObject::WriteTo( TTree* tree ) {

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
   void PrimaryVertexD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void PrimaryVertexD3PDObject::ReadAllActive() {

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

   D3PDReadStats PrimaryVertexD3PDObject::GetStatistics() const {

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
   PrimaryVertexD3PDObject& PrimaryVertexD3PDObject::Set( const PrimaryVertexD3PDObject& parent ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Set", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( parent.E.IsAvailable() ) {
         *( E() ) = *( parent.E() );
      } else {
         E()->clear();
      }
      if( parent.chi2.IsAvailable() ) {
         *( chi2() ) = *( parent.chi2() );
      } else {
         chi2()->clear();
      }
      if( parent.cov_x.IsAvailable() ) {
         *( cov_x() ) = *( parent.cov_x() );
      } else {
         cov_x()->clear();
      }
      if( parent.cov_xy.IsAvailable() ) {
         *( cov_xy() ) = *( parent.cov_xy() );
      } else {
         cov_xy()->clear();
      }
      if( parent.cov_xz.IsAvailable() ) {
         *( cov_xz() ) = *( parent.cov_xz() );
      } else {
         cov_xz()->clear();
      }
      if( parent.cov_y.IsAvailable() ) {
         *( cov_y() ) = *( parent.cov_y() );
      } else {
         cov_y()->clear();
      }
      if( parent.cov_yz.IsAvailable() ) {
         *( cov_yz() ) = *( parent.cov_yz() );
      } else {
         cov_yz()->clear();
      }
      if( parent.cov_z.IsAvailable() ) {
         *( cov_z() ) = *( parent.cov_z() );
      } else {
         cov_z()->clear();
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
      if( parent.nTracks.IsAvailable() ) {
         *( nTracks() ) = *( parent.nTracks() );
      } else {
         nTracks()->clear();
      }
      if( parent.ndof.IsAvailable() ) {
         *( ndof() ) = *( parent.ndof() );
      } else {
         ndof()->clear();
      }
      if( parent.px.IsAvailable() ) {
         *( px() ) = *( parent.px() );
      } else {
         px()->clear();
      }
      if( parent.py.IsAvailable() ) {
         *( py() ) = *( parent.py() );
      } else {
         py()->clear();
      }
      if( parent.pz.IsAvailable() ) {
         *( pz() ) = *( parent.pz() );
      } else {
         pz()->clear();
      }
      if( parent.sumPt.IsAvailable() ) {
         *( sumPt() ) = *( parent.sumPt() );
      } else {
         sumPt()->clear();
      }
      if( parent.trk_index.IsAvailable() ) {
         *( trk_index() ) = *( parent.trk_index() );
      } else {
         trk_index()->clear();
      }
      if( parent.trk_n.IsAvailable() ) {
         *( trk_n() ) = *( parent.trk_n() );
      } else {
         trk_n()->clear();
      }
      if( parent.trk_weight.IsAvailable() ) {
         *( trk_weight() ) = *( parent.trk_weight() );
      } else {
         trk_weight()->clear();
      }
      if( parent.type.IsAvailable() ) {
         *( type() ) = *( parent.type() );
      } else {
         type()->clear();
      }
      if( parent.x.IsAvailable() ) {
         *( x() ) = *( parent.x() );
      } else {
         x()->clear();
      }
      if( parent.y.IsAvailable() ) {
         *( y() ) = *( parent.y() );
      } else {
         y()->clear();
      }
      if( parent.z.IsAvailable() ) {
         *( z() ) = *( parent.z() );
      } else {
         z()->clear();
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
   void PrimaryVertexD3PDObject::Clear( Option_t* ) {

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
   PrimaryVertexD3PDObject& PrimaryVertexD3PDObject::Add( const PrimaryVertexD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( el.E.IsAvailable() ) {
         E()->push_back( el.E() );
      } else {
         E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.chi2.IsAvailable() ) {
         chi2()->push_back( el.chi2() );
      } else {
         chi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_x.IsAvailable() ) {
         cov_x()->push_back( el.cov_x() );
      } else {
         cov_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_xy.IsAvailable() ) {
         cov_xy()->push_back( el.cov_xy() );
      } else {
         cov_xy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_xz.IsAvailable() ) {
         cov_xz()->push_back( el.cov_xz() );
      } else {
         cov_xz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_y.IsAvailable() ) {
         cov_y()->push_back( el.cov_y() );
      } else {
         cov_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_yz.IsAvailable() ) {
         cov_yz()->push_back( el.cov_yz() );
      } else {
         cov_yz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z.IsAvailable() ) {
         cov_z()->push_back( el.cov_z() );
      } else {
         cov_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
      }
      ++( n() );
      if( el.nTracks.IsAvailable() ) {
         nTracks()->push_back( el.nTracks() );
      } else {
         nTracks()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ndof.IsAvailable() ) {
         ndof()->push_back( el.ndof() );
      } else {
         ndof()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.px.IsAvailable() ) {
         px()->push_back( el.px() );
      } else {
         px()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.py.IsAvailable() ) {
         py()->push_back( el.py() );
      } else {
         py()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pz.IsAvailable() ) {
         pz()->push_back( el.pz() );
      } else {
         pz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.sumPt.IsAvailable() ) {
         sumPt()->push_back( el.sumPt() );
      } else {
         sumPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trk_index.IsAvailable() ) {
         trk_index()->push_back( el.trk_index() );
      } else {
         trk_index()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.trk_n.IsAvailable() ) {
         trk_n()->push_back( el.trk_n() );
      } else {
         trk_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trk_weight.IsAvailable() ) {
         trk_weight()->push_back( el.trk_weight() );
      } else {
         trk_weight()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.type.IsAvailable() ) {
         type()->push_back( el.type() );
      } else {
         type()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.x.IsAvailable() ) {
         x()->push_back( el.x() );
      } else {
         x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.y.IsAvailable() ) {
         y()->push_back( el.y() );
      } else {
         y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.z.IsAvailable() ) {
         z()->push_back( el.z() );
      } else {
         z()->push_back( std::numeric_limits< float >::min() );
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
   PrimaryVertexD3PDObjectElement& PrimaryVertexD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new PrimaryVertexD3PDObjectElement( fProxies.size(), *this ) );
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
   const PrimaryVertexD3PDObjectElement& PrimaryVertexD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new PrimaryVertexD3PDObjectElement( fProxies.size(), *this ) );
      }
      return *fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   PrimaryVertexD3PDObject& PrimaryVertexD3PDObject::operator+=( const PrimaryVertexD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
