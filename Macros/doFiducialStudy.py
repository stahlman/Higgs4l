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

import os
import math
from ROOT import *
from PlotUtils import *
from AnalysisRoutines import *
from variables import *
import glob
import re

non_decimal = re.compile(r'[^\d.]+')

lumi = 20.277 #fb-1

def main():

  ROOT.gROOT.LoadMacro("AtlasStyle.C");
  ROOT.gROOT.LoadMacro("AtlasUtils.C");
  SetAtlasStyle()

  #tag='2012'
  #tag='2011'
  #tag='2011and2012'
  label = 'test'; tag='test'
  #label = 'No Mispairing'; tag='NoMispairing'

  #label = 'Window 115-130 GeV'; tag='Window.115-130'
  #label = 'Window 120-130 GeV'; tag='Window.120-130'

  tree_name = "inclusive"

  inputDir_fid = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/fiducial_minitree_v02/";
  #inputDir_fid = "/disk/userdata00/atlas_data2/stahlman/output/12032014/minitrees/"
  #inputDir_fid = "/disk/userdata00/atlas_data2/stahlman/output/27052014_Fiducial//minitrees/"

  inputDir_reco = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/stahlman_minitree_v05/";
  #inputDir_reco = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/minitree_v05/";
  #inputDir_reco = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/minitree_v04/mc12/";
  #inputDir_reco = "/disk/userdata00/atlas_data2/stahlman/output/27052014//minitrees/";

  outputDir = '/disk/userdata00/atlas_data2/stahlman/output/test/'
  #outputDir = inputDir_fid + "/Plots/";
  
  if not os.path.exists(outputDir): os.makedirs(outputDir)

  mass_window_lo = 118
  mass_window_hi = 129

  #Find input ------------------------------------------------------------------------------------------------------------

  #label = 'ggH, #sqrt{s} = 8 TeV'; tag='ggH'
  #label = 'ggH, #sqrt{s} = 8 TeV'; tag='ggH_Systematics'
  #label = 'VBFH, #sqrt{s} = 8 TeV'; tag='VBFH'
  #label = 'ZH, #sqrt{s} = 8 TeV'; tag='ZH'
  #label = 'WH, #sqrt{s} = 8 TeV'; tag='WH'
  #label = 'ttH, #sqrt{s} = 8 TeV'; tag='ttH'

  samples = []
  fid_filenames = []
  rec_filenames = []

  ##samples.append("ggH110");
  ##samples.append("ggH115");
