from ROOT import *
from array import *
from variables import *
import glob
  
  
def make2DFiducialHistograms(sample, fid_files, rec_files, output_file, x_fid, x_rec, x_name, x_label, x_n, x_lo, x_hi, y_fid, y_rec, y_name, y_label, y_n, y_lo, y_hi, mass_window_lo=115, mass_window_hi = 130):

  #print 'make2DFiducialHistograms(): processing sample:', sample

  fid_chain = GetChain("output",   fid_files)  
  gen_chain = GetChain("gen_tree", fid_files)  
  rec_chain = GetChain("output",   rec_files)
        
  #Define derived histograms ------------------------------------------------------------------------------------------------------------
  hists = []

  h_gen_name = "h_"+x_name+"_"+y_name+"_gen"
  h_fid_name = "h_"+x_name+"_"+y_name+"_fid"
  h_rec_name = "h_"+x_name+"_"+y_name+"_rec"

  h_gen = TH2F(h_gen_name, ";"+x_label+";"+y_label, x_n,x_lo,x_hi,y_n,y_lo,y_hi);hists.append(h_gen)
  h_fid = TH2F(h_fid_name, ";"+x_label+";"+y_label, x_n,x_lo,x_hi,y_n,y_lo,y_hi);hists.append(h_fid)
  h_rec = TH2F(h_rec_name, ";"+x_label+";"+y_label, x_n,x_lo,x_hi,y_n,y_lo,y_hi);hists.append(h_rec)

  h_total_efficiency	= TH2F("h_"+x_name+"_"+y_name+"_total_efficiency",    ";"+x_label+";"+y_label+';#epsilon', x_n,x_lo,x_hi,y_n,y_lo,y_hi);hists.append(h_total_efficiency)
  h_fiducial_efficiency = TH2F("h_"+x_name+"_"+y_name+"_fiducial_efficiency", ";"+x_label+";"+y_label+';#epsilon', x_n,x_lo,x_hi,y_n,y_lo,y_hi);hists.append(h_fiducial_efficiency)
  h_fiducial_acceptance = TH2F("h_"+x_name+"_"+y_name+"_fiducial_acceptance", ";"+x_label+";"+y_label+';#epsilon', x_n,x_lo,x_hi,y_n,y_lo,y_hi);hists.append(h_fiducial_acceptance)

  for hist in hists: 
    hist.Sumw2()
    #hist.GetXaxis().SetNdivisions(005)
    
  #Fill histograms ------------------------------------------------------------------------------------------------------------
  #print 'makeFiducialPtHistograms(): Filling derived histograms'

  gen_chain.Draw(y_fid+":"+x_fid+">>"+h_gen_name, "evt_weight")

  fid_chain.Draw(y_fid+":"+x_fid+">>"+h_fid_name, "(lep4_m<"+str(mass_window_hi*1000)+"&&lep4_m>"+str(mass_window_lo*1000)+")*evt_weight")

  rec_chain.Draw(y_rec+":"+x_rec+">>"+h_rec_name, "(m_4l<"+str(mass_window_hi*1000)+"&&m_4l>"+str(mass_window_lo*1000)+")*evt_weight")

  h_total_efficiency.Divide(h_rec,h_gen)
  h_fiducial_efficiency.Divide(h_rec,h_fid)
  h_fiducial_acceptance.Divide(h_fid,h_gen,1,1,"B")

  output_file.mkdir(sample)
  output_file.cd(sample)

  for hist in hists: hist.Write()
  
  return
  
  
