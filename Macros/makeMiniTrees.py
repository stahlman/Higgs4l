#!/usr/bin/env python

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'Jan 2013'

#####################################################################
# There are 3 ways to specify input for this script:
#
# 1) Specify single input file using --file
#
# 2) Specify input directory using --dir and minitrees are produced for every subdirectory
#
# 3) Specify input directory using --dir and keys using --keys, minitrees are produced for every key
#
# Note that script expects root directories to follow structure: files = input_dir + '/*'+key+'*/*/*.root'
#####################################################################

#---------------------------------------------------------------------------
import os, sys, string, commands, math
from datetime import datetime
from pprint import pprint
import math
from ROOT import *
from array import array
import glob
from argparse import ArgumentParser

from Histmaker_class import Histmaker
 
lumi = 20.277
tree_name = 'output'

#-----------------------------------------------------------------------------------------------------        
def ParseOptions() :

    parser = ArgumentParser(usage='python makeMiniTrees.py --dir dirname --key key [ --data ] ' \
            '--out [ ouputdir ] ' )
    
    parser.add_argument('--file', dest='input_file', default=None, 
            help='Input file (one file only)' )

    parser.add_argument('--dir', dest='input_dir', default=None,
            help='Path to input directory to be used with keys' )

    parser.add_argument('--keys', dest='input_keys', nargs="+" , default=None, 
            help='Keys to match (one key per output file)' )    

    parser.add_argument('--out', dest='output_dir', default=None,
            help='Path to output directory' )       

    parser.add_argument('--tag', dest='output_tag', default=None,
            help='Output tag' )    

    parser.add_argument('--data', action='store_true', dest='isData', default=False,
            help='isData' )    

    parser.add_argument('--syst', action='store_true', dest='addSystematics', default=False,
            help='Add Systematics variables' )    
    
    options = parser.parse_args()

    return options


#-----------------------------------------------------------------------------------------------------        
#-----------------------------------------------------------------------------------------------------        
def main(options) :

    print 'Input options : '
    print vars(options)
    makeMiniTrees(**vars(options))

#-----------------------------------------------------------------------------------------------------         
def makeMiniTrees(**kwargs) :

   input_file     = kwargs.get('input_file',None)
   input_dir      = kwargs.get('input_dir', None)
   input_keys     = kwargs.get('input_keys', None)
   output_dir     = kwargs.get('output_dir',input_dir)
   output_tag     = kwargs.get('output_tag','')
   isData         = kwargs.get('isData',    False)
   addSystematics = kwargs.get('addSystematics',  False)

   if output_dir is None: output_dir = input_dir + '/minitrees/'
   if not os.path.exists(output_dir): os.makedirs(output_dir)
       
   if input_file is not None:
     makeTrees(input_file, input_dir, input_keys, output_dir, output_tag, isData, addSystematics)
     return
   
   if input_keys is None:
     input_keys = os.walk(input_dir).next()[1]    
   
   for index, key in enumerate(input_keys):
     print "Processing key",index,'/',len(input_keys),':', key
     makeTrees(input_file, input_dir, key, output_dir, output_tag, isData, addSystematics)
   
   return
 
