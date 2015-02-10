#ifndef PLOTMRG_HH
#define PLOTMRG_HH

// STD includes
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>


#include "TH1.h"
#include "TH2.h"
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
#include "TF1.h"
#include "TColor.h"
#include "TTree.h"
#include "TChain.h"

using namespace std;


class PlotMgr {

protected:
  
  string m_output_dir;
  string m_output_tag;
  string m_plot_type;
  
  vector<string> HistoNameVec;
  vector<string> HistoFileNameVec;
  vector<string> HistoLegNameVec;  
  vector<double> HistoSFVec;
  vector<int>    HistoColorVec;
  vector<int>    HistoStyleVec;
  
  vector<string> TreeNameVec;
  vector<string> TreeFileNameVec;
  vector<string> TreeLegNameVec;  
  vector<string> TreeWeightVec;
  vector<double> TreeSFVec;
  vector<int>    TreeColorVec;
  vector<int>    TreeStyleVec; 
  
public:
  PlotMgr(string output_dir, string output_tag,string m_plot_type); 
  ~PlotMgr();

  void AddHisto(string filename, string histname, string legname, double SF=1.,int color=-999, int style=-999);
  void AddMiniTree(string filename, string treename, string legname, string weight="weight", double SF=1.,int color=-999, int style=-999);

  void plot(string var_name, string savename,string ytitle="",string xtitle="",int norm = 0, int rebin=1, double xmin=-999, double xmax=-999,double ymin=-999, double ymax=-999,string legopt = "",bool log = 0,bool logx=0,double norm1=-999,double norm2=-999,string drawopt = "HIST");

  //void plot2D(string savename,string ytitle="",string xtitle="",int norm = 0, int rebin=1, double xmin=-999, double xmax=-999,double ymin=-999, double ymax=-999,string legopt = "",bool log = 0,bool logz=0,double norm1=-999,double norm2=-999,string drawopt = "",double zmin=-999);

  void addAtlasLabel(string legopt);

  void ClearVec();
  void set_plot_style();
  

private:

  TLegend* newLegend(string opt);
  TCanvas* newCanvas(string title="Canvas",bool logx=false, bool logy=false);
  
  void normalizeHistogram(TH1* hist, double hist_scale, int norm, double norm1, double norm2 );
 
   TChain* GetChain(string treename, string filename);

  static const int ColorArr[16];
  static const int StyleArr[17]; 
  static const int MarkerArr[9];

};


using namespace std;

const int PlotMgr::ColorArr[16] = {1,kBlue+1,kAzure+1,kGreen+1,kCyan+1,1,kOrange+2,33,kCyan,2,kBlue,kGreen+2,kMagenta+2,kOrange+2,33,kCyan};
  //ColorArr[] = {1,2,kBlue,kGreen+2,kGreen+2,kBlue,2,1};
  //ColorArr[] = {1,2,kBlue,kGreen+2,kMagenta+2,kOrange+2,33,kCyan,2,kBlue,kGreen+2,kMagenta+2,kOrange+2,33,kCyan};
  //ColorArr[] = {2,kMagenta+2,kCyan+2,kBlue,1,kOrange+2,33,kCyan,2,kBlue,kGreen+2,kMagenta+2,kOrange+2,33,kCyan};
  //ColorArr[] = {1,kBlue+1,kAzure+1,1,kBlue+1,kAzure+1,kRed};

const int PlotMgr::StyleArr[17] = {1,1,1,2,2,2,1,1,2,2,2,2,2,2,2,2,2};
  //StyleArr[] = {1,2,1,2,2,1,1,1,2,2,2,2,2,2,2,2,2};

const int PlotMgr::MarkerArr[9] = {22,23,24,25,22,23,24,25,26};


PlotMgr::PlotMgr(string output_dir, string output_tag, string plot_type): 
m_output_dir(output_dir),
m_output_tag(output_tag),
m_plot_type(plot_type)
{

}

PlotMgr::~PlotMgr(){}


