"""
Draw Pretty Plots ...
"""

__author__ = 'Stahlman Jonathan'
__email__ = 'stahlman@cern.ch'
__date__ = 'November 2011'

#-----------------------------------------------------------------------------

import sys
if not sys.argv.count('-i') and not sys.argv.count('-b'):
    sys.argv.append('-b')

import math
from ROOT import *
from PlotUtils import *
from AnalysisRoutines import *
import glob
from array import array

def main():

  ROOT.gROOT.LoadMacro("AtlasStyle.C");
  ROOT.gROOT.LoadMacro("AtlasUtils.C");
  SetAtlasStyle()

  #tag='2012'
  #tag='2011'
  #tag='2011and2012'
  tag='test'
  #tag = 'H125'

  tree_name = "inclusive"

  #inputDir2 = "/local_data1/stahlman/output/HSG2_output/06022013/"
  #inputDir = "/local_data1/stahlman/output/HSG2_output/Moriond/"
  #inputDir = "/disk/userdata00/atlas_data2/stahlman/output/Moriond/minitrees/v02/"
  #inputDir =  "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/v03/";
  inputDir =  "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/MiniTrees/Test_v09/"

  #outputDir = inputDir + "Plots/";
  #outputDir = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Plots/";
  outputDir = "/disk/userdata00/atlas_data2/stahlman/output/test/";

  signal_masses = [123,124,125,126,127]
  #signal_masses = [124,125]

  ZZ_SF = 1.0
  signal_SF = 1.0

  maxes = []

  for signal_mass in signal_masses:

    #Find input ------------------------------------------------------------------------------------------------------------

    ZZ_file_names = []
    ZZ_file_names.extend(glob.glob(inputDir + '../v03/MC12a/*ZZ*.root'))
    print 'Using ZZ files:'
    for ZZ_file in ZZ_file_names: print ZZ_file

    signal_file_names = []
    signal_file_names.extend(glob.glob(inputDir + '/MC12a/Signal/*H'+str(signal_mass)+'*.root'))
    print 'Using signal files:'
    for signal_file in signal_file_names: print signal_file

    red_mu_file_names = []
    red_mu_file_names.append(inputDir + "../v04/Reducible/redBkg.root")

    red_el_file_names = []
    red_el_file_names.append(inputDir + "../v04/Reducible/redBkg_llee.root")

    print 'Using reducible files:'
    for r_file in red_mu_file_names+red_el_file_names: print r_file
    reducible_bkg_fullmass_yield  = [2.5, 2.1, 2.3, 2.6 ] #per channel yield


    signal_xsection = 0
    if (signal_mass == 123):signal_xsection = 23.047
    if (signal_mass == 124):signal_xsection = (19.57 + 1.595 + 0.7240 + 0.4260 + 0.1324) #pb; mH=124 GeV 
    if (signal_mass == 125):signal_xsection = (19.27 + 1.578 + 0.7046 + 0.4153 + 0.1293) #pb; mH=125 GeV 
    if (signal_mass == 126):signal_xsection = (18.97 + 1.568 + 0.6861 + 0.4051 + 0.1262) #pb; mH=126 GeV 
    if (signal_mass == 127):signal_xsection = 21.634

    branching_ratio = 0.0 #BR for H->4l; l=e,mu
    if (signal_mass == 123): branching_ratio = 0.000103
    if (signal_mass == 124): branching_ratio = 0.000114
    if (signal_mass == 125): branching_ratio = 0.000125
    if (signal_mass == 126): branching_ratio = 0.000136
    if (signal_mass == 127): branching_ratio = 0.000148

    int_lumi = 20277 #pb-1

    prod_yield = int_lumi*signal_xsection*branching_ratio


    #Retrieve trees ------------------------------------------------------------------------------------------------------------
    print 'Retrieving trees from files:'

    ZZ_chain     = GetChain(tree_name,     ZZ_file_names)
    red_mu_chain = GetChain("mt_muon",     red_mu_file_names)
    red_el_chain = GetChain("mt_electron", red_el_file_names)

    signal_chain = GetChain(tree_name, signal_file_names)

    #Open Output File ------------------------------------------------------------------------------------------------------------

    fout = TFile(outputDir + "MassWindowStudy_H"+str(signal_mass)+"_"+tag+".root", "RECREATE")
    fout.cd()

    #Define derived histograms ------------------------------------------------------------------------------------------------------------
    print 'Defining derived histograms'

    xbins = 300
    xmin  = 110
    xmax  = 140

    hists = []

    h_ZZ_yield     = TH1F("h_ZZ_yield",    ";m_{4l} [GeV];events",xbins, xmin, xmax); hists.append(h_ZZ_yield)
    h_red_mu_yield = TH1F("h_red_mu_yield",";m_{4l} [GeV];events",xbins, xmin, xmax); hists.append(h_red_mu_yield)
    h_red_el_yield = TH1F("h_red_el_yield",";m_{4l} [GeV];events",xbins, xmin, xmax); hists.append(h_red_el_yield)
    h_signal_yield = TH1F("h_signal_yield",";m_{4l} [GeV];events",xbins, xmin, xmax); hists.append(h_signal_yield)

    hists_2d = []
    h2_signal_yield    = TH2F("h2_signal_yield",	";m_{4l}^{lower} [GeV];m_{4l}^{higher} [GeV]; events",		xbins, xmin, xmax,xbins, xmin, xmax); hists_2d.append(h2_signal_yield)
    h2_bkg_yield       = TH2F("h2_bkg_yield",	";m_{4l}^{lower} [GeV];m_{4l}^{higher} [GeV]; events",		xbins, xmin, xmax,xbins, xmin, xmax); hists_2d.append(h2_bkg_yield)
    h_significance     = TH2F("h_significance",	";m_{4l}^{lower} [GeV];m_{4l}^{higher} [GeV]; S/#sqrt{B}",		xbins, xmin, xmax,xbins, xmin, xmax); hists_2d.append(h_significance)
    h_significance_alt = TH2F("h_significance_alt",	";m_{4l}^{lower} [GeV];m_{4l}^{higher} [GeV]; S/#sqrt{S+B}",	xbins, xmin, xmax,xbins, xmin, xmax); hists_2d.append(h_significance_alt)
    h_purity           = TH2F("h_purity",		";m_{4l}^{lower} [GeV];m_{4l}^{higher} [GeV]; S/(S+B)",		xbins, xmin, xmax,xbins, xmin, xmax); hists_2d.append(h_purity)
    h_eff              = TH2F("h_eff",		";m_{4l}^{lower} [GeV];m_{4l}^{higher} [GeV]; #epsilon",	xbins, xmin, xmax,xbins, xmin, xmax); hists_2d.append(h_eff)
    h_purity_x_eff     = TH2F("h_purity_x_eff",	";m_{4l}^{lower} [GeV];m_{4l}^{higher} [GeV]; purity*#epsilon",	xbins, xmin, xmax,xbins, xmin, xmax); hists_2d.append(h_purity_x_eff)
    h_z0               = TH2F("h_z0",		";m_{4l}^{lower} [GeV];m_{4l}^{higher} [GeV]; Z_{A}",		xbins, xmin, xmax,xbins, xmin, xmax); hists_2d.append(h_z0)

    for hist in hists: hist.Sumw2()

    #Fill histograms ------------------------------------------------------------------------------------------------------------

    #mass_variable  = 'm4l_unconstrained'
    mass_variable  = 'm4l_constrained'

    ZZ_chain.Draw(    mass_variable+' >> h_ZZ_yield',     "weight*"+str(ZZ_SF), "goff");
    red_mu_chain.Draw(mass_variable+' >> h_red_mu_yield', "weight", "goff")
    red_el_chain.Draw(mass_variable+' >> h_red_el_yield', "weight_TF", "goff")
    signal_chain.Draw(mass_variable+' >> h_signal_yield', "weight*"+str(signal_SF), "goff");

    #Normalize reducible estimates
    h_red_mu_yield.Scale((reducible_bkg_fullmass_yield[0]+reducible_bkg_fullmass_yield[3]) / h_red_mu_yield.Integral(0,xbins+1))
    h_red_el_yield.Scale((reducible_bkg_fullmass_yield[1]+reducible_bkg_fullmass_yield[2]) / h_red_el_yield.Integral(0,xbins+1))

    #Calculate variables as a function of mass cuts
    for i in range(xbins):
      for j in range(xbins):

	if (i >= j): continue
	bkg_yield    = h_ZZ_yield.Integral(i+1,j+1) + h_red_mu_yield.Integral(i+1,j+1) + h_red_el_yield.Integral(i+1,j+1)
	signal_yield = h_signal_yield.Integral(i+1,j+1)

	sig = 0

	if (bkg_yield != 0):
	  sig = signal_yield / sqrt(bkg_yield)
	h2_signal_yield.SetBinContent(i+1,j+1,signal_yield)
	h2_bkg_yield.SetBinContent(i+1,j+1,bkg_yield)
	h_significance.SetBinContent(i+1,j+1,sig)
	h_significance_alt.SetBinContent(i+1,j+1,signal_yield/sqrt(signal_yield+bkg_yield))
	h_purity.SetBinContent(i+1,j+1,signal_yield/(signal_yield+bkg_yield))
	h_eff.SetBinContent(i+1,j+1,signal_yield/prod_yield)
	h_purity_x_eff.SetBinContent(i+1,j+1,signal_yield/(signal_yield+bkg_yield)*signal_yield/prod_yield)
	h_z0.SetBinContent(i+1,j+1,sqrt(2*((signal_yield+bkg_yield)*log(1+signal_yield/bkg_yield) - signal_yield)))

    binx = Long(0)
    biny = Long(0)
    binz = Long(0)

    print "-----------------------------------------------------------------------------------------------------------------------"
    print "M_H =",signal_mass, mass_variable
    print "-----------------------------------------------------------------------------------------------------------------------"
    print "Metric\t\t| Optimal ( Default )\t| Mass Window\t\t| N_Signal\t | N_Background"
    print "-----------------------------------------------------------------------------------------------------------------------"

    def_bin = h2_signal_yield.FindBin(115,130)

    h_significance.GetMaximumBin(binx, biny, binz)
    print "S/sqrt(B) \t| ",round(h_significance.GetMaximum(),2),
    print "(",round(h_significance.GetBinContent(def_bin),2),")\t| ",
    print h_significance.GetXaxis().GetBinLowEdge(binx),' - ', h_significance.GetYaxis().GetBinLowEdge(biny+1),"\t| ",
    print round(h2_signal_yield.GetBinContent(binx,biny,binz),2),"\t| ",
    print round(h2_bkg_yield.GetBinContent(binx,biny,binz),2)
    x_min_bin = binx
    x_max_bin = binx
    y_min_bin = biny
    y_max_bin = biny

    h_significance_alt.GetMaximumBin(binx, biny, binz)
    print "S/sqrt(S+B) \t| ",round(h_significance_alt.GetMaximum(),2),
    print "(",round(h_significance_alt.GetBinContent(def_bin),2),")\t| ",
    print h_significance_alt.GetXaxis().GetBinLowEdge(binx),' - ', h_significance_alt.GetYaxis().GetBinLowEdge(biny+1),"\t| ",
    print round(h2_signal_yield.GetBinContent(binx,biny,binz),2),"\t| ",
    print round(h2_bkg_yield.GetBinContent(binx,biny,binz),2)
    x_min_bin = min(binx, x_min_bin) 
    x_max_bin = max(binx, x_max_bin)
    y_min_bin = min(biny, y_min_bin) 
    y_max_bin = max(biny, y_max_bin)

    maxes.append((h_significance_alt.GetXaxis().GetBinLowEdge(binx), h_significance_alt.GetYaxis().GetBinLowEdge(biny+1)))

    h_purity_x_eff.GetMaximumBin(binx, biny, binz)
    print "Pur*eff \t| ",round(h_purity_x_eff.GetMaximum(),2),
    print "(",round(h_purity_x_eff.GetBinContent(def_bin),2),")\t| ",
    print h_purity_x_eff.GetXaxis().GetBinLowEdge(binx),' - ', h_purity_x_eff.GetYaxis().GetBinLowEdge(biny+1), "\t| ",
    print round(h2_signal_yield.GetBinContent(binx,biny,binz),2),"\t| ",
    print round(h2_bkg_yield.GetBinContent(binx,biny,binz),2)
    x_min_bin = min(binx, x_min_bin) 
    x_max_bin = max(binx, x_max_bin)
    y_min_bin = min(biny, y_min_bin) 
    y_max_bin = max(biny, y_max_bin)

    print "Default \t| ",
    print " --- \t\t| ",
    print '115.0  -  130.0\t| ',
    print round(h2_signal_yield.GetBinContent(def_bin),2),"\t| ",
    print round(h2_bkg_yield.GetBinContent(def_bin),2)

    alt_bin = h2_signal_yield.FindBin(119,129)
    print "Alternate \t| ",
    print " --- \t\t| ",
    print '119.0  -  129.0\t| ',
    print round(h2_signal_yield.GetBinContent(alt_bin),2),"\t| ",
    print round(h2_bkg_yield.GetBinContent(alt_bin),2)

    print "-----------------------------------------------------------------------------------------------------------------------"

    hzz_label = 'H#rightarrow ZZ^{(*)}#rightarrow4l'
    atlas_label_text = 'Internal'

    bin_width_gev = xbins / (xmax-xmin)

    x_min_bin = x_min_bin - 8*bin_width_gev if  x_min_bin - 8*bin_width_gev >= 0 else 0
    x_max_bin = x_max_bin + 8*bin_width_gev if  x_max_bin + 8*bin_width_gev <= xbins else xbins

    y_min_bin = y_min_bin - 4*bin_width_gev if  y_min_bin - 4*bin_width_gev >= 0 else 0
    y_max_bin = y_max_bin + 8*bin_width_gev if  y_max_bin + 8*bin_width_gev <= xbins else xbins

    for hist in hists_2d:
	  canvas = TCanvas('c_'+hist.GetName(),'',800,600)      
          canvas.SetRightMargin(0.18)
	  hist.GetXaxis().SetRange( x_min_bin,x_max_bin)
	  hist.GetYaxis().SetRange( y_min_bin,y_max_bin)

	  hist.SetMinimum( hist.GetMaximum()*0.9 )

	  Plot2DMap(hist)

	  ATLAS_Label(atlas_label_text)
	  ADD_LABEL(hzz_label)
	  label = "M_{H} = "+str(signal_mass)+" GeV"
	  ADD_LABEL(label, 0.76)
	  canvas.Write()
	  #canvas.Print(outputDir+'/Plots/'+canvas.GetName()+'.eps')

    for hist in hists+hists_2d: hist.Write()

    print 'Closing output file: '
    print '\t',fout.GetPath().rstrip(':/')
    fout.Close()

  #make summary plot
  fout = TFile(outputDir + "/MassWindowStudy_Summary_"+tag+".root", "RECREATE")
  fout.cd()

  makeContourPlot('h_significance', 	signal_masses, outputDir, fout, tag)
  makeContourPlot('h_significance_alt', signal_masses, outputDir, fout, tag)
  makeContourPlot('h_z0', 		signal_masses, outputDir, fout, tag)

  print 'Closing output file: '
  print '\t',fout.GetPath().rstrip(':/')
  fout.Close()


