//ROOT
#include "TLorentzVector.h"

#include "../include/Quadruplet.h"

ClassImp(Quadruplet)

Quadruplet::Quadruplet()  
{
}
//Lepton charges (+, -, +, -) for default
Quadruplet::Quadruplet(Muon* l1, Muon* l2, Muon* l3, Muon* l4)  
:  n_muons(4),
   n_electrons(0),
   m_index_FSR(-1),
   m_type_FSR(-1),
   passed_trigger(0),
   tlv_Z1_FSR(0,0,0,0),
   tlv_Z2_FSR(0,0,0,0)
{

  quadtype = FourMuon;

  v_muons.push_back(l1);
  v_muons.push_back(l2);
  v_muons.push_back(l3);
  v_muons.push_back(l4);
    
  lepton_type.push_back(l1->charge()*(l1->isCaloMuon() ? 3 : 2));
  lepton_type.push_back(l2->charge()*(l2->isCaloMuon() ? 3 : 2));
  lepton_type.push_back(l3->charge()*(l3->isCaloMuon() ? 3 : 2));
  lepton_type.push_back(l4->charge()*(l4->isCaloMuon() ? 3 : 2));

  lepton_index.push_back(l1->GetIndex());
  lepton_index.push_back(l2->GetIndex());
  lepton_index.push_back(l3->GetIndex());
  lepton_index.push_back(l4->GetIndex());
       
  return;
}

Quadruplet::Quadruplet(Electron* l1, Electron* l2, Electron* l3, Electron* l4)  
:  n_muons(0),
   n_electrons(4),
   m_index_FSR(-1),
   m_type_FSR(-1),
   passed_trigger(0),
   tlv_Z1_FSR(0,0,0,0),
   tlv_Z2_FSR(0,0,0,0)
{

  quadtype = FourElectron;

  v_electrons.push_back(l1);
  v_electrons.push_back(l2);
  v_electrons.push_back(l3);
  v_electrons.push_back(l4);
    
  lepton_type.push_back(l1->charge());
  lepton_type.push_back(l2->charge());
  lepton_type.push_back(l3->charge());
  lepton_type.push_back(l4->charge());

  lepton_index.push_back(l1->GetIndex());
  lepton_index.push_back(l2->GetIndex());
  lepton_index.push_back(l3->GetIndex());
  lepton_index.push_back(l4->GetIndex());
       
  return;
}

Quadruplet::Quadruplet(Muon* l1, Muon* l2, Electron* l3, Electron* l4)  
:  n_muons(2),
   n_electrons(2),
   m_index_FSR(-1),
   m_type_FSR(-1),
   passed_trigger(0),
   tlv_Z1_FSR(0,0,0,0),
   tlv_Z2_FSR(0,0,0,0)
{

  quadtype = TwoMuonTwoElectron;

  v_muons.push_back(l1);
  v_muons.push_back(l2);
  v_electrons.push_back(l3);
  v_electrons.push_back(l4);
      
  lepton_type.push_back(l1->charge()*(l1->isCaloMuon() ? 3 : 2));
  lepton_type.push_back(l2->charge()*(l2->isCaloMuon() ? 3 : 2));
  lepton_type.push_back(l3->charge());
  lepton_type.push_back(l4->charge());

  lepton_index.push_back(l1->GetIndex());
  lepton_index.push_back(l2->GetIndex());
  lepton_index.push_back(l3->GetIndex());
  lepton_index.push_back(l4->GetIndex());
       
  return;
}

Quadruplet::Quadruplet(Electron* l1, Electron* l2, Muon* l3, Muon* l4)  
:  n_muons(2),
   n_electrons(2),
   m_index_FSR(-1),
   m_type_FSR(-1),
   passed_trigger(0),
   tlv_Z1_FSR(0,0,0,0),
   tlv_Z2_FSR(0,0,0,0)
{

  quadtype = TwoElectronTwoMuon;

  v_electrons.push_back(l1);
  v_electrons.push_back(l2);
  v_muons.push_back(l3);
  v_muons.push_back(l4);
      
  lepton_type.push_back(l1->charge());
  lepton_type.push_back(l2->charge());
  lepton_type.push_back(l3->charge()*(l3->isCaloMuon() ? 3 : 2));
  lepton_type.push_back(l4->charge()*(l4->isCaloMuon() ? 3 : 2));

  lepton_index.push_back(l1->GetIndex());
  lepton_index.push_back(l2->GetIndex());
  lepton_index.push_back(l3->GetIndex());
  lepton_index.push_back(l4->GetIndex());
       
  return;
}

