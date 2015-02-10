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
from PlotUtils import *
from AnalysisRoutines import *
import glob
import re

ROOT.gROOT.LoadMacro("AtlasStyle.C");
ROOT.gROOT.LoadMacro("AtlasUtils.C");
SetAtlasStyle()

tag='test'

#inputDir =  "/disk/userdata00/atlas_data2/stahlman/output/Moriond/minitrees/v02/";
inputDir =  "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/v02/";

outputDir = "/disk/userdata00/atlas_data2/stahlman/output/Moriond/Plots/";

#fid_corrections_file_name = "/disk/userdata00/atlas_data2/stahlman/output/08072013/Plots/FiducialStudy.test.root"
fid_corrections_file_name = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Fiducial/v02/FiducialStudy.H125.root"

ZZ_bkg_syst_file  = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v01/IrreducibleBackgroundSystematics.txt"
red_bkg_syst_file = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v01/ReducibleBackgroundSystematics.txt"
signal_syst_file  = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v01/SignalSystematics.txt"

#variable = "((higgspt <20)*0+(higgspt>=20&&higgspt<50)*1+(higgspt>=50&&higgspt<100)*2+(higgspt>=100)*3)";  
variable = 'pt4l_unconstrained'
var_name = 'pt'
var_label_reco = 'p_{T,4l}'
var_label_truth = 'p_{T,H}'
var_unit = "GeV"
var_bins = [0.0, 20.0, 50.0, 100.0, 250.0]


usePseudoData = true
preset = [12,8,2,1]

mass_window_lo = 115
#mass_window_lo = 120
mass_window_hi = 130

#Configurable inputs
#------------------------------

ggH_xsection  =  19.27 *1000 #fb
VBFH_xsection =  1.578 *1000 #fb
WH_xsection   = 0.7046 *1000 #fb
ZH_xsection   = 0.4153 *1000 #fb
ttH_xsection  = 0.1293 *1000 #fb

total_xsection = ggH_xsection + VBFH_xsection + WH_xsection + ZH_xsection + ttH_xsection

#branching_ratio = 0.000125 #BR for H->4l; l=e,mu
branching_ratio = 0.000276 #BR for H->4l; l=e,mu, tau

lumi = 20.7  #fb-1
lumi_syst = 3.6 #% systematic on luminosity

bins = array('d', var_bins)
n_bins = len(bins)-1 

#TODO FINAL NUMBERS
reducible_bkg_total_yield_mu = 5.13  #total red bkg yield with muons (Moriond) 
reducible_bkg_total_yield_el = 6.93  #total red bkg yield with electrons (Moriond) 
reducible_bkg_total_yield_el = 0.66*reducible_bkg_total_yield_el #scale Moriond to Fall2013 estimate

tree_name = "inclusive"

signal_SF = 1.

hzz_label = 'H#rightarrow ZZ^{(*)}#rightarrow4l'
atlas_label_text = 'Internal'
label = "\\sqrt{s} = 8 TeV #int L dt = 20.7 fb^{-1}"


#Find input ------------------------------------------------------------------------------------------------------------

ZZ_file_names = []
ZZ_file_names.extend(glob.glob(inputDir + '/MC12a/*ZZ*.root'))

print "Using ZZ files:"
for f in ZZ_file_names:
   print '\t',f

red_file_names = []
red_file_names.extend(glob.glob(inputDir + '/MC12a/*Zbb*.root'))

print "Using Zbb files:"
for f in red_file_names:
   print '\t',f

signal_file_names = []
signal_file_names.extend(glob.glob(inputDir + '/MC12a/Signal/*H125_ZZ4lep.root'))

print "Using signal files:"
for f in signal_file_names:
   print '\t',f

data_file_names = []
data_file_names.extend(glob.glob(inputDir + '/data12.root'))

print "Using data files:"
for f in data_file_names:
   print '\t',f

print "Using fiducial corrections file:"
print '\t',fid_corrections_file_name
fid_correction_file = TFile( fid_corrections_file_name, "READ")