void PlotMgr::plot(string var_name, string savename,string ytitle,string xtitle,int norm,int rebin,double xmin, double xmax,double ymin, double ymax,string legopt,bool log,bool logx,double norm1,double norm2,string drawopt){

  TLegend * leg = newLegend(legopt);

  TCanvas *c1 = newCanvas("canvas",logx, log);

  vector<TH1F*> vecHist;
  vector<string> vecNames;
  int counter = 0;
  double  hist_max = -1;
  double hist_min = -1;
  //First retrieve Histograms
  for(unsigned int i = 0; i < HistoNameVec.size(); i++){

    TFile * m_rootfile = new TFile((HistoFileNameVec[i]).c_str(),"READ");
    if (m_rootfile == 0 ){
      cout << "ERROR: file not found! " << HistoFileNameVec[i] << endl;
      return;
    }  

    TH1F * hist = (TH1F*) (m_rootfile->Get(HistoNameVec[i].c_str()));
    if(hist == 0) {
	cout<<"hist "<<HistoNameVec[i]<<" cannot be found"<<endl;
	return;
    }
    
    hist->SetName("test");
    
    normalizeHistogram(hist, HistoSFVec[i], norm, norm1, norm2 );    

    if(rebin !=1) hist->Rebin(rebin);

    hist->SetLineWidth(2);
    hist->SetLineColor(HistoColorVec[i] == -999 ? ColorArr[counter]: HistoColorVec[i]);
    hist->SetLineStyle(HistoStyleVec[i] == -999 ? StyleArr[counter]: HistoStyleVec[i]);
    
    if(drawopt!= "HIST" && drawopt!= "hist" ){
      hist->SetMarkerColor(HistoColorVec[i] == -999 ? ColorArr[counter]: HistoColorVec[i]);

      HistoStyleVec[i] == -999 ? hist->SetLineStyle(StyleArr[counter]): hist->SetMarkerStyle(HistoStyleVec[i]);
      hist->SetLineStyle(1);
    }

    if(drawopt == "HIST" || drawopt == "hist") leg->AddEntry(hist,HistoLegNameVec[i].c_str(),"L");
    else leg->AddEntry(hist,HistoLegNameVec[i].c_str());
    
    if ( hist_max == -1 || hist->GetMaximum() > hist_max) hist_max = hist->GetMaximum();
    if ( hist_min == -1 || hist->GetMinimum() < hist_min) hist_min = hist->GetMinimum();
        
    vecHist.push_back(hist);    
    counter++;  
  }
  
  int nbins = 0;
  
  //get binning from Histos for Tree Histos
  if (vecHist.size() > 0){
    nbins = vecHist[0]->GetNbinsX();
  } else {
    nbins = rebin;
  }
 
  //Second retrieve Trees
  for(unsigned int i = 0; i < TreeNameVec.size(); i++){
        
    TChain * chain = GetChain(TreeNameVec[i],TreeFileNameVec[i]);
    
    if(!chain || chain->GetEntries() == 0) {
	cout<<"Tree "<<TreeNameVec[i]<<" cannot be found in file:"<<endl;
	cout<<TreeFileNameVec[i].c_str()<<endl;
	return;
    }

    string hist_name = Form("h_%i_%s",i,savename.c_str());
    //cout << " Making hist("<<nbins << ","<<xmin<<","<<xmax<<")"<<endl;
    TH1F * hist = new TH1F(hist_name.c_str(),"",nbins, xmin, xmax);
    hist->Sumw2();
    chain->Draw(Form("%s >> %s",var_name.c_str(),hist_name.c_str()), TreeWeightVec[i].c_str(), "goff");
    
    //hist->SetName("test");
    
    normalizeHistogram(hist, TreeSFVec[i], norm, norm1, norm2 );    

    hist->SetLineWidth(2);
    hist->SetLineColor(TreeColorVec[i] == -999 ? ColorArr[counter]: TreeColorVec[i]);
    hist->SetLineStyle(TreeStyleVec[i] == -999 ? StyleArr[counter]: TreeStyleVec[i]);
    
    if(drawopt!= "HIST" && drawopt!= "hist" ){
      hist->SetMarkerColor(TreeColorVec[i] == -999 ? ColorArr[counter]: TreeColorVec[i]);

      TreeStyleVec[i] == -999 ? hist->SetLineStyle(StyleArr[counter]): hist->SetMarkerStyle(TreeStyleVec[i]);
      hist->SetLineStyle(1);
    }        

    if(drawopt == "HIST" || drawopt == "hist") leg->AddEntry(hist,TreeLegNameVec[i].c_str(),"L");
    else leg->AddEntry(hist,TreeLegNameVec[i].c_str());

    if ( hist_max == -1 || hist->GetMaximum() > hist_max) hist_max = hist->GetMaximum();
    if ( hist_min == -1 || hist->GetMinimum() < hist_min) hist_min = hist->GetMinimum();

    vecHist.push_back(hist);      
    counter++;  
  }

  double h_min = hist_min > 0 ? hist_min*0.9 : hist_min*1.1; 
  double h_max = hist_max < 0 ? hist_max*0.9 : hist_max*1.1; 

  for(unsigned int ihist = 0; ihist < vecHist.size(); ihist++){
    
    vecHist[ihist]->SetTitle("");
    vecHist[ihist]->GetXaxis()->SetTitle(xtitle.c_str());
    vecHist[ihist]->GetYaxis()->SetTitle(ytitle.c_str());
    //vecHist[ihist]->GetYaxis()->SetTitleOffset(2);
    vecHist[ihist]->SetMinimum(ymin == -999 ? h_min : ymin);
    vecHist[ihist]->SetMaximum(ymax == -999 ? h_max : ymax);
    
    if(xmin != -999) vecHist[ihist]->GetXaxis()->SetRangeUser(xmin,xmax);

    //vecHist[ihist]->GetXaxis()->SetMoreLogLabels(1);

    if(ihist == 0) vecHist[ihist]->Draw(drawopt.c_str());
    else vecHist[ihist]->Draw((drawopt+"SAME").c_str());
    
  }

  vecHist[0]->Draw("AXISSAME");

  leg->Draw();
  
  addAtlasLabel(legopt);
  string filename = m_output_dir + "/" + savename + "_" + m_output_tag + m_plot_type;
  c1->SaveAs(filename.c_str()); 

  return;
}



