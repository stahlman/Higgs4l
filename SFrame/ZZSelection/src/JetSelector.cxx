// $Id: JetSelector.cxx 26304 2014-02-26 21:37:57Z stahlman $

#include <math.h>
#include"TLorentzVector.h"

// Local include(s):
#include "../include/JetSelector.h"

//Common Tools
#include "EnergyRescalerTool.h"

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Jet.h"
#include "ParticleElementBuilder.h"


const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( JetSelector );

//____________________________________________________________________________         
JetSelector::JetSelector(SCycleBase* parent, const char* name)
  : ToolBase( parent, name ),
    cf_preselect(0),
    cf_jetcleaning(0),	
    cf_pt(0),	
    cf_eta(0),	
    cf_jvf(0),	
    cf_overlap(0)
{
  DeclareProperty( "RecoTreeString", m_recoTreeName = "physics");
  DeclareProperty( "DoLowPt",  m_doLowPt = false );  
  DeclareProperty( "CalibrateJets",  m_doJetCalibration = true );  
 
  return;  
}

//____________________________________________________________________________         
JetSelector::~JetSelector() {


 return;

}


//____________________________________________________________________________         
void JetSelector::BeginMasterInputData( const SInputData& ) throw( SError ){

  
  m_JVFTool = new JVFUncertaintyTool("AntiKt4TopoEM");
  
  return;
  
}


//____________________________________________________________________________         
void JetSelector::EndMasterInputData( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                  H -> ZZ jet Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of jets passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Jets Before Cuts................:"<<cf_preselect   <<SLogger::endmsg;
  m_logger << ALWAYS <<"Jets After eta, pT..............:"<<cf_pt          <<" ("<<((double)cf_pt)/((double)cf_preselect)*100 <<"%)" <<" ("<<((double)cf_pt)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  //m_logger << ALWAYS <<"jets After eta.............:"<<cf_eta	        <<" ("<<((double)cf_eta)/((double)cf_pt)*100 <<"%)" <<" ("<<((double)cf_eta)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Jets After JVF..................:"<<cf_jvf	        <<" ("<<((double)cf_jvf)/((double)cf_pt)*100 <<"%)"  <<" ("<<((double)cf_jvf)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Jets After Cleaning.............:"<<cf_jetcleaning      <<" ("<<((double)cf_jetcleaning)/((double)cf_jvf)*100 <<"%)"  <<" ("<<((double)cf_jetcleaning)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Jets After Hot Tile Cell Veto...:"<<cf_hottilecellveto      <<" ("<<((double)cf_hottilecellveto)/((double)cf_jetcleaning)*100 <<"%)"  <<" ("<<((double)cf_hottilecellveto)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Jets After Overlap...............:"<<cf_overlap	<<" ("<<((double)cf_overlap)/((double)cf_hottilecellveto)*100 <<"%)"  <<" ("<<((double)cf_overlap)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;


  return;

}

//____________________________________________________________________________         
void JetSelector::BeginInputFile( const SInputData& ) throw( SError )
{

  ConnectVariable( m_recoTreeName.c_str(), "Eventshape_rhoKt4EM", m_Eventshape_rhoKt4EM );

}


//____________________________________________________________________________         
void JetSelector::SelectJets( std::vector<Jet*> &sel_jets, const D3PDReader::JetD3PDObject* m_jet_d3pdobject, double mu, unsigned int npv, JetType jet_type, bool cutflow) {

  //jet selection
   m_logger << ::DEBUG << "Jet Selection " << SLogger::endmsg;
   
  std::vector<Jet> all_jets;
  ParticleElementBuilder::build( all_jets, (*m_jet_d3pdobject) );

  m_logger << ::DEBUG << "Number of jets in event: " << all_jets.size() << SLogger::endmsg;

  if(cutflow) cf_preselect += all_jets.size();
  
  if ( m_doJetCalibration ) { 
    GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
    energy_rescaler->ApplyEnergyRescaler(all_jets, mu, npv, m_Eventshape_rhoKt4EM);
  }
  
  SelectJets( all_jets, sel_jets, mu, npv, jet_type, cutflow);
  
  return;
}

