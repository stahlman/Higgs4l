// file:        Muon.h
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     January 2010
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_MuonStaco_h
#define AtlasSFrameUtils_MuonStaco_h

#include "ParticleElement.h"
//#include "ParticleElementBuilder.h"
#include "MuonStacoD3PDObject.h"
#include <vector>

/*
class MuonStaco : public ParticleElement<D3PDReader::MuonStacoD3PDObjectElement> {

 public:
  // main constructor
  MuonStaco(const ParticleElement<D3PDReader::MuonStacoD3PDObjectElement>& p, int index = -1);
  
  bool isMuon() { return true; };
  
  ClassDef(MuonStaco, 1);

};
*/

typedef ParticleElement< D3PDReader::MuonStacoD3PDObjectElement > MuonStaco;
//typedef ParticleElementBuilder::build< Muon, D3PDReader::MuonD3PDObject > MuonBuilder;

#endif // AtlasSFrameUtils_MuonStaco_h
