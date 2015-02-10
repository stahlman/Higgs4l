// $Id: TruthSelector.cxx 27180 2014-05-27 13:55:11Z stahlman $

// Local include(s):
#include "../include/TruthSelector.h"

//SFrameUtils include(s):
#include "ParticleElementBuilder.h"

//ROOT includes
#include "TLorentzVector.h"
#include "TFile.h"

ClassImp( TruthSelector );

TruthSelector::TruthSelector(SCycleBase* parent, const char* name)
:   ToolBase( parent, name )
{

  DeclareProperty( "RecoTreeString", m_recoTreeName = "physics" );

  return;
  
}

TruthSelector::~TruthSelector() {

 return;

}


//____________________________________________________________________________         
void TruthSelector::BeginInputData( const SInputData& )
{

   m_logger << DEBUG << "Initializing Higgs Pt Reweighting SF for Powheg" << SLogger::endmsg;
   TFile *f = TFile::Open((sframe_dir()+"/config/other/Higgs_pT_Njets_reweighing_April2014.root").c_str());
   m_ggF_HpT_weight_01jets   = (TH1F*)f->Get("Reweigh_Powheg_To_HRes2Dynamic_01jets");
   m_ggF_HpT_weight_geq2jets = (TH1F*)f->Get("Reweigh_Powheg_To_HRes2Dynamic_geq2jets");

}

//____________________________________________________________________________
void TruthSelector::DressLeptons( const D3PDReader::TruthParticleD3PDObject* truth_d3pdobject, std::vector<TruthParticle*> &dressed_particles ) {

  std::vector<TruthParticle> tparts;  
  ParticleElementBuilder::build( tparts, (*truth_d3pdobject) );

  for (unsigned int i = 0; i < tparts.size(); i++) {

     dressed_particles.push_back(new TruthParticle(tparts[i]));
     
     //dress final state electrons
     if ( dressed_particles[i]->status() == 1 && (dressed_particles[i]->pdgId() == PDG::e_minus  || dressed_particles[i]->pdgId() == PDG::e_plus )){        
       for (unsigned int j = 0; j < tparts.size(); j++) {
	  //find FSR photons
          if ( tparts[j].pdgId()  != PDG::gamma ) 		continue;
          if ( tparts[j].status() != 1 ) 			continue;
          if ( tparts[j].barcode() >= 200000 ) 			continue;
          if ( tparts[j].TLV().DeltaR(dressed_particles[i]->TLV()) > 0.1 ) 	continue;
          
	  if ( tparts[j].GetMother().pdgId() != PDG::Z0) continue; 
          
	  m_logger << DEBUG << "DressLeptons: Adding Photon to Electron. Mother: "<<tparts[j].GetMother().pdgId() << SLogger::endmsg;          
          dressed_particles[i]->AddPhoton(tparts[j].TLV());
          //m_logger << DEBUG << "DressLeptons: Bare pT: " << dressed_particles[i]->TLV().Pt() << " Dressed pT: "<< dressed_particles[i]->Dressed_TLV().Pt() << SLogger::endmsg;          
       }
     }	       
  }
  
  m_logger << DEBUG << "Finished dressing leptons" << SLogger::endmsg;          
   
  return;
}

//____________________________________________________________________________
int TruthSelector::ClassifyQuad( std::vector<TruthParticle*> &quad ){
  
  if (quad.size() != 4) {      
      m_logger << ERROR << "Quad has " << quad.size() << " leptons" << SLogger::endmsg;
      return -1;    
  }
  
  if ((quad[0]->pdgId() != -1*quad[1]->pdgId()) || (quad[2]->pdgId() != -1*quad[3]->pdgId())){
      m_logger << ERROR << "Incorrect truth quadruplet formation" << SLogger::endmsg;
      return -1;
  }
  
  int event_type = -1;  
  int l12 = fabs(quad[0]->pdgId());
  int l34 = fabs(quad[2]->pdgId());
 
  if (l12 == PDG::mu_minus && l34 == PDG::mu_minus) 	 event_type = 0;
  else if (l12 == PDG::e_minus  && l34 == PDG::e_minus)  event_type = 1;
  else if (l12 == PDG::mu_minus && l34 == PDG::e_minus)  event_type = 2;
  else if (l12 == PDG::e_minus  && l34 == PDG::mu_minus) event_type = 3;
  else if (l12 == l34) event_type = 4; //tau events
  else event_type = 5;  

  return event_type;
}