print "Using ZZ background systematics file:"
print '\t', ZZ_bkg_syst_file
ZZ_bkg_syst_names = loadtxt(ZZ_bkg_syst_file, usecols=[0], dtype=string)
ZZ_bkg_syst_vals  = loadtxt(ZZ_bkg_syst_file, usecols=range(1,n_bins+1))

print "Using red background systematics file:"
print '\t',red_bkg_syst_file
red_bkg_syst_names = loadtxt(red_bkg_syst_file, usecols=[0], dtype=string)
red_bkg_syst_vals  = loadtxt(red_bkg_syst_file, usecols=range(1,n_bins+1))

print "Using signal systematics file:"
print '\t',signal_syst_file
signal_syst_names = loadtxt(signal_syst_file, usecols=[0], dtype=string)
signal_syst_vals  = loadtxt(signal_syst_file, usecols=range(1,n_bins+1))

#Retrieve trees ------------------------------------------------------------------------------------------------------------
print 'Retrieving trees from files'

ZZ_chain     = GetChain(tree_name, ZZ_file_names)
red_chain    = GetChain(tree_name, red_file_names)
signal_chain = GetChain(tree_name, signal_file_names)
data_chain   = GetChain(tree_name, data_file_names)


#Open Output File ------------------------------------------------------------------------------------------------------------

fout = TFile(outputDir + "DifferentialMeasurement."+var_name+'.'+tag+".root", "RECREATE")
fout.cd()

#Create Histograms
#------------------------------

hists = []
for hist in hists: hist.Sumw2()

#aignal
h_signal_yield      = TH1F("h_signal_yield",";"+var_label_reco+";events",n_bins, bins);hists.append(h_signal_yield)
h_signal_yield_syst = TH1F("h_signal_yield_syst",";"+var_label_reco+";systematic",n_bins, bins);hists.append(h_signal_yield_syst)

h_signal_total_xsection      = TH1F("h_signal_total_xsection",";"+var_label_truth+";d#sigma_{tot}/d "+var_label_truth+" [fb"+("/"+var_unit if var_unit != "" else "")+"]",n_bins, bins);hists.append(h_signal_total_xsection)
h_signal_total_xsection_syst = TH1F("h_signal_total_xsection_syst",";"+var_label_truth+";systematic",n_bins, bins);hists.append(h_signal_total_xsection_syst)

h_signal_fiducial_xsection      = TH1F("h_signal_fiducial_xsection",";"+var_label_truth+";d#sigma_{fid}/d "+var_label_truth+" [fb"+("/"+var_unit if var_unit != "" else "")+"]",n_bins, bins);hists.append(h_signal_fiducial_xsection)
h_signal_fiducial_xsection_syst = TH1F("h_signal_fiducial_xsection_syst",";"+var_label_truth+";systematic",n_bins, bins);hists.append(h_signal_fiducial_xsection_syst)

#backgrounds
h_ZZ_yield       = TH1F("h_ZZ_yield", ";"+var_label_reco+";events",n_bins, bins);hists.append(h_ZZ_yield)
h_ZZ_yield_syst  = TH1F("h_ZZ_yield_syst", ";"+var_label_reco+";systematic",n_bins, bins);hists.append(h_ZZ_yield_syst)

h_red_yield      = TH1F("h_red_yield",";"+var_label_reco+";events",n_bins, bins);hists.append(h_red_yield)
h_red_yield_syst = TH1F("h_red_yield_syst",";"+var_label_reco+";systematic",n_bins, bins);hists.append(h_red_yield_syst)

h_mass_red_yield = TH1F("h_mass_red_yield",";m_{4l};systematic",400, 0, 400);hists.append(h_mass_red_yield)

#data
h_data_yield = TH1F("h_data_yield",";"+var_label_reco+";events",n_bins, bins);hists.append(h_data_yield)

#derived hists
h_background_yield      = TH1F("h_background_yield",";"+var_label_reco+";events",n_bins, bins);hists.append(h_background_yield)
h_background_yield_syst = TH1F("h_background_yield_syst",";"+var_label_reco+";systematic",n_bins, bins);hists.append(h_background_yield_syst)

