// $Id: ProbeSelector.cxx 18120 2012-09-16 14:35:37Z sheim $

// Local include(s):
#include "../include/ProbeSelector.h"
#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Electron.h"
#include "Muon.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "EnergyRescalerTool.h"
#include "IDTool.h"


const float M_MU = 105.658367;
const float M_Z = 91187.6;
const float GeV = 1000.0;

ClassImp( ProbeSelector );

ProbeSelector::ProbeSelector(SCycleBase* parent, const char* name)
  : ToolBase( parent, name ),
    cf_preselect(0),
    cf_author(0),	 
    cf_electronid(0),
    cf_eta(0),	
    cf_et(0),	
    cf_oq(0),	
    cf_z0(0)	
{

  DeclareProperty( "DoSmear", m_doSmear=1 );
  DeclareProperty( "DoCalibration", m_doCalibration=1 );
  DeclareProperty( "VetoCrack", m_vetoCrack=0 );
  DeclareProperty( "DoLikelihood", m_doLikelihood=0 );
  DeclareProperty( "LikelihoodOP", m_likelihoodOP = "Loose");//LikeEnum::Loose);
  DeclareProperty( "PTCutLikelihood", m_ptcutLikelihood=0 );
  DeclareProperty( "DoTruthMatchEleZ", m_doTruthMatchEleZ=0 );
  

  return;
  
}

ProbeSelector::~ProbeSelector() {


 return;

}


void ProbeSelector::BeginMasterInputData( const SInputData& ) throw( SError ){

  
  return;
  
}


