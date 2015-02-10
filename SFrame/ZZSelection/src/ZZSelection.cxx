// $Id: ZZSelection.cxx 18698 2012-10-05 10:53:57Z stahlman $

// Local include(s):
#include "../include/ZZ_Selection.h"
#include "TH2.h"
#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "MuonStaco.h"
#include "ParticleElementBuilder.h"

const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( ZZ_Selection );

ZZ_Selection::ZZ_Selection()
  : CycleBase(), 
    m_doGRL ( true ),
    isMC( false ),
    m_doSmear ( false ),
    m_doTrig ( true ),
    m_doVert ( true ),
    m_doZ ( false ),
    m_doZWindow( false ),
    cf_preselect( "preselect", this ),
    cf_grl( "grl", this ),
    cf_trigger( "trigger", this ),
    cf_vertex( "vertex", this ),
    cf_jetcleaning( "jetcleaning", this ),
    cf_two_comb_mu( "two_comb_mu", this ),
    cf_eta( "eta", this ),
    cf_pt( "pt", this ),
    cf_id_hits( "id_hits", this ),
    cf_MS_hits( "MS_hits", this ),
    cf_d0( "d0", this ),
    cf_z0( "z0", this ),
    cf_isolation( "isolation", this ),
    cf_charge( "charge", this ),
    cf_mass_mumu( "mass_mumu", this ),
    cf_weight( "weight", this ),
    pileupEventWeight( 1.0 ),
    zPtEventWeight( 1.0 ),
    evt_actualIntPerXing(0.0),
    evt_averageIntPerXing(0.0),
    n_vertices(0),
    n_jetspt20(0),
    run_number(0),
    evt_number(0),
    lb_number(0),
    bcid(0),
    bunch_config_id(0),
    mt(0.0),
    m_ll(0.0),
    pt_ll(0.0),
    phi_ll(0.0),
    eta_ll(0.0),
    l_pt(0.0),
    l_phi(0.0),
    l_eta(0.0),
    l_d0(0.0),
    l_z0(0.0),
    l_eloss(0.0),
    sl_pt(0.0),
    sl_phi(0.0),
    sl_eta(0.0),
    sl_d0(0.0),
    sl_z0(0.0),
    sl_eloss(0.0),
    met_lochadtopo_ex(0.0),
    met_lochadtopo_ey(0.0),
    met_lochadtopo_et(0.0),
    met_lochadtopo_phi(0.0),
    met_lochadtopo_sumet(0.0),
    met_reffinal_ex(0.0),
    met_reffinal_ey(0.0),
    met_reffinal_et(0.0),
    met_reffinal_phi(0.0),
    met_reffinal_sumet(0.0),
    met_refgamma_ex(0.0),
    met_refgamma_ey(0.0),
    met_refgamma_et(0.0),
    met_refgamma_phi(0.0),
    met_refgamma_sumet(0.0),
    met_reftau_ex(0.0),
    met_reftau_ey(0.0),
    met_reftau_et(0.0),
    met_reftau_phi(0.0),
    met_reftau_sumet(0.0),
    met_refele_ex(0.0),
    met_refele_ey(0.0),
    met_refele_et(0.0),
    met_refele_phi(0.0),
    met_refele_sumet(0.0),
    met_refjet_ex(0.0),
    met_refjet_ey(0.0),
    met_refjet_et(0.0),
    met_refjet_phi(0.0),
    met_refjet_sumet(0.0),
    met_muonboy_ex(0.0),
    met_muonboy_ey(0.0),
    met_muonboy_et(0.0),
    met_muonboy_phi(0.0),
    met_muonboy_sumet(0.0),
    met_refmuon_ex(0.0),
    met_refmuon_ey(0.0),
    met_refmuon_et(0.0),
    met_refmuon_phi(0.0),
    met_refmuon_sumet(0.0),
    met_cellout_ex(0.0),
    met_cellout_ey(0.0),
    met_cellout_et(0.0),
    met_cellout_phi(0.0),
    met_cellout_sumet(0.0),
    met_cellout_eflow_ex(0.0),
    met_cellout_eflow_ey(0.0),
    met_cellout_eflow_et(0.0),
    met_cellout_eflow_phi(0.0),
    met_cellout_eflow_sumet(0.0),
    met_softjets_ex(0.0),
    met_softjets_ey(0.0),
    met_softjets_et(0.0),
    met_softjets_phi(0.0),
    met_softjets_sumet(0.0),
    met_reffinal_em_ex(0.0),
    met_reffinal_em_ey(0.0),
    met_reffinal_em_et(0.0),
    met_reffinal_em_phi(0.0),
    met_reffinal_em_sumet(0.0),
    met_refgamma_em_ex(0.0),
    met_refgamma_em_ey(0.0),
    met_refgamma_em_et(0.0),
    met_refgamma_em_phi(0.0),
    met_refgamma_em_sumet(0.0),
    met_reftau_em_ex(0.0),
    met_reftau_em_ey(0.0),
    met_reftau_em_et(0.0),
    met_reftau_em_phi(0.0),
    met_reftau_em_sumet(0.0),
    met_refele_em_ex(0.0),
    met_refele_em_ey(0.0),
    met_refele_em_et(0.0),
    met_refele_em_phi(0.0),
    met_refele_em_sumet(0.0),
    met_refjet_em_ex(0.0),
    met_refjet_em_ey(0.0),
    met_refjet_em_et(0.0),
    met_refjet_em_phi(0.0),
    met_refjet_em_sumet(0.0),
