#include "../include/MuonCutTool.h"

#include <iomanip> // setw
#include <TSystem.h> // gSystem->Getenv("PWD")

const float GeV = 1000.0;

//____________________________________________________________________________         
MuonCutTool::MuonCutTool(SCycleBase* parent, const char* name)
    :
        ToolBase(parent, name)
{
    DeclareProperty("require_combined", c_require_combined = false);
    // kinematic cuts
    DeclareProperty("min_pt", c_min_pt = 0.);
    DeclareProperty("max_eta", c_max_eta = 9e9);

}

//____________________________________________________________________________
void MuonCutTool::BeginCycle( ) throw( SError )
{

}

//____________________________________________________________________________
void MuonCutTool::BeginInputData(const SInputData& ) throw( SError )
{

}

//____________________________________________________________________________
void MuonCutTool::EndCycle( ) throw( SError )
{

}

//____________________________________________________________________________         
bool MuonCutTool::IsPassedCombined( const Muon& p )
{
    if (c_require_combined && !p.isCombinedMuon()) return false;
    return true;
}

//____________________________________________________________________________         
bool MuonCutTool::IsPassedPt( const Muon& p )
{
    if (p.tlv.Pt() < c_min_pt*GeV) return false;
    return true;
}

//____________________________________________________________________________         
bool MuonCutTool::IsPassedEta( const Muon& p )
{
    if (fabs(p.tlv.Eta()) > c_max_eta) return false;
    return true;
}
