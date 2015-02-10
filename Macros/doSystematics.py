"""
Calculate Systematics
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'May 2013'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

import math
from ROOT import *
from PlotUtils import *
from AnalysisRoutines import *
from variables import *
import glob
import re
from systematics import *

ROOT.gROOT.LoadMacro("AtlasStyle.C");
ROOT.gROOT.LoadMacro("AtlasUtils.C");
SetAtlasStyle()


#tree_names = ['inclusive','tree_incl_4mu','tree_incl_2e2mu','tree_incl_2mu2e','tree_incl_4e']
tree_names = ['inclusive']

sample_tags = []
sample_keys = []
inputDir_Nominal = []
inputDir_Systematic =[]

#H125
#sample_tags.append("H125")
#sample_keys.append("H125")
#inputDir_Nominal.append("/disk/userdata00/atlas_data2/stahlman/output/11052014/minitrees/")
#inputDir_Systematic.append("/disk/userdata00/atlas_data2/stahlman/output/11052014/minitrees/")

#qqZZ
sample_tags.append("qqZZ"); 
sample_keys.append("_ZZ_"); 
inputDir_Nominal.append("/disk/userdata00/atlas_data2/stahlman/output/11052014/minitrees")
inputDir_Systematic.append("/disk/userdata00/atlas_data2/stahlman/output/11052014/minitrees")

#qqZZ
sample_tags.append("ggZZ"); 
sample_keys.append("gg2ZZJimmy"); 
inputDir_Nominal.append("/disk/userdata00/atlas_data2/stahlman/output/11052014/minitrees")
inputDir_Systematic.append("/disk/userdata00/atlas_data2/stahlman/output/11052014/minitrees")

outputDir = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v07/"
#outputDir = "/disk/userdata00/atlas_data2/stahlman/output/test/"

#Define input ------------------------------------------------------------------------------------------------------------

#numbers =[]
fid_filenames = []
rec_filenames = []

mass_window_cut = "(m4l_constrained<129 && m4l_constrained>118)"
#mass_window_cut = "(m4l_constrained<130 && m4l_constrained>115)"
#mass_window_cut = "1"

nominal_weight = 'weight*'+mass_window_cut

#define systematics

#weight based systematics
w_systematics = systematics_electron_efficiency + systematics_muon_efficiency	   

#selection based systematics
f_systematics = [] # systematics_all_scale_resolution

#variable based systematics
jet_systematics = systematics_jet_all

#Find input ------------------------------------------------------------------------------------------------------------
nominal_filenames = []
for i in range(len(sample_tags)):
  key = inputDir_Nominal[i]+"/*"+sample_keys[i]+"*Nominal*.root"
  print "Using nominal files that match: " + key
  nominal_filenames.append(glob.glob(key))
  if len(nominal_filenames[i]) == 0: 
    print "No Nominal files found for "+sample_tags[i]+" in "+inputDir_Nominal[i]
    sys.exit(0)
  print "Nominal files for sample: ", sample_tags[i]
  for filename in nominal_filenames[i]:
    print '\t',filename


syst_filenames = []
for i in range(len(sample_tags)):
  syst_filenames.append([])
  for j in range(len(f_systematics)):
    syst_filenames[i].append(glob.glob(inputDir_Systematic[i]+"/*"+sample_keys[i]+"*"+f_systematics[j][0]+"*.root"))
    if len(syst_filenames[i]) == 0: 
      print "No Systematic files found for "+sample_tags[i]+" with systematic "+ f_systematics[j][0]
    else:
      print "Variation files for sample: ", sample_tags[i], " systematic: ", f_systematics[j][0]
      for filename in syst_filenames[i][j]:
         print '\t',filename

#loop over samples
for sample_i in range(len(sample_tags)):
  
  #loop over channels
  for tree_name in tree_names:  

    #Retrieve trees ------------------------------------------------------------------------------------------------------------
    nominal_chain =  GetChain(tree_name, nominal_filenames[sample_i]) 

    systematic_chains = []
    for j in range(len(f_systematics)):
     systematic_chains.append( GetChain(tree_name,syst_filenames[sample_i][j]) )

    for var_i in range(len(variables)):
    #for var_i in range(1):

       #get variables
       var_name = variables[var_i]
       var      = var_mt[var_i]     
       var_bin  = var_bins[var_i]
       doJetSystematics  = var_jet[var_i]

       jet_vars = []
       if doJetSystematics:
	 for i in range(len(jet_systematics)): 
	   jet_vars.append(var.replace(var_name_mt[var_i], var_name_mt[var_i]+'_syst['+str(i)+']'))

       print "Variable:", var_name

       #Open Output File ------------------------------------------------------------------------------------------------------------

       channel = tree_name
       if channel.startswith('tree_incl_'): channel = channel.lstrip('tree_incl_')

       fout = TFile(outputDir + "/Systematics."+var_name+'.'+sample_tags[sample_i]+"."+channel+".root", "RECREATE")
       fout.cd()
       f = open(outputDir + "/Systematics."+var_name+'.'+sample_tags[sample_i]+"."+channel+".txt", 'w')
       f_tab = open(outputDir + "/Systematics."+var_name+'.'+sample_tags[sample_i]+"."+channel+".table", 'w')


       #Fill Hists ------------------------------------------------------------------------------------------------------------
       print "Filling Hists"
       hists  = []
       shifts = []
       #weight based systematics
       for i in range(len(w_systematics)):
	 hists += CalculateSystematic( w_systematics[i][0], nominal_chain, nominal_chain, nominal_weight, nominal_weight+'*weight_'+w_systematics[i][0], var_name,var,var, var_bin)

       #selection based systematics
       for i in range(len(f_systematics)):
	 hists += CalculateSystematic( f_systematics[i][0], nominal_chain, systematic_chains[i], nominal_weight, nominal_weight, var_name,var,var, var_bin)

	 #shifts.append( CalculateMassSystematic(f_systematics[i], nominal_chain, systematic_chains[i], nominal_weight))

       #variable based systematics
       if doJetSystematics:
         for i in range(len(jet_systematics)):
	   hists += CalculateSystematic( jet_systematics[i][0], nominal_chain, nominal_chain, nominal_weight, nominal_weight, var_name,var,jet_vars[i], var_bin)

       n_bins = len(var_bin) - 1
       total_syst_up = [0 for i in range(n_bins)] 
       total_syst_dn = [0 for i in range(n_bins)] 
       syst_name_dict = dict(systematics_all)
       print '----------------------------------------------------------------'
       print ("Systematic "+var_name + " "+channel).ljust(25),
       for i in range(n_bins): print'\tBin',i,
       print ''
       print '----------------------------------------------------------------'
       for hist in hists:
	 if not hist.GetName().endswith('_syst'): continue
	 
	 syst_name = hist.GetName().replace('h_'+var_name+'_','').replace('_syst','')
	   
	 atlas_np_name = syst_name_dict[syst_name]	 	 
	 single_variation = syst_name.endswith('Up') or syst_name.endswith('Dn')
	 variation = 'Sym' 
	 if syst_name.endswith('Up'): variation = 'Up'
	 if syst_name.endswith('Dn'): variation = 'Down'
	 
	 line = (atlas_np_name+','+variation).ljust(50)
	 line_tab = (syst_name).ljust(50)

	 for i in range(n_bins): 
	   if hist[i+1] > 0 or not single_variation: total_syst_up[i] += hist[i+1]*hist[i+1]
	   if hist[i+1] < 0 or not single_variation: total_syst_dn[i] += hist[i+1]*hist[i+1]      
	   line += "\t"+str(round(hist[i+1], 3)).ljust(9)
	   line_tab += "\t& " +str(round(hist[i+1], 3)).ljust(9)
	 line_tab += r'\\'
	 print line
	 f.write(line+'\n')
	 f_tab.write(line_tab+'\n')
	 
       for i in range(n_bins):
	 total_syst_up[i] = sqrt(total_syst_up[i])
	 total_syst_dn[i] = sqrt(total_syst_dn[i])

       print '-----------------------------------------------------------------'
       print 'Total Up: '.ljust(25),
       for i in range(n_bins): print '\t',round(total_syst_up[i],3),
       print ''
       print 'Total Dn: '.ljust(25),
       for i in range(n_bins): print '\t',round(total_syst_dn[i],3),
       print ''
       print '-----------------------------------------------------------------'

       print "Mass Systematics for sample:", sample_tags[sample_i]
       for i in range(len(shifts)): print f_systematics[i], '\t',round(shifts[i], 4)

       #Write Output ------------------------------------------------------------------------------------------------------------

       print 'Closing output files: '
       fout.cd()
       for hist in hists: hist.Write()
       print '\t',fout.GetPath().rstrip(':/')
       fout.Close()
       print '\t',f.name
       f.close()
       print '\t',f_tab.name
       f_tab.close()



