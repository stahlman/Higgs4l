#ifndef OverlapTool_H
#define OverlapTool_H

// STL include(s):
#include <vector>
#include <set>

//LocalIncludes
#include "ToolBase.h"

class OverlapTool : public ToolBase 
{
    public:
        OverlapTool( SCycleBase* parent, const char* name = "Overlap" );

        // calculate dR for two objects
        float DeltaR( const float& eta1, const float& phi1, const float& eta2, const float& phi2 );
        // check dR for overlap
        bool IsOverlap( const float& dR ) throw( SError );

    private:
        // configurables
        //--------------------------
        double  c_dR;

}; // class OverlapTool


#endif // OverlapTool_H
