import user

import math
import ROOT
import PyCintex

# Put your AOD file here.
def getBranchName(tree):
    branchName = [];
    list_of_branches= tree.GetListOfBranches()
    for i in range(list_of_branches.GetEntries()):
        branch = list_of_branches.At(i)
        tempName = branch.GetName()
    	branchName.append(tempName)
        continue
    return branchName
def intersect(a, b):
    return list(set(a) & set(b))

def difference(a, b):
    diffList = []
    diffList = diffList + list(set(a)-set(b))
    diffList = diffList + list(set(b)-set(a))
    return diffList



def doCompareMinitrees():

    # compare isem bits for events in two jpsi ntuples
    fabienPath = "/afs/cern.ch/user/t/tarrade/public/ForValerio/ForHaider/MiniTreeChallenge/v32" 
    #frdsNtupName  = "/afs/cern.ch/user/j/jdandoy/public/forSyed/mc12_8TeV.160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep.root"
    frdsNtupName  = "/disk/userdata00/atlas_data2/stahlman/output/test/MC12_test.root"
    fchkNtupeName = fabienPath + "/mc12_8TeV.160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep.merge.NTUP_HSG2.e1195_s1771_s1741_r4829_r4540_p1344.root"
    
    # new geotest
    #frdsNtupName  = "../MyAnalysis/Run/Output/mc12_8TeV.160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep_newGeo.root"
    #fchkNtupeName = fabienPath + "/mc12_8TeV.160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep.merge.NTUP_HSG2.e1195_s1771_s1741_r4829_r4540_p1344.root"
    
    #frdsNtupName  = "../MyAnalysis/Run/Output/mc11_7TeV.125066.PowHegPythia_VBFH125_ZZ4lep.root"
    #fchkNtupeName = fabienPath + "/mc11_7TeV.125066.PowHegPythia_VBFH125_ZZ4lep.merge.NTUP_HSG2.e893_s1310_s1300_r3043_r2993_p1486.root"
    
    #frdsNtupName  = "../MyAnalysis/Run/Output/mc12_8Tev.126938.PowHegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5.root"
    #frdsNtupName  = "../MyAnalysis/Run/Output/mc12_8TeV.126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5.root"
    #fchkNtupeName = "FabienResult/file_MC_ZZ_mixing_4e_2e2mu_4mu_2012_new_all.root"
    
    #frdsNtupName  = "../MyAnalysis/Run/Output/mc12_8TeV.167120.JHUPythia8_AU2CTEQ6L1_ggH125_Spin0p_ZZ4lep.root"
    #fchkNtupeName = "FabienResult/mc12_8TeV.167120.JHUPythia8_AU2CTEQ6L1_ggH125_Spin0p_ZZ4lep.root"
    
    #frdsNtupName  = "../MyAnalysis/Run/Output/mc11_7TeV.167603.JHU_CTEQ6L1_ggH125_ZZ4lep_Spin2m.root"
    #fchkNtupeName = "FabienResult/mc11_7TeV.167603.JHU_CTEQ6L1_ggH125_ZZ4lep_Spin2m.merge.NTUP_HSG2.e1535_s1372_s1370_r3108_r3109_p1486.root"
    
    #frdsNtupName  = "../MyAnalysis/Run/Output/mc11_7TeV.169496.PowHegPythia_ggH126_ZZ4lep.root"
    #fchkNtupeName = "FabienResult/mc11_7TeV.169496.PowHegPythia_ggH126_ZZ4lep.root"  

    #frdsNtupName  = "../MyAnalysis/Run/Output/mc11_7TeV.167572.Pythia_ttH125_ZZ4lep.root"
    #fchkNtupeName = "FabienResult/mc11_7TeV.167572.Pythia_ttH125_ZZ4lep.root"
    #fchkNtupeName = "FabienResult/mc11_7TeV.167572.Pythia_ttH125_ZZ4lep.merge.NTUP_HSG2.e1459_s1372_s1370_r3108_r3109_p1486.root"

    #frdsNtupName  = "../MyAnalysis/Run/Output/mc12_8TeV.167562.Pythia8_AU2CTEQ6L1_ttH125_ZZ4lep_newGeo.root"
    #fchkNtupeName = fabienPath + "/mc12_8TeV.167562.Pythia8_AU2CTEQ6L1_ttH125_ZZ4lep.merge.NTUP_HSG2.e2211_s1771_s1741_r4829_r4540_p1344.root" 
    
    #frdsNtupName  = "../MyAnalysis/Run/Output/mc12_8TeV.181330.PowhegPythia8_AU2CT10_ggH121_ZZ4lep_noTau.root"
    #fchkNtupeName = "FabienResult/mc12_8TeV.181330.PowhegPythia8_AU2CT10_ggH121_ZZ4lep_noTau.root"  
    
    #frdsNtupName  = "../MyAnalysis/Run/Output/mc12_8TeV.181332.PowhegPythia8_AU2CT10_ggH123p5_ZZ4lep_noTau.root"
    #fchkNtupeName = "FabienResult/mc12_8TeV.181332.PowhegPythia8_AU2CT10_ggH123p5_ZZ4lep_noTau.root"  

    #frdsNtupName  = "../MyAnalysis/Run/Output/mc12_8TeV.160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep_newGeo.root"
    #fchkNtupeName = fabienPath+ "/mc12_8TeV.160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep.merge.NTUP_HSG2.e1419_s1771_s1741_r4829_r4540_p1344.root"  

    #frdsNtupName  = "../MyAnalysis/Run/Output/mc12_8TeV.160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep_newGeo.root"
    #fchkNtupeName = fabienPath + "/mc12_8TeV.160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep.merge.NTUP_HSG2.e1217_s1771_s1741_r4829_r4540_p1344.root"  
	
    #frdsNtupName  = "/afs/cern.ch/work/s/sabidi/private/FinalizedRootFile/prodV01/mc11_7TeV.105200.T1_McAtNlo_Jimmy.root"
    #fchkNtupeName = "/afs/cern.ch/work/s/sabidi/public/FabienResult/mc11_7TeV.105200.T1_McAtNlo_Jimmy.root"
    frds  = ROOT.TFile.Open (frdsNtupName)
    fchk  = ROOT.TFile.Open (fchkNtupeName)

    print "opened file", frdsNtupName, fchkNtupeName

    # Loop over ntuples - jpsiTPPairs is the ntuple name

    epsilon = 0.0001 # relative tolerance for the difference

    #trees = ["tree_incl_4mu", "tree_incl_4e", "tree_incl_2mu2e", "tree_incl_2e2mu", 
    #         "tree_ggF_4mu", "tree_ggF_4e", "tree_ggF_2mu2e", "tree_ggF_2e2mu", 
    #         "tree_VBF", "tree_VH"]

    trees = ["tree_incl_4mu", "tree_incl_4e", "tree_incl_2mu2e", "tree_incl_2e2mu"]
    
    #trees = ["tree_incl_4mu"]

    for tr in trees:
        print "tree: ", tr
        pass
    

    # Getting the two histrograms from fabien's files
    histCount = fchk.Get("hNprocessed")
    histCountReweight = fchk.Get("hNprocessed_reweighted")
    print type( histCount )
    print type( histCountReweight )

    nGeneratedRaw = histCount.GetBinContent(2)
    nGenerated = histCountReweight.GetBinContent(2)
    print histCount.GetBinContent(2)
    print histCountReweight.GetBinContent(2)

    doM4lErr = False
    # doM4lErr = True
    # getting the list of branches to check
    trdsBranch = getBranchName(frds.Get(trees[0]))
    tchkBranch = getBranchName(fchk.Get(trees[0]))
    #print rdsBranch
    #print chkBranch
    brToCheck = intersect(trdsBranch, tchkBranch)
    brToCheck.remove('run')
    brToCheck.remove('weight_lumi')
    brToCheck.remove('weight')

    brToCheck.sort()
    print "Branch that are different"
    print difference(trdsBranch, tchkBranch)

    #for itree in range(0,10):
    for itree in range(0,4):
    #for itree in range(1):
        trds  = frds.Get(trees[itree])
        tchk  = fchk.Get(trees[itree])
        brChkCut    = tchk.GetBranch('cut')
        brChkEvt    = tchk.GetBranch('event')

        #print "Got trees:", trds.GetName(), tchk.GetName()
        nrds = trds.GetEntries()
        nForchk = tchk.GetEntries()
	
        nchk = 0
        ichk = 0
        IsLoopOk = True
        while IsLoopOk:
            brChkEvt.GetEntry(ichk)
            brChkCut.GetEntry(ichk)
            cut = getattr(tchk, 'cut')			
            if tchk.cut[5] == 1:
                nchk += 1
	    ichk += 1
	    if ichk >= nForchk:
		IsLoopOk = False
        print "Got trees:", trds.GetName(), tchk.GetName()
        print "trees:", nrds, nchk
        if nrds != nchk:
            print '\033[91m'+'CutFlow Mismatch'+'\033[0m' 
			
        nrds = trds.GetEntries()
        nchk = tchk.GetEntries()
        #print "trees:", nrds, nchk
        if (nrds == 0) or (nchk == 0): continue 
        
        brs = trds.GetListOfBranches()
        
        # for br in brs:
        #     print "br:",br.GetName()
        #     pass
        
        # check matching event numbers
        irds = 0
        ichk = 0
        brRdsEvt    = trds.GetBranch('event')
        brChkEvt    = tchk.GetBranch('event')

        brChkCut    = tchk.GetBranch('cut')

        brRdsWeightLumi     = trds.GetBranch('weight_lumi')
        brChkWeightLumi     = tchk.GetBranch('weight_lumi')
        brRdsWeight    = trds.GetBranch('weight')
        brChkWeight    = tchk.GetBranch('weight')
        numMatchLumi = 0		
        numMatchWeight = 0
        numTestedLumi = 0
        numTestedWeight = 0

        # cannot be compare
        #run, weight, weight_lumi
        
        #Old vars
        massVars  = ['m4l_unconstrained', 'm4lerr_unconstrained', 'mZ1_unconstrained', 'mZ2_unconstrained', 'm4l_fsr', 'mZ1_fsr', 'mZ2_fsr', 'm4l_constrained', 'm4lerr_constrained', 'mZ1_constrained', 'mZ2_constrained']
        
        higgsVars = ['pt4l_unconstrained', 'y4l_unconstrained', 'eta4l_unconstrained', 'pt4l_fsr', 'y4l_fsr', 'eta4l_fsr', 'pt4l_constrained', 'y4l_constrained', 'eta4l_constrained']
        
        weightVars = ['event','lbn','npv','weight_corr'] # 'weight_sampleoverlap'
        
        ##lepvars = ['Z1_lepplus_pt', 'Z1_lepminus_pt', 'Z2_lepplus_pt', 'Z2_lepminus_pt', 'Z1_lepplus_eta', 'Z1_lepminus_eta', 'Z2_lepplus_eta', 'Z2_lepminus_eta', 'Z1_lepplus_phi', 'Z1_lepminus_phi', 'Z2_lepplus_phi', 'Z2_lepminus_phi', 'Z1_lepplus_m', 'Z1_lepminus_m', 'Z2_lepplus_m', 'Z2_lepminus_m']
        lepvars = ['Z1_lepplus_pt', 'Z1_lepminus_pt', 'Z2_lepplus_pt', 'Z2_lepminus_pt', 'Z1_lepplus_eta', 'Z1_lepminus_eta', 'Z2_lepplus_eta', 'Z2_lepminus_eta', 'Z1_lepplus_phi', 'Z1_lepminus_phi', 'Z2_lepplus_phi', 'Z2_lepminus_phi', 'Z1_lepplus_m', 'Z1_lepminus_m', 'Z2_lepplus_m', 'Z2_lepminus_m', 'Z1_lepplus_cov_mom', 'Z1_lepminus_cov_mom', 'Z2_lepplus_cov_mom', 'Z2_lepminus_cov_mom']
        
        angleVars =  ['cthstr', 'phi1', 'cth1', 'cth2', 'phi']
        
        jetVars =  ['n_jets', 'dijet_invmass', 'dijet_deltaeta', 'leading_jet_pt', 'leading_jet_eta', 'leading_jet_phi','leading_jet_m','leading_jet_width','leading_jet_nTrk', 'subleading_jet_pt', 'subleading_jet_eta', 'subleading_jet_phi','subleading_jet_m','subleading_jet_width','subleading_jet_nTrk','third_jet_pt', 'third_jet_eta', 'third_jet_phi','third_jet_m','third_jet_width','third_jet_nTrk','KD_discriminant','BDT_discriminant']
        
        jetTruthVars =  ['n_jets_truth_bare', 'leading_jet_pt_truth_bare']
        
        higgsTruthVars =  ['pt4l_truth_born', 'y4l_truth_born', 'eta4l_truth_born', 'm4l_truth_born']

        massTruthVars =  ['m4l_truth_matched_born', 'mZ1_truth_matched_born', 'mZ2_truth_matched_born', 'm4l_truth_matched_bare', 'mZ1_truth_matched_bare', 'mZ2_truth_matched_bare', 'm4l_truth_matched_dressed', 'mZ1_truth_matched_dressed', 'mZ2_truth_matched_dressed']
		
        lepTruthVars =  [ 'Z1_lepplus_pt_truth_born', 'Z1_lepminus_pt_truth_born', 'Z2_lepplus_pt_truth_born', 'Z2_lepminus_pt_truth_born', 'Z1_lepplus_eta_truth_born', 'Z1_lepminus_eta_truth_born', 'Z2_lepplus_eta_truth_born', 'Z2_lepminus_eta_truth_born', 'Z1_lepplus_phi_truth_born', 'Z1_lepminus_phi_truth_born', 'Z2_lepplus_phi_truth_born', 'Z2_lepminus_phi_truth_born', 'Z1_lepplus_m_truth_born', 'Z1_lepminus_m_truth_born', 'Z2_lepplus_m_truth_born', 'Z2_lepminus_m_truth_born']

        checkVars =   ['calib', 'fsrType']

        #diff_Vars = ['weight','m4l_constrained','pt4l_unconstrained','y4l_unconstrained','mZ2_unconstrained','cthstr','n_jets_fid','pt_leadingjet_fid']
        diff_Vars = ['m4l_constrained','m4l_fsr','pt4l_unconstrained','y4l_unconstrained','mZ2_unconstrained','cthstr']
	
        #brsToChk = massVars + higgsVars + lepvars + angleVars + weightVars + jetTruthVars + jetVars + massTruthVars + lepTruthVars + higgsTruthVars + checkVars 
        brsToChk = diff_Vars
        #overwriting the name with branches gotten from the tree
        #brsToChk  = brToCheck
        #brsNames  = brsToChk

        brToCheck = brsToChk
        brsNames  = brsToChk

        #print ''
        #print ''
        #print ' Total number of variables in the mini tree : ', len(brsToChk)
        #print ''
        #print ''

        #print '  brsNames ',   brsNames
        #print '  brsToChk ',  brsToChk
        #print '  brToCheck ',  brToCheck
        
        nbrsToChk  = []
        nbrsMatch  = []

        brsRDS = []
        brsChk = []
        for br in brsToChk:
            #print "Get br rds", br, trds.GetBranch(br)
            brsRDS.append(trds.GetBranch(br))
            # print "Get br chk", br, tchk.GetBranch(br)
            brsChk.append(tchk.GetBranch(br))
            nbrsToChk.append(0)
            nbrsMatch.append(0)
            pass
        
        loopIsOK = True
        while loopIsOK:
            brRdsEvt.GetEntry(irds)
            brChkEvt.GetEntry(ichk)
            brChkCut.GetEntry(ichk)
            cut = getattr(tchk, 'cut')			
            while tchk.cut[5] != 1:
                ichk += 1
                brChkEvt.GetEntry(ichk)
                brChkCut.GetEntry(ichk)
            if trds.event != tchk.event:
                print "evtNum mismatch, i1,i2,evt1,evt2", irds, ichk, trds.event, tchk.event
                # check which one is missing
                ev1 = trds.event 
                ev2 = tchk.event
                brRdsEvt.GetEntry(irds+1)
                brChkEvt.GetEntry(ichk+1)
                if ev1 == tchk.event:
                    print "missing rds", ev2
                    ichk += 1
                elif ev2 == trds.event:
                    print "missing chk", ev1
                    irds += 1
                else:
                    print "cannot match with one iteration"
                    loopIsOK = False
                    pass
                    # else:
                    # do checks of variables
			
			# Check the lumi weight
            brRdsWeightLumi.GetEntry(irds)
            brChkWeightLumi.GetEntry(ichk)
            numTestedLumi += 1
            #Comparing lumi Weight
            valrds = trds.weight_lumi
            valchk = tchk.weight_lumi/nGeneratedRaw
            if valrds != 0.0:
                diff = math.fabs(valrds - valchk)/math.fabs(valrds)
            else:
                diff = 0.0

            if diff > epsilon:
               print 'Lumi Mismatch', trds.event, valrds, valchk, diff
            else:
               numMatchLumi += 1

            # Check the lumi weight
            brRdsWeight.GetEntry(irds)
            brChkWeight.GetEntry(ichk)
            numTestedWeight += 1
            #Comparing lumi Weight
            valrds = trds.weight
            valchk = tchk.weight/nGenerated
            if valrds != 0.0:
                diff = math.fabs(valrds - valchk)/valrds
            else:
                diff = 0.0
                
            if diff > epsilon:
               print 'weight Mismatch', trds.event, valrds, valchk, diff
            else:
               numMatchWeight += 1

            # Now check variables
            #print ' len(brsRDS)   = ',len(brsRDS)
            #print ' len(brsToChk) = ',len(brsToChk)
            #print ' len(brsRDS)   = ',len(brsRDS)
            for i in range(len(brsRDS)):
                #print 'i',i
                #print 'brsToChk[i]',brsToChk[i]
                #print 'brsRDS[i]',brsRDS[i]
                tempStr = "mismatch evt" + brsToChk[i] + ":"
                brsRDS[i].GetEntry(irds)
                try:
                    brsChk[i].GetEntry(ichk)
                except:
                    # print "Branch doesn't exist: ", brsToChk[i]
                    continue
                pass
                valrds = getattr(trds, brsToChk[i])
                valchk = getattr(tchk, brsToChk[i])
                if valrds != 0.0:
                    diff = math.fabs(valrds - valchk)/math.fabs(valrds)
                else:
                    diff = 0
                nbrsToChk[i] += 1
                #if "n_jets_truth_bare" in brsToChk[i]: 
				#    print brsNames[i], tempStr, trds.event, valrds, valchk, diff
                # print brsNames[i], tempStr, trds.event, valrds, valchk, diff
                if diff > epsilon:
                    print brsNames[i], tempStr, trds.event, valrds, valchk, diff
                    pass
                else:
                    nbrsMatch[i] += 1
                    pass
                pass
            pass
        
            ichk += 1
            irds += 1
            if irds >= nrds or ichk >= nchk: loopIsOK = False
            pass
        pass
        
        print "Checks ok for variables: ",
        for i in range(len(brsRDS)):
            print brsNames[i], nbrsToChk[i],
            pass
        pass
        print 'weightLumi', numTestedLumi,	
	print 'weight', numTestedWeight,
        print " "
        print " "
		
        print "Numbers matched ok for variables: ",
        for i in range(len(brsRDS)):
            if(nrds == nbrsMatch[i]):
                print brsNames[i], nbrsMatch[i],
            else:
                print '\033[91m'+brsNames[i]+'\033[0m', nbrsMatch[i],
            pass
        pass
        if(nrds == numMatchLumi):
            print 'weightLumi', numMatchLumi, 
        else:
            print '\033[91m'+'weightlumi'+'\033[0m', numMatchLumi,
        pass
        if(nrds == numMatchWeight):
            print 'weight', numMatchWeight, 
        else:
            print '\033[91m'+'weight'+'\033[0m', numMatchWeight,
        pass
        print " "
        print " "


    
    
    return

# execute the comparison
doCompareMinitrees()
exit()



