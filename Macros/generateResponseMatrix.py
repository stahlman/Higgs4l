"""
Make Response from SM combination
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'October 2013'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

import math
from ROOT import *
from PlotUtils import *
from AnalysisRoutines import *
import glob
import re
from variables import *

lumi = 20.277
mass_window_hi = 129
mass_window_lo = 118

def main():

  ROOT.gROOT.LoadMacro("AtlasStyle.C");
  ROOT.gROOT.LoadMacro("AtlasUtils.C");
  SetAtlasStyle()

  #tag='2012'
  label = 'test'; tag='test'

  inputDir_rec = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/stahlman_minitree_v05/";
  #inputDir_rec = "/disk/userdata00/atlas_data2/stahlman/output/04022014/minitrees/";

  inputDir_fid = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/fiducial_minitree_v02/";

  outputFile = "/disk/userdata00/atlas_data2/stahlman/output/test/Response.MC.test.root";

  #Find input ------------------------------------------------------------------------------------------------------------
  samples = []
  xsection_times_BR = []
  
  branching_ratio = 0.000276 #BR for H->4l; l=e,mu, tau
  
  samples.append('ggH125'); 	xsection_times_BR.append(19.27*1000*branching_ratio)
  samples.append('VBFH125'); 	xsection_times_BR.append(1.578*1000*branching_ratio)
  samples.append('WH125');     xsection_times_BR.append(0.7046*1000*branching_ratio)
  samples.append('ZH125');     xsection_times_BR.append(0.4153*1000*branching_ratio)
  samples.append('ttH125');    xsection_times_BR.append(0.1293*1000*branching_ratio)

  rec_filenames = []
  fid_filenames = []
  response_matrices = []
  for i in range(len(samples)):
    rec_filenames.append(glob.glob(inputDir_rec+"/*"+samples[i]+"*.root"))
    print "Found", len(rec_filenames[i]),"minitree files for sample", samples[i]
    for infile in rec_filenames[i]: print '\t',infile  

    fid_filenames.append(glob.glob(inputDir_fid+"/*"+samples[i]+"*.root"))
    print "Found", len(fid_filenames[i]),"fiducial files for sample", samples[i]
    for infile in fid_filenames[i]: print '\t',infile  

    ###derive matrices
    response_matrices += ResponseMatrices( samples[i], rec_filenames[i], fid_filenames[i], xsection_times_BR[i])
  
  ###sum matrices
  for i in range(len(variables)):    
    n_bins = len(var_bins[i]) - 1
    a_bins = array('d',var_bins[i])
    x_label_reco  = var_labels_reco[i]  + (' ['+var_units[i]+']' if var_units[i] != "" else "")
    x_label_truth = var_labels_truth[i] + (' ['+var_units[i]+']' if var_units[i] != "" else "")
    h_rec = TH1F('rec_'+variables[i],  ';'+x_label_reco +';rec',   n_bins, a_bins)
    h_gen = TH1F('gen_'+variables[i],  ';'+x_label_truth+';gen',  n_bins, a_bins)
    h_fid = TH1F('fid_'+variables[i],  ';'+x_label_truth+';fid',  n_bins, a_bins)

    response_tot = RooUnfoldResponse(h_rec, h_gen, 'tot_response_H125_'+variables[i], 'tot_response_H215_'+variables[i])    
    response_fid = RooUnfoldResponse(h_rec, h_fid, 'fid_response_H125_'+variables[i], 'fid_response_H125_'+variables[i])
  
    for matrix in response_matrices:
      tokens =  matrix.GetName().split('_')
      if len(tokens) < 4: print "Warning - Messed up name: ", tokens
      if (tokens[3]!=variables[i]): continue
      if (tokens[0]=='tot'): response_tot.Add(matrix)
      if (tokens[0]=='fid'): response_fid.Add(matrix)
    
    response_matrices.append(response_tot)    
    response_matrices.append(response_fid)
  
  ### save result
  fout = TFile(outputFile,"RECREATE")

  for matrix in response_matrices: matrix.Write()

  print 'Closing output file: '
  print fout.GetPath().rstrip(':/')
  fout.Close()


def ResponseMatrices( sample, rec_files, fid_files, x_section_times_BR):
  
  print "Process sample:",sample
  
  fin_rec  = GetChain("inclusive",rec_files)
  fin_gen  = GetChain("tree_incl_gen",fid_files)
  fin_fid  = GetChain("tree_incl_fid",fid_files)

  n_gen = fin_gen.GetEntries()
  n_rec = fin_rec.GetEntries()
  n_fid = fin_fid.GetEntries()
  print "Raw Generated Events: ",n_gen
  print "Raw Fiducial Events: ",n_fid
  print "Raw Reconstructed Events: ",n_rec
  
  print "Building event dictionaries..."
  fin_fid.BuildIndex("event")
  fin_rec.BuildIndex("event")
  print "Done"
  
  response_tot = []
  response_fid = []

  n_vars = len(variables)
  
  print "Setting up Response Matrices"
  for i in range(n_vars):    
    x_label_reco  = var_labels_reco[i]  + (' ['+var_units[i]+']' if var_units[i] != "" else "")
    x_label_truth = var_labels_truth[i] + (' ['+var_units[i]+']' if var_units[i] != "" else "")
    
    h_rec = TH1F('rec_'+variables[i],  ';'+x_label_reco +';rec',   len(var_bins[i]) - 1, array('d',var_bins[i]))
    h_gen = TH1F('gen_'+variables[i],  ';'+x_label_truth+';gen',  len(var_bins[i]) - 1, array('d',var_bins[i]))
    h_fid = TH1F('fid_'+variables[i],  ';'+x_label_truth+';fid',  len(var_bins[i]) - 1, array('d',var_bins[i]))

    response_tot.append(RooUnfoldResponse(h_rec, h_gen, 'tot_response_'+sample+'_'+variables[i], 'tot_response_'+sample+'_'+variables[i]))
    response_fid.append(RooUnfoldResponse(h_rec, h_fid, 'fid_response_'+sample+'_'+variables[i], 'fid_response_'+sample+'_'+variables[i]))
  
  print "Processing Events"  
  for i in range(n_gen):
    if (i % (int(n_gen/10.)) == 0): print "Event "+str(i)+"/"+str(n_gen)
    fin_gen.GetEntry(i)

    reco = True
    found = fin_rec.GetEntryWithIndex(fin_gen.event)           
    if (found > 0):
      if (fin_rec.m4l_constrained > mass_window_hi): reco = False
      if (fin_rec.m4l_constrained < mass_window_lo): reco = False
    else:
      reco = False

    fiducial = True
    found = fin_fid.GetEntryWithIndex(fin_gen.event)           
    if (found > 0):        
      if (fin_fid.event_type_truth >= 4): fiducial = False
      if (fin_fid.bare_lep4_m > mass_window_hi): fiducial = False
      if (fin_fid.bare_lep4_m < mass_window_lo): fiducial = False
    else:
      fiducial = False

    for j in range(n_vars):    
      if (reco):    
	response_tot[j].Fill(myvariable(variables[j], "mt",fin_rec), myvariable(variables[j], "fiducial_mt",fin_gen), fin_rec.weight)
	if (fiducial):
	  response_fid[j].Fill(myvariable(variables[j], "mt",fin_rec), myvariable(variables[j], "fiducial_mt",fin_fid), fin_rec.weight)
	else:
	  #Leakage - treat as fake background for now
	  response_fid[j].Fake(myvariable(variables[j], "mt",fin_rec), fin_rec.weight)
      else:
        response_tot[j].Miss( myvariable(variables[j], "fiducial_mt",fin_gen), fin_gen.weight_fiducial)
        if (fiducial):
	  response_fid[j].Miss( myvariable(variables[j], "fiducial_mt",fin_fid), fin_gen.weight_fiducial)

  print "Normalized Generated Events: ",response_tot[0].Htruth().Integral(0,response_tot[0].Htruth().GetNbinsX()+1)
  print "Normalized Fiducial Events: ", response_fid[0].Htruth().Integral(0,response_fid[0].Htruth().GetNbinsX()+1)
  print "Normalized Reconstructed Events: ",response_tot[0].Hmeasured().Integral(0,response_tot[0].Hmeasured().GetNbinsX()+1)

  return response_tot + response_fid


if __name__ == '__main__' :
    main()
