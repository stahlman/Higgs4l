#!/usr/bin/env python

"""
Produce systematics for correction factors associated with model dependence
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'July 2013'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

import math
#from numpy import *
from ROOT import *
#from ROOT import RooStats
#from RooStats import *
from PlotUtils import *
from AnalysisRoutines import *
from variables import *
import glob
#import re
from array import *


fid_corrections_file_name = '/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Fiducial/v10/FiducialStudy.H120_H130.root'
fid_corrections_mass_file_name = '/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Fiducial/v10/FiducialStudy.H120_H130.root'

#fid_corrections_file_name = '/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Fiducial/v09/FiducialStudy.MassWindowCheck.root'
#fid_corrections_mass_file_name = '/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Fiducial/v09/FiducialStudy.MassWindowCheck.root'

reco_minitree_dir = '/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/stahlman_minitree_v05/'
fid_minitree_dir = '/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/fiducial_minitree_v02/'

scale_pdf_weights_file_name = '/disk/userdata00/atlas_data2/stahlman/output/fromKurt/CorrectionFactorWeights_v0.root'

obsdata_file_name = '/home/stahlman/testarea/HZZllllDifferential/makeWS/results/obsData/nll_scans_pt.root'

wsinput_file_name = '/home/stahlman/testarea/HZZllllDifferential/makeWS/data/WorkspaceInputs.pt.root'

#outputDir =  "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v09/"
outputDir =  "/disk/userdata00/atlas_data2/stahlman/output/test/"

#mass variations
masses = [ '125', '126']

name_mode     = ["ggH", "VBFH", "WH", "ZH", "ttH" ] 

n_modes = len(name_mode)

#variations to apply when evaluating systematic - each set of numbers is scale factor on production mode cross section
variations = []
variation_names =[]

 #Nominal
variations.append( [1, 1, 1, 1, 1] ); variation_names.append('Nominal')

#VBFH 0.5x to 2x
variations.append( [1, 0.5, 1, 1, 1] ); variation_names.append('VBF0p5x')
variations.append( [1, 2.0, 1, 1, 1] ); variation_names.append('VBF2x')

#WH 0.5x to 2x
variations.append( [1, 1, 0.5, 1, 1] ); variation_names.append('WH0p5x')
variations.append( [1, 1, 2.0, 1, 1] ); variation_names.append('WH2x')

#ZH 0.5x to 2x
variations.append( [1, 1, 1, 0.5, 1] ); variation_names.append('ZH0p5x')
variations.append( [1, 1, 1, 2.0, 1] ); variation_names.append('ZH2x')

#ttH 0x to 6x
variations.append( [1, 1, 1, 1, 0] ); variation_names.append('ttH0x')
variations.append( [1, 1, 1, 1, 5] ); variation_names.append('ttH5x')

#Scale variations
scale_variations = [ 'RNomFNom', 'RDownFDown', 'RDownFNom','RNomFDown','RNomFUp','RUpFNom','RUpFUp' ]

pdf_variations = [ 'nominal', 'nnpd', 'mstw' ]

#observed data reweighting
obsdata_variations = [ 'nominal', 'obsdata' ]

#mass_window_lo = 118
#mass_window_hi = 129

w = 800
h = 600
hzz_label = 'H#rightarrow ZZ^{(*)}#rightarrow4l'
atlas_label_text = 'Internal'
label = "#sqrt{s} = 8 TeV #int L dt = 20.3 fb^{-1}"

def main():
   
  ROOT.gROOT.LoadMacro("AtlasStyle.C");
  ROOT.gROOT.LoadMacro("AtlasUtils.C");
  SetAtlasStyle()
   
  print "Using fiducial corrections file:"
  print '\t',fid_corrections_file_name

  fout = TFile( outputDir + 'CorrectionFactorSystematics.test.root', "RECREATE")

  for i in range(len(variables)):
  #for i in range(0,1):
    #MakeTablesAndPlots_var(i, fout)
    doCompositionStudy_var(i, fout)
    doMassStudy_var(i, fout)
    doObservedReweightingStudy(i, fout)
    #if (i!=0): #no inclusive
      #doQCDScaleStudy(i,fout)
      #doPDFStudy(i,fout)
    
  #MakeTablesAndPlots('inclusive_nomasswindow', '', 'inclusive', array('d',[0.5,1.5]), fout)
  #doCompositionStudy('inclusive_nomasswindow', '', 'inclusive', array('d',[0.5,1.5]), fout)
  #doMassStudy(       'inclusive_nomasswindow', '', 'inclusive', array('d',[0.5,1.5]), fout)
 
  #doCompositionStudy('inclusive_window110_140', '', 'inclusive', array('d',[0.5,1.5]), fout)
  #doMassStudy(       'inclusive_window110_140', '', 'inclusive', array('d',[0.5,1.5]), fout)

  print 'Closing output file: '
  print fout.GetPath().rstrip(':/')
  fout.Close()

  return

def doCompositionStudy_var(var, fout):

  var_name = variables[var]
  var_unit = var_units[var]
  var_label_reco = var_labels_reco[var]

  bins = array('d', var_bins[var])

  doCompositionStudy(var_name, var_unit, var_label_reco, bins, fout)

  return

def doCompositionStudy(var_name, var_unit, var_label_reco, bins, fout):

  n_bins = len(bins)-1 

  x_label_reco  = var_label_reco  + (' ['+var_unit+']' if var_unit != "" else "")

  n_variations = len(variations)
  
  mass = '125'
  
  print "-----------------------------------------------"
  print "Correction Factor Composition Systematic Study -",var_name
  print "-----------------------------------------------"
  
  #Load correction factors from file
  fid_correction_file = TFile( fid_corrections_file_name, "READ")
  
  h_fid_mode_125  = []
  h_reco_mode_125 = []
  h_fid_mode_126  = []
  h_reco_mode_126 = []
  for i,mode in enumerate(name_mode):    
    h_fid_mode_125.append(fid_correction_file.Get( mode +"125/h_"+var_name+"_fid") )
    h_reco_mode_125.append( fid_correction_file.Get( mode +"125/h_"+var_name+"_rec") )

    h_fid_mode_126.append(fid_correction_file.Get( mode + "126/h_"+var_name+"_fid") )
    h_reco_mode_126.append( fid_correction_file.Get( mode + "126/h_"+var_name+"_rec") )
        
  fout.cd()
  
  print "-----------------------------------------------"
  #derive correction factors for each variation
  h_correction_factor_variations = []
  for i in range(n_variations):
    h_correction_factor_variations.append( TH1F("h_correction_factor_"+var_name+"_"+variation_names[i],";"+x_label_reco+";Correction Factor",n_bins, bins) )

    h_sum_reco = TH1F("h_rec_"+var_name+"_"+variation_names[i],";"+x_label_reco+";N_{Reco}",n_bins, bins)
    h_sum_fid  = TH1F("h_fid_"+var_name+"_"+variation_names[i],";"+x_label_reco+";N_{Reco}",n_bins, bins)

    for j in range(n_modes):
      h_sum_reco.Add(h_reco_mode_125[j], 0.6*variations[i][j])
      h_sum_fid.Add( h_fid_mode_125[j],  0.6*variations[i][j])

      h_sum_reco.Add(h_reco_mode_126[j], 0.4*variations[i][j])
      h_sum_fid.Add( h_fid_mode_126[j],  0.4*variations[i][j])

    h_correction_factor_variations[i].Divide(h_sum_fid, h_sum_reco,1,1,"B")
            
    print variation_names[i].ljust(10),'\t',
    for k in range(1,n_bins+1): print round(h_correction_factor_variations[i][k],3),'\t',
    print ''
    #h_correction_factor_variations[i].Print('all')
  
  #Now determine systematics
  h_nominal = h_correction_factor_variations[0]
  h_syst    =  TH1F("h_correction_factor_comp_syst_"+var_name,";"+x_label_reco+";systematic [%]",n_bins, bins) 

  #print 'Combined \t',
  #for i in range(n_bins): print round(h_nominal[i+1],4), '\t',
  #print ''
  
  for i in range(1,n_variations):
    for j in range(n_bins):  
      syst = 0
      if (h_nominal[j+1] != 0):
        syst = ( h_correction_factor_variations[i][j+1] - h_nominal[j+1] ) / h_nominal[j+1]
      h_syst[j+1] = max(h_syst[j+1], abs(syst*100))    

  print "-----------------------------------------------"
  print "Systematics (in %)"
  print "-----------------------------------------------"
  print 'Norm,ATLAS_norm_SF_SignalComp,Sym \t',
  for i in range(n_bins): print round(h_syst[i+1],1),'\t',
  print "\n-----------------------------------------------"
  for i in range(n_bins): print '&',round(h_syst[i+1],1),'\t',
  print "\n-----------------------------------------------"
    
    
  h_syst.Write()
  for hist in h_correction_factor_variations: hist.Write()
  
  #------------------------------
  c_cf = TCanvas('CorrectionFactorVariations_'+var_name,'',w,h)
  l_cf = NewLegend(n_variations, 'tr')
    
  for i,hist in enumerate(h_correction_factor_variations):
    hist.SetMaximum(2)
    hist.SetMinimum(1.4)
   
    PlotDerived(hist, False, i, i!=0) #axes etc.  
    l_cf.AddEntry(hist, variation_names[i],'lep')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  FormatLegend(l_cf)
  l_cf.Draw()
  c_cf.Write()

  #------------------------------
      
  return

def doMassStudy_var(var, fout):

  var_name = variables[var]
  var_unit = var_units[var]
  var_label_reco = var_labels_reco[var]

  bins = array('d', var_bins[var])
  
  doMassStudy(var_name, var_unit, var_label_reco, bins, fout)

  return

def doMassStudy(var_name, var_unit, var_label_reco, bins, fout):

  n_bins = len(bins)-1 

  x_label_reco  = var_label_reco  + (' ['+var_unit+']' if var_unit != "" else "")

  n_variations = len(masses)
    
  print "-----------------------------------------------"
  print "Correction Factor Mass Systematic Study -",var_name
  print "-----------------------------------------------"
  
  #Load correction factors from file
  fid_correction_file = TFile( fid_corrections_mass_file_name, "READ")

  #nominal - extrapolate to MH=125.4 GeV using linear interpolation
  h_cf_125 = fid_correction_file.Get( 'H125/h_'+var_name+"_correction_factor")
  h_cf_126 = fid_correction_file.Get( 'H126/h_'+var_name+"_correction_factor")
  h_nominal = h_cf_125.Clone('h_cf_nominal')
  
  for i in range(n_bins):     
    h_nominal[i+1] = h_cf_125[i+1] + (0.4 * (h_cf_126[i+1] - h_cf_125[i+1]) / (126-125))

  #get variations
  h_correction_factor_variations = []
  for i in range(n_variations): 
    h_correction_factor_variations.append( fid_correction_file.Get( 'H' + masses[i]+"/h_"+var_name+"_correction_factor").Clone("h_"+var_name+"_correction_factor_H"+masses[i]))

    print 'M_H =',masses[i],'\t',
    for j in range(1,n_bins+1): print round(h_correction_factor_variations[i][j],3),'\pm',round(h_correction_factor_variations[i].GetBinError(j),3),'\t',
    print ''

  fout.cd()
    
  #Now determine systematics
  h_syst    =  TH1F("h_correction_factor_mass_syst_"+var_name,";"+x_label_reco+";systematic [%]",n_bins, bins) 

  print "-----------------------------------------------"
  print 'Nominal \t',
  for i in range(n_bins): print h_nominal[i+1], '\t',
  print ''
  print "-----------------------------------------------"
  
  for i in range(1,n_variations):
    for j in range(n_bins):  
      syst = 0
      if (h_nominal[j+1] != 0):
        syst = ( h_correction_factor_variations[i][j+1] - h_nominal[j+1] ) / h_nominal[j+1]
      h_syst[j+1] = max(h_syst[j+1], abs(syst*100))    
  #print "-----------------------------------------------"
  print "Systematics (in %)"
  print "-----------------------------------------------"
  #print 'Norm,ATLAS_norm_SF_HiggsMass,Sym \t',
  #for i in range(n_bins): print round(h_syst[i+1],1),'\t',
  #print "\n-----------------------------------------------"
  for i in range(n_bins): print '&',round(h_syst[i+1],1),'\t',
  print "\n-----------------------------------------------"

  #------------------------------
  c_cf = TCanvas('CorrectionFactorMassVariations_'+var_name,'',w,h)
  l_cf = NewLegend(n_variations, 'tr')
    
  for i,hist in enumerate(h_correction_factor_variations):
    hist.SetMaximum(2)
    hist.SetMinimum(1.4)
   
    PlotDerived(hist, False, i, i!=0) #axes etc.  
    l_cf.AddEntry(hist, masses[i],'lep')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  FormatLegend(l_cf)
  l_cf.Draw()
  c_cf.Write()
  #------------------------------
   
  h_syst.Write()
  for hist in h_correction_factor_variations: hist.Write()  
      
  return


def doQCDScaleStudy(var, fout, mass_window_lo=118, mass_window_hi=129):

  var_name = variables[var]
  var_unit = var_units[var]
  var_label_reco = var_labels_reco[var]
  v_bins = var_bins[var]

  bins = array('d', v_bins)
  n_bins = len(bins)-1 

  print 'QCD scale systematic study', var_name

  weights_file = TFile(scale_pdf_weights_file_name)
  
  reco_minitree_files = glob.glob(reco_minitree_dir+"/*H125*.root")
  reco_chain = GetChain('inclusive', reco_minitree_files)

  fid_minitree_files  = glob.glob(fid_minitree_dir +"/*H125*.root")
  fid_chain  = GetChain('tree_incl_fid', fid_minitree_files)
  gen_chain  = GetChain('tree_incl_gen', fid_minitree_files)

  #for each variation:
    #retrieve weighting histograms
    #create reco and fiducial distributions using weights
    #calculate correction factors
  #calculate systematics using envelope 
  
  #calculate reweighted reco and fiducial distributions
  reco_scale_hists = [ TH1F('h_'+var_name+'_reco_scale_'+variation, ";"+var_name+";events",n_bins,bins) for variation in scale_variations]
  fid_scale_hists  = [ TH1F('h_'+var_name+'_fid_scale_'+variation,  ";"+var_name+";events",n_bins,bins) for variation in scale_variations]
  cf_scale_hists   = [ TH1F('h_'+var_name+'_cf_scale_'+variation, ";"+var_name+";events",n_bins,bins) for variation in scale_variations]
  
  for hist in reco_scale_hists + fid_scale_hists: hist.Sumw2()

  gROOT.ProcessLine("gErrorIgnoreLevel = kFatal;") 
  gen_chain.BuildIndex("run","event")
  gROOT.ProcessLine("gErrorIgnoreLevel = kInfo;") 

  print 'Processing Reco events'  
  for i in range(reco_chain.GetEntries()):
    reco_chain.GetEntry(i)
    #print "Processing event",i
    if (reco_chain.m4l_constrained > mass_window_hi): continue
    if (reco_chain.m4l_constrained < mass_window_lo): continue	 

    if not(gen_chain.GetEntryWithIndex(reco_chain.run, reco_chain.event) > 0):
      print "ERROR: reco event not found with run,event =",reco_chain.run,reco_chain.event

    truth_var = myvariable( var_name, 'fiducial_mt',gen_chain )
    reco_var  = myvariable( var_name,'mt',reco_chain)
    
    for var_i,variation in enumerate(scale_variations):
      weight_hist = weights_file.Get(var_name+'_scale_all_'+variation)
      weight_variation = weight_hist.GetBinContent(weight_hist.GetXaxis().FindBin(truth_var))
      if (weight_variation == 0): weight_variation = 1.0;

      reco_scale_hists[var_i].Fill( reco_var, reco_chain.weight*weight_variation)


  print 'Processing Fiducial events'  
  for i in range(fid_chain.GetEntries()):
    fid_chain.GetEntry(i)
    if (fid_chain.bare_lep4_m > mass_window_hi): continue
    if (fid_chain.bare_lep4_m < mass_window_lo): continue

    truth_var = myvariable( var_name, 'fiducial_mt',fid_chain )

    for var_i,variation in enumerate(scale_variations):
      weight_hist = weights_file.Get(var_name+'_scale_all_'+variation)
      weight_variation = weight_hist.GetBinContent(weight_hist.GetXaxis().FindBin(truth_var))
      if (weight_variation == 0): weight_variation = 1.0;

      fid_scale_hists[var_i].Fill( truth_var, fid_chain.weight_fiducial*weight_variation)

  #calculate correction factors
  for var_i,variation in enumerate(scale_variations):
      cf_scale_hists[var_i].Divide(fid_scale_hists[var_i],reco_scale_hists[var_i],1,1,"B")

  #now calculate systematics
  h_nominal = cf_scale_hists[0]
  h_syst    =  TH1F('h_'+var_name+'_cf_scale_syst',";"+var_name+";systematic [%]",n_bins, bins) 

  print "-----------------------------------------------"
  print 'Nominal \t',
  for i in range(n_bins): print h_nominal[i+1], '\t',
  print ''
  print "-----------------------------------------------"
  
  for i in range(1,len(cf_scale_hists)):
    for j in range(n_bins):  
      syst = 0
      if (h_nominal[j+1] != 0):
        syst = ( cf_scale_hists[i][j+1] - h_nominal[j+1] ) / h_nominal[j+1]
      h_syst[j+1] = max(h_syst[j+1], abs(syst*100))    
  #print "-----------------------------------------------"
  print "Systematics (in %)"
  print "-----------------------------------------------"
  #print 'Norm,ATLAS_norm_SF_HiggsMass,Sym \t',
  #for i in range(n_bins): print round(h_syst[i+1],1),'\t',
  #print "\n-----------------------------------------------"
  for i in range(n_bins): print '&',round(h_syst[i+1],1),'\t',
  print "\n-----------------------------------------------"
    
  fout.cd()
  for hist in cf_scale_hists+reco_scale_hists+fid_scale_hists: hist.Write()
  h_syst.Write()
      
  return
  
def doPDFStudy(var, fout, mass_window_lo=118, mass_window_hi=129):

  var_name = variables[var]
  var_unit = var_units[var]
  var_label_reco = var_labels_reco[var]
  v_bins = var_bins[var]

  bins = array('d', v_bins)
  n_bins = len(bins)-1 

  print 'PDF systematic study', var_name

  weights_file = TFile(scale_pdf_weights_file_name)
  
  reco_minitree_files = glob.glob(reco_minitree_dir+"/*H125*.root")
  reco_chain = GetChain('inclusive', reco_minitree_files)

  fid_minitree_files  = glob.glob(fid_minitree_dir +"/*H125*.root")
  fid_chain  = GetChain('tree_incl_fid', fid_minitree_files)
  gen_chain  = GetChain('tree_incl_gen', fid_minitree_files)

  #for each variation:
    #retrieve weighting histograms
    #create reco and fiducial distributions using weights
    #calculate correction factors
  #calculate systematics using envelope 
  
  #calculate reweighted reco and fiducial distributions
  reco_hists = [ TH1F('h_'+var_name+'_reco_pdf_'+variation, ";"+var_name+";events",n_bins,bins) for variation in pdf_variations]
  fid_hists  = [ TH1F('h_'+var_name+'_fid_pdf_'+variation,  ";"+var_name+";events",n_bins,bins) for variation in pdf_variations]
  cf_hists   = [ TH1F('h_'+var_name+'_cf_pdf_'+variation,   ";"+var_name+";events",n_bins,bins) for variation in pdf_variations]
  
  for hist in reco_hists + fid_hists: hist.Sumw2()

  gROOT.ProcessLine("gErrorIgnoreLevel = kFatal;") 
  gen_chain.BuildIndex("run","event")
  gROOT.ProcessLine("gErrorIgnoreLevel = kInfo;") 
    
  print 'Processing Reco events'  
  for i in range(reco_chain.GetEntries()):
    reco_chain.GetEntry(i)
    if (reco_chain.m4l_constrained > mass_window_hi): continue
    if (reco_chain.m4l_constrained < mass_window_lo): continue	 

    if not(gen_chain.GetEntryWithIndex(reco_chain.run, reco_chain.event) > 0):
      print "ERROR: reco event not found with run,event =",reco_chain.run,reco_chain.event

    truth_var = myvariable( var_name, 'fiducial_mt',gen_chain )
    reco_var  = myvariable( var_name,'mt',reco_chain)
    
    for var_i,variation in enumerate(pdf_variations):
      weight_variation = 1.0
      if (variation != 'nominal'):
        weight_hist = weights_file.Get(var_name+'_pdf_all_weight_'+variation)        
	weight_variation = weight_hist.GetBinContent(weight_hist.GetXaxis().FindBin(truth_var))
        if (weight_variation == 0): weight_variation = 1.0;

      reco_hists[var_i].Fill( reco_var, reco_chain.weight*weight_variation)


  print 'Processing Fiducial events'  
  for i in range(fid_chain.GetEntries()):
    fid_chain.GetEntry(i)
    if (fid_chain.dressed_lep4_m > mass_window_hi): continue
    if (fid_chain.dressed_lep4_m < mass_window_lo): continue

    truth_var = myvariable( var_name, 'fiducial_mt',fid_chain )

    for var_i,variation in enumerate(pdf_variations):
      weight_variation = 1.0
      if (variation != 'nominal'):
        weight_hist = weights_file.Get(var_name+'_pdf_all_weight_'+variation)
        weight_variation = weight_hist.GetBinContent(weight_hist.GetXaxis().FindBin(truth_var))
        if (weight_variation == 0): weight_variation = 1.0;

      fid_hists[var_i].Fill( truth_var, fid_chain.weight_fiducial*weight_variation)

  #calculate correction factors
  for var_i,variation in enumerate(pdf_variations):
      cf_hists[var_i].Divide(fid_hists[var_i],reco_hists[var_i],1,1,"B")

  #now calculate systematics
  h_nominal = cf_hists[0]
  h_syst    =  TH1F('h_'+var_name+'_cf_pdf_syst',";"+var_name+";systematic [%]",n_bins, bins) 

  print "-----------------------------------------------"
  print 'Nominal \t',
  for i in range(n_bins): print h_nominal[i+1], '\t',
  print ''
  print "-----------------------------------------------"  
  for i in range(1,len(cf_hists)):
    for j in range(n_bins):  
      syst = 0
      if (h_nominal[j+1] != 0):
        syst = ( cf_hists[i][j+1] - h_nominal[j+1] ) / h_nominal[j+1]
      h_syst[j+1] = max(h_syst[j+1], abs(syst*100))    
  #print "-----------------------------------------------"
  print "Systematics (in %)"
  print "-----------------------------------------------"
  #print 'Norm,ATLAS_norm_SF_HiggsMass,Sym \t',
  #for i in range(n_bins): print round(h_syst[i+1],1),'\t',
  #print "\n-----------------------------------------------"
  for i in range(n_bins): print '&',round(h_syst[i+1],3),'\t',
  print "\n-----------------------------------------------"
    
  fout.cd()
  for hist in cf_hists+reco_hists+fid_hists: hist.Write()
  h_syst.Write()
      
  return


def doObservedReweightingStudy(var, fout, mass_window_lo=118, mass_window_hi=129):

  var_name = variables[var]
  var_unit = var_units[var]
  var_label_reco = var_labels_reco[var]
  v_bins = var_bins[var]

  bins = array('d', v_bins)
  n_bins = len(bins)-1 

  print 'Observed Reweighting systematic study', var_name

  obsdata_file = TFile(obsdata_file_name)  
  wsinput_file = TFile(wsinput_file_name)
 
  reco_minitree_files = glob.glob(reco_minitree_dir+"/*H125*.root")
  reco_chain = GetChain('inclusive', reco_minitree_files)

  fid_minitree_files  = glob.glob(fid_minitree_dir +"/*H125*.root")
  fid_chain  = GetChain('tree_incl_fid', fid_minitree_files)
  gen_chain  = GetChain('tree_incl_gen', fid_minitree_files)
    
  #for each variation:
    #retrieve weighting histograms
    #create reco and fiducial distributions using weights
    #calculate correction factors
  #calculate systematics using envelope 
  
  #calculate reweighted reco and fiducial distributions
  reco_hists = [ TH1F('h_'+var_name+'_reco_obsdata_'+variation, ";"+var_name+";events",n_bins,bins) for variation in obsdata_variations]
  fid_hists  = [ TH1F('h_'+var_name+'_fid_obsdata_'+variation,  ";"+var_name+";events",n_bins,bins) for variation in obsdata_variations]
  cf_hists   = [ TH1F('h_'+var_name+'_cf_obsdata_'+variation,   ";"+var_name+";events",n_bins,bins) for variation in obsdata_variations]
  
  for hist in reco_hists + fid_hists: hist.Sumw2()

  #calculate weight histogram
  g_obsdata_pt = obsdata_file.Get("pt_XS")
  #g_obsdata_pt.Print('all')
  h_powheg_pt  = wsinput_file.Get("hists/h_pt_dsigmadxPowheg_nominal")
  #h_powheg_pt.Print('all')
  
  h_pt_weights = h_powheg_pt.Clone('h_pt_weights')
  h_pt_weights.Reset()
  h_pt_weights[0] = 1.0
  h_pt_weights[5] = 1.0  
  print 'pT weights:'
  for i in range(4):
    h_pt_weights[i+1] = g_obsdata_pt.GetY()[i] / h_powheg_pt[i+1]
    print h_pt_weights[i+1],
  print ''
    
  gROOT.ProcessLine("gErrorIgnoreLevel = kFatal;") 
  gen_chain.BuildIndex("run","event")
  gROOT.ProcessLine("gErrorIgnoreLevel = kInfo;") 
    
  print 'Processing Reco events'  
  for i in range(reco_chain.GetEntries()):
    reco_chain.GetEntry(i)
    if (reco_chain.m4l_constrained > mass_window_hi): continue
    if (reco_chain.m4l_constrained < mass_window_lo): continue	 

    if not(gen_chain.GetEntryWithIndex(reco_chain.run, reco_chain.event) > 0):
      print "ERROR: reco event not found with run,event =",reco_chain.run,reco_chain.event

    #truth_var = myvariable( var_name, 'fiducial_mt',gen_chain )
    reco_var  = myvariable( var_name,'mt',reco_chain)
    
    for var_i,variation in enumerate(obsdata_variations):
      weight_variation = 1.0
      if (variation != 'nominal'):
	weight_variation = h_pt_weights.GetBinContent(h_pt_weights.GetXaxis().FindBin(gen_chain.higgs_pt))
        if (weight_variation == 0): weight_variation = 1.0;

      reco_hists[var_i].Fill( reco_var, reco_chain.weight*weight_variation)


  print 'Processing Fiducial events'  
  for i in range(fid_chain.GetEntries()):
    fid_chain.GetEntry(i)
    if (fid_chain.dressed_lep4_m > mass_window_hi): continue
    if (fid_chain.dressed_lep4_m < mass_window_lo): continue

    truth_var = myvariable( var_name, 'fiducial_mt',fid_chain )

    for var_i,variation in enumerate(obsdata_variations):
      weight_variation = 1.0
      if (variation != 'nominal'):
	weight_variation = h_pt_weights.GetBinContent(h_pt_weights.GetXaxis().FindBin(fid_chain.higgs_pt))
        if (weight_variation == 0): weight_variation = 1.0;

      fid_hists[var_i].Fill( truth_var, fid_chain.weight_fiducial*weight_variation)

  #calculate correction factors
  for var_i,variation in enumerate(obsdata_variations):
      cf_hists[var_i].Divide(fid_hists[var_i],reco_hists[var_i],1,1,"B")

  #now calculate systematics
  h_nominal = cf_hists[0]
  h_syst    =  TH1F('h_'+var_name+'_cf_obsdata_syst',";"+var_name+";systematic [%]",n_bins, bins) 

  for i in range(1,len(cf_hists)):
    for j in range(n_bins):  
      syst = 0
      if (h_nominal[j+1] != 0):
        syst = ( cf_hists[i][j+1] - h_nominal[j+1] ) / h_nominal[j+1]
      h_syst[j+1] = max(h_syst[j+1], abs(syst*100))    

  #print info
  print "-----------------------------------------------"
  for var_i,variation in enumerate(obsdata_variations):
    print variation,'\t',
    for i in range(n_bins): print cf_hists[var_i][i+1], '\t',
    print ''
  print "-----------------------------------------------"  
  print "Systematics (in %)"
  print "-----------------------------------------------"
  for i in range(n_bins): print '&',round(h_syst[i+1],3),'\t',
  print "\n-----------------------------------------------"
    
  fout.cd()
  for hist in cf_hists+reco_hists+fid_hists: hist.Write()
  h_syst.Write()
      
  return
  
  
def MakeTablesAndPlots_var(var, fout):

  var_name = variables[var]
  var_unit = var_units[var]
  var_label_reco = var_labels_reco[var]

  bins = array('d', var_bins[var])

  x_label_reco  = var_label_reco  + (' ['+var_unit+']' if var_unit != "" else "")
  
  MakeTablesAndPlots(var_name, var_unit, x_label_reco, bins, fout)
  
  return
  
def MakeTablesAndPlots(var_name, var_unit, var_label_reco, bins, fout):

  n_bins = len(bins)-1

  #Load correction factors from file
  fid_correction_file = TFile( fid_corrections_file_name, "READ")
  
  #------------------------------
  h_125_combined = fid_correction_file.Get( "H125/h_"+var_name+"_correction_factor")
  h_126_combined = fid_correction_file.Get( "H126/h_"+var_name+"_correction_factor")
  
  h_125p4_combined = h_125_combined.Clone( "H125p4_"+var_name+"_correction_factor" )
  h_125p4_combined.Reset()
  h_125p4_combined.Add(h_125_combined,0.6)
  h_125p4_combined.Add(h_126_combined,0.4)  
    
  h_cf_mode  = []
  for i,mode in enumerate(name_mode):    
    
    h_125 = fid_correction_file.Get( mode + "125/h_"+var_name+"_correction_factor")
    h_126 = fid_correction_file.Get( mode + "126/h_"+var_name+"_correction_factor")
    h_nom = h_125.Clone('h_nom')
    h_nom.Reset()
    h_nom.Add(h_125,0.6)
    h_nom.Add(h_126,0.4)
    
    h_cf_mode.append( h_nom )

  print var_name, '\t',
  for i in range(n_bins): print 'bin',i,'\t',
  print '\n------------------------------------------------------------'

  for i,mode in enumerate(name_mode): 
    print mode, '\t',
    for j in range(n_bins):    
      print ('& '+str(round(h_cf_mode[i][j+1],3))+' $\pm$ '+str(round(h_cf_mode[i].GetBinError(j+1),3))).ljust(15),'\t',
    print ' \\\\ '

  print '\\hline \nCombined',
  for j in range(n_bins): print ('& '+str(round(h_125p4_combined[j+1],3))+' $\pm$ '+str(round(h_125p4_combined.GetBinError(j+1),3))).ljust(15),'\t', 
  print '\\\\  \n \\hline'

  print '------------------------------------------------------------'
  
  fout.cd()
  
  #------------------------------
  c_cf_mode = TCanvas('CorrectionFactorModes_'+var_name,'',w,h)
  l_cf_mode = NewLegend(n_modes, 'trn')
  
  MaxMin(h_cf_mode)
  
  for i,hist in enumerate(h_cf_mode):    
    hist.GetXaxis().SetTitle(var_label_reco)
    
    PlotDerived(hist, False, i, i!=0) #axes etc.  
    l_cf_mode.AddEntry(hist, name_mode[i],'lep')

  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  ADD_LABEL(label, 0.76)
  FormatLegend(l_cf_mode)
  l_cf_mode.Draw()
  c_cf_mode.Write()
  
  #------------------------------

  return  
 
if __name__ == '__main__' :
    main()

  
