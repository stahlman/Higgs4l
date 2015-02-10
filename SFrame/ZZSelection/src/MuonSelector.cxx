// $Id: MuonSelector.cxx 26089 2014-01-31 23:14:19Z stahlman $

#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Muon.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "EnergyRescalerTool.h"

// Local include(s):
#include "../include/MuonSelector.h"


const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( MuonSelector );

MuonSelector::MuonSelector(SCycleBase* parent, const char* name)
  : ToolBase( parent, name ),
    cf_preselect(0),
    cf_author(0),
    cf_momentum(0),
    cf_eta(0),
    cf_blayer(0),
    cf_pixel(0),
    cf_sct(0),
    cf_holes(0),
    cf_trt(0),
    cf_d0z0(0),
    cf_overlap(0),
    cf_isolation(0)

{
  DeclareProperty( "SelectCombinedMuons", 	m_selectCombinedMuons = true );
  DeclareProperty( "SelectSegmentTaggedMuons", 	m_selectSegmentTaggedMuons = true );
  DeclareProperty( "SelectStandAloneMuons", 	m_selectStandAloneMuons = true );
  DeclareProperty( "SelectCaloMuons", 		m_selectCaloMuons = true );

  DeclareProperty( "IsolationConeSize", m_cone_size = 20 );

  DeclareProperty( "DoBLayerCut", m_doBLayerCut = false );

  DeclareProperty( "DoSmear", m_doSmear = true );

  DeclareProperty( "DoTrackIsolation", m_doTrkIso = false );
  DeclareProperty( "DoCaloIsolation",  m_doCaloIso = false );
  DeclareProperty( "DoD0",  m_doD0 = false );

  return;
  
}

MuonSelector::~MuonSelector() {

 return;

}

void MuonSelector::BeginMasterInputData( const SInputData& ) throw( SError ){

  
  return;
  
}

