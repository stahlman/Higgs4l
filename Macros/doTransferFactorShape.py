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


output_tag = 'test'

#legend labels---------------------------


#ouput file tags ---------------------------

#label options ---------------------------

add_atlas_label = True
atlas_label_text = 'Internal'

add_lumi_label = False
lumi_label_text = "20.7 fb^{-1} #sqrt{s} = 8 TeV" 

add_label = True
label_text = output_tag 

#------------------------------------------------------

gStyle.SetOptStat(0)

w = 800
h = 600

input_data = '/disk/userdata00/atlas_data2/stahlman/data/ControlRegion2013/BkgSFInfo_CR5_OS_DATA_20130723_WithCat.root'
input_mc   = '/disk/userdata00/atlas_data2/stahlman/data/ControlRegion2013/BkgSFInfo_CR5_OS_DATAMC_20130723_WithCat.root'

output_dir = '/disk/userdata00/atlas_data2/stahlman/data/ControlRegion2013/'

#------------------------------------------------------

hists = []

#Retrieve Data histograms ------------------------------------------------------------------------------------------------------------
print 'Retrieving trees from files'

file_data = TFile(input_data)
file_mc   = TFile(input_mc)

tree_data = file_data.Get("treeCR")
tree_mc   = file_mc.Get("treeCR")

#---------------------------------


#Define derived histograms ------------------------------------------------------------------------------------------------------------
print 'Defining histograms'

h_pt4l_cr        = TH1F("h_pt4l_cr", ";p_{T} bin", 4, -0.5, 3.5); hists.append(h_pt4l_cr)

h_pt4l_data      = TH1F("h_pt4l_data", ";p_{T} bin", 4, -0.5, 3.5); hists.append(h_pt4l_data)
h_pt4l_data_err  = TH1F("h_pt4l_data_err"  , ";p_{T} bin", 4, -0.5, 3.5); hists.append(h_pt4l_data_err)

h_pt4l_zz      = TH1F("h_pt4l_zz"  , ";p_{T} bin", 4, -0.5, 3.5); hists.append(h_pt4l_zz)
h_pt4l_zz_err  = TH1F("h_pt4l_zz_err"  , ";p_{T} bin", 4, -0.5, 3.5); hists.append(h_pt4l_zz_err)

h_pt4l_yield   = TH1F("h_pt4l_yield"  , ";p_{T} bin; yield", 4, -0.5, 3.5); hists.append(h_pt4l_yield)
h_pt4l_shape   = TH1F("h_pt4l_shape"  , ";p_{T} bin; normalized", 4, -0.5, 3.5); hists.append(h_pt4l_shape)
h_pt4l_error   = TH1F("h_pt4l_error"  , ";p_{T} bin", 4, -0.5, 3.5); hists.append(h_pt4l_error)
h_pt4l_unc     = TH1F("h_pt4l_unc"    , ";p_{T} bin", 4, -0.5, 3.5); hists.append(h_pt4l_unc)

for hist in hists: hist.Sumw2()

#Fill histograms ------------------------------------------------------------------------------------------------------------

ptbin = "((pt4l<20000)*0+(pt4l>=20000&&pt4l<50000)*1+(pt4l>=50000&&pt4l<100000)*2+(pt4l>=100000)*3)";  

mass_window_cut = "(M4l>115000&&M4l<130000)"

zz_cut = "((RunNumber >= 116601 && RunNumber <= 116603) || (RunNumber >= 126937 && RunNumber <= 126942) || (RunNumber >= 167162 && RunNumber <= 167167) || RunNumber == 161988)"

tree_data.Draw( ptbin + " >> h_pt4l_cr", mass_window_cut)

tree_data.Draw( ptbin + " >> h_pt4l_data", "TotalWeight*"+mass_window_cut)
tree_data.Draw( ptbin + " >> h_pt4l_data_err", "(TotalWeight*TransferFactorError/TransferFactor)^2*"+mass_window_cut)
for i in range(h_pt4l_data_err.GetNbinsX()): h_pt4l_data_err.SetBinContent(i+1, sqrt(h_pt4l_data_err[i+1]))

tree_mc.Draw( ptbin + " >> h_pt4l_zz", "TotalWeight*"+mass_window_cut+"*"+zz_cut)
tree_mc.Draw( ptbin + " >> h_pt4l_zz_err", "(TotalWeight*TransferFactorError/TransferFactor)^2*"+mass_window_cut+"*"+zz_cut)
for i in range(h_pt4l_zz_err.GetNbinsX()): h_pt4l_zz_err.SetBinContent(i+1, sqrt(h_pt4l_zz_err[i+1]))

h_pt4l_yield.Add(h_pt4l_data,h_pt4l_zz, 1.0, -1.0)
h_pt4l_shape.Add(h_pt4l_data,h_pt4l_zz, 1.0, -1.0)
h_pt4l_shape.Scale(1/h_pt4l_shape.Integral())
for i in range(h_pt4l_error.GetNbinsX()): 
  err =   h_pt4l_data_err[i+1]*h_pt4l_data_err[i+1]
  err +=  h_pt4l_zz_err[i+1]*h_pt4l_zz_err[i+1]
  h_pt4l_error.SetBinContent(i+1, sqrt(err))
  h_pt4l_yield.SetBinError(i+1, sqrt(err))
h_pt4l_unc.Divide(h_pt4l_error, h_pt4l_yield)

#Begin drawing ------------------------------------------------------------------------------------------------------------
print 'Drawing results'

fout = TFile(output_dir+'TransferFactorShape.'+ output_tag + '.root', 'RECREATE')

fout.cd()

##--------------------------------------

#c_significance_iso20_4e = TCanvas('c_significance_iso20_4e','',w,h)
#
#h_significance_iso20_4e.GetXaxis().SetRangeUser(0,0.5)
#h_significance_iso20_4e.GetYaxis().SetRangeUser(0,0.5)
#h_significance_iso20_4e.SetTitle('')
##h_significance_iso20_4e.GetXaxis().SetTitle('Cut')
#h_significance_iso20_4e.GetZaxis().SetRangeUser(max_sig_4e*0.95,max_sig_4e)
#h_significance_iso20_4e.GetZaxis().SetTitle('Z_{0}')
#Plot2DMap(h_significance_iso20_4e)
#
#if (add_atlas_label): ATLAS_LABEL(atlas_label_text)
#if (add_lumi_label): INTEGRATED_LUMI(lumi_label_text)
#if (add_label): ADD_LABEL(label_text + ' 4e')
#
#c_significance_iso20_4e.Write()

##--------------------------------------


#--------------------------------------

for hist in hists: hist.Write()

print 'Closing output file: '
print fout.GetPath().rstrip(':/')
fout.Close()