void Quadruplet::GetMuons(std::vector<Muon*> &leptons) {

  for (unsigned int i = 0; i < v_muons.size(); i++){
    leptons.push_back(v_muons.at(i));
  }

  return;
}


void Quadruplet::GetElectrons(std::vector<Electron*> &leptons){

  for (unsigned int i = 0; i < v_electrons.size(); i++){
    leptons.push_back(v_electrons.at(i));
  }

  return;
}

void Quadruplet::GetMuonTLVs(std::vector<TLorentzVector*> &leptons) {

  for (unsigned int i = 0; i < v_muons.size(); i++){    
    leptons.push_back(v_muons.at(i)->TLV());
  }

  return;
}


void Quadruplet::GetElectronTLVs(std::vector<TLorentzVector*> &leptons){

  for (unsigned int i = 0; i < v_electrons.size(); i++){
    leptons.push_back(v_electrons.at(i)->TLV());
  }

  return;
}

void Quadruplet::GetLeptonTLVs(std::vector<TLorentzVector*> &leptons){

  if (quadtype == TwoElectronTwoMuon) {
    for (unsigned int i = 0; i < v_electrons.size(); i++){
      leptons.push_back(v_electrons.at(i)->TLV());
    }  
    for (unsigned int i = 0; i < v_muons.size(); i++){
      leptons.push_back(v_muons.at(i)->TLV());
    } 
  }  else {
    for (unsigned int i = 0; i < v_muons.size(); i++){
      leptons.push_back(v_muons.at(i)->TLV());
    } 
    for (unsigned int i = 0; i < v_electrons.size(); i++){
      leptons.push_back(v_electrons.at(i)->TLV());
    }  
  }
   
  return;
}


TLorentzVector Quadruplet::TLV(){

  TLorentzVector tlv_4l(0,0,0,0);

  for (unsigned int i = 0; i < v_muons.size(); i++){    
    tlv_4l += *(v_muons.at(i)->TLV());
  }
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    tlv_4l += *(v_electrons.at(i)->TLV());
  }   
 
  return tlv_4l;
}

TLorentzVector Quadruplet::Z1_TLV(){

  TLorentzVector tlv_12(0,0,0,0);

  if ( quadtype == FourMuon || quadtype == TwoMuonTwoElectron){
    tlv_12 += *(v_muons.at(0)->TLV());
    tlv_12 += *(v_muons.at(1)->TLV());
  } else if ( quadtype == FourElectron || quadtype == TwoElectronTwoMuon){
    tlv_12 += *(v_electrons.at(0)->TLV());
    tlv_12 += *(v_electrons.at(1)->TLV());
  }
   
  return tlv_12;
}

TLorentzVector Quadruplet::Z2_TLV(){

  TLorentzVector tlv_34(0,0,0,0);

  if ( quadtype == FourMuon ){
    tlv_34 += *(v_muons.at(2)->TLV());
    tlv_34 += *(v_muons.at(3)->TLV());
  } else if ( quadtype == TwoElectronTwoMuon){
    tlv_34 += *(v_muons.at(0)->TLV());
    tlv_34 += *(v_muons.at(1)->TLV());
  } else if( quadtype == TwoMuonTwoElectron ){ 
    tlv_34 += *(v_electrons.at(0)->TLV());
    tlv_34 += *(v_electrons.at(1)->TLV());     
  } else if ( quadtype == FourElectron){
    tlv_34 += *(v_electrons.at(2)->TLV());
    tlv_34 += *(v_electrons.at(3)->TLV()); 
  }   
  
  return tlv_34;
}