#  samples.append("ggH120");
#  samples.append("ggH123");
#  samples.append("ggH124");
#  samples.append("ggH125");
#  samples.append("ggH126");
#  samples.append("ggH127");
#  samples.append("ggH130");
##  ##samples.append("ggH135");
##  ##samples.append("ggH140");
##  ##samples.append("ggH145");
##  ##samples.append("ggH150");
##  ##samples.append("ggH155");
##  ##samples.append("ggH160");
##  ##samples.append("ggH165");
##  ##samples.append("ggH170");
##  ##samples.append("ggH175");
##  ##samples.append("ggH180");
##  ##samples.append("ggH185");
##  ##samples.append("ggH190");
##  ##samples.append("ggH195");
##  ##samples.append("ggH200");
##  ##samples.append("ggH220");
##  ##samples.append("ggH260");
##  ##samples.append("ggH280");
##  ##samples.append("ggH300");
##  ##samples.append("ggH320");
##  ##samples.append("ggH340");
##  ##samples.append("ggH380");
#  #
#  #
##  ##samples.append("VBFH110")
##  ##samples.append("VBFH115")
#  samples.append("VBFH120")
#  samples.append("VBFH123")
#  samples.append("VBFH124")
#  samples.append("VBFH125")
#  samples.append("VBFH126")
#  samples.append("VBFH127")
#  samples.append("VBFH130")
##  ##samples.append("VBFH135")
##  ##samples.append("VBFH140")
##  ##samples.append("VBFH145")
##  ##samples.append("VBFH150")
##  ##samples.append("VBFH155")
##  ##samples.append("VBFH160")
#  #
##  ##samples.append("WH110");
##  ##samples.append("WH115");
#  samples.append("WH120");
#  samples.append("WH123");
#  samples.append("WH124");
#  samples.append("WH125");
#  samples.append("WH126");
#  samples.append("WH127");
#  samples.append("WH130");
##  ##samples.append("WH135");
##  ##samples.append("WH140");
##  ##samples.append("WH145");
##  ##samples.append("WH150");
##  ##samples.append("WH155");
##  ##samples.append("WH160");
#  ##
##  ##samples.append("ZH110");
##  ##samples.append("ZH115");
#  samples.append("ZH120");
#  samples.append("ZH123");
#  samples.append("ZH124");
#  samples.append("ZH125");
#  samples.append("ZH126");
#  samples.append("ZH127");
#  samples.append("ZH130");
##  ##samples.append("ZH135");
##  ##samples.append("ZH140");
##  ##samples.append("ZH145");
##  ##samples.append("ZH150");
##  ##samples.append("ZH155");
##  ##samples.append("ZH160");
#  ##
##  ##samples.append("ttH110")
#  samples.append("ttH120")
#  samples.append("ttH123")
#  samples.append("ttH124")
#  samples.append("ttH125")
#  samples.append("ttH126")
#  samples.append("ttH127")
#  samples.append("ttH130")
#  ##samples.append("ttH140")
  ##samples.append("ttH150")

  #systematics
  #samples.append("ggH125_SRenFacDown"); numbers.append("160354")
  #samples.append("ggH125_SRenFacUp"); numbers.append("160353")
  #samples.append("ggH125_AU2NNPDF21NLO"); numbers.append("160351")

  #125 samples
  #samples.append("ggH125"); 
  #samples.append("VBFH125");
  #samples.append("WH125");  
  #samples.append("ZH125"); 
  #samples.append("ttH125"); 

  #Mass points
  samples.append("H125"); 
  #samples.append("H124"); 
  #samples.append("H126"); 

  #samples = ['ggH125_ZZ4lep.', 'ggH125_ZZ4lep_SRenFacUp', 'ggH125_ZZ4lep_SRenFacDown' ]

  for i in range(len(samples)):
    fid_filenames.append(glob.glob(inputDir_fid+"/*"+samples[i]+"*.root"))
    print "Found", len(fid_filenames[i]),"fiducial files for sample", samples[i]
    for infile in fid_filenames[i]: print '\t',infile  

    rec_filenames.append(glob.glob(inputDir_reco+"/*"+samples[i]+"*.root"))
    print "Found", len(rec_filenames[i]),"reco files for sample", samples[i]
    for infile in rec_filenames[i]: print '\t',infile

  #Open Output File ------------------------------------------------------------------------------------------------------------

  channels = ["4mu", "4e", "2mu2e", "2e2mu", "incl"]
  latex_channels = ["4#mu", "4e", "2#mu2e", "2e2#mu", "incl"]

  fout = TFile(outputDir + "FiducialStudy."+tag+".root", "RECREATE")
  fout.cd()
    
  for i in range(len(samples)):
  #for i in range(1):
    make1DFiducialHistograms(samples[i], fid_filenames[i], rec_filenames[i], fout, "1", "1", "inclusive", [0.5,1.5], 0, 1000, "nomasswindow")
    make1DFiducialHistograms(samples[i], fid_filenames[i], rec_filenames[i], fout, "event_type_truth", "quad_type", "quad_type", [-0.5,0.5,1.5,2.5,3.5,4.5])
    make1DFiducialHistograms(samples[i], fid_filenames[i], rec_filenames[i], fout, "event_type_truth", "quad_type", "quad_type", [-0.5,0.5,1.5,2.5,3.5,4.5], mass_window_lo, mass_window_hi, "mass_window")
    make1DFiducialHistograms(samples[i], fid_filenames[i], rec_filenames[i], fout, "event_type_truth", "event_type_truth","event_type", [-0.5,0.5,1.5,2.5,3.5,4.5])
    make1DFiducialHistograms(samples[i], fid_filenames[i], rec_filenames[i], fout, "event_type_truth", "event_type_truth","event_type", [-0.5,0.5,1.5,2.5,3.5,4.5], mass_window_lo, mass_window_hi, "mass_window")

    for j in range(len(variables)):
      make1DFiducialHistograms(samples[i], fid_filenames[i], rec_filenames[i], fout, var_gen[j], var_mt[j], variables[j], var_bins[j], mass_window_lo, mass_window_hi)
      
   #make tables   
  for i in range(len(variables)):
    ftable = open(outputDir + "/CorrectionFactors."+variables[i]+'.'+tag+".table", 'w')
    for j in range(len(samples)):
    #for j in range(1):
      h_cf_name = samples[j]+"/h_"+variables[i]+"_correction_factor"
      h_cf      = fout.Get(h_cf_name)

      line = samples[j]
      line += '\t& '
      for k in range(1,h_cf.GetNbinsX()+1): line += str(round(h_cf[k],3)) + ' $\pm$ '+ str(round(h_cf.GetBinError(k),3)) +'\t& '
      line += ' \n'
      
      ftable.write(line)
    ftable.close()
    
  print 'Closing output file: '
  print fout.GetPath().rstrip(':/')
  fout.Close()

  return

