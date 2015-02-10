// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/MuonMuidD3PDObject.h"

ClassImp( D3PDReader::MuonMuidD3PDObjectElement )
ClassImp( D3PDReader::MuonMuidD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class MuonMuidD3PDObject.
    */
   MuonMuidD3PDObjectElement::MuonMuidD3PDObjectElement( size_t index, const MuonMuidD3PDObject& parent )
      : E( parent.E, index, this ),
        pt( parent.pt, index, this ),
        m( parent.m, index, this ),
        eta( parent.eta, index, this ),
        phi( parent.phi, index, this ),
        px( parent.px, index, this ),
        py( parent.py, index, this ),
        pz( parent.pz, index, this ),
        charge( parent.charge, index, this ),
        allauthor( parent.allauthor, index, this ),
        author( parent.author, index, this ),
        beta( parent.beta, index, this ),
        isMuonLikelihood( parent.isMuonLikelihood, index, this ),
        matchchi2( parent.matchchi2, index, this ),
        matchndof( parent.matchndof, index, this ),
        etcone20( parent.etcone20, index, this ),
        etcone30( parent.etcone30, index, this ),
        etcone40( parent.etcone40, index, this ),
        nucone20( parent.nucone20, index, this ),
        nucone30( parent.nucone30, index, this ),
        nucone40( parent.nucone40, index, this ),
        ptcone20( parent.ptcone20, index, this ),
        ptcone30( parent.ptcone30, index, this ),
        ptcone40( parent.ptcone40, index, this ),
        energyLossPar( parent.energyLossPar, index, this ),
        energyLossErr( parent.energyLossErr, index, this ),
        etCore( parent.etCore, index, this ),
        energyLossType( parent.energyLossType, index, this ),
        caloMuonIdTag( parent.caloMuonIdTag, index, this ),
        caloLRLikelihood( parent.caloLRLikelihood, index, this ),
        bestMatch( parent.bestMatch, index, this ),
        isStandAloneMuon( parent.isStandAloneMuon, index, this ),
        isCombinedMuon( parent.isCombinedMuon, index, this ),
        isLowPtReconstructedMuon( parent.isLowPtReconstructedMuon, index, this ),
        isSegmentTaggedMuon( parent.isSegmentTaggedMuon, index, this ),
        isCaloMuonId( parent.isCaloMuonId, index, this ),
        alsoFoundByLowPt( parent.alsoFoundByLowPt, index, this ),
        alsoFoundByCaloMuonId( parent.alsoFoundByCaloMuonId, index, this ),
        loose( parent.loose, index, this ),
        medium( parent.medium, index, this ),
        tight( parent.tight, index, this ),
        d0_exPV( parent.d0_exPV, index, this ),
        z0_exPV( parent.z0_exPV, index, this ),
        phi_exPV( parent.phi_exPV, index, this ),
        theta_exPV( parent.theta_exPV, index, this ),
        qoverp_exPV( parent.qoverp_exPV, index, this ),
        cb_d0_exPV( parent.cb_d0_exPV, index, this ),
        cb_z0_exPV( parent.cb_z0_exPV, index, this ),
        cb_phi_exPV( parent.cb_phi_exPV, index, this ),
        cb_theta_exPV( parent.cb_theta_exPV, index, this ),
        cb_qoverp_exPV( parent.cb_qoverp_exPV, index, this ),
        id_d0_exPV( parent.id_d0_exPV, index, this ),
        id_z0_exPV( parent.id_z0_exPV, index, this ),
        id_phi_exPV( parent.id_phi_exPV, index, this ),
        id_theta_exPV( parent.id_theta_exPV, index, this ),
        id_qoverp_exPV( parent.id_qoverp_exPV, index, this ),
        me_d0_exPV( parent.me_d0_exPV, index, this ),
        me_z0_exPV( parent.me_z0_exPV, index, this ),
        me_phi_exPV( parent.me_phi_exPV, index, this ),
        me_theta_exPV( parent.me_theta_exPV, index, this ),
        me_qoverp_exPV( parent.me_qoverp_exPV, index, this ),
        ie_d0_exPV( parent.ie_d0_exPV, index, this ),
        ie_z0_exPV( parent.ie_z0_exPV, index, this ),
        ie_phi_exPV( parent.ie_phi_exPV, index, this ),
        ie_theta_exPV( parent.ie_theta_exPV, index, this ),
        ie_qoverp_exPV( parent.ie_qoverp_exPV, index, this ),
        SpaceTime_detID( parent.SpaceTime_detID, index, this ),
        SpaceTime_t( parent.SpaceTime_t, index, this ),
        SpaceTime_tError( parent.SpaceTime_tError, index, this ),
        SpaceTime_weight( parent.SpaceTime_weight, index, this ),
        SpaceTime_x( parent.SpaceTime_x, index, this ),
        SpaceTime_y( parent.SpaceTime_y, index, this ),
        SpaceTime_z( parent.SpaceTime_z, index, this ),
        cov_d0_exPV( parent.cov_d0_exPV, index, this ),
        cov_z0_exPV( parent.cov_z0_exPV, index, this ),
        cov_phi_exPV( parent.cov_phi_exPV, index, this ),
        cov_theta_exPV( parent.cov_theta_exPV, index, this ),
        cov_qoverp_exPV( parent.cov_qoverp_exPV, index, this ),
        cov_d0_z0_exPV( parent.cov_d0_z0_exPV, index, this ),
        cov_d0_phi_exPV( parent.cov_d0_phi_exPV, index, this ),
        cov_d0_theta_exPV( parent.cov_d0_theta_exPV, index, this ),
        cov_d0_qoverp_exPV( parent.cov_d0_qoverp_exPV, index, this ),
        cov_z0_phi_exPV( parent.cov_z0_phi_exPV, index, this ),
        cov_z0_theta_exPV( parent.cov_z0_theta_exPV, index, this ),
        cov_z0_qoverp_exPV( parent.cov_z0_qoverp_exPV, index, this ),
        cov_phi_theta_exPV( parent.cov_phi_theta_exPV, index, this ),
        cov_phi_qoverp_exPV( parent.cov_phi_qoverp_exPV, index, this ),
        cov_theta_qoverp_exPV( parent.cov_theta_qoverp_exPV, index, this ),
        id_cov_d0_exPV( parent.id_cov_d0_exPV, index, this ),
        id_cov_z0_exPV( parent.id_cov_z0_exPV, index, this ),
        id_cov_phi_exPV( parent.id_cov_phi_exPV, index, this ),
        id_cov_theta_exPV( parent.id_cov_theta_exPV, index, this ),
        id_cov_qoverp_exPV( parent.id_cov_qoverp_exPV, index, this ),
        me_cov_d0_exPV( parent.me_cov_d0_exPV, index, this ),
        me_cov_z0_exPV( parent.me_cov_z0_exPV, index, this ),
        me_cov_phi_exPV( parent.me_cov_phi_exPV, index, this ),
        me_cov_theta_exPV( parent.me_cov_theta_exPV, index, this ),
        me_cov_qoverp_exPV( parent.me_cov_qoverp_exPV, index, this ),
        ms_d0( parent.ms_d0, index, this ),
        ms_z0( parent.ms_z0, index, this ),
        ms_phi( parent.ms_phi, index, this ),
        ms_theta( parent.ms_theta, index, this ),
        ms_qoverp( parent.ms_qoverp, index, this ),
        id_d0( parent.id_d0, index, this ),
        id_z0( parent.id_z0, index, this ),
        id_phi( parent.id_phi, index, this ),
        id_theta( parent.id_theta, index, this ),
        id_qoverp( parent.id_qoverp, index, this ),
        me_d0( parent.me_d0, index, this ),
        me_z0( parent.me_z0, index, this ),
        me_phi( parent.me_phi, index, this ),
        me_theta( parent.me_theta, index, this ),
        me_qoverp( parent.me_qoverp, index, this ),
        ie_d0( parent.ie_d0, index, this ),
        ie_z0( parent.ie_z0, index, this ),
        ie_phi( parent.ie_phi, index, this ),
        ie_theta( parent.ie_theta, index, this ),
        ie_qoverp( parent.ie_qoverp, index, this ),
        nOutliersOnTrack( parent.nOutliersOnTrack, index, this ),
        nBLHits( parent.nBLHits, index, this ),
        nPixHits( parent.nPixHits, index, this ),
        nSCTHits( parent.nSCTHits, index, this ),
        nTRTHits( parent.nTRTHits, index, this ),
        nTRTHighTHits( parent.nTRTHighTHits, index, this ),
        nBLSharedHits( parent.nBLSharedHits, index, this ),
        nPixSharedHits( parent.nPixSharedHits, index, this ),
        nPixHoles( parent.nPixHoles, index, this ),
        nSCTSharedHits( parent.nSCTSharedHits, index, this ),
        nSCTHoles( parent.nSCTHoles, index, this ),
        nTRTOutliers( parent.nTRTOutliers, index, this ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers, index, this ),
        nGangedPixels( parent.nGangedPixels, index, this ),
        nPixelDeadSensors( parent.nPixelDeadSensors, index, this ),
        nSCTDeadSensors( parent.nSCTDeadSensors, index, this ),
        nTRTDeadStraws( parent.nTRTDeadStraws, index, this ),
        expectBLayerHit( parent.expectBLayerHit, index, this ),
        nMDTHits( parent.nMDTHits, index, this ),
        nMDTHoles( parent.nMDTHoles, index, this ),
        nCSCEtaHits( parent.nCSCEtaHits, index, this ),
        nCSCEtaHoles( parent.nCSCEtaHoles, index, this ),
        nCSCPhiHits( parent.nCSCPhiHits, index, this ),
        nCSCPhiHoles( parent.nCSCPhiHoles, index, this ),
        nRPCEtaHits( parent.nRPCEtaHits, index, this ),
        nRPCEtaHoles( parent.nRPCEtaHoles, index, this ),
        nRPCPhiHits( parent.nRPCPhiHits, index, this ),
        nRPCPhiHoles( parent.nRPCPhiHoles, index, this ),
        nTGCEtaHits( parent.nTGCEtaHits, index, this ),
        nTGCEtaHoles( parent.nTGCEtaHoles, index, this ),
        nTGCPhiHits( parent.nTGCPhiHits, index, this ),
        nTGCPhiHoles( parent.nTGCPhiHoles, index, this ),
        nMDTBIHits( parent.nMDTBIHits, index, this ),
        nMDTBMHits( parent.nMDTBMHits, index, this ),
        nMDTBOHits( parent.nMDTBOHits, index, this ),
        nMDTBEEHits( parent.nMDTBEEHits, index, this ),
        nMDTBIS78Hits( parent.nMDTBIS78Hits, index, this ),
        nMDTEIHits( parent.nMDTEIHits, index, this ),
        nMDTEMHits( parent.nMDTEMHits, index, this ),
        nMDTEOHits( parent.nMDTEOHits, index, this ),
        nMDTEEHits( parent.nMDTEEHits, index, this ),
        nRPCLayer1EtaHits( parent.nRPCLayer1EtaHits, index, this ),
        nRPCLayer2EtaHits( parent.nRPCLayer2EtaHits, index, this ),
        nRPCLayer3EtaHits( parent.nRPCLayer3EtaHits, index, this ),
        nRPCLayer1PhiHits( parent.nRPCLayer1PhiHits, index, this ),
        nRPCLayer2PhiHits( parent.nRPCLayer2PhiHits, index, this ),
        nRPCLayer3PhiHits( parent.nRPCLayer3PhiHits, index, this ),
        nTGCLayer1EtaHits( parent.nTGCLayer1EtaHits, index, this ),
        nTGCLayer2EtaHits( parent.nTGCLayer2EtaHits, index, this ),
        nTGCLayer3EtaHits( parent.nTGCLayer3EtaHits, index, this ),
        nTGCLayer4EtaHits( parent.nTGCLayer4EtaHits, index, this ),
        nTGCLayer1PhiHits( parent.nTGCLayer1PhiHits, index, this ),
        nTGCLayer2PhiHits( parent.nTGCLayer2PhiHits, index, this ),
        nTGCLayer3PhiHits( parent.nTGCLayer3PhiHits, index, this ),
        nTGCLayer4PhiHits( parent.nTGCLayer4PhiHits, index, this ),
        barrelSectors( parent.barrelSectors, index, this ),
        endcapSectors( parent.endcapSectors, index, this ),
        trackd0( parent.trackd0, index, this ),
        trackz0( parent.trackz0, index, this ),
        trackphi( parent.trackphi, index, this ),
        tracktheta( parent.tracktheta, index, this ),
        trackqoverp( parent.trackqoverp, index, this ),
        trackcov_d0( parent.trackcov_d0, index, this ),
        trackcov_z0( parent.trackcov_z0, index, this ),
        trackcov_phi( parent.trackcov_phi, index, this ),
        trackcov_theta( parent.trackcov_theta, index, this ),
        trackcov_qoverp( parent.trackcov_qoverp, index, this ),
        trackcov_d0_z0( parent.trackcov_d0_z0, index, this ),
        trackcov_d0_phi( parent.trackcov_d0_phi, index, this ),
        trackcov_d0_theta( parent.trackcov_d0_theta, index, this ),
        trackcov_d0_qoverp( parent.trackcov_d0_qoverp, index, this ),
        trackcov_z0_phi( parent.trackcov_z0_phi, index, this ),
        trackcov_z0_theta( parent.trackcov_z0_theta, index, this ),
        trackcov_z0_qoverp( parent.trackcov_z0_qoverp, index, this ),
        trackcov_phi_theta( parent.trackcov_phi_theta, index, this ),
        trackcov_phi_qoverp( parent.trackcov_phi_qoverp, index, this ),
        trackcov_theta_qoverp( parent.trackcov_theta_qoverp, index, this ),
        trackfitchi2( parent.trackfitchi2, index, this ),
        trackfitndof( parent.trackfitndof, index, this ),
        hastrack( parent.hastrack, index, this ),
        trackd0beam( parent.trackd0beam, index, this ),
        trackz0beam( parent.trackz0beam, index, this ),
        tracksigd0beam( parent.tracksigd0beam, index, this ),
        tracksigz0beam( parent.tracksigz0beam, index, this ),
        trackd0pv( parent.trackd0pv, index, this ),
        trackz0pv( parent.trackz0pv, index, this ),
        tracksigd0pv( parent.tracksigd0pv, index, this ),
        tracksigz0pv( parent.tracksigz0pv, index, this ),
        trackIPEstimate_d0_biasedpvunbiased( parent.trackIPEstimate_d0_biasedpvunbiased, index, this ),
        trackIPEstimate_z0_biasedpvunbiased( parent.trackIPEstimate_z0_biasedpvunbiased, index, this ),
        trackIPEstimate_sigd0_biasedpvunbiased( parent.trackIPEstimate_sigd0_biasedpvunbiased, index, this ),
        trackIPEstimate_sigz0_biasedpvunbiased( parent.trackIPEstimate_sigz0_biasedpvunbiased, index, this ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased, index, this ),
        trackd0pvunbiased( parent.trackd0pvunbiased, index, this ),
        trackz0pvunbiased( parent.trackz0pvunbiased, index, this ),
        tracksigd0pvunbiased( parent.tracksigd0pvunbiased, index, this ),
        tracksigz0pvunbiased( parent.tracksigz0pvunbiased, index, this ),
        truth_dr( parent.truth_dr, index, this ),
        truth_matched( parent.truth_matched, index, this ),
	EFCB_dr( parent.EFCB_dr, index, this ),
	//        EFCB_n( parent.EFCB_n, index, this ),
	//        EFCB_MuonType( parent.EFCB_MuonType, index, this ),
	//        EFCB_pt( parent.EFCB_pt, index, this ),
	//        EFCB_eta( parent.EFCB_eta, index, this ),
	//        EFCB_phi( parent.EFCB_phi, index, this ),
	//        EFCB_hasCB( parent.EFCB_hasCB, index, this ),
	//        EFCB_matched( parent.EFCB_matched, index, this ),
        EFMG_dr( parent.EFMG_dr, index, this ),
	//        EFMG_n( parent.EFMG_n, index, this ),
	//        EFMG_MuonType( parent.EFMG_MuonType, index, this ),
	//        EFMG_pt( parent.EFMG_pt, index, this ),
	//        EFMG_eta( parent.EFMG_eta, index, this ),
	//        EFMG_phi( parent.EFMG_phi, index, this ),
	//        EFMG_hasMG( parent.EFMG_hasMG, index, this ),
	//        EFMG_matched( parent.EFMG_matched, index, this ),
	EFME_dr( parent.EFME_dr, index, this ),
	//        EFME_n( parent.EFME_n, index, this ),
	//        EFME_MuonType( parent.EFME_MuonType, index, this ),
	//        EFME_pt( parent.EFME_pt, index, this ),
	//        EFME_eta( parent.EFME_eta, index, this ),
	//        EFME_phi( parent.EFME_phi, index, this ),
	//        EFME_hasME( parent.EFME_hasME, index, this ),
	//        EFME_matched( parent.EFME_matched, index, this ),
	L2CB_dr( parent.L2CB_dr, index, this ),
        L2CB_pt( parent.L2CB_pt, index, this ),
        L2CB_eta( parent.L2CB_eta, index, this ),
        L2CB_phi( parent.L2CB_phi, index, this ),
        L2CB_id_pt( parent.L2CB_id_pt, index, this ),
        L2CB_ms_pt( parent.L2CB_ms_pt, index, this ),
        L2CB_nPixHits( parent.L2CB_nPixHits, index, this ),
        L2CB_nSCTHits( parent.L2CB_nSCTHits, index, this ),
        L2CB_nTRTHits( parent.L2CB_nTRTHits, index, this ),
        L2CB_nTRTHighTHits( parent.L2CB_nTRTHighTHits, index, this ),
        L2CB_matched( parent.L2CB_matched, index, this ),
        L1_dr( parent.L1_dr, index, this ),
        L1_pt( parent.L1_pt, index, this ),
        L1_eta( parent.L1_eta, index, this ),
        L1_phi( parent.L1_phi, index, this ),
        L1_thrNumber( parent.L1_thrNumber, index, this ),
        L1_RoINumber( parent.L1_RoINumber, index, this ),
        L1_sectorAddress( parent.L1_sectorAddress, index, this ),
        L1_firstCandidate( parent.L1_firstCandidate, index, this ),
        L1_moreCandInRoI( parent.L1_moreCandInRoI, index, this ),
        L1_moreCandInSector( parent.L1_moreCandInSector, index, this ),
        L1_source( parent.L1_source, index, this ),
        L1_hemisphere( parent.L1_hemisphere, index, this ),
        L1_charge( parent.L1_charge, index, this ),
        L1_vetoed( parent.L1_vetoed, index, this ),
        L1_matched( parent.L1_matched, index, this ) {

   }

   /**
    * This constructor is useful for creating copies of proxy objects.
    * Such objects are fairly cheap to copy, so the user is allowed to have
    * his/her containers of them inside an analysis code. (To select and
    * sort objects according to some criteria for instance.)
    *
    * @param parent The proxy object that should be copied
    */
   MuonMuidD3PDObjectElement::MuonMuidD3PDObjectElement( const MuonMuidD3PDObjectElement& parent )
      : TObject( parent ),
        E( parent.E ),
        pt( parent.pt ),
        m( parent.m ),
        eta( parent.eta ),
        phi( parent.phi ),
        px( parent.px ),
        py( parent.py ),
        pz( parent.pz ),
        charge( parent.charge ),
        allauthor( parent.allauthor ),
        author( parent.author ),
        beta( parent.beta ),
        isMuonLikelihood( parent.isMuonLikelihood ),
        matchchi2( parent.matchchi2 ),
        matchndof( parent.matchndof ),
        etcone20( parent.etcone20 ),
        etcone30( parent.etcone30 ),
        etcone40( parent.etcone40 ),
        nucone20( parent.nucone20 ),
        nucone30( parent.nucone30 ),
        nucone40( parent.nucone40 ),
        ptcone20( parent.ptcone20 ),
        ptcone30( parent.ptcone30 ),
        ptcone40( parent.ptcone40 ),
        energyLossPar( parent.energyLossPar ),
        energyLossErr( parent.energyLossErr ),
        etCore( parent.etCore ),
        energyLossType( parent.energyLossType ),
        caloMuonIdTag( parent.caloMuonIdTag ),
        caloLRLikelihood( parent.caloLRLikelihood ),
        bestMatch( parent.bestMatch ),
        isStandAloneMuon( parent.isStandAloneMuon ),
        isCombinedMuon( parent.isCombinedMuon ),
        isLowPtReconstructedMuon( parent.isLowPtReconstructedMuon ),
        isSegmentTaggedMuon( parent.isSegmentTaggedMuon ),
        isCaloMuonId( parent.isCaloMuonId ),
        alsoFoundByLowPt( parent.alsoFoundByLowPt ),
        alsoFoundByCaloMuonId( parent.alsoFoundByCaloMuonId ),
        loose( parent.loose ),
        medium( parent.medium ),
        tight( parent.tight ),
        d0_exPV( parent.d0_exPV ),
        z0_exPV( parent.z0_exPV ),
        phi_exPV( parent.phi_exPV ),
        theta_exPV( parent.theta_exPV ),
        qoverp_exPV( parent.qoverp_exPV ),
        cb_d0_exPV( parent.cb_d0_exPV ),
        cb_z0_exPV( parent.cb_z0_exPV ),
        cb_phi_exPV( parent.cb_phi_exPV ),
        cb_theta_exPV( parent.cb_theta_exPV ),
        cb_qoverp_exPV( parent.cb_qoverp_exPV ),
        id_d0_exPV( parent.id_d0_exPV ),
        id_z0_exPV( parent.id_z0_exPV ),
        id_phi_exPV( parent.id_phi_exPV ),
        id_theta_exPV( parent.id_theta_exPV ),
        id_qoverp_exPV( parent.id_qoverp_exPV ),
        me_d0_exPV( parent.me_d0_exPV ),
        me_z0_exPV( parent.me_z0_exPV ),
        me_phi_exPV( parent.me_phi_exPV ),
        me_theta_exPV( parent.me_theta_exPV ),
        me_qoverp_exPV( parent.me_qoverp_exPV ),
        ie_d0_exPV( parent.ie_d0_exPV ),
        ie_z0_exPV( parent.ie_z0_exPV ),
        ie_phi_exPV( parent.ie_phi_exPV ),
        ie_theta_exPV( parent.ie_theta_exPV ),
        ie_qoverp_exPV( parent.ie_qoverp_exPV ),
        SpaceTime_detID( parent.SpaceTime_detID ),
        SpaceTime_t( parent.SpaceTime_t ),
        SpaceTime_tError( parent.SpaceTime_tError ),
        SpaceTime_weight( parent.SpaceTime_weight ),
        SpaceTime_x( parent.SpaceTime_x ),
        SpaceTime_y( parent.SpaceTime_y ),
        SpaceTime_z( parent.SpaceTime_z ),
        cov_d0_exPV( parent.cov_d0_exPV ),
        cov_z0_exPV( parent.cov_z0_exPV ),
        cov_phi_exPV( parent.cov_phi_exPV ),
        cov_theta_exPV( parent.cov_theta_exPV ),
        cov_qoverp_exPV( parent.cov_qoverp_exPV ),
        cov_d0_z0_exPV( parent.cov_d0_z0_exPV ),
        cov_d0_phi_exPV( parent.cov_d0_phi_exPV ),
        cov_d0_theta_exPV( parent.cov_d0_theta_exPV ),
        cov_d0_qoverp_exPV( parent.cov_d0_qoverp_exPV ),
        cov_z0_phi_exPV( parent.cov_z0_phi_exPV ),
        cov_z0_theta_exPV( parent.cov_z0_theta_exPV ),
        cov_z0_qoverp_exPV( parent.cov_z0_qoverp_exPV ),
        cov_phi_theta_exPV( parent.cov_phi_theta_exPV ),
        cov_phi_qoverp_exPV( parent.cov_phi_qoverp_exPV ),
        cov_theta_qoverp_exPV( parent.cov_theta_qoverp_exPV ),
        id_cov_d0_exPV( parent.id_cov_d0_exPV ),
        id_cov_z0_exPV( parent.id_cov_z0_exPV ),
        id_cov_phi_exPV( parent.id_cov_phi_exPV ),
        id_cov_theta_exPV( parent.id_cov_theta_exPV ),
        id_cov_qoverp_exPV( parent.id_cov_qoverp_exPV ),
        me_cov_d0_exPV( parent.me_cov_d0_exPV ),
        me_cov_z0_exPV( parent.me_cov_z0_exPV ),
        me_cov_phi_exPV( parent.me_cov_phi_exPV ),
        me_cov_theta_exPV( parent.me_cov_theta_exPV ),
        me_cov_qoverp_exPV( parent.me_cov_qoverp_exPV ),
        ms_d0( parent.ms_d0 ),
        ms_z0( parent.ms_z0 ),
        ms_phi( parent.ms_phi ),
        ms_theta( parent.ms_theta ),
        ms_qoverp( parent.ms_qoverp ),
        id_d0( parent.id_d0 ),
        id_z0( parent.id_z0 ),
        id_phi( parent.id_phi ),
        id_theta( parent.id_theta ),
        id_qoverp( parent.id_qoverp ),
        me_d0( parent.me_d0 ),
        me_z0( parent.me_z0 ),
        me_phi( parent.me_phi ),
        me_theta( parent.me_theta ),
        me_qoverp( parent.me_qoverp ),
        ie_d0( parent.ie_d0 ),
        ie_z0( parent.ie_z0 ),
        ie_phi( parent.ie_phi ),
        ie_theta( parent.ie_theta ),
        ie_qoverp( parent.ie_qoverp ),
        nOutliersOnTrack( parent.nOutliersOnTrack ),
        nBLHits( parent.nBLHits ),
        nPixHits( parent.nPixHits ),
        nSCTHits( parent.nSCTHits ),
        nTRTHits( parent.nTRTHits ),
        nTRTHighTHits( parent.nTRTHighTHits ),
        nBLSharedHits( parent.nBLSharedHits ),
        nPixSharedHits( parent.nPixSharedHits ),
        nPixHoles( parent.nPixHoles ),
        nSCTSharedHits( parent.nSCTSharedHits ),
        nSCTHoles( parent.nSCTHoles ),
        nTRTOutliers( parent.nTRTOutliers ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers ),
        nGangedPixels( parent.nGangedPixels ),
        nPixelDeadSensors( parent.nPixelDeadSensors ),
        nSCTDeadSensors( parent.nSCTDeadSensors ),
        nTRTDeadStraws( parent.nTRTDeadStraws ),
        expectBLayerHit( parent.expectBLayerHit ),
        nMDTHits( parent.nMDTHits ),
        nMDTHoles( parent.nMDTHoles ),
        nCSCEtaHits( parent.nCSCEtaHits ),
        nCSCEtaHoles( parent.nCSCEtaHoles ),
        nCSCPhiHits( parent.nCSCPhiHits ),
        nCSCPhiHoles( parent.nCSCPhiHoles ),
        nRPCEtaHits( parent.nRPCEtaHits ),
        nRPCEtaHoles( parent.nRPCEtaHoles ),
        nRPCPhiHits( parent.nRPCPhiHits ),
        nRPCPhiHoles( parent.nRPCPhiHoles ),
        nTGCEtaHits( parent.nTGCEtaHits ),
        nTGCEtaHoles( parent.nTGCEtaHoles ),
        nTGCPhiHits( parent.nTGCPhiHits ),
        nTGCPhiHoles( parent.nTGCPhiHoles ),
        nMDTBIHits( parent.nMDTBIHits ),
        nMDTBMHits( parent.nMDTBMHits ),
        nMDTBOHits( parent.nMDTBOHits ),
        nMDTBEEHits( parent.nMDTBEEHits ),
        nMDTBIS78Hits( parent.nMDTBIS78Hits ),
        nMDTEIHits( parent.nMDTEIHits ),
        nMDTEMHits( parent.nMDTEMHits ),
        nMDTEOHits( parent.nMDTEOHits ),
        nMDTEEHits( parent.nMDTEEHits ),
        nRPCLayer1EtaHits( parent.nRPCLayer1EtaHits ),
        nRPCLayer2EtaHits( parent.nRPCLayer2EtaHits ),
        nRPCLayer3EtaHits( parent.nRPCLayer3EtaHits ),
        nRPCLayer1PhiHits( parent.nRPCLayer1PhiHits ),
        nRPCLayer2PhiHits( parent.nRPCLayer2PhiHits ),
        nRPCLayer3PhiHits( parent.nRPCLayer3PhiHits ),
        nTGCLayer1EtaHits( parent.nTGCLayer1EtaHits ),
        nTGCLayer2EtaHits( parent.nTGCLayer2EtaHits ),
        nTGCLayer3EtaHits( parent.nTGCLayer3EtaHits ),
        nTGCLayer4EtaHits( parent.nTGCLayer4EtaHits ),
        nTGCLayer1PhiHits( parent.nTGCLayer1PhiHits ),
        nTGCLayer2PhiHits( parent.nTGCLayer2PhiHits ),
        nTGCLayer3PhiHits( parent.nTGCLayer3PhiHits ),
        nTGCLayer4PhiHits( parent.nTGCLayer4PhiHits ),
        barrelSectors( parent.barrelSectors ),
        endcapSectors( parent.endcapSectors ),
        trackd0( parent.trackd0 ),
        trackz0( parent.trackz0 ),
        trackphi( parent.trackphi ),
        tracktheta( parent.tracktheta ),
        trackqoverp( parent.trackqoverp ),
        trackcov_d0( parent.trackcov_d0 ),
        trackcov_z0( parent.trackcov_z0 ),
        trackcov_phi( parent.trackcov_phi ),
        trackcov_theta( parent.trackcov_theta ),
        trackcov_qoverp( parent.trackcov_qoverp ),
        trackcov_d0_z0( parent.trackcov_d0_z0 ),
        trackcov_d0_phi( parent.trackcov_d0_phi ),
        trackcov_d0_theta( parent.trackcov_d0_theta ),
        trackcov_d0_qoverp( parent.trackcov_d0_qoverp ),
        trackcov_z0_phi( parent.trackcov_z0_phi ),
        trackcov_z0_theta( parent.trackcov_z0_theta ),
        trackcov_z0_qoverp( parent.trackcov_z0_qoverp ),
        trackcov_phi_theta( parent.trackcov_phi_theta ),
        trackcov_phi_qoverp( parent.trackcov_phi_qoverp ),
        trackcov_theta_qoverp( parent.trackcov_theta_qoverp ),
        trackfitchi2( parent.trackfitchi2 ),
        trackfitndof( parent.trackfitndof ),
        hastrack( parent.hastrack ),
        trackd0beam( parent.trackd0beam ),
        trackz0beam( parent.trackz0beam ),
        tracksigd0beam( parent.tracksigd0beam ),
        tracksigz0beam( parent.tracksigz0beam ),
        trackd0pv( parent.trackd0pv ),
        trackz0pv( parent.trackz0pv ),
        tracksigd0pv( parent.tracksigd0pv ),
        tracksigz0pv( parent.tracksigz0pv ),
        trackIPEstimate_d0_biasedpvunbiased( parent.trackIPEstimate_d0_biasedpvunbiased ),
        trackIPEstimate_z0_biasedpvunbiased( parent.trackIPEstimate_z0_biasedpvunbiased ),
        trackIPEstimate_sigd0_biasedpvunbiased( parent.trackIPEstimate_sigd0_biasedpvunbiased ),
        trackIPEstimate_sigz0_biasedpvunbiased( parent.trackIPEstimate_sigz0_biasedpvunbiased ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased ),
        trackd0pvunbiased( parent.trackd0pvunbiased ),
        trackz0pvunbiased( parent.trackz0pvunbiased ),
        tracksigd0pvunbiased( parent.tracksigd0pvunbiased ),
        tracksigz0pvunbiased( parent.tracksigz0pvunbiased ),
        truth_dr( parent.truth_dr ),
        truth_matched( parent.truth_matched ),
	EFCB_dr( parent.EFCB_dr ),
	//        EFCB_n( parent.EFCB_n ),
	//        EFCB_MuonType( parent.EFCB_MuonType ),
	//        EFCB_pt( parent.EFCB_pt ),
	//        EFCB_eta( parent.EFCB_eta ),
	//        EFCB_phi( parent.EFCB_phi ),
	//        EFCB_hasCB( parent.EFCB_hasCB ),
	//        EFCB_matched( parent.EFCB_matched ),
        EFMG_dr( parent.EFMG_dr ),
	//        EFMG_n( parent.EFMG_n ),
	//        EFMG_MuonType( parent.EFMG_MuonType ),
	//        EFMG_pt( parent.EFMG_pt ),
	//        EFMG_eta( parent.EFMG_eta ),
	//        EFMG_phi( parent.EFMG_phi ),
	//        EFMG_hasMG( parent.EFMG_hasMG ),
	//        EFMG_matched( parent.EFMG_matched ),
        EFME_dr( parent.EFME_dr ),
	//        EFME_n( parent.EFME_n ),
	//        EFME_MuonType( parent.EFME_MuonType ),
	//        EFME_pt( parent.EFME_pt ),
	//        EFME_eta( parent.EFME_eta ),
	//        EFME_phi( parent.EFME_phi ),
	//        EFME_hasME( parent.EFME_hasME ),
	//        EFME_matched( parent.EFME_matched ),
        L2CB_dr( parent.L2CB_dr ),
        L2CB_pt( parent.L2CB_pt ),
        L2CB_eta( parent.L2CB_eta ),
        L2CB_phi( parent.L2CB_phi ),
        L2CB_id_pt( parent.L2CB_id_pt ),
        L2CB_ms_pt( parent.L2CB_ms_pt ),
        L2CB_nPixHits( parent.L2CB_nPixHits ),
        L2CB_nSCTHits( parent.L2CB_nSCTHits ),
        L2CB_nTRTHits( parent.L2CB_nTRTHits ),
        L2CB_nTRTHighTHits( parent.L2CB_nTRTHighTHits ),
        L2CB_matched( parent.L2CB_matched ),
        L1_dr( parent.L1_dr ),
        L1_pt( parent.L1_pt ),
        L1_eta( parent.L1_eta ),
        L1_phi( parent.L1_phi ),
        L1_thrNumber( parent.L1_thrNumber ),
        L1_RoINumber( parent.L1_RoINumber ),
        L1_sectorAddress( parent.L1_sectorAddress ),
        L1_firstCandidate( parent.L1_firstCandidate ),
        L1_moreCandInRoI( parent.L1_moreCandInRoI ),
        L1_moreCandInSector( parent.L1_moreCandInSector ),
        L1_source( parent.L1_source ),
        L1_hemisphere( parent.L1_hemisphere ),
        L1_charge( parent.L1_charge ),
        L1_vetoed( parent.L1_vetoed ),
        L1_matched( parent.L1_matched ) {

   }

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   MuonMuidD3PDObject::MuonMuidD3PDObject( const ::Long64_t& master, const char* prefix )
      : TObject(),
        n( this, ::TString( prefix ) + "n", &master ),
        E( this, ::TString( prefix ) + "E", &master ),
        pt( this, ::TString( prefix ) + "pt", &master ),
        m( this, ::TString( prefix ) + "m", &master ),
        eta( this, ::TString( prefix ) + "eta", &master ),
        phi( this, ::TString( prefix ) + "phi", &master ),
        px( this, ::TString( prefix ) + "px", &master ),
        py( this, ::TString( prefix ) + "py", &master ),
        pz( this, ::TString( prefix ) + "pz", &master ),
        charge( this, ::TString( prefix ) + "charge", &master ),
        allauthor( this, ::TString( prefix ) + "allauthor", &master ),
        author( this, ::TString( prefix ) + "author", &master ),
        beta( this, ::TString( prefix ) + "beta", &master ),
        isMuonLikelihood( this, ::TString( prefix ) + "isMuonLikelihood", &master ),
        matchchi2( this, ::TString( prefix ) + "matchchi2", &master ),
        matchndof( this, ::TString( prefix ) + "matchndof", &master ),
        etcone20( this, ::TString( prefix ) + "etcone20", &master ),
        etcone30( this, ::TString( prefix ) + "etcone30", &master ),
        etcone40( this, ::TString( prefix ) + "etcone40", &master ),
        nucone20( this, ::TString( prefix ) + "nucone20", &master ),
        nucone30( this, ::TString( prefix ) + "nucone30", &master ),
        nucone40( this, ::TString( prefix ) + "nucone40", &master ),
        ptcone20( this, ::TString( prefix ) + "ptcone20", &master ),
        ptcone30( this, ::TString( prefix ) + "ptcone30", &master ),
        ptcone40( this, ::TString( prefix ) + "ptcone40", &master ),
        energyLossPar( this, ::TString( prefix ) + "energyLossPar", &master ),
        energyLossErr( this, ::TString( prefix ) + "energyLossErr", &master ),
        etCore( this, ::TString( prefix ) + "etCore", &master ),
        energyLossType( this, ::TString( prefix ) + "energyLossType", &master ),
        caloMuonIdTag( this, ::TString( prefix ) + "caloMuonIdTag", &master ),
        caloLRLikelihood( this, ::TString( prefix ) + "caloLRLikelihood", &master ),
        bestMatch( this, ::TString( prefix ) + "bestMatch", &master ),
        isStandAloneMuon( this, ::TString( prefix ) + "isStandAloneMuon", &master ),
        isCombinedMuon( this, ::TString( prefix ) + "isCombinedMuon", &master ),
        isLowPtReconstructedMuon( this, ::TString( prefix ) + "isLowPtReconstructedMuon", &master ),
        isSegmentTaggedMuon( this, ::TString( prefix ) + "isSegmentTaggedMuon", &master ),
        isCaloMuonId( this, ::TString( prefix ) + "isCaloMuonId", &master ),
        alsoFoundByLowPt( this, ::TString( prefix ) + "alsoFoundByLowPt", &master ),
        alsoFoundByCaloMuonId( this, ::TString( prefix ) + "alsoFoundByCaloMuonId", &master ),
        loose( this, ::TString( prefix ) + "loose", &master ),
        medium( this, ::TString( prefix ) + "medium", &master ),
        tight( this, ::TString( prefix ) + "tight", &master ),
        d0_exPV( this, ::TString( prefix ) + "d0_exPV", &master ),
        z0_exPV( this, ::TString( prefix ) + "z0_exPV", &master ),
        phi_exPV( this, ::TString( prefix ) + "phi_exPV", &master ),
        theta_exPV( this, ::TString( prefix ) + "theta_exPV", &master ),
        qoverp_exPV( this, ::TString( prefix ) + "qoverp_exPV", &master ),
        cb_d0_exPV( this, ::TString( prefix ) + "cb_d0_exPV", &master ),
        cb_z0_exPV( this, ::TString( prefix ) + "cb_z0_exPV", &master ),
        cb_phi_exPV( this, ::TString( prefix ) + "cb_phi_exPV", &master ),
        cb_theta_exPV( this, ::TString( prefix ) + "cb_theta_exPV", &master ),
        cb_qoverp_exPV( this, ::TString( prefix ) + "cb_qoverp_exPV", &master ),
        id_d0_exPV( this, ::TString( prefix ) + "id_d0_exPV", &master ),
        id_z0_exPV( this, ::TString( prefix ) + "id_z0_exPV", &master ),
        id_phi_exPV( this, ::TString( prefix ) + "id_phi_exPV", &master ),
        id_theta_exPV( this, ::TString( prefix ) + "id_theta_exPV", &master ),
        id_qoverp_exPV( this, ::TString( prefix ) + "id_qoverp_exPV", &master ),
        me_d0_exPV( this, ::TString( prefix ) + "me_d0_exPV", &master ),
        me_z0_exPV( this, ::TString( prefix ) + "me_z0_exPV", &master ),
        me_phi_exPV( this, ::TString( prefix ) + "me_phi_exPV", &master ),
        me_theta_exPV( this, ::TString( prefix ) + "me_theta_exPV", &master ),
        me_qoverp_exPV( this, ::TString( prefix ) + "me_qoverp_exPV", &master ),
        ie_d0_exPV( this, ::TString( prefix ) + "ie_d0_exPV", &master ),
        ie_z0_exPV( this, ::TString( prefix ) + "ie_z0_exPV", &master ),
        ie_phi_exPV( this, ::TString( prefix ) + "ie_phi_exPV", &master ),
        ie_theta_exPV( this, ::TString( prefix ) + "ie_theta_exPV", &master ),
        ie_qoverp_exPV( this, ::TString( prefix ) + "ie_qoverp_exPV", &master ),
        SpaceTime_detID( this, ::TString( prefix ) + "SpaceTime_detID", &master ),
        SpaceTime_t( this, ::TString( prefix ) + "SpaceTime_t", &master ),
        SpaceTime_tError( this, ::TString( prefix ) + "SpaceTime_tError", &master ),
        SpaceTime_weight( this, ::TString( prefix ) + "SpaceTime_weight", &master ),
        SpaceTime_x( this, ::TString( prefix ) + "SpaceTime_x", &master ),
        SpaceTime_y( this, ::TString( prefix ) + "SpaceTime_y", &master ),
        SpaceTime_z( this, ::TString( prefix ) + "SpaceTime_z", &master ),
        cov_d0_exPV( this, ::TString( prefix ) + "cov_d0_exPV", &master ),
        cov_z0_exPV( this, ::TString( prefix ) + "cov_z0_exPV", &master ),
        cov_phi_exPV( this, ::TString( prefix ) + "cov_phi_exPV", &master ),
        cov_theta_exPV( this, ::TString( prefix ) + "cov_theta_exPV", &master ),
        cov_qoverp_exPV( this, ::TString( prefix ) + "cov_qoverp_exPV", &master ),
        cov_d0_z0_exPV( this, ::TString( prefix ) + "cov_d0_z0_exPV", &master ),
        cov_d0_phi_exPV( this, ::TString( prefix ) + "cov_d0_phi_exPV", &master ),
        cov_d0_theta_exPV( this, ::TString( prefix ) + "cov_d0_theta_exPV", &master ),
        cov_d0_qoverp_exPV( this, ::TString( prefix ) + "cov_d0_qoverp_exPV", &master ),
        cov_z0_phi_exPV( this, ::TString( prefix ) + "cov_z0_phi_exPV", &master ),
        cov_z0_theta_exPV( this, ::TString( prefix ) + "cov_z0_theta_exPV", &master ),
        cov_z0_qoverp_exPV( this, ::TString( prefix ) + "cov_z0_qoverp_exPV", &master ),
        cov_phi_theta_exPV( this, ::TString( prefix ) + "cov_phi_theta_exPV", &master ),
        cov_phi_qoverp_exPV( this, ::TString( prefix ) + "cov_phi_qoverp_exPV", &master ),
        cov_theta_qoverp_exPV( this, ::TString( prefix ) + "cov_theta_qoverp_exPV", &master ),
        id_cov_d0_exPV( this, ::TString( prefix ) + "id_cov_d0_exPV", &master ),
        id_cov_z0_exPV( this, ::TString( prefix ) + "id_cov_z0_exPV", &master ),
        id_cov_phi_exPV( this, ::TString( prefix ) + "id_cov_phi_exPV", &master ),
        id_cov_theta_exPV( this, ::TString( prefix ) + "id_cov_theta_exPV", &master ),
        id_cov_qoverp_exPV( this, ::TString( prefix ) + "id_cov_qoverp_exPV", &master ),
        me_cov_d0_exPV( this, ::TString( prefix ) + "me_cov_d0_exPV", &master ),
        me_cov_z0_exPV( this, ::TString( prefix ) + "me_cov_z0_exPV", &master ),
        me_cov_phi_exPV( this, ::TString( prefix ) + "me_cov_phi_exPV", &master ),
        me_cov_theta_exPV( this, ::TString( prefix ) + "me_cov_theta_exPV", &master ),
        me_cov_qoverp_exPV( this, ::TString( prefix ) + "me_cov_qoverp_exPV", &master ),
        ms_d0( this, ::TString( prefix ) + "ms_d0", &master ),
        ms_z0( this, ::TString( prefix ) + "ms_z0", &master ),
        ms_phi( this, ::TString( prefix ) + "ms_phi", &master ),
        ms_theta( this, ::TString( prefix ) + "ms_theta", &master ),
        ms_qoverp( this, ::TString( prefix ) + "ms_qoverp", &master ),
        id_d0( this, ::TString( prefix ) + "id_d0", &master ),
        id_z0( this, ::TString( prefix ) + "id_z0", &master ),
        id_phi( this, ::TString( prefix ) + "id_phi", &master ),
        id_theta( this, ::TString( prefix ) + "id_theta", &master ),
        id_qoverp( this, ::TString( prefix ) + "id_qoverp", &master ),
        me_d0( this, ::TString( prefix ) + "me_d0", &master ),
        me_z0( this, ::TString( prefix ) + "me_z0", &master ),
        me_phi( this, ::TString( prefix ) + "me_phi", &master ),
        me_theta( this, ::TString( prefix ) + "me_theta", &master ),
        me_qoverp( this, ::TString( prefix ) + "me_qoverp", &master ),
        ie_d0( this, ::TString( prefix ) + "ie_d0", &master ),
        ie_z0( this, ::TString( prefix ) + "ie_z0", &master ),
        ie_phi( this, ::TString( prefix ) + "ie_phi", &master ),
        ie_theta( this, ::TString( prefix ) + "ie_theta", &master ),
        ie_qoverp( this, ::TString( prefix ) + "ie_qoverp", &master ),
        nOutliersOnTrack( this, ::TString( prefix ) + "nOutliersOnTrack", &master ),
        nBLHits( this, ::TString( prefix ) + "nBLHits", &master ),
        nPixHits( this, ::TString( prefix ) + "nPixHits", &master ),
        nSCTHits( this, ::TString( prefix ) + "nSCTHits", &master ),
        nTRTHits( this, ::TString( prefix ) + "nTRTHits", &master ),
        nTRTHighTHits( this, ::TString( prefix ) + "nTRTHighTHits", &master ),
        nBLSharedHits( this, ::TString( prefix ) + "nBLSharedHits", &master ),
        nPixSharedHits( this, ::TString( prefix ) + "nPixSharedHits", &master ),
        nPixHoles( this, ::TString( prefix ) + "nPixHoles", &master ),
        nSCTSharedHits( this, ::TString( prefix ) + "nSCTSharedHits", &master ),
        nSCTHoles( this, ::TString( prefix ) + "nSCTHoles", &master ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", &master ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", &master ),
        nGangedPixels( this, ::TString( prefix ) + "nGangedPixels", &master ),
        nPixelDeadSensors( this, ::TString( prefix ) + "nPixelDeadSensors", &master ),
        nSCTDeadSensors( this, ::TString( prefix ) + "nSCTDeadSensors", &master ),
        nTRTDeadStraws( this, ::TString( prefix ) + "nTRTDeadStraws", &master ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", &master ),
        nMDTHits( this, ::TString( prefix ) + "nMDTHits", &master ),
        nMDTHoles( this, ::TString( prefix ) + "nMDTHoles", &master ),
        nCSCEtaHits( this, ::TString( prefix ) + "nCSCEtaHits", &master ),
        nCSCEtaHoles( this, ::TString( prefix ) + "nCSCEtaHoles", &master ),
        nCSCPhiHits( this, ::TString( prefix ) + "nCSCPhiHits", &master ),
        nCSCPhiHoles( this, ::TString( prefix ) + "nCSCPhiHoles", &master ),
        nRPCEtaHits( this, ::TString( prefix ) + "nRPCEtaHits", &master ),
        nRPCEtaHoles( this, ::TString( prefix ) + "nRPCEtaHoles", &master ),
        nRPCPhiHits( this, ::TString( prefix ) + "nRPCPhiHits", &master ),
        nRPCPhiHoles( this, ::TString( prefix ) + "nRPCPhiHoles", &master ),
        nTGCEtaHits( this, ::TString( prefix ) + "nTGCEtaHits", &master ),
        nTGCEtaHoles( this, ::TString( prefix ) + "nTGCEtaHoles", &master ),
        nTGCPhiHits( this, ::TString( prefix ) + "nTGCPhiHits", &master ),
        nTGCPhiHoles( this, ::TString( prefix ) + "nTGCPhiHoles", &master ),
        nMDTBIHits( this, ::TString( prefix ) + "nMDTBIHits", &master ),
        nMDTBMHits( this, ::TString( prefix ) + "nMDTBMHits", &master ),
        nMDTBOHits( this, ::TString( prefix ) + "nMDTBOHits", &master ),
        nMDTBEEHits( this, ::TString( prefix ) + "nMDTBEEHits", &master ),
        nMDTBIS78Hits( this, ::TString( prefix ) + "nMDTBIS78Hits", &master ),
        nMDTEIHits( this, ::TString( prefix ) + "nMDTEIHits", &master ),
        nMDTEMHits( this, ::TString( prefix ) + "nMDTEMHits", &master ),
        nMDTEOHits( this, ::TString( prefix ) + "nMDTEOHits", &master ),
        nMDTEEHits( this, ::TString( prefix ) + "nMDTEEHits", &master ),
        nRPCLayer1EtaHits( this, ::TString( prefix ) + "nRPCLayer1EtaHits", &master ),
        nRPCLayer2EtaHits( this, ::TString( prefix ) + "nRPCLayer2EtaHits", &master ),
        nRPCLayer3EtaHits( this, ::TString( prefix ) + "nRPCLayer3EtaHits", &master ),
        nRPCLayer1PhiHits( this, ::TString( prefix ) + "nRPCLayer1PhiHits", &master ),
        nRPCLayer2PhiHits( this, ::TString( prefix ) + "nRPCLayer2PhiHits", &master ),
        nRPCLayer3PhiHits( this, ::TString( prefix ) + "nRPCLayer3PhiHits", &master ),
        nTGCLayer1EtaHits( this, ::TString( prefix ) + "nTGCLayer1EtaHits", &master ),
        nTGCLayer2EtaHits( this, ::TString( prefix ) + "nTGCLayer2EtaHits", &master ),
        nTGCLayer3EtaHits( this, ::TString( prefix ) + "nTGCLayer3EtaHits", &master ),
        nTGCLayer4EtaHits( this, ::TString( prefix ) + "nTGCLayer4EtaHits", &master ),
        nTGCLayer1PhiHits( this, ::TString( prefix ) + "nTGCLayer1PhiHits", &master ),
        nTGCLayer2PhiHits( this, ::TString( prefix ) + "nTGCLayer2PhiHits", &master ),
        nTGCLayer3PhiHits( this, ::TString( prefix ) + "nTGCLayer3PhiHits", &master ),
        nTGCLayer4PhiHits( this, ::TString( prefix ) + "nTGCLayer4PhiHits", &master ),
        barrelSectors( this, ::TString( prefix ) + "barrelSectors", &master ),
        endcapSectors( this, ::TString( prefix ) + "endcapSectors", &master ),
        trackd0( this, ::TString( prefix ) + "trackd0", &master ),
        trackz0( this, ::TString( prefix ) + "trackz0", &master ),
        trackphi( this, ::TString( prefix ) + "trackphi", &master ),
        tracktheta( this, ::TString( prefix ) + "tracktheta", &master ),
        trackqoverp( this, ::TString( prefix ) + "trackqoverp", &master ),
        trackcov_d0( this, ::TString( prefix ) + "trackcov_d0", &master ),
        trackcov_z0( this, ::TString( prefix ) + "trackcov_z0", &master ),
        trackcov_phi( this, ::TString( prefix ) + "trackcov_phi", &master ),
        trackcov_theta( this, ::TString( prefix ) + "trackcov_theta", &master ),
        trackcov_qoverp( this, ::TString( prefix ) + "trackcov_qoverp", &master ),
        trackcov_d0_z0( this, ::TString( prefix ) + "trackcov_d0_z0", &master ),
        trackcov_d0_phi( this, ::TString( prefix ) + "trackcov_d0_phi", &master ),
        trackcov_d0_theta( this, ::TString( prefix ) + "trackcov_d0_theta", &master ),
        trackcov_d0_qoverp( this, ::TString( prefix ) + "trackcov_d0_qoverp", &master ),
        trackcov_z0_phi( this, ::TString( prefix ) + "trackcov_z0_phi", &master ),
        trackcov_z0_theta( this, ::TString( prefix ) + "trackcov_z0_theta", &master ),
        trackcov_z0_qoverp( this, ::TString( prefix ) + "trackcov_z0_qoverp", &master ),
        trackcov_phi_theta( this, ::TString( prefix ) + "trackcov_phi_theta", &master ),
        trackcov_phi_qoverp( this, ::TString( prefix ) + "trackcov_phi_qoverp", &master ),
        trackcov_theta_qoverp( this, ::TString( prefix ) + "trackcov_theta_qoverp", &master ),
        trackfitchi2( this, ::TString( prefix ) + "trackfitchi2", &master ),
        trackfitndof( this, ::TString( prefix ) + "trackfitndof", &master ),
        hastrack( this, ::TString( prefix ) + "hastrack", &master ),
        trackd0beam( this, ::TString( prefix ) + "trackd0beam", &master ),
        trackz0beam( this, ::TString( prefix ) + "trackz0beam", &master ),
        tracksigd0beam( this, ::TString( prefix ) + "tracksigd0beam", &master ),
        tracksigz0beam( this, ::TString( prefix ) + "tracksigz0beam", &master ),
        trackd0pv( this, ::TString( prefix ) + "trackd0pv", &master ),
        trackz0pv( this, ::TString( prefix ) + "trackz0pv", &master ),
        tracksigd0pv( this, ::TString( prefix ) + "tracksigd0pv", &master ),
        tracksigz0pv( this, ::TString( prefix ) + "tracksigz0pv", &master ),
        trackIPEstimate_d0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_biasedpvunbiased", &master ),
        trackIPEstimate_z0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_biasedpvunbiased", &master ),
        trackIPEstimate_sigd0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_biasedpvunbiased", &master ),
        trackIPEstimate_sigz0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_biasedpvunbiased", &master ),
        trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", &master ),
        trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", &master ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", &master ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased", &master ),
        trackd0pvunbiased( this, ::TString( prefix ) + "trackd0pvunbiased", &master ),
        trackz0pvunbiased( this, ::TString( prefix ) + "trackz0pvunbiased", &master ),
        tracksigd0pvunbiased( this, ::TString( prefix ) + "tracksigd0pvunbiased", &master ),
        tracksigz0pvunbiased( this, ::TString( prefix ) + "tracksigz0pvunbiased", &master ),
        truth_dr( this, ::TString( prefix ) + "truth_dr", &master ),
        truth_matched( this, ::TString( prefix ) + "truth_matched", &master ),
        EFCB_dr( this, ::TString( prefix ) + "EFCB_dr", &master ),
	//        EFCB_n( this, ::TString( prefix ) + "EFCB_n", &master ),
	//        EFCB_MuonType( this, ::TString( prefix ) + "EFCB_MuonType", &master ),
	//        EFCB_pt( this, ::TString( prefix ) + "EFCB_pt", &master ),
	//        EFCB_eta( this, ::TString( prefix ) + "EFCB_eta", &master ),
	//        EFCB_phi( this, ::TString( prefix ) + "EFCB_phi", &master ),
	//        EFCB_hasCB( this, ::TString( prefix ) + "EFCB_hasCB", &master ),
	//        EFCB_matched( this, ::TString( prefix ) + "EFCB_matched", &master ),
	EFMG_dr( this, ::TString( prefix ) + "EFMG_dr", &master ),
	//        EFMG_n( this, ::TString( prefix ) + "EFMG_n", &master ),
	//        EFMG_MuonType( this, ::TString( prefix ) + "EFMG_MuonType", &master ),
	//        EFMG_pt( this, ::TString( prefix ) + "EFMG_pt", &master ),
	//        EFMG_eta( this, ::TString( prefix ) + "EFMG_eta", &master ),
	//        EFMG_phi( this, ::TString( prefix ) + "EFMG_phi", &master ),
	//        EFMG_hasMG( this, ::TString( prefix ) + "EFMG_hasMG", &master ),
	//        EFMG_matched( this, ::TString( prefix ) + "EFMG_matched", &master ),
        EFME_dr( this, ::TString( prefix ) + "EFME_dr", &master ),
	//        EFME_n( this, ::TString( prefix ) + "EFME_n", &master ),
	//        EFME_MuonType( this, ::TString( prefix ) + "EFME_MuonType", &master ),
	//        EFME_pt( this, ::TString( prefix ) + "EFME_pt", &master ),
	//        EFME_eta( this, ::TString( prefix ) + "EFME_eta", &master ),
	//        EFME_phi( this, ::TString( prefix ) + "EFME_phi", &master ),
	//        EFME_hasME( this, ::TString( prefix ) + "EFME_hasME", &master ),
	//        EFME_matched( this, ::TString( prefix ) + "EFME_matched", &master ),
        L2CB_dr( this, ::TString( prefix ) + "L2CB_dr", &master ),
        L2CB_pt( this, ::TString( prefix ) + "L2CB_pt", &master ),
        L2CB_eta( this, ::TString( prefix ) + "L2CB_eta", &master ),
        L2CB_phi( this, ::TString( prefix ) + "L2CB_phi", &master ),
        L2CB_id_pt( this, ::TString( prefix ) + "L2CB_id_pt", &master ),
        L2CB_ms_pt( this, ::TString( prefix ) + "L2CB_ms_pt", &master ),
        L2CB_nPixHits( this, ::TString( prefix ) + "L2CB_nPixHits", &master ),
        L2CB_nSCTHits( this, ::TString( prefix ) + "L2CB_nSCTHits", &master ),
        L2CB_nTRTHits( this, ::TString( prefix ) + "L2CB_nTRTHits", &master ),
        L2CB_nTRTHighTHits( this, ::TString( prefix ) + "L2CB_nTRTHighTHits", &master ),
        L2CB_matched( this, ::TString( prefix ) + "L2CB_matched", &master ),
        L1_dr( this, ::TString( prefix ) + "L1_dr", &master ),
        L1_pt( this, ::TString( prefix ) + "L1_pt", &master ),
        L1_eta( this, ::TString( prefix ) + "L1_eta", &master ),
        L1_phi( this, ::TString( prefix ) + "L1_phi", &master ),
        L1_thrNumber( this, ::TString( prefix ) + "L1_thrNumber", &master ),
        L1_RoINumber( this, ::TString( prefix ) + "L1_RoINumber", &master ),
        L1_sectorAddress( this, ::TString( prefix ) + "L1_sectorAddress", &master ),
        L1_firstCandidate( this, ::TString( prefix ) + "L1_firstCandidate", &master ),
        L1_moreCandInRoI( this, ::TString( prefix ) + "L1_moreCandInRoI", &master ),
        L1_moreCandInSector( this, ::TString( prefix ) + "L1_moreCandInSector", &master ),
        L1_source( this, ::TString( prefix ) + "L1_source", &master ),
        L1_hemisphere( this, ::TString( prefix ) + "L1_hemisphere", &master ),
        L1_charge( this, ::TString( prefix ) + "L1_charge", &master ),
        L1_vetoed( this, ::TString( prefix ) + "L1_vetoed", &master ),
        L1_matched( this, ::TString( prefix ) + "L1_matched", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "charge" ] = &charge;
      fHandles[ "allauthor" ] = &allauthor;
      fHandles[ "author" ] = &author;
      fHandles[ "beta" ] = &beta;
      fHandles[ "isMuonLikelihood" ] = &isMuonLikelihood;
      fHandles[ "matchchi2" ] = &matchchi2;
      fHandles[ "matchndof" ] = &matchndof;
      fHandles[ "etcone20" ] = &etcone20;
      fHandles[ "etcone30" ] = &etcone30;
      fHandles[ "etcone40" ] = &etcone40;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "energyLossPar" ] = &energyLossPar;
      fHandles[ "energyLossErr" ] = &energyLossErr;
      fHandles[ "etCore" ] = &etCore;
      fHandles[ "energyLossType" ] = &energyLossType;
      fHandles[ "caloMuonIdTag" ] = &caloMuonIdTag;
      fHandles[ "caloLRLikelihood" ] = &caloLRLikelihood;
      fHandles[ "bestMatch" ] = &bestMatch;
      fHandles[ "isStandAloneMuon" ] = &isStandAloneMuon;
      fHandles[ "isCombinedMuon" ] = &isCombinedMuon;
      fHandles[ "isLowPtReconstructedMuon" ] = &isLowPtReconstructedMuon;
      fHandles[ "isSegmentTaggedMuon" ] = &isSegmentTaggedMuon;
      fHandles[ "isCaloMuonId" ] = &isCaloMuonId;
      fHandles[ "alsoFoundByLowPt" ] = &alsoFoundByLowPt;
      fHandles[ "alsoFoundByCaloMuonId" ] = &alsoFoundByCaloMuonId;
      fHandles[ "loose" ] = &loose;
      fHandles[ "medium" ] = &medium;
      fHandles[ "tight" ] = &tight;
      fHandles[ "d0_exPV" ] = &d0_exPV;
      fHandles[ "z0_exPV" ] = &z0_exPV;
      fHandles[ "phi_exPV" ] = &phi_exPV;
      fHandles[ "theta_exPV" ] = &theta_exPV;
      fHandles[ "qoverp_exPV" ] = &qoverp_exPV;
      fHandles[ "cb_d0_exPV" ] = &cb_d0_exPV;
      fHandles[ "cb_z0_exPV" ] = &cb_z0_exPV;
      fHandles[ "cb_phi_exPV" ] = &cb_phi_exPV;
      fHandles[ "cb_theta_exPV" ] = &cb_theta_exPV;
      fHandles[ "cb_qoverp_exPV" ] = &cb_qoverp_exPV;
      fHandles[ "id_d0_exPV" ] = &id_d0_exPV;
      fHandles[ "id_z0_exPV" ] = &id_z0_exPV;
      fHandles[ "id_phi_exPV" ] = &id_phi_exPV;
      fHandles[ "id_theta_exPV" ] = &id_theta_exPV;
      fHandles[ "id_qoverp_exPV" ] = &id_qoverp_exPV;
      fHandles[ "me_d0_exPV" ] = &me_d0_exPV;
      fHandles[ "me_z0_exPV" ] = &me_z0_exPV;
      fHandles[ "me_phi_exPV" ] = &me_phi_exPV;
      fHandles[ "me_theta_exPV" ] = &me_theta_exPV;
      fHandles[ "me_qoverp_exPV" ] = &me_qoverp_exPV;
      fHandles[ "ie_d0_exPV" ] = &ie_d0_exPV;
      fHandles[ "ie_z0_exPV" ] = &ie_z0_exPV;
      fHandles[ "ie_phi_exPV" ] = &ie_phi_exPV;
      fHandles[ "ie_theta_exPV" ] = &ie_theta_exPV;
      fHandles[ "ie_qoverp_exPV" ] = &ie_qoverp_exPV;
      fHandles[ "SpaceTime_detID" ] = &SpaceTime_detID;
      fHandles[ "SpaceTime_t" ] = &SpaceTime_t;
      fHandles[ "SpaceTime_tError" ] = &SpaceTime_tError;
      fHandles[ "SpaceTime_weight" ] = &SpaceTime_weight;
      fHandles[ "SpaceTime_x" ] = &SpaceTime_x;
      fHandles[ "SpaceTime_y" ] = &SpaceTime_y;
      fHandles[ "SpaceTime_z" ] = &SpaceTime_z;
      fHandles[ "cov_d0_exPV" ] = &cov_d0_exPV;
      fHandles[ "cov_z0_exPV" ] = &cov_z0_exPV;
      fHandles[ "cov_phi_exPV" ] = &cov_phi_exPV;
      fHandles[ "cov_theta_exPV" ] = &cov_theta_exPV;
      fHandles[ "cov_qoverp_exPV" ] = &cov_qoverp_exPV;
      fHandles[ "cov_d0_z0_exPV" ] = &cov_d0_z0_exPV;
      fHandles[ "cov_d0_phi_exPV" ] = &cov_d0_phi_exPV;
      fHandles[ "cov_d0_theta_exPV" ] = &cov_d0_theta_exPV;
      fHandles[ "cov_d0_qoverp_exPV" ] = &cov_d0_qoverp_exPV;
      fHandles[ "cov_z0_phi_exPV" ] = &cov_z0_phi_exPV;
      fHandles[ "cov_z0_theta_exPV" ] = &cov_z0_theta_exPV;
      fHandles[ "cov_z0_qoverp_exPV" ] = &cov_z0_qoverp_exPV;
      fHandles[ "cov_phi_theta_exPV" ] = &cov_phi_theta_exPV;
      fHandles[ "cov_phi_qoverp_exPV" ] = &cov_phi_qoverp_exPV;
      fHandles[ "cov_theta_qoverp_exPV" ] = &cov_theta_qoverp_exPV;
      fHandles[ "id_cov_d0_exPV" ] = &id_cov_d0_exPV;
      fHandles[ "id_cov_z0_exPV" ] = &id_cov_z0_exPV;
      fHandles[ "id_cov_phi_exPV" ] = &id_cov_phi_exPV;
      fHandles[ "id_cov_theta_exPV" ] = &id_cov_theta_exPV;
      fHandles[ "id_cov_qoverp_exPV" ] = &id_cov_qoverp_exPV;
      fHandles[ "me_cov_d0_exPV" ] = &me_cov_d0_exPV;
      fHandles[ "me_cov_z0_exPV" ] = &me_cov_z0_exPV;
      fHandles[ "me_cov_phi_exPV" ] = &me_cov_phi_exPV;
      fHandles[ "me_cov_theta_exPV" ] = &me_cov_theta_exPV;
      fHandles[ "me_cov_qoverp_exPV" ] = &me_cov_qoverp_exPV;
      fHandles[ "ms_d0" ] = &ms_d0;
      fHandles[ "ms_z0" ] = &ms_z0;
      fHandles[ "ms_phi" ] = &ms_phi;
      fHandles[ "ms_theta" ] = &ms_theta;
      fHandles[ "ms_qoverp" ] = &ms_qoverp;
      fHandles[ "id_d0" ] = &id_d0;
      fHandles[ "id_z0" ] = &id_z0;
      fHandles[ "id_phi" ] = &id_phi;
      fHandles[ "id_theta" ] = &id_theta;
      fHandles[ "id_qoverp" ] = &id_qoverp;
      fHandles[ "me_d0" ] = &me_d0;
      fHandles[ "me_z0" ] = &me_z0;
      fHandles[ "me_phi" ] = &me_phi;
      fHandles[ "me_theta" ] = &me_theta;
      fHandles[ "me_qoverp" ] = &me_qoverp;
      fHandles[ "ie_d0" ] = &ie_d0;
      fHandles[ "ie_z0" ] = &ie_z0;
      fHandles[ "ie_phi" ] = &ie_phi;
      fHandles[ "ie_theta" ] = &ie_theta;
      fHandles[ "ie_qoverp" ] = &ie_qoverp;
      fHandles[ "nOutliersOnTrack" ] = &nOutliersOnTrack;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nTRTDeadStraws" ] = &nTRTDeadStraws;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nMDTHits" ] = &nMDTHits;
      fHandles[ "nMDTHoles" ] = &nMDTHoles;
      fHandles[ "nCSCEtaHits" ] = &nCSCEtaHits;
      fHandles[ "nCSCEtaHoles" ] = &nCSCEtaHoles;
      fHandles[ "nCSCPhiHits" ] = &nCSCPhiHits;
      fHandles[ "nCSCPhiHoles" ] = &nCSCPhiHoles;
      fHandles[ "nRPCEtaHits" ] = &nRPCEtaHits;
      fHandles[ "nRPCEtaHoles" ] = &nRPCEtaHoles;
      fHandles[ "nRPCPhiHits" ] = &nRPCPhiHits;
      fHandles[ "nRPCPhiHoles" ] = &nRPCPhiHoles;
      fHandles[ "nTGCEtaHits" ] = &nTGCEtaHits;
      fHandles[ "nTGCEtaHoles" ] = &nTGCEtaHoles;
      fHandles[ "nTGCPhiHits" ] = &nTGCPhiHits;
      fHandles[ "nTGCPhiHoles" ] = &nTGCPhiHoles;
      fHandles[ "nMDTBIHits" ] = &nMDTBIHits;
      fHandles[ "nMDTBMHits" ] = &nMDTBMHits;
      fHandles[ "nMDTBOHits" ] = &nMDTBOHits;
      fHandles[ "nMDTBEEHits" ] = &nMDTBEEHits;
      fHandles[ "nMDTBIS78Hits" ] = &nMDTBIS78Hits;
      fHandles[ "nMDTEIHits" ] = &nMDTEIHits;
      fHandles[ "nMDTEMHits" ] = &nMDTEMHits;
      fHandles[ "nMDTEOHits" ] = &nMDTEOHits;
      fHandles[ "nMDTEEHits" ] = &nMDTEEHits;
      fHandles[ "nRPCLayer1EtaHits" ] = &nRPCLayer1EtaHits;
      fHandles[ "nRPCLayer2EtaHits" ] = &nRPCLayer2EtaHits;
      fHandles[ "nRPCLayer3EtaHits" ] = &nRPCLayer3EtaHits;
      fHandles[ "nRPCLayer1PhiHits" ] = &nRPCLayer1PhiHits;
      fHandles[ "nRPCLayer2PhiHits" ] = &nRPCLayer2PhiHits;
      fHandles[ "nRPCLayer3PhiHits" ] = &nRPCLayer3PhiHits;
      fHandles[ "nTGCLayer1EtaHits" ] = &nTGCLayer1EtaHits;
      fHandles[ "nTGCLayer2EtaHits" ] = &nTGCLayer2EtaHits;
      fHandles[ "nTGCLayer3EtaHits" ] = &nTGCLayer3EtaHits;
      fHandles[ "nTGCLayer4EtaHits" ] = &nTGCLayer4EtaHits;
      fHandles[ "nTGCLayer1PhiHits" ] = &nTGCLayer1PhiHits;
      fHandles[ "nTGCLayer2PhiHits" ] = &nTGCLayer2PhiHits;
      fHandles[ "nTGCLayer3PhiHits" ] = &nTGCLayer3PhiHits;
      fHandles[ "nTGCLayer4PhiHits" ] = &nTGCLayer4PhiHits;
      fHandles[ "barrelSectors" ] = &barrelSectors;
      fHandles[ "endcapSectors" ] = &endcapSectors;
      fHandles[ "trackd0" ] = &trackd0;
      fHandles[ "trackz0" ] = &trackz0;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "tracktheta" ] = &tracktheta;
      fHandles[ "trackqoverp" ] = &trackqoverp;
      fHandles[ "trackcov_d0" ] = &trackcov_d0;
      fHandles[ "trackcov_z0" ] = &trackcov_z0;
      fHandles[ "trackcov_phi" ] = &trackcov_phi;
      fHandles[ "trackcov_theta" ] = &trackcov_theta;
      fHandles[ "trackcov_qoverp" ] = &trackcov_qoverp;
      fHandles[ "trackcov_d0_z0" ] = &trackcov_d0_z0;
      fHandles[ "trackcov_d0_phi" ] = &trackcov_d0_phi;
      fHandles[ "trackcov_d0_theta" ] = &trackcov_d0_theta;
      fHandles[ "trackcov_d0_qoverp" ] = &trackcov_d0_qoverp;
      fHandles[ "trackcov_z0_phi" ] = &trackcov_z0_phi;
      fHandles[ "trackcov_z0_theta" ] = &trackcov_z0_theta;
      fHandles[ "trackcov_z0_qoverp" ] = &trackcov_z0_qoverp;
      fHandles[ "trackcov_phi_theta" ] = &trackcov_phi_theta;
      fHandles[ "trackcov_phi_qoverp" ] = &trackcov_phi_qoverp;
      fHandles[ "trackcov_theta_qoverp" ] = &trackcov_theta_qoverp;
      fHandles[ "trackfitchi2" ] = &trackfitchi2;
      fHandles[ "trackfitndof" ] = &trackfitndof;
      fHandles[ "hastrack" ] = &hastrack;
      fHandles[ "trackd0beam" ] = &trackd0beam;
      fHandles[ "trackz0beam" ] = &trackz0beam;
      fHandles[ "tracksigd0beam" ] = &tracksigd0beam;
      fHandles[ "tracksigz0beam" ] = &tracksigz0beam;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackz0pv" ] = &trackz0pv;
      fHandles[ "tracksigd0pv" ] = &tracksigd0pv;
      fHandles[ "tracksigz0pv" ] = &tracksigz0pv;
      fHandles[ "trackIPEstimate_d0_biasedpvunbiased" ] = &trackIPEstimate_d0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_biasedpvunbiased" ] = &trackIPEstimate_z0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_biasedpvunbiased" ] = &trackIPEstimate_sigd0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_biasedpvunbiased" ] = &trackIPEstimate_sigz0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
      fHandles[ "trackd0pvunbiased" ] = &trackd0pvunbiased;
      fHandles[ "trackz0pvunbiased" ] = &trackz0pvunbiased;
      fHandles[ "tracksigd0pvunbiased" ] = &tracksigd0pvunbiased;
      fHandles[ "tracksigz0pvunbiased" ] = &tracksigz0pvunbiased;
      fHandles[ "truth_dr" ] = &truth_dr;
      fHandles[ "truth_matched" ] = &truth_matched;
      fHandles[ "EFCB_dr" ] = &EFCB_dr;
      //      fHandles[ "EFCB_n" ] = &EFCB_n;
      //      fHandles[ "EFCB_MuonType" ] = &EFCB_MuonType;
      //      fHandles[ "EFCB_pt" ] = &EFCB_pt;
      //      fHandles[ "EFCB_eta" ] = &EFCB_eta;
      //      fHandles[ "EFCB_phi" ] = &EFCB_phi;
      //      fHandles[ "EFCB_hasCB" ] = &EFCB_hasCB;
      //      fHandles[ "EFCB_matched" ] = &EFCB_matched;
      fHandles[ "EFMG_dr" ] = &EFMG_dr;
      //      fHandles[ "EFMG_n" ] = &EFMG_n;
      //      fHandles[ "EFMG_MuonType" ] = &EFMG_MuonType;
      //      fHandles[ "EFMG_pt" ] = &EFMG_pt;
      //      fHandles[ "EFMG_eta" ] = &EFMG_eta;
      //      fHandles[ "EFMG_phi" ] = &EFMG_phi;
      //      fHandles[ "EFMG_hasMG" ] = &EFMG_hasMG;
      //      fHandles[ "EFMG_matched" ] = &EFMG_matched;
      fHandles[ "EFME_dr" ] = &EFME_dr;
      //      fHandles[ "EFME_n" ] = &EFME_n;
      //      fHandles[ "EFME_MuonType" ] = &EFME_MuonType;
      //      fHandles[ "EFME_pt" ] = &EFME_pt;
      //      fHandles[ "EFME_eta" ] = &EFME_eta;
      //      fHandles[ "EFME_phi" ] = &EFME_phi;
      //      fHandles[ "EFME_hasME" ] = &EFME_hasME;
      //      fHandles[ "EFME_matched" ] = &EFME_matched;
      fHandles[ "L2CB_dr" ] = &L2CB_dr;
      fHandles[ "L2CB_pt" ] = &L2CB_pt;
      fHandles[ "L2CB_eta" ] = &L2CB_eta;
      fHandles[ "L2CB_phi" ] = &L2CB_phi;
      fHandles[ "L2CB_id_pt" ] = &L2CB_id_pt;
      fHandles[ "L2CB_ms_pt" ] = &L2CB_ms_pt;
      fHandles[ "L2CB_nPixHits" ] = &L2CB_nPixHits;
      fHandles[ "L2CB_nSCTHits" ] = &L2CB_nSCTHits;
      fHandles[ "L2CB_nTRTHits" ] = &L2CB_nTRTHits;
      fHandles[ "L2CB_nTRTHighTHits" ] = &L2CB_nTRTHighTHits;
      fHandles[ "L2CB_matched" ] = &L2CB_matched;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_pt" ] = &L1_pt;
      fHandles[ "L1_eta" ] = &L1_eta;
      fHandles[ "L1_phi" ] = &L1_phi;
      fHandles[ "L1_thrNumber" ] = &L1_thrNumber;
      fHandles[ "L1_RoINumber" ] = &L1_RoINumber;
      fHandles[ "L1_sectorAddress" ] = &L1_sectorAddress;
      fHandles[ "L1_firstCandidate" ] = &L1_firstCandidate;
      fHandles[ "L1_moreCandInRoI" ] = &L1_moreCandInRoI;
      fHandles[ "L1_moreCandInSector" ] = &L1_moreCandInSector;
      fHandles[ "L1_source" ] = &L1_source;
      fHandles[ "L1_hemisphere" ] = &L1_hemisphere;
      fHandles[ "L1_charge" ] = &L1_charge;
      fHandles[ "L1_vetoed" ] = &L1_vetoed;
      fHandles[ "L1_matched" ] = &L1_matched;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   MuonMuidD3PDObject::MuonMuidD3PDObject( const char* prefix )
      : TObject(),
        n( this, ::TString( prefix ) + "n", 0 ),
        E( this, ::TString( prefix ) + "E", 0 ),
        pt( this, ::TString( prefix ) + "pt", 0 ),
        m( this, ::TString( prefix ) + "m", 0 ),
        eta( this, ::TString( prefix ) + "eta", 0 ),
        phi( this, ::TString( prefix ) + "phi", 0 ),
        px( this, ::TString( prefix ) + "px", 0 ),
        py( this, ::TString( prefix ) + "py", 0 ),
        pz( this, ::TString( prefix ) + "pz", 0 ),
        charge( this, ::TString( prefix ) + "charge", 0 ),
        allauthor( this, ::TString( prefix ) + "allauthor", 0 ),
        author( this, ::TString( prefix ) + "author", 0 ),
        beta( this, ::TString( prefix ) + "beta", 0 ),
        isMuonLikelihood( this, ::TString( prefix ) + "isMuonLikelihood", 0 ),
        matchchi2( this, ::TString( prefix ) + "matchchi2", 0 ),
        matchndof( this, ::TString( prefix ) + "matchndof", 0 ),
        etcone20( this, ::TString( prefix ) + "etcone20", 0 ),
        etcone30( this, ::TString( prefix ) + "etcone30", 0 ),
        etcone40( this, ::TString( prefix ) + "etcone40", 0 ),
        nucone20( this, ::TString( prefix ) + "nucone20", 0 ),
        nucone30( this, ::TString( prefix ) + "nucone30", 0 ),
        nucone40( this, ::TString( prefix ) + "nucone40", 0 ),
        ptcone20( this, ::TString( prefix ) + "ptcone20", 0 ),
        ptcone30( this, ::TString( prefix ) + "ptcone30", 0 ),
        ptcone40( this, ::TString( prefix ) + "ptcone40", 0 ),
        energyLossPar( this, ::TString( prefix ) + "energyLossPar", 0 ),
        energyLossErr( this, ::TString( prefix ) + "energyLossErr", 0 ),
        etCore( this, ::TString( prefix ) + "etCore", 0 ),
        energyLossType( this, ::TString( prefix ) + "energyLossType", 0 ),
        caloMuonIdTag( this, ::TString( prefix ) + "caloMuonIdTag", 0 ),
        caloLRLikelihood( this, ::TString( prefix ) + "caloLRLikelihood", 0 ),
        bestMatch( this, ::TString( prefix ) + "bestMatch", 0 ),
        isStandAloneMuon( this, ::TString( prefix ) + "isStandAloneMuon", 0 ),
        isCombinedMuon( this, ::TString( prefix ) + "isCombinedMuon", 0 ),
        isLowPtReconstructedMuon( this, ::TString( prefix ) + "isLowPtReconstructedMuon", 0 ),
        isSegmentTaggedMuon( this, ::TString( prefix ) + "isSegmentTaggedMuon", 0 ),
        isCaloMuonId( this, ::TString( prefix ) + "isCaloMuonId", 0 ),
        alsoFoundByLowPt( this, ::TString( prefix ) + "alsoFoundByLowPt", 0 ),
        alsoFoundByCaloMuonId( this, ::TString( prefix ) + "alsoFoundByCaloMuonId", 0 ),
        loose( this, ::TString( prefix ) + "loose", 0 ),
        medium( this, ::TString( prefix ) + "medium", 0 ),
        tight( this, ::TString( prefix ) + "tight", 0 ),
        d0_exPV( this, ::TString( prefix ) + "d0_exPV", 0 ),
        z0_exPV( this, ::TString( prefix ) + "z0_exPV", 0 ),
        phi_exPV( this, ::TString( prefix ) + "phi_exPV", 0 ),
        theta_exPV( this, ::TString( prefix ) + "theta_exPV", 0 ),
        qoverp_exPV( this, ::TString( prefix ) + "qoverp_exPV", 0 ),
        cb_d0_exPV( this, ::TString( prefix ) + "cb_d0_exPV", 0 ),
        cb_z0_exPV( this, ::TString( prefix ) + "cb_z0_exPV", 0 ),
        cb_phi_exPV( this, ::TString( prefix ) + "cb_phi_exPV", 0 ),
        cb_theta_exPV( this, ::TString( prefix ) + "cb_theta_exPV", 0 ),
        cb_qoverp_exPV( this, ::TString( prefix ) + "cb_qoverp_exPV", 0 ),
        id_d0_exPV( this, ::TString( prefix ) + "id_d0_exPV", 0 ),
        id_z0_exPV( this, ::TString( prefix ) + "id_z0_exPV", 0 ),
        id_phi_exPV( this, ::TString( prefix ) + "id_phi_exPV", 0 ),
        id_theta_exPV( this, ::TString( prefix ) + "id_theta_exPV", 0 ),
        id_qoverp_exPV( this, ::TString( prefix ) + "id_qoverp_exPV", 0 ),
        me_d0_exPV( this, ::TString( prefix ) + "me_d0_exPV", 0 ),
        me_z0_exPV( this, ::TString( prefix ) + "me_z0_exPV", 0 ),
        me_phi_exPV( this, ::TString( prefix ) + "me_phi_exPV", 0 ),
        me_theta_exPV( this, ::TString( prefix ) + "me_theta_exPV", 0 ),
        me_qoverp_exPV( this, ::TString( prefix ) + "me_qoverp_exPV", 0 ),
        ie_d0_exPV( this, ::TString( prefix ) + "ie_d0_exPV", 0 ),
        ie_z0_exPV( this, ::TString( prefix ) + "ie_z0_exPV", 0 ),
        ie_phi_exPV( this, ::TString( prefix ) + "ie_phi_exPV", 0 ),
        ie_theta_exPV( this, ::TString( prefix ) + "ie_theta_exPV", 0 ),
        ie_qoverp_exPV( this, ::TString( prefix ) + "ie_qoverp_exPV", 0 ),
        SpaceTime_detID( this, ::TString( prefix ) + "SpaceTime_detID", 0 ),
        SpaceTime_t( this, ::TString( prefix ) + "SpaceTime_t", 0 ),
        SpaceTime_tError( this, ::TString( prefix ) + "SpaceTime_tError", 0 ),
        SpaceTime_weight( this, ::TString( prefix ) + "SpaceTime_weight", 0 ),
        SpaceTime_x( this, ::TString( prefix ) + "SpaceTime_x", 0 ),
        SpaceTime_y( this, ::TString( prefix ) + "SpaceTime_y", 0 ),
        SpaceTime_z( this, ::TString( prefix ) + "SpaceTime_z", 0 ),
        cov_d0_exPV( this, ::TString( prefix ) + "cov_d0_exPV", 0 ),
        cov_z0_exPV( this, ::TString( prefix ) + "cov_z0_exPV", 0 ),
        cov_phi_exPV( this, ::TString( prefix ) + "cov_phi_exPV", 0 ),
        cov_theta_exPV( this, ::TString( prefix ) + "cov_theta_exPV", 0 ),
        cov_qoverp_exPV( this, ::TString( prefix ) + "cov_qoverp_exPV", 0 ),
        cov_d0_z0_exPV( this, ::TString( prefix ) + "cov_d0_z0_exPV", 0 ),
        cov_d0_phi_exPV( this, ::TString( prefix ) + "cov_d0_phi_exPV", 0 ),
        cov_d0_theta_exPV( this, ::TString( prefix ) + "cov_d0_theta_exPV", 0 ),
        cov_d0_qoverp_exPV( this, ::TString( prefix ) + "cov_d0_qoverp_exPV", 0 ),
        cov_z0_phi_exPV( this, ::TString( prefix ) + "cov_z0_phi_exPV", 0 ),
        cov_z0_theta_exPV( this, ::TString( prefix ) + "cov_z0_theta_exPV", 0 ),
        cov_z0_qoverp_exPV( this, ::TString( prefix ) + "cov_z0_qoverp_exPV", 0 ),
        cov_phi_theta_exPV( this, ::TString( prefix ) + "cov_phi_theta_exPV", 0 ),
        cov_phi_qoverp_exPV( this, ::TString( prefix ) + "cov_phi_qoverp_exPV", 0 ),
        cov_theta_qoverp_exPV( this, ::TString( prefix ) + "cov_theta_qoverp_exPV", 0 ),
        id_cov_d0_exPV( this, ::TString( prefix ) + "id_cov_d0_exPV", 0 ),
        id_cov_z0_exPV( this, ::TString( prefix ) + "id_cov_z0_exPV", 0 ),
        id_cov_phi_exPV( this, ::TString( prefix ) + "id_cov_phi_exPV", 0 ),
        id_cov_theta_exPV( this, ::TString( prefix ) + "id_cov_theta_exPV", 0 ),
        id_cov_qoverp_exPV( this, ::TString( prefix ) + "id_cov_qoverp_exPV", 0 ),
        me_cov_d0_exPV( this, ::TString( prefix ) + "me_cov_d0_exPV", 0 ),
        me_cov_z0_exPV( this, ::TString( prefix ) + "me_cov_z0_exPV", 0 ),
        me_cov_phi_exPV( this, ::TString( prefix ) + "me_cov_phi_exPV", 0 ),
        me_cov_theta_exPV( this, ::TString( prefix ) + "me_cov_theta_exPV", 0 ),
        me_cov_qoverp_exPV( this, ::TString( prefix ) + "me_cov_qoverp_exPV", 0 ),
        ms_d0( this, ::TString( prefix ) + "ms_d0", 0 ),
        ms_z0( this, ::TString( prefix ) + "ms_z0", 0 ),
        ms_phi( this, ::TString( prefix ) + "ms_phi", 0 ),
        ms_theta( this, ::TString( prefix ) + "ms_theta", 0 ),
        ms_qoverp( this, ::TString( prefix ) + "ms_qoverp", 0 ),
        id_d0( this, ::TString( prefix ) + "id_d0", 0 ),
        id_z0( this, ::TString( prefix ) + "id_z0", 0 ),
        id_phi( this, ::TString( prefix ) + "id_phi", 0 ),
        id_theta( this, ::TString( prefix ) + "id_theta", 0 ),
        id_qoverp( this, ::TString( prefix ) + "id_qoverp", 0 ),
        me_d0( this, ::TString( prefix ) + "me_d0", 0 ),
        me_z0( this, ::TString( prefix ) + "me_z0", 0 ),
        me_phi( this, ::TString( prefix ) + "me_phi", 0 ),
        me_theta( this, ::TString( prefix ) + "me_theta", 0 ),
        me_qoverp( this, ::TString( prefix ) + "me_qoverp", 0 ),
        ie_d0( this, ::TString( prefix ) + "ie_d0", 0 ),
        ie_z0( this, ::TString( prefix ) + "ie_z0", 0 ),
        ie_phi( this, ::TString( prefix ) + "ie_phi", 0 ),
        ie_theta( this, ::TString( prefix ) + "ie_theta", 0 ),
        ie_qoverp( this, ::TString( prefix ) + "ie_qoverp", 0 ),
        nOutliersOnTrack( this, ::TString( prefix ) + "nOutliersOnTrack", 0 ),
        nBLHits( this, ::TString( prefix ) + "nBLHits", 0 ),
        nPixHits( this, ::TString( prefix ) + "nPixHits", 0 ),
        nSCTHits( this, ::TString( prefix ) + "nSCTHits", 0 ),
        nTRTHits( this, ::TString( prefix ) + "nTRTHits", 0 ),
        nTRTHighTHits( this, ::TString( prefix ) + "nTRTHighTHits", 0 ),
        nBLSharedHits( this, ::TString( prefix ) + "nBLSharedHits", 0 ),
        nPixSharedHits( this, ::TString( prefix ) + "nPixSharedHits", 0 ),
        nPixHoles( this, ::TString( prefix ) + "nPixHoles", 0 ),
        nSCTSharedHits( this, ::TString( prefix ) + "nSCTSharedHits", 0 ),
        nSCTHoles( this, ::TString( prefix ) + "nSCTHoles", 0 ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", 0 ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", 0 ),
        nGangedPixels( this, ::TString( prefix ) + "nGangedPixels", 0 ),
        nPixelDeadSensors( this, ::TString( prefix ) + "nPixelDeadSensors", 0 ),
        nSCTDeadSensors( this, ::TString( prefix ) + "nSCTDeadSensors", 0 ),
        nTRTDeadStraws( this, ::TString( prefix ) + "nTRTDeadStraws", 0 ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", 0 ),
        nMDTHits( this, ::TString( prefix ) + "nMDTHits", 0 ),
        nMDTHoles( this, ::TString( prefix ) + "nMDTHoles", 0 ),
        nCSCEtaHits( this, ::TString( prefix ) + "nCSCEtaHits", 0 ),
        nCSCEtaHoles( this, ::TString( prefix ) + "nCSCEtaHoles", 0 ),
        nCSCPhiHits( this, ::TString( prefix ) + "nCSCPhiHits", 0 ),
        nCSCPhiHoles( this, ::TString( prefix ) + "nCSCPhiHoles", 0 ),
        nRPCEtaHits( this, ::TString( prefix ) + "nRPCEtaHits", 0 ),
        nRPCEtaHoles( this, ::TString( prefix ) + "nRPCEtaHoles", 0 ),
        nRPCPhiHits( this, ::TString( prefix ) + "nRPCPhiHits", 0 ),
        nRPCPhiHoles( this, ::TString( prefix ) + "nRPCPhiHoles", 0 ),
        nTGCEtaHits( this, ::TString( prefix ) + "nTGCEtaHits", 0 ),
        nTGCEtaHoles( this, ::TString( prefix ) + "nTGCEtaHoles", 0 ),
        nTGCPhiHits( this, ::TString( prefix ) + "nTGCPhiHits", 0 ),
        nTGCPhiHoles( this, ::TString( prefix ) + "nTGCPhiHoles", 0 ),
        nMDTBIHits( this, ::TString( prefix ) + "nMDTBIHits", 0 ),
        nMDTBMHits( this, ::TString( prefix ) + "nMDTBMHits", 0 ),
        nMDTBOHits( this, ::TString( prefix ) + "nMDTBOHits", 0 ),
        nMDTBEEHits( this, ::TString( prefix ) + "nMDTBEEHits", 0 ),
        nMDTBIS78Hits( this, ::TString( prefix ) + "nMDTBIS78Hits", 0 ),
        nMDTEIHits( this, ::TString( prefix ) + "nMDTEIHits", 0 ),
        nMDTEMHits( this, ::TString( prefix ) + "nMDTEMHits", 0 ),
        nMDTEOHits( this, ::TString( prefix ) + "nMDTEOHits", 0 ),
        nMDTEEHits( this, ::TString( prefix ) + "nMDTEEHits", 0 ),
        nRPCLayer1EtaHits( this, ::TString( prefix ) + "nRPCLayer1EtaHits", 0 ),
        nRPCLayer2EtaHits( this, ::TString( prefix ) + "nRPCLayer2EtaHits", 0 ),
        nRPCLayer3EtaHits( this, ::TString( prefix ) + "nRPCLayer3EtaHits", 0 ),
        nRPCLayer1PhiHits( this, ::TString( prefix ) + "nRPCLayer1PhiHits", 0 ),
        nRPCLayer2PhiHits( this, ::TString( prefix ) + "nRPCLayer2PhiHits", 0 ),
        nRPCLayer3PhiHits( this, ::TString( prefix ) + "nRPCLayer3PhiHits", 0 ),
        nTGCLayer1EtaHits( this, ::TString( prefix ) + "nTGCLayer1EtaHits", 0 ),
        nTGCLayer2EtaHits( this, ::TString( prefix ) + "nTGCLayer2EtaHits", 0 ),
        nTGCLayer3EtaHits( this, ::TString( prefix ) + "nTGCLayer3EtaHits", 0 ),
        nTGCLayer4EtaHits( this, ::TString( prefix ) + "nTGCLayer4EtaHits", 0 ),
        nTGCLayer1PhiHits( this, ::TString( prefix ) + "nTGCLayer1PhiHits", 0 ),
        nTGCLayer2PhiHits( this, ::TString( prefix ) + "nTGCLayer2PhiHits", 0 ),
        nTGCLayer3PhiHits( this, ::TString( prefix ) + "nTGCLayer3PhiHits", 0 ),
        nTGCLayer4PhiHits( this, ::TString( prefix ) + "nTGCLayer4PhiHits", 0 ),
        barrelSectors( this, ::TString( prefix ) + "barrelSectors", 0 ),
        endcapSectors( this, ::TString( prefix ) + "endcapSectors", 0 ),
        trackd0( this, ::TString( prefix ) + "trackd0", 0 ),
        trackz0( this, ::TString( prefix ) + "trackz0", 0 ),
        trackphi( this, ::TString( prefix ) + "trackphi", 0 ),
        tracktheta( this, ::TString( prefix ) + "tracktheta", 0 ),
        trackqoverp( this, ::TString( prefix ) + "trackqoverp", 0 ),
        trackcov_d0( this, ::TString( prefix ) + "trackcov_d0", 0 ),
        trackcov_z0( this, ::TString( prefix ) + "trackcov_z0", 0 ),
        trackcov_phi( this, ::TString( prefix ) + "trackcov_phi", 0 ),
        trackcov_theta( this, ::TString( prefix ) + "trackcov_theta", 0 ),
        trackcov_qoverp( this, ::TString( prefix ) + "trackcov_qoverp", 0 ),
        trackcov_d0_z0( this, ::TString( prefix ) + "trackcov_d0_z0", 0 ),
        trackcov_d0_phi( this, ::TString( prefix ) + "trackcov_d0_phi", 0 ),
        trackcov_d0_theta( this, ::TString( prefix ) + "trackcov_d0_theta", 0 ),
        trackcov_d0_qoverp( this, ::TString( prefix ) + "trackcov_d0_qoverp", 0 ),
        trackcov_z0_phi( this, ::TString( prefix ) + "trackcov_z0_phi", 0 ),
        trackcov_z0_theta( this, ::TString( prefix ) + "trackcov_z0_theta", 0 ),
        trackcov_z0_qoverp( this, ::TString( prefix ) + "trackcov_z0_qoverp", 0 ),
        trackcov_phi_theta( this, ::TString( prefix ) + "trackcov_phi_theta", 0 ),
        trackcov_phi_qoverp( this, ::TString( prefix ) + "trackcov_phi_qoverp", 0 ),
        trackcov_theta_qoverp( this, ::TString( prefix ) + "trackcov_theta_qoverp", 0 ),
        trackfitchi2( this, ::TString( prefix ) + "trackfitchi2", 0 ),
        trackfitndof( this, ::TString( prefix ) + "trackfitndof", 0 ),
        hastrack( this, ::TString( prefix ) + "hastrack", 0 ),
        trackd0beam( this, ::TString( prefix ) + "trackd0beam", 0 ),
        trackz0beam( this, ::TString( prefix ) + "trackz0beam", 0 ),
        tracksigd0beam( this, ::TString( prefix ) + "tracksigd0beam", 0 ),
        tracksigz0beam( this, ::TString( prefix ) + "tracksigz0beam", 0 ),
        trackd0pv( this, ::TString( prefix ) + "trackd0pv", 0 ),
        trackz0pv( this, ::TString( prefix ) + "trackz0pv", 0 ),
        tracksigd0pv( this, ::TString( prefix ) + "tracksigd0pv", 0 ),
        tracksigz0pv( this, ::TString( prefix ) + "tracksigz0pv", 0 ),
        trackIPEstimate_d0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_biasedpvunbiased", 0 ),
        trackIPEstimate_z0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_biasedpvunbiased", 0 ),
        trackIPEstimate_sigd0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_biasedpvunbiased", 0 ),
        trackIPEstimate_sigz0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_biasedpvunbiased", 0 ),
        trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased", 0 ),
        trackd0pvunbiased( this, ::TString( prefix ) + "trackd0pvunbiased", 0 ),
        trackz0pvunbiased( this, ::TString( prefix ) + "trackz0pvunbiased", 0 ),
        tracksigd0pvunbiased( this, ::TString( prefix ) + "tracksigd0pvunbiased", 0 ),
        tracksigz0pvunbiased( this, ::TString( prefix ) + "tracksigz0pvunbiased", 0 ),
        truth_dr( this, ::TString( prefix ) + "truth_dr", 0 ),
        truth_matched( this, ::TString( prefix ) + "truth_matched", 0 ),
        EFCB_dr( this, ::TString( prefix ) + "EFCB_dr", 0 ),
	//        EFCB_n( this, ::TString( prefix ) + "EFCB_n", 0 ),
	//        EFCB_MuonType( this, ::TString( prefix ) + "EFCB_MuonType", 0 ),
	//        EFCB_pt( this, ::TString( prefix ) + "EFCB_pt", 0 ),
	//        EFCB_eta( this, ::TString( prefix ) + "EFCB_eta", 0 ),
	//        EFCB_phi( this, ::TString( prefix ) + "EFCB_phi", 0 ),
	//        EFCB_hasCB( this, ::TString( prefix ) + "EFCB_hasCB", 0 ),
	//        EFCB_matched( this, ::TString( prefix ) + "EFCB_matched", 0 ),
        EFMG_dr( this, ::TString( prefix ) + "EFMG_dr", 0 ),
	//        EFMG_n( this, ::TString( prefix ) + "EFMG_n", 0 ),
	//        EFMG_MuonType( this, ::TString( prefix ) + "EFMG_MuonType", 0 ),
	//        EFMG_pt( this, ::TString( prefix ) + "EFMG_pt", 0 ),
	//        EFMG_eta( this, ::TString( prefix ) + "EFMG_eta", 0 ),
	//        EFMG_phi( this, ::TString( prefix ) + "EFMG_phi", 0 ),
	//        EFMG_hasMG( this, ::TString( prefix ) + "EFMG_hasMG", 0 ),
	//        EFMG_matched( this, ::TString( prefix ) + "EFMG_matched", 0 ),
        EFME_dr( this, ::TString( prefix ) + "EFME_dr", 0 ),
	//        EFME_n( this, ::TString( prefix ) + "EFME_n", 0 ),
	//        EFME_MuonType( this, ::TString( prefix ) + "EFME_MuonType", 0 ),
	//        EFME_pt( this, ::TString( prefix ) + "EFME_pt", 0 ),
	//        EFME_eta( this, ::TString( prefix ) + "EFME_eta", 0 ),
	//        EFME_phi( this, ::TString( prefix ) + "EFME_phi", 0 ),
	//        EFME_hasME( this, ::TString( prefix ) + "EFME_hasME", 0 ),
	//        EFME_matched( this, ::TString( prefix ) + "EFME_matched", 0 ),
        L2CB_dr( this, ::TString( prefix ) + "L2CB_dr", 0 ),
	L2CB_pt( this, ::TString( prefix ) + "L2CB_pt", 0 ),
        L2CB_eta( this, ::TString( prefix ) + "L2CB_eta", 0 ),
        L2CB_phi( this, ::TString( prefix ) + "L2CB_phi", 0 ),
        L2CB_id_pt( this, ::TString( prefix ) + "L2CB_id_pt", 0 ),
        L2CB_ms_pt( this, ::TString( prefix ) + "L2CB_ms_pt", 0 ),
        L2CB_nPixHits( this, ::TString( prefix ) + "L2CB_nPixHits", 0 ),
        L2CB_nSCTHits( this, ::TString( prefix ) + "L2CB_nSCTHits", 0 ),
        L2CB_nTRTHits( this, ::TString( prefix ) + "L2CB_nTRTHits", 0 ),
        L2CB_nTRTHighTHits( this, ::TString( prefix ) + "L2CB_nTRTHighTHits", 0 ),
        L2CB_matched( this, ::TString( prefix ) + "L2CB_matched", 0 ),
        L1_dr( this, ::TString( prefix ) + "L1_dr", 0 ),
        L1_pt( this, ::TString( prefix ) + "L1_pt", 0 ),
        L1_eta( this, ::TString( prefix ) + "L1_eta", 0 ),
        L1_phi( this, ::TString( prefix ) + "L1_phi", 0 ),
        L1_thrNumber( this, ::TString( prefix ) + "L1_thrNumber", 0 ),
        L1_RoINumber( this, ::TString( prefix ) + "L1_RoINumber", 0 ),
        L1_sectorAddress( this, ::TString( prefix ) + "L1_sectorAddress", 0 ),
        L1_firstCandidate( this, ::TString( prefix ) + "L1_firstCandidate", 0 ),
        L1_moreCandInRoI( this, ::TString( prefix ) + "L1_moreCandInRoI", 0 ),
        L1_moreCandInSector( this, ::TString( prefix ) + "L1_moreCandInSector", 0 ),
        L1_source( this, ::TString( prefix ) + "L1_source", 0 ),
        L1_hemisphere( this, ::TString( prefix ) + "L1_hemisphere", 0 ),
        L1_charge( this, ::TString( prefix ) + "L1_charge", 0 ),
        L1_vetoed( this, ::TString( prefix ) + "L1_vetoed", 0 ),
        L1_matched( this, ::TString( prefix ) + "L1_matched", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "charge" ] = &charge;
      fHandles[ "allauthor" ] = &allauthor;
      fHandles[ "author" ] = &author;
      fHandles[ "beta" ] = &beta;
      fHandles[ "isMuonLikelihood" ] = &isMuonLikelihood;
      fHandles[ "matchchi2" ] = &matchchi2;
      fHandles[ "matchndof" ] = &matchndof;
      fHandles[ "etcone20" ] = &etcone20;
      fHandles[ "etcone30" ] = &etcone30;
      fHandles[ "etcone40" ] = &etcone40;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "energyLossPar" ] = &energyLossPar;
      fHandles[ "energyLossErr" ] = &energyLossErr;
      fHandles[ "etCore" ] = &etCore;
      fHandles[ "energyLossType" ] = &energyLossType;
      fHandles[ "caloMuonIdTag" ] = &caloMuonIdTag;
      fHandles[ "caloLRLikelihood" ] = &caloLRLikelihood;
      fHandles[ "bestMatch" ] = &bestMatch;
      fHandles[ "isStandAloneMuon" ] = &isStandAloneMuon;
      fHandles[ "isCombinedMuon" ] = &isCombinedMuon;
      fHandles[ "isLowPtReconstructedMuon" ] = &isLowPtReconstructedMuon;
      fHandles[ "isSegmentTaggedMuon" ] = &isSegmentTaggedMuon;
      fHandles[ "isCaloMuonId" ] = &isCaloMuonId;
      fHandles[ "alsoFoundByLowPt" ] = &alsoFoundByLowPt;
      fHandles[ "alsoFoundByCaloMuonId" ] = &alsoFoundByCaloMuonId;
      fHandles[ "loose" ] = &loose;
      fHandles[ "medium" ] = &medium;
      fHandles[ "tight" ] = &tight;
      fHandles[ "d0_exPV" ] = &d0_exPV;
      fHandles[ "z0_exPV" ] = &z0_exPV;
      fHandles[ "phi_exPV" ] = &phi_exPV;
      fHandles[ "theta_exPV" ] = &theta_exPV;
      fHandles[ "qoverp_exPV" ] = &qoverp_exPV;
      fHandles[ "cb_d0_exPV" ] = &cb_d0_exPV;
      fHandles[ "cb_z0_exPV" ] = &cb_z0_exPV;
      fHandles[ "cb_phi_exPV" ] = &cb_phi_exPV;
      fHandles[ "cb_theta_exPV" ] = &cb_theta_exPV;
      fHandles[ "cb_qoverp_exPV" ] = &cb_qoverp_exPV;
      fHandles[ "id_d0_exPV" ] = &id_d0_exPV;
      fHandles[ "id_z0_exPV" ] = &id_z0_exPV;
      fHandles[ "id_phi_exPV" ] = &id_phi_exPV;
      fHandles[ "id_theta_exPV" ] = &id_theta_exPV;
      fHandles[ "id_qoverp_exPV" ] = &id_qoverp_exPV;
      fHandles[ "me_d0_exPV" ] = &me_d0_exPV;
      fHandles[ "me_z0_exPV" ] = &me_z0_exPV;
      fHandles[ "me_phi_exPV" ] = &me_phi_exPV;
      fHandles[ "me_theta_exPV" ] = &me_theta_exPV;
      fHandles[ "me_qoverp_exPV" ] = &me_qoverp_exPV;
      fHandles[ "ie_d0_exPV" ] = &ie_d0_exPV;
      fHandles[ "ie_z0_exPV" ] = &ie_z0_exPV;
      fHandles[ "ie_phi_exPV" ] = &ie_phi_exPV;
      fHandles[ "ie_theta_exPV" ] = &ie_theta_exPV;
      fHandles[ "ie_qoverp_exPV" ] = &ie_qoverp_exPV;
      fHandles[ "SpaceTime_detID" ] = &SpaceTime_detID;
      fHandles[ "SpaceTime_t" ] = &SpaceTime_t;
      fHandles[ "SpaceTime_tError" ] = &SpaceTime_tError;
      fHandles[ "SpaceTime_weight" ] = &SpaceTime_weight;
      fHandles[ "SpaceTime_x" ] = &SpaceTime_x;
      fHandles[ "SpaceTime_y" ] = &SpaceTime_y;
      fHandles[ "SpaceTime_z" ] = &SpaceTime_z;
      fHandles[ "cov_d0_exPV" ] = &cov_d0_exPV;
      fHandles[ "cov_z0_exPV" ] = &cov_z0_exPV;
      fHandles[ "cov_phi_exPV" ] = &cov_phi_exPV;
      fHandles[ "cov_theta_exPV" ] = &cov_theta_exPV;
      fHandles[ "cov_qoverp_exPV" ] = &cov_qoverp_exPV;
      fHandles[ "cov_d0_z0_exPV" ] = &cov_d0_z0_exPV;
      fHandles[ "cov_d0_phi_exPV" ] = &cov_d0_phi_exPV;
      fHandles[ "cov_d0_theta_exPV" ] = &cov_d0_theta_exPV;
      fHandles[ "cov_d0_qoverp_exPV" ] = &cov_d0_qoverp_exPV;
      fHandles[ "cov_z0_phi_exPV" ] = &cov_z0_phi_exPV;
      fHandles[ "cov_z0_theta_exPV" ] = &cov_z0_theta_exPV;
      fHandles[ "cov_z0_qoverp_exPV" ] = &cov_z0_qoverp_exPV;
      fHandles[ "cov_phi_theta_exPV" ] = &cov_phi_theta_exPV;
      fHandles[ "cov_phi_qoverp_exPV" ] = &cov_phi_qoverp_exPV;
      fHandles[ "cov_theta_qoverp_exPV" ] = &cov_theta_qoverp_exPV;
      fHandles[ "id_cov_d0_exPV" ] = &id_cov_d0_exPV;
      fHandles[ "id_cov_z0_exPV" ] = &id_cov_z0_exPV;
      fHandles[ "id_cov_phi_exPV" ] = &id_cov_phi_exPV;
      fHandles[ "id_cov_theta_exPV" ] = &id_cov_theta_exPV;
      fHandles[ "id_cov_qoverp_exPV" ] = &id_cov_qoverp_exPV;
      fHandles[ "me_cov_d0_exPV" ] = &me_cov_d0_exPV;
      fHandles[ "me_cov_z0_exPV" ] = &me_cov_z0_exPV;
      fHandles[ "me_cov_phi_exPV" ] = &me_cov_phi_exPV;
      fHandles[ "me_cov_theta_exPV" ] = &me_cov_theta_exPV;
      fHandles[ "me_cov_qoverp_exPV" ] = &me_cov_qoverp_exPV;
      fHandles[ "ms_d0" ] = &ms_d0;
      fHandles[ "ms_z0" ] = &ms_z0;
      fHandles[ "ms_phi" ] = &ms_phi;
      fHandles[ "ms_theta" ] = &ms_theta;
      fHandles[ "ms_qoverp" ] = &ms_qoverp;
      fHandles[ "id_d0" ] = &id_d0;
      fHandles[ "id_z0" ] = &id_z0;
      fHandles[ "id_phi" ] = &id_phi;
      fHandles[ "id_theta" ] = &id_theta;
      fHandles[ "id_qoverp" ] = &id_qoverp;
      fHandles[ "me_d0" ] = &me_d0;
      fHandles[ "me_z0" ] = &me_z0;
      fHandles[ "me_phi" ] = &me_phi;
      fHandles[ "me_theta" ] = &me_theta;
      fHandles[ "me_qoverp" ] = &me_qoverp;
      fHandles[ "ie_d0" ] = &ie_d0;
      fHandles[ "ie_z0" ] = &ie_z0;
      fHandles[ "ie_phi" ] = &ie_phi;
      fHandles[ "ie_theta" ] = &ie_theta;
      fHandles[ "ie_qoverp" ] = &ie_qoverp;
      fHandles[ "nOutliersOnTrack" ] = &nOutliersOnTrack;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nTRTDeadStraws" ] = &nTRTDeadStraws;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nMDTHits" ] = &nMDTHits;
      fHandles[ "nMDTHoles" ] = &nMDTHoles;
      fHandles[ "nCSCEtaHits" ] = &nCSCEtaHits;
      fHandles[ "nCSCEtaHoles" ] = &nCSCEtaHoles;
      fHandles[ "nCSCPhiHits" ] = &nCSCPhiHits;
      fHandles[ "nCSCPhiHoles" ] = &nCSCPhiHoles;
      fHandles[ "nRPCEtaHits" ] = &nRPCEtaHits;
      fHandles[ "nRPCEtaHoles" ] = &nRPCEtaHoles;
      fHandles[ "nRPCPhiHits" ] = &nRPCPhiHits;
      fHandles[ "nRPCPhiHoles" ] = &nRPCPhiHoles;
      fHandles[ "nTGCEtaHits" ] = &nTGCEtaHits;
      fHandles[ "nTGCEtaHoles" ] = &nTGCEtaHoles;
      fHandles[ "nTGCPhiHits" ] = &nTGCPhiHits;
      fHandles[ "nTGCPhiHoles" ] = &nTGCPhiHoles;
      fHandles[ "nMDTBIHits" ] = &nMDTBIHits;
      fHandles[ "nMDTBMHits" ] = &nMDTBMHits;
      fHandles[ "nMDTBOHits" ] = &nMDTBOHits;
      fHandles[ "nMDTBEEHits" ] = &nMDTBEEHits;
      fHandles[ "nMDTBIS78Hits" ] = &nMDTBIS78Hits;
      fHandles[ "nMDTEIHits" ] = &nMDTEIHits;
      fHandles[ "nMDTEMHits" ] = &nMDTEMHits;
      fHandles[ "nMDTEOHits" ] = &nMDTEOHits;
      fHandles[ "nMDTEEHits" ] = &nMDTEEHits;
      fHandles[ "nRPCLayer1EtaHits" ] = &nRPCLayer1EtaHits;
      fHandles[ "nRPCLayer2EtaHits" ] = &nRPCLayer2EtaHits;
      fHandles[ "nRPCLayer3EtaHits" ] = &nRPCLayer3EtaHits;
      fHandles[ "nRPCLayer1PhiHits" ] = &nRPCLayer1PhiHits;
      fHandles[ "nRPCLayer2PhiHits" ] = &nRPCLayer2PhiHits;
      fHandles[ "nRPCLayer3PhiHits" ] = &nRPCLayer3PhiHits;
      fHandles[ "nTGCLayer1EtaHits" ] = &nTGCLayer1EtaHits;
      fHandles[ "nTGCLayer2EtaHits" ] = &nTGCLayer2EtaHits;
      fHandles[ "nTGCLayer3EtaHits" ] = &nTGCLayer3EtaHits;
      fHandles[ "nTGCLayer4EtaHits" ] = &nTGCLayer4EtaHits;
      fHandles[ "nTGCLayer1PhiHits" ] = &nTGCLayer1PhiHits;
      fHandles[ "nTGCLayer2PhiHits" ] = &nTGCLayer2PhiHits;
      fHandles[ "nTGCLayer3PhiHits" ] = &nTGCLayer3PhiHits;
      fHandles[ "nTGCLayer4PhiHits" ] = &nTGCLayer4PhiHits;
      fHandles[ "barrelSectors" ] = &barrelSectors;
      fHandles[ "endcapSectors" ] = &endcapSectors;
      fHandles[ "trackd0" ] = &trackd0;
      fHandles[ "trackz0" ] = &trackz0;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "tracktheta" ] = &tracktheta;
      fHandles[ "trackqoverp" ] = &trackqoverp;
      fHandles[ "trackcov_d0" ] = &trackcov_d0;
      fHandles[ "trackcov_z0" ] = &trackcov_z0;
      fHandles[ "trackcov_phi" ] = &trackcov_phi;
      fHandles[ "trackcov_theta" ] = &trackcov_theta;
      fHandles[ "trackcov_qoverp" ] = &trackcov_qoverp;
      fHandles[ "trackcov_d0_z0" ] = &trackcov_d0_z0;
      fHandles[ "trackcov_d0_phi" ] = &trackcov_d0_phi;
      fHandles[ "trackcov_d0_theta" ] = &trackcov_d0_theta;
      fHandles[ "trackcov_d0_qoverp" ] = &trackcov_d0_qoverp;
      fHandles[ "trackcov_z0_phi" ] = &trackcov_z0_phi;
      fHandles[ "trackcov_z0_theta" ] = &trackcov_z0_theta;
      fHandles[ "trackcov_z0_qoverp" ] = &trackcov_z0_qoverp;
      fHandles[ "trackcov_phi_theta" ] = &trackcov_phi_theta;
      fHandles[ "trackcov_phi_qoverp" ] = &trackcov_phi_qoverp;
      fHandles[ "trackcov_theta_qoverp" ] = &trackcov_theta_qoverp;
      fHandles[ "trackfitchi2" ] = &trackfitchi2;
      fHandles[ "trackfitndof" ] = &trackfitndof;
      fHandles[ "hastrack" ] = &hastrack;
      fHandles[ "trackd0beam" ] = &trackd0beam;
      fHandles[ "trackz0beam" ] = &trackz0beam;
      fHandles[ "tracksigd0beam" ] = &tracksigd0beam;
      fHandles[ "tracksigz0beam" ] = &tracksigz0beam;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackz0pv" ] = &trackz0pv;
      fHandles[ "tracksigd0pv" ] = &tracksigd0pv;
      fHandles[ "tracksigz0pv" ] = &tracksigz0pv;
      fHandles[ "trackIPEstimate_d0_biasedpvunbiased" ] = &trackIPEstimate_d0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_biasedpvunbiased" ] = &trackIPEstimate_z0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_biasedpvunbiased" ] = &trackIPEstimate_sigd0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_biasedpvunbiased" ] = &trackIPEstimate_sigz0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
      fHandles[ "trackd0pvunbiased" ] = &trackd0pvunbiased;
      fHandles[ "trackz0pvunbiased" ] = &trackz0pvunbiased;
      fHandles[ "tracksigd0pvunbiased" ] = &tracksigd0pvunbiased;
      fHandles[ "tracksigz0pvunbiased" ] = &tracksigz0pvunbiased;
      fHandles[ "truth_dr" ] = &truth_dr;
      fHandles[ "truth_matched" ] = &truth_matched;
      fHandles[ "EFCB_dr" ] = &EFCB_dr;
      //      fHandles[ "EFCB_n" ] = &EFCB_n;
      //      fHandles[ "EFCB_MuonType" ] = &EFCB_MuonType;
      //      fHandles[ "EFCB_pt" ] = &EFCB_pt;
      //      fHandles[ "EFCB_eta" ] = &EFCB_eta;
      //      fHandles[ "EFCB_phi" ] = &EFCB_phi;
      //      fHandles[ "EFCB_hasCB" ] = &EFCB_hasCB;
      //      fHandles[ "EFCB_matched" ] = &EFCB_matched;
      fHandles[ "EFMG_dr" ] = &EFMG_dr;