h_observed_yield        = TH1F("h_observed_yield",";"+var_label_reco+";Data-Background",n_bins, bins);hists.append(h_observed_yield)
h_observed_yield_syst   = TH1F("h_observed_yield_syst",";"+var_label_reco+";systematic",n_bins, bins);hists.append(h_observed_yield_syst)
h_observed_yield_perr   = TGraphAsymmErrors(n_bins); hists.append(h_observed_yield_perr)

h_observed_xsection      = TH1F("h_observed_xsection",";"+var_label_truth+";d#sigma_{fid}/d "+var_label_truth+" [fb"+("/"+var_unit if var_unit != "" else "")+"]",n_bins, bins);hists.append(h_observed_xsection)
h_observed_xsection_syst = TH1F("h_observed_xsection_syst",";"+var_label_truth+";systematic",n_bins, bins);hists.append(h_observed_xsection_syst)
h_observed_xsection_perr = TGraphAsymmErrors(n_bins); hists.append(h_observed_xsection_perr)

#fiducial corrections
h_fid_efficiency_ggH      = fid_correction_file.Get("ggH125/h_"+var_name+"_fiducial_efficiency"); hists.append(h_fid_efficiency_ggH )
h_fid_efficiency_VBFH     = fid_correction_file.Get("VBFH125/h_"+var_name+"_fiducial_efficiency");hists.append(h_fid_efficiency_VBFH)
h_fid_efficiency_WH       = fid_correction_file.Get("WH125/h_"+var_name+"_fiducial_efficiency");  hists.append(h_fid_efficiency_WH  )
h_fid_efficiency_ZH       = fid_correction_file.Get("ZH125/h_"+var_name+"_fiducial_efficiency");  hists.append(h_fid_efficiency_ZH  )
h_fid_efficiency_ttH      = fid_correction_file.Get("ttH125/h_"+var_name+"_fiducial_efficiency"); hists.append(h_fid_efficiency_ttH )

h_fid_efficiency          = TH1F("h_fid_efficiency",";"+var_label_reco+";Fiducial Efficiency",n_bins, bins);hists.append(h_fid_efficiency)
h_fid_efficiency_syst     = TH1F("h_fid_efficiency_syst",";"+var_label_reco+";systematic",n_bins, bins);hists.append(h_fid_efficiency_syst)

h_fid_acceptance_ggH      = fid_correction_file.Get("ggH125/h_"+var_name+"_fiducial_acceptance"); hists.append(h_fid_acceptance_ggH )
h_fid_acceptance_VBFH     = fid_correction_file.Get("VBFH125/h_"+var_name+"_fiducial_acceptance");hists.append(h_fid_acceptance_VBFH)
h_fid_acceptance_WH       = fid_correction_file.Get("WH125/h_"+var_name+"_fiducial_acceptance");  hists.append(h_fid_acceptance_WH  )
h_fid_acceptance_ZH       = fid_correction_file.Get("ZH125/h_"+var_name+"_fiducial_acceptance");  hists.append(h_fid_acceptance_ZH  )
h_fid_acceptance_ttH      = fid_correction_file.Get("ttH125/h_"+var_name+"_fiducial_acceptance"); hists.append(h_fid_acceptance_ttH )

h_fid_acceptance          = TH1F("h_fid_acceptance",";"+var_label_reco+";Fiducial Acceptance",n_bins, bins);hists.append(h_fid_acceptance)
h_fid_acceptance_syst     = TH1F("h_fid_acceptance_syst",";"+var_label_reco+";systematic",n_bins, bins);hists.append(h_fid_acceptance_syst)

h_correction_factor      = TH1F("h_correction_factor",";"+var_label_reco+";Correction Factor",n_bins, bins);hists.append(h_correction_factor)
h_correction_factor_syst = TH1F("h_correction_factor_syst",";"+var_label_reco+";systematic",n_bins, bins);hists.append(h_correction_factor_syst)

#Fill Histograms
#------------------------------

mass_window = "((m4l_constrained < " + str(mass_window_hi) + ")&&(m4l_constrained > " + str(mass_window_lo)+"))"

ZZ_chain.Draw(variable+" >> h_ZZ_yield", "weight*"+mass_window, "goff");

red_chain.Draw(variable+" >> h_red_yield", "weight*"+mass_window, "goff");
red_chain.Draw('m4l_constrained >> h_mass_red_yield', "weight", "goff")

