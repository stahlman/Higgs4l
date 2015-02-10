#ifndef ZZPtSystTool_H
#define ZZPtSystTool_H

#include "TFile.h"
#include "TObject.h"
#include "TH2.h"

#include <iostream>

class ZZPtSystTool {
   public: 
    
    typedef enum { PT, RAPIDITY, M34, COSTHETASTAR } Variable;
    typedef enum { NOMINAL, PLUS1SIGMA, MINUS1SIGMA } Variation;   

    ZZPtSystTool(std::string);
    ~ZZPtSystTool();
    
    double RewSys(Variable variable, float value, int channel, std::string source, Variation syst);
    double Rewscale( Variable var, float var_value, int channel,  Variation sigma);
    double Rewpdfset( Variable var, float var_value, Variation sigma);

 
private:
    TFile* _file0;

#if !defined(ALLOW_INCLUDE_CODE) || !defined(__ACLIC__)
protected:
        ClassDef(ZZPtSystTool, 1)
#endif



    
};

#endif
