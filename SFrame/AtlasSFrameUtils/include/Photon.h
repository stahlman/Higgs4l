// file:        Photon.h
// author:      Dominick Olivito       <olivito@cern.ch>
// created:     March 2011
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Photon_h
#define AtlasSFrameUtils_Photon_h

#include "ParticleElement.h"
#include "ParticleElementBuilder.h"
#include "PhotonD3PDObject.h"
#include <vector>

class Photon : public ParticleElement<D3PDReader::PhotonD3PDObjectElement> {

 public:
  // main constructor
  Photon(const ParticleElement<D3PDReader::PhotonD3PDObjectElement>& p, int index = -1);

  void Set_cl_E(double p) { m_cl_e = p;};
  double cl_E_cal() { return (m_cl_e == 0 ? cl_E() : m_cl_e); };
  double cl_Et() { return (m_cl_e == 0 ? cl_E()/cosh(etas2()) : m_cl_e/cosh(etas2())); };

  void Set_topoiso20(double p) {m_topoiso20  = p;};
  double topoiso20() { return m_topoiso20; };

  void Set_topoiso40(double p) {m_topoiso40  = p;};
  double topoiso40() { return m_topoiso40; };

  
 private:

  double m_cl_e;
  double m_topoiso20;
  double m_topoiso40;  

  ClassDef(Photon, 1);

};






//typedef ParticleElement< D3PDReader::PhotonD3PDObjectElement > Photon;
//typedef ParticleElementBuilder::build< Photon, D3PDReader::PhotonD3PDObject > PhotonBuilder;

#endif // AtlasSFrameUtils_Photon_h