//____________________________________________________________________________
int TruthSelector::ClassifyEvent( std::vector<TruthParticle*> &tparts ){
  
  int n_muons = 0;
  int n_electrons = 0;
  int n_taus = 0;
    
  for (unsigned int i = 0; i < tparts.size(); i++) {

      if (tparts[i]->pdgId() == PDG::Z0 && tparts[i]->status() == 22) {

	 m_logger << DEBUG << "Found Z0 Truth Particle " << SLogger::endmsg;  

         for (unsigned int j = 0; j < tparts[i]->child_index().size(); j++) {
	   int l_index = tparts[i]->child_index()[j];

	   m_logger << DEBUG << "Daughter Particle: "<<tparts[l_index]->pdgId() << " " <<tparts[l_index]->status() << SLogger::endmsg;  

	   //First look for electrons.... 
	   if ( (tparts[l_index]->pdgId() == PDG::e_minus  || tparts[l_index]->pdgId() == PDG::e_plus ) 
	     && (tparts[l_index]->status() == 1) )  {

	      m_logger << DEBUG << "Found electron from H->ZZ->4l decay! "  << SLogger::endmsg;  
 	      n_electrons++; 
	      continue;	     
           }			 

           //and muons....
	   if ( (tparts[l_index]->pdgId() == PDG::mu_minus || tparts[l_index]->pdgId() == PDG::mu_plus ) 
	     && (tparts[l_index]->status() == 1) )  {

	       m_logger << DEBUG << "Found muon from H->ZZ->4l decay! "  << SLogger::endmsg;  
    	       n_muons++; 	     
 	       continue;	     
	   }			 


	   //Then look for taus.... 
	   if ((tparts[l_index]->pdgId() == PDG::tau_minus  ||
  	        tparts[l_index]->pdgId() == PDG::tau_plus  )) {

	       m_logger << DEBUG << "Found tau from H->ZZ->4l decay! "  << SLogger::endmsg;  			 
    	       n_taus++;
	       continue; 	     
	   }
	 }
      }
  }
  
  if ((n_electrons + n_muons + n_taus)!= 4) {
     m_logger << DEBUG << "Found " << n_electrons + n_muons + n_taus<< " leptons.  Check your code!" << SLogger::endmsg;    
  }
  
  if (n_muons == 4)                     return 0;
  if (n_electrons == 4)                 return 1;
  if (n_muons == 2 && n_electrons == 2) return 2;
  if (n_taus != 0)                      return 4;
  
  m_logger << DEBUG << "Unclassified event! Returning -1" << SLogger::endmsg;    
  return -1;  
}


//____________________________________________________________________________
TruthParticle* TruthSelector::GetTruthHiggs( std::vector<TruthParticle*> &tparts ){
  
  for (unsigned int i = 0; i < tparts.size(); i++) {
    if (tparts[i]->pdgId() == PDG::Higgs0 && tparts[i]->status() == 62 ) {
	
	m_logger << DEBUG << "Found Higgs Truth Particle" << SLogger::endmsg;  
	return tparts[i];
    }      
  }
  
  return 0;  
}