reducible_bkg_mass_window_fraction = h_mass_red_yield.Integral(mass_window_lo,mass_window_hi)/h_mass_red_yield.Integral()
print "Reducible mass window fraction:",reducible_bkg_mass_window_fraction

reducible_bkg_yield = (reducible_bkg_total_yield_el+reducible_bkg_total_yield_mu)*reducible_bkg_mass_window_fraction

red_integral = h_red_yield.Integral()
if(red_integral != 0 and reducible_bkg_yield != 0): h_red_yield.Scale(reducible_bkg_yield/red_integral)

signal_chain.Draw(variable+" >> h_signal_yield", "weight*"+mass_window+"*"+str(signal_SF), "goff");

if (usePseudoData):
  signal_chain.Draw(variable+" >> h_data_yield", "weight*"+mass_window+"*"+str(signal_SF), "goff");
  for i in range(h_data_yield.GetNbinsX()):
     h_data_yield[i+1] = random.poisson(h_ZZ_yield[i+1]+h_red_yield[i+1]+h_signal_yield[i+1])    
     #h_data_yield[i+1] = preset[i]    
else:
  data_chain.Draw( variable+" >> h_data_yield", "weight*"+mass_window, "goff");

h_data_yield_perr = PoissonGraph(h_data_yield); hists.append(h_data_yield_perr)


ggH  = fid_correction_file.Get("ggH125/h_"+var_name+"_gen")
VBFH = fid_correction_file.Get("VBFH125/h_"+var_name+"_gen")
WH   = fid_correction_file.Get("WH125/h_"+var_name+"_gen")
ZH   = fid_correction_file.Get("ZH125/h_"+var_name+"_gen")
ttH  = fid_correction_file.Get("ttH125/h_"+var_name+"_gen")

#fiducial efficiency
h_fid_efficiency.Add(h_fid_efficiency_ggH,  ggH_xsection/total_xsection)
h_fid_efficiency.Add(h_fid_efficiency_VBFH, VBFH_xsection/total_xsection)
h_fid_efficiency.Add(h_fid_efficiency_WH,   WH_xsection/total_xsection)
h_fid_efficiency.Add(h_fid_efficiency_ZH,   ZH_xsection/total_xsection)
h_fid_efficiency.Add(h_fid_efficiency_ttH,  ttH_xsection/total_xsection)

#fiducial acceptance
h_fid_acceptance.Add(h_fid_acceptance_ggH,  ggH_xsection/total_xsection)
h_fid_acceptance.Add(h_fid_acceptance_VBFH, VBFH_xsection/total_xsection)
h_fid_acceptance.Add(h_fid_acceptance_WH,   WH_xsection/total_xsection)
h_fid_acceptance.Add(h_fid_acceptance_ZH,   ZH_xsection/total_xsection)
h_fid_acceptance.Add(h_fid_acceptance_ttH,  ttH_xsection/total_xsection)

for i in range(n_bins):
  
  bin_width = 100
  if (i+1 != n_bins):
    bin_width = bins[i+1] - bins[i]
  
  signal_total_xsection =  ggH[i+1]/ggH.Integral()*ggH_xsection
  signal_total_xsection += VBFH[i+1]/VBFH.Integral()*VBFH_xsection
  signal_total_xsection += WH[i+1]/WH.Integral()*WH_xsection
  signal_total_xsection += ZH[i+1]/ZH.Integral()*ZH_xsection
  signal_total_xsection += ttH[i+1]/ttH.Integral()*ttH_xsection

  h_signal_total_xsection[i+1] = signal_total_xsection*branching_ratio / bin_width
  h_signal_total_xsection.SetBinError(i+1, h_signal_total_xsection.GetBinError(i+1) / bin_width)

  signal_fiducial_xsection     = h_signal_total_xsection[i+1]*h_fid_acceptance[i+1]
  signal_fiducial_xsection_err = h_signal_total_xsection.GetBinError(i+1)*h_fid_acceptance[i+1]
  
  h_signal_fiducial_xsection[i+1] = signal_fiducial_xsection
  h_signal_fiducial_xsection.SetBinError(i+1, signal_fiducial_xsection_err)

  