/*

void PlotMgr::plot2D(string savename,string ytitle,string xtitle,int norm,int rebin,double xmin, double xmax,double ymin, double ymax,string legopt,bool log,bool logz,double norm1,double norm2,string drawopt, double zmin){

  TLegend * leg = newLegend(legopt);

  TCanvas *c1 = new TCanvas("combi","",50,44,600,500);
  // make more space for the Y-axis title
  c1->SetLeftMargin(0.15); // default is 10%
  //c1->SetBottomMargin(0.15);
  c1->SetBottomMargin(0.28);
  // minimize top and bottom margin
  c1->SetRightMargin(0.15);
  c1->SetTopMargin(0.04);

  if(log) c1->SetLogy();
  if(logz) {
    c1->SetLogz();
  }

  vector<TH2F*> vecHist;
  vector<string> vecNames;
  
  TH2F* hist = 0;
  TFile * m_rootfile = 0;
  int counter = 0;

 
  for(int i = 0; i < HistoNameVec.size(); i++){
    m_rootfile = 0;
    m_rootfile = new TFile((FileNameVec[i]).c_str(),"READ");
    if (m_rootfile == 0 ){
      cout << "ERROR: file not found! " << FileNameVec[i] << endl;
      return;
    }  
    hist = 0;
    hist = (TH2F*) (m_rootfile->Get(HistoNameVec[i].c_str()));
      if(hist == 0) {
	cout<<"hist "<<i<<" cannot be found"<<endl;
	return;
      }

    //   if(norm==1){
// 	if(norm1 == -999) {
// 	  cout<<"integral before scaling: "<<hist->Integral()<<endl;
// 	  hist->Scale((double)1./(double)(hist->Integral()));
// 	}
// 	else{
// 	  int bin1 = hist->FindBin(norm1);
// 	  int bin2 = hist->FindBin(norm2);
// 	  double histint = hist->Integral(bin1,bin2-1);
// 	  cout<<"boundaries given, integral before scaling: "<<histint<<endl;
// 	  hist->Scale((double)1./(double)histint);
// 	  cout<<"boundaries given, integral after scaling: "<<hist->Integral(bin1,bin2-1)<<endl;

// 	}
//       }
//       else if(norm==2){
// 	double shift = hist->GetBinContent(1);
// 	cout<<"shift by "<<shift<<endl;
// 	for(int ibin = 1; ibin <= hist->GetNbinsX();ibin++){
// 	  hist->SetBinContent(ibin,hist->GetBinContent(ibin)-shift);
// 	}
//       }
//       else{
// 	cout<<"scale factor...integral before scaling: "<<hist->Integral()<<endl;
// 	hist->Scale(SFVec[i]);
//       }

      if(norm == 1) {
      hist->Fit("pol1");
      TF1 *fit = hist->GetFunction("pol1");
      fit->SetLineColor(ColorVec[i]);
      StyleVec[i] == 20? fit->SetLineStyle(StyleVec[i]-20): fit->SetLineStyle(StyleVec[i]-22);
    }
      else if(norm == 2) {
      hist->Fit("pol2");
      TF1 *fit = hist->GetFunction("pol2");
      fit->SetLineColor(ColorVec[i]);
      StyleVec[i] == 20? fit->SetLineStyle(StyleVec[i]-20): fit->SetLineStyle(StyleVec[i]-22);
    }
      else if(norm == 3) {
	hist->Fit("pol1","","",12,50);
      TF1 *fit = hist->GetFunction("pol1");
      fit->SetLineColor(ColorVec[i]);
      StyleVec[i] == 20? fit->SetLineStyle(StyleVec[i]-20): fit->SetLineStyle(StyleVec[i]-22);
    }
      if(rebin !=1){
	hist->Rebin(rebin);
      }

      hist->LabelsOption("v","X");

      vecHist.push_back(hist);
  }
 



  for(int ihist = 0; ihist < vecHist.size(); ihist++){

    cout<<ihist<<endl;
    vecHist[ihist]->SetLineWidth(2);
    vecHist[ihist]->SetMarkerSize(1);

    ColorVec[ihist] == -999 ? vecHist[ihist]->SetLineColor(ColorArr[ihist]): vecHist[ihist]->SetLineColor(ColorVec[ihist]);
    StyleVec[ihist] == -999 ? vecHist[ihist]->SetLineStyle(StyleArr[ihist]): vecHist[ihist]->SetLineStyle(StyleVec[ihist]);

    if(drawopt!= "HIST" && drawopt!= "hist" ){
       ColorVec[ihist] == -999 ? vecHist[ihist]->SetMarkerColor(ColorArr[ihist]): vecHist[ihist]->SetMarkerColor(ColorVec[ihist]);
       ColorVec[ihist] == -999 ? vecHist[ihist]->SetLineColor(ColorArr[ihist]): vecHist[ihist]->SetLineColor(ColorVec[ihist]);
       StyleVec[ihist] == -999 ? vecHist[ihist]->SetMarkerStyle(StyleArr[ihist]): vecHist[ihist]->SetMarkerStyle(StyleVec[ihist]);
       StyleVec[ihist] == -999 ? vecHist[ihist]->SetLineStyle(StyleArr[ihist]-20): (StyleVec[ihist] == 20 ? vecHist[ihist]->SetLineStyle(StyleVec[ihist]-20):vecHist[ihist]->SetLineStyle(StyleVec[ihist]-22));
       
    }
    
    vecHist[ihist]->SetMarkerStyle(StyleArr[ihist]);



    vecHist[ihist]->SetTitle("");
    vecHist[ihist]->GetXaxis()->SetTitle(xtitle.c_str());
    vecHist[ihist]->GetYaxis()->SetTitleOffset(1.3);
    vecHist[ihist]->GetYaxis()->SetTitle(ytitle.c_str());
    if(ymin != -999){
    //   vecHist[ihist]->SetMinimum(ymin);
//       vecHist[ihist]->SetMaximum(ymax);
      vecHist[ihist]->GetYaxis()->SetRangeUser(ymin,ymax);
    }
    if(xmin != -999) vecHist[ihist]->GetXaxis()->SetRangeUser(xmin,xmax);

    if(zmin!=-999) vecHist[ihist]->SetMinimum(zmin);
    cout<<"setting minimum..."<<zmin<<endl;

    //vecHist[ihist]->GetXaxis()->SetMoreLogLabels(1);
   if(norm !=4  && norm !=5){
      if(ihist == 0) vecHist[ihist]->Draw(drawopt.c_str());
          else {
	    vecHist[ihist]->Draw((drawopt+"SAME").c_str());
       }
      
    }
    else if(norm == 4){
      int bin1 = hist->GetYaxis()->FindBin(norm1);
      int bin2 = hist->GetYaxis()->FindBin(norm2);

      if(ihist == 0) vecHist[ihist]->ProjectionX("_px",bin1,bin2)->Draw(drawopt.c_str());
      else vecHist[ihist]->ProjectionX("_px",bin1,bin2)->Draw((drawopt+"SAME").c_str());
    }
   else if(norm == 5){
     int bin1 = hist->GetXaxis()->FindBin(norm1);
     int bin2 = hist->GetXaxis()->FindBin(norm2);
     
     vecHist[ihist]->GetYaxis()->SetTitleOffset(1.2);

      if(ihist == 0) vecHist[ihist]->ProjectionY("_py",bin1,bin2)->Draw(drawopt.c_str());
      else vecHist[ihist]->ProjectionY("_py",bin1,bin2)->Draw((drawopt+"SAME").c_str());
    }

//if(ihist == 0) vecHist[ihist]->Draw("");
    // else vecHist[ihist]->Draw("SAME");


   
    
   if(legopt!="stats"){
    if(drawopt == "HIST" || drawopt == "hist") leg->AddEntry(vecHist[ihist],LegNameVec[ihist].c_str(),"L");
    else leg->AddEntry(vecHist[ihist],LegNameVec[ihist].c_str()),"*";
  }
   else{
    int binx = vecHist[ihist]->GetXaxis()->FindBin(0.2);
    int biny = vecHist[ihist]->GetYaxis()->FindBin(0.2);

    leg->SetTextSize(0.03);

    stringstream legstream;
    legstream<<"Ele3,Ele4: "<<vecHist[ihist]->Integral(0,binx,0,biny);
    leg->AddEntry((TObject*)0, legstream.str().c_str(), "");

    stringstream legstream2;
    legstream2<<"!Ele3,!Ele4: "<<vecHist[ihist]->Integral(binx,10000,biny,10000);
    leg->AddEntry((TObject*)0, legstream2.str().c_str(), "");

    stringstream legstream3;
    legstream3<<"Ele3,!Ele4: "<<vecHist[ihist]->Integral(0,binx-1,biny,10000);
    leg->AddEntry((TObject*)0, legstream3.str().c_str(), "");

    stringstream legstream4;
    legstream4<<"!Ele3,Ele4: "<<vecHist[ihist]->Integral(binx,10000,0,biny-1);
    leg->AddEntry((TObject*)0, legstream4.str().c_str(), "");

   }
  



  }

  
  vecHist[0]->Draw("AXISSAME");

  leg->Draw();
  c1->SaveAs(savename.c_str()); 

}
*/


