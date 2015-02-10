#slimming code
import math
import ROOT
from ROOT import (TFile,TDirectory,TParameter,
                  TChain,TTree, TLorentzVector,TFormula)

from array import array

#ROOT.gROOT.ProcessLine('.L Loader.C+') 

#from typemap_novec import typemap_novec as typemap_novec
#from typemap_vec import typemap_vec as typemap_vec
#from typemap_vecvec import typemap_vecvec as typemap_vecvec
#from initmap_novec import initmap_novec as initmap_novec




TTree.SetMaxTreeSize( 5 * 1024 * 1024 * 1024 )

TFormula.SetMaxima(100000)


import sys
print "sys.argv = ", sys.argv

if not len(sys.argv)>=5:  raise(Exception, "Must specify inputFiles as argument!")
    
INPUTDATA = sys.argv[1].split(',')  ##was -1
print "inputFiles = ", INPUTDATA

FILETYPE = sys.argv[2]
TREENAME = sys.argv[3]
OUTPUTFILENAME = sys.argv[4]


#######################################################################
#
# SLIM: Select branches from the TTree
#
#######################################################################
def selectBranches(TREE):
    TREE.SetBranchStatus("*",0)


     ##trigger selector
    TREE.SetBranchStatus("trig_DB_SMK",1)
    TREE.SetBranchStatus("trig_Nav_n",1)
    TREE.SetBranchStatus("trig_Nav_chain_ChainId",1)
    TREE.SetBranchStatus("trig_Nav_chain_RoIType",1)
    TREE.SetBranchStatus("trig_Nav_chain_RoIIndex",1)
    TREE.SetBranchStatus("trig_RoI_EF_e_egammaContainer_egamma_Electrons",1)
    TREE.SetBranchStatus("trig_RoI_EF_e_egammaContainer_egamma_ElectronsStatus",1)
    TREE.SetBranchStatus("trig_EF_el_n",1)
    TREE.SetBranchStatus("trig_EF_el_Et",1)
    TREE.SetBranchStatus("trig_EF_el_eta",1)
    TREE.SetBranchStatus("trig_EF_el_phi",1)
    TREE.SetBranchStatus("trig_RoI_EF_mu_Muon_ROI",1)
    TREE.SetBranchStatus("trig_RoI_EF_mu_TrigMuonEFInfoContainer",1)
    TREE.SetBranchStatus("trig_RoI_EF_mu_TrigMuonEFInfoContainerStatus",1)
    TREE.SetBranchStatus("trig_RoI_L2_mu_CombinedMuonFeature",1)
    TREE.SetBranchStatus("trig_RoI_L2_mu_CombinedMuonFeatureStatus",1)
    TREE.SetBranchStatus("trig_RoI_L2_mu_MuonFeature",1)
    TREE.SetBranchStatus("trig_RoI_L2_mu_Muon_ROI",1)
    TREE.SetBranchStatus("trig_EF_trigmuonef_track_MuonType",1)
    TREE.SetBranchStatus("trig_EF_trigmuonef_track_CB_pt",1)
    TREE.SetBranchStatus("trig_EF_trigmuonef_track_CB_eta",1)
    TREE.SetBranchStatus("trig_EF_trigmuonef_track_CB_phi",1)
    TREE.SetBranchStatus("trig_EF_trigmuonef_track_SA_pt",1)
    TREE.SetBranchStatus("trig_EF_trigmuonef_track_SA_eta",1)
    TREE.SetBranchStatus("trig_EF_trigmuonef_track_SA_phi",1)
    TREE.SetBranchStatus("trig_EF_trigmugirl_track_CB_pt",1)
    TREE.SetBranchStatus("trig_EF_trigmugirl_track_CB_eta",1)
    TREE.SetBranchStatus("trig_EF_trigmugirl_track_CB_phi",1)
    TREE.SetBranchStatus("trig_L2_combmuonfeature_eta",1)
    TREE.SetBranchStatus("trig_L2_combmuonfeature_phi",1)
    TREE.SetBranchStatus("trig_L2_muonfeature_eta",1)
    TREE.SetBranchStatus("trig_L2_muonfeature_phi",1)
    TREE.SetBranchStatus("trig_L1_mu_eta",1)
    TREE.SetBranchStatus("trig_L1_mu_phi",1)
    TREE.SetBranchStatus("trig_L1_mu_thrName",1)
    TREE.SetBranchStatus("trig_L1_TAV",1)
    TREE.SetBranchStatus("trig_RoI_EF_mu_TrigMuonEFIsolationContainer",1)
    TREE.SetBranchStatus("trig_RoI_EF_mu_TrigMuonEFIsolationContainerStatus",1)

    ##electron selector
    TREE.SetBranchStatus("el_n",1)
    TREE.SetBranchStatus("el_charge",1)
    TREE.SetBranchStatus("el_cl_E",1)
    TREE.SetBranchStatus("el_cl_pt",1)
    TREE.SetBranchStatus("el_Et",1)
    TREE.SetBranchStatus("el_pt",1)    
    TREE.SetBranchStatus("el_etas2",1)
    TREE.SetBranchStatus("el_author",1)
    TREE.SetBranchStatus("el_refittedTrack_LMqoverp",1)
    TREE.SetBranchStatus("el_refittedTrack_author",1)
    TREE.SetBranchStatus("el_trackqoverp",1)
    TREE.SetBranchStatus("el_nTRTHits",1)
    TREE.SetBranchStatus("el_nTRTOutliers",1)
    TREE.SetBranchStatus("el_nTRTHighTHits",1)
    TREE.SetBranchStatus("el_nTRTHighTOutliers",1)
    TREE.SetBranchStatus("el_etas2",1)
    TREE.SetBranchStatus("el_Ethad",1)
    TREE.SetBranchStatus("el_Ethad1",1)
    TREE.SetBranchStatus("el_reta",1)
    TREE.SetBranchStatus("el_weta2",1)
    TREE.SetBranchStatus("el_f1",1)
    TREE.SetBranchStatus("el_f3",1)
    TREE.SetBranchStatus("el_wstot",1)
    TREE.SetBranchStatus("el_emaxs1",1)
    TREE.SetBranchStatus("el_Emax2",1)
    TREE.SetBranchStatus("el_deltaeta1",1)
    TREE.SetBranchStatus("el_nSCTHits",1)
    TREE.SetBranchStatus("el_nSiHits",1)
    TREE.SetBranchStatus("el_nSCTDeadSensors",1)
    TREE.SetBranchStatus("el_nPixelDeadSensors",1)
    TREE.SetBranchStatus("el_nPixHits",1)
    TREE.SetBranchStatus("el_nPixelDeadSensors",1)
    TREE.SetBranchStatus("el_deltaphiRescaled",1)
    TREE.SetBranchStatus("el_nBLHits",1)
    TREE.SetBranchStatus("el_expectBLayerHit",1)
    TREE.SetBranchStatus("el_expectHitInBLayer",1)
    TREE.SetBranchStatus("el_cl_eta",1)
    TREE.SetBranchStatus("el_cl_phi",1)
    TREE.SetBranchStatus("el_tracketa",1)
    TREE.SetBranchStatus("el_trackphi",1)
    TREE.SetBranchStatus("el_trackpt",1)
    TREE.SetBranchStatus("el_OQ",1)
    TREE.SetBranchStatus("el_trackz0pvunbiased",1)
    TREE.SetBranchStatus("el_trackd0pvunbiased",1)
    TREE.SetBranchStatus("el_tracksigd0pvunbiased",1)
    TREE.SetBranchStatus("el_Unrefittedtrack_d0",1)
    TREE.SetBranchStatus("el_Unrefittedtrack_z0",1)
    TREE.SetBranchStatus("el_Unrefittedtrack_theta",1)
    TREE.SetBranchStatus("el_Unrefittedtrack_phi",1)
    TREE.SetBranchStatus("el_Unrefittedtrack_eta",1)
    TREE.SetBranchStatus("el_Unrefittedtrack_qoverp",1)
    TREE.SetBranchStatus("el_trackcov_d0",1)
    TREE.SetBranchStatus("el_trackcov_d0_phi",1)
    TREE.SetBranchStatus("el_trackcov_d0_qoverp",1)
    TREE.SetBranchStatus("el_trackcov_d0_theta",1)
    TREE.SetBranchStatus("el_trackcov_d0_z0",1)
    TREE.SetBranchStatus("el_trackcov_z0",1)
    TREE.SetBranchStatus("el_trackcov_z0_phi",1)
    TREE.SetBranchStatus("el_trackcov_z0_qoverp",1)
    TREE.SetBranchStatus("el_trackcov_z0_theta",1)
    TREE.SetBranchStatus("el_trackcov_qoverp",1)
    TREE.SetBranchStatus("el_trackcov_theta",1)
    TREE.SetBranchStatus("el_trackcov_theta_qoverp",1)
    TREE.SetBranchStatus("el_trackcov_phi",1)
    TREE.SetBranchStatus("el_trackcov_phi_qoverp",1)
    TREE.SetBranchStatus("el_trackcov_phi_theta",1)
    TREE.SetBranchStatus("el_ptcone20",1)
    TREE.SetBranchStatus("el_ptcone30",1)
    TREE.SetBranchStatus("el_ptcone40",1)
    TREE.SetBranchStatus("el_Etcone20",1)
    TREE.SetBranchStatus("el_Etcone30",1)
    TREE.SetBranchStatus("el_Etcone40",1)
    TREE.SetBranchStatus("el_topoEtcone20",1)
    TREE.SetBranchStatus("el_topoEtcone30",1)
    TREE.SetBranchStatus("el_topoEtcone40",1)
    TREE.SetBranchStatus("el_topoEtcone60",1)
    TREE.SetBranchStatus("el_topoEtcone20",1)
    TREE.SetBranchStatus("el_ED_median",1)
    TREE.SetBranchStatus("el_etap",1)
    TREE.SetBranchStatus("el_rphi",1)
    TREE.SetBranchStatus("el_isEM",1)
    TREE.SetBranchStatus("el_Emins1",1)
    TREE.SetBranchStatus("el_fside",1)
    TREE.SetBranchStatus("el_ws3",1)
    TREE.SetBranchStatus("el_deltaphi2",1)
    TREE.SetBranchStatus("el_tracktheta",1)
    TREE.SetBranchStatus("el_nPixelOutliers",1)
    TREE.SetBranchStatus("el_nBLayerOutliers",1)
    TREE.SetBranchStatus("el_nSCTOutliers",1)
    TREE.SetBranchStatus("el_TRTHighTHitsRatio",1)
    TREE.SetBranchStatus("el_TRTHighTOutliersRatio",1)
    TREE.SetBranchStatus("el_deltaEmax2",1)
    TREE.SetBranchStatus("el_trackd0pv",1)
    TREE.SetBranchStatus("el_trackd0_physics",1)
    TREE.SetBranchStatus("el_tracksigd0pv",1)
    TREE.SetBranchStatus("el_Es0",1)
    TREE.SetBranchStatus("el_Es1",1)
    TREE.SetBranchStatus("el_Es2",1)
    TREE.SetBranchStatus("el_Es3",1)
    TREE.SetBranchStatus("el_type",1)
    TREE.SetBranchStatus("el_origin",1)
    TREE.SetBranchStatus("el_originbkg",1)
    TREE.SetBranchStatus("el_typebkg",1)
    TREE.SetBranchStatus("trig_L1_emtau_n",1)
    TREE.SetBranchStatus("trig_L1_emtau_eta",1)
    TREE.SetBranchStatus("trig_L1_emtau_phi",1)
    TREE.SetBranchStatus("el_rawcl_E",1)
    TREE.SetBranchStatus("el_phis2",1)
    ## More electron selector
    TREE.SetBranchStatus("el_E237"                ,1)
    TREE.SetBranchStatus("el_E277"                ,1)
    TREE.SetBranchStatus("el_f1core"              ,1)
    TREE.SetBranchStatus("el_nTRTXenonHits"       ,1)
    TREE.SetBranchStatus("el_rawcl_Es0"           ,1)
    TREE.SetBranchStatus("el_rawcl_Es1"           ,1)
    TREE.SetBranchStatus("el_rawcl_Es2"           ,1)
    TREE.SetBranchStatus("el_rawcl_Es3"           ,1)
    TREE.SetBranchStatus("el_cl_etaCalo"          ,1)
    TREE.SetBranchStatus("el_cl_phiCalo"          ,1)
    TREE.SetBranchStatus("el_calibHitsShowerDepth",1)

    ##muon selector
    ##staco
    TREE.SetBranchStatus("mu_staco_n",1)
    TREE.SetBranchStatus("mu_staco_charge",1)
    TREE.SetBranchStatus("mu_staco_author",1)
    TREE.SetBranchStatus("mu_staco_isStandAloneMuon",1)
    TREE.SetBranchStatus("mu_staco_isCombinedMuon",1)
    TREE.SetBranchStatus("mu_staco_isSegmentTaggedMuon",1)
    TREE.SetBranchStatus("mu_staco_pt",1)
    TREE.SetBranchStatus("mu_staco_eta",1)
    TREE.SetBranchStatus("mu_staco_E",1)
    TREE.SetBranchStatus("mu_staco_m",1)
    TREE.SetBranchStatus("mu_staco_expectBLayerHit",1)
    TREE.SetBranchStatus("mu_staco_nBLHits",1)
    TREE.SetBranchStatus("mu_staco_nPixHits",1)
    TREE.SetBranchStatus("mu_staco_nPixelDeadSensors",1)
    TREE.SetBranchStatus("mu_staco_nSCTHits",1)
    TREE.SetBranchStatus("mu_staco_nSCTDeadSensors",1)
    TREE.SetBranchStatus("mu_staco_nPixHoles",1)
    TREE.SetBranchStatus("mu_staco_nSCTHoles",1)
    TREE.SetBranchStatus("mu_staco_nTRTOutliers",1)
    TREE.SetBranchStatus("mu_staco_nTRTHits",1)
    TREE.SetBranchStatus("mu_staco_nTRTOutliers",1)
    TREE.SetBranchStatus("mu_staco_d0_exPV",1)
    TREE.SetBranchStatus("mu_staco_z0_exPV",1)
    TREE.SetBranchStatus("mu_staco_nCSCEtaHits",1)
    TREE.SetBranchStatus("mu_staco_nCSCPhiHits",1)
    TREE.SetBranchStatus("mu_staco_nMDTEMHits",1)
    TREE.SetBranchStatus("mu_staco_nMDTEOHits",1)
    TREE.SetBranchStatus("mu_staco_phi",1)
    TREE.SetBranchStatus("mu_staco_id_phi",1) 
    TREE.SetBranchStatus("mu_staco_id_theta",1)
    TREE.SetBranchStatus("mu_staco_id_qoverp",1)
    TREE.SetBranchStatus("mu_staco_ms_phi",1)
    TREE.SetBranchStatus("mu_staco_ms_theta",1)
    TREE.SetBranchStatus("mu_staco_ms_qoverp",1)
    TREE.SetBranchStatus("mu_staco_me_phi",1)
    TREE.SetBranchStatus("mu_staco_me_theta",1)
    TREE.SetBranchStatus("mu_staco_me_qoverp",1)
    TREE.SetBranchStatus("mu_staco_isCaloMuonId",1)
    TREE.SetBranchStatus("mu_staco_caloLRLikelihood",1)
    TREE.SetBranchStatus("mu_staco_ptcone20",1)
    TREE.SetBranchStatus("mu_staco_ptcone30",1)
    TREE.SetBranchStatus("mu_staco_ptcone40",1)
    TREE.SetBranchStatus("mu_staco_etcone20",1)
    TREE.SetBranchStatus("mu_staco_etcone30",1)
    TREE.SetBranchStatus("mu_staco_etcone40",1)
    TREE.SetBranchStatus("mu_staco_trackz0pvunbiased",1)
    TREE.SetBranchStatus("mu_staco_trackd0pvunbiased",1)
    TREE.SetBranchStatus("mu_staco_tracksigd0pvunbiased",1)
    TREE.SetBranchStatus("mu_staco_trackIPEstimate_d0_unbiasedpvunbiased",1)
    TREE.SetBranchStatus("mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased",1)        
    TREE.SetBranchStatus("mu_staco_phi_exPV",1)
    TREE.SetBranchStatus("mu_staco_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_staco_theta_exPV",1)
    TREE.SetBranchStatus("mu_staco_d0_exPV",1)
    TREE.SetBranchStatus("mu_staco_z0_exPV",1)   
    TREE.SetBranchStatus("mu_staco_cov_d0_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_d0_phi_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_d0_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_d0_theta_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_d0_z0_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_z0_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_z0_phi_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_z0_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_z0_theta_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_theta_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_theta_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_phi_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_phi_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_staco_cov_phi_theta_exPV",1)

    ##muon selector
    ##calo
    TREE.SetBranchStatus("mu_calo_n",1)
    TREE.SetBranchStatus("mu_calo_charge",1)
    TREE.SetBranchStatus("mu_calo_author",1)    
    TREE.SetBranchStatus("mu_calo_caloLRLikelihood",1)
    TREE.SetBranchStatus("mu_calo_caloMuonIdTag",1)
    TREE.SetBranchStatus("mu_calo_pt",1)
    TREE.SetBranchStatus("mu_calo_eta",1)
    TREE.SetBranchStatus("mu_calo_phi",1)
    TREE.SetBranchStatus("mu_calo_m",1)
    TREE.SetBranchStatus("mu_calo_E",1)
    TREE.SetBranchStatus("mu_calo_id_d0",1)
    TREE.SetBranchStatus("mu_calo_id_z0",1)
    TREE.SetBranchStatus("mu_calo_id_theta",1)
    TREE.SetBranchStatus("mu_calo_id_phi",1)
    TREE.SetBranchStatus("mu_calo_id_qoverp",1)
    TREE.SetBranchStatus("mu_calo_cov_d0_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_d0_phi_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_d0_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_d0_theta_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_d0_z0_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_z0_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_z0_phi_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_z0_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_z0_theta_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_theta_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_theta_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_phi_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_phi_qoverp_exPV",1)
    TREE.SetBranchStatus("mu_calo_cov_phi_theta_exPV",1)
    TREE.SetBranchStatus("mu_calo_ms_phi",1)
    TREE.SetBranchStatus("mu_calo_ms_theta",1)
    TREE.SetBranchStatus("mu_calo_ms_qoverp",1)
    TREE.SetBranchStatus("mu_calo_isCombinedMuon",1)
    TREE.SetBranchStatus("mu_calo_expectBLayerHit",1)
    TREE.SetBranchStatus("mu_calo_nBLHits",1)
    TREE.SetBranchStatus("mu_calo_nPixHits",1)
    TREE.SetBranchStatus("mu_calo_nPixelDeadSensors",1)
    TREE.SetBranchStatus("mu_calo_nSCTHits",1)
    TREE.SetBranchStatus("mu_calo_nSCTDeadSensors",1)
    TREE.SetBranchStatus("mu_calo_nPixHoles",1)
    TREE.SetBranchStatus("mu_calo_nSCTHoles",1)
    TREE.SetBranchStatus("mu_calo_nTRTOutliers",1)
    TREE.SetBranchStatus("mu_calo_nTRTHits",1)
    TREE.SetBranchStatus("mu_calo_nTRTOutliers",1)
    TREE.SetBranchStatus("mu_calo_d0_exPV",1)
    TREE.SetBranchStatus("mu_calo_z0_exPV",1)
    TREE.SetBranchStatus("mu_calo_isStandAloneMuon",1)
    TREE.SetBranchStatus("mu_calo_ptcone20",1)
    TREE.SetBranchStatus("mu_calo_ptcone30",1)
    TREE.SetBranchStatus("mu_calo_ptcone40",1)
    TREE.SetBranchStatus("mu_calo_etcone20",1)
    TREE.SetBranchStatus("mu_calo_etcone30",1)
    TREE.SetBranchStatus("mu_calo_etcone40",1)
    TREE.SetBranchStatus("mu_calo_trackz0pvunbiased",1)
    TREE.SetBranchStatus("mu_calo_trackd0pvunbiased",1)
    TREE.SetBranchStatus("mu_calo_tracksigd0pvunbiased",1)
    TREE.SetBranchStatus("mu_calo_trackIPEstimate_d0_unbiasedpvunbiased",1)
    TREE.SetBranchStatus("mu_calo_trackIPEstimate_sigd0_unbiasedpvunbiased",1)
    TREE.SetBranchStatus("mu_calo_isSegmentTaggedMuon",1)

    ####jets
    TREE.SetBranchStatus("jet_akt4topoem_n",1)
    TREE.SetBranchStatus("jet_akt4topoem_m",1)
    TREE.SetBranchStatus("jet_akt4topoem_E",1)
    TREE.SetBranchStatus("jet_akt4topoem_pt",1)
    TREE.SetBranchStatus("jet_akt4topoem_eta",1)
    TREE.SetBranchStatus("jet_akt4topoem_phi",1)
    TREE.SetBranchStatus("jet_akt4topoem_emscale_m",1)
    TREE.SetBranchStatus("jet_akt4topoem_emscale_E",1)
    TREE.SetBranchStatus("jet_akt4topoem_emscale_pt",1)
    TREE.SetBranchStatus("jet_akt4topoem_emscale_eta",1)
    TREE.SetBranchStatus("jet_akt4topoem_emscale_phi",1)
    TREE.SetBranchStatus("jet_akt4topoem_jvtxf",1)
    TREE.SetBranchStatus("jet_akt4topoem_isBadTight",1)
    TREE.SetBranchStatus("jet_akt4topoem_isBadMedium",1)
    TREE.SetBranchStatus("jet_akt4topoem_isBadLoose",1)
    TREE.SetBranchStatus("jet_akt4topoem_isBadLooseMinus",1)
    TREE.SetBranchStatus("jet_akt4topoem_fracSamplingMax",1)
    TREE.SetBranchStatus("jet_akt4topoem_SamplingMax",1)
    TREE.SetBranchStatus("jet_akt4topoem_flavor_weight_MV1",1)##new
    TREE.SetBranchStatus("jet_akt4topoem_ActiveAreaPx",1)
    TREE.SetBranchStatus("jet_akt4topoem_ActiveAreaPy",1) 
    TREE.SetBranchStatus("jet_akt4topoem_ActiveAreaPz",1)
    TREE.SetBranchStatus("jet_akt4topoem_ActiveAreaE",1) 

    TREE.SetBranchStatus("jet_antikt4truth_n",1)
    TREE.SetBranchStatus("jet_antikt4truth_m",1)
    TREE.SetBranchStatus("jet_antikt4truth_E",1)
    TREE.SetBranchStatus("jet_antikt4truth_pt",1)
    TREE.SetBranchStatus("jet_antikt4truth_eta",1)
    TREE.SetBranchStatus("jet_antikt4truth_phi",1)
    TREE.SetBranchStatus("jet_antikt4truth_emscale_m",1)
    TREE.SetBranchStatus("jet_antikt4truth_emscale_E",1)
    TREE.SetBranchStatus("jet_antikt4truth_emscale_pt",1)
    TREE.SetBranchStatus("jet_antikt4truth_emscale_eta",1)
    TREE.SetBranchStatus("jet_antikt4truth_emscale_phi",1)
    TREE.SetBranchStatus("jet_antikt4truth_isBadTight",1)
    TREE.SetBranchStatus("jet_antikt4truth_isBadMedium",1)
    TREE.SetBranchStatus("jet_antikt4truth_isBadLoose",1)
    TREE.SetBranchStatus("jet_antikt4truth_isBadLooseMinus",1)
    TREE.SetBranchStatus("jet_antikt4truth_fracSamplingMax",1)
    TREE.SetBranchStatus("jet_antikt4truth_SamplingMax",1)
    TREE.SetBranchStatus("jet_antikt4truth_ActiveAreaPx",1)
    TREE.SetBranchStatus("jet_antikt4truth_ActiveAreaPy",1) 
    TREE.SetBranchStatus("jet_antikt4truth_ActiveAreaPz",1)
    TREE.SetBranchStatus("jet_antikt4truth_ActiveAreaE",1) 
    
    ###photons
    TREE.SetBranchStatus("ph_origin",1)
    TREE.SetBranchStatus("ph_type",1)
    TREE.SetBranchStatus("ph_tight",1)
    TREE.SetBranchStatus("ph_originbkg",1)
    TREE.SetBranchStatus("ph_n",1)
    TREE.SetBranchStatus("ph_el_index",1)
    TREE.SetBranchStatus("ph_author",1)
    TREE.SetBranchStatus("ph_cl_E",1)
    TREE.SetBranchStatus("ph_cl_eta",1)
    TREE.SetBranchStatus("ph_cl_phi",1)
    TREE.SetBranchStatus("ph_cl_pt",1)
    TREE.SetBranchStatus("ph_pt",1)
    TREE.SetBranchStatus("ph_Et",1)
    TREE.SetBranchStatus("ph_m",1)
    TREE.SetBranchStatus("ph_etas2",1)
    TREE.SetBranchStatus("ph_eta",1)##new
    TREE.SetBranchStatus("ph_reta",1)
    TREE.SetBranchStatus("ph_rphi",1)
    TREE.SetBranchStatus("ph_etap",1)
    TREE.SetBranchStatus("ph_phi",1)
    TREE.SetBranchStatus("ph_px",1)
    TREE.SetBranchStatus("ph_py",1)
    TREE.SetBranchStatus("ph_pz",1)
    TREE.SetBranchStatus("ph_author",1)
    TREE.SetBranchStatus("ph_isEM",1)
    TREE.SetBranchStatus("ph_OQ",1)    
    TREE.SetBranchStatus("ph_tightAR",1)
    TREE.SetBranchStatus("ph_Rconv",1)
    TREE.SetBranchStatus("ph_isConv",1)
    TREE.SetBranchStatus("ph_convFlag",1)
    TREE.SetBranchStatus("ph_topoEtcone20",1)
    TREE.SetBranchStatus("ph_topoEtcone30",1)
    TREE.SetBranchStatus("ph_topoEtcone40",1)
    TREE.SetBranchStatus("ph_Etcone20",1)
    TREE.SetBranchStatus("ph_Etcone30",1)
    TREE.SetBranchStatus("ph_Etcone40",1)
    TREE.SetBranchStatus("ph_Etcone40_ED_corrected",1)    
    TREE.SetBranchStatus("ph_ED_median",1)
    TREE.SetBranchStatus("ph_Ethad1",1);
    TREE.SetBranchStatus("ph_Ethad",1);
    TREE.SetBranchStatus("ph_E277",1);
    TREE.SetBranchStatus("ph_E237",1);
    TREE.SetBranchStatus("ph_E233",1);
    TREE.SetBranchStatus("ph_weta2",1);
    TREE.SetBranchStatus("ph_f1",1);
    TREE.SetBranchStatus("ph_fside",1);
    TREE.SetBranchStatus("ph_Emax2",1);
    TREE.SetBranchStatus("ph_Emins1",1);
    TREE.SetBranchStatus("ph_wstot",1);
    TREE.SetBranchStatus("ph_ws3",1);
    TREE.SetBranchStatus("ph_deltaEs",1);
    TREE.SetBranchStatus("ph_emaxs1",1);    
    # photon calibration
    TREE.SetBranchStatus("ph_rawcl_Es0"       ,1)
    TREE.SetBranchStatus("ph_rawcl_Es1"       ,1)
    TREE.SetBranchStatus("ph_rawcl_Es2"       ,1)
    TREE.SetBranchStatus("ph_rawcl_Es3"       ,1)
    TREE.SetBranchStatus("ph_cl_etaCalo"      ,1)
    TREE.SetBranchStatus("ph_cl_phiCalo"      ,1)
    TREE.SetBranchStatus("ph_ptconv"          ,1)
    TREE.SetBranchStatus("ph_pt1conv"         ,1)
    TREE.SetBranchStatus("ph_pt2conv"         ,1)
    TREE.SetBranchStatus("ph_convtrk1nPixHits",1)
    TREE.SetBranchStatus("ph_convtrk1nSCTHits",1)
    TREE.SetBranchStatus("ph_convtrk2nPixHits",1)
    TREE.SetBranchStatus("ph_convtrk2nSCTHits",1)

    ###MET
    TREE.SetBranchStatus("MET_RefFinal_et",1)
    TREE.SetBranchStatus("MET_RefFinal_sumet",1)
    TREE.SetBranchStatus("MET_RefFinal_phi",1)

    ##general stuff
    TREE.SetBranchStatus("RunNumber",1)
    TREE.SetBranchStatus("EventNumber",1)
    TREE.SetBranchStatus("lbn",1)
    TREE.SetBranchStatus("actualIntPerXing",1)
    TREE.SetBranchStatus("averageIntPerXing",1)
    TREE.SetBranchStatus("bcid",1)
    TREE.SetBranchStatus("bunch_configID",1)
    TREE.SetBranchStatus("larError",1)
    TREE.SetBranchStatus("tileError",1)
    TREE.SetBranchStatus("coreFlags",1)
    TREE.SetBranchStatus("Eventshape_rhoKt4EM",1)
     
    ##vertices
    TREE.SetBranchStatus("vxp_n",1)
    TREE.SetBranchStatus("vxp_nTracks",1)

    ##trigger objects
    TREE.SetBranchStatus("trig_EF_el_n",1)
    TREE.SetBranchStatus("trig_EF_el_phi",1)
    TREE.SetBranchStatus("trig_EF_el_eta",1)
    TREE.SetBranchStatus("trig_EF_el_EF_e24vhi_medium1",1)
    TREE.SetBranchStatus("trig_EF_el_EF_e60_medium1",1)
         

    ##trigger
    #ele 2011
    if TREE.GetBranch("L1_EM12")!=0:
        TREE.SetBranchStatus("L1_EM12",1)
    if TREE.GetBranch("EF_2e12_medium")!=0:
        TREE.SetBranchStatus("EF_2e12_medium",1)
    if TREE.GetBranch("EF_2e12T_medium")!=0:
        TREE.SetBranchStatus("EF_2e12T_medium",1)   
    if TREE.GetBranch("EF_2e12Tvh_medium")!=0:
        TREE.SetBranchStatus("EF_2e12Tvh_medium",1)     
    if TREE.GetBranch("EF_e20_medium")!=0:
        TREE.SetBranchStatus("EF_e20_medium",1)
    if TREE.GetBranch("EF_e22_medium")!=0:
        TREE.SetBranchStatus("EF_e22_medium",1)
    if TREE.GetBranch("EF_e22vh_medium1")!=0:
        TREE.SetBranchStatus("EF_e22vh_medium1",1)
    #mu 2011    
    if TREE.GetBranch("EF_mu18_MG")!=0:
        TREE.SetBranchStatus("EF_mu18_MG",1)      
    if TREE.GetBranch("EF_mu18_MG_medium")!=0:
        TREE.SetBranchStatus("EF_mu18_MG_medium",1)      
    if TREE.GetBranch("EF_2mu10_loose")!=0:
        TREE.SetBranchStatus("EF_2mu10_loose",1)
    #ele 2012
    if TREE.GetBranch("L1_EM14VH")!=0:
        TREE.SetBranchStatus("L1_EM14VH",1)
    if TREE.GetBranch("L1_EM16VH")!=0:
        TREE.SetBranchStatus("L1_EM16VH",1)
    if TREE.GetBranch("L1_EM18VH")!=0:
        TREE.SetBranchStatus("L1_EM18VH",1)
    if TREE.GetBranch("EF_e24vhi_medium1")!=0:
        TREE.SetBranchStatus("EF_e24vhi_medium1",1)
    if TREE.GetBranch("EF_e25vhi_medium1")!=0:
        TREE.SetBranchStatus("EF_e25vhi_medium1",1)    
    if TREE.GetBranch("EF_e60_medium1")!=0:
        TREE.SetBranchStatus("EF_e60_medium1",1) 
    if TREE.GetBranch("EF_2e12Tvh_loose1")!=0:
        TREE.SetBranchStatus("EF_2e12Tvh_loose1",1)
    if TREE.GetBranch("EF_2e12Tvh_loose1_L2StarB")!=0:
        TREE.SetBranchStatus("EF_2e12Tvh_loose1_L2StarB",1)
    #mu 2012
    if TREE.GetBranch("EF_mu24i_tight")!=0:
        TREE.SetBranchStatus("EF_mu24i_tight",1)      
    if TREE.GetBranch("EF_mu36_tight")!=0:
        TREE.SetBranchStatus("EF_mu36_tight",1) 
    if TREE.GetBranch("EF_2mu13")!=0:
        TREE.SetBranchStatus("EF_2mu13",1)
    if TREE.GetBranch("EF_mu18_tight_mu8_EFFS")!=0:
        TREE.SetBranchStatus("EF_mu18_tight_mu8_EFFS",1)
    #ele mu 2012
    if TREE.GetBranch("EF_e12Tvh_medium1_mu8")!=0:
        TREE.SetBranchStatus("EF_e12Tvh_medium1_mu8",1)
    if TREE.GetBranch("EF_e24vhi_loose1_mu8")!=0:
        TREE.SetBranchStatus("EF_e24vhi_loose1_mu8",1)
    
    if FILETYPE == "mc":
        #EL_TRUTH
        TREE.SetBranchStatus("el_truth_type",1)
        TREE.SetBranchStatus("el_truth_matched",1)
        TREE.SetBranchStatus("el_truth_mothertype",1)
        
        ##truth photons
        TREE.SetBranchStatus("ph_truth_type",1)
        TREE.SetBranchStatus("ph_truth_matched",1)
        TREE.SetBranchStatus("ph_truth_status",1)
        TREE.SetBranchStatus("ph_truth_barcode",1)
        TREE.SetBranchStatus("ph_truth_mothertype",1)
        TREE.SetBranchStatus("ph_truth_motherbarcode",1)

        ##MC stuff
        TREE.SetBranchStatus("mc_channel_number",1)
        TREE.SetBranchStatus("mc_n",1)
        TREE.SetBranchStatus("mc_barcode",1)
        TREE.SetBranchStatus("mc_charge",1)
        TREE.SetBranchStatus("mc_child_index",1)
        TREE.SetBranchStatus("mc_parent_index",1)
        TREE.SetBranchStatus("mc_children",1)
        TREE.SetBranchStatus("mc_parents",1)
        TREE.SetBranchStatus("mc_eta",1)
        TREE.SetBranchStatus("mc_phi",1)
        TREE.SetBranchStatus("mc_pt",1)
        TREE.SetBranchStatus("mc_m",1)
        TREE.SetBranchStatus("mc_pdgId",1)
        TREE.SetBranchStatus("mc_status",1)
        TREE.SetBranchStatus("mc_vx_barcode",1)
        TREE.SetBranchStatus("mc_vx_x",1)
        TREE.SetBranchStatus("mc_vx_y",1)
        TREE.SetBranchStatus("mc_vx_z",1)
        TREE.SetBranchStatus("mc_event_weight")
        TREE.SetBranchStatus("mcevt_weight")
        TREE.SetBranchStatus("mcevt_n")

