// $Id: FiducialCutflow.cxx 27398 2014-06-11 15:30:03Z stahlman $

#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Muon.h"
#include "Electron.h"
#include "Quadruplet.h"
#include "Jet.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "ScaleFactorTool.h"

//RootCore
#include "HiggsZZ4lUtils/GetElicityAngles.h"

//local
#include "../include/FiducialCutflow.h"

const float M_Z = 91187.6;
const float M_MU = 105.658367;
const float GeV = 1000.0;

const string FiducialCutflow::channel_names[] = { "4mu", "4e", "2mu2e", "2e2mu", "4tau", "2l2tau" };

const double FiducialCutflow::m34cut_m34[] = {  12000,  50000 };
const double FiducialCutflow::m34cut_m4l[] = { 140000, 190000 };

ClassImp( FiducialCutflow );

FiducialCutflow::FiducialCutflow()
  : CycleBase(),
    cf_preselect( "preselect", this ),
    cf_higgs( "higgs", this ),
    cf_zs( "zs", this ),
    cf_leptons( "leptons", this ),
    cf_sfos( "sfos", this ), 
    cf_pt( "pt", this ),
    cf_eta( "eta", this ),
    cf_m12( "m12", this ),
    cf_m34( "m34", this ),
    cf_deltar( "deltar", this ),
    cf_jpsi( "jpsi", this ),
    n_4mu(0),
    n_2mu2e(0),
    n_4e(0),
    n_taus(0),
    n_other(0)

{

   SetLogName( GetName() );
   DeclareProperty( "TreeString", m_TreeName = "physics" );
   DeclareProperty( "OutputTreeString", c_output_tree_name = "output");   

   DeclareProperty( "MC_Generator", m_MCGenerator = "POWHEG");   

   DeclareProperty( "DressElectrons",  b_dress_electrons  = false);   
   DeclareProperty( "DressMuons",      b_dress_muons      = false);   
   DeclareProperty( "AllowMispairing", b_allow_mispairing = true);   

   DeclareProperty( "DebugEvent", debug_event = -1);   

   DeclareProperty("output_event_branches_regex", c_output_event_branches_regex = ".*");
   DeclareProperty("output_mcevt_branches_regex", c_output_mcevt_branches_regex = ".*");
   DeclareProperty("output_electron_trigger_branches_regex", c_output_electron_trigger_branches_regex = ".*");
   DeclareProperty("output_muon_trigger_branches_regex", c_output_muon_trigger_branches_regex = ".*");
   DeclareProperty("output_trigger_branches_regex", c_output_trigger_branches_regex = ".*");
   DeclareProperty("output_vxp_branchegs_regex", c_output_vxp_branches_regex = ".*");
   DeclareProperty("output_electron_branches_regex", c_output_electron_branches_regex = ".*");
   DeclareProperty("output_muon_branches_regex", c_output_muon_branches_regex = ".*");
   DeclareProperty("output_jet_branches_regex", c_output_jet_branches_regex = ".*");
   DeclareProperty("output_met_branches_regex", c_output_met_branches_regex = ".*");
   DeclareProperty("output_truth_branches_regex", c_output_truth_branches_regex = ".*");
   //DeclareProperty("output_photon_branches_regex", c_output_photon_branches_regex = ".*");

   DeclareProperty( "JetContainer", c_jet_container = "jet_antikt4truth_");

   //DECLARE_TOOL(EnergyRescalerTool, "EnergyRescalerTool");
   DECLARE_TOOL(ScaleFactorTool,    "ScaleFactorTool");

}

FiducialCutflow::~FiducialCutflow() {

}

void FiducialCutflow::BeginCycleImp() throw( SError ) {  
  

  return;

}

void FiducialCutflow::EndCycleImp() throw( SError ) {

   return;

}

