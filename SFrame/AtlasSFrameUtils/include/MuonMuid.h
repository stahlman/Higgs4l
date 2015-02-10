// file:        Muon.h
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     January 2010
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_MuonMuid_h
#define AtlasSFrameUtils_MuonMuid_h

#include "ParticleElement.h"
#include "ParticleElementBuilder.h"
#include "MuonMuidD3PDObject.h"
#include <vector>

typedef ParticleElement< D3PDReader::MuonMuidD3PDObjectElement > MuonMuid;
//typedef ParticleElementBuilder::build< Muon, D3PDReader::MuonMuidD3PDObject > MuonBuilder;

#endif // AtlasSFrameUtils_MuonMuid_h
