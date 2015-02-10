// file:        TruthParticle.h
// author:      Jonathan Stahlman       <stahlman@cern.ch>
// created:     September 2013
//------------------------------------------------------------------------------
#ifndef AtlasSframeUtils_TruthParticle_h
#define AtlasSframeUtils_TruthParticle_h

#include "ParticleElement.h"
#include "TruthParticleD3PDObject.h"
#include <vector>


class TruthParticle : public ParticleElement<D3PDReader::TruthParticleD3PDObjectElement> {

 public:
  // main constructor
  TruthParticle(const ParticleElement<D3PDReader::TruthParticleD3PDObjectElement>& p, const D3PDReader::TruthParticleD3PDObject* object, int index = -1);


  // copy constructor
  TruthParticle(const TruthParticle& p);

  // assignment operator
  TruthParticle& operator=(const TruthParticle& p);

  //equal operator
  bool operator == (const TruthParticle &p) const;
  bool operator != (const TruthParticle &p) const;

  //functions
  //Returns itself in no mother record present
  //Do while( part->GetMother() != part )
  //In any recursive functions
  TruthParticle GetMother() const;
  
  TLorentzVector TLV() {  return bare_tlv;};
  TLorentzVector Dressed_TLV() { return bare_tlv + fsr_tlv; };
  
  void AddPhoton(TLorentzVector t) { fsr_tlv = fsr_tlv + t; };

  //removed for now - causes rootcint to crash
  //void GetParents(std::vector<TruthParticle>& parents) const;
  //void GetChildren(std::vector<TruthParticle>& children) const; 

 private:
  //This is not owned
  const D3PDReader::TruthParticleD3PDObject* m_truth_d3pd_object;

  TLorentzVector bare_tlv;
  TLorentzVector fsr_tlv;

  ClassDef(TruthParticle, 1);

};


#endif
