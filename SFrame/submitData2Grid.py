import os
from dataSets import mc12_hsg2 as datasets


preFix = "user.stahlman."
tag = ".test2"
postFix = ".ZMassStudy/"

extFiles =   'RootCore/TrigMuonEfficiency/share/muon_trigger_sf_2012_AB.root'
extFiles += ',RootCore/egammaAnalysisUtils/share/EnergyRescalerData.root'
	   

for i in range(len(datasets)):
    
    print 'Submitting dataset: ' + str(i+1) + '/' + str(len(datasets))
    
    command = "prun "
    command += " --bexec grid_build.sh"
    command += ' --exec "grid_run.sh %IN"'
    command += " --nGBPerJob=MAX"

    #command += " --excludeFile="

    command += " --inDS "+datasets[i]
    dsName = datasets[i].rstrip("/")
    command += " --outDS "+preFix+dsName+tag+postFix

    command += " --athenaTag=17.0.3.4" #to set up ROOT
    
    command += " --excludedSite=ANALY_MPPMU,ANALY_ROMANIA07,ANALY_LAPP,ANALY_ARC,ANALY_LIV,ANALY_INFN-MILANO-ATLASC,ANALY_MANC,ANALY_SFU_bugaboo,ANALY_INFN-NAPOLI,ANALY_NET2,ANALY_MWT2,ANALY_AGLT2"
    
    command += ' --outputs "ZMassStudy.Data.Reco.root"'
    
    #command += " --mergeOutput"
    
    command += " --extFile " + extFiles
    
    command += " --nFiles=1"  #for testing

    print command
    os.system(command)
