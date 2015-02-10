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

if not (len(sys.argv) >= 3):  raise(Exception, "Must specify inputdir, key and type as argument!")

input_dir =  ''
input_key =  ''
input_type = ''
output_dir = ''

if (len(sys.argv) == 3):
  input_key = sys.argv[1]
  input_type = sys.argv[2]

if (len(sys.argv) >= 4):
  input_dir = sys.argv[1]
  input_key = sys.argv[2]
  input_type = sys.argv[3]

if (len(sys.argv) == 5):
  output_dir = sys.argv[4]
else: 
  output_dir = input_dir

add_name = ""
printEventNumbers = 1
lumi = 20.7

debug_runs   = []
debug_events = []

isData = 0
if input_type == "data" or input_type == "Data": isData = 1

####################################INITIALIZATION OF EXTERNAL TOOLS
if isData:
    goodrunslist = hm.LoadGRL('externals/GoodRunsLists/lists/data12_8TeV.periodAllYear_HEAD_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml')

####################################INPUTFILES

file_key = ''
if (len(sys.argv) == 3):  file_key = input_key
if (len(sys.argv) >= 4):  file_key = input_dir + '/*'+input_key+'*/*/*.root'

tree_name = 'output'
fin = TChain(tree_name)
hm.GetFilesAndInitialCounts(fin,file_key,isData)

####################################COUNTERS

numberevents_all=0
numberevents_passed = [0,0,0,0,0]

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
   
    if isData:
        passData = hm.ApplyDataTreatment(fin,goodrunslist)
        if passData == -999: continue

    ##############################apply cuts if wanted
    #PassCutsOnElectrons(self,fin,vecindex,blayer,Pix,TrkIso,CaloIso,d0,typeisEM)

    #if not hm.PassD0SignificanceCuts(fin): continue
    #if not hm.PassCaloIsolationCuts(fin): continue
    #if not hm.PassTrackIsolationCuts(fin): continue	

   ##############################Fill histos
    
    numberevents_passed[4]+=1

    ##############################print event numbers

    if fin.EventNumber in debug_events:
       if (fin.RunNumber == debug_runs[debug_events.index(fin.EventNumber)]):
         print "Found debug event", fin.RunNumber, 'run' ,fin.EventNumber
         print 'quad type:', fin.quad_type
	 print 'm4l',round(fin.m_4l/1000.,2),'m12', round(fin.m_12/1000.,2),'m34',round(fin.m_34/1000.,2)
         print 'type:',fin.lepton_type[0],fin.lepton_type[1],fin.lepton_type[2],fin.lepton_type[3]
         print 'pt:',fin.lepton_pt[0],fin.lepton_pt[1],fin.lepton_pt[2],fin.lepton_pt[3]
         print 'trkiso:',fin.lepton_trk_iso20[0],fin.lepton_trk_iso20[1],fin.lepton_trk_iso20[2],fin.lepton_trk_iso20[3]
         print 'caloiso:',fin.lepton_calo_iso20[0],fin.lepton_calo_iso20[1],fin.lepton_calo_iso20[2],fin.lepton_calo_iso20[3]
         print 'd0 sig:',fin.lepton_d0_significance[0],fin.lepton_d0_significance[1],fin.lepton_d0_significance[2],fin.lepton_d0_significance[3]
       
    for itype in xrange(4):
        if fin.quad_type == itype:
            numberevents_passed[itype]+=1
            if printEventNumbers:
                print >>f_candidates[itype],str(fin.RunNumber).ljust(8)+" "+str(fin.EventNumber).ljust(12)+" "+str(fin.lbn).ljust(6)+" "+str(round(fin.m_4l/1000.,2)).ljust(8)+" "+str(round(fin.m_12/1000.,2)).ljust(8)+"\t"+str(round(fin.m_34/1000.,2)).ljust(8)
                #print >>f_candidates[itype],str(fin.EventNumber)
       


####################################PRINT

print input_dir
print 'initial number of events: '+str(hm.numberevents_all)
print 'after cutflow: '+str(numberevents_passed[4])
print '4mu: '+str(numberevents_passed[0])
print '4e: '+str(numberevents_passed[1])
print '2mu2e: '+str(numberevents_passed[2])
print '2e2mu: '+str(numberevents_passed[3])


####################################WRITE TO FILE

if printEventNumbers:
    for ifile in xrange(4):
        f_candidates[ifile].close()
        os.system("sort -k1,1n -k2,2n "+ name_files[ifile]+" > test.txt")
        os.system("mv test.txt "+ name_files[ifile])


#print "Closing output file: " + fileout.GetPath().rstrip(':/')
#fileout.Close()


