#include "../include/JetCutTool.h"

#include <iomanip> // setw
#include <TSystem.h> // gSystem->Getenv("PWD")

const float GeV = 1000.0;

//____________________________________________________________________________         
JetCutTool::JetCutTool(SCycleBase* parent, const char* name)
    :
        ToolBase(parent, name)
{
    // kinematic cuts
    DeclareProperty("min_pt", c_min_pt = 0.);
    DeclareProperty("min_emscale_pt", c_min_emscale_pt = 0.);
    DeclareProperty("max_eta", c_max_eta = 9e9);

}

//____________________________________________________________________________
void JetCutTool::BeginCycle( ) throw( SError )
{

}

//____________________________________________________________________________
void JetCutTool::BeginInputData(const SInputData& ) throw( SError )
{

}

//____________________________________________________________________________
void JetCutTool::EndCycle( ) throw( SError )
{

}

//____________________________________________________________________________         
bool JetCutTool::IsPassedPt( const Jet& p )
{
    if ((c_min_pt > 1.) && (p.tlv.Pt() < c_min_pt*GeV)) return false;
    return true;
}

//____________________________________________________________________________         
bool JetCutTool::IsPassedEMScalePt( const Jet& p )
{
    if ((c_min_emscale_pt > 1.) && (p.emscale_pt() * p.EMJES() < c_min_emscale_pt*GeV)) return false;
    return true;
}

//____________________________________________________________________________         
bool JetCutTool::IsPassedEta( const Jet& p )
{
    if (fabs(p.emscale_eta()) > c_max_eta) return false;
    return true;
}
