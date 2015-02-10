// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/MuonD3PDObject.h"

ClassImp( D3PDReader::MuonD3PDObjectElement )
ClassImp( D3PDReader::MuonD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class MuonD3PDObject.
    */
   MuonD3PDObjectElement::MuonD3PDObjectElement( size_t index, const MuonD3PDObject& parent )
      : E( parent.E, index, this ),
        EFCB_index( parent.EFCB_index, index, this ),
        EFME_index( parent.EFME_index, index, this ),
        EFMG_index( parent.EFMG_index, index, this ),
        SpaceTime_detID( parent.SpaceTime_detID, index, this ),
        SpaceTime_t( parent.SpaceTime_t, index, this ),
        SpaceTime_tError( parent.SpaceTime_tError, index, this ),
        SpaceTime_weight( parent.SpaceTime_weight, index, this ),
        SpaceTime_x( parent.SpaceTime_x, index, this ),
        SpaceTime_y( parent.SpaceTime_y, index, this ),
        SpaceTime_z( parent.SpaceTime_z, index, this ),
        allauthor( parent.allauthor, index, this ),
        alsoFoundByCaloMuonId( parent.alsoFoundByCaloMuonId, index, this ),
        alsoFoundByLowPt( parent.alsoFoundByLowPt, index, this ),
        author( parent.author, index, this ),
        barrelSectors( parent.barrelSectors, index, this ),
        bestMatch( parent.bestMatch, index, this ),
        beta( parent.beta, index, this ),
        caloLRLikelihood( parent.caloLRLikelihood, index, this ),
        caloMuonIdTag( parent.caloMuonIdTag, index, this ),
        cb_d0_exPV( parent.cb_d0_exPV, index, this ),
        cb_phi_exPV( parent.cb_phi_exPV, index, this ),
        cb_qoverp_exPV( parent.cb_qoverp_exPV, index, this ),
        cb_theta_exPV( parent.cb_theta_exPV, index, this ),
        cb_z0_exPV( parent.cb_z0_exPV, index, this ),
        charge( parent.charge, index, this ),
        cov_d0_exPV( parent.cov_d0_exPV, index, this ),
        cov_d0_phi_exPV( parent.cov_d0_phi_exPV, index, this ),
        cov_d0_qoverp_exPV( parent.cov_d0_qoverp_exPV, index, this ),
        cov_d0_theta_exPV( parent.cov_d0_theta_exPV, index, this ),
        cov_d0_z0_exPV( parent.cov_d0_z0_exPV, index, this ),
        cov_phi_exPV( parent.cov_phi_exPV, index, this ),
        cov_phi_qoverp_exPV( parent.cov_phi_qoverp_exPV, index, this ),
        cov_phi_theta_exPV( parent.cov_phi_theta_exPV, index, this ),
        cov_qoverp_exPV( parent.cov_qoverp_exPV, index, this ),
        cov_theta_exPV( parent.cov_theta_exPV, index, this ),
        cov_theta_qoverp_exPV( parent.cov_theta_qoverp_exPV, index, this ),
        cov_z0_exPV( parent.cov_z0_exPV, index, this ),
        cov_z0_phi_exPV( parent.cov_z0_phi_exPV, index, this ),
        cov_z0_qoverp_exPV( parent.cov_z0_qoverp_exPV, index, this ),
        cov_z0_theta_exPV( parent.cov_z0_theta_exPV, index, this ),
        d0_exPV( parent.d0_exPV, index, this ),
        endcapSectors( parent.endcapSectors, index, this ),
        energyLossErr( parent.energyLossErr, index, this ),
        energyLossPar( parent.energyLossPar, index, this ),
        energyLossType( parent.energyLossType, index, this ),
        etCore( parent.etCore, index, this ),
        eta( parent.eta, index, this ),
        etcone20( parent.etcone20, index, this ),
        etcone30( parent.etcone30, index, this ),
        etcone40( parent.etcone40, index, this ),
        expectBLayerHit( parent.expectBLayerHit, index, this ),
        hastrack( parent.hastrack, index, this ),
        id_cov_d0_exPV( parent.id_cov_d0_exPV, index, this ),
        id_cov_d0_phi_exPV( parent.id_cov_d0_phi_exPV, index, this ),
        id_cov_d0_qoverp_exPV( parent.id_cov_d0_qoverp_exPV, index, this ),
        id_cov_d0_theta_exPV( parent.id_cov_d0_theta_exPV, index, this ),
        id_cov_d0_z0_exPV( parent.id_cov_d0_z0_exPV, index, this ),
        id_cov_phi_exPV( parent.id_cov_phi_exPV, index, this ),
        id_cov_phi_qoverp_exPV( parent.id_cov_phi_qoverp_exPV, index, this ),
        id_cov_phi_theta_exPV( parent.id_cov_phi_theta_exPV, index, this ),
        id_cov_qoverp_exPV( parent.id_cov_qoverp_exPV, index, this ),
        id_cov_theta_exPV( parent.id_cov_theta_exPV, index, this ),
        id_cov_theta_qoverp_exPV( parent.id_cov_theta_qoverp_exPV, index, this ),
        id_cov_z0_exPV( parent.id_cov_z0_exPV, index, this ),
        id_cov_z0_phi_exPV( parent.id_cov_z0_phi_exPV, index, this ),
        id_cov_z0_qoverp_exPV( parent.id_cov_z0_qoverp_exPV, index, this ),
        id_cov_z0_theta_exPV( parent.id_cov_z0_theta_exPV, index, this ),
        id_d0( parent.id_d0, index, this ),
        id_d0_exPV( parent.id_d0_exPV, index, this ),
        id_phi( parent.id_phi, index, this ),
        id_phi_exPV( parent.id_phi_exPV, index, this ),
        id_qoverp( parent.id_qoverp, index, this ),
        id_qoverp_exPV( parent.id_qoverp_exPV, index, this ),
        id_theta( parent.id_theta, index, this ),
        id_theta_exPV( parent.id_theta_exPV, index, this ),
        id_z0( parent.id_z0, index, this ),
        id_z0_exPV( parent.id_z0_exPV, index, this ),
        ie_d0( parent.ie_d0, index, this ),
        ie_d0_exPV( parent.ie_d0_exPV, index, this ),
        ie_phi( parent.ie_phi, index, this ),
        ie_phi_exPV( parent.ie_phi_exPV, index, this ),
        ie_qoverp( parent.ie_qoverp, index, this ),
        ie_qoverp_exPV( parent.ie_qoverp_exPV, index, this ),
        ie_theta( parent.ie_theta, index, this ),
        ie_theta_exPV( parent.ie_theta_exPV, index, this ),
        ie_z0( parent.ie_z0, index, this ),
        ie_z0_exPV( parent.ie_z0_exPV, index, this ),
        isCaloMuonId( parent.isCaloMuonId, index, this ),
        isCombinedMuon( parent.isCombinedMuon, index, this ),
        isLowPtReconstructedMuon( parent.isLowPtReconstructedMuon, index, this ),
        isMuonLikelihood( parent.isMuonLikelihood, index, this ),
        isSegmentTaggedMuon( parent.isSegmentTaggedMuon, index, this ),
        isSiliconAssociatedForwardMuon( parent.isSiliconAssociatedForwardMuon, index, this ),
        isStandAloneMuon( parent.isStandAloneMuon, index, this ),
        loose( parent.loose, index, this ),
        m( parent.m, index, this ),
        matchchi2( parent.matchchi2, index, this ),
        matchndof( parent.matchndof, index, this ),
        me_cov_d0_exPV( parent.me_cov_d0_exPV, index, this ),
        me_cov_d0_phi_exPV( parent.me_cov_d0_phi_exPV, index, this ),
        me_cov_d0_qoverp_exPV( parent.me_cov_d0_qoverp_exPV, index, this ),
        me_cov_d0_theta_exPV( parent.me_cov_d0_theta_exPV, index, this ),
        me_cov_d0_z0_exPV( parent.me_cov_d0_z0_exPV, index, this ),
        me_cov_phi_exPV( parent.me_cov_phi_exPV, index, this ),
        me_cov_phi_qoverp_exPV( parent.me_cov_phi_qoverp_exPV, index, this ),
        me_cov_phi_theta_exPV( parent.me_cov_phi_theta_exPV, index, this ),
        me_cov_qoverp_exPV( parent.me_cov_qoverp_exPV, index, this ),
        me_cov_theta_exPV( parent.me_cov_theta_exPV, index, this ),
        me_cov_theta_qoverp_exPV( parent.me_cov_theta_qoverp_exPV, index, this ),
        me_cov_z0_exPV( parent.me_cov_z0_exPV, index, this ),
        me_cov_z0_phi_exPV( parent.me_cov_z0_phi_exPV, index, this ),
        me_cov_z0_qoverp_exPV( parent.me_cov_z0_qoverp_exPV, index, this ),
        me_cov_z0_theta_exPV( parent.me_cov_z0_theta_exPV, index, this ),
        me_d0( parent.me_d0, index, this ),
        me_d0_exPV( parent.me_d0_exPV, index, this ),
        me_phi( parent.me_phi, index, this ),
        me_phi_exPV( parent.me_phi_exPV, index, this ),
        me_qoverp( parent.me_qoverp, index, this ),
        me_qoverp_exPV( parent.me_qoverp_exPV, index, this ),
        me_theta( parent.me_theta, index, this ),
        me_theta_exPV( parent.me_theta_exPV, index, this ),
        me_z0( parent.me_z0, index, this ),
        me_z0_exPV( parent.me_z0_exPV, index, this ),
        medium( parent.medium, index, this ),
        momentumBalanceSignificance( parent.momentumBalanceSignificance, index, this ),
        ms_d0( parent.ms_d0, index, this ),
        ms_phi( parent.ms_phi, index, this ),
        ms_qoverp( parent.ms_qoverp, index, this ),
        ms_theta( parent.ms_theta, index, this ),
        ms_z0( parent.ms_z0, index, this ),
        nBLHits( parent.nBLHits, index, this ),
        nBLSharedHits( parent.nBLSharedHits, index, this ),
        nCSCEtaHits( parent.nCSCEtaHits, index, this ),
        nCSCEtaHoles( parent.nCSCEtaHoles, index, this ),
        nCSCPhiHits( parent.nCSCPhiHits, index, this ),
        nCSCPhiHoles( parent.nCSCPhiHoles, index, this ),
        nCSCUnspoiledEtaHits( parent.nCSCUnspoiledEtaHits, index, this ),
        nGangedPixels( parent.nGangedPixels, index, this ),
        nMDTBEEHits( parent.nMDTBEEHits, index, this ),
        nMDTBIHits( parent.nMDTBIHits, index, this ),
        nMDTBIS78Hits( parent.nMDTBIS78Hits, index, this ),
        nMDTBMHits( parent.nMDTBMHits, index, this ),
        nMDTBOHits( parent.nMDTBOHits, index, this ),
        nMDTEEHits( parent.nMDTEEHits, index, this ),
        nMDTEIHits( parent.nMDTEIHits, index, this ),
        nMDTEMHits( parent.nMDTEMHits, index, this ),
        nMDTEOHits( parent.nMDTEOHits, index, this ),
        nMDTHits( parent.nMDTHits, index, this ),
        nMDTHoles( parent.nMDTHoles, index, this ),
        nOutliersOnTrack( parent.nOutliersOnTrack, index, this ),
        nPixHits( parent.nPixHits, index, this ),
        nPixHoles( parent.nPixHoles, index, this ),
        nPixSharedHits( parent.nPixSharedHits, index, this ),
        nPixelDeadSensors( parent.nPixelDeadSensors, index, this ),
        nRPCEtaHits( parent.nRPCEtaHits, index, this ),
        nRPCEtaHoles( parent.nRPCEtaHoles, index, this ),
        nRPCLayer1EtaHits( parent.nRPCLayer1EtaHits, index, this ),
        nRPCLayer1PhiHits( parent.nRPCLayer1PhiHits, index, this ),
        nRPCLayer2EtaHits( parent.nRPCLayer2EtaHits, index, this ),
        nRPCLayer2PhiHits( parent.nRPCLayer2PhiHits, index, this ),
        nRPCLayer3EtaHits( parent.nRPCLayer3EtaHits, index, this ),
        nRPCLayer3PhiHits( parent.nRPCLayer3PhiHits, index, this ),
        nRPCPhiHits( parent.nRPCPhiHits, index, this ),
        nRPCPhiHoles( parent.nRPCPhiHoles, index, this ),
        nSCTDeadSensors( parent.nSCTDeadSensors, index, this ),
        nSCTHits( parent.nSCTHits, index, this ),
        nSCTHoles( parent.nSCTHoles, index, this ),
        nSCTSharedHits( parent.nSCTSharedHits, index, this ),
        nTGCEtaHits( parent.nTGCEtaHits, index, this ),
        nTGCEtaHoles( parent.nTGCEtaHoles, index, this ),
        nTGCLayer1EtaHits( parent.nTGCLayer1EtaHits, index, this ),
        nTGCLayer1PhiHits( parent.nTGCLayer1PhiHits, index, this ),
        nTGCLayer2EtaHits( parent.nTGCLayer2EtaHits, index, this ),
        nTGCLayer2PhiHits( parent.nTGCLayer2PhiHits, index, this ),
        nTGCLayer3EtaHits( parent.nTGCLayer3EtaHits, index, this ),
        nTGCLayer3PhiHits( parent.nTGCLayer3PhiHits, index, this ),
        nTGCLayer4EtaHits( parent.nTGCLayer4EtaHits, index, this ),
        nTGCLayer4PhiHits( parent.nTGCLayer4PhiHits, index, this ),
        nTGCPhiHits( parent.nTGCPhiHits, index, this ),
        nTGCPhiHoles( parent.nTGCPhiHoles, index, this ),
        nTRTDeadStraws( parent.nTRTDeadStraws, index, this ),
        nTRTHighTHits( parent.nTRTHighTHits, index, this ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers, index, this ),
        nTRTHits( parent.nTRTHits, index, this ),
        nTRTOutliers( parent.nTRTOutliers, index, this ),
        nphiHoleLayers( parent.nphiHoleLayers, index, this ),
        nphiLayers( parent.nphiLayers, index, this ),
        nprecisionHoleLayers( parent.nprecisionHoleLayers, index, this ),
        nprecisionLayers( parent.nprecisionLayers, index, this ),
        ntrigEtaHoleLayers( parent.ntrigEtaHoleLayers, index, this ),
        ntrigEtaLayers( parent.ntrigEtaLayers, index, this ),
        nucone20( parent.nucone20, index, this ),
        nucone30( parent.nucone30, index, this ),
        nucone40( parent.nucone40, index, this ),
        origin( parent.origin, index, this ),
        phi( parent.phi, index, this ),
        phi_exPV( parent.phi_exPV, index, this ),
        pt( parent.pt, index, this ),
        ptcone20( parent.ptcone20, index, this ),
        ptcone30( parent.ptcone30, index, this ),
        ptcone40( parent.ptcone40, index, this ),
        px( parent.px, index, this ),
        py( parent.py, index, this ),
        pz( parent.pz, index, this ),
        qoverp_exPV( parent.qoverp_exPV, index, this ),
        scatteringCurvatureSignificance( parent.scatteringCurvatureSignificance, index, this ),
        scatteringNeighbourSignificance( parent.scatteringNeighbourSignificance, index, this ),
        theta_exPV( parent.theta_exPV, index, this ),
        tight( parent.tight, index, this ),
        trackIPEstimate_d0_biasedpvunbiased( parent.trackIPEstimate_d0_biasedpvunbiased, index, this ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_sigd0_biasedpvunbiased( parent.trackIPEstimate_sigd0_biasedpvunbiased, index, this ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_sigz0_biasedpvunbiased( parent.trackIPEstimate_sigz0_biasedpvunbiased, index, this ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_z0_biasedpvunbiased( parent.trackIPEstimate_z0_biasedpvunbiased, index, this ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased, index, this ),
        trackcov_d0( parent.trackcov_d0, index, this ),
        trackcov_d0_phi( parent.trackcov_d0_phi, index, this ),
        trackcov_d0_qoverp( parent.trackcov_d0_qoverp, index, this ),
        trackcov_d0_theta( parent.trackcov_d0_theta, index, this ),
        trackcov_d0_z0( parent.trackcov_d0_z0, index, this ),
        trackcov_phi( parent.trackcov_phi, index, this ),
        trackcov_phi_qoverp( parent.trackcov_phi_qoverp, index, this ),
        trackcov_phi_theta( parent.trackcov_phi_theta, index, this ),
        trackcov_qoverp( parent.trackcov_qoverp, index, this ),
        trackcov_theta( parent.trackcov_theta, index, this ),
        trackcov_theta_qoverp( parent.trackcov_theta_qoverp, index, this ),
        trackcov_z0( parent.trackcov_z0, index, this ),
        trackcov_z0_phi( parent.trackcov_z0_phi, index, this ),
        trackcov_z0_qoverp( parent.trackcov_z0_qoverp, index, this ),
        trackcov_z0_theta( parent.trackcov_z0_theta, index, this ),
        trackd0( parent.trackd0, index, this ),
        trackd0beam( parent.trackd0beam, index, this ),
        trackd0pv( parent.trackd0pv, index, this ),
        trackd0pvunbiased( parent.trackd0pvunbiased, index, this ),
        trackfitchi2( parent.trackfitchi2, index, this ),
        trackfitndof( parent.trackfitndof, index, this ),
        trackphi( parent.trackphi, index, this ),
        trackqoverp( parent.trackqoverp, index, this ),
        tracksigd0beam( parent.tracksigd0beam, index, this ),
        tracksigd0pv( parent.tracksigd0pv, index, this ),
        tracksigd0pvunbiased( parent.tracksigd0pvunbiased, index, this ),
        tracksigz0beam( parent.tracksigz0beam, index, this ),
        tracksigz0pv( parent.tracksigz0pv, index, this ),
        tracksigz0pvunbiased( parent.tracksigz0pvunbiased, index, this ),
        tracktheta( parent.tracktheta, index, this ),
        trackz0( parent.trackz0, index, this ),
        trackz0beam( parent.trackz0beam, index, this ),
        trackz0pv( parent.trackz0pv, index, this ),
        trackz0pvunbiased( parent.trackz0pvunbiased, index, this ),
        truth_E( parent.truth_E, index, this ),
        truth_barcode( parent.truth_barcode, index, this ),
        truth_dr( parent.truth_dr, index, this ),
        truth_eta( parent.truth_eta, index, this ),
        truth_matched( parent.truth_matched, index, this ),
        truth_motherbarcode( parent.truth_motherbarcode, index, this ),
        truth_mothertype( parent.truth_mothertype, index, this ),
        truth_phi( parent.truth_phi, index, this ),
        truth_pt( parent.truth_pt, index, this ),
        truth_status( parent.truth_status, index, this ),
        truth_type( parent.truth_type, index, this ),
        type( parent.type, index, this ),
        z0_exPV( parent.z0_exPV, index, this ),
        fParent( &parent ), fIndex( index ) {

   }

   /**
    * This constructor is useful for creating copies of proxy objects.
    * Such objects are fairly cheap to copy, so the user is allowed to have
    * his/her containers of them inside an analysis code. (To select and
    * sort objects according to some criteria for instance.)
    *
    * @param parent The proxy object that should be copied
    */
   MuonD3PDObjectElement::MuonD3PDObjectElement( const MuonD3PDObjectElement& parent )
      : TObject( parent ),
        E( parent.E ),
        EFCB_index( parent.EFCB_index ),
        EFME_index( parent.EFME_index ),
        EFMG_index( parent.EFMG_index ),
        SpaceTime_detID( parent.SpaceTime_detID ),
        SpaceTime_t( parent.SpaceTime_t ),
        SpaceTime_tError( parent.SpaceTime_tError ),
        SpaceTime_weight( parent.SpaceTime_weight ),
        SpaceTime_x( parent.SpaceTime_x ),
        SpaceTime_y( parent.SpaceTime_y ),
        SpaceTime_z( parent.SpaceTime_z ),
        allauthor( parent.allauthor ),
        alsoFoundByCaloMuonId( parent.alsoFoundByCaloMuonId ),
        alsoFoundByLowPt( parent.alsoFoundByLowPt ),
        author( parent.author ),
        barrelSectors( parent.barrelSectors ),
        bestMatch( parent.bestMatch ),
        beta( parent.beta ),
        caloLRLikelihood( parent.caloLRLikelihood ),
        caloMuonIdTag( parent.caloMuonIdTag ),
        cb_d0_exPV( parent.cb_d0_exPV ),
        cb_phi_exPV( parent.cb_phi_exPV ),
        cb_qoverp_exPV( parent.cb_qoverp_exPV ),
        cb_theta_exPV( parent.cb_theta_exPV ),
        cb_z0_exPV( parent.cb_z0_exPV ),
        charge( parent.charge ),
        cov_d0_exPV( parent.cov_d0_exPV ),
        cov_d0_phi_exPV( parent.cov_d0_phi_exPV ),
        cov_d0_qoverp_exPV( parent.cov_d0_qoverp_exPV ),
        cov_d0_theta_exPV( parent.cov_d0_theta_exPV ),
        cov_d0_z0_exPV( parent.cov_d0_z0_exPV ),
        cov_phi_exPV( parent.cov_phi_exPV ),
        cov_phi_qoverp_exPV( parent.cov_phi_qoverp_exPV ),
        cov_phi_theta_exPV( parent.cov_phi_theta_exPV ),
        cov_qoverp_exPV( parent.cov_qoverp_exPV ),
        cov_theta_exPV( parent.cov_theta_exPV ),
        cov_theta_qoverp_exPV( parent.cov_theta_qoverp_exPV ),
        cov_z0_exPV( parent.cov_z0_exPV ),
        cov_z0_phi_exPV( parent.cov_z0_phi_exPV ),
        cov_z0_qoverp_exPV( parent.cov_z0_qoverp_exPV ),
        cov_z0_theta_exPV( parent.cov_z0_theta_exPV ),
        d0_exPV( parent.d0_exPV ),
        endcapSectors( parent.endcapSectors ),
        energyLossErr( parent.energyLossErr ),
        energyLossPar( parent.energyLossPar ),
        energyLossType( parent.energyLossType ),
        etCore( parent.etCore ),
        eta( parent.eta ),
        etcone20( parent.etcone20 ),
        etcone30( parent.etcone30 ),
        etcone40( parent.etcone40 ),
        expectBLayerHit( parent.expectBLayerHit ),
        hastrack( parent.hastrack ),
        id_cov_d0_exPV( parent.id_cov_d0_exPV ),
        id_cov_d0_phi_exPV( parent.id_cov_d0_phi_exPV ),
        id_cov_d0_qoverp_exPV( parent.id_cov_d0_qoverp_exPV ),
        id_cov_d0_theta_exPV( parent.id_cov_d0_theta_exPV ),
        id_cov_d0_z0_exPV( parent.id_cov_d0_z0_exPV ),
        id_cov_phi_exPV( parent.id_cov_phi_exPV ),
        id_cov_phi_qoverp_exPV( parent.id_cov_phi_qoverp_exPV ),
        id_cov_phi_theta_exPV( parent.id_cov_phi_theta_exPV ),
        id_cov_qoverp_exPV( parent.id_cov_qoverp_exPV ),
        id_cov_theta_exPV( parent.id_cov_theta_exPV ),
        id_cov_theta_qoverp_exPV( parent.id_cov_theta_qoverp_exPV ),
        id_cov_z0_exPV( parent.id_cov_z0_exPV ),
        id_cov_z0_phi_exPV( parent.id_cov_z0_phi_exPV ),
        id_cov_z0_qoverp_exPV( parent.id_cov_z0_qoverp_exPV ),
        id_cov_z0_theta_exPV( parent.id_cov_z0_theta_exPV ),
        id_d0( parent.id_d0 ),
        id_d0_exPV( parent.id_d0_exPV ),
        id_phi( parent.id_phi ),
        id_phi_exPV( parent.id_phi_exPV ),
        id_qoverp( parent.id_qoverp ),
        id_qoverp_exPV( parent.id_qoverp_exPV ),
        id_theta( parent.id_theta ),
        id_theta_exPV( parent.id_theta_exPV ),
        id_z0( parent.id_z0 ),
        id_z0_exPV( parent.id_z0_exPV ),
        ie_d0( parent.ie_d0 ),
        ie_d0_exPV( parent.ie_d0_exPV ),
        ie_phi( parent.ie_phi ),
        ie_phi_exPV( parent.ie_phi_exPV ),
        ie_qoverp( parent.ie_qoverp ),
        ie_qoverp_exPV( parent.ie_qoverp_exPV ),
        ie_theta( parent.ie_theta ),
        ie_theta_exPV( parent.ie_theta_exPV ),
        ie_z0( parent.ie_z0 ),
        ie_z0_exPV( parent.ie_z0_exPV ),
        isCaloMuonId( parent.isCaloMuonId ),
        isCombinedMuon( parent.isCombinedMuon ),
        isLowPtReconstructedMuon( parent.isLowPtReconstructedMuon ),
        isMuonLikelihood( parent.isMuonLikelihood ),
        isSegmentTaggedMuon( parent.isSegmentTaggedMuon ),
        isSiliconAssociatedForwardMuon( parent.isSiliconAssociatedForwardMuon ),
        isStandAloneMuon( parent.isStandAloneMuon ),
        loose( parent.loose ),
        m( parent.m ),
        matchchi2( parent.matchchi2 ),
        matchndof( parent.matchndof ),
        me_cov_d0_exPV( parent.me_cov_d0_exPV ),
        me_cov_d0_phi_exPV( parent.me_cov_d0_phi_exPV ),
        me_cov_d0_qoverp_exPV( parent.me_cov_d0_qoverp_exPV ),
        me_cov_d0_theta_exPV( parent.me_cov_d0_theta_exPV ),
        me_cov_d0_z0_exPV( parent.me_cov_d0_z0_exPV ),
        me_cov_phi_exPV( parent.me_cov_phi_exPV ),
        me_cov_phi_qoverp_exPV( parent.me_cov_phi_qoverp_exPV ),
        me_cov_phi_theta_exPV( parent.me_cov_phi_theta_exPV ),
        me_cov_qoverp_exPV( parent.me_cov_qoverp_exPV ),
        me_cov_theta_exPV( parent.me_cov_theta_exPV ),
        me_cov_theta_qoverp_exPV( parent.me_cov_theta_qoverp_exPV ),
        me_cov_z0_exPV( parent.me_cov_z0_exPV ),
        me_cov_z0_phi_exPV( parent.me_cov_z0_phi_exPV ),
        me_cov_z0_qoverp_exPV( parent.me_cov_z0_qoverp_exPV ),
        me_cov_z0_theta_exPV( parent.me_cov_z0_theta_exPV ),
        me_d0( parent.me_d0 ),
        me_d0_exPV( parent.me_d0_exPV ),
        me_phi( parent.me_phi ),
        me_phi_exPV( parent.me_phi_exPV ),
        me_qoverp( parent.me_qoverp ),
        me_qoverp_exPV( parent.me_qoverp_exPV ),
        me_theta( parent.me_theta ),
        me_theta_exPV( parent.me_theta_exPV ),
        me_z0( parent.me_z0 ),
        me_z0_exPV( parent.me_z0_exPV ),
        medium( parent.medium ),
        momentumBalanceSignificance( parent.momentumBalanceSignificance ),
        ms_d0( parent.ms_d0 ),
        ms_phi( parent.ms_phi ),
        ms_qoverp( parent.ms_qoverp ),
        ms_theta( parent.ms_theta ),
        ms_z0( parent.ms_z0 ),
        nBLHits( parent.nBLHits ),
        nBLSharedHits( parent.nBLSharedHits ),
        nCSCEtaHits( parent.nCSCEtaHits ),
        nCSCEtaHoles( parent.nCSCEtaHoles ),
        nCSCPhiHits( parent.nCSCPhiHits ),
        nCSCPhiHoles( parent.nCSCPhiHoles ),
        nCSCUnspoiledEtaHits( parent.nCSCUnspoiledEtaHits ),
        nGangedPixels( parent.nGangedPixels ),
        nMDTBEEHits( parent.nMDTBEEHits ),
        nMDTBIHits( parent.nMDTBIHits ),
        nMDTBIS78Hits( parent.nMDTBIS78Hits ),
        nMDTBMHits( parent.nMDTBMHits ),
        nMDTBOHits( parent.nMDTBOHits ),
        nMDTEEHits( parent.nMDTEEHits ),
        nMDTEIHits( parent.nMDTEIHits ),
        nMDTEMHits( parent.nMDTEMHits ),
        nMDTEOHits( parent.nMDTEOHits ),
        nMDTHits( parent.nMDTHits ),
        nMDTHoles( parent.nMDTHoles ),
        nOutliersOnTrack( parent.nOutliersOnTrack ),
        nPixHits( parent.nPixHits ),
        nPixHoles( parent.nPixHoles ),
        nPixSharedHits( parent.nPixSharedHits ),
        nPixelDeadSensors( parent.nPixelDeadSensors ),
        nRPCEtaHits( parent.nRPCEtaHits ),
        nRPCEtaHoles( parent.nRPCEtaHoles ),
        nRPCLayer1EtaHits( parent.nRPCLayer1EtaHits ),
        nRPCLayer1PhiHits( parent.nRPCLayer1PhiHits ),
        nRPCLayer2EtaHits( parent.nRPCLayer2EtaHits ),
        nRPCLayer2PhiHits( parent.nRPCLayer2PhiHits ),
        nRPCLayer3EtaHits( parent.nRPCLayer3EtaHits ),
        nRPCLayer3PhiHits( parent.nRPCLayer3PhiHits ),
        nRPCPhiHits( parent.nRPCPhiHits ),
        nRPCPhiHoles( parent.nRPCPhiHoles ),
        nSCTDeadSensors( parent.nSCTDeadSensors ),
        nSCTHits( parent.nSCTHits ),
        nSCTHoles( parent.nSCTHoles ),
        nSCTSharedHits( parent.nSCTSharedHits ),
        nTGCEtaHits( parent.nTGCEtaHits ),
        nTGCEtaHoles( parent.nTGCEtaHoles ),
        nTGCLayer1EtaHits( parent.nTGCLayer1EtaHits ),
        nTGCLayer1PhiHits( parent.nTGCLayer1PhiHits ),
        nTGCLayer2EtaHits( parent.nTGCLayer2EtaHits ),
        nTGCLayer2PhiHits( parent.nTGCLayer2PhiHits ),
        nTGCLayer3EtaHits( parent.nTGCLayer3EtaHits ),
        nTGCLayer3PhiHits( parent.nTGCLayer3PhiHits ),
        nTGCLayer4EtaHits( parent.nTGCLayer4EtaHits ),
        nTGCLayer4PhiHits( parent.nTGCLayer4PhiHits ),
        nTGCPhiHits( parent.nTGCPhiHits ),
        nTGCPhiHoles( parent.nTGCPhiHoles ),
        nTRTDeadStraws( parent.nTRTDeadStraws ),
        nTRTHighTHits( parent.nTRTHighTHits ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers ),
        nTRTHits( parent.nTRTHits ),
        nTRTOutliers( parent.nTRTOutliers ),
        nphiHoleLayers( parent.nphiHoleLayers ),
        nphiLayers( parent.nphiLayers ),
        nprecisionHoleLayers( parent.nprecisionHoleLayers ),
        nprecisionLayers( parent.nprecisionLayers ),
        ntrigEtaHoleLayers( parent.ntrigEtaHoleLayers ),
        ntrigEtaLayers( parent.ntrigEtaLayers ),
        nucone20( parent.nucone20 ),
        nucone30( parent.nucone30 ),
        nucone40( parent.nucone40 ),
        origin( parent.origin ),
        phi( parent.phi ),
        phi_exPV( parent.phi_exPV ),
        pt( parent.pt ),
        ptcone20( parent.ptcone20 ),
        ptcone30( parent.ptcone30 ),
        ptcone40( parent.ptcone40 ),
        px( parent.px ),
        py( parent.py ),
        pz( parent.pz ),
        qoverp_exPV( parent.qoverp_exPV ),
        scatteringCurvatureSignificance( parent.scatteringCurvatureSignificance ),
        scatteringNeighbourSignificance( parent.scatteringNeighbourSignificance ),
        theta_exPV( parent.theta_exPV ),
        tight( parent.tight ),
        trackIPEstimate_d0_biasedpvunbiased( parent.trackIPEstimate_d0_biasedpvunbiased ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased ),
        trackIPEstimate_sigd0_biasedpvunbiased( parent.trackIPEstimate_sigd0_biasedpvunbiased ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased ),
        trackIPEstimate_sigz0_biasedpvunbiased( parent.trackIPEstimate_sigz0_biasedpvunbiased ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased ),
        trackIPEstimate_z0_biasedpvunbiased( parent.trackIPEstimate_z0_biasedpvunbiased ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased ),
        trackcov_d0( parent.trackcov_d0 ),
        trackcov_d0_phi( parent.trackcov_d0_phi ),
        trackcov_d0_qoverp( parent.trackcov_d0_qoverp ),
        trackcov_d0_theta( parent.trackcov_d0_theta ),
        trackcov_d0_z0( parent.trackcov_d0_z0 ),
        trackcov_phi( parent.trackcov_phi ),
        trackcov_phi_qoverp( parent.trackcov_phi_qoverp ),
        trackcov_phi_theta( parent.trackcov_phi_theta ),
        trackcov_qoverp( parent.trackcov_qoverp ),
        trackcov_theta( parent.trackcov_theta ),
        trackcov_theta_qoverp( parent.trackcov_theta_qoverp ),
        trackcov_z0( parent.trackcov_z0 ),
        trackcov_z0_phi( parent.trackcov_z0_phi ),
        trackcov_z0_qoverp( parent.trackcov_z0_qoverp ),
        trackcov_z0_theta( parent.trackcov_z0_theta ),
        trackd0( parent.trackd0 ),
        trackd0beam( parent.trackd0beam ),
        trackd0pv( parent.trackd0pv ),
        trackd0pvunbiased( parent.trackd0pvunbiased ),
        trackfitchi2( parent.trackfitchi2 ),
        trackfitndof( parent.trackfitndof ),
        trackphi( parent.trackphi ),
        trackqoverp( parent.trackqoverp ),
        tracksigd0beam( parent.tracksigd0beam ),
        tracksigd0pv( parent.tracksigd0pv ),
        tracksigd0pvunbiased( parent.tracksigd0pvunbiased ),
        tracksigz0beam( parent.tracksigz0beam ),
        tracksigz0pv( parent.tracksigz0pv ),
        tracksigz0pvunbiased( parent.tracksigz0pvunbiased ),
        tracktheta( parent.tracktheta ),
        trackz0( parent.trackz0 ),
        trackz0beam( parent.trackz0beam ),
        trackz0pv( parent.trackz0pv ),
        trackz0pvunbiased( parent.trackz0pvunbiased ),
        truth_E( parent.truth_E ),
        truth_barcode( parent.truth_barcode ),
        truth_dr( parent.truth_dr ),
        truth_eta( parent.truth_eta ),
        truth_matched( parent.truth_matched ),
        truth_motherbarcode( parent.truth_motherbarcode ),
        truth_mothertype( parent.truth_mothertype ),
        truth_phi( parent.truth_phi ),
        truth_pt( parent.truth_pt ),
        truth_status( parent.truth_status ),
        truth_type( parent.truth_type ),
        type( parent.type ),
        z0_exPV( parent.z0_exPV ),
        fParent( parent.fParent ), fIndex( parent.fIndex ) {

   }

   /**
    * This function can be used to access the parent object of this
    * proxy object. It can come in handy when optimizing an analysis code.
    *
    * @returns A reference to this object's parent
    */
   const MuonD3PDObject* MuonD3PDObjectElement::GetParent() const {

      return fParent;
   }

   /**
    * This function can be used to access the index of this proxy object
    * inside the parent container. It can come in handy when optimizing an
    * analysis code.
    *
    * @returns The index of the proxy in the object's parent
    */
   size_t MuonD3PDObjectElement::GetIndex() const {

      return fIndex;
   }

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   MuonD3PDObject::MuonD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "E" ] = &E;
      fHandles[ "EFCB_index" ] = &EFCB_index;
      fHandles[ "EFME_index" ] = &EFME_index;
      fHandles[ "EFMG_index" ] = &EFMG_index;
      fHandles[ "SpaceTime_detID" ] = &SpaceTime_detID;
      fHandles[ "SpaceTime_t" ] = &SpaceTime_t;
      fHandles[ "SpaceTime_tError" ] = &SpaceTime_tError;
      fHandles[ "SpaceTime_weight" ] = &SpaceTime_weight;
      fHandles[ "SpaceTime_x" ] = &SpaceTime_x;
      fHandles[ "SpaceTime_y" ] = &SpaceTime_y;
      fHandles[ "SpaceTime_z" ] = &SpaceTime_z;
      fHandles[ "allauthor" ] = &allauthor;
      fHandles[ "alsoFoundByCaloMuonId" ] = &alsoFoundByCaloMuonId;
      fHandles[ "alsoFoundByLowPt" ] = &alsoFoundByLowPt;
      fHandles[ "author" ] = &author;
      fHandles[ "barrelSectors" ] = &barrelSectors;
      fHandles[ "bestMatch" ] = &bestMatch;
      fHandles[ "beta" ] = &beta;
      fHandles[ "caloLRLikelihood" ] = &caloLRLikelihood;
      fHandles[ "caloMuonIdTag" ] = &caloMuonIdTag;
      fHandles[ "cb_d0_exPV" ] = &cb_d0_exPV;
      fHandles[ "cb_phi_exPV" ] = &cb_phi_exPV;
      fHandles[ "cb_qoverp_exPV" ] = &cb_qoverp_exPV;
      fHandles[ "cb_theta_exPV" ] = &cb_theta_exPV;
      fHandles[ "cb_z0_exPV" ] = &cb_z0_exPV;
      fHandles[ "charge" ] = &charge;
      fHandles[ "cov_d0_exPV" ] = &cov_d0_exPV;
      fHandles[ "cov_d0_phi_exPV" ] = &cov_d0_phi_exPV;
      fHandles[ "cov_d0_qoverp_exPV" ] = &cov_d0_qoverp_exPV;
      fHandles[ "cov_d0_theta_exPV" ] = &cov_d0_theta_exPV;
      fHandles[ "cov_d0_z0_exPV" ] = &cov_d0_z0_exPV;
      fHandles[ "cov_phi_exPV" ] = &cov_phi_exPV;
      fHandles[ "cov_phi_qoverp_exPV" ] = &cov_phi_qoverp_exPV;
      fHandles[ "cov_phi_theta_exPV" ] = &cov_phi_theta_exPV;
      fHandles[ "cov_qoverp_exPV" ] = &cov_qoverp_exPV;
      fHandles[ "cov_theta_exPV" ] = &cov_theta_exPV;
      fHandles[ "cov_theta_qoverp_exPV" ] = &cov_theta_qoverp_exPV;
      fHandles[ "cov_z0_exPV" ] = &cov_z0_exPV;
      fHandles[ "cov_z0_phi_exPV" ] = &cov_z0_phi_exPV;
      fHandles[ "cov_z0_qoverp_exPV" ] = &cov_z0_qoverp_exPV;
      fHandles[ "cov_z0_theta_exPV" ] = &cov_z0_theta_exPV;
      fHandles[ "d0_exPV" ] = &d0_exPV;
      fHandles[ "endcapSectors" ] = &endcapSectors;
      fHandles[ "energyLossErr" ] = &energyLossErr;
      fHandles[ "energyLossPar" ] = &energyLossPar;
      fHandles[ "energyLossType" ] = &energyLossType;
      fHandles[ "etCore" ] = &etCore;
      fHandles[ "eta" ] = &eta;
      fHandles[ "etcone20" ] = &etcone20;
      fHandles[ "etcone30" ] = &etcone30;
      fHandles[ "etcone40" ] = &etcone40;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "hastrack" ] = &hastrack;
      fHandles[ "id_cov_d0_exPV" ] = &id_cov_d0_exPV;
      fHandles[ "id_cov_d0_phi_exPV" ] = &id_cov_d0_phi_exPV;
      fHandles[ "id_cov_d0_qoverp_exPV" ] = &id_cov_d0_qoverp_exPV;
      fHandles[ "id_cov_d0_theta_exPV" ] = &id_cov_d0_theta_exPV;
      fHandles[ "id_cov_d0_z0_exPV" ] = &id_cov_d0_z0_exPV;
      fHandles[ "id_cov_phi_exPV" ] = &id_cov_phi_exPV;
      fHandles[ "id_cov_phi_qoverp_exPV" ] = &id_cov_phi_qoverp_exPV;
      fHandles[ "id_cov_phi_theta_exPV" ] = &id_cov_phi_theta_exPV;
      fHandles[ "id_cov_qoverp_exPV" ] = &id_cov_qoverp_exPV;
      fHandles[ "id_cov_theta_exPV" ] = &id_cov_theta_exPV;
      fHandles[ "id_cov_theta_qoverp_exPV" ] = &id_cov_theta_qoverp_exPV;
      fHandles[ "id_cov_z0_exPV" ] = &id_cov_z0_exPV;
      fHandles[ "id_cov_z0_phi_exPV" ] = &id_cov_z0_phi_exPV;
      fHandles[ "id_cov_z0_qoverp_exPV" ] = &id_cov_z0_qoverp_exPV;
      fHandles[ "id_cov_z0_theta_exPV" ] = &id_cov_z0_theta_exPV;
      fHandles[ "id_d0" ] = &id_d0;
      fHandles[ "id_d0_exPV" ] = &id_d0_exPV;
      fHandles[ "id_phi" ] = &id_phi;
      fHandles[ "id_phi_exPV" ] = &id_phi_exPV;
      fHandles[ "id_qoverp" ] = &id_qoverp;
      fHandles[ "id_qoverp_exPV" ] = &id_qoverp_exPV;
      fHandles[ "id_theta" ] = &id_theta;
      fHandles[ "id_theta_exPV" ] = &id_theta_exPV;
      fHandles[ "id_z0" ] = &id_z0;
      fHandles[ "id_z0_exPV" ] = &id_z0_exPV;
      fHandles[ "ie_d0" ] = &ie_d0;
      fHandles[ "ie_d0_exPV" ] = &ie_d0_exPV;
      fHandles[ "ie_phi" ] = &ie_phi;
      fHandles[ "ie_phi_exPV" ] = &ie_phi_exPV;
      fHandles[ "ie_qoverp" ] = &ie_qoverp;
      fHandles[ "ie_qoverp_exPV" ] = &ie_qoverp_exPV;
      fHandles[ "ie_theta" ] = &ie_theta;
      fHandles[ "ie_theta_exPV" ] = &ie_theta_exPV;
      fHandles[ "ie_z0" ] = &ie_z0;
      fHandles[ "ie_z0_exPV" ] = &ie_z0_exPV;
      fHandles[ "isCaloMuonId" ] = &isCaloMuonId;
      fHandles[ "isCombinedMuon" ] = &isCombinedMuon;
      fHandles[ "isLowPtReconstructedMuon" ] = &isLowPtReconstructedMuon;
      fHandles[ "isMuonLikelihood" ] = &isMuonLikelihood;
      fHandles[ "isSegmentTaggedMuon" ] = &isSegmentTaggedMuon;
      fHandles[ "isSiliconAssociatedForwardMuon" ] = &isSiliconAssociatedForwardMuon;
      fHandles[ "isStandAloneMuon" ] = &isStandAloneMuon;
      fHandles[ "loose" ] = &loose;
      fHandles[ "m" ] = &m;
      fHandles[ "matchchi2" ] = &matchchi2;
      fHandles[ "matchndof" ] = &matchndof;
      fHandles[ "me_cov_d0_exPV" ] = &me_cov_d0_exPV;
      fHandles[ "me_cov_d0_phi_exPV" ] = &me_cov_d0_phi_exPV;
      fHandles[ "me_cov_d0_qoverp_exPV" ] = &me_cov_d0_qoverp_exPV;
      fHandles[ "me_cov_d0_theta_exPV" ] = &me_cov_d0_theta_exPV;
      fHandles[ "me_cov_d0_z0_exPV" ] = &me_cov_d0_z0_exPV;
      fHandles[ "me_cov_phi_exPV" ] = &me_cov_phi_exPV;
      fHandles[ "me_cov_phi_qoverp_exPV" ] = &me_cov_phi_qoverp_exPV;
      fHandles[ "me_cov_phi_theta_exPV" ] = &me_cov_phi_theta_exPV;
      fHandles[ "me_cov_qoverp_exPV" ] = &me_cov_qoverp_exPV;
      fHandles[ "me_cov_theta_exPV" ] = &me_cov_theta_exPV;
      fHandles[ "me_cov_theta_qoverp_exPV" ] = &me_cov_theta_qoverp_exPV;
      fHandles[ "me_cov_z0_exPV" ] = &me_cov_z0_exPV;
      fHandles[ "me_cov_z0_phi_exPV" ] = &me_cov_z0_phi_exPV;
      fHandles[ "me_cov_z0_qoverp_exPV" ] = &me_cov_z0_qoverp_exPV;
      fHandles[ "me_cov_z0_theta_exPV" ] = &me_cov_z0_theta_exPV;
      fHandles[ "me_d0" ] = &me_d0;
      fHandles[ "me_d0_exPV" ] = &me_d0_exPV;
      fHandles[ "me_phi" ] = &me_phi;
      fHandles[ "me_phi_exPV" ] = &me_phi_exPV;
      fHandles[ "me_qoverp" ] = &me_qoverp;
      fHandles[ "me_qoverp_exPV" ] = &me_qoverp_exPV;
      fHandles[ "me_theta" ] = &me_theta;
      fHandles[ "me_theta_exPV" ] = &me_theta_exPV;
      fHandles[ "me_z0" ] = &me_z0;
      fHandles[ "me_z0_exPV" ] = &me_z0_exPV;
      fHandles[ "medium" ] = &medium;
      fHandles[ "momentumBalanceSignificance" ] = &momentumBalanceSignificance;
      fHandles[ "ms_d0" ] = &ms_d0;
      fHandles[ "ms_phi" ] = &ms_phi;
      fHandles[ "ms_qoverp" ] = &ms_qoverp;
      fHandles[ "ms_theta" ] = &ms_theta;
      fHandles[ "ms_z0" ] = &ms_z0;
      fHandles[ "n" ] = &n;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nCSCEtaHits" ] = &nCSCEtaHits;
      fHandles[ "nCSCEtaHoles" ] = &nCSCEtaHoles;
      fHandles[ "nCSCPhiHits" ] = &nCSCPhiHits;
      fHandles[ "nCSCPhiHoles" ] = &nCSCPhiHoles;
      fHandles[ "nCSCUnspoiledEtaHits" ] = &nCSCUnspoiledEtaHits;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nMDTBEEHits" ] = &nMDTBEEHits;
      fHandles[ "nMDTBIHits" ] = &nMDTBIHits;
      fHandles[ "nMDTBIS78Hits" ] = &nMDTBIS78Hits;
      fHandles[ "nMDTBMHits" ] = &nMDTBMHits;
      fHandles[ "nMDTBOHits" ] = &nMDTBOHits;
      fHandles[ "nMDTEEHits" ] = &nMDTEEHits;
      fHandles[ "nMDTEIHits" ] = &nMDTEIHits;
      fHandles[ "nMDTEMHits" ] = &nMDTEMHits;
      fHandles[ "nMDTEOHits" ] = &nMDTEOHits;
      fHandles[ "nMDTHits" ] = &nMDTHits;
      fHandles[ "nMDTHoles" ] = &nMDTHoles;
      fHandles[ "nOutliersOnTrack" ] = &nOutliersOnTrack;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nRPCEtaHits" ] = &nRPCEtaHits;
      fHandles[ "nRPCEtaHoles" ] = &nRPCEtaHoles;
      fHandles[ "nRPCLayer1EtaHits" ] = &nRPCLayer1EtaHits;
      fHandles[ "nRPCLayer1PhiHits" ] = &nRPCLayer1PhiHits;
      fHandles[ "nRPCLayer2EtaHits" ] = &nRPCLayer2EtaHits;
      fHandles[ "nRPCLayer2PhiHits" ] = &nRPCLayer2PhiHits;
      fHandles[ "nRPCLayer3EtaHits" ] = &nRPCLayer3EtaHits;
      fHandles[ "nRPCLayer3PhiHits" ] = &nRPCLayer3PhiHits;
      fHandles[ "nRPCPhiHits" ] = &nRPCPhiHits;
      fHandles[ "nRPCPhiHoles" ] = &nRPCPhiHoles;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nTGCEtaHits" ] = &nTGCEtaHits;
      fHandles[ "nTGCEtaHoles" ] = &nTGCEtaHoles;
      fHandles[ "nTGCLayer1EtaHits" ] = &nTGCLayer1EtaHits;
      fHandles[ "nTGCLayer1PhiHits" ] = &nTGCLayer1PhiHits;
      fHandles[ "nTGCLayer2EtaHits" ] = &nTGCLayer2EtaHits;
      fHandles[ "nTGCLayer2PhiHits" ] = &nTGCLayer2PhiHits;
      fHandles[ "nTGCLayer3EtaHits" ] = &nTGCLayer3EtaHits;
      fHandles[ "nTGCLayer3PhiHits" ] = &nTGCLayer3PhiHits;
      fHandles[ "nTGCLayer4EtaHits" ] = &nTGCLayer4EtaHits;
      fHandles[ "nTGCLayer4PhiHits" ] = &nTGCLayer4PhiHits;
      fHandles[ "nTGCPhiHits" ] = &nTGCPhiHits;
      fHandles[ "nTGCPhiHoles" ] = &nTGCPhiHoles;
      fHandles[ "nTRTDeadStraws" ] = &nTRTDeadStraws;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nphiHoleLayers" ] = &nphiHoleLayers;
      fHandles[ "nphiLayers" ] = &nphiLayers;
      fHandles[ "nprecisionHoleLayers" ] = &nprecisionHoleLayers;
      fHandles[ "nprecisionLayers" ] = &nprecisionLayers;
      fHandles[ "ntrigEtaHoleLayers" ] = &ntrigEtaHoleLayers;
      fHandles[ "ntrigEtaLayers" ] = &ntrigEtaLayers;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "origin" ] = &origin;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phi_exPV" ] = &phi_exPV;
      fHandles[ "pt" ] = &pt;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "qoverp_exPV" ] = &qoverp_exPV;
      fHandles[ "scatteringCurvatureSignificance" ] = &scatteringCurvatureSignificance;
      fHandles[ "scatteringNeighbourSignificance" ] = &scatteringNeighbourSignificance;
      fHandles[ "theta_exPV" ] = &theta_exPV;
      fHandles[ "tight" ] = &tight;
      fHandles[ "trackIPEstimate_d0_biasedpvunbiased" ] = &trackIPEstimate_d0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_biasedpvunbiased" ] = &trackIPEstimate_sigd0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_biasedpvunbiased" ] = &trackIPEstimate_sigz0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_biasedpvunbiased" ] = &trackIPEstimate_z0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackcov_d0" ] = &trackcov_d0;
      fHandles[ "trackcov_d0_phi" ] = &trackcov_d0_phi;
      fHandles[ "trackcov_d0_qoverp" ] = &trackcov_d0_qoverp;
      fHandles[ "trackcov_d0_theta" ] = &trackcov_d0_theta;
      fHandles[ "trackcov_d0_z0" ] = &trackcov_d0_z0;
      fHandles[ "trackcov_phi" ] = &trackcov_phi;
      fHandles[ "trackcov_phi_qoverp" ] = &trackcov_phi_qoverp;
      fHandles[ "trackcov_phi_theta" ] = &trackcov_phi_theta;
      fHandles[ "trackcov_qoverp" ] = &trackcov_qoverp;
      fHandles[ "trackcov_theta" ] = &trackcov_theta;
      fHandles[ "trackcov_theta_qoverp" ] = &trackcov_theta_qoverp;
      fHandles[ "trackcov_z0" ] = &trackcov_z0;
      fHandles[ "trackcov_z0_phi" ] = &trackcov_z0_phi;
      fHandles[ "trackcov_z0_qoverp" ] = &trackcov_z0_qoverp;
      fHandles[ "trackcov_z0_theta" ] = &trackcov_z0_theta;
      fHandles[ "trackd0" ] = &trackd0;
      fHandles[ "trackd0beam" ] = &trackd0beam;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackd0pvunbiased" ] = &trackd0pvunbiased;
      fHandles[ "trackfitchi2" ] = &trackfitchi2;
      fHandles[ "trackfitndof" ] = &trackfitndof;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "trackqoverp" ] = &trackqoverp;
      fHandles[ "tracksigd0beam" ] = &tracksigd0beam;
      fHandles[ "tracksigd0pv" ] = &tracksigd0pv;
      fHandles[ "tracksigd0pvunbiased" ] = &tracksigd0pvunbiased;
      fHandles[ "tracksigz0beam" ] = &tracksigz0beam;
      fHandles[ "tracksigz0pv" ] = &tracksigz0pv;
      fHandles[ "tracksigz0pvunbiased" ] = &tracksigz0pvunbiased;
      fHandles[ "tracktheta" ] = &tracktheta;
      fHandles[ "trackz0" ] = &trackz0;
      fHandles[ "trackz0beam" ] = &trackz0beam;
      fHandles[ "trackz0pv" ] = &trackz0pv;
      fHandles[ "trackz0pvunbiased" ] = &trackz0pvunbiased;
      fHandles[ "truth_E" ] = &truth_E;
      fHandles[ "truth_barcode" ] = &truth_barcode;
      fHandles[ "truth_dr" ] = &truth_dr;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_matched" ] = &truth_matched;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "type" ] = &type;
      fHandles[ "z0_exPV" ] = &z0_exPV;

      // Configure all variables in a loop:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->SetParent( this );
         itr->second->SetName( fPrefix + itr->first );
         itr->second->SetMaster( &master );
      }
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   MuonD3PDObject::MuonD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "E" ] = &E;
      fHandles[ "EFCB_index" ] = &EFCB_index;
      fHandles[ "EFME_index" ] = &EFME_index;
      fHandles[ "EFMG_index" ] = &EFMG_index;
      fHandles[ "SpaceTime_detID" ] = &SpaceTime_detID;
      fHandles[ "SpaceTime_t" ] = &SpaceTime_t;
      fHandles[ "SpaceTime_tError" ] = &SpaceTime_tError;
      fHandles[ "SpaceTime_weight" ] = &SpaceTime_weight;
      fHandles[ "SpaceTime_x" ] = &SpaceTime_x;
      fHandles[ "SpaceTime_y" ] = &SpaceTime_y;
      fHandles[ "SpaceTime_z" ] = &SpaceTime_z;
      fHandles[ "allauthor" ] = &allauthor;
      fHandles[ "alsoFoundByCaloMuonId" ] = &alsoFoundByCaloMuonId;
      fHandles[ "alsoFoundByLowPt" ] = &alsoFoundByLowPt;
      fHandles[ "author" ] = &author;
      fHandles[ "barrelSectors" ] = &barrelSectors;
      fHandles[ "bestMatch" ] = &bestMatch;
      fHandles[ "beta" ] = &beta;
      fHandles[ "caloLRLikelihood" ] = &caloLRLikelihood;
      fHandles[ "caloMuonIdTag" ] = &caloMuonIdTag;
      fHandles[ "cb_d0_exPV" ] = &cb_d0_exPV;
      fHandles[ "cb_phi_exPV" ] = &cb_phi_exPV;
      fHandles[ "cb_qoverp_exPV" ] = &cb_qoverp_exPV;
      fHandles[ "cb_theta_exPV" ] = &cb_theta_exPV;
      fHandles[ "cb_z0_exPV" ] = &cb_z0_exPV;
      fHandles[ "charge" ] = &charge;
      fHandles[ "cov_d0_exPV" ] = &cov_d0_exPV;
      fHandles[ "cov_d0_phi_exPV" ] = &cov_d0_phi_exPV;
      fHandles[ "cov_d0_qoverp_exPV" ] = &cov_d0_qoverp_exPV;
      fHandles[ "cov_d0_theta_exPV" ] = &cov_d0_theta_exPV;
      fHandles[ "cov_d0_z0_exPV" ] = &cov_d0_z0_exPV;
      fHandles[ "cov_phi_exPV" ] = &cov_phi_exPV;
      fHandles[ "cov_phi_qoverp_exPV" ] = &cov_phi_qoverp_exPV;
      fHandles[ "cov_phi_theta_exPV" ] = &cov_phi_theta_exPV;
      fHandles[ "cov_qoverp_exPV" ] = &cov_qoverp_exPV;
      fHandles[ "cov_theta_exPV" ] = &cov_theta_exPV;
      fHandles[ "cov_theta_qoverp_exPV" ] = &cov_theta_qoverp_exPV;
      fHandles[ "cov_z0_exPV" ] = &cov_z0_exPV;
      fHandles[ "cov_z0_phi_exPV" ] = &cov_z0_phi_exPV;
      fHandles[ "cov_z0_qoverp_exPV" ] = &cov_z0_qoverp_exPV;
      fHandles[ "cov_z0_theta_exPV" ] = &cov_z0_theta_exPV;
      fHandles[ "d0_exPV" ] = &d0_exPV;
      fHandles[ "endcapSectors" ] = &endcapSectors;
      fHandles[ "energyLossErr" ] = &energyLossErr;
      fHandles[ "energyLossPar" ] = &energyLossPar;
      fHandles[ "energyLossType" ] = &energyLossType;
      fHandles[ "etCore" ] = &etCore;
      fHandles[ "eta" ] = &eta;
      fHandles[ "etcone20" ] = &etcone20;
      fHandles[ "etcone30" ] = &etcone30;
      fHandles[ "etcone40" ] = &etcone40;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "hastrack" ] = &hastrack;
      fHandles[ "id_cov_d0_exPV" ] = &id_cov_d0_exPV;
      fHandles[ "id_cov_d0_phi_exPV" ] = &id_cov_d0_phi_exPV;
      fHandles[ "id_cov_d0_qoverp_exPV" ] = &id_cov_d0_qoverp_exPV;
      fHandles[ "id_cov_d0_theta_exPV" ] = &id_cov_d0_theta_exPV;
      fHandles[ "id_cov_d0_z0_exPV" ] = &id_cov_d0_z0_exPV;
      fHandles[ "id_cov_phi_exPV" ] = &id_cov_phi_exPV;
      fHandles[ "id_cov_phi_qoverp_exPV" ] = &id_cov_phi_qoverp_exPV;
      fHandles[ "id_cov_phi_theta_exPV" ] = &id_cov_phi_theta_exPV;
      fHandles[ "id_cov_qoverp_exPV" ] = &id_cov_qoverp_exPV;
      fHandles[ "id_cov_theta_exPV" ] = &id_cov_theta_exPV;
      fHandles[ "id_cov_theta_qoverp_exPV" ] = &id_cov_theta_qoverp_exPV;
      fHandles[ "id_cov_z0_exPV" ] = &id_cov_z0_exPV;
      fHandles[ "id_cov_z0_phi_exPV" ] = &id_cov_z0_phi_exPV;
      fHandles[ "id_cov_z0_qoverp_exPV" ] = &id_cov_z0_qoverp_exPV;
      fHandles[ "id_cov_z0_theta_exPV" ] = &id_cov_z0_theta_exPV;
      fHandles[ "id_d0" ] = &id_d0;
      fHandles[ "id_d0_exPV" ] = &id_d0_exPV;
      fHandles[ "id_phi" ] = &id_phi;
      fHandles[ "id_phi_exPV" ] = &id_phi_exPV;
      fHandles[ "id_qoverp" ] = &id_qoverp;
      fHandles[ "id_qoverp_exPV" ] = &id_qoverp_exPV;
      fHandles[ "id_theta" ] = &id_theta;
      fHandles[ "id_theta_exPV" ] = &id_theta_exPV;
      fHandles[ "id_z0" ] = &id_z0;
      fHandles[ "id_z0_exPV" ] = &id_z0_exPV;
      fHandles[ "ie_d0" ] = &ie_d0;
      fHandles[ "ie_d0_exPV" ] = &ie_d0_exPV;
      fHandles[ "ie_phi" ] = &ie_phi;
      fHandles[ "ie_phi_exPV" ] = &ie_phi_exPV;
      fHandles[ "ie_qoverp" ] = &ie_qoverp;
      fHandles[ "ie_qoverp_exPV" ] = &ie_qoverp_exPV;
      fHandles[ "ie_theta" ] = &ie_theta;
      fHandles[ "ie_theta_exPV" ] = &ie_theta_exPV;
      fHandles[ "ie_z0" ] = &ie_z0;
      fHandles[ "ie_z0_exPV" ] = &ie_z0_exPV;
      fHandles[ "isCaloMuonId" ] = &isCaloMuonId;
      fHandles[ "isCombinedMuon" ] = &isCombinedMuon;
      fHandles[ "isLowPtReconstructedMuon" ] = &isLowPtReconstructedMuon;
      fHandles[ "isMuonLikelihood" ] = &isMuonLikelihood;
      fHandles[ "isSegmentTaggedMuon" ] = &isSegmentTaggedMuon;
      fHandles[ "isSiliconAssociatedForwardMuon" ] = &isSiliconAssociatedForwardMuon;
      fHandles[ "isStandAloneMuon" ] = &isStandAloneMuon;
      fHandles[ "loose" ] = &loose;
      fHandles[ "m" ] = &m;
      fHandles[ "matchchi2" ] = &matchchi2;
      fHandles[ "matchndof" ] = &matchndof;
      fHandles[ "me_cov_d0_exPV" ] = &me_cov_d0_exPV;
      fHandles[ "me_cov_d0_phi_exPV" ] = &me_cov_d0_phi_exPV;
      fHandles[ "me_cov_d0_qoverp_exPV" ] = &me_cov_d0_qoverp_exPV;
      fHandles[ "me_cov_d0_theta_exPV" ] = &me_cov_d0_theta_exPV;
      fHandles[ "me_cov_d0_z0_exPV" ] = &me_cov_d0_z0_exPV;
      fHandles[ "me_cov_phi_exPV" ] = &me_cov_phi_exPV;
      fHandles[ "me_cov_phi_qoverp_exPV" ] = &me_cov_phi_qoverp_exPV;
      fHandles[ "me_cov_phi_theta_exPV" ] = &me_cov_phi_theta_exPV;
      fHandles[ "me_cov_qoverp_exPV" ] = &me_cov_qoverp_exPV;
      fHandles[ "me_cov_theta_exPV" ] = &me_cov_theta_exPV;
      fHandles[ "me_cov_theta_qoverp_exPV" ] = &me_cov_theta_qoverp_exPV;
      fHandles[ "me_cov_z0_exPV" ] = &me_cov_z0_exPV;
      fHandles[ "me_cov_z0_phi_exPV" ] = &me_cov_z0_phi_exPV;
      fHandles[ "me_cov_z0_qoverp_exPV" ] = &me_cov_z0_qoverp_exPV;
      fHandles[ "me_cov_z0_theta_exPV" ] = &me_cov_z0_theta_exPV;
      fHandles[ "me_d0" ] = &me_d0;
      fHandles[ "me_d0_exPV" ] = &me_d0_exPV;
      fHandles[ "me_phi" ] = &me_phi;
      fHandles[ "me_phi_exPV" ] = &me_phi_exPV;
      fHandles[ "me_qoverp" ] = &me_qoverp;
      fHandles[ "me_qoverp_exPV" ] = &me_qoverp_exPV;
      fHandles[ "me_theta" ] = &me_theta;
      fHandles[ "me_theta_exPV" ] = &me_theta_exPV;
      fHandles[ "me_z0" ] = &me_z0;
      fHandles[ "me_z0_exPV" ] = &me_z0_exPV;
      fHandles[ "medium" ] = &medium;
      fHandles[ "momentumBalanceSignificance" ] = &momentumBalanceSignificance;
      fHandles[ "ms_d0" ] = &ms_d0;
      fHandles[ "ms_phi" ] = &ms_phi;
      fHandles[ "ms_qoverp" ] = &ms_qoverp;
      fHandles[ "ms_theta" ] = &ms_theta;
      fHandles[ "ms_z0" ] = &ms_z0;
      fHandles[ "n" ] = &n;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nCSCEtaHits" ] = &nCSCEtaHits;
      fHandles[ "nCSCEtaHoles" ] = &nCSCEtaHoles;
      fHandles[ "nCSCPhiHits" ] = &nCSCPhiHits;
      fHandles[ "nCSCPhiHoles" ] = &nCSCPhiHoles;
      fHandles[ "nCSCUnspoiledEtaHits" ] = &nCSCUnspoiledEtaHits;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nMDTBEEHits" ] = &nMDTBEEHits;
      fHandles[ "nMDTBIHits" ] = &nMDTBIHits;
      fHandles[ "nMDTBIS78Hits" ] = &nMDTBIS78Hits;
      fHandles[ "nMDTBMHits" ] = &nMDTBMHits;
      fHandles[ "nMDTBOHits" ] = &nMDTBOHits;
      fHandles[ "nMDTEEHits" ] = &nMDTEEHits;
      fHandles[ "nMDTEIHits" ] = &nMDTEIHits;
      fHandles[ "nMDTEMHits" ] = &nMDTEMHits;
      fHandles[ "nMDTEOHits" ] = &nMDTEOHits;
      fHandles[ "nMDTHits" ] = &nMDTHits;
      fHandles[ "nMDTHoles" ] = &nMDTHoles;
      fHandles[ "nOutliersOnTrack" ] = &nOutliersOnTrack;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nRPCEtaHits" ] = &nRPCEtaHits;
      fHandles[ "nRPCEtaHoles" ] = &nRPCEtaHoles;
      fHandles[ "nRPCLayer1EtaHits" ] = &nRPCLayer1EtaHits;
      fHandles[ "nRPCLayer1PhiHits" ] = &nRPCLayer1PhiHits;
      fHandles[ "nRPCLayer2EtaHits" ] = &nRPCLayer2EtaHits;
      fHandles[ "nRPCLayer2PhiHits" ] = &nRPCLayer2PhiHits;
      fHandles[ "nRPCLayer3EtaHits" ] = &nRPCLayer3EtaHits;
      fHandles[ "nRPCLayer3PhiHits" ] = &nRPCLayer3PhiHits;
      fHandles[ "nRPCPhiHits" ] = &nRPCPhiHits;
      fHandles[ "nRPCPhiHoles" ] = &nRPCPhiHoles;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nTGCEtaHits" ] = &nTGCEtaHits;
      fHandles[ "nTGCEtaHoles" ] = &nTGCEtaHoles;
      fHandles[ "nTGCLayer1EtaHits" ] = &nTGCLayer1EtaHits;
      fHandles[ "nTGCLayer1PhiHits" ] = &nTGCLayer1PhiHits;
      fHandles[ "nTGCLayer2EtaHits" ] = &nTGCLayer2EtaHits;
      fHandles[ "nTGCLayer2PhiHits" ] = &nTGCLayer2PhiHits;
      fHandles[ "nTGCLayer3EtaHits" ] = &nTGCLayer3EtaHits;
      fHandles[ "nTGCLayer3PhiHits" ] = &nTGCLayer3PhiHits;
      fHandles[ "nTGCLayer4EtaHits" ] = &nTGCLayer4EtaHits;
      fHandles[ "nTGCLayer4PhiHits" ] = &nTGCLayer4PhiHits;
      fHandles[ "nTGCPhiHits" ] = &nTGCPhiHits;
      fHandles[ "nTGCPhiHoles" ] = &nTGCPhiHoles;
      fHandles[ "nTRTDeadStraws" ] = &nTRTDeadStraws;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nphiHoleLayers" ] = &nphiHoleLayers;
      fHandles[ "nphiLayers" ] = &nphiLayers;
      fHandles[ "nprecisionHoleLayers" ] = &nprecisionHoleLayers;
      fHandles[ "nprecisionLayers" ] = &nprecisionLayers;
      fHandles[ "ntrigEtaHoleLayers" ] = &ntrigEtaHoleLayers;
      fHandles[ "ntrigEtaLayers" ] = &ntrigEtaLayers;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "origin" ] = &origin;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phi_exPV" ] = &phi_exPV;
      fHandles[ "pt" ] = &pt;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "qoverp_exPV" ] = &qoverp_exPV;
      fHandles[ "scatteringCurvatureSignificance" ] = &scatteringCurvatureSignificance;
      fHandles[ "scatteringNeighbourSignificance" ] = &scatteringNeighbourSignificance;
      fHandles[ "theta_exPV" ] = &theta_exPV;
      fHandles[ "tight" ] = &tight;
      fHandles[ "trackIPEstimate_d0_biasedpvunbiased" ] = &trackIPEstimate_d0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_biasedpvunbiased" ] = &trackIPEstimate_sigd0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_biasedpvunbiased" ] = &trackIPEstimate_sigz0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_biasedpvunbiased" ] = &trackIPEstimate_z0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackcov_d0" ] = &trackcov_d0;
      fHandles[ "trackcov_d0_phi" ] = &trackcov_d0_phi;
      fHandles[ "trackcov_d0_qoverp" ] = &trackcov_d0_qoverp;
      fHandles[ "trackcov_d0_theta" ] = &trackcov_d0_theta;
      fHandles[ "trackcov_d0_z0" ] = &trackcov_d0_z0;
      fHandles[ "trackcov_phi" ] = &trackcov_phi;
      fHandles[ "trackcov_phi_qoverp" ] = &trackcov_phi_qoverp;
      fHandles[ "trackcov_phi_theta" ] = &trackcov_phi_theta;
      fHandles[ "trackcov_qoverp" ] = &trackcov_qoverp;
      fHandles[ "trackcov_theta" ] = &trackcov_theta;
      fHandles[ "trackcov_theta_qoverp" ] = &trackcov_theta_qoverp;
      fHandles[ "trackcov_z0" ] = &trackcov_z0;
      fHandles[ "trackcov_z0_phi" ] = &trackcov_z0_phi;
      fHandles[ "trackcov_z0_qoverp" ] = &trackcov_z0_qoverp;
      fHandles[ "trackcov_z0_theta" ] = &trackcov_z0_theta;
      fHandles[ "trackd0" ] = &trackd0;
      fHandles[ "trackd0beam" ] = &trackd0beam;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackd0pvunbiased" ] = &trackd0pvunbiased;
      fHandles[ "trackfitchi2" ] = &trackfitchi2;
      fHandles[ "trackfitndof" ] = &trackfitndof;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "trackqoverp" ] = &trackqoverp;
      fHandles[ "tracksigd0beam" ] = &tracksigd0beam;
      fHandles[ "tracksigd0pv" ] = &tracksigd0pv;
      fHandles[ "tracksigd0pvunbiased" ] = &tracksigd0pvunbiased;
      fHandles[ "tracksigz0beam" ] = &tracksigz0beam;
      fHandles[ "tracksigz0pv" ] = &tracksigz0pv;
      fHandles[ "tracksigz0pvunbiased" ] = &tracksigz0pvunbiased;
      fHandles[ "tracktheta" ] = &tracktheta;
      fHandles[ "trackz0" ] = &trackz0;
      fHandles[ "trackz0beam" ] = &trackz0beam;
      fHandles[ "trackz0pv" ] = &trackz0pv;
      fHandles[ "trackz0pvunbiased" ] = &trackz0pvunbiased;
      fHandles[ "truth_E" ] = &truth_E;
      fHandles[ "truth_barcode" ] = &truth_barcode;
      fHandles[ "truth_dr" ] = &truth_dr;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_matched" ] = &truth_matched;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "type" ] = &type;
      fHandles[ "z0_exPV" ] = &z0_exPV;

      // Configure all variables in a loop:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->SetParent( this );
         itr->second->SetName( fPrefix + itr->first );
         itr->second->SetMaster( 0 );
      }
   }

   /**
    * The destructor needs to delete all the allocated objects.
    */
   MuonD3PDObject::~MuonD3PDObject() {

      for( size_t i = 0; i < fProxies.size(); ++i ) {
         delete fProxies[ i ];
      }
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* MuonD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void MuonD3PDObject::SetPrefix( const char* prefix ) {

      fPrefix = prefix;

      // Set all the variable names:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->SetName( ::TString( prefix ) + itr->first );
      }

      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void MuonD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      // Call ReadFrom(...) on all the variables:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->ReadFrom( tree );
      }

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void MuonD3PDObject::WriteTo( TTree* tree ) {

      // Call WriteTo(...) on all the variables:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->WriteTo( tree );
      }

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
   void MuonD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void MuonD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      // Read in the current entry for each active variable:
      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         if( ! itr->second->IsActive() ) continue;
         itr->second->ReadCurrentEntry();
      }

      return;
   }

   D3PDReadStats MuonD3PDObject::GetStatistics() const {

      // The result object:
      D3PDReadStats result;

      // Add the statistics from each variable to the result:
      std::map< ::TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< ::TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         result.AddVariable( itr->second->GetStatistics() );
      }

      return result;
   }

   /**
    * This function can be used to copy the contents of the entire object
    * for a given event. This can be useful for instance when the user
    * wants to copy all information to an output file, and modify it a bit,
    * and only then write it out.
    *
    * @param parent The object to copy the information from
    * @returns This same object, for convenience reasons
    */
   MuonD3PDObject& MuonD3PDObject::Set( const MuonD3PDObject& parent ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Set", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( parent.E.IsAvailable() ) {
         *( E() ) = *( parent.E() );
      } else {
         E()->clear();
      }
      if( parent.EFCB_index.IsAvailable() ) {
         *( EFCB_index() ) = *( parent.EFCB_index() );
      } else {
         EFCB_index()->clear();
      }
      if( parent.EFME_index.IsAvailable() ) {
         *( EFME_index() ) = *( parent.EFME_index() );
      } else {
         EFME_index()->clear();
      }
      if( parent.EFMG_index.IsAvailable() ) {
         *( EFMG_index() ) = *( parent.EFMG_index() );
      } else {
         EFMG_index()->clear();
      }
      if( parent.SpaceTime_detID.IsAvailable() ) {
         *( SpaceTime_detID() ) = *( parent.SpaceTime_detID() );
      } else {
         SpaceTime_detID()->clear();
      }
      if( parent.SpaceTime_t.IsAvailable() ) {
         *( SpaceTime_t() ) = *( parent.SpaceTime_t() );
      } else {
         SpaceTime_t()->clear();
      }
      if( parent.SpaceTime_tError.IsAvailable() ) {
         *( SpaceTime_tError() ) = *( parent.SpaceTime_tError() );
      } else {
         SpaceTime_tError()->clear();
      }
      if( parent.SpaceTime_weight.IsAvailable() ) {
         *( SpaceTime_weight() ) = *( parent.SpaceTime_weight() );
      } else {
         SpaceTime_weight()->clear();
      }
      if( parent.SpaceTime_x.IsAvailable() ) {
         *( SpaceTime_x() ) = *( parent.SpaceTime_x() );
      } else {
         SpaceTime_x()->clear();
      }
      if( parent.SpaceTime_y.IsAvailable() ) {
         *( SpaceTime_y() ) = *( parent.SpaceTime_y() );
      } else {
         SpaceTime_y()->clear();
      }
      if( parent.SpaceTime_z.IsAvailable() ) {
         *( SpaceTime_z() ) = *( parent.SpaceTime_z() );
      } else {
         SpaceTime_z()->clear();
      }
      if( parent.allauthor.IsAvailable() ) {
         *( allauthor() ) = *( parent.allauthor() );
      } else {
         allauthor()->clear();
      }
      if( parent.alsoFoundByCaloMuonId.IsAvailable() ) {
         *( alsoFoundByCaloMuonId() ) = *( parent.alsoFoundByCaloMuonId() );
      } else {
         alsoFoundByCaloMuonId()->clear();
      }
      if( parent.alsoFoundByLowPt.IsAvailable() ) {
         *( alsoFoundByLowPt() ) = *( parent.alsoFoundByLowPt() );
      } else {
         alsoFoundByLowPt()->clear();
      }
      if( parent.author.IsAvailable() ) {
         *( author() ) = *( parent.author() );
      } else {
         author()->clear();
      }
      if( parent.barrelSectors.IsAvailable() ) {
         *( barrelSectors() ) = *( parent.barrelSectors() );
      } else {
         barrelSectors()->clear();
      }
      if( parent.bestMatch.IsAvailable() ) {
         *( bestMatch() ) = *( parent.bestMatch() );
      } else {
         bestMatch()->clear();
      }
      if( parent.beta.IsAvailable() ) {
         *( beta() ) = *( parent.beta() );
      } else {
         beta()->clear();
      }
      if( parent.caloLRLikelihood.IsAvailable() ) {
         *( caloLRLikelihood() ) = *( parent.caloLRLikelihood() );
      } else {
         caloLRLikelihood()->clear();
      }
      if( parent.caloMuonIdTag.IsAvailable() ) {
         *( caloMuonIdTag() ) = *( parent.caloMuonIdTag() );
      } else {
         caloMuonIdTag()->clear();
      }
      if( parent.cb_d0_exPV.IsAvailable() ) {
         *( cb_d0_exPV() ) = *( parent.cb_d0_exPV() );
      } else {
         cb_d0_exPV()->clear();
      }
      if( parent.cb_phi_exPV.IsAvailable() ) {
         *( cb_phi_exPV() ) = *( parent.cb_phi_exPV() );
      } else {
         cb_phi_exPV()->clear();
      }
      if( parent.cb_qoverp_exPV.IsAvailable() ) {
         *( cb_qoverp_exPV() ) = *( parent.cb_qoverp_exPV() );
      } else {
         cb_qoverp_exPV()->clear();
      }
      if( parent.cb_theta_exPV.IsAvailable() ) {
         *( cb_theta_exPV() ) = *( parent.cb_theta_exPV() );
      } else {
         cb_theta_exPV()->clear();
      }
      if( parent.cb_z0_exPV.IsAvailable() ) {
         *( cb_z0_exPV() ) = *( parent.cb_z0_exPV() );
      } else {
         cb_z0_exPV()->clear();
      }
      if( parent.charge.IsAvailable() ) {
         *( charge() ) = *( parent.charge() );
      } else {
         charge()->clear();
      }
      if( parent.cov_d0_exPV.IsAvailable() ) {
         *( cov_d0_exPV() ) = *( parent.cov_d0_exPV() );
      } else {
         cov_d0_exPV()->clear();
      }
      if( parent.cov_d0_phi_exPV.IsAvailable() ) {
         *( cov_d0_phi_exPV() ) = *( parent.cov_d0_phi_exPV() );
      } else {
         cov_d0_phi_exPV()->clear();
      }
      if( parent.cov_d0_qoverp_exPV.IsAvailable() ) {
         *( cov_d0_qoverp_exPV() ) = *( parent.cov_d0_qoverp_exPV() );
      } else {
         cov_d0_qoverp_exPV()->clear();
      }
      if( parent.cov_d0_theta_exPV.IsAvailable() ) {
         *( cov_d0_theta_exPV() ) = *( parent.cov_d0_theta_exPV() );
      } else {
         cov_d0_theta_exPV()->clear();
      }
      if( parent.cov_d0_z0_exPV.IsAvailable() ) {
         *( cov_d0_z0_exPV() ) = *( parent.cov_d0_z0_exPV() );
      } else {
         cov_d0_z0_exPV()->clear();
      }
      if( parent.cov_phi_exPV.IsAvailable() ) {
         *( cov_phi_exPV() ) = *( parent.cov_phi_exPV() );
      } else {
         cov_phi_exPV()->clear();
      }
      if( parent.cov_phi_qoverp_exPV.IsAvailable() ) {
         *( cov_phi_qoverp_exPV() ) = *( parent.cov_phi_qoverp_exPV() );
      } else {
         cov_phi_qoverp_exPV()->clear();
      }
      if( parent.cov_phi_theta_exPV.IsAvailable() ) {
         *( cov_phi_theta_exPV() ) = *( parent.cov_phi_theta_exPV() );
      } else {
         cov_phi_theta_exPV()->clear();
      }
      if( parent.cov_qoverp_exPV.IsAvailable() ) {
         *( cov_qoverp_exPV() ) = *( parent.cov_qoverp_exPV() );
      } else {
         cov_qoverp_exPV()->clear();
      }
      if( parent.cov_theta_exPV.IsAvailable() ) {
         *( cov_theta_exPV() ) = *( parent.cov_theta_exPV() );
      } else {
         cov_theta_exPV()->clear();
      }
      if( parent.cov_theta_qoverp_exPV.IsAvailable() ) {
         *( cov_theta_qoverp_exPV() ) = *( parent.cov_theta_qoverp_exPV() );
      } else {
         cov_theta_qoverp_exPV()->clear();
      }
      if( parent.cov_z0_exPV.IsAvailable() ) {
         *( cov_z0_exPV() ) = *( parent.cov_z0_exPV() );
      } else {
         cov_z0_exPV()->clear();
      }
      if( parent.cov_z0_phi_exPV.IsAvailable() ) {
         *( cov_z0_phi_exPV() ) = *( parent.cov_z0_phi_exPV() );
      } else {
         cov_z0_phi_exPV()->clear();
      }
      if( parent.cov_z0_qoverp_exPV.IsAvailable() ) {
         *( cov_z0_qoverp_exPV() ) = *( parent.cov_z0_qoverp_exPV() );
      } else {
         cov_z0_qoverp_exPV()->clear();
      }
      if( parent.cov_z0_theta_exPV.IsAvailable() ) {
         *( cov_z0_theta_exPV() ) = *( parent.cov_z0_theta_exPV() );
      } else {
         cov_z0_theta_exPV()->clear();
      }
      if( parent.d0_exPV.IsAvailable() ) {
         *( d0_exPV() ) = *( parent.d0_exPV() );
      } else {
         d0_exPV()->clear();
      }
      if( parent.endcapSectors.IsAvailable() ) {
         *( endcapSectors() ) = *( parent.endcapSectors() );
      } else {
         endcapSectors()->clear();
      }
      if( parent.energyLossErr.IsAvailable() ) {
         *( energyLossErr() ) = *( parent.energyLossErr() );
      } else {
         energyLossErr()->clear();
      }
      if( parent.energyLossPar.IsAvailable() ) {
         *( energyLossPar() ) = *( parent.energyLossPar() );
      } else {
         energyLossPar()->clear();
      }
      if( parent.energyLossType.IsAvailable() ) {
         *( energyLossType() ) = *( parent.energyLossType() );
      } else {
         energyLossType()->clear();
      }
      if( parent.etCore.IsAvailable() ) {
         *( etCore() ) = *( parent.etCore() );
      } else {
         etCore()->clear();
      }
      if( parent.eta.IsAvailable() ) {
         *( eta() ) = *( parent.eta() );
      } else {
         eta()->clear();
      }
      if( parent.etcone20.IsAvailable() ) {
         *( etcone20() ) = *( parent.etcone20() );
      } else {
         etcone20()->clear();
      }
      if( parent.etcone30.IsAvailable() ) {
         *( etcone30() ) = *( parent.etcone30() );
      } else {
         etcone30()->clear();
      }
      if( parent.etcone40.IsAvailable() ) {
         *( etcone40() ) = *( parent.etcone40() );
      } else {
         etcone40()->clear();
      }
      if( parent.expectBLayerHit.IsAvailable() ) {
         *( expectBLayerHit() ) = *( parent.expectBLayerHit() );
      } else {
         expectBLayerHit()->clear();
      }
      if( parent.hastrack.IsAvailable() ) {
         *( hastrack() ) = *( parent.hastrack() );
      } else {
         hastrack()->clear();
      }
      if( parent.id_cov_d0_exPV.IsAvailable() ) {
         *( id_cov_d0_exPV() ) = *( parent.id_cov_d0_exPV() );
      } else {
         id_cov_d0_exPV()->clear();
      }
      if( parent.id_cov_d0_phi_exPV.IsAvailable() ) {
         *( id_cov_d0_phi_exPV() ) = *( parent.id_cov_d0_phi_exPV() );
      } else {
         id_cov_d0_phi_exPV()->clear();
      }
      if( parent.id_cov_d0_qoverp_exPV.IsAvailable() ) {
         *( id_cov_d0_qoverp_exPV() ) = *( parent.id_cov_d0_qoverp_exPV() );
      } else {
         id_cov_d0_qoverp_exPV()->clear();
      }
      if( parent.id_cov_d0_theta_exPV.IsAvailable() ) {
         *( id_cov_d0_theta_exPV() ) = *( parent.id_cov_d0_theta_exPV() );
      } else {
         id_cov_d0_theta_exPV()->clear();
      }
      if( parent.id_cov_d0_z0_exPV.IsAvailable() ) {
         *( id_cov_d0_z0_exPV() ) = *( parent.id_cov_d0_z0_exPV() );
      } else {
         id_cov_d0_z0_exPV()->clear();
      }
      if( parent.id_cov_phi_exPV.IsAvailable() ) {
         *( id_cov_phi_exPV() ) = *( parent.id_cov_phi_exPV() );
      } else {
         id_cov_phi_exPV()->clear();
      }
      if( parent.id_cov_phi_qoverp_exPV.IsAvailable() ) {
         *( id_cov_phi_qoverp_exPV() ) = *( parent.id_cov_phi_qoverp_exPV() );
      } else {
         id_cov_phi_qoverp_exPV()->clear();
      }
      if( parent.id_cov_phi_theta_exPV.IsAvailable() ) {
         *( id_cov_phi_theta_exPV() ) = *( parent.id_cov_phi_theta_exPV() );
      } else {
         id_cov_phi_theta_exPV()->clear();
      }
      if( parent.id_cov_qoverp_exPV.IsAvailable() ) {
         *( id_cov_qoverp_exPV() ) = *( parent.id_cov_qoverp_exPV() );
      } else {
         id_cov_qoverp_exPV()->clear();
      }
      if( parent.id_cov_theta_exPV.IsAvailable() ) {
         *( id_cov_theta_exPV() ) = *( parent.id_cov_theta_exPV() );
      } else {
         id_cov_theta_exPV()->clear();
      }
      if( parent.id_cov_theta_qoverp_exPV.IsAvailable() ) {
         *( id_cov_theta_qoverp_exPV() ) = *( parent.id_cov_theta_qoverp_exPV() );
      } else {
         id_cov_theta_qoverp_exPV()->clear();
      }
      if( parent.id_cov_z0_exPV.IsAvailable() ) {
         *( id_cov_z0_exPV() ) = *( parent.id_cov_z0_exPV() );
      } else {
         id_cov_z0_exPV()->clear();
      }
      if( parent.id_cov_z0_phi_exPV.IsAvailable() ) {
         *( id_cov_z0_phi_exPV() ) = *( parent.id_cov_z0_phi_exPV() );
      } else {
         id_cov_z0_phi_exPV()->clear();
      }
      if( parent.id_cov_z0_qoverp_exPV.IsAvailable() ) {
         *( id_cov_z0_qoverp_exPV() ) = *( parent.id_cov_z0_qoverp_exPV() );
      } else {
         id_cov_z0_qoverp_exPV()->clear();
      }
      if( parent.id_cov_z0_theta_exPV.IsAvailable() ) {
         *( id_cov_z0_theta_exPV() ) = *( parent.id_cov_z0_theta_exPV() );
      } else {
         id_cov_z0_theta_exPV()->clear();
      }
      if( parent.id_d0.IsAvailable() ) {
         *( id_d0() ) = *( parent.id_d0() );
      } else {
         id_d0()->clear();
      }
      if( parent.id_d0_exPV.IsAvailable() ) {
         *( id_d0_exPV() ) = *( parent.id_d0_exPV() );
      } else {
         id_d0_exPV()->clear();
      }
      if( parent.id_phi.IsAvailable() ) {
         *( id_phi() ) = *( parent.id_phi() );
      } else {
         id_phi()->clear();
      }
      if( parent.id_phi_exPV.IsAvailable() ) {
         *( id_phi_exPV() ) = *( parent.id_phi_exPV() );
      } else {
         id_phi_exPV()->clear();
      }
      if( parent.id_qoverp.IsAvailable() ) {
         *( id_qoverp() ) = *( parent.id_qoverp() );
      } else {
         id_qoverp()->clear();
      }
      if( parent.id_qoverp_exPV.IsAvailable() ) {
         *( id_qoverp_exPV() ) = *( parent.id_qoverp_exPV() );
      } else {
         id_qoverp_exPV()->clear();
      }
      if( parent.id_theta.IsAvailable() ) {
         *( id_theta() ) = *( parent.id_theta() );
      } else {
         id_theta()->clear();
      }
      if( parent.id_theta_exPV.IsAvailable() ) {
         *( id_theta_exPV() ) = *( parent.id_theta_exPV() );
      } else {
         id_theta_exPV()->clear();
      }
      if( parent.id_z0.IsAvailable() ) {
         *( id_z0() ) = *( parent.id_z0() );
      } else {
         id_z0()->clear();
      }
      if( parent.id_z0_exPV.IsAvailable() ) {
         *( id_z0_exPV() ) = *( parent.id_z0_exPV() );
      } else {
         id_z0_exPV()->clear();
      }
      if( parent.ie_d0.IsAvailable() ) {
         *( ie_d0() ) = *( parent.ie_d0() );
      } else {
         ie_d0()->clear();
      }
      if( parent.ie_d0_exPV.IsAvailable() ) {
         *( ie_d0_exPV() ) = *( parent.ie_d0_exPV() );
      } else {
         ie_d0_exPV()->clear();
      }
      if( parent.ie_phi.IsAvailable() ) {
         *( ie_phi() ) = *( parent.ie_phi() );
      } else {
         ie_phi()->clear();
      }
      if( parent.ie_phi_exPV.IsAvailable() ) {
         *( ie_phi_exPV() ) = *( parent.ie_phi_exPV() );
      } else {
         ie_phi_exPV()->clear();
      }
      if( parent.ie_qoverp.IsAvailable() ) {
         *( ie_qoverp() ) = *( parent.ie_qoverp() );
      } else {
         ie_qoverp()->clear();
      }
      if( parent.ie_qoverp_exPV.IsAvailable() ) {
         *( ie_qoverp_exPV() ) = *( parent.ie_qoverp_exPV() );
      } else {
         ie_qoverp_exPV()->clear();
      }
      if( parent.ie_theta.IsAvailable() ) {
         *( ie_theta() ) = *( parent.ie_theta() );
      } else {
         ie_theta()->clear();
      }
      if( parent.ie_theta_exPV.IsAvailable() ) {
         *( ie_theta_exPV() ) = *( parent.ie_theta_exPV() );
      } else {
         ie_theta_exPV()->clear();
      }
      if( parent.ie_z0.IsAvailable() ) {
         *( ie_z0() ) = *( parent.ie_z0() );
      } else {
         ie_z0()->clear();
      }
      if( parent.ie_z0_exPV.IsAvailable() ) {
         *( ie_z0_exPV() ) = *( parent.ie_z0_exPV() );
      } else {
         ie_z0_exPV()->clear();
      }
      if( parent.isCaloMuonId.IsAvailable() ) {
         *( isCaloMuonId() ) = *( parent.isCaloMuonId() );
      } else {
         isCaloMuonId()->clear();
      }
      if( parent.isCombinedMuon.IsAvailable() ) {
         *( isCombinedMuon() ) = *( parent.isCombinedMuon() );
      } else {
         isCombinedMuon()->clear();
      }
      if( parent.isLowPtReconstructedMuon.IsAvailable() ) {
         *( isLowPtReconstructedMuon() ) = *( parent.isLowPtReconstructedMuon() );
      } else {
         isLowPtReconstructedMuon()->clear();
      }
      if( parent.isMuonLikelihood.IsAvailable() ) {
         *( isMuonLikelihood() ) = *( parent.isMuonLikelihood() );
      } else {
         isMuonLikelihood()->clear();
      }
      if( parent.isSegmentTaggedMuon.IsAvailable() ) {
         *( isSegmentTaggedMuon() ) = *( parent.isSegmentTaggedMuon() );
      } else {
         isSegmentTaggedMuon()->clear();
      }
      if( parent.isSiliconAssociatedForwardMuon.IsAvailable() ) {
         *( isSiliconAssociatedForwardMuon() ) = *( parent.isSiliconAssociatedForwardMuon() );
      } else {
         isSiliconAssociatedForwardMuon()->clear();
      }
      if( parent.isStandAloneMuon.IsAvailable() ) {
         *( isStandAloneMuon() ) = *( parent.isStandAloneMuon() );
      } else {
         isStandAloneMuon()->clear();
      }
      if( parent.loose.IsAvailable() ) {
         *( loose() ) = *( parent.loose() );
      } else {
         loose()->clear();
      }
      if( parent.m.IsAvailable() ) {
         *( m() ) = *( parent.m() );
      } else {
         m()->clear();
      }
      if( parent.matchchi2.IsAvailable() ) {
         *( matchchi2() ) = *( parent.matchchi2() );
      } else {
         matchchi2()->clear();
      }
      if( parent.matchndof.IsAvailable() ) {
         *( matchndof() ) = *( parent.matchndof() );
      } else {
         matchndof()->clear();
      }
      if( parent.me_cov_d0_exPV.IsAvailable() ) {
         *( me_cov_d0_exPV() ) = *( parent.me_cov_d0_exPV() );
      } else {
         me_cov_d0_exPV()->clear();
      }
      if( parent.me_cov_d0_phi_exPV.IsAvailable() ) {
         *( me_cov_d0_phi_exPV() ) = *( parent.me_cov_d0_phi_exPV() );
      } else {
         me_cov_d0_phi_exPV()->clear();
      }
      if( parent.me_cov_d0_qoverp_exPV.IsAvailable() ) {
         *( me_cov_d0_qoverp_exPV() ) = *( parent.me_cov_d0_qoverp_exPV() );
      } else {
         me_cov_d0_qoverp_exPV()->clear();
      }
      if( parent.me_cov_d0_theta_exPV.IsAvailable() ) {
         *( me_cov_d0_theta_exPV() ) = *( parent.me_cov_d0_theta_exPV() );
      } else {
         me_cov_d0_theta_exPV()->clear();
      }
      if( parent.me_cov_d0_z0_exPV.IsAvailable() ) {
         *( me_cov_d0_z0_exPV() ) = *( parent.me_cov_d0_z0_exPV() );
      } else {
         me_cov_d0_z0_exPV()->clear();
      }
      if( parent.me_cov_phi_exPV.IsAvailable() ) {
         *( me_cov_phi_exPV() ) = *( parent.me_cov_phi_exPV() );
      } else {
         me_cov_phi_exPV()->clear();
      }
      if( parent.me_cov_phi_qoverp_exPV.IsAvailable() ) {
         *( me_cov_phi_qoverp_exPV() ) = *( parent.me_cov_phi_qoverp_exPV() );
      } else {
         me_cov_phi_qoverp_exPV()->clear();
      }
      if( parent.me_cov_phi_theta_exPV.IsAvailable() ) {
         *( me_cov_phi_theta_exPV() ) = *( parent.me_cov_phi_theta_exPV() );
      } else {
         me_cov_phi_theta_exPV()->clear();
      }
      if( parent.me_cov_qoverp_exPV.IsAvailable() ) {
         *( me_cov_qoverp_exPV() ) = *( parent.me_cov_qoverp_exPV() );
      } else {
         me_cov_qoverp_exPV()->clear();
      }
      if( parent.me_cov_theta_exPV.IsAvailable() ) {
         *( me_cov_theta_exPV() ) = *( parent.me_cov_theta_exPV() );
      } else {
         me_cov_theta_exPV()->clear();
      }
      if( parent.me_cov_theta_qoverp_exPV.IsAvailable() ) {
         *( me_cov_theta_qoverp_exPV() ) = *( parent.me_cov_theta_qoverp_exPV() );
      } else {
         me_cov_theta_qoverp_exPV()->clear();
      }
      if( parent.me_cov_z0_exPV.IsAvailable() ) {
         *( me_cov_z0_exPV() ) = *( parent.me_cov_z0_exPV() );
      } else {
         me_cov_z0_exPV()->clear();
      }
      if( parent.me_cov_z0_phi_exPV.IsAvailable() ) {
         *( me_cov_z0_phi_exPV() ) = *( parent.me_cov_z0_phi_exPV() );
      } else {
         me_cov_z0_phi_exPV()->clear();
      }
      if( parent.me_cov_z0_qoverp_exPV.IsAvailable() ) {
         *( me_cov_z0_qoverp_exPV() ) = *( parent.me_cov_z0_qoverp_exPV() );
      } else {
         me_cov_z0_qoverp_exPV()->clear();
      }
      if( parent.me_cov_z0_theta_exPV.IsAvailable() ) {
         *( me_cov_z0_theta_exPV() ) = *( parent.me_cov_z0_theta_exPV() );
      } else {
         me_cov_z0_theta_exPV()->clear();
      }
      if( parent.me_d0.IsAvailable() ) {
         *( me_d0() ) = *( parent.me_d0() );
      } else {
         me_d0()->clear();
      }
      if( parent.me_d0_exPV.IsAvailable() ) {
         *( me_d0_exPV() ) = *( parent.me_d0_exPV() );
      } else {
         me_d0_exPV()->clear();
      }
      if( parent.me_phi.IsAvailable() ) {
         *( me_phi() ) = *( parent.me_phi() );
      } else {
         me_phi()->clear();
      }
      if( parent.me_phi_exPV.IsAvailable() ) {
         *( me_phi_exPV() ) = *( parent.me_phi_exPV() );
      } else {
         me_phi_exPV()->clear();
      }
      if( parent.me_qoverp.IsAvailable() ) {
         *( me_qoverp() ) = *( parent.me_qoverp() );
      } else {
         me_qoverp()->clear();
      }
      if( parent.me_qoverp_exPV.IsAvailable() ) {
         *( me_qoverp_exPV() ) = *( parent.me_qoverp_exPV() );
      } else {
         me_qoverp_exPV()->clear();
      }
      if( parent.me_theta.IsAvailable() ) {
         *( me_theta() ) = *( parent.me_theta() );
      } else {
         me_theta()->clear();
      }
      if( parent.me_theta_exPV.IsAvailable() ) {
         *( me_theta_exPV() ) = *( parent.me_theta_exPV() );
      } else {
         me_theta_exPV()->clear();
      }
      if( parent.me_z0.IsAvailable() ) {
         *( me_z0() ) = *( parent.me_z0() );
      } else {
         me_z0()->clear();
      }
      if( parent.me_z0_exPV.IsAvailable() ) {
         *( me_z0_exPV() ) = *( parent.me_z0_exPV() );
      } else {
         me_z0_exPV()->clear();
      }
      if( parent.medium.IsAvailable() ) {
         *( medium() ) = *( parent.medium() );
      } else {
         medium()->clear();
      }
      if( parent.momentumBalanceSignificance.IsAvailable() ) {
         *( momentumBalanceSignificance() ) = *( parent.momentumBalanceSignificance() );
      } else {
         momentumBalanceSignificance()->clear();
      }
      if( parent.ms_d0.IsAvailable() ) {
         *( ms_d0() ) = *( parent.ms_d0() );
      } else {
         ms_d0()->clear();
      }
      if( parent.ms_phi.IsAvailable() ) {
         *( ms_phi() ) = *( parent.ms_phi() );
      } else {
         ms_phi()->clear();
      }
      if( parent.ms_qoverp.IsAvailable() ) {
         *( ms_qoverp() ) = *( parent.ms_qoverp() );
      } else {
         ms_qoverp()->clear();
      }
      if( parent.ms_theta.IsAvailable() ) {
         *( ms_theta() ) = *( parent.ms_theta() );
      } else {
         ms_theta()->clear();
      }
      if( parent.ms_z0.IsAvailable() ) {
         *( ms_z0() ) = *( parent.ms_z0() );
      } else {
         ms_z0()->clear();
      }
      if( parent.n.IsAvailable() ) {
         n() = parent.n();
      } else {
         n() = 0;
      }
      if( parent.nBLHits.IsAvailable() ) {
         *( nBLHits() ) = *( parent.nBLHits() );
      } else {
         nBLHits()->clear();
      }
      if( parent.nBLSharedHits.IsAvailable() ) {
         *( nBLSharedHits() ) = *( parent.nBLSharedHits() );
      } else {
         nBLSharedHits()->clear();
      }
      if( parent.nCSCEtaHits.IsAvailable() ) {
         *( nCSCEtaHits() ) = *( parent.nCSCEtaHits() );
      } else {
         nCSCEtaHits()->clear();
      }
      if( parent.nCSCEtaHoles.IsAvailable() ) {
         *( nCSCEtaHoles() ) = *( parent.nCSCEtaHoles() );
      } else {
         nCSCEtaHoles()->clear();
      }
      if( parent.nCSCPhiHits.IsAvailable() ) {
         *( nCSCPhiHits() ) = *( parent.nCSCPhiHits() );
      } else {
         nCSCPhiHits()->clear();
      }
      if( parent.nCSCPhiHoles.IsAvailable() ) {
         *( nCSCPhiHoles() ) = *( parent.nCSCPhiHoles() );
      } else {
         nCSCPhiHoles()->clear();
      }
      if( parent.nCSCUnspoiledEtaHits.IsAvailable() ) {
         *( nCSCUnspoiledEtaHits() ) = *( parent.nCSCUnspoiledEtaHits() );
      } else {
         nCSCUnspoiledEtaHits()->clear();
      }
      if( parent.nGangedPixels.IsAvailable() ) {
         *( nGangedPixels() ) = *( parent.nGangedPixels() );
      } else {
         nGangedPixels()->clear();
      }
      if( parent.nMDTBEEHits.IsAvailable() ) {
         *( nMDTBEEHits() ) = *( parent.nMDTBEEHits() );
      } else {
         nMDTBEEHits()->clear();
      }
      if( parent.nMDTBIHits.IsAvailable() ) {
         *( nMDTBIHits() ) = *( parent.nMDTBIHits() );
      } else {
         nMDTBIHits()->clear();
      }
      if( parent.nMDTBIS78Hits.IsAvailable() ) {
         *( nMDTBIS78Hits() ) = *( parent.nMDTBIS78Hits() );
      } else {
         nMDTBIS78Hits()->clear();
      }
      if( parent.nMDTBMHits.IsAvailable() ) {
         *( nMDTBMHits() ) = *( parent.nMDTBMHits() );
      } else {
         nMDTBMHits()->clear();
      }
      if( parent.nMDTBOHits.IsAvailable() ) {
         *( nMDTBOHits() ) = *( parent.nMDTBOHits() );
      } else {
         nMDTBOHits()->clear();
      }
      if( parent.nMDTEEHits.IsAvailable() ) {
         *( nMDTEEHits() ) = *( parent.nMDTEEHits() );
      } else {
         nMDTEEHits()->clear();
      }
      if( parent.nMDTEIHits.IsAvailable() ) {
         *( nMDTEIHits() ) = *( parent.nMDTEIHits() );
      } else {
         nMDTEIHits()->clear();
      }
      if( parent.nMDTEMHits.IsAvailable() ) {
         *( nMDTEMHits() ) = *( parent.nMDTEMHits() );
      } else {
         nMDTEMHits()->clear();
      }
      if( parent.nMDTEOHits.IsAvailable() ) {
         *( nMDTEOHits() ) = *( parent.nMDTEOHits() );
      } else {
         nMDTEOHits()->clear();
      }
      if( parent.nMDTHits.IsAvailable() ) {
         *( nMDTHits() ) = *( parent.nMDTHits() );
      } else {
         nMDTHits()->clear();
      }
      if( parent.nMDTHoles.IsAvailable() ) {
         *( nMDTHoles() ) = *( parent.nMDTHoles() );
      } else {
         nMDTHoles()->clear();
      }
      if( parent.nOutliersOnTrack.IsAvailable() ) {
         *( nOutliersOnTrack() ) = *( parent.nOutliersOnTrack() );
      } else {
         nOutliersOnTrack()->clear();
      }
      if( parent.nPixHits.IsAvailable() ) {
         *( nPixHits() ) = *( parent.nPixHits() );
      } else {
         nPixHits()->clear();
      }
      if( parent.nPixHoles.IsAvailable() ) {
         *( nPixHoles() ) = *( parent.nPixHoles() );
      } else {
         nPixHoles()->clear();
      }
      if( parent.nPixSharedHits.IsAvailable() ) {
         *( nPixSharedHits() ) = *( parent.nPixSharedHits() );
      } else {
         nPixSharedHits()->clear();
      }
      if( parent.nPixelDeadSensors.IsAvailable() ) {
         *( nPixelDeadSensors() ) = *( parent.nPixelDeadSensors() );
      } else {
         nPixelDeadSensors()->clear();
      }
      if( parent.nRPCEtaHits.IsAvailable() ) {
         *( nRPCEtaHits() ) = *( parent.nRPCEtaHits() );
      } else {
         nRPCEtaHits()->clear();
      }
      if( parent.nRPCEtaHoles.IsAvailable() ) {
         *( nRPCEtaHoles() ) = *( parent.nRPCEtaHoles() );
      } else {
         nRPCEtaHoles()->clear();
      }
      if( parent.nRPCLayer1EtaHits.IsAvailable() ) {
         *( nRPCLayer1EtaHits() ) = *( parent.nRPCLayer1EtaHits() );
      } else {
         nRPCLayer1EtaHits()->clear();
      }
      if( parent.nRPCLayer1PhiHits.IsAvailable() ) {
         *( nRPCLayer1PhiHits() ) = *( parent.nRPCLayer1PhiHits() );
      } else {
         nRPCLayer1PhiHits()->clear();
      }
      if( parent.nRPCLayer2EtaHits.IsAvailable() ) {
         *( nRPCLayer2EtaHits() ) = *( parent.nRPCLayer2EtaHits() );
      } else {
         nRPCLayer2EtaHits()->clear();
      }
      if( parent.nRPCLayer2PhiHits.IsAvailable() ) {
         *( nRPCLayer2PhiHits() ) = *( parent.nRPCLayer2PhiHits() );
      } else {
         nRPCLayer2PhiHits()->clear();
      }
      if( parent.nRPCLayer3EtaHits.IsAvailable() ) {
         *( nRPCLayer3EtaHits() ) = *( parent.nRPCLayer3EtaHits() );
      } else {
         nRPCLayer3EtaHits()->clear();
      }
      if( parent.nRPCLayer3PhiHits.IsAvailable() ) {
         *( nRPCLayer3PhiHits() ) = *( parent.nRPCLayer3PhiHits() );
      } else {
         nRPCLayer3PhiHits()->clear();
      }
      if( parent.nRPCPhiHits.IsAvailable() ) {
         *( nRPCPhiHits() ) = *( parent.nRPCPhiHits() );
      } else {
         nRPCPhiHits()->clear();
      }
      if( parent.nRPCPhiHoles.IsAvailable() ) {
         *( nRPCPhiHoles() ) = *( parent.nRPCPhiHoles() );
      } else {
         nRPCPhiHoles()->clear();
      }
      if( parent.nSCTDeadSensors.IsAvailable() ) {
         *( nSCTDeadSensors() ) = *( parent.nSCTDeadSensors() );
      } else {
         nSCTDeadSensors()->clear();
      }
      if( parent.nSCTHits.IsAvailable() ) {
         *( nSCTHits() ) = *( parent.nSCTHits() );
      } else {
         nSCTHits()->clear();
      }
      if( parent.nSCTHoles.IsAvailable() ) {
         *( nSCTHoles() ) = *( parent.nSCTHoles() );
      } else {
         nSCTHoles()->clear();
      }
      if( parent.nSCTSharedHits.IsAvailable() ) {
         *( nSCTSharedHits() ) = *( parent.nSCTSharedHits() );
      } else {
         nSCTSharedHits()->clear();
      }
      if( parent.nTGCEtaHits.IsAvailable() ) {
         *( nTGCEtaHits() ) = *( parent.nTGCEtaHits() );
      } else {
         nTGCEtaHits()->clear();
      }
      if( parent.nTGCEtaHoles.IsAvailable() ) {
         *( nTGCEtaHoles() ) = *( parent.nTGCEtaHoles() );
      } else {
         nTGCEtaHoles()->clear();
      }
      if( parent.nTGCLayer1EtaHits.IsAvailable() ) {
         *( nTGCLayer1EtaHits() ) = *( parent.nTGCLayer1EtaHits() );
      } else {
         nTGCLayer1EtaHits()->clear();
      }
      if( parent.nTGCLayer1PhiHits.IsAvailable() ) {
         *( nTGCLayer1PhiHits() ) = *( parent.nTGCLayer1PhiHits() );
      } else {
         nTGCLayer1PhiHits()->clear();
      }
      if( parent.nTGCLayer2EtaHits.IsAvailable() ) {
         *( nTGCLayer2EtaHits() ) = *( parent.nTGCLayer2EtaHits() );
      } else {
         nTGCLayer2EtaHits()->clear();
      }
      if( parent.nTGCLayer2PhiHits.IsAvailable() ) {
         *( nTGCLayer2PhiHits() ) = *( parent.nTGCLayer2PhiHits() );
      } else {
         nTGCLayer2PhiHits()->clear();
      }
      if( parent.nTGCLayer3EtaHits.IsAvailable() ) {
         *( nTGCLayer3EtaHits() ) = *( parent.nTGCLayer3EtaHits() );
      } else {
         nTGCLayer3EtaHits()->clear();
      }
      if( parent.nTGCLayer3PhiHits.IsAvailable() ) {
         *( nTGCLayer3PhiHits() ) = *( parent.nTGCLayer3PhiHits() );
      } else {
         nTGCLayer3PhiHits()->clear();
      }
      if( parent.nTGCLayer4EtaHits.IsAvailable() ) {
         *( nTGCLayer4EtaHits() ) = *( parent.nTGCLayer4EtaHits() );
      } else {
         nTGCLayer4EtaHits()->clear();
      }
      if( parent.nTGCLayer4PhiHits.IsAvailable() ) {
         *( nTGCLayer4PhiHits() ) = *( parent.nTGCLayer4PhiHits() );
      } else {
         nTGCLayer4PhiHits()->clear();
      }
      if( parent.nTGCPhiHits.IsAvailable() ) {
         *( nTGCPhiHits() ) = *( parent.nTGCPhiHits() );
      } else {
         nTGCPhiHits()->clear();
      }
      if( parent.nTGCPhiHoles.IsAvailable() ) {
         *( nTGCPhiHoles() ) = *( parent.nTGCPhiHoles() );
      } else {
         nTGCPhiHoles()->clear();
      }
      if( parent.nTRTDeadStraws.IsAvailable() ) {
         *( nTRTDeadStraws() ) = *( parent.nTRTDeadStraws() );
      } else {
         nTRTDeadStraws()->clear();
      }
      if( parent.nTRTHighTHits.IsAvailable() ) {
         *( nTRTHighTHits() ) = *( parent.nTRTHighTHits() );
      } else {
         nTRTHighTHits()->clear();
      }
      if( parent.nTRTHighTOutliers.IsAvailable() ) {
         *( nTRTHighTOutliers() ) = *( parent.nTRTHighTOutliers() );
      } else {
         nTRTHighTOutliers()->clear();
      }
      if( parent.nTRTHits.IsAvailable() ) {
         *( nTRTHits() ) = *( parent.nTRTHits() );
      } else {
         nTRTHits()->clear();
      }
      if( parent.nTRTOutliers.IsAvailable() ) {
         *( nTRTOutliers() ) = *( parent.nTRTOutliers() );
      } else {
         nTRTOutliers()->clear();
      }
      if( parent.nphiHoleLayers.IsAvailable() ) {
         *( nphiHoleLayers() ) = *( parent.nphiHoleLayers() );
      } else {
         nphiHoleLayers()->clear();
      }
      if( parent.nphiLayers.IsAvailable() ) {
         *( nphiLayers() ) = *( parent.nphiLayers() );
      } else {
         nphiLayers()->clear();
      }
      if( parent.nprecisionHoleLayers.IsAvailable() ) {
         *( nprecisionHoleLayers() ) = *( parent.nprecisionHoleLayers() );
      } else {
         nprecisionHoleLayers()->clear();
      }
      if( parent.nprecisionLayers.IsAvailable() ) {
         *( nprecisionLayers() ) = *( parent.nprecisionLayers() );
      } else {
         nprecisionLayers()->clear();
      }
      if( parent.ntrigEtaHoleLayers.IsAvailable() ) {
         *( ntrigEtaHoleLayers() ) = *( parent.ntrigEtaHoleLayers() );
      } else {
         ntrigEtaHoleLayers()->clear();
      }
      if( parent.ntrigEtaLayers.IsAvailable() ) {
         *( ntrigEtaLayers() ) = *( parent.ntrigEtaLayers() );
      } else {
         ntrigEtaLayers()->clear();
      }
      if( parent.nucone20.IsAvailable() ) {
         *( nucone20() ) = *( parent.nucone20() );
      } else {
         nucone20()->clear();
      }
      if( parent.nucone30.IsAvailable() ) {
         *( nucone30() ) = *( parent.nucone30() );
      } else {
         nucone30()->clear();
      }
      if( parent.nucone40.IsAvailable() ) {
         *( nucone40() ) = *( parent.nucone40() );
      } else {
         nucone40()->clear();
      }
      if( parent.origin.IsAvailable() ) {
         *( origin() ) = *( parent.origin() );
      } else {
         origin()->clear();
      }
      if( parent.phi.IsAvailable() ) {
         *( phi() ) = *( parent.phi() );
      } else {
         phi()->clear();
      }
      if( parent.phi_exPV.IsAvailable() ) {
         *( phi_exPV() ) = *( parent.phi_exPV() );
      } else {
         phi_exPV()->clear();
      }
      if( parent.pt.IsAvailable() ) {
         *( pt() ) = *( parent.pt() );
      } else {
         pt()->clear();
      }
      if( parent.ptcone20.IsAvailable() ) {
         *( ptcone20() ) = *( parent.ptcone20() );
      } else {
         ptcone20()->clear();
      }
      if( parent.ptcone30.IsAvailable() ) {
         *( ptcone30() ) = *( parent.ptcone30() );
      } else {
         ptcone30()->clear();
      }
      if( parent.ptcone40.IsAvailable() ) {
         *( ptcone40() ) = *( parent.ptcone40() );
      } else {
         ptcone40()->clear();
      }
      if( parent.px.IsAvailable() ) {
         *( px() ) = *( parent.px() );
      } else {
         px()->clear();
      }
      if( parent.py.IsAvailable() ) {
         *( py() ) = *( parent.py() );
      } else {
         py()->clear();
      }
      if( parent.pz.IsAvailable() ) {
         *( pz() ) = *( parent.pz() );
      } else {
         pz()->clear();
      }
      if( parent.qoverp_exPV.IsAvailable() ) {
         *( qoverp_exPV() ) = *( parent.qoverp_exPV() );
      } else {
         qoverp_exPV()->clear();
      }
      if( parent.scatteringCurvatureSignificance.IsAvailable() ) {
         *( scatteringCurvatureSignificance() ) = *( parent.scatteringCurvatureSignificance() );
      } else {
         scatteringCurvatureSignificance()->clear();
      }
      if( parent.scatteringNeighbourSignificance.IsAvailable() ) {
         *( scatteringNeighbourSignificance() ) = *( parent.scatteringNeighbourSignificance() );
      } else {
         scatteringNeighbourSignificance()->clear();
      }
      if( parent.theta_exPV.IsAvailable() ) {
         *( theta_exPV() ) = *( parent.theta_exPV() );
      } else {
         theta_exPV()->clear();
      }
      if( parent.tight.IsAvailable() ) {
         *( tight() ) = *( parent.tight() );
      } else {
         tight()->clear();
      }
      if( parent.trackIPEstimate_d0_biasedpvunbiased.IsAvailable() ) {
         *( trackIPEstimate_d0_biasedpvunbiased() ) = *( parent.trackIPEstimate_d0_biasedpvunbiased() );
      } else {
         trackIPEstimate_d0_biasedpvunbiased()->clear();
      }
      if( parent.trackIPEstimate_d0_unbiasedpvunbiased.IsAvailable() ) {
         *( trackIPEstimate_d0_unbiasedpvunbiased() ) = *( parent.trackIPEstimate_d0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_d0_unbiasedpvunbiased()->clear();
      }
      if( parent.trackIPEstimate_sigd0_biasedpvunbiased.IsAvailable() ) {
         *( trackIPEstimate_sigd0_biasedpvunbiased() ) = *( parent.trackIPEstimate_sigd0_biasedpvunbiased() );
      } else {
         trackIPEstimate_sigd0_biasedpvunbiased()->clear();
      }
      if( parent.trackIPEstimate_sigd0_unbiasedpvunbiased.IsAvailable() ) {
         *( trackIPEstimate_sigd0_unbiasedpvunbiased() ) = *( parent.trackIPEstimate_sigd0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_sigd0_unbiasedpvunbiased()->clear();
      }
      if( parent.trackIPEstimate_sigz0_biasedpvunbiased.IsAvailable() ) {
         *( trackIPEstimate_sigz0_biasedpvunbiased() ) = *( parent.trackIPEstimate_sigz0_biasedpvunbiased() );
      } else {
         trackIPEstimate_sigz0_biasedpvunbiased()->clear();
      }
      if( parent.trackIPEstimate_sigz0_unbiasedpvunbiased.IsAvailable() ) {
         *( trackIPEstimate_sigz0_unbiasedpvunbiased() ) = *( parent.trackIPEstimate_sigz0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_sigz0_unbiasedpvunbiased()->clear();
      }
      if( parent.trackIPEstimate_z0_biasedpvunbiased.IsAvailable() ) {
         *( trackIPEstimate_z0_biasedpvunbiased() ) = *( parent.trackIPEstimate_z0_biasedpvunbiased() );
      } else {
         trackIPEstimate_z0_biasedpvunbiased()->clear();
      }
      if( parent.trackIPEstimate_z0_unbiasedpvunbiased.IsAvailable() ) {
         *( trackIPEstimate_z0_unbiasedpvunbiased() ) = *( parent.trackIPEstimate_z0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_z0_unbiasedpvunbiased()->clear();
      }
      if( parent.trackcov_d0.IsAvailable() ) {
         *( trackcov_d0() ) = *( parent.trackcov_d0() );
      } else {
         trackcov_d0()->clear();
      }
      if( parent.trackcov_d0_phi.IsAvailable() ) {
         *( trackcov_d0_phi() ) = *( parent.trackcov_d0_phi() );
      } else {
         trackcov_d0_phi()->clear();
      }
      if( parent.trackcov_d0_qoverp.IsAvailable() ) {
         *( trackcov_d0_qoverp() ) = *( parent.trackcov_d0_qoverp() );
      } else {
         trackcov_d0_qoverp()->clear();
      }
      if( parent.trackcov_d0_theta.IsAvailable() ) {
         *( trackcov_d0_theta() ) = *( parent.trackcov_d0_theta() );
      } else {
         trackcov_d0_theta()->clear();
      }
      if( parent.trackcov_d0_z0.IsAvailable() ) {
         *( trackcov_d0_z0() ) = *( parent.trackcov_d0_z0() );
      } else {
         trackcov_d0_z0()->clear();
      }
      if( parent.trackcov_phi.IsAvailable() ) {
         *( trackcov_phi() ) = *( parent.trackcov_phi() );
      } else {
         trackcov_phi()->clear();
      }
      if( parent.trackcov_phi_qoverp.IsAvailable() ) {
         *( trackcov_phi_qoverp() ) = *( parent.trackcov_phi_qoverp() );
      } else {
         trackcov_phi_qoverp()->clear();
      }
      if( parent.trackcov_phi_theta.IsAvailable() ) {
         *( trackcov_phi_theta() ) = *( parent.trackcov_phi_theta() );
      } else {
         trackcov_phi_theta()->clear();
      }
      if( parent.trackcov_qoverp.IsAvailable() ) {
         *( trackcov_qoverp() ) = *( parent.trackcov_qoverp() );
      } else {
         trackcov_qoverp()->clear();
      }
      if( parent.trackcov_theta.IsAvailable() ) {
         *( trackcov_theta() ) = *( parent.trackcov_theta() );
      } else {
         trackcov_theta()->clear();
      }
      if( parent.trackcov_theta_qoverp.IsAvailable() ) {
         *( trackcov_theta_qoverp() ) = *( parent.trackcov_theta_qoverp() );
      } else {
         trackcov_theta_qoverp()->clear();
      }
      if( parent.trackcov_z0.IsAvailable() ) {
         *( trackcov_z0() ) = *( parent.trackcov_z0() );
      } else {
         trackcov_z0()->clear();
      }
      if( parent.trackcov_z0_phi.IsAvailable() ) {
         *( trackcov_z0_phi() ) = *( parent.trackcov_z0_phi() );
      } else {
         trackcov_z0_phi()->clear();
      }
      if( parent.trackcov_z0_qoverp.IsAvailable() ) {
         *( trackcov_z0_qoverp() ) = *( parent.trackcov_z0_qoverp() );
      } else {
         trackcov_z0_qoverp()->clear();
      }
      if( parent.trackcov_z0_theta.IsAvailable() ) {
         *( trackcov_z0_theta() ) = *( parent.trackcov_z0_theta() );
      } else {
         trackcov_z0_theta()->clear();
      }
      if( parent.trackd0.IsAvailable() ) {
         *( trackd0() ) = *( parent.trackd0() );
      } else {
         trackd0()->clear();
      }
      if( parent.trackd0beam.IsAvailable() ) {
         *( trackd0beam() ) = *( parent.trackd0beam() );
      } else {
         trackd0beam()->clear();
      }
      if( parent.trackd0pv.IsAvailable() ) {
         *( trackd0pv() ) = *( parent.trackd0pv() );
      } else {
         trackd0pv()->clear();
      }
      if( parent.trackd0pvunbiased.IsAvailable() ) {
         *( trackd0pvunbiased() ) = *( parent.trackd0pvunbiased() );
      } else {
         trackd0pvunbiased()->clear();
      }
      if( parent.trackfitchi2.IsAvailable() ) {
         *( trackfitchi2() ) = *( parent.trackfitchi2() );
      } else {
         trackfitchi2()->clear();
      }
      if( parent.trackfitndof.IsAvailable() ) {
         *( trackfitndof() ) = *( parent.trackfitndof() );
      } else {
         trackfitndof()->clear();
      }
      if( parent.trackphi.IsAvailable() ) {
         *( trackphi() ) = *( parent.trackphi() );
      } else {
         trackphi()->clear();
      }
      if( parent.trackqoverp.IsAvailable() ) {
         *( trackqoverp() ) = *( parent.trackqoverp() );
      } else {
         trackqoverp()->clear();
      }
      if( parent.tracksigd0beam.IsAvailable() ) {
         *( tracksigd0beam() ) = *( parent.tracksigd0beam() );
      } else {
         tracksigd0beam()->clear();
      }
      if( parent.tracksigd0pv.IsAvailable() ) {
         *( tracksigd0pv() ) = *( parent.tracksigd0pv() );
      } else {
         tracksigd0pv()->clear();
      }
      if( parent.tracksigd0pvunbiased.IsAvailable() ) {
         *( tracksigd0pvunbiased() ) = *( parent.tracksigd0pvunbiased() );
      } else {
         tracksigd0pvunbiased()->clear();
      }
      if( parent.tracksigz0beam.IsAvailable() ) {
         *( tracksigz0beam() ) = *( parent.tracksigz0beam() );
      } else {
         tracksigz0beam()->clear();
      }
      if( parent.tracksigz0pv.IsAvailable() ) {
         *( tracksigz0pv() ) = *( parent.tracksigz0pv() );
      } else {
         tracksigz0pv()->clear();
      }
      if( parent.tracksigz0pvunbiased.IsAvailable() ) {
         *( tracksigz0pvunbiased() ) = *( parent.tracksigz0pvunbiased() );
      } else {
         tracksigz0pvunbiased()->clear();
      }
      if( parent.tracktheta.IsAvailable() ) {
         *( tracktheta() ) = *( parent.tracktheta() );
      } else {
         tracktheta()->clear();
      }
      if( parent.trackz0.IsAvailable() ) {
         *( trackz0() ) = *( parent.trackz0() );
      } else {
         trackz0()->clear();
      }
      if( parent.trackz0beam.IsAvailable() ) {
         *( trackz0beam() ) = *( parent.trackz0beam() );
      } else {
         trackz0beam()->clear();
      }
      if( parent.trackz0pv.IsAvailable() ) {
         *( trackz0pv() ) = *( parent.trackz0pv() );
      } else {
         trackz0pv()->clear();
      }
      if( parent.trackz0pvunbiased.IsAvailable() ) {
         *( trackz0pvunbiased() ) = *( parent.trackz0pvunbiased() );
      } else {
         trackz0pvunbiased()->clear();
      }
      if( parent.truth_E.IsAvailable() ) {
         *( truth_E() ) = *( parent.truth_E() );
      } else {
         truth_E()->clear();
      }
      if( parent.truth_barcode.IsAvailable() ) {
         *( truth_barcode() ) = *( parent.truth_barcode() );
      } else {
         truth_barcode()->clear();
      }
      if( parent.truth_dr.IsAvailable() ) {
         *( truth_dr() ) = *( parent.truth_dr() );
      } else {
         truth_dr()->clear();
      }
      if( parent.truth_eta.IsAvailable() ) {
         *( truth_eta() ) = *( parent.truth_eta() );
      } else {
         truth_eta()->clear();
      }
      if( parent.truth_matched.IsAvailable() ) {
         *( truth_matched() ) = *( parent.truth_matched() );
      } else {
         truth_matched()->clear();
      }
      if( parent.truth_motherbarcode.IsAvailable() ) {
         *( truth_motherbarcode() ) = *( parent.truth_motherbarcode() );
      } else {
         truth_motherbarcode()->clear();
      }
      if( parent.truth_mothertype.IsAvailable() ) {
         *( truth_mothertype() ) = *( parent.truth_mothertype() );
      } else {
         truth_mothertype()->clear();
      }
      if( parent.truth_phi.IsAvailable() ) {
         *( truth_phi() ) = *( parent.truth_phi() );
      } else {
         truth_phi()->clear();
      }
      if( parent.truth_pt.IsAvailable() ) {
         *( truth_pt() ) = *( parent.truth_pt() );
      } else {
         truth_pt()->clear();
      }
      if( parent.truth_status.IsAvailable() ) {
         *( truth_status() ) = *( parent.truth_status() );
      } else {
         truth_status()->clear();
      }
      if( parent.truth_type.IsAvailable() ) {
         *( truth_type() ) = *( parent.truth_type() );
      } else {
         truth_type()->clear();
      }
      if( parent.type.IsAvailable() ) {
         *( type() ) = *( parent.type() );
      } else {
         type()->clear();
      }
      if( parent.z0_exPV.IsAvailable() ) {
         *( z0_exPV() ) = *( parent.z0_exPV() );
      } else {
         z0_exPV()->clear();
      }

      return *this;
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
   void MuonD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      // Clear each variable:
      std::map< ::TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< ::TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         itr->second->Clear();
      }

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
   MuonD3PDObject& MuonD3PDObject::Add( const MuonD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( el.E.IsAvailable() ) {
         E()->push_back( el.E() );
      } else {
         E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EFCB_index.IsAvailable() ) {
         EFCB_index()->push_back( el.EFCB_index() );
      } else {
         EFCB_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EFME_index.IsAvailable() ) {
         EFME_index()->push_back( el.EFME_index() );
      } else {
         EFME_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EFMG_index.IsAvailable() ) {
         EFMG_index()->push_back( el.EFMG_index() );
      } else {
         EFMG_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.SpaceTime_detID.IsAvailable() ) {
         SpaceTime_detID()->push_back( el.SpaceTime_detID() );
      } else {
         SpaceTime_detID()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.SpaceTime_t.IsAvailable() ) {
         SpaceTime_t()->push_back( el.SpaceTime_t() );
      } else {
         SpaceTime_t()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.SpaceTime_tError.IsAvailable() ) {
         SpaceTime_tError()->push_back( el.SpaceTime_tError() );
      } else {
         SpaceTime_tError()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.SpaceTime_weight.IsAvailable() ) {
         SpaceTime_weight()->push_back( el.SpaceTime_weight() );
      } else {
         SpaceTime_weight()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.SpaceTime_x.IsAvailable() ) {
         SpaceTime_x()->push_back( el.SpaceTime_x() );
      } else {
         SpaceTime_x()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.SpaceTime_y.IsAvailable() ) {
         SpaceTime_y()->push_back( el.SpaceTime_y() );
      } else {
         SpaceTime_y()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.SpaceTime_z.IsAvailable() ) {
         SpaceTime_z()->push_back( el.SpaceTime_z() );
      } else {
         SpaceTime_z()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.allauthor.IsAvailable() ) {
         allauthor()->push_back( el.allauthor() );
      } else {
         allauthor()->push_back( std::numeric_limits< unsigned short >::min() );
      }
      if( el.alsoFoundByCaloMuonId.IsAvailable() ) {
         alsoFoundByCaloMuonId()->push_back( el.alsoFoundByCaloMuonId() );
      } else {
         alsoFoundByCaloMuonId()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.alsoFoundByLowPt.IsAvailable() ) {
         alsoFoundByLowPt()->push_back( el.alsoFoundByLowPt() );
      } else {
         alsoFoundByLowPt()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.author.IsAvailable() ) {
         author()->push_back( el.author() );
      } else {
         author()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.barrelSectors.IsAvailable() ) {
         barrelSectors()->push_back( el.barrelSectors() );
      } else {
         barrelSectors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.bestMatch.IsAvailable() ) {
         bestMatch()->push_back( el.bestMatch() );
      } else {
         bestMatch()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.beta.IsAvailable() ) {
         beta()->push_back( el.beta() );
      } else {
         beta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.caloLRLikelihood.IsAvailable() ) {
         caloLRLikelihood()->push_back( el.caloLRLikelihood() );
      } else {
         caloLRLikelihood()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.caloMuonIdTag.IsAvailable() ) {
         caloMuonIdTag()->push_back( el.caloMuonIdTag() );
      } else {
         caloMuonIdTag()->push_back( std::numeric_limits< unsigned short >::min() );
      }
      if( el.cb_d0_exPV.IsAvailable() ) {
         cb_d0_exPV()->push_back( el.cb_d0_exPV() );
      } else {
         cb_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_phi_exPV.IsAvailable() ) {
         cb_phi_exPV()->push_back( el.cb_phi_exPV() );
      } else {
         cb_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_qoverp_exPV.IsAvailable() ) {
         cb_qoverp_exPV()->push_back( el.cb_qoverp_exPV() );
      } else {
         cb_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_theta_exPV.IsAvailable() ) {
         cb_theta_exPV()->push_back( el.cb_theta_exPV() );
      } else {
         cb_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_z0_exPV.IsAvailable() ) {
         cb_z0_exPV()->push_back( el.cb_z0_exPV() );
      } else {
         cb_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.charge.IsAvailable() ) {
         charge()->push_back( el.charge() );
      } else {
         charge()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_exPV.IsAvailable() ) {
         cov_d0_exPV()->push_back( el.cov_d0_exPV() );
      } else {
         cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_phi_exPV.IsAvailable() ) {
         cov_d0_phi_exPV()->push_back( el.cov_d0_phi_exPV() );
      } else {
         cov_d0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_qoverp_exPV.IsAvailable() ) {
         cov_d0_qoverp_exPV()->push_back( el.cov_d0_qoverp_exPV() );
      } else {
         cov_d0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_theta_exPV.IsAvailable() ) {
         cov_d0_theta_exPV()->push_back( el.cov_d0_theta_exPV() );
      } else {
         cov_d0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_z0_exPV.IsAvailable() ) {
         cov_d0_z0_exPV()->push_back( el.cov_d0_z0_exPV() );
      } else {
         cov_d0_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_phi_exPV.IsAvailable() ) {
         cov_phi_exPV()->push_back( el.cov_phi_exPV() );
      } else {
         cov_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_phi_qoverp_exPV.IsAvailable() ) {
         cov_phi_qoverp_exPV()->push_back( el.cov_phi_qoverp_exPV() );
      } else {
         cov_phi_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_phi_theta_exPV.IsAvailable() ) {
         cov_phi_theta_exPV()->push_back( el.cov_phi_theta_exPV() );
      } else {
         cov_phi_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_qoverp_exPV.IsAvailable() ) {
         cov_qoverp_exPV()->push_back( el.cov_qoverp_exPV() );
      } else {
         cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_theta_exPV.IsAvailable() ) {
         cov_theta_exPV()->push_back( el.cov_theta_exPV() );
      } else {
         cov_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_theta_qoverp_exPV.IsAvailable() ) {
         cov_theta_qoverp_exPV()->push_back( el.cov_theta_qoverp_exPV() );
      } else {
         cov_theta_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_exPV.IsAvailable() ) {
         cov_z0_exPV()->push_back( el.cov_z0_exPV() );
      } else {
         cov_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_phi_exPV.IsAvailable() ) {
         cov_z0_phi_exPV()->push_back( el.cov_z0_phi_exPV() );
      } else {
         cov_z0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_qoverp_exPV.IsAvailable() ) {
         cov_z0_qoverp_exPV()->push_back( el.cov_z0_qoverp_exPV() );
      } else {
         cov_z0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_theta_exPV.IsAvailable() ) {
         cov_z0_theta_exPV()->push_back( el.cov_z0_theta_exPV() );
      } else {
         cov_z0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.d0_exPV.IsAvailable() ) {
         d0_exPV()->push_back( el.d0_exPV() );
      } else {
         d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.endcapSectors.IsAvailable() ) {
         endcapSectors()->push_back( el.endcapSectors() );
      } else {
         endcapSectors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.energyLossErr.IsAvailable() ) {
         energyLossErr()->push_back( el.energyLossErr() );
      } else {
         energyLossErr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.energyLossPar.IsAvailable() ) {
         energyLossPar()->push_back( el.energyLossPar() );
      } else {
         energyLossPar()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.energyLossType.IsAvailable() ) {
         energyLossType()->push_back( el.energyLossType() );
      } else {
         energyLossType()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etCore.IsAvailable() ) {
         etCore()->push_back( el.etCore() );
      } else {
         etCore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eta.IsAvailable() ) {
         eta()->push_back( el.eta() );
      } else {
         eta()->push_back( std::numeric_limits< float >::min() );
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
      if( el.expectBLayerHit.IsAvailable() ) {
         expectBLayerHit()->push_back( el.expectBLayerHit() );
      } else {
         expectBLayerHit()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.hastrack.IsAvailable() ) {
         hastrack()->push_back( el.hastrack() );
      } else {
         hastrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.id_cov_d0_exPV.IsAvailable() ) {
         id_cov_d0_exPV()->push_back( el.id_cov_d0_exPV() );
      } else {
         id_cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_phi_exPV.IsAvailable() ) {
         id_cov_d0_phi_exPV()->push_back( el.id_cov_d0_phi_exPV() );
      } else {
         id_cov_d0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_qoverp_exPV.IsAvailable() ) {
         id_cov_d0_qoverp_exPV()->push_back( el.id_cov_d0_qoverp_exPV() );
      } else {
         id_cov_d0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_theta_exPV.IsAvailable() ) {
         id_cov_d0_theta_exPV()->push_back( el.id_cov_d0_theta_exPV() );
      } else {
         id_cov_d0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_z0_exPV.IsAvailable() ) {
         id_cov_d0_z0_exPV()->push_back( el.id_cov_d0_z0_exPV() );
      } else {
         id_cov_d0_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_phi_exPV.IsAvailable() ) {
         id_cov_phi_exPV()->push_back( el.id_cov_phi_exPV() );
      } else {
         id_cov_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_phi_qoverp_exPV.IsAvailable() ) {
         id_cov_phi_qoverp_exPV()->push_back( el.id_cov_phi_qoverp_exPV() );
      } else {
         id_cov_phi_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_phi_theta_exPV.IsAvailable() ) {
         id_cov_phi_theta_exPV()->push_back( el.id_cov_phi_theta_exPV() );
      } else {
         id_cov_phi_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_qoverp_exPV.IsAvailable() ) {
         id_cov_qoverp_exPV()->push_back( el.id_cov_qoverp_exPV() );
      } else {
         id_cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_theta_exPV.IsAvailable() ) {
         id_cov_theta_exPV()->push_back( el.id_cov_theta_exPV() );
      } else {
         id_cov_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_theta_qoverp_exPV.IsAvailable() ) {
         id_cov_theta_qoverp_exPV()->push_back( el.id_cov_theta_qoverp_exPV() );
      } else {
         id_cov_theta_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_z0_exPV.IsAvailable() ) {
         id_cov_z0_exPV()->push_back( el.id_cov_z0_exPV() );
      } else {
         id_cov_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_z0_phi_exPV.IsAvailable() ) {
         id_cov_z0_phi_exPV()->push_back( el.id_cov_z0_phi_exPV() );
      } else {
         id_cov_z0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_z0_qoverp_exPV.IsAvailable() ) {
         id_cov_z0_qoverp_exPV()->push_back( el.id_cov_z0_qoverp_exPV() );
      } else {
         id_cov_z0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_z0_theta_exPV.IsAvailable() ) {
         id_cov_z0_theta_exPV()->push_back( el.id_cov_z0_theta_exPV() );
      } else {
         id_cov_z0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_d0.IsAvailable() ) {
         id_d0()->push_back( el.id_d0() );
      } else {
         id_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_d0_exPV.IsAvailable() ) {
         id_d0_exPV()->push_back( el.id_d0_exPV() );
      } else {
         id_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_phi.IsAvailable() ) {
         id_phi()->push_back( el.id_phi() );
      } else {
         id_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_phi_exPV.IsAvailable() ) {
         id_phi_exPV()->push_back( el.id_phi_exPV() );
      } else {
         id_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_qoverp.IsAvailable() ) {
         id_qoverp()->push_back( el.id_qoverp() );
      } else {
         id_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_qoverp_exPV.IsAvailable() ) {
         id_qoverp_exPV()->push_back( el.id_qoverp_exPV() );
      } else {
         id_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_theta.IsAvailable() ) {
         id_theta()->push_back( el.id_theta() );
      } else {
         id_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_theta_exPV.IsAvailable() ) {
         id_theta_exPV()->push_back( el.id_theta_exPV() );
      } else {
         id_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_z0.IsAvailable() ) {
         id_z0()->push_back( el.id_z0() );
      } else {
         id_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_z0_exPV.IsAvailable() ) {
         id_z0_exPV()->push_back( el.id_z0_exPV() );
      } else {
         id_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_d0.IsAvailable() ) {
         ie_d0()->push_back( el.ie_d0() );
      } else {
         ie_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_d0_exPV.IsAvailable() ) {
         ie_d0_exPV()->push_back( el.ie_d0_exPV() );
      } else {
         ie_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_phi.IsAvailable() ) {
         ie_phi()->push_back( el.ie_phi() );
      } else {
         ie_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_phi_exPV.IsAvailable() ) {
         ie_phi_exPV()->push_back( el.ie_phi_exPV() );
      } else {
         ie_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_qoverp.IsAvailable() ) {
         ie_qoverp()->push_back( el.ie_qoverp() );
      } else {
         ie_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_qoverp_exPV.IsAvailable() ) {
         ie_qoverp_exPV()->push_back( el.ie_qoverp_exPV() );
      } else {
         ie_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_theta.IsAvailable() ) {
         ie_theta()->push_back( el.ie_theta() );
      } else {
         ie_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_theta_exPV.IsAvailable() ) {
         ie_theta_exPV()->push_back( el.ie_theta_exPV() );
      } else {
         ie_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_z0.IsAvailable() ) {
         ie_z0()->push_back( el.ie_z0() );
      } else {
         ie_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_z0_exPV.IsAvailable() ) {
         ie_z0_exPV()->push_back( el.ie_z0_exPV() );
      } else {
         ie_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.isCaloMuonId.IsAvailable() ) {
         isCaloMuonId()->push_back( el.isCaloMuonId() );
      } else {
         isCaloMuonId()->push_back( std::numeric_limits< int >::min() );
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
      if( el.isMuonLikelihood.IsAvailable() ) {
         isMuonLikelihood()->push_back( el.isMuonLikelihood() );
      } else {
         isMuonLikelihood()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.isSegmentTaggedMuon.IsAvailable() ) {
         isSegmentTaggedMuon()->push_back( el.isSegmentTaggedMuon() );
      } else {
         isSegmentTaggedMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isSiliconAssociatedForwardMuon.IsAvailable() ) {
         isSiliconAssociatedForwardMuon()->push_back( el.isSiliconAssociatedForwardMuon() );
      } else {
         isSiliconAssociatedForwardMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isStandAloneMuon.IsAvailable() ) {
         isStandAloneMuon()->push_back( el.isStandAloneMuon() );
      } else {
         isStandAloneMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.loose.IsAvailable() ) {
         loose()->push_back( el.loose() );
      } else {
         loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
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
      if( el.me_cov_d0_exPV.IsAvailable() ) {
         me_cov_d0_exPV()->push_back( el.me_cov_d0_exPV() );
      } else {
         me_cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_d0_phi_exPV.IsAvailable() ) {
         me_cov_d0_phi_exPV()->push_back( el.me_cov_d0_phi_exPV() );
      } else {
         me_cov_d0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_d0_qoverp_exPV.IsAvailable() ) {
         me_cov_d0_qoverp_exPV()->push_back( el.me_cov_d0_qoverp_exPV() );
      } else {
         me_cov_d0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_d0_theta_exPV.IsAvailable() ) {
         me_cov_d0_theta_exPV()->push_back( el.me_cov_d0_theta_exPV() );
      } else {
         me_cov_d0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_d0_z0_exPV.IsAvailable() ) {
         me_cov_d0_z0_exPV()->push_back( el.me_cov_d0_z0_exPV() );
      } else {
         me_cov_d0_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_phi_exPV.IsAvailable() ) {
         me_cov_phi_exPV()->push_back( el.me_cov_phi_exPV() );
      } else {
         me_cov_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_phi_qoverp_exPV.IsAvailable() ) {
         me_cov_phi_qoverp_exPV()->push_back( el.me_cov_phi_qoverp_exPV() );
      } else {
         me_cov_phi_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_phi_theta_exPV.IsAvailable() ) {
         me_cov_phi_theta_exPV()->push_back( el.me_cov_phi_theta_exPV() );
      } else {
         me_cov_phi_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_qoverp_exPV.IsAvailable() ) {
         me_cov_qoverp_exPV()->push_back( el.me_cov_qoverp_exPV() );
      } else {
         me_cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_theta_exPV.IsAvailable() ) {
         me_cov_theta_exPV()->push_back( el.me_cov_theta_exPV() );
      } else {
         me_cov_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_theta_qoverp_exPV.IsAvailable() ) {
         me_cov_theta_qoverp_exPV()->push_back( el.me_cov_theta_qoverp_exPV() );
      } else {
         me_cov_theta_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_z0_exPV.IsAvailable() ) {
         me_cov_z0_exPV()->push_back( el.me_cov_z0_exPV() );
      } else {
         me_cov_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_z0_phi_exPV.IsAvailable() ) {
         me_cov_z0_phi_exPV()->push_back( el.me_cov_z0_phi_exPV() );
      } else {
         me_cov_z0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_z0_qoverp_exPV.IsAvailable() ) {
         me_cov_z0_qoverp_exPV()->push_back( el.me_cov_z0_qoverp_exPV() );
      } else {
         me_cov_z0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_z0_theta_exPV.IsAvailable() ) {
         me_cov_z0_theta_exPV()->push_back( el.me_cov_z0_theta_exPV() );
      } else {
         me_cov_z0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_d0.IsAvailable() ) {
         me_d0()->push_back( el.me_d0() );
      } else {
         me_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_d0_exPV.IsAvailable() ) {
         me_d0_exPV()->push_back( el.me_d0_exPV() );
      } else {
         me_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_phi.IsAvailable() ) {
         me_phi()->push_back( el.me_phi() );
      } else {
         me_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_phi_exPV.IsAvailable() ) {
         me_phi_exPV()->push_back( el.me_phi_exPV() );
      } else {
         me_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_qoverp.IsAvailable() ) {
         me_qoverp()->push_back( el.me_qoverp() );
      } else {
         me_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_qoverp_exPV.IsAvailable() ) {
         me_qoverp_exPV()->push_back( el.me_qoverp_exPV() );
      } else {
         me_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_theta.IsAvailable() ) {
         me_theta()->push_back( el.me_theta() );
      } else {
         me_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_theta_exPV.IsAvailable() ) {
         me_theta_exPV()->push_back( el.me_theta_exPV() );
      } else {
         me_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_z0.IsAvailable() ) {
         me_z0()->push_back( el.me_z0() );
      } else {
         me_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_z0_exPV.IsAvailable() ) {
         me_z0_exPV()->push_back( el.me_z0_exPV() );
      } else {
         me_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.medium.IsAvailable() ) {
         medium()->push_back( el.medium() );
      } else {
         medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.momentumBalanceSignificance.IsAvailable() ) {
         momentumBalanceSignificance()->push_back( el.momentumBalanceSignificance() );
      } else {
         momentumBalanceSignificance()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_d0.IsAvailable() ) {
         ms_d0()->push_back( el.ms_d0() );
      } else {
         ms_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_phi.IsAvailable() ) {
         ms_phi()->push_back( el.ms_phi() );
      } else {
         ms_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_qoverp.IsAvailable() ) {
         ms_qoverp()->push_back( el.ms_qoverp() );
      } else {
         ms_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_theta.IsAvailable() ) {
         ms_theta()->push_back( el.ms_theta() );
      } else {
         ms_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_z0.IsAvailable() ) {
         ms_z0()->push_back( el.ms_z0() );
      } else {
         ms_z0()->push_back( std::numeric_limits< float >::min() );
      }
      ++( n() );
      if( el.nBLHits.IsAvailable() ) {
         nBLHits()->push_back( el.nBLHits() );
      } else {
         nBLHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nBLSharedHits.IsAvailable() ) {
         nBLSharedHits()->push_back( el.nBLSharedHits() );
      } else {
         nBLSharedHits()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nCSCUnspoiledEtaHits.IsAvailable() ) {
         nCSCUnspoiledEtaHits()->push_back( el.nCSCUnspoiledEtaHits() );
      } else {
         nCSCUnspoiledEtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nGangedPixels.IsAvailable() ) {
         nGangedPixels()->push_back( el.nGangedPixels() );
      } else {
         nGangedPixels()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBEEHits.IsAvailable() ) {
         nMDTBEEHits()->push_back( el.nMDTBEEHits() );
      } else {
         nMDTBEEHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBIHits.IsAvailable() ) {
         nMDTBIHits()->push_back( el.nMDTBIHits() );
      } else {
         nMDTBIHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBIS78Hits.IsAvailable() ) {
         nMDTBIS78Hits()->push_back( el.nMDTBIS78Hits() );
      } else {
         nMDTBIS78Hits()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nMDTEEHits.IsAvailable() ) {
         nMDTEEHits()->push_back( el.nMDTEEHits() );
      } else {
         nMDTEEHits()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nOutliersOnTrack.IsAvailable() ) {
         nOutliersOnTrack()->push_back( el.nOutliersOnTrack() );
      } else {
         nOutliersOnTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixHits.IsAvailable() ) {
         nPixHits()->push_back( el.nPixHits() );
      } else {
         nPixHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixHoles.IsAvailable() ) {
         nPixHoles()->push_back( el.nPixHoles() );
      } else {
         nPixHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixSharedHits.IsAvailable() ) {
         nPixSharedHits()->push_back( el.nPixSharedHits() );
      } else {
         nPixSharedHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixelDeadSensors.IsAvailable() ) {
         nPixelDeadSensors()->push_back( el.nPixelDeadSensors() );
      } else {
         nPixelDeadSensors()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nRPCLayer1EtaHits.IsAvailable() ) {
         nRPCLayer1EtaHits()->push_back( el.nRPCLayer1EtaHits() );
      } else {
         nRPCLayer1EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer1PhiHits.IsAvailable() ) {
         nRPCLayer1PhiHits()->push_back( el.nRPCLayer1PhiHits() );
      } else {
         nRPCLayer1PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer2EtaHits.IsAvailable() ) {
         nRPCLayer2EtaHits()->push_back( el.nRPCLayer2EtaHits() );
      } else {
         nRPCLayer2EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer2PhiHits.IsAvailable() ) {
         nRPCLayer2PhiHits()->push_back( el.nRPCLayer2PhiHits() );
      } else {
         nRPCLayer2PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer3EtaHits.IsAvailable() ) {
         nRPCLayer3EtaHits()->push_back( el.nRPCLayer3EtaHits() );
      } else {
         nRPCLayer3EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nRPCLayer3PhiHits.IsAvailable() ) {
         nRPCLayer3PhiHits()->push_back( el.nRPCLayer3PhiHits() );
      } else {
         nRPCLayer3PhiHits()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nSCTDeadSensors.IsAvailable() ) {
         nSCTDeadSensors()->push_back( el.nSCTDeadSensors() );
      } else {
         nSCTDeadSensors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTHits.IsAvailable() ) {
         nSCTHits()->push_back( el.nSCTHits() );
      } else {
         nSCTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTHoles.IsAvailable() ) {
         nSCTHoles()->push_back( el.nSCTHoles() );
      } else {
         nSCTHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTSharedHits.IsAvailable() ) {
         nSCTSharedHits()->push_back( el.nSCTSharedHits() );
      } else {
         nSCTSharedHits()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nTGCLayer1EtaHits.IsAvailable() ) {
         nTGCLayer1EtaHits()->push_back( el.nTGCLayer1EtaHits() );
      } else {
         nTGCLayer1EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer1PhiHits.IsAvailable() ) {
         nTGCLayer1PhiHits()->push_back( el.nTGCLayer1PhiHits() );
      } else {
         nTGCLayer1PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer2EtaHits.IsAvailable() ) {
         nTGCLayer2EtaHits()->push_back( el.nTGCLayer2EtaHits() );
      } else {
         nTGCLayer2EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer2PhiHits.IsAvailable() ) {
         nTGCLayer2PhiHits()->push_back( el.nTGCLayer2PhiHits() );
      } else {
         nTGCLayer2PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer3EtaHits.IsAvailable() ) {
         nTGCLayer3EtaHits()->push_back( el.nTGCLayer3EtaHits() );
      } else {
         nTGCLayer3EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer3PhiHits.IsAvailable() ) {
         nTGCLayer3PhiHits()->push_back( el.nTGCLayer3PhiHits() );
      } else {
         nTGCLayer3PhiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer4EtaHits.IsAvailable() ) {
         nTGCLayer4EtaHits()->push_back( el.nTGCLayer4EtaHits() );
      } else {
         nTGCLayer4EtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTGCLayer4PhiHits.IsAvailable() ) {
         nTGCLayer4PhiHits()->push_back( el.nTGCLayer4PhiHits() );
      } else {
         nTGCLayer4PhiHits()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nTRTDeadStraws.IsAvailable() ) {
         nTRTDeadStraws()->push_back( el.nTRTDeadStraws() );
      } else {
         nTRTDeadStraws()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHighTHits.IsAvailable() ) {
         nTRTHighTHits()->push_back( el.nTRTHighTHits() );
      } else {
         nTRTHighTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHighTOutliers.IsAvailable() ) {
         nTRTHighTOutliers()->push_back( el.nTRTHighTOutliers() );
      } else {
         nTRTHighTOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHits.IsAvailable() ) {
         nTRTHits()->push_back( el.nTRTHits() );
      } else {
         nTRTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTOutliers.IsAvailable() ) {
         nTRTOutliers()->push_back( el.nTRTOutliers() );
      } else {
         nTRTOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nphiHoleLayers.IsAvailable() ) {
         nphiHoleLayers()->push_back( el.nphiHoleLayers() );
      } else {
         nphiHoleLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nphiLayers.IsAvailable() ) {
         nphiLayers()->push_back( el.nphiLayers() );
      } else {
         nphiLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nprecisionHoleLayers.IsAvailable() ) {
         nprecisionHoleLayers()->push_back( el.nprecisionHoleLayers() );
      } else {
         nprecisionHoleLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nprecisionLayers.IsAvailable() ) {
         nprecisionLayers()->push_back( el.nprecisionLayers() );
      } else {
         nprecisionLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ntrigEtaHoleLayers.IsAvailable() ) {
         ntrigEtaHoleLayers()->push_back( el.ntrigEtaHoleLayers() );
      } else {
         ntrigEtaHoleLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ntrigEtaLayers.IsAvailable() ) {
         ntrigEtaLayers()->push_back( el.ntrigEtaLayers() );
      } else {
         ntrigEtaLayers()->push_back( std::numeric_limits< int >::min() );
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
      if( el.origin.IsAvailable() ) {
         origin()->push_back( el.origin() );
      } else {
         origin()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.phi.IsAvailable() ) {
         phi()->push_back( el.phi() );
      } else {
         phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phi_exPV.IsAvailable() ) {
         phi_exPV()->push_back( el.phi_exPV() );
      } else {
         phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pt.IsAvailable() ) {
         pt()->push_back( el.pt() );
      } else {
         pt()->push_back( std::numeric_limits< float >::min() );
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
      if( el.qoverp_exPV.IsAvailable() ) {
         qoverp_exPV()->push_back( el.qoverp_exPV() );
      } else {
         qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.scatteringCurvatureSignificance.IsAvailable() ) {
         scatteringCurvatureSignificance()->push_back( el.scatteringCurvatureSignificance() );
      } else {
         scatteringCurvatureSignificance()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.scatteringNeighbourSignificance.IsAvailable() ) {
         scatteringNeighbourSignificance()->push_back( el.scatteringNeighbourSignificance() );
      } else {
         scatteringNeighbourSignificance()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.theta_exPV.IsAvailable() ) {
         theta_exPV()->push_back( el.theta_exPV() );
      } else {
         theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tight.IsAvailable() ) {
         tight()->push_back( el.tight() );
      } else {
         tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trackIPEstimate_d0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_d0_biasedpvunbiased()->push_back( el.trackIPEstimate_d0_biasedpvunbiased() );
      } else {
         trackIPEstimate_d0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_d0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_d0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_d0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_d0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigd0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigd0_biasedpvunbiased()->push_back( el.trackIPEstimate_sigd0_biasedpvunbiased() );
      } else {
         trackIPEstimate_sigd0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigd0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigd0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_sigd0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_sigd0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigz0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigz0_biasedpvunbiased()->push_back( el.trackIPEstimate_sigz0_biasedpvunbiased() );
      } else {
         trackIPEstimate_sigz0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigz0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigz0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_sigz0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_sigz0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_z0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_z0_biasedpvunbiased()->push_back( el.trackIPEstimate_z0_biasedpvunbiased() );
      } else {
         trackIPEstimate_z0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_z0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_z0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_z0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_z0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0.IsAvailable() ) {
         trackcov_d0()->push_back( el.trackcov_d0() );
      } else {
         trackcov_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_phi.IsAvailable() ) {
         trackcov_d0_phi()->push_back( el.trackcov_d0_phi() );
      } else {
         trackcov_d0_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_qoverp.IsAvailable() ) {
         trackcov_d0_qoverp()->push_back( el.trackcov_d0_qoverp() );
      } else {
         trackcov_d0_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_theta.IsAvailable() ) {
         trackcov_d0_theta()->push_back( el.trackcov_d0_theta() );
      } else {
         trackcov_d0_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_z0.IsAvailable() ) {
         trackcov_d0_z0()->push_back( el.trackcov_d0_z0() );
      } else {
         trackcov_d0_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_phi.IsAvailable() ) {
         trackcov_phi()->push_back( el.trackcov_phi() );
      } else {
         trackcov_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_phi_qoverp.IsAvailable() ) {
         trackcov_phi_qoverp()->push_back( el.trackcov_phi_qoverp() );
      } else {
         trackcov_phi_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_phi_theta.IsAvailable() ) {
         trackcov_phi_theta()->push_back( el.trackcov_phi_theta() );
      } else {
         trackcov_phi_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_qoverp.IsAvailable() ) {
         trackcov_qoverp()->push_back( el.trackcov_qoverp() );
      } else {
         trackcov_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_theta.IsAvailable() ) {
         trackcov_theta()->push_back( el.trackcov_theta() );
      } else {
         trackcov_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_theta_qoverp.IsAvailable() ) {
         trackcov_theta_qoverp()->push_back( el.trackcov_theta_qoverp() );
      } else {
         trackcov_theta_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0.IsAvailable() ) {
         trackcov_z0()->push_back( el.trackcov_z0() );
      } else {
         trackcov_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0_phi.IsAvailable() ) {
         trackcov_z0_phi()->push_back( el.trackcov_z0_phi() );
      } else {
         trackcov_z0_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0_qoverp.IsAvailable() ) {
         trackcov_z0_qoverp()->push_back( el.trackcov_z0_qoverp() );
      } else {
         trackcov_z0_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0_theta.IsAvailable() ) {
         trackcov_z0_theta()->push_back( el.trackcov_z0_theta() );
      } else {
         trackcov_z0_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackd0.IsAvailable() ) {
         trackd0()->push_back( el.trackd0() );
      } else {
         trackd0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackd0beam.IsAvailable() ) {
         trackd0beam()->push_back( el.trackd0beam() );
      } else {
         trackd0beam()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackd0pv.IsAvailable() ) {
         trackd0pv()->push_back( el.trackd0pv() );
      } else {
         trackd0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackd0pvunbiased.IsAvailable() ) {
         trackd0pvunbiased()->push_back( el.trackd0pvunbiased() );
      } else {
         trackd0pvunbiased()->push_back( std::numeric_limits< float >::min() );
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
      if( el.trackphi.IsAvailable() ) {
         trackphi()->push_back( el.trackphi() );
      } else {
         trackphi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackqoverp.IsAvailable() ) {
         trackqoverp()->push_back( el.trackqoverp() );
      } else {
         trackqoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigd0beam.IsAvailable() ) {
         tracksigd0beam()->push_back( el.tracksigd0beam() );
      } else {
         tracksigd0beam()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigd0pv.IsAvailable() ) {
         tracksigd0pv()->push_back( el.tracksigd0pv() );
      } else {
         tracksigd0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigd0pvunbiased.IsAvailable() ) {
         tracksigd0pvunbiased()->push_back( el.tracksigd0pvunbiased() );
      } else {
         tracksigd0pvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigz0beam.IsAvailable() ) {
         tracksigz0beam()->push_back( el.tracksigz0beam() );
      } else {
         tracksigz0beam()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigz0pv.IsAvailable() ) {
         tracksigz0pv()->push_back( el.tracksigz0pv() );
      } else {
         tracksigz0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigz0pvunbiased.IsAvailable() ) {
         tracksigz0pvunbiased()->push_back( el.tracksigz0pvunbiased() );
      } else {
         tracksigz0pvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracktheta.IsAvailable() ) {
         tracktheta()->push_back( el.tracktheta() );
      } else {
         tracktheta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0.IsAvailable() ) {
         trackz0()->push_back( el.trackz0() );
      } else {
         trackz0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0beam.IsAvailable() ) {
         trackz0beam()->push_back( el.trackz0beam() );
      } else {
         trackz0beam()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0pv.IsAvailable() ) {
         trackz0pv()->push_back( el.trackz0pv() );
      } else {
         trackz0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0pvunbiased.IsAvailable() ) {
         trackz0pvunbiased()->push_back( el.trackz0pvunbiased() );
      } else {
         trackz0pvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_E.IsAvailable() ) {
         truth_E()->push_back( el.truth_E() );
      } else {
         truth_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_barcode.IsAvailable() ) {
         truth_barcode()->push_back( el.truth_barcode() );
      } else {
         truth_barcode()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_dr.IsAvailable() ) {
         truth_dr()->push_back( el.truth_dr() );
      } else {
         truth_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_eta.IsAvailable() ) {
         truth_eta()->push_back( el.truth_eta() );
      } else {
         truth_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_matched.IsAvailable() ) {
         truth_matched()->push_back( el.truth_matched() );
      } else {
         truth_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_motherbarcode.IsAvailable() ) {
         truth_motherbarcode()->push_back( el.truth_motherbarcode() );
      } else {
         truth_motherbarcode()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_mothertype.IsAvailable() ) {
         truth_mothertype()->push_back( el.truth_mothertype() );
      } else {
         truth_mothertype()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_phi.IsAvailable() ) {
         truth_phi()->push_back( el.truth_phi() );
      } else {
         truth_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_pt.IsAvailable() ) {
         truth_pt()->push_back( el.truth_pt() );
      } else {
         truth_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_status.IsAvailable() ) {
         truth_status()->push_back( el.truth_status() );
      } else {
         truth_status()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_type.IsAvailable() ) {
         truth_type()->push_back( el.truth_type() );
      } else {
         truth_type()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.type.IsAvailable() ) {
         type()->push_back( el.type() );
      } else {
         type()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.z0_exPV.IsAvailable() ) {
         z0_exPV()->push_back( el.z0_exPV() );
      } else {
         z0_exPV()->push_back( std::numeric_limits< float >::min() );
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
   MuonD3PDObjectElement& MuonD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new MuonD3PDObjectElement( fProxies.size(), *this ) );
      }
      return *fProxies[ index ];
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
   const MuonD3PDObjectElement& MuonD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new MuonD3PDObjectElement( fProxies.size(), *this ) );
      }
      return *fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   MuonD3PDObject& MuonD3PDObject::operator+=( const MuonD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
