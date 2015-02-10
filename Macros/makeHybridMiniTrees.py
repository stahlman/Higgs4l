"""
Make fiducial/reco combination mini-tree using official reco mini-tree and output of fiducial cutflow
Saves event which pass reco OR fiducial selection
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'January 2014'

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
 
#tag='2012'
label = 'test'; tag='test'

inputDir_rec = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/minitree_v04/mc12/";
#inputDir_rec = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/v03/MC12a/Signal/"

inputDir_fid = "/disk/userdata00/atlas_data2/stahlman/output/21022014/minitrees/";

outputDir = "/disk/userdata00/atlas_data2/stahlman/output/test/";

def main():

  #Find input ------------------------------------------------------------------------------------------------------------
  samples = []
  
  samples.append('ggH125'); 
  #samples.append('VBFH125');
  #samples.append('WH125');  
  #samples.append('ZH125');  
  #samples.append('ttH125'); 

  rec_filenames = []
  fid_filenames = []
  trees = []
  for i in range(len(samples)):
    rec_filenames.append(glob.glob(inputDir_rec+"/*"+samples[i]+"*.root"))
    print "Found", len(rec_filenames[i]),"minitree files for sample", samples[i]
    for infile in rec_filenames[i]: print '\t',infile  

    fid_filenames.append(glob.glob(inputDir_fid+"/*"+samples[i]+"*.root"))
    print "Found", len(fid_filenames[i]),"fiducial files for sample", samples[i]
    for infile in fid_filenames[i]: print '\t',infile  

    MakeMiniTrees( samples[i], rec_filenames[i], fid_filenames[i])
    
  return

def MakeMiniTrees( sample, rec_files, fid_files):
  
  print "Process sample:",sample
  
  #Set up output variables
  ####################################VARIABLES

  run   = array( 'i', [ 0 ] )
  event = array( 'i', [ 0 ] )
  lbn   = array( 'i', [ 0 ] )

  reconstructed = array( 'i', [ 0 ] )
  fiducial 	= array( 'i', [ 0 ] )
  event_type	= array( 'i', [ 0 ] )

  reco_weight  = array( 'd', [ 0 ] )
  truth_weight = array( 'd', [ 0 ] )

  reco_quad_type = array( 'i', [ 0 ] )
  reco_mispaired = array( 'i', [ 0 ] )
  
  fiducial_quad_type = array( 'i', [ 0 ] )
  fiducial_mispaired = array( 'i', [ 0 ] )
  
  #reco differential variables
  m4l_constrained 	= array( 'd', [ 0 ] )
  mZ2_unconstrained 	= array( 'd', [ 0 ] )
  pt4l_unconstrained 	= array( 'd', [ 0 ] )
  y4l_unconstrained 	= array( 'd', [ 0 ] )

  cthstr 	= array( 'd', [ 0 ] )
  phi1   	= array( 'd', [ 0 ] )
  cth1 	= array( 'd', [ 0 ] )
  cth2 	= array( 'd', [ 0 ] ) 
  phi 	= array( 'd', [ 0 ] )
    
  n_jets_fid	 	= array( 'i', [ 0 ] )
  leading_jet_pt_fid 	= array( 'd', [ 0 ] )

  #truth differential variables
  truth_m4l	  = array( 'd', [ 0 ] )
  truth_m34	  = array( 'd', [ 0 ] )
  truth_pt4l	  = array( 'd', [ 0 ] )
  truth_y4l	  = array( 'd', [ 0 ] )

  truth_cthstr 	= array( 'd', [ 0 ] )
  truth_phi1   	= array( 'd', [ 0 ] )
  truth_cth1 	= array( 'd', [ 0 ] )
  truth_cth2 	= array( 'd', [ 0 ] ) 
  truth_phi 	= array( 'd', [ 0 ] )
    
  truth_njets	   = array( 'i', [ 0 ] )
  truth_leading_jet_pt = array( 'd', [ 0 ] )

  ####################################TREES
  fout = TFile(outputDir+"/HybridMiniTree.MC12."+sample+".root","RECREATE")

  tree = TTree("tree_incl"  ,"tree_incl"  )

  tree.Branch("run",	run,	"run/I");
  tree.Branch("event",	event,	"event/I");
  tree.Branch("lbn",	lbn,	"lbn/I");
  
  tree.Branch("reconstructed",	reconstructed,	"reconstructed/I");
  tree.Branch("fiducial",	fiducial,	"fiducial/I");
  tree.Branch("event_type",     event_type,     "event_type/I")

  tree.Branch("weight_reco",     reco_weight,	"weight_reco/D");
  tree.Branch("weight_truth",    truth_weight,	"weight_truth/D");

  tree.Branch("reco_quad_type", reco_quad_type, "reco_quad_type/I")
  tree.Branch("reco_quad_type", reco_quad_type, "reco_quad_type/I")

  tree.Branch("fiducial_quad_type", fiducial_quad_type, "fiducial_quad_type/I")
  tree.Branch("fiducial_mispaired", fiducial_mispaired, "fiducial_mispaired/I")
  
  #reco differential variables
  tree.Branch("m4l_constrained",	m4l_constrained,	"m4l_constrained/D")
  tree.Branch("mZ2_unconstrained",	mZ2_unconstrained,	"mZ2_unconstrained/D")
  tree.Branch("pt4l_unconstrained",	pt4l_unconstrained,	"pt4l_unconstrained/D")
  tree.Branch("y4l_unconstrained",	y4l_unconstrained,	"y4l_unconstrained/D")

  tree.Branch("cthstr",	cthstr,	"cthstr/D")
  tree.Branch("phi1",	phi1,	"phi1/D")
  tree.Branch("cth1",	cth1,	"cth1/D")
  tree.Branch("cth2",	cth2,	"cth2/D") 
  tree.Branch("phi",	phi,	"phi/D")
    
  tree.Branch("n_jets_fid",	n_jets_fid, 	"n_jets_fid/I")
  tree.Branch("leading_jet_pt_fid",	leading_jet_pt_fid,	"leading_jet_pt_fid/D")

  #truth differential variables
  tree.Branch("truth_m4l",	truth_m4l,       "truth_m4l/D")
  tree.Branch("truth_m34",	truth_m34,       "truth_m34/D")
  tree.Branch("truth_pt4l",	truth_pt4l,      "truth_pt4l/D")
  tree.Branch("truth_y4l", 	truth_y4l,       "truth_y4l/D") 
			    
  tree.Branch("truth_cthstr",	truth_cthstr,	"truth_cthstr/D")
  tree.Branch("truth_phi1",	truth_phi1,	"truth_phi1/D")
  tree.Branch("truth_cth1",	truth_cth1,	"truth_cth1/D")
  tree.Branch("truth_cth2",	truth_cth2,	"truth_cth2/D") 
  tree.Branch("truth_phi",	truth_phi,	"truth_phi/D")
    
  tree.Branch("truth_njets",	truth_njets,	"truth_njets/I")
  tree.Branch("truth_leading_jet_pt",	truth_leading_jet_pt,	"truth_leading_jet_pt/D")

  ####################################FILL TREES

  fin_gen  = GetChain("tree_incl_gen",fid_files)
  fin_rec  = GetChain("inclusive",rec_files)
  fin_fid  = GetChain("tree_incl_fid",fid_files)

  n_gen = fin_gen.GetEntries()
  n_rec = fin_rec.GetEntries()
  n_fid = fin_fid.GetEntries()
  print "Raw Generated Events: ",n_gen
  print "Raw Fiducial Events: ",n_fid
  print "Raw Reconstructed Events: ",n_rec
  
  print "Building event dictionaries..."
  fin_rec.BuildIndex("run","event")
  fin_fid.BuildIndex("run","event")
  print "Done"

  print "Processing Events"  
  for i in range(n_gen):
    if (i % (int(n_gen/10.)) == 0): print "Event "+str(i)+"/"+str(n_gen)

    fin_gen.GetEntry(i)

    fid  = (fin_fid.GetEntryWithIndex(fin_gen.run, fin_gen.event) > 0)              
    reco = (fin_rec.GetEntryWithIndex(fin_gen.run, fin_gen.event) > 0)
    
    if (not fid and not reco): continue
    
    #sanity check          
    #if (fid and reco):
    #  if (fin_fid.weight_fiducial != fin_rec.weight_fiducial):      
    #    print "MISMATCH:", fin_fid.weight_fiducial, fin_rec.weight_fiducial
    	      
    #event level variables
    run[0]   = fin_gen.run
    event[0] = fin_gen.event
    lbn[0]   = -999

    reconstructed[0] = reco
    fiducial[0]      = fid
 
    event_type[0] = fin_gen.event_type
   
    reco_weight[0]  = fin_rec.weight     if reco else 0
    truth_weight[0] = fin_gen.weight_fiducial

    #reco_quad_type[0] = fin_rec.quad_type if reco else 0
    #reco_mispaired[0] = fin_rec.mispaired if reco else 0
    
    fiducial_quad_type[0] = fin_fid.quad_type if fid else 0
    fiducial_mispaired[0] = fin_fid.mispaired if fid else 0
    
    #reco differential variables
    m4l_constrained[0]    = fin_rec.m4l_constrained	if reco else 0
    mZ2_unconstrained[0]  = fin_rec.mZ2_unconstrained	if reco else 0
    pt4l_unconstrained[0] = fin_rec.pt4l_unconstrained	if reco else 0
    y4l_unconstrained[0]  = fin_rec.y4l_unconstrained	if reco else 0

    cthstr[0] = fin_rec.cthstr	if reco else 0
    phi1[0]   = fin_rec.phi1	if reco else 0
    cth1[0]   = fin_rec.cth1	if reco else 0
    cth2[0]   = fin_rec.cth2	if reco else 0
    phi[0]    = fin_rec.phi	if reco else 0

    n_jets_fid[0] 	   = fin_rec.n_jets_fid		if reco else 0
    leading_jet_pt_fid[0]  = fin_rec.leading_jet_pt_fid	if reco else 0

    #truth differential variables
    truth_m4l[0]  = fin_gen.higgs_m 
    truth_pt4l[0] = fin_gen.higgs_pt
    truth_y4l[0]  = fin_gen.higgs_rapidity 

    truth_m34[0]  = fin_gen.born_paired_higgslep34_m 
    
    truth_cthstr[0] = fin_gen.born_paired_higgslep4_cthstr
    truth_phi1[0]   = fin_gen.born_paired_higgslep4_phi1  
    truth_cth1[0]   = fin_gen.born_paired_higgslep4_cth1  
    truth_cth2[0]   = fin_gen.born_paired_higgslep4_cth2  
    truth_phi[0]    = fin_gen.born_paired_higgslep4_phi   

    truth_njets[0] 	     = fin_gen.n_jets_truth_fid 
    truth_leading_jet_pt [0] = fin_gen.leading_jet_pt_truth_fid
        
    tree.Fill()
    

  #SANITY CHECK
  #if len(dict_rec_evtnumbers) != 0: print "WARNING: Reco events not found in gen tree:",len(dict_rec_evtnumbers)
  #if len(dict_fid_evtnumbers) != 0: print "WARNING: Fiducial events not found in gen tree:",len(dict_fid_evtnumbers)

  tree.Write()

  print 'Closing output file: '
  print fout.GetPath().rstrip(':/')
  fout.Close()

  return


if __name__ == '__main__' :
    main()