double Quadruplet::M14(){

  TLorentzVector tlv_14(0,0,0,0);

  if ( quadtype == FourMuon ){
    tlv_14 += *(v_muons.at(0)->TLV());
    tlv_14 += *(v_muons.at(3)->TLV());
  } else if ( quadtype == TwoElectronTwoMuon){
    tlv_14 += *(v_electrons.at(0)->TLV());
    tlv_14 += *(v_muons.at(1)->TLV());
  } else if( quadtype == TwoMuonTwoElectron ){ 
    tlv_14 += *(v_muons.at(0)->TLV());
    tlv_14 += *(v_electrons.at(1)->TLV());     
  } else if ( quadtype == FourElectron){
    tlv_14 += *(v_electrons.at(0)->TLV());
    tlv_14 += *(v_electrons.at(3)->TLV()); 
  }   
  
  return tlv_14.M();
}


double Quadruplet::M23(){

  TLorentzVector tlv_23(0,0,0,0);

  if ( quadtype == FourMuon ){
    tlv_23 += *(v_muons.at(1)->TLV());
    tlv_23 += *(v_muons.at(2)->TLV());
  } else if ( quadtype == TwoElectronTwoMuon){
    tlv_23 += *(v_electrons.at(1)->TLV());
    tlv_23 += *(v_muons.at(0)->TLV());
  } else if( quadtype == TwoMuonTwoElectron ){ 
    tlv_23 += *(v_muons.at(1)->TLV());
    tlv_23 += *(v_electrons.at(0)->TLV());     
  } else if ( quadtype == FourElectron){
    tlv_23 += *(v_electrons.at(1)->TLV());
    tlv_23 += *(v_electrons.at(2)->TLV()); 
  }   
  
  return tlv_23.M();
}

int Quadruplet::n_StandAloneMuons() {

  int n_sa = 0;
  
  for (unsigned int i = 0; i < v_muons.size(); i++){
    if (v_muons.at(i)->isStandAloneMuon() == 1) n_sa++;
  }

  return n_sa;
}

int Quadruplet::n_CaloTagMuons() {

  int n_calo = 0;
  
  for (unsigned int i = 0; i < v_muons.size(); i++){
    if (v_muons.at(i)->author() == 16) n_calo++;
  }

  return n_calo;
}

void Quadruplet::LeptonType(std::vector<int> &types){

  for (unsigned int i = 0; i < lepton_type.size(); i++){
     types.push_back(lepton_type.at(i));  
  }
  
  return;
}

void Quadruplet::LeptonIndex(std::vector<int> &index){

  for (unsigned int i = 0; i < lepton_index.size(); i++){
     index.push_back(lepton_index.at(i));  
  }
  
  return;
}

void Quadruplet::LeptonPt(std::vector<double> &pt) {

  std::vector<double> pt_mu;
  for (unsigned int i = 0; i < v_muons.size(); i++){
     pt_mu.push_back(v_muons.at(i)->TLV()->Pt());  
  }

  std::vector<double> pt_el;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    pt_el.push_back(v_electrons.at(i)->TLV()->Pt());  
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton pt vector
  if (quadtype == TwoElectronTwoMuon) {
    pt.insert(pt.end(), pt_el.begin(), pt_el.end() );
    pt.insert(pt.end(), pt_mu.begin(), pt_mu.end() );
  }  else {
    pt.insert(pt.end(), pt_mu.begin(), pt_mu.end() );
    pt.insert(pt.end(), pt_el.begin(), pt_el.end() );
  }

  if (pt.size() != 4) std::cout<< "Error in Quadruplet::LeptonPt(): Only found "<< pt.size() <<" particles."<<std::endl;
      
  return;
}


void Quadruplet::LeptonPhi(std::vector<double> &phi) {

  std::vector<double> phi_mu;
  for (unsigned int i = 0; i < v_muons.size(); i++){
     phi_mu.push_back(v_muons.at(i)->TLV()->Phi());  
  }

  std::vector<double> phi_el;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    phi_el.push_back(v_electrons.at(i)->TLV()->Phi());  
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton phi vector
  if (quadtype == TwoElectronTwoMuon) {
    phi.insert(phi.end(), phi_el.begin(), phi_el.end() );
    phi.insert(phi.end(), phi_mu.begin(), phi_mu.end() );
  }  else {
    phi.insert(phi.end(), phi_mu.begin(), phi_mu.end() );
    phi.insert(phi.end(), phi_el.begin(), phi_el.end() );
  }

  if (phi.size() != 4) std::cout<< "Error in Quadruplet::LeptonPhi(): Only found "<< phi.size() <<" particles."<<std::endl;
      
  return;
}

