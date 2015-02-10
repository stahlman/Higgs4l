#ifndef CommonTools_MuonStacoCutTool_h
#define CommonTools_MuonStacoCutTool_h

#include <vector>

#include "ToolBase.h"
#include "MuonStaco.h"

class MuonStacoCutTool : public ToolBase {

   public:
  
        MuonStacoCutTool(SCycleBase* parent, const char* name = "MuonStacoCut");
   
        void BeginCycle( ) throw( SError );
        void BeginInputData(const SInputData& ) throw( SError );   
        void EndCycle( ) throw( SError );   

        // basic author and kinematic, OQ cuts
        bool IsPassedCombined( const MuonStaco& p );
        bool IsPassedPt( const MuonStaco& p );
        bool IsPassedEta( const MuonStaco& p );
    
    private:
        // configurables
        //--------------------------
        bool c_require_combined;
        // kinematic cuts
        double c_min_pt; // GeV
        double c_max_eta; 
      
};

#endif // CommonTools_MuonStacoCutTool_h
