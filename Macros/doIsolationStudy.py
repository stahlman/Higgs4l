"""
Draw Pretty Plots ...
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'November 2011'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

import math
from ROOT import *
from PlotUtils import *

ROOT.gROOT.LoadMacro("AtlasStyle.C") 
ROOT.gROOT.LoadMacro("AtlasUtils.C") 
SetAtlasStyle()


#input options ---------------------------

default_calc = True

#output_tag = 'ML_HCP'; signal_tag = '160155_ML_HCP_passed'; ZZ_tag     = 'MC_ZZ_ML_HCP_passed'; zjets_tag  = 'Data_SS_ML_HCPfirstpair_passed'

#output_tag = 'ML_BL_Pix'; signal_tag = '160155_ML_BL_Pix_passed'; ZZ_tag     = 'MC_ZZ_ML_BL_Pix_passed'; zjets_tag  = 'Data_SS_ML_BL_Pixfirstpair_passed';default_calc = False

output_tag = 'LooseLikelihood_BL_Pix' ;signal_tag = '160155_LooseLikelihood_BL_Pix_passed';ZZ_tag     = 'MC_ZZ_LooseLikelihood_BL_Pix_passed';zjets_tag  = 'Data_SS_LooseLikelihood_BL_Pixfirstpair_passed';default_calc = False


#legend labels---------------------------


#ouput file tags ---------------------------

#label options ---------------------------

add_atlas_label = True
atlas_label_text = 'Internal'

add_lumi_label = False
lumi_label_text = "13.0 fb^{-1} #sqrt{s} = 8 TeV" 

add_label = True
label_text = output_tag 

#------------------------------------------------------

gStyle.SetOptStat(0)

w = 800
h = 600

input_dir  = '/afs/cern.ch/user/s/stahlman/NewIsoStudies/'
output_dir = '/local_data1/stahlman/output/HSG2_output/IsoStudies/'


#------------------------------------------------------
#HCP note yields

signal_yield_4e_HCP = 1.47
ZZ_yield_4e_HCP     = 0.77
Zjets_yield_4e_HCP  = 1.2

signal_yield_2mu2e_HCP = 1.39
ZZ_yield_2mu2e_HCP     = 0.56
Zjets_yield_2mu2e_HCP  = 0.78

signal_delta_4e_HCP = 0.22 / signal_yield_4e_HCP
ZZ_delta_4e_HCP     = 0.08 / ZZ_yield_4e_HCP   
Zjets_delta_4e_HCP  = 0.19 / Zjets_yield_4e_HCP

signal_delta_2mu2e_HCP = 0.20 / signal_yield_2mu2e_HCP
ZZ_delta_2mu2e_HCP     = 0.04 / ZZ_yield_2mu2e_HCP   
Zjets_delta_2mu2e_HCP  = 0.16 / Zjets_yield_2mu2e_HCP

scale = 20./13.

#Default Yields for ML analysis
signal_yield_4e_default = 0.0983301570152
ZZ_yield_4e_default	= 0.141877248405
Zjets_yield_4e_default  = 723.0

signal_yield_2mu2e_default = 0.101637707948
ZZ_yield_2mu2e_default     = 0.0829355790081
Zjets_yield_2mu2e_default  = 892.0

hists = []

#Retrieve Data histograms ------------------------------------------------------------------------------------------------------------
print 'Retrieving histograms from files:'

signal_fin = TFile(input_dir  + signal_tag + ".root")
ZZ_fin     = TFile(input_dir  + ZZ_tag     + ".root")
Zjets_fin  = TFile(input_dir  + zjets_tag  + ".root")

#---------------------------------
hist_name = 'h_max_trkiso20_vs_caloiso20_sr_4e'
signal_iso20_4e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(signal_iso20_4e)
ZZ_iso20_4e     = ZZ_fin.Get(hist_name).Clone(hist_name+'_ZZ'); hists.append(ZZ_iso20_4e)

hist_name = 'h_trkiso20_vs_caloiso20_secondpair_4e'
Zjets_iso20_4e     = Zjets_fin.Get(hist_name).Clone(hist_name+'_Zjets'); hists.append(Zjets_iso20_4e)

hist_name = 'h_max_trkiso30_vs_caloiso30_sr_4e'
signal_iso30_4e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(signal_iso30_4e)
ZZ_iso30_4e     = ZZ_fin.Get(hist_name).Clone(hist_name+'_ZZ'); hists.append(ZZ_iso30_4e)

hist_name = 'h_trkiso30_vs_caloiso30_secondpair_4e'
Zjets_iso30_4e     = Zjets_fin.Get(hist_name).Clone(hist_name+'_Zjets'); hists.append(Zjets_iso30_4e)

hist_name = 'h_max_trkiso40_vs_caloiso40_sr_4e'
signal_iso40_4e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(signal_iso40_4e)
ZZ_iso40_4e     = ZZ_fin.Get(hist_name).Clone(hist_name+'_ZZ'); hists.append(ZZ_iso40_4e)

hist_name = 'h_trkiso40_vs_caloiso40_secondpair_4e'
Zjets_iso40_4e     = Zjets_fin.Get(hist_name).Clone(hist_name+'_Zjets'); hists.append(Zjets_iso40_4e)

#---------------------------------
hist_name = 'h_max_trkiso20_vs_caloiso20_sr_2mu2e'
signal_iso20_2mu2e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(signal_iso20_2mu2e)
ZZ_iso20_2mu2e     = ZZ_fin.Get(hist_name).Clone(hist_name+'_ZZ'); hists.append(ZZ_iso20_2mu2e)

hist_name = 'h_trkiso20_vs_caloiso20_secondpair_2mu2e'
Zjets_iso20_2mu2e     = Zjets_fin.Get(hist_name).Clone(hist_name+'_Zjets'); hists.append(Zjets_iso20_2mu2e)

hist_name = 'h_max_trkiso30_vs_caloiso30_sr_2mu2e'
signal_iso30_2mu2e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(signal_iso30_2mu2e)
ZZ_iso30_2mu2e     = ZZ_fin.Get(hist_name).Clone(hist_name+'_ZZ'); hists.append(ZZ_iso30_2mu2e)

hist_name = 'h_trkiso30_vs_caloiso30_secondpair_2mu2e'
Zjets_iso30_2mu2e     = Zjets_fin.Get(hist_name).Clone(hist_name+'_Zjets'); hists.append(Zjets_iso30_2mu2e)

hist_name = 'h_max_trkiso40_vs_caloiso40_sr_2mu2e'
signal_iso40_2mu2e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(signal_iso40_2mu2e)
ZZ_iso40_2mu2e     = ZZ_fin.Get(hist_name).Clone(hist_name+'_ZZ'); hists.append(ZZ_iso40_2mu2e)

hist_name = 'h_trkiso40_vs_caloiso40_secondpair_2mu2e'
Zjets_iso40_2mu2e     = Zjets_fin.Get(hist_name).Clone(hist_name+'_Zjets'); hists.append(Zjets_iso40_2mu2e)

#---------------------------------
hist_name = 'h_mu_4e'
h_signal_mu_4e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(h_signal_mu_4e)
h_signal_mu_4e.Rebin(4)

hist_name = 'h_mu_defiso_4e'
h_signal_mu_defiso_4e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(h_signal_mu_defiso_4e)
h_signal_mu_defiso_4e.Rebin(4)

hist_name = 'h_mu_optiso_4e'
h_signal_mu_optiso_4e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(h_signal_mu_optiso_4e)
h_signal_mu_optiso_4e.Rebin(4)

hist_name = 'h_nvertex_4e'
h_signal_nvertex_4e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(h_signal_nvertex_4e)
h_signal_nvertex_4e.Rebin(4)

hist_name = 'h_nvertex_defiso_4e'
h_signal_nvertex_defiso_4e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(h_signal_nvertex_defiso_4e)
h_signal_nvertex_defiso_4e.Rebin(4)

hist_name = 'h_nvertex_optiso_4e'
h_signal_nvertex_optiso_4e = signal_fin.Get(hist_name).Clone(hist_name+'_signal'); hists.append(h_signal_nvertex_optiso_4e)
h_signal_nvertex_optiso_4e.Rebin(4)

hist_name = 'h_mu_4e'
h_zjets_mu_4e = Zjets_fin.Get(hist_name).Clone(hist_name+'_zjets'); hists.append(h_zjets_mu_4e)
h_zjets_mu_4e.Rebin(8)

hist_name = 'h_mu_defiso_4e'
h_zjets_mu_defiso_4e = Zjets_fin.Get(hist_name).Clone(hist_name+'_zjets'); hists.append(h_zjets_mu_defiso_4e)
h_zjets_mu_defiso_4e.Rebin(8)

hist_name = 'h_mu_optiso_4e'
h_zjets_mu_optiso_4e = Zjets_fin.Get(hist_name).Clone(hist_name+'_zjets'); hists.append(h_zjets_mu_optiso_4e)
h_zjets_mu_optiso_4e.Rebin(8)

hist_name = 'h_nvertex_4e'
h_zjets_nvertex_4e = Zjets_fin.Get(hist_name).Clone(hist_name+'_zjets'); hists.append(h_zjets_nvertex_4e)
h_zjets_nvertex_4e.Rebin(8)

hist_name = 'h_nvertex_defiso_4e'
h_zjets_nvertex_defiso_4e = Zjets_fin.Get(hist_name).Clone(hist_name+'_zjets'); hists.append(h_zjets_nvertex_defiso_4e)
h_zjets_nvertex_defiso_4e.Rebin(8)

hist_name = 'h_nvertex_optiso_4e'
h_zjets_nvertex_optiso_4e = Zjets_fin.Get(hist_name).Clone(hist_name+'_zjets'); hists.append(h_zjets_nvertex_optiso_4e)
h_zjets_nvertex_optiso_4e.Rebin(8)


#Define derived histograms ------------------------------------------------------------------------------------------------------------
print 'Defining derived histograms'

default_bin_x = signal_iso20_4e.GetXaxis().FindBin(0.15)
default_bin_y = signal_iso20_4e.GetYaxis().FindBin(0.20)

#make cumulative distributions
signal_iso20_4e_cumulative = CumulativeDistribution2D(signal_iso20_4e); hists.append(signal_iso20_4e_cumulative)
ZZ_iso20_4e_cumulative     = CumulativeDistribution2D(ZZ_iso20_4e); hists.append(ZZ_iso20_4e_cumulative)
Zjets_iso20_4e_cumulative  = CumulativeDistribution2D(Zjets_iso20_4e); hists.append(Zjets_iso20_4e_cumulative)

signal_iso30_4e_cumulative = CumulativeDistribution2D(signal_iso30_4e); hists.append(signal_iso30_4e_cumulative)
ZZ_iso30_4e_cumulative     = CumulativeDistribution2D(ZZ_iso30_4e); hists.append(ZZ_iso30_4e_cumulative)
Zjets_iso30_4e_cumulative  = CumulativeDistribution2D(Zjets_iso30_4e); hists.append(Zjets_iso30_4e_cumulative)

signal_iso40_4e_cumulative = CumulativeDistribution2D(signal_iso40_4e); hists.append(signal_iso40_4e_cumulative)
ZZ_iso40_4e_cumulative     = CumulativeDistribution2D(ZZ_iso40_4e); hists.append(ZZ_iso40_4e_cumulative)
Zjets_iso40_4e_cumulative  = CumulativeDistribution2D(Zjets_iso40_4e); hists.append(Zjets_iso40_4e_cumulative)

#----------------------------

signal_iso20_2mu2e_cumulative = CumulativeDistribution2D(signal_iso20_2mu2e); hists.append(signal_iso20_2mu2e_cumulative)
ZZ_iso20_2mu2e_cumulative     = CumulativeDistribution2D(ZZ_iso20_2mu2e); hists.append(ZZ_iso20_2mu2e_cumulative)
Zjets_iso20_2mu2e_cumulative  = CumulativeDistribution2D(Zjets_iso20_2mu2e); hists.append(Zjets_iso20_2mu2e_cumulative)

signal_iso30_2mu2e_cumulative = CumulativeDistribution2D(signal_iso30_2mu2e); hists.append(signal_iso30_2mu2e_cumulative)
ZZ_iso30_2mu2e_cumulative     = CumulativeDistribution2D(ZZ_iso30_2mu2e); hists.append(ZZ_iso30_2mu2e_cumulative)
Zjets_iso30_2mu2e_cumulative  = CumulativeDistribution2D(Zjets_iso30_2mu2e); hists.append(Zjets_iso30_2mu2e_cumulative)

signal_iso40_2mu2e_cumulative = CumulativeDistribution2D(signal_iso40_2mu2e); hists.append(signal_iso40_2mu2e_cumulative)
ZZ_iso40_2mu2e_cumulative     = CumulativeDistribution2D(ZZ_iso40_2mu2e); hists.append(ZZ_iso40_2mu2e_cumulative)
Zjets_iso40_2mu2e_cumulative  = CumulativeDistribution2D(Zjets_iso40_2mu2e); hists.append(Zjets_iso40_2mu2e_cumulative)

#----------------------------

h_signal_yield_iso20_4e = signal_iso20_4e.Clone('h_signal_yield_iso20_4e'); hists.append(h_signal_yield_iso20_4e)
h_ZZ_yield_iso20_4e     = ZZ_iso20_4e.Clone('h_ZZ_yield_iso20_4e'); hists.append(h_ZZ_yield_iso20_4e)
h_Zjets_yield_iso20_4e  = Zjets_iso20_4e.Clone('h_Zjets_yield_iso20_4e'); hists.append(h_Zjets_yield_iso20_4e)

h_signal_yield_iso30_4e = signal_iso30_4e.Clone('h_signal_yield_iso30_4e'); hists.append(h_signal_yield_iso30_4e)
h_ZZ_yield_iso30_4e     = ZZ_iso30_4e.Clone('h_ZZ_yield_iso30_4e'); hists.append(h_ZZ_yield_iso30_4e)
h_Zjets_yield_iso30_4e  = Zjets_iso30_4e.Clone('h_Zjets_yield_iso30_4e'); hists.append(h_Zjets_yield_iso30_4e)

h_signal_yield_iso40_4e = signal_iso40_4e.Clone('h_signal_yield_iso40_4e'); hists.append(h_signal_yield_iso40_4e)
h_ZZ_yield_iso40_4e     = ZZ_iso40_4e.Clone('h_ZZ_yield_iso40_4e'); hists.append(h_ZZ_yield_iso40_4e)
h_Zjets_yield_iso40_4e  = Zjets_iso40_4e.Clone('h_Zjets_yield_iso40_4e'); hists.append(h_Zjets_yield_iso40_4e)

h_signal_yield_iso20_2mu2e = signal_iso20_2mu2e.Clone('h_signal_yield_iso20_2mu2e'); hists.append(h_signal_yield_iso20_2mu2e)
h_ZZ_yield_iso20_2mu2e     = ZZ_iso20_2mu2e.Clone('h_ZZ_yield_iso20_2mu2e'); hists.append(h_ZZ_yield_iso20_2mu2e)
h_Zjets_yield_iso20_2mu2e  = Zjets_iso20_2mu2e.Clone('h_Zjets_yield_iso20_2mu2e'); hists.append(h_Zjets_yield_iso20_2mu2e)

h_signal_yield_iso30_2mu2e = signal_iso30_2mu2e.Clone('h_signal_yield_iso30_2mu2e'); hists.append(h_signal_yield_iso30_2mu2e)
h_ZZ_yield_iso30_2mu2e     = ZZ_iso30_2mu2e.Clone('h_ZZ_yield_iso30_2mu2e'); hists.append(h_ZZ_yield_iso30_2mu2e)
h_Zjets_yield_iso30_2mu2e  = Zjets_iso30_2mu2e.Clone('h_Zjets_yield_iso30_2mu2e'); hists.append(h_Zjets_yield_iso30_2mu2e)

h_signal_yield_iso40_2mu2e = signal_iso40_2mu2e.Clone('h_signal_yield_iso40_2mu2e'); hists.append(h_signal_yield_iso40_2mu2e)
h_ZZ_yield_iso40_2mu2e     = ZZ_iso40_2mu2e.Clone('h_ZZ_yield_iso40_2mu2e'); hists.append(h_ZZ_yield_iso40_2mu2e)
h_Zjets_yield_iso40_2mu2e  = Zjets_iso40_2mu2e.Clone('h_Zjets_yield_iso40_2mu2e'); hists.append(h_Zjets_yield_iso40_2mu2e)

#----------------------------

h_significance_iso20_4e = signal_iso20_4e.Clone('h_significance_iso20_4e');hists.append(h_significance_iso20_4e)
h_significance_iso30_4e = signal_iso30_4e.Clone('h_significance_iso30_4e');hists.append(h_significance_iso30_4e)
h_significance_iso40_4e = signal_iso40_4e.Clone('h_significance_iso40_4e');hists.append(h_significance_iso40_4e)

h_significance_iso20_2mu2e = signal_iso20_2mu2e.Clone('h_significance_iso20_2mu2e');hists.append(h_significance_iso20_2mu2e)
h_significance_iso30_2mu2e = signal_iso30_2mu2e.Clone('h_significance_iso30_2mu2e');hists.append(h_significance_iso30_2mu2e)
h_significance_iso40_2mu2e = signal_iso40_2mu2e.Clone('h_significance_iso40_2mu2e');hists.append(h_significance_iso40_2mu2e)

h_modsignificance_iso20_4e = signal_iso20_4e.Clone('h_modsignificance_iso20_4e');hists.append(h_modsignificance_iso20_4e)
h_modsignificance_iso30_4e = signal_iso30_4e.Clone('h_modsignificance_iso30_4e');hists.append(h_modsignificance_iso30_4e)

###########################################################################################
#calculate yield for default isolation cuts - only do once, then results are stored at top
###########################################################################################

if (default_calc):
   signal_yield_4e_default = signal_iso20_4e.Integral(1,default_bin_x,1,default_bin_y)
   ZZ_yield_4e_default    = ZZ_iso20_4e.Integral(1,default_bin_x,1,default_bin_y)
   Zjets_yield_4e_default  = Zjets_iso20_4e.Integral(1,default_bin_x,1,default_bin_y)

   signal_yield_2mu2e_default = signal_iso20_2mu2e.Integral(1,default_bin_x,1,default_bin_y)
   ZZ_yield_2mu2e_default    = ZZ_iso20_2mu2e.Integral(1,default_bin_x,1,default_bin_y)
   Zjets_yield_2mu2e_default  = Zjets_iso20_2mu2e.Integral(1,default_bin_x,1,default_bin_y)


   print 'Default Cut Yields for scaling:'
   print '----------------------------------------'
   print signal_yield_4e_default
   print ZZ_yield_4e_default
   print Zjets_yield_4e_default

   print signal_yield_2mu2e_default
   print ZZ_yield_2mu2e_default
   print Zjets_yield_2mu2e_default
   print '----------------------------------------'
   print 'Copy these values to top of script'

###########################################################################################

#calculate significances

for i in range(h_significance_iso20_4e.GetNbinsX()):
  for j in range(h_significance_iso20_4e.GetNbinsY()):
  
    signal = scale*signal_yield_4e_HCP*signal_iso20_4e_cumulative.GetBinContent(i,j)/signal_yield_4e_default
    h_signal_yield_iso20_4e.SetBinContent(i,j,signal)

    background = 0
    
    ZZ_yield = scale*ZZ_yield_4e_HCP*ZZ_iso20_4e_cumulative.GetBinContent(i,j)/ZZ_yield_4e_default
    background += ZZ_yield
    h_ZZ_yield_iso20_4e.SetBinContent(i,j, ZZ_yield)

    zjets_scale = Zjets_iso20_4e_cumulative.GetBinContent(i,j)*Zjets_iso20_4e_cumulative.GetBinContent(i,j)/Zjets_yield_4e_default/Zjets_yield_4e_default
    zjets_yield = scale*Zjets_yield_4e_HCP*zjets_scale
    background += zjets_yield
    h_Zjets_yield_iso20_4e.SetBinContent(i,j, zjets_yield)

    sig = 0
    if (background != 0):
      sig = sqrt(2*((signal+background)*log(1+signal/background)-signal))

    h_significance_iso20_4e.SetBinContent(i,j,sig)
    
    #calculate mod significance
    delta_b_over_s_zjets = 0
    if (signal != 0): 
      delta_b_over_s_zjets = (Zjets_delta_4e_HCP)*zjets_yield/signal

    delta_b_over_s_ZZ = 0
    if (signal != 0): 
      delta_b_over_s_ZZ = (ZZ_delta_4e_HCP)*ZZ_yield/signal

    mod_sig = 0
    if (sig != 0): 
      mod_sig = 1/sqrt( 1/sig/sig + delta_b_over_s_zjets*delta_b_over_s_zjets + delta_b_over_s_ZZ*delta_b_over_s_ZZ )

    h_modsignificance_iso20_4e.SetBinContent(i,j,mod_sig)

for i in range(h_significance_iso30_4e.GetNbinsX()):
  for j in range(h_significance_iso30_4e.GetNbinsY()):
  
    signal = scale*signal_yield_4e_HCP*signal_iso30_4e_cumulative.GetBinContent(i,j)/signal_yield_4e_default
    h_signal_yield_iso30_4e.SetBinContent(i,j,signal)

    background = 0
    
    ZZ_yield = scale*ZZ_yield_4e_HCP*ZZ_iso30_4e_cumulative.GetBinContent(i,j)/ZZ_yield_4e_default
    background += ZZ_yield
    h_ZZ_yield_iso30_4e.SetBinContent(i,j, ZZ_yield)

    zjets_scale = Zjets_iso30_4e_cumulative.GetBinContent(i,j)*Zjets_iso30_4e_cumulative.GetBinContent(i,j)/Zjets_yield_4e_default/Zjets_yield_4e_default
    zjets_yield = scale*Zjets_yield_4e_HCP*zjets_scale
    background += zjets_yield
    h_Zjets_yield_iso30_4e.SetBinContent(i,j, zjets_yield)

    sig = 0
    if (background != 0):
      sig = sqrt(2*((signal+background)*log(1+signal/background)-signal))

    h_significance_iso30_4e.SetBinContent(i,j,sig)

    #calculate mod significance
    delta_b_over_s_zjets = 0
    if (signal != 0): 
      delta_b_over_s_zjets = (Zjets_delta_4e_HCP)*zjets_yield/signal

    delta_b_over_s_ZZ = 0
    if (signal != 0): 
      delta_b_over_s_ZZ = (ZZ_delta_4e_HCP)*ZZ_yield/signal

    mod_sig = 0
    if (sig != 0): 
      mod_sig = 1/sqrt( 1/sig/sig + delta_b_over_s_zjets*delta_b_over_s_zjets + delta_b_over_s_ZZ*delta_b_over_s_ZZ )

    h_modsignificance_iso30_4e.SetBinContent(i,j,mod_sig)

for i in range(h_significance_iso40_4e.GetNbinsX()):
  for j in range(h_significance_iso40_4e.GetNbinsY()):
  
    signal = scale*signal_yield_4e_HCP*signal_iso40_4e_cumulative.GetBinContent(i,j)/signal_yield_4e_default
    h_signal_yield_iso40_4e.SetBinContent(i,j,signal)

    background = scale*ZZ_yield_4e_HCP*ZZ_iso40_4e_cumulative.GetBinContent(i,j)/ZZ_yield_4e_default
    h_ZZ_yield_iso40_4e.SetBinContent(i,j, background)

    zjets_scale = Zjets_iso40_4e_cumulative.GetBinContent(i,j)*Zjets_iso40_4e_cumulative.GetBinContent(i,j)/Zjets_yield_4e_default/Zjets_yield_4e_default
    background += scale*Zjets_yield_4e_HCP*zjets_scale
    h_Zjets_yield_iso40_4e.SetBinContent(i,j, scale*Zjets_yield_4e_HCP*zjets_scale)

    sig = 0
    if (background != 0):
      sig = sqrt(2*((signal+background)*log(1+signal/background)-signal))

    h_significance_iso40_4e.SetBinContent(i,j,sig)

for i in range(h_significance_iso20_2mu2e.GetNbinsX()):
  for j in range(h_significance_iso20_2mu2e.GetNbinsY()):
  
    signal = scale*signal_yield_2mu2e_HCP*signal_iso20_2mu2e_cumulative.GetBinContent(i,j)/signal_yield_2mu2e_default
    h_signal_yield_iso20_2mu2e.SetBinContent(i,j,signal)

    background = scale*ZZ_yield_2mu2e_HCP*ZZ_iso20_2mu2e_cumulative.GetBinContent(i,j)/ZZ_yield_2mu2e_default
    h_ZZ_yield_iso20_2mu2e.SetBinContent(i,j, background)

    zjets_scale = Zjets_iso20_2mu2e_cumulative.GetBinContent(i,j)*Zjets_iso20_2mu2e_cumulative.GetBinContent(i,j)/Zjets_yield_2mu2e_default/Zjets_yield_2mu2e_default
    background += scale*Zjets_yield_2mu2e_HCP*zjets_scale
    h_Zjets_yield_iso20_2mu2e.SetBinContent(i,j, scale*Zjets_yield_2mu2e_HCP*zjets_scale)

    sig = 0
    if (background != 0):
      sig = sqrt(2*((signal+background)*log(1+signal/background)-signal))

    h_significance_iso20_2mu2e.SetBinContent(i,j,sig)

for i in range(h_significance_iso30_2mu2e.GetNbinsX()):
  for j in range(h_significance_iso30_2mu2e.GetNbinsY()):
  
    signal = scale*signal_yield_2mu2e_HCP*signal_iso30_2mu2e_cumulative.GetBinContent(i,j)/signal_yield_2mu2e_default
    h_signal_yield_iso30_2mu2e.SetBinContent(i,j,signal)

    background = scale*ZZ_yield_2mu2e_HCP*ZZ_iso30_2mu2e_cumulative.GetBinContent(i,j)/ZZ_yield_2mu2e_default
    h_ZZ_yield_iso30_2mu2e.SetBinContent(i,j, background)

    zjets_scale = Zjets_iso30_2mu2e_cumulative.GetBinContent(i,j)*Zjets_iso30_2mu2e_cumulative.GetBinContent(i,j)/Zjets_yield_2mu2e_default/Zjets_yield_2mu2e_default
    background += scale*Zjets_yield_2mu2e_HCP*zjets_scale
    h_Zjets_yield_iso30_2mu2e.SetBinContent(i,j, scale*Zjets_yield_2mu2e_HCP*zjets_scale)

    sig = 0
    if (background != 0):
      sig = sqrt(2*((signal+background)*log(1+signal/background)-signal))

    h_significance_iso30_2mu2e.SetBinContent(i,j,sig)

for i in range(h_significance_iso40_2mu2e.GetNbinsX()):
  for j in range(h_significance_iso40_2mu2e.GetNbinsY()):
  
    signal = scale*signal_yield_2mu2e_HCP*signal_iso40_2mu2e_cumulative.GetBinContent(i,j)/signal_yield_2mu2e_default
    h_signal_yield_iso40_2mu2e.SetBinContent(i,j,signal)

    background = scale*ZZ_yield_2mu2e_HCP*ZZ_iso40_2mu2e_cumulative.GetBinContent(i,j)/ZZ_yield_2mu2e_default
    h_ZZ_yield_iso40_2mu2e.SetBinContent(i,j, background)

    zjets_scale = Zjets_iso40_2mu2e_cumulative.GetBinContent(i,j)*Zjets_iso40_2mu2e_cumulative.GetBinContent(i,j)/Zjets_yield_2mu2e_default/Zjets_yield_2mu2e_default
    background += scale*Zjets_yield_2mu2e_HCP*zjets_scale
    h_Zjets_yield_iso40_2mu2e.SetBinContent(i,j, scale*Zjets_yield_2mu2e_HCP*zjets_scale)

    sig = 0
    if (background != 0):
      sig = sqrt(2*((signal+background)*log(1+signal/background)-signal))

    h_significance_iso40_2mu2e.SetBinContent(i,j,sig)


# check pileup effect in efficiency
h_signal_mu_defiso_ratio_4e = h_signal_mu_defiso_4e.Clone('h_signal_mu_defiso_ratio_4e')
h_signal_mu_defiso_ratio_4e.Divide(h_signal_mu_4e)

h_signal_mu_optiso_ratio_4e = h_signal_mu_optiso_4e.Clone('h_signal_mu_optiso_ratio_4e')
h_signal_mu_optiso_ratio_4e.Divide(h_signal_mu_4e)

h_signal_nvertex_defiso_ratio_4e = h_signal_nvertex_defiso_4e.Clone('h_signal_nvertex_defiso_ratio_4e')
h_signal_nvertex_defiso_ratio_4e.Divide(h_signal_nvertex_4e)

h_signal_nvertex_optiso_ratio_4e = h_signal_nvertex_optiso_4e.Clone('h_signal_nvertex_optiso_ratio_4e')
h_signal_nvertex_optiso_ratio_4e.Divide(h_signal_nvertex_4e)


h_zjets_mu_defiso_ratio_4e = h_zjets_mu_defiso_4e.Clone('h_zjets_mu_defiso_ratio_4e')
h_zjets_mu_defiso_ratio_4e.Divide(h_zjets_mu_4e)

h_zjets_mu_optiso_ratio_4e = h_zjets_mu_optiso_4e.Clone('h_zjets_mu_optiso_ratio_4e')
h_zjets_mu_optiso_ratio_4e.Divide(h_zjets_mu_4e)

h_zjets_nvertex_defiso_ratio_4e = h_zjets_nvertex_defiso_4e.Clone('h_zjets_nvertex_defiso_ratio_4e')
h_zjets_nvertex_defiso_ratio_4e.Divide(h_zjets_nvertex_4e)

h_zjets_nvertex_optiso_ratio_4e = h_zjets_nvertex_optiso_4e.Clone('h_zjets_nvertex_optiso_ratio_4e')
h_zjets_nvertex_optiso_ratio_4e.Divide(h_zjets_nvertex_4e)

#Begin drawing ------------------------------------------------------------------------------------------------------------
print 'Drawing results'

fout = TFile(output_dir+'IsolationStudy2D.'+ output_tag + '.root', 'RECREATE')

fout.cd()


max_sig_4e = max(h_significance_iso20_4e.GetMaximum(),h_significance_iso30_4e.GetMaximum(),h_significance_iso40_4e.GetMaximum())

c_significance_iso20_4e = TCanvas('c_significance_iso20_4e','',w,h)

h_significance_iso20_4e.GetXaxis().SetRangeUser(0,0.5)
h_significance_iso20_4e.GetYaxis().SetRangeUser(0,0.5)
h_significance_iso20_4e.SetTitle('')
#h_significance_iso20_4e.GetXaxis().SetTitle('Cut')
h_significance_iso20_4e.GetZaxis().SetRangeUser(max_sig_4e*0.95,max_sig_4e)
h_significance_iso20_4e.GetZaxis().SetTitle('Z_{0}')
Plot2DMap(h_significance_iso20_4e)

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text + ' 4e')

c_significance_iso20_4e.Write()

##--------------------------------------

c_significance_iso30_4e = TCanvas('c_significance_iso30_4e','',w,h)

h_significance_iso30_4e.GetXaxis().SetRangeUser(0,0.5)
h_significance_iso30_4e.GetYaxis().SetRangeUser(0,0.5)
h_significance_iso30_4e.SetTitle('')
#h_significance_iso30_4e.GetXaxis().SetTitle('Cut')
h_significance_iso30_4e.GetZaxis().SetRangeUser(max_sig_4e*0.95,max_sig_4e)
h_significance_iso30_4e.GetZaxis().SetTitle('Z_{0}')
Plot2DMap(h_significance_iso30_4e)

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text + ' 4e')

c_significance_iso30_4e.Write()

##--------------------------------------

c_significance_iso40_4e = TCanvas('c_significance_iso40_4e','',w,h)

h_significance_iso40_4e.GetXaxis().SetRangeUser(0,0.5)
h_significance_iso40_4e.GetYaxis().SetRangeUser(0,0.5)
h_significance_iso40_4e.SetTitle('')
#h_significance_iso40_4e.GetXaxis().SetTitle('Cut')
h_significance_iso40_4e.GetZaxis().SetRangeUser(max_sig_4e*0.95,max_sig_4e)
h_significance_iso40_4e.GetZaxis().SetTitle('Z_{0}')
Plot2DMap(h_significance_iso40_4e)

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text + ' 4e')

c_significance_iso40_4e.Write()

##--------------------------------------

max_sig_2mu2e = max(h_significance_iso20_2mu2e.GetMaximum(),h_significance_iso30_2mu2e.GetMaximum(),h_significance_iso40_2mu2e.GetMaximum())

c_significance_iso20_2mu2e = TCanvas('c_significance_iso20_2mu2e','',w,h)
c_significance_iso20_2mu2e.SetRightMargin(0.18)

h_significance_iso20_2mu2e.GetXaxis().SetRangeUser(0,0.5)
h_significance_iso20_2mu2e.GetYaxis().SetRangeUser(0,0.5)
h_significance_iso20_2mu2e.SetTitle('')
#h_significance_iso20_2mu2e.GetXaxis().SetTitle('Cut')
h_significance_iso20_2mu2e.GetZaxis().SetRangeUser(max_sig_2mu2e*0.95,max_sig_2mu2e)
h_significance_iso20_2mu2e.GetZaxis().SetTitle('Z_{0}')
Plot2DMap(h_significance_iso20_2mu2e)

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text + ' 2mu2e')

c_significance_iso20_2mu2e.Write()

##--------------------------------------

c_significance_iso30_2mu2e = TCanvas('c_significance_iso30_2mu2e','',w,h)

h_significance_iso30_2mu2e.GetXaxis().SetRangeUser(0,0.5)
h_significance_iso30_2mu2e.GetYaxis().SetRangeUser(0,0.5)
h_significance_iso30_2mu2e.SetTitle('')
#h_significance_iso30_2mu2e.GetXaxis().SetTitle('Cut')
h_significance_iso30_2mu2e.GetZaxis().SetRangeUser(max_sig_2mu2e*0.95,max_sig_2mu2e)
h_significance_iso30_2mu2e.GetZaxis().SetTitle('Z_{0}')
Plot2DMap(h_significance_iso30_2mu2e)

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text + ' 2mu2e')

c_significance_iso30_2mu2e.Write()

##--------------------------------------

c_significance_iso40_2mu2e = TCanvas('c_significance_iso40_2mu2e','',w,h)

h_significance_iso40_2mu2e.GetXaxis().SetRangeUser(0,0.5)
h_significance_iso40_2mu2e.GetYaxis().SetRangeUser(0,0.5)
h_significance_iso40_2mu2e.SetTitle('')
#h_significance_iso40_2mu2e.GetXaxis().SetTitle('Cut')
h_significance_iso40_2mu2e.GetZaxis().SetRangeUser(max_sig_2mu2e*0.95,max_sig_2mu2e)
h_significance_iso40_2mu2e.GetZaxis().SetTitle('Z_{0}')
Plot2DMap(h_significance_iso40_2mu2e)

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text + ' 2mu2e')

c_significance_iso40_2mu2e.Write()

##--------------------------------------

c_signal_mu_defiso_ratio_4 = TCanvas('c_signal_mu_defiso_ratio_4','',w,h)

#h_signal_mu_defiso_ratio_4e.GetXaxis().SetRangeUser(0,0.5)
#h_signal_mu_defiso_ratio_4e.GetYaxis().SetRangeUser(0.9,1.6)
h_signal_mu_defiso_ratio_4e.SetTitle('')
h_signal_mu_defiso_ratio_4e.GetXaxis().SetTitle('#mu')
h_signal_mu_defiso_ratio_4e.GetYaxis().SetTitle('#epsilon')
h_signal_mu_defiso_ratio_4e.Draw("LEP")

h_signal_mu_optiso_ratio_4e.SetMarkerColor(kRed)
h_signal_mu_optiso_ratio_4e.SetLineColor(kRed)
h_signal_mu_optiso_ratio_4e.Draw("LEPSAME")

leg_signal_mu_defiso_ratio_4e = TLegend(0.7, 0.7, 0.9,0.9)

leg_signal_mu_defiso_ratio_4e.AddEntry(h_signal_mu_defiso_ratio_4e,"Default (Cone20)" ,'lep')
leg_signal_mu_defiso_ratio_4e.AddEntry(h_signal_mu_optiso_ratio_4e,"Optimal (Cone30)"  ,'lep')

FormatLegend(leg_signal_mu_defiso_ratio_4e)
leg_signal_mu_defiso_ratio_4e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_signal_mu_defiso_ratio_4.Write()

#--------------------------------------

c_signal_nvertex_defiso_ratio_4 = TCanvas('c_signal_nvertex_defiso_ratio_4','',w,h)

#h_signal_nvertex_defiso_ratio_4e.GetXaxis().SetRangeUser(0,0.5)
#h_signal_nvertex_defiso_ratio_4e.GetYaxis().SetRangeUser(0.9,1.6)
h_signal_nvertex_defiso_ratio_4e.SetTitle('')
h_signal_nvertex_defiso_ratio_4e.GetXaxis().SetTitle('N_{Vertex}')
h_signal_nvertex_defiso_ratio_4e.GetYaxis().SetTitle('#epsilon')
h_signal_nvertex_defiso_ratio_4e.Draw("LEP")

h_signal_nvertex_optiso_ratio_4e.SetMarkerColor(kRed)
h_signal_nvertex_optiso_ratio_4e.SetLineColor(kRed)
h_signal_nvertex_optiso_ratio_4e.Draw("LEPSAME")

leg_signal_nvertex_defiso_ratio_4e = TLegend(0.7, 0.7, 0.9,0.9)

leg_signal_nvertex_defiso_ratio_4e.AddEntry(h_signal_nvertex_defiso_ratio_4e,"Default (Cone20)" ,'lep')
leg_signal_nvertex_defiso_ratio_4e.AddEntry(h_signal_nvertex_optiso_ratio_4e,"Optimal (Cone30)"  ,'lep')

FormatLegend(leg_signal_nvertex_defiso_ratio_4e)
leg_signal_nvertex_defiso_ratio_4e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_signal_nvertex_defiso_ratio_4.Write()

#--------------------------------------

c_zjets_mu_defiso_ratio_4 = TCanvas('c_zjets_mu_defiso_ratio_4','',w,h)

#h_zjets_mu_defiso_ratio_4e.GetXaxis().SetRangeUser(0,0.5)
h_zjets_mu_defiso_ratio_4e.GetYaxis().SetRangeUser(0,0.5)
h_zjets_mu_defiso_ratio_4e.SetTitle('')
h_zjets_mu_defiso_ratio_4e.GetXaxis().SetTitle('#mu')
h_zjets_mu_defiso_ratio_4e.GetYaxis().SetTitle('#epsilon')
h_zjets_mu_defiso_ratio_4e.Draw("LEP")

h_zjets_mu_optiso_ratio_4e.SetMarkerColor(kRed)
h_zjets_mu_optiso_ratio_4e.SetLineColor(kRed)
h_zjets_mu_optiso_ratio_4e.Draw("LEPSAME")

leg_zjets_mu_defiso_ratio_4e = TLegend(0.7, 0.7, 0.9,0.9)

leg_zjets_mu_defiso_ratio_4e.AddEntry(h_zjets_mu_defiso_ratio_4e,"Default (Cone20)" ,'lep')
leg_zjets_mu_defiso_ratio_4e.AddEntry(h_zjets_mu_optiso_ratio_4e,"Optimal (Cone30)"  ,'lep')

FormatLegend(leg_zjets_mu_defiso_ratio_4e)
leg_zjets_mu_defiso_ratio_4e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_zjets_mu_defiso_ratio_4.Write()

#--------------------------------------

c_zjets_nvertex_defiso_ratio_4 = TCanvas('c_zjets_nvertex_defiso_ratio_4','',w,h)

#h_zjets_nvertex_defiso_ratio_4e.GetXaxis().SetRangeUser(0,0.5)
h_zjets_nvertex_defiso_ratio_4e.GetYaxis().SetRangeUser(0,0.5)
h_zjets_nvertex_defiso_ratio_4e.SetTitle('')
h_zjets_nvertex_defiso_ratio_4e.GetXaxis().SetTitle('N_{Vertex}')
h_zjets_nvertex_defiso_ratio_4e.GetYaxis().SetTitle('#epsilon')
h_zjets_nvertex_defiso_ratio_4e.Draw("LEP")

h_zjets_nvertex_optiso_ratio_4e.SetMarkerColor(kRed)
h_zjets_nvertex_optiso_ratio_4e.SetLineColor(kRed)
h_zjets_nvertex_optiso_ratio_4e.Draw("LEPSAME")

leg_zjets_nvertex_defiso_ratio_4e = TLegend(0.7, 0.7, 0.9,0.9)

leg_zjets_nvertex_defiso_ratio_4e.AddEntry(h_zjets_nvertex_defiso_ratio_4e,"Default (Cone20)" ,'lep')
leg_zjets_nvertex_defiso_ratio_4e.AddEntry(h_zjets_nvertex_optiso_ratio_4e,"Optimal (Cone30)"  ,'lep')

FormatLegend(leg_zjets_nvertex_defiso_ratio_4e)
leg_zjets_nvertex_defiso_ratio_4e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_zjets_nvertex_defiso_ratio_4.Write()

#--------------------------------------
print 'Information on optimal cuts for each histogram'
print '-------------------------'

#find 'optimal' cuts, significances, and yields

binx = Long(0)
biny = Long(0)
binz = Long(0)

#--------------------------------------


max_bin = h_significance_iso20_4e.GetMaximumBin()
h_significance_iso20_4e.GetBinXYZ(max_bin,binx,biny,binz)
opt_significance_iso20_4e = h_significance_iso20_4e.GetBinContent(max_bin)
opt_cut_trkiso20_4e       = h_significance_iso20_4e.GetXaxis().GetBinCenter(binx)
opt_cut_caloiso20_4e      = h_significance_iso20_4e.GetYaxis().GetBinCenter(biny)
opt_signal_yield_4e       = h_signal_yield_iso20_4e.GetBinContent(max_bin)
opt_ZZ_yield_4e           = h_ZZ_yield_iso20_4e.GetBinContent(max_bin)
opt_Zjets_yield_4e        = h_Zjets_yield_iso20_4e.GetBinContent(max_bin)

h_Zjets_yield_trkiso20_opt_4e  = h_Zjets_yield_iso20_4e.ProjectionX('h_Zjets_yield_trkiso20_opt_4e',biny,biny)
h_Zjets_yield_caloiso20_opt_4e = h_Zjets_yield_iso20_4e.ProjectionY('h_Zjets_yield_caloiso20_opt_4e',binx,binx)

h_significance_trkiso20_opt_4e  = h_significance_iso20_4e.ProjectionX('h_significance_trkiso20_opt_4e',biny,biny)
h_significance_caloiso20_opt_4e = h_significance_iso20_4e.ProjectionY('h_significance_caloiso20_opt_4e',binx,binx)

#--------------------------------------

print '4e channel, cone size 20'
print 'Optimal cuts - trk: ',opt_cut_trkiso20_4e, 'calo:', opt_cut_caloiso20_4e
print 'Significance: ', opt_significance_iso20_4e
print 'Yields:', opt_signal_yield_4e, opt_ZZ_yield_4e, opt_Zjets_yield_4e
print '-------------------------'

max_bin = h_significance_iso30_4e.GetMaximumBin()
h_significance_iso30_4e.GetBinXYZ(max_bin,binx,biny,binz)
opt_significance_iso30_4e = h_significance_iso30_4e.GetBinContent(max_bin)
opt_cut_trkiso30_4e       = h_significance_iso30_4e.GetXaxis().GetBinCenter(binx)
opt_cut_caloiso30_4e      = h_significance_iso30_4e.GetYaxis().GetBinCenter(biny)
opt_signal_yield_4e       = h_signal_yield_iso30_4e.GetBinContent(max_bin)
opt_ZZ_yield_4e           = h_ZZ_yield_iso30_4e.GetBinContent(max_bin)
opt_Zjets_yield_4e        = h_Zjets_yield_iso30_4e.GetBinContent(max_bin)

h_Zjets_yield_trkiso30_opt_4e  = h_Zjets_yield_iso30_4e.ProjectionX('h_Zjets_yield_trkiso30_opt_4e',biny,biny)
h_Zjets_yield_caloiso30_opt_4e = h_Zjets_yield_iso30_4e.ProjectionY('h_Zjets_yield_caloiso30_opt_4e',binx,binx)

h_significance_trkiso30_opt_4e  = h_significance_iso30_4e.ProjectionX('h_significance_trkiso30_opt_4e',biny,biny)
h_significance_caloiso30_opt_4e = h_significance_iso30_4e.ProjectionY('h_significance_caloiso30_opt_4e',binx,binx)


print '4e channel, cone size 30'
print 'Optimal cuts - trk: ',opt_cut_trkiso30_4e, 'calo:', opt_cut_caloiso30_4e
print 'Significance: ', opt_significance_iso30_4e
print 'Yields:', opt_signal_yield_4e, opt_ZZ_yield_4e, opt_Zjets_yield_4e
print '-------------------------'

#--------------------------------------

max_bin = h_significance_iso40_4e.GetMaximumBin()
h_significance_iso40_4e.GetBinXYZ(max_bin,binx,biny,binz)
opt_significance_iso40_4e = h_significance_iso40_4e.GetBinContent(max_bin)
opt_cut_trkiso40_4e       = h_significance_iso40_4e.GetXaxis().GetBinCenter(binx)
opt_cut_caloiso40_4e      = h_significance_iso40_4e.GetYaxis().GetBinCenter(biny)
opt_signal_yield_4e       = h_signal_yield_iso40_4e.GetBinContent(max_bin)
opt_ZZ_yield_4e           = h_ZZ_yield_iso40_4e.GetBinContent(max_bin)
opt_Zjets_yield_4e        = h_Zjets_yield_iso40_4e.GetBinContent(max_bin)

h_Zjets_yield_trkiso40_opt_4e  = h_Zjets_yield_iso40_4e.ProjectionX('h_Zjets_yield_trkiso40_opt_4e',biny,biny)
h_Zjets_yield_caloiso40_opt_4e = h_Zjets_yield_iso40_4e.ProjectionY('h_Zjets_yield_caloiso40_opt_4e',binx,binx)

h_significance_trkiso40_opt_4e  = h_significance_iso40_4e.ProjectionX('h_significance_trkiso40_opt_4e',biny,biny)
h_significance_caloiso40_opt_4e = h_significance_iso40_4e.ProjectionY('h_significance_caloiso40_opt_4e',binx,binx)


print '4e channel, cone size 40'
print 'Optimal cuts - trk: ',opt_cut_trkiso40_4e, 'calo:', opt_cut_caloiso40_4e
print 'Significance: ', opt_significance_iso40_4e
print 'Yields:', opt_signal_yield_4e, opt_ZZ_yield_4e, opt_Zjets_yield_4e
print '-------------------------'

#--------------------------------------

max_bin = h_significance_iso20_2mu2e.GetMaximumBin()
h_significance_iso20_2mu2e.GetBinXYZ(max_bin,binx,biny,binz)
opt_significance_iso20_2mu2e = h_significance_iso20_2mu2e.GetBinContent(max_bin)
opt_cut_trkiso20_2mu2e       = h_significance_iso20_2mu2e.GetXaxis().GetBinCenter(binx)
opt_cut_caloiso20_2mu2e      = h_significance_iso20_2mu2e.GetYaxis().GetBinCenter(biny)
opt_signal_yield_2mu2e       = h_signal_yield_iso20_2mu2e.GetBinContent(max_bin)
opt_ZZ_yield_2mu2e           = h_ZZ_yield_iso20_2mu2e.GetBinContent(max_bin)
opt_Zjets_yield_2mu2e        = h_Zjets_yield_iso20_2mu2e.GetBinContent(max_bin)

h_Zjets_yield_trkiso20_opt_2mu2e  = h_Zjets_yield_iso20_2mu2e.ProjectionX('h_Zjets_yield_trkiso20_opt_2mu2e',biny,biny)
h_Zjets_yield_caloiso20_opt_2mu2e = h_Zjets_yield_iso20_2mu2e.ProjectionY('h_Zjets_yield_caloiso20_opt_2mu2e',binx,binx)

h_significance_trkiso20_opt_2mu2e  = h_significance_iso20_2mu2e.ProjectionX('h_significance_trkiso20_opt_2mu2e',biny,biny)
h_significance_caloiso20_opt_2mu2e = h_significance_iso20_2mu2e.ProjectionY('h_significance_caloiso20_opt_2mu2e',binx,binx)

print '2mu2e channel, cone size 20'
print 'Optimal cuts - trk: ',opt_cut_trkiso20_2mu2e, 'calo:', opt_cut_caloiso20_2mu2e
print 'Significance: ', opt_significance_iso20_2mu2e
print 'Yields:', opt_signal_yield_2mu2e, opt_ZZ_yield_2mu2e, opt_Zjets_yield_2mu2e
print '-------------------------'

#--------------------------------------

max_bin = h_significance_iso30_2mu2e.GetMaximumBin()
h_significance_iso30_2mu2e.GetBinXYZ(max_bin,binx,biny,binz)
opt_significance_iso30_2mu2e = h_significance_iso30_2mu2e.GetBinContent(max_bin)
opt_cut_trkiso30_2mu2e       = h_significance_iso30_2mu2e.GetXaxis().GetBinCenter(binx)
opt_cut_caloiso30_2mu2e      = h_significance_iso30_2mu2e.GetYaxis().GetBinCenter(biny)
opt_signal_yield_2mu2e       = h_signal_yield_iso30_2mu2e.GetBinContent(max_bin)
opt_ZZ_yield_2mu2e           = h_ZZ_yield_iso30_2mu2e.GetBinContent(max_bin)
opt_Zjets_yield_2mu2e        = h_Zjets_yield_iso30_2mu2e.GetBinContent(max_bin)

h_Zjets_yield_trkiso30_opt_2mu2e  = h_Zjets_yield_iso30_2mu2e.ProjectionX('h_Zjets_yield_trkiso30_opt_2mu2e',biny,biny)
h_Zjets_yield_caloiso30_opt_2mu2e = h_Zjets_yield_iso30_2mu2e.ProjectionY('h_Zjets_yield_caloiso30_opt_2mu2e',binx,binx)

h_significance_trkiso30_opt_2mu2e  = h_significance_iso30_2mu2e.ProjectionX('h_significance_trkiso30_opt_2mu2e',biny,biny)
h_significance_caloiso30_opt_2mu2e = h_significance_iso30_2mu2e.ProjectionY('h_significance_caloiso30_opt_2mu2e',binx,binx)


print '2mu2e channel, cone size 30'
print 'Optimal cuts - trk: ',opt_cut_trkiso30_2mu2e, 'calo:', opt_cut_caloiso30_2mu2e
print 'Significance: ', opt_significance_iso30_2mu2e
print 'Yields:', opt_signal_yield_2mu2e, opt_ZZ_yield_2mu2e, opt_Zjets_yield_2mu2e
print '-------------------------'

#--------------------------------------

max_bin = h_significance_iso40_2mu2e.GetMaximumBin()
h_significance_iso40_2mu2e.GetBinXYZ(max_bin,binx,biny,binz)
opt_significance_iso40_2mu2e = h_significance_iso40_2mu2e.GetBinContent(max_bin)
opt_cut_trkiso40_2mu2e       = h_significance_iso40_2mu2e.GetXaxis().GetBinCenter(binx)
opt_cut_caloiso40_2mu2e      = h_significance_iso40_2mu2e.GetYaxis().GetBinCenter(biny)
opt_signal_yield_2mu2e       = h_signal_yield_iso40_2mu2e.GetBinContent(max_bin)
opt_ZZ_yield_2mu2e           = h_ZZ_yield_iso40_2mu2e.GetBinContent(max_bin)
opt_Zjets_yield_2mu2e        = h_Zjets_yield_iso40_2mu2e.GetBinContent(max_bin)

h_Zjets_yield_trkiso40_opt_2mu2e  = h_Zjets_yield_iso40_2mu2e.ProjectionX('h_Zjets_yield_trkiso40_opt_2mu2e',biny,biny)
h_Zjets_yield_caloiso40_opt_2mu2e = h_Zjets_yield_iso40_2mu2e.ProjectionY('h_Zjets_yield_caloiso40_opt_2mu2e',binx,binx)

h_significance_trkiso40_opt_2mu2e  = h_significance_iso40_2mu2e.ProjectionX('h_significance_trkiso40_opt_2mu2e',biny,biny)
h_significance_caloiso40_opt_2mu2e = h_significance_iso40_2mu2e.ProjectionY('h_significance_caloiso40_opt_2mu2e',binx,binx)


print '2mu2e channel, cone size 40'
print 'Optimal cuts - trk: ',opt_cut_trkiso40_2mu2e, 'calo:', opt_cut_caloiso40_2mu2e
print 'Significance: ', opt_significance_iso40_2mu2e
print 'Yields:', opt_signal_yield_2mu2e, opt_ZZ_yield_2mu2e, opt_Zjets_yield_2mu2e
print '-------------------------'

#--------------------------------------

print 'Default isolation cuts 4e:'
print 'Significance: ', h_significance_iso20_4e.GetBinContent(default_bin_x,default_bin_y)
print 'Signal: ', h_signal_yield_iso20_4e.GetBinContent(default_bin_x,default_bin_y)
print 'ZZ: ',     h_ZZ_yield_iso20_4e.GetBinContent(default_bin_x,default_bin_y)
print 'Zjets: ',  h_Zjets_yield_iso20_4e.GetBinContent(default_bin_x,default_bin_y)
print '-------------------------'

print 'Default isolation cuts 2mu2e:'
print 'Significance: ', h_significance_iso20_2mu2e.GetBinContent(default_bin_x,default_bin_y)
print 'Signal: ', h_signal_yield_iso20_2mu2e.GetBinContent(default_bin_x,default_bin_y)
print 'ZZ: ',     h_ZZ_yield_iso20_2mu2e.GetBinContent(default_bin_x,default_bin_y)
print 'Zjets: ',  h_Zjets_yield_iso20_2mu2e.GetBinContent(default_bin_x,default_bin_y)

print '-------------------------'

#--------------------------------------

c_significance_trkiso_opt_4e = TCanvas('c_significance_trkiso_opt_4e','',w,h)

#h_significance_trkiso20_opt_4e.GetXaxis().SetRangeUser(0,0.5)
h_significance_trkiso20_opt_4e.GetYaxis().SetRangeUser(1.35,1.6)
h_significance_trkiso20_opt_4e.SetTitle('')
h_significance_trkiso20_opt_4e.GetXaxis().SetTitle('TrkIso Cut')
h_significance_trkiso20_opt_4e.GetYaxis().SetTitle('Z_{0}')
h_significance_trkiso20_opt_4e.Draw("LEP")

h_significance_trkiso30_opt_4e.SetMarkerColor(kRed)
h_significance_trkiso30_opt_4e.SetLineColor(kRed)
h_significance_trkiso30_opt_4e.Draw("LEPSAME")

h_significance_trkiso40_opt_4e.SetMarkerColor(kBlue)
h_significance_trkiso40_opt_4e.SetLineColor(kBlue)
h_significance_trkiso40_opt_4e.Draw("LEPSAME")

leg_significance_iso20_opt_4e = TLegend(0.7, 0.7, 0.9,0.9)

leg_significance_iso20_opt_4e.AddEntry(h_significance_trkiso20_opt_4e,"TrkIso20" ,'lep')
leg_significance_iso20_opt_4e.AddEntry(h_significance_trkiso30_opt_4e,"TrkIso30"  ,'lep')
leg_significance_iso20_opt_4e.AddEntry(h_significance_trkiso40_opt_4e,"TrkIso40"  ,'lep')

FormatLegend(leg_significance_iso20_opt_4e)
leg_significance_iso20_opt_4e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_significance_trkiso_opt_4e.Write()

#--------------------------------------

c_significance_caloiso_opt_4e = TCanvas('c_significance_caloiso_opt_4e','',w,h)

#h_significance_caloiso20_opt_4e.GetXaxis().SetRangeUser(0,0.5)
h_significance_caloiso20_opt_4e.GetYaxis().SetRangeUser(1.35,1.6)
h_significance_caloiso20_opt_4e.SetTitle('')
h_significance_caloiso20_opt_4e.GetXaxis().SetTitle('TrkIso Cut')
h_significance_caloiso20_opt_4e.GetYaxis().SetTitle('Z_{0}')
h_significance_caloiso20_opt_4e.Draw("LEP")

h_significance_caloiso30_opt_4e.SetMarkerColor(kRed)
h_significance_caloiso30_opt_4e.SetLineColor(kRed)
h_significance_caloiso30_opt_4e.Draw("LEPSAME")

h_significance_caloiso40_opt_4e.SetMarkerColor(kBlue)
h_significance_caloiso40_opt_4e.SetLineColor(kBlue)
h_significance_caloiso40_opt_4e.Draw("LEPSAME")

leg_significance_iso20_opt_4e = TLegend(0.7, 0.7, 0.9,0.9)

leg_significance_iso20_opt_4e.AddEntry(h_significance_caloiso20_opt_4e,"CaloIso20" ,'lep')
leg_significance_iso20_opt_4e.AddEntry(h_significance_caloiso30_opt_4e,"CaloIso30"  ,'lep')
leg_significance_iso20_opt_4e.AddEntry(h_significance_caloiso40_opt_4e,"CaloIso40"  ,'lep')

FormatLegend(leg_significance_iso20_opt_4e)
leg_significance_iso20_opt_4e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_significance_caloiso_opt_4e.Write()

#--------------------------------------

c_significance_trkiso_opt_2mu2e = TCanvas('c_significance_trkiso_opt_2mu2e','',w,h)

#h_significance_trkiso20_opt_2mu2e.GetXaxis().SetRangeUser(0,0.5)
h_significance_trkiso20_opt_2mu2e.GetYaxis().SetRangeUser(1.4,1.8)
h_significance_trkiso20_opt_2mu2e.SetTitle('')
h_significance_trkiso20_opt_2mu2e.GetXaxis().SetTitle('TrkIso Cut')
h_significance_trkiso20_opt_2mu2e.GetYaxis().SetTitle('Z_{0}')
h_significance_trkiso20_opt_2mu2e.Draw("LEP")

h_significance_trkiso30_opt_2mu2e.SetMarkerColor(kRed)
h_significance_trkiso30_opt_2mu2e.SetLineColor(kRed)
h_significance_trkiso30_opt_2mu2e.Draw("LEPSAME")

h_significance_trkiso40_opt_2mu2e.SetMarkerColor(kBlue)
h_significance_trkiso40_opt_2mu2e.SetLineColor(kBlue)
h_significance_trkiso40_opt_2mu2e.Draw("LEPSAME")

leg_significance_iso20_opt_2mu2e = TLegend(0.7, 0.7, 0.9,0.9)

leg_significance_iso20_opt_2mu2e.AddEntry(h_significance_trkiso20_opt_2mu2e,"TrkIso20" ,'lep')
leg_significance_iso20_opt_2mu2e.AddEntry(h_significance_trkiso30_opt_2mu2e,"TrkIso30"  ,'lep')
leg_significance_iso20_opt_2mu2e.AddEntry(h_significance_trkiso40_opt_2mu2e,"TrkIso40"  ,'lep')

FormatLegend(leg_significance_iso20_opt_2mu2e)
leg_significance_iso20_opt_2mu2e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_significance_trkiso_opt_2mu2e.Write()

#--------------------------------------

c_significance_caloiso_opt_2mu2e = TCanvas('c_significance_caloiso_opt_2mu2e','',w,h)

#h_significance_caloiso20_opt_2mu2e.GetXaxis().SetRangeUser(0,0.5)
h_significance_caloiso20_opt_2mu2e.GetYaxis().SetRangeUser(1.4,1.8)
h_significance_caloiso20_opt_2mu2e.SetTitle('')
h_significance_caloiso20_opt_2mu2e.GetXaxis().SetTitle('TrkIso Cut')
h_significance_caloiso20_opt_2mu2e.GetYaxis().SetTitle('Z_{0}')
h_significance_caloiso20_opt_2mu2e.Draw("LEP")

h_significance_caloiso30_opt_2mu2e.SetMarkerColor(kRed)
h_significance_caloiso30_opt_2mu2e.SetLineColor(kRed)
h_significance_caloiso30_opt_2mu2e.Draw("LEPSAME")

h_significance_caloiso40_opt_2mu2e.SetMarkerColor(kBlue)
h_significance_caloiso40_opt_2mu2e.SetLineColor(kBlue)
h_significance_caloiso40_opt_2mu2e.Draw("LEPSAME")

leg_significance_iso20_opt_2mu2e = TLegend(0.7, 0.7, 0.9,0.9)

leg_significance_iso20_opt_2mu2e.AddEntry(h_significance_caloiso20_opt_2mu2e,"CaloIso20" ,'lep')
leg_significance_iso20_opt_2mu2e.AddEntry(h_significance_caloiso30_opt_2mu2e,"CaloIso30"  ,'lep')
leg_significance_iso20_opt_2mu2e.AddEntry(h_significance_caloiso40_opt_2mu2e,"CaloIso40"  ,'lep')

FormatLegend(leg_significance_iso20_opt_2mu2e)
leg_significance_iso20_opt_2mu2e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_significance_caloiso_opt_2mu2e.Write()

#--------------------------------------

c_Zjets_yield_trkiso_opt_4e = TCanvas('c_Zjets_yield_trkiso_opt_4e','',w,h)

h_Zjets_yield_trkiso20_opt_4e.GetXaxis().SetRangeUser(0,0.5)
h_Zjets_yield_trkiso20_opt_4e.GetYaxis().SetRangeUser(0,2)
h_Zjets_yield_trkiso20_opt_4e.SetTitle('')
h_Zjets_yield_trkiso20_opt_4e.GetXaxis().SetTitle('TrkIso Cut')
h_Zjets_yield_trkiso20_opt_4e.GetYaxis().SetTitle('Z+Jets Yield')
h_Zjets_yield_trkiso20_opt_4e.Draw("HIST")

h_Zjets_yield_trkiso30_opt_4e.SetMarkerColor(kRed)
h_Zjets_yield_trkiso30_opt_4e.SetLineColor(kRed)
h_Zjets_yield_trkiso30_opt_4e.Draw("HIST SAME")

h_Zjets_yield_trkiso40_opt_4e.SetMarkerColor(kBlue)
h_Zjets_yield_trkiso40_opt_4e.SetLineColor(kBlue)
h_Zjets_yield_trkiso40_opt_4e.Draw("HIST SAME")

leg_Zjets_yield_trkiso_opt_4e = TLegend(0.7, 0.7, 0.9,0.9)

leg_Zjets_yield_trkiso_opt_4e.AddEntry(h_Zjets_yield_trkiso20_opt_4e,"TrkIso20" ,'lep')
leg_Zjets_yield_trkiso_opt_4e.AddEntry(h_Zjets_yield_trkiso30_opt_4e,"TrkIso30"  ,'lep')
leg_Zjets_yield_trkiso_opt_4e.AddEntry(h_Zjets_yield_trkiso40_opt_4e,"TrkIso40"  ,'lep')

FormatLegend(leg_Zjets_yield_trkiso_opt_4e)
leg_Zjets_yield_trkiso_opt_4e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_Zjets_yield_trkiso_opt_4e.Write()

#--------------------------------------

c_Zjets_yield_caloiso_opt_4e = TCanvas('c_Zjets_yield_caloiso_opt_4e','',w,h)

h_Zjets_yield_caloiso20_opt_4e.GetXaxis().SetRangeUser(0,0.5)
h_Zjets_yield_caloiso20_opt_4e.GetYaxis().SetRangeUser(0,2)
h_Zjets_yield_caloiso20_opt_4e.SetTitle('')
h_Zjets_yield_caloiso20_opt_4e.GetXaxis().SetTitle('CaloIso Cut')
h_Zjets_yield_caloiso20_opt_4e.GetYaxis().SetTitle('Z+Jets Yield')
h_Zjets_yield_caloiso20_opt_4e.Draw("HIST")

h_Zjets_yield_caloiso30_opt_4e.SetMarkerColor(kRed)
h_Zjets_yield_caloiso30_opt_4e.SetLineColor(kRed)
h_Zjets_yield_caloiso30_opt_4e.Draw("HIST SAME")

h_Zjets_yield_caloiso40_opt_4e.SetMarkerColor(kBlue)
h_Zjets_yield_caloiso40_opt_4e.SetLineColor(kBlue)
h_Zjets_yield_caloiso40_opt_4e.Draw("HIST SAME")

leg_Zjets_yield_caloiso_opt_4e = TLegend(0.7, 0.7, 0.9,0.9)

leg_Zjets_yield_caloiso_opt_4e.AddEntry(h_Zjets_yield_caloiso20_opt_4e,"CaloIso20" ,'lep')
leg_Zjets_yield_caloiso_opt_4e.AddEntry(h_Zjets_yield_caloiso30_opt_4e,"CaloIso30"  ,'lep')
leg_Zjets_yield_caloiso_opt_4e.AddEntry(h_Zjets_yield_caloiso40_opt_4e,"CaloIso40"  ,'lep')

FormatLegend(leg_Zjets_yield_caloiso_opt_4e)
leg_Zjets_yield_caloiso_opt_4e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_Zjets_yield_caloiso_opt_4e.Write()

#--------------------------------------

c_Zjets_yield_trkiso_opt_2mu2e = TCanvas('c_Zjets_yield_trkiso_opt_2mu2e','',w,h)

h_Zjets_yield_trkiso20_opt_2mu2e.GetXaxis().SetRangeUser(0,0.5)
h_Zjets_yield_trkiso20_opt_2mu2e.GetYaxis().SetRangeUser(0,2)
h_Zjets_yield_trkiso20_opt_2mu2e.SetTitle('')
h_Zjets_yield_trkiso20_opt_2mu2e.GetXaxis().SetTitle('TrkIso Cut')
h_Zjets_yield_trkiso20_opt_2mu2e.GetYaxis().SetTitle('Z+Jets Yield')
h_Zjets_yield_trkiso20_opt_2mu2e.Draw("HIST")

h_Zjets_yield_trkiso30_opt_2mu2e.SetMarkerColor(kRed)
h_Zjets_yield_trkiso30_opt_2mu2e.SetLineColor(kRed)
h_Zjets_yield_trkiso30_opt_2mu2e.Draw("HIST SAME")

h_Zjets_yield_trkiso40_opt_2mu2e.SetMarkerColor(kBlue)
h_Zjets_yield_trkiso40_opt_2mu2e.SetLineColor(kBlue)
h_Zjets_yield_trkiso40_opt_2mu2e.Draw("HIST SAME")

leg_Zjets_yield_trkiso_opt_2mu2e = TLegend(0.7, 0.7, 0.9,0.9)

leg_Zjets_yield_trkiso_opt_2mu2e.AddEntry(h_Zjets_yield_trkiso20_opt_2mu2e,"TrkIso20" ,'lep')
leg_Zjets_yield_trkiso_opt_2mu2e.AddEntry(h_Zjets_yield_trkiso30_opt_2mu2e,"TrkIso30"  ,'lep')
leg_Zjets_yield_trkiso_opt_2mu2e.AddEntry(h_Zjets_yield_trkiso40_opt_2mu2e,"TrkIso40"  ,'lep')

FormatLegend(leg_Zjets_yield_trkiso_opt_2mu2e)
leg_Zjets_yield_trkiso_opt_2mu2e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_Zjets_yield_trkiso_opt_2mu2e.Write()

#--------------------------------------

c_Zjets_yield_caloiso_opt_2mu2e = TCanvas('c_Zjets_yield_caloiso_opt_2mu2e','',w,h)

h_Zjets_yield_caloiso20_opt_2mu2e.GetXaxis().SetRangeUser(0,0.5)
h_Zjets_yield_caloiso20_opt_2mu2e.GetYaxis().SetRangeUser(0,2)
h_Zjets_yield_caloiso20_opt_2mu2e.SetTitle('')
h_Zjets_yield_caloiso20_opt_2mu2e.GetXaxis().SetTitle('CaloIso Cut')
h_Zjets_yield_caloiso20_opt_2mu2e.GetYaxis().SetTitle('Z+Jets Yield')
h_Zjets_yield_caloiso20_opt_2mu2e.Draw("HIST")

h_Zjets_yield_caloiso30_opt_2mu2e.SetMarkerColor(kRed)
h_Zjets_yield_caloiso30_opt_2mu2e.SetLineColor(kRed)
h_Zjets_yield_caloiso30_opt_2mu2e.Draw("HIST SAME")

h_Zjets_yield_caloiso40_opt_2mu2e.SetMarkerColor(kBlue)
h_Zjets_yield_caloiso40_opt_2mu2e.SetLineColor(kBlue)
h_Zjets_yield_caloiso40_opt_2mu2e.Draw("HIST SAME")

leg_Zjets_yield_caloiso_opt_2mu2e = TLegend(0.7, 0.7, 0.9,0.9)

leg_Zjets_yield_caloiso_opt_2mu2e.AddEntry(h_Zjets_yield_caloiso20_opt_2mu2e,"CaloIso20" ,'lep')
leg_Zjets_yield_caloiso_opt_2mu2e.AddEntry(h_Zjets_yield_caloiso30_opt_2mu2e,"CaloIso30"  ,'lep')
leg_Zjets_yield_caloiso_opt_2mu2e.AddEntry(h_Zjets_yield_caloiso40_opt_2mu2e,"CaloIso40"  ,'lep')

FormatLegend(leg_Zjets_yield_caloiso_opt_2mu2e)
leg_Zjets_yield_caloiso_opt_2mu2e.Draw()

if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
if (add_label): ADD_LABEL(label_text)

c_Zjets_yield_caloiso_opt_2mu2e.Write()

#--------------------------------------

for hist in hists: hist.Write()

print 'Closing output file: ' + fout.GetPath().rstrip(':/')
fout.Close()




