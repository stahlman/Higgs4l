#// make and test  Poisson model
#
import ROOT
from ROOT import *
from numpy import *
from variables import *
#from sets import Set
#gInterpreter.GenerateDictionary("std::map<std::string, RooDataSet*>", "map;string;RooDataSet.h")


inputDir       = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Plots/";
systematicDir  = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Systematics/v03/"
outputDir      = "/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Workspaces/"

#name_poi = 'nreco'
#name_poi = 'ntrue'
#name_poi = 'dsigmadx'
name_poi = 'mu'

def main():
 
  #for i in range(len(variables)): 
  #  makeWorkspace(i)
  makeWorkspace(1)

  print "Done"
 
  
def makeWorkspace(i_var):

  var_name = variables[i_var]
  n_bins = len(var_bins[i_var]) - 1
  
  fout  = TFile(outputDir+'/DifferentialWS.'+var_name+'.root',"RECREATE")
  
  ZZ_bkg_syst_file = systematicDir+ "/Systematics."+('inclusive' if var_jet[i_var] else var_name)+".ZZ.inclusive.txt"
  print "Using ZZ background systematics file:"
  print '\t', ZZ_bkg_syst_file
  ZZ_bkg_syst_names = loadtxt(ZZ_bkg_syst_file, usecols=[0], dtype=string).tolist()
  ZZ_bkg_syst_vals  = loadtxt(ZZ_bkg_syst_file, usecols=range(1, 2 if var_jet[i_var] else n_bins+1))

  red_bkg_syst_file = systematicDir+ "/Systematics."+var_name+".Reducible.inclusive.txt"
  print "Using red background systematics file:"
  print '\t',red_bkg_syst_file
  red_bkg_syst_names = loadtxt(red_bkg_syst_file, usecols=[0], dtype=string).tolist()
  red_bkg_syst_vals  = loadtxt(red_bkg_syst_file, usecols=range(1,n_bins+1))

  signal_syst_file = systematicDir+ "/Systematics."+var_name+".H125.inclusive.txt"
  print "Using signal systematics file:"
  print '\t',signal_syst_file
  signal_syst_names = loadtxt(signal_syst_file, usecols=[0], dtype=string).tolist()
  signal_syst_vals  = loadtxt(signal_syst_file, usecols=range(1,n_bins+1))

