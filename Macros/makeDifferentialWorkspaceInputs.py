"""
Produce input text files for all workspace numbers
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'July 2013'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

import os
import math
from numpy import *
from ROOT import *
from PlotUtils import *
from AnalysisRoutines import *
from variables import *
import glob
import re

tag='test'

#inputDir =  "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/minitree_v04/mc12/";
inputDir =  "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/stahlman_minitree_v05/";

inputDir_Reducible = '/disk/userdata00/atlas_data2/stahlman/output/fromEleonora/WorkspaceInputs.Reducible.v7/'

systematicDir   = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v09/"

systematicDir_ZZ = '/disk/userdata00/atlas_data2/stahlman/output/fromAndrea/ZZ_systematics/v1/'

fid_corrections_file_name = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Fiducial/v10/FiducialStudy.H120_H130.root"
 
fid_corrections_syst_file_name = '/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v10/CorrectionFactorSystematics.H125p4.root'
 
outputDir = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Workspaces/inputs/v08/";
#outputDir = "/disk/userdata00/atlas_data2/stahlman/output/test/";

usePseudoData = false


def main():

   for i in range(len(variables)):
   #for i in range(3,1):
     makeInputs(i)
  
   return

def makeInputs(var):

  var_name = variables[var]
  v_reco = var_mt[var]
  var_label_reco = var_labels_reco[var]
  var_label_truth = var_labels_truth[var]
  var_unit = var_units[var]
  v_bins = var_bins[var]
  v_ZZshape_from_CR1 = var_ZZshape_from_CR1[var]

  #separateChannels = false

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

  hzz_label = 'H#rightarrow ZZ^{(*)}#rightarrow4l'
  atlas_label_text = 'Internal'
  label = "#sqrt{s} = 8 TeV #int L dt = 20.3 fb^{-1}"

  x_label_reco  = var_label_reco  + (' ['+var_unit+']' if var_unit != "" else "")
  x_label_truth = var_label_truth + (' ['+var_unit+']' if var_unit != "" else "")

  mass_window = "(("+mass_window_var+" < " + str(mass_window_hi) + ")&&("+mass_window_var+" > " + str(mass_window_lo)+"))"
  mass_window_CR1 = "("+mass_window_var+" > " + str(mass_window_CR1_lo)+")"
  mass_window_CR2 = "("+mass_window_var+" < " + str(mass_window_CR2_hi)+")"

  #Open Output File ------------------------------------------------------------------------------------------------------------

  fout = TFile(outputDir + "WorkspaceInputs."+var_name+'.'+tag+".root", "RECREATE")
  fout.cd()
  
  hists = [] #list of hists to be saved
        

  #------------------------------------------------------------------------------------------------------------
  #ggZZ ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------
  
  ggZZ_file_names = glob.glob(inputDir + '/*gg2ZZ*.root')
  print "Using ggZZ files:"
  for f in ggZZ_file_names: print '\t',f

  ggZZ_chain   = GetChain(tree_name, ggZZ_file_names)

  h_ggZZ_yield = TH1F("h_ggZZ_yield", ";"+x_label_reco+";events",n_bins, bins)
  h_ggZZ_yield.Sumw2()
  
  ggZZ_chain.Draw(v_reco+" >> h_ggZZ_yield", "weight*"+mass_window, "goff");  
  
  ggZZ_yield = [ h_ggZZ_yield[i+1] for i in range(n_bins) ]
    
  # ggZZ systematics
  ggZZ_syst_names = []
  ggZZ_syst_vals  = []
 
  #MC stat
  ggZZ_syst_names.append('MCStat_ggZZ,Sym')
  ggZZ_syst_vals.append( [ h_ggZZ_yield.GetBinError(i+1)/h_ggZZ_yield[i+1]*100 for i in range(n_bins) ] )  
 
  #theory normalization
  ggZZ_syst_names.append('QCDScale_ggZZ,Sym')
  ggZZ_syst_vals.append( [ 24.3 for i in range(n_bins) ] )

  ggZZ_syst_names.append('PDF_ggZZ,Sym')
  ggZZ_syst_vals.append( [ 7.1 for i in range(n_bins) ] )

  #theory shape systematics
  ZZ_shape_syst_file = systematicDir_ZZ+ "/ZZShapeSystematics_"+var_name+".txt"  
  LoadfromFile(ZZ_shape_syst_file, ggZZ_syst_names, ggZZ_syst_vals, false, n_bins)
  
  #experimental systematics
  #use inclusive normalization systematics file if jet variable  
  ggZZ_bkg_syst_file = systematicDir+ "/Systematics."+('inclusive' if var_jet[var] else var_name)+".ggZZ.inclusive.txt"  
  LoadfromFile(ggZZ_bkg_syst_file, ggZZ_syst_names, ggZZ_syst_vals, var_jet[var], n_bins)
       
  WritetoFile(var_name, 'ggZZ', ggZZ_yield, ggZZ_syst_names, ggZZ_syst_vals)
  
  #return
  
  #------------------------------------------------------------------------------------------------------------
  #qqZZ ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------

  qqZZ_file_names = glob.glob(inputDir + '/*PowhegPythia8_AU2CT10_ZZ*.root')
  qqZZ_file_names += glob.glob(inputDir + '/*Sherpa_CT10_llll_ZZ_EW6_noHiggs.root')
  print "Using qqZZ files:"
  for f in qqZZ_file_names: print '\t',f
  
  qqZZ_chain   = GetChain(tree_name, qqZZ_file_names)
  
  h_qqZZ_yield = TH1F("h_qqZZ_yield", ";"+x_label_reco+";events",n_bins, bins)    
  h_qqZZ_yield.Sumw2()

  qqZZ_chain.Draw(v_reco+" >> h_qqZZ_yield", "weight*"+mass_window, "goff");  
  qqZZ_yield = [ h_qqZZ_yield[i+1] for i in range(n_bins) ]

  #systematics
  qqZZ_syst_names = []
  qqZZ_syst_vals  = []

  #MC stat
  qqZZ_syst_names.append('MCStat_qqZZ,Sym')
  qqZZ_syst_vals.append( [ h_qqZZ_yield.GetBinError(i+1)/h_qqZZ_yield[i+1]*100 for i in range(n_bins) ] )  

  #theory normalization systematic
  qqZZ_syst_names.append('QCDScale_qqZZ,Sym')
  qqZZ_syst_vals.append( [ 2.8 for i in range(n_bins) ] )
  
  qqZZ_syst_names.append('PDF_qqZZ,Sym')
  qqZZ_syst_vals.append( [ 3.4 for i in range(n_bins) ] )

  #theory shape systematics
  ZZ_shape_syst_file = systematicDir_ZZ+ "/ZZShapeSystematics_"+var_name+".txt"  
  LoadfromFile(ZZ_shape_syst_file, qqZZ_syst_names, qqZZ_syst_vals, false, n_bins)
  
  #experimental systematics 
  #use inclusive normalization systematics file if jet variable  
  qqZZ_bkg_syst_file = systematicDir+ "/Systematics."+('inclusive' if var_jet[var] else var_name)+".qqZZ.inclusive.txt"  
  LoadfromFile(qqZZ_bkg_syst_file, qqZZ_syst_names, qqZZ_syst_vals, var_jet[var], n_bins)
  
  WritetoFile(var_name, 'qqZZ', qqZZ_yield, qqZZ_syst_names, qqZZ_syst_vals)  

  #return
  
  #------------------------------------------------------------------------------------------------------------
  #Correction Factors  ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------

  print "Using fiducial corrections file:"
  print '\t',fid_corrections_file_name
  fid_correction_file = TFile( fid_corrections_file_name, "READ")
  fid_correction_syst_file = TFile( fid_corrections_syst_file_name, "READ")
  
  h_correction_factor_124 = fid_correction_file.Get("H124/h_"+var_name+"_correction_factor")
  h_correction_factor_125 = fid_correction_file.Get("H125/h_"+var_name+"_correction_factor")
  h_correction_factor_126 = fid_correction_file.Get("H126/h_"+var_name+"_correction_factor")

  #correction_factor = [ h_correction_factor_125[i+1] for i in range(n_bins) ]
  correction_factor = [ h_correction_factor_125[i+1] + 0.4*(h_correction_factor_126[i+1]-h_correction_factor_125[i+1]) for i in range(n_bins) ]  
  
  #correction factor systematics  
  cf_syst_names = []
  cf_syst_vals  = []
  
  #MC stats
  cf_syst_names.append('MCStat_correction_factor,Sym')
  cf_syst_vals.append( [ h_correction_factor_125.GetBinError(i+1)/h_correction_factor_125[i+1]*100 for i in range(n_bins) ] )    
  
  #experimental systematics
  signal_syst_file = systematicDir+ "/Systematics."+var_name+".H125.inclusive.txt"  
  LoadfromFile(signal_syst_file, cf_syst_names, cf_syst_vals)

  #model-dependence systematic
  hist = fid_correction_syst_file.Get('h_correction_factor_comp_syst_'+var_name)
  cf_syst_names.append( 'ATLAS_norm_SF_SignalComp,Sym' )
  cf_syst_vals.append( [ hist[i+1] for i in range(n_bins) ] )
  
  #higgs mass systematic?
  hist = fid_correction_syst_file.Get('h_correction_factor_mass_syst_'+var_name)
  cf_syst_names.append( 'ATLAS_norm_SF_HiggsMass,Sym' )
  cf_syst_vals.append( [ hist[i+1] for i in range(n_bins) ] )
      
  WritetoFile(var_name, 'correction_factor', correction_factor, cf_syst_names, cf_syst_vals)  
  
  #return
  
  #------------------------------------------------------------------------------------------------------------
  #Signal - Powheg  ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------

  signal_file_names = glob.glob(inputDir + '/*H125*.root')
  print "Using signal files:"
  for f in signal_file_names: print '\t',f
  
  mode_file_names = []
  for mode in name_mode: mode_file_names.append( glob.glob(inputDir + '/*'+mode+'125*.root'))

  signal_chain = GetChain(tree_name, signal_file_names)

  signal_mode_chain = []
  for files in mode_file_names:  signal_mode_chain.append(GetChain(tree_name, files))

  h_signal_yield          	= TH1F("h_signal_yield",		";"+x_label_reco+";events",	n_bins, bins);hists.append(h_signal_yield)
  h_signal_yield.Sumw2()

  h_signal_yield_mode = []
  for i,mode in enumerate(name_mode):    
    h_signal_yield_mode.append( TH1F("h_signal_yield_"+mode,";"+x_label_reco+";events",	n_bins, bins));hists.append(h_signal_yield_mode[i])

  signal_chain.Draw(v_reco+" >> h_signal_yield",     "weight*"+mass_window,     "goff");
  signal_yield = [ h_signal_yield[i+1] for i in range(n_bins) ]
  print "Total",h_signal_yield.Integral(0,n_bins+1),
  print '' if (var_name != 'inclusive') else '+-',h_signal_yield.GetBinError(1)

  
  for i in range(n_modes):
    h_signal_yield_mode[i].Sumw2()
    signal_mode_chain[i].Draw(v_reco+" >> h_signal_yield_"+name_mode[i],     "weight*"+mass_window,     "goff");
    print name_mode[i], h_signal_yield_mode[i].Integral(0,n_bins+1),
    print '' if (var_name != 'inclusive') else '+-',h_signal_yield_mode[i].GetBinError(1)
    
  print "signal systematics"
  signal_syst_names = []
  signal_syst_vals  = []
     
  WritetoFile(var_name, 'signal', signal_yield, signal_syst_names, signal_syst_vals)  
  
  #return

  #------------------------------------------------------------------------------------------------------------
  #dsigmadx - Powheg  ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------
  
  h_dsigmadx = fid_correction_file.Get("H125/h_"+var_name+"_dsigmadx")
    
  dsigmadx = [ h_dsigmadx[i+1] for i in range(n_bins) ]
  
  #correction factor systematics  
  dsigmadx_syst_names = []
  dsigmadx_syst_vals  = []
  
  #MC stats
  dsigmadx_syst_names.append('MCStat_dsigmadx,Sym')
  dsigmadx_syst_vals.append( [ h_dsigmadx.GetBinError(i+1)/h_dsigmadx[i+1]*100 for i in range(n_bins) ] )    

  #signal theory - QCD 
  dsigmadx_syst_names.append('QCDScale_signal,Sym')
  dsigmadx_syst_vals.append( [ 8 for i in range(n_bins) ] )

  #signal theory - PDF 
  dsigmadx_syst_names.append('PDF_signal,Sym')
  dsigmadx_syst_vals.append( [ 8 for i in range(n_bins) ] )
  
  #other systematics to come from Kurt
        
  WritetoFile(var_name, 'dsigmadxPowheg', dsigmadx, dsigmadx_syst_names, dsigmadx_syst_vals)  
  
  #------------------------------------------------------------------------------------------------------------
  #dsigmadx - non-ggH modes  ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------  
  
  h_dsigmadx_mode_125 = [ fid_correction_file.Get(mode+"125/h_"+var_name+"_dsigmadx") for mode in name_mode ]
  h_dsigmadx_mode_126 = [ fid_correction_file.Get(mode+"126/h_"+var_name+"_dsigmadx") for mode in name_mode ]

  h_dsigmadx_mode_125p4 = [ h_dsigmadx_mode_125[0].Clone('h_'+var_name+'dsigmadx_125p4_'+mode) for mode in name_mode ]
  for i in range(n_modes): h_dsigmadx_mode_125p4[i].Add(h_dsigmadx_mode_125[i], h_dsigmadx_mode_126[i], 0.6, 0.4)
  
  dsigmadx_noggH = [ sum([h_dsigmadx_mode_125p4[i][j+1] for i in range(1,n_modes) ]) for j in range(n_bins) ]
  
  #correction factor systematics  
  dsigmadx_noggH_syst_names = []
  dsigmadx_noggH_syst_vals  = []
  
  #MC stats
  #dsigmadx_syst_names.append('MCStat_dsigmadx,Sym')
  #dsigmadx_syst_vals.append( [ h_dsigmadx.GetBinError(i+1)/h_dsigmadx[i+1]*100 for i in range(n_bins) ] )    

  #signal theory - QCD 
  #dsigmadx_syst_names.append('QCDScale_signal,Sym')
  #dsigmadx_syst_vals.append( [ 8 for i in range(n_bins) ] )

  #signal theory - PDF 
  #dsigmadx_syst_names.append('PDF_signal,Sym')
  #dsigmadx_syst_vals.append( [ 8 for i in range(n_bins) ] )
  
  #other systematics to come from Kurt
        
  WritetoFile(var_name, 'dsigmadxnoggH', dsigmadx_noggH, dsigmadx_noggH_syst_names, dsigmadx_noggH_syst_vals)  
  
  #------------------------------------------------------------------------------------------------------------
  #Data  ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------

  data_file_names =  glob.glob(inputDir + '/data12.root')

  print "Using data files:"
  for f in data_file_names: print '\t',f

  data_chain   = GetChain(tree_name, data_file_names)

  h_data_yield     = TH1F("h_data_yield",";"+x_label_reco+";events",n_bins, bins);hists.append(h_data_yield)

  if (usePseudoData):
    for i in range(h_data_yield.GetNbinsX()+2):
       h_data_yield[i] = random.poisson(h_ggZZ_yield[i]+h_qqZZ_yield[i]+h_signal_yield[i])#+h_red_yield[i]  
  else:
    data_chain.Draw( v_reco+" >> h_data_yield", mass_window, "goff");
  data_yield = [ h_data_yield[i+1] for i in range(n_bins) ]
    
  WritetoFile(var_name, 'data', data_yield, [], [])  
  
  #------------------------------------------------------------------------------------------------------------
  #Reducible - muons  ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------
  
  file_name = '/WorkspaceInput.'+var_name+'.Reducible_mm.txt'
  red_mu_file = open(inputDir_Reducible+file_name,'r')

  nom_vals = (red_mu_file.readline()).split()
        
  h_red_mm_yield = TH1F("h_red_mm_yield", ";"+x_label_reco+";events",n_bins, bins)
  for i in range(n_bins): h_red_mm_yield[i+1] = float(nom_vals[i+1])
    
  os.system('cp '+inputDir_Reducible+file_name + ' ' + outputDir+file_name) 
  
  #------------------------------------------------------------------------------------------------------------
  #Reducible - electrons  ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------

  file_name = '/WorkspaceInput.'+var_name+'.Reducible_ee.txt'
  red_mu_file = open(inputDir_Reducible+file_name,'r')

  nom_vals = (red_mu_file.readline()).split()
  
  h_red_ee_yield = TH1F("h_red_ee_yield", ";"+x_label_reco+";events",n_bins, bins)
  for i in range(n_bins): h_red_ee_yield[i+1] = float(nom_vals[i+1])
    
  os.system('cp '+inputDir_Reducible+file_name + ' ' + outputDir+file_name) 

  #------------------------------------------------------------------------------------------------------------
  #Asimov Data  ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------

  h_sig_plus_bkg     = TH1F("h_sig_plus_bkg",";"+x_label_reco+";events",n_bins, bins);hists.append(h_data_yield)
  
  h_sig_plus_bkg.Add(h_signal_yield)
  h_sig_plus_bkg.Add(h_qqZZ_yield)
  h_sig_plus_bkg.Add(h_ggZZ_yield)
  h_sig_plus_bkg.Add(h_red_mm_yield)
  h_sig_plus_bkg.Add(h_red_ee_yield)

  sig_plus_bkg = [ h_sig_plus_bkg[i+1] for i in range(n_bins) ]
    
  WritetoFile(var_name, 'asimovData', sig_plus_bkg, [], [])  

  #------------------------------------------------------------------------------------------------------------
  #Bin Widths  ------------------------------------------------------------------------------------------------------------
  #------------------------------------------------------------------------------------------------------------
  
  bin_widths = [ bins[i+1]-bins[i] for i in range(n_bins) ]
  
  WritetoFile(var_name, 'DX', bin_widths, [], [])  

  return

      
 
def WritetoFile(var_name, par_name, par_vals, par_syst, par_syst_vals):
  
  print par_name, '-',var_name,'-', par_vals
  
  f_name = outputDir + "/WorkspaceInput."+var_name+'.'+par_name+'.txt'
  f = open(f_name, 'w')
  
  line = ('Nominal,'+par_name).ljust(40)+'\t'
  for val in par_vals: line += str(val)+'\t'
  f.write(line+'\n')
  
  #print par_syst
  #print par_syst_vals
  for i,syst in enumerate(par_syst):
    line = syst.ljust(40)+'\t'
    for val in par_syst_vals[i]: line += str(val)+'\t'
    f.write(line+'\n')
  
  print "Output: ",f_name   
  f.close()
  
  return 
  
def LoadfromFile(syst_file, syst_names, syst_vals, v_jet=False, n_bins=0):

  for line in open(syst_file):
    tokens = line.split()  
    if (len(tokens) == 0): continue
    syst_names.append( tokens[0] )
    if (v_jet):
      syst_vals.append( [ float(tokens[1]) for i in range(n_bins) ] )     
    else:
      syst_vals.append( [ float(tokens[i]) for i in range(1,len(tokens)) ] )
  
  return
    
if __name__ == '__main__' :
    main()

  
