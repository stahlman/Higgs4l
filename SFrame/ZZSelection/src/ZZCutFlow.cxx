
// $Id: ZZCutFlow.cxx 27196 2014-05-28 03:10:25Z stahlman $

#include <math.h>

//Common Tools
#include "ScaleFactorTool.h"
#include "EnergyRescalerTool.h"
#include "IDTool.h"
#include "HiggsMassTool.h"

// Local include(s):
#include "../include/TriggerSelector.h"
#include "../include/MuonSelector.h"
#include "../include/ElectronSelector.h"
#include "../include/JetSelector.h"
#include "../include/QuadSelector.h"
#include "../include/TruthSelector.h"
#include "../include/FsrSelector.h"

//RootCore
#include "HiggsZZ4lUtils/GetElicityAngles.h"

#include "../include/ZZCutFlow.h"

ClassImp( ZZCutFlow );

ZZCutFlow::ZZCutFlow()
  : CycleBase(), 
    cf_preselect( "preselect", this ),
    cf_el_preselect( "el_preselect", this ),
    cf_mu_preselect( "mu_preselect", this ),
    cf_jet_preselect( "jet_preselect", this ),
    cf_grl( "grl", this ),
    cf_larerror( "larerror", this ),
    cf_tileerror( "tileerror", this ),
    cf_daqerror( "daqerror", this ),
    cf_trigger( "trigger", this ),
    cf_el_trigger( "el_trigger", this ),
    cf_mu_trigger( "mu_trigger", this ),
    cf_jet_trigger( "jet_trigger", this ),
    cf_vertex( "vertex", this ),
    cf_el_vertex( "em_vertex", this ),
    cf_mu_vertex( "mu_vertex", this ),
    cf_jet_vertex( "jet_vertex", this ),
    cf_leptons( "leptons", this ),
    cf_quads( "quads", this ),
    cf_four_mu( "four_mu", this ),
    cf_four_el( "four_el", this ),
    cf_two_mu_two_el( "two_mu_two_el", this ),
    cf_jetcuts( "jetcuts", this ),
    cf_addleptoncut( "addleptoncut", this ),
    cf_vbf( "cf_vbf", this),
    cf_vh_hadronic( "cf_vh_hadronic", this),
    cf_vh_leptonic( "cf_vh_leptonic", this),
    cf_ggf( "cf_ggf", this),
    cf_weighted_final( "cf_weighted_final", this),
    cf_signal_final( "cf_signal_final", this),
    cf_signal_weighted_final( "cf_signal_weighted_final", this)

{

   SetLogName( GetName() );
   DeclareProperty( "RecoTreeString", m_recoTreeName = "physics");
   DeclareProperty( "TrigTreeString", m_trigTreeName );
   DeclareProperty( "OutputTreeString", c_output_tree_name = "output");
   DeclareProperty( "DoGRL", m_doGRL = false );
   DeclareProperty( "DoLarError", m_doLarError = true);
   DeclareProperty( "DoTileError", m_doTileError = true);
   DeclareProperty( "DoDaqError", m_doDaqError = true);
   DeclareProperty( "DoTrigger", m_doTrig = true );
   DeclareProperty( "DoVertex", m_doVert = true );
   
   DeclareProperty( "DoLeptonSF", DoLeptonSF = true );
   DeclareProperty( "DoTriggerSF", DoTriggerSF = true);
   DeclareProperty( "DoPileupSF", DoPileupSF = true );
   DeclareProperty( "DoVertexSF", DoVertexSF = true );

   DeclareProperty( "JetContainer", c_jet_container = "jet_akt4topoem_");
   
   DeclareProperty( "DebugRun",   m_debugRun   = 0 );
   DeclareProperty( "DebugEvent", m_debugEvent = 0 );
   DeclareProperty( "DebugRun1",   m_debugRun1   = 0 );
   DeclareProperty( "DebugEvent1", m_debugEvent1 = 0 );
   DeclareProperty( "DebugRun2",   m_debugRun2   = 0 );
   DeclareProperty( "DebugEvent2", m_debugEvent2 = 0 );
   DeclareProperty( "DebugRun3",   m_debugRun3   = 0 );
   DeclareProperty( "DebugEvent3", m_debugEvent3 = 0 );
   DeclareProperty( "DebugRun4",   m_debugRun4   = 0 );
   DeclareProperty( "DebugEvent4", m_debugEvent4 = 0 );
   DeclareProperty( "DebugRun5",   m_debugRun5   = 0 );
   DeclareProperty( "DebugEvent5", m_debugEvent5 = 0 );
  


 
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
   
   //DECLARE_TOOL(GoodRunsListTool, "GoodRunsList");
   //DECLARE_TOOL(PileUpTool, "PileUpTool");
   //DECLARE_TOOL(PileupReweightingTool, "PileupReweighting");
   //DECLARE_TOOL(PileupReweightingTool, "ScaledMuPileupReweighting1");
   //DECLARE_TOOL(PileupReweightingTool, "ScaledMuPileupReweighting2");
   
   DECLARE_TOOL(TriggerSelector,    "TriggerSelector");
   DECLARE_TOOL(MuonSelector,       "MuonSelector");
   DECLARE_TOOL(ElectronSelector,   "ElectronSelector");
   DECLARE_TOOL(QuadSelector,       "QuadSelector");
   DECLARE_TOOL(TruthSelector,      "TruthSelector");
   DECLARE_TOOL(JetSelector,        "JetSelector");
   DECLARE_TOOL(FsrSelector,        "FsrSelector");
   DECLARE_TOOL(ScaleFactorTool,    "ScaleFactorTool");
   DECLARE_TOOL(EnergyRescalerTool, "EnergyRescalerTool");
   DECLARE_TOOL(IDTool,             "IDTool");
   DECLARE_TOOL(HiggsMassTool,      "HiggsMassTool");

}

ZZCutFlow::~ZZCutFlow() {

}

void ZZCutFlow::BeginCycleImp() throw( SError ) {  
  
  return;

}

void ZZCutFlow::EndCycleImp() throw( SError ) {

   return;

}

