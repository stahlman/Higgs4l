#slimming code
import math,sys,os

import ROOT
from ROOT import *
#(TFile,TDirectory,TParameter, TChain,TTree, TLorentzVector,TFormula,gSystem)

#import PyCintex
#ROOT.gSystem.Load( "libCintex" )
#PyCintex.Cintex.Enable()

from array import array

#ROOT.gROOT.ProcessLine('.L Loader.C++') 
#from typemap_novec import typemap_novec as typemap_novec
#from typemap_vec import typemap_vec as typemap_vec
#from typemap_vecvec import typemap_vecvec as typemap_vecvec
#from initmap_novec import initmap_novec as initmap_novec

CWD = os.getcwd()
os.chdir(CWD)
gSystem.Load('egammaAnalysisUtils.so')
#gSystem.Load('libegammaEvent.so')
print 'egammaMenu.eg2012: '+str(egammaMenu.eg2012)
 
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
    TREE.SetBranchStatus("trig_L1_emtau_n",1)
    TREE.SetBranchStatus("trig_L1_emtau_eta",1)
    TREE.SetBranchStatus("trig_L1_emtau_phi",1)
    TREE.SetBranchStatus("el_rawcl_E",1)
    TREE.SetBranchStatus("el_phis2",1)
    
    ####jets
    #AntiKt4TopoEM
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_n",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_E",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_pt",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_eta",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_phi",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_jvtxf",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_isBadTight",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_isBadMedium",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_isBadLoose",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_isBadLooseMinus",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_fracSamplingMax",1)
    #TREE.SetBranchStatus("jet_AntiKt4TopoEM_SamplingMax",1)

    ###photons
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
      
    if FILETYPE == "mc":
        #EL_TRUTH
        TREE.SetBranchStatus("el_truth_type",1)
        TREE.SetBranchStatus("el_truth_matched",1)
        TREE.SetBranchStatus("el_truth_mothertype",1)
        TREE.SetBranchStatus("el_type",1)
        TREE.SetBranchStatus("el_origin",1)
        TREE.SetBranchStatus("el_originbkg",1)
        TREE.SetBranchStatus("el_typebkg",1)
        
        ##truth photons
        TREE.SetBranchStatus("ph_truth_type",1)
        TREE.SetBranchStatus("ph_truth_matched",1)
        TREE.SetBranchStatus("ph_truth_status",1)
        TREE.SetBranchStatus("ph_truth_barcode",1)
        TREE.SetBranchStatus("ph_truth_mothertype",1)
        TREE.SetBranchStatus("ph_truth_motherbarcode",1)
        TREE.SetBranchStatus("ph_origin",1)
        TREE.SetBranchStatus("ph_type",1)
        TREE.SetBranchStatus("ph_originbkg",1)

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
    g=TFile(OUTPUTFILENAME,"RECREATE")
    newTree=ROOT.TTree(TREENAME,TREENAME)
    newTree.Write()
    exit()


