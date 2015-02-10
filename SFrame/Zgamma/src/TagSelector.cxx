// $Id: TagSelector.cxx 18120 2012-09-16 14:35:37Z sheim $

// Local include(s):
#include "../include/TagSelector.h"
#include "../include/TriggerSelector.h"
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
//#include "egammaAnalysisUtils/MultiLeptonDefs.h"
#include "egammaEvent/egammaPIDdefs.h"
#include "egammaAnalysisUtils/IsEMPlusPlusDefs.h"

const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( TagSelector );

TagSelector::TagSelector(SCycleBase* parent, const char* name)
  : ToolBase( parent, name ),
    cf_preselect(0),
    cf_author(0),	 
    cf_electronid(0),
    cf_eta(0),	
    cf_et(0),	
    cf_oq(0),	
    cf_z0(0),
    cf_trigger(0)	
{

  DeclareProperty( "DoSmear", m_doSmear );
  DeclareProperty( "DoCalibration", m_doCalibration );
  DeclareProperty( "VetoCrack", m_vetoCrack );
  DeclareProperty( "DoLikelihood", m_doLikelihood );
  DeclareProperty( "LikelihoodOP", m_likelihoodOP = "Loose");//LikeEnum::Loose);
  DeclareProperty( "PTCutLikelihood", m_ptcutLikelihood );
  DeclareProperty( "DoTruthMatchEleZ", m_doTruthMatchEleZ );
  
  //m_likelihoodtool = new ElectronLikelihoodTool("RootCore/egammaAnalysisUtils/share/PDFs_2012_august25_update_1.root NO! ");
  //m_likelihoodtool = new ElectronLikelihoodToolLocal("config/other/PDFs_2012_august29_lowetbin.root NO! ");
  //m_likelihoodtool = new ElectronLikelihoodToolLocal("config/other/PDFs_2012_sig_tagInBarrelAtLowEt.root");
  

  return;
  
}

TagSelector::~TagSelector() {


 return;

}


void TagSelector::BeginMasterInputData( const SInputData& ) throw( SError ){

  
  return;
  
}


void TagSelector::EndMasterInputData( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                  Zgamma Tag Cut Flow"<<SLogger::endmsg;
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
   m_logger << ALWAYS <<"Electrons After trigger........:"<<cf_trigger    <<" ("<<((double)cf_trigger)/((double)cf_z0)*100 <<"%)"   <<" ("<<((double)cf_trigger)/((double)cf_preselect)*100 <<"%)" <<SLogger::endmsg;
   m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;


  return;

}


void TagSelector::SelectElectrons( std::vector<Electron*> &sel_electrons, const D3PDReader::ElectronD3PDObject* m_electron_d3pdobject, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, int n_vertices ) {

  //electron selection
   m_logger << ::DEBUG << "Electron Selection " << SLogger::endmsg;

  std::vector<Electron> all_eles;  
  ParticleElementBuilder::build( all_eles, (*m_electron_d3pdobject) );

  m_logger << ::DEBUG << "Number of electrons in event: " << all_eles.size() << SLogger::endmsg;

  for(std::vector<Electron>::iterator itr = all_eles.begin(); itr != all_eles.end(); ++itr) { 
    
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

    //ID
    GET_TOOL(id, IDTool, "IDTool");
    if(!(id->passPlusPlus((*itr),"tight"))) continue;
    cf_electronid++;

    
      //calibrate energy afterwards
      if (m_doSmear || m_doCalibration) {
	GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
	energy_rescaler->ApplyEnergyRescaler( (*itr), m_event_d3pdobject->EventNumber(), m_event_d3pdobject->RunNumber());          
      }


    
    //eta cuts, tag should eb out of crack
    m_logger << ::DEBUG << "Eta cut" << SLogger::endmsg;
    if(!(fabs((*itr).cl_eta()) < 2.47)) continue;
    if(fabs((*itr).cl_eta())<1.52 && fabs((*itr).cl_eta())>1.37) continue;
    cf_eta++;

     //et cut 25 GeV
    m_logger << ::DEBUG << "Et cut" << SLogger::endmsg;
    if(!((*itr).cl_Et() > 25000.)) continue;
    if(m_ptcutLikelihood && ((*itr).cl_Et() < 10000.)) continue;
    cf_et++;

    //object quality
    m_logger << ::DEBUG << "OQ cut" << SLogger::endmsg;
    if(!(((*itr).OQ()&1446) == 0)) continue;
    cf_oq++;

    //z0 cut --- leave out for now
    m_logger << ::DEBUG << "Z0 cut" << SLogger::endmsg;
    //if(!(fabs((*itr).trackz0pvunbiased()) < 10.)) continue;
    cf_z0++;

    //Trigger match
    m_logger << ::DEBUG << "Trigger match cut" << SLogger::endmsg;
    GET_TOOL(trig_select, TriggerSelector, "TriggerSelector");
    bool trigger_pass = trig_select->MatchTriggers( (*itr) );
    if (!trigger_pass) continue;
    cf_trigger++;


    sel_electrons.push_back( new Electron(*itr));

  }
  
  m_logger << ::DEBUG << "Number of selected electrons in event: " << sel_electrons.size() << SLogger::endmsg;

				    
  return;
}



double TagSelector::DeltaR(double eta1, double phi1, double eta2, double phi2) {      
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  double delta_eta = eta1 - eta2;  
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}
