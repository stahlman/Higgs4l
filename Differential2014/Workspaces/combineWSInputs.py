#!/usr/bin/env python

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'March 2013'


#script to take input text files and save all numbers in ROOT histograms for HistFactory input

from ROOT import *
import glob
from variables import *


for var_i,var in enumerate(variables):

  print 'Processing variable: ', var
  
  input_file_names = glob.glob('./inputs/WorkspaceInput.'+var+'.*.txt')
  #print input_file_names

  fout = TFile('./data/WorkspaceInputs.'+var+'.root', 'RECREATE')

  for f_name in input_file_names:

    tokens = f_name.split('.')
    if len(tokens) != 5: 
      print tokens
      continue

    var_name = tokens[2]
    par_name = tokens[3]
    var_i    = variables.index(var_name)  

    with open(f_name, 'r') as par_file:

      for i,line in enumerate(par_file.readlines()):      
	vals = line.split()

	for j in range(1,len(vals)):	 

	  dir_name = 'bin_'+str(j-1)+'/' 	  
          if not fout.GetDirectory(dir_name): fout.mkdir(dir_name)
	  fout.cd(dir_name)

	  dir_name = par_name+'/' 	  
          if not gDirectory.GetDirectory(dir_name): gDirectory.mkdir(dir_name)
	  gDirectory.cd(dir_name)

	  if (i==0): #central values in first line
              hist = TH1F('nominal','',1,var_bins[var_i][j-1],var_bins[var_i][j])
	      hist[1] = float(vals[j])
	      hist.Write()
          else:	  
	      hist_nominal = gDirectory.Get('nominal')
	      
	      syst_name = vals[0]
              symmetric = not( syst_name.endswith('Up') or syst_name.endswith('Dn') or syst_name.endswith('_up') or syst_name.endswith('_down') )   
	      if not symmetric: syst_name = vals[0][:-2] 
	      
              if not gDirectory.GetDirectory('ATLAS_'+syst_name): gDirectory.mkdir('ATLAS_'+syst_name)
	      gDirectory.cd('ATLAS_'+syst_name)
 
	      if (symmetric):
	   	hist = TH1F('ATLAS_'+str(vals[0])+'_down',"",1,var_bins[var_i][j-1],var_bins[var_i][j])
		hist[1] = (1-float(vals[j])/100.)*hist_nominal[1]
	   	hist.Write()
		
		hist = TH1F('ATLAS_'+str(vals[0])+'_up',  "",1,var_bins[var_i][j-1],var_bins[var_i][j])   
		hist[1] = (1+float(vals[j])/100.)*hist_nominal[1]
	        hist.Write()
	      else:
		suffix = 'up' if vals[0].endswith('Up') or vals[0].endswith('_up') else 'down'
		
		hist = TH1F('ATLAS_'+syst_name+'_'+suffix,"",1,var_bins[var_i][j-1],var_bins[var_i][j])
		hist[1] = (1+float(vals[j])/100.)*hist_nominal[1]
		hist.Write()
          fout.cd() 
	  
  fout.Close()  

print 'Done'
