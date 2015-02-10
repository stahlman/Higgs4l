#!/usr/bin/env python

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'Jan 2012'

#---------------------------------------------------------------------------
import os, sys, string, commands, math

if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

from datetime import datetime
from pprint import pprint
import math
from ROOT import *
#from array import array
import glob
from FitUtils import performMassFit

ROOT.gROOT.LoadMacro("AtlasStyle.C");
ROOT.gROOT.LoadMacro("AtlasUtils.C");
ROOT.gROOT.SetStyle("ATLAS");
ROOT.gROOT.ForceStyle();

#tag='2012'
#tag='2011'
tag='2011and2012'


inputDir2 = "/local_data1/stahlman/output/HSG2_output/06022013/";
inputDir = "/local_data1/stahlman/output/HSG2_output/Moriond/";
  
outputDir = inputDir + "Plots/";



#Retrieve MC histograms ------------------------------------------------------------------------------------------------------------
mc_fin  = TFile(inputDir2 + "ZZ_FullSelection_passed.root")

mc_file_names = []
mc_file_names.extend(glob.glob(inputDir + 'minitrees/v02/MC12a/*ZZ*.root'))
mc_file_names.extend(glob.glob(inputDir + 'minitrees/v02/MC11c/*ZZ*.root'))

mc_files = TFileCollection()
print "Using mc files:"
for mc_file in mc_file_names:
   print mc_file
   mc_files.Add(mc_file)


#Retrieve Data histograms ------------------------------------------------------------------------------------------------------------
print 'Retrieving data from files'

fin  = TFile(inputDir2 + "Data_FullSelection_passed.root")

data_files = TFileCollection()
data_files.Add(inputDir + "minitrees/v02/data12.root")
data_files.Add(inputDir + "minitrees/v02/data11.root")


#Open Output File ------------------------------------------------------------------------------------------------------------

fout = TFile(outputDir + "ZMassFit."+tag+".root", "RECREATE")
fout.cd()


#Perform Fit
a_vals = []
a_errs = []

params = []

doToys = false

fit_var = 'both'
performMassFit(tag,'4mu',  fit_var,data_files, mc_files, "shift", doToys, outputDir)
performMassFit(tag,'2mu2e',fit_var,data_files, mc_files, "shift", doToys, outputDir)
performMassFit(tag,'2e2mu',fit_var,data_files, mc_files, "shift", doToys, outputDir)
performMassFit(tag,'4e',   fit_var,data_files, mc_files, "shift", doToys, outputDir)

fit_var = 'm12'
performMassFit(tag,'4mu',  fit_var,data_files, mc_files, "shift", doToys, outputDir)
performMassFit(tag,'2mu2e',fit_var,data_files, mc_files, "shift", doToys, outputDir)
performMassFit(tag,'2e2mu',fit_var,data_files, mc_files, "shift", doToys, outputDir)
performMassFit(tag,'4e',   fit_var,data_files, mc_files, "shift", doToys, outputDir)

fit_var = 'm34'
performMassFit(tag,'4mu',  fit_var,data_files, mc_files, "shift", doToys, outputDir)
performMassFit(tag,'2mu2e',fit_var,data_files, mc_files, "shift", doToys, outputDir)
performMassFit(tag,'2e2mu',fit_var,data_files, mc_files, "shift", doToys, outputDir)
performMassFit(tag,'4e',   fit_var,data_files, mc_files, "shift", doToys, outputDir)





#performMassFit(data_chain_4e, mc_chain_4e, fit_var, "shift", doToys, outputDir)

#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "scale")

hist_name = 'h_m_mumu_4mu'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)

hist_name = 'h_m_mumu_2e2mu'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)

hist_name = 'h_m_mumu_2mu2e'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)

hist_name = 'h_m_ee'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "scale")

hist_name = 'h_m_ee_4e'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)

hist_name = 'h_m_ee_2e2mu'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)

hist_name = 'h_m_ee_2mu2e'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)

hist_name = 'h_m_4l'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", 60,120)

hist_name = 'h_m_4l_4mu'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", 60,120)

h_m_ee_mixed   = fin.Get('h_m_ee_2e2mu').Clone('h_m_ee_mixed')
h_m_ee_mixed.Add(fin.Get('h_m_ee_2e2mu'),fin.Get('h_m_ee_2mu2e'))
mch_m_ee_mixed   = mc_fin.Get('h_m_ee_2e2mu').Clone('mch_m_ee_mixed')
mch_m_ee_mixed.Add(mc_fin.Get('h_m_ee_2e2mu'),mc_fin.Get('h_m_ee_2mu2e'))
#performMassFit(h_m_ee_mixed, mch_m_ee_mixed, params, "shift", doToys, outputDir)


h_m_mumu_mixed   = fin.Get('h_m_mumu_2e2mu').Clone('h_m_mumu_mixed')
h_m_mumu_mixed.Add(fin.Get('h_m_mumu_2e2mu'),fin.Get('h_m_mumu_2mu2e'))
mch_m_mumu_mixed   = mc_fin.Get('h_m_mumu_2e2mu').Clone('mch_m_mumu_mixed')
mch_m_mumu_mixed.Add(mc_fin.Get('h_m_mumu_2e2mu'),mc_fin.Get('h_m_mumu_2mu2e'))
#performMassFit(h_m_mumu_mixed, mch_m_mumu_mixed, params, "shift", doToys, outputDir)

hist_name = 'h_highmass_m12_4mu'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)

hist_name = 'h_highmass_m34_4mu'
#performMassFit(fin.Get(hist_name), mc_fin.Get(hist_name), params, "shift", doToys, outputDir)




print 'Closing output file: ' + fout.GetPath().rstrip(':/')
fout.Close()
