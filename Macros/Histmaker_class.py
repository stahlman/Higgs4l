#!/usr/bin/env python

__author__ = 'Heim Sarah'
__email__ = 'sheim@cern.ch'
__date__ = 'Nov 2012'

import os, sys, string, commands, math
from datetime import datetime
from pprint import pprint
import math
from ROOT import *
from ROOT import Math
from array import array
import glob

class Histmaker:

    i = 12345
    nevents_processed = {}
    nevents_processed_weighted = {}
    eventnumberarr = []
    numberevents_all=0
    #BkgCrossSection = 0
    MyHiggsCrossSection = 0
    MyH4lBrRatio = 0
    MyGoodRunsList = 0
    
    def __init__(self):
        
	self.LoadHiggsUtils()
	self.LoadXSBkg()
	self.LoadXSHiggs()       
       
    def LoadGRL(self,nameGRL):
        CWD = os.getcwd()
        os.chdir(CWD)
        reader = Root.TGoodRunsListReader(nameGRL)
        reader.Interpret()
        self.MyGoodRunsList = reader.GetMergedGRLCollection()
        self.MyGoodRunsList.Summary()
        return 

    def LoadXSBkg(self):
        CWD = os.getcwd()
        os.chdir(CWD)
        crossSection = CrossSections.bkgCrossSection(107650, CrossSections.EightTeV, 1)
        print 'test XS: '+str(crossSection)
        return crossSection

    def LoadXSHiggs(self):
        CWD = os.getcwd()
        os.chdir(CWD)
        self.MyHiggsCrossSection = HiggsCrossSection()
        print 'test higgs XS, 125 GeV: ', self.MyHiggsCrossSection.higgsprodxsecGGF(125, CrossSections.EightTeV)
        self.MyH4lBrRatio = H4lBrRatio()
	print 'test higgs BR, 125 GeV: ', self.MyH4lBrRatio.getemutauBrRatio(125)
        return 

    def LoadHiggsUtils(self):
        gSystem.Load('externals/GoodRunsLists/StandAlone/libGoodRunsLists.so')
	gSystem.Load('libMathMore.so')
	gSystem.Load('externals/HiggsZZ4lUtils/StandAlone/libHiggsZZ4lUtils.so')

    def GetFilesAndInitialCounts(self,fin,file_key,isData,listfilename=''):
        if listfilename == '':
            print "Using files that match: "+ file_key
            files = glob.glob(file_key)
        else: 
           with open(listfilename, 'r') as f:
               files=list(line for line in (l.strip() for l in f) if line)
               #files = [line.strip() for line in f]
        print "Found files: "
        for f in files:
            print "  " + f
        mc_channel_numberarr = []
        for subf in files:
            file = TFile(subf,"READ")
            h_nevents = file.Get("NEvents")
	    if ( not isinstance(h_nevents, TH1) ): 
	      print "ERROR: NEvents hist not found!  Skipping file"
	      continue	    
            if not isData:
                mcChannelPar = file.Get("MC_channel_number")
                mcChannel = mcChannelPar.GetVal()
                if mcChannel not in mc_channel_numberarr:
                   print 'Adding sample:',mcChannel
                   mc_channel_numberarr.append(mcChannel)
                   self.nevents_processed[mcChannel]=h_nevents.GetBinContent(1)
                   self.nevents_processed_weighted[mcChannel]=h_nevents.GetBinContent(2)
                else: 
		   self.nevents_processed[mcChannel] += h_nevents.GetBinContent(1)
                   self.nevents_processed_weighted[mcChannel] += h_nevents.GetBinContent(2)
		     
	    fin.Add(subf)
            file.Close()
        if not isData: pprint(self.nevents_processed)
	
	return

    def ApplyDataTreatment(self,fin):
	if not self.MyGoodRunsList.HasRunLumiBlock (fin.RunNumber,fin.lbn) : return -999
        if  fin.RunNumber*100000+fin.EventNumber not in self.eventnumberarr: self.eventnumberarr.append(fin.RunNumber*100000+fin.EventNumber)
        else:
            #print 'duplicate in the two streams'
            return -999

    def VetoEvent(self,fin):
        return killEvent(fin.mc_channel_number,146369,fin.mc_n,fin.mc_pt,fin.mc_eta,fin.mc_phi,fin.mc_m,fin.mc_status,fin.mc_pdgId) 
 
    def EventWeight(self,fin,lumi):
        return self.LumiWeight(fin,lumi) * fin.evt_weight * self.MCWeightSF(fin.mc_channel_number)

    def ApplyMCTreatment(self,fin,lumi):
        if killEvent(fin.mc_channel_number,146369,fin.mc_n,fin.mc_pt,fin.mc_eta,fin.mc_phi,fin.mc_m,fin.mc_status,fin.mc_pdgId): 
            return -999
         
	lumi_weight = self.LumiWeight(fin,lumi)

        event_weight = lumi_weight * fin.evt_weight * self.MCWeightSF(fin.mc_channel_number)
	return event_weight

    def MCWeightSF(self,channel):
    
	if self.nevents_processed_weighted[channel] == 0:
	    print "ERROR: 0 weighted generated mc events"
	    return 0
	    
        return self.nevents_processed[channel] / self.nevents_processed_weighted[channel]

    def LumiWeight(self,fin,lumi):
        
	crossSection = CrossSections.bkgCrossSection(fin.mc_channel_number, CrossSections.EightTeV, 1)

        if crossSection == -1: 
	    crossSection = self.SignalCrossSection(fin.mc_channel_number, fin.event_type_truth)
	    crossSection *= fin.weight_brcorrection

        if crossSection < 0: 
            print "ERROR: MC cross section less than 0 (not found?)! Event:",fin.EventNumber, fin.mc_channel_number
            return 0

	if self.nevents_processed[fin.mc_channel_number] == 0:
	    print "ERROR: 0 generated mc events"
	    return 0
	
        event_weight = 1./self.nevents_processed[fin.mc_channel_number] * crossSection * lumi
        
	return event_weight

    
    def SignalCrossSection(self, channel, event_type):
    
        mass,mode = self.MCChanneltoMassMode(channel)
        	
        crossSection = -1	        
	branchingRatio = -1
	if (mass != 0):
	  if (mode   == 'ggH'): crossSection = self.MyHiggsCrossSection.higgsprodxsecGGF(mass, CrossSections.EightTeV)
          elif (mode == 'VBF'): crossSection = self.MyHiggsCrossSection.higgsprodxsecVBF(mass, CrossSections.EightTeV)
          elif (mode == 'WH'):  crossSection = self.MyHiggsCrossSection.higgsprodxsecWH( mass, CrossSections.EightTeV) 
          elif (mode == 'ZH'):  crossSection = self.MyHiggsCrossSection.higgsprodxsecZH( mass, CrossSections.EightTeV) 
          elif (mode == 'ttH'): crossSection = self.MyHiggsCrossSection.higgsprodxsecttH(mass, CrossSections.EightTeV)
        
	  if (event_type == 0 or event_type == 1 or event_type == 4):  #same flavor channels (interference) 
	     branchingRatio = self.MyH4lBrRatio.get4eBrRatio(mass) * 9.
	  elif (event_type == 2 or event_type == 3 or event_type == 5): #not same flavor channels (no interference)
	     branchingRatio = self.MyH4lBrRatio.get2e2muBrRatio(mass) * 9. / 2.
         	
	if (crossSection == -1 or branchingRatio == -1): 
	  print "WARNING: Signal cross section not found! channel =", channel,"event_type =", event_type
	  return -1
	
	return crossSection * branchingRatio

    def MCChanneltoMassMode(self, channel, verbose=true):
       #can prob do this in a smarter way, but works for now
       if channel   == 160155: return 125, 'ggH'
       elif channel == 160205: return 125, 'VBF'
       elif channel == 160255: return 125, 'WH' 
       elif channel == 160305: return 125, 'ZH'
       elif channel == 167562: return 125, 'ttH'       

       elif channel == 160154: return 120, 'ggH'
       elif channel == 160204: return 120, 'VBF'
       elif channel == 160254: return 120, 'WH' 
       elif channel == 160304: return 120, 'ZH'
       elif channel == 167561: return 120, 'ttH'       

       elif channel == 167220: return 123, 'ggH'
       elif channel == 167230: return 123, 'VBF'
       elif channel == 167240: return 123, 'WH' 
       elif channel == 167250: return 123, 'ZH'
       elif channel == 167566: return 123, 'ttH'       
	
       elif channel == 167222: return 124, 'ggH'
       elif channel == 167232: return 124, 'VBF'
       elif channel == 167242: return 124, 'WH' 
       elif channel == 167252: return 124, 'ZH'
       elif channel == 167567: return 124, 'ttH'
              
       elif channel == 167225: return 126, 'ggH'
       elif channel == 167235: return 126, 'VBF'
       elif channel == 167245: return 126, 'WH' 
       elif channel == 167255: return 126, 'ZH'
       elif channel == 167568: return 126, 'ttH'
              
       elif channel == 167227: return 127, 'ggH'
       elif channel == 167237: return 127, 'VBF'
       elif channel == 167247: return 127, 'WH' 
       elif channel == 167257: return 127, 'ZH'
       elif channel == 167569: return 127, 'ttH' 
             
       elif channel == 160156: return 130, 'ggH'
       elif channel == 160206: return 130, 'VBF'
       elif channel == 160256: return 130, 'WH' 
       elif channel == 160306: return 130, 'ZH'
       elif channel == 167563: return 130, 'ttH'

       elif channel == 160353: return 125, 'ggH'
       elif channel == 160354: return 125, 'ggH'
              
       if (verbose): print "WARNING: Unknown signal channel number:", channel
       
       return 0, ''
       
       
    def PassCutsOnElectrons(self,fin,vecindex,blayer,Pix,TrkIso,CaloIso,d0,typeisEM,optiso="std"):
	if abs(fin.lepton_type[vecindex]) != 1: return 1 #not an electron
	index = fin.lepton_index[vecindex]
       	#blayer
        if blayer and ((fin.el_expectHitInBLayer[index]==1) and (fin.el_nBLHits[index] < 1)): return 0
        #Pixel
        if Pix and (fin.el_nPixHits[index]+fin.el_nPixelDeadSensors[index]) < 2: return 0
        #TrkIso
	if optiso == "std" and TrkIso and fin.lepton_trk_iso20[vecindex] > 0.15: return 0
        if optiso == "new" and TrkIso and fin.lepton_trk_iso30[vecindex] > 0.20: return 0
        #CaloIso
	if optiso == "std" and CaloIso and fin.lepton_calo_iso20[vecindex] > 0.2: return 0
        if optiso == "new" and CaloIso and fin.lepton_calo_iso30[vecindex] > 0.35: return 0
        #d0
        if d0 and fin.lepton_d0_significance[vecindex] > 6.5: return 0
        #isEM
	if typeisEM == "ML": 
	    if fin.lepton_passML[vecindex]==0: return 0
        elif typeisEM == "ML_HCP":
            if fin.lepton_passML_HCP[vecindex]==0: return 0
        elif typeisEM == "ML_Relaxed":
            if fin.lepton_passML_Relaxed[vecindex]==0: return 0
        elif typeisEM == "VeryLooseLikelihood":
	    if fin.lepton_passVeryLooseLikelihood[vecindex]==0: return 0	
        elif typeisEM == "VeryLooseLikelihoodORML":
            if (fin.lepton_passVeryLooseLikelihood[vecindex]==0 and fin.lepton_passML[vecindex]==0): return 0
	elif typeisEM == "LooseLikelihood":
            if fin.lepton_passLooseLikelihood[vecindex]==0: return 0
        elif typeisEM == "LooseBLPixLikelihood":
            if fin.lepton_passLooseBLPixLikelihood[vecindex]==0: return 0
        elif typeisEM == "3_5Likelihood":
            if fin.lepton_pass3_5Likelihood[vecindex]==0: return 0
        elif typeisEM == "3_5LikelihoodORML":
            if (fin.lepton_pass3_5Likelihood[vecindex]==0 and fin.lepton_passML[vecindex]==0): return 0
        elif typeisEM == "SiTrack":
 	    if (fin.el_nPixHits[index] + fin.el_nSCTHits[index] ) < 7: return 0
        elif typeisEM == "None": return 1
        else: print 'Warning: ID not known!'
        return 1

    def passM34Cut(self,fin,m34cut):
      
        masscut = 0

        if m34cut == 17500: m34cut_m34 = [ 17500.,  30000.,  35000.,  40000.,  50000. ]
        elif m34cut == 15000: m34cut_m34 = [ 15000.,  30000.,  35000.,  40000.,  50000. ]
        elif m34cut == 12000: m34cut_m34 = [ 12000.,  30000.,  35000.,  40000.,  50000. ]


        m34cut_m4l = [ 140000., 160000., 165000., 180000., 190000. ]

        
        i = 0
        for i in xrange(len(m34cut_m4l)):
            #if fin.EventNumber == 83011892: print  str(fin.m_4l)+', '+str(m34cut_m4l[i])
            if m34cut_m4l[i] >= fin.m_4l: break



        if i == 0: masscut = m34cut_m34[i]
        elif i == len(m34cut_m4l): masscut =  m34cut_m34[len(m34cut_m4l)-1] 
        else: masscut = m34cut_m34[i-1] + (m34cut_m34[i] - m34cut_m34[i-1])/(m34cut_m4l[i] - m34cut_m4l[i-1])*(fin.m_4l - m34cut_m4l[i-1])
 
        if fin.EventNumber == 83011892: print str(fin.m_4l)+', cut: '+str(masscut) 
 
        if fin.m_34 < masscut: return false
        else: return true
    
    def PassTrackIsolationCuts(self,fin,optiso="All"):

      pass_TrkIso = true
      pass_TrkIso_firstpair = true
      pass_TrkIso_secondpair = true

      for i in range(len(fin.lepton_type)):       
	 if not (fin.lepton_trk_iso20[i] < 0.15): 
            pass_TrkIso = false
            if (i < 2): pass_TrkIso_firstpair = false
            else: pass_TrkIso_secondpair = false

      if (optiso == "All"): return pass_TrkIso
      if (optiso == "FirstPair"): return pass_TrkIso_firstpair
      if (optiso == "SecondPair"): return pass_TrkIso_secondpair

      pass_LooseTrkIso = true
      pass_LooseTrkIso_firstpair = true
      pass_LooseTrkIso_secondpair = true

      pass_LooseTrkIso_OR = false
      pass_LooseTrkIso_firstpair_OR = false
      pass_LooseTrkIso_secondpair_OR = false

      for i in range(len(fin.lepton_type)):       
	 if not (fin.lepton_trk_iso20[i] < 0.3): 
            pass_LooseTrkIso = false
            if (i < 2): pass_LooseTrkIso_firstpair = false
            else: pass_LooseTrkIso_secondpair = false

         if (fin.lepton_trk_iso20[i] < 0.3):
            pass_LooseTrkIso_OR = true
            if (i < 2): pass_LooseTrkIso_firstpair_OR = true
            else: pass_LooseTrkIso_secondpair_OR = true


      if (optiso == "LooseAll"): return pass_LooseTrkIso
      if (optiso == "LooseFirstPair"): return pass_LooseTrkIso_firstpair
      if (optiso == "LooseSecondPair"): return pass_LooseTrkIso_secondpair

      if (optiso == "LooseAllOR"): return pass_LooseTrkIso_OR
      if (optiso == "LooseFirstPairOR"): return pass_LooseTrkIso_firstpair_OR
      if (optiso == "LooseSecondPairOR"): return pass_LooseTrkIso_secondpair_OR
      
      print "ERROR: Invalid track isolation option: ", optiso
      return 0
      
    def PassCaloIsolationCuts(self,fin,optiso="All"):

      pass_CaloIso = true
      pass_CaloIso_firstpair = true
      pass_CaloIso_secondpair = true

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


      if (optiso == "All"): return pass_CaloIso
      if (optiso == "FirstPair"): return pass_CaloIso_firstpair
      if (optiso == "SecondPair"): return pass_CaloIso_secondpair

      pass_LooseCaloIso = true
      pass_LooseCaloIso_firstpair = true
      pass_LooseCaloIso_secondpair = true

      for i in range(len(fin.lepton_type)):       
        if (abs(fin.lepton_type[i]) == 1): #electrons
          if not (fin.lepton_calo_iso20[i] < 0.30): 
             pass_LooseCaloIso = false
             if (i < 2): pass_LooseCaloIso_firstpair = false
             else: pass_LooseCaloIso_secondpair = false

        elif ((abs(fin.lepton_type[i]) == 2) and (fin.mu_staco_isStandAloneMuon[ fin.lepton_index[i] ] == 1)): #standalone muons
          if not (fin.lepton_calo_iso20[i] < 0.30): 
             pass_LooseCaloIso = false
             if (i < 2): pass_LooseCaloIso_firstpair = false
             else: pass_LooseCaloIso_secondpair = false
             
        else: #all other muons
          if not (fin.lepton_calo_iso20[i] < 0.30): #muons
             pass_LooseCaloIso = false
             if (i < 2): pass_LooseCaloIso_firstpair = false
             else: pass_LooseCaloIso_secondpair = false

      if (optiso == "LooseAll"): return pass_LooseCaloIso
      if (optiso == "LooseFirstPair"): return pass_LooseCaloIso_firstpair
      if (optiso == "LooseSecondPair"): return pass_LooseCaloIso_secondpair

      
      print "ERROR: Invalid calo isolation option: ", optiso
      return 0
      
      
    def PassD0SignificanceCuts(self,fin,optiso="All"):

      pass_D0Sig = true
      pass_D0Sig_firstpair = true
      pass_D0Sig_secondpair = true

      for i in range(len(fin.lepton_type)):       
	if (abs(fin.lepton_type[i]) == 1): #electrons
           if not (fin.lepton_d0_significance[i] < 6.5 ):
              pass_D0Sig = false
              if (i < 2): pass_D0Sig_firstpair = false
              else: pass_D0Sig_secondpair = false
	      
	if (abs(fin.lepton_type[i]) == 2 or abs(fin.lepton_type[i]) == 3): #muons
           if not (fin.lepton_d0_significance[i] < 3.5 ):
              pass_D0Sig = false
              if (i < 2): pass_D0Sig_firstpair = false
              else: pass_D0Sig_secondpair = false

      if (optiso == "All"): return pass_D0Sig
      if (optiso == "FirstPair"): return pass_D0Sig_firstpair
      if (optiso == "SecondPair"): return pass_D0Sig_secondpair

      pass_LooseD0Sig = true
      pass_LooseD0Sig_firstpair = true
      pass_LooseD0Sig_secondpair = true

      for i in range(len(fin.lepton_type)):       
	if (abs(fin.lepton_type[i]) == 1): #electrons
           if not (fin.lepton_d0_significance[i] < 6.5 ):
              pass_LooseD0Sig = false
              if (i < 2): pass_LooseD0Sig_firstpair = false
              else: pass_LooseD0Sig_secondpair = false
	      
	if (abs(fin.lepton_type[i]) == 2 or abs(fin.lepton_type[i]) == 3): #muons
           if not (fin.lepton_d0_significance[i] < 6.5 ):
              pass_LooseD0Sig = false
              if (i < 2): pass_LooseD0Sig_firstpair = false
              else: pass_LooseD0Sig_secondpair = false

      if (optiso == "LooseAll"): return pass_LooseD0Sig
      if (optiso == "LooseFirstPair"): return pass_LooseD0Sig_firstpair
      if (optiso == "LooseSecondPair"): return pass_LooseD0Sig_secondpair
      
      print "ERROR: Invalid d0 significance option: ", optiso
      return 0
  
    def SignalRegion(self, fin, opt=""):

      if (fin.m_4l/1000.0 > 120 and fin.m_4l/1000.0 < 130): return true

      return false
  
