#!/usr/bin/env python

__author__ = 'Heim Sarah'
__email__ = 'sheim@cern.ch'
__date__ = 'Nov 2012'

import os, sys, string, commands, math
from datetime import datetime
from pprint import pprint
import math
from ROOT import * 
from array import array
import glob

class Categorization:

   #enum for criteria      
   all=1
   E=2
   faild0=3                                       
   failiso=4
   failTRT=5
   TRT=6
   failID=7
   Blayer=8
   ML=9
   VeryLooseLikelihood=10
   LooseLikelihood=11
   pass3_5LooseLikelihood=12
   MLrel=13

   #enum for denominators
   den_noID=10
   den_noIDTRT=11
   den_noIDfailTRT=12
   den_3_5=20
   den_3_5TRT=21
   den_3_5failTRT=22
   den_ML=30
   den_MLTRT=31
   den_MLfailTRT=32
   den_MLrel=40
   den_MLrelTRT=41
   den_MLrelfailTRT=42


   list = [0 for i in xrange(15)]

   def Cat_Jets(self,vecindex,fin,flag):

        if not flag:
            index = fin.lepton_index[vecindex]
            eta = fin.lepton_eta[vecindex]

            passIso = (fin.lepton_trk_iso20[vecindex] < 0.15 and fin.lepton_calo_iso20[vecindex] < 0.2)
            #passIso = (fin.lepton_trk_iso30[vecindex] < 0.15 and fin.lepton_calo_iso30[vecindex] < 0.35)
            passd0 = fin.lepton_d0_significance[vecindex] < 6.5
            #passID = fin.lepton_passLooseLikelihood[vecindex]
            passID = fin.lepton_passML[vecindex]
            passBlayer =  (((fin.el_expectHitInBLayer[index]==0) or (fin.el_nBLHits[index] > 0)) and (fin.el_nPixHits[index]+fin.el_nPixelDeadSensors[index]) > 1)
            passML = fin.lepton_passML[vecindex]
            passLooseLikelihood = fin.lepton_passLooseLikelihood[vecindex]
            passVeryLooseLikelihood = fin.lepton_passVeryLooseLikelihood[vecindex]
            pass3_5LooseLikelihood = fin.lepton_pass3_5Likelihood[vecindex]
            passMLrel = fin.lepton_passML_Relaxed[vecindex]

        else:
            index = int(fin.x_index[vecindex])
            eta = fin.x_eta[vecindex]
            bitmask = fin.x_bitmask[vecindex] 

            PassTrkIso             = 0x1 << 1
            PassOptTrkIso          = 0x1 << 2
            PassCaloIso            = 0x1 << 3
            PassOptCaloIso         = 0x1 << 4
            PassD0                 = 0x1 << 5
            PassLikelihood         = 0x1 << 6
            PassLooseLikelihood    = 0x1 << 7
            PassMediumLikelihood   = 0x1 << 8
            PassML                 = 0x1 << 9
            PassML_HCP             = 0x1 << 10
            PassBLayer             = 0x1 << 11
            Pass3_5LooseLikelihood = 0x1 << 12
            PassVeryLooseLikelihood = 0x1 << 13
            PassMLrel               = 0x1 << 15          
 


            #passID = ((bitmask & PassLooseLikelihood) > 0)    #?
            passID = ((bitmask & PassML) > 0)    #?
            passIso = ((bitmask & PassTrkIso > 0) and (fin.x_bitmask[vecindex] & PassCaloIso > 0))
            #passIso = ((fin.x_trk_iso30[vecindex] < 0.15) and (fin.x_calo_iso30[vecindex] < 0.35))
            passd0 = (bitmask & PassD0 > 0)

            passBlayer = ((bitmask & PassBLayer) > 0)
            passML = ((bitmask & PassML) > 0)
            passLooseLikelihood = ((bitmask & PassLooseLikelihood) > 0)
            passVeryLooseLikelihood = ((bitmask & PassVeryLooseLikelihood) > 0)
            pass3_5LooseLikelihood = ((bitmask & Pass3_5LooseLikelihood) > 0)
            passMLrel = ((bitmask & PassMLrel) > 0)

        #########TRT/rphi
        passTRTrphi = 0
        nTRTTotal= fin.el_nTRTHits[index]+fin.el_nTRTOutliers[index]
        CutTR = [0.09, 0.105, 0.11, 0.125, 0.145, 0.16]
        etaTR = [0.1, 0.625, 1.07, 1.304, 1.752, 2.0]
        ibin_eta_TRT = -1

        for ibinEta in xrange(6):
            if ibinEta == 0:
                if abs(eta) < etaTR[ibinEta]: ibin_eta_TRT = ibinEta
            else:
                if abs(eta) >= etaTR[ibinEta-1] and abs(eta) < etaTR[ibinEta]: ibin_eta_TRT = ibinEta

        passTR=0
        if ibin_eta_TRT >= 0:  passTR = (fin.el_TRTHighTOutliersRatio[index] > CutTR[ibin_eta_TRT])
        passRphi=(fin.el_rphi[index]>0.9)

        if abs(eta)<2.0 or nTRTTotal>=10: passTRTrphi = passTR
        else: passTRTrphi = passRphi

        if (fin.el_f1[index] > 0.1) and passTRTrphi: passTRTrphi = True
        else: passTRTrphi = False 

        ####
        self.list[1] = True	
        self.list[2] = (passIso and passd0 and passID) 
        self.list[3] = not passd0 
        self.list[4] = not passIso
        self.list[5] = not passTRTrphi
        self.list[6] = passTRTrphi
        self.list[7] = not passID
        self.list[8] = passBlayer
        self.list[9] = passML
        self.list[10] = passVeryLooseLikelihood
        self.list[11] = passLooseLikelihood
        self.list[12] = pass3_5LooseLikelihood
        self.list[13] = passMLrel

     
def bin(s):
    return str(s) if s<=1 else bin(s>>1) + str(s&1)










