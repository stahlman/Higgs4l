// Dear emacs, this is -*- c++ -*-
// $Id: D3PDObjects_LinkDef.h 16587 2012-07-16 11:50:38Z stahlman $
#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;  

#pragma link C++ class D3PDReader::EventInfoD3PDObject+;
#pragma link C++ class D3PDReader::MuonD3PDObject+;
#pragma link C++ class D3PDReader::MuonD3PDObjectElement+;
#pragma link C++ class D3PDReader::MuonStacoD3PDObject+;
#pragma link C++ class D3PDReader::MuonStacoD3PDObjectElement+;
#pragma link C++ class D3PDReader::MuonMuidD3PDObject+;
#pragma link C++ class D3PDReader::MuonMuidD3PDObjectElement+;
#pragma link C++ class D3PDReader::ElectronD3PDObject+;
#pragma link C++ class D3PDReader::ElectronD3PDObjectElement+;
#pragma link C++ class D3PDReader::PrimaryVertexD3PDObject+;
#pragma link C++ class D3PDReader::PrimaryVertexD3PDObjectElement+;
#pragma link C++ class D3PDReader::PhotonD3PDObject+;
#pragma link C++ class D3PDReader::PhotonD3PDObjectElement+;
#pragma link C++ class D3PDReader::TauD3PDObject+;
#pragma link C++ class D3PDReader::TauD3PDObjectElement+;
#pragma link C++ class D3PDReader::TriggerD3PDObject+;
#pragma link C++ class D3PDReader::METD3PDObject+;
#pragma link C++ class D3PDReader::TruthParticleD3PDObject+;
#pragma link C++ class D3PDReader::TruthParticleD3PDObjectElement+;
#pragma link C++ class D3PDReader::JetD3PDObject+;
#pragma link C++ class D3PDReader::JetD3PDObjectElement+;
#pragma link C++ class D3PDReader::MCEvtD3PDObject+;

// #pragma link C++ class D3PDReader::TrigDecisionD3PDObject+;
// #pragma link C++ class D3PDReader::TrigEFelD3PDObject+;
// #pragma link C++ class D3PDReader::TrigEFelD3PDObjectElement+;
// #pragma link C++ class D3PDReader::TrigEFmuD3PDObject+;
// #pragma link C++ class D3PDReader::TrigEFmuD3PDObjectElement+;
// #pragma link C++ class D3PDReader::TrigEFtauD3PDObject+;
// #pragma link C++ class D3PDReader::TrigEFtauD3PDObjectElement+;
// #pragma link C++ class D3PDReader::TrigMETD3PDObject+;
// #pragma link C++ class D3PDReader::MCEvtD3PDObject+;
// #pragma link C++ class D3PDReader::HadronRecoilD3PDObject+;
// #pragma link C++ class D3PDReader::HadronRecoilD3PDObjectElement+;
// #pragma link C++ class D3PDReader::GenEventD3PDObject+;
// #pragma link C++ class D3PDReader::GenEventD3PDObjectElement+;

#pragma link C++ class D3PDReader::D3PDPerfStats+;
#pragma link C++ class D3PDReader::D3PDReadStats+;
#pragma link C++ class D3PDReader::VariableStats+;
#pragma link C++ class D3PDReader::D3PDObjectBase+;

// vector vectors
#pragma link C++ class std::vector<std::vector<int> >+;
#pragma link C++ class std::vector<std::vector<unsigned int> >+;
#pragma link C++ class std::vector<std::vector<long> >+;
#pragma link C++ class std::vector<std::vector<unsigned long> >+;
#pragma link C++ class std::vector<std::vector<float> >+;
#pragma link C++ class std::vector<std::vector<double> >+;
#pragma link C++ class std::vector<std::vector<string> >+;
#pragma link C++ class std::vector<std::vector<bool> >+;

#endif // __CINT__
