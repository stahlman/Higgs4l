#!/usr/bin/env python

__author__ = 'Heim Sarah'
__email__ = 'sheim@cern.ch'
__date__ = 'Sep 2012'

#---------------------------------------------------------------------------
print 'before import root stuff'
from ROOT import * 
print 'after import root stuff'
import os, sys, string, commands, math
from datetime import datetime
from pprint import pprint
import math
from array import array
import glob

from Histmaker_class import Histmaker
hm=Histmaker()
from Histfiller_class import Histfiller
hf=Histfiller()
from Categorization_class import Categorization
cat=Categorization()

if not len(sys.argv) >= 4:  raise(Exception, "Must specify inputdir, key and type as argument!")

input_dir = sys.argv[1]
input_key = sys.argv[2]
input_type = sys.argv[3]
output_dir = input_dir
filelist = 0
if(len(sys.argv) >= 5): filelist = sys.argv[4]
outputname = ''
if (len(sys.argv) >= 5): outputname = sys.argv[5]

doMCcorrection = 1
doFFMCCorrection = 1
lumi = 20.7

isData = 0
if input_type == "data" or input_type == "Data": isData = 1
if not isData: printEventNumbers = 0 #does not make sense for MC

####################################INITIALIZATION OF EXTERNAL TOOLS
if isData:
    goodrunslist = hm.LoadGRL('externals/GoodRunsLists/lists/data12_8TeV.periodAllYear_HEAD_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml')
else:
    crossSection = hm.LoadXSBkg()
    HiggsCrossSection = hm.LoadXSHiggs()	
    hm.LoadHiggsUtils()

####################################INPUTFILES
if filelist == 0: file_key = input_dir + '/*'+input_key+'*/Job*/*.root'
else: file_key = "isList"

tree_name = 'output'
fin = TChain(tree_name)
hm.GetFilesAndInitialCounts(fin,file_key,isData)
####################################COUNTERS

numberevents_all=0
numberevents_passed = [0,0,0,0,0]

####################################HISTOGRAMS

###make labels
varvec = ["E","all","!d0","!iso","!TRT","!ID"]
varvec_int = [Categorization.E,Categorization.all,Categorization.faild0,Categorization.failiso,Categorization.failTRT,Categorization.failID]
lenvarvec = len(varvec)

labels_reco_int = []
labels_reco = []
labels_reco.append("tot")
labels_reco_int.append(-1)

countbins_reco = 1

for i2 in xrange(lenvarvec):#EF
    labels_reco.append("E"+varvec[i2])
    labels_reco_int.append(Categorization.E*10+varvec_int[i2])
    countbins_reco = countbins_reco +1
for i1 in xrange(lenvarvec-1):#FE
    labels_reco.append(varvec[i1+1]+"E")
    labels_reco_int.append(varvec_int[i1+1]*10+Categorization.E)
    countbins_reco = countbins_reco +1
for i1 in xrange(lenvarvec-1):
    for i2 in xrange(lenvarvec-1):#FF
        if not (varvec_int[i1+1] == varvec_int[i2+1]): continue
        labels_reco.append(varvec[i1+1]+varvec[i2+1])
        labels_reco_int.append(varvec_int[i1+1]*10+varvec_int[i2+1])
        countbins_reco = countbins_reco +1

print labels_reco
print labels_reco_int

labels_truth_1_text = ["all","e","b","fsr","c","f","m"]
labels_truth_1_int = [9,1,2,3,4,5,6]
labels_truth_int = []
labels_truth = []
labels_truth.append("tot")
labels_truth_int.append(-1)

for i1 in xrange(len(labels_truth_1_int)):
     for i2 in xrange(len(labels_truth_1_int)):
         labels_truth.append(labels_truth_1_text[i1]+labels_truth_1_text[i2])
         labels_truth_int.append(labels_truth_1_int[i1]*10+labels_truth_1_int[i2])

print labels_truth
print labels_truth_int

typevec = ["4e","2mu2e"]
lentypevec = len(typevec)

denvec = ['noID','noIDTRT','noID!TRT','3.5','3.5TRT','3.5!TRT','ML','MLTRT','ML!TRT','MLrel','MLrelTRT','MLrel!TRT']
denvec_int = [Categorization.den_noID,Categorization.den_noIDTRT,Categorization.den_noIDfailTRT,Categorization.den_3_5,Categorization.den_3_5TRT,Categorization.den_3_5failTRT,Categorization.den_ML,Categorization.den_MLTRT,Categorization.den_MLfailTRT,Categorization.den_MLrel,Categorization.den_MLrelTRT,Categorization.den_MLrelfailTRT]
#denvec = ['noID','noIDTRT','noID!TRT','3.5','3.5TRT','3.5!TRT','ML','MLTRT','ML!TRT']
#denvec_int = [Categorization.den_noID,Categorization.den_noIDTRT,Categorization.den_noIDfailTRT,Categorization.den_3_5,Categorization.den_3_5TRT,Categorization.den_3_5failTRT,Categorization.den_ML,Categorization.den_MLTRT,Categorization.den_MLfailTRT]
lendenvec = len(denvec)

results_text = ["full","EF","FE","FF"]

etaarr = array('d',[0,1.37,1.52,2.47])
ptarr = array('d',[7,10,15,20,25,30,35])

#etaarr_1bin = array('d',[0,2.47])
#ptarr_1bin = array('d',[7,30])

###make hist

#multidimensional arrays
h_reco_categories_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]
h_reco_categories_overlap_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]
h_weighted_2e_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]
h_weighted_2mu_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]

h_results_2e_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]
h_results_2mu_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]
h_stats_2e_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]
h_stats_2mu_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]

h_categories_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]

