// $Id: CycleCreators.py 173 2010-05-12 15:49:33Z krasznaa $

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Electron.h"
#include "ProbeElectron.h"
#include "Photon.h"
#include "ProbeElectron.h"
#include "ParticleElementBuilder.h"

// Local include(s):
#include "../include/ZgammaTruth.h"
#include "../include/TagSelector.h"
#include "../include/ProbeSelector.h"
#include "../include/PhotonSelector.h"
#include "../include/TriggerSelector.h"

//Common Tools
#include "EnergyRescalerTool.h"
#include "ScaleFactorTool.h"
#include "IDTool.h"

ClassImp( ZgammaTruth );

ZgammaTruth::ZgammaTruth()
  : CycleBase(), 
    m_doGRL ( true ),
    m_doTrig ( true ),
    m_doVert ( true ),
    cf_preselect( "preselect", this ),
    cf_grl( "grl", this ),
    cf_larerror( "larerror", this ),
    cf_vertex( "vertex", this ),
    cf_trigger( "trigger", this ),
    cf_tag( "tag", this ),
    cf_photon( "photon", this ),
    cf_probe( "probe", this )
{
  
   SetLogName( GetName() );
   DeclareProperty( "RecoTreeString", m_recoTreeName );
   DeclareProperty( "OutputTreeString", c_output_tree_name = "output"); 

   DeclareProperty( "DoGRL", m_doGRL );
   DeclareProperty( "DoLarError", m_doLarError );
   DeclareProperty( "DoTrigger", m_doTrig );
   DeclareProperty( "DoVertex", m_doVert );
   DeclareProperty( "DoPileupSF", DoPileupSF = true );
   DeclareProperty( "DoVertexSF", DoVertexSF = true );

   DeclareProperty("output_event_branches_regex", c_output_event_branches_regex = ".*");
   DeclareProperty("output_vxp_branchegs_regex", c_output_vxp_branches_regex = ".*");
   DeclareProperty("output_trigger_branchegs_regex", c_output_trigger_branches_regex = ".*");
   DeclareProperty("output_electron_branches_regex", c_output_electron_branches_regex = ".*");
   DeclareProperty("output_photon_branches_regex", c_output_photon_branches_regex = ".*");
   DeclareProperty("output_met_branches_regex", c_output_met_branches_regex = ".*");

   DECLARE_TOOL(TriggerSelector,   "TriggerSelector");
   DECLARE_TOOL(TagSelector,   "TagSelector");
   DECLARE_TOOL(ProbeSelector,   "ProbeSelector");
   DECLARE_TOOL(PhotonSelector,   "PhotonSelector");
   DECLARE_TOOL(EnergyRescalerTool, "EnergyRescalerTool");
   DECLARE_TOOL(ScaleFactorTool,    "ScaleFactorTool");
   DECLARE_TOOL(IDTool,    "IDTool");
}

ZgammaTruth::~ZgammaTruth() {

}

void ZgammaTruth::BeginCycleImp() throw( SError ) {

   return;

}

void ZgammaTruth::EndCycleImp() throw( SError ) {

   return;

}

