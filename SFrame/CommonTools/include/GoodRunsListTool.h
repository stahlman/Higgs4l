#ifndef CommonTools_GoodRunsListTool_H
#define CommonTools_GoodRunsListTool_H

# include "EventInfoD3PDObject.h"

//RootCore include(s):
#include "GoodRunsLists/TGoodRunsList.h"
#include "GoodRunsLists/TGoodRunsListReader.h"

//ROOT
#include "TH1F.h"

//LocalIncludes
#include "ToolBase.h"

class GoodRunsListTool : public ToolBase
{
    public:
        GoodRunsListTool( SCycleBase* parent, const char* name = "GoodRunsList" );

	void BeginCycle() throw( SError );
	//	void BeginMasterInputData( const SInputData& id ) throw( SError );
        void BeginInputData( const SInputData& id ) throw( SError );

        bool Select(const D3PDReader::EventInfoD3PDObject& eventinfo);

    private:
        // configurables
        //--------------------------

        std::string c_grl_xml;


        // private data
        //---------------------------
        Root::TGoodRunsList m_grl;
        
}; // class GoodRunsListTool

#endif // CommonTools_GoodRunsListTool_H
