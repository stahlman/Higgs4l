#include "../include/ParticleElementBuilder.h"

void ParticleElementBuilder::build(std::vector<TruthParticle>& vec, const D3PDReader::TruthParticleD3PDObject& obj)
{

  for(int i = 0; i != obj.n(); ++i){
    vec.push_back( TruthParticle( obj[i], &obj, i ) );
  }

}

void ParticleElementBuilder::build(std::vector<TruthParticle*>& vec, const D3PDReader::TruthParticleD3PDObject& obj)
{

  for(int i = 0; i != obj.n(); ++i){
    vec.push_back( new TruthParticle( obj[i], &obj, i ) );
  }

}