void FiducialCutflow::BeginInputDataImp( const SInputData& ) throw( SError ) {


  //Declare output variables:  

  DeclareVariable( event_type_truth, "event_type_truth");
  DeclareVariable( quad_type, "quad_type");
  DeclareVariable( mispaired, "mispaired");
  DeclareVariable( swapped, "swapped");
  DeclareVariable( paired_leptons_are_from_higgs, "paired_leptons_are_from_higgs");

  DeclareVariable( evt_weight, "evt_weight");
  DeclareVariable( mc_event_weight, "mc_event_weight");
  DeclareVariable( pileup_sf,  "pileup_sf");
  DeclareVariable( vertex_sf,  "vertex_sf");
  //DeclareVariable( qcd_scale_weights,   "qcd_scale_weights");
  //DeclareVariable( pdf_weights,   "pdf_weights");
  DeclareVariable( weight_brcorrection,  "weight_brcorrection");
  DeclareVariable( weight_higgspt, "weight_higgspt");

  DeclareVariable( higgs_m, "higgs_m");
  DeclareVariable( higgs_pt, "higgs_pt");
  DeclareVariable( higgs_eta, "higgs_eta");
  DeclareVariable( higgs_rapidity, "higgs_rapidity");

  DeclareVariable( higgs_cthstr, "higgs_cthstr");
  //DeclareVariable( higgs_phi1,   "higgs_phi1"); //not implemented for now
  //DeclareVariable( higgs_cth1,   "higgs_cth1");
  //DeclareVariable( higgs_cth2,   "higgs_cth2");
  //DeclareVariable( higgs_phi,    "higgs_phi");

  DeclareVariable( Z1_m, "Z1_m");
  DeclareVariable( Z1_pt, "Z1_pt");
  DeclareVariable( Z1_eta, "Z1_eta");

  DeclareVariable( Z2_m, "Z2_m");
  DeclareVariable( Z2_pt, "Z2_pt");
  DeclareVariable( Z2_eta, "Z2_eta");
  
  DeclareVariable( born_higgslep4_m, "born_higgslep4_m");
  DeclareVariable( born_higgslep4_pt, "born_higgslep4_pt");
  DeclareVariable( born_higgslep4_eta, "born_higgslep4_eta");
  DeclareVariable( born_higgslep4_y, "born_higgslep4_y");
  
  DeclareVariable( born_higgslep12_m, "born_higgslep12_m");
  DeclareVariable( born_higgslep12_pt, "born_higgslep12_pt");
  DeclareVariable( born_higgslep12_eta, "born_higgslep12_eta");
  
  DeclareVariable( born_higgslep34_m, "born_higgslep34_m");
  DeclareVariable( born_higgslep34_pt, "born_higgslep34_pt");
  DeclareVariable( born_higgslep34_eta, "born_higgslep34_eta");

  DeclareVariable( born_higgslep4_cthstr, "born_higgslep4_cthstr");
  DeclareVariable( born_higgslep4_phi1,   "born_higgslep4_phi1");
  DeclareVariable( born_higgslep4_cth1,   "born_higgslep4_cth1");
  DeclareVariable( born_higgslep4_cth2,   "born_higgslep4_cth2");
  DeclareVariable( born_higgslep4_phi,	  "born_higgslep4_phi");

  DeclareVariable( born_paired_higgslep4_m, "born_paired_higgslep4_m");
  DeclareVariable( born_paired_higgslep4_pt, "born_paired_higgslep4_pt");
  DeclareVariable( born_paired_higgslep4_eta, "born_paired_higgslep4_eta");
  DeclareVariable( born_paired_higgslep4_y, "born_paired_higgslep4_y");
  
  DeclareVariable( born_paired_higgslep12_m, "born_paired_higgslep12_m");
  DeclareVariable( born_paired_higgslep12_pt, "born_paired_higgslep12_pt");
  DeclareVariable( born_paired_higgslep12_eta, "born_paired_higgslep12_eta");
  
  DeclareVariable( born_paired_higgslep34_m, "born_paired_higgslep34_m");
  DeclareVariable( born_paired_higgslep34_pt, "born_paired_higgslep34_pt");
  DeclareVariable( born_paired_higgslep34_eta, "born_paired_higgslep34_eta");

  DeclareVariable( born_paired_higgslep4_cthstr, "born_paired_higgslep4_cthstr");
  DeclareVariable( born_paired_higgslep4_phi1,   "born_paired_higgslep4_phi1");
  DeclareVariable( born_paired_higgslep4_cth1,   "born_paired_higgslep4_cth1");
  DeclareVariable( born_paired_higgslep4_cth2,   "born_paired_higgslep4_cth2");
  DeclareVariable( born_paired_higgslep4_phi,	  "born_paired_higgslep4_phi");

  DeclareVariable( lep4_m, "lep4_m");
  DeclareVariable( lep4_pt, "lep4_pt");
  DeclareVariable( lep4_eta, "lep4_eta");
  DeclareVariable( lep4_y, "lep4_y");

  DeclareVariable( lep4_cthstr, "lep4_cthstr");
  DeclareVariable( lep4_phi1,   "lep4_phi1");
  DeclareVariable( lep4_cth1,   "lep4_cth1");
  DeclareVariable( lep4_cth2,   "lep4_cth2");
  DeclareVariable( lep4_phi,    "lep4_phi");

  DeclareVariable( lep12_m, "lep12_m");
  DeclareVariable( lep12_pt, "lep12_pt");
  DeclareVariable( lep12_eta, "lep12_eta");

  DeclareVariable( lep34_m, "lep34_m");
  DeclareVariable( lep34_pt, "lep34_pt");
  DeclareVariable( lep34_eta, "lep34_eta");
  
  DeclareVariable( dressed_lep4_m, "dressed_lep4_m");
  DeclareVariable( dressed_lep4_pt, "dressed_lep4_pt");
  DeclareVariable( dressed_lep4_eta, "dressed_lep4_eta");
  DeclareVariable( dressed_lep4_y, "dressed_lep4_y");

  DeclareVariable( dressed_lep4_cthstr, "dressed_lep4_cthstr");
  DeclareVariable( dressed_lep4_phi1,   "dressed_lep4_phi1");
  DeclareVariable( dressed_lep4_cth1,   "dressed_lep4_cth1");
  DeclareVariable( dressed_lep4_cth2,   "dressed_lep4_cth2");
  DeclareVariable( dressed_lep4_phi,    "dressed_lep4_phi");

  DeclareVariable( dressed_lep12_m, "dressed_lep12_m");
  DeclareVariable( dressed_lep12_pt, "dressed_lep12_pt");
  DeclareVariable( dressed_lep12_eta, "dressed_lep12_eta");

  DeclareVariable( dressed_lep34_m, "dressed_lep34_m");
  DeclareVariable( dressed_lep34_pt, "dressed_lep34_pt");
  DeclareVariable( dressed_lep34_eta, "dressed_lep34_eta");

  DeclareVariable( born_lep4_m, "born_lep4_m");
  DeclareVariable( born_lep4_pt, "born_lep4_pt");
  DeclareVariable( born_lep4_eta, "born_lep4_eta");
  DeclareVariable( born_lep4_y, "born_lep4_y");

  DeclareVariable( born_lep4_cthstr, "born_lep4_cthstr");
  DeclareVariable( born_lep4_phi1,   "born_lep4_phi1");
  DeclareVariable( born_lep4_cth1,   "born_lep4_cth1");
  DeclareVariable( born_lep4_cth2,   "born_lep4_cth2");
  DeclareVariable( born_lep4_phi,    "born_lep4_phi");

  DeclareVariable( born_lep12_m, "born_lep12_m");
  DeclareVariable( born_lep12_pt, "born_lep12_pt");
  DeclareVariable( born_lep12_eta, "born_lep12_eta");

  DeclareVariable( born_lep34_m, "born_lep34_m");
  DeclareVariable( born_lep34_pt, "born_lep34_pt");
  DeclareVariable( born_lep34_eta, "born_lep34_eta");
  
  DeclareVariable( n_jets_truth,      "n_jets_truth");
  DeclareVariable( n_jets_truth_fid,  "n_jets_truth_fid");
  DeclareVariable( n_jets_truth_rew,  "n_jets_truth_rew");
  DeclareVariable( pt_leadingjet,     "pt_leadingjet");
  DeclareVariable( pt_leadingjet_fid, "pt_leadingjet_fid");

  DeclareVariable( n_jets_removed,      "n_jets_removed");

  DeclareVariable( born_higgslep_pt,  "born_higgslep_pt");
  DeclareVariable( born_higgslep_eta, "born_higgslep_eta");

  DeclareVariable( lep_pt,  "lep_pt");
  DeclareVariable( lep_eta, "lep_eta");

  DeclareVariable( dressed_lep_pt, "dressed_lep_pt");
  DeclareVariable( dressed_lep_eta, "dressed_lep_eta");

  DeclareVariable( born_lep_pt, "born_lep_pt");
  DeclareVariable( born_lep_eta, "born_lep_eta");

  DeclareVariable( lep_mother_pdgid,  "lep_mother_pdgid");

  DeclareVariable( n_electrons, "n_electrons");
  DeclareVariable( n_muons,     "n_muons");

  Book("NEvents", "Number of Events", 2, 0., 2.,"");
  Book("EventType", "Event Type", 5, -0.5, 4.5,"");

  gen_tree = new TTree("gen_tree", "gen_tree");
  gen_tree->SetDirectory(0);
  gen_tree->Branch("event", &event, "event/I");
  gen_tree->Branch("run", &run, "run/I");
  gen_tree->Branch("mc_channel_number", &mc_channel_number, "mc_channel_number/I");

  gen_tree->Branch("event_type_truth", &event_type_truth, "event_type_truth/I");
  gen_tree->Branch("evt_weight", &evt_weight, "evt_weight/D");
  gen_tree->Branch("mc_event_weight", &mc_event_weight, "mc_event_weight/D");
  //gen_tree->Branch("qcd_scale_weights", "std::vector<double>", &qcd_scale_weights);
  //gen_tree->Branch("pdf_weights", "std::vector<double>", &pdf_weights);
  gen_tree->Branch("weight_brcorrection", &weight_brcorrection, "weight_brcorrection/D");
  gen_tree->Branch("weight_higgspt", &weight_higgspt, "weight_higgspt/D");

  gen_tree->Branch("n_muons",       &n_muons,       "n_muons/I");
  gen_tree->Branch("n_electrons",   &n_electrons,   "n_electrons/I");

  gen_tree->Branch("higgs_m",   &higgs_m,   "higgs_m/D");
  gen_tree->Branch("higgs_pt",  &higgs_pt,  "higgs_pt/D");
  gen_tree->Branch("higgs_eta", &higgs_eta, "higgs_eta/D");
  gen_tree->Branch("higgs_rapidity", &higgs_rapidity, "higgs_rapidity/D");
  gen_tree->Branch("higgs_cthstr", &higgs_cthstr, "higgs_cthstr/F");

  gen_tree->Branch("Z1_m",   &Z1_m,   "Z1_m/D");
  gen_tree->Branch("Z1_pt",  &Z1_pt,  "Z1_pt/D");
  gen_tree->Branch("Z1_eta", &Z1_eta, "Z1_eta/D");

  gen_tree->Branch("Z2_m",   &Z2_m,   "Z2_m/D");
  gen_tree->Branch("Z2_pt",  &Z2_pt,  "Z2_pt/D");
  gen_tree->Branch("Z2_eta", &Z2_eta, "Z2_eta/D");

  gen_tree->Branch("born_higgslep4_m", &born_higgslep4_m ,"born_higgslep4_m/D");
  gen_tree->Branch("born_higgslep4_pt", &born_higgslep4_pt ,"born_higgslep4_pt/D");
  gen_tree->Branch("born_higgslep4_eta", &born_higgslep4_eta ,"born_higgslep4_eta/D");
  gen_tree->Branch("born_higgslep4_y", &born_higgslep4_y ,"born_higgslep4_y/D");
  
  gen_tree->Branch("born_higgslep12_m", &born_higgslep12_m ,"born_higgslep12_m/D");
  gen_tree->Branch("born_higgslep12_pt", &born_higgslep12_pt ,"born_higgslep12_pt/D");
  gen_tree->Branch("born_higgslep12_eta", &born_higgslep12_eta ,"born_higgslep12_eta/D");
  
  gen_tree->Branch("born_higgslep34_m", &born_higgslep34_m ,"born_higgslep34_m/D");
  gen_tree->Branch("born_higgslep34_pt", &born_higgslep34_pt ,"born_higgslep34_pt/D");
  gen_tree->Branch("born_higgslep34_eta", &born_higgslep34_eta ,"born_higgslep34_eta/D");

  gen_tree->Branch("born_higgslep4_cthstr", &born_higgslep4_cthstr ,"born_higgslep4_cthstr/F");
  gen_tree->Branch("born_higgslep4_phi1", &born_higgslep4_phi1   ,"born_higgslep4_phi1/F");
  gen_tree->Branch("born_higgslep4_cth1", &born_higgslep4_cth1   ,"born_higgslep4_cth1/F");
  gen_tree->Branch("born_higgslep4_cth2", &born_higgslep4_cth2   ,"born_higgslep4_cth2/F");
  gen_tree->Branch("born_higgslep4_phi", &born_higgslep4_phi	  ,"born_higgslep4_phi/F");

  gen_tree->Branch("born_paired_higgslep4_m", &born_paired_higgslep4_m ,"born_paired_higgslep4_m/D");
  gen_tree->Branch("born_paired_higgslep4_pt", &born_paired_higgslep4_pt ,"born_paired_higgslep4_pt/D");
  gen_tree->Branch("born_paired_higgslep4_eta", &born_paired_higgslep4_eta ,"born_paired_higgslep4_eta/D");
  gen_tree->Branch("born_paired_higgslep4_y", &born_paired_higgslep4_y ,"born_paired_higgslep4_y/D");
  
  gen_tree->Branch("born_paired_higgslep12_m", &born_paired_higgslep12_m ,"born_paired_higgslep12_m/D");
  gen_tree->Branch("born_paired_higgslep12_pt", &born_paired_higgslep12_pt ,"born_paired_higgslep12_pt/D");
  gen_tree->Branch("born_paired_higgslep12_eta", &born_paired_higgslep12_eta ,"born_paired_higgslep12_eta/D");
  
  gen_tree->Branch("born_paired_higgslep34_m", &born_paired_higgslep34_m ,"born_paired_higgslep34_m/D");
  gen_tree->Branch("born_paired_higgslep34_pt", &born_paired_higgslep34_pt ,"born_paired_higgslep34_pt/D");
  gen_tree->Branch("born_paired_higgslep34_eta", &born_paired_higgslep34_eta ,"born_paired_higgslep34_eta/D");

  gen_tree->Branch("born_paired_higgslep4_cthstr", &born_paired_higgslep4_cthstr ,"born_paired_higgslep4_cthstr/F");
  gen_tree->Branch("born_paired_higgslep4_phi1", &born_paired_higgslep4_phi1   ,"born_paired_higgslep4_phi1/F");
  gen_tree->Branch("born_paired_higgslep4_cth1", &born_paired_higgslep4_cth1   ,"born_paired_higgslep4_cth1/F");
  gen_tree->Branch("born_paired_higgslep4_cth2", &born_paired_higgslep4_cth2   ,"born_paired_higgslep4_cth2/F");
  gen_tree->Branch("born_paired_higgslep4_phi", &born_paired_higgslep4_phi	  ,"born_paired_higgslep4_phi/F");

  gen_tree->Branch("n_jets_truth_fid", &n_jets_truth_fid, "n_jets_truth_fid/I");
  gen_tree->Branch("pt_leadingjet_fid", &pt_leadingjet_fid, "pt_leadingjet_fid/D");

  gen_tree->Branch("n_jets_truth_rew", &n_jets_truth_rew, "n_jets_truth_rew/I");

  // -----------------------------------------------------------------
  // ---------------- D3PD Reader constuctors ------------------------
  
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
   
  // -------------------------------------------------------------
  // ---------------- Activating branches ------------------------

  // control what is read out by setting those branches Active
  // - all branches are Not Active by default
  m_event_d3pdobject->SetActive(kTRUE,"mc_channel_number|RunNumber|EventNumber|lbn|actualIntPerXing|averageIntPerXing");
  //m_event_d3pdobject->SetActive(kTRUE,c_output_event_branches_regex);
  m_trigger_d3pdobject->SetActive(kTRUE,c_output_trigger_branches_regex);
  m_vxp_d3pdobject->SetActive(kTRUE,c_output_vxp_branches_regex);

  m_electron_d3pdobject->SetActive(kTRUE,c_output_electron_branches_regex);
  m_muon_staco_d3pdobject->SetActive(kTRUE,c_output_muon_branches_regex);
  m_muon_calo_d3pdobject->SetActive(kTRUE,c_output_muon_branches_regex);

  m_truth_d3pdobject->SetActive(kTRUE,c_output_truth_branches_regex);

  // ----------------------------------------------------------
  // ---------------- Enabling writing ------------------------

  // enable writing (only affects already Active branches!)
  m_event_d3pdobject->WriteTo( GetOutputTree(c_output_tree_name.c_str()) );

  return;

}

