#include "PlotMgr.C"
#include <string>
#include <vector>

void makeplots(){

  PlotMgr * plotMgr = new PlotMgr();

  //string InputDir = "/local_data1/stahlman/output/HSG2_output/29012013/";
  string InputDir = "/local_data1/stahlman/output/HSG2_output/05022013/";
  
  string OutputDir = InputDir + "Plots/";

  string plottype = ".eps";
  //string plottype = ".png";
  string InputFile = "";
  //string cat [] = {"1","2","3","4","5","6","99"};
  //int ncat = 7;
  string cat [] = {"1","2","3","4"};
  int ncat = 4;


  //string tag = "RelaxedMLOR";
  string tag = "RelaxedML";
 
  plotMgr->AddHisto(InputDir+"Zjets_CR_"+tag+"_passed.root","h_m_4l_4e","MC OS",1.);
  plotMgr->AddHisto(InputDir+"Zjets_SS_CR_"+tag+"_passed.root","h_m_4l_4e","MC SS",1.);
  plotMgr->AddHisto(InputDir+"Data_CR_"+tag+"_passed.root","h_m_4l_4e","Data OS",1.);
  plotMgr->AddHisto(InputDir+"Data_SS_CR_"+tag+"_passed.root","h_m_4l_4e","Data SS",1.);
  
  //plotMgr->AddHisto(InputDir+"Zjets_CR_SiTrack_passed.root","h_m_4l_4e","SiTrack",1.);

  //void PlotMgr::plot(string savename,string ytitle,string xtitle,int norm,int rebin,double xmin, double xmax,double ymin, double ymax,string legopt,bool log,bool logx,double norm1,double norm2,string drawopt){
  plotMgr->plot(OutputDir+"/h_m_4l_4e."+tag+"Comparison"+plottype,"","",1,5,-999,-999,-999,-999,"rt",0,0,-999,-999,"");
   
  plotMgr->ClearVec();
   
  //plotMgr->AddHisto(InputDir+"Zjets_CR_RelaxedML_passed.root","h_m_4l_2mu2e","R_ML",1.);
  //plotMgr->AddHisto(InputDir+"Zjets_CR_"+tag+"_passed.root","h_m_4l_2mu2e","R_ML_OR",1.);
  //plotMgr->AddHisto(InputDir+"Zjets_CR_SiTrack_passed.root","h_m_4l_2mu2e","Si",1.);

  plotMgr->AddHisto(InputDir+"Zjets_CR_"+tag+"_passed.root","h_m_4l_2mu2e","MC OS",1.);
  plotMgr->AddHisto(InputDir+"Zjets_SS_CR_"+tag+"_passed.root","h_m_4l_2mu2e","MC SS",1.);
  plotMgr->AddHisto(InputDir+"Data_CR_"+tag+"_passed.root","h_m_4l_2mu2e","Data OS",1.);
  plotMgr->AddHisto(InputDir+"Data_SS_CR_"+tag+"_passed.root","h_m_4l_2mu2e","Data SS",1.);

  //void PlotMgr::plot(string savename,string ytitle,string xtitle,int norm,int rebin,double xmin, double xmax,double ymin, double ymax,string legopt,bool log,bool logx,double norm1,double norm2,string drawopt){
  plotMgr->plot(OutputDir+"/h_m_4l_2mu2e."+tag+"Comparison"+plottype,"","",1,5,-999,-999,-999,-999,"rt",0,0,-999,-999,"");

  return;


}
