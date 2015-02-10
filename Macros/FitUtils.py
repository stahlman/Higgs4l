from ROOT import *
from math import log10, floor

def performMassFit(fithist, templatehist, params, opt='shift', doToys=true, showFit=false, xmin=-999, xmax=-999):
    
    M = RooRealVar("M","M_{Z}", -120., 120., "GeV");
    data = RooDataHist("data","hist", RooArgList(M), fithist);
    mframe = M.frame(60,120);
    
    if (fithist.GetTitle() == 'm_mumu'): mframe.SetTitle("Z#rightarrow#mu#mu");
    elif (fithist.GetTitle() == 'm_ee'): mframe.SetTitle("Z#rightarrow ee");    
    else: mframe.SetTitle(fithist.GetTitle());
    
    data.plotOn(mframe)#,RooFit.Binning(120));
    #mframe.Draw();
  
    if (opt == 'shift'):
       
       a = RooRealVar("a","#alpha",0,-3.,3., "GeV") ; 
       xf = RooFormulaVar("xf","M-a",RooArgList(M,a)) ;  

       templatedata = RooDataHist("templatedata","templatedata", RooArgList(M), templatehist);   
       templatepdf  = RooHistPdf("templatepdf","templatepdf",RooArgList(xf),RooArgList(M),templatedata,1) 
       templatepdf.plotOn(mframe, RooFit.LineColor(kRed));
                    
       a_shift = []
       a_val = []
       a_rms = []

       if (doToys):
	  #now, throw toys to estimate error

	  n_toys = 250
	  n_shifts = 10
	  begin_shift = -1.0
	  step_shift = 0.2
          	  
	  h_a_results = TH1F('h_a_toyresults_'+fithist.GetTitle(), 'h_a_results;Input #alpha;Fit #alpha', n_shifts, begin_shift-step_shift/2., begin_shift+(n_shifts-1)*step_shift + step_shift/2.)
          h_failed_fits = TH1F('h_failed_fits_'+fithist.GetTitle(), 'h_failed_fits', 100,  0., 1.)
          
	  RooMsgService.instance().setGlobalKillBelow(RooFit.ERROR) ;
	  
	  for i_shift in range(n_shifts):
	    print fithist.GetName()+", shift", i_shift,"of", n_shifts 	 
	    shift = begin_shift + i_shift*step_shift

            h_a_val = TH1F('h_a_val_'+fithist.GetTitle()+str(shift), 'h_a_val', 100, -3., 3.)
            h_a_err = TH1F('h_a_err_'+fithist.GetTitle()+str(shift), 'h_a_err', 100,  0., 2.)
	    a_shift.append(shift)
	  
	    n_fail = 0
  
	    for i in range(n_toys):	       
	       a.setVal(shift)
               pseudodata = templatepdf.generate(RooArgSet(M),int(fithist.GetEntries()))

	       a.setVal(0.)
	       a.setError(1.)
	       r = RooFitResult()
	       if (xmin != -999) and (xmax!=-999):
        	  r = templatepdf.fitTo(pseudodata, RooFit.NumCPU(2), RooFit.Range(xmin,xmax), RooFit.PrintLevel(-1), RooFit.Verbose(kFALSE),RooFit.Save(kTRUE))
	       else:
        	  r = templatepdf.fitTo(pseudodata, RooFit.NumCPU(2), RooFit.PrintLevel(-1), RooFit.Verbose(kFALSE), RooFit.Save(kTRUE))
        	  #r = templatepdf.fitTo(pseudodata, RooFit.Save(kTRUE))

	       #if (fabs(a.getVal() - shift) > 5*0.2):
	       #if (r.status() != 0):
	       if (r.covQual() != 3 or a.getVal() == 0.0):
		 n_fail += 1
		 print a.getVal(),'+/-',a.getError()
	         continue
                 #temp_frame = M.frame(60,120);
		 #pseudodata.plotOn(temp_frame)
		 #templatepdf.plotOn(temp_frame)
		 #temp_frame.Draw()
   		 #raw_input("Press ENTER to continue")	

	       h_a_val.Fill(a.getVal())
               h_a_err.Fill(a.getError())
            
	    print "Failed Fits:", n_fail, '/',n_toys 
	    h_failed_fits.Fill(float(n_fail)/float(n_toys))
	    
            h_a_results.SetBinContent(i_shift+1,h_a_val.GetMean())
            h_a_results.SetBinError(i_shift+1,h_a_val.GetRMS())
            	    
	    a_val.append(h_a_val.GetMean())
	    a_rms.append(h_a_val.GetRMS())
	    h_a_val.Write()
	    h_a_err.Write()

	  h_a_results.Write()
	  h_failed_fits.Write()

       #fit data
       a.setVal(0.) #reset intial values and errors - very important!
       a.setError(1.)
       if (xmin != -999) and (xmax!=-999):
          r = templatepdf.fitTo(data,RooFit.Save(kTRUE),RooFit.Range(xmin,xmax))
       else:
	  r = templatepdf.fitTo(data,RooFit.Save(kTRUE)) ;
       	     
       templatepdf.plotOn(mframe) ;
       
       templatepdf.paramOn(mframe,
        		   RooFit.Layout(0.7, 0.9, 0.9),
        		   RooFit.Format("NEU", RooFit.AutoPrecision(1)),
        		   RooFit.ShowConstants())	 

       if (doToys):
	  txt = TLatex() ;
	  txt.SetNDC()
	  toy_err = sum(a_rms) / float(len(a_rms))
	  #txt.SetText(0.7,0.7,"Toy Error: " + str('%.2g' % toy_err) )
	  txt.SetText(0.7,0.78,"Toy Error: " + str( round(toy_err, 2-int(floor(log10(toy_err)))-1)) + ' GeV')
	  txt.SetTextSize(0.04) ;
	  mframe.addObject(txt) ;
 

    if (opt == 'scale'):
       
       a = RooRealVar("a","a",1,0.,2.) ; 
       xf = RooFormulaVar("xf","M*a",RooArgList(M,a)) ;  

       templatedata = RooDataHist("templatedata","templatedata", RooArgList(M), templatehist);   
       templatepdf  = RooHistPdf("templatepdf","templatepdf",RooArgList(xf),RooArgList(M),templatedata,1) 
       templatepdf.plotOn(mframe, RooFit.LineColor(kRed));
              
       if (xmin != -999) and (xmax!=-999):
          r = templatepdf.fitTo(data, RooFit.Range(xmin,xmax))
       else:
          r = templatepdf.fitTo(data) ;
       	     
       templatepdf.plotOn(mframe) ;
              
       mframe.Write('fit_'+fithist.GetTitle())
       
       if (doToys):
	  #throw toys to estimate error

	  a_shift = []
	  a_val = []
	  a_rms = []

	  n_toys = 50
	  n_shifts = 4
	  begin_shift = 0.98
	  step_shift = 0.01

	  h_a_results = TH1F('h_a_toyresults_'+fithist.GetTitle(), 'h_a_results;Input #alpha;Fit #alpha', n_shifts, begin_shift-step_shift/2., begin_shift+(n_shifts-1)*step_shift + step_shift/2.)

	  for i_shift in range(n_shifts):	 
	    shift = begin_shift + i_shift*step_shift

            h_a_val = TH1F('h_a_val_'+fithist.GetTitle()+str(shift), 'h_a_val', 100, 0.8, 1.2)
            h_a_err = TH1F('h_a_err_'+fithist.GetTitle()+str(shift), 'h_a_err', 100,  0., 0.2)
	    a_shift.append(shift)
	    for i in range(n_toys):
	       a.setVal(shift)
               pseudodata = templatepdf.generate(RooArgSet(M),int(fithist.GetEntries()))

	       a.setVal(1.)
	       if (xmin != -999) and (xmax!=-999):
        	  r = templatepdf.fitTo(pseudodata, RooFit.Range(xmin,xmax), RooFit.PrintLevel(-1), RooFit.Verbose(kFALSE))
	       else:
        	  r = templatepdf.fitTo(pseudodata)

	       #if (fabs(a.getVal() - shift) > 5*0.2):
		 #continue
		 #pseudodata.plotOn(mframe)
		 #templatepdf.plotOn(mframe)
		 #mframe.Draw()
   		 #raw_input("Press ENTER to continue")   

	       h_a_val.Fill(a.getVal())
               h_a_err.Fill(a.getError())

	    print "Shift: ", shift 
	    print "h_a_val mean: ", h_a_val.GetMean(), '+/-', h_a_val.GetMeanError()
	    print "h_a_val RMS: ", h_a_val.GetRMS(), '+/-', h_a_val.GetRMSError()

            h_a_results.SetBinContent(i_shift+1,h_a_val.GetMean())
            h_a_results.SetBinError(i_shift+1,h_a_val.GetRMS())

	    a_val.append(h_a_val.GetMean())
	    a_rms.append(h_a_val.GetRMS())
	    h_a_val.Write()
	    #raw_input("Press ENTER to continue")   
	    h_a_err.Write()
	    #raw_input("Press ENTER to continue")   


	  h_a_results.Write()

	  for i in range(len(a_shift)):
	    print "Shift: ", a_shift[i] 
	    print "h_a_val mean: ", a_val[i], '+/-', a_rms[i]
	    
    if (opt == 'gauss'):
  
       templatedata = RooDataHist("templatedata","templatedata", RooArgList(M), templatehist);   
       templatepdf = RooHistPdf("templatepdf","templatepdf", RooArgSet(M),templatedata,0);

       # resolution function
       mu = RooRealVar("#mu", "Mu of Gaussian" , 0., -10., 5.) ;
       sigma = RooRealVar("#sigma","Sigma of Gaussian", 0.1, 0., 10.) ;
       gauss = RooGaussian("gauss", "gauss(M,mean,sigma)", M, mu, sigma) ;

       # Convolute the signal with the Gaussian
       model = RooFFTConvPdf("model","truth (X) gaussian", M, templatepdf, gauss);

       if (xmin != -999) and (xmax!=-999):
          r = model.fitTo(data, RooFit.Range(xmin,xmax))
       else:
          r = model.fitTo(data) ;
   
       model.plotOn(mframe) ;

       params = []
       params.append(mu.getVal())
       params.append(mu.getError())
       params.append(sigma.getVal())
       params.append(sigma.getError())

   
       #r = model.fitTo(data,ROOFIT.Save(true),RooFit.Hesse(true),RooFit.Minos(false)); #, Range(80,100),) ;
       #model.fitTo(data,Save(true),Hesse(true),Minos(false)); #, Range(80,100),) ;
       #r.Print("v");  

       #model.plotOn(mframe,Components(f1),LineStyle(kDashed)) ;
       #model.paramOn(mframe, Format("NEA", AutoPrecision(1)), Layout(0.65,0.95,0.9) ) ;

    #add plot labels and write out        
    txt1 = TLatex() ;
    txt1.SetNDC()
    txt1.SetText(0.14,0.84,"#font[72]{ATLAS} Internal")
    txt1.SetTextSize(0.05) ;
    mframe.addObject(txt1) ;

    txt2 = TLatex() ;
    txt2.SetNDC()
    txt2.SetText(0.14,0.77,"#int L dt = 20.7 fb^{-1}")
    txt2.SetTextSize(0.04) ;
    mframe.addObject(txt2) ;

    txt3 = TLatex() ;
    txt3.SetNDC()
    txt3.SetText(0.14,0.70,"\\sqrt{s} = 8 TeV")
    txt3.SetTextSize(0.04) ;
    mframe.addObject(txt3) ;

    mframe.Draw();

    #raw_input("Press ENTER to continue")   

    mframe.Write('fit_'+opt+'_'+fithist.GetTitle())

    if(showFit):  
       raw_input("Press ENTER to continue")   
           
    return;

