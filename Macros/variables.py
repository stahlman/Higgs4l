variables = []     
var_reco = []
var_mt = []    
var_name_mt = []
var_gen = []    
var_fid = []    
var_labels_reco = [] 
var_labels_truth = []
var_labels_simple = []
var_units = []    
var_bins = [] 
var_bins_CR1 = []   
var_jet = []
var_ZZshape_from_CR1 = []
var_latex = []

#-------------------------------------------------
variables.append('inclusive')
var_reco.append('1')
var_mt.append('1')
var_name_mt.append('1')
var_gen.append('1')
var_fid.append('1')
var_labels_reco.append('inclusive')
var_labels_truth.append('inclusive')
var_labels_simple.append('inclusive')
var_units.append('')
var_bins.append([0.5, 1.5])
var_bins_CR1.append([0.5, 1.5])
var_jet.append(False)
var_ZZshape_from_CR1.append(False)
var_latex.append( 'inclusive')

#-------------------------------------------------
variables.append('pt')
var_reco.append('pt_4l/1000.0')
var_mt.append('pt4l_unconstrained')
var_name_mt.append('pt4l_unconstrained')
var_gen.append('higgs_pt')
var_fid.append('lep4_pt/1000.0')
var_labels_reco.append('#it{p}_{T,4#font[12]{l}}')
var_labels_truth.append('#it{p}_{T,H}')
var_labels_simple.append('#it{p}_{T}')
var_units.append("GeV")
var_bins.append([0.0, 20.0, 50.0, 100.0, 200.0])
var_bins_CR1.append([0.0, 20.0, 50.0, 100.0, 200.0, 300.0])
var_jet.append(False)
var_ZZshape_from_CR1.append(False)
var_latex.append( '\\ptH\\')

#-------------------------------------------------
variables.append('rapidity')
var_reco.append("abs(y4l_unconstrained)")
var_mt.append('abs(y4l_unconstrained)')
var_name_mt.append('y4l_unconstrained')
var_gen.append('abs(higgs_rapidity)')
var_fid.append('abs(lep4_y)')
var_labels_reco.append('|#it{y}_{4#font[12]{l}}|')
var_labels_truth.append('|#it{y}_{H}|')
var_labels_simple.append('|#it{y}|')
var_units.append("")
var_bins.append([0.0, 0.3, 0.6, 0.9, 1.2, 2.4])
var_bins_CR1.append([0.0, 0.3, 0.6, 0.9, 1.2, 2.4])
var_jet.append(False)
var_ZZshape_from_CR1.append(False)
var_latex.append( '$|y|$')

#-------------------------------------------------
variables.append('m34')
var_reco.append("m_34/1000.0")
var_mt.append('mZ2_unconstrained')
var_name_mt.append('mZ2_unconstrained')
var_gen.append("born_paired_higgslep34_m")
var_fid.append("lep34_m/1000.0")
var_labels_reco.append('#it{m}_{34}')
var_labels_truth.append('#it{m}_{34}')
var_labels_simple.append('#it{m}_{34}')
var_units.append("GeV")
var_bins.append([12, 20, 30, 40, 60])
var_bins_CR1.append([ 40, 60, 80, 90, 100, 120])
var_jet.append(False)
var_ZZshape_from_CR1.append(False)
var_latex.append( '$m_{34}$')

#-------------------------------------------------
variables.append('costhetastar')
var_reco.append('abs(cthstr)')
var_mt.append('abs(cthstr)')
var_name_mt.append('cthstr')
var_gen.append("abs(born_paired_higgslep4_cthstr)")
var_fid.append("abs(lep4_cthstr)")
var_labels_reco.append('|cos #it{#theta}*_{4#font[12]{l}}|')
var_labels_truth.append('|cos #it{#theta}*|')
var_labels_simple.append('|cos #it{#theta}*|')
var_units.append("")
var_bins.append([0.0, 0.2, 0.4, 0.6, 0.8, 1.0])
var_bins_CR1.append([0.0, 0.2, 0.4, 0.6, 0.8, 1.0])
var_jet.append(False)
var_ZZshape_from_CR1.append(False)
var_latex.append( '$|cos\\theta^{*}|$' )

#-------------------------------------------------
variables.append('njets')
var_reco.append('(n_jets_fid)*(n_jets_fid<3) + 3*(n_jets_fid>=3)')
var_mt.append('(n_jets_fid)*(n_jets_fid<3) + 3*(n_jets_fid>=3)')
var_name_mt.append('n_jets_fid')
var_gen.append('(n_jets_truth_fid)*(n_jets_truth_fid<3) + 3*(n_jets_truth_fid>=3)')
var_fid.append('(n_jets_truth_fid)*(n_jets_truth_fid<3) + 3*(n_jets_truth_fid>=3)')
var_labels_reco.append('#it{n}_{jets}')
var_labels_truth.append('#it{n}_{jets}')
var_labels_simple.append('#it{n}_{jets}')
var_units.append('')
var_bins.append([-0.5, 0.5, 1.5, 2.5, 3.5])
var_bins_CR1.append([-0.5, 0.5, 1.5, 2.5, 3.5])
var_jet.append(True)
var_ZZshape_from_CR1.append(True)
var_latex.append( '\\njets\\' )