void ProbeSelector::EndMasterInputData( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                  Zgamma Probe Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of probes passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Probes Before Cuts..........:"<<cf_preselect   <<SLogger::endmsg;
  m_logger << ALWAYS <<"Probes After Author.........:"<<cf_author      <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)"  <<" ("<<((double)cf_author)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Probes After Electron ID....:"<<cf_electronid  <<" ("<<((double)cf_electronid)/((double)cf_author)*100 <<"%)"  <<" ("<<((double)cf_electronid)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Probes After Eta............:"<<cf_eta	        <<" ("<<((double)cf_eta)/((double)cf_electronid)*100 <<"%)"	 <<" ("<<((double)cf_eta)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Probes After Et.............:"<<cf_et          <<" ("<<((double)cf_et)/((double)cf_eta)*100 <<"%)" <<" ("<<((double)cf_et)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Probes After Object Quality.:"<<cf_oq	        <<" ("<<((double)cf_oq)/((double)cf_et)*100 <<"%)" <<" ("<<((double)cf_oq)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Probes After Z0.............:"<<cf_z0	        <<" ("<<((double)cf_z0)/((double)cf_oq)*100 <<"%)"  <<" ("<<((double)cf_z0)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;


  return;

}


void ProbeSelector::SelectElectrons( std::vector<ProbeElectron*> &sel_electrons, std::vector<Electron*> &sel_tags,  std::vector<Photon*> &sel_photons, const D3PDReader::ElectronD3PDObject* m_electron_d3pdobject, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, int n_vertices ) {

  //electron selection
   m_logger << ::DEBUG << "Electron Selection " << SLogger::endmsg;

  std::vector<ProbeElectron> all_eles;  
  ParticleElementBuilder::build( all_eles, (*m_electron_d3pdobject) );

  m_logger << ::DEBUG << "Number of electrons in event: " << all_eles.size() << SLogger::endmsg;

  //loop over tags
  for(unsigned int itag = 0; itag < sel_tags.size(); itag++){

    //loop over other electrons in the event
    for(std::vector<ProbeElectron>::iterator itr = all_eles.begin(); itr != all_eles.end(); ++itr) { 
      
      //probe must not be equal to tag!
      m_logger << ::DEBUG << "tag index: " <<sel_tags[itag]->GetIndex() << ", probe index: " << (*itr).GetIndex() << SLogger::endmsg;
      if((*itr).GetIndex() == sel_tags[itag]->GetIndex()) continue;

       //calibrate energy afterwards
        if (m_doSmear || m_doCalibration) {
          GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
          energy_rescaler->ApplyEnergyRescaler( (*itr), m_event_d3pdobject->EventNumber(), m_event_d3pdobject->RunNumber());
        }

       //if((*itr).cl_Et() < 8000) m_logger << ALWAYS << "probe Et, 0: " << (*itr).cl_Et() << SLogger::endmsg;

      
      //is there a photon in the event, that does not overlap with the tag or the probe?
      //if yes, pick photon that brings mass closest to the Z mass 
       TLorentzVector* v_probe = new TLorentzVector();
       TLorentzVector* v_tag = new TLorentzVector();
       TLorentzVector* v_photon = new TLorentzVector();
  
       //pick Photon that brings invariant mass closest to Z mass
       double deltaZ = 9999999.;
       double deltaZ_test = 0;
       int ph_vec_index = 0;
       int ph_index = 0;
       int count = -1;

       bool foundphoton = 0;        

for(std::vector<Photon*>::iterator itr_g = sel_photons.begin(); itr_g != sel_photons.end(); ++itr_g) {
          count++;

          v_probe->SetPtEtaPhiE((*itr).cl_Et(), (*itr).tracketa(), (*itr).trackphi(), (*itr).cl_E_cal());
          v_tag->SetPtEtaPhiE(sel_tags[itag]->cl_Et(), sel_tags[itag]->tracketa(), sel_tags[itag]->trackphi(), sel_tags[itag]->cl_E_cal());
          v_photon->SetPtEtaPhiE((*itr_g)->cl_Et(), (*itr_g)->etas2(), (*itr_g)->phi(), (*itr_g)->cl_E_cal());

          //remove overlap
          if((*v_probe).DeltaR(*v_photon) < 0.2) {
             m_logger << ::DEBUG << " photon failed overlap removal, deltaR, probe: " << (*v_probe).DeltaR(*v_photon) << SLogger::endmsg; 
             continue;
          }
          if((*v_tag).DeltaR(*v_photon) < 0.2) {
             m_logger << ::DEBUG << " photon failed overlap removal, deltaR, tag: " << (*v_tag).DeltaR(*v_photon) << SLogger::endmsg;
             continue;
          }

         //require photon pt + probe pt to be larger than 30 GeV
         if((*v_probe).Pt() + (*v_photon).Pt() < 30000) continue;

         //require tag + probe mass to be smaller than 90 GeV
         if((*v_probe+*v_tag).M() > 90000) continue;

         //require tag + photon mass to be smaller than 80 GeV ----> Z+jets rejection
         //if((*v_photon+*v_tag).M() > 80000) continue;


          deltaZ_test = fabs((*v_probe+*v_tag+*v_photon).M() - M_Z);
          m_logger << ::DEBUG << count << " deltaZ_test: " << deltaZ_test << SLogger::endmsg;
          if(deltaZ_test < deltaZ){
             deltaZ = deltaZ_test;
             ph_vec_index = count;
             ph_index = (*itr_g)->GetIndex();
             foundphoton = 1;
          }
          
         }
      m_logger << ::DEBUG << "number of photons: " << sel_photons.size() << ", deltaZ: " << deltaZ << ", ph_vec_index:"<< ph_vec_index<<", ph_index: "<< ph_index << SLogger::endmsg;
      //if not continue
      if(foundphoton == 0) continue;  
     
      //truthmatch
      //if(m_doTruthMatchEleZ  && !(fabs((*itr).truth_type()) == 11 && (*itr).truth_matched() && (*itr).truth_mothertype() == 23) ) {
      if(!is_data() && m_doTruthMatchEleZ && !((*itr).truth_matched() == 1 && (((*itr).type() == 2 && (*itr).origin() == 13) || ((*itr).type() == 4 && ((*itr).originbkg() == 13 || (*itr).originbkg() == 40))))){
	continue;
      }
      if(!is_data()) m_logger << ::DEBUG << "truthtype: " << fabs((*itr).truth_type()) << ", truthmatched: " <<(*itr).truth_matched() << ", truthmothertype: " << (*itr).truth_mothertype()<< SLogger::endmsg;
      cf_preselect++;
      
      //author
      m_logger << ::DEBUG << "Author cut" << SLogger::endmsg;
      if(!((*itr).author() == 1 || (*itr).author() == 3)) continue;
      cf_author++;
      

     //no ID cut, but cut on silicon hits
      if((*itr).nPixHits() + (*itr).nPixelOutliers() < 1 || (*itr).nSiHits() + (*itr).nSCTOutliers() + (*itr).nPixelOutliers() < 7) continue; 
      cf_electronid++; 
      
      //eta cuts
      m_logger << ::DEBUG << "Eta cut" << SLogger::endmsg;
      if(!(fabs((*itr).cl_eta()) < 2.47)) continue;
      cf_eta++;
      
      //et cut 25 GeV
      m_logger << ::DEBUG << "Et cut" << SLogger::endmsg;
      if(!((*itr).cl_Et() > 7000.)) continue;
      //if(m_ptcutLikelihood && ((*itr).cl_Et() < 10000.)) continue;
      cf_et++;
//      if((*itr).cl_Et() < 8000) m_logger << ALWAYS << "probe Et" << (*itr).cl_Et() << SLogger::endmsg;      
 
      //object quality
      m_logger << ::DEBUG << "OQ cut" << SLogger::endmsg;
      if(!(((*itr).OQ()&1446) == 0)) continue;
      cf_oq++;
      
      //z0 cut --- leave out for now
      m_logger << ::DEBUG << "Z0 cut" << SLogger::endmsg;
      //if(!(fabs((*itr).trackz0pvunbiased()) < 10.)) continue;
      cf_z0++;
      
    //fill tag-related properties
      //index of tag
      (*itr).Set_tag_index(sel_tags[itag]->GetIndex());
      (*itr).Set_tag_vecindex(itag);

      //index of photon
      (*itr).Set_photon_index(ph_index);
      (*itr).Set_photon_vecindex(ph_vec_index);

      //push back probe selection
      sel_electrons.push_back( new ProbeElectron(*itr));
      
    }//end loop over probes
    
  }//end loop over tags
  
  m_logger << ::DEBUG << "Number of selected electrons in event: " << sel_electrons.size() << SLogger::endmsg;
  
				    
  return;
}



void ProbeSelector::CalculateTPGVariables(std::vector<ProbeElectron*> &sel_probes, std::vector<Electron*> &sel_tags,std::vector<Photon*> &sel_photons){

  TLorentzVector* v_probe = new TLorentzVector();
  TLorentzVector* v_tag = new TLorentzVector();
  TLorentzVector* v_photon = new TLorentzVector();

  //for ID checks
  GET_TOOL(id, IDTool, "IDTool");

  //loop over probes
  for(std::vector<ProbeElectron*>::iterator itr = sel_probes.begin(); itr != sel_probes.end(); ++itr) {
 
        //get TagVectorIndex
        Electron * tagptr = sel_tags[(*itr)->GetTagVecIndex()];
        Photon * photonptr = sel_photons[(*itr)->GetPhotonVecIndex()];        

        v_probe->SetPtEtaPhiE((*itr)->cl_Et(), (*itr)->tracketa(), (*itr)->trackphi(), (*itr)->cl_E_cal());
        v_tag->SetPtEtaPhiE(tagptr->cl_Et(), tagptr->tracketa(), tagptr->trackphi(), tagptr->cl_E_cal());
        v_photon->SetPtEtaPhiE(photonptr->cl_Et(), photonptr->etas2(), photonptr->phi(), photonptr->cl_E_cal());

        if((*v_probe).DeltaR(*v_photon) < 0.2) m_logger << ALWAYS << "deltaR: " << (*v_probe).DeltaR(*v_probe) << ", vec index: "<< (*itr)->GetPhotonVecIndex() << ", index: "<< (*itr)->GetPhotonIndex() << SLogger::endmsg;

        //OS?
        (*itr)->Set_OS_tp(((*itr)->charge() != tagptr->charge()));

        //TP mass
	(*itr)->Set_mass_tp((*v_probe+*v_tag).M());
  	//TPg Mass
  	(*itr)->Set_mass_tpg((*v_probe+*v_tag+*v_photon).M());
  	//deltaR TP
        (*itr)->Set_deltaR_tp((*v_probe).DeltaR(*v_tag));
  	//deltaRPg
  	(*itr)->Set_deltaR_pg((*v_probe).DeltaR(*v_photon));

         //Tg Mass
        (*itr)->Set_mass_tg((*v_tag+*v_photon).M());
        (*itr)->Set_deltaR_tg((*v_tag).DeltaR(*v_photon));

        /////////////////////////////////////////////////////////////////
        //Conditions
       (*itr)->Set_passML(id->passML((**itr)));      
       (*itr)->Set_passTight(id->passPlusPlus((**itr),"tight"));

       //Tag check
       (*itr)->Set_tag_passTight(id->passPlusPlus((*tagptr),"tight"));


   
  }//end loop over probes
  
  //loop over tags
  //void Set_deltaR_tg(double deltaR) { m_deltaR_tg = deltaR;};


return;

}



double ProbeSelector::DeltaR(double eta1, double phi1, double eta2, double phi2) {      
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  double delta_eta = eta1 - eta2;  
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}