//    met_muonboy_em_ex(0.0),
//    met_muonboy_em_ey(0.0),
//    met_muonboy_em_et(0.0),
//    met_muonboy_em_phi(0.0),
//    met_muonboy_em_sumet(0.0),
    met_refmuon_em_ex(0.0),
    met_refmuon_em_ey(0.0),
    met_refmuon_em_et(0.0),
    met_refmuon_em_phi(0.0),
    met_refmuon_em_sumet(0.0),
    met_cellout_em_ex(0.0),
    met_cellout_em_ey(0.0),
    met_cellout_em_et(0.0),
    met_cellout_em_phi(0.0),
    met_cellout_em_sumet(0.0),
    met_softjets_em_ex(0.0),
    met_softjets_em_ey(0.0),
    met_softjets_em_et(0.0),
    met_softjets_em_phi(0.0),
    met_softjets_em_sumet(0.0),
    met_truth_nonint_ex(0.0),
    met_truth_nonint_ey(0.0),
    met_truth_nonint_et(0.0),
    met_truth_nonint_phi(0.0),
    met_truth_nonint_sumet(0.0),

    muon_pt(0.0),
    muon_phi(0.0),
    muon_eta(0.0),
    muon_eloss(0.0),
    muon_pz(0.0)
    /*sMET_calo_ex(0.0),
    sMET_calo_ey(0.0),
    sMET_calo_et(0.0),
    sfinal_met_ex(0.0),
    sfinal_met_ey(0.0),
    sfinal_met_et(0.0),
    smuon_pt(0.0),
    smuon_phi(0.0),
    smuon_eta(0.0),
    smuon_eloss(0.0),
    smuon_pz(0.0)*/
{

   SetLogName( GetName() );
   DeclareProperty( "RecoTreeString", m_recoTreeName );
   DeclareProperty( "TrigTreeString", m_trigTreeName );
   DeclareProperty( "ISMC", isMC );
   DeclareProperty( "DoSmear",m_doSmear );
   DeclareProperty( "DoGRL", m_doGRL );
   //DeclareProperty( "DoLarError", m_doLarError ):
   DeclareProperty( "DoTrigger", m_doTrig );
   DeclareProperty( "DoVertex", m_doVert );
   DeclareProperty( "DoZ", m_doZ );
   DeclareProperty( "DoZWindow", m_doZWindow );

   DeclareProperty( "PuDataRootFileName", m_puDataRootFileName );
   DeclareProperty( "PuMCRootFileName", m_puMCRootFileName );
   DeclareProperty( "PuMCRootHistName", m_puMCRootHistName );
   DeclareProperty( "JetContainer", c_jet_container = "jet_AntiKt4LCTopo_");
   
   
   DeclareProperty("output_event_branches_regex", c_output_event_branches_regex = ".*");
   DeclareProperty("output_mcevt_branches_regex", c_output_mcevt_branches_regex = ".*");
   //DeclareProperty("output_trigger_branches_regex", c_output_trigger_branches_regex = ".*");
   //DeclareProperty("output_trigEFel_branches_regex", c_output_trigEFel_branches_regex = ".*");
   DeclareProperty("output_vxp_branchegs_regex", c_output_vxp_branches_regex = ".*");
   //DeclareProperty("output_electron_branches_regex", c_output_electron_branches_regex = ".*");
   //DeclareProperty("output_photon_branches_regex", c_output_photon_branches_regex = ".*");
   DeclareProperty("output_muon_branches_regex", c_output_muon_branches_regex = ".*");
   DeclareProperty("output_jet_branches_regex", c_output_jet_branches_regex = ".*");
   DeclareProperty("output_met_branches_regex", c_output_met_branches_regex = ".*");
   DeclareProperty("output_truth_branches_regex", c_output_truth_branches_regex = ".*");
   
   //DECLARE_TOOL(GoodRunsListTool, "GoodRunsList");
   //DECLARE_TOOL(PileupReweightingTool, "PileupReweighting");
   //DECLARE_TOOL(PileupReweightingTool, "ScaledMuPileupReweighting1");
   //DECLARE_TOOL(PileupReweightingTool, "ScaledMuPileupReweighting2");
   //DECLARE_TOOL(ZPtReweightingTool, "ZPtReweighting");
   
   //2012 candidates   
   unsigned int mu4_runs[26] = {200926,201494,202668,203195,203258,203277,203353,203432,203456,203524,203602,203636,203745,203779,203876,203934,204026,204071,204073,204153,204153,204158,204240,204416,204564,204564};
   unsigned int mu4_evts[26] = {17712380,26817712,26299894,5763465,59505222,22949094,26647061,46880033,24914034,62321499,80248134,34504484,63994592,46710128,9282788,100600041,87732822,30963264,18405446,22992989,32436165,108769641,52902065,20491680,25416035,149682166};
   double mu4_mass[26]       = {293.33,281.35,385.72,257.11,228.84,193.86,242.89,212.26,187.46,238.78,373.90,340.92,226.89,341.66,333.15,211.18,190.67,263.33,280.49,120.99,583.09,232.01,208.27,292.50,128.90,288.37};

   unsigned int mu2e2_runs[55] = {200987,201113,201113,201138,201190,202798,203027,203195,203228,203258,203353,203432,203523,203636,203636,203739,203876,204153,204158,201113,201257,201257,201289,201556,201556,202798,203258,203335,203353,203353,203524,203636,203680,203719,203745,203745,203876,203876,203934,203934,204071,204073,204153,204240,204240,204265,204416,204474,204474,204265,204474,204474,204564,204564,204668};
   unsigned int mu2e2_evts[55] = {50726675,29045106,34945963,27887257,13200815,43736485,71454016,25217284,15214720,105740575,79978481,20659622,13350735,10916804,69879354,67630085,96963848,33235991,18242755,55604596,21308431,121862343,10043905,6395332,10787809,7203716,114413312,49048571,7225045,28661403,28303221,65210779,10638148,12262192,75039428,90860257,36135200,60324400,70728810,98492930,32311568,38389153,26755807,31409138,151358568,72546153,42212637,56451245,89082513,223273173,131005091,134814016,68230882,198222712,141229289};
   double mu2e2_mass[55]       = {246.59,202.75,259.45,214.73,236.32,161.42,192.31,362.89,235.65,131.14,374.82,447.57,206.21,317.09,433.25,259.58,343.08,194.85,262.56,222.30,189.10,350.82,221.29,178.93,213.01,242.33,186.09,280.69,162.31,202.33,199.92,212.89,176.17,255.68,229.40,312.66,289.56,212.62,150.84,255.64,294.00,192.43,225.82,229.73,195.35,201.66,193.41,269.48,182.60,367.23,232.76,93.53,893.35,218.18,199.10};   
   
   unsigned int e4_runs[23] = {201113,202991,203335,203432,203524,203602,203602,203602,203636,203680,203719,203739,203934,203934,204240,204265,204265,204564,204564,204564,204564,204633,204668};
   unsigned int e4_evts[23] = {36934150,29492591,44927851,58320601,64340754,82614360,99681996,106701658,95484441,44088690,20441551,73042609,89714329,91585470,29054747,11531490,15870479,72798274,76786292,193961472,228171673,4809722,60678687};
   double e4_mass[55]       = {308.80,209.73,209.07,162.70,189.16,124.61,175.08,295.16,403.05,228.74,265.66,221.99,87.38,160.25,196.88,203.04,192.80,144.21,114.24,194.60,305.18,195.17,205.85};

   
   for (int i = 0; i < 26; i++) {
     v_runs.push_back(mu4_runs[i]);
     v_evts.push_back(mu4_evts[i]);   
     v_mass.push_back(mu4_mass[i]);   
   }

   for (int i = 0; i < 43; i++) {
     v_runs.push_back(mu2e2_runs[i]);
     v_evts.push_back(mu2e2_evts[i]);   
     v_mass.push_back(mu2e2_mass[i]);   
   }

   for (int i = 0; i < 14; i++) {
     v_runs.push_back(e4_runs[i]);
     v_evts.push_back(e4_evts[i]);
     v_mass.push_back(e4_mass[i]);   
   
   }

   //2011 candidates   
   unsigned int mu4_runs_11[22] = {182284,182486,182766,183003,183003,183391,183426,183602,184130,186156,187219,189207,189207,189280,189280,189280,189561,189693,190116,190300,190872,191426};
   unsigned int mu4_evts_11[22] = {91584073,33852510,5404925,44433120,121099951,19834577,47756740,282919,194694606,65491657,88203394,79774710,81313827,82801561,128083498,143576946,20659041,10714212,60445481,60554334,52781235,60906769};
   double mu4_mass_11[22]       = {277.7,208.6,243.0,222.2,603.5,204.9,455.3,239.7,182.9,234.4,372.2,250.7,171.9,208.7,220.6,124.6,207.3,209.6,199.8,145.8,264.2,225.5};
   
   unsigned int mu2e2_runs_11[31] = {179710,180636,180710,182747,182796,183407,183426,183462,186399,186877,186877,186923,187014,189242,189483,189561,189719,189781,190046,190300,190343,190878,190878,190975,190975,191138,191150,191150,191190,191218,191428};
   unsigned int mu2e2_evts_11[31] = {25946709,71391739,37143864,63217197,74566644,136901836,50303812,75344317,14250520,12509901,84622334,96974859,105211056,7233912,1021987,105481981,37988693,8619753,8638208,17344710,23439188,50034828,57044890,20471852,62905396,15762515,5742674,45707611,76273161,1072214,25718643};
   double mu2e2_mass_11[31]       = {234.5,242.9,247.3,209.2,124.3,188.9,251.9,486.8,325.1,191.0,123.6,238.7,292.2,158.2,460.1,214.2,314.8,568.1,267.0,321.7,147.5,210.9,200.2,281.4,268.2,199.4,244.1,222.3,218.6,249.7,236.4};   
   
   unsigned int e4_runs_11[15] = {182787,183216,184022,184022,186216,186216,186729,186934,187453,187552,187763,189483,189751,190933,191138};
   unsigned int e4_evts_11[15] = {35518831,75692579,20046902,78541915,10253640,36894463,203362752,65787798,34960141,3744932,83732606,33468656,51800361,99272087,17388332};
   double e4_mass_11[15]       = {196.0,270.3,245.4,496.1,264.4,157.6,200.4,230.7,226.0,331.2,172.0,238.4,184.9,426.2,194.6};  
   
   for (int i = 0; i < 22; i++) {
     v_runs.push_back(mu4_runs_11[i]);
     v_evts.push_back(mu4_evts_11[i]);   
     v_mass.push_back(mu4_mass_11[i]);   
   }

   for (int i = 0; i < 31; i++) {
     v_runs.push_back(mu2e2_runs_11[i]);
     v_evts.push_back(mu2e2_evts_11[i]);   
     v_mass.push_back(mu2e2_mass_11[i]);   
   }

   for (int i = 0; i < 15; i++) {
     v_runs.push_back(e4_runs_11[i]);
     v_evts.push_back(e4_evts_11[i]);   
     v_mass.push_back(e4_mass_11[i]);   
   }

   //mc check
   //v_runs.push_back(195847);
   //v_evts.push_back(44305);	 
   //v_mass.push_back(50);	 
   
   //v_runs.push_back(195847);
   //v_evts.push_back(44307);   

}

