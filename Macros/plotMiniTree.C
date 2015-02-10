#include "PlotMgr.C"
#include <string>
#include <vector>

void makeplots(){

  //string InputDir = "/local_data1/stahlman/output/HSG2_output/29012013/";
  //string InputDir = "/local_data1/stahlman/output/HSG2_output/05022013/";
  //string InputDir = "/local_data1/stahlman/output/HSG2_output/Moriond/";
  string InputDir = "/local_data1/stahlman/output/HSG2_output/04062013/";
  
  string OutputDir = InputDir + "Plots/";

  //string OutputTag = "test";
  //string OutputTag = "ZbbSidebandComparison";
  string OutputTag = "ZbbCRComparison";
  
  string plottype = ".eps";
  //string plottype = ".png";
  
  //string InputFile = "";
  //string cat [] = {"1","2","3","4","5","6","99"};
  //int ncat = 7;
  //string cat [] = {"1","2","3","4"};
  //int ncat = 4;

  string binpt = "((higgspt <20)+(higgspt>20&&higgspt<50)*2+(higgspt>50&&higgspt<100)*3+(higgspt>100)*4)";  

  string signalwindow     = "(m4l_constrained>120)&&(m4l_constrained<130)";
  string sidebandhiwindow = "(m4l_constrained>130)&&(m4l_constrained<140)";
  string sidebandlowindow = "(m4l_constrained>110)&&(m4l_constrained<120)";
  
  PlotMgr * plotMgr = new PlotMgr(OutputDir,OutputTag, plottype);
 
  //**********
  //Add files
  //**********
  //void AddMiniTree(string filename, string histname, string legname, int color=-999, int style=-999);

  //plotMgr->AddMiniTree(InputDir+"Minitrees/MC12_Zjets_CR_RelaxIsoNoD0.root","tree_incl_4e","MC OS RelaxIsoNoD0");
  //plotMgr->AddMiniTree(InputDir+"Minitrees/MC12_Zjets_CR_NoIsoNoD0.root","tree_incl_4e","MC OS NoIsoNoD0");
  //plotMgr->AddMiniTree(InputDir+"Minitrees/Data_CR_IsoD0.root","tree_incl_4e","Data OS IsoD0");
  //plotMgr->AddMiniTree(InputDir+"Minitrees/Data_CR_RelaxIsoD0.root","tree_incl_4e","Data OS RelaxIsoD0");
  //plotMgr->AddMiniTree(InputDir+"Minitrees/Data_CR_RelaxIsoNoD0.root","tree_incl_4e","Data OS RelaxIsoNoD0");
  //plotMgr->AddMiniTree(InputDir+"Minitrees/Data_CR_NoIsoNoD0.root","tree_incl_4e","Data OS NoIsoNoD0");
  //plotMgr->AddMiniTree(InputDir+"Minitrees/Data_SS_CR_RelaxIsoNoD0.root","tree_incl_4e","Data SS RelaxIsoNoD0");
  //plotMgr->AddMiniTree(InputDir+"minitrees/v02/MC12a/Signal/*H125_ZZ4lep.root","tree_incl_4e","MC11");
  //plotMgr->AddMiniTree(InputDir+"minitrees/v02/MC11c/Signal/*H125_ZZ4lep.root","tree_incl_4e","MC12");

  //plotMgr->AddMiniTree(InputDir+"minitrees/v02/MC12a/Signal/*H125_ZZ4lep.root","tree_incl_4e","p_{T} < 25 GeV", "weight*(higgspt<25)");
  //plotMgr->AddMiniTree(InputDir+"minitrees/v02/MC12a/Signal/*H125_ZZ4lep.root","tree_incl_4e","25 < p_{T} < 50 GeV", "weight*(higgspt<50&&higgspt>=25)");
  //plotMgr->AddMiniTree(InputDir+"minitrees/v02/MC12a/Signal/*H125_ZZ4lep.root","tree_incl_4e","p_{T} >= 50 GeV", "weight*(higgspt>=50)");

  //plotMgr->AddMiniTree(InputDir+"SignalRegion/*ZZ*.root","inclusive","ZZ SR",    signalwindow+"*weight");
  //plotMgr->AddMiniTree(InputDir+"SignalRegion/*ZZ*.root","inclusive","ZZ SB Hi", sidebandhiwindow+"*weight");
  //plotMgr->AddMiniTree(InputDir+"SignalRegion/*ZZ*.root","inclusive","ZZ SB Lo", sidebandlowindow+"*weight");
  
  plotMgr->AddMiniTree(InputDir+"SignalRegion/*Zbb*.root","inclusive","Zbb", signalwindow+"*weight");
  //plotMgr->AddMiniTree(InputDir+"SignalRegion/*Zbb*.root","inclusive","Zbb SB Hi", sidebandhiwindow+"*weight");
  //plotMgr->AddMiniTree(InputDir+"SignalRegion/*Zbb*.root","inclusive","Zbb SB Lo", sidebandlowindow+"*weight");

  //plotMgr->AddMiniTree(InputDir+"LooseCalo_LooseD0/*Zbb*.root",        "inclusive","Zbb LooseCalo_LooseD0",      signalwindow+"*weight");
  //plotMgr->AddMiniTree(InputDir+"NoCalo_NoD0_LooseTrack/*Zbb*.root",   "inclusive","Zbb NoCalo_NoD0_LooseTrack", signalwindow+"*weight");
  plotMgr->AddMiniTree(InputDir+"LooseTrack_LooseCalo_NoD0/*Zbb*.root","inclusive","Zbb LooseTrack_LooseCalo_NoD0", signalwindow+"*weight");
  //plotMgr->AddMiniTree(InputDir+"NoIso_FailD0/*Zbb*.root",	       "inclusive","Zbb NoIso_FailD0",	      signalwindow+"*weight");
  //plotMgr->AddMiniTree(InputDir+"FailD0/*Zbb*.root",	               "inclusive","Zbb FailD0",	              signalwindow+"*weight");
  //plotMgr->AddMiniTree(InputDir+"FailTrack_FailCalo/*Zbb*.root",       "inclusive","Zbb FailTrack_FailCalo",	              signalwindow+"*weight");


  plotMgr->AddMiniTree(InputDir+"NoIso_NoD0_LooseRelaxed/*Zjets*.root","inclusive","Zjets NoIso_NoD0_LooseRelaxed", signalwindow+"*weight");

  //**********
  //Make plots
  //**********
  //void PlotMgr::plot(string var_name, string savename,string ytitle,string xtitle,int norm,int rebin,double xmin, double xmax,double ymin, double ymax,string legopt,bool log,bool logx,double norm1,double norm2,string drawopt){

  //plotMgr->plot("m4l_unconstrained","m4l_unconstrained","arb. units","M_{4l}",1,45,50,500,-999,-999,"rt",0,0,-999,-999,"E");
  //plotMgr->plot("higgspt","higgspt","arb. units","p_{T}^{4l} [GeV]",1,100,0,300,-999,-999,"rt",0,0,-999,-999,"E");

  plotMgr->plot(binpt, "binpt","arb. units","p_{T}^{4l} bin",1,4,0.5,4.5,0.0001,1.0,"rt",0,0,-999,-999,"E");

   
  plotMgr->ClearVec();
   

  return;


}
