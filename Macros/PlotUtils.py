from ROOT import *

#-----------------------------------------------------------------------------
def PlotDerived( hist, isMC, format, same):
   
   FormatTH1(hist, isMC, format)
            
   hist.Draw('E0' + ' ' + ('SAME' if same else ''))
   
   return

#-----------------------------------------------------------------------------
def PlotGraph( hist, isMC, format=0, same=false):
   
   FormatGraph(hist, isMC, format)
            
   hist.Draw('PZ SAME' if same else 'APZ')
   
   return

#-----------------------------------------------------------------------------
def PlotBand( hist, isMC, format, same):
         
   FormatBand( hist, isMC, format)
    
   hist.Draw('E2' + ' ' + ('SAME' if same else ''))
      
   return


#-----------------------------------------------------------------------------
def PlotBox( hist, isMC, format, same):
   
   FormatBand( hist, isMC, format)
           
   hist.Draw('E2' + ' ' + ('SAME' if same else ''))
   
   hist_up = hist.Clone(hist.GetName()+"_up")
   for i in range(hist_up.GetNbinsX()):
     hist_up.SetBinContent(i+1, hist[i+1] + hist.GetBinError(i+1))
   hist_up.SetFillStyle(0)
   hist_up.Draw("HIST SAME")  
   SetOwnership(hist_up, False)
   
   hist_dn = hist.Clone(hist.GetName()+"_dn")
   for i in range(hist_up.GetNbinsX()):
     hist_dn.SetBinContent(i+1, hist[i+1] - hist.GetBinError(i+1))
   hist_dn.SetFillStyle(0)
   hist_dn.Draw("HIST SAME")  
   SetOwnership(hist_dn, False)

   return

#-----------------------------------------------------------------------------
def FormatBand( hist, isMC, format):

   hist.SetMarkerStyle(0)

   if (format == 1):
     hist.SetFillColor(17)
     hist.SetLineColor(17)
     hist.SetFillStyle(1001)
   if (format == 2):
     hist.SetFillColor(1)
     hist.SetLineColor(1)
     hist.SetFillStyle(3345)
   if (format == 3):
     hist.SetFillColor(1)
     hist.SetLineColor(1)
     hist.SetFillStyle(3354)
   if (format == 4):
     hist.SetFillColor(1)
     hist.SetLineColor(1)
     hist.SetFillStyle(3006)
   if (format == 5):
     hist.SetFillColor(kAzure-2)
     hist.SetLineColor(kAzure-2)
     hist.SetFillStyle(3013)
   if (format == 6):
     hist.SetFillColor(kAzure-3)
     hist.SetLineColor(kAzure-3)
     hist.SetFillStyle(3004)
   if (format == 7):
     hist.SetFillColor(kSpring-6)
     hist.SetLineColor(kSpring-6)
     hist.SetFillStyle(3006)
   if (format == 8):
     hist.SetFillColor(kOrange+9)
     hist.SetLineColor(kOrange+9)
     hist.SetFillStyle(3005)

#-----------------------------------------------------------------------------
def Plot2DMap(hist):

  marg = gStyle.GetPadRightMargin()
  gStyle.SetPadRightMargin(0.18)
       
  hist.GetYaxis().SetTitleOffset(1.0)
  hist.GetZaxis().SetTitleOffset(1.1)

  hist.Draw("colz")

  gStyle.SetPadRightMargin(marg)

  return
   
#-----------------------------------------------------------------------------
def NormalizeAndPlot( hist, isMC, format, same):
  
   if hist.Integral() > 0:
     norm = 1.0 / hist.Integral()
   else : norm = 1.0
   
   hist.Scale(norm)

   Plot( hist, isMC, format, same)
   
   return

#-----------------------------------------------------------------------------
def Plot( hist, isMC, format, same):
  
   FormatTH1(hist, isMC, format)
                
   hist.Draw(('HIST' if isMC else 'E1') + ' ' + ('SAME' if same else ''))

   if hist.GetFunction("fit_func"):
      func =  hist.GetFunction("fit_func")
      func.Draw("SAME")
  
   return