ZZ_Selection::~ZZ_Selection() {

}

void ZZ_Selection::BeginCycleImp() throw( SError ) {  
  
  //gRand_Calo = new TRandom3();
  //gRand_Calo->SetSeed(0);

  return;

}

void ZZ_Selection::EndCycleImp() throw( SError ) {

  //delete m_tPileUp;
  //delete gRand_Calo;
   return;

}

void ZZ_Selection::BeginInputDataImp( const SInputData& ) throw( SError ) {


  //Declare variables:  
  DeclareVariable( pileupEventWeight, "pileupEventWeight" );
  DeclareVariable( scaledMuPileupEventWeight1, "scaledMuPileupEventWeight1" );
  DeclareVariable( scaledMuPileupEventWeight2, "scaledMuPileupEventWeight2" );
  DeclareVariable( zPtEventWeight, "zPtEventWeight" );
  DeclareVariable( evt_actualIntPerXing, "evt_actualIntPerXing" );
  DeclareVariable( evt_averageIntPerXing, "evt_averageIntPerXing" );
  DeclareVariable( n_vertices, "n_vertices" );  
  DeclareVariable( n_jetspt20, "n_jetspt20" );  
  DeclareVariable( run_number, "run_number" );
  DeclareVariable( evt_number, "evt_number" );
  DeclareVariable( lb_number, "lb_number" );
  DeclareVariable( bcid, "bcid" );
  DeclareVariable( bunch_config_id, "bunch_config_id" );
  DeclareVariable( mt, "mt" );
  DeclareVariable( m_ll, "m_ll");
  DeclareVariable( m_4l, "m_4l");
  DeclareVariable( m_12, "m_12");
  DeclareVariable( m_34, "m_34");
  DeclareVariable( pt_ll, "pt_ll");
  DeclareVariable( phi_ll, "phi_ll");
  DeclareVariable( eta_ll, "eta_ll");
  DeclareVariable( l_pt, "l_pt");
  DeclareVariable( l_eta, "l_eta");
  DeclareVariable( l_phi, "l_phi");
  DeclareVariable( l_d0, "l_d0");
  DeclareVariable( l_z0, "l_z0");
  DeclareVariable( l_eloss, "l_eloss");
  DeclareVariable( sl_pt, "sl_pt");
  DeclareVariable( sl_eta, "sl_eta");
  DeclareVariable( sl_phi, "sl_phi");
  DeclareVariable( sl_d0, "sl_d0");
  DeclareVariable( sl_z0, "sl_z0");
  DeclareVariable( sl_eloss, "sl_eloss");

  DeclareVariable( met_lochadtopo_ex, "MET_LocHadTopo_ex" );
  DeclareVariable( met_lochadtopo_ey, "MET_LocHadTopo_ey" );
  DeclareVariable( met_lochadtopo_et, "MET_LocHadTopo_et");
  DeclareVariable( met_lochadtopo_phi, "MET_LocHadTopo_phi");
  DeclareVariable( met_lochadtopo_sumet, "MET_LocHadTopo_sumet");
  
  DeclareVariable( met_reffinal_ex, "MET_RefFinal_ex" );
  DeclareVariable( met_reffinal_ey, "MET_RefFinal_ey" );
  DeclareVariable( met_reffinal_et, "MET_RefFinal_et");
  DeclareVariable( met_reffinal_phi, "MET_RefFinal_phi");
  DeclareVariable( met_reffinal_sumet, "MET_RefFinal_sumet");  
  DeclareVariable( met_refgamma_ex, "MET_RefGamma_ex" );
  DeclareVariable( met_refgamma_ey, "MET_RefGamma_ey" );
  DeclareVariable( met_refgamma_et, "MET_RefGamma_et");
  DeclareVariable( met_refgamma_phi, "MET_RefGamma_phi");
  DeclareVariable( met_refgamma_sumet, "MET_RefGamma_sumet");  
  DeclareVariable( met_reftau_ex, "MET_RefTau_ex" );
  DeclareVariable( met_reftau_ey, "MET_RefTau_ey" );
  DeclareVariable( met_reftau_et, "MET_RefTau_et");
  DeclareVariable( met_reftau_phi, "MET_RefTau_phi");
  DeclareVariable( met_reftau_sumet, "MET_RefTau_sumet");  
  DeclareVariable( met_refele_ex, "MET_RefEle_ex" );
  DeclareVariable( met_refele_ey, "MET_RefEle_ey" );
  DeclareVariable( met_refele_et, "MET_RefEle_et");
  DeclareVariable( met_refele_phi, "MET_RefEle_phi");
  DeclareVariable( met_refele_sumet, "MET_RefEle_sumet");  
  DeclareVariable( met_refjet_ex, "MET_RefJet_ex" );
  DeclareVariable( met_refjet_ey, "MET_RefJet_ey" );
  DeclareVariable( met_refjet_et, "MET_RefJet_et");
  DeclareVariable( met_refjet_phi, "MET_RefJet_phi");
  DeclareVariable( met_refjet_sumet, "MET_RefJet_sumet");
  DeclareVariable( met_refmuon_ex, "MET_RefMuon_ex" );
  DeclareVariable( met_refmuon_ey, "MET_RefMuon_ey" );
  DeclareVariable( met_refmuon_et, "MET_RefMuon_et");
  DeclareVariable( met_refmuon_phi, "MET_RefMuon_phi");  
  DeclareVariable( met_refmuon_sumet, "MET_RefMuon_sumet");    
  DeclareVariable( met_muonboy_ex, "MET_MuonBoy_ex" );
  DeclareVariable( met_muonboy_ey, "MET_MuonBoy_ey" );
  DeclareVariable( met_muonboy_et, "MET_MuonBoy_et");
  DeclareVariable( met_muonboy_phi, "MET_MuonBoy_phi");
  DeclareVariable( met_muonboy_sumet, "MET_MuonBoy_sumet");
  DeclareVariable( met_cellout_ex, "MET_CellOut_ex" );
  DeclareVariable( met_cellout_ey, "MET_CellOut_ey" );
  DeclareVariable( met_cellout_et, "MET_CellOut_et");
  DeclareVariable( met_cellout_phi, "MET_CellOut_phi");
  DeclareVariable( met_cellout_sumet, "MET_CellOut_sumet");
  DeclareVariable( met_cellout_eflow_ex, "MET_CellOut_Eflow_ex" );
  DeclareVariable( met_cellout_eflow_ey, "MET_CellOut_Eflow_ey" );
  DeclareVariable( met_cellout_eflow_et, "MET_CellOut_Eflow_et");
  DeclareVariable( met_cellout_eflow_phi, "MET_CellOut_Eflow_phi");
  DeclareVariable( met_cellout_eflow_sumet, "MET_CellOut_Eflow_sumet");
  DeclareVariable( met_softjets_ex, "MET_SoftJets_ex" );
  DeclareVariable( met_softjets_ey, "MET_SoftJets_ey" );
  DeclareVariable( met_softjets_et, "MET_SoftJets_et");
  DeclareVariable( met_softjets_phi, "MET_SoftJets_phi");
  DeclareVariable( met_softjets_sumet, "MET_SoftJets_sumet");
  
  DeclareVariable( met_reffinal_em_ex, 	  "MET_RefFinal_em_ex" );      
  DeclareVariable( met_reffinal_em_ey, 	  "MET_RefFinal_em_ey" );      
  DeclareVariable( met_reffinal_em_et, 	  "MET_RefFinal_em_et");       
  DeclareVariable( met_reffinal_em_phi,   "MET_RefFinal_em_phi");      
  DeclareVariable( met_reffinal_em_sumet, "MET_RefFinal_em_sumet");    
  DeclareVariable( met_refgamma_em_ex,    "MET_RefGamma_em_ex" );  
  DeclareVariable( met_refgamma_em_ey,    "MET_RefGamma_em_ey" );  
  DeclareVariable( met_refgamma_em_et,    "MET_RefGamma_em_et");   
  DeclareVariable( met_refgamma_em_phi,   "MET_RefGamma_em_phi");  
  DeclareVariable( met_refgamma_em_sumet, "MET_RefGamma_em_sumet");
  DeclareVariable( met_reftau_em_ex,      "MET_RefTau_em_ex" );        
  DeclareVariable( met_reftau_em_ey,      "MET_RefTau_em_ey" );        
  DeclareVariable( met_reftau_em_et,      "MET_RefTau_em_et");         
  DeclareVariable( met_reftau_em_phi,     "MET_RefTau_em_phi");        
  DeclareVariable( met_reftau_em_sumet,   "MET_RefTau_em_sumet");      
  DeclareVariable( met_refele_em_ex,      "MET_RefEle_em_ex" );        
  DeclareVariable( met_refele_em_ey,      "MET_RefEle_em_ey" );        
  DeclareVariable( met_refele_em_et,      "MET_RefEle_em_et");         
  DeclareVariable( met_refele_em_phi,     "MET_RefEle_em_phi");        
  DeclareVariable( met_refele_em_sumet,   "MET_RefEle_em_sumet");      
  DeclareVariable( met_refjet_em_ex,      "MET_RefJet_em_ex" );        
  DeclareVariable( met_refjet_em_ey,      "MET_RefJet_em_ey" );        
  DeclareVariable( met_refjet_em_et,      "MET_RefJet_em_et");         
  DeclareVariable( met_refjet_em_phi,     "MET_RefJet_em_phi");        
  DeclareVariable( met_refjet_em_sumet,   "MET_RefJet_em_sumet");      
  DeclareVariable( met_refmuon_em_ex,	  "MET_RefMuon_em_ex" );       
  DeclareVariable( met_refmuon_em_ey,	  "MET_RefMuon_em_ey" );       
  DeclareVariable( met_refmuon_em_et,	  "MET_RefMuon_em_et");        
  DeclareVariable( met_refmuon_em_phi,    "MET_RefMuon_em_phi");       
  DeclareVariable( met_refmuon_em_sumet,  "MET_RefMuon_em_sumet");     
//  DeclareVariable( met_muonboy_em_ex,	  "MET_MuonBoy_em_ex" );       
//  DeclareVariable( met_muonboy_em_ey,	  "MET_MuonBoy_em_ey" );       
//  DeclareVariable( met_muonboy_em_et,	  "MET_MuonBoy_em_et");        
//  DeclareVariable( met_muonboy_em_phi,    "MET_MuonBoy_em_phi");       
//  DeclareVariable( met_muonboy_em_sumet,  "MET_MuonBoy_em_sumet");     
  DeclareVariable( met_cellout_em_ex,	  "MET_CellOut_em_ex" );       
  DeclareVariable( met_cellout_em_ey,	  "MET_CellOut_em_ey" );       
  DeclareVariable( met_cellout_em_et,	  "MET_CellOut_em_et");        
  DeclareVariable( met_cellout_em_phi,    "MET_CellOut_em_phi");       
  DeclareVariable( met_cellout_em_sumet,  "MET_CellOut_em_sumet");     
  DeclareVariable( met_softjets_em_ex,    "MET_SoftJets_em_ex" );      
  DeclareVariable( met_softjets_em_ey,    "MET_SoftJets_em_ey" );      
  DeclareVariable( met_softjets_em_et,    "MET_SoftJets_em_et");       
  DeclareVariable( met_softjets_em_phi,   "MET_SoftJets_em_phi");      
  DeclareVariable( met_softjets_em_sumet, "MET_SoftJets_em_sumet");    
  
  if (isMC) {
    DeclareVariable( met_truth_nonint_ex,   "MET_Truth_NonInt_ex" );   
    DeclareVariable( met_truth_nonint_ey,   "MET_Truth_NonInt_ey" );   
    DeclareVariable( met_truth_nonint_et,   "MET_Truth_NonInt_et");    
    DeclareVariable( met_truth_nonint_phi,  "MET_Truth_NonInt_phi");   
    DeclareVariable( met_truth_nonint_sumet,"MET_Truth_NonInt_sumet"); 
  }
  
  DeclareVariable( muon_pt, "muon_pt" );
  DeclareVariable( muon_phi, "muon_phi" );
  DeclareVariable( muon_eta, "muon_eta" );
  DeclareVariable( muon_eloss, "muon_eloss" );
  DeclareVariable( muon_pz, "muon_pz" );

  // inputs/outputs
  m_event_d3pdobject = new D3PDReader::EventInfoD3PDObject( m_entry_number );
  //m_mcevt_d3pdobject = new D3PDReader::MCEvtD3PDObject( m_entry_number );
  //m_trigger_d3pdobject = new D3PDReader::TriggerD3PDObject( m_entry_number );
  //m_trigEFel_d3pdobject = new D3PDReader::TrigEFelD3PDObject( m_entry_number, "trig_EF_el_" );
  m_met_d3pdobject = new D3PDReader::METD3PDObject( m_entry_number );
  m_vxp_d3pdobject = new D3PDReader::PrimaryVertexD3PDObject( m_entry_number );
  //m_truth_d3pdobject = new D3PDReader::TruthD3PDObject( m_entry_number );

  // input only
  //m_in_electron_d3pdobject = new D3PDReader::ElectronD3PDObject( m_entry_number, "el_" );
  //m_in_photon_d3pdobject = new D3PDReader::PhotonD3PDObject( m_entry_number, "ph_" );
  m_muon_d3pdobject = new D3PDReader::MuonStacoD3PDObject( m_entry_number, "mu_staco_" );
  //m_jet_d3pdobject = new D3PDReader::JetD3PDObject( m_entry_number, c_jet_container.c_str() );

  // control what is read out by setting those branches Active
  // - all branches are Not Active by default
  m_event_d3pdobject->SetActive(kTRUE,c_output_event_branches_regex);
  //m_mcevt_d3pdobject->SetActive(kTRUE,c_output_mcevt_branches_regex);
  //m_trigger_d3pdobject->SetActive(kTRUE,c_output_trigger_branches_regex);
  //m_trigEFel_d3pdobject->SetActive(kTRUE,c_output_trigEFel_branches_regex);
  m_met_d3pdobject->SetActive(kTRUE,c_output_met_branches_regex);
  //m_vxp_d3pdobject->SetActive(kTRUE,c_output_vxp_branches_regex);
 
  // input objects should have (at least) the same branches active as the outputs
  //m_in_electron_d3pdobject->SetActive(kTRUE,c_output_electron_branches_regex);
  //m_in_photon_d3pdobject->SetActive(kTRUE,c_output_photon_branches_regex);
  m_muon_d3pdobject->SetActive(kTRUE,c_output_muon_branches_regex);
  //m_jet_d3pdobject->SetActive(kTRUE,c_output_jet_branches_regex);
  //m_truth_d3pdobject->SetActive(kTRUE,c_output_truth_branches_regex);

   return;

}