void ZgammaTruth::BeginInputDataImp( const SInputData& ) throw( SError ) {

  //Declare output variables:  
  DeclareVariable( RunNumber, "RunNumber");
  DeclareVariable( EventNumber, "EventNumber");
  DeclareVariable( lbn, "lbn");
  DeclareVariable( mc_channel_number, "mc_channel_number");
  DeclareVariable( n_vertices3, "n_vertices3");

  DeclareVariable( tag_n, "tag_n");
  DeclareVariable( tag_E, "tag_E");
  DeclareVariable( tag_Et, "tag_Et");
  DeclareVariable( tag_eta, "tag_eta");
  DeclareVariable( tag_phi, "tag_phi");
  DeclareVariable( tag_index, "tag_index");
  DeclareVariable( tag_type, "tag_type");
  DeclareVariable( tag_origin, "tag_origin");
  DeclareVariable( tag_originbkg, "tag_originbkg");
  DeclareVariable( tag_truth_matched, "tag_truth_matched");

  DeclareVariable( probe_n, "probe_n");
  DeclareVariable( probe_E, "probe_E");
  DeclareVariable( probe_Et, "probe_Et");
  DeclareVariable( probe_eta, "probe_eta");
  DeclareVariable( probe_phi, "probe_phi");
  DeclareVariable( probe_type, "probe_type");
  DeclareVariable( probe_origin, "probe_origin");
  DeclareVariable( probe_originbkg, "probe_originbkg");
  DeclareVariable( probe_truth_matched, "probe_truth_matched");
  
  DeclareVariable( probe_index, "probe_index");
  DeclareVariable( probe_tag_index, "probe_tag_index");
  DeclareVariable( probe_tag_vecindex, "probe_tag_vecindex");
  DeclareVariable( probe_photon_index, "probe_photon_index");
  DeclareVariable( probe_photon_vecindex, "probe_photon_vecindex");

  DeclareVariable( probe_tag_OS, "probe_tag_OS");

  DeclareVariable( probe_tag_mass, "probe_tag_mass");
  DeclareVariable( probe_tag_photon_mass, "probe_tag_photon_mass");
  DeclareVariable( probe_tag_dR, "probe_tag_dR");
  DeclareVariable( probe_photon_dR, "probe_photon_dR");
  DeclareVariable( p_tag_photon_mass, "p_tag_photon_mass");
  DeclareVariable( p_tag_photon_dR, "p_tag_photon_dR");
  //conditions
  DeclareVariable( probe_passML, "probe_passML"); 
  DeclareVariable( probe_passTight, "probe_passTight");
  //tag conditions
  DeclareVariable( probe_tag_passTight, "probe_tag_passTight");

  DeclareVariable( photon_n, "photon_n");
  DeclareVariable( photon_E, "photon_E");
  DeclareVariable( photon_Et, "photon_Et");
  DeclareVariable( photon_eta, "photon_eta");
  DeclareVariable( photon_phi, "photon_phi");
  DeclareVariable( photon_topoiso20, "photon_topoiso20");
  DeclareVariable( photon_topoiso40, "photon_topoiso40");
  DeclareVariable( photon_truth_type, "photon_truth_type");
  DeclareVariable( photon_type, "photon_type");
  DeclareVariable( photon_origin, "photon_origin");
  DeclareVariable( photon_isConv, "photon_isConv");

  DeclareVariable( evt_weight, "evt_weight");
  DeclareVariable( pileup_sf,  "pileup_sf");
  DeclareVariable( vertex_sf,  "vertex_sf");


  // -----------------------------------------------------------------
  // ---------------- D3PD Reader constuctors ------------------------
  m_event_d3pdobject = new D3PDReader::EventInfoD3PDObject( m_entry_number );
  m_vxp_d3pdobject = new D3PDReader::PrimaryVertexD3PDObject( m_entry_number );
  m_trigger_d3pdobject = new D3PDReader::TriggerD3PDObject( m_entry_number );
  m_electron_d3pdobject = new D3PDReader::ElectronD3PDObject( m_entry_number, "el_" );
  m_photon_d3pdobject = new D3PDReader::PhotonD3PDObject( m_entry_number, "ph_" );
  m_truth_d3pdobject = new D3PDReader::TruthParticleD3PDObject( m_entry_number );
  m_met_d3pdobject = new D3PDReader::METD3PDObject( m_entry_number, "MET_RefFinal_" ); 


 
  // -------------------------------------------------------------
  // ---------------- Activating branches ------------------------
  m_event_d3pdobject->SetActive(kTRUE,c_output_event_branches_regex);
  m_electron_d3pdobject->SetActive(kTRUE,c_output_electron_branches_regex);
  m_vxp_d3pdobject->SetActive(kTRUE,c_output_vxp_branches_regex);
  m_trigger_d3pdobject->SetActive(kTRUE,c_output_trigger_branches_regex);
  m_photon_d3pdobject->SetActive(kTRUE,c_output_photon_branches_regex);
  m_truth_d3pdobject->SetActive(kTRUE,c_output_truth_branches_regex);
  m_met_d3pdobject->SetActive(kTRUE,"\\bet\\b");

  // ---------------- Enabling writing ------------------------
  m_met_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );

  return;

}

void ZgammaTruth::EndInputDataImp( const SInputData& ) throw( SError ) {

  delete m_event_d3pdobject;
  delete m_vxp_d3pdobject;
  delete m_trigger_d3pdobject;
  delete m_electron_d3pdobject;
  delete m_photon_d3pdobject;
  delete m_truth_d3pdobject;
  delete m_met_d3pdobject;

   return;

}

