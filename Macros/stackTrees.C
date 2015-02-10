#include "StackMgr.C"
#include <string>
#include <vector>
#include "TSystem.h" 

void stackPlots()
{
      
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
  
  string InDir = "/local_data1/stahlman/output/HSG2_output/Moriond/minitrees/v02/MC12a/";
  //string InDir = "/local_data1/stahlman/output/HSG2_output/04062013/NoIso_FailD0/";
  //string InDir = "/local_data1/stahlman/output/HSG2_output/04062013/NoIso_NoD0_LooseRelaxed/";

  //string OutDir = InDir + "Plots/";
  string OutDir = "/local_data1/stahlman/output/HSG2_output/Moriond/Plots/";
  
  string tag = "test";
  //string tag = "FullSelection";
  //string tag = "NoIso_FailD0";
  //string tag = "NoIso_NoD0_LooseRelaxed";
  //string tag = "NoIso_NoD0_LooseRelaxed";
  
  string tag_zjets = "";
  //string tag_zjets = "CR_RelaxedML";
  //string tag_zjets = "CR_RelaxedMLOR";
  //string tag_zjets = "FullSelection";
  //string tag_zjets = "";
 
  //string tag_mod = "";
  string tag_mod = "test";
  //string tag_mod = "FullSel";
  //string tag_mod = "FullSel.RMLORShape";
  //string tag_mod = "DataNorm";
  //string tag_mod = ".NoData";
  //string tag_mod = ".Signalx1.66";
  //string tag_mod = ".SignalCat";

  string channel = "inclusive";
  //string channel = "tree_incl_4mu";
  //string channel = "tree_incl_2e2mu";
  //string channel = "tree_incl_4e";
  //string channel = "tree_incl_2mu2e";

  //int nbins = 0;
  double lumi = 1.;
  double SF_allMC=lumi;
  string Dir = "";

  string SubDir = "";
 
  StackMgr * stackMgr = new StackMgr(OutDir, tag+"_"+channel+"_"+tag_mod);  

  //****************************************************************************************************

  //********************//
  //ZZ
  //********************//

  //stackMgr->addMCMiniTree(InDir+"MC12a/*ZZ*.root",                             "inclusive", "ZZ", 	kRed+1,     SF_allMC,""); //ZZ
  //stackMgr->addMCMiniTree(InDir+"MC11c/*ZZ*.root",                             "inclusive", "ZZ", 	kRed+1,     SF_allMC,""); //ZZ

  stackMgr->addMCMiniTree(InDir+"/*ZZ*.root",  channel, "ZZ", 	kRed+1,     SF_allMC,""); //ZZ

  //********************//
  //ttbar
  //********************//

  double SF_ttbar = 1.;
  if (channel == "tree_incl_4mu" && tag == "NoIso_FailD0")   SF_ttbar = 79.8 / 53.8; //4mu 2012
  if (channel == "tree_incl_2e2mu" && tag == "NoIso_FailD0") SF_ttbar = 54.3 / 55.8; //2e2mu 2012
  stackMgr->addMCMiniTree(InDir+"/*ttbar*.root",  channel,   "ttbar",  kOrange+1,  SF_ttbar,""); //ttbar
  

  //********************//
  //Z + bb
  //********************//
  double SF_Zbb = 1.;
  if (channel == "tree_incl_4mu" && tag == "NoIso_FailD0")   SF_Zbb = 66.2 / 35.7; //4mu 2012
  if (channel == "tree_incl_2e2mu" && tag == "NoIso_FailD0") SF_Zbb = 68.6 / 31.0; //2e2mu 2012
  stackMgr->addMCMiniTree(InDir+"/*Zbb*.root",  channel,   "Zbb",  kGreen+1,  SF_Zbb,""); //Zjets

  //********************//
  //Z + jets
  //********************//
  
  double SF_Zjets = 1.;
  //SF_Zjets = 11.57 / 6786;
  //SF_Zjets = 11.57/10829.;  //2012 
  //SF_Zjets = 14.14/10829.;  // 2011+2012
  
  if (channel == "tree_incl_4e"    && tag == "NoIso_NoD0_LooseRelaxed") SF_Zjets = 442.2 / 590.7; //4e 2012
  if (channel == "tree_incl_2mu2e" && tag == "NoIso_NoD0_LooseRelaxed") SF_Zjets = 495.8 / 660.7; //2mu2e 2012

  //stackMgr->addMCMiniTree(InDir+"minitrees/MC12_Zjets_RelaxedMLOR.root",                     "inclusive",   "Z+jets,t#bar{t}",  kViolet+1,  SF_allMC*SF_Zjets,""); //Zjets
  //stackMgr->addMCMiniTree(InDir+"minitrees/v02/MC12a/ZPlusJetsForShapes/reduxbkg_tree_v2.root", "tree",   "Z+jets,t#bar{t}",  kViolet+1,  SF_allMC*SF_Zjets,""); //Zjets
  //stackMgr->addMCMiniTree(InDir+"minitrees/MC12_Zjets_RelaxedMLOR.root",                     "inclusive",   "Z+jets,t#bar{t}",  kViolet+1,  SF_allMC*SF_Zjets,""); //Zjets

  //stackMgr->addMCMiniTree(InDir+"/*Zjets*.root",  channel,   "Z+jets",  kViolet+1,  SF_allMC*SF_Zjets,""); //Zjets
  
  //********************//
  //signal
  //********************//
  
  //stackMgr->addMCMiniTree(InDir+"minitrees/v02/MC12a/Signal/Pythia8_AU2CTEQ6L1_*H125_ZZ4lep.root","inclusive", "VH(125)",     kAzure-5,   SF_allMC,""); //signal
  //stackMgr->addMCMiniTree(InDir+"minitrees/v02/MC12a/Signal/*VBFH125_ZZ4lep.root",		  "inclusive", "VBFH(125)",     kAzure-7,   SF_allMC,""); //signal
  //stackMgr->addMCMiniTree(InDir+"minitrees/v02/MC12a/Signal/*ggH125_ZZ4lep.root",	          "inclusive", "ggH(125)",       kAzure-9,   SF_allMC,""); //signal

  //stackMgr->addMCMiniTree(InDir+"minitrees/v02/MC11c/Signal/Pythia*H125_ZZ4lep.root",           "inclusive", "VH(125)",     kAzure-5,   SF_allMC,""); //signal
  //stackMgr->addMCMiniTree(InDir+"minitrees/v02/MC11c/Signal/PowHegPythia_VBFH125_ZZ4lep.root",	"inclusive", "VBFH(125)",     kAzure-7,   SF_allMC,""); //signal
  //stackMgr->addMCMiniTree(InDir+"minitrees/v02/MC11c/Signal/PowHegPythia_ggH125_ZZ4lep.root",	"inclusive", "ggH(125)",       kAzure-9,   SF_allMC,""); //signal
  
  //stackMgr->addMCMiniTree(InDir+"minitrees/v02/MC12a/Signal/*H125_ZZ4lep.root",              "inclusive", "H(125)",	kAzure-9,   SF_allMC,""); //signal
  //stackMgr->addMCMiniTree(InDir+"minitrees/v02/MC11c/Signal/*H125_ZZ4lep.root",              "inclusive", "H(125)",	kAzure-9,   SF_allMC,""); //signal

  stackMgr->addMCMiniTree(InDir+"/Signal/*H125_ZZ4lep.root",  channel, "H(125)",	kAzure-9,   SF_allMC,""); //signal

  //stackMgr->addMCMiniTree(InDir+"/*signal*.root", channel, "H(125)", kAzure-9, SF_allMC, ""); 

  //********************//
  //data
  //********************//

  stackMgr->addDataMiniTree(InDir+"../data12*.root",channel, "Data"); 
  //stackMgr->addDataMiniTree(InDir+"Data*.root",channel, "Data"); 
  
  
  
  //****************************************************************************************************
  string binpt = "((higgspt <20)+(higgspt>20&&higgspt<50)*2+(higgspt>50&&higgspt<100)*3+(higgspt>100)*4)";  
  
  string label = "H#rightarrow ZZ^{(*)} #rightarrow l^{+}l^{-}l^{+}l^{-}";
  string cut = "1";
    
  stackMgr->drawStackBranch(channel,"m4l_constrained",cut, "m4l",           "","M_{4l} [GeV]",    "Events / 4 GeV",label,"tr",false,(240-80)/4, 80, 240);
  stackMgr->drawStackBranch(channel,"m4l_constrained",cut, "m4l_FullRange", "","M_{4l} [GeV]",    "Events / 5 GeV",label,"tr",false,(800-80)/5, 80, 800);
  stackMgr->drawStackBranch(channel,"mZ1_constrained",cut, "m12",           "","M_{12} [GeV]",    "Events / 4 GeV",label,"tr",false,(140-40)/4, 40, 140);
  stackMgr->drawStackBranch(channel,"mZ2_constrained",cut, "m34",           "","M_{34} [GeV]",    "Events / 4 GeV",label,"tr",false,(140-0.)/4, 0., 140);

  stackMgr->drawStackBranch(channel,"higgspt",     cut, "pt4l",    "","p_{T}^{4l} [GeV]","Events / 5 GeV",label,"tr",false, (250-0.)/5, 0., 250);
  stackMgr->drawStackBranch(channel, binpt,        cut, "pt4lbin", "","p_{T}^{4l} bin","Events",label,"tr",false, 4,0.5,4.5);
  
  cut = "(higgspt <20)";
  stackMgr->drawStackBranch(channel,"m4l_constrained",cut,"m4l_PtBin1", "","M_{4l} [GeV]","Events / 5 GeV",label,"tr",false,(240-80)/5,80,240);
  stackMgr->drawStackBranch(channel,"mZ1_constrained",cut,"m12_PtBin1", "","M_{12} [GeV]","Events / 4 GeV",label,"tr",false,(140-40)/4, 40, 140);
  stackMgr->drawStackBranch(channel,"mZ2_constrained",cut,"m34_PtBin1", "","M_{34} [GeV]","Events / 4 GeV",label,"tr",false,(140-0.)/4, 0., 140);

  cut = "(higgspt<50&&higgspt>20)";
  stackMgr->drawStackBranch(channel,"m4l_constrained",cut,"m4l_PtBin2", "","M_{4l} [GeV]","Events / 5 GeV",label,"tr",false,(240-80)/5,80,240);
  stackMgr->drawStackBranch(channel,"mZ1_constrained",cut,"m12_PtBin2", "","M_{12} [GeV]","Events / 4 GeV",label,"tr",false,(140-40)/4, 40, 140);
  stackMgr->drawStackBranch(channel,"mZ2_constrained",cut,"m34_PtBin2", "","M_{34} [GeV]","Events / 4 GeV",label,"tr",false,(140-0.)/4, 0., 140);

  cut = "(higgspt<100&&higgspt>50)";
  stackMgr->drawStackBranch(channel,"m4l_constrained",cut,"m4l_PtBin3", "","M_{4l} [GeV]","Events / 5 GeV",label,"tr",false,(240-80)/5,80,240);
  stackMgr->drawStackBranch(channel,"mZ1_constrained",cut,"m12_PtBin3", "","M_{12} [GeV]","Events / 4 GeV",label,"tr",false,(140-40)/4, 40, 140);
  stackMgr->drawStackBranch(channel,"mZ2_constrained",cut,"m34_PtBin3", "","M_{34} [GeV]","Events / 4 GeV",label,"tr",false,(140-0.)/4, 0., 140);

  cut = "(higgspt >100)";
  stackMgr->drawStackBranch(channel,"m4l_constrained",cut,"m4l_PtBin4", "","M_{4l} [GeV]","Events / 5 GeV",label,"tr",false,(240-80)/5,80,240);
  stackMgr->drawStackBranch(channel,"mZ1_constrained",cut,"m12_PtBin4", "","M_{12} [GeV]","Events / 4 GeV",label,"tr",false,(140-40)/4, 40, 140);
  stackMgr->drawStackBranch(channel,"mZ2_constrained",cut,"m34_PtBin4", "","M_{34} [GeV]","Events / 4 GeV",label,"tr",false,(140-0.)/4, 0., 140);

  //signal region plots
  cut = "(m4l_constrained>120)&&(m4l_constrained<130)";
    
  stackMgr->drawStackBranch(channel,"higgspt", cut,"pt4l_SignalRegion", "","p_{T}^{4l} [GeV]","Events / 2 GeV",label,"tr",false,(300-0.)/2,0.,300);

  stackMgr->drawStackBranch(channel,binpt, cut,"pt4lbin_SignalRegion", "","p_{T}^{4l} bin","Events",label,"tr",false,4,0.5,4.5);

  //high mass plots
  cut = "(m4l_constrained>190)";
  stackMgr->drawStackBranch(channel,"higgspt", cut,"pt4l_HighMass",    "","p_{T}^{4l} [GeV]","Events / 25 GeV",label,"tr",false,(300-0.)/20,0.,300);
  stackMgr->drawStackBranch(channel, binpt,    cut,"pt4lbin_HighMass", "","p_{T}^{4l} bin","Events",label,"tr",false,4,0.5,4.5);

  //low mass plots
  cut = "(m4l_constrained<120)";
  stackMgr->drawStackBranch(channel,"higgspt", cut,"pt4l_LowMass", "","p_{T}^{4l} [GeV]","Events / 25 GeV",label,"tr",false,(300-0.)/25,0.,300);
  stackMgr->drawStackBranch(channel, binpt,    cut,"pt4lbin_LowMass", "","p_{T}^{4l} bin","Events",label,"tr",false,4,0.5,4.5);
 
  //4e channel
/*
  SF_Zjets = 2.7/ 5006.; //scale Z+jets to background estimate yield

  stackMgr_4e * stackMgr_4e = new stackMgr_4e(OutDir, tag+"_inclusive"+tag_mod);  
  
  stackMgr_4e->addMCMiniTree(InDir+"minitrees/v02/MC12a/*ZZ*.root",               "inclusive", "ZZ",    kRed+1,     SF_allMC,""); //ZZ
  stackMgr_4e->addMCMiniTree(InDir+"minitrees/v02/MC12a/Signal/*H125_ZZ4lep.root","inclusive", "H(125)",kAzure - 9 ,SF_allMC,""); //signal
			  
  stackMgr_4e->setDatafile(InDir+"minitrees/v02/data12.root",""); 
  
  string label = "H#rightarrow ZZ^{(*)} #rightarrow e^{+}e^{-}e^{+}e^{-}";
  string cut = "1"
    
  stackMgr_4e->drawStackBranch("inclusive","m4l_unconstrained",cut, OutDir+SubDir+"m_4e."+tag+tag_mod,  	"","M_{4e} [GeV]","Events / 4 GeV",label,"tr",false,(240-80)/4,80,240);
  stackMgr_4e->drawStackBranch("inclusive","m4l_unconstrained",cut, OutDir+SubDir+"m_4e.FullRange."+tag+tag_mod,"","M_{4e} [GeV]","Events / 5 GeV",label,"tr",false,(800-80)/5,80,800);
  stackMgr_4e->drawStackBranch("inclusive","mZ1_unconstrained",cut, OutDir+SubDir+"m_12_4e."+tag+tag_mod,	"","M_{12} [GeV]","Events / 4 GeV",label,"tr",false,(140-40)/4,40,140);
  stackMgr_4e->drawStackBranch("inclusive","mZ2_unconstrained",cut, OutDir+SubDir+"m_34_4e."+tag+tag_mod,	"","M_{34} [GeV]","Events / 4 GeV",label,"tr",false,(140-0.)/4,0.,140);
  
  //signal region plots
  cut = "(m4l_unconstrained>120)&&(m4l_unconstrained<130)"
  
  stackMgr_4e->drawStackBranch("inclusive","higgspt", cut, OutDir+SubDir+"higgspt."+tag+tag_mod, "","P_{T}^{4l} [GeV]","Events / 50 GeV",label,"tr",false,(200-0.)/50,0.,200);



  //2mu2e channel
  SF_Zjets = 3.8 / 5680.; //scale Z+jets to background estimate yield

  StackMgr * stackMgr_2mu2e = new StackMgr(OutDir, tag+"_2mu2e"+tag_mod);  
  
  stackMgr_2mu2e->addMCDataset(InDir+"/WZ_" + tag + "_passed.root", "WZ",kBlue+1 ,SF_allMC,""); //WZ
  //stackMgr_2mu2e->addMCDataset(InDir+"/ttbar_" + tag + "_passed.root", "ttbar",kOrange+1 ,SF_allMC,""); //ttbar
  //stackMgr_2mu2e->addMCDataset(InDir+"/Zbb_" + tag + "_passed.root", "Zbb",kGreen+1 ,SF_allMC,""); //Zbb
  stackMgr_2mu2e->addMCDataset(InDir+"/Zjets_" + tag_zjets + "_passed.root", "Z+jets, tt",kViolet+1 ,SF_allMC*SF_Zjets,""); //Zjets
  stackMgr_2mu2e->addMCDataset(InDir+"/ZZ_" + tag + "_passed.root", "ZZ",kRed+1 ,SF_allMC,""); //ZZ
			  
  stackMgr_2mu2e->setDatafile(InDir+"/Data_" + tag + "_passed.root",""); 

  stackMgr_2mu2e->addMCDataset(InDir+"/signal_" + tag + "_passed.root", "H(125)",kAzure - 9 ,SF_allMC,""); //signal

  // drawStack: Automatically makes a stack plot from the files added
  // hnameMC (in file), hnamedata, datanameForSave, plotTitle, xtitle, opt ="", log=true

  label = "H#rightarrow Z Z^{(*)} #rightarrow #mu^{+}#mu^{-}e^{+}e^{-}";
  nbins = 4;
  stackMgr_2mu2e->drawStackAdd("h_m_4l_2mu2e", OutDir+SubDir+"m_2mu2e."+tag+tag_mod, "","M_{2#mu2e} [GeV]",Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,240);
  nbins = 5;
  stackMgr_2mu2e->drawStackAdd("h_m_4l_2mu2e", OutDir+SubDir+"m_2mu2e.FullRange."+tag+tag_mod, "","M_{2#mu2e} [GeV]",Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,800);
  nbins = 2;
  stackMgr_2mu2e->drawStackAdd("h_m_12_2mu2e", OutDir+SubDir+"m_12_2mu2e."+tag+tag_mod, "","2#mu2e - M_{12} [GeV]",Form("Events / %i GeV", nbins),label,"tr",false,nbins,40,140);
  nbins = 5;
  stackMgr_2mu2e->drawStackAdd("h_m_34_2mu2e", OutDir+SubDir+"m_34_2mu2e."+tag+tag_mod, "","2#mu2e - M_{34} [GeV]",Form("Events / %i GeV", nbins),label,"tr",false,nbins,0,140);


  //Draw muon plots
  tag_zjets = "FullSelection";
  tag_mod = "";
  SF_Zjets = 1.;

  StackMgr * stackMgr_mu = new StackMgr(OutDir, tag+tag_mod);  
    
  stackMgr_mu->addMCDataset(InDir+"/WZ_" + tag + "_passed.root", "WZ",kBlue+1 ,SF_allMC,""); //WZ
  stackMgr_mu->addMCDataset(InDir+"/ttbar_" + tag + "_passed.root", "ttbar",kOrange+1 ,SF_allMC,""); //ttbar
  stackMgr_mu->addMCDataset(InDir+"/Zbb_" + tag + "_passed.root", "Zbb",kGreen+1 ,SF_allMC,""); //Zbb
  stackMgr_mu->addMCDataset(InDir+"/Zjets_" + tag_zjets + "_passed.root", "Z+jets",kViolet+1 ,SF_allMC*SF_Zjets,""); //Zjets
  stackMgr_mu->addMCDataset(InDir+"/ZZ_" + tag + "_passed.root", "ZZ",kRed+1 ,SF_allMC,""); //ZZ
			  
  stackMgr_mu->setDatafile(InDir+"/Data_" + tag + "_passed.root",""); 

  stackMgr_mu->addMCDataset(InDir+"/signal_" + tag + "_passed.root", "H(125)",kAzure - 9 ,SF_allMC,""); //signal

  // drawStack: Automatically makes a stack plot from the files added
  // hnameMC (in file), hnamedata, datanameForSave, plotTitle, xtitle, opt ="", log=true

  label = "H#rightarrow Z Z^{(*)} #rightarrow #mu^{+}#mu^{-}#mu^{+}#mu^{-}";

  nbins = 4;

  stackMgr_mu->drawStackAdd("h_m_4l_4mu",   OutDir+SubDir+"m_4mu."+tag+tag_mod,   "","M_{4#mu} [GeV]",  Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,240);

  nbins = 5;

  stackMgr_mu->drawStackAdd("h_m_4l_4mu",   OutDir+SubDir+"m_4mu.FullRange."+tag+tag_mod,   "","M_{4#mu} [GeV]",  Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,800);

  nbins = 2;

  stackMgr_mu->drawStackAdd("h_m_12_4mu",   OutDir+SubDir+"m_12_4mu."+tag+tag_mod,   "","4#mu - M_{12} [GeV]",  Form("Events / %i GeV", nbins),label,"tr",false,nbins,40,140);

  nbins = 5;

  stackMgr_mu->drawStackAdd("h_m_34_4mu",   OutDir+SubDir+"m_34_4mu."+tag+tag_mod,   "","4#mu - M_{34} [GeV]",  Form("Events / %i GeV", nbins),label,"tr",false,nbins,0,140);
  

  label = "H#rightarrow Z Z^{(*)} #rightarrow e^{+}e^{-}#mu^{+}#mu^{-}";
  nbins = 4;

  stackMgr_mu->drawStackAdd("h_m_4l_2e2mu", OutDir+SubDir+"m_2e2mu."+tag+tag_mod, "","M_{2e2#mu} [GeV]",Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,240);

  nbins = 5;

  stackMgr_mu->drawStackAdd("h_m_4l_2e2mu", OutDir+SubDir+"m_2e2mu.FullRange."+tag+tag_mod, "","M_{2e2#mu} [GeV]",Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,800);

  nbins = 2;

  stackMgr_mu->drawStackAdd("h_m_12_2e2mu", OutDir+SubDir+"m_12_2e2mu."+tag+tag_mod, "","2e2#mu - M_{12} [GeV]",Form("Events / %i GeV", nbins),label,"tr",false,nbins,40,140);

  nbins = 5;

  stackMgr_mu->drawStackAdd("h_m_34_2e2mu", OutDir+SubDir+"m_34_2e2mu."+tag+tag_mod, "","2e2#mu - M_{34} [GeV]",Form("Events / %i GeV", nbins),label,"tr",false,nbins,0,140);


  StackMgr * stackMgr_pt = new StackMgr(OutDir, tag+"_pt"+tag_mod);  
  
  stackMgr_pt->addMCDataset(InDir+"/ZZ_" + tag + "_passed.root", "ZZ",kRed+1 ,SF_allMC,""); //ZZ			  
  stackMgr_pt->setDatafile(InDir+"/Data_" + tag + "_passed.root",""); 

  // drawStack: Automatically makes a stack plot from the files added
  // hnameMC (in file), hnamedata, datanameForSave, plotTitle, xtitle, opt ="", log=true
  
  label = "H#rightarrow ZZ^{(*)} #rightarrow l^{+}l^{-}l^{+}l^{-}";
  nbins = 10;
  stackMgr_pt->drawStackAdd("h_pt_mu",OutDir+SubDir+"pt_mu."+tag+tag_mod,   "","p_{T} [GeV]", "",label,"tr",false,nbins,0,200);  
  stackMgr_pt->drawStackAdd("h_pt_e", OutDir+SubDir+"pt_e."+tag+tag_mod,    "","p_{T} [GeV]", "",label,"tr",false,nbins,0,200);  

*/
  delete stackMgr;
 
  return;
}
