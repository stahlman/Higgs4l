// Dear emacs, this is -*- c++ -*-
// $Id: ZZSelection_LinkDef.h 23528 2013-05-30 16:16:04Z stahlman $
#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;

// Add the declarations of your cycles, and any other classes for which you
// want to generate a dictionary, here. The usual format is:
//
// #pragma link C++ class MySuperClass+;

#pragma link C++ class ZZ_Selection+;
#pragma link C++ class ZZCutFlow+;
#pragma link C++ class TriggerSelector+;
#pragma link C++ class ElectronSelector+;
#pragma link C++ class MuonSelector+;
#pragma link C++ class JetSelector+;
#pragma link C++ class QuadSelector+;
#pragma link C++ class TruthSelector+;
#pragma link C++ class FsrSelector+;

#endif // __CINT__
