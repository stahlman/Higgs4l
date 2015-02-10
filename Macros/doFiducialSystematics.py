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
import glob
#import re
from array import array

def main():

  ROOT.gROOT.LoadMacro("AtlasStyle.C");
  ROOT.gROOT.LoadMacro("AtlasUtils.C");
  SetAtlasStyle()

  #tag='2012'
  #tag='2011'
  #tag='2011and2012'
  label = 'test'; tag='test'

  #tree_name = "inclusive"

  #inputDir_fid  = "/local_data1/stahlman/output/HSG2_output/02052013/"
  #inputDir_fid  = "/disk/userdata00/atlas_data2/stahlman/output/02052013/"
  #inputDir_fid  = "/disk/userdata00/atlas_data2/stahlman/output/07102013/"
  inputDir_fid  = "/disk/userdata00/atlas_data2/stahlman/output/22102013/"

  #inputDir_reco = "/local_data1/stahlman/output/HSG2_output/02052013/";
  inputDir_reco  = "/disk/userdata00/atlas_data2/stahlman/output/04102013/"

  outputDir = inputDir_fid + "Plots/";


  var_name = 'inclusive'; 	var_bins = [0.5,1.5]
  #var_name = 'pt'; 		var_bins = [0,20,50,100,200]
  #var_name = 'rapidity'; 	var_bins = [0.0, 0.3, 0.65, 1.0, 1.4, 2.4]
  #var_name = 'njets'; 		var_bins = [-0.5, 0.5, 1.5, 2.5, 3.5]
  #var_name = 'leadingjetpt'; 	var_bins = [0, 30, 50, 80, 200]

  channels = ["4mu", "4e", "2mu2e", "2e2mu", "incl"]
  latex_channels = ["4#mu", "4e", "2#mu2e", "2e2#mu", "incl"]


  #Find input ------------------------------------------------------------------------------------------------------------

  #label = 'ggH, #sqrt{s} = 8 TeV'; tag='ggH'
  #label = 'ggH, #sqrt{s} = 8 TeV'; tag='ggH_Systematics'
  #label = 'VBFH, #sqrt{s} = 8 TeV'; tag='VBFH'
  #label = 'ZH, #sqrt{s} = 8 TeV'; tag='ZH'
  #label = 'WH, #sqrt{s} = 8 TeV'; tag='WH'
  #label = 'ttH, #sqrt{s} = 8 TeV'; tag='ttH'

  samples = []
  numbers =[]
  fid_filenames = []
  rec_filenames = []

  #samples.append("ggH110"); numbers.append("160152")
  #samples.append("ggH115"); numbers.append("160153")
  #samples.append("ggH120"); numbers.append("160154")
  #samples.append("ggH123"); numbers.append("167220")
  #samples.append("ggH124"); numbers.append("167222")
  samples.append("ggH125"); numbers.append("160155")
  #samples.append("ggH126"); numbers.append("167225")
  #samples.append("ggH127"); numbers.append("167227")
  ##samples.append("ggH130"); numbers.append("160156")
  #samples.append("ggH135"); numbers.append("160157")
  #samples.append("ggH140"); numbers.append("160158")
  #samples.append("ggH145"); numbers.append("160159")
  #samples.append("ggH150"); numbers.append("160160")
  #samples.append("ggH155"); numbers.append("160161")
  #samples.append("ggH160"); numbers.append("160162")

  #crosscheck
  #samples.append("ggH125"); numbers.append("160155")
  #samples.append("VBFH125"); numbers.append("160205")
  #samples.append("WH125"); numbers.append("160255")
  #samples.append("ZH125"); numbers.append("160305")


  for i in range(len(samples)):
    
    fid_filenames.append(glob.glob(inputDir_fid+"/*"+samples[i]+"*Fiducial*"+"/Job_*/*.root"))
    print "Using fiducial files for sample "+ samples[i]+':'
    for filename in fid_filenames[i]: print '\t',filename
    
    rec_filenames.append(glob.glob(inputDir_reco+"/*"+samples[i]+"*Nominal*"+"/Job_*/*.root"))
    print "Using reco files for sample "+ samples[i]+':'
    for filename in rec_filenames[i]: print '\t',filename



  #Open Output File ------------------------------------------------------------------------------------------------------------
  fout = TFile(outputDir + "FiducialSystematics."+var_name+'.'+tag+".root", "RECREATE")
  fout.cd()
  
  for s in range(len(samples)):
    
    fout.mkdir(samples[s])
    fout.cd(samples[s])
    
    #Retrieve trees ------------------------------------------------------------------------------------------------------------
    gen_tree = GetChain("gen_tree", fid_filenames[s])
    fid_tree = GetChain("output", fid_filenames[s])
    rec_tree = GetChain("output", rec_filenames[s])


    #Make Hists ------------------------------------------------------------------------------------------------------------
    print "Defining hists"

    n_var_bins = len(var_bins) - 1
    arr_var_bins = array( 'd', var_bins)
    n_qcd_syst = 13
    n_pdf_syst = 40 

    hists = []

    h_var_qcd_gen  = TH2F("h_"+var_name+"_qcd_gen", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_qcd_syst,-0.5,n_qcd_syst-0.5); hists.append(h_var_qcd_gen)
    h_var_qcd_fid  = TH2F("h_"+var_name+"_qcd_fid", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_qcd_syst,-0.5,n_qcd_syst-0.5); hists.append(h_var_qcd_fid)
    h_var_qcd_rec  = TH2F("h_"+var_name+"_qcd_rec", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_qcd_syst,-0.5,n_qcd_syst-0.5); hists.append(h_var_qcd_rec)

    h_var_qcd_rec_syst = TH1F("h_"+var_name+"_qcd_rec_syst",";"+var_name+";systematic (%)",n_var_bins,arr_var_bins); hists.append(h_var_qcd_rec_syst)
    h_var_qcd_fid_syst = TH1F("h_"+var_name+"_qcd_fid_syst",";"+var_name+";systematic (%)",n_var_bins,arr_var_bins); hists.append(h_var_qcd_fid_syst)
    h_var_qcd_gen_syst = TH1F("h_"+var_name+"_qcd_gen_syst",";"+var_name+";systematic (%)",n_var_bins,arr_var_bins); hists.append(h_var_qcd_gen_syst)

    h_var_qcd_eff  = TH2F("h_"+var_name+"_qcd_eff", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_qcd_syst,-0.5,n_qcd_syst-0.5); hists.append(h_var_qcd_eff)
    h_var_qcd_acc  = TH2F("h_"+var_name+"_qcd_acc", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_qcd_syst,-0.5,n_qcd_syst-0.5); hists.append(h_var_qcd_acc)

    h_var_qcd_eff_syst = TH1F("h_"+var_name+"_qcd_eff_syst",";"+var_name+";systematic (%)",n_var_bins,arr_var_bins); hists.append(h_var_qcd_eff_syst)
    h_var_qcd_acc_syst = TH1F("h_"+var_name+"_qcd_acc_syst",";"+var_name+";systematic (%)",n_var_bins,arr_var_bins); hists.append(h_var_qcd_acc_syst)

    h_var_pdf_gen  = TH2F("h_"+var_name+"_pdf_gen", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_pdf_syst,-0.5,n_pdf_syst-0.5); hists.append(h_var_pdf_gen)
    h_var_pdf_fid  = TH2F("h_"+var_name+"_pdf_fid", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_pdf_syst,-0.5,n_pdf_syst-0.5); hists.append(h_var_pdf_fid)
    h_var_pdf_rec  = TH2F("h_"+var_name+"_pdf_rec", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_pdf_syst,-0.5,n_pdf_syst-0.5); hists.append(h_var_pdf_rec)

    h_var_pdf_eff  = TH2F("h_"+var_name+"_pdf_eff", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_pdf_syst,-0.5,n_pdf_syst-0.5); hists.append(h_var_pdf_eff)
    h_var_pdf_acc  = TH2F("h_"+var_name+"_pdf_acc", ";"+var_name+";variation",     n_var_bins,arr_var_bins,n_pdf_syst,-0.5,n_pdf_syst-0.5); hists.append(h_var_pdf_acc)

    h_var_pdf_eff_syst = TH1F("h_"+var_name+"_pdf_eff_syst",";"+var_name+";systematic (%)",n_var_bins,arr_var_bins); hists.append(h_var_pdf_eff_syst)
    h_var_pdf_acc_syst = TH1F("h_"+var_name+"_pdf_acc_syst",";"+var_name+";systematic (%)",n_var_bins,arr_var_bins); hists.append(h_var_pdf_acc_syst)

    for hist in hists: hist.Sumw2()

    #Fill Hists ------------------------------------------------------------------------------------------------------------
    print "Filling Reco hists"

    for i in range(rec_tree.GetEntries()):
      rec_tree.GetEntry(i)
      
      #apply mass window cut
      if (rec_tree.m_4l < 120000 or rec_tree.m_4l > 130000): continue 
      
      value = variable(var_name,"reco",rec_tree)

      for j in range(n_qcd_syst):
	 h_var_qcd_rec.Fill(value, j, rec_tree.evt_weight*rec_tree.qcd_scale_weights[j])

      for j in range(n_pdf_syst):
	h_var_pdf_rec.Fill(value, j, rec_tree.evt_weight*rec_tree.pdf_weights[j])

    print "Filling Generated hists"

    for i in range(gen_tree.GetEntries()):
      gen_tree.GetEntry(i)

      value = variable(var_name,"gen",gen_tree)
      
      for j in range(n_qcd_syst):
	h_var_qcd_gen.Fill(value, j, gen_tree.evt_weight*gen_tree.qcd_scale_weights[j])

      for j in range(n_pdf_syst):
	h_var_pdf_gen.Fill(value, j, gen_tree.evt_weight*gen_tree.pdf_weights[j])

    print "Filling Fiducial hists"

    for i in range(fid_tree.GetEntries()):
      fid_tree.GetEntry(i)
      
      #apply mass window cut
      if (fid_tree.lep4_m < 120000 or fid_tree.lep4_m > 130000): continue 

      value = variable(var_name,"fid",fid_tree)

      for j in range(n_qcd_syst):
	h_var_qcd_fid.Fill(value, j, fid_tree.evt_weight*fid_tree.qcd_scale_weights[j])

      for j in range(n_pdf_syst):
	h_var_pdf_fid.Fill(value, j, fid_tree.evt_weight*fid_tree.pdf_weights[j])

