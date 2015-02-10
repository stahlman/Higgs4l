#!/usr/bin/env python

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'Feb 2014'

#####################################################################
# Script to compare mini-trees value by value for each branch
#
# Based on compareH4lMinitrees.py  from RD Schaffer 
#####################################################################

import os, user, math
from array import array
from ROOT import *
import PyCintex

from argparse import ArgumentParser

#global variables

#default trees to check
def_trees = ["tree_incl_4mu", "tree_incl_4e", "tree_incl_2mu2e", "tree_incl_2e2mu"]
#def_trees = ["tree_incl_4mu", "tree_incl_4e", "tree_incl_2mu2e", "tree_incl_2e2mu", 
#         "tree_ggF_4mu", "tree_ggF_4e", "tree_ggF_2mu2e", "tree_ggF_2e2mu", 
#         "tree_VBF", "tree_VH"]
#def_trees = ["tree_incl_4mu"]
    
#    
epsilon = 0.0001 # relative tolerance for the difference

doM4lErr = False
# doM4lErr = True

mass_lo = 0
mass_hi = 10000

#variables
massVars  = ['m4l_unconstrained', 'm4lerr_unconstrained', 'mZ1_unconstrained', 'mZ2_unconstrained', 'm4l_fsr', 'mZ1_fsr', 'mZ2_fsr', 'm4l_constrained', 'm4lerr_constrained', 'mZ1_constrained', 'mZ2_constrained']

higgsVars = ['pt4l_unconstrained', 'y4l_unconstrained', 'eta4l_unconstrained', 'pt4l_fsr', 'y4l_fsr', 'eta4l_fsr', 'pt4l_constrained', 'y4l_constrained', 'eta4l_constrained']

weightVars = ['event','lbn','npv','weight_corr'] # 'weight_sampleoverlap'

##lepvars = ['Z1_lepplus_pt', 'Z1_lepminus_pt', 'Z2_lepplus_pt', 'Z2_lepminus_pt', 'Z1_lepplus_eta', 'Z1_lepminus_eta', 'Z2_lepplus_eta', 'Z2_lepminus_eta', 'Z1_lepplus_phi', 'Z1_lepminus_phi', 'Z2_lepplus_phi', 'Z2_lepminus_phi', 'Z1_lepplus_m', 'Z1_lepminus_m', 'Z2_lepplus_m', 'Z2_lepminus_m']
lepvars = ['Z1_lepplus_pt', 'Z1_lepminus_pt', 'Z2_lepplus_pt', 'Z2_lepminus_pt', 'Z1_lepplus_eta', 'Z1_lepminus_eta', 'Z2_lepplus_eta', 'Z2_lepminus_eta', 'Z1_lepplus_phi', 'Z1_lepminus_phi', 'Z2_lepplus_phi', 'Z2_lepminus_phi', 'Z1_lepplus_m', 'Z1_lepminus_m', 'Z2_lepplus_m', 'Z2_lepminus_m', 'Z1_lepplus_cov_mom', 'Z1_lepminus_cov_mom', 'Z2_lepplus_cov_mom', 'Z2_lepminus_cov_mom']

angleVars =  ['cthstr', 'phi1', 'cth1', 'cth2', 'phi']

jetVars =  ['n_jets', 'dijet_invmass', 'dijet_deltaeta', 'leading_jet_pt', 'leading_jet_eta', 'leading_jet_phi','leading_jet_m','leading_jet_width','leading_jet_nTrk', 'subleading_jet_pt', 'subleading_jet_eta', 'subleading_jet_phi','subleading_jet_m','subleading_jet_width','subleading_jet_nTrk','third_jet_pt', 'third_jet_eta', 'third_jet_phi','third_jet_m','third_jet_width','third_jet_nTrk','KD_discriminant','BDT_discriminant']

jetTruthVars =  ['n_jets_truth_bare', 'leading_jet_pt_truth_bare']

higgsTruthVars =  ['pt4l_truth_born', 'y4l_truth_born', 'eta4l_truth_born', 'm4l_truth_born']