void ZZCutFlow::BeginInputDataImp( const SInputData& ) throw( SError ) {
  
  //Declare output variables:  
  DeclareVariable( m_4l, "m_4l");
  DeclareVariable( m_12, "m_12");
  DeclareVariable( m_34, "m_34");

  DeclareVariable( m_4l_fsr, "m_4l_fsr");
  DeclareVariable( m_12_fsr, "m_12_fsr");
  DeclareVariable( m_34_fsr, "m_34_fsr");

  DeclareVariable( m_4l_constrained, "m_4l_constrained");
  DeclareVariable( m_12_constrained, "m_12_constrained");
  DeclareVariable( m_34_constrained, "m_34_constrained");

  DeclareVariable( m_4l_id, "m_4l_id");

  DeclareVariable( m_4l_err, "m_4l_err");
  DeclareVariable( m_4l_err_fsr, "m_4l_err_fsr");
  DeclareVariable( m_4l_err_constrained, "m_4l_err_constrained");
  
  DeclareVariable( pt_4l, "pt_4l");
  DeclareVariable( pt_Z1, "pt_Z1");
  DeclareVariable( pt_Z2, "pt_Z2");

  DeclareVariable( pt_4l_constrained, "pt_4l_constrained");
  DeclareVariable( pt_Z1_constrained, "pt_Z1_constrained");
  DeclareVariable( pt_Z2_constrained, "pt_Z2_constrained");

  DeclareVariable( pt_4l_fsr, "pt_4l_fsr");
  DeclareVariable( pt_Z1_fsr, "pt_Z1_fsr");
  DeclareVariable( pt_Z2_fsr, "pt_Z2_fsr");

  DeclareVariable( eta_4l, "eta_4l");
  DeclareVariable( eta_4l_constrained, "eta_4l_constrained");
  DeclareVariable( eta_4l_fsr, "eta_4l_fsr");

  DeclareVariable( y_4l_unconstrained, "y4l_unconstrained");
  DeclareVariable( y_4l_unconstrained_mH, "y4l_unconstrained_mH");
  DeclareVariable( y_4l_constrained,   "y4l_constrained");
  DeclareVariable( y_4l_fsr,           "y4l_fsr");

  DeclareVariable( cthstr, "cthstr");
  DeclareVariable( phi1,   "phi1");
  DeclareVariable( cth1,   "cth1"); 
  DeclareVariable( cth2,   "cth2");
  DeclareVariable( phi,    "phi");

  DeclareVariable( n_quads, "n_quads");
  DeclareVariable( n_jets, "n_jets");
  DeclareVariable( m_jj, "m_jj");
  DeclareVariable( deltaeta_jj, "deltaeta_jj");
  DeclareVariable( pt_leadingjet, "pt_leadingjet");
  DeclareVariable( eta_leadingjet, "eta_leadingjet");
  DeclareVariable( pt_subleadingjet, "pt_subleadingjet");
  DeclareVariable( eta_subleadingjet, "eta_subleadingjet");
  DeclareVariable( VBF_discriminant,  "VBF_discriminant");
  DeclareVariable( HadVH_discriminant, "HadVH_discriminant");

  DeclareVariable( n_jets_fid, "n_jets_fid");
  DeclareVariable( pt_leadingjet_fid, "pt_leadingjet_fid");
  DeclareVariable( n_jets_fid_syst, "n_jets_fid_syst");
  DeclareVariable( pt_leadingjet_fid_syst, "pt_leadingjet_fid_syst");

  
  DeclareVariable( n_verts, "n_verts");
  DeclareVariable( mu, "mu");

  DeclareVariable( evt_weight, "evt_weight");
  DeclareVariable( lepton_sf,  "lepton_sf");
  DeclareVariable( trigger_sf, "trigger_sf");
  DeclareVariable( pileup_sf,  "pileup_sf");
  DeclareVariable( vertex_sf,  "vertex_sf");
  DeclareVariable( weight_brcorrection,  "weight_brcorrection");
  DeclareVariable( weight_higgspt,  "weight_higgspt");

  //systematic variations
  DeclareVariable( lepton_sf_ElectronRecoLow   , "lepton_sf_ElectronRecoLow");
  DeclareVariable( lepton_sf_ElectronRecoHigh  , "lepton_sf_ElectronRecoHigh");
  DeclareVariable( lepton_sf_ElectronIDLow     , "lepton_sf_ElectronIDLow");
  DeclareVariable( lepton_sf_ElectronIDStatHigh, "lepton_sf_ElectronIDStatHigh");
  DeclareVariable( lepton_sf_ElectronStat15    , "lepton_sf_ElectronStat15");
  DeclareVariable( lepton_sf_ElectronStat10    , "lepton_sf_ElectronStat10");
  DeclareVariable( lepton_sf_ElectronStat7     , "lepton_sf_ElectronStat7");
  DeclareVariable( lepton_sf_MuonSyst, "lepton_sf_MuonSyst");
  DeclareVariable( trigger_sf_ElectronSyst, "trigger_sf_ElectronSyst");
  DeclareVariable( trigger_sf_MuonSyst, "trigger_sf_MuonSyst");
  DeclareVariable( isolationip_sf_ElectronSyst, "isolationip_sf_ElectronSyst");
  DeclareVariable( qcd_scale_weights,   "qcd_scale_weights");
  DeclareVariable( pdf_weights,   "pdf_weights");
/*
  DeclareVariable( weight_pt_ZZPdfUp,   "weight_pt_ZZPdfUp");
  DeclareVariable( weight_pt_ZZPdfDn,   "weight_pt_ZZPdfDn");
  DeclareVariable( weight_pt_ZZScaleUp, "weight_pt_ZZScaleUp");
  DeclareVariable( weight_pt_ZZScaleDn, "weight_pt_ZZScaleDn");
  DeclareVariable( weight_rapidity_ZZPdfUp,   "weight_rapidity_ZZPdfUp");
  DeclareVariable( weight_rapidity_ZZPdfDn,   "weight_rapidity_ZZPdfDn");
  DeclareVariable( weight_rapidity_ZZScaleUp, "weight_rapidity_ZZScaleUp");
  DeclareVariable( weight_rapidity_ZZScaleDn, "weight_rapidity_ZZScaleDn");
  DeclareVariable( weight_m34_ZZPdfUp,   "weight_m34_ZZPdfUp");
  DeclareVariable( weight_m34_ZZPdfDn,   "weight_m34_ZZPdfDn");
  DeclareVariable( weight_m34_ZZScaleUp, "weight_m34_ZZScaleUp");
  DeclareVariable( weight_m34_ZZScaleDn, "weight_m34_ZZScaleDn");
  DeclareVariable( weight_costhetastar_ZZPdfUp,   "weight_costhetastar_ZZPdfUp");
  DeclareVariable( weight_costhetastar_ZZPdfDn,   "weight_costhetastar_ZZPdfDn");
  DeclareVariable( weight_costhetastar_ZZScaleUp, "weight_costhetastar_ZZScaleUp");
  DeclareVariable( weight_costhetastar_ZZScaleDn, "weight_costhetastar_ZZScaleDn");
*/  
  DeclareVariable( evt_category, "evt_category");

  DeclareVariable( evt_passML, "evt_passML");
  DeclareVariable( evt_passML_HCP, "evt_passML_HCP");
  DeclareVariable( evt_passML_Relaxed, "evt_passML_Relaxed");
  DeclareVariable( evt_passLikelihood, "evt_passLikelihood");
  DeclareVariable( evt_passLooseRelaxedLikelihood, "evt_passLooseRelaxedLikelihood");
  DeclareVariable( evt_passVeryLooseLikelihood, "evt_passVeryLooseLikelihood");
  DeclareVariable( evt_passLooseLikelihood, "evt_passLooseLikelihood");
  DeclareVariable( evt_passLooseBLPixLikelihood, "evt_passLooseBLPixLikelihood");
  DeclareVariable( evt_passMediumLikelihood, "evt_passMediumLikelihood");

  DeclareVariable( evt_passLooseBLPixLowLikelihood, "evt_passLooseBLPixLowLikelihood");
  DeclareVariable( evt_passLooseBLPixMedLikelihood, "evt_passLooseBLPixMedLikelihood");
  DeclareVariable( evt_passLooseBLPixHighLikelihood, "evt_passLooseBLPixHighLikelihood");

  DeclareVariable( quad_type, "quad_type");
  DeclareVariable( quad_passML, "quad_passML");
  DeclareVariable( quad_passML_HCP, "quad_passML_HCP");
  DeclareVariable( quad_passML_Relaxed, "quad_passML_Relaxed");
  DeclareVariable( quad_passLikelihood, "quad_passLikelihood");
  DeclareVariable( quad_passLooseRelaxedLikelihood, "quad_passLooseRelaxedLikelihood");
  DeclareVariable( quad_passVeryLooseLikelihood, "quad_passVeryLooseLikelihood");
  DeclareVariable( quad_passLooseLikelihood, "quad_passLooseLikelihood");
  DeclareVariable( quad_passLooseBLPixLikelihood, "quad_passLooseBLPixLikelihood");
  DeclareVariable( quad_passMediumLikelihood, "quad_passMediumLikelihood");

  DeclareVariable( quad_passLooseBLPixLowLikelihood, "quad_passLooseBLPixLowLikelihood");
  DeclareVariable( quad_passLooseBLPixMedLikelihood, "quad_passLooseBLPixMedLikelihood");
  DeclareVariable( quad_passLooseBLPixHighLikelihood, "quad_passLooseBLPixHighLikelihood");

  DeclareVariable( quad_passTrkIso, "quad_passTrkIso");
  DeclareVariable( quad_passCaloIso, "quad_passCaloIso");

  DeclareVariable( quad_hasStandaloneMuon, "quad_hasStandaloneMuon");
  DeclareVariable( quad_hasCaloMuon, "quad_hasCaloMuon");

  DeclareVariable( quad_TriggerBitword, "quad_TriggerBitword");

  DeclareVariable( lepton_type,  "lepton_type");
  DeclareVariable( lepton_index,  "lepton_index");

  DeclareVariable( lepton_sf_recoid,  "lepton_sf_recoid");

  DeclareVariable( lepton_pt,   "lepton_pt");
  DeclareVariable( lepton_eta,  "lepton_eta");
  DeclareVariable( lepton_phi,  "lepton_phi");
  DeclareVariable( lepton_m,    "lepton_m");

  DeclareVariable( lepton_cov_mom,    "lepton_cov_mom");

  DeclareVariable( lepton_pt_id,   "lepton_pt_id");
  DeclareVariable( lepton_eta_id,  "lepton_eta_id");
  DeclareVariable( lepton_phi_id,  "lepton_phi_id");

  DeclareVariable( lepton_pt_truth_born,   "lepton_pt_truth_born");
  DeclareVariable( lepton_eta_truth_born,  "lepton_eta_truth_born");
  DeclareVariable( lepton_phi_truth_born,  "lepton_phi_truth_born");
  DeclareVariable( lepton_m_truth_born,    "lepton_m_truth_born");

  DeclareVariable( lepton_pt_truth_paired_bare,   "lepton_pt_truth_paired_bare");
  DeclareVariable( lepton_eta_truth_paired_bare,  "lepton_eta_truth_paired_bare");
  DeclareVariable( lepton_phi_truth_paired_bare,  "lepton_phi_truth_paired_bare");
  DeclareVariable( lepton_m_truth_paired_bare,    "lepton_m_truth_paired_bare");

  DeclareVariable( lepton_pt_truth_paired_dressed,   "lepton_pt_truth_paired_dressed");
  DeclareVariable( lepton_eta_truth_paired_dressed,  "lepton_eta_truth_paired_dressed");
  DeclareVariable( lepton_phi_truth_paired_dressed,  "lepton_phi_truth_paired_dressed");
  DeclareVariable( lepton_m_truth_paired_dressed,    "lepton_m_truth_paired_dressed");

  DeclareVariable( lepton_pt_truth_matched_bare,   "lepton_pt_truth_matched_bare");
  DeclareVariable( lepton_eta_truth_matched_bare,  "lepton_eta_truth_matched_bare");
  DeclareVariable( lepton_phi_truth_matched_bare,  "lepton_phi_truth_matched_bare");
  DeclareVariable( lepton_m_truth_matched_bare,    "lepton_m_truth_matched_bare");

  DeclareVariable( lepton_pt_truth_matched_dressed,   "lepton_pt_truth_matched_dressed");
  DeclareVariable( lepton_eta_truth_matched_dressed,  "lepton_eta_truth_matched_dressed");
  DeclareVariable( lepton_phi_truth_matched_dressed,  "lepton_phi_truth_matched_dressed");
  DeclareVariable( lepton_m_truth_matched_dressed,    "lepton_m_truth_matched_dressed");

  DeclareVariable( lepton_pt_truth_matched_born,   "lepton_pt_truth_matched_born");
  DeclareVariable( lepton_eta_truth_matched_born,  "lepton_eta_truth_matched_born");
  DeclareVariable( lepton_phi_truth_matched_born,  "lepton_phi_truth_matched_born");
  DeclareVariable( lepton_m_truth_matched_born,    "lepton_m_truth_matched_born");

  DeclareVariable( lepton_trk_iso20,  "lepton_trk_iso20");
  DeclareVariable( lepton_trk_iso30,  "lepton_trk_iso30");
  DeclareVariable( lepton_trk_iso40,  "lepton_trk_iso40");
  
  DeclareVariable( lepton_calo_iso20,  "lepton_calo_iso20");
  DeclareVariable( lepton_calo_iso30,  "lepton_calo_iso30");
  DeclareVariable( lepton_calo_iso40,  "lepton_calo_iso40");

  DeclareVariable( lepton_d0_significance,  "lepton_d0_significance");

  DeclareVariable( lepton_dR_jet,  "lepton_dR_jet");

  DeclareVariable( lepton_passML,  "lepton_passML");
  DeclareVariable( lepton_passML_HCP,  "lepton_passML_HCP");
  DeclareVariable( lepton_passML_Relaxed,  "lepton_passML_Relaxed");
  DeclareVariable( lepton_passLikelihood,  "lepton_passLikelihood");
  DeclareVariable( lepton_passLooseRelaxedLikelihood,  "lepton_passLooseRelaxedLikelihood");
  DeclareVariable( lepton_passVeryLooseLikelihood,  "lepton_passVeryLooseLikelihood");
  DeclareVariable( lepton_passLooseLikelihood,  "lepton_passLooseLikelihood");
  DeclareVariable( lepton_passLooseBLPixLikelihood,  "lepton_passLooseBLPixLikelihood");
  DeclareVariable( lepton_passMediumLikelihood,  "lepton_passMediumLikelihood");

  DeclareVariable( lepton_passLooseBLPixLowLikelihood,  "lepton_passLooseBLPixLowLikelihood");
  DeclareVariable( lepton_passLooseBLPixMedLikelihood,  "lepton_passLooseBLPixMedLikelihood");
  DeclareVariable( lepton_passLooseBLPixHighLikelihood,  "lepton_passLooseBLPixHighLikelihood");

  DeclareVariable( mc_event_weight,   "mc_event_weight");
  DeclareVariable( mc_event_reweight, "mc_event_reweight");

  DeclareVariable( event_type_truth,  "event_type_truth");
  DeclareVariable( mispaired,  "mispaired");
  DeclareVariable( reco_higgs_quad, "reco_higgs_quad");

  DeclareVariable( m_higgs_truth,   "m_higgs_truth");
  DeclareVariable( pt_higgs_truth,  "pt_higgs_truth");
  DeclareVariable( eta_higgs_truth, "eta_higgs_truth");
  DeclareVariable( y_higgs_truth,   "y_higgs_truth");

  DeclareVariable( m_Z1_truth, "m_Z1_truth");
  DeclareVariable( m_Z2_truth, "m_Z2_truth");

  DeclareVariable( pt_Z1_truth, "pt_Z1_truth");
  DeclareVariable( pt_Z2_truth, "pt_Z2_truth");

  DeclareVariable( m_4l_truth, "m_4l_truth");
  DeclareVariable( m_l12_truth, "m_l12_truth");
  DeclareVariable( m_l34_truth, "m_l34_truth");

  DeclareVariable( pt_4l_truth, "pt_4l_truth");
  DeclareVariable( pt_l12_truth, "pt_l12_truth");
  DeclareVariable( pt_l34_truth, "pt_l34_truth");

  DeclareVariable( m4l_truth_paired_bare, "m4l_truth_paired_bare");
  DeclareVariable( m12_truth_paired_bare, "m12_truth_paired_bare");
  DeclareVariable( m34_truth_paired_bare, "m34_truth_paired_bare");

  DeclareVariable( m4l_truth_paired_dressed, "m4l_truth_paired_dressed");
  DeclareVariable( m12_truth_paired_dressed, "m12_truth_paired_dressed");
  DeclareVariable( m34_truth_paired_dressed, "m34_truth_paired_dressed");

  DeclareVariable( m4l_truth_matched_bare, "m4l_truth_matched_bare");
  DeclareVariable( m12_truth_matched_bare, "m12_truth_matched_bare");
  DeclareVariable( m34_truth_matched_bare, "m34_truth_matched_bare");

  DeclareVariable( m4l_truth_matched_dressed, "m4l_truth_matched_dressed");
  DeclareVariable( m12_truth_matched_dressed, "m12_truth_matched_dressed");
  DeclareVariable( m34_truth_matched_dressed, "m34_truth_matched_dressed");

  DeclareVariable( m4l_truth_matched_born, "m4l_truth_matched_born");
  DeclareVariable( m12_truth_matched_born, "m12_truth_matched_born");
  DeclareVariable( m34_truth_matched_born, "m34_truth_matched_born");

  //Declare Histograms
  Book("NEvents", "Number of Events", 3, 0., 3.,"");
  
  m_logger << ::DEBUG  << "Initializing Categories MVA" << SLogger::endmsg;
  m_CategoriesDiscriminantTool = new CategoriesMVA( sframe_dir()+"/RootCore/CategoriesMVA/weights" );
  m_CategoriesDiscriminantTool->ConnectVariables( m_jj, deltaeta_jj, pt_leadingjet, eta_leadingjet, pt_subleadingjet );

  //m_logger << ::DEBUG  << "Initializing ZZ Pt systematic tool" << SLogger::endmsg;
  //m_ZZPtSystTool = new ZZPtSystTool(sframe_dir()+"/config/other/Inputsys.v2.root");

  // -----------------------------------------------------------------
  // ---------------- D3PD Reader constuctors ------------------------
 
  //if(is_data()) cout<<"isData!!!"<<endl;
  //else cout<<"isMC!!!"<<endl;
   m_logger << ::DEBUG  << "Initializing D3PD Objects" << SLogger::endmsg;

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
  m_truthjet_d3pdobject = new D3PDReader::JetD3PDObject( m_entry_number, "jet_antikt4truth_" );

  m_met_d3pdobject = new D3PDReader::METD3PDObject( m_entry_number, "MET_RefFinal_" );
  m_photon_d3pdobject = new D3PDReader::PhotonD3PDObject( m_entry_number, "ph_" );

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
    if(!is_data()) m_electron_d3pdobject->SetActive(kTRUE,"\\bcl_eta\\b|\\btracketa\\b|\\bnTRTHits\\b|\\bnTRTOutliers\\b|\\bnTRTHighTHits\\b|\\bnTRTHighTOutliers\\b|\\bTRTHighTOutliersRatio\\b|\\brphi\\b|\\btracksigd0pvunbiased\\b|\\btrackd0pvunbiased\\b|\\bf1\\b|\\bexpectHitInBLayer\\b|\\bnBLHits\\b|\\bnPixHits\\b|\\bnPixelDeadSensors\\b|\\bnSCTHits\\b|\\bnSCTDeadSensors\\b|\\btype\\b|\\borigin\\b|\\btypebkg\\b|\\boriginbkg\\b");
    else m_electron_d3pdobject->SetActive(kTRUE,"\\bcl_phi\\b|\\bcl_eta\\b|\\btracketa\\b|\\bnTRTHits\\b|\\bnTRTOutliers\\b|\\bnTRTHighTHits\\b|\\bnTRTHighTOutliers\\b|\\bTRTHighTOutliersRatio\\b|\\brphi\\b|\\btracksigd0pvunbiased\\b|\\btrackd0pvunbiased\\b|\\bf1\\b|\\bexpectHitInBLayer\\b|\\bnBLHits\\b|\\bnPixHits\\b|\\bnPixelDeadSensors\\b|\\bnSCTHits\\b|\\bnSCTDeadSensors\\b");
    //else m_electron_d3pdobject->SetActive(kTRUE,".*");
    m_muon_staco_d3pdobject->SetActive(kTRUE,"\\beta\\b|\\bauthor\\b|\\bisStandAloneMuon\\b");
    m_muon_calo_d3pdobject->SetActive(kTRUE,"\\beta\\b|\\bauthor\\b|\\bisStandAloneMuon\\b");

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

void ZZCutFlow::EndInputDataImp( const SInputData& ) throw( SError ) {

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
    delete m_truthjet_d3pdobject;

    delete m_photon_d3pdobject;
    delete m_met_d3pdobject;    

   return;

}

void ZZCutFlow::BeginInputFileImp( const SInputData& ) throw( SError ) {

    m_logger << ::DEBUG  << "BeginInputFileImp "                         << SLogger::endmsg;

    m_event_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_trigger_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_vxp_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_electron_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_staco_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_calo_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_jet_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_mcevt_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_truth_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_truthjet_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_photon_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_met_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );


   return;

}

