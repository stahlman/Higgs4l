#!/usr/bin/env python
"""
"""

__author__ = 'Heim Sarah'
__email__ = 'sheim@cern.ch'
__date__ = 'Sep 2012'

#---------------------------------------------------------------------------
DEBUG = 1

import os, sys, string, commands, math
from datetime import datetime
from pprint import pprint
## Needed to correct ROOT behavior; see below
CWD = os.getcwd()

if not len(sys.argv) >= 4:  raise(Exception, "Must specify inputdir, key and type as argument!")

input_dir = sys.argv[1]
input_key = sys.argv[2]
input_type = sys.argv[3]
printEventNumbers = 1
doCategories = 1


output_dir = ''
if (len(sys.argv) == 5):
  output_dir = sys.argv[4]

isData = 0
if input_type == "data" or input_type == "Data": isData = 1
#if not isData: printEventNumbers = 0 ###does not make sense for MC


import math
from ROOT import *
#from pyroot_helpers import *
from array import array
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
    crossSection = CrossSections.bkgCrossSection(107650, CrossSections.EightTeV, 1) 
    print 'test XS: '+str(crossSection) 
    HiggsCrossSection = HiggsCrossSection()
    print 'test higgs XS, 125 GeV: '+str(HiggsCrossSection.higgs4lxsecGGF(125, CrossSections.EightTeV))
    #dec = killEvent(1,1,1,1,1,1,1,1,1)
    #print 'test MC overlap: '+str(dec) 

###for jets
if doCategories:
    gSystem.Load('externals/HiggsZZ4lUtils/StandAlone/libHiggsZZ4lUtils.so')
    isJetLike = ElectronRecoClass.getRecoClassificationPenn(1,0,0,10,1,0,0,0,0,0)
    print 'test Reco, should be 3 for jets: '+str(isJetLike)


####################################INPUTFILES
file_key = input_dir + '/*'+input_key+'*/*/*.root'
#file_key = input_dir + '/*'+input_key+'.root'

print "Using files that match: "+ file_key
files = glob.glob(file_key)
print "Found files: "
for f in files:
  print "  " + f
tree_name = 'output'
fin = TChain(tree_name)

####################################COUNTERS

numberevents_all=0
numberevents_passed = [0,0,0,0,0]


#signal region definition
sr_min = 120
sr_max = 130

####################################HISTOGRAMS

hists = []
hists2D = []
typevec = ["4mu","4e","2mu2e","2e2mu",""]

h_lepton_trk_iso20_34 = TH1F('h_lepton_trk_iso20_34','lepton_trk_iso20_34',125,-0.5,2);  hists.append(h_lepton_trk_iso20_34)
h_lepton_calo_iso20_34 = TH1F('h_lepton_calo_iso20_34','lepton_calo_iso20_34',125,-0.5,2);  hists.append(h_lepton_calo_iso20_34)
h_el_calo_iso20_34 = TH1F('h_el_calo_iso20_34','el_calo_iso20_34',125,-0.5,2);  hists.append(h_el_calo_iso20_34)
h_el_calo_iso20_34_M4l_70_110 = TH1F('h_el_calo_iso20_34_M4l_70_110','el_calo_iso20_34_M4l_70_110',125,-0.5,2);  hists.append(h_el_calo_iso20_34_M4l_70_110) 
h_el_calo_iso20_34_M34_l90 = TH1F('h_el_calo_iso20_34_M34_l90','el_calo_iso20_34_M34_l90',125,-0.5,2);  hists.append(h_el_calo_iso20_34_M34_l90)
h_el_calo_iso20_34_M12_l90 = TH1F('h_el_calo_iso20_34_M12_l90','el_calo_iso20_34_M12_l90',125,-0.5,2);  hists.append(h_el_calo_iso20_34_M12_l90)
h_m_4l = TH1F('h_m_4l','m_4l',220,80,300);  hists.append(h_m_4l)
h_m_12 = TH1F('h_m_12','m_12',150,0,150);  hists.append(h_m_12)
h_m_34 = TH1F('h_m_34','m_34',150,0,150);  hists.append(h_m_34)
h_m_4l_sr = TH1F('h_m_4l_sr','m_4l',int((sr_max-sr_min)/0.5),sr_min,sr_max);  hists.append(h_m_4l_sr)
h_m_12_sr = TH1F('h_m_12_sr','m_12',150,0,150);  hists.append(h_m_12_sr)
h_m_34_sr = TH1F('h_m_34_sr','m_34',150,0,150);  hists.append(h_m_34_sr)
h_el_nTRT_34 = TH1F('h_el_nTRT_34','el_nTRT_34',100,0,1);  hists.append(h_el_nTRT_34)
h_el_nTRT_34_M4l_70_110 = TH1F('h_el_nTRT_34_M4l_70_110','el_nTRT_34_M4l_70_110',100,0,1);  hists.append(h_el_nTRT_34_M4l_70_110)
h_el_nTRT_34_M34_l90 = TH1F('h_el_nTRT_34_M34_l90','el_nTRT_34_M34_l90',100,0,1);  hists.append(h_el_nTRT_34_M34_l90)
h_el_nTRT_34_M12_l90 = TH1F('h_el_nTRT_34_M12_l90','el_nTRT_34_M12_l90',100,0,1);  hists.append(h_el_nTRT_34_M12_l90)

