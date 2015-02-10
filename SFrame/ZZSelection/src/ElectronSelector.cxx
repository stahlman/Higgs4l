// $Id: ElectronSelector.cxx 25756 2014-01-01 01:18:47Z brendlin $

// Local include(s):
#include "../include/ElectronSelector.h"
#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Electron.h"
#include "Muon.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "EnergyRescalerTool.h"
#include "IDTool.h"

//RootCore
#include "egammaAnalysisUtils/CaloIsoCorrection.h"


const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( ElectronSelector );

ElectronSelector::ElectronSelector(SCycleBase* parent, const char* name)
  : ToolBase( parent, name ),
    cf_preselect(0),
    cf_author(0),	 
    cf_electronid(0),
    cf_eta(0),	
    cf_et(0),	
    cf_oq(0),	
    cf_z0(0),	
    cf_overlap(0),
    cf_cl_overlap(0),
    cf_mu_overlap(0)
{

  DeclareProperty( "DoElectronIDCut", m_doElectronIDCut = true );

  DeclareProperty( "DoCalibration", m_doCalibration = true);
  DeclareProperty( "VetoCrack", m_vetoCrack = false);
  DeclareProperty( "PTCutZ", m_ptcutZ = 0);
  DeclareProperty( "DoTruthMatchEleZ", m_doTruthMatchEleZ = false);

  DeclareProperty( "IsolationConeSize", m_cone_size = 20);

  DeclareProperty( "DoBlayer", m_doBlayer = false );
  DeclareProperty( "DoML", m_doML = false );
  DeclareProperty( "DoML_HCP", m_doML_HCP = false );
  DeclareProperty( "DoLikelihood", m_doLikelihood = false );
  DeclareProperty( "DoLikelihoodMedium", m_doLikelihoodMedium = false );
  // DoLikelihoodLoose: this and only this needs to be
  // set to true for the official cutflow
  DeclareProperty( "DoLikelihoodLoose", m_doLikelihoodLoose = true ); 
  DeclareProperty( "DoLikelihoodLoose_BL_Pix", m_doLikelihoodLoose_BL_Pix = false );
  DeclareProperty( "DoLikelihoodLoose_BL_PixLow", m_doLikelihoodLoose_BL_PixLow = false );
  DeclareProperty( "DoLikelihoodLoose_BL_PixMed", m_doLikelihoodLoose_BL_PixMed = false );
  DeclareProperty( "DoLikelihoodLoose_BL_PixHigh", m_doLikelihoodLoose_BL_PixHigh = false );
  DeclareProperty( "DoSiTrack", m_doSiTrack = false );
  DeclareProperty( "LH_OP", m_LH_OP = "Loose");
  DeclareProperty( "ML_OP", m_ML_OP = "");
  
  DeclareProperty( "DoTrackIsolation", m_doTrkIso = false );
  DeclareProperty( "DoCaloIsolation",  m_doCaloIso = false );
  DeclareProperty( "DoD0",  m_doD0 = false );

  


  return;
  
}

ElectronSelector::~ElectronSelector() {


 return;

}


void ElectronSelector::BeginMasterInputData( const SInputData& ) throw( SError ){


  return;
  
}