def performMassFit(tag,channel,fit_var,data_files, mc_files,  opt='shift', doToys=false, outputDir='', xmin=-999, xmax=-999,showFit=false):
    
    c1 = TCanvas("c1")
    
    RooAbsReal.defaultIntegratorConfig().setEpsAbs(1e-10) ;
    RooAbsReal.defaultIntegratorConfig().setEpsRel(1e-10) ;
  
    MZ1 = RooRealVar("mZ1_unconstrained","M_{12}", 50., 115., "GeV");
    MZ2 = RooRealVar("mZ2_unconstrained","M_{34}", 50., 115., "GeV");
    M4l = RooRealVar("m4l_unconstrained","M_{4l}", 0., 1000., "GeV");
    MZ = RooRealVar("mZ_unconstrained","M_{Z}", 50., 115., "GeV");

    weight = RooRealVar("weight","weight", -1000., 1000.);
   
    data = RooDataSet()
    mc = RooDataSet()
        
    if (fit_var == 'both'):
       data_tree  = TChain()
       data_tree2 = TChain()
       mc_tree    = TChain()
       mc_tree2   = TChain()
   
       if (channel == '4mu' or channel == '4e'):
	   data_tree  = TChain('tree_incl_'+channel)      
	   data_tree2 = TChain('tree_incl_'+channel)      
	   mc_tree    = TChain('tree_incl_'+channel)
	   mc_tree2   = TChain('tree_incl_'+channel)
       elif (channel == '2mu2e'):
	   data_tree  = TChain('tree_incl_2mu2e')      
	   data_tree2 = TChain('tree_incl_2e2mu')      
	   mc_tree    = TChain('tree_incl_2mu2e')
	   mc_tree2   = TChain('tree_incl_2e2mu')
       elif (channel == '2e2mu'):
	   data_tree2 = TChain('tree_incl_2mu2e')      
	   data_tree  = TChain('tree_incl_2e2mu')      
	   mc_tree2   = TChain('tree_incl_2mu2e')
	   mc_tree    = TChain('tree_incl_2e2mu')
       else:
           print 'Unknown channel:',channel,'. Aborting...'
	   return   
   
       data_tree.AddFileInfoList(data_files.GetList())
       data_tree2.AddFileInfoList(data_files.GetList())
       mc_tree.AddFileInfoList(mc_files.GetList())
       mc_tree2.AddFileInfoList(mc_files.GetList())
                            
       data = RooDataSet("data","data",data_tree, RooArgSet(M4l,MZ1), "m4l_unconstrained>190.0");
       data_z2 = RooDataSet("data","data",data_tree2, RooArgSet(M4l,MZ2), "m4l_unconstrained>190.0");
       data.changeObservableName("mZ1_unconstrained", "mZ_unconstrained")
       data_z2.changeObservableName("mZ2_unconstrained", "mZ_unconstrained")       
       data.append(data_z2)

       mc = RooDataSet("mc","mc",mc_tree, RooArgSet(M4l,MZ1, weight), "m4l_unconstrained>190.0", 'weight');
       mc_z2 = RooDataSet("mc","mc",mc_tree2, RooArgSet(M4l,MZ2, weight), "m4l_unconstrained>190.0", 'weight');
       mc.changeObservableName("mZ1_unconstrained", "mZ_unconstrained")
       mc_z2.changeObservableName("mZ2_unconstrained", "mZ_unconstrained")       
       mc.append(mc_z2)

    else:
      data_tree = TChain('tree_incl_'+channel)      
      mc_tree   = TChain('tree_incl_'+channel)

      data_tree.AddFileInfoList(data_files.GetList())
      mc_tree.AddFileInfoList(mc_files.GetList())

      if (fit_var == 'm12'):
	 data = RooDataSet("data","data",data_tree, RooArgSet(M4l,MZ1), "m4l_unconstrained>190.0");
	 data.changeObservableName("mZ1_unconstrained", "mZ_unconstrained")
	 mc = RooDataSet("mc","mc",mc_tree, RooArgSet(M4l,MZ1,weight), "m4l_unconstrained>190.0", 'weight');
	 mc.changeObservableName("mZ1_unconstrained", "mZ_unconstrained")
      elif (fit_var == 'm34'):
	 data = RooDataSet("data","data",data_tree, RooArgSet(M4l,MZ2), "m4l_unconstrained>190.0");
	 data.changeObservableName("mZ2_unconstrained", "mZ_unconstrained")
	 mc = RooDataSet("mc","mc",mc_tree, RooArgSet(M4l,MZ2,weight), "m4l_unconstrained>190.0",'weight');
	 mc.changeObservableName("mZ2_unconstrained", "mZ_unconstrained")
      else:
         print "Unknown fit_var:",fit_var," Aborting"
	 return
                       
    file_suffix = opt+'_'+channel+'_'+fit_var+'_'+data_tree.GetName()+'.'+tag

    mframe = MZ.frame(70,110);    
    mframe.SetTitle("")    
    data.plotOn(mframe,RooFit.Binning(120,60,120), RooFit.Name("data"));
    mean_data = data.mean(MZ)
    #mframe.Draw();
  
    if (opt == 'shift'):
       
       a = RooRealVar("#alpha","#alpha",0,-3.,3., "GeV") ; 
       xf = RooFormulaVar("xf","mZ_unconstrained-#alpha",RooArgList(MZ,a)) ;  
       
       #print MZ.getBins()
       MZ.setBins(130)
       mc_template_data = RooDataHist("mc_template_data","mc_template_data", RooArgSet(MZ), mc); 
       mc_frame = MZ.frame()
       mc_template_data.plotOn(mc_frame)
       mc_frame.Draw()
       mc_frame.Write('template_'+file_suffix)
       mean_mc = mc_template_data.mean(MZ)

       MZ.setBins(120)

       templatepdf  = RooHistPdf("templatepdf","templatepdf",RooArgList(xf),RooArgList(MZ),mc_template_data,2) 
       #templatepdf  = RooKeysPdf("templatepdf","templatepdf",xf,mc,RooKeysPdf.NoMirror) ;
       
       templatepdf.plotOn(mframe, RooFit.LineColor(kRed), RooFit.Name("mctemp"));
       
       initial_chi2 = mframe.chiSquare("mctemp","data")
       
