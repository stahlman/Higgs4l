#ifndef CommonTools_MuonCutTool_h
#define CommonTools_MuonCutTool_h

#include <vector>

#include "ToolBase.h"
#include "Muon.h"

class MuonCutTool : public ToolBase {

   public:
  
        MuonCutTool(SCycleBase* parent, const char* name = "MuonCut");
   
        void BeginCycle( ) throw( SError );
        void BeginInputData(const SInputData& ) throw( SError );   
        void EndCycle( ) throw( SError );   

        // basic author and kinematic, OQ cuts
        bool IsPassedCombined( const Muon& p );
        bool IsPassedPt( const Muon& p );
        bool IsPassedEta( const Muon& p );
    
    private:
        // configurables
        //--------------------------
        bool c_require_combined;
        // kinematic cuts
        double c_min_pt; // GeV
        double c_max_eta; 
      
};

#endif // CommonTools_MuonCutTool_h
