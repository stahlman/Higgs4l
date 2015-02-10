// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------
#ifndef D3PDREADER_MuonMuidD3PDObject_H
#define D3PDREADER_MuonMuidD3PDObject_H

#include <map>
#include <vector>
using std::vector;

#include <TObject.h>
#include <TString.h>

#include "VarHandle.h"
#include "VarProxy.h"

class TTree;

namespace D3PDReader {

   // Forward declaration(s):
   class MuonMuidD3PDObject;

   /**
    * Code generated by CodeGenerator_v2 on:
    *  host = pc-penn-d-05.cern.ch
    *  OS   = Linux / 2.6.18-274.3.1.el5
    *  user = jdegenha
    *  time = Mon Nov  7 10:17:47 2011
    */
   class MuonMuidD3PDObjectElement : public TObject {

      friend class MuonMuidD3PDObject;

   protected:
      /// Constructor only visible to MuonMuidD3PDObject
      MuonMuidD3PDObjectElement( size_t index, const MuonMuidD3PDObject& parent );

   public:
      /// Copy constructor
      MuonMuidD3PDObjectElement( const MuonMuidD3PDObjectElement& parent );

      VarProxy< float > E;
      VarProxy< float > pt;
      VarProxy< float > m;
      VarProxy< float > eta;
      VarProxy< float > phi;
      VarProxy< float > px;
      VarProxy< float > py;
      VarProxy< float > pz;
      VarProxy< float > charge;
      VarProxy< unsigned short > allauthor;
      VarProxy< int > author;
      VarProxy< float > beta;
      VarProxy< float > isMuonLikelihood;
      VarProxy< float > matchchi2;
      VarProxy< int > matchndof;
      VarProxy< float > etcone20;
      VarProxy< float > etcone30;
      VarProxy< float > etcone40;
      VarProxy< float > nucone20;
      VarProxy< float > nucone30;
      VarProxy< float > nucone40;
      VarProxy< float > ptcone20;
      VarProxy< float > ptcone30;
      VarProxy< float > ptcone40;
      VarProxy< float > energyLossPar;
      VarProxy< float > energyLossErr;
      VarProxy< float > etCore;
      VarProxy< float > energyLossType;
      VarProxy< unsigned short > caloMuonIdTag;
      VarProxy< double > caloLRLikelihood;
      /// Is this combined track the best match to a MS track?
      VarProxy< int > bestMatch;
      /// Muon identified by a spectrometer track (not associated to ID).
      VarProxy< int > isStandAloneMuon;
      /// Muon identified by combining an ID and a MS track.
      VarProxy< int > isCombinedMuon;
      /// Low-pt reconstructed muon (deprecated).
      VarProxy< int > isLowPtReconstructedMuon;
      /// Muon identified by inner-detector seeded identification (segment tagging or ID+MS refit).
      VarProxy< int > isSegmentTaggedMuon;
      /// Muon identified solely from calorimeter information (so no signal in MS).
      VarProxy< int > isCaloMuonId;
      /// Is this muon also reconstructed by the lowPt algorithm?
      VarProxy< int > alsoFoundByLowPt;
      /// Is this muon also reconstructed by a CaloMuon ID algorithm?
      VarProxy< int > alsoFoundByCaloMuonId;
      /// Passes loose quality cuts.
      VarProxy< int > loose;
      /// Passes medium quality cuts.
      VarProxy< int > medium;
      /// Passes tight quality cuts.
      VarProxy< int > tight;
      VarProxy< float > d0_exPV;
      VarProxy< float > z0_exPV;
      VarProxy< float > phi_exPV;
      VarProxy< float > theta_exPV;
      VarProxy< float > qoverp_exPV;
      VarProxy< float > cb_d0_exPV;
      VarProxy< float > cb_z0_exPV;
      VarProxy< float > cb_phi_exPV;
      VarProxy< float > cb_theta_exPV;
      VarProxy< float > cb_qoverp_exPV;
      VarProxy< float > id_d0_exPV;
      VarProxy< float > id_z0_exPV;
      VarProxy< float > id_phi_exPV;
      VarProxy< float > id_theta_exPV;
      VarProxy< float > id_qoverp_exPV;
      VarProxy< float > me_d0_exPV;
      VarProxy< float > me_z0_exPV;
      VarProxy< float > me_phi_exPV;
      VarProxy< float > me_theta_exPV;
      VarProxy< float > me_qoverp_exPV;
      VarProxy< float > ie_d0_exPV;
      VarProxy< float > ie_z0_exPV;
      VarProxy< float > ie_phi_exPV;
      VarProxy< float > ie_theta_exPV;
      VarProxy< float > ie_qoverp_exPV;
      VarProxy< vector<int> > SpaceTime_detID;
      VarProxy< vector<float> > SpaceTime_t;
      VarProxy< vector<float> > SpaceTime_tError;
      VarProxy< vector<float> > SpaceTime_weight;
      VarProxy< vector<float> > SpaceTime_x;
      VarProxy< vector<float> > SpaceTime_y;
      VarProxy< vector<float> > SpaceTime_z;
      VarProxy< float > cov_d0_exPV;
      VarProxy< float > cov_z0_exPV;
      VarProxy< float > cov_phi_exPV;
      VarProxy< float > cov_theta_exPV;
      VarProxy< float > cov_qoverp_exPV;
      VarProxy< float > cov_d0_z0_exPV;
      VarProxy< float > cov_d0_phi_exPV;
      VarProxy< float > cov_d0_theta_exPV;
      VarProxy< float > cov_d0_qoverp_exPV;
      VarProxy< float > cov_z0_phi_exPV;
      VarProxy< float > cov_z0_theta_exPV;
      VarProxy< float > cov_z0_qoverp_exPV;
      VarProxy< float > cov_phi_theta_exPV;
      VarProxy< float > cov_phi_qoverp_exPV;
      VarProxy< float > cov_theta_qoverp_exPV;
      VarProxy< float > id_cov_d0_exPV;
      VarProxy< float > id_cov_z0_exPV;
      VarProxy< float > id_cov_phi_exPV;
      VarProxy< float > id_cov_theta_exPV;
      VarProxy< float > id_cov_qoverp_exPV;
      VarProxy< float > me_cov_d0_exPV;
      VarProxy< float > me_cov_z0_exPV;
      VarProxy< float > me_cov_phi_exPV;
      VarProxy< float > me_cov_theta_exPV;
      VarProxy< float > me_cov_qoverp_exPV;
      VarProxy< float > ms_d0;
      VarProxy< float > ms_z0;
      VarProxy< float > ms_phi;
      VarProxy< float > ms_theta;
      VarProxy< float > ms_qoverp;
      VarProxy< float > id_d0;
      VarProxy< float > id_z0;
      VarProxy< float > id_phi;
      VarProxy< float > id_theta;
      VarProxy< float > id_qoverp;
      VarProxy< float > me_d0;
      VarProxy< float > me_z0;
      VarProxy< float > me_phi;
      VarProxy< float > me_theta;
      VarProxy< float > me_qoverp;
      VarProxy< float > ie_d0;
      VarProxy< float > ie_z0;
      VarProxy< float > ie_phi;
      VarProxy< float > ie_theta;
      VarProxy< float > ie_qoverp;
      VarProxy< int > nOutliersOnTrack;
      VarProxy< int > nBLHits;
      VarProxy< int > nPixHits;
      VarProxy< int > nSCTHits;
      VarProxy< int > nTRTHits;
      VarProxy< int > nTRTHighTHits;
      VarProxy< int > nBLSharedHits;
      VarProxy< int > nPixSharedHits;
      VarProxy< int > nPixHoles;
      VarProxy< int > nSCTSharedHits;
      VarProxy< int > nSCTHoles;
      VarProxy< int > nTRTOutliers;
      VarProxy< int > nTRTHighTOutliers;
      VarProxy< int > nGangedPixels;
      VarProxy< int > nPixelDeadSensors;
      VarProxy< int > nSCTDeadSensors;
      VarProxy< int > nTRTDeadStraws;
      VarProxy< int > expectBLayerHit;
      VarProxy< int > nMDTHits;
      VarProxy< int > nMDTHoles;
      VarProxy< int > nCSCEtaHits;
      VarProxy< int > nCSCEtaHoles;
      VarProxy< int > nCSCPhiHits;
      VarProxy< int > nCSCPhiHoles;
      VarProxy< int > nRPCEtaHits;
      VarProxy< int > nRPCEtaHoles;
      VarProxy< int > nRPCPhiHits;
      VarProxy< int > nRPCPhiHoles;
      VarProxy< int > nTGCEtaHits;
      VarProxy< int > nTGCEtaHoles;
      VarProxy< int > nTGCPhiHits;
      VarProxy< int > nTGCPhiHoles;
      VarProxy< int > nMDTBIHits;
      VarProxy< int > nMDTBMHits;
      VarProxy< int > nMDTBOHits;
      VarProxy< int > nMDTBEEHits;
      VarProxy< int > nMDTBIS78Hits;
      VarProxy< int > nMDTEIHits;
      VarProxy< int > nMDTEMHits;
      VarProxy< int > nMDTEOHits;
      VarProxy< int > nMDTEEHits;
      VarProxy< int > nRPCLayer1EtaHits;
      VarProxy< int > nRPCLayer2EtaHits;
      VarProxy< int > nRPCLayer3EtaHits;
      VarProxy< int > nRPCLayer1PhiHits;
      VarProxy< int > nRPCLayer2PhiHits;
      VarProxy< int > nRPCLayer3PhiHits;
      VarProxy< int > nTGCLayer1EtaHits;
      VarProxy< int > nTGCLayer2EtaHits;
      VarProxy< int > nTGCLayer3EtaHits;
      VarProxy< int > nTGCLayer4EtaHits;
      VarProxy< int > nTGCLayer1PhiHits;
      VarProxy< int > nTGCLayer2PhiHits;
      VarProxy< int > nTGCLayer3PhiHits;
      VarProxy< int > nTGCLayer4PhiHits;
      VarProxy< int > barrelSectors;
      VarProxy< int > endcapSectors;
      VarProxy< float > trackd0;
      VarProxy< float > trackz0;
      VarProxy< float > trackphi;
      VarProxy< float > tracktheta;
      VarProxy< float > trackqoverp;
      VarProxy< float > trackcov_d0;
      VarProxy< float > trackcov_z0;
      VarProxy< float > trackcov_phi;
      VarProxy< float > trackcov_theta;
      VarProxy< float > trackcov_qoverp;
      VarProxy< float > trackcov_d0_z0;
      VarProxy< float > trackcov_d0_phi;
      VarProxy< float > trackcov_d0_theta;
      VarProxy< float > trackcov_d0_qoverp;
      VarProxy< float > trackcov_z0_phi;
      VarProxy< float > trackcov_z0_theta;
      VarProxy< float > trackcov_z0_qoverp;
      VarProxy< float > trackcov_phi_theta;
      VarProxy< float > trackcov_phi_qoverp;
      VarProxy< float > trackcov_theta_qoverp;
      VarProxy< float > trackfitchi2;
      VarProxy< int > trackfitndof;
      VarProxy< int > hastrack;
      VarProxy< float > trackd0beam;
      VarProxy< float > trackz0beam;
      /// Uncertainty on transverse impact parameter.
      VarProxy< float > tracksigd0beam;
      /// Uncertainty on longitudinal impact parameter.
      VarProxy< float > tracksigz0beam;
      VarProxy< float > trackd0pv;
      VarProxy< float > trackz0pv;
      /// Uncertainty on transverse impact parameter.
      VarProxy< float > tracksigd0pv;
      /// Uncertainty on longitudinal impact parameter.
      VarProxy< float > tracksigz0pv;
      VarProxy< float > trackIPEstimate_d0_biasedpvunbiased;
      VarProxy< float > trackIPEstimate_z0_biasedpvunbiased;
      VarProxy< float > trackIPEstimate_sigd0_biasedpvunbiased;
      VarProxy< float > trackIPEstimate_sigz0_biasedpvunbiased;
      VarProxy< float > trackIPEstimate_d0_unbiasedpvunbiased;
      VarProxy< float > trackIPEstimate_z0_unbiasedpvunbiased;
      VarProxy< float > trackIPEstimate_sigd0_unbiasedpvunbiased;
      VarProxy< float > trackIPEstimate_sigz0_unbiasedpvunbiased;
      VarProxy< float > trackd0pvunbiased;
      VarProxy< float > trackz0pvunbiased;
      VarProxy< float > tracksigd0pvunbiased;
      VarProxy< float > tracksigz0pvunbiased;
      VarProxy< float > truth_dr;
      VarProxy< int > truth_matched;
      /// DeltaR between the offline and trigger objects.
      VarProxy< float > EFCB_dr;
      /// Number of ntuple rows.
//       VarProxy< int > EFCB_n;
//       VarProxy< vector<int> > EFCB_MuonType;
//       VarProxy< vector<float> > EFCB_pt;
//       VarProxy< vector<float> > EFCB_eta;
//       VarProxy< vector<float> > EFCB_phi;
//       VarProxy< vector<int> > EFCB_hasCB;
//       VarProxy< int > EFCB_matched;
      /// DeltaR between the offline and trigger objects.
      VarProxy< float > EFMG_dr;
      /// Number of ntuple rows.
//       VarProxy< int > EFMG_n;
//       VarProxy< vector<int> > EFMG_MuonType;
//       VarProxy< vector<float> > EFMG_pt;
//       VarProxy< vector<float> > EFMG_eta;
//       VarProxy< vector<float> > EFMG_phi;
//       VarProxy< vector<int> > EFMG_hasMG;
//       VarProxy< int > EFMG_matched;
      /// DeltaR between the offline and trigger objects.
      VarProxy< float > EFME_dr;
      /// Number of ntuple rows.
//       VarProxy< int > EFME_n;
//       VarProxy< vector<int> > EFME_MuonType;
//       VarProxy< vector<float> > EFME_pt;
//       VarProxy< vector<float> > EFME_eta;
//       VarProxy< vector<float> > EFME_phi;
//       VarProxy< vector<int> > EFME_hasME;
//      VarProxy< int > EFME_matched;
      /// DeltaR between the offline and trigger objects.
      VarProxy< float > L2CB_dr;
      VarProxy< float > L2CB_pt;
      VarProxy< float > L2CB_eta;
      VarProxy< float > L2CB_phi;
      VarProxy< float > L2CB_id_pt;
      VarProxy< float > L2CB_ms_pt;
      VarProxy< int > L2CB_nPixHits;
      VarProxy< int > L2CB_nSCTHits;
      VarProxy< int > L2CB_nTRTHits;
      VarProxy< int > L2CB_nTRTHighTHits;
      VarProxy< int > L2CB_matched;
      /// DeltaR between the offline and trigger objects.
      VarProxy< float > L1_dr;
      VarProxy< float > L1_pt;
      VarProxy< float > L1_eta;
      VarProxy< float > L1_phi;
      /// Number of the highest threshold this RoI passed
      VarProxy< short > L1_thrNumber;
      /// "RoI" (pad) number of the muon candidate
      VarProxy< short > L1_RoINumber;
      /// The encoded "full" sector address
      VarProxy< short > L1_sectorAddress;
      /// True if the candidate had the highest pT in its sector
      VarProxy< int > L1_firstCandidate;
      /// True if there were other muons detected in the same pad
      VarProxy< int > L1_moreCandInRoI;
      /// True if there were >2 muons detected in the same sector
      VarProxy< int > L1_moreCandInSector;
      /// Muon candidate system ID (Barrel=0, Endcap=1, Forward=2)
      VarProxy< short > L1_source;
      /// Hemisphere of the muon candidate (Negative=0, Positive=1)
      VarProxy< short > L1_hemisphere;
      /// Charge of the muon candidate (Negative=0, Positive=1, Undefined=100)
      VarProxy< short > L1_charge;
      /// True if the candidate was vetoed in the multiplicity sum
      VarProxy< int > L1_vetoed;
      VarProxy< int > L1_matched;