void ZgammaTruth::BeginInputFileImp( const SInputData& ) throw( SError ) {

  m_logger << ::DEBUG  << "BeginInputFileImp " << SLogger::endmsg;
  m_event_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
  m_vxp_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
  m_trigger_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
  m_electron_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
  m_photon_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
  m_truth_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
  m_met_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) ); 

  return;

}

void ZgammaTruth::BeginMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZgammaTruth::EndMasterInputDataImp( const SInputData& ) throw( SError ){

  
  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                  Zgamma Event Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of events passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Events Before Cuts...........:"<<*cf_preselect  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After GRL.............:"<<*cf_grl        <<" ("<<((double)*cf_grl)/((double)*cf_preselect)*100 <<"%)"     <<" ("<<((double)*cf_grl)/((double)*cf_preselect)*100 <<"%)"      <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After LAR Error.......:"<<*cf_larerror   <<" ("<<((double)*cf_larerror)/((double)*cf_grl)*100 <<"%)"      <<" ("<<((double)*cf_larerror)/((double)*cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Vertex..........:"<<*cf_vertex     <<" ("<<((double)*cf_vertex)/((double)*cf_larerror)*100 <<"%)"   <<" ("<<((double)*cf_vertex)/((double)*cf_preselect)*100 <<"%)"   <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Trigger.........:"<<*cf_trigger    <<" ("<<((double)*cf_trigger)/((double)*cf_vertex)*100 <<"%)"    <<" ("<<((double)*cf_trigger)/((double)*cf_preselect)*100 <<"%)"  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events w/ 1 Tag..............:"<<*cf_tag     <<" ("<<((double)*cf_tag)/((double)*cf_trigger)*100 <<"%)"   <<" ("<<((double)*cf_tag)/((double)*cf_preselect)*100 <<"%)"   <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events w/ one photon.........:"<<*cf_photon     <<" ("<<((double)*cf_photon)/((double)*cf_tag)*100 <<"%)"   <<" ("<<((double)*cf_photon)/((double)*cf_preselect)*100 <<"%)"   <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events w/ one probe..........:"<<*cf_probe     <<" ("<<((double)*cf_probe)/((double)*cf_photon)*100 <<"%)"   <<" ("<<((double)*cf_probe)/((double)*cf_preselect)*100 <<"%)"   <<SLogger::endmsg;


  return;

}


void ZgammaTruth::ExecuteEventImp( const SInputData&, Double_t ) throw( SError ) {

  //reset vectors with persistified objects
  for (unsigned int i = 0; i <sel_tags.size(); i++) delete sel_tags.at(i);
  for (unsigned int i = 0; i <sel_probes.size(); i++) delete sel_probes.at(i);
  for (unsigned int i = 0; i <sel_photons.size(); i++) delete sel_photons.at(i);
  sel_tags.clear();
  sel_probes.clear();
  sel_photons.clear();

  ///////////////////////////////////////
  //start cutflow
  ++cf_preselect;
  //TODO - maybe add GRL tool here?
  ++cf_grl;

  if(m_doLarError){
    m_logger << ::DEBUG << "LarError Cut " << SLogger::endmsg;
    if (m_event_d3pdobject->larError() == 2) {
      throw SError( SError::SkipEvent );
    }
  } 
  ++cf_larerror;

  //vertices
  bool vertex_pass = false;
  int n_verts = 0;
  int n_verts2 = 0; //vertices with 2 tracks, needed for electron likelihood
  if(m_doVert){
    m_logger << ::DEBUG << "Vertex Cut " << SLogger::endmsg;
    m_logger << ::DEBUG << "Number of vertices: " << m_vxp_d3pdobject->n() << SLogger::endmsg;
    for (int n_vtx = 0; n_vtx < m_vxp_d3pdobject->n(); n_vtx++){ 
      if (m_vxp_d3pdobject->nTracks()->at(n_vtx) >= 2 ) { 
	n_verts2++;
      }
      if (m_vxp_d3pdobject->nTracks()->at(n_vtx) >= 3 ) { 
	n_verts++;
	vertex_pass = true; 
      }
    }
    if (!vertex_pass) throw SError( SError::SkipEvent );
  } 
  ++cf_vertex;
 
  //trigger cuts
  //bool trigger_pass = false;
  //if(m_doTrig){
  //  m_logger << ::DEBUG << "Trigger Cut " << SLogger::endmsg;
  //  GET_TOOL(trig_select, TriggerSelector, "TriggerSelector");
  //  trigger_pass = trig_select->SelectTriggers( m_trigger_d3pdobject );
  //  if (!trigger_pass) throw SError( SError::SkipEvent );
  //}
  ++cf_trigger;
  



  GET_TOOL(tag_select, TagSelector, "TagSelector");  
  tag_select->SelectElectrons(sel_tags, m_electron_d3pdobject, m_event_d3pdobject,n_verts2); 
  if(sel_tags.size() < 1)  throw SError( SError::SkipEvent );
  ++cf_tag;  

  GET_TOOL(photon_select, PhotonSelector, "PhotonSelector");  
  photon_select->SelectPhotons(sel_photons, m_photon_d3pdobject, m_event_d3pdobject); 
  if(sel_photons.size() < 1)  throw SError( SError::SkipEvent ); 
  ++cf_photon;

  GET_TOOL(probe_select, ProbeSelector, "ProbeSelector"); //put photon in here, too
  probe_select->SelectElectrons(sel_probes, sel_tags, sel_photons, m_electron_d3pdobject, m_event_d3pdobject,n_verts2);
  if(sel_probes.size() < 1)  throw SError( SError::SkipEvent );
  ++cf_probe;

  //remove photons that are too close to electrons --replaced by removal only if too close to specific tag/probe
  //m_logger << ::DEBUG << "Number of selected photons in event: " << sel_photons.size() << SLogger::endmsg;
  //photon_select->RemoveElectronPhotonOverlap(sel_photons,sel_tags,0.2);
  //photon_select->RemoveElectronPhotonOverlap(sel_photons,sel_probes,0.2);
  //m_logger << ::DEBUG << "Number of selected photons in event after overlap removal: " << sel_photons.size() << SLogger::endmsg;

  //calculate pair properties (using the photon that gives mass closest to Z mass)
  probe_select->CalculateTPGVariables(sel_probes,sel_tags,sel_photons);  


  ////////////////////////
  //to store

  //event properties
  RunNumber= m_event_d3pdobject->RunNumber();
  EventNumber= m_event_d3pdobject->EventNumber();
  lbn= m_event_d3pdobject->lbn();
  if(!is_data()) mc_channel_number = m_event_d3pdobject->mc_channel_number();
  else  mc_channel_number = 0;
  n_vertices3 = n_verts;

  probe_n = sel_probes.size();
  tag_n = sel_tags.size();
  photon_n = sel_photons.size();

  //vectors of probe properties
  //loop over probes

//clear vectors
    probe_E.clear();
    probe_Et.clear();
    probe_eta.clear();
    probe_phi.clear();
    probe_type.clear();
    probe_origin.clear();
    probe_originbkg.clear();
    probe_truth_matched.clear();

    probe_index.clear();
    probe_tag_index.clear();
    probe_tag_vecindex.clear();
    probe_photon_index.clear();
    probe_photon_vecindex.clear();

    probe_tag_OS.clear();

    probe_tag_mass.clear();
    probe_tag_photon_mass.clear();
    probe_tag_dR.clear();
    probe_photon_dR.clear();

    p_tag_photon_mass.clear();
    p_tag_photon_dR.clear();

    //conditions
    probe_passML.clear();
    probe_passTight.clear();
    //tag conditions
    probe_tag_passTight.clear();

    tag_E.clear();
    tag_Et.clear();
    tag_eta.clear();
    tag_phi.clear();
    tag_index.clear();
    tag_type.clear();
    tag_origin.clear();
    tag_originbkg.clear();
    tag_truth_matched.clear();

    photon_E.clear();
    photon_Et.clear();
    photon_eta.clear();
    photon_phi.clear();
    photon_topoiso20.clear();
    photon_topoiso40.clear();
    photon_truth_type.clear();
    photon_type.clear();
    photon_origin.clear();
    photon_isConv.clear();


  for(std::vector<ProbeElectron*>::iterator itr = sel_probes.begin(); itr != sel_probes.end(); ++itr) { 
    probe_E.push_back((*itr)->cl_E_cal());
    probe_Et.push_back((*itr)->cl_Et());
    probe_eta.push_back((*itr)->tracketa());
    probe_phi.push_back((*itr)->trackphi());

    if(!is_data()){
        probe_type.push_back((*itr)->type());
        probe_origin.push_back((*itr)->origin());
        probe_originbkg.push_back((*itr)->originbkg());
        probe_truth_matched.push_back((*itr)->truth_matched());
   }

    probe_index.push_back((*itr)->GetIndex());
    probe_tag_index.push_back((*itr)->GetTagIndex());
    probe_tag_vecindex.push_back((*itr)->GetTagVecIndex()); 
    probe_photon_index.push_back((*itr)->GetPhotonIndex());
    probe_photon_vecindex.push_back((*itr)->GetPhotonVecIndex());

    probe_tag_OS.push_back((*itr)->GetOSTP());

    probe_tag_mass.push_back((*itr)->GetMassTP());
    probe_tag_photon_mass.push_back((*itr)->GetMassTPG());
    probe_tag_dR.push_back((*itr)->GetDeltaRTP());
    probe_photon_dR.push_back((*itr)->GetDeltaRPG());
   
    p_tag_photon_mass.push_back((*itr)->GetMassTG());
    p_tag_photon_dR.push_back((*itr)->GetDeltaRTG());  

    //conditions
    probe_passML.push_back((*itr)->GetPassML());
    probe_passTight.push_back((*itr)->GetPassTight());

   //tag conditions
    probe_tag_passTight.push_back((*itr)->GetTagPassTight());

  }

  for(std::vector<Electron*>::iterator itr = sel_tags.begin(); itr != sel_tags.end(); ++itr) { 

    tag_E.push_back((*itr)->cl_E_cal());
    tag_Et.push_back((*itr)->cl_Et());
    tag_eta.push_back((*itr)->tracketa());
    tag_phi.push_back((*itr)->trackphi());
    tag_index.push_back((*itr)->GetIndex());
  
     if(!is_data()){
        tag_type.push_back((*itr)->type());
        tag_origin.push_back((*itr)->origin());
        tag_originbkg.push_back((*itr)->originbkg());
        tag_truth_matched.push_back((*itr)->truth_matched());
   }
 }

  for(std::vector<Photon*>::iterator itr = sel_photons.begin(); itr != sel_photons.end(); ++itr) { 

    photon_E.push_back((*itr)->cl_E());
    photon_Et.push_back((*itr)->cl_pt());
    photon_eta.push_back((*itr)->cl_eta());
    photon_phi.push_back((*itr)->cl_phi());
  
    photon_topoiso20.push_back((*itr)->topoiso20());
    photon_topoiso40.push_back((*itr)->topoiso40());
    
    if(!is_data()){
        photon_truth_type.push_back((*itr)->truth_type());
        photon_type.push_back((*itr)->type());
        photon_origin.push_back((*itr)->origin());
   }
    photon_isConv.push_back((*itr)->isConv());
    
  }

  m_met_d3pdobject->ReadAllActive();

  m_logger << ::DEBUG << "*****" << SLogger::endmsg;

  //weights
  //calculate event weight
  evt_weight = 1.0;
  pileup_sf = 1.0;
  vertex_sf = 1.0;

 if (!is_data()) {
   GET_TOOL(sf_tool, ScaleFactorTool, "ScaleFactorTool");
   m_logger << ::DEBUG << "Pileup SF " << SLogger::endmsg;
   //pileup_sf  = sf_tool->PileupSF(m_event_d3pdobject->RunNumber(), m_event_d3pdobject->mc_channel_number(),m_event_d3pdobject->averageIntPerXing());
   pileup_sf  = sf_tool->PileupSF(m_event_d3pdobject);
   m_logger << ::DEBUG << "Vertex SF " << SLogger::endmsg;
   vertex_sf  = sf_tool->VertexSF( m_truth_d3pdobject[0].vx_z()->at(2) );
}//end is not data

   evt_weight = evt_weight*((DoPileupSF ? pileup_sf : 1.0)*(DoVertexSF ? vertex_sf : 1.0));

   return;

}

