#include "../include/PileupReweightingTool.h"

#include <cmath> //std::min

const float GeV = 1000.0;

//____________________________________________________________________________
PileupReweightingTool::PileupReweightingTool( SCycleBase* parent, const char* name/*=PileupReweighting*/ )
    : ToolBase( parent, name )
{
    DeclareProperty("do_pileup_reweighting", c_do_pileup_reweighting = false );
    DeclareProperty("data_file", c_data_file = "" );
    DeclareProperty("data_hist", c_data_hist = "avgintperbx" );
    DeclareProperty("mc_file", c_mc_file = "mu_mc10b.root" );
    DeclareProperty("mc_hist", c_mc_hist = "mu_mc10b" );
    DeclareProperty("var", c_var = "lbn" );
    DeclareProperty("generate_mc_hist", c_generate_mc_hist = false );
    DeclareProperty("default_channel", c_channel = 0 );
    DeclareProperty("scale_mu", c_scale_mu = 1.0 );
   
    m_toolname = name;
    m_toolname.append("_TPileupReweighting");
}


//____________________________________________________________________________
void PileupReweightingTool::BeginCycle() throw(SError)
{
    if (c_do_pileup_reweighting || c_generate_mc_hist) {
        m_pileup_reweighting = new Root::TPileupReweighting(m_toolname.c_str());
        if (c_do_pileup_reweighting) {
            // allow unrepresented data for now
            // and merge MC run numbers for mc11a
            m_pileup_reweighting->SetDataScaleFactors(c_scale_mu);
	    m_pileup_reweighting->MergeMCRunNumbers(185649,185761); //keep this?
            m_pileup_reweighting->SetUnrepresentedDataAction(2);
	    
            //int isGood = m_pileup_reweighting->initialize( c_data_file,
            //                                              c_data_hist,
            //                                              c_mc_file,
            //                                              c_mc_hist );
	    m_pileup_reweighting->AddConfigFile(c_mc_file);
	    m_pileup_reweighting->AddLumiCalcFile(c_data_file);
            //m_pileup_reweighting->AddMCDistribution(c_mc_file,"MCPileupReweighting");
            //m_pileup_reweighting->AddDataDistribution(c_data_file,"LumiMetaData");
                            
            m_pileup_reweighting->SetDefaultChannel(c_channel);
	    
	    m_pileup_reweighting->initialize();
            
	    // 0 means good
            //if (isGood) {
            //    m_logger << FATAL  << "Problem initializing TPileupReweighting tool" << SLogger::endmsg;
            //    c_do_pileup_reweighting = false;
            //} else {
            AddConfigObject(m_pileup_reweighting);
	    //}
    
        } else if (c_generate_mc_hist) {
            m_pileup_reweighting->AddPeriod(180164, 177986,180481); //associates mc runnumber 180164 with data period 177986 to 180481 (period B-D)
            m_pileup_reweighting->AddPeriod(183003, 180614,184169); //period E-H
            m_pileup_reweighting->AddPeriod(185649, 185353,186934); //period I-K1. For I-K you would change the last number to 187815
            m_pileup_reweighting->AddPeriod(185761, 186935,999999); //everything after K1. If you changed the previous line to I-K, change middle number of this line to 187816
            int isGood = m_pileup_reweighting->initialize();
            
            // 0 means good
            if (isGood) {
                m_logger << FATAL  << "Problem initializing TPileupReweighting tool" << SLogger::endmsg;
                c_do_pileup_reweighting = false;
            } else {
                AddConfigObject(m_pileup_reweighting);
            }
        }
    } // if (c_do_pileup_reweighting || c_generate_mc_hist)
}

//____________________________________________________________________________
void PileupReweightingTool::BeginInputData( const SInputData& id) throw( SError )
{
     if (c_do_pileup_reweighting || c_generate_mc_hist) {
         m_pileup_reweighting = dynamic_cast<Root::TPileupReweighting*>(GetConfigObject(m_toolname.c_str()));
     }
}


//____________________________________________________________________________
float PileupReweightingTool::GetPileupWeight(const D3PDReader::EventInfoD3PDObject& eventinfo, const D3PDReader::MCEvtD3PDObject& mcevt)
{
    float pileupEventWeight = 1.0;
    if ((c_do_pileup_reweighting || c_generate_mc_hist) && !is_data()) {
        float mu = 0.0;
        if (c_var == "lbn") mu = eventinfo.lbn();
        else if (c_var == "averageIntPerXing") mu = eventinfo.averageIntPerXing();
        else if (c_var == "actualIntPerXing") mu = eventinfo.actualIntPerXing();
        //pileupEventWeight = m_pileup_reweighting->getPileupWeight( mu, eventinfo.RunNumber(), mcevt.mc_channel_number() );
	pileupEventWeight = m_pileup_reweighting->GetCombinedWeight( eventinfo.RunNumber(), mcevt.mc_channel_number(), mu );
        if (pileupEventWeight < 0) pileupEventWeight = 0.;
    }
    return pileupEventWeight;
}

//____________________________________________________________________________
void PileupReweightingTool::EndCycle()
{
    
    if (c_do_pileup_reweighting || c_generate_mc_hist) {
        // next line causes crashes in LOCAL mode, not sure if this would crash in PROOF ...
        //m_pileup_reweighting = dynamic_cast<Root::TPileupReweighting*>(GetConfigObject("TPileupReweighting"));
        if (c_generate_mc_hist && !is_data()) {
            m_pileup_reweighting->WriteToFile();
        }
        delete m_pileup_reweighting;
    }
}

