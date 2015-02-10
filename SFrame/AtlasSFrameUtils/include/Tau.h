// file:        Tau.h
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     January 2010
//------------------------------------------------------------------------------
#ifndef AtlasSFrameTools_Tau_h
#define AtlasSFrameTools_Tau_h

#include "ParticleElement.h"
#include "ParticleElementBuilder.h"
#include "TauD3PDObject.h"
#include <vector>

typedef ParticleElement< D3PDReader::TauD3PDObjectElement > Tau;
//typedef ParticleElementBuilder::build< Tau, D3PDReader::TauD3PDObject > TauBuilder;

#endif // AtlasSFrameTools_Tau_h