#-----------------------------------------------------------------------------
def FormatTH1(hist, isMC, format):
  
   hist.SetMarkerSize(1.2)

   if (isMC):
     if (format == 0):
       hist.SetLineColor(kBlack)
       hist.SetMarkerStyle(24)
       hist.SetMarkerColor(kBlack)
     if (format == 1):
       hist.SetLineColor(kRed)
       hist.SetMarkerStyle(25)
       hist.SetMarkerColor(kRed)
     if (format == 2):
       hist.SetLineColor(kBlue)
       hist.SetMarkerStyle(26)
       hist.SetMarkerColor(kBlue)
     if (format == 3):
       hist.SetLineColor(kGreen)
       hist.SetMarkerStyle(27)
       hist.SetMarkerColor(kGreen)
     if (format == 4):
       hist.SetLineColor(kOrange-3)
       hist.SetMarkerStyle(28)
       hist.SetMarkerColor(kOrange-3)
     if (format == 5):
       hist.SetLineColor(kViolet)
       hist.SetMarkerStyle(29)
       hist.SetMarkerColor(kViolet)            
     if (format == 6):
       hist.SetLineColor(kCyan-4)
       hist.SetMarkerStyle(30)
       hist.SetMarkerColor(kCyan-4)
     if (format == 7):
       hist.SetLineColor(kGreen-5)
       hist.SetMarkerStyle(31)
       hist.SetMarkerColor(kGreen-5)
     if (format == 8):
       hist.SetLineColor(kOrange-6)
       hist.SetMarkerStyle(32)
       hist.SetMarkerColor(kOrange-6)
     if (format == 9):
       hist.SetLineColor(kBlue-5)
       hist.SetMarkerStyle(32)
       hist.SetMarkerColor(kBlue-5)

   else:
     if (format == 0):
       hist.SetLineColor(kBlack)
       hist.SetMarkerColor(kBlack)
       hist.SetMarkerStyle(20)
     if (format == 1):
       hist.SetLineColor(kRed)
       hist.SetMarkerColor(kRed)
       hist.SetMarkerStyle(21)
     if (format == 2):
       hist.SetLineColor(kBlue)
       hist.SetMarkerColor(kBlue)
       hist.SetMarkerStyle(22)
     if (format == 3):
       hist.SetLineColor(kGreen)
       hist.SetMarkerStyle(23)
       hist.SetMarkerColor(kGreen)
     if (format == 4):
       hist.SetLineColor(kOrange-3)
       hist.SetMarkerStyle(24)
       hist.SetMarkerColor(kOrange-3)
   
   return


#-----------------------------------------------------------------------------
def FormatGraph(hist, isMC, format):
  
   hist.SetMarkerSize(1.2)

   if (isMC):
     if (format == 0):
       hist.SetLineColor(kBlack)
       hist.SetMarkerStyle(20)
       hist.SetMarkerColor(kBlack)
     if (format == 1):
       hist.SetLineColor(kRed)
       hist.SetMarkerStyle(21)
       hist.SetMarkerColor(kRed)
     if (format == 2):
       hist.SetLineColor(kBlue)
       hist.SetMarkerStyle(22)
       hist.SetMarkerColor(kBlue)
     if (format == 3):
       hist.SetLineColor(kGreen-3)
       hist.SetMarkerStyle(23)
       hist.SetMarkerColor(kGreen-3)
     if (format == 4):
       hist.SetLineColor(kOrange-3)
       hist.SetMarkerStyle(29)
       hist.SetMarkerColor(kOrange-3)
     if (format == 5):
       hist.SetFillColor(kAzure-2)
       hist.SetFillStyle(3013)

   if not isMC:
     if (format == 0):
       hist.SetLineColor(kBlack)
       hist.SetMarkerStyle(20)
       hist.SetMarkerColor(kBlack)
       hist.SetMarkerSize(1.2)

     if (format == 1):
       hist.SetLineColor(kBlack)
       hist.SetMarkerStyle(20)
       hist.SetMarkerColor(kBlack)
       hist.SetMarkerSize(1.0)
       