h_m_12_vs_m_34 = TH2F('h_m_12_vs_m_34','m12_m34',150,0,150,150,0,150);hists2D.append(h_m_12_vs_m_34)
h_m_4l_vs_m_12 = TH2F('h_m_4l_vs_m_12','m4l_m12',300,0,300,150,0,150);hists2D.append(h_m_4l_vs_m_12)

h_m_4l_ = []
h_m_12_ = []
h_m_34_  = []

h_m_12_vs_m_34_= []
h_m_4l_vs_m_12_ = []
h_m_4l_vs_m_34_ = []
h_reco_categories_ = []
h_categories_ = []

h_max_lepton_trk_iso20_ = []
h_max_lepton_trk_iso30_ = []
h_max_lepton_trk_iso40_ = []
h_max_lepton_calo_iso20_ = []
h_max_lepton_calo_iso30_ = []
h_max_lepton_calo_iso40_ = []

h_trk_iso20_secondpair_sr_ = []
h_trk_iso30_secondpair_sr_ = []
h_trk_iso40_secondpair_sr_ = []
h_calo_iso20_secondpair_sr_ = []
h_calo_iso30_secondpair_sr_ = []
h_calo_iso40_secondpair_sr_ = []

for itype in xrange(4):
    h_test = TH1F('h_m_4l_'+typevec[itype],'m_4l_'+typevec[itype],220,80,300); h_m_4l_.append(h_test); hists.append(h_test)
    h_test = TH1F('h_m_12_'+typevec[itype],'m_12_'+typevec[itype],150,0,150); h_m_12_.append(h_test); hists.append(h_test) 
    h_test = TH1F('h_m_34_'+typevec[itype],'m_34_'+typevec[itype],150,0,150); h_m_34_.append(h_test); hists.append(h_test) 
    h_test2D = TH2F('h_m_12_vs_m_34_'+typevec[itype],'m12_m34_'+typevec[itype],150,0,150,150,0,150);h_m_12_vs_m_34_.append(h_test2D);hists2D.append(h_test2D) 
    h_test2D = TH2F('h_m_4l_vs_m_12_'+typevec[itype],'m4l_m12_'+typevec[itype],300,0,300,150,0,150);h_m_4l_vs_m_12_.append(h_test2D);hists2D.append(h_test2D)
    h_test2D = TH2F('h_m_4l_vs_m_34_'+typevec[itype],'m4l_m34_'+typevec[itype],300,0,300,150,0,150);h_m_4l_vs_m_34_.append(h_test2D);hists2D.append(h_test2D)

    h_test = TH1F('h_max_lepton_trk_iso20_'+typevec[itype], ';TrkIso20/Et',125,-0.5,2); h_max_lepton_trk_iso20_.append(h_test); hists.append(h_test)
    h_test = TH1F('h_max_lepton_trk_iso30_'+typevec[itype], ';TrkIso30/Et',125,-0.5,2); h_max_lepton_trk_iso30_.append(h_test); hists.append(h_test)
    h_test = TH1F('h_max_lepton_trk_iso40_'+typevec[itype], ';TrkIso40/Et',125,-0.5,2); h_max_lepton_trk_iso40_.append(h_test); hists.append(h_test)
    h_test = TH1F('h_max_lepton_calo_iso20_'+typevec[itype],';CaloIso20/Et',250,-0.5,2); h_max_lepton_calo_iso20_.append(h_test); hists.append(h_test)
    h_test = TH1F('h_max_lepton_calo_iso30_'+typevec[itype],';CaloIso30/Et',250,-0.5,2); h_max_lepton_calo_iso30_.append(h_test); hists.append(h_test)
    h_test = TH1F('h_max_lepton_calo_iso40_'+typevec[itype],';CaloIso40/Et',250,-0.5,2); h_max_lepton_calo_iso40_.append(h_test); hists.append(h_test)

    h_test = TH1F('h_trk_iso20_secondpair_sr_'+typevec[itype],  ';TrkIso20/Et',125, -0.5, 2);h_trk_iso20_secondpair_sr_.append(h_test); hists.append(h_test) 
    h_test = TH1F('h_trk_iso30_secondpair_sr_'+typevec[itype],  ';TrkIso30/Et',125, -0.5, 2);h_trk_iso30_secondpair_sr_.append(h_test); hists.append(h_test)			 				    
    h_test = TH1F('h_trk_iso40_secondpair_sr_'+typevec[itype],  ';TrkIso40/Et',125, -0.5, 2);h_trk_iso40_secondpair_sr_.append(h_test); hists.append(h_test)			 				    
    h_test = TH1F('h_calo_iso20_secondpair_sr_'+typevec[itype], ';CaloIso20/Et',250, -0.5, 2);h_calo_iso20_secondpair_sr_.append(h_test); hists.append(h_test) 
    h_test = TH1F('h_calo_iso30_secondpair_sr_'+typevec[itype], ';CaloIso30/Et',250, -0.5, 2);h_calo_iso30_secondpair_sr_.append(h_test); hists.append(h_test)								
    h_test = TH1F('h_calo_iso40_secondpair_sr_'+typevec[itype], ';CaloIso40/Et',250, -0.5, 2);h_calo_iso40_secondpair_sr_.append(h_test); hists.append(h_test)								

    if doCategories:
        h_test = TH1F('h_reco_categories_'+typevec[itype],'reco_categories_'+typevec[itype],10,0,10); h_reco_categories_.append(h_test); hists.append(h_test) 
        h_test2D = TH2F('h_categories_'+typevec[itype],'categories_'+typevec[itype],10,0,10,6,0,6);h_categories_.append(h_test2D);hists2D.append(h_test2D)