#    print "Filling Reco hists"
#
#    for i in range(rec_tree.GetEntries()):
#      rec_tree.GetEntry(i)
#      value = variable(var_name,"reco",rec_tree)
#
#      for j in range(n_qcd_syst):
#	 h_var_qcd_rec.Fill(value, j, rec_tree.evt_weight*rec_tree.qcd_scale_weights[j])
#
#      for j in range(n_pdf_syst):
#	h_var_pdf_rec.Fill(value, j, rec_tree.evt_weight*rec_tree.pdf_weights[j])


    #Fill Derived Hists ------------------------------------------------------------------------------------------------------------
    print "Filling Derived hists"

    h_var_qcd_acc.Divide(h_var_qcd_fid,h_var_qcd_gen, 1,1,"B")
    h_var_qcd_eff.Divide(h_var_qcd_rec,h_var_qcd_fid)

    h_var_pdf_acc.Divide(h_var_pdf_fid,h_var_pdf_gen, 1,1,"B")
    h_var_pdf_eff.Divide(h_var_pdf_rec,h_var_pdf_fid)

    #calculate systematics ------------------------------------------------------------------------------------------------------------
    print "Final Results for sample ", samples[0]
    #print "-------------"

    for i in range(n_qcd_syst):
      for j in range(n_qcd_syst):
	 if i >= j: continue

	 for k in range(n_var_bins):
            diff = abs(h_var_qcd_rec.GetBinContent(k+1,i+1)  - h_var_qcd_rec.GetBinContent(k+1,j+1))/2 
            if (diff > h_var_qcd_rec_syst[k+1]): h_var_qcd_rec_syst[k+1] = diff
 
            diff = abs(h_var_qcd_fid.GetBinContent(k+1,i+1)  - h_var_qcd_fid.GetBinContent(k+1,j+1))/2 
            if (diff > h_var_qcd_fid_syst[k+1]): h_var_qcd_fid_syst[k+1] = diff
 
            diff = abs(h_var_qcd_gen.GetBinContent(k+1,i+1)  - h_var_qcd_gen.GetBinContent(k+1,j+1))/2 
            if (diff > h_var_qcd_gen_syst[k+1]): h_var_qcd_gen_syst[k+1] = diff

            diff = abs(h_var_qcd_eff.GetBinContent(k+1,i+1)  - h_var_qcd_eff.GetBinContent(k+1,j+1))/2 
            if (diff > h_var_qcd_eff_syst[k+1]): h_var_qcd_eff_syst[k+1] = diff

            diff = abs(h_var_qcd_acc.GetBinContent(k+1,i+1)  - h_var_qcd_acc.GetBinContent(k+1,j+1))/2 
            if (diff > h_var_qcd_acc_syst[k+1]): h_var_qcd_acc_syst[k+1] = diff

    for i in range(n_var_bins):  
      if (h_var_qcd_rec.GetBinContent(i+1,1) != 0):
	h_var_qcd_rec_syst.SetBinContent(i+1, h_var_qcd_rec_syst[i+1]/h_var_qcd_rec.GetBinContent(i+1,1)*100)
      
      if (h_var_qcd_fid.GetBinContent(i+1,1) != 0):
	h_var_qcd_fid_syst.SetBinContent(i+1, h_var_qcd_fid_syst[i+1]/h_var_qcd_fid.GetBinContent(i+1,1)*100)
      
      if (h_var_qcd_gen.GetBinContent(i+1,1) != 0):
	h_var_qcd_gen_syst.SetBinContent(i+1, h_var_qcd_gen_syst[i+1]/h_var_qcd_gen.GetBinContent(i+1,1)*100)
      
      if (h_var_qcd_eff.GetBinContent(i+1,1) != 0):
	h_var_qcd_eff_syst.SetBinContent(i+1, h_var_qcd_eff_syst[i+1]/h_var_qcd_eff.GetBinContent(i+1,1)*100)
      
      if (h_var_qcd_acc.GetBinContent(i+1,1) != 0):
	h_var_qcd_acc_syst.SetBinContent(i+1, h_var_qcd_acc_syst[i+1]/h_var_qcd_acc.GetBinContent(i+1,1)*100)

    #print"-------------"

    for i in range(n_pdf_syst/2):    
      for j in range(n_var_bins):  
	diff = h_var_pdf_eff.GetBinContent(j+1,2*i+1) - h_var_pdf_eff.GetBinContent(j+1,2*i+2)
	h_var_pdf_eff_syst[j+1] += (diff*diff)/2

 	diff = h_var_pdf_acc.GetBinContent(j+1,2*i+1) - h_var_pdf_acc.GetBinContent(j+1,2*i+2)
	h_var_pdf_acc_syst[j+1] += (diff*diff)/2

    for i in range(n_var_bins):
      if (h_var_pdf_eff[i+1] != 0):
	h_var_pdf_eff_syst[i+1] = sqrt(h_var_pdf_eff_syst[i+1]) / h_var_pdf_eff[i+1] *100

      if (h_var_pdf_acc[i+1] != 0):
	h_var_pdf_acc_syst[i+1] = sqrt(h_var_pdf_acc_syst[i+1]) / h_var_pdf_acc[i+1] *100

    for hist in hists: hist.Write()
  
  #end loop over samples

  print 'Closing output file: '
  print '\t',fout.GetPath().rstrip(':/')
  fout.Close()

  return
  
  
def variable(variable,f_type, f):

  if variable == "inclusive": return 1

  if variable == "pt":
    if (f_type == "gen" or f_type == "fid"):
      return f.higgs_pt / 1000.0
    if (f_type == "reco"):
      return f.pt_4l / 1000.0
    
  if variable == "rapidity":
    return abs(f.y4l_unconstrained)
   
  if variable == "njets":
    return f.n_jets_fid if f.n_jets_fid < 3 else 3

  if variable == "leadingjetpt":
    return f.leading_jet_pt_fid / 1000.0
  
  print "WARNING: Unknown variable "+variable+" with type "+f_type
  return 0

if __name__ == '__main__' :
    main()