#-----------------------------------------------------------------------------
def FormatLegend(leg):
  leg.SetFillStyle(0)
  leg.SetShadowColor(0)
  leg.SetBorderSize(0)
  leg.SetLineColor(0)
  
  leg.SetTextSize(0.0305)
  
  n_entries = leg.GetNRows()
  if n_entries > 4:
    leg.SetNColumns(2)
    leg.SetX1(leg.GetX2()-(leg.GetX2()-leg.GetX1())*2)
    leg.SetY1(leg.GetY2()-n_entries/2*0.06)
  else:
    leg.SetY1(leg.GetY2()-n_entries*0.06)

  return

#-----------------------------------------------------------------------------
def FormatLeg(leg):
  leg.SetFillStyle(0)
  leg.SetShadowColor(0)
  leg.SetBorderSize(0)
  leg.SetLineColor(0)
  
  leg.SetTextSize(0.0305)

  return


#-----------------------------------------------------------------------------
def NewLegend(n_entries, location = 'tr'):
  
  xmin = 0.7
  xmax = 0.9
  ymin = 0.7
  ymax = 0.9

  if (location == 'trn'):
    xmin = 0.75
    xmax = 0.9
    ymin = 0.9 - 0.06*n_entries
    ymax = 0.9  
  if (location == 'tr'):
    xmin = 0.65
    xmax = 0.9
    ymin = 0.9 - 0.06*n_entries
    ymax = 0.9
  if (location == 'br'):
    xmin = 0.7
    xmax = 0.9
    ymin = 0.2
    ymax = 0.2 + 0.06*n_entries
  if (location == 'tl'):
    xmin = 0.2
    xmax = 0.4
    ymin = 0.8 - 0.06*n_entries
    ymax = 0.8
  if (location == 'bl'):
    xmin = 0.2
    xmax = 0.4
    ymin = 0.2
    ymax = 0.2 + 0.06*n_entries
    
  leg = TLegend(xmin, ymin, xmax,ymax)
  
  leg.SetFillStyle(0)
  leg.SetShadowColor(0)
  leg.SetBorderSize(0)
  leg.SetLineColor(0)
  
  return leg

#-----------------------------------------------------------------------------
def NewCanvas(name, ratio = false):

  canvas = TCanvas(name,'',800,600+(200 if ratio else 0))
  
  if (ratio):
     pad0 = TPad("pad", "pad", 0., 0., 1.,0.30);
     pad0.SetTopMargin(0.03);
     pad0.SetBottomMargin(0.4);
     pad0.SetFillColor(0);
     pad0.Draw();
     SetOwnership(pad0, False)

     pad1 = TPad("pad1", "pad", 0., 0.3, 1.,1.);
     pad1.SetBottomMargin(0);
     pad1.Draw();
     SetOwnership(pad1, False)
     
  return canvas

#-----------------------------------------------------------------------------
def MaxMin(hists):
  h_max = 0
  h_min = 0
  
  for hist in hists:
    l_max = hist.GetMaximum()
    l_min = hist.GetMinimum()

    for i in range(hist.GetNbinsX()):
      l_max = max(hist[i+1], l_max)
      l_min = min(hist[i+1], l_min)

    h_max = max( l_max, h_max)
    h_min = min( l_min, h_min)
  
  t_max = h_max
  t_min = h_min
  if (h_max > 0 and h_min >= 0):
    t_max = 2.5*h_max
    t_min = 0
    
  elif (h_max > 0 and h_min < 0):    
    t_max =  2.5*max(h_max, abs(h_min))
    t_min = -1.5*max(h_max, abs(h_min))
  
  for hist in hists:
    hist.SetMaximum(t_max)
    hist.SetMinimum(t_min)
     
  return  
  
