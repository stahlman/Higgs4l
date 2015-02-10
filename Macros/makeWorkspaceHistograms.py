#!/usr/bin/env python
"""
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'Nov 2012'

#---------------------------------------------------------------------------
DEBUG = 1

import os, sys, string, commands, math
from datetime import datetime
from pprint import pprint
from HistogramUtils import *
## Needed to correct ROOT behavior; see below
CWD = os.getcwd()

if not len(sys.argv) >= 4:  raise(Exception, "Usage: ./makeWorkspaceHistograms.py <inputdir> <key> <type=mc or data>")

input_dir = sys.argv[1]
input_key = sys.argv[2]
input_type = sys.argv[3]
printEventNumbers = 0
doCategories = 1

isData = 0
if input_type == "data" or input_type == "Data": isData = 1
if not isData: printEventNumbers = 0 ###does not make sense for MC


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


#files = glob.glob(input_dir + '/*'+input_key+'*/*/*.root')
files = glob.glob(input_dir + '/*'+input_key+'.root')
print "Using input files:"
for f in files: print '  ' + f
tree_name = 'output'
fin = TChain(tree_name)

####################################COUNTERS

numberevents_all=0
numberevents_passed = [0,0,0,0,0]

GeV = 1000.0

####################################HISTOGRAMS

channelvec = ["4mu","4e","2mu2e","2e2mu"]

bkghists = []
bkgvec = ['ZZ', 'Z', 'Zbb', 'gg2ZZ', 'tt']

sighists = []
sigvec = ['higgs', 'higgsVBF', 'higgsWH', 'higgsZH']


for i in range(len(bkgvec)):
  for j in range(len(channelvec)):
     if (j == 0): bkghists.append([])
     bkghists[i].append(TH1F('histo' + bkgvec[i]+ '_' + str(j),'',2000,0.0,1000.0))
     bkghists[i][j].Sumw2()

for i in range(len(sigvec)):
  for j in range(len(channelvec)):
     if (j == 0): sighists.append([])
     sighists[i].append(TH1F(sigvec[i]+ '_' + str(j),'',2000,0.0,1000.0))
     sighists[i][j].Sumw2()


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
for i in xrange(nentries):
    if not (fin.GetEntry(i)): continue
    if not i%10000: print 'Processing entry %d/%d'%(i,nentries)
                 
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
        event_weight = 1./weightsmap[fin.mc_channel_number] * crossSection * fin.evt_weight

    ###don't allow duplicates
    if isData: 
        if  fin.RunNumber*100000+fin.EventNumber not in eventnumberarr: eventnumberarr.append(fin.RunNumber*100000+fin.EventNumber)
        else:
	    print 'duplicate in the two streams' 
	    continue
    numberevents_passed[4]+=1

    ###fill inclusive histograms
    
    quad_type = fin.quad_type
    channel = ChannelNumber(fin.mc_channel_number)
    
    bkghists[channel][quad_type].Fill(fin.m_4l/GeV,event_weight)    
    
    numberevents_passed[quad_type]+=1
    
    ###separate into quadruplets
    #for itype in xrange(4):
#	if fin.quad_type == itype:
#            numberevents_passed[itype]+=1
#            if printEventNumbers: 
#                print >>f_candidates[itype],str(fin.RunNumber).ljust(8)+" "+str(fin.EventNumber).ljust(12)+" "+str(fin.lbn).ljust(6)+" "+str(round(fin.m_4l/1000.,2)).ljust(8)+" "+str(round(fin.m_12/1000.,2)).ljust(8)+"\t"+str(round(fin.m_34/1000.,2)).ljust(8)
#            h_m_4l_[itype].Fill(fin.m_4l/1000., event_weight)

            #####categories

                     
            #####end categories



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
#h_passed  = TH1F('h_passed','passed',5,0,5);  hists.append(h_passed)
#for itype in xrange(5):
#    h_passed.SetBinContent(itype+1,numberevents_passed[itype])
#    h_passed.GetXaxis().SetBinLabel(itype+1,labels[itype])

fileout = TFile(input_dir+"/"+input_key+"_WorkspaceHistos.root",'RECREATE')

for i in range(len(bkgvec)):
  for j in range(len(channelvec)):
     bkghists[i][j].Write()

for i in range(len(sigvec)):
  for j in range(len(channelvec)):
     sighists[i][j].Write()

if printEventNumbers:
    for ifile in xrange(4):
        f_candidates[ifile].close()
        os.system("sort -k1,1n -k2,2n "+ name_files[ifile]+" > test.txt")
        os.system("mv test.txt "+ name_files[ifile])

print "Closing output file: " + fileout.GetPath().rstrip(':/')
fileout.Close()