//____________________________________________________________________________
TruthParticle* TruthSelector::GetTruthZ( int index, std::vector<TruthParticle*> &tparts ){
  
  bool higgs_evt = (GetTruthHiggs(tparts) != 0);
    
  std::vector<TruthParticle*> truth_Zs;
  for (unsigned int i = 0; i < tparts.size(); i++) {
    if (!(tparts[i]->pdgId() == PDG::Z0)) continue;
    m_logger << DEBUG << "Found Z0 Truth Particle with status="<<tparts[i]->status() << SLogger::endmsg;  

    if (tparts[i]->status()!=22 && higgs_evt)    continue;
    	
    bool associated_z = false;	
    std::vector<int> children = tparts[i]->child_index();
    if (children.size() == 0) associated_z = true;    
    for (unsigned int j = 0; j < children.size(); j++) {
       if (tparts[children[j]]->pdgId()== PDG::Z0){
         associated_z = true;
	 break;
       }
    }    
    if (associated_z) continue;
    
    m_logger << DEBUG << "Found Z0 Truth Particle" << SLogger::endmsg;  
    truth_Zs.push_back( tparts[i] );	             
  }
  
  TruthParticle* truth_z = 0;
  		  
  if (truth_Zs.size() != 2){
     m_logger << WARNING << "Found " << truth_Zs.size() << " Z0 Truth Particles.  Looking for 2!" << SLogger::endmsg;      
  } else {
      if (index == 0) {
        truth_z = fabs(truth_Zs[0]->m() - 91187.6) > fabs(truth_Zs[1]->m() - 91187.6) ? truth_Zs[1]: truth_Zs[0];
      } else {
        truth_z = fabs(truth_Zs[0]->m() - 91187.6) > fabs(truth_Zs[1]->m() - 91187.6) ? truth_Zs[0]: truth_Zs[1];      
      }
  }
  
  return truth_z;  
}


//____________________________________________________________________________
TruthParticle* TruthSelector::GetTruthLepton( int index, std::vector<TruthParticle*> &tparts ){
  
  TruthParticle* truth_z = GetTruthZ( index/2,  tparts );
  
  if (!truth_z){
     m_logger << DEBUG << "Did not find truth Z.  Cannot return truth lepton." << SLogger::endmsg;      
     return 0;  
  }
  
  //now find specified lepton child
  std::vector<int> children = truth_z->child_index();
  TruthParticle* lepton = 0;
  int charge = (index % 2 == 0) ? +1 : -1;     
  
  if (children.size() == 2) { //easy case!    
     if (tparts[children[0]]->charge() == charge)      lepton = tparts[children[0]]; 
     else if (tparts[children[1]]->charge() == charge) lepton = tparts[children[1]];
     else {
        m_logger << ERROR << "Unable to match charge of truth lepton!" << SLogger::endmsg;         
     }
     return lepton;           
  }  
  
  //more than 2 children - must check status to choose born level!
  std::vector<TruthParticle*> leptons_status1;
  std::vector<TruthParticle*> leptons_status2;
  std::vector<TruthParticle*> leptons_status3;
  std::vector<TruthParticle*> leptons_statusother;
  for (unsigned int i = 0; i < children.size(); i++) {

     if(( tparts[children[i]]->pdgId() == PDG::e_minus   ||
  	  tparts[children[i]]->pdgId() == PDG::e_plus	 ||
  	  tparts[children[i]]->pdgId() == PDG::mu_minus  ||
  	  tparts[children[i]]->pdgId() == PDG::mu_plus	 ||
  	  tparts[children[i]]->pdgId() == PDG::tau_minus ||
  	  tparts[children[i]]->pdgId() == PDG::tau_plus	)
	   && (tparts[children[i]]->charge() == charge )) {
	  
	  if (tparts[children[i]]->status() == 1) leptons_status1.push_back(tparts[children[i]]);    	  
	  else if (tparts[children[i]]->status() == 2) leptons_status2.push_back(tparts[children[i]]);    
	  else if (tparts[children[i]]->status() == 3) leptons_status3.push_back(tparts[children[i]]);    
	  else leptons_statusother.push_back(tparts[children[i]]);    
    }    
  }
  
  //preferentially choose leptons by status:  3, 1, 2, other
  if (leptons_status3.size() != 0){//leptons before radiation
     if (leptons_status3.size() == 1) lepton = leptons_status3[0]; 
     else m_logger << ERROR << "More than 1 status 3 truth lepton!" << SLogger::endmsg;       
  } else if (leptons_status1.size() != 0){//final state leptons
     if (leptons_status1.size() == 1) lepton = leptons_status1[0]; 
     else m_logger << ERROR << "More than 1 status 1 truth lepton!" << SLogger::endmsg;       
  } else if (leptons_status2.size() != 0){//taus!
     if (leptons_status2.size() == 1) lepton = leptons_status2[0]; 
     else m_logger << ERROR << "More than 1 status 2 truth lepton!" << SLogger::endmsg;       
  } else if (leptons_statusother.size() != 0){//taus!
     if (leptons_statusother.size() == 1) lepton = leptons_statusother[0]; 
     else m_logger << ERROR << "More than 1 status >3 truth lepton!" << SLogger::endmsg;       
  } else {
     m_logger << ERROR << "Unable to determine truth lepton!" << SLogger::endmsg;  
     m_logger << ERROR << "Found "<< leptons_status1.size() <<" status 1, " <<leptons_status2.size() <<" status 2, and "<< leptons_status3.size()<<" status 3 daughter leptons" << SLogger::endmsg;  
     m_logger << ERROR << "Z has "<< children.size() <<" children" << SLogger::endmsg;  
     for (unsigned int i = 0; i < children.size(); i++) {
       m_logger << ERROR << tparts[children[i]]->pdgId()<<" "<< tparts[children[i]]->status()<< SLogger::endmsg;  
     }
  } 
     
  return lepton;  
}

