///////////////////////////////////////////////////////////////////////////////////////////
//  Sarah Heim
//  Inspired by StackMgr.C by Andrew Meade
//  Designed to take a set of input files, each corresponding to a physics process (ex zmumu)
//  drawStack() will then produce a well formated stack plot for a given histogram
//  MC can be scaled either to a set luminosity, or to the entries in the data plot.
///////////////////////////////////////////////////////////////////////////////////////////



#ifndef STACKMRG_HH
#define STACKMRG_HH

// STD includes
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>


#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TProfile.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TSystem.h"
#include "TPad.h"
#include "TMath.h"
#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TROOT.h"
#include "THStack.h"
#include "TLatex.h"
#include "TGaxis.h"
#include "TTree.h"
#include "TChain.h"


class StackMgr {

protected:
  bool m_debug;

  // defines all the objects that will be used
  // for stack plots
  TFile * m_datafile;
  string  m_datafilename;
  
  TChain* m_datachain;
  string  m_dataname;
  
  std::vector<TFile*> m_fileVec;
  std::vector<TChain*> m_chainVec;
  std::vector<string> m_datanameVec; // the name for legends
  std::vector<string> m_dirnameVec; // the name for legends
  std::vector<string> m_filenameVec;  
  std::vector<int> m_colorVec;
  std::vector<double> m_scaleFacVec;

  std::vector<TFile*> m_fileVec_signal;
  std::vector<string> m_datanameVec_signal; // the name for legends
  std::vector<string> m_dirnameVec_signal; // the name for legends
  std::vector<string> m_filenameVec_signal;  
  std::vector<int> m_colorVec_signal;
  std::vector<double> m_scaleFacVec_signal;

  std::vector<TFile*> m_fileVecAdd;
  std::vector<string> m_datanameVecAdd; // the name for legends
   std::vector<string> m_dirnameVecAdd; // the name for legends
  std::vector<string> m_filenameVecAdd;  
  std::vector<int> m_colorVecAdd;
  std::vector<double> m_scaleFacVecAdd;
  
  float m_luminosity; // luminosity to scale to
  bool useLuminosity; // if the luminosity is externally set, use it
                      // otherwise, scale to nevents in final histo

  // these are pointers to the graphics objects the
  // mgr is currently working on
  TCanvas * m_canvas;
  std::vector<TH1*> m_currentHistVec;
  std::vector<TH1*> m_currentHistErrorVec;
  TH1* m_currentDataHist;
  TH1* m_currentDataHist2;
  TH1* m_currentDataHist3;
  THStack * m_stack;
  THStack * m_stackError;
  std::string m_title;
  string m_datadirname;
  string m_tag;
  
  int m_nCanvas;

  TFile * m_outputfile;
  string m_outDir; 

public:
  StackMgr(string outdir, string tag); 
  ~StackMgr();
  
  void addMCDataset(std::string filename, std::string dataname, int color, float scalefac = 1, string dir = "");
  void addMCDatasetAdd(std::string filename, std::string dataname, int color, float scalefac = 1, string dir = "");
  void setDatafile(std::string filename, string dir);
  THStack * drawStack(std::string hname, std::string hnameData, std::string hnameAntiData, std::string hnameSave, std::string plotTitle, std::string xtitle, std::string ytitle="Entries", std::string opt = "", bool log=true, int Rebin = 1, double xmin = 999, double xmax = 999);
  THStack * drawStackAdd(std::string hname, std::string hnameSave,std::string plotTitle, std::string xtitle, std::string ytitle="Entries", string label="", std::string opt = "", bool log=true, int Rebin = 1, double xmin = 999, double xmax = 999, double ymin=999, double ymax=999);
  THStack * drawStackSimple(std::string hname, std::string hnameData,std::string hnameSave, std::string plotTitle, std::string xtitle, std::string ytitle="Entries", std::string opt = "", bool log=true, int Rebin = 1, double xmin = 999, double xmax = 999, bool normalize=false);

  void addDataMiniTree(string filename, string tree_name, string label);
  void addMCMiniTree(string filename, string tree_name, string label, int color,float scalefac,string dir);
  THStack * drawStackBranch(string tree_name, string branch_name,string cut,string tag, string plotTitle, string xtitle, string ytitle, string label, string opt, bool log,int xbins, double xmin, double xmax, double ymin =999, double ymax=999);

  TCanvas * newCanvas(std::string canvasTitle="NONE", bool drawRatio=false);
  
  TH1 * StackSum(THStack*);
  
  void addMCDataset_signal(std::string filename, std::string dataname, int color, float scalefac = 1, string dir = "");


  TFile *f;

};

//Start of cxx

 


using namespace std;

StackMgr::StackMgr(string outdir, string tag) : 
  m_debug(false), m_datafile(0), m_luminosity(1), m_nCanvas(0), m_outDir(outdir)
{
  if (m_debug) cout << "In StackMgr()" << endl;
  
  m_tag = tag;
  
  m_outputfile = new TFile(Form("%s%s%s%s",outdir.c_str(),"/",tag.c_str(),"_plots.root"),"RECREATE");

 
}

StackMgr::~StackMgr(){ 
  cout << "Closing output file: " << endl;
  cout << m_outputfile->GetPath() << endl;
  m_outputfile->Close(); 

}

void StackMgr::setDatafile(string filename, string dir){
  m_datafile = 0;
  m_datafilename = filename;
  m_datafile = new TFile(filename.c_str(),"READ");
  if (m_datafile == 0 ) cout << "ERROR: file not found! " << filename << endl;
  m_datadirname = dir;
  return;
}

void StackMgr::addDataMiniTree(string filename, string tree_name, string label){
  m_datachain = 0;

  if (tree_name == "inclusive"){   
    TChain * myChain_4mu   = new TChain("tree_incl_4mu");
    TChain * myChain_2mu2e = new TChain("tree_incl_2mu2e");
    TChain * myChain_2e2mu = new TChain("tree_incl_2e2mu");
    TChain * myChain_4e    = new TChain("tree_incl_4e");

    myChain_4mu->Add(filename.c_str());  
    myChain_2mu2e->Add(filename.c_str());  
    myChain_2e2mu->Add(filename.c_str());  
    myChain_4e->Add(filename.c_str());  

    myChain_4mu->SetName("tree_incl");
    myChain_2mu2e->SetName("tree_incl");
    myChain_2e2mu->SetName("tree_incl");
    myChain_4e->SetName("tree_incl");
    
    m_datachain= new TChain("tree_incl");    
    m_datachain->Add(myChain_4mu  );
    m_datachain->Add(myChain_2mu2e);
    m_datachain->Add(myChain_2e2mu);
    m_datachain->Add(myChain_4e   );

  } else {
    m_datachain = new TChain(tree_name.c_str());
    m_datachain->Add(filename.c_str());    
  }

  m_datafilename = filename;
  m_dataname = label;
    
  return;
}

void StackMgr::addMCMiniTree(string filename, string tree_name, string label, int color,float scalefac,string dir){

  TChain * myChain = 0;

  if (tree_name == "inclusive"){   
    TChain * myChain_4mu   = new TChain("tree_incl_4mu");
    TChain * myChain_2mu2e = new TChain("tree_incl_2mu2e");
    TChain * myChain_2e2mu = new TChain("tree_incl_2e2mu");
    TChain * myChain_4e    = new TChain("tree_incl_4e");

    myChain_4mu->Add(filename.c_str());  
    myChain_2mu2e->Add(filename.c_str());  
    myChain_2e2mu->Add(filename.c_str());  
    myChain_4e->Add(filename.c_str());  

    myChain_4mu->SetName("tree_incl");
    myChain_2mu2e->SetName("tree_incl");
    myChain_2e2mu->SetName("tree_incl");
    myChain_4e->SetName("tree_incl");
    
    myChain= new TChain("tree_incl");    
    myChain->Add(myChain_4mu  );
    myChain->Add(myChain_2mu2e);
    myChain->Add(myChain_2e2mu);
    myChain->Add(myChain_4e   );

  } else {
    myChain = new TChain(tree_name.c_str());
    myChain->Add(filename.c_str());    
  }


  int index = -1;
  if (std::find(m_datanameVec.begin(), m_datanameVec.end(), label) != m_datanameVec.end()) {
     index = distance(m_datanameVec.begin(), find(m_datanameVec.begin(),m_datanameVec.end(), label));       
  }
    
  if (index != -1){
    m_chainVec[index]->Add(myChain);
  
  } else {
   
    m_chainVec.push_back(myChain);
    m_filenameVec.push_back(filename);
    m_dirnameVec.push_back(dir);
    m_datanameVec.push_back(label);
    m_colorVec.push_back(color);

    m_scaleFacVec.push_back(scalefac);
  }
    
  return;
}


