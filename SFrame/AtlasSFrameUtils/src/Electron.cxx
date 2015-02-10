#include "../include/Electron.h"


#include <cmath>

//RootCore
#include "egammaAnalysisUtils/CaloIsoCorrection.h"


ClassImp(Electron)

//______________________________________________________________________________
Electron::Electron(const ParticleElement<D3PDReader::ElectronD3PDObjectElement>& p, int index)
    :   ParticleElement<D3PDReader::ElectronD3PDObjectElement>(p,index,false),
	m_calibrated_e(0),
	m_cl_e(0),
	m_d0(0),
	m_sigma_d0(0),
	m_z0(0),
	XBitMask(0)
{

  m_tlv = new TLorentzVector(0,0,0,0);
  m_tlv->SetPtEtaPhiE(cl_Et(), tracketa(), trackphi(), cl_E_cal());

  return;
}


//______________________________________________________________________________
double Electron::ptcone(int cone_size) {

    if (cone_size == 20)      return ptcone20();
    else if (cone_size == 30) return ptcone30();
    else if (cone_size == 40) return ptcone40();
    else   std::cout << "Electron::ERROR: Unknown cone size: "<< cone_size << std::endl;
    
    return 0;
}



//______________________________________________________________________________
double Electron::etcone(int cone_size, bool isMC) {

    double t_iso = 0;
    if (cone_size == 20)      t_iso = topoEtcone20();
    else if (cone_size == 30) t_iso = topoEtcone30();
    else if (cone_size == 40) t_iso = topoEtcone40();
    else  {
     std::cout << "Electron::ERROR: Unknown cone size: "<< cone_size << std::endl;
     return 0;    
    }
    
    float calo_iso = CaloIsoCorrection::GetPtEDCorrectedTopoIsolation(ED_median(),
                                                                      cl_E(),
                                                                      etas2(),
                                                                      etap(),
                                                                      cl_eta(),
                                                                      cone_size,
                                                                      isMC, // is_mc: true for MC, false for data 
                                                                      t_iso,
                                                                      false, // not used for electrons, can be set to false
                                                                      CaloIsoCorrection::ELECTRON, // CaloIsoCorrection::ELECTRON for electrons
    								      CaloIsoCorrection::REL17_2);
    return calo_iso;
}


//______________________________________________________________________________
void Electron::FillTLV(TLorentzVector* el_TLV) {
   el_TLV->SetPtEtaPhiE(this->cl_Et(), this->tracketa(), this->trackphi(), this->cl_E_cal());
   return;
}

