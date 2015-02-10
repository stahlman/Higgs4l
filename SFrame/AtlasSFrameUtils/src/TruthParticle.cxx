#include "../include/TruthParticle.h"

ClassImp(TruthParticle)

//____________________________________________________________________________
TruthParticle::TruthParticle(const ParticleElement<D3PDReader::TruthParticleD3PDObjectElement>& p, const D3PDReader::TruthParticleD3PDObject* object, int index)
  : ParticleElement<D3PDReader::TruthParticleD3PDObjectElement>(p,index),
    m_truth_d3pd_object(object)
{
  bare_tlv.SetPtEtaPhiM(pt(),eta(),phi(),m());
}

//____________________________________________________________________________
TruthParticle::TruthParticle(const TruthParticle& p)
  : ParticleElement<D3PDReader::TruthParticleD3PDObjectElement>(p,p.D3PD_index), 
    m_truth_d3pd_object(p.m_truth_d3pd_object)
{
  bare_tlv.SetPtEtaPhiM(pt(),eta(),phi(),m());
  fsr_tlv = p.fsr_tlv;
}

//____________________________________________________________________________
TruthParticle& TruthParticle::operator=(const TruthParticle& p) 
{
  if(this != &p)
    {
      this->ParticleElement<D3PDReader::TruthParticleD3PDObjectElement>::operator=(p);
      this->m_truth_d3pd_object = p.m_truth_d3pd_object;
    }
  return *this;
}

//____________________________________________________________________________
bool TruthParticle::operator == (const TruthParticle &p) const
{
  if( this->barcode() == p.barcode() ) return true;
  else return false;
}

//____________________________________________________________________________
bool TruthParticle::operator != (const TruthParticle &p) const
{
  return !( (*this) == p);
}


//____________________________________________________________________________
TruthParticle TruthParticle::GetMother() const
{
  std::vector<int> parents = this->parent_index();
  if(!parents.size()) return (*this);
  return TruthParticle( (*m_truth_d3pd_object)[parents[0]], m_truth_d3pd_object );
}

 /*
//removed for now - causes rootcint to crash
//____________________________________________________________________________
void TruthParticle::GetParents(std::vector<TruthParticle>& parents) const
{
  std::vector<int> parent = this->parent_index();
  for(unsigned i = 0; i != parent.size(); ++i)
    {
      parents.push_back( TruthParticle( (*m_truth_d3pd_object)[parent[i]], m_truth_d3pd_object ) );
    }
}

//____________________________________________________________________________
void TruthParticle::GetChildren(std::vector<TruthParticle>& children) const
{
  std::vector<int> child = this->child_index();
  for(unsigned i = 0; i != child.size(); ++i)
    {
      children.push_back( TruthParticle( (*m_truth_d3pd_object)[child[i]], m_truth_d3pd_object ) );
    }
} 


*/