h_etapt_1_ = [[[[] for ivar in range (lenvarvec)] for itype in range(lentypevec)] for iden in range(lendenvec)]
h_etapt_2_ = [[[[] for ivar in range (lenvarvec)] for itype in range(lentypevec)] for iden in range(lendenvec)]
h_etapt_bins_12_ = [[[[] for ivar in range (lenvarvec)] for itype in range(lentypevec)] for iden in range(lendenvec)]

for iden in xrange(lendenvec):
    for itype in xrange(lentypevec):
  
        h_test = TH1F('h_reco_categories_'+typevec[itype]+'_'+denvec[iden],'reco_categories_'+typevec[itype]+'_'+denvec[iden],countbins_reco,0,countbins_reco);
        for icat in xrange(countbins_reco):
            h_test.GetXaxis().SetBinLabel(icat+1,labels_reco[icat])
        h_reco_categories_[iden][itype] = h_test; hf.hists.append(h_test)

        h_test2D = TH2F('h_reco_categories_overlap_'+typevec[itype]+'_'+denvec[iden],'reco_categories_overlap_'+typevec[itype]+'_'+denvec[iden],countbins_reco,0,countbins_reco,countbins_reco,0,countbins_reco);
        for icat in xrange(countbins_reco):
            h_test2D.GetXaxis().SetBinLabel(icat+1,labels_reco[icat])
        for icat in xrange(countbins_reco):
            h_test2D.GetYaxis().SetBinLabel(icat+1,labels_reco[icat])
        h_reco_categories_overlap_[iden][itype]=h_test2D; hf.hists2D.append(h_test2D)

        h_test = TH1F('h_weighted_2e_'+typevec[itype]+'_'+denvec[iden],'weighted_2e_'+typevec[itype]+'_'+denvec[iden],countbins_reco,0,countbins_reco);
        for icat in xrange(countbins_reco):
            h_test.GetXaxis().SetBinLabel(icat+1,labels_reco[icat])
        h_weighted_2e_[iden][itype]=h_test; hf.hists.append(h_test)
        h_test = TH1F('h_weighted_2mu_'+typevec[itype]+'_'+denvec[iden],'weighted_2mu_'+typevec[itype]+'_'+denvec[iden],countbins_reco,0,countbins_reco);
        for icat in xrange(countbins_reco):
            h_test.GetXaxis().SetBinLabel(icat+1,labels_reco[icat])
        h_weighted_2mu_[iden][itype]=h_test; hf.hists.append(h_test)

        ###results histograms, 2D   
        n_res = len(results_text)
        
        h_test = TH2F('h_results_2e_'+typevec[itype]+'_'+denvec[iden],'results_2e_'+typevec[itype]+'_'+denvec[iden],lenvarvec,0,lenvarvec,n_res,0,n_res)
        for ivar in xrange(lenvarvec):
            h_test.GetXaxis().SetBinLabel(ivar+1,varvec[ivar])
        for ires in xrange(n_res):
            h_test.GetYaxis().SetBinLabel(ires+1,results_text[ires])
        h_results_2e_[iden][itype]=h_test; hf.hists.append(h_test)
        h_test = TH2F('h_results_2mu_'+typevec[itype]+'_'+denvec[iden],'results_2mu_'+typevec[itype]+'_'+denvec[iden],lenvarvec,0,lenvarvec,n_res,0,n_res)
        for ivar in xrange(lenvarvec):
            h_test.GetXaxis().SetBinLabel(ivar+1,varvec[ivar])
        for ires in xrange(n_res):
            h_test.GetYaxis().SetBinLabel(ires+1,results_text[ires])
        h_results_2mu_[iden][itype]=h_test; hf.hists.append(h_test)
        h_test = TH2F('h_stats_2e_'+typevec[itype]+'_'+denvec[iden],'stats_2e_'+typevec[itype]+'_'+denvec[iden],lenvarvec,0,lenvarvec,n_res,0,n_res)
        for ivar in xrange(lenvarvec):
            h_test.GetXaxis().SetBinLabel(ivar+1,varvec[ivar])
        for ires in xrange(n_res):
            h_test.GetYaxis().SetBinLabel(ires+1,results_text[ires])
        h_stats_2e_[iden][itype]=h_test; hf.hists.append(h_test)
        h_test = TH2F('h_stats_2mu_'+typevec[itype]+'_'+denvec[iden],'stats_2mu_'+typevec[itype]+'_'+denvec[iden],lenvarvec,0,lenvarvec,n_res,0,n_res)
        for ivar in xrange(lenvarvec):
            h_test.GetXaxis().SetBinLabel(ivar+1,varvec[ivar])
        for ires in xrange(n_res):
            h_test.GetYaxis().SetBinLabel(ires+1,results_text[ires])
        h_stats_2mu_[iden][itype]=h_test; hf.hists.append(h_test)

        ###yields in eta/pt bins
        for ivar in xrange(lenvarvec):
            h_test2D = TH2F('h_etapt_1_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar]+'E','etapt_1_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar]+'E',len(etaarr)-1,etaarr,len(ptarr)-1,ptarr)
            h_etapt_1_[iden][itype][ivar]=h_test2D;hf.hists2D.append(h_test2D)
            h_test2D = TH2F('h_etapt_2_'+typevec[itype]+'_'+denvec[iden]+'_E'+varvec[ivar],'etapt_2_'+typevec[itype]+'_'+denvec[iden]+'_E'+varvec[ivar],len(etaarr)-1,etaarr,len(ptarr)-1,ptarr)
            h_etapt_2_[iden][itype][ivar]=h_test2D;hf.hists2D.append(h_test2D)
            h_test2D = TH2F('h_etapt_bins_12_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar]+varvec[ivar],'etapt_bins_12_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar]+varvec[ivar],(len(etaarr)+2)*(len(ptarr)+2),0,(len(etaarr)+2)*(len(ptarr)+2),(len(etaarr)+2)*(len(ptarr)+2),0,(len(etaarr)+2)*(len(ptarr)+2))
            h_etapt_bins_12_[iden][itype][ivar]=h_test2D;hf.hists2D.append(h_test2D)

     


        ##truth 
        if not isData:
            h_test2D = TH2F('h_categories_'+typevec[itype]+'_'+denvec[iden],'categories_'+typevec[itype]+'_'+denvec[iden],countbins_reco,0,countbins_reco,len(labels_truth),0,len(labels_truth));
            for icat in xrange(countbins_reco):
                h_test2D.GetXaxis().SetBinLabel(icat+1,labels_reco[icat])
            for icat in xrange(len(labels_truth)):
                h_test2D.GetYaxis().SetBinLabel(icat+1,labels_truth[icat])
            h_categories_[iden][itype]=h_test2D;hf.hists2D.append(h_test2D)