#       h_a_fitresults = TH1F('h_a_binresults_'+data_tree.GetName(), 'h_a_results;Input bin;Fit #alpha', 100, 100,1100)
#       for i in range(1,100+1):
#       
#         MZ.setBins(100+i*10)
#	 mc_template_data = RooDataHist("mc_template_data","mc_template_data", RooArgSet(MZ), mc); 
#
#	 templatepdf  = RooHistPdf("templatepdf","templatepdf",RooArgList(xf),RooArgList(MZ),mc_template_data,1) 
#	 #templatepdf.plotOn(mframe, RooFit.LineColor(kRed));
#	 
#	 #fit data
#	 a.setVal(0.) #reset intial values and errors - very important!
#	 a.setError(1.)
#	 if (xmin != -999) and (xmax!=-999):
#            r = templatepdf.fitTo(data,RooFit.Save(kTRUE),RooFit.Range(xmin,xmax))
#	 else:
#            r = templatepdf.fitTo(data,RooFit.Save(kTRUE)) ;
#	 
#	 h_a_fitresults.SetBinContent(i,a.getVal())  
#	 h_a_fitresults.SetBinError(i,a.getError())  
#       
#       h_a_fitresults.Write()
                    
       a_shift = []
       a_val = []
       a_rms = []

       if (doToys):
	  #now, throw toys to estimate error

	  n_toys = 250
	  n_shifts = 10
	  begin_shift = -1.0
	  step_shift = 0.2
          	  
	  h_a_results = TH1F('h_a_toyresults_'+data_tree.GetName(), 'h_a_results;Input #alpha;Fit #alpha', n_shifts, begin_shift-step_shift/2., begin_shift+(n_shifts-1)*step_shift + step_shift/2.)
          h_failed_fits = TH1F('h_failed_fits_'+data_tree.GetName(), 'h_failed_fits', 100,  0., 1.)
          
	  RooMsgService.instance().setGlobalKillBelow(RooFit.ERROR) ;
	  
	  for i_shift in range(n_shifts):
	    print data_tree.GetName()+", shift", i_shift,"of", n_shifts 	 
	    shift = begin_shift + i_shift*step_shift

            h_a_val = TH1F('h_a_val_'+data_tree.GetName()+str(shift), 'h_a_val', 100, -3., 3.)
            h_a_err = TH1F('h_a_err_'+data_tree.GetName()+str(shift), 'h_a_err', 100,  0., 2.)
	    a_shift.append(shift)
	  
	    n_fail = 0
  
	    for i in range(n_toys):	       
	       a.setVal(shift)
               pseudodata = templatepdf.generate(RooArgSet(MZ),int(data_tree.GetEntries()))

	       a.setVal(0.)
	       a.setError(1.)
	       r = RooFitResult()
	       if (xmin != -999) and (xmax!=-999):
        	  r = templatepdf.fitTo(pseudodata, RooFit.NumCPU(2), RooFit.Range(xmin,xmax), RooFit.PrintLevel(-1), RooFit.Verbose(kFALSE),RooFit.Save(kTRUE))
	       else:
        	  r = templatepdf.fitTo(pseudodata, RooFit.NumCPU(2), RooFit.PrintLevel(-1), RooFit.Verbose(kFALSE), RooFit.Save(kTRUE))
        	  #r = templatepdf.fitTo(pseudodata, RooFit.Save(kTRUE))
               
	       if (a.getError() < 0.010):
 		  print a.getVal(),'+/-',a.getError()
	          nll = templatepdf.createNLL(pseudodata) ;
		  t_frame = a.frame(RooFit.Bins(10),RooFit.Range(a.getVal()-0.010,a.getVal()+0.010),RooFit.Title("LL and profileLL in a")) ;
		  nll.plotOn(t_frame,RooFit.ShiftToZero()) ;
		  t_frame.Draw()
		  raw_input("Press ENTER to continue")       

	       #if (fabs(a.getVal() - shift) > 5*0.2):
	       #if (r.status() != 0):
	       if (r.covQual() != 3 or a.getVal() == 0.0):
		 n_fail += 1
		 print a.getVal(),'+/-',a.getError()
	         continue
               #temp_frame = MZ.frame(60,120);
	       #pseudodata.plotOn(temp_frame)
	       #templatepdf.plotOn(temp_frame)
	       #a.setVal(0.)
	       #templatepdf.plotOn(temp_frame, RooFit.LineColor(kRed))
	       #temp_frame.Draw()
   	       #raw_input("Press ENTER to continue")  

	       h_a_val.Fill(a.getVal())
               h_a_err.Fill(a.getError())
            
	    print "Failed Fits:", n_fail, '/',n_toys 
	    h_failed_fits.Fill(float(n_fail)/float(n_toys))
	    
            h_a_results.SetBinContent(i_shift+1,h_a_val.GetMean())
            h_a_results.SetBinError(i_shift+1,h_a_val.GetRMS())
            	    
	    a_val.append(h_a_val.GetMean())
	    a_rms.append(h_a_val.GetRMS())
	    h_a_val.Write()
	    h_a_err.Write()

	  h_a_results.Write()
	  h_failed_fits.Write()

       #fit data
       a.setVal(0.) #reset intial values and errors - very important!
       a.setError(1.)
       r = RooFitResult()
       if (xmin != -999) and (xmax!=-999):
          r = templatepdf.fitTo(data,RooFit.Save(kTRUE),RooFit.Range(xmin,xmax))
       else:
          r = templatepdf.fitTo(data, RooFit.Minos(kTRUE),RooFit.Save(kTRUE)) ;
          #r = templatepdf.fitTo(data,RooFit.InitialHesse(kTRUE), RooFit.Minos(kTRUE),RooFit.Save(kTRUE)) ;
          #r = templatepdf.fitTo(data,RooFit.InitialHesse(kTRUE), RooFit.Minos(kTRUE),RooFit.Save(kTRUE),RooFit.Optimize(kTRUE),RooFit.Strategy(2)) ;

       nll = templatepdf.createNLL(data) ;

       frame1 = a.frame(RooFit.Bins(10),RooFit.Range(-2,2),RooFit.Title("LL and profileLL in a")) ;
       nll.plotOn(frame1,RooFit.ShiftToZero())
       frame1.SetAxisRange(0,10,"Y")
       frame1.Draw()
       frame1.Write('nll_'+file_suffix)
       c1.Print(outputDir+'/nll_'+file_suffix+'.eps')
       #raw_input("Press ENTER to continue")       

       templatepdf.plotOn(mframe, RooFit.Name("shift_mctemp")) ;
       
       #templatepdf.paramOn(mframe,
       # 		  RooFit.Layout(0.6, 0.9, 0.9),
       # 		  RooFit.Format("NEALU", RooFit.AutoPrecision(2)),
       # 		  RooFit.ShowConstants())	
       
       if (r.covQual() !=3):
         print "WARNING: Data fit had covQual=", r.covQual() 
       
       print data_tree.GetName()+" fit value=",a.getVal(),"+/-",a.getError(), "+", a.getErrorHi(), "-", a.getErrorLo()
       print "Initial Chi2 =", initial_chi2
       final_chi2 =  mframe.chiSquare("shift_mctemp","data")
       print "Final Chi2 =", final_chi2
       
       txt_alpha = TLatex() ;
       txt_alpha.SetNDC()
       txt_alpha.SetText(0.63,0.83,a.format(2,"NEALU").Data())
       txt_alpha.SetTextSize(0.04) ;
       mframe.addObject(txt_alpha) ;

       txt_chi2_initial = TLatex() ;
       txt_chi2_initial.SetNDC()
       txt_chi2_initial.SetText(0.69,0.7,"Initial #chi^{2} = " +str( round(initial_chi2, 2-int(floor(log10(initial_chi2)))-1)) )
       txt_chi2_initial.SetTextSize(0.04) ;
       mframe.addObject(txt_chi2_initial) ;

       txt_chi2 = TLatex() ;
       txt_chi2.SetNDC()
       txt_chi2.SetText(0.697,0.65,"Final #chi^{2} = " + str( round(final_chi2, 2-int(floor(log10(final_chi2)))-1)) )
       txt_chi2.SetTextSize(0.04) ;
       mframe.addObject(txt_chi2) ;
 
       txt_mean_data = TLatex() ;
       txt_mean_data.SetNDC()
       txt_mean_data.SetText(0.7,0.6,"<M>_{data} = " +str( round(mean_data, 3-int(floor(log10(mean_data)))-1)) )
       txt_mean_data.SetTextSize(0.04) ;
       mframe.addObject(txt_mean_data) ;

       txt_mean_mc = TLatex() ;
       txt_mean_mc.SetNDC()
       txt_mean_mc.SetText(0.71,0.55,"<M>_{mc} = " +str( round(mean_mc, 3-int(floor(log10(mean_mc)))-1)) )
       txt_mean_mc.SetTextSize(0.04) ;
       mframe.addObject(txt_mean_mc) ;
       
       if (doToys):
	  txt = TLatex() ;
	  txt.SetNDC()
	  toy_err = sum(a_rms) / float(len(a_rms))
	  #txt.SetText(0.7,0.7,"Toy Error: " + str('%.2g' % toy_err) )
	  txt.SetText(0.7,0.78,"Toy Error: " + str( round(toy_err, 2-int(floor(log10(toy_err)))-1)) + ' GeV')
	  txt.SetTextSize(0.04) ;
	  mframe.addObject(txt) ;
 
 
    #add plot labels and write out        
    txt1 = TLatex() ;
    txt1.SetNDC()
    txt1.SetTextFont(42)
    txt1.SetText(0.14,0.84,"#font[72]{ATLAS} Internal")
    txt1.SetTextSize(0.05) ;
    mframe.addObject(txt1) ;
    
    
    txt2 = TLatex() ;
    txt2.SetNDC()
    txt2.SetTextFont(42)
    if (tag == '2012'):
       txt2.SetText(0.14,0.77,"\\sqrt{s} = 8 TeV #int L dt = 20.7 fb^{-1}")
    elif (tag == '2011' or tag == '2011and2012'):
       txt2.SetText(0.14,0.77,"\\sqrt{s} = 7 TeV #int L dt = 4.6 fb^{-1}")
    txt2.SetTextSize(0.035) ;
    mframe.addObject(txt2) ;

    if (tag == '2011and2012'):
       txt3 = TLatex() ;
       txt3.SetNDC()
       txt3.SetTextFont(42)
       txt3.SetText(0.14,0.70,"\\sqrt{s} = 8 TeV #int L dt = 20.7 fb^{-1}")
       txt3.SetTextSize(0.035) ;
       mframe.addObject(txt3) ;

    mframe.Draw();

    #raw_input("Press ENTER to continue")   

    mframe.Write('fit_'+file_suffix)
    c1.Print(outputDir+'/fit_'+file_suffix+'.eps')

    if(showFit):  
       raw_input("Press ENTER to continue")   
           
    return;
         