void FiducialCutflow::EndInputDataImp( const SInputData& ) throw( SError ) {

   // inputs/outputs
    delete m_event_d3pdobject;
    delete m_trigger_d3pdobject;
    delete m_vxp_d3pdobject;

    delete m_electron_d3pdobject;
    delete m_muon_staco_d3pdobject;
    delete m_muon_calo_d3pdobject;
    delete m_jet_d3pdobject;

    delete m_truth_d3pdobject;
    delete m_mcevt_d3pdobject;

   return;

}

void FiducialCutflow::BeginInputFileImp( const SInputData& ) throw( SError ) {

    m_logger << DEBUG  << "BeginInputFileImp " << SLogger::endmsg;

    m_event_d3pdobject->ReadFrom( GetInputTree(m_TreeName.c_str()) );
    m_trigger_d3pdobject->ReadFrom( GetInputTree(m_TreeName.c_str()) );
    m_vxp_d3pdobject->ReadFrom( GetInputTree(m_TreeName.c_str()) );

    m_electron_d3pdobject->ReadFrom( GetInputTree(m_TreeName.c_str()) );
    m_muon_staco_d3pdobject->ReadFrom( GetInputTree(m_TreeName.c_str()) );
    m_muon_calo_d3pdobject->ReadFrom( GetInputTree(m_TreeName.c_str()) );
    m_jet_d3pdobject->ReadFrom( GetInputTree(m_TreeName.c_str()) );

    m_truth_d3pdobject->ReadFrom( GetInputTree(m_TreeName.c_str()) );
    m_mcevt_d3pdobject->ReadFrom( GetInputTree(m_TreeName.c_str()) );

   return;

}

void FiducialCutflow::BeginMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void FiducialCutflow::EndMasterInputDataImp( const SInputData& data) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"                  H -> ZZ Fiducial Event Types"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"4mu Events.............:"<<n_4mu  <<SLogger::endmsg;
  m_logger << ALWAYS <<"4e Events..............:"<<n_4e  <<SLogger::endmsg;
  m_logger << ALWAYS <<"2mu2e Events...........:"<<n_2mu2e  <<SLogger::endmsg;
  m_logger << ALWAYS <<"2e2mu Events...........:"<<n_2e2mu  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Tau Events.............:"<<n_taus  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Other Events...........:"<<n_other  <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"                  H -> ZZ Fiducial Cut Flow"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Cut........................:"<<"Number of events passed"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Events Before Cuts...........:"<<*cf_preselect  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Higgs...........:"<<*cf_higgs  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Zs..............:"<<*cf_zs  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Leptons.........:"<<*cf_leptons  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Pt..............:"<<*cf_pt  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Eta.............:"<<*cf_eta  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After M12.............:"<<*cf_m12  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After M34.............:"<<*cf_m34  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After DeltaR..........:"<<*cf_deltar  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After J/Psi...........:"<<*cf_jpsi  <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  //m_logger << ALWAYS <<"                  H -> ZZ Fiducial Efficiency"<<SLogger::endmsg;
  //m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  //m_logger << ALWAYS <<"4mu.............:"<<n_pass_4mu  <<"/"<<n_4mu  <<" = "<<n_pass_4mu/n_4mu  <<SLogger::endmsg;
  //m_logger << ALWAYS <<"4e..............:"<<n_pass_4e   <<"/"<<n_4e   <<" = "<<n_pass_4e/n_4e  <<SLogger::endmsg;
  //m_logger << ALWAYS <<"2mu2e...........:"<<n_pass_2mu2e<<"/"<<n_2mu2e<<" = "<<n_pass_2mu2e/n_2mu2e  <<SLogger::endmsg;
  //m_logger << ALWAYS <<"2e2mu...........:"<<n_pass_2e2mu<<"/"<<n_2e2mu<<" = "<<n_pass_2e2mu/n_2e2mu  <<SLogger::endmsg;
  //m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;


  PrintCutFlow(data);

  WriteObj(*gen_tree);

  return;

}