void Quadruplet::LeptonEta(std::vector<double> &eta) {

  std::vector<double> eta_mu;
  for (unsigned int i = 0; i < v_muons.size(); i++){
     eta_mu.push_back(v_muons.at(i)->TLV()->Eta());  
  }

  std::vector<double> eta_el;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    eta_el.push_back(v_electrons.at(i)->TLV()->Eta());  
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton eta vector
  if (quadtype == TwoElectronTwoMuon) {
    eta.insert(eta.end(), eta_el.begin(), eta_el.end() );
    eta.insert(eta.end(), eta_mu.begin(), eta_mu.end() );
  }  else {
    eta.insert(eta.end(), eta_mu.begin(), eta_mu.end() );
    eta.insert(eta.end(), eta_el.begin(), eta_el.end() );
  }

  if (eta.size() != 4) std::cout<< "Error in Quadruplet::LeptonEta(): Only found "<< eta.size() <<" particles."<<std::endl;
      
  return;
}

void Quadruplet::LeptonM(std::vector<double> &m) {

  std::vector<double> m_mu;
  for (unsigned int i = 0; i < v_muons.size(); i++){
     m_mu.push_back(v_muons.at(i)->TLV()->M());  
  }

  std::vector<double> m_el;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    m_el.push_back(v_electrons.at(i)->TLV()->M());  
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton mass vector
  if (quadtype == TwoElectronTwoMuon) {
    m.insert(m.end(), m_el.begin(), m_el.end() );
    m.insert(m.end(), m_mu.begin(), m_mu.end() );
  }  else {
    m.insert(m.end(), m_mu.begin(), m_mu.end() );
    m.insert(m.end(), m_el.begin(), m_el.end() );
  }

  if (m.size() != 4) std::cout<< "Error in Quadruplet::Leptonm(): Only found "<< m.size() <<" particles."<<std::endl;
      
  return;
}

void Quadruplet::LeptonCovMom(std::vector<double> &m) {

  std::vector<double> m_mu;
  for (unsigned int i = 0; i < v_muons.size(); i++){
     m_mu.push_back(pow(v_muons.at(i)->TLV()->P(), 4)*v_muons.at(i)->cov_qoverp_exPV_cal());  
  }

  std::vector<double> m_el;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    m_el.push_back(v_electrons.at(i)->E_resolution()*v_electrons.at(i)->cl_E_cal()*v_electrons.at(i)->E_resolution()*v_electrons.at(i)->cl_E_cal());  
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton mass vector
  if (quadtype == TwoElectronTwoMuon) {
    m.insert(m.end(), m_el.begin(), m_el.end() );
    m.insert(m.end(), m_mu.begin(), m_mu.end() );
  }  else {
    m.insert(m.end(), m_mu.begin(), m_mu.end() );
    m.insert(m.end(), m_el.begin(), m_el.end() );
  }

  if (m.size() != 4) std::cout<< "Error in Quadruplet::LeptonCovMom(): Only found "<< m.size() <<" particles."<<std::endl;
      
  return;
}

void Quadruplet::LeptonIDPt(std::vector<double> &pt) {

  std::vector<double> pt_mu;
  for (unsigned int i = 0; i < v_muons.size(); i++){
     if (v_muons.at(i)->isStandAloneMuon()){
       pt_mu.push_back(v_muons.at(i)->TLV()->Pt());
     } else {
       pt_mu.push_back(v_muons.at(i)->id_Pt());       
     }
  }

  std::vector<double> pt_el;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    pt_el.push_back(v_electrons.at(i)->TLV()->Pt());  
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton pt vector
  if (quadtype == TwoElectronTwoMuon) {
    pt.insert(pt.end(), pt_el.begin(), pt_el.end() );
    pt.insert(pt.end(), pt_mu.begin(), pt_mu.end() );
  }  else {
    pt.insert(pt.end(), pt_mu.begin(), pt_mu.end() );
    pt.insert(pt.end(), pt_el.begin(), pt_el.end() );
  }

  if (pt.size() != 4) std::cout<< "Error in Quadruplet::LeptonPt(): Only found "<< pt.size() <<" particles."<<std::endl;
      
  return;
}


