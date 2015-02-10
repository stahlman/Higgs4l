// Local include(s):
#include "../CommonTools/include/OverlapTool.h"

// stdlib includes
#include <cmath>

// Root includes
#include "TVector3.h"

//______________________________________________________________________________
OverlapTool::OverlapTool( SCycleBase* parent, const char* name )
:   ToolBase( parent, name )
{
    SetLogName( name );

    DeclareProperty("dR", c_dR = 9e9 );
}
  
 //______________________________________________________________________________
// calculate dR between two objects given eta,phi
float OverlapTool::DeltaR( const float& eta1, const float& phi1, const float& eta2, const float& phi2 ) {

  // use TVector3 to get DeltaR
  TVector3 v1,v2;
  const float dummy = 1.0;
  v1.SetPtEtaPhi(dummy,eta1,phi1);
  v2.SetPtEtaPhi(dummy,eta2,phi2);
  return v1.DeltaR(v2);
  
}   
  
//______________________________________________________________________________
// cut on overlap between two objects, taking dR
bool OverlapTool::IsOverlap( const float& dR ) throw( SError ) {

  if (dR < c_dR) return true;
  return false;
}
  
