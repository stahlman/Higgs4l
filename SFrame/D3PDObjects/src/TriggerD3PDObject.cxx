// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/TriggerD3PDObject.h"

ClassImp( D3PDReader::TriggerD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   TriggerD3PDObject::TriggerD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "trig_L1_TAV" ] = &L1_TAV;
      fHandles[ "EF_2e12Tvh_loose1" ] = &EF_2e12Tvh_loose1;
      fHandles[ "EF_2e5_tight1_Jpsi" ] = &EF_2e5_tight1_Jpsi;
      fHandles[ "EF_2e7T_loose1_mu6" ] = &EF_2e7T_loose1_mu6;
      fHandles[ "EF_2e7T_medium1_mu6" ] = &EF_2e7T_medium1_mu6;
      fHandles[ "EF_2g15vh_loose_g10_loose" ] = &EF_2g15vh_loose_g10_loose;
      fHandles[ "EF_2g15vh_medium" ] = &EF_2g15vh_medium;
      fHandles[ "EF_2g15vh_medium_g10_medium" ] = &EF_2g15vh_medium_g10_medium;
      fHandles[ "EF_2g20_loose" ] = &EF_2g20_loose;
      fHandles[ "EF_2g20vh_medium" ] = &EF_2g20vh_medium;
      fHandles[ "EF_2g30_loose" ] = &EF_2g30_loose;
      fHandles[ "EF_2g40_loose" ] = &EF_2g40_loose;
      fHandles[ "EF_2mu10" ] = &EF_2mu10;
      fHandles[ "EF_2mu10_MSonly_g10_loose" ] = &EF_2mu10_MSonly_g10_loose;
      fHandles[ "EF_2mu10_MSonly_g10_loose_EMPTY" ] = &EF_2mu10_MSonly_g10_loose_EMPTY;
      fHandles[ "EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO" ] = &EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO;
      fHandles[ "EF_2mu13" ] = &EF_2mu13;
      fHandles[ "EF_2mu13_Zmumu_IDTrkNoCut" ] = &EF_2mu13_Zmumu_IDTrkNoCut;
      fHandles[ "EF_2mu13_l2muonSA" ] = &EF_2mu13_l2muonSA;
      fHandles[ "EF_2mu15" ] = &EF_2mu15;
      fHandles[ "EF_2mu4T" ] = &EF_2mu4T;
      fHandles[ "EF_2mu4T_2e5_tight1" ] = &EF_2mu4T_2e5_tight1;
      fHandles[ "EF_2mu4T_Bmumu" ] = &EF_2mu4T_Bmumu;
      fHandles[ "EF_2mu4T_Bmumu_Barrel" ] = &EF_2mu4T_Bmumu_Barrel;
      fHandles[ "EF_2mu4T_Bmumu_BarrelOnly" ] = &EF_2mu4T_Bmumu_BarrelOnly;
      fHandles[ "EF_2mu4T_Bmumux" ] = &EF_2mu4T_Bmumux;
      fHandles[ "EF_2mu4T_Bmumux_Barrel" ] = &EF_2mu4T_Bmumux_Barrel;
      fHandles[ "EF_2mu4T_Bmumux_BarrelOnly" ] = &EF_2mu4T_Bmumux_BarrelOnly;
      fHandles[ "EF_2mu4T_DiMu" ] = &EF_2mu4T_DiMu;
      fHandles[ "EF_2mu4T_DiMu_Barrel" ] = &EF_2mu4T_DiMu_Barrel;
      fHandles[ "EF_2mu4T_DiMu_BarrelOnly" ] = &EF_2mu4T_DiMu_BarrelOnly;
      fHandles[ "EF_2mu4T_DiMu_L2StarB" ] = &EF_2mu4T_DiMu_L2StarB;
      fHandles[ "EF_2mu4T_DiMu_L2StarC" ] = &EF_2mu4T_DiMu_L2StarC;
      fHandles[ "EF_2mu4T_DiMu_e5_tight1" ] = &EF_2mu4T_DiMu_e5_tight1;
      fHandles[ "EF_2mu4T_DiMu_l2muonSA" ] = &EF_2mu4T_DiMu_l2muonSA;
      fHandles[ "EF_2mu4T_DiMu_noVtx_noOS" ] = &EF_2mu4T_DiMu_noVtx_noOS;
      fHandles[ "EF_2mu4T_Jpsimumu" ] = &EF_2mu4T_Jpsimumu;
      fHandles[ "EF_2mu4T_Jpsimumu_Barrel" ] = &EF_2mu4T_Jpsimumu_Barrel;
      fHandles[ "EF_2mu4T_Jpsimumu_BarrelOnly" ] = &EF_2mu4T_Jpsimumu_BarrelOnly;
      fHandles[ "EF_2mu4T_Jpsimumu_IDTrkNoCut" ] = &EF_2mu4T_Jpsimumu_IDTrkNoCut;
      fHandles[ "EF_2mu4T_Upsimumu" ] = &EF_2mu4T_Upsimumu;
      fHandles[ "EF_2mu4T_Upsimumu_Barrel" ] = &EF_2mu4T_Upsimumu_Barrel;
      fHandles[ "EF_2mu4T_Upsimumu_BarrelOnly" ] = &EF_2mu4T_Upsimumu_BarrelOnly;
      fHandles[ "EF_2mu4T_xe50_tclcw" ] = &EF_2mu4T_xe50_tclcw;
      fHandles[ "EF_2mu4T_xe60" ] = &EF_2mu4T_xe60;
      fHandles[ "EF_2mu4T_xe60_tclcw" ] = &EF_2mu4T_xe60_tclcw;
      fHandles[ "EF_2mu6" ] = &EF_2mu6;
      fHandles[ "EF_2mu6_Bmumu" ] = &EF_2mu6_Bmumu;
      fHandles[ "EF_2mu6_Bmumux" ] = &EF_2mu6_Bmumux;
      fHandles[ "EF_2mu6_DiMu" ] = &EF_2mu6_DiMu;
      fHandles[ "EF_2mu6_DiMu_DY20" ] = &EF_2mu6_DiMu_DY20;
      fHandles[ "EF_2mu6_DiMu_DY25" ] = &EF_2mu6_DiMu_DY25;
      fHandles[ "EF_2mu6_DiMu_noVtx_noOS" ] = &EF_2mu6_DiMu_noVtx_noOS;
      fHandles[ "EF_2mu6_Jpsimumu" ] = &EF_2mu6_Jpsimumu;
      fHandles[ "EF_2mu6_Upsimumu" ] = &EF_2mu6_Upsimumu;
      fHandles[ "EF_2mu6i_DiMu_DY" ] = &EF_2mu6i_DiMu_DY;
      fHandles[ "EF_2mu6i_DiMu_DY_2j25_a4tchad" ] = &EF_2mu6i_DiMu_DY_2j25_a4tchad;
      fHandles[ "EF_2mu6i_DiMu_DY_noVtx_noOS" ] = &EF_2mu6i_DiMu_DY_noVtx_noOS;
      fHandles[ "EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" ] = &EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
      fHandles[ "EF_2mu8_EFxe30" ] = &EF_2mu8_EFxe30;
      fHandles[ "EF_2mu8_EFxe30_tclcw" ] = &EF_2mu8_EFxe30_tclcw;
      fHandles[ "EF_2tau29T_medium1" ] = &EF_2tau29T_medium1;
      fHandles[ "EF_2tau29_medium1" ] = &EF_2tau29_medium1;
      fHandles[ "EF_2tau29i_medium1" ] = &EF_2tau29i_medium1;
      fHandles[ "EF_2tau38T_medium" ] = &EF_2tau38T_medium;
      fHandles[ "EF_2tau38T_medium1" ] = &EF_2tau38T_medium1;
      fHandles[ "EF_2tau38T_medium1_llh" ] = &EF_2tau38T_medium1_llh;
      fHandles[ "EF_b110_loose_j110_a4tchad_xe55_tclcw" ] = &EF_b110_loose_j110_a4tchad_xe55_tclcw;
      fHandles[ "EF_b110_loose_j110_a4tchad_xe60_tclcw" ] = &EF_b110_loose_j110_a4tchad_xe60_tclcw;
      fHandles[ "EF_b45_mediumEF_j110_j45_xe60_tclcw" ] = &EF_b45_mediumEF_j110_j45_xe60_tclcw;
      fHandles[ "EF_b55_mediumEF_j110_j55_xe60_tclcw" ] = &EF_b55_mediumEF_j110_j55_xe60_tclcw;
      fHandles[ "EF_b80_loose_j80_a4tchad_xe55_tclcw" ] = &EF_b80_loose_j80_a4tchad_xe55_tclcw;
      fHandles[ "EF_b80_loose_j80_a4tchad_xe60_tclcw" ] = &EF_b80_loose_j80_a4tchad_xe60_tclcw;
      fHandles[ "EF_b80_loose_j80_a4tchad_xe70_tclcw" ] = &EF_b80_loose_j80_a4tchad_xe70_tclcw;
      fHandles[ "EF_b80_loose_j80_a4tchad_xe75_tclcw" ] = &EF_b80_loose_j80_a4tchad_xe75_tclcw;
      fHandles[ "EF_e11_etcut" ] = &EF_e11_etcut;
      fHandles[ "EF_e12Tvh_loose1" ] = &EF_e12Tvh_loose1;
      fHandles[ "EF_e12Tvh_loose1_mu8" ] = &EF_e12Tvh_loose1_mu8;
      fHandles[ "EF_e12Tvh_medium1" ] = &EF_e12Tvh_medium1;
      fHandles[ "EF_e12Tvh_medium1_mu10" ] = &EF_e12Tvh_medium1_mu10;
      fHandles[ "EF_e12Tvh_medium1_mu6" ] = &EF_e12Tvh_medium1_mu6;
      fHandles[ "EF_e12Tvh_medium1_mu6_topo_medium" ] = &EF_e12Tvh_medium1_mu6_topo_medium;
      fHandles[ "EF_e12Tvh_medium1_mu8" ] = &EF_e12Tvh_medium1_mu8;
      fHandles[ "EF_e13_etcutTrk_xs60" ] = &EF_e13_etcutTrk_xs60;
      fHandles[ "EF_e13_etcutTrk_xs60_dphi2j15xe20" ] = &EF_e13_etcutTrk_xs60_dphi2j15xe20;
      fHandles[ "EF_e14_tight1_e4_etcut_Jpsi" ] = &EF_e14_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_e15vh_medium1" ] = &EF_e15vh_medium1;
      fHandles[ "EF_e18_loose1" ] = &EF_e18_loose1;
      fHandles[ "EF_e18_loose1_g25_medium" ] = &EF_e18_loose1_g25_medium;
      fHandles[ "EF_e18_loose1_g35_loose" ] = &EF_e18_loose1_g35_loose;
      fHandles[ "EF_e18_loose1_g35_medium" ] = &EF_e18_loose1_g35_medium;
      fHandles[ "EF_e18_medium1" ] = &EF_e18_medium1;
      fHandles[ "EF_e18_medium1_g25_loose" ] = &EF_e18_medium1_g25_loose;
      fHandles[ "EF_e18_medium1_g25_medium" ] = &EF_e18_medium1_g25_medium;
      fHandles[ "EF_e18_medium1_g35_loose" ] = &EF_e18_medium1_g35_loose;
      fHandles[ "EF_e18_medium1_g35_medium" ] = &EF_e18_medium1_g35_medium;
      fHandles[ "EF_e18vh_medium1" ] = &EF_e18vh_medium1;
      fHandles[ "EF_e18vh_medium1_2e7T_medium1" ] = &EF_e18vh_medium1_2e7T_medium1;
      fHandles[ "EF_e20_etcutTrk_xe30_dphi2j15xe20" ] = &EF_e20_etcutTrk_xe30_dphi2j15xe20;
      fHandles[ "EF_e20_etcutTrk_xs60_dphi2j15xe20" ] = &EF_e20_etcutTrk_xs60_dphi2j15xe20;
      fHandles[ "EF_e20vhT_medium1_g6T_etcut_Upsi" ] = &EF_e20vhT_medium1_g6T_etcut_Upsi;
      fHandles[ "EF_e20vhT_tight1_g6T_etcut_Upsi" ] = &EF_e20vhT_tight1_g6T_etcut_Upsi;
      fHandles[ "EF_e22vh_loose" ] = &EF_e22vh_loose;
      fHandles[ "EF_e22vh_loose0" ] = &EF_e22vh_loose0;
      fHandles[ "EF_e22vh_loose1" ] = &EF_e22vh_loose1;
      fHandles[ "EF_e22vh_medium1" ] = &EF_e22vh_medium1;
      fHandles[ "EF_e22vh_medium1_IDTrkNoCut" ] = &EF_e22vh_medium1_IDTrkNoCut;
      fHandles[ "EF_e22vh_medium1_IdScan" ] = &EF_e22vh_medium1_IdScan;
      fHandles[ "EF_e22vh_medium1_SiTrk" ] = &EF_e22vh_medium1_SiTrk;
      fHandles[ "EF_e22vh_medium1_TRT" ] = &EF_e22vh_medium1_TRT;
      fHandles[ "EF_e22vhi_medium1" ] = &EF_e22vhi_medium1;
      fHandles[ "EF_e24vh_loose" ] = &EF_e24vh_loose;
      fHandles[ "EF_e24vh_loose0" ] = &EF_e24vh_loose0;
      fHandles[ "EF_e24vh_loose1" ] = &EF_e24vh_loose1;
      fHandles[ "EF_e24vh_medium1" ] = &EF_e24vh_medium1;
      fHandles[ "EF_e24vh_medium1_EFxe30" ] = &EF_e24vh_medium1_EFxe30;
      fHandles[ "EF_e24vh_medium1_EFxe30_tcem" ] = &EF_e24vh_medium1_EFxe30_tcem;
      fHandles[ "EF_e24vh_medium1_EFxe35_tcem" ] = &EF_e24vh_medium1_EFxe35_tcem;
      fHandles[ "EF_e24vh_medium1_EFxe35_tclcw" ] = &EF_e24vh_medium1_EFxe35_tclcw;
      fHandles[ "EF_e24vh_medium1_EFxe40" ] = &EF_e24vh_medium1_EFxe40;
      fHandles[ "EF_e24vh_medium1_IDTrkNoCut" ] = &EF_e24vh_medium1_IDTrkNoCut;
      fHandles[ "EF_e24vh_medium1_IdScan" ] = &EF_e24vh_medium1_IdScan;
      fHandles[ "EF_e24vh_medium1_L2StarB" ] = &EF_e24vh_medium1_L2StarB;
      fHandles[ "EF_e24vh_medium1_L2StarC" ] = &EF_e24vh_medium1_L2StarC;
      fHandles[ "EF_e24vh_medium1_SiTrk" ] = &EF_e24vh_medium1_SiTrk;
      fHandles[ "EF_e24vh_medium1_TRT" ] = &EF_e24vh_medium1_TRT;
      fHandles[ "EF_e24vh_medium1_b35_mediumEF_j35_a4tchad" ] = &EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;
      fHandles[ "EF_e24vh_medium1_e7_medium1" ] = &EF_e24vh_medium1_e7_medium1;
      fHandles[ "EF_e24vh_tight1_e15_NoCut_Zee" ] = &EF_e24vh_tight1_e15_NoCut_Zee;
      fHandles[ "EF_e24vhi_loose1_mu8" ] = &EF_e24vhi_loose1_mu8;
      fHandles[ "EF_e24vhi_medium1" ] = &EF_e24vhi_medium1;
      fHandles[ "EF_e45_etcut" ] = &EF_e45_etcut;
      fHandles[ "EF_e45_medium1" ] = &EF_e45_medium1;
      fHandles[ "EF_e5_tight1" ] = &EF_e5_tight1;
      fHandles[ "EF_e5_tight1_e14_etcut_Jpsi" ] = &EF_e5_tight1_e14_etcut_Jpsi;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi" ] = &EF_e5_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_IdScan" ] = &EF_e5_tight1_e4_etcut_Jpsi_IdScan;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_L2StarB" ] = &EF_e5_tight1_e4_etcut_Jpsi_L2StarB;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_L2StarC" ] = &EF_e5_tight1_e4_etcut_Jpsi_L2StarC;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_SiTrk" ] = &EF_e5_tight1_e4_etcut_Jpsi_SiTrk;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_TRT" ] = &EF_e5_tight1_e4_etcut_Jpsi_TRT;
      fHandles[ "EF_e5_tight1_e5_NoCut" ] = &EF_e5_tight1_e5_NoCut;
      fHandles[ "EF_e5_tight1_e9_etcut_Jpsi" ] = &EF_e5_tight1_e9_etcut_Jpsi;
      fHandles[ "EF_e60_etcut" ] = &EF_e60_etcut;
      fHandles[ "EF_e60_medium1" ] = &EF_e60_medium1;
      fHandles[ "EF_e7T_loose1" ] = &EF_e7T_loose1;
      fHandles[ "EF_e7T_loose1_2mu6" ] = &EF_e7T_loose1_2mu6;
      fHandles[ "EF_e7T_medium1" ] = &EF_e7T_medium1;
      fHandles[ "EF_e7T_medium1_2mu6" ] = &EF_e7T_medium1_2mu6;
      fHandles[ "EF_e9_tight1_e4_etcut_Jpsi" ] = &EF_e9_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_eb_physics" ] = &EF_eb_physics;
      fHandles[ "EF_eb_physics_empty" ] = &EF_eb_physics_empty;
      fHandles[ "EF_eb_physics_firstempty" ] = &EF_eb_physics_firstempty;
      fHandles[ "EF_eb_physics_noL1PS" ] = &EF_eb_physics_noL1PS;
      fHandles[ "EF_eb_physics_unpaired_iso" ] = &EF_eb_physics_unpaired_iso;
      fHandles[ "EF_eb_physics_unpaired_noniso" ] = &EF_eb_physics_unpaired_noniso;
      fHandles[ "EF_eb_random" ] = &EF_eb_random;
      fHandles[ "EF_eb_random_empty" ] = &EF_eb_random_empty;
      fHandles[ "EF_eb_random_firstempty" ] = &EF_eb_random_firstempty;
      fHandles[ "EF_eb_random_unpaired_iso" ] = &EF_eb_random_unpaired_iso;
      fHandles[ "EF_g100_loose" ] = &EF_g100_loose;
      fHandles[ "EF_g10_NoCut_cosmic" ] = &EF_g10_NoCut_cosmic;
      fHandles[ "EF_g10_loose" ] = &EF_g10_loose;
      fHandles[ "EF_g10_medium" ] = &EF_g10_medium;
      fHandles[ "EF_g120_loose" ] = &EF_g120_loose;
      fHandles[ "EF_g12Tvh_loose" ] = &EF_g12Tvh_loose;
      fHandles[ "EF_g12Tvh_loose_larcalib" ] = &EF_g12Tvh_loose_larcalib;
      fHandles[ "EF_g12Tvh_medium" ] = &EF_g12Tvh_medium;
      fHandles[ "EF_g15_loose" ] = &EF_g15_loose;
      fHandles[ "EF_g15vh_loose" ] = &EF_g15vh_loose;
      fHandles[ "EF_g15vh_medium" ] = &EF_g15vh_medium;
      fHandles[ "EF_g200_etcut" ] = &EF_g200_etcut;
      fHandles[ "EF_g20Tvh_medium" ] = &EF_g20Tvh_medium;
      fHandles[ "EF_g20_etcut" ] = &EF_g20_etcut;
      fHandles[ "EF_g20_loose" ] = &EF_g20_loose;
      fHandles[ "EF_g20_loose_larcalib" ] = &EF_g20_loose_larcalib;
      fHandles[ "EF_g20_medium" ] = &EF_g20_medium;
      fHandles[ "EF_g20vh_medium" ] = &EF_g20vh_medium;
      fHandles[ "EF_g30_loose_g20_loose" ] = &EF_g30_loose_g20_loose;
      fHandles[ "EF_g30_medium_g20_medium" ] = &EF_g30_medium_g20_medium;
      fHandles[ "EF_g35_loose_g25_loose" ] = &EF_g35_loose_g25_loose;
      fHandles[ "EF_g35_loose_g30_loose" ] = &EF_g35_loose_g30_loose;
      fHandles[ "EF_g40_loose" ] = &EF_g40_loose;
      fHandles[ "EF_g40_loose_EFxe50" ] = &EF_g40_loose_EFxe50;
      fHandles[ "EF_g40_loose_L2EFxe50" ] = &EF_g40_loose_L2EFxe50;
      fHandles[ "EF_g40_loose_L2EFxe60" ] = &EF_g40_loose_L2EFxe60;
      fHandles[ "EF_g40_loose_L2EFxe60_tclcw" ] = &EF_g40_loose_L2EFxe60_tclcw;
      fHandles[ "EF_g40_loose_g25_loose" ] = &EF_g40_loose_g25_loose;
      fHandles[ "EF_g40_loose_g30_loose" ] = &EF_g40_loose_g30_loose;
      fHandles[ "EF_g40_loose_larcalib" ] = &EF_g40_loose_larcalib;
      fHandles[ "EF_g5_NoCut_cosmic" ] = &EF_g5_NoCut_cosmic;
      fHandles[ "EF_g60_loose" ] = &EF_g60_loose;
      fHandles[ "EF_g60_loose_larcalib" ] = &EF_g60_loose_larcalib;
      fHandles[ "EF_g80_loose" ] = &EF_g80_loose;
      fHandles[ "EF_g80_loose_larcalib" ] = &EF_g80_loose_larcalib;
      fHandles[ "EF_j10_a4tchadloose" ] = &EF_j10_a4tchadloose;
      fHandles[ "EF_j10_a4tchadloose_L1MBTS" ] = &EF_j10_a4tchadloose_L1MBTS;
      fHandles[ "EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS" ] = &EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS;
      fHandles[ "EF_j110_2j55_a4tchad" ] = &EF_j110_2j55_a4tchad;
      fHandles[ "EF_j110_2j55_a4tchad_L2FS" ] = &EF_j110_2j55_a4tchad_L2FS;
      fHandles[ "EF_j110_a10tcem_L2FS" ] = &EF_j110_a10tcem_L2FS;
      fHandles[ "EF_j110_a10tcem_L2FS_2j55_a4tchad" ] = &EF_j110_a10tcem_L2FS_2j55_a4tchad;
      fHandles[ "EF_j110_a4tchad" ] = &EF_j110_a4tchad;
      fHandles[ "EF_j110_a4tchad_xe100_tclcw" ] = &EF_j110_a4tchad_xe100_tclcw;
      fHandles[ "EF_j110_a4tchad_xe100_tclcw_veryloose" ] = &EF_j110_a4tchad_xe100_tclcw_veryloose;
      fHandles[ "EF_j110_a4tchad_xe50_tclcw" ] = &EF_j110_a4tchad_xe50_tclcw;
      fHandles[ "EF_j110_a4tchad_xe55_tclcw" ] = &EF_j110_a4tchad_xe55_tclcw;
      fHandles[ "EF_j110_a4tchad_xe60_tclcw" ] = &EF_j110_a4tchad_xe60_tclcw;
      fHandles[ "EF_j110_a4tchad_xe60_tclcw_loose" ] = &EF_j110_a4tchad_xe60_tclcw_loose;
      fHandles[ "EF_j110_a4tchad_xe60_tclcw_veryloose" ] = &EF_j110_a4tchad_xe60_tclcw_veryloose;
      fHandles[ "EF_j110_a4tchad_xe65_tclcw" ] = &EF_j110_a4tchad_xe65_tclcw;
      fHandles[ "EF_j110_a4tchad_xe70_tclcw_loose" ] = &EF_j110_a4tchad_xe70_tclcw_loose;
      fHandles[ "EF_j110_a4tchad_xe70_tclcw_veryloose" ] = &EF_j110_a4tchad_xe70_tclcw_veryloose;
      fHandles[ "EF_j110_a4tchad_xe75_tclcw" ] = &EF_j110_a4tchad_xe75_tclcw;
      fHandles[ "EF_j110_a4tchad_xe80_tclcw_loose" ] = &EF_j110_a4tchad_xe80_tclcw_loose;
      fHandles[ "EF_j110_a4tchad_xe90_tclcw_loose" ] = &EF_j110_a4tchad_xe90_tclcw_loose;
      fHandles[ "EF_j110_a4tchad_xe90_tclcw_veryloose" ] = &EF_j110_a4tchad_xe90_tclcw_veryloose;
      fHandles[ "EF_j110_a4tclcw_xe100_tclcw_veryloose" ] = &EF_j110_a4tclcw_xe100_tclcw_veryloose;
      fHandles[ "EF_j145_2j45_a4tchad_L2EFxe70_tclcw" ] = &EF_j145_2j45_a4tchad_L2EFxe70_tclcw;
      fHandles[ "EF_j145_a10tcem_L2FS" ] = &EF_j145_a10tcem_L2FS;
      fHandles[ "EF_j145_a10tcem_L2FS_L2xe60_tclcw" ] = &EF_j145_a10tcem_L2FS_L2xe60_tclcw;
      fHandles[ "EF_j145_a4tchad" ] = &EF_j145_a4tchad;
      fHandles[ "EF_j145_a4tchad_L2EFxe60_tclcw" ] = &EF_j145_a4tchad_L2EFxe60_tclcw;
      fHandles[ "EF_j145_a4tchad_L2EFxe70_tclcw" ] = &EF_j145_a4tchad_L2EFxe70_tclcw;
      fHandles[ "EF_j145_a4tchad_L2EFxe80_tclcw" ] = &EF_j145_a4tchad_L2EFxe80_tclcw;
      fHandles[ "EF_j145_a4tchad_L2EFxe90_tclcw" ] = &EF_j145_a4tchad_L2EFxe90_tclcw;
      fHandles[ "EF_j145_a4tchad_ht500_L2FS" ] = &EF_j145_a4tchad_ht500_L2FS;
      fHandles[ "EF_j145_a4tchad_ht600_L2FS" ] = &EF_j145_a4tchad_ht600_L2FS;
      fHandles[ "EF_j145_a4tchad_ht700_L2FS" ] = &EF_j145_a4tchad_ht700_L2FS;
      fHandles[ "EF_j145_a4tclcw_L2EFxe90_tclcw" ] = &EF_j145_a4tclcw_L2EFxe90_tclcw;
      fHandles[ "EF_j145_j100_j35_a4tchad" ] = &EF_j145_j100_j35_a4tchad;
      fHandles[ "EF_j15_a4tchad" ] = &EF_j15_a4tchad;
      fHandles[ "EF_j15_a4tchad_L1MBTS" ] = &EF_j15_a4tchad_L1MBTS;
      fHandles[ "EF_j15_a4tchad_L1TE20" ] = &EF_j15_a4tchad_L1TE20;
      fHandles[ "EF_j15_fj15_a4tchad_deta50_FC_L1MBTS" ] = &EF_j15_fj15_a4tchad_deta50_FC_L1MBTS;
      fHandles[ "EF_j15_fj15_a4tchad_deta50_FC_L1TE20" ] = &EF_j15_fj15_a4tchad_deta50_FC_L1TE20;
      fHandles[ "EF_j165_u0uchad_LArNoiseBurst" ] = &EF_j165_u0uchad_LArNoiseBurst;
      fHandles[ "EF_j170_a4tchad_EFxe50_tclcw" ] = &EF_j170_a4tchad_EFxe50_tclcw;
      fHandles[ "EF_j170_a4tchad_EFxe60_tclcw" ] = &EF_j170_a4tchad_EFxe60_tclcw;
      fHandles[ "EF_j170_a4tchad_EFxe70_tclcw" ] = &EF_j170_a4tchad_EFxe70_tclcw;
      fHandles[ "EF_j170_a4tchad_EFxe80_tclcw" ] = &EF_j170_a4tchad_EFxe80_tclcw;
      fHandles[ "EF_j170_a4tchad_ht500" ] = &EF_j170_a4tchad_ht500;
      fHandles[ "EF_j170_a4tchad_ht600" ] = &EF_j170_a4tchad_ht600;
      fHandles[ "EF_j170_a4tchad_ht700" ] = &EF_j170_a4tchad_ht700;
      fHandles[ "EF_j180_a10tcem" ] = &EF_j180_a10tcem;
      fHandles[ "EF_j180_a10tcem_EFxe50_tclcw" ] = &EF_j180_a10tcem_EFxe50_tclcw;
      fHandles[ "EF_j180_a10tcem_e45_loose1" ] = &EF_j180_a10tcem_e45_loose1;
      fHandles[ "EF_j180_a10tclcw_EFxe50_tclcw" ] = &EF_j180_a10tclcw_EFxe50_tclcw;
      fHandles[ "EF_j180_a4tchad" ] = &EF_j180_a4tchad;
      fHandles[ "EF_j180_a4tclcw" ] = &EF_j180_a4tclcw;
      fHandles[ "EF_j180_a4tthad" ] = &EF_j180_a4tthad;
      fHandles[ "EF_j220_a10tcem_e45_etcut" ] = &EF_j220_a10tcem_e45_etcut;
      fHandles[ "EF_j220_a10tcem_e45_loose1" ] = &EF_j220_a10tcem_e45_loose1;
      fHandles[ "EF_j220_a10tcem_e60_etcut" ] = &EF_j220_a10tcem_e60_etcut;
      fHandles[ "EF_j220_a4tchad" ] = &EF_j220_a4tchad;
      fHandles[ "EF_j220_a4tthad" ] = &EF_j220_a4tthad;
      fHandles[ "EF_j240_a10tcem" ] = &EF_j240_a10tcem;
      fHandles[ "EF_j240_a10tcem_e45_etcut" ] = &EF_j240_a10tcem_e45_etcut;
      fHandles[ "EF_j240_a10tcem_e45_loose1" ] = &EF_j240_a10tcem_e45_loose1;
      fHandles[ "EF_j240_a10tcem_e60_etcut" ] = &EF_j240_a10tcem_e60_etcut;
      fHandles[ "EF_j240_a10tcem_e60_loose1" ] = &EF_j240_a10tcem_e60_loose1;
      fHandles[ "EF_j240_a10tclcw" ] = &EF_j240_a10tclcw;
      fHandles[ "EF_j25_a4tchad" ] = &EF_j25_a4tchad;
      fHandles[ "EF_j25_a4tchad_L1MBTS" ] = &EF_j25_a4tchad_L1MBTS;
      fHandles[ "EF_j25_a4tchad_L1TE20" ] = &EF_j25_a4tchad_L1TE20;
      fHandles[ "EF_j25_fj25_a4tchad_deta50_FC_L1MBTS" ] = &EF_j25_fj25_a4tchad_deta50_FC_L1MBTS;
      fHandles[ "EF_j25_fj25_a4tchad_deta50_FC_L1TE20" ] = &EF_j25_fj25_a4tchad_deta50_FC_L1TE20;
      fHandles[ "EF_j260_a4tthad" ] = &EF_j260_a4tthad;
      fHandles[ "EF_j280_a10tclcw_L2FS" ] = &EF_j280_a10tclcw_L2FS;
      fHandles[ "EF_j280_a4tchad" ] = &EF_j280_a4tchad;
      fHandles[ "EF_j280_a4tchad_mjj2000dy34" ] = &EF_j280_a4tchad_mjj2000dy34;
      fHandles[ "EF_j30_a4tcem_eta13_xe30_empty" ] = &EF_j30_a4tcem_eta13_xe30_empty;
      fHandles[ "EF_j30_a4tcem_eta13_xe30_firstempty" ] = &EF_j30_a4tcem_eta13_xe30_firstempty;
      fHandles[ "EF_j30_u0uchad_empty_LArNoiseBurst" ] = &EF_j30_u0uchad_empty_LArNoiseBurst;
      fHandles[ "EF_j35_a10tcem" ] = &EF_j35_a10tcem;
      fHandles[ "EF_j35_a4tcem_L1TAU_LOF_HV" ] = &EF_j35_a4tcem_L1TAU_LOF_HV;
      fHandles[ "EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY" ] = &EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY;
      fHandles[ "EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO" ] = &EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO;
      fHandles[ "EF_j35_a4tchad" ] = &EF_j35_a4tchad;
      fHandles[ "EF_j35_a4tchad_L1MBTS" ] = &EF_j35_a4tchad_L1MBTS;
      fHandles[ "EF_j35_a4tchad_L1TE20" ] = &EF_j35_a4tchad_L1TE20;
      fHandles[ "EF_j35_a4tclcw" ] = &EF_j35_a4tclcw;
      fHandles[ "EF_j35_a4tthad" ] = &EF_j35_a4tthad;
      fHandles[ "EF_j35_fj35_a4tchad_deta50_FC_L1MBTS" ] = &EF_j35_fj35_a4tchad_deta50_FC_L1MBTS;
      fHandles[ "EF_j35_fj35_a4tchad_deta50_FC_L1TE20" ] = &EF_j35_fj35_a4tchad_deta50_FC_L1TE20;
      fHandles[ "EF_j360_a10tcem" ] = &EF_j360_a10tcem;
      fHandles[ "EF_j360_a10tclcw" ] = &EF_j360_a10tclcw;
      fHandles[ "EF_j360_a4tchad" ] = &EF_j360_a4tchad;
      fHandles[ "EF_j360_a4tclcw" ] = &EF_j360_a4tclcw;
      fHandles[ "EF_j360_a4tthad" ] = &EF_j360_a4tthad;
      fHandles[ "EF_j380_a4tthad" ] = &EF_j380_a4tthad;
      fHandles[ "EF_j45_a10tcem_L1RD0" ] = &EF_j45_a10tcem_L1RD0;
      fHandles[ "EF_j45_a4tchad" ] = &EF_j45_a4tchad;
      fHandles[ "EF_j45_a4tchad_L1RD0" ] = &EF_j45_a4tchad_L1RD0;
      fHandles[ "EF_j45_a4tchad_L2FS" ] = &EF_j45_a4tchad_L2FS;
      fHandles[ "EF_j45_a4tchad_L2FS_L1RD0" ] = &EF_j45_a4tchad_L2FS_L1RD0;
      fHandles[ "EF_j460_a10tcem" ] = &EF_j460_a10tcem;
      fHandles[ "EF_j460_a10tclcw" ] = &EF_j460_a10tclcw;
      fHandles[ "EF_j460_a4tchad" ] = &EF_j460_a4tchad;
      fHandles[ "EF_j50_a4tcem_eta13_xe50_empty" ] = &EF_j50_a4tcem_eta13_xe50_empty;
      fHandles[ "EF_j50_a4tcem_eta13_xe50_firstempty" ] = &EF_j50_a4tcem_eta13_xe50_firstempty;
      fHandles[ "EF_j50_a4tcem_eta25_xe50_empty" ] = &EF_j50_a4tcem_eta25_xe50_empty;
      fHandles[ "EF_j50_a4tcem_eta25_xe50_firstempty" ] = &EF_j50_a4tcem_eta25_xe50_firstempty;
      fHandles[ "EF_j55_a4tchad" ] = &EF_j55_a4tchad;
      fHandles[ "EF_j55_a4tchad_L2FS" ] = &EF_j55_a4tchad_L2FS;
      fHandles[ "EF_j55_a4tclcw" ] = &EF_j55_a4tclcw;
      fHandles[ "EF_j55_u0uchad_firstempty_LArNoiseBurst" ] = &EF_j55_u0uchad_firstempty_LArNoiseBurst;
      fHandles[ "EF_j65_a4tchad_L2FS" ] = &EF_j65_a4tchad_L2FS;
      fHandles[ "EF_j80_a10tcem_L2FS" ] = &EF_j80_a10tcem_L2FS;
      fHandles[ "EF_j80_a4tchad" ] = &EF_j80_a4tchad;
      fHandles[ "EF_j80_a4tchad_xe100_tclcw_loose" ] = &EF_j80_a4tchad_xe100_tclcw_loose;
      fHandles[ "EF_j80_a4tchad_xe100_tclcw_veryloose" ] = &EF_j80_a4tchad_xe100_tclcw_veryloose;
      fHandles[ "EF_j80_a4tchad_xe55_tclcw" ] = &EF_j80_a4tchad_xe55_tclcw;
      fHandles[ "EF_j80_a4tchad_xe60_tclcw" ] = &EF_j80_a4tchad_xe60_tclcw;
      fHandles[ "EF_j80_a4tchad_xe70_tclcw" ] = &EF_j80_a4tchad_xe70_tclcw;
      fHandles[ "EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10" ] = &EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10;
      fHandles[ "EF_j80_a4tchad_xe70_tclcw_loose" ] = &EF_j80_a4tchad_xe70_tclcw_loose;
      fHandles[ "EF_j80_a4tchad_xe80_tclcw_loose" ] = &EF_j80_a4tchad_xe80_tclcw_loose;
      fHandles[ "EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10" ] = &EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10;
      fHandles[ "EF_mu10" ] = &EF_mu10;
      fHandles[ "EF_mu10_Jpsimumu" ] = &EF_mu10_Jpsimumu;
      fHandles[ "EF_mu10_MSonly" ] = &EF_mu10_MSonly;
      fHandles[ "EF_mu10_Upsimumu_tight_FS" ] = &EF_mu10_Upsimumu_tight_FS;
      fHandles[ "EF_mu10i_g10_loose" ] = &EF_mu10i_g10_loose;
      fHandles[ "EF_mu10i_g10_loose_TauMass" ] = &EF_mu10i_g10_loose_TauMass;
      fHandles[ "EF_mu10i_g10_medium" ] = &EF_mu10i_g10_medium;
      fHandles[ "EF_mu10i_g10_medium_TauMass" ] = &EF_mu10i_g10_medium_TauMass;
      fHandles[ "EF_mu10i_loose_g12Tvh_loose" ] = &EF_mu10i_loose_g12Tvh_loose;
      fHandles[ "EF_mu10i_loose_g12Tvh_loose_TauMass" ] = &EF_mu10i_loose_g12Tvh_loose_TauMass;
      fHandles[ "EF_mu10i_loose_g12Tvh_medium" ] = &EF_mu10i_loose_g12Tvh_medium;
      fHandles[ "EF_mu10i_loose_g12Tvh_medium_TauMass" ] = &EF_mu10i_loose_g12Tvh_medium_TauMass;
      fHandles[ "EF_mu11_empty_NoAlg" ] = &EF_mu11_empty_NoAlg;
      fHandles[ "EF_mu13" ] = &EF_mu13;
      fHandles[ "EF_mu15" ] = &EF_mu15;
      fHandles[ "EF_mu18" ] = &EF_mu18;
      fHandles[ "EF_mu18_2g10_loose" ] = &EF_mu18_2g10_loose;
      fHandles[ "EF_mu18_2g10_medium" ] = &EF_mu18_2g10_medium;
      fHandles[ "EF_mu18_2g15_loose" ] = &EF_mu18_2g15_loose;
      fHandles[ "EF_mu18_IDTrkNoCut_tight" ] = &EF_mu18_IDTrkNoCut_tight;
      fHandles[ "EF_mu18_g20vh_loose" ] = &EF_mu18_g20vh_loose;
      fHandles[ "EF_mu18_medium" ] = &EF_mu18_medium;
      fHandles[ "EF_mu18_tight" ] = &EF_mu18_tight;
      fHandles[ "EF_mu18_tight_2mu4_EFFS" ] = &EF_mu18_tight_2mu4_EFFS;
      fHandles[ "EF_mu18_tight_e7_medium1" ] = &EF_mu18_tight_e7_medium1;
      fHandles[ "EF_mu18_tight_mu8_EFFS" ] = &EF_mu18_tight_mu8_EFFS;
      fHandles[ "EF_mu18i4_tight" ] = &EF_mu18i4_tight;
      fHandles[ "EF_mu18it_tight" ] = &EF_mu18it_tight;
      fHandles[ "EF_mu20i_tight_g5_loose" ] = &EF_mu20i_tight_g5_loose;
      fHandles[ "EF_mu20i_tight_g5_loose_TauMass" ] = &EF_mu20i_tight_g5_loose_TauMass;
      fHandles[ "EF_mu20i_tight_g5_medium" ] = &EF_mu20i_tight_g5_medium;
      fHandles[ "EF_mu20i_tight_g5_medium_TauMass" ] = &EF_mu20i_tight_g5_medium_TauMass;
      fHandles[ "EF_mu20it_tight" ] = &EF_mu20it_tight;
      fHandles[ "EF_mu22_IDTrkNoCut_tight" ] = &EF_mu22_IDTrkNoCut_tight;
      fHandles[ "EF_mu24" ] = &EF_mu24;
      fHandles[ "EF_mu24_g20vh_loose" ] = &EF_mu24_g20vh_loose;
      fHandles[ "EF_mu24_g20vh_medium" ] = &EF_mu24_g20vh_medium;
      fHandles[ "EF_mu24_j65_a4tchad" ] = &EF_mu24_j65_a4tchad;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe40" ] = &EF_mu24_j65_a4tchad_EFxe40;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe40_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe40_tclcw;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe50_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe50_tclcw;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe60_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe60_tclcw;
      fHandles[ "EF_mu24_medium" ] = &EF_mu24_medium;
      fHandles[ "EF_mu24_muCombTag_NoEF_tight" ] = &EF_mu24_muCombTag_NoEF_tight;
      fHandles[ "EF_mu24_tight" ] = &EF_mu24_tight;
      fHandles[ "EF_mu24_tight_2j35_a4tchad" ] = &EF_mu24_tight_2j35_a4tchad;
      fHandles[ "EF_mu24_tight_3j35_a4tchad" ] = &EF_mu24_tight_3j35_a4tchad;
      fHandles[ "EF_mu24_tight_4j35_a4tchad" ] = &EF_mu24_tight_4j35_a4tchad;
      fHandles[ "EF_mu24_tight_EFxe40" ] = &EF_mu24_tight_EFxe40;
      fHandles[ "EF_mu24_tight_L2StarB" ] = &EF_mu24_tight_L2StarB;
      fHandles[ "EF_mu24_tight_L2StarC" ] = &EF_mu24_tight_L2StarC;
      fHandles[ "EF_mu24_tight_MG" ] = &EF_mu24_tight_MG;
      fHandles[ "EF_mu24_tight_MuonEF" ] = &EF_mu24_tight_MuonEF;
      fHandles[ "EF_mu24_tight_b35_mediumEF_j35_a4tchad" ] = &EF_mu24_tight_b35_mediumEF_j35_a4tchad;
      fHandles[ "EF_mu24_tight_mu6_EFFS" ] = &EF_mu24_tight_mu6_EFFS;
      fHandles[ "EF_mu24i_tight" ] = &EF_mu24i_tight;
      fHandles[ "EF_mu24i_tight_MG" ] = &EF_mu24i_tight_MG;
      fHandles[ "EF_mu24i_tight_MuonEF" ] = &EF_mu24i_tight_MuonEF;
      fHandles[ "EF_mu24i_tight_l2muonSA" ] = &EF_mu24i_tight_l2muonSA;
      fHandles[ "EF_mu36_tight" ] = &EF_mu36_tight;
      fHandles[ "EF_mu40_MSonly_barrel_tight" ] = &EF_mu40_MSonly_barrel_tight;
      fHandles[ "EF_mu40_muCombTag_NoEF" ] = &EF_mu40_muCombTag_NoEF;
      fHandles[ "EF_mu40_slow_outOfTime_tight" ] = &EF_mu40_slow_outOfTime_tight;
      fHandles[ "EF_mu40_slow_tight" ] = &EF_mu40_slow_tight;
      fHandles[ "EF_mu40_tight" ] = &EF_mu40_tight;
      fHandles[ "EF_mu4T" ] = &EF_mu4T;
      fHandles[ "EF_mu4T_Trk_Jpsi" ] = &EF_mu4T_Trk_Jpsi;
      fHandles[ "EF_mu4T_cosmic" ] = &EF_mu4T_cosmic;
      fHandles[ "EF_mu4T_j110_a4tchad_L2FS_matched" ] = &EF_mu4T_j110_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j110_a4tchad_matched" ] = &EF_mu4T_j110_a4tchad_matched;
      fHandles[ "EF_mu4T_j145_a4tchad_L2FS_matched" ] = &EF_mu4T_j145_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j145_a4tchad_matched" ] = &EF_mu4T_j145_a4tchad_matched;
      fHandles[ "EF_mu4T_j15_a4tchad_matched" ] = &EF_mu4T_j15_a4tchad_matched;
      fHandles[ "EF_mu4T_j15_a4tchad_matchedZ" ] = &EF_mu4T_j15_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j180_a4tchad_L2FS_matched" ] = &EF_mu4T_j180_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j180_a4tchad_matched" ] = &EF_mu4T_j180_a4tchad_matched;
      fHandles[ "EF_mu4T_j220_a4tchad_L2FS_matched" ] = &EF_mu4T_j220_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j220_a4tchad_matched" ] = &EF_mu4T_j220_a4tchad_matched;
      fHandles[ "EF_mu4T_j25_a4tchad_matched" ] = &EF_mu4T_j25_a4tchad_matched;
      fHandles[ "EF_mu4T_j25_a4tchad_matchedZ" ] = &EF_mu4T_j25_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j280_a4tchad_L2FS_matched" ] = &EF_mu4T_j280_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j280_a4tchad_matched" ] = &EF_mu4T_j280_a4tchad_matched;
      fHandles[ "EF_mu4T_j35_a4tchad_matched" ] = &EF_mu4T_j35_a4tchad_matched;
      fHandles[ "EF_mu4T_j35_a4tchad_matchedZ" ] = &EF_mu4T_j35_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j360_a4tchad_L2FS_matched" ] = &EF_mu4T_j360_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j360_a4tchad_matched" ] = &EF_mu4T_j360_a4tchad_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_L2FS_matched" ] = &EF_mu4T_j45_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_L2FS_matchedZ" ] = &EF_mu4T_j45_a4tchad_L2FS_matchedZ;
      fHandles[ "EF_mu4T_j45_a4tchad_matched" ] = &EF_mu4T_j45_a4tchad_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_matchedZ" ] = &EF_mu4T_j45_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j55_a4tchad_L2FS_matched" ] = &EF_mu4T_j55_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j55_a4tchad_L2FS_matchedZ" ] = &EF_mu4T_j55_a4tchad_L2FS_matchedZ;
      fHandles[ "EF_mu4T_j55_a4tchad_matched" ] = &EF_mu4T_j55_a4tchad_matched;
      fHandles[ "EF_mu4T_j55_a4tchad_matchedZ" ] = &EF_mu4T_j55_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j65_a4tchad_L2FS_matched" ] = &EF_mu4T_j65_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j65_a4tchad_matched" ] = &EF_mu4T_j65_a4tchad_matched;
      fHandles[ "EF_mu4T_j65_a4tchad_xe60_tclcw_loose" ] = &EF_mu4T_j65_a4tchad_xe60_tclcw_loose;
      fHandles[ "EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose" ] = &EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;
      fHandles[ "EF_mu4T_j80_a4tchad_L2FS_matched" ] = &EF_mu4T_j80_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j80_a4tchad_matched" ] = &EF_mu4T_j80_a4tchad_matched;
      fHandles[ "EF_mu4Ti_g20Tvh_loose" ] = &EF_mu4Ti_g20Tvh_loose;
      fHandles[ "EF_mu4Ti_g20Tvh_loose_TauMass" ] = &EF_mu4Ti_g20Tvh_loose_TauMass;
      fHandles[ "EF_mu4Ti_g20Tvh_medium" ] = &EF_mu4Ti_g20Tvh_medium;
      fHandles[ "EF_mu4Ti_g20Tvh_medium_TauMass" ] = &EF_mu4Ti_g20Tvh_medium_TauMass;
      fHandles[ "EF_mu4Tmu6_Bmumu" ] = &EF_mu4Tmu6_Bmumu;
      fHandles[ "EF_mu4Tmu6_Bmumu_Barrel" ] = &EF_mu4Tmu6_Bmumu_Barrel;
      fHandles[ "EF_mu4Tmu6_Bmumux" ] = &EF_mu4Tmu6_Bmumux;
      fHandles[ "EF_mu4Tmu6_Bmumux_Barrel" ] = &EF_mu4Tmu6_Bmumux_Barrel;
      fHandles[ "EF_mu4Tmu6_DiMu" ] = &EF_mu4Tmu6_DiMu;
      fHandles[ "EF_mu4Tmu6_DiMu_Barrel" ] = &EF_mu4Tmu6_DiMu_Barrel;
      fHandles[ "EF_mu4Tmu6_DiMu_noVtx_noOS" ] = &EF_mu4Tmu6_DiMu_noVtx_noOS;
      fHandles[ "EF_mu4Tmu6_Jpsimumu" ] = &EF_mu4Tmu6_Jpsimumu;
      fHandles[ "EF_mu4Tmu6_Jpsimumu_Barrel" ] = &EF_mu4Tmu6_Jpsimumu_Barrel;
      fHandles[ "EF_mu4Tmu6_Jpsimumu_IDTrkNoCut" ] = &EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;
      fHandles[ "EF_mu4Tmu6_Upsimumu" ] = &EF_mu4Tmu6_Upsimumu;
      fHandles[ "EF_mu4Tmu6_Upsimumu_Barrel" ] = &EF_mu4Tmu6_Upsimumu_Barrel;
      fHandles[ "EF_mu4_L1MU11_MSonly_cosmic" ] = &EF_mu4_L1MU11_MSonly_cosmic;
      fHandles[ "EF_mu4_L1MU11_cosmic" ] = &EF_mu4_L1MU11_cosmic;
      fHandles[ "EF_mu4_empty_NoAlg" ] = &EF_mu4_empty_NoAlg;
      fHandles[ "EF_mu4_firstempty_NoAlg" ] = &EF_mu4_firstempty_NoAlg;
      fHandles[ "EF_mu4_unpaired_iso_NoAlg" ] = &EF_mu4_unpaired_iso_NoAlg;
      fHandles[ "EF_mu50_MSonly_barrel_tight" ] = &EF_mu50_MSonly_barrel_tight;
      fHandles[ "EF_mu6" ] = &EF_mu6;
      fHandles[ "EF_mu60_slow_outOfTime_tight1" ] = &EF_mu60_slow_outOfTime_tight1;
      fHandles[ "EF_mu60_slow_tight1" ] = &EF_mu60_slow_tight1;
      fHandles[ "EF_mu6_Jpsimumu_tight" ] = &EF_mu6_Jpsimumu_tight;
      fHandles[ "EF_mu6_MSonly" ] = &EF_mu6_MSonly;
      fHandles[ "EF_mu6_Trk_Jpsi_loose" ] = &EF_mu6_Trk_Jpsi_loose;
      fHandles[ "EF_mu6i" ] = &EF_mu6i;
      fHandles[ "EF_mu8" ] = &EF_mu8;
      fHandles[ "EF_mu8_4j45_a4tchad_L2FS" ] = &EF_mu8_4j45_a4tchad_L2FS;
      fHandles[ "EF_tau125_IDTrkNoCut" ] = &EF_tau125_IDTrkNoCut;
      fHandles[ "EF_tau125_medium1" ] = &EF_tau125_medium1;
      fHandles[ "EF_tau125_medium1_L2StarA" ] = &EF_tau125_medium1_L2StarA;
      fHandles[ "EF_tau125_medium1_L2StarB" ] = &EF_tau125_medium1_L2StarB;
      fHandles[ "EF_tau125_medium1_L2StarC" ] = &EF_tau125_medium1_L2StarC;
      fHandles[ "EF_tau125_medium1_llh" ] = &EF_tau125_medium1_llh;
      fHandles[ "EF_tau20T_medium" ] = &EF_tau20T_medium;
      fHandles[ "EF_tau20T_medium1" ] = &EF_tau20T_medium1;
      fHandles[ "EF_tau20T_medium1_e15vh_medium1" ] = &EF_tau20T_medium1_e15vh_medium1;
      fHandles[ "EF_tau20T_medium1_mu15i" ] = &EF_tau20T_medium1_mu15i;
      fHandles[ "EF_tau20T_medium_mu15" ] = &EF_tau20T_medium_mu15;
      fHandles[ "EF_tau20Ti_medium" ] = &EF_tau20Ti_medium;
      fHandles[ "EF_tau20Ti_medium1" ] = &EF_tau20Ti_medium1;
      fHandles[ "EF_tau20Ti_medium1_e18vh_medium1" ] = &EF_tau20Ti_medium1_e18vh_medium1;
      fHandles[ "EF_tau20Ti_medium1_llh_e18vh_medium1" ] = &EF_tau20Ti_medium1_llh_e18vh_medium1;
      fHandles[ "EF_tau20Ti_medium_e18vh_medium1" ] = &EF_tau20Ti_medium_e18vh_medium1;
      fHandles[ "EF_tau20Ti_tight1" ] = &EF_tau20Ti_tight1;
      fHandles[ "EF_tau20Ti_tight1_llh" ] = &EF_tau20Ti_tight1_llh;
      fHandles[ "EF_tau20_medium" ] = &EF_tau20_medium;
      fHandles[ "EF_tau20_medium1" ] = &EF_tau20_medium1;
      fHandles[ "EF_tau20_medium1_llh" ] = &EF_tau20_medium1_llh;
      fHandles[ "EF_tau20_medium1_llh_mu15" ] = &EF_tau20_medium1_llh_mu15;
      fHandles[ "EF_tau20_medium1_mu15" ] = &EF_tau20_medium1_mu15;
      fHandles[ "EF_tau20_medium1_mu15i" ] = &EF_tau20_medium1_mu15i;
      fHandles[ "EF_tau20_medium1_mu18" ] = &EF_tau20_medium1_mu18;
      fHandles[ "EF_tau20_medium_llh" ] = &EF_tau20_medium_llh;
      fHandles[ "EF_tau20_medium_mu15" ] = &EF_tau20_medium_mu15;
      fHandles[ "EF_tau29T_medium" ] = &EF_tau29T_medium;
      fHandles[ "EF_tau29T_medium1" ] = &EF_tau29T_medium1;
      fHandles[ "EF_tau29T_medium1_tau20T_medium1" ] = &EF_tau29T_medium1_tau20T_medium1;
      fHandles[ "EF_tau29T_medium1_xe40_tight" ] = &EF_tau29T_medium1_xe40_tight;
      fHandles[ "EF_tau29T_medium1_xe45_tight" ] = &EF_tau29T_medium1_xe45_tight;
      fHandles[ "EF_tau29T_medium_xe40_tight" ] = &EF_tau29T_medium_xe40_tight;
      fHandles[ "EF_tau29T_medium_xe45_tight" ] = &EF_tau29T_medium_xe45_tight;
      fHandles[ "EF_tau29T_tight1" ] = &EF_tau29T_tight1;
      fHandles[ "EF_tau29T_tight1_llh" ] = &EF_tau29T_tight1_llh;
      fHandles[ "EF_tau29Ti_medium1" ] = &EF_tau29Ti_medium1;
      fHandles[ "EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh" ] = &EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh;
      fHandles[ "EF_tau29Ti_medium1_llh_xe40_tight" ] = &EF_tau29Ti_medium1_llh_xe40_tight;
      fHandles[ "EF_tau29Ti_medium1_llh_xe45_tight" ] = &EF_tau29Ti_medium1_llh_xe45_tight;
      fHandles[ "EF_tau29Ti_medium1_tau20Ti_medium1" ] = &EF_tau29Ti_medium1_tau20Ti_medium1;
      fHandles[ "EF_tau29Ti_medium1_xe40_tight" ] = &EF_tau29Ti_medium1_xe40_tight;
      fHandles[ "EF_tau29Ti_medium1_xe45_tight" ] = &EF_tau29Ti_medium1_xe45_tight;
      fHandles[ "EF_tau29Ti_medium1_xe55_tclcw" ] = &EF_tau29Ti_medium1_xe55_tclcw;
      fHandles[ "EF_tau29Ti_medium1_xe55_tclcw_tight" ] = &EF_tau29Ti_medium1_xe55_tclcw_tight;
      fHandles[ "EF_tau29Ti_medium_xe40_tight" ] = &EF_tau29Ti_medium_xe40_tight;
      fHandles[ "EF_tau29Ti_medium_xe45_tight" ] = &EF_tau29Ti_medium_xe45_tight;
      fHandles[ "EF_tau29Ti_tight1" ] = &EF_tau29Ti_tight1;
      fHandles[ "EF_tau29Ti_tight1_llh" ] = &EF_tau29Ti_tight1_llh;
      fHandles[ "EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh" ] = &EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh;
      fHandles[ "EF_tau29Ti_tight1_tau20Ti_tight1" ] = &EF_tau29Ti_tight1_tau20Ti_tight1;
      fHandles[ "EF_tau29_IDTrkNoCut" ] = &EF_tau29_IDTrkNoCut;
      fHandles[ "EF_tau29_medium" ] = &EF_tau29_medium;
      fHandles[ "EF_tau29_medium1" ] = &EF_tau29_medium1;
      fHandles[ "EF_tau29_medium1_llh" ] = &EF_tau29_medium1_llh;
      fHandles[ "EF_tau29_medium_2stTest" ] = &EF_tau29_medium_2stTest;
      fHandles[ "EF_tau29_medium_L2StarA" ] = &EF_tau29_medium_L2StarA;
      fHandles[ "EF_tau29_medium_L2StarB" ] = &EF_tau29_medium_L2StarB;
      fHandles[ "EF_tau29_medium_L2StarC" ] = &EF_tau29_medium_L2StarC;
      fHandles[ "EF_tau29_medium_llh" ] = &EF_tau29_medium_llh;
      fHandles[ "EF_tau29i_medium" ] = &EF_tau29i_medium;
      fHandles[ "EF_tau29i_medium1" ] = &EF_tau29i_medium1;
      fHandles[ "EF_tau38T_medium" ] = &EF_tau38T_medium;
      fHandles[ "EF_tau38T_medium1" ] = &EF_tau38T_medium1;
      fHandles[ "EF_tau38T_medium1_e18vh_medium1" ] = &EF_tau38T_medium1_e18vh_medium1;
      fHandles[ "EF_tau38T_medium1_llh_e18vh_medium1" ] = &EF_tau38T_medium1_llh_e18vh_medium1;
      fHandles[ "EF_tau38T_medium1_xe40_tight" ] = &EF_tau38T_medium1_xe40_tight;
      fHandles[ "EF_tau38T_medium1_xe45_tight" ] = &EF_tau38T_medium1_xe45_tight;
      fHandles[ "EF_tau38T_medium1_xe55_tclcw_tight" ] = &EF_tau38T_medium1_xe55_tclcw_tight;
      fHandles[ "EF_tau38T_medium_e18vh_medium1" ] = &EF_tau38T_medium_e18vh_medium1;
      fHandles[ "EF_tau50_medium" ] = &EF_tau50_medium;
      fHandles[ "EF_tau50_medium1_e18vh_medium1" ] = &EF_tau50_medium1_e18vh_medium1;
      fHandles[ "EF_tau50_medium_e15vh_medium1" ] = &EF_tau50_medium_e15vh_medium1;
      fHandles[ "EF_tauNoCut" ] = &EF_tauNoCut;
      fHandles[ "EF_tauNoCut_L1TAU40" ] = &EF_tauNoCut_L1TAU40;
      fHandles[ "EF_tauNoCut_cosmic" ] = &EF_tauNoCut_cosmic;
      fHandles[ "EF_xe100" ] = &EF_xe100;
      fHandles[ "EF_xe100T_tclcw" ] = &EF_xe100T_tclcw;
      fHandles[ "EF_xe100T_tclcw_loose" ] = &EF_xe100T_tclcw_loose;
      fHandles[ "EF_xe100_tclcw" ] = &EF_xe100_tclcw;
      fHandles[ "EF_xe100_tclcw_loose" ] = &EF_xe100_tclcw_loose;
      fHandles[ "EF_xe100_tclcw_veryloose" ] = &EF_xe100_tclcw_veryloose;
      fHandles[ "EF_xe100_tclcw_verytight" ] = &EF_xe100_tclcw_verytight;
      fHandles[ "EF_xe100_tight" ] = &EF_xe100_tight;
      fHandles[ "EF_xe110" ] = &EF_xe110;
      fHandles[ "EF_xe30" ] = &EF_xe30;
      fHandles[ "EF_xe30_tclcw" ] = &EF_xe30_tclcw;
      fHandles[ "EF_xe40" ] = &EF_xe40;
      fHandles[ "EF_xe50" ] = &EF_xe50;
      fHandles[ "EF_xe55_LArNoiseBurst" ] = &EF_xe55_LArNoiseBurst;
      fHandles[ "EF_xe55_tclcw" ] = &EF_xe55_tclcw;
      fHandles[ "EF_xe60" ] = &EF_xe60;
      fHandles[ "EF_xe60T" ] = &EF_xe60T;
      fHandles[ "EF_xe60_tclcw" ] = &EF_xe60_tclcw;
      fHandles[ "EF_xe60_tclcw_loose" ] = &EF_xe60_tclcw_loose;
      fHandles[ "EF_xe70" ] = &EF_xe70;
      fHandles[ "EF_xe70_tclcw_loose" ] = &EF_xe70_tclcw_loose;
      fHandles[ "EF_xe70_tclcw_veryloose" ] = &EF_xe70_tclcw_veryloose;
      fHandles[ "EF_xe70_tight" ] = &EF_xe70_tight;
      fHandles[ "EF_xe70_tight_tclcw" ] = &EF_xe70_tight_tclcw;
      fHandles[ "EF_xe75_tclcw" ] = &EF_xe75_tclcw;
      fHandles[ "EF_xe80" ] = &EF_xe80;
      fHandles[ "EF_xe80T" ] = &EF_xe80T;
      fHandles[ "EF_xe80T_loose" ] = &EF_xe80T_loose;
      fHandles[ "EF_xe80T_tclcw" ] = &EF_xe80T_tclcw;
      fHandles[ "EF_xe80T_tclcw_loose" ] = &EF_xe80T_tclcw_loose;
      fHandles[ "EF_xe80_tclcw" ] = &EF_xe80_tclcw;
      fHandles[ "EF_xe80_tclcw_loose" ] = &EF_xe80_tclcw_loose;
      fHandles[ "EF_xe80_tclcw_tight" ] = &EF_xe80_tclcw_tight;
      fHandles[ "EF_xe80_tclcw_verytight" ] = &EF_xe80_tclcw_verytight;
      fHandles[ "EF_xe80_tight" ] = &EF_xe80_tight;
      fHandles[ "EF_xe90" ] = &EF_xe90;
      fHandles[ "EF_xe90_tclcw" ] = &EF_xe90_tclcw;
      fHandles[ "EF_xe90_tclcw_tight" ] = &EF_xe90_tclcw_tight;
      fHandles[ "EF_xe90_tclcw_veryloose" ] = &EF_xe90_tclcw_veryloose;
      fHandles[ "EF_xe90_tclcw_verytight" ] = &EF_xe90_tclcw_verytight;
      fHandles[ "EF_xe90_tight" ] = &EF_xe90_tight;
      fHandles[ "L1_2EM10VH" ] = &L1_2EM10VH;
      fHandles[ "L1_2EM12" ] = &L1_2EM12;
      fHandles[ "L1_2EM12_EM16V" ] = &L1_2EM12_EM16V;
      fHandles[ "L1_2EM3" ] = &L1_2EM3;
      fHandles[ "L1_2EM3_EM12" ] = &L1_2EM3_EM12;
      fHandles[ "L1_2EM3_EM6" ] = &L1_2EM3_EM6;
      fHandles[ "L1_2EM6" ] = &L1_2EM6;
      fHandles[ "L1_2EM6_EM16VH" ] = &L1_2EM6_EM16VH;
      fHandles[ "L1_2EM6_MU6" ] = &L1_2EM6_MU6;
      fHandles[ "L1_2J20_XE20" ] = &L1_2J20_XE20;
      fHandles[ "L1_2J30_XE20" ] = &L1_2J30_XE20;
      fHandles[ "L1_2MU10" ] = &L1_2MU10;
      fHandles[ "L1_2MU4" ] = &L1_2MU4;
      fHandles[ "L1_2MU4_2EM3" ] = &L1_2MU4_2EM3;
      fHandles[ "L1_2MU4_BARREL" ] = &L1_2MU4_BARREL;
      fHandles[ "L1_2MU4_BARRELONLY" ] = &L1_2MU4_BARRELONLY;
      fHandles[ "L1_2MU4_EM3" ] = &L1_2MU4_EM3;
      fHandles[ "L1_2MU4_EMPTY" ] = &L1_2MU4_EMPTY;
      fHandles[ "L1_2MU4_FIRSTEMPTY" ] = &L1_2MU4_FIRSTEMPTY;
      fHandles[ "L1_2MU4_MU6" ] = &L1_2MU4_MU6;
      fHandles[ "L1_2MU4_MU6_BARREL" ] = &L1_2MU4_MU6_BARREL;
      fHandles[ "L1_2MU4_XE30" ] = &L1_2MU4_XE30;
      fHandles[ "L1_2MU4_XE40" ] = &L1_2MU4_XE40;
      fHandles[ "L1_2MU6" ] = &L1_2MU6;
      fHandles[ "L1_2MU6_UNPAIRED_ISO" ] = &L1_2MU6_UNPAIRED_ISO;
      fHandles[ "L1_2MU6_UNPAIRED_NONISO" ] = &L1_2MU6_UNPAIRED_NONISO;
      fHandles[ "L1_2TAU11" ] = &L1_2TAU11;
      fHandles[ "L1_2TAU11I" ] = &L1_2TAU11I;
      fHandles[ "L1_2TAU11I_EM14VH" ] = &L1_2TAU11I_EM14VH;
      fHandles[ "L1_2TAU11I_TAU15" ] = &L1_2TAU11I_TAU15;
      fHandles[ "L1_2TAU11_EM10VH" ] = &L1_2TAU11_EM10VH;
      fHandles[ "L1_2TAU11_TAU15" ] = &L1_2TAU11_TAU15;
      fHandles[ "L1_2TAU11_TAU20_EM10VH" ] = &L1_2TAU11_TAU20_EM10VH;
      fHandles[ "L1_2TAU11_TAU20_EM14VH" ] = &L1_2TAU11_TAU20_EM14VH;
      fHandles[ "L1_2TAU15" ] = &L1_2TAU15;
      fHandles[ "L1_2TAU20" ] = &L1_2TAU20;
      fHandles[ "L1_EM10VH" ] = &L1_EM10VH;
      fHandles[ "L1_EM10VH_MU6" ] = &L1_EM10VH_MU6;
      fHandles[ "L1_EM10VH_XE20" ] = &L1_EM10VH_XE20;
      fHandles[ "L1_EM10VH_XE30" ] = &L1_EM10VH_XE30;
      fHandles[ "L1_EM10VH_XE35" ] = &L1_EM10VH_XE35;
      fHandles[ "L1_EM12" ] = &L1_EM12;
      fHandles[ "L1_EM12_3J10" ] = &L1_EM12_3J10;
      fHandles[ "L1_EM12_4J10" ] = &L1_EM12_4J10;
      fHandles[ "L1_EM12_XE20" ] = &L1_EM12_XE20;
      fHandles[ "L1_EM12_XS30" ] = &L1_EM12_XS30;
      fHandles[ "L1_EM12_XS45" ] = &L1_EM12_XS45;
      fHandles[ "L1_EM14VH" ] = &L1_EM14VH;
      fHandles[ "L1_EM16V" ] = &L1_EM16V;
      fHandles[ "L1_EM16VH" ] = &L1_EM16VH;
      fHandles[ "L1_EM16VH_MU4" ] = &L1_EM16VH_MU4;
      fHandles[ "L1_EM16V_XE20" ] = &L1_EM16V_XE20;
      fHandles[ "L1_EM16V_XS45" ] = &L1_EM16V_XS45;
      fHandles[ "L1_EM18VH" ] = &L1_EM18VH;
      fHandles[ "L1_EM3" ] = &L1_EM3;
      fHandles[ "L1_EM30" ] = &L1_EM30;
      fHandles[ "L1_EM30_BGRP7" ] = &L1_EM30_BGRP7;
      fHandles[ "L1_EM3_EMPTY" ] = &L1_EM3_EMPTY;
      fHandles[ "L1_EM3_FIRSTEMPTY" ] = &L1_EM3_FIRSTEMPTY;
      fHandles[ "L1_EM3_MU6" ] = &L1_EM3_MU6;
      fHandles[ "L1_EM3_UNPAIRED_ISO" ] = &L1_EM3_UNPAIRED_ISO;
      fHandles[ "L1_EM3_UNPAIRED_NONISO" ] = &L1_EM3_UNPAIRED_NONISO;
      fHandles[ "L1_EM6" ] = &L1_EM6;
      fHandles[ "L1_EM6_2MU6" ] = &L1_EM6_2MU6;
      fHandles[ "L1_EM6_EMPTY" ] = &L1_EM6_EMPTY;
      fHandles[ "L1_EM6_MU10" ] = &L1_EM6_MU10;
      fHandles[ "L1_EM6_MU6" ] = &L1_EM6_MU6;
      fHandles[ "L1_EM6_XS45" ] = &L1_EM6_XS45;
      fHandles[ "L1_J30_XE35" ] = &L1_J30_XE35;
      fHandles[ "L1_J30_XE40" ] = &L1_J30_XE40;
      fHandles[ "L1_J30_XE50" ] = &L1_J30_XE50;
      fHandles[ "L1_J50_XE30" ] = &L1_J50_XE30;
      fHandles[ "L1_J50_XE35" ] = &L1_J50_XE35;
      fHandles[ "L1_J50_XE40" ] = &L1_J50_XE40;
      fHandles[ "L1_MU10" ] = &L1_MU10;
      fHandles[ "L1_MU10_EMPTY" ] = &L1_MU10_EMPTY;
      fHandles[ "L1_MU10_FIRSTEMPTY" ] = &L1_MU10_FIRSTEMPTY;
      fHandles[ "L1_MU10_J20" ] = &L1_MU10_J20;
      fHandles[ "L1_MU10_UNPAIRED_ISO" ] = &L1_MU10_UNPAIRED_ISO;
      fHandles[ "L1_MU10_XE20" ] = &L1_MU10_XE20;
      fHandles[ "L1_MU10_XE25" ] = &L1_MU10_XE25;
      fHandles[ "L1_MU11" ] = &L1_MU11;
      fHandles[ "L1_MU11_EMPTY" ] = &L1_MU11_EMPTY;
      fHandles[ "L1_MU15" ] = &L1_MU15;
      fHandles[ "L1_MU20" ] = &L1_MU20;
      fHandles[ "L1_MU20_FIRSTEMPTY" ] = &L1_MU20_FIRSTEMPTY;
      fHandles[ "L1_MU4" ] = &L1_MU4;
      fHandles[ "L1_MU4_EMPTY" ] = &L1_MU4_EMPTY;
      fHandles[ "L1_MU4_FIRSTEMPTY" ] = &L1_MU4_FIRSTEMPTY;
      fHandles[ "L1_MU4_J10" ] = &L1_MU4_J10;
      fHandles[ "L1_MU4_J15" ] = &L1_MU4_J15;
      fHandles[ "L1_MU4_J15_EMPTY" ] = &L1_MU4_J15_EMPTY;
      fHandles[ "L1_MU4_J15_UNPAIRED_ISO" ] = &L1_MU4_J15_UNPAIRED_ISO;
      fHandles[ "L1_MU4_J20_XE20" ] = &L1_MU4_J20_XE20;
      fHandles[ "L1_MU4_J20_XE35" ] = &L1_MU4_J20_XE35;
      fHandles[ "L1_MU4_J30" ] = &L1_MU4_J30;
      fHandles[ "L1_MU4_J50" ] = &L1_MU4_J50;
      fHandles[ "L1_MU4_J75" ] = &L1_MU4_J75;
      fHandles[ "L1_MU4_UNPAIRED_ISO" ] = &L1_MU4_UNPAIRED_ISO;
      fHandles[ "L1_MU4_UNPAIRED_NONISO" ] = &L1_MU4_UNPAIRED_NONISO;
      fHandles[ "L1_MU6" ] = &L1_MU6;
      fHandles[ "L1_MU6_2J20" ] = &L1_MU6_2J20;
      fHandles[ "L1_MU6_FIRSTEMPTY" ] = &L1_MU6_FIRSTEMPTY;
      fHandles[ "L1_MU6_J15" ] = &L1_MU6_J15;
      fHandles[ "L1_MUB" ] = &L1_MUB;
      fHandles[ "L1_MUE" ] = &L1_MUE;
      fHandles[ "L1_TAU11" ] = &L1_TAU11;
      fHandles[ "L1_TAU11I" ] = &L1_TAU11I;
      fHandles[ "L1_TAU11_MU10" ] = &L1_TAU11_MU10;
      fHandles[ "L1_TAU11_XE20" ] = &L1_TAU11_XE20;
      fHandles[ "L1_TAU15" ] = &L1_TAU15;
      fHandles[ "L1_TAU15I" ] = &L1_TAU15I;
      fHandles[ "L1_TAU15I_XE35" ] = &L1_TAU15I_XE35;
      fHandles[ "L1_TAU15I_XE40" ] = &L1_TAU15I_XE40;
      fHandles[ "L1_TAU15_XE25_3J10" ] = &L1_TAU15_XE25_3J10;
      fHandles[ "L1_TAU15_XE25_3J10_J30" ] = &L1_TAU15_XE25_3J10_J30;
      fHandles[ "L1_TAU15_XE25_3J15" ] = &L1_TAU15_XE25_3J15;
      fHandles[ "L1_TAU15_XE35" ] = &L1_TAU15_XE35;
      fHandles[ "L1_TAU15_XE40" ] = &L1_TAU15_XE40;
      fHandles[ "L1_TAU15_XS25_3J10" ] = &L1_TAU15_XS25_3J10;
      fHandles[ "L1_TAU15_XS35" ] = &L1_TAU15_XS35;
      fHandles[ "L1_TAU20" ] = &L1_TAU20;
      fHandles[ "L1_TAU20_XE35" ] = &L1_TAU20_XE35;
      fHandles[ "L1_TAU20_XE40" ] = &L1_TAU20_XE40;
      fHandles[ "L1_TAU40" ] = &L1_TAU40;
      fHandles[ "L1_TAU8" ] = &L1_TAU8;
      fHandles[ "L1_TAU8_EMPTY" ] = &L1_TAU8_EMPTY;
      fHandles[ "L1_TAU8_FIRSTEMPTY" ] = &L1_TAU8_FIRSTEMPTY;
      fHandles[ "L1_TAU8_MU10" ] = &L1_TAU8_MU10;
      fHandles[ "L1_TAU8_UNPAIRED_ISO" ] = &L1_TAU8_UNPAIRED_ISO;
      fHandles[ "L1_TAU8_UNPAIRED_NONISO" ] = &L1_TAU8_UNPAIRED_NONISO;
      fHandles[ "L1_XE20" ] = &L1_XE20;
      fHandles[ "L1_XE25" ] = &L1_XE25;
      fHandles[ "L1_XE30" ] = &L1_XE30;
      fHandles[ "L1_XE35" ] = &L1_XE35;
      fHandles[ "L1_XE40" ] = &L1_XE40;
      fHandles[ "L1_XE40_BGRP7" ] = &L1_XE40_BGRP7;
      fHandles[ "L1_XE50" ] = &L1_XE50;
      fHandles[ "L1_XE50_BGRP7" ] = &L1_XE50_BGRP7;
      fHandles[ "L1_XE60" ] = &L1_XE60;
      fHandles[ "L1_XE70" ] = &L1_XE70;
      fHandles[ "L2_2e12Tvh_loose1" ] = &L2_2e12Tvh_loose1;
      fHandles[ "L2_2e5_tight1_Jpsi" ] = &L2_2e5_tight1_Jpsi;
      fHandles[ "L2_2e7T_loose1_mu6" ] = &L2_2e7T_loose1_mu6;
      fHandles[ "L2_2e7T_medium1_mu6" ] = &L2_2e7T_medium1_mu6;
      fHandles[ "L2_2g15vh_loose_g10_loose" ] = &L2_2g15vh_loose_g10_loose;
      fHandles[ "L2_2g15vh_medium" ] = &L2_2g15vh_medium;
      fHandles[ "L2_2g15vh_medium_g10_medium" ] = &L2_2g15vh_medium_g10_medium;
      fHandles[ "L2_2g20_loose" ] = &L2_2g20_loose;
      fHandles[ "L2_2g20vh_medium" ] = &L2_2g20vh_medium;
      fHandles[ "L2_2g30_loose" ] = &L2_2g30_loose;
      fHandles[ "L2_2g40_loose" ] = &L2_2g40_loose;
      fHandles[ "L2_2mu10" ] = &L2_2mu10;
      fHandles[ "L2_2mu10_MSonly_g10_loose" ] = &L2_2mu10_MSonly_g10_loose;
      fHandles[ "L2_2mu10_MSonly_g10_loose_EMPTY" ] = &L2_2mu10_MSonly_g10_loose_EMPTY;
      fHandles[ "L2_2mu10_MSonly_g10_loose_UNPAIRED_ISO" ] = &L2_2mu10_MSonly_g10_loose_UNPAIRED_ISO;
      fHandles[ "L2_2mu13" ] = &L2_2mu13;
      fHandles[ "L2_2mu13_Zmumu_IDTrkNoCut" ] = &L2_2mu13_Zmumu_IDTrkNoCut;
      fHandles[ "L2_2mu13_l2muonSA" ] = &L2_2mu13_l2muonSA;
      fHandles[ "L2_2mu15" ] = &L2_2mu15;
      fHandles[ "L2_2mu4T" ] = &L2_2mu4T;
      fHandles[ "L2_2mu4T_2e5_tight1" ] = &L2_2mu4T_2e5_tight1;
      fHandles[ "L2_2mu4T_Bmumu" ] = &L2_2mu4T_Bmumu;
      fHandles[ "L2_2mu4T_Bmumu_Barrel" ] = &L2_2mu4T_Bmumu_Barrel;
      fHandles[ "L2_2mu4T_Bmumu_BarrelOnly" ] = &L2_2mu4T_Bmumu_BarrelOnly;
      fHandles[ "L2_2mu4T_Bmumux" ] = &L2_2mu4T_Bmumux;
      fHandles[ "L2_2mu4T_Bmumux_Barrel" ] = &L2_2mu4T_Bmumux_Barrel;
      fHandles[ "L2_2mu4T_Bmumux_BarrelOnly" ] = &L2_2mu4T_Bmumux_BarrelOnly;
      fHandles[ "L2_2mu4T_DiMu" ] = &L2_2mu4T_DiMu;
      fHandles[ "L2_2mu4T_DiMu_Barrel" ] = &L2_2mu4T_DiMu_Barrel;
      fHandles[ "L2_2mu4T_DiMu_BarrelOnly" ] = &L2_2mu4T_DiMu_BarrelOnly;
      fHandles[ "L2_2mu4T_DiMu_L2StarB" ] = &L2_2mu4T_DiMu_L2StarB;
      fHandles[ "L2_2mu4T_DiMu_L2StarC" ] = &L2_2mu4T_DiMu_L2StarC;
      fHandles[ "L2_2mu4T_DiMu_e5_tight1" ] = &L2_2mu4T_DiMu_e5_tight1;
      fHandles[ "L2_2mu4T_DiMu_l2muonSA" ] = &L2_2mu4T_DiMu_l2muonSA;
      fHandles[ "L2_2mu4T_DiMu_noVtx_noOS" ] = &L2_2mu4T_DiMu_noVtx_noOS;
      fHandles[ "L2_2mu4T_Jpsimumu" ] = &L2_2mu4T_Jpsimumu;
      fHandles[ "L2_2mu4T_Jpsimumu_Barrel" ] = &L2_2mu4T_Jpsimumu_Barrel;
      fHandles[ "L2_2mu4T_Jpsimumu_BarrelOnly" ] = &L2_2mu4T_Jpsimumu_BarrelOnly;
      fHandles[ "L2_2mu4T_Jpsimumu_IDTrkNoCut" ] = &L2_2mu4T_Jpsimumu_IDTrkNoCut;
      fHandles[ "L2_2mu4T_Upsimumu" ] = &L2_2mu4T_Upsimumu;
      fHandles[ "L2_2mu4T_Upsimumu_Barrel" ] = &L2_2mu4T_Upsimumu_Barrel;
      fHandles[ "L2_2mu4T_Upsimumu_BarrelOnly" ] = &L2_2mu4T_Upsimumu_BarrelOnly;
      fHandles[ "L2_2mu4T_xe35" ] = &L2_2mu4T_xe35;
      fHandles[ "L2_2mu4T_xe45" ] = &L2_2mu4T_xe45;
      fHandles[ "L2_2mu4T_xe60" ] = &L2_2mu4T_xe60;
      fHandles[ "L2_2mu6" ] = &L2_2mu6;
      fHandles[ "L2_2mu6_Bmumu" ] = &L2_2mu6_Bmumu;
      fHandles[ "L2_2mu6_Bmumux" ] = &L2_2mu6_Bmumux;
      fHandles[ "L2_2mu6_DiMu" ] = &L2_2mu6_DiMu;
      fHandles[ "L2_2mu6_DiMu_DY20" ] = &L2_2mu6_DiMu_DY20;
      fHandles[ "L2_2mu6_DiMu_DY25" ] = &L2_2mu6_DiMu_DY25;
      fHandles[ "L2_2mu6_DiMu_noVtx_noOS" ] = &L2_2mu6_DiMu_noVtx_noOS;
      fHandles[ "L2_2mu6_Jpsimumu" ] = &L2_2mu6_Jpsimumu;
      fHandles[ "L2_2mu6_Upsimumu" ] = &L2_2mu6_Upsimumu;
      fHandles[ "L2_2mu6i_DiMu_DY" ] = &L2_2mu6i_DiMu_DY;
      fHandles[ "L2_2mu6i_DiMu_DY_2j25_a4tchad" ] = &L2_2mu6i_DiMu_DY_2j25_a4tchad;
      fHandles[ "L2_2mu6i_DiMu_DY_noVtx_noOS" ] = &L2_2mu6i_DiMu_DY_noVtx_noOS;
      fHandles[ "L2_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" ] = &L2_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
      fHandles[ "L2_2mu8_EFxe30" ] = &L2_2mu8_EFxe30;
      fHandles[ "L2_2tau29T_medium1" ] = &L2_2tau29T_medium1;
      fHandles[ "L2_2tau29_medium1" ] = &L2_2tau29_medium1;
      fHandles[ "L2_2tau29i_medium1" ] = &L2_2tau29i_medium1;
      fHandles[ "L2_2tau38T_medium" ] = &L2_2tau38T_medium;
      fHandles[ "L2_2tau38T_medium1" ] = &L2_2tau38T_medium1;
      fHandles[ "L2_2tau38T_medium1_llh" ] = &L2_2tau38T_medium1_llh;
      fHandles[ "L2_b105_loose_j105_c4cchad_xe40" ] = &L2_b105_loose_j105_c4cchad_xe40;
      fHandles[ "L2_b105_loose_j105_c4cchad_xe45" ] = &L2_b105_loose_j105_c4cchad_xe45;
      fHandles[ "L2_b75_loose_j75_c4cchad_xe40" ] = &L2_b75_loose_j75_c4cchad_xe40;
      fHandles[ "L2_b75_loose_j75_c4cchad_xe45" ] = &L2_b75_loose_j75_c4cchad_xe45;
      fHandles[ "L2_b75_loose_j75_c4cchad_xe55" ] = &L2_b75_loose_j75_c4cchad_xe55;
      fHandles[ "L2_e11_etcut" ] = &L2_e11_etcut;
      fHandles[ "L2_e12Tvh_loose1" ] = &L2_e12Tvh_loose1;
      fHandles[ "L2_e12Tvh_loose1_mu8" ] = &L2_e12Tvh_loose1_mu8;
      fHandles[ "L2_e12Tvh_medium1" ] = &L2_e12Tvh_medium1;
      fHandles[ "L2_e12Tvh_medium1_mu10" ] = &L2_e12Tvh_medium1_mu10;
      fHandles[ "L2_e12Tvh_medium1_mu6" ] = &L2_e12Tvh_medium1_mu6;
      fHandles[ "L2_e12Tvh_medium1_mu6_topo_medium" ] = &L2_e12Tvh_medium1_mu6_topo_medium;
      fHandles[ "L2_e12Tvh_medium1_mu8" ] = &L2_e12Tvh_medium1_mu8;
      fHandles[ "L2_e13_etcutTrk_xs45" ] = &L2_e13_etcutTrk_xs45;
      fHandles[ "L2_e14_tight1_e4_etcut_Jpsi" ] = &L2_e14_tight1_e4_etcut_Jpsi;
      fHandles[ "L2_e15vh_medium1" ] = &L2_e15vh_medium1;
      fHandles[ "L2_e18_loose1" ] = &L2_e18_loose1;
      fHandles[ "L2_e18_loose1_g25_medium" ] = &L2_e18_loose1_g25_medium;
      fHandles[ "L2_e18_loose1_g35_loose" ] = &L2_e18_loose1_g35_loose;
      fHandles[ "L2_e18_loose1_g35_medium" ] = &L2_e18_loose1_g35_medium;
      fHandles[ "L2_e18_medium1" ] = &L2_e18_medium1;
      fHandles[ "L2_e18_medium1_g25_loose" ] = &L2_e18_medium1_g25_loose;
      fHandles[ "L2_e18_medium1_g25_medium" ] = &L2_e18_medium1_g25_medium;
      fHandles[ "L2_e18_medium1_g35_loose" ] = &L2_e18_medium1_g35_loose;
      fHandles[ "L2_e18_medium1_g35_medium" ] = &L2_e18_medium1_g35_medium;
      fHandles[ "L2_e18vh_medium1" ] = &L2_e18vh_medium1;
      fHandles[ "L2_e18vh_medium1_2e7T_medium1" ] = &L2_e18vh_medium1_2e7T_medium1;
      fHandles[ "L2_e20_etcutTrk_xe25" ] = &L2_e20_etcutTrk_xe25;
      fHandles[ "L2_e20_etcutTrk_xs45" ] = &L2_e20_etcutTrk_xs45;
      fHandles[ "L2_e20vhT_medium1_g6T_etcut_Upsi" ] = &L2_e20vhT_medium1_g6T_etcut_Upsi;
      fHandles[ "L2_e20vhT_tight1_g6T_etcut_Upsi" ] = &L2_e20vhT_tight1_g6T_etcut_Upsi;
      fHandles[ "L2_e22vh_loose" ] = &L2_e22vh_loose;
      fHandles[ "L2_e22vh_loose0" ] = &L2_e22vh_loose0;
      fHandles[ "L2_e22vh_loose1" ] = &L2_e22vh_loose1;
      fHandles[ "L2_e22vh_medium1" ] = &L2_e22vh_medium1;
      fHandles[ "L2_e22vh_medium1_IDTrkNoCut" ] = &L2_e22vh_medium1_IDTrkNoCut;
      fHandles[ "L2_e22vh_medium1_IdScan" ] = &L2_e22vh_medium1_IdScan;
      fHandles[ "L2_e22vh_medium1_SiTrk" ] = &L2_e22vh_medium1_SiTrk;
      fHandles[ "L2_e22vh_medium1_TRT" ] = &L2_e22vh_medium1_TRT;
      fHandles[ "L2_e22vhi_medium1" ] = &L2_e22vhi_medium1;
      fHandles[ "L2_e24vh_loose" ] = &L2_e24vh_loose;
      fHandles[ "L2_e24vh_loose0" ] = &L2_e24vh_loose0;
      fHandles[ "L2_e24vh_loose1" ] = &L2_e24vh_loose1;
      fHandles[ "L2_e24vh_medium1" ] = &L2_e24vh_medium1;
      fHandles[ "L2_e24vh_medium1_EFxe30" ] = &L2_e24vh_medium1_EFxe30;
      fHandles[ "L2_e24vh_medium1_EFxe35" ] = &L2_e24vh_medium1_EFxe35;
      fHandles[ "L2_e24vh_medium1_EFxe40" ] = &L2_e24vh_medium1_EFxe40;
      fHandles[ "L2_e24vh_medium1_IDTrkNoCut" ] = &L2_e24vh_medium1_IDTrkNoCut;
      fHandles[ "L2_e24vh_medium1_IdScan" ] = &L2_e24vh_medium1_IdScan;
      fHandles[ "L2_e24vh_medium1_L2StarB" ] = &L2_e24vh_medium1_L2StarB;
      fHandles[ "L2_e24vh_medium1_L2StarC" ] = &L2_e24vh_medium1_L2StarC;
      fHandles[ "L2_e24vh_medium1_SiTrk" ] = &L2_e24vh_medium1_SiTrk;
      fHandles[ "L2_e24vh_medium1_TRT" ] = &L2_e24vh_medium1_TRT;
      fHandles[ "L2_e24vh_medium1_e7_medium1" ] = &L2_e24vh_medium1_e7_medium1;
      fHandles[ "L2_e24vh_tight1_e15_NoCut_Zee" ] = &L2_e24vh_tight1_e15_NoCut_Zee;
      fHandles[ "L2_e24vhi_loose1_mu8" ] = &L2_e24vhi_loose1_mu8;
      fHandles[ "L2_e24vhi_medium1" ] = &L2_e24vhi_medium1;
      fHandles[ "L2_e45_etcut" ] = &L2_e45_etcut;
      fHandles[ "L2_e45_loose1" ] = &L2_e45_loose1;
      fHandles[ "L2_e45_medium1" ] = &L2_e45_medium1;
      fHandles[ "L2_e5_tight1" ] = &L2_e5_tight1;
      fHandles[ "L2_e5_tight1_e14_etcut_Jpsi" ] = &L2_e5_tight1_e14_etcut_Jpsi;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi" ] = &L2_e5_tight1_e4_etcut_Jpsi;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_IdScan" ] = &L2_e5_tight1_e4_etcut_Jpsi_IdScan;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_L2StarB" ] = &L2_e5_tight1_e4_etcut_Jpsi_L2StarB;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_L2StarC" ] = &L2_e5_tight1_e4_etcut_Jpsi_L2StarC;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_SiTrk" ] = &L2_e5_tight1_e4_etcut_Jpsi_SiTrk;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_TRT" ] = &L2_e5_tight1_e4_etcut_Jpsi_TRT;
      fHandles[ "L2_e5_tight1_e5_NoCut" ] = &L2_e5_tight1_e5_NoCut;
      fHandles[ "L2_e5_tight1_e9_etcut_Jpsi" ] = &L2_e5_tight1_e9_etcut_Jpsi;
      fHandles[ "L2_e60_etcut" ] = &L2_e60_etcut;
      fHandles[ "L2_e60_loose1" ] = &L2_e60_loose1;
      fHandles[ "L2_e60_medium1" ] = &L2_e60_medium1;
      fHandles[ "L2_e7T_loose1" ] = &L2_e7T_loose1;
      fHandles[ "L2_e7T_loose1_2mu6" ] = &L2_e7T_loose1_2mu6;
      fHandles[ "L2_e7T_medium1" ] = &L2_e7T_medium1;
      fHandles[ "L2_e7T_medium1_2mu6" ] = &L2_e7T_medium1_2mu6;
      fHandles[ "L2_e9_tight1_e4_etcut_Jpsi" ] = &L2_e9_tight1_e4_etcut_Jpsi;
      fHandles[ "L2_eb_physics" ] = &L2_eb_physics;
      fHandles[ "L2_eb_physics_empty" ] = &L2_eb_physics_empty;
      fHandles[ "L2_eb_physics_firstempty" ] = &L2_eb_physics_firstempty;
      fHandles[ "L2_eb_physics_noL1PS" ] = &L2_eb_physics_noL1PS;
      fHandles[ "L2_eb_physics_unpaired_iso" ] = &L2_eb_physics_unpaired_iso;
      fHandles[ "L2_eb_physics_unpaired_noniso" ] = &L2_eb_physics_unpaired_noniso;
      fHandles[ "L2_eb_random" ] = &L2_eb_random;
      fHandles[ "L2_eb_random_empty" ] = &L2_eb_random_empty;
      fHandles[ "L2_eb_random_firstempty" ] = &L2_eb_random_firstempty;
      fHandles[ "L2_eb_random_unpaired_iso" ] = &L2_eb_random_unpaired_iso;
      fHandles[ "L2_em3_empty_larcalib" ] = &L2_em3_empty_larcalib;
      fHandles[ "L2_em6_empty_larcalib" ] = &L2_em6_empty_larcalib;
      fHandles[ "L2_g100_loose" ] = &L2_g100_loose;
      fHandles[ "L2_g10_NoCut_cosmic" ] = &L2_g10_NoCut_cosmic;
      fHandles[ "L2_g10_loose" ] = &L2_g10_loose;
      fHandles[ "L2_g10_medium" ] = &L2_g10_medium;
      fHandles[ "L2_g120_loose" ] = &L2_g120_loose;
      fHandles[ "L2_g12Tvh_loose" ] = &L2_g12Tvh_loose;
      fHandles[ "L2_g12Tvh_medium" ] = &L2_g12Tvh_medium;
      fHandles[ "L2_g15_loose" ] = &L2_g15_loose;
      fHandles[ "L2_g15vh_loose" ] = &L2_g15vh_loose;
      fHandles[ "L2_g15vh_medium" ] = &L2_g15vh_medium;
      fHandles[ "L2_g200_etcut" ] = &L2_g200_etcut;
      fHandles[ "L2_g20Tvh_medium" ] = &L2_g20Tvh_medium;
      fHandles[ "L2_g20_etcut" ] = &L2_g20_etcut;
      fHandles[ "L2_g20_loose" ] = &L2_g20_loose;
      fHandles[ "L2_g20_medium" ] = &L2_g20_medium;
      fHandles[ "L2_g20vh_medium" ] = &L2_g20vh_medium;
      fHandles[ "L2_g30_loose_g20_loose" ] = &L2_g30_loose_g20_loose;
      fHandles[ "L2_g30_medium_g20_medium" ] = &L2_g30_medium_g20_medium;
      fHandles[ "L2_g35_loose_g25_loose" ] = &L2_g35_loose_g25_loose;
      fHandles[ "L2_g35_loose_g30_loose" ] = &L2_g35_loose_g30_loose;
      fHandles[ "L2_g40_loose" ] = &L2_g40_loose;
      fHandles[ "L2_g40_loose_EFxe50" ] = &L2_g40_loose_EFxe50;
      fHandles[ "L2_g40_loose_L2xe35" ] = &L2_g40_loose_L2xe35;
      fHandles[ "L2_g40_loose_L2xe45" ] = &L2_g40_loose_L2xe45;
      fHandles[ "L2_g40_loose_g25_loose" ] = &L2_g40_loose_g25_loose;
      fHandles[ "L2_g40_loose_g30_loose" ] = &L2_g40_loose_g30_loose;
      fHandles[ "L2_g5_NoCut_cosmic" ] = &L2_g5_NoCut_cosmic;
      fHandles[ "L2_g60_loose" ] = &L2_g60_loose;
      fHandles[ "L2_g80_loose" ] = &L2_g80_loose;
      fHandles[ "L2_j105_c4cchad_xe35" ] = &L2_j105_c4cchad_xe35;
      fHandles[ "L2_j105_c4cchad_xe40" ] = &L2_j105_c4cchad_xe40;
      fHandles[ "L2_j105_c4cchad_xe45" ] = &L2_j105_c4cchad_xe45;
      fHandles[ "L2_j105_j40_c4cchad_xe40" ] = &L2_j105_j40_c4cchad_xe40;
      fHandles[ "L2_j105_j50_c4cchad_xe40" ] = &L2_j105_j50_c4cchad_xe40;
      fHandles[ "L2_j30_a4tcem_eta13_xe30_empty" ] = &L2_j30_a4tcem_eta13_xe30_empty;
      fHandles[ "L2_j30_a4tcem_eta13_xe30_firstempty" ] = &L2_j30_a4tcem_eta13_xe30_firstempty;
      fHandles[ "L2_j50_a4tcem_eta13_xe50_empty" ] = &L2_j50_a4tcem_eta13_xe50_empty;
      fHandles[ "L2_j50_a4tcem_eta13_xe50_firstempty" ] = &L2_j50_a4tcem_eta13_xe50_firstempty;
      fHandles[ "L2_j50_a4tcem_eta25_xe50_empty" ] = &L2_j50_a4tcem_eta25_xe50_empty;
      fHandles[ "L2_j50_a4tcem_eta25_xe50_firstempty" ] = &L2_j50_a4tcem_eta25_xe50_firstempty;
      fHandles[ "L2_j75_c4cchad_xe40" ] = &L2_j75_c4cchad_xe40;
      fHandles[ "L2_j75_c4cchad_xe45" ] = &L2_j75_c4cchad_xe45;
      fHandles[ "L2_j75_c4cchad_xe55" ] = &L2_j75_c4cchad_xe55;
      fHandles[ "L2_mu10" ] = &L2_mu10;
      fHandles[ "L2_mu10_Jpsimumu" ] = &L2_mu10_Jpsimumu;
      fHandles[ "L2_mu10_MSonly" ] = &L2_mu10_MSonly;
      fHandles[ "L2_mu10_Upsimumu_tight_FS" ] = &L2_mu10_Upsimumu_tight_FS;
      fHandles[ "L2_mu10i_g10_loose" ] = &L2_mu10i_g10_loose;
      fHandles[ "L2_mu10i_g10_loose_TauMass" ] = &L2_mu10i_g10_loose_TauMass;
      fHandles[ "L2_mu10i_g10_medium" ] = &L2_mu10i_g10_medium;
      fHandles[ "L2_mu10i_g10_medium_TauMass" ] = &L2_mu10i_g10_medium_TauMass;
      fHandles[ "L2_mu10i_loose_g12Tvh_loose" ] = &L2_mu10i_loose_g12Tvh_loose;
      fHandles[ "L2_mu10i_loose_g12Tvh_loose_TauMass" ] = &L2_mu10i_loose_g12Tvh_loose_TauMass;
      fHandles[ "L2_mu10i_loose_g12Tvh_medium" ] = &L2_mu10i_loose_g12Tvh_medium;
      fHandles[ "L2_mu10i_loose_g12Tvh_medium_TauMass" ] = &L2_mu10i_loose_g12Tvh_medium_TauMass;
      fHandles[ "L2_mu11_empty_NoAlg" ] = &L2_mu11_empty_NoAlg;
      fHandles[ "L2_mu13" ] = &L2_mu13;
      fHandles[ "L2_mu15" ] = &L2_mu15;
      fHandles[ "L2_mu15_l2cal" ] = &L2_mu15_l2cal;
      fHandles[ "L2_mu18" ] = &L2_mu18;
      fHandles[ "L2_mu18_2g10_loose" ] = &L2_mu18_2g10_loose;
      fHandles[ "L2_mu18_2g10_medium" ] = &L2_mu18_2g10_medium;
      fHandles[ "L2_mu18_2g15_loose" ] = &L2_mu18_2g15_loose;
      fHandles[ "L2_mu18_IDTrkNoCut_tight" ] = &L2_mu18_IDTrkNoCut_tight;
      fHandles[ "L2_mu18_g20vh_loose" ] = &L2_mu18_g20vh_loose;
      fHandles[ "L2_mu18_medium" ] = &L2_mu18_medium;
      fHandles[ "L2_mu18_tight" ] = &L2_mu18_tight;
      fHandles[ "L2_mu18_tight_e7_medium1" ] = &L2_mu18_tight_e7_medium1;
      fHandles[ "L2_mu18i4_tight" ] = &L2_mu18i4_tight;
      fHandles[ "L2_mu18it_tight" ] = &L2_mu18it_tight;
      fHandles[ "L2_mu20i_tight_g5_loose" ] = &L2_mu20i_tight_g5_loose;
      fHandles[ "L2_mu20i_tight_g5_loose_TauMass" ] = &L2_mu20i_tight_g5_loose_TauMass;
      fHandles[ "L2_mu20i_tight_g5_medium" ] = &L2_mu20i_tight_g5_medium;
      fHandles[ "L2_mu20i_tight_g5_medium_TauMass" ] = &L2_mu20i_tight_g5_medium_TauMass;
      fHandles[ "L2_mu20it_tight" ] = &L2_mu20it_tight;
      fHandles[ "L2_mu22_IDTrkNoCut_tight" ] = &L2_mu22_IDTrkNoCut_tight;
      fHandles[ "L2_mu24" ] = &L2_mu24;
      fHandles[ "L2_mu24_g20vh_loose" ] = &L2_mu24_g20vh_loose;
      fHandles[ "L2_mu24_g20vh_medium" ] = &L2_mu24_g20vh_medium;
      fHandles[ "L2_mu24_j60_c4cchad_EFxe40" ] = &L2_mu24_j60_c4cchad_EFxe40;
      fHandles[ "L2_mu24_j60_c4cchad_EFxe50" ] = &L2_mu24_j60_c4cchad_EFxe50;
      fHandles[ "L2_mu24_j60_c4cchad_EFxe60" ] = &L2_mu24_j60_c4cchad_EFxe60;
      fHandles[ "L2_mu24_j60_c4cchad_xe35" ] = &L2_mu24_j60_c4cchad_xe35;
      fHandles[ "L2_mu24_j65_c4cchad" ] = &L2_mu24_j65_c4cchad;
      fHandles[ "L2_mu24_medium" ] = &L2_mu24_medium;
      fHandles[ "L2_mu24_muCombTag_NoEF_tight" ] = &L2_mu24_muCombTag_NoEF_tight;
      fHandles[ "L2_mu24_tight" ] = &L2_mu24_tight;
      fHandles[ "L2_mu24_tight_2j35_a4tchad" ] = &L2_mu24_tight_2j35_a4tchad;
      fHandles[ "L2_mu24_tight_3j35_a4tchad" ] = &L2_mu24_tight_3j35_a4tchad;
      fHandles[ "L2_mu24_tight_4j35_a4tchad" ] = &L2_mu24_tight_4j35_a4tchad;
      fHandles[ "L2_mu24_tight_EFxe40" ] = &L2_mu24_tight_EFxe40;
      fHandles[ "L2_mu24_tight_L2StarB" ] = &L2_mu24_tight_L2StarB;
      fHandles[ "L2_mu24_tight_L2StarC" ] = &L2_mu24_tight_L2StarC;
      fHandles[ "L2_mu24_tight_l2muonSA" ] = &L2_mu24_tight_l2muonSA;
      fHandles[ "L2_mu36_tight" ] = &L2_mu36_tight;
      fHandles[ "L2_mu40_MSonly_barrel_tight" ] = &L2_mu40_MSonly_barrel_tight;
      fHandles[ "L2_mu40_muCombTag_NoEF" ] = &L2_mu40_muCombTag_NoEF;
      fHandles[ "L2_mu40_slow_outOfTime_tight" ] = &L2_mu40_slow_outOfTime_tight;
      fHandles[ "L2_mu40_slow_tight" ] = &L2_mu40_slow_tight;
      fHandles[ "L2_mu40_tight" ] = &L2_mu40_tight;
      fHandles[ "L2_mu4T" ] = &L2_mu4T;
      fHandles[ "L2_mu4T_Trk_Jpsi" ] = &L2_mu4T_Trk_Jpsi;
      fHandles[ "L2_mu4T_cosmic" ] = &L2_mu4T_cosmic;
      fHandles[ "L2_mu4T_j105_c4cchad" ] = &L2_mu4T_j105_c4cchad;
      fHandles[ "L2_mu4T_j10_a4TTem" ] = &L2_mu4T_j10_a4TTem;
      fHandles[ "L2_mu4T_j140_c4cchad" ] = &L2_mu4T_j140_c4cchad;
      fHandles[ "L2_mu4T_j15_a4TTem" ] = &L2_mu4T_j15_a4TTem;
      fHandles[ "L2_mu4T_j165_c4cchad" ] = &L2_mu4T_j165_c4cchad;
      fHandles[ "L2_mu4T_j30_a4TTem" ] = &L2_mu4T_j30_a4TTem;
      fHandles[ "L2_mu4T_j40_c4cchad" ] = &L2_mu4T_j40_c4cchad;
      fHandles[ "L2_mu4T_j50_a4TTem" ] = &L2_mu4T_j50_a4TTem;
      fHandles[ "L2_mu4T_j50_c4cchad" ] = &L2_mu4T_j50_c4cchad;
      fHandles[ "L2_mu4T_j60_c4cchad" ] = &L2_mu4T_j60_c4cchad;
      fHandles[ "L2_mu4T_j60_c4cchad_xe40" ] = &L2_mu4T_j60_c4cchad_xe40;
      fHandles[ "L2_mu4T_j75_a4TTem" ] = &L2_mu4T_j75_a4TTem;
      fHandles[ "L2_mu4T_j75_c4cchad" ] = &L2_mu4T_j75_c4cchad;
      fHandles[ "L2_mu4Ti_g20Tvh_loose" ] = &L2_mu4Ti_g20Tvh_loose;
      fHandles[ "L2_mu4Ti_g20Tvh_loose_TauMass" ] = &L2_mu4Ti_g20Tvh_loose_TauMass;
      fHandles[ "L2_mu4Ti_g20Tvh_medium" ] = &L2_mu4Ti_g20Tvh_medium;
      fHandles[ "L2_mu4Ti_g20Tvh_medium_TauMass" ] = &L2_mu4Ti_g20Tvh_medium_TauMass;
      fHandles[ "L2_mu4Tmu6_Bmumu" ] = &L2_mu4Tmu6_Bmumu;
      fHandles[ "L2_mu4Tmu6_Bmumu_Barrel" ] = &L2_mu4Tmu6_Bmumu_Barrel;
      fHandles[ "L2_mu4Tmu6_Bmumux" ] = &L2_mu4Tmu6_Bmumux;
      fHandles[ "L2_mu4Tmu6_Bmumux_Barrel" ] = &L2_mu4Tmu6_Bmumux_Barrel;
      fHandles[ "L2_mu4Tmu6_DiMu" ] = &L2_mu4Tmu6_DiMu;
      fHandles[ "L2_mu4Tmu6_DiMu_Barrel" ] = &L2_mu4Tmu6_DiMu_Barrel;
      fHandles[ "L2_mu4Tmu6_DiMu_noVtx_noOS" ] = &L2_mu4Tmu6_DiMu_noVtx_noOS;
      fHandles[ "L2_mu4Tmu6_Jpsimumu" ] = &L2_mu4Tmu6_Jpsimumu;
      fHandles[ "L2_mu4Tmu6_Jpsimumu_Barrel" ] = &L2_mu4Tmu6_Jpsimumu_Barrel;
      fHandles[ "L2_mu4Tmu6_Jpsimumu_IDTrkNoCut" ] = &L2_mu4Tmu6_Jpsimumu_IDTrkNoCut;
      fHandles[ "L2_mu4Tmu6_Upsimumu" ] = &L2_mu4Tmu6_Upsimumu;
      fHandles[ "L2_mu4Tmu6_Upsimumu_Barrel" ] = &L2_mu4Tmu6_Upsimumu_Barrel;
      fHandles[ "L2_mu4_L1MU11_MSonly_cosmic" ] = &L2_mu4_L1MU11_MSonly_cosmic;
      fHandles[ "L2_mu4_L1MU11_cosmic" ] = &L2_mu4_L1MU11_cosmic;
      fHandles[ "L2_mu4_empty_NoAlg" ] = &L2_mu4_empty_NoAlg;
      fHandles[ "L2_mu4_firstempty_NoAlg" ] = &L2_mu4_firstempty_NoAlg;
      fHandles[ "L2_mu4_l2cal_empty" ] = &L2_mu4_l2cal_empty;
      fHandles[ "L2_mu4_unpaired_iso_NoAlg" ] = &L2_mu4_unpaired_iso_NoAlg;
      fHandles[ "L2_mu50_MSonly_barrel_tight" ] = &L2_mu50_MSonly_barrel_tight;
      fHandles[ "L2_mu6" ] = &L2_mu6;
      fHandles[ "L2_mu60_slow_outOfTime_tight1" ] = &L2_mu60_slow_outOfTime_tight1;
      fHandles[ "L2_mu60_slow_tight1" ] = &L2_mu60_slow_tight1;
      fHandles[ "L2_mu6_Jpsimumu_tight" ] = &L2_mu6_Jpsimumu_tight;
      fHandles[ "L2_mu6_MSonly" ] = &L2_mu6_MSonly;
      fHandles[ "L2_mu6_Trk_Jpsi_loose" ] = &L2_mu6_Trk_Jpsi_loose;
      fHandles[ "L2_mu8" ] = &L2_mu8;
      fHandles[ "L2_mu8_4j15_a4TTem" ] = &L2_mu8_4j15_a4TTem;
      fHandles[ "L2_tau125_IDTrkNoCut" ] = &L2_tau125_IDTrkNoCut;
      fHandles[ "L2_tau125_medium1" ] = &L2_tau125_medium1;
      fHandles[ "L2_tau125_medium1_L2StarA" ] = &L2_tau125_medium1_L2StarA;
      fHandles[ "L2_tau125_medium1_L2StarB" ] = &L2_tau125_medium1_L2StarB;
      fHandles[ "L2_tau125_medium1_L2StarC" ] = &L2_tau125_medium1_L2StarC;
      fHandles[ "L2_tau125_medium1_llh" ] = &L2_tau125_medium1_llh;
      fHandles[ "L2_tau20T_medium" ] = &L2_tau20T_medium;
      fHandles[ "L2_tau20T_medium1" ] = &L2_tau20T_medium1;
      fHandles[ "L2_tau20T_medium1_e15vh_medium1" ] = &L2_tau20T_medium1_e15vh_medium1;
      fHandles[ "L2_tau20T_medium1_mu15i" ] = &L2_tau20T_medium1_mu15i;
      fHandles[ "L2_tau20T_medium_mu15" ] = &L2_tau20T_medium_mu15;
      fHandles[ "L2_tau20Ti_medium" ] = &L2_tau20Ti_medium;
      fHandles[ "L2_tau20Ti_medium1" ] = &L2_tau20Ti_medium1;
      fHandles[ "L2_tau20Ti_medium1_e18vh_medium1" ] = &L2_tau20Ti_medium1_e18vh_medium1;
      fHandles[ "L2_tau20Ti_medium1_llh_e18vh_medium1" ] = &L2_tau20Ti_medium1_llh_e18vh_medium1;
      fHandles[ "L2_tau20Ti_medium_e18vh_medium1" ] = &L2_tau20Ti_medium_e18vh_medium1;
      fHandles[ "L2_tau20Ti_tight1" ] = &L2_tau20Ti_tight1;
      fHandles[ "L2_tau20Ti_tight1_llh" ] = &L2_tau20Ti_tight1_llh;
      fHandles[ "L2_tau20_medium" ] = &L2_tau20_medium;
      fHandles[ "L2_tau20_medium1" ] = &L2_tau20_medium1;
      fHandles[ "L2_tau20_medium1_llh" ] = &L2_tau20_medium1_llh;
      fHandles[ "L2_tau20_medium1_llh_mu15" ] = &L2_tau20_medium1_llh_mu15;
      fHandles[ "L2_tau20_medium1_mu15" ] = &L2_tau20_medium1_mu15;
      fHandles[ "L2_tau20_medium1_mu15i" ] = &L2_tau20_medium1_mu15i;
      fHandles[ "L2_tau20_medium1_mu18" ] = &L2_tau20_medium1_mu18;
      fHandles[ "L2_tau20_medium_llh" ] = &L2_tau20_medium_llh;
      fHandles[ "L2_tau20_medium_mu15" ] = &L2_tau20_medium_mu15;
      fHandles[ "L2_tau29T_medium" ] = &L2_tau29T_medium;
      fHandles[ "L2_tau29T_medium1" ] = &L2_tau29T_medium1;
      fHandles[ "L2_tau29T_medium1_tau20T_medium1" ] = &L2_tau29T_medium1_tau20T_medium1;
      fHandles[ "L2_tau29T_medium1_xe35_tight" ] = &L2_tau29T_medium1_xe35_tight;
      fHandles[ "L2_tau29T_medium1_xe40_tight" ] = &L2_tau29T_medium1_xe40_tight;
      fHandles[ "L2_tau29T_medium_xe35_tight" ] = &L2_tau29T_medium_xe35_tight;
      fHandles[ "L2_tau29T_medium_xe40_tight" ] = &L2_tau29T_medium_xe40_tight;
      fHandles[ "L2_tau29T_tight1" ] = &L2_tau29T_tight1;
      fHandles[ "L2_tau29T_tight1_llh" ] = &L2_tau29T_tight1_llh;
      fHandles[ "L2_tau29Ti_medium1" ] = &L2_tau29Ti_medium1;
      fHandles[ "L2_tau29Ti_medium1_llh_tau20Ti_medium1_llh" ] = &L2_tau29Ti_medium1_llh_tau20Ti_medium1_llh;
      fHandles[ "L2_tau29Ti_medium1_llh_xe35_tight" ] = &L2_tau29Ti_medium1_llh_xe35_tight;
      fHandles[ "L2_tau29Ti_medium1_llh_xe40_tight" ] = &L2_tau29Ti_medium1_llh_xe40_tight;
      fHandles[ "L2_tau29Ti_medium1_tau20Ti_medium1" ] = &L2_tau29Ti_medium1_tau20Ti_medium1;
      fHandles[ "L2_tau29Ti_medium1_xe35_tight" ] = &L2_tau29Ti_medium1_xe35_tight;
      fHandles[ "L2_tau29Ti_medium1_xe40" ] = &L2_tau29Ti_medium1_xe40;
      fHandles[ "L2_tau29Ti_medium1_xe40_tight" ] = &L2_tau29Ti_medium1_xe40_tight;
      fHandles[ "L2_tau29Ti_medium_xe35_tight" ] = &L2_tau29Ti_medium_xe35_tight;
      fHandles[ "L2_tau29Ti_medium_xe40_tight" ] = &L2_tau29Ti_medium_xe40_tight;
      fHandles[ "L2_tau29Ti_tight1" ] = &L2_tau29Ti_tight1;
      fHandles[ "L2_tau29Ti_tight1_llh" ] = &L2_tau29Ti_tight1_llh;
      fHandles[ "L2_tau29Ti_tight1_llh_tau20Ti_tight1_llh" ] = &L2_tau29Ti_tight1_llh_tau20Ti_tight1_llh;
      fHandles[ "L2_tau29Ti_tight1_tau20Ti_tight1" ] = &L2_tau29Ti_tight1_tau20Ti_tight1;
      fHandles[ "L2_tau29_IDTrkNoCut" ] = &L2_tau29_IDTrkNoCut;
      fHandles[ "L2_tau29_medium" ] = &L2_tau29_medium;
      fHandles[ "L2_tau29_medium1" ] = &L2_tau29_medium1;
      fHandles[ "L2_tau29_medium1_llh" ] = &L2_tau29_medium1_llh;
      fHandles[ "L2_tau29_medium_2stTest" ] = &L2_tau29_medium_2stTest;
      fHandles[ "L2_tau29_medium_L2StarA" ] = &L2_tau29_medium_L2StarA;
      fHandles[ "L2_tau29_medium_L2StarB" ] = &L2_tau29_medium_L2StarB;
      fHandles[ "L2_tau29_medium_L2StarC" ] = &L2_tau29_medium_L2StarC;
      fHandles[ "L2_tau29_medium_llh" ] = &L2_tau29_medium_llh;
      fHandles[ "L2_tau29i_medium" ] = &L2_tau29i_medium;
      fHandles[ "L2_tau29i_medium1" ] = &L2_tau29i_medium1;
      fHandles[ "L2_tau38T_medium" ] = &L2_tau38T_medium;
      fHandles[ "L2_tau38T_medium1" ] = &L2_tau38T_medium1;
      fHandles[ "L2_tau38T_medium1_e18vh_medium1" ] = &L2_tau38T_medium1_e18vh_medium1;
      fHandles[ "L2_tau38T_medium1_llh_e18vh_medium1" ] = &L2_tau38T_medium1_llh_e18vh_medium1;
      fHandles[ "L2_tau38T_medium1_xe35_tight" ] = &L2_tau38T_medium1_xe35_tight;
      fHandles[ "L2_tau38T_medium1_xe40_tight" ] = &L2_tau38T_medium1_xe40_tight;
      fHandles[ "L2_tau38T_medium_e18vh_medium1" ] = &L2_tau38T_medium_e18vh_medium1;
      fHandles[ "L2_tau50_medium" ] = &L2_tau50_medium;
      fHandles[ "L2_tau50_medium1_e18vh_medium1" ] = &L2_tau50_medium1_e18vh_medium1;
      fHandles[ "L2_tau50_medium_e15vh_medium1" ] = &L2_tau50_medium_e15vh_medium1;
      fHandles[ "L2_tau8_empty_larcalib" ] = &L2_tau8_empty_larcalib;
      fHandles[ "L2_tauNoCut" ] = &L2_tauNoCut;
      fHandles[ "L2_tauNoCut_L1TAU40" ] = &L2_tauNoCut_L1TAU40;
      fHandles[ "L2_tauNoCut_cosmic" ] = &L2_tauNoCut_cosmic;
      fHandles[ "L2_xe25" ] = &L2_xe25;
      fHandles[ "L2_xe35" ] = &L2_xe35;
      fHandles[ "L2_xe40" ] = &L2_xe40;
      fHandles[ "L2_xe45" ] = &L2_xe45;
      fHandles[ "L2_xe45T" ] = &L2_xe45T;
      fHandles[ "L2_xe55" ] = &L2_xe55;
      fHandles[ "L2_xe55T" ] = &L2_xe55T;
      fHandles[ "L2_xe55_LArNoiseBurst" ] = &L2_xe55_LArNoiseBurst;
      fHandles[ "L2_xe65" ] = &L2_xe65;
      fHandles[ "L2_xe65_tight" ] = &L2_xe65_tight;
      fHandles[ "L2_xe75" ] = &L2_xe75;
      fHandles[ "L2_xe90" ] = &L2_xe90;
      fHandles[ "L2_xe90_tight" ] = &L2_xe90_tight;

      // Configure all variables in a loop:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->SetParent( this );
         itr->second->SetName( fPrefix + itr->first );
         itr->second->SetMaster( &master );
      }
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   TriggerD3PDObject::TriggerD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "trig_L1_TAV" ] = &L1_TAV;
      fHandles[ "EF_2e12Tvh_loose1" ] = &EF_2e12Tvh_loose1;
      fHandles[ "EF_2e5_tight1_Jpsi" ] = &EF_2e5_tight1_Jpsi;
      fHandles[ "EF_2e7T_loose1_mu6" ] = &EF_2e7T_loose1_mu6;
      fHandles[ "EF_2e7T_medium1_mu6" ] = &EF_2e7T_medium1_mu6;
      fHandles[ "EF_2g15vh_loose_g10_loose" ] = &EF_2g15vh_loose_g10_loose;
      fHandles[ "EF_2g15vh_medium" ] = &EF_2g15vh_medium;
      fHandles[ "EF_2g15vh_medium_g10_medium" ] = &EF_2g15vh_medium_g10_medium;
      fHandles[ "EF_2g20_loose" ] = &EF_2g20_loose;
      fHandles[ "EF_2g20vh_medium" ] = &EF_2g20vh_medium;
      fHandles[ "EF_2g30_loose" ] = &EF_2g30_loose;
      fHandles[ "EF_2g40_loose" ] = &EF_2g40_loose;
      fHandles[ "EF_2mu10" ] = &EF_2mu10;
      fHandles[ "EF_2mu10_MSonly_g10_loose" ] = &EF_2mu10_MSonly_g10_loose;
      fHandles[ "EF_2mu10_MSonly_g10_loose_EMPTY" ] = &EF_2mu10_MSonly_g10_loose_EMPTY;
      fHandles[ "EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO" ] = &EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO;
      fHandles[ "EF_2mu13" ] = &EF_2mu13;
      fHandles[ "EF_2mu13_Zmumu_IDTrkNoCut" ] = &EF_2mu13_Zmumu_IDTrkNoCut;
      fHandles[ "EF_2mu13_l2muonSA" ] = &EF_2mu13_l2muonSA;
      fHandles[ "EF_2mu15" ] = &EF_2mu15;
      fHandles[ "EF_2mu4T" ] = &EF_2mu4T;
      fHandles[ "EF_2mu4T_2e5_tight1" ] = &EF_2mu4T_2e5_tight1;
      fHandles[ "EF_2mu4T_Bmumu" ] = &EF_2mu4T_Bmumu;
      fHandles[ "EF_2mu4T_Bmumu_Barrel" ] = &EF_2mu4T_Bmumu_Barrel;
      fHandles[ "EF_2mu4T_Bmumu_BarrelOnly" ] = &EF_2mu4T_Bmumu_BarrelOnly;
      fHandles[ "EF_2mu4T_Bmumux" ] = &EF_2mu4T_Bmumux;
      fHandles[ "EF_2mu4T_Bmumux_Barrel" ] = &EF_2mu4T_Bmumux_Barrel;
      fHandles[ "EF_2mu4T_Bmumux_BarrelOnly" ] = &EF_2mu4T_Bmumux_BarrelOnly;
      fHandles[ "EF_2mu4T_DiMu" ] = &EF_2mu4T_DiMu;
      fHandles[ "EF_2mu4T_DiMu_Barrel" ] = &EF_2mu4T_DiMu_Barrel;
      fHandles[ "EF_2mu4T_DiMu_BarrelOnly" ] = &EF_2mu4T_DiMu_BarrelOnly;
      fHandles[ "EF_2mu4T_DiMu_L2StarB" ] = &EF_2mu4T_DiMu_L2StarB;
      fHandles[ "EF_2mu4T_DiMu_L2StarC" ] = &EF_2mu4T_DiMu_L2StarC;
      fHandles[ "EF_2mu4T_DiMu_e5_tight1" ] = &EF_2mu4T_DiMu_e5_tight1;
      fHandles[ "EF_2mu4T_DiMu_l2muonSA" ] = &EF_2mu4T_DiMu_l2muonSA;
      fHandles[ "EF_2mu4T_DiMu_noVtx_noOS" ] = &EF_2mu4T_DiMu_noVtx_noOS;
      fHandles[ "EF_2mu4T_Jpsimumu" ] = &EF_2mu4T_Jpsimumu;
      fHandles[ "EF_2mu4T_Jpsimumu_Barrel" ] = &EF_2mu4T_Jpsimumu_Barrel;
      fHandles[ "EF_2mu4T_Jpsimumu_BarrelOnly" ] = &EF_2mu4T_Jpsimumu_BarrelOnly;
      fHandles[ "EF_2mu4T_Jpsimumu_IDTrkNoCut" ] = &EF_2mu4T_Jpsimumu_IDTrkNoCut;
      fHandles[ "EF_2mu4T_Upsimumu" ] = &EF_2mu4T_Upsimumu;
      fHandles[ "EF_2mu4T_Upsimumu_Barrel" ] = &EF_2mu4T_Upsimumu_Barrel;
      fHandles[ "EF_2mu4T_Upsimumu_BarrelOnly" ] = &EF_2mu4T_Upsimumu_BarrelOnly;
      fHandles[ "EF_2mu4T_xe50_tclcw" ] = &EF_2mu4T_xe50_tclcw;
      fHandles[ "EF_2mu4T_xe60" ] = &EF_2mu4T_xe60;
      fHandles[ "EF_2mu4T_xe60_tclcw" ] = &EF_2mu4T_xe60_tclcw;
      fHandles[ "EF_2mu6" ] = &EF_2mu6;
      fHandles[ "EF_2mu6_Bmumu" ] = &EF_2mu6_Bmumu;
      fHandles[ "EF_2mu6_Bmumux" ] = &EF_2mu6_Bmumux;
      fHandles[ "EF_2mu6_DiMu" ] = &EF_2mu6_DiMu;
      fHandles[ "EF_2mu6_DiMu_DY20" ] = &EF_2mu6_DiMu_DY20;
      fHandles[ "EF_2mu6_DiMu_DY25" ] = &EF_2mu6_DiMu_DY25;
      fHandles[ "EF_2mu6_DiMu_noVtx_noOS" ] = &EF_2mu6_DiMu_noVtx_noOS;
      fHandles[ "EF_2mu6_Jpsimumu" ] = &EF_2mu6_Jpsimumu;
      fHandles[ "EF_2mu6_Upsimumu" ] = &EF_2mu6_Upsimumu;
      fHandles[ "EF_2mu6i_DiMu_DY" ] = &EF_2mu6i_DiMu_DY;
      fHandles[ "EF_2mu6i_DiMu_DY_2j25_a4tchad" ] = &EF_2mu6i_DiMu_DY_2j25_a4tchad;
      fHandles[ "EF_2mu6i_DiMu_DY_noVtx_noOS" ] = &EF_2mu6i_DiMu_DY_noVtx_noOS;
      fHandles[ "EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" ] = &EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
      fHandles[ "EF_2mu8_EFxe30" ] = &EF_2mu8_EFxe30;
      fHandles[ "EF_2mu8_EFxe30_tclcw" ] = &EF_2mu8_EFxe30_tclcw;
      fHandles[ "EF_2tau29T_medium1" ] = &EF_2tau29T_medium1;
      fHandles[ "EF_2tau29_medium1" ] = &EF_2tau29_medium1;
      fHandles[ "EF_2tau29i_medium1" ] = &EF_2tau29i_medium1;
      fHandles[ "EF_2tau38T_medium" ] = &EF_2tau38T_medium;
      fHandles[ "EF_2tau38T_medium1" ] = &EF_2tau38T_medium1;
      fHandles[ "EF_2tau38T_medium1_llh" ] = &EF_2tau38T_medium1_llh;
      fHandles[ "EF_b110_loose_j110_a4tchad_xe55_tclcw" ] = &EF_b110_loose_j110_a4tchad_xe55_tclcw;
      fHandles[ "EF_b110_loose_j110_a4tchad_xe60_tclcw" ] = &EF_b110_loose_j110_a4tchad_xe60_tclcw;
      fHandles[ "EF_b45_mediumEF_j110_j45_xe60_tclcw" ] = &EF_b45_mediumEF_j110_j45_xe60_tclcw;
      fHandles[ "EF_b55_mediumEF_j110_j55_xe60_tclcw" ] = &EF_b55_mediumEF_j110_j55_xe60_tclcw;
      fHandles[ "EF_b80_loose_j80_a4tchad_xe55_tclcw" ] = &EF_b80_loose_j80_a4tchad_xe55_tclcw;
      fHandles[ "EF_b80_loose_j80_a4tchad_xe60_tclcw" ] = &EF_b80_loose_j80_a4tchad_xe60_tclcw;
      fHandles[ "EF_b80_loose_j80_a4tchad_xe70_tclcw" ] = &EF_b80_loose_j80_a4tchad_xe70_tclcw;
      fHandles[ "EF_b80_loose_j80_a4tchad_xe75_tclcw" ] = &EF_b80_loose_j80_a4tchad_xe75_tclcw;
      fHandles[ "EF_e11_etcut" ] = &EF_e11_etcut;
      fHandles[ "EF_e12Tvh_loose1" ] = &EF_e12Tvh_loose1;
      fHandles[ "EF_e12Tvh_loose1_mu8" ] = &EF_e12Tvh_loose1_mu8;
      fHandles[ "EF_e12Tvh_medium1" ] = &EF_e12Tvh_medium1;
      fHandles[ "EF_e12Tvh_medium1_mu10" ] = &EF_e12Tvh_medium1_mu10;
      fHandles[ "EF_e12Tvh_medium1_mu6" ] = &EF_e12Tvh_medium1_mu6;
      fHandles[ "EF_e12Tvh_medium1_mu6_topo_medium" ] = &EF_e12Tvh_medium1_mu6_topo_medium;
      fHandles[ "EF_e12Tvh_medium1_mu8" ] = &EF_e12Tvh_medium1_mu8;
      fHandles[ "EF_e13_etcutTrk_xs60" ] = &EF_e13_etcutTrk_xs60;
      fHandles[ "EF_e13_etcutTrk_xs60_dphi2j15xe20" ] = &EF_e13_etcutTrk_xs60_dphi2j15xe20;
      fHandles[ "EF_e14_tight1_e4_etcut_Jpsi" ] = &EF_e14_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_e15vh_medium1" ] = &EF_e15vh_medium1;
      fHandles[ "EF_e18_loose1" ] = &EF_e18_loose1;
      fHandles[ "EF_e18_loose1_g25_medium" ] = &EF_e18_loose1_g25_medium;
      fHandles[ "EF_e18_loose1_g35_loose" ] = &EF_e18_loose1_g35_loose;
      fHandles[ "EF_e18_loose1_g35_medium" ] = &EF_e18_loose1_g35_medium;
      fHandles[ "EF_e18_medium1" ] = &EF_e18_medium1;
      fHandles[ "EF_e18_medium1_g25_loose" ] = &EF_e18_medium1_g25_loose;
      fHandles[ "EF_e18_medium1_g25_medium" ] = &EF_e18_medium1_g25_medium;
      fHandles[ "EF_e18_medium1_g35_loose" ] = &EF_e18_medium1_g35_loose;
      fHandles[ "EF_e18_medium1_g35_medium" ] = &EF_e18_medium1_g35_medium;
      fHandles[ "EF_e18vh_medium1" ] = &EF_e18vh_medium1;
      fHandles[ "EF_e18vh_medium1_2e7T_medium1" ] = &EF_e18vh_medium1_2e7T_medium1;
      fHandles[ "EF_e20_etcutTrk_xe30_dphi2j15xe20" ] = &EF_e20_etcutTrk_xe30_dphi2j15xe20;
      fHandles[ "EF_e20_etcutTrk_xs60_dphi2j15xe20" ] = &EF_e20_etcutTrk_xs60_dphi2j15xe20;
      fHandles[ "EF_e20vhT_medium1_g6T_etcut_Upsi" ] = &EF_e20vhT_medium1_g6T_etcut_Upsi;
      fHandles[ "EF_e20vhT_tight1_g6T_etcut_Upsi" ] = &EF_e20vhT_tight1_g6T_etcut_Upsi;
      fHandles[ "EF_e22vh_loose" ] = &EF_e22vh_loose;
      fHandles[ "EF_e22vh_loose0" ] = &EF_e22vh_loose0;
      fHandles[ "EF_e22vh_loose1" ] = &EF_e22vh_loose1;
      fHandles[ "EF_e22vh_medium1" ] = &EF_e22vh_medium1;
      fHandles[ "EF_e22vh_medium1_IDTrkNoCut" ] = &EF_e22vh_medium1_IDTrkNoCut;
      fHandles[ "EF_e22vh_medium1_IdScan" ] = &EF_e22vh_medium1_IdScan;
      fHandles[ "EF_e22vh_medium1_SiTrk" ] = &EF_e22vh_medium1_SiTrk;
      fHandles[ "EF_e22vh_medium1_TRT" ] = &EF_e22vh_medium1_TRT;
      fHandles[ "EF_e22vhi_medium1" ] = &EF_e22vhi_medium1;
      fHandles[ "EF_e24vh_loose" ] = &EF_e24vh_loose;
      fHandles[ "EF_e24vh_loose0" ] = &EF_e24vh_loose0;
      fHandles[ "EF_e24vh_loose1" ] = &EF_e24vh_loose1;
      fHandles[ "EF_e24vh_medium1" ] = &EF_e24vh_medium1;
      fHandles[ "EF_e24vh_medium1_EFxe30" ] = &EF_e24vh_medium1_EFxe30;
      fHandles[ "EF_e24vh_medium1_EFxe30_tcem" ] = &EF_e24vh_medium1_EFxe30_tcem;
      fHandles[ "EF_e24vh_medium1_EFxe35_tcem" ] = &EF_e24vh_medium1_EFxe35_tcem;
      fHandles[ "EF_e24vh_medium1_EFxe35_tclcw" ] = &EF_e24vh_medium1_EFxe35_tclcw;
      fHandles[ "EF_e24vh_medium1_EFxe40" ] = &EF_e24vh_medium1_EFxe40;
      fHandles[ "EF_e24vh_medium1_IDTrkNoCut" ] = &EF_e24vh_medium1_IDTrkNoCut;
      fHandles[ "EF_e24vh_medium1_IdScan" ] = &EF_e24vh_medium1_IdScan;
      fHandles[ "EF_e24vh_medium1_L2StarB" ] = &EF_e24vh_medium1_L2StarB;
      fHandles[ "EF_e24vh_medium1_L2StarC" ] = &EF_e24vh_medium1_L2StarC;
      fHandles[ "EF_e24vh_medium1_SiTrk" ] = &EF_e24vh_medium1_SiTrk;
      fHandles[ "EF_e24vh_medium1_TRT" ] = &EF_e24vh_medium1_TRT;
      fHandles[ "EF_e24vh_medium1_b35_mediumEF_j35_a4tchad" ] = &EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;
      fHandles[ "EF_e24vh_medium1_e7_medium1" ] = &EF_e24vh_medium1_e7_medium1;
      fHandles[ "EF_e24vh_tight1_e15_NoCut_Zee" ] = &EF_e24vh_tight1_e15_NoCut_Zee;
      fHandles[ "EF_e24vhi_loose1_mu8" ] = &EF_e24vhi_loose1_mu8;
      fHandles[ "EF_e24vhi_medium1" ] = &EF_e24vhi_medium1;
      fHandles[ "EF_e45_etcut" ] = &EF_e45_etcut;
      fHandles[ "EF_e45_medium1" ] = &EF_e45_medium1;
      fHandles[ "EF_e5_tight1" ] = &EF_e5_tight1;
      fHandles[ "EF_e5_tight1_e14_etcut_Jpsi" ] = &EF_e5_tight1_e14_etcut_Jpsi;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi" ] = &EF_e5_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_IdScan" ] = &EF_e5_tight1_e4_etcut_Jpsi_IdScan;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_L2StarB" ] = &EF_e5_tight1_e4_etcut_Jpsi_L2StarB;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_L2StarC" ] = &EF_e5_tight1_e4_etcut_Jpsi_L2StarC;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_SiTrk" ] = &EF_e5_tight1_e4_etcut_Jpsi_SiTrk;
      fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_TRT" ] = &EF_e5_tight1_e4_etcut_Jpsi_TRT;
      fHandles[ "EF_e5_tight1_e5_NoCut" ] = &EF_e5_tight1_e5_NoCut;
      fHandles[ "EF_e5_tight1_e9_etcut_Jpsi" ] = &EF_e5_tight1_e9_etcut_Jpsi;
      fHandles[ "EF_e60_etcut" ] = &EF_e60_etcut;
      fHandles[ "EF_e60_medium1" ] = &EF_e60_medium1;
      fHandles[ "EF_e7T_loose1" ] = &EF_e7T_loose1;
      fHandles[ "EF_e7T_loose1_2mu6" ] = &EF_e7T_loose1_2mu6;
      fHandles[ "EF_e7T_medium1" ] = &EF_e7T_medium1;
      fHandles[ "EF_e7T_medium1_2mu6" ] = &EF_e7T_medium1_2mu6;
      fHandles[ "EF_e9_tight1_e4_etcut_Jpsi" ] = &EF_e9_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_eb_physics" ] = &EF_eb_physics;
      fHandles[ "EF_eb_physics_empty" ] = &EF_eb_physics_empty;
      fHandles[ "EF_eb_physics_firstempty" ] = &EF_eb_physics_firstempty;
      fHandles[ "EF_eb_physics_noL1PS" ] = &EF_eb_physics_noL1PS;
      fHandles[ "EF_eb_physics_unpaired_iso" ] = &EF_eb_physics_unpaired_iso;
      fHandles[ "EF_eb_physics_unpaired_noniso" ] = &EF_eb_physics_unpaired_noniso;
      fHandles[ "EF_eb_random" ] = &EF_eb_random;
      fHandles[ "EF_eb_random_empty" ] = &EF_eb_random_empty;
      fHandles[ "EF_eb_random_firstempty" ] = &EF_eb_random_firstempty;
      fHandles[ "EF_eb_random_unpaired_iso" ] = &EF_eb_random_unpaired_iso;
      fHandles[ "EF_g100_loose" ] = &EF_g100_loose;
      fHandles[ "EF_g10_NoCut_cosmic" ] = &EF_g10_NoCut_cosmic;
      fHandles[ "EF_g10_loose" ] = &EF_g10_loose;
      fHandles[ "EF_g10_medium" ] = &EF_g10_medium;
      fHandles[ "EF_g120_loose" ] = &EF_g120_loose;
      fHandles[ "EF_g12Tvh_loose" ] = &EF_g12Tvh_loose;
      fHandles[ "EF_g12Tvh_loose_larcalib" ] = &EF_g12Tvh_loose_larcalib;
      fHandles[ "EF_g12Tvh_medium" ] = &EF_g12Tvh_medium;
      fHandles[ "EF_g15_loose" ] = &EF_g15_loose;
      fHandles[ "EF_g15vh_loose" ] = &EF_g15vh_loose;
      fHandles[ "EF_g15vh_medium" ] = &EF_g15vh_medium;
      fHandles[ "EF_g200_etcut" ] = &EF_g200_etcut;
      fHandles[ "EF_g20Tvh_medium" ] = &EF_g20Tvh_medium;
      fHandles[ "EF_g20_etcut" ] = &EF_g20_etcut;
      fHandles[ "EF_g20_loose" ] = &EF_g20_loose;
      fHandles[ "EF_g20_loose_larcalib" ] = &EF_g20_loose_larcalib;
      fHandles[ "EF_g20_medium" ] = &EF_g20_medium;
      fHandles[ "EF_g20vh_medium" ] = &EF_g20vh_medium;
      fHandles[ "EF_g30_loose_g20_loose" ] = &EF_g30_loose_g20_loose;
      fHandles[ "EF_g30_medium_g20_medium" ] = &EF_g30_medium_g20_medium;
      fHandles[ "EF_g35_loose_g25_loose" ] = &EF_g35_loose_g25_loose;
      fHandles[ "EF_g35_loose_g30_loose" ] = &EF_g35_loose_g30_loose;
      fHandles[ "EF_g40_loose" ] = &EF_g40_loose;
      fHandles[ "EF_g40_loose_EFxe50" ] = &EF_g40_loose_EFxe50;
      fHandles[ "EF_g40_loose_L2EFxe50" ] = &EF_g40_loose_L2EFxe50;
      fHandles[ "EF_g40_loose_L2EFxe60" ] = &EF_g40_loose_L2EFxe60;
      fHandles[ "EF_g40_loose_L2EFxe60_tclcw" ] = &EF_g40_loose_L2EFxe60_tclcw;
      fHandles[ "EF_g40_loose_g25_loose" ] = &EF_g40_loose_g25_loose;
      fHandles[ "EF_g40_loose_g30_loose" ] = &EF_g40_loose_g30_loose;
      fHandles[ "EF_g40_loose_larcalib" ] = &EF_g40_loose_larcalib;
      fHandles[ "EF_g5_NoCut_cosmic" ] = &EF_g5_NoCut_cosmic;
      fHandles[ "EF_g60_loose" ] = &EF_g60_loose;
      fHandles[ "EF_g60_loose_larcalib" ] = &EF_g60_loose_larcalib;
      fHandles[ "EF_g80_loose" ] = &EF_g80_loose;
      fHandles[ "EF_g80_loose_larcalib" ] = &EF_g80_loose_larcalib;
      fHandles[ "EF_j10_a4tchadloose" ] = &EF_j10_a4tchadloose;
      fHandles[ "EF_j10_a4tchadloose_L1MBTS" ] = &EF_j10_a4tchadloose_L1MBTS;
      fHandles[ "EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS" ] = &EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS;
      fHandles[ "EF_j110_2j55_a4tchad" ] = &EF_j110_2j55_a4tchad;
      fHandles[ "EF_j110_2j55_a4tchad_L2FS" ] = &EF_j110_2j55_a4tchad_L2FS;
      fHandles[ "EF_j110_a10tcem_L2FS" ] = &EF_j110_a10tcem_L2FS;
      fHandles[ "EF_j110_a10tcem_L2FS_2j55_a4tchad" ] = &EF_j110_a10tcem_L2FS_2j55_a4tchad;
      fHandles[ "EF_j110_a4tchad" ] = &EF_j110_a4tchad;
      fHandles[ "EF_j110_a4tchad_xe100_tclcw" ] = &EF_j110_a4tchad_xe100_tclcw;
      fHandles[ "EF_j110_a4tchad_xe100_tclcw_veryloose" ] = &EF_j110_a4tchad_xe100_tclcw_veryloose;
      fHandles[ "EF_j110_a4tchad_xe50_tclcw" ] = &EF_j110_a4tchad_xe50_tclcw;
      fHandles[ "EF_j110_a4tchad_xe55_tclcw" ] = &EF_j110_a4tchad_xe55_tclcw;
      fHandles[ "EF_j110_a4tchad_xe60_tclcw" ] = &EF_j110_a4tchad_xe60_tclcw;
      fHandles[ "EF_j110_a4tchad_xe60_tclcw_loose" ] = &EF_j110_a4tchad_xe60_tclcw_loose;
      fHandles[ "EF_j110_a4tchad_xe60_tclcw_veryloose" ] = &EF_j110_a4tchad_xe60_tclcw_veryloose;
      fHandles[ "EF_j110_a4tchad_xe65_tclcw" ] = &EF_j110_a4tchad_xe65_tclcw;
      fHandles[ "EF_j110_a4tchad_xe70_tclcw_loose" ] = &EF_j110_a4tchad_xe70_tclcw_loose;
      fHandles[ "EF_j110_a4tchad_xe70_tclcw_veryloose" ] = &EF_j110_a4tchad_xe70_tclcw_veryloose;
      fHandles[ "EF_j110_a4tchad_xe75_tclcw" ] = &EF_j110_a4tchad_xe75_tclcw;
      fHandles[ "EF_j110_a4tchad_xe80_tclcw_loose" ] = &EF_j110_a4tchad_xe80_tclcw_loose;
      fHandles[ "EF_j110_a4tchad_xe90_tclcw_loose" ] = &EF_j110_a4tchad_xe90_tclcw_loose;
      fHandles[ "EF_j110_a4tchad_xe90_tclcw_veryloose" ] = &EF_j110_a4tchad_xe90_tclcw_veryloose;
      fHandles[ "EF_j110_a4tclcw_xe100_tclcw_veryloose" ] = &EF_j110_a4tclcw_xe100_tclcw_veryloose;
      fHandles[ "EF_j145_2j45_a4tchad_L2EFxe70_tclcw" ] = &EF_j145_2j45_a4tchad_L2EFxe70_tclcw;
      fHandles[ "EF_j145_a10tcem_L2FS" ] = &EF_j145_a10tcem_L2FS;
      fHandles[ "EF_j145_a10tcem_L2FS_L2xe60_tclcw" ] = &EF_j145_a10tcem_L2FS_L2xe60_tclcw;
      fHandles[ "EF_j145_a4tchad" ] = &EF_j145_a4tchad;
      fHandles[ "EF_j145_a4tchad_L2EFxe60_tclcw" ] = &EF_j145_a4tchad_L2EFxe60_tclcw;
      fHandles[ "EF_j145_a4tchad_L2EFxe70_tclcw" ] = &EF_j145_a4tchad_L2EFxe70_tclcw;
      fHandles[ "EF_j145_a4tchad_L2EFxe80_tclcw" ] = &EF_j145_a4tchad_L2EFxe80_tclcw;
      fHandles[ "EF_j145_a4tchad_L2EFxe90_tclcw" ] = &EF_j145_a4tchad_L2EFxe90_tclcw;
      fHandles[ "EF_j145_a4tchad_ht500_L2FS" ] = &EF_j145_a4tchad_ht500_L2FS;
      fHandles[ "EF_j145_a4tchad_ht600_L2FS" ] = &EF_j145_a4tchad_ht600_L2FS;
      fHandles[ "EF_j145_a4tchad_ht700_L2FS" ] = &EF_j145_a4tchad_ht700_L2FS;
      fHandles[ "EF_j145_a4tclcw_L2EFxe90_tclcw" ] = &EF_j145_a4tclcw_L2EFxe90_tclcw;
      fHandles[ "EF_j145_j100_j35_a4tchad" ] = &EF_j145_j100_j35_a4tchad;
      fHandles[ "EF_j15_a4tchad" ] = &EF_j15_a4tchad;
      fHandles[ "EF_j15_a4tchad_L1MBTS" ] = &EF_j15_a4tchad_L1MBTS;
      fHandles[ "EF_j15_a4tchad_L1TE20" ] = &EF_j15_a4tchad_L1TE20;
      fHandles[ "EF_j15_fj15_a4tchad_deta50_FC_L1MBTS" ] = &EF_j15_fj15_a4tchad_deta50_FC_L1MBTS;
      fHandles[ "EF_j15_fj15_a4tchad_deta50_FC_L1TE20" ] = &EF_j15_fj15_a4tchad_deta50_FC_L1TE20;
      fHandles[ "EF_j165_u0uchad_LArNoiseBurst" ] = &EF_j165_u0uchad_LArNoiseBurst;
      fHandles[ "EF_j170_a4tchad_EFxe50_tclcw" ] = &EF_j170_a4tchad_EFxe50_tclcw;
      fHandles[ "EF_j170_a4tchad_EFxe60_tclcw" ] = &EF_j170_a4tchad_EFxe60_tclcw;
      fHandles[ "EF_j170_a4tchad_EFxe70_tclcw" ] = &EF_j170_a4tchad_EFxe70_tclcw;
      fHandles[ "EF_j170_a4tchad_EFxe80_tclcw" ] = &EF_j170_a4tchad_EFxe80_tclcw;
      fHandles[ "EF_j170_a4tchad_ht500" ] = &EF_j170_a4tchad_ht500;
      fHandles[ "EF_j170_a4tchad_ht600" ] = &EF_j170_a4tchad_ht600;
      fHandles[ "EF_j170_a4tchad_ht700" ] = &EF_j170_a4tchad_ht700;
      fHandles[ "EF_j180_a10tcem" ] = &EF_j180_a10tcem;
      fHandles[ "EF_j180_a10tcem_EFxe50_tclcw" ] = &EF_j180_a10tcem_EFxe50_tclcw;
      fHandles[ "EF_j180_a10tcem_e45_loose1" ] = &EF_j180_a10tcem_e45_loose1;
      fHandles[ "EF_j180_a10tclcw_EFxe50_tclcw" ] = &EF_j180_a10tclcw_EFxe50_tclcw;
      fHandles[ "EF_j180_a4tchad" ] = &EF_j180_a4tchad;
      fHandles[ "EF_j180_a4tclcw" ] = &EF_j180_a4tclcw;
      fHandles[ "EF_j180_a4tthad" ] = &EF_j180_a4tthad;
      fHandles[ "EF_j220_a10tcem_e45_etcut" ] = &EF_j220_a10tcem_e45_etcut;
      fHandles[ "EF_j220_a10tcem_e45_loose1" ] = &EF_j220_a10tcem_e45_loose1;
      fHandles[ "EF_j220_a10tcem_e60_etcut" ] = &EF_j220_a10tcem_e60_etcut;
      fHandles[ "EF_j220_a4tchad" ] = &EF_j220_a4tchad;
      fHandles[ "EF_j220_a4tthad" ] = &EF_j220_a4tthad;
      fHandles[ "EF_j240_a10tcem" ] = &EF_j240_a10tcem;
      fHandles[ "EF_j240_a10tcem_e45_etcut" ] = &EF_j240_a10tcem_e45_etcut;
      fHandles[ "EF_j240_a10tcem_e45_loose1" ] = &EF_j240_a10tcem_e45_loose1;
      fHandles[ "EF_j240_a10tcem_e60_etcut" ] = &EF_j240_a10tcem_e60_etcut;
      fHandles[ "EF_j240_a10tcem_e60_loose1" ] = &EF_j240_a10tcem_e60_loose1;
      fHandles[ "EF_j240_a10tclcw" ] = &EF_j240_a10tclcw;
      fHandles[ "EF_j25_a4tchad" ] = &EF_j25_a4tchad;
      fHandles[ "EF_j25_a4tchad_L1MBTS" ] = &EF_j25_a4tchad_L1MBTS;
      fHandles[ "EF_j25_a4tchad_L1TE20" ] = &EF_j25_a4tchad_L1TE20;
      fHandles[ "EF_j25_fj25_a4tchad_deta50_FC_L1MBTS" ] = &EF_j25_fj25_a4tchad_deta50_FC_L1MBTS;
      fHandles[ "EF_j25_fj25_a4tchad_deta50_FC_L1TE20" ] = &EF_j25_fj25_a4tchad_deta50_FC_L1TE20;
      fHandles[ "EF_j260_a4tthad" ] = &EF_j260_a4tthad;
      fHandles[ "EF_j280_a10tclcw_L2FS" ] = &EF_j280_a10tclcw_L2FS;
      fHandles[ "EF_j280_a4tchad" ] = &EF_j280_a4tchad;
      fHandles[ "EF_j280_a4tchad_mjj2000dy34" ] = &EF_j280_a4tchad_mjj2000dy34;
      fHandles[ "EF_j30_a4tcem_eta13_xe30_empty" ] = &EF_j30_a4tcem_eta13_xe30_empty;
      fHandles[ "EF_j30_a4tcem_eta13_xe30_firstempty" ] = &EF_j30_a4tcem_eta13_xe30_firstempty;
      fHandles[ "EF_j30_u0uchad_empty_LArNoiseBurst" ] = &EF_j30_u0uchad_empty_LArNoiseBurst;
      fHandles[ "EF_j35_a10tcem" ] = &EF_j35_a10tcem;
      fHandles[ "EF_j35_a4tcem_L1TAU_LOF_HV" ] = &EF_j35_a4tcem_L1TAU_LOF_HV;
      fHandles[ "EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY" ] = &EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY;
      fHandles[ "EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO" ] = &EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO;
      fHandles[ "EF_j35_a4tchad" ] = &EF_j35_a4tchad;
      fHandles[ "EF_j35_a4tchad_L1MBTS" ] = &EF_j35_a4tchad_L1MBTS;
      fHandles[ "EF_j35_a4tchad_L1TE20" ] = &EF_j35_a4tchad_L1TE20;
      fHandles[ "EF_j35_a4tclcw" ] = &EF_j35_a4tclcw;
      fHandles[ "EF_j35_a4tthad" ] = &EF_j35_a4tthad;
      fHandles[ "EF_j35_fj35_a4tchad_deta50_FC_L1MBTS" ] = &EF_j35_fj35_a4tchad_deta50_FC_L1MBTS;
      fHandles[ "EF_j35_fj35_a4tchad_deta50_FC_L1TE20" ] = &EF_j35_fj35_a4tchad_deta50_FC_L1TE20;
      fHandles[ "EF_j360_a10tcem" ] = &EF_j360_a10tcem;
      fHandles[ "EF_j360_a10tclcw" ] = &EF_j360_a10tclcw;
      fHandles[ "EF_j360_a4tchad" ] = &EF_j360_a4tchad;
      fHandles[ "EF_j360_a4tclcw" ] = &EF_j360_a4tclcw;
      fHandles[ "EF_j360_a4tthad" ] = &EF_j360_a4tthad;
      fHandles[ "EF_j380_a4tthad" ] = &EF_j380_a4tthad;
      fHandles[ "EF_j45_a10tcem_L1RD0" ] = &EF_j45_a10tcem_L1RD0;
      fHandles[ "EF_j45_a4tchad" ] = &EF_j45_a4tchad;
      fHandles[ "EF_j45_a4tchad_L1RD0" ] = &EF_j45_a4tchad_L1RD0;
      fHandles[ "EF_j45_a4tchad_L2FS" ] = &EF_j45_a4tchad_L2FS;
      fHandles[ "EF_j45_a4tchad_L2FS_L1RD0" ] = &EF_j45_a4tchad_L2FS_L1RD0;
      fHandles[ "EF_j460_a10tcem" ] = &EF_j460_a10tcem;
      fHandles[ "EF_j460_a10tclcw" ] = &EF_j460_a10tclcw;
      fHandles[ "EF_j460_a4tchad" ] = &EF_j460_a4tchad;
      fHandles[ "EF_j50_a4tcem_eta13_xe50_empty" ] = &EF_j50_a4tcem_eta13_xe50_empty;
      fHandles[ "EF_j50_a4tcem_eta13_xe50_firstempty" ] = &EF_j50_a4tcem_eta13_xe50_firstempty;
      fHandles[ "EF_j50_a4tcem_eta25_xe50_empty" ] = &EF_j50_a4tcem_eta25_xe50_empty;
      fHandles[ "EF_j50_a4tcem_eta25_xe50_firstempty" ] = &EF_j50_a4tcem_eta25_xe50_firstempty;
      fHandles[ "EF_j55_a4tchad" ] = &EF_j55_a4tchad;
      fHandles[ "EF_j55_a4tchad_L2FS" ] = &EF_j55_a4tchad_L2FS;
      fHandles[ "EF_j55_a4tclcw" ] = &EF_j55_a4tclcw;
      fHandles[ "EF_j55_u0uchad_firstempty_LArNoiseBurst" ] = &EF_j55_u0uchad_firstempty_LArNoiseBurst;
      fHandles[ "EF_j65_a4tchad_L2FS" ] = &EF_j65_a4tchad_L2FS;
      fHandles[ "EF_j80_a10tcem_L2FS" ] = &EF_j80_a10tcem_L2FS;
      fHandles[ "EF_j80_a4tchad" ] = &EF_j80_a4tchad;
      fHandles[ "EF_j80_a4tchad_xe100_tclcw_loose" ] = &EF_j80_a4tchad_xe100_tclcw_loose;
      fHandles[ "EF_j80_a4tchad_xe100_tclcw_veryloose" ] = &EF_j80_a4tchad_xe100_tclcw_veryloose;
      fHandles[ "EF_j80_a4tchad_xe55_tclcw" ] = &EF_j80_a4tchad_xe55_tclcw;
      fHandles[ "EF_j80_a4tchad_xe60_tclcw" ] = &EF_j80_a4tchad_xe60_tclcw;
      fHandles[ "EF_j80_a4tchad_xe70_tclcw" ] = &EF_j80_a4tchad_xe70_tclcw;
      fHandles[ "EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10" ] = &EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10;
      fHandles[ "EF_j80_a4tchad_xe70_tclcw_loose" ] = &EF_j80_a4tchad_xe70_tclcw_loose;
      fHandles[ "EF_j80_a4tchad_xe80_tclcw_loose" ] = &EF_j80_a4tchad_xe80_tclcw_loose;
      fHandles[ "EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10" ] = &EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10;
      fHandles[ "EF_mu10" ] = &EF_mu10;
      fHandles[ "EF_mu10_Jpsimumu" ] = &EF_mu10_Jpsimumu;
      fHandles[ "EF_mu10_MSonly" ] = &EF_mu10_MSonly;
      fHandles[ "EF_mu10_Upsimumu_tight_FS" ] = &EF_mu10_Upsimumu_tight_FS;
      fHandles[ "EF_mu10i_g10_loose" ] = &EF_mu10i_g10_loose;
      fHandles[ "EF_mu10i_g10_loose_TauMass" ] = &EF_mu10i_g10_loose_TauMass;
      fHandles[ "EF_mu10i_g10_medium" ] = &EF_mu10i_g10_medium;
      fHandles[ "EF_mu10i_g10_medium_TauMass" ] = &EF_mu10i_g10_medium_TauMass;
      fHandles[ "EF_mu10i_loose_g12Tvh_loose" ] = &EF_mu10i_loose_g12Tvh_loose;
      fHandles[ "EF_mu10i_loose_g12Tvh_loose_TauMass" ] = &EF_mu10i_loose_g12Tvh_loose_TauMass;
      fHandles[ "EF_mu10i_loose_g12Tvh_medium" ] = &EF_mu10i_loose_g12Tvh_medium;
      fHandles[ "EF_mu10i_loose_g12Tvh_medium_TauMass" ] = &EF_mu10i_loose_g12Tvh_medium_TauMass;
      fHandles[ "EF_mu11_empty_NoAlg" ] = &EF_mu11_empty_NoAlg;
      fHandles[ "EF_mu13" ] = &EF_mu13;
      fHandles[ "EF_mu15" ] = &EF_mu15;
      fHandles[ "EF_mu18" ] = &EF_mu18;
      fHandles[ "EF_mu18_2g10_loose" ] = &EF_mu18_2g10_loose;
      fHandles[ "EF_mu18_2g10_medium" ] = &EF_mu18_2g10_medium;
      fHandles[ "EF_mu18_2g15_loose" ] = &EF_mu18_2g15_loose;
      fHandles[ "EF_mu18_IDTrkNoCut_tight" ] = &EF_mu18_IDTrkNoCut_tight;
      fHandles[ "EF_mu18_g20vh_loose" ] = &EF_mu18_g20vh_loose;
      fHandles[ "EF_mu18_medium" ] = &EF_mu18_medium;
      fHandles[ "EF_mu18_tight" ] = &EF_mu18_tight;
      fHandles[ "EF_mu18_tight_2mu4_EFFS" ] = &EF_mu18_tight_2mu4_EFFS;
      fHandles[ "EF_mu18_tight_e7_medium1" ] = &EF_mu18_tight_e7_medium1;
      fHandles[ "EF_mu18_tight_mu8_EFFS" ] = &EF_mu18_tight_mu8_EFFS;
      fHandles[ "EF_mu18i4_tight" ] = &EF_mu18i4_tight;
      fHandles[ "EF_mu18it_tight" ] = &EF_mu18it_tight;
      fHandles[ "EF_mu20i_tight_g5_loose" ] = &EF_mu20i_tight_g5_loose;
      fHandles[ "EF_mu20i_tight_g5_loose_TauMass" ] = &EF_mu20i_tight_g5_loose_TauMass;
      fHandles[ "EF_mu20i_tight_g5_medium" ] = &EF_mu20i_tight_g5_medium;
      fHandles[ "EF_mu20i_tight_g5_medium_TauMass" ] = &EF_mu20i_tight_g5_medium_TauMass;
      fHandles[ "EF_mu20it_tight" ] = &EF_mu20it_tight;
      fHandles[ "EF_mu22_IDTrkNoCut_tight" ] = &EF_mu22_IDTrkNoCut_tight;
      fHandles[ "EF_mu24" ] = &EF_mu24;
      fHandles[ "EF_mu24_g20vh_loose" ] = &EF_mu24_g20vh_loose;
      fHandles[ "EF_mu24_g20vh_medium" ] = &EF_mu24_g20vh_medium;
      fHandles[ "EF_mu24_j65_a4tchad" ] = &EF_mu24_j65_a4tchad;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe40" ] = &EF_mu24_j65_a4tchad_EFxe40;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe40_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe40_tclcw;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe50_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe50_tclcw;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe60_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe60_tclcw;
      fHandles[ "EF_mu24_medium" ] = &EF_mu24_medium;
      fHandles[ "EF_mu24_muCombTag_NoEF_tight" ] = &EF_mu24_muCombTag_NoEF_tight;
      fHandles[ "EF_mu24_tight" ] = &EF_mu24_tight;
      fHandles[ "EF_mu24_tight_2j35_a4tchad" ] = &EF_mu24_tight_2j35_a4tchad;
      fHandles[ "EF_mu24_tight_3j35_a4tchad" ] = &EF_mu24_tight_3j35_a4tchad;
      fHandles[ "EF_mu24_tight_4j35_a4tchad" ] = &EF_mu24_tight_4j35_a4tchad;
      fHandles[ "EF_mu24_tight_EFxe40" ] = &EF_mu24_tight_EFxe40;
      fHandles[ "EF_mu24_tight_L2StarB" ] = &EF_mu24_tight_L2StarB;
      fHandles[ "EF_mu24_tight_L2StarC" ] = &EF_mu24_tight_L2StarC;
      fHandles[ "EF_mu24_tight_MG" ] = &EF_mu24_tight_MG;
      fHandles[ "EF_mu24_tight_MuonEF" ] = &EF_mu24_tight_MuonEF;
      fHandles[ "EF_mu24_tight_b35_mediumEF_j35_a4tchad" ] = &EF_mu24_tight_b35_mediumEF_j35_a4tchad;
      fHandles[ "EF_mu24_tight_mu6_EFFS" ] = &EF_mu24_tight_mu6_EFFS;
      fHandles[ "EF_mu24i_tight" ] = &EF_mu24i_tight;
      fHandles[ "EF_mu24i_tight_MG" ] = &EF_mu24i_tight_MG;
      fHandles[ "EF_mu24i_tight_MuonEF" ] = &EF_mu24i_tight_MuonEF;
      fHandles[ "EF_mu24i_tight_l2muonSA" ] = &EF_mu24i_tight_l2muonSA;
      fHandles[ "EF_mu36_tight" ] = &EF_mu36_tight;
      fHandles[ "EF_mu40_MSonly_barrel_tight" ] = &EF_mu40_MSonly_barrel_tight;
      fHandles[ "EF_mu40_muCombTag_NoEF" ] = &EF_mu40_muCombTag_NoEF;
      fHandles[ "EF_mu40_slow_outOfTime_tight" ] = &EF_mu40_slow_outOfTime_tight;
      fHandles[ "EF_mu40_slow_tight" ] = &EF_mu40_slow_tight;
      fHandles[ "EF_mu40_tight" ] = &EF_mu40_tight;
      fHandles[ "EF_mu4T" ] = &EF_mu4T;
      fHandles[ "EF_mu4T_Trk_Jpsi" ] = &EF_mu4T_Trk_Jpsi;
      fHandles[ "EF_mu4T_cosmic" ] = &EF_mu4T_cosmic;
      fHandles[ "EF_mu4T_j110_a4tchad_L2FS_matched" ] = &EF_mu4T_j110_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j110_a4tchad_matched" ] = &EF_mu4T_j110_a4tchad_matched;
      fHandles[ "EF_mu4T_j145_a4tchad_L2FS_matched" ] = &EF_mu4T_j145_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j145_a4tchad_matched" ] = &EF_mu4T_j145_a4tchad_matched;
      fHandles[ "EF_mu4T_j15_a4tchad_matched" ] = &EF_mu4T_j15_a4tchad_matched;
      fHandles[ "EF_mu4T_j15_a4tchad_matchedZ" ] = &EF_mu4T_j15_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j180_a4tchad_L2FS_matched" ] = &EF_mu4T_j180_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j180_a4tchad_matched" ] = &EF_mu4T_j180_a4tchad_matched;
      fHandles[ "EF_mu4T_j220_a4tchad_L2FS_matched" ] = &EF_mu4T_j220_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j220_a4tchad_matched" ] = &EF_mu4T_j220_a4tchad_matched;
      fHandles[ "EF_mu4T_j25_a4tchad_matched" ] = &EF_mu4T_j25_a4tchad_matched;
      fHandles[ "EF_mu4T_j25_a4tchad_matchedZ" ] = &EF_mu4T_j25_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j280_a4tchad_L2FS_matched" ] = &EF_mu4T_j280_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j280_a4tchad_matched" ] = &EF_mu4T_j280_a4tchad_matched;
      fHandles[ "EF_mu4T_j35_a4tchad_matched" ] = &EF_mu4T_j35_a4tchad_matched;
      fHandles[ "EF_mu4T_j35_a4tchad_matchedZ" ] = &EF_mu4T_j35_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j360_a4tchad_L2FS_matched" ] = &EF_mu4T_j360_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j360_a4tchad_matched" ] = &EF_mu4T_j360_a4tchad_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_L2FS_matched" ] = &EF_mu4T_j45_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_L2FS_matchedZ" ] = &EF_mu4T_j45_a4tchad_L2FS_matchedZ;
      fHandles[ "EF_mu4T_j45_a4tchad_matched" ] = &EF_mu4T_j45_a4tchad_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_matchedZ" ] = &EF_mu4T_j45_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j55_a4tchad_L2FS_matched" ] = &EF_mu4T_j55_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j55_a4tchad_L2FS_matchedZ" ] = &EF_mu4T_j55_a4tchad_L2FS_matchedZ;
      fHandles[ "EF_mu4T_j55_a4tchad_matched" ] = &EF_mu4T_j55_a4tchad_matched;
      fHandles[ "EF_mu4T_j55_a4tchad_matchedZ" ] = &EF_mu4T_j55_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j65_a4tchad_L2FS_matched" ] = &EF_mu4T_j65_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j65_a4tchad_matched" ] = &EF_mu4T_j65_a4tchad_matched;
      fHandles[ "EF_mu4T_j65_a4tchad_xe60_tclcw_loose" ] = &EF_mu4T_j65_a4tchad_xe60_tclcw_loose;
      fHandles[ "EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose" ] = &EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;
      fHandles[ "EF_mu4T_j80_a4tchad_L2FS_matched" ] = &EF_mu4T_j80_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j80_a4tchad_matched" ] = &EF_mu4T_j80_a4tchad_matched;
      fHandles[ "EF_mu4Ti_g20Tvh_loose" ] = &EF_mu4Ti_g20Tvh_loose;
      fHandles[ "EF_mu4Ti_g20Tvh_loose_TauMass" ] = &EF_mu4Ti_g20Tvh_loose_TauMass;
      fHandles[ "EF_mu4Ti_g20Tvh_medium" ] = &EF_mu4Ti_g20Tvh_medium;
      fHandles[ "EF_mu4Ti_g20Tvh_medium_TauMass" ] = &EF_mu4Ti_g20Tvh_medium_TauMass;
      fHandles[ "EF_mu4Tmu6_Bmumu" ] = &EF_mu4Tmu6_Bmumu;
      fHandles[ "EF_mu4Tmu6_Bmumu_Barrel" ] = &EF_mu4Tmu6_Bmumu_Barrel;
      fHandles[ "EF_mu4Tmu6_Bmumux" ] = &EF_mu4Tmu6_Bmumux;
      fHandles[ "EF_mu4Tmu6_Bmumux_Barrel" ] = &EF_mu4Tmu6_Bmumux_Barrel;
      fHandles[ "EF_mu4Tmu6_DiMu" ] = &EF_mu4Tmu6_DiMu;
      fHandles[ "EF_mu4Tmu6_DiMu_Barrel" ] = &EF_mu4Tmu6_DiMu_Barrel;
      fHandles[ "EF_mu4Tmu6_DiMu_noVtx_noOS" ] = &EF_mu4Tmu6_DiMu_noVtx_noOS;
      fHandles[ "EF_mu4Tmu6_Jpsimumu" ] = &EF_mu4Tmu6_Jpsimumu;
      fHandles[ "EF_mu4Tmu6_Jpsimumu_Barrel" ] = &EF_mu4Tmu6_Jpsimumu_Barrel;
      fHandles[ "EF_mu4Tmu6_Jpsimumu_IDTrkNoCut" ] = &EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;
      fHandles[ "EF_mu4Tmu6_Upsimumu" ] = &EF_mu4Tmu6_Upsimumu;
      fHandles[ "EF_mu4Tmu6_Upsimumu_Barrel" ] = &EF_mu4Tmu6_Upsimumu_Barrel;
      fHandles[ "EF_mu4_L1MU11_MSonly_cosmic" ] = &EF_mu4_L1MU11_MSonly_cosmic;
      fHandles[ "EF_mu4_L1MU11_cosmic" ] = &EF_mu4_L1MU11_cosmic;
      fHandles[ "EF_mu4_empty_NoAlg" ] = &EF_mu4_empty_NoAlg;
      fHandles[ "EF_mu4_firstempty_NoAlg" ] = &EF_mu4_firstempty_NoAlg;
      fHandles[ "EF_mu4_unpaired_iso_NoAlg" ] = &EF_mu4_unpaired_iso_NoAlg;
      fHandles[ "EF_mu50_MSonly_barrel_tight" ] = &EF_mu50_MSonly_barrel_tight;
      fHandles[ "EF_mu6" ] = &EF_mu6;
      fHandles[ "EF_mu60_slow_outOfTime_tight1" ] = &EF_mu60_slow_outOfTime_tight1;
      fHandles[ "EF_mu60_slow_tight1" ] = &EF_mu60_slow_tight1;
      fHandles[ "EF_mu6_Jpsimumu_tight" ] = &EF_mu6_Jpsimumu_tight;
      fHandles[ "EF_mu6_MSonly" ] = &EF_mu6_MSonly;
      fHandles[ "EF_mu6_Trk_Jpsi_loose" ] = &EF_mu6_Trk_Jpsi_loose;
      fHandles[ "EF_mu6i" ] = &EF_mu6i;
      fHandles[ "EF_mu8" ] = &EF_mu8;
      fHandles[ "EF_mu8_4j45_a4tchad_L2FS" ] = &EF_mu8_4j45_a4tchad_L2FS;
      fHandles[ "EF_tau125_IDTrkNoCut" ] = &EF_tau125_IDTrkNoCut;
      fHandles[ "EF_tau125_medium1" ] = &EF_tau125_medium1;
      fHandles[ "EF_tau125_medium1_L2StarA" ] = &EF_tau125_medium1_L2StarA;
      fHandles[ "EF_tau125_medium1_L2StarB" ] = &EF_tau125_medium1_L2StarB;
      fHandles[ "EF_tau125_medium1_L2StarC" ] = &EF_tau125_medium1_L2StarC;
      fHandles[ "EF_tau125_medium1_llh" ] = &EF_tau125_medium1_llh;
      fHandles[ "EF_tau20T_medium" ] = &EF_tau20T_medium;
      fHandles[ "EF_tau20T_medium1" ] = &EF_tau20T_medium1;
      fHandles[ "EF_tau20T_medium1_e15vh_medium1" ] = &EF_tau20T_medium1_e15vh_medium1;
      fHandles[ "EF_tau20T_medium1_mu15i" ] = &EF_tau20T_medium1_mu15i;
      fHandles[ "EF_tau20T_medium_mu15" ] = &EF_tau20T_medium_mu15;
      fHandles[ "EF_tau20Ti_medium" ] = &EF_tau20Ti_medium;
      fHandles[ "EF_tau20Ti_medium1" ] = &EF_tau20Ti_medium1;
      fHandles[ "EF_tau20Ti_medium1_e18vh_medium1" ] = &EF_tau20Ti_medium1_e18vh_medium1;
      fHandles[ "EF_tau20Ti_medium1_llh_e18vh_medium1" ] = &EF_tau20Ti_medium1_llh_e18vh_medium1;
      fHandles[ "EF_tau20Ti_medium_e18vh_medium1" ] = &EF_tau20Ti_medium_e18vh_medium1;
      fHandles[ "EF_tau20Ti_tight1" ] = &EF_tau20Ti_tight1;
      fHandles[ "EF_tau20Ti_tight1_llh" ] = &EF_tau20Ti_tight1_llh;
      fHandles[ "EF_tau20_medium" ] = &EF_tau20_medium;
      fHandles[ "EF_tau20_medium1" ] = &EF_tau20_medium1;
      fHandles[ "EF_tau20_medium1_llh" ] = &EF_tau20_medium1_llh;
      fHandles[ "EF_tau20_medium1_llh_mu15" ] = &EF_tau20_medium1_llh_mu15;
      fHandles[ "EF_tau20_medium1_mu15" ] = &EF_tau20_medium1_mu15;
      fHandles[ "EF_tau20_medium1_mu15i" ] = &EF_tau20_medium1_mu15i;
      fHandles[ "EF_tau20_medium1_mu18" ] = &EF_tau20_medium1_mu18;
      fHandles[ "EF_tau20_medium_llh" ] = &EF_tau20_medium_llh;
      fHandles[ "EF_tau20_medium_mu15" ] = &EF_tau20_medium_mu15;
      fHandles[ "EF_tau29T_medium" ] = &EF_tau29T_medium;
      fHandles[ "EF_tau29T_medium1" ] = &EF_tau29T_medium1;
      fHandles[ "EF_tau29T_medium1_tau20T_medium1" ] = &EF_tau29T_medium1_tau20T_medium1;
      fHandles[ "EF_tau29T_medium1_xe40_tight" ] = &EF_tau29T_medium1_xe40_tight;
      fHandles[ "EF_tau29T_medium1_xe45_tight" ] = &EF_tau29T_medium1_xe45_tight;
      fHandles[ "EF_tau29T_medium_xe40_tight" ] = &EF_tau29T_medium_xe40_tight;
      fHandles[ "EF_tau29T_medium_xe45_tight" ] = &EF_tau29T_medium_xe45_tight;
      fHandles[ "EF_tau29T_tight1" ] = &EF_tau29T_tight1;
      fHandles[ "EF_tau29T_tight1_llh" ] = &EF_tau29T_tight1_llh;
      fHandles[ "EF_tau29Ti_medium1" ] = &EF_tau29Ti_medium1;
      fHandles[ "EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh" ] = &EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh;
      fHandles[ "EF_tau29Ti_medium1_llh_xe40_tight" ] = &EF_tau29Ti_medium1_llh_xe40_tight;
      fHandles[ "EF_tau29Ti_medium1_llh_xe45_tight" ] = &EF_tau29Ti_medium1_llh_xe45_tight;
      fHandles[ "EF_tau29Ti_medium1_tau20Ti_medium1" ] = &EF_tau29Ti_medium1_tau20Ti_medium1;
      fHandles[ "EF_tau29Ti_medium1_xe40_tight" ] = &EF_tau29Ti_medium1_xe40_tight;
      fHandles[ "EF_tau29Ti_medium1_xe45_tight" ] = &EF_tau29Ti_medium1_xe45_tight;
      fHandles[ "EF_tau29Ti_medium1_xe55_tclcw" ] = &EF_tau29Ti_medium1_xe55_tclcw;
      fHandles[ "EF_tau29Ti_medium1_xe55_tclcw_tight" ] = &EF_tau29Ti_medium1_xe55_tclcw_tight;
      fHandles[ "EF_tau29Ti_medium_xe40_tight" ] = &EF_tau29Ti_medium_xe40_tight;
      fHandles[ "EF_tau29Ti_medium_xe45_tight" ] = &EF_tau29Ti_medium_xe45_tight;
      fHandles[ "EF_tau29Ti_tight1" ] = &EF_tau29Ti_tight1;
      fHandles[ "EF_tau29Ti_tight1_llh" ] = &EF_tau29Ti_tight1_llh;
      fHandles[ "EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh" ] = &EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh;
      fHandles[ "EF_tau29Ti_tight1_tau20Ti_tight1" ] = &EF_tau29Ti_tight1_tau20Ti_tight1;
      fHandles[ "EF_tau29_IDTrkNoCut" ] = &EF_tau29_IDTrkNoCut;
      fHandles[ "EF_tau29_medium" ] = &EF_tau29_medium;
      fHandles[ "EF_tau29_medium1" ] = &EF_tau29_medium1;
      fHandles[ "EF_tau29_medium1_llh" ] = &EF_tau29_medium1_llh;
      fHandles[ "EF_tau29_medium_2stTest" ] = &EF_tau29_medium_2stTest;
      fHandles[ "EF_tau29_medium_L2StarA" ] = &EF_tau29_medium_L2StarA;
      fHandles[ "EF_tau29_medium_L2StarB" ] = &EF_tau29_medium_L2StarB;
      fHandles[ "EF_tau29_medium_L2StarC" ] = &EF_tau29_medium_L2StarC;
      fHandles[ "EF_tau29_medium_llh" ] = &EF_tau29_medium_llh;
      fHandles[ "EF_tau29i_medium" ] = &EF_tau29i_medium;
      fHandles[ "EF_tau29i_medium1" ] = &EF_tau29i_medium1;
      fHandles[ "EF_tau38T_medium" ] = &EF_tau38T_medium;
      fHandles[ "EF_tau38T_medium1" ] = &EF_tau38T_medium1;
      fHandles[ "EF_tau38T_medium1_e18vh_medium1" ] = &EF_tau38T_medium1_e18vh_medium1;
      fHandles[ "EF_tau38T_medium1_llh_e18vh_medium1" ] = &EF_tau38T_medium1_llh_e18vh_medium1;
      fHandles[ "EF_tau38T_medium1_xe40_tight" ] = &EF_tau38T_medium1_xe40_tight;
      fHandles[ "EF_tau38T_medium1_xe45_tight" ] = &EF_tau38T_medium1_xe45_tight;
      fHandles[ "EF_tau38T_medium1_xe55_tclcw_tight" ] = &EF_tau38T_medium1_xe55_tclcw_tight;
      fHandles[ "EF_tau38T_medium_e18vh_medium1" ] = &EF_tau38T_medium_e18vh_medium1;
      fHandles[ "EF_tau50_medium" ] = &EF_tau50_medium;
      fHandles[ "EF_tau50_medium1_e18vh_medium1" ] = &EF_tau50_medium1_e18vh_medium1;
      fHandles[ "EF_tau50_medium_e15vh_medium1" ] = &EF_tau50_medium_e15vh_medium1;
      fHandles[ "EF_tauNoCut" ] = &EF_tauNoCut;
      fHandles[ "EF_tauNoCut_L1TAU40" ] = &EF_tauNoCut_L1TAU40;
      fHandles[ "EF_tauNoCut_cosmic" ] = &EF_tauNoCut_cosmic;
      fHandles[ "EF_xe100" ] = &EF_xe100;
      fHandles[ "EF_xe100T_tclcw" ] = &EF_xe100T_tclcw;
      fHandles[ "EF_xe100T_tclcw_loose" ] = &EF_xe100T_tclcw_loose;
      fHandles[ "EF_xe100_tclcw" ] = &EF_xe100_tclcw;
      fHandles[ "EF_xe100_tclcw_loose" ] = &EF_xe100_tclcw_loose;
      fHandles[ "EF_xe100_tclcw_veryloose" ] = &EF_xe100_tclcw_veryloose;
      fHandles[ "EF_xe100_tclcw_verytight" ] = &EF_xe100_tclcw_verytight;
      fHandles[ "EF_xe100_tight" ] = &EF_xe100_tight;
      fHandles[ "EF_xe110" ] = &EF_xe110;
      fHandles[ "EF_xe30" ] = &EF_xe30;
      fHandles[ "EF_xe30_tclcw" ] = &EF_xe30_tclcw;
      fHandles[ "EF_xe40" ] = &EF_xe40;
      fHandles[ "EF_xe50" ] = &EF_xe50;
      fHandles[ "EF_xe55_LArNoiseBurst" ] = &EF_xe55_LArNoiseBurst;
      fHandles[ "EF_xe55_tclcw" ] = &EF_xe55_tclcw;
      fHandles[ "EF_xe60" ] = &EF_xe60;
      fHandles[ "EF_xe60T" ] = &EF_xe60T;
      fHandles[ "EF_xe60_tclcw" ] = &EF_xe60_tclcw;
      fHandles[ "EF_xe60_tclcw_loose" ] = &EF_xe60_tclcw_loose;
      fHandles[ "EF_xe70" ] = &EF_xe70;
      fHandles[ "EF_xe70_tclcw_loose" ] = &EF_xe70_tclcw_loose;
      fHandles[ "EF_xe70_tclcw_veryloose" ] = &EF_xe70_tclcw_veryloose;
      fHandles[ "EF_xe70_tight" ] = &EF_xe70_tight;
      fHandles[ "EF_xe70_tight_tclcw" ] = &EF_xe70_tight_tclcw;
      fHandles[ "EF_xe75_tclcw" ] = &EF_xe75_tclcw;
      fHandles[ "EF_xe80" ] = &EF_xe80;
      fHandles[ "EF_xe80T" ] = &EF_xe80T;
      fHandles[ "EF_xe80T_loose" ] = &EF_xe80T_loose;
      fHandles[ "EF_xe80T_tclcw" ] = &EF_xe80T_tclcw;
      fHandles[ "EF_xe80T_tclcw_loose" ] = &EF_xe80T_tclcw_loose;
      fHandles[ "EF_xe80_tclcw" ] = &EF_xe80_tclcw;
      fHandles[ "EF_xe80_tclcw_loose" ] = &EF_xe80_tclcw_loose;
      fHandles[ "EF_xe80_tclcw_tight" ] = &EF_xe80_tclcw_tight;
      fHandles[ "EF_xe80_tclcw_verytight" ] = &EF_xe80_tclcw_verytight;
      fHandles[ "EF_xe80_tight" ] = &EF_xe80_tight;
      fHandles[ "EF_xe90" ] = &EF_xe90;
      fHandles[ "EF_xe90_tclcw" ] = &EF_xe90_tclcw;
      fHandles[ "EF_xe90_tclcw_tight" ] = &EF_xe90_tclcw_tight;
      fHandles[ "EF_xe90_tclcw_veryloose" ] = &EF_xe90_tclcw_veryloose;
      fHandles[ "EF_xe90_tclcw_verytight" ] = &EF_xe90_tclcw_verytight;
      fHandles[ "EF_xe90_tight" ] = &EF_xe90_tight;
      fHandles[ "L1_2EM10VH" ] = &L1_2EM10VH;
      fHandles[ "L1_2EM12" ] = &L1_2EM12;
      fHandles[ "L1_2EM12_EM16V" ] = &L1_2EM12_EM16V;
      fHandles[ "L1_2EM3" ] = &L1_2EM3;
      fHandles[ "L1_2EM3_EM12" ] = &L1_2EM3_EM12;
      fHandles[ "L1_2EM3_EM6" ] = &L1_2EM3_EM6;
      fHandles[ "L1_2EM6" ] = &L1_2EM6;
      fHandles[ "L1_2EM6_EM16VH" ] = &L1_2EM6_EM16VH;
      fHandles[ "L1_2EM6_MU6" ] = &L1_2EM6_MU6;
      fHandles[ "L1_2J20_XE20" ] = &L1_2J20_XE20;
      fHandles[ "L1_2J30_XE20" ] = &L1_2J30_XE20;
      fHandles[ "L1_2MU10" ] = &L1_2MU10;
      fHandles[ "L1_2MU4" ] = &L1_2MU4;
      fHandles[ "L1_2MU4_2EM3" ] = &L1_2MU4_2EM3;
      fHandles[ "L1_2MU4_BARREL" ] = &L1_2MU4_BARREL;
      fHandles[ "L1_2MU4_BARRELONLY" ] = &L1_2MU4_BARRELONLY;
      fHandles[ "L1_2MU4_EM3" ] = &L1_2MU4_EM3;
      fHandles[ "L1_2MU4_EMPTY" ] = &L1_2MU4_EMPTY;
      fHandles[ "L1_2MU4_FIRSTEMPTY" ] = &L1_2MU4_FIRSTEMPTY;
      fHandles[ "L1_2MU4_MU6" ] = &L1_2MU4_MU6;
      fHandles[ "L1_2MU4_MU6_BARREL" ] = &L1_2MU4_MU6_BARREL;
      fHandles[ "L1_2MU4_XE30" ] = &L1_2MU4_XE30;
      fHandles[ "L1_2MU4_XE40" ] = &L1_2MU4_XE40;
      fHandles[ "L1_2MU6" ] = &L1_2MU6;
      fHandles[ "L1_2MU6_UNPAIRED_ISO" ] = &L1_2MU6_UNPAIRED_ISO;
      fHandles[ "L1_2MU6_UNPAIRED_NONISO" ] = &L1_2MU6_UNPAIRED_NONISO;
      fHandles[ "L1_2TAU11" ] = &L1_2TAU11;
      fHandles[ "L1_2TAU11I" ] = &L1_2TAU11I;
      fHandles[ "L1_2TAU11I_EM14VH" ] = &L1_2TAU11I_EM14VH;
      fHandles[ "L1_2TAU11I_TAU15" ] = &L1_2TAU11I_TAU15;
      fHandles[ "L1_2TAU11_EM10VH" ] = &L1_2TAU11_EM10VH;
      fHandles[ "L1_2TAU11_TAU15" ] = &L1_2TAU11_TAU15;
      fHandles[ "L1_2TAU11_TAU20_EM10VH" ] = &L1_2TAU11_TAU20_EM10VH;
      fHandles[ "L1_2TAU11_TAU20_EM14VH" ] = &L1_2TAU11_TAU20_EM14VH;
      fHandles[ "L1_2TAU15" ] = &L1_2TAU15;
      fHandles[ "L1_2TAU20" ] = &L1_2TAU20;
      fHandles[ "L1_EM10VH" ] = &L1_EM10VH;
      fHandles[ "L1_EM10VH_MU6" ] = &L1_EM10VH_MU6;
      fHandles[ "L1_EM10VH_XE20" ] = &L1_EM10VH_XE20;
      fHandles[ "L1_EM10VH_XE30" ] = &L1_EM10VH_XE30;
      fHandles[ "L1_EM10VH_XE35" ] = &L1_EM10VH_XE35;
      fHandles[ "L1_EM12" ] = &L1_EM12;
      fHandles[ "L1_EM12_3J10" ] = &L1_EM12_3J10;
      fHandles[ "L1_EM12_4J10" ] = &L1_EM12_4J10;
      fHandles[ "L1_EM12_XE20" ] = &L1_EM12_XE20;
      fHandles[ "L1_EM12_XS30" ] = &L1_EM12_XS30;
      fHandles[ "L1_EM12_XS45" ] = &L1_EM12_XS45;
      fHandles[ "L1_EM14VH" ] = &L1_EM14VH;
      fHandles[ "L1_EM16V" ] = &L1_EM16V;
      fHandles[ "L1_EM16VH" ] = &L1_EM16VH;
      fHandles[ "L1_EM16VH_MU4" ] = &L1_EM16VH_MU4;
      fHandles[ "L1_EM16V_XE20" ] = &L1_EM16V_XE20;
      fHandles[ "L1_EM16V_XS45" ] = &L1_EM16V_XS45;
      fHandles[ "L1_EM18VH" ] = &L1_EM18VH;
      fHandles[ "L1_EM3" ] = &L1_EM3;
      fHandles[ "L1_EM30" ] = &L1_EM30;
      fHandles[ "L1_EM30_BGRP7" ] = &L1_EM30_BGRP7;
      fHandles[ "L1_EM3_EMPTY" ] = &L1_EM3_EMPTY;
      fHandles[ "L1_EM3_FIRSTEMPTY" ] = &L1_EM3_FIRSTEMPTY;
      fHandles[ "L1_EM3_MU6" ] = &L1_EM3_MU6;
      fHandles[ "L1_EM3_UNPAIRED_ISO" ] = &L1_EM3_UNPAIRED_ISO;
      fHandles[ "L1_EM3_UNPAIRED_NONISO" ] = &L1_EM3_UNPAIRED_NONISO;
      fHandles[ "L1_EM6" ] = &L1_EM6;
      fHandles[ "L1_EM6_2MU6" ] = &L1_EM6_2MU6;
      fHandles[ "L1_EM6_EMPTY" ] = &L1_EM6_EMPTY;
      fHandles[ "L1_EM6_MU10" ] = &L1_EM6_MU10;
      fHandles[ "L1_EM6_MU6" ] = &L1_EM6_MU6;
      fHandles[ "L1_EM6_XS45" ] = &L1_EM6_XS45;
      fHandles[ "L1_J30_XE35" ] = &L1_J30_XE35;
      fHandles[ "L1_J30_XE40" ] = &L1_J30_XE40;
      fHandles[ "L1_J30_XE50" ] = &L1_J30_XE50;
      fHandles[ "L1_J50_XE30" ] = &L1_J50_XE30;
      fHandles[ "L1_J50_XE35" ] = &L1_J50_XE35;
      fHandles[ "L1_J50_XE40" ] = &L1_J50_XE40;
      fHandles[ "L1_MU10" ] = &L1_MU10;
      fHandles[ "L1_MU10_EMPTY" ] = &L1_MU10_EMPTY;
      fHandles[ "L1_MU10_FIRSTEMPTY" ] = &L1_MU10_FIRSTEMPTY;
      fHandles[ "L1_MU10_J20" ] = &L1_MU10_J20;
      fHandles[ "L1_MU10_UNPAIRED_ISO" ] = &L1_MU10_UNPAIRED_ISO;
      fHandles[ "L1_MU10_XE20" ] = &L1_MU10_XE20;
      fHandles[ "L1_MU10_XE25" ] = &L1_MU10_XE25;
      fHandles[ "L1_MU11" ] = &L1_MU11;
      fHandles[ "L1_MU11_EMPTY" ] = &L1_MU11_EMPTY;
      fHandles[ "L1_MU15" ] = &L1_MU15;
      fHandles[ "L1_MU20" ] = &L1_MU20;
      fHandles[ "L1_MU20_FIRSTEMPTY" ] = &L1_MU20_FIRSTEMPTY;
      fHandles[ "L1_MU4" ] = &L1_MU4;
      fHandles[ "L1_MU4_EMPTY" ] = &L1_MU4_EMPTY;
      fHandles[ "L1_MU4_FIRSTEMPTY" ] = &L1_MU4_FIRSTEMPTY;
      fHandles[ "L1_MU4_J10" ] = &L1_MU4_J10;
      fHandles[ "L1_MU4_J15" ] = &L1_MU4_J15;
      fHandles[ "L1_MU4_J15_EMPTY" ] = &L1_MU4_J15_EMPTY;
      fHandles[ "L1_MU4_J15_UNPAIRED_ISO" ] = &L1_MU4_J15_UNPAIRED_ISO;
      fHandles[ "L1_MU4_J20_XE20" ] = &L1_MU4_J20_XE20;
      fHandles[ "L1_MU4_J20_XE35" ] = &L1_MU4_J20_XE35;
      fHandles[ "L1_MU4_J30" ] = &L1_MU4_J30;
      fHandles[ "L1_MU4_J50" ] = &L1_MU4_J50;
      fHandles[ "L1_MU4_J75" ] = &L1_MU4_J75;
      fHandles[ "L1_MU4_UNPAIRED_ISO" ] = &L1_MU4_UNPAIRED_ISO;
      fHandles[ "L1_MU4_UNPAIRED_NONISO" ] = &L1_MU4_UNPAIRED_NONISO;
      fHandles[ "L1_MU6" ] = &L1_MU6;
      fHandles[ "L1_MU6_2J20" ] = &L1_MU6_2J20;
      fHandles[ "L1_MU6_FIRSTEMPTY" ] = &L1_MU6_FIRSTEMPTY;
      fHandles[ "L1_MU6_J15" ] = &L1_MU6_J15;
      fHandles[ "L1_MUB" ] = &L1_MUB;
      fHandles[ "L1_MUE" ] = &L1_MUE;
      fHandles[ "L1_TAU11" ] = &L1_TAU11;
      fHandles[ "L1_TAU11I" ] = &L1_TAU11I;
      fHandles[ "L1_TAU11_MU10" ] = &L1_TAU11_MU10;
      fHandles[ "L1_TAU11_XE20" ] = &L1_TAU11_XE20;
      fHandles[ "L1_TAU15" ] = &L1_TAU15;
      fHandles[ "L1_TAU15I" ] = &L1_TAU15I;
      fHandles[ "L1_TAU15I_XE35" ] = &L1_TAU15I_XE35;
      fHandles[ "L1_TAU15I_XE40" ] = &L1_TAU15I_XE40;
      fHandles[ "L1_TAU15_XE25_3J10" ] = &L1_TAU15_XE25_3J10;
      fHandles[ "L1_TAU15_XE25_3J10_J30" ] = &L1_TAU15_XE25_3J10_J30;
      fHandles[ "L1_TAU15_XE25_3J15" ] = &L1_TAU15_XE25_3J15;
      fHandles[ "L1_TAU15_XE35" ] = &L1_TAU15_XE35;
      fHandles[ "L1_TAU15_XE40" ] = &L1_TAU15_XE40;
      fHandles[ "L1_TAU15_XS25_3J10" ] = &L1_TAU15_XS25_3J10;
      fHandles[ "L1_TAU15_XS35" ] = &L1_TAU15_XS35;
      fHandles[ "L1_TAU20" ] = &L1_TAU20;
      fHandles[ "L1_TAU20_XE35" ] = &L1_TAU20_XE35;
      fHandles[ "L1_TAU20_XE40" ] = &L1_TAU20_XE40;
      fHandles[ "L1_TAU40" ] = &L1_TAU40;
      fHandles[ "L1_TAU8" ] = &L1_TAU8;
      fHandles[ "L1_TAU8_EMPTY" ] = &L1_TAU8_EMPTY;
      fHandles[ "L1_TAU8_FIRSTEMPTY" ] = &L1_TAU8_FIRSTEMPTY;
      fHandles[ "L1_TAU8_MU10" ] = &L1_TAU8_MU10;
      fHandles[ "L1_TAU8_UNPAIRED_ISO" ] = &L1_TAU8_UNPAIRED_ISO;
      fHandles[ "L1_TAU8_UNPAIRED_NONISO" ] = &L1_TAU8_UNPAIRED_NONISO;
      fHandles[ "L1_XE20" ] = &L1_XE20;
      fHandles[ "L1_XE25" ] = &L1_XE25;
      fHandles[ "L1_XE30" ] = &L1_XE30;
      fHandles[ "L1_XE35" ] = &L1_XE35;
      fHandles[ "L1_XE40" ] = &L1_XE40;
      fHandles[ "L1_XE40_BGRP7" ] = &L1_XE40_BGRP7;
      fHandles[ "L1_XE50" ] = &L1_XE50;
      fHandles[ "L1_XE50_BGRP7" ] = &L1_XE50_BGRP7;
      fHandles[ "L1_XE60" ] = &L1_XE60;
      fHandles[ "L1_XE70" ] = &L1_XE70;
      fHandles[ "L2_2e12Tvh_loose1" ] = &L2_2e12Tvh_loose1;
      fHandles[ "L2_2e5_tight1_Jpsi" ] = &L2_2e5_tight1_Jpsi;
      fHandles[ "L2_2e7T_loose1_mu6" ] = &L2_2e7T_loose1_mu6;
      fHandles[ "L2_2e7T_medium1_mu6" ] = &L2_2e7T_medium1_mu6;
      fHandles[ "L2_2g15vh_loose_g10_loose" ] = &L2_2g15vh_loose_g10_loose;
      fHandles[ "L2_2g15vh_medium" ] = &L2_2g15vh_medium;
      fHandles[ "L2_2g15vh_medium_g10_medium" ] = &L2_2g15vh_medium_g10_medium;
      fHandles[ "L2_2g20_loose" ] = &L2_2g20_loose;
      fHandles[ "L2_2g20vh_medium" ] = &L2_2g20vh_medium;
      fHandles[ "L2_2g30_loose" ] = &L2_2g30_loose;
      fHandles[ "L2_2g40_loose" ] = &L2_2g40_loose;
      fHandles[ "L2_2mu10" ] = &L2_2mu10;
      fHandles[ "L2_2mu10_MSonly_g10_loose" ] = &L2_2mu10_MSonly_g10_loose;
      fHandles[ "L2_2mu10_MSonly_g10_loose_EMPTY" ] = &L2_2mu10_MSonly_g10_loose_EMPTY;
      fHandles[ "L2_2mu10_MSonly_g10_loose_UNPAIRED_ISO" ] = &L2_2mu10_MSonly_g10_loose_UNPAIRED_ISO;
      fHandles[ "L2_2mu13" ] = &L2_2mu13;
      fHandles[ "L2_2mu13_Zmumu_IDTrkNoCut" ] = &L2_2mu13_Zmumu_IDTrkNoCut;
      fHandles[ "L2_2mu13_l2muonSA" ] = &L2_2mu13_l2muonSA;
      fHandles[ "L2_2mu15" ] = &L2_2mu15;
      fHandles[ "L2_2mu4T" ] = &L2_2mu4T;
      fHandles[ "L2_2mu4T_2e5_tight1" ] = &L2_2mu4T_2e5_tight1;
      fHandles[ "L2_2mu4T_Bmumu" ] = &L2_2mu4T_Bmumu;
      fHandles[ "L2_2mu4T_Bmumu_Barrel" ] = &L2_2mu4T_Bmumu_Barrel;
      fHandles[ "L2_2mu4T_Bmumu_BarrelOnly" ] = &L2_2mu4T_Bmumu_BarrelOnly;
      fHandles[ "L2_2mu4T_Bmumux" ] = &L2_2mu4T_Bmumux;
      fHandles[ "L2_2mu4T_Bmumux_Barrel" ] = &L2_2mu4T_Bmumux_Barrel;
      fHandles[ "L2_2mu4T_Bmumux_BarrelOnly" ] = &L2_2mu4T_Bmumux_BarrelOnly;
      fHandles[ "L2_2mu4T_DiMu" ] = &L2_2mu4T_DiMu;
      fHandles[ "L2_2mu4T_DiMu_Barrel" ] = &L2_2mu4T_DiMu_Barrel;
      fHandles[ "L2_2mu4T_DiMu_BarrelOnly" ] = &L2_2mu4T_DiMu_BarrelOnly;
      fHandles[ "L2_2mu4T_DiMu_L2StarB" ] = &L2_2mu4T_DiMu_L2StarB;
      fHandles[ "L2_2mu4T_DiMu_L2StarC" ] = &L2_2mu4T_DiMu_L2StarC;
      fHandles[ "L2_2mu4T_DiMu_e5_tight1" ] = &L2_2mu4T_DiMu_e5_tight1;
      fHandles[ "L2_2mu4T_DiMu_l2muonSA" ] = &L2_2mu4T_DiMu_l2muonSA;
      fHandles[ "L2_2mu4T_DiMu_noVtx_noOS" ] = &L2_2mu4T_DiMu_noVtx_noOS;
      fHandles[ "L2_2mu4T_Jpsimumu" ] = &L2_2mu4T_Jpsimumu;
      fHandles[ "L2_2mu4T_Jpsimumu_Barrel" ] = &L2_2mu4T_Jpsimumu_Barrel;
      fHandles[ "L2_2mu4T_Jpsimumu_BarrelOnly" ] = &L2_2mu4T_Jpsimumu_BarrelOnly;
      fHandles[ "L2_2mu4T_Jpsimumu_IDTrkNoCut" ] = &L2_2mu4T_Jpsimumu_IDTrkNoCut;
      fHandles[ "L2_2mu4T_Upsimumu" ] = &L2_2mu4T_Upsimumu;
      fHandles[ "L2_2mu4T_Upsimumu_Barrel" ] = &L2_2mu4T_Upsimumu_Barrel;
      fHandles[ "L2_2mu4T_Upsimumu_BarrelOnly" ] = &L2_2mu4T_Upsimumu_BarrelOnly;
      fHandles[ "L2_2mu4T_xe35" ] = &L2_2mu4T_xe35;
      fHandles[ "L2_2mu4T_xe45" ] = &L2_2mu4T_xe45;
      fHandles[ "L2_2mu4T_xe60" ] = &L2_2mu4T_xe60;
      fHandles[ "L2_2mu6" ] = &L2_2mu6;
      fHandles[ "L2_2mu6_Bmumu" ] = &L2_2mu6_Bmumu;
      fHandles[ "L2_2mu6_Bmumux" ] = &L2_2mu6_Bmumux;
      fHandles[ "L2_2mu6_DiMu" ] = &L2_2mu6_DiMu;
      fHandles[ "L2_2mu6_DiMu_DY20" ] = &L2_2mu6_DiMu_DY20;
      fHandles[ "L2_2mu6_DiMu_DY25" ] = &L2_2mu6_DiMu_DY25;
      fHandles[ "L2_2mu6_DiMu_noVtx_noOS" ] = &L2_2mu6_DiMu_noVtx_noOS;
      fHandles[ "L2_2mu6_Jpsimumu" ] = &L2_2mu6_Jpsimumu;
      fHandles[ "L2_2mu6_Upsimumu" ] = &L2_2mu6_Upsimumu;
      fHandles[ "L2_2mu6i_DiMu_DY" ] = &L2_2mu6i_DiMu_DY;
      fHandles[ "L2_2mu6i_DiMu_DY_2j25_a4tchad" ] = &L2_2mu6i_DiMu_DY_2j25_a4tchad;
      fHandles[ "L2_2mu6i_DiMu_DY_noVtx_noOS" ] = &L2_2mu6i_DiMu_DY_noVtx_noOS;
      fHandles[ "L2_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" ] = &L2_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
      fHandles[ "L2_2mu8_EFxe30" ] = &L2_2mu8_EFxe30;
      fHandles[ "L2_2tau29T_medium1" ] = &L2_2tau29T_medium1;
      fHandles[ "L2_2tau29_medium1" ] = &L2_2tau29_medium1;
      fHandles[ "L2_2tau29i_medium1" ] = &L2_2tau29i_medium1;
      fHandles[ "L2_2tau38T_medium" ] = &L2_2tau38T_medium;
      fHandles[ "L2_2tau38T_medium1" ] = &L2_2tau38T_medium1;
      fHandles[ "L2_2tau38T_medium1_llh" ] = &L2_2tau38T_medium1_llh;
      fHandles[ "L2_b105_loose_j105_c4cchad_xe40" ] = &L2_b105_loose_j105_c4cchad_xe40;
      fHandles[ "L2_b105_loose_j105_c4cchad_xe45" ] = &L2_b105_loose_j105_c4cchad_xe45;
      fHandles[ "L2_b75_loose_j75_c4cchad_xe40" ] = &L2_b75_loose_j75_c4cchad_xe40;
      fHandles[ "L2_b75_loose_j75_c4cchad_xe45" ] = &L2_b75_loose_j75_c4cchad_xe45;
      fHandles[ "L2_b75_loose_j75_c4cchad_xe55" ] = &L2_b75_loose_j75_c4cchad_xe55;
      fHandles[ "L2_e11_etcut" ] = &L2_e11_etcut;
      fHandles[ "L2_e12Tvh_loose1" ] = &L2_e12Tvh_loose1;
      fHandles[ "L2_e12Tvh_loose1_mu8" ] = &L2_e12Tvh_loose1_mu8;
      fHandles[ "L2_e12Tvh_medium1" ] = &L2_e12Tvh_medium1;
      fHandles[ "L2_e12Tvh_medium1_mu10" ] = &L2_e12Tvh_medium1_mu10;
      fHandles[ "L2_e12Tvh_medium1_mu6" ] = &L2_e12Tvh_medium1_mu6;
      fHandles[ "L2_e12Tvh_medium1_mu6_topo_medium" ] = &L2_e12Tvh_medium1_mu6_topo_medium;
      fHandles[ "L2_e12Tvh_medium1_mu8" ] = &L2_e12Tvh_medium1_mu8;
      fHandles[ "L2_e13_etcutTrk_xs45" ] = &L2_e13_etcutTrk_xs45;
      fHandles[ "L2_e14_tight1_e4_etcut_Jpsi" ] = &L2_e14_tight1_e4_etcut_Jpsi;
      fHandles[ "L2_e15vh_medium1" ] = &L2_e15vh_medium1;
      fHandles[ "L2_e18_loose1" ] = &L2_e18_loose1;
      fHandles[ "L2_e18_loose1_g25_medium" ] = &L2_e18_loose1_g25_medium;
      fHandles[ "L2_e18_loose1_g35_loose" ] = &L2_e18_loose1_g35_loose;
      fHandles[ "L2_e18_loose1_g35_medium" ] = &L2_e18_loose1_g35_medium;
      fHandles[ "L2_e18_medium1" ] = &L2_e18_medium1;
      fHandles[ "L2_e18_medium1_g25_loose" ] = &L2_e18_medium1_g25_loose;
      fHandles[ "L2_e18_medium1_g25_medium" ] = &L2_e18_medium1_g25_medium;
      fHandles[ "L2_e18_medium1_g35_loose" ] = &L2_e18_medium1_g35_loose;
      fHandles[ "L2_e18_medium1_g35_medium" ] = &L2_e18_medium1_g35_medium;
      fHandles[ "L2_e18vh_medium1" ] = &L2_e18vh_medium1;
      fHandles[ "L2_e18vh_medium1_2e7T_medium1" ] = &L2_e18vh_medium1_2e7T_medium1;
      fHandles[ "L2_e20_etcutTrk_xe25" ] = &L2_e20_etcutTrk_xe25;
      fHandles[ "L2_e20_etcutTrk_xs45" ] = &L2_e20_etcutTrk_xs45;
      fHandles[ "L2_e20vhT_medium1_g6T_etcut_Upsi" ] = &L2_e20vhT_medium1_g6T_etcut_Upsi;
      fHandles[ "L2_e20vhT_tight1_g6T_etcut_Upsi" ] = &L2_e20vhT_tight1_g6T_etcut_Upsi;
      fHandles[ "L2_e22vh_loose" ] = &L2_e22vh_loose;
      fHandles[ "L2_e22vh_loose0" ] = &L2_e22vh_loose0;
      fHandles[ "L2_e22vh_loose1" ] = &L2_e22vh_loose1;
      fHandles[ "L2_e22vh_medium1" ] = &L2_e22vh_medium1;
      fHandles[ "L2_e22vh_medium1_IDTrkNoCut" ] = &L2_e22vh_medium1_IDTrkNoCut;
      fHandles[ "L2_e22vh_medium1_IdScan" ] = &L2_e22vh_medium1_IdScan;
      fHandles[ "L2_e22vh_medium1_SiTrk" ] = &L2_e22vh_medium1_SiTrk;
      fHandles[ "L2_e22vh_medium1_TRT" ] = &L2_e22vh_medium1_TRT;
      fHandles[ "L2_e22vhi_medium1" ] = &L2_e22vhi_medium1;
      fHandles[ "L2_e24vh_loose" ] = &L2_e24vh_loose;
      fHandles[ "L2_e24vh_loose0" ] = &L2_e24vh_loose0;
      fHandles[ "L2_e24vh_loose1" ] = &L2_e24vh_loose1;
      fHandles[ "L2_e24vh_medium1" ] = &L2_e24vh_medium1;
      fHandles[ "L2_e24vh_medium1_EFxe30" ] = &L2_e24vh_medium1_EFxe30;
      fHandles[ "L2_e24vh_medium1_EFxe35" ] = &L2_e24vh_medium1_EFxe35;
      fHandles[ "L2_e24vh_medium1_EFxe40" ] = &L2_e24vh_medium1_EFxe40;
      fHandles[ "L2_e24vh_medium1_IDTrkNoCut" ] = &L2_e24vh_medium1_IDTrkNoCut;
      fHandles[ "L2_e24vh_medium1_IdScan" ] = &L2_e24vh_medium1_IdScan;
      fHandles[ "L2_e24vh_medium1_L2StarB" ] = &L2_e24vh_medium1_L2StarB;
      fHandles[ "L2_e24vh_medium1_L2StarC" ] = &L2_e24vh_medium1_L2StarC;
      fHandles[ "L2_e24vh_medium1_SiTrk" ] = &L2_e24vh_medium1_SiTrk;
      fHandles[ "L2_e24vh_medium1_TRT" ] = &L2_e24vh_medium1_TRT;
      fHandles[ "L2_e24vh_medium1_e7_medium1" ] = &L2_e24vh_medium1_e7_medium1;
      fHandles[ "L2_e24vh_tight1_e15_NoCut_Zee" ] = &L2_e24vh_tight1_e15_NoCut_Zee;
      fHandles[ "L2_e24vhi_loose1_mu8" ] = &L2_e24vhi_loose1_mu8;
      fHandles[ "L2_e24vhi_medium1" ] = &L2_e24vhi_medium1;
      fHandles[ "L2_e45_etcut" ] = &L2_e45_etcut;
      fHandles[ "L2_e45_loose1" ] = &L2_e45_loose1;
      fHandles[ "L2_e45_medium1" ] = &L2_e45_medium1;
      fHandles[ "L2_e5_tight1" ] = &L2_e5_tight1;
      fHandles[ "L2_e5_tight1_e14_etcut_Jpsi" ] = &L2_e5_tight1_e14_etcut_Jpsi;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi" ] = &L2_e5_tight1_e4_etcut_Jpsi;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_IdScan" ] = &L2_e5_tight1_e4_etcut_Jpsi_IdScan;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_L2StarB" ] = &L2_e5_tight1_e4_etcut_Jpsi_L2StarB;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_L2StarC" ] = &L2_e5_tight1_e4_etcut_Jpsi_L2StarC;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_SiTrk" ] = &L2_e5_tight1_e4_etcut_Jpsi_SiTrk;
      fHandles[ "L2_e5_tight1_e4_etcut_Jpsi_TRT" ] = &L2_e5_tight1_e4_etcut_Jpsi_TRT;
      fHandles[ "L2_e5_tight1_e5_NoCut" ] = &L2_e5_tight1_e5_NoCut;
      fHandles[ "L2_e5_tight1_e9_etcut_Jpsi" ] = &L2_e5_tight1_e9_etcut_Jpsi;
      fHandles[ "L2_e60_etcut" ] = &L2_e60_etcut;
      fHandles[ "L2_e60_loose1" ] = &L2_e60_loose1;
      fHandles[ "L2_e60_medium1" ] = &L2_e60_medium1;
      fHandles[ "L2_e7T_loose1" ] = &L2_e7T_loose1;
      fHandles[ "L2_e7T_loose1_2mu6" ] = &L2_e7T_loose1_2mu6;
      fHandles[ "L2_e7T_medium1" ] = &L2_e7T_medium1;
      fHandles[ "L2_e7T_medium1_2mu6" ] = &L2_e7T_medium1_2mu6;
      fHandles[ "L2_e9_tight1_e4_etcut_Jpsi" ] = &L2_e9_tight1_e4_etcut_Jpsi;
      fHandles[ "L2_eb_physics" ] = &L2_eb_physics;
      fHandles[ "L2_eb_physics_empty" ] = &L2_eb_physics_empty;
      fHandles[ "L2_eb_physics_firstempty" ] = &L2_eb_physics_firstempty;
      fHandles[ "L2_eb_physics_noL1PS" ] = &L2_eb_physics_noL1PS;
      fHandles[ "L2_eb_physics_unpaired_iso" ] = &L2_eb_physics_unpaired_iso;
      fHandles[ "L2_eb_physics_unpaired_noniso" ] = &L2_eb_physics_unpaired_noniso;
      fHandles[ "L2_eb_random" ] = &L2_eb_random;
      fHandles[ "L2_eb_random_empty" ] = &L2_eb_random_empty;
      fHandles[ "L2_eb_random_firstempty" ] = &L2_eb_random_firstempty;
      fHandles[ "L2_eb_random_unpaired_iso" ] = &L2_eb_random_unpaired_iso;
      fHandles[ "L2_em3_empty_larcalib" ] = &L2_em3_empty_larcalib;
      fHandles[ "L2_em6_empty_larcalib" ] = &L2_em6_empty_larcalib;
      fHandles[ "L2_g100_loose" ] = &L2_g100_loose;
      fHandles[ "L2_g10_NoCut_cosmic" ] = &L2_g10_NoCut_cosmic;
      fHandles[ "L2_g10_loose" ] = &L2_g10_loose;
      fHandles[ "L2_g10_medium" ] = &L2_g10_medium;
      fHandles[ "L2_g120_loose" ] = &L2_g120_loose;
      fHandles[ "L2_g12Tvh_loose" ] = &L2_g12Tvh_loose;
      fHandles[ "L2_g12Tvh_medium" ] = &L2_g12Tvh_medium;
      fHandles[ "L2_g15_loose" ] = &L2_g15_loose;
      fHandles[ "L2_g15vh_loose" ] = &L2_g15vh_loose;
      fHandles[ "L2_g15vh_medium" ] = &L2_g15vh_medium;
      fHandles[ "L2_g200_etcut" ] = &L2_g200_etcut;
      fHandles[ "L2_g20Tvh_medium" ] = &L2_g20Tvh_medium;
      fHandles[ "L2_g20_etcut" ] = &L2_g20_etcut;
      fHandles[ "L2_g20_loose" ] = &L2_g20_loose;
      fHandles[ "L2_g20_medium" ] = &L2_g20_medium;
      fHandles[ "L2_g20vh_medium" ] = &L2_g20vh_medium;
      fHandles[ "L2_g30_loose_g20_loose" ] = &L2_g30_loose_g20_loose;
      fHandles[ "L2_g30_medium_g20_medium" ] = &L2_g30_medium_g20_medium;
      fHandles[ "L2_g35_loose_g25_loose" ] = &L2_g35_loose_g25_loose;
      fHandles[ "L2_g35_loose_g30_loose" ] = &L2_g35_loose_g30_loose;
      fHandles[ "L2_g40_loose" ] = &L2_g40_loose;
      fHandles[ "L2_g40_loose_EFxe50" ] = &L2_g40_loose_EFxe50;
      fHandles[ "L2_g40_loose_L2xe35" ] = &L2_g40_loose_L2xe35;
      fHandles[ "L2_g40_loose_L2xe45" ] = &L2_g40_loose_L2xe45;
      fHandles[ "L2_g40_loose_g25_loose" ] = &L2_g40_loose_g25_loose;
      fHandles[ "L2_g40_loose_g30_loose" ] = &L2_g40_loose_g30_loose;
      fHandles[ "L2_g5_NoCut_cosmic" ] = &L2_g5_NoCut_cosmic;
      fHandles[ "L2_g60_loose" ] = &L2_g60_loose;
      fHandles[ "L2_g80_loose" ] = &L2_g80_loose;
      fHandles[ "L2_j105_c4cchad_xe35" ] = &L2_j105_c4cchad_xe35;
      fHandles[ "L2_j105_c4cchad_xe40" ] = &L2_j105_c4cchad_xe40;
      fHandles[ "L2_j105_c4cchad_xe45" ] = &L2_j105_c4cchad_xe45;
      fHandles[ "L2_j105_j40_c4cchad_xe40" ] = &L2_j105_j40_c4cchad_xe40;
      fHandles[ "L2_j105_j50_c4cchad_xe40" ] = &L2_j105_j50_c4cchad_xe40;
      fHandles[ "L2_j30_a4tcem_eta13_xe30_empty" ] = &L2_j30_a4tcem_eta13_xe30_empty;
      fHandles[ "L2_j30_a4tcem_eta13_xe30_firstempty" ] = &L2_j30_a4tcem_eta13_xe30_firstempty;
      fHandles[ "L2_j50_a4tcem_eta13_xe50_empty" ] = &L2_j50_a4tcem_eta13_xe50_empty;
      fHandles[ "L2_j50_a4tcem_eta13_xe50_firstempty" ] = &L2_j50_a4tcem_eta13_xe50_firstempty;
      fHandles[ "L2_j50_a4tcem_eta25_xe50_empty" ] = &L2_j50_a4tcem_eta25_xe50_empty;
      fHandles[ "L2_j50_a4tcem_eta25_xe50_firstempty" ] = &L2_j50_a4tcem_eta25_xe50_firstempty;
      fHandles[ "L2_j75_c4cchad_xe40" ] = &L2_j75_c4cchad_xe40;
      fHandles[ "L2_j75_c4cchad_xe45" ] = &L2_j75_c4cchad_xe45;
      fHandles[ "L2_j75_c4cchad_xe55" ] = &L2_j75_c4cchad_xe55;
      fHandles[ "L2_mu10" ] = &L2_mu10;
      fHandles[ "L2_mu10_Jpsimumu" ] = &L2_mu10_Jpsimumu;
      fHandles[ "L2_mu10_MSonly" ] = &L2_mu10_MSonly;
      fHandles[ "L2_mu10_Upsimumu_tight_FS" ] = &L2_mu10_Upsimumu_tight_FS;
      fHandles[ "L2_mu10i_g10_loose" ] = &L2_mu10i_g10_loose;
      fHandles[ "L2_mu10i_g10_loose_TauMass" ] = &L2_mu10i_g10_loose_TauMass;
      fHandles[ "L2_mu10i_g10_medium" ] = &L2_mu10i_g10_medium;
      fHandles[ "L2_mu10i_g10_medium_TauMass" ] = &L2_mu10i_g10_medium_TauMass;
      fHandles[ "L2_mu10i_loose_g12Tvh_loose" ] = &L2_mu10i_loose_g12Tvh_loose;
      fHandles[ "L2_mu10i_loose_g12Tvh_loose_TauMass" ] = &L2_mu10i_loose_g12Tvh_loose_TauMass;
      fHandles[ "L2_mu10i_loose_g12Tvh_medium" ] = &L2_mu10i_loose_g12Tvh_medium;
      fHandles[ "L2_mu10i_loose_g12Tvh_medium_TauMass" ] = &L2_mu10i_loose_g12Tvh_medium_TauMass;
      fHandles[ "L2_mu11_empty_NoAlg" ] = &L2_mu11_empty_NoAlg;
      fHandles[ "L2_mu13" ] = &L2_mu13;
      fHandles[ "L2_mu15" ] = &L2_mu15;
      fHandles[ "L2_mu15_l2cal" ] = &L2_mu15_l2cal;
      fHandles[ "L2_mu18" ] = &L2_mu18;
      fHandles[ "L2_mu18_2g10_loose" ] = &L2_mu18_2g10_loose;
      fHandles[ "L2_mu18_2g10_medium" ] = &L2_mu18_2g10_medium;
      fHandles[ "L2_mu18_2g15_loose" ] = &L2_mu18_2g15_loose;
      fHandles[ "L2_mu18_IDTrkNoCut_tight" ] = &L2_mu18_IDTrkNoCut_tight;
      fHandles[ "L2_mu18_g20vh_loose" ] = &L2_mu18_g20vh_loose;
      fHandles[ "L2_mu18_medium" ] = &L2_mu18_medium;
      fHandles[ "L2_mu18_tight" ] = &L2_mu18_tight;
      fHandles[ "L2_mu18_tight_e7_medium1" ] = &L2_mu18_tight_e7_medium1;
      fHandles[ "L2_mu18i4_tight" ] = &L2_mu18i4_tight;
      fHandles[ "L2_mu18it_tight" ] = &L2_mu18it_tight;
      fHandles[ "L2_mu20i_tight_g5_loose" ] = &L2_mu20i_tight_g5_loose;
      fHandles[ "L2_mu20i_tight_g5_loose_TauMass" ] = &L2_mu20i_tight_g5_loose_TauMass;
      fHandles[ "L2_mu20i_tight_g5_medium" ] = &L2_mu20i_tight_g5_medium;
      fHandles[ "L2_mu20i_tight_g5_medium_TauMass" ] = &L2_mu20i_tight_g5_medium_TauMass;
      fHandles[ "L2_mu20it_tight" ] = &L2_mu20it_tight;
      fHandles[ "L2_mu22_IDTrkNoCut_tight" ] = &L2_mu22_IDTrkNoCut_tight;
      fHandles[ "L2_mu24" ] = &L2_mu24;
      fHandles[ "L2_mu24_g20vh_loose" ] = &L2_mu24_g20vh_loose;
      fHandles[ "L2_mu24_g20vh_medium" ] = &L2_mu24_g20vh_medium;
      fHandles[ "L2_mu24_j60_c4cchad_EFxe40" ] = &L2_mu24_j60_c4cchad_EFxe40;
      fHandles[ "L2_mu24_j60_c4cchad_EFxe50" ] = &L2_mu24_j60_c4cchad_EFxe50;
      fHandles[ "L2_mu24_j60_c4cchad_EFxe60" ] = &L2_mu24_j60_c4cchad_EFxe60;
      fHandles[ "L2_mu24_j60_c4cchad_xe35" ] = &L2_mu24_j60_c4cchad_xe35;
      fHandles[ "L2_mu24_j65_c4cchad" ] = &L2_mu24_j65_c4cchad;
      fHandles[ "L2_mu24_medium" ] = &L2_mu24_medium;
      fHandles[ "L2_mu24_muCombTag_NoEF_tight" ] = &L2_mu24_muCombTag_NoEF_tight;
      fHandles[ "L2_mu24_tight" ] = &L2_mu24_tight;
      fHandles[ "L2_mu24_tight_2j35_a4tchad" ] = &L2_mu24_tight_2j35_a4tchad;
      fHandles[ "L2_mu24_tight_3j35_a4tchad" ] = &L2_mu24_tight_3j35_a4tchad;
      fHandles[ "L2_mu24_tight_4j35_a4tchad" ] = &L2_mu24_tight_4j35_a4tchad;
      fHandles[ "L2_mu24_tight_EFxe40" ] = &L2_mu24_tight_EFxe40;
      fHandles[ "L2_mu24_tight_L2StarB" ] = &L2_mu24_tight_L2StarB;
      fHandles[ "L2_mu24_tight_L2StarC" ] = &L2_mu24_tight_L2StarC;
      fHandles[ "L2_mu24_tight_l2muonSA" ] = &L2_mu24_tight_l2muonSA;
      fHandles[ "L2_mu36_tight" ] = &L2_mu36_tight;
      fHandles[ "L2_mu40_MSonly_barrel_tight" ] = &L2_mu40_MSonly_barrel_tight;
      fHandles[ "L2_mu40_muCombTag_NoEF" ] = &L2_mu40_muCombTag_NoEF;
      fHandles[ "L2_mu40_slow_outOfTime_tight" ] = &L2_mu40_slow_outOfTime_tight;
      fHandles[ "L2_mu40_slow_tight" ] = &L2_mu40_slow_tight;
      fHandles[ "L2_mu40_tight" ] = &L2_mu40_tight;
      fHandles[ "L2_mu4T" ] = &L2_mu4T;
      fHandles[ "L2_mu4T_Trk_Jpsi" ] = &L2_mu4T_Trk_Jpsi;
      fHandles[ "L2_mu4T_cosmic" ] = &L2_mu4T_cosmic;
      fHandles[ "L2_mu4T_j105_c4cchad" ] = &L2_mu4T_j105_c4cchad;
      fHandles[ "L2_mu4T_j10_a4TTem" ] = &L2_mu4T_j10_a4TTem;
      fHandles[ "L2_mu4T_j140_c4cchad" ] = &L2_mu4T_j140_c4cchad;
      fHandles[ "L2_mu4T_j15_a4TTem" ] = &L2_mu4T_j15_a4TTem;
      fHandles[ "L2_mu4T_j165_c4cchad" ] = &L2_mu4T_j165_c4cchad;
      fHandles[ "L2_mu4T_j30_a4TTem" ] = &L2_mu4T_j30_a4TTem;
      fHandles[ "L2_mu4T_j40_c4cchad" ] = &L2_mu4T_j40_c4cchad;
      fHandles[ "L2_mu4T_j50_a4TTem" ] = &L2_mu4T_j50_a4TTem;
      fHandles[ "L2_mu4T_j50_c4cchad" ] = &L2_mu4T_j50_c4cchad;
      fHandles[ "L2_mu4T_j60_c4cchad" ] = &L2_mu4T_j60_c4cchad;
      fHandles[ "L2_mu4T_j60_c4cchad_xe40" ] = &L2_mu4T_j60_c4cchad_xe40;
      fHandles[ "L2_mu4T_j75_a4TTem" ] = &L2_mu4T_j75_a4TTem;
      fHandles[ "L2_mu4T_j75_c4cchad" ] = &L2_mu4T_j75_c4cchad;
      fHandles[ "L2_mu4Ti_g20Tvh_loose" ] = &L2_mu4Ti_g20Tvh_loose;
      fHandles[ "L2_mu4Ti_g20Tvh_loose_TauMass" ] = &L2_mu4Ti_g20Tvh_loose_TauMass;
      fHandles[ "L2_mu4Ti_g20Tvh_medium" ] = &L2_mu4Ti_g20Tvh_medium;
      fHandles[ "L2_mu4Ti_g20Tvh_medium_TauMass" ] = &L2_mu4Ti_g20Tvh_medium_TauMass;
      fHandles[ "L2_mu4Tmu6_Bmumu" ] = &L2_mu4Tmu6_Bmumu;
      fHandles[ "L2_mu4Tmu6_Bmumu_Barrel" ] = &L2_mu4Tmu6_Bmumu_Barrel;
      fHandles[ "L2_mu4Tmu6_Bmumux" ] = &L2_mu4Tmu6_Bmumux;
      fHandles[ "L2_mu4Tmu6_Bmumux_Barrel" ] = &L2_mu4Tmu6_Bmumux_Barrel;
      fHandles[ "L2_mu4Tmu6_DiMu" ] = &L2_mu4Tmu6_DiMu;
      fHandles[ "L2_mu4Tmu6_DiMu_Barrel" ] = &L2_mu4Tmu6_DiMu_Barrel;
      fHandles[ "L2_mu4Tmu6_DiMu_noVtx_noOS" ] = &L2_mu4Tmu6_DiMu_noVtx_noOS;
      fHandles[ "L2_mu4Tmu6_Jpsimumu" ] = &L2_mu4Tmu6_Jpsimumu;
      fHandles[ "L2_mu4Tmu6_Jpsimumu_Barrel" ] = &L2_mu4Tmu6_Jpsimumu_Barrel;
      fHandles[ "L2_mu4Tmu6_Jpsimumu_IDTrkNoCut" ] = &L2_mu4Tmu6_Jpsimumu_IDTrkNoCut;
      fHandles[ "L2_mu4Tmu6_Upsimumu" ] = &L2_mu4Tmu6_Upsimumu;
      fHandles[ "L2_mu4Tmu6_Upsimumu_Barrel" ] = &L2_mu4Tmu6_Upsimumu_Barrel;
      fHandles[ "L2_mu4_L1MU11_MSonly_cosmic" ] = &L2_mu4_L1MU11_MSonly_cosmic;
      fHandles[ "L2_mu4_L1MU11_cosmic" ] = &L2_mu4_L1MU11_cosmic;
      fHandles[ "L2_mu4_empty_NoAlg" ] = &L2_mu4_empty_NoAlg;
      fHandles[ "L2_mu4_firstempty_NoAlg" ] = &L2_mu4_firstempty_NoAlg;
      fHandles[ "L2_mu4_l2cal_empty" ] = &L2_mu4_l2cal_empty;
      fHandles[ "L2_mu4_unpaired_iso_NoAlg" ] = &L2_mu4_unpaired_iso_NoAlg;
      fHandles[ "L2_mu50_MSonly_barrel_tight" ] = &L2_mu50_MSonly_barrel_tight;
      fHandles[ "L2_mu6" ] = &L2_mu6;
      fHandles[ "L2_mu60_slow_outOfTime_tight1" ] = &L2_mu60_slow_outOfTime_tight1;
      fHandles[ "L2_mu60_slow_tight1" ] = &L2_mu60_slow_tight1;
      fHandles[ "L2_mu6_Jpsimumu_tight" ] = &L2_mu6_Jpsimumu_tight;
      fHandles[ "L2_mu6_MSonly" ] = &L2_mu6_MSonly;
      fHandles[ "L2_mu6_Trk_Jpsi_loose" ] = &L2_mu6_Trk_Jpsi_loose;
      fHandles[ "L2_mu8" ] = &L2_mu8;
      fHandles[ "L2_mu8_4j15_a4TTem" ] = &L2_mu8_4j15_a4TTem;
      fHandles[ "L2_tau125_IDTrkNoCut" ] = &L2_tau125_IDTrkNoCut;
      fHandles[ "L2_tau125_medium1" ] = &L2_tau125_medium1;
      fHandles[ "L2_tau125_medium1_L2StarA" ] = &L2_tau125_medium1_L2StarA;
      fHandles[ "L2_tau125_medium1_L2StarB" ] = &L2_tau125_medium1_L2StarB;
      fHandles[ "L2_tau125_medium1_L2StarC" ] = &L2_tau125_medium1_L2StarC;
      fHandles[ "L2_tau125_medium1_llh" ] = &L2_tau125_medium1_llh;
      fHandles[ "L2_tau20T_medium" ] = &L2_tau20T_medium;
      fHandles[ "L2_tau20T_medium1" ] = &L2_tau20T_medium1;
      fHandles[ "L2_tau20T_medium1_e15vh_medium1" ] = &L2_tau20T_medium1_e15vh_medium1;
      fHandles[ "L2_tau20T_medium1_mu15i" ] = &L2_tau20T_medium1_mu15i;
      fHandles[ "L2_tau20T_medium_mu15" ] = &L2_tau20T_medium_mu15;
      fHandles[ "L2_tau20Ti_medium" ] = &L2_tau20Ti_medium;
      fHandles[ "L2_tau20Ti_medium1" ] = &L2_tau20Ti_medium1;
      fHandles[ "L2_tau20Ti_medium1_e18vh_medium1" ] = &L2_tau20Ti_medium1_e18vh_medium1;
      fHandles[ "L2_tau20Ti_medium1_llh_e18vh_medium1" ] = &L2_tau20Ti_medium1_llh_e18vh_medium1;
      fHandles[ "L2_tau20Ti_medium_e18vh_medium1" ] = &L2_tau20Ti_medium_e18vh_medium1;
      fHandles[ "L2_tau20Ti_tight1" ] = &L2_tau20Ti_tight1;
      fHandles[ "L2_tau20Ti_tight1_llh" ] = &L2_tau20Ti_tight1_llh;
      fHandles[ "L2_tau20_medium" ] = &L2_tau20_medium;
      fHandles[ "L2_tau20_medium1" ] = &L2_tau20_medium1;
      fHandles[ "L2_tau20_medium1_llh" ] = &L2_tau20_medium1_llh;
      fHandles[ "L2_tau20_medium1_llh_mu15" ] = &L2_tau20_medium1_llh_mu15;
      fHandles[ "L2_tau20_medium1_mu15" ] = &L2_tau20_medium1_mu15;
      fHandles[ "L2_tau20_medium1_mu15i" ] = &L2_tau20_medium1_mu15i;
      fHandles[ "L2_tau20_medium1_mu18" ] = &L2_tau20_medium1_mu18;
      fHandles[ "L2_tau20_medium_llh" ] = &L2_tau20_medium_llh;
      fHandles[ "L2_tau20_medium_mu15" ] = &L2_tau20_medium_mu15;
      fHandles[ "L2_tau29T_medium" ] = &L2_tau29T_medium;
      fHandles[ "L2_tau29T_medium1" ] = &L2_tau29T_medium1;
      fHandles[ "L2_tau29T_medium1_tau20T_medium1" ] = &L2_tau29T_medium1_tau20T_medium1;
      fHandles[ "L2_tau29T_medium1_xe35_tight" ] = &L2_tau29T_medium1_xe35_tight;
      fHandles[ "L2_tau29T_medium1_xe40_tight" ] = &L2_tau29T_medium1_xe40_tight;
      fHandles[ "L2_tau29T_medium_xe35_tight" ] = &L2_tau29T_medium_xe35_tight;
      fHandles[ "L2_tau29T_medium_xe40_tight" ] = &L2_tau29T_medium_xe40_tight;
      fHandles[ "L2_tau29T_tight1" ] = &L2_tau29T_tight1;
      fHandles[ "L2_tau29T_tight1_llh" ] = &L2_tau29T_tight1_llh;
      fHandles[ "L2_tau29Ti_medium1" ] = &L2_tau29Ti_medium1;
      fHandles[ "L2_tau29Ti_medium1_llh_tau20Ti_medium1_llh" ] = &L2_tau29Ti_medium1_llh_tau20Ti_medium1_llh;
      fHandles[ "L2_tau29Ti_medium1_llh_xe35_tight" ] = &L2_tau29Ti_medium1_llh_xe35_tight;
      fHandles[ "L2_tau29Ti_medium1_llh_xe40_tight" ] = &L2_tau29Ti_medium1_llh_xe40_tight;
      fHandles[ "L2_tau29Ti_medium1_tau20Ti_medium1" ] = &L2_tau29Ti_medium1_tau20Ti_medium1;
      fHandles[ "L2_tau29Ti_medium1_xe35_tight" ] = &L2_tau29Ti_medium1_xe35_tight;
      fHandles[ "L2_tau29Ti_medium1_xe40" ] = &L2_tau29Ti_medium1_xe40;
      fHandles[ "L2_tau29Ti_medium1_xe40_tight" ] = &L2_tau29Ti_medium1_xe40_tight;
      fHandles[ "L2_tau29Ti_medium_xe35_tight" ] = &L2_tau29Ti_medium_xe35_tight;
      fHandles[ "L2_tau29Ti_medium_xe40_tight" ] = &L2_tau29Ti_medium_xe40_tight;
      fHandles[ "L2_tau29Ti_tight1" ] = &L2_tau29Ti_tight1;
      fHandles[ "L2_tau29Ti_tight1_llh" ] = &L2_tau29Ti_tight1_llh;
      fHandles[ "L2_tau29Ti_tight1_llh_tau20Ti_tight1_llh" ] = &L2_tau29Ti_tight1_llh_tau20Ti_tight1_llh;
      fHandles[ "L2_tau29Ti_tight1_tau20Ti_tight1" ] = &L2_tau29Ti_tight1_tau20Ti_tight1;
      fHandles[ "L2_tau29_IDTrkNoCut" ] = &L2_tau29_IDTrkNoCut;
      fHandles[ "L2_tau29_medium" ] = &L2_tau29_medium;
      fHandles[ "L2_tau29_medium1" ] = &L2_tau29_medium1;
      fHandles[ "L2_tau29_medium1_llh" ] = &L2_tau29_medium1_llh;
      fHandles[ "L2_tau29_medium_2stTest" ] = &L2_tau29_medium_2stTest;
      fHandles[ "L2_tau29_medium_L2StarA" ] = &L2_tau29_medium_L2StarA;
      fHandles[ "L2_tau29_medium_L2StarB" ] = &L2_tau29_medium_L2StarB;
      fHandles[ "L2_tau29_medium_L2StarC" ] = &L2_tau29_medium_L2StarC;
      fHandles[ "L2_tau29_medium_llh" ] = &L2_tau29_medium_llh;
      fHandles[ "L2_tau29i_medium" ] = &L2_tau29i_medium;
      fHandles[ "L2_tau29i_medium1" ] = &L2_tau29i_medium1;
      fHandles[ "L2_tau38T_medium" ] = &L2_tau38T_medium;
      fHandles[ "L2_tau38T_medium1" ] = &L2_tau38T_medium1;
      fHandles[ "L2_tau38T_medium1_e18vh_medium1" ] = &L2_tau38T_medium1_e18vh_medium1;
      fHandles[ "L2_tau38T_medium1_llh_e18vh_medium1" ] = &L2_tau38T_medium1_llh_e18vh_medium1;
      fHandles[ "L2_tau38T_medium1_xe35_tight" ] = &L2_tau38T_medium1_xe35_tight;
      fHandles[ "L2_tau38T_medium1_xe40_tight" ] = &L2_tau38T_medium1_xe40_tight;
      fHandles[ "L2_tau38T_medium_e18vh_medium1" ] = &L2_tau38T_medium_e18vh_medium1;
      fHandles[ "L2_tau50_medium" ] = &L2_tau50_medium;
      fHandles[ "L2_tau50_medium1_e18vh_medium1" ] = &L2_tau50_medium1_e18vh_medium1;
      fHandles[ "L2_tau50_medium_e15vh_medium1" ] = &L2_tau50_medium_e15vh_medium1;
      fHandles[ "L2_tau8_empty_larcalib" ] = &L2_tau8_empty_larcalib;
      fHandles[ "L2_tauNoCut" ] = &L2_tauNoCut;
      fHandles[ "L2_tauNoCut_L1TAU40" ] = &L2_tauNoCut_L1TAU40;
      fHandles[ "L2_tauNoCut_cosmic" ] = &L2_tauNoCut_cosmic;
      fHandles[ "L2_xe25" ] = &L2_xe25;
      fHandles[ "L2_xe35" ] = &L2_xe35;
      fHandles[ "L2_xe40" ] = &L2_xe40;
      fHandles[ "L2_xe45" ] = &L2_xe45;
      fHandles[ "L2_xe45T" ] = &L2_xe45T;
      fHandles[ "L2_xe55" ] = &L2_xe55;
      fHandles[ "L2_xe55T" ] = &L2_xe55T;
      fHandles[ "L2_xe55_LArNoiseBurst" ] = &L2_xe55_LArNoiseBurst;
      fHandles[ "L2_xe65" ] = &L2_xe65;
      fHandles[ "L2_xe65_tight" ] = &L2_xe65_tight;
      fHandles[ "L2_xe75" ] = &L2_xe75;
      fHandles[ "L2_xe90" ] = &L2_xe90;
      fHandles[ "L2_xe90_tight" ] = &L2_xe90_tight;

      // Configure all variables in a loop:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->SetParent( this );
         itr->second->SetName( fPrefix + itr->first );
         itr->second->SetMaster( 0 );
      }
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TriggerD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TriggerD3PDObject::SetPrefix( const char* prefix ) {

      fPrefix = prefix;

      // Set all the variable names:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->SetName( ::TString( prefix ) + itr->first );
      }

      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void TriggerD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      // Call ReadFrom(...) on all the variables:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->ReadFrom( tree );
      }

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void TriggerD3PDObject::WriteTo( TTree* tree ) {

      // Call WriteTo(...) on all the variables:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->WriteTo( tree );
      }

      return;
   }

   /**
    * This is a convenience function for turning the branches active or
    * inactive conveniently. If the parameter is set to <code>kTRUE</code>
    * then the branches available from the input which match the given
    * pattern are turned active.
    * When it's set to <code>kFALSE</code> then all the variables matching
    * the pattern are turned inactive.
    *
    * @param active Flag behaving as explained above
    * @param pattern Regular expression specifying which branches to modify
    */
   void TriggerD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

      ::TPRegexp re( pattern );

      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         if( ! re.Match( itr->first ) ) continue;
         if( active ) {
            if( itr->second->IsAvailable() ) itr->second->SetActive( active );
         } else {
            itr->second->SetActive( active );
         }
      }

      return;
   }

   /**
    * This function can be used to read in all the branches from the input
    * TTree which are set active for writing out. This can simplify writing
    * event selector codes immensely. Remember to set the desired variable
    * active before calling this function.
    */
   void TriggerD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      // Read in the current entry for each active variable:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         if( ! itr->second->IsActive() ) continue;
         itr->second->ReadCurrentEntry();
      }

      return;
   }

   D3PDReadStats TriggerD3PDObject::GetStatistics() const {

      // The result object:
      D3PDReadStats result;

      // Add the statistics from each variable to the result:
      std::map< ::TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< ::TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         result.AddVariable( itr->second->GetStatistics() );
      }

      return result;
   }

   /**
    * This function can be used to copy the contents of the entire object
    * for a given event. This can be useful for instance when the user
    * wants to copy all information to an output file, and modify it a bit,
    * and only then write it out.
    *
    * @param parent The object to copy the information from
    * @returns This same object, for convenience reasons
    */
   TriggerD3PDObject& TriggerD3PDObject::Set( const TriggerD3PDObject& parent ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Set", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( parent.L1_TAV.IsAvailable() ) {
         *( L1_TAV() ) = *( parent.L1_TAV() );
      } else {
         L1_TAV()->clear();
      }
      if( parent.EF_2e12Tvh_loose1.IsAvailable() ) {
         EF_2e12Tvh_loose1() = parent.EF_2e12Tvh_loose1();
      } else {
         EF_2e12Tvh_loose1() = 0;
      }
      if( parent.EF_2e5_tight1_Jpsi.IsAvailable() ) {
         EF_2e5_tight1_Jpsi() = parent.EF_2e5_tight1_Jpsi();
      } else {
         EF_2e5_tight1_Jpsi() = 0;
      }
      if( parent.EF_2e7T_loose1_mu6.IsAvailable() ) {
         EF_2e7T_loose1_mu6() = parent.EF_2e7T_loose1_mu6();
      } else {
         EF_2e7T_loose1_mu6() = 0;
      }
      if( parent.EF_2e7T_medium1_mu6.IsAvailable() ) {
         EF_2e7T_medium1_mu6() = parent.EF_2e7T_medium1_mu6();
      } else {
         EF_2e7T_medium1_mu6() = 0;
      }
      if( parent.EF_2g15vh_loose_g10_loose.IsAvailable() ) {
         EF_2g15vh_loose_g10_loose() = parent.EF_2g15vh_loose_g10_loose();
      } else {
         EF_2g15vh_loose_g10_loose() = 0;
      }
      if( parent.EF_2g15vh_medium.IsAvailable() ) {
         EF_2g15vh_medium() = parent.EF_2g15vh_medium();
      } else {
         EF_2g15vh_medium() = 0;
      }
      if( parent.EF_2g15vh_medium_g10_medium.IsAvailable() ) {
         EF_2g15vh_medium_g10_medium() = parent.EF_2g15vh_medium_g10_medium();
      } else {
         EF_2g15vh_medium_g10_medium() = 0;
      }
      if( parent.EF_2g20_loose.IsAvailable() ) {
         EF_2g20_loose() = parent.EF_2g20_loose();
      } else {
         EF_2g20_loose() = 0;
      }
      if( parent.EF_2g20vh_medium.IsAvailable() ) {
         EF_2g20vh_medium() = parent.EF_2g20vh_medium();
      } else {
         EF_2g20vh_medium() = 0;
      }
      if( parent.EF_2g30_loose.IsAvailable() ) {
         EF_2g30_loose() = parent.EF_2g30_loose();
      } else {
         EF_2g30_loose() = 0;
      }
      if( parent.EF_2g40_loose.IsAvailable() ) {
         EF_2g40_loose() = parent.EF_2g40_loose();
      } else {
         EF_2g40_loose() = 0;
      }
      if( parent.EF_2mu10.IsAvailable() ) {
         EF_2mu10() = parent.EF_2mu10();
      } else {
         EF_2mu10() = 0;
      }
      if( parent.EF_2mu10_MSonly_g10_loose.IsAvailable() ) {
         EF_2mu10_MSonly_g10_loose() = parent.EF_2mu10_MSonly_g10_loose();
      } else {
         EF_2mu10_MSonly_g10_loose() = 0;
      }
      if( parent.EF_2mu10_MSonly_g10_loose_EMPTY.IsAvailable() ) {
         EF_2mu10_MSonly_g10_loose_EMPTY() = parent.EF_2mu10_MSonly_g10_loose_EMPTY();
      } else {
         EF_2mu10_MSonly_g10_loose_EMPTY() = 0;
      }
      if( parent.EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO.IsAvailable() ) {
         EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO() = parent.EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO();
      } else {
         EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO() = 0;
      }
      if( parent.EF_2mu13.IsAvailable() ) {
         EF_2mu13() = parent.EF_2mu13();
      } else {
         EF_2mu13() = 0;
      }
      if( parent.EF_2mu13_Zmumu_IDTrkNoCut.IsAvailable() ) {
         EF_2mu13_Zmumu_IDTrkNoCut() = parent.EF_2mu13_Zmumu_IDTrkNoCut();
      } else {
         EF_2mu13_Zmumu_IDTrkNoCut() = 0;
      }
      if( parent.EF_2mu13_l2muonSA.IsAvailable() ) {
         EF_2mu13_l2muonSA() = parent.EF_2mu13_l2muonSA();
      } else {
         EF_2mu13_l2muonSA() = 0;
      }
      if( parent.EF_2mu15.IsAvailable() ) {
         EF_2mu15() = parent.EF_2mu15();
      } else {
         EF_2mu15() = 0;
      }
      if( parent.EF_2mu4T.IsAvailable() ) {
         EF_2mu4T() = parent.EF_2mu4T();
      } else {
         EF_2mu4T() = 0;
      }
      if( parent.EF_2mu4T_2e5_tight1.IsAvailable() ) {
         EF_2mu4T_2e5_tight1() = parent.EF_2mu4T_2e5_tight1();
      } else {
         EF_2mu4T_2e5_tight1() = 0;
      }
      if( parent.EF_2mu4T_Bmumu.IsAvailable() ) {
         EF_2mu4T_Bmumu() = parent.EF_2mu4T_Bmumu();
      } else {
         EF_2mu4T_Bmumu() = 0;
      }
      if( parent.EF_2mu4T_Bmumu_Barrel.IsAvailable() ) {
         EF_2mu4T_Bmumu_Barrel() = parent.EF_2mu4T_Bmumu_Barrel();
      } else {
         EF_2mu4T_Bmumu_Barrel() = 0;
      }
      if( parent.EF_2mu4T_Bmumu_BarrelOnly.IsAvailable() ) {
         EF_2mu4T_Bmumu_BarrelOnly() = parent.EF_2mu4T_Bmumu_BarrelOnly();
      } else {
         EF_2mu4T_Bmumu_BarrelOnly() = 0;
      }
      if( parent.EF_2mu4T_Bmumux.IsAvailable() ) {
         EF_2mu4T_Bmumux() = parent.EF_2mu4T_Bmumux();
      } else {
         EF_2mu4T_Bmumux() = 0;
      }
      if( parent.EF_2mu4T_Bmumux_Barrel.IsAvailable() ) {
         EF_2mu4T_Bmumux_Barrel() = parent.EF_2mu4T_Bmumux_Barrel();
      } else {
         EF_2mu4T_Bmumux_Barrel() = 0;
      }
      if( parent.EF_2mu4T_Bmumux_BarrelOnly.IsAvailable() ) {
         EF_2mu4T_Bmumux_BarrelOnly() = parent.EF_2mu4T_Bmumux_BarrelOnly();
      } else {
         EF_2mu4T_Bmumux_BarrelOnly() = 0;
      }
      if( parent.EF_2mu4T_DiMu.IsAvailable() ) {
         EF_2mu4T_DiMu() = parent.EF_2mu4T_DiMu();
      } else {
         EF_2mu4T_DiMu() = 0;
      }
      if( parent.EF_2mu4T_DiMu_Barrel.IsAvailable() ) {
         EF_2mu4T_DiMu_Barrel() = parent.EF_2mu4T_DiMu_Barrel();
      } else {
         EF_2mu4T_DiMu_Barrel() = 0;
      }
      if( parent.EF_2mu4T_DiMu_BarrelOnly.IsAvailable() ) {
         EF_2mu4T_DiMu_BarrelOnly() = parent.EF_2mu4T_DiMu_BarrelOnly();
      } else {
         EF_2mu4T_DiMu_BarrelOnly() = 0;
      }
      if( parent.EF_2mu4T_DiMu_L2StarB.IsAvailable() ) {
         EF_2mu4T_DiMu_L2StarB() = parent.EF_2mu4T_DiMu_L2StarB();
      } else {
         EF_2mu4T_DiMu_L2StarB() = 0;
      }
      if( parent.EF_2mu4T_DiMu_L2StarC.IsAvailable() ) {
         EF_2mu4T_DiMu_L2StarC() = parent.EF_2mu4T_DiMu_L2StarC();
      } else {
         EF_2mu4T_DiMu_L2StarC() = 0;
      }
      if( parent.EF_2mu4T_DiMu_e5_tight1.IsAvailable() ) {
         EF_2mu4T_DiMu_e5_tight1() = parent.EF_2mu4T_DiMu_e5_tight1();
      } else {
         EF_2mu4T_DiMu_e5_tight1() = 0;
      }
      if( parent.EF_2mu4T_DiMu_l2muonSA.IsAvailable() ) {
         EF_2mu4T_DiMu_l2muonSA() = parent.EF_2mu4T_DiMu_l2muonSA();
      } else {
         EF_2mu4T_DiMu_l2muonSA() = 0;
      }
      if( parent.EF_2mu4T_DiMu_noVtx_noOS.IsAvailable() ) {
         EF_2mu4T_DiMu_noVtx_noOS() = parent.EF_2mu4T_DiMu_noVtx_noOS();
      } else {
         EF_2mu4T_DiMu_noVtx_noOS() = 0;
      }
      if( parent.EF_2mu4T_Jpsimumu.IsAvailable() ) {
         EF_2mu4T_Jpsimumu() = parent.EF_2mu4T_Jpsimumu();
      } else {
         EF_2mu4T_Jpsimumu() = 0;
      }
      if( parent.EF_2mu4T_Jpsimumu_Barrel.IsAvailable() ) {
         EF_2mu4T_Jpsimumu_Barrel() = parent.EF_2mu4T_Jpsimumu_Barrel();
      } else {
         EF_2mu4T_Jpsimumu_Barrel() = 0;
      }
      if( parent.EF_2mu4T_Jpsimumu_BarrelOnly.IsAvailable() ) {
         EF_2mu4T_Jpsimumu_BarrelOnly() = parent.EF_2mu4T_Jpsimumu_BarrelOnly();
      } else {
         EF_2mu4T_Jpsimumu_BarrelOnly() = 0;
      }
      if( parent.EF_2mu4T_Jpsimumu_IDTrkNoCut.IsAvailable() ) {
         EF_2mu4T_Jpsimumu_IDTrkNoCut() = parent.EF_2mu4T_Jpsimumu_IDTrkNoCut();
      } else {
         EF_2mu4T_Jpsimumu_IDTrkNoCut() = 0;
      }
      if( parent.EF_2mu4T_Upsimumu.IsAvailable() ) {
         EF_2mu4T_Upsimumu() = parent.EF_2mu4T_Upsimumu();
      } else {
         EF_2mu4T_Upsimumu() = 0;
      }
      if( parent.EF_2mu4T_Upsimumu_Barrel.IsAvailable() ) {
         EF_2mu4T_Upsimumu_Barrel() = parent.EF_2mu4T_Upsimumu_Barrel();
      } else {
         EF_2mu4T_Upsimumu_Barrel() = 0;
      }
      if( parent.EF_2mu4T_Upsimumu_BarrelOnly.IsAvailable() ) {
         EF_2mu4T_Upsimumu_BarrelOnly() = parent.EF_2mu4T_Upsimumu_BarrelOnly();
      } else {
         EF_2mu4T_Upsimumu_BarrelOnly() = 0;
      }
      if( parent.EF_2mu4T_xe50_tclcw.IsAvailable() ) {
         EF_2mu4T_xe50_tclcw() = parent.EF_2mu4T_xe50_tclcw();
      } else {
         EF_2mu4T_xe50_tclcw() = 0;
      }
      if( parent.EF_2mu4T_xe60.IsAvailable() ) {
         EF_2mu4T_xe60() = parent.EF_2mu4T_xe60();
      } else {
         EF_2mu4T_xe60() = 0;
      }
      if( parent.EF_2mu4T_xe60_tclcw.IsAvailable() ) {
         EF_2mu4T_xe60_tclcw() = parent.EF_2mu4T_xe60_tclcw();
      } else {
         EF_2mu4T_xe60_tclcw() = 0;
      }
      if( parent.EF_2mu6.IsAvailable() ) {
         EF_2mu6() = parent.EF_2mu6();
      } else {
         EF_2mu6() = 0;
      }
      if( parent.EF_2mu6_Bmumu.IsAvailable() ) {
         EF_2mu6_Bmumu() = parent.EF_2mu6_Bmumu();
      } else {
         EF_2mu6_Bmumu() = 0;
      }
      if( parent.EF_2mu6_Bmumux.IsAvailable() ) {
         EF_2mu6_Bmumux() = parent.EF_2mu6_Bmumux();
      } else {
         EF_2mu6_Bmumux() = 0;
      }
      if( parent.EF_2mu6_DiMu.IsAvailable() ) {
         EF_2mu6_DiMu() = parent.EF_2mu6_DiMu();
      } else {
         EF_2mu6_DiMu() = 0;
      }
      if( parent.EF_2mu6_DiMu_DY20.IsAvailable() ) {
         EF_2mu6_DiMu_DY20() = parent.EF_2mu6_DiMu_DY20();
      } else {
         EF_2mu6_DiMu_DY20() = 0;
      }
      if( parent.EF_2mu6_DiMu_DY25.IsAvailable() ) {
         EF_2mu6_DiMu_DY25() = parent.EF_2mu6_DiMu_DY25();
      } else {
         EF_2mu6_DiMu_DY25() = 0;
      }
      if( parent.EF_2mu6_DiMu_noVtx_noOS.IsAvailable() ) {
         EF_2mu6_DiMu_noVtx_noOS() = parent.EF_2mu6_DiMu_noVtx_noOS();
      } else {
         EF_2mu6_DiMu_noVtx_noOS() = 0;
      }
      if( parent.EF_2mu6_Jpsimumu.IsAvailable() ) {
         EF_2mu6_Jpsimumu() = parent.EF_2mu6_Jpsimumu();
      } else {
         EF_2mu6_Jpsimumu() = 0;
      }
      if( parent.EF_2mu6_Upsimumu.IsAvailable() ) {
         EF_2mu6_Upsimumu() = parent.EF_2mu6_Upsimumu();
      } else {
         EF_2mu6_Upsimumu() = 0;
      }
      if( parent.EF_2mu6i_DiMu_DY.IsAvailable() ) {
         EF_2mu6i_DiMu_DY() = parent.EF_2mu6i_DiMu_DY();
      } else {
         EF_2mu6i_DiMu_DY() = 0;
      }
      if( parent.EF_2mu6i_DiMu_DY_2j25_a4tchad.IsAvailable() ) {
         EF_2mu6i_DiMu_DY_2j25_a4tchad() = parent.EF_2mu6i_DiMu_DY_2j25_a4tchad();
      } else {
         EF_2mu6i_DiMu_DY_2j25_a4tchad() = 0;
      }
      if( parent.EF_2mu6i_DiMu_DY_noVtx_noOS.IsAvailable() ) {
         EF_2mu6i_DiMu_DY_noVtx_noOS() = parent.EF_2mu6i_DiMu_DY_noVtx_noOS();
      } else {
         EF_2mu6i_DiMu_DY_noVtx_noOS() = 0;
      }
      if( parent.EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.IsAvailable() ) {
         EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad() = parent.EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad();
      } else {
         EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad() = 0;
      }
      if( parent.EF_2mu8_EFxe30.IsAvailable() ) {
         EF_2mu8_EFxe30() = parent.EF_2mu8_EFxe30();
      } else {
         EF_2mu8_EFxe30() = 0;
      }
      if( parent.EF_2mu8_EFxe30_tclcw.IsAvailable() ) {
         EF_2mu8_EFxe30_tclcw() = parent.EF_2mu8_EFxe30_tclcw();
      } else {
         EF_2mu8_EFxe30_tclcw() = 0;
      }
      if( parent.EF_2tau29T_medium1.IsAvailable() ) {
         EF_2tau29T_medium1() = parent.EF_2tau29T_medium1();
      } else {
         EF_2tau29T_medium1() = 0;
      }
      if( parent.EF_2tau29_medium1.IsAvailable() ) {
         EF_2tau29_medium1() = parent.EF_2tau29_medium1();
      } else {
         EF_2tau29_medium1() = 0;
      }
      if( parent.EF_2tau29i_medium1.IsAvailable() ) {
         EF_2tau29i_medium1() = parent.EF_2tau29i_medium1();
      } else {
         EF_2tau29i_medium1() = 0;
      }
      if( parent.EF_2tau38T_medium.IsAvailable() ) {
         EF_2tau38T_medium() = parent.EF_2tau38T_medium();
      } else {
         EF_2tau38T_medium() = 0;
      }
      if( parent.EF_2tau38T_medium1.IsAvailable() ) {
         EF_2tau38T_medium1() = parent.EF_2tau38T_medium1();
      } else {
         EF_2tau38T_medium1() = 0;
      }
      if( parent.EF_2tau38T_medium1_llh.IsAvailable() ) {
         EF_2tau38T_medium1_llh() = parent.EF_2tau38T_medium1_llh();
      } else {
         EF_2tau38T_medium1_llh() = 0;
      }
      if( parent.EF_b110_loose_j110_a4tchad_xe55_tclcw.IsAvailable() ) {
         EF_b110_loose_j110_a4tchad_xe55_tclcw() = parent.EF_b110_loose_j110_a4tchad_xe55_tclcw();
      } else {
         EF_b110_loose_j110_a4tchad_xe55_tclcw() = 0;
      }
      if( parent.EF_b110_loose_j110_a4tchad_xe60_tclcw.IsAvailable() ) {
         EF_b110_loose_j110_a4tchad_xe60_tclcw() = parent.EF_b110_loose_j110_a4tchad_xe60_tclcw();
      } else {
         EF_b110_loose_j110_a4tchad_xe60_tclcw() = 0;
      }
      if( parent.EF_b45_mediumEF_j110_j45_xe60_tclcw.IsAvailable() ) {
         EF_b45_mediumEF_j110_j45_xe60_tclcw() = parent.EF_b45_mediumEF_j110_j45_xe60_tclcw();
      } else {
         EF_b45_mediumEF_j110_j45_xe60_tclcw() = 0;
      }
      if( parent.EF_b55_mediumEF_j110_j55_xe60_tclcw.IsAvailable() ) {
         EF_b55_mediumEF_j110_j55_xe60_tclcw() = parent.EF_b55_mediumEF_j110_j55_xe60_tclcw();
      } else {
         EF_b55_mediumEF_j110_j55_xe60_tclcw() = 0;
      }
      if( parent.EF_b80_loose_j80_a4tchad_xe55_tclcw.IsAvailable() ) {
         EF_b80_loose_j80_a4tchad_xe55_tclcw() = parent.EF_b80_loose_j80_a4tchad_xe55_tclcw();
      } else {
         EF_b80_loose_j80_a4tchad_xe55_tclcw() = 0;
      }
      if( parent.EF_b80_loose_j80_a4tchad_xe60_tclcw.IsAvailable() ) {
         EF_b80_loose_j80_a4tchad_xe60_tclcw() = parent.EF_b80_loose_j80_a4tchad_xe60_tclcw();
      } else {
         EF_b80_loose_j80_a4tchad_xe60_tclcw() = 0;
      }
      if( parent.EF_b80_loose_j80_a4tchad_xe70_tclcw.IsAvailable() ) {
         EF_b80_loose_j80_a4tchad_xe70_tclcw() = parent.EF_b80_loose_j80_a4tchad_xe70_tclcw();
      } else {
         EF_b80_loose_j80_a4tchad_xe70_tclcw() = 0;
      }
      if( parent.EF_b80_loose_j80_a4tchad_xe75_tclcw.IsAvailable() ) {
         EF_b80_loose_j80_a4tchad_xe75_tclcw() = parent.EF_b80_loose_j80_a4tchad_xe75_tclcw();
      } else {
         EF_b80_loose_j80_a4tchad_xe75_tclcw() = 0;
      }
      if( parent.EF_e11_etcut.IsAvailable() ) {
         EF_e11_etcut() = parent.EF_e11_etcut();
      } else {
         EF_e11_etcut() = 0;
      }
      if( parent.EF_e12Tvh_loose1.IsAvailable() ) {
         EF_e12Tvh_loose1() = parent.EF_e12Tvh_loose1();
      } else {
         EF_e12Tvh_loose1() = 0;
      }
      if( parent.EF_e12Tvh_loose1_mu8.IsAvailable() ) {
         EF_e12Tvh_loose1_mu8() = parent.EF_e12Tvh_loose1_mu8();
      } else {
         EF_e12Tvh_loose1_mu8() = 0;
      }
      if( parent.EF_e12Tvh_medium1.IsAvailable() ) {
         EF_e12Tvh_medium1() = parent.EF_e12Tvh_medium1();
      } else {
         EF_e12Tvh_medium1() = 0;
      }
      if( parent.EF_e12Tvh_medium1_mu10.IsAvailable() ) {
         EF_e12Tvh_medium1_mu10() = parent.EF_e12Tvh_medium1_mu10();
      } else {
         EF_e12Tvh_medium1_mu10() = 0;
      }
      if( parent.EF_e12Tvh_medium1_mu6.IsAvailable() ) {
         EF_e12Tvh_medium1_mu6() = parent.EF_e12Tvh_medium1_mu6();
      } else {
         EF_e12Tvh_medium1_mu6() = 0;
      }
      if( parent.EF_e12Tvh_medium1_mu6_topo_medium.IsAvailable() ) {
         EF_e12Tvh_medium1_mu6_topo_medium() = parent.EF_e12Tvh_medium1_mu6_topo_medium();
      } else {
         EF_e12Tvh_medium1_mu6_topo_medium() = 0;
      }
      if( parent.EF_e12Tvh_medium1_mu8.IsAvailable() ) {
         EF_e12Tvh_medium1_mu8() = parent.EF_e12Tvh_medium1_mu8();
      } else {
         EF_e12Tvh_medium1_mu8() = 0;
      }
      if( parent.EF_e13_etcutTrk_xs60.IsAvailable() ) {
         EF_e13_etcutTrk_xs60() = parent.EF_e13_etcutTrk_xs60();
      } else {
         EF_e13_etcutTrk_xs60() = 0;
      }
      if( parent.EF_e13_etcutTrk_xs60_dphi2j15xe20.IsAvailable() ) {
         EF_e13_etcutTrk_xs60_dphi2j15xe20() = parent.EF_e13_etcutTrk_xs60_dphi2j15xe20();
      } else {
         EF_e13_etcutTrk_xs60_dphi2j15xe20() = 0;
      }
      if( parent.EF_e14_tight1_e4_etcut_Jpsi.IsAvailable() ) {
         EF_e14_tight1_e4_etcut_Jpsi() = parent.EF_e14_tight1_e4_etcut_Jpsi();
      } else {
         EF_e14_tight1_e4_etcut_Jpsi() = 0;
      }
      if( parent.EF_e15vh_medium1.IsAvailable() ) {
         EF_e15vh_medium1() = parent.EF_e15vh_medium1();
      } else {
         EF_e15vh_medium1() = 0;
      }
      if( parent.EF_e18_loose1.IsAvailable() ) {
         EF_e18_loose1() = parent.EF_e18_loose1();
      } else {
         EF_e18_loose1() = 0;
      }
      if( parent.EF_e18_loose1_g25_medium.IsAvailable() ) {
         EF_e18_loose1_g25_medium() = parent.EF_e18_loose1_g25_medium();
      } else {
         EF_e18_loose1_g25_medium() = 0;
      }
      if( parent.EF_e18_loose1_g35_loose.IsAvailable() ) {
         EF_e18_loose1_g35_loose() = parent.EF_e18_loose1_g35_loose();
      } else {
         EF_e18_loose1_g35_loose() = 0;
      }
      if( parent.EF_e18_loose1_g35_medium.IsAvailable() ) {
         EF_e18_loose1_g35_medium() = parent.EF_e18_loose1_g35_medium();
      } else {
         EF_e18_loose1_g35_medium() = 0;
      }
      if( parent.EF_e18_medium1.IsAvailable() ) {
         EF_e18_medium1() = parent.EF_e18_medium1();
      } else {
         EF_e18_medium1() = 0;
      }
      if( parent.EF_e18_medium1_g25_loose.IsAvailable() ) {
         EF_e18_medium1_g25_loose() = parent.EF_e18_medium1_g25_loose();
      } else {
         EF_e18_medium1_g25_loose() = 0;
      }
      if( parent.EF_e18_medium1_g25_medium.IsAvailable() ) {
         EF_e18_medium1_g25_medium() = parent.EF_e18_medium1_g25_medium();
      } else {
         EF_e18_medium1_g25_medium() = 0;
      }
      if( parent.EF_e18_medium1_g35_loose.IsAvailable() ) {
         EF_e18_medium1_g35_loose() = parent.EF_e18_medium1_g35_loose();
      } else {
         EF_e18_medium1_g35_loose() = 0;
      }
      if( parent.EF_e18_medium1_g35_medium.IsAvailable() ) {
         EF_e18_medium1_g35_medium() = parent.EF_e18_medium1_g35_medium();
      } else {
         EF_e18_medium1_g35_medium() = 0;
      }
      if( parent.EF_e18vh_medium1.IsAvailable() ) {
         EF_e18vh_medium1() = parent.EF_e18vh_medium1();
      } else {
         EF_e18vh_medium1() = 0;
      }
      if( parent.EF_e18vh_medium1_2e7T_medium1.IsAvailable() ) {
         EF_e18vh_medium1_2e7T_medium1() = parent.EF_e18vh_medium1_2e7T_medium1();
      } else {
         EF_e18vh_medium1_2e7T_medium1() = 0;
      }
      if( parent.EF_e20_etcutTrk_xe30_dphi2j15xe20.IsAvailable() ) {
         EF_e20_etcutTrk_xe30_dphi2j15xe20() = parent.EF_e20_etcutTrk_xe30_dphi2j15xe20();
      } else {
         EF_e20_etcutTrk_xe30_dphi2j15xe20() = 0;
      }
      if( parent.EF_e20_etcutTrk_xs60_dphi2j15xe20.IsAvailable() ) {
         EF_e20_etcutTrk_xs60_dphi2j15xe20() = parent.EF_e20_etcutTrk_xs60_dphi2j15xe20();
      } else {
         EF_e20_etcutTrk_xs60_dphi2j15xe20() = 0;
      }
      if( parent.EF_e20vhT_medium1_g6T_etcut_Upsi.IsAvailable() ) {
         EF_e20vhT_medium1_g6T_etcut_Upsi() = parent.EF_e20vhT_medium1_g6T_etcut_Upsi();
      } else {
         EF_e20vhT_medium1_g6T_etcut_Upsi() = 0;
      }
      if( parent.EF_e20vhT_tight1_g6T_etcut_Upsi.IsAvailable() ) {
         EF_e20vhT_tight1_g6T_etcut_Upsi() = parent.EF_e20vhT_tight1_g6T_etcut_Upsi();
      } else {
         EF_e20vhT_tight1_g6T_etcut_Upsi() = 0;
      }
      if( parent.EF_e22vh_loose.IsAvailable() ) {
         EF_e22vh_loose() = parent.EF_e22vh_loose();
      } else {
         EF_e22vh_loose() = 0;
      }
      if( parent.EF_e22vh_loose0.IsAvailable() ) {
         EF_e22vh_loose0() = parent.EF_e22vh_loose0();
      } else {
         EF_e22vh_loose0() = 0;
      }
      if( parent.EF_e22vh_loose1.IsAvailable() ) {
         EF_e22vh_loose1() = parent.EF_e22vh_loose1();
      } else {
         EF_e22vh_loose1() = 0;
      }
      if( parent.EF_e22vh_medium1.IsAvailable() ) {
         EF_e22vh_medium1() = parent.EF_e22vh_medium1();
      } else {
         EF_e22vh_medium1() = 0;
      }
      if( parent.EF_e22vh_medium1_IDTrkNoCut.IsAvailable() ) {
         EF_e22vh_medium1_IDTrkNoCut() = parent.EF_e22vh_medium1_IDTrkNoCut();
      } else {
         EF_e22vh_medium1_IDTrkNoCut() = 0;
      }
      if( parent.EF_e22vh_medium1_IdScan.IsAvailable() ) {
         EF_e22vh_medium1_IdScan() = parent.EF_e22vh_medium1_IdScan();
      } else {
         EF_e22vh_medium1_IdScan() = 0;
      }
      if( parent.EF_e22vh_medium1_SiTrk.IsAvailable() ) {
         EF_e22vh_medium1_SiTrk() = parent.EF_e22vh_medium1_SiTrk();
      } else {
         EF_e22vh_medium1_SiTrk() = 0;
      }
      if( parent.EF_e22vh_medium1_TRT.IsAvailable() ) {
         EF_e22vh_medium1_TRT() = parent.EF_e22vh_medium1_TRT();
      } else {
         EF_e22vh_medium1_TRT() = 0;
      }
      if( parent.EF_e22vhi_medium1.IsAvailable() ) {
         EF_e22vhi_medium1() = parent.EF_e22vhi_medium1();
      } else {
         EF_e22vhi_medium1() = 0;
      }
      if( parent.EF_e24vh_loose.IsAvailable() ) {
         EF_e24vh_loose() = parent.EF_e24vh_loose();
      } else {
         EF_e24vh_loose() = 0;
      }
      if( parent.EF_e24vh_loose0.IsAvailable() ) {
         EF_e24vh_loose0() = parent.EF_e24vh_loose0();
      } else {
         EF_e24vh_loose0() = 0;
      }
      if( parent.EF_e24vh_loose1.IsAvailable() ) {
         EF_e24vh_loose1() = parent.EF_e24vh_loose1();
      } else {
         EF_e24vh_loose1() = 0;
      }
      if( parent.EF_e24vh_medium1.IsAvailable() ) {
         EF_e24vh_medium1() = parent.EF_e24vh_medium1();
      } else {
         EF_e24vh_medium1() = 0;
      }
      if( parent.EF_e24vh_medium1_EFxe30.IsAvailable() ) {
         EF_e24vh_medium1_EFxe30() = parent.EF_e24vh_medium1_EFxe30();
      } else {
         EF_e24vh_medium1_EFxe30() = 0;
      }
      if( parent.EF_e24vh_medium1_EFxe30_tcem.IsAvailable() ) {
         EF_e24vh_medium1_EFxe30_tcem() = parent.EF_e24vh_medium1_EFxe30_tcem();
      } else {
         EF_e24vh_medium1_EFxe30_tcem() = 0;
      }
      if( parent.EF_e24vh_medium1_EFxe35_tcem.IsAvailable() ) {
         EF_e24vh_medium1_EFxe35_tcem() = parent.EF_e24vh_medium1_EFxe35_tcem();
      } else {
         EF_e24vh_medium1_EFxe35_tcem() = 0;
      }
      if( parent.EF_e24vh_medium1_EFxe35_tclcw.IsAvailable() ) {
         EF_e24vh_medium1_EFxe35_tclcw() = parent.EF_e24vh_medium1_EFxe35_tclcw();
      } else {
         EF_e24vh_medium1_EFxe35_tclcw() = 0;
      }
      if( parent.EF_e24vh_medium1_EFxe40.IsAvailable() ) {
         EF_e24vh_medium1_EFxe40() = parent.EF_e24vh_medium1_EFxe40();
      } else {
         EF_e24vh_medium1_EFxe40() = 0;
      }
      if( parent.EF_e24vh_medium1_IDTrkNoCut.IsAvailable() ) {
         EF_e24vh_medium1_IDTrkNoCut() = parent.EF_e24vh_medium1_IDTrkNoCut();
      } else {
         EF_e24vh_medium1_IDTrkNoCut() = 0;
      }
      if( parent.EF_e24vh_medium1_IdScan.IsAvailable() ) {
         EF_e24vh_medium1_IdScan() = parent.EF_e24vh_medium1_IdScan();
      } else {
         EF_e24vh_medium1_IdScan() = 0;
      }
      if( parent.EF_e24vh_medium1_L2StarB.IsAvailable() ) {
         EF_e24vh_medium1_L2StarB() = parent.EF_e24vh_medium1_L2StarB();
      } else {
         EF_e24vh_medium1_L2StarB() = 0;
      }
      if( parent.EF_e24vh_medium1_L2StarC.IsAvailable() ) {
         EF_e24vh_medium1_L2StarC() = parent.EF_e24vh_medium1_L2StarC();
      } else {
         EF_e24vh_medium1_L2StarC() = 0;
      }
      if( parent.EF_e24vh_medium1_SiTrk.IsAvailable() ) {
         EF_e24vh_medium1_SiTrk() = parent.EF_e24vh_medium1_SiTrk();
      } else {
         EF_e24vh_medium1_SiTrk() = 0;
      }
      if( parent.EF_e24vh_medium1_TRT.IsAvailable() ) {
         EF_e24vh_medium1_TRT() = parent.EF_e24vh_medium1_TRT();
      } else {
         EF_e24vh_medium1_TRT() = 0;
      }
      if( parent.EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.IsAvailable() ) {
         EF_e24vh_medium1_b35_mediumEF_j35_a4tchad() = parent.EF_e24vh_medium1_b35_mediumEF_j35_a4tchad();
      } else {
         EF_e24vh_medium1_b35_mediumEF_j35_a4tchad() = 0;
      }
      if( parent.EF_e24vh_medium1_e7_medium1.IsAvailable() ) {
         EF_e24vh_medium1_e7_medium1() = parent.EF_e24vh_medium1_e7_medium1();
      } else {
         EF_e24vh_medium1_e7_medium1() = 0;
      }
      if( parent.EF_e24vh_tight1_e15_NoCut_Zee.IsAvailable() ) {
         EF_e24vh_tight1_e15_NoCut_Zee() = parent.EF_e24vh_tight1_e15_NoCut_Zee();
      } else {
         EF_e24vh_tight1_e15_NoCut_Zee() = 0;
      }
      if( parent.EF_e24vhi_loose1_mu8.IsAvailable() ) {
         EF_e24vhi_loose1_mu8() = parent.EF_e24vhi_loose1_mu8();
      } else {
         EF_e24vhi_loose1_mu8() = 0;
      }
      if( parent.EF_e24vhi_medium1.IsAvailable() ) {
         EF_e24vhi_medium1() = parent.EF_e24vhi_medium1();
      } else {
         EF_e24vhi_medium1() = 0;
      }
      if( parent.EF_e45_etcut.IsAvailable() ) {
         EF_e45_etcut() = parent.EF_e45_etcut();
      } else {
         EF_e45_etcut() = 0;
      }
      if( parent.EF_e45_medium1.IsAvailable() ) {
         EF_e45_medium1() = parent.EF_e45_medium1();
      } else {
         EF_e45_medium1() = 0;
      }
      if( parent.EF_e5_tight1.IsAvailable() ) {
         EF_e5_tight1() = parent.EF_e5_tight1();
      } else {
         EF_e5_tight1() = 0;
      }
      if( parent.EF_e5_tight1_e14_etcut_Jpsi.IsAvailable() ) {
         EF_e5_tight1_e14_etcut_Jpsi() = parent.EF_e5_tight1_e14_etcut_Jpsi();
      } else {
         EF_e5_tight1_e14_etcut_Jpsi() = 0;
      }
      if( parent.EF_e5_tight1_e4_etcut_Jpsi.IsAvailable() ) {
         EF_e5_tight1_e4_etcut_Jpsi() = parent.EF_e5_tight1_e4_etcut_Jpsi();
      } else {
         EF_e5_tight1_e4_etcut_Jpsi() = 0;
      }
      if( parent.EF_e5_tight1_e4_etcut_Jpsi_IdScan.IsAvailable() ) {
         EF_e5_tight1_e4_etcut_Jpsi_IdScan() = parent.EF_e5_tight1_e4_etcut_Jpsi_IdScan();
      } else {
         EF_e5_tight1_e4_etcut_Jpsi_IdScan() = 0;
      }
      if( parent.EF_e5_tight1_e4_etcut_Jpsi_L2StarB.IsAvailable() ) {
         EF_e5_tight1_e4_etcut_Jpsi_L2StarB() = parent.EF_e5_tight1_e4_etcut_Jpsi_L2StarB();
      } else {
         EF_e5_tight1_e4_etcut_Jpsi_L2StarB() = 0;
      }
      if( parent.EF_e5_tight1_e4_etcut_Jpsi_L2StarC.IsAvailable() ) {
         EF_e5_tight1_e4_etcut_Jpsi_L2StarC() = parent.EF_e5_tight1_e4_etcut_Jpsi_L2StarC();
      } else {
         EF_e5_tight1_e4_etcut_Jpsi_L2StarC() = 0;
      }
      if( parent.EF_e5_tight1_e4_etcut_Jpsi_SiTrk.IsAvailable() ) {
         EF_e5_tight1_e4_etcut_Jpsi_SiTrk() = parent.EF_e5_tight1_e4_etcut_Jpsi_SiTrk();
      } else {
         EF_e5_tight1_e4_etcut_Jpsi_SiTrk() = 0;
      }
      if( parent.EF_e5_tight1_e4_etcut_Jpsi_TRT.IsAvailable() ) {
         EF_e5_tight1_e4_etcut_Jpsi_TRT() = parent.EF_e5_tight1_e4_etcut_Jpsi_TRT();
      } else {
         EF_e5_tight1_e4_etcut_Jpsi_TRT() = 0;
      }
      if( parent.EF_e5_tight1_e5_NoCut.IsAvailable() ) {
         EF_e5_tight1_e5_NoCut() = parent.EF_e5_tight1_e5_NoCut();
      } else {
         EF_e5_tight1_e5_NoCut() = 0;
      }
      if( parent.EF_e5_tight1_e9_etcut_Jpsi.IsAvailable() ) {
         EF_e5_tight1_e9_etcut_Jpsi() = parent.EF_e5_tight1_e9_etcut_Jpsi();
      } else {
         EF_e5_tight1_e9_etcut_Jpsi() = 0;
      }
      if( parent.EF_e60_etcut.IsAvailable() ) {
         EF_e60_etcut() = parent.EF_e60_etcut();
      } else {
         EF_e60_etcut() = 0;
      }
      if( parent.EF_e60_medium1.IsAvailable() ) {
         EF_e60_medium1() = parent.EF_e60_medium1();
      } else {
         EF_e60_medium1() = 0;
      }
      if( parent.EF_e7T_loose1.IsAvailable() ) {
         EF_e7T_loose1() = parent.EF_e7T_loose1();
      } else {
         EF_e7T_loose1() = 0;
      }
      if( parent.EF_e7T_loose1_2mu6.IsAvailable() ) {
         EF_e7T_loose1_2mu6() = parent.EF_e7T_loose1_2mu6();
      } else {
         EF_e7T_loose1_2mu6() = 0;
      }
      if( parent.EF_e7T_medium1.IsAvailable() ) {
         EF_e7T_medium1() = parent.EF_e7T_medium1();
      } else {
         EF_e7T_medium1() = 0;
      }
      if( parent.EF_e7T_medium1_2mu6.IsAvailable() ) {
         EF_e7T_medium1_2mu6() = parent.EF_e7T_medium1_2mu6();
      } else {
         EF_e7T_medium1_2mu6() = 0;
      }
      if( parent.EF_e9_tight1_e4_etcut_Jpsi.IsAvailable() ) {
         EF_e9_tight1_e4_etcut_Jpsi() = parent.EF_e9_tight1_e4_etcut_Jpsi();
      } else {
         EF_e9_tight1_e4_etcut_Jpsi() = 0;
      }
      if( parent.EF_eb_physics.IsAvailable() ) {
         EF_eb_physics() = parent.EF_eb_physics();
      } else {
         EF_eb_physics() = 0;
      }
      if( parent.EF_eb_physics_empty.IsAvailable() ) {
         EF_eb_physics_empty() = parent.EF_eb_physics_empty();
      } else {
         EF_eb_physics_empty() = 0;
      }
      if( parent.EF_eb_physics_firstempty.IsAvailable() ) {
         EF_eb_physics_firstempty() = parent.EF_eb_physics_firstempty();
      } else {
         EF_eb_physics_firstempty() = 0;
      }
      if( parent.EF_eb_physics_noL1PS.IsAvailable() ) {
         EF_eb_physics_noL1PS() = parent.EF_eb_physics_noL1PS();
      } else {
         EF_eb_physics_noL1PS() = 0;
      }
      if( parent.EF_eb_physics_unpaired_iso.IsAvailable() ) {
         EF_eb_physics_unpaired_iso() = parent.EF_eb_physics_unpaired_iso();
      } else {
         EF_eb_physics_unpaired_iso() = 0;
      }
      if( parent.EF_eb_physics_unpaired_noniso.IsAvailable() ) {
         EF_eb_physics_unpaired_noniso() = parent.EF_eb_physics_unpaired_noniso();
      } else {
         EF_eb_physics_unpaired_noniso() = 0;
      }
      if( parent.EF_eb_random.IsAvailable() ) {
         EF_eb_random() = parent.EF_eb_random();
      } else {
         EF_eb_random() = 0;
      }
      if( parent.EF_eb_random_empty.IsAvailable() ) {
         EF_eb_random_empty() = parent.EF_eb_random_empty();
      } else {
         EF_eb_random_empty() = 0;
      }
      if( parent.EF_eb_random_firstempty.IsAvailable() ) {
         EF_eb_random_firstempty() = parent.EF_eb_random_firstempty();
      } else {
         EF_eb_random_firstempty() = 0;
      }
      if( parent.EF_eb_random_unpaired_iso.IsAvailable() ) {
         EF_eb_random_unpaired_iso() = parent.EF_eb_random_unpaired_iso();
      } else {
         EF_eb_random_unpaired_iso() = 0;
      }
      if( parent.EF_g100_loose.IsAvailable() ) {
         EF_g100_loose() = parent.EF_g100_loose();
      } else {
         EF_g100_loose() = 0;
      }
      if( parent.EF_g10_NoCut_cosmic.IsAvailable() ) {
         EF_g10_NoCut_cosmic() = parent.EF_g10_NoCut_cosmic();
      } else {
         EF_g10_NoCut_cosmic() = 0;
      }
      if( parent.EF_g10_loose.IsAvailable() ) {
         EF_g10_loose() = parent.EF_g10_loose();
      } else {
         EF_g10_loose() = 0;
      }
      if( parent.EF_g10_medium.IsAvailable() ) {
         EF_g10_medium() = parent.EF_g10_medium();
      } else {
         EF_g10_medium() = 0;
      }
      if( parent.EF_g120_loose.IsAvailable() ) {
         EF_g120_loose() = parent.EF_g120_loose();
      } else {
         EF_g120_loose() = 0;
      }
      if( parent.EF_g12Tvh_loose.IsAvailable() ) {
         EF_g12Tvh_loose() = parent.EF_g12Tvh_loose();
      } else {
         EF_g12Tvh_loose() = 0;
      }
      if( parent.EF_g12Tvh_loose_larcalib.IsAvailable() ) {
         EF_g12Tvh_loose_larcalib() = parent.EF_g12Tvh_loose_larcalib();
      } else {
         EF_g12Tvh_loose_larcalib() = 0;
      }
      if( parent.EF_g12Tvh_medium.IsAvailable() ) {
         EF_g12Tvh_medium() = parent.EF_g12Tvh_medium();
      } else {
         EF_g12Tvh_medium() = 0;
      }
      if( parent.EF_g15_loose.IsAvailable() ) {
         EF_g15_loose() = parent.EF_g15_loose();
      } else {
         EF_g15_loose() = 0;
      }
      if( parent.EF_g15vh_loose.IsAvailable() ) {
         EF_g15vh_loose() = parent.EF_g15vh_loose();
      } else {
         EF_g15vh_loose() = 0;
      }
      if( parent.EF_g15vh_medium.IsAvailable() ) {
         EF_g15vh_medium() = parent.EF_g15vh_medium();
      } else {
         EF_g15vh_medium() = 0;
      }
      if( parent.EF_g200_etcut.IsAvailable() ) {
         EF_g200_etcut() = parent.EF_g200_etcut();
      } else {
         EF_g200_etcut() = 0;
      }
      if( parent.EF_g20Tvh_medium.IsAvailable() ) {
         EF_g20Tvh_medium() = parent.EF_g20Tvh_medium();
      } else {
         EF_g20Tvh_medium() = 0;
      }
      if( parent.EF_g20_etcut.IsAvailable() ) {
         EF_g20_etcut() = parent.EF_g20_etcut();
      } else {
         EF_g20_etcut() = 0;
      }
      if( parent.EF_g20_loose.IsAvailable() ) {
         EF_g20_loose() = parent.EF_g20_loose();
      } else {
         EF_g20_loose() = 0;
      }
      if( parent.EF_g20_loose_larcalib.IsAvailable() ) {
         EF_g20_loose_larcalib() = parent.EF_g20_loose_larcalib();
      } else {
         EF_g20_loose_larcalib() = 0;
      }
      if( parent.EF_g20_medium.IsAvailable() ) {
         EF_g20_medium() = parent.EF_g20_medium();
      } else {
         EF_g20_medium() = 0;
      }
      if( parent.EF_g20vh_medium.IsAvailable() ) {
         EF_g20vh_medium() = parent.EF_g20vh_medium();
      } else {
         EF_g20vh_medium() = 0;
      }
      if( parent.EF_g30_loose_g20_loose.IsAvailable() ) {
         EF_g30_loose_g20_loose() = parent.EF_g30_loose_g20_loose();
      } else {
         EF_g30_loose_g20_loose() = 0;
      }
      if( parent.EF_g30_medium_g20_medium.IsAvailable() ) {
         EF_g30_medium_g20_medium() = parent.EF_g30_medium_g20_medium();
      } else {
         EF_g30_medium_g20_medium() = 0;
      }
      if( parent.EF_g35_loose_g25_loose.IsAvailable() ) {
         EF_g35_loose_g25_loose() = parent.EF_g35_loose_g25_loose();
      } else {
         EF_g35_loose_g25_loose() = 0;
      }
      if( parent.EF_g35_loose_g30_loose.IsAvailable() ) {
         EF_g35_loose_g30_loose() = parent.EF_g35_loose_g30_loose();
      } else {
         EF_g35_loose_g30_loose() = 0;
      }
      if( parent.EF_g40_loose.IsAvailable() ) {
         EF_g40_loose() = parent.EF_g40_loose();
      } else {
         EF_g40_loose() = 0;
      }
      if( parent.EF_g40_loose_EFxe50.IsAvailable() ) {
         EF_g40_loose_EFxe50() = parent.EF_g40_loose_EFxe50();
      } else {
         EF_g40_loose_EFxe50() = 0;
      }
      if( parent.EF_g40_loose_L2EFxe50.IsAvailable() ) {
         EF_g40_loose_L2EFxe50() = parent.EF_g40_loose_L2EFxe50();
      } else {
         EF_g40_loose_L2EFxe50() = 0;
      }
      if( parent.EF_g40_loose_L2EFxe60.IsAvailable() ) {
         EF_g40_loose_L2EFxe60() = parent.EF_g40_loose_L2EFxe60();
      } else {
         EF_g40_loose_L2EFxe60() = 0;
      }
      if( parent.EF_g40_loose_L2EFxe60_tclcw.IsAvailable() ) {
         EF_g40_loose_L2EFxe60_tclcw() = parent.EF_g40_loose_L2EFxe60_tclcw();
      } else {
         EF_g40_loose_L2EFxe60_tclcw() = 0;
      }
      if( parent.EF_g40_loose_g25_loose.IsAvailable() ) {
         EF_g40_loose_g25_loose() = parent.EF_g40_loose_g25_loose();
      } else {
         EF_g40_loose_g25_loose() = 0;
      }
      if( parent.EF_g40_loose_g30_loose.IsAvailable() ) {
         EF_g40_loose_g30_loose() = parent.EF_g40_loose_g30_loose();
      } else {
         EF_g40_loose_g30_loose() = 0;
      }
      if( parent.EF_g40_loose_larcalib.IsAvailable() ) {
         EF_g40_loose_larcalib() = parent.EF_g40_loose_larcalib();
      } else {
         EF_g40_loose_larcalib() = 0;
      }
      if( parent.EF_g5_NoCut_cosmic.IsAvailable() ) {
         EF_g5_NoCut_cosmic() = parent.EF_g5_NoCut_cosmic();
      } else {
         EF_g5_NoCut_cosmic() = 0;
      }
      if( parent.EF_g60_loose.IsAvailable() ) {
         EF_g60_loose() = parent.EF_g60_loose();
      } else {
         EF_g60_loose() = 0;
      }
      if( parent.EF_g60_loose_larcalib.IsAvailable() ) {
         EF_g60_loose_larcalib() = parent.EF_g60_loose_larcalib();
      } else {
         EF_g60_loose_larcalib() = 0;
      }
      if( parent.EF_g80_loose.IsAvailable() ) {
         EF_g80_loose() = parent.EF_g80_loose();
      } else {
         EF_g80_loose() = 0;
      }
      if( parent.EF_g80_loose_larcalib.IsAvailable() ) {
         EF_g80_loose_larcalib() = parent.EF_g80_loose_larcalib();
      } else {
         EF_g80_loose_larcalib() = 0;
      }
      if( parent.EF_j10_a4tchadloose.IsAvailable() ) {
         EF_j10_a4tchadloose() = parent.EF_j10_a4tchadloose();
      } else {
         EF_j10_a4tchadloose() = 0;
      }
      if( parent.EF_j10_a4tchadloose_L1MBTS.IsAvailable() ) {
         EF_j10_a4tchadloose_L1MBTS() = parent.EF_j10_a4tchadloose_L1MBTS();
      } else {
         EF_j10_a4tchadloose_L1MBTS() = 0;
      }
      if( parent.EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS.IsAvailable() ) {
         EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS() = parent.EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS();
      } else {
         EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS() = 0;
      }
      if( parent.EF_j110_2j55_a4tchad.IsAvailable() ) {
         EF_j110_2j55_a4tchad() = parent.EF_j110_2j55_a4tchad();
      } else {
         EF_j110_2j55_a4tchad() = 0;
      }
      if( parent.EF_j110_2j55_a4tchad_L2FS.IsAvailable() ) {
         EF_j110_2j55_a4tchad_L2FS() = parent.EF_j110_2j55_a4tchad_L2FS();
      } else {
         EF_j110_2j55_a4tchad_L2FS() = 0;
      }
      if( parent.EF_j110_a10tcem_L2FS.IsAvailable() ) {
         EF_j110_a10tcem_L2FS() = parent.EF_j110_a10tcem_L2FS();
      } else {
         EF_j110_a10tcem_L2FS() = 0;
      }
      if( parent.EF_j110_a10tcem_L2FS_2j55_a4tchad.IsAvailable() ) {
         EF_j110_a10tcem_L2FS_2j55_a4tchad() = parent.EF_j110_a10tcem_L2FS_2j55_a4tchad();
      } else {
         EF_j110_a10tcem_L2FS_2j55_a4tchad() = 0;
      }
      if( parent.EF_j110_a4tchad.IsAvailable() ) {
         EF_j110_a4tchad() = parent.EF_j110_a4tchad();
      } else {
         EF_j110_a4tchad() = 0;
      }
      if( parent.EF_j110_a4tchad_xe100_tclcw.IsAvailable() ) {
         EF_j110_a4tchad_xe100_tclcw() = parent.EF_j110_a4tchad_xe100_tclcw();
      } else {
         EF_j110_a4tchad_xe100_tclcw() = 0;
      }
      if( parent.EF_j110_a4tchad_xe100_tclcw_veryloose.IsAvailable() ) {
         EF_j110_a4tchad_xe100_tclcw_veryloose() = parent.EF_j110_a4tchad_xe100_tclcw_veryloose();
      } else {
         EF_j110_a4tchad_xe100_tclcw_veryloose() = 0;
      }
      if( parent.EF_j110_a4tchad_xe50_tclcw.IsAvailable() ) {
         EF_j110_a4tchad_xe50_tclcw() = parent.EF_j110_a4tchad_xe50_tclcw();
      } else {
         EF_j110_a4tchad_xe50_tclcw() = 0;
      }
      if( parent.EF_j110_a4tchad_xe55_tclcw.IsAvailable() ) {
         EF_j110_a4tchad_xe55_tclcw() = parent.EF_j110_a4tchad_xe55_tclcw();
      } else {
         EF_j110_a4tchad_xe55_tclcw() = 0;
      }
      if( parent.EF_j110_a4tchad_xe60_tclcw.IsAvailable() ) {
         EF_j110_a4tchad_xe60_tclcw() = parent.EF_j110_a4tchad_xe60_tclcw();
      } else {
         EF_j110_a4tchad_xe60_tclcw() = 0;
      }
      if( parent.EF_j110_a4tchad_xe60_tclcw_loose.IsAvailable() ) {
         EF_j110_a4tchad_xe60_tclcw_loose() = parent.EF_j110_a4tchad_xe60_tclcw_loose();
      } else {
         EF_j110_a4tchad_xe60_tclcw_loose() = 0;
      }
      if( parent.EF_j110_a4tchad_xe60_tclcw_veryloose.IsAvailable() ) {
         EF_j110_a4tchad_xe60_tclcw_veryloose() = parent.EF_j110_a4tchad_xe60_tclcw_veryloose();
      } else {
         EF_j110_a4tchad_xe60_tclcw_veryloose() = 0;
      }
      if( parent.EF_j110_a4tchad_xe65_tclcw.IsAvailable() ) {
         EF_j110_a4tchad_xe65_tclcw() = parent.EF_j110_a4tchad_xe65_tclcw();
      } else {
         EF_j110_a4tchad_xe65_tclcw() = 0;
      }
      if( parent.EF_j110_a4tchad_xe70_tclcw_loose.IsAvailable() ) {
         EF_j110_a4tchad_xe70_tclcw_loose() = parent.EF_j110_a4tchad_xe70_tclcw_loose();
      } else {
         EF_j110_a4tchad_xe70_tclcw_loose() = 0;
      }
      if( parent.EF_j110_a4tchad_xe70_tclcw_veryloose.IsAvailable() ) {
         EF_j110_a4tchad_xe70_tclcw_veryloose() = parent.EF_j110_a4tchad_xe70_tclcw_veryloose();
      } else {
         EF_j110_a4tchad_xe70_tclcw_veryloose() = 0;
      }
      if( parent.EF_j110_a4tchad_xe75_tclcw.IsAvailable() ) {
         EF_j110_a4tchad_xe75_tclcw() = parent.EF_j110_a4tchad_xe75_tclcw();
      } else {
         EF_j110_a4tchad_xe75_tclcw() = 0;
      }
      if( parent.EF_j110_a4tchad_xe80_tclcw_loose.IsAvailable() ) {
         EF_j110_a4tchad_xe80_tclcw_loose() = parent.EF_j110_a4tchad_xe80_tclcw_loose();
      } else {
         EF_j110_a4tchad_xe80_tclcw_loose() = 0;
      }
      if( parent.EF_j110_a4tchad_xe90_tclcw_loose.IsAvailable() ) {
         EF_j110_a4tchad_xe90_tclcw_loose() = parent.EF_j110_a4tchad_xe90_tclcw_loose();
      } else {
         EF_j110_a4tchad_xe90_tclcw_loose() = 0;
      }
      if( parent.EF_j110_a4tchad_xe90_tclcw_veryloose.IsAvailable() ) {
         EF_j110_a4tchad_xe90_tclcw_veryloose() = parent.EF_j110_a4tchad_xe90_tclcw_veryloose();
      } else {
         EF_j110_a4tchad_xe90_tclcw_veryloose() = 0;
      }
      if( parent.EF_j110_a4tclcw_xe100_tclcw_veryloose.IsAvailable() ) {
         EF_j110_a4tclcw_xe100_tclcw_veryloose() = parent.EF_j110_a4tclcw_xe100_tclcw_veryloose();
      } else {
         EF_j110_a4tclcw_xe100_tclcw_veryloose() = 0;
      }
      if( parent.EF_j145_2j45_a4tchad_L2EFxe70_tclcw.IsAvailable() ) {
         EF_j145_2j45_a4tchad_L2EFxe70_tclcw() = parent.EF_j145_2j45_a4tchad_L2EFxe70_tclcw();
      } else {
         EF_j145_2j45_a4tchad_L2EFxe70_tclcw() = 0;
      }
      if( parent.EF_j145_a10tcem_L2FS.IsAvailable() ) {
         EF_j145_a10tcem_L2FS() = parent.EF_j145_a10tcem_L2FS();
      } else {
         EF_j145_a10tcem_L2FS() = 0;
      }
      if( parent.EF_j145_a10tcem_L2FS_L2xe60_tclcw.IsAvailable() ) {
         EF_j145_a10tcem_L2FS_L2xe60_tclcw() = parent.EF_j145_a10tcem_L2FS_L2xe60_tclcw();
      } else {
         EF_j145_a10tcem_L2FS_L2xe60_tclcw() = 0;
      }
      if( parent.EF_j145_a4tchad.IsAvailable() ) {
         EF_j145_a4tchad() = parent.EF_j145_a4tchad();
      } else {
         EF_j145_a4tchad() = 0;
      }
      if( parent.EF_j145_a4tchad_L2EFxe60_tclcw.IsAvailable() ) {
         EF_j145_a4tchad_L2EFxe60_tclcw() = parent.EF_j145_a4tchad_L2EFxe60_tclcw();
      } else {
         EF_j145_a4tchad_L2EFxe60_tclcw() = 0;
      }
      if( parent.EF_j145_a4tchad_L2EFxe70_tclcw.IsAvailable() ) {
         EF_j145_a4tchad_L2EFxe70_tclcw() = parent.EF_j145_a4tchad_L2EFxe70_tclcw();
      } else {
         EF_j145_a4tchad_L2EFxe70_tclcw() = 0;
      }
      if( parent.EF_j145_a4tchad_L2EFxe80_tclcw.IsAvailable() ) {
         EF_j145_a4tchad_L2EFxe80_tclcw() = parent.EF_j145_a4tchad_L2EFxe80_tclcw();
      } else {
         EF_j145_a4tchad_L2EFxe80_tclcw() = 0;
      }
      if( parent.EF_j145_a4tchad_L2EFxe90_tclcw.IsAvailable() ) {
         EF_j145_a4tchad_L2EFxe90_tclcw() = parent.EF_j145_a4tchad_L2EFxe90_tclcw();
      } else {
         EF_j145_a4tchad_L2EFxe90_tclcw() = 0;
      }
      if( parent.EF_j145_a4tchad_ht500_L2FS.IsAvailable() ) {
         EF_j145_a4tchad_ht500_L2FS() = parent.EF_j145_a4tchad_ht500_L2FS();
      } else {
         EF_j145_a4tchad_ht500_L2FS() = 0;
      }
      if( parent.EF_j145_a4tchad_ht600_L2FS.IsAvailable() ) {
         EF_j145_a4tchad_ht600_L2FS() = parent.EF_j145_a4tchad_ht600_L2FS();
      } else {
         EF_j145_a4tchad_ht600_L2FS() = 0;
      }
      if( parent.EF_j145_a4tchad_ht700_L2FS.IsAvailable() ) {
         EF_j145_a4tchad_ht700_L2FS() = parent.EF_j145_a4tchad_ht700_L2FS();
      } else {
         EF_j145_a4tchad_ht700_L2FS() = 0;
      }
      if( parent.EF_j145_a4tclcw_L2EFxe90_tclcw.IsAvailable() ) {
         EF_j145_a4tclcw_L2EFxe90_tclcw() = parent.EF_j145_a4tclcw_L2EFxe90_tclcw();
      } else {
         EF_j145_a4tclcw_L2EFxe90_tclcw() = 0;
      }
      if( parent.EF_j145_j100_j35_a4tchad.IsAvailable() ) {
         EF_j145_j100_j35_a4tchad() = parent.EF_j145_j100_j35_a4tchad();
      } else {
         EF_j145_j100_j35_a4tchad() = 0;
      }
      if( parent.EF_j15_a4tchad.IsAvailable() ) {
         EF_j15_a4tchad() = parent.EF_j15_a4tchad();
      } else {
         EF_j15_a4tchad() = 0;
      }
      if( parent.EF_j15_a4tchad_L1MBTS.IsAvailable() ) {
         EF_j15_a4tchad_L1MBTS() = parent.EF_j15_a4tchad_L1MBTS();
      } else {
         EF_j15_a4tchad_L1MBTS() = 0;
      }
      if( parent.EF_j15_a4tchad_L1TE20.IsAvailable() ) {
         EF_j15_a4tchad_L1TE20() = parent.EF_j15_a4tchad_L1TE20();
      } else {
         EF_j15_a4tchad_L1TE20() = 0;
      }
      if( parent.EF_j15_fj15_a4tchad_deta50_FC_L1MBTS.IsAvailable() ) {
         EF_j15_fj15_a4tchad_deta50_FC_L1MBTS() = parent.EF_j15_fj15_a4tchad_deta50_FC_L1MBTS();
      } else {
         EF_j15_fj15_a4tchad_deta50_FC_L1MBTS() = 0;
      }
      if( parent.EF_j15_fj15_a4tchad_deta50_FC_L1TE20.IsAvailable() ) {
         EF_j15_fj15_a4tchad_deta50_FC_L1TE20() = parent.EF_j15_fj15_a4tchad_deta50_FC_L1TE20();
      } else {
         EF_j15_fj15_a4tchad_deta50_FC_L1TE20() = 0;
      }
      if( parent.EF_j165_u0uchad_LArNoiseBurst.IsAvailable() ) {
         EF_j165_u0uchad_LArNoiseBurst() = parent.EF_j165_u0uchad_LArNoiseBurst();
      } else {
         EF_j165_u0uchad_LArNoiseBurst() = 0;
      }
      if( parent.EF_j170_a4tchad_EFxe50_tclcw.IsAvailable() ) {
         EF_j170_a4tchad_EFxe50_tclcw() = parent.EF_j170_a4tchad_EFxe50_tclcw();
      } else {
         EF_j170_a4tchad_EFxe50_tclcw() = 0;
      }
      if( parent.EF_j170_a4tchad_EFxe60_tclcw.IsAvailable() ) {
         EF_j170_a4tchad_EFxe60_tclcw() = parent.EF_j170_a4tchad_EFxe60_tclcw();
      } else {
         EF_j170_a4tchad_EFxe60_tclcw() = 0;
      }
      if( parent.EF_j170_a4tchad_EFxe70_tclcw.IsAvailable() ) {
         EF_j170_a4tchad_EFxe70_tclcw() = parent.EF_j170_a4tchad_EFxe70_tclcw();
      } else {
         EF_j170_a4tchad_EFxe70_tclcw() = 0;
      }
      if( parent.EF_j170_a4tchad_EFxe80_tclcw.IsAvailable() ) {
         EF_j170_a4tchad_EFxe80_tclcw() = parent.EF_j170_a4tchad_EFxe80_tclcw();
      } else {
         EF_j170_a4tchad_EFxe80_tclcw() = 0;
      }
      if( parent.EF_j170_a4tchad_ht500.IsAvailable() ) {
         EF_j170_a4tchad_ht500() = parent.EF_j170_a4tchad_ht500();
      } else {
         EF_j170_a4tchad_ht500() = 0;
      }
      if( parent.EF_j170_a4tchad_ht600.IsAvailable() ) {
         EF_j170_a4tchad_ht600() = parent.EF_j170_a4tchad_ht600();
      } else {
         EF_j170_a4tchad_ht600() = 0;
      }
      if( parent.EF_j170_a4tchad_ht700.IsAvailable() ) {
         EF_j170_a4tchad_ht700() = parent.EF_j170_a4tchad_ht700();
      } else {
         EF_j170_a4tchad_ht700() = 0;
      }
      if( parent.EF_j180_a10tcem.IsAvailable() ) {
         EF_j180_a10tcem() = parent.EF_j180_a10tcem();
      } else {
         EF_j180_a10tcem() = 0;
      }
      if( parent.EF_j180_a10tcem_EFxe50_tclcw.IsAvailable() ) {
         EF_j180_a10tcem_EFxe50_tclcw() = parent.EF_j180_a10tcem_EFxe50_tclcw();
      } else {
         EF_j180_a10tcem_EFxe50_tclcw() = 0;
      }
      if( parent.EF_j180_a10tcem_e45_loose1.IsAvailable() ) {
         EF_j180_a10tcem_e45_loose1() = parent.EF_j180_a10tcem_e45_loose1();
      } else {
         EF_j180_a10tcem_e45_loose1() = 0;
      }
      if( parent.EF_j180_a10tclcw_EFxe50_tclcw.IsAvailable() ) {
         EF_j180_a10tclcw_EFxe50_tclcw() = parent.EF_j180_a10tclcw_EFxe50_tclcw();
      } else {
         EF_j180_a10tclcw_EFxe50_tclcw() = 0;
      }
      if( parent.EF_j180_a4tchad.IsAvailable() ) {
         EF_j180_a4tchad() = parent.EF_j180_a4tchad();
      } else {
         EF_j180_a4tchad() = 0;
      }
      if( parent.EF_j180_a4tclcw.IsAvailable() ) {
         EF_j180_a4tclcw() = parent.EF_j180_a4tclcw();
      } else {
         EF_j180_a4tclcw() = 0;
      }
      if( parent.EF_j180_a4tthad.IsAvailable() ) {
         EF_j180_a4tthad() = parent.EF_j180_a4tthad();
      } else {
         EF_j180_a4tthad() = 0;
      }
      if( parent.EF_j220_a10tcem_e45_etcut.IsAvailable() ) {
         EF_j220_a10tcem_e45_etcut() = parent.EF_j220_a10tcem_e45_etcut();
      } else {
         EF_j220_a10tcem_e45_etcut() = 0;
      }
      if( parent.EF_j220_a10tcem_e45_loose1.IsAvailable() ) {
         EF_j220_a10tcem_e45_loose1() = parent.EF_j220_a10tcem_e45_loose1();
      } else {
         EF_j220_a10tcem_e45_loose1() = 0;
      }
      if( parent.EF_j220_a10tcem_e60_etcut.IsAvailable() ) {
         EF_j220_a10tcem_e60_etcut() = parent.EF_j220_a10tcem_e60_etcut();
      } else {
         EF_j220_a10tcem_e60_etcut() = 0;
      }
      if( parent.EF_j220_a4tchad.IsAvailable() ) {
         EF_j220_a4tchad() = parent.EF_j220_a4tchad();
      } else {
         EF_j220_a4tchad() = 0;
      }
      if( parent.EF_j220_a4tthad.IsAvailable() ) {
         EF_j220_a4tthad() = parent.EF_j220_a4tthad();
      } else {
         EF_j220_a4tthad() = 0;
      }
      if( parent.EF_j240_a10tcem.IsAvailable() ) {
         EF_j240_a10tcem() = parent.EF_j240_a10tcem();
      } else {
         EF_j240_a10tcem() = 0;
      }
      if( parent.EF_j240_a10tcem_e45_etcut.IsAvailable() ) {
         EF_j240_a10tcem_e45_etcut() = parent.EF_j240_a10tcem_e45_etcut();
      } else {
         EF_j240_a10tcem_e45_etcut() = 0;
      }
      if( parent.EF_j240_a10tcem_e45_loose1.IsAvailable() ) {
         EF_j240_a10tcem_e45_loose1() = parent.EF_j240_a10tcem_e45_loose1();
      } else {
         EF_j240_a10tcem_e45_loose1() = 0;
      }
      if( parent.EF_j240_a10tcem_e60_etcut.IsAvailable() ) {
         EF_j240_a10tcem_e60_etcut() = parent.EF_j240_a10tcem_e60_etcut();
      } else {
         EF_j240_a10tcem_e60_etcut() = 0;
      }
      if( parent.EF_j240_a10tcem_e60_loose1.IsAvailable() ) {
         EF_j240_a10tcem_e60_loose1() = parent.EF_j240_a10tcem_e60_loose1();
      } else {
         EF_j240_a10tcem_e60_loose1() = 0;
      }
      if( parent.EF_j240_a10tclcw.IsAvailable() ) {
         EF_j240_a10tclcw() = parent.EF_j240_a10tclcw();
      } else {
         EF_j240_a10tclcw() = 0;
      }
      if( parent.EF_j25_a4tchad.IsAvailable() ) {
         EF_j25_a4tchad() = parent.EF_j25_a4tchad();
      } else {
         EF_j25_a4tchad() = 0;
      }
      if( parent.EF_j25_a4tchad_L1MBTS.IsAvailable() ) {
         EF_j25_a4tchad_L1MBTS() = parent.EF_j25_a4tchad_L1MBTS();
      } else {
         EF_j25_a4tchad_L1MBTS() = 0;
      }
      if( parent.EF_j25_a4tchad_L1TE20.IsAvailable() ) {
         EF_j25_a4tchad_L1TE20() = parent.EF_j25_a4tchad_L1TE20();
      } else {
         EF_j25_a4tchad_L1TE20() = 0;
      }
      if( parent.EF_j25_fj25_a4tchad_deta50_FC_L1MBTS.IsAvailable() ) {
         EF_j25_fj25_a4tchad_deta50_FC_L1MBTS() = parent.EF_j25_fj25_a4tchad_deta50_FC_L1MBTS();
      } else {
         EF_j25_fj25_a4tchad_deta50_FC_L1MBTS() = 0;
      }
      if( parent.EF_j25_fj25_a4tchad_deta50_FC_L1TE20.IsAvailable() ) {
         EF_j25_fj25_a4tchad_deta50_FC_L1TE20() = parent.EF_j25_fj25_a4tchad_deta50_FC_L1TE20();
      } else {
         EF_j25_fj25_a4tchad_deta50_FC_L1TE20() = 0;
      }
      if( parent.EF_j260_a4tthad.IsAvailable() ) {
         EF_j260_a4tthad() = parent.EF_j260_a4tthad();
      } else {
         EF_j260_a4tthad() = 0;
      }
      if( parent.EF_j280_a10tclcw_L2FS.IsAvailable() ) {
         EF_j280_a10tclcw_L2FS() = parent.EF_j280_a10tclcw_L2FS();
      } else {
         EF_j280_a10tclcw_L2FS() = 0;
      }
      if( parent.EF_j280_a4tchad.IsAvailable() ) {
         EF_j280_a4tchad() = parent.EF_j280_a4tchad();
      } else {
         EF_j280_a4tchad() = 0;
      }
      if( parent.EF_j280_a4tchad_mjj2000dy34.IsAvailable() ) {
         EF_j280_a4tchad_mjj2000dy34() = parent.EF_j280_a4tchad_mjj2000dy34();
      } else {
         EF_j280_a4tchad_mjj2000dy34() = 0;
      }
      if( parent.EF_j30_a4tcem_eta13_xe30_empty.IsAvailable() ) {
         EF_j30_a4tcem_eta13_xe30_empty() = parent.EF_j30_a4tcem_eta13_xe30_empty();
      } else {
         EF_j30_a4tcem_eta13_xe30_empty() = 0;
      }
      if( parent.EF_j30_a4tcem_eta13_xe30_firstempty.IsAvailable() ) {
         EF_j30_a4tcem_eta13_xe30_firstempty() = parent.EF_j30_a4tcem_eta13_xe30_firstempty();
      } else {
         EF_j30_a4tcem_eta13_xe30_firstempty() = 0;
      }
      if( parent.EF_j30_u0uchad_empty_LArNoiseBurst.IsAvailable() ) {
         EF_j30_u0uchad_empty_LArNoiseBurst() = parent.EF_j30_u0uchad_empty_LArNoiseBurst();
      } else {
         EF_j30_u0uchad_empty_LArNoiseBurst() = 0;
      }
      if( parent.EF_j35_a10tcem.IsAvailable() ) {
         EF_j35_a10tcem() = parent.EF_j35_a10tcem();
      } else {
         EF_j35_a10tcem() = 0;
      }
      if( parent.EF_j35_a4tcem_L1TAU_LOF_HV.IsAvailable() ) {
         EF_j35_a4tcem_L1TAU_LOF_HV() = parent.EF_j35_a4tcem_L1TAU_LOF_HV();
      } else {
         EF_j35_a4tcem_L1TAU_LOF_HV() = 0;
      }
      if( parent.EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY.IsAvailable() ) {
         EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY() = parent.EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY();
      } else {
         EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY() = 0;
      }
      if( parent.EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO.IsAvailable() ) {
         EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO() = parent.EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO();
      } else {
         EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO() = 0;
      }
      if( parent.EF_j35_a4tchad.IsAvailable() ) {
         EF_j35_a4tchad() = parent.EF_j35_a4tchad();
      } else {
         EF_j35_a4tchad() = 0;
      }
      if( parent.EF_j35_a4tchad_L1MBTS.IsAvailable() ) {
         EF_j35_a4tchad_L1MBTS() = parent.EF_j35_a4tchad_L1MBTS();
      } else {
         EF_j35_a4tchad_L1MBTS() = 0;
      }
      if( parent.EF_j35_a4tchad_L1TE20.IsAvailable() ) {
         EF_j35_a4tchad_L1TE20() = parent.EF_j35_a4tchad_L1TE20();
      } else {
         EF_j35_a4tchad_L1TE20() = 0;
      }
      if( parent.EF_j35_a4tclcw.IsAvailable() ) {
         EF_j35_a4tclcw() = parent.EF_j35_a4tclcw();
      } else {
         EF_j35_a4tclcw() = 0;
      }
      if( parent.EF_j35_a4tthad.IsAvailable() ) {
         EF_j35_a4tthad() = parent.EF_j35_a4tthad();
      } else {
         EF_j35_a4tthad() = 0;
      }
      if( parent.EF_j35_fj35_a4tchad_deta50_FC_L1MBTS.IsAvailable() ) {
         EF_j35_fj35_a4tchad_deta50_FC_L1MBTS() = parent.EF_j35_fj35_a4tchad_deta50_FC_L1MBTS();
      } else {
         EF_j35_fj35_a4tchad_deta50_FC_L1MBTS() = 0;
      }
      if( parent.EF_j35_fj35_a4tchad_deta50_FC_L1TE20.IsAvailable() ) {
         EF_j35_fj35_a4tchad_deta50_FC_L1TE20() = parent.EF_j35_fj35_a4tchad_deta50_FC_L1TE20();
      } else {
         EF_j35_fj35_a4tchad_deta50_FC_L1TE20() = 0;
      }
      if( parent.EF_j360_a10tcem.IsAvailable() ) {
         EF_j360_a10tcem() = parent.EF_j360_a10tcem();
      } else {
         EF_j360_a10tcem() = 0;
      }
      if( parent.EF_j360_a10tclcw.IsAvailable() ) {
         EF_j360_a10tclcw() = parent.EF_j360_a10tclcw();
      } else {
         EF_j360_a10tclcw() = 0;
      }
      if( parent.EF_j360_a4tchad.IsAvailable() ) {
         EF_j360_a4tchad() = parent.EF_j360_a4tchad();
      } else {
         EF_j360_a4tchad() = 0;
      }
      if( parent.EF_j360_a4tclcw.IsAvailable() ) {
         EF_j360_a4tclcw() = parent.EF_j360_a4tclcw();
      } else {
         EF_j360_a4tclcw() = 0;
      }
      if( parent.EF_j360_a4tthad.IsAvailable() ) {
         EF_j360_a4tthad() = parent.EF_j360_a4tthad();
      } else {
         EF_j360_a4tthad() = 0;
      }
      if( parent.EF_j380_a4tthad.IsAvailable() ) {
         EF_j380_a4tthad() = parent.EF_j380_a4tthad();
      } else {
         EF_j380_a4tthad() = 0;
      }
      if( parent.EF_j45_a10tcem_L1RD0.IsAvailable() ) {
         EF_j45_a10tcem_L1RD0() = parent.EF_j45_a10tcem_L1RD0();
      } else {
         EF_j45_a10tcem_L1RD0() = 0;
      }
      if( parent.EF_j45_a4tchad.IsAvailable() ) {
         EF_j45_a4tchad() = parent.EF_j45_a4tchad();
      } else {
         EF_j45_a4tchad() = 0;
      }
      if( parent.EF_j45_a4tchad_L1RD0.IsAvailable() ) {
         EF_j45_a4tchad_L1RD0() = parent.EF_j45_a4tchad_L1RD0();
      } else {
         EF_j45_a4tchad_L1RD0() = 0;
      }
      if( parent.EF_j45_a4tchad_L2FS.IsAvailable() ) {
         EF_j45_a4tchad_L2FS() = parent.EF_j45_a4tchad_L2FS();
      } else {
         EF_j45_a4tchad_L2FS() = 0;
      }
      if( parent.EF_j45_a4tchad_L2FS_L1RD0.IsAvailable() ) {
         EF_j45_a4tchad_L2FS_L1RD0() = parent.EF_j45_a4tchad_L2FS_L1RD0();
      } else {
         EF_j45_a4tchad_L2FS_L1RD0() = 0;
      }
      if( parent.EF_j460_a10tcem.IsAvailable() ) {
         EF_j460_a10tcem() = parent.EF_j460_a10tcem();
      } else {
         EF_j460_a10tcem() = 0;
      }
      if( parent.EF_j460_a10tclcw.IsAvailable() ) {
         EF_j460_a10tclcw() = parent.EF_j460_a10tclcw();
      } else {
         EF_j460_a10tclcw() = 0;
      }
      if( parent.EF_j460_a4tchad.IsAvailable() ) {
         EF_j460_a4tchad() = parent.EF_j460_a4tchad();
      } else {
         EF_j460_a4tchad() = 0;
      }
      if( parent.EF_j50_a4tcem_eta13_xe50_empty.IsAvailable() ) {
         EF_j50_a4tcem_eta13_xe50_empty() = parent.EF_j50_a4tcem_eta13_xe50_empty();
      } else {
         EF_j50_a4tcem_eta13_xe50_empty() = 0;
      }
      if( parent.EF_j50_a4tcem_eta13_xe50_firstempty.IsAvailable() ) {
         EF_j50_a4tcem_eta13_xe50_firstempty() = parent.EF_j50_a4tcem_eta13_xe50_firstempty();
      } else {
         EF_j50_a4tcem_eta13_xe50_firstempty() = 0;
      }
      if( parent.EF_j50_a4tcem_eta25_xe50_empty.IsAvailable() ) {
         EF_j50_a4tcem_eta25_xe50_empty() = parent.EF_j50_a4tcem_eta25_xe50_empty();
      } else {
         EF_j50_a4tcem_eta25_xe50_empty() = 0;
      }
      if( parent.EF_j50_a4tcem_eta25_xe50_firstempty.IsAvailable() ) {
         EF_j50_a4tcem_eta25_xe50_firstempty() = parent.EF_j50_a4tcem_eta25_xe50_firstempty();
      } else {
         EF_j50_a4tcem_eta25_xe50_firstempty() = 0;
      }
      if( parent.EF_j55_a4tchad.IsAvailable() ) {
         EF_j55_a4tchad() = parent.EF_j55_a4tchad();
      } else {
         EF_j55_a4tchad() = 0;
      }
      if( parent.EF_j55_a4tchad_L2FS.IsAvailable() ) {
         EF_j55_a4tchad_L2FS() = parent.EF_j55_a4tchad_L2FS();
      } else {
         EF_j55_a4tchad_L2FS() = 0;
      }
      if( parent.EF_j55_a4tclcw.IsAvailable() ) {
         EF_j55_a4tclcw() = parent.EF_j55_a4tclcw();
      } else {
         EF_j55_a4tclcw() = 0;
      }
      if( parent.EF_j55_u0uchad_firstempty_LArNoiseBurst.IsAvailable() ) {
         EF_j55_u0uchad_firstempty_LArNoiseBurst() = parent.EF_j55_u0uchad_firstempty_LArNoiseBurst();
      } else {
         EF_j55_u0uchad_firstempty_LArNoiseBurst() = 0;
      }
      if( parent.EF_j65_a4tchad_L2FS.IsAvailable() ) {
         EF_j65_a4tchad_L2FS() = parent.EF_j65_a4tchad_L2FS();
      } else {
         EF_j65_a4tchad_L2FS() = 0;
      }
      if( parent.EF_j80_a10tcem_L2FS.IsAvailable() ) {
         EF_j80_a10tcem_L2FS() = parent.EF_j80_a10tcem_L2FS();
      } else {
         EF_j80_a10tcem_L2FS() = 0;
      }
      if( parent.EF_j80_a4tchad.IsAvailable() ) {
         EF_j80_a4tchad() = parent.EF_j80_a4tchad();
      } else {
         EF_j80_a4tchad() = 0;
      }
      if( parent.EF_j80_a4tchad_xe100_tclcw_loose.IsAvailable() ) {
         EF_j80_a4tchad_xe100_tclcw_loose() = parent.EF_j80_a4tchad_xe100_tclcw_loose();
      } else {
         EF_j80_a4tchad_xe100_tclcw_loose() = 0;
      }
      if( parent.EF_j80_a4tchad_xe100_tclcw_veryloose.IsAvailable() ) {
         EF_j80_a4tchad_xe100_tclcw_veryloose() = parent.EF_j80_a4tchad_xe100_tclcw_veryloose();
      } else {
         EF_j80_a4tchad_xe100_tclcw_veryloose() = 0;
      }
      if( parent.EF_j80_a4tchad_xe55_tclcw.IsAvailable() ) {
         EF_j80_a4tchad_xe55_tclcw() = parent.EF_j80_a4tchad_xe55_tclcw();
      } else {
         EF_j80_a4tchad_xe55_tclcw() = 0;
      }
      if( parent.EF_j80_a4tchad_xe60_tclcw.IsAvailable() ) {
         EF_j80_a4tchad_xe60_tclcw() = parent.EF_j80_a4tchad_xe60_tclcw();
      } else {
         EF_j80_a4tchad_xe60_tclcw() = 0;
      }
      if( parent.EF_j80_a4tchad_xe70_tclcw.IsAvailable() ) {
         EF_j80_a4tchad_xe70_tclcw() = parent.EF_j80_a4tchad_xe70_tclcw();
      } else {
         EF_j80_a4tchad_xe70_tclcw() = 0;
      }
      if( parent.EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10.IsAvailable() ) {
         EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10() = parent.EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10();
      } else {
         EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10() = 0;
      }
      if( parent.EF_j80_a4tchad_xe70_tclcw_loose.IsAvailable() ) {
         EF_j80_a4tchad_xe70_tclcw_loose() = parent.EF_j80_a4tchad_xe70_tclcw_loose();
      } else {
         EF_j80_a4tchad_xe70_tclcw_loose() = 0;
      }
      if( parent.EF_j80_a4tchad_xe80_tclcw_loose.IsAvailable() ) {
         EF_j80_a4tchad_xe80_tclcw_loose() = parent.EF_j80_a4tchad_xe80_tclcw_loose();
      } else {
         EF_j80_a4tchad_xe80_tclcw_loose() = 0;
      }
      if( parent.EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10.IsAvailable() ) {
         EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10() = parent.EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10();
      } else {
         EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10() = 0;
      }
      if( parent.EF_mu10.IsAvailable() ) {
         EF_mu10() = parent.EF_mu10();
      } else {
         EF_mu10() = 0;
      }
      if( parent.EF_mu10_Jpsimumu.IsAvailable() ) {
         EF_mu10_Jpsimumu() = parent.EF_mu10_Jpsimumu();
      } else {
         EF_mu10_Jpsimumu() = 0;
      }
      if( parent.EF_mu10_MSonly.IsAvailable() ) {
         EF_mu10_MSonly() = parent.EF_mu10_MSonly();
      } else {
         EF_mu10_MSonly() = 0;
      }
      if( parent.EF_mu10_Upsimumu_tight_FS.IsAvailable() ) {
         EF_mu10_Upsimumu_tight_FS() = parent.EF_mu10_Upsimumu_tight_FS();
      } else {
         EF_mu10_Upsimumu_tight_FS() = 0;
      }
      if( parent.EF_mu10i_g10_loose.IsAvailable() ) {
         EF_mu10i_g10_loose() = parent.EF_mu10i_g10_loose();
      } else {
         EF_mu10i_g10_loose() = 0;
      }
      if( parent.EF_mu10i_g10_loose_TauMass.IsAvailable() ) {
         EF_mu10i_g10_loose_TauMass() = parent.EF_mu10i_g10_loose_TauMass();
      } else {
         EF_mu10i_g10_loose_TauMass() = 0;
      }
      if( parent.EF_mu10i_g10_medium.IsAvailable() ) {
         EF_mu10i_g10_medium() = parent.EF_mu10i_g10_medium();
      } else {
         EF_mu10i_g10_medium() = 0;
      }
      if( parent.EF_mu10i_g10_medium_TauMass.IsAvailable() ) {
         EF_mu10i_g10_medium_TauMass() = parent.EF_mu10i_g10_medium_TauMass();
      } else {
         EF_mu10i_g10_medium_TauMass() = 0;
      }
      if( parent.EF_mu10i_loose_g12Tvh_loose.IsAvailable() ) {
         EF_mu10i_loose_g12Tvh_loose() = parent.EF_mu10i_loose_g12Tvh_loose();
      } else {
         EF_mu10i_loose_g12Tvh_loose() = 0;
      }
      if( parent.EF_mu10i_loose_g12Tvh_loose_TauMass.IsAvailable() ) {
         EF_mu10i_loose_g12Tvh_loose_TauMass() = parent.EF_mu10i_loose_g12Tvh_loose_TauMass();
      } else {
         EF_mu10i_loose_g12Tvh_loose_TauMass() = 0;
      }
      if( parent.EF_mu10i_loose_g12Tvh_medium.IsAvailable() ) {
         EF_mu10i_loose_g12Tvh_medium() = parent.EF_mu10i_loose_g12Tvh_medium();
      } else {
         EF_mu10i_loose_g12Tvh_medium() = 0;
      }
      if( parent.EF_mu10i_loose_g12Tvh_medium_TauMass.IsAvailable() ) {
         EF_mu10i_loose_g12Tvh_medium_TauMass() = parent.EF_mu10i_loose_g12Tvh_medium_TauMass();
      } else {
         EF_mu10i_loose_g12Tvh_medium_TauMass() = 0;
      }
      if( parent.EF_mu11_empty_NoAlg.IsAvailable() ) {
         EF_mu11_empty_NoAlg() = parent.EF_mu11_empty_NoAlg();
      } else {
         EF_mu11_empty_NoAlg() = 0;
      }
      if( parent.EF_mu13.IsAvailable() ) {
         EF_mu13() = parent.EF_mu13();
      } else {
         EF_mu13() = 0;
      }
      if( parent.EF_mu15.IsAvailable() ) {
         EF_mu15() = parent.EF_mu15();
      } else {
         EF_mu15() = 0;
      }
      if( parent.EF_mu18.IsAvailable() ) {
         EF_mu18() = parent.EF_mu18();
      } else {
         EF_mu18() = 0;
      }
      if( parent.EF_mu18_2g10_loose.IsAvailable() ) {
         EF_mu18_2g10_loose() = parent.EF_mu18_2g10_loose();
      } else {
         EF_mu18_2g10_loose() = 0;
      }
      if( parent.EF_mu18_2g10_medium.IsAvailable() ) {
         EF_mu18_2g10_medium() = parent.EF_mu18_2g10_medium();
      } else {
         EF_mu18_2g10_medium() = 0;
      }
      if( parent.EF_mu18_2g15_loose.IsAvailable() ) {
         EF_mu18_2g15_loose() = parent.EF_mu18_2g15_loose();
      } else {
         EF_mu18_2g15_loose() = 0;
      }
      if( parent.EF_mu18_IDTrkNoCut_tight.IsAvailable() ) {
         EF_mu18_IDTrkNoCut_tight() = parent.EF_mu18_IDTrkNoCut_tight();
      } else {
         EF_mu18_IDTrkNoCut_tight() = 0;
      }
      if( parent.EF_mu18_g20vh_loose.IsAvailable() ) {
         EF_mu18_g20vh_loose() = parent.EF_mu18_g20vh_loose();
      } else {
         EF_mu18_g20vh_loose() = 0;
      }
      if( parent.EF_mu18_medium.IsAvailable() ) {
         EF_mu18_medium() = parent.EF_mu18_medium();
      } else {
         EF_mu18_medium() = 0;
      }
      if( parent.EF_mu18_tight.IsAvailable() ) {
         EF_mu18_tight() = parent.EF_mu18_tight();
      } else {
         EF_mu18_tight() = 0;
      }
      if( parent.EF_mu18_tight_2mu4_EFFS.IsAvailable() ) {
         EF_mu18_tight_2mu4_EFFS() = parent.EF_mu18_tight_2mu4_EFFS();
      } else {
         EF_mu18_tight_2mu4_EFFS() = 0;
      }
      if( parent.EF_mu18_tight_e7_medium1.IsAvailable() ) {
         EF_mu18_tight_e7_medium1() = parent.EF_mu18_tight_e7_medium1();
      } else {
         EF_mu18_tight_e7_medium1() = 0;
      }
      if( parent.EF_mu18_tight_mu8_EFFS.IsAvailable() ) {
         EF_mu18_tight_mu8_EFFS() = parent.EF_mu18_tight_mu8_EFFS();
      } else {
         EF_mu18_tight_mu8_EFFS() = 0;
      }
      if( parent.EF_mu18i4_tight.IsAvailable() ) {
         EF_mu18i4_tight() = parent.EF_mu18i4_tight();
      } else {
         EF_mu18i4_tight() = 0;
      }
      if( parent.EF_mu18it_tight.IsAvailable() ) {
         EF_mu18it_tight() = parent.EF_mu18it_tight();
      } else {
         EF_mu18it_tight() = 0;
      }
      if( parent.EF_mu20i_tight_g5_loose.IsAvailable() ) {
         EF_mu20i_tight_g5_loose() = parent.EF_mu20i_tight_g5_loose();
      } else {
         EF_mu20i_tight_g5_loose() = 0;
      }
      if( parent.EF_mu20i_tight_g5_loose_TauMass.IsAvailable() ) {
         EF_mu20i_tight_g5_loose_TauMass() = parent.EF_mu20i_tight_g5_loose_TauMass();
      } else {
         EF_mu20i_tight_g5_loose_TauMass() = 0;
      }
      if( parent.EF_mu20i_tight_g5_medium.IsAvailable() ) {
         EF_mu20i_tight_g5_medium() = parent.EF_mu20i_tight_g5_medium();
      } else {
         EF_mu20i_tight_g5_medium() = 0;
      }
      if( parent.EF_mu20i_tight_g5_medium_TauMass.IsAvailable() ) {
         EF_mu20i_tight_g5_medium_TauMass() = parent.EF_mu20i_tight_g5_medium_TauMass();
      } else {
         EF_mu20i_tight_g5_medium_TauMass() = 0;
      }
      if( parent.EF_mu20it_tight.IsAvailable() ) {
         EF_mu20it_tight() = parent.EF_mu20it_tight();
      } else {
         EF_mu20it_tight() = 0;
      }
      if( parent.EF_mu22_IDTrkNoCut_tight.IsAvailable() ) {
         EF_mu22_IDTrkNoCut_tight() = parent.EF_mu22_IDTrkNoCut_tight();
      } else {
         EF_mu22_IDTrkNoCut_tight() = 0;
      }
      if( parent.EF_mu24.IsAvailable() ) {
         EF_mu24() = parent.EF_mu24();
      } else {
         EF_mu24() = 0;
      }
      if( parent.EF_mu24_g20vh_loose.IsAvailable() ) {
         EF_mu24_g20vh_loose() = parent.EF_mu24_g20vh_loose();
      } else {
         EF_mu24_g20vh_loose() = 0;
      }
      if( parent.EF_mu24_g20vh_medium.IsAvailable() ) {
         EF_mu24_g20vh_medium() = parent.EF_mu24_g20vh_medium();
      } else {
         EF_mu24_g20vh_medium() = 0;
      }
      if( parent.EF_mu24_j65_a4tchad.IsAvailable() ) {
         EF_mu24_j65_a4tchad() = parent.EF_mu24_j65_a4tchad();
      } else {
         EF_mu24_j65_a4tchad() = 0;
      }
      if( parent.EF_mu24_j65_a4tchad_EFxe40.IsAvailable() ) {
         EF_mu24_j65_a4tchad_EFxe40() = parent.EF_mu24_j65_a4tchad_EFxe40();
      } else {
         EF_mu24_j65_a4tchad_EFxe40() = 0;
      }
      if( parent.EF_mu24_j65_a4tchad_EFxe40_tclcw.IsAvailable() ) {
         EF_mu24_j65_a4tchad_EFxe40_tclcw() = parent.EF_mu24_j65_a4tchad_EFxe40_tclcw();
      } else {
         EF_mu24_j65_a4tchad_EFxe40_tclcw() = 0;
      }
      if( parent.EF_mu24_j65_a4tchad_EFxe50_tclcw.IsAvailable() ) {
         EF_mu24_j65_a4tchad_EFxe50_tclcw() = parent.EF_mu24_j65_a4tchad_EFxe50_tclcw();
      } else {
         EF_mu24_j65_a4tchad_EFxe50_tclcw() = 0;
      }
      if( parent.EF_mu24_j65_a4tchad_EFxe60_tclcw.IsAvailable() ) {
         EF_mu24_j65_a4tchad_EFxe60_tclcw() = parent.EF_mu24_j65_a4tchad_EFxe60_tclcw();
      } else {
         EF_mu24_j65_a4tchad_EFxe60_tclcw() = 0;
      }
      if( parent.EF_mu24_medium.IsAvailable() ) {
         EF_mu24_medium() = parent.EF_mu24_medium();
      } else {
         EF_mu24_medium() = 0;
      }
      if( parent.EF_mu24_muCombTag_NoEF_tight.IsAvailable() ) {
         EF_mu24_muCombTag_NoEF_tight() = parent.EF_mu24_muCombTag_NoEF_tight();
      } else {
         EF_mu24_muCombTag_NoEF_tight() = 0;
      }
      if( parent.EF_mu24_tight.IsAvailable() ) {
         EF_mu24_tight() = parent.EF_mu24_tight();
      } else {
         EF_mu24_tight() = 0;
      }
      if( parent.EF_mu24_tight_2j35_a4tchad.IsAvailable() ) {
         EF_mu24_tight_2j35_a4tchad() = parent.EF_mu24_tight_2j35_a4tchad();
      } else {
         EF_mu24_tight_2j35_a4tchad() = 0;
      }
      if( parent.EF_mu24_tight_3j35_a4tchad.IsAvailable() ) {
         EF_mu24_tight_3j35_a4tchad() = parent.EF_mu24_tight_3j35_a4tchad();
      } else {
         EF_mu24_tight_3j35_a4tchad() = 0;
      }
      if( parent.EF_mu24_tight_4j35_a4tchad.IsAvailable() ) {
         EF_mu24_tight_4j35_a4tchad() = parent.EF_mu24_tight_4j35_a4tchad();
      } else {
         EF_mu24_tight_4j35_a4tchad() = 0;
      }
      if( parent.EF_mu24_tight_EFxe40.IsAvailable() ) {
         EF_mu24_tight_EFxe40() = parent.EF_mu24_tight_EFxe40();
      } else {
         EF_mu24_tight_EFxe40() = 0;
      }
      if( parent.EF_mu24_tight_L2StarB.IsAvailable() ) {
         EF_mu24_tight_L2StarB() = parent.EF_mu24_tight_L2StarB();
      } else {
         EF_mu24_tight_L2StarB() = 0;
      }
      if( parent.EF_mu24_tight_L2StarC.IsAvailable() ) {
         EF_mu24_tight_L2StarC() = parent.EF_mu24_tight_L2StarC();
      } else {
         EF_mu24_tight_L2StarC() = 0;
      }
      if( parent.EF_mu24_tight_MG.IsAvailable() ) {
         EF_mu24_tight_MG() = parent.EF_mu24_tight_MG();
      } else {
         EF_mu24_tight_MG() = 0;
      }
      if( parent.EF_mu24_tight_MuonEF.IsAvailable() ) {
         EF_mu24_tight_MuonEF() = parent.EF_mu24_tight_MuonEF();
      } else {
         EF_mu24_tight_MuonEF() = 0;
      }
      if( parent.EF_mu24_tight_b35_mediumEF_j35_a4tchad.IsAvailable() ) {
         EF_mu24_tight_b35_mediumEF_j35_a4tchad() = parent.EF_mu24_tight_b35_mediumEF_j35_a4tchad();
      } else {
         EF_mu24_tight_b35_mediumEF_j35_a4tchad() = 0;
      }
      if( parent.EF_mu24_tight_mu6_EFFS.IsAvailable() ) {
         EF_mu24_tight_mu6_EFFS() = parent.EF_mu24_tight_mu6_EFFS();
      } else {
         EF_mu24_tight_mu6_EFFS() = 0;
      }
      if( parent.EF_mu24i_tight.IsAvailable() ) {
         EF_mu24i_tight() = parent.EF_mu24i_tight();
      } else {
         EF_mu24i_tight() = 0;
      }
      if( parent.EF_mu24i_tight_MG.IsAvailable() ) {
         EF_mu24i_tight_MG() = parent.EF_mu24i_tight_MG();
      } else {
         EF_mu24i_tight_MG() = 0;
      }
      if( parent.EF_mu24i_tight_MuonEF.IsAvailable() ) {
         EF_mu24i_tight_MuonEF() = parent.EF_mu24i_tight_MuonEF();
      } else {
         EF_mu24i_tight_MuonEF() = 0;
      }
      if( parent.EF_mu24i_tight_l2muonSA.IsAvailable() ) {
         EF_mu24i_tight_l2muonSA() = parent.EF_mu24i_tight_l2muonSA();
      } else {
         EF_mu24i_tight_l2muonSA() = 0;
      }
      if( parent.EF_mu36_tight.IsAvailable() ) {
         EF_mu36_tight() = parent.EF_mu36_tight();
      } else {
         EF_mu36_tight() = 0;
      }
      if( parent.EF_mu40_MSonly_barrel_tight.IsAvailable() ) {
         EF_mu40_MSonly_barrel_tight() = parent.EF_mu40_MSonly_barrel_tight();
      } else {
         EF_mu40_MSonly_barrel_tight() = 0;
      }
      if( parent.EF_mu40_muCombTag_NoEF.IsAvailable() ) {
         EF_mu40_muCombTag_NoEF() = parent.EF_mu40_muCombTag_NoEF();
      } else {
         EF_mu40_muCombTag_NoEF() = 0;
      }
      if( parent.EF_mu40_slow_outOfTime_tight.IsAvailable() ) {
         EF_mu40_slow_outOfTime_tight() = parent.EF_mu40_slow_outOfTime_tight();
      } else {
         EF_mu40_slow_outOfTime_tight() = 0;
      }
      if( parent.EF_mu40_slow_tight.IsAvailable() ) {
         EF_mu40_slow_tight() = parent.EF_mu40_slow_tight();
      } else {
         EF_mu40_slow_tight() = 0;
      }
      if( parent.EF_mu40_tight.IsAvailable() ) {
         EF_mu40_tight() = parent.EF_mu40_tight();
      } else {
         EF_mu40_tight() = 0;
      }
      if( parent.EF_mu4T.IsAvailable() ) {
         EF_mu4T() = parent.EF_mu4T();
      } else {
         EF_mu4T() = 0;
      }
      if( parent.EF_mu4T_Trk_Jpsi.IsAvailable() ) {
         EF_mu4T_Trk_Jpsi() = parent.EF_mu4T_Trk_Jpsi();
      } else {
         EF_mu4T_Trk_Jpsi() = 0;
      }
      if( parent.EF_mu4T_cosmic.IsAvailable() ) {
         EF_mu4T_cosmic() = parent.EF_mu4T_cosmic();
      } else {
         EF_mu4T_cosmic() = 0;
      }
      if( parent.EF_mu4T_j110_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j110_a4tchad_L2FS_matched() = parent.EF_mu4T_j110_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j110_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j110_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j110_a4tchad_matched() = parent.EF_mu4T_j110_a4tchad_matched();
      } else {
         EF_mu4T_j110_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j145_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j145_a4tchad_L2FS_matched() = parent.EF_mu4T_j145_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j145_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j145_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j145_a4tchad_matched() = parent.EF_mu4T_j145_a4tchad_matched();
      } else {
         EF_mu4T_j145_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j15_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j15_a4tchad_matched() = parent.EF_mu4T_j15_a4tchad_matched();
      } else {
         EF_mu4T_j15_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j15_a4tchad_matchedZ.IsAvailable() ) {
         EF_mu4T_j15_a4tchad_matchedZ() = parent.EF_mu4T_j15_a4tchad_matchedZ();
      } else {
         EF_mu4T_j15_a4tchad_matchedZ() = 0;
      }
      if( parent.EF_mu4T_j180_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j180_a4tchad_L2FS_matched() = parent.EF_mu4T_j180_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j180_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j180_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j180_a4tchad_matched() = parent.EF_mu4T_j180_a4tchad_matched();
      } else {
         EF_mu4T_j180_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j220_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j220_a4tchad_L2FS_matched() = parent.EF_mu4T_j220_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j220_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j220_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j220_a4tchad_matched() = parent.EF_mu4T_j220_a4tchad_matched();
      } else {
         EF_mu4T_j220_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j25_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j25_a4tchad_matched() = parent.EF_mu4T_j25_a4tchad_matched();
      } else {
         EF_mu4T_j25_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j25_a4tchad_matchedZ.IsAvailable() ) {
         EF_mu4T_j25_a4tchad_matchedZ() = parent.EF_mu4T_j25_a4tchad_matchedZ();
      } else {
         EF_mu4T_j25_a4tchad_matchedZ() = 0;
      }
      if( parent.EF_mu4T_j280_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j280_a4tchad_L2FS_matched() = parent.EF_mu4T_j280_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j280_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j280_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j280_a4tchad_matched() = parent.EF_mu4T_j280_a4tchad_matched();
      } else {
         EF_mu4T_j280_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j35_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j35_a4tchad_matched() = parent.EF_mu4T_j35_a4tchad_matched();
      } else {
         EF_mu4T_j35_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j35_a4tchad_matchedZ.IsAvailable() ) {
         EF_mu4T_j35_a4tchad_matchedZ() = parent.EF_mu4T_j35_a4tchad_matchedZ();
      } else {
         EF_mu4T_j35_a4tchad_matchedZ() = 0;
      }
      if( parent.EF_mu4T_j360_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j360_a4tchad_L2FS_matched() = parent.EF_mu4T_j360_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j360_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j360_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j360_a4tchad_matched() = parent.EF_mu4T_j360_a4tchad_matched();
      } else {
         EF_mu4T_j360_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j45_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j45_a4tchad_L2FS_matched() = parent.EF_mu4T_j45_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j45_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j45_a4tchad_L2FS_matchedZ.IsAvailable() ) {
         EF_mu4T_j45_a4tchad_L2FS_matchedZ() = parent.EF_mu4T_j45_a4tchad_L2FS_matchedZ();
      } else {
         EF_mu4T_j45_a4tchad_L2FS_matchedZ() = 0;
      }
      if( parent.EF_mu4T_j45_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j45_a4tchad_matched() = parent.EF_mu4T_j45_a4tchad_matched();
      } else {
         EF_mu4T_j45_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j45_a4tchad_matchedZ.IsAvailable() ) {
         EF_mu4T_j45_a4tchad_matchedZ() = parent.EF_mu4T_j45_a4tchad_matchedZ();
      } else {
         EF_mu4T_j45_a4tchad_matchedZ() = 0;
      }
      if( parent.EF_mu4T_j55_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j55_a4tchad_L2FS_matched() = parent.EF_mu4T_j55_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j55_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j55_a4tchad_L2FS_matchedZ.IsAvailable() ) {
         EF_mu4T_j55_a4tchad_L2FS_matchedZ() = parent.EF_mu4T_j55_a4tchad_L2FS_matchedZ();
      } else {
         EF_mu4T_j55_a4tchad_L2FS_matchedZ() = 0;
      }
      if( parent.EF_mu4T_j55_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j55_a4tchad_matched() = parent.EF_mu4T_j55_a4tchad_matched();
      } else {
         EF_mu4T_j55_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j55_a4tchad_matchedZ.IsAvailable() ) {
         EF_mu4T_j55_a4tchad_matchedZ() = parent.EF_mu4T_j55_a4tchad_matchedZ();
      } else {
         EF_mu4T_j55_a4tchad_matchedZ() = 0;
      }
      if( parent.EF_mu4T_j65_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j65_a4tchad_L2FS_matched() = parent.EF_mu4T_j65_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j65_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j65_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j65_a4tchad_matched() = parent.EF_mu4T_j65_a4tchad_matched();
      } else {
         EF_mu4T_j65_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4T_j65_a4tchad_xe60_tclcw_loose.IsAvailable() ) {
         EF_mu4T_j65_a4tchad_xe60_tclcw_loose() = parent.EF_mu4T_j65_a4tchad_xe60_tclcw_loose();
      } else {
         EF_mu4T_j65_a4tchad_xe60_tclcw_loose() = 0;
      }
      if( parent.EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.IsAvailable() ) {
         EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose() = parent.EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose();
      } else {
         EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose() = 0;
      }
      if( parent.EF_mu4T_j80_a4tchad_L2FS_matched.IsAvailable() ) {
         EF_mu4T_j80_a4tchad_L2FS_matched() = parent.EF_mu4T_j80_a4tchad_L2FS_matched();
      } else {
         EF_mu4T_j80_a4tchad_L2FS_matched() = 0;
      }
      if( parent.EF_mu4T_j80_a4tchad_matched.IsAvailable() ) {
         EF_mu4T_j80_a4tchad_matched() = parent.EF_mu4T_j80_a4tchad_matched();
      } else {
         EF_mu4T_j80_a4tchad_matched() = 0;
      }
      if( parent.EF_mu4Ti_g20Tvh_loose.IsAvailable() ) {
         EF_mu4Ti_g20Tvh_loose() = parent.EF_mu4Ti_g20Tvh_loose();
      } else {
         EF_mu4Ti_g20Tvh_loose() = 0;
      }
      if( parent.EF_mu4Ti_g20Tvh_loose_TauMass.IsAvailable() ) {
         EF_mu4Ti_g20Tvh_loose_TauMass() = parent.EF_mu4Ti_g20Tvh_loose_TauMass();
      } else {
         EF_mu4Ti_g20Tvh_loose_TauMass() = 0;
      }
      if( parent.EF_mu4Ti_g20Tvh_medium.IsAvailable() ) {
         EF_mu4Ti_g20Tvh_medium() = parent.EF_mu4Ti_g20Tvh_medium();
      } else {
         EF_mu4Ti_g20Tvh_medium() = 0;
      }
      if( parent.EF_mu4Ti_g20Tvh_medium_TauMass.IsAvailable() ) {
         EF_mu4Ti_g20Tvh_medium_TauMass() = parent.EF_mu4Ti_g20Tvh_medium_TauMass();
      } else {
         EF_mu4Ti_g20Tvh_medium_TauMass() = 0;
      }
      if( parent.EF_mu4Tmu6_Bmumu.IsAvailable() ) {
         EF_mu4Tmu6_Bmumu() = parent.EF_mu4Tmu6_Bmumu();
      } else {
         EF_mu4Tmu6_Bmumu() = 0;
      }
      if( parent.EF_mu4Tmu6_Bmumu_Barrel.IsAvailable() ) {
         EF_mu4Tmu6_Bmumu_Barrel() = parent.EF_mu4Tmu6_Bmumu_Barrel();
      } else {
         EF_mu4Tmu6_Bmumu_Barrel() = 0;
      }
      if( parent.EF_mu4Tmu6_Bmumux.IsAvailable() ) {
         EF_mu4Tmu6_Bmumux() = parent.EF_mu4Tmu6_Bmumux();
      } else {
         EF_mu4Tmu6_Bmumux() = 0;
      }
      if( parent.EF_mu4Tmu6_Bmumux_Barrel.IsAvailable() ) {
         EF_mu4Tmu6_Bmumux_Barrel() = parent.EF_mu4Tmu6_Bmumux_Barrel();
      } else {
         EF_mu4Tmu6_Bmumux_Barrel() = 0;
      }
      if( parent.EF_mu4Tmu6_DiMu.IsAvailable() ) {
         EF_mu4Tmu6_DiMu() = parent.EF_mu4Tmu6_DiMu();
      } else {
         EF_mu4Tmu6_DiMu() = 0;
      }
      if( parent.EF_mu4Tmu6_DiMu_Barrel.IsAvailable() ) {
         EF_mu4Tmu6_DiMu_Barrel() = parent.EF_mu4Tmu6_DiMu_Barrel();
      } else {
         EF_mu4Tmu6_DiMu_Barrel() = 0;
      }
      if( parent.EF_mu4Tmu6_DiMu_noVtx_noOS.IsAvailable() ) {
         EF_mu4Tmu6_DiMu_noVtx_noOS() = parent.EF_mu4Tmu6_DiMu_noVtx_noOS();
      } else {
         EF_mu4Tmu6_DiMu_noVtx_noOS() = 0;
      }
      if( parent.EF_mu4Tmu6_Jpsimumu.IsAvailable() ) {
         EF_mu4Tmu6_Jpsimumu() = parent.EF_mu4Tmu6_Jpsimumu();
      } else {
         EF_mu4Tmu6_Jpsimumu() = 0;
      }
      if( parent.EF_mu4Tmu6_Jpsimumu_Barrel.IsAvailable() ) {
         EF_mu4Tmu6_Jpsimumu_Barrel() = parent.EF_mu4Tmu6_Jpsimumu_Barrel();
      } else {
         EF_mu4Tmu6_Jpsimumu_Barrel() = 0;
      }
      if( parent.EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.IsAvailable() ) {
         EF_mu4Tmu6_Jpsimumu_IDTrkNoCut() = parent.EF_mu4Tmu6_Jpsimumu_IDTrkNoCut();
      } else {
         EF_mu4Tmu6_Jpsimumu_IDTrkNoCut() = 0;
      }
      if( parent.EF_mu4Tmu6_Upsimumu.IsAvailable() ) {
         EF_mu4Tmu6_Upsimumu() = parent.EF_mu4Tmu6_Upsimumu();
      } else {
         EF_mu4Tmu6_Upsimumu() = 0;
      }
      if( parent.EF_mu4Tmu6_Upsimumu_Barrel.IsAvailable() ) {
         EF_mu4Tmu6_Upsimumu_Barrel() = parent.EF_mu4Tmu6_Upsimumu_Barrel();
      } else {
         EF_mu4Tmu6_Upsimumu_Barrel() = 0;
      }
      if( parent.EF_mu4_L1MU11_MSonly_cosmic.IsAvailable() ) {
         EF_mu4_L1MU11_MSonly_cosmic() = parent.EF_mu4_L1MU11_MSonly_cosmic();
      } else {
         EF_mu4_L1MU11_MSonly_cosmic() = 0;
      }
      if( parent.EF_mu4_L1MU11_cosmic.IsAvailable() ) {
         EF_mu4_L1MU11_cosmic() = parent.EF_mu4_L1MU11_cosmic();
      } else {
         EF_mu4_L1MU11_cosmic() = 0;
      }
      if( parent.EF_mu4_empty_NoAlg.IsAvailable() ) {
         EF_mu4_empty_NoAlg() = parent.EF_mu4_empty_NoAlg();
      } else {
         EF_mu4_empty_NoAlg() = 0;
      }
      if( parent.EF_mu4_firstempty_NoAlg.IsAvailable() ) {
         EF_mu4_firstempty_NoAlg() = parent.EF_mu4_firstempty_NoAlg();
      } else {
         EF_mu4_firstempty_NoAlg() = 0;
      }
      if( parent.EF_mu4_unpaired_iso_NoAlg.IsAvailable() ) {
         EF_mu4_unpaired_iso_NoAlg() = parent.EF_mu4_unpaired_iso_NoAlg();
      } else {
         EF_mu4_unpaired_iso_NoAlg() = 0;
      }
      if( parent.EF_mu50_MSonly_barrel_tight.IsAvailable() ) {
         EF_mu50_MSonly_barrel_tight() = parent.EF_mu50_MSonly_barrel_tight();
      } else {
         EF_mu50_MSonly_barrel_tight() = 0;
      }
      if( parent.EF_mu6.IsAvailable() ) {
         EF_mu6() = parent.EF_mu6();
      } else {
         EF_mu6() = 0;
      }
      if( parent.EF_mu60_slow_outOfTime_tight1.IsAvailable() ) {
         EF_mu60_slow_outOfTime_tight1() = parent.EF_mu60_slow_outOfTime_tight1();
      } else {
         EF_mu60_slow_outOfTime_tight1() = 0;
      }
      if( parent.EF_mu60_slow_tight1.IsAvailable() ) {
         EF_mu60_slow_tight1() = parent.EF_mu60_slow_tight1();
      } else {
         EF_mu60_slow_tight1() = 0;
      }
      if( parent.EF_mu6_Jpsimumu_tight.IsAvailable() ) {
         EF_mu6_Jpsimumu_tight() = parent.EF_mu6_Jpsimumu_tight();
      } else {
         EF_mu6_Jpsimumu_tight() = 0;
      }
      if( parent.EF_mu6_MSonly.IsAvailable() ) {
         EF_mu6_MSonly() = parent.EF_mu6_MSonly();
      } else {
         EF_mu6_MSonly() = 0;
      }
      if( parent.EF_mu6_Trk_Jpsi_loose.IsAvailable() ) {
         EF_mu6_Trk_Jpsi_loose() = parent.EF_mu6_Trk_Jpsi_loose();
      } else {
         EF_mu6_Trk_Jpsi_loose() = 0;
      }
      if( parent.EF_mu6i.IsAvailable() ) {
         EF_mu6i() = parent.EF_mu6i();
      } else {
         EF_mu6i() = 0;
      }
      if( parent.EF_mu8.IsAvailable() ) {
         EF_mu8() = parent.EF_mu8();
      } else {
         EF_mu8() = 0;
      }
      if( parent.EF_mu8_4j45_a4tchad_L2FS.IsAvailable() ) {
         EF_mu8_4j45_a4tchad_L2FS() = parent.EF_mu8_4j45_a4tchad_L2FS();
      } else {
         EF_mu8_4j45_a4tchad_L2FS() = 0;
      }
      if( parent.EF_tau125_IDTrkNoCut.IsAvailable() ) {
         EF_tau125_IDTrkNoCut() = parent.EF_tau125_IDTrkNoCut();
      } else {
         EF_tau125_IDTrkNoCut() = 0;
      }
      if( parent.EF_tau125_medium1.IsAvailable() ) {
         EF_tau125_medium1() = parent.EF_tau125_medium1();
      } else {
         EF_tau125_medium1() = 0;
      }
      if( parent.EF_tau125_medium1_L2StarA.IsAvailable() ) {
         EF_tau125_medium1_L2StarA() = parent.EF_tau125_medium1_L2StarA();
      } else {
         EF_tau125_medium1_L2StarA() = 0;
      }
      if( parent.EF_tau125_medium1_L2StarB.IsAvailable() ) {
         EF_tau125_medium1_L2StarB() = parent.EF_tau125_medium1_L2StarB();
      } else {
         EF_tau125_medium1_L2StarB() = 0;
      }
      if( parent.EF_tau125_medium1_L2StarC.IsAvailable() ) {
         EF_tau125_medium1_L2StarC() = parent.EF_tau125_medium1_L2StarC();
      } else {
         EF_tau125_medium1_L2StarC() = 0;
      }
      if( parent.EF_tau125_medium1_llh.IsAvailable() ) {
         EF_tau125_medium1_llh() = parent.EF_tau125_medium1_llh();
      } else {
         EF_tau125_medium1_llh() = 0;
      }
      if( parent.EF_tau20T_medium.IsAvailable() ) {
         EF_tau20T_medium() = parent.EF_tau20T_medium();
      } else {
         EF_tau20T_medium() = 0;
      }
      if( parent.EF_tau20T_medium1.IsAvailable() ) {
         EF_tau20T_medium1() = parent.EF_tau20T_medium1();
      } else {
         EF_tau20T_medium1() = 0;
      }
      if( parent.EF_tau20T_medium1_e15vh_medium1.IsAvailable() ) {
         EF_tau20T_medium1_e15vh_medium1() = parent.EF_tau20T_medium1_e15vh_medium1();
      } else {
         EF_tau20T_medium1_e15vh_medium1() = 0;
      }
      if( parent.EF_tau20T_medium1_mu15i.IsAvailable() ) {
         EF_tau20T_medium1_mu15i() = parent.EF_tau20T_medium1_mu15i();
      } else {
         EF_tau20T_medium1_mu15i() = 0;
      }
      if( parent.EF_tau20T_medium_mu15.IsAvailable() ) {
         EF_tau20T_medium_mu15() = parent.EF_tau20T_medium_mu15();
      } else {
         EF_tau20T_medium_mu15() = 0;
      }
      if( parent.EF_tau20Ti_medium.IsAvailable() ) {
         EF_tau20Ti_medium() = parent.EF_tau20Ti_medium();
      } else {
         EF_tau20Ti_medium() = 0;
      }
      if( parent.EF_tau20Ti_medium1.IsAvailable() ) {
         EF_tau20Ti_medium1() = parent.EF_tau20Ti_medium1();
      } else {
         EF_tau20Ti_medium1() = 0;
      }
      if( parent.EF_tau20Ti_medium1_e18vh_medium1.IsAvailable() ) {
         EF_tau20Ti_medium1_e18vh_medium1() = parent.EF_tau20Ti_medium1_e18vh_medium1();
      } else {
         EF_tau20Ti_medium1_e18vh_medium1() = 0;
      }
      if( parent.EF_tau20Ti_medium1_llh_e18vh_medium1.IsAvailable() ) {
         EF_tau20Ti_medium1_llh_e18vh_medium1() = parent.EF_tau20Ti_medium1_llh_e18vh_medium1();
      } else {
         EF_tau20Ti_medium1_llh_e18vh_medium1() = 0;
      }
      if( parent.EF_tau20Ti_medium_e18vh_medium1.IsAvailable() ) {
         EF_tau20Ti_medium_e18vh_medium1() = parent.EF_tau20Ti_medium_e18vh_medium1();
      } else {
         EF_tau20Ti_medium_e18vh_medium1() = 0;
      }
      if( parent.EF_tau20Ti_tight1.IsAvailable() ) {
         EF_tau20Ti_tight1() = parent.EF_tau20Ti_tight1();
      } else {
         EF_tau20Ti_tight1() = 0;
      }
      if( parent.EF_tau20Ti_tight1_llh.IsAvailable() ) {
         EF_tau20Ti_tight1_llh() = parent.EF_tau20Ti_tight1_llh();
      } else {
         EF_tau20Ti_tight1_llh() = 0;
      }
      if( parent.EF_tau20_medium.IsAvailable() ) {
         EF_tau20_medium() = parent.EF_tau20_medium();
      } else {
         EF_tau20_medium() = 0;
      }
      if( parent.EF_tau20_medium1.IsAvailable() ) {
         EF_tau20_medium1() = parent.EF_tau20_medium1();
      } else {
         EF_tau20_medium1() = 0;
      }
      if( parent.EF_tau20_medium1_llh.IsAvailable() ) {
         EF_tau20_medium1_llh() = parent.EF_tau20_medium1_llh();
      } else {
         EF_tau20_medium1_llh() = 0;
      }
      if( parent.EF_tau20_medium1_llh_mu15.IsAvailable() ) {
         EF_tau20_medium1_llh_mu15() = parent.EF_tau20_medium1_llh_mu15();
      } else {
         EF_tau20_medium1_llh_mu15() = 0;
      }
      if( parent.EF_tau20_medium1_mu15.IsAvailable() ) {
         EF_tau20_medium1_mu15() = parent.EF_tau20_medium1_mu15();
      } else {
         EF_tau20_medium1_mu15() = 0;
      }
      if( parent.EF_tau20_medium1_mu15i.IsAvailable() ) {
         EF_tau20_medium1_mu15i() = parent.EF_tau20_medium1_mu15i();
      } else {
         EF_tau20_medium1_mu15i() = 0;
      }
      if( parent.EF_tau20_medium1_mu18.IsAvailable() ) {
         EF_tau20_medium1_mu18() = parent.EF_tau20_medium1_mu18();
      } else {
         EF_tau20_medium1_mu18() = 0;
      }
      if( parent.EF_tau20_medium_llh.IsAvailable() ) {
         EF_tau20_medium_llh() = parent.EF_tau20_medium_llh();
      } else {
         EF_tau20_medium_llh() = 0;
      }
      if( parent.EF_tau20_medium_mu15.IsAvailable() ) {
         EF_tau20_medium_mu15() = parent.EF_tau20_medium_mu15();
      } else {
         EF_tau20_medium_mu15() = 0;
      }
      if( parent.EF_tau29T_medium.IsAvailable() ) {
         EF_tau29T_medium() = parent.EF_tau29T_medium();
      } else {
         EF_tau29T_medium() = 0;
      }
      if( parent.EF_tau29T_medium1.IsAvailable() ) {
         EF_tau29T_medium1() = parent.EF_tau29T_medium1();
      } else {
         EF_tau29T_medium1() = 0;
      }
      if( parent.EF_tau29T_medium1_tau20T_medium1.IsAvailable() ) {
         EF_tau29T_medium1_tau20T_medium1() = parent.EF_tau29T_medium1_tau20T_medium1();
      } else {
         EF_tau29T_medium1_tau20T_medium1() = 0;
      }
      if( parent.EF_tau29T_medium1_xe40_tight.IsAvailable() ) {
         EF_tau29T_medium1_xe40_tight() = parent.EF_tau29T_medium1_xe40_tight();
      } else {
         EF_tau29T_medium1_xe40_tight() = 0;
      }
      if( parent.EF_tau29T_medium1_xe45_tight.IsAvailable() ) {
         EF_tau29T_medium1_xe45_tight() = parent.EF_tau29T_medium1_xe45_tight();
      } else {
         EF_tau29T_medium1_xe45_tight() = 0;
      }
      if( parent.EF_tau29T_medium_xe40_tight.IsAvailable() ) {
         EF_tau29T_medium_xe40_tight() = parent.EF_tau29T_medium_xe40_tight();
      } else {
         EF_tau29T_medium_xe40_tight() = 0;
      }
      if( parent.EF_tau29T_medium_xe45_tight.IsAvailable() ) {
         EF_tau29T_medium_xe45_tight() = parent.EF_tau29T_medium_xe45_tight();
      } else {
         EF_tau29T_medium_xe45_tight() = 0;
      }
      if( parent.EF_tau29T_tight1.IsAvailable() ) {
         EF_tau29T_tight1() = parent.EF_tau29T_tight1();
      } else {
         EF_tau29T_tight1() = 0;
      }
      if( parent.EF_tau29T_tight1_llh.IsAvailable() ) {
         EF_tau29T_tight1_llh() = parent.EF_tau29T_tight1_llh();
      } else {
         EF_tau29T_tight1_llh() = 0;
      }
      if( parent.EF_tau29Ti_medium1.IsAvailable() ) {
         EF_tau29Ti_medium1() = parent.EF_tau29Ti_medium1();
      } else {
         EF_tau29Ti_medium1() = 0;
      }
      if( parent.EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh.IsAvailable() ) {
         EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh() = parent.EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh();
      } else {
         EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh() = 0;
      }
      if( parent.EF_tau29Ti_medium1_llh_xe40_tight.IsAvailable() ) {
         EF_tau29Ti_medium1_llh_xe40_tight() = parent.EF_tau29Ti_medium1_llh_xe40_tight();
      } else {
         EF_tau29Ti_medium1_llh_xe40_tight() = 0;
      }
      if( parent.EF_tau29Ti_medium1_llh_xe45_tight.IsAvailable() ) {
         EF_tau29Ti_medium1_llh_xe45_tight() = parent.EF_tau29Ti_medium1_llh_xe45_tight();
      } else {
         EF_tau29Ti_medium1_llh_xe45_tight() = 0;
      }
      if( parent.EF_tau29Ti_medium1_tau20Ti_medium1.IsAvailable() ) {
         EF_tau29Ti_medium1_tau20Ti_medium1() = parent.EF_tau29Ti_medium1_tau20Ti_medium1();
      } else {
         EF_tau29Ti_medium1_tau20Ti_medium1() = 0;
      }
      if( parent.EF_tau29Ti_medium1_xe40_tight.IsAvailable() ) {
         EF_tau29Ti_medium1_xe40_tight() = parent.EF_tau29Ti_medium1_xe40_tight();
      } else {
         EF_tau29Ti_medium1_xe40_tight() = 0;
      }
      if( parent.EF_tau29Ti_medium1_xe45_tight.IsAvailable() ) {
         EF_tau29Ti_medium1_xe45_tight() = parent.EF_tau29Ti_medium1_xe45_tight();
      } else {
         EF_tau29Ti_medium1_xe45_tight() = 0;
      }
      if( parent.EF_tau29Ti_medium1_xe55_tclcw.IsAvailable() ) {
         EF_tau29Ti_medium1_xe55_tclcw() = parent.EF_tau29Ti_medium1_xe55_tclcw();
      } else {
         EF_tau29Ti_medium1_xe55_tclcw() = 0;
      }
      if( parent.EF_tau29Ti_medium1_xe55_tclcw_tight.IsAvailable() ) {
         EF_tau29Ti_medium1_xe55_tclcw_tight() = parent.EF_tau29Ti_medium1_xe55_tclcw_tight();
      } else {
         EF_tau29Ti_medium1_xe55_tclcw_tight() = 0;
      }
      if( parent.EF_tau29Ti_medium_xe40_tight.IsAvailable() ) {
         EF_tau29Ti_medium_xe40_tight() = parent.EF_tau29Ti_medium_xe40_tight();
      } else {
         EF_tau29Ti_medium_xe40_tight() = 0;
      }
      if( parent.EF_tau29Ti_medium_xe45_tight.IsAvailable() ) {
         EF_tau29Ti_medium_xe45_tight() = parent.EF_tau29Ti_medium_xe45_tight();
      } else {
         EF_tau29Ti_medium_xe45_tight() = 0;
      }
      if( parent.EF_tau29Ti_tight1.IsAvailable() ) {
         EF_tau29Ti_tight1() = parent.EF_tau29Ti_tight1();
      } else {
         EF_tau29Ti_tight1() = 0;
      }
      if( parent.EF_tau29Ti_tight1_llh.IsAvailable() ) {
         EF_tau29Ti_tight1_llh() = parent.EF_tau29Ti_tight1_llh();
      } else {
         EF_tau29Ti_tight1_llh() = 0;
      }
      if( parent.EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh.IsAvailable() ) {
         EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh() = parent.EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh();
      } else {
         EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh() = 0;
      }
      if( parent.EF_tau29Ti_tight1_tau20Ti_tight1.IsAvailable() ) {
         EF_tau29Ti_tight1_tau20Ti_tight1() = parent.EF_tau29Ti_tight1_tau20Ti_tight1();
      } else {
         EF_tau29Ti_tight1_tau20Ti_tight1() = 0;
      }
      if( parent.EF_tau29_IDTrkNoCut.IsAvailable() ) {
         EF_tau29_IDTrkNoCut() = parent.EF_tau29_IDTrkNoCut();
      } else {
         EF_tau29_IDTrkNoCut() = 0;
      }
      if( parent.EF_tau29_medium.IsAvailable() ) {
         EF_tau29_medium() = parent.EF_tau29_medium();
      } else {
         EF_tau29_medium() = 0;
      }
      if( parent.EF_tau29_medium1.IsAvailable() ) {
         EF_tau29_medium1() = parent.EF_tau29_medium1();
      } else {
         EF_tau29_medium1() = 0;
      }
      if( parent.EF_tau29_medium1_llh.IsAvailable() ) {
         EF_tau29_medium1_llh() = parent.EF_tau29_medium1_llh();
      } else {
         EF_tau29_medium1_llh() = 0;
      }
      if( parent.EF_tau29_medium_2stTest.IsAvailable() ) {
         EF_tau29_medium_2stTest() = parent.EF_tau29_medium_2stTest();
      } else {
         EF_tau29_medium_2stTest() = 0;
      }
      if( parent.EF_tau29_medium_L2StarA.IsAvailable() ) {
         EF_tau29_medium_L2StarA() = parent.EF_tau29_medium_L2StarA();
      } else {
         EF_tau29_medium_L2StarA() = 0;
      }
      if( parent.EF_tau29_medium_L2StarB.IsAvailable() ) {
         EF_tau29_medium_L2StarB() = parent.EF_tau29_medium_L2StarB();
      } else {
         EF_tau29_medium_L2StarB() = 0;
      }
      if( parent.EF_tau29_medium_L2StarC.IsAvailable() ) {
         EF_tau29_medium_L2StarC() = parent.EF_tau29_medium_L2StarC();
      } else {
         EF_tau29_medium_L2StarC() = 0;
      }
      if( parent.EF_tau29_medium_llh.IsAvailable() ) {
         EF_tau29_medium_llh() = parent.EF_tau29_medium_llh();
      } else {
         EF_tau29_medium_llh() = 0;
      }
      if( parent.EF_tau29i_medium.IsAvailable() ) {
         EF_tau29i_medium() = parent.EF_tau29i_medium();
      } else {
         EF_tau29i_medium() = 0;
      }
      if( parent.EF_tau29i_medium1.IsAvailable() ) {
         EF_tau29i_medium1() = parent.EF_tau29i_medium1();
      } else {
         EF_tau29i_medium1() = 0;
      }
      if( parent.EF_tau38T_medium.IsAvailable() ) {
         EF_tau38T_medium() = parent.EF_tau38T_medium();
      } else {
         EF_tau38T_medium() = 0;
      }
      if( parent.EF_tau38T_medium1.IsAvailable() ) {
         EF_tau38T_medium1() = parent.EF_tau38T_medium1();
      } else {
         EF_tau38T_medium1() = 0;
      }
      if( parent.EF_tau38T_medium1_e18vh_medium1.IsAvailable() ) {
         EF_tau38T_medium1_e18vh_medium1() = parent.EF_tau38T_medium1_e18vh_medium1();
      } else {
         EF_tau38T_medium1_e18vh_medium1() = 0;
      }
      if( parent.EF_tau38T_medium1_llh_e18vh_medium1.IsAvailable() ) {
         EF_tau38T_medium1_llh_e18vh_medium1() = parent.EF_tau38T_medium1_llh_e18vh_medium1();
      } else {
         EF_tau38T_medium1_llh_e18vh_medium1() = 0;
      }
      if( parent.EF_tau38T_medium1_xe40_tight.IsAvailable() ) {
         EF_tau38T_medium1_xe40_tight() = parent.EF_tau38T_medium1_xe40_tight();
      } else {
         EF_tau38T_medium1_xe40_tight() = 0;
      }
      if( parent.EF_tau38T_medium1_xe45_tight.IsAvailable() ) {
         EF_tau38T_medium1_xe45_tight() = parent.EF_tau38T_medium1_xe45_tight();
      } else {
         EF_tau38T_medium1_xe45_tight() = 0;
      }
      if( parent.EF_tau38T_medium1_xe55_tclcw_tight.IsAvailable() ) {
         EF_tau38T_medium1_xe55_tclcw_tight() = parent.EF_tau38T_medium1_xe55_tclcw_tight();
      } else {
         EF_tau38T_medium1_xe55_tclcw_tight() = 0;
      }
      if( parent.EF_tau38T_medium_e18vh_medium1.IsAvailable() ) {
         EF_tau38T_medium_e18vh_medium1() = parent.EF_tau38T_medium_e18vh_medium1();
      } else {
         EF_tau38T_medium_e18vh_medium1() = 0;
      }
      if( parent.EF_tau50_medium.IsAvailable() ) {
         EF_tau50_medium() = parent.EF_tau50_medium();
      } else {
         EF_tau50_medium() = 0;
      }
      if( parent.EF_tau50_medium1_e18vh_medium1.IsAvailable() ) {
         EF_tau50_medium1_e18vh_medium1() = parent.EF_tau50_medium1_e18vh_medium1();
      } else {
         EF_tau50_medium1_e18vh_medium1() = 0;
      }
      if( parent.EF_tau50_medium_e15vh_medium1.IsAvailable() ) {
         EF_tau50_medium_e15vh_medium1() = parent.EF_tau50_medium_e15vh_medium1();
      } else {
         EF_tau50_medium_e15vh_medium1() = 0;
      }
      if( parent.EF_tauNoCut.IsAvailable() ) {
         EF_tauNoCut() = parent.EF_tauNoCut();
      } else {
         EF_tauNoCut() = 0;
      }
      if( parent.EF_tauNoCut_L1TAU40.IsAvailable() ) {
         EF_tauNoCut_L1TAU40() = parent.EF_tauNoCut_L1TAU40();
      } else {
         EF_tauNoCut_L1TAU40() = 0;
      }
      if( parent.EF_tauNoCut_cosmic.IsAvailable() ) {
         EF_tauNoCut_cosmic() = parent.EF_tauNoCut_cosmic();
      } else {
         EF_tauNoCut_cosmic() = 0;
      }
      if( parent.EF_xe100.IsAvailable() ) {
         EF_xe100() = parent.EF_xe100();
      } else {
         EF_xe100() = 0;
      }
      if( parent.EF_xe100T_tclcw.IsAvailable() ) {
         EF_xe100T_tclcw() = parent.EF_xe100T_tclcw();
      } else {
         EF_xe100T_tclcw() = 0;
      }
      if( parent.EF_xe100T_tclcw_loose.IsAvailable() ) {
         EF_xe100T_tclcw_loose() = parent.EF_xe100T_tclcw_loose();
      } else {
         EF_xe100T_tclcw_loose() = 0;
      }
      if( parent.EF_xe100_tclcw.IsAvailable() ) {
         EF_xe100_tclcw() = parent.EF_xe100_tclcw();
      } else {
         EF_xe100_tclcw() = 0;
      }
      if( parent.EF_xe100_tclcw_loose.IsAvailable() ) {
         EF_xe100_tclcw_loose() = parent.EF_xe100_tclcw_loose();
      } else {
         EF_xe100_tclcw_loose() = 0;
      }
      if( parent.EF_xe100_tclcw_veryloose.IsAvailable() ) {
         EF_xe100_tclcw_veryloose() = parent.EF_xe100_tclcw_veryloose();
      } else {
         EF_xe100_tclcw_veryloose() = 0;
      }
      if( parent.EF_xe100_tclcw_verytight.IsAvailable() ) {
         EF_xe100_tclcw_verytight() = parent.EF_xe100_tclcw_verytight();
      } else {
         EF_xe100_tclcw_verytight() = 0;
      }
      if( parent.EF_xe100_tight.IsAvailable() ) {
         EF_xe100_tight() = parent.EF_xe100_tight();
      } else {
         EF_xe100_tight() = 0;
      }
      if( parent.EF_xe110.IsAvailable() ) {
         EF_xe110() = parent.EF_xe110();
      } else {
         EF_xe110() = 0;
      }
      if( parent.EF_xe30.IsAvailable() ) {
         EF_xe30() = parent.EF_xe30();
      } else {
         EF_xe30() = 0;
      }
      if( parent.EF_xe30_tclcw.IsAvailable() ) {
         EF_xe30_tclcw() = parent.EF_xe30_tclcw();
      } else {
         EF_xe30_tclcw() = 0;
      }
      if( parent.EF_xe40.IsAvailable() ) {
         EF_xe40() = parent.EF_xe40();
      } else {
         EF_xe40() = 0;
      }
      if( parent.EF_xe50.IsAvailable() ) {
         EF_xe50() = parent.EF_xe50();
      } else {
         EF_xe50() = 0;
      }
      if( parent.EF_xe55_LArNoiseBurst.IsAvailable() ) {
         EF_xe55_LArNoiseBurst() = parent.EF_xe55_LArNoiseBurst();
      } else {
         EF_xe55_LArNoiseBurst() = 0;
      }
      if( parent.EF_xe55_tclcw.IsAvailable() ) {
         EF_xe55_tclcw() = parent.EF_xe55_tclcw();
      } else {
         EF_xe55_tclcw() = 0;
      }
      if( parent.EF_xe60.IsAvailable() ) {
         EF_xe60() = parent.EF_xe60();
      } else {
         EF_xe60() = 0;
      }
      if( parent.EF_xe60T.IsAvailable() ) {
         EF_xe60T() = parent.EF_xe60T();
      } else {
         EF_xe60T() = 0;
      }
      if( parent.EF_xe60_tclcw.IsAvailable() ) {
         EF_xe60_tclcw() = parent.EF_xe60_tclcw();
      } else {
         EF_xe60_tclcw() = 0;
      }
      if( parent.EF_xe60_tclcw_loose.IsAvailable() ) {
         EF_xe60_tclcw_loose() = parent.EF_xe60_tclcw_loose();
      } else {
         EF_xe60_tclcw_loose() = 0;
      }
      if( parent.EF_xe70.IsAvailable() ) {
         EF_xe70() = parent.EF_xe70();
      } else {
         EF_xe70() = 0;
      }
      if( parent.EF_xe70_tclcw_loose.IsAvailable() ) {
         EF_xe70_tclcw_loose() = parent.EF_xe70_tclcw_loose();
      } else {
         EF_xe70_tclcw_loose() = 0;
      }
      if( parent.EF_xe70_tclcw_veryloose.IsAvailable() ) {
         EF_xe70_tclcw_veryloose() = parent.EF_xe70_tclcw_veryloose();
      } else {
         EF_xe70_tclcw_veryloose() = 0;
      }
      if( parent.EF_xe70_tight.IsAvailable() ) {
         EF_xe70_tight() = parent.EF_xe70_tight();
      } else {
         EF_xe70_tight() = 0;
      }
      if( parent.EF_xe70_tight_tclcw.IsAvailable() ) {
         EF_xe70_tight_tclcw() = parent.EF_xe70_tight_tclcw();
      } else {
         EF_xe70_tight_tclcw() = 0;
      }
      if( parent.EF_xe75_tclcw.IsAvailable() ) {
         EF_xe75_tclcw() = parent.EF_xe75_tclcw();
      } else {
         EF_xe75_tclcw() = 0;
      }
      if( parent.EF_xe80.IsAvailable() ) {
         EF_xe80() = parent.EF_xe80();
      } else {
         EF_xe80() = 0;
      }
      if( parent.EF_xe80T.IsAvailable() ) {
         EF_xe80T() = parent.EF_xe80T();
      } else {
         EF_xe80T() = 0;
      }
      if( parent.EF_xe80T_loose.IsAvailable() ) {
         EF_xe80T_loose() = parent.EF_xe80T_loose();
      } else {
         EF_xe80T_loose() = 0;
      }
      if( parent.EF_xe80T_tclcw.IsAvailable() ) {
         EF_xe80T_tclcw() = parent.EF_xe80T_tclcw();
      } else {
         EF_xe80T_tclcw() = 0;
      }
      if( parent.EF_xe80T_tclcw_loose.IsAvailable() ) {
         EF_xe80T_tclcw_loose() = parent.EF_xe80T_tclcw_loose();
      } else {
         EF_xe80T_tclcw_loose() = 0;
      }
      if( parent.EF_xe80_tclcw.IsAvailable() ) {
         EF_xe80_tclcw() = parent.EF_xe80_tclcw();
      } else {
         EF_xe80_tclcw() = 0;
      }
      if( parent.EF_xe80_tclcw_loose.IsAvailable() ) {
         EF_xe80_tclcw_loose() = parent.EF_xe80_tclcw_loose();
      } else {
         EF_xe80_tclcw_loose() = 0;
      }
      if( parent.EF_xe80_tclcw_tight.IsAvailable() ) {
         EF_xe80_tclcw_tight() = parent.EF_xe80_tclcw_tight();
      } else {
         EF_xe80_tclcw_tight() = 0;
      }
      if( parent.EF_xe80_tclcw_verytight.IsAvailable() ) {
         EF_xe80_tclcw_verytight() = parent.EF_xe80_tclcw_verytight();
      } else {
         EF_xe80_tclcw_verytight() = 0;
      }
      if( parent.EF_xe80_tight.IsAvailable() ) {
         EF_xe80_tight() = parent.EF_xe80_tight();
      } else {
         EF_xe80_tight() = 0;
      }
      if( parent.EF_xe90.IsAvailable() ) {
         EF_xe90() = parent.EF_xe90();
      } else {
         EF_xe90() = 0;
      }
      if( parent.EF_xe90_tclcw.IsAvailable() ) {
         EF_xe90_tclcw() = parent.EF_xe90_tclcw();
      } else {
         EF_xe90_tclcw() = 0;
      }
      if( parent.EF_xe90_tclcw_tight.IsAvailable() ) {
         EF_xe90_tclcw_tight() = parent.EF_xe90_tclcw_tight();
      } else {
         EF_xe90_tclcw_tight() = 0;
      }
      if( parent.EF_xe90_tclcw_veryloose.IsAvailable() ) {
         EF_xe90_tclcw_veryloose() = parent.EF_xe90_tclcw_veryloose();
      } else {
         EF_xe90_tclcw_veryloose() = 0;
      }
      if( parent.EF_xe90_tclcw_verytight.IsAvailable() ) {
         EF_xe90_tclcw_verytight() = parent.EF_xe90_tclcw_verytight();
      } else {
         EF_xe90_tclcw_verytight() = 0;
      }
      if( parent.EF_xe90_tight.IsAvailable() ) {
         EF_xe90_tight() = parent.EF_xe90_tight();
      } else {
         EF_xe90_tight() = 0;
      }
      if( parent.L1_2EM10VH.IsAvailable() ) {
         L1_2EM10VH() = parent.L1_2EM10VH();
      } else {
         L1_2EM10VH() = 0;
      }
      if( parent.L1_2EM12.IsAvailable() ) {
         L1_2EM12() = parent.L1_2EM12();
      } else {
         L1_2EM12() = 0;
      }
      if( parent.L1_2EM12_EM16V.IsAvailable() ) {
         L1_2EM12_EM16V() = parent.L1_2EM12_EM16V();
      } else {
         L1_2EM12_EM16V() = 0;
      }
      if( parent.L1_2EM3.IsAvailable() ) {
         L1_2EM3() = parent.L1_2EM3();
      } else {
         L1_2EM3() = 0;
      }
      if( parent.L1_2EM3_EM12.IsAvailable() ) {
         L1_2EM3_EM12() = parent.L1_2EM3_EM12();
      } else {
         L1_2EM3_EM12() = 0;
      }
      if( parent.L1_2EM3_EM6.IsAvailable() ) {
         L1_2EM3_EM6() = parent.L1_2EM3_EM6();
      } else {
         L1_2EM3_EM6() = 0;
      }
      if( parent.L1_2EM6.IsAvailable() ) {
         L1_2EM6() = parent.L1_2EM6();
      } else {
         L1_2EM6() = 0;
      }
      if( parent.L1_2EM6_EM16VH.IsAvailable() ) {
         L1_2EM6_EM16VH() = parent.L1_2EM6_EM16VH();
      } else {
         L1_2EM6_EM16VH() = 0;
      }
      if( parent.L1_2EM6_MU6.IsAvailable() ) {
         L1_2EM6_MU6() = parent.L1_2EM6_MU6();
      } else {
         L1_2EM6_MU6() = 0;
      }
      if( parent.L1_2J20_XE20.IsAvailable() ) {
         L1_2J20_XE20() = parent.L1_2J20_XE20();
      } else {
         L1_2J20_XE20() = 0;
      }
      if( parent.L1_2J30_XE20.IsAvailable() ) {
         L1_2J30_XE20() = parent.L1_2J30_XE20();
      } else {
         L1_2J30_XE20() = 0;
      }
      if( parent.L1_2MU10.IsAvailable() ) {
         L1_2MU10() = parent.L1_2MU10();
      } else {
         L1_2MU10() = 0;
      }
      if( parent.L1_2MU4.IsAvailable() ) {
         L1_2MU4() = parent.L1_2MU4();
      } else {
         L1_2MU4() = 0;
      }
      if( parent.L1_2MU4_2EM3.IsAvailable() ) {
         L1_2MU4_2EM3() = parent.L1_2MU4_2EM3();
      } else {
         L1_2MU4_2EM3() = 0;
      }
      if( parent.L1_2MU4_BARREL.IsAvailable() ) {
         L1_2MU4_BARREL() = parent.L1_2MU4_BARREL();
      } else {
         L1_2MU4_BARREL() = 0;
      }
      if( parent.L1_2MU4_BARRELONLY.IsAvailable() ) {
         L1_2MU4_BARRELONLY() = parent.L1_2MU4_BARRELONLY();
      } else {
         L1_2MU4_BARRELONLY() = 0;
      }
      if( parent.L1_2MU4_EM3.IsAvailable() ) {
         L1_2MU4_EM3() = parent.L1_2MU4_EM3();
      } else {
         L1_2MU4_EM3() = 0;
      }
      if( parent.L1_2MU4_EMPTY.IsAvailable() ) {
         L1_2MU4_EMPTY() = parent.L1_2MU4_EMPTY();
      } else {
         L1_2MU4_EMPTY() = 0;
      }
      if( parent.L1_2MU4_FIRSTEMPTY.IsAvailable() ) {
         L1_2MU4_FIRSTEMPTY() = parent.L1_2MU4_FIRSTEMPTY();
      } else {
         L1_2MU4_FIRSTEMPTY() = 0;
      }
      if( parent.L1_2MU4_MU6.IsAvailable() ) {
         L1_2MU4_MU6() = parent.L1_2MU4_MU6();
      } else {
         L1_2MU4_MU6() = 0;
      }
      if( parent.L1_2MU4_MU6_BARREL.IsAvailable() ) {
         L1_2MU4_MU6_BARREL() = parent.L1_2MU4_MU6_BARREL();
      } else {
         L1_2MU4_MU6_BARREL() = 0;
      }
      if( parent.L1_2MU4_XE30.IsAvailable() ) {
         L1_2MU4_XE30() = parent.L1_2MU4_XE30();
      } else {
         L1_2MU4_XE30() = 0;
      }
      if( parent.L1_2MU4_XE40.IsAvailable() ) {
         L1_2MU4_XE40() = parent.L1_2MU4_XE40();
      } else {
         L1_2MU4_XE40() = 0;
      }
      if( parent.L1_2MU6.IsAvailable() ) {
         L1_2MU6() = parent.L1_2MU6();
      } else {
         L1_2MU6() = 0;
      }
      if( parent.L1_2MU6_UNPAIRED_ISO.IsAvailable() ) {
         L1_2MU6_UNPAIRED_ISO() = parent.L1_2MU6_UNPAIRED_ISO();
      } else {
         L1_2MU6_UNPAIRED_ISO() = 0;
      }
      if( parent.L1_2MU6_UNPAIRED_NONISO.IsAvailable() ) {
         L1_2MU6_UNPAIRED_NONISO() = parent.L1_2MU6_UNPAIRED_NONISO();
      } else {
         L1_2MU6_UNPAIRED_NONISO() = 0;
      }
      if( parent.L1_2TAU11.IsAvailable() ) {
         L1_2TAU11() = parent.L1_2TAU11();
      } else {
         L1_2TAU11() = 0;
      }
      if( parent.L1_2TAU11I.IsAvailable() ) {
         L1_2TAU11I() = parent.L1_2TAU11I();
      } else {
         L1_2TAU11I() = 0;
      }
      if( parent.L1_2TAU11I_EM14VH.IsAvailable() ) {
         L1_2TAU11I_EM14VH() = parent.L1_2TAU11I_EM14VH();
      } else {
         L1_2TAU11I_EM14VH() = 0;
      }
      if( parent.L1_2TAU11I_TAU15.IsAvailable() ) {
         L1_2TAU11I_TAU15() = parent.L1_2TAU11I_TAU15();
      } else {
         L1_2TAU11I_TAU15() = 0;
      }
      if( parent.L1_2TAU11_EM10VH.IsAvailable() ) {
         L1_2TAU11_EM10VH() = parent.L1_2TAU11_EM10VH();
      } else {
         L1_2TAU11_EM10VH() = 0;
      }
      if( parent.L1_2TAU11_TAU15.IsAvailable() ) {
         L1_2TAU11_TAU15() = parent.L1_2TAU11_TAU15();
      } else {
         L1_2TAU11_TAU15() = 0;
      }
      if( parent.L1_2TAU11_TAU20_EM10VH.IsAvailable() ) {
         L1_2TAU11_TAU20_EM10VH() = parent.L1_2TAU11_TAU20_EM10VH();
      } else {
         L1_2TAU11_TAU20_EM10VH() = 0;
      }
      if( parent.L1_2TAU11_TAU20_EM14VH.IsAvailable() ) {
         L1_2TAU11_TAU20_EM14VH() = parent.L1_2TAU11_TAU20_EM14VH();
      } else {
         L1_2TAU11_TAU20_EM14VH() = 0;
      }
      if( parent.L1_2TAU15.IsAvailable() ) {
         L1_2TAU15() = parent.L1_2TAU15();
      } else {
         L1_2TAU15() = 0;
      }
      if( parent.L1_2TAU20.IsAvailable() ) {
         L1_2TAU20() = parent.L1_2TAU20();
      } else {
         L1_2TAU20() = 0;
      }
      if( parent.L1_EM10VH.IsAvailable() ) {
         L1_EM10VH() = parent.L1_EM10VH();
      } else {
         L1_EM10VH() = 0;
      }
      if( parent.L1_EM10VH_MU6.IsAvailable() ) {
         L1_EM10VH_MU6() = parent.L1_EM10VH_MU6();
      } else {
         L1_EM10VH_MU6() = 0;
      }
      if( parent.L1_EM10VH_XE20.IsAvailable() ) {
         L1_EM10VH_XE20() = parent.L1_EM10VH_XE20();
      } else {
         L1_EM10VH_XE20() = 0;
      }
      if( parent.L1_EM10VH_XE30.IsAvailable() ) {
         L1_EM10VH_XE30() = parent.L1_EM10VH_XE30();
      } else {
         L1_EM10VH_XE30() = 0;
      }
      if( parent.L1_EM10VH_XE35.IsAvailable() ) {
         L1_EM10VH_XE35() = parent.L1_EM10VH_XE35();
      } else {
         L1_EM10VH_XE35() = 0;
      }
      if( parent.L1_EM12.IsAvailable() ) {
         L1_EM12() = parent.L1_EM12();
      } else {
         L1_EM12() = 0;
      }
      if( parent.L1_EM12_3J10.IsAvailable() ) {
         L1_EM12_3J10() = parent.L1_EM12_3J10();
      } else {
         L1_EM12_3J10() = 0;
      }
      if( parent.L1_EM12_4J10.IsAvailable() ) {
         L1_EM12_4J10() = parent.L1_EM12_4J10();
      } else {
         L1_EM12_4J10() = 0;
      }
      if( parent.L1_EM12_XE20.IsAvailable() ) {
         L1_EM12_XE20() = parent.L1_EM12_XE20();
      } else {
         L1_EM12_XE20() = 0;
      }
      if( parent.L1_EM12_XS30.IsAvailable() ) {
         L1_EM12_XS30() = parent.L1_EM12_XS30();
      } else {
         L1_EM12_XS30() = 0;
      }
      if( parent.L1_EM12_XS45.IsAvailable() ) {
         L1_EM12_XS45() = parent.L1_EM12_XS45();
      } else {
         L1_EM12_XS45() = 0;
      }
      if( parent.L1_EM14VH.IsAvailable() ) {
         L1_EM14VH() = parent.L1_EM14VH();
      } else {
         L1_EM14VH() = 0;
      }
      if( parent.L1_EM16V.IsAvailable() ) {
         L1_EM16V() = parent.L1_EM16V();
      } else {
         L1_EM16V() = 0;
      }
      if( parent.L1_EM16VH.IsAvailable() ) {
         L1_EM16VH() = parent.L1_EM16VH();
      } else {
         L1_EM16VH() = 0;
      }
      if( parent.L1_EM16VH_MU4.IsAvailable() ) {
         L1_EM16VH_MU4() = parent.L1_EM16VH_MU4();
      } else {
         L1_EM16VH_MU4() = 0;
      }
      if( parent.L1_EM16V_XE20.IsAvailable() ) {
         L1_EM16V_XE20() = parent.L1_EM16V_XE20();
      } else {
         L1_EM16V_XE20() = 0;
      }
      if( parent.L1_EM16V_XS45.IsAvailable() ) {
         L1_EM16V_XS45() = parent.L1_EM16V_XS45();
      } else {
         L1_EM16V_XS45() = 0;
      }
      if( parent.L1_EM18VH.IsAvailable() ) {
         L1_EM18VH() = parent.L1_EM18VH();
      } else {
         L1_EM18VH() = 0;
      }
      if( parent.L1_EM3.IsAvailable() ) {
         L1_EM3() = parent.L1_EM3();
      } else {
         L1_EM3() = 0;
      }
      if( parent.L1_EM30.IsAvailable() ) {
         L1_EM30() = parent.L1_EM30();
      } else {
         L1_EM30() = 0;
      }
      if( parent.L1_EM30_BGRP7.IsAvailable() ) {
         L1_EM30_BGRP7() = parent.L1_EM30_BGRP7();
      } else {
         L1_EM30_BGRP7() = 0;
      }
      if( parent.L1_EM3_EMPTY.IsAvailable() ) {
         L1_EM3_EMPTY() = parent.L1_EM3_EMPTY();
      } else {
         L1_EM3_EMPTY() = 0;
      }
      if( parent.L1_EM3_FIRSTEMPTY.IsAvailable() ) {
         L1_EM3_FIRSTEMPTY() = parent.L1_EM3_FIRSTEMPTY();
      } else {
         L1_EM3_FIRSTEMPTY() = 0;
      }
      if( parent.L1_EM3_MU6.IsAvailable() ) {
         L1_EM3_MU6() = parent.L1_EM3_MU6();
      } else {
         L1_EM3_MU6() = 0;
      }
      if( parent.L1_EM3_UNPAIRED_ISO.IsAvailable() ) {
         L1_EM3_UNPAIRED_ISO() = parent.L1_EM3_UNPAIRED_ISO();
      } else {
         L1_EM3_UNPAIRED_ISO() = 0;
      }
      if( parent.L1_EM3_UNPAIRED_NONISO.IsAvailable() ) {
         L1_EM3_UNPAIRED_NONISO() = parent.L1_EM3_UNPAIRED_NONISO();
      } else {
         L1_EM3_UNPAIRED_NONISO() = 0;
      }
      if( parent.L1_EM6.IsAvailable() ) {
         L1_EM6() = parent.L1_EM6();
      } else {
         L1_EM6() = 0;
      }
      if( parent.L1_EM6_2MU6.IsAvailable() ) {
         L1_EM6_2MU6() = parent.L1_EM6_2MU6();
      } else {
         L1_EM6_2MU6() = 0;
      }
      if( parent.L1_EM6_EMPTY.IsAvailable() ) {
         L1_EM6_EMPTY() = parent.L1_EM6_EMPTY();
      } else {
         L1_EM6_EMPTY() = 0;
      }
      if( parent.L1_EM6_MU10.IsAvailable() ) {
         L1_EM6_MU10() = parent.L1_EM6_MU10();
      } else {
         L1_EM6_MU10() = 0;
      }
      if( parent.L1_EM6_MU6.IsAvailable() ) {
         L1_EM6_MU6() = parent.L1_EM6_MU6();
      } else {
         L1_EM6_MU6() = 0;
      }
      if( parent.L1_EM6_XS45.IsAvailable() ) {
         L1_EM6_XS45() = parent.L1_EM6_XS45();
      } else {
         L1_EM6_XS45() = 0;
      }
      if( parent.L1_J30_XE35.IsAvailable() ) {
         L1_J30_XE35() = parent.L1_J30_XE35();
      } else {
         L1_J30_XE35() = 0;
      }
      if( parent.L1_J30_XE40.IsAvailable() ) {
         L1_J30_XE40() = parent.L1_J30_XE40();
      } else {
         L1_J30_XE40() = 0;
      }
      if( parent.L1_J30_XE50.IsAvailable() ) {
         L1_J30_XE50() = parent.L1_J30_XE50();
      } else {
         L1_J30_XE50() = 0;
      }
      if( parent.L1_J50_XE30.IsAvailable() ) {
         L1_J50_XE30() = parent.L1_J50_XE30();
      } else {
         L1_J50_XE30() = 0;
      }
      if( parent.L1_J50_XE35.IsAvailable() ) {
         L1_J50_XE35() = parent.L1_J50_XE35();
      } else {
         L1_J50_XE35() = 0;
      }
      if( parent.L1_J50_XE40.IsAvailable() ) {
         L1_J50_XE40() = parent.L1_J50_XE40();
      } else {
         L1_J50_XE40() = 0;
      }
      if( parent.L1_MU10.IsAvailable() ) {
         L1_MU10() = parent.L1_MU10();
      } else {
         L1_MU10() = 0;
      }
      if( parent.L1_MU10_EMPTY.IsAvailable() ) {
         L1_MU10_EMPTY() = parent.L1_MU10_EMPTY();
      } else {
         L1_MU10_EMPTY() = 0;
      }
      if( parent.L1_MU10_FIRSTEMPTY.IsAvailable() ) {
         L1_MU10_FIRSTEMPTY() = parent.L1_MU10_FIRSTEMPTY();
      } else {
         L1_MU10_FIRSTEMPTY() = 0;
      }
      if( parent.L1_MU10_J20.IsAvailable() ) {
         L1_MU10_J20() = parent.L1_MU10_J20();
      } else {
         L1_MU10_J20() = 0;
      }
      if( parent.L1_MU10_UNPAIRED_ISO.IsAvailable() ) {
         L1_MU10_UNPAIRED_ISO() = parent.L1_MU10_UNPAIRED_ISO();
      } else {
         L1_MU10_UNPAIRED_ISO() = 0;
      }
      if( parent.L1_MU10_XE20.IsAvailable() ) {
         L1_MU10_XE20() = parent.L1_MU10_XE20();
      } else {
         L1_MU10_XE20() = 0;
      }
      if( parent.L1_MU10_XE25.IsAvailable() ) {
         L1_MU10_XE25() = parent.L1_MU10_XE25();
      } else {
         L1_MU10_XE25() = 0;
      }
      if( parent.L1_MU11.IsAvailable() ) {
         L1_MU11() = parent.L1_MU11();
      } else {
         L1_MU11() = 0;
      }
      if( parent.L1_MU11_EMPTY.IsAvailable() ) {
         L1_MU11_EMPTY() = parent.L1_MU11_EMPTY();
      } else {
         L1_MU11_EMPTY() = 0;
      }
      if( parent.L1_MU15.IsAvailable() ) {
         L1_MU15() = parent.L1_MU15();
      } else {
         L1_MU15() = 0;
      }
      if( parent.L1_MU20.IsAvailable() ) {
         L1_MU20() = parent.L1_MU20();
      } else {
         L1_MU20() = 0;
      }
      if( parent.L1_MU20_FIRSTEMPTY.IsAvailable() ) {
         L1_MU20_FIRSTEMPTY() = parent.L1_MU20_FIRSTEMPTY();
      } else {
         L1_MU20_FIRSTEMPTY() = 0;
      }
      if( parent.L1_MU4.IsAvailable() ) {
         L1_MU4() = parent.L1_MU4();
      } else {
         L1_MU4() = 0;
      }
      if( parent.L1_MU4_EMPTY.IsAvailable() ) {
         L1_MU4_EMPTY() = parent.L1_MU4_EMPTY();
      } else {
         L1_MU4_EMPTY() = 0;
      }
      if( parent.L1_MU4_FIRSTEMPTY.IsAvailable() ) {
         L1_MU4_FIRSTEMPTY() = parent.L1_MU4_FIRSTEMPTY();
      } else {
         L1_MU4_FIRSTEMPTY() = 0;
      }
      if( parent.L1_MU4_J10.IsAvailable() ) {
         L1_MU4_J10() = parent.L1_MU4_J10();
      } else {
         L1_MU4_J10() = 0;
      }
      if( parent.L1_MU4_J15.IsAvailable() ) {
         L1_MU4_J15() = parent.L1_MU4_J15();
      } else {
         L1_MU4_J15() = 0;
      }
      if( parent.L1_MU4_J15_EMPTY.IsAvailable() ) {
         L1_MU4_J15_EMPTY() = parent.L1_MU4_J15_EMPTY();
      } else {
         L1_MU4_J15_EMPTY() = 0;
      }
      if( parent.L1_MU4_J15_UNPAIRED_ISO.IsAvailable() ) {
         L1_MU4_J15_UNPAIRED_ISO() = parent.L1_MU4_J15_UNPAIRED_ISO();
      } else {
         L1_MU4_J15_UNPAIRED_ISO() = 0;
      }
      if( parent.L1_MU4_J20_XE20.IsAvailable() ) {
         L1_MU4_J20_XE20() = parent.L1_MU4_J20_XE20();
      } else {
         L1_MU4_J20_XE20() = 0;
      }
      if( parent.L1_MU4_J20_XE35.IsAvailable() ) {
         L1_MU4_J20_XE35() = parent.L1_MU4_J20_XE35();
      } else {
         L1_MU4_J20_XE35() = 0;
      }
      if( parent.L1_MU4_J30.IsAvailable() ) {
         L1_MU4_J30() = parent.L1_MU4_J30();
      } else {
         L1_MU4_J30() = 0;
      }
      if( parent.L1_MU4_J50.IsAvailable() ) {
         L1_MU4_J50() = parent.L1_MU4_J50();
      } else {
         L1_MU4_J50() = 0;
      }
      if( parent.L1_MU4_J75.IsAvailable() ) {
         L1_MU4_J75() = parent.L1_MU4_J75();
      } else {
         L1_MU4_J75() = 0;
      }
      if( parent.L1_MU4_UNPAIRED_ISO.IsAvailable() ) {
         L1_MU4_UNPAIRED_ISO() = parent.L1_MU4_UNPAIRED_ISO();
      } else {
         L1_MU4_UNPAIRED_ISO() = 0;
      }
      if( parent.L1_MU4_UNPAIRED_NONISO.IsAvailable() ) {
         L1_MU4_UNPAIRED_NONISO() = parent.L1_MU4_UNPAIRED_NONISO();
      } else {
         L1_MU4_UNPAIRED_NONISO() = 0;
      }
      if( parent.L1_MU6.IsAvailable() ) {
         L1_MU6() = parent.L1_MU6();
      } else {
         L1_MU6() = 0;
      }
      if( parent.L1_MU6_2J20.IsAvailable() ) {
         L1_MU6_2J20() = parent.L1_MU6_2J20();
      } else {
         L1_MU6_2J20() = 0;
      }
      if( parent.L1_MU6_FIRSTEMPTY.IsAvailable() ) {
         L1_MU6_FIRSTEMPTY() = parent.L1_MU6_FIRSTEMPTY();
      } else {
         L1_MU6_FIRSTEMPTY() = 0;
      }
      if( parent.L1_MU6_J15.IsAvailable() ) {
         L1_MU6_J15() = parent.L1_MU6_J15();
      } else {
         L1_MU6_J15() = 0;
      }
      if( parent.L1_MUB.IsAvailable() ) {
         L1_MUB() = parent.L1_MUB();
      } else {
         L1_MUB() = 0;
      }
      if( parent.L1_MUE.IsAvailable() ) {
         L1_MUE() = parent.L1_MUE();
      } else {
         L1_MUE() = 0;
      }
      if( parent.L1_TAU11.IsAvailable() ) {
         L1_TAU11() = parent.L1_TAU11();
      } else {
         L1_TAU11() = 0;
      }
      if( parent.L1_TAU11I.IsAvailable() ) {
         L1_TAU11I() = parent.L1_TAU11I();
      } else {
         L1_TAU11I() = 0;
      }
      if( parent.L1_TAU11_MU10.IsAvailable() ) {
         L1_TAU11_MU10() = parent.L1_TAU11_MU10();
      } else {
         L1_TAU11_MU10() = 0;
      }
      if( parent.L1_TAU11_XE20.IsAvailable() ) {
         L1_TAU11_XE20() = parent.L1_TAU11_XE20();
      } else {
         L1_TAU11_XE20() = 0;
      }
      if( parent.L1_TAU15.IsAvailable() ) {
         L1_TAU15() = parent.L1_TAU15();
      } else {
         L1_TAU15() = 0;
      }
      if( parent.L1_TAU15I.IsAvailable() ) {
         L1_TAU15I() = parent.L1_TAU15I();
      } else {
         L1_TAU15I() = 0;
      }
      if( parent.L1_TAU15I_XE35.IsAvailable() ) {
         L1_TAU15I_XE35() = parent.L1_TAU15I_XE35();
      } else {
         L1_TAU15I_XE35() = 0;
      }
      if( parent.L1_TAU15I_XE40.IsAvailable() ) {
         L1_TAU15I_XE40() = parent.L1_TAU15I_XE40();
      } else {
         L1_TAU15I_XE40() = 0;
      }
      if( parent.L1_TAU15_XE25_3J10.IsAvailable() ) {
         L1_TAU15_XE25_3J10() = parent.L1_TAU15_XE25_3J10();
      } else {
         L1_TAU15_XE25_3J10() = 0;
      }
      if( parent.L1_TAU15_XE25_3J10_J30.IsAvailable() ) {
         L1_TAU15_XE25_3J10_J30() = parent.L1_TAU15_XE25_3J10_J30();
      } else {
         L1_TAU15_XE25_3J10_J30() = 0;
      }
      if( parent.L1_TAU15_XE25_3J15.IsAvailable() ) {
         L1_TAU15_XE25_3J15() = parent.L1_TAU15_XE25_3J15();
      } else {
         L1_TAU15_XE25_3J15() = 0;
      }
      if( parent.L1_TAU15_XE35.IsAvailable() ) {
         L1_TAU15_XE35() = parent.L1_TAU15_XE35();
      } else {
         L1_TAU15_XE35() = 0;
      }
      if( parent.L1_TAU15_XE40.IsAvailable() ) {
         L1_TAU15_XE40() = parent.L1_TAU15_XE40();
      } else {
         L1_TAU15_XE40() = 0;
      }
      if( parent.L1_TAU15_XS25_3J10.IsAvailable() ) {
         L1_TAU15_XS25_3J10() = parent.L1_TAU15_XS25_3J10();
      } else {
         L1_TAU15_XS25_3J10() = 0;
      }
      if( parent.L1_TAU15_XS35.IsAvailable() ) {
         L1_TAU15_XS35() = parent.L1_TAU15_XS35();
      } else {
         L1_TAU15_XS35() = 0;
      }
      if( parent.L1_TAU20.IsAvailable() ) {
         L1_TAU20() = parent.L1_TAU20();
      } else {
         L1_TAU20() = 0;
      }
      if( parent.L1_TAU20_XE35.IsAvailable() ) {
         L1_TAU20_XE35() = parent.L1_TAU20_XE35();
      } else {
         L1_TAU20_XE35() = 0;
      }
      if( parent.L1_TAU20_XE40.IsAvailable() ) {
         L1_TAU20_XE40() = parent.L1_TAU20_XE40();
      } else {
         L1_TAU20_XE40() = 0;
      }
      if( parent.L1_TAU40.IsAvailable() ) {
         L1_TAU40() = parent.L1_TAU40();
      } else {
         L1_TAU40() = 0;
      }
      if( parent.L1_TAU8.IsAvailable() ) {
         L1_TAU8() = parent.L1_TAU8();
      } else {
         L1_TAU8() = 0;
      }
      if( parent.L1_TAU8_EMPTY.IsAvailable() ) {
         L1_TAU8_EMPTY() = parent.L1_TAU8_EMPTY();
      } else {
         L1_TAU8_EMPTY() = 0;
      }
      if( parent.L1_TAU8_FIRSTEMPTY.IsAvailable() ) {
         L1_TAU8_FIRSTEMPTY() = parent.L1_TAU8_FIRSTEMPTY();
      } else {
         L1_TAU8_FIRSTEMPTY() = 0;
      }
      if( parent.L1_TAU8_MU10.IsAvailable() ) {
         L1_TAU8_MU10() = parent.L1_TAU8_MU10();
      } else {
         L1_TAU8_MU10() = 0;
      }
      if( parent.L1_TAU8_UNPAIRED_ISO.IsAvailable() ) {
         L1_TAU8_UNPAIRED_ISO() = parent.L1_TAU8_UNPAIRED_ISO();
      } else {
         L1_TAU8_UNPAIRED_ISO() = 0;
      }
      if( parent.L1_TAU8_UNPAIRED_NONISO.IsAvailable() ) {
         L1_TAU8_UNPAIRED_NONISO() = parent.L1_TAU8_UNPAIRED_NONISO();
      } else {
         L1_TAU8_UNPAIRED_NONISO() = 0;
      }
      if( parent.L1_XE20.IsAvailable() ) {
         L1_XE20() = parent.L1_XE20();
      } else {
         L1_XE20() = 0;
      }
      if( parent.L1_XE25.IsAvailable() ) {
         L1_XE25() = parent.L1_XE25();
      } else {
         L1_XE25() = 0;
      }
      if( parent.L1_XE30.IsAvailable() ) {
         L1_XE30() = parent.L1_XE30();
      } else {
         L1_XE30() = 0;
      }
      if( parent.L1_XE35.IsAvailable() ) {
         L1_XE35() = parent.L1_XE35();
      } else {
         L1_XE35() = 0;
      }
      if( parent.L1_XE40.IsAvailable() ) {
         L1_XE40() = parent.L1_XE40();
      } else {
         L1_XE40() = 0;
      }
      if( parent.L1_XE40_BGRP7.IsAvailable() ) {
         L1_XE40_BGRP7() = parent.L1_XE40_BGRP7();
      } else {
         L1_XE40_BGRP7() = 0;
      }
      if( parent.L1_XE50.IsAvailable() ) {
         L1_XE50() = parent.L1_XE50();
      } else {
         L1_XE50() = 0;
      }
      if( parent.L1_XE50_BGRP7.IsAvailable() ) {
         L1_XE50_BGRP7() = parent.L1_XE50_BGRP7();
      } else {
         L1_XE50_BGRP7() = 0;
      }
      if( parent.L1_XE60.IsAvailable() ) {
         L1_XE60() = parent.L1_XE60();
      } else {
         L1_XE60() = 0;
      }
      if( parent.L1_XE70.IsAvailable() ) {
         L1_XE70() = parent.L1_XE70();
      } else {
         L1_XE70() = 0;
      }
      if( parent.L2_2e12Tvh_loose1.IsAvailable() ) {
         L2_2e12Tvh_loose1() = parent.L2_2e12Tvh_loose1();
      } else {
         L2_2e12Tvh_loose1() = 0;
      }
      if( parent.L2_2e5_tight1_Jpsi.IsAvailable() ) {
         L2_2e5_tight1_Jpsi() = parent.L2_2e5_tight1_Jpsi();
      } else {
         L2_2e5_tight1_Jpsi() = 0;
      }
      if( parent.L2_2e7T_loose1_mu6.IsAvailable() ) {
         L2_2e7T_loose1_mu6() = parent.L2_2e7T_loose1_mu6();
      } else {
         L2_2e7T_loose1_mu6() = 0;
      }
      if( parent.L2_2e7T_medium1_mu6.IsAvailable() ) {
         L2_2e7T_medium1_mu6() = parent.L2_2e7T_medium1_mu6();
      } else {
         L2_2e7T_medium1_mu6() = 0;
      }
      if( parent.L2_2g15vh_loose_g10_loose.IsAvailable() ) {
         L2_2g15vh_loose_g10_loose() = parent.L2_2g15vh_loose_g10_loose();
      } else {
         L2_2g15vh_loose_g10_loose() = 0;
      }
      if( parent.L2_2g15vh_medium.IsAvailable() ) {
         L2_2g15vh_medium() = parent.L2_2g15vh_medium();
      } else {
         L2_2g15vh_medium() = 0;
      }
      if( parent.L2_2g15vh_medium_g10_medium.IsAvailable() ) {
         L2_2g15vh_medium_g10_medium() = parent.L2_2g15vh_medium_g10_medium();
      } else {
         L2_2g15vh_medium_g10_medium() = 0;
      }
      if( parent.L2_2g20_loose.IsAvailable() ) {
         L2_2g20_loose() = parent.L2_2g20_loose();
      } else {
         L2_2g20_loose() = 0;
      }
      if( parent.L2_2g20vh_medium.IsAvailable() ) {
         L2_2g20vh_medium() = parent.L2_2g20vh_medium();
      } else {
         L2_2g20vh_medium() = 0;
      }
      if( parent.L2_2g30_loose.IsAvailable() ) {
         L2_2g30_loose() = parent.L2_2g30_loose();
      } else {
         L2_2g30_loose() = 0;
      }
      if( parent.L2_2g40_loose.IsAvailable() ) {
         L2_2g40_loose() = parent.L2_2g40_loose();
      } else {
         L2_2g40_loose() = 0;
      }
      if( parent.L2_2mu10.IsAvailable() ) {
         L2_2mu10() = parent.L2_2mu10();
      } else {
         L2_2mu10() = 0;
      }
      if( parent.L2_2mu10_MSonly_g10_loose.IsAvailable() ) {
         L2_2mu10_MSonly_g10_loose() = parent.L2_2mu10_MSonly_g10_loose();
      } else {
         L2_2mu10_MSonly_g10_loose() = 0;
      }
      if( parent.L2_2mu10_MSonly_g10_loose_EMPTY.IsAvailable() ) {
         L2_2mu10_MSonly_g10_loose_EMPTY() = parent.L2_2mu10_MSonly_g10_loose_EMPTY();
      } else {
         L2_2mu10_MSonly_g10_loose_EMPTY() = 0;
      }
      if( parent.L2_2mu10_MSonly_g10_loose_UNPAIRED_ISO.IsAvailable() ) {
         L2_2mu10_MSonly_g10_loose_UNPAIRED_ISO() = parent.L2_2mu10_MSonly_g10_loose_UNPAIRED_ISO();
      } else {
         L2_2mu10_MSonly_g10_loose_UNPAIRED_ISO() = 0;
      }
      if( parent.L2_2mu13.IsAvailable() ) {
         L2_2mu13() = parent.L2_2mu13();
      } else {
         L2_2mu13() = 0;
      }
      if( parent.L2_2mu13_Zmumu_IDTrkNoCut.IsAvailable() ) {
         L2_2mu13_Zmumu_IDTrkNoCut() = parent.L2_2mu13_Zmumu_IDTrkNoCut();
      } else {
         L2_2mu13_Zmumu_IDTrkNoCut() = 0;
      }
      if( parent.L2_2mu13_l2muonSA.IsAvailable() ) {
         L2_2mu13_l2muonSA() = parent.L2_2mu13_l2muonSA();
      } else {
         L2_2mu13_l2muonSA() = 0;
      }
      if( parent.L2_2mu15.IsAvailable() ) {
         L2_2mu15() = parent.L2_2mu15();
      } else {
         L2_2mu15() = 0;
      }
      if( parent.L2_2mu4T.IsAvailable() ) {
         L2_2mu4T() = parent.L2_2mu4T();
      } else {
         L2_2mu4T() = 0;
      }
      if( parent.L2_2mu4T_2e5_tight1.IsAvailable() ) {
         L2_2mu4T_2e5_tight1() = parent.L2_2mu4T_2e5_tight1();
      } else {
         L2_2mu4T_2e5_tight1() = 0;
      }
      if( parent.L2_2mu4T_Bmumu.IsAvailable() ) {
         L2_2mu4T_Bmumu() = parent.L2_2mu4T_Bmumu();
      } else {
         L2_2mu4T_Bmumu() = 0;
      }
      if( parent.L2_2mu4T_Bmumu_Barrel.IsAvailable() ) {
         L2_2mu4T_Bmumu_Barrel() = parent.L2_2mu4T_Bmumu_Barrel();
      } else {
         L2_2mu4T_Bmumu_Barrel() = 0;
      }
      if( parent.L2_2mu4T_Bmumu_BarrelOnly.IsAvailable() ) {
         L2_2mu4T_Bmumu_BarrelOnly() = parent.L2_2mu4T_Bmumu_BarrelOnly();
      } else {
         L2_2mu4T_Bmumu_BarrelOnly() = 0;
      }
      if( parent.L2_2mu4T_Bmumux.IsAvailable() ) {
         L2_2mu4T_Bmumux() = parent.L2_2mu4T_Bmumux();
      } else {
         L2_2mu4T_Bmumux() = 0;
      }
      if( parent.L2_2mu4T_Bmumux_Barrel.IsAvailable() ) {
         L2_2mu4T_Bmumux_Barrel() = parent.L2_2mu4T_Bmumux_Barrel();
      } else {
         L2_2mu4T_Bmumux_Barrel() = 0;
      }
      if( parent.L2_2mu4T_Bmumux_BarrelOnly.IsAvailable() ) {
         L2_2mu4T_Bmumux_BarrelOnly() = parent.L2_2mu4T_Bmumux_BarrelOnly();
      } else {
         L2_2mu4T_Bmumux_BarrelOnly() = 0;
      }
      if( parent.L2_2mu4T_DiMu.IsAvailable() ) {
         L2_2mu4T_DiMu() = parent.L2_2mu4T_DiMu();
      } else {
         L2_2mu4T_DiMu() = 0;
      }
      if( parent.L2_2mu4T_DiMu_Barrel.IsAvailable() ) {
         L2_2mu4T_DiMu_Barrel() = parent.L2_2mu4T_DiMu_Barrel();
      } else {
         L2_2mu4T_DiMu_Barrel() = 0;
      }
      if( parent.L2_2mu4T_DiMu_BarrelOnly.IsAvailable() ) {
         L2_2mu4T_DiMu_BarrelOnly() = parent.L2_2mu4T_DiMu_BarrelOnly();
      } else {
         L2_2mu4T_DiMu_BarrelOnly() = 0;
      }
      if( parent.L2_2mu4T_DiMu_L2StarB.IsAvailable() ) {
         L2_2mu4T_DiMu_L2StarB() = parent.L2_2mu4T_DiMu_L2StarB();
      } else {
         L2_2mu4T_DiMu_L2StarB() = 0;
      }
      if( parent.L2_2mu4T_DiMu_L2StarC.IsAvailable() ) {
         L2_2mu4T_DiMu_L2StarC() = parent.L2_2mu4T_DiMu_L2StarC();
      } else {
         L2_2mu4T_DiMu_L2StarC() = 0;
      }
      if( parent.L2_2mu4T_DiMu_e5_tight1.IsAvailable() ) {
         L2_2mu4T_DiMu_e5_tight1() = parent.L2_2mu4T_DiMu_e5_tight1();
      } else {
         L2_2mu4T_DiMu_e5_tight1() = 0;
      }
      if( parent.L2_2mu4T_DiMu_l2muonSA.IsAvailable() ) {
         L2_2mu4T_DiMu_l2muonSA() = parent.L2_2mu4T_DiMu_l2muonSA();
      } else {
         L2_2mu4T_DiMu_l2muonSA() = 0;
      }
      if( parent.L2_2mu4T_DiMu_noVtx_noOS.IsAvailable() ) {
         L2_2mu4T_DiMu_noVtx_noOS() = parent.L2_2mu4T_DiMu_noVtx_noOS();
      } else {
         L2_2mu4T_DiMu_noVtx_noOS() = 0;
      }
      if( parent.L2_2mu4T_Jpsimumu.IsAvailable() ) {
         L2_2mu4T_Jpsimumu() = parent.L2_2mu4T_Jpsimumu();
      } else {
         L2_2mu4T_Jpsimumu() = 0;
      }
      if( parent.L2_2mu4T_Jpsimumu_Barrel.IsAvailable() ) {
         L2_2mu4T_Jpsimumu_Barrel() = parent.L2_2mu4T_Jpsimumu_Barrel();
      } else {
         L2_2mu4T_Jpsimumu_Barrel() = 0;
      }
      if( parent.L2_2mu4T_Jpsimumu_BarrelOnly.IsAvailable() ) {
         L2_2mu4T_Jpsimumu_BarrelOnly() = parent.L2_2mu4T_Jpsimumu_BarrelOnly();
      } else {
         L2_2mu4T_Jpsimumu_BarrelOnly() = 0;
      }
      if( parent.L2_2mu4T_Jpsimumu_IDTrkNoCut.IsAvailable() ) {
         L2_2mu4T_Jpsimumu_IDTrkNoCut() = parent.L2_2mu4T_Jpsimumu_IDTrkNoCut();
      } else {
         L2_2mu4T_Jpsimumu_IDTrkNoCut() = 0;
      }
      if( parent.L2_2mu4T_Upsimumu.IsAvailable() ) {
         L2_2mu4T_Upsimumu() = parent.L2_2mu4T_Upsimumu();
      } else {
         L2_2mu4T_Upsimumu() = 0;
      }
      if( parent.L2_2mu4T_Upsimumu_Barrel.IsAvailable() ) {
         L2_2mu4T_Upsimumu_Barrel() = parent.L2_2mu4T_Upsimumu_Barrel();
      } else {
         L2_2mu4T_Upsimumu_Barrel() = 0;
      }
      if( parent.L2_2mu4T_Upsimumu_BarrelOnly.IsAvailable() ) {
         L2_2mu4T_Upsimumu_BarrelOnly() = parent.L2_2mu4T_Upsimumu_BarrelOnly();
      } else {
         L2_2mu4T_Upsimumu_BarrelOnly() = 0;
      }
      if( parent.L2_2mu4T_xe35.IsAvailable() ) {
         L2_2mu4T_xe35() = parent.L2_2mu4T_xe35();
      } else {
         L2_2mu4T_xe35() = 0;
      }
      if( parent.L2_2mu4T_xe45.IsAvailable() ) {
         L2_2mu4T_xe45() = parent.L2_2mu4T_xe45();
      } else {
         L2_2mu4T_xe45() = 0;
      }
      if( parent.L2_2mu4T_xe60.IsAvailable() ) {
         L2_2mu4T_xe60() = parent.L2_2mu4T_xe60();
      } else {
         L2_2mu4T_xe60() = 0;
      }
      if( parent.L2_2mu6.IsAvailable() ) {
         L2_2mu6() = parent.L2_2mu6();
      } else {
         L2_2mu6() = 0;
      }
      if( parent.L2_2mu6_Bmumu.IsAvailable() ) {
         L2_2mu6_Bmumu() = parent.L2_2mu6_Bmumu();
      } else {
         L2_2mu6_Bmumu() = 0;
      }
      if( parent.L2_2mu6_Bmumux.IsAvailable() ) {
         L2_2mu6_Bmumux() = parent.L2_2mu6_Bmumux();
      } else {
         L2_2mu6_Bmumux() = 0;
      }
      if( parent.L2_2mu6_DiMu.IsAvailable() ) {
         L2_2mu6_DiMu() = parent.L2_2mu6_DiMu();
      } else {
         L2_2mu6_DiMu() = 0;
      }
      if( parent.L2_2mu6_DiMu_DY20.IsAvailable() ) {
         L2_2mu6_DiMu_DY20() = parent.L2_2mu6_DiMu_DY20();
      } else {
         L2_2mu6_DiMu_DY20() = 0;
      }
      if( parent.L2_2mu6_DiMu_DY25.IsAvailable() ) {
         L2_2mu6_DiMu_DY25() = parent.L2_2mu6_DiMu_DY25();
      } else {
         L2_2mu6_DiMu_DY25() = 0;
      }
      if( parent.L2_2mu6_DiMu_noVtx_noOS.IsAvailable() ) {
         L2_2mu6_DiMu_noVtx_noOS() = parent.L2_2mu6_DiMu_noVtx_noOS();
      } else {
         L2_2mu6_DiMu_noVtx_noOS() = 0;
      }
      if( parent.L2_2mu6_Jpsimumu.IsAvailable() ) {
         L2_2mu6_Jpsimumu() = parent.L2_2mu6_Jpsimumu();
      } else {
         L2_2mu6_Jpsimumu() = 0;
      }
      if( parent.L2_2mu6_Upsimumu.IsAvailable() ) {
         L2_2mu6_Upsimumu() = parent.L2_2mu6_Upsimumu();
      } else {
         L2_2mu6_Upsimumu() = 0;
      }
      if( parent.L2_2mu6i_DiMu_DY.IsAvailable() ) {
         L2_2mu6i_DiMu_DY() = parent.L2_2mu6i_DiMu_DY();
      } else {
         L2_2mu6i_DiMu_DY() = 0;
      }
      if( parent.L2_2mu6i_DiMu_DY_2j25_a4tchad.IsAvailable() ) {
         L2_2mu6i_DiMu_DY_2j25_a4tchad() = parent.L2_2mu6i_DiMu_DY_2j25_a4tchad();
      } else {
         L2_2mu6i_DiMu_DY_2j25_a4tchad() = 0;
      }
      if( parent.L2_2mu6i_DiMu_DY_noVtx_noOS.IsAvailable() ) {
         L2_2mu6i_DiMu_DY_noVtx_noOS() = parent.L2_2mu6i_DiMu_DY_noVtx_noOS();
      } else {
         L2_2mu6i_DiMu_DY_noVtx_noOS() = 0;
      }
      if( parent.L2_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.IsAvailable() ) {
         L2_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad() = parent.L2_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad();
      } else {
         L2_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad() = 0;
      }
      if( parent.L2_2mu8_EFxe30.IsAvailable() ) {
         L2_2mu8_EFxe30() = parent.L2_2mu8_EFxe30();
      } else {
         L2_2mu8_EFxe30() = 0;
      }
      if( parent.L2_2tau29T_medium1.IsAvailable() ) {
         L2_2tau29T_medium1() = parent.L2_2tau29T_medium1();
      } else {
         L2_2tau29T_medium1() = 0;
      }
      if( parent.L2_2tau29_medium1.IsAvailable() ) {
         L2_2tau29_medium1() = parent.L2_2tau29_medium1();
      } else {
         L2_2tau29_medium1() = 0;
      }
      if( parent.L2_2tau29i_medium1.IsAvailable() ) {
         L2_2tau29i_medium1() = parent.L2_2tau29i_medium1();
      } else {
         L2_2tau29i_medium1() = 0;
      }
      if( parent.L2_2tau38T_medium.IsAvailable() ) {
         L2_2tau38T_medium() = parent.L2_2tau38T_medium();
      } else {
         L2_2tau38T_medium() = 0;
      }
      if( parent.L2_2tau38T_medium1.IsAvailable() ) {
         L2_2tau38T_medium1() = parent.L2_2tau38T_medium1();
      } else {
         L2_2tau38T_medium1() = 0;
      }
      if( parent.L2_2tau38T_medium1_llh.IsAvailable() ) {
         L2_2tau38T_medium1_llh() = parent.L2_2tau38T_medium1_llh();
      } else {
         L2_2tau38T_medium1_llh() = 0;
      }
      if( parent.L2_b105_loose_j105_c4cchad_xe40.IsAvailable() ) {
         L2_b105_loose_j105_c4cchad_xe40() = parent.L2_b105_loose_j105_c4cchad_xe40();
      } else {
         L2_b105_loose_j105_c4cchad_xe40() = 0;
      }
      if( parent.L2_b105_loose_j105_c4cchad_xe45.IsAvailable() ) {
         L2_b105_loose_j105_c4cchad_xe45() = parent.L2_b105_loose_j105_c4cchad_xe45();
      } else {
         L2_b105_loose_j105_c4cchad_xe45() = 0;
      }
      if( parent.L2_b75_loose_j75_c4cchad_xe40.IsAvailable() ) {
         L2_b75_loose_j75_c4cchad_xe40() = parent.L2_b75_loose_j75_c4cchad_xe40();
      } else {
         L2_b75_loose_j75_c4cchad_xe40() = 0;
      }
      if( parent.L2_b75_loose_j75_c4cchad_xe45.IsAvailable() ) {
         L2_b75_loose_j75_c4cchad_xe45() = parent.L2_b75_loose_j75_c4cchad_xe45();
      } else {
         L2_b75_loose_j75_c4cchad_xe45() = 0;
      }
      if( parent.L2_b75_loose_j75_c4cchad_xe55.IsAvailable() ) {
         L2_b75_loose_j75_c4cchad_xe55() = parent.L2_b75_loose_j75_c4cchad_xe55();
      } else {
         L2_b75_loose_j75_c4cchad_xe55() = 0;
      }
      if( parent.L2_e11_etcut.IsAvailable() ) {
         L2_e11_etcut() = parent.L2_e11_etcut();
      } else {
         L2_e11_etcut() = 0;
      }
      if( parent.L2_e12Tvh_loose1.IsAvailable() ) {
         L2_e12Tvh_loose1() = parent.L2_e12Tvh_loose1();
      } else {
         L2_e12Tvh_loose1() = 0;
      }
      if( parent.L2_e12Tvh_loose1_mu8.IsAvailable() ) {
         L2_e12Tvh_loose1_mu8() = parent.L2_e12Tvh_loose1_mu8();
      } else {
         L2_e12Tvh_loose1_mu8() = 0;
      }
      if( parent.L2_e12Tvh_medium1.IsAvailable() ) {
         L2_e12Tvh_medium1() = parent.L2_e12Tvh_medium1();
      } else {
         L2_e12Tvh_medium1() = 0;
      }
      if( parent.L2_e12Tvh_medium1_mu10.IsAvailable() ) {
         L2_e12Tvh_medium1_mu10() = parent.L2_e12Tvh_medium1_mu10();
      } else {
         L2_e12Tvh_medium1_mu10() = 0;
      }
      if( parent.L2_e12Tvh_medium1_mu6.IsAvailable() ) {
         L2_e12Tvh_medium1_mu6() = parent.L2_e12Tvh_medium1_mu6();
      } else {
         L2_e12Tvh_medium1_mu6() = 0;
      }
      if( parent.L2_e12Tvh_medium1_mu6_topo_medium.IsAvailable() ) {
         L2_e12Tvh_medium1_mu6_topo_medium() = parent.L2_e12Tvh_medium1_mu6_topo_medium();
      } else {
         L2_e12Tvh_medium1_mu6_topo_medium() = 0;
      }
      if( parent.L2_e12Tvh_medium1_mu8.IsAvailable() ) {
         L2_e12Tvh_medium1_mu8() = parent.L2_e12Tvh_medium1_mu8();
      } else {
         L2_e12Tvh_medium1_mu8() = 0;
      }
      if( parent.L2_e13_etcutTrk_xs45.IsAvailable() ) {
         L2_e13_etcutTrk_xs45() = parent.L2_e13_etcutTrk_xs45();
      } else {
         L2_e13_etcutTrk_xs45() = 0;
      }
      if( parent.L2_e14_tight1_e4_etcut_Jpsi.IsAvailable() ) {
         L2_e14_tight1_e4_etcut_Jpsi() = parent.L2_e14_tight1_e4_etcut_Jpsi();
      } else {
         L2_e14_tight1_e4_etcut_Jpsi() = 0;
      }
      if( parent.L2_e15vh_medium1.IsAvailable() ) {
         L2_e15vh_medium1() = parent.L2_e15vh_medium1();
      } else {
         L2_e15vh_medium1() = 0;
      }
      if( parent.L2_e18_loose1.IsAvailable() ) {
         L2_e18_loose1() = parent.L2_e18_loose1();
      } else {
         L2_e18_loose1() = 0;
      }
      if( parent.L2_e18_loose1_g25_medium.IsAvailable() ) {
         L2_e18_loose1_g25_medium() = parent.L2_e18_loose1_g25_medium();
      } else {
         L2_e18_loose1_g25_medium() = 0;
      }
      if( parent.L2_e18_loose1_g35_loose.IsAvailable() ) {
         L2_e18_loose1_g35_loose() = parent.L2_e18_loose1_g35_loose();
      } else {
         L2_e18_loose1_g35_loose() = 0;
      }
      if( parent.L2_e18_loose1_g35_medium.IsAvailable() ) {
         L2_e18_loose1_g35_medium() = parent.L2_e18_loose1_g35_medium();
      } else {
         L2_e18_loose1_g35_medium() = 0;
      }
      if( parent.L2_e18_medium1.IsAvailable() ) {
         L2_e18_medium1() = parent.L2_e18_medium1();
      } else {
         L2_e18_medium1() = 0;
      }
      if( parent.L2_e18_medium1_g25_loose.IsAvailable() ) {
         L2_e18_medium1_g25_loose() = parent.L2_e18_medium1_g25_loose();
      } else {
         L2_e18_medium1_g25_loose() = 0;
      }
      if( parent.L2_e18_medium1_g25_medium.IsAvailable() ) {
         L2_e18_medium1_g25_medium() = parent.L2_e18_medium1_g25_medium();
      } else {
         L2_e18_medium1_g25_medium() = 0;
      }
      if( parent.L2_e18_medium1_g35_loose.IsAvailable() ) {
         L2_e18_medium1_g35_loose() = parent.L2_e18_medium1_g35_loose();
      } else {
         L2_e18_medium1_g35_loose() = 0;
      }
      if( parent.L2_e18_medium1_g35_medium.IsAvailable() ) {
         L2_e18_medium1_g35_medium() = parent.L2_e18_medium1_g35_medium();
      } else {
         L2_e18_medium1_g35_medium() = 0;
      }
      if( parent.L2_e18vh_medium1.IsAvailable() ) {
         L2_e18vh_medium1() = parent.L2_e18vh_medium1();
      } else {
         L2_e18vh_medium1() = 0;
      }
      if( parent.L2_e18vh_medium1_2e7T_medium1.IsAvailable() ) {
         L2_e18vh_medium1_2e7T_medium1() = parent.L2_e18vh_medium1_2e7T_medium1();
      } else {
         L2_e18vh_medium1_2e7T_medium1() = 0;
      }
      if( parent.L2_e20_etcutTrk_xe25.IsAvailable() ) {
         L2_e20_etcutTrk_xe25() = parent.L2_e20_etcutTrk_xe25();
      } else {
         L2_e20_etcutTrk_xe25() = 0;
      }
      if( parent.L2_e20_etcutTrk_xs45.IsAvailable() ) {
         L2_e20_etcutTrk_xs45() = parent.L2_e20_etcutTrk_xs45();
      } else {
         L2_e20_etcutTrk_xs45() = 0;
      }
      if( parent.L2_e20vhT_medium1_g6T_etcut_Upsi.IsAvailable() ) {
         L2_e20vhT_medium1_g6T_etcut_Upsi() = parent.L2_e20vhT_medium1_g6T_etcut_Upsi();
      } else {
         L2_e20vhT_medium1_g6T_etcut_Upsi() = 0;
      }
      if( parent.L2_e20vhT_tight1_g6T_etcut_Upsi.IsAvailable() ) {
         L2_e20vhT_tight1_g6T_etcut_Upsi() = parent.L2_e20vhT_tight1_g6T_etcut_Upsi();
      } else {
         L2_e20vhT_tight1_g6T_etcut_Upsi() = 0;
      }
      if( parent.L2_e22vh_loose.IsAvailable() ) {
         L2_e22vh_loose() = parent.L2_e22vh_loose();
      } else {
         L2_e22vh_loose() = 0;
      }
      if( parent.L2_e22vh_loose0.IsAvailable() ) {
         L2_e22vh_loose0() = parent.L2_e22vh_loose0();
      } else {
         L2_e22vh_loose0() = 0;
      }
      if( parent.L2_e22vh_loose1.IsAvailable() ) {
         L2_e22vh_loose1() = parent.L2_e22vh_loose1();
      } else {
         L2_e22vh_loose1() = 0;
      }
      if( parent.L2_e22vh_medium1.IsAvailable() ) {
         L2_e22vh_medium1() = parent.L2_e22vh_medium1();
      } else {
         L2_e22vh_medium1() = 0;
      }
      if( parent.L2_e22vh_medium1_IDTrkNoCut.IsAvailable() ) {
         L2_e22vh_medium1_IDTrkNoCut() = parent.L2_e22vh_medium1_IDTrkNoCut();
      } else {
         L2_e22vh_medium1_IDTrkNoCut() = 0;
      }
      if( parent.L2_e22vh_medium1_IdScan.IsAvailable() ) {
         L2_e22vh_medium1_IdScan() = parent.L2_e22vh_medium1_IdScan();
      } else {
         L2_e22vh_medium1_IdScan() = 0;
      }
      if( parent.L2_e22vh_medium1_SiTrk.IsAvailable() ) {
         L2_e22vh_medium1_SiTrk() = parent.L2_e22vh_medium1_SiTrk();
      } else {
         L2_e22vh_medium1_SiTrk() = 0;
      }
      if( parent.L2_e22vh_medium1_TRT.IsAvailable() ) {
         L2_e22vh_medium1_TRT() = parent.L2_e22vh_medium1_TRT();
      } else {
         L2_e22vh_medium1_TRT() = 0;
      }
      if( parent.L2_e22vhi_medium1.IsAvailable() ) {
         L2_e22vhi_medium1() = parent.L2_e22vhi_medium1();
      } else {
         L2_e22vhi_medium1() = 0;
      }
      if( parent.L2_e24vh_loose.IsAvailable() ) {
         L2_e24vh_loose() = parent.L2_e24vh_loose();
      } else {
         L2_e24vh_loose() = 0;
      }
      if( parent.L2_e24vh_loose0.IsAvailable() ) {
         L2_e24vh_loose0() = parent.L2_e24vh_loose0();
      } else {
         L2_e24vh_loose0() = 0;
      }
      if( parent.L2_e24vh_loose1.IsAvailable() ) {
         L2_e24vh_loose1() = parent.L2_e24vh_loose1();
      } else {
         L2_e24vh_loose1() = 0;
      }
      if( parent.L2_e24vh_medium1.IsAvailable() ) {
         L2_e24vh_medium1() = parent.L2_e24vh_medium1();
      } else {
         L2_e24vh_medium1() = 0;
      }
      if( parent.L2_e24vh_medium1_EFxe30.IsAvailable() ) {
         L2_e24vh_medium1_EFxe30() = parent.L2_e24vh_medium1_EFxe30();
      } else {
         L2_e24vh_medium1_EFxe30() = 0;
      }
      if( parent.L2_e24vh_medium1_EFxe35.IsAvailable() ) {
         L2_e24vh_medium1_EFxe35() = parent.L2_e24vh_medium1_EFxe35();
      } else {
         L2_e24vh_medium1_EFxe35() = 0;
      }
      if( parent.L2_e24vh_medium1_EFxe40.IsAvailable() ) {
         L2_e24vh_medium1_EFxe40() = parent.L2_e24vh_medium1_EFxe40();
      } else {
         L2_e24vh_medium1_EFxe40() = 0;
      }
      if( parent.L2_e24vh_medium1_IDTrkNoCut.IsAvailable() ) {
         L2_e24vh_medium1_IDTrkNoCut() = parent.L2_e24vh_medium1_IDTrkNoCut();
      } else {
         L2_e24vh_medium1_IDTrkNoCut() = 0;
      }
      if( parent.L2_e24vh_medium1_IdScan.IsAvailable() ) {
         L2_e24vh_medium1_IdScan() = parent.L2_e24vh_medium1_IdScan();
      } else {
         L2_e24vh_medium1_IdScan() = 0;
      }
      if( parent.L2_e24vh_medium1_L2StarB.IsAvailable() ) {
         L2_e24vh_medium1_L2StarB() = parent.L2_e24vh_medium1_L2StarB();
      } else {
         L2_e24vh_medium1_L2StarB() = 0;
      }
      if( parent.L2_e24vh_medium1_L2StarC.IsAvailable() ) {
         L2_e24vh_medium1_L2StarC() = parent.L2_e24vh_medium1_L2StarC();
      } else {
         L2_e24vh_medium1_L2StarC() = 0;
      }
      if( parent.L2_e24vh_medium1_SiTrk.IsAvailable() ) {
         L2_e24vh_medium1_SiTrk() = parent.L2_e24vh_medium1_SiTrk();
      } else {
         L2_e24vh_medium1_SiTrk() = 0;
      }
      if( parent.L2_e24vh_medium1_TRT.IsAvailable() ) {
         L2_e24vh_medium1_TRT() = parent.L2_e24vh_medium1_TRT();
      } else {
         L2_e24vh_medium1_TRT() = 0;
      }
      if( parent.L2_e24vh_medium1_e7_medium1.IsAvailable() ) {
         L2_e24vh_medium1_e7_medium1() = parent.L2_e24vh_medium1_e7_medium1();
      } else {
         L2_e24vh_medium1_e7_medium1() = 0;
      }
      if( parent.L2_e24vh_tight1_e15_NoCut_Zee.IsAvailable() ) {
         L2_e24vh_tight1_e15_NoCut_Zee() = parent.L2_e24vh_tight1_e15_NoCut_Zee();
      } else {
         L2_e24vh_tight1_e15_NoCut_Zee() = 0;
      }
      if( parent.L2_e24vhi_loose1_mu8.IsAvailable() ) {
         L2_e24vhi_loose1_mu8() = parent.L2_e24vhi_loose1_mu8();
      } else {
         L2_e24vhi_loose1_mu8() = 0;
      }
      if( parent.L2_e24vhi_medium1.IsAvailable() ) {
         L2_e24vhi_medium1() = parent.L2_e24vhi_medium1();
      } else {
         L2_e24vhi_medium1() = 0;
      }
      if( parent.L2_e45_etcut.IsAvailable() ) {
         L2_e45_etcut() = parent.L2_e45_etcut();
      } else {
         L2_e45_etcut() = 0;
      }
      if( parent.L2_e45_loose1.IsAvailable() ) {
         L2_e45_loose1() = parent.L2_e45_loose1();
      } else {
         L2_e45_loose1() = 0;
      }
      if( parent.L2_e45_medium1.IsAvailable() ) {
         L2_e45_medium1() = parent.L2_e45_medium1();
      } else {
         L2_e45_medium1() = 0;
      }
      if( parent.L2_e5_tight1.IsAvailable() ) {
         L2_e5_tight1() = parent.L2_e5_tight1();
      } else {
         L2_e5_tight1() = 0;
      }
      if( parent.L2_e5_tight1_e14_etcut_Jpsi.IsAvailable() ) {
         L2_e5_tight1_e14_etcut_Jpsi() = parent.L2_e5_tight1_e14_etcut_Jpsi();
      } else {
         L2_e5_tight1_e14_etcut_Jpsi() = 0;
      }
      if( parent.L2_e5_tight1_e4_etcut_Jpsi.IsAvailable() ) {
         L2_e5_tight1_e4_etcut_Jpsi() = parent.L2_e5_tight1_e4_etcut_Jpsi();
      } else {
         L2_e5_tight1_e4_etcut_Jpsi() = 0;
      }
      if( parent.L2_e5_tight1_e4_etcut_Jpsi_IdScan.IsAvailable() ) {
         L2_e5_tight1_e4_etcut_Jpsi_IdScan() = parent.L2_e5_tight1_e4_etcut_Jpsi_IdScan();
      } else {
         L2_e5_tight1_e4_etcut_Jpsi_IdScan() = 0;
      }
      if( parent.L2_e5_tight1_e4_etcut_Jpsi_L2StarB.IsAvailable() ) {
         L2_e5_tight1_e4_etcut_Jpsi_L2StarB() = parent.L2_e5_tight1_e4_etcut_Jpsi_L2StarB();
      } else {
         L2_e5_tight1_e4_etcut_Jpsi_L2StarB() = 0;
      }
      if( parent.L2_e5_tight1_e4_etcut_Jpsi_L2StarC.IsAvailable() ) {
         L2_e5_tight1_e4_etcut_Jpsi_L2StarC() = parent.L2_e5_tight1_e4_etcut_Jpsi_L2StarC();
      } else {
         L2_e5_tight1_e4_etcut_Jpsi_L2StarC() = 0;
      }
      if( parent.L2_e5_tight1_e4_etcut_Jpsi_SiTrk.IsAvailable() ) {
         L2_e5_tight1_e4_etcut_Jpsi_SiTrk() = parent.L2_e5_tight1_e4_etcut_Jpsi_SiTrk();
      } else {
         L2_e5_tight1_e4_etcut_Jpsi_SiTrk() = 0;
      }
      if( parent.L2_e5_tight1_e4_etcut_Jpsi_TRT.IsAvailable() ) {
         L2_e5_tight1_e4_etcut_Jpsi_TRT() = parent.L2_e5_tight1_e4_etcut_Jpsi_TRT();
      } else {
         L2_e5_tight1_e4_etcut_Jpsi_TRT() = 0;
      }
      if( parent.L2_e5_tight1_e5_NoCut.IsAvailable() ) {
         L2_e5_tight1_e5_NoCut() = parent.L2_e5_tight1_e5_NoCut();
      } else {
         L2_e5_tight1_e5_NoCut() = 0;
      }
      if( parent.L2_e5_tight1_e9_etcut_Jpsi.IsAvailable() ) {
         L2_e5_tight1_e9_etcut_Jpsi() = parent.L2_e5_tight1_e9_etcut_Jpsi();
      } else {
         L2_e5_tight1_e9_etcut_Jpsi() = 0;
      }
      if( parent.L2_e60_etcut.IsAvailable() ) {
         L2_e60_etcut() = parent.L2_e60_etcut();
      } else {
         L2_e60_etcut() = 0;
      }
      if( parent.L2_e60_loose1.IsAvailable() ) {
         L2_e60_loose1() = parent.L2_e60_loose1();
      } else {
         L2_e60_loose1() = 0;
      }
      if( parent.L2_e60_medium1.IsAvailable() ) {
         L2_e60_medium1() = parent.L2_e60_medium1();
      } else {
         L2_e60_medium1() = 0;
      }
      if( parent.L2_e7T_loose1.IsAvailable() ) {
         L2_e7T_loose1() = parent.L2_e7T_loose1();
      } else {
         L2_e7T_loose1() = 0;
      }
      if( parent.L2_e7T_loose1_2mu6.IsAvailable() ) {
         L2_e7T_loose1_2mu6() = parent.L2_e7T_loose1_2mu6();
      } else {
         L2_e7T_loose1_2mu6() = 0;
      }
      if( parent.L2_e7T_medium1.IsAvailable() ) {
         L2_e7T_medium1() = parent.L2_e7T_medium1();
      } else {
         L2_e7T_medium1() = 0;
      }
      if( parent.L2_e7T_medium1_2mu6.IsAvailable() ) {
         L2_e7T_medium1_2mu6() = parent.L2_e7T_medium1_2mu6();
      } else {
         L2_e7T_medium1_2mu6() = 0;
      }
      if( parent.L2_e9_tight1_e4_etcut_Jpsi.IsAvailable() ) {
         L2_e9_tight1_e4_etcut_Jpsi() = parent.L2_e9_tight1_e4_etcut_Jpsi();
      } else {
         L2_e9_tight1_e4_etcut_Jpsi() = 0;
      }
      if( parent.L2_eb_physics.IsAvailable() ) {
         L2_eb_physics() = parent.L2_eb_physics();
      } else {
         L2_eb_physics() = 0;
      }
      if( parent.L2_eb_physics_empty.IsAvailable() ) {
         L2_eb_physics_empty() = parent.L2_eb_physics_empty();
      } else {
         L2_eb_physics_empty() = 0;
      }
      if( parent.L2_eb_physics_firstempty.IsAvailable() ) {
         L2_eb_physics_firstempty() = parent.L2_eb_physics_firstempty();
      } else {
         L2_eb_physics_firstempty() = 0;
      }
      if( parent.L2_eb_physics_noL1PS.IsAvailable() ) {
         L2_eb_physics_noL1PS() = parent.L2_eb_physics_noL1PS();
      } else {
         L2_eb_physics_noL1PS() = 0;
      }
      if( parent.L2_eb_physics_unpaired_iso.IsAvailable() ) {
         L2_eb_physics_unpaired_iso() = parent.L2_eb_physics_unpaired_iso();
      } else {
         L2_eb_physics_unpaired_iso() = 0;
      }
      if( parent.L2_eb_physics_unpaired_noniso.IsAvailable() ) {
         L2_eb_physics_unpaired_noniso() = parent.L2_eb_physics_unpaired_noniso();
      } else {
         L2_eb_physics_unpaired_noniso() = 0;
      }
      if( parent.L2_eb_random.IsAvailable() ) {
         L2_eb_random() = parent.L2_eb_random();
      } else {
         L2_eb_random() = 0;
      }
      if( parent.L2_eb_random_empty.IsAvailable() ) {
         L2_eb_random_empty() = parent.L2_eb_random_empty();
      } else {
         L2_eb_random_empty() = 0;
      }
      if( parent.L2_eb_random_firstempty.IsAvailable() ) {
         L2_eb_random_firstempty() = parent.L2_eb_random_firstempty();
      } else {
         L2_eb_random_firstempty() = 0;
      }
      if( parent.L2_eb_random_unpaired_iso.IsAvailable() ) {
         L2_eb_random_unpaired_iso() = parent.L2_eb_random_unpaired_iso();
      } else {
         L2_eb_random_unpaired_iso() = 0;
      }
      if( parent.L2_em3_empty_larcalib.IsAvailable() ) {
         L2_em3_empty_larcalib() = parent.L2_em3_empty_larcalib();
      } else {
         L2_em3_empty_larcalib() = 0;
      }
      if( parent.L2_em6_empty_larcalib.IsAvailable() ) {
         L2_em6_empty_larcalib() = parent.L2_em6_empty_larcalib();
      } else {
         L2_em6_empty_larcalib() = 0;
      }
      if( parent.L2_g100_loose.IsAvailable() ) {
         L2_g100_loose() = parent.L2_g100_loose();
      } else {
         L2_g100_loose() = 0;
      }
      if( parent.L2_g10_NoCut_cosmic.IsAvailable() ) {
         L2_g10_NoCut_cosmic() = parent.L2_g10_NoCut_cosmic();
      } else {
         L2_g10_NoCut_cosmic() = 0;
      }
      if( parent.L2_g10_loose.IsAvailable() ) {
         L2_g10_loose() = parent.L2_g10_loose();
      } else {
         L2_g10_loose() = 0;
      }
      if( parent.L2_g10_medium.IsAvailable() ) {
         L2_g10_medium() = parent.L2_g10_medium();
      } else {
         L2_g10_medium() = 0;
      }
      if( parent.L2_g120_loose.IsAvailable() ) {
         L2_g120_loose() = parent.L2_g120_loose();
      } else {
         L2_g120_loose() = 0;
      }
      if( parent.L2_g12Tvh_loose.IsAvailable() ) {
         L2_g12Tvh_loose() = parent.L2_g12Tvh_loose();
      } else {
         L2_g12Tvh_loose() = 0;
      }
      if( parent.L2_g12Tvh_medium.IsAvailable() ) {
         L2_g12Tvh_medium() = parent.L2_g12Tvh_medium();
      } else {
         L2_g12Tvh_medium() = 0;
      }
      if( parent.L2_g15_loose.IsAvailable() ) {
         L2_g15_loose() = parent.L2_g15_loose();
      } else {
         L2_g15_loose() = 0;
      }
      if( parent.L2_g15vh_loose.IsAvailable() ) {
         L2_g15vh_loose() = parent.L2_g15vh_loose();
      } else {
         L2_g15vh_loose() = 0;
      }
      if( parent.L2_g15vh_medium.IsAvailable() ) {
         L2_g15vh_medium() = parent.L2_g15vh_medium();
      } else {
         L2_g15vh_medium() = 0;
      }
      if( parent.L2_g200_etcut.IsAvailable() ) {
         L2_g200_etcut() = parent.L2_g200_etcut();
      } else {
         L2_g200_etcut() = 0;
      }
      if( parent.L2_g20Tvh_medium.IsAvailable() ) {
         L2_g20Tvh_medium() = parent.L2_g20Tvh_medium();
      } else {
         L2_g20Tvh_medium() = 0;
      }
      if( parent.L2_g20_etcut.IsAvailable() ) {
         L2_g20_etcut() = parent.L2_g20_etcut();
      } else {
         L2_g20_etcut() = 0;
      }
      if( parent.L2_g20_loose.IsAvailable() ) {
         L2_g20_loose() = parent.L2_g20_loose();
      } else {
         L2_g20_loose() = 0;
      }
      if( parent.L2_g20_medium.IsAvailable() ) {
         L2_g20_medium() = parent.L2_g20_medium();
      } else {
         L2_g20_medium() = 0;
      }
      if( parent.L2_g20vh_medium.IsAvailable() ) {
         L2_g20vh_medium() = parent.L2_g20vh_medium();
      } else {
         L2_g20vh_medium() = 0;
      }
      if( parent.L2_g30_loose_g20_loose.IsAvailable() ) {
         L2_g30_loose_g20_loose() = parent.L2_g30_loose_g20_loose();
      } else {
         L2_g30_loose_g20_loose() = 0;
      }
      if( parent.L2_g30_medium_g20_medium.IsAvailable() ) {
         L2_g30_medium_g20_medium() = parent.L2_g30_medium_g20_medium();
      } else {
         L2_g30_medium_g20_medium() = 0;
      }
      if( parent.L2_g35_loose_g25_loose.IsAvailable() ) {
         L2_g35_loose_g25_loose() = parent.L2_g35_loose_g25_loose();
      } else {
         L2_g35_loose_g25_loose() = 0;
      }
      if( parent.L2_g35_loose_g30_loose.IsAvailable() ) {
         L2_g35_loose_g30_loose() = parent.L2_g35_loose_g30_loose();
      } else {
         L2_g35_loose_g30_loose() = 0;
      }
      if( parent.L2_g40_loose.IsAvailable() ) {
         L2_g40_loose() = parent.L2_g40_loose();
      } else {
         L2_g40_loose() = 0;
      }
      if( parent.L2_g40_loose_EFxe50.IsAvailable() ) {
         L2_g40_loose_EFxe50() = parent.L2_g40_loose_EFxe50();
      } else {
         L2_g40_loose_EFxe50() = 0;
      }
      if( parent.L2_g40_loose_L2xe35.IsAvailable() ) {
         L2_g40_loose_L2xe35() = parent.L2_g40_loose_L2xe35();
      } else {
         L2_g40_loose_L2xe35() = 0;
      }
      if( parent.L2_g40_loose_L2xe45.IsAvailable() ) {
         L2_g40_loose_L2xe45() = parent.L2_g40_loose_L2xe45();
      } else {
         L2_g40_loose_L2xe45() = 0;
      }
      if( parent.L2_g40_loose_g25_loose.IsAvailable() ) {
         L2_g40_loose_g25_loose() = parent.L2_g40_loose_g25_loose();
      } else {
         L2_g40_loose_g25_loose() = 0;
      }
      if( parent.L2_g40_loose_g30_loose.IsAvailable() ) {
         L2_g40_loose_g30_loose() = parent.L2_g40_loose_g30_loose();
      } else {
         L2_g40_loose_g30_loose() = 0;
      }
      if( parent.L2_g5_NoCut_cosmic.IsAvailable() ) {
         L2_g5_NoCut_cosmic() = parent.L2_g5_NoCut_cosmic();
      } else {
         L2_g5_NoCut_cosmic() = 0;
      }
      if( parent.L2_g60_loose.IsAvailable() ) {
         L2_g60_loose() = parent.L2_g60_loose();
      } else {
         L2_g60_loose() = 0;
      }
      if( parent.L2_g80_loose.IsAvailable() ) {
         L2_g80_loose() = parent.L2_g80_loose();
      } else {
         L2_g80_loose() = 0;
      }
      if( parent.L2_j105_c4cchad_xe35.IsAvailable() ) {
         L2_j105_c4cchad_xe35() = parent.L2_j105_c4cchad_xe35();
      } else {
         L2_j105_c4cchad_xe35() = 0;
      }
      if( parent.L2_j105_c4cchad_xe40.IsAvailable() ) {
         L2_j105_c4cchad_xe40() = parent.L2_j105_c4cchad_xe40();
      } else {
         L2_j105_c4cchad_xe40() = 0;
      }
      if( parent.L2_j105_c4cchad_xe45.IsAvailable() ) {
         L2_j105_c4cchad_xe45() = parent.L2_j105_c4cchad_xe45();
      } else {
         L2_j105_c4cchad_xe45() = 0;
      }
      if( parent.L2_j105_j40_c4cchad_xe40.IsAvailable() ) {
         L2_j105_j40_c4cchad_xe40() = parent.L2_j105_j40_c4cchad_xe40();
      } else {
         L2_j105_j40_c4cchad_xe40() = 0;
      }
      if( parent.L2_j105_j50_c4cchad_xe40.IsAvailable() ) {
         L2_j105_j50_c4cchad_xe40() = parent.L2_j105_j50_c4cchad_xe40();
      } else {
         L2_j105_j50_c4cchad_xe40() = 0;
      }
      if( parent.L2_j30_a4tcem_eta13_xe30_empty.IsAvailable() ) {
         L2_j30_a4tcem_eta13_xe30_empty() = parent.L2_j30_a4tcem_eta13_xe30_empty();
      } else {
         L2_j30_a4tcem_eta13_xe30_empty() = 0;
      }
      if( parent.L2_j30_a4tcem_eta13_xe30_firstempty.IsAvailable() ) {
         L2_j30_a4tcem_eta13_xe30_firstempty() = parent.L2_j30_a4tcem_eta13_xe30_firstempty();
      } else {
         L2_j30_a4tcem_eta13_xe30_firstempty() = 0;
      }
      if( parent.L2_j50_a4tcem_eta13_xe50_empty.IsAvailable() ) {
         L2_j50_a4tcem_eta13_xe50_empty() = parent.L2_j50_a4tcem_eta13_xe50_empty();
      } else {
         L2_j50_a4tcem_eta13_xe50_empty() = 0;
      }
      if( parent.L2_j50_a4tcem_eta13_xe50_firstempty.IsAvailable() ) {
         L2_j50_a4tcem_eta13_xe50_firstempty() = parent.L2_j50_a4tcem_eta13_xe50_firstempty();
      } else {
         L2_j50_a4tcem_eta13_xe50_firstempty() = 0;
      }
      if( parent.L2_j50_a4tcem_eta25_xe50_empty.IsAvailable() ) {
         L2_j50_a4tcem_eta25_xe50_empty() = parent.L2_j50_a4tcem_eta25_xe50_empty();
      } else {
         L2_j50_a4tcem_eta25_xe50_empty() = 0;
      }
      if( parent.L2_j50_a4tcem_eta25_xe50_firstempty.IsAvailable() ) {
         L2_j50_a4tcem_eta25_xe50_firstempty() = parent.L2_j50_a4tcem_eta25_xe50_firstempty();
      } else {
         L2_j50_a4tcem_eta25_xe50_firstempty() = 0;
      }
      if( parent.L2_j75_c4cchad_xe40.IsAvailable() ) {
         L2_j75_c4cchad_xe40() = parent.L2_j75_c4cchad_xe40();
      } else {
         L2_j75_c4cchad_xe40() = 0;
      }
      if( parent.L2_j75_c4cchad_xe45.IsAvailable() ) {
         L2_j75_c4cchad_xe45() = parent.L2_j75_c4cchad_xe45();
      } else {
         L2_j75_c4cchad_xe45() = 0;
      }
      if( parent.L2_j75_c4cchad_xe55.IsAvailable() ) {
         L2_j75_c4cchad_xe55() = parent.L2_j75_c4cchad_xe55();
      } else {
         L2_j75_c4cchad_xe55() = 0;
      }
      if( parent.L2_mu10.IsAvailable() ) {
         L2_mu10() = parent.L2_mu10();
      } else {
         L2_mu10() = 0;
      }
      if( parent.L2_mu10_Jpsimumu.IsAvailable() ) {
         L2_mu10_Jpsimumu() = parent.L2_mu10_Jpsimumu();
      } else {
         L2_mu10_Jpsimumu() = 0;
      }
      if( parent.L2_mu10_MSonly.IsAvailable() ) {
         L2_mu10_MSonly() = parent.L2_mu10_MSonly();
      } else {
         L2_mu10_MSonly() = 0;
      }
      if( parent.L2_mu10_Upsimumu_tight_FS.IsAvailable() ) {
         L2_mu10_Upsimumu_tight_FS() = parent.L2_mu10_Upsimumu_tight_FS();
      } else {
         L2_mu10_Upsimumu_tight_FS() = 0;
      }
      if( parent.L2_mu10i_g10_loose.IsAvailable() ) {
         L2_mu10i_g10_loose() = parent.L2_mu10i_g10_loose();
      } else {
         L2_mu10i_g10_loose() = 0;
      }
      if( parent.L2_mu10i_g10_loose_TauMass.IsAvailable() ) {
         L2_mu10i_g10_loose_TauMass() = parent.L2_mu10i_g10_loose_TauMass();
      } else {
         L2_mu10i_g10_loose_TauMass() = 0;
      }
      if( parent.L2_mu10i_g10_medium.IsAvailable() ) {
         L2_mu10i_g10_medium() = parent.L2_mu10i_g10_medium();
      } else {
         L2_mu10i_g10_medium() = 0;
      }
      if( parent.L2_mu10i_g10_medium_TauMass.IsAvailable() ) {
         L2_mu10i_g10_medium_TauMass() = parent.L2_mu10i_g10_medium_TauMass();
      } else {
         L2_mu10i_g10_medium_TauMass() = 0;
      }
      if( parent.L2_mu10i_loose_g12Tvh_loose.IsAvailable() ) {
         L2_mu10i_loose_g12Tvh_loose() = parent.L2_mu10i_loose_g12Tvh_loose();
      } else {
         L2_mu10i_loose_g12Tvh_loose() = 0;
      }
      if( parent.L2_mu10i_loose_g12Tvh_loose_TauMass.IsAvailable() ) {
         L2_mu10i_loose_g12Tvh_loose_TauMass() = parent.L2_mu10i_loose_g12Tvh_loose_TauMass();
      } else {
         L2_mu10i_loose_g12Tvh_loose_TauMass() = 0;
      }
      if( parent.L2_mu10i_loose_g12Tvh_medium.IsAvailable() ) {
         L2_mu10i_loose_g12Tvh_medium() = parent.L2_mu10i_loose_g12Tvh_medium();
      } else {
         L2_mu10i_loose_g12Tvh_medium() = 0;
      }
      if( parent.L2_mu10i_loose_g12Tvh_medium_TauMass.IsAvailable() ) {
         L2_mu10i_loose_g12Tvh_medium_TauMass() = parent.L2_mu10i_loose_g12Tvh_medium_TauMass();
      } else {
         L2_mu10i_loose_g12Tvh_medium_TauMass() = 0;
      }
      if( parent.L2_mu11_empty_NoAlg.IsAvailable() ) {
         L2_mu11_empty_NoAlg() = parent.L2_mu11_empty_NoAlg();
      } else {
         L2_mu11_empty_NoAlg() = 0;
      }
      if( parent.L2_mu13.IsAvailable() ) {
         L2_mu13() = parent.L2_mu13();
      } else {
         L2_mu13() = 0;
      }
      if( parent.L2_mu15.IsAvailable() ) {
         L2_mu15() = parent.L2_mu15();
      } else {
         L2_mu15() = 0;
      }
      if( parent.L2_mu15_l2cal.IsAvailable() ) {
         L2_mu15_l2cal() = parent.L2_mu15_l2cal();
      } else {
         L2_mu15_l2cal() = 0;
      }
      if( parent.L2_mu18.IsAvailable() ) {
         L2_mu18() = parent.L2_mu18();
      } else {
         L2_mu18() = 0;
      }
      if( parent.L2_mu18_2g10_loose.IsAvailable() ) {
         L2_mu18_2g10_loose() = parent.L2_mu18_2g10_loose();
      } else {
         L2_mu18_2g10_loose() = 0;
      }
      if( parent.L2_mu18_2g10_medium.IsAvailable() ) {
         L2_mu18_2g10_medium() = parent.L2_mu18_2g10_medium();
      } else {
         L2_mu18_2g10_medium() = 0;
      }
      if( parent.L2_mu18_2g15_loose.IsAvailable() ) {
         L2_mu18_2g15_loose() = parent.L2_mu18_2g15_loose();
      } else {
         L2_mu18_2g15_loose() = 0;
      }
      if( parent.L2_mu18_IDTrkNoCut_tight.IsAvailable() ) {
         L2_mu18_IDTrkNoCut_tight() = parent.L2_mu18_IDTrkNoCut_tight();
      } else {
         L2_mu18_IDTrkNoCut_tight() = 0;
      }
      if( parent.L2_mu18_g20vh_loose.IsAvailable() ) {
         L2_mu18_g20vh_loose() = parent.L2_mu18_g20vh_loose();
      } else {
         L2_mu18_g20vh_loose() = 0;
      }
      if( parent.L2_mu18_medium.IsAvailable() ) {
         L2_mu18_medium() = parent.L2_mu18_medium();
      } else {
         L2_mu18_medium() = 0;
      }
      if( parent.L2_mu18_tight.IsAvailable() ) {
         L2_mu18_tight() = parent.L2_mu18_tight();
      } else {
         L2_mu18_tight() = 0;
      }
      if( parent.L2_mu18_tight_e7_medium1.IsAvailable() ) {
         L2_mu18_tight_e7_medium1() = parent.L2_mu18_tight_e7_medium1();
      } else {
         L2_mu18_tight_e7_medium1() = 0;
      }
      if( parent.L2_mu18i4_tight.IsAvailable() ) {
         L2_mu18i4_tight() = parent.L2_mu18i4_tight();
      } else {
         L2_mu18i4_tight() = 0;
      }
      if( parent.L2_mu18it_tight.IsAvailable() ) {
         L2_mu18it_tight() = parent.L2_mu18it_tight();
      } else {
         L2_mu18it_tight() = 0;
      }
      if( parent.L2_mu20i_tight_g5_loose.IsAvailable() ) {
         L2_mu20i_tight_g5_loose() = parent.L2_mu20i_tight_g5_loose();
      } else {
         L2_mu20i_tight_g5_loose() = 0;
      }
      if( parent.L2_mu20i_tight_g5_loose_TauMass.IsAvailable() ) {
         L2_mu20i_tight_g5_loose_TauMass() = parent.L2_mu20i_tight_g5_loose_TauMass();
      } else {
         L2_mu20i_tight_g5_loose_TauMass() = 0;
      }
      if( parent.L2_mu20i_tight_g5_medium.IsAvailable() ) {
         L2_mu20i_tight_g5_medium() = parent.L2_mu20i_tight_g5_medium();
      } else {
         L2_mu20i_tight_g5_medium() = 0;
      }
      if( parent.L2_mu20i_tight_g5_medium_TauMass.IsAvailable() ) {
         L2_mu20i_tight_g5_medium_TauMass() = parent.L2_mu20i_tight_g5_medium_TauMass();
      } else {
         L2_mu20i_tight_g5_medium_TauMass() = 0;
      }
      if( parent.L2_mu20it_tight.IsAvailable() ) {
         L2_mu20it_tight() = parent.L2_mu20it_tight();
      } else {
         L2_mu20it_tight() = 0;
      }
      if( parent.L2_mu22_IDTrkNoCut_tight.IsAvailable() ) {
         L2_mu22_IDTrkNoCut_tight() = parent.L2_mu22_IDTrkNoCut_tight();
      } else {
         L2_mu22_IDTrkNoCut_tight() = 0;
      }
      if( parent.L2_mu24.IsAvailable() ) {
         L2_mu24() = parent.L2_mu24();
      } else {
         L2_mu24() = 0;
      }
      if( parent.L2_mu24_g20vh_loose.IsAvailable() ) {
         L2_mu24_g20vh_loose() = parent.L2_mu24_g20vh_loose();
      } else {
         L2_mu24_g20vh_loose() = 0;
      }
      if( parent.L2_mu24_g20vh_medium.IsAvailable() ) {
         L2_mu24_g20vh_medium() = parent.L2_mu24_g20vh_medium();
      } else {
         L2_mu24_g20vh_medium() = 0;
      }
      if( parent.L2_mu24_j60_c4cchad_EFxe40.IsAvailable() ) {
         L2_mu24_j60_c4cchad_EFxe40() = parent.L2_mu24_j60_c4cchad_EFxe40();
      } else {
         L2_mu24_j60_c4cchad_EFxe40() = 0;
      }
      if( parent.L2_mu24_j60_c4cchad_EFxe50.IsAvailable() ) {
         L2_mu24_j60_c4cchad_EFxe50() = parent.L2_mu24_j60_c4cchad_EFxe50();
      } else {
         L2_mu24_j60_c4cchad_EFxe50() = 0;
      }
      if( parent.L2_mu24_j60_c4cchad_EFxe60.IsAvailable() ) {
         L2_mu24_j60_c4cchad_EFxe60() = parent.L2_mu24_j60_c4cchad_EFxe60();
      } else {
         L2_mu24_j60_c4cchad_EFxe60() = 0;
      }
      if( parent.L2_mu24_j60_c4cchad_xe35.IsAvailable() ) {
         L2_mu24_j60_c4cchad_xe35() = parent.L2_mu24_j60_c4cchad_xe35();
      } else {
         L2_mu24_j60_c4cchad_xe35() = 0;
      }
      if( parent.L2_mu24_j65_c4cchad.IsAvailable() ) {
         L2_mu24_j65_c4cchad() = parent.L2_mu24_j65_c4cchad();
      } else {
         L2_mu24_j65_c4cchad() = 0;
      }
      if( parent.L2_mu24_medium.IsAvailable() ) {
         L2_mu24_medium() = parent.L2_mu24_medium();
      } else {
         L2_mu24_medium() = 0;
      }
      if( parent.L2_mu24_muCombTag_NoEF_tight.IsAvailable() ) {
         L2_mu24_muCombTag_NoEF_tight() = parent.L2_mu24_muCombTag_NoEF_tight();
      } else {
         L2_mu24_muCombTag_NoEF_tight() = 0;
      }
      if( parent.L2_mu24_tight.IsAvailable() ) {
         L2_mu24_tight() = parent.L2_mu24_tight();
      } else {
         L2_mu24_tight() = 0;
      }
      if( parent.L2_mu24_tight_2j35_a4tchad.IsAvailable() ) {
         L2_mu24_tight_2j35_a4tchad() = parent.L2_mu24_tight_2j35_a4tchad();
      } else {
         L2_mu24_tight_2j35_a4tchad() = 0;
      }
      if( parent.L2_mu24_tight_3j35_a4tchad.IsAvailable() ) {
         L2_mu24_tight_3j35_a4tchad() = parent.L2_mu24_tight_3j35_a4tchad();
      } else {
         L2_mu24_tight_3j35_a4tchad() = 0;
      }
      if( parent.L2_mu24_tight_4j35_a4tchad.IsAvailable() ) {
         L2_mu24_tight_4j35_a4tchad() = parent.L2_mu24_tight_4j35_a4tchad();
      } else {
         L2_mu24_tight_4j35_a4tchad() = 0;
      }
      if( parent.L2_mu24_tight_EFxe40.IsAvailable() ) {
         L2_mu24_tight_EFxe40() = parent.L2_mu24_tight_EFxe40();
      } else {
         L2_mu24_tight_EFxe40() = 0;
      }
      if( parent.L2_mu24_tight_L2StarB.IsAvailable() ) {
         L2_mu24_tight_L2StarB() = parent.L2_mu24_tight_L2StarB();
      } else {
         L2_mu24_tight_L2StarB() = 0;
      }
      if( parent.L2_mu24_tight_L2StarC.IsAvailable() ) {
         L2_mu24_tight_L2StarC() = parent.L2_mu24_tight_L2StarC();
      } else {
         L2_mu24_tight_L2StarC() = 0;
      }
      if( parent.L2_mu24_tight_l2muonSA.IsAvailable() ) {
         L2_mu24_tight_l2muonSA() = parent.L2_mu24_tight_l2muonSA();
      } else {
         L2_mu24_tight_l2muonSA() = 0;
      }
      if( parent.L2_mu36_tight.IsAvailable() ) {
         L2_mu36_tight() = parent.L2_mu36_tight();
      } else {
         L2_mu36_tight() = 0;
      }
      if( parent.L2_mu40_MSonly_barrel_tight.IsAvailable() ) {
         L2_mu40_MSonly_barrel_tight() = parent.L2_mu40_MSonly_barrel_tight();
      } else {
         L2_mu40_MSonly_barrel_tight() = 0;
      }
      if( parent.L2_mu40_muCombTag_NoEF.IsAvailable() ) {
         L2_mu40_muCombTag_NoEF() = parent.L2_mu40_muCombTag_NoEF();
      } else {
         L2_mu40_muCombTag_NoEF() = 0;
      }
      if( parent.L2_mu40_slow_outOfTime_tight.IsAvailable() ) {
         L2_mu40_slow_outOfTime_tight() = parent.L2_mu40_slow_outOfTime_tight();
      } else {
         L2_mu40_slow_outOfTime_tight() = 0;
      }
      if( parent.L2_mu40_slow_tight.IsAvailable() ) {
         L2_mu40_slow_tight() = parent.L2_mu40_slow_tight();
      } else {
         L2_mu40_slow_tight() = 0;
      }
      if( parent.L2_mu40_tight.IsAvailable() ) {
         L2_mu40_tight() = parent.L2_mu40_tight();
      } else {
         L2_mu40_tight() = 0;
      }
      if( parent.L2_mu4T.IsAvailable() ) {
         L2_mu4T() = parent.L2_mu4T();
      } else {
         L2_mu4T() = 0;
      }
      if( parent.L2_mu4T_Trk_Jpsi.IsAvailable() ) {
         L2_mu4T_Trk_Jpsi() = parent.L2_mu4T_Trk_Jpsi();
      } else {
         L2_mu4T_Trk_Jpsi() = 0;
      }
      if( parent.L2_mu4T_cosmic.IsAvailable() ) {
         L2_mu4T_cosmic() = parent.L2_mu4T_cosmic();
      } else {
         L2_mu4T_cosmic() = 0;
      }
      if( parent.L2_mu4T_j105_c4cchad.IsAvailable() ) {
         L2_mu4T_j105_c4cchad() = parent.L2_mu4T_j105_c4cchad();
      } else {
         L2_mu4T_j105_c4cchad() = 0;
      }
      if( parent.L2_mu4T_j10_a4TTem.IsAvailable() ) {
         L2_mu4T_j10_a4TTem() = parent.L2_mu4T_j10_a4TTem();
      } else {
         L2_mu4T_j10_a4TTem() = 0;
      }
      if( parent.L2_mu4T_j140_c4cchad.IsAvailable() ) {
         L2_mu4T_j140_c4cchad() = parent.L2_mu4T_j140_c4cchad();
      } else {
         L2_mu4T_j140_c4cchad() = 0;
      }
      if( parent.L2_mu4T_j15_a4TTem.IsAvailable() ) {
         L2_mu4T_j15_a4TTem() = parent.L2_mu4T_j15_a4TTem();
      } else {
         L2_mu4T_j15_a4TTem() = 0;
      }
      if( parent.L2_mu4T_j165_c4cchad.IsAvailable() ) {
         L2_mu4T_j165_c4cchad() = parent.L2_mu4T_j165_c4cchad();
      } else {
         L2_mu4T_j165_c4cchad() = 0;
      }
      if( parent.L2_mu4T_j30_a4TTem.IsAvailable() ) {
         L2_mu4T_j30_a4TTem() = parent.L2_mu4T_j30_a4TTem();
      } else {
         L2_mu4T_j30_a4TTem() = 0;
      }
      if( parent.L2_mu4T_j40_c4cchad.IsAvailable() ) {
         L2_mu4T_j40_c4cchad() = parent.L2_mu4T_j40_c4cchad();
      } else {
         L2_mu4T_j40_c4cchad() = 0;
      }
      if( parent.L2_mu4T_j50_a4TTem.IsAvailable() ) {
         L2_mu4T_j50_a4TTem() = parent.L2_mu4T_j50_a4TTem();
      } else {
         L2_mu4T_j50_a4TTem() = 0;
      }
      if( parent.L2_mu4T_j50_c4cchad.IsAvailable() ) {
         L2_mu4T_j50_c4cchad() = parent.L2_mu4T_j50_c4cchad();
      } else {
         L2_mu4T_j50_c4cchad() = 0;
      }
      if( parent.L2_mu4T_j60_c4cchad.IsAvailable() ) {
         L2_mu4T_j60_c4cchad() = parent.L2_mu4T_j60_c4cchad();
      } else {
         L2_mu4T_j60_c4cchad() = 0;
      }
      if( parent.L2_mu4T_j60_c4cchad_xe40.IsAvailable() ) {
         L2_mu4T_j60_c4cchad_xe40() = parent.L2_mu4T_j60_c4cchad_xe40();
      } else {
         L2_mu4T_j60_c4cchad_xe40() = 0;
      }
      if( parent.L2_mu4T_j75_a4TTem.IsAvailable() ) {
         L2_mu4T_j75_a4TTem() = parent.L2_mu4T_j75_a4TTem();
      } else {
         L2_mu4T_j75_a4TTem() = 0;
      }
      if( parent.L2_mu4T_j75_c4cchad.IsAvailable() ) {
         L2_mu4T_j75_c4cchad() = parent.L2_mu4T_j75_c4cchad();
      } else {
         L2_mu4T_j75_c4cchad() = 0;
      }
      if( parent.L2_mu4Ti_g20Tvh_loose.IsAvailable() ) {
         L2_mu4Ti_g20Tvh_loose() = parent.L2_mu4Ti_g20Tvh_loose();
      } else {
         L2_mu4Ti_g20Tvh_loose() = 0;
      }
      if( parent.L2_mu4Ti_g20Tvh_loose_TauMass.IsAvailable() ) {
         L2_mu4Ti_g20Tvh_loose_TauMass() = parent.L2_mu4Ti_g20Tvh_loose_TauMass();
      } else {
         L2_mu4Ti_g20Tvh_loose_TauMass() = 0;
      }
      if( parent.L2_mu4Ti_g20Tvh_medium.IsAvailable() ) {
         L2_mu4Ti_g20Tvh_medium() = parent.L2_mu4Ti_g20Tvh_medium();
      } else {
         L2_mu4Ti_g20Tvh_medium() = 0;
      }
      if( parent.L2_mu4Ti_g20Tvh_medium_TauMass.IsAvailable() ) {
         L2_mu4Ti_g20Tvh_medium_TauMass() = parent.L2_mu4Ti_g20Tvh_medium_TauMass();
      } else {
         L2_mu4Ti_g20Tvh_medium_TauMass() = 0;
      }
      if( parent.L2_mu4Tmu6_Bmumu.IsAvailable() ) {
         L2_mu4Tmu6_Bmumu() = parent.L2_mu4Tmu6_Bmumu();
      } else {
         L2_mu4Tmu6_Bmumu() = 0;
      }
      if( parent.L2_mu4Tmu6_Bmumu_Barrel.IsAvailable() ) {
         L2_mu4Tmu6_Bmumu_Barrel() = parent.L2_mu4Tmu6_Bmumu_Barrel();
      } else {
         L2_mu4Tmu6_Bmumu_Barrel() = 0;
      }
      if( parent.L2_mu4Tmu6_Bmumux.IsAvailable() ) {
         L2_mu4Tmu6_Bmumux() = parent.L2_mu4Tmu6_Bmumux();
      } else {
         L2_mu4Tmu6_Bmumux() = 0;
      }
      if( parent.L2_mu4Tmu6_Bmumux_Barrel.IsAvailable() ) {
         L2_mu4Tmu6_Bmumux_Barrel() = parent.L2_mu4Tmu6_Bmumux_Barrel();
      } else {
         L2_mu4Tmu6_Bmumux_Barrel() = 0;
      }
      if( parent.L2_mu4Tmu6_DiMu.IsAvailable() ) {
         L2_mu4Tmu6_DiMu() = parent.L2_mu4Tmu6_DiMu();
      } else {
         L2_mu4Tmu6_DiMu() = 0;
      }
      if( parent.L2_mu4Tmu6_DiMu_Barrel.IsAvailable() ) {
         L2_mu4Tmu6_DiMu_Barrel() = parent.L2_mu4Tmu6_DiMu_Barrel();
      } else {
         L2_mu4Tmu6_DiMu_Barrel() = 0;
      }
      if( parent.L2_mu4Tmu6_DiMu_noVtx_noOS.IsAvailable() ) {
         L2_mu4Tmu6_DiMu_noVtx_noOS() = parent.L2_mu4Tmu6_DiMu_noVtx_noOS();
      } else {
         L2_mu4Tmu6_DiMu_noVtx_noOS() = 0;
      }
      if( parent.L2_mu4Tmu6_Jpsimumu.IsAvailable() ) {
         L2_mu4Tmu6_Jpsimumu() = parent.L2_mu4Tmu6_Jpsimumu();
      } else {
         L2_mu4Tmu6_Jpsimumu() = 0;
      }
      if( parent.L2_mu4Tmu6_Jpsimumu_Barrel.IsAvailable() ) {
         L2_mu4Tmu6_Jpsimumu_Barrel() = parent.L2_mu4Tmu6_Jpsimumu_Barrel();
      } else {
         L2_mu4Tmu6_Jpsimumu_Barrel() = 0;
      }
      if( parent.L2_mu4Tmu6_Jpsimumu_IDTrkNoCut.IsAvailable() ) {
         L2_mu4Tmu6_Jpsimumu_IDTrkNoCut() = parent.L2_mu4Tmu6_Jpsimumu_IDTrkNoCut();
      } else {
         L2_mu4Tmu6_Jpsimumu_IDTrkNoCut() = 0;
      }
      if( parent.L2_mu4Tmu6_Upsimumu.IsAvailable() ) {
         L2_mu4Tmu6_Upsimumu() = parent.L2_mu4Tmu6_Upsimumu();
      } else {
         L2_mu4Tmu6_Upsimumu() = 0;
      }
      if( parent.L2_mu4Tmu6_Upsimumu_Barrel.IsAvailable() ) {
         L2_mu4Tmu6_Upsimumu_Barrel() = parent.L2_mu4Tmu6_Upsimumu_Barrel();
      } else {
         L2_mu4Tmu6_Upsimumu_Barrel() = 0;
      }
      if( parent.L2_mu4_L1MU11_MSonly_cosmic.IsAvailable() ) {
         L2_mu4_L1MU11_MSonly_cosmic() = parent.L2_mu4_L1MU11_MSonly_cosmic();
      } else {
         L2_mu4_L1MU11_MSonly_cosmic() = 0;
      }
      if( parent.L2_mu4_L1MU11_cosmic.IsAvailable() ) {
         L2_mu4_L1MU11_cosmic() = parent.L2_mu4_L1MU11_cosmic();
      } else {
         L2_mu4_L1MU11_cosmic() = 0;
      }
      if( parent.L2_mu4_empty_NoAlg.IsAvailable() ) {
         L2_mu4_empty_NoAlg() = parent.L2_mu4_empty_NoAlg();
      } else {
         L2_mu4_empty_NoAlg() = 0;
      }
      if( parent.L2_mu4_firstempty_NoAlg.IsAvailable() ) {
         L2_mu4_firstempty_NoAlg() = parent.L2_mu4_firstempty_NoAlg();
      } else {
         L2_mu4_firstempty_NoAlg() = 0;
      }
      if( parent.L2_mu4_l2cal_empty.IsAvailable() ) {
         L2_mu4_l2cal_empty() = parent.L2_mu4_l2cal_empty();
      } else {
         L2_mu4_l2cal_empty() = 0;
      }
      if( parent.L2_mu4_unpaired_iso_NoAlg.IsAvailable() ) {
         L2_mu4_unpaired_iso_NoAlg() = parent.L2_mu4_unpaired_iso_NoAlg();
      } else {
         L2_mu4_unpaired_iso_NoAlg() = 0;
      }
      if( parent.L2_mu50_MSonly_barrel_tight.IsAvailable() ) {
         L2_mu50_MSonly_barrel_tight() = parent.L2_mu50_MSonly_barrel_tight();
      } else {
         L2_mu50_MSonly_barrel_tight() = 0;
      }
      if( parent.L2_mu6.IsAvailable() ) {
         L2_mu6() = parent.L2_mu6();
      } else {
         L2_mu6() = 0;
      }
      if( parent.L2_mu60_slow_outOfTime_tight1.IsAvailable() ) {
         L2_mu60_slow_outOfTime_tight1() = parent.L2_mu60_slow_outOfTime_tight1();
      } else {
         L2_mu60_slow_outOfTime_tight1() = 0;
      }
      if( parent.L2_mu60_slow_tight1.IsAvailable() ) {
         L2_mu60_slow_tight1() = parent.L2_mu60_slow_tight1();
      } else {
         L2_mu60_slow_tight1() = 0;
      }
      if( parent.L2_mu6_Jpsimumu_tight.IsAvailable() ) {
         L2_mu6_Jpsimumu_tight() = parent.L2_mu6_Jpsimumu_tight();
      } else {
         L2_mu6_Jpsimumu_tight() = 0;
      }
      if( parent.L2_mu6_MSonly.IsAvailable() ) {
         L2_mu6_MSonly() = parent.L2_mu6_MSonly();
      } else {
         L2_mu6_MSonly() = 0;
      }
      if( parent.L2_mu6_Trk_Jpsi_loose.IsAvailable() ) {
         L2_mu6_Trk_Jpsi_loose() = parent.L2_mu6_Trk_Jpsi_loose();
      } else {
         L2_mu6_Trk_Jpsi_loose() = 0;
      }
      if( parent.L2_mu8.IsAvailable() ) {
         L2_mu8() = parent.L2_mu8();
      } else {
         L2_mu8() = 0;
      }
      if( parent.L2_mu8_4j15_a4TTem.IsAvailable() ) {
         L2_mu8_4j15_a4TTem() = parent.L2_mu8_4j15_a4TTem();
      } else {
         L2_mu8_4j15_a4TTem() = 0;
      }
      if( parent.L2_tau125_IDTrkNoCut.IsAvailable() ) {
         L2_tau125_IDTrkNoCut() = parent.L2_tau125_IDTrkNoCut();
      } else {
         L2_tau125_IDTrkNoCut() = 0;
      }
      if( parent.L2_tau125_medium1.IsAvailable() ) {
         L2_tau125_medium1() = parent.L2_tau125_medium1();
      } else {
         L2_tau125_medium1() = 0;
      }
      if( parent.L2_tau125_medium1_L2StarA.IsAvailable() ) {
         L2_tau125_medium1_L2StarA() = parent.L2_tau125_medium1_L2StarA();
      } else {
         L2_tau125_medium1_L2StarA() = 0;
      }
      if( parent.L2_tau125_medium1_L2StarB.IsAvailable() ) {
         L2_tau125_medium1_L2StarB() = parent.L2_tau125_medium1_L2StarB();
      } else {
         L2_tau125_medium1_L2StarB() = 0;
      }
      if( parent.L2_tau125_medium1_L2StarC.IsAvailable() ) {
         L2_tau125_medium1_L2StarC() = parent.L2_tau125_medium1_L2StarC();
      } else {
         L2_tau125_medium1_L2StarC() = 0;
      }
      if( parent.L2_tau125_medium1_llh.IsAvailable() ) {
         L2_tau125_medium1_llh() = parent.L2_tau125_medium1_llh();
      } else {
         L2_tau125_medium1_llh() = 0;
      }
      if( parent.L2_tau20T_medium.IsAvailable() ) {
         L2_tau20T_medium() = parent.L2_tau20T_medium();
      } else {
         L2_tau20T_medium() = 0;
      }
      if( parent.L2_tau20T_medium1.IsAvailable() ) {
         L2_tau20T_medium1() = parent.L2_tau20T_medium1();
      } else {
         L2_tau20T_medium1() = 0;
      }
      if( parent.L2_tau20T_medium1_e15vh_medium1.IsAvailable() ) {
         L2_tau20T_medium1_e15vh_medium1() = parent.L2_tau20T_medium1_e15vh_medium1();
      } else {
         L2_tau20T_medium1_e15vh_medium1() = 0;
      }
      if( parent.L2_tau20T_medium1_mu15i.IsAvailable() ) {
         L2_tau20T_medium1_mu15i() = parent.L2_tau20T_medium1_mu15i();
      } else {
         L2_tau20T_medium1_mu15i() = 0;
      }
      if( parent.L2_tau20T_medium_mu15.IsAvailable() ) {
         L2_tau20T_medium_mu15() = parent.L2_tau20T_medium_mu15();
      } else {
         L2_tau20T_medium_mu15() = 0;
      }
      if( parent.L2_tau20Ti_medium.IsAvailable() ) {
         L2_tau20Ti_medium() = parent.L2_tau20Ti_medium();
      } else {
         L2_tau20Ti_medium() = 0;
      }
      if( parent.L2_tau20Ti_medium1.IsAvailable() ) {
         L2_tau20Ti_medium1() = parent.L2_tau20Ti_medium1();
      } else {
         L2_tau20Ti_medium1() = 0;
      }
      if( parent.L2_tau20Ti_medium1_e18vh_medium1.IsAvailable() ) {
         L2_tau20Ti_medium1_e18vh_medium1() = parent.L2_tau20Ti_medium1_e18vh_medium1();
      } else {
         L2_tau20Ti_medium1_e18vh_medium1() = 0;
      }
      if( parent.L2_tau20Ti_medium1_llh_e18vh_medium1.IsAvailable() ) {
         L2_tau20Ti_medium1_llh_e18vh_medium1() = parent.L2_tau20Ti_medium1_llh_e18vh_medium1();
      } else {
         L2_tau20Ti_medium1_llh_e18vh_medium1() = 0;
      }
      if( parent.L2_tau20Ti_medium_e18vh_medium1.IsAvailable() ) {
         L2_tau20Ti_medium_e18vh_medium1() = parent.L2_tau20Ti_medium_e18vh_medium1();
      } else {
         L2_tau20Ti_medium_e18vh_medium1() = 0;
      }
      if( parent.L2_tau20Ti_tight1.IsAvailable() ) {
         L2_tau20Ti_tight1() = parent.L2_tau20Ti_tight1();
      } else {
         L2_tau20Ti_tight1() = 0;
      }
      if( parent.L2_tau20Ti_tight1_llh.IsAvailable() ) {
         L2_tau20Ti_tight1_llh() = parent.L2_tau20Ti_tight1_llh();
      } else {
         L2_tau20Ti_tight1_llh() = 0;
      }
      if( parent.L2_tau20_medium.IsAvailable() ) {
         L2_tau20_medium() = parent.L2_tau20_medium();
      } else {
         L2_tau20_medium() = 0;
      }
      if( parent.L2_tau20_medium1.IsAvailable() ) {
         L2_tau20_medium1() = parent.L2_tau20_medium1();
      } else {
         L2_tau20_medium1() = 0;
      }
      if( parent.L2_tau20_medium1_llh.IsAvailable() ) {
         L2_tau20_medium1_llh() = parent.L2_tau20_medium1_llh();
      } else {
         L2_tau20_medium1_llh() = 0;
      }
      if( parent.L2_tau20_medium1_llh_mu15.IsAvailable() ) {
         L2_tau20_medium1_llh_mu15() = parent.L2_tau20_medium1_llh_mu15();
      } else {
         L2_tau20_medium1_llh_mu15() = 0;
      }
      if( parent.L2_tau20_medium1_mu15.IsAvailable() ) {
         L2_tau20_medium1_mu15() = parent.L2_tau20_medium1_mu15();
      } else {
         L2_tau20_medium1_mu15() = 0;
      }
      if( parent.L2_tau20_medium1_mu15i.IsAvailable() ) {
         L2_tau20_medium1_mu15i() = parent.L2_tau20_medium1_mu15i();
      } else {
         L2_tau20_medium1_mu15i() = 0;
      }
      if( parent.L2_tau20_medium1_mu18.IsAvailable() ) {
         L2_tau20_medium1_mu18() = parent.L2_tau20_medium1_mu18();
      } else {
         L2_tau20_medium1_mu18() = 0;
      }
      if( parent.L2_tau20_medium_llh.IsAvailable() ) {
         L2_tau20_medium_llh() = parent.L2_tau20_medium_llh();
      } else {
         L2_tau20_medium_llh() = 0;
      }
      if( parent.L2_tau20_medium_mu15.IsAvailable() ) {
         L2_tau20_medium_mu15() = parent.L2_tau20_medium_mu15();
      } else {
         L2_tau20_medium_mu15() = 0;
      }
      if( parent.L2_tau29T_medium.IsAvailable() ) {
         L2_tau29T_medium() = parent.L2_tau29T_medium();
      } else {
         L2_tau29T_medium() = 0;
      }
      if( parent.L2_tau29T_medium1.IsAvailable() ) {
         L2_tau29T_medium1() = parent.L2_tau29T_medium1();
      } else {
         L2_tau29T_medium1() = 0;
      }
      if( parent.L2_tau29T_medium1_tau20T_medium1.IsAvailable() ) {
         L2_tau29T_medium1_tau20T_medium1() = parent.L2_tau29T_medium1_tau20T_medium1();
      } else {
         L2_tau29T_medium1_tau20T_medium1() = 0;
      }
      if( parent.L2_tau29T_medium1_xe35_tight.IsAvailable() ) {
         L2_tau29T_medium1_xe35_tight() = parent.L2_tau29T_medium1_xe35_tight();
      } else {
         L2_tau29T_medium1_xe35_tight() = 0;
      }
      if( parent.L2_tau29T_medium1_xe40_tight.IsAvailable() ) {
         L2_tau29T_medium1_xe40_tight() = parent.L2_tau29T_medium1_xe40_tight();
      } else {
         L2_tau29T_medium1_xe40_tight() = 0;
      }
      if( parent.L2_tau29T_medium_xe35_tight.IsAvailable() ) {
         L2_tau29T_medium_xe35_tight() = parent.L2_tau29T_medium_xe35_tight();
      } else {
         L2_tau29T_medium_xe35_tight() = 0;
      }
      if( parent.L2_tau29T_medium_xe40_tight.IsAvailable() ) {
         L2_tau29T_medium_xe40_tight() = parent.L2_tau29T_medium_xe40_tight();
      } else {
         L2_tau29T_medium_xe40_tight() = 0;
      }
      if( parent.L2_tau29T_tight1.IsAvailable() ) {
         L2_tau29T_tight1() = parent.L2_tau29T_tight1();
      } else {
         L2_tau29T_tight1() = 0;
      }
      if( parent.L2_tau29T_tight1_llh.IsAvailable() ) {
         L2_tau29T_tight1_llh() = parent.L2_tau29T_tight1_llh();
      } else {
         L2_tau29T_tight1_llh() = 0;
      }
      if( parent.L2_tau29Ti_medium1.IsAvailable() ) {
         L2_tau29Ti_medium1() = parent.L2_tau29Ti_medium1();
      } else {
         L2_tau29Ti_medium1() = 0;
      }
      if( parent.L2_tau29Ti_medium1_llh_tau20Ti_medium1_llh.IsAvailable() ) {
         L2_tau29Ti_medium1_llh_tau20Ti_medium1_llh() = parent.L2_tau29Ti_medium1_llh_tau20Ti_medium1_llh();
      } else {
         L2_tau29Ti_medium1_llh_tau20Ti_medium1_llh() = 0;
      }
      if( parent.L2_tau29Ti_medium1_llh_xe35_tight.IsAvailable() ) {
         L2_tau29Ti_medium1_llh_xe35_tight() = parent.L2_tau29Ti_medium1_llh_xe35_tight();
      } else {
         L2_tau29Ti_medium1_llh_xe35_tight() = 0;
      }
      if( parent.L2_tau29Ti_medium1_llh_xe40_tight.IsAvailable() ) {
         L2_tau29Ti_medium1_llh_xe40_tight() = parent.L2_tau29Ti_medium1_llh_xe40_tight();
      } else {
         L2_tau29Ti_medium1_llh_xe40_tight() = 0;
      }
      if( parent.L2_tau29Ti_medium1_tau20Ti_medium1.IsAvailable() ) {
         L2_tau29Ti_medium1_tau20Ti_medium1() = parent.L2_tau29Ti_medium1_tau20Ti_medium1();
      } else {
         L2_tau29Ti_medium1_tau20Ti_medium1() = 0;
      }
      if( parent.L2_tau29Ti_medium1_xe35_tight.IsAvailable() ) {
         L2_tau29Ti_medium1_xe35_tight() = parent.L2_tau29Ti_medium1_xe35_tight();
      } else {
         L2_tau29Ti_medium1_xe35_tight() = 0;
      }
      if( parent.L2_tau29Ti_medium1_xe40.IsAvailable() ) {
         L2_tau29Ti_medium1_xe40() = parent.L2_tau29Ti_medium1_xe40();
      } else {
         L2_tau29Ti_medium1_xe40() = 0;
      }
      if( parent.L2_tau29Ti_medium1_xe40_tight.IsAvailable() ) {
         L2_tau29Ti_medium1_xe40_tight() = parent.L2_tau29Ti_medium1_xe40_tight();
      } else {
         L2_tau29Ti_medium1_xe40_tight() = 0;
      }
      if( parent.L2_tau29Ti_medium_xe35_tight.IsAvailable() ) {
         L2_tau29Ti_medium_xe35_tight() = parent.L2_tau29Ti_medium_xe35_tight();
      } else {
         L2_tau29Ti_medium_xe35_tight() = 0;
      }
      if( parent.L2_tau29Ti_medium_xe40_tight.IsAvailable() ) {
         L2_tau29Ti_medium_xe40_tight() = parent.L2_tau29Ti_medium_xe40_tight();
      } else {
         L2_tau29Ti_medium_xe40_tight() = 0;
      }
      if( parent.L2_tau29Ti_tight1.IsAvailable() ) {
         L2_tau29Ti_tight1() = parent.L2_tau29Ti_tight1();
      } else {
         L2_tau29Ti_tight1() = 0;
      }
      if( parent.L2_tau29Ti_tight1_llh.IsAvailable() ) {
         L2_tau29Ti_tight1_llh() = parent.L2_tau29Ti_tight1_llh();
      } else {
         L2_tau29Ti_tight1_llh() = 0;
      }
      if( parent.L2_tau29Ti_tight1_llh_tau20Ti_tight1_llh.IsAvailable() ) {
         L2_tau29Ti_tight1_llh_tau20Ti_tight1_llh() = parent.L2_tau29Ti_tight1_llh_tau20Ti_tight1_llh();
      } else {
         L2_tau29Ti_tight1_llh_tau20Ti_tight1_llh() = 0;
      }
      if( parent.L2_tau29Ti_tight1_tau20Ti_tight1.IsAvailable() ) {
         L2_tau29Ti_tight1_tau20Ti_tight1() = parent.L2_tau29Ti_tight1_tau20Ti_tight1();
      } else {
         L2_tau29Ti_tight1_tau20Ti_tight1() = 0;
      }
      if( parent.L2_tau29_IDTrkNoCut.IsAvailable() ) {
         L2_tau29_IDTrkNoCut() = parent.L2_tau29_IDTrkNoCut();
      } else {
         L2_tau29_IDTrkNoCut() = 0;
      }
      if( parent.L2_tau29_medium.IsAvailable() ) {
         L2_tau29_medium() = parent.L2_tau29_medium();
      } else {
         L2_tau29_medium() = 0;
      }
      if( parent.L2_tau29_medium1.IsAvailable() ) {
         L2_tau29_medium1() = parent.L2_tau29_medium1();
      } else {
         L2_tau29_medium1() = 0;
      }
      if( parent.L2_tau29_medium1_llh.IsAvailable() ) {
         L2_tau29_medium1_llh() = parent.L2_tau29_medium1_llh();
      } else {
         L2_tau29_medium1_llh() = 0;
      }
      if( parent.L2_tau29_medium_2stTest.IsAvailable() ) {
         L2_tau29_medium_2stTest() = parent.L2_tau29_medium_2stTest();
      } else {
         L2_tau29_medium_2stTest() = 0;
      }
      if( parent.L2_tau29_medium_L2StarA.IsAvailable() ) {
         L2_tau29_medium_L2StarA() = parent.L2_tau29_medium_L2StarA();
      } else {
         L2_tau29_medium_L2StarA() = 0;
      }
      if( parent.L2_tau29_medium_L2StarB.IsAvailable() ) {
         L2_tau29_medium_L2StarB() = parent.L2_tau29_medium_L2StarB();
      } else {
         L2_tau29_medium_L2StarB() = 0;
      }
      if( parent.L2_tau29_medium_L2StarC.IsAvailable() ) {
         L2_tau29_medium_L2StarC() = parent.L2_tau29_medium_L2StarC();
      } else {
         L2_tau29_medium_L2StarC() = 0;
      }
      if( parent.L2_tau29_medium_llh.IsAvailable() ) {
         L2_tau29_medium_llh() = parent.L2_tau29_medium_llh();
      } else {
         L2_tau29_medium_llh() = 0;
      }
      if( parent.L2_tau29i_medium.IsAvailable() ) {
         L2_tau29i_medium() = parent.L2_tau29i_medium();
      } else {
         L2_tau29i_medium() = 0;
      }
      if( parent.L2_tau29i_medium1.IsAvailable() ) {
         L2_tau29i_medium1() = parent.L2_tau29i_medium1();
      } else {
         L2_tau29i_medium1() = 0;
      }
      if( parent.L2_tau38T_medium.IsAvailable() ) {
         L2_tau38T_medium() = parent.L2_tau38T_medium();
      } else {
         L2_tau38T_medium() = 0;
      }
      if( parent.L2_tau38T_medium1.IsAvailable() ) {
         L2_tau38T_medium1() = parent.L2_tau38T_medium1();
      } else {
         L2_tau38T_medium1() = 0;
      }
      if( parent.L2_tau38T_medium1_e18vh_medium1.IsAvailable() ) {
         L2_tau38T_medium1_e18vh_medium1() = parent.L2_tau38T_medium1_e18vh_medium1();
      } else {
         L2_tau38T_medium1_e18vh_medium1() = 0;
      }
      if( parent.L2_tau38T_medium1_llh_e18vh_medium1.IsAvailable() ) {
         L2_tau38T_medium1_llh_e18vh_medium1() = parent.L2_tau38T_medium1_llh_e18vh_medium1();
      } else {
         L2_tau38T_medium1_llh_e18vh_medium1() = 0;
      }
      if( parent.L2_tau38T_medium1_xe35_tight.IsAvailable() ) {
         L2_tau38T_medium1_xe35_tight() = parent.L2_tau38T_medium1_xe35_tight();
      } else {
         L2_tau38T_medium1_xe35_tight() = 0;
      }
      if( parent.L2_tau38T_medium1_xe40_tight.IsAvailable() ) {
         L2_tau38T_medium1_xe40_tight() = parent.L2_tau38T_medium1_xe40_tight();
      } else {
         L2_tau38T_medium1_xe40_tight() = 0;
      }
      if( parent.L2_tau38T_medium_e18vh_medium1.IsAvailable() ) {
         L2_tau38T_medium_e18vh_medium1() = parent.L2_tau38T_medium_e18vh_medium1();
      } else {
         L2_tau38T_medium_e18vh_medium1() = 0;
      }
      if( parent.L2_tau50_medium.IsAvailable() ) {
         L2_tau50_medium() = parent.L2_tau50_medium();
      } else {
         L2_tau50_medium() = 0;
      }
      if( parent.L2_tau50_medium1_e18vh_medium1.IsAvailable() ) {
         L2_tau50_medium1_e18vh_medium1() = parent.L2_tau50_medium1_e18vh_medium1();
      } else {
         L2_tau50_medium1_e18vh_medium1() = 0;
      }
      if( parent.L2_tau50_medium_e15vh_medium1.IsAvailable() ) {
         L2_tau50_medium_e15vh_medium1() = parent.L2_tau50_medium_e15vh_medium1();
      } else {
         L2_tau50_medium_e15vh_medium1() = 0;
      }
      if( parent.L2_tau8_empty_larcalib.IsAvailable() ) {
         L2_tau8_empty_larcalib() = parent.L2_tau8_empty_larcalib();
      } else {
         L2_tau8_empty_larcalib() = 0;
      }
      if( parent.L2_tauNoCut.IsAvailable() ) {
         L2_tauNoCut() = parent.L2_tauNoCut();
      } else {
         L2_tauNoCut() = 0;
      }
      if( parent.L2_tauNoCut_L1TAU40.IsAvailable() ) {
         L2_tauNoCut_L1TAU40() = parent.L2_tauNoCut_L1TAU40();
      } else {
         L2_tauNoCut_L1TAU40() = 0;
      }
      if( parent.L2_tauNoCut_cosmic.IsAvailable() ) {
         L2_tauNoCut_cosmic() = parent.L2_tauNoCut_cosmic();
      } else {
         L2_tauNoCut_cosmic() = 0;
      }
      if( parent.L2_xe25.IsAvailable() ) {
         L2_xe25() = parent.L2_xe25();
      } else {
         L2_xe25() = 0;
      }
      if( parent.L2_xe35.IsAvailable() ) {
         L2_xe35() = parent.L2_xe35();
      } else {
         L2_xe35() = 0;
      }
      if( parent.L2_xe40.IsAvailable() ) {
         L2_xe40() = parent.L2_xe40();
      } else {
         L2_xe40() = 0;
      }
      if( parent.L2_xe45.IsAvailable() ) {
         L2_xe45() = parent.L2_xe45();
      } else {
         L2_xe45() = 0;
      }
      if( parent.L2_xe45T.IsAvailable() ) {
         L2_xe45T() = parent.L2_xe45T();
      } else {
         L2_xe45T() = 0;
      }
      if( parent.L2_xe55.IsAvailable() ) {
         L2_xe55() = parent.L2_xe55();
      } else {
         L2_xe55() = 0;
      }
      if( parent.L2_xe55T.IsAvailable() ) {
         L2_xe55T() = parent.L2_xe55T();
      } else {
         L2_xe55T() = 0;
      }
      if( parent.L2_xe55_LArNoiseBurst.IsAvailable() ) {
         L2_xe55_LArNoiseBurst() = parent.L2_xe55_LArNoiseBurst();
      } else {
         L2_xe55_LArNoiseBurst() = 0;
      }
      if( parent.L2_xe65.IsAvailable() ) {
         L2_xe65() = parent.L2_xe65();
      } else {
         L2_xe65() = 0;
      }
      if( parent.L2_xe65_tight.IsAvailable() ) {
         L2_xe65_tight() = parent.L2_xe65_tight();
      } else {
         L2_xe65_tight() = 0;
      }
      if( parent.L2_xe75.IsAvailable() ) {
         L2_xe75() = parent.L2_xe75();
      } else {
         L2_xe75() = 0;
      }
      if( parent.L2_xe90.IsAvailable() ) {
         L2_xe90() = parent.L2_xe90();
      } else {
         L2_xe90() = 0;
      }
      if( parent.L2_xe90_tight.IsAvailable() ) {
         L2_xe90_tight() = parent.L2_xe90_tight();
      } else {
         L2_xe90_tight() = 0;
      }

      return *this;
   }

} // namespace D3PDReader