#-----------------------------------------------------------------------------
def SliceTH2(hist, y_variable='', write=False):

   hists = []
   
   for bin in range(1, hist.GetNbinsX()+1):   
     hist_proj = hist.ProjectionY(hist.GetName() + "_" + str(hist.GetXaxis().GetBinLowEdge(bin)) + "_" + y_variable + "_" + str(hist.GetXaxis().GetBinUpEdge(bin)), bin, bin,"e")
     if (write): hist_proj.Write()
     hists.append(hist_proj)
   
   return hists

#-----------------------------------------------------------------------------
def CumulativeDistribution2D(hist):

  c_hist = hist.Clone(hist.GetName() + "_cumulative")
  #c_hist.Clear()
  
  c_hist.GetXaxis().SetTitle('Cut on ' + hist.GetXaxis().GetTitle())
  
  for i in range(1,hist.GetNbinsX()+1):
    for j in range(1,hist.GetNbinsY()+1):
      
      total = 0
      if (i==0):
         total = c_hist.GetBinContent(i,j-1)
	 total = total + hist.GetBinContent(i,j)
      if (j==0):
         total = c_hist.GetBinContent(i-1,j)
	 total = total + hist.GetBinContent(i,j)      
      else:
	 total = c_hist.GetBinContent(i-1,j)
	 total = total + c_hist.GetBinContent(i,j-1)
	 total = total - c_hist.GetBinContent(i-1,j-1)
	 total = total + hist.GetBinContent(i,j)
	 
      #total_check = hist.Integral(1,i,1,j)
      #if (total_check != 0):
      #  if ((total-total_check)/total_check > 0.0001): 
      #     print "ERROR: Mismatch in integral", total_check, total
      
      c_hist.SetBinContent(i,j,total)
         
  return c_hist

#-----------------------------------------------------------------------------
def CumulativeDistribution(hist):

  c_hist = hist.Clone(hist.GetName() + "_cumulative")
  #c_hist.Clear()
  
  c_hist.GetXaxis().SetTitle('Cut on ' + hist.GetXaxis().GetTitle())
  c_hist.GetYaxis().SetTitle(hist.GetYaxis().GetTitle())
  
  total = 0;
  for i in range(hist.GetNbinsX()+1):
     total += hist.GetBinContent(i);
     c_hist.SetBinContent(i,total)
         
  return c_hist

#-----------------------------------------------------------------------------
def FitMetHists(hists, width_hist, mean_hist):
   
   if not (len(hists) > 0):
      print "Histogram array empty" 
      return
         
   #f_gaus = TF1('fit_func',"gaus", -500,500)
   
   for i in range(0,len(hists)):

        if hists[i].Integral() > 0:
	  norm = 1.0 / hists[i].Integral()
	else : norm = 1.0

	hists[i].Scale(norm)
	
        #hists[i].Fit(f_gaus, "Q")
        
	#width_hist.SetBinContent(i+1,f_gaus.GetParameter(2))
        #width_hist.SetBinError(i+1,f_gaus.GetParError(2))
        
	#mean_hist.SetBinContent(i+1,f_gaus.GetParameter(1))
        #mean_hist.SetBinError(i+1,f_gaus.GetParError(1))
	
        params = []    
	IterativeGaussFit(hists[i],params)
	
	mean_hist.SetBinContent(i+1,params[0])
        mean_hist.SetBinError(i+1,params[1])
	
	width_hist.SetBinContent(i+1,params[2])
        width_hist.SetBinError(i+1,params[3])

   return

