// Dear emacs, this is -*- c++ -*-
// $Id: D3PDObjectBase.h 15916 2012-06-17 09:16:37Z stahlman $
#ifndef D3PDREADER_D3PDOBJECTBASE_H
#define D3PDREADER_D3PDOBJECTBASE_H

// ROOT include(s):
#include <TObject.h>
#include <TString.h>

// Local include(s):
#include "D3PDReadStats.h"

// Forward declaration(s):
class TTree;

namespace D3PDReader {

   /**
    *  @short Common base class for all main D3PDReader classes
    *
    *         To make the classes a bit easier to handle in "smart" code
    *         they inherit from a common base that defines all of their
    *         common features.
    *
    * @author Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
    *
    * $Revision: 15916 $
    * $Date: 2012-06-17 05:16:37 -0400 (Sun, 17 Jun 2012) $
    */
   class D3PDObjectBase : public ::TObject {

   public:
      /// Default constructor
      D3PDObjectBase() : ::TObject() {}

      /// Get the currently configured prefix value
      virtual const char* GetPrefix() const = 0;
      /// Set the prefix for the variables
      virtual void SetPrefix( const char* prefix ) = 0;

      /// Connect the object to an input TTree
      virtual void ReadFrom( ::TTree* tree ) = 0;
      /// Connect the object to an output TTree
      virtual void WriteTo( ::TTree* tree ) = 0;

      /// Turn (selected) branches either on or off
      virtual void SetActive( ::Bool_t active = kTRUE,
                              const ::TString& pattern = ".*" ) = 0;

      /// Read in all the variables that we need to write out as well
      virtual void ReadAllActive() = 0;

      /// Get the D3PD reading statistics
      virtual D3PDReadStats GetStatistics() const = 0;

      ClassDef( D3PDObjectBase, 0 )

   }; // class D3PDObjectBase

} // namespace D3PDReader

#endif // D3PDREADER_D3PDOBJECTBASE_H