void FiducialCutflow::ExecuteEventImp( const SInputData&, Double_t ) throw( SError ) {

  if (debug_event != -1 && m_event_d3pdobject->EventNumber() != debug_event ) throw SError( SError::SkipEvent );

  //clean up
  for (unsigned int i = 0; i <truth_parts.size(); i++) delete truth_parts[i];
  truth_parts.clear();

  //save event info
  event = m_event_d3pdobject->EventNumber();
  run   = m_event_d3pdobject->RunNumber();
  mc_channel_number = m_event_d3pdobject->mc_channel_number();

  //only do this once
  if(cf_preselect == 0) {
     Set_MC_channel_number(mc_channel_number);
     
     //initialize BR correciton tool
     br_tool = new BRCorrection(mc_channel_number,true);

     m_logger << DEBUG << "Initializing Higgs Pt Reweighting SF for Powheg" << SLogger::endmsg;
     TFile *f = TFile::Open((sframe_dir()+"/config/other/Higgs_pT_Njets_reweighing_April2014.root").c_str());
     m_ggF_HpT_weight_01jets   = (TH1F*)f->Get("Reweigh_Powheg_To_HRes2Dynamic_01jets");
     m_ggF_HpT_weight_geq2jets = (TH1F*)f->Get("Reweigh_Powheg_To_HRes2Dynamic_geq2jets");
  }

  //initialize event weights
  evt_weight = 1.0;  
  pileup_sf = 1.0;
  vertex_sf = 1.0;
  mc_event_weight = 1.0;  
  qcd_scale_weights.clear();
  pdf_weights.clear();
  weight_brcorrection = 1.0;
  weight_higgspt = 1.0;
  
  //build some collections    
  ParticleElementBuilder::build( truth_parts, (*m_truth_d3pdobject) );
  DressLeptons(truth_parts);

  m_logger << DEBUG  << "Number of Truth Particles: "<< truth_parts.size() << SLogger::endmsg;
 
  std::vector<Jet> all_jets;
  ParticleElementBuilder::build( all_jets, (*m_jet_d3pdobject) );

  m_logger << DEBUG  << "Number of Truth Jets: "<< all_jets.size() << SLogger::endmsg;
  

  //fill truth level variables before any fiducial selection
  //includes weight_higgs_pt
  if(m_MCGenerator == "POWHEG")        FillHiggsVariables_Powheg(truth_parts, all_jets);
  else if(m_MCGenerator == "PROPHECY") FillHiggsVariables_Prophecy4f(truth_parts, all_jets);
  else if(m_MCGenerator == "JHU")      FillHiggsVariables_JHU(truth_parts, all_jets);

  Hist("EventType")->Fill( event_type_truth, 1. );

  //calculate event weight
  GET_TOOL(sf_tool, ScaleFactorTool, "ScaleFactorTool");

  m_logger << DEBUG << "Pileup SF " << SLogger::endmsg;
  pileup_sf  = sf_tool->PileupSF(m_event_d3pdobject);

  m_logger << DEBUG << "Vertex SF " << SLogger::endmsg;
  vertex_sf  = sf_tool->VertexSF( m_truth_d3pdobject[0].vx_z()->at(2) );    

  m_logger << DEBUG << "mcevt_weight SF " << SLogger::endmsg;
  if( m_mcevt_d3pdobject->mcevt_weight.IsAvailable() ) {  
     mc_event_weight = m_mcevt_d3pdobject->mcevt_weight()->at(0).at(0);    
  }

  m_logger << DEBUG << "qcd scale weights " << SLogger::endmsg;
  sf_tool->QCDWeights(qcd_scale_weights, m_mcevt_d3pdobject, m_truth_d3pdobject );

  m_logger << DEBUG << "pdf weights " << SLogger::endmsg;
  sf_tool->PDFWeights(pdf_weights, m_mcevt_d3pdobject, m_truth_d3pdobject );

  m_logger << ::DEBUG << "BR Correction " << SLogger::endmsg;
  weight_brcorrection = br_tool->getBRcorrection(m_truth_d3pdobject->pdgId(), 
                                                 m_truth_d3pdobject->status(), 
                                                 m_truth_d3pdobject->child_index(),
                                                 m_truth_d3pdobject->parent_index());
  
  evt_weight = pileup_sf*vertex_sf*mc_event_weight*weight_higgspt;

  Hist("NEvents")->Fill( 0., 1. );
  Hist("NEvents")->Fill( 1., evt_weight );

  CutFlow("Preselect", true, false, evt_weight);
  ++cf_preselect;  
     
  //calculate jet variables
  vector<TruthParticle*> final_state_leptons;
  GetFinalStateLeptons(truth_parts, final_state_leptons);

  m_logger << DEBUG << "Number of jets in event: " << all_jets.size() << SLogger::endmsg;

  n_jets_truth = 0;
  n_jets_truth_fid = 0;
  pt_leadingjet = 0;
  pt_leadingjet_fid = 0;  

  n_jets_removed = 0;

  for(std::vector<Jet>::iterator itr = all_jets.begin(); itr != all_jets.end(); ++itr) {     
    
    bool pass_kin = false;
    bool pass_kin_fid = false;
      
    m_logger << DEBUG << "Jet pT: "<<(*itr).pt() << " eta: " << (*itr).eta() << " phi: " << (*itr).phi()<< SLogger::endmsg;

    if( fabs((*itr).eta()) < 2.4 && (*itr).pt() > 25000) pass_kin = true; 
    if( fabs((*itr).eta()) < 4.5 && fabs((*itr).eta()) > 2.4 && (*itr).pt() > 30000) pass_kin = true;     
    
    if( fabs((*itr).Rapidity()) < 4.4 && (*itr).pt() > 30000) pass_kin_fid = true;
    
    if (!pass_kin && !pass_kin_fid) continue;
    
    //remove overlap with electrons
    bool pass_deltaR = true;
    
    for (unsigned int i = 0; i < final_state_leptons.size(); i++){
       if (! (final_state_leptons[i]->pdgId() == PDG::e_minus  || final_state_leptons[i]->pdgId() == PDG::e_plus)) continue;      
       
       if ( (*itr).TLV().DeltaR( final_state_leptons[i]->Dressed_TLV() ) < 0.2) {
         pass_deltaR = false;
	 
	 if (final_state_leptons[i]->GetMother().pdgId() != PDG::Z0) n_jets_removed++;
	 
         break;
       }
    }

    if (!pass_deltaR) continue;

    if (pass_kin){
      n_jets_truth++;
      if ((*itr).pt() > pt_leadingjet) pt_leadingjet = (*itr).pt();
    }    
    
    if (pass_kin_fid){
      n_jets_truth_fid++;
      if ((*itr).pt() > pt_leadingjet_fid) pt_leadingjet_fid = (*itr).pt();
    }
  }

  m_logger << DEBUG << "Number of selected fiducial jets in event: " << n_jets_truth_fid << SLogger::endmsg;
    
  //now begin fiducial selection
  
  vector<TruthParticle*> truth_leptons;
  if(m_MCGenerator == "POWHEG")        GetBornLeptons_Powheg(truth_parts, truth_leptons);
  else if(m_MCGenerator == "PROPHECY") GetBornLeptons_Prophecy4f(truth_parts, truth_leptons);
  else if(m_MCGenerator == "JHU")      GetBornLeptons_JHU(truth_parts, truth_leptons);    

  n_electrons = 0;
  unsigned int n_electrons_pos = 0;
  unsigned int n_electrons_neg = 0;
  n_muons = 0;
  unsigned int n_muons_pos = 0;
  unsigned int n_muons_neg = 0;
  
  for (unsigned int i = 0; i < truth_leptons.size(); i++) {
     if ( abs(truth_leptons[i]->pdgId()) == abs(PDG::e_minus) ) {             
       n_electrons++;
       truth_leptons[i]->charge() == +1 ? n_electrons_pos++ : n_electrons_neg++; 
     }		
     	 
     if ( abs(truth_leptons[i]->pdgId()) == abs(PDG::mu_minus) ) {
       n_muons++;
       truth_leptons[i]->charge() == +1 ? n_muons_pos++ : n_muons_neg++; 
     }
  }
    
  //fill generator level tree before apply first real cuts (lepton pt/eta)
  gen_tree->Fill();

  m_logger << DEBUG << "Found "<< n_muons << " muons and "<< n_electrons <<" electrons." << SLogger::endmsg;        
  bool pass_leptons = (n_electrons >= 4) || (n_muons >= 4) || (n_electrons >= 2 && n_muons >= 2);

  CutFlow("Pt/Eta/Leptons", pass_leptons, true, evt_weight, channel_names[event_type_truth]);
  ++cf_leptons;

  bool pass_SFOS    = (n_electrons_pos >=2 && n_electrons_neg >=2) || (n_muons_pos >=2 && n_muons_neg >=2) || (n_muons_pos >=1 && n_muons_neg >=1 && n_electrons_pos >=1 && n_electrons_neg >=1);

  CutFlow("SFOS", pass_SFOS, true, evt_weight, channel_names[event_type_truth]);
  ++cf_sfos;        
  
  m_logger << DEBUG << "Passed SFOS cut" << SLogger::endmsg;        
    
  vector<TruthParticle*> paired_leptons;
  bool pass_pairing = PairLeptons(truth_leptons, paired_leptons, b_dress_electrons, b_dress_muons);  
  CutFlow("Pairing", true, pass_pairing, evt_weight, channel_names[event_type_truth]);                 

  //classify paired quad
  quad_type = ClassifyQuad(paired_leptons);
  if (quad_type == -1){  
      m_logger << WARNING << "Problem with event classification!" << SLogger::endmsg;            
      m_logger << WARNING << "l1: "<<paired_leptons[0]->pdgId() <<  " l3: "<<paired_leptons[2]->pdgId()<< SLogger::endmsg;                
  }
  
  m_logger << DEBUG << "Event classified as " << channel_names[quad_type]<< SLogger::endmsg;                
  //CutFlow("Quad Type", true, true, evt_weight, channel_names[event_type_truth]);
  
  vector<TLorentzVector> paired_leptons_tlvs;
  for (unsigned int i = 0; i < paired_leptons.size(); i++){
    if ((b_dress_electrons && abs(paired_leptons[i]->pdgId()) == PDG::e_minus) || (b_dress_muons && abs(paired_leptons[i]->pdgId()) == PDG::mu_minus)){
      paired_leptons_tlvs.push_back( paired_leptons[i]->Dressed_TLV() );
    } else {
      paired_leptons_tlvs.push_back( paired_leptons[i]->TLV() );
    }
  }
    
  TLorentzVector tlv_lep12 = paired_leptons_tlvs[0] + paired_leptons_tlvs[1];
  TLorentzVector tlv_lep34 = paired_leptons_tlvs[2] + paired_leptons_tlvs[3];
  TLorentzVector tlv_lep4 = tlv_lep12 + tlv_lep34;
  
  //lepton pt cut  
  bool pass_pt = true;

  //leading leptons pt cut
  std::vector<double> lepton_pt;
  for (unsigned int i = 0; i < paired_leptons.size(); i++){
    lepton_pt.push_back(paired_leptons_tlvs[i].Pt());
  }
  std::sort(lepton_pt.begin(), lepton_pt.end(), std::greater<double>());
  if (!(lepton_pt.at(0) > 20000 && lepton_pt.at(1) > 15000 && lepton_pt.at(2) > 10000)) {
    pass_pt = false;
  }
  if (!pass_pt) m_logger << DEBUG << "Failed pt cut" << SLogger::endmsg;  
  CutFlow("Pt", pass_pt, true, evt_weight, channel_names[event_type_truth]);
  ++cf_pt;
    
  //m12 cut
  double m12 = tlv_lep12.M();
  bool pass_m12 = ( m12 < 106000 && m12 > 50000);
  if (!pass_m12) m_logger << DEBUG << "Failed m12 cut:"<< m12 << SLogger::endmsg;  
  CutFlow("M12", pass_m12, true, evt_weight, channel_names[event_type_truth]);
  ++cf_m12;

  //m34 cut
  double m34 = tlv_lep34.M();
  double m4l = tlv_lep4.M();
  //double cut_m34 = interpolate(m4l);
  bool pass_m34 = ( m34 < 115000 && m34 > 12000);
  if (!pass_m34) m_logger << DEBUG << "Failed m34 cut! m34: "<< m34 << SLogger::endmsg;  
  CutFlow("M34", pass_m34, true, evt_weight, channel_names[event_type_truth]);
  ++cf_m34;
  
  
  //deltaR cut
  bool pass_deltaR = true;
  
  for (unsigned int i = 0; i < paired_leptons.size(); i++){
    for (unsigned int j = 0; j < paired_leptons.size(); j++){     
       if (i >= j) continue; 

       double deltar = paired_leptons_tlvs[i].DeltaR(paired_leptons_tlvs[j]);
       
       if ((abs(paired_leptons[i]->pdgId()) == abs(paired_leptons[j]->pdgId())) && (deltar < 0.1)) pass_deltaR = false;
       if ((abs(paired_leptons[i]->pdgId()) != abs(paired_leptons[j]->pdgId())) && (deltar < 0.2)) pass_deltaR = false;         
    }
  }
  if (!pass_deltaR) m_logger << DEBUG << "Failed DeltaR cut" << SLogger::endmsg;  
  CutFlow("DeltaR", pass_deltaR, true, evt_weight, channel_names[event_type_truth]);
  ++cf_deltar;
  
  //J/Psi cut
  bool pass_jpsi = true;
  
  for (unsigned int i = 0; i < paired_leptons.size(); i++){
    for (unsigned int j = 0; j < paired_leptons.size(); j++){     
       if (i >= j) continue; 
       
       if (paired_leptons[i]->pdgId() != -1*paired_leptons[j]->pdgId()) continue;
       
       double mass = (paired_leptons_tlvs[i]+paired_leptons_tlvs[j]).M();
              
       if (mass < 5000) pass_jpsi = false;
    }
  }
  if (!pass_jpsi) m_logger << DEBUG << "Failed J/Psi cut" << SLogger::endmsg;  
  CutFlow("J/Psi", pass_jpsi, true, evt_weight, channel_names[event_type_truth]);
  ++cf_jpsi;
    

  //******************************************
  //Save observables     
  //******************************************
    
    
  //check mispairing
  mispaired = false; 
  if (paired_leptons[0]->parent_index().size() != 0 && paired_leptons[1]->parent_index().size() != 0){
    if (paired_leptons[0]->parent_index()[0] != paired_leptons[1]->parent_index()[0]) mispaired = true;
  } else {
    m_logger << DEBUG << "Cannot find parents of paired leptons to check mispairing" << SLogger::endmsg;  
  }

  if (paired_leptons[2]->parent_index().size() != 0 && paired_leptons[3]->parent_index().size() != 0){
    if (paired_leptons[2]->parent_index()[0] != paired_leptons[3]->parent_index()[0]) mispaired = true;
  } else {
    m_logger << DEBUG << "Cannot find parents of paired leptons to check mispairing" << SLogger::endmsg;  
  }

  swapped = false; 
  paired_leptons_are_from_higgs = true;
  if (m_MCGenerator == "POWHEG"){

    TruthParticle* Z0 = GetTruthZ(0, truth_parts);
    TruthParticle* Z1 = GetTruthZ(1, truth_parts);
    
    if (!mispaired){
      if (paired_leptons[0]->parent_index().size() != 0){
	if (paired_leptons[0]->parent_index()[0] != int(Z0->GetIndex())) swapped = true;
      } else {
	m_logger << DEBUG << "Cannot find parents of leptons to check swapping" << SLogger::endmsg;  
      }

      if (paired_leptons[2]->parent_index().size() != 0){
	if (paired_leptons[2]->parent_index()[0] != int(Z1->GetIndex())) swapped = true;
      } else {
	m_logger << DEBUG << "Cannot find parents of leptons to check swapping" << SLogger::endmsg;  
      }
    }

    paired_leptons_are_from_higgs = true;
    for (unsigned int i = 0; i < paired_leptons.size(); i++){

      if (paired_leptons[i]->parent_index().size() == 0) {
	paired_leptons_are_from_higgs = false;
	break;
      }

      if ( paired_leptons[i]->parent_index()[0] != int(Z0->GetIndex()) && 
           paired_leptons[i]->parent_index()[0] != int(Z1->GetIndex()) ) {
	paired_leptons_are_from_higgs = false;
	break;
      }
    }
  }
  
  //bare lepton observables  
  tlv_lep4  = paired_leptons[0]->TLV() + paired_leptons[1]->TLV() + paired_leptons[2]->TLV() + paired_leptons[3]->TLV();
  tlv_lep12 = paired_leptons[0]->TLV() + paired_leptons[1]->TLV();
  tlv_lep34 = paired_leptons[2]->TLV() + paired_leptons[3]->TLV();

  lep4_m   = tlv_lep4.M();
  lep4_pt  = tlv_lep4.Pt();
  lep4_eta = tlv_lep4.Eta();
  lep4_y   = tlv_lep4.Rapidity();

  lep12_m   = tlv_lep12.M();
  lep12_pt  = tlv_lep12.Pt();
  lep12_eta = tlv_lep12.Eta();

  lep34_m   = tlv_lep34.M();
  lep34_pt  = tlv_lep34.Pt();
  lep34_eta = tlv_lep34.Eta();
  
  lep_pt.clear();
  lep_eta.clear();
  lep_mother_pdgid.clear();
  for (int i=0; i<4; i++){
    lep_pt.push_back(paired_leptons[i]->TLV().Pt());
    lep_eta.push_back(paired_leptons[i]->TLV().Eta());
    lep_mother_pdgid.push_back(paired_leptons[i]->GetMother().pdgId());    
  }
  
  GetElicityAngles( paired_leptons[1]->TLV(), paired_leptons[0]->TLV(), paired_leptons[3]->TLV(), paired_leptons[2]->TLV(), &lep4_cthstr, &lep4_phi1, &lep4_cth1, &lep4_cth2, &lep4_phi );

  //dressed lepton observables  
  TLorentzVector dressed_tlv_lep4  = paired_leptons[0]->Dressed_TLV() + paired_leptons[1]->Dressed_TLV() + paired_leptons[2]->Dressed_TLV() + paired_leptons[3]->Dressed_TLV();
  TLorentzVector dressed_tlv_lep12 = paired_leptons[0]->Dressed_TLV() + paired_leptons[1]->Dressed_TLV();
  TLorentzVector dressed_tlv_lep34 = paired_leptons[2]->Dressed_TLV() + paired_leptons[3]->Dressed_TLV();

  dressed_lep4_m   = dressed_tlv_lep4.M();
  dressed_lep4_pt  = dressed_tlv_lep4.Pt();
  dressed_lep4_eta = dressed_tlv_lep4.Eta();
  dressed_lep4_y   = dressed_tlv_lep4.Rapidity();

  dressed_lep12_m   = dressed_tlv_lep12.M();
  dressed_lep12_pt  = dressed_tlv_lep12.Pt();
  dressed_lep12_eta = dressed_tlv_lep12.Eta();

  dressed_lep34_m   = dressed_tlv_lep34.M();
  dressed_lep34_pt  = dressed_tlv_lep34.Pt();
  dressed_lep34_eta = dressed_tlv_lep34.Eta();

  dressed_lep_pt.clear();
  dressed_lep_eta.clear();
  for (int i=0; i<4; i++){
    dressed_lep_pt.push_back(paired_leptons[i]->Dressed_TLV().Pt());
    dressed_lep_eta.push_back(paired_leptons[i]->Dressed_TLV().Eta());
  }
  
  GetElicityAngles( paired_leptons[1]->Dressed_TLV(), paired_leptons[0]->Dressed_TLV(), paired_leptons[3]->Dressed_TLV(), paired_leptons[2]->Dressed_TLV(), &dressed_lep4_cthstr, &dressed_lep4_phi1, &dressed_lep4_cth1, &dressed_lep4_cth2, &dressed_lep4_phi );

  //born lepton observables
  //first, match paired leptons to born leptons
  std::vector<TruthParticle*> matched_born_leptons;
  for (int i=0; i < 4; i++){    

    double max_energy = 0;
    int matched_index = -1;
    
    //m_logger << INFO << "bare: " << paired_leptons[i]->pdgId() << SLogger::endmsg;     
    //m_logger << INFO << "bare mother: " << paired_leptons[i]->GetMother().pdgId() << SLogger::endmsg;     
     
    for (unsigned int j = 0; j < truth_parts.size(); j++) {
    
      if (paired_leptons[i]->pdgId() != truth_parts[j]->pdgId()) continue;
          
      if (paired_leptons[i]->TLV().DeltaR(truth_parts[j]->TLV()) > 0.1) continue;
      
      if (truth_parts[j]->TLV().E() > max_energy) {
         max_energy = truth_parts[j]->TLV().E();
         matched_index = j;
      }
    }  
  
    if (matched_index != -1) {
      m_logger << DEBUG << "Matched bare lepton to born lepton." << SLogger::endmsg;
      matched_born_leptons.push_back(truth_parts[matched_index]);
    } else {
      m_logger << WARNING << "Unable to match bare lepton to born lepton." << SLogger::endmsg;
    }  
  }
  
  born_lep_pt.clear();
  born_lep_eta.clear();
  
  if (matched_born_leptons.size() == 4){
    TLorentzVector TLV_born_lep4  = matched_born_leptons[0]->TLV() + matched_born_leptons[1]->TLV() + matched_born_leptons[2]->TLV() + matched_born_leptons[3]->TLV();
    TLorentzVector TLV_born_lep12 = matched_born_leptons[0]->TLV() + matched_born_leptons[1]->TLV();
    TLorentzVector TLV_born_lep34 = matched_born_leptons[2]->TLV() + matched_born_leptons[3]->TLV();
    
    born_lep4_m   = TLV_born_lep4.M();
    born_lep4_pt  = TLV_born_lep4.Pt();
    born_lep4_eta = TLV_born_lep4.Eta();
    born_lep4_y   = TLV_born_lep4.Rapidity();

    born_lep12_m   = TLV_born_lep12.M();
    born_lep12_pt  = TLV_born_lep12.Pt();
    born_lep12_eta = TLV_born_lep12.Eta();

    born_lep34_m   = TLV_born_lep34.M();
    born_lep34_pt  = TLV_born_lep34.Pt();
    born_lep34_eta = TLV_born_lep34.Eta();
 
    for (int i=0; i<4; i++){
      born_lep_pt.push_back(matched_born_leptons[i]->TLV().Pt());
      born_lep_eta.push_back(matched_born_leptons[i]->TLV().Eta());
    }
  
    GetElicityAngles( matched_born_leptons[1]->TLV(), matched_born_leptons[0]->TLV(), matched_born_leptons[3]->TLV(), matched_born_leptons[2]->TLV(), &born_lep4_cthstr, &born_lep4_phi1, &born_lep4_cth1, &born_lep4_cth2, &born_lep4_phi );
  }

  m_event_d3pdobject->ReadAllActive();

  if (quad_type == 0) n_pass_4mu++;  
  if (quad_type == 1) n_pass_4e++;
  if (quad_type == 2) n_pass_2mu2e++;
  if (quad_type == 3) n_pass_2e2mu++;
 
  return;

}

