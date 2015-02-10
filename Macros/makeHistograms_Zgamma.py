#!/usr/bin/env python
"""
"""

__author__ = 'Heim Sarah'
__email__ = 'sheim@cern.ch'
__date__ = 'Sep 2012'

#---------------------------------------------------------------------------


import os, sys, string, commands, math
from datetime import datetime
## Needed to correct ROOT behavior; see below
CWD = os.getcwd()

if not len(sys.argv) >= 4:  raise(Exception, "Must specify inputdir, key and type as argument!")

input_dir = sys.argv[1]
input_key = sys.argv[2]
input_type = sys.argv[3]

isData = 0
if input_type == "data" or input_type == "Data": isData = 1



import math
from ROOT import *
#from pyroot_helpers import *
from array import array
import glob

##for GRL...
if isData:
    os.chdir(CWD)
    gSystem.Load('externals/GoodRunsLists/StandAlone/libGoodRunsLists.so')
    from ROOT import Root
    reader = Root.TGoodRunsListReader('externals/GoodRunsLists/lists/data12_8TeV.periodAllYear_HEAD_CoolRunQuery-00-04-08_All_Good.xml')
    reader.Interpret()
    goodrunslist = reader.GetMergedGRLCollection()
    ## show summary of content
    goodrunslist.Summary()



else:
    #os.chdir(CWD)
    ###need LinkDef.h in HiggsZZ4lUtils package with CrossSections included for this to work
    #gSystem.Load('externals/libHiggsZZ4lUtils.so')
    #crossSection = CrossSections.bkgCrossSection(107650, CrossSections.EightTeV, 1) 
    #print 'test: '+crossSection 
    crossSection = 1

files = glob.glob(input_dir + '/*'+input_key+'*/*/*.root')

numberevents_all=0
numberevents_passed=0
hists = []
hists2D = []

h_probe_eta = TH1F('h_probe_eta','probe_eta',600,-3,3);  hists.append(h_probe_eta)
h_probe_Et = TH1F('h_probe_Et','probe_Et',200,0,200);  hists.append(h_probe_Et)
h_probe_Et_ML = TH1F('h_probe_Et_ML','probe_Et_ML',200,0,200);  hists.append(h_probe_Et_ML)
h_probe_Et_Tight = TH1F('h_probe_Et_Tight','probe_Et_Tight',200,0,200);  hists.append(h_probe_Et_Tight)


h_probe_Et_probe_eta = TH2F('h_probe_Et_probe_eta','probe_Et_probe_eta',200,0,200,500,-2.5,2.5);  hists2D.append(h_probe_Et_probe_eta)
h_probe_Et_probe_eta_OS = TH2F('h_probe_Et_probe_eta_OS','probe_Et_probe_eta_OS',200,0,200,500,-2.5,2.5);  hists2D.append(h_probe_Et_probe_eta_OS)