void ZZCutFlow::BeginMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZZCutFlow::EndMasterInputDataImp( const SInputData& data) throw( SError ){

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
  m_logger << ALWAYS <<"Events After Lepton Sel......:"<<*cf_leptons    <<" ("<<((double)*cf_leptons)/((double)*cf_trigger)*100 <<"%)"   <<" ("<<((double)*cf_leptons)/((double)*cf_preselect)*100 <<"%)"  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Lepton Sel(4e)..:"<<*cf_four_el       <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Lepton Sel(4m)..:"<<*cf_four_mu       <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Lepton Sel(2e2m):"<<*cf_two_mu_two_el <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Jet Cuts........:"<<*cf_jetcuts <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Quad Sel........: "<<*cf_quads      <<" ("<<((double)*cf_quads)/((double)*cf_leptons)*100 <<"%)"     <<" ("<<((double)*cf_quads)/((double)*cf_preselect)*100 <<"%)"    <<SLogger::endmsg;
  m_logger << ALWAYS <<"Events After Add Lepton Cut (GGF, VH)........: "<<*cf_addleptoncut      <<" ("<<((double)*cf_addleptoncut)/((double)*cf_quads)*100 <<"%)"     <<" ("<<((double)*cf_addleptoncut)/((double)*cf_preselect)*100 <<"%)"    <<SLogger::endmsg;
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
  m_logger << ALWAYS <<"Jets Before Cuts..........:"<<*cf_jet_preselect  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Jets After Vertex.........:"<<*cf_jet_vertex  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Jets After Trigger........:"<<*cf_jet_trigger  <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;

  m_logger << ALWAYS <<"                  H -> ZZ Signal Region Yields (120-130 GeV)"<<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"Events.....................:"<<*cf_signal_final  <<SLogger::endmsg;
  m_logger << ALWAYS <<"Weighted Events............:"<<*cf_signal_weighted_final     <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;

  m_logger << ALWAYS <<"                  H -> ZZ Yields by Category"         <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << ALWAYS <<"VBF Events...........:"<<*cf_vbf  <<SLogger::endmsg;
  m_logger << ALWAYS <<"VH-Hadronic Events...:"<<*cf_vh_hadronic     <<SLogger::endmsg;
  m_logger << ALWAYS <<"VH-Leptonic Events...:"<<*cf_vh_leptonic     <<SLogger::endmsg;
  m_logger << ALWAYS <<"ggH Events...........:"<<*cf_ggf     <<SLogger::endmsg;
  m_logger << ALWAYS <<"============================"<<"============================"<<SLogger::endmsg;

  PrintCutFlow(data);

  return;

}