//___________________________________________________________________________________________________________________________
bool FiducialCutflow::PairLeptons(std::vector<TruthParticle*> &input_leptons, std::vector<TruthParticle*> &paired_leptons, bool dress_electrons, bool dress_muons) {

  int paired_index_l1 = -1;
  int paired_index_l2 = -1;
  int paired_index_l3 = -1;
  int paired_index_l4 = -1;
  
  //determine l1 and l2 first
  double smallest_mass_diff = -1;
  for (unsigned int i = 0; i < input_leptons.size(); i++){
    for (unsigned int j = 0; j < input_leptons.size(); j++){

      if (i>=j) continue;//don't pair a lepton with itself

      if (input_leptons[i]->pdgId() != -1*input_leptons[j]->pdgId()) continue; //only pair same flavor opposite sign leptons

      //don't allow mispairing
      if (!b_allow_mispairing && input_leptons[i]->GetMother() != input_leptons[j]->GetMother()) continue;         
      
      double mass_diff = 0;
      if ((dress_electrons && abs(input_leptons[i]->pdgId()) == PDG::e_minus) || (dress_muons && abs(input_leptons[i]->pdgId()) == PDG::mu_minus)){
         mass_diff = fabs((input_leptons[i]->Dressed_TLV()+input_leptons[j]->Dressed_TLV()).M() - M_Z);
      } else {
         mass_diff = fabs((input_leptons[i]->TLV()+input_leptons[j]->TLV()).M() - M_Z);
      }
      if (smallest_mass_diff == -1 || mass_diff < smallest_mass_diff){
	smallest_mass_diff = mass_diff;
	paired_index_l1 = input_leptons[i]->charge() == +1 ? i : j;
	paired_index_l2 = input_leptons[i]->charge() == +1 ? j : i;	
      }
    }
  }
  m_logger << DEBUG << "l1="<<input_leptons[paired_index_l1]->barcode() <<" l2="<<input_leptons[paired_index_l2]->barcode() << SLogger::endmsg;        
        
  //determine l3 and l4 second
  smallest_mass_diff = -1;
  for (unsigned int i = 0; i < input_leptons.size(); i++){
    if (int(i) == paired_index_l1 || int(i) == paired_index_l2) continue;
    for (unsigned int j = 0; j < input_leptons.size(); j++){
      if (i>=j) continue; 

      if (int(j) == paired_index_l1 || int(j) == paired_index_l2) continue;

      if (input_leptons[i]->pdgId() != -1*input_leptons[j]->pdgId()) continue; //only pair same flavor opposite sign leptons

      if (!b_allow_mispairing && input_leptons[i]->GetMother() != input_leptons[j]->GetMother()) continue;         
      
      double mass_diff = 0;
      if ((dress_electrons && abs(input_leptons[i]->pdgId()) == PDG::e_minus) || (dress_muons && abs(input_leptons[i]->pdgId()) == PDG::mu_minus)){
         mass_diff = fabs((input_leptons[i]->Dressed_TLV()+input_leptons[j]->Dressed_TLV()).M() - M_Z);
      } else {
         mass_diff = fabs((input_leptons[i]->TLV()+input_leptons[j]->TLV()).M() - M_Z);
      }
      if (smallest_mass_diff == -1 || mass_diff < smallest_mass_diff){
	smallest_mass_diff = mass_diff;
	paired_index_l3 = input_leptons[i]->charge() == +1 ? i : j;
	paired_index_l4 = input_leptons[i]->charge() == +1 ? j : i;		
      }      
    }
  } 
  m_logger << DEBUG << "l3="<<input_leptons[paired_index_l3]->barcode() <<" l4="<<input_leptons[paired_index_l4]->barcode() << SLogger::endmsg;        
  
  if (paired_index_l1 == -1 || paired_index_l2 == -1 || paired_index_l3 == -1 || paired_index_l4 == -1 ){
     m_logger << DEBUG << "Unable to pair leptons." << SLogger::endmsg;
     return false;
  } else {
    paired_leptons.push_back(input_leptons[paired_index_l1]);
    paired_leptons.push_back(input_leptons[paired_index_l2]);
    paired_leptons.push_back(input_leptons[paired_index_l3]);
    paired_leptons.push_back(input_leptons[paired_index_l4]);
  }
  return true;
}