void StackMgr::addMCDataset(string filename, string dataname, int color,float scalefac,string dir){
  TFile * myFile = 0;
  myFile = new TFile(filename.c_str(),"READ");
  if (myFile == 0 ) cout << "ERROR: file not found! " << filename << endl;
  m_fileVec.push_back(myFile);
  m_filenameVec.push_back(filename);
  m_dirnameVec.push_back(dir);
  m_datanameVec.push_back(dataname);
  m_colorVec.push_back(color);
  
  m_scaleFacVec.push_back(scalefac);
  
  return;
}

void StackMgr::addMCDataset_signal(string filename, string dataname, int color,float scalefac,string dir){
  TFile * myFile = 0;
  myFile = new TFile(filename.c_str(),"READ");
  if (myFile == 0 ) cout << "ERROR: file not found! " << filename << endl;
  m_fileVec_signal.push_back(myFile);
  m_filenameVec_signal.push_back(filename);
  m_dirnameVec_signal.push_back(dir);
  m_datanameVec_signal.push_back(dataname);
  m_colorVec_signal.push_back(color);
  
  m_scaleFacVec_signal.push_back(scalefac);

  return;
}

void StackMgr::addMCDatasetAdd(string filename, string dataname, int color,float scalefac,string dir){
  TFile * myFile = 0;
  myFile = new TFile(filename.c_str(),"READ");
  if (myFile == 0 ) cout << "ERROR: file not found! " << filename << endl;
  m_fileVecAdd.push_back(myFile);
  m_filenameVecAdd.push_back(filename);
  m_dirnameVecAdd.push_back(dir);
  m_datanameVecAdd.push_back(dataname);
  m_colorVecAdd.push_back(color);
  
  m_scaleFacVecAdd.push_back(scalefac);
  
  return;
}


