#include "../include/Photon.h"

#include <cmath>

ClassImp(Photon)

//______________________________________________________________________________
Photon::Photon(const ParticleElement<D3PDReader::PhotonD3PDObjectElement>& p, int index)
    :   ParticleElement<D3PDReader::PhotonD3PDObjectElement>(p,index,false),
	m_cl_e(0)
{
  return;
}