      ClassDef( MuonMuidD3PDObjectElement, 0 )

   }; // class MuonMuidD3PDObjectElement

   /**
    * Code generated by CodeGenerator_v2 on:
    *  host = pc-penn-d-05.cern.ch
    *  OS   = Linux / 2.6.18-274.3.1.el5
    *  user = jdegenha
    *  time = Mon Nov  7 10:17:47 2011
    */
   class MuonMuidD3PDObject : public TObject {

   public:
      /// Constructor used when reading from a TTree
      MuonMuidD3PDObject( const ::Long64_t& master, const char* prefix = "mu_muid_" );
      /// Constructor when the object is only used for writing data out
      MuonMuidD3PDObject( const char* prefix = "mu_muid_" );

      /// Get the currently configured prefix value
      const char* GetPrefix() const;
      /// Set the prefix for the variables
      void SetPrefix( const char* prefix );

      /// Connect the object to an input TTree
      void ReadFrom( ::TTree* tree );
      /// Connect the object to an output TTree
      void WriteTo( ::TTree* tree );

      /// Turn (selected) branches either on or off
      void SetActive( ::Bool_t active = kTRUE,
                      const ::TString& pattern = ".*" );
      /// Read in all the variables that we need to write out as well
      void ReadAllActive();

      /// Clear the container. Useful when writing new branches.
      void Clear( Option_t* option = "" );
      /// Add one element to an output collection
      MuonMuidD3PDObject& Add( const MuonMuidD3PDObjectElement& el );