void Quadruplet::LeptonIDPhi(std::vector<double> &phi) {

  std::vector<double> phi_mu;
  for (unsigned int i = 0; i < v_muons.size(); i++){
     if (v_muons.at(i)->isStandAloneMuon()){
       phi_mu.push_back(v_muons.at(i)->TLV()->Phi());
     } else {
       phi_mu.push_back(v_muons.at(i)->id_phi());       
     }
  }

  std::vector<double> phi_el;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    phi_el.push_back(v_electrons.at(i)->TLV()->Phi());  
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton phi vector
  if (quadtype == TwoElectronTwoMuon) {
    phi.insert(phi.end(), phi_el.begin(), phi_el.end() );
    phi.insert(phi.end(), phi_mu.begin(), phi_mu.end() );
  }  else {
    phi.insert(phi.end(), phi_mu.begin(), phi_mu.end() );
    phi.insert(phi.end(), phi_el.begin(), phi_el.end() );
  }

  if (phi.size() != 4) std::cout<< "Error in Quadruplet::LeptonPhi(): Only found "<< phi.size() <<" particles."<<std::endl;
      
  return;
}

void Quadruplet::LeptonIDEta(std::vector<double> &eta) {

  std::vector<double> eta_mu;
  for (unsigned int i = 0; i < v_muons.size(); i++){
     if (v_muons.at(i)->isStandAloneMuon()){
       eta_mu.push_back(v_muons.at(i)->TLV()->Eta());
     } else {
       eta_mu.push_back(v_muons.at(i)->id_eta());       
     }
  }

  std::vector<double> eta_el;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    eta_el.push_back(v_electrons.at(i)->TLV()->Eta());  
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton eta vector
  if (quadtype == TwoElectronTwoMuon) {
    eta.insert(eta.end(), eta_el.begin(), eta_el.end() );
    eta.insert(eta.end(), eta_mu.begin(), eta_mu.end() );
  }  else {
    eta.insert(eta.end(), eta_mu.begin(), eta_mu.end() );
    eta.insert(eta.end(), eta_el.begin(), eta_el.end() );
  }

  if (eta.size() != 4) std::cout<< "Error in Quadruplet::LeptonEta(): Only found "<< eta.size() <<" particles."<<std::endl;
      
  return;
}



void Quadruplet::LeptonTrkIsolation(std::vector<double> &trk_iso, int muon_cone_size, int electron_cone_size){

  //put in check on previous calcuation of isolation to reduce number of times it is calculated?  (requires same cone size)

  CalculateTrkIso(muon_cone_size, electron_cone_size);
  
  trk_iso.insert(trk_iso.end(), lepton_trk_iso.begin(), lepton_trk_iso.end() );
   
  return; 
}
  
void Quadruplet::LeptonCaloIsolation(std::vector<double> &calo_iso, bool isMC, int muon_cone_size, int electron_cone_size, int sub_electron_cone_size){

  //put in check on previous calcuation of isolation to reduce number of times it is calculated?  requires same cone sizes...

  CalculateCaloIso(muon_cone_size, electron_cone_size, sub_electron_cone_size, isMC);
  
  calo_iso.insert(calo_iso.end(), lepton_calo_iso.begin(), lepton_calo_iso.end() );
   
  return; 
}

void Quadruplet::LeptonD0Significance(std::vector<double> &d0_sig, bool isMC){

  CalculateD0Significance(isMC);
  
  d0_sig.insert(d0_sig.end(), lepton_d0_sig.begin(), lepton_d0_sig.end() );
   
  return; 
}

void Quadruplet::LeptondRJet(std::vector<double> &dr_jet, std::vector<Jet*> jets){

  std::vector<TLorentzVector*> vectors;
  GetLeptonTLVs(vectors);
  
  for (unsigned int i = 0; i < vectors.size(); ++i) {
    double min_dr = -1;
    for (unsigned int j = 0; j < jets.size(); ++j) {
      min_dr = (min_dr == -1) ? vectors[i]->DeltaR(jets[j]->TLV()) : std::min(min_dr,vectors[i]->DeltaR(jets[j]->TLV()));
    }    
    dr_jet.push_back(min_dr);
  }  
  
  return; 
}

