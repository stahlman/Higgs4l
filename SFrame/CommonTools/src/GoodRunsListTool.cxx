#include "../include/GoodRunsListTool.h"

#include <cmath> //std::min

const float GeV = 1000.0;

//____________________________________________________________________________
GoodRunsListTool::GoodRunsListTool( SCycleBase* parent, const char* name/*=GoodRunsList*/ )
    : ToolBase( parent, name )
{
  DeclareProperty("grl", c_grl_xml = "" );
}


//____________________________________________________________________________
void GoodRunsListTool::BeginCycle() throw(SError)
{
  if (! c_grl_xml.empty() ) {
    Root::TGoodRunsListReader reader(c_grl_xml);
    if(!reader.Interpret()) m_logger << FATAL << "GRL requested " << c_grl_xml << " But unable to Interpret!" << SLogger::endmsg;
    m_grl = reader.GetMergedGoodRunsList();
    // Give this TObject a name so that we can retrieve it on the worker nodes
    m_grl.SetName("GoodRunsList");
    AddConfigObject(&m_grl);
    
  }
}

//____________________________________________________________________________
void GoodRunsListTool::BeginInputData( const SInputData& id) throw( SError )
{

    //Retrieve GoodRunsList if c_do_grl and not mc
    if( is_data() && ! c_grl_xml.empty() )
    {
      m_grl = *( dynamic_cast<Root::TGoodRunsList*>(GetConfigObject("GoodRunsList")) );
    }
}


//____________________________________________________________________________
bool GoodRunsListTool::Select(const D3PDReader::EventInfoD3PDObject& eventinfo)
{
    if( is_data() && ! c_grl_xml.empty() )
    {
        bool passed_grl = m_grl.HasRunLumiBlock( eventinfo.RunNumber(), eventinfo.lbn() );
        if(passed_grl) 
        {
            m_logger << DEBUG << "Pass GRL " << passed_grl << " Run: " << eventinfo.RunNumber() << " LB: " << eventinfo.lbn() << SLogger::endmsg;
        }
        else 
        {
            m_logger << DEBUG << "Fail GRL " << passed_grl << " Run: " << eventinfo.RunNumber() << " LB: " << eventinfo.lbn() << SLogger::endmsg;
        }
        return passed_grl;
    }
    else
    {
        // Monte Carlo or no GRL
        return true;
    }
}

