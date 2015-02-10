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
from AnalysisRoutines import *
from array import array

ROOT.gROOT.LoadMacro("AtlasStyle.C") 
ROOT.gROOT.LoadMacro("AtlasUtils.C") 
SetAtlasStyle()


#input options ---------------------------

SF_signal = "1.66"
SF_background = "1.505"  #scale ZZ yield to include reducible background yield !!!APPROXIMATION!!!

#ouput file tags ---------------------------

#label options ---------------------------

add_atlas_label = True
atlas_label_text = 'Internal'

add_lumi_label = False
lumi_label_text = "20.7 fb^{-1} #sqrt{s} = 8 TeV" 

add_label = True
#label_text = output_tag 

#------------------------------------------------------

gStyle.SetOptStat(0)

w = 800
h = 600

input_dir  = "/local_data1/stahlman/output/HSG2_output/Moriond/"
output_dir = '/local_data1/stahlman/output/HSG2_output/Moriond/Plots/'

signal_filenames = []
signal_filenames.append( input_dir + "minitrees/v02/MC12a/Signal/*H125_ZZ4lep.root")
signal_filenames.append( input_dir + "minitrees/v02/MC11c/Signal/*H125_ZZ4lep.root")

background_filenames = []
background_filenames.append( input_dir + "minitrees/v02/MC12a/*ZZ*.root")
background_filenames.append( input_dir + "minitrees/v02/MC11c/PowhegZZ*.root")

data_filenames = []
data_filenames.append( input_dir + "minitrees/v02/data12.root")
data_filenames.append( input_dir + "minitrees/v02/data11.root")


#------------------------------------------------------


hists = []

#------------------------------------------------------
#Retrieve files ------------------------------------------------------------------------------------------------------------
#------------------------------------------------------
print 'Retrieving trees from files'

signal_chain     = InclusiveChain(signal_filenames)
background_chain = InclusiveChain(background_filenames)
data_chain       = InclusiveChain(data_filenames)

#------------------------------------------------------
#define histograms
#------------------------------------------------------

fout = TFile(output_dir + 'PtStudy.test.root', "RECREATE")
fout.cd()


bins = array('d',[0,20,50,100,1000])
h_sig_fine_pt4l = TH1F("h_sig_fine_pt4l", ";p_{T}^{4l} [GeV];events",500, 0, 500); hists.append(h_sig_fine_pt4l)
h_bkg_fine_pt4l = TH1F("h_bkg_fine_pt4l", ";p_{T}^{4l} [GeV];events",500, 0, 500); hists.append(h_bkg_fine_pt4l)
h_dat_fine_pt4l = TH1F("h_dat_fine_pt4l", ";p_{T}^{4l} [GeV];events",500, 0, 500); hists.append(h_dat_fine_pt4l)
h_sig_pt4l = TH1F("h_sig_pt4l", ";p_{T}^{4l} [GeV];events",len(bins)-1,bins); hists.append(h_sig_pt4l)
h_bkg_pt4l = TH1F("h_bkg_pt4l", ";p_{T}^{4l} [GeV];events",len(bins)-1,bins); hists.append(h_bkg_pt4l)
h_dat_pt4l = TH1F("h_dat_pt4l", ";p_{T}^{4l} [GeV];events",len(bins)-1,bins); hists.append(h_dat_pt4l)
h_sig_bin_pt4l = TH1F("h_sig_bin_pt4l", ";p_{T} bin;events",len(bins)-1, -0.5, len(bins)-1-0.5); hists.append(h_sig_bin_pt4l)


bin_str = '('
for i in range(len(bins)-1):
  if (i!=0): bin_str += " + "
  bin_str += "("+str(bins[i])+"<higgspt&&higgspt<"+str(bins[i+1])+")*"+str(i)
bin_str+= ')'


print 'Filling histograms'

cut = "(m4l_unconstrained>120)*(m4l_unconstrained<130)"

signal_chain.Draw("higgspt >> h_sig_pt4l", SF_signal+"*weight*"+cut, "goff")
signal_chain.Draw("higgspt >> h_sig_fine_pt4l", SF_signal+"*weight*"+cut, "goff")
signal_chain.Draw(bin_str+" >> h_sig_bin_pt4l", SF_signal+"*weight*"+cut, "goff")
background_chain.Draw("higgspt >> h_bkg_pt4l", SF_background+"*weight*"+cut, "goff")
background_chain.Draw("higgspt >> h_bkg_fine_pt4l", SF_background+"*weight*"+cut, "goff")
data_chain.Draw("higgspt >> h_dat_pt4l", cut, "goff")
data_chain.Draw("higgspt >> h_dat_fine_pt4l", cut, "goff")

hc_sig_fine_pt4l = CumulativeDistribution(h_sig_fine_pt4l); hists.append(hc_sig_fine_pt4l)
hc_bkg_fine_pt4l = CumulativeDistribution(h_bkg_fine_pt4l); hists.append(hc_bkg_fine_pt4l)

#------------------------------------------------------
#derived histograms
#------------------------------------------------------

h_soverb_pt4l = TH1F("h_soverb_pt4l", ";p_{T}^{4l} [GeV];S/B",len(bins)-1,bins); hists.append(h_soverb_pt4l) 
h_soversplusb_pt4l = TH1F("h_soversplusb_pt4l", ";p_{T}^{4l} [GeV];#frac{S}{#sqrt{S+B}}",len(bins)-1,bins); hists.append(h_soversplusb_pt4l)
h_soverrootb_pt4l = TH1F("h_soverrootb_pt4l", ";p_{T}^{4l} [GeV];#frac{S}{#sqrt{B}}",len(bins)-1,bins); hists.append(h_soverrootb_pt4l)
h_z0_pt4l = TH1F("h_z0_pt4l", ";p_{T}^{4l} [GeV];Z_{0}",len(bins)-1,bins); hists.append(h_z0_pt4l)

h_soverb_pt4l.Divide(h_sig_pt4l,h_bkg_pt4l)

for i in range(1,len(bins)):
  significance = h_sig_pt4l.GetBinContent(i)/sqrt(h_sig_pt4l.GetBinContent(i)+h_bkg_pt4l.GetBinContent(i))
  h_soversplusb_pt4l.SetBinContent(i,significance)

  significance = h_sig_pt4l.GetBinContent(i)/sqrt(h_bkg_pt4l.GetBinContent(i))
  h_soverrootb_pt4l.SetBinContent(i,significance)  

  significance = Significance(h_sig_pt4l.GetBinContent(i), h_bkg_pt4l.GetBinContent(i))
  h_z0_pt4l.SetBinContent(i,significance)


for hist in hists: hist.Write()

print 'Closing output file: ' + fout.GetPath().rstrip(':/')
fout.Close()