//____________________________________________________________________________
bool TruthSelector::Mispaired( std::vector<TruthParticle*> &quad) {
  
  if (quad.size() != 4) return true;
  
  for (unsigned int i = 0; i < quad.size(); i++) {
    if(!quad[i])return true;
  } 
  
  bool mispaired = false;
    
  if (quad[0]->parent_index().size() != 0 && quad[1]->parent_index().size() != 0) {
    if (quad[0]->parent_index()[0] != quad[1]->parent_index()[0]) mispaired = true;       
  }
    
  if (quad[2]->parent_index().size() != 0 && quad[3]->parent_index().size() != 0) {
    if (quad[2]->parent_index()[0] != quad[3]->parent_index()[0]) mispaired = true;       
  }

  return mispaired;  
}

//____________________________________________________________________________
bool TruthSelector::HiggsQuad(std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &quad) {

  if (quad.size() != 4) return false;

  if (GetTruthHiggs(tparts) == 0) return false;
  
  TruthParticle* Z1 = GetTruthZ( 0,  tparts );
  TruthParticle* Z2 = GetTruthZ( 1,  tparts );
 
  bool higgs_quad = true;
  
  for (unsigned int i = 0; i < quad.size(); i++) {
    if(!quad[i]){
      higgs_quad = false;
      break;    
    }
    
    if (quad[i]->parent_index().size() == 0) {
      higgs_quad = false;
      break;
    }
    
    if ( quad[i]->parent_index()[0] != int(Z1->GetIndex()) && 
         quad[i]->parent_index()[0] != int(Z2->GetIndex()) ) {
      higgs_quad = false;
      break;
    }
  }
  
  return higgs_quad;
}

//____________________________________________________________________________
int TruthSelector::MatchElectron( Electron* electron, std::vector<TruthParticle*> &tparts ) {
  
  double delta_r = -1;
  int matched_index = -1;

  for (unsigned int i = 0; i < tparts.size(); i++) {

    if (tparts[i]->status() != 1) continue;

    if (!(tparts[i]->pdgId() == PDG::e_minus || tparts[i]->pdgId() == PDG::e_plus)) continue;
   
    double t_delta_r = electron->TLV()->DeltaR(tparts[i]->TLV());
    if (delta_r == -1 || t_delta_r < delta_r) {
       delta_r = t_delta_r;
       matched_index = i;
    }  
  }
  
  if ((matched_index != -1) &&   delta_r < 0.05) {
    m_logger << DEBUG << "Matched electron to truth electron.  delta_r = " << delta_r << SLogger::endmsg;                
  } else {
    m_logger << DEBUG << "Unable to match electron to truth electron" << SLogger::endmsg;                
  }  
  
  return matched_index;
}