#code for plotting likelihood curve for reference
#		  if (a.getVal() > -0.1 and a.getVal() < 0.1 and shift < -0.3):
#		    print a.getVal(),'+/-',a.getError()
#		    print r.covQual()
#		    print r.status()
#                    temp_frame = M.frame(60,120);
#		    pseudodata.plotOn(temp_frame)
#		    templatepdf.plotOn(temp_frame)
#		    temp_frame.Draw()
#		    
#		    frac = RooRealVar("frac","frac",0.5,0.0,1.0) ;
#		    
#		    #Construct unbinned likelihood
#		    nll = templatepdf.createNLL(pseudodata) ;
#
#		    #Minimize likelihood w.r.t all parameters before making plots
#		    RooMinuit(nll).migrad() ;
#
#		    #Plot likelihood scan frac 
#		    frame1 = a.frame(RooFit.Bins(10),RooFit.Range(-2,2),RooFit.Title("LL and profileLL in a")) ;
#		    nll.plotOn(frame1,RooFit.ShiftToZero()) ;
#		    frame1.Draw()
#		    
#		    #// Plot likelihood scan in sigma_g2
#		    #RooPlot* frame2 = sigma_g2.frame(Bins(10),Range(3.3,5.0),Title("LL and profileLL in sigma_g2")) ;
#		    #nll->plotOn(frame2,ShiftToZero()) ;
#  
#     		    raw_input("Press ENTER to continue")       


