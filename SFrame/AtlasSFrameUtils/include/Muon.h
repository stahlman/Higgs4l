// file:        Muon.h
// author:      Ryan Reece       <stahlman@cern.ch>
// created:     July 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Muon_h
#define AtlasSFrameUtils_Muon_h

#include "ParticleElement.h"
#include "ParticleElementBuilder.h"
#include "MuonD3PDObject.h"
#include <vector>


class Muon : public ParticleElement<D3PDReader::MuonD3PDObjectElement> {

 public:
  // main constructor
  Muon(const ParticleElement<D3PDReader::MuonD3PDObjectElement>& p, int index = -1);

  void Set_Pt(double pt) { m_pt = pt; m_tlv->SetPtEtaPhiM(pt, m_tlv->Eta(), m_tlv->Phi(), m_tlv->M());};
  double Pt() { return (m_pt == 0 ? pt() : m_pt); };
  
  void Set_id_Pt(double p) { m_id_pt = p;};
  double id_pt() { return 1/fabs(id_qoverp())*sin(id_theta()); };
  double id_Pt() { return (m_id_pt == 0 ? 1/fabs(id_qoverp())*sin(id_theta()) : m_id_pt); };
  
  double id_eta() { return -log(tan(id_theta()/2)); };

  void Set_ms_Pt(double p) { m_ms_pt = p;};
  double ms_pt() { return  1/fabs(ms_qoverp())*sin(ms_theta()); };
  double ms_Pt() { return (m_ms_pt == 0 ? 1/fabs(ms_qoverp())*sin(ms_theta()) : m_ms_pt); };

  void Set_me_Pt(double p) { m_me_pt = p;};
  double me_pt() { return  1/fabs(me_qoverp())*sin(me_theta()); };
  double me_Pt() { return (m_me_pt == 0 ? 1/fabs(me_qoverp())*sin(me_theta()) : m_me_pt); };

  void Set_D0(double d0) { m_d0 = d0;};
  double D0() { return (m_d0 == 0 ? trackd0pvunbiased() : m_d0); };

  void Set_sigma_D0(double sig_d0) { m_sigma_d0 = sig_d0;};
  double sigma_D0() { return (m_sigma_d0 == 0 ? tracksigd0pvunbiased() : m_sigma_d0); };

  void Set_Z0(double z0) { m_z0 = z0;};
  double Z0() { return (m_z0 == 0 ? trackz0pvunbiased() : m_z0); };
  
  void Set_cov_qoverp_exPV(double v) { m_cov_qoverp_exPV = v; };
  double cov_qoverp_exPV_cal() { return (m_cov_qoverp_exPV == 0 ? cov_qoverp_exPV() : m_cov_qoverp_exPV); };

  void Set_cov_d0_qoverp_exPV(double v) { m_cov_d0_qoverp_exPV = v; };
  double cov_d0_qoverp_exPV_cal() { return (m_cov_d0_qoverp_exPV == 0 ? cov_d0_qoverp_exPV() : m_cov_d0_qoverp_exPV); };

  void Set_cov_z0_qoverp_exPV(double v) { m_cov_z0_qoverp_exPV = v; };
  double cov_z0_qoverp_exPV_cal() { return (m_cov_z0_qoverp_exPV == 0 ? cov_z0_qoverp_exPV() : m_cov_z0_qoverp_exPV); };

  void Set_cov_phi_qoverp_exPV(double v) { m_cov_phi_qoverp_exPV = v; };
  double cov_phi_qoverp_exPV_cal() { return (m_cov_phi_qoverp_exPV == 0 ? cov_phi_qoverp_exPV() : m_cov_phi_qoverp_exPV); };

  void Set_cov_theta_qoverp_exPV(double v) { m_cov_theta_qoverp_exPV = v; };
  double cov_theta_qoverp_exPV_cal() { return (m_cov_theta_qoverp_exPV == 0 ? cov_theta_qoverp_exPV() : m_cov_theta_qoverp_exPV); };

  double D0Significance() { return fabs(D0())/sigma_D0(); };
  
  double ptcone(int cone_size);
  double etcone(int cone_size);

  bool isCaloMuon() { return (author() == 16); };  
  
  void SetXBitMask(int bitmask) { XBitMask = bitmask; };
  int  GetXBitMask() { return XBitMask; };

  void FillTLV(TLorentzVector * mu_TLV);
  TLorentzVector* TLV() { return m_tlv; };
  
 private:

  TLorentzVector * m_tlv;

  double m_pt;
  double m_id_pt;
  double m_ms_pt;
  double m_me_pt;

  double m_d0;
  double m_sigma_d0;
  double m_z0;

  double m_cov_qoverp_exPV;
  double m_cov_d0_qoverp_exPV;
  double m_cov_z0_qoverp_exPV;
  double m_cov_phi_qoverp_exPV;
  double m_cov_theta_qoverp_exPV;

  int XBitMask;

  ClassDef(Muon, 1);

};



//typedef ParticleElement< D3PDReader::MuonD3PDObjectElement > Muon;
//typedef ParticleElementBuilder::build< Muon, D3PDReader::MuonD3PDObject > MuonBuilder;

#endif // AtlasSFrameUtils_Muon_h
