#include "../include/CleaningTool.h"

#include <cmath> //std::min

const float GeV = 1000.0;

//____________________________________________________________________________
CleaningTool::CleaningTool( SCycleBase* parent, const char* name )
    : ToolBase( parent, name ),
      m_tightness(JetID::LooseBad)
{
    SetLogName( name );

    DeclareProperty("do_jet_cleaning", c_do_jet_cleaning = false);
    DeclareProperty("min_pt", c_min_pt = 0.0 );
    DeclareProperty("tightness", c_tightness_str = "Loose" );
    DeclareProperty("do_lar_error_cleaning", c_do_lar_error_cleaning = false);

}

//______________________________________________________________________________
void CleaningTool::BeginInputData(const SInputData&) throw(SError){ 

  if (c_tightness_str == "Loose")
    {
      m_tightness = JetID::LooseBad;
    }
  else if (c_tightness_str == "Medium")
    {
      m_tightness = JetID::MediumBad;
    }
  else if (c_tightness_str == "Tight")
    {
      m_tightness = JetID::TightBad;
    }
  else
    {
      m_logger << ERROR << " Tightness not correctly defined, set as: " << c_tightness_str <<  SLogger::endmsg;
    }
  
}

//____________________________________________________________________________
bool CleaningTool::IsPassedBad(const Jet& p)
{
  if (!c_do_jet_cleaning) return true;
  
  if ((p.emscale_pt() * p.EMJES()) < c_min_pt*GeV) return true;
  
  return !JetID::isBadJet(m_tightness,
      p.emfrac(),
      p.hecf(),
      p.LArQuality(),
      p.HECQuality(),
      p.Timing(),
      p.sumPtTrk(),
      p.emscale_eta(),
      p.emscale_pt()*p.EMJES(),
      p.fracSamplingMax(),
      p.NegativeE() );
}

//____________________________________________________________________________
bool CleaningTool::IsPassedLarError(const unsigned int& larError)
{
  // larError == 1 corresponds to noise burst
  // larError == 2 corresponds to corrupted data
//  if (c_do_lar_error_cleaning && ((larError == 1) || (larError == 2))) return false;
  if (c_do_lar_error_cleaning && (larError >= 1)) return false;
  return true;
}