#TODO place holder until real systematics available
  theory_syst_names = ['dummy']
  theory_syst_vals  = [[0,0,0,0]]

  #declare workspace
  w = RooWorkspace("combined",true)
  
  syst_names = set()
  
  #global variables
  vars_global = ['lumi', 'branching_ratio', 'total_xsection']
  
  for var in vars_global:
    w.factory("expr::"+var+"('nom_"+var+"*(1+alpha_"+var+"*sigma_"+var+")',nom_"+var+"[0],alpha_"+var+"[0],sigma_"+var+"[0,-10,10])")
    syst_names.add(var)
    
  data_obs = RooArgSet()
  poi = RooArgSet()
  go = RooArgSet()
  
  #create PDF in each bin
  for i in range(n_bins):

    #bin width - constant, no systematics
    w.factory("bin_width_"+str(i)+"[1]")
    
    AddParameterWithSystematics(w, "b_ZZ_"+str(i),  ZZ_bkg_syst_names,  syst_names, go)
    AddParameterWithSystematics(w, "b_Red_"+str(i), red_bkg_syst_names,  syst_names, go)
    AddParameterWithSystematics(w, "cf_"+str(i),    signal_syst_names,  syst_names, go)
    AddParameterWithSystematics(w, "fiducial_acc_"+str(i),    theory_syst_names,  syst_names, go)
   
    w.factory("expr::dsigmadx_theory_"+str(i)+"('total_xsection*branching_ratio*fiducial_acc_"+str(i)+"/bin_width_"+str(i)+"', total_xsection,branching_ratio,fiducial_acc_"+str(i)+",bin_width_"+str(i)+")")

    #define s_i in terms of POI (choose POI here)
    #----------------------
    # n reco signal as poi
    if (name_poi == 'nreco'): 
      w.factory("s_"+str(i)+"[1.,0,100]")
      poi.add(w.var("s_"+str(i)))

    # n true signal as poi
    if (name_poi == 'ntrue'): 
      w.factory("expr::s_"+str(i)+"('ntrue_"+str(i)+"/cf_"+str(i)+"',ntrue_"+str(i)+"[1,0,100],cf_"+str(i)+")") 
      poi.add(w.var("ntrue_"+str(i)))

    # dsigma/dx as poi   
    if (name_poi == 'dsigmadx'): 
      w.factory("expr::s_"+str(i)+"('dsigmadx_"+str(i)+"/cf_"+str(i)+"*lumi*bin_width_"+str(i)+"',dsigmadx_"+str(i)+"[1,0,100],cf_"+str(i)+",lumi,bin_width_"+str(i)+")") 
      poi.add(w.var("dsigmadx_"+str(i)))
      
    # mu as poi   
    if (name_poi == 'mu'):
      w.factory("expr::s_"+str(i)+"('mu_"+str(i)+"/cf_"+str(i)+"*lumi*dsigmadx_theory_"+str(i)+"*bin_width_"+str(i)+"',mu_"+str(i)+"[1,0,100],cf_"+str(i)+",lumi,dsigmadx_theory_"+str(i)+",bin_width_"+str(i)+")") 
      poi.add(w.var("mu_"+str(i)))
          
    #----------------------

    #N_expected_i = S_i + B_ZZ_i + B_Red_i
    w.factory("sum::nexp_"+str(i)+"(s_"+str(i)+",b_ZZ_"+str(i)+",b_Red_"+str(i)+")")

    #poisson pdf for n_observed given n_expected (= S+B)
    w.factory("Poisson::pois_"+str(i)+"(nobs_"+str(i)+"[0],nexp_"+str(i)+", kTrue)");
    data_obs.add(w.var("nobs_"+str(i)))  
    
    w.pdf('pois_'+str(i)).setNoRounding() #only necessary to check that no bias observed when n_exp is not integer


  #create gaussian constraint on systematics
  prod_constraint = ''
  np = RooArgSet()
  #pdfs = RooArgList()
  for syst in syst_names:
    w.factory("Gaussian::constraint_"+syst+"(sigma_"+syst+",0,1)")
    prod_constraint +=  "constraint_"+syst+","
    np.add(w.var('sigma_'+syst))
    #w.var("sigma_"+syst).setConstant(True)      
  prod_constraint.rstrip(',')

  #create product of poisson pdf * constraints from each bin
  channels = RooCategory("master_channel","master_channel")
  for i in range(n_bins):
    w.factory("PROD::pdf_"+str(i)+"(pois_"+str(i)+','+prod_constraint+")")
    channels.defineType('bin_'+str(i))
  getattr(w,'import')(channels)
  
  #total pdf = product of poissons and gaussian constraints
  model = RooSimultaneous('comb_pdf', 'comb_pdf', channels)
  for i in range(n_bins): model.addPdf(w.pdf('pdf_'+str(i)), 'bin_'+str(i))
  getattr(w,'import')(model)

  #w.factory("RooProdPdf::model("+prod_poisson+prod_constraint+")");
  #w.factory("PROD::model("+prod_poisson+prod_constraint+")");  

  #Now, put in real numbers!
  #--------------------------------------------
  
  fin = TFile(inputDir+'/DifferentialMeasurement.'+var_name+'.test.root')

  total_xsection = 22.0972*1000 #fb
  branching_ratio = 0.000276

  #sig  = [4.54, 5.18, 3.26, 1.48]
  #zz   = [5.57, 2.86, 0.93, 0.17]
  #red  = [1.04, 1.23, 0.27, 0.02]
  #cf   = [ 1.2,  1.3,  1.4,  1.5]

  h_signal = fin.Get("h_signal_yield")
  #h_signal.Scale(10)
  h_ZZ     = fin.Get("h_ZZ_yield")
  h_red    = fin.Get("h_red_yield")
  
  h_cf = fin.Get("h_correction_factor")
  
  h_signal_total_diff_xsection  = fin.Get("h_signal_total_xsection")
  h_fiducial_acceptance         = fin.Get("h_fid_acceptance")
  h_fid_acc = h_fiducial_acceptance.Clone('h_fid_acc')
  for i in range(n_bins):
    bin_width = var_bins[i_var][i+1] - var_bins[i_var][i]
    sigma_times_br = h_signal_total_diff_xsection[i+1]*bin_width
    fraction = sigma_times_br / (total_xsection*branching_ratio)
    #print sigma_times_br, fraction
    h_fid_acc[i+1] = fraction*h_fiducial_acceptance[i+1]
  
  obs = [11, 9, 5, 2]
  h_obs = fin.Get("h_data_yield")
  
  # set example input variables
  #-------------------------------
  w.var('nom_lumi').setVal(20.277)
  w.var('alpha_lumi').setVal(0.028)

  w.var('nom_total_xsection').setVal(total_xsection)

  w.var('nom_branching_ratio').setVal(branching_ratio)

  for i in range(n_bins):
    
    bin_width = var_bins[i_var][i+1] - var_bins[i_var][i]
    
    if (name_poi == 'nreco'): 	 w.var("s_"+str(i)).setVal(h_signal[i+1])
    if (name_poi == 'ntrue'): 	 w.var("ntrue_"+str(i)).setVal(h_signal[i+1]*h_cf[i+1])    
    if (name_poi == 'dsigmadx'): w.var('dsigmadx_'+str(i)).setVal(h_signal[i+1]*h_cf[i+1]/20.277/bin_width)
    if (name_poi == 'mu'):	 w.var('mu_'+str(i)).setVal(1)
    
    w.var("nom_b_ZZ_"+str(i)).setVal(h_ZZ[i+1]);
    w.var("nom_b_Red_"+str(i)).setVal(h_red[i+1]);

    w.var("nom_cf_"+str(i)).setVal(h_cf[i+1])    
    w.var("nom_fiducial_acc_"+str(i)).setVal(h_fid_acc[i+1])

    w.var("bin_width_"+str(i)).setVal(bin_width)

    #systematics
    for j in range(len(ZZ_bkg_syst_names)):
      syst = ZZ_bkg_syst_names[j]
      val  = ZZ_bkg_syst_vals[j][i]/100
      symmetric = not(syst.endswith('Up') or syst.endswith('Dn'))
      syst_name = syst if symmetric else syst[:-2]
      if symmetric or syst.endswith('Up'): w.var("alpha_b_ZZ_" +str(i)+"_"+syst_name+'_up').setVal(val);
      if symmetric or syst.endswith('Dn'): w.var("alpha_b_ZZ_" +str(i)+"_"+syst_name+'_dn').setVal(val);

    for j in range(len(red_bkg_syst_names)):
      syst = red_bkg_syst_names[j]
      #val  = red_bkg_syst_vals[j][i]/100
      val = 0.01
      symmetric = not(syst.endswith('Up') or syst.endswith('Dn'))
      syst_name = syst if symmetric else syst[:-2]
      if symmetric or syst.endswith('Up'): w.var("alpha_b_Red_" +str(i)+"_"+syst_name+'_up').setVal(val);
      if symmetric or syst.endswith('Dn'): w.var("alpha_b_Red_" +str(i)+"_"+syst_name+'_dn').setVal(val);

    for j in range(len(signal_syst_names)):
      syst = signal_syst_names[j]
      val  = signal_syst_vals[j][i]/100
      symmetric = not(syst.endswith('Up') or syst.endswith('Dn'))
      syst_name = syst if symmetric else syst[:-2]
      if symmetric or syst.endswith('Up'): w.var("alpha_cf_" +str(i)+"_"+syst_name+'_up').setVal(val);
      if symmetric or syst.endswith('Dn'): w.var("alpha_cf_" +str(i)+"_"+syst_name+'_dn').setVal(val);

    
    #w.var("nobs_"+str(i)).setVal(h_obs[i+1]);
    #w.var("nobs_"+str(i)).setVal(obs[i]);
    #w.var("nobs_"+str(i)).setVal(h_signal[i+1]+h_ZZ[i+1]+h_red[i+1]);    
    w.var("nobs_"+str(i)).setVal(w.function('nexp_'+str(i)).getVal());

  #-------------------------------

  #print s and b estimates for convenience
  for i in range(n_bins):
     print 'bin ',i, 
     print 's= ', w.function('s_'+str(i)).getVal(), 
     print 'b= ', w.function('b_ZZ_'+str(i)).getVal()+w.function('b_Red_'+str(i)).getVal()
     

