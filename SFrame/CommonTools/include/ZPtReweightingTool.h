#ifndef CommonTools_ZPtReweightingTool_H
#define CommonTools_ZPtReweightingTool_H

#include "TruthParticleD3PDObject.h"

//AtlasSFrameUtils
#include "ToolBase.h"
#include "TruthParticle.h"

//Common Tools
#include "PdtPdg.h"
#include "BosonPtReweightingTool.h"


class ZPtReweightingTool : public ToolBase
{
    public:
        ZPtReweightingTool( SCycleBase* parent, const char* name = "PileupReweighting" );

	void BeginCycle() throw( SError );
        void BeginInputData( const SInputData& id ) throw( SError );
        void EndCycle();

        float GetZPtWeight(const D3PDReader::TruthParticleD3PDObject& m_truth_d3pdobject);

    private:
        // configurables
        //--------------------------

        bool c_do_zpt_reweighting;
        std::string c_file;
        std::string m_toolname;
	

        // private data
        //---------------------------
        BosonPtReweightingTool* m_zpt_reweighting;
        
}; // class ZPtReweightingTool

#endif // CommonTools_ZPtReweightingTool_H