THStack * StackMgr::drawStackAdd(string hname, string hnameSave, string plotTitle, string xtitle, string ytitle, string label, string opt, bool log,int RebinFac, double xmin, double xmax, double ymin, double ymax){

  
  double maximum = 1;

  int size = m_fileVec.size();
  m_canvas = newCanvas();
  //m_canvas->SetBottomMargin (0.30); //for ratio plots
  m_canvas->cd(1);
  //m_title = plotTitle;
  // m_stack = new THStack((hname+"_stack").c_str(), (plotTitle+";;").c_str());
  m_title = "";
  m_stack = new THStack((hname+"_stack").c_str(), "");

   //if signal fill vector, scale
  vector<TH1*> Signal_Vec;
  
  //cout<< "adding signal hists" << endl;
  
  //if(opt == "signal"){
  TH1* hist_signal = 0;
  for(int i = 0; i <  m_fileVec_signal.size(); i++){
    if(m_dirnameVec[i] != "") hist_signal = (TH1F*)((TDirectory*) m_fileVec_signal[i]->Get((m_dirnameVec_signal[i]+"/"+hname).c_str()))->Clone("hist_signal");
    else hist_signal = (TH1F*)((TDirectory*) m_fileVec_signal[i]->Get(hname.c_str()))->Clone("hist_signal");
    hist_signal->Scale(m_scaleFacVec_signal[i]);
    hist_signal->Rebin(RebinFac);
    hist_signal->SetLineColor(m_colorVec_signal[i]);
    Signal_Vec.push_back(hist_signal);
  }
  //}

 
   // loop over different datasets to stack
  for (int i = 0; i < size; i++){

    //cout<<"sample/dataset number: "<<i<<endl;

    TH1* hist = 0;
    //TH1* hist2 = 0;
       
   
    if(m_dirnameVec[i] != "") hist = (TH1F*)((TDirectory*) m_fileVec[i]->Get((m_dirnameVec[i]+"/"+hname).c_str()))->Clone("hist");
    else hist = (TH1F*)((TDirectory*) m_fileVec[i]->Get((hname).c_str()))->Clone("hist");       
       

/*       if(m_datanameVec[i] == "QCD" )  {
      for(int iadd = 0; iadd < m_datanameVecAdd.size(); iadd++){
	if(m_datanameVecAdd[iadd] != "QCD2") continue;
	hist2 = (TH1F*)((TDirectory*) m_fileVecAdd[iadd]->Get((m_dirnameVecAdd[iadd]+"/"+hname).c_str()))->Clone("hist");
	hist2->Scale(m_scaleFacVecAdd[iadd]);
	hist2->Rebin(RebinFac);
      }
    }

    else if(m_datanameVec[i] == "Z/#gamma*" )  {
     
        for(int iadd = 0; iadd < m_datanameVecAdd.size(); iadd++){
	if(m_datanameVecAdd[iadd] != "DY") continue;
	hist2 = (TH1F*)((TDirectory*) m_fileVecAdd[iadd]->Get((m_dirnameVecAdd[iadd]+"/"+hname).c_str()))->Clone("hist");
	hist2->Scale(m_scaleFacVecAdd[iadd]);
	hist2->Rebin(RebinFac);
      }
    }    
 */  
    
    if (hist == 0){
      cout << "Simu file" << endl;
      cout << "Error, hist not found: " << hname << " " << m_filenameVec[i] << endl;
      TH1F * temphist =  (TH1F*)((TDirectory*) m_datafile->Get(hname.c_str()));
      //make an empty histogram with the right range
      hist = new TH1F((hname+"_dummy").c_str(),hname.c_str(),temphist->GetNbinsX(),
		      temphist->GetXaxis()->GetXmin(), temphist->GetXaxis()->GetXmax());
    }
    
    hist->Scale(m_scaleFacVec[i]);
    hist->Rebin(RebinFac);
    hist->SetFillColor(m_colorVec[i]);
    hist->SetLineColor(1);
    hist->GetXaxis()->SetTitle(xtitle.c_str());
    hist->GetYaxis()->SetTitle(ytitle.c_str());

    //if(m_datanameVec[i] == "QCD" && hist2 !=0 ) hist->Add(hist2);
    //if(m_datanameVec[i] == "Z/#gamma*" ) hist->Add(hist2);
/*
    if(m_datanameVec[i] == "Z+jets" || m_datanameVec[i] == "Z+jets         ")  { //inflate errors due to scaling uncertainty
       for (int j =0; j<hist->GetNbinsX()+1; ++j){
           double scale_err = 0.0032; //TODO FIX THIS
           //double scale_err = 1; //TODO FIX THIS
           double error = hist->GetBinError(j);
	   if (hist->GetBinContent(j) != 0){
	      error = hist->GetBinContent(j)*sqrt((hist->GetBinError(j)/hist->GetBinContent(j))*(hist->GetBinError(j)/hist->GetBinContent(j)) + (scale_err/m_scaleFacVec[i])*(scale_err/m_scaleFacVec[i]));
   	      //cout << "Bin: "<< hist->GetBinContent(j) << "+/-"<<error<< " " << error/ hist->GetBinContent(j)<< endl;;
           }
	   //cout << "Bin: "<< hist->GetBinContent(j) << "+/-"<<error<< << endl;;
	   hist->SetBinError(j,error);	   
       } 
       //hist->Sumw2();      
    }
*/  


    //double xvalueRap = 0;
    //double yvalueRap = 0;
    //int newbin = 0;
    //TH1F * temphistRap;

    hist->SetFillColor(m_colorVec[i]);
    hist->SetLineColor(1);
    hist->GetXaxis()->SetTitle(xtitle.c_str());
    //  hist->GetXaxis()->SetTitleOffset(1.8);
    hist->GetYaxis()->SetTitle(ytitle.c_str());
    //hist->GetYaxis()->SetMaxDigits(2);
   TGaxis::SetMaxDigits(4);
    
    m_currentHistVec.push_back(hist);
  }

  cout<<" m_currentHistVec.: "<< m_currentHistVec.size()<<endl;

  TGraphAsymmErrors *Data = new TGraphAsymmErrors();
  //TH1F * temphistRapData;
  //double xvalueRapData = 0;
  //double yvalueRapData = 0;
  //int newbinData = 0;
  TH1* data_stack_sum =  new TH1();


  if (m_datafile != 0){
    m_currentDataHist = 0;
    if(m_datadirname != "") m_currentDataHist = (TH1F*)((TDirectory*) m_datafile->Get((m_datadirname+"/"+hname).c_str()))->Clone("hist");
    else m_currentDataHist = (TH1F*)((TDirectory*) m_datafile->Get((hname).c_str()))->Clone("hist");

    if (m_currentDataHist == 0){ 
      cout << "For Data file:" << endl;
      cout << "Error, hist not found: " << hname << endl;
      
    } else {

          
	// data_entries = m_currentDataHist->GetEntries();
      m_currentDataHist->Sumw2();
      m_currentDataHist->Rebin(RebinFac);
      maximum = m_currentDataHist->GetMaximum();
      
      
       if(opt == "normiso"){

	 int binlow = m_currentDataHist->FindBin(-2);
	 int binhigh = m_currentDataHist->FindBin(2);

	 double integralData =  m_currentDataHist->Integral(binlow,binhigh-1);
	 double integralMC = 0;
	 for(int iMC = 0; iMC < m_currentHistVec.size(); iMC++){
	   integralMC += m_currentHistVec[iMC]->Integral(binlow,binhigh-1);
	 }
	  for(int iMC = 0; iMC < m_currentHistVec.size(); iMC++){
	   m_currentHistVec[iMC]->Scale(integralData/integralMC);
	 }
    }
         if(opt == "normmass"){

	 int binlow = m_currentDataHist->FindBin(70);
	 int binhigh = m_currentDataHist->FindBin(130);

	 double integralData =  m_currentDataHist->Integral(binlow,binhigh-1);
	 double integralMC = 0;
	 for(int iMC = 0; iMC < m_currentHistVec.size(); iMC++){
	   integralMC += m_currentHistVec[iMC]->Integral(binlow,binhigh-1);
	 }
	  for(int iMC = 0; iMC < m_currentHistVec.size(); iMC++){
	   m_currentHistVec[iMC]->Scale(integralData/integralMC);
	 }
    }
     
        //clone hist for ratio plot here before errors are zeroed (=>not entirely correct error treatment in ratio)
       data_stack_sum = (TH1*)m_currentDataHist->Clone(Form("%s_data_sum",m_stack->GetName()));

       double value = 0;
       double error_poisson_up   = 0;
       double error_poisson_down = 0;
       double y1 = 0;
       double y2 = 0;
       double d1 = 0;
       double d2 = 0;
       for(int i=1; i<=m_currentDataHist->GetNbinsX(); i++){


	 m_currentDataHist->SetBinError(i,0);

	 value = m_currentDataHist->GetBinContent(i);
	 if(value!=0) { 
	   y1 = value + 1.0;
	   d1 = 1.0 - 1.0/(9.0*y1) + 1.0/(3*TMath::Sqrt(y1));
	   error_poisson_up = y1*d1*d1*d1 - value;
	   y2 = value;
	   d2 = 1.0 - 1.0/(9.0*y2) - 1.0/(3.0*TMath::Sqrt(y2));
	   error_poisson_down = value - y2*d2*d2*d2;
	   Data->SetPoint(i-1, m_currentDataHist->GetBinCenter(i), value);
	   Data->SetPointError(i-1, 0, 0, error_poisson_down, error_poisson_up);
	 }
	 else{
	   Data->SetPoint(i-1, -999, value);
	 }
       }
     

       Data->SetMarkerStyle(20);
       Data->SetLineWidth(2.);

       m_currentDataHist->SetTitle(("; "+ xtitle + "; " + ytitle) .c_str());
       Data->GetXaxis()->SetTitle(xtitle.c_str());
       Data->GetYaxis()->SetTitle(ytitle.c_str());
       m_currentDataHist->GetYaxis()->SetTitleOffset(1.2);
       m_currentDataHist->GetXaxis()->SetTitle(xtitle.c_str());
       m_currentDataHist->GetYaxis()->SetTitle(ytitle.c_str());
    
    }
  }    

  int iQCD = 0;
  if(opt == "high" && !log){
    for (int i = 0; i < size; i++){
      if(m_datanameVec[i] == "Z/#gamma*") iQCD = i;
    }
     for (int i = 0; i < size; i++){
       if(i == iQCD) m_stack->Add(m_currentHistVec[i]);
     }
  }
  else if(opt == "Dijets" || opt=="normiso"){
    for (int i = 0; i < size; i++){
      if(m_datanameVec[i] == "QCD") iQCD = i;
    }
    m_stack->Add(m_currentHistVec[iQCD]);
     for (int i = 0; i < size; i++){
       if(i == iQCD) continue;
       m_stack->Add(m_currentHistVec[i]);
     }

  }
  else{
    for (int i = 0; i < size; i++){
      m_stack->Add(m_currentHistVec[i]);
    }
  }
  
  bool high = 0;
  if(xtitle == "cos(#theta^{*})" || opt == "high") high = 1;
    
  if (log) {  gPad->SetLogy(); //hist->GetYaxis()->SetRangeUser(1,1000000);
  }

  if(opt == "logX") gPad->SetLogx();
  

   if(log){
     m_currentDataHist->SetMinimum(0.02);
     if(ymin != 999)   m_currentDataHist->SetMinimum(ymin);
     m_currentDataHist->SetMaximum(maximum*20);

     if(high)  m_currentDataHist->SetMaximum(maximum*200);
  } else {
    
     if(ymin != 999) m_currentDataHist->SetMinimum(ymin);
     else  m_currentDataHist->SetMinimum(0.001);
     if(ymax != 999) m_currentDataHist->SetMaximum(ymax);
     else  m_currentDataHist->SetMaximum(maximum*2);
    if(high)  m_currentDataHist->SetMaximum(maximum*1.5);	 
  }
  
  if(xmin !=999) m_currentDataHist->GetXaxis()->SetRangeUser(xmin,xmax-0.000001);

  TPad* pad0 = new TPad("pad", "pad", 0., 0., 1.,0.30);
  pad0->SetTopMargin(0.03);
  pad0->SetBottomMargin(0.4);
  pad0->SetFillColor(0);
  //pad->SetFillStyle(0);
  pad0->Draw();

  TPad* pad1 = new TPad("pad1", "pad", 0., 0.3, 1.,1.);
  pad1->SetBottomMargin(0);
  pad1->Draw();
  
  
  pad1->cd(0);
  
  //m_currentDataHist->GetXaxis()->SetLabelSize(0.0);
  
  m_currentDataHist->Draw("*");

  m_stack->Draw("histsame");
  m_currentDataHist->Draw("axissame");
  Data->Draw("psame");

  //if(opt == "signal"){
  for(int i = 0; i < Signal_Vec.size(); i++){
    Signal_Vec[i]->Draw("histsame");
  }
  //}


  
 char writetext1[100];
 char writetext2[100];
 char writetext3[100];
 char writetext4[100];
 TLatex *t = new TLatex();
 t->SetNDC(1);
 t->SetTextAlign(13);
 t->SetTextSize(0.05);
 t->SetTextColor(kBlack);



 sprintf(writetext4,"#font[72]{ATLAS} Internal");
 sprintf(writetext2,label.c_str());
 sprintf(writetext3,"#int L dt = 20.7 fb^{-1}");
 sprintf(writetext1,"\\sqrt{s} = 8 TeV");


  TLegend * leg_hist;
  TLegend * leg_integral;

  double leg_ymax = 0.92;

  if(opt == "signal" && Signal_Vec.size() > 0){
    leg_hist = new TLegend(0.66,0.5,0.89,0.92);
    t->DrawLatex(0.4,0.90,writetext4);
    t->DrawLatex(0.4,0.80,writetext3);
    t->DrawLatex(0.4,0.70,writetext1);
  }

  else if(high && log) {
    leg_hist = new TLegend(0.5,0.78,0.90,0.90);
    leg_hist->SetNColumns(2);
    t->DrawLatex(0.2,0.90,writetext4);
    t->DrawLatex(0.2,0.80,writetext3);
    t->DrawLatex(0.2,0.70,writetext1);
  }
  else if(high && !log) {
    leg_hist = new TLegend(0.72,0.80,0.89,0.92);
    t->DrawLatex(0.2,0.90,writetext4);
    t->DrawLatex(0.2,0.80,writetext3);
    t->DrawLatex(0.2,0.70,writetext1);
  }
  else if(opt == "tr"){
     leg_hist = new TLegend(0.60,leg_ymax-(m_currentHistVec.size()+2)*0.07,0.82,0.92);
     t->DrawLatex(0.2,0.91,writetext4);
     t->SetTextSize(0.04);     
     t->DrawLatex(0.2,0.84,writetext2);
     t->DrawLatex(0.2,0.76,writetext3);
     t->DrawLatex(0.2,0.68,writetext1);
     leg_integral = new TLegend(0.803,leg_ymax-(m_currentHistVec.size()+2)*0.07,0.87,0.92);
  }
  else{
  leg_hist = new TLegend(0.72,0.60,0.89,0.92);
  t->DrawLatex(0.4,0.90,writetext4);
  t->DrawLatex(0.4,0.80,writetext3);
  t->DrawLatex(0.4,0.70,writetext1);
  }


  leg_hist->SetTextSize(0.05);
  leg_hist->SetFillColor(0);
  leg_hist->SetShadowColor(0);
  leg_hist->SetBorderSize(0);
  leg_hist->SetLineColor(0);

  leg_integral->SetTextSize(0.03);
  leg_integral->SetFillColor(0);
  leg_integral->SetShadowColor(0);
  leg_integral->SetBorderSize(0);
  leg_integral->SetLineColor(0);


   
  double total_mc = 0; 
  double total_mc_error = 0;
  //int binlow = m_currentDataHist->FindBin(0);
  //int binhigh = m_currentDataHist->FindBin(300);
  double integralDataError;
  double integralData =  m_currentDataHist->IntegralAndError(0,m_currentDataHist->GetNbinsX()+1,integralDataError);
    
  integralDataError = sqrt(integralData);
  
  leg_hist->AddEntry(Data,m_dataname.c_str(),"P");
  leg_integral-> AddEntry("data_integral", Form("(%.0f #pm %.0f)",integralData,integralDataError));
  if(opt == "signal"){
     for (int i = size-1; i > -1; i--){
      cout<<"name: "<< m_datanameVec[i]<<endl;
      if (m_currentHistVec[i]){
	leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");
      }
    }
     for (int i = 0; i < Signal_Vec.size(); i++){
       leg_hist->AddEntry( Signal_Vec[i],m_datanameVec_signal[i].c_str(),"F");
    }  
  }
  else if(opt == "Dijets"){
  for (int i = 0; i < size; i++){
    if(m_datanameVec[i] == "QCD") iQCD = i;
  }
  for (int i = size-1; i > -1; i--){
    if(i == iQCD) continue;
    if (m_currentHistVec[i])
      leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");
  }
  leg_hist->AddEntry(m_currentHistVec[iQCD],m_datanameVec[iQCD].c_str(),"F");

 }
 else if(high && log){
   for (int i = size-1; i > 2; i--){ 
     if (m_currentHistVec[i-2])
       leg_hist->AddEntry(m_currentHistVec[i-2],m_datanameVec[i-2].c_str(),"F");
     if (m_currentHistVec[i])
       leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");     
    }
   if (m_currentHistVec[0])
     leg_hist->AddEntry(m_currentHistVec[0],m_datanameVec[0].c_str(),"F");     
 }
 else if((high && !log) ||  xtitle == "Track d0 [Ele from Z]" ){
   if (m_currentHistVec[size-1])
     leg_hist->AddEntry(m_currentHistVec[size-1],m_datanameVec[size-1].c_str(),"F");    
 
 }
 
  else{
    for (int i = size-1; i > -1; i--){
      //cout<<"name: "<< m_datanameVec[i]<<endl;
      if (m_currentHistVec[i]){
	m_datanameVec[i].insert(m_datanameVec[i].end(), 15 - m_datanameVec[i].size(), ' ');

	//leg_hist->AddEntry(m_currentHistVec[i], Form("%s #small{(%.0f)}",m_datanameVec[i].c_str(),m_currentHistVec[i]->Integral()) ,"F");
	leg_hist->AddEntry(m_currentHistVec[i], m_datanameVec[i].c_str() ,"F");
	
	double mc_integral_error;
	double mc_integral = m_currentHistVec[i]->IntegralAndError(0,m_currentHistVec[i]->GetNbinsX()+1, mc_integral_error);
        if (m_datanameVec[i] == "Z+jets         ") {
  	  for (int j =0; j<m_currentHistVec[i]->GetNbinsX()+1; ++j){
	     //cout << "Check Error: "<< m_currentHistVec[i]->GetBinError(j)<<endl;	   
          }
	} 
	cout << m_datanameVec[i]<<" integral: " << mc_integral << "+/-" << mc_integral_error << endl;
        total_mc += mc_integral;
        total_mc_error = sqrt(total_mc_error*total_mc_error + mc_integral_error*mc_integral_error); 
	
	//cout << "integral is " << mc_integral << endl;
	leg_integral-> AddEntry(Form("%s%s",m_datanameVec[i].c_str(),"_integral"), Form("(%.0f #pm %.0f)",mc_integral,mc_integral_error) );

      }
    }
  }
  
  //leg_hist->AddEntry("total_mc", Form("%s (%.0f)","Total MC",total_mc));
  leg_hist->AddEntry("total_mc","Total MC", "l");
  leg_integral->AddEntry("mc_integral", Form("(%.0f #pm %.0f)",total_mc,total_mc_error));
  //t->DrawLatex(0.8,0.60,Form("(%.0f)",total_mc));

  leg_integral->Draw("p same");
  leg_hist->Draw("p same");
  //leg_integral->Draw("p same");
  
  //draw ratio plot
  TH1* mc_stack_sum = (TH1*) (m_stack->GetStack()->Last()->Clone(Form("%s_mc_sum",m_stack->GetName()))); 
  mc_stack_sum->Rebin(2);

  //this is now done above
  //TH1* data_stack_sum =  (TH1*)Data->Clone(Form("%s_data_sum",m_stack->GetName()));
  data_stack_sum->Rebin(2);

  TH1* mc_stack_sum_denom = (TH1*)mc_stack_sum->Clone(Form("%s_denom",m_stack->GetName()));
  //zero out errors on one hist to get correct errors on ratio
  for (int i = 0; i < mc_stack_sum_denom->GetNbinsX(); i++) mc_stack_sum_denom->SetBinError(i, 0.);

  TH1* h_ratio = (TH1*)mc_stack_sum->Clone(Form("%s_ratio",m_stack->GetName()));
  
  //cout << "Now dividing" << endl;
  h_ratio->Divide(data_stack_sum,mc_stack_sum_denom);  
  mc_stack_sum->Divide(mc_stack_sum_denom);
  
  h_ratio->GetYaxis()->SetTitle("Data/MC");                
  h_ratio->GetYaxis()->SetTitleSize(0.08);                
  h_ratio->GetYaxis()->SetTitleOffset(0.6);                
  h_ratio->GetYaxis()->SetLabelSize(0.08);                
  h_ratio->GetYaxis()->SetNdivisions(505);                
  h_ratio->GetXaxis()->SetTitleSize(0.12);                
  h_ratio->GetXaxis()->SetTitleOffset(1.5);                
  h_ratio->GetXaxis()->SetLabelSize(0.12);                
  h_ratio->GetXaxis()->SetRangeUser(xmin,xmax-0.000001);
  h_ratio->SetTitle("");                
  h_ratio->SetMarkerStyle(Data->GetMarkerStyle());
  h_ratio->SetMaximum(2.0);
  h_ratio->SetMinimum(0.0);	 

  mc_stack_sum->SetMarkerStyle(0);
  mc_stack_sum->SetFillStyle(1001);
  mc_stack_sum->SetFillColor(kYellow - 7);
  mc_stack_sum->GetXaxis()->SetRangeUser(xmin,xmax-0.000001);
  mc_stack_sum->SetMaximum(2.0);
  mc_stack_sum->SetMinimum(0.0);	 

  pad0->cd(0);       

  TF1 *line = new TF1("line","1",h_ratio->GetXaxis()->GetXmin(), h_ratio->GetXaxis()->GetXmax());
  line->SetLineColor(kRed);
  line->SetLineStyle(7);

  h_ratio->Draw("E"); //for axis,range      
  mc_stack_sum->Draw("SAME E2");
  //mc_stack_sum->Draw("E2");
  line->Draw("SAME");
  h_ratio->Draw("SAME E");//so points lie on top of line       
  
  pad0->RedrawAxis();
  
  m_canvas->Print((hnameSave+".eps").c_str());
  m_canvas->Print((hnameSave+".png").c_str());

  m_outputfile->cd();
  if(log)  m_canvas->SetName((hname+"_log").c_str());
  else  m_canvas->SetName((hname).c_str());
  m_canvas->Write();

  //output some stats
  cout << "Yields for histogram: " << hname <<  std::endl;
  cout << "Integral of Data: " << integralData << " +/- " << sqrt(integralData) << std::endl;
  cout << "Sum of MC: " << total_mc << " +/- " << total_mc_error << std::endl;
  cout << "Data/MC: " <<  integralData/total_mc << " +/- " << integralData/total_mc*sqrt(1/integralData + (total_mc_error/total_mc)*(total_mc_error/total_mc)) << std::endl;

  return m_stack;
}