h_probe_Et_probe_tag_mass = TH2F('h_probe_Et_probe_tag_mass','probe_Et_probe_tag_mass',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_mass)
h_probe_Et_probe_tag_photon_mass = TH2F('h_probe_Et_probe_tag_photon_mass','probe_Et_probe_tag_photon_mass',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_photon_mass)
h_probe_Et_probe_tag_photon_mass_OS = TH2F('h_probe_Et_probe_tag_photon_mass_OS','probe_Et_probe_tag_photon_mass_OS',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_photon_mass_OS)
h_probe_Et_probe_tag_photon_mass_SS = TH2F('h_probe_Et_probe_tag_photon_mass_SS','probe_Et_probe_tag_photon_mass_SS',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_photon_mass_SS)
h_probe_Et_probe_tag_photon_mass_ML = TH2F('h_probe_Et_probe_tag_photon_mass_ML','probe_Et_probe_tag_photon_mass_ML',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_photon_mass_ML)
h_probe_Et_probe_tag_photon_mass_ML_OS = TH2F('h_probe_Et_probe_tag_photon_mass_ML_OS','probe_Et_probe_tag_photon_mass_ML_OS',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_photon_mass_ML_OS)
h_probe_Et_probe_tag_photon_mass_ML_SS = TH2F('h_probe_Et_probe_tag_photon_mass_ML_SS','probe_Et_probe_tag_photon_mass_ML_SS',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_photon_mass_ML_SS)
h_probe_Et_probe_tag_photon_mass_Tight = TH2F('h_probe_Et_probe_tag_photon_mass_Tight','probe_Et_probe_tag_photon_mass_Tight',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_photon_mass_Tight)
h_probe_Et_probe_tag_photon_mass_Tight_OS = TH2F('h_probe_Et_probe_tag_photon_mass_Tight_OS','probe_Et_probe_tag_photon_mass_Tight_OS',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_photon_mass_Tight_OS)
h_probe_Et_probe_tag_photon_mass_Tight_SS = TH2F('h_probe_Et_probe_tag_photon_mass_Tight_SS','probe_Et_probe_tag_photon_mass_Tight_SS',200,0,200,200,0,200);  hists2D.append(h_probe_Et_probe_tag_photon_mass_Tight_SS)
h_probe_Et_photon_Et = TH2F('h_probe_Et_photon_Et','probe_Et_photon_Et',200,0,200,200,0,200);  hists2D.append(h_probe_Et_photon_Et)
h_tag_Et_photon_Et = TH2F('h_tag_Et_photon_Et','tag_Et_photon_Et',200,0,200,200,0,200);  hists2D.append(h_tag_Et_photon_Et)
h_probe_Et_photon_Et_prompt = TH2F('h_probe_Et_photon_Et_prompt','probe_Et_photon_Et_prompt',200,0,200,200,0,200);  hists2D.append(h_probe_Et_photon_Et_prompt)
h_probe_Et_probe_photon_dR = TH2F('h_probe_Et_probe_photon_dR','probe_Et_probe_photon_dR',200,0,200,100,0,10);  hists2D.append(h_probe_Et_probe_photon_dR)
h_probe_Et_probe_photon_dR_Tight = TH2F('h_probe_Et_probe_photon_dR_Tight','probe_Et_probe_photon_dR_Tight',200,0,200,100,0,10);  hists2D.append(h_probe_Et_probe_photon_dR_Tight)
h_probe_Et_photon_topoiso20 = TH2F('h_probe_Et_photon_topoiso20','probe_Et_photon_topoiso20',200,0,200,100,0,10);  hists2D.append(h_probe_Et_photon_topoiso20)
h_probe_Et_photon_topoiso40 = TH2F('h_probe_Et_photon_topoiso40','probe_Et_photon_topoiso40',200,0,200,100,0,10);  hists2D.append(h_probe_Et_photon_topoiso40)
h_probe_photon_dR_probe_tag_mass = TH2F('h_probe_photon_dR_probe_tag_mass','probe_photon_dR_probe_tag_mass',100,0,10,200,0,200);  hists2D.append(h_probe_photon_dR_probe_tag_mass)
h_probe_photon_dR_probe_tag_photon_mass = TH2F('h_probe_photon_dR_probe_tag_photon_mass','probe_photon_dR_probe_tag_photon_mass',100,0,10,200,0,200);  hists2D.append(h_probe_photon_dR_probe_tag_photon_mass)
h_probe_photon_dR_probe_tag_photon_mass_7_10 = TH2F('h_probe_photon_dR_probe_tag_photon_mass_7_10','probe_photon_dR_probe_tag_photon_mass_7_10',100,0,10,200,0,200);  hists2D.append(h_probe_photon_dR_probe_tag_photon_mass_7_10)
h_tag_photon_dR_probe_tag_photon_mass = TH2F('h_tag_photon_dR_probe_tag_photon_mass','tag_photon_dR_probe_tag_photon_mass',100,0,10,200,0,200);  hists2D.append(h_tag_photon_dR_probe_tag_photon_mass)
h_tag_photon_dR_probe_tag_photon_mass_7_10 = TH2F('h_tag_photon_dR_probe_tag_photon_mass_7_10','tag_photon_dR_probe_tag_photon_mass_7_10',100,0,10,200,0,200);  hists2D.append(h_tag_photon_dR_probe_tag_photon_mass_7_10)
h_probe_tag_dR_probe_tag_photon_mass = TH2F('h_probe_tag_dR_probe_tag_photon_mass','probe_tag_dR_probe_tag_photon_mass',100,0,10,200,0,200);  hists2D.append(h_probe_tag_dR_probe_tag_photon_mass)
h_probe_tag_dR_probe_tag_photon_mass_7_10 = TH2F('h_probe_tag_dR_probe_tag_photon_mass_7_10','probe_tag_dR_probe_tag_photon_mass_7_10',100,0,10,200,0,200);  hists2D.append(h_probe_tag_dR_probe_tag_photon_mass_7_10)
h_probe_tag_mass_probe_tag_photon_mass = TH2F('h_probe_tag_mass_probe_tag_photon_mass','probe_tag_mass_probe_tag_photon_mass',200,0,200,200,0,200);  hists2D.append(h_probe_tag_mass_probe_tag_photon_mass)
h_probe_tag_mass_probe_tag_photon_mass_7_10 = TH2F('h_probe_tag_mass_probe_tag_photon_mass_7_10','probe_tag_mass_probe_tag_photon_mass_7_10',200,0,200,200,0,200);  hists2D.append(h_probe_tag_mass_probe_tag_photon_mass_7_10)
h_tag_photon_mass_probe_tag_photon_mass = TH2F('h_tag_photon_mass_probe_tag_photon_mass','tag_photon_mass_probe_tag_photon_mass',200,0,200,200,0,200);  hists2D.append(h_tag_photon_mass_probe_tag_photon_mass)
h_tag_photon_mass_probe_tag_photon_mass_7_10 = TH2F('h_tag_photon_mass_probe_tag_photon_mass_7_10','tag_photon_mass_probe_tag_photon_mass_7_10',200,0,200,200,0,200);  hists2D.append(h_tag_photon_mass_probe_tag_photon_mass_7_10)




