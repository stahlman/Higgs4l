// file:        Jet.h
// author:      Ryan Reece       <ryan.reece@cern.ch>
// created:     January 2010
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Jet_h
#define AtlasSFrameUtils_Jet_h

#include "ParticleElement.h"
#include "ParticleElementBuilder.h"
#include "JetD3PDObject.h"
#include <vector>

class Jet : public ParticleElement<D3PDReader::JetD3PDObjectElement> {

 public:
  // main constructor
  Jet(const ParticleElement<D3PDReader::JetD3PDObjectElement>& p, int index = -1);
  
  void SetVector(TLorentzVector v) { calibrated_vector = v;};
   
  TLorentzVector TLV(){return calibrated_vector;};

  double Pt(){ return calibrated_vector.Pt();};
  double Eta(){ return calibrated_vector.Eta();};
  double Phi(){ return calibrated_vector.Phi();};
  double Rapidity(){ return calibrated_vector.Rapidity();};
  double M(){ return calibrated_vector.M();};
  
  void SetfCloseby(double t){ m_fcloseby = t;}
  double fCloseby(){return m_fcloseby;}
  
 private:
  
  double m_fcloseby;
  
  TLorentzVector calibrated_vector;

  ClassDef(Jet, 1);

};


//typedef ParticleElement< D3PDReader::JetD3PDObjectElement > Jet;
//typedef ParticleElementBuilder::build< Jet, D3PDReader::JetD3PDObject > JetBuilder;

#endif // AtlasSFrameUtils_Jet_h
