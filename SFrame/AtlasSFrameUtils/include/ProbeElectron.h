// file:        ProbeElectron.h
// author:      Sarah Heim       <sheim@cern.ch>
// created:     September 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_ProbeElectron_h
#define AtlasSFrameUtils_ProbeElectron_h

#include "ParticleElement.h"
#include "ElectronD3PDObject.h"
#include "Electron.h"
#include <vector>



class ProbeElectron : public Electron {

 public:
  // main constructor
  ProbeElectron(const ParticleElement<D3PDReader::ElectronD3PDObjectElement>& p, int index = -1);

  void Set_tag_index(int index) { m_tag_index = index;};
  double GetTagIndex() { return m_tag_index; };

  void Set_tag_vecindex(int index) { m_tag_vecindex = index;};
  double GetTagVecIndex() { return m_tag_vecindex; };

  void Set_photon_index(int index) { m_photon_index = index;};
  double GetPhotonIndex() { return m_photon_index; };

  void Set_photon_vecindex(int index) { m_photon_vecindex = index;};
  double GetPhotonVecIndex() { return m_photon_vecindex; };

  //Charge
  void Set_OS_tp(int isOS) { m_OS_tp = isOS;};
  int GetOSTP() { return m_OS_tp; };



  //TP Mass
  void Set_mass_tp(double mass) { m_mass_tp = mass;};
  double GetMassTP() { return m_mass_tp; };

  //TPg Mass
  void Set_mass_tpg(double mass) { m_mass_tpg = mass;};
  double GetMassTPG() { return m_mass_tpg; };

  //TPg Mass
  void Set_mass_tg(double mass) { m_mass_tg = mass;};
  double GetMassTG() { return m_mass_tg; };


  //deltaR TP
  void Set_deltaR_tp(double deltaR) { m_deltaR_tp = deltaR;};
  double GetDeltaRTP() { return m_deltaR_tp; };

  //deltaR Tg
  void Set_deltaR_tg(double deltaR) { m_deltaR_tg = deltaR;};
  double GetDeltaRTG() { return m_deltaR_tg; };

  //deltaRPg
  void Set_deltaR_pg(double deltaR) { m_deltaR_pg = deltaR;};
  double GetDeltaRPG() { return m_deltaR_pg; };

  //passML
  void Set_passML(int pass) { m_passML = pass;};
  int GetPassML() { return m_passML; };

  //passML
  void Set_passMedium(int pass) { m_passMedium = pass;};
  int GetPassMedium() { return m_passMedium; };

  //passML
  void Set_passTight(int pass) { m_passTight = pass;};
  int GetPassTight() { return m_passTight; };

  //tag pass Tight
  void Set_tag_passTight(int pass) { m_tag_passTight = pass;};
  int GetTagPassTight() { return m_tag_passTight; };




 private:

  //double m_cl_e;
  int m_tag_index;
  int m_tag_vecindex;
  int m_photon_index;
  int m_photon_vecindex;


  double m_mass_tp;
  double m_mass_tpg;
  double m_mass_tg;
  double m_deltaR_tp;
  double m_deltaR_tg;
  double m_deltaR_pg;

  int m_OS_tp;


  //numerators
  int m_passML;
  int m_passMedium;
  int m_passTight;

  //tag conditions
  int m_tag_passTight;

  

  ClassDef(ProbeElectron, 1);

};


#endif // AtlasSFrameUtils_ProbeElectron_h