//____________________________________________________________________________
int TruthSelector::MatchBornElectron( Electron* electron, std::vector<TruthParticle*> &tparts ) {
  
  //double delta_r = -1;
  double max_energy = 0;
  int matched_index = -1;

  for (unsigned int i = 0; i < tparts.size(); i++) {

    if (!(tparts[i]->pdgId() == PDG::e_minus || tparts[i]->pdgId() == PDG::e_plus)) continue;
        
    if (electron->TLV()->DeltaR(tparts[i]->TLV()) > 0.1) continue;
     
    if (tparts[i]->TLV().E() > max_energy) {
       max_energy = tparts[i]->TLV().E();
       matched_index = i;
    }
  }
  
  if (matched_index != -1) {
    m_logger << DEBUG << "Matched electron to truth muon. " << SLogger::endmsg;                
  } else {
    m_logger << DEBUG << "Unable to match electron to truth electron" << SLogger::endmsg;                
  }  
  
  return matched_index;
}

//____________________________________________________________________________
int TruthSelector::MatchMuon( Muon* muon, std::vector<TruthParticle*> &tparts ) {
  
  double delta_r = -1;
  int matched_index = -1;

  for (unsigned int i = 0; i < tparts.size(); i++) {

    if (tparts[i]->status() != 1) continue;

    if (!(tparts[i]->pdgId() == PDG::mu_minus || tparts[i]->pdgId() == PDG::mu_plus)) continue;

    double t_delta_r = muon->TLV()->DeltaR(tparts[i]->TLV());
    if (delta_r == -1 || t_delta_r < delta_r) {
       delta_r = t_delta_r;
       matched_index = i;
    }  
  }
  
  if ((matched_index != -1) &&   delta_r < 0.05) {
    m_logger << DEBUG << "Matched muon to truth muon.  delta_r = " << delta_r << SLogger::endmsg;                
  } else {
    m_logger << DEBUG << "Unable to match muon to truth muon" << SLogger::endmsg;
    matched_index = -1;                
  }  
  
  return matched_index;
}

//____________________________________________________________________________
int TruthSelector::MatchBornMuon( Muon* muon, std::vector<TruthParticle*> &tparts ) {
  
  //double delta_r = -1;
  double max_energy = 0;
  int matched_index = -1;

  for (unsigned int i = 0; i < tparts.size(); i++) {

    if (!(tparts[i]->pdgId() == PDG::mu_minus || tparts[i]->pdgId() == PDG::mu_plus)) continue;
    
    if (muon->TLV()->DeltaR(tparts[i]->TLV()) > 0.1) continue;
     
    if (tparts[i]->TLV().E() > max_energy) {
       max_energy = tparts[i]->TLV().E();
       matched_index = i;
    }
  }
  
  if (matched_index != -1) {
    m_logger << DEBUG << "Matched muon to truth muon." << SLogger::endmsg;                
  } else {
    m_logger << DEBUG << "Unable to match muon to truth muon" << SLogger::endmsg;
  }  
  
  return matched_index;
}

//____________________________________________________________________________
void TruthSelector::GetPairedTruthQuad( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &quad ) {
  
  //find all final state leptons
  std::vector<TruthParticle*> leptons;
  for (unsigned int i = 0; i < tparts.size(); i++){
    if ( tparts[i]->status() != 1 ) continue;  
    if (!( tparts[i]->pdgId() == PDG::e_minus  || tparts[i]->pdgId() == PDG::e_plus 
	|| tparts[i]->pdgId() == PDG::mu_minus || tparts[i]->pdgId() == PDG::mu_plus ) ) continue;
    
    leptons.push_back(tparts[i]);    
  }
  
  if (leptons.size() < 4){
    m_logger << DEBUG << "Only "<<leptons.size() << "status 1 leptons. Returning" << SLogger::endmsg;        
    return;
  }
  
  PairLeptons(leptons, quad);
  
  return;  
}

