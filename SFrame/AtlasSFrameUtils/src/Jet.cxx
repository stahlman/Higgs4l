#include "../include/Jet.h"

#include <cmath>

ClassImp(Jet)

//______________________________________________________________________________
Jet::Jet(const ParticleElement<D3PDReader::JetD3PDObjectElement>& p, int index)
    :   ParticleElement<D3PDReader::JetD3PDObjectElement>(p,index,false),
        m_fcloseby(0)
{

  //calibrated_vector.SetPtEtaPhiM(emscale_pt(), emscale_eta(), emscale_phi(), emscale_m());
  calibrated_vector.SetPtEtaPhiM(pt(),eta(),phi(),m());
  
  return;
}
