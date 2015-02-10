#ifndef CommonTools_JetCutTool_h
#define CommonTools_JetCutTool_h

#include <vector>

#include "ToolBase.h"
#include "Jet.h"

class JetCutTool : public ToolBase {

   public:
  
        JetCutTool(SCycleBase* parent, const char* name = "JetCut");
   
        void BeginCycle( ) throw( SError );
        void BeginInputData(const SInputData& ) throw( SError );   
        void EndCycle( ) throw( SError );   

        // basic author and kinematic, OQ cuts
        bool IsPassedPt( const Jet& p );
        bool IsPassedEMScalePt( const Jet& p );
        bool IsPassedEta( const Jet& p );
    
    private:
        // configurables
        //--------------------------
        // kinematic cuts
        double c_min_pt; // GeV
        double c_min_emscale_pt; // GeV
        double c_max_eta; 
      
};

#endif // CommonTools_JetCutTool_h