double Quadruplet::MinDeltaRSF() {

  double min_delta_r = 100;

  for (unsigned int i = 0; i < v_muons.size(); i++){
    for (unsigned int j = 0; j < v_muons.size(); j++){
      if (i>=j) continue;

      double delta_r = DeltaR(v_muons.at(i)->eta(), v_muons.at(i)->phi(), v_muons.at(j)->eta(), v_muons.at(j)->phi());
        
      min_delta_r = std::min(min_delta_r, delta_r);
    } 
  }
  
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    for (unsigned int j = 0; j < v_electrons.size(); j++){
      if (i>=j) continue;

      double delta_r = DeltaR(v_electrons.at(i)->tracketa(), v_electrons.at(i)->trackphi(), v_electrons.at(j)->tracketa(), v_electrons.at(j)->trackphi());
      
      min_delta_r = std::min(min_delta_r, delta_r);
    }
  }

  return min_delta_r;
}

double Quadruplet::MinDeltaROF() {

  double min_delta_r = 100;

  for (unsigned int i = 0; i < v_muons.size(); i++){
    for (unsigned int j = 0; j < v_electrons.size(); j++){

      double delta_r = DeltaR(v_muons.at(i)->eta(), v_muons.at(i)->phi(), v_electrons.at(j)->tracketa(), v_electrons.at(j)->trackphi());
        
      min_delta_r = std::min(min_delta_r, delta_r);
    } 
  }
  
  return min_delta_r;
}

void Quadruplet::CalculateTrkIso(int muon_cone_size, int electron_cone_size){
  
  lepton_trk_iso.clear();

  //muons first
  std::vector<double> muon_trk_iso;
  for (unsigned int i = 0; i < v_muons.size(); i++){
    double trk_iso = CalculateTrkIso(v_muons.at(i), muon_cone_size);    
    muon_trk_iso.push_back(trk_iso);
  }

  //electrons second
  std::vector<double> electron_trk_iso;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    double trk_iso = CalculateTrkIso(v_electrons.at(i), electron_cone_size);
    electron_trk_iso.push_back(trk_iso);    
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton iso vector
  if (quadtype == TwoElectronTwoMuon) {
    lepton_trk_iso.insert(lepton_trk_iso.end(), electron_trk_iso.begin(), electron_trk_iso.end() );
    lepton_trk_iso.insert(lepton_trk_iso.end(), muon_trk_iso.begin(), muon_trk_iso.end() );
  }  else {
    lepton_trk_iso.insert(lepton_trk_iso.end(), muon_trk_iso.begin(), muon_trk_iso.end() );  
    lepton_trk_iso.insert(lepton_trk_iso.end(), electron_trk_iso.begin(), electron_trk_iso.end() );
  }
  
  if (lepton_trk_iso.size() != 4) std::cout<< "Error in Quadruplet::CalculateTrkIso(): Found "<< lepton_trk_iso.size() <<" particles."<<std::endl;

  return;
}