void ElectronSelector::EndMasterInputData( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                  H -> ZZ Electron Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of electrons passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons Before Cuts..........:"<<cf_preselect   <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Author.........:"<<cf_author      <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)"  <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Electron ID....:"<<cf_electronid  <<" ("<<((double)cf_electronid)/((double)cf_author)*100 <<"%)"  <<" ("<<((double)cf_electronid)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Eta............:"<<cf_eta	        <<" ("<<((double)cf_eta)/((double)cf_electronid)*100 <<"%)"	 <<" ("<<((double)cf_eta)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Et.............:"<<cf_et          <<" ("<<((double)cf_et)/((double)cf_eta)*100 <<"%)" <<" ("<<((double)cf_et)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Object Quality.:"<<cf_oq	        <<" ("<<((double)cf_oq)/((double)cf_et)*100 <<"%)" <<" ("<<((double)cf_oq)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Z0.............:"<<cf_z0	        <<" ("<<((double)cf_z0)/((double)cf_oq)*100 <<"%)"  <<" ("<<((double)cf_z0)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Overlap........:"<<cf_overlap	<<" ("<<((double)cf_overlap)/((double)cf_z0)*100 <<"%)"  <<" ("<<((double)cf_overlap)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Cluster Overlap:"<<cf_cl_overlap	<<" ("<<((double)cf_cl_overlap)/((double)cf_overlap)*100 <<"%)"  <<" ("<<((double)cf_cl_overlap)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Muon Overlap...:"<<cf_mu_overlap	<<" ("<<((double)cf_mu_overlap)/((double)cf_cl_overlap)*100 <<"%)"  <<" ("<<((double)cf_cl_overlap)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;


  return;

}


void ElectronSelector::SelectElectrons( std::vector<Electron*> &sel_electrons, const D3PDReader::ElectronD3PDObject* m_electron_d3pdobject, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, int n_vertices ) {

  //electron selection
   m_logger << ::DEBUG << "Electron Selection " << SLogger::endmsg;

  std::vector<Electron> all_eles;  
  ParticleElementBuilder::build( all_eles, (*m_electron_d3pdobject) );

  m_logger << ::DEBUG << "Number of electrons in event: " << all_eles.size() << SLogger::endmsg;

  for(std::vector<Electron>::iterator itr = all_eles.begin(); itr != all_eles.end(); ++itr) { 
    
    //truthmatch
    if(!is_data() && m_doTruthMatchEleZ  && !(fabs((*itr).truth_type()) == 11 && (*itr).truth_matched() && (*itr).truth_mothertype() == 23) ) {
      continue;
    }
    if(!is_data() && m_doTruthMatchEleZ) m_logger << ::DEBUG << "truthtype: " << fabs((*itr).truth_type()) << ", truthmatched: " <<(*itr).truth_matched() << ", truthmothertype: " << (*itr).truth_mothertype()<< SLogger::endmsg;
    cf_preselect++;

    //author
    m_logger << ::DEBUG << "Author cut" << SLogger::endmsg;
    if(!((*itr).author() == 1 || (*itr).author() == 3)) continue;
    cf_author++;

    //energy correction
   m_logger << ::DEBUG << "Et, before scaling: " << (*itr).cl_Et() << SLogger::endmsg;   
 if (m_doCalibration) {
        GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
        energy_rescaler->ApplyEnergyRescaler( (*itr), m_event_d3pdobject->EventNumber(), m_event_d3pdobject->RunNumber());         
      }
   m_logger << ::DEBUG << "Et, after scaling: " << (*itr).cl_Et() << SLogger::endmsg;



    //electron ID
    if (m_doElectronIDCut) {
      GET_TOOL(id, IDTool, "IDTool");
      bool pass_electronID = false;
      
      if(m_doLikelihood){
        m_logger << ::DEBUG << "check likelihood" << SLogger::endmsg;  
       if(id->passLikelihood((*itr),m_LH_OP,n_vertices)) pass_electronID = true; 
      }
      
      if(m_doLikelihoodMedium){
         m_logger << ::DEBUG << "check likelihood, medium" << SLogger::endmsg;
         if(id->passLikelihood((*itr),"Medium",n_vertices)) pass_electronID = true; 
      }
      
      if(m_doLikelihoodLoose){
         m_logger << ::DEBUG << "check likelihood, loose" << SLogger::endmsg;
         if(id->passLikelihood((*itr),LikeEnum::Loose,n_vertices)) pass_electronID = true; 
      }
      
      //if(m_doLikelihoodLoose_BL_Pix){
      //   m_logger << ::DEBUG << "check likelihood, Loose_BL_Pix" << SLogger::endmsg;
      //   if(id->passLikelihood((*itr),LikeEnum::Loose_BL_Pix,n_vertices)) pass_electronID = true; 
      //}
      
      if(m_doLikelihoodLoose_BL_PixLow){
         m_logger << ALWAYS << "Error! Loose_BL_PixLow DEPRECATED! Defaulting to Loose LH" << SLogger::endmsg;
         if(id->passLikelihood((*itr),LikeEnum::Loose,n_vertices)) pass_electronID = true; 
      }
      
      if(m_doLikelihoodLoose_BL_PixMed){
         m_logger << ALWAYS << "Error! Loose_BL_PixMed DEPRECATED! Defaulting to Loose LH" << SLogger::endmsg;
         if(id->passLikelihood((*itr),LikeEnum::Loose,n_vertices)) pass_electronID = true; 
      }
      
      if(m_doLikelihoodLoose_BL_PixHigh){
         m_logger << ALWAYS << "Error! Loose_BL_PixHigh DEPRECATED! Defaulting to Loose LH" << SLogger::endmsg;
         if(id->passLikelihood((*itr),LikeEnum::Loose,n_vertices)) pass_electronID = true; 
      }
      
      if(m_doML){
          m_logger << ::DEBUG << "check multilepton cuts" << SLogger::endmsg;
         if(id->passML((*itr),m_ML_OP)) pass_electronID = true; 
         //if(id->passML((*itr),m_ML_OP) && id->passLikelihood((*itr),LLikeEnum::Loose_BL_PixMed,n_vertices)) pass_electronID = true;
      }


      if(m_doML_HCP){
         m_logger << ::DEBUG << "check multilepton cuts, hcp" << SLogger::endmsg;
         if(id->passML_HCP((*itr),m_ML_OP)) pass_electronID = true; 
      }
      
      if(m_doSiTrack){
         m_logger << ::DEBUG << "check SiTrack" << SLogger::endmsg;
         if( ((*itr).nPixHits()+(*itr).nSCTHits()) >= 7  ) pass_electronID = true; 
      }
            
      if (!pass_electronID) continue;
    }
    
    //Blayer (should be in new Multilepton ID anyways, and in some likelihoods, here the option to require in additionally)    
    if(m_doBlayer){
        if((*itr).expectHitInBLayer()){
             if((*itr).nBLHits() < 1 || ((*itr).nPixHits()+(*itr).nPixelDeadSensors()) < 2) continue;
          }//end if expected blayer
        else{
              if((*itr).nPixHits()+(*itr).nPixelDeadSensors() < 2) continue;
          }//end if else
    }//end if doblayer

    cf_electronid++;
    
    //eta cuts 
    m_logger << ::DEBUG << "Eta cut" << SLogger::endmsg;
    if(!(fabs((*itr).cl_eta()) < 2.47)) continue;
    m_logger << ::DEBUG << "m_vetoCrack " <<m_vetoCrack << SLogger::endmsg;
    if(m_vetoCrack && fabs((*itr).cl_eta())<1.52 && fabs((*itr).cl_eta())>1.37) continue;
    cf_eta++;

     //et cuts 7 GeV
    m_logger << ::DEBUG << "Et cut, et: " << (*itr).cl_Et() << SLogger::endmsg;
    if(!((*itr).cl_Et() > 7000.)) continue;
    if(m_ptcutZ && ((*itr).cl_Et() < 20000.)) continue;
    cf_et++;

    //object quality
    m_logger << ::DEBUG << "OQ cut" << SLogger::endmsg;
    if(!(((*itr).OQ()&1446) == 0)) continue;
    cf_oq++;

    //z0 cut
    m_logger << ::DEBUG << "Z0 cut" << SLogger::endmsg;
    if(!(fabs((*itr).Z0()) < 10.)) continue;
    cf_z0++;

    //overlap removal
    bool passed_overlap = true;
    for(unsigned int i = 0; i < sel_electrons.size(); ++i) { 
       if ( ((*itr).Unrefittedtrack_d0()     == sel_electrons.at(i)->Unrefittedtrack_d0())
      	 && ((*itr).Unrefittedtrack_z0()     == sel_electrons.at(i)->Unrefittedtrack_z0())
      	 && ((*itr).Unrefittedtrack_theta()  == sel_electrons.at(i)->Unrefittedtrack_theta())
      	 && ((*itr).Unrefittedtrack_phi()    == sel_electrons.at(i)->Unrefittedtrack_phi())
      	 && ((*itr).Unrefittedtrack_qoverp() == sel_electrons.at(i)->Unrefittedtrack_qoverp()) ){
	 
	   if ((*itr).cl_E_cal() > sel_electrons.at(i)->cl_E_cal()) {
             //m_logger << WARNING << "Removing Electron" << SLogger::endmsg;
       	     sel_electrons.erase(sel_electrons.begin()+i); 
	     i--;//subtract one from i to keep counting consistent
	     cf_overlap--;//remove one electron from cutflow
   	   } else { passed_overlap = false; }
       }
    }
    if (!passed_overlap) continue;    
    cf_overlap++;

    bool passed_cl_overlap = true;
    double delta_phi = 0;
    for(unsigned int i = 0; i < sel_electrons.size(); ++i) { 
      delta_phi = (fabs((*itr).cl_phi() - sel_electrons.at(i)->cl_phi()) > TMath::Pi()) ? 2*TMath::Pi()-fabs((*itr).cl_phi() - sel_electrons.at(i)->cl_phi()) : fabs((*itr).cl_phi() - sel_electrons.at(i)->cl_phi());

       if ( (fabs((*itr).cl_eta() - sel_electrons.at(i)->cl_eta()) < 3*0.025)
	    //&& (fabs((*itr).cl_phi() - sel_electrons.at(i)->cl_phi()) < 5*0.025) ){
	    && (delta_phi < 5*0.025) ){

 	   if ((*itr).cl_E_cal() > sel_electrons.at(i)->cl_E_cal()) {
             //m_logger << WARNING << "Removing Electron" << SLogger::endmsg;
       	     sel_electrons.erase(sel_electrons.begin()+i); 
	     i--;//subtract one from i to keep counting consistent
	     cf_cl_overlap--;//remove one electron from cutflow
   	   } else { passed_cl_overlap = false; }
       }
    }
    if (!passed_cl_overlap) continue;    
    cf_cl_overlap++;
    
    //increment for now, will decrement later
    cf_mu_overlap++;

    //isolation cuts
    if (m_doTrkIso) {
       double trk_iso = (*itr).ptcone(m_cone_size);
       
       if (!(trk_iso/(*itr).cl_Et() < 0.15)) continue;
    }
    
    if (m_doCaloIso) {
       double calo_iso = (*itr).etcone(m_cone_size, !is_data());

       if (!(calo_iso/(*itr).cl_Et() < 0.20)) continue;
    }
    
    //d0 significance cut
    if (m_doD0) {      
      if (!((*itr).D0Significance() < 6.5)) continue;
    }
    
    sel_electrons.push_back( new Electron(*itr));

  }
  
  m_logger << ::DEBUG << "Number of selected electrons in event: " << sel_electrons.size() << SLogger::endmsg;

				    
  return;
}
void ElectronSelector::RemoveElectronMuonOverlap(std::vector<Muon*> &sel_muons, std::vector<Electron*> &sel_electrons){

  for(unsigned int j = 0; j < sel_muons.size(); ++j) { 
    for(unsigned int i = 0; i < sel_electrons.size(); ++i) { 
      
      if (sel_muons.at(j)->isStandAloneMuon() == 1 || sel_muons.at(j)->isCaloMuon()) continue;
      
      double deltaR = DeltaR(sel_electrons.at(i)->Unrefittedtrack_eta(), sel_electrons.at(i)->Unrefittedtrack_phi(),sel_muons.at(j)->id_eta(), sel_muons.at(j)->id_phi());
      
      if (deltaR < 0.02) { // remove electron 
           m_logger << ::DEBUG << "Removing Overlap Electron " << i << SLogger::endmsg;
       	   sel_electrons.erase(sel_electrons.begin()+i); 
	   i--;//subtract one from i to keep counting consistent
	   cf_mu_overlap--;//remove one electron from cutflow        	 
      }      
    }
  }

  return;
} 

int ElectronSelector::NumberAdditionalElectrons( Quadruplet* quad, std::vector<Electron*> &sel_electrons) {

  m_logger << ::DEBUG << "entering num add electrons "  << SLogger::endmsg;
  
  int n_add_electrons = 0;
  
  std::vector<Electron*> quad_electrons;
  quad->GetElectrons(quad_electrons);

  std::vector<Muon*> quad_muons;
  quad->GetMuons(quad_muons);
  
  for(unsigned int i = 0; i < sel_electrons.size(); ++i) { 
    
    //check first if electron already part of quad
    bool quad_e = false;
    for(unsigned int j = 0; j < quad_electrons.size(); ++j) { 
       if ( sel_electrons.at(i)->GetIndex() == quad_electrons.at(j)->GetIndex() ){
         quad_e = true;
	 break;
       }
    }
    if (quad_e) continue;
    
    m_logger << ::DEBUG << "pt cut "  << SLogger::endmsg;
    //pt cut
    if (!(sel_electrons.at(i)->cl_Et() > 10000)) continue;
    
    m_logger << ::DEBUG << "track iso cut "  << SLogger::endmsg;
    //track isolation cut
    double trk_iso = quad->CalculateTrkIso(sel_electrons.at(i), 20);
    if (!(trk_iso < 0.15 )) continue;
    
    m_logger << ::DEBUG << "calo iso cut "  << SLogger::endmsg;
    //calo isolation
    double calo_iso = quad->CalculateCaloIso(sel_electrons.at(i), 20, 18, !is_data());
    if (!(calo_iso < 0.2 )) continue;
    
    //check d0    
    m_logger << ::DEBUG << "d0 significance cut "  << SLogger::endmsg;
    if (!(sel_electrons.at(i)->D0Significance() < 6.5 )) continue;
    
    n_add_electrons++;        
        
  }
  
  return n_add_electrons;  
}

double ElectronSelector::DeltaR(double eta1, double phi1, double eta2, double phi2) {      
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  double delta_eta = eta1 - eta2;  
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}
