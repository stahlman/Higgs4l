#!/usr/bin/env python

__author__ = 'Heim Sarah'
__email__ = 'sheim@cern.ch'
__date__ = 'Dec 2012'

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
from time import clock, time

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
filelist = ''
if(len(sys.argv) >= 5): filelist = sys.argv[4]
outputname = ''
if (len(sys.argv) >= 5): outputname = sys.argv[5]


#if (len(sys.argv) == 5):
#  output_dir = sys.argv[4]
#if (len(sys.argv) == 5):
#  var = int(sys.argv[4])
#  add_name = str(var)
add_name = ""

printEventNumbers = 0
lumi = 20.7
#lumi = 13


isData = 0
if input_type == "data" or input_type == "Data": isData = 1
if not isData: printEventNumbers = 0 #does not make sense for MC

doWeightPt = 1
if isData: doWeightPt = 0 #does not make sense for data

####################################INITIALIZATION OF EXTERNAL TOOLS
if isData:
    #goodrunslist = hm.LoadGRL('externals/GoodRunsLists/lists/data12_8TeV.periodAllYear_DetStatus-v54-pro13-04_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml')
    goodrunslist = hm.LoadGRL('externals/GoodRunsLists/lists/data12_8TeV.periodAllYear_HEAD_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml')
else:
    crossSection = hm.LoadXSBkg()
    HiggsCrossSection = hm.LoadXSHiggs()	
    hm.LoadHiggsUtils()

####################################INPUTFILES
if filelist == '': file_key = input_dir + '/*'+input_key+'*/Job*/*.root'
else: file_key = "isList"

tree_name = 'output'
fin = TChain(tree_name)
hm.GetFilesAndInitialCounts(fin,file_key,isData,filelist)

####################################COUNTERS

numberevents_all=0
numberevents_passed = [0,0,0,0,0]

####################################HISTOGRAMS
#all -- 0
#E -- 1
#!d0 -- 2                                       
#!iso -- 3
#!TRT -- 4
#TRT -- 5
#!ID -- 6
#Blayer -- 7
#ML -- 8
#VeryLooseLikelihood -- 9
#LooseLikelihood -- 10
#3_5LooseLikelihood --11

###make labels
varvec = ["E","all","!d0","!iso","!TRT","!ID"]
varvec_int = [Categorization.E,Categorization.all,Categorization.faild0,Categorization.failiso,Categorization.failTRT,Categorization.failID]
lenvarvec = len(varvec)	 

labels_truth = ["all","e","b","fsr","c","f","m"]
labels_truth_int = [9,1,2,3,4,5,6]

typevec = ["2eX","2muX"]
lentypevec = len(typevec)

denvec = ['noID','noIDTRT','noID!TRT','3.5','3.5TRT','3.5!TRT','ML','MLTRT','ML!TRT','MLrel','MLrelTRT','MLrel!TRT']
denvec_int = [Categorization.den_noID,Categorization.den_noIDTRT,Categorization.den_noIDfailTRT,Categorization.den_3_5,Categorization.den_3_5TRT,Categorization.den_3_5failTRT,Categorization.den_ML,Categorization.den_MLTRT,Categorization.den_MLfailTRT,Categorization.den_MLrel,Categorization.den_MLrelTRT,Categorization.den_MLrelfailTRT]
lendenvec = len(denvec)

etaarr = array('d',[-2.47,-1.52,-1.37,0,1.37,1.52,2.47])
ptarr = array('d',[7,10,15,20,25,30,35])

etaarr_abs = array('d',[0,1.37,1.52,2.47])

etaarr_1bin = array('d',[0,2.5])
ptarr_1bin = array('d',[0,35])

###make hist

#multidimensional arrays
h_reco_categories_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)] 
h_categories_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)] 
h_categories_weighted_X1_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]
h_categories_weighted_X2_ = [[[] for itype in range (lentypevec)] for iden in range(lendenvec)]
h_etapt_ = [[[[] for ivar in range (lenvarvec)] for itype in range(lentypevec)] for iden in range(lendenvec)]
h_etapt_abs_ = [[[[] for ivar in range (lenvarvec)] for itype in range(lentypevec)] for iden in range(lendenvec)]
h_etapt_1bin_ = [[[[] for ivar in range (lenvarvec)] for itype in range(lentypevec)] for iden in range(lendenvec)]
h_eta_ = [[[[] for ivar in range (lenvarvec)] for itype in range(lentypevec)] for iden in range(lendenvec)]
h_pt_ = [[[[] for ivar in range (lenvarvec)] for itype in range(lentypevec)] for iden in range(lendenvec)]