//____________________________________________________________________________         
void JetSelector::SelectJets( std::vector<Jet> &all_jets, std::vector<Jet*> &sel_jets, double mu, unsigned int npv, JetType jet_type, bool cutflow, int syst) {

  m_logger << ::DEBUG << "Beginning jet selection for jet type: "<< jet_type << SLogger::endmsg;
  
  for(std::vector<Jet>::iterator itr = all_jets.begin(); itr != all_jets.end(); ++itr) {     
         
    bool pass_kin = false;        

    if(jet_type == LOWPT){
      if( fabs((*itr).eta()) < 2.5 && (*itr).Pt() > 7000) pass_kin = true;
    
    } else if(jet_type == DEFAULT){
      if( fabs((*itr).emscale_eta()) < 2.4 && (*itr).Pt() > 25000) pass_kin = true; 
      if( fabs((*itr).emscale_eta()) < 4.5 && fabs((*itr).emscale_eta()) > 2.4 && (*itr).Pt() > 30000) pass_kin = true;
    
    } else if(jet_type == HSG1){      
      if( fabs((*itr).Rapidity()) < 4.4 && (*itr).Pt() > 30000) pass_kin = true;
    
    } else {
      m_logger << ::WARNING << "Unknown jet type: "<< jet_type << SLogger::endmsg;
    }

    if (!pass_kin) {
      m_logger << ::DEBUG << "Jet "<< itr - all_jets.begin()<< " failed pt/eta cut" << SLogger::endmsg;
      continue;
    }
    if(cutflow) cf_pt++;

    bool pass_jvf = true;    
    double jvfcut = 1;
  
    if (jet_type == HSG1)    jvfcut = 0.25;
    if (jet_type == DEFAULT) jvfcut = 0.50;

    if (fabs((*itr).emscale_eta()) < 2.4 && (*itr).Pt() < 50000){ 
	
       if (syst == 1){ // Up variation
	 jvfcut = m_JVFTool->getJVFcut(jvfcut, false, (*itr).Pt(), (*itr).emscale_eta(), true);
       }
       if (syst == 2){ // Dn variation
	 jvfcut = m_JVFTool->getJVFcut(jvfcut, false, (*itr).Pt(), (*itr).emscale_eta(), false);
       }

       if (fabs((*itr).jvtxf()) < jvfcut) pass_jvf = false;
    }

    if (!pass_jvf) {
      m_logger << ::DEBUG << "Jet "<< itr - all_jets.begin()<< " failed jvf cut" << SLogger::endmsg;
      continue;
    }
    if(cutflow) cf_jvf++;

    if ((*itr).isBadLooseMinus()) {
      m_logger << ::DEBUG << "Jet "<< itr - all_jets.begin()<< " failed first jet cleaning cut" << SLogger::endmsg;
      continue;
    }
    if(cutflow) cf_jetcleaning++;

    double j_fmax= (*itr).fracSamplingMax();
    double j_smax= (*itr).SamplingMax();
    double j_eta = (*itr).eta();
    double j_phi = (*itr).phi();
    bool _etaphi28=false; 
    if(j_eta>-0.2 && j_eta<-0.1 && j_phi>2.65 && j_phi< 2.75 ) 
      _etaphi28=true;
    if (j_fmax>0.6 && j_smax==13 && _etaphi28) {
      m_logger << ::DEBUG << "Jet "<< itr - all_jets.begin()<< " failed second jet cleaning cut" << SLogger::endmsg;
      continue;
    }
    
    if(cutflow) cf_hottilecellveto++;
    if(cutflow) cf_overlap++;
    
    m_logger << ::DEBUG << "Selected jet pt: " <<(*itr).Pt() << " eta: " <<(*itr).emscale_eta() << " phi: "<< (*itr).emscale_phi() << SLogger::endmsg;
    
    sel_jets.push_back( new Jet(*itr));
  }
  
  std::sort(sel_jets.begin(), sel_jets.end(),compareJets());
  
  m_logger << ::DEBUG << "Selected jet pt: " << sel_jets.size() << SLogger::endmsg;    
				    
  return;
}


//____________________________________________________________________________         
void JetSelector::RemoveElectronJetOverlap( std::vector<Electron*> &sel_electrons, std::vector<Jet*> &sel_jets, JetType jet_type, bool cutflow){

  m_logger << ::DEBUG << "Doing jet overlap removal for jet type " << jet_type << SLogger::endmsg;   

  for(unsigned int j = 0; j < sel_electrons.size(); ++j) { 
    for(unsigned int i = 0; i < sel_jets.size(); ++i) { 
            
      double deltaR = DeltaR(sel_electrons.at(j)->tracketa(), sel_electrons.at(j)->trackphi(), sel_jets.at(i)->emscale_eta(), sel_jets.at(i)->emscale_phi());
      
      m_logger << ::DEBUG << "Electron "<<j<< " Jet " << i << " dR= " << deltaR << SLogger::endmsg;
      
      if (deltaR < 0.2) {
         m_logger << ::DEBUG << "Removing Jet " << i << SLogger::endmsg;
       	 sel_jets.erase(sel_jets.begin()+i); 
	 i--;//subtract one from i to keep counting consistent
	 if (cutflow) cf_overlap--;
      }      
    }
  }
  return;
} 