THStack * StackMgr::drawStackBranch(string tree_name, string branch_name, string cut, string tag, string plotTitle, string xtitle, string ytitle, string label, string opt, bool log,int xbins, double xmin, double xmax, double ymin, double ymax){

  bool drawData = true;
  bool drawRatio = false;
  double maximum = 1;

  int size = m_chainVec.size();
  m_canvas = newCanvas("NONE", drawRatio);
  m_canvas->cd(1);
  m_title = "";
  m_stack = new THStack((tag+"_stack").c_str(), "");

   //if signal fill vector, scale
  vector<TH1*> Signal_Vec;
  
   // loop over different datasets to stack
  for (int i = 0; i < m_chainVec.size(); i++){
    
    string hist_name = Form("h_mc%i_%s_%s_%s",i,tree_name.c_str(),tag.c_str(), tag.c_str());
    
    TH1F* hist = new TH1F(hist_name.c_str(),"",xbins, xmin, xmax);
    hist->Sumw2();
    m_chainVec[i]->Draw(Form("%s >> %s",branch_name.c_str(),hist_name.c_str()), Form("(%s)*weight",cut.c_str()), "goff");
            
    hist->Scale(m_scaleFacVec[i]);
    hist->SetFillColor(m_colorVec[i]);
    hist->SetLineColor(1);
    hist->GetXaxis()->SetTitle(xtitle.c_str());
    hist->GetYaxis()->SetTitle(ytitle.c_str());
    //hist->GetXaxis()->SetTitleOffset(1.8);
    //hist->GetYaxis()->SetMaxDigits(2);
    TGaxis::SetMaxDigits(4);
    
    m_currentHistVec.push_back(hist);
  }

  cout<<" m_currentHistVec.size: "<< m_currentHistVec.size()<<endl;

  TH1* data_stack_sum =  new TH1();

  if(m_datachain == 0) {
      cout<<"Data chain cannot be found"<<endl;
      return 0;
  }

  string hist_name = Form("h_data_%s_%s_%s",tree_name.c_str(),tag.c_str(), tag.c_str());
  
  m_currentDataHist = new TH1F(hist_name.c_str(),"",xbins, xmin, xmax);
  m_currentDataHist->Sumw2();
  m_currentDataHist->SetTitle(("; "+ xtitle + "; " + ytitle) .c_str());
  m_currentDataHist->GetYaxis()->SetTitleOffset(1.2);
  m_currentDataHist->GetXaxis()->SetTitle(xtitle.c_str());
  m_currentDataHist->GetYaxis()->SetTitle(ytitle.c_str());
      
  m_datachain->Draw(Form("%s >> %s",branch_name.c_str(), hist_name.c_str()), cut.c_str(), "goff");

  //clone hist for ratio plot here before errors are zeroed (=>not entirely correct error treatment in ratio)
  data_stack_sum = (TH1*)m_currentDataHist->Clone(Form("%s_data_sum",m_stack->GetName()));

  //make graph for data with asymmetric errors
  TGraphAsymmErrors *Data = new TGraphAsymmErrors();
  Data->SetMarkerStyle(20);
  Data->SetLineWidth(2.);
  Data->GetXaxis()->SetTitle(xtitle.c_str());
  Data->GetYaxis()->SetTitle(ytitle.c_str());
  
  //set errors on data hist
  double value = 0;
  double error_poisson_up   = 0;
  double error_poisson_down = 0;
  double y1 = 0;
  double y2 = 0;
  double d1 = 0;
  double d2 = 0;
  for(int i=1; i<=m_currentDataHist->GetNbinsX(); i++){
    m_currentDataHist->SetBinError(i,0);

    value = m_currentDataHist->GetBinContent(i);
    if(value!=0) { 
      y1 = value + 1.0;
      d1 = 1.0 - 1.0/(9.0*y1) + 1.0/(3*TMath::Sqrt(y1));
      error_poisson_up = y1*d1*d1*d1 - value;
      y2 = value;
      d2 = 1.0 - 1.0/(9.0*y2) - 1.0/(3.0*TMath::Sqrt(y2));
      error_poisson_down = value - y2*d2*d2*d2;
      Data->SetPoint(i-1, m_currentDataHist->GetBinCenter(i), value);
      Data->SetPointError(i-1, 0, 0, error_poisson_down, error_poisson_up);
    } else {
      Data->SetPoint(i-1, -999, value);
    }
  }

  cout << "making stack" <<endl;
  for (int i = 0; i < size; i++){
    m_stack->Add(m_currentHistVec[i]);
  }

  cout << "setting plot range" <<endl;
  maximum = m_currentDataHist->GetMaximum();

  if(log){
     m_currentDataHist->SetMinimum(0.02);
     if(ymin != 999)   m_currentDataHist->SetMinimum(ymin);
     m_currentDataHist->SetMaximum(maximum*500);

     m_stack->SetMinimum(0.02);
     if(ymin != 999)   m_stack->SetMinimum(ymin);
     m_stack->SetMaximum(maximum*500);

  } else {    
     if(ymin != 999) m_currentDataHist->SetMinimum(ymin);
     else  m_currentDataHist->SetMinimum(0.001);
     if(ymax != 999) m_currentDataHist->SetMaximum(ymax);
     else  m_currentDataHist->SetMaximum(maximum*2);
     if(ymin != 999) m_stack->SetMinimum(ymin);
     else  m_stack->SetMinimum(0.001);
     if(ymax != 999) m_stack->SetMaximum(ymax);
     else  m_stack->SetMaximum(maximum*2);

  }
  
  if(xmin !=999) m_currentDataHist->GetXaxis()->SetRangeUser(xmin,xmax-0.000001);

  TPad* pad0;
  if (drawRatio){
     pad0 = new TPad("pad", "pad", 0., 0., 1.,0.30);
     pad0->SetTopMargin(0.03);
     pad0->SetBottomMargin(0.4);
     pad0->SetFillColor(0);
     //pad->SetFillStyle(0);
     pad0->Draw();
  }
  
  TPad* pad1 = new TPad("pad1", "pad", 0., (drawRatio? 0.3:0.), 1.,1.);
  if (drawRatio) pad1->SetBottomMargin(0);
  pad1->SetLogy(log);
  if(opt == "logX") pad1->SetLogx();
  pad1->Draw();  
  pad1->cd(0);
  
  //errors on MC
  TH1* mc_stack_sum = (TH1*) (m_stack->GetStack()->Last()->Clone(Form("%s_mc_sum",m_stack->GetName()))); 
  mc_stack_sum->SetFillColor(1);
  mc_stack_sum->SetMarkerStyle(0);
  mc_stack_sum->SetFillStyle(3345);
  
  if (drawData) {
     m_currentDataHist->Draw("*");
     m_stack->Draw("histsame");
     mc_stack_sum->Draw("E2 SAME");
     m_currentDataHist->Draw("axissame");
     Data->Draw("psame");
  } else {  

     m_stack->Draw("hist");  
     mc_stack_sum->Draw("E2 SAME");

     m_stack->SetTitle(("; "+ xtitle + "; " + ytitle) .c_str());
     m_stack->GetYaxis()->SetTitleOffset(1.2);
     m_stack->GetXaxis()->SetTitle(xtitle.c_str());
     m_stack->GetYaxis()->SetTitle(ytitle.c_str());
     
     if(xmin !=999) m_stack->GetXaxis()->SetRangeUser(xmin,xmax-0.000001);

     m_stack->Draw("hist");  
  }
  
  if(opt == "signal"){
    for(int i = 0; i < Signal_Vec.size(); i++){
      Signal_Vec[i]->Draw("histsame");
    }
  }

 char writetext1[100];
 char writetext2[100];
 char writetext3[100];
 char writetext4[100];
 TLatex *t = new TLatex();
 t->SetNDC(1);
 t->SetTextAlign(13);
 t->SetTextSize(0.05);
 t->SetTextColor(kBlack);

 sprintf(writetext4,"#font[72]{ATLAS} Internal");
 sprintf(writetext2,label.c_str());
 sprintf(writetext3,"\\sqrt{s} = 8 TeV #int L dt = 20.7 fb^{-1}");
 //sprintf(writetext1,"");
 //sprintf(writetext1,"\\sqrt{s} = 7 TeV #int L dt = 4.6 fb^{-1}");


  TLegend * leg_hist;
  TLegend * leg_integral;

  double leg_ymax = 0.92;

  if(opt == "signal" && Signal_Vec.size() > 0){
    leg_hist = new TLegend(0.66,0.5,0.89,0.92);
    t->DrawLatex(0.4,0.90,writetext4);
    t->DrawLatex(0.4,0.80,writetext3);
    t->DrawLatex(0.4,0.70,writetext1);
  }

  else if(opt == "tr"){
     leg_hist = new TLegend(0.60,leg_ymax-(m_currentHistVec.size()+2)*0.07,0.82,0.92);
     t->DrawLatex(0.2,0.91,writetext4);
     t->SetTextSize(0.04);     
     t->DrawLatex(0.2,0.84,writetext2);
     t->DrawLatex(0.2,0.76,writetext3);
     t->DrawLatex(0.2,0.68,writetext1);
     leg_integral = new TLegend(0.803,leg_ymax-(m_currentHistVec.size()+2)*0.07,0.87,0.92);
  }
  else{
  leg_hist = new TLegend(0.72,0.60,0.89,0.92);
  t->DrawLatex(0.4,0.90,writetext4);
  t->DrawLatex(0.4,0.80,writetext3);
  t->DrawLatex(0.4,0.70,writetext1);
  }


  leg_hist->SetTextSize(0.05);
  leg_hist->SetFillColor(0);
  leg_hist->SetShadowColor(0);
  leg_hist->SetBorderSize(0);
  leg_hist->SetLineColor(0);
  leg_hist->SetFillStyle(0);
 
  leg_integral->SetTextSize(0.03);
  leg_integral->SetFillColor(0);
  leg_integral->SetShadowColor(0);
  leg_integral->SetBorderSize(0);
  leg_integral->SetLineColor(0);
  leg_integral->SetFillStyle(0);

   
  double total_mc = 0; 
  double total_mc_error = 0;
  double integralDataError;
  double integralData =  m_currentDataHist->IntegralAndError(0,m_currentDataHist->GetNbinsX()+1,integralDataError);
    
  integralDataError = sqrt(integralData);
  if (drawData) {
    leg_hist->AddEntry(Data,m_dataname.c_str(),"P");
    leg_integral->AddEntry("data_integral", Form("(%.0f #pm %.0f)",integralData,integralDataError), "");
  }
  if(opt == "signal"){
     for (int i = size-1; i > -1; i--){
      cout<<"name: "<< m_datanameVec[i]<<endl;
      if (m_currentHistVec[i]){
	leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");
      }
    }
     for (int i = 0; i < Signal_Vec.size(); i++){
       leg_hist->AddEntry( Signal_Vec[i],m_datanameVec_signal[i].c_str(),"F");
    }  
  } else {
    for (int i = size-1; i > -1; i--){
      if (m_currentHistVec[i]){
	m_datanameVec[i].insert(m_datanameVec[i].end(), 15 - m_datanameVec[i].size(), ' ');

	leg_hist->AddEntry(m_currentHistVec[i], m_datanameVec[i].c_str() ,"F");
	
	double mc_integral_error;
	double mc_integral = m_currentHistVec[i]->IntegralAndError(0,m_currentHistVec[i]->GetNbinsX()+1, mc_integral_error);
        if (m_datanameVec[i] == "Z+jets         ") {
  	  for (int j =0; j<m_currentHistVec[i]->GetNbinsX()+1; ++j){
	     //cout << "Check Error: "<< m_currentHistVec[i]->GetBinError(j)<<endl;	   
          }
	} 
	cout << m_datanameVec[i]<<" integral: " << mc_integral << "+/-" << mc_integral_error << endl;
        total_mc += mc_integral;
        total_mc_error = sqrt(total_mc_error*total_mc_error + mc_integral_error*mc_integral_error); 
	
	leg_integral-> AddEntry(Form("%s%s",m_datanameVec[i].c_str(),"_integral"), Form("(%.1f #pm %.1f)",mc_integral,mc_integral_error), "" );

      }
    }
  }
  
  //leg_hist->AddEntry("total_mc", Form("%s (%.0f)","Total MC",total_mc));
  leg_hist->AddEntry("total_mc","Total MC", "l");
  leg_integral->AddEntry("mc_integral", Form("(%.0f #pm %.0f)",total_mc,total_mc_error), "");
  //t->DrawLatex(0.8,0.60,Form("(%.0f)",total_mc));

  leg_integral->Draw("p same");
  leg_hist->Draw("p same");
  //leg_integral->Draw("p same");
  

  //draw ratio plot
  if (drawRatio){
    TH1* mc_stack_sum_denom = (TH1*)mc_stack_sum->Clone(Form("%s_denom",m_stack->GetName()));
    //zero out errors on one hist to get correct errors on ratio
    for (int i = 1; i < mc_stack_sum_denom->GetNbinsX(); i++) {
      mc_stack_sum_denom->SetBinError(i, 0.);
  /*    
      double value = 0;
      double err_up = 0;
      double err_down = 0;    
      double x_val = 0;
      double y_val = 0;

      h_ratio->GetPoint(i-1, x_val, y_val);

      if (x_val == -999) continue;

      if (mc_stack_sum_denom->GetBinContent(i) != 0){
	value = y_val / mc_stack_sum_denom->GetBinContent(i); 
	err_up  = h_ratio->GetErrorYhigh(i) / mc_stack_sum_denom->GetBinContent(i); 
	err_down = h_ratio->GetErrorYlow(i) / mc_stack_sum_denom->GetBinContent(i); 
      }    
      cout << i << " "<< x_val <<" "<< y_val <<" "<<mc_stack_sum_denom->GetBinContent(i)<<" "<< value<<" " << err_up <<" "<< err_down << endl;

      h_ratio->SetPoint(i-1, x_val, value);
      h_ratio->SetPointError(i-1, 0, 0, err_down, err_up);
  */    
    }
    TH1* h_ratio = (TH1*)mc_stack_sum->Clone(Form("%s_ratio",m_stack->GetName()));

    //cout << "Now dividing" << endl;
    h_ratio->Divide(data_stack_sum,mc_stack_sum_denom);  
    mc_stack_sum->Divide(mc_stack_sum_denom);

    h_ratio->GetYaxis()->SetTitle("Data/MC");                
    h_ratio->GetYaxis()->SetTitleSize(0.08);                
    h_ratio->GetYaxis()->SetTitleOffset(0.6);                
    h_ratio->GetYaxis()->SetLabelSize(0.08);                
    h_ratio->GetYaxis()->SetNdivisions(505);                
    h_ratio->GetXaxis()->SetTitleSize(0.12);                
    h_ratio->GetXaxis()->SetTitleOffset(1.5);                
    h_ratio->GetXaxis()->SetLabelSize(0.12);                
    h_ratio->GetXaxis()->SetRangeUser(xmin,xmax-0.000001);
    h_ratio->SetTitle("");                
    h_ratio->SetMarkerStyle(Data->GetMarkerStyle());
    h_ratio->SetMaximum(2.0);
    h_ratio->SetMinimum(0.0);	 

    mc_stack_sum->SetMarkerStyle(0);
    mc_stack_sum->SetFillStyle(1001);
    mc_stack_sum->SetFillColor(kYellow - 7);
    mc_stack_sum->GetXaxis()->SetRangeUser(xmin,xmax-0.000001);
    mc_stack_sum->SetMaximum(2.0);
    mc_stack_sum->SetMinimum(0.0);	 

    TF1 *line = new TF1("line","1",h_ratio->GetXaxis()->GetXmin(), h_ratio->GetXaxis()->GetXmax());
    line->SetLineColor(kRed);
    line->SetLineStyle(7);

    pad0->cd(0);       
    h_ratio->Draw("p axis"); //for axis,range      
    mc_stack_sum->Draw("SAME E2");
    //mc_stack_sum->Draw("E2");
    line->Draw("SAME");
    h_ratio->Draw("SAME p");//so points lie on top of line       

    pad0->RedrawAxis();
  }  
    
  string canvas_name = tree_name+"_"+tag;
  if (log) canvas_name += "_log";
  m_canvas->SetName(canvas_name.c_str());
  
  m_outputfile->cd();
  m_canvas->Write();

  //output some stats
  cout << "Yields for histogram: " << branch_name <<  std::endl;
  cout << "Integral of Data: " << integralData << " +/- " << sqrt(integralData) << std::endl;
  cout << "Sum of MC: " << total_mc << " +/- " << total_mc_error << std::endl;
  cout << "Data/MC: " <<  integralData/total_mc << " +/- " << integralData/total_mc*sqrt(1/integralData + (total_mc_error/total_mc)*(total_mc_error/total_mc)) << std::endl;

  return m_stack;
}