if 1:
    
    # SKIM: cut on electrons and muons
    # Select Events with cuts
    nEntries = evtChain.GetEntries()
    EntryList_TPG=ROOT.TEntryList()
    evtChain.GetEntry(0)

           
    for i in range(nEntries):
    #for i in range(100): ###only for tests...

        if not i%10000: print 'Processing entry %d/%d'%(i,nEntries)
        evtChain.GetEntry(i)
        
        n_ele=evtChain.el_n
        n_ph=evtChain.ph_n
        n_tpg=0

           

        ###################
        ###loop over tags
        for j_tag in range(n_ele):

            ###first tag cuts
            #ET > 6.5
            clus_e=evtChain.el_cl_E[j_tag]
            nSihits=evtChain.el_nSCTHits[j_tag]+evtChain.el_nPixHits[j_tag]
            try:
                clus_pt=clus_e/math.cosh(evtChain.el_cl_eta[j_tag])
            except:
                print "Oh Dear"
            if nSihits>=4:
                clus_pt=clus_e/math.cosh(evtChain.el_tracketa[j_tag])
            if not ( clus_pt>24000 
                     or evtChain.el_pt[j_tag]>=24000 
                     or evtChain.el_Et[j_tag]>=24000
                     or evtChain.el_cl_pt[j_tag]>=24000):
                continue

            #author
            if not (evtChain.el_author[j_tag]==1 or evtChain.el_author[j_tag]==3): ###central
                continue

            ###trkQ
            if ((evtChain.el_nPixHits[j_tag] + evtChain.el_nPixelOutliers[j_tag]) < 1) or ((evtChain.el_nSiHits[j_tag] + evtChain.el_nSCTOutliers[j_tag] + evtChain.el_nPixelOutliers[j_tag]) < 7):
                continue

           ###out of gap
            if (abs(evtChain.el_cl_eta[j_tag]) < 1.52 and abs(evtChain.el_cl_eta[j_tag]) > 1.37):
                continue


           ###isMedium
            Et_help = evtChain.el_cl_E[j_tag]/math.cosh(evtChain.el_etas2[j_tag])
            if (evtChain.el_emaxs1[j_tag]+evtChain.el_Emax2[j_tag]) !=0:
                demax = (evtChain.el_emaxs1[j_tag]-evtChain.el_Emax2[j_tag])/float(evtChain.el_emaxs1[j_tag]+evtChain.el_Emax2[j_tag])
            else:
                demax = 0
                #print 'demax = 0?'
            
            if not isMediumPlusPlus(evtChain.el_etas2[j_tag],Et_help,
                                    evtChain.el_f3[j_tag],evtChain.el_Ethad[j_tag]/Et_help, evtChain.el_Ethad1[j_tag]/Et_help,
                                    evtChain.el_reta[j_tag], evtChain.el_weta2[j_tag] ,evtChain.el_f1[j_tag], evtChain.el_wstot[j_tag],
                                    demax,
                                    evtChain.el_deltaeta1[j_tag],evtChain.el_trackd0pv[j_tag], ##replace with trackd0_physics
                                    evtChain.el_TRTHighTOutliersRatio[j_tag],evtChain.el_nTRTHits[j_tag],evtChain.el_nTRTOutliers[j_tag],
                                    evtChain.el_nSiHits[j_tag],evtChain.el_nSCTOutliers[j_tag] + evtChain.el_nPixelOutliers[j_tag],
                                    evtChain.el_nPixHits[j_tag],evtChain.el_nPixelOutliers[j_tag],
                                    evtChain.el_nBLHits[j_tag],evtChain.el_nBLayerOutliers[j_tag],
                                    evtChain.el_expectBLayerHit[j_tag],
                                    egammaMenu.eg2012, 0, 0):
                continue


            #print 'tag!'
           ##################
           ###loop over probes
            for j_probe in range(n_ele): 
                if j_probe == j_tag: continue
                #ET > 6.5
                clus_e=evtChain.el_cl_E[j_probe]
                nSihits=evtChain.el_nSCTHits[j_probe]+evtChain.el_nPixHits[j_probe]
                try:
                    clus_pt=clus_e/math.cosh(evtChain.el_cl_eta[j_probe])
                except:
                    print "Oh Dear"
                if nSihits>=4:
                    clus_pt=clus_e/math.cosh(evtChain.el_tracketa[j_probe])
                if not ( clus_pt>6500 
                     or evtChain.el_pt[j_probe]>=6500 
                     or evtChain.el_Et[j_probe]>=6500
                     or evtChain.el_cl_pt[j_probe]>=6500):
                    continue

                #author
                if not (evtChain.el_author[j_probe]==1 or evtChain.el_author[j_probe]==3): ###central
                    continue

                ###trkQ
                if ((evtChain.el_nPixHits[j_probe] + evtChain.el_nPixelOutliers[j_probe]) < 1) or ((evtChain.el_nSiHits[j_probe] + evtChain.el_nSCTOutliers[j_probe] + evtChain.el_nPixelOutliers[j_probe]) < 7):
                    continue

                #print 'probe!'
                ####################
                ###loop over photons
                for j_ph in range(n_ph):
                
                    ##overlap removal
                    #print str(evtChain.ph_isEM[j_ph] & 0x800000)
                    if not ((evtChain.ph_isEM[j_ph] & 0x800000) == 0):
                        continue                
                    ##eta
                    if not (evtChain.ph_etas2[j_ph] < 2.37): 
                        continue
                    if (abs(evtChain.ph_etas2[j_ph]) > 1.37 and abs(evtChain.ph_etas2[j_ph]) < 1.52): 
                        continue    
                    ##ET
                    clus_e=evtChain.ph_cl_E[j_ph]
                    try:
                        clus_pt=clus_e/math.cosh(evtChain.ph_etas2[j_ph])
                    except:
                        print "Oh Dear"
                    if not evtChain.ph_cl_pt[j_ph] > 9500:
                        continue

                    ##deltaR with tag
                    if abs(evtChain.ph_phi[j_ph] - evtChain.el_trackphi[j_tag]) > math.pi: delta_phi = abs(evtChain.ph_phi[j_ph] - evtChain.el_trackphi[j_tag])
                    else:  delta_phi = 2*math.pi - abs(evtChain.ph_phi[j_ph] - evtChain.el_trackphi[j_tag])
                    delta_eta = evtChain.ph_etas2[j_ph] - evtChain.el_tracketa[j_tag]
                    deltaR = math.sqrt(delta_eta*delta_eta + delta_phi*delta_phi)
                    if not deltaR > 0.2:
                        continue
                    if abs(evtChain.ph_phi[j_ph] - evtChain.el_trackphi[j_probe]) > math.pi: delta_phi = abs(evtChain.ph_phi[j_ph] - evtChain.el_trackphi[j_probe])
                    else:  delta_phi = 2*math.pi - abs(evtChain.ph_phi[j_ph] - evtChain.el_trackphi[j_probe])
                    delta_eta = evtChain.ph_etas2[j_ph] - evtChain.el_tracketa[j_probe]
                    deltaR = math.sqrt(delta_eta*delta_eta + delta_phi*delta_phi)
                    if not deltaR > 0.2:
                        continue

                    ###isEM Loose for the photon
                    rhad = 0
                    if 0.8 < fabs(evtChain.ph_etas2[j_ph]) and fabs(evtChain.ph_etas2[j_ph]) < 1.37: 
                        rhad = evtChain.ph_Ethad[j_ph]/clus_pt
                    else:
                        rhad = evtChain.ph_Ethad1[j_ph]/clus_pt
         
                    rhad1 = evtChain.ph_Ethad1[j_ph]/clus_pt
                    eratio = 0
                    if (evtChain.ph_emaxs1[j_ph] != - evtChain.ph_Emax2[j_ph]):
                        eratio = (evtChain.ph_emaxs1[j_ph] - evtChain.ph_Emax2[j_ph])/(evtChain.ph_emaxs1[j_ph] + evtChain.ph_Emax2[j_ph]);

                    ph_pid = PhotonIDTool(clus_pt, evtChain.ph_etas2[j_ph],
                                                       rhad, rhad, evtChain.ph_E277[j_ph], evtChain.ph_reta[j_ph],
                                                       evtChain.ph_rphi[j_ph], evtChain.ph_weta2[j_ph], evtChain.ph_f1[j_ph],
                                                       evtChain.ph_fside[j_ph], evtChain.ph_wstot[j_ph], evtChain.ph_ws3[j_ph],
                                                       evtChain.ph_deltaEs[j_ph], eratio, evtChain.ph_isConv[j_ph]);
                    if not ph_pid.PhotonCutsLoose(4):
                        continue
                    
                    n_tpg = n_tpg+1
                    #print 'photon!'
     
          
        if n_tpg>=1:    
            EntryList_TPG.Enter(i,evtChain)
           
    evtChain.SetEntryList(EntryList_TPG)
    print " with TPG ", EntryList_TPG.GetN()



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
newTree=evtChain.CopyTree("","fast SortBasketsByEntry")
g.SetCompressionLevel(9)
newTree.Write()
g.mkdir(metaName); g.cd(metaName)
newMeta=metaChain.CloneTree(-1,"fast SortBasketsByEntry")
newMeta.BuildIndex("SMK","L1PSK")
newMeta.Write()


g.Close()
sys.exit()