//       fHandles[ "EFMG_n" ] = &EFMG_n;
//       fHandles[ "EFMG_MuonType" ] = &EFMG_MuonType;
//       fHandles[ "EFMG_pt" ] = &EFMG_pt;
//       fHandles[ "EFMG_eta" ] = &EFMG_eta;
//       fHandles[ "EFMG_phi" ] = &EFMG_phi;
//       fHandles[ "EFMG_hasMG" ] = &EFMG_hasMG;
//       fHandles[ "EFMG_matched" ] = &EFMG_matched;
      fHandles[ "EFME_dr" ] = &EFME_dr;
//       fHandles[ "EFME_n" ] = &EFME_n;
//       fHandles[ "EFME_MuonType" ] = &EFME_MuonType;
//       fHandles[ "EFME_pt" ] = &EFME_pt;
//       fHandles[ "EFME_eta" ] = &EFME_eta;
//       fHandles[ "EFME_phi" ] = &EFME_phi;
//       fHandles[ "EFME_hasME" ] = &EFME_hasME;
//       fHandles[ "EFME_matched" ] = &EFME_matched;
      fHandles[ "L2CB_dr" ] = &L2CB_dr;
      fHandles[ "L2CB_pt" ] = &L2CB_pt;
      fHandles[ "L2CB_eta" ] = &L2CB_eta;
      fHandles[ "L2CB_phi" ] = &L2CB_phi;
      fHandles[ "L2CB_id_pt" ] = &L2CB_id_pt;
      fHandles[ "L2CB_ms_pt" ] = &L2CB_ms_pt;
      fHandles[ "L2CB_nPixHits" ] = &L2CB_nPixHits;
      fHandles[ "L2CB_nSCTHits" ] = &L2CB_nSCTHits;
      fHandles[ "L2CB_nTRTHits" ] = &L2CB_nTRTHits;
      fHandles[ "L2CB_nTRTHighTHits" ] = &L2CB_nTRTHighTHits;
      fHandles[ "L2CB_matched" ] = &L2CB_matched;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_pt" ] = &L1_pt;
      fHandles[ "L1_eta" ] = &L1_eta;
      fHandles[ "L1_phi" ] = &L1_phi;
      fHandles[ "L1_thrNumber" ] = &L1_thrNumber;
      fHandles[ "L1_RoINumber" ] = &L1_RoINumber;
      fHandles[ "L1_sectorAddress" ] = &L1_sectorAddress;
      fHandles[ "L1_firstCandidate" ] = &L1_firstCandidate;
      fHandles[ "L1_moreCandInRoI" ] = &L1_moreCandInRoI;
      fHandles[ "L1_moreCandInSector" ] = &L1_moreCandInSector;
      fHandles[ "L1_source" ] = &L1_source;
      fHandles[ "L1_hemisphere" ] = &L1_hemisphere;
      fHandles[ "L1_charge" ] = &L1_charge;
      fHandles[ "L1_vetoed" ] = &L1_vetoed;
      fHandles[ "L1_matched" ] = &L1_matched;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* MuonMuidD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void MuonMuidD3PDObject::SetPrefix( const char* prefix ) {

      n.SetName( ::TString( prefix ) + "n" );
      E.SetName( ::TString( prefix ) + "E" );
      pt.SetName( ::TString( prefix ) + "pt" );
      m.SetName( ::TString( prefix ) + "m" );
      eta.SetName( ::TString( prefix ) + "eta" );
      phi.SetName( ::TString( prefix ) + "phi" );
      px.SetName( ::TString( prefix ) + "px" );
      py.SetName( ::TString( prefix ) + "py" );
      pz.SetName( ::TString( prefix ) + "pz" );
      charge.SetName( ::TString( prefix ) + "charge" );
      allauthor.SetName( ::TString( prefix ) + "allauthor" );
      author.SetName( ::TString( prefix ) + "author" );
      beta.SetName( ::TString( prefix ) + "beta" );
      isMuonLikelihood.SetName( ::TString( prefix ) + "isMuonLikelihood" );
      matchchi2.SetName( ::TString( prefix ) + "matchchi2" );
      matchndof.SetName( ::TString( prefix ) + "matchndof" );
      etcone20.SetName( ::TString( prefix ) + "etcone20" );
      etcone30.SetName( ::TString( prefix ) + "etcone30" );
      etcone40.SetName( ::TString( prefix ) + "etcone40" );
      nucone20.SetName( ::TString( prefix ) + "nucone20" );
      nucone30.SetName( ::TString( prefix ) + "nucone30" );
      nucone40.SetName( ::TString( prefix ) + "nucone40" );
      ptcone20.SetName( ::TString( prefix ) + "ptcone20" );
      ptcone30.SetName( ::TString( prefix ) + "ptcone30" );
      ptcone40.SetName( ::TString( prefix ) + "ptcone40" );
      energyLossPar.SetName( ::TString( prefix ) + "energyLossPar" );
      energyLossErr.SetName( ::TString( prefix ) + "energyLossErr" );
      etCore.SetName( ::TString( prefix ) + "etCore" );
      energyLossType.SetName( ::TString( prefix ) + "energyLossType" );
      caloMuonIdTag.SetName( ::TString( prefix ) + "caloMuonIdTag" );
      caloLRLikelihood.SetName( ::TString( prefix ) + "caloLRLikelihood" );
      bestMatch.SetName( ::TString( prefix ) + "bestMatch" );
      isStandAloneMuon.SetName( ::TString( prefix ) + "isStandAloneMuon" );
      isCombinedMuon.SetName( ::TString( prefix ) + "isCombinedMuon" );
      isLowPtReconstructedMuon.SetName( ::TString( prefix ) + "isLowPtReconstructedMuon" );
      isSegmentTaggedMuon.SetName( ::TString( prefix ) + "isSegmentTaggedMuon" );
      isCaloMuonId.SetName( ::TString( prefix ) + "isCaloMuonId" );
      alsoFoundByLowPt.SetName( ::TString( prefix ) + "alsoFoundByLowPt" );
      alsoFoundByCaloMuonId.SetName( ::TString( prefix ) + "alsoFoundByCaloMuonId" );
      loose.SetName( ::TString( prefix ) + "loose" );
      medium.SetName( ::TString( prefix ) + "medium" );
      tight.SetName( ::TString( prefix ) + "tight" );
      d0_exPV.SetName( ::TString( prefix ) + "d0_exPV" );
      z0_exPV.SetName( ::TString( prefix ) + "z0_exPV" );
      phi_exPV.SetName( ::TString( prefix ) + "phi_exPV" );
      theta_exPV.SetName( ::TString( prefix ) + "theta_exPV" );
      qoverp_exPV.SetName( ::TString( prefix ) + "qoverp_exPV" );
      cb_d0_exPV.SetName( ::TString( prefix ) + "cb_d0_exPV" );
      cb_z0_exPV.SetName( ::TString( prefix ) + "cb_z0_exPV" );
      cb_phi_exPV.SetName( ::TString( prefix ) + "cb_phi_exPV" );
      cb_theta_exPV.SetName( ::TString( prefix ) + "cb_theta_exPV" );
      cb_qoverp_exPV.SetName( ::TString( prefix ) + "cb_qoverp_exPV" );
      id_d0_exPV.SetName( ::TString( prefix ) + "id_d0_exPV" );
      id_z0_exPV.SetName( ::TString( prefix ) + "id_z0_exPV" );
      id_phi_exPV.SetName( ::TString( prefix ) + "id_phi_exPV" );
      id_theta_exPV.SetName( ::TString( prefix ) + "id_theta_exPV" );
      id_qoverp_exPV.SetName( ::TString( prefix ) + "id_qoverp_exPV" );
      me_d0_exPV.SetName( ::TString( prefix ) + "me_d0_exPV" );
      me_z0_exPV.SetName( ::TString( prefix ) + "me_z0_exPV" );
      me_phi_exPV.SetName( ::TString( prefix ) + "me_phi_exPV" );
      me_theta_exPV.SetName( ::TString( prefix ) + "me_theta_exPV" );
      me_qoverp_exPV.SetName( ::TString( prefix ) + "me_qoverp_exPV" );
      ie_d0_exPV.SetName( ::TString( prefix ) + "ie_d0_exPV" );
      ie_z0_exPV.SetName( ::TString( prefix ) + "ie_z0_exPV" );
      ie_phi_exPV.SetName( ::TString( prefix ) + "ie_phi_exPV" );
      ie_theta_exPV.SetName( ::TString( prefix ) + "ie_theta_exPV" );
      ie_qoverp_exPV.SetName( ::TString( prefix ) + "ie_qoverp_exPV" );
      SpaceTime_detID.SetName( ::TString( prefix ) + "SpaceTime_detID" );
      SpaceTime_t.SetName( ::TString( prefix ) + "SpaceTime_t" );
      SpaceTime_tError.SetName( ::TString( prefix ) + "SpaceTime_tError" );
      SpaceTime_weight.SetName( ::TString( prefix ) + "SpaceTime_weight" );
      SpaceTime_x.SetName( ::TString( prefix ) + "SpaceTime_x" );
      SpaceTime_y.SetName( ::TString( prefix ) + "SpaceTime_y" );
      SpaceTime_z.SetName( ::TString( prefix ) + "SpaceTime_z" );
      cov_d0_exPV.SetName( ::TString( prefix ) + "cov_d0_exPV" );
      cov_z0_exPV.SetName( ::TString( prefix ) + "cov_z0_exPV" );
      cov_phi_exPV.SetName( ::TString( prefix ) + "cov_phi_exPV" );
      cov_theta_exPV.SetName( ::TString( prefix ) + "cov_theta_exPV" );
      cov_qoverp_exPV.SetName( ::TString( prefix ) + "cov_qoverp_exPV" );
      cov_d0_z0_exPV.SetName( ::TString( prefix ) + "cov_d0_z0_exPV" );
      cov_d0_phi_exPV.SetName( ::TString( prefix ) + "cov_d0_phi_exPV" );
      cov_d0_theta_exPV.SetName( ::TString( prefix ) + "cov_d0_theta_exPV" );
      cov_d0_qoverp_exPV.SetName( ::TString( prefix ) + "cov_d0_qoverp_exPV" );
      cov_z0_phi_exPV.SetName( ::TString( prefix ) + "cov_z0_phi_exPV" );
      cov_z0_theta_exPV.SetName( ::TString( prefix ) + "cov_z0_theta_exPV" );
      cov_z0_qoverp_exPV.SetName( ::TString( prefix ) + "cov_z0_qoverp_exPV" );
      cov_phi_theta_exPV.SetName( ::TString( prefix ) + "cov_phi_theta_exPV" );
      cov_phi_qoverp_exPV.SetName( ::TString( prefix ) + "cov_phi_qoverp_exPV" );
      cov_theta_qoverp_exPV.SetName( ::TString( prefix ) + "cov_theta_qoverp_exPV" );
      id_cov_d0_exPV.SetName( ::TString( prefix ) + "id_cov_d0_exPV" );
      id_cov_z0_exPV.SetName( ::TString( prefix ) + "id_cov_z0_exPV" );
      id_cov_phi_exPV.SetName( ::TString( prefix ) + "id_cov_phi_exPV" );
      id_cov_theta_exPV.SetName( ::TString( prefix ) + "id_cov_theta_exPV" );
      id_cov_qoverp_exPV.SetName( ::TString( prefix ) + "id_cov_qoverp_exPV" );
      me_cov_d0_exPV.SetName( ::TString( prefix ) + "me_cov_d0_exPV" );
      me_cov_z0_exPV.SetName( ::TString( prefix ) + "me_cov_z0_exPV" );
      me_cov_phi_exPV.SetName( ::TString( prefix ) + "me_cov_phi_exPV" );
      me_cov_theta_exPV.SetName( ::TString( prefix ) + "me_cov_theta_exPV" );
      me_cov_qoverp_exPV.SetName( ::TString( prefix ) + "me_cov_qoverp_exPV" );
      ms_d0.SetName( ::TString( prefix ) + "ms_d0" );
      ms_z0.SetName( ::TString( prefix ) + "ms_z0" );
      ms_phi.SetName( ::TString( prefix ) + "ms_phi" );
      ms_theta.SetName( ::TString( prefix ) + "ms_theta" );
      ms_qoverp.SetName( ::TString( prefix ) + "ms_qoverp" );
      id_d0.SetName( ::TString( prefix ) + "id_d0" );
      id_z0.SetName( ::TString( prefix ) + "id_z0" );
      id_phi.SetName( ::TString( prefix ) + "id_phi" );
      id_theta.SetName( ::TString( prefix ) + "id_theta" );
      id_qoverp.SetName( ::TString( prefix ) + "id_qoverp" );
      me_d0.SetName( ::TString( prefix ) + "me_d0" );
      me_z0.SetName( ::TString( prefix ) + "me_z0" );
      me_phi.SetName( ::TString( prefix ) + "me_phi" );
      me_theta.SetName( ::TString( prefix ) + "me_theta" );
      me_qoverp.SetName( ::TString( prefix ) + "me_qoverp" );
      ie_d0.SetName( ::TString( prefix ) + "ie_d0" );
      ie_z0.SetName( ::TString( prefix ) + "ie_z0" );
      ie_phi.SetName( ::TString( prefix ) + "ie_phi" );
      ie_theta.SetName( ::TString( prefix ) + "ie_theta" );
      ie_qoverp.SetName( ::TString( prefix ) + "ie_qoverp" );
      nOutliersOnTrack.SetName( ::TString( prefix ) + "nOutliersOnTrack" );
      nBLHits.SetName( ::TString( prefix ) + "nBLHits" );
      nPixHits.SetName( ::TString( prefix ) + "nPixHits" );
      nSCTHits.SetName( ::TString( prefix ) + "nSCTHits" );
      nTRTHits.SetName( ::TString( prefix ) + "nTRTHits" );
      nTRTHighTHits.SetName( ::TString( prefix ) + "nTRTHighTHits" );
      nBLSharedHits.SetName( ::TString( prefix ) + "nBLSharedHits" );
      nPixSharedHits.SetName( ::TString( prefix ) + "nPixSharedHits" );
      nPixHoles.SetName( ::TString( prefix ) + "nPixHoles" );
      nSCTSharedHits.SetName( ::TString( prefix ) + "nSCTSharedHits" );
      nSCTHoles.SetName( ::TString( prefix ) + "nSCTHoles" );
      nTRTOutliers.SetName( ::TString( prefix ) + "nTRTOutliers" );
      nTRTHighTOutliers.SetName( ::TString( prefix ) + "nTRTHighTOutliers" );
      nGangedPixels.SetName( ::TString( prefix ) + "nGangedPixels" );
      nPixelDeadSensors.SetName( ::TString( prefix ) + "nPixelDeadSensors" );
      nSCTDeadSensors.SetName( ::TString( prefix ) + "nSCTDeadSensors" );
      nTRTDeadStraws.SetName( ::TString( prefix ) + "nTRTDeadStraws" );
      expectBLayerHit.SetName( ::TString( prefix ) + "expectBLayerHit" );
      nMDTHits.SetName( ::TString( prefix ) + "nMDTHits" );
      nMDTHoles.SetName( ::TString( prefix ) + "nMDTHoles" );
      nCSCEtaHits.SetName( ::TString( prefix ) + "nCSCEtaHits" );
      nCSCEtaHoles.SetName( ::TString( prefix ) + "nCSCEtaHoles" );
      nCSCPhiHits.SetName( ::TString( prefix ) + "nCSCPhiHits" );
      nCSCPhiHoles.SetName( ::TString( prefix ) + "nCSCPhiHoles" );
      nRPCEtaHits.SetName( ::TString( prefix ) + "nRPCEtaHits" );
      nRPCEtaHoles.SetName( ::TString( prefix ) + "nRPCEtaHoles" );
      nRPCPhiHits.SetName( ::TString( prefix ) + "nRPCPhiHits" );
      nRPCPhiHoles.SetName( ::TString( prefix ) + "nRPCPhiHoles" );
      nTGCEtaHits.SetName( ::TString( prefix ) + "nTGCEtaHits" );
      nTGCEtaHoles.SetName( ::TString( prefix ) + "nTGCEtaHoles" );
      nTGCPhiHits.SetName( ::TString( prefix ) + "nTGCPhiHits" );
      nTGCPhiHoles.SetName( ::TString( prefix ) + "nTGCPhiHoles" );
      nMDTBIHits.SetName( ::TString( prefix ) + "nMDTBIHits" );
      nMDTBMHits.SetName( ::TString( prefix ) + "nMDTBMHits" );
      nMDTBOHits.SetName( ::TString( prefix ) + "nMDTBOHits" );
      nMDTBEEHits.SetName( ::TString( prefix ) + "nMDTBEEHits" );
      nMDTBIS78Hits.SetName( ::TString( prefix ) + "nMDTBIS78Hits" );
      nMDTEIHits.SetName( ::TString( prefix ) + "nMDTEIHits" );
      nMDTEMHits.SetName( ::TString( prefix ) + "nMDTEMHits" );
      nMDTEOHits.SetName( ::TString( prefix ) + "nMDTEOHits" );
      nMDTEEHits.SetName( ::TString( prefix ) + "nMDTEEHits" );
      nRPCLayer1EtaHits.SetName( ::TString( prefix ) + "nRPCLayer1EtaHits" );
      nRPCLayer2EtaHits.SetName( ::TString( prefix ) + "nRPCLayer2EtaHits" );
      nRPCLayer3EtaHits.SetName( ::TString( prefix ) + "nRPCLayer3EtaHits" );
      nRPCLayer1PhiHits.SetName( ::TString( prefix ) + "nRPCLayer1PhiHits" );
      nRPCLayer2PhiHits.SetName( ::TString( prefix ) + "nRPCLayer2PhiHits" );
      nRPCLayer3PhiHits.SetName( ::TString( prefix ) + "nRPCLayer3PhiHits" );
      nTGCLayer1EtaHits.SetName( ::TString( prefix ) + "nTGCLayer1EtaHits" );
      nTGCLayer2EtaHits.SetName( ::TString( prefix ) + "nTGCLayer2EtaHits" );
      nTGCLayer3EtaHits.SetName( ::TString( prefix ) + "nTGCLayer3EtaHits" );
      nTGCLayer4EtaHits.SetName( ::TString( prefix ) + "nTGCLayer4EtaHits" );
      nTGCLayer1PhiHits.SetName( ::TString( prefix ) + "nTGCLayer1PhiHits" );
      nTGCLayer2PhiHits.SetName( ::TString( prefix ) + "nTGCLayer2PhiHits" );
      nTGCLayer3PhiHits.SetName( ::TString( prefix ) + "nTGCLayer3PhiHits" );
      nTGCLayer4PhiHits.SetName( ::TString( prefix ) + "nTGCLayer4PhiHits" );
      barrelSectors.SetName( ::TString( prefix ) + "barrelSectors" );
      endcapSectors.SetName( ::TString( prefix ) + "endcapSectors" );
      trackd0.SetName( ::TString( prefix ) + "trackd0" );
      trackz0.SetName( ::TString( prefix ) + "trackz0" );
      trackphi.SetName( ::TString( prefix ) + "trackphi" );
      tracktheta.SetName( ::TString( prefix ) + "tracktheta" );
      trackqoverp.SetName( ::TString( prefix ) + "trackqoverp" );
      trackcov_d0.SetName( ::TString( prefix ) + "trackcov_d0" );
      trackcov_z0.SetName( ::TString( prefix ) + "trackcov_z0" );
      trackcov_phi.SetName( ::TString( prefix ) + "trackcov_phi" );
      trackcov_theta.SetName( ::TString( prefix ) + "trackcov_theta" );
      trackcov_qoverp.SetName( ::TString( prefix ) + "trackcov_qoverp" );
      trackcov_d0_z0.SetName( ::TString( prefix ) + "trackcov_d0_z0" );
      trackcov_d0_phi.SetName( ::TString( prefix ) + "trackcov_d0_phi" );
      trackcov_d0_theta.SetName( ::TString( prefix ) + "trackcov_d0_theta" );
      trackcov_d0_qoverp.SetName( ::TString( prefix ) + "trackcov_d0_qoverp" );
      trackcov_z0_phi.SetName( ::TString( prefix ) + "trackcov_z0_phi" );
      trackcov_z0_theta.SetName( ::TString( prefix ) + "trackcov_z0_theta" );
      trackcov_z0_qoverp.SetName( ::TString( prefix ) + "trackcov_z0_qoverp" );
      trackcov_phi_theta.SetName( ::TString( prefix ) + "trackcov_phi_theta" );
      trackcov_phi_qoverp.SetName( ::TString( prefix ) + "trackcov_phi_qoverp" );
      trackcov_theta_qoverp.SetName( ::TString( prefix ) + "trackcov_theta_qoverp" );
      trackfitchi2.SetName( ::TString( prefix ) + "trackfitchi2" );
      trackfitndof.SetName( ::TString( prefix ) + "trackfitndof" );
      hastrack.SetName( ::TString( prefix ) + "hastrack" );
      trackd0beam.SetName( ::TString( prefix ) + "trackd0beam" );
      trackz0beam.SetName( ::TString( prefix ) + "trackz0beam" );
      tracksigd0beam.SetName( ::TString( prefix ) + "tracksigd0beam" );
      tracksigz0beam.SetName( ::TString( prefix ) + "tracksigz0beam" );
      trackd0pv.SetName( ::TString( prefix ) + "trackd0pv" );
      trackz0pv.SetName( ::TString( prefix ) + "trackz0pv" );
      tracksigd0pv.SetName( ::TString( prefix ) + "tracksigd0pv" );
      tracksigz0pv.SetName( ::TString( prefix ) + "tracksigz0pv" );
      trackIPEstimate_d0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_d0_biasedpvunbiased" );
      trackIPEstimate_z0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_z0_biasedpvunbiased" );
      trackIPEstimate_sigd0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigd0_biasedpvunbiased" );
      trackIPEstimate_sigz0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigz0_biasedpvunbiased" );
      trackIPEstimate_d0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased" );
      trackIPEstimate_z0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased" );
      trackIPEstimate_sigd0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased" );
      trackIPEstimate_sigz0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased" );
      trackd0pvunbiased.SetName( ::TString( prefix ) + "trackd0pvunbiased" );
      trackz0pvunbiased.SetName( ::TString( prefix ) + "trackz0pvunbiased" );
      tracksigd0pvunbiased.SetName( ::TString( prefix ) + "tracksigd0pvunbiased" );
      tracksigz0pvunbiased.SetName( ::TString( prefix ) + "tracksigz0pvunbiased" );
      truth_dr.SetName( ::TString( prefix ) + "truth_dr" );
      truth_matched.SetName( ::TString( prefix ) + "truth_matched" );
      EFCB_dr.SetName( ::TString( prefix ) + "EFCB_dr" );
//       EFCB_n.SetName( ::TString( prefix ) + "EFCB_n" );
//       EFCB_MuonType.SetName( ::TString( prefix ) + "EFCB_MuonType" );
//       EFCB_pt.SetName( ::TString( prefix ) + "EFCB_pt" );
//       EFCB_eta.SetName( ::TString( prefix ) + "EFCB_eta" );
//       EFCB_phi.SetName( ::TString( prefix ) + "EFCB_phi" );
//       EFCB_hasCB.SetName( ::TString( prefix ) + "EFCB_hasCB" );
//       EFCB_matched.SetName( ::TString( prefix ) + "EFCB_matched" );
      EFMG_dr.SetName( ::TString( prefix ) + "EFMG_dr" );
//       EFMG_n.SetName( ::TString( prefix ) + "EFMG_n" );
//       EFMG_MuonType.SetName( ::TString( prefix ) + "EFMG_MuonType" );
//       EFMG_pt.SetName( ::TString( prefix ) + "EFMG_pt" );
//       EFMG_eta.SetName( ::TString( prefix ) + "EFMG_eta" );
//       EFMG_phi.SetName( ::TString( prefix ) + "EFMG_phi" );
//       EFMG_hasMG.SetName( ::TString( prefix ) + "EFMG_hasMG" );
//       EFMG_matched.SetName( ::TString( prefix ) + "EFMG_matched" );
      EFME_dr.SetName( ::TString( prefix ) + "EFME_dr" );
//       EFME_n.SetName( ::TString( prefix ) + "EFME_n" );
//       EFME_MuonType.SetName( ::TString( prefix ) + "EFME_MuonType" );
//       EFME_pt.SetName( ::TString( prefix ) + "EFME_pt" );
//       EFME_eta.SetName( ::TString( prefix ) + "EFME_eta" );
//       EFME_phi.SetName( ::TString( prefix ) + "EFME_phi" );
//       EFME_hasME.SetName( ::TString( prefix ) + "EFME_hasME" );
//       EFME_matched.SetName( ::TString( prefix ) + "EFME_matched" );
      L2CB_dr.SetName( ::TString( prefix ) + "L2CB_dr" );
      L2CB_pt.SetName( ::TString( prefix ) + "L2CB_pt" );
      L2CB_eta.SetName( ::TString( prefix ) + "L2CB_eta" );
      L2CB_phi.SetName( ::TString( prefix ) + "L2CB_phi" );
      L2CB_id_pt.SetName( ::TString( prefix ) + "L2CB_id_pt" );
      L2CB_ms_pt.SetName( ::TString( prefix ) + "L2CB_ms_pt" );
      L2CB_nPixHits.SetName( ::TString( prefix ) + "L2CB_nPixHits" );
      L2CB_nSCTHits.SetName( ::TString( prefix ) + "L2CB_nSCTHits" );
      L2CB_nTRTHits.SetName( ::TString( prefix ) + "L2CB_nTRTHits" );
      L2CB_nTRTHighTHits.SetName( ::TString( prefix ) + "L2CB_nTRTHighTHits" );
      L2CB_matched.SetName( ::TString( prefix ) + "L2CB_matched" );
      L1_dr.SetName( ::TString( prefix ) + "L1_dr" );
      L1_pt.SetName( ::TString( prefix ) + "L1_pt" );
      L1_eta.SetName( ::TString( prefix ) + "L1_eta" );
      L1_phi.SetName( ::TString( prefix ) + "L1_phi" );
      L1_thrNumber.SetName( ::TString( prefix ) + "L1_thrNumber" );
      L1_RoINumber.SetName( ::TString( prefix ) + "L1_RoINumber" );
      L1_sectorAddress.SetName( ::TString( prefix ) + "L1_sectorAddress" );
      L1_firstCandidate.SetName( ::TString( prefix ) + "L1_firstCandidate" );
      L1_moreCandInRoI.SetName( ::TString( prefix ) + "L1_moreCandInRoI" );
      L1_moreCandInSector.SetName( ::TString( prefix ) + "L1_moreCandInSector" );
      L1_source.SetName( ::TString( prefix ) + "L1_source" );
      L1_hemisphere.SetName( ::TString( prefix ) + "L1_hemisphere" );
      L1_charge.SetName( ::TString( prefix ) + "L1_charge" );
      L1_vetoed.SetName( ::TString( prefix ) + "L1_vetoed" );
      L1_matched.SetName( ::TString( prefix ) + "L1_matched" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void MuonMuidD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      n.ReadFrom( tree );
      E.ReadFrom( tree );
      pt.ReadFrom( tree );
      m.ReadFrom( tree );
      eta.ReadFrom( tree );
      phi.ReadFrom( tree );
      px.ReadFrom( tree );
      py.ReadFrom( tree );
      pz.ReadFrom( tree );
      charge.ReadFrom( tree );
      allauthor.ReadFrom( tree );
      author.ReadFrom( tree );
      beta.ReadFrom( tree );
      isMuonLikelihood.ReadFrom( tree );
      matchchi2.ReadFrom( tree );
      matchndof.ReadFrom( tree );
      etcone20.ReadFrom( tree );
      etcone30.ReadFrom( tree );
      etcone40.ReadFrom( tree );
      nucone20.ReadFrom( tree );
      nucone30.ReadFrom( tree );
      nucone40.ReadFrom( tree );
      ptcone20.ReadFrom( tree );
      ptcone30.ReadFrom( tree );
      ptcone40.ReadFrom( tree );
      energyLossPar.ReadFrom( tree );
      energyLossErr.ReadFrom( tree );
      etCore.ReadFrom( tree );
      energyLossType.ReadFrom( tree );
      caloMuonIdTag.ReadFrom( tree );
      caloLRLikelihood.ReadFrom( tree );
      bestMatch.ReadFrom( tree );
      isStandAloneMuon.ReadFrom( tree );
      isCombinedMuon.ReadFrom( tree );
      isLowPtReconstructedMuon.ReadFrom( tree );
      isSegmentTaggedMuon.ReadFrom( tree );
      isCaloMuonId.ReadFrom( tree );
      alsoFoundByLowPt.ReadFrom( tree );
      alsoFoundByCaloMuonId.ReadFrom( tree );
      loose.ReadFrom( tree );
      medium.ReadFrom( tree );
      tight.ReadFrom( tree );
      d0_exPV.ReadFrom( tree );
      z0_exPV.ReadFrom( tree );
      phi_exPV.ReadFrom( tree );
      theta_exPV.ReadFrom( tree );
      qoverp_exPV.ReadFrom( tree );
      cb_d0_exPV.ReadFrom( tree );
      cb_z0_exPV.ReadFrom( tree );
      cb_phi_exPV.ReadFrom( tree );
      cb_theta_exPV.ReadFrom( tree );
      cb_qoverp_exPV.ReadFrom( tree );
      id_d0_exPV.ReadFrom( tree );
      id_z0_exPV.ReadFrom( tree );
      id_phi_exPV.ReadFrom( tree );
      id_theta_exPV.ReadFrom( tree );
      id_qoverp_exPV.ReadFrom( tree );
      me_d0_exPV.ReadFrom( tree );
      me_z0_exPV.ReadFrom( tree );
      me_phi_exPV.ReadFrom( tree );
      me_theta_exPV.ReadFrom( tree );
      me_qoverp_exPV.ReadFrom( tree );
      ie_d0_exPV.ReadFrom( tree );
      ie_z0_exPV.ReadFrom( tree );
      ie_phi_exPV.ReadFrom( tree );
      ie_theta_exPV.ReadFrom( tree );
      ie_qoverp_exPV.ReadFrom( tree );
      SpaceTime_detID.ReadFrom( tree );
      SpaceTime_t.ReadFrom( tree );
      SpaceTime_tError.ReadFrom( tree );
      SpaceTime_weight.ReadFrom( tree );
      SpaceTime_x.ReadFrom( tree );
      SpaceTime_y.ReadFrom( tree );
      SpaceTime_z.ReadFrom( tree );
      cov_d0_exPV.ReadFrom( tree );
      cov_z0_exPV.ReadFrom( tree );
      cov_phi_exPV.ReadFrom( tree );
      cov_theta_exPV.ReadFrom( tree );
      cov_qoverp_exPV.ReadFrom( tree );
      cov_d0_z0_exPV.ReadFrom( tree );
      cov_d0_phi_exPV.ReadFrom( tree );
      cov_d0_theta_exPV.ReadFrom( tree );
      cov_d0_qoverp_exPV.ReadFrom( tree );
      cov_z0_phi_exPV.ReadFrom( tree );
      cov_z0_theta_exPV.ReadFrom( tree );
      cov_z0_qoverp_exPV.ReadFrom( tree );
      cov_phi_theta_exPV.ReadFrom( tree );
      cov_phi_qoverp_exPV.ReadFrom( tree );
      cov_theta_qoverp_exPV.ReadFrom( tree );
      id_cov_d0_exPV.ReadFrom( tree );
      id_cov_z0_exPV.ReadFrom( tree );
      id_cov_phi_exPV.ReadFrom( tree );
      id_cov_theta_exPV.ReadFrom( tree );
      id_cov_qoverp_exPV.ReadFrom( tree );
      me_cov_d0_exPV.ReadFrom( tree );
      me_cov_z0_exPV.ReadFrom( tree );
      me_cov_phi_exPV.ReadFrom( tree );
      me_cov_theta_exPV.ReadFrom( tree );
      me_cov_qoverp_exPV.ReadFrom( tree );
      ms_d0.ReadFrom( tree );
      ms_z0.ReadFrom( tree );
      ms_phi.ReadFrom( tree );
      ms_theta.ReadFrom( tree );
      ms_qoverp.ReadFrom( tree );
      id_d0.ReadFrom( tree );
      id_z0.ReadFrom( tree );
      id_phi.ReadFrom( tree );
      id_theta.ReadFrom( tree );
      id_qoverp.ReadFrom( tree );
      me_d0.ReadFrom( tree );
      me_z0.ReadFrom( tree );
      me_phi.ReadFrom( tree );
      me_theta.ReadFrom( tree );
      me_qoverp.ReadFrom( tree );
      ie_d0.ReadFrom( tree );
      ie_z0.ReadFrom( tree );
      ie_phi.ReadFrom( tree );
      ie_theta.ReadFrom( tree );
      ie_qoverp.ReadFrom( tree );
      nOutliersOnTrack.ReadFrom( tree );
      nBLHits.ReadFrom( tree );
      nPixHits.ReadFrom( tree );
      nSCTHits.ReadFrom( tree );
      nTRTHits.ReadFrom( tree );
      nTRTHighTHits.ReadFrom( tree );
      nBLSharedHits.ReadFrom( tree );
      nPixSharedHits.ReadFrom( tree );
      nPixHoles.ReadFrom( tree );
      nSCTSharedHits.ReadFrom( tree );
      nSCTHoles.ReadFrom( tree );
      nTRTOutliers.ReadFrom( tree );
      nTRTHighTOutliers.ReadFrom( tree );
      nGangedPixels.ReadFrom( tree );
      nPixelDeadSensors.ReadFrom( tree );
      nSCTDeadSensors.ReadFrom( tree );
      nTRTDeadStraws.ReadFrom( tree );
      expectBLayerHit.ReadFrom( tree );
      nMDTHits.ReadFrom( tree );
      nMDTHoles.ReadFrom( tree );
      nCSCEtaHits.ReadFrom( tree );
      nCSCEtaHoles.ReadFrom( tree );
      nCSCPhiHits.ReadFrom( tree );
      nCSCPhiHoles.ReadFrom( tree );
      nRPCEtaHits.ReadFrom( tree );
      nRPCEtaHoles.ReadFrom( tree );
      nRPCPhiHits.ReadFrom( tree );
      nRPCPhiHoles.ReadFrom( tree );
      nTGCEtaHits.ReadFrom( tree );
      nTGCEtaHoles.ReadFrom( tree );
      nTGCPhiHits.ReadFrom( tree );
      nTGCPhiHoles.ReadFrom( tree );
      nMDTBIHits.ReadFrom( tree );
      nMDTBMHits.ReadFrom( tree );
      nMDTBOHits.ReadFrom( tree );
      nMDTBEEHits.ReadFrom( tree );
      nMDTBIS78Hits.ReadFrom( tree );
      nMDTEIHits.ReadFrom( tree );
      nMDTEMHits.ReadFrom( tree );
      nMDTEOHits.ReadFrom( tree );
      nMDTEEHits.ReadFrom( tree );
      nRPCLayer1EtaHits.ReadFrom( tree );
      nRPCLayer2EtaHits.ReadFrom( tree );
      nRPCLayer3EtaHits.ReadFrom( tree );
      nRPCLayer1PhiHits.ReadFrom( tree );
      nRPCLayer2PhiHits.ReadFrom( tree );
      nRPCLayer3PhiHits.ReadFrom( tree );
      nTGCLayer1EtaHits.ReadFrom( tree );
      nTGCLayer2EtaHits.ReadFrom( tree );
      nTGCLayer3EtaHits.ReadFrom( tree );
      nTGCLayer4EtaHits.ReadFrom( tree );
      nTGCLayer1PhiHits.ReadFrom( tree );
      nTGCLayer2PhiHits.ReadFrom( tree );
      nTGCLayer3PhiHits.ReadFrom( tree );
      nTGCLayer4PhiHits.ReadFrom( tree );
      barrelSectors.ReadFrom( tree );
      endcapSectors.ReadFrom( tree );
      trackd0.ReadFrom( tree );
      trackz0.ReadFrom( tree );
      trackphi.ReadFrom( tree );
      tracktheta.ReadFrom( tree );
      trackqoverp.ReadFrom( tree );
      trackcov_d0.ReadFrom( tree );
      trackcov_z0.ReadFrom( tree );
      trackcov_phi.ReadFrom( tree );
      trackcov_theta.ReadFrom( tree );
      trackcov_qoverp.ReadFrom( tree );
      trackcov_d0_z0.ReadFrom( tree );
      trackcov_d0_phi.ReadFrom( tree );
      trackcov_d0_theta.ReadFrom( tree );
      trackcov_d0_qoverp.ReadFrom( tree );
      trackcov_z0_phi.ReadFrom( tree );
      trackcov_z0_theta.ReadFrom( tree );
      trackcov_z0_qoverp.ReadFrom( tree );
      trackcov_phi_theta.ReadFrom( tree );
      trackcov_phi_qoverp.ReadFrom( tree );
      trackcov_theta_qoverp.ReadFrom( tree );
      trackfitchi2.ReadFrom( tree );
      trackfitndof.ReadFrom( tree );
      hastrack.ReadFrom( tree );
      trackd0beam.ReadFrom( tree );
      trackz0beam.ReadFrom( tree );
      tracksigd0beam.ReadFrom( tree );
      tracksigz0beam.ReadFrom( tree );
      trackd0pv.ReadFrom( tree );
      trackz0pv.ReadFrom( tree );
      tracksigd0pv.ReadFrom( tree );
      tracksigz0pv.ReadFrom( tree );
      trackIPEstimate_d0_biasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_z0_biasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigd0_biasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigz0_biasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_d0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_z0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigd0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigz0_unbiasedpvunbiased.ReadFrom( tree );
      trackd0pvunbiased.ReadFrom( tree );
      trackz0pvunbiased.ReadFrom( tree );
      tracksigd0pvunbiased.ReadFrom( tree );
      tracksigz0pvunbiased.ReadFrom( tree );
      truth_dr.ReadFrom( tree );
      truth_matched.ReadFrom( tree );
      EFCB_dr.ReadFrom( tree );
//       EFCB_n.ReadFrom( tree );
//       EFCB_MuonType.ReadFrom( tree );
//       EFCB_pt.ReadFrom( tree );
//       EFCB_eta.ReadFrom( tree );
//       EFCB_phi.ReadFrom( tree );
//       EFCB_hasCB.ReadFrom( tree );
//       EFCB_matched.ReadFrom( tree );
      EFMG_dr.ReadFrom( tree );
//       EFMG_n.ReadFrom( tree );
//       EFMG_MuonType.ReadFrom( tree );
//       EFMG_pt.ReadFrom( tree );
//       EFMG_eta.ReadFrom( tree );
//       EFMG_phi.ReadFrom( tree );
//       EFMG_hasMG.ReadFrom( tree );
//       EFMG_matched.ReadFrom( tree );
      EFME_dr.ReadFrom( tree );
//       EFME_n.ReadFrom( tree );
//       EFME_MuonType.ReadFrom( tree );
//       EFME_pt.ReadFrom( tree );
//       EFME_eta.ReadFrom( tree );
//       EFME_phi.ReadFrom( tree );
//       EFME_hasME.ReadFrom( tree );
//       EFME_matched.ReadFrom( tree );
      L2CB_dr.ReadFrom( tree );
      L2CB_pt.ReadFrom( tree );
      L2CB_eta.ReadFrom( tree );
      L2CB_phi.ReadFrom( tree );
      L2CB_id_pt.ReadFrom( tree );
      L2CB_ms_pt.ReadFrom( tree );
      L2CB_nPixHits.ReadFrom( tree );
      L2CB_nSCTHits.ReadFrom( tree );
      L2CB_nTRTHits.ReadFrom( tree );
      L2CB_nTRTHighTHits.ReadFrom( tree );
      L2CB_matched.ReadFrom( tree );
      L1_dr.ReadFrom( tree );
      L1_pt.ReadFrom( tree );
      L1_eta.ReadFrom( tree );
      L1_phi.ReadFrom( tree );
      L1_thrNumber.ReadFrom( tree );
      L1_RoINumber.ReadFrom( tree );
      L1_sectorAddress.ReadFrom( tree );
      L1_firstCandidate.ReadFrom( tree );
      L1_moreCandInRoI.ReadFrom( tree );
      L1_moreCandInSector.ReadFrom( tree );
      L1_source.ReadFrom( tree );
      L1_hemisphere.ReadFrom( tree );
      L1_charge.ReadFrom( tree );
      L1_vetoed.ReadFrom( tree );
      L1_matched.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void MuonMuidD3PDObject::WriteTo( TTree* tree ) {

      n.WriteTo( tree );
      E.WriteTo( tree );
      pt.WriteTo( tree );
      m.WriteTo( tree );
      eta.WriteTo( tree );
      phi.WriteTo( tree );
      px.WriteTo( tree );
      py.WriteTo( tree );
      pz.WriteTo( tree );
      charge.WriteTo( tree );
      allauthor.WriteTo( tree );
      author.WriteTo( tree );
      beta.WriteTo( tree );
      isMuonLikelihood.WriteTo( tree );
      matchchi2.WriteTo( tree );
      matchndof.WriteTo( tree );
      etcone20.WriteTo( tree );
      etcone30.WriteTo( tree );
      etcone40.WriteTo( tree );
      nucone20.WriteTo( tree );
      nucone30.WriteTo( tree );
      nucone40.WriteTo( tree );
      ptcone20.WriteTo( tree );
      ptcone30.WriteTo( tree );
      ptcone40.WriteTo( tree );
      energyLossPar.WriteTo( tree );
      energyLossErr.WriteTo( tree );
      etCore.WriteTo( tree );
      energyLossType.WriteTo( tree );
      caloMuonIdTag.WriteTo( tree );
      caloLRLikelihood.WriteTo( tree );
      bestMatch.WriteTo( tree );
      isStandAloneMuon.WriteTo( tree );
      isCombinedMuon.WriteTo( tree );
      isLowPtReconstructedMuon.WriteTo( tree );
      isSegmentTaggedMuon.WriteTo( tree );
      isCaloMuonId.WriteTo( tree );
      alsoFoundByLowPt.WriteTo( tree );
      alsoFoundByCaloMuonId.WriteTo( tree );
      loose.WriteTo( tree );
      medium.WriteTo( tree );
      tight.WriteTo( tree );
      d0_exPV.WriteTo( tree );
      z0_exPV.WriteTo( tree );
      phi_exPV.WriteTo( tree );
      theta_exPV.WriteTo( tree );
      qoverp_exPV.WriteTo( tree );
      cb_d0_exPV.WriteTo( tree );
      cb_z0_exPV.WriteTo( tree );
      cb_phi_exPV.WriteTo( tree );
      cb_theta_exPV.WriteTo( tree );
      cb_qoverp_exPV.WriteTo( tree );
      id_d0_exPV.WriteTo( tree );
      id_z0_exPV.WriteTo( tree );
      id_phi_exPV.WriteTo( tree );
      id_theta_exPV.WriteTo( tree );
      id_qoverp_exPV.WriteTo( tree );
      me_d0_exPV.WriteTo( tree );
      me_z0_exPV.WriteTo( tree );
      me_phi_exPV.WriteTo( tree );
      me_theta_exPV.WriteTo( tree );
      me_qoverp_exPV.WriteTo( tree );
      ie_d0_exPV.WriteTo( tree );
      ie_z0_exPV.WriteTo( tree );
      ie_phi_exPV.WriteTo( tree );
      ie_theta_exPV.WriteTo( tree );
      ie_qoverp_exPV.WriteTo( tree );
      SpaceTime_detID.WriteTo( tree );
      SpaceTime_t.WriteTo( tree );
      SpaceTime_tError.WriteTo( tree );
      SpaceTime_weight.WriteTo( tree );
      SpaceTime_x.WriteTo( tree );
      SpaceTime_y.WriteTo( tree );
      SpaceTime_z.WriteTo( tree );
      cov_d0_exPV.WriteTo( tree );
      cov_z0_exPV.WriteTo( tree );
      cov_phi_exPV.WriteTo( tree );
      cov_theta_exPV.WriteTo( tree );
      cov_qoverp_exPV.WriteTo( tree );
      cov_d0_z0_exPV.WriteTo( tree );
      cov_d0_phi_exPV.WriteTo( tree );
      cov_d0_theta_exPV.WriteTo( tree );
      cov_d0_qoverp_exPV.WriteTo( tree );
      cov_z0_phi_exPV.WriteTo( tree );
      cov_z0_theta_exPV.WriteTo( tree );
      cov_z0_qoverp_exPV.WriteTo( tree );
      cov_phi_theta_exPV.WriteTo( tree );
      cov_phi_qoverp_exPV.WriteTo( tree );
      cov_theta_qoverp_exPV.WriteTo( tree );
      id_cov_d0_exPV.WriteTo( tree );
      id_cov_z0_exPV.WriteTo( tree );
      id_cov_phi_exPV.WriteTo( tree );
      id_cov_theta_exPV.WriteTo( tree );
      id_cov_qoverp_exPV.WriteTo( tree );
      me_cov_d0_exPV.WriteTo( tree );
      me_cov_z0_exPV.WriteTo( tree );
      me_cov_phi_exPV.WriteTo( tree );
      me_cov_theta_exPV.WriteTo( tree );
      me_cov_qoverp_exPV.WriteTo( tree );
      ms_d0.WriteTo( tree );
      ms_z0.WriteTo( tree );
      ms_phi.WriteTo( tree );
      ms_theta.WriteTo( tree );
      ms_qoverp.WriteTo( tree );
      id_d0.WriteTo( tree );
      id_z0.WriteTo( tree );
      id_phi.WriteTo( tree );
      id_theta.WriteTo( tree );
      id_qoverp.WriteTo( tree );
      me_d0.WriteTo( tree );
      me_z0.WriteTo( tree );
      me_phi.WriteTo( tree );
      me_theta.WriteTo( tree );
      me_qoverp.WriteTo( tree );
      ie_d0.WriteTo( tree );
      ie_z0.WriteTo( tree );
      ie_phi.WriteTo( tree );
      ie_theta.WriteTo( tree );
      ie_qoverp.WriteTo( tree );
      nOutliersOnTrack.WriteTo( tree );
      nBLHits.WriteTo( tree );
      nPixHits.WriteTo( tree );
      nSCTHits.WriteTo( tree );
      nTRTHits.WriteTo( tree );
      nTRTHighTHits.WriteTo( tree );
      nBLSharedHits.WriteTo( tree );
      nPixSharedHits.WriteTo( tree );
      nPixHoles.WriteTo( tree );
      nSCTSharedHits.WriteTo( tree );
      nSCTHoles.WriteTo( tree );
      nTRTOutliers.WriteTo( tree );
      nTRTHighTOutliers.WriteTo( tree );
      nGangedPixels.WriteTo( tree );
      nPixelDeadSensors.WriteTo( tree );
      nSCTDeadSensors.WriteTo( tree );
      nTRTDeadStraws.WriteTo( tree );
      expectBLayerHit.WriteTo( tree );
      nMDTHits.WriteTo( tree );
      nMDTHoles.WriteTo( tree );
      nCSCEtaHits.WriteTo( tree );
      nCSCEtaHoles.WriteTo( tree );
      nCSCPhiHits.WriteTo( tree );
      nCSCPhiHoles.WriteTo( tree );
      nRPCEtaHits.WriteTo( tree );
      nRPCEtaHoles.WriteTo( tree );
      nRPCPhiHits.WriteTo( tree );
      nRPCPhiHoles.WriteTo( tree );
      nTGCEtaHits.WriteTo( tree );
      nTGCEtaHoles.WriteTo( tree );
      nTGCPhiHits.WriteTo( tree );
      nTGCPhiHoles.WriteTo( tree );
      nMDTBIHits.WriteTo( tree );
      nMDTBMHits.WriteTo( tree );
      nMDTBOHits.WriteTo( tree );
      nMDTBEEHits.WriteTo( tree );
      nMDTBIS78Hits.WriteTo( tree );
      nMDTEIHits.WriteTo( tree );
      nMDTEMHits.WriteTo( tree );
      nMDTEOHits.WriteTo( tree );
      nMDTEEHits.WriteTo( tree );
      nRPCLayer1EtaHits.WriteTo( tree );
      nRPCLayer2EtaHits.WriteTo( tree );
      nRPCLayer3EtaHits.WriteTo( tree );
      nRPCLayer1PhiHits.WriteTo( tree );
      nRPCLayer2PhiHits.WriteTo( tree );
      nRPCLayer3PhiHits.WriteTo( tree );
      nTGCLayer1EtaHits.WriteTo( tree );
      nTGCLayer2EtaHits.WriteTo( tree );
      nTGCLayer3EtaHits.WriteTo( tree );
      nTGCLayer4EtaHits.WriteTo( tree );
      nTGCLayer1PhiHits.WriteTo( tree );
      nTGCLayer2PhiHits.WriteTo( tree );
      nTGCLayer3PhiHits.WriteTo( tree );
      nTGCLayer4PhiHits.WriteTo( tree );
      barrelSectors.WriteTo( tree );
      endcapSectors.WriteTo( tree );
      trackd0.WriteTo( tree );
      trackz0.WriteTo( tree );
      trackphi.WriteTo( tree );
      tracktheta.WriteTo( tree );
      trackqoverp.WriteTo( tree );
      trackcov_d0.WriteTo( tree );
      trackcov_z0.WriteTo( tree );
      trackcov_phi.WriteTo( tree );
      trackcov_theta.WriteTo( tree );
      trackcov_qoverp.WriteTo( tree );
      trackcov_d0_z0.WriteTo( tree );
      trackcov_d0_phi.WriteTo( tree );
      trackcov_d0_theta.WriteTo( tree );
      trackcov_d0_qoverp.WriteTo( tree );
      trackcov_z0_phi.WriteTo( tree );
      trackcov_z0_theta.WriteTo( tree );
      trackcov_z0_qoverp.WriteTo( tree );
      trackcov_phi_theta.WriteTo( tree );
      trackcov_phi_qoverp.WriteTo( tree );
      trackcov_theta_qoverp.WriteTo( tree );
      trackfitchi2.WriteTo( tree );
      trackfitndof.WriteTo( tree );
      hastrack.WriteTo( tree );
      trackd0beam.WriteTo( tree );
      trackz0beam.WriteTo( tree );
      tracksigd0beam.WriteTo( tree );
      tracksigz0beam.WriteTo( tree );
      trackd0pv.WriteTo( tree );
      trackz0pv.WriteTo( tree );
      tracksigd0pv.WriteTo( tree );
      tracksigz0pv.WriteTo( tree );
      trackIPEstimate_d0_biasedpvunbiased.WriteTo( tree );
      trackIPEstimate_z0_biasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigd0_biasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigz0_biasedpvunbiased.WriteTo( tree );
      trackIPEstimate_d0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_z0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigd0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigz0_unbiasedpvunbiased.WriteTo( tree );
      trackd0pvunbiased.WriteTo( tree );
      trackz0pvunbiased.WriteTo( tree );
      tracksigd0pvunbiased.WriteTo( tree );
      tracksigz0pvunbiased.WriteTo( tree );
      truth_dr.WriteTo( tree );
      truth_matched.WriteTo( tree );
      EFCB_dr.WriteTo( tree );
//       EFCB_n.WriteTo( tree );
//       EFCB_MuonType.WriteTo( tree );
//       EFCB_pt.WriteTo( tree );
//       EFCB_eta.WriteTo( tree );
//       EFCB_phi.WriteTo( tree );
//       EFCB_hasCB.WriteTo( tree );
//       EFCB_matched.WriteTo( tree );
      EFMG_dr.WriteTo( tree );
//       EFMG_n.WriteTo( tree );
//       EFMG_MuonType.WriteTo( tree );
//       EFMG_pt.WriteTo( tree );
//       EFMG_eta.WriteTo( tree );
//       EFMG_phi.WriteTo( tree );
//       EFMG_hasMG.WriteTo( tree );
//       EFMG_matched.WriteTo( tree );
      EFME_dr.WriteTo( tree );
//       EFME_n.WriteTo( tree );
//       EFME_MuonType.WriteTo( tree );
//       EFME_pt.WriteTo( tree );
//       EFME_eta.WriteTo( tree );
//       EFME_phi.WriteTo( tree );
//       EFME_hasME.WriteTo( tree );
//       EFME_matched.WriteTo( tree );
      L2CB_dr.WriteTo( tree );
      L2CB_pt.WriteTo( tree );
      L2CB_eta.WriteTo( tree );
      L2CB_phi.WriteTo( tree );
      L2CB_id_pt.WriteTo( tree );
      L2CB_ms_pt.WriteTo( tree );
      L2CB_nPixHits.WriteTo( tree );
      L2CB_nSCTHits.WriteTo( tree );
      L2CB_nTRTHits.WriteTo( tree );
      L2CB_nTRTHighTHits.WriteTo( tree );
      L2CB_matched.WriteTo( tree );
      L1_dr.WriteTo( tree );
      L1_pt.WriteTo( tree );
      L1_eta.WriteTo( tree );
      L1_phi.WriteTo( tree );
      L1_thrNumber.WriteTo( tree );
      L1_RoINumber.WriteTo( tree );
      L1_sectorAddress.WriteTo( tree );
      L1_firstCandidate.WriteTo( tree );
      L1_moreCandInRoI.WriteTo( tree );
      L1_moreCandInSector.WriteTo( tree );
      L1_source.WriteTo( tree );
      L1_hemisphere.WriteTo( tree );
      L1_charge.WriteTo( tree );
      L1_vetoed.WriteTo( tree );
      L1_matched.WriteTo( tree );

      return;
   }

   /**
    * This is a convenience function for turning the branches active or
    * inactive conveniently. If the parameter is set to <code>kTRUE</code>
    * then the branches available from the input which match the given
    * pattern are turned active.
    * When it's set to <code>kFALSE</code> then all the variables matching
    * the pattern are turned inactive.
    *
    * @param active Flag behaving as explained above
    * @param pattern Regular expression specifying which branches to modify
    */
   void MuonMuidD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

      ::TPRegexp re( pattern );

      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         if( ! re.Match( itr->first ) ) continue;
         if( active ) {
            if( itr->second->IsAvailable() ) itr->second->SetActive( active );
         } else {
            itr->second->SetActive( active );
         }
      }
      return;
   }

   /**
    * This function can be used to read in all the branches from the input
    * TTree which are set active for writing out. This can simplify writing
    * event selector codes immensely. Remember to set the desired variable
    * active before calling this function.
    */
   void MuonMuidD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( n.IsActive() ) n();
      if( E.IsActive() ) E();
      if( pt.IsActive() ) pt();
      if( m.IsActive() ) m();
      if( eta.IsActive() ) eta();
      if( phi.IsActive() ) phi();
      if( px.IsActive() ) px();
      if( py.IsActive() ) py();
      if( pz.IsActive() ) pz();
      if( charge.IsActive() ) charge();
      if( allauthor.IsActive() ) allauthor();
      if( author.IsActive() ) author();
      if( beta.IsActive() ) beta();
      if( isMuonLikelihood.IsActive() ) isMuonLikelihood();
      if( matchchi2.IsActive() ) matchchi2();
      if( matchndof.IsActive() ) matchndof();
      if( etcone20.IsActive() ) etcone20();
      if( etcone30.IsActive() ) etcone30();
      if( etcone40.IsActive() ) etcone40();
      if( nucone20.IsActive() ) nucone20();
      if( nucone30.IsActive() ) nucone30();
      if( nucone40.IsActive() ) nucone40();
      if( ptcone20.IsActive() ) ptcone20();
      if( ptcone30.IsActive() ) ptcone30();
      if( ptcone40.IsActive() ) ptcone40();
      if( energyLossPar.IsActive() ) energyLossPar();
      if( energyLossErr.IsActive() ) energyLossErr();
      if( etCore.IsActive() ) etCore();
      if( energyLossType.IsActive() ) energyLossType();
      if( caloMuonIdTag.IsActive() ) caloMuonIdTag();
      if( caloLRLikelihood.IsActive() ) caloLRLikelihood();
      if( bestMatch.IsActive() ) bestMatch();
      if( isStandAloneMuon.IsActive() ) isStandAloneMuon();
      if( isCombinedMuon.IsActive() ) isCombinedMuon();
      if( isLowPtReconstructedMuon.IsActive() ) isLowPtReconstructedMuon();
      if( isSegmentTaggedMuon.IsActive() ) isSegmentTaggedMuon();
      if( isCaloMuonId.IsActive() ) isCaloMuonId();
      if( alsoFoundByLowPt.IsActive() ) alsoFoundByLowPt();
      if( alsoFoundByCaloMuonId.IsActive() ) alsoFoundByCaloMuonId();
      if( loose.IsActive() ) loose();
      if( medium.IsActive() ) medium();
      if( tight.IsActive() ) tight();
      if( d0_exPV.IsActive() ) d0_exPV();
      if( z0_exPV.IsActive() ) z0_exPV();
      if( phi_exPV.IsActive() ) phi_exPV();
      if( theta_exPV.IsActive() ) theta_exPV();
      if( qoverp_exPV.IsActive() ) qoverp_exPV();
      if( cb_d0_exPV.IsActive() ) cb_d0_exPV();
      if( cb_z0_exPV.IsActive() ) cb_z0_exPV();
      if( cb_phi_exPV.IsActive() ) cb_phi_exPV();
      if( cb_theta_exPV.IsActive() ) cb_theta_exPV();
      if( cb_qoverp_exPV.IsActive() ) cb_qoverp_exPV();
      if( id_d0_exPV.IsActive() ) id_d0_exPV();
      if( id_z0_exPV.IsActive() ) id_z0_exPV();
      if( id_phi_exPV.IsActive() ) id_phi_exPV();
      if( id_theta_exPV.IsActive() ) id_theta_exPV();
      if( id_qoverp_exPV.IsActive() ) id_qoverp_exPV();
      if( me_d0_exPV.IsActive() ) me_d0_exPV();
      if( me_z0_exPV.IsActive() ) me_z0_exPV();
      if( me_phi_exPV.IsActive() ) me_phi_exPV();
      if( me_theta_exPV.IsActive() ) me_theta_exPV();
      if( me_qoverp_exPV.IsActive() ) me_qoverp_exPV();
      if( ie_d0_exPV.IsActive() ) ie_d0_exPV();
      if( ie_z0_exPV.IsActive() ) ie_z0_exPV();
      if( ie_phi_exPV.IsActive() ) ie_phi_exPV();
      if( ie_theta_exPV.IsActive() ) ie_theta_exPV();
      if( ie_qoverp_exPV.IsActive() ) ie_qoverp_exPV();
      if( SpaceTime_detID.IsActive() ) SpaceTime_detID();
      if( SpaceTime_t.IsActive() ) SpaceTime_t();
      if( SpaceTime_tError.IsActive() ) SpaceTime_tError();
      if( SpaceTime_weight.IsActive() ) SpaceTime_weight();
      if( SpaceTime_x.IsActive() ) SpaceTime_x();
      if( SpaceTime_y.IsActive() ) SpaceTime_y();
      if( SpaceTime_z.IsActive() ) SpaceTime_z();
      if( cov_d0_exPV.IsActive() ) cov_d0_exPV();
      if( cov_z0_exPV.IsActive() ) cov_z0_exPV();
      if( cov_phi_exPV.IsActive() ) cov_phi_exPV();
      if( cov_theta_exPV.IsActive() ) cov_theta_exPV();
      if( cov_qoverp_exPV.IsActive() ) cov_qoverp_exPV();
      if( cov_d0_z0_exPV.IsActive() ) cov_d0_z0_exPV();
      if( cov_d0_phi_exPV.IsActive() ) cov_d0_phi_exPV();
      if( cov_d0_theta_exPV.IsActive() ) cov_d0_theta_exPV();
      if( cov_d0_qoverp_exPV.IsActive() ) cov_d0_qoverp_exPV();
      if( cov_z0_phi_exPV.IsActive() ) cov_z0_phi_exPV();
      if( cov_z0_theta_exPV.IsActive() ) cov_z0_theta_exPV();
      if( cov_z0_qoverp_exPV.IsActive() ) cov_z0_qoverp_exPV();
      if( cov_phi_theta_exPV.IsActive() ) cov_phi_theta_exPV();
      if( cov_phi_qoverp_exPV.IsActive() ) cov_phi_qoverp_exPV();
      if( cov_theta_qoverp_exPV.IsActive() ) cov_theta_qoverp_exPV();
      if( id_cov_d0_exPV.IsActive() ) id_cov_d0_exPV();
      if( id_cov_z0_exPV.IsActive() ) id_cov_z0_exPV();
      if( id_cov_phi_exPV.IsActive() ) id_cov_phi_exPV();
      if( id_cov_theta_exPV.IsActive() ) id_cov_theta_exPV();
      if( id_cov_qoverp_exPV.IsActive() ) id_cov_qoverp_exPV();
      if( me_cov_d0_exPV.IsActive() ) me_cov_d0_exPV();
      if( me_cov_z0_exPV.IsActive() ) me_cov_z0_exPV();
      if( me_cov_phi_exPV.IsActive() ) me_cov_phi_exPV();
      if( me_cov_theta_exPV.IsActive() ) me_cov_theta_exPV();
      if( me_cov_qoverp_exPV.IsActive() ) me_cov_qoverp_exPV();
      if( ms_d0.IsActive() ) ms_d0();
      if( ms_z0.IsActive() ) ms_z0();
      if( ms_phi.IsActive() ) ms_phi();
      if( ms_theta.IsActive() ) ms_theta();
      if( ms_qoverp.IsActive() ) ms_qoverp();
      if( id_d0.IsActive() ) id_d0();
      if( id_z0.IsActive() ) id_z0();
      if( id_phi.IsActive() ) id_phi();
      if( id_theta.IsActive() ) id_theta();
      if( id_qoverp.IsActive() ) id_qoverp();
      if( me_d0.IsActive() ) me_d0();
      if( me_z0.IsActive() ) me_z0();
      if( me_phi.IsActive() ) me_phi();
      if( me_theta.IsActive() ) me_theta();
      if( me_qoverp.IsActive() ) me_qoverp();
      if( ie_d0.IsActive() ) ie_d0();
      if( ie_z0.IsActive() ) ie_z0();
      if( ie_phi.IsActive() ) ie_phi();
      if( ie_theta.IsActive() ) ie_theta();
      if( ie_qoverp.IsActive() ) ie_qoverp();
      if( nOutliersOnTrack.IsActive() ) nOutliersOnTrack();
      if( nBLHits.IsActive() ) nBLHits();
      if( nPixHits.IsActive() ) nPixHits();
      if( nSCTHits.IsActive() ) nSCTHits();
      if( nTRTHits.IsActive() ) nTRTHits();
      if( nTRTHighTHits.IsActive() ) nTRTHighTHits();
      if( nBLSharedHits.IsActive() ) nBLSharedHits();
      if( nPixSharedHits.IsActive() ) nPixSharedHits();
      if( nPixHoles.IsActive() ) nPixHoles();
      if( nSCTSharedHits.IsActive() ) nSCTSharedHits();
      if( nSCTHoles.IsActive() ) nSCTHoles();
      if( nTRTOutliers.IsActive() ) nTRTOutliers();
      if( nTRTHighTOutliers.IsActive() ) nTRTHighTOutliers();
      if( nGangedPixels.IsActive() ) nGangedPixels();
      if( nPixelDeadSensors.IsActive() ) nPixelDeadSensors();
      if( nSCTDeadSensors.IsActive() ) nSCTDeadSensors();
      if( nTRTDeadStraws.IsActive() ) nTRTDeadStraws();
      if( expectBLayerHit.IsActive() ) expectBLayerHit();
      if( nMDTHits.IsActive() ) nMDTHits();
      if( nMDTHoles.IsActive() ) nMDTHoles();
      if( nCSCEtaHits.IsActive() ) nCSCEtaHits();
      if( nCSCEtaHoles.IsActive() ) nCSCEtaHoles();
      if( nCSCPhiHits.IsActive() ) nCSCPhiHits();
      if( nCSCPhiHoles.IsActive() ) nCSCPhiHoles();
      if( nRPCEtaHits.IsActive() ) nRPCEtaHits();
      if( nRPCEtaHoles.IsActive() ) nRPCEtaHoles();
      if( nRPCPhiHits.IsActive() ) nRPCPhiHits();
      if( nRPCPhiHoles.IsActive() ) nRPCPhiHoles();
      if( nTGCEtaHits.IsActive() ) nTGCEtaHits();
      if( nTGCEtaHoles.IsActive() ) nTGCEtaHoles();
      if( nTGCPhiHits.IsActive() ) nTGCPhiHits();
      if( nTGCPhiHoles.IsActive() ) nTGCPhiHoles();
      if( nMDTBIHits.IsActive() ) nMDTBIHits();
      if( nMDTBMHits.IsActive() ) nMDTBMHits();
      if( nMDTBOHits.IsActive() ) nMDTBOHits();
      if( nMDTBEEHits.IsActive() ) nMDTBEEHits();
      if( nMDTBIS78Hits.IsActive() ) nMDTBIS78Hits();
      if( nMDTEIHits.IsActive() ) nMDTEIHits();
      if( nMDTEMHits.IsActive() ) nMDTEMHits();
      if( nMDTEOHits.IsActive() ) nMDTEOHits();
      if( nMDTEEHits.IsActive() ) nMDTEEHits();
      if( nRPCLayer1EtaHits.IsActive() ) nRPCLayer1EtaHits();
      if( nRPCLayer2EtaHits.IsActive() ) nRPCLayer2EtaHits();
      if( nRPCLayer3EtaHits.IsActive() ) nRPCLayer3EtaHits();
      if( nRPCLayer1PhiHits.IsActive() ) nRPCLayer1PhiHits();
      if( nRPCLayer2PhiHits.IsActive() ) nRPCLayer2PhiHits();
      if( nRPCLayer3PhiHits.IsActive() ) nRPCLayer3PhiHits();
      if( nTGCLayer1EtaHits.IsActive() ) nTGCLayer1EtaHits();
      if( nTGCLayer2EtaHits.IsActive() ) nTGCLayer2EtaHits();
      if( nTGCLayer3EtaHits.IsActive() ) nTGCLayer3EtaHits();
      if( nTGCLayer4EtaHits.IsActive() ) nTGCLayer4EtaHits();
      if( nTGCLayer1PhiHits.IsActive() ) nTGCLayer1PhiHits();
      if( nTGCLayer2PhiHits.IsActive() ) nTGCLayer2PhiHits();
      if( nTGCLayer3PhiHits.IsActive() ) nTGCLayer3PhiHits();
      if( nTGCLayer4PhiHits.IsActive() ) nTGCLayer4PhiHits();
      if( barrelSectors.IsActive() ) barrelSectors();
      if( endcapSectors.IsActive() ) endcapSectors();
      if( trackd0.IsActive() ) trackd0();
      if( trackz0.IsActive() ) trackz0();
      if( trackphi.IsActive() ) trackphi();
      if( tracktheta.IsActive() ) tracktheta();
      if( trackqoverp.IsActive() ) trackqoverp();
      if( trackcov_d0.IsActive() ) trackcov_d0();
      if( trackcov_z0.IsActive() ) trackcov_z0();
      if( trackcov_phi.IsActive() ) trackcov_phi();
      if( trackcov_theta.IsActive() ) trackcov_theta();
      if( trackcov_qoverp.IsActive() ) trackcov_qoverp();
      if( trackcov_d0_z0.IsActive() ) trackcov_d0_z0();
      if( trackcov_d0_phi.IsActive() ) trackcov_d0_phi();
      if( trackcov_d0_theta.IsActive() ) trackcov_d0_theta();
      if( trackcov_d0_qoverp.IsActive() ) trackcov_d0_qoverp();
      if( trackcov_z0_phi.IsActive() ) trackcov_z0_phi();
      if( trackcov_z0_theta.IsActive() ) trackcov_z0_theta();
      if( trackcov_z0_qoverp.IsActive() ) trackcov_z0_qoverp();
      if( trackcov_phi_theta.IsActive() ) trackcov_phi_theta();
      if( trackcov_phi_qoverp.IsActive() ) trackcov_phi_qoverp();
      if( trackcov_theta_qoverp.IsActive() ) trackcov_theta_qoverp();
      if( trackfitchi2.IsActive() ) trackfitchi2();
      if( trackfitndof.IsActive() ) trackfitndof();
      if( hastrack.IsActive() ) hastrack();
      if( trackd0beam.IsActive() ) trackd0beam();
      if( trackz0beam.IsActive() ) trackz0beam();
      if( tracksigd0beam.IsActive() ) tracksigd0beam();
      if( tracksigz0beam.IsActive() ) tracksigz0beam();
      if( trackd0pv.IsActive() ) trackd0pv();
      if( trackz0pv.IsActive() ) trackz0pv();
      if( tracksigd0pv.IsActive() ) tracksigd0pv();
      if( tracksigz0pv.IsActive() ) tracksigz0pv();
      if( trackIPEstimate_d0_biasedpvunbiased.IsActive() ) trackIPEstimate_d0_biasedpvunbiased();
      if( trackIPEstimate_z0_biasedpvunbiased.IsActive() ) trackIPEstimate_z0_biasedpvunbiased();
      if( trackIPEstimate_sigd0_biasedpvunbiased.IsActive() ) trackIPEstimate_sigd0_biasedpvunbiased();
      if( trackIPEstimate_sigz0_biasedpvunbiased.IsActive() ) trackIPEstimate_sigz0_biasedpvunbiased();
      if( trackIPEstimate_d0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_d0_unbiasedpvunbiased();
      if( trackIPEstimate_z0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_z0_unbiasedpvunbiased();
      if( trackIPEstimate_sigd0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_sigd0_unbiasedpvunbiased();
      if( trackIPEstimate_sigz0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_sigz0_unbiasedpvunbiased();
      if( trackd0pvunbiased.IsActive() ) trackd0pvunbiased();
      if( trackz0pvunbiased.IsActive() ) trackz0pvunbiased();
      if( tracksigd0pvunbiased.IsActive() ) tracksigd0pvunbiased();
      if( tracksigz0pvunbiased.IsActive() ) tracksigz0pvunbiased();
      if( truth_dr.IsActive() ) truth_dr();
      if( truth_matched.IsActive() ) truth_matched();
      if( EFCB_dr.IsActive() ) EFCB_dr();
//       if( EFCB_n.IsActive() ) EFCB_n();
//       if( EFCB_MuonType.IsActive() ) EFCB_MuonType();
//       if( EFCB_pt.IsActive() ) EFCB_pt();
//       if( EFCB_eta.IsActive() ) EFCB_eta();
//       if( EFCB_phi.IsActive() ) EFCB_phi();
//       if( EFCB_hasCB.IsActive() ) EFCB_hasCB();
//       if( EFCB_matched.IsActive() ) EFCB_matched();
       if( EFMG_dr.IsActive() ) EFMG_dr();
//      if( EFMG_n.IsActive() ) EFMG_n();
//       if( EFMG_MuonType.IsActive() ) EFMG_MuonType();
//       if( EFMG_pt.IsActive() ) EFMG_pt();
//       if( EFMG_eta.IsActive() ) EFMG_eta();
//       if( EFMG_phi.IsActive() ) EFMG_phi();
//       if( EFMG_hasMG.IsActive() ) EFMG_hasMG();
//       if( EFMG_matched.IsActive() ) EFMG_matched();
      if( EFME_dr.IsActive() ) EFME_dr();
//       if( EFME_n.IsActive() ) EFME_n();
//       if( EFME_MuonType.IsActive() ) EFME_MuonType();
//       if( EFME_pt.IsActive() ) EFME_pt();
//       if( EFME_eta.IsActive() ) EFME_eta();
//       if( EFME_phi.IsActive() ) EFME_phi();
//       if( EFME_hasME.IsActive() ) EFME_hasME();
//       if( EFME_matched.IsActive() ) EFME_matched();
      if( L2CB_dr.IsActive() ) L2CB_dr();
      if( L2CB_pt.IsActive() ) L2CB_pt();
      if( L2CB_eta.IsActive() ) L2CB_eta();
      if( L2CB_phi.IsActive() ) L2CB_phi();
      if( L2CB_id_pt.IsActive() ) L2CB_id_pt();
      if( L2CB_ms_pt.IsActive() ) L2CB_ms_pt();
      if( L2CB_nPixHits.IsActive() ) L2CB_nPixHits();
      if( L2CB_nSCTHits.IsActive() ) L2CB_nSCTHits();
      if( L2CB_nTRTHits.IsActive() ) L2CB_nTRTHits();
      if( L2CB_nTRTHighTHits.IsActive() ) L2CB_nTRTHighTHits();
      if( L2CB_matched.IsActive() ) L2CB_matched();
      if( L1_dr.IsActive() ) L1_dr();
      if( L1_pt.IsActive() ) L1_pt();
      if( L1_eta.IsActive() ) L1_eta();
      if( L1_phi.IsActive() ) L1_phi();
      if( L1_thrNumber.IsActive() ) L1_thrNumber();
      if( L1_RoINumber.IsActive() ) L1_RoINumber();
      if( L1_sectorAddress.IsActive() ) L1_sectorAddress();
      if( L1_firstCandidate.IsActive() ) L1_firstCandidate();
      if( L1_moreCandInRoI.IsActive() ) L1_moreCandInRoI();
      if( L1_moreCandInSector.IsActive() ) L1_moreCandInSector();
      if( L1_source.IsActive() ) L1_source();
      if( L1_hemisphere.IsActive() ) L1_hemisphere();
      if( L1_charge.IsActive() ) L1_charge();
      if( L1_vetoed.IsActive() ) L1_vetoed();
      if( L1_matched.IsActive() ) L1_matched();

      return;
   }

   /**
    * This function makes it easier to clear out the object completely.
    * It cleares all the vector variables, and sets the element number
    * variable to 0. Very useful when performing object selection.
    * The option argument is not used at the moment for anything.
    * It's only there because the <code>Clear</code> function defined in
    * TObject has this parameter as well.
    *
    * @param option Ignored at the moment
    */
   void MuonMuidD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      n() = 0;
      E()->clear();
      pt()->clear();
      m()->clear();
      eta()->clear();
      phi()->clear();
      px()->clear();
      py()->clear();
      pz()->clear();
      charge()->clear();
      allauthor()->clear();
      author()->clear();
      beta()->clear();
      isMuonLikelihood()->clear();
      matchchi2()->clear();
      matchndof()->clear();
      etcone20()->clear();
      etcone30()->clear();
      etcone40()->clear();
      nucone20()->clear();
      nucone30()->clear();
      nucone40()->clear();
      ptcone20()->clear();
      ptcone30()->clear();
      ptcone40()->clear();
      energyLossPar()->clear();
      energyLossErr()->clear();
      etCore()->clear();
      energyLossType()->clear();
      caloMuonIdTag()->clear();
      caloLRLikelihood()->clear();
      bestMatch()->clear();
      isStandAloneMuon()->clear();
      isCombinedMuon()->clear();
      isLowPtReconstructedMuon()->clear();
      isSegmentTaggedMuon()->clear();
      isCaloMuonId()->clear();
      alsoFoundByLowPt()->clear();
      alsoFoundByCaloMuonId()->clear();
      loose()->clear();
      medium()->clear();
      tight()->clear();
      d0_exPV()->clear();
      z0_exPV()->clear();
      phi_exPV()->clear();
      theta_exPV()->clear();
      qoverp_exPV()->clear();
      cb_d0_exPV()->clear();
      cb_z0_exPV()->clear();
      cb_phi_exPV()->clear();
      cb_theta_exPV()->clear();
      cb_qoverp_exPV()->clear();
      id_d0_exPV()->clear();
      id_z0_exPV()->clear();
      id_phi_exPV()->clear();
      id_theta_exPV()->clear();
      id_qoverp_exPV()->clear();
      me_d0_exPV()->clear();
      me_z0_exPV()->clear();
      me_phi_exPV()->clear();
      me_theta_exPV()->clear();
      me_qoverp_exPV()->clear();
      ie_d0_exPV()->clear();
      ie_z0_exPV()->clear();
      ie_phi_exPV()->clear();
      ie_theta_exPV()->clear();
      ie_qoverp_exPV()->clear();
      SpaceTime_detID()->clear();
      SpaceTime_t()->clear();
      SpaceTime_tError()->clear();
      SpaceTime_weight()->clear();
      SpaceTime_x()->clear();
      SpaceTime_y()->clear();
      SpaceTime_z()->clear();
      cov_d0_exPV()->clear();
      cov_z0_exPV()->clear();
      cov_phi_exPV()->clear();
      cov_theta_exPV()->clear();
      cov_qoverp_exPV()->clear();
      cov_d0_z0_exPV()->clear();
      cov_d0_phi_exPV()->clear();
      cov_d0_theta_exPV()->clear();
      cov_d0_qoverp_exPV()->clear();
      cov_z0_phi_exPV()->clear();
      cov_z0_theta_exPV()->clear();
      cov_z0_qoverp_exPV()->clear();
      cov_phi_theta_exPV()->clear();
      cov_phi_qoverp_exPV()->clear();
      cov_theta_qoverp_exPV()->clear();
      id_cov_d0_exPV()->clear();
      id_cov_z0_exPV()->clear();
      id_cov_phi_exPV()->clear();
      id_cov_theta_exPV()->clear();
      id_cov_qoverp_exPV()->clear();
      me_cov_d0_exPV()->clear();
      me_cov_z0_exPV()->clear();
      me_cov_phi_exPV()->clear();
      me_cov_theta_exPV()->clear();
      me_cov_qoverp_exPV()->clear();
      ms_d0()->clear();
      ms_z0()->clear();
      ms_phi()->clear();
      ms_theta()->clear();
      ms_qoverp()->clear();
      id_d0()->clear();
      id_z0()->clear();
      id_phi()->clear();
      id_theta()->clear();
      id_qoverp()->clear();
      me_d0()->clear();
      me_z0()->clear();
      me_phi()->clear();
      me_theta()->clear();
      me_qoverp()->clear();
      ie_d0()->clear();
      ie_z0()->clear();
      ie_phi()->clear();
      ie_theta()->clear();
      ie_qoverp()->clear();
      nOutliersOnTrack()->clear();
      nBLHits()->clear();
      nPixHits()->clear();
      nSCTHits()->clear();
      nTRTHits()->clear();
      nTRTHighTHits()->clear();
      nBLSharedHits()->clear();
      nPixSharedHits()->clear();
      nPixHoles()->clear();
      nSCTSharedHits()->clear();
      nSCTHoles()->clear();
      nTRTOutliers()->clear();
      nTRTHighTOutliers()->clear();
      nGangedPixels()->clear();
      nPixelDeadSensors()->clear();
      nSCTDeadSensors()->clear();
      nTRTDeadStraws()->clear();
      expectBLayerHit()->clear();
      nMDTHits()->clear();
      nMDTHoles()->clear();
      nCSCEtaHits()->clear();
      nCSCEtaHoles()->clear();
      nCSCPhiHits()->clear();
      nCSCPhiHoles()->clear();
      nRPCEtaHits()->clear();
      nRPCEtaHoles()->clear();
      nRPCPhiHits()->clear();
      nRPCPhiHoles()->clear();
      nTGCEtaHits()->clear();
      nTGCEtaHoles()->clear();
      nTGCPhiHits()->clear();
      nTGCPhiHoles()->clear();
      nMDTBIHits()->clear();
      nMDTBMHits()->clear();
      nMDTBOHits()->clear();
      nMDTBEEHits()->clear();
      nMDTBIS78Hits()->clear();
      nMDTEIHits()->clear();
      nMDTEMHits()->clear();
      nMDTEOHits()->clear();
      nMDTEEHits()->clear();
      nRPCLayer1EtaHits()->clear();
      nRPCLayer2EtaHits()->clear();
      nRPCLayer3EtaHits()->clear();
      nRPCLayer1PhiHits()->clear();
      nRPCLayer2PhiHits()->clear();
      nRPCLayer3PhiHits()->clear();
      nTGCLayer1EtaHits()->clear();
      nTGCLayer2EtaHits()->clear();
      nTGCLayer3EtaHits()->clear();
      nTGCLayer4EtaHits()->clear();
      nTGCLayer1PhiHits()->clear();
      nTGCLayer2PhiHits()->clear();
      nTGCLayer3PhiHits()->clear();
      nTGCLayer4PhiHits()->clear();
      barrelSectors()->clear();
      endcapSectors()->clear();
      trackd0()->clear();
      trackz0()->clear();
      trackphi()->clear();
      tracktheta()->clear();
      trackqoverp()->clear();
      trackcov_d0()->clear();
      trackcov_z0()->clear();
      trackcov_phi()->clear();
      trackcov_theta()->clear();
      trackcov_qoverp()->clear();
      trackcov_d0_z0()->clear();
      trackcov_d0_phi()->clear();
      trackcov_d0_theta()->clear();
      trackcov_d0_qoverp()->clear();
      trackcov_z0_phi()->clear();
      trackcov_z0_theta()->clear();
      trackcov_z0_qoverp()->clear();
      trackcov_phi_theta()->clear();
      trackcov_phi_qoverp()->clear();
      trackcov_theta_qoverp()->clear();
      trackfitchi2()->clear();
      trackfitndof()->clear();
      hastrack()->clear();
      trackd0beam()->clear();
      trackz0beam()->clear();
      tracksigd0beam()->clear();
      tracksigz0beam()->clear();
      trackd0pv()->clear();
      trackz0pv()->clear();
      tracksigd0pv()->clear();
      tracksigz0pv()->clear();
      trackIPEstimate_d0_biasedpvunbiased()->clear();
      trackIPEstimate_z0_biasedpvunbiased()->clear();
      trackIPEstimate_sigd0_biasedpvunbiased()->clear();
      trackIPEstimate_sigz0_biasedpvunbiased()->clear();
      trackIPEstimate_d0_unbiasedpvunbiased()->clear();
      trackIPEstimate_z0_unbiasedpvunbiased()->clear();
      trackIPEstimate_sigd0_unbiasedpvunbiased()->clear();
      trackIPEstimate_sigz0_unbiasedpvunbiased()->clear();
      trackd0pvunbiased()->clear();
      trackz0pvunbiased()->clear();
      tracksigd0pvunbiased()->clear();
      tracksigz0pvunbiased()->clear();
      truth_dr()->clear();
      truth_matched()->clear();
      EFCB_dr()->clear();
//       EFCB_n()->clear();
//       EFCB_MuonType()->clear();
//       EFCB_pt()->clear();
//       EFCB_eta()->clear();
//       EFCB_phi()->clear();
//       EFCB_hasCB()->clear();
//       EFCB_matched()->clear();
      EFMG_dr()->clear();
//       EFMG_n()->clear();
//       EFMG_MuonType()->clear();
//       EFMG_pt()->clear();
//       EFMG_eta()->clear();
//       EFMG_phi()->clear();
//       EFMG_hasMG()->clear();
//       EFMG_matched()->clear();
      EFME_dr()->clear();
//       EFME_n()->clear();
//       EFME_MuonType()->clear();
//       EFME_pt()->clear();
//       EFME_eta()->clear();
//       EFME_phi()->clear();
//       EFME_hasME()->clear();
//       EFME_matched()->clear();
      L2CB_dr()->clear();
      L2CB_pt()->clear();
      L2CB_eta()->clear();
      L2CB_phi()->clear();
      L2CB_id_pt()->clear();
      L2CB_ms_pt()->clear();
      L2CB_nPixHits()->clear();
      L2CB_nSCTHits()->clear();
      L2CB_nTRTHits()->clear();
      L2CB_nTRTHighTHits()->clear();
      L2CB_matched()->clear();
      L1_dr()->clear();
      L1_pt()->clear();
      L1_eta()->clear();
      L1_phi()->clear();
      L1_thrNumber()->clear();
      L1_RoINumber()->clear();
      L1_sectorAddress()->clear();
      L1_firstCandidate()->clear();
      L1_moreCandInRoI()->clear();
      L1_moreCandInSector()->clear();
      L1_source()->clear();
      L1_hemisphere()->clear();
      L1_charge()->clear();
      L1_vetoed()->clear();
      L1_matched()->clear();

      return;
   }

   /**
    * This function can be used to easily add an 'element' describing one
    * object to an output collection. Comes in very handy when performing
    * object selection.
    *
    * Note that variables which are not available from the input, will be
    * filled with dummy values.
    *
    * @param el The 'element' that should be added to the collection
    */
   MuonMuidD3PDObject& MuonMuidD3PDObject::Add( const MuonMuidD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      ++( n() );
      if( el.E.IsAvailable() ) {
         E()->push_back( el.E() );
      } else {
         E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pt.IsAvailable() ) {
         pt()->push_back( el.pt() );
      } else {
         pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eta.IsAvailable() ) {
         eta()->push_back( el.eta() );
      } else {
         eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phi.IsAvailable() ) {
         phi()->push_back( el.phi() );
      } else {
         phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.px.IsAvailable() ) {
         px()->push_back( el.px() );
      } else {
         px()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.py.IsAvailable() ) {
         py()->push_back( el.py() );
      } else {
         py()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pz.IsAvailable() ) {
         pz()->push_back( el.pz() );
      } else {
         pz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.charge.IsAvailable() ) {
         charge()->push_back( el.charge() );
      } else {
         charge()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.allauthor.IsAvailable() ) {
         allauthor()->push_back( el.allauthor() );
      } else {
         allauthor()->push_back( std::numeric_limits< unsigned short >::min() );
      }
      if( el.author.IsAvailable() ) {
         author()->push_back( el.author() );
      } else {
         author()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.beta.IsAvailable() ) {
         beta()->push_back( el.beta() );
      } else {
         beta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.isMuonLikelihood.IsAvailable() ) {
         isMuonLikelihood()->push_back( el.isMuonLikelihood() );
      } else {
         isMuonLikelihood()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.matchchi2.IsAvailable() ) {
         matchchi2()->push_back( el.matchchi2() );
      } else {
         matchchi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.matchndof.IsAvailable() ) {
         matchndof()->push_back( el.matchndof() );
      } else {
         matchndof()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.etcone20.IsAvailable() ) {
         etcone20()->push_back( el.etcone20() );
      } else {
         etcone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etcone30.IsAvailable() ) {
         etcone30()->push_back( el.etcone30() );
      } else {
         etcone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etcone40.IsAvailable() ) {
         etcone40()->push_back( el.etcone40() );
      } else {
         etcone40()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone20.IsAvailable() ) {
         nucone20()->push_back( el.nucone20() );
      } else {
         nucone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone30.IsAvailable() ) {
         nucone30()->push_back( el.nucone30() );
      } else {
         nucone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone40.IsAvailable() ) {
         nucone40()->push_back( el.nucone40() );
      } else {
         nucone40()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone20.IsAvailable() ) {
         ptcone20()->push_back( el.ptcone20() );
      } else {
         ptcone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone30.IsAvailable() ) {
         ptcone30()->push_back( el.ptcone30() );
      } else {
         ptcone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone40.IsAvailable() ) {
         ptcone40()->push_back( el.ptcone40() );
      } else {
         ptcone40()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.energyLossPar.IsAvailable() ) {
         energyLossPar()->push_back( el.energyLossPar() );
      } else {
         energyLossPar()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.energyLossErr.IsAvailable() ) {
         energyLossErr()->push_back( el.energyLossErr() );
      } else {
         energyLossErr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etCore.IsAvailable() ) {
         etCore()->push_back( el.etCore() );
      } else {
         etCore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.energyLossType.IsAvailable() ) {
         energyLossType()->push_back( el.energyLossType() );
      } else {
         energyLossType()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.caloMuonIdTag.IsAvailable() ) {
         caloMuonIdTag()->push_back( el.caloMuonIdTag() );
      } else {
         caloMuonIdTag()->push_back( std::numeric_limits< unsigned short >::min() );
      }
      if( el.caloLRLikelihood.IsAvailable() ) {
         caloLRLikelihood()->push_back( el.caloLRLikelihood() );
      } else {
         caloLRLikelihood()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.bestMatch.IsAvailable() ) {
         bestMatch()->push_back( el.bestMatch() );
      } else {
         bestMatch()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isStandAloneMuon.IsAvailable() ) {
         isStandAloneMuon()->push_back( el.isStandAloneMuon() );
      } else {
         isStandAloneMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isCombinedMuon.IsAvailable() ) {
         isCombinedMuon()->push_back( el.isCombinedMuon() );
      } else {
         isCombinedMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isLowPtReconstructedMuon.IsAvailable() ) {
         isLowPtReconstructedMuon()->push_back( el.isLowPtReconstructedMuon() );
      } else {
         isLowPtReconstructedMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isSegmentTaggedMuon.IsAvailable() ) {
         isSegmentTaggedMuon()->push_back( el.isSegmentTaggedMuon() );
      } else {
         isSegmentTaggedMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isCaloMuonId.IsAvailable() ) {
         isCaloMuonId()->push_back( el.isCaloMuonId() );
      } else {
         isCaloMuonId()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.alsoFoundByLowPt.IsAvailable() ) {
         alsoFoundByLowPt()->push_back( el.alsoFoundByLowPt() );
      } else {
         alsoFoundByLowPt()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.alsoFoundByCaloMuonId.IsAvailable() ) {
         alsoFoundByCaloMuonId()->push_back( el.alsoFoundByCaloMuonId() );
      } else {
         alsoFoundByCaloMuonId()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.loose.IsAvailable() ) {
         loose()->push_back( el.loose() );
      } else {
         loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.medium.IsAvailable() ) {
         medium()->push_back( el.medium() );
      } else {
         medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tight.IsAvailable() ) {
         tight()->push_back( el.tight() );
      } else {
         tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.d0_exPV.IsAvailable() ) {
         d0_exPV()->push_back( el.d0_exPV() );
      } else {
         d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.z0_exPV.IsAvailable() ) {
         z0_exPV()->push_back( el.z0_exPV() );
      } else {
         z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phi_exPV.IsAvailable() ) {
         phi_exPV()->push_back( el.phi_exPV() );
      } else {
         phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.theta_exPV.IsAvailable() ) {
         theta_exPV()->push_back( el.theta_exPV() );
      } else {
         theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.qoverp_exPV.IsAvailable() ) {
         qoverp_exPV()->push_back( el.qoverp_exPV() );
      } else {
         qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_d0_exPV.IsAvailable() ) {
         cb_d0_exPV()->push_back( el.cb_d0_exPV() );
      } else {
         cb_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_z0_exPV.IsAvailable() ) {
         cb_z0_exPV()->push_back( el.cb_z0_exPV() );
      } else {
         cb_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_phi_exPV.IsAvailable() ) {
         cb_phi_exPV()->push_back( el.cb_phi_exPV() );
      } else {
         cb_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_theta_exPV.IsAvailable() ) {
         cb_theta_exPV()->push_back( el.cb_theta_exPV() );
      } else {
         cb_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_qoverp_exPV.IsAvailable() ) {
         cb_qoverp_exPV()->push_back( el.cb_qoverp_exPV() );
      } else {
         cb_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_d0_exPV.IsAvailable() ) {
         id_d0_exPV()->push_back( el.id_d0_exPV() );
      } else {
         id_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_z0_exPV.IsAvailable() ) {
         id_z0_exPV()->push_back( el.id_z0_exPV() );
      } else {
         id_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_phi_exPV.IsAvailable() ) {
         id_phi_exPV()->push_back( el.id_phi_exPV() );
      } else {
         id_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_theta_exPV.IsAvailable() ) {
         id_theta_exPV()->push_back( el.id_theta_exPV() );
      } else {
         id_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_qoverp_exPV.IsAvailable() ) {
         id_qoverp_exPV()->push_back( el.id_qoverp_exPV() );
      } else {
         id_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_d0_exPV.IsAvailable() ) {
         me_d0_exPV()->push_back( el.me_d0_exPV() );
      } else {
         me_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_z0_exPV.IsAvailable() ) {
         me_z0_exPV()->push_back( el.me_z0_exPV() );
      } else {
         me_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_phi_exPV.IsAvailable() ) {
         me_phi_exPV()->push_back( el.me_phi_exPV() );
      } else {
         me_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_theta_exPV.IsAvailable() ) {
         me_theta_exPV()->push_back( el.me_theta_exPV() );
      } else {
         me_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_qoverp_exPV.IsAvailable() ) {
         me_qoverp_exPV()->push_back( el.me_qoverp_exPV() );
      } else {
         me_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_d0_exPV.IsAvailable() ) {
         ie_d0_exPV()->push_back( el.ie_d0_exPV() );
      } else {
         ie_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_z0_exPV.IsAvailable() ) {
         ie_z0_exPV()->push_back( el.ie_z0_exPV() );
      } else {
         ie_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_phi_exPV.IsAvailable() ) {
         ie_phi_exPV()->push_back( el.ie_phi_exPV() );
      } else {
         ie_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_theta_exPV.IsAvailable() ) {
         ie_theta_exPV()->push_back( el.ie_theta_exPV() );
      } else {
         ie_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_qoverp_exPV.IsAvailable() ) {
         ie_qoverp_exPV()->push_back( el.ie_qoverp_exPV() );
      } else {
         ie_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.SpaceTime_detID.IsAvailable() ) {
         SpaceTime_detID()->push_back( el.SpaceTime_detID() );
      } else {
         SpaceTime_detID()->push_back( vector<int>() );
      }
      if( el.SpaceTime_t.IsAvailable() ) {
         SpaceTime_t()->push_back( el.SpaceTime_t() );
      } else {
         SpaceTime_t()->push_back( vector<float>() );
      }
      if( el.SpaceTime_tError.IsAvailable() ) {
         SpaceTime_tError()->push_back( el.SpaceTime_tError() );
      } else {
         SpaceTime_tError()->push_back( vector<float>() );
      }
      if( el.SpaceTime_weight.IsAvailable() ) {
         SpaceTime_weight()->push_back( el.SpaceTime_weight() );
      } else {
         SpaceTime_weight()->push_back( vector<float>() );
      }
      if( el.SpaceTime_x.IsAvailable() ) {
         SpaceTime_x()->push_back( el.SpaceTime_x() );
      } else {
         SpaceTime_x()->push_back( vector<float>() );
      }
      if( el.SpaceTime_y.IsAvailable() ) {
         SpaceTime_y()->push_back( el.SpaceTime_y() );
      } else {
         SpaceTime_y()->push_back( vector<float>() );
      }
      if( el.SpaceTime_z.IsAvailable() ) {
         SpaceTime_z()->push_back( el.SpaceTime_z() );
      } else {
         SpaceTime_z()->push_back( vector<float>() );
      }
      if( el.cov_d0_exPV.IsAvailable() ) {
         cov_d0_exPV()->push_back( el.cov_d0_exPV() );
      } else {
         cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_exPV.IsAvailable() ) {
         cov_z0_exPV()->push_back( el.cov_z0_exPV() );
      } else {
         cov_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_phi_exPV.IsAvailable() ) {
         cov_phi_exPV()->push_back( el.cov_phi_exPV() );
      } else {
         cov_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_theta_exPV.IsAvailable() ) {
         cov_theta_exPV()->push_back( el.cov_theta_exPV() );
      } else {
         cov_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_qoverp_exPV.IsAvailable() ) {
         cov_qoverp_exPV()->push_back( el.cov_qoverp_exPV() );
      } else {
         cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_z0_exPV.IsAvailable() ) {
         cov_d0_z0_exPV()->push_back( el.cov_d0_z0_exPV() );
      } else {
         cov_d0_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_phi_exPV.IsAvailable() ) {
         cov_d0_phi_exPV()->push_back( el.cov_d0_phi_exPV() );
      } else {
         cov_d0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_theta_exPV.IsAvailable() ) {
         cov_d0_theta_exPV()->push_back( el.cov_d0_theta_exPV() );
      } else {
         cov_d0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_qoverp_exPV.IsAvailable() ) {
         cov_d0_qoverp_exPV()->push_back( el.cov_d0_qoverp_exPV() );
      } else {
         cov_d0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_phi_exPV.IsAvailable() ) {
         cov_z0_phi_exPV()->push_back( el.cov_z0_phi_exPV() );
      } else {
         cov_z0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_theta_exPV.IsAvailable() ) {
         cov_z0_theta_exPV()->push_back( el.cov_z0_theta_exPV() );
      } else {
         cov_z0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_qoverp_exPV.IsAvailable() ) {
         cov_z0_qoverp_exPV()->push_back( el.cov_z0_qoverp_exPV() );
      } else {
         cov_z0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_phi_theta_exPV.IsAvailable() ) {
         cov_phi_theta_exPV()->push_back( el.cov_phi_theta_exPV() );
      } else {
         cov_phi_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_phi_qoverp_exPV.IsAvailable() ) {
         cov_phi_qoverp_exPV()->push_back( el.cov_phi_qoverp_exPV() );
      } else {
         cov_phi_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_theta_qoverp_exPV.IsAvailable() ) {
         cov_theta_qoverp_exPV()->push_back( el.cov_theta_qoverp_exPV() );
      } else {
         cov_theta_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_exPV.IsAvailable() ) {
         id_cov_d0_exPV()->push_back( el.id_cov_d0_exPV() );
      } else {
         id_cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_z0_exPV.IsAvailable() ) {
         id_cov_z0_exPV()->push_back( el.id_cov_z0_exPV() );
      } else {
         id_cov_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_phi_exPV.IsAvailable() ) {
         id_cov_phi_exPV()->push_back( el.id_cov_phi_exPV() );
      } else {
         id_cov_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_theta_exPV.IsAvailable() ) {
         id_cov_theta_exPV()->push_back( el.id_cov_theta_exPV() );
      } else {
         id_cov_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_qoverp_exPV.IsAvailable() ) {
         id_cov_qoverp_exPV()->push_back( el.id_cov_qoverp_exPV() );
      } else {
         id_cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_d0_exPV.IsAvailable() ) {
         me_cov_d0_exPV()->push_back( el.me_cov_d0_exPV() );
      } else {
         me_cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_z0_exPV.IsAvailable() ) {
         me_cov_z0_exPV()->push_back( el.me_cov_z0_exPV() );
      } else {
         me_cov_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_phi_exPV.IsAvailable() ) {
         me_cov_phi_exPV()->push_back( el.me_cov_phi_exPV() );
      } else {
         me_cov_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_theta_exPV.IsAvailable() ) {
         me_cov_theta_exPV()->push_back( el.me_cov_theta_exPV() );
      } else {
         me_cov_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_qoverp_exPV.IsAvailable() ) {
         me_cov_qoverp_exPV()->push_back( el.me_cov_qoverp_exPV() );
      } else {
         me_cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_d0.IsAvailable() ) {
         ms_d0()->push_back( el.ms_d0() );
      } else {
         ms_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_z0.IsAvailable() ) {
         ms_z0()->push_back( el.ms_z0() );
      } else {
         ms_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_phi.IsAvailable() ) {
         ms_phi()->push_back( el.ms_phi() );
      } else {
         ms_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_theta.IsAvailable() ) {
         ms_theta()->push_back( el.ms_theta() );
      } else {
         ms_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_qoverp.IsAvailable() ) {
         ms_qoverp()->push_back( el.ms_qoverp() );
      } else {
         ms_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_d0.IsAvailable() ) {
         id_d0()->push_back( el.id_d0() );
      } else {
         id_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_z0.IsAvailable() ) {
         id_z0()->push_back( el.id_z0() );
      } else {
         id_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_phi.IsAvailable() ) {
         id_phi()->push_back( el.id_phi() );
      } else {
         id_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_theta.IsAvailable() ) {
         id_theta()->push_back( el.id_theta() );
      } else {
         id_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_qoverp.IsAvailable() ) {
         id_qoverp()->push_back( el.id_qoverp() );
      } else {
         id_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_d0.IsAvailable() ) {
         me_d0()->push_back( el.me_d0() );
      } else {
         me_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_z0.IsAvailable() ) {
         me_z0()->push_back( el.me_z0() );
      } else {
         me_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_phi.IsAvailable() ) {
         me_phi()->push_back( el.me_phi() );
      } else {
         me_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_theta.IsAvailable() ) {
         me_theta()->push_back( el.me_theta() );
      } else {
         me_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_qoverp.IsAvailable() ) {
         me_qoverp()->push_back( el.me_qoverp() );
      } else {
         me_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_d0.IsAvailable() ) {
         ie_d0()->push_back( el.ie_d0() );
      } else {
         ie_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_z0.IsAvailable() ) {
         ie_z0()->push_back( el.ie_z0() );
      } else {
         ie_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_phi.IsAvailable() ) {
         ie_phi()->push_back( el.ie_phi() );
      } else {
         ie_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_theta.IsAvailable() ) {
         ie_theta()->push_back( el.ie_theta() );
      } else {
         ie_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_qoverp.IsAvailable() ) {
         ie_qoverp()->push_back( el.ie_qoverp() );
      } else {
         ie_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nOutliersOnTrack.IsAvailable() ) {
         nOutliersOnTrack()->push_back( el.nOutliersOnTrack() );
      } else {
         nOutliersOnTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nBLHits.IsAvailable() ) {
         nBLHits()->push_back( el.nBLHits() );
      } else {
         nBLHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixHits.IsAvailable() ) {
         nPixHits()->push_back( el.nPixHits() );
      } else {
         nPixHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTHits.IsAvailable() ) {
         nSCTHits()->push_back( el.nSCTHits() );
      } else {
         nSCTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHits.IsAvailable() ) {
         nTRTHits()->push_back( el.nTRTHits() );
      } else {
         nTRTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHighTHits.IsAvailable() ) {
         nTRTHighTHits()->push_back( el.nTRTHighTHits() );
      } else {
         nTRTHighTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nBLSharedHits.IsAvailable() ) {
         nBLSharedHits()->push_back( el.nBLSharedHits() );
      } else {
         nBLSharedHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixSharedHits.IsAvailable() ) {
         nPixSharedHits()->push_back( el.nPixSharedHits() );
      } else {
         nPixSharedHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixHoles.IsAvailable() ) {
         nPixHoles()->push_back( el.nPixHoles() );
      } else {
         nPixHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTSharedHits.IsAvailable() ) {
         nSCTSharedHits()->push_back( el.nSCTSharedHits() );
      } else {
         nSCTSharedHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTHoles.IsAvailable() ) {
         nSCTHoles()->push_back( el.nSCTHoles() );
      } else {
         nSCTHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTOutliers.IsAvailable() ) {
         nTRTOutliers()->push_back( el.nTRTOutliers() );
      } else {
         nTRTOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHighTOutliers.IsAvailable() ) {
         nTRTHighTOutliers()->push_back( el.nTRTHighTOutliers() );
      } else {
         nTRTHighTOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nGangedPixels.IsAvailable() ) {
         nGangedPixels()->push_back( el.nGangedPixels() );
      } else {
         nGangedPixels()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixelDeadSensors.IsAvailable() ) {
         nPixelDeadSensors()->push_back( el.nPixelDeadSensors() );
      } else {
         nPixelDeadSensors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTDeadSensors.IsAvailable() ) {
         nSCTDeadSensors()->push_back( el.nSCTDeadSensors() );
      } else {
         nSCTDeadSensors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTDeadStraws.IsAvailable() ) {
         nTRTDeadStraws()->push_back( el.nTRTDeadStraws() );
      } else {
         nTRTDeadStraws()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.expectBLayerHit.IsAvailable() ) {
         expectBLayerHit()->push_back( el.expectBLayerHit() );
      } else {
         expectBLayerHit()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTHits.IsAvailable() ) {
         nMDTHits()->push_back( el.nMDTHits() );
      } else {
         nMDTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTHoles.IsAvailable() ) {
         nMDTHoles()->push_back( el.nMDTHoles() );
      } else {
         nMDTHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nCSCEtaHits.IsAvailable() ) {
         nCSCEtaHits()->push_back( el.nCSCEtaHits() );
      } else {
         nCSCEtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nCSCEtaHoles.IsAvailable() ) {
         nCSCEtaHoles()->push_back( el.nCSCEtaHoles() );
      } else {
         nCSCEtaHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nCSCPhiHits.IsAvailable() ) {
         nCSCPhiHits()->push_back( el.nCSCPhiHits() );
      } else {
         nCSCPhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nCSCPhiHoles.IsAvailable() ) {
         nCSCPhiHoles()->push_back( el.nCSCPhiHoles() );
      } else {
         nCSCPhiHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCEtaHits.IsAvailable() ) {
         nRPCEtaHits()->push_back( el.nRPCEtaHits() );
      } else {
         nRPCEtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCEtaHoles.IsAvailable() ) {
         nRPCEtaHoles()->push_back( el.nRPCEtaHoles() );
      } else {
         nRPCEtaHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCPhiHits.IsAvailable() ) {
         nRPCPhiHits()->push_back( el.nRPCPhiHits() );
      } else {
         nRPCPhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCPhiHoles.IsAvailable() ) {
         nRPCPhiHoles()->push_back( el.nRPCPhiHoles() );
      } else {
         nRPCPhiHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCEtaHits.IsAvailable() ) {
         nTGCEtaHits()->push_back( el.nTGCEtaHits() );
      } else {
         nTGCEtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCEtaHoles.IsAvailable() ) {
         nTGCEtaHoles()->push_back( el.nTGCEtaHoles() );
      } else {
         nTGCEtaHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCPhiHits.IsAvailable() ) {
         nTGCPhiHits()->push_back( el.nTGCPhiHits() );
      } else {
         nTGCPhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCPhiHoles.IsAvailable() ) {
         nTGCPhiHoles()->push_back( el.nTGCPhiHoles() );
      } else {
         nTGCPhiHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBIHits.IsAvailable() ) {
         nMDTBIHits()->push_back( el.nMDTBIHits() );
      } else {
         nMDTBIHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBMHits.IsAvailable() ) {
         nMDTBMHits()->push_back( el.nMDTBMHits() );
      } else {
         nMDTBMHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBOHits.IsAvailable() ) {
         nMDTBOHits()->push_back( el.nMDTBOHits() );
      } else {
         nMDTBOHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBEEHits.IsAvailable() ) {
         nMDTBEEHits()->push_back( el.nMDTBEEHits() );
      } else {
         nMDTBEEHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBIS78Hits.IsAvailable() ) {
         nMDTBIS78Hits()->push_back( el.nMDTBIS78Hits() );
      } else {
         nMDTBIS78Hits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTEIHits.IsAvailable() ) {
         nMDTEIHits()->push_back( el.nMDTEIHits() );
      } else {
         nMDTEIHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTEMHits.IsAvailable() ) {
         nMDTEMHits()->push_back( el.nMDTEMHits() );
      } else {
         nMDTEMHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTEOHits.IsAvailable() ) {
         nMDTEOHits()->push_back( el.nMDTEOHits() );
      } else {
         nMDTEOHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTEEHits.IsAvailable() ) {
         nMDTEEHits()->push_back( el.nMDTEEHits() );
      } else {
         nMDTEEHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer1EtaHits.IsAvailable() ) {
         nRPCLayer1EtaHits()->push_back( el.nRPCLayer1EtaHits() );
      } else {
         nRPCLayer1EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer2EtaHits.IsAvailable() ) {
         nRPCLayer2EtaHits()->push_back( el.nRPCLayer2EtaHits() );
      } else {
         nRPCLayer2EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer3EtaHits.IsAvailable() ) {
         nRPCLayer3EtaHits()->push_back( el.nRPCLayer3EtaHits() );
      } else {
         nRPCLayer3EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer1PhiHits.IsAvailable() ) {
         nRPCLayer1PhiHits()->push_back( el.nRPCLayer1PhiHits() );
      } else {
         nRPCLayer1PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer2PhiHits.IsAvailable() ) {
         nRPCLayer2PhiHits()->push_back( el.nRPCLayer2PhiHits() );
      } else {
         nRPCLayer2PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer3PhiHits.IsAvailable() ) {
         nRPCLayer3PhiHits()->push_back( el.nRPCLayer3PhiHits() );
      } else {
         nRPCLayer3PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer1EtaHits.IsAvailable() ) {
         nTGCLayer1EtaHits()->push_back( el.nTGCLayer1EtaHits() );
      } else {
         nTGCLayer1EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer2EtaHits.IsAvailable() ) {
         nTGCLayer2EtaHits()->push_back( el.nTGCLayer2EtaHits() );
      } else {
         nTGCLayer2EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer3EtaHits.IsAvailable() ) {
         nTGCLayer3EtaHits()->push_back( el.nTGCLayer3EtaHits() );
      } else {
         nTGCLayer3EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer4EtaHits.IsAvailable() ) {
         nTGCLayer4EtaHits()->push_back( el.nTGCLayer4EtaHits() );
      } else {
         nTGCLayer4EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer1PhiHits.IsAvailable() ) {
         nTGCLayer1PhiHits()->push_back( el.nTGCLayer1PhiHits() );
      } else {
         nTGCLayer1PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer2PhiHits.IsAvailable() ) {
         nTGCLayer2PhiHits()->push_back( el.nTGCLayer2PhiHits() );
      } else {
         nTGCLayer2PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer3PhiHits.IsAvailable() ) {
         nTGCLayer3PhiHits()->push_back( el.nTGCLayer3PhiHits() );
      } else {
         nTGCLayer3PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer4PhiHits.IsAvailable() ) {
         nTGCLayer4PhiHits()->push_back( el.nTGCLayer4PhiHits() );
      } else {
         nTGCLayer4PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.barrelSectors.IsAvailable() ) {
         barrelSectors()->push_back( el.barrelSectors() );
      } else {
         barrelSectors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.endcapSectors.IsAvailable() ) {
         endcapSectors()->push_back( el.endcapSectors() );
      } else {
         endcapSectors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trackd0.IsAvailable() ) {
         trackd0()->push_back( el.trackd0() );
      } else {
         trackd0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0.IsAvailable() ) {
         trackz0()->push_back( el.trackz0() );
      } else {
         trackz0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackphi.IsAvailable() ) {
         trackphi()->push_back( el.trackphi() );
      } else {
         trackphi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracktheta.IsAvailable() ) {
         tracktheta()->push_back( el.tracktheta() );
      } else {
         tracktheta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackqoverp.IsAvailable() ) {
         trackqoverp()->push_back( el.trackqoverp() );
      } else {
         trackqoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0.IsAvailable() ) {
         trackcov_d0()->push_back( el.trackcov_d0() );
      } else {
         trackcov_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0.IsAvailable() ) {
         trackcov_z0()->push_back( el.trackcov_z0() );
      } else {
         trackcov_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_phi.IsAvailable() ) {
         trackcov_phi()->push_back( el.trackcov_phi() );
      } else {
         trackcov_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_theta.IsAvailable() ) {
         trackcov_theta()->push_back( el.trackcov_theta() );
      } else {
         trackcov_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_qoverp.IsAvailable() ) {
         trackcov_qoverp()->push_back( el.trackcov_qoverp() );
      } else {
         trackcov_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_z0.IsAvailable() ) {
         trackcov_d0_z0()->push_back( el.trackcov_d0_z0() );
      } else {
         trackcov_d0_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_phi.IsAvailable() ) {
         trackcov_d0_phi()->push_back( el.trackcov_d0_phi() );
      } else {
         trackcov_d0_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_theta.IsAvailable() ) {
         trackcov_d0_theta()->push_back( el.trackcov_d0_theta() );
      } else {
         trackcov_d0_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_qoverp.IsAvailable() ) {
         trackcov_d0_qoverp()->push_back( el.trackcov_d0_qoverp() );
      } else {
         trackcov_d0_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0_phi.IsAvailable() ) {
         trackcov_z0_phi()->push_back( el.trackcov_z0_phi() );
      } else {
         trackcov_z0_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0_theta.IsAvailable() ) {
         trackcov_z0_theta()->push_back( el.trackcov_z0_theta() );
      } else {
         trackcov_z0_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0_qoverp.IsAvailable() ) {
         trackcov_z0_qoverp()->push_back( el.trackcov_z0_qoverp() );
      } else {
         trackcov_z0_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_phi_theta.IsAvailable() ) {
         trackcov_phi_theta()->push_back( el.trackcov_phi_theta() );
      } else {
         trackcov_phi_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_phi_qoverp.IsAvailable() ) {
         trackcov_phi_qoverp()->push_back( el.trackcov_phi_qoverp() );
      } else {
         trackcov_phi_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_theta_qoverp.IsAvailable() ) {
         trackcov_theta_qoverp()->push_back( el.trackcov_theta_qoverp() );
      } else {
         trackcov_theta_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackfitchi2.IsAvailable() ) {
         trackfitchi2()->push_back( el.trackfitchi2() );
      } else {
         trackfitchi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackfitndof.IsAvailable() ) {
         trackfitndof()->push_back( el.trackfitndof() );
      } else {
         trackfitndof()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.hastrack.IsAvailable() ) {
         hastrack()->push_back( el.hastrack() );
      } else {
         hastrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trackd0beam.IsAvailable() ) {
         trackd0beam()->push_back( el.trackd0beam() );
      } else {
         trackd0beam()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0beam.IsAvailable() ) {
         trackz0beam()->push_back( el.trackz0beam() );
      } else {
         trackz0beam()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigd0beam.IsAvailable() ) {
         tracksigd0beam()->push_back( el.tracksigd0beam() );
      } else {
         tracksigd0beam()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigz0beam.IsAvailable() ) {
         tracksigz0beam()->push_back( el.tracksigz0beam() );
      } else {
         tracksigz0beam()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackd0pv.IsAvailable() ) {
         trackd0pv()->push_back( el.trackd0pv() );
      } else {
         trackd0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0pv.IsAvailable() ) {
         trackz0pv()->push_back( el.trackz0pv() );
      } else {
         trackz0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigd0pv.IsAvailable() ) {
         tracksigd0pv()->push_back( el.tracksigd0pv() );
      } else {
         tracksigd0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigz0pv.IsAvailable() ) {
         tracksigz0pv()->push_back( el.tracksigz0pv() );
      } else {
         tracksigz0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_d0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_d0_biasedpvunbiased()->push_back( el.trackIPEstimate_d0_biasedpvunbiased() );
      } else {
         trackIPEstimate_d0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_z0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_z0_biasedpvunbiased()->push_back( el.trackIPEstimate_z0_biasedpvunbiased() );
      } else {
         trackIPEstimate_z0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigd0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigd0_biasedpvunbiased()->push_back( el.trackIPEstimate_sigd0_biasedpvunbiased() );
      } else {
         trackIPEstimate_sigd0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigz0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigz0_biasedpvunbiased()->push_back( el.trackIPEstimate_sigz0_biasedpvunbiased() );
      } else {
         trackIPEstimate_sigz0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_d0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_d0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_d0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_d0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_z0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_z0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_z0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_z0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigd0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigd0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_sigd0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_sigd0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigz0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigz0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_sigz0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_sigz0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackd0pvunbiased.IsAvailable() ) {
         trackd0pvunbiased()->push_back( el.trackd0pvunbiased() );
      } else {
         trackd0pvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0pvunbiased.IsAvailable() ) {
         trackz0pvunbiased()->push_back( el.trackz0pvunbiased() );
      } else {
         trackz0pvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigd0pvunbiased.IsAvailable() ) {
         tracksigd0pvunbiased()->push_back( el.tracksigd0pvunbiased() );
      } else {
         tracksigd0pvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigz0pvunbiased.IsAvailable() ) {
         tracksigz0pvunbiased()->push_back( el.tracksigz0pvunbiased() );
      } else {
         tracksigz0pvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_dr.IsAvailable() ) {
         truth_dr()->push_back( el.truth_dr() );
      } else {
         truth_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_matched.IsAvailable() ) {
         truth_matched()->push_back( el.truth_matched() );
      } else {
         truth_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EFCB_dr.IsAvailable() ) {
         EFCB_dr()->push_back( el.EFCB_dr() );
      } else {
         EFCB_dr()->push_back( std::numeric_limits< float >::min() );
      }
//       if( el.EFCB_n.IsAvailable() ) {
//          EFCB_n()->push_back( el.EFCB_n() );
//       } else {
//          EFCB_n()->push_back( std::numeric_limits< int >::min() );
//       }
//       if( el.EFCB_MuonType.IsAvailable() ) {
//          EFCB_MuonType()->push_back( el.EFCB_MuonType() );
//       } else {
//          EFCB_MuonType()->push_back( vector<int>() );
//       }
//       if( el.EFCB_pt.IsAvailable() ) {
//          EFCB_pt()->push_back( el.EFCB_pt() );
//       } else {
//          EFCB_pt()->push_back( vector<float>() );
//       }
//       if( el.EFCB_eta.IsAvailable() ) {
//          EFCB_eta()->push_back( el.EFCB_eta() );
//       } else {
//          EFCB_eta()->push_back( vector<float>() );
//       }
//       if( el.EFCB_phi.IsAvailable() ) {
//          EFCB_phi()->push_back( el.EFCB_phi() );
//       } else {
//          EFCB_phi()->push_back( vector<float>() );
//       }
//       if( el.EFCB_hasCB.IsAvailable() ) {
//          EFCB_hasCB()->push_back( el.EFCB_hasCB() );
//       } else {
//          EFCB_hasCB()->push_back( vector<int>() );
//       }
//       if( el.EFCB_matched.IsAvailable() ) {
//          EFCB_matched()->push_back( el.EFCB_matched() );
//       } else {
//          EFCB_matched()->push_back( std::numeric_limits< int >::min() );
//       }
      if( el.EFMG_dr.IsAvailable() ) {
         EFMG_dr()->push_back( el.EFMG_dr() );
      } else {
         EFMG_dr()->push_back( std::numeric_limits< float >::min() );
      }
//       if( el.EFMG_n.IsAvailable() ) {
//          EFMG_n()->push_back( el.EFMG_n() );
//       } else {
//          EFMG_n()->push_back( std::numeric_limits< int >::min() );
//       }
//       if( el.EFMG_MuonType.IsAvailable() ) {
//          EFMG_MuonType()->push_back( el.EFMG_MuonType() );
//       } else {
//          EFMG_MuonType()->push_back( vector<int>() );
//       }
//       if( el.EFMG_pt.IsAvailable() ) {
//          EFMG_pt()->push_back( el.EFMG_pt() );
//       } else {
//          EFMG_pt()->push_back( vector<float>() );
//       }
//       if( el.EFMG_eta.IsAvailable() ) {
//          EFMG_eta()->push_back( el.EFMG_eta() );
//       } else {
//          EFMG_eta()->push_back( vector<float>() );
//       }
//       if( el.EFMG_phi.IsAvailable() ) {
//          EFMG_phi()->push_back( el.EFMG_phi() );
//       } else {
//          EFMG_phi()->push_back( vector<float>() );
//       }
//       if( el.EFMG_hasMG.IsAvailable() ) {
//          EFMG_hasMG()->push_back( el.EFMG_hasMG() );
//       } else {
//          EFMG_hasMG()->push_back( vector<int>() );
//       }
//       if( el.EFMG_matched.IsAvailable() ) {
//          EFMG_matched()->push_back( el.EFMG_matched() );
//       } else {
//          EFMG_matched()->push_back( std::numeric_limits< int >::min() );
//       }
      if( el.EFME_dr.IsAvailable() ) {
         EFME_dr()->push_back( el.EFME_dr() );
      } else {
         EFME_dr()->push_back( std::numeric_limits< float >::min() );
      }
//       if( el.EFME_n.IsAvailable() ) {
//          EFME_n()->push_back( el.EFME_n() );
//       } else {
//          EFME_n()->push_back( std::numeric_limits< int >::min() );
//       }
//       if( el.EFME_MuonType.IsAvailable() ) {
//          EFME_MuonType()->push_back( el.EFME_MuonType() );
//       } else {
//          EFME_MuonType()->push_back( vector<int>() );
//       }
//       if( el.EFME_pt.IsAvailable() ) {
//          EFME_pt()->push_back( el.EFME_pt() );
//       } else {
//          EFME_pt()->push_back( vector<float>() );
//       }
//       if( el.EFME_eta.IsAvailable() ) {
//          EFME_eta()->push_back( el.EFME_eta() );
//       } else {
//          EFME_eta()->push_back( vector<float>() );
//       }
//       if( el.EFME_phi.IsAvailable() ) {
//          EFME_phi()->push_back( el.EFME_phi() );
//       } else {
//          EFME_phi()->push_back( vector<float>() );
//       }
//       if( el.EFME_hasME.IsAvailable() ) {
//          EFME_hasME()->push_back( el.EFME_hasME() );
//       } else {
//          EFME_hasME()->push_back( vector<int>() );
//       }
//       if( el.EFME_matched.IsAvailable() ) {
//          EFME_matched()->push_back( el.EFME_matched() );
//       } else {
//          EFME_matched()->push_back( std::numeric_limits< int >::min() );
//       }
      if( el.L2CB_dr.IsAvailable() ) {
         L2CB_dr()->push_back( el.L2CB_dr() );
      } else {
         L2CB_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2CB_pt.IsAvailable() ) {
         L2CB_pt()->push_back( el.L2CB_pt() );
      } else {
         L2CB_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2CB_eta.IsAvailable() ) {
         L2CB_eta()->push_back( el.L2CB_eta() );
      } else {
         L2CB_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2CB_phi.IsAvailable() ) {
         L2CB_phi()->push_back( el.L2CB_phi() );
      } else {
         L2CB_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2CB_id_pt.IsAvailable() ) {
         L2CB_id_pt()->push_back( el.L2CB_id_pt() );
      } else {
         L2CB_id_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2CB_ms_pt.IsAvailable() ) {
         L2CB_ms_pt()->push_back( el.L2CB_ms_pt() );
      } else {
         L2CB_ms_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2CB_nPixHits.IsAvailable() ) {
         L2CB_nPixHits()->push_back( el.L2CB_nPixHits() );
      } else {
         L2CB_nPixHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L2CB_nSCTHits.IsAvailable() ) {
         L2CB_nSCTHits()->push_back( el.L2CB_nSCTHits() );
      } else {
         L2CB_nSCTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L2CB_nTRTHits.IsAvailable() ) {
         L2CB_nTRTHits()->push_back( el.L2CB_nTRTHits() );
      } else {
         L2CB_nTRTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L2CB_nTRTHighTHits.IsAvailable() ) {
         L2CB_nTRTHighTHits()->push_back( el.L2CB_nTRTHighTHits() );
      } else {
         L2CB_nTRTHighTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L2CB_matched.IsAvailable() ) {
         L2CB_matched()->push_back( el.L2CB_matched() );
      } else {
         L2CB_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L1_dr.IsAvailable() ) {
         L1_dr()->push_back( el.L1_dr() );
      } else {
         L1_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_pt.IsAvailable() ) {
         L1_pt()->push_back( el.L1_pt() );
      } else {
         L1_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_eta.IsAvailable() ) {
         L1_eta()->push_back( el.L1_eta() );
      } else {
         L1_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_phi.IsAvailable() ) {
         L1_phi()->push_back( el.L1_phi() );
      } else {
         L1_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_thrNumber.IsAvailable() ) {
         L1_thrNumber()->push_back( el.L1_thrNumber() );
      } else {
         L1_thrNumber()->push_back( std::numeric_limits< short >::min() );
      }
      if( el.L1_RoINumber.IsAvailable() ) {
         L1_RoINumber()->push_back( el.L1_RoINumber() );
      } else {
         L1_RoINumber()->push_back( std::numeric_limits< short >::min() );
      }
      if( el.L1_sectorAddress.IsAvailable() ) {
         L1_sectorAddress()->push_back( el.L1_sectorAddress() );
      } else {
         L1_sectorAddress()->push_back( std::numeric_limits< short >::min() );
      }
      if( el.L1_firstCandidate.IsAvailable() ) {
         L1_firstCandidate()->push_back( el.L1_firstCandidate() );
      } else {
         L1_firstCandidate()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L1_moreCandInRoI.IsAvailable() ) {
         L1_moreCandInRoI()->push_back( el.L1_moreCandInRoI() );
      } else {
         L1_moreCandInRoI()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L1_moreCandInSector.IsAvailable() ) {
         L1_moreCandInSector()->push_back( el.L1_moreCandInSector() );
      } else {
         L1_moreCandInSector()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L1_source.IsAvailable() ) {
         L1_source()->push_back( el.L1_source() );
      } else {
         L1_source()->push_back( std::numeric_limits< short >::min() );
      }
      if( el.L1_hemisphere.IsAvailable() ) {
         L1_hemisphere()->push_back( el.L1_hemisphere() );
      } else {
         L1_hemisphere()->push_back( std::numeric_limits< short >::min() );
      }
      if( el.L1_charge.IsAvailable() ) {
         L1_charge()->push_back( el.L1_charge() );
      } else {
         L1_charge()->push_back( std::numeric_limits< short >::min() );
      }
      if( el.L1_vetoed.IsAvailable() ) {
         L1_vetoed()->push_back( el.L1_vetoed() );
      } else {
         L1_vetoed()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L1_matched.IsAvailable() ) {
         L1_matched()->push_back( el.L1_matched() );
      } else {
         L1_matched()->push_back( std::numeric_limits< int >::min() );
      }
      return *this;
   }

   /**
    * This operator can be used to get access to one element in the
    * collection. This element can then be passed around between parts
    * of the analysis code easily.
    *
    * This version is useful when modifying the variable contents through
    * the proxy objects.
    *
    * @param index Index of the element inside the collection
    */
   MuonMuidD3PDObjectElement& MuonMuidD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( MuonMuidD3PDObjectElement( fProxies.size(), *this ) );
      }
      return fProxies[ index ];
   }

   /**
    * This operator can be used to get access to one element in the
    * collection. This element can then be passed around between parts
    * of the analysis code easily.
    *
    * This version is useful when only reading the variables.
    *
    * @param index Index of the element inside the collection
    */
   const MuonMuidD3PDObjectElement& MuonMuidD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( MuonMuidD3PDObjectElement( fProxies.size(), *this ) );
      }
      return fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   MuonMuidD3PDObject& MuonMuidD3PDObject::operator+=( const MuonMuidD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