void PlotMgr::AddHisto(string filename, string histname, string legname, double SF,int color, int style){
  HistoFileNameVec.push_back(filename);
  HistoNameVec.push_back(histname);
  HistoLegNameVec.push_back(legname);
  HistoSFVec.push_back(SF);
  HistoColorVec.push_back(color);
  HistoStyleVec.push_back(style);
}

void PlotMgr::AddMiniTree(string filename, string treename, string legname, string weightname, double SF, int color, int style){
  TreeFileNameVec.push_back(filename);
  TreeNameVec.push_back(treename);
  TreeLegNameVec.push_back(legname);
  TreeWeightVec.push_back(weightname);
  TreeSFVec.push_back(SF);
  TreeColorVec.push_back(color);
  TreeStyleVec.push_back(style);
}

void PlotMgr::ClearVec(){

  HistoNameVec.clear();
  HistoFileNameVec.clear();
  HistoLegNameVec.clear(); 
  HistoSFVec.clear();
  HistoColorVec.clear();
  HistoStyleVec.clear();

  TreeNameVec.clear();
  TreeFileNameVec.clear();
  TreeLegNameVec.clear();  
  TreeSFVec.clear();
  TreeColorVec.clear();
  TreeStyleVec.clear(); 

}

void PlotMgr::set_plot_style()
{
    const Int_t NRGBs = 5;
    const Int_t NCont = 255;

    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    //Double_t green[NRGBs] = { 0.51, 0.81, 1.00, 0.20, 0.00 };
    ////Double_t blue[NRGBs]  = { 0.77, 0.88,0.12,0.05,0.00  };
    //Double_t blue[NRGBs]  = { 0.7, 1.00,0.12,0.05,0.00  };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
}