#systematics
#------------------------------
print "Irreducible Background Systematics:"
for i in range(len(ZZ_bkg_syst_names)):
  print "\t",ZZ_bkg_syst_names[i]
  for j in range(n_bins):
    h_ZZ_yield_syst.SetBinContent(j+1,sqrt(h_ZZ_yield_syst[j+1]*h_ZZ_yield_syst[j+1]+ZZ_bkg_syst_vals[i][j]*ZZ_bkg_syst_vals[i][j]))

print "Reducible Background Systematics:"
for i in range(len(red_bkg_syst_names)):
  print "\t",red_bkg_syst_names[i]
  for j in range(n_bins):
    h_red_yield_syst.SetBinContent(j+1,sqrt(h_red_yield_syst[j+1]*h_red_yield_syst[j+1]+red_bkg_syst_vals[i][j]*red_bkg_syst_vals[i][j]))

print "Signal Systematics:"
for i in range(len(signal_syst_names)):
  print "\t",signal_syst_names[i]
  for j in range(n_bins):
    h_signal_yield_syst.SetBinContent(j+1,sqrt(h_signal_yield_syst[j+1]*h_signal_yield_syst[j+1]+signal_syst_vals[i][j]*signal_syst_vals[i][j]))


for i in range(h_fid_efficiency.GetNbinsX()):
  
  #TODO Proper systematics (no theory?)
  h_fid_efficiency_syst[i+1] = h_signal_yield_syst[i+1]
  
  c_factor = 0
  c_factor_syst = 0
  c_factor_err = 0
  if (h_fid_efficiency[i+1] != 0):
    c_factor      = 1/h_fid_efficiency[i+1]
    c_factor_err  = h_fid_efficiency.GetBinError(i+1)/h_fid_efficiency[i+1]/h_fid_efficiency[i+1]
    c_factor_syst = h_fid_efficiency_syst[i+1]
 
  h_correction_factor.SetBinContent(i+1,c_factor)
  h_correction_factor.SetBinError(i+1,c_factor_err)
  h_correction_factor_syst.SetBinContent(i+1,c_factor_syst)



#Background Estimate
#------------------------------

h_background_yield.Add(h_ZZ_yield)
h_background_yield.Add(h_red_yield)
  
for i in range(n_bins):
  zz_syst  = h_ZZ_yield[i+1]*h_ZZ_yield_syst[i+1]/100
  red_syst = h_red_yield[i+1]*h_red_yield_syst[i+1]/100
  h_background_yield_syst.SetBinContent(i+1,sqrt(zz_syst*zz_syst+red_syst*red_syst)/h_background_yield[i+1]*100)
  h_observed_yield_syst.SetBinContent(i+1,sqrt(zz_syst*zz_syst+red_syst*red_syst)/h_background_yield[i+1]*100)
  
  
#Background Subtraction
#------------------------------

h_observed_yield.Add(h_data_yield, h_background_yield,1.0,-1.0)

for i in range(n_bins):
  #assume negligible stat uncertainty on background estimate
  h_observed_yield_perr.SetPoint(i,h_observed_yield.GetBinCenter(i+1), h_observed_yield[i+1]); 
  h_observed_yield_perr.SetPointError(i,h_observed_yield.GetBinWidth(i+1)/2,h_observed_yield.GetBinWidth(i+1)/2,h_data_yield_perr.GetErrorYlow(i),h_data_yield_perr.GetErrorYhigh(i)); 

#derive xsection
#------------------------------

for i in range(n_bins):
    
  bin_width = 100
  if (i+1 != n_bins):
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
    
  observed_xsection_syt =  h_observed_yield_syst[i+1]*h_observed_yield_syst[i+1]
  observed_xsection_syt += h_fid_efficiency_syst[i+1]*h_fid_efficiency_syst[i+1]
  observed_xsection_syt += lumi_syst*lumi_syst
  observed_xsection_syt =  sqrt(observed_xsection_syt)
      
  h_observed_xsection.SetBinContent(i+1,observed_xsection)
  h_observed_xsection.SetBinError(i+1,observed_xsection_unc)
  h_observed_xsection_syst.SetBinContent(i+1,observed_xsection_syt)
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
print "Event Yields ("+str(mass_window_lo)+"-"+str(mass_window_hi)+" GeV)"
print "------------------------"
print "Bin\t|",
for i in range(n_bins): print str(var_bins[i])+"-"+str(var_bins[i+1]),'\t',
print''
print "------------------------"