#  #  make data set
#  data_map = ROOT.std.map("string,RooDataSet*")()
#  for i in range(n_bins):
#    data_i = RooDataSet("asimovData_"+str(i), "asimovData_"+str(i), RooArgSet(w.var('nobs_'+str(i))))  
#    getattr(w,'import')(data_i)
#    data_map['bin_'+str(i)] = id(data_i)
#  data = RooDataSet("asimovData","asimovData",data_obs,RooFit.Index(channels), RooFit.Import(data_map));
#  #data.add( data_obs );
#  getattr(w,'import')(data)


  #make model config
  mc = RooStats.ModelConfig("ModelConfig",w);
  mc.SetPdf(w.pdf("comb_pdf"));
  mc.SetParametersOfInterest( poi );
  mc.SetObservables( data_obs );
  mc.SetSnapshot( poi );
  mc.SetNuisanceParameters( np );
  mc.SetGlobalObservables( go );
  getattr(w,'import')(mc);

  data = RooStats.AsymptoticCalculator.GenerateAsimovData(mc.GetPdf(), mc.GetObservables());
  data.SetName('asimovData')
  getattr(w,'import')(data)

  fout.cd()
  w.Write();
  w.Print()
  print 'Closing output file: '
  print fout.GetPath().rstrip(':/'), '\n'
  fout.Close();


  #quick test to make sure workspace is sensible
  w.pdf('comb_pdf').fitTo(data)

  #h_signal.Print("all")
  #h_ZZ.Print("all")
  #h_red.Print("all")

  #nll = w.pdf('model').createNLL(data)

  #frame1 = w.var('s_0').frame() 
  #nll.plotOn(frame1,RooFit.ShiftToZero()) 
  #c = TCanvas()
  #frame1.Draw()
  #c.Print('test.eps')

  #plc = RooStats.ProfileLikelihoodCalculator( w.data("obsData"), mc);
  #
  #
  #htr = plc.GetHypoTest();
  #if (htr):
  #  print "-------------------------------------------------" 
  #  print "The p-value for the null is " , htr.NullPValue() 
  #  print "Corresponding to a signifcance of " , htr.Significance() 
  #  print "-------------------------------------------------\n" 
  #
  #print "-------------------------------------------------" 
  #
  #lrint = plc.GetInterval();  #// that was easy.
  #lrint.SetConfidenceLevel(0.68);
  #bestfit  = lrint.GetBestFitParameters().getRealValue("s_0")
  #lower = lrint.LowerLimit(w.var('s_0'));
  #upper = lrint.UpperLimit(w.var('s_0'));
  #print "central value = ", bestfit
  #print "lower limit on master signal = ",  lower
  #print "upper limit on master signal = ",  upper
  #print "-------------------------------------------------\n" 
  
      
def AddParameterWithSystematics(w, par_name, syst_names, all_syst_names, go):

    prod = ''
    for syst in syst_names:
      if syst.endswith('Dn'): continue
      syst_name = syst[:-2] if syst.endswith('Up') else syst                 
      prod += "expr('1 + sigma_"+syst_name+"*(alpha_"+par_name+"_"+syst_name+"_up*(sigma_"+syst_name+">0) + alpha_"+par_name+"_"+syst_name+"_dn*(sigma_"+syst_name+"<0))',alpha_"+par_name+"_"+syst_name+"_up[0], alpha_"+par_name+"_"+syst_name+"_dn[0], sigma_"+syst_name+"[0,-10,10]),"
      all_syst_names.add(syst_name)
    prod = prod.rstrip(',')
    w.factory("prod::sf_"+par_name+"("+prod+")")
    w.factory("prod::"+par_name+"(nom_"+par_name+"[1], sf_"+par_name+")")
    go.add(w.var('nom_'+par_name))

if __name__ == '__main__' :
    main()