massTruthVars =  ['m4l_truth_matched_born', 'mZ1_truth_matched_born', 'mZ2_truth_matched_born', 'm4l_truth_matched_bare', 'mZ1_truth_matched_bare', 'mZ2_truth_matched_bare', 'm4l_truth_matched_dressed', 'mZ1_truth_matched_dressed', 'mZ2_truth_matched_dressed']

lepTruthVars =  [ 'Z1_lepplus_pt_truth_born', 'Z1_lepminus_pt_truth_born', 'Z2_lepplus_pt_truth_born', 'Z2_lepminus_pt_truth_born', 'Z1_lepplus_eta_truth_born', 'Z1_lepminus_eta_truth_born', 'Z2_lepplus_eta_truth_born', 'Z2_lepminus_eta_truth_born', 'Z1_lepplus_phi_truth_born', 'Z1_lepminus_phi_truth_born', 'Z2_lepplus_phi_truth_born', 'Z2_lepminus_phi_truth_born', 'Z1_lepplus_m_truth_born', 'Z1_lepminus_m_truth_born', 'Z2_lepplus_m_truth_born', 'Z2_lepminus_m_truth_born']

checkVars =   ['calib', 'fsrType']

diffVars = ['weight','weight_lumi','weight_corr', 'm4l_unconstrained', 'mZ1_unconstrained', 'm4l_constrained','m4l_fsr','pt4l_unconstrained','y4l_unconstrained','mZ2_unconstrained','cthstr','n_jets_fid', 'leading_jet_pt']

systVars = ['m4l_constrained', 'weight']#,'weight_ElectronRecoLow','weight_ElectronRecoHigh','weight_ElectronIDStatHigh','weight_ElectronIDLow','weight_ElectronStat15','weight_ElectronStat10','weight_ElectronStat7','weight_ElectronTrigger','weight_MuonTrigger','weight_ElectronIsoIP']


def_branches = systVars

#-----------------------------------------------------------------------------------------------------        
def ParseOptions() :

    parser = ArgumentParser(usage='python compareHSG2Minitrees.py --f1 file1 --f2 file2 [ --trees <tree_names>]' )
    
    parser.add_argument('--f1', dest='input_file1', default=None, 
            help='First input file (one file only)' )

    parser.add_argument('--f2', dest='input_file2', default=None, 
            help='Second input file (one file only)' )

    parser.add_argument('--dir1', dest='input_dir1', default=None,
            help='First input directory' )

    parser.add_argument('--dir2', dest='input_dir2', default=None,
            help='Second input directory' )

    parser.add_argument('--trees', dest='input_trees', nargs="+" , default=None,  
            help='Trees to check' )    

    parser.add_argument('--count', action='store_true',dest='input_count', default=False,  
            help='Option to check event count only' )    

    parser.add_argument('--branches', dest='input_branches', nargs="+" , default=None,  
            help='Branches to check' )    

    parser.add_argument('--v', dest='input_v', default=1,  
            help='verbosity (0,1)' )    
     
    options = parser.parse_args()

    return options