#-----------------------------------------------------------------------------
def IterativeGaussFit(hist, params):

  #constants for fitting algorithm
  min_entries = 0
  iteration_limit = 20
  percent_limit = 0.01
  fit_range_multiplier = 1.5
  fDebug = False
  
  
  #if (!hist) {
  #  if (fDebug) print  "Error in  Anp::IterativeGaussFit(): Histogram to be fit is missing" 
  #  return 1
  #}  
  
  if (hist.GetEntries() <= min_entries):
     params.append(0)
     params.append(0)
     params.append(0)
     params.append(0)
     if (fDebug): print "Not enough entries in histogram: " + hist.GetTitle()
     return 
  
  fit_func = TF1("fit_func","gaus")
  fit_func.SetLineColor(hist.GetLineColor())
  
  bad_fit = hist.Fit(fit_func,"QN")

  #if (fDebug and bad_fit) print "BAD INITIAL FIT: "+ hist.GetTitle()

  last_mu = fit_func.GetParameter(1) 
  last_sigma = fit_func.GetParameter(2)

  fit_func.SetRange(last_mu-fit_range_multiplier*last_sigma,last_mu+fit_range_multiplier*last_sigma)

  iteration = 0

  while ( iteration < iteration_limit ):

     iteration += 1

     bad_fit = hist.Fit(fit_func, "RQN")

     #if (fDebug and bad_fit) print "BAD FIT: bin "+ hist.GetTitle() +" iteration "+iteration

     current_mu = fit_func.GetParameter(1) 
     current_sigma = fit_func.GetParameter(2)

     fit_func.SetRange(current_mu-fit_range_multiplier*current_sigma,current_mu+fit_range_multiplier*current_sigma)

     #print "Iteration: "+iteration+" Current: "+current_mu+" "+current_sigma+" Last: "+last_mu+" "+last_sigma

     average_mu = (last_mu+current_mu)/2
     average_sigma = (last_sigma+current_sigma)/2

     if (average_mu == 0):
       if ( fDebug ):  print "Average mu = 0 in bin " + hist.GetTitle() + ' '+ str(last_mu)+" "+str(current_mu)
       average_mu = current_mu       
	
     if (average_sigma == 0):
       if ( fDebug ): print "Average sigma = 0 Fit Problem in " + hist.GetTitle() + ". "+str(last_sigma)+" "+str(current_sigma)
       average_sigma = current_sigma

     mu_percent_diff = fabs((last_mu-current_mu)/average_mu)
     sigma_percent_diff = fabs((last_sigma-current_sigma)/average_sigma)

     if ( mu_percent_diff < percent_limit and sigma_percent_diff < percent_limit ): break

     if (iteration != iteration_limit): #necessary?
       last_mu = current_mu
       last_sigma = current_sigma
        
  if (iteration == iteration_limit): 
    if ( fDebug ): print "WARNING: Fit did not converge to < "+percent_limit*100+"% in "+ hist.GetTitle() +" in "+iteration_limit+" iterations. Percent Diffs: "+mu_percent_diff*100+"% (Mu),"+" "+sigma_percent_diff*100+"% (Sigma)"
    #possibly return a value other than 0 to indicate not converged?
  

  params.append(current_mu)
  params.append(fit_func.GetParError(1))
  params.append(current_sigma)
  params.append(fit_func.GetParError(2))
  
  hist.GetListOfFunctions().Add(fit_func)
  
  return 0

  
#-----------------------------------------------------------------------------
def PrintAll( can, name):
   
   if (not can):
     print 'Canvas not found'
     return
   #can.Print( name + '.gif' ) 
   can.Print( name + '.eps') 
   #can.Print( name + '.C' )
   #can.Print( name + '.png' )
   can.Print( name + '.pdf' )
   
   return

   
#-----------------------------------------------------------------------------
def JET_LABEL():

  l = TLatex()
  l.SetNDC()
  l.SetTextFont(72)
  #l.SetTextSize(20)
  l.DrawLatex(0.2,0.7,"#scale[0.8]{N_Jets(p_{T} >20 GeV) == 0}")
  
  return
  
#-----------------------------------------------------------------------------
def ADD_LABEL(text, y=0.82, x=0.2, color=1, size=0.035): 
  
  l2 = TLatex() 
  #l.SetTextAlign(12) 
  l2.SetTextSize(size) 
  l2.SetNDC()
  l2.SetTextColor(color)
  l2.DrawLatex(x,y,text)

  return 