void MuonSelector::EndMasterInputData( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                  H -> ZZ Muon Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of muons passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons Before Cuts..........:"<<cf_preselect  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Author..........:"<<cf_author     <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)"  <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Momentum........:"<<cf_momentum   <<" ("<<((double)cf_momentum)/((double)cf_author)*100 <<"%)"  <<" ("<<((double)cf_momentum)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Eta.............:"<<cf_eta	   <<" ("<<((double)cf_eta)/((double)cf_momentum)*100 <<"%)"	 <<" ("<<((double)cf_eta)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After B-Layer.........:"<<cf_blayer     <<" ("<<((double)cf_blayer)/((double)cf_eta)*100 <<"%)" <<" ("<<((double)cf_blayer)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Pixel...........:"<<cf_pixel	   <<" ("<<((double)cf_pixel)/((double)cf_blayer)*100 <<"%)" <<" ("<<((double)cf_pixel)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After SCT.............:"<<cf_sct	   <<" ("<<((double)cf_sct)/((double)cf_pixel)*100 <<"%)"  <<" ("<<((double)cf_sct)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Si Holes........:"<<cf_holes	   <<" ("<<((double)cf_holes)/((double)cf_sct)*100 <<"%)"  <<" ("<<((double)cf_holes)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After TRT Hits........:"<<cf_trt	   <<" ("<<((double)cf_trt)/((double)cf_holes)*100 <<"%)"  <<" ("<<((double)cf_trt)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After D0/Z0...........:"<<cf_d0z0	   <<" ("<<((double)cf_d0z0)/((double)cf_trt)*100 <<"%)"  <<" ("<<((double)cf_d0z0)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Overlap Removal.:"<<cf_overlap    <<" ("<<((double)cf_overlap)/((double)cf_d0z0)*100 <<"%)"  <<" ("<<((double)cf_overlap)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After El OL Removal...:"<<cf_emu_overlap    <<" ("<<((double)cf_emu_overlap)/((double)cf_overlap)*100 <<"%)"  <<" ("<<((double)cf_emu_overlap)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  //m_logger << ALWAYS <<"Muons After Jet OL Removal..:"<<cf_jetmu_overlap    <<" ("<<((double)cf_jetmu_overlap)/((double)cf_emu_overlap)*100 <<"%)"  <<" ("<<((double)cf_jetmu_overlap)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  if (m_doCaloIso) {  
  m_logger << ALWAYS <<"Muons After Isolation.......:"<<cf_isolation    <<" ("<<((double)cf_isolation)/((double)cf_overlap)*100 <<"%)"  <<" ("<<((double)cf_isolation)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  }
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;


  return;

}

void MuonSelector::SelectMuons( std::vector<Muon*>& sel_muons, const D3PDReader::MuonD3PDObject* m_muon_d3pdobject, const D3PDReader::MuonD3PDObject* m_muon_calo_d3pdobject, unsigned int evt_number ) {

  //Muon Selection
  m_logger << ::DEBUG << "Muon Selection " << SLogger::endmsg;
  
  // select muons 
  std::vector<Muon> all_muons;
  ParticleElementBuilder::build( all_muons, (*m_muon_d3pdobject) );

  std::vector<Muon> all_calo_muons;
  if(m_selectCaloMuons) ParticleElementBuilder::build( all_calo_muons, (*m_muon_calo_d3pdobject) );
  
  m_logger << ::DEBUG << "Number of muons in event: " << all_muons.size() + all_calo_muons.size()<< SLogger::endmsg;
  
  
  // select CB+ST muons first (for overlap removal later)
  for(std::vector<Muon>::iterator itr = all_muons.begin(); itr != all_muons.end(); ++itr) {  
 
     cf_preselect++;
     
     //Staco CB+ST muons      
     if (!(((*itr).author() == 6 || (*itr).author() == 7)  && ((*itr).isStandAloneMuon() == 0))) continue;      
     
     if ((*itr).author() == 6 && m_selectCombinedMuons == false) continue;
     if ((*itr).author() == 7 && m_selectSegmentTaggedMuons == false) continue;
     cf_author++;
     
     //smear momentum (MC only)
     if (m_doSmear) {
       GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
       energy_rescaler->ApplyEnergyRescaler( (*itr), evt_number);          
     }
     
     //pt cut
     if(!((*itr).Pt() > 6000.0 )) continue;     
     cf_momentum++;

     //eta cut
     if(!( fabs((*itr).eta()) < 2.7)) continue;        
     cf_eta++;
	 
     //ID hit cuts
     if( m_doBLayerCut && !( !(*itr).expectBLayerHit() || ((*itr).nBLHits() > 0 )))continue;
     cf_blayer++;

     if( !((*itr).nPixHits() + (*itr).nPixelDeadSensors() > 0 ))continue;
     cf_pixel++;

     if( !((*itr).nSCTHits() + (*itr).nSCTDeadSensors() > 4 ))continue;
     cf_sct++;

     if( !((*itr).nPixHoles()+ (*itr).nSCTHoles() < 3 )) continue;	   
     cf_holes++;

     int ntrt = (*itr).nTRTHits() + (*itr).nTRTOutliers();
     if ( (fabs((*itr).eta()) > 0.1) && (fabs((*itr).eta()) < 1.9)){ 
         if ( !((ntrt > 5.0) && ((*itr).nTRTOutliers() < 0.9*ntrt))) continue;
     }
     cf_trt++;
     	      
     //d0 cut
     if (!(fabs((*itr).D0()) < 1.0 )) continue;

     //z0 cut
     if (!(fabs((*itr).Z0()) < 10.0 )) continue;
     cf_d0z0++;
     
     //no overlap removal		  
     cf_overlap++;

     //increment for now
     cf_emu_overlap++;
     cf_jetmu_overlap++;
     
    //isolation cuts
    if (m_doTrkIso) {
       double trk_iso = (*itr).ptcone(m_cone_size);

       if (!(trk_iso/(*itr).Pt() < 0.15)) continue;
    }
    
    if (m_doCaloIso) {
       double calo_iso = (*itr).etcone(m_cone_size);

       if (!(calo_iso/(*itr).Pt() < 0.30)) continue;
    }
    cf_isolation++;
    
    //d0 cut
    if (m_doD0) {
      if (!((*itr).D0Significance() < 3.5)) continue;
    }
     //Good muon!
     sel_muons.push_back( new Muon(*itr) );

  }// loop over muons
  
  //CaloTag Muons  
  for(std::vector<Muon>::iterator itr = all_calo_muons.begin(); itr != all_calo_muons.end(); ++itr) {  

     cf_preselect++;

     //select CaloTag muons       
     if (!( ((*itr).isCaloMuon()) && ((*itr).caloMuonIdTag() > 10 || (*itr).caloLRLikelihood() > 0.9 ))) continue;
     cf_author++;
     
     //smear momentum (MC only)
     if (m_doSmear) {
       GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
       energy_rescaler->ApplyEnergyRescaler( (*itr), evt_number);          
     }
     
     //pt cut
     if (!((*itr).Pt() > 15000)) continue;
     cf_momentum++;
     
     //eta cut
     if (!(fabs((*itr).eta()) < 0.1)) continue;	 
     cf_eta++;
	 
     //ID hit cuts
     if( m_doBLayerCut && !( !(*itr).expectBLayerHit() || ((*itr).nBLHits() > 0 )))continue;
     cf_blayer++;

     if( !((*itr).nPixHits() + (*itr).nPixelDeadSensors() > 0 ))continue;
     cf_pixel++;

     if( !((*itr).nSCTHits() + (*itr).nSCTDeadSensors() > 4 ))continue;
     cf_sct++;

     if( !((*itr).nPixHoles()+ (*itr).nSCTHoles() < 3 )) continue;	   
     cf_holes++;

     //automatically passes trt cuts (TRT cuts only for eta > 0.1)
     cf_trt++;
          
     //d0
     if (!(fabs((*itr).D0()) < 1.0 )) continue;
       
     //z0
     if (!(fabs((*itr).Z0()) < 10.0 )) continue;
     cf_d0z0++;
     
     //overlap removal
     bool overlap_pass = true;
     for (unsigned int i = 0; i < sel_muons.size(); i++){
	if (CalculateDeltaR(sel_muons.at(i),(*itr),1) < 0.1) overlap_pass = false;
     }
     if (!overlap_pass) continue;
     cf_overlap++;

     //increment for now
     cf_emu_overlap++;
     
     //isolation cuts
     if (m_doTrkIso) {
	if (!((*itr).ptcone(m_cone_size)/(*itr).Pt() < 0.15)) continue;
     }

     if (m_doCaloIso) {
	if (!((*itr).etcone(m_cone_size)/(*itr).Pt() < 0.30)) continue;
     }
     cf_isolation++;

      //d0 cut
     if (m_doD0) {
       if (!((*itr).D0Significance() < 3.5)) continue;
     }

     //Good Muon!
     sel_muons.push_back( new Muon(*itr) );
  }
  
  //Standalone muons
  if(m_selectStandAloneMuons) {
  for(std::vector<Muon>::iterator itr = all_muons.begin(); itr != all_muons.end(); ++itr) {  
            
     //Staco StandAlone muons      
     if (!(((*itr).author() == 6)  && ((*itr).isStandAloneMuon() == 1))) continue;        
     cf_author++;

     //smear momentum (MC only)
     if (m_doSmear) {
       GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
       energy_rescaler->ApplyEnergyRescaler( (*itr), evt_number);          
     }

     //pt cut
     if(!((*itr).Pt() > 6000)) continue;
     cf_momentum++;

     //eta cuts
     if(!((fabs((*itr).eta()) > 2.5) && (fabs((*itr).eta()) < 2.7))) continue;	 
     cf_eta++;

     //MS hits cut
     if (!(((*itr).nCSCEtaHits() + (*itr).nCSCPhiHits() > 0) && ((*itr).nMDTEMHits() > 0) && ((*itr).nMDTEOHits() > 0))) continue;
     cf_blayer++;
     cf_pixel++;
     cf_sct++;
     cf_holes++;
     cf_trt++;
     cf_d0z0++;

     //overlap removal
     bool overlap_pass = true;
     for (unsigned int i = 0; i < sel_muons.size(); i++){
	if ((sel_muons.at(i)->author() == 7) && (CalculateDeltaR(sel_muons.at(i),(*itr), 0) < 0.2)) overlap_pass = false;
     }

     if (!overlap_pass) continue;
     cf_overlap++;
    
     //increment for now
     cf_emu_overlap++;
    
     //isolation cuts
     if (m_doTrkIso) {
	if (!((*itr).ptcone(m_cone_size)/(*itr).Pt() < 0.15)) continue;
     }

     if (m_doCaloIso) {
	if (!((*itr).etcone(m_cone_size)/(*itr).Pt() < 0.15)) continue;
     }
     cf_isolation++;

     // no d0 significance cut for standalone muons

     //Good Muon!
     sel_muons.push_back( new Muon(*itr) );

  }}//loop over muons
 
  m_logger << ::DEBUG << "Number of selected muons in event: " << sel_muons.size() << SLogger::endmsg;
  
  return;

}

int MuonSelector::NumberAdditionalMuons( Quadruplet* quad, std::vector<Muon*> &sel_muons) {

  m_logger << ::DEBUG << "Entering NumberAdditionalMuons() "  << SLogger::endmsg;

  int n_add_muons = 0;
  
  std::vector<Muon*> quad_muons;
  quad->GetMuons(quad_muons);
  
  for(unsigned int i = 0; i < sel_muons.size(); ++i) { 
    
    //check first if muon already part of quad
    bool quad_m = false;
    for(unsigned int j = 0; j < quad_muons.size(); ++j) { 
       if ( sel_muons.at(i)->GetIndex() == quad_muons.at(j)->GetIndex() ){
         if (sel_muons.at(i)->author() == quad_muons.at(j)->author() ){
           quad_m = true;
	   break;
	 }
       }
    }
    if (quad_m) continue;
    
    m_logger << ::DEBUG << "pt cut "  << SLogger::endmsg;
    //pt cut
    if (!(sel_muons.at(i)->Pt() > 10000)) continue;
    
    m_logger << ::DEBUG << "trk iso cut "  << SLogger::endmsg;
    //track isolation cut
    double trk_iso = quad->CalculateTrkIso(sel_muons.at(i), 20);
    if (!(trk_iso < 0.15 )) continue;
    
    m_logger << ::DEBUG << "calo iso cut "  << SLogger::endmsg;
    //calo isolation
    double calo_iso = quad->CalculateCaloIso(sel_muons.at(i), 20, 18);    
    if ( sel_muons.at(i)->isStandAloneMuon() ){ 
      if (!(calo_iso < 0.15 ))  continue; 
    } else {
      if (!(calo_iso < 0.30 ))  continue; 
    }
    
    m_logger << ::DEBUG << "d0 significance cut "  << SLogger::endmsg;
    if (!(sel_muons.at(i)->D0Significance() < 3.5)) continue;
    
    n_add_muons++;        
        
  }
  
  return n_add_muons;  
}

void MuonSelector::RemoveElectronMuonOverlap(std::vector<Muon*> &sel_muons, std::vector<Electron*> &sel_electrons){

  for(unsigned int i = 0; i < sel_electrons.size(); ++i) { 
    for(unsigned int j = 0; j < sel_muons.size(); ++j) { 
      
      if (!sel_muons.at(j)->isCaloMuon()) continue;
      
      double deltaR = DeltaR(sel_electrons.at(i)->Unrefittedtrack_eta(), sel_electrons.at(i)->Unrefittedtrack_phi(),sel_muons.at(j)->id_eta(), sel_muons.at(j)->id_phi());
      
      if (deltaR < 0.02) { // remove  muon
           m_logger << ::DEBUG << "Removing Overlap Muon " << j << SLogger::endmsg;
       	   sel_muons.erase(sel_muons.begin()+j); 
	   j--;//subtract one from j to keep counting consistent
	   cf_emu_overlap--;      	 
      }      
    }
  }

  return;
} 

void MuonSelector::RemoveJetMuonOverlap(std::vector<Muon*> &sel_muons, std::vector<Jet*> &sel_jets){

  for(unsigned int i = 0; i < sel_jets.size(); ++i) { 
    for(unsigned int j = 0; j < sel_muons.size(); ++j) { 
      
      //if (!sel_muons.at(j)->isCaloMuon()) continue;
      
      double deltaR = sel_jets[i]->TLV().DeltaR(*sel_muons[j]->TLV());
      
      if (deltaR < 0.5) { // remove  muon
           m_logger << ::DEBUG << "Removing Overlap Muon " << j << SLogger::endmsg;
       	   sel_muons.erase(sel_muons.begin()+j); 
	   j--;//subtract one from j to keep counting consistent
	   cf_jetmu_overlap--;      	 
      }      
    }
  }

  return;
} 

double MuonSelector::CalculateDeltaR(Muon* m1, Muon m2, int track_params) {  
  
  if (track_params == 0){ //combined
    double delta_phi = (fabs(m1->phi() - m2.phi()) >  TMath::Pi()) ? 2*TMath::Pi()-fabs(m1->phi() - m2.phi()) : fabs(m1->phi() - m2.phi());
    double delta_eta = m1->eta() - m2.eta();
    return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
  }

  if (track_params == 1){ //id
    double delta_phi = (fabs(m1->id_phi() - m2.id_phi()) >  TMath::Pi()) ? 2*TMath::Pi()-fabs(m1->id_phi() - m2.id_phi()) : fabs(m1->id_phi() - m2.id_phi());
    //double delta_phi = m1->id_phi() - m2.id_phi();
    double delta_eta = (-log(tan(m1->id_theta()/2))) - (-log(tan(m2.id_theta()/2)));
    return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
  }
  
  m_logger << ::WARNING << "MuonSelector::CalculateDeltaR(): Unknown track parameters.  Returning 0" << SLogger::endmsg;
  return 0;
}

double MuonSelector::DeltaR(double eta1, double phi1, double eta2, double phi2) {      
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  double delta_eta = eta1 - eta2;  
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}