for hist in hists:
    hist.Sumw2()

for hist in hists2D:
    hist.Sumw2() 



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


####################################CANDIDATE LIST

eventnumberarr = []
f_candidates = []
name_files = ['candidates_4mu.txt','candidates_4e.txt','candidates_2mu2e.txt','candidates_2e2mu.txt']
if printEventNumbers: 
    for ifile in xrange(4):
        f_test = open(name_files[ifile], 'w')
        f_candidates.append(f_test)

####################################LOOP OVER EVENTS

nentries = fin.GetEntries()

if (nentries == 0):
  print "Found no events!  Aborting..."
  sys.exit()

for i in xrange(nentries):
    if not (fin.GetEntry(i)): continue
    if not i%10000: print 'Processing entry %d/%d'%(i,nentries)

    #electron cuts
    pass_ML = true
    pass_ML_firstpair = true
    pass_ML_secondpair = true
    pass_ML_HCP = true
    pass_ML_HCP_firstpair = true
    pass_ML_HCP_secondpair = true
    pass_LooseLikelihood = true
    pass_LooseLikelihood_firstpair = true
    pass_LooseLikelihood_secondpair = true
    pass_blayer = true
    pass_blayer_firstpair = true
    pass_blayer_secondpair = true
    pass_twopixel = true
    
    #electron cuts
    for i in range(len(fin.lepton_type)):
    
      #only apply cuts on electrons
      if ( abs(fin.lepton_type[i]) != 1): continue

      if (fin.lepton_passML[i] != 1):
        pass_ML = false
        if (i < 2): pass_ML_firstpair = false
	else: pass_ML_secondpair = false

      if (fin.lepton_passML_HCP[i] != 1):
        pass_ML_HCP = false
        if (i < 2): pass_ML_HCP_firstpair = false
	else: pass_ML_HCP_secondpair = false

      if (fin.lepton_passLooseLikelihood[i] != 1):
        pass_LooseLikelihood = false
        if (i < 2): pass_LooseLikelihood_firstpair = false
	else: pass_LooseLikelihood_secondpair = false
     
      #if ( fin.lepton_pt[i] > 15000): continue

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
       if not (fin.lepton_trk_iso20[i] < 0.15): 
          pass_TrkIso = false
          if (i < 2): pass_TrkIso_firstpair = false
          else: pass_TrkIso_secondpair = false
                
    #sanity check
    if (fin.quad_passML != pass_ML): print "ERROR 1"
    if (fin.quad_passLooseLikelihood != pass_LooseLikelihood): print "ERROR 2"
    #if (fin.quad_passMediumLikelihood != pass_MediumLikelihood): print "ERROR 3"
    #if (fin.quad_passTrkIso != pass_TrkIso): print "ERROR 4"
   

    #electron cuts
    #if not fin.quad_passML: continue
    #if not fin.quad_passML_HCP: continue    
    #if not fin.quad_passLooseLikelihood: continue
    #if not fin.quad_passMediumLikelihood: continue
    #if not fin.quad_passLikelihood: continue
  
    #if not pass_ML: continue
    #if not pass_ML_firstpair: continue
    #if not pass_ML_secondpair: continue

    #if not pass_ML_HCP: continue
    if not pass_ML_HCP_firstpair: continue
    #if not pass_ML_HCP_secondpair: continue

    #if not pass_LooseLikelihood: continue
    #if not pass_LooseLikelihood_firstpair: continue
    #if not pass_LooseLikelihood_secondpair: continue
  
    #if not pass_blayer: continue
    #if not pass_blayer_firstpair: continue
    #if not pass_blayer_secondpair: continue

    #if not pass_twopixel: continue

    #iso cuts
    #if not fin.quad_passTrkIso: continue
    if not pass_TrkIso_firstpair: continue
    #if not pass_TrkIso_secondpair: continue    
    
    if not fin.quad_passCaloIso: continue
 

    #if doJets: ##require !TRT, !rphi (eta >2.0)
    #    passJets = 1
    #    for il in xrange(4):
    #        if il < 2: continue
    #        if abs(fin.lepton_type[il]) == 1:
    #            if ElectronRecoClass.IsJetLike(fin.el_cl_eta[fin.lepton_index[il]],fin.el_TRTHighTOutliersRatio[fin.lepton_index[il]],fin.el_rphi[fin.lepton_index[il]],fin.el_nTRTHits[fin.lepton_index[il]],fin.el_nTRTOutliers[fin.lepton_index[il]],fin.el_f1[fin.lepton_index[il]]) != 1: passJets = 0
    #    if not passJets: continue 
    
    xs_norm = 1.0
                 
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
        xs_norm = 1./weightsmap[fin.mc_channel_number] * crossSection

    ###don't allow duplicates
    if isData: 
        if  fin.RunNumber*100000+fin.EventNumber not in eventnumberarr: eventnumberarr.append(fin.RunNumber*100000+fin.EventNumber)
        else:
	    #print 'duplicate in the two streams' 
	    continue
    numberevents_passed[4]+=1

    event_weight = 1.0
    event_weight = event_weight*xs_norm
    #event_weight = event_weight*fin.lepton_sf
    event_weight = event_weight*fin.trigger_sf
    event_weight = event_weight*fin.vertex_sf
    event_weight = event_weight*fin.pileup_sf

    ###fill inclusive histograms

    h_m_4l.Fill(fin.m_4l/1000., event_weight)
    h_m_12.Fill(fin.m_12/1000., event_weight)
    h_m_34.Fill(fin.m_34/1000., event_weight)
    h_m_12_vs_m_34.Fill(fin.m_12/1000.,fin.m_34/1000., event_weight)
    h_m_4l_vs_m_12.Fill(fin.m_4l/1000.,fin.m_12/1000., event_weight)
    
    ###fill signal region histograms
    if (fin.m_4l/1000. > sr_min and fin.m_4l/1000. < sr_max):
	h_m_4l_sr.Fill(fin.m_4l/1000., event_weight)
	h_m_12_sr.Fill(fin.m_12/1000., event_weight)
	h_m_34_sr.Fill(fin.m_34/1000., event_weight)
 
    ###separate into quadruplets
    for itype in xrange(4):
	if fin.quad_type == itype:
            numberevents_passed[itype]+=1
            if printEventNumbers: 
                print >>f_candidates[itype],str(fin.RunNumber).ljust(8)+" "+str(fin.EventNumber).ljust(12)+" "+str(fin.lbn).ljust(6)+" "+str(round(fin.m_4l/1000.,2)).ljust(8)+" "+str(round(fin.m_12/1000.,2)).ljust(8)+"\t"+str(round(fin.m_34/1000.,2)).ljust(8)
            h_m_4l_[itype].Fill(fin.m_4l/1000., event_weight)
            h_m_12_[itype].Fill(fin.m_12/1000., event_weight)
            h_m_34_[itype].Fill(fin.m_34/1000., event_weight)
            h_m_12_vs_m_34_[itype].Fill(fin.m_12/1000.,fin.m_34/1000., event_weight)
            h_m_4l_vs_m_12_[itype].Fill(fin.m_4l/1000.,fin.m_12/1000., event_weight)   
            h_m_4l_vs_m_34_[itype].Fill(fin.m_4l/1000.,fin.m_34/1000., event_weight)

	    for i in (2,3):
	       if (abs(fin.lepton_type[i]) != 1): continue
               #if (fin.lepton_passML[i] != 1): continue
               if (fin.lepton_passML_HCP[i] != 1): continue
  	       #if (fin.lepton_passLooseLikelihood[i] != 1): continue

	       index = fin.lepton_index[i]
               if ( (fin.el_expectHitInBLayer[index] == 1 and fin.el_nBLHits[index] < 1) or ((fin.el_nPixHits[index]+fin.el_nPixelDeadSensors[index]) < 2)): continue       	   

	       h_trk_iso20_secondpair_sr_[itype].Fill(fin.lepton_trk_iso20[i], event_weight)
               h_trk_iso30_secondpair_sr_[itype].Fill(fin.lepton_trk_iso30[i], event_weight)
               h_trk_iso40_secondpair_sr_[itype].Fill(fin.lepton_trk_iso40[i], event_weight)

	       h_calo_iso20_secondpair_sr_[itype].Fill(fin.lepton_calo_iso20[i], event_weight)
               h_calo_iso30_secondpair_sr_[itype].Fill(fin.lepton_calo_iso30[i], event_weight)
               h_calo_iso40_secondpair_sr_[itype].Fill(fin.lepton_calo_iso40[i], event_weight)
            
	    if (fin.m_4l/1000. > sr_min and fin.m_4l/1000. < sr_max):
		h_max_lepton_trk_iso20_[itype].Fill(max(fin.lepton_trk_iso20), event_weight)
		h_max_lepton_trk_iso30_[itype].Fill(max(fin.lepton_trk_iso30), event_weight)
		h_max_lepton_trk_iso40_[itype].Fill(max(fin.lepton_trk_iso40), event_weight)

		h_max_lepton_calo_iso20_[itype].Fill(max(fin.lepton_calo_iso20), event_weight)
		h_max_lepton_calo_iso30_[itype].Fill(max(fin.lepton_calo_iso30), event_weight)
		h_max_lepton_calo_iso40_[itype].Fill(max(fin.lepton_calo_iso40), event_weight)
        	

            #####categories
            if doCategories:
                if abs(fin.lepton_type[3]) != 1: continue ##only interested in subleading pair being electrons
                index_sub1 = fin.lepton_index[2]
                index_sub2 = fin.lepton_index[3]
                h_reco_categories_[itype].Fill(0, event_weight) ##all
                cat_sub1 = ElectronRecoClass.getRecoClassificationPenn(fin.el_cl_eta[index_sub1],fin.el_TRTHighTOutliersRatio[index_sub1],fin.el_rphi[index_sub1],fin.el_nTRTHits[index_sub1],fin.el_nTRTOutliers[index_sub1],fin.el_f1[index_sub1],fin.lepton_calo_iso20[2],fin.lepton_trk_iso20[2],fin.lepton_d0_significance[2],fin.lepton_passML[2])
                cat_sub2 = ElectronRecoClass.getRecoClassificationPenn(fin.el_cl_eta[index_sub2],fin.el_TRTHighTOutliersRatio[index_sub2],fin.el_rphi[index_sub2],fin.el_nTRTHits[index_sub2],fin.el_nTRTOutliers[index_sub2],fin.el_f1[index_sub2],fin.lepton_calo_iso20[3],fin.lepton_trk_iso20[3],fin.lepton_d0_significance[3],fin.lepton_passML[3])

                if cat_sub1 == 1 and cat_sub2 ==1: h_reco_categories_[itype].Fill(1, event_weight)
                elif cat_sub1 == 3 and cat_sub2 ==3: h_reco_categories_[itype].Fill(2, event_weight)  
                elif cat_sub1 == 4 and cat_sub2 ==4: h_reco_categories_[itype].Fill(3, event_weight)
                elif cat_sub1 == 3 and cat_sub2 ==4: h_reco_categories_[itype].Fill(4, event_weight)
                elif cat_sub1 == 4 and cat_sub2 ==3: h_reco_categories_[itype].Fill(5, event_weight)
                else: h_reco_categories_[itype].Fill(6, event_weight)

                     
            #####end categories

    for il in xrange(4):
	if il < 2: continue
	h_lepton_trk_iso20_34.Fill(fin.lepton_trk_iso20[il], event_weight)
	h_lepton_calo_iso20_34.Fill(fin.lepton_calo_iso20[il], event_weight)
        if abs(fin.lepton_type[il]) == 1:
            h_el_calo_iso20_34.Fill(fin.lepton_calo_iso20[il], event_weight)
            if fin.m_4l < 110000 and fin.m_4l > 70000: h_el_calo_iso20_34_M4l_70_110.Fill(fin.lepton_calo_iso20[il], event_weight)
            if fin.m_34 < 90000: h_el_calo_iso20_34_M34_l90.Fill(fin.lepton_calo_iso20[il], event_weight)
            if fin.m_12 < 90000: h_el_calo_iso20_34_M12_l90.Fill(fin.lepton_calo_iso20[il], event_weight)

            TRT_total = fin.el_nTRTHits[fin.lepton_index[il]]+fin.el_nTRTOutliers[fin.lepton_index[il]]
            if TRT_total != 0: 
                TRT_ratio = (float(fin.el_nTRTHighTHits[fin.lepton_index[il]])+fin.el_nTRTHighTOutliers[fin.lepton_index[il]])/TRT_total
                h_el_nTRT_34.Fill(TRT_ratio, event_weight)
                if fin.m_4l < 110000 and fin.m_4l > 70000: h_el_nTRT_34_M4l_70_110.Fill(TRT_ratio, event_weight)
                if fin.m_34 < 90000: h_el_nTRT_34_M34_l90.Fill(TRT_ratio, event_weight)
                if fin.m_12 < 90000: h_el_nTRT_34_M12_l90.Fill(TRT_ratio, event_weight)