#-----------------------------------------------------------------------------
def CorrectMuonMomentum(pt, eta, phi, charge, corrections):

  delta = corrections.GetBinContent(corrections.FindBin(eta,phi))

  return pt*(1 + charge*delta*pt/1000000)   

#-----------------------------------------------------------------------------
def CorrectMuonMomentum(vector, charge, corrections):
  
  delta = corrections.GetBinContent(corrections.FindBin(vector.Eta(),vector.Phi()))
  #print delta
  vec = TLorentzVector(0,0,0,0)
  vec.SetXYZM(vector.Px()/(1 + charge*delta*vector.Pt()/1000000),vector.Py()/(1 + charge*delta*vector.Pt()/1000000),vector.Pz()/(1 + charge*delta*vector.Pt()/1000000), vector.M())
  return vec

#-----------------------------------------------------------------------------
def InclusiveChain(filenames):

  myChain_4mu   = TChain("tree_incl_4mu");
  myChain_2mu2e = TChain("tree_incl_2mu2e");
  myChain_2e2mu = TChain("tree_incl_2e2mu");
  myChain_4e    = TChain("tree_incl_4e");
  for in_file in filenames:
    myChain_4mu.Add(in_file);  
    myChain_2mu2e.Add(in_file);  
    myChain_2e2mu.Add(in_file);  
    myChain_4e.Add(in_file);  

  myChain_4mu.SetName("tree_incl");
  myChain_2mu2e.SetName("tree_incl");
  myChain_2e2mu.SetName("tree_incl");
  myChain_4e.SetName("tree_incl");

  outchain =  TChain("tree_incl");	 
  outchain.Add(myChain_4mu  );
  outchain.Add(myChain_2mu2e);
  outchain.Add(myChain_2e2mu);
  outchain.Add(myChain_4e   );

  return outchain

#-----------------------------------------------------------------------------
def ErrorHist( central_value_hist, error_hist ):

  hist = central_value_hist.Clone(central_value_hist.GetName()+"_err")
  for i in range(central_value_hist.GetNbinsX()):
    hist.SetBinError(i+1, hist[i+1]*error_hist[i+1]/100)
    
  return hist  

#-----------------------------------------------------------------------------
def AsymmErrorHist( central_value_hist, error_hist_up, error_hist_dn ):

  hist = central_value_hist.Clone(central_value_hist.GetName()+"_err")
  for i in range(central_value_hist.GetNbinsX()):    
    
    val_lo = hist[i+1]*(1-error_hist_dn[i+1]/100)
    val_hi = hist[i+1]*(1+error_hist_up[i+1]/100)
    delta = abs(val_hi-val_lo)/2
    hist[i+1] = val_lo + delta
    hist.SetBinError(i+1, delta)
    
  return hist    
#-----------------------------------------------------------------------------
def AddPtBinLabels( hist ):

  hist.GetXaxis().SetTitle("")

  hist.GetXaxis().SetNdivisions(004, false)

  hist.GetXaxis().SetBinLabel(1, "p_{T} < 20 GeV")
  hist.GetXaxis().SetBinLabel(2, "20 < p_{T} < 50 GeV")
  hist.GetXaxis().SetBinLabel(3, "50 < p_{T} < 100 GeV")
  hist.GetXaxis().SetBinLabel(4, "p_{T} > 100 GeV")

#-----------------------------------------------------------------------------
def PoissonGraph(hist, name):

  graph = TGraphAsymmErrors(hist.GetNbinsX())  
  graph.SetName(name)

  for i in range(hist.GetNbinsX()):
  
    value = hist[i+1]
    x_err = hist.GetBinWidth(i+1)/2
    
    graph.SetPoint(i, hist.GetBinCenter(i+1), value);
    
    error_poisson_down = 0
    error_poisson_up   = 1

    if( value != 0): 
      y1 = value + 1.0;
      d1 = 1.0 - 1.0/(9.0*y1) + 1.0/(3*sqrt(y1));
      error_poisson_up = y1*d1*d1*d1 - value;
      y2 = value;
      d2 = 1.0 - 1.0/(9.0*y2) - 1.0/(3.0*sqrt(y2));
      error_poisson_down = value - y2*d2*d2*d2;
    
    graph.SetPointError(i, x_err, x_err, error_poisson_down, error_poisson_up);

  return graph


