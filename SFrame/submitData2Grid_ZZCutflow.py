import os
from dataSets import data12_hsg2 as datasets


preFix = "user.sheim."
tag = ".data.v2"
postFix = ".SFrame/"

extFiles = 'RootCore/egammaAnalysisUtils/share/zvtx_weights_2011_2012.root,config/other/PDFs_2012_sig_tagInBarrelAtLowEt.root,RootCore/PileupReweighting/share/mc12a_defaults.prw.root,config/other/muon_trigger_sf_2012_AB.root,config/other/muon_trigger_sf_2012_AtoD.root,config/lumi/MC12a.prw.root,config/lumi/ilumicalc_2012_AllYear_All_Good.root,RootCore/MuonEfficiencyCorrections/share/STACO_CB_plus_ST_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/STACO_CB_plus_ST_2012_SFms.txt,RootCore/MuonEfficiencyCorrections/share/STACO_CB_HighPt_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/STACO_CB_HighPt_2012_SFms.txt,RootCore/MuonEfficiencyCorrections/share/STACO_CB_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/STACO_CB_2012_SFms.txt,RootCore/MuonEfficiencyCorrections/share/MuonsChain_CB_plus_ST_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/MuonsChain_CB_plus_ST_2012_SFms.txt,RootCore/MuonEfficiencyCorrections/share/MuonsChain_CB_HighPt_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/MuonsChain_CB_HighPt_2012_SFms.txt,RootCore/MuonEfficiencyCorrections/share/MuonsChain_CB_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/MuonsChain_CB_2012_SFms.txt,RootCore/MuonEfficiencyCorrections/share/Muid_CB_plus_ST_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/Muid_CB_plus_ST_2012_SFms.txt,RootCore/MuonEfficiencyCorrections/share/Muid_CB_HighPt_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/Muid_CB_HighPt_2012_SFms.txt,RootCore/MuonEfficiencyCorrections/share/Muid_CB_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/Muid_CB_2012_SFms.txt,RootCore/MuonEfficiencyCorrections/share/ID_2012_SF.txt,RootCore/MuonEfficiencyCorrections/share/CaloTag_2012_SF.txt,RootCore/egammaAnalysisUtils/share/EnergyRescalerData.root'
	   

for i in range(len(datasets)):
    
    print 'Submitting dataset: ' + str(i+1) + '/' + str(len(datasets))
    
    command = "prun "
    command += " --bexec grid_build.sh"
    command += ' --exec "grid_run_ZZCutflow.sh %IN"'
    command += " --nGBPerJob=MAX"

    command += " --excludeFile=ZZMassResolution,ZZTruthStudies"

    command += " --inDS "+datasets[i]
    dsName = datasets[i].rstrip("/")
    dsName = dsName.replace(preFix,'')
    #dsName = "data12_hsg2"
    command += " --outDS "+preFix+dsName+tag+postFix

    command += " --athenaTag=17.0.3.4" #to set up ROOT
    #command += " --athenaTag=17.2.4" #to set up ROOT
    
    command += " --excludedSite=TAIWAN,TW,NAPOLI,ANALY_MANC,MILANO,IN2P3,ROMANIA,ANALY_AUSTRALIA,ANALY_INFN-ROMA1,ANALY_INFN-FRASCATI,ANALY_MCGILL,ANALY_RAL_XROOTD,ANALY_UAM,ANALY_LANCS,ANALY_AGLT2"
    
    command += ' --outputs "ZZCutFlow.data.Reco.root"'
    
    #command += " --mergeOutput"
    
    command += " --extFile " + extFiles

    #command += " --rootVer 5.30.05" 
    
    #command += " --libDS LAST"  #useful for re-submitting jobs with bad configs
    
    #command += " --nFiles=1"  #for testing

    print command
    os.system(command)
