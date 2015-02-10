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

zjets_filenames = []
zjets_filenames.append( input_dir + "minitrees/v02/MC12a/AlpgenJimmy_Auto_AUET2CTEQ6L1_*.root")
zjets_filenames.append( input_dir + "minitrees/v02/MC12a/AlpgenJimmy_AUET2CTEQ6L1_*.root")
zjets_filenames.append( input_dir + "minitrees/v02/MC11c/AlpgenJimmy*.root")
zjets_filenames.append( input_dir + "minitrees/v02/MC11c/AlpgenHWf*.root")

ttbar_filenames = []
ttbar_filenames.append( input_dir + "minitrees/v02/MC12a/McAtNloJimmy_CT10_ttbar*.root")
ttbar_filenames.append( input_dir + "minitrees/v02/MC11c/T1_McAtNlo_Jimmy*.root")

zz_filenames = []
zz_filenames.append( input_dir + "minitrees/v02/MC12a/gg2ZZJimmy_AUET2CT10_ZZ*.root")
zz_filenames.append( input_dir + "minitrees/v02/MC12a/PowhegPythia8_AU2CT10_ZZ_*.root")
zz_filenames.append( input_dir + "minitrees/v02/MC11c/gg2ZZ_JIMMY_ZZ*.root")
zz_filenames.append( input_dir + "minitrees/v02/MC11c/PowHegZZ*.root")


#------------------------------------------------------


hists = []

#------------------------------------------------------
#Retrieve files ------------------------------------------------------------------------------------------------------------
#------------------------------------------------------
print 'Retrieving trees from files'

zjets_chain  = InclusiveChain(zjets_filenames)
ttbar_chain  = InclusiveChain(ttbar_filenames)
zz_chain     = InclusiveChain(zz_filenames)

#------------------------------------------------------
#define histograms
#------------------------------------------------------

fout = TFile(output_dir + 'ReduciblePtStudy.test.root', "RECREATE")
fout.cd()


bins = array('d',[0,20,50,100,1000])

h_zjets_fine_pt4l = TH1F("h_zjets_fine_pt4l", ";p_{T}^{4l} [GeV];events",500, 0, 500); hists.append(h_zjets_fine_pt4l)
h_ttbar_fine_pt4l = TH1F("h_ttbar_fine_pt4l", ";p_{T}^{4l} [GeV];events",500, 0, 500); hists.append(h_ttbar_fine_pt4l)
h_zz_fine_pt4l    = TH1F("h_zz_fine_pt4l", ";p_{T}^{4l} [GeV];events",500, 0, 500); hists.append(h_zz_fine_pt4l)

h_zjets_pt4l = TH1F("h_zjets_bin_pt4l", ";p_{T} bin;events",len(bins)-1, -0.5, len(bins)-1-0.5); hists.append(h_zjets_bin_pt4l)
h_ttbar_pt4l = TH1F("h_ttbar_bin_pt4l", ";p_{T} bin;events",len(bins)-1, -0.5, len(bins)-1-0.5); hists.append(h_ttbar_bin_pt4l)
h_zz_pt4l    = TH1F("h_zz_bin_pt4l", ";p_{T} bin;events",len(bins)-1, -0.5, len(bins)-1-0.5); hists.append(h_zz_bin_pt4l)

h_zz_SBHi_bin_pt4l    = TH1F("h_zz_SBHi_bin_pt4l", ";p_{T} bin;events",len(bins)-1, -0.5, len(bins)-1-0.5); hists.append(h_zz_SBHi_bin_pt4l)
h_zz_SBLo_bin_pt4l    = TH1F("h_zz_SBLo_bin_pt4l", ";p_{T} bin;events",len(bins)-1, -0.5, len(bins)-1-0.5); hists.append(h_zz_SBLo_bin_pt4l)


for hist in hists: hist.Sumw2()

bin_str = '('
for i in range(len(bins)-1):
  if (i!=0): bin_str += " + "
  bin_str += "("+str(bins[i])+"<higgspt&&higgspt<"+str(bins[i+1])+")*"+str(i)
bin_str+= ')'


print 'Filling histograms'

Sig_cut = "(m4l_constrained>115)*(m4l_constrained<130)"

zjets_chain.Draw("higgspt >> h_zjets_fine_pt4l", "weight*"+Sig_cut, "goff")
zjets_chain.Draw(bin_str+">> h_zjets_bin_pt4l", "weight*"+Sig_cut, "goff")

ttbar_chain.Draw("higgspt >> h_ttbar_fine_pt4l", "weight*"+Sig_cut, "goff")
ttbar_chain.Draw(bin_str+">> h_ttbar_bin_pt4l", "weight*"+Sig_cut, "goff")

zz_chain.Draw("higgspt >> h_zz_fine_pt4l", "weight*"+Sig_cut, "goff")
zz_chain.Draw(bin_str+">> h_zz_bin_pt4l", "weight*"+Sig_cut, "goff")

SBLo_cut = "(m4l_constrained>100)*(m4l_constrained<115)"

zz_chain.Draw(bin_str+">> h_zz_SBLo_bin_pt4l", "weight*"+SBLo_cut, "goff")

SBHi_cut = "(m4l_constrained>130)*(m4l_constrained<150)"

zz_chain.Draw(bin_str+">> h_zz_SBHi_bin_pt4l", "weight*"+SBHi_cut, "goff")


#------------------------------------------------------
#derived histograms
#------------------------------------------------------



for hist in hists: hist.Write()

print 'Closing output file: ' + fout.GetPath().rstrip(':/')
fout.Close()