def CalculateSystematic(syst_name, tree1, tree2, weight1, weight2, variable_name, variable_nom, variable_syst, bins):

  hists = []

  x_bins = array('d', bins)
  nbins = len(x_bins)-1

  h_nominal   = TH1F('h_'+variable_name+"_"+syst_name+"_nom",';'+variable_name+';yield',nbins, x_bins); hists.append(h_nominal)
  h_variation = TH1F('h_'+variable_name+"_"+syst_name+"_var",';'+variable_name+';yield',nbins, x_bins); hists.append(h_variation)
  h_syst      = TH1F('h_'+variable_name+"_"+syst_name+"_syst",';'+variable_name+';systematic (%)',nbins, x_bins); hists.append(h_syst) 
  h_norm_syst = TH1F('h_'+variable_name+"_"+syst_name+"_normsyst",';'+variable_name+';systematic (%)',nbins, x_bins); hists.append(h_norm_syst) 
  h_shape_syst= TH1F('h_'+variable_name+"_"+syst_name+"_shapesyst",';'+variable_name+';systematic (%)',nbins, x_bins); hists.append(h_shape_syst) 

  tree1.Draw(variable_nom  + ' >> h_'+variable_name+"_"+syst_name+"_nom",weight1,"goff")
  tree2.Draw(variable_syst + ' >> h_'+variable_name+"_"+syst_name+"_var",weight2,"goff")

  nominal_yield   = h_nominal.Integral(0,nbins+1)
  variation_yield = h_variation.Integral(0,nbins+1)
  norm_syst = (variation_yield - nominal_yield) / nominal_yield * 100 if nominal_yield != 0 else 0
   
  for i in range(nbins):  
    h_norm_syst[i+1] = norm_syst
    
    h_syst[i+1] = (h_variation[i+1] - h_nominal[i+1]) / h_nominal[i+1] * 100 if h_nominal[i+1] != 0 else 0 
        
    normalized_yield = h_variation[i+1] / variation_yield * nominal_yield if variation_yield !=0 else 0
    h_shape_syst[i+1] = (normalized_yield - h_nominal[i+1]) / h_nominal[i+1] * 100 if h_nominal[i+1] != 0 else 0 
        
  return hists 
  
    
def CalculateMassSystematic(syst_name, tree1, tree2, weight):

  hists = []

  h_nominal   = TH1F('h_m4l_nom',';m4l;yield',500, 0, 500); hists.append(h_nominal)
  h_variation = TH1F('h_m4l_var',';m4l;yield',500, 0, 500); hists.append(h_variation)

  tree1.Draw('m4l_constrained >> h_m4l_nom',weight,"goff")
  tree2.Draw('m4l_constrained >> h_m4l_var',weight,"goff")  
   
  mean_nom = h_nominal.GetMean()
  mean_var = h_variation.GetMean()  
    
  return mean_var - mean_nom  

def ShapeSystematic(hist1, hist2, name):

  hist1_shape = Shape(hist1,'shape_1')
  hist2_shape = Shape(hist2,'shape_2')
  hist = hist1.Clone(name)
  hist.Reset()

  for i in range(hist.GetNbinsX()+2):  
    syst = 1    
    if (hist1_shape[i] != 0):
      syst = abs( hist2_shape[i] - hist1_shape[i] ) / hist1_shape[i]   
    hist[i] = syst*100
    
  return hist  

def Shape(hist, name):
  shape = hist.Clone(name)
  integral = shape.Integral(0,hist.GetNbinsX()+1)
  if integral != 0: shape.Scale(1.0 / integral)
  return shape

  
def Significance(n_sig, n_bkg):
  sig = sqrt(2*((n_sig+n_bkg)*log(1+n_sig/n_bkg)-n_sig))
  return sig

def PtBin(pt):
  bin = (0*(pt<20000) + 1*(pt>=20000 and pt < 50000) + 2*(pt>=50000 and pt<100000) + 3*(pt>100000))
  return bin

def GetChain( tree_name, files):

  file_list = TFileCollection()
  for t_file in files:
     file_list.Add(t_file)
  
  trees = []   
  if (tree_name == "inclusive"):   
    trees = [ "tree_incl_4mu","tree_incl_2mu2e","tree_incl_2e2mu","tree_incl_4e" ];
  elif (tree_name == "mt_muon"):   
    trees = [ "tree_incl_4mu","tree_incl_2e2mu" ];
  elif (tree_name == "mt_electron"):   
    trees = [ "tree_incl_2mu2e","tree_incl_4e" ];
  else:
    chain = TChain(tree_name);
    chain.AddFileInfoList(file_list.GetList());    
    return chain
    
  chain= TChain("tree_incl");      
  for tree in trees:
    t_Chain = TChain(tree);
    t_Chain.AddFileInfoList(file_list.GetList());  
    t_Chain.SetName("tree_incl");
    chain.Add( t_Chain ); 
    t_Chain.Reset(); #needed to close files properly

  return chain


def find_element_in_list(element,list_element):
  try:
      index_element=list_element.index(element)
      return index_element
  except ValueError:
      return -1
