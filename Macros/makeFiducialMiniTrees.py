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
# Note that script expects root directories to follow structure: files = input_dir + '/*'+input_key+'*/*/*.root'
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
   output_tag     = kwargs.get('output_tag',None)

   if (output_dir == None): output_dir = input_dir + '/minitrees/'
   if not os.path.exists(output_dir): os.makedirs(output_dir)
    
   lumi = 20.277
   tree_name = 'tree_gen'
   
   if input_file != None:
     makeTrees(input_file, input_dir, input_keys, output_dir, output_tag, lumi, tree_name)
     return
   
   if input_keys is None:
     input_keys = os.walk(input_dir).next()[1]    
   
   for key in input_keys:
     print "Processing key: ", key
     makeTrees(input_file, input_dir, key, output_dir, output_tag, lumi, tree_name)

 
def makeTrees(input_file, input_dir, input_key, output_dir, output_tag, lumi, tree_name): 
     
   ####################################INITIALIZATION OF EXTERNAL TOOLS
   hm=Histmaker()
 
   ####################################INPUTFILES
   print input_file
   
   if input_file != None:
     file_key = input_file
   else:  
     file_key = input_dir + '/*'+input_key+'*/*/*.root'
   fin_gen = TChain("gen_tree")
   hm.GetFilesAndInitialCounts(fin_gen,file_key,False)
   
   files = glob.glob(file_key)
   fin_fid = TChain("output")
   for f in files: fin_fid.Add(f)

   ####################################COUNTERS

   numberevents_all=0
   numberevents_passed = [0,0,0,0,0]


   ####################################VARIABLES

   run 		= array( 'i', [ 0 ] )
   event 	= array( 'i', [ 0 ] )
   lbn 		= array( 'i', [ 0 ] )

   quad_type 	= array( 'i', [ 0 ] )
   event_type_truth 	= array( 'i', [ 0 ] )

   weight_fiducial 	= array( 'd', [ 0 ] )
   weight_lumi 		= array( 'd', [ 0 ] )
   weight_pu 		= array( 'd', [ 0 ] )
   weight_zvtx 		= array( 'd', [ 0 ] )

   #higgs truth variables
   higgs_m  	= array( 'd', [ 0 ] )
   higgs_pt 	= array( 'd', [ 0 ] )
   higgs_eta	= array( 'd', [ 0 ] )
   higgs_rapidity = array( 'd', [ 0 ] )
   higgs_cthstr = array( 'd', [ 0 ] )
   
   #Z1 truth variables
   Z1_m  	= array( 'd', [ 0 ] )
   Z1_pt 	= array( 'd', [ 0 ] )
   Z1_eta	= array( 'd', [ 0 ] )

   #Z2 truth variables
   Z2_m  	= array( 'd', [ 0 ] )
   Z2_pt 	= array( 'd', [ 0 ] )
   Z2_eta	= array( 'd', [ 0 ] )

   born_paired_higgslep34_m 	= array( 'd', [ 0 ] )
   born_paired_higgslep34_pt	= array( 'd', [ 0 ] )
   born_paired_higgslep34_eta	= array( 'd', [ 0 ] )

   born_paired_higgslep12_m 	= array( 'd', [ 0 ] )
   born_paired_higgslep12_pt	= array( 'd', [ 0 ] )
   born_paired_higgslep12_eta	= array( 'd', [ 0 ] )

   born_paired_higgslep4_cthstr	= array( 'd', [ 0 ] )
   born_paired_higgslep4_phi1  	= array( 'd', [ 0 ] )
   born_paired_higgslep4_cth1  	= array( 'd', [ 0 ] )
   born_paired_higgslep4_cth2  	= array( 'd', [ 0 ] )
   born_paired_higgslep4_phi   	= array( 'd', [ 0 ] )

   #jet variables
   n_jets_truth_fid 		= array( 'i', [ 0 ] )		
   leading_jet_pt_truth_fid 	= array( 'd', [ 0 ] )	
   
   #others
   n_electrons = array( 'i', [ 0 ] )
   n_muons     = array( 'i', [ 0 ] )
   
   #4-lepton variables (paired)
   lep4_m	   = array( 'd', [ 0 ] )
   lep4_pt	   = array( 'd', [ 0 ] )
   lep4_eta	   = array( 'd', [ 0 ] ) 
   lep4_y	   = array( 'd', [ 0 ] ) 

   bare_lep4_m  	= array( 'd', [ 0 ] )
   bare_lep4_pt 	= array( 'd', [ 0 ] )
   bare_lep4_eta 	= array( 'd', [ 0 ] ) 
   bare_lep4_y  	= array( 'd', [ 0 ] ) 

   bare_lep4_cthstr 	= array( 'd', [ 0 ] )
   bare_lep4_phi1 	= array( 'd', [ 0 ] )
   bare_lep4_cth1 	= array( 'd', [ 0 ] )
   bare_lep4_cth2 	= array( 'd', [ 0 ] ) 
   bare_lep4_phi 	= array( 'd', [ 0 ] )  
   
   #dressed 4-lepton variables (paired)
   dressed_lep4_m  	= array( 'd', [ 0 ] )
   dressed_lep4_pt 	= array( 'd', [ 0 ] )
   dressed_lep4_eta 	= array( 'd', [ 0 ] ) 
   dressed_lep4_y  	= array( 'd', [ 0 ] ) 

   #2-lepton variables (paired)
   bare_lep12_m  	= array( 'd', [ 0 ] )
   bare_lep12_pt 	= array( 'd', [ 0 ] )
   bare_lep12_eta 	= array( 'd', [ 0 ] ) 

   bare_lep34_m  	= array( 'd', [ 0 ] )
   bare_lep34_pt 	= array( 'd', [ 0 ] )
   bare_lep34_eta 	= array( 'd', [ 0 ] ) 

   #dressed 2-lepton variables (paired)
   dressed_lep12_m	= array( 'd', [ 0 ] )
   dressed_lep12_pt	= array( 'd', [ 0 ] )
   dressed_lep12_eta	= array( 'd', [ 0 ] ) 

   dressed_lep34_m	= array( 'd', [ 0 ] )
   dressed_lep34_pt	= array( 'd', [ 0 ] )
   dressed_lep34_eta	= array( 'd', [ 0 ] ) 
 
   mispaired     = array( 'i', [ 0 ] )
  	
   ####################################TREES

   trees = []

   tree_incl_fid    = TTree("tree_incl_fid"  ,"tree_incl_fid"  ); trees.append(tree_incl_fid )
   tree_incl_gen    = TTree("tree_incl_gen"  ,"tree_incl_gen"  ); trees.append(tree_incl_gen )
   
   for tree in (tree_incl_fid, tree_incl_gen):
     tree.Branch("run",		run,	"run/I");
     tree.Branch("event",	event,	"event/I");
     tree.Branch("lbn",		lbn,	"lbn/I");

     tree.Branch("quad_type",  quad_type,  "quad_type/I");
     tree.Branch("event_type_truth", event_type_truth, "event_type_truth/I");

     tree.Branch("weight_fiducial", 	weight_fiducial,"weight_fiducial/D");
     tree.Branch("weight_lumi", 	weight_lumi, 	"weight_lumi/D");
     #tree.Branch("weight_pu", 		weight_pu, 	"weight_pu/D");
     #tree.Branch("weight_zvtx", 	weight_zvtx, 	"weight_zvtx/D");
   
     tree.Branch("higgs_m ", 	higgs_m, 	"higgs_m/D");
     tree.Branch("higgs_pt", 	higgs_pt, 	"higgs_pt/D");
     tree.Branch("higgs_eta", 	higgs_eta, 	"higgs_eta/D");
     tree.Branch("higgs_rapidity", higgs_rapidity, "higgs_rapidity/D");
     tree.Branch("higgs_cthstr",higgs_cthstr,	"higgs_cthstr/D");

     tree.Branch("Z1_m", 	Z1_m	  , "Z1_m/D");
     tree.Branch("Z1_pt", 	Z1_pt	  , "Z1_pt/D");
     tree.Branch("Z1_eta", 	Z1_eta	  , "Z1_eta/D");

     tree.Branch("Z2_m", 	Z2_m	  , "Z2_m/D");
     tree.Branch("Z2_pt", 	Z2_pt	  , "Z2_pt/D");
     tree.Branch("Z2_eta", 	Z2_eta	  , "Z2_eta/D");

     tree.Branch("born_paired_higgslep34_m", born_paired_higgslep34_m, "born_paired_higgslep34_m/D");
     tree.Branch("born_paired_higgslep34_pt", born_paired_higgslep34_pt, "born_paired_higgslep34_pt/D");
     tree.Branch("born_paired_higgslep34_eta", born_paired_higgslep34_eta, "born_paired_higgslep34_eta/D");

     tree.Branch("born_paired_higgslep12_m", born_paired_higgslep12_m, "born_paired_higgslep12_m/D");
     tree.Branch("born_paired_higgslep12_pt", born_paired_higgslep12_pt, "born_paired_higgslep12_pt/D");
     tree.Branch("born_paired_higgslep12_eta", born_paired_higgslep12_eta, "born_paired_higgslep12_eta/D");

     tree.Branch("born_paired_higgslep4_cthstr", born_paired_higgslep4_cthstr, "born_paired_higgslep4_cthstr/D");
     tree.Branch("born_paired_higgslep4_phi1", born_paired_higgslep4_phi1  , "born_paired_higgslep4_phi1/D");
     tree.Branch("born_paired_higgslep4_cth1", born_paired_higgslep4_cth1  , "born_paired_higgslep4_cth1/D");
     tree.Branch("born_paired_higgslep4_cth2", born_paired_higgslep4_cth2  , "born_paired_higgslep4_cth2/D");
     tree.Branch("born_paired_higgslep4_phi", born_paired_higgslep4_phi   , "born_paired_higgslep4_phi/D");

     tree.Branch("n_jets_truth_fid", 		n_jets_truth_fid, 		"n_jets_truth_fid/I");
     tree.Branch("leading_jet_pt_truth_fid", 	leading_jet_pt_truth_fid, 	"leading_jet_pt_truth_fid/D");

 
   for tree in [tree_incl_fid]:
     tree.Branch("lep4_m", 	lep4_m	  , "lep4_m/D");
     tree.Branch("lep4_pt", 	lep4_pt	  , "lep4_pt/D");
     tree.Branch("lep4_eta", 	lep4_eta  , "lep4_eta/D");
     tree.Branch("lep4_y", 	lep4_y	  , "lep4_y/D");

     tree.Branch("bare_lep4_m", 	bare_lep4_m	  , "bare_lep4_m/D");
     tree.Branch("bare_lep4_pt", 	bare_lep4_pt	  , "bare_lep4_pt/D");
     tree.Branch("bare_lep4_eta", 	bare_lep4_eta  	  , "bare_lep4_eta/D");
     tree.Branch("bare_lep4_y", 	bare_lep4_y	  , "bare_lep4_y/D");

     tree.Branch("bare_lep4_cthstr", 	bare_lep4_cthstr  , "bare_lep4_cthstr/D");
     tree.Branch("bare_lep4_phi1", 	bare_lep4_phi1    , "bare_lep4_phi1/D");
     tree.Branch("bare_lep4_cth1", 	bare_lep4_cth1    , "bare_lep4_cth1/D");
     tree.Branch("bare_lep4_cth2", 	bare_lep4_cth2    , "bare_lep4_cth2/D");
     tree.Branch("bare_lep4_phi", 	bare_lep4_phi     , "bare_lep4_phi/D");
 
     tree.Branch("dressed_lep4_m",   dressed_lep4_m,   "dressed_lep4_m/D");
     tree.Branch("dressed_lep4_pt",  dressed_lep4_pt,  "dressed_lep4_pt/D");
     tree.Branch("dressed_lep4_eta", dressed_lep4_eta, "dressed_lep4_eta/D");
     tree.Branch("dressed_lep4_y",   dressed_lep4_y,   "dressed_lep4_y/D");

     tree.Branch("bare_lep12_m", 	bare_lep12_m,   "bare_lep12_m/D");
     tree.Branch("bare_lep12_pt", 	bare_lep12_pt,  "bare_lep12_pt/D");
     tree.Branch("bare_lep12_eta", 	bare_lep12_eta, "bare_lep12_eta/D");

     tree.Branch("bare_lep34_m", 	bare_lep34_m,   "bare_lep34_m/D");
     tree.Branch("bare_lep34_pt", 	bare_lep34_pt,  "bare_lep34_pt/D");
     tree.Branch("bare_lep34_eta", 	bare_lep34_eta, "bare_lep34_eta/D");

     tree.Branch("dressed_lep12_m",   dressed_lep12_m,   "dressed_lep12_m/D");
     tree.Branch("dressed_lep12_pt",  dressed_lep12_pt,  "dressed_lep12_pt/D");
     tree.Branch("dressed_lep12_eta", dressed_lep12_eta, "dressed_lep12_eta/D");

     tree.Branch("dressed_lep34_m",   dressed_lep34_m,   "dressed_lep34_m/D");
     tree.Branch("dressed_lep34_pt",  dressed_lep34_pt,  "dressed_lep34_pt/D");
     tree.Branch("dressed_lep34_eta", dressed_lep34_eta, "dressed_lep34_eta/D");

     tree.Branch("n_electrons", 	n_electrons, 		"n_electrons/I");
     tree.Branch("n_muons", 		n_muons, 		"n_muons/I");

     tree.Branch("mispaired", 		mispaired, 		"mispaired/I");

  ####################################LOOP OVER EVENTS
   
   fin_fid.BuildIndex('EventNumber')
   
   nentries = fin_gen.GetEntries()
   if (nentries == 0):
     print "Found no events!  Aborting..."
     return

   for i in xrange(nentries):
       if not (fin_gen.GetEntry(i)): continue
       if not i%10000: print 'Processing entry %d/%d'%(i,nentries)

       ############################### Get event weight
       
       event_weight = hm.EventWeight(fin_gen, lumi)
       lumi_weight  = hm.LumiWeight(fin_gen,lumi)
            
       ##############################Fiducial

       fiducial = (fin_fid.GetEntryWithIndex(fin_gen.event) > 0)
       if ( fiducial):
         #remove tau events
	 if (fin_fid.event_type_truth >= 4): fiducial = False
       
       ##############################Fill variables

       numberevents_passed[4]+=1

       #Not Yet Implemented = -999
       run[0]   = fin_gen.mc_channel_number
       event[0] = fin_gen.event 
       #lbn[0]   = fin_gen.lbn
       
       event_type_truth[0] = fin_gen.event_type_truth

       weight_fiducial[0] = event_weight
       weight_lumi[0]     = lumi_weight 
       #weight_pu[0]       = fin_gen.pileup_sf
       #weight_zvtx[0]     = fin_gen.vertex_sf 

       #higgs truth variables
       higgs_m[0]  	= fin_gen.higgs_m /1000.0
       higgs_pt[0] 	= fin_gen.higgs_pt /1000.0
       higgs_eta[0]	= fin_gen.higgs_eta
       higgs_rapidity[0]= fin_gen.higgs_rapidity
       higgs_cthstr[0] 	= fin_gen.higgs_cthstr

       #Z1 truth variables
       Z1_m[0]  	= fin_gen.Z1_m /1000.0
       Z1_pt[0] 	= fin_gen.Z1_pt /1000.0
       Z1_eta[0]	= fin_gen.Z1_eta

       #Z2 truth variables
       Z2_m[0]  	= fin_gen.Z2_m /1000.0
       Z2_pt[0] 	= fin_gen.Z2_pt /1000.0
       Z2_eta[0]	= fin_gen.Z2_eta

       born_paired_higgslep34_m[0]     =  fin_gen.born_paired_higgslep34_m  /1000.0
       born_paired_higgslep34_pt[0]    =  fin_gen.born_paired_higgslep34_pt /1000.0
       born_paired_higgslep34_eta [0]  =  fin_gen.born_paired_higgslep34_eta

       born_paired_higgslep12_m[0]     =  fin_gen.born_paired_higgslep12_m  /1000.0
       born_paired_higgslep12_pt[0]    =  fin_gen.born_paired_higgslep12_pt /1000.0
       born_paired_higgslep12_eta[0]   =  fin_gen.born_paired_higgslep12_eta

       born_paired_higgslep4_cthstr[0] =  fin_gen.born_paired_higgslep4_cthstr
       born_paired_higgslep4_phi1[0]   =  fin_gen.born_paired_higgslep4_phi1  
       born_paired_higgslep4_cth1[0]   =  fin_gen.born_paired_higgslep4_cth1  
       born_paired_higgslep4_cth2[0]   =  fin_gen.born_paired_higgslep4_cth2  
       born_paired_higgslep4_phi[0]    =  fin_gen.born_paired_higgslep4_phi   

       #jet variables
       n_jets_truth_fid[0] 	= fin_gen.n_jets_truth_fid 		
       leading_jet_pt_truth_fid[0] = fin_gen.pt_leadingjet_fid /1000.0	
   
       if (fiducial): 
	 quad_type[0]  = fin_fid.quad_type

          #4-lepton variables (paired)
	 lep4_m[0]	   = fin_fid.lep4_m /1000.0
	 lep4_pt[0]	   = fin_fid.lep4_pt /1000.0
	 lep4_eta[0] 	   = fin_fid.lep4_eta
	 lep4_y[0]	   = fin_fid.lep4_y 
	 
	 #change this sometime in the future
	 bare_lep4_m[0]  	= fin_fid.lep4_m /1000.0
	 bare_lep4_pt[0] 	= fin_fid.lep4_pt /1000.0
	 bare_lep4_eta[0] = fin_fid.lep4_eta
	 bare_lep4_y[0]  	= fin_fid.lep4_y 

	 bare_lep4_cthstr[0] = fin_fid.lep4_cthstr
	 bare_lep4_phi1[0]   = fin_fid.lep4_phi1
	 bare_lep4_cth1[0]   = fin_fid.lep4_cth1
	 bare_lep4_cth2[0]   = fin_fid.lep4_cth2 
	 bare_lep4_phi[0]    = fin_fid.lep4_phi

	 #dressed 4-lepton variables (paired)
	 dressed_lep4_m[0]   = fin_fid.dressed_lep4_m /1000.0
	 dressed_lep4_pt[0]  = fin_fid.dressed_lep4_pt /1000.0
	 dressed_lep4_eta[0] = fin_fid.dressed_lep4_eta 
	 dressed_lep4_y[0]   = fin_fid.dressed_lep4_y 

          #2-lepton variables (paired)
	 bare_lep12_m[0]   = fin_fid.lep12_m /1000.0
	 bare_lep12_pt[0]  = fin_fid.lep12_pt /1000.0
	 bare_lep12_eta[0] = fin_fid.lep12_eta

	 bare_lep34_m[0]   = fin_fid.lep34_m /1000.0
	 bare_lep34_pt[0]  = fin_fid.lep34_pt /1000.0
	 bare_lep34_eta[0] = fin_fid.lep34_eta

	 #dressed 2-lepton variables (paired)
	 dressed_lep12_m[0]   = fin_fid.dressed_lep12_m /1000.0
	 dressed_lep12_pt[0]  = fin_fid.dressed_lep12_pt /1000.0
	 dressed_lep12_eta[0] = fin_fid.dressed_lep12_eta 

	 dressed_lep34_m[0]   = fin_fid.dressed_lep34_m /1000.0
	 dressed_lep34_pt[0]  = fin_fid.dressed_lep34_pt /1000.0
	 dressed_lep34_eta[0] = fin_fid.dressed_lep34_eta 
 
	 n_electrons[0] 	= fin_fid.n_electrons		
	 n_muons[0] 	= fin_fid.n_muons		
	 
	 mispaired[0] 	= fin_fid.mispaired		

       ##############################Fill appropriate tree

       if (fiducial): tree_incl_fid.Fill()
       tree_incl_gen.Fill()
       
       if (fiducial): numberevents_passed[fin_fid.quad_type]+=1

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
   if (input_key != None):    filename += input_key 
   if (output_tag != None):   filename += '_'+output_tag
   if filename.endswith('/'): filename += 'default'
   filename += '.root'
   fileout = TFile(filename,'RECREATE')

   for tree in (trees): tree.Write()

   print "Closing output file: " + fileout.GetPath().rstrip(':/')
   fileout.Close()
   
   return


if __name__ == '__main__' :
    main(ParseOptions())

