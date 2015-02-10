// $Id: ZXCutflow.cxx 19801 2012-11-14 15:30:24Z stahlman $

#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Muon.h"
#include "Electron.h"
#include "Jet.h"
#include "Quadruplet.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "ScaleFactorTool.h"
#include "EnergyRescalerTool.h"
#include "IDTool.h"

//ZZSelection
#include "TriggerSelector.h"
#include "MuonSelector.h"
#include "ElectronSelector.h"
#include "JetSelector.h"


// Local include(s):
#include "../include/XSelector.h"

//RootCore
#include "egammaAnalysisUtils/CaloIsoCorrection.h"

#include "../include/ZXCutflow.h"


const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( ZXCutflow );

ZXCutflow::ZXCutflow()
  : CycleBase(), 
    m_doGRL ( true ),
    m_doTrig ( true ),
    m_doVert ( true ),
    cf_preselect( "preselect", this ),
    cf_el_preselect( "el_preselect", this ),
    cf_mu_preselect( "mu_preselect", this ),
    cf_grl( "grl", this ),
    cf_larerror( "larerror", this ),
    cf_tileerror( "tileerror", this ),
    cf_daqerror( "daqerror", this ),
    cf_trigger( "trigger", this ),
    cf_el_trigger( "el_trigger", this ),
    cf_mu_trigger( "mu_trigger", this ),
    cf_vertex( "vertex", this ),
    cf_el_vertex( "el_vertex", this ),
    cf_mu_vertex( "mu_vertex", this ),
    cf_leptons( "leptons", this ),
    cf_two_mu( "four_mu", this ),
    cf_two_el( "four_el", this ),
    cf_mass_cut( "mass_cut", this ),
    cf_weighted_final( "cf_weighted_final", this )

{

    m_logger << DEBUG  << "INITIALIZE" << SLogger::endmsg;

   SetLogName( GetName() );
   DeclareProperty( "RecoTreeString", m_recoTreeName );
   DeclareProperty( "OutputTreeString", c_output_tree_name = "output");
   DeclareProperty( "DoGRL", m_doGRL = false);
   DeclareProperty( "DoLarError", m_doLarError = true);
   DeclareProperty( "DoTileError", m_doTileError );
   DeclareProperty( "DoDaqError", m_doDaqError );
   DeclareProperty( "DoTrigger", m_doTrig = true );
   DeclareProperty( "DoVertex", m_doVert = true );
   DeclareProperty( "ProdType", m_ProdType = "incl" );
   //DeclareProperty( "DoVH", m_DoVH = false );
   DeclareProperty( "RequireExtraMuon", m_reqExtraMuon = false );

   DeclareProperty( "DoLeptonSF", DoLeptonSF = true );
   DeclareProperty( "DoTriggerSF", DoTriggerSF = true);
   DeclareProperty( "DoPileupSF", DoPileupSF = true );
   DeclareProperty( "DoVertexSF", DoVertexSF = true );

   DeclareProperty( "JetContainer", c_jet_container = "jet_akt4topoem_");
   
   DeclareProperty( "DebugRun",   m_debugRun   = 0 );
   DeclareProperty( "DebugEvent", m_debugEvent = 0 );
   
   DeclareProperty("output_event_branches_regex", c_output_event_branches_regex = ".*");
   DeclareProperty("output_mcevt_branches_regex", c_output_mcevt_branches_regex = ".*");
   DeclareProperty("output_electron_trigger_branches_regex", c_output_electron_trigger_branches_regex = ".*");
   DeclareProperty("output_muon_trigger_branches_regex", c_output_muon_trigger_branches_regex = ".*");
   DeclareProperty("output_trigger_branches_regex", c_output_trigger_branches_regex = ".*");
   DeclareProperty("output_vxp_branchegs_regex", c_output_vxp_branches_regex = ".*");
   DeclareProperty("output_electron_branches_regex", c_output_electron_branches_regex = ".*");
   DeclareProperty("output_muon_branches_regex", c_output_muon_branches_regex = ".*");
   //DeclareProperty("output_jet_branches_regex", c_output_jet_branches_regex = ".*");
   DeclareProperty("output_met_branches_regex", c_output_met_branches_regex = ".*");
   DeclareProperty("output_truth_branches_regex", c_output_truth_branches_regex = ".*");
   //DeclareProperty("output_photon_branches_regex", c_output_photon_branches_regex = ".*");
         
   DECLARE_TOOL(TriggerSelector,    "TriggerSelector");
   DECLARE_TOOL(MuonSelector,       "MuonSelector");
   DECLARE_TOOL(ElectronSelector,   "ElectronSelector");
   DECLARE_TOOL(ScaleFactorTool,    "ScaleFactorTool");
   DECLARE_TOOL(EnergyRescalerTool, "EnergyRescalerTool");
   DECLARE_TOOL(IDTool,             "IDTool");
   DECLARE_TOOL(JetSelector,        "JetSelector");
   DECLARE_TOOL(XSelector,          "XSelector");
  
}