TLegend* PlotMgr::newLegend(string legopt)
{

  TLegend * leg = 0;
  if(legopt == "lt") leg = new TLegend(0.2,0.4,0.45,0.92);
  else if(legopt == "lb_large") leg = new TLegend(0.2,0.18,0.45,0.65);
  else if(legopt == "lt_large") leg = new TLegend(0.2,0.45,0.45,0.95);
  else if(legopt == "lb") leg = new TLegend(0.2,0.18,0.45,0.45);
  else if(legopt == "rb") leg = new TLegend(0.65,0.18,0.8,0.45);
  else if(legopt == "rt") leg = new TLegend(0.7,0.7,0.8,0.92);
  else if(legopt == "lm") leg = new TLegend(0.2,0.4,0.5,0.6);
  else if(legopt == "lmt") leg = new TLegend(0.35,0.7,0.6,0.92);
  else if(legopt == "mt") leg = new TLegend(0.5,0.7,0.8,0.92);
  else if(legopt == "stats") leg = new TLegend(0.8,0.7,0.9,0.92);
  else if(legopt == "none") leg = new TLegend(2,2,2.1,2.1);
  else leg = new TLegend(0.35,0.18,0.75,0.38);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  leg->SetFillColor(0);
  
  return leg;
}

TCanvas* PlotMgr::newCanvas(string title, bool logx, bool logy)
{

  TCanvas *c1 = new TCanvas(title.c_str(),"",50,44,800,600);
  // make more space for the Y-axis title
  c1->SetLeftMargin(0.18); // default is 10%
  c1->SetBottomMargin(0.15);
  //c1->SetBottomMargin(0.28);
  // minimize top and bottom margin
  c1->SetRightMargin(0.08);
  c1->SetTopMargin(0.04);

  if(logx)c1->SetLogx();
  if(logy)c1->SetLogy();
    
  return c1;  
}


