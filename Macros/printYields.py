#!/usr/bin/env python
"""
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'Nov 2012'

#-----------------------------------------------------------------------------

import os, sys, string, commands, math
from datetime import datetime
from pprint import pprint
## Needed to correct ROOT behavior; see below
CWD = os.getcwd()

if not len(sys.argv) >= 4:  raise(Exception, "Must specify inputdir, key and type as argument!")

input_dir = sys.argv[1]
input_key = sys.argv[2]
input_type = sys.argv[3]
printEventNumbers = 0
doCategories = 1

isData = 0
if input_type == "data" or input_type == "Data": isData = 1
if not isData: printEventNumbers = 0 ###does not make sense for MC

#import math
from ROOT import *
import glob


####################################INITIALIZATION OF EXTERNAL TOOLS

##for GRL...
if isData:
    os.chdir(CWD)
    gSystem.Load('externals/GoodRunsLists/StandAlone/libGoodRunsLists.so')
    from ROOT import Root
    reader = Root.TGoodRunsListReader('externals/GoodRunsLists/lists/data12_8TeV.periodAllYear_DetStatus-v54-pro13-04_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml')
    reader.Interpret()
    goodrunslist = reader.GetMergedGRLCollection()
    ## show summary of content
    goodrunslist.Summary()

else:
    os.chdir(CWD)
    ###need LinkDef.h in HiggsZZ4lUtils package with CrossSections included for this to work
    ###right now doing this fopr backgrounds only!
    gSystem.Load('externals/HiggsZZ4lUtils/StandAlone/libHiggsZZ4lUtils.so')
    #gSystem.Load('/home/stahlman/testarea/Higgs4lDev.trunk/SFrame/RootCore/HiggsZZ4lUtils/StandAlone/libHiggsZZ4lUtils.so')
    crossSection = CrossSections.bkgCrossSection(107650, CrossSections.EightTeV, 1) 
    print 'test XS: '+str(crossSection) 
    HiggsCrossSection = HiggsCrossSection()
    print 'test higgs XS, 125 GeV: '+str(HiggsCrossSection.higgs4lxsecGGF(125, CrossSections.EightTeV))
    #dec = killEvent(1,1,1,1,1,1,1,1,1)
    #print 'test MC overlap: '+str(dec) 
    
####################################INPUTFILES


files = glob.glob(input_dir + '/*'+input_key+'*/*/*.root')
#files = glob.glob(input_dir + '/*'+input_key+'.root')
tree_name = 'output'
fin = TChain(tree_name)
print 'Number of events: ' + str(fin.GetEntries())  #this opens the tchain? crashes otherwise

#--------------------------------------------

#counter variables
n_4e    = 0
n_4mu   = 0
n_2e2mu = 0
n_2mu2e = 0

n_4e_sr    = 0
n_4mu_sr   = 0
n_2e2mu_sr = 0
n_2mu2e_sr = 0


numberevents_all=0
numberevents_passed = [0,0,0,0,0]


#--------------------------------------------

####################################FIND MC CHANNEL NUMBERS, INITIAL NUMBER OF EVENTS PER CHANNEL

weightsmap = {}
mc_channel_numberarr = []
event_weight = 1.


for subf in files:
    file = TFile(subf,"READ")
    numbereventsPar = file.Get("N_all_events")
    numberevents_all+=numbereventsPar.GetVal()
    if not isData:
        fin_test = file.Get(tree_name)
        if not fin_test.GetEntry(0): continue
        if fin_test.mc_channel_number not in mc_channel_numberarr:
            mc_channel_numberarr.append(fin_test.mc_channel_number)
            weightsmap[fin_test.mc_channel_number]=numbereventsPar.GetVal()
            print 'sample: '+str(fin_test.mc_channel_number)+', XS: '+str(CrossSections.bkgCrossSection(fin_test.mc_channel_number, CrossSections.EightTeV, 1))
        else: weightsmap[fin_test.mc_channel_number]=weightsmap[fin_test.mc_channel_number]+numbereventsPar.GetVal()       
    #weights = 1./numbereventsPar.GetVal()
    #numbereventspassedPar = file.Get("N_passed_events")
    #numberevents_passed+=numbereventspassedPar.GetVal()
    fin.Add(subf)
    file.Close()    

print 'channel : initial number of events'
pprint(weightsmap)

eventnumberarr = []


####################################LOOP OVER EVENTS


print 'Processing events'
n_events = 0

nentries = fin.GetEntries()

for i in xrange(nentries):

    if not (fin.GetEntry(i)): continue

    if not i%10000: print 'Processing entry %d/%d'%(i,nentries)
    
    
    #electron cuts
    pass_ML = true
    pass_ML_firstpair = true
    pass_ML_secondpair = true
    pass_LooseLikelihood = true
    pass_LooseLikelihood_firstpair = true
    pass_LooseLikelihood_secondpair = true
    pass_blayer = true
    pass_blayer_firstpair = true
    pass_blayer_secondpair = true
    pass_twopixel = true

    for i in range(len(fin.lepton_type)):
    
      #only apply cuts on electrons
      if ( abs(fin.lepton_type[i]) != 1): continue

      if (fin.lepton_passML[i] != 1):
        pass_ML = false
        if (i < 2): pass_ML_firstpair = false
	else: pass_ML_secondpair = false

      if (fin.lepton_passLooseLikelihood[i] != 1):
        pass_LooseLikelihood = false
        if (i < 2): pass_LooseLikelihood_firstpair = false
	else: pass_LooseLikelihood_secondpair = false 

      index = fin.lepton_index[i]
      if ( (fin.el_expectHitInBLayer[index] == 1) and (fin.el_nBLHits[index] < 1 or ((fin.el_nPixHits[index]+fin.el_nPixelDeadSensors[index]) < 2))): 
        pass_blayer = false
        if (i < 2): pass_blayer_firstpair = false
	else: pass_blayer_secondpair = false
     
      if ((fin.el_nPixHits[index]+fin.el_nPixelDeadSensors[index]) < 2):
        pass_twopixel = false

    pass_TrkIso = true
    pass_TrkIso_firstpair = true
    pass_TrkIso_secondpair = true
    
    #iso cuts
    for i in range(len(fin.lepton_type)):       
       
       if (abs(fin.lepton_type[i] == 1)): #electrons
	 if not (fin.lepton_trk_iso20[i] < 0.12): 
            pass_TrkIso = false
            if (i < 2): pass_TrkIso_firstpair = false
            else: pass_TrkIso_secondpair = false

       else:
	 if not (fin.lepton_trk_iso20[i] < 0.15): #muons
            pass_TrkIso = false
            if (i < 2): pass_TrkIso_firstpair = false
            else: pass_TrkIso_secondpair = false

    pass_CaloIso = true
    pass_CaloIso_firstpair = true
    pass_CaloIso_secondpair = true
    
    #iso cuts
    for i in range(len(fin.lepton_type)):       
       
       if (abs(fin.lepton_type[i]) == 1): #electrons
	 if not (fin.lepton_calo_iso20[i] < 0.20): 
            pass_CaloIso = false
            if (i < 2): pass_CaloIso_firstpair = false
            else: pass_CaloIso_secondpair = false

       elif ((abs(fin.lepton_type[i]) == 2) and (fin.mu_staco_isStandAloneMuon[ fin.lepton_index[i] ] == 1)): #standalone muons
	 if not (fin.lepton_calo_iso20[i] < 0.15): 
            pass_CaloIso = false
            if (i < 2): pass_CaloIso_firstpair = false
            else: pass_CaloIso_secondpair = false
             
       else: #all other muons
	 if not (fin.lepton_calo_iso20[i] < 0.30): #muons
            pass_CaloIso = false
            if (i < 2): pass_CaloIso_firstpair = false
            else: pass_CaloIso_secondpair = false

    #sanity check
    if (fin.quad_passML != pass_ML): print "ERROR 1"
    if (fin.quad_passLooseLikelihood != pass_LooseLikelihood): print "ERROR 2"
    #if (fin.quad_passTrkIso != pass_TrkIso): print "ERROR 3"
    #if (fin.quad_passCaloIso != pass_CaloIso): print "ERROR 4"
    #if (fin.quad_passMediumLikelihood != pass_MediumLikelihood): print "ERROR 3"

    #apply cuts
    #if not fin.quad_passML: continue
    #if not fin.quad_passML_HCP: continue    
    #if not fin.quad_passLooseLikelihood: continue
    #if not fin.quad_passMediumLikelihood: continue
    #if not fin.quad_passLikelihood: continue
 
    #if not pass_ML: continue
    #if not pass_ML_firstpair: continue
    #if not pass_ML_secondpair: continue

    #if not pass_LooseLikelihood: continue
    #if not pass_LooseLikelihood_firstpair: continue
    #if not pass_LooseLikelihood_secondpair: continue
  
    #if not pass_blayer: continue
    #if not pass_blayer_firstpair: continue
    #if not pass_blayer_secondpair: continue

    #if not pass_twopixel: continue

    #iso cuts
    #if not fin.quad_passTrkIso: continue
    #if not fin.quad_passCaloIso: continue
    if not pass_TrkIso: continue
    if not pass_CaloIso: continue
    
    xs_weight = 1.0
    
    ###GRL cut, only if data..
    if isData: 
        if not goodrunslist.HasRunLumiBlock (fin.RunNumber,fin.lbn) : continue 
    
    ####otherwise weights and overlap removal
    else:
        if killEvent(fin.mc_channel_number,0,fin.mc_n,fin.mc_pt,fin.mc_eta,fin.mc_phi,fin.mc_m,fin.mc_status,fin.mc_pdgId):
            continue
        crossSection = CrossSections.bkgCrossSection(fin.mc_channel_number, CrossSections.EightTeV, 1)
        if crossSection == -1: 
            if fin.mc_channel_number == 160155: crossSection = HiggsCrossSection.higgs4lxsecGGF(125, CrossSections.EightTeV) 
            if fin.mc_channel_number == 160205: crossSection = HiggsCrossSection.higgs4lxsecVBF(125, CrossSections.EightTeV) 
            if fin.mc_channel_number == 160255: crossSection = HiggsCrossSection.higgs4lxsecWH(125, CrossSections.EightTeV) 
            if fin.mc_channel_number == 160305: crossSection = HiggsCrossSection.higgs4lxsecZH(125, CrossSections.EightTeV) 
            if fin.mc_channel_number == 167562: crossSection = HiggsCrossSection.higgs4lxsecttH(125, CrossSections.EightTeV) 
        xs_weight = 1./weightsmap[fin.mc_channel_number] * crossSection

    ###don't allow duplicates
    if isData: 
        if  fin.RunNumber*100000+fin.EventNumber not in eventnumberarr: eventnumberarr.append(fin.RunNumber*100000+fin.EventNumber)
        else:
	    #print 'duplicate in the two streams' 
	    continue

    n_events += 1

    wt = 1.0
    wt = wt*xs_weight
    wt = wt*fin.lepton_sf
    wt = wt*fin.trigger_sf
    wt = wt*fin.vertex_sf
    wt = wt*fin.pileup_sf

    n_4mu   += (fin.quad_type == 0)*wt 
    n_4e    += (fin.quad_type == 1)*wt 
    n_2mu2e += (fin.quad_type == 2)*wt 
    n_2e2mu += (fin.quad_type == 3)*wt 

    if (fin.m_4l > 120000 and fin.m_4l < 130000):
       n_4mu_sr   += (fin.quad_type == 0)*wt 
       n_4e_sr    += (fin.quad_type == 1)*wt 
       n_2mu2e_sr += (fin.quad_type == 2)*wt 
       n_2e2mu_sr += (fin.quad_type == 3)*wt 
      
    
print ''
print 'Selected events: ' + str(n_events)
print ''
print "Total Yield (1 fb-1):  ", n_4mu+n_4e+n_2mu2e+n_2e2mu
print 'Yields per category:' 
print '4mu....:  ' + str(n_4mu)  
print '4e.....:  ' + str(n_4e)   
print '2mu2e..:  ' + str(n_2mu2e) 
print '2e2mu..:  ' + str(n_2e2mu) 
print ''
print "Signal Region Yield (120-130 GeV):  ", n_4mu_sr+n_4e_sr+n_2mu2e_sr+n_2e2mu_sr
print 'Signal Region Yields per category:' 
print '4mu....:  ' + str(n_4mu_sr)  
print '4e.....:  ' + str(n_4e_sr)   
print '2mu2e..:  ' + str(n_2mu2e_sr) 
print '2e2mu..:  ' + str(n_2e2mu_sr) 
print ''
