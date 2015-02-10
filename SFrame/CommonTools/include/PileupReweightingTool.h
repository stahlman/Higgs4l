#ifndef CommonTools_PileupReweightingTool_H
#define CommonTools_PileupReweightingTool_H

#include "EventInfoD3PDObject.h"
#include "MCEvtD3PDObject.h"

// TPileupReweighting
#include "PileupReweighting/TPileupReweighting.h"

//LocalIncludes
#include "ToolBase.h"

class PileupReweightingTool : public ToolBase
{
    public:
        PileupReweightingTool( SCycleBase* parent, const char* name = "PileupReweighting" );

	void BeginCycle() throw( SError );
        void BeginInputData( const SInputData& id ) throw( SError );
        void EndCycle();

        float GetPileupWeight(const D3PDReader::EventInfoD3PDObject& eventinfo, const D3PDReader::MCEvtD3PDObject& mcevt);

    private:
        // configurables
        //--------------------------

        bool c_do_pileup_reweighting;
        std::string c_data_file;
        std::string c_data_hist;
        std::string c_mc_file;
        std::string c_mc_hist;
        std::string c_var;
        bool c_generate_mc_hist;
	int c_channel;
	double c_scale_mu;
        std::string m_toolname;
	

        // private data
        //---------------------------
        Root::TPileupReweighting* m_pileup_reweighting;
        
}; // class PileupReweightingTool

#endif // CommonTools_PileupReweightingTool_H