print "Signal\t|",
for i in range(n_bins): print round(h_signal_yield[i+1],3),"\t",
print ''

print "ZZ\t|",
for i in range(n_bins): print round(h_ZZ_yield[i+1],3), "\t",
print ''

print "Red.\t|", 
for i in range(n_bins): print round(h_red_yield[i+1],3),"\t",
print ''

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

print "Pseudo-Data\t|" if usePseudoData else "Data\t|", 
for i in range(n_bins): print round(h_data_yield[i+1],3),"\t",
print ''

print "------------------------"


print "Fiducial Cross Sections"
print "------------------------"
print "Signal\t|",
for i in range(n_bins): print h_signal_fiducial_xsection[i+1],"\t",
print ''
print "------------------------"

print "Data\t|", 
for i in range(n_bins): print h_observed_xsection[i+1],
print ''

print "Stat(%)\t|", 
for i in range(n_bins): print h_observed_xsection.GetBinError(i+1)/h_observed_xsection[i+1]*100,
print ''

print "Syst(%)\t|", 
for i in range(n_bins): print h_observed_xsection_syst[i+1],
print ''

print "------------------------"

#Make plots
#------------------------------
gStyle.SetOptStat(0)

w = 800
h = 600

#------------------------------

c_dn_dy_bkg = TCanvas('dN_dy_Background','',w,h)
l_dn_dy_bkg = NewLegend(4, 'tr')

#plot MC prediction
h_red_yield.SetFillColor(kViolet+1)
h_ZZ_yield.SetFillColor(kRed+1)
h_signal_yield.SetFillColor(kAzure-9)

stack = THStack()
stack.Add(h_red_yield)
stack.Add(h_ZZ_yield)
stack.Add(h_signal_yield)

stack.SetMaximum(25)
stack.SetMinimum(0.001)
#AddPtBinLabels(h_red_yield)

stack.Draw()

#plot Data
PlotGraph( h_data_yield_perr, false, 0, true)
#PlotDerived(h_data_yield, false, 0, true)  
c_dn_dy_bkg.RedrawAxis()

l_dn_dy_bkg.AddEntry(h_observed_yield, 'Pseudo-Data' if usePseudoData else 'Data','LEP')
l_dn_dy_bkg.AddEntry(h_signal_yield, 'SM (M_{H}=125 GeV)','F')
l_dn_dy_bkg.AddEntry(h_ZZ_yield, 'ZZ','F')
l_dn_dy_bkg.AddEntry(h_red_yield, 'Z+jets, tt#bar','F')

ATLAS_Label(atlas_label_text)
ADD_LABEL(hzz_label)
ADD_LABEL(label, 0.76)
l_dn_dy_bkg.Draw()
c_dn_dy_bkg.Write()

#------------------------------

c_dn_dy = TCanvas('dN_dy','',w,h)
l_dn_dy = NewLegend(3, 'tr')

#plot data systematic
h_observed_yield_err = ErrorHist( h_observed_yield, h_observed_yield_syst ); hists.append(h_observed_yield_err)
h_observed_yield_err.SetMaximum(15)
h_observed_yield_err.SetMinimum(0.001)
#AddPtBinLabels(h_observed_yield_err)
PlotBand(h_observed_yield_err, false, 1, false)

#plot MC prediction
h_signal_yield_err = ErrorHist( h_signal_yield, h_signal_yield_syst )
PlotBox(h_signal_yield_err, 1, 5, true)

#plot Data
PlotGraph( h_observed_yield_perr, false, 0, true)

c_dn_dy.RedrawAxis()

l_dn_dy.AddEntry(h_observed_yield, 'Pseudo-Data' if usePseudoData else 'Data','LEP')
l_dn_dy.AddEntry(h_observed_yield_err, 'syst','F')
l_dn_dy.AddEntry(h_signal_yield_err, 'SM (M_{H}=125 GeV)','F')

