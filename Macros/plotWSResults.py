"""
Plot Systematics
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'April 2014'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

from math import *
from numpy import *
from ROOT import *
from PlotUtils import *
from AnalysisRoutines import *
from variables import *
from systematics import *
import glob
from array import *

atlas_label_text = 'Internal'
label = "#sqrt{s} = 8 TeV: #int L dt = 20.3 fb^{-1}"
hzz_label = 'H #rightarrow ZZ* #rightarrow 4#font[12]{l}'

w = 800
h = 600

fiducial_file_name = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Fiducial/v10/FiducialStudy.H120_H130.root"

name_mode   = ["ggH", "VBFH", "WH", "ZH", "ttH" ] 
label_mode  = ["#it{gg}F", "VBF", "#it{WH}", "#it{ZH}", "#it{t#bar{t}H}" ] 
latex_mode  = ['ggF', 'VBF', '$WH$', '$ZH$', '$t\\bar{t}H$' ]

def main():

   ROOT.gROOT.LoadMacro("AtlasStyle.C");
   ROOT.gROOT.LoadMacro("AtlasUtils.C");
   SetAtlasStyle()

   tag='test'
   
   sample = 'H125'
   
   inputDir =  "/home/stahlman/testarea/HZZllllDifferential/makeWS/";

   #outputDir = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Plots/";
   #outputDir = "/disk/userdata00/atlas_data2/stahlman/output/test/";
   outputDir =  "/home/stahlman/testarea/HZZllllDifferential/makeWS/results/obsData";

   makeTables(inputDir, outputDir, tag)
   
   for var in range(len(variables)):
   #for var in range(1,2):
      makePlots(inputDir, outputDir, var, tag)
   

   return

def makePlots(inputDir, outputDir, var_i, tag):
  
  variable = variables[var_i]
  bins = var_bins[var_i]
  n_bins = len(bins) - 1

  print "Processing var", variable

  x_label_reco   = var_labels_reco[var_i]   + (' ['+var_units[var_i]+']' if var_units[var_i] != "" else "")
  x_label_truth  = var_labels_truth[var_i]  + (' ['+var_units[var_i]+']' if var_units[var_i] != "" else "")
  
  y_label_truth  = "d#sigma_{fid} / d"+var_labels_simple[var_i]  +' '+ ('[fb/'+var_units[var_i]+']' if var_units[var_i] != "" else " [fb]")

  label_sr  = "118 < #it{m}_{4#font[12]{l}} < 129 GeV"

  minlo_label  = '#scale[0.8]{#it{gg}#rightarrow#it{H} (#scale[0.9]{MiNLO HJ+PS}) + #it{#bf{X}H}}'
  powheg_label = '#scale[0.8]{#it{gg}#rightarrow#it{H} (#scale[0.9]{P}#scale[0.7]{OWHEG}+#scale[0.9]{PS}) + #it{#bf{X}H}}'
  hres_label   = '#scale[0.8]{#it{gg}#rightarrow#it{H} (#scale[0.9]{HR}#scale[0.7]{ES}) + #it{#bf{X}H}}'
  nonggH_label = '#scale[0.8]{#it{#bf{X}H}  =  VBF + #it{VH} + #it{t#bar{t}H}}'


  #make dummy histogram for jet variables 
  h_t = TH1F('dummy','',4,-0.5,3.5)
  h_t.GetXaxis().SetBinLabel(1,'0');
  h_t.GetXaxis().SetBinLabel(2,'1');
  h_t.GetXaxis().SetBinLabel(3,'2');
  h_t.GetXaxis().SetBinLabel(4,'#geq 3');
  h_t.GetXaxis().SetLabelSize(0.07);
  h_t.GetXaxis().SetNdivisions(503,false)
  h_t.GetXaxis().SetTitle(x_label_truth)
  h_t.GetYaxis().SetTitle('#sigma_{fid} [fb]')  
  h_t.SetStats(false)


  fin = TFile( inputDir + '/results/obsData/modified_nll_scans_'+variable+'.root')
  finputs =TFile( inputDir + '/data/WorkspaceInputs.'+variable+'.root')
  fout = TFile( outputDir + "/nll_scan_plots."+variable+'.root', "RECREATE")  
    
  #------------------------------

  c_mu = TCanvas('SignalStrength_'+variable,'',w,h)
  l_mu = NewLegend(1, 'tr')
  
  g_mu = fin.Get(variable+'_mu')
  g_mu.GetXaxis().SetTitle(x_label_reco)
  g_mu.GetXaxis().SetLimits(bins[0],bins[n_bins])
  g_mu.GetYaxis().SetTitle('#mu')
  g_mu.GetHistogram().SetMaximum(4)
  g_mu.SetMarkerStyle(20)

  PlotGraph(g_mu, False, 1, False) #axes etc.
  
  one = TF1("one","1",0,1000)
  one.SetLineColor(ROOT.kRed)
  one.SetLineStyle(7)
  one.Draw("SAME")

  PlotGraph(g_mu, False, 1, True) 
  
  l_mu.AddEntry(g_mu,  'Observed', 'l')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  FormatLegend(l_mu)
  l_mu.Draw()
  c_mu.Write()

  #------------------------------  
  c_nevents = TCanvas('NEvents_'+variable,'',w,h)
  l_nevents = NewLegend(1, 'tr')
  
  g = fin.Get(variable+'_NE')
  g.GetXaxis().SetLimits(bins[0],bins[n_bins])
  g.GetXaxis().SetTitle(x_label_reco)
  g.GetYaxis().SetTitle('N_{signal}')
  g.GetHistogram().SetMaximum(18)
  g.SetMarkerStyle(20)
 
  PlotGraph(g, False, 1, False) #axes etc.

  l_nevents.AddEntry(g,  'Observed', 'l')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  FormatLegend(l_nevents)
  l_nevents.Draw()
  c_nevents.Write()

  #------------------------------  
  c_xs = TCanvas('CrossSection_'+variable,'',w,h)
  
  g = fin.Get(variable+'_XS')
  g.GetXaxis().SetLimits(bins[0],bins[n_bins])
  g.GetXaxis().SetTitle(x_label_truth)
  g.GetYaxis().SetTitle(y_label_truth)  
  g.GetHistogram().SetMinimum(0.0001)
  g.GetHistogram().SetMaximum(2*(TMath.MaxElement(n_bins,g.GetY())))
  g.SetMarkerStyle(20)
  
  if (variable=='njets'):
    h_t.SetMaximum(2*(TMath.MaxElement(n_bins,g.GetY())))
    h_t.Draw()
    
  PlotGraph(g, False, 1, (variable=='njets'))

  g_syst = fin.Get(variable+'_XS_Syst')
  PlotBand(g_syst, False, 1, true)
    
  hist_noggH = finputs.Get('hists/h_'+variable+'_dsigmadxnoggH_nominal')
  hist_noggH.SetLineStyle(7)
  hist_noggH.SetLineWidth(3)
  hist_noggH.SetLineColor(kGreen+2)
  hist_noggH.Draw("HIST SAME")

  hist_nom = finputs.Get('hists/h_'+variable+'_dsigmadxHJ_nominal')
  hist_up  = finputs.Get('hists/h_'+variable+'_dsigmadxHJ_syst_up')
  hist_dn  = finputs.Get('hists/h_'+variable+'_dsigmadxHJ_syst_dn')  
  minlo_graph = AsymmErrorHist(hist_nom,hist_up,hist_dn)
  PlotBox(minlo_graph,1,6,True)  

  #draw again to plot over MC
  PlotGraph(g, False, 1, True)
  c_xs.RedrawAxis()  

  l_xs = TLegend(0.55,0.84,0.9,0.9)
  FormatLeg(l_xs)
  l_xs.SetTextSize(0.045)
  l_xs.SetTextFont(42)
  l_xs.SetNColumns(2)
  l_xs.AddEntry(g,  'data', 'ple')
  l_xs.AddEntry(g_syst,  'syst. unc.', 'f')
  l_xs.Draw() 

  l_xs2 = TLegend(0.55,0.72,0.9,0.84)
  FormatLeg(l_xs2)
  l_xs2.SetTextSize(0.045)
  l_xs2.SetTextFont(42)
  l_xs2.AddEntry(minlo_graph, minlo_label,'f')
  l_xs2.AddEntry(hist_noggH, nonggH_label, 'L')
  l_xs2.Draw()
  
  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  if (variable=='njets'): ADD_LABEL('#it{p}_{T}^{jet} > 30 GeV', 0.70)
   
  c_xs.Write('CrossSection_'+variable+'_MinloOnly')
  #------------------------------  
      
  hist_nom = finputs.Get('hists/h_'+variable+'_dsigmadxPowheg_nominal')
  hist_up  = finputs.Get('hists/h_'+variable+'_dsigmadxPowheg_syst_up')
  hist_dn  = finputs.Get('hists/h_'+variable+'_dsigmadxPowheg_syst_dn')  
  powheg_graph = AsymmErrorHist(hist_nom,hist_up,hist_dn)
  PlotBox(powheg_graph,1,8,True)  
  
  hres = false
  hist_nom = finputs.Get('hists/h_'+variable+'_dsigmadxHRes_nominal')
  if hist_nom:     
     hres = true
     hist_up  = finputs.Get('hists/h_'+variable+'_dsigmadxHRes_syst_up')
     hist_dn  = finputs.Get('hists/h_'+variable+'_dsigmadxHRes_syst_dn')  

     hres_graph = AsymmErrorHist(hist_nom,hist_up,hist_dn)
     PlotBox(hres_graph,1,7,True)  

  #draw again to plot over MC
  PlotGraph(g, False, 1, True)
  
  c_xs.RedrawAxis()  
   
  l_xs.Draw()

  l_xs2.Clear()
  l_xs2.SetY1(0.66)
  l_xs2.AddEntry(minlo_graph, minlo_label,'f')
  l_xs2.AddEntry(powheg_graph, powheg_label,'f')
  if hres:
     l_xs2.AddEntry(hres_graph, hres_label,'f')
     l_xs2.SetY1(0.60)
  l_xs2.AddEntry(hist_noggH, nonggH_label, 'L')
  l_xs2.Draw() 

  c_xs.Write()
  #------------------------------  

  #reformat plot for log scale
  g.GetXaxis().SetLimits(bins[0],bins[n_bins])  
  g.GetHistogram().SetMaximum(100*TMath.MaxElement(n_bins,g.GetY()))   
  g.GetHistogram().SetMinimum(0.01*TMath.MinElement(n_bins,g.GetY()))
  if (variable=='njets'):
    h_t.SetMaximum(100*TMath.MaxElement(n_bins,g.GetY()))
    h_t.SetMinimum(0.01*TMath.MinElement(n_bins,g.GetY()))    
    
  c_xs.SetLogy(1)
  c_xs.Write('CrossSection_'+variable+'_logscale')
  
    
  #------------------------------  
  #now add ratio plot
  c_xs_ratio = TCanvas('CrossSection_'+variable+'_ratio','',800,800)  
  
  pad0 = TPad("pad", '', 0., 0., 1.,0.30);
  pad0.SetTopMargin(0.03);
  pad0.SetBottomMargin(0.4);
  pad0.SetFillColor(0);
  pad0.Draw();

  pad1 = TPad("pad1", '', 0., 0.3, 1.,1.);
  pad1.SetBottomMargin(0);
  pad1.Draw();
  pad1.cd()

  if (variable=='njets'):
    h_t.SetMinimum(0.0001)
    h_t.SetMaximum(2*(TMath.MaxElement(n_bins,g.GetY())))
    h_t.Draw()
    PlotBand(g_syst, False, 1, True)
  else:
    g_syst.GetHistogram().SetMinimum(0.0001)
    g_syst.GetHistogram().SetMaximum(2*(TMath.MaxElement(n_bins,g.GetY()))) 
    PlotBand(g_syst, False, 1, False)
  
  if minlo_graph:  PlotBox(minlo_graph, 1,6,True)  
  if powheg_graph: PlotBox(powheg_graph,1,8,True)  
  if hres:         PlotBox(hres_graph,  1,7,True)  

  PlotGraph(g, False, 1, True)

  l_xs.Draw()
  l_xs2.Draw()
  
  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)

  pad0.cd()
  
  if (variable=='njets'):
    h_t.SetMinimum(0.0)
    h_t.SetMaximum(4.0)
    h_t.Draw()
    PlotBand(g_syst, False, 1, True)
  else:
    g_mu.GetHistogram().SetMinimum(0.0)
    g_mu.GetHistogram().SetMaximum(4.0) 
    PlotGraph(g_mu, False, 1, False) 

  #PlotGraph(g_mu, False, 1, True) 

  c_xs_ratio.Write()

  #------------------------------  

  c_correction_factor = TCanvas('Correction_Factor_'+variable,'',w,h)
  
  h_correction_factor 		= finputs.Get('hists/h_'+variable+'_correction_factor_nominal')
  h_correction_factor_syst_up 	= finputs.Get('hists/h_'+variable+'_correction_factor_syst_up')
  h_correction_factor_syst_dn 	= finputs.Get('hists/h_'+variable+'_correction_factor_syst_dn')
    
  AtlasStyle(h_correction_factor)
  h_correction_factor.SetMaximum(2.5)
  h_correction_factor.SetMinimum(1.1001)
  h_correction_factor.GetXaxis().SetTitle(x_label_reco)
  h_correction_factor.GetYaxis().SetTitle('Correction Factor')

  if (variable=='njets'):
    h_t.GetXaxis().SetTitle(x_label_reco)
    h_t.GetYaxis().SetTitle('Correction factors')
    h_t.SetMaximum(2.5)
    h_t.SetMinimum(1.1001)
    h_t.Draw()

  PlotDerived(h_correction_factor, false, 0, (variable=='njets')) #axes etc.

  h_correction_factor_err = AsymmErrorHist( h_correction_factor, h_correction_factor_syst_up, h_correction_factor_syst_dn )
  PlotBand(h_correction_factor_err, false, 1, true)
  PlotDerived(h_correction_factor, false, 0, true)
  c_correction_factor.RedrawAxis()

  l_correction_factor = TLegend(0.55,0.78,0.9,0.9)
  FormatLeg(l_correction_factor)
  l_correction_factor.SetTextSize(0.045)
  l_correction_factor.SetTextFont(42)
  l_correction_factor.AddEntry(h_correction_factor, powheg_label,'lep')
  l_correction_factor.AddEntry(h_correction_factor_err, '#scale[0.8]{Systematic uncertainty}','F')
  l_correction_factor.Draw()
    
  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL("Simulation, #sqrt{s} = 8 TeV", 0.76)
  ADD_LABEL("#it{m}_{H} = 125.4 GeV", 0.70)
  c_correction_factor.Write()

  #------------------------------  

  c_fiducial_efficiency = TCanvas('Fiducial_Efficiency_'+variable,'',w,h)
  
  h_fiducial_efficiency 		= h_correction_factor.Clone('h_'+variable+'_fiducial_efficiency_nominal')
  h_fiducial_efficiency_syst_dn 	= h_correction_factor_syst_up.Clone('h_'+variable+'_fiducial_efficiency_syst_up')
  h_fiducial_efficiency_syst_up 	= h_correction_factor_syst_dn.Clone('h_'+variable+'_fiducial_efficiency_syst_dn')
  
  for i in range(h_fiducial_efficiency.GetNbinsX()): 
    
    h_fiducial_efficiency[i+1] = 1. / h_correction_factor[i+1]
    h_fiducial_efficiency.SetBinError(i+1, h_correction_factor.GetBinError(i+1) / pow(h_correction_factor[i+1],2) )
    
  AtlasStyle(h_fiducial_efficiency)
  h_fiducial_efficiency.SetMaximum(1.0)
  h_fiducial_efficiency.SetMinimum(0.001)
  h_fiducial_efficiency.GetXaxis().SetTitle(x_label_reco)
  h_fiducial_efficiency.GetYaxis().SetTitle('Correction factors')

  if (variable=='njets'):
    h_t.GetXaxis().SetTitle(x_label_reco)
    h_t.GetYaxis().SetTitle('Correction factors')
    h_t.SetMaximum(1.0)
    h_t.SetMinimum(0.001)
    h_t.Draw()

  PlotDerived(h_fiducial_efficiency, false, 0, (variable=='njets')) #axes etc.

  h_fiducial_efficiency_err = AsymmErrorHist( h_fiducial_efficiency, h_fiducial_efficiency_syst_up, h_fiducial_efficiency_syst_dn )
  PlotBand(h_fiducial_efficiency_err, false, 1, true)
  PlotDerived(h_fiducial_efficiency, false, 0, true)
  c_fiducial_efficiency.RedrawAxis()

  l_fiducial_efficiency = TLegend(0.55,0.78,0.9,0.9)
  FormatLeg(l_fiducial_efficiency)
  l_fiducial_efficiency.SetTextSize(0.045)
  l_fiducial_efficiency.SetTextFont(42)
  l_fiducial_efficiency.AddEntry(h_fiducial_efficiency, powheg_label,'lep')
  l_fiducial_efficiency.AddEntry(h_fiducial_efficiency_err, '#scale[0.8]{Systematic uncertainty}','F')
  l_fiducial_efficiency.Draw()
    
  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL("Simulation, #sqrt{s} = 8 TeV", 0.76)
  ADD_LABEL("#it{m}_{H} = 125.4 GeV", 0.70)
  
  c_fiducial_efficiency.Write()
  
  #------------------------------  

  #Load correction factors from file
  fid_correction_file = TFile( fiducial_file_name, "READ")
      
  h_cf_mode  = []
  for i,mode in enumerate(name_mode):    
    
    h_125 = fid_correction_file.Get( mode + "125/h_"+variable+"_correction_factor")
    h_126 = fid_correction_file.Get( mode + "126/h_"+variable+"_correction_factor")
    h_nom = h_125.Clone('h_nom')
    h_nom.Reset()
    h_nom.Add(h_125,0.6)
    h_nom.Add(h_126,0.4)
    
    h_cf_mode.append( h_nom )

  h_fid_eff_mode  = []
  for i,mode in enumerate(name_mode):    
    h_fid_eff_mode.append(h_cf_mode[i].Clone('h_'+variable+'_fiducial_efficiency'))
    for j in range(h_fid_eff_mode[i].GetNbinsX()): 
      h_fid_eff_mode[i][j+1] = 1. / h_cf_mode[i][j+1]
      h_fid_eff_mode[i].SetBinError(j+1, h_cf_mode[i].GetBinError(j+1) / pow( h_cf_mode[i][j+1],2) )    
    
  fout.cd()
  
  #------------------------------  

  c_cf_mode = TCanvas('CorrectionFactorModes_'+variable,'',w,h)
  
  #MaxMin(h_cf_mode)
  
  if (variable=='njets'):
    h_t.GetXaxis().SetTitle(x_label_reco)
    h_t.GetYaxis().SetTitle('Correction factors')
    h_t.SetMinimum(1.0001)
    h_t.SetMaximum(1.8*h_cf_mode[4].GetMaximum())
    h_t.Draw()

  for i,hist in enumerate(h_cf_mode):    
    hist.GetXaxis().SetTitle(x_label_reco)
    hist.GetYaxis().SetTitle('Correction factors')
    hist.SetMinimum(1.0001)
    hist.SetMaximum(1.8*h_cf_mode[4].GetMaximum())
    PlotDerived(hist, False, i, i!=0 or (variable=='njets') ) #axes etc.  

  l_cf_mode = TLegend(0.76,0.67,0.99,0.90)
  FormatLeg(l_cf_mode)
  for i,hist in enumerate(h_cf_mode):    
    l_cf_mode.AddEntry(hist, label_mode[i],'lep')
  l_cf_mode.SetTextFont(42)
  l_cf_mode.SetTextSize(0.04)
  l_cf_mode.Draw()
  
  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL("Simulation, #sqrt{s} = 8 TeV", 0.76)
  ADD_LABEL("#it{m}_{H} = 125.4 GeV", 0.70)

  c_cf_mode.Write()

  #------------------------------

  c_fid_eff_mode = TCanvas('Fiducial_Efficiency_Modes_'+variable,'',w,h)
  
  rng_up = 1.8*max([hist.GetMaximum() for hist in h_fid_eff_mode])
    
  if (variable=='njets'):
    h_t.GetXaxis().SetTitle(x_label_reco)
    h_t.GetYaxis().SetTitle('Correction factors')
    h_t.SetMinimum(0.0001)
    h_t.SetMaximum(rng_up)
    h_t.Draw()

  for i,hist in enumerate(h_fid_eff_mode):    
    hist.GetXaxis().SetTitle(x_label_reco)
    hist.GetYaxis().SetTitle('Correction factors')
    hist.SetMinimum(0.0001)
    hist.SetMaximum(rng_up)
    PlotDerived(hist, False, i, i!=0 or (variable=='njets') ) #axes etc.  

  l_fid_eff_mode = TLegend(0.76,0.67,0.99,0.90)
  FormatLeg(l_fid_eff_mode)
  for i,hist in enumerate(h_cf_mode):    
    l_fid_eff_mode.AddEntry(hist, label_mode[i],'lep')
  l_fid_eff_mode.SetTextFont(42)
  l_fid_eff_mode.SetTextSize(0.04)
  l_fid_eff_mode.Draw()
  
  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL("Simulation, #sqrt{s} = 8 TeV", 0.76)
  ADD_LABEL("#it{m}_{H} = 125.4 GeV", 0.70)

  c_fid_eff_mode.Write()
  
  #------------------------------

  print "Table of Correction Factors",variable ,"\n"
    
  for i,hist in enumerate(h_fid_eff_mode):    
    print latex_mode[i],'\t ',
    for j in range(n_bins):
       val = hist[j+1]
       val_stat = hist.GetBinError(j+1)

       precision = 1+int(math.ceil(-math.log(val_stat,10)))

       print '& $', '{0:.{1}f}'.format(val, precision),
       print ' \\pm','{0:.{1}f}'.format(val_stat,precision), ' $\t ',
    print ' \\\\'
  print '\\hline'
  print 'Combined\t',
  for j in range(n_bins):
     val = h_fiducial_efficiency[j+1]
     val_stat = h_fiducial_efficiency.GetBinError(j+1)

     precision = 1+int(math.ceil(-math.log(val_stat,10)))

     print '& $', '{0:.{1}f}'.format(val, precision),
     print ' \\pm','{0:.{1}f}'.format(val_stat,precision), ' $\t ',
  print ' \\\\ \n\\hline'
    
  print '----------------------------------------------\n\n'
  
  #------------------------------
  
  #get yield predictions
  h_red_el_yield = finputs.Get('hists/h_'+variable+'_Reducible_ee_nominal')
  h_red_el_yield_syst_up = finputs.Get('hists/h_'+variable+'_Reducible_ee_syst_up')
  h_red_el_yield_syst_dn = finputs.Get('hists/h_'+variable+'_Reducible_ee_syst_dn')

  h_red_mu_yield = finputs.Get('hists/h_'+variable+'_Reducible_mm_nominal')
  h_red_mu_yield_syst_up = finputs.Get('hists/h_'+variable+'_Reducible_mm_syst_up')
  h_red_mu_yield_syst_dn = finputs.Get('hists/h_'+variable+'_Reducible_mm_syst_dn')

  red_hists 	    = [h_red_el_yield,h_red_mu_yield]
  red_hists_syst_up = [h_red_el_yield_syst_up,h_red_mu_yield_syst_up]
  red_hists_syst_dn = [h_red_el_yield_syst_dn,h_red_mu_yield_syst_dn]

  h_ggZZ_yield         = finputs.Get('hists/h_'+variable+'_ggZZ_nominal')
  h_ggZZ_yield_syst_up = finputs.Get('hists/h_'+variable+'_ggZZ_syst_up')
  h_ggZZ_yield_syst_dn = finputs.Get('hists/h_'+variable+'_ggZZ_syst_dn')

  h_qqZZ_yield   =  finputs.Get('hists/h_'+variable+'_qqZZ_nominal')
  h_qqZZ_yield_syst_up = finputs.Get('hists/h_'+variable+'_qqZZ_syst_up')
  h_qqZZ_yield_syst_dn = finputs.Get('hists/h_'+variable+'_qqZZ_syst_dn')

  #ZZ hists are missing lumi uncertainty, add it here:
  lumi_unc = 2.8 #%
  for i in range(n_bins):
    h_ggZZ_yield_syst_up[i+1] = sqrt(pow(lumi_unc,2) + pow(h_ggZZ_yield_syst_up[i+1],2))
    h_ggZZ_yield_syst_dn[i+1] = sqrt(pow(lumi_unc,2) + pow(h_ggZZ_yield_syst_dn[i+1],2))
    h_qqZZ_yield_syst_up[i+1] = sqrt(pow(lumi_unc,2) + pow(h_qqZZ_yield_syst_up[i+1],2))
    h_qqZZ_yield_syst_dn[i+1] = sqrt(pow(lumi_unc,2) + pow(h_qqZZ_yield_syst_dn[i+1],2))
  
  ZZ_hists 	   = [h_ggZZ_yield,h_qqZZ_yield]
  ZZ_hists_syst_up = [h_ggZZ_yield_syst_up,h_qqZZ_yield_syst_up]
  ZZ_hists_syst_dn = [h_ggZZ_yield_syst_dn,h_qqZZ_yield_syst_dn]

  h_red_yield,h_d1,h_d2 = AddHistsWithSysts('h_red_yield', red_hists, red_hists_syst_up,red_hists_syst_dn)  
  h_ZZ_yield ,h_d3,h_d4 = AddHistsWithSysts('h_ZZ_yield',  ZZ_hists, ZZ_hists_syst_up,ZZ_hists_syst_dn)

  h_bkg_yield,h_bkg_yield_syst_up,h_bkg_yield_syst_dn = AddHistsWithSysts('h_bkg_yield', red_hists+ZZ_hists,red_hists_syst_up+ZZ_hists_syst_up, red_hists_syst_dn+ZZ_hists_syst_dn) 
  
  #h_bkg_yield.Print('all')
  #h_bkg_yield_syst_up.Print('all')
  #h_bkg_yield_syst_dn.Print('all')
    
  h_data_yield = finputs.Get('hists/h_'+variable+'_data_nominal')
  h_data_yield_perr  = PoissonGraph(h_data_yield,     'h_data_yield_perr')
  
  h_signal_yield = finputs.Get('hists/h_'+variable+'_signal_nominal')
 
  #now make plot
  c_dn_dy_bkg = TCanvas('dN_dy_Background_'+variable,'',w,h)

  #plot MC prediction
  h_red_yield.SetFillColor(kViolet+1)
  h_red_yield.SetLineWidth(2)
  h_red_yield.SetLineColor(kBlack)
  h_ZZ_yield.SetFillColor(kRed+1)
  h_ZZ_yield.SetLineWidth(2)
  h_ZZ_yield.SetLineColor(kBlack)
  h_signal_yield.SetFillColor(kAzure-9)
  h_signal_yield.SetLineWidth(2)
  h_signal_yield.SetLineColor(kBlack)

  #dummy = TH1F('h_dummy',';'+x_label_reco+'Events',n_bins, array('d',bins))  
  
  stack = THStack()
  #stack.Add(dummy)
  stack.Add(h_red_yield)
  stack.Add(h_ZZ_yield)
  stack.Add(h_signal_yield)

  #stack.SetMaximum(3.5*stack.GetMaximum())
  stack.SetMaximum(2.15*h_data_yield.GetMaximum())
  stack.SetMinimum(0.001)

  stack.Draw("HIST")  
  
  if (variable=='njets'): makeNjetsXaxis(stack)   
  stack.GetXaxis().SetTitle(x_label_reco)
  stack.GetYaxis().SetTitle('Events')
  
  stack.Draw("HIST")

  #add uncertainty band on background prediction
  h_bkg_yield_err = AsymmErrorHist(h_bkg_yield,h_bkg_yield_syst_up,h_bkg_yield_syst_dn)
  gStyle.SetHatchesSpacing(0.75)
  PlotBand(h_bkg_yield_err, false, 3, true)
  h_bkg_yield_err.SetLineWidth(0)
  h_bkg_yield_err.SetLineColor(kWhite)
  #gStyle.SetHatchesLineWidth(1)

  #plot Data
  PlotGraph( h_data_yield_perr, false, 0, true)
 
  c_dn_dy_bkg.RedrawAxis()

  #l_dn_dy_bkg = NewLegend(4, 'tr')
  l_dn_dy_bkg = TLegend(0.55, 0.66, 0.9,0.9)
  FormatLeg(l_dn_dy_bkg)
  l_dn_dy_bkg.SetTextSize(0.04)
  l_dn_dy_bkg.SetTextFont(42)
  l_dn_dy_bkg.AddEntry(h_data_yield_perr, 'data','LEP')
  l_dn_dy_bkg.AddEntry(h_signal_yield, 'Signal (#it{m}_{H} = 125 GeV)','F')
  l_dn_dy_bkg.AddEntry(h_ZZ_yield, 'Background ZZ*','F')
  l_dn_dy_bkg.AddEntry(h_red_yield, 'Background Z+jets, t#bar{t}','F')
  l_dn_dy_bkg.AddEntry(h_bkg_yield_err, 'Systematic uncertainty','F')
  l_dn_dy_bkg.Draw()

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL( label, 0.75)
  ADD_LABEL( label_sr, 0.68)
  c_dn_dy_bkg.Write()

  #------------------------------

  
  print 'Closing output files: '
  print '\t',fout.GetPath().rstrip(':/')
  fout.Close()
      
  return
    

def makeTables(inputDir, outputDir, tag):
  
  #variable = variables[var_i]
  #bins = var_bins[var_i]
  #n_bins = len(bins) - 1
  
  
  fins = []
  finputs = []
  for variable in variables:
    fins.append( TFile( inputDir + '/results/obsData/modified_nll_scans_'+variable+'.root'))
    finputs.append( TFile( inputDir + '/data/WorkspaceInputs.'+variable+'.root'))

  print "Processing var", variable
  
  #compatibility test tables
  print '----------------------------------------------'
  print "\\multicolumn{3}{c}{\\Powheg\\ $\chi^2$ Compatibility (\\%) } \\\\"
  print '\\hline'
  print "Variable & $\mu_i$=1.0  & $\mu_i$=1.5 \\\\ "
  print '\\hline'
  for i,variable in enumerate(variables):
    if i==0: continue
    print var_latex[i].ljust(20) + '\t& ', int(round(fins[i].Get('chi2_prob_one').GetVal()*100,0)), '\t&',int(round(fins[i].Get('chi2_prob_onep5').GetVal()*100,0)), '\t\\\\'
  print '\\hline'
  print '----------------------------------------------'
  print "\\multicolumn{3}{c}{\\HResTwo\\ $\chi^2$ Compatibility (\\%) } \\\\"
  print '\\hline'
  print "Variable & $\mu_i$=1.0  & $\mu_i$=1.5 \\\\ "
  print '\\hline'
  for i,variable in enumerate(variables):
    if not fins[i].Get('chi2_prob_one_HRes'): continue
    print var_latex[i].ljust(20) + '\t& ', int(round(fins[i].Get('chi2_prob_one_HRes').GetVal()*100,0)), '\t&',int(round(fins[i].Get('chi2_prob_onep5_HRes').GetVal()*100,0)), '\t\\\\'
  print '\\hline'  
  print '----------------------------------------------'
  print "\\multicolumn{3}{c}{\\Minlo\\ $\chi^2$ Compatibility (\\%) } \\\\"
  print '\\hline'
  print "Variable & $\mu_i$=1.0  & $\mu_i$=1.5 \\\\ "
  print '\\hline'
  for i,variable in enumerate(variables):
    if not fins[i].Get('chi2_prob_one_HJ'): continue
    print var_latex[i].ljust(20) + '\t& ', int(round(fins[i].Get('chi2_prob_one_HJ').GetVal()*100,0)), '\t&',int(round(fins[i].Get('chi2_prob_onep5_HJ').GetVal()*100,0)), '\t\\\\'
  print '\\hline'  
  print '----------------------------------------------\n\n\n'
   
  #event yield tables
  for i,variable in enumerate(variables):
    n_bins = len(var_bins[i])-1
    print variable

    print '$N_{\mathrm{irreducible}}$ \t ',
    hist = finputs[i].Get('hists/h_'+variable+'_qqZZ_nominal').Clone()
    hist.Add(finputs[i].Get('hists/h_'+variable+'_ggZZ_nominal'))
    for j in range(n_bins):
      print  '&',round(hist[j+1],2),'\t',  
    print' \\\\ '

    print '$N_{\mathrm{reducible}}$ \t ',
    hist = finputs[i].Get('hists/h_'+variable+'_Reducible_ee_nominal').Clone()
    hist.Add(finputs[i].Get('hists/h_'+variable+'_Reducible_mm_nominal'))
    for j in range(n_bins):
      print  '&',round(hist[j+1],2),'\t',  
    print' \\\\ '

    print '$N_{\mathrm{signal}}^{\mathrm{expected}}$ \t ',
    hist = finputs[i].Get('hists/h_'+variable+'_signal_nominal')
    for j in range(n_bins):
      print  '&',round(hist[j+1],2),'\t',  
    print' \\\\ \n \\hline '
    
    print '$N_{\mathrm{total}}^{\mathrm{expected}}$ \t ',
    hist = finputs[i].Get('hists/h_'+variable+'_asimovData_nominal')
    for j in range(n_bins):
      print  '&',round(hist[j+1],2),'\t',  
    print' \\\\ '

    print '$n^{\mathrm{observed}}$ \t ',
    hist = finputs[i].Get('hists/h_'+variable+'_data_nominal')
    for j in range(n_bins):
      print  '&',round(hist[j+1],0),'\t',  
    print' \\\\ \n \\hline'

    print '$n^{\mathrm{observed}}-N_{\mathrm{bkg}}$ \t ',
    hist  = finputs[i].Get('hists/h_'+variable+'_data_nominal').Clone()
    hist.Add(finputs[i].Get('hists/h_'+variable+'_qqZZ_nominal'), -1)
    hist.Add(finputs[i].Get('hists/h_'+variable+'_ggZZ_nominal'), -1)
    hist.Add(finputs[i].Get('hists/h_'+variable+'_Reducible_ee_nominal'), -1)
    hist.Add(finputs[i].Get('hists/h_'+variable+'_Reducible_mm_nominal'), -1)
    for j in range(n_bins):
      print  '&',round(hist[j+1],2),'\t',  
    print' \\\\'

    print '$n^{\mathrm{fit}}_{\mathrm{signal}} $ \t ',
    g = fins[i].Get(variable+'_NE')
    for j in range(n_bins):
      print  '&',round(g.GetY()[j],2),'\t',  
    print' \\\\ \n \\hline'

    print '----------------------------------------------\n'
  
  #correction factor tables
  print "Table of Correction Factors\n"
    
  for i,variable in enumerate(variables):
    if (i==0): continue
    n_bins = len(var_bins[i])-1
    
    hist         = finputs[i].Get('hists/h_'+variable+'_correction_factor_nominal')
    hist_syst_up = finputs[i].Get('hists/h_'+variable+'_correction_factor_syst_up')
    hist_syst_dn = finputs[i].Get('hists/h_'+variable+'_correction_factor_syst_dn')
    
    print var_latex[i], '\t', 
    for j in range(5):
      if (j+1 > n_bins):
        print '& -',
      else:	
	val = 1./hist[j+1]
	val_stat = hist.GetBinError(j+1)/pow(hist[j+1],2)
	val_up   = hist_syst_up[j+1]/100*val
	val_dn   = hist_syst_dn[j+1]/100*val
	
	precision = 1+int(math.ceil(max(-math.log(val_up,10),-math.log(val_dn,10))))
        	
	print '& $', '{0:.{1}f}'.format(val, precision),
	print '\\pm','{0:.{1}f}'.format(val_stat,precision),'\\rm{(stat)}',
	s_err_up = '{0:.{1}f}'.format(val_up,precision)
	s_err_dn = '{0:.{1}f}'.format( val_dn,precision)
	if (s_err_up == s_err_dn):	   
  	  print '\\pm', s_err_up,	 
	else:
	  print '^{+',s_err_up,'}',
	  print '_{-',s_err_dn,'}',
	print '\\rm{(syst)}  $\t',
	
    print ' \\\\ '
  
  print '----------------------------------------------\n\n'

  #observed cross section results table
  print "Table of Cross sections\n"
  
  for i,variable in enumerate(variables):
    if (i==0): continue
    n_bins = len(var_bins[i])-1
    
    graph = fins[i].Get(variable+'_XS') 
    
    print var_latex[i], ' & [fb'+('/'+var_units[i] if var_units[i] != '' else '') +']','\t',
    for j in range(5):
      if (j+1 > n_bins):
        print '& -',
      else:
      	# take precision from smaller of the errors - keep 2 sig figs
	precision = 1+int(math.ceil(max(-math.log(graph.GetErrorYhigh(j),10),-math.log(graph.GetErrorYlow(j),10))))
		
	nom = '{0:.{1}f}'.format(graph.GetY()[j],precision)
	err_up = '{0:.{1}f}'.format(graph.GetErrorYhigh(j), precision)
	err_dn = '{0:.{1}f}'.format(graph.GetErrorYlow(j),  precision)
		
	print '& $', nom, '^{+',err_up,'}', '_{-',err_dn,'}', ' $\t',
	
    print ' \\\\ '

  print '\n----------------------------------------------\n\n'


  return

#input: list of hists to be added.  hists_up and hists_dn are histgrams containing the relative systematic in %s
def AddHistsWithSysts(name, hists, hists_up, hists_dn):
  
  if not(len(hists) > 0 and len(hists)==len(hists_up) and len(hists)==len(hists_dn)):
    print 'AddHistsWithSysts: ERROR'
    return
  
  h_sum = hists[0].Clone(name)
  h_sum_syst_up = hists[0].Clone(name+'_syst_up')
  h_sum_syst_dn = hists[0].Clone(name+'_syst_dn')

  h_sum.Reset()
  h_sum_syst_up.Reset()
  h_sum_syst_dn.Reset()
  
  n_bins = h_sum.GetNbinsX()
  
  for i in range(len(hists)):      
    for j in range(n_bins+2):
      
      #calculate absolute errors
      sum_err_up = h_sum[j]*h_sum_syst_up[j]/100
      sum_err_dn = h_sum[j]*h_sum_syst_dn[j]/100

      hist_err_up = hists[i][j]*hists_up[i][j]/100
      hist_err_dn = hists[i][j]*hists_dn[i][j]/100
      
      #add errors in quadrature
      syst_up = sqrt(pow(sum_err_up,2) + pow(hist_err_up,2)) 
      syst_dn = sqrt(pow(sum_err_dn,2) + pow(hist_err_dn,2)) 

      h_sum_syst_up[j] = syst_up / (h_sum[j]+ hists[i][j]) * 100
      h_sum_syst_dn[j] = syst_dn / (h_sum[j]+ hists[i][j]) * 100
      
    h_sum.Add(hists[i])
 
  return h_sum,h_sum_syst_up,h_sum_syst_dn 

def makeNjetsXaxis(hist):

  hist.GetXaxis().SetBinLabel(1,'0');
  hist.GetXaxis().SetBinLabel(2,'1');
  hist.GetXaxis().SetBinLabel(3,'2');
  hist.GetXaxis().SetBinLabel(4,'#geq 3');
  hist.GetXaxis().SetLabelSize(0.07);
  hist.GetXaxis().SetNdivisions(503,false)
      
  return
 
def AtlasStyle(hist):

  font=42
  tsize=0.05;
  #hist.SetTextFont(font);
  #hist.SetTextSize(tsize);

  hist.GetXaxis().SetLabelFont(font);
  hist.GetXaxis().SetTitleFont(font);
  hist.GetYaxis().SetLabelFont(font);
  hist.GetYaxis().SetTitleFont(font);
  hist.GetZaxis().SetLabelFont(font);
  hist.GetZaxis().SetTitleFont(font);
  
  hist.GetXaxis().SetLabelSize(tsize);
  hist.GetXaxis().SetTitleSize(tsize);
  hist.GetYaxis().SetLabelSize(tsize);
  hist.GetYaxis().SetTitleSize(tsize);
  hist.GetZaxis().SetLabelSize(tsize);
  hist.GetZaxis().SetTitleSize(tsize);

  hist.GetXaxis().SetTitleOffset(1.4);
  hist.GetYaxis().SetTitleOffset(1.4);

  #hist.SetOptTitle(0);
  #hist.SetOptStat(0);
  hist.SetStats(False);

  return
  
  
if __name__ == '__main__' :
    main()