tree_name = 'output'
fin = TChain(tree_name)

eventnumberarr = []
weights = 1.
Lumi = 12000


for subf in files:
    file = TFile(subf,"READ")
    numbereventsPar = file.Get("N_all_events")
    numberevents_all+=numbereventsPar.GetVal()
    numbereventspassedPar = file.Get("N_passed_events")
    numberevents_passed+=numbereventspassedPar.GetVal()
    fin.Add(subf)
    file.Close()    


###loop over events
nentries = fin.GetEntries()
for i in xrange(nentries):
    if not (fin.GetEntry(i)): continue
    #if not i%10000: print 'Processing entry %d/%d'%(i,nentries)
    ###GRL cut, only if data..
    if isData: 
        if not goodrunslist.HasRunLumiBlock (fin.RunNumber,fin.lbn) : continue 
        weights_event = 1
    ####weights
    else:
         if fin.mc_channel_number == 129250: crossSection = 1109*0.04
         elif fin.mc_channel_number == 147806: crossSection = 1109*1.04
         #crossSection = 1109*0.04
         weights_event = crossSection * Lumi * fin.evt_weight /numberevents_all

    ###loop over probes
    for iprobe in xrange(fin.probe_n):
        if fin.probe_Et[iprobe]+fin.photon_Et[fin.probe_photon_vecindex[iprobe]] < 30000: continue
        #if fin.photon_isConv[fin.probe_photon_vecindex[iprobe]]: continue
        #if fin.probe_photon_dR[iprobe] > 1: continue
        #if fin.p_tag_photon_mass[iprobe]  > 80000: continue
        #if not (fin.probe_truth_matched[iprobe] == 1 and ((fin.probe_type[iprobe] == 2 and fin.probe_origin[iprobe] == 13) or (fin.probe_type[iprobe] == 4 and (fin.probe_origin[iprobe] == 13 or fin.probe_origin[iprobe] == 40)))): continue
        #if fin.photon_truth_type[fin.probe_photon_vecindex[iprobe]] != 22: continue
        if fin.probe_tag_photon_mass[iprobe] < 100000 and fin.probe_tag_photon_mass[iprobe]> 80000:
        #if 1:
            h_probe_Et.Fill(fin.probe_Et[iprobe]/1000.,weights_event)
            h_probe_Et_probe_eta.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_eta[iprobe],weights_event)
            if fin.probe_tag_OS[iprobe]: h_probe_Et_probe_eta_OS.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_eta[iprobe],weights_event)
            if fin.probe_passML[iprobe]:  h_probe_Et_ML.Fill(fin.probe_Et[iprobe]/1000.,weights_event)          
            if fin.probe_passTight[iprobe]: h_probe_Et_Tight.Fill(fin.probe_Et[iprobe]/1000.,weights_event)
        
        if fin.probe_passML[iprobe]: 
            h_probe_Et_probe_tag_photon_mass_ML.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
            if fin.probe_tag_OS[iprobe]:
                h_probe_Et_probe_tag_photon_mass_ML_OS.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
            else:
                h_probe_Et_probe_tag_photon_mass_ML_SS.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
        if fin.probe_passTight[iprobe]: 
            h_probe_Et_probe_tag_photon_mass_Tight.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
            h_probe_Et_probe_photon_dR_Tight.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_photon_dR[iprobe],weights_event)
            if fin.probe_tag_OS[iprobe]:
                h_probe_Et_probe_tag_photon_mass_Tight_OS.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
            else:
                h_probe_Et_probe_tag_photon_mass_Tight_SS.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
        h_probe_Et_probe_tag_mass.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_mass[iprobe]/1000.,weights_event)
        h_probe_Et_probe_tag_photon_mass.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
        if fin.probe_tag_OS[iprobe]: 
            h_probe_Et_probe_tag_photon_mass_OS.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event) 
        else:
            h_probe_Et_probe_tag_photon_mass_SS.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
        h_probe_Et_probe_photon_dR.Fill(fin.probe_Et[iprobe]/1000.,fin.probe_photon_dR[iprobe],weights_event)
        h_probe_Et_photon_topoiso20.Fill(fin.probe_Et[iprobe]/1000.,fin.photon_topoiso20[fin.probe_photon_vecindex[iprobe]]/1000.,weights_event)
        h_probe_Et_photon_topoiso40.Fill(fin.probe_Et[iprobe]/1000.,fin.photon_topoiso40[fin.probe_photon_vecindex[iprobe]]/1000.,weights_event)
        h_probe_photon_dR_probe_tag_mass.Fill(fin.probe_photon_dR[iprobe],fin.probe_tag_mass[iprobe]/1000.,weights_event)
        h_probe_photon_dR_probe_tag_photon_mass.Fill(fin.probe_photon_dR[iprobe],fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
        h_probe_tag_dR_probe_tag_photon_mass.Fill(fin.probe_tag_dR[iprobe],fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
        h_tag_photon_dR_probe_tag_photon_mass.Fill(fin.p_tag_photon_dR[iprobe],fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
        #if fin.probe_type[iprobe]==2 and fin.probe_origin[iprobe]==13: h_probe_Et_photon_Et_prompt.Fill(fin.probe_Et[iprobe]/1000.,fin.photon_Et[fin.probe_photon_vecindex[iprobe]]/1000.,weights_event) 
        h_probe_Et_photon_Et.Fill(fin.probe_Et[iprobe]/1000.,fin.photon_Et[fin.probe_photon_vecindex[iprobe]]/1000.,weights_event)
        h_probe_tag_mass_probe_tag_photon_mass.Fill(fin.probe_tag_mass[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
        h_tag_photon_mass_probe_tag_photon_mass.Fill(fin.p_tag_photon_mass[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
        if fin.probe_Et[iprobe]/1000. < 10: 
            h_tag_Et_photon_Et.Fill(fin.tag_Et[fin.probe_tag_vecindex[iprobe]]/1000.,fin.photon_Et[fin.probe_photon_vecindex[iprobe]]/1000.,weights_event)   
            h_probe_photon_dR_probe_tag_photon_mass_7_10.Fill(fin.probe_photon_dR[iprobe],fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
            h_tag_photon_dR_probe_tag_photon_mass_7_10.Fill(fin.p_tag_photon_dR[iprobe],fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
            h_probe_tag_dR_probe_tag_photon_mass_7_10.Fill(fin.probe_tag_dR[iprobe],fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
            h_probe_tag_mass_probe_tag_photon_mass_7_10.Fill(fin.probe_tag_mass[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)
            h_tag_photon_mass_probe_tag_photon_mass_7_10.Fill(fin.p_tag_photon_mass[iprobe]/1000.,fin.probe_tag_photon_mass[iprobe]/1000.,weights_event)



print input_dir
print 'initial number of events: '+str(numberevents_all)
print 'after cutflow: '+str(numberevents_passed)


fileout = TFile(input_dir+"/"+input_key+"_passed.root",'RECREATE')

for hist in hists:
    hist.Write()
for hist in hists2D:
    hist.Write()