def performPtFit(tag,channel,fit_var,data_files, mc_files,  opt='shift', doToys=false, outputDir='',showFit=false, xmin=-999, xmax=-999):
    
    c1 = TCanvas("c1")
    
    RooAbsReal.defaultIntegratorConfig().setEpsAbs(1e-10) ;
    RooAbsReal.defaultIntegratorConfig().setEpsRel(1e-10) ;
  
    #MZ1 = RooRealVar("mZ1_unconstrained","M_{12}", 50., 115., "GeV");
    #MZ2 = RooRealVar("mZ2_unconstrained","M_{34}", 50., 115., "GeV");
    #M4l = RooRealVar("m4l_unconstrained","M_{4l}", 0., 1000., "GeV");
    #MZ = RooRealVar("mZ_unconstrained","M_{Z}", 50., 115., "GeV");

    PT = RooRealVar("higgspt","p_{T}^{4l}", 0., 500., "GeV");

    weight = RooRealVar("weight","weight", -1000., 1000.);
   
    data = RooDataSet()
    mc = RooDataSet()
    
    data_tree = GetTChain(channel, data_files)
    mc_tree   = GetTChain(channel, mc_files)
            
    data = RooDataSet("data","data",data_tree, RooArgSet(PT));
    mc   = RooDataSet("mc","mc",mc_tree, RooArgSet(PT, weight), "", 'weight');
                           
    file_suffix = opt+'_'+channel+'_'+fit_var+'_'+data_tree.GetName()+'.'+tag

    mframe = PT.frame(0,100);    
    mframe.SetTitle("")    
    #data.plotOn(mframe,RooFit.Binning(10,0,300), RooFit.Name("data"));
    mc.plotOn(mframe,RooFit.Binning(300,0,300), RooFit.Name("mc"));

    if (opt == 'CB'):
       
       mean   = RooRealVar("mean","mean",20.,0.,200., "GeV") ; 
       sigma  = RooRealVar("sigma","#sigma",10.,0.,300., "GeV") ; 
       alpha  = RooRealVar("#alpha","#alpha",-0.6,-20.,20.) ; 
       n      = RooRealVar("n","n",7,0.,100.) ; 

       mean.setError(0.5*mean.getVal())  
       sigma.setError(0.5*sigma.getVal())  
       alpha.setError(0.5*alpha.getVal())   
       n.setError(0.5*n.getVal())       
       
       #mean.setConstant(true) 
       #sigma.setConstant(true) 
       alpha.setConstant(true) 
       n.setConstant(true)     
       
       #CBpdf = RooCBShape("CBpdf", "", PT, mean, sigma, alpha, n)
       CBpdf = RooLandau("lx","lx",PT,mean ,sigma)       
             
       CBpdf.plotOn(mframe, RooFit.LineColor(kRed), RooFit.Name("mctemp"));
       
       if(showFit):  
	  mframe.Draw();
	  raw_input("Press ENTER to continue")   

       #initial_chi2 = mframe.chiSquare("mctemp","data")
       