THStack * StackMgr::drawStack(string hname, string hnameData,string hnameAntiData,string hnameSave, string plotTitle, string xtitle, string ytitle, string opt, bool log,int RebinFac, double xmin, double xmax){

  
  double maximum = 1;

  int size = m_fileVec.size();
  m_canvas = newCanvas();
  m_title = plotTitle;
  m_stack = new THStack((hname+"_stack").c_str(), (plotTitle+";;").c_str());
 
  
 
   // loop over different datasets to stack
  for (int i = 0; i < size; i++){

    TH1* hist = 0;
    //TH1* hist2 = 0;
       
    if(m_datanameVec[i] == "QCD" )  {
      hist = (TH1F*)((TDirectory*) m_fileVec[i]->Get(hnameAntiData.c_str()))->Clone("hist");

    }
    
    else  hist = (TH1F*)((TDirectory*) m_fileVec[i]->Get(hname.c_str()))->Clone("hist");
    

    
    if (hist == 0){
      cout << "Simu file" << endl;
      cout << "Error, hist not found: " << hname << " " << m_filenameVec[i] << endl;
      TH1F * temphist =  (TH1F*)((TDirectory*) m_datafile->Get(hname.c_str()));
      //make an empty histogram with the right range
      hist = new TH1F((hname+"_dummy").c_str(),hname.c_str(),temphist->GetNbinsX(),
		      temphist->GetXaxis()->GetXmin(), temphist->GetXaxis()->GetXmax());
    }
    
    
       
    hist->Scale(m_scaleFacVec[i]);
    hist->Rebin(RebinFac);
    // cout<<"m_scaleFacVec[i]: "<<m_scaleFacVec[i]<<endl;
    hist->SetFillColor(m_colorVec[i]);
    hist->SetLineColor(1);
    hist->GetXaxis()->SetTitle(xtitle.c_str());
    hist->GetYaxis()->SetTitle(ytitle.c_str());

    m_currentHistVec.push_back(hist);
  }

  

  if (m_datafile != 0){
    m_currentDataHist = 0;
    m_currentDataHist = (TH1F*)((TDirectory*) m_datafile->Get(hnameData.c_str()))->Clone("hist");
    if (m_currentDataHist == 0){ 
      cout << "For Data file:" << endl;
      cout << "Error, hist not found: " << hnameData << endl;
      
    } else {
      // data_entries = m_currentDataHist->GetEntries();
      m_currentDataHist->Sumw2();
      m_currentDataHist->Rebin(RebinFac);
      m_currentDataHist->SetMarkerStyle(20);
      m_currentDataHist->SetMarkerSize(0.9);

    m_currentDataHist->SetTitle(("; "+ xtitle + "; " + ytitle) .c_str());
    m_currentDataHist->GetXaxis()->SetTitle(xtitle.c_str());
    m_currentDataHist->GetYaxis()->SetTitle(ytitle.c_str());
    m_currentDataHist->GetXaxis()->SetTitleOffset(1.2);
    maximum = m_currentDataHist->GetMaximum();
    }
  }    

  int iQCD = 0;
  if(opt == "Dijets"){
    for (int i = 0; i < size; i++){
      if(m_datanameVec[i] == "QCD") iQCD = i;
    }
    m_stack->Add(m_currentHistVec[iQCD]);
     for (int i = 0; i < size; i++){
       if(i == iQCD) continue;
       m_stack->Add(m_currentHistVec[i]);
     }

  }
  else{
    for (int i = 0; i < size; i++){
      m_stack->Add(m_currentHistVec[i]);
    }
  }
  
  bool high = 0;
  if(xtitle == "cos(#theta^{*})" || opt == "high") high = 1;
    
  if (log) {  gPad->SetLogy(); //hist->GetYaxis()->SetRangeUser(1,1000000);
  }
  
  if(opt == "logX") gPad->SetLogx();

  if(log){
     m_currentDataHist->SetMinimum(0.001);
     m_currentDataHist->SetMaximum(maximum*10);

     if(high)  m_currentDataHist->SetMaximum(maximum*100);
  } else {
    //m_currentDataHist->SetMaximum(maximum*1.8);
    if(high)  m_currentDataHist->SetMaximum(maximum+maximum);	 
  }
  
  if(xmin !=999) m_currentDataHist->GetXaxis()->SetRangeUser(xmin,xmax);

   m_currentDataHist->Draw("e");
  m_stack->Draw("histsame");
  m_currentDataHist->Draw("axissame");
  m_currentDataHist->Draw("esame"); char writetext1[100];
 char writetext2[100];
 char writetext3[100];
 char writetext4[100];
 TLatex *t = new TLatex();
 t->SetNDC(1);
 t->SetTextAlign(13);
 t->SetTextSize(0.05);
 t->SetTextColor(kBlack);
 sprintf(writetext1,"#font[72]{ATLAS} Internal");
 sprintf(writetext2,"");
 sprintf(writetext3,"\\sqrt{s} = 7 TeV");
 sprintf(writetext4,"93 pb^{-1}");
 t->DrawLatex(0.400,0.90,writetext1);
 t->DrawLatex(0.440,0.85,writetext2);
 t->DrawLatex(0.440,0.80,writetext3);
 t->DrawLatex(0.440,0.75,writetext4);






  TLegend * leg_hist;
  if(high) {
    leg_hist = new TLegend(0.5,0.78,0.90,0.90);
    leg_hist->SetNColumns(2);
  }
  else{
  leg_hist = new TLegend(0.73,0.60,0.90,0.90);
  }

  leg_hist->SetTextSize(0.04);
  leg_hist->SetFillColor(0);
 
 
  leg_hist->AddEntry(m_currentDataHist,"Data 2011","P");
 
if(opt == "Dijets"){
  for (int i = 0; i < size; i++){
    if(m_datanameVec[i] == "QCD") iQCD = i;
  }
  for (int i = size-1; i > -1; i--){
    if(i == iQCD) continue;
    if (m_currentHistVec[i])
      leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");
  }
  leg_hist->AddEntry(m_currentHistVec[iQCD],m_datanameVec[iQCD].c_str(),"F");

 }
 else if(high){
    for (int i = size-1; i > 2; i--){ 
       if (m_currentHistVec[i-2])
	leg_hist->AddEntry(m_currentHistVec[i-2],m_datanameVec[i-2].c_str(),"F");
       if (m_currentHistVec[i])
	leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");     
    }
   if (m_currentHistVec[0])
	leg_hist->AddEntry(m_currentHistVec[0],m_datanameVec[0].c_str(),"F");     
 }
  else{
    for (int i = size-1; i > -1; i--){
      cout<<"name: "<< m_datanameVec[i]<<endl;
      if (m_currentHistVec[i]){
	leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");
      }
    }
  }
 leg_hist->Draw("p same");
  m_canvas->Print((hnameSave+".eps").c_str());

  m_outputfile->cd();
  m_canvas->SetName(hnameSave.c_str());
  m_canvas->Write();

  return m_stack;
}