//____________________________________________________________________________
void TruthSelector::GetMatchedTruthQuad( Quadruplet* quad,  std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &matched_quad ) {

  std::vector<Muon*> muons;
  quad->GetMuons(muons);

  std::vector<Electron*> electrons;
  quad->GetElectrons(electrons);

  if (quad->Type() == Quadruplet::TwoElectronTwoMuon) {
    for (unsigned int i = 0; i < electrons.size(); i++) {
      int index = MatchElectron( electrons[i], tparts); 
      matched_quad.push_back(index != -1 ? tparts[index] : 0);
    }     
    for (unsigned int i = 0; i < muons.size(); i++) {
      int index = MatchMuon( muons[i], tparts); 
      matched_quad.push_back(index != -1 ? tparts[index] : 0);
    } 

  } else {
    for (unsigned int i = 0; i < muons.size(); i++) {
      int index = MatchMuon( muons[i], tparts); 
      matched_quad.push_back(index != -1 ? tparts[index] : 0);
    } 
    for (unsigned int i = 0; i < electrons.size(); i++) {
      int index = MatchElectron( electrons[i], tparts); 
      matched_quad.push_back(index != -1 ? tparts[index] : 0);
    }	  	  
  }  
  
  return;
}

//____________________________________________________________________________
void TruthSelector::GetMatchedBornTruthQuad( Quadruplet* quad,  std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &matched_quad ) {

  std::vector<Muon*> muons;
  quad->GetMuons(muons);

  std::vector<Electron*> electrons;
  quad->GetElectrons(electrons);

  if (quad->Type() == Quadruplet::TwoElectronTwoMuon) {
    for (unsigned int i = 0; i < electrons.size(); i++) {
      int index = MatchBornElectron( electrons[i], tparts); 
      matched_quad.push_back(index != -1 ? tparts[index] : 0);
    }     
    for (unsigned int i = 0; i < muons.size(); i++) {
      int index = MatchBornMuon( muons[i], tparts); 
      matched_quad.push_back(index != -1 ? tparts[index] : 0);
    } 

  } else {
    for (unsigned int i = 0; i < muons.size(); i++) {
      int index = MatchBornMuon( muons[i], tparts); 
      matched_quad.push_back(index != -1 ? tparts[index] : 0);
    } 
    for (unsigned int i = 0; i < electrons.size(); i++) {
      int index = MatchBornElectron( electrons[i], tparts); 
      matched_quad.push_back(index != -1 ? tparts[index] : 0);
    }	  	  
  }  
  
  return;
}

//____________________________________________________________________________
void TruthSelector::GetBornTruthQuad( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &quad ) {

  for (unsigned int i = 0; i < 4; i++){  
    TruthParticle* part = GetTruthLepton(i, tparts);
    if (part) quad.push_back( part );
  }
  
  return;
}

