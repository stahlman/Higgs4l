#include "../include/Muon.h"

#include <cmath>

ClassImp(Muon)

//______________________________________________________________________________
Muon::Muon(const ParticleElement<D3PDReader::MuonD3PDObjectElement>& p, int index)
    :   ParticleElement<D3PDReader::MuonD3PDObjectElement>(p,index,false),
	m_pt(0),
	m_id_pt(0),
	m_ms_pt(0),
	m_me_pt(0),
	m_d0(0),
	m_sigma_d0(0),
	m_z0(0),
	m_cov_qoverp_exPV(0),
	m_cov_d0_qoverp_exPV(0),
	m_cov_z0_qoverp_exPV(0),
	m_cov_phi_qoverp_exPV(0),
	m_cov_theta_qoverp_exPV(0)

{

  m_tlv = new TLorentzVector(0,0,0,0);
  m_tlv->SetPtEtaPhiM(Pt(), eta(), phi(), m());
  
  return;
}


//______________________________________________________________________________
double Muon::ptcone(int cone_size) {

    if (cone_size == 20)      return ptcone20();
    else if (cone_size == 30) return ptcone30();
    else if (cone_size == 40) return ptcone40();
    else   std::cout << "Electron::ERROR: Unknown cone size: "<< cone_size << std::endl;
    
    return 0;
}



//______________________________________________________________________________
double Muon::etcone(int cone_size) {

    if (cone_size == 20)      return etcone20();
    else if (cone_size == 30) return etcone30();
    else if (cone_size == 40) return etcone40();
    else std::cout << "Electron::ERROR: Unknown cone size: "<< cone_size << std::endl;
        
    return 0;    
    
}


//______________________________________________________________________________
void Muon::FillTLV(TLorentzVector* mu_TLV) {
   mu_TLV->SetPtEtaPhiE(this->Pt(), this->eta(), this->phi(), this->m());
   return;
}