#       a_shift = []
#       a_val = []
#       a_rms = []
#
#       if (doToys):
#	  #now, throw toys to estimate error
#
#	  n_toys = 250
#	  n_shifts = 10
#	  begin_shift = -1.0
#	  step_shift = 0.2
#          	  
#	  h_a_results = TH1F('h_a_toyresults_'+data_tree.GetName(), 'h_a_results;Input #alpha;Fit #alpha', n_shifts, begin_shift-step_shift/2., begin_shift+(n_shifts-1)*step_shift + step_shift/2.)
#          h_failed_fits = TH1F('h_failed_fits_'+data_tree.GetName(), 'h_failed_fits', 100,  0., 1.)
#          
#	  RooMsgService.instance().setGlobalKillBelow(RooFit.ERROR) ;
#	  
#	  for i_shift in range(n_shifts):
#	    print data_tree.GetName()+", shift", i_shift,"of", n_shifts 	 
#	    shift = begin_shift + i_shift*step_shift
#
#            h_a_val = TH1F('h_a_val_'+data_tree.GetName()+str(shift), 'h_a_val', 100, -3., 3.)
#            h_a_err = TH1F('h_a_err_'+data_tree.GetName()+str(shift), 'h_a_err', 100,  0., 2.)
#	    a_shift.append(shift)
#	  
#	    n_fail = 0
#  
#	    for i in range(n_toys):	       
#	       a.setVal(shift)
#               pseudodata = templatepdf.generate(RooArgSet(MZ),int(data_tree.GetEntries()))
#
#	       a.setVal(0.)
#	       a.setError(1.)
#	       r = RooFitResult()
#	       if (xmin != -999) and (xmax!=-999):
#        	  r = templatepdf.fitTo(pseudodata, RooFit.NumCPU(2), RooFit.Range(xmin,xmax), RooFit.PrintLevel(-1), RooFit.Verbose(kFALSE),RooFit.Save(kTRUE))
#	       else:
#        	  r = templatepdf.fitTo(pseudodata, RooFit.NumCPU(2), RooFit.PrintLevel(-1), RooFit.Verbose(kFALSE), RooFit.Save(kTRUE))
#        	  #r = templatepdf.fitTo(pseudodata, RooFit.Save(kTRUE))
#               
#	       if (a.getError() < 0.010):
# 		  print a.getVal(),'+/-',a.getError()
#	          nll = templatepdf.createNLL(pseudodata) ;
#		  t_frame = a.frame(RooFit.Bins(10),RooFit.Range(a.getVal()-0.010,a.getVal()+0.010),RooFit.Title("LL and profileLL in a")) ;
#		  nll.plotOn(t_frame,RooFit.ShiftToZero()) ;
#		  t_frame.Draw()
#		  raw_input("Press ENTER to continue")       
#
#	       #if (fabs(a.getVal() - shift) > 5*0.2):
#	       #if (r.status() != 0):
#	       if (r.covQual() != 3 or a.getVal() == 0.0):
#		 n_fail += 1
#		 print a.getVal(),'+/-',a.getError()
#	         continue
#               #temp_frame = MZ.frame(60,120);
#	       #pseudodata.plotOn(temp_frame)
#	       #templatepdf.plotOn(temp_frame)
#	       #a.setVal(0.)
#	       #templatepdf.plotOn(temp_frame, RooFit.LineColor(kRed))
#	       #temp_frame.Draw()
#   	       #raw_input("Press ENTER to continue")  
#
#	       h_a_val.Fill(a.getVal())
#               h_a_err.Fill(a.getError())
#            
#	    print "Failed Fits:", n_fail, '/',n_toys 
#	    h_failed_fits.Fill(float(n_fail)/float(n_toys))
#	    
#            h_a_results.SetBinContent(i_shift+1,h_a_val.GetMean())
#            h_a_results.SetBinError(i_shift+1,h_a_val.GetRMS())
#            	    
#	    a_val.append(h_a_val.GetMean())
#	    a_rms.append(h_a_val.GetRMS())
#	    h_a_val.Write()
#	    h_a_err.Write()
#
#	  h_a_results.Write()
#	  h_failed_fits.Write()

       #fit data
       #a.setVal(0.) #reset intial values and errors - very important!
       #a.setError(1.)
       r = RooFitResult()
       if (xmin != -999) and (xmax!=-999):
      	  r = CBpdf.fitTo(mc,RooFit.Save(kTRUE),RooFit.Range(xmin,xmax))
       else:
          #print "BLAH"
          r = CBpdf.fitTo(mc,  RooFit.SumW2Error(kTRUE), RooFit.Minos(kTRUE),RooFit.Save(kTRUE)) ;
          #r = templatepdf.fitTo(data,RooFit.InitialHesse(kTRUE), RooFit.Minos(kTRUE),RooFit.Save(kTRUE)) ;
          #r = templatepdf.fitTo(data,RooFit.InitialHesse(kTRUE), RooFit.Minos(kTRUE),RooFit.Save(kTRUE),RooFit.Optimize(kTRUE),RooFit.Strategy(2)) ;