void ZZ_Selection::EndInputDataImp( const SInputData& ) throw( SError ) {

   return;

}

void ZZ_Selection::BeginInputFileImp( const SInputData& ) throw( SError ) {

    m_logger << DEBUG  << "BeginInputFileImp "                         << SLogger::endmsg;

    m_event_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    //m_mcevt_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    //m_trigger_d3pdobject->ReadFrom( GetInputTree(c_trigger_tree_name.c_str()) );
    //m_trigEFel_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_met_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_vxp_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    //m_in_electron_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    //m_in_photon_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    //m_jet_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    //m_truth_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

   return;

}

void ZZ_Selection::BeginMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZZ_Selection::EndMasterInputDataImp( const SInputData& ) throw( SError ){

  //print cut flow and fill cut flow histo.
  m_logger << INFO <<"                  Z --> mu mu Cut Flow"<<SLogger::endmsg;
  m_logger << INFO <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << INFO <<"Cut........................:"<<"Number of events passed"<<SLogger::endmsg;
  m_logger << INFO <<"============================"<<"============================"<<SLogger::endmsg;
  m_logger << INFO <<"Events Before Cuts..........:"<<*cf_preselect  <<SLogger::endmsg;
  m_logger << INFO <<"Events After GRL............:"<<*cf_grl        <<" ("<<((double)*cf_grl)/((double)*cf_preselect)*100 <<"%)"      <<" ("<<((double)*cf_grl)/((double)*cf_preselect)*100 <<"%)"<< (m_doGRL ? "" : "(Disabled)") <<SLogger::endmsg;
  m_logger << INFO <<"Events After Trigger........:"<<*cf_trigger    <<" ("<<((double)*cf_trigger)/((double)*cf_grl)*100 <<"%)"        <<" ("<<((double)*cf_trigger)/((double)*cf_preselect)*100 <<"%)"<< (m_doTrig ? "" : "(Disabled)") <<SLogger::endmsg;
  m_logger << INFO <<"Events After Vertex.........:"<<*cf_vertex     <<" ("<<((double)*cf_vertex)/((double)*cf_trigger)*100 <<"%)"     <<" ("<<((double)*cf_vertex)/((double)*cf_preselect)*100 <<"%)"<< (m_doVert ? "" : "(Disabled)") <<SLogger::endmsg;
  m_logger << INFO <<"Events After Jet Cleaning...:"<<*cf_jetcleaning<<" ("<<((double)*cf_jetcleaning)/((double)*cf_vertex)*100 <<"%)" <<" ("<<((double)*cf_jetcleaning)/((double)*cf_preselect)*100 <<"%)" <<SLogger::endmsg;
  m_logger << INFO <<"Events After two comb. muons:"<<*cf_two_comb_mu<<" ("<<((double)*cf_two_comb_mu)/((double)*cf_jetcleaning)*100 <<"%)" <<" ("<<((double)*cf_two_comb_mu)/((double)*cf_preselect)*100 <<"%)"<< (m_doZ ? "" : "(Disabled)") <<SLogger::endmsg;
  m_logger << INFO <<"Events After Charge cut.....:"<<*cf_charge     <<" ("<<((double)*cf_charge)/((double)*cf_two_comb_mu)*100 <<"%)"   <<" ("<<((double)*cf_charge)/((double)*cf_preselect)*100 <<"%)" << (m_doZ ? "" : "(Disabled)")<<SLogger::endmsg;
  m_logger << INFO <<"Events After Mass Cut (mumu):"<<*cf_mass_mumu  <<" ("<<((double)*cf_mass_mumu)/((double)*cf_charge)*100 <<"%)"   <<" ("<<((double)*cf_mass_mumu)/((double)*cf_preselect)*100 <<"%)"<< (m_doZWindow ? "" : "(Disabled)") <<SLogger::endmsg;
  m_logger << INFO <<"============================"<<"============================"<<SLogger::endmsg;

  //delete mcp_smear;

  return;

}