hf.HistsSumw2()


#fileout = TFile(output_dir+"/"+input_key+"_passed.root",'RECREATE')
#hf.HistsWrite()
#fileout.Close()
#print "Closing output file: " + fileout.GetPath().rstrip(':/')
#exit(1)


#for weights and MC subtraction
MCfiles = []
FFMCfiles = []

#fileweight = TFile("/disk/userdata00/atlas_data2/sheim/output/01092013_X/Data_passed_02202013_incl.root",'READ')
fileweight = TFile("/disk/userdata00/atlas_data2/sheim/output/02262013_X/out_Data/Data_passed_02262013_pt.root",'READ')
if isData and doMCcorrection:
    fileZZ = TFile("/disk/userdata00/atlas_data2/sheim/output/02052013/ZZ_bkg_OS_passed.root","READ")
    MCfiles.append(fileZZ)
    fileWZ = TFile("/disk/userdata00/atlas_data2/sheim/output/02052013/WZ_bkg_OS_passed.root","READ")
    MCfiles.append(fileWZ)

if doFFMCCorrection:
    fileFFZZ = TFile("/disk/userdata00/atlas_data2/sheim/output/02262013_X/out_ZZ/ZZ_passed_02262013_pt.root","READ")
    FFMCfiles.append(fileFFZZ)
    fileFFWZ = TFile("/disk/userdata00/atlas_data2/sheim/output/02262013_X/out_WZ/WZ_passed_02262013_pt.root","READ")
    FFMCfiles.append(fileFFWZ)


weight_2e_1 = 1.
weight_2e_2 = 1.
weight_2mu_1 = 1.
weight_2mu_2 = 1.

#for fake factor correction
hist_2e_arr = [[[] for ivar in range (lenvarvec)] for iden in range(lendenvec)]
hist_2mu_arr = [[[] for ivar in range (lenvarvec)] for iden in range(lendenvec)]

for iden in xrange(lendenvec):
    for ivar in xrange(lenvarvec):
        hist_name = 'h_etapt_abs_2eX_'+denvec[iden]+'_'+varvec[ivar]
        hist_test = fileweight.Get(hist_name)
        if doFFMCCorrection:
            for ifile in xrange(len(FFMCfiles)):
                hist_test.Add(FFMCfiles[ifile].Get(hist_name),-1)
        hist_2e_arr[iden][ivar]=hist_test
        ##
        hist_name = 'h_etapt_abs_2muX_'+denvec[iden]+'_'+varvec[ivar]
        hist_test = fileweight.Get(hist_name)
        if doFFMCCorrection:
           for ifile in xrange(len(FFMCfiles)):
               hist_test.Add(FFMCfiles[ifile].Get(hist_name),-1)
        hist_2mu_arr[iden][ivar]=hist_test

#for MC correction of result
hist_MC_2e_results_arr = [[[[] for iMC in range (len(MCfiles))] for itype in range (lentypevec)] for iden in range(lendenvec)]
hist_MC_2mu_results_arr = [[[[] for iMC in range (len(MCfiles))] for itype in range (lentypevec)] for iden in range(lendenvec)]
hist_MC_2e_stats_arr = [[[[] for iMC in range (len(MCfiles))] for itype in range (lentypevec)] for iden in range(lendenvec)]
hist_MC_2mu_stats_arr = [[[[] for iMC in range (len(MCfiles))] for itype in range (lentypevec)] for iden in range(lendenvec)]

for iden in xrange(lendenvec):
    for itype in xrange(lentypevec):
        for iMC in xrange(len(MCfiles)):
            hist_name = 'h_results_2e_'+typevec[itype]+'_'+denvec[iden] 
            hist_MC_2e_results_arr[iden][itype][iMC]=MCfiles[iMC].Get(hist_name)
            #print 'pointer: '+str(hist_MC_2e_results_arr[iden][itype][iMC])
            hist_name = 'h_results_2mu_'+typevec[itype]+'_'+denvec[iden]
            hist_MC_2mu_results_arr[iden][itype][iMC]=MCfiles[iMC].Get(hist_name)
            hist_name = 'h_stats_2e_'+typevec[itype]+'_'+denvec[iden]
            hist_MC_2e_stats_arr[iden][itype][iMC]=MCfiles[iMC].Get(hist_name)
            hist_name = 'h_stats_2mu_'+typevec[itype]+'_'+denvec[iden]
            hist_MC_2mu_stats_arr[iden][itype][iMC]=MCfiles[iMC].Get(hist_name)   


####################################OUTPUT TEXT FILE

f_bkg_estimate = open(output_dir+"/"+input_key+"_bkg_estimate.txt", 'w')

####################################LOOP OVER EVENTS

nentries = fin.GetEntries()
#if nentries > 10000: nentries = 10000

if (nentries == 0):
  print "Found no events!  Aborting..."
  sys.exit()

