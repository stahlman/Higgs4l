// file:        Electron.h
// author:      Dominick Olivito       <olivito@cern.ch>
// created:     March 2011
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Electron_h
#define AtlasSFrameUtils_Electron_h

#include "ParticleElement.h"
#include "ElectronD3PDObject.h"
#include <vector>

class Electron : public ParticleElement<D3PDReader::ElectronD3PDObjectElement> {

 public:
  // main constructor
  Electron(const ParticleElement<D3PDReader::ElectronD3PDObjectElement>& p, int index = -1);
  
  //fully calibrated energy: calibration + e/p combo
  void Set_cl_E(double p) { m_cl_e = p;  m_tlv->SetPtEtaPhiM(cl_Et(), tracketa(), trackphi(), 0.511);};
  double cl_E_cal() { return (m_cl_e == 0 ? cl_E() : m_cl_e); };
  double cl_Et() { return (m_cl_e == 0 ? cl_E()/cosh(tracketa()) : m_cl_e/cosh(tracketa())); };

  //calibration only
  void Set_calibrated_E(double p) { m_calibrated_e = p;};
  double calibrated_E() { return m_calibrated_e; };
  double calibrated_Et() { return m_calibrated_e/cosh(tracketa()); };

  void Set_D0(double d0) { m_d0 = d0;};
  double D0() { return (m_d0 == 0 ? trackd0pvunbiased() : m_d0); };

  void Set_sigma_D0(double sig_d0) { m_sigma_d0 = sig_d0;};
  double sigma_D0() { return (m_sigma_d0 == 0 ? tracksigd0pvunbiased() : m_sigma_d0); };

  void Set_Z0(double z0) { m_z0 = z0;};
  double Z0() { return (m_z0 == 0 ? trackz0pvunbiased() : m_z0); };

  void Set_E_resolution(double er) { m_E_resolution = er;};
  double E_resolution() { return m_E_resolution; };

  double D0Significance() { return fabs(D0())/sigma_D0(); };

  double ptcone(int cone_size);
  double etcone(int cone_size, bool isMC);
    
  double DEmaxs1() { return ((emaxs1()+Emax2()) == 0.) ? 0. :(emaxs1()-Emax2())/(emaxs1()+Emax2()); };
  
  void SetXBitMask(int bitmask) { XBitMask = bitmask; };
  int  GetXBitMask() { return XBitMask; };

  void FillTLV(TLorentzVector * el_TLV);
  TLorentzVector* TLV() { return m_tlv; };
  
 private:

  TLorentzVector * m_tlv;
  
  double m_calibrated_e; //calibrated energy, no e-p combo
  double m_cl_e;  //fully calibrated energy
  double m_d0;
  double m_sigma_d0;
  double m_z0;
  double m_E_resolution;
  
  int XBitMask;
  
  ClassDef(Electron, 1);

};



//typedef ParticleElement< D3PDReader::ElectronD3PDObjectElement > Electron;
//typedef ParticleElementBuilder::build< Electron, D3PDReader::ElectronD3PDObject > ElectronBuilder;

#endif // AtlasSFrameUtils_Electron_h