//___________________________________________________________________________________________________________________________
double FiducialCutflow::interpolate(double mass)
{

  m_logger << DEBUG  << "FiducialCutflow::interpolate(): input mass: " << mass << SLogger::endmsg;
  
  unsigned int max = 2;
  
  double result = 0.;
  unsigned int i = 0;
  while(i < max){
    if(m34cut_m4l[i] >= mass) break;
    i++;
  }
  
  if (i==0) return m34cut_m34[0];
  if (i==max) return m34cut_m34[max-1];
  
  result = m34cut_m34[i-1] + (m34cut_m34[i] - m34cut_m34[i-1])/(m34cut_m4l[i] - m34cut_m4l[i-1])*(mass - m34cut_m4l[i-1]);
  return result;
}

//___________________________________________________________________________________________________________________________
int FiducialCutflow::findStableChildren(TruthParticle* mother, std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &stablechildren){

  int n_grand_children = 0;

  for (unsigned int i = 0; i < mother->child_index().size(); i++) {
      int index = mother->child_index()[i];
				              
      if (tparts[index]->status() == 1){
	 stablechildren.push_back(tparts[index]);
      } else {
         n_grand_children += findStableChildren(tparts[index], tparts, stablechildren);
      }
  }
  
  return mother->child_index().size() + n_grand_children;
}

//___________________________________________________________________________________________________________________________
int FiducialCutflow::findLastHiggs(int higgs_index, std::vector<TruthParticle*> &tparts){

  if ( tparts[higgs_index]->pdgId() != PDG::Higgs0){
    m_logger << WARNING  << "findLastHiggs(): Input particle is not a Higgs" << SLogger::endmsg;
  }  
  
  for (unsigned int i = 0; i < tparts[higgs_index]->child_index().size(); i++) {
      int index = tparts[higgs_index]->child_index()[i];
				              
      if (tparts[index]->pdgId() == PDG::Higgs0){
	 return findLastHiggs(index, tparts);
      }
  }
  
  return higgs_index;
}