def make1DFiducialHistograms(sample, fid_files, rec_files, output_file, x_fid, x_rec, x_name, bins, mass_window_lo=0, mass_window_hi = 10000, tag = ''):

  print 'make1DFiducialHistograms(): processing sample:', sample, 'with variable:', x_name

  fid_chain = GetChain("tree_incl_fid", fid_files)  
  gen_chain = GetChain("tree_incl_gen", fid_files)  
  rec_chain = GetChain("inclusive",   rec_files)
        
  #Define derived histograms ------------------------------------------------------------------------------------------------------------
  event_hists = []
  derived_hists = []

  h_gen_name = "h_"+x_name+('_'+tag if tag != '' else '')+"_gen"
  h_fid_name = "h_"+x_name+('_'+tag if tag != '' else '')+"_fid"
  h_rec_name = "h_"+x_name+('_'+tag if tag != '' else '')+"_rec"
  h_rec_notfid_name = "h_"+x_name+('_'+tag if tag != '' else '')+"_rec_notfid"
  h_fid_mispaired_name = "h_"+x_name+('_'+tag if tag != '' else '')+"_fid_mispaired"
  h_rec_mispaired_name = "h_"+x_name+('_'+tag if tag != '' else '')+"_rec_mispaired"

  x_bins = array('d', bins)
  x_n = len(x_bins)-1

  h_gen = TH1F(h_gen_name, ";"+x_name+";# Generated", x_n,x_bins);event_hists.append(h_gen)
  h_fid = TH1F(h_fid_name, ";"+x_name+";# Fiducial",  x_n,x_bins);event_hists.append(h_fid)
  h_rec = TH1F(h_rec_name, ";"+x_name+";# Reco",      x_n,x_bins);event_hists.append(h_rec)
  h_rec_notfid = TH1F(h_rec_notfid_name, ";"+x_name+"; # (Reco && !Fiducial)", x_n,x_bins);event_hists.append(h_rec_notfid)
  h_fid_mispaired  = TH1F(h_fid_mispaired_name, ";"+x_name+"; # Mispaired", x_n,x_bins);event_hists.append(h_fid_mispaired)
  h_rec_mispaired  = TH1F(h_rec_mispaired_name, ";"+x_name+"; # Mispaired", x_n,x_bins);event_hists.append(h_rec_mispaired)

  h_total_efficiency		= TH1F("h_"+x_name+('_'+tag if tag != '' else '')+"_total_efficiency",    ";"+x_name+";Total Efficiency", x_n,x_bins);derived_hists.append(h_total_efficiency)
  h_fiducial_efficiency 	= TH1F("h_"+x_name+('_'+tag if tag != '' else '')+"_fiducial_efficiency", ";"+x_name+";Fiducial Efficiency", x_n,x_bins);derived_hists.append(h_fiducial_efficiency)
  h_fiducial_acceptance 	= TH1F("h_"+x_name+('_'+tag if tag != '' else '')+"_fiducial_acceptance", ";"+x_name+";Fiducial Acceptance", x_n,x_bins);derived_hists.append(h_fiducial_acceptance)
  h_fiducial_leakage    	= TH1F("h_"+x_name+('_'+tag if tag != '' else '')+"_fiducial_leakage",    ";"+x_name+";Fiducial Leakage", x_n,x_bins);derived_hists.append(h_fiducial_leakage)
  h_fiducial_mispair_fraction 	= TH1F("h_"+x_name+('_'+tag if tag != '' else '')+"_fiducial_mispair_fraction",    ";"+x_name+";Mispair Fraction", x_n,x_bins);derived_hists.append(h_fiducial_mispair_fraction)
  h_reco_mispair_fraction     	= TH1F("h_"+x_name+('_'+tag if tag != '' else '')+"_reco_mispair_fraction",    ";"+x_name+";Mispair Fraction", x_n,x_bins);derived_hists.append(h_reco_mispair_fraction)
  h_correction_factor     	= TH1F("h_"+x_name+('_'+tag if tag != '' else '')+"_correction_factor",    ";"+x_name+";Correction Factor", x_n,x_bins);derived_hists.append(h_correction_factor)
  h_dsigmadx		     	= TH1F("h_"+x_name+('_'+tag if tag != '' else '')+"_dsigmadx",    ";"+x_name+";d#sigma/dx", x_n,x_bins);derived_hists.append(h_dsigmadx)

  for hist in event_hists: hist.Sumw2()
  
  reco_mass_cut = "(m4l_constrained<"+str(mass_window_hi)+"&&m4l_constrained>"+str(mass_window_lo)+")"  
  fid_mass_cut  = "(bare_lep4_m<"+str(mass_window_hi)+"&&bare_lep4_m>"+str(mass_window_lo)+")"
  
  #Fill histograms ------------------------------------------------------------------------------------------------------------
  gen_chain.Draw(x_fid+">>"+h_gen_name, 	  "weight_fiducial")
  fid_chain.Draw(x_fid+">>"+h_fid_name, 	  fid_mass_cut+"*weight_fiducial")
  fid_chain.Draw(x_fid+">>"+h_fid_mispaired_name, fid_mass_cut+"*weight_fiducial*mispaired")
  rec_chain.Draw(x_rec+">>"+h_rec_name, 	  reco_mass_cut+"*weight")
  rec_chain.Draw(x_rec+">>"+h_rec_mispaired_name, reco_mass_cut+"*weight*mispaired")

  #suppress spurious error messages created when building index with tchain
  gROOT.ProcessLine("gErrorIgnoreLevel = kFatal;") 
  fid_chain.BuildIndex("run","event")
  gROOT.ProcessLine("gErrorIgnoreLevel = kInfo;") 
    
  for i in range(rec_chain.GetEntries()):
    rec_chain.GetEntry(i)
    if (rec_chain.m4l_constrained > mass_window_hi): continue
    if (rec_chain.m4l_constrained < mass_window_lo): continue	 
    #event reconstructed!
    
    fiducial = (fid_chain.GetEntryWithIndex(rec_chain.run, rec_chain.event) > 0)           
    if (fiducial):        
      #if (fid_chain.event_type == 4): fiducial = False
      if (fid_chain.bare_lep4_m > mass_window_hi): fiducial = False
      if (fid_chain.bare_lep4_m < mass_window_lo): fiducial = False
    
    if fiducial: continue
            
    h_rec_notfid.Fill(myvariable(x_name,'mt',rec_chain), rec_chain.weight)  

  h_total_efficiency.Divide(h_rec,h_gen,1,1,"B")
  h_fiducial_efficiency.Divide(h_rec,h_fid,1,1,"B")
  h_fiducial_acceptance.Divide(h_fid,h_gen,1,1,"B")
  h_fiducial_leakage.Divide(h_rec_notfid,h_rec,1,1,"B")
  h_fiducial_mispair_fraction.Divide(h_fid_mispaired,h_fid,1,1,"B")
  h_reco_mispair_fraction.Divide(h_rec_mispaired,h_rec,1,1,"B")
  h_correction_factor.Divide(h_fid,h_rec,1,1,"B")

  h_dsigmadx.Add(h_fid, 1/lumi)
  for i in range(x_n):
    h_dsigmadx[i+1] = h_dsigmadx[i+1] / (bins[i+1]-bins[i])
    h_dsigmadx.SetBinError(i+1, h_dsigmadx.GetBinError(i+1) / (bins[i+1]-bins[i]))
    
  if not output_file.GetDirectory(sample): output_file.mkdir(sample)
  output_file.cd(sample)
  
  for hist in derived_hists:
    hist.SetMaximum(1);   
    hist.SetMinimum(0);

  for hist in (event_hists+derived_hists): hist.Write()
  
  #to close the files
  fid_chain.Reset()
  gen_chain.Reset()
  rec_chain.Reset()
    
  return

if __name__ == '__main__' :
    main()