void ZZ_Selection::ExecuteEventImp( const SInputData&, Double_t ) throw( SError ) {

  //run and event selection
  //m_logger << DEBUG << "Run Number: " <<m_event_d3pdobject->RunNumber()<< SLogger::endmsg;
  //m_logger << DEBUG << "Evt Number: " <<m_event_d3pdobject->EventNumber()<< SLogger::endmsg;

  //run and event selection
  vector<unsigned int>::iterator run_it = v_runs.begin();
  vector<unsigned int>::iterator evt_it = v_evts.begin();
  vector<double>::iterator mass_it = v_mass.begin();
  bool found_evt = false;

  while(run_it != v_runs.end() && evt_it != v_evts.end()) {
    if ((*run_it) == m_event_d3pdobject->RunNumber() && (*evt_it) == m_event_d3pdobject->EventNumber()) {
      m_logger << INFO << "Found Event! " << m_event_d3pdobject->RunNumber() <<", "<<m_event_d3pdobject->EventNumber() << ", "<<(*mass_it)<<SLogger::endmsg;
      m_4l = (*mass_it);
      found_evt = true;
      break;
    }
    run_it++;
    evt_it++;
    mass_it++;
  }

  if (!found_evt) throw SError( SError::SkipEvent );
  
  pileupEventWeight = 1.0;
  scaledMuPileupEventWeight1 = 1.0;
  scaledMuPileupEventWeight2 = 1.0;
  zPtEventWeight = 1.0;
  evt_actualIntPerXing = 0.0;
  evt_averageIntPerXing = 0.0;
  n_vertices = 0;
  n_jetspt20 = 0;
  run_number = 0;
  evt_number = 0;
  lb_number = 0;
  bcid = 0;
  bunch_config_id = 0;
  mt = 0.0;

  met_lochadtopo_ex = 0.0;
  met_lochadtopo_ey = 0.0;  
  met_lochadtopo_et = 0.0;
  met_lochadtopo_phi = 0.0;
  met_lochadtopo_sumet = 0.0;
  
  met_reffinal_ex = 0.0;
  met_reffinal_ey = 0.0;
  met_reffinal_et = 0.0;
  met_reffinal_phi = 0.0;
  met_reffinal_sumet = 0.0;
  met_refgamma_ex = 0.0;
  met_refgamma_ey = 0.0;
  met_refgamma_et = 0.0;
  met_refgamma_phi = 0.0;
  met_refgamma_sumet = 0.0;
  met_reftau_ex = 0.0;
  met_reftau_ey = 0.0;
  met_reftau_et = 0.0;
  met_reftau_phi = 0.0;
  met_reftau_sumet = 0.0;
  met_refele_ex = 0.0;
  met_refele_ey = 0.0;
  met_refele_et = 0.0;
  met_refele_phi = 0.0;
  met_refele_sumet = 0.0;
  met_refjet_ex = 0.0;
  met_refjet_ey = 0.0;
  met_refjet_et = 0.0;
  met_refjet_phi = 0.0;
  met_refjet_sumet = 0.0;
  met_muonboy_ex = 0.0;
  met_muonboy_ey = 0.0;
  met_muonboy_et = 0.0;
  met_muonboy_phi = 0.0;
  met_muonboy_sumet = 0.0;
  met_refmuon_ex = 0.0;
  met_refmuon_ey = 0.0;
  met_refmuon_et = 0.0;
  met_refmuon_phi = 0.0;
  met_refmuon_sumet = 0.0;
  met_cellout_ex = 0.0;
  met_cellout_ey = 0.0;
  met_cellout_et = 0.0;
  met_cellout_phi = 0.0;
  met_cellout_sumet = 0.0;
  met_cellout_eflow_ex = 0.0;
  met_cellout_eflow_ey = 0.0;
  met_cellout_eflow_et = 0.0;
  met_cellout_eflow_phi = 0.0;
  met_cellout_eflow_sumet = 0.0;
  met_softjets_ex = 0.0;
  met_softjets_ey = 0.0;
  met_softjets_et = 0.0;
  met_softjets_phi = 0.0; 
  met_softjets_sumet = 0.0;

  met_reffinal_em_ex = 0.0;
  met_reffinal_em_ey = 0.0;
  met_reffinal_em_et = 0.0;
  met_reffinal_em_phi = 0.0;
  met_reffinal_em_sumet = 0.0;
  met_refgamma_em_ex = 0.0;
  met_refgamma_em_ey = 0.0;
  met_refgamma_em_et = 0.0;
  met_refgamma_em_phi = 0.0;
  met_refgamma_em_sumet = 0.0;
  met_reftau_em_ex = 0.0;
  met_reftau_em_ey = 0.0;
  met_reftau_em_et = 0.0;
  met_reftau_em_phi = 0.0;
  met_reftau_em_sumet = 0.0;
  met_refele_em_ex = 0.0;
  met_refele_em_ey = 0.0;
  met_refele_em_et = 0.0;
  met_refele_em_phi = 0.0;
  met_refele_em_sumet = 0.0;
  met_refjet_em_ex = 0.0;
  met_refjet_em_ey = 0.0;
  met_refjet_em_et = 0.0;
  met_refjet_em_phi = 0.0;
  met_refjet_em_sumet = 0.0;
//  met_muonboy_em_ex = 0.0;
//  met_muonboy_em_ey = 0.0;
//  met_muonboy_em_et = 0.0;
//  met_muonboy_em_phi = 0.0;
//  met_muonboy_em_sumet = 0.0;
  met_refmuon_em_ex = 0.0;
  met_refmuon_em_ey = 0.0;
  met_refmuon_em_et = 0.0;
  met_refmuon_em_phi = 0.0;
  met_refmuon_em_sumet = 0.0;
  met_cellout_em_ex = 0.0;
  met_cellout_em_ey = 0.0;
  met_cellout_em_et = 0.0;
  met_cellout_em_phi = 0.0;
  met_cellout_em_sumet = 0.0;
  met_softjets_em_ex = 0.0;
  met_softjets_em_ey = 0.0;
  met_softjets_em_et = 0.0;
  met_softjets_em_phi = 0.0;
  met_softjets_em_sumet = 0.0;
  
  met_truth_nonint_ex = 0.0;
  met_truth_nonint_ey = 0.0;
  met_truth_nonint_et = 0.0;
  met_truth_nonint_phi = 0.0;
  met_truth_nonint_sumet = 0.0;

  muon_pt = 0.0;
  muon_phi = 0.0;
  muon_eta = 0.0;
  muon_eloss = 0.0;
  muon_pz = 0.0;

 
 //fill event and pileup variables
 evt_actualIntPerXing =  m_event_d3pdobject->actualIntPerXing();
 evt_averageIntPerXing = m_event_d3pdobject->averageIntPerXing();
 run_number = m_event_d3pdobject->RunNumber();
 evt_number = m_event_d3pdobject->EventNumber();
 lb_number = m_event_d3pdobject->lbn();
 bcid = m_event_d3pdobject->bcid();
 //if (!isMC) bunch_config_id = m_event_d3pdobject->bunch_configID(); 

/*TODO Update for new MET Object
 m_logger << DEBUG << "Calculate Met " << SLogger::endmsg;
 
//  //met_lochadtopo_ex = m_met_d3pdobject->LocHadTopo_etx();
//  //met_lochadtopo_ey = m_met_d3pdobject->LocHadTopo_ety();
//  met_lochadtopo_et = m_met_d3pdobject->LocHadTopo_et();
//  met_lochadtopo_phi = m_met_d3pdobject->LocHadTopo_phi();
//  met_lochadtopo_sumet = m_met_d3pdobject->LocHadTopo_sumet();
 
//  //Store MET RefFinal terms
//  //met_reffinal_ex = m_met_d3pdobject->RefFinal_etx();
//  //met_reffinal_ey = m_met_d3pdobject->RefFinal_ety();
//  met_reffinal_et = m_met_d3pdobject->RefFinal_et();
//  met_reffinal_phi = m_met_d3pdobject->RefFinal_phi();
//  met_reffinal_sumet = m_met_d3pdobject->RefFinal_sumet();

//  //met_refgamma_ex = m_met_d3pdobject->RefGamma_etx();
//  //met_refgamma_ey = m_met_d3pdobject->RefGamma_ety();
//  met_refgamma_et = m_met_d3pdobject->RefGamma_et();
//  met_refgamma_phi = m_met_d3pdobject->RefGamma_phi();
//  met_refgamma_sumet = m_met_d3pdobject->RefGamma_sumet();

//  //met_reftau_ex = m_met_d3pdobject->RefTau_etx();
//  //met_reftau_ey = m_met_d3pdobject->RefTau_ety();
//  met_reftau_et = m_met_d3pdobject->RefTau_et();
//  met_reftau_phi = m_met_d3pdobject->RefTau_phi();
//  met_reftau_sumet = m_met_d3pdobject->RefTau_sumet();

//  //met_refele_ex = m_met_d3pdobject->RefEle_etx();
//  //met_refele_ey = m_met_d3pdobject->RefEle_ety();
//  met_refele_et = m_met_d3pdobject->RefEle_et();
//  met_refele_phi = m_met_d3pdobject->RefEle_phi();
//  met_refele_sumet = m_met_d3pdobject->RefEle_sumet();

//  //met_refjet_ex = m_met_d3pdobject->RefJet_etx();
//  //met_refjet_ey = m_met_d3pdobject->RefJet_ety();
//  met_refjet_et = m_met_d3pdobject->RefJet_et();
//  met_refjet_phi = m_met_d3pdobject->RefJet_phi();
//  met_refjet_sumet = m_met_d3pdobject->RefJet_sumet();
  
//  //met_muonboy_ex = m_met_d3pdobject->MuonBoy_etx();
//  //met_muonboy_ey = m_met_d3pdobject->MuonBoy_ety();
//  met_muonboy_et = m_met_d3pdobject->MuonBoy_et();
//  met_muonboy_phi = m_met_d3pdobject->MuonBoy_phi();
//  met_muonboy_sumet = m_met_d3pdobject->MuonBoy_sumet();

//  //met_refmuon_ex = m_met_d3pdobject->RefMuon_etx();
//  //met_refmuon_ey = m_met_d3pdobject->RefMuon_ety();
//  met_refmuon_et = m_met_d3pdobject->RefMuon_et();
//  met_refmuon_phi = m_met_d3pdobject->RefMuon_phi();
//  met_refmuon_sumet = m_met_d3pdobject->RefMuon_sumet();
 
//  //met_cellout_ex = m_met_d3pdobject->CellOut_etx();
//  //met_cellout_ey = m_met_d3pdobject->CellOut_ety();
//  met_cellout_et = m_met_d3pdobject->CellOut_et();
//  met_cellout_phi = m_met_d3pdobject->CellOut_phi();
//  met_cellout_sumet = m_met_d3pdobject->CellOut_sumet();

//  //met_cellout_eflow_ex = m_met_d3pdobject->CellOut_Eflow_etx();
//  //met_cellout_eflow_ey = m_met_d3pdobject->CellOut_Eflow_ety();
//  met_cellout_eflow_et = m_met_d3pdobject->CellOut_Eflow_et();
//  met_cellout_eflow_phi = m_met_d3pdobject->CellOut_Eflow_phi();
//  met_cellout_eflow_sumet = m_met_d3pdobject->CellOut_Eflow_sumet();

//  //met_softjets_ex = m_met_d3pdobject->SoftJets_etx();
//  //met_softjets_ey = m_met_d3pdobject->SoftJets_ety();
//  met_softjets_et = m_met_d3pdobject->SoftJets_et();
//  met_softjets_phi = m_met_d3pdobject->SoftJets_phi();
//  met_softjets_sumet = m_met_d3pdobject->SoftJets_sumet();

//  //met_reffinal_em_ex = m_met_d3pdobject->RefFinal_em_etx();
//  //met_reffinal_em_ey = m_met_d3pdobject->RefFinal_em_ety();
//  met_reffinal_em_et = m_met_d3pdobject->RefFinal_em_et();
//  met_reffinal_em_phi = m_met_d3pdobject->RefFinal_em_phi();
//  met_reffinal_em_sumet = m_met_d3pdobject->RefFinal_em_sumet();

//  //met_refgamma_em_ex = m_met_d3pdobject->RefGamma_em_etx();
//  //met_refgamma_em_ey = m_met_d3pdobject->RefGamma_em_ety();
//  met_refgamma_em_et = m_met_d3pdobject->RefGamma_em_et();
//  met_refgamma_em_phi = m_met_d3pdobject->RefGamma_em_phi();
//  met_refgamma_em_sumet = m_met_d3pdobject->RefGamma_em_sumet();

//  //met_reftau_em_ex = m_met_d3pdobject->RefTau_em_etx();
//  //met_reftau_em_ey = m_met_d3pdobject->RefTau_em_ety();
//  met_reftau_em_et = m_met_d3pdobject->RefTau_em_et();
//  met_reftau_em_phi = m_met_d3pdobject->RefTau_em_phi();
//  met_reftau_em_sumet = m_met_d3pdobject->RefTau_em_sumet();

//  //met_refele_em_ex = m_met_d3pdobject->RefEle_em_etx();
//  //met_refele_em_ey = m_met_d3pdobject->RefEle_em_ety();
//  met_refele_em_et = m_met_d3pdobject->RefEle_em_et();
//  met_refele_em_phi = m_met_d3pdobject->RefEle_em_phi();;
//  met_refele_em_sumet = m_met_d3pdobject->RefEle_em_sumet();

//  //met_refjet_em_ex = m_met_d3pdobject->RefJet_em_etx();
//  //met_refjet_em_ey = m_met_d3pdobject->RefJet_em_ety();
//  met_refjet_em_et = m_met_d3pdobject->RefJet_em_et();
//  met_refjet_em_phi = m_met_d3pdobject->RefJet_em_phi();
//  met_refjet_em_sumet = m_met_d3pdobject->RefJet_em_sumet();
  
//  //met_refmuon_em_ex = m_met_d3pdobject->RefMuon_em_etx();
//  //met_refmuon_em_ey = m_met_d3pdobject->RefMuon_em_ety();
//  met_refmuon_em_et = m_met_d3pdobject->RefMuon_em_et();
//  met_refmuon_em_phi = m_met_d3pdobject->RefMuon_em_phi();
//  met_refmuon_em_sumet = m_met_d3pdobject->RefMuon_em_sumet();
 
//  //met_cellout_em_ex = m_met_d3pdobject->CellOut_em_etx();
//  //met_cellout_em_ey = m_met_d3pdobject->CellOut_em_ety();
//  met_cellout_em_et = m_met_d3pdobject->CellOut_em_et();
//  met_cellout_em_phi = m_met_d3pdobject->CellOut_em_phi();
//  met_cellout_em_sumet = m_met_d3pdobject->CellOut_em_sumet();

//  //met_softjets_em_ex = m_met_d3pdobject->SoftJets_em_etx();
//  //met_softjets_em_ey = m_met_d3pdobject->SoftJets_em_ety();
//  met_softjets_em_et = m_met_d3pdobject->SoftJets_em_et();
//  met_softjets_em_phi = m_met_d3pdobject->SoftJets_em_phi();
//  met_softjets_em_sumet = m_met_d3pdobject->SoftJets_em_sumet();
 
//  if (isMC) {
//    //met_truth_nonint_ex = m_met_d3pdobject->Truth_NonInt_etx();
//    //met_truth_nonint_ey = m_met_d3pdobject->Truth_NonInt_ety();
//    met_truth_nonint_et = m_met_d3pdobject->Truth_NonInt_et();
//    met_truth_nonint_phi = m_met_d3pdobject->Truth_NonInt_phi();
//    met_truth_nonint_sumet = m_met_d3pdobject->Truth_NonInt_sumet();
//  }
*/
 return;

}