//____________________________________________________________________________         
void JetSelector::JetSystematics( std::vector< unsigned int > &n_jets_, std::vector< double > &leading_jet_pt, const D3PDReader::JetD3PDObject* m_jet_d3pdobject, std::vector<Electron*> &sel_electrons, double mu, unsigned int npv, const int event_number, JetType jet_type) {

  //build jet collection
  std::vector<Jet> all_jets;
  ParticleElementBuilder::build( all_jets, (*m_jet_d3pdobject) );

  GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
  
  // loop over all possible jet variations - HARD CODED number  FIX THIS  ??
  // kludgy fix for now - syst 0,1 are jvf, >=2 are JES/JER variations
  for (unsigned int i = 0; i < 47; i++){
  
    //calibrate jets
    energy_rescaler->ApplyEnergyRescaler(all_jets, mu, npv, m_Eventshape_rhoKt4EM);
    if (i >= 2){
      energy_rescaler->ApplyJetSystematic(all_jets, mu, npv, event_number, i);
    }
    
    //select jets
    std::vector<Jet*> sel_jets;
    if (i<2){
      SelectJets( all_jets, sel_jets, mu, npv, jet_type, false, i+1);    
    } else {
      SelectJets( all_jets, sel_jets, mu, npv, jet_type, false);    
    }
    RemoveElectronJetOverlap(sel_electrons, sel_jets, jet_type, false);

    //output jet variables
    unsigned int n_jets = sel_jets.size();
    n_jets_.push_back( n_jets );
    leading_jet_pt.push_back( n_jets >= 1 ? sel_jets[0]->Pt() : 0.0 );    
    //double leading_jet_eta = n_jets >= 1 ? sel_jets[0].Eta() : 0;
    //double subleading_jet_pt  = n_jets >= 2 ? sel_jets[1].Pt() : 0;
    //double subleading_jet_eta = n_jets >= 2 ? sel_jets[1].Eta() : 0;
    
    for (unsigned int j = 0; j < n_jets; ++j) delete sel_jets[j]; // memory cleanup
  }
   
  return;

}

//____________________________________________________________________________         
double JetSelector::Mjj( std::vector<Jet*> &jets){

  double m_jj = 0;

  for(unsigned int i = 0; i < jets.size(); ++i) {     
    for(unsigned int j = 0; j < jets.size(); ++j) { 
       if (i>=j) continue;
              
       double mass = (jets[i]->TLV() + jets[j]->TLV()).M();
       if (mass > m_jj) m_jj = mass;
    }  
  }

  return m_jj;
}

//____________________________________________________________________________         
double JetSelector::LeadingJetPt( std::vector<Jet*> &jets){

  double max_pt = 0;

  for(unsigned int i = 0; i < jets.size(); ++i) {                   
    double pt = jets[i]->Pt();
    if (pt > max_pt) max_pt = pt;  
  }

  return max_pt;
}

//____________________________________________________________________________         
bool JetSelector::VBFCuts( std::vector<Jet*> &sel_jets){
  
  if(sel_jets.size() < 2)
    return false;

  for(unsigned int j = 0; j < sel_jets.size(); ++j) {
    m_logger << ::DEBUG <<"jet["<<j<<"], pt = "<<sel_jets.at(j)->pt()<<SLogger::endmsg;
  }

  std::sort(sel_jets.begin(), sel_jets.end(),compareJets());

  for(unsigned int j = 0; j < sel_jets.size(); ++j) {
     m_logger << ::DEBUG <<"after, jet["<<j<<"], pt = "<<sel_jets.at(j)->pt()<<SLogger::endmsg;
  }

  if( fabs(sel_jets[0]->eta()-sel_jets[1]->eta())<=3)
    return false;

  TLorentzVector jet_0; jet_0.SetPtEtaPhiE(sel_jets[0]->pt(),sel_jets[0]->eta(), sel_jets[0]->phi(), sel_jets[0]->E()); 
  TLorentzVector jet_1; jet_1.SetPtEtaPhiE(sel_jets[1]->pt(),sel_jets[1]->eta(), sel_jets[1]->phi(), sel_jets[1]->E()); 

  if((jet_0+jet_1).M() <= 350000)
    return false;


  return true;
}

//____________________________________________________________________________         
bool JetSelector::GGFCuts( std::vector<Jet*> &sel_jets){
  
  if(sel_jets.size() >= 2)
    return false; 
  return true;
}

//____________________________________________________________________________         
bool JetSelector::VHCuts( std::vector<Jet*> &sel_jets){
  
  if(sel_jets.size() >= 2)
    return false;
  return true;
}

//____________________________________________________________________________         
double JetSelector::DeltaR(double eta1, double phi1, double eta2, double phi2) {      
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  double delta_eta = eta1 - eta2;  
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}