//____________________________________________________________________________
void FiducialCutflow::DressLeptons( std::vector<TruthParticle*> &tparts ) {

  for (unsigned int i = 0; i < tparts.size(); i++) {
     
     //dress final state electrons
     if ( tparts[i]->status() == 1 && abs(tparts[i]->pdgId()) == PDG::e_minus ){        
      //find FSR photons
      for (unsigned int j = 0; j < tparts.size(); j++) {
          if ( tparts[j]->pdgId()  != PDG::gamma )		  continue;
          if ( tparts[j]->status() != 1 )			  continue;
          if ( tparts[j]->barcode() >= 200000 )			  continue;
          if ( tparts[j]->TLV().DeltaR(tparts[i]->TLV()) > 0.1 )	  continue;
          
	  /*
	  TruthParticle mother = tparts[j]->GetMother();
	  m_logger << WARNING << "DressLeptons: Photon's mother: " << mother.pdgId() <<  "  status " << mother.status() << SLogger::endmsg;          
	  m_logger << WARNING << "DressLeptons: Photon's mother's chlidren: " <<  SLogger::endmsg;
	  std::vector<int> children = mother.child_index();
	  for(unsigned c = 0; c != children.size(); ++c)
	    {
	     m_logger << WARNING << "pdg: " << tparts[children[c]].pdgId() << " status: "<< tparts[children[c]].status() <<  SLogger::endmsg;          
	     // children.push_back( TruthParticle( (*m_truth_d3pd_object)[child[i]], m_truth_d3pd_object ) );
	    }
	  //for (int c= 0; c < mother.children()
	    // m_logger << WARNING << mother.pdgId() <<  SLogger::endmsg;          

	  */
	  //mother req.
	  //if ( tparts[j]->GetMother().pdgId() != PDG::Z0) continue; 
	  //if ( tparts[j]->GetMother().pdgId() != PDG::Z0 && abs(tparts[j]->GetMother().pdgId()) != 15) continue; 
	  
          m_logger << DEBUG << "DressLeptons: Adding Photon to Electron..." << SLogger::endmsg;          
          tparts[i]->AddPhoton(tparts[j]->TLV());
          m_logger << DEBUG << "DressLeptons: Bare pT: " << tparts[i]->TLV().Pt() << " Dressed pT: "<< tparts[i]->Dressed_TLV().Pt() << SLogger::endmsg;          
       }
     }
     
     if ( tparts[i]->status() == 1 && abs(tparts[i]->pdgId()) == PDG::mu_minus ){        
      //find FSR photons
      for (unsigned int j = 0; j < tparts.size(); j++) {
          if ( tparts[j]->pdgId()  != PDG::gamma )		  continue;
          if ( tparts[j]->status() != 1 )			  continue;
          if ( tparts[j]->barcode() >= 200000 )			  continue;
          if ( tparts[j]->TLV().DeltaR(tparts[i]->TLV()) > 0.1 )	  continue;
          
	  /*
	  TruthParticle mother = tparts[j]->GetMother();
	  m_logger << WARNING << "DressLeptons: Photon's mother: " << mother.pdgId() <<  "  status " << mother.status() << SLogger::endmsg;          
	  m_logger << WARNING << "DressLeptons: Photon's mother's chlidren: " <<  SLogger::endmsg;
	  std::vector<int> children = mother.child_index();
	  for(unsigned c = 0; c != children.size(); ++c)
	    {
	     m_logger << WARNING << "pdg: " << tparts[children[c]].pdgId() << " status: "<< tparts[children[c]].status() <<  SLogger::endmsg;          
	     // children.push_back( TruthParticle( (*m_truth_d3pd_object)[child[i]], m_truth_d3pd_object ) );
	    }
	  //for (int c= 0; c < mother.children()
	    // m_logger << WARNING << mother.pdgId() <<  SLogger::endmsg;          

	  */
	  //mother req.
	  //if ( tparts[j]->GetMother().pdgId() != PDG::Z0) continue; 
	  //if ( tparts[j]->GetMother().pdgId() != PDG::Z0 && abs(tparts[j]->GetMother().pdgId()) != 15) continue; 
	  //if ( tparts[j]->GetMother() != tparts[i]->GetMother() ) continue;
	  
          m_logger << DEBUG << "DressLeptons: Adding Photon to Muon..." << SLogger::endmsg;          
          tparts[i]->AddPhoton(tparts[j]->TLV());
          m_logger << DEBUG << "DressLeptons: Bare pT: " << tparts[i]->TLV().Pt() << " Dressed pT: "<< tparts[i]->Dressed_TLV().Pt() << SLogger::endmsg;          
       }
     }	       
  }
  
  m_logger << DEBUG << "Finished dressing leptons" << SLogger::endmsg;          
   
  return;
}


//____________________________________________________________________________
void FiducialCutflow::GetFinalStateLeptons( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &leptons, bool dress_electrons, bool dress_muons) {
  
  for (unsigned int i = 0; i < tparts.size(); i++) {
     if ( tparts[i]->status() != 1 ) continue;  

     if ( tparts[i]->pdgId() == PDG::e_minus || tparts[i]->pdgId() == PDG::e_plus ) {             

       if ( (dress_electrons ? tparts[i]->Dressed_TLV().Pt() : tparts[i]->TLV().Pt()) < 7000) continue;  

       if ( (dress_electrons ? fabs(tparts[i]->Dressed_TLV().Eta()): fabs(tparts[i]->TLV().Eta())) > 2.47) continue;  

       m_logger << DEBUG << "Found final state electron - barcode: "<< tparts[i]->barcode() << " pt: "<<  tparts[i]->pt() << " eta: " << tparts[i]->eta() << " phi: "<< tparts[i]->phi()<< SLogger::endmsg;  
       leptons.push_back( tparts[i] );
     }		
     	 
     if ( tparts[i]->pdgId() == PDG::mu_minus || tparts[i]->pdgId() == PDG::mu_plus ) {

       if ( (dress_muons ? tparts[i]->Dressed_TLV().Pt() : tparts[i]->TLV().Pt()) < 6000 ) continue;  

       if ( (dress_muons ? fabs(tparts[i]->Dressed_TLV().Eta()) : fabs(tparts[i]->eta())) > 2.7) continue;  

       m_logger << DEBUG << "Found final state muon - barcode: "<< tparts[i]->barcode() << " pt: "<<  tparts[i]->pt() << " eta: " << tparts[i]->eta() << " phi: "<< tparts[i]->phi()<< SLogger::endmsg;  
       leptons.push_back( tparts[i] );
     }
  }
  
  return;  
}

//____________________________________________________________________________
void FiducialCutflow::GetBornLeptons_Powheg( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &leptons ) {
  
  std::vector<TruthParticle*> status1_leptons;
  std::vector<TruthParticle*> status3_leptons;

  for (unsigned int i = 0; i < tparts.size(); i++) {
          
     //flavor cut
     if ( ! (abs(tparts[i]->pdgId()) == abs(PDG::e_minus) || abs(tparts[i]->pdgId()) == abs(PDG::mu_minus))) continue;             
     
     //cut on mother
     if ( ! (tparts[i]->GetMother().pdgId() == PDG::Z0 || tparts[i]->GetMother().pdgId() == PDG::W_plus || tparts[i]->GetMother().pdgId() == PDG::W_minus) ) continue;
          
     if (tparts[i]->status() == 1) status1_leptons.push_back( tparts[i] );		
     if (tparts[i]->status() == 3) status3_leptons.push_back( tparts[i] );		
 }

  m_logger << DEBUG << "Found "<< status1_leptons.size() << " truth status 1 leptons." << SLogger::endmsg;  
  m_logger << DEBUG << "Found "<< status3_leptons.size() << " truth status 3 leptons." << SLogger::endmsg;  
  
  //remove overlap between status 1 and 3 by checking mother
  std::vector<TruthParticle*> born_leptons;
  for (unsigned int i = 0; i < status1_leptons.size(); i++) {
    bool overlap = false;
    for (unsigned int j = 0; j < status3_leptons.size(); j++) {
    
      if ( status1_leptons[i]->GetMother() == status3_leptons[j]->GetMother() ){
         overlap = true;
	 break; 
      }    
    }
    //add lepton as born lepton if no status 3 particles share the same mother
    if (!overlap) born_leptons.push_back(status1_leptons[i]);
  }
  //add status3 leptons by default  
  for (unsigned int i = 0; i < status3_leptons.size(); i++) born_leptons.push_back(status3_leptons[i]);
   
  //sanity check
  for (unsigned int i = 0; i < born_leptons.size(); i++) {     
    for (unsigned int j = 0; j < born_leptons.size(); j++) {     
      if (i>=j) continue;
      if(born_leptons[i]->barcode() == born_leptons[j]->barcode()){
         m_logger << WARNING << "Duplicate born leptons!" << SLogger::endmsg;          
      }
    }
  }
  
  m_logger << DEBUG << "Found "<< born_leptons.size() << " truth born leptons." << SLogger::endmsg;  
  
  //now apply cuts on remaining leptons
  for (unsigned int i = 0; i < born_leptons.size(); i++) {     
     if ( abs(born_leptons[i]->pdgId()) == abs(PDG::e_minus) ) {             

       if ( born_leptons[i]->TLV().Pt() < 7000) continue;  

       if ( fabs(born_leptons[i]->TLV().Eta()) > 2.47) continue;  

       m_logger << DEBUG << "Found born electron - barcode: "<< born_leptons[i]->barcode() << " pt: "<<  born_leptons[i]->pt() << " eta: " << born_leptons[i]->eta() << " phi: "<< born_leptons[i]->phi()<< SLogger::endmsg;  
       leptons.push_back(born_leptons[i]);
     }		
     	 
     if ( abs(born_leptons[i]->pdgId()) == abs(PDG::mu_minus) ) {

       if ( born_leptons[i]->TLV().Pt() < 6000 ) continue;  

       if ( fabs(born_leptons[i]->eta()) > 2.7) continue;  

       m_logger << DEBUG << "Found born muon - barcode: "<< born_leptons[i]->barcode() << " pt: "<<  born_leptons[i]->pt() << " eta: " << born_leptons[i]->eta() << " phi: "<< born_leptons[i]->phi()<< SLogger::endmsg;  
       leptons.push_back( born_leptons[i] );    
     }
  }  
   
  
  m_logger << DEBUG << "Selected "<< leptons.size() << " born leptons." << SLogger::endmsg;  
  
  return;  
}

//____________________________________________________________________________
void FiducialCutflow::GetBornLeptons_Prophecy4f( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &leptons ) {

  //to be completed
  return;
}
  
//____________________________________________________________________________
void FiducialCutflow::GetBornLeptons_JHU( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &leptons ) {

  //to be completed
  return;  
}


//____________________________________________________________________________
void FiducialCutflow::GetBornTruthQuad( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &quad ) {

  for (unsigned int i = 0; i < 4; i++){  
    TruthParticle* part = GetTruthLepton(i, tparts);
    if (part) quad.push_back( part );
  }
  
  return;
}