THStack * StackMgr::drawStackSimple(string hname, string hnameData, string hnameSave, string plotTitle, string xtitle, string ytitle, string opt, bool log,int RebinFac, double xmin, double xmax, bool normalize){

  double integralData = 0;  
  double integralMC = 0;  

  double maximum = 1;

  int size = m_fileVec.size();
  m_canvas = newCanvas();
  m_title = plotTitle;
  m_stack = new THStack((hname+"_stack").c_str(), (plotTitle+";;").c_str());

  

   if (m_datafile != 0){
    m_currentDataHist = 0;
    m_currentDataHist = (TH1F*)((TDirectory*) m_datafile->Get(hnameData.c_str()))->Clone("hist");
    if (m_currentDataHist == 0){ 
      cout << "For Data file:" << endl;
      cout << "Error, hist not found: " << hnameData << endl;
      
    } else {

      maximum = m_currentDataHist->GetMaximum();  
      // data_entries = m_currentDataHist->GetEntries();
      m_currentDataHist->Sumw2();
      m_currentDataHist->Rebin(RebinFac);
      m_currentDataHist->SetMarkerStyle(20);
      m_currentDataHist->SetMarkerSize(0.9);
      m_currentDataHist->SetTitle(("; "+ xtitle + "; " + ytitle) .c_str());
    m_currentDataHist->GetXaxis()->SetTitle(xtitle.c_str());
    m_currentDataHist->GetYaxis()->SetTitle(ytitle.c_str());
    m_currentDataHist->GetXaxis()->SetTitleOffset(1.2);
    maximum = m_currentDataHist->GetMaximum();  
    cout<<"maximum: "<<maximum<<endl;
    integralData = m_currentDataHist->Integral();
    }
  }    

   
   // loop over different MC sets to stack
  for (int i = 0; i < size; i++){
    TH1* hist = 0;
    hist = (TH1F*)((TDirectory*) m_fileVec[i]->Get(hname.c_str()))->Clone("hist");
    if (hist == 0){
      cout << "Simu file" << endl;
      cout << "Error, hist not found: " << hname << " " << m_filenameVec[i] << endl;
      TH1F * temphist =  (TH1F*)((TDirectory*) m_datafile->Get(hname.c_str()));
      //make an empty histogram with the right range
      hist = new TH1F((hname+"_dummy").c_str(),hname.c_str(),temphist->GetNbinsX(),
		      temphist->GetXaxis()->GetXmin(), temphist->GetXaxis()->GetXmax());
    }
    
    
    hist->Scale(m_scaleFacVec[i]);
    hist->Rebin(RebinFac);
    // cout<<"m_scaleFacVec[i]: "<<m_scaleFacVec[i]<<endl;

    integralMC += hist->Integral();
    hist->SetFillColor(m_colorVec[i]);
    hist->SetLineColor(1);
    hist->GetXaxis()->SetTitle(xtitle.c_str());
    hist->GetYaxis()->SetTitle(ytitle.c_str());

    m_currentHistVec.push_back(hist);
  }

  if(normalize){
    for(int iMC = 0; iMC < m_currentHistVec.size(); iMC++){
      m_currentHistVec[iMC]->Scale((double)integralData/(double)integralMC);
    }
  }


 
  int iQCD = 0;
  if(opt == "Dijets"){
    for (int i = 0; i < size; i++){
      if(m_datanameVec[i] == "QCD") iQCD = i;
    }
    m_stack->Add(m_currentHistVec[iQCD]);
     for (int i = 0; i < size; i++){
       if(i == iQCD) continue;
       m_stack->Add(m_currentHistVec[i]);
     }

  }
  else{
    for (int i = 0; i < size; i++){
      m_stack->Add(m_currentHistVec[i]);
    }
  }
  
  bool high = 0;
  if(xtitle == "cos(#theta^{*})" || opt == "high") high = 1;
    
  if (log) {  gPad->SetLogy(); //hist->GetYaxis()->SetRangeUser(1,1000000);
  }
  
  if(log){
    //  m_currentDataHist->SetMinimum(0.001);
//      m_currentDataHist->SetMaximum(maximum*10);

    m_currentDataHist->GetYaxis()->SetRangeUser(0.001,maximum*10);

     if(high)  m_currentDataHist->SetMaximum(maximum*100);
  } else {
    m_currentDataHist->SetMaximum(maximum*1.2);
    if(high)  m_currentDataHist->SetMaximum(maximum+maximum);	 
  }
  
  if(xmin !=999) m_currentDataHist->GetXaxis()->SetRangeUser(xmin,xmax);

  m_currentDataHist->Draw("e");
  m_stack->Draw("histsame");
  m_currentDataHist->Draw("axissame");
  m_currentDataHist->Draw("esame");






  TLegend * leg_hist;
  if(high) {
    leg_hist = new TLegend(0.5,0.78,0.90,0.90);
    leg_hist->SetNColumns(2);
  }
  else{
  leg_hist = new TLegend(0.73,0.60,0.90,0.90);
  }
  leg_hist->SetTextSize(0.04);
  leg_hist->SetFillColor(0);
 
 
  leg_hist->AddEntry(m_currentDataHist,"Data 2011","P");
 
if(opt == "Dijets"){
  for (int i = 0; i < size; i++){
    if(m_datanameVec[i] == "QCD") iQCD = i;
  }
  for (int i = size-1; i > -1; i--){
    if(i == iQCD) continue;
    if (m_currentHistVec[i])
      leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");
  }
  leg_hist->AddEntry(m_currentHistVec[iQCD],m_datanameVec[iQCD].c_str(),"F");

 }
 else if(high){
    for (int i = size-1; i > 2; i--){ 
       if (m_currentHistVec[i-2])
	leg_hist->AddEntry(m_currentHistVec[i-2],m_datanameVec[i-2].c_str(),"F");
       if (m_currentHistVec[i])
	leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");     
    }
   if (m_currentHistVec[0])
	leg_hist->AddEntry(m_currentHistVec[0],m_datanameVec[0].c_str(),"F");     
 }
  else{
    for (int i = size-1; i > -1; i--){
      if (m_currentHistVec[i])
	leg_hist->AddEntry(m_currentHistVec[i],m_datanameVec[i].c_str(),"F");
    }
  }
  leg_hist->Draw("p same");
  m_canvas->Print((hnameSave+".eps").c_str());

  return m_stack;
}