//____________________________________________________________________________
void TruthSelector::PairLeptons( std::vector<TruthParticle*> &leptons, std::vector<TruthParticle*> &paired_quad ) {
  
  paired_quad.clear();

  const double M_Z = 91187.6;

  int paired_index_l1 = -1;
  int paired_index_l2 = -1;
  int paired_index_l3 = -1;
  int paired_index_l4 = -1;

  //determine l1 and l2 first
  double smallest_mass_diff = -1;
  for (unsigned int i = 0; i < leptons.size(); i++){
    for (unsigned int j = 0; j < leptons.size(); j++){

      if (i>=j) continue;//don't pair a lepton with itself
      
      if (leptons[i]->pdgId() != -1*leptons[j]->pdgId()) continue; //only pair same flavor opposite sign leptons
      
      double mass_diff = fabs((leptons[i]->Dressed_TLV()+leptons[j]->Dressed_TLV()).M() - M_Z);
      if (smallest_mass_diff == -1 || mass_diff < smallest_mass_diff){
	smallest_mass_diff = mass_diff;
        paired_index_l1 = leptons[i]->charge() == +1 ? i : j;
	paired_index_l2 = leptons[i]->charge() == +1 ? j : i;	
      }
    }
  }

  m_logger << DEBUG << "paired_index_l1="<<paired_index_l1<<" paired_index_l2="<<paired_index_l2 << SLogger::endmsg;        
  
  //check for failed pairing
  if (paired_index_l1 == -1 || paired_index_l2 == -1) return;

  //determine l3 and l4 second
  smallest_mass_diff = -1;
  for (unsigned int i = 0; i < leptons.size(); i++){
    
    if (int(i) == paired_index_l1 || int(i) == paired_index_l2) continue;

    for (unsigned int j = 0; j < leptons.size(); j++){

      if (i>=j) continue;//don't pair a lepton with itself
      
      if (int(j) == paired_index_l1 || int(j) == paired_index_l2) continue;

      if (leptons[i]->pdgId() != -1*leptons[j]->pdgId()) continue; //only pair same flavor opposite sign leptons
      
      double mass_diff = fabs((leptons[i]->Dressed_TLV()+leptons[j]->Dressed_TLV()).M() - M_Z);
      if (smallest_mass_diff == -1 || mass_diff < smallest_mass_diff){
	smallest_mass_diff = mass_diff;
        paired_index_l3 = leptons[i]->charge() == +1 ? i : j;
	paired_index_l4 = leptons[i]->charge() == +1 ? j : i;	
      }
    }
  }

  m_logger << DEBUG << "paired_index_l3="<<paired_index_l3<<" paired_index_l4="<<paired_index_l4 << SLogger::endmsg;        
  
  if (paired_index_l3 == -1 || paired_index_l4 == -1 )return;

  paired_quad.push_back( leptons[paired_index_l1]);
  paired_quad.push_back( leptons[paired_index_l2]);
  paired_quad.push_back( leptons[paired_index_l3]);
  paired_quad.push_back( leptons[paired_index_l4]);
  
  return;
}


//____________________________________________________________________________         
double TruthSelector::HiggsPtWeight(int mc_channel, std::vector<TruthParticle*> &tparts, std::vector<Jet> &jets ){
 
  //weight only applies to ggH modes
  if (! ( mc_channel == 160155 ||
	  mc_channel == 167220 ||
	  mc_channel == 167222 ||
	  mc_channel == 160155 ||
	  mc_channel == 167225 ||
	  mc_channel == 167227 ||
	  mc_channel == 160156 ) ) {
    return 1.0;
  } 
  
  int nJetsTruth = 0;
  
  //get Higgs leptons for overlap removal
  std::vector<TruthParticle*> quad;
  GetBornTruthQuad( tparts, quad );
  
  for(std::vector<Jet>::iterator itr = jets.begin(); itr != jets.end(); ++itr) {
  
    if((*itr).pt() < 25000) continue; 
    
    bool overlap = false;
    
    for (unsigned int i = 0; i<quad.size(); i++){
      if (quad[i]->TLV().DeltaR((*itr).TLV()) < 0.4){
         overlap = true;
	 break; 
      }
    }
    
    if (overlap) continue;

    nJetsTruth++;     
  }
  
  TruthParticle* higgs = GetTruthHiggs(tparts);
  
  if (!higgs) return 1.0;
  
  double trueHiggsPt = higgs->pt(); 
  
  return nJetsTruth < 2 ?
	   m_ggF_HpT_weight_01jets->Interpolate(trueHiggsPt/1000):
	   m_ggF_HpT_weight_geq2jets->Interpolate(trueHiggsPt/1000);

}