double Quadruplet::CalculateTrkIso(Muon* muon, int cone_size){
  
  double trk_iso = muon->ptcone(cone_size);

  //subtract other muon contributions
  for (unsigned int i = 0; i < v_muons.size(); i++){
    
    if (muon->GetIndex() == v_muons.at(i)->GetIndex()){
      if (muon->author() == v_muons.at(i)->author()){ //check author because we use two collections
	continue; //found input muon - skip this one
      }
    }

    if (v_muons.at(i)->isStandAloneMuon() == 1) continue;  //don't remove standalone muon contribution (no id track)

    if (DeltaR(muon->eta(), muon->phi(), v_muons.at(i)->eta(), v_muons.at(i)->phi()) < cone_size/100.0){  
      //std::cout<< "DEBUG: CalculateTrkIso(): Overlapping muon found in muon cone: " <<muon_cone_size/100.0 << std::endl;
      trk_iso -= 1/fabs(v_muons.at(i)->id_qoverp())*sin(v_muons.at(i)->id_theta()); 
    }
  }
    
  //subtract electron contributions
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    if (DeltaR(muon->eta(), muon->phi(), v_electrons.at(i)->tracketa(), v_electrons.at(i)->trackphi()) < cone_size/100.0){  
      //std::cout<< "DEBUG: CalculateTrkIso(): Overlapping electron found in muon cone: " <<muon_cone_size/100.0 << std::endl;
      trk_iso -= v_electrons.at(i)->trackpt();
    }
  }
  //std::cout<< "DEBUG: CalculateTrkIso(): muon isolation: " << trk_iso/muon->Pt() << std::endl;

  return trk_iso/muon->Pt();
}
  
  
double Quadruplet::CalculateTrkIso(Electron* electron, int cone_size){

  double trk_iso = electron->ptcone(cone_size);

  //subtract muon contributions
  for (unsigned int j = 0; j < v_muons.size(); j++){

    if (v_muons.at(j)->isStandAloneMuon() == 1) continue;  //don't remove standalone muon contribution (no id track)

    if (DeltaR(electron->tracketa(), electron->trackphi(), v_muons.at(j)->eta(), v_muons.at(j)->phi()) < cone_size/100.0){  
      trk_iso -= 1/fabs(v_muons.at(j)->id_qoverp())*sin(v_muons.at(j)->id_theta()); 
    }
  }

  //subtract other electron contributions
  for (unsigned int j = 0; j < v_electrons.size(); j++){

    if (electron->GetIndex() == v_electrons.at(j)->GetIndex()) continue;

    if  (DeltaR(electron->tracketa(), electron->trackphi(), v_electrons.at(j)->tracketa(), v_electrons.at(j)->trackphi()) < cone_size/100.0){  
      trk_iso -= v_electrons.at(j)->trackpt();
    }

  }

  return trk_iso/electron->cl_Et();
}

void Quadruplet::CalculateCaloIso(int muon_cone_size, int electron_cone_size, int sub_electron_cone_size, bool isMC){

  lepton_calo_iso.clear();

  //muons first
  std::vector<double> muon_calo_iso;
  for (unsigned int i = 0; i < v_muons.size(); i++){
    double calo_iso = CalculateCaloIso(v_muons.at(i), muon_cone_size, sub_electron_cone_size);      
    muon_calo_iso.push_back(calo_iso);
  }

  //electrons second
  std::vector<double> electron_calo_iso;
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    double calo_iso = CalculateCaloIso(v_electrons.at(i), electron_cone_size, sub_electron_cone_size, isMC);      
    electron_calo_iso.push_back(calo_iso);
  }

  //preserve 1-1 mapping between lepton type vector and lepton iso vector
  if (quadtype == TwoElectronTwoMuon) {
    lepton_calo_iso.insert(lepton_calo_iso.end(), electron_calo_iso.begin(), electron_calo_iso.end() );
    lepton_calo_iso.insert(lepton_calo_iso.end(), muon_calo_iso.begin(), muon_calo_iso.end() );
  }  else {
    lepton_calo_iso.insert(lepton_calo_iso.end(), muon_calo_iso.begin(), muon_calo_iso.end() );  
    lepton_calo_iso.insert(lepton_calo_iso.end(), electron_calo_iso.begin(), electron_calo_iso.end() );
  }

  if (lepton_calo_iso.size() != 4) std::cout<< "Error in Quadruplet::CalculateCaloIso(): Found "<< lepton_calo_iso.size() <<" particles."<<std::endl;

  return;
}
  

double Quadruplet::CalculateCaloIso(Muon* muon, int muon_cone_size, int sub_electron_cone_size){

    double calo_iso = muon->etcone(muon_cone_size);
    
    //subtract electron contributions
    for (unsigned int j = 0; j < v_electrons.size(); j++){
      if  (DeltaR(muon->eta(), muon->phi(), v_electrons.at(j)->etas2(), v_electrons.at(j)->phis2()) < sub_electron_cone_size/100.0){  
        calo_iso -= v_electrons.at(j)->rawcl_E()/cosh(v_electrons.at(j)->tracketa());
      }
    }

    return calo_iso/muon->Pt();
}

