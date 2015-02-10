#// make and test  Poisson model
#
from ROOT import *


fout  = TFile('DifferentialWS.root',"RECREATE")

n_bins = 4

systematics = ['dummy']
n_systematics = len(systematics)

#name_poi = 'nreco'
#name_poi = 'ntrue'
name_poi = 'sigma'

#declare workspace
w = RooWorkspace("combined",true)

w.factory('nom_lumi[0]')
w.factory("expr::lumi('nom_lumi*(1+alpha_lumi*gamma_lumi)',nom_lumi,alpha_lumi[0],gamma_lumi[0,-10,10])")

data_obs = RooArgSet()
poi = RooArgSet()

#create PDF in each bin
for i in range(n_bins):
    
  #adding systematics
  #B_ZZ = ZZ_Nominal_i * SF_ZZ_i, where SF_ZZ_i = Product(1+alpha_ZZ_i_j * gamma_j), 
  #alpha_i_j gives relative strength of particular uncertainty in ith bin of ZZ and is constant
  #gamma_j gives strength of particular systematic (allows correlation between signal and background) and floats according to gaussian constraint - think of this as n-sigma fluctuation?
  
  prod = ''
  for j in range(n_systematics):
    prod += "sum(1,prod(alpha_ZZ_"+str(i)+"_"+systematics[j]+"[0],gamma_"+systematics[j]+"[0,-10,10])),"
  prod = prod.rstrip(',')
  w.factory("prod::sf_ZZ_"+str(i)+"("+prod+")")
  w.factory("prod::b_ZZ_"+str(i)+"(nom_ZZ_"+str(i)+"[0], sf_ZZ_"+str(i)+")")
    
  prod = ''
  for j in range(n_systematics):
    prod += "sum(1,prod(alpha_Red_"+str(i)+"_"+systematics[j]+"[0],gamma_"+systematics[j]+"[0,-10,10])),"
  prod = prod.rstrip(',')
  w.factory("prod::sf_Red_"+str(i)+"("+prod+")")
  w.factory("prod::b_Red_"+str(i)+"(nom_Red_"+str(i)+"[0], sf_Red_"+str(i)+")")

  #correction factor with systematics
  prod = ''
  for j in range(n_systematics):
    prod += "sum(1,prod(alpha_cf_"+str(i)+"_"+systematics[j]+"[0],gamma_"+systematics[j]+"[0,-10,10])),"
  prod = prod.rstrip(',')
  w.factory("prod::sf_cf_"+str(i)+"("+prod+")")
  w.factory("prod::cf_"+str(i)+"(nom_cf_"+str(i)+"[1], sf_cf_"+str(i)+")")
 
  #bin width - constant, no systematics
  w.factory("bin_width_"+str(i)+"[1]")
 
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
  if (name_poi == 'sigma'): 
    w.factory("expr::s_"+str(i)+"('sigma_"+str(i)+"/cf_"+str(i)+"*lumi*bin_width_"+str(i)+"',sigma_"+str(i)+"[1,0,100],cf_"+str(i)+",lumi,bin_width_"+str(i)+")") 
    poi.add(w.var("sigma_"+str(i)))
  #----------------------

  #N_expected_i = S_i + B_ZZ_i + B_Red_i
  w.factory("sum::nexp_"+str(i)+"(s_"+str(i)+",b_ZZ_"+str(i)+",b_Red_"+str(i)+")")
  
  #poisson pdf for n_observed given n_expected (= S+B)
  w.factory("Poisson::pois_"+str(i)+"(nobs_"+str(i)+"[0],nexp_"+str(i)+")");
  data_obs.add(w.var("nobs_"+str(i)))  
  
#create gaussian constraint on systematics
w.factory("Gaussian::constraint_gamma_lumi(gamma_lumi,0,1)")
prod_constraint = "constraint_gamma_lumi,"

for j in range(n_systematics):
  w.factory("Gaussian::constraint_gamma_"+systematics[j]+"(gamma_"+systematics[j]+",0,1)")
  prod_constraint +=  "constraint_gamma_"+systematics[j]+","

prod_constraint.rstrip(',')

#create product of poisson pdfs from each bin
prod_mod = ''
for i in range(n_bins):
  prod_mod += 'pois_'+str(i)+','

#total pdf = product of poissons and gaussian constraints
w.factory("PROD::model("+prod_mod+prod_constraint+")");


#example number inputs to WS
sig  = [4.54, 5.18, 3.26, 1.48]
zz   = [5.57, 2.86, 0.93, 0.17]
red  = [1.04, 1.23, 0.27, 0.02]

cf   = [ 1.2,  1.3,  1.4,  1.5]

bin_width = [1, 1, 1, 1]

# % uncertainties
zz_syst   = [2.13,  2.22,  2.34,  2.29]
red_syst  = [  10,     3,    30,   7.5]
cf_syst  = [2.29,   2.3,  2.35,  2.21]

obs = [11, 9, 5, 2]

# set example input variables
#-------------------------------
w.var('nom_lumi').setVal(20.277)
w.var('alpha_lumi').setVal(0.028)

for i in range(n_bins):

  #yields
  #w.var("s_"+str(i)).setVal(sig[i]*10)
  w.var("nom_ZZ_"+str(i)).setVal(zz[i]);
  w.var("nom_Red_"+str(i)).setVal(red[i]);
  
  w.var("nobs_"+str(i)).setVal(sig[i]*10+zz[i]+red[i]);
  #w.var("nobs_"+str(i)).setVal(obs[i]);

  w.var("nom_cf_"+str(i)).setVal(cf[i])
  
  w.var("bin_width_"+str(i)).setVal(bin_width[i])

  #systematics
  for j in range(n_systematics):
    w.var("alpha_ZZ_" +str(i)+"_"+systematics[j]).setVal(zz_syst[i]/100);
    w.var("alpha_Red_"+str(i)+"_"+systematics[j]).setVal(red_syst[i]/100);
    w.var("alpha_cf_" +str(i)+"_"+systematics[j]).setVal(cf_syst[i]/100);

#-------------------------------

#  make data set
data = RooDataSet("obsData","", data_obs);
data.add( data_obs );
getattr(w,'import')(data)

#make model config
mc = RooStats.ModelConfig("ModelConfig",w);
mc.SetPdf(w.pdf("model"));
mc.SetParametersOfInterest( poi );
mc.SetObservables( data_obs );
mc.SetSnapshot(poi );
mc.SetNuisanceParameters( "gamma_dummy,gamma_lumi" );
mc.SetGlobalObservables( "nom_ZZ_0,nom_ZZ_1,nom_ZZ_2,nom_ZZ_3,nom_Red_0,nom_Red_1,nom_Red_2,nom_Red_3" );
getattr(w,'import')(mc);


w.Write();
w.Print()
print 'Closing output file: '
print fout.GetPath().rstrip(':/')
fout.Close();

#quick test to make sure workspace is sensible
w.pdf('model').fitTo(data)

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