      /// Access a proxy class describing one element of the container
      MuonMuidD3PDObjectElement& operator[]( size_t index );
      /// Access a proxy class describing one element of the container (constant version)
      const MuonMuidD3PDObjectElement& operator[]( size_t index ) const;
      /// Add one element to an output collection
      MuonMuidD3PDObject& operator+=( const MuonMuidD3PDObjectElement& el );

      /// Number of ntuple rows.
      VarHandle< Int_t > n;
      VarHandle< vector<float>* > E;
      VarHandle< vector<float>* > pt;
      VarHandle< vector<float>* > m;
      VarHandle< vector<float>* > eta;
      VarHandle< vector<float>* > phi;
      VarHandle< vector<float>* > px;
      VarHandle< vector<float>* > py;
      VarHandle< vector<float>* > pz;
      VarHandle< vector<float>* > charge;
      VarHandle< vector<unsigned short>* > allauthor;
      VarHandle< vector<int>* > author;
      VarHandle< vector<float>* > beta;
      VarHandle< vector<float>* > isMuonLikelihood;
      VarHandle< vector<float>* > matchchi2;
      VarHandle< vector<int>* > matchndof;
      VarHandle< vector<float>* > etcone20;
      VarHandle< vector<float>* > etcone30;
      VarHandle< vector<float>* > etcone40;
      VarHandle< vector<float>* > nucone20;
      VarHandle< vector<float>* > nucone30;
      VarHandle< vector<float>* > nucone40;
      VarHandle< vector<float>* > ptcone20;
      VarHandle< vector<float>* > ptcone30;
      VarHandle< vector<float>* > ptcone40;
      VarHandle< vector<float>* > energyLossPar;
      VarHandle< vector<float>* > energyLossErr;
      VarHandle< vector<float>* > etCore;
      VarHandle< vector<float>* > energyLossType;
      VarHandle< vector<unsigned short>* > caloMuonIdTag;
      VarHandle< vector<double>* > caloLRLikelihood;
      /// Is this combined track the best match to a MS track?
      VarHandle< vector<int>* > bestMatch;
      /// Muon identified by a spectrometer track (not associated to ID).
      VarHandle< vector<int>* > isStandAloneMuon;
      /// Muon identified by combining an ID and a MS track.
      VarHandle< vector<int>* > isCombinedMuon;
      /// Low-pt reconstructed muon (deprecated).
      VarHandle< vector<int>* > isLowPtReconstructedMuon;
      /// Muon identified by inner-detector seeded identification (segment tagging or ID+MS refit).
      VarHandle< vector<int>* > isSegmentTaggedMuon;
      /// Muon identified solely from calorimeter information (so no signal in MS).
      VarHandle< vector<int>* > isCaloMuonId;
      /// Is this muon also reconstructed by the lowPt algorithm?
      VarHandle< vector<int>* > alsoFoundByLowPt;
      /// Is this muon also reconstructed by a CaloMuon ID algorithm?
      VarHandle< vector<int>* > alsoFoundByCaloMuonId;
      /// Passes loose quality cuts.
      VarHandle< vector<int>* > loose;
      /// Passes medium quality cuts.
      VarHandle< vector<int>* > medium;
      /// Passes tight quality cuts.
      VarHandle< vector<int>* > tight;
      VarHandle< vector<float>* > d0_exPV;
      VarHandle< vector<float>* > z0_exPV;
      VarHandle< vector<float>* > phi_exPV;
      VarHandle< vector<float>* > theta_exPV;
      VarHandle< vector<float>* > qoverp_exPV;
      VarHandle< vector<float>* > cb_d0_exPV;
      VarHandle< vector<float>* > cb_z0_exPV;
      VarHandle< vector<float>* > cb_phi_exPV;
      VarHandle< vector<float>* > cb_theta_exPV;
      VarHandle< vector<float>* > cb_qoverp_exPV;
      VarHandle< vector<float>* > id_d0_exPV;
      VarHandle< vector<float>* > id_z0_exPV;
      VarHandle< vector<float>* > id_phi_exPV;
      VarHandle< vector<float>* > id_theta_exPV;
      VarHandle< vector<float>* > id_qoverp_exPV;
      VarHandle< vector<float>* > me_d0_exPV;
      VarHandle< vector<float>* > me_z0_exPV;
      VarHandle< vector<float>* > me_phi_exPV;
      VarHandle< vector<float>* > me_theta_exPV;
      VarHandle< vector<float>* > me_qoverp_exPV;
      VarHandle< vector<float>* > ie_d0_exPV;
      VarHandle< vector<float>* > ie_z0_exPV;
      VarHandle< vector<float>* > ie_phi_exPV;
      VarHandle< vector<float>* > ie_theta_exPV;
      VarHandle< vector<float>* > ie_qoverp_exPV;
      VarHandle< vector<vector<int> >* > SpaceTime_detID;
      VarHandle< vector<vector<float> >* > SpaceTime_t;
      VarHandle< vector<vector<float> >* > SpaceTime_tError;
      VarHandle< vector<vector<float> >* > SpaceTime_weight;
      VarHandle< vector<vector<float> >* > SpaceTime_x;
      VarHandle< vector<vector<float> >* > SpaceTime_y;
      VarHandle< vector<vector<float> >* > SpaceTime_z;
      VarHandle< vector<float>* > cov_d0_exPV;
      VarHandle< vector<float>* > cov_z0_exPV;
      VarHandle< vector<float>* > cov_phi_exPV;
      VarHandle< vector<float>* > cov_theta_exPV;
      VarHandle< vector<float>* > cov_qoverp_exPV;
      VarHandle< vector<float>* > cov_d0_z0_exPV;
      VarHandle< vector<float>* > cov_d0_phi_exPV;
      VarHandle< vector<float>* > cov_d0_theta_exPV;
      VarHandle< vector<float>* > cov_d0_qoverp_exPV;
      VarHandle< vector<float>* > cov_z0_phi_exPV;
      VarHandle< vector<float>* > cov_z0_theta_exPV;
      VarHandle< vector<float>* > cov_z0_qoverp_exPV;
      VarHandle< vector<float>* > cov_phi_theta_exPV;
      VarHandle< vector<float>* > cov_phi_qoverp_exPV;
      VarHandle< vector<float>* > cov_theta_qoverp_exPV;
      VarHandle< vector<float>* > id_cov_d0_exPV;
      VarHandle< vector<float>* > id_cov_z0_exPV;
      VarHandle< vector<float>* > id_cov_phi_exPV;
      VarHandle< vector<float>* > id_cov_theta_exPV;
      VarHandle< vector<float>* > id_cov_qoverp_exPV;
      VarHandle< vector<float>* > me_cov_d0_exPV;
      VarHandle< vector<float>* > me_cov_z0_exPV;
      VarHandle< vector<float>* > me_cov_phi_exPV;
      VarHandle< vector<float>* > me_cov_theta_exPV;
      VarHandle< vector<float>* > me_cov_qoverp_exPV;
      VarHandle< vector<float>* > ms_d0;
      VarHandle< vector<float>* > ms_z0;
      VarHandle< vector<float>* > ms_phi;
      VarHandle< vector<float>* > ms_theta;
      VarHandle< vector<float>* > ms_qoverp;
      VarHandle< vector<float>* > id_d0;
      VarHandle< vector<float>* > id_z0;
      VarHandle< vector<float>* > id_phi;
      VarHandle< vector<float>* > id_theta;
      VarHandle< vector<float>* > id_qoverp;
      VarHandle< vector<float>* > me_d0;
      VarHandle< vector<float>* > me_z0;
      VarHandle< vector<float>* > me_phi;
      VarHandle< vector<float>* > me_theta;
      VarHandle< vector<float>* > me_qoverp;
      VarHandle< vector<float>* > ie_d0;
      VarHandle< vector<float>* > ie_z0;
      VarHandle< vector<float>* > ie_phi;
      VarHandle< vector<float>* > ie_theta;
      VarHandle< vector<float>* > ie_qoverp;
      VarHandle< vector<int>* > nOutliersOnTrack;
      VarHandle< vector<int>* > nBLHits;
      VarHandle< vector<int>* > nPixHits;
      VarHandle< vector<int>* > nSCTHits;
      VarHandle< vector<int>* > nTRTHits;
      VarHandle< vector<int>* > nTRTHighTHits;
      VarHandle< vector<int>* > nBLSharedHits;
      VarHandle< vector<int>* > nPixSharedHits;
      VarHandle< vector<int>* > nPixHoles;
      VarHandle< vector<int>* > nSCTSharedHits;
      VarHandle< vector<int>* > nSCTHoles;
      VarHandle< vector<int>* > nTRTOutliers;
      VarHandle< vector<int>* > nTRTHighTOutliers;
      VarHandle< vector<int>* > nGangedPixels;
      VarHandle< vector<int>* > nPixelDeadSensors;
      VarHandle< vector<int>* > nSCTDeadSensors;
      VarHandle< vector<int>* > nTRTDeadStraws;
      VarHandle< vector<int>* > expectBLayerHit;
      VarHandle< vector<int>* > nMDTHits;
      VarHandle< vector<int>* > nMDTHoles;
      VarHandle< vector<int>* > nCSCEtaHits;
      VarHandle< vector<int>* > nCSCEtaHoles;
      VarHandle< vector<int>* > nCSCPhiHits;
      VarHandle< vector<int>* > nCSCPhiHoles;
      VarHandle< vector<int>* > nRPCEtaHits;
      VarHandle< vector<int>* > nRPCEtaHoles;
      VarHandle< vector<int>* > nRPCPhiHits;
      VarHandle< vector<int>* > nRPCPhiHoles;
      VarHandle< vector<int>* > nTGCEtaHits;
      VarHandle< vector<int>* > nTGCEtaHoles;
      VarHandle< vector<int>* > nTGCPhiHits;
      VarHandle< vector<int>* > nTGCPhiHoles;
      VarHandle< vector<int>* > nMDTBIHits;
      VarHandle< vector<int>* > nMDTBMHits;
      VarHandle< vector<int>* > nMDTBOHits;
      VarHandle< vector<int>* > nMDTBEEHits;
      VarHandle< vector<int>* > nMDTBIS78Hits;
      VarHandle< vector<int>* > nMDTEIHits;
      VarHandle< vector<int>* > nMDTEMHits;
      VarHandle< vector<int>* > nMDTEOHits;
      VarHandle< vector<int>* > nMDTEEHits;
      VarHandle< vector<int>* > nRPCLayer1EtaHits;
      VarHandle< vector<int>* > nRPCLayer2EtaHits;
      VarHandle< vector<int>* > nRPCLayer3EtaHits;
      VarHandle< vector<int>* > nRPCLayer1PhiHits;
      VarHandle< vector<int>* > nRPCLayer2PhiHits;
      VarHandle< vector<int>* > nRPCLayer3PhiHits;
      VarHandle< vector<int>* > nTGCLayer1EtaHits;
      VarHandle< vector<int>* > nTGCLayer2EtaHits;
      VarHandle< vector<int>* > nTGCLayer3EtaHits;
      VarHandle< vector<int>* > nTGCLayer4EtaHits;
      VarHandle< vector<int>* > nTGCLayer1PhiHits;
      VarHandle< vector<int>* > nTGCLayer2PhiHits;
      VarHandle< vector<int>* > nTGCLayer3PhiHits;
      VarHandle< vector<int>* > nTGCLayer4PhiHits;
      VarHandle< vector<int>* > barrelSectors;
      VarHandle< vector<int>* > endcapSectors;
      VarHandle< vector<float>* > trackd0;
      VarHandle< vector<float>* > trackz0;
      VarHandle< vector<float>* > trackphi;
      VarHandle< vector<float>* > tracktheta;
      VarHandle< vector<float>* > trackqoverp;
      VarHandle< vector<float>* > trackcov_d0;
      VarHandle< vector<float>* > trackcov_z0;
      VarHandle< vector<float>* > trackcov_phi;
      VarHandle< vector<float>* > trackcov_theta;
      VarHandle< vector<float>* > trackcov_qoverp;
      VarHandle< vector<float>* > trackcov_d0_z0;
      VarHandle< vector<float>* > trackcov_d0_phi;
      VarHandle< vector<float>* > trackcov_d0_theta;
      VarHandle< vector<float>* > trackcov_d0_qoverp;
      VarHandle< vector<float>* > trackcov_z0_phi;
      VarHandle< vector<float>* > trackcov_z0_theta;
      VarHandle< vector<float>* > trackcov_z0_qoverp;
      VarHandle< vector<float>* > trackcov_phi_theta;
      VarHandle< vector<float>* > trackcov_phi_qoverp;
      VarHandle< vector<float>* > trackcov_theta_qoverp;
      VarHandle< vector<float>* > trackfitchi2;
      VarHandle< vector<int>* > trackfitndof;
      VarHandle< vector<int>* > hastrack;
      VarHandle< vector<float>* > trackd0beam;
      VarHandle< vector<float>* > trackz0beam;
      /// Uncertainty on transverse impact parameter.
      VarHandle< vector<float>* > tracksigd0beam;
      /// Uncertainty on longitudinal impact parameter.
      VarHandle< vector<float>* > tracksigz0beam;
      VarHandle< vector<float>* > trackd0pv;
      VarHandle< vector<float>* > trackz0pv;
      /// Uncertainty on transverse impact parameter.
      VarHandle< vector<float>* > tracksigd0pv;
      /// Uncertainty on longitudinal impact parameter.
      VarHandle< vector<float>* > tracksigz0pv;
      VarHandle< vector<float>* > trackIPEstimate_d0_biasedpvunbiased;
      VarHandle< vector<float>* > trackIPEstimate_z0_biasedpvunbiased;
      VarHandle< vector<float>* > trackIPEstimate_sigd0_biasedpvunbiased;
      VarHandle< vector<float>* > trackIPEstimate_sigz0_biasedpvunbiased;
      VarHandle< vector<float>* > trackIPEstimate_d0_unbiasedpvunbiased;
      VarHandle< vector<float>* > trackIPEstimate_z0_unbiasedpvunbiased;
      VarHandle< vector<float>* > trackIPEstimate_sigd0_unbiasedpvunbiased;
      VarHandle< vector<float>* > trackIPEstimate_sigz0_unbiasedpvunbiased;
      VarHandle< vector<float>* > trackd0pvunbiased;
      VarHandle< vector<float>* > trackz0pvunbiased;
      VarHandle< vector<float>* > tracksigd0pvunbiased;
      VarHandle< vector<float>* > tracksigz0pvunbiased;
      VarHandle< vector<float>* > truth_dr;
      VarHandle< vector<int>* > truth_matched;
      /// DeltaR between the offline and trigger objects.
      VarHandle< vector<float>* > EFCB_dr;
      /// Number of ntuple rows.
//       VarHandle< vector<int>* > EFCB_n;
//       VarHandle< vector<vector<int> >* > EFCB_MuonType;
//       VarHandle< vector<vector<float> >* > EFCB_pt;
//       VarHandle< vector<vector<float> >* > EFCB_eta;
//       VarHandle< vector<vector<float> >* > EFCB_phi;
//       VarHandle< vector<vector<int> >* > EFCB_hasCB;
//       VarHandle< vector<int>* > EFCB_matched;
      /// DeltaR between the offline and trigger objects.
      VarHandle< vector<float>* > EFMG_dr;
      /// Number of ntuple rows.
//       VarHandle< vector<int>* > EFMG_n;
//       VarHandle< vector<vector<int> >* > EFMG_MuonType;
//       VarHandle< vector<vector<float> >* > EFMG_pt;
//       VarHandle< vector<vector<float> >* > EFMG_eta;
//       VarHandle< vector<vector<float> >* > EFMG_phi;
//       VarHandle< vector<vector<int> >* > EFMG_hasMG;
//       VarHandle< vector<int>* > EFMG_matched;
      /// DeltaR between the offline and trigger objects.
      VarHandle< vector<float>* > EFME_dr;
      /// Number of ntuple rows.
//       VarHandle< vector<int>* > EFME_n;
//       VarHandle< vector<vector<int> >* > EFME_MuonType;
//       VarHandle< vector<vector<float> >* > EFME_pt;
//       VarHandle< vector<vector<float> >* > EFME_eta;
//       VarHandle< vector<vector<float> >* > EFME_phi;
//       VarHandle< vector<vector<int> >* > EFME_hasME;
//       VarHandle< vector<int>* > EFME_matched;
      /// DeltaR between the offline and trigger objects.
      VarHandle< vector<float>* > L2CB_dr;
      VarHandle< vector<float>* > L2CB_pt;
      VarHandle< vector<float>* > L2CB_eta;
      VarHandle< vector<float>* > L2CB_phi;
      VarHandle< vector<float>* > L2CB_id_pt;
      VarHandle< vector<float>* > L2CB_ms_pt;
      VarHandle< vector<int>* > L2CB_nPixHits;
      VarHandle< vector<int>* > L2CB_nSCTHits;
      VarHandle< vector<int>* > L2CB_nTRTHits;
      VarHandle< vector<int>* > L2CB_nTRTHighTHits;
      VarHandle< vector<int>* > L2CB_matched;
      /// DeltaR between the offline and trigger objects.
      VarHandle< vector<float>* > L1_dr;
      VarHandle< vector<float>* > L1_pt;
      VarHandle< vector<float>* > L1_eta;
      VarHandle< vector<float>* > L1_phi;
      /// Number of the highest threshold this RoI passed
      VarHandle< vector<short>* > L1_thrNumber;
      /// "RoI" (pad) number of the muon candidate
      VarHandle< vector<short>* > L1_RoINumber;
      /// The encoded "full" sector address
      VarHandle< vector<short>* > L1_sectorAddress;
      /// True if the candidate had the highest pT in its sector
      VarHandle< vector<int>* > L1_firstCandidate;
      /// True if there were other muons detected in the same pad
      VarHandle< vector<int>* > L1_moreCandInRoI;
      /// True if there were >2 muons detected in the same sector
      VarHandle< vector<int>* > L1_moreCandInSector;
      /// Muon candidate system ID (Barrel=0, Endcap=1, Forward=2)
      VarHandle< vector<short>* > L1_source;
      /// Hemisphere of the muon candidate (Negative=0, Positive=1)
      VarHandle< vector<short>* > L1_hemisphere;
      /// Charge of the muon candidate (Negative=0, Positive=1, Undefined=100)
      VarHandle< vector<short>* > L1_charge;
      /// True if the candidate was vetoed in the multiplicity sum
      VarHandle< vector<int>* > L1_vetoed;
      VarHandle< vector<int>* > L1_matched;

   private:
      mutable std::vector< MuonMuidD3PDObjectElement > fProxies; ///< Internal list of proxy objects
      std::map< ::TString, VarHandleBase* > fHandles; ///< Book-keeper of the VarHandle members
      const ::Bool_t fFromInput; ///< Flag specifying if object is used for D3PD reading
      const ::TString fPrefix; ///< Prefix to the branch names

      ClassDef( MuonMuidD3PDObject, 0 )

   }; // class MuonMuidD3PDObject

} // namespace D3PDReader

#endif // D3PDREADER_MuonMuidD3PDObject_H
