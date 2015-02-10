// $Id: PhotonSelector.cxx 18120 2012-09-16 14:35:37Z sheim $

// Local include(s):
#include "../include/PhotonSelector.h"
#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Electron.h"
#include "ProbeElectron.h"
#include "Photon.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "EnergyRescalerTool.h"
#include "IDTool.h"

#include "egammaAnalysisUtils/CaloIsoCorrection.h"

const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( PhotonSelector );

PhotonSelector::PhotonSelector(SCycleBase* parent, const char* name)
  : ToolBase( parent, name ),
    cf_preselect(0),
    cf_author(0),	 
    cf_photonid(0),
    cf_eta(0),	
    cf_et(0),	
    cf_oq(0),
    cf_iso(0)
{

  DeclareProperty( "DoSmear", m_doSmear=1 );
  DeclareProperty( "DoCalibration", m_doCalibration=1 );
  DeclareProperty( "VetoCrack", m_vetoCrack=1 );
  DeclareProperty( "DoTruthMatchPhoton", m_doTruthMatchPhoton=0 );
  
  
  return;
  
}

PhotonSelector::~PhotonSelector() {


 return;

}


void PhotonSelector::BeginMasterInputData( const SInputData& ) throw( SError ){

  
  return;
  
}


void PhotonSelector::EndMasterInputData( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                  Zgamma Photon Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of photons passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Photons Before Cuts..........:"<<cf_preselect   <<SLogger::endmsg;
  m_logger << ALWAYS <<"Photons After Author.........:"<<cf_author      <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)"  <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Photons After Photon ID....:"<<cf_photonid  <<" ("<<((double)cf_photonid)/((double)cf_author)*100 <<"%)"  <<" ("<<((double)cf_photonid)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Photons After Eta............:"<<cf_eta	        <<" ("<<((double)cf_eta)/((double)cf_photonid)*100 <<"%)"	 <<" ("<<((double)cf_eta)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Photons After Et.............:"<<cf_et          <<" ("<<((double)cf_et)/((double)cf_eta)*100 <<"%)" <<" ("<<((double)cf_et)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Photons After Object Quality.:"<<cf_oq	        <<" ("<<((double)cf_oq)/((double)cf_et)*100 <<"%)" <<" ("<<((double)cf_oq)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Photons After Isolation......:"<<cf_iso	        <<" ("<<((double)cf_iso)/((double)cf_et)*100 <<"%)" <<" ("<<((double)cf_iso)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;


  return;

}


void PhotonSelector::SelectPhotons( std::vector<Photon*> &sel_photons, const D3PDReader::PhotonD3PDObject* m_photon_d3pdobject, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject) {

  //return; 

  //electron selection
  //m_logger << ::DEBUG << "Photon Selection " << SLogger::endmsg;
 


  std::vector<Photon> all_phs;  
  ParticleElementBuilder::build( all_phs, (*m_photon_d3pdobject) );

  m_logger << ::DEBUG << "Number of photons in event: " << all_phs.size() << SLogger::endmsg;

  for(std::vector<Photon>::iterator itr = all_phs.begin(); itr != all_phs.end(); ++itr) { 
    
    //truthmatch
    //if(m_doTruthMatchPhoton  && !(fabs((*itr).truth_type()) == 22 && (*itr).truth_matched() && fabs((*itr).truth_mothertype()) == 23)){// or 0 or what?
    if(!is_data() && m_doTruthMatchPhoton  && !(fabs((*itr).truth_type()) == 22 && (*itr).truth_matched())) {
      continue;
    }
    if(!is_data()) m_logger << ::DEBUG << "truthtype: " << fabs((*itr).truth_type()) << ", truthmatched: " <<(*itr).truth_matched() << ", truthmothertype: " << (*itr).truth_mothertype()<< SLogger::endmsg;
    cf_preselect++;

    //author //no photon author...
    m_logger << ::DEBUG << "Author cut" << SLogger::endmsg;
    //if(!((*itr).author() == 1 || (*itr).author() == 3)) continue;
    cf_author++;

    //ID ///***
    m_logger << ::DEBUG << "ID cut" << SLogger::endmsg;
    if (m_doSmear || m_doCalibration) {
       GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
       energy_rescaler->ApplyEnergyRescaler( (*itr), m_event_d3pdobject->EventNumber(), m_event_d3pdobject->RunNumber());
    }
   
    //ID
    GET_TOOL(id, IDTool, "IDTool");
    if(!(id->passPID((*itr),"tight"))) {
	 m_logger << ::DEBUG << "ID failed" << SLogger::endmsg;
        continue;
    }
    //if isConv
    //if((*itr).isConv()) continue;

    if(((*itr).isEM()& 0x800000) !=0 ) continue; //Ambiguity resolution
    cf_photonid++;
    
    //eta cuts
    m_logger << ::DEBUG << "Eta cut" << SLogger::endmsg;
    if(!(fabs((*itr).etas2()) < 2.37)) continue;
    if(fabs((*itr).etas2())<1.52 && fabs((*itr).etas2())>1.37) continue;
    cf_eta++;

    //et cut 25 GeV
    //need to do scaling/is conversion etc.//***
    if(!((*itr).cl_pt() > 10000.)) continue;
    //if(!((*itr).cl_Et() > 7000.)) continue; 
    cf_et++;

    //object quality
    m_logger << ::DEBUG << "OQ cut" << SLogger::endmsg;
    if(!(((*itr).OQ()&34214) == 0)) continue;
    if (((*itr).OQ()&134217728) &&
	((*itr).reta() > 0.98 || (*itr).rphi() > 1.0 || ((*itr).OQ()&67108864) ))continue;
    cf_oq++;

    //isolation
    float calo_iso_20 = CaloIsoCorrection::GetPtEDCorrectedTopoIsolation((*itr).ED_median(),
                                                                      (*itr).cl_E(),
                                                                      (*itr).etas2(),
                                                                      (*itr).etap(),
                                                                      (*itr).cl_eta(),
                                                                      20,
                                                                      !is_data(), // is_mc: true for MC, false for data 
                                                                      (*itr).topoEtcone20(),
                                                                      (*itr).isConv(), // not used for electrons, can be set to false
                                                                      CaloIsoCorrection::PHOTON,
								      CaloIsoCorrection::REL17
								      ); // CaloIsoCorrection::PHOTON for photons

    
    if(calo_iso_20 > 4000) continue; //good value?
    cf_iso++;

    (*itr).Set_topoiso20(calo_iso_20);
    float calo_iso_40 = CaloIsoCorrection::GetPtEDCorrectedTopoIsolation((*itr).ED_median(),
                                                                      (*itr).cl_E(),
                                                                      (*itr).etas2(),
                                                                      (*itr).etap(),
                                                                      (*itr).cl_eta(),
                                                                      40,
                                                                      !is_data(), // is_mc: true for MC, false for data 
                                                                      (*itr).topoEtcone40(),
                                                                      (*itr).isConv(), // not used for electrons, can be set to false
                                                                      CaloIsoCorrection::PHOTON,
                                                                      CaloIsoCorrection::REL17
                                                                      ); // CaloIsoCorrection::PHOTON for photons
 
   (*itr).Set_topoiso40(calo_iso_40);

   //if(calo_iso_40 > 4000) continue; //good value?
   //cf_iso++;



    sel_photons.push_back( new Photon(*itr));

  }
  
  m_logger << ::DEBUG << "Number of selected photons in event: " << sel_photons.size() << SLogger::endmsg;

				    
  return;
}

//void PhotonSelector::RemoveElectronPhotonOverlap(std::vector<Photon*> &sel_photons,std::vector<Electron*> &sel_electrons, double Radius) {     
template <class T> void PhotonSelector::RemoveElectronPhotonOverlap(std::vector<Photon*> &sel_photons,std::vector<T*> &sel_electrons, double Radius) {     
 
  if(sel_photons.size() == 0) return;

  double eta_ph = 0;
  double phi_ph = 0;
  double eta_el = 0;
  double phi_el = 0;
  double deltaR = 0;

  m_logger << ::DEBUG << "in overlap tool, ph size is " << sel_photons.size() << SLogger::endmsg;
  
  for(unsigned int iel = 0; iel < sel_electrons.size(); ++iel) { 

    m_logger << ::DEBUG << "el "<< iel <<", ph size is " << sel_photons.size() << SLogger::endmsg;
    for(int iph = sel_photons.size()-1; iph >= 0; --iph) { 

      m_logger << ::DEBUG << "ph "<< iph <<", ph size is " << sel_photons.size() << SLogger::endmsg;

      eta_ph = sel_photons[iph]->etas2();
      phi_ph = sel_photons[iph]->phi();
      eta_el = sel_electrons[iel]->tracketa();
      phi_el = sel_electrons[iel]->trackphi();
      m_logger << ::DEBUG << "eta_ph: " << eta_ph << ", eta_el: " << eta_el << SLogger::endmsg;

      deltaR = DeltaR(eta_ph, phi_ph, eta_el, phi_el);

      if(deltaR < Radius)  {
	sel_photons.erase(sel_photons.begin()+iph); 
	m_logger << ::DEBUG << "erased" << SLogger::endmsg;
      }
      m_logger << ::DEBUG << "deltaR was " <<deltaR << SLogger::endmsg;
      
    }//end loop over photons
  }//end loop over electrons


  m_logger << ::DEBUG << "done with overlap tool" << SLogger::endmsg;
  return;
}

//to help compiler...
template void PhotonSelector::RemoveElectronPhotonOverlap<Electron>(std::vector<Photon*> &sel_photons,std::vector<Electron*> &sel_electrons, double Radius);
template void PhotonSelector::RemoveElectronPhotonOverlap<ProbeElectron>(std::vector<Photon*> &sel_photons,std::vector<ProbeElectron*> &sel_electrons, double Radius);


double PhotonSelector::DeltaR(double eta1, double phi1, double eta2, double phi2) {      
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  double delta_eta = eta1 - eta2;  
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}
