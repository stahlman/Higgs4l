import os
from dataSets import mc12_higgs as datasets


preFix = "user.stahlman."
tag = ".v1"
postFix = ".SFrame/"

extFiles = 'config/lumi/ilumicalc_histograms_None_178044-184072.root,config/lumi/mu_mc10b.root'
	   

for i in range(len(datasets)):
    
    print 'Submitting dataset: ' + str(i+1) + '/' + str(len(datasets))
    
    command = "prun "
    command += " --bexec grid_build.sh"
    command += ' --exec "grid_mc_run.sh %IN"'
    command += " --nGBPerJob=MAX"

    command += " --excludeFile=ElectronPreselCycle,ElectronAnaCycles,Skimmers,TrigBunchCrossingTool,OutputNtuple,EgammaTools"

    command += " --inDS "+datasets[i]
    dsName = datasets[i].rstrip("/")
    dsName = dsName.replace(preFix,'')
    command += " --outDS "+preFix+dsName+tag+postFix

    command += " --athenaTag=17.0.3.4" #to set up ROOT
    
    command += " --excludedSite=TAIWAN,TW,NAPOLI,ANALY_MANC,MILANO,SWT2,IN2P3,ROMANIA"
    
    command += ' --outputs "ZZ_Selection.MC.Reco.root"'
    
    #command += " --mergeOutput"
    
    command += " --extFile " + extFiles
    
    #command += " --libDS LAST"  #useful for re-submitting jobs with bad configs
    
    #command += " --nFiles=1"  #for testing

    print command
    os.system(command)