#-------------------------------------------------
variables.append('leadingjetpt')
var_reco.append('pt_leadingjet_fid/1000.0')
var_mt.append('0*(leading_jet_pt_fid==-999) + leading_jet_pt_fid*(leading_jet_pt_fid!=-999)')
var_name_mt.append('leading_jet_pt_fid')
var_gen.append("leading_jet_pt_truth_fid")
var_fid.append("pt_leadingjet_fid/1000.0")
var_labels_reco.append('#it{p}_{T}^{jet}')
var_labels_truth.append('#it{p}_{T}^{jet}')
var_labels_simple.append('#it{p}_{T}^{jet}')
var_units.append('GeV')
var_bins.append([0, 30, 50, 70, 140])
var_bins_CR1.append([0, 30, 50, 70, 140, 200])
var_jet.append(True)
var_ZZshape_from_CR1.append(True)
var_latex.append( '\\ptjet\\' )

#-------------------------------------------------


def myvariable(variable,f_type, f):

  if variable == "inclusive": 
     return 1

  if variable == "event_type":
    if (f_type == "gen"):  return f.event_type_truth
    if (f_type == "fid"):  return f.event_type_truth
    if (f_type == "reco"): return f.event_type_truth
    if (f_type == "mt"):   return f.event_type_truth

  if variable == "quad_type" or variable == "quad_type_mass_window":
    if (f_type == "gen"):  return f.event_type_truth
    if (f_type == "fid"):  return f.event_type_truth
    if (f_type == "reco"): return f.quad_type
    if (f_type == "mt"):   return f.quad_type

  if variable == "pt":
    if (f_type == "gen"):  return f.higgs_pt / 1000.0
    if (f_type == "fid"):  return f.higgs_pt / 1000.0
    if (f_type == "reco"): return f.pt_4l    / 1000.0
    if (f_type == "mt"):   return f.pt4l_unconstrained
    if (f_type == "fiducial_mt"):  return f.higgs_pt

  if variable == "rapidity":
    if (f_type == "gen"):  return abs(f.higgs_rapidity)
    if (f_type == "fid"):  return abs(f.higgs_rapidity)
    if (f_type == "reco"): return abs(f.y4l_unconstrained)
    if (f_type == "mt"):   return abs(f.y4l_unconstrained)
    if (f_type == "fiducial_mt"):  return abs(f.higgs_rapidity)

  if variable == "m34":
    if (f_type == "gen"):  return f.Z2_m    / 1000.0
    if (f_type == "fid"):  return f.lep34_m / 1000.0
    if (f_type == "reco"): return f.m_34    / 1000.0
    if (f_type == "mt"):   return f.mZ2_unconstrained 
    if (f_type == "fiducial_mt"):  return f.born_paired_higgslep34_m
  
  if variable == "costhetastar":
    if (f_type == "gen"):  return abs(f.higgs_cthstr)
    if (f_type == "fid"):  return abs(f.lep4_cthstr)
    if (f_type == "reco"): return abs(f.cthstr)
    if (f_type == "mt"):   return abs(f.cthstr) 
    if (f_type == "fiducial_mt"):  return abs(f.born_paired_higgslep4_cthstr)

  if variable == "njets":
    if (f_type == "gen"):  return f.n_jets_truth_fid if f.n_jets_truth_fid < 3 else 3
    if (f_type == "fid"):  return f.n_jets_truth_fid if f.n_jets_truth_fid < 3 else 3
    if (f_type == "reco"): return f.n_jets_fid if f.n_jets_fid < 3 else 3
    if (f_type == "mt"):   return f.n_jets_fid if f.n_jets_fid < 3 else 3
    if (f_type == "fiducial_mt"): return f.n_jets_truth_fid if f.n_jets_truth_fid < 3 else 3 

  if variable == "leadingjetpt":
    if (f_type == "gen"):  return f.pt_leadingjet_fid / 1000.0 if f.pt_leadingjet_fid > 0 else 0
    if (f_type == "fid"):  return f.pt_leadingjet_fid / 1000.0 if f.pt_leadingjet_fid > 0 else 0
    if (f_type == "reco"): return f.pt_leadingjet_fid / 1000.0 if f.pt_leadingjet_fid > 0 else 0
    if (f_type == "mt"):   return f.leading_jet_pt_fid if f.leading_jet_pt_fid > 0 else 0
    if (f_type == "fiducial_mt"): return f.leading_jet_pt_truth_fid if f.leading_jet_pt_truth_fid > 0 else 0

  print "WARNING: Unknown variable "+variable+" with type "+f_type
  return 0
