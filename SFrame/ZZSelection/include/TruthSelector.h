// Dear emacs, this is -*- c++ -*-
// $Id: TruthSelector.h 27180 2014-05-27 13:55:11Z stahlman $
#ifndef TruthSelector_H
#define TruthSelector_H

//#include <string>

// D3PDObjects
#include "TruthParticleD3PDObject.h"

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Quadruplet.h"
#include "TruthParticle.h"

//Common tools
#include "PdtPdg.h"


//RootCore include(s):

/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 27180 $
 */
class TruthSelector : public ToolBase {

public:
   /// Default constructor
   TruthSelector( SCycleBase* parent, const char* name = "Truth" );
   
   /// Default destructor
   ~TruthSelector();
   
   void BeginInputData( const SInputData& id );
   
   void DressLeptons( const D3PDReader::TruthParticleD3PDObject* truth_d3pdobject, std::vector<TruthParticle*> &dressed_particles );
   void PairLeptons( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &quad );
   
   void GetBornTruthQuad( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &quad );
   void GetPairedTruthQuad( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &quad );

   void GetMatchedTruthQuad( Quadruplet* quad, std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &matched_quad);
   void GetMatchedBornTruthQuad( Quadruplet* quad, std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &matched_quad);

   TruthParticle* GetTruthHiggs(std::vector<TruthParticle*> &tparts);
   TruthParticle* GetTruthZ(int index, std::vector<TruthParticle*> &tparts );
   TruthParticle* GetTruthLepton(int index, std::vector<TruthParticle*> &tparts );
   
   bool Mispaired( std::vector<TruthParticle*> &quad);
   bool HiggsQuad( std::vector<TruthParticle*> &tparts, std::vector<TruthParticle*> &quad);

   int MatchElectron( Electron* electron, std::vector<TruthParticle*> &tparts);
   int MatchMuon( Muon* muon, std::vector<TruthParticle*> &tparts );

   int MatchBornElectron( Electron* electron, std::vector<TruthParticle*> &tparts);
   int MatchBornMuon( Muon* muon, std::vector<TruthParticle*> &tparts );

   int ClassifyEvent( std::vector<TruthParticle*> &tparts );
   int ClassifyQuad( std::vector<TruthParticle*> &tparts );

   double HiggsPtWeight(int channel, std::vector<TruthParticle*> &tparts, std::vector<Jet> &jets );

   //TLorentzVector MatchedQuad( Quadruplet* quad, std::vector<TruthParticle*> &tparts );
   //TLorentzVector MatchedZ1( Quadruplet* quad, std::vector<TruthParticle*> &tparts );
   //TLorentzVector MatchedZ2( Quadruplet* quad, std::vector<TruthParticle*> &tparts );

private:
   //
   // Put all your private variables here
   //
   std::string m_recoTreeName;

   TH1F* m_ggF_HpT_weight_01jets;  
   TH1F* m_ggF_HpT_weight_geq2jets;      

 
   // Macro adding the functions for dictionary generation
   ClassDef( TruthSelector, 0 );

}; // class TruthSelector

#endif // TruthSelector_H