#-----------------------------------------------------------------------------------------------------        
#-----------------------------------------------------------------------------------------------------        
def main(options) :
    
    m_args = vars(options)
    input_file1  = m_args.get('input_file1',None)
    input_file2  = m_args.get('input_file2',None)
    input_dir1   = m_args.get('input_dir1',None)
    input_dir2   = m_args.get('input_dir2',None)    
    input_trees  = m_args.get('input_trees',None)
    input_branches  = m_args.get('input_branches',None)
    input_count  = m_args.get('input_count',None)
    input_v      = int(m_args.get('input_v',None)) 

    #get tree names
    check_trees = []
    if (input_trees != None):
      check_trees = input_trees
    else:
      check_trees = def_trees       
    print 'Checking trees:', check_trees
    #for tr in check_trees: print '\t',tr    

    #get tree names
    check_branches = []
    if (input_branches != None):
      check_branches = input_branches
    else:
      check_branches = def_branches      
    print 'Checking branches:', check_branches
    #for br in check_branches: print '\t',br    
 
    #find input
    if (input_file1 != None and input_file2 != None):
       compareMiniTrees(input_file1, input_file2, check_trees, check_branches,input_count, input_v)
    
    elif (input_dir1 != None and input_dir2 != None):
      input_files1 = os.walk(input_dir1).next()[2]          
      input_files2 = os.walk(input_dir2).next()[2]
      #print input_files1, input_files2
      common_files = intersect(input_files1, input_files2)
      print common_files
      for i,filename in enumerate(common_files):
        print "Processing file:",i+1,' / ',len(common_files) 
        compareMiniTrees(input_dir1+'/'+filename, input_dir2+'/'+filename, check_trees, check_branches,input_count, input_v)
                 
    else:
      print "ERROR: Must specify two input files or two directories"
    
    return    
   
#-----------------------------------------------------------------------------------------------------        