####################################PRINT

print input_dir
print 'initial number of events: '+str(numberevents_all)
print 'after cutflow: '+str(numberevents_passed[4])
print '4mu: '+str(numberevents_passed[0])
print '4e: '+str(numberevents_passed[1])
print '2mu2e: '+str(numberevents_passed[2])
print '2e2mu: '+str(numberevents_passed[3])


####################################WRITE TO FILE

labels = ["4#mu","4e","2#mu2e","2e2#mu","all"]
h_passed  = TH1F('h_passed','passed',5,0,5);  hists.append(h_passed)
for itype in xrange(5):
    h_passed.SetBinContent(itype+1,numberevents_passed[itype])
    h_passed.GetXaxis().SetBinLabel(itype+1,labels[itype])

fileout = TFile((output_dir if (output_dir != '') else input_dir)+"/"+input_key+"_passed.root",'RECREATE')
#fileout = TFile(input_key+"_passed.root",'RECREATE')

for hist in hists:
    hist.Write()

for hist in hists2D:
    hist.Write()

if printEventNumbers:
    for ifile in xrange(4):
        f_candidates[ifile].close()
        os.system("sort -k1,1n -k2,2n "+ name_files[ifile]+" > test.txt")
        os.system("mv test.txt "+ name_files[ifile])


print "Closing output file: " + fileout.GetPath().rstrip(':/')
fileout.Close()