#       nll = templatepdf.createNLL(data) ;
#
#       frame1 = a.frame(RooFit.Bins(10),RooFit.Range(-2,2),RooFit.Title("LL and profileLL in a")) ;
#       nll.plotOn(frame1,RooFit.ShiftToZero())
#       frame1.SetAxisRange(0,10,"Y")
#       frame1.Draw()
#       frame1.Write('nll_'+file_suffix)
#       c1.Print(outputDir+'/nll_'+file_suffix+'.eps')
#       #raw_input("Press ENTER to continue")       
#
       CBpdf.plotOn(mframe, RooFit.Name("shift_mctemp")) ;
       
       #templatepdf.paramOn(mframe,
       # 		  RooFit.Layout(0.6, 0.9, 0.9),
       # 		  RooFit.Format("NEALU", RooFit.AutoPrecision(2)),
       # 		  RooFit.ShowConstants())	
       
       if (r.covQual() !=3):
         print "WARNING: Data fit had covQual=", r.covQual() 
       
       #print data_tree.GetName()+" fit value=",a.getVal(),"+/-",a.getError(), "+", a.getErrorHi(), "-", a.getErrorLo()
       #print "Initial Chi2 =", initial_chi2
       #final_chi2 =  mframe.chiSquare("shift_mctemp","data")
       #print "Final Chi2 =", final_chi2
       