for iden in xrange(lendenvec):
    for itype in xrange(2):
        h_test = TH1F('h_reco_categories_'+typevec[itype]+'_'+denvec[iden],'reco_categories_'+typevec[itype]+'_'+denvec[iden],lenvarvec,0,lenvarvec);
        for ivar in xrange(lenvarvec):
            h_test.GetXaxis().SetBinLabel(ivar+1,varvec[ivar])
        h_reco_categories_[iden][itype] = h_test; hf.hists.append(h_test)

        for ivar in xrange(lenvarvec):
            h_test2D = TH2F('h_etapt_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],'etapt_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],len(etaarr)-1,etaarr,len(ptarr)-1,ptarr)
            h_etapt_[iden][itype][ivar] = h_test2D;hf.hists2D.append(h_test2D)
            h_test2D = TH2F('h_etapt_abs_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],'etapt_abs_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],len(etaarr_abs)-1,etaarr_abs,len(ptarr)-1,ptarr)
            h_etapt_abs_[iden][itype][ivar]= h_test2D;hf.hists2D.append(h_test2D)
            h_test2D = TH2F('h_etapt_1bin_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],'etapt_1bin_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],len(etaarr_1bin)-1,etaarr_1bin,len(ptarr_1bin)-1,ptarr_1bin)
            h_etapt_1bin_[iden][itype][ivar]=h_test2D;hf.hists2D.append(h_test2D)
            h_test2D = TH2F('h_eta_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],'eta_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],len(etaarr_abs)-1,etaarr_abs,len(ptarr_1bin)-1,ptarr_1bin)
            h_eta_[iden][itype][ivar]=h_test2D;hf.hists2D.append(h_test2D)
            h_test2D = TH2F('h_pt_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],'pt_'+typevec[itype]+'_'+denvec[iden]+'_'+varvec[ivar],len(etaarr_1bin)-1,etaarr_1bin,len(ptarr)-1,ptarr)
            h_pt_[iden][itype][ivar]=h_test2D;hf.hists2D.append(h_test2D)

        if not isData:
            h_test2D = TH2F('h_categories_'+typevec[itype]+'_'+denvec[iden],'categories_'+typevec[itype]+'_'+denvec[iden],lenvarvec,0,lenvarvec,len(labels_truth),0,len(labels_truth));
            for ivar in xrange(lenvarvec):
                h_test2D.GetXaxis().SetBinLabel(ivar+1,varvec[ivar])
            for ivar in xrange(len(labels_truth)):
                h_test2D.GetYaxis().SetBinLabel(ivar+1,labels_truth[ivar])
            h_categories_[iden][itype]=h_test2D;hf.hists2D.append(h_test2D)

            h_test2D = TH2F('h_categories_weighted_X1_'+typevec[itype]+'_'+denvec[iden],'categories_weighted_X1_'+typevec[itype]+'_'+denvec[iden],lenvarvec,0,lenvarvec,len(labels_truth),0,len(labels_truth));
            for ivar in xrange(lenvarvec):
                h_test2D.GetXaxis().SetBinLabel(ivar+1,varvec[ivar])
            for ivar in xrange(len(labels_truth)):
                h_test2D.GetYaxis().SetBinLabel(ivar+1,labels_truth[ivar])
            h_categories_weighted_X1_[iden][itype]=h_test2D;hf.hists2D.append(h_test2D)

            h_test2D = TH2F('h_categories_weighted_X2_'+typevec[itype]+'_'+denvec[iden],'categories_weighted_X2_'+typevec[itype]+'_'+denvec[iden],lenvarvec,0,lenvarvec,len(labels_truth),0,len(labels_truth));
            for ivar in xrange(lenvarvec):
                h_test2D.GetXaxis().SetBinLabel(ivar+1,varvec[ivar])
            for ivar in xrange(len(labels_truth)):
                h_test2D.GetYaxis().SetBinLabel(ivar+1,labels_truth[ivar])
            h_categories_weighted_X2_[iden][itype]=h_test2D;hf.hists2D.append(h_test2D)



hf.HistsSumw2()

####################################for pt reweighting (truth histo only)
if doWeightPt:

    hist_arr_X1=[[[] for ivar in range (lenvarvec)] for iden in range(lendenvec)]
    hist_arr_X2=[[[] for ivar in range (lenvarvec)] for iden in range(lendenvec)]

    #file Cat (ttbar+Z+jets+Zbb)
    fileCat = TFile("/disk/userdata00/atlas_data2/sheim/output/02052013/AllMCNoWZZZ_02052013.root","READ") ##really only for ML relaxed...
    #file CatX (ttbar+Z+jets+Zbb)
    fileCatX = TFile("/disk/userdata00/atlas_data2/sheim/output/02262013_X/AllMCNoWZZZ_pt.root","READ")

    ##add up in eta, divide, such that histograms contain weight

    for iden in xrange(lendenvec):
        for ivar in xrange(lenvarvec):
            #hist_name_catX = 'h_etapt_abs_2muX_'+denvec[iden]+'_'+varvec[ivar]
            #hist_test_catX = fileCatX.Get(hist_name_catX)
            #hist_name_catX1 = 'h_etapt_1_2mu2e_'+denvec[iden]+'_'+varvec[ivar]+'E'
            #hist_test_catX1 = fileCat.Get(hist_name_catX1)
            #hist_name_catX2 = 'h_etapt_2_2mu2e_'+denvec[iden]+'_E'+varvec[ivar]
            #hist_test_catX2 = fileCat.Get(hist_name_catX2)
            hist_name_catX = 'h_etapt_abs_2muX_'+denvec[iden]+'_all'
            hist_test_catX = fileCatX.Get(hist_name_catX)
            hist_name_catX1 = 'h_etapt_1_2mu2e_'+denvec[iden]+'_allE'
            hist_test_catX1 = fileCat.Get(hist_name_catX1)
            hist_name_catX2 = 'h_etapt_2_2mu2e_'+denvec[iden]+'_Eall'
            hist_test_catX2 = fileCat.Get(hist_name_catX2)



            ##normalize
            integral = hist_test_catX.Integral()
            if integral != 0: hist_test_catX.Scale(1./integral)
            integral = hist_test_catX1.Integral()
            if integral != 0: hist_test_catX1.Scale(1./integral)
            integral = hist_test_catX2.Integral()
            if integral != 0: hist_test_catX2.Scale(1./integral)



            ##new hist
            hist_test_X1 = TH2F('h_X1_ptweight_'+denvec[iden]+'_'+varvec[ivar],'X1_ptweight_'+denvec[iden]+'_'+varvec[ivar],len(etaarr_1bin)-1,etaarr_1bin,len(ptarr)-1,ptarr)
            hist_test_X2 = TH2F('h_X2_ptweight_'+denvec[iden]+'_'+varvec[ivar],'X2_ptweight_'+denvec[iden]+'_'+varvec[ivar],len(etaarr_1bin)-1,etaarr_1bin,len(ptarr)-1,ptarr)

            ##loop over bins, fill
            for ibin_pt in xrange(hist_test_catX1.GetNbinsY()+1):
               ptyield_X1=0 
               ptyield_X2=0
               ptyield_X=0 
               for ibin_eta in xrange(hist_test_catX1.GetNbinsX()+1):
                   ptyield_X1=ptyield_X1+hist_test_catX1.GetBinContent(ibin_eta,ibin_pt)
                   ptyield_X2=ptyield_X2+hist_test_catX2.GetBinContent(ibin_eta,ibin_pt)
                   ptyield_X=ptyield_X+hist_test_catX.GetBinContent(ibin_eta,ibin_pt)
                   print 'ibin_pt: '+str(ibin_pt)+', ptyield_X1: '+str(ptyield_X1)+', ptyield_X2: '+str(ptyield_X2)+', ptyield_X: '+str(ptyield_X) 
                
  
               if not ptyield_X==0: 
	          ptyield_X1=ptyield_X1/ptyield_X
                  ptyield_X2=ptyield_X2/ptyield_X
               else:
                  ptyield_X1=0
                  ptyield_X2=0
               hist_test_X1.SetBinContent(1,ibin_pt,ptyield_X1)
               hist_test_X2.SetBinContent(1,ibin_pt,ptyield_X2)


            ##fill array
            hist_arr_X1[iden][ivar]=hist_test_X1
            hist_arr_X2[iden][ivar]=hist_test_X2
            hf.hists2D.append(hist_test_X1)
            hf.hists2D.append(hist_test_X2)

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
#for i in xrange(10000):
 
    if not (fin.GetEntry(i)): continue
    if not i%10000: print 'Processing entry %d/%d'%(i,nentries)
   

    #if not fin.mc_channel_number == 107661: continue

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

    numberevents_passed[4]+=1
    ##############################Apply cuts

    #no cuts on first pair necessary
    for iden in xrange(len(denvec)):
   
        #find index of highest pt x object, xindex
        xindex = -1
        maxpt = -1
   
        icount=0

        for il in xrange(fin.n_x_el):

            ##list test
            cat.Cat_Jets(il,fin,1)

            ##denominator selection 1
            if not cat.list[Categorization.Blayer]: continue
 
            ##do nothing at first for noID
            if denvec_int[iden]==Categorization.den_3_5 or denvec_int[iden]==Categorization.den_3_5TRT or denvec_int[iden]==Categorization.den_3_5failTRT:
                if not (cat.list[Categorization.pass3_5LooseLikelihood] or cat.list[Categorization.ML]): continue
            elif denvec_int[iden]==Categorization.den_ML or denvec_int[iden]==Categorization.den_MLTRT or denvec_int[iden]==Categorization.den_MLfailTRT:
                if not cat.list[Categorization.ML]: continue
            elif denvec_int[iden]==Categorization.den_MLrel or denvec_int[iden]==Categorization.den_MLrelTRT or denvec_int[iden]==Categorization.den_MLrelfailTRT:
                if not cat.list[Categorization.MLrel]: continue

            if fin.x_pt[il] > maxpt:
                xindex = il
                maxpt = fin.x_pt[il]

            icount=icount+1

        #if did not find a suitable x object:
        if xindex == -1: 
            continue 

        ##Kate/Elodie					      
        if icount > 1: continue			      
        if fin.MET_RefFinal_et > 25000: continue	      
        ##

        #list
        cat.Cat_Jets(xindex,fin,1) 

        ##denominator selection 2
        if denvec_int[iden]==Categorization.den_noIDTRT or denvec_int[iden]==Categorization.den_3_5TRT or denvec_int[iden]==Categorization.den_MLTRT or denvec_int[iden]==Categorization.den_MLrelTRT:
            if not cat.list[Categorization.TRT]: continue
        elif denvec_int[iden]==Categorization.den_noIDfailTRT or denvec_int[iden]==Categorization.den_3_5failTRT or denvec_int[iden]==Categorization.den_MLfailTRT or denvec_int[iden]==Categorization.den_MLrelfailTRT:
            if not cat.list[Categorization.failTRT]: continue

        index = fin.x_index[xindex]

        xpt = fin.x_pt[xindex]/1000.
        xeta = fin.x_eta[xindex]

        if xpt > 35: xpt = 34
        if xeta > 2.47: xeta = 2.46
        if xeta < -2.47: xeta = -2.46 

        if doWeightPt:
           ptbin_weight = hist_arr_X1[iden][ivar].FindBin(1,xpt)
 
        ################################Categories
    
        for itype in xrange(lentypevec):

            if fin.z_type != itype+1: continue

            for ivar in xrange(lenvarvec):
                if cat.list[varvec_int[ivar]]: 
                    h_reco_categories_[iden][itype].Fill(ivar, event_weight) 
                    h_etapt_[iden][itype][ivar].Fill(xeta,xpt, event_weight)   
                    h_etapt_abs_[iden][itype][ivar].Fill(abs(xeta),xpt, event_weight)
                    h_etapt_1bin_[iden][itype][ivar].Fill(abs(xeta),xpt, event_weight)
                    h_eta_[iden][itype][ivar].Fill(abs(xeta),xpt, event_weight)
                    h_pt_[iden][itype][ivar].Fill(abs(xeta),xpt, event_weight) 

            if not isData:
                truth_cat1 = ElectronTruth.getMCClassification(fin.el_type[index],fin.el_origin[index],fin.el_typebkg[index],fin.el_originbkg[index])
                if truth_cat1 == 7: truth_cat1 = 5

                #fill inside
                
                for ivar in xrange(lenvarvec):
                    for ibin_truth in xrange(len(labels_truth_int)):
                            if cat.list[varvec_int[ivar]] and labels_truth_int[ibin_truth] == 9: ##all
                                h_categories_[iden][itype].Fill(ivar,ibin_truth,event_weight)
                                if doWeightPt:
                                   h_categories_weighted_X1_[iden][itype].Fill(ivar,ibin_truth,event_weight*hist_arr_X1[iden][ivar].GetBinContent(ptbin_weight))
                                   h_categories_weighted_X2_[iden][itype].Fill(ivar,ibin_truth,event_weight*hist_arr_X2[iden][ivar].GetBinContent(ptbin_weight))
                            if cat.list[varvec_int[ivar]] and truth_cat1 == labels_truth_int[ibin_truth]: 
                                h_categories_[iden][itype].Fill(ivar,ibin_truth,event_weight)
                                if doWeightPt:
                                   h_categories_weighted_X1_[iden][itype].Fill(ivar,ibin_truth,event_weight*hist_arr_X1[iden][ivar].GetBinContent(ptbin_weight))
                                   h_categories_weighted_X2_[iden][itype].Fill(ivar,ibin_truth,event_weight*hist_arr_X2[iden][ivar].GetBinContent(ptbin_weight))      
            
####################################PRINT

print input_dir
print 'initial number of events: '+str(hm.numberevents_all)
print 'after cutflow: '+str(numberevents_passed[4])


####################################WRITE TO FILE

if outputname == '': fileout = TFile(output_dir+"/"+input_key+"_passed"+add_name+".root",'RECREATE')
else: fileout = TFile(outputname,'RECREATE')


hf.HistsWrite()

if printEventNumbers:
    for ifile in xrange(4):
        f_candidates[ifile].close()
        os.system("sort -k1,1n -k2,2n "+ name_files[ifile]+" > test.txt")
        os.system("mv test.txt "+ name_files[ifile])


print "Closing output file: " + fileout.GetPath().rstrip(':/')
fileout.Close()


