#include "StackMgr.C"
#include <string>
#include <vector>
#include "TSystem.h" 


void stackPlots()
{
      
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
  
  //string InDir = "/local_data1/stahlman/output/HSG2_output/21012013/";
  //string InDir = "/local_data1/stahlman/output/HSG2_output/22012013/";
  //string InDir = "/local_data1/stahlman/output/HSG2_output/24012013/";
  //string InDir = "/local_data1/stahlman/output/HSG2_output/27012013/";
  //string InDir = "/local_data1/stahlman/output/HSG2_output/29012013/";
  //string InDir = "/local_data1/stahlman/output/HSG2_output/31012013/";
  //string InDir = "/local_data1/stahlman/output/HSG2_output/05022013/";
  //string InDir = "/local_data1/stahlman/output/HSG2_output/06022013/";
  string InDir = "/local_data1/stahlman/output/HSG2_output/Moriond/";
  
  //string OutDir = "/local_data1/stahlman/output/HSG2_output/17012013/Plots/";
  //string OutDir = "/local_data1/stahlman/output/HSG2_output/21012013/Plots/";
  //string OutDir = "/local_data1/stahlman/output/HSG2_output/22012013/Plots/";
  //string OutDir = "/local_data1/stahlman/output/HSG2_output/24012013/Plots/";
  string OutDir = InDir + "Plots/";
  
  //tag = "3.5ControlRegion"
  //string tag = "3.5ControlRegion_Unblind";
  //string tag = "NoID";
  //string tag = "3_5ID";
  //string tag = "SS_3_5ID";
  //string tag = "CR_RelaxedML";
  //string tag = "CR_RelaxedMLOR";
  //string tag = "SS_CR_RelaxedML";
  //string tag = "CR_SiTrack";
  //string tag = "FullSelection";
  string tag = "FullSelection.SignalRegion";
  
  //string tag_zjets = "CR_RelaxedML";
  //string tag_zjets = "CR_RelaxedMLOR";
  //string tag_zjets = "FullSelection";
  string tag_zjets = "CR.RelaxedMLOR";
  //string tag_zjets = "";

  double SF_Zjets = 1.;
 
  //string tag_mod = "";
  //string tag_mod = "FullSel";
  //string tag_mod = "FullSel.RMLORShape";
  string tag_mod = ".RMLORShape";


  int nbins = 0;
  double lumi = 20.7/13;
  double SF_signal_1000=lumi;
  double SF_allMC=lumi;
  string Dir = "";

  //SF_Zjets = 11.57 / 10686;
  SF_Zjets = 1.92 / 1474;  //signal region
 
  StackMgr * stackMgr = new StackMgr(OutDir, tag+"_inclusive"+tag_mod);  
  
  //stackMgr->addMCDataset(InDir+"/WZ_" + tag + "_passed.root", "WZ",kBlue+1 ,SF_allMC,""); //WZ
  //stackMgr->addMCDataset(InDir+"/ttbar_" + tag + "_passed.root", "ttbar",kOrange+1 ,SF_allMC,""); //ttbar
  //stackMgr->addMCDataset(InDir+"/Zbb_" + tag + "_passed.root", "Zbb",kGreen+1 ,SF_allMC,""); //Zbb
  stackMgr->addMCDataset(InDir+"/Zjets_" + tag_zjets + "_passed.root", "Z+jets, tt",kViolet+1 ,SF_allMC*SF_Zjets,""); //Zjets
  stackMgr->addMCDataset(InDir+"/ZZ_" + tag + "_passed.root", "ZZ",kRed+1 ,SF_allMC,""); //ZZ
			  
  stackMgr->setDatafile(InDir+"/Data_" + tag + "_passed.root",""); 

  stackMgr->addMCDataset(InDir+"/signal_" + tag + "_passed.root", "H(125)",kAzure - 9 ,SF_allMC,""); //signal
  //stackMgr->addMCDataset_signal(InDir+"/signal" + tag + "_passed.root", "signal",kRed ,SF_allMC,""); //signal

  // drawStack: Automatically makes a stack plot from the files added
  // hnameMC (in file), hnamedata, datanameForSave, plotTitle, xtitle, opt ="", log=true

  string SubDir = "";
  
  string label = "H#rightarrow ZZ^{(*)} #rightarrow l^{+}l^{-}l^{+}l^{-}";
  nbins = 4;
/*  
  stackMgr->drawStackAdd("h_m_4l",       OutDir+SubDir+"m_4l."+tag+tag_mod,    "","M_{4l} [GeV]",    Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,240);  
  nbins = 5;
  stackMgr->drawStackAdd("h_m_4l",       OutDir+SubDir+"m_4l.FullRange."+tag+tag_mod,    "","M_{4l} [GeV]",    Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,800);  
  nbins = 2;
  stackMgr->drawStackAdd("h_m_12",       OutDir+SubDir+"m_12."+tag+tag_mod,       "","M_{12} [GeV]",         Form("Events / %i GeV", nbins),label,"tr",false,nbins,40,140);
  nbins = 5;
  stackMgr->drawStackAdd("h_m_34",       OutDir+SubDir+"m_34."+tag+tag_mod,       "","M_{34} [GeV]",         Form("Events / %i GeV", nbins),label,"tr",false,nbins,0,140);
*/

  stackMgr->drawStackAdd("h_met_reffinal_et",  OutDir+SubDir+"met_reffinal_et."+tag+tag_mod,	"","E_{T}^{miss} [GeV]",	 Form("Events / %i GeV", nbins),label,"tr",false,25,0,150);
  stackMgr->drawStackAdd("h_pt",               OutDir+SubDir+"pt."+tag+tag_mod,	"","p_{T} [GeV]",	 Form("Events / %i GeV", nbins),label,"tr",false,50,0,300);
  stackMgr->drawStackAdd("h_n_jets",           OutDir+SubDir+"n_jets."+tag+tag_mod,	"","N_{jets}",	 Form("Events", nbins),label,"tr",false,1,0,10);
 
/* 
  //4e channel

  SF_Zjets = 2.7/ 5006.; //scale Z+jets to background estimate yield

  StackMgr * stackMgr_4e = new StackMgr(OutDir, tag+"_4e"+tag_mod);  
  
  stackMgr_4e->addMCDataset(InDir+"/WZ_" + tag + "_passed.root", "WZ",kBlue+1 ,SF_allMC,""); //WZ
  //stackMgr_4e->addMCDataset(InDir+"/ttbar_" + tag + "_passed.root", "ttbar",kOrange+1 ,SF_allMC,""); //ttbar
  //stackMgr_4e->addMCDataset(InDir+"/Zbb_" + tag + "_passed.root", "Zbb",kGreen+1 ,SF_allMC,""); //Zbb
  stackMgr_4e->addMCDataset(InDir+"/Zjets_" + tag_zjets + "_passed.root", "Z+jets, tt",kViolet+1 ,SF_allMC*SF_Zjets,""); //Zjets
  stackMgr_4e->addMCDataset(InDir+"/ZZ_" + tag + "_passed.root", "ZZ",kRed+1 ,SF_allMC,""); //ZZ
			  
  stackMgr_4e->setDatafile(InDir+"/Data_" + tag + "_passed.root",""); 

  stackMgr_4e->addMCDataset(InDir+"/signal_" + tag + "_passed.root", "H(125)",kAzure - 9 ,SF_allMC,""); //signal

  // drawStack: Automatically makes a stack plot from the files added
  // hnameMC (in file), hnamedata, datanameForSave, plotTitle, xtitle, opt ="", log=true

  label = "H#rightarrow Z Z^{(*)} #rightarrow e^{+}e^{-}e^{+}e^{-}";
  nbins = 4;
  stackMgr_4e->drawStackAdd("h_m_4l_4e",    OutDir+SubDir+"m_4e."+tag+tag_mod,    "","M_{4e} [GeV]",    Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,240);
  nbins = 5;
  stackMgr_4e->drawStackAdd("h_m_4l_4e",    OutDir+SubDir+"m_4e.FullRange."+tag+tag_mod,    "","M_{4e} [GeV]",    Form("Events / %i GeV", nbins),label,"tr",false,nbins,80,800);
  nbins = 2;
  stackMgr_4e->drawStackAdd("h_m_12_4e",    OutDir+SubDir+"m_12_4e."+tag+tag_mod,    "","4e - M_{12} [GeV]",    Form("Events / %i GeV", nbins),label,"tr",false,nbins,40,140);
  nbins = 5;
  stackMgr_4e->drawStackAdd("h_m_34_4e",    OutDir+SubDir+"m_34_4e."+tag+tag_mod,    "","4e - M_{34} [GeV]",    Form("Events / %i GeV", nbins),label,"tr",false,nbins,0,140);



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
  return;
}