for i in xrange(nentries):
    if not (fin.GetEntry(i)): continue
    if not i%10000: print 'Processing entry %d/%d'%(i,nentries)
 
    ##############################Apply cuts

    if abs(fin.lepton_type[3]) !=1: continue #only interested in 2X2e events

    #PassCutsOnElectrons(self,fin,vecindex,blayer,Pix,TrkIso,CaloIso,d0,typeisEM)
    if fin.lepton_pt[2]>fin.lepton_pt[3]:
        vecindex_sub1 = 2
        vecindex_sub2 = 3
    else:
        vecindex_sub1 = 3
        vecindex_sub2 = 2
    index_sub1 = fin.lepton_index[vecindex_sub1]
    index_sub2 = fin.lepton_index[vecindex_sub2]

    ##leading electrons
    if not hm.PassCutsOnElectrons(fin,0,1,1,1,1,1,"ML"): continue
    if not hm.PassCutsOnElectrons(fin,1,1,1,1,1,1,"ML"): continue
   
    ##leading muons
    if not hm.PassD0SignificanceCuts(fin,"FirstPair"): continue
    if not hm.PassCaloIsolationCuts(fin,"FirstPair"): continue
    if not hm.PassTrackIsolationCuts(fin,"FirstPair"): continue     

    ###apply other cuts if you want
    #start with m34 cut to reject ZZ        
    #if fin.m_34 > 70000 and fin.m_34 < 110000: continue      

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

    ################################Categories

    cat.Cat_Jets(vecindex_sub1,fin,0)
    list_1=list(cat.list)
    cat.Cat_Jets(vecindex_sub2,fin,0)
    list_2=list(cat.list)

    #print 'list1:'
    #print list_1
    #print 'list2'
    #print list_2

    ##get eta/pt
    pt1 = fin.lepton_pt[vecindex_sub1]/1000.
    eta1 = fin.lepton_eta[vecindex_sub1]
    pt2 = fin.lepton_pt[vecindex_sub2]/1000.
    eta2 = fin.lepton_eta[vecindex_sub2]

    if pt1 >=35: pt1 = 34
    if pt2 >= 35: pt2 = 34

    eta1 = abs(eta1)
    eta2 = abs(eta2)

    bin1 = hist_2e_arr[0][0].FindBin(eta1,pt1)
    bin2 = hist_2e_arr[0][0].FindBin(eta2,pt2)

    truth_cat1 = 0
    truth_cat2 = 0

    ##loop over denominators and types
    for iden in xrange(len(denvec)):

        for itype in xrange(lentypevec):
           if fin.quad_type != itype+1: continue #4mu:0,4e:1,2mu2e:2
     
           ######Fill histos
           #0 bin
           h_reco_categories_[iden][itype].Fill(0, event_weight) #all
           h_reco_categories_overlap_[iden][itype].Fill(0,0,event_weight) #all

           #other bins
           for ibin in xrange(len(labels_reco_int)-1):
              for ivar1 in xrange(lenvarvec):
                  for ivar2 in xrange(lenvarvec):
                       if (varvec_int[ivar1]*list_1[varvec_int[ivar1]]*10+varvec_int[ivar2]*list_2[varvec_int[ivar2]]) == labels_reco_int[ibin+1]:


                           ###den/categorization cuts only on fakes, not on real electrons
                           ###if this is too slow, need to think where else one could do it
                           if varvec_int[ivar1] != Categorization.E:
                              if not list_1[Categorization.Blayer]: continue
                              if denvec_int[iden]==Categorization.den_noIDTRT:
                                 if not list_1[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_noIDfailTRT:
                                 if list_1[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_3_5:
                                 if not (list_1[Categorization.pass3_5LooseLikelihood] or list_1[Categorization.ML]): continue
                              elif denvec_int[iden]==Categorization.den_3_5TRT:
                                 if not (list_1[Categorization.pass3_5LooseLikelihood] or list_1[Categorization.ML]): continue
                                 if not list_1[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_3_5failTRT:
                                 if not (list_1[Categorization.pass3_5LooseLikelihood] or list_1[Categorization.ML]): continue
                                 if list_1[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_ML:
                                 if not list_1[Categorization.ML]: continue
                              elif denvec_int[iden]==Categorization.den_MLTRT:
                                 if not list_1[Categorization.ML]: continue
                                 if not list_1[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_MLfailTRT:
                                 if not list_1[Categorization.ML]: continue
                                 if list_1[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_MLrel:
                                 if not list_1[Categorization.MLrel]: continue
                              elif denvec_int[iden]==Categorization.den_MLrelTRT:
                                 if not list_1[Categorization.MLrel]: continue
                                 if not list_1[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_MLrelfailTRT:
                                 if not list_1[Categorization.MLrel]: continue
                                 if list_1[Categorization.TRT]: continue

                           if varvec_int[ivar2] != Categorization.E:
                              if not list_2[Categorization.Blayer]: continue
                              if denvec_int[iden]==Categorization.den_noIDTRT:
                                 if not list_2[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_noIDfailTRT:
                                 if list_2[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_3_5:
                                 if not (list_2[Categorization.pass3_5LooseLikelihood] or list_2[Categorization.ML]): continue
                              elif denvec_int[iden]==Categorization.den_3_5TRT:
                                 if not (list_2[Categorization.pass3_5LooseLikelihood] or list_2[Categorization.ML]): continue
                                 if not list_2[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_3_5failTRT:
                                 if not (list_2[Categorization.pass3_5LooseLikelihood] or list_2[Categorization.ML]): continue
                                 if list_2[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_ML:
                                 if not list_2[Categorization.ML]: continue
                              elif denvec_int[iden]==Categorization.den_MLTRT:
                                 if not list_2[Categorization.ML]: continue
                                 if not list_2[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_MLfailTRT:
                                 if not list_2[Categorization.ML]: continue
                                 if list_2[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_MLrel:
                                 if not list_2[Categorization.MLrel]: continue
                              elif denvec_int[iden]==Categorization.den_MLrelTRT:
                                 if not list_2[Categorization.MLrel]: continue
                                 if not list_2[Categorization.TRT]: continue
                              elif denvec_int[iden]==Categorization.den_MLrelfailTRT:
                                 if not list_2[Categorization.MLrel]: continue
                                 if list_2[Categorization.TRT]: continue

                           h_reco_categories_[iden][itype].Fill(ibin+1, event_weight)

	                   ##overlap histo
                           for jbin in xrange(len(labels_reco_int)-1):
                               for jvar1 in xrange(lenvarvec):
		                   for jvar2 in xrange(lenvarvec):
                                       if (varvec_int[jvar1]*list_1[varvec_int[jvar1]]*10+varvec_int[jvar2]*list_2[varvec_int[jvar2]]) == labels_reco_int[jbin+1]:
                                           h_reco_categories_overlap_[iden][itype].Fill(ibin+1, jbin+1,event_weight)
                           


                           ##weights (can be commented out)
                           #needs adjustments for categorization of F
                           hist_2e_num = hist_2e_arr[iden][0]
                           hist_2e_den_1 = hist_2e_arr[iden][ivar1]
                           hist_2e_den_2 = hist_2e_arr[iden][ivar2]
                           hist_2mu_num = hist_2mu_arr[iden][0]
                           hist_2mu_den_1 = hist_2mu_arr[iden][ivar1]
                           hist_2mu_den_2 = hist_2mu_arr[iden][ivar2]                      
                        
                           if hist_2e_den_1.GetBinContent(bin1) != 0: weight_2e_1 = float(hist_2e_num.GetBinContent(bin1))/(hist_2e_den_1.GetBinContent(bin1))
                           else: weight_2e_1 = 0
                           if hist_2e_den_2.GetBinContent(bin2) != 0: weight_2e_2 = float(hist_2e_num.GetBinContent(bin2))/(hist_2e_den_2.GetBinContent(bin2))
                           else: weight_2e_2 = 0
                           if hist_2mu_den_1.GetBinContent(bin1) != 0: weight_2mu_1 = float(hist_2mu_num.GetBinContent(bin1))/(hist_2mu_den_1.GetBinContent(bin1))
                           else: weight_2mu_1 = 0
                           if hist_2mu_den_2.GetBinContent(bin2) != 0: weight_2mu_2 = float(hist_2mu_num.GetBinContent(bin2))/(hist_2mu_den_2.GetBinContent(bin2))
                           else: weight_2mu_2 = 0                       

                           if varvec_int[ivar1] == Categorization.E: 
                              weight_2e_1 = 1
                              weight_2mu_1 = 1
                           if varvec_int[ivar2] == Categorization.E: 
                              weight_2e_2 = 1
                              weight_2mu_2 = 1

                           h_weighted_2e_[iden][itype].Fill(ibin+1, event_weight*weight_2e_1*weight_2e_2)
                           h_weighted_2mu_[iden][itype].Fill(ibin+1, event_weight*weight_2mu_1*weight_2mu_2)

                           #Fill 2D histograms
                           #FE
                           if varvec_int[ivar1] != Categorization.E and varvec_int[ivar2] == Categorization.E: 
                               h_etapt_1_[iden][itype][ivar1].Fill(eta1,pt1,event_weight)
                           #EF
                           elif varvec_int[ivar1] == Categorization.E and varvec_int[ivar2] != Categorization.E: 
                               h_etapt_2_[iden][itype][ivar2].Fill(eta2,pt2,event_weight) 
                           #FF
                           elif varvec_int[ivar1] != Categorization.E and varvec_int[ivar2] != Categorization.E: 
                              h_etapt_bins_12_[iden][itype][ivar1].Fill(bin1,bin2,event_weight)

                           if not isData:
                                 
                              h_categories_[iden][itype].Fill(0,0,event_weight) ##all
                              truth_cat1 = ElectronTruth.getMCClassification(fin.el_type[index_sub1],fin.el_origin[index_sub1],fin.el_typebkg[index_sub1],fin.el_originbkg[index_sub1])
                              truth_cat2 = ElectronTruth.getMCClassification(fin.el_type[index_sub2],fin.el_origin[index_sub2],fin.el_typebkg[index_sub2],fin.el_originbkg[index_sub2])
                              if truth_cat1 == 7: truth_cat1 = 5
                              if truth_cat2 == 7: truth_cat2 = 5
                              for ibin_truth in xrange(len(labels_truth_int)):
                                 if truth_cat1*10+truth_cat2 == labels_truth_int[ibin_truth]:
                                    h_categories_[iden][itype].Fill(0,ibin_truth,event_weight)

                              h_categories_[iden][itype].Fill(ibin+1, 0, event_weight)
                              for ibin_truth in xrange(len(labels_truth_int)):
                                  if truth_cat1*10+truth_cat2 == labels_truth_int[ibin_truth]:
                                      h_categories_[iden][itype].Fill(ibin+1,ibin_truth,event_weight)




####################################PRINT

print input_dir
print 'initial number of events: '+str(hm.numberevents_all)


####################################WRITE TO FILE


##write background estimate to file
#4 cases: 2mu2X, 2e2X * 2muX, 2eX
#for itype in [1,2]:
#h_weighted_2e_[itype]
#h_weighted_2mu_[itype]
#different variables

EF=0
FE=0
FF=0
EF_label=''
FE_label=''
FF_label=''

for itype in xrange(lentypevec):
    print >>f_bkg_estimate,'**************************** '+typevec[itype]

    for ivar in xrange(lenvarvec):
        if ivar == 0: continue ###E
        print >>f_bkg_estimate,'*********** '+varvec[ivar]

        for ibin in xrange(h_weighted_2e_[0][0].GetNbinsX()+1):
           if h_weighted_2e_[0][0].GetXaxis().GetBinLabel(ibin) == ("E"+varvec[ivar]): EF=ibin
           elif h_weighted_2e_[0][0].GetXaxis().GetBinLabel(ibin) == (varvec[ivar]+"E"): FE=ibin
           elif h_weighted_2e_[0][0].GetXaxis().GetBinLabel(ibin) == (varvec[ivar]+varvec[ivar]):
               FF=ibin
               #print 'FF, ivar: '+str(ivar)+', ibin: '+str(ibin)+', label: '+h_weighted_2e_[0][0].GetXaxis().GetBinLabel(ibin)
           EF_label = h_weighted_2e_[0][0].GetXaxis().GetBinLabel(EF)
           FE_label = h_weighted_2e_[0][0].GetXaxis().GetBinLabel(FE)
           FF_label = h_weighted_2e_[0][0].GetXaxis().GetBinLabel(FF)

        for iden in xrange(lendenvec):
           print >>f_bkg_estimate,'**** '+denvec[iden]

           ##first the weighted ones (can be commented out)
           EF_2e_weighted = h_weighted_2e_[iden][itype].GetBinContent(EF)
           FE_2e_weighted = h_weighted_2e_[iden][itype].GetBinContent(FE)
           FF_2e_weighted = h_weighted_2e_[iden][itype].GetBinContent(FF)
           EF_2mu_weighted = h_weighted_2mu_[iden][itype].GetBinContent(EF)
           FE_2mu_weighted = h_weighted_2mu_[iden][itype].GetBinContent(FE)
           FF_2mu_weighted = h_weighted_2mu_[iden][itype].GetBinContent(FF)
         
           stats_EF_2e_weighted = h_weighted_2e_[iden][itype].GetBinError(EF)
           stats_FE_2e_weighted = h_weighted_2e_[iden][itype].GetBinError(FE)
           stats_FF_2e_weighted = h_weighted_2e_[iden][itype].GetBinError(FF)
           stats_EF_2mu_weighted = h_weighted_2mu_[iden][itype].GetBinError(EF)
           stats_FE_2mu_weighted = h_weighted_2mu_[iden][itype].GetBinError(FE)
           stats_FF_2mu_weighted = h_weighted_2mu_[iden][itype].GetBinError(FF)
           ###

           #EF and FE
           hist_yield_EF = h_etapt_2_[iden][itype][ivar]
           hist_yield_FE = h_etapt_1_[iden][itype][ivar]
           hist_yield_FF = h_etapt_bins_12_[iden][itype][ivar]

           hist_2e_num = hist_2e_arr[iden][0]
           hist_2e_den = hist_2e_arr[iden][ivar]
           hist_2mu_num = hist_2mu_arr[iden][0]
           hist_2mu_den = hist_2mu_arr[iden][ivar]

           result_2e_EF = 0
           result_2e_FE = 0
           result_2e_FF = 0
           result_2mu_EF = 0
           result_2mu_FE = 0
           result_2mu_FF = 0

           stats_2e_EF = 0
           stats_2e_FE = 0
           stats_2e_FF = 0
           stats_2mu_EF = 0
           stats_2mu_FE = 0
           stats_2mu_FF = 0

           #to make sure we are consistent
           #print 'EF: '+hist_yield_EF.GetName()+', label: '+EF_label+', ff, num: '+hist_2e_num.GetName()+', ff, den: '+hist_2e_den.GetName()
           #print 'FE: '+hist_yield_FE.GetName()+', label: '+FE_label
           #print 'FF: '+hist_yield_FF.GetName()+', label: '+FF_label

           for ibin in xrange(50): ##...from 5*6 histogram + overflow, must be updated if eta/pt binning changes
           
               if hist_2e_den.GetBinContent(ibin) != 0: 
                   weight_2e_1 = float(hist_2e_num.GetBinContent(ibin))/(hist_2e_den.GetBinContent(ibin))
                   delta_weight_2e_1 = sqrt(hist_2e_num.GetBinContent(ibin)/(hist_2e_den.GetBinContent(ibin))**2 + (hist_2e_num.GetBinContent(ibin))**2/(hist_2e_den.GetBinContent(ibin))**3)
               else: 
                   weight_2e_1 = 0
                   delta_weight_2e_1 = 0
               if hist_2mu_den.GetBinContent(ibin) != 0: 
                   weight_2mu_1 = float(hist_2mu_num.GetBinContent(ibin))/(hist_2mu_den.GetBinContent(ibin))
                   delta_weight_2mu_1 = sqrt((hist_2mu_num.GetBinContent(ibin))/(hist_2mu_den.GetBinContent(ibin))**2 + (hist_2mu_num.GetBinContent(ibin))**2/(hist_2mu_den.GetBinContent(ibin))**3)
               else: 
                   weight_2mu_1 = 0
                   delta_weight_2mu_1 = 0


               result_2e_EF = result_2e_EF+(hist_yield_EF.GetBinContent(ibin)*weight_2e_1)
               stats_2e_EF = stats_2e_EF+(hist_yield_EF.GetBinContent(ibin)*delta_weight_2e_1)**2+(hist_yield_EF.GetBinError(ibin)*weight_2e_1)**2
               result_2mu_EF = result_2mu_EF+(hist_yield_EF.GetBinContent(ibin)*weight_2mu_1)
               stats_2mu_EF = stats_2mu_EF+(hist_yield_EF.GetBinContent(ibin)*delta_weight_2mu_1)**2+(hist_yield_EF.GetBinError(ibin)*weight_2mu_1)**2
               result_2e_FE = result_2e_FE+(hist_yield_FE.GetBinContent(ibin)*weight_2e_1)
               stats_2e_FE = stats_2e_FE+(hist_yield_FE.GetBinContent(ibin)*delta_weight_2e_1)**2+(hist_yield_FE.GetBinError(ibin)*weight_2e_1)**2
               result_2mu_FE = result_2mu_FE+(hist_yield_FE.GetBinContent(ibin)*weight_2mu_1) 
               stats_2mu_FE = stats_2mu_FE+(hist_yield_FE.GetBinContent(ibin)*delta_weight_2mu_1)**2+(hist_yield_FE.GetBinError(ibin)*weight_2mu_1)**2

               #print 'itype: '+str(itype)+', iden: '+str(iden)+', ivar: '+str(ivar)+'ibin: '+str(ibin)+', hist_yield_EF.GetBinContent(ibin): '+str(hist_yield_EF.GetBinContent(ibin))+', weight_2e_1: '+str(weight_2e_1)

               ##FF
               for ibin2 in xrange(50):

                   if hist_2e_den.GetBinContent(ibin2) != 0: 
                      weight_2e_2 = float(hist_2e_num.GetBinContent(ibin2))/(hist_2e_den.GetBinContent(ibin2))
                      delta_weight_2e_2 = sqrt((hist_2e_num.GetBinContent(ibin2))/(hist_2e_den.GetBinContent(ibin2))**2 + (hist_2e_num.GetBinContent(ibin2))**2/(hist_2e_den.GetBinContent(ibin2))**3)
                   else: 
                      weight_2e_2 = 0
                      delta_weight_2e_2 = 0
                   if hist_2mu_den.GetBinContent(ibin2) != 0: 
                      weight_2mu_2 = float(hist_2mu_num.GetBinContent(ibin2))/(hist_2mu_den.GetBinContent(ibin2))
                      delta_weight_2mu_2 = sqrt((hist_2mu_num.GetBinContent(ibin2))/(hist_2mu_den.GetBinContent(ibin2))**2 + (hist_2mu_num.GetBinContent(ibin2))**2/(hist_2mu_den.GetBinContent(ibin2))**3)
                   else: 
                      weight_2mu_2 = 0
                      delta_weight_2mu_2 = 0 

                   result_2e_FF = result_2e_FF+(hist_yield_FF.GetBinContent(ibin+1,ibin2+1)*weight_2e_1*weight_2e_2)
                   stats_2e_FF = stats_2e_FF + (hist_yield_FF.GetBinContent(ibin+1,ibin2+1)*weight_2e_1*delta_weight_2e_2)**2+(hist_yield_FF.GetBinContent(ibin+1,ibin2+1)*weight_2e_2*delta_weight_2e_1)**2+(weight_2e_1*weight_2e_2*hist_yield_FF.GetBinError(ibin+1,ibin2+1))**2

                   result_2mu_FF = result_2mu_FF+(hist_yield_FF.GetBinContent(ibin+1,ibin2+1)*weight_2mu_1*weight_2mu_2)
                   stats_2mu_FF = stats_2mu_FF + (hist_yield_FF.GetBinContent(ibin+1,ibin2+1)*weight_2mu_1*delta_weight_2mu_2)**2+(hist_yield_FF.GetBinContent(ibin+1,ibin2+1)*weight_2mu_2*delta_weight_2mu_1)**2+(weight_2mu_1*weight_2mu_2*hist_yield_FF.GetBinError(ibin+1,ibin2+1))**2


           stats_2e_EF = sqrt(stats_2e_EF)
           stats_2mu_EF = sqrt(stats_2mu_EF)
           stats_2e_FE = sqrt(stats_2e_FE)
           stats_2mu_FE = sqrt(stats_2mu_FE)
           stats_2e_FF = sqrt(stats_2e_FF)
           stats_2mu_FF = sqrt(stats_2mu_FF)

           results_2e_all = result_2e_EF+result_2e_FE-result_2e_FF
           results_2mu_all = result_2mu_EF+result_2mu_FE-result_2mu_FF
           stats_2e_all = sqrt((stats_2e_EF)**2+(stats_2e_FE)**2+(stats_2e_FF)**2)
           stats_2mu_all = sqrt((stats_2mu_EF)**2+(stats_2mu_FE)**2+(stats_2mu_FF)**2)

           results_2e_weighted_all = EF_2e_weighted + FE_2e_weighted - FF_2e_weighted  
           results_2mu_weighted_all = EF_2mu_weighted + FE_2mu_weighted - FF_2mu_weighted
           stats_2e_weighted_all = sqrt((EF_2e_weighted)**2 + (FE_2e_weighted)**2 + (FF_2e_weighted)**2)
           stats_2mu_weighted_all = sqrt((EF_2mu_weighted)**2 + (FE_2mu_weighted)**2 + (FF_2mu_weighted)**2)

           results_2e_arr = [results_2e_all,result_2e_EF,result_2e_FE,result_2e_FF]
           stats_2e_arr = [stats_2e_all,stats_2e_EF,stats_2e_FE,stats_2e_FF]
           results_2mu_arr = [results_2mu_all,result_2mu_EF,result_2mu_FE,result_2mu_FF]
           stats_2mu_arr = [stats_2mu_all,stats_2mu_EF,stats_2mu_FE,stats_2mu_FF]

           results_2e_weighted_arr = [results_2e_weighted_all,EF_2e_weighted,FE_2e_weighted,FF_2e_weighted]
           results_2mu_weighted_arr = [results_2mu_weighted_all,EF_2mu_weighted,FE_2mu_weighted,FF_2mu_weighted]
           stats_2e_weighted_arr = [stats_2e_weighted_all,stats_EF_2e_weighted,stats_FE_2e_weighted,stats_FF_2e_weighted]
           stats_2mu_weighted_arr = [stats_2mu_weighted_all,stats_EF_2mu_weighted,stats_FE_2mu_weighted,stats_FF_2mu_weighted]

           if isData and doMCcorrection:
              #print 'in here: '
              #subtract MC results from external root files
              for iMC in xrange(len(MCfiles)):
                  for ires in  xrange(len(results_2e_arr)):     
                      results_2e_arr[ires] = results_2e_arr[ires] - hist_MC_2e_results_arr[iden][itype][iMC].GetBinContent(ivar+1,ires+1)
                      results_2mu_arr[ires] = results_2mu_arr[ires] - hist_MC_2mu_results_arr[iden][itype][iMC].GetBinContent(ivar+1,ires+1)
                      stats_2e_arr[ires] = sqrt(stats_2e_arr[ires]**2 + (hist_MC_2e_stats_arr[iden][itype][iMC].GetBinContent(ivar+1,ires+1))**2)
                      stats_2mu_arr[ires] = sqrt(stats_2mu_arr[ires]**2 + (hist_MC_2e_stats_arr[iden][itype][iMC].GetBinContent(ivar+1,ires+1))**2)
                      results_2e_weighted_arr[ires] = results_2e_weighted_arr[ires] - hist_MC_2e_results_arr[iden][itype][iMC].GetBinContent(ivar+1,ires+1)
                      results_2mu_weighted_arr[ires] = results_2mu_weighted_arr[ires] - hist_MC_2mu_results_arr[iden][itype][iMC].GetBinContent(ivar+1,ires+1)
                      stats_2e_weighted_arr[ires] = sqrt(stats_2e_weighted_arr[ires]**2 + (hist_MC_2e_stats_arr[iden][itype][iMC].GetBinContent(ivar+1,ires+1))**2)
                      stats_2mu_weighted_arr[ires] = sqrt(stats_2mu_weighted_arr[ires]**2 + (hist_MC_2e_stats_arr[iden][itype][iMC].GetBinContent(ivar+1,ires+1))**2)


           #fill result histogram with array content           
           for ires in xrange(len(results_2e_arr)):     
                   h_results_2e_[iden][itype].SetBinContent(ivar+1,ires+1,results_2e_arr[ires])
                   h_results_2mu_[iden][itype].SetBinContent(ivar+1,ires+1,results_2mu_arr[ires])
                   h_stats_2e_[iden][itype].SetBinContent(ivar+1,ires+1,stats_2e_arr[ires])
                   h_stats_2mu_[iden][itype].SetBinContent(ivar+1,ires+1,stats_2mu_arr[ires])
 
           print >>f_bkg_estimate,'*from 2D* fake factor from 2e  --- '+EF_label.ljust(10)+' : '+str("%.2f" % results_2e_arr[1]).ljust(8)+' +/- '+str("%.2f" % stats_2e_arr[1]).ljust(5)+FE_label.ljust(10)+' : '+str("%.2f" % results_2e_arr[2]).ljust(8)+'+/-'+str("%.2f" % stats_2e_arr[2]).ljust(5)+FF_label.ljust(16)+' : '+str("%.2f" % results_2e_arr[3])+' +/- '+str("%.2f" % stats_2e_arr[3]).ljust(5)+' , final estimate EF+FE-FF: '+str("%.2f" % (results_2e_arr[0]))+'+/-'+str("%.2f" % stats_2e_arr[0])
           print >>f_bkg_estimate,'*from 2D* fake factor from 2mu --- '+EF_label.ljust(8)+' : '+str("%.2f" % results_2mu_arr[1]).ljust(8)+' +/- '+str("%.2f" % stats_2mu_arr[1]).ljust(5)+FE_label.ljust(8)+' : '+str("%.2f" % results_2mu_arr[2]).ljust(8)+'+/-'+str("%.2f" % stats_2mu_arr[2]).ljust(5)+FF_label.ljust(16)+' : '+str("%.2f" % results_2mu_arr[3])+' +/- '+str("%.2f" % stats_2mu_arr[3]).ljust(5)+' , final estimate EF+FE-FF: '+str("%.2f" % (results_2mu_arr[0]))+'+/-'+str("%.2f" % stats_2mu_arr[0])
       
           print >>f_bkg_estimate,'*from weight* fake factor from 2e  --- '+EF_label.ljust(10)+' : '+str("%.2f" % results_2e_weighted_arr[1]).ljust(8)+' +/- '+str("%.2f" % stats_2e_weighted_arr[1]).ljust(5)+FE_label.ljust(10)+' : '+str("%.2f" % results_2e_weighted_arr[2]).ljust(8)+'+/-'+str("%.2f" % stats_2e_weighted_arr[2]).ljust(5)+FF_label.ljust(16)+' : '+str("%.2f" % results_2e_weighted_arr[3])+' +/- '+str("%.2f" % stats_2e_weighted_arr[3]).ljust(5)+' , final estimate EF+FE-FF: '+str("%.2f" % (results_2e_weighted_arr[0]))+'+/-'+str("%.2f" % stats_2e_weighted_arr[0])
           print >>f_bkg_estimate,'*from weight* fake factor from 2mu  --- '+EF_label.ljust(10)+' : '+str("%.2f" % results_2mu_weighted_arr[1]).ljust(8)+' +/- '+str("%.2f" % stats_2mu_weighted_arr[1]).ljust(5)+FE_label.ljust(10)+' : '+str("%.2f" % results_2mu_weighted_arr[2]).ljust(8)+'+/-'+str("%.2f" % stats_2mu_weighted_arr[2]).ljust(5)+FF_label.ljust(16)+' : '+str("%.2f" % results_2mu_weighted_arr[3])+' +/- '+str("%.2f" % stats_2mu_weighted_arr[3]).ljust(5)+' , final estimate EF+FE-FF: '+str("%.2f" % (results_2mu_weighted_arr[0]))+'+/-'+str("%.2f" % stats_2mu_weighted_arr[0])

 
           print >>f_bkg_estimate,'---'

if outputname == '': fileout = TFile(output_dir+"/"+input_key+"_passed.root",'RECREATE')
else: fileout = TFile(outputname,'RECREATE')




hf.HistsWrite()
fileout.Close()
print "Closing output file: " + fileout.GetPath().rstrip(':/')
print "Textfile: "+output_dir+"/"+input_key+"_bkg_estimate.txt"



