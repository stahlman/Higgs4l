#!/usr/bin/env python

__author__ = 'Heim Sarah'
__email__ = 'sheim@cern.ch'
__date__ = 'Sep 2012'

#---------------------------------------------------------------------------
import os, sys, string, commands, math
from datetime import datetime
from pprint import pprint
import math
from ROOT import *
from array import array
import glob

from Histmaker_class import Histmaker
hm=Histmaker()
from Histfiller_class import Histfiller
hf=Histfiller()

if not len(sys.argv) >= 4:  raise(Exception, "Must specify inputdir, key and type as argument!")

input_dir = sys.argv[1]
input_key = sys.argv[2]
input_type = sys.argv[3]
output_dir = input_dir
if (len(sys.argv) == 5):
  output_dir = sys.argv[4]

add_name = ""
printEventNumbers = 1
lumi = 20.7

isData = 0
if input_type == "data" or input_type == "Data": isData = 1
if not isData: printEventNumbers = 0 #does not make sense for MC

blindSignalRegion = false

####################################INITIALIZATION OF EXTERNAL TOOLS
if isData:
    goodrunslist = hm.LoadGRL('externals/GoodRunsLists/lists/data12_8TeV.periodAllYear_HEAD_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml')
else:
    crossSection = hm.LoadXSBkg()
    HiggsCrossSection = hm.LoadXSHiggs()	
####################################INPUTFILES
#file_key = input_dir + '/*'+input_key+'*/*/*.root'
file_key = input_dir + '/*'+input_key+'*.root'
tree_name = 'output'
fin = TChain(tree_name)
hm.GetFilesAndInitialCounts(fin,file_key,isData)

####################################COUNTERS

numberevents_all=0
numberevents_passed = [0,0,0,0,0]

####################################HISTOGRAMS

hf.HistsBasic_Def()
hf.HistsSumw2()

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
   

    ##############################Apply cuts

    #PassCutsOnElectrons(self,fin,vecindex,blayer,Pix,TrkIso,CaloIso,d0,typeisEM)
    if fin.lepton_pt[2]>fin.lepton_pt[3]:
        vecindex_sub1 = 2
        vecindex_sub2 = 3
    else:
        vecindex_sub1 = 3
        vecindex_sub2 = 2
    index_sub1 = fin.lepton_index[vecindex_sub1]
    index_sub2 = fin.lepton_index[vecindex_sub2]

    #if (blindSignalRegion and hm.SignalRegion(fin)): continue
    if not (hm.SignalRegion(fin)): continue

    #if not hm.PassCutsOnElectrons(fin,0,1,1,0,0,0,"LooseLikelihood"): continue
    #if not hm.PassCutsOnElectrons(fin,1,1,1,0,0,0,"LooseLikelihood"): continue
    #if not hm.PassCutsOnElectrons(fin,vecindex_sub1,1,1,0,0,0,"VeryLooseLikelihood"): continue
    #if not hm.PassCutsOnElectrons(fin,vecindex_sub2,1,1,0,0,0,"VeryLooseLikelihood"): continue 
        
    if not hm.PassTrackIsolationCuts(fin,"All"): continue
    if not hm.PassCaloIsolationCuts(fin,"All"):  continue
    if not hm.PassD0SignificanceCuts(fin,"All"): continue

   

    for itype in xrange(4):
        if fin.quad_type == itype:
            numberevents_passed[itype]+=1
            if printEventNumbers:
                print >>f_candidates[itype],str(fin.RunNumber).ljust(8)+" "+str(fin.EventNumber).ljust(12)+" "+str(fin.lbn).ljust(6)+" "+str(round(fin.m_4l/1000.,2)).ljust(8)+" "+str(round(fin.m_12/1000.,2)).ljust(8)+"\t"+str(round(fin.m_34/1000.,2)).ljust(8)


 
    ###############################
    event_weight = 1.
    ###GRL cut, only if data..
    if isData:
        passData = hm.ApplyDataTreatment(fin,goodrunslist)
        if passData == -999: continue
    ####otherwise weights and overlap removal 146369 for 2012 (concerns ttbar sample)
    else:
        event_weight = hm.ApplyMCTreatment(fin,crossSection,HiggsCrossSection,lumi)
        if event_weight == -999: continue

   ##############################Fill histos
   
    numberevents_passed[4]+=1
    hf.HistsBasic_Fill(fin,event_weight)

    ##############################print event numbers

    #for itype in xrange(4):
    #    if fin.quad_type == itype:
    #        numberevents_passed[itype]+=1
    #        if printEventNumbers:
    #            print >>f_candidates[itype],str(fin.RunNumber).ljust(8)+" "+str(fin.EventNumber).ljust(12)+" "+str(fin.lbn).ljust(6)+" "+str(round(fin.m_4l/1000.,2)).ljust(8)+" "+str(round(fin.m_12/1000.,2)).ljust(8)+"\t"+str(round(fin.m_34/1000.,2)).ljust(8)
       


####################################PRINT

print input_dir
print 'initial number of events: '+str(hm.numberevents_all)
print 'after cutflow: '+str(numberevents_passed[4])
print '4mu: '+str(numberevents_passed[0])
print '4e: '+str(numberevents_passed[1])
print '2mu2e: '+str(numberevents_passed[2])
print '2e2mu: '+str(numberevents_passed[3])


####################################WRITE TO FILE

labels = ["4#mu","4e","2#mu2e","2e2#mu","all"]
h_passed  = TH1F('h_passed','passed',5,0,5);  hf.hists.append(h_passed)
for itype in xrange(5):
    h_passed.SetBinContent(itype+1,numberevents_passed[itype])
    h_passed.GetXaxis().SetBinLabel(itype+1,labels[itype])

fileout = TFile(output_dir+"/"+input_key+"_passed"+add_name+".root",'RECREATE')

hf.HistsWrite()

if printEventNumbers:
    for ifile in xrange(4):
        f_candidates[ifile].close()
        os.system("sort -k1,1n -k2,2n "+ name_files[ifile]+" > test.txt")
        os.system("mv test.txt "+ name_files[ifile])


print "Closing output file: " + fileout.GetPath().rstrip(':/')
fileout.Close()