ZXCutflow::~ZXCutflow() {

}

void ZXCutflow::BeginCycleImp() throw( SError ) {  
  

  return;

}

void ZXCutflow::EndCycleImp() throw( SError ) {

   return;

}

void ZXCutflow::BeginInputDataImp( const SInputData& ) throw( SError ) {


  //Declare output variables:  
  DeclareVariable( n_vertices, "n_vertices");  
  
  DeclareVariable( z_mass, "z_mass");
  DeclareVariable( z_type, "z_type");
  
  DeclareVariable( n_x_el, "n_x_el");
  
  DeclareVariable( x_index,     "x_index");
  DeclareVariable( x_bitmask,   "x_bitmask");

  DeclareVariable( x_pt,        "x_pt");
  DeclareVariable( x_eta,       "x_eta");
  DeclareVariable( x_phi,       "x_phi");
  
  DeclareVariable( x_trk_iso20, "x_trk_iso20");
  DeclareVariable( x_trk_iso30, "x_trk_iso30");
  DeclareVariable( x_trk_iso40, "x_trk_iso40");

  DeclareVariable( x_calo_iso20, "x_calo_iso20");
  DeclareVariable( x_calo_iso30, "x_calo_iso30");
  DeclareVariable( x_calo_iso40, "x_calo_iso40");

  DeclareVariable( x_matched_jet_deltaR, "x_matched_jet_deltaR");
  DeclareVariable( x_matched_jet_btagweight, "x_matched_jet_btagweight");
  DeclareVariable( x_jet_btagged_deltaR, "x_jet_btagged_deltaR");

  DeclareVariable( n_x_mu, "n_x_mu");
  
  DeclareVariable( x_mu_index,     "x_mu_index");
  DeclareVariable( x_mu_bitmask,   "x_mu_bitmask");

  DeclareVariable( x_mu_pt,        "x_mu_pt");
  DeclareVariable( x_mu_eta,       "x_mu_eta");
  DeclareVariable( x_mu_phi,       "x_mu_phi");
  
  DeclareVariable( x_mu_trk_iso20, "x_mu_trk_iso20");
  DeclareVariable( x_mu_trk_iso30, "x_mu_trk_iso30");
  DeclareVariable( x_mu_trk_iso40, "x_mu_trk_iso40");

  DeclareVariable( x_mu_calo_iso20, "x_mu_calo_iso20");
  DeclareVariable( x_mu_calo_iso30, "x_mu_calo_iso30");
  DeclareVariable( x_mu_calo_iso40, "x_mu_calo_iso40");

  DeclareVariable( evt_weight, "evt_weight");
  DeclareVariable( lepton_sf,  "lepton_sf");
  DeclareVariable( trigger_sf, "trigger_sf");
  DeclareVariable( pileup_sf,  "pileup_sf");
  DeclareVariable( vertex_sf,  "vertex_sf");
  DeclareVariable( mc_event_weight,   "mc_event_weight");

  //Declare Histograms
  Book("NEvents", "Number of Events", 2, 0., 2.,"");



  // -----------------------------------------------------------------
  // ---------------- D3PD Reader constuctors ------------------------
 
  //if(is_data()) cout<<"isData!!!"<<endl;
  //else cout<<"isMC!!!"<<endl;
 
  // inputs/outputs
  m_event_d3pdobject = new D3PDReader::EventInfoD3PDObject( m_entry_number );
  m_trigger_d3pdobject = new D3PDReader::TriggerD3PDObject( m_entry_number );
  m_vxp_d3pdobject = new D3PDReader::PrimaryVertexD3PDObject( m_entry_number );

  m_electron_d3pdobject = new D3PDReader::ElectronD3PDObject( m_entry_number, "el_" );
  m_muon_staco_d3pdobject = new D3PDReader::MuonD3PDObject( m_entry_number, "mu_staco_" );
  m_muon_calo_d3pdobject = new D3PDReader::MuonD3PDObject( m_entry_number, "mu_calo_" );
  m_jet_d3pdobject = new D3PDReader::JetD3PDObject( m_entry_number, c_jet_container.c_str() );

  m_truth_d3pdobject = new D3PDReader::TruthParticleD3PDObject( m_entry_number );
  m_mcevt_d3pdobject = new D3PDReader::MCEvtD3PDObject( m_entry_number );
   
  m_met_d3pdobject = new D3PDReader::METD3PDObject( m_entry_number, "MET_RefFinal_" );
  //m_photon_d3pdobject = new D3PDReader::PhotonD3PDObject( m_entry_number, "ph_" );

  //m_muon_trigger_d3pdobject = new D3PDReader::TrigMuonEFInfoD3PDObject( m_entry_number );
  //m_electron_trigger_d3pdobject = new D3PDReader::TrigElectronD3PDObject( m_entry_number );

  // -------------------------------------------------------------
  // ---------------- Activating branches ------------------------

  // control what is read out by setting those branches Active
  // - all branches are Not Active by default
  //m_event_d3pdobject->SetActive(kTRUE,c_output_event_branches_regex);
  //m_trigger_d3pdobject->SetActive(kTRUE,c_output_trigger_branches_regex);
  //m_vxp_d3pdobject->SetActive(kTRUE,c_output_vxp_branches_regex);
  //m_electron_d3pdobject->SetActive(kTRUE,c_output_electron_branches_regex);
  //m_muon_staco_d3pdobject->SetActive(kTRUE,c_output_muon_branches_regex);
  //m_muon_calo_d3pdobject->SetActive(kTRUE,c_output_muon_branches_regex);
  //m_jet_d3pdobject->SetActive(kTRUE,c_output_jet_branches_regex);
  //m_truth_d3pdobject->SetActive(kTRUE,c_output_truth_branches_regex);
  //m_met_d3pdobject->SetActive(kTRUE,c_output_met_branches_regex);

    if(!is_data()) m_event_d3pdobject->SetActive(kTRUE,"mc_channel_number|RunNumber|EventNumber|lbn|actualIntPerXing|averageIntPerXing");
    else m_event_d3pdobject->SetActive(kTRUE,"RunNumber|EventNumber|lbn|actualIntPerXing|averageIntPerXing"); 
    if(!is_data()) m_truth_d3pdobject->SetActive(kTRUE,"\\bn\\b|phi|eta|pt|m|status|pdgId");
    if(!is_data()) m_electron_d3pdobject->SetActive(kTRUE,"\\bcl_eta\\b|\\btracketa\\b|\\bnTRTHits\\b|\\bnTRTOutliers\\b|\\bnTRTHighTHits\\b|\\bnTRTHighTOutliers\\b|\\bTRTHighTOutliersRatio\\b|\\brphi\\b|\\btracksigd0pvunbiased\\b|\\btrackd0pvunbiased\\b|\\bf1\\b|\\bexpectHitInBLayer\\b|\\bnBLHits\\b|\\bnPixHits\\b|\\bnPixelDeadSensors\\b|\\btype\\b|\\borigin\\b|\\btypebkg\\b|\\boriginbkg\\b");
    else m_electron_d3pdobject->SetActive(kTRUE,"\\bcl_eta\\b|\\btracketa\\b|\\bnTRTHits\\b|\\bnTRTOutliers\\b|\\bnTRTHighTHits\\b|\\bnTRTHighTOutliers\\b|\\bTRTHighTOutliersRatio\\b|\\brphi\\b|\\btracksigd0pvunbiased\\b|\\btrackd0pvunbiased\\b|\\bf1\\b|\\bexpectHitInBLayer\\b|\\bnBLHits\\b|\\bnPixHits\\b|\\bnPixelDeadSensors\\b");
    m_muon_staco_d3pdobject->SetActive(kTRUE,"\\beta\\b|\\bnTRTHits\\b|\\bnTRTOutliers\\b|\\bnTRTHighTHits\\b|\\bnTRTHighTOutliers\\b");
    m_muon_calo_d3pdobject->SetActive(kTRUE,"\\beta\\b|\\bnTRTHits\\b|\\bnTRTOutliers\\b|\\bnTRTHighTHits\\b|\\bnTRTHighTOutliers\\b");

    m_met_d3pdobject->SetActive(kTRUE,"\\bet\\b");

   //m_muon_trigger_d3pdobject->SetActive(kTRUE,c_output_muon_trigger_branches_regex);
  //m_electron_trigger_d3pdobject->SetActive(kTRUE,c_output_electron_trigger_branches_regex);
 //m_mcevt_d3pdobject->SetActive(kTRUE,c_output_mcevt_branches_regex);
 //m_photon_d3pdobject->SetActive(kTRUE,c_output_photon_branches_regex);

  // ----------------------------------------------------------
  // ---------------- Enabling writing ------------------------

  // enable writing (only affects already Active branches!)
  m_event_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );
  m_trigger_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );
  m_vxp_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );

  m_electron_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );
  m_muon_staco_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );
  m_muon_calo_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );

  m_truth_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );
  
  //m_photon_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );
  //m_o_jet_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );
  m_met_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );

  return;

}