def compareMiniTrees(input_file1, input_file2, check_trees, in_brsToChk, checkCountOnly, verbose=1):

    
    print "Opening files:"
    print "\t", input_file1
    print "\t", input_file2
    fin1 = TFile.Open (input_file1)
    fin2 = TFile.Open (input_file2)
    if (not fin1 or not fin2):
      print "Problem with input files!"
      return
    
    if len(check_trees) == 0:
      print "Error: No trees specified!"
      return
      
    # getting the list of branches to check
    brsToChk = []
    if not checkCountOnly:
      f1_branches = getBranchNames(fin1.Get(check_trees[0]))
      f2_branches = getBranchNames(fin2.Get(check_trees[0]))

      brsAvailable = intersect(f1_branches, f2_branches)
      brsToChk = intersect(brsAvailable, in_brsToChk)
    
      if ( len(brsToChk) == 0 ):
	print "Error: Requested branches not found!"
	return
    
    for tree in check_trees:
        
	t_verbose = verbose
	
	print "\n\nChecking tree:",tree
	
	f1_tree  = fin1.Get(tree)
        f2_tree  = fin2.Get(tree)
        if (not f1_tree or not f2_tree):
          print "Problem with input trees!"
          continue
 
        f1_n = f1_tree.GetEntries()
        f2_n = f2_tree.GetEntries()
	
	if checkCountOnly:
          print '----------------------------------------'
	  if (f1_n != f2_n):
 	    print '\033[91m'+'CutFlow Mismatch'+'\033[0m' 
	    print 'File 1:',f1_n, 'File 2:', f2_n
	    print 'Run script without option --count for more info'
          else:
	    print 'Cutflows match with',f1_n,'events'
	  print '----------------------------------------'
	  continue
		
        n_brsToChk = [ 0 for br in brsToChk ]
	
	#build index for f2
	#f1_tree.BuildIndex("run", "event")
	f2_tree.BuildIndex("run", "event")
	
	n_checked = 0
	cf_mismatch = False
	n_mismatch = 0
	
	#check for type mismatch
	f1_tree.GetEntry(0)
	f2_tree.GetEntry(0)
	for br in brsToChk:
	  f1_val = getattr(f1_tree, br)
	  f2_val = getattr(f2_tree, br)
	  if (type(f1_val) != type(f2_val)):
	    print "Type Mismatch for branch",br,". Expect precision mismatches." 

	for ievt in range(f1_tree.GetEntries()):
	#for ievt in range(5):

	  f1_tree.GetEntry(ievt)
	  
	  found = f2_tree.GetEntryWithIndex(f1_tree.run, f1_tree.event)
	  if not (found > 0):
	    cf_mismatch = True
	    #print "Cutflow Mismatch: Event", f1_tree.event,"not found in File2"
	    continue
	  
	  #trees synchronized, now check variables
	  if (f1_tree.run != f2_tree.run or f1_tree.event != f2_tree.event):
	    print "ERROR: still not synchronized"
	    continue

          #signal region check
	  #if ((f1_tree.m4l_constrained < mass_lo or f1_tree.m4l_constrained > mass_hi) and (f2_tree.m4l_constrained < mass_lo or f2_tree.m4l_constrained > mass_hi)): continue

          n_checked += 1
	  	  
	  for i in range(len(brsToChk)):
	    f1_val = getattr(f1_tree, brsToChk[i])
	    f2_val = getattr(f2_tree, brsToChk[i])
	    
	    diff = 0
	    if (f1_val != 0.0):
	       diff = math.fabs(f1_val - f2_val)/math.fabs(f1_val)
	    elif (f2_val != 0.0):
	       diff = math.fabs(f1_val - f2_val)/math.fabs(f2_val)
            
	    #if (True):
	    if diff > epsilon:
                if (t_verbose > 0): print "mismatch: ",brsToChk[i].ljust(20), str(f1_tree.run).ljust(8), str(f1_tree.event).ljust(8), f1_val, f2_val, diff
	        n_mismatch += 1
		if (n_mismatch == 50):
		  print "**** More than 50 mismatches. Suppressing output... ****"
		  t_verbose = 0
	    else:
		n_brsToChk[i] += 1
	# end event loop
	
	print "Total number of events:",f1_n 

	# if mismatch detected, determine events not matching
	if (f1_n != f2_n or cf_mismatch):
	   f1_evts = set()
	   for ievt in range(f1_tree.GetEntries()):
	      f1_tree.GetEntry(ievt)
	      #if (f1_tree.m4l_constrained < mass_lo or f1_tree.m4l_constrained > mass_hi): continue
	      f1_evts.add( (f1_tree.run,f1_tree.event) )
	   f2_evts = set()
	   for ievt in range(f2_tree.GetEntries()):
	      f2_tree.GetEntry(ievt)
	      #if (f2_tree.m4l_constrained < mass_lo or f2_tree.m4l_constrained > mass_hi): continue
	      f2_evts.add( (f2_tree.run,f2_tree.event) )
           common_events = f1_evts & f2_evts
	   f1only_events = f1_evts - f2_evts
	   f2only_events = f2_evts - f1_evts

           print '----------------------------------------'
	   print '\033[91m'+'CutFlow Mismatch'+'\033[0m' 
	   print "Events in common:", len(common_events)
	   print "Events only in File 1:",len(f1only_events)
	   for evt in f1only_events: print evt,
	   #   f1_tree.GetEntryWithIndex(evt[0], evt[1])
	   #   print "Lost event", evt, f1_tree.m4l_constrained
	   print ''
	   print "Events only in File 2:",len(f2only_events)
	   for evt in f2only_events: print evt,
	   #   f2_tree.GetEntryWithIndex(evt[0], evt[1])
	   #   print "Gained event", evt, f2_tree.m4l_constrained
	   print ''	
           print '----------------------------------------'
	
	      
        #print "Checks ok for variables: ",
        #for i in range(len(brsToChk)):
        #    print brsToChk[i], n_brsToChk[i],
        #print ''
	     
        print "Numbers matched ok for variables: ",
        for i in range(len(brsToChk)):
            if(n_checked == n_brsToChk[i]):
                print brsToChk[i], n_brsToChk[i],
            else:
                print '\033[91m'+brsToChk[i]+'\033[0m', n_brsToChk[i],            
        print ''
    
    print "Closing files:"
    print "\t", input_file1
    print "\t", input_file2
    fin1.Close()
    fin2.Close()

    return

def getBranchNames(tree):
    branchNames = [];
    list_of_branches= tree.GetListOfBranches()
    for i in range(list_of_branches.GetEntries()):
    	branchNames.append(list_of_branches.At(i).GetName())
        continue
    return branchNames
    
def intersect(a, b):
    return list(set(a) & set(b))

def difference(a, b):
    diffList = []
    diffList = diffList + list(set(a)-set(b))
    diffList = diffList + list(set(b)-set(a))
    return diffList


if __name__ == '__main__' :
    main(ParseOptions())


