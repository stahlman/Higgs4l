// Dear emacs, this is -*- c++ -*-
// $Id: CommonTools_LinkDef.h 24926 2013-10-04 16:50:30Z stahlman $
#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;

// Add the declarations of your cycles, and any other classes for which you
// want to generate a dictionary, here. The usual format is:
//
// #pragma link C++ class MySuperClass+;

#pragma link C++ class Root::TPileupReweighting+ ; //sarah test
#pragma link C++ class ScaleFactorTool+ ; 
#pragma link C++ class HiggsMassTool+ ; 
#pragma link C++ class ZZPtSystTool+ ; 
//#pragma link C++ class Root::ElectronLikelihoodTool+ ; 

#pragma link C++ class map<string,string>;

#endif // __CINT__