ATLAS_Label(atlas_label_text)
ADD_LABEL(hzz_label)
ADD_LABEL(label, 0.76)
l_dn_dy.Draw()
c_dn_dy.Write()

#------------------------------

c_dn_dy_ratio = TCanvas('dN_dy_ratio','',w,800)
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
#AddPtBinLabels(h_observed_yield_err)

PlotBand(h_observed_yield_err, false, 1, false)

#plot MC prediction
#PlotBox(h_signal_yield_err, 1, 5, true)
PlotBox(h_signal_yield_err, 1, 5, true)

#plot Data
PlotGraph( h_observed_yield_perr, false, 0, true)

c_dn_dy_ratio.RedrawAxis()
l_dn_dy_ratio.AddEntry(h_observed_yield, 'Pseudo-Data' if usePseudoData else 'Data','LEP')
l_dn_dy_ratio.AddEntry(h_observed_yield_err, 'syst','F')
l_dn_dy_ratio.AddEntry(h_signal_yield_err, 'SM (M_{H}=125 GeV)','F')
l_dn_dy_ratio.Draw()

ATLAS_Label(atlas_label_text)
ADD_LABEL(hzz_label)
ADD_LABEL(label, 0.76)

#plot ratio
pad0.cd()

h_observed_yield_err_ratio  = RatioHist(h_observed_yield_err, h_signal_yield)
h_observed_yield_perr_ratio = RatioGraph(h_observed_yield_perr, h_signal_yield)
h_signal_yield_ratio = RatioHist(h_signal_yield_err, h_signal_yield)

#AddPtBinLabels(h_observed_yield_err_ratio)
PlotBand(h_observed_yield_err_ratio, false, 1, false)
PlotBox(h_signal_yield_ratio, 1, 5, true)

h_observed_yield_perr_ratio.Draw("P SAME")
  
c_dn_dy_ratio.Write()

#------------------------------

c_dsigma_dy = TCanvas('dsigma_dy','',w,h)
l_dsigma_dy = NewLegend(3, 'tr')

h_observed_xsection_err = ErrorHist( h_observed_xsection, h_observed_xsection_syst );hists.append(h_observed_xsection_err)
h_observed_xsection_err.SetMaximum(0.06)
h_observed_xsection_err.SetMinimum(0.0001)
#AddPtBinLabels(h_observed_xsection_err)
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
#l_dsigma_dy.AddEntry(h_signal_xsection_err, 'SM (M_{H}=125 GeV)','F')
l_dsigma_dy.AddEntry(h_signal_fiducial_xsection, 'SM (M_{H}=125 GeV)','l')

ATLAS_Label(atlas_label_text)
ADD_LABEL(hzz_label)
ADD_LABEL(label, 0.76)
l_dsigma_dy.Draw()
c_dsigma_dy.Write()

#------------------------------

c_correction_factor = TCanvas('Correction_Factor','',w,h)
l_correction_factor = NewLegend(2, 'tr')

h_correction_factor.SetMaximum(2.5)
h_correction_factor.SetMinimum(0.5)
#AddPtBinLabels(h_correction_factor)
PlotDerived(h_correction_factor, false, 0, false) #axes etc.

h_correction_factor_err = ErrorHist( h_correction_factor, h_correction_factor_syst )
hists.append(h_correction_factor_err)
PlotBand(h_correction_factor_err, false, 1, true)
PlotDerived(h_correction_factor, false, 0, true)
c_correction_factor.RedrawAxis()

l_correction_factor.AddEntry(h_correction_factor, 'SM (M_{H}=125 GeV)','lep')
l_correction_factor.AddEntry(h_correction_factor_err, 'syst','F')

ATLAS_Label(atlas_label_text)
ADD_LABEL(hzz_label)
ADD_LABEL("Simulation, \\sqrt{s} = 8 TeV", 0.76)
l_correction_factor.Draw()
c_correction_factor.Write()

#------------------------------

#Close files
#------------------------------
for hist in hists: hist.Write()

print 'Closing output file: '
print fout.GetPath().rstrip(':/')
fout.Close()
