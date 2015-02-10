#ifndef AtlasSFrameTools_ParticleElementBuilder_h
#define AtlasSFrameTools_ParticleElementBuilder_h 

#include <vector>
#include <iostream>
#include "TruthParticle.h"

#include "TruthParticle.h"

namespace ParticleElementBuilder
{

  template < class ParticleElementType, class D3PDObjectType >
  void build(std::vector<ParticleElementType>& vec, const D3PDObjectType& obj);
  
  void build(std::vector<TruthParticle>& vec, const D3PDReader::TruthParticleD3PDObject& obj);
  void build(std::vector<TruthParticle*>& vec, const D3PDReader::TruthParticleD3PDObject& obj);
};

//______________________________________________________________________________
template < class ParticleElementType, class D3PDObjectType >
void ParticleElementBuilder::build(std::vector<ParticleElementType>& vec, const D3PDObjectType& obj)
{
    for(int i=0; i < obj.n(); i++)
    {
         vec.push_back( ParticleElementType( obj[i], i ) );
    }
    
    // temporary hack: get size from another variable
    if (!obj.n.IsAvailable()) {
        unsigned int vec_length = obj.pt()->size();
    
        for(unsigned int i=0; i < vec_length; i++)
        {
            vec.push_back( ParticleElementType( obj[i], i ) );
        }
    }
}

#endif