/*
//____________________________________________________________________________
TLorentzVector TruthSelector::MatchedQuad( Quadruplet* quad, std::vector<TruthParticle*> &tparts ) {

  TLorentzVector tlv_4l(0,0,0,0);

  std::vector<Muon*> muons;
  quad->GetMuons(muons);

  int n_matched = 0;
  
  m_logger << DEBUG << "muons.size(): "<< muons.size() << SLogger::endmsg;                

  for (unsigned int i = 0; i < muons.size(); i++) {
    int index = MatchMuon( muons[i], tparts); 

    if (index != -1){
      n_matched++;
      tlv_4l += tparts[index]->TLV();
    }
  } 

  std::vector<Electron*> electrons;
  quad->GetElectrons(electrons);

  m_logger << DEBUG << "electrons.size(): "<< electrons.size() << SLogger::endmsg;                

  for (unsigned int i = 0; i < electrons.size(); i++) {
    int index = MatchElectron( electrons[i], tparts); 

    if (index != -1){
      n_matched++;
      tlv_4l += tparts[index]->TLV();
    }
  } 
  
  if (n_matched != 4) {
    m_logger << DEBUG << "Able to truth match only " << n_matched <<" leptons in quadruplet" << SLogger::endmsg;                
    
    return TLorentzVector(0,0,0,0);
  }

  return tlv_4l;
}


//____________________________________________________________________________
TLorentzVector TruthSelector::MatchedZ1( Quadruplet* quad, std::vector<TruthParticle*> &tparts ) {

  TLorentzVector tlv_z1(0,0,0,0);
  
  std::vector<Muon*> muons;
  quad->GetMuons(muons);

  int n_matched = 0;
  
  m_logger << DEBUG << "muons.size(): "<< muons.size() << SLogger::endmsg;                
  if (quad->Type() == Quadruplet::FourMuon || quad->Type() == Quadruplet::TwoMuonTwoElectron) { 
    for (unsigned int i = 0; i < 2; i++) {
      int index = MatchMuon( muons[i], tparts); 

      if (index != -1){
        n_matched++;
	tlv_z1 += tparts[index]->TLV();
      }
    } 
  }
  
  std::vector<Electron*> electrons;
  quad->GetElectrons(electrons);

  m_logger << DEBUG << "electrons.size(): "<< electrons.size() << SLogger::endmsg;                

  if (quad->Type() == Quadruplet::FourElectron || quad->Type() == Quadruplet::TwoElectronTwoMuon) { 
    for (unsigned int i = 0; i < 2; i++) {
      int index = MatchElectron( electrons[i], tparts); 

      if (index != -1){
        n_matched++;
	tlv_z1 += tparts[index]->TLV();
      }
    } 
  }

  if (n_matched != 2) {
    m_logger << DEBUG << "Able to truth match only " << n_matched <<" leptons for Z1" << SLogger::endmsg;                
    
    return TLorentzVector(0,0,0,0);
  }

  return tlv_z1;
}

//____________________________________________________________________________
TLorentzVector TruthSelector::MatchedZ2( Quadruplet* quad, std::vector<TruthParticle*> &tparts ) {

  TLorentzVector tlv_z2(0,0,0,0);

  std::vector<Muon*> muons;
  quad->GetMuons(muons);

  int n_matched = 0;
  
  m_logger << DEBUG << "muons.size(): "<< muons.size() << SLogger::endmsg;                
  if (quad->Type() == Quadruplet::FourMuon || quad->Type() == Quadruplet::TwoElectronTwoMuon) { 
    unsigned int min = quad->Type() == Quadruplet::FourMuon ? 2 : 0;
    unsigned int max = quad->Type() == Quadruplet::FourMuon ? 4 : 2;

    for (unsigned int i = min; i < max; i++) {
      int index = MatchMuon( muons[i], tparts); 

      if (index != -1){
        n_matched++;
	tlv_z2 += tparts[index]->TLV();
      }
    }     
  }
  
  std::vector<Electron*> electrons;
  quad->GetElectrons(electrons);

  m_logger << DEBUG << "electrons.size(): "<< electrons.size() << SLogger::endmsg;                

  if (quad->Type() == Quadruplet::FourElectron || quad->Type() == Quadruplet::TwoMuonTwoElectron) { 
    unsigned int min = quad->Type() == Quadruplet::FourElectron ? 2 : 0;
    unsigned int max = quad->Type() == Quadruplet::FourElectron ? 4 : 2;
    
    for (unsigned int i = min; i < max; i++) {
      int index = MatchElectron( electrons[i], tparts); 

      if (index != -1){
        n_matched++;
	tlv_z2 += tparts[index]->TLV();
      }
    } 
  }
  
  if (n_matched != 2) {
    m_logger << DEBUG << "Able to truth match only " << n_matched <<" leptons for Z2" << SLogger::endmsg;                    
    return TLorentzVector(0,0,0,0);
  }

  return tlv_z2;
}

*/