#-----------------------------------------------------------------------------
def RatioGraph(hist_num, hist_den):
  
  #divide graph by histogram, assuming no error on denominator (useful for ratio plot)
  
  if (hist_num.GetN() != hist_den.GetNbinsX()):
    print "incompatible hists.  not dividing"
    return TGraphAsymmErrors() 

  ratio = hist_num.Clone(hist_num.GetName()+"_ratio");

  for i in range(1, hist_num.GetN()+1):
     
     value = 0
     if (hist_den[i] != 0):
       value = hist_num.GetY()[i-1] / hist_den[i]
     else:
       print "PlotUtils::RatioGraph - Divide zero error"
       
     err_up = hist_num.GetErrorYhigh(i-1) / hist_den[i]
     err_dn = hist_num.GetErrorYlow(i-1) / hist_den[i]
     ratio.SetPoint(i-1, hist_den.GetBinCenter(i), value)
     ratio.SetPointError(i-1, hist_num.GetErrorXlow(i-1), hist_num.GetErrorXhigh(i-1), err_dn, err_up,)

  FormatRatioHist(ratio)
  
  return ratio

#-----------------------------------------------------------------------------
def RatioHist(hist_num, hist_den):
  
  #divide histogram by histogram, assuming no error on denominator (useful for ratio plot)
  
  if (hist_num.GetNbinsX() != hist_den.GetNbinsX()):
    print "incompatible hists.  not dividing"
    return TH1F() 

  ratio = hist_num.Clone(hist_num.GetName()+"_ratio");

  for i in range(1, hist_num.GetNbinsX()+1):
     
     value = 0
     if (hist_den[i] != 0):
       value = hist_num[i] / hist_den[i]
       #print value
     else:
       print "PlotUtils::RatioGraph - Divide zero error"
       
     err = hist_num.GetBinError(i) / hist_den[i]
     #print err
     ratio[i] = value
     ratio.SetBinError(i, err)  

  FormatRatioHist(ratio)

  return ratio


def FormatRatioHist(ratio):

  ratio.GetYaxis().SetTitle("Ratio");
  ratio.GetYaxis().SetTitleSize(0.12);
  ratio.GetYaxis().SetTitleOffset(0.6);
  ratio.GetYaxis().SetLabelSize(0.08);
  ratio.GetYaxis().SetNdivisions(505);
  ratio.GetXaxis().SetTitleSize(0.12);
  ratio.GetXaxis().SetTitleOffset(1.5);
  ratio.GetXaxis().SetLabelSize(0.12);
  ratio.SetTitle("");
  ratio.SetMaximum(2.0);
  ratio.SetMinimum(0.0001);

  return

#-----------------------------------------------------------------------------
def MY_ATLAS_LABEL( text="Internal",x=0.2, y=0.87, color=1, size=0.05): 

  l = TLatex();  
  l.SetNDC();
  l.SetTextColor(color);
  l.SetTextSize(size)
  l.DrawLatex(x,y,"#font[72]{ATLAS} "+text);

  return

#-----------------------------------------------------------------------------
def ATLAS_Label(text="Internal",x=0.2,y=0.87,color=1):

  l = TLatex() ; #l.SetTextAlign(12); l.SetTextSize(tsize); 
  l.SetNDC();
  l.SetTextFont(72);
  l.SetTextColor(color);
  l.DrawLatex(x,y,"ATLAS");

  l2 = TLatex(); #l.SetTextAlign(12); l.SetTextSize(tsize); 
  l2.SetNDC();
  #l2.SetTextColor(color);
  #l2.DrawLatex(0.33,0.87,"Preliminary");
  #l2.DrawLatex(x+0.11,y," Work in Progress");
  l2.DrawLatex(x+0.12,y,text);


