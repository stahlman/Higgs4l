// $Id: FsrSelector.cxx 26117 2014-02-04 21:06:31Z stahlman $

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Electron.h"
#include "Muon.h"

//Common Tools
#include "EnergyRescalerTool.h"

//RootCore
#include "egammaAnalysisUtils/FsrPhotons.h"
#include "egammaAnalysisUtils/CaloIsoCorrection.h"

// Local include(s):
#include "../include/FsrSelector.h"


ClassImp( FsrSelector );

FsrSelector::FsrSelector(SCycleBase* parent, const char* name)
  : ToolBase( parent, name ),
    m_recoTreeName("")
{

  DeclareProperty( "RecoTreeString", m_recoTreeName = "physics");
  DeclareProperty( "DoFarFSRCorrection", m_doFarFSRCorrection = true);

  return;
  
}

FsrSelector::~FsrSelector() {


 return;

}


void FsrSelector::BeginInputFile( const SInputData& ) throw( SError ){

  return;
}


void FsrSelector::SelectFsr( Quadruplet* quad , D3PDReader::ElectronD3PDObject* m_electron_d3pdobject, D3PDReader::PhotonD3PDObject* m_photon_d3pdobject, D3PDReader::EventInfoD3PDObject* m_event_d3pdobject) {
    
  GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");

  m_logger<<::DEBUG<< "Checking for FSR photons" << SLogger::endmsg;

  std::vector<Photon> all_photons;  
  ParticleElementBuilder::build( all_photons, (*m_photon_d3pdobject) );  
  energy_rescaler->ApplyEnergyRescaler( all_photons, m_event_d3pdobject->EventNumber(), m_event_d3pdobject->RunNumber());	      

  std::vector<float>* ph_et = new std::vector<float>();
  std::vector<float>* ph_topoEtcone40 = new std::vector<float>();
  for(std::vector<Photon>::iterator itr = all_photons.begin(); itr != all_photons.end(); ++itr) { 
      //  isolation corrections for 2012
      float etcone40 = CaloIsoCorrection::GetPtEDCorrectedTopoIsolation((*itr).ED_median(),
                                                                        (*itr).cl_E(),
                                                                        (*itr).etas2(),
                                                                        (*itr).etap(),
                                                                        (*itr).cl_eta(),
                                                                        40,
                                                                        !is_data(),
                                                                        (*itr).topoEtcone40(),
                                                                        (*itr).isConv(),       
                                                                        CaloIsoCorrection::PHOTON);
      ph_topoEtcone40->push_back(etcone40);
      ph_et->push_back((*itr).Et()*(*itr).cl_E_cal()/(*itr).cl_E());
  }

  std::vector<Electron> all_electrons;  
  ParticleElementBuilder::build( all_electrons, (*m_electron_d3pdobject) );  
  energy_rescaler->ApplyEnergyRescaler( all_electrons, m_event_d3pdobject->EventNumber(), m_event_d3pdobject->RunNumber());
  
  std::vector<float>* el_et = new std::vector<float>();
  for(std::vector<Electron>::iterator itr = all_electrons.begin(); itr != all_electrons.end(); ++itr) { 
     el_et->push_back((*itr).cl_pt()*(*itr).calibrated_E()/(*itr).cl_E());
  }

  FsrPhotons fsrphotons; 

  m_logger<<::DEBUG<< "Checking muon FSR candidates" << SLogger::endmsg;

  std::vector<Muon*> muons;
  quad->GetMuons(muons);

  std::vector<FsrPhotons::FsrCandidate> muon_cands;
  std::vector<bool> found_muon_cands;
  int n_cands = 0;
  for (unsigned int i = 0; i < muons.size(); i++){
    muon_cands.push_back(FsrPhotons::FsrCandidate());
    if ( !muons[i]->isCaloMuon()){
      found_muon_cands.push_back( fsrphotons.getFsrPhotons(muons[i]->eta(), 
                        				   muons[i]->phi(),      		   
                        				   muons[i]->id_theta(), 		   
                        				   muons[i]->id_phi(),   		   
                        				   (*m_photon_d3pdobject).eta(),					      
                        				   (*m_photon_d3pdobject).phi(),					      
                        				   ph_et,					      
                        				   (*m_photon_d3pdobject).f1(),					      
                         				   ph_topoEtcone40,				    		   
	                       				   (*m_photon_d3pdobject).author(),			    		   
                        				   (*m_electron_d3pdobject).cl_eta(),			    		   
                        				   (*m_electron_d3pdobject).cl_phi(),			    		   
                        				   el_et,			    		   
                        				   (*m_electron_d3pdobject).f1(),				    		   
                        				   (*m_electron_d3pdobject).tracktheta(),			    		   
                        				   (*m_electron_d3pdobject).trackphi(),			    		   
                        				   muon_cands[i], 			    		   
                        				   (*m_photon_d3pdobject).tight() ));
    } else {
      found_muon_cands.push_back(false);
    }
  }
  
  //m_logger<<::DEBUG<< "Found "<< found_muon_cands.size() << " muon FSR candidates" << SLogger::endmsg;
  
  for (unsigned int i = 0; i < found_muon_cands.size(); i++){
    if (found_muon_cands[i]){
       n_cands++;
       m_logger<<::DEBUG<< "Found muon FSR index, dR, Et, f1, cont " << muon_cands[i].index << " " << muon_cands[i].deltaR
                    << " " << muon_cands[i].Et << " " <<  muon_cands[i].f1 << " " << muon_cands[i].container << SLogger::endmsg;
    }
  }   
  
  m_logger<<::DEBUG<< "Checking electron FSR candidates" << SLogger::endmsg;

  std::vector<Electron*> electrons;
  quad->GetElectrons(electrons);

  std::vector<FsrPhotons::FsrCandidate> electron_cands;
  std::vector<bool> found_electron_cands;
  for (unsigned int i = 0; i < electrons.size(); i++){
    electron_cands.push_back(FsrPhotons::FsrCandidate());
    found_electron_cands.push_back( fsrphotons.getFsrPhotons(electrons[i]->tracketa(), 
                        				     electrons[i]->trackphi(),      		   
                        				     (*m_photon_d3pdobject).eta(),					      
                        				     (*m_photon_d3pdobject).phi(),					      
                        				     ph_et,					      
                        				     (*m_photon_d3pdobject).f1(),					      
                         				     ph_topoEtcone40,				    		   
	                       				     (*m_photon_d3pdobject).author(),			    		   
                          				     (*m_photon_d3pdobject).tight(),
 							     electron_cands[i]));
  }

  //m_logger<<::DEBUG<< "Found "<< found_electron_cands.size() << " electron FSR candidates" << SLogger::endmsg;
  
  for (unsigned int i = 0; i < found_electron_cands.size(); i++){
    if (found_electron_cands[i]){
       n_cands++;
       m_logger<<::DEBUG<< "Found electron FSR index, dR, Et, f1, cont " << electron_cands[i].index << " " << electron_cands[i].deltaR
                    << " " << electron_cands[i].Et << " " <<  electron_cands[i].f1 << " " << electron_cands[i].container << SLogger::endmsg;
    }
  }   
  
  m_logger<<::DEBUG<< "Found "<< n_cands <<" FSR candidates" << SLogger::endmsg;
  if (n_cands == 0) return; // escape early if no candidates found
  
  //combine vectors
  std::vector<FsrPhotons::FsrCandidate> cands;
  std::vector<bool> found_cands;
  if (quad->Type() == Quadruplet::TwoElectronTwoMuon) {
    cands.insert(cands.end(), electron_cands.begin(), electron_cands.end() );
    cands.insert(cands.end(), muon_cands.begin(), muon_cands.end() );

    found_cands.insert(found_cands.end(), found_electron_cands.begin(), found_electron_cands.end() );
    found_cands.insert(found_cands.end(), found_muon_cands.begin(), found_muon_cands.end() );
  }  else {
    cands.insert(cands.end(), muon_cands.begin(), muon_cands.end() );
    cands.insert(cands.end(), electron_cands.begin(), electron_cands.end() );

    found_cands.insert(found_cands.end(), found_muon_cands.begin(), found_muon_cands.end() );
    found_cands.insert(found_cands.end(), found_electron_cands.begin(), found_electron_cands.end() );
  }

  std::vector<TLorentzVector> tlv_cands;
  for (unsigned int i = 0; i < cands.size(); ++i){
    tlv_cands.push_back(TLorentzVector(0,0,0,0));
    if (found_cands[i]) tlv_cands[i].SetPtEtaPhiM(cands[i].Et, cands[i].eta, cands[i].phi, 0.);
  }

  std::vector<TLorentzVector*> tlv_leptons;
  quad->GetLeptonTLVs(tlv_leptons);

  //First check for collinear FSR
  int col_cand = -1;
  bool quad_type = quad->Type() == Quadruplet::FourMuon || quad->Type() == Quadruplet::TwoMuonTwoElectron;
  bool quad_mass = quad->M12() >= 66000 && quad->M12() <= 89000;
  if (quad_type && quad_mass) {
    bool collinear_cand0 = (found_cands[0] == true) && (cands[0].deltaR <= 0.15);
    bool collinear_cand1 = (found_cands[1] == true) && (cands[1].deltaR <= 0.15);
    
    if (collinear_cand0 && collinear_cand1){    
      col_cand = cands[0].Et > cands[1].Et ?  0 : 1;
    } else if (collinear_cand0){
      col_cand = 0;
    } else if (collinear_cand1) {
      col_cand = 1;
    } else {
      m_logger<<::DEBUG<< "No collinear FSR candidate found" << SLogger::endmsg;
    }
  
    if (col_cand != -1){
      double new_m12_mass = (*tlv_leptons[0] + *tlv_leptons[1] + tlv_cands[col_cand]).M();
      if ( new_m12_mass > 100000 ) {
        m_logger<<::DEBUG<< "Failed FSR mass cut: "<< new_m12_mass << SLogger::endmsg;    
      } else {
        //Found candidate!
	m_logger<<::DEBUG<< "Found collinear FSR candidate" << SLogger::endmsg; 
	int fsr_type = cands[col_cand].container == "electron" ? 0 : ((*m_photon_d3pdobject).isConv()->at(cands[col_cand].index) ? 1 : 2);	
        quad->addFSR( tlv_cands[col_cand], 0, fsr_type );
	return;
      }       
    }
  }
  
  if(!m_doFarFSRCorrection) return;
  
  //Second check for far FSR if no collinear FSR found
  m_logger<<::DEBUG<< "Checking for far FSR candidate" << SLogger::endmsg;
  double max_et = -1;
  int far_cand =  -1;
  for (unsigned int i = 0; i <cands.size(); ++i){
    
    if(found_cands[i] == false) continue;    
    if(cands[i].deltaR <= 0.15) continue;
    
    //Found far FSR candidate
    if (far_cand == -1 || cands[i].Et > max_et){      
      far_cand = i;
      max_et   = cands[i].Et;
    }    
  }
  
  if (far_cand != -1){
    bool pass_deltar = true;
    for (unsigned int i = 0; i <tlv_leptons.size(); ++i) {
      if (tlv_leptons[i]->DeltaR(tlv_cands[far_cand]) <= 0.15) pass_deltar = false;    
    }
    m_logger<<::DEBUG<< "pass_deltar "<<pass_deltar << SLogger::endmsg;
    if (!pass_deltar) return;  
    
    double m_llg_12 = (*tlv_leptons[0] + *tlv_leptons[1] + tlv_cands[far_cand]).M();
    double m_llg_34 = (*tlv_leptons[2] + *tlv_leptons[3] + tlv_cands[far_cand]).M();

    bool pass_mass_12  = (quad->M12() < 81000) && (m_llg_12 < 100000);
    bool pass_mass_34  = (quad->M34() < 81000) && (m_llg_34 < 100000) && (quad->M4l() > 190000);

    if (pass_mass_12 || pass_mass_34){
      //Found candidate!
      m_logger<<::DEBUG<< "Found far FSR candidate" << SLogger::endmsg;    
    
      int z_index = -1;
      if (pass_mass_12 && !pass_mass_34) z_index = 0;
      if (!pass_mass_12 && pass_mass_34) z_index = 1;
      if (pass_mass_12 && pass_mass_34)  z_index = abs(m_llg_12 - 91187.6) < abs(m_llg_34 - 91187.6) ? 0 : 1;
      
      int fsr_type = cands[far_cand].container == "electron" ? 0 : ((*m_photon_d3pdobject).isConv()->at(cands[far_cand].index) ? 1 : 2);	

      quad->addFSR( tlv_cands[far_cand] , z_index, fsr_type);      
    }
  }
  
  return;
  
}