void ZZCutFlow::ExecuteEventImp( const SInputData&, Double_t ) throw( SError ) {

  //only do this once (or so)
  if(cf_preselect == 0){
      if(!is_data()) m_mc_channel_number = m_event_d3pdobject->mc_channel_number();
      else m_mc_channel_number = -1;
      //m_logger << ::DEBUG <<"m_mc_channel_number: "<<m_mc_channel_number<<SLogger::endmsg;
      Set_MC_channel_number(m_mc_channel_number);
      
      //initialize shitty BR correciton tool
      br_tool = new BRCorrection(m_mc_channel_number,true);
  }
  
  //reset vectors with persistified objects
  for (unsigned int i = 0; i <sel_muons.size(); i++)delete sel_muons.at(i);
  for (unsigned int i = 0; i <sel_electrons.size(); i++) delete sel_electrons.at(i);
  for (unsigned int i = 0; i <all_quads.size(); i++) delete all_quads.at(i);  
  for (unsigned int i = 0; i <sel_jets.size(); i++) delete sel_jets.at(i);
  for (unsigned int i = 0; i <sel_jets_fid.size(); i++) delete sel_jets_fid.at(i);

  sel_muons.clear();
  sel_electrons.clear();
  all_quads.clear();
  sel_jets.clear();
  sel_jets_fid.clear();

  //debug filter for picking out events
   if (m_debugEvent != 0 && m_event_d3pdobject->EventNumber() != m_debugEvent) throw SError( SError::SkipEvent );
   /*
   {
      int runarr[] = {m_debugRun,m_debugRun1,m_debugRun2,m_debugRun3,m_debugRun4,m_debugRun5};
      int eventarr[] = {m_debugEvent,m_debugEvent1,m_debugEvent2,m_debugEvent3,m_debugEvent4,m_debugEvent5};
      int debugnum = 6;  
      bool founddebug = 0;
      for(int idebug = 0; idebug < debugnum; idebug++){
	if (m_event_d3pdobject->EventNumber() == (unsigned int)eventarr[idebug] && m_event_d3pdobject->RunNumber() == (unsigned int)runarr[idebug]) {
               m_logger << ALWAYS << "Found debug event: " << runarr[idebug] << eventarr[idebug] << SLogger::endmsg;    
               founddebug = 1;
          }//if foundevent
       }//loop over debug events 
      if(founddebug == 0 ) throw SError( SError::SkipEvent );
   }//only do this if debugging necessary
  */
  mu= (m_event_d3pdobject->lbn()==1 && int(m_event_d3pdobject->averageIntPerXing()+0.5)==1) ? 0. : m_event_d3pdobject->averageIntPerXing();

  //Removing MC events with bad trigger due to bug
  //Done before preselect!!
  if (!is_data()){   
    GET_TOOL(trig_select, TriggerSelector, "TriggerSelector");
    
    if (!(trig_select->hasMCTriggerInfo())){
      m_logger << ::WARNING << "No trigger info: skipping event! " << SLogger::endmsg;
       throw SError( SError::SkipEvent );
    }
  }

  // Calculate some event weights and truth quantities before any event cuts
  // Needed for weighted cutfow 
  //
  evt_weight = 1.0;  
  pileup_sf = 1.0;
  vertex_sf = 1.0;
  mc_event_weight = 1.0;  
  weight_brcorrection = 1.0;
  weight_higgspt = 1.0;

  GET_TOOL(sf_tool, ScaleFactorTool, "ScaleFactorTool");
  if (!is_data()) {

    m_logger << ::DEBUG << "Pileup SF " << SLogger::endmsg;
    pileup_sf  = sf_tool->PileupSF(m_event_d3pdobject);

    m_logger << ::DEBUG << "Vertex SF " << SLogger::endmsg;
    vertex_sf  = sf_tool->VertexSF( m_truth_d3pdobject[0].vx_z()->at(2) );    

    m_logger << ::DEBUG << "mcevt_weight SF " << SLogger::endmsg;
    if( m_mcevt_d3pdobject->mcevt_weight.IsAvailable() ) {  
       mc_event_weight = m_mcevt_d3pdobject->mcevt_weight()->at(0).at(0);    
    }
    
    m_logger << ::DEBUG << "BR Correction " << SLogger::endmsg;
    weight_brcorrection = br_tool->getBRcorrection(m_truth_d3pdobject->pdgId(), 
                                                   m_truth_d3pdobject->status(), 
                                                   m_truth_d3pdobject->child_index(),
                                                   m_truth_d3pdobject->parent_index());                                                   
                                                       
    m_logger << ::DEBUG << "Retrieving truth tool "<< SLogger::endmsg;  
    GET_TOOL(truth_select, TruthSelector, "TruthSelector");

    std::vector<TruthParticle*> tparts;    
    ParticleElementBuilder::build( tparts, (*m_truth_d3pdobject) );
   
    m_logger << ::DEBUG << "Retrieving truth Higgs "<< SLogger::endmsg;      
    TruthParticle* higgs = truth_select->GetTruthHiggs(tparts); 
    if (higgs){
      m_higgs_truth   = higgs->m();
      pt_higgs_truth  = higgs->pt();
      eta_higgs_truth = higgs->eta();
      y_higgs_truth   = higgs->TLV().Rapidity();
    } else {
      m_higgs_truth   = 0;
      pt_higgs_truth  = 0;
      eta_higgs_truth = 0;
      y_higgs_truth   = 0;
    }    
    
    m_logger << ::DEBUG << "Higgs Pt Correction " << SLogger::endmsg;

    std::vector<Jet> truth_jets;    
    ParticleElementBuilder::build( truth_jets, (*m_truthjet_d3pdobject) );

    weight_higgspt = truth_select->HiggsPtWeight(m_mc_channel_number, tparts, truth_jets);
                                                      
    //clean up
    for (unsigned int i = 0; i <tparts.size(); i++) delete tparts[i];

  }

  evt_weight *= mc_event_weight;
  evt_weight *= (DoPileupSF ? pileup_sf : 1.0);
  evt_weight *= (DoVertexSF ? vertex_sf : 1.0);
  evt_weight *= weight_higgspt;

  Hist("NEvents")->Fill( 0., 1. );
  Hist("NEvents")->Fill( 1., is_data() ? 1 : evt_weight );

  //CutFlow("Preselect",true,false,evt_weight);
  ++cf_preselect;
  cf_el_preselect += m_electron_d3pdobject->n();
  cf_mu_preselect += m_muon_staco_d3pdobject->n() + m_muon_calo_d3pdobject->n();
  cf_jet_preselect += m_jet_d3pdobject->n();
  
  //TODO - maybe add GRL tool here?
  CutFlow("GRL",true,false,evt_weight);
  ++cf_grl;

  m_logger << ::DEBUG << "LArError Cut " << SLogger::endmsg;
  bool passLArError = sf_tool->PassLArError(m_event_d3pdobject);
  CutFlow("LAR Error",passLArError,m_doLarError,evt_weight);
  ++cf_larerror;

  m_logger << ::DEBUG << "TileError Cut " << SLogger::endmsg;
  bool passTileError = sf_tool->PassTileError(m_event_d3pdobject);
  CutFlow("Tile Error",passTileError,m_doTileError,evt_weight);
  ++cf_tileerror;

  bool passDaqError = true;
  if (is_data()) {
    m_logger << ::DEBUG << "DaqError Cut" << SLogger::endmsg;
    if ((m_event_d3pdobject->coreFlags()&0x40000) != 0) passDaqError = false;
  }
  CutFlow("DAQ Error",passDaqError,m_doDaqError,evt_weight);
  ++cf_daqerror;
  
  //vertices
  bool vertex_pass = false;
  n_verts = 0;
  int n_verts2 = 0; //vertices with 2 tracks, needed for electron likelihood, jet calibration
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
  CutFlow("Vertex",vertex_pass,m_doVert,evt_weight);
  ++cf_vertex;
  cf_el_vertex += m_electron_d3pdobject->n();
  cf_mu_vertex += m_muon_staco_d3pdobject->n() + m_muon_calo_d3pdobject->n();
  cf_jet_vertex += m_jet_d3pdobject->n();

  //trigger cuts
  m_logger << ::DEBUG << "Trigger Cut " << SLogger::endmsg;    
  GET_TOOL(trig_select, TriggerSelector, "TriggerSelector");
  bool trigger_pass = trig_select->SelectTriggers( m_trigger_d3pdobject );  
  CutFlow("Trigger",trigger_pass,m_doTrig,evt_weight);
  ++cf_trigger;
  cf_el_trigger += m_electron_d3pdobject->n();
  cf_mu_trigger += m_muon_staco_d3pdobject->n() + m_muon_calo_d3pdobject->n();
  cf_jet_trigger += m_jet_d3pdobject->n();

  GET_TOOL(mu_select, MuonSelector, "MuonSelector");
  mu_select->SelectMuons(sel_muons, m_muon_staco_d3pdobject, m_muon_calo_d3pdobject, m_event_d3pdobject->EventNumber()); 

  GET_TOOL(el_select, ElectronSelector, "ElectronSelector");  
  el_select->SelectElectrons(sel_electrons, m_electron_d3pdobject, m_event_d3pdobject,n_verts2); 
  
  //overlap removal between electrons and muons
  el_select->RemoveElectronMuonOverlap(sel_muons, sel_electrons);  
  mu_select->RemoveElectronMuonOverlap(sel_muons, sel_electrons);  

  GET_TOOL(jet_select, JetSelector, "JetSelector");  

  //calculate jet variables for categorization
  jet_select->SelectJets(sel_jets, m_jet_d3pdobject, mu, n_verts2, JetSelector::DEFAULT, true); 
  jet_select->RemoveElectronJetOverlap(sel_electrons, sel_jets, JetSelector::DEFAULT, true);

  //never used, for testing only
  //mu_select->RemoveJetMuonOverlap(sel_muons, sel_jets);  
  
  //BCH Cleaning
  //bool passBCH = sf_tool->PassBCHCleaning(m_event_d3pdobject,sel_jets);
  //CutFlow("BCH Clean",passBCH, true, evt_weight);
  
  n_jets = sel_jets.size();
  pt_leadingjet     = n_jets >= 1 ? sel_jets[0]->Pt()  : -999000.;
  eta_leadingjet    = n_jets >= 1 ? sel_jets[0]->Eta() : -999.;
  pt_subleadingjet  = n_jets >= 2 ? sel_jets[1]->Pt()  : -999000.;
  eta_subleadingjet = n_jets >= 2 ? sel_jets[1]->Eta() : -999.;
  deltaeta_jj       = n_jets >= 2 ? sel_jets[0]->Eta() - sel_jets[1]->Eta() : 0;
  m_jj              = n_jets >= 2 ? (sel_jets[0]->TLV() + sel_jets[1]->TLV()).M() : 0;
  
  //CutFlow("Jet Cuts",true,false,evt_weight);
  cf_jetcuts++;

  GET_TOOL(quad_select, QuadSelector, "QuadSelector");
  
  bool passed_leptons = false;
  bool doall                = (quad_select->GetDoFourMuon() && quad_select->GetDoFourElectron() && quad_select->GetDoTwoElectronTwoMuon() && quad_select->GetDoTwoMuonTwoElectron());
  bool dofourmuon           = quad_select->GetDoFourMuon() || doall;
  bool dofourelectron       = quad_select->GetDoFourElectron() || doall;
  bool dotwomuontwoelectron = quad_select->GetDoTwoElectronTwoMuon() || quad_select->GetDoTwoMuonTwoElectron() || doall;

  if (dofourmuon           && sel_muons.size() >=4) { passed_leptons = true; cf_four_mu++;}
  if (dofourelectron       && sel_electrons.size() >=4) { passed_leptons = true; cf_four_el++; }
  if (dotwomuontwoelectron && (sel_muons.size() >= 2) && (sel_electrons.size() >=2)) { passed_leptons = true;cf_two_mu_two_el++; }

  CutFlow("Lepton Sel",passed_leptons,true,evt_weight);
  cf_leptons++;

  std::vector<Quadruplet*> sel_quads;
  
  quad_select->MakeQuadruplets(sel_electrons, sel_muons, all_quads);   
  quad_select->SelectQuadruplets(all_quads, sel_quads,n_verts2);   

  //bool quad_cuts = quad_select->GetEvent_SFOS() && quad_select->GetEvent_kinematics() && quad_select->GetEvent_trigger() && (sel_quads.size() != 0);
  CutFlow("SFOS      ",quad_select->GetEvent_SFOS(),	  true,evt_weight);
  CutFlow("kinematics",quad_select->GetEvent_kinematics(),true,evt_weight);
  CutFlow("trigger   ",quad_select->GetEvent_trigger(),	  true,evt_weight);    
  CutFlow("Quad Sel  ",(sel_quads.size() != 0),		  true,evt_weight);
  cf_quads++;


  GET_TOOL(id, IDTool, "IDTool");
  m_logger << ::DEBUG << "ID Tool " << SLogger::endmsg;
  n_quads = 0;
  evt_passML = false;
  evt_passML_HCP = false;
  evt_passML_Relaxed = false;
  evt_passLikelihood = false;
  evt_passLooseRelaxedLikelihood = false;
  evt_passVeryLooseLikelihood = false;
  evt_passLooseLikelihood = false;
  evt_passLooseBLPixLikelihood = false;
  evt_passMediumLikelihood = false;

  evt_passLooseBLPixLowLikelihood = false;
  evt_passLooseBLPixMedLikelihood = false;
  evt_passLooseBLPixHighLikelihood = false;

  std::vector<double> masses;
  std::vector<int> lepton_passID;
  bool quad_pass = false; 
  for (unsigned int i=0; i<sel_quads.size(); i++){
    //
    // Note! This call below has no effect on the cutflow!
    if ( quad_select->FinalQuadCuts(sel_quads.at(i), false) ){
    
      lepton_passID.clear();
      evt_passML     |= id->passML(lepton_passID,sel_quads.at(i),"");

      lepton_passID.clear();
      evt_passML_HCP |= id->passML_HCP(lepton_passID,sel_quads.at(i),"");

      lepton_passID.clear();
      evt_passML_Relaxed |= id->passML(lepton_passID,sel_quads.at(i),"Relaxed");

      lepton_passID.clear();
      evt_passLikelihood |= id->passLikelihood(lepton_passID,sel_quads.at(i),"Loose_PostHCP",n_verts2);

      lepton_passID.clear();
      evt_passLooseRelaxedLikelihood |= id->passLikelihood(lepton_passID,sel_quads.at(i),LikeEnum::LooseRelaxed,n_verts2);

      lepton_passID.clear();
      evt_passVeryLooseLikelihood |= id->passLikelihood(lepton_passID,sel_quads.at(i),"VeryLoose",n_verts2);

      lepton_passID.clear();
      evt_passLooseLikelihood |= id->passLikelihood(lepton_passID,sel_quads.at(i),"Loose",n_verts2);

      //lepton_passID.clear();
      //evt_passLooseBLPixLikelihood |= id->passLikelihood(lepton_passID,sel_quads.at(i),LikeEnum::Loose_BL_Pix,n_verts2);

//       lepton_passID.clear();
//       evt_passLooseBLPixLowLikelihood |= id->passLikelihood(lepton_passID,sel_quads.at(i),LLikeEnum::Loose_BL_PixLow,n_verts2);

//       lepton_passID.clear();
//       evt_passLooseBLPixMedLikelihood |= id->passLikelihood(lepton_passID,sel_quads.at(i),LLikeEnum::Loose_BL_PixMed,n_verts2);

//       lepton_passID.clear();
//       evt_passLooseBLPixHighLikelihood |= id->passLikelihood(lepton_passID,sel_quads.at(i),LLikeEnum::Loose_BL_PixHigh,n_verts2);

      lepton_passID.clear();
      evt_passMediumLikelihood |= id->passLikelihood(lepton_passID,sel_quads.at(i),"Medium",n_verts2);

      double mass = sel_quads.at(i)->M4l();
      if (std::find(masses.begin(), masses.end(), mass)==masses.end()){
	masses.push_back(mass);
	n_quads++;
      }
    }
  }  

  //
  // Cutflow only! Do this in the invidual channel
  //
  // Final quad. 15 means all channels.
  // If the channels are turned off in the xml file, then those channels will not have
  // quads selected.
  quad_select->ResetFinalQuadCuts(); //reset booleans for cutflow
  
  Quadruplet* final_quad_4mu   = quad_select->SelectFinalQuadruplet(sel_quads,Quadruplet::FourMuon          );
  Quadruplet* final_quad_2e2mu = quad_select->SelectFinalQuadruplet(sel_quads,Quadruplet::TwoElectronTwoMuon);
  Quadruplet* final_quad_2mu2e = quad_select->SelectFinalQuadruplet(sel_quads,Quadruplet::TwoMuonTwoElectron);
  Quadruplet* final_quad_4e    = quad_select->SelectFinalQuadruplet(sel_quads,Quadruplet::FourElectron      );

  // If cutflow is being run, then only one FinalQuadCuts should be called.
  bool passed_final_cuts_4mu   = !dofourmuon           ? false : quad_select->FinalQuadCuts(final_quad_4mu  );
  bool passed_final_cuts_2e2mu = !dotwomuontwoelectron ? false : quad_select->FinalQuadCuts(final_quad_2e2mu);
  bool passed_final_cuts_2mu2e = !dotwomuontwoelectron ? false : quad_select->FinalQuadCuts(final_quad_2mu2e);
  bool passed_final_cuts_4e    = !dofourelectron       ? false : quad_select->FinalQuadCuts(final_quad_4e   );

  // Resolve which channel to take:
  //  4mu, 2e2mu, 2mu2e, 4e
  Quadruplet* final_quad = 0;
  if      (passed_final_cuts_4mu  ) final_quad = final_quad_4mu  ;
  else if (passed_final_cuts_2e2mu) final_quad = final_quad_2e2mu;
  else if (passed_final_cuts_2mu2e) final_quad = final_quad_2mu2e;
  else if (passed_final_cuts_4e   ) final_quad = final_quad_4e   ;
  // if it didn't pass but we're running a cutflow for a particular channel, 
  // then we still need to fill some cutflow items
  else if (dofourmuon           && !doall                    ) final_quad = final_quad_4mu  ;
  else if (dotwomuontwoelectron && !doall && final_quad_2e2mu) final_quad = final_quad_2e2mu;
  else if (dotwomuontwoelectron && !doall && final_quad_2mu2e) final_quad = final_quad_2mu2e; // wtf
  else if (dofourelectron       && !doall) final_quad = final_quad_4e   ;

  // Do this once here too, in case you're running the full inclusive
  // and not the cutflow
  if (!final_quad){
    m_logger << ::DEBUG << "Final Quadruplet did not pass final cuts" << SLogger::endmsg;
    throw SError( SError::SkipEvent );
  }  

  m_logger << ::DEBUG << "Final quad type: " << final_quad->Type() << SLogger::endmsg;    
  m_logger << ::DEBUG << "Final quad m4l : " << final_quad->M4l() << SLogger::endmsg;    
  m_logger << ::DEBUG << "Final quad m12 : " << final_quad->M12() << SLogger::endmsg;    
  m_logger << ::DEBUG << "Final quad m34 : " << final_quad->M34() << SLogger::endmsg;    
  
  // Calculate weight for final quad before applying cuts
  //
  lepton_sf = 1.0;
  trigger_sf = 1.0;
  lepton_sf_recoid.clear();
  
  if (!is_data()) {
    GET_TOOL(sf_tool, ScaleFactorTool, "ScaleFactorTool");
    m_logger << ::DEBUG << "Lepton SF " << SLogger::endmsg;    
    lepton_sf  = sf_tool->LeptonSF(final_quad, m_event_d3pdobject, lepton_sf_recoid);
    
    m_logger << ::DEBUG << "Trigger SF " << SLogger::endmsg;
    GET_TOOL(trig_select, TriggerSelector, "TriggerSelector");
    if (trig_select->PassSingleLeptonTriggers( m_trigger_d3pdobject )) {
      trigger_sf = sf_tool->TriggerSF(final_quad, m_event_d3pdobject);
    }
  }

  evt_weight *= (DoLeptonSF ? lepton_sf : 1.0);
  evt_weight *= (DoTriggerSF ? trigger_sf : 1.0);

  m_logger << ::DEBUG << "Final cutflow: " << SLogger::endmsg;    

  CutFlow("z1_mass   ",quad_select->GetEvent_z1_mass(),  true,evt_weight);
  CutFlow("z2_mass   ",quad_select->GetEvent_z2_mass(),  true,evt_weight);
  CutFlow("deltaR    ",quad_select->GetEvent_deltaR(),   true,evt_weight);
  CutFlow("jpsi      ",quad_select->GetEvent_jpsi(),	 true,evt_weight);
  CutFlow("track_iso ",quad_select->GetEvent_track_iso(),true,evt_weight);
  CutFlow("calo_iso  ",quad_select->GetEvent_calo_iso(), true,evt_weight);
  CutFlow("d0_sig    ",quad_select->GetEvent_d0_sig(),   true,evt_weight);
  //CutFlow("Blind_Region",quad_select->GetEvent_outside_blind(),true,evt_weight);
  
  if ( quad_select->IsBlinded(final_quad) ) {
    m_logger << ::DEBUG << "Final Quadruplet blinded." << SLogger::endmsg;
    throw SError( SError::SkipEvent );
  }
  
  //***************************************************************
  //Event passes!  Now, do whatever with selected quadruplet
   //***************************************************************

  //categories variables 
  VBF_discriminant  = m_CategoriesDiscriminantTool->Get_VBFDiscriminant_Output();
  HadVH_discriminant = m_CategoriesDiscriminantTool->Get_HadVHDiscriminant_Output();

  if(n_jets >= 2 && m_jj > 130000) {    
    cf_vbf++;
    evt_category = 1;
  } else if(n_jets >= 2 && m_jj > 40000 && m_jj < 130000 && m_CategoriesDiscriminantTool->Pass_HadVHDiscriminant()) {
    cf_vh_hadronic++;
    evt_category = 2;
  } else if( el_select->NumberAdditionalElectrons(final_quad, sel_electrons) + mu_select->NumberAdditionalMuons(final_quad, sel_muons) > 0) {
    cf_vh_leptonic++;   
    evt_category = 3;
  } else {
    cf_ggf++;
    evt_category = 0;
  }  
  //calculate jet variables for differential measurement
  jet_select->SelectJets(sel_jets_fid, m_jet_d3pdobject, mu, n_verts2, JetSelector::HSG1, false); 
  jet_select->RemoveElectronJetOverlap(sel_electrons, sel_jets_fid, JetSelector::HSG1, false);

  n_jets_fid = sel_jets_fid.size();
  pt_leadingjet_fid     = n_jets_fid >= 1 ? sel_jets_fid[0]->Pt()  : 0.;
  eta_leadingjet_fid    = n_jets_fid >= 1 ? sel_jets_fid[0]->Eta() : 0.;

  if (!is_data()){
    n_jets_fid_syst.clear();
    pt_leadingjet_fid_syst.clear();
    jet_select->JetSystematics(n_jets_fid_syst, pt_leadingjet_fid_syst, m_jet_d3pdobject, sel_electrons, mu, n_verts2,m_event_d3pdobject->EventNumber(), JetSelector::HSG1);
  }
  
  //Quadruplet kinematics
  //save indices of selected leptons so quad may be reconstructed later
  lepton_type.clear();
  lepton_index.clear();
  lepton_pt.clear();
  lepton_eta.clear();
  lepton_phi.clear();
  lepton_m.clear();
  lepton_cov_mom.clear();
  lepton_pt_id.clear();
  lepton_eta_id.clear();
  lepton_phi_id.clear();

  final_quad->LeptonType(lepton_type);
  final_quad->LeptonIndex(lepton_index);

  final_quad->LeptonPt(lepton_pt);
  final_quad->LeptonEta(lepton_eta);
  final_quad->LeptonPhi(lepton_phi);
  final_quad->LeptonM(lepton_m);

  final_quad->LeptonCovMom(lepton_cov_mom);

  final_quad->LeptonIDPt(lepton_pt_id);
  final_quad->LeptonIDEta(lepton_eta_id);
  final_quad->LeptonIDPhi(lepton_phi_id);

  quad_type = final_quad->Type();

  //save lepton isolation values
  lepton_trk_iso20.clear();
  lepton_trk_iso30.clear();
  lepton_trk_iso40.clear();
  
  lepton_calo_iso20.clear();
  lepton_calo_iso30.clear();
  lepton_calo_iso40.clear();

  final_quad->LeptonTrkIsolation(lepton_trk_iso20, 20, 20);  
  final_quad->LeptonTrkIsolation(lepton_trk_iso30, 30, 30);  
  final_quad->LeptonTrkIsolation(lepton_trk_iso40, 40, 40);  

  final_quad->LeptonCaloIsolation(lepton_calo_iso20, !is_data(), 20, 20, 18);  
  final_quad->LeptonCaloIsolation(lepton_calo_iso30, !is_data(), 30, 30, 28);  
  final_quad->LeptonCaloIsolation(lepton_calo_iso40, !is_data(), 40, 40, 38);  
 
  //save d0 significance
  lepton_d0_significance.clear();
 
  final_quad->LeptonD0Significance(lepton_d0_significance, !is_data());

  lepton_dR_jet.clear();

  final_quad->LeptondRJet(lepton_dR_jet, sel_jets);
  
  //save isem decisions
  lepton_passML.clear();
  lepton_passML_HCP.clear();
  lepton_passML_Relaxed.clear();
  lepton_passLikelihood.clear();
  lepton_passLooseRelaxedLikelihood.clear();
  lepton_passVeryLooseLikelihood.clear();
  lepton_passLooseLikelihood.clear();
  lepton_passLooseBLPixLikelihood.clear();
  lepton_passMediumLikelihood.clear();

  lepton_passLooseBLPixLowLikelihood.clear();
  lepton_passLooseBLPixMedLikelihood.clear();
  lepton_passLooseBLPixHighLikelihood.clear();

  quad_passML = id->passML(lepton_passML,final_quad,"");
  quad_passML_HCP = id->passML_HCP(lepton_passML_HCP,final_quad,"");
  quad_passML_Relaxed = id->passML(lepton_passML_Relaxed,final_quad,"Relaxed");
  quad_passLikelihood = id->passLikelihood(lepton_passLikelihood,final_quad,"Loose_PostHCP",n_verts2);
  quad_passLooseRelaxedLikelihood = id->passLikelihood(lepton_passLooseRelaxedLikelihood,final_quad,LikeEnum::LooseRelaxed,n_verts2);
  quad_passVeryLooseLikelihood = id->passLikelihood(lepton_passVeryLooseLikelihood,final_quad,LikeEnum::VeryLoose,n_verts2);
  quad_passLooseLikelihood = id->passLikelihood(lepton_passLooseLikelihood,final_quad,LikeEnum::Loose,n_verts2);
  //quad_passLooseBLPixLikelihood = id->passLikelihood(lepton_passLooseBLPixLi/kelihood,final_quad,LikeEnum::Loose_BL_Pix,n_verts2);
  quad_passMediumLikelihood = id->passLikelihood(lepton_passMediumLikelihood,final_quad,LikeEnum::Medium,n_verts2);
  
//   quad_passLooseBLPixLowLikelihood = id->passLikelihood(lepton_passLooseBLPixLowLikelihood,final_quad,LLikeEnum::Loose_BL_PixLow,n_verts2);
//   quad_passLooseBLPixMedLikelihood = id->passLikelihood(lepton_passLooseBLPixMedLikelihood,final_quad,LLikeEnum::Loose_BL_PixMed,n_verts2);
//   quad_passLooseBLPixHighLikelihood = id->passLikelihood(lepton_passLooseBLPixHighLikelihood,final_quad,LLikeEnum::Loose_BL_PixHigh,n_verts2);

  quad_passTrkIso = quad_select->TrkIsolationCut(final_quad);
  quad_passCaloIso = quad_select->CaloIsolationCut(final_quad);
  
  quad_hasStandaloneMuon = (final_quad->n_StandAloneMuons() > 0);
  quad_hasCaloMuon = (final_quad->n_CaloTagMuons() > 0);
  if (is_data()){
    m_logger << ALWAYS << "Found ZZ Candidate! Run: "<<m_event_d3pdobject->RunNumber() << " Event Number: "<<m_event_d3pdobject->EventNumber()  << SLogger::endmsg;  
    m_logger << ALWAYS << "Type\tM4l\tM12\tM34" << SLogger::endmsg;  
    m_logger << ALWAYS << final_quad->Type() <<"\t"<<final_quad->M4l()<<"\t"<<final_quad->M12() <<"\t"<<final_quad->M34() << SLogger::endmsg;  
  }


  //calculate weight systematics
  lepton_sf_ElectronRecoLow    = 1.0;
  lepton_sf_ElectronRecoHigh   = 1.0;
  lepton_sf_ElectronIDLow      = 1.0;
  lepton_sf_ElectronIDStatHigh = 1.0;
  lepton_sf_ElectronStat15     = 1.0;
  lepton_sf_ElectronStat10     = 1.0;
  lepton_sf_ElectronStat7      = 1.0;
  lepton_sf_MuonSyst = 1.0;
  trigger_sf_ElectronSyst = 1.0;
  trigger_sf_MuonSyst = 1.0;
  isolationip_sf_ElectronSyst = 1.0;
  qcd_scale_weights.clear();
  pdf_weights.clear();

  if (!is_data()) {
    GET_TOOL(sf_tool, ScaleFactorTool, "ScaleFactorTool");
    m_logger << ::DEBUG << "Lepton SF Systematics" << SLogger::endmsg;    
    lepton_sf_ElectronRecoLow     = sf_tool->LeptonSF(final_quad, m_event_d3pdobject, ScaleFactorTool::ElectronRecoLow);
    lepton_sf_ElectronRecoHigh    = sf_tool->LeptonSF(final_quad, m_event_d3pdobject, ScaleFactorTool::ElectronRecoHigh);
    lepton_sf_ElectronIDLow  	  = sf_tool->LeptonSF(final_quad, m_event_d3pdobject, ScaleFactorTool::ElectronIDLow);
    lepton_sf_ElectronIDStatHigh  = sf_tool->LeptonSF(final_quad, m_event_d3pdobject, ScaleFactorTool::ElectronIDStatHigh);
    lepton_sf_ElectronStat15 	  = sf_tool->LeptonSF(final_quad, m_event_d3pdobject, ScaleFactorTool::ElectronStat15);
    lepton_sf_ElectronStat10 	  = sf_tool->LeptonSF(final_quad, m_event_d3pdobject, ScaleFactorTool::ElectronStat10);
    lepton_sf_ElectronStat7	  = sf_tool->LeptonSF(final_quad, m_event_d3pdobject, ScaleFactorTool::ElectronStat7);
    
    lepton_sf_MuonSyst      = sf_tool->LeptonSF(final_quad, m_event_d3pdobject, ScaleFactorTool::MuonIDReco);

    m_logger << ::DEBUG << "Trigger SF Systematics" << SLogger::endmsg;
    GET_TOOL(trig_select, TriggerSelector, "TriggerSelector");
    if (trig_select->PassSingleLeptonTriggers( m_trigger_d3pdobject )) {
      trigger_sf_ElectronSyst = sf_tool->TriggerSF(final_quad, m_event_d3pdobject, ScaleFactorTool::ElectronTrigger);
      trigger_sf_MuonSyst = sf_tool->TriggerSF(final_quad, m_event_d3pdobject, ScaleFactorTool::MuonTrigger);
    }

    quad_TriggerBitword = trig_select->FillTriggerBitword(final_quad,m_trigger_d3pdobject);
    
    m_logger << ::DEBUG << "Isolation SF " << SLogger::endmsg;
    isolationip_sf_ElectronSyst = sf_tool->IsolationIPSF(final_quad);
    
    m_logger << ::DEBUG << "mcevt_reweight SF " << SLogger::endmsg;
    mc_event_reweight = sf_tool->MCReweightSF(m_mcevt_d3pdobject, m_truth_d3pdobject );

    m_logger << ::DEBUG << "qcd scale weights " << SLogger::endmsg;
    sf_tool->QCDWeights(qcd_scale_weights, m_mcevt_d3pdobject, m_truth_d3pdobject );

    m_logger << ::DEBUG << "pdf weights " << SLogger::endmsg;
    sf_tool->PDFWeights(pdf_weights, m_mcevt_d3pdobject, m_truth_d3pdobject );

 }
  
  //evt_weight = mc_event_weight*(DoLeptonSF ? lepton_sf : 1.0)*(DoTriggerSF ? trigger_sf : 1.0)*(DoPileupSF ? pileup_sf : 1.0)*(DoVertexSF ? vertex_sf : 1.0);
  
  cf_weighted_final += evt_weight;
  
  //save various quad variables
  m_4l = final_quad->M4l();
  m_12 = final_quad->M12();
  m_34 = final_quad->M34();
  
  pt_4l = final_quad->Pt4l();
  pt_Z1 = final_quad->PtZ1();
  pt_Z2 = final_quad->PtZ2();
    
  GET_TOOL(fsrtool, FsrSelector, "FsrSelector");
  fsrtool->SelectFsr(final_quad, m_electron_d3pdobject, m_photon_d3pdobject, m_event_d3pdobject);
  
  m_4l_fsr = final_quad->M4l_fsr();
  m_12_fsr = final_quad->M12_fsr();
  m_34_fsr = final_quad->M34_fsr();
  
  pt_4l_fsr = final_quad->Pt4l_fsr();
  pt_Z1_fsr = final_quad->PtZ1_fsr();
  pt_Z2_fsr = final_quad->PtZ2_fsr();

  GET_TOOL(masstool, HiggsMassTool, "HiggsMassTool");    
  masstool->calculateConstrainedMass(final_quad);   

  m_4l_constrained =  final_quad->M4l_constrained();
  m_12_constrained =  final_quad->M12_constrained();
  m_34_constrained =  final_quad->M34_constrained();

  pt_4l_constrained = final_quad->Pt4l_constrained();
  pt_Z1_constrained = final_quad->PtZ1_constrained();
  pt_Z2_constrained = final_quad->PtZ2_constrained();

  y_4l_unconstrained = final_quad->Y4l_unconstrained();
  y_4l_constrained   = final_quad->Y4l_constrained();
  y_4l_fsr	     = final_quad->Y4l_fsr();
   
  m_4l_err             = final_quad->M4lErr();
  m_4l_err_fsr         = final_quad->M4lErr_fsr();
  m_4l_err_constrained = final_quad->M4lErr_constrained();
  
  m_4l_id = final_quad->M4l_ID();

  eta_4l              = final_quad->Eta4l_unconstrained();
  eta_4l_constrained  = final_quad->Eta4l_constrained();
  eta_4l_fsr          = final_quad->Eta4l_fsr();
 
  final_quad->getElicityAngles( &cthstr, &phi1, &cth1, &cth2, &phi );

  TLorentzVector quad_tlv;
  quad_tlv.SetPtEtaPhiM( pt_4l, eta_4l, phi, m_4l );
  double quad_e = sqrt(pow(quad_tlv.P(),2) + pow(125000,2));
  y_4l_unconstrained_mH = 0.5*log( (quad_e + quad_tlv.Pz()) / (quad_e - quad_tlv.Pz()));
  //if (y_4l_unconstrained_mH != quad_tlv.Rapidity()){
  //  m_logger << ::DEBUG << "rapdity problem: "<<quad_tlv.Rapidity()<< " " <<y_4l_unconstrained_mH << SLogger::endmsg;  
  //}
    
  
  TLorentzVector quad_tlv_mH;
  //quad_tlv_mH.SetPtEtaPhiM( pt_4l, eta_4l, phi, 125000 /*MeV*/ );
  //y_4l_unconstrained_mH = quad_tlv_mH.Rapidity();

  //quad_tlv_mH.SetPtEtaPhiM( pt_4l*125000/m_4l, eta_4l, phi, 125000 /*MeV*/ );
  //y_4l_unconstrained_mH = quad_tlv_mH.Rapidity();
  
  quad_tlv_mH.SetPtEtaPhiM( pt_4l, eta_4l, phi, m_4l );
  quad_tlv_mH *= 125000/m_4l;
  //y_4l_unconstrained_mH = quad_tlv_mH.Rapidity();
  if (quad_tlv_mH.M() != 125000){
    m_logger << ::DEBUG << "mass problem: "<<quad_tlv_mH.M() << SLogger::endmsg;  
  }
  
  
  m_Z1_truth = 0;
  m_Z2_truth = 0;
  pt_Z1_truth = 0;
  pt_Z2_truth = 0;

  m_4l_truth = 0;    
  m_l12_truth = 0;    
  m_l34_truth = 0;    
  pt_4l_truth = 0;
  pt_l12_truth = 0;
  pt_l34_truth = 0;

  m4l_truth_paired_bare = 0;
  m12_truth_paired_bare = 0;
  m34_truth_paired_bare = 0;

  m4l_truth_paired_dressed = 0;
  m12_truth_paired_dressed = 0;
  m34_truth_paired_dressed = 0;
	 
  m4l_truth_matched_bare = 0;
  m12_truth_matched_bare = 0;
  m34_truth_matched_bare = 0;

  m4l_truth_matched_dressed = 0;
  m12_truth_matched_dressed = 0;
  m34_truth_matched_dressed = 0;

  lepton_pt_truth_born.clear();
  lepton_eta_truth_born.clear();
  lepton_phi_truth_born.clear();
  lepton_m_truth_born.clear();

  lepton_pt_truth_paired_bare.clear();
  lepton_eta_truth_paired_bare.clear();
  lepton_phi_truth_paired_bare.clear();
  lepton_m_truth_paired_bare.clear();

  lepton_pt_truth_paired_dressed.clear();
  lepton_eta_truth_paired_dressed.clear();
  lepton_phi_truth_paired_dressed.clear();
  lepton_m_truth_paired_dressed.clear();

  lepton_pt_truth_matched_bare.clear();
  lepton_eta_truth_matched_bare.clear();
  lepton_phi_truth_matched_bare.clear();
  lepton_m_truth_matched_bare.clear();

  lepton_pt_truth_matched_dressed.clear();
  lepton_eta_truth_matched_dressed.clear();
  lepton_phi_truth_matched_dressed.clear();
  lepton_m_truth_matched_dressed.clear();

  lepton_pt_truth_matched_born.clear();
  lepton_eta_truth_matched_born.clear();
  lepton_phi_truth_matched_born.clear();
  lepton_m_truth_matched_born.clear();

  weight_pt_ZZPdfUp   = 1.0;
  weight_pt_ZZPdfDn   = 1.0;
  weight_pt_ZZScaleUp = 1.0;
  weight_pt_ZZScaleDn = 1.0;
  weight_rapidity_ZZPdfUp   = 1.0;
  weight_rapidity_ZZPdfDn   = 1.0;
  weight_rapidity_ZZScaleUp = 1.0;
  weight_rapidity_ZZScaleDn = 1.0;
  weight_m34_ZZPdfUp   = 1.0;
  weight_m34_ZZPdfDn   = 1.0;
  weight_m34_ZZScaleUp = 1.0;
  weight_m34_ZZScaleDn = 1.0;
  weight_costhetastar_ZZPdfUp   = 1.0;
  weight_costhetastar_ZZPdfDn   = 1.0;
  weight_costhetastar_ZZScaleUp = 1.0;
  weight_costhetastar_ZZScaleDn = 1.0;

  if (!is_data()){
     
    m_logger << ::DEBUG << "Retrieving truth tool "<< SLogger::endmsg;  
    GET_TOOL(truth_select, TruthSelector, "TruthSelector");

    std::vector<TruthParticle*> tparts;    
    truth_select->DressLeptons(m_truth_d3pdobject, tparts);
    
    //get truth quad with no pairing done
    std::vector<TruthParticle*> born_truth_quad;
    truth_select->GetBornTruthQuad(tparts, born_truth_quad);    
    for (unsigned int i = 0; i < 4; ++i){
       if (born_truth_quad.size() == 4){
	  lepton_pt_truth_born.push_back(born_truth_quad[i]->pt());
	  lepton_eta_truth_born.push_back(born_truth_quad[i]->eta());
	  lepton_phi_truth_born.push_back(born_truth_quad[i]->phi());
	  lepton_m_truth_born.push_back(born_truth_quad[i]->m());
       } else {
	  lepton_pt_truth_born.push_back(0);
	  lepton_eta_truth_born.push_back(0);
	  lepton_phi_truth_born.push_back(0);
	  lepton_m_truth_born.push_back(0);       
       }            
    }     
    
    m_logger << ::DEBUG << "Classifying truth event "<< SLogger::endmsg;          
    event_type_truth = truth_select->ClassifyQuad( born_truth_quad );
    
    //pair the born leptons   
    std::vector<TruthParticle*> born_paired_truth_quad;
    truth_select->PairLeptons(born_truth_quad, born_paired_truth_quad);
    
    if (born_paired_truth_quad.size() == 4) {
       double pt4l_born_paired_truth = (born_paired_truth_quad[0]->TLV() + born_paired_truth_quad[1]->TLV() + born_paired_truth_quad[2]->TLV() + born_paired_truth_quad[3]->TLV()).Pt();
       double y4l_born_paired_truth = (born_paired_truth_quad[0]->TLV() + born_paired_truth_quad[1]->TLV() + born_paired_truth_quad[2]->TLV() + born_paired_truth_quad[3]->TLV()).Rapidity();
       double m34_born_paired_truth = (born_paired_truth_quad[2]->TLV() + born_paired_truth_quad[3]->TLV()).M();
       
       float csthstr_born_paired_truth, phi1_born_paired_truth, csth1_born_paired_truth, csth2_born_paired_truth, phi_born_paired_truth;       
       GetElicityAngles( born_paired_truth_quad[1]->TLV(), born_paired_truth_quad[0]->TLV(), born_paired_truth_quad[3]->TLV(), born_paired_truth_quad[2]->TLV(), &csthstr_born_paired_truth, &phi1_born_paired_truth, &csth1_born_paired_truth, &csth2_born_paired_truth, &phi_born_paired_truth);
 
       //weight_pt_ZZPdfUp   = m_ZZPtSystTool->RewSys(ZZPtSystTool::PT, pt4l_born_paired_truth, event_type_truth, "pdf",ZZPtSystTool::PLUS1SIGMA);
       //weight_pt_ZZPdfDn   = m_ZZPtSystTool->RewSys(ZZPtSystTool::PT, pt4l_born_paired_truth, event_type_truth, "pdf",ZZPtSystTool::MINUS1SIGMA);    
       //weight_pt_ZZScaleUp = m_ZZPtSystTool->RewSys(ZZPtSystTool::PT, pt4l_born_paired_truth, event_type_truth, "scale",ZZPtSystTool::PLUS1SIGMA);
       //weight_pt_ZZScaleDn = m_ZZPtSystTool->RewSys(ZZPtSystTool::PT, pt4l_born_paired_truth, event_type_truth, "scale",ZZPtSystTool::MINUS1SIGMA);

       //weight_rapidity_ZZPdfUp   = m_ZZPtSystTool->RewSys(ZZPtSystTool::RAPIDITY, y4l_born_paired_truth, event_type_truth, "pdf",ZZPtSystTool::PLUS1SIGMA);
       //weight_rapidity_ZZPdfDn   = m_ZZPtSystTool->RewSys(ZZPtSystTool::RAPIDITY, y4l_born_paired_truth, event_type_truth, "pdf",ZZPtSystTool::MINUS1SIGMA);    
       //weight_rapidity_ZZScaleUp = m_ZZPtSystTool->RewSys(ZZPtSystTool::RAPIDITY, y4l_born_paired_truth, event_type_truth, "scale",ZZPtSystTool::PLUS1SIGMA);
       //weight_rapidity_ZZScaleDn = m_ZZPtSystTool->RewSys(ZZPtSystTool::RAPIDITY, y4l_born_paired_truth, event_type_truth, "scale",ZZPtSystTool::MINUS1SIGMA);

       //weight_m34_ZZPdfUp   = m_ZZPtSystTool->RewSys(ZZPtSystTool::M34, m34_born_paired_truth, event_type_truth, "pdf",ZZPtSystTool::PLUS1SIGMA);
       //weight_m34_ZZPdfDn   = m_ZZPtSystTool->RewSys(ZZPtSystTool::M34, m34_born_paired_truth, event_type_truth, "pdf",ZZPtSystTool::MINUS1SIGMA);    
       //weight_m34_ZZScaleUp = m_ZZPtSystTool->RewSys(ZZPtSystTool::M34, m34_born_paired_truth, event_type_truth, "scale",ZZPtSystTool::PLUS1SIGMA);
       //weight_m34_ZZScaleDn = m_ZZPtSystTool->RewSys(ZZPtSystTool::M34, m34_born_paired_truth, event_type_truth, "scale",ZZPtSystTool::MINUS1SIGMA);

       //weight_costhetastar_ZZPdfUp   = m_ZZPtSystTool->RewSys(ZZPtSystTool::COSTHETASTAR, csthstr_born_paired_truth, event_type_truth, "pdf",ZZPtSystTool::PLUS1SIGMA);
       //weight_costhetastar_ZZPdfDn   = m_ZZPtSystTool->RewSys(ZZPtSystTool::COSTHETASTAR, csthstr_born_paired_truth, event_type_truth, "pdf",ZZPtSystTool::MINUS1SIGMA);    
       //weight_costhetastar_ZZScaleUp = m_ZZPtSystTool->RewSys(ZZPtSystTool::COSTHETASTAR, csthstr_born_paired_truth, event_type_truth, "scale",ZZPtSystTool::PLUS1SIGMA);
       //weight_costhetastar_ZZScaleDn = m_ZZPtSystTool->RewSys(ZZPtSystTool::COSTHETASTAR, csthstr_born_paired_truth, event_type_truth, "scale",ZZPtSystTool::MINUS1SIGMA);
    }
   
    std::vector<TruthParticle*> paired_truth_quad;
    truth_select->GetPairedTruthQuad(tparts, paired_truth_quad);    
    if (paired_truth_quad.size() == 4){

      m4l_truth_paired_bare = (paired_truth_quad[0]->TLV() + paired_truth_quad[1]->TLV() + paired_truth_quad[2]->TLV() + paired_truth_quad[3]->TLV()).M();
      m12_truth_paired_bare = (paired_truth_quad[0]->TLV() + paired_truth_quad[1]->TLV()).M();
      m34_truth_paired_bare = (paired_truth_quad[2]->TLV() + paired_truth_quad[3]->TLV()).M(); 

      //would pairing be different with dressed leptons? Assume no for now... (small effect)
      m4l_truth_paired_dressed = (paired_truth_quad[0]->Dressed_TLV() + paired_truth_quad[1]->Dressed_TLV() + paired_truth_quad[2]->Dressed_TLV() + paired_truth_quad[3]->Dressed_TLV()).M();
      m12_truth_paired_dressed = (paired_truth_quad[0]->Dressed_TLV() + paired_truth_quad[1]->Dressed_TLV()).M();
      m34_truth_paired_dressed = (paired_truth_quad[2]->Dressed_TLV() + paired_truth_quad[3]->Dressed_TLV()).M();       

      for (unsigned int i = 0; i <4; ++i){
	  lepton_pt_truth_paired_bare.push_back(paired_truth_quad[i]->pt());
	  lepton_eta_truth_paired_bare.push_back(paired_truth_quad[i]->eta());
	  lepton_phi_truth_paired_bare.push_back(paired_truth_quad[i]->phi());
	  lepton_m_truth_paired_bare.push_back(paired_truth_quad[i]->m());

	  lepton_pt_truth_paired_dressed.push_back(paired_truth_quad[i]->Dressed_TLV().Pt());
	  lepton_eta_truth_paired_dressed.push_back(paired_truth_quad[i]->Dressed_TLV().Eta());
	  lepton_phi_truth_paired_dressed.push_back(paired_truth_quad[i]->Dressed_TLV().Phi());
	  lepton_m_truth_paired_dressed.push_back(paired_truth_quad[i]->Dressed_TLV().M());
      }            
    } else {
       for (unsigned int i = 0; i <4; ++i){
	  lepton_pt_truth_paired_bare.push_back(0);
	  lepton_eta_truth_paired_bare.push_back(0);
	  lepton_phi_truth_paired_bare.push_back(0);
	  lepton_m_truth_paired_bare.push_back(0);

	  lepton_pt_truth_paired_dressed.push_back(0);
	  lepton_eta_truth_paired_dressed.push_back(0);
	  lepton_phi_truth_paired_dressed.push_back(0);
	  lepton_m_truth_paired_dressed.push_back(0);
       }                
    } 
    
    std::vector<TruthParticle*> matched_truth_quad;
    truth_select->GetMatchedTruthQuad( final_quad, tparts, matched_truth_quad );

    int n_matched = 0;
    for (unsigned int i = 0; i <4; ++i){
        if(matched_truth_quad[i]) n_matched++;
      
	lepton_pt_truth_matched_bare.push_back( matched_truth_quad[i] ? matched_truth_quad[i]->pt()  : 0);
	lepton_eta_truth_matched_bare.push_back(matched_truth_quad[i] ? matched_truth_quad[i]->eta() : 0);
	lepton_phi_truth_matched_bare.push_back(matched_truth_quad[i] ? matched_truth_quad[i]->phi() : 0);
	lepton_m_truth_matched_bare.push_back(  matched_truth_quad[i] ? matched_truth_quad[i]->m()   : 0);

	lepton_pt_truth_matched_dressed.push_back( matched_truth_quad[i] ? matched_truth_quad[i]->Dressed_TLV().Pt()  : 0);
	lepton_eta_truth_matched_dressed.push_back(matched_truth_quad[i] ? matched_truth_quad[i]->Dressed_TLV().Eta() : 0);
	lepton_phi_truth_matched_dressed.push_back(matched_truth_quad[i] ? matched_truth_quad[i]->Dressed_TLV().Phi() : 0);
	lepton_m_truth_matched_dressed.push_back(  matched_truth_quad[i] ? matched_truth_quad[i]->Dressed_TLV().M()   : 0);
    }            
    if (n_matched == 4){
      m4l_truth_matched_bare = (matched_truth_quad[0]->TLV() + matched_truth_quad[1]->TLV() + matched_truth_quad[2]->TLV() + matched_truth_quad[3]->TLV()).M();
      m12_truth_matched_bare = (matched_truth_quad[0]->TLV() + matched_truth_quad[1]->TLV()).M();
      m34_truth_matched_bare = (matched_truth_quad[2]->TLV() + matched_truth_quad[3]->TLV()).M(); 

      //would pairing be different with dressed leptons? Assume no for now... (small effect)
      m4l_truth_matched_dressed = (matched_truth_quad[0]->Dressed_TLV() + matched_truth_quad[1]->Dressed_TLV() + matched_truth_quad[2]->Dressed_TLV() + matched_truth_quad[3]->Dressed_TLV()).M();
      m12_truth_matched_dressed = (matched_truth_quad[0]->Dressed_TLV() + matched_truth_quad[1]->Dressed_TLV()).M();
      m34_truth_matched_dressed = (matched_truth_quad[2]->Dressed_TLV() + matched_truth_quad[3]->Dressed_TLV()).M();       
    }
    
    m_logger << ::DEBUG << "Checking mispairing "<< SLogger::endmsg;          
    mispaired = truth_select->Mispaired( matched_truth_quad );
    reco_higgs_quad = truth_select->HiggsQuad( tparts, matched_truth_quad );    
    
    std::vector<TruthParticle*> matched_born_truth_quad;
    truth_select->GetMatchedBornTruthQuad( final_quad, tparts, matched_born_truth_quad );

    n_matched = 0;
    for (unsigned int i = 0; i <4; ++i){
        if(matched_born_truth_quad[i]) n_matched++;

	lepton_pt_truth_matched_born.push_back( matched_born_truth_quad[i] ? matched_born_truth_quad[i]->pt()  : 0);
	lepton_eta_truth_matched_born.push_back(matched_born_truth_quad[i] ? matched_born_truth_quad[i]->eta() : 0);
	lepton_phi_truth_matched_born.push_back(matched_born_truth_quad[i] ? matched_born_truth_quad[i]->phi() : 0);
	lepton_m_truth_matched_born.push_back(  matched_born_truth_quad[i] ? matched_born_truth_quad[i]->m()   : 0);
    }            
    if(n_matched==4){
      m4l_truth_matched_born = (matched_born_truth_quad[0]->TLV() + matched_born_truth_quad[1]->TLV() + matched_born_truth_quad[2]->TLV() + matched_born_truth_quad[3]->TLV()).M();
      m12_truth_matched_born = (matched_born_truth_quad[0]->TLV() + matched_born_truth_quad[1]->TLV()).M();
      m34_truth_matched_born = (matched_born_truth_quad[2]->TLV() + matched_born_truth_quad[3]->TLV()).M(); 
    }

    //clean up
    for (unsigned int i = 0; i <tparts.size(); i++) delete tparts[i];
  }  

  
  // ------------------------------------------------------------
  // ------------------- Managing outputs -----------------------

  // if the event passes, write the selected event to output tree
  // - events are automatically written, just need to manage the outputs here

   // ----------------------------------------------------------
  // ---------------- Enabling writing ------------------------



  if (m_4l_constrained > 120000 && m_4l_constrained < 130000){
    cf_signal_final++;
    cf_signal_weighted_final += evt_weight;
  }


  // make sure to read all active branches of objects we want to write
  m_event_d3pdobject->ReadAllActive();
  m_trigger_d3pdobject->ReadAllActive();//do we want to save all trigger info??
  m_vxp_d3pdobject->ReadAllActive();
  
  m_electron_d3pdobject->ReadAllActive();
  m_muon_staco_d3pdobject->ReadAllActive();
  m_truth_d3pdobject->ReadAllActive();

  m_photon_d3pdobject->ReadAllActive();
  m_met_d3pdobject->ReadAllActive();

  if (m_debugEvent != 0){
    if (m_event_d3pdobject->EventNumber() == (unsigned int)m_debugEvent && m_event_d3pdobject->RunNumber() == (unsigned int)m_debugRun) {    
      m_logger << ALWAYS << "Found debug Event: Ending Processing!" << SLogger::endmsg;
      throw SError( SError::StopExecution );
    }
  }
    
 return;

}
