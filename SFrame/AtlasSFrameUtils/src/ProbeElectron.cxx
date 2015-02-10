#include "../include/ProbeElectron.h"

#include <cmath>

ClassImp(ProbeElectron)

//______________________________________________________________________________

  ProbeElectron::ProbeElectron(const ParticleElement<D3PDReader::ElectronD3PDObjectElement>& p, int index) 

    :   Electron( p,index),
	m_tag_index(0),
	m_tag_vecindex(0),
	m_mass_tp(0),
	m_mass_tpg(0),
	m_deltaR_tp(0),
	m_deltaR_tg(0),
	m_deltaR_pg(0)
{
  return;
}
