#include "../include/ZZPtSystTool.h"

// ____________________________________________________________________________|__________
// Constructor
ZZPtSystTool::ZZPtSystTool(std::string input_file)
:

_file0(NULL)

{
    _file0 = TFile::Open(input_file.c_str());
    if (!_file0) {
        std::cout<<"ZZPtSystTool: Unable to open input file: " <<input_file<<std::endl;
    }
}

// ____________________________________________________________________________|__________/ Destructor
ZZPtSystTool::~ZZPtSystTool()
{
    if (_file0) _file0->Close();
}

//  std::string sigma:
//  "nominal"
//  "plus1sigma"
//  "minus1sigma"

double ZZPtSystTool::RewSys(Variable var, float value, int channel, std::string source, Variation syst){
    
    std::string histovar;
    if (var == PT)       histovar = "pt";    
    else if (var == RAPIDITY) histovar = "rapidity";
    else if (var == M34) histovar = "m34";
    else if (var == COSTHETASTAR) histovar = "costhetastar";

    std::string histocat;    
    if (source =="pdf"){
      histocat = "all";
    } else {
      if ( channel == 0 || channel == 2 ) histocat = "sameflavour";
      if ( channel == 1 || channel == 3 ) histocat = "oppositeflavour";
    }
 
    std::string histoname = histovar+"_"+source+"_"+histocat;
    
    TH1F *nominal = (TH1F*) _file0->Get((histoname+"_nominal").c_str());
    if (!nominal) {
      std::cout<<"WARNING  ZZPtSystTool: Unable to find histogram: " << histoname<<"_nominal"<<std::endl;
      return 0;
    }    

    std::string sigma;
    if (syst == PLUS1SIGMA)  sigma = "plus1sigma";
    else if (syst == MINUS1SIGMA) sigma = "minus1sigma";
     
    TH1F *variation = (TH1F*) _file0->Get((histoname+"_"+sigma).c_str());
    if (!variation){
      std::cout<<"WARNING  ZZPtSystTool: Unable to find histogram: " << histoname<<"_"<<sigma<<std::endl;
      return 0;
    }    
    
    int bin = nominal->FindBin(value);
   
    double weight = variation->GetBinContent(bin)/nominal->GetBinContent(bin);
    
    return weight;
}

double ZZPtSystTool::Rewscale(Variable var, float var_value, int channel, Variation syst){
    
    std::string histname;
    
    if (var == PT)       histname = "";    
    if (var == RAPIDITY) histname = "Eta_";
    
    if ( channel == 0 || channel == 1 ) histname += "sameflavour";
    if ( channel == 2 || channel == 3 ) histname += "oppositeflavour";
        
    TH1F *nominal   = (TH1F*) _file0->Get((histname+"_nominal").c_str());
    if (!nominal) {
      std::cout<<"WARNING  ZZPtSystTool: Unable to find histogram: " << histname<<"_nominal"<<std::endl;
      return 0;
    }
 
    std::string sigma;    
    if (syst == NOMINAL)     sigma = "nominal";
    if (syst == PLUS1SIGMA)  sigma = "plus1sigma";
    if (syst == MINUS1SIGMA) sigma = "minus1sigma";
   
    TH1F *variation = (TH1F*) _file0->Get((histname+"_"+sigma).c_str());
    if (!variation){
      std::cout<<"WARNING  ZZPtSystTool: Unable to find histogram: " << histname<<"_"<<sigma<<std::endl;
      return 0;
    }
    
    int bin = nominal->FindBin(var_value);    
    if (bin == 0 || bin == nominal->GetNbinsX() + 1) return 1;
    
    double denom  = nominal->GetBinContent(bin);
    if (denom == 0){
      std::cout<<"WARNING  ZZPtSystTool: Denominator == 0: Check input histogram " << histname<<"_nominal bin "<< bin <<std::endl;
      return 0;    
    }
    
    double weight = variation->GetBinContent(bin)/denom;
    
    return weight;
}

double ZZPtSystTool::Rewpdfset( Variable var, float var_value, Variation syst){

    std::string histname;
    
    if (var == PT)       histname = "";    
    if (var == RAPIDITY) histname = "Eta_";

    histname += "pdfvar";

    TH1F *nominal   = (TH1F*) _file0->Get((histname+"_nominal").c_str());
    if (!nominal) {
      std::cout<<"WARNING  ZZPtSystTool: Unable to find histogram: " << histname<<"_nominal"<<std::endl;
      return 0;
    }

    std::string sigma;    
    if (syst == NOMINAL)     sigma = "nominal";
    if (syst == PLUS1SIGMA)  sigma = "plus1sigma";
    if (syst == MINUS1SIGMA) sigma = "minus1sigma";
   
    TH1F *variation = (TH1F*) _file0->Get((histname+"_"+sigma).c_str());
    if (!variation) {
      std::cout<<"WARNING  ZZPtSystTool: Unable to find histogram: " << histname<<"_"<<sigma<<std::endl;
      return 0;
    }

    int bin = nominal->FindBin(var_value);
    if (bin == 0 || bin == nominal->GetNbinsX() + 1) return 1;

    double denom  = nominal->GetBinContent(bin);
    if (denom == 0){
      std::cout<<"WARNING  ZZPtSystTool: Denominator == 0: Check input histogram " << histname<<"_nominal bin "<< bin <<std::endl;
      return 0;    
    }
    
    double weight = variation->GetBinContent(bin)/denom;
    
    return weight;
}