def makeTrees(input_file, input_dir, input_key, output_dir, output_tag, isData, addSystematics): 
     
   ####################################INITIALIZATION OF EXTERNAL TOOLS
   hm=Histmaker()
   if isData:
       goodrunslist = hm.LoadGRL('../SFrame/config/GRL/data12_8TeV.periodAllYear_DetStatus-v61-pro14-02_DQDefects-00-01-00_PHYS_StandardGRL_All_Good.xml')

   ####################################INPUTFILES
   print input_file
   
   if input_file != None:
     file_key = input_file
   else:  
     file_key = input_dir + '/*'+input_key+'*/*/*.root'
   fin = TChain(tree_name)
   hm.GetFilesAndInitialCounts(fin,file_key,isData)

   ####################################COUNTERS

   numberevents_all=0
   numberevents_passed = [0,0,0,0,0]


   ####################################VARIABLES

   run = array( 'i', [ 0 ] )
   event = array( 'i', [ 0 ] )
   event_type_truth = array( 'i', [ 0 ] )
   lbn = array( 'i', [ 0 ] )
   quad_type = array( 'i', [ 0 ] )
   
   m4l_unconstrained = array( 'd', [ 0 ] )
   m4lerr_unconstrained = array( 'd', [ 0 ] )
   mZ1_unconstrained = array( 'd', [ 0 ] )
   mZ2_unconstrained = array( 'd', [ 0 ] )
   m4l_fsr = array( 'd', [ 0 ] )
   m4lerr_fsr = array( 'd', [ 0 ] )
   mZ1_fsr = array( 'd', [ 0 ] ) 
   mZ2_fsr = array( 'd', [ 0 ] ) 
   m4l_constrained = array( 'd', [ 0 ] )
   m4lerr_constrained = array( 'd', [ 0 ] )
   mZ1_constrained = array( 'd', [ 0 ] )
   mZ2_constrained = array( 'd', [ 0 ] ) 

   weight = array( 'd', [ 0 ] )
   weight_corr = array( 'd', [ 0 ] )
   weight_lumi = array( 'd', [ 0 ] )
   weight_sampleoverlap = array( 'd', [ 0 ] )
   weight_fiducial = array( 'd', [ 0 ] )

   weight_higgspt = array( 'd', [ 0 ] )
   weight_vertex = array( 'd', [ 0 ] )
   weight_pileup = array( 'd', [ 0 ] )

   #weight_higgspt_gen  = array( 'd', [ 0 ] )
   #weight_higgspt_reco = array( 'd', [ 0 ] )

   cthstr = array( 'd', [ 0 ] )
   phi1 = array( 'd', [ 0 ] )
   cth1 = array( 'd', [ 0 ] )
   cth2 = array( 'd', [ 0 ] ) 
   phi = array( 'd', [ 0 ] )

   pt4l_unconstrained = array( 'd', [ 0 ] )
   pt4l_fsr = array( 'd', [ 0 ] )
   pt4l_constrained = array( 'd', [ 0 ] )
   y4l_unconstrained = array( 'd', [ 0 ] )
   y4l_fsr = array( 'd', [ 0 ] )
   y4l_constrained = array( 'd', [ 0 ] )
   eta4l_unconstrained = array( 'd', [ 0 ] )
   eta4l_fsr = array( 'd', [ 0 ] )
   eta4l_constrained = array( 'd', [ 0 ] )

   Z1_lepplus_pt = array( 'd', [ 0 ] )	
   Z1_lepminus_pt = array( 'd', [ 0 ] )	
   Z2_lepplus_pt = array( 'd', [ 0 ] )	
   Z2_lepminus_pt = array( 'd', [ 0 ] )	
   Z1_lepplus_eta = array( 'd', [ 0 ] )	
   Z1_lepminus_eta = array( 'd', [ 0 ] )
   Z2_lepplus_eta = array( 'd', [ 0 ] )	
   Z2_lepminus_eta = array( 'd', [ 0 ] )
   Z1_lepplus_phi = array( 'd', [ 0 ] )	
   Z1_lepminus_phi = array( 'd', [ 0 ] )
   Z2_lepplus_phi = array( 'd', [ 0 ] )	
   Z2_lepminus_phi = array( 'd', [ 0 ] )
   Z1_lepplus_m = array( 'd', [ 0 ] )	
   Z1_lepminus_m = array( 'd', [ 0 ] )	
   Z2_lepplus_m = array( 'd', [ 0 ] )	
   Z2_lepminus_m = array( 'd', [ 0 ] )	
   Z1_lepplus_cov_mom = array( 'd', [ 0 ] )
   Z1_lepminus_cov_mom = array( 'd', [ 0 ] )
   Z2_lepplus_cov_mom = array( 'd', [ 0 ] )
   Z2_lepminus_cov_mom = array( 'd', [ 0 ] )

   n_jets = array( 'i', [ 0 ] )		
   dijet_invmass = array( 'd', [ 0 ] )	
   dijet_deltaeta = array( 'd', [ 0 ] )	
   leading_jet_pt = array( 'd', [ 0 ] )	
   leading_jet_eta = array( 'd', [ 0 ] )
   subleading_jet_pt = array( 'd', [ 0 ] )

   n_jets_fid = array( 'i', [ 0 ] )		
   leading_jet_pt_fid = array( 'd', [ 0 ] )	

   KD_discriminant = array( 'd', [ 0 ] )
   BDT_discriminant = array( 'd', [ 0 ] )

   pt4l_truth_born = array( 'd', [ 0 ] )
   y4l_truth_born = array( 'd', [ 0 ] ) 
   eta4l_truth_born = array( 'd', [ 0 ] )
   m4l_truth_born = array( 'd', [ 0 ] ) 
 
   m4l_truth_matched_born = array( 'd', [ 0 ] )	
   mZ1_truth_matched_born = array( 'd', [ 0 ] )	
   mZ2_truth_matched_born = array( 'd', [ 0 ] )	
   m4l_truth_matched_bare = array( 'd', [ 0 ] )	
   mZ1_truth_matched_bare = array( 'd', [ 0 ] )	
   mZ2_truth_matched_bare = array( 'd', [ 0 ] )	
   m4l_truth_matched_dressed = array( 'd', [ 0 ] )
   mZ1_truth_matched_dressed = array( 'd', [ 0 ] )
   mZ2_truth_matched_dressed = array( 'd', [ 0 ] )

   Z1_lepplus_pt_truth_born = array( 'd', [ 0 ] )
   Z1_lepminus_pt_truth_born = array( 'd', [ 0 ] )
   Z2_lepplus_pt_truth_born = array( 'd', [ 0 ] )
   Z2_lepminus_pt_truth_born = array( 'd', [ 0 ] )
   Z1_lepplus_eta_truth_born = array( 'd', [ 0 ] )
   Z1_lepminus_eta_truth_born = array( 'd', [ 0 ] )
   Z2_lepplus_eta_truth_born = array( 'd', [ 0 ] )
   Z2_lepminus_eta_truth_born = array( 'd', [ 0 ] )
   Z1_lepplus_phi_truth_born = array( 'd', [ 0 ] )
   Z1_lepminus_phi_truth_born = array( 'd', [ 0 ] )
   Z2_lepplus_phi_truth_born = array( 'd', [ 0 ] )
   Z2_lepminus_phi_truth_born = array( 'd', [ 0 ] )
   Z1_lepplus_m_truth_born = array( 'd', [ 0 ] )
   Z1_lepminus_m_truth_born = array( 'd', [ 0 ] )
   Z2_lepplus_m_truth_born = array( 'd', [ 0 ] )
   Z2_lepminus_m_truth_born = array( 'd', [ 0 ] )

   n_jets_truth_bare = array( 'i', [ 0 ] )	
   leading_jet_pt_truth_bare = array( 'd', [ 0 ] )

   weight_sf = array( 'd', [ 0 ] )
   weight_sf1 = array( 'd', [ 0 ] )
   weight_sf2 = array( 'd', [ 0 ] )
   weight_sf3 = array( 'd', [ 0 ] )
   weight_sf4 = array( 'd', [ 0 ] )
   trigger_sf = array( 'd', [ 0 ] )
   weight_mc = array( 'd', [ 0 ] )
   
   weight_ElectronRecoLow	 = array( 'd', [ 0 ] )
   weight_ElectronRecoHigh   	 = array( 'd', [ 0 ] )
   weight_ElectronIDStatHigh 	 = array( 'd', [ 0 ] )
   weight_ElectronIDLow	 	 = array( 'd', [ 0 ] )
   weight_ElectronStat15	 = array( 'd', [ 0 ] )
   weight_ElectronStat10	 = array( 'd', [ 0 ] )
   weight_ElectronStat7   	 = array( 'd', [ 0 ] )
   weight_ElectronTrigger 	 = array( 'd', [ 0 ] )
   weight_ElectronIsoIP 	 = array( 'd', [ 0 ] )
   weight_MuonRecoID 		 = array( 'd', [ 0 ] )
   weight_MuonTrigger 		 = array( 'd', [ 0 ] )

   mispaired = array( 'i', [ 0 ] )

   n_jets_fid_syst = std.vector( 'int' )()
   leading_jet_pt_fid_syst = std.vector( 'double' )()
   	
   ####################################TREES

   trees = []

   tree_incl_4mu   = TTree("tree_incl_4mu"  ,"tree_incl_4mu"  ); trees.append(tree_incl_4mu  )
   tree_incl_4e    = TTree("tree_incl_4e"   ,"tree_incl_4e"   ); trees.append(tree_incl_4e   )
   tree_incl_2mu2e = TTree("tree_incl_2mu2e","tree_incl_2mu2e"); trees.append(tree_incl_2mu2e)
   tree_incl_2e2mu = TTree("tree_incl_2e2mu","tree_incl_2e2mu"); trees.append(tree_incl_2e2mu)

   trees_cat = []
   tree_ggF_4mu   = TTree("tree_ggF_4mu"  ,"tree_ggF_4mu"  ); trees_cat.append(tree_ggF_4mu  )
   tree_ggF_4e    = TTree("tree_ggF_4e"   ,"tree_ggF_4e"   ); trees_cat.append(tree_ggF_4e   )
   tree_ggF_2mu2e = TTree("tree_ggF_2mu2e","tree_ggF_2mu2e"); trees_cat.append(tree_ggF_2mu2e)
   tree_ggF_2e2mu = TTree("tree_ggF_2e2mu","tree_ggF_2e2mu"); trees_cat.append(tree_ggF_2e2mu)
   tree_VBF       = TTree("tree_VBF",      "tree_VBF");       trees_cat.append(tree_VBF)
   tree_VH_Had    = TTree("tree_VH_Had",   "tree_VH_Had");    trees_cat.append(tree_VH_Had)
   tree_VH_Lep    = TTree("tree_VH_Lep",   "tree_VH_Lep");    trees_cat.append(tree_VH_Lep)

   tree_incl      = TTree("tree_incl"  ,"tree_incl"  ); trees.append(tree_incl)

   for tree in (trees+trees_cat):
     tree.Branch("run",		run,	"run/I");
     tree.Branch("event",	event,	"event/I");
     tree.Branch("event_type_truth",	event_type_truth,	"event_type_truth/I");
     tree.Branch("lbn",		lbn,	"lbn/I");
     tree.Branch("quad_type",	quad_type,	"quad_type/I");

     tree.Branch("m4l_unconstrained",	m4l_unconstrained,	"m4l_unconstrained/D");
     tree.Branch("m4l_fsr",		m4l_fsr,		"m4l_fsr/D");
     tree.Branch("m4l_constrained",	m4l_constrained,	"m4l_constrained/D");
     tree.Branch("mZ1_unconstrained",	mZ1_unconstrained,	"mZ1_unconstrained/D");
     tree.Branch("mZ1_fsr",		mZ1_fsr,		"mZ1_fsr/D");
     tree.Branch("mZ1_constrained",	mZ1_constrained,	"mZ1_constrained/D");
     tree.Branch("mZ2_unconstrained",	mZ2_unconstrained,	"mZ2_unconstrained/D");
     tree.Branch("mZ2_fsr",		mZ2_fsr,		"mZ2_fsr/D");
     tree.Branch("mZ2_constrained",	mZ2_constrained,	"mZ2_constrained/D");
     tree.Branch("m4lerr_constrained",	m4lerr_constrained,	"m4lerr_constrained/D");
     tree.Branch("m4lerr_fsr",		m4lerr_fsr,		"m4lerr_fsr/D");
     tree.Branch("m4lerr_unconstrained",m4lerr_unconstrained,	"m4lerr_unconstrained/D");

     tree.Branch("weight",			weight,			"weight/D");
     tree.Branch("weight_corr",			weight_corr,		"weight_corr/D");
     tree.Branch("weight_lumi",			weight_lumi,		"weight_lumi/D");
     tree.Branch("weight_sampleoverlap",	weight_sampleoverlap,	"weight_sampleoverlap/D");
     tree.Branch("weight_fiducial",		weight_fiducial,	"weight_fiducial/D");

     tree.Branch("weight_vertex",		weight_vertex,		"weight_vertex/D");
     tree.Branch("weight_pileup",		weight_pileup,		"weight_pileup/D");
     tree.Branch("weight_higgspt",		weight_higgspt,		"weight_higgspt/D");

     #tree.Branch("weight_higgspt_gen",		weight_higgspt_gen,	"weight_higgspt_gen/D");

     tree.Branch("cthstr",	cthstr,	"cthstr/D");
     tree.Branch("phi1",	phi1,	"phi1/D");
     tree.Branch("cth1",	cth1,	"cth1/D");
     tree.Branch("cth2",	cth2,	"cth2/D");
     tree.Branch("phi",		phi,	"phi/D");

     tree.Branch("pt4l_unconstrained" ,pt4l_unconstrained ,"pt4l_unconstrained/D");
     tree.Branch("pt4l_fsr"	      ,pt4l_fsr		  ,"pt4l_fsr/D");
     tree.Branch("pt4l_constrained"   ,pt4l_constrained	  ,"pt4l_constrained/D");
     tree.Branch("y4l_unconstrained"  ,y4l_unconstrained  ,"y4l_unconstrained/D");
     tree.Branch("y4l_fsr"	      ,y4l_fsr	 	  ,"y4l_fsr/D");
     tree.Branch("y4l_constrained"    ,y4l_constrained    ,"y4l_constrained/D");
     tree.Branch("eta4l_unconstrained",eta4l_unconstrained,"eta4l_unconstrained/D");
     tree.Branch("eta4l_fsr"          ,eta4l_fsr	  ,"eta4l_fsr/D");
     tree.Branch("eta4l_constrained"  ,eta4l_constrained  ,"eta4l_constrained/D");
 
     tree.Branch("Z1_lepplus_pt",	Z1_lepplus_pt,		"Z1_lepplus_pt/D");
     tree.Branch("Z1_lepminus_pt",	Z1_lepminus_pt,		"Z1_lepminus_pt/D");
     tree.Branch("Z2_lepplus_pt",	Z2_lepplus_pt,		"Z2_lepplus_pt/D");
     tree.Branch("Z2_lepminus_pt",	Z2_lepminus_pt,		"Z2_lepminus_pt/D");
     tree.Branch("Z1_lepplus_eta",	Z1_lepplus_eta,		"Z1_lepplus_eta/D");
     tree.Branch("Z1_lepminus_eta",	Z1_lepminus_eta,	"Z1_lepminus_eta/D");
     tree.Branch("Z2_lepplus_eta",	Z2_lepplus_eta,		"Z2_lepplus_eta/D");
     tree.Branch("Z2_lepminus_eta",	Z2_lepminus_eta,	"Z2_lepminus_eta/D");
     tree.Branch("Z1_lepplus_phi",	Z1_lepplus_phi,		"Z1_lepplus_phi/D");
     tree.Branch("Z1_lepminus_phi",	Z1_lepminus_phi,	"Z1_lepminus_phi/D");
     tree.Branch("Z2_lepplus_phi",	Z2_lepplus_phi,		"Z2_lepplus_phi/D");
     tree.Branch("Z2_lepminus_phi",	Z2_lepminus_phi,	"Z2_lepminus_phi/D");
     tree.Branch("Z1_lepplus_m",	Z1_lepplus_m,		"Z1_lepplus_m/D");
     tree.Branch("Z1_lepminus_m",	Z1_lepminus_m,		"Z1_lepminus_m/D");
     tree.Branch("Z2_lepplus_m",	Z2_lepplus_m,		"Z2_lepplus_m/D");
     tree.Branch("Z2_lepminus_m",	Z2_lepminus_m,		"Z2_lepminus_m/D");
     tree.Branch("Z1_lepplus_cov_mom",	Z1_lepplus_cov_mom,	"Z1_lepplus_cov_mom/D");
     tree.Branch("Z1_lepminus_cov_mom",	Z1_lepminus_cov_mom,	"Z1_lepminus_cov_mom/D");
     tree.Branch("Z2_lepplus_cov_mom",	Z2_lepplus_cov_mom,	"Z2_lepplus_cov_mom/D");
     tree.Branch("Z2_lepminus_cov_mom",	Z2_lepminus_cov_mom,	"Z2_lepminus_cov_mom/D");

     tree.Branch("n_jets",		n_jets,			"n_jets/I");
     tree.Branch("dijet_invmass",	dijet_invmass,		"dijet_invmass/D");
     tree.Branch("dijet_deltaeta",	dijet_deltaeta,		"dijet_deltaeta/D");
     tree.Branch("leading_jet_pt",	leading_jet_pt,		"leading_jet_pt/D");
     tree.Branch("leading_jet_eta",	leading_jet_eta,	"leading_jet_eta/D");
     tree.Branch("subleading_jet_pt",	subleading_jet_pt,	"subleading_jet_pt/D");

     tree.Branch("n_jets_fid",		n_jets_fid,		"n_jets_fid/I");
     tree.Branch("leading_jet_pt_fid",	leading_jet_pt_fid,	"leading_jet_pt_fid/D");

     tree.Branch("KD_discriminant",	KD_discriminant,	"KD_discriminant/D");
     tree.Branch("BDT_discriminant",	BDT_discriminant,	"BDT_discriminant/D");

     if not isData: 
       tree.Branch("pt4l_truth_born",	pt4l_truth_born,	"pt4l_truth_born/D");
       tree.Branch("y4l_truth_born",	y4l_truth_born,		"y4l_truth_born/D");
       tree.Branch("eta4l_truth_born",	eta4l_truth_born,	"eta4l_truth_born/D");
       tree.Branch("m4l_truth_born",	m4l_truth_born,		"m4l_truth_born/D");
       
       tree.Branch("mispaired",		mispaired,		"mispaired/I");

       tree.Branch("m4l_truth_matched_born",	m4l_truth_matched_born,		"m4l_truth_matched_born/D");
       tree.Branch("mZ1_truth_matched_born",	mZ1_truth_matched_born,		"mZ1_truth_matched_born/D");
       tree.Branch("mZ2_truth_matched_born",	mZ2_truth_matched_born,		"mZ2_truth_matched_born/D");
       tree.Branch("m4l_truth_matched_bare",	m4l_truth_matched_bare,		"m4l_truth_matched_bare/D");
       tree.Branch("mZ1_truth_matched_bare",	mZ1_truth_matched_bare,		"mZ1_truth_matched_bare/D");
       tree.Branch("mZ2_truth_matched_bare",	mZ2_truth_matched_bare,		"mZ2_truth_matched_bare/D");
       tree.Branch("m4l_truth_matched_dressed",	m4l_truth_matched_dressed,	"m4l_truth_matched_dressed/D");
       tree.Branch("mZ1_truth_matched_dressed",	mZ1_truth_matched_dressed,	"mZ1_truth_matched_dressed/D");
       tree.Branch("mZ2_truth_matched_dressed",	mZ2_truth_matched_dressed,	"mZ2_truth_matched_dressed/D");

       tree.Branch("Z1_lepplus_pt_truth_born",	Z1_lepplus_pt_truth_born,	"Z1_lepplus_pt_truth_born/D");
       tree.Branch("Z1_lepminus_pt_truth_born",	Z1_lepminus_pt_truth_born,	"Z1_lepminus_pt_truth_born/D");
       tree.Branch("Z2_lepplus_pt_truth_born",	Z2_lepplus_pt_truth_born,	"Z2_lepplus_pt_truth_born/D");
       tree.Branch("Z2_lepminus_pt_truth_born",	Z2_lepminus_pt_truth_born,	"Z2_lepminus_pt_truth_born/D");
       tree.Branch("Z1_lepplus_eta_truth_born",	Z1_lepplus_eta_truth_born,	"Z1_lepplus_eta_truth_born/D");
       tree.Branch("Z1_lepminus_eta_truth_born",Z1_lepminus_eta_truth_born,	"Z1_lepminus_eta_truth_born/D");
       tree.Branch("Z2_lepplus_eta_truth_born",	Z2_lepplus_eta_truth_born,	"Z2_lepplus_eta_truth_born/D");
       tree.Branch("Z2_lepminus_eta_truth_born",Z2_lepminus_eta_truth_born,	"Z2_lepminus_eta_truth_born/D");
       tree.Branch("Z1_lepplus_phi_truth_born",	Z1_lepplus_phi_truth_born,	"Z1_lepplus_phi_truth_born/D");
       tree.Branch("Z1_lepminus_phi_truth_born",Z1_lepminus_phi_truth_born,	"Z1_lepminus_phi_truth_born/D");
       tree.Branch("Z2_lepplus_phi_truth_born",	Z2_lepplus_phi_truth_born,	"Z2_lepplus_phi_truth_born/D");
       tree.Branch("Z2_lepminus_phi_truth_born",Z2_lepminus_phi_truth_born,	"Z2_lepminus_phi_truth_born/D");
       tree.Branch("Z1_lepplus_m_truth_born",	Z1_lepplus_m_truth_born,	"Z1_lepplus_m_truth_born/D");
       tree.Branch("Z1_lepminus_m_truth_born",	Z1_lepminus_m_truth_born,	"Z1_lepminus_m_truth_born/D");
       tree.Branch("Z2_lepplus_m_truth_born",	Z2_lepplus_m_truth_born,	"Z2_lepplus_m_truth_born/D");
       tree.Branch("Z2_lepminus_m_truth_born",	Z2_lepminus_m_truth_born,	"Z2_lepminus_m_truth_born/D");

       tree.Branch("n_jets_truth_bare",		n_jets_truth_bare,		"n_jets_truth_bare/I");
       tree.Branch("leading_jet_pt_truth_bare",	leading_jet_pt_truth_bare,	"leading_jet_pt_truth_bare/D");

       if addSystematics:
	   tree.Branch("weight_sf",	 		weight_sf,			"weight_sf/D");
	   tree.Branch("weight_sf1",	 		weight_sf1,			"weight_sf1/D");
	   tree.Branch("weight_sf2",	 		weight_sf2,			"weight_sf2/D");
	   tree.Branch("weight_sf3",	 		weight_sf3,			"weight_sf3/D");
	   tree.Branch("weight_sf4",	 		weight_sf4,			"weight_sf4/D");
	   tree.Branch("trigger_sf",			trigger_sf,			"trigger_sf/D");
	   tree.Branch("weight_mc",	 		weight_mc,			"weight_mc/D");
	   tree.Branch("weight_ElectronRecoLow",     	weight_ElectronRecoLow   ,	"weight_ElectronRecoLow/D");
	   tree.Branch("weight_ElectronRecoHigh",    	weight_ElectronRecoHigh  ,	"weight_ElectronRecoHigh/D");
	   tree.Branch("weight_ElectronIDStatHigh",  	weight_ElectronIDStatHigh,	"weight_ElectronIDStatHigh/D");
	   tree.Branch("weight_ElectronIDLow",       	weight_ElectronIDLow	  ,	"weight_ElectronIDLow/D");
	   tree.Branch("weight_ElectronStat15",      	weight_ElectronStat15	  ,	"weight_ElectronStat15/D");
	   tree.Branch("weight_ElectronStat10",      	weight_ElectronStat10	  ,	"weight_ElectronStat10/D");
	   tree.Branch("weight_ElectronStat7",      	weight_ElectronStat7	  ,	"weight_ElectronStat7/D");
	   tree.Branch("weight_ElectronTrigger",	weight_ElectronTrigger,		"weight_ElectronTrigger/D");
	   tree.Branch("weight_ElectronIsoIP",		weight_ElectronIsoIP,		"weight_ElectronIsoIP/D");

 	   tree.Branch("weight_MuonRecoID",		weight_MuonRecoID,		"weight_MuonRecoID/D");  
	   tree.Branch("weight_MuonTrigger",		weight_MuonTrigger,		"weight_MuonTrigger/D");

	   tree.Branch("n_jets_fid_syst", n_jets_fid_syst)
	   
	   tree.Branch("leading_jet_pt_fid_syst", leading_jet_pt_fid_syst)

   ####################################LOOP OVER EVENTS

   nentries = fin.GetEntries()
   if (nentries == 0):
     print "Found no events!  Aborting..."
     return

   for i in xrange(nentries):
       if not (fin.GetEntry(i)): continue
       if not i%10000: print 'Processing entry %d/%d'%(i,nentries)


       ##############################Apply cuts

       #PassCutsOnElectrons(self,fin,vecindex,blayer,Pix,TrkIso,CaloIso,d0,typeisEM)
       if fin.lepton_pt[2]>fin.lepton_pt[3]:
           vecindex_sub1 = 2
           vecindex_sub2 = 3
       else:
           vecindex_sub1 = 3
           vecindex_sub2 = 2
       index_sub1 = fin.lepton_index[vecindex_sub1]
       index_sub2 = fin.lepton_index[vecindex_sub2]


       #if not hm.PassCutsOnElectrons(fin,0,0,0,0,0,0,"ML"): continue
       #if not hm.PassCutsOnElectrons(fin,1,0,0,0,0,0,"ML"): continue
       #if not hm.PassCutsOnElectrons(fin,2,0,0,0,0,0,"ML"): continue
       #if not hm.PassCutsOnElectrons(fin,3,0,0,0,0,0,"ML"): continue
       #if not hm.PassCutsOnElectrons(fin,vecindex_sub1,0,0,0,0,0,"ML_Relaxed"): continue
       #if not hm.PassCutsOnElectrons(fin,vecindex_sub2,0,0,0,0,0,"ML_Relaxed"): continue 
       #if not (hm.PassCutsOnElectrons(fin,vecindex_sub1,0,0,0,0,0,"ML_Relaxed") or hm.PassCutsOnElectrons(fin,vecindex_sub2,0,0,0,0,0,"ML_Relaxed")): continue
       #if not hm.PassCutsOnElectrons(fin,vecindex_sub1,0,0,0,0,0,"SiTrack"): continue
       #if not hm.PassCutsOnElectrons(fin,vecindex_sub2,0,0,0,0,0,"SiTrack"): continue

       #if not hm.PassTrackIsolationCuts(fin,"All"): continue
       #if not hm.PassCaloIsolationCuts(fin,"All"):  continue
       #if not hm.PassD0SignificanceCuts(fin,"All"): continue

       #if not hm.PassTrackIsolationCuts(fin,"FirstPair"): continue
       #if not hm.PassCaloIsolationCuts(fin,"FirstPair"):  continue
       #if not hm.PassD0SignificanceCuts(fin,"FirstPair"): continue

       #if hm.PassD0SignificanceCuts(fin,"SecondPair"): continue

       #if not hm.PassTrackIsolationCuts(fin,"LooseSecondPair"): continue
       #if not hm.PassTrackIsolationCuts(fin,"SecondPair"): continue
       #if not hm.PassCaloIsolationCuts(fin,"LooseSecondPair"):  continue
       #if not hm.PassD0SignificanceCuts(fin,"SecondPair"): continue

       ###############################
       event_weight = 1.
       lumi_weight = 1.    
       ###GRL cut, only if data..
       if isData:
           passData = hm.ApplyDataTreatment(fin)
           if passData == -999: continue
	   #blinding cut
	   #if (fin.m_4l_constrained > 110000 and fin.m_4l_constrained < 140000): continue
       ####otherwise weights and overlap removal 146369 for 2012 (concerns ttbar sample)
       else:
           if hm.VetoEvent(fin): continue
	   
	   event_weight = hm.EventWeight(fin, lumi)
       	   lumi_weight  = hm.LumiWeight(fin,lumi)
       
       ##############################Fill variables

       numberevents_passed[4]+=1

       #Not Yet Implemented = -999
       run[0] = fin.RunNumber if isData else fin.mc_channel_number
       event[0] = fin.EventNumber 
       event_type_truth[0] = fin.event_type_truth 
       lbn[0] = fin.lbn
       quad_type[0] = fin.quad_type
       
       m4l_unconstrained[0]    = fin.m_4l / 1000.0
       m4lerr_unconstrained[0] = fin.m_4l_err / 1000.0
       mZ1_unconstrained[0]    = fin.m_12 / 1000.0
       mZ2_unconstrained[0]    = fin.m_34 / 1000.0
       m4l_fsr[0]    = fin.m_4l_fsr / 1000.0
       m4lerr_fsr[0] = fin.m_4l_err_fsr / 1000.0
       mZ1_fsr[0]    = fin.m_12_fsr / 1000.0
       mZ2_fsr[0]    = fin.m_34_fsr / 1000.0
       m4l_constrained[0]    = fin.m_4l_constrained / 1000.0
       m4lerr_constrained[0] = fin.m_4l_err_constrained / 1000.0 
       mZ1_constrained[0]    = fin.m_12_constrained / 1000.0
       mZ2_constrained[0]    = fin.m_34_constrained / 1000.0
       
       weight[0] = event_weight 
       weight_corr[0] = fin.evt_weight
       weight_lumi[0] = lumi_weight 
       weight_sampleoverlap[0] = -999 
       weight_fiducial[0] = 1 if isData else lumi_weight*hm.MCWeightSF(fin.mc_channel_number)*fin.weight_higgspt*fin.pileup_sf*fin.vertex_sf*fin.mc_event_weight

       weight_pileup[0] = fin.pileup_sf
       weight_vertex[0] = fin.vertex_sf
       weight_higgspt[0] = fin.weight_higgspt

       cthstr[0] = fin.cthstr
       phi1[0]   = fin.phi1
       cth1[0]   = fin.cth1
       cth2[0]   = fin.cth2
       phi[0]    = fin.phi 
       
       pt4l_unconstrained[0]  = fin.pt_4l / 1000.0
       pt4l_fsr[0]            = fin.pt_4l_fsr / 1000.0   
       pt4l_constrained[0]    = fin.pt_4l_constrained /1000.0
       y4l_unconstrained[0]   = fin.y4l_unconstrained
       y4l_fsr[0]             = fin.y4l_fsr
       y4l_constrained[0]     = fin.y4l_constrained
       eta4l_unconstrained[0] = fin.eta_4l
       eta4l_fsr[0]           = fin.eta_4l_fsr
       eta4l_constrained[0]   = fin.eta_4l_constrained
       
       Z1_lepplus_pt[0]   = fin.lepton_pt[0] / 1000.0	
       Z1_lepminus_pt[0]  = fin.lepton_pt[1] / 1000.0
       Z2_lepplus_pt[0]   = fin.lepton_pt[2] / 1000.0	
       Z2_lepminus_pt[0]  = fin.lepton_pt[3] / 1000.0	
       Z1_lepplus_eta[0]  = fin.lepton_eta[0]
       Z1_lepminus_eta[0] = fin.lepton_eta[1]
       Z2_lepplus_eta[0]  = fin.lepton_eta[2]
       Z2_lepminus_eta[0] = fin.lepton_eta[3]
       Z1_lepplus_phi[0]  = fin.lepton_phi[0]
       Z1_lepminus_phi[0] = fin.lepton_phi[1]
       Z2_lepplus_phi[0]  = fin.lepton_phi[2]
       Z2_lepminus_phi[0] = fin.lepton_phi[3]
       Z1_lepplus_m[0]    = fin.lepton_m[0] / 1000.0
       Z1_lepminus_m[0]   = fin.lepton_m[1] / 1000.0
       Z2_lepplus_m[0]    = fin.lepton_m[2] / 1000.0
       Z2_lepminus_m[0]   = fin.lepton_m[3] / 1000.0 
       Z1_lepplus_cov_mom[0]  = fin.lepton_cov_mom[0] / 1e6
       Z1_lepminus_cov_mom[0] = fin.lepton_cov_mom[1] / 1e6
       Z2_lepplus_cov_mom[0]  = fin.lepton_cov_mom[2] / 1e6
       Z2_lepminus_cov_mom[0] = fin.lepton_cov_mom[3] / 1e6

       n_jets[0] = fin.n_jets		
       dijet_invmass[0] = fin.m_jj / 1000.0	
       dijet_deltaeta[0] = fin.deltaeta_jj
       leading_jet_pt[0] = fin.pt_leadingjet / 1000.0	
       leading_jet_eta[0] = fin.eta_leadingjet
       subleading_jet_pt[0] = fin.pt_subleadingjet / 1000.0

       n_jets_fid[0] = fin.n_jets_fid		
       leading_jet_pt_fid[0] = fin.pt_leadingjet_fid / 1000.0	

       KD_discriminant[0] = -999
       BDT_discriminant[0] = -999


       if not isData: 
	  pt4l_truth_born[0]  = fin.pt_higgs_truth / 1000.0
	  y4l_truth_born[0]   = fin.y_higgs_truth
	  eta4l_truth_born[0] = fin.eta_higgs_truth
	  m4l_truth_born[0]   = fin.m_higgs_truth / 1000.0	
          
	  mispaired[0] = fin.mispaired  
	  
	  m4l_truth_matched_born[0] = -999	
	  mZ1_truth_matched_born[0] = -999	
	  mZ2_truth_matched_born[0] = -999	
	  m4l_truth_matched_bare[0] = fin.m4l_truth_matched_bare / 1000.0	
	  mZ1_truth_matched_bare[0] = fin.m12_truth_matched_bare / 1000.0     
	  mZ2_truth_matched_bare[0] = fin.m34_truth_matched_bare / 1000.0     
	  m4l_truth_matched_dressed[0] = fin.m4l_truth_matched_dressed / 1000.0
	  mZ1_truth_matched_dressed[0] = fin.m12_truth_matched_dressed / 1000.0
	  mZ2_truth_matched_dressed[0] = fin.m34_truth_matched_dressed / 1000.0

	  Z1_lepplus_pt_truth_born[0]  = fin.lepton_pt_truth_born[0] / 1000.0
	  Z1_lepminus_pt_truth_born[0] = fin.lepton_pt_truth_born[1] / 1000.0
	  Z2_lepplus_pt_truth_born[0]  = fin.lepton_pt_truth_born[2] / 1000.0
	  Z2_lepminus_pt_truth_born[0] = fin.lepton_pt_truth_born[3] / 1000.0
	  Z1_lepplus_eta_truth_born[0]  = fin.lepton_eta_truth_born[0]
	  Z1_lepminus_eta_truth_born[0] = fin.lepton_eta_truth_born[1]
	  Z2_lepplus_eta_truth_born[0]  = fin.lepton_eta_truth_born[2]
	  Z2_lepminus_eta_truth_born[0] = fin.lepton_eta_truth_born[3]
	  Z1_lepplus_phi_truth_born[0]  = fin.lepton_phi_truth_born[0]
	  Z1_lepminus_phi_truth_born[0] = fin.lepton_phi_truth_born[1]
	  Z2_lepplus_phi_truth_born[0]  = fin.lepton_phi_truth_born[2]
	  Z2_lepminus_phi_truth_born[0] = fin.lepton_phi_truth_born[3]
	  Z1_lepplus_m_truth_born[0]  = fin.lepton_m_truth_born[0] / 1000.0
	  Z1_lepminus_m_truth_born[0] = fin.lepton_m_truth_born[1] / 1000.0
	  Z2_lepplus_m_truth_born[0]  = fin.lepton_m_truth_born[2] / 1000.0
	  Z2_lepminus_m_truth_born[0] = fin.lepton_m_truth_born[3] / 1000.0

	  n_jets_truth_bare[0] = -999	
	  leading_jet_pt_truth_bare[0] = -999

       if addSystematics:
          weight_sf[0]  = fin.lepton_sf
          weight_sf1[0]  = fin.lepton_sf_recoid[0]
          weight_sf2[0]  = fin.lepton_sf_recoid[1]
          weight_sf3[0]  = fin.lepton_sf_recoid[2]
          weight_sf4[0]  = fin.lepton_sf_recoid[3]
          trigger_sf[0] = fin.trigger_sf
	  
	  weight_ElectronRecoLow[0] 	=  0 if fin.lepton_sf == 0 else fin.lepton_sf_ElectronRecoLow / fin.lepton_sf
	  weight_ElectronRecoHigh[0] 	=  0 if fin.lepton_sf == 0 else fin.lepton_sf_ElectronRecoHigh / fin.lepton_sf
	  weight_ElectronIDStatHigh[0] 	=  0 if fin.lepton_sf == 0 else fin.lepton_sf_ElectronIDStatHigh / fin.lepton_sf
	  weight_ElectronIDLow[0] 	=  0 if fin.lepton_sf == 0 else fin.lepton_sf_ElectronIDLow / fin.lepton_sf
	  weight_ElectronStat15[0] 	=  0 if fin.lepton_sf == 0 else fin.lepton_sf_ElectronStat15 / fin.lepton_sf
	  weight_ElectronStat10[0] 	=  0 if fin.lepton_sf == 0 else fin.lepton_sf_ElectronStat10 / fin.lepton_sf
	  weight_ElectronStat7[0] 	=  0 if fin.lepton_sf == 0 else fin.lepton_sf_ElectronStat7 / fin.lepton_sf
	  
	  weight_ElectronTrigger[0] 	=  0 if fin.trigger_sf == 0 else fin.trigger_sf_ElectronSyst / fin.trigger_sf 
	  
	  weight_ElectronIsoIP[0] 	=  fin.isolationip_sf_ElectronSyst      
	  
	  weight_MuonRecoID[0] 		=  0 if fin.lepton_sf == 0 else fin.lepton_sf_MuonSyst / fin.lepton_sf 
	          
	  weight_MuonTrigger[0] 	=  0 if fin.trigger_sf == 0 else fin.trigger_sf_MuonSyst / fin.trigger_sf        

 	  n_jets_fid_syst.clear()
	  for val in fin.n_jets_fid_syst: n_jets_fid_syst.push_back(val)
	  leading_jet_pt_fid_syst.clear()
	  for val in fin.pt_leadingjet_fid_syst:leading_jet_pt_fid_syst.push_back(val/1000.0)
  
       ##############################Fill appropriate tree

       trees[fin.quad_type].Fill()
       tree_incl.Fill()
       
       cat_index = int((fin.evt_category==0)*fin.quad_type + (fin.evt_category!=0)*(3+fin.evt_category))
       trees_cat[cat_index].Fill()

       numberevents_passed[fin.quad_type]+=1

   ####################################PRINT

   print input_dir
   print 'initial number of events: '+str(hm.numberevents_all)
   print 'after cutflow: '+str(numberevents_passed[4])
   print '4mu: '+str(numberevents_passed[0])
   print '4e: '+str(numberevents_passed[1])
   print '2mu2e: '+str(numberevents_passed[2])
   print '2e2mu: '+str(numberevents_passed[3])


   ####################################WRITE TO FILE


   filename = output_dir
   filename += '/'
   if (input_key != None): filename += input_key 
   filename += ("_"+output_tag) if output_tag != None else ""
   filename += '.root'
   fileout = TFile(filename,'RECREATE')

   for tree in (trees+trees_cat): tree.Write()

   print "Closing output file: " + fileout.GetPath().rstrip(':/')
   fileout.Close()
   
   return


if __name__ == '__main__' :
    main(ParseOptions())

