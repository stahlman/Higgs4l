"""
Produce Fiducial cross section numbers
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'July 2013'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

import math
from numpy import *
from ROOT import *
#from ROOT import RooStats
#from RooStats import *
from PlotUtils import *
from AnalysisRoutines import *
from variables import *
import glob
import re


inputDir =  "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/stahlman_minitree_v05/";

inputDir_reducible_minitree =  "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/bkg_minitree_test_v05/";
inputDir_reducible =  '/home/stahlman/testarea/HZZllllDifferential/makeWS/inputs/'

outputDir = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Plots/v05/";
#outputDir = "/disk/userdata00/atlas_data2/stahlman/output/test/";

systematicDir   = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v03/"

fid_corrections_file_name = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Fiducial/v10/FiducialStudy.H120_H130.root"

def main():

   ROOT.gROOT.LoadMacro("AtlasStyle.C");
   ROOT.gROOT.LoadMacro("AtlasUtils.C");
   SetAtlasStyle()

   tag='test'

   for i in range(len(variables)):
   #for i in range(1,2):
     doMeasurement(i, tag)
  
   return

def doMeasurement(var, tag):

  var_name = variables[var]
  v_reco = var_mt[var]
  var_label_reco = var_labels_reco[var]
  var_label_truth = var_labels_truth[var]
  var_unit = var_units[var]
  v_bins = var_bins[var]
  v_ZZshape_from_CR1 = var_ZZshape_from_CR1[var]

  separateChannels = false
  doToys = false

  usePseudoData = false
  #preset = [12,8,2,1]

  #mass_window_lo = 115
  #mass_window_hi = 130

  mass_window_lo = 118
  mass_window_hi = 129

  mass_window_CR1_lo = 190

  mass_window_CR2_hi = 110
  
  mass_window_var = 'm4l_constrained'
  
  #Configurable inputs
  #------------------------------

  ggH_xsection  =  19.27 *1000 #fb
  VBFH_xsection =  1.578 *1000 #fb
  WH_xsection   = 0.7046 *1000 #fb
  ZH_xsection   = 0.4153 *1000 #fb
  ttH_xsection  = 0.1293 *1000 #fb
  
  name_mode     = ["ggH", "VBFH", "WH", "ZH", "ttH" ] 
  xsection_mode = [ggH_xsection, VBFH_xsection, WH_xsection, ZH_xsection, ttH_xsection]
  n_modes = len(name_mode)
  label_mode   = ["#it{gg}F", "VBF", "#it{WH}", "#it{ZH}", "#it{t#bar{t}H}" ] 
  
  total_xsection = sum(xsection_mode) 

  #branching_ratio = 0.000125 #BR for H->4l; l=e,mu
  branching_ratio = 0.000276 #BR for H->4l; l=e,mu, tau

  lumi = 20.277  #fb-1
  lumi_syst = 3.6 #% systematic on luminosity

  bins = array('d', v_bins)
  n_bins = len(bins)-1 

  bins_CR1 = array('d', var_bins_CR1[var])
  n_bins_CR1 = len(bins_CR1)-1 

  tree_name = "inclusive"

  signal_SF = 1.

  channels = ["4mu", "4e", "2mu2e", "2e2mu"]

  #TODO FINAL NUMBERS - Input from main analysis
  reducible_bkg_fullmass_yield      = [2.5, 1.503, 1.668,   2.6 ] #per channel yield
  reducible_bkg_fullmass_yield_stat = [0.5, 0.113, 0.111,   0.5 ] #per channel yield stat unc.
  reducible_bkg_fullmass_yield_syst = [0.6,   0.6,   0.6,   0.6 ] #per channel yield syst unc.

  hzz_label = 'H #rightarrow ZZ* #rightarrow 4#font[12]{l}'
  atlas_label_text = 'Internal'
  label = "#sqrt{s} = 8 TeV: #int L dt = 20.3 fb^{-1}"

  #make dummy histogram for njets 
  h_jets = TH1F('dummy','',4,-0.5,3.5)
  h_jets.GetXaxis().SetBinLabel(1,'0');
  h_jets.GetXaxis().SetBinLabel(2,'1');
  h_jets.GetXaxis().SetBinLabel(3,'2');
  h_jets.GetXaxis().SetBinLabel(4,'#geq 3');
  h_jets.GetXaxis().SetLabelSize(0.07);
  h_jets.GetXaxis().SetNdivisions(503,false)
  h_jets.SetStats(false)

  #Find input ------------------------------------------------------------------------------------------------------------

  ZZ_file_names = []
  ZZ_file_names.extend(glob.glob(inputDir + '/*CT10_ZZ*.root'))

  print "Using ZZ files:"
  for f in ZZ_file_names: print '\t',f

  ggZZ_file_names = []
  ggZZ_file_names.extend(glob.glob(inputDir + '/*gg2ZZ*.root'))

  qqZZ_file_names = []
  qqZZ_file_names.extend(glob.glob(inputDir + '/*PowhegPythia8_AU2CT10_ZZ*.root'))

  red_file_names = []
  red_file_names.extend(glob.glob(inputDir + '/*Zbb*.root'))

  print "Using Zbb files:"
  for f in red_file_names: print '\t',f

  red_mu_file_names = []
  red_mu_file_names.append(inputDir_reducible_minitree + "/mc12_redBkg.root")
  
  print "Using reducible muon files:"
  for f in red_mu_file_names: print '\t',f

  red_el_file_names = []
  red_el_file_names.extend(glob.glob(inputDir_reducible_minitree + "/mc12_redBkg.root"))
  
  print "Using reducible electron files:"
  for f in red_el_file_names: print '\t',f

  signal_file_names = []
  signal_file_names.extend(glob.glob(inputDir + '/*H125*.root'))

  print "Using signal files:"
  for f in signal_file_names: print '\t',f
  
  mode_file_names = []
  for mode in name_mode: mode_file_names.append( glob.glob(inputDir + '/*'+mode+'125*.root'))

  data_file_names = []
  data_file_names.extend(glob.glob(inputDir + '/data12.root'))

  print "Using data files:"
  for f in data_file_names: print '\t',f

  print "Using fiducial corrections file:"
  print '\t',fid_corrections_file_name
  fid_correction_file = TFile( fid_corrections_file_name, "READ")
  
  #use inclusive normalization systematics file if jet variable  
  ZZ_bkg_syst_file = systematicDir+ "/Systematics."+('inclusive' if var_jet[var] else var_name)+".ZZ.inclusive.txt"
  print "Using ZZ background systematics file:"
  print '\t', ZZ_bkg_syst_file
  ZZ_bkg_syst_names = loadtxt(ZZ_bkg_syst_file, usecols=[0], dtype=string)
  ZZ_bkg_syst_vals  = loadtxt(ZZ_bkg_syst_file, usecols=range(1, 2 if var_jet[var] else n_bins+1))

  red_bkg_syst_file = systematicDir+ "/Systematics."+var_name+".Reducible.inclusive.txt"
  print "Using red background systematics file:"
  print '\t',red_bkg_syst_file
  red_bkg_syst_names = loadtxt(red_bkg_syst_file, usecols=[0], dtype=string)
  red_bkg_syst_vals  = loadtxt(red_bkg_syst_file, usecols=range(1,n_bins+1))

  signal_syst_file = systematicDir+ "/Systematics."+var_name+".H125.inclusive.txt"
  print "Using signal systematics file:"
  print '\t',signal_syst_file
  signal_syst_names = loadtxt(signal_syst_file, usecols=[0], dtype=string)
  signal_syst_vals  = loadtxt(signal_syst_file, usecols=range(1,n_bins+1))

#  ZZ_bkg_syst_names_  = []
#  ZZ_bkg_syst_vals_   = []
#  red_bkg_syst_names_ = []
#  red_bkg_syst_vals_  = []

#  for channel in channels:
#     syst_file = systematicDir+'/Systematics.'+var_name+'.ZZ.'+channel+'.txt'
#     ZZ_bkg_syst_names_.append( loadtxt(syst_file, usecols=[0], dtype=string))
#     ZZ_bkg_syst_vals_.append(  loadtxt(syst_file, usecols=range(1,n_bins+1)))
#
#     syst_file = systematicDir+'/Systematics.'+var_name+'.Reducible.'+channel+'.txt'
#     red_bkg_syst_names_.append( loadtxt(syst_file, usecols=[0], dtype=string))
#     red_bkg_syst_vals_.append(  loadtxt(syst_file, usecols=range(1,n_bins+1)))
#
#     #signal_syst_names = loadtxt(signal_syst_file, usecols=[0], dtype=string)
#     #signal_syst_vals  = loadtxt(signal_syst_file, usecols=range(1,n_bins+1))


  #Retrieve trees ------------------------------------------------------------------------------------------------------------
  print 'Retrieving trees from files'

  ZZ_chain     = GetChain(tree_name, ZZ_file_names)
  qqZZ_chain   = GetChain(tree_name, qqZZ_file_names)
  ggZZ_chain   = GetChain(tree_name, ggZZ_file_names)
  red_mc_chain = GetChain("mt_muon", red_file_names)
  red_mu_chain = GetChain("mt_muon", red_mu_file_names)
  red_el_chain = GetChain("mt_electron", red_el_file_names)
  signal_chain = GetChain(tree_name, signal_file_names)
  data_chain   = GetChain(tree_name, data_file_names)

  signal_mode_chain = []
  for files in mode_file_names:  signal_mode_chain.append(GetChain(tree_name, files))

  ZZ_chain_    = []
  red_mu_chain_= []
  signal_chain_= []

  for channel in channels:
    ZZ_chain_.append(    GetChain('tree_incl_'+channel, ZZ_file_names))
    red_mu_chain_.append(   GetChain('tree_incl_'+channel, red_file_names))
    signal_chain_.append(GetChain('tree_incl_'+channel, signal_file_names))

  #Open Output File ------------------------------------------------------------------------------------------------------------

  fout = TFile(outputDir + "DifferentialMeasurement."+var_name+'.'+tag+".root", "RECREATE")
  fout.cd()

  #Create Histograms
  #------------------------------

  hists = []

  x_label_reco  = var_label_reco  + (' ['+var_unit+']' if var_unit != "" else "")
  x_label_truth = var_label_truth + (' ['+var_unit+']' if var_unit != "" else "")

  #signal
  h_signal_yield         = TH1F("h_signal_yield",	 ";"+x_label_reco+";Events",	n_bins, bins);hists.append(h_signal_yield)
  h_signal_yield_syst    = TH1F("h_signal_yield_syst",	 ";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_signal_yield_syst)
  h_signal_yield_syst_up = TH1F("h_signal_yield_syst_up",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_signal_yield_syst_up)
  h_signal_yield_syst_dn = TH1F("h_signal_yield_syst_dn",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_signal_yield_syst_dn)

  h_signal_total_xsection      = TH1F("h_signal_total_xsection",     ";"+x_label_truth+";d#sigma_{tot}/d "+var_label_truth+" [fb"+("/"+var_unit if var_unit != "" else "")+"]",n_bins, bins);hists.append(h_signal_total_xsection)
  h_signal_total_xsection_syst = TH1F("h_signal_total_xsection_syst",";"+x_label_truth+";systematic",n_bins, bins);hists.append(h_signal_total_xsection_syst)

  h_signal_fiducial_xsection      = TH1F("h_signal_fiducial_xsection",";"+x_label_truth+";d#sigma_{fid}/d "+var_label_truth+" [fb"+("/"+var_unit if var_unit != "" else "")+"]",n_bins, bins);hists.append(h_signal_fiducial_xsection)
  h_signal_fiducial_xsection_syst = TH1F("h_signal_fiducial_xsection_syst",";"+x_label_truth+";systematic",n_bins, bins);hists.append(h_signal_fiducial_xsection_syst)

  h_signal_yield_CR1      = TH1F("h_signal_yield_CR1",	   ";"+x_label_reco+";Events",n_bins_CR1, bins_CR1);hists.append(h_signal_yield_CR1)
  h_signal_yield_CR1_syst = TH1F("h_signal_yield_CR1_syst",";"+x_label_reco+";systematic",n_bins_CR1, bins_CR1);hists.append(h_signal_yield_CR1_syst)

  h_signal_yield_CR2      = TH1F("h_signal_yield_CR2",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_signal_yield_CR2)
  h_signal_yield_CR2_syst = TH1F("h_signal_yield_CR2_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_signal_yield_CR2_syst)

  #backgrounds
  h_ZZ_yield          = TH1F("h_ZZ_yield", ";"+x_label_reco+";Events",n_bins, bins);hists.append(h_ZZ_yield)
  h_ZZ_yield_syst     = TH1F("h_ZZ_yield_syst", ";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_ZZ_yield_syst)
  h_ZZ_yield_syst_up  = TH1F("h_ZZ_yield_syst_up", ";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_ZZ_yield_syst_up)
  h_ZZ_yield_syst_dn  = TH1F("h_ZZ_yield_syst_dn", ";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_ZZ_yield_syst_dn)

  h_qqZZ_yield        = TH1F("h_qqZZ_yield", ";"+x_label_reco+";Events",n_bins, bins);hists.append(h_qqZZ_yield)
  h_ggZZ_yield        = TH1F("h_ggZZ_yield", ";"+x_label_reco+";Events",n_bins, bins);hists.append(h_ggZZ_yield)

  h_red_el_yield      = TH1F("h_red_el_yield",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_red_el_yield)
  h_red_el_yield_syst_up = TH1F("h_red_el_yield_syst_up",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_el_yield_syst_up)
  h_red_el_yield_syst_dn = TH1F("h_red_el_yield_syst_dn",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_el_yield_syst_dn)

  h_red_mu_yield      = TH1F("h_red_mu_yield",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_red_mu_yield)
  h_red_mu_yield_syst = TH1F("h_red_mu_yield_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_mu_yield_syst)
  h_red_mu_yield_syst_up = TH1F("h_red_mu_yield_syst_up",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_mu_yield_syst_up)
  h_red_mu_yield_syst_dn = TH1F("h_red_mu_yield_syst_dn",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_mu_yield_syst_dn)

  h_red_yield      = TH1F("h_red_yield",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_red_yield)
  h_red_yield_syst = TH1F("h_red_yield_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_yield_syst)
  h_red_yield_syst_up = TH1F("h_red_yield_syst_up",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_yield_syst_up)
  h_red_yield_syst_dn = TH1F("h_red_yield_syst_dn",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_yield_syst_dn)

  h_mass_red_mu_yield = TH1F("h_mass_red_mu_yield",";m_{4l};Events",400, 0, 400);hists.append(h_mass_red_mu_yield)
  h_mass_red_el_yield = TH1F("h_mass_red_el_yield",";m_{4l};Events",400, 0, 400);hists.append(h_mass_red_el_yield)

  h_ZZ_yield_CR1       = TH1F("h_ZZ_yield_CR1", ";"+x_label_reco+";Events",n_bins_CR1, bins_CR1);hists.append(h_ZZ_yield_CR1)
  h_ZZ_yield_CR1_syst  = TH1F("h_ZZ_yield_CR1_syst", ";"+x_label_reco+";systematic",n_bins_CR1, bins_CR1);hists.append(h_ZZ_yield_CR1_syst)

  h_red_mu_yield_CR1      = TH1F("h_red_mu_yield_CR1",";"+x_label_reco+";Events",n_bins_CR1, bins_CR1);hists.append(h_red_mu_yield_CR1)
  h_red_mu_yield_CR1_syst = TH1F("h_red_mu_yield_CR1_syst",";"+x_label_reco+";systematic",n_bins_CR1, bins_CR1);hists.append(h_red_mu_yield_CR1_syst)

  h_red_el_yield_CR1      = TH1F("h_red_el_yield_CR1",";"+x_label_reco+";Events",n_bins_CR1, bins_CR1);hists.append(h_red_el_yield_CR1)
  h_red_el_yield_CR1_syst = TH1F("h_red_el_yield_CR1_syst",";"+x_label_reco+";systematic",n_bins_CR1, bins_CR1);hists.append(h_red_el_yield_CR1_syst)

  h_red_yield_CR1      = TH1F("h_red_yield_CR1",";"+x_label_reco+";Events",n_bins_CR1, bins_CR1);hists.append(h_red_yield_CR1)
  h_red_yield_CR1_syst = TH1F("h_red_yield_CR1_syst",";"+x_label_reco+";systematic",n_bins_CR1, bins_CR1);hists.append(h_red_yield_CR1_syst)

  h_ZZ_yield_CR2       = TH1F("h_ZZ_yield_CR2", ";"+x_label_reco+";Events",n_bins, bins);hists.append(h_ZZ_yield_CR2)
  h_ZZ_yield_CR2_syst  = TH1F("h_ZZ_yield_CR2_syst", ";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_ZZ_yield_CR2_syst)

  h_red_mu_yield_CR2      = TH1F("h_red_mu_yield_CR2",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_red_mu_yield_CR2)
  h_red_mu_yield_CR2_syst = TH1F("h_red_mu_yield_CR2_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_mu_yield_CR2_syst)

  h_red_el_yield_CR2      = TH1F("h_red_el_yield_CR2",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_red_el_yield_CR2)
  h_red_el_yield_CR2_syst = TH1F("h_red_el_yield_CR2_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_el_yield_CR2_syst)

  h_red_yield_CR2      = TH1F("h_red_yield_CR2",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_red_yield_CR2)
  h_red_yield_CR2_syst = TH1F("h_red_yield_CR2_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_red_yield_CR2_syst)

  h_red_mc_yield      = TH1F("h_red_mc_yield",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_red_mc_yield)

  #data
  h_data_yield     = TH1F("h_data_yield",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_data_yield)
  h_data_yield_CR1 = TH1F("h_data_yield_CR1",";"+x_label_reco+";Events",n_bins_CR1, bins_CR1);hists.append(h_data_yield_CR1)
  h_data_yield_CR2 = TH1F("h_data_yield_CR2",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_data_yield_CR2)

  #derived hists
  h_background_yield         = TH1F("h_background_yield",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_background_yield)
  h_background_yield_syst    = TH1F("h_background_yield_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_background_yield_syst)
  h_background_yield_syst_up = TH1F("h_background_yield_syst_up",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_background_yield_syst_up)
  h_background_yield_syst_dn = TH1F("h_background_yield_syst_dn",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_background_yield_syst_dn)

  h_observed_yield           = TH1F("h_observed_yield",";"+x_label_reco+";Data-Background",n_bins, bins);hists.append(h_observed_yield)
  h_observed_yield_syst      = TH1F("h_observed_yield_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_observed_yield_syst)
  h_observed_yield_syst_up   = TH1F("h_observed_yield_syst_up",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_observed_yield_syst_up)
  h_observed_yield_syst_dn   = TH1F("h_observed_yield_syst_dn",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_observed_yield_syst_dn)
  h_observed_yield_perr      = TGraphAsymmErrors(n_bins);h_observed_yield_perr.SetName('h_observed_yield_perr'); hists.append(h_observed_yield_perr)

  h_observed_xsection         = TH1F("h_observed_xsection",";"+x_label_truth+";d#sigma_{fid}/d "+var_label_truth+" [fb"+("/"+var_unit if var_unit != "" else "")+"]",n_bins, bins);hists.append(h_observed_xsection)
  h_observed_xsection_syst    = TH1F("h_observed_xsection_syst",";"+x_label_truth+";systematic",n_bins, bins);hists.append(h_observed_xsection_syst)
  h_observed_xsection_syst_up = TH1F("h_observed_xsection_syst_up",";"+x_label_truth+";systematic",n_bins, bins);hists.append(h_observed_xsection_syst_up)
  h_observed_xsection_syst_dn = TH1F("h_observed_xsection_syst_dn",";"+x_label_truth+";systematic",n_bins, bins);hists.append(h_observed_xsection_syst_dn)
  h_observed_xsection_perr    = TGraphAsymmErrors(n_bins);h_observed_xsection_perr.SetName('h_observed_xsection_perr'); hists.append(h_observed_xsection_perr)

  h_background_yield_CR1      = TH1F("h_background_yield_CR1",";"+x_label_reco+";Events",n_bins_CR1, bins_CR1);hists.append(h_background_yield_CR1)
  h_background_yield_CR1_syst = TH1F("h_background_yield_CR1_syst",";"+x_label_reco+";systematic",n_bins_CR1, bins_CR1);hists.append(h_background_yield_CR1_syst)

  h_observed_yield_CR1        = TH1F("h_observed_yield_CR1",";"+x_label_reco+";Data-Background",n_bins_CR1, bins_CR1);hists.append(h_observed_yield_CR1)
  h_observed_yield_CR1_syst   = TH1F("h_observed_yield_CR1_syst",";"+x_label_reco+";systematic",n_bins_CR1, bins_CR1);hists.append(h_observed_yield_CR1_syst)
  h_observed_yield_CR1_perr   = TGraphAsymmErrors(n_bins); h_observed_yield_CR1_perr.SetName('h_observed_yield_CR1_perr');hists.append(h_observed_yield_CR1_perr)

  h_background_yield_CR2      = TH1F("h_background_yield_CR2",";"+x_label_reco+";Events",n_bins, bins);hists.append(h_background_yield_CR2)
  h_background_yield_CR2_syst = TH1F("h_background_yield_CR2_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_background_yield_CR2_syst)

  h_observed_yield_CR2        = TH1F("h_observed_yield_CR2",";"+x_label_reco+";Data-Background",n_bins, bins);hists.append(h_observed_yield_CR2)
  h_observed_yield_CR2_syst   = TH1F("h_observed_yield_CR2_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_observed_yield_CR2_syst)
  h_observed_yield_CR2_perr   = TGraphAsymmErrors(n_bins);h_observed_yield_CR2_perr.SetName('h_observed_yield_CR2_perr'); hists.append(h_observed_yield_CR2_perr)

  #fiducial corrections
  h_signal_yield_mode = []
  h_fid_efficiency_mode = []
  h_fid_acceptance_mode = []
  h_gen_mode = []
  for i in range(n_modes):
    mode = name_mode[i]
    
    h_signal_yield_mode.append( TH1F("h_signal_yield_"+mode,";"+x_label_reco+";Events",	n_bins, bins));hists.append(h_signal_yield_mode[i])
        
    hist = fid_correction_file.Get( mode + "125/h_"+var_name+"_fiducial_efficiency").Clone('h_fiducial_efficiency_'+name_mode[i])
    h_fid_efficiency_mode.append( hist ); hists.append( hist )
    
    hist = fid_correction_file.Get( mode + "125/h_"+var_name+"_fiducial_acceptance").Clone('h_fiducial_acceptance_'+name_mode[i])
    h_fid_acceptance_mode.append( hist ); hists.append( hist )

    hist = fid_correction_file.Get( mode + "125/h_"+var_name+"_gen").Clone('h_gen_'+name_mode[i])
    h_gen_mode.append( hist ); hists.append( hist )
 
  h_fid_efficiency          = TH1F("h_fid_efficiency",";"+x_label_reco+";Fiducial Efficiency",n_bins, bins);hists.append(h_fid_efficiency)
  h_fid_efficiency_syst     = TH1F("h_fid_efficiency_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_fid_efficiency_syst)
  h_fid_efficiency_syst_up  = TH1F("h_fid_efficiency_syst_up",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_fid_efficiency_syst_up)
  h_fid_efficiency_syst_dn  = TH1F("h_fid_efficiency_syst_dn",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_fid_efficiency_syst_dn)

  h_fid_acceptance          = TH1F("h_fid_acceptance",";"+x_label_reco+";Fiducial Acceptance",n_bins, bins);hists.append(h_fid_acceptance)
  h_fid_acceptance_syst     = TH1F("h_fid_acceptance_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_fid_acceptance_syst)

  h_correction_factor      = TH1F("h_correction_factor",";"+x_label_reco+";Correction Factor",n_bins, bins);hists.append(h_correction_factor)
  h_correction_factor_syst = TH1F("h_correction_factor_syst",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_correction_factor_syst)
  h_correction_factor_syst_up = TH1F("h_correction_factor_syst_up",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_correction_factor_syst_up)
  h_correction_factor_syst_dn = TH1F("h_correction_factor_syst_dn",";"+x_label_reco+";systematic",n_bins, bins);hists.append(h_correction_factor_syst_dn)

  h_signal_yield_ = []
  h_signal_yield_syst_ = []
  h_ZZ_yield_ = []
  #h_ZZ_yield_syst_ = []
  h_red_yield_ = []
  #h_red_yield_syst_ = []
  h_background_yield_ = []  
  h_background_yield_syst_ = []

  for i in range(len(channels)):
    #signal
    h_signal_yield_.append(      TH1F("h_signal_yield_"+channels[i],";"+x_label_reco+";Events",n_bins, bins)); hists.append(h_signal_yield_[i])
    h_signal_yield_syst_.append( TH1F("h_signal_yield_syst_"+channels[i],";"+x_label_reco+";systematic",n_bins, bins)); hists.append(h_signal_yield_syst_[i])

    #backgrounds
    h_ZZ_yield_.append(       TH1F("h_ZZ_yield_"+channels[i], ";"+x_label_reco+";Events",n_bins, bins))
    #h_ZZ_yield_syst_.append(  TH1F("h_ZZ_yield_syst_"+channels[i], ";"+x_label_reco+";systematic",n_bins, bins))

    h_red_yield_.append(      TH1F("h_red_yield_"+channels[i],";"+x_label_reco+";Events",n_bins, bins))
    #h_red_yield_syst_.append( TH1F("h_red_yield_syst_"+channels[i],";"+x_label_reco+";systematic",n_bins, bins))

    #derived hists
    h_background_yield_.append(      TH1F("h_background_yield_"+channels[i],";"+x_label_reco+";Events",n_bins, bins)); hists.append(h_background_yield_[i])
    h_background_yield_syst_.append( TH1F("h_background_yield_syst_"+channels[i],";"+x_label_reco+";systematic",n_bins, bins)); hists.append(h_background_yield_syst_[i])

  for hist in hists: 
    if not hist.InheritsFrom("TH1"): continue    
    hist.Sumw2()

  #Fill Histograms
  #------------------------------
  print "Filling Histograms using variable", v_reco

  mass_window = "(("+mass_window_var+" < " + str(mass_window_hi) + ")&&("+mass_window_var+" > " + str(mass_window_lo)+"))"
  mass_window_CR1 = "("+mass_window_var+" > " + str(mass_window_CR1_lo)+")"
  mass_window_CR2 = "("+mass_window_var+" < " + str(mass_window_CR2_hi)+")"

  #------------------------------
  #ZZ Estimate
  #------------------------------
  ZZ_chain.Draw(v_reco+" >> h_ZZ_yield", "weight*"+mass_window, "goff");  
  ZZ_chain.Draw(v_reco+" >> h_ZZ_yield_CR1", "weight*"+mass_window_CR1, "goff");
  ZZ_chain.Draw(v_reco+" >> h_ZZ_yield_CR2", "weight*"+mass_window_CR2, "goff");
  
  qqZZ_chain.Draw(v_reco+" >> h_qqZZ_yield", "weight*"+mass_window, "goff");  
  ggZZ_chain.Draw(v_reco+" >> h_ggZZ_yield", "weight*"+mass_window, "goff");  

  #------------------------------
  #Reducible Estimate
  #------------------------------
  
  #Muon channels estimate  
  #------------------------------
  #Draw from MC chain for shape
#  #red_mu_chain.Draw(v_reco+" >> h_red_mu_yield",     "weight*"+mass_window,     "goff");
#  red_mc_chain.Draw(v_reco+" >> h_red_mu_yield",     "weight*"+mass_window,     "goff");
#  red_mu_chain.Draw(v_reco+" >> h_red_mu_yield_CR1", "weight*"+mass_window_CR1, "goff");
#  red_mu_chain.Draw(v_reco+" >> h_red_mu_yield_CR2", "weight*"+mass_window_CR2, "goff");
#  #red_mu_chain.Draw(mass_window_var+' >> h_mass_red_mu_yield', "weight", "goff")
#  red_mc_chain.Draw(mass_window_var+' >> h_mass_red_mu_yield', "weight", "goff")
#  
#  h_total = TH1F("h_total", '', 1,0.5,1.5); h_total.Sumw2()
#  h_mw    = TH1F("h_mw", '', 1,0.5,1.5); h_mw.Sumw2()
#  h_fraction    = TH1F("h_fraction", '', 1,0.5,1.5); h_fraction.Sumw2()
#
#  red_mu_chain.Draw('1 >> h_total', "weight", "goff")
#  red_mu_chain.Draw('1 >> h_mw', "weight*"+mass_window, "goff")
#  
#  h_fraction.Divide(h_mw,h_total, 1,1,"B")
#  
#  #calculate normalization within mass windows
#  h_mass_red_mu_shape = Shape( h_mass_red_mu_yield , 'h_mass_red_mu_shape') 
#  red_mu_mass_window_fraction_err = Double(0)
#  red_mu_mass_window_fraction     = h_mass_red_mu_shape.IntegralAndError(mass_window_lo+1,mass_window_hi, red_mu_mass_window_fraction_err)
#  red_mu_mass_window_fraction_CR1 = h_mass_red_mu_shape.Integral(mass_window_CR1_lo+1,h_mass_red_mu_shape.GetNbinsX()+1)
#  red_mu_mass_window_fraction_CR2 = h_mass_red_mu_shape.Integral(0,mass_window_CR2_hi)
#  
#  #print "Raw number of events in reducible muon control region:",red_mu_chain.GetEntries(mass_window)
#
#  print "Reducible muon mass window fractions:"
#  print "Signal Region:",   red_mu_mass_window_fraction, '+/-',red_mu_mass_window_fraction_err
#  print "Alternate:",  h_fraction[1], h_fraction.GetBinError(1)
#  print "Control Region 1:",red_mu_mass_window_fraction_CR1
#  print "Control Region 2:",red_mu_mass_window_fraction_CR2
#  
#  tot_red_mu_yield      = reducible_bkg_fullmass_yield[0]+reducible_bkg_fullmass_yield[3]
#  red_mu_yield	   = tot_red_mu_yield*red_mu_mass_window_fraction
#  red_mu_yield_CR1 = tot_red_mu_yield*red_mu_mass_window_fraction_CR1
#  red_mu_yield_CR2 = tot_red_mu_yield*red_mu_mass_window_fraction_CR2
#
#  #normalize muon channel histograms
#  red_integral = h_red_mu_yield.Integral(0,h_red_mu_yield.GetNbinsX()+1)
#  if(red_integral != 0 and red_mu_yield != 0): h_red_mu_yield.Scale(red_mu_yield/red_integral)
#
#  red_integral_CR1 = h_red_mu_yield_CR1.Integral(0,h_red_mu_yield_CR1.GetNbinsX()+1)
#  if(red_integral_CR1 != 0 and red_mu_yield_CR1 != 0): h_red_mu_yield_CR1.Scale(red_mu_yield_CR1/red_integral_CR1)
#
#  red_integral_CR2 = h_red_mu_yield_CR2.Integral(0,h_red_mu_yield_CR2.GetNbinsX()+1)
#  if(red_integral_CR2 != 0 and red_mu_yield_CR2 != 0): h_red_mu_yield_CR2.Scale(red_mu_yield_CR2/red_integral_CR2)
  
  f_red_mu = open(inputDir_reducible+'/WorkspaceInput.'+var_name+'.Reducible_mm.txt', 'r')
  vals = (f_red_mu.readline()).split()
  for i in range(1,n_bins+1): h_red_mu_yield[i] = float(vals[i])
  
  red_mu_chain.Draw(v_reco+' >> h_red_mu_yield_CR1', "weight*"+mass_window_CR1, "goff")

  #Electron Channels estimate
  #------------------------------
#  #mass_window_alt = "(m4l_constrained<129000 && m4l_constrained>118000)"
#  #red_el_chain.Draw(v_reco+" >> h_red_el_yield",     "TransferFactor*weight*"+mass_window_alt,     "goff");
#  red_mc_chain.Draw(v_reco+" >> h_red_el_yield",     "weight*"+mass_window,     "goff");
#  #red_el_chain.Draw(v_reco+" >> h_red_el_yield",     "TransferFactor*weight*"+mass_window,     "goff");
#  red_el_chain.Draw(v_reco+" >> h_red_el_yield_CR1", "TransferFactor*weight*"+mass_window_CR1, "goff");
#  red_el_chain.Draw(v_reco+" >> h_red_el_yield_CR2", "TransferFactor*weight*"+mass_window_CR2, "goff");
#  red_el_chain.Draw(mass_window_var+' >> h_mass_red_el_yield', "TransferFactor*weight", "goff")
#  red_mc_chain.Draw(mass_window_var+' >> h_mass_red_el_yield', "weight", "goff")
#  
#  #calculate normalization within mass windows
#  h_mass_red_el_shape = Shape( h_mass_red_el_yield , 'h_mass_red_el_shape') 
#  red_el_mass_window_fraction_err = Double(0)
#  red_el_mass_window_fraction     = h_mass_red_el_shape.IntegralAndError(mass_window_lo+1,mass_window_hi, red_el_mass_window_fraction_err)
#  red_el_mass_window_fraction_CR1 = h_mass_red_el_shape.Integral(mass_window_CR1_lo+1,h_mass_red_el_shape.GetNbinsX()+1)
#  red_el_mass_window_fraction_CR2 = h_mass_red_el_shape.Integral(0,mass_window_CR2_hi)
#
#  print "Raw number of events in reducible electron control region (no mass window):",red_el_chain.GetEntries()
#  print "Raw number of events in reducible electron control region (with mass window):",red_el_chain.GetEntries(mass_window)
#
#  print "Reducible electron mass window fractions:"
#  print "Signal Region:",   red_el_mass_window_fraction, '+/-',red_el_mass_window_fraction_err
#  print "Control Region 1:",red_el_mass_window_fraction_CR1
#  print "Control Region 2:",red_el_mass_window_fraction_CR2
#  
#  tot_red_el_yield = reducible_bkg_fullmass_yield[1]+reducible_bkg_fullmass_yield[2]
#  red_el_yield	   = tot_red_el_yield*red_el_mass_window_fraction
#  red_el_yield_CR1 = tot_red_el_yield*red_el_mass_window_fraction_CR1
#  red_el_yield_CR2 = tot_red_el_yield*red_el_mass_window_fraction_CR2
#
#  #normalize muon channel histograms
#  red_integral = h_red_el_yield.Integral(0,h_red_el_yield.GetNbinsX()+1)
#  if(red_integral != 0 and red_el_yield != 0): h_red_el_yield.Scale(red_el_yield/red_integral)
#
#  red_integral_CR1 = h_red_el_yield_CR1.Integral(0,h_red_el_yield_CR1.GetNbinsX()+1)
#  if(red_integral_CR1 != 0 and red_el_yield_CR1 != 0): h_red_el_yield_CR1.Scale(red_el_yield_CR1/red_integral_CR1)
#
#  red_integral_CR2 = h_red_el_yield_CR2.Integral(0,h_red_el_yield_CR2.GetNbinsX()+1)
#  if(red_integral_CR2 != 0 and red_el_yield_CR2 != 0): h_red_el_yield_CR2.Scale(red_el_yield_CR2/red_integral_CR2)

  f_red_e = open(inputDir_reducible+'/WorkspaceInput.'+var_name+'.Reducible_ee.txt', 'r')
  vals = (f_red_e.readline()).split()
  for i in range(1,n_bins+1): h_red_el_yield[i] = float(vals[i])
  
  red_el_chain.Draw(v_reco+' >> h_red_el_yield_CR1', "weight*"+mass_window_CR1, "goff")
  
  #------------------------------
  #add muon and electron channel contributions
  #------------------------------
  h_red_yield.Add(h_red_mu_yield)
  h_red_yield.Add(h_red_el_yield)
  
  h_red_yield_CR1.Add(h_red_mu_yield_CR1)
  h_red_yield_CR1.Add(h_red_el_yield_CR1)

  h_red_yield_CR2.Add(h_red_mu_yield_CR2)
  h_red_yield_CR2.Add(h_red_el_yield_CR2)
  
  #------------------------------
  #check reducible shape in mc
  #------------------------------
  red_mc_chain.Draw(v_reco+" >> h_red_mc_yield",  "weight*"+mass_window,     "goff");

  #------------------------------
  # Signal estimate
  #------------------------------
  signal_chain.Draw(v_reco+" >> h_signal_yield",     "weight*"+mass_window+"*"+str(signal_SF),     "goff");
  signal_chain.Draw(v_reco+" >> h_signal_yield_CR1", "weight*"+mass_window_CR1+"*"+str(signal_SF), "goff");
  signal_chain.Draw(v_reco+" >> h_signal_yield_CR2", "weight*"+mass_window_CR2+"*"+str(signal_SF), "goff");
  
  for i in range(n_modes):
    signal_mode_chain[i].Draw(v_reco+" >> h_signal_yield_"+name_mode[i],     "weight*"+mass_window+"*"+str(signal_SF),     "goff");

  #------------------------------
  # Data 
  #------------------------------
  if (usePseudoData):
    #signal_chain.Draw(v_reco+" >> h_data_yield", "weight*"+mass_window+"*"+str(signal_SF), "goff");
    for i in range(h_data_yield.GetNbinsX()+2):
       h_data_yield[i] = random.poisson(h_ZZ_yield[i]+h_red_yield[i]+h_signal_yield[i])    
       #h_data_yield[i] = preset[i]    
  else:
    data_chain.Draw( v_reco+" >> h_data_yield", mass_window, "goff");

  data_chain.Draw( v_reco+" >> h_data_yield_CR1", mass_window_CR1, "goff");
  data_chain.Draw( v_reco+" >> h_data_yield_CR2", mass_window_CR2, "goff");

  h_data_yield_perr     = PoissonGraph(h_data_yield,     'h_data_yield_perr'); hists.append(h_data_yield_perr)
  h_data_yield_CR1_perr = PoissonGraph(h_data_yield_CR1, 'h_data_yield_CR1_perr'); hists.append(h_data_yield_CR1_perr)
  h_data_yield_CR2_perr = PoissonGraph(h_data_yield_CR2, 'h_data_yield_CR2_perr'); hists.append(h_data_yield_CR2_perr)

  #------------------------------

  for i in range(len(channels)):

    ZZ_chain_[i].Draw( v_reco+" >> h_ZZ_yield_"+channels[i],  "weight*"+mass_window, "goff");

    #TODO Assume same reducible shape for all channels 
    #red_mu_chain.Draw(v_reco+" >> h_red_yield_"+channels[i], "weight*"+mass_window, "goff");

    signal_chain_[i].Draw(v_reco+" >> h_signal_yield_"+channels[i], "weight*"+mass_window+'*'+str(signal_SF), "goff");

    #TODO - approximation - using average mass window fraction instead of channel-by-channel
    #reducible_bkg_yield = reducible_bkg_fullmass_yield[i]*red_mu_mass_window_fraction

    #red_integral = h_red_yield_[i].Integral()
    #if(red_integral != 0 and reducible_bkg_yield != 0): h_red_yield_[i].Scale(reducible_bkg_yield/red_integral)


  #------------------------------
  #Fiducial efficiency
  #------------------------------
  for i in range(n_modes):
    h_fid_efficiency.Add(h_fid_efficiency_mode[i],  xsection_mode[i]/total_xsection)

  #------------------------------
  #Fiducial acceptance
  #------------------------------
  for i in range(n_modes):
    h_fid_acceptance.Add(h_fid_acceptance_mode[i],  xsection_mode[i]/total_xsection)


  #------------------------------
  # Total cross section   
  #------------------------------
  for i in range(n_modes):
    total_gen  = h_gen_mode[i].Integral(0,n_bins+1)
    hist       = h_gen_mode[i].Clone("h_xsection_"+name_mode[i]); hists.append(hist)
    hist.Scale( xsection_mode[i] / total_gen )    
    h_signal_total_xsection.Add( hist )

  for i in range(n_bins):

    bin_width = bins[i+1] - bins[i]
        
    val = h_signal_total_xsection[i+1]*branching_ratio / bin_width
    err = h_signal_total_xsection.GetBinError(i+1)*branching_ratio / bin_width

    h_signal_total_xsection[i+1] = val
    h_signal_total_xsection.SetBinError(i+1, err)

    signal_fiducial_xsection     = h_signal_total_xsection[i+1]*h_fid_acceptance[i+1]
    signal_fiducial_xsection_err = h_signal_total_xsection.GetBinError(i+1)*h_fid_acceptance[i+1]

    h_signal_fiducial_xsection[i+1] = signal_fiducial_xsection
    h_signal_fiducial_xsection.SetBinError(i+1, signal_fiducial_xsection_err)


  #systematics
  #------------------------------
  print "Irreducible Background Systematics:"
  AddSystematics(h_ZZ_yield_syst_up, h_ZZ_yield_syst_dn, ZZ_bkg_syst_names, ZZ_bkg_syst_vals, var_jet[var])
  
  #for k in range(len(channels)):
  #  for i in range(len(ZZ_bkg_syst_names_[k])):
  #    for j in range(n_bins):
  #        h_ZZ_yield_syst_[k].SetBinContent(j+1,sqrt(h_ZZ_yield_syst_[k][j+1]*h_ZZ_yield_syst_[k][j+1]+ZZ_bkg_syst_vals_[k][i][j]*ZZ_bkg_syst_vals_[k][i][j]))

  print "Reducible Background Systematics:"
  AddSystematics(h_red_mu_yield_syst_up, h_red_mu_yield_syst_dn, red_bkg_syst_names, red_bkg_syst_vals)
  AddSystematics(h_red_el_yield_syst_up, h_red_el_yield_syst_dn, red_bkg_syst_names, red_bkg_syst_vals)

  #systematics from mini-tree?  or from given systematics?
  #red_el_chain.Draw(v_reco+" >> h_red_el_yield_syst_up", "(weight_TF+weight_TF_error)*"+mass_window, "goff");
  #red_el_chain.Draw(v_reco+" >> h_red_el_yield_syst_dn", "(weight_TF-weight_TF_error)*"+mass_window, "goff");
  #for i in range(n_bins):
  #  if ( h_red_el_yield[i+1] != 0):
  #    h_red_el_yield_syst_up[i+1] = abs(h_red_el_yield_syst_up[i+1] - h_red_el_yield[i+1]) / h_red_el_yield[i+1] * 100
  #    h_red_el_yield_syst_dn[i+1] = abs(h_red_el_yield_syst_dn[i+1] - h_red_el_yield[i+1]) / h_red_el_yield[i+1] * 100

  for i in range(n_bins):
     h_red_yield_syst_up[i+1] = sqrt(pow(h_red_el_yield_syst_up[i+1]*h_red_el_yield[i+1],2)+pow(h_red_mu_yield_syst_up[i+1]*h_red_mu_yield[i+1],2))
     h_red_yield_syst_dn[i+1] = sqrt(pow(h_red_el_yield_syst_dn[i+1]*h_red_el_yield[i+1],2)+pow(h_red_mu_yield_syst_dn[i+1]*h_red_mu_yield[i+1],2))
    
  #for k in range(len(channels)):
  #  for i in range(len(red_bkg_syst_names_[k])):
  #    for j in range(n_bins):
  #        h_red_yield_syst_[k].SetBinContent(j+1,sqrt(h_red_yield_syst_[k][j+1]*h_red_yield_syst_[k][j+1]+red_bkg_syst_vals_[k][i][j]*red_bkg_syst_vals_[k][i][j]))

  print "Signal Systematics:"
  AddSystematics(h_signal_yield_syst_up, h_signal_yield_syst_dn, signal_syst_names, signal_syst_vals)


  for i in range(h_fid_efficiency.GetNbinsX()):

    #TODO Proper systematics (no theory?)
    h_fid_efficiency_syst[i+1]    = h_signal_yield_syst[i+1]
    h_fid_efficiency_syst_up[i+1] = h_signal_yield_syst_up[i+1] 
    h_fid_efficiency_syst_dn[i+1] = h_signal_yield_syst_dn[i+1]

    c_factor = 0
    c_factor_err = 0
    if (h_fid_efficiency[i+1] != 0):
      c_factor      = 1/h_fid_efficiency[i+1]
      c_factor_err  = h_fid_efficiency.GetBinError(i+1)/h_fid_efficiency[i+1]/h_fid_efficiency[i+1]
    c_factor_syst    = h_fid_efficiency_syst[i+1]
    c_factor_syst_up = h_fid_efficiency_syst_dn[i+1]#switch dn and up because C = 1/eff
    c_factor_syst_dn = h_fid_efficiency_syst_up[i+1]

    h_correction_factor.SetBinContent(i+1,c_factor)
    h_correction_factor.SetBinError(i+1,c_factor_err)
    h_correction_factor_syst.SetBinContent(i+1,c_factor_syst)
    h_correction_factor_syst_up.SetBinContent(i+1,c_factor_syst_up)
    h_correction_factor_syst_dn.SetBinContent(i+1,c_factor_syst_dn)



  #Background Estimate
  #------------------------------

  h_background_yield.Add(h_ZZ_yield)
  h_background_yield.Add(h_red_yield)

  for i in range(n_bins):
    zz_syst  = h_ZZ_yield[i+1]*h_ZZ_yield_syst[i+1]/100
    red_syst = h_red_yield[i+1]*h_red_yield_syst[i+1]/100
    h_background_yield_syst.SetBinContent(i+1,sqrt(zz_syst*zz_syst+red_syst*red_syst)/h_background_yield[i+1]*100)
    h_observed_yield_syst.SetBinContent(i+1,sqrt(zz_syst*zz_syst+red_syst*red_syst)/h_background_yield[i+1]*100)

    zz_syst_up  = h_ZZ_yield[i+1]*h_ZZ_yield_syst_up[i+1]/100
    red_syst_up = h_red_yield[i+1]*h_red_yield_syst_up[i+1]/100
    h_background_yield_syst_up.SetBinContent(i+1,sqrt(zz_syst_up*zz_syst_up+red_syst_up*red_syst_up)/h_background_yield[i+1]*100)
 
    zz_syst_dn  = h_ZZ_yield[i+1]*h_ZZ_yield_syst_dn[i+1]/100
    red_syst_dn = h_red_yield[i+1]*h_red_yield_syst_dn[i+1]/100
    h_background_yield_syst_dn.SetBinContent(i+1,sqrt(zz_syst_dn*zz_syst_dn+red_syst_dn*red_syst_dn)/h_background_yield[i+1]*100)

  for i in range(len(channels)):
    h_background_yield_[i].Add(h_ZZ_yield_[i])
    h_background_yield_[i].Add(h_red_yield_[i])

    #for j in range(n_bins):
    #  zz_syst  = h_ZZ_yield_[i][j+1]*h_ZZ_yield_syst_[i][j+1]/100
    #  red_syst = h_red_yield_[i][j+1]*h_red_yield_syst_[i][j+1]/100
    #  h_background_yield_syst_[i].SetBinContent(j+1,sqrt(zz_syst*zz_syst+red_syst*red_syst)/h_background_yield_[i][j+1]*100)

  #Background Subtraction
  #------------------------------

  h_observed_yield.Add(h_data_yield, h_background_yield,1.0,-1.0)
  h_observed_yield.Print("all")
  for i in range(n_bins):
    #only systematic on data-bkg is systematic on background
    h_observed_yield_syst_up.SetBinContent(i+1,h_background_yield[i+1]*h_background_yield_syst_up[i+1]/h_observed_yield[i+1])
    h_observed_yield_syst_dn.SetBinContent(i+1,h_background_yield[i+1]*h_background_yield_syst_dn[i+1]/h_observed_yield[i+1])
    
    value = h_observed_yield[i+1]
    err_up = 1
    err_dn = 0
    x_err = h_observed_yield.GetBinWidth(i+1)/2
    if (value <=0): #case - observe < background prediction -TODO handle this case
      value = 0
    #else:
    
    #add error in quad - stat from bkg + stat from data    
    err_up = sqrt(pow(h_background_yield.GetBinError(i+1),2) + pow(h_data_yield_perr.GetErrorYhigh(i),2))
    err_dn = sqrt(pow(h_background_yield.GetBinError(i+1),2) + pow(h_data_yield_perr.GetErrorYlow(i) ,2))

    h_observed_yield_perr.SetPoint(i,h_observed_yield.GetBinCenter(i+1), value); 
    h_observed_yield_perr.SetPointError(i,x_err,x_err,err_dn, err_up); 

  #derive xsection
  #------------------------------

  for i in range(n_bins):

    bin_width = bins[i+1] - bins[i]

    observed_xsection = h_observed_yield[i+1] / h_fid_efficiency[i+1] / lumi / bin_width
    if (h_observed_yield[i+1] != 0):
      observed_xsection_unc    = observed_xsection*(h_observed_yield.GetBinError(i+1)/h_observed_yield[i+1])
      observed_xsection_err_up = observed_xsection*(h_observed_yield_perr.GetErrorYhigh(i)/h_observed_yield[i+1])
      observed_xsection_err_dn = observed_xsection*(h_observed_yield_perr.GetErrorYlow(i)/h_observed_yield[i+1])
    else:
      print "WARNING: Observed yield in bin " +str(i) + " == 0!"
      observed_xsection_unc    = 0
      observed_xsection_err_up = 0
      observed_xsection_err_dn = 0

    observed_xsection_syst =  h_observed_yield_syst[i+1]*h_observed_yield_syst[i+1]
    observed_xsection_syst += h_fid_efficiency_syst[i+1]*h_fid_efficiency_syst[i+1]
    observed_xsection_syst += lumi_syst*lumi_syst
    observed_xsection_syst =  sqrt(observed_xsection_syst)

    observed_xsection_syst_up =  h_observed_yield_syst_up[i+1]*h_observed_yield_syst_up[i+1]
    observed_xsection_syst_up += h_fid_efficiency_syst_up[i+1]*h_fid_efficiency_syst_up[i+1]
    observed_xsection_syst_up += lumi_syst*lumi_syst
    observed_xsection_syst_up =  sqrt(observed_xsection_syst_up)

    observed_xsection_syst_dn =  h_observed_yield_syst_dn[i+1]*h_observed_yield_syst_dn[i+1]
    observed_xsection_syst_dn += h_fid_efficiency_syst_dn[i+1]*h_fid_efficiency_syst_dn[i+1]
    observed_xsection_syst_dn += lumi_syst*lumi_syst
    observed_xsection_syst_dn =  sqrt(observed_xsection_syst)

    h_observed_xsection.SetBinContent(i+1,observed_xsection)
    h_observed_xsection.SetBinError(i+1,observed_xsection_unc)
    
    h_observed_xsection_syst.SetBinContent(i+1,observed_xsection_syst)
    h_observed_xsection_syst_up.SetBinContent(i+1,observed_xsection_syst_up)
    h_observed_xsection_syst_dn.SetBinContent(i+1,observed_xsection_syst_dn)
    
    h_observed_xsection_perr.SetPoint(i,h_observed_xsection.GetBinCenter(i+1), observed_xsection)
    h_observed_xsection_perr.SetPointError(i,h_observed_xsection.GetBinWidth(i+1)/2, h_observed_xsection.GetBinWidth(i+1)/2, observed_xsection_err_dn, observed_xsection_err_up,)

    #signal_xsection = h_signal_yield[i+1] / h_fid_efficiency[i+1] / lumi / bin_width
    #print signal_xsection, h_signal_fiducial_xsection[i+1]
    #signal_xsection_unc = h_signal_yield.GetBinError(i+1) / h_fid_efficiency[i+1] / lumi / bin_width #WRONG uncertainty form theory only  

    #TODO WRONG uncertainty from theory only
    #signal_xsection_syt =  h_signal_yield_syst[i+1]*h_signal_yield_syst[i+1]  
    #signal_xsection_syt += h_fid_efficiency_syst[i+1]*h_fid_efficiency_syst[i+1]
    #signal_xsection_syt += lumi_syst*lumi_syst
    #signal_xsection_syt =  sqrt(signal_xsection_syt)

    #h_signal_xsection.SetBinContent(i+1,signal_xsection)
    #h_signal_xsection.SetBinError(i+1,signal_xsection_unc)
    #h_signal_xsection_syst.SetBinContent(i+1,0)  #TODO Fix this  

  #Make tables
  #------------------------------

  print "------------------------"
  print "Event Yields for "+var_name+" ("+str(mass_window_lo)+"-"+str(mass_window_hi)+" GeV)"
  print "------------------------"
  print "Bin\t|",
  for i in range(n_bins): print str(v_bins[i])+"-"+str(v_bins[i+1]),'\t',
  print' Overflow\t| Total'
  print "------------------------"

  print "Signal\t|",
  for i in range(n_bins+1): print round(h_signal_yield[i+1],3),"\t",
  print '\t|',round(h_signal_yield.Integral(0,n_bins+1),3)  


  print "ZZ\t|",
  for i in range(n_bins+1): print round(h_ZZ_yield[i+1],3), "\t",
  print '\t|',round(h_ZZ_yield.Integral(0,n_bins+1)  ,3)


  print "Red.\t|", 
  for i in range(n_bins+1): print round(h_red_yield[i+1],3),"\t",
  print '\t|',round(h_red_yield.Integral(0,n_bins+1) ,3) 

  print "------------------------"

  print "Pseudo-Data\t|" if usePseudoData else "Data\t|" ,  
  for i in range(n_bins+1): print h_data_yield[i+1],"\t",
  print '\t|',h_data_yield.Integral(0,n_bins+1)  

  print "------------------------"


  print "Significances"
  print "------------------------"
  print "S/B\t\t|", 
  for i in range(n_bins):
    print round(h_signal_yield[i+1]/h_background_yield[i+1],2), '\t',
  print ''

  print "S/sqrt(S+B)\t|", 
  for i in range(n_bins):
    print round(h_signal_yield[i+1]/sqrt(h_signal_yield[i+1]+h_background_yield[i+1]),2), '\t',
  print ''

  print "Z_0\t\t|", 
  for i in range(n_bins):
    print round(Significance(h_signal_yield[i+1],h_background_yield[i+1]),2), '\t',
  print ''
  print "------------------------"

  if (separateChannels):
    for j in range(len(channels)):

      print "------------------------"
      print "Event Yields - "+channels[j]+" ("+str(mass_window_lo)+"-"+str(mass_window_hi)+" GeV)"
      print "------------------------"
      print "Bin\t|",
      for i in range(n_bins): print str(v_bins[i])+"-"+str(v_bins[i+1]),'\t',
      print''
      print "------------------------"

      print "Signal\t|",
      for i in range(n_bins): print round(h_signal_yield_[j][i+1],3),"\t",
      print ''

      print "ZZ\t|",
      for i in range(n_bins): print round(h_ZZ_yield_[j][i+1],3), "\t",
      print ''

      print "Red.\t|", 
      for i in range(n_bins): print round(h_red_yield_[j][i+1],3),"\t",
      print ''
      print "------------------------"

      print "Significances"
      print "------------------------"
      print "S/B\t\t|", 
      for i in range(n_bins):
	print round(h_signal_yield_[j][i+1]/h_background_yield_[j][i+1],2), '\t',
      print ''

      print "S/sqrt(S+B)\t|", 
      for i in range(n_bins):
	print round(h_signal_yield_[j][i+1]/sqrt(h_signal_yield_[j][i+1]+h_background_yield_[j][i+1]),2), '\t',
      print ''

      print "Z_0\t\t|", 
      for i in range(n_bins):
	print round(Significance(h_signal_yield_[j][i+1],h_background_yield_[j][i+1]),2), '\t',
      print ''
      print "------------------------"


  print "Fiducial Cross Sections"
  print "------------------------"
  print "Signal\t|",
  for i in range(n_bins): print h_signal_fiducial_xsection[i+1],"\t",
  print ''
  print "------------------------"

  print "Pseudo-Data\t|" if usePseudoData else "Data\t|" , 
  for i in range(n_bins): print h_observed_xsection[i+1],
  print ''

  print "Stat Up(%)\t|", 
  for i in range(n_bins): print round(h_observed_xsection_perr.GetErrorYhigh(i)/h_observed_xsection[i+1]*100,1),
  print ''

  print "Stat Dn(%)\t|", 
  for i in range(n_bins): print round(h_observed_xsection_perr.GetErrorYlow(i)/h_observed_xsection[i+1]*100,1),
  print ''

  print "Syst Up(%)\t|", 
  for i in range(n_bins): print round(h_observed_xsection_syst_up[i+1],1),
  print ''

  print "Syst Dn(%)\t|", 
  for i in range(n_bins): print round(h_observed_xsection_syst_dn[i+1],1),
  print ''

  print "------------------------"

  #Make plots
  #------------------------------
  gStyle.SetOptStat(0)

  w = 800
  h = 600
  mode_colors = [kBlue, kGreen, kRed, kViolet, kOrange]

  label_cr2 = "#it{m}_{4#font[12]{l}} < " + str(mass_window_CR2_hi)+" GeV"
  label_sr  = str(mass_window_lo) + " < #it{m}_{4#font[12]{l}} < " + str(mass_window_hi) + " GeV"
  label_cr1 = "#it{m}_{4#font[12]{l}} > " + str(mass_window_CR1_lo)+" GeV"
  
   #------------------------------

  c_signal_yield_mode = TCanvas('SignalMode_Yield_'+var_name,'',w,h)
 
  #plot MC prediction
  mode_stack = THStack()
  for i in range(n_modes):
    h_signal_yield_mode[i].SetFillColor(mode_colors[i])
    h_signal_yield_mode[i].SetFillStyle(3003)
    h_signal_yield_mode[i].SetLineColor(mode_colors[i])
    mode_stack.Add(h_signal_yield_mode[i])

  mode_stack.SetMaximum(1.9*mode_stack.GetMaximum())
  mode_stack.SetMinimum(0.001)

  if (var_name=='njets'):
    h_jets.GetXaxis().SetTitle(var_label_reco)
    h_jets.GetYaxis().SetTitle('Events')
    h_jets.SetMaximum(14)
    h_jets.SetMinimum(0.001)
    h_jets.Draw() #for axes
    mode_stack.Draw("HIST SAME")
  else :
    mode_stack.Draw("HIST")  

  mode_stack.GetXaxis().SetTitle(h_signal_yield_mode[0].GetXaxis().GetTitle())
  mode_stack.GetYaxis().SetTitle(h_signal_yield_mode[0].GetYaxis().GetTitle())

  c_signal_yield_mode.RedrawAxis()

  l_signal_yield_mode = TLegend(0.76,0.67,0.99,0.90)
  FormatLeg(l_signal_yield_mode)
  l_signal_yield_mode.SetTextFont(42)
  l_signal_yield_mode.SetTextSize(0.04)
  for i in range(n_modes):
    l_signal_yield_mode.AddEntry(h_signal_yield_mode[i], label_mode[i],'F')
  l_signal_yield_mode.Draw()

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.75)
  ADD_LABEL( label_sr+', #it{m}_{H} = 125 GeV' , 0.68)
  c_signal_yield_mode.Write()

  #------------------------------

  c_signal_mode_fraction = TCanvas('SignalMode_Fraction_'+var_name,'',w,h)
  
  mode_fraction_stack = THStack()
  for i in range(n_modes):
    hist = h_signal_yield_mode[i].Clone('h_signal_fraction_'+name_mode[i])
    for j in range(n_bins):
      hist[j+1] = hist[j+1] / h_signal_yield[j+1]
    mode_fraction_stack.Add(hist)

  mode_fraction_stack.SetMaximum(1.5)
  mode_fraction_stack.SetMinimum(0.4)

  if (var_name=='njets'):
    h_jets.GetXaxis().SetTitle(var_label_reco)
    h_jets.GetYaxis().SetTitle('Fraction')
    h_jets.SetMaximum(1.5)
    h_jets.SetMinimum(0.4)
    h_jets.Draw() #for axes
    mode_fraction_stack.Draw("HIST SAME")
  else :
    mode_fraction_stack.Draw("HIST")  

  mode_fraction_stack.GetXaxis().SetTitle(h_signal_yield_mode[0].GetXaxis().GetTitle())
  mode_fraction_stack.GetYaxis().SetTitle('Fraction')

  c_signal_mode_fraction.RedrawAxis()
  
  #reuse legend
  l_signal_yield_mode.Draw()

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.75)
  ADD_LABEL( label_sr+', #it{m}_{H} = 125 GeV' , 0.68)

  c_signal_mode_fraction.Write()

  #------------------------------

  c_dn_dy_bkg = TCanvas('dN_dy_Background_'+var_name,'',w,h)
  l_dn_dy_bkg = NewLegend(4, 'tr')

  #plot MC prediction
  h_red_yield.SetFillColor(kViolet+1)
  h_ZZ_yield.SetFillColor(kRed+1)
  h_signal_yield.SetFillColor(kAzure-9)

  stack = THStack()
  stack.Add(h_red_yield)
  stack.Add(h_ZZ_yield)
  stack.Add(h_signal_yield)

  #stack.SetMaximum(3.5*stack.GetMaximum())
  stack.SetMaximum(2.15*h_data_yield.GetMaximum())
  stack.SetMinimum(0.001)

  stack.Draw("HIST")  
  
  if (var_name=='njets'): makeNjetsXaxis(stack)   
  stack.GetXaxis().SetTitle(h_red_yield.GetXaxis().GetTitle())
  stack.GetYaxis().SetTitle(h_red_yield.GetYaxis().GetTitle())
  
  stack.Draw("HIST")

  #plot Data
  PlotGraph( h_data_yield_perr, false, 0, true)
  #PlotDerived(h_data_yield, false, 0, true)  
 
  c_dn_dy_bkg.RedrawAxis()

  l_dn_dy_bkg.AddEntry(h_observed_yield, 'pseudo-data' if usePseudoData else 'data','LEP')
  l_dn_dy_bkg.AddEntry(h_signal_yield, 'SM (#it{m}_{H} = 125 GeV)','F')
  l_dn_dy_bkg.AddEntry(h_ZZ_yield, 'Irreducible','F')
  l_dn_dy_bkg.AddEntry(h_red_yield, 'Reducible','F')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL( label, 0.75)
  ADD_LABEL( label_sr, 0.68)
  l_dn_dy_bkg.Draw()
  c_dn_dy_bkg.Write()

  #------------------------------

  #flat calculation of ZZ systematics including PDF and QCD scale uncertainties from YR
  avg_m4l = 200
  
  QCD_error = 0.01*sqrt((avg_m4l-20.)/13.)
  PDF_error = 0.0035*sqrt(avg_m4l-30.)
  lumi_error = 0.028
  
  tot_error = sqrt(pow(QCD_error,2)+pow(PDF_error,2)+pow(lumi_error,2))*100
  
  h_ZZ_yield_CR1_syst = h_ZZ_yield_CR1.Clone('h_ZZ_yield_CR1_syst')
  for i in range(n_bins+2): h_ZZ_yield_CR1_syst[i] = tot_error
  
  #------------------------------
  c_dn_dy_bkg_CR1 = TCanvas('dN_dy_Background_CR1_'+var_name,'',w,800)

  ratio_pad = TPad("ratio_pad", "", 0., 0., 1.,0.30);
  ratio_pad.SetTopMargin(0.03);
  ratio_pad.SetBottomMargin(0.4);
  ratio_pad.SetFillColor(0);
  ratio_pad.Draw();

  main_pad = TPad("main_pad", "", 0., 0.3, 1.,1.);
  main_pad.SetBottomMargin(0);
  main_pad.Draw();

  main_pad.cd()

  #plot MC prediction
  h_red_yield_CR1.SetFillColor(kViolet+1)
  h_ZZ_yield_CR1.SetFillColor(kRed+1)
  h_signal_yield_CR1.SetFillColor(kAzure-9)

  stack_CR1 = THStack()
  #stack_CR1.Add(h_signal_yield_CR1)
  stack_CR1.Add(h_red_yield_CR1)
  stack_CR1.Add(h_ZZ_yield_CR1)
    
  stack_CR1.Draw("HIST")
  if (var_name=='njets'): makeNjetsXaxis(stack_CR1)
  stack_CR1.SetMaximum(1.8*h_data_yield_CR1.GetMaximum())
  stack_CR1.SetMinimum(0.0001)
  stack_CR1.GetXaxis().SetTitle(h_red_yield_CR1.GetXaxis().GetTitle())
  stack_CR1.GetYaxis().SetTitle(h_red_yield_CR1.GetYaxis().GetTitle())
  stack_CR1.Draw("HIST")

  h_sum_CR1 = stack_CR1.GetStack().Last()

  #add uncertainty band on background prediction
  h_ZZ_yield_err = AsymmErrorHist(h_sum_CR1,h_ZZ_yield_CR1_syst,h_ZZ_yield_CR1_syst)
  gStyle.SetHatchesSpacing(0.75)
  PlotBand(h_ZZ_yield_err, false, 3, true)
  h_ZZ_yield_err.SetLineWidth(0)
  h_ZZ_yield_err.SetLineColor(kWhite)

  #plot Data
  PlotGraph( h_data_yield_CR1_perr, false, 0, true)
  #PlotDerived(h_data_yield, false, 0, true)  
  
  c_dn_dy_bkg_CR1.RedrawAxis()

  l_dn_dy_bkg_CR1 = TLegend(0.59,0.67,0.82,0.88)
  FormatLeg(l_dn_dy_bkg_CR1)
  l_dn_dy_bkg_CR1.SetTextFont(42)
  l_dn_dy_bkg_CR1.SetTextSize(0.042)  
  l_dn_dy_bkg_CR1.AddEntry(h_data_yield_CR1_perr, 'data','LEP')
  #l_dn_dy_bkg_CR1.AddEntry(h_signal_yield_CR1, 'SM (#it{m}_{H} = 125 GeV)','F')
  l_dn_dy_bkg_CR1.AddEntry(h_ZZ_yield_CR1, 'Background ZZ*','F')
  l_dn_dy_bkg_CR1.AddEntry(h_red_yield_CR1, 'Background Z+jets, t#bar{t}','F')
  l_dn_dy_bkg_CR1.AddEntry(h_ZZ_yield_err, 'Systematic uncertainty','F')
  l_dn_dy_bkg_CR1.Draw()

  ratio_pad.cd()
      
  ratio_CR1_yield = RatioHist(h_ZZ_yield_err, h_sum_CR1)
  ratio_CR1       = RatioGraph(h_data_yield_CR1_perr, h_sum_CR1)
  
  if (var_name=='njets'):
    h_jets_ratio = h_jets.Clone('dummy_ratio')
    h_jets_ratio.GetXaxis().SetTitle(var_label_reco)
    FormatRatioHist(h_jets_ratio)
    h_jets_ratio.GetXaxis().SetLabelSize(0.18)
    h_jets_ratio.GetXaxis().SetLabelOffset(0.01)
    h_jets_ratio.Draw() #for axes
    PlotBox(ratio_CR1_yield,false,3,true)
  else:
    PlotBox(ratio_CR1_yield,false,3,false)
   
  ratio_CR1.Draw("PZ SAME")
  ratio_CR1.Write()
  
  ks_prob = h_sum_CR1.KolmogorovTest(h_data_yield_CR1)
  #print "KS Prob:", ks_prob

  c_dn_dy_bkg_CR1.RedrawAxis()
   
  main_pad.cd()
    
  MY_ATLAS_LABEL(atlas_label_text, size=0.065)
  ADD_LABEL(hzz_label, y = 0.80, size=0.045)
  ADD_LABEL(label, y=0.72, size=0.045)
  ADD_LABEL( label_cr1 + '   KS = ' + str(round(ks_prob,3)), y=0.64, size=0.045)

  c_dn_dy_bkg_CR1.RedrawAxis()

  c_dn_dy_bkg_CR1.Write()

  #------------------------------

  print "-----------------------------------"
  print "ZZ Data-MC CR1 Systematic"
  print "-----------------------------------"
  
  h_zzbkg_CR1_syst = TH1F('h_zzbkg_CR1_syst', ';systematic [%]',n_bins_CR1, bins_CR1)
  norm_sf =  h_data_yield_CR1.Integral(0,n_bins_CR1) / h_sum_CR1.Integral(0,n_bins_CR1)
  for i in range(n_bins_CR1):
    syst_err = max( abs(norm_sf*h_sum_CR1[i+1] - h_data_yield_CR1[i+1]),h_data_yield_CR1.GetBinError(i+1)) 
    h_zzbkg_CR1_syst[i+1] = syst_err / h_sum_CR1[i+1] * 100
    print round(h_zzbkg_CR1_syst[i+1],1), 
  print "\n-----------------------------------"

  #------------------------------

  c_dn_dy_bkg_CR2 = TCanvas('dN_dy_Background_CR2_'+var_name,'',w,h)
  l_dn_dy_bkg_CR2 = NewLegend(4, 'tr')

  #plot MC prediction
  h_red_yield_CR2.SetFillColor(kViolet+1)
  h_ZZ_yield_CR2.SetFillColor(kRed+1)
  h_signal_yield_CR2.SetFillColor(kAzure-9)

  stack_CR2 = THStack()
  stack_CR2.Add(h_red_yield_CR2)
  stack_CR2.Add(h_ZZ_yield_CR2)
  stack_CR2.Add(h_signal_yield_CR2)

  stack_CR2.SetMaximum(45)
  stack_CR2.SetMinimum(0.0001)

  stack_CR2.Draw("HIST")
  stack_CR2.GetXaxis().SetTitle(h_red_yield_CR2.GetXaxis().GetTitle())
  stack_CR2.GetYaxis().SetTitle(h_red_yield_CR2.GetYaxis().GetTitle())

  #plot Data
  PlotGraph( h_data_yield_CR2_perr, false, 0, true)
  #PlotDerived(h_data_yield, false, 0, true)  
  c_dn_dy_bkg_CR2.RedrawAxis()

  l_dn_dy_bkg_CR2.AddEntry(h_observed_yield_CR2, 'Data','LEP')
  l_dn_dy_bkg_CR2.AddEntry(h_signal_yield_CR2, 'SM (#it{m}_{H} = 125 GeV)','F')
  l_dn_dy_bkg_CR2.AddEntry(h_ZZ_yield_CR2, 'Irreducible','F')
  l_dn_dy_bkg_CR2.AddEntry(h_red_yield_CR2, 'Reducible','F')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  ADD_LABEL( label_cr2, 0.68)
  l_dn_dy_bkg_CR2.Draw()
  c_dn_dy_bkg_CR2.Write()
  
  #------------------------------

  c_dn_dy_bkgonly = TCanvas('dN_dy_BackgroundOnly_'+var_name,'',w,h)
  l_dn_dy_bkgonly = NewLegend(3, 'tr')

  stack_BackOnly = THStack()
  stack_BackOnly.Add(h_red_yield)
  stack_BackOnly.Add(h_ZZ_yield)

  stack_BackOnly.SetMaximum(25)
  stack_BackOnly.SetMinimum(0.001)

  stack_BackOnly.Draw("HIST")
  stack_BackOnly.GetXaxis().SetTitle(h_red_yield.GetXaxis().GetTitle())
  stack_BackOnly.GetYaxis().SetTitle(h_red_yield.GetYaxis().GetTitle())

  #h_background_yield_err = ErrorHist( h_background_yield, h_background_yield_syst )
  h_background_yield_err = AsymmErrorHist( h_background_yield, h_background_yield_syst_up, h_background_yield_syst_dn )
  hists.append(h_background_yield_err)
  PlotBand(h_background_yield_err, true, 2, true)

  #plot Data
  PlotGraph( h_data_yield_perr, false, 0, true)
  c_dn_dy_bkgonly.RedrawAxis()

  l_dn_dy_bkg.AddEntry(h_observed_yield, 'Pseudo-Data' if usePseudoData else 'Data','LEP')
  l_dn_dy_bkgonly.AddEntry(h_ZZ_yield, 'Irreducible','F')
  l_dn_dy_bkgonly.AddEntry(h_red_yield, 'Reducible','F')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  l_dn_dy_bkgonly.Draw()
  c_dn_dy_bkgonly.Write()
  
  #------------------------------

  c_dn_dy = TCanvas('dN_dy_'+var_name,'',w,h)
  l_dn_dy = NewLegend(3, 'tr')

  #plot data systematic
  #h_observed_yield_err = ErrorHist( h_observed_yield, h_observed_yield_syst ); hists.append(h_observed_yield_err)
  h_observed_yield_err = AsymmErrorHist( h_observed_yield, h_observed_yield_syst_up,h_background_yield_syst_dn ); 
  hists.append(h_observed_yield_err)
  h_observed_yield_err.SetMaximum(15)
  h_observed_yield_err.SetMinimum(0.001)
  PlotBand(h_observed_yield_err, false, 1, false)

  #plot MC prediction
  #h_signal_yield_err = ErrorHist( h_signal_yield, h_signal_yield_syst )
  h_signal_yield_err = AsymmErrorHist( h_signal_yield, h_signal_yield_syst_up, h_signal_yield_syst_dn )
  hists.append(h_signal_yield_err)
  PlotBox(h_signal_yield_err, 1, 5, true)

  #plot Data
  PlotGraph( h_observed_yield_perr, false, 0, true)

  c_dn_dy.RedrawAxis()

  l_dn_dy.AddEntry(h_observed_yield, 'Pseudo-Data' if usePseudoData else 'Data','LEP')
  l_dn_dy.AddEntry(h_observed_yield_err, 'syst','F')
  l_dn_dy.AddEntry(h_signal_yield_err, 'SM (#it{m}_{H} = 125 GeV)','F')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  l_dn_dy.Draw()
  c_dn_dy.Write()

  #------------------------------

  c_dn_dy_ratio = TCanvas('dN_dy_ratio_'+var_name,'',w,800)
  l_dn_dy_ratio = NewLegend(3, 'tr')

  pad0 = TPad("pad", '', 0., 0., 1.,0.30);
  pad0.SetTopMargin(0.03);
  pad0.SetBottomMargin(0.4);
  pad0.SetFillColor(0);
  pad0.Draw();

  pad1 = TPad("pad1", '', 0., 0.3, 1.,1.);
  pad1.SetBottomMargin(0);
  pad1.Draw();

  pad1.cd()

  PlotBand(h_observed_yield_err, false, 1, false)

  #plot MC prediction
  #PlotBox(h_signal_yield_err, 1, 5, true)
  PlotBox(h_signal_yield_err, 1, 5, true)

  #plot Data
  PlotGraph( h_observed_yield_perr, false, 0, true)

  c_dn_dy_ratio.RedrawAxis()
  l_dn_dy_ratio.AddEntry(h_observed_yield, 'Pseudo-Data' if usePseudoData else 'Data','LEP')
  l_dn_dy_ratio.AddEntry(h_observed_yield_err, 'syst','F')
  l_dn_dy_ratio.AddEntry(h_signal_yield_err, 'SM (#it{m}_{H} = 125 GeV)','F')
  l_dn_dy_ratio.Draw()

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)

  #plot ratio
  pad0.cd()

  h_observed_yield_err_ratio  = RatioHist(h_observed_yield_err, h_signal_yield)
  h_observed_yield_perr_ratio = RatioGraph(h_observed_yield_perr, h_signal_yield)
  h_signal_yield_ratio = RatioHist(h_signal_yield_err, h_signal_yield)

  PlotBand(h_observed_yield_err_ratio, false, 1, false)
  PlotBox(h_signal_yield_ratio, 1, 5, true)

  h_observed_yield_perr_ratio.Draw("P SAME")

  c_dn_dy_ratio.Write()

  #------------------------------

  c_dsigma_dy = TCanvas('dsigma_dy_'+var_name,'',w,h)
  l_dsigma_dy = NewLegend(3, 'tr')

  h_observed_xsection_err = ErrorHist( h_observed_xsection, h_observed_xsection_syst );hists.append(h_observed_xsection_err)
  obs_max = 0
  obs_min = h_observed_xsection[1]
  for i in range(n_bins):
    obs_max = max(h_observed_xsection_err[i+1]+h_observed_xsection_err.GetBinError(i+1), obs_max)
    obs_min = min(h_observed_xsection[i+1], obs_min)
    
  h_observed_xsection_err.SetMaximum(obs_max*2.5)
  h_observed_xsection_err.SetMinimum(obs_min/100)
  PlotBand(h_observed_xsection_err, false, 1, false)

  #plot MC prediction
  Plot(h_signal_fiducial_xsection, true, 2, true)
  #h_signal_xsection_err = ErrorHist( h_signal_xsection, h_signal_xsection_syst )
  #PlotBox(h_signal_xsection_err, 1, 5, true)

  #plot Data
  PlotGraph(h_observed_xsection_perr, false, 0, true)
  c_dsigma_dy.RedrawAxis()

  l_dsigma_dy.AddEntry(h_observed_yield, 'Pseudo-Data' if usePseudoData else 'Data','LEP')
  l_dsigma_dy.AddEntry(h_observed_xsection_err, 'syst','F')
  #l_dsigma_dy.AddEntry(h_signal_xsection_err, 'SM (#it{m}_{H} = 125 GeV)','F')
  l_dsigma_dy.AddEntry(h_signal_fiducial_xsection, 'SM (#it{m}_{H} = 125 GeV)','l')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  l_dsigma_dy.Draw()
  c_dsigma_dy.Write()

  #------------------------------

  c_correction_factor = TCanvas('Correction_Factor_'+var_name,'',w,h)
  l_correction_factor = NewLegend(2, 'tr')

  h_correction_factor.SetMaximum(2.5)
  h_correction_factor.SetMinimum(0.5)
  PlotDerived(h_correction_factor, false, 0, false) #axes etc.

  #h_correction_factor_err = ErrorHist( h_correction_factor, h_correction_factor_syst )
  h_correction_factor_err = AsymmErrorHist( h_correction_factor, h_correction_factor_syst_up, h_correction_factor_syst_dn )
  hists.append(h_correction_factor_err)
  PlotBand(h_correction_factor_err, false, 1, true)
  PlotDerived(h_correction_factor, false, 0, true)
  c_correction_factor.RedrawAxis()

  l_correction_factor.AddEntry(h_correction_factor, 'SM (#it{m}_{H} = 125 GeV)','lep')
  l_correction_factor.AddEntry(h_correction_factor_err, 'syst','F')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL("Simulation, #sqrt{s} = 8 TeV", 0.76)
  l_correction_factor.Draw()
  c_correction_factor.Write()

  #------------------------------
  c_shape = TCanvas('ReducibleShapeComparison_'+var_name,'',w,h)
  l_shape = NewLegend(3, 'tr')

  h_red_mc_shape = Shape(h_red_mc_yield, 'h_red_mc_shape')
  h_red_mu_shape = Shape(h_red_mu_yield, 'h_red_mu_shape')
  h_red_el_shape = Shape(h_red_el_yield, 'h_red_el_shape')
  
  h_red_mc_shape.SetMaximum(1.0)
  h_red_mc_shape.SetMinimum(0.0001)

  PlotDerived(h_red_mc_shape, False, 1, False) #axes etc.
  PlotDerived(h_red_mu_shape, False, 2, True) #axes etc.
  PlotDerived(h_red_el_shape, False, 3, True) #axes etc.
  
  l_shape.AddEntry(h_red_mc_shape, 'Muon MC','l')
  l_shape.AddEntry(h_red_mu_shape, 'Muon CR','l')
  l_shape.AddEntry(h_red_el_shape, 'Electron CR','l')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  FormatLegend(l_shape)
  l_shape.Draw()
  c_shape.Write()

  #------------------------------

  c_zz_shape = TCanvas('IrreducibleShapeComparison_'+var_name,'',w,h)
  l_zz_shape = NewLegend(5, 'tr')

  h_ZZ_SR_mc  = h_ZZ_yield.Clone('h_ZZ_SR_MC')
  ZZ_chain.Draw(v_reco+" >> h_ZZ_SR_MC", "weight*"+mass_window, "goff");  
  h_ZZ_SR_shape  = Shape(h_ZZ_SR_mc,  'h_ZZ_SR_shape')
  h_ZZ_CR1_shape = Shape(h_ZZ_yield_CR1, 'h_ZZ_CR1_shape')
  h_ZZ_CR2_shape = Shape(h_ZZ_yield_CR2, 'h_ZZ_CR2_shape')

  h_data_CR1_shape = Shape(h_data_yield_CR1, 'h_data_CR1_shape')
  h_data_CR2_shape = Shape(h_data_yield_CR2, 'h_data_CR2_shape')

  h_data_CR1_shape.SetMaximum(1.2)
  h_data_CR1_shape.SetMinimum(0.0001)
  h_data_CR1_shape.GetYaxis().SetTitle('prob.')

  PlotDerived(h_data_CR1_shape, True,  1, False)
  PlotDerived(h_data_CR2_shape, True,  2, True)
  PlotDerived(h_ZZ_CR2_shape,   False, 2, True)
  PlotDerived(h_ZZ_SR_shape,    False, 4, True)
  PlotDerived(h_ZZ_CR1_shape,   False, 1, True)
    
  l_zz_shape.AddEntry(h_ZZ_SR_shape,    'ZZ MC - '+label_sr, 'lep')
  l_zz_shape.AddEntry(h_ZZ_CR1_shape,   'ZZ MC - '+label_cr1,'lep')
  l_zz_shape.AddEntry(h_ZZ_CR2_shape,   'ZZ MC - '+label_cr2,'lep')
  l_zz_shape.AddEntry(h_data_CR1_shape, 'Data - '+label_cr1, 'lep')
  l_zz_shape.AddEntry(h_data_CR2_shape, 'Data - '+label_cr2, 'lep')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  #FormatLegend(l_zz_shape)
  l_zz_shape.Draw()
  c_zz_shape.Write()

  #------------------------------

  c_zz_syst = TCanvas('IrreducibleShapeSystematicComparison_'+var_name,'',w,h)
  l_zz_syst = NewLegend(2, 'tr')

  #data - MC difference
  h_ZZ_CR1_syst = ShapeSystematic(h_ZZ_yield_CR1, h_data_yield_CR1,'h_ZZ_CR1_syst')
  
  #data stat error
  h_data_CR1_syst = TH1F('h_data_CR1_syst','',n_bins, bins)
  for i in range(n_bins):
    if ( h_data_CR1_shape[i+1] != 0):
      h_data_CR1_syst.SetBinContent(i+1, h_data_CR1_shape.GetBinError(i+1) / h_data_CR1_shape[i+1] * 100.0)
    else:
      h_data_CR1_syst.SetBinContent(i+1, 100)

  #MC syst error??
  
  MaxMin([h_ZZ_CR1_syst, h_data_CR1_syst])
  h_ZZ_CR1_syst.SetFillColor(kWhite)
  h_ZZ_CR1_syst.GetYaxis().SetTitle("systematic [%]")

  h_ZZ_CR1_syst.Write()
  h_data_CR1_syst.Write()
  Plot(h_ZZ_CR1_syst,	True,  1, False)
  Plot(h_data_CR1_syst, True,  2, True)
    
  l_zz_syst.AddEntry(h_ZZ_CR1_syst,    'Data/MC difference', 'l')
  l_zz_syst.AddEntry(h_data_CR1_syst,  'Data stat.','l')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  #FormatLegend(l_zz_syst)
  l_zz_syst.Draw()
  c_zz_syst.Write()
  #------------------------------

  c_zz_comp = TCanvas('IrreducibleComposition_'+var_name,'',w,h)
  l_zz_comp = NewLegend(5, 'tr')
  
  c_zz_comp.SetLogy()
  
  h_qqZZ_yield.SetMaximum(h_qqZZ_yield.GetMaximum()*500)
  h_qqZZ_yield.SetMinimum(h_ggZZ_yield.GetMinimum()/10)

  Plot(h_qqZZ_yield, False, 1, False) #axes etc.
  Plot(h_ggZZ_yield, False, 2, True) #axes etc.
  
  l_zz_comp.AddEntry(h_qqZZ_yield,  'qqZZ', 'l')
  l_zz_comp.AddEntry(h_ggZZ_yield,  'ggZZ','l')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  FormatLegend(l_zz_comp)
  l_zz_comp.Draw()
  c_zz_comp.Write()
  
  #------------------------------
  
  #make tables 
  
  f_table = open(outputDir+'/DifferentialMeasurement.'+var_name+'.'+tag+'.table','w')
  
  line = var_name + ' '
  for i in range(n_bins): line += ' &  Bin '+str(i)
  line += '\\\\ \n'
  f_table.write(line)

  f_table.write('\hline\n')
  
  line = '$N_{ZZ}$ ' 
  for i in range(n_bins): line += ' & '+str(round(h_ZZ_yield[i+1],2))
  line += '  \\\\ \n'
  f_table.write(line)

  line = '$N_{reducible}$ ' 
  for i in range(n_bins): line += ' & '+str(round(h_red_yield[i+1],2))
  line += '  \\\\ \n'
  f_table.write(line)

  line = '$N_{signal}^{expected}$ ' 
  for i in range(n_bins): line += ' & '+str(round(h_signal_yield[i+1],2))
  line += '  \\\\ \n'
  f_table.write(line)

  f_table.write('\hline\n')  
  
  line = '$N_{total}^{expected}$ ' 
  for i in range(n_bins): line += ' & '+str(round(h_signal_yield[i+1]+h_ZZ_yield[i+1]+h_red_yield[i+1],2))
  line += '  \\\\ \n'
  f_table.write(line)

  f_table.write('\hline\n')  

  line = '$N^{observed}$ ' 
  for i in range(n_bins): line += ' & '+str(round(h_data_yield[i+1],0))
  line += '  \\\\ \n'
  f_table.write(line)
  
  line = '$N^{observed}-N_{bkg}$ ' 
  for i in range(n_bins): line += ' & '+str(round(h_data_yield[i+1]-h_ZZ_yield[i+1]-h_red_yield[i+1],2))
  line += '  \\\\ \n'
  f_table.write(line)

  f_table.close()

#
#
#  #/////////////////////////////////////////
#  #// The Model building stage
#  #/////////////////////////////////////////
#  #wspace = RooWorkspace();
#
#  for i in range(n_bins):
#
#    wspace = RooWorkspace("ws_"+var_name+'_'+str(i));
#
#    s = []
#    b = []
#    db= []
#    n_channels = 0
#
#    #// Step 1, define arrays with signal & bkg expectations and background uncertainties
#
#    if separateChannels:   
#      n_channels = len(channels)
#      for j in range(n_channels):
#	s.append(h_signal_yield_[j][i+1])       #// expected signal
#	b.append(h_background_yield_[j][i+1])   #// expected background
#	db.append(h_background_yield_syst_[j][i+1] / 100.0)                         #// fractional background uncertainty
#    else:
#      n_channels = 1
#      signal     = 0
#      background = 0
#      backunc    = 0
#
#      for j in range(len(channels)):
#	signal     += h_signal_yield_[j][i+1]     
#	background += h_background_yield_[j][i+1]
#      backunc   = h_background_yield_syst[i+1] / 100.0
#
#      #if (signal != h_signal_yield[i+1]):  print "ERROR SIGNAL MISMATCH!!!!!!!!", signal, h_signal_yield[i+1]
#      #if (background != h_background_yield[i+1]):  print "ERROR BACKGROUND MISMATCH!!!!!!!!", background, h_background_yield[i+1]
#
#      s.append(signal)	  #// expected signal
#      b.append(background)   #// expected background
#      db.append(backunc) #// fractional background uncertainty
#
#    print 'bin ', i
#    print 'signal', s
#    print 'background', b
#    print 'background unc', db
#
#    #exit(0)
#    continue
#
#    arr_s = array( 'd', s )
#    arr_b = array( 'd', b )
#    arr_db = array('d', db )
#
#
#    #// Step 2, use a RooStats factory to build a PDF for a 
#    #// number counting combination and add it to the workspace.
#    #// We need to give the signal expectation to relate the masterSignal
#    #// to the signal contribution in the individual channels.
#    #// The model neglects correlations in background uncertainty, 
#    #// but they could be added without much change to the example.
#    f = RooStats.NumberCountingPdfFactory()
#    f.AddModel(arr_s,n_channels,wspace,"TopLevelPdf_"+str(i), "masterSignal_"+str(i)); 
#
#    #// Step 3, use a RooStats factory to add datasets to the workspace.
#    #// Step 3a.
#    #// Add the expected data to the workspace
#    print "STEP 3"
#    f.AddExpData( arr_s, arr_b, arr_db, n_channels, wspace, "ExpectedNumberCountingData_"+str(i));
#
#    #wspace.Print()
#
#    #/////////////////////////////////////////
#    #// The Hypothesis testing stage:
#    #/////////////////////////////////////////
#    #// Step 4, Define the null hypothesis for the calculator
#    #// Here you need to know the name of the variables corresponding to hypothesis.
#    mu = wspace.var("masterSignal_"+str(i)); 
#    mu.setRange(-5,10)
#    poi = RooArgSet(mu); 
#    nullParams = RooArgSet("nullParams_"+str(i)); 
#    mu2 = mu.Clone(); 
#    nullParams.add(mu2);
#    #nullParams.addClone(mu);
#    #// here we explicitly set the value of the parameters for the null
#    nullParams.setRealValue("masterSignal_"+str(i),0); 
#
#    #// Step 5, Create a calculator for doing the hypothesis test.
#    #// because this is a 
#    plc = RooStats.ProfileLikelihoodCalculator( wspace.data("ExpectedNumberCountingData_"+str(i)),
#						wspace.pdf("TopLevelPdf_"+str(i)), poi, 0.05, nullParams);
#
#
#    #// Step 6, Use the Calculator to get a HypoTestResult
#    htr = plc.GetHypoTest();
#    #assert(htr != 0);
#    #htr.Print()
#    if (htr):
#      print "-------------------------------------------------" 
#      print "The p-value for the null is " , htr.NullPValue() 
#      print "Corresponding to a signifcance of " , htr.Significance() 
#      print "-------------------------------------------------\n" 
#
#    #ONLY WORKS FOR INCLUSIVE CALCULATION
#    print "Alternate Calculation (INCLUSIVE ONLY)"
#    pExp = RooStats.NumberCountingUtils.BinomialExpP(s[0], b[0], db[0])
#    zExp = RooStats.NumberCountingUtils.BinomialExpZ(s[0], b[0], db[0])
#    print "  expected p-value = ", pExp
#    print "  Z value (Gaussian sigma) = ", zExp
#
#    print "-------------------------------------------------" 
#    print var_name, "Bin", i, "(",v_bins[i]," - ", v_bins[i+1],")" 
#
#    #// Step 8, Here we re-use the ProfileLikelihoodCalculator to return a confidence interval.
#    #// We need to specify what are our parameters of interest
#    paramsOfInterest = nullParams #// they are the same as before in this case
#    plc.SetParameters(paramsOfInterest);
#    lrint = plc.GetInterval();  #// that was easy.
#    lrint.SetConfidenceLevel(0.68);
#
#    #// Step 9, make a plot of the likelihood ratio and the interval obtained
#    #//paramsOfInterest->setRealValue("masterSignal",1.); 
#    #// find limits
#    bestfit  = lrint.GetBestFitParameters().getRealValue("masterSignal_"+str(i))
#    lower = lrint.LowerLimit(mu);
#    upper = lrint.UpperLimit(mu);
#
#    #lrPlot = RooStats.LikelihoodIntervalPlot(lrint);
#    #lrPlot.SetMaximum(3.);
#    #lrPlot.Draw();
#    #lrPlot.Write();
#
#    #// Step 10a. Get upper and lower limits
#    print "central value = ", bestfit
#    print "lower limit on master signal = ",  lower
#    print "upper limit on master signal = ",  upper
#    print "-------------------------------------------------\n" 
#
#    if (doToys):
#      toy_signal    = array('i', [0])
#      toy_background= array('i', [0])
#      central_value = array('d', [0])
#      lower_limit   = array('d', [0])
#      upper_limit   = array('d', [0])
#      p0_value      = array('d', [0])
#      significance  = array('d', [0])
#
#      toy_tree = TTree("toys_"+var_name+"_"+str(i), "toys")
#
#      toy_tree.Branch("toy_signal", toy_signal, "toy_signal/I")
#      toy_tree.Branch("toy_background", toy_background, "toy_background/I")
#
#      toy_tree.Branch("central_value", central_value, "central_value/D")
#      toy_tree.Branch("lower_limit", lower_limit, "lower_limit/D")
#      toy_tree.Branch("upper_limit", upper_limit, "upper_limit/D")
#      toy_tree.Branch("p0_value", p0_value, "p0_value/D")
#      toy_tree.Branch("significance", significance, "significance/D")
#
#      #//step 11.  Throw toys 
#      for toy in range(50):
#	 print "********************"
#	 print "TOY ", toy
#
#	 toy_data = []
#	 toy_signal[0] = 0
#	 toy_background[0] = 0
#	 for j in range(n_channels):
#	   toy_s = random.poisson(s[j])
#	   toy_b = random.poisson(b[j])
#	   toy_data.append(toy_s+toy_b)
#	   toy_signal[0]     += toy_s
#	   toy_background[0] += toy_b
#	 print toy_data
#
#	 toy_s = array( 'd', toy_data )
#
#	 f.AddData( toy_s, arr_b, arr_db, n_channels, wspace, "Toy_"+str(toy));
#
#	 nullParams.setRealValue("masterSignal_"+str(i),0);
#
#	 plc = RooStats.ProfileLikelihoodCalculator( wspace.data("Toy_"+str(toy)),
#						     wspace.pdf("TopLevelPdf_"+str(i)), poi, 0.05, nullParams);
#
#	 #// Step 6, Use the Calculator to get a HypoTestResult
#	 htr = plc.GetHypoTest();
#  #       if (htr):
#  #	 p0_value[0]     = htr.NullPValue() 
#  #	 significance[0] = htr.Significance() 
#
#	 #ONLY WORKS IN INCLUSIVE CALCULATION
#	 p0_value[0]     = RooStats.NumberCountingUtils.BinomialObsP(toy_data[0], b[0], db[0]);
#	 significance[0] = RooStats.NumberCountingUtils.BinomialObsZ(toy_data[0], b[0], db[0]);
#	 #cout << "observed p-value ="<< pObs << "  Z value (Gaussian sigma) = "<< zObs << endl;
#
#	 #// Step 8, Here we re-use the ProfileLikelihoodCalculator to return a confidence interval.
#	 #// We need to specify what are our parameters of interest
#	 paramsOfInterest = nullParams #// they are the same as before in this case
#	 plc.SetParameters(paramsOfInterest);
#	 lrint = plc.GetInterval();  #// that was easy.
#	 lrint.SetConfidenceLevel(0.68);
#
#	 #// find central value and 1-sigma limits
#	 central_value[0] = lrint.GetBestFitParameters().getRealValue("masterSignal_"+str(i))
#	 upper_limit[0] =  lrint.LowerLimit(mu);
#	 lower_limit[0] =  lrint.UpperLimit(mu);
#
#	 toy_tree.Fill()
#
#      #print "Toy Results"
#      toy_tree.Write()
#      #end loop on toys
#    #end if doToys
  #end loop on bins

  #Close files
  #------------------------------
  for hist in hists: hist.Write()

  print 'Closing output file: '
  print fout.GetPath().rstrip(':/')
  fout.Close()
  
  return

def MY_ATLAS_LABEL( text="Internal",x=0.2, y=0.87, color=1, size=0.05): 

  l = TLatex();  
  l.SetNDC();
  l.SetTextColor(color);
  l.SetTextSize(size)
  l.DrawLatex(x,y,"#font[72]{ATLAS} "+text);

  return
      
  
def AddSystematics(h_syst_up, h_syst_dn, syst_names, syst_vals, single_syst=False):  
  
  n_bins = h_syst_up.GetNbinsX()
  
  for i in range(len(syst_names)):
    #print "\t",syst_names[i]
    single_variation = syst_names[i].endswith('Up') or syst_names[i].endswith('Dn')
    systs = syst_vals[i]

    try:
      n_systs = len(systs)
    except TypeError:
      systs = [systs]
      n_systs = len(systs)
      
    if (not single_syst and n_systs != n_bins):  
      print "Mismatch in systematic bins for systematic ",syst_names[i],":",n_systs, 'vs', n_bins ," - check your input systematic files!"
      continue
    for j in range(n_bins):
      syst = systs[0] if single_syst else systs[j]
      if syst > 0 or not single_variation: h_syst_up[j+1] = sqrt(h_syst_up[j+1]*h_syst_up[j+1]+syst*syst)
      if syst < 0 or not single_variation: h_syst_dn[j+1] = sqrt(h_syst_dn[j+1]*h_syst_dn[j+1]+syst*syst)	       

    
def makeNjetsXaxis(hist):

  hist.GetXaxis().SetBinLabel(1,'0');
  hist.GetXaxis().SetBinLabel(2,'1');
  hist.GetXaxis().SetBinLabel(3,'2');
  hist.GetXaxis().SetBinLabel(4,'#geq 3');
  hist.GetXaxis().SetLabelSize(0.07);
  hist.GetXaxis().SetNdivisions(503,false)
      
  return
    
if __name__ == '__main__' :
    main()

  