#######################################################################
#
# Create Chains
#
#######################################################################
evtTreeName = TREENAME
metaName = evtTreeName+"Meta"


evtChain =TChain(evtTreeName)
metaChain=TChain(metaName+"/TrigConfTree")
[map(i.Add,INPUTDATA) for i in [evtChain,metaChain]]

# empty input
print " number of events ",  evtChain.GetEntries()
inputevents = TParameter(int)("n_inputevents",evtChain.GetEntries())

if evtChain.GetEntries()==0:
    print "Found 0 events - Aborting!"
    #g=TFile(OUTPUTFILENAME,"RECREATE")
    #newTree=ROOT.TTree(TREENAME,TREENAME)
    #newTree.Write()
    exit()


if FILETYPE != "mc":
    
    # SKIM: cut on electrons and muons
    # Select Events with cuts
    nEntries = evtChain.GetEntries()
    EntryList_4l=ROOT.TEntryList()
    evtChain.GetEntry(0)

           
    for i in range(nEntries):
    #for i in range(100): ###only for tests...
        evtChain.GetEntry(i)
        
        n_ele=evtChain.el_n
        n_muon_staco=evtChain.mu_staco_n
        n_muon_calo=evtChain.mu_calo_n

        n_ele_good=0
        n_muon_good=0

        n_ele1_good=0
        n_muon1_good=0

        n_ele2_good=0
        n_muon2_good=0

        electronLorentzVectors=[]
        muonLorentzVectors=[]

        ###################
        ###loop over electron
        for j_ele in range(n_ele):
        
            clus_e=evtChain.el_cl_E[j_ele]
            nSihits=evtChain.el_nSCTHits[j_ele]+evtChain.el_nPixHits[j_ele]
            try:
                clus_pt=clus_e/math.cosh(evtChain.el_cl_eta[j_ele])
            except:
                print "Oh Dear"
            if nSihits>=4:
                clus_pt=clus_e/math.cosh(evtChain.el_tracketa[j_ele])
            if not ( clus_pt>6500 
                     or evtChain.el_pt[j_ele]>=6500 
                     or evtChain.el_Et[j_ele]>=6500
                     or evtChain.el_cl_pt[j_ele]>=6500):
                continue
            #cut on Si hit
            if not nSihits>=1:
                continue
            
            #cut on author
            if not (evtChain.el_author[j_ele]==1 or evtChain.el_author[j_ele]==3): ###central
                continue

            #if made it till here, increment ele count
            n_ele_good=n_ele_good+1
            #also fill lorentzvector
            lorentzVector=ROOT.TLorentzVector()
            lorentzVector.SetPtEtaPhiE(clus_pt,evtChain.el_tracketa[j_ele],evtChain.el_trackphi[j_ele],clus_e)
            electronLorentzVectors.append(lorentzVector)
        
            #additional et cuts
            if ( clus_pt>=19000 or evtChain.el_pt[j_ele]>=19000 or evtChain.el_Et[j_ele]>=19000 or evtChain.el_cl_pt[j_ele]>=19000):
                n_ele1_good=n_ele1_good+1
            if ( clus_pt>=14000 or evtChain.el_pt[j_ele]>=14000 or evtChain.el_Et[j_ele]>=14000 or evtChain.el_cl_pt[j_ele]>=14000):
                n_ele2_good=n_ele2_good+1
        
                
        ###################
        ###loop over muons
        ###staco
        for j_muon in range(n_muon_staco):
            #if not ((evtChain.mu_staco_isCombinedMuon[j_muon]==1 or evtChain.mu_staco_isSegmentTaggedMuon[j_muon]==1) and (evtChain.mu_staco_author[j_muon]==6 or evtChain.mu_staco_author[j_muon]==7) and evtChain.mu_staco_pt[j_muon]>=6000):
            if not ((evtChain.mu_staco_isCombinedMuon[j_muon]==1 or evtChain.mu_staco_isSegmentTaggedMuon[j_muon]==1) and (evtChain.mu_staco_author[j_muon]==6 or evtChain.mu_staco_author[j_muon]==7) and evtChain.mu_staco_pt[j_muon]>=5500):
                continue
            #if made it till here, increment muon count
            n_muon_good=n_muon_good+1
            lorentzVector=ROOT.TLorentzVector()
            lorentzVector.SetPtEtaPhiE(evtChain.mu_staco_pt[j_muon],evtChain.mu_staco_eta[j_muon],evtChain.mu_staco_phi[j_muon],evtChain.mu_staco_E[j_muon])
            muonLorentzVectors.append(lorentzVector)
        
            #additional et cuts
            if not evtChain.mu_staco_pt[j_muon]>=8000:
                continue
            n_muon2_good=n_muon2_good+1
            #if not evtChain.mu_staco_pt[j_muon]>=14000:
            if not evtChain.mu_staco_pt[j_muon]>=20000:
                continue
            n_muon1_good=n_muon1_good+1
       
        ###calo
        for j_muon in range(n_muon_calo):
        ###remove overlap
            for j_muon_s in range(n_muon_staco):
                deltaPhi=math.fabs(evtChain.mu_staco_id_phi[j_muon_s]-evtChain.mu_calo_id_phi[j_muon])
                if(deltaPhi>math.pi):
                    deltaPhi=2*math.pi-deltaPhi
                if(evtChain.mu_staco_id_theta[j_muon_s]<=0 or evtChain.mu_calo_id_theta[j_muon]<=0):
                    continue
                deltaEta=math.fabs(math.log(math.tan(evtChain.mu_staco_id_theta[j_muon_s]/2.))-math.log(math.tan(evtChain.mu_calo_id_theta[j_muon]/2.)))
                deltaR= math.sqrt(pow(deltaPhi,2)+pow(deltaEta,2))
                if(deltaR<0.1):
                    continue
            
            if not evtChain.mu_calo_author[j_muon]==16 and evtChain.mu_calo_pt[j_muon]>=14000:
                    continue
            #if made it till here, increment muon count
            n_muon_good=n_muon_good+1
            lorentzVector=ROOT.TLorentzVector()
            lorentzVector.SetPtEtaPhiE(evtChain.mu_calo_pt[j_muon],evtChain.mu_calo_eta[j_muon],evtChain.mu_calo_phi[j_muon],evtChain.mu_calo_E[j_muon])
            muonLorentzVectors.append(lorentzVector)
        
            #additional et cuts
            if not evtChain.mu_calo_pt[j_muon]>=8000:
                continue
            if not math.fabs(evtChain.mu_calo_eta[j_muon])<0.1:
                continue
            n_muon2_good=n_muon2_good+1
            if not evtChain.mu_calo_pt[j_muon]>=14000:
                continue
            n_muon1_good=n_muon1_good+1
            
        ###loop over tlorentzvectors to check mass
        bestmasselediff=999999999
        for iele1 in range(len(electronLorentzVectors)):
            for iele2 in range(len(electronLorentzVectors)):
                if iele1 == iele2:
                    continue
                massdiff = math.fabs((electronLorentzVectors[iele1]+electronLorentzVectors[iele2]).M()-90000)
                if massdiff < bestmasselediff:
                    bestmasselediff=massdiff
   
        bestmassmuondiff=999999999
        for imu1 in range(len(muonLorentzVectors)):
            for imu2 in range(len(muonLorentzVectors)):
                if imu1 == imu2:
                    continue
                massdiff = math.fabs((muonLorentzVectors[imu1]+muonLorentzVectors[imu2]).M()-90000)
                if massdiff < bestmassmuondiff:
                    bestmassmuondiff=massdiff
        #print "bestmassmuondiff: ",bestmassmuondiff           
        #if (n_ele_good>=4 or n_muon_good>=4 or (n_ele_good>=2 and n_muon_good>=2)) and ((n_ele2_good>=2 and n_ele1_good>=1) or (n_muon2_good>=2 and n_muon1_good>=1)):
        #if (n_ele_good>=4 or n_muon_good>=4 or (n_ele_good>=2 and n_muon_good>=2)) and ((n_ele2_good>=2 and n_ele1_good>=1) or (n_muon2_good>=2 and n_muon1_good>=1)) and (bestmasselediff < 50000 or bestmassmuondiff < 50000):
        #if (n_ele_good>=2 or n_muon_good>=2) and ((n_ele2_good>=2 and n_ele1_good>=1) or (n_muon2_good>=2)):
        #if (n_ele_good>=2 or n_muon_good>=2) and ((n_ele2_good>=2 and n_ele1_good>=1) or (n_muon2_good>=2 and n_muon1_good>=1)):
        #if (n_ele_good>=2 or n_muon_good>=2) and ((n_ele2_good>=2 and n_ele1_good>=1) or (n_muon1_good>=1)):
        #if (n_ele_good>=2 or n_muon_good>=2) and ((n_ele2_good>=2 and n_ele1_good>=1) or (n_muon_good>=2)): #works...
        #if (n_ele_good>=2 or n_muon_good>=2) and ((n_ele2_good>=2 and n_ele1_good>=1) or (n_muon2_good>=2 and n_muon1_good>=1)) and (bestmasselediff < 50000 or bestmassmuondiff < 50000):
        if ((n_ele_good>=2 and n_ele2_good>=1) or (n_muon_good>=2 and n_muon1_good>=1)):
            EntryList_4l.Enter(i,evtChain)
           
    evtChain.SetEntryList(EntryList_4l)
    print " with 4l ", EntryList_4l.GetN()



#######################################################################
#
# Select and write out
#
#######################################################################
selectBranches(evtChain)
#g=TFile("skim_2l.root","RECREATE")
g=TFile(OUTPUTFILENAME,"RECREATE")
inputevents.Write()
nEntries = evtChain.GetEntries()
newTree=evtChain.CopyTree("","fast SortBasketsByOffset")
g.SetCompressionLevel(9)
newTree.Write()
g.mkdir(metaName); g.cd(metaName)
newMeta=metaChain.CloneTree(-1,"fast SortBasketsByOffset")
newMeta.BuildIndex("SMK","L1PSK")
newMeta.Write()


g.Close()
sys.exit()