//____________________________________________________________________________
TruthParticle* FiducialCutflow::GetTruthZ( int index, std::vector<TruthParticle*> &tparts ){
      
  std::vector<TruthParticle*> truth_Zs;
  for (unsigned int i = 0; i < tparts.size(); i++) {
    if (!(tparts[i]->pdgId() == PDG::Z0)) continue;
    m_logger << DEBUG << "Found Z0 Truth Particle with status="<<tparts[i]->status() << SLogger::endmsg;  

    if (tparts[i]->status()!=22)    continue;
    	
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
TruthParticle* FiducialCutflow::GetTruthLepton( int index, std::vector<TruthParticle*> &tparts ){
  
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
int FiducialCutflow::ClassifyQuad( std::vector<TruthParticle*> &quad ){
  
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
  else if (l12 == l34) event_type = 4; //tau events (same flavor vs mixed flavor)
  else event_type = 5;  

  return event_type;
}


//____________________________________________________________________________
void FiducialCutflow::FillHiggsVariables_Powheg( std::vector<TruthParticle*> &truth_parts, std::vector<Jet> &all_jets){

  //first find Higgs
  vector<TruthParticle*> truth_higgses;
  int higgs_index = -1;
  for (unsigned int i = 0; i < truth_parts.size(); i++) {
     if (truth_parts[i]->pdgId() == PDG::Higgs0 ) {
	m_logger << DEBUG << "Found Higgs Truth Particle - status: "<< truth_parts[i]->status() << SLogger::endmsg;  
	truth_higgses.push_back( truth_parts[i] );
        if (truth_parts[i]->status() == 62 ) {
          higgs_index = i;
	}
     }
  }
  
  //recover higgs when status==62 particle not available
  if (higgs_index == -1){ 
    m_logger << DEBUG << "No status 62 Higgs found.  Finding last Higgs in chain" << SLogger::endmsg;  
    if (truth_higgses.size() != 0) {
      higgs_index = findLastHiggs(truth_higgses[0]->GetIndex(), truth_parts);      
    }                
  }
  
  //at this point, if higgs still not found, something is wrong. Give warning and skip event
  if (higgs_index == -1){ 
     m_logger << ERROR <<"Unable to find Truth Higgs." << SLogger::endmsg;
     return;      
  }

  ++cf_higgs;
  
  TruthParticle* truth_higgs = truth_parts[higgs_index];  
  higgs_m        = truth_higgs->m();
  higgs_pt       = truth_higgs->pt();
  higgs_eta      = truth_higgs->eta();
  higgs_rapidity = truth_higgs->TLV().Rapidity();
    
  //next find Z's
  vector<TruthParticle*> truth_Zs;
  TruthParticle* t = 0;
  
  t = GetTruthZ(0, truth_parts);
  if (t) truth_Zs.push_back(t);

  t = GetTruthZ(1, truth_parts);
  if (t) truth_Zs.push_back(t);
   
  if (truth_Zs.size() != 2) {
    m_logger << ERROR << "Found "<< truth_Zs.size() << " Z boson truth particles!" << SLogger::endmsg;  
    return;
  }
  ++cf_zs;

  Z1_m = truth_Zs[0]->m();
  Z1_pt = truth_Zs[0]->pt();
  Z1_eta = truth_Zs[0]->eta();

  Z2_m = truth_Zs[1]->m();
  Z2_pt = truth_Zs[1]->pt();
  Z2_eta = truth_Zs[1]->eta();
  
  //angle calculation  (adapted from HiggsZZ4lUtils/GetElicityAngles.h)
  TLorentzVector z1 = truth_Zs[0]->TLV();
  z1.Boost(-( truth_higgs->TLV().BoostVector() ) ); //boost to Higgs reference frame
  higgs_cthstr = z1.Vect().Unit().Z();  
  

  //get leptons from Higgs
  std::vector<TruthParticle*> born_higgs_leptons;
  GetBornTruthQuad(truth_parts, born_higgs_leptons);  

  //classify event
  event_type_truth = ClassifyQuad(born_higgs_leptons);

  if ( event_type_truth == -1) {
    m_logger << ERROR << "Unable to classify truth event!" << SLogger::endmsg; 
  }
  m_logger << DEBUG << "event_type_truth=="<<event_type_truth << SLogger::endmsg; 
 
  m_logger << ::DEBUG << "Higgs pT reweight" << SLogger::endmsg;
  n_jets_truth_rew = 0;
  if (mc_channel_number == 160155 ||
      mc_channel_number == 167220 ||
      mc_channel_number == 167222 ||
      mc_channel_number == 160155 ||
      mc_channel_number == 167225 ||
      mc_channel_number == 167227 ||
      mc_channel_number == 160156    ){

     for(std::vector<Jet>::iterator itr = all_jets.begin(); itr != all_jets.end(); ++itr) {

       if((*itr).pt() < 25000) continue; 

       bool overlap = false;

       for (unsigned int i = 0; i<born_higgs_leptons.size(); i++){
	 if (abs(born_higgs_leptons[i]->pdgId()) == PDG::mu_minus) continue;
	 
	 if (born_higgs_leptons[i]->TLV().DeltaR((*itr).TLV()) < 0.4){
            overlap = true;
	    break; 
	 }
       }

       if (overlap) continue;

       n_jets_truth_rew++;     
     }
     
     weight_higgspt = n_jets_truth_rew < 2 ?
	      m_ggF_HpT_weight_01jets->Interpolate(higgs_pt/1000):
	      m_ggF_HpT_weight_geq2jets->Interpolate(higgs_pt/1000);
  }  

  //save higgs-associated born lepton kinematics      
  TLorentzVector tlv_born_higgslep12 = born_higgs_leptons[0]->TLV()+born_higgs_leptons[1]->TLV();
  TLorentzVector tlv_born_higgslep34 = born_higgs_leptons[2]->TLV()+born_higgs_leptons[3]->TLV();
  TLorentzVector tlv_born_higgslep4  = tlv_born_higgslep12 + tlv_born_higgslep34;

  born_higgslep4_m = tlv_born_higgslep4.M();
  born_higgslep4_pt = tlv_born_higgslep4.Pt();
  born_higgslep4_eta = tlv_born_higgslep4.Eta();
  born_higgslep4_y = tlv_born_higgslep4.Rapidity();

  born_higgslep12_m = tlv_born_higgslep12.M();
  born_higgslep12_pt = tlv_born_higgslep12.Pt();
  born_higgslep12_eta = tlv_born_higgslep12.Eta();

  born_higgslep34_m = tlv_born_higgslep34.M();
  born_higgslep34_pt = tlv_born_higgslep34.Pt();
  born_higgslep34_eta = tlv_born_higgslep34.Eta();

  born_higgslep_pt.clear();
  born_higgslep_eta.clear();
  for (int i=0; i<4; i++){
    born_higgslep_pt.push_back(born_higgs_leptons[i]->TLV().Pt());
    born_higgslep_eta.push_back(born_higgs_leptons[i]->TLV().Eta());
  }

  GetElicityAngles( born_higgs_leptons[1]->TLV(), born_higgs_leptons[0]->TLV(), born_higgs_leptons[3]->TLV(), born_higgs_leptons[2]->TLV(), &born_higgslep4_cthstr, &born_higgslep4_phi1, &born_higgslep4_cth1, &born_higgslep4_cth2, &born_higgslep4_phi );
  
  if (born_higgslep4_cthstr > 1 || born_higgslep4_cthstr < -1){
     m_logger << ERROR << "costhetastar = "<<born_higgslep4_cthstr << " inputs are:"<< SLogger::endmsg; 
     for (int i=0; i<4; i++){
       born_higgs_leptons[1]->TLV().Print("all");
       //m_logger << ERROR << born_higgs_leptons[1]->TLV().Print("all") << SLogger::endmsg;
     }
  }
  
  std::vector<TruthParticle*> paired_born_leptons;
  PairLeptons(born_higgs_leptons, paired_born_leptons, false, false);

  TLorentzVector tlv_born_paired_higgslep12 = paired_born_leptons[0]->TLV()+paired_born_leptons[1]->TLV();
  TLorentzVector tlv_born_paired_higgslep34 = paired_born_leptons[2]->TLV()+paired_born_leptons[3]->TLV();
  TLorentzVector tlv_born_paired_higgslep4  = tlv_born_paired_higgslep12 + tlv_born_paired_higgslep34;

  born_paired_higgslep4_m = tlv_born_paired_higgslep4.M();
  born_paired_higgslep4_pt = tlv_born_paired_higgslep4.Pt();
  born_paired_higgslep4_eta = tlv_born_paired_higgslep4.Eta();
  born_paired_higgslep4_y = tlv_born_paired_higgslep4.Rapidity();

  born_paired_higgslep12_m = tlv_born_paired_higgslep12.M();
  born_paired_higgslep12_pt = tlv_born_paired_higgslep12.Pt();
  born_paired_higgslep12_eta = tlv_born_paired_higgslep12.Eta();

  born_paired_higgslep34_m = tlv_born_paired_higgslep34.M();
  born_paired_higgslep34_pt = tlv_born_paired_higgslep34.Pt();
  born_paired_higgslep34_eta = tlv_born_paired_higgslep34.Eta();

  GetElicityAngles( paired_born_leptons[1]->TLV(), paired_born_leptons[0]->TLV(), paired_born_leptons[3]->TLV(), paired_born_leptons[2]->TLV(), &born_paired_higgslep4_cthstr, &born_paired_higgslep4_phi1, &born_paired_higgslep4_cth1, &born_paired_higgslep4_cth2, &born_paired_higgslep4_phi );

  return;
}


//____________________________________________________________________________
void FiducialCutflow::FillHiggsVariables_JHU( std::vector<TruthParticle*> &tparts, std::vector<Jet> &all_jets){
  
  //to be completed
  
  return;

}

//____________________________________________________________________________
void FiducialCutflow::FillHiggsVariables_Prophecy4f( std::vector<TruthParticle*> &tparts, std::vector<Jet> &all_jets){

  //to be completed
  
  return;

}