void PlotMgr::normalizeHistogram(TH1* hist, double hist_scale, int norm, double norm1, double norm2 )
{
  if(norm==1){
    if(norm1 == -999) {
      cout<<"integral before scaling: "<<hist->Integral()<<endl;
      hist->Scale((double)1./(double)(hist->Integral()));
    } else {
      int bin1 = hist->FindBin(norm1);
      int bin2 = hist->FindBin(norm2);
      double histint = hist->Integral(bin1,bin2-1);
      cout<<"boundaries given, integral before scaling: "<<histint<<endl;
      hist->Scale((double)1./(double)histint);
      cout<<"boundaries given, integral after scaling: "<<hist->Integral(bin1,bin2-1)<<endl;

    }
  } else if(norm==2) {
    double shift = hist->GetBinContent(1);
    cout<<"shift by "<<shift<<endl;
    for(int ibin = 1; ibin <= hist->GetNbinsX();ibin++){
      hist->SetBinContent(ibin,hist->GetBinContent(ibin)-shift);
    }

  } else {
    cout<<"scale factor...integral before scaling: "<<hist->Integral()<<endl;
    hist->Scale(hist_scale); 
  }

  return;
}

TChain* PlotMgr::GetChain( string treename, string filename ) {
 
    TChain* chain;
    
    if (treename == "inclusive"){   
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

      chain= new TChain("tree_incl");    
      chain->Add(myChain_4mu  );
      chain->Add(myChain_2mu2e);
      chain->Add(myChain_2e2mu);
      chain->Add(myChain_4e   );

    } else {
      chain = new TChain(treename.c_str());
      chain->Add(filename.c_str());    
    } 
    
    return chain;    
}

void PlotMgr::addAtlasLabel(string opt){

  char writetext1[100];
  //char writetext2[100];
  //char writetext3[100];
  char writetext4[100];
  TLatex *t = new TLatex();
  t->SetNDC(1);
  t->SetTextAlign(13);
  t->SetTextSize(0.05);
  t->SetTextColor(kBlack);

  sprintf(writetext4,"#font[72]{ATLAS} Internal");
  //sprintf(writetext2,label.c_str());
  //sprintf(writetext3,"#int L dt = 20.7 fb^{-1}");
  sprintf(writetext1,"\\sqrt{s} = 8 TeV #int L dt = 20.7 fb^{-1}");

  if(opt == "rt" || opt == "tr"){
     t->DrawLatex(0.2,0.91,writetext4);
     t->SetTextSize(0.04);     
     //t->DrawLatex(0.2,0.84,writetext2);
     //t->DrawLatex(0.2,0.76,writetext3);
     t->DrawLatex(0.2,0.68,writetext1);
  }
  
  return;
}

#endif