TCanvas * StackMgr::newCanvas(string canvasTitle, bool drawRatio){
  if (m_debug) cout << "Now in newCanvas()" << endl;
  m_nCanvas++;
  m_currentHistVec.clear(); //new canvas, so we assume we are done messing with the old histos
  if (canvasTitle=="NONE"){
    stringstream title;
    title << "Canvas " << m_nCanvas;
    canvasTitle=title.str();
  }

  m_canvas = new TCanvas(canvasTitle.c_str(),canvasTitle.c_str(),10,10,800,(drawRatio?800:600)); 

  
return m_canvas;
}





TH1* StackMgr::StackSum(THStack* stack)
{
  //cout<<"doing sum  "<<endl;         
  TList * mylist = (TList*)stack->GetHists();
  TIter next(mylist);
  TH1 *hh  = (TH1*) mylist -> First() ->Clone();
  hh -> SetLineColor(kBlack);
  hh -> SetFillStyle(0);
  TObject *obj;
  while ((obj = next()))
    {
      // cout<<obj->GetName()<<endl;
     //skip first object since it's used by creating the histogram                               
      if(obj == mylist->First()) continue;
      hh -> Add((TH1*)obj);
    }
  //cout<<"end of sum"<<endl;                                                                
  return hh;
}








#endif