#       txt_alpha = TLatex() ;
#       txt_alpha.SetNDC()
#       txt_alpha.SetText(0.63,0.83,a.format(2,"NEALU").Data())
#       txt_alpha.SetTextSize(0.04) ;
#       mframe.addObject(txt_alpha) ;
#
#       txt_chi2_initial = TLatex() ;
#       txt_chi2_initial.SetNDC()
#       txt_chi2_initial.SetText(0.69,0.7,"Initial #chi^{2} = " +str( round(initial_chi2, 2-int(floor(log10(initial_chi2)))-1)) )
#       txt_chi2_initial.SetTextSize(0.04) ;
#       mframe.addObject(txt_chi2_initial) ;
#
#       txt_chi2 = TLatex() ;
#       txt_chi2.SetNDC()
#       txt_chi2.SetText(0.697,0.65,"Final #chi^{2} = " + str( round(final_chi2, 2-int(floor(log10(final_chi2)))-1)) )
#       txt_chi2.SetTextSize(0.04) ;
#       mframe.addObject(txt_chi2) ;
# 
#       txt_mean_data = TLatex() ;
#       txt_mean_data.SetNDC()
#       txt_mean_data.SetText(0.7,0.6,"<M>_{data} = " +str( round(mean_data, 3-int(floor(log10(mean_data)))-1)) )
#       txt_mean_data.SetTextSize(0.04) ;
#       mframe.addObject(txt_mean_data) ;
#
#       txt_mean_mc = TLatex() ;
#       txt_mean_mc.SetNDC()
#       txt_mean_mc.SetText(0.71,0.55,"<M>_{mc} = " +str( round(mean_mc, 3-int(floor(log10(mean_mc)))-1)) )
#       txt_mean_mc.SetTextSize(0.04) ;
#       mframe.addObject(txt_mean_mc) ;
       
#       if (doToys):
#	  txt = TLatex() ;
#	  txt.SetNDC()
#	  toy_err = sum(a_rms) / float(len(a_rms))
#	  #txt.SetText(0.7,0.7,"Toy Error: " + str('%.2g' % toy_err) )
#	  txt.SetText(0.7,0.78,"Toy Error: " + str( round(toy_err, 2-int(floor(log10(toy_err)))-1)) + ' GeV')
#	  txt.SetTextSize(0.04) ;
#	  mframe.addObject(txt) ;
 
 
    #add plot labels and write out        
    txt1 = TLatex() ;
    txt1.SetNDC()
    txt1.SetTextFont(42)
    txt1.SetText(0.14,0.84,"#font[72]{ATLAS} Internal")
    txt1.SetTextSize(0.05) ;
    mframe.addObject(txt1) ;
    
    
    txt2 = TLatex() ;
    txt2.SetNDC()
    txt2.SetTextFont(42)
    if (tag == '2012'):
       txt2.SetText(0.14,0.77,"\\sqrt{s} = 8 TeV #int L dt = 20.7 fb^{-1}")
    elif (tag == '2011' or tag == '2011and2012'):
       txt2.SetText(0.14,0.77,"\\sqrt{s} = 7 TeV #int L dt = 4.6 fb^{-1}")
    txt2.SetTextSize(0.035) ;
    mframe.addObject(txt2) ;

    if (tag == '2011and2012'):
       txt3 = TLatex() ;
       txt3.SetNDC()
       txt3.SetTextFont(42)
       txt3.SetText(0.14,0.70,"\\sqrt{s} = 8 TeV #int L dt = 20.7 fb^{-1}")
       txt3.SetTextSize(0.035) ;
       mframe.addObject(txt3) ;

    mframe.Draw();

    #raw_input("Press ENTER to continue")   

    mframe.Write('fit_'+file_suffix)
    c1.Print(outputDir+'/fit_'+file_suffix+'.eps')

    if(showFit):  
       raw_input("Press ENTER to continue")   
           
    return;


def GetTChain(channel, files):
    
  chain = TChain() 
  
  if (channel == "inclusive"):  
    myChain_4mu   = TChain("tree_incl_4mu");
    myChain_2mu2e = TChain("tree_incl_2mu2e");
    myChain_2e2mu = TChain("tree_incl_2e2mu");
    myChain_4e    = TChain("tree_incl_4e");

    myChain_4mu.AddFileInfoList(files.GetList())
    myChain_2mu2e.AddFileInfoList(files.GetList())
    myChain_2e2mu.AddFileInfoList(files.GetList())
    myChain_4e.AddFileInfoList(files.GetList())

    myChain_4mu.SetName("tree_incl");
    myChain_2mu2e.SetName("tree_incl");
    myChain_2e2mu.SetName("tree_incl");
    myChain_4e.SetName("tree_incl");

    chain= TChain("tree_incl");	
    chain.Add(myChain_4mu  );
    chain.Add(myChain_2mu2e);
    chain.Add(myChain_2e2mu);
    chain.Add(myChain_4e   );

  else:
    chain = TChain(channel);
    chain.AddFileInfoList(files.GetList())

  return chain