def makeContourPlot(hist_name, signal_masses, outputDir, fout, tag ): 

  hzz_label = 'H#rightarrow ZZ^{(*)}#rightarrow4l'
  atlas_label_text = 'Internal'

  canvas = TCanvas('c_'+hist_name+'_masses','',800,600)   
  contours = []  
  contours_995 = [] 
  for i in range(len(signal_masses)):

    signal_mass = signal_masses[i]

    fin = TFile(outputDir + "MassWindowStudy_H"+str(signal_mass)+"_"+tag+".root")
    hist = fin.Get(hist_name).Clone(hist_name+"_"+str(signal_mass))
    hist.GetXaxis().SetRangeUser( 110 , 140)
    hist.GetYaxis().SetRangeUser( 110 , 140)

    hist.SetContour(1)
    hist.SetContourLevel(0,hist.GetMaximum()*0.975)
    hist.Draw("CONTZ LIST")
    gPad.Update(); 
    conts = gROOT.GetListOfSpecials().FindObject("contours");
    for j in range(conts.GetSize()):      
	contLevel = conts.At(j);
	contours.append(contLevel.At(0).Clone("contour_975_"+str(signal_mass)))  
    hist.Draw()   

    hist.SetContourLevel(0,hist.GetMaximum()*0.995)
    hist.Draw("CONTZ LIST")
    gPad.Update(); 
    conts = gROOT.GetListOfSpecials().FindObject("contours");
    for j in range(conts.GetSize()):      
	contLevel = conts.At(j);
	contours_995.append(contLevel.At(0).Clone("contour_995_"+str(signal_mass)))  

    #draw hist one last time for correct range for final plot
    hist.GetXaxis().SetRangeUser( 111 , 126)
    hist.GetYaxis().SetRangeUser( 120 , 140)
    hist.Draw()   
  
  fout.cd()
  
  #canvas = TCanvas('Significance','',800,600)   
  legend = NewLegend(len(contours), "tr")
  markers = []
  for i in range(len(contours)):
    contours[i].SetLineColor(i+1)
    contours[i].SetMarkerColor(i+1)
    #contours[i].Draw("C" + ("SAME" if i!=0 else "A"))
    contours[i].Draw("CSAME")
    legend.AddEntry(contours[i], 'M_{H} = ' + str(signal_masses[i]) + " GeV", 'L')


  print '--------------------------------------------------'
  print "Mass\t| Mass Windows for "+hist_name
  print '--------------------------------------------------'
  for i in range(len(contours_995)):
    #calculate average coordinate
    n_points = contours_995[i].GetN()
    x_avg = 0 
    y_avg = 0
    x = Double(0)
    y = Double(0)
    for j in range(n_points):
      contours_995[i].GetPoint(j, x, y)
      x_avg += x
      y_avg += y
    x_avg = x_avg / n_points
    y_avg = y_avg / n_points

    #markers.append(TMarker(maxes[i][0],maxes[i][1],29))
    markers.append( TMarker(x_avg , y_avg, 29))
    markers[i].SetMarkerColor(i+1)
    markers[i].SetMarkerSize(1.5)
    markers[i].Draw("SAME")
    print signal_masses[i],'\t|',round(x_avg,1),'-',round(y_avg,1)

  FormatLegend(legend)
  legend.Draw()
  ATLAS_Label(atlas_label_text)
  ADD_LABEL(hzz_label)
  canvas.Write()


if __name__ == '__main__' :
    main()

