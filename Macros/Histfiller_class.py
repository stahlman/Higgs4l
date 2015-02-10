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

class Histfiller:
   
    hists = []
    hists2D = []
    typevec = ["4mu","4e","2mu2e","2e2mu",""]
   
    #List all HistDefs?

    #Basics
    h_m_4l=TH1F()
    h_m_12=TH1F()
    h_m_34=TH1F()
    h_pt=TH1F()

    h_m_mumu=TH1F()
    h_m_ee=TH1F()

    h_pt_mu=TH1F()
    h_pt_e=TH1F()

    h_pt_l1_highmass=TH1F()
    h_pt_l2_highmass=TH1F()
    h_pt_l3_highmass=TH1F()
    h_pt_l4_highmass=TH1F()
   
    h_met_reffinal_et=TH1F()
    h_n_jets=TH1F()
   
    #Arrays (4mu, 4e etc., categories)
    h_m_4l_ = []
    h_m_12_ = []
    h_m_34_ = []

    h_m_mumu_ = []
    h_m_ee_ = []

    h_highmass_m12_ = []
    h_highmass_m34_ = []

    #Isolation
    h_isEMd0_caloiso3_vs_caloiso4_etcone20_ = []
    h_isEM_caloiso3_vs_caloiso4_etcone20_ = []
    h_isEMd0_caloiso3_vs_caloiso4_etcone30_ = []
    h_isEM_caloiso3_vs_caloiso4_etcone30_ = []
    h_isEMd0_caloiso3_vs_caloiso4_etcone20_lt160_ = []
    h_isEM_caloiso3_vs_caloiso4_etcone20_lt160_ = []
    h_isEMd0_caloiso3_vs_caloiso4_etcone30_lt160_ = []
    h_isEM_caloiso3_vs_caloiso4_etcone30_lt160_ = []


    def HistsWrite(self):
       for hist in self.hists:
           hist.Write()
       for hist in self.hists2D:
           hist.Write()

    def HistsSumw2(self):
       for hist in self.hists:
           hist.Sumw2()
       for hist in self.hists2D:
           hist.Sumw2()

    def HistsBasic_Def(self):
       self.h_m_4l = TH1F('h_m_4l','m_4l',1000,0,1000);  self.hists.append(self.h_m_4l) 
       self.h_m_12 = TH1F('h_m_12','m_12',200,0,200);  self.hists.append(self.h_m_12) 
       self.h_m_34 = TH1F('h_m_34','m_34',200,0,200);  self.hists.append(self.h_m_34) 

       self.h_m_mumu = TH1F('h_m_mumu','m_mumu',400,0,200);  self.hists.append(self.h_m_mumu) 
       self.h_m_ee   = TH1F('h_m_ee',  'm_ee'  ,400,0,200);  self.hists.append(self.h_m_ee) 
      
       self.h_met_reffinal_et = TH1F('h_met_reffinal_et','E_{T}^{miss}',200,0,200);  self.hists.append(self.h_met_reffinal_et) 
       self.h_n_jets          = TH1F('h_n_jets','N_{jets}',11,-0.5,10.5);  self.hists.append(self.h_n_jets) 

       ####loop over categories
       for itype in xrange(4):
           h_test = TH1F('h_m_4l_'+self.typevec[itype],'m_4l_'+self.typevec[itype],1000,0,1000); self.h_m_4l_.append(h_test); self.hists.append(h_test)
           h_test = TH1F('h_m_12_'+self.typevec[itype],'m_12_'+self.typevec[itype],200,0,200); self.h_m_12_.append(h_test); self.hists.append(h_test)
           h_test = TH1F('h_m_34_'+self.typevec[itype],'m_34_'+self.typevec[itype],200,0,200); self.h_m_34_.append(h_test); self.hists.append(h_test)

           h_test = TH1F('h_m_mumu_'+self.typevec[itype],'m_mumu_'+self.typevec[itype],400,0,200); self.h_m_mumu_.append(h_test); self.hists.append(h_test)
           h_test = TH1F('h_m_ee_'  +self.typevec[itype],'m_ee_'+self.typevec[itype],400,0,200); self.h_m_ee_.append(h_test); self.hists.append(h_test)

           h_test = TH1F('h_highmass_m12_'+self.typevec[itype],'highmass_m12_'+self.typevec[itype],400,0,200); self.h_highmass_m12_.append(h_test); self.hists.append(h_test)
           h_test = TH1F('h_highmass_m34_'+self.typevec[itype],'highmass_m34_'+self.typevec[itype],400,0,200); self.h_highmass_m34_.append(h_test); self.hists.append(h_test)


    def HistsPt_Def(self):
    
       self.h_pt          = TH1F('h_pt','p_{T}^{4l}',300,0,300);  self.hists.append(self.h_pt) 
       
       self.h_pt_highmass = TH1F('h_pt_highmass','p_{T}^{4l}',300,0,300);  self.hists.append(self.h_pt_highmass) 
       self.h_pt_lowmass  = TH1F('h_pt_lowmass','p_{T}^{4l}',300,0,300);  self.hists.append(self.h_pt_lowmass) 
       self.h_pt_signal   = TH1F('h_pt_signal','p_{T}^{4l}',300,0,300);  self.hists.append(self.h_pt_lowmass) 

       self.h_pt_mu = TH1F('h_pt_mu','h_pt_mu;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_mu) 
       self.h_pt_e  = TH1F('h_pt_e','h_pt_e;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_e) 

       self.h_pt_l1_highmass  = TH1F('h_pt_l1_highmass','h_pt_l1;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l1_highmass) 
       self.h_pt_l2_highmass  = TH1F('h_pt_l2_highmass','h_pt_l2;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l2_highmass) 
       self.h_pt_l3_highmass  = TH1F('h_pt_l3_highmass','h_pt_l3;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l3_highmass) 
       self.h_pt_l4_highmass  = TH1F('h_pt_l4_highmass','h_pt_l4;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l4_highmass) 
      
       self.h_pt_l1_lowmass  = TH1F('h_pt_l1_lowmass','h_pt_l1;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l1_lowmass) 
       self.h_pt_l2_lowmass  = TH1F('h_pt_l2_lowmass','h_pt_l2;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l2_lowmass) 
       self.h_pt_l3_lowmass  = TH1F('h_pt_l3_lowmass','h_pt_l3;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l3_lowmass) 
       self.h_pt_l4_lowmass  = TH1F('h_pt_l4_lowmass','h_pt_l4;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l4_lowmass) 

       self.h_pt_l1_signal  = TH1F('h_pt_l1_signal','h_pt_l1;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l1_signal) 
       self.h_pt_l2_signal  = TH1F('h_pt_l2_signal','h_pt_l2;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l2_signal) 
       self.h_pt_l3_signal  = TH1F('h_pt_l3_signal','h_pt_l3;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l3_signal) 
       self.h_pt_l4_signal  = TH1F('h_pt_l4_signal','h_pt_l4;p_{T} [GeV]',200,0,200);  self.hists.append(self.h_pt_l4_signal) 
      


    def HistsIso_Def(self):
       for itype in xrange(4):
           h_test2D = TH2F('h_isEMd0_caloiso3_vs_caloiso4_etcone20_'+self.typevec[itype],'isEMd0_caloiso3_vs_caloiso4_etcone20_'+self.typevec[itype],100,-0.5,2,100,-0.5,2);self.h_isEMd0_caloiso3_vs_caloiso4_etcone20_.append(h_test2D);self.hists2D.append(h_test2D)
           h_test2D = TH2F('h_isEM_caloiso3_vs_caloiso4_etcone20_'+self.typevec[itype],'isEMcaloiso3_vs_caloiso4_etcone20_'+self.typevec[itype],100,-0.5,2,100,-0.5,2);self.h_isEM_caloiso3_vs_caloiso4_etcone20_.append(h_test2D);self.hists2D.append(h_test2D)
           h_test2D = TH2F('h_isEMd0_caloiso3_vs_caloiso4_etcone30_'+self.typevec[itype],'isEMd0_caloiso3_vs_caloiso4_etcone30_'+self.typevec[itype],100,-0.5,2,100,-0.5,2);self.h_isEMd0_caloiso3_vs_caloiso4_etcone30_.append(h_test2D);self.hists2D.append(h_test2D)
           h_test2D = TH2F('h_isEM_caloiso3_vs_caloiso4_etcone30_'+self.typevec[itype],'isEMcaloiso3_vs_caloiso4_etcone30_'+self.typevec[itype],100,-0.5,2,100,-0.5,2);self.h_isEM_caloiso3_vs_caloiso4_etcone30_.append(h_test2D);self.hists2D.append(h_test2D)
           h_test2D = TH2F('h_isEMd0_caloiso3_vs_caloiso4_etcone20_lt160_'+self.typevec[itype],'isEMd0_caloiso3_vs_caloiso4_etcone20_lt160_'+self.typevec[itype],100,-0.5,2,100,-0.5,2);self.h_isEMd0_caloiso3_vs_caloiso4_etcone20_lt160_.append(h_test2D);self.hists2D.append(h_test2D)
           h_test2D = TH2F('h_isEM_caloiso3_vs_caloiso4_etcone20_lt160_'+self.typevec[itype],'isEMcaloiso3_vs_caloiso4_etcone20_lt160_'+self.typevec[itype],100,-0.5,2,100,-0.5,2);self.h_isEM_caloiso3_vs_caloiso4_etcone20_lt160_.append(h_test2D);self.hists2D.append(h_test2D)
           h_test2D = TH2F('h_isEMd0_caloiso3_vs_caloiso4_etcone30_lt160_'+self.typevec[itype],'isEMd0_caloiso3_vs_caloiso4_etcone30_lt160_'+self.typevec[itype],100,-0.5,2,100,-0.5,2);self.h_isEMd0_caloiso3_vs_caloiso4_etcone30_lt160_.append(h_test2D);self.hists2D.append(h_test2D)
           h_test2D = TH2F('h_isEM_caloiso3_vs_caloiso4_etcone30_lt160_'+self.typevec[itype],'isEMcaloiso3_vs_caloiso4_etcone30_lt160_'+self.typevec[itype],100,-0.5,2,100,-0.5,2);self.h_isEM_caloiso3_vs_caloiso4_etcone30_lt160_.append(h_test2D);self.hists2D.append(h_test2D)


    def HistsBasic_Fill(self,fin,event_weight):
       self.h_m_4l.Fill(fin.m_4l/1000., event_weight) 
       self.h_m_12.Fill(fin.m_12/1000., event_weight) 
       self.h_m_34.Fill(fin.m_34/1000., event_weight) 

       self.h_met_reffinal_et.Fill(fin.MET_RefFinal_et/1000., event_weight) 
       self.h_n_jets.Fill(fin.n_jets, event_weight) 
       
       if (fin.m_4l > 190000.):
           if (fin.quad_type == 0):        
               self.h_m_mumu.Fill(fin.m_12/1000., event_weight)
               self.h_m_mumu.Fill(fin.m_34/1000., event_weight) 
	       self.h_m_mumu_[fin.quad_type].Fill(fin.m_12/1000., event_weight)	 
	       self.h_m_mumu_[fin.quad_type].Fill(fin.m_34/1000., event_weight)	 
           if (fin.quad_type == 1):        
               self.h_m_ee.Fill(fin.m_12/1000., event_weight) 
               self.h_m_ee.Fill(fin.m_34/1000., event_weight) 
	       self.h_m_ee_[fin.quad_type].Fill(fin.m_12/1000., event_weight)	 
	       self.h_m_ee_[fin.quad_type].Fill(fin.m_34/1000., event_weight)	 
           if (fin.quad_type == 2):        
               self.h_m_mumu.Fill(fin.m_12/1000., event_weight) 
               self.h_m_ee.Fill(fin.m_34/1000., event_weight) 
	       self.h_m_mumu_[fin.quad_type].Fill(fin.m_12/1000., event_weight)	 
	       self.h_m_ee_[fin.quad_type].Fill(fin.m_34/1000., event_weight)	 
           if (fin.quad_type == 3):        
               self.h_m_ee.Fill(fin.m_12/1000., event_weight) 
               self.h_m_mumu.Fill(fin.m_34/1000., event_weight) 
	       self.h_m_ee_[fin.quad_type].Fill(fin.m_12/1000., event_weight)	 
	       self.h_m_mumu_[fin.quad_type].Fill(fin.m_34/1000., event_weight)	 

	   for itype in xrange(4):
               if fin.quad_type == itype:
        	   self.h_highmass_m12_[itype].Fill(fin.m_12/1000., event_weight)	
        	   self.h_highmass_m34_[itype].Fill(fin.m_34/1000., event_weight)	

       
       ####loop over categories
       for itype in xrange(4):
           if fin.quad_type == itype:
               self.h_m_4l_[itype].Fill(fin.m_4l/1000., event_weight)	
               self.h_m_12_[itype].Fill(fin.m_12/1000., event_weight)	
               self.h_m_34_[itype].Fill(fin.m_34/1000., event_weight)	
       


    def HistsPt_Fill(self,fin,event_weight):
       self.h_pt.Fill(fin.pt_4l/1000., event_weight) 
       
       lep_pt = sorted(fin.lepton_pt, reverse=True)
       
       if (fin.m_4l < 160000.): 
           self.h_pt_lowmass.Fill(fin.pt_4l/1000., event_weight) 

	   self.h_pt_l1_lowmass.Fill(lep_pt[0]/1000., event_weight)
	   self.h_pt_l2_lowmass.Fill(lep_pt[1]/1000., event_weight)
	   self.h_pt_l3_lowmass.Fill(lep_pt[2]/1000., event_weight)
	   self.h_pt_l4_lowmass.Fill(lep_pt[3]/1000., event_weight)
	   
       if (fin.m_4l > 120000. and fin.m_4l < 130000.): 
           self.h_pt_signal.Fill(fin.pt_4l/1000., event_weight) 
	   
	   self.h_pt_l1_signal.Fill(lep_pt[0]/1000., event_weight)
	   self.h_pt_l2_signal.Fill(lep_pt[1]/1000., event_weight)
	   self.h_pt_l3_signal.Fill(lep_pt[2]/1000., event_weight)
	   self.h_pt_l4_signal.Fill(lep_pt[3]/1000., event_weight)

       if (fin.m_4l > 190000.):
	   self.h_pt_highmass.Fill(fin.pt_4l/1000., event_weight) 
	   
	   self.h_pt_l1_highmass.Fill(lep_pt[0]/1000., event_weight)
	   self.h_pt_l2_highmass.Fill(lep_pt[1]/1000., event_weight)
	   self.h_pt_l3_highmass.Fill(lep_pt[2]/1000., event_weight)
	   self.h_pt_l4_highmass.Fill(lep_pt[3]/1000., event_weight)

       for i in range(4):
           if (fabs(fin.lepton_type[i]) == 1): #electrons  	   	    
	      self.h_pt_e.Fill(fin.lepton_pt[i]/1000., event_weight)
	   else:     
              self.h_pt_mu.Fill(fin.lepton_pt[i]/1000., event_weight)
      

    def HistsIso_Fill(self,fin,vecindex_sub1,vecindex_sub2,event_weight):
       for itype in xrange(4):
           if fin.quad_type == itype:
               if fin.lepton_d0_significance[vecindex_sub1] < 6.5 and fin.lepton_d0_significance[vecindex_sub2]<6.5:
                   self.h_isEMd0_caloiso3_vs_caloiso4_etcone20_[itype].Fill(fin.lepton_calo_iso20[vecindex_sub1],fin.lepton_calo_iso20[vecindex_sub2], event_weight)
                   self.h_isEMd0_caloiso3_vs_caloiso4_etcone30_[itype].Fill(fin.lepton_calo_iso30[vecindex_sub1],fin.lepton_calo_iso30[vecindex_sub2], event_weight) 
                   if fin.m_4l/1000. < 160 and not (fin.m_4l/1000. < 130 and fin.m_4l/1000. > 120): 
                       self.h_isEMd0_caloiso3_vs_caloiso4_etcone20_lt160_[itype].Fill(fin.lepton_calo_iso20[vecindex_sub1],fin.lepton_calo_iso20[vecindex_sub2], event_weight)
                       self.h_isEMd0_caloiso3_vs_caloiso4_etcone30_lt160_[itype].Fill(fin.lepton_calo_iso30[vecindex_sub1],fin.lepton_calo_iso30[vecindex_sub2], event_weight)              
               self.h_isEM_caloiso3_vs_caloiso4_etcone20_[itype].Fill(fin.lepton_calo_iso20[vecindex_sub1],fin.lepton_calo_iso20[vecindex_sub2], event_weight)
               self.h_isEM_caloiso3_vs_caloiso4_etcone30_[itype].Fill(fin.lepton_calo_iso30[vecindex_sub1],fin.lepton_calo_iso30[vecindex_sub2], event_weight)
               if fin.m_4l/1000. < 160 and not (fin.m_4l/1000. < 130 and fin.m_4l/1000. > 120):
                   #if itype == 1: print fin.EventNumber
                   self.h_isEM_caloiso3_vs_caloiso4_etcone20_lt160_[itype].Fill(fin.lepton_calo_iso20[vecindex_sub1],fin.lepton_calo_iso20[vecindex_sub2], event_weight)   
                   self.h_isEM_caloiso3_vs_caloiso4_etcone30_lt160_[itype].Fill(fin.lepton_calo_iso30[vecindex_sub1],fin.lepton_calo_iso30[vecindex_sub2], event_weight)


