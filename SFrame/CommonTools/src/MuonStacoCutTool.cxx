#include "../include/MuonStacoCutTool.h"

#include <iomanip> // setw
#include <TSystem.h> // gSystem->Getenv("PWD")

const float GeV = 1000.0;

//____________________________________________________________________________         
MuonStacoCutTool::MuonStacoCutTool(SCycleBase* parent, const char* name)
    :
        ToolBase(parent, name)
{
    DeclareProperty("require_combined", c_require_combined = false);
    // kinematic cuts
    DeclareProperty("min_pt", c_min_pt = 0.);
    DeclareProperty("max_eta", c_max_eta = 9e9);

}

//____________________________________________________________________________
void MuonStacoCutTool::BeginCycle( ) throw( SError )
{

}

//____________________________________________________________________________
void MuonStacoCutTool::BeginInputData(const SInputData& ) throw( SError )
{

}

//____________________________________________________________________________
void MuonStacoCutTool::EndCycle( ) throw( SError )
{

}

//____________________________________________________________________________         
bool MuonStacoCutTool::IsPassedCombined( const MuonStaco& p )
{
    if (c_require_combined && !p.isCombinedMuon()) return false;
    return true;
}

//____________________________________________________________________________         
bool MuonStacoCutTool::IsPassedPt( const MuonStaco& p )
{
    if (p.tlv.Pt() < c_min_pt*GeV) return false;
    return true;
}

//____________________________________________________________________________         
bool MuonStacoCutTool::IsPassedEta( const MuonStaco& p )
{
    if (fabs(p.tlv.Eta()) > c_max_eta) return false;
    return true;
}
