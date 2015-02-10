"""
Make Fiducial cross section numbers
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'March 2013'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

import math
from ROOT import *
from PlotUtils import *
from AnalysisRoutines import *
from variables import *
import glob
import re

non_decimal = re.compile(r'[^\d.]+')

ROOT.gROOT.LoadMacro("AtlasStyle.C");
ROOT.gROOT.LoadMacro("AtlasUtils.C");
SetAtlasStyle()

#tag='test'
tag = 'H120_H130'

#inputDir = "/disk/userdata00/atlas_data2/stahlman/output/16012014/Plots/";
inputDir = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Fiducial/v09/";

outputDir = inputDir;

modes = ['ggH', 'VBFH', 'WH', 'ZH', 'ttH']

#channels = ["4mu", "4e", "2mu2e", "2e2mu", "incl"]
channels = ["4mu", "4e", "2mu2e", "2e2mu"]
latex_channels = ["4#mu", "4e", "2#mu2e", "2e2#mu", "incl"]

label = '#sqrt{s} = 8 TeV'
atlas_label_text = 'Internal'

w = 800
h = 600


def main():

  #Open Input File ------------------------------------------------------------------------------------------------------------
  fin = TFile(inputDir + "FiducialStudy."+tag+".root", "READ")

  samples = []
  for key in gDirectory.GetListOfKeys():
    if key.IsFolder():
      sample_name = key.GetName()
      if not sample_name.startswith('H'):
        samples.append( key.GetName() )

  #Open Output File ------------------------------------------------------------------------------------------------------------
  fout = TFile(outputDir + "FiducialPlots."+tag+".root", "RECREATE")
  fout.cd()

  #First, plot mode vs mass for inclusive
  makeModePlots( 'Fiducial Acceptance','inclusive_nomasswindow', 'fiducial_acceptance', samples, fin )
  makeModePlots( 'Fiducial Efficiency','inclusive_nomasswindow', 'fiducial_efficiency', samples, fin )
  makeModePlots( 'Mispair Fraction',   'inclusive_nomasswindow', 'fiducial_mispair_fraction', samples, fin )
  makeModePlots( 'Reco Mispair Fraction',   'inclusive_nomasswindow', 'reco_mispair_fraction', samples, fin )
  makeModePlots( 'Fiducial Leakage',   'inclusive_nomasswindow', 'fiducial_leakage', samples, fin )

  makeModePlots( 'Fiducial Acceptance','inclusive', 'fiducial_acceptance', samples, fin )
  makeModePlots( 'Fiducial Efficiency','inclusive', 'fiducial_efficiency', samples, fin )
  makeModePlots( 'Mispair Fraction',   'inclusive', 'fiducial_mispair_fraction', samples, fin )
  makeModePlots( 'Reco Mispair Fraction',   'inclusive', 'reco_mispair_fraction', samples, fin )
  makeModePlots( 'Fiducial Leakage',   'inclusive', 'fiducial_leakage', samples, fin )

  #Second, plot channels vs mass for each mode
  for mode in modes:
    #makePlots( 'NGenerated', 'gen', samples, mode, fin )
    makeChannelPlots( 'Fiducial Acceptance','fiducial_acceptance',samples, mode, fin )
    makeChannelPlots( 'Fiducial Efficiency','fiducial_efficiency',samples, mode, fin )
    makeChannelPlots( 'Reco Mispair Fraction',   'fiducial_mispair_fraction',samples, mode, fin )
    makeChannelPlots( 'Fiducial Leakage',   'fiducial_leakage',samples, mode, fin )
  
  #print table of inclusive fiducial efficiencies
  print '--------------------------------------------------'
  for mass in range(124,127):
    print mass,
    for mode in modes + ['H']:
      hist = fin.Get(mode+str(mass)+'/h_inclusive_fiducial_efficiency')
      print '& ', round(hist[1],3), ' $\pm$ ', round(hist.GetBinError(1),3), 
    print ' \\\\'
  print '--------------------------------------------------'
     
  print 'Closing output file: '
  print fout.GetPath().rstrip(':/')
  fout.Close()
  
  return

def makeChannelPlots( hist_name, fid_variable, samples, mode, fin):
  
  hists = []  
  masses = []
  
  for i in range(len(samples)):
    if not samples[i].startswith(mode): continue 
   
    hists.append(fin.Get(samples[i]+"/h_quad_type_"+fid_variable))
    masses.append(int(non_decimal.sub('', samples[i])))
  
  hists_mass = []
  n_hists = len(hists)
  n_channels = len(channels)
  
  for i in range(n_channels):
    t = TGraphErrors(n_hists)
    t.SetName(hist_name+'_'+channels[i])
    t.SetTitle('')
    hists_mass.append( t )

  for i in range(n_hists):
    for j in range(n_channels):
      hists_mass[j].SetPoint(i, masses[i], hists[i].GetBinContent(j+1))
      hists_mass[j].SetPointError(i, 0.5, hists[i].GetBinError(j+1))


  gStyle.SetOptStat(0)
  #------------------------------
  c_name = hist_name+'_'+mode
  canvas = TCanvas(c_name.replace(' ','_'),'',w,h)
  legend = NewLegend(len(hists_mass), 'br')

  for i in range(len(hists_mass)):
    hists_mass[i].GetXaxis().SetTitle('M_{H} [GeV]')
    hists_mass[i].GetYaxis().SetTitle(hist_name)
    hists_mass[i].SetMaximum(1.2)
    hists_mass[i].SetMinimum(0)
    PlotGraph(hists_mass[i], 1, i, i!=0)
    legend.AddEntry(hists_mass[i], latex_channels[i],'lep')

  ATLAS_LABEL(atlas_label_text)
  ADD_LABEL('H#rightarrow ZZ^{(*)} #rightarrow l^{+}l^{-}l^{+}l^{-}')
  #ADD_LABEL(label+ ', 118 < m_{4l} < 129 GeV ', 0.77)
  ADD_LABEL(label+ ', ' + mode, 0.77)
  #ADD_LABEL(mode, 0.72)
  legend.Draw()
  canvas.Write()

def makeModePlots( hist_name, channel_variable, fid_variable, samples, fin):

  hists  = [ [] for mode in modes ]  
  masses = [ [] for mode in modes ]
  
  for i in range(len(samples)):   
    mode = samples[i][:-3]
    mode_index = modes.index(mode)

    hists[mode_index].append(fin.Get(samples[i]+"/h_"+channel_variable+"_"+fid_variable))
    masses[mode_index].append(int(non_decimal.sub('', samples[i])))

  hists_mass = []
  n_hists = len(hists)
  
  for i in range(len(modes)):
    t = TGraphErrors(len(hists[i]))
    t.SetName(hist_name+'_'+modes[i])
    t.SetTitle('')
    hists_mass.append( t )

  for i in range(len(modes)):
    for j in range(len(hists[i])):
      hists_mass[i].SetPoint(j, masses[i][j], hists[i][j].GetBinContent(1))
      hists_mass[i].SetPointError(j, 0.5, hists[i][j].GetBinError(1))


  gStyle.SetOptStat(0)
  #------------------------------
  c_name = hist_name+('_Mass_Window' if channel_variable=='inclusive' else '')
  canvas = TCanvas(c_name.replace(' ', '_'),'',w,h)
  legend = NewLegend(len(channels), 'tr')

  for i in range(len(hists_mass)):
    hists_mass[i].GetXaxis().SetTitle('M_{H} [GeV]')
    hists_mass[i].GetYaxis().SetTitle(hist_name)
    hists_mass[i].SetMaximum(1.2)
    hists_mass[i].SetMinimum(0)
    PlotGraph(hists_mass[i], 1, i, i!=0)
    legend.AddEntry(hists_mass[i], modes[i],'lep')

  ATLAS_LABEL(atlas_label_text)
  ADD_LABEL('H#rightarrow ZZ^{(*)} #rightarrow l^{+}l^{-}l^{+}l^{-}')
  ADD_LABEL(label + ('' if channel_variable!='inclusive' else ', 118 < m_{4l} < 129 GeV'), 0.77)
  legend.Draw()
  canvas.Write()

  return
  
  
if __name__ == '__main__' :
    main()