void ZXCutflow::EndInputDataImp( const SInputData& ) throw( SError ) {

   // inputs/outputs
    delete m_event_d3pdobject;
    delete m_trigger_d3pdobject;
    delete m_vxp_d3pdobject;

    delete m_electron_d3pdobject;
    delete m_muon_staco_d3pdobject;
    delete m_muon_calo_d3pdobject;
    delete m_jet_d3pdobject;

    delete m_truth_d3pdobject;
    
    //delete m_photon_d3pdobject;
    delete m_met_d3pdobject;
    //bool m_doVH;
    

   return;

}

void ZXCutflow::BeginInputFileImp( const SInputData& ) throw( SError ) {

    m_logger << DEBUG  << "BeginInputFileImp "                         << SLogger::endmsg;

    m_event_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_trigger_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_vxp_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_electron_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_staco_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_calo_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_jet_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_mcevt_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_truth_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    //m_in_photon_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_met_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );


   return;

}

void ZXCutflow::BeginMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZXCutflow::EndMasterInputDataImp( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"                  H -> ZZ Event Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of events passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Events Before Cuts...........:"<<*cf_preselect  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After GRL.............:"<<*cf_grl        <<" ("<<((double)*cf_grl)/((double)*cf_preselect)*100 <<"%)"     <<" ("<<((double)*cf_grl)/((double)*cf_preselect)*100 <<"%)"      <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After LAR Error.......:"<<*cf_larerror   <<" ("<<((double)*cf_larerror)/((double)*cf_grl)*100 <<"%)"      <<" ("<<((double)*cf_larerror)/((double)*cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Vertex..........:"<<*cf_vertex     <<" ("<<((double)*cf_vertex)/((double)*cf_larerror)*100 <<"%)"   <<" ("<<((double)*cf_vertex)/((double)*cf_preselect)*100 <<"%)"   <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Trigger.........:"<<*cf_trigger    <<" ("<<((double)*cf_trigger)/((double)*cf_vertex)*100 <<"%)"    <<" ("<<((double)*cf_trigger)/((double)*cf_preselect)*100 <<"%)"  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Z Mass Cut......:"<<*cf_mass_cut    <<" ("<<((double)*cf_mass_cut)/((double)*cf_trigger)*100 <<"%)"    <<" ("<<((double)*cf_mass_cut)/((double)*cf_preselect)*100 <<"%)"  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Full Sel(weight): "<<*cf_weighted_final <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;

  m_logger << ALWAYS <<"                  H -> ZZ Event Object Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons Before Cuts..........:"<<*cf_mu_preselect  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Vertex.........:"<<*cf_mu_vertex  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Muons After Trigger........:"<<*cf_mu_trigger  <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons Before Cuts......:"<<*cf_el_preselect  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Vertex.....:"<<*cf_el_vertex  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Electrons After Trigger....:"<<*cf_el_trigger  <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;


  return;

}

void ZXCutflow::ExecuteEventImp( const SInputData&, Double_t ) throw( SError ) {

  //only do this once (or so)
  if(cf_preselect == 0){
      if(!is_data()) m_mc_channel_number = m_event_d3pdobject->mc_channel_number();
      else m_mc_channel_number = -1;
      m_logger << ALWAYS <<"m_mc_channel_number: "<<m_mc_channel_number<<SLogger::endmsg;
      Set_MC_channel_number(m_mc_channel_number);
  }

  Hist("NEvents")->Fill( 0., 1. );
  if (is_data()){
     Hist("NEvents")->Fill( 1., 1. );
  } else {
     if( m_mcevt_d3pdobject->mcevt_weight.IsAvailable() ) {
        Hist("NEvents")->Fill( 1., m_mcevt_d3pdobject->mcevt_weight()->at(0).at(0) );
     } else {
        Hist("NEvents")->Fill( 1., 1. );
     }
  }

  //reset vectors with persistified objects
  for (unsigned int i = 0; i <sel_muons.size(); i++)delete sel_muons.at(i);
  for (unsigned int i = 0; i <sel_electrons.size(); i++) delete sel_electrons.at(i);
  for (unsigned int i = 0; i <sel_jets.size(); i++) delete sel_jets.at(i);
  for (unsigned int i = 0; i <x_electrons.size(); i++) delete x_electrons.at(i);
  for (unsigned int i = 0; i <x_muons.size(); i++) delete x_muons.at(i);
    
  sel_muons.clear();
  sel_electrons.clear();
  sel_jets.clear();
  x_electrons.clear();
  x_muons.clear();

  //debug filter for picking out events
  if (m_debugEvent != 0){
    if (m_event_d3pdobject->EventNumber() != m_debugEvent || m_event_d3pdobject->RunNumber() != m_debugRun) throw SError( SError::SkipEvent );
       m_logger << ALWAYS << "Found debug event!" << SLogger::endmsg;    
  }
  
  //Removing MC events with bad trigger due to bug
  //Done before preselect!!
  if (!is_data()){   
    GET_TOOL(trig_select, TriggerSelector, "TriggerSelector");
    
    if (!(trig_select->hasMCTriggerInfo())){
       m_logger << WARNING << "No trigger info: skipping event! " << SLogger::endmsg;
       throw SError( SError::SkipEvent );
    }
  }

  ++cf_preselect;
  cf_el_preselect += m_electron_d3pdobject->n();
  cf_mu_preselect += m_muon_staco_d3pdobject->n() + m_muon_calo_d3pdobject->n();
  
  //TODO - maybe add GRL tool here?
  ++cf_grl;

  if(m_doLarError && is_data()){
    m_logger << DEBUG << "LarError Cut " << SLogger::endmsg;
    if (m_event_d3pdobject->larError() == 2) {
      throw SError( SError::SkipEvent );
    }
  }  
  ++cf_larerror;

  if(m_doTileError && is_data()){
    m_logger << DEBUG << "TileError Cut " << SLogger::endmsg;
    if (m_event_d3pdobject->tileError() == 2) {
      throw SError( SError::SkipEvent );
    }
  } 
  ++cf_tileerror;

  if (m_doDaqError && is_data()) {
    m_logger << DEBUG << "DaqError Cut" << SLogger::endmsg;
    if ((m_event_d3pdobject->coreFlags()&0x40000) != 0) { // This is an incomplete event remove from analysis
      throw SError( SError::SkipEvent );     
    }
  }
  ++cf_daqerror;
  
  //vertices
  bool vertex_pass = false;
  int n_verts = 0;
  int n_verts2 = 0; //vertices with 2 tracks, needed for electron likelihood
  if(m_doVert){
    m_logger << DEBUG << "Vertex Cut " << SLogger::endmsg;
    m_logger << DEBUG << "Number of vertices: " << m_vxp_d3pdobject->n() << SLogger::endmsg;
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
  cf_el_vertex += m_electron_d3pdobject->n();
  cf_mu_vertex += m_muon_staco_d3pdobject->n() + m_muon_calo_d3pdobject->n();
  n_vertices = n_verts;


  //trigger cuts
  bool trigger_pass = false;
  //if(m_doTrig){
    m_logger << DEBUG << "Trigger Cut " << SLogger::endmsg;
    
    GET_TOOL(trig_select, TriggerSelector, "TriggerSelector");
    trigger_pass = trig_select->SelectTriggers( m_trigger_d3pdobject );
        
    if (!trigger_pass) throw SError( SError::SkipEvent );
  //}  
  ++cf_trigger;
  cf_el_trigger += m_electron_d3pdobject->n();
  cf_mu_trigger += m_muon_staco_d3pdobject->n() + m_muon_calo_d3pdobject->n();


  //need to call doiso, d0 for electrons and muons in config file
  GET_TOOL(mu_select, MuonSelector, "MuonSelector");
  mu_select->SelectMuons(sel_muons, m_muon_staco_d3pdobject, m_muon_calo_d3pdobject, m_event_d3pdobject->EventNumber()); 

  GET_TOOL(el_select, ElectronSelector, "ElectronSelector");  
  el_select->SelectElectrons(sel_electrons, m_electron_d3pdobject, m_event_d3pdobject,n_verts2); 
  
  //overlap removal between electrons and muons
  el_select->RemoveElectronMuonOverlap(sel_muons, sel_electrons);  
  
  bool passed_leptons = false;
  if ( sel_muons.size() >=2) { passed_leptons = true; cf_two_mu++;}
  if ( sel_electrons.size() >=2) { passed_leptons = true; cf_two_el++; }

  if (!passed_leptons){
    throw SError( SError::SkipEvent );  
  }
  cf_leptons++;

  
  //select candidate Z from muons
  std::vector<Muon*> sel_muons_pos;
  std::vector<Muon*> sel_muons_neg;
  
  for (unsigned int i = 0; i < sel_muons.size(); i++){
    if (sel_muons.at(i)->charge() == +1){
      sel_muons_pos.push_back(sel_muons.at(i));
    } else if (sel_muons.at(i)->charge() == -1){
      sel_muons_neg.push_back(sel_muons.at(i));
    }
  }
  
  double largest_mass = 0;
  int index_pos_mu = -1;
  int index_neg_mu = -1;
  bool passZmumu = true;
  for (unsigned int i =0; i < sel_muons_pos.size(); i++) {
      for (unsigned int j =0; j < sel_muons_neg.size(); j++) {
          TLorentzVector tlv_pos; tlv_pos.SetPtEtaPhiM(sel_muons_pos[i]->Pt(), sel_muons_pos[i]->eta(), sel_muons_pos[i]->phi(), sel_muons_pos[i]->m());
	  TLorentzVector tlv_neg; tlv_neg.SetPtEtaPhiM(sel_muons_neg[j]->Pt(), sel_muons_neg[j]->eta(), sel_muons_neg[j]->phi(), sel_muons_neg[j]->m());
          if(tlv_pos.DeltaR(tlv_neg) < 0.1) continue;
	  if(!(trig_select->MatchTriggers(sel_muons_pos[i],sel_muons_neg[j]))) continue;
          double mass = (tlv_pos + tlv_neg).M();
	  if (mass > largest_mass) {
	     largest_mass = mass;
	     index_pos_mu = i;
	     index_neg_mu = j;
	  }
     }   
  }

  //apply Z window
  if (!(largest_mass > 75000 && largest_mass < 105000)){
    m_logger << DEBUG  << "Zmumu candidate not in the Z mass window" << SLogger::endmsg;
    passZmumu = false;
  }


  //select candidate Z from electrons
  std::vector<Electron*> sel_electrons_pos;
  std::vector<Electron*> sel_electrons_neg;
  
  for (unsigned int i = 0; i < sel_electrons.size(); i++){
    if (sel_electrons.at(i)->charge() == +1){
      sel_electrons_pos.push_back(sel_electrons.at(i));
    } else if (sel_electrons.at(i)->charge() == -1){
      sel_electrons_neg.push_back(sel_electrons.at(i));
    }
  }
  m_logger << DEBUG  << "after charge, ee" << SLogger::endmsg; 
 
  largest_mass = 0;
  int index_pos_el = -1;
  int index_neg_el = -1;
  bool passZee = true;
  for (unsigned int i =0; i < sel_electrons_pos.size(); i++) {
      for (unsigned int j =0; j < sel_electrons_neg.size(); j++) {
	  TLorentzVector tlv_pos; tlv_pos.SetPtEtaPhiE(sel_electrons_pos[i]->cl_Et(), sel_electrons_pos[i]->tracketa(), sel_electrons_pos[i]->trackphi(), sel_electrons_pos[i]->cl_E_cal());
	  TLorentzVector tlv_neg; tlv_neg.SetPtEtaPhiE(sel_electrons_neg[j]->cl_Et(), sel_electrons_neg[j]->tracketa(), sel_electrons_neg[j]->trackphi(), sel_electrons_neg[j]->cl_E_cal());
          if(tlv_pos.DeltaR(tlv_neg) < 0.1) continue;
          if(!(trig_select->MatchTriggers(sel_electrons_pos[i],sel_electrons_neg[j]))) continue;
	  double mass = (tlv_pos + tlv_neg).M();
	  if (mass > largest_mass) {
	     largest_mass = mass;
	     index_pos_el = i;
	     index_neg_el = j;
	  }
     }   
  }
  m_logger << DEBUG  << "after mass, ee" << SLogger::endmsg;
  //apply Z window
  if (!(largest_mass > 75000 && largest_mass < 105000)){
    m_logger << DEBUG  << "Zee candidate not in the Z mass window" << SLogger::endmsg;
    passZee = false;
  }

  if ( !passZee && !passZmumu ) {
    m_logger << DEBUG  << "No reconstructed Z candidate found - Skipping event" << SLogger::endmsg;
    throw SError( SError::SkipEvent );  
  }

  if ( passZee && passZmumu ) {
    m_logger << DEBUG  << "2 Z candidate founds - Skipping event" << SLogger::endmsg;
    throw SError( SError::SkipEvent );  
  }
  
  int index_pos = -1;
  int index_neg = -1;

  TLorentzVector tlv_pos;
  TLorentzVector tlv_neg;
  Electron* el_pos;
  Electron* el_neg;
  Muon* mu_pos;
  Muon* mu_neg;

  if (passZmumu) {     
   mu_pos = sel_muons_pos[index_pos_mu];
   mu_neg = sel_muons_neg[index_neg_mu];

   tlv_pos.SetPtEtaPhiM(mu_pos->Pt(), mu_pos->eta(), mu_pos->phi(), mu_pos->m());
   tlv_neg.SetPtEtaPhiM(mu_neg->Pt(), mu_neg->eta(), mu_neg->phi(), mu_neg->m());
   
   z_type = 2;
  }

  if (passZee) {     
   el_pos = sel_electrons_pos[index_pos_el];
   el_neg = sel_electrons_neg[index_neg_el];

   tlv_pos.SetPtEtaPhiE(el_pos->cl_Et(), el_pos->tracketa(), el_pos->trackphi(), el_pos->cl_E_cal());
   tlv_neg.SetPtEtaPhiE(el_neg->cl_Et(), el_neg->tracketa(), el_neg->trackphi(), el_neg->cl_E_cal());

   z_type = 1;

  }
  
  cf_mass_cut++;
  
  //require additional muon for heavy flavor studies
  GET_TOOL(x_select, XSelector, "XSelector");  

  x_select->SelectXMuons(x_muons, m_muon_staco_d3pdobject, m_muon_calo_d3pdobject, m_event_d3pdobject->EventNumber()); 

  TLorentzVector tlv_x;

  //remove overlap with electrons from Z
  for (unsigned int i =0; i < x_muons.size(); i++) {
     tlv_x.SetPtEtaPhiM(x_muons[i]->Pt(), x_muons[i]->eta(), x_muons[i]->phi(), x_muons[i]->m());

     //check deltaR         
     if(passZee && (tlv_x.DeltaR(tlv_pos) < 0.1 || tlv_x.DeltaR(tlv_neg) < 0.1)) {
        x_muons.erase(x_muons.begin()+i);
        i--;//subtract one from i to keep counting consistent       
     }
     if(passZmumu && (tlv_x.DeltaR(tlv_pos) < 0.1 || tlv_x.DeltaR(tlv_neg) < 0.1)){
        x_muons.erase(x_muons.begin()+i);
        i--;//subtract one from i to keep counting consistent       
     }
  }

  if (m_reqExtraMuon){      
    if (x_muons.size() == 0) {
       m_logger << DEBUG  << "No Additional Muon. Skipping Event" << SLogger::endmsg;
       throw SError( SError::SkipEvent );  
    }
  }    

  //Now, find X
  
  x_select->SelectXElectrons(x_electrons, m_electron_d3pdobject, m_event_d3pdobject,n_verts2); 
  
  if (passZee || passZmumu) {

    TLorentzVector tlv_x;

    //remove overlap with electrons from Z
    for (unsigned int i =0; i < x_electrons.size(); i++) {
      //if (x_electrons[i]->GetIndex() == el_pos->GetIndex() || x_electrons[i]->GetIndex() == el_neg->GetIndex()) {
         //check deltaR   
         tlv_x.SetPtEtaPhiE(x_electrons[i]->cl_Et(), x_electrons[i]->tracketa(), x_electrons[i]->trackphi(), x_electrons[i]->cl_E_cal());
         if(passZee && (tlv_x.DeltaR(tlv_pos) < 0.1 || tlv_x.DeltaR(tlv_neg) < 0.1)) {
            x_electrons.erase(x_electrons.begin()+i);
            i--;//subtract one from i to keep counting consistent       
      }
       if(passZmumu && (tlv_x.DeltaR(tlv_pos) < 0.1 || tlv_x.DeltaR(tlv_neg) < 0.1)){
            x_electrons.erase(x_electrons.begin()+i);
            i--;//subtract one from i to keep counting consistent       
      }
    }
  }



  //if (passZee) {
  //  //remove overlap with electrons from Z
  //  for (unsigned int i =0; i < x_electrons.size(); i++) {
  //    if (x_electrons[i]->GetIndex() == el_pos->GetIndex() || x_electrons[i]->GetIndex() == el_neg->GetIndex()) {
  //     	 x_electrons.erase(x_electrons.begin()+i); 
  //	 i--;//subtract one from i to keep counting consistent	
  //    }
  //  }
  //}
  
  if (x_electrons.size() == 0) {
    m_logger << DEBUG  << "No X found - Skipping event" << SLogger::endmsg;
    throw SError( SError::SkipEvent );  
  }

  //get some jets/need to adjust pt cut!
  GET_TOOL(jet_select, JetSelector, "JetSelector");
  jet_select->SelectJets(sel_jets, m_jet_d3pdobject, m_event_d3pdobject->EventNumber());

 
  //Now fill, variables
  
  x_index.clear();
  x_bitmask.clear();
  
  x_pt.clear();      
  x_eta.clear();         
  x_phi.clear();         

  x_trk_iso20.clear();   
  x_trk_iso30.clear();   
  x_trk_iso40.clear();   

  x_calo_iso20.clear();   
  x_calo_iso30.clear();   
  x_calo_iso40.clear();   

  x_matched_jet_deltaR.clear();
  x_matched_jet_btagweight.clear();
  x_jet_btagged_deltaR.clear();

  x_mu_index.clear();
  x_mu_bitmask.clear();
  
  x_mu_pt.clear();      
  x_mu_eta.clear();         
  x_mu_phi.clear();         

  x_mu_trk_iso20.clear();   
  x_mu_trk_iso30.clear();   
  x_mu_trk_iso40.clear();   

  x_mu_calo_iso20.clear();   
  x_mu_calo_iso30.clear();   
  x_mu_calo_iso40.clear();   
 
  n_x_el = x_electrons.size();
  n_x_mu = x_muons.size();
            
  //calculate event weight
  evt_weight = 1.0;  
  lepton_sf = 1.0;
  trigger_sf = 1.0;
  pileup_sf = 1.0;
  vertex_sf = 1.0;
  mc_event_weight = 1.0;

  
  if (!is_data()) {
    GET_TOOL(sf_tool, ScaleFactorTool, "ScaleFactorTool");
    m_logger << DEBUG << "Pileup SF " << SLogger::endmsg;
    pileup_sf  = sf_tool->PileupSF(m_event_d3pdobject);

    m_logger << DEBUG << "Vertex SF " << SLogger::endmsg;
    vertex_sf  = sf_tool->VertexSF( m_truth_d3pdobject[0].vx_z()->at(2) );    
  
  m_logger << DEBUG << "mcevt_weight SF " << SLogger::endmsg;
    // if(m_event_d3pdobject->mc_channel_number() == 105200 or m_event_d3pdobject->mc_channel_number() == 146369) mc_event_weight = m_mcevt_d3pdobject->mcevt_weight()->at(0).at(0);
    if( m_mcevt_d3pdobject->mcevt_weight.IsAvailable() ) {
     mc_event_weight = m_mcevt_d3pdobject->mcevt_weight()->at(0).at(0);
    }
 }

  evt_weight = evt_weight*(DoLeptonSF ? lepton_sf : 1.0)*(DoTriggerSF ? trigger_sf : 1.0)*(DoPileupSF ? pileup_sf : 1.0)*(DoVertexSF ? vertex_sf : 1.0);
  
  cf_weighted_final += evt_weight;
  
  //save various variables
  z_mass = (tlv_pos + tlv_neg).M();
  
  for (unsigned int i =0; i < x_electrons.size(); i++) {
     x_index.push_back(  x_electrons[i]->GetIndex() );
     x_bitmask.push_back(  x_electrons[i]->GetXBitMask() );
     
     x_pt.push_back(  x_electrons[i]->cl_Et() );
     x_eta.push_back( x_electrons[i]->tracketa() );
     x_phi.push_back( x_electrons[i]->trackphi() );

     x_trk_iso20.push_back( x_electrons[i]->ptcone(20)/x_electrons[i]->cl_Et() );
     x_trk_iso30.push_back( x_electrons[i]->ptcone(30)/x_electrons[i]->cl_Et() );
     x_trk_iso40.push_back( x_electrons[i]->ptcone(40)/x_electrons[i]->cl_Et() );

     x_calo_iso20.push_back( x_electrons[i]->etcone(20, !is_data())/x_electrons[i]->cl_Et() );
     x_calo_iso30.push_back( x_electrons[i]->etcone(30, !is_data())/x_electrons[i]->cl_Et() );
     x_calo_iso40.push_back( x_electrons[i]->etcone(40, !is_data())/x_electrons[i]->cl_Et() );

    //loop over jets
    double deltaRMin = 100;
    double deltaRMinBtagged = 100;
    double deltaR=0;

    double matched_jet_deltaR = 0;
    double matched_jet_btagweight = -1;
    double jet_btagged_deltaR = 100;

    for(int ijet=0; ijet < sel_jets.size(); ijet++){
            
      deltaR=DeltaR(x_electrons[i]->tracketa(),x_electrons[i]->trackphi(),sel_jets[ijet]->eta(),sel_jets[ijet]->phi());

      if(deltaR < deltaRMin){
	 deltaRMin = deltaR;
         matched_jet_btagweight = sel_jets[ijet]->flavor_weight_MV1();
	}
      if(sel_jets[ijet]->flavor_weight_MV1() > 0.6065 && deltaR < deltaRMinBtagged){
        deltaRMinBtagged = deltaR;
      }
    }
   x_matched_jet_deltaR.push_back(deltaRMin);
   x_matched_jet_btagweight.push_back(matched_jet_btagweight);
   x_jet_btagged_deltaR.push_back(deltaRMinBtagged);

  }//end loop over x (electrons)

  for (unsigned int i =0; i < x_muons.size(); i++) {
     x_mu_index.push_back(  x_muons[i]->GetIndex() );
     x_mu_bitmask.push_back(  x_muons[i]->GetXBitMask() );
     
     x_mu_pt.push_back(  x_muons[i]->Pt() );
     x_mu_eta.push_back( x_muons[i]->eta() );
     x_mu_phi.push_back( x_muons[i]->phi() );

     x_mu_trk_iso20.push_back( x_muons[i]->ptcone(20)/x_muons[i]->Pt() );
     x_mu_trk_iso30.push_back( x_muons[i]->ptcone(30)/x_muons[i]->Pt() );
     x_mu_trk_iso40.push_back( x_muons[i]->ptcone(40)/x_muons[i]->Pt() );

     x_mu_calo_iso20.push_back( x_muons[i]->etcone(20)/x_muons[i]->Pt() );
     x_mu_calo_iso30.push_back( x_muons[i]->etcone(30)/x_muons[i]->Pt() );
     x_mu_calo_iso40.push_back( x_muons[i]->etcone(40)/x_muons[i]->Pt() );
  
  }
    
  // ------------------------------------------------------------
  // ------------------- Managing outputs -----------------------

  // if the event passes, write the selected event to output tree
  // - events are automatically written, just need to manage the outputs here

   // ----------------------------------------------------------
  // ---------------- Enabling writing ------------------------




  // make sure to read all active branches of objects we want to write
  m_event_d3pdobject->ReadAllActive();
  m_trigger_d3pdobject->ReadAllActive();//do we want to save all trigger info??
  m_vxp_d3pdobject->ReadAllActive();
  
  m_electron_d3pdobject->ReadAllActive();
  m_muon_staco_d3pdobject->ReadAllActive();
  m_muon_staco_d3pdobject->ReadAllActive();

  m_truth_d3pdobject->ReadAllActive();

  //m_photon_d3pdobject->ReadAllActive();
  m_met_d3pdobject->ReadAllActive();

  if (m_debugEvent != 0){
    if (m_event_d3pdobject->EventNumber() == m_debugEvent && m_event_d3pdobject->RunNumber() == m_debugRun) {    
      m_logger << ALWAYS << "Found debug Event: Ending Processing!" << SLogger::endmsg;
      throw SError( SError::StopExecution );
    }
  }
  
  
 return;

}

double ZXCutflow::DeltaR(double eta1, double phi1, double eta2, double phi2) {
  double delta_phi = (fabs(phi1 - phi2) > TMath::Pi()) ? 2*TMath::Pi()-fabs(phi1 - phi2) : fabs(phi1 - phi2);
  double delta_eta = eta1 - eta2;
  return sqrt(delta_eta*delta_eta + delta_phi*delta_phi);
}