double Quadruplet::CalculateCaloIso(Electron* electron, int electron_cone_size, int sub_electron_cone_size, bool isMC){

    double calo_iso = electron->etcone(electron_cone_size, isMC);

    //subtract other electron contributions
    for (unsigned int j = 0; j < v_electrons.size(); j++){
      if (electron->GetIndex() == v_electrons.at(j)->GetIndex()) continue;
      if (DeltaR(electron->etas2(), electron->phis2(), v_electrons.at(j)->etas2(), v_electrons.at(j)->phis2()) < sub_electron_cone_size/100.0){  
        calo_iso -= v_electrons.at(j)->rawcl_E()/cosh(v_electrons.at(j)->tracketa());
      }
    }

    return calo_iso/electron->cl_Et();
}

  
void Quadruplet::CalculateD0Significance(bool isMC){
  
  lepton_d0_sig.clear();

  //muons first
  std::vector<double> muon_d0_sig;
  for (unsigned int i = 0; i < v_muons.size(); i++){
    
    if (v_muons.at(i)->isStandAloneMuon() == 1) {
      muon_d0_sig.push_back(0.0);
    } else {    
      muon_d0_sig.push_back(v_muons.at(i)->D0Significance());
    }
  }

  //electrons second
  std::vector<double> electron_d0_sig;
  for (unsigned int i = 0; i < v_electrons.size(); i++){

    electron_d0_sig.push_back(v_electrons.at(i)->D0Significance());  
    
  }
  
  //preserve 1-1 mapping between lepton type vector and lepton iso vector
  if (quadtype == TwoElectronTwoMuon) {
    lepton_d0_sig.insert(lepton_d0_sig.end(), electron_d0_sig.begin(), electron_d0_sig.end() );
    lepton_d0_sig.insert(lepton_d0_sig.end(), muon_d0_sig.begin(), muon_d0_sig.end() );
  }  else {
    lepton_d0_sig.insert(lepton_d0_sig.end(), muon_d0_sig.begin(), muon_d0_sig.end() );  
    lepton_d0_sig.insert(lepton_d0_sig.end(), electron_d0_sig.begin(), electron_d0_sig.end() );
  }

  if (lepton_d0_sig.size() != 4) std::cout<< "Error in Quadruplet::CalculateD0Significance(): Found "<< lepton_d0_sig.size() <<" particles."<<std::endl;
  
  return;
}

double Quadruplet::M4l_ID(){

  TLorentzVector v_H(0,0,0,0);

  //muons first
  for (unsigned int i = 0; i < v_muons.size(); i++){
    
    TLorentzVector v_m(0,0,0,0);
    if (v_muons.at(i)->isStandAloneMuon()){
      v_m.SetPtEtaPhiM(v_muons.at(i)->Pt(), v_muons.at(i)->eta(), v_muons.at(i)->phi(), v_muons.at(i)->m()); 
    } else {
      v_m.SetPtEtaPhiM(v_muons.at(i)->id_Pt(), v_muons.at(i)->id_eta(), v_muons.at(i)->id_phi(), v_muons.at(i)->m());       
    }
       
    v_H = v_H + v_m;	
  }

  //electrons second
  for (unsigned int i = 0; i < v_electrons.size(); i++){
    TLorentzVector v_e(0,0,0,0);
    v_e.SetPtEtaPhiE(v_electrons.at(i)->cl_Et(), v_electrons.at(i)->tracketa(), v_electrons.at(i)->trackphi(), v_electrons.at(i)->cl_E_cal());

    v_H = v_H + v_e;	
  }
 
  return v_H.M();
}


void Quadruplet::addFSR( TLorentzVector fsr, int index, int type) { 

  m_index_FSR = index; 
  
  m_type_FSR = type;

  if (index == 0) tlv_Z1_FSR = fsr; 
  if (index == 1) tlv_Z2_FSR = fsr;
  
  return;
}

void Quadruplet::getElicityAngles( float* cthstr, float* phi1, float* cth1, float* cth2, float* phi ){

    std::vector<TLorentzVector*> vectors;
    GetLeptonTLVs(vectors);

    GetElicityAngles( *vectors[1], *vectors[0], *vectors[3], *vectors[2],
		      cthstr, phi1, cth1, cth2, phi );
    return;
}

double Quadruplet::DeltaR(double eta1, double phi1, double eta2, double phi2) {  
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  //  double delta_phi = phi1 - phi2;
  double delta_eta = eta1 - eta2;  
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}

