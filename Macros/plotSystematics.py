"""
Plot Systematics
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'November 2013'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

import math
from numpy import *
from ROOT import *
from PlotUtils import *
from AnalysisRoutines import *
from variables import *
from systematics import *
import glob


def main():

   ROOT.gROOT.LoadMacro("AtlasStyle.C");
   ROOT.gROOT.LoadMacro("AtlasUtils.C");
   SetAtlasStyle()

   tag='test'
   
   sample = 'H125'
   
   inputDir =  "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v03/";

   outputDir = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Plots/";

   plotSystematic(inputDir, outputDir, sample, tag)
  
   return

def plotSystematic(inputDir, outputDir, sample, tag):

  atlas_label_text = 'Internal'
  label = "#sqrt{s} = 8 TeV #int L dt = 20.3 fb^{-1}"
  hzz_label = 'H#rightarrow ZZ^{(*)}#rightarrow4l'
  
  w = 800
  h = 600

  fout = TFile( outputDir + "/SystematicPlots."+sample+'.'+'inclusive.'+tag+'.root', "RECREATE")
      
  for var in range(len(variables)):
    
    var_name = variables[var]
    x_label  = var_labels_reco[var] + (' ['+var_units[var]+']' if var_units[var] != '' else '') 
   
    syst_cats = []; syst_names = []

    syst_cats.append('lepton_efficiency');  syst_names.append( lep_eff_syst )
    syst_cats.append('lepton_scale_resolution');	    syst_names.append( lep_resscl_syst )
    if (var_jet[var]): syst_cats.append('jet_scale_resolution_jvf');  syst_names.append( jt_syst )

    fin  = TFile( inputDir  + "/Systematics."+var_name+'.'+sample+'.'+'inclusive.root', "READ")
  
    for syst_plot in range(len(syst_cats)):
    
      t_syst_names = syst_names[syst_plot]
      fout.cd()

      #------------------------------
      syst_hists = []	
      for syst_name in t_syst_names:      
	hist = fin.Get('h_'+var_name+'_'+syst_name[0]+'_syst')
	hist.GetXaxis().SetTitle(x_label)
	syst_hists.append( hist )	 
      cat_hists = SumHists(syst_hists, t_syst_names)
	
      MaxMin(cat_hists)      
      
      canvas = TCanvas('systematics_'+syst_cats[syst_plot]+'_'+sample+'_'+var_name,'',w,h)      
      legend = NewLegend(len(cat_hists)/2, 'tr')
      format = 0
      for i in range(len(cat_hists)):   
	if (cat_hists[i].GetName().endswith('Up')):
	  legend.AddEntry(cat_hists[i], cat_hists[i].GetTitle(), "L")
	  cat_hists[i].SetTitle('')
	  cat_hists[i+1].SetTitle('')
	  Plot(cat_hists[i],  True, format, i!=0)
	  Plot(cat_hists[i+1],True, format, True)
	  
	elif (cat_hists[i].GetName().endswith('Dn')): continue
	else:
	  legend.AddEntry(cat_hists[i], cat_hists[i].GetTitle(), "L")
	  cat_hists[i].SetTitle('')
	  Plot(cat_hists[i], True, format, i!=0)
        format+=1
	
      ATLAS_Label(atlas_label_text)
      ADD_LABEL(hzz_label)
      ADD_LABEL(label, 0.76)
      FormatLegend(legend)
      legend.Draw()
      canvas.Write()
  
  print 'Closing output file: '
  print fout.GetPath().rstrip(':/')
  fout.Close()
  
  return
 
def SumHists(hists, syst_names):
  
  n_hists = len(hists)
    
  if n_hists == 0: return 0
  
  seen_cats = []
  hist_cats = []
  for i in range(n_hists):
    
    #find histogram
    cat  = syst_names[i][1]
    if cat not in seen_cats:
      hist = hists[i].Clone('h_'+cat + '_Up');
      hist.Reset()
      hist.SetTitle(syst_names[i][2]);
      hist_cats.append(hist)
      hist = hists[i].Clone('h_'+cat + '_Dn');
      hist.Reset()
      hist.SetTitle(syst_names[i][2]);
      hist_cats.append(hist)
      seen_cats.append(cat)    
    hist_up = gDirectory.Get('h_'+cat + '_Up')
    hist_dn = gDirectory.Get('h_'+cat + '_Dn')
                
    name = syst_names[i][0]
    single_var = not(name.endswith('Up') or name.endswith('Dn'))#determine single var
    for j in range(hist_up.GetNbinsX()):     
      if (single_var or hists[i][j+1]>0): hist_up[j+1] = +sqrt(pow(hist_up[j+1],2) + pow(hists[i][j+1],2)) 
      if (single_var or hists[i][j+1]<0): hist_dn[j+1] = -sqrt(pow(hist_dn[j+1],2) + pow(hists[i][j+1],2)) 

  return hist_cats  
    
 
 
if __name__ == '__main__' :
    main()

