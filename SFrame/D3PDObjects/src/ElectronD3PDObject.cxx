// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/ElectronD3PDObject.h"

ClassImp( D3PDReader::ElectronD3PDObjectElement )
ClassImp( D3PDReader::ElectronD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class ElectronD3PDObject.
    */
   ElectronD3PDObjectElement::ElectronD3PDObjectElement( size_t index, const ElectronD3PDObject& parent )
      : CaloPointing_eta( parent.CaloPointing_eta, index, this ),
        CaloPointing_sigma_eta( parent.CaloPointing_sigma_eta, index, this ),
        CaloPointing_sigma_zvertex( parent.CaloPointing_sigma_zvertex, index, this ),
        CaloPointing_zvertex( parent.CaloPointing_zvertex, index, this ),
        E( parent.E, index, this ),
        E233( parent.E233, index, this ),
        E237( parent.E237, index, this ),
        E277( parent.E277, index, this ),
        ED_Njets( parent.ED_Njets, index, this ),
        ED_median( parent.ED_median, index, this ),
        ED_sigma( parent.ED_sigma, index, this ),
        EF_dr( parent.EF_dr, index, this ),
        EF_index( parent.EF_index, index, this ),
        ES0_real( parent.ES0_real, index, this ),
        ES1_real( parent.ES1_real, index, this ),
        ES2_real( parent.ES2_real, index, this ),
        ES3_real( parent.ES3_real, index, this ),
        E_EMB1( parent.E_EMB1, index, this ),
        E_EMB2( parent.E_EMB2, index, this ),
        E_EMB3( parent.E_EMB3, index, this ),
        E_EME1( parent.E_EME1, index, this ),
        E_EME2( parent.E_EME2, index, this ),
        E_EME3( parent.E_EME3, index, this ),
        E_FCAL0( parent.E_FCAL0, index, this ),
        E_FCAL1( parent.E_FCAL1, index, this ),
        E_FCAL2( parent.E_FCAL2, index, this ),
        E_HEC0( parent.E_HEC0, index, this ),
        E_HEC1( parent.E_HEC1, index, this ),
        E_HEC2( parent.E_HEC2, index, this ),
        E_HEC3( parent.E_HEC3, index, this ),
        E_PreSamplerB( parent.E_PreSamplerB, index, this ),
        E_PreSamplerE( parent.E_PreSamplerE, index, this ),
        E_TileBar0( parent.E_TileBar0, index, this ),
        E_TileBar1( parent.E_TileBar1, index, this ),
        E_TileBar2( parent.E_TileBar2, index, this ),
        E_TileExt0( parent.E_TileExt0, index, this ),
        E_TileExt1( parent.E_TileExt1, index, this ),
        E_TileExt2( parent.E_TileExt2, index, this ),
        E_TileGap1( parent.E_TileGap1, index, this ),
        E_TileGap2( parent.E_TileGap2, index, this ),
        E_TileGap3( parent.E_TileGap3, index, this ),
        EcellS0( parent.EcellS0, index, this ),
        Emax2( parent.Emax2, index, this ),
        Emins1( parent.Emins1, index, this ),
        Es0( parent.Es0, index, this ),
        Es1( parent.Es1, index, this ),
        Es2( parent.Es2, index, this ),
        Es3( parent.Es3, index, this ),
        Et( parent.Et, index, this ),
        Etcone15( parent.Etcone15, index, this ),
        Etcone15_pt_corrected( parent.Etcone15_pt_corrected, index, this ),
        Etcone20( parent.Etcone20, index, this ),
        Etcone20_pt_corrected( parent.Etcone20_pt_corrected, index, this ),
        Etcone25( parent.Etcone25, index, this ),
        Etcone25_pt_corrected( parent.Etcone25_pt_corrected, index, this ),
        Etcone30( parent.Etcone30, index, this ),
        Etcone30_pt_corrected( parent.Etcone30_pt_corrected, index, this ),
        Etcone35( parent.Etcone35, index, this ),
        Etcone35_pt_corrected( parent.Etcone35_pt_corrected, index, this ),
        Etcone40( parent.Etcone40, index, this ),
        Etcone40_ED_corrected( parent.Etcone40_ED_corrected, index, this ),
        Etcone40_corrected( parent.Etcone40_corrected, index, this ),
        Etcone40_pt_corrected( parent.Etcone40_pt_corrected, index, this ),
        Etcone45( parent.Etcone45, index, this ),
        Ethad( parent.Ethad, index, this ),
        Ethad1( parent.Ethad1, index, this ),
        EtringnoisedR03sig2( parent.EtringnoisedR03sig2, index, this ),
        EtringnoisedR03sig3( parent.EtringnoisedR03sig3, index, this ),
        EtringnoisedR03sig4( parent.EtringnoisedR03sig4, index, this ),
        HPV_eta( parent.HPV_eta, index, this ),
        HPV_sigma_eta( parent.HPV_sigma_eta, index, this ),
        HPV_sigma_zvertex( parent.HPV_sigma_zvertex, index, this ),
        HPV_zvertex( parent.HPV_zvertex, index, this ),
        Hmatrix( parent.Hmatrix, index, this ),
        Hmatrix5( parent.Hmatrix5, index, this ),
        OQ( parent.OQ, index, this ),
        Rconv( parent.Rconv, index, this ),
        TRTHighTHitsRatio( parent.TRTHighTHitsRatio, index, this ),
        TRTHighTOutliersRatio( parent.TRTHighTOutliersRatio, index, this ),
        Unrefittedtrack_d0( parent.Unrefittedtrack_d0, index, this ),
        Unrefittedtrack_eta( parent.Unrefittedtrack_eta, index, this ),
        Unrefittedtrack_phi( parent.Unrefittedtrack_phi, index, this ),
        Unrefittedtrack_pt( parent.Unrefittedtrack_pt, index, this ),
        Unrefittedtrack_qoverp( parent.Unrefittedtrack_qoverp, index, this ),
        Unrefittedtrack_theta( parent.Unrefittedtrack_theta, index, this ),
        Unrefittedtrack_z0( parent.Unrefittedtrack_z0, index, this ),
        adaboost( parent.adaboost, index, this ),
        author( parent.author, index, this ),
        calibHitsShowerDepth( parent.calibHitsShowerDepth, index, this ),
        cellmaxfrac( parent.cellmaxfrac, index, this ),
        centerlambda( parent.centerlambda, index, this ),
        charge( parent.charge, index, this ),
        cl_E( parent.cl_E, index, this ),
        cl_eta( parent.cl_eta, index, this ),
        cl_phi( parent.cl_phi, index, this ),
        cl_pt( parent.cl_pt, index, this ),
        convFlag( parent.convFlag, index, this ),
        convanglematch( parent.convanglematch, index, this ),
        convtrackmatch( parent.convtrackmatch, index, this ),
        convtrk1nBLHits( parent.convtrk1nBLHits, index, this ),
        convtrk1nPixHits( parent.convtrk1nPixHits, index, this ),
        convtrk1nSCTHits( parent.convtrk1nSCTHits, index, this ),
        convtrk1nTRTHits( parent.convtrk1nTRTHits, index, this ),
        convtrk2nBLHits( parent.convtrk2nBLHits, index, this ),
        convtrk2nPixHits( parent.convtrk2nPixHits, index, this ),
        convtrk2nSCTHits( parent.convtrk2nSCTHits, index, this ),
        convtrk2nTRTHits( parent.convtrk2nTRTHits, index, this ),
        convvtxchi2( parent.convvtxchi2, index, this ),
        convvtxx( parent.convvtxx, index, this ),
        convvtxy( parent.convvtxy, index, this ),
        convvtxz( parent.convvtxz, index, this ),
        deltaEmax2( parent.deltaEmax2, index, this ),
        deltaEs( parent.deltaEs, index, this ),
        deltaPhiFromLast( parent.deltaPhiFromLast, index, this ),
        deltaPhiRot( parent.deltaPhiRot, index, this ),
        deltaeta1( parent.deltaeta1, index, this ),
        deltaeta2( parent.deltaeta2, index, this ),
        deltaphi2( parent.deltaphi2, index, this ),
        deltaphiRescaled( parent.deltaphiRescaled, index, this ),
        depth( parent.depth, index, this ),
        eProbabilityBrem( parent.eProbabilityBrem, index, this ),
        eProbabilityComb( parent.eProbabilityComb, index, this ),
        eProbabilityHT( parent.eProbabilityHT, index, this ),
        eProbabilityToT( parent.eProbabilityToT, index, this ),
        electronbgweight( parent.electronbgweight, index, this ),
        electronweight( parent.electronweight, index, this ),
        emaxs1( parent.emaxs1, index, this ),
        errz( parent.errz, index, this ),
        eta( parent.eta, index, this ),
        etaSampling1( parent.etaSampling1, index, this ),
        etacellS0( parent.etacellS0, index, this ),
        etacorrmag( parent.etacorrmag, index, this ),
        etap( parent.etap, index, this ),
        etas0( parent.etas0, index, this ),
        etas1( parent.etas1, index, this ),
        etas2( parent.etas2, index, this ),
        etas3( parent.etas3, index, this ),
        expectBLayerHit( parent.expectBLayerHit, index, this ),
        expectHitInBLayer( parent.expectHitInBLayer, index, this ),
        f1( parent.f1, index, this ),
        f1core( parent.f1core, index, this ),
        f3( parent.f3, index, this ),
        f3core( parent.f3core, index, this ),
        firstEdens( parent.firstEdens, index, this ),
        fside( parent.fside, index, this ),
        goodOQ( parent.goodOQ, index, this ),
        hasconv( parent.hasconv, index, this ),
        hastrack( parent.hastrack, index, this ),
        isConv( parent.isConv, index, this ),
        isEM( parent.isEM, index, this ),
        isEMLoose( parent.isEMLoose, index, this ),
        isEMMedium( parent.isEMMedium, index, this ),
        isEMTight( parent.isEMTight, index, this ),
        isIso( parent.isIso, index, this ),
        isolationlikelihoodhqelectrons( parent.isolationlikelihoodhqelectrons, index, this ),
        isolationlikelihoodjets( parent.isolationlikelihoodjets, index, this ),
        jet_E( parent.jet_E, index, this ),
        jet_dr( parent.jet_dr, index, this ),
        jet_eta( parent.jet_eta, index, this ),
        jet_m( parent.jet_m, index, this ),
        jet_matched( parent.jet_matched, index, this ),
        jet_phi( parent.jet_phi, index, this ),
        jet_pt( parent.jet_pt, index, this ),
        jet_truth_E( parent.jet_truth_E, index, this ),
        jet_truth_dr( parent.jet_truth_dr, index, this ),
        jet_truth_eta( parent.jet_truth_eta, index, this ),
        jet_truth_m( parent.jet_truth_m, index, this ),
        jet_truth_matched( parent.jet_truth_matched, index, this ),
        jet_truth_phi( parent.jet_truth_phi, index, this ),
        jet_truth_pt( parent.jet_truth_pt, index, this ),
        lateral( parent.lateral, index, this ),
        likelihoodsPixeldEdx( parent.likelihoodsPixeldEdx, index, this ),
        longitudinal( parent.longitudinal, index, this ),
        loose( parent.loose, index, this ),
        looseIso( parent.looseIso, index, this ),
        loosePP( parent.loosePP, index, this ),
        loosePPIso( parent.loosePPIso, index, this ),
        m( parent.m, index, this ),
        massPixeldEdx( parent.massPixeldEdx, index, this ),
        medium( parent.medium, index, this ),
        mediumIso( parent.mediumIso, index, this ),
        mediumIsoWithoutTrack( parent.mediumIsoWithoutTrack, index, this ),
        mediumPP( parent.mediumPP, index, this ),
        mediumPPIso( parent.mediumPPIso, index, this ),
        mediumWithoutTrack( parent.mediumWithoutTrack, index, this ),
        mvaptcone20( parent.mvaptcone20, index, this ),
        mvaptcone30( parent.mvaptcone30, index, this ),
        mvaptcone40( parent.mvaptcone40, index, this ),
        nBLHits( parent.nBLHits, index, this ),
        nBLSharedHits( parent.nBLSharedHits, index, this ),
        nBLayerOutliers( parent.nBLayerOutliers, index, this ),
        nBLayerSplitHits( parent.nBLayerSplitHits, index, this ),
        nContribPixelLayers( parent.nContribPixelLayers, index, this ),
        nConv( parent.nConv, index, this ),
        nDoubleTrackConv( parent.nDoubleTrackConv, index, this ),
        nGangedFlaggedFakes( parent.nGangedFlaggedFakes, index, this ),
        nGangedPixels( parent.nGangedPixels, index, this ),
        nGoodHitsPixeldEdx( parent.nGoodHitsPixeldEdx, index, this ),
        nPixHits( parent.nPixHits, index, this ),
        nPixHoles( parent.nPixHoles, index, this ),
        nPixSharedHits( parent.nPixSharedHits, index, this ),
        nPixSplitHits( parent.nPixSplitHits, index, this ),
        nPixelDeadSensors( parent.nPixelDeadSensors, index, this ),
        nPixelOutliers( parent.nPixelOutliers, index, this ),
        nPixelSpoiltHits( parent.nPixelSpoiltHits, index, this ),
        nSCTDeadSensors( parent.nSCTDeadSensors, index, this ),
        nSCTDoubleHoles( parent.nSCTDoubleHoles, index, this ),
        nSCTHits( parent.nSCTHits, index, this ),
        nSCTHoles( parent.nSCTHoles, index, this ),
        nSCTOutliers( parent.nSCTOutliers, index, this ),
        nSCTSharedHits( parent.nSCTSharedHits, index, this ),
        nSCTSpoiltHits( parent.nSCTSpoiltHits, index, this ),
        nSiHits( parent.nSiHits, index, this ),
        nSingleTrackConv( parent.nSingleTrackConv, index, this ),
        nTRTHighTHits( parent.nTRTHighTHits, index, this ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers, index, this ),
        nTRTHits( parent.nTRTHits, index, this ),
        nTRTHoles( parent.nTRTHoles, index, this ),
        nTRTOutliers( parent.nTRTOutliers, index, this ),
        neuralnet( parent.neuralnet, index, this ),
        nucone20( parent.nucone20, index, this ),
        nucone30( parent.nucone30, index, this ),
        nucone40( parent.nucone40, index, this ),
        origin( parent.origin, index, this ),
        originbkg( parent.originbkg, index, this ),
        phi( parent.phi, index, this ),
        phis0( parent.phis0, index, this ),
        phis1( parent.phis1, index, this ),
        phis2( parent.phis2, index, this ),
        phis3( parent.phis3, index, this ),
        pixeldEdx( parent.pixeldEdx, index, this ),
        pos7( parent.pos7, index, this ),
        pt( parent.pt, index, this ),
        pt1conv( parent.pt1conv, index, this ),
        pt2conv( parent.pt2conv, index, this ),
        ptcone20( parent.ptcone20, index, this ),
        ptcone30( parent.ptcone30, index, this ),
        ptcone40( parent.ptcone40, index, this ),
        ptconv( parent.ptconv, index, this ),
        px( parent.px, index, this ),
        py( parent.py, index, this ),
        pz( parent.pz, index, this ),
        pzconv( parent.pzconv, index, this ),
        rawcl_E( parent.rawcl_E, index, this ),
        rawcl_Es0( parent.rawcl_Es0, index, this ),
        rawcl_Es1( parent.rawcl_Es1, index, this ),
        rawcl_Es2( parent.rawcl_Es2, index, this ),
        rawcl_Es3( parent.rawcl_Es3, index, this ),
        rawcl_eta( parent.rawcl_eta, index, this ),
        rawcl_etas0( parent.rawcl_etas0, index, this ),
        rawcl_etas1( parent.rawcl_etas1, index, this ),
        rawcl_etas2( parent.rawcl_etas2, index, this ),
        rawcl_etas3( parent.rawcl_etas3, index, this ),
        rawcl_phi( parent.rawcl_phi, index, this ),
        rawcl_phis0( parent.rawcl_phis0, index, this ),
        rawcl_phis1( parent.rawcl_phis1, index, this ),
        rawcl_phis2( parent.rawcl_phis2, index, this ),
        rawcl_phis3( parent.rawcl_phis3, index, this ),
        rawcl_pt( parent.rawcl_pt, index, this ),
        cl_etaCalo( parent.cl_etaCalo, index, this ),
        cl_phiCalo( parent.cl_phiCalo, index, this ),
        refittedTrack_LMqoverp( parent.refittedTrack_LMqoverp, index, this ),
        refittedTrack_author( parent.refittedTrack_author, index, this ),
        refittedTrack_bremFitStatus( parent.refittedTrack_bremFitStatus, index, this ),
        refittedTrack_bremRadius( parent.refittedTrack_bremRadius, index, this ),
        refittedTrack_bremRadiusErr( parent.refittedTrack_bremRadiusErr, index, this ),
        refittedTrack_bremZ( parent.refittedTrack_bremZ, index, this ),
        refittedTrack_bremZErr( parent.refittedTrack_bremZErr, index, this ),
        refittedTrack_chi2( parent.refittedTrack_chi2, index, this ),
        refittedTrack_covd0( parent.refittedTrack_covd0, index, this ),
        refittedTrack_covd0phi( parent.refittedTrack_covd0phi, index, this ),
        refittedTrack_covd0qoverp( parent.refittedTrack_covd0qoverp, index, this ),
        refittedTrack_covd0theta( parent.refittedTrack_covd0theta, index, this ),
        refittedTrack_covd0z0( parent.refittedTrack_covd0z0, index, this ),
        refittedTrack_covphi( parent.refittedTrack_covphi, index, this ),
        refittedTrack_covphiqoverp( parent.refittedTrack_covphiqoverp, index, this ),
        refittedTrack_covphitheta( parent.refittedTrack_covphitheta, index, this ),
        refittedTrack_covqoverp( parent.refittedTrack_covqoverp, index, this ),
        refittedTrack_covtheta( parent.refittedTrack_covtheta, index, this ),
        refittedTrack_covthetaqoverp( parent.refittedTrack_covthetaqoverp, index, this ),
        refittedTrack_covz0( parent.refittedTrack_covz0, index, this ),
        refittedTrack_covz0phi( parent.refittedTrack_covz0phi, index, this ),
        refittedTrack_covz0qoverp( parent.refittedTrack_covz0qoverp, index, this ),
        refittedTrack_covz0theta( parent.refittedTrack_covz0theta, index, this ),
        refittedTrack_d0( parent.refittedTrack_d0, index, this ),
        refittedTrack_hasBrem( parent.refittedTrack_hasBrem, index, this ),
        refittedTrack_n( parent.refittedTrack_n, index, this ),
        refittedTrack_phi( parent.refittedTrack_phi, index, this ),
        refittedTrack_qoverp( parent.refittedTrack_qoverp, index, this ),
        refittedTrack_theta( parent.refittedTrack_theta, index, this ),
        refittedTrack_z0( parent.refittedTrack_z0, index, this ),
        reta( parent.reta, index, this ),
        ringernn( parent.ringernn, index, this ),
        rings_E( parent.rings_E, index, this ),
        rphi( parent.rphi, index, this ),
        rphiallcalo( parent.rphiallcalo, index, this ),
        secondR( parent.secondR, index, this ),
        secondlambda( parent.secondlambda, index, this ),
        softebgweight( parent.softebgweight, index, this ),
        softeneuralnet( parent.softeneuralnet, index, this ),
        softeweight( parent.softeweight, index, this ),
        tight( parent.tight, index, this ),
        tightIso( parent.tightIso, index, this ),
        tightIsoWithoutTrack( parent.tightIsoWithoutTrack, index, this ),
        tightPP( parent.tightPP, index, this ),
        tightPPIso( parent.tightPPIso, index, this ),
        tightWithoutTrack( parent.tightWithoutTrack, index, this ),
        topoEtcone20( parent.topoEtcone20, index, this ),
        topoEtcone20_corrected( parent.topoEtcone20_corrected, index, this ),
        topoEtcone30( parent.topoEtcone30, index, this ),
        topoEtcone30_corrected( parent.topoEtcone30_corrected, index, this ),
        topoEtcone40( parent.topoEtcone40, index, this ),
        topoEtcone40_corrected( parent.topoEtcone40_corrected, index, this ),
        topoEtcone60( parent.topoEtcone60, index, this ),
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
        trackd0_physics( parent.trackd0_physics, index, this ),
        trackd0beam( parent.trackd0beam, index, this ),
        trackd0pv( parent.trackd0pv, index, this ),
        trackd0pvunbiased( parent.trackd0pvunbiased, index, this ),
        tracketa( parent.tracketa, index, this ),
        trackfitchi2( parent.trackfitchi2, index, this ),
        trackfitndof( parent.trackfitndof, index, this ),
        trackphi( parent.trackphi, index, this ),
        trackpt( parent.trackpt, index, this ),
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
        truth_bremLoc( parent.truth_bremLoc, index, this ),
        truth_bremSi( parent.truth_bremSi, index, this ),
        truth_eta( parent.truth_eta, index, this ),
        truth_hasHardBrem( parent.truth_hasHardBrem, index, this ),
        truth_index( parent.truth_index, index, this ),
        truth_matched( parent.truth_matched, index, this ),
        truth_motherbarcode( parent.truth_motherbarcode, index, this ),
        truth_mothertype( parent.truth_mothertype, index, this ),
        truth_phi( parent.truth_phi, index, this ),
        truth_pt( parent.truth_pt, index, this ),
        truth_status( parent.truth_status, index, this ),
        truth_sumbrem( parent.truth_sumbrem, index, this ),
        truth_type( parent.truth_type, index, this ),
        type( parent.type, index, this ),
        typebkg( parent.typebkg, index, this ),
        vertweight( parent.vertweight, index, this ),
        vertx( parent.vertx, index, this ),
        verty( parent.verty, index, this ),
        vertz( parent.vertz, index, this ),
        weta2( parent.weta2, index, this ),
        ws3( parent.ws3, index, this ),
        wstot( parent.wstot, index, this ),
        zconv( parent.zconv, index, this ),
        zvertex( parent.zvertex, index, this ),
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
   ElectronD3PDObjectElement::ElectronD3PDObjectElement( const ElectronD3PDObjectElement& parent )
      : TObject( parent ),
        CaloPointing_eta( parent.CaloPointing_eta ),
        CaloPointing_sigma_eta( parent.CaloPointing_sigma_eta ),
        CaloPointing_sigma_zvertex( parent.CaloPointing_sigma_zvertex ),
        CaloPointing_zvertex( parent.CaloPointing_zvertex ),
        E( parent.E ),
        E233( parent.E233 ),
        E237( parent.E237 ),
        E277( parent.E277 ),
        ED_Njets( parent.ED_Njets ),
        ED_median( parent.ED_median ),
        ED_sigma( parent.ED_sigma ),
        EF_dr( parent.EF_dr ),
        EF_index( parent.EF_index ),
        ES0_real( parent.ES0_real ),
        ES1_real( parent.ES1_real ),
        ES2_real( parent.ES2_real ),
        ES3_real( parent.ES3_real ),
        E_EMB1( parent.E_EMB1 ),
        E_EMB2( parent.E_EMB2 ),
        E_EMB3( parent.E_EMB3 ),
        E_EME1( parent.E_EME1 ),
        E_EME2( parent.E_EME2 ),
        E_EME3( parent.E_EME3 ),
        E_FCAL0( parent.E_FCAL0 ),
        E_FCAL1( parent.E_FCAL1 ),
        E_FCAL2( parent.E_FCAL2 ),
        E_HEC0( parent.E_HEC0 ),
        E_HEC1( parent.E_HEC1 ),
        E_HEC2( parent.E_HEC2 ),
        E_HEC3( parent.E_HEC3 ),
        E_PreSamplerB( parent.E_PreSamplerB ),
        E_PreSamplerE( parent.E_PreSamplerE ),
        E_TileBar0( parent.E_TileBar0 ),
        E_TileBar1( parent.E_TileBar1 ),
        E_TileBar2( parent.E_TileBar2 ),
        E_TileExt0( parent.E_TileExt0 ),
        E_TileExt1( parent.E_TileExt1 ),
        E_TileExt2( parent.E_TileExt2 ),
        E_TileGap1( parent.E_TileGap1 ),
        E_TileGap2( parent.E_TileGap2 ),
        E_TileGap3( parent.E_TileGap3 ),
        EcellS0( parent.EcellS0 ),
        Emax2( parent.Emax2 ),
        Emins1( parent.Emins1 ),
        Es0( parent.Es0 ),
        Es1( parent.Es1 ),
        Es2( parent.Es2 ),
        Es3( parent.Es3 ),
        Et( parent.Et ),
        Etcone15( parent.Etcone15 ),
        Etcone15_pt_corrected( parent.Etcone15_pt_corrected ),
        Etcone20( parent.Etcone20 ),
        Etcone20_pt_corrected( parent.Etcone20_pt_corrected ),
        Etcone25( parent.Etcone25 ),
        Etcone25_pt_corrected( parent.Etcone25_pt_corrected ),
        Etcone30( parent.Etcone30 ),
        Etcone30_pt_corrected( parent.Etcone30_pt_corrected ),
        Etcone35( parent.Etcone35 ),
        Etcone35_pt_corrected( parent.Etcone35_pt_corrected ),
        Etcone40( parent.Etcone40 ),
        Etcone40_ED_corrected( parent.Etcone40_ED_corrected ),
        Etcone40_corrected( parent.Etcone40_corrected ),
        Etcone40_pt_corrected( parent.Etcone40_pt_corrected ),
        Etcone45( parent.Etcone45 ),
        Ethad( parent.Ethad ),
        Ethad1( parent.Ethad1 ),
        EtringnoisedR03sig2( parent.EtringnoisedR03sig2 ),
        EtringnoisedR03sig3( parent.EtringnoisedR03sig3 ),
        EtringnoisedR03sig4( parent.EtringnoisedR03sig4 ),
        HPV_eta( parent.HPV_eta ),
        HPV_sigma_eta( parent.HPV_sigma_eta ),
        HPV_sigma_zvertex( parent.HPV_sigma_zvertex ),
        HPV_zvertex( parent.HPV_zvertex ),
        Hmatrix( parent.Hmatrix ),
        Hmatrix5( parent.Hmatrix5 ),
        OQ( parent.OQ ),
        Rconv( parent.Rconv ),
        TRTHighTHitsRatio( parent.TRTHighTHitsRatio ),
        TRTHighTOutliersRatio( parent.TRTHighTOutliersRatio ),
        Unrefittedtrack_d0( parent.Unrefittedtrack_d0 ),
        Unrefittedtrack_eta( parent.Unrefittedtrack_eta ),
        Unrefittedtrack_phi( parent.Unrefittedtrack_phi ),
        Unrefittedtrack_pt( parent.Unrefittedtrack_pt ),
        Unrefittedtrack_qoverp( parent.Unrefittedtrack_qoverp ),
        Unrefittedtrack_theta( parent.Unrefittedtrack_theta ),
        Unrefittedtrack_z0( parent.Unrefittedtrack_z0 ),
        adaboost( parent.adaboost ),
        author( parent.author ),
        calibHitsShowerDepth( parent.calibHitsShowerDepth ),
        cellmaxfrac( parent.cellmaxfrac ),
        centerlambda( parent.centerlambda ),
        charge( parent.charge ),
        cl_E( parent.cl_E ),
        cl_eta( parent.cl_eta ),
        cl_phi( parent.cl_phi ),
        cl_pt( parent.cl_pt ),
        convFlag( parent.convFlag ),
        convanglematch( parent.convanglematch ),
        convtrackmatch( parent.convtrackmatch ),
        convtrk1nBLHits( parent.convtrk1nBLHits ),
        convtrk1nPixHits( parent.convtrk1nPixHits ),
        convtrk1nSCTHits( parent.convtrk1nSCTHits ),
        convtrk1nTRTHits( parent.convtrk1nTRTHits ),
        convtrk2nBLHits( parent.convtrk2nBLHits ),
        convtrk2nPixHits( parent.convtrk2nPixHits ),
        convtrk2nSCTHits( parent.convtrk2nSCTHits ),
        convtrk2nTRTHits( parent.convtrk2nTRTHits ),
        convvtxchi2( parent.convvtxchi2 ),
        convvtxx( parent.convvtxx ),
        convvtxy( parent.convvtxy ),
        convvtxz( parent.convvtxz ),
        deltaEmax2( parent.deltaEmax2 ),
        deltaEs( parent.deltaEs ),
        deltaPhiFromLast( parent.deltaPhiFromLast ),
        deltaPhiRot( parent.deltaPhiRot ),
        deltaeta1( parent.deltaeta1 ),
        deltaeta2( parent.deltaeta2 ),
        deltaphi2( parent.deltaphi2 ),
        deltaphiRescaled( parent.deltaphiRescaled ),
        depth( parent.depth ),
        eProbabilityBrem( parent.eProbabilityBrem ),
        eProbabilityComb( parent.eProbabilityComb ),
        eProbabilityHT( parent.eProbabilityHT ),
        eProbabilityToT( parent.eProbabilityToT ),
        electronbgweight( parent.electronbgweight ),
        electronweight( parent.electronweight ),
        emaxs1( parent.emaxs1 ),
        errz( parent.errz ),
        eta( parent.eta ),
        etaSampling1( parent.etaSampling1 ),
        etacellS0( parent.etacellS0 ),
        etacorrmag( parent.etacorrmag ),
        etap( parent.etap ),
        etas0( parent.etas0 ),
        etas1( parent.etas1 ),
        etas2( parent.etas2 ),
        etas3( parent.etas3 ),
        expectBLayerHit( parent.expectBLayerHit ),
        expectHitInBLayer( parent.expectHitInBLayer ),
        f1( parent.f1 ),
        f1core( parent.f1core ),
        f3( parent.f3 ),
        f3core( parent.f3core ),
        firstEdens( parent.firstEdens ),
        fside( parent.fside ),
        goodOQ( parent.goodOQ ),
        hasconv( parent.hasconv ),
        hastrack( parent.hastrack ),
        isConv( parent.isConv ),
        isEM( parent.isEM ),
        isEMLoose( parent.isEMLoose ),
        isEMMedium( parent.isEMMedium ),
        isEMTight( parent.isEMTight ),
        isIso( parent.isIso ),
        isolationlikelihoodhqelectrons( parent.isolationlikelihoodhqelectrons ),
        isolationlikelihoodjets( parent.isolationlikelihoodjets ),
        jet_E( parent.jet_E ),
        jet_dr( parent.jet_dr ),
        jet_eta( parent.jet_eta ),
        jet_m( parent.jet_m ),
        jet_matched( parent.jet_matched ),
        jet_phi( parent.jet_phi ),
        jet_pt( parent.jet_pt ),
        jet_truth_E( parent.jet_truth_E ),
        jet_truth_dr( parent.jet_truth_dr ),
        jet_truth_eta( parent.jet_truth_eta ),
        jet_truth_m( parent.jet_truth_m ),
        jet_truth_matched( parent.jet_truth_matched ),
        jet_truth_phi( parent.jet_truth_phi ),
        jet_truth_pt( parent.jet_truth_pt ),
        lateral( parent.lateral ),
        likelihoodsPixeldEdx( parent.likelihoodsPixeldEdx ),
        longitudinal( parent.longitudinal ),
        loose( parent.loose ),
        looseIso( parent.looseIso ),
        loosePP( parent.loosePP ),
        loosePPIso( parent.loosePPIso ),
        m( parent.m ),
        massPixeldEdx( parent.massPixeldEdx ),
        medium( parent.medium ),
        mediumIso( parent.mediumIso ),
        mediumIsoWithoutTrack( parent.mediumIsoWithoutTrack ),
        mediumPP( parent.mediumPP ),
        mediumPPIso( parent.mediumPPIso ),
        mediumWithoutTrack( parent.mediumWithoutTrack ),
        mvaptcone20( parent.mvaptcone20 ),
        mvaptcone30( parent.mvaptcone30 ),
        mvaptcone40( parent.mvaptcone40 ),
        nBLHits( parent.nBLHits ),
        nBLSharedHits( parent.nBLSharedHits ),
        nBLayerOutliers( parent.nBLayerOutliers ),
        nBLayerSplitHits( parent.nBLayerSplitHits ),
        nContribPixelLayers( parent.nContribPixelLayers ),
        nConv( parent.nConv ),
        nDoubleTrackConv( parent.nDoubleTrackConv ),
        nGangedFlaggedFakes( parent.nGangedFlaggedFakes ),
        nGangedPixels( parent.nGangedPixels ),
        nGoodHitsPixeldEdx( parent.nGoodHitsPixeldEdx ),
        nPixHits( parent.nPixHits ),
        nPixHoles( parent.nPixHoles ),
        nPixSharedHits( parent.nPixSharedHits ),
        nPixSplitHits( parent.nPixSplitHits ),
        nPixelDeadSensors( parent.nPixelDeadSensors ),
        nPixelOutliers( parent.nPixelOutliers ),
        nPixelSpoiltHits( parent.nPixelSpoiltHits ),
        nSCTDeadSensors( parent.nSCTDeadSensors ),
        nSCTDoubleHoles( parent.nSCTDoubleHoles ),
        nSCTHits( parent.nSCTHits ),
        nSCTHoles( parent.nSCTHoles ),
        nSCTOutliers( parent.nSCTOutliers ),
        nSCTSharedHits( parent.nSCTSharedHits ),
        nSCTSpoiltHits( parent.nSCTSpoiltHits ),
        nSiHits( parent.nSiHits ),
        nSingleTrackConv( parent.nSingleTrackConv ),
        nTRTHighTHits( parent.nTRTHighTHits ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers ),
        nTRTHits( parent.nTRTHits ),
        nTRTHoles( parent.nTRTHoles ),
        nTRTOutliers( parent.nTRTOutliers ),
        neuralnet( parent.neuralnet ),
        nucone20( parent.nucone20 ),
        nucone30( parent.nucone30 ),
        nucone40( parent.nucone40 ),
        origin( parent.origin ),
        originbkg( parent.originbkg ),
        phi( parent.phi ),
        phis0( parent.phis0 ),
        phis1( parent.phis1 ),
        phis2( parent.phis2 ),
        phis3( parent.phis3 ),
        pixeldEdx( parent.pixeldEdx ),
        pos7( parent.pos7 ),
        pt( parent.pt ),
        pt1conv( parent.pt1conv ),
        pt2conv( parent.pt2conv ),
        ptcone20( parent.ptcone20 ),
        ptcone30( parent.ptcone30 ),
        ptcone40( parent.ptcone40 ),
        ptconv( parent.ptconv ),
        px( parent.px ),
        py( parent.py ),
        pz( parent.pz ),
        pzconv( parent.pzconv ),
        rawcl_E( parent.rawcl_E ),
        rawcl_Es0( parent.rawcl_Es0 ),
        rawcl_Es1( parent.rawcl_Es1 ),
        rawcl_Es2( parent.rawcl_Es2 ),
        rawcl_Es3( parent.rawcl_Es3 ),
        rawcl_eta( parent.rawcl_eta ),
        rawcl_etas0( parent.rawcl_etas0 ),
        rawcl_etas1( parent.rawcl_etas1 ),
        rawcl_etas2( parent.rawcl_etas2 ),
        rawcl_etas3( parent.rawcl_etas3 ),
        rawcl_phi( parent.rawcl_phi ),
        rawcl_phis0( parent.rawcl_phis0 ),
        rawcl_phis1( parent.rawcl_phis1 ),
        rawcl_phis2( parent.rawcl_phis2 ),
        rawcl_phis3( parent.rawcl_phis3 ),
        rawcl_pt( parent.rawcl_pt ),
	cl_etaCalo( parent.cl_etaCalo ),
	cl_phiCalo( parent.cl_phiCalo ),
        refittedTrack_LMqoverp( parent.refittedTrack_LMqoverp ),
        refittedTrack_author( parent.refittedTrack_author ),
        refittedTrack_bremFitStatus( parent.refittedTrack_bremFitStatus ),
        refittedTrack_bremRadius( parent.refittedTrack_bremRadius ),
        refittedTrack_bremRadiusErr( parent.refittedTrack_bremRadiusErr ),
        refittedTrack_bremZ( parent.refittedTrack_bremZ ),
        refittedTrack_bremZErr( parent.refittedTrack_bremZErr ),
        refittedTrack_chi2( parent.refittedTrack_chi2 ),
        refittedTrack_covd0( parent.refittedTrack_covd0 ),
        refittedTrack_covd0phi( parent.refittedTrack_covd0phi ),
        refittedTrack_covd0qoverp( parent.refittedTrack_covd0qoverp ),
        refittedTrack_covd0theta( parent.refittedTrack_covd0theta ),
        refittedTrack_covd0z0( parent.refittedTrack_covd0z0 ),
        refittedTrack_covphi( parent.refittedTrack_covphi ),
        refittedTrack_covphiqoverp( parent.refittedTrack_covphiqoverp ),
        refittedTrack_covphitheta( parent.refittedTrack_covphitheta ),
        refittedTrack_covqoverp( parent.refittedTrack_covqoverp ),
        refittedTrack_covtheta( parent.refittedTrack_covtheta ),
        refittedTrack_covthetaqoverp( parent.refittedTrack_covthetaqoverp ),
        refittedTrack_covz0( parent.refittedTrack_covz0 ),
        refittedTrack_covz0phi( parent.refittedTrack_covz0phi ),
        refittedTrack_covz0qoverp( parent.refittedTrack_covz0qoverp ),
        refittedTrack_covz0theta( parent.refittedTrack_covz0theta ),
        refittedTrack_d0( parent.refittedTrack_d0 ),
        refittedTrack_hasBrem( parent.refittedTrack_hasBrem ),
        refittedTrack_n( parent.refittedTrack_n ),
        refittedTrack_phi( parent.refittedTrack_phi ),
        refittedTrack_qoverp( parent.refittedTrack_qoverp ),
        refittedTrack_theta( parent.refittedTrack_theta ),
        refittedTrack_z0( parent.refittedTrack_z0 ),
        reta( parent.reta ),
        ringernn( parent.ringernn ),
        rings_E( parent.rings_E ),
        rphi( parent.rphi ),
        rphiallcalo( parent.rphiallcalo ),
        secondR( parent.secondR ),
        secondlambda( parent.secondlambda ),
        softebgweight( parent.softebgweight ),
        softeneuralnet( parent.softeneuralnet ),
        softeweight( parent.softeweight ),
        tight( parent.tight ),
        tightIso( parent.tightIso ),
        tightIsoWithoutTrack( parent.tightIsoWithoutTrack ),
        tightPP( parent.tightPP ),
        tightPPIso( parent.tightPPIso ),
        tightWithoutTrack( parent.tightWithoutTrack ),
        topoEtcone20( parent.topoEtcone20 ),
        topoEtcone20_corrected( parent.topoEtcone20_corrected ),
        topoEtcone30( parent.topoEtcone30 ),
        topoEtcone30_corrected( parent.topoEtcone30_corrected ),
        topoEtcone40( parent.topoEtcone40 ),
        topoEtcone40_corrected( parent.topoEtcone40_corrected ),
        topoEtcone60( parent.topoEtcone60 ),
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
        trackd0_physics( parent.trackd0_physics ),
        trackd0beam( parent.trackd0beam ),
        trackd0pv( parent.trackd0pv ),
        trackd0pvunbiased( parent.trackd0pvunbiased ),
        tracketa( parent.tracketa ),
        trackfitchi2( parent.trackfitchi2 ),
        trackfitndof( parent.trackfitndof ),
        trackphi( parent.trackphi ),
        trackpt( parent.trackpt ),
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
        truth_bremLoc( parent.truth_bremLoc ),
        truth_bremSi( parent.truth_bremSi ),
        truth_eta( parent.truth_eta ),
        truth_hasHardBrem( parent.truth_hasHardBrem ),
        truth_index( parent.truth_index ),
        truth_matched( parent.truth_matched ),
        truth_motherbarcode( parent.truth_motherbarcode ),
        truth_mothertype( parent.truth_mothertype ),
        truth_phi( parent.truth_phi ),
        truth_pt( parent.truth_pt ),
        truth_status( parent.truth_status ),
        truth_sumbrem( parent.truth_sumbrem ),
        truth_type( parent.truth_type ),
        type( parent.type ),
        typebkg( parent.typebkg ),
        vertweight( parent.vertweight ),
        vertx( parent.vertx ),
        verty( parent.verty ),
        vertz( parent.vertz ),
        weta2( parent.weta2 ),
        ws3( parent.ws3 ),
        wstot( parent.wstot ),
        zconv( parent.zconv ),
        zvertex( parent.zvertex ),
        fParent( parent.fParent ), fIndex( parent.fIndex ) {

   }

   /**
    * This function can be used to access the parent object of this
    * proxy object. It can come in handy when optimizing an analysis code.
    *
    * @returns A reference to this object's parent
    */
   const ElectronD3PDObject* ElectronD3PDObjectElement::GetParent() const {

      return fParent;
   }

   /**
    * This function can be used to access the index of this proxy object
    * inside the parent container. It can come in handy when optimizing an
    * analysis code.
    *
    * @returns The index of the proxy in the object's parent
    */
   size_t ElectronD3PDObjectElement::GetIndex() const {

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
   ElectronD3PDObject::ElectronD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "CaloPointing_eta" ] = &CaloPointing_eta;
      fHandles[ "CaloPointing_sigma_eta" ] = &CaloPointing_sigma_eta;
      fHandles[ "CaloPointing_sigma_zvertex" ] = &CaloPointing_sigma_zvertex;
      fHandles[ "CaloPointing_zvertex" ] = &CaloPointing_zvertex;
      fHandles[ "E" ] = &E;
      fHandles[ "E233" ] = &E233;
      fHandles[ "E237" ] = &E237;
      fHandles[ "E277" ] = &E277;
      fHandles[ "ED_Njets" ] = &ED_Njets;
      fHandles[ "ED_median" ] = &ED_median;
      fHandles[ "ED_sigma" ] = &ED_sigma;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_index" ] = &EF_index;
      fHandles[ "ES0_real" ] = &ES0_real;
      fHandles[ "ES1_real" ] = &ES1_real;
      fHandles[ "ES2_real" ] = &ES2_real;
      fHandles[ "ES3_real" ] = &ES3_real;
      fHandles[ "E_EMB1" ] = &E_EMB1;
      fHandles[ "E_EMB2" ] = &E_EMB2;
      fHandles[ "E_EMB3" ] = &E_EMB3;
      fHandles[ "E_EME1" ] = &E_EME1;
      fHandles[ "E_EME2" ] = &E_EME2;
      fHandles[ "E_EME3" ] = &E_EME3;
      fHandles[ "E_FCAL0" ] = &E_FCAL0;
      fHandles[ "E_FCAL1" ] = &E_FCAL1;
      fHandles[ "E_FCAL2" ] = &E_FCAL2;
      fHandles[ "E_HEC0" ] = &E_HEC0;
      fHandles[ "E_HEC1" ] = &E_HEC1;
      fHandles[ "E_HEC2" ] = &E_HEC2;
      fHandles[ "E_HEC3" ] = &E_HEC3;
      fHandles[ "E_PreSamplerB" ] = &E_PreSamplerB;
      fHandles[ "E_PreSamplerE" ] = &E_PreSamplerE;
      fHandles[ "E_TileBar0" ] = &E_TileBar0;
      fHandles[ "E_TileBar1" ] = &E_TileBar1;
      fHandles[ "E_TileBar2" ] = &E_TileBar2;
      fHandles[ "E_TileExt0" ] = &E_TileExt0;
      fHandles[ "E_TileExt1" ] = &E_TileExt1;
      fHandles[ "E_TileExt2" ] = &E_TileExt2;
      fHandles[ "E_TileGap1" ] = &E_TileGap1;
      fHandles[ "E_TileGap2" ] = &E_TileGap2;
      fHandles[ "E_TileGap3" ] = &E_TileGap3;
      fHandles[ "EcellS0" ] = &EcellS0;
      fHandles[ "Emax2" ] = &Emax2;
      fHandles[ "Emins1" ] = &Emins1;
      fHandles[ "Es0" ] = &Es0;
      fHandles[ "Es1" ] = &Es1;
      fHandles[ "Es2" ] = &Es2;
      fHandles[ "Es3" ] = &Es3;
      fHandles[ "Et" ] = &Et;
      fHandles[ "Etcone15" ] = &Etcone15;
      fHandles[ "Etcone15_pt_corrected" ] = &Etcone15_pt_corrected;
      fHandles[ "Etcone20" ] = &Etcone20;
      fHandles[ "Etcone20_pt_corrected" ] = &Etcone20_pt_corrected;
      fHandles[ "Etcone25" ] = &Etcone25;
      fHandles[ "Etcone25_pt_corrected" ] = &Etcone25_pt_corrected;
      fHandles[ "Etcone30" ] = &Etcone30;
      fHandles[ "Etcone30_pt_corrected" ] = &Etcone30_pt_corrected;
      fHandles[ "Etcone35" ] = &Etcone35;
      fHandles[ "Etcone35_pt_corrected" ] = &Etcone35_pt_corrected;
      fHandles[ "Etcone40" ] = &Etcone40;
      fHandles[ "Etcone40_ED_corrected" ] = &Etcone40_ED_corrected;
      fHandles[ "Etcone40_corrected" ] = &Etcone40_corrected;
      fHandles[ "Etcone40_pt_corrected" ] = &Etcone40_pt_corrected;
      fHandles[ "Etcone45" ] = &Etcone45;
      fHandles[ "Ethad" ] = &Ethad;
      fHandles[ "Ethad1" ] = &Ethad1;
      fHandles[ "EtringnoisedR03sig2" ] = &EtringnoisedR03sig2;
      fHandles[ "EtringnoisedR03sig3" ] = &EtringnoisedR03sig3;
      fHandles[ "EtringnoisedR03sig4" ] = &EtringnoisedR03sig4;
      fHandles[ "HPV_eta" ] = &HPV_eta;
      fHandles[ "HPV_sigma_eta" ] = &HPV_sigma_eta;
      fHandles[ "HPV_sigma_zvertex" ] = &HPV_sigma_zvertex;
      fHandles[ "HPV_zvertex" ] = &HPV_zvertex;
      fHandles[ "Hmatrix" ] = &Hmatrix;
      fHandles[ "Hmatrix5" ] = &Hmatrix5;
      fHandles[ "OQ" ] = &OQ;
      fHandles[ "Rconv" ] = &Rconv;
      fHandles[ "TRTHighTHitsRatio" ] = &TRTHighTHitsRatio;
      fHandles[ "TRTHighTOutliersRatio" ] = &TRTHighTOutliersRatio;
      fHandles[ "Unrefittedtrack_d0" ] = &Unrefittedtrack_d0;
      fHandles[ "Unrefittedtrack_eta" ] = &Unrefittedtrack_eta;
      fHandles[ "Unrefittedtrack_phi" ] = &Unrefittedtrack_phi;
      fHandles[ "Unrefittedtrack_pt" ] = &Unrefittedtrack_pt;
      fHandles[ "Unrefittedtrack_qoverp" ] = &Unrefittedtrack_qoverp;
      fHandles[ "Unrefittedtrack_theta" ] = &Unrefittedtrack_theta;
      fHandles[ "Unrefittedtrack_z0" ] = &Unrefittedtrack_z0;
      fHandles[ "adaboost" ] = &adaboost;
      fHandles[ "author" ] = &author;
      fHandles[ "calibHitsShowerDepth" ] = &calibHitsShowerDepth;
      fHandles[ "cellmaxfrac" ] = &cellmaxfrac;
      fHandles[ "centerlambda" ] = &centerlambda;
      fHandles[ "charge" ] = &charge;
      fHandles[ "cl_E" ] = &cl_E;
      fHandles[ "cl_eta" ] = &cl_eta;
      fHandles[ "cl_phi" ] = &cl_phi;
      fHandles[ "cl_pt" ] = &cl_pt;
      fHandles[ "convFlag" ] = &convFlag;
      fHandles[ "convanglematch" ] = &convanglematch;
      fHandles[ "convtrackmatch" ] = &convtrackmatch;
      fHandles[ "convtrk1nBLHits" ] = &convtrk1nBLHits;
      fHandles[ "convtrk1nPixHits" ] = &convtrk1nPixHits;
      fHandles[ "convtrk1nSCTHits" ] = &convtrk1nSCTHits;
      fHandles[ "convtrk1nTRTHits" ] = &convtrk1nTRTHits;
      fHandles[ "convtrk2nBLHits" ] = &convtrk2nBLHits;
      fHandles[ "convtrk2nPixHits" ] = &convtrk2nPixHits;
      fHandles[ "convtrk2nSCTHits" ] = &convtrk2nSCTHits;
      fHandles[ "convtrk2nTRTHits" ] = &convtrk2nTRTHits;
      fHandles[ "convvtxchi2" ] = &convvtxchi2;
      fHandles[ "convvtxx" ] = &convvtxx;
      fHandles[ "convvtxy" ] = &convvtxy;
      fHandles[ "convvtxz" ] = &convvtxz;
      fHandles[ "deltaEmax2" ] = &deltaEmax2;
      fHandles[ "deltaEs" ] = &deltaEs;
      fHandles[ "deltaPhiFromLast" ] = &deltaPhiFromLast;
      fHandles[ "deltaPhiRot" ] = &deltaPhiRot;
      fHandles[ "deltaeta1" ] = &deltaeta1;
      fHandles[ "deltaeta2" ] = &deltaeta2;
      fHandles[ "deltaphi2" ] = &deltaphi2;
      fHandles[ "deltaphiRescaled" ] = &deltaphiRescaled;
      fHandles[ "depth" ] = &depth;
      fHandles[ "eProbabilityBrem" ] = &eProbabilityBrem;
      fHandles[ "eProbabilityComb" ] = &eProbabilityComb;
      fHandles[ "eProbabilityHT" ] = &eProbabilityHT;
      fHandles[ "eProbabilityToT" ] = &eProbabilityToT;
      fHandles[ "electronbgweight" ] = &electronbgweight;
      fHandles[ "electronweight" ] = &electronweight;
      fHandles[ "emaxs1" ] = &emaxs1;
      fHandles[ "errz" ] = &errz;
      fHandles[ "eta" ] = &eta;
      fHandles[ "etaSampling1" ] = &etaSampling1;
      fHandles[ "etacellS0" ] = &etacellS0;
      fHandles[ "etacorrmag" ] = &etacorrmag;
      fHandles[ "etap" ] = &etap;
      fHandles[ "etas0" ] = &etas0;
      fHandles[ "etas1" ] = &etas1;
      fHandles[ "etas2" ] = &etas2;
      fHandles[ "etas3" ] = &etas3;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "expectHitInBLayer" ] = &expectHitInBLayer;
      fHandles[ "f1" ] = &f1;
      fHandles[ "f1core" ] = &f1core;
      fHandles[ "f3" ] = &f3;
      fHandles[ "f3core" ] = &f3core;
      fHandles[ "firstEdens" ] = &firstEdens;
      fHandles[ "fside" ] = &fside;
      fHandles[ "goodOQ" ] = &goodOQ;
      fHandles[ "hasconv" ] = &hasconv;
      fHandles[ "hastrack" ] = &hastrack;
      fHandles[ "isConv" ] = &isConv;
      fHandles[ "isEM" ] = &isEM;
      fHandles[ "isEMLoose" ] = &isEMLoose;
      fHandles[ "isEMMedium" ] = &isEMMedium;
      fHandles[ "isEMTight" ] = &isEMTight;
      fHandles[ "isIso" ] = &isIso;
      fHandles[ "isolationlikelihoodhqelectrons" ] = &isolationlikelihoodhqelectrons;
      fHandles[ "isolationlikelihoodjets" ] = &isolationlikelihoodjets;
      fHandles[ "jet_E" ] = &jet_E;
      fHandles[ "jet_dr" ] = &jet_dr;
      fHandles[ "jet_eta" ] = &jet_eta;
      fHandles[ "jet_m" ] = &jet_m;
      fHandles[ "jet_matched" ] = &jet_matched;
      fHandles[ "jet_phi" ] = &jet_phi;
      fHandles[ "jet_pt" ] = &jet_pt;
      fHandles[ "jet_truth_E" ] = &jet_truth_E;
      fHandles[ "jet_truth_dr" ] = &jet_truth_dr;
      fHandles[ "jet_truth_eta" ] = &jet_truth_eta;
      fHandles[ "jet_truth_m" ] = &jet_truth_m;
      fHandles[ "jet_truth_matched" ] = &jet_truth_matched;
      fHandles[ "jet_truth_phi" ] = &jet_truth_phi;
      fHandles[ "jet_truth_pt" ] = &jet_truth_pt;
      fHandles[ "lateral" ] = &lateral;
      fHandles[ "likelihoodsPixeldEdx" ] = &likelihoodsPixeldEdx;
      fHandles[ "longitudinal" ] = &longitudinal;
      fHandles[ "loose" ] = &loose;
      fHandles[ "looseIso" ] = &looseIso;
      fHandles[ "loosePP" ] = &loosePP;
      fHandles[ "loosePPIso" ] = &loosePPIso;
      fHandles[ "m" ] = &m;
      fHandles[ "massPixeldEdx" ] = &massPixeldEdx;
      fHandles[ "medium" ] = &medium;
      fHandles[ "mediumIso" ] = &mediumIso;
      fHandles[ "mediumIsoWithoutTrack" ] = &mediumIsoWithoutTrack;
      fHandles[ "mediumPP" ] = &mediumPP;
      fHandles[ "mediumPPIso" ] = &mediumPPIso;
      fHandles[ "mediumWithoutTrack" ] = &mediumWithoutTrack;
      fHandles[ "mvaptcone20" ] = &mvaptcone20;
      fHandles[ "mvaptcone30" ] = &mvaptcone30;
      fHandles[ "mvaptcone40" ] = &mvaptcone40;
      fHandles[ "n" ] = &n;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nBLayerOutliers" ] = &nBLayerOutliers;
      fHandles[ "nBLayerSplitHits" ] = &nBLayerSplitHits;
      fHandles[ "nContribPixelLayers" ] = &nContribPixelLayers;
      fHandles[ "nConv" ] = &nConv;
      fHandles[ "nDoubleTrackConv" ] = &nDoubleTrackConv;
      fHandles[ "nGangedFlaggedFakes" ] = &nGangedFlaggedFakes;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nGoodHitsPixeldEdx" ] = &nGoodHitsPixeldEdx;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nPixSplitHits" ] = &nPixSplitHits;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nPixelOutliers" ] = &nPixelOutliers;
      fHandles[ "nPixelSpoiltHits" ] = &nPixelSpoiltHits;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nSCTDoubleHoles" ] = &nSCTDoubleHoles;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nSCTOutliers" ] = &nSCTOutliers;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nSCTSpoiltHits" ] = &nSCTSpoiltHits;
      fHandles[ "nSiHits" ] = &nSiHits;
      fHandles[ "nSingleTrackConv" ] = &nSingleTrackConv;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTHoles" ] = &nTRTHoles;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "neuralnet" ] = &neuralnet;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "origin" ] = &origin;
      fHandles[ "originbkg" ] = &originbkg;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phis0" ] = &phis0;
      fHandles[ "phis1" ] = &phis1;
      fHandles[ "phis2" ] = &phis2;
      fHandles[ "phis3" ] = &phis3;
      fHandles[ "pixeldEdx" ] = &pixeldEdx;
      fHandles[ "pos7" ] = &pos7;
      fHandles[ "pt" ] = &pt;
      fHandles[ "pt1conv" ] = &pt1conv;
      fHandles[ "pt2conv" ] = &pt2conv;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "ptconv" ] = &ptconv;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "pzconv" ] = &pzconv;
      fHandles[ "rawcl_E" ] = &rawcl_E;
      fHandles[ "rawcl_Es0" ] = &rawcl_Es0;
      fHandles[ "rawcl_Es1" ] = &rawcl_Es1;
      fHandles[ "rawcl_Es2" ] = &rawcl_Es2;
      fHandles[ "rawcl_Es3" ] = &rawcl_Es3;
      fHandles[ "rawcl_eta" ] = &rawcl_eta;
      fHandles[ "rawcl_etas0" ] = &rawcl_etas0;
      fHandles[ "rawcl_etas1" ] = &rawcl_etas1;
      fHandles[ "rawcl_etas2" ] = &rawcl_etas2;
      fHandles[ "rawcl_etas3" ] = &rawcl_etas3;
      fHandles[ "rawcl_phi" ] = &rawcl_phi;
      fHandles[ "rawcl_phis0" ] = &rawcl_phis0;
      fHandles[ "rawcl_phis1" ] = &rawcl_phis1;
      fHandles[ "rawcl_phis2" ] = &rawcl_phis2;
      fHandles[ "rawcl_phis3" ] = &rawcl_phis3;
      fHandles[ "rawcl_pt" ] = &rawcl_pt;
      fHandles[ "cl_etaCalo" ] = &cl_etaCalo;
      fHandles[ "cl_phiCalo" ] = &cl_phiCalo;
      fHandles[ "refittedTrack_LMqoverp" ] = &refittedTrack_LMqoverp;
      fHandles[ "refittedTrack_author" ] = &refittedTrack_author;
      fHandles[ "refittedTrack_bremFitStatus" ] = &refittedTrack_bremFitStatus;
      fHandles[ "refittedTrack_bremRadius" ] = &refittedTrack_bremRadius;
      fHandles[ "refittedTrack_bremRadiusErr" ] = &refittedTrack_bremRadiusErr;
      fHandles[ "refittedTrack_bremZ" ] = &refittedTrack_bremZ;
      fHandles[ "refittedTrack_bremZErr" ] = &refittedTrack_bremZErr;
      fHandles[ "refittedTrack_chi2" ] = &refittedTrack_chi2;
      fHandles[ "refittedTrack_covd0" ] = &refittedTrack_covd0;
      fHandles[ "refittedTrack_covd0phi" ] = &refittedTrack_covd0phi;
      fHandles[ "refittedTrack_covd0qoverp" ] = &refittedTrack_covd0qoverp;
      fHandles[ "refittedTrack_covd0theta" ] = &refittedTrack_covd0theta;
      fHandles[ "refittedTrack_covd0z0" ] = &refittedTrack_covd0z0;
      fHandles[ "refittedTrack_covphi" ] = &refittedTrack_covphi;
      fHandles[ "refittedTrack_covphiqoverp" ] = &refittedTrack_covphiqoverp;
      fHandles[ "refittedTrack_covphitheta" ] = &refittedTrack_covphitheta;
      fHandles[ "refittedTrack_covqoverp" ] = &refittedTrack_covqoverp;
      fHandles[ "refittedTrack_covtheta" ] = &refittedTrack_covtheta;
      fHandles[ "refittedTrack_covthetaqoverp" ] = &refittedTrack_covthetaqoverp;
      fHandles[ "refittedTrack_covz0" ] = &refittedTrack_covz0;
      fHandles[ "refittedTrack_covz0phi" ] = &refittedTrack_covz0phi;
      fHandles[ "refittedTrack_covz0qoverp" ] = &refittedTrack_covz0qoverp;
      fHandles[ "refittedTrack_covz0theta" ] = &refittedTrack_covz0theta;
      fHandles[ "refittedTrack_d0" ] = &refittedTrack_d0;
      fHandles[ "refittedTrack_hasBrem" ] = &refittedTrack_hasBrem;
      fHandles[ "refittedTrack_n" ] = &refittedTrack_n;
      fHandles[ "refittedTrack_phi" ] = &refittedTrack_phi;
      fHandles[ "refittedTrack_qoverp" ] = &refittedTrack_qoverp;
      fHandles[ "refittedTrack_theta" ] = &refittedTrack_theta;
      fHandles[ "refittedTrack_z0" ] = &refittedTrack_z0;
      fHandles[ "reta" ] = &reta;
      fHandles[ "ringernn" ] = &ringernn;
      fHandles[ "rings_E" ] = &rings_E;
      fHandles[ "rphi" ] = &rphi;
      fHandles[ "rphiallcalo" ] = &rphiallcalo;
      fHandles[ "secondR" ] = &secondR;
      fHandles[ "secondlambda" ] = &secondlambda;
      fHandles[ "softebgweight" ] = &softebgweight;
      fHandles[ "softeneuralnet" ] = &softeneuralnet;
      fHandles[ "softeweight" ] = &softeweight;
      fHandles[ "tight" ] = &tight;
      fHandles[ "tightIso" ] = &tightIso;
      fHandles[ "tightIsoWithoutTrack" ] = &tightIsoWithoutTrack;
      fHandles[ "tightPP" ] = &tightPP;
      fHandles[ "tightPPIso" ] = &tightPPIso;
      fHandles[ "tightWithoutTrack" ] = &tightWithoutTrack;
      fHandles[ "topoEtcone20" ] = &topoEtcone20;
      fHandles[ "topoEtcone20_corrected" ] = &topoEtcone20_corrected;
      fHandles[ "topoEtcone30" ] = &topoEtcone30;
      fHandles[ "topoEtcone30_corrected" ] = &topoEtcone30_corrected;
      fHandles[ "topoEtcone40" ] = &topoEtcone40;
      fHandles[ "topoEtcone40_corrected" ] = &topoEtcone40_corrected;
      fHandles[ "topoEtcone60" ] = &topoEtcone60;
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
      fHandles[ "trackd0_physics" ] = &trackd0_physics;
      fHandles[ "trackd0beam" ] = &trackd0beam;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackd0pvunbiased" ] = &trackd0pvunbiased;
      fHandles[ "tracketa" ] = &tracketa;
      fHandles[ "trackfitchi2" ] = &trackfitchi2;
      fHandles[ "trackfitndof" ] = &trackfitndof;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "trackpt" ] = &trackpt;
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
      fHandles[ "truth_bremLoc" ] = &truth_bremLoc;
      fHandles[ "truth_bremSi" ] = &truth_bremSi;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_hasHardBrem" ] = &truth_hasHardBrem;
      fHandles[ "truth_index" ] = &truth_index;
      fHandles[ "truth_matched" ] = &truth_matched;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_sumbrem" ] = &truth_sumbrem;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "type" ] = &type;
      fHandles[ "typebkg" ] = &typebkg;
      fHandles[ "vertweight" ] = &vertweight;
      fHandles[ "vertx" ] = &vertx;
      fHandles[ "verty" ] = &verty;
      fHandles[ "vertz" ] = &vertz;
      fHandles[ "weta2" ] = &weta2;
      fHandles[ "ws3" ] = &ws3;
      fHandles[ "wstot" ] = &wstot;
      fHandles[ "zconv" ] = &zconv;
      fHandles[ "zvertex" ] = &zvertex;

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
   ElectronD3PDObject::ElectronD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "CaloPointing_eta" ] = &CaloPointing_eta;
      fHandles[ "CaloPointing_sigma_eta" ] = &CaloPointing_sigma_eta;
      fHandles[ "CaloPointing_sigma_zvertex" ] = &CaloPointing_sigma_zvertex;
      fHandles[ "CaloPointing_zvertex" ] = &CaloPointing_zvertex;
      fHandles[ "E" ] = &E;
      fHandles[ "E233" ] = &E233;
      fHandles[ "E237" ] = &E237;
      fHandles[ "E277" ] = &E277;
      fHandles[ "ED_Njets" ] = &ED_Njets;
      fHandles[ "ED_median" ] = &ED_median;
      fHandles[ "ED_sigma" ] = &ED_sigma;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_index" ] = &EF_index;
      fHandles[ "ES0_real" ] = &ES0_real;
      fHandles[ "ES1_real" ] = &ES1_real;
      fHandles[ "ES2_real" ] = &ES2_real;
      fHandles[ "ES3_real" ] = &ES3_real;
      fHandles[ "E_EMB1" ] = &E_EMB1;
      fHandles[ "E_EMB2" ] = &E_EMB2;
      fHandles[ "E_EMB3" ] = &E_EMB3;
      fHandles[ "E_EME1" ] = &E_EME1;
      fHandles[ "E_EME2" ] = &E_EME2;
      fHandles[ "E_EME3" ] = &E_EME3;
      fHandles[ "E_FCAL0" ] = &E_FCAL0;
      fHandles[ "E_FCAL1" ] = &E_FCAL1;
      fHandles[ "E_FCAL2" ] = &E_FCAL2;
      fHandles[ "E_HEC0" ] = &E_HEC0;
      fHandles[ "E_HEC1" ] = &E_HEC1;
      fHandles[ "E_HEC2" ] = &E_HEC2;
      fHandles[ "E_HEC3" ] = &E_HEC3;
      fHandles[ "E_PreSamplerB" ] = &E_PreSamplerB;
      fHandles[ "E_PreSamplerE" ] = &E_PreSamplerE;
      fHandles[ "E_TileBar0" ] = &E_TileBar0;
      fHandles[ "E_TileBar1" ] = &E_TileBar1;
      fHandles[ "E_TileBar2" ] = &E_TileBar2;
      fHandles[ "E_TileExt0" ] = &E_TileExt0;
      fHandles[ "E_TileExt1" ] = &E_TileExt1;
      fHandles[ "E_TileExt2" ] = &E_TileExt2;
      fHandles[ "E_TileGap1" ] = &E_TileGap1;
      fHandles[ "E_TileGap2" ] = &E_TileGap2;
      fHandles[ "E_TileGap3" ] = &E_TileGap3;
      fHandles[ "EcellS0" ] = &EcellS0;
      fHandles[ "Emax2" ] = &Emax2;
      fHandles[ "Emins1" ] = &Emins1;
      fHandles[ "Es0" ] = &Es0;
      fHandles[ "Es1" ] = &Es1;
      fHandles[ "Es2" ] = &Es2;
      fHandles[ "Es3" ] = &Es3;
      fHandles[ "Et" ] = &Et;
      fHandles[ "Etcone15" ] = &Etcone15;
      fHandles[ "Etcone15_pt_corrected" ] = &Etcone15_pt_corrected;
      fHandles[ "Etcone20" ] = &Etcone20;
      fHandles[ "Etcone20_pt_corrected" ] = &Etcone20_pt_corrected;
      fHandles[ "Etcone25" ] = &Etcone25;
      fHandles[ "Etcone25_pt_corrected" ] = &Etcone25_pt_corrected;
      fHandles[ "Etcone30" ] = &Etcone30;
      fHandles[ "Etcone30_pt_corrected" ] = &Etcone30_pt_corrected;
      fHandles[ "Etcone35" ] = &Etcone35;
      fHandles[ "Etcone35_pt_corrected" ] = &Etcone35_pt_corrected;
      fHandles[ "Etcone40" ] = &Etcone40;
      fHandles[ "Etcone40_ED_corrected" ] = &Etcone40_ED_corrected;
      fHandles[ "Etcone40_corrected" ] = &Etcone40_corrected;
      fHandles[ "Etcone40_pt_corrected" ] = &Etcone40_pt_corrected;
      fHandles[ "Etcone45" ] = &Etcone45;
      fHandles[ "Ethad" ] = &Ethad;
      fHandles[ "Ethad1" ] = &Ethad1;
      fHandles[ "EtringnoisedR03sig2" ] = &EtringnoisedR03sig2;
      fHandles[ "EtringnoisedR03sig3" ] = &EtringnoisedR03sig3;
      fHandles[ "EtringnoisedR03sig4" ] = &EtringnoisedR03sig4;
      fHandles[ "HPV_eta" ] = &HPV_eta;
      fHandles[ "HPV_sigma_eta" ] = &HPV_sigma_eta;
      fHandles[ "HPV_sigma_zvertex" ] = &HPV_sigma_zvertex;
      fHandles[ "HPV_zvertex" ] = &HPV_zvertex;
      fHandles[ "Hmatrix" ] = &Hmatrix;
      fHandles[ "Hmatrix5" ] = &Hmatrix5;
      fHandles[ "OQ" ] = &OQ;
      fHandles[ "Rconv" ] = &Rconv;
      fHandles[ "TRTHighTHitsRatio" ] = &TRTHighTHitsRatio;
      fHandles[ "TRTHighTOutliersRatio" ] = &TRTHighTOutliersRatio;
      fHandles[ "Unrefittedtrack_d0" ] = &Unrefittedtrack_d0;
      fHandles[ "Unrefittedtrack_eta" ] = &Unrefittedtrack_eta;
      fHandles[ "Unrefittedtrack_phi" ] = &Unrefittedtrack_phi;
      fHandles[ "Unrefittedtrack_pt" ] = &Unrefittedtrack_pt;
      fHandles[ "Unrefittedtrack_qoverp" ] = &Unrefittedtrack_qoverp;
      fHandles[ "Unrefittedtrack_theta" ] = &Unrefittedtrack_theta;
      fHandles[ "Unrefittedtrack_z0" ] = &Unrefittedtrack_z0;
      fHandles[ "adaboost" ] = &adaboost;
      fHandles[ "author" ] = &author;
      fHandles[ "calibHitsShowerDepth" ] = &calibHitsShowerDepth;
      fHandles[ "cellmaxfrac" ] = &cellmaxfrac;
      fHandles[ "centerlambda" ] = &centerlambda;
      fHandles[ "charge" ] = &charge;
      fHandles[ "cl_E" ] = &cl_E;
      fHandles[ "cl_eta" ] = &cl_eta;
      fHandles[ "cl_phi" ] = &cl_phi;
      fHandles[ "cl_pt" ] = &cl_pt;
      fHandles[ "convFlag" ] = &convFlag;
      fHandles[ "convanglematch" ] = &convanglematch;
      fHandles[ "convtrackmatch" ] = &convtrackmatch;
      fHandles[ "convtrk1nBLHits" ] = &convtrk1nBLHits;
      fHandles[ "convtrk1nPixHits" ] = &convtrk1nPixHits;
      fHandles[ "convtrk1nSCTHits" ] = &convtrk1nSCTHits;
      fHandles[ "convtrk1nTRTHits" ] = &convtrk1nTRTHits;
      fHandles[ "convtrk2nBLHits" ] = &convtrk2nBLHits;
      fHandles[ "convtrk2nPixHits" ] = &convtrk2nPixHits;
      fHandles[ "convtrk2nSCTHits" ] = &convtrk2nSCTHits;
      fHandles[ "convtrk2nTRTHits" ] = &convtrk2nTRTHits;
      fHandles[ "convvtxchi2" ] = &convvtxchi2;
      fHandles[ "convvtxx" ] = &convvtxx;
      fHandles[ "convvtxy" ] = &convvtxy;
      fHandles[ "convvtxz" ] = &convvtxz;
      fHandles[ "deltaEmax2" ] = &deltaEmax2;
      fHandles[ "deltaEs" ] = &deltaEs;
      fHandles[ "deltaPhiFromLast" ] = &deltaPhiFromLast;
      fHandles[ "deltaPhiRot" ] = &deltaPhiRot;
      fHandles[ "deltaeta1" ] = &deltaeta1;
      fHandles[ "deltaeta2" ] = &deltaeta2;
      fHandles[ "deltaphi2" ] = &deltaphi2;
      fHandles[ "deltaphiRescaled" ] = &deltaphiRescaled;
      fHandles[ "depth" ] = &depth;
      fHandles[ "eProbabilityBrem" ] = &eProbabilityBrem;
      fHandles[ "eProbabilityComb" ] = &eProbabilityComb;
      fHandles[ "eProbabilityHT" ] = &eProbabilityHT;
      fHandles[ "eProbabilityToT" ] = &eProbabilityToT;
      fHandles[ "electronbgweight" ] = &electronbgweight;
      fHandles[ "electronweight" ] = &electronweight;
      fHandles[ "emaxs1" ] = &emaxs1;
      fHandles[ "errz" ] = &errz;
      fHandles[ "eta" ] = &eta;
      fHandles[ "etaSampling1" ] = &etaSampling1;
      fHandles[ "etacellS0" ] = &etacellS0;
      fHandles[ "etacorrmag" ] = &etacorrmag;
      fHandles[ "etap" ] = &etap;
      fHandles[ "etas0" ] = &etas0;
      fHandles[ "etas1" ] = &etas1;
      fHandles[ "etas2" ] = &etas2;
      fHandles[ "etas3" ] = &etas3;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "expectHitInBLayer" ] = &expectHitInBLayer;
      fHandles[ "f1" ] = &f1;
      fHandles[ "f1core" ] = &f1core;
      fHandles[ "f3" ] = &f3;
      fHandles[ "f3core" ] = &f3core;
      fHandles[ "firstEdens" ] = &firstEdens;
      fHandles[ "fside" ] = &fside;
      fHandles[ "goodOQ" ] = &goodOQ;
      fHandles[ "hasconv" ] = &hasconv;
      fHandles[ "hastrack" ] = &hastrack;
      fHandles[ "isConv" ] = &isConv;
      fHandles[ "isEM" ] = &isEM;
      fHandles[ "isEMLoose" ] = &isEMLoose;
      fHandles[ "isEMMedium" ] = &isEMMedium;
      fHandles[ "isEMTight" ] = &isEMTight;
      fHandles[ "isIso" ] = &isIso;
      fHandles[ "isolationlikelihoodhqelectrons" ] = &isolationlikelihoodhqelectrons;
      fHandles[ "isolationlikelihoodjets" ] = &isolationlikelihoodjets;
      fHandles[ "jet_E" ] = &jet_E;
      fHandles[ "jet_dr" ] = &jet_dr;
      fHandles[ "jet_eta" ] = &jet_eta;
      fHandles[ "jet_m" ] = &jet_m;
      fHandles[ "jet_matched" ] = &jet_matched;
      fHandles[ "jet_phi" ] = &jet_phi;
      fHandles[ "jet_pt" ] = &jet_pt;
      fHandles[ "jet_truth_E" ] = &jet_truth_E;
      fHandles[ "jet_truth_dr" ] = &jet_truth_dr;
      fHandles[ "jet_truth_eta" ] = &jet_truth_eta;
      fHandles[ "jet_truth_m" ] = &jet_truth_m;
      fHandles[ "jet_truth_matched" ] = &jet_truth_matched;
      fHandles[ "jet_truth_phi" ] = &jet_truth_phi;
      fHandles[ "jet_truth_pt" ] = &jet_truth_pt;
      fHandles[ "lateral" ] = &lateral;
      fHandles[ "likelihoodsPixeldEdx" ] = &likelihoodsPixeldEdx;
      fHandles[ "longitudinal" ] = &longitudinal;
      fHandles[ "loose" ] = &loose;
      fHandles[ "looseIso" ] = &looseIso;
      fHandles[ "loosePP" ] = &loosePP;
      fHandles[ "loosePPIso" ] = &loosePPIso;
      fHandles[ "m" ] = &m;
      fHandles[ "massPixeldEdx" ] = &massPixeldEdx;
      fHandles[ "medium" ] = &medium;
      fHandles[ "mediumIso" ] = &mediumIso;
      fHandles[ "mediumIsoWithoutTrack" ] = &mediumIsoWithoutTrack;
      fHandles[ "mediumPP" ] = &mediumPP;
      fHandles[ "mediumPPIso" ] = &mediumPPIso;
      fHandles[ "mediumWithoutTrack" ] = &mediumWithoutTrack;
      fHandles[ "mvaptcone20" ] = &mvaptcone20;
      fHandles[ "mvaptcone30" ] = &mvaptcone30;
      fHandles[ "mvaptcone40" ] = &mvaptcone40;
      fHandles[ "n" ] = &n;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nBLayerOutliers" ] = &nBLayerOutliers;
      fHandles[ "nBLayerSplitHits" ] = &nBLayerSplitHits;
      fHandles[ "nContribPixelLayers" ] = &nContribPixelLayers;
      fHandles[ "nConv" ] = &nConv;
      fHandles[ "nDoubleTrackConv" ] = &nDoubleTrackConv;
      fHandles[ "nGangedFlaggedFakes" ] = &nGangedFlaggedFakes;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nGoodHitsPixeldEdx" ] = &nGoodHitsPixeldEdx;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nPixSplitHits" ] = &nPixSplitHits;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nPixelOutliers" ] = &nPixelOutliers;
      fHandles[ "nPixelSpoiltHits" ] = &nPixelSpoiltHits;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nSCTDoubleHoles" ] = &nSCTDoubleHoles;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nSCTOutliers" ] = &nSCTOutliers;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nSCTSpoiltHits" ] = &nSCTSpoiltHits;
      fHandles[ "nSiHits" ] = &nSiHits;
      fHandles[ "nSingleTrackConv" ] = &nSingleTrackConv;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTHoles" ] = &nTRTHoles;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "neuralnet" ] = &neuralnet;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "origin" ] = &origin;
      fHandles[ "originbkg" ] = &originbkg;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phis0" ] = &phis0;
      fHandles[ "phis1" ] = &phis1;
      fHandles[ "phis2" ] = &phis2;
      fHandles[ "phis3" ] = &phis3;
      fHandles[ "pixeldEdx" ] = &pixeldEdx;
      fHandles[ "pos7" ] = &pos7;
      fHandles[ "pt" ] = &pt;
      fHandles[ "pt1conv" ] = &pt1conv;
      fHandles[ "pt2conv" ] = &pt2conv;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "ptconv" ] = &ptconv;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "pzconv" ] = &pzconv;
      fHandles[ "rawcl_E" ] = &rawcl_E;
      fHandles[ "rawcl_Es0" ] = &rawcl_Es0;
      fHandles[ "rawcl_Es1" ] = &rawcl_Es1;
      fHandles[ "rawcl_Es2" ] = &rawcl_Es2;
      fHandles[ "rawcl_Es3" ] = &rawcl_Es3;
      fHandles[ "rawcl_eta" ] = &rawcl_eta;
      fHandles[ "rawcl_etas0" ] = &rawcl_etas0;
      fHandles[ "rawcl_etas1" ] = &rawcl_etas1;
      fHandles[ "rawcl_etas2" ] = &rawcl_etas2;
      fHandles[ "rawcl_etas3" ] = &rawcl_etas3;
      fHandles[ "rawcl_phi" ] = &rawcl_phi;
      fHandles[ "rawcl_phis0" ] = &rawcl_phis0;
      fHandles[ "rawcl_phis1" ] = &rawcl_phis1;
      fHandles[ "rawcl_phis2" ] = &rawcl_phis2;
      fHandles[ "rawcl_phis3" ] = &rawcl_phis3;
      fHandles[ "rawcl_pt" ] = &rawcl_pt;
      fHandles[ "cl_etaCalo" ] = &cl_etaCalo;
      fHandles[ "cl_phiCalo" ] = &cl_phiCalo;
      fHandles[ "refittedTrack_LMqoverp" ] = &refittedTrack_LMqoverp;
      fHandles[ "refittedTrack_author" ] = &refittedTrack_author;
      fHandles[ "refittedTrack_bremFitStatus" ] = &refittedTrack_bremFitStatus;
      fHandles[ "refittedTrack_bremRadius" ] = &refittedTrack_bremRadius;
      fHandles[ "refittedTrack_bremRadiusErr" ] = &refittedTrack_bremRadiusErr;
      fHandles[ "refittedTrack_bremZ" ] = &refittedTrack_bremZ;
      fHandles[ "refittedTrack_bremZErr" ] = &refittedTrack_bremZErr;
      fHandles[ "refittedTrack_chi2" ] = &refittedTrack_chi2;
      fHandles[ "refittedTrack_covd0" ] = &refittedTrack_covd0;
      fHandles[ "refittedTrack_covd0phi" ] = &refittedTrack_covd0phi;
      fHandles[ "refittedTrack_covd0qoverp" ] = &refittedTrack_covd0qoverp;
      fHandles[ "refittedTrack_covd0theta" ] = &refittedTrack_covd0theta;
      fHandles[ "refittedTrack_covd0z0" ] = &refittedTrack_covd0z0;
      fHandles[ "refittedTrack_covphi" ] = &refittedTrack_covphi;
      fHandles[ "refittedTrack_covphiqoverp" ] = &refittedTrack_covphiqoverp;
      fHandles[ "refittedTrack_covphitheta" ] = &refittedTrack_covphitheta;
      fHandles[ "refittedTrack_covqoverp" ] = &refittedTrack_covqoverp;
      fHandles[ "refittedTrack_covtheta" ] = &refittedTrack_covtheta;
      fHandles[ "refittedTrack_covthetaqoverp" ] = &refittedTrack_covthetaqoverp;
      fHandles[ "refittedTrack_covz0" ] = &refittedTrack_covz0;
      fHandles[ "refittedTrack_covz0phi" ] = &refittedTrack_covz0phi;
      fHandles[ "refittedTrack_covz0qoverp" ] = &refittedTrack_covz0qoverp;
      fHandles[ "refittedTrack_covz0theta" ] = &refittedTrack_covz0theta;
      fHandles[ "refittedTrack_d0" ] = &refittedTrack_d0;
      fHandles[ "refittedTrack_hasBrem" ] = &refittedTrack_hasBrem;
      fHandles[ "refittedTrack_n" ] = &refittedTrack_n;
      fHandles[ "refittedTrack_phi" ] = &refittedTrack_phi;
      fHandles[ "refittedTrack_qoverp" ] = &refittedTrack_qoverp;
      fHandles[ "refittedTrack_theta" ] = &refittedTrack_theta;
      fHandles[ "refittedTrack_z0" ] = &refittedTrack_z0;
      fHandles[ "reta" ] = &reta;
      fHandles[ "ringernn" ] = &ringernn;
      fHandles[ "rings_E" ] = &rings_E;
      fHandles[ "rphi" ] = &rphi;
      fHandles[ "rphiallcalo" ] = &rphiallcalo;
      fHandles[ "secondR" ] = &secondR;
      fHandles[ "secondlambda" ] = &secondlambda;
      fHandles[ "softebgweight" ] = &softebgweight;
      fHandles[ "softeneuralnet" ] = &softeneuralnet;
      fHandles[ "softeweight" ] = &softeweight;
      fHandles[ "tight" ] = &tight;
      fHandles[ "tightIso" ] = &tightIso;
      fHandles[ "tightIsoWithoutTrack" ] = &tightIsoWithoutTrack;
      fHandles[ "tightPP" ] = &tightPP;
      fHandles[ "tightPPIso" ] = &tightPPIso;
      fHandles[ "tightWithoutTrack" ] = &tightWithoutTrack;
      fHandles[ "topoEtcone20" ] = &topoEtcone20;
      fHandles[ "topoEtcone20_corrected" ] = &topoEtcone20_corrected;
      fHandles[ "topoEtcone30" ] = &topoEtcone30;
      fHandles[ "topoEtcone30_corrected" ] = &topoEtcone30_corrected;
      fHandles[ "topoEtcone40" ] = &topoEtcone40;
      fHandles[ "topoEtcone40_corrected" ] = &topoEtcone40_corrected;
      fHandles[ "topoEtcone60" ] = &topoEtcone60;
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
      fHandles[ "trackd0_physics" ] = &trackd0_physics;
      fHandles[ "trackd0beam" ] = &trackd0beam;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackd0pvunbiased" ] = &trackd0pvunbiased;
      fHandles[ "tracketa" ] = &tracketa;
      fHandles[ "trackfitchi2" ] = &trackfitchi2;
      fHandles[ "trackfitndof" ] = &trackfitndof;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "trackpt" ] = &trackpt;
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
      fHandles[ "truth_bremLoc" ] = &truth_bremLoc;
      fHandles[ "truth_bremSi" ] = &truth_bremSi;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_hasHardBrem" ] = &truth_hasHardBrem;
      fHandles[ "truth_index" ] = &truth_index;
      fHandles[ "truth_matched" ] = &truth_matched;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_sumbrem" ] = &truth_sumbrem;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "type" ] = &type;
      fHandles[ "typebkg" ] = &typebkg;
      fHandles[ "vertweight" ] = &vertweight;
      fHandles[ "vertx" ] = &vertx;
      fHandles[ "verty" ] = &verty;
      fHandles[ "vertz" ] = &vertz;
      fHandles[ "weta2" ] = &weta2;
      fHandles[ "ws3" ] = &ws3;
      fHandles[ "wstot" ] = &wstot;
      fHandles[ "zconv" ] = &zconv;
      fHandles[ "zvertex" ] = &zvertex;

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
   ElectronD3PDObject::~ElectronD3PDObject() {

      for( size_t i = 0; i < fProxies.size(); ++i ) {
         delete fProxies[ i ];
      }
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* ElectronD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void ElectronD3PDObject::SetPrefix( const char* prefix ) {

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
   void ElectronD3PDObject::ReadFrom( TTree* tree ) {

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
   void ElectronD3PDObject::WriteTo( TTree* tree ) {

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
   void ElectronD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void ElectronD3PDObject::ReadAllActive() {

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

   D3PDReadStats ElectronD3PDObject::GetStatistics() const {

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
   ElectronD3PDObject& ElectronD3PDObject::Set( const ElectronD3PDObject& parent ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Set", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( parent.CaloPointing_eta.IsAvailable() ) {
         *( CaloPointing_eta() ) = *( parent.CaloPointing_eta() );
      } else {
         CaloPointing_eta()->clear();
      }
      if( parent.CaloPointing_sigma_eta.IsAvailable() ) {
         *( CaloPointing_sigma_eta() ) = *( parent.CaloPointing_sigma_eta() );
      } else {
         CaloPointing_sigma_eta()->clear();
      }
      if( parent.CaloPointing_sigma_zvertex.IsAvailable() ) {
         *( CaloPointing_sigma_zvertex() ) = *( parent.CaloPointing_sigma_zvertex() );
      } else {
         CaloPointing_sigma_zvertex()->clear();
      }
      if( parent.CaloPointing_zvertex.IsAvailable() ) {
         *( CaloPointing_zvertex() ) = *( parent.CaloPointing_zvertex() );
      } else {
         CaloPointing_zvertex()->clear();
      }
      if( parent.E.IsAvailable() ) {
         *( E() ) = *( parent.E() );
      } else {
         E()->clear();
      }
      if( parent.E233.IsAvailable() ) {
         *( E233() ) = *( parent.E233() );
      } else {
         E233()->clear();
      }
      if( parent.E237.IsAvailable() ) {
         *( E237() ) = *( parent.E237() );
      } else {
         E237()->clear();
      }
      if( parent.E277.IsAvailable() ) {
         *( E277() ) = *( parent.E277() );
      } else {
         E277()->clear();
      }
      if( parent.ED_Njets.IsAvailable() ) {
         *( ED_Njets() ) = *( parent.ED_Njets() );
      } else {
         ED_Njets()->clear();
      }
      if( parent.ED_median.IsAvailable() ) {
         *( ED_median() ) = *( parent.ED_median() );
      } else {
         ED_median()->clear();
      }
      if( parent.ED_sigma.IsAvailable() ) {
         *( ED_sigma() ) = *( parent.ED_sigma() );
      } else {
         ED_sigma()->clear();
      }
      if( parent.EF_dr.IsAvailable() ) {
         *( EF_dr() ) = *( parent.EF_dr() );
      } else {
         EF_dr()->clear();
      }
      if( parent.EF_index.IsAvailable() ) {
         *( EF_index() ) = *( parent.EF_index() );
      } else {
         EF_index()->clear();
      }
      if( parent.ES0_real.IsAvailable() ) {
         *( ES0_real() ) = *( parent.ES0_real() );
      } else {
         ES0_real()->clear();
      }
      if( parent.ES1_real.IsAvailable() ) {
         *( ES1_real() ) = *( parent.ES1_real() );
      } else {
         ES1_real()->clear();
      }
      if( parent.ES2_real.IsAvailable() ) {
         *( ES2_real() ) = *( parent.ES2_real() );
      } else {
         ES2_real()->clear();
      }
      if( parent.ES3_real.IsAvailable() ) {
         *( ES3_real() ) = *( parent.ES3_real() );
      } else {
         ES3_real()->clear();
      }
      if( parent.E_EMB1.IsAvailable() ) {
         *( E_EMB1() ) = *( parent.E_EMB1() );
      } else {
         E_EMB1()->clear();
      }
      if( parent.E_EMB2.IsAvailable() ) {
         *( E_EMB2() ) = *( parent.E_EMB2() );
      } else {
         E_EMB2()->clear();
      }
      if( parent.E_EMB3.IsAvailable() ) {
         *( E_EMB3() ) = *( parent.E_EMB3() );
      } else {
         E_EMB3()->clear();
      }
      if( parent.E_EME1.IsAvailable() ) {
         *( E_EME1() ) = *( parent.E_EME1() );
      } else {
         E_EME1()->clear();
      }
      if( parent.E_EME2.IsAvailable() ) {
         *( E_EME2() ) = *( parent.E_EME2() );
      } else {
         E_EME2()->clear();
      }
      if( parent.E_EME3.IsAvailable() ) {
         *( E_EME3() ) = *( parent.E_EME3() );
      } else {
         E_EME3()->clear();
      }
      if( parent.E_FCAL0.IsAvailable() ) {
         *( E_FCAL0() ) = *( parent.E_FCAL0() );
      } else {
         E_FCAL0()->clear();
      }
      if( parent.E_FCAL1.IsAvailable() ) {
         *( E_FCAL1() ) = *( parent.E_FCAL1() );
      } else {
         E_FCAL1()->clear();
      }
      if( parent.E_FCAL2.IsAvailable() ) {
         *( E_FCAL2() ) = *( parent.E_FCAL2() );
      } else {
         E_FCAL2()->clear();
      }
      if( parent.E_HEC0.IsAvailable() ) {
         *( E_HEC0() ) = *( parent.E_HEC0() );
      } else {
         E_HEC0()->clear();
      }
      if( parent.E_HEC1.IsAvailable() ) {
         *( E_HEC1() ) = *( parent.E_HEC1() );
      } else {
         E_HEC1()->clear();
      }
      if( parent.E_HEC2.IsAvailable() ) {
         *( E_HEC2() ) = *( parent.E_HEC2() );
      } else {
         E_HEC2()->clear();
      }
      if( parent.E_HEC3.IsAvailable() ) {
         *( E_HEC3() ) = *( parent.E_HEC3() );
      } else {
         E_HEC3()->clear();
      }
      if( parent.E_PreSamplerB.IsAvailable() ) {
         *( E_PreSamplerB() ) = *( parent.E_PreSamplerB() );
      } else {
         E_PreSamplerB()->clear();
      }
      if( parent.E_PreSamplerE.IsAvailable() ) {
         *( E_PreSamplerE() ) = *( parent.E_PreSamplerE() );
      } else {
         E_PreSamplerE()->clear();
      }
      if( parent.E_TileBar0.IsAvailable() ) {
         *( E_TileBar0() ) = *( parent.E_TileBar0() );
      } else {
         E_TileBar0()->clear();
      }
      if( parent.E_TileBar1.IsAvailable() ) {
         *( E_TileBar1() ) = *( parent.E_TileBar1() );
      } else {
         E_TileBar1()->clear();
      }
      if( parent.E_TileBar2.IsAvailable() ) {
         *( E_TileBar2() ) = *( parent.E_TileBar2() );
      } else {
         E_TileBar2()->clear();
      }
      if( parent.E_TileExt0.IsAvailable() ) {
         *( E_TileExt0() ) = *( parent.E_TileExt0() );
      } else {
         E_TileExt0()->clear();
      }
      if( parent.E_TileExt1.IsAvailable() ) {
         *( E_TileExt1() ) = *( parent.E_TileExt1() );
      } else {
         E_TileExt1()->clear();
      }
      if( parent.E_TileExt2.IsAvailable() ) {
         *( E_TileExt2() ) = *( parent.E_TileExt2() );
      } else {
         E_TileExt2()->clear();
      }
      if( parent.E_TileGap1.IsAvailable() ) {
         *( E_TileGap1() ) = *( parent.E_TileGap1() );
      } else {
         E_TileGap1()->clear();
      }
      if( parent.E_TileGap2.IsAvailable() ) {
         *( E_TileGap2() ) = *( parent.E_TileGap2() );
      } else {
         E_TileGap2()->clear();
      }
      if( parent.E_TileGap3.IsAvailable() ) {
         *( E_TileGap3() ) = *( parent.E_TileGap3() );
      } else {
         E_TileGap3()->clear();
      }
      if( parent.EcellS0.IsAvailable() ) {
         *( EcellS0() ) = *( parent.EcellS0() );
      } else {
         EcellS0()->clear();
      }
      if( parent.Emax2.IsAvailable() ) {
         *( Emax2() ) = *( parent.Emax2() );
      } else {
         Emax2()->clear();
      }
      if( parent.Emins1.IsAvailable() ) {
         *( Emins1() ) = *( parent.Emins1() );
      } else {
         Emins1()->clear();
      }
      if( parent.Es0.IsAvailable() ) {
         *( Es0() ) = *( parent.Es0() );
      } else {
         Es0()->clear();
      }
      if( parent.Es1.IsAvailable() ) {
         *( Es1() ) = *( parent.Es1() );
      } else {
         Es1()->clear();
      }
      if( parent.Es2.IsAvailable() ) {
         *( Es2() ) = *( parent.Es2() );
      } else {
         Es2()->clear();
      }
      if( parent.Es3.IsAvailable() ) {
         *( Es3() ) = *( parent.Es3() );
      } else {
         Es3()->clear();
      }
      if( parent.Et.IsAvailable() ) {
         *( Et() ) = *( parent.Et() );
      } else {
         Et()->clear();
      }
      if( parent.Etcone15.IsAvailable() ) {
         *( Etcone15() ) = *( parent.Etcone15() );
      } else {
         Etcone15()->clear();
      }
      if( parent.Etcone15_pt_corrected.IsAvailable() ) {
         *( Etcone15_pt_corrected() ) = *( parent.Etcone15_pt_corrected() );
      } else {
         Etcone15_pt_corrected()->clear();
      }
      if( parent.Etcone20.IsAvailable() ) {
         *( Etcone20() ) = *( parent.Etcone20() );
      } else {
         Etcone20()->clear();
      }
      if( parent.Etcone20_pt_corrected.IsAvailable() ) {
         *( Etcone20_pt_corrected() ) = *( parent.Etcone20_pt_corrected() );
      } else {
         Etcone20_pt_corrected()->clear();
      }
      if( parent.Etcone25.IsAvailable() ) {
         *( Etcone25() ) = *( parent.Etcone25() );
      } else {
         Etcone25()->clear();
      }
      if( parent.Etcone25_pt_corrected.IsAvailable() ) {
         *( Etcone25_pt_corrected() ) = *( parent.Etcone25_pt_corrected() );
      } else {
         Etcone25_pt_corrected()->clear();
      }
      if( parent.Etcone30.IsAvailable() ) {
         *( Etcone30() ) = *( parent.Etcone30() );
      } else {
         Etcone30()->clear();
      }
      if( parent.Etcone30_pt_corrected.IsAvailable() ) {
         *( Etcone30_pt_corrected() ) = *( parent.Etcone30_pt_corrected() );
      } else {
         Etcone30_pt_corrected()->clear();
      }
      if( parent.Etcone35.IsAvailable() ) {
         *( Etcone35() ) = *( parent.Etcone35() );
      } else {
         Etcone35()->clear();
      }
      if( parent.Etcone35_pt_corrected.IsAvailable() ) {
         *( Etcone35_pt_corrected() ) = *( parent.Etcone35_pt_corrected() );
      } else {
         Etcone35_pt_corrected()->clear();
      }
      if( parent.Etcone40.IsAvailable() ) {
         *( Etcone40() ) = *( parent.Etcone40() );
      } else {
         Etcone40()->clear();
      }
      if( parent.Etcone40_ED_corrected.IsAvailable() ) {
         *( Etcone40_ED_corrected() ) = *( parent.Etcone40_ED_corrected() );
      } else {
         Etcone40_ED_corrected()->clear();
      }
      if( parent.Etcone40_corrected.IsAvailable() ) {
         *( Etcone40_corrected() ) = *( parent.Etcone40_corrected() );
      } else {
         Etcone40_corrected()->clear();
      }
      if( parent.Etcone40_pt_corrected.IsAvailable() ) {
         *( Etcone40_pt_corrected() ) = *( parent.Etcone40_pt_corrected() );
      } else {
         Etcone40_pt_corrected()->clear();
      }
      if( parent.Etcone45.IsAvailable() ) {
         *( Etcone45() ) = *( parent.Etcone45() );
      } else {
         Etcone45()->clear();
      }
      if( parent.Ethad.IsAvailable() ) {
         *( Ethad() ) = *( parent.Ethad() );
      } else {
         Ethad()->clear();
      }
      if( parent.Ethad1.IsAvailable() ) {
         *( Ethad1() ) = *( parent.Ethad1() );
      } else {
         Ethad1()->clear();
      }
      if( parent.EtringnoisedR03sig2.IsAvailable() ) {
         *( EtringnoisedR03sig2() ) = *( parent.EtringnoisedR03sig2() );
      } else {
         EtringnoisedR03sig2()->clear();
      }
      if( parent.EtringnoisedR03sig3.IsAvailable() ) {
         *( EtringnoisedR03sig3() ) = *( parent.EtringnoisedR03sig3() );
      } else {
         EtringnoisedR03sig3()->clear();
      }
      if( parent.EtringnoisedR03sig4.IsAvailable() ) {
         *( EtringnoisedR03sig4() ) = *( parent.EtringnoisedR03sig4() );
      } else {
         EtringnoisedR03sig4()->clear();
      }
      if( parent.HPV_eta.IsAvailable() ) {
         *( HPV_eta() ) = *( parent.HPV_eta() );
      } else {
         HPV_eta()->clear();
      }
      if( parent.HPV_sigma_eta.IsAvailable() ) {
         *( HPV_sigma_eta() ) = *( parent.HPV_sigma_eta() );
      } else {
         HPV_sigma_eta()->clear();
      }
      if( parent.HPV_sigma_zvertex.IsAvailable() ) {
         *( HPV_sigma_zvertex() ) = *( parent.HPV_sigma_zvertex() );
      } else {
         HPV_sigma_zvertex()->clear();
      }
      if( parent.HPV_zvertex.IsAvailable() ) {
         *( HPV_zvertex() ) = *( parent.HPV_zvertex() );
      } else {
         HPV_zvertex()->clear();
      }
      if( parent.Hmatrix.IsAvailable() ) {
         *( Hmatrix() ) = *( parent.Hmatrix() );
      } else {
         Hmatrix()->clear();
      }
      if( parent.Hmatrix5.IsAvailable() ) {
         *( Hmatrix5() ) = *( parent.Hmatrix5() );
      } else {
         Hmatrix5()->clear();
      }
      if( parent.OQ.IsAvailable() ) {
         *( OQ() ) = *( parent.OQ() );
      } else {
         OQ()->clear();
      }
      if( parent.Rconv.IsAvailable() ) {
         *( Rconv() ) = *( parent.Rconv() );
      } else {
         Rconv()->clear();
      }
      if( parent.TRTHighTHitsRatio.IsAvailable() ) {
         *( TRTHighTHitsRatio() ) = *( parent.TRTHighTHitsRatio() );
      } else {
         TRTHighTHitsRatio()->clear();
      }
      if( parent.TRTHighTOutliersRatio.IsAvailable() ) {
         *( TRTHighTOutliersRatio() ) = *( parent.TRTHighTOutliersRatio() );
      } else {
         TRTHighTOutliersRatio()->clear();
      }
      if( parent.Unrefittedtrack_d0.IsAvailable() ) {
         *( Unrefittedtrack_d0() ) = *( parent.Unrefittedtrack_d0() );
      } else {
         Unrefittedtrack_d0()->clear();
      }
      if( parent.Unrefittedtrack_eta.IsAvailable() ) {
         *( Unrefittedtrack_eta() ) = *( parent.Unrefittedtrack_eta() );
      } else {
         Unrefittedtrack_eta()->clear();
      }
      if( parent.Unrefittedtrack_phi.IsAvailable() ) {
         *( Unrefittedtrack_phi() ) = *( parent.Unrefittedtrack_phi() );
      } else {
         Unrefittedtrack_phi()->clear();
      }
      if( parent.Unrefittedtrack_pt.IsAvailable() ) {
         *( Unrefittedtrack_pt() ) = *( parent.Unrefittedtrack_pt() );
      } else {
         Unrefittedtrack_pt()->clear();
      }
      if( parent.Unrefittedtrack_qoverp.IsAvailable() ) {
         *( Unrefittedtrack_qoverp() ) = *( parent.Unrefittedtrack_qoverp() );
      } else {
         Unrefittedtrack_qoverp()->clear();
      }
      if( parent.Unrefittedtrack_theta.IsAvailable() ) {
         *( Unrefittedtrack_theta() ) = *( parent.Unrefittedtrack_theta() );
      } else {
         Unrefittedtrack_theta()->clear();
      }
      if( parent.Unrefittedtrack_z0.IsAvailable() ) {
         *( Unrefittedtrack_z0() ) = *( parent.Unrefittedtrack_z0() );
      } else {
         Unrefittedtrack_z0()->clear();
      }
      if( parent.adaboost.IsAvailable() ) {
         *( adaboost() ) = *( parent.adaboost() );
      } else {
         adaboost()->clear();
      }
      if( parent.author.IsAvailable() ) {
         *( author() ) = *( parent.author() );
      } else {
         author()->clear();
      }
      if( parent.calibHitsShowerDepth.IsAvailable() ) {
         *( calibHitsShowerDepth() ) = *( parent.calibHitsShowerDepth() );
      } else {
         calibHitsShowerDepth()->clear();
      }
      if( parent.cellmaxfrac.IsAvailable() ) {
         *( cellmaxfrac() ) = *( parent.cellmaxfrac() );
      } else {
         cellmaxfrac()->clear();
      }
      if( parent.centerlambda.IsAvailable() ) {
         *( centerlambda() ) = *( parent.centerlambda() );
      } else {
         centerlambda()->clear();
      }
      if( parent.charge.IsAvailable() ) {
         *( charge() ) = *( parent.charge() );
      } else {
         charge()->clear();
      }
      if( parent.cl_E.IsAvailable() ) {
         *( cl_E() ) = *( parent.cl_E() );
      } else {
         cl_E()->clear();
      }
      if( parent.cl_eta.IsAvailable() ) {
         *( cl_eta() ) = *( parent.cl_eta() );
      } else {
         cl_eta()->clear();
      }
      if( parent.cl_phi.IsAvailable() ) {
         *( cl_phi() ) = *( parent.cl_phi() );
      } else {
         cl_phi()->clear();
      }
      if( parent.cl_pt.IsAvailable() ) {
         *( cl_pt() ) = *( parent.cl_pt() );
      } else {
         cl_pt()->clear();
      }
      if( parent.convFlag.IsAvailable() ) {
         *( convFlag() ) = *( parent.convFlag() );
      } else {
         convFlag()->clear();
      }
      if( parent.convanglematch.IsAvailable() ) {
         *( convanglematch() ) = *( parent.convanglematch() );
      } else {
         convanglematch()->clear();
      }
      if( parent.convtrackmatch.IsAvailable() ) {
         *( convtrackmatch() ) = *( parent.convtrackmatch() );
      } else {
         convtrackmatch()->clear();
      }
      if( parent.convtrk1nBLHits.IsAvailable() ) {
         *( convtrk1nBLHits() ) = *( parent.convtrk1nBLHits() );
      } else {
         convtrk1nBLHits()->clear();
      }
      if( parent.convtrk1nPixHits.IsAvailable() ) {
         *( convtrk1nPixHits() ) = *( parent.convtrk1nPixHits() );
      } else {
         convtrk1nPixHits()->clear();
      }
      if( parent.convtrk1nSCTHits.IsAvailable() ) {
         *( convtrk1nSCTHits() ) = *( parent.convtrk1nSCTHits() );
      } else {
         convtrk1nSCTHits()->clear();
      }
      if( parent.convtrk1nTRTHits.IsAvailable() ) {
         *( convtrk1nTRTHits() ) = *( parent.convtrk1nTRTHits() );
      } else {
         convtrk1nTRTHits()->clear();
      }
      if( parent.convtrk2nBLHits.IsAvailable() ) {
         *( convtrk2nBLHits() ) = *( parent.convtrk2nBLHits() );
      } else {
         convtrk2nBLHits()->clear();
      }
      if( parent.convtrk2nPixHits.IsAvailable() ) {
         *( convtrk2nPixHits() ) = *( parent.convtrk2nPixHits() );
      } else {
         convtrk2nPixHits()->clear();
      }
      if( parent.convtrk2nSCTHits.IsAvailable() ) {
         *( convtrk2nSCTHits() ) = *( parent.convtrk2nSCTHits() );
      } else {
         convtrk2nSCTHits()->clear();
      }
      if( parent.convtrk2nTRTHits.IsAvailable() ) {
         *( convtrk2nTRTHits() ) = *( parent.convtrk2nTRTHits() );
      } else {
         convtrk2nTRTHits()->clear();
      }
      if( parent.convvtxchi2.IsAvailable() ) {
         *( convvtxchi2() ) = *( parent.convvtxchi2() );
      } else {
         convvtxchi2()->clear();
      }
      if( parent.convvtxx.IsAvailable() ) {
         *( convvtxx() ) = *( parent.convvtxx() );
      } else {
         convvtxx()->clear();
      }
      if( parent.convvtxy.IsAvailable() ) {
         *( convvtxy() ) = *( parent.convvtxy() );
      } else {
         convvtxy()->clear();
      }
      if( parent.convvtxz.IsAvailable() ) {
         *( convvtxz() ) = *( parent.convvtxz() );
      } else {
         convvtxz()->clear();
      }
      if( parent.deltaEmax2.IsAvailable() ) {
         *( deltaEmax2() ) = *( parent.deltaEmax2() );
      } else {
         deltaEmax2()->clear();
      }
      if( parent.deltaEs.IsAvailable() ) {
         *( deltaEs() ) = *( parent.deltaEs() );
      } else {
         deltaEs()->clear();
      }
      if( parent.deltaPhiFromLast.IsAvailable() ) {
         *( deltaPhiFromLast() ) = *( parent.deltaPhiFromLast() );
      } else {
         deltaPhiFromLast()->clear();
      }
      if( parent.deltaPhiRot.IsAvailable() ) {
         *( deltaPhiRot() ) = *( parent.deltaPhiRot() );
      } else {
         deltaPhiRot()->clear();
      }
      if( parent.deltaeta1.IsAvailable() ) {
         *( deltaeta1() ) = *( parent.deltaeta1() );
      } else {
         deltaeta1()->clear();
      }
      if( parent.deltaeta2.IsAvailable() ) {
         *( deltaeta2() ) = *( parent.deltaeta2() );
      } else {
         deltaeta2()->clear();
      }
      if( parent.deltaphi2.IsAvailable() ) {
         *( deltaphi2() ) = *( parent.deltaphi2() );
      } else {
         deltaphi2()->clear();
      }
      if( parent.deltaphiRescaled.IsAvailable() ) {
         *( deltaphiRescaled() ) = *( parent.deltaphiRescaled() );
      } else {
         deltaphiRescaled()->clear();
      }
      if( parent.depth.IsAvailable() ) {
         *( depth() ) = *( parent.depth() );
      } else {
         depth()->clear();
      }
      if( parent.eProbabilityBrem.IsAvailable() ) {
         *( eProbabilityBrem() ) = *( parent.eProbabilityBrem() );
      } else {
         eProbabilityBrem()->clear();
      }
      if( parent.eProbabilityComb.IsAvailable() ) {
         *( eProbabilityComb() ) = *( parent.eProbabilityComb() );
      } else {
         eProbabilityComb()->clear();
      }
      if( parent.eProbabilityHT.IsAvailable() ) {
         *( eProbabilityHT() ) = *( parent.eProbabilityHT() );
      } else {
         eProbabilityHT()->clear();
      }
      if( parent.eProbabilityToT.IsAvailable() ) {
         *( eProbabilityToT() ) = *( parent.eProbabilityToT() );
      } else {
         eProbabilityToT()->clear();
      }
      if( parent.electronbgweight.IsAvailable() ) {
         *( electronbgweight() ) = *( parent.electronbgweight() );
      } else {
         electronbgweight()->clear();
      }
      if( parent.electronweight.IsAvailable() ) {
         *( electronweight() ) = *( parent.electronweight() );
      } else {
         electronweight()->clear();
      }
      if( parent.emaxs1.IsAvailable() ) {
         *( emaxs1() ) = *( parent.emaxs1() );
      } else {
         emaxs1()->clear();
      }
      if( parent.errz.IsAvailable() ) {
         *( errz() ) = *( parent.errz() );
      } else {
         errz()->clear();
      }
      if( parent.eta.IsAvailable() ) {
         *( eta() ) = *( parent.eta() );
      } else {
         eta()->clear();
      }
      if( parent.etaSampling1.IsAvailable() ) {
         *( etaSampling1() ) = *( parent.etaSampling1() );
      } else {
         etaSampling1()->clear();
      }
      if( parent.etacellS0.IsAvailable() ) {
         *( etacellS0() ) = *( parent.etacellS0() );
      } else {
         etacellS0()->clear();
      }
      if( parent.etacorrmag.IsAvailable() ) {
         *( etacorrmag() ) = *( parent.etacorrmag() );
      } else {
         etacorrmag()->clear();
      }
      if( parent.etap.IsAvailable() ) {
         *( etap() ) = *( parent.etap() );
      } else {
         etap()->clear();
      }
      if( parent.etas0.IsAvailable() ) {
         *( etas0() ) = *( parent.etas0() );
      } else {
         etas0()->clear();
      }
      if( parent.etas1.IsAvailable() ) {
         *( etas1() ) = *( parent.etas1() );
      } else {
         etas1()->clear();
      }
      if( parent.etas2.IsAvailable() ) {
         *( etas2() ) = *( parent.etas2() );
      } else {
         etas2()->clear();
      }
      if( parent.etas3.IsAvailable() ) {
         *( etas3() ) = *( parent.etas3() );
      } else {
         etas3()->clear();
      }
      if( parent.expectBLayerHit.IsAvailable() ) {
         *( expectBLayerHit() ) = *( parent.expectBLayerHit() );
      } else {
         expectBLayerHit()->clear();
      }
      if( parent.expectHitInBLayer.IsAvailable() ) {
         *( expectHitInBLayer() ) = *( parent.expectHitInBLayer() );
      } else {
         expectHitInBLayer()->clear();
      }
      if( parent.f1.IsAvailable() ) {
         *( f1() ) = *( parent.f1() );
      } else {
         f1()->clear();
      }
      if( parent.f1core.IsAvailable() ) {
         *( f1core() ) = *( parent.f1core() );
      } else {
         f1core()->clear();
      }
      if( parent.f3.IsAvailable() ) {
         *( f3() ) = *( parent.f3() );
      } else {
         f3()->clear();
      }
      if( parent.f3core.IsAvailable() ) {
         *( f3core() ) = *( parent.f3core() );
      } else {
         f3core()->clear();
      }
      if( parent.firstEdens.IsAvailable() ) {
         *( firstEdens() ) = *( parent.firstEdens() );
      } else {
         firstEdens()->clear();
      }
      if( parent.fside.IsAvailable() ) {
         *( fside() ) = *( parent.fside() );
      } else {
         fside()->clear();
      }
      if( parent.goodOQ.IsAvailable() ) {
         *( goodOQ() ) = *( parent.goodOQ() );
      } else {
         goodOQ()->clear();
      }
      if( parent.hasconv.IsAvailable() ) {
         *( hasconv() ) = *( parent.hasconv() );
      } else {
         hasconv()->clear();
      }
      if( parent.hastrack.IsAvailable() ) {
         *( hastrack() ) = *( parent.hastrack() );
      } else {
         hastrack()->clear();
      }
      if( parent.isConv.IsAvailable() ) {
         *( isConv() ) = *( parent.isConv() );
      } else {
         isConv()->clear();
      }
      if( parent.isEM.IsAvailable() ) {
         *( isEM() ) = *( parent.isEM() );
      } else {
         isEM()->clear();
      }
      if( parent.isEMLoose.IsAvailable() ) {
         *( isEMLoose() ) = *( parent.isEMLoose() );
      } else {
         isEMLoose()->clear();
      }
      if( parent.isEMMedium.IsAvailable() ) {
         *( isEMMedium() ) = *( parent.isEMMedium() );
      } else {
         isEMMedium()->clear();
      }
      if( parent.isEMTight.IsAvailable() ) {
         *( isEMTight() ) = *( parent.isEMTight() );
      } else {
         isEMTight()->clear();
      }
      if( parent.isIso.IsAvailable() ) {
         *( isIso() ) = *( parent.isIso() );
      } else {
         isIso()->clear();
      }
      if( parent.isolationlikelihoodhqelectrons.IsAvailable() ) {
         *( isolationlikelihoodhqelectrons() ) = *( parent.isolationlikelihoodhqelectrons() );
      } else {
         isolationlikelihoodhqelectrons()->clear();
      }
      if( parent.isolationlikelihoodjets.IsAvailable() ) {
         *( isolationlikelihoodjets() ) = *( parent.isolationlikelihoodjets() );
      } else {
         isolationlikelihoodjets()->clear();
      }
      if( parent.jet_E.IsAvailable() ) {
         *( jet_E() ) = *( parent.jet_E() );
      } else {
         jet_E()->clear();
      }
      if( parent.jet_dr.IsAvailable() ) {
         *( jet_dr() ) = *( parent.jet_dr() );
      } else {
         jet_dr()->clear();
      }
      if( parent.jet_eta.IsAvailable() ) {
         *( jet_eta() ) = *( parent.jet_eta() );
      } else {
         jet_eta()->clear();
      }
      if( parent.jet_m.IsAvailable() ) {
         *( jet_m() ) = *( parent.jet_m() );
      } else {
         jet_m()->clear();
      }
      if( parent.jet_matched.IsAvailable() ) {
         *( jet_matched() ) = *( parent.jet_matched() );
      } else {
         jet_matched()->clear();
      }
      if( parent.jet_phi.IsAvailable() ) {
         *( jet_phi() ) = *( parent.jet_phi() );
      } else {
         jet_phi()->clear();
      }
      if( parent.jet_pt.IsAvailable() ) {
         *( jet_pt() ) = *( parent.jet_pt() );
      } else {
         jet_pt()->clear();
      }
      if( parent.jet_truth_E.IsAvailable() ) {
         *( jet_truth_E() ) = *( parent.jet_truth_E() );
      } else {
         jet_truth_E()->clear();
      }
      if( parent.jet_truth_dr.IsAvailable() ) {
         *( jet_truth_dr() ) = *( parent.jet_truth_dr() );
      } else {
         jet_truth_dr()->clear();
      }
      if( parent.jet_truth_eta.IsAvailable() ) {
         *( jet_truth_eta() ) = *( parent.jet_truth_eta() );
      } else {
         jet_truth_eta()->clear();
      }
      if( parent.jet_truth_m.IsAvailable() ) {
         *( jet_truth_m() ) = *( parent.jet_truth_m() );
      } else {
         jet_truth_m()->clear();
      }
      if( parent.jet_truth_matched.IsAvailable() ) {
         *( jet_truth_matched() ) = *( parent.jet_truth_matched() );
      } else {
         jet_truth_matched()->clear();
      }
      if( parent.jet_truth_phi.IsAvailable() ) {
         *( jet_truth_phi() ) = *( parent.jet_truth_phi() );
      } else {
         jet_truth_phi()->clear();
      }
      if( parent.jet_truth_pt.IsAvailable() ) {
         *( jet_truth_pt() ) = *( parent.jet_truth_pt() );
      } else {
         jet_truth_pt()->clear();
      }
      if( parent.lateral.IsAvailable() ) {
         *( lateral() ) = *( parent.lateral() );
      } else {
         lateral()->clear();
      }
      if( parent.likelihoodsPixeldEdx.IsAvailable() ) {
         *( likelihoodsPixeldEdx() ) = *( parent.likelihoodsPixeldEdx() );
      } else {
         likelihoodsPixeldEdx()->clear();
      }
      if( parent.longitudinal.IsAvailable() ) {
         *( longitudinal() ) = *( parent.longitudinal() );
      } else {
         longitudinal()->clear();
      }
      if( parent.loose.IsAvailable() ) {
         *( loose() ) = *( parent.loose() );
      } else {
         loose()->clear();
      }
      if( parent.looseIso.IsAvailable() ) {
         *( looseIso() ) = *( parent.looseIso() );
      } else {
         looseIso()->clear();
      }
      if( parent.loosePP.IsAvailable() ) {
         *( loosePP() ) = *( parent.loosePP() );
      } else {
         loosePP()->clear();
      }
      if( parent.loosePPIso.IsAvailable() ) {
         *( loosePPIso() ) = *( parent.loosePPIso() );
      } else {
         loosePPIso()->clear();
      }
      if( parent.m.IsAvailable() ) {
         *( m() ) = *( parent.m() );
      } else {
         m()->clear();
      }
      if( parent.massPixeldEdx.IsAvailable() ) {
         *( massPixeldEdx() ) = *( parent.massPixeldEdx() );
      } else {
         massPixeldEdx()->clear();
      }
      if( parent.medium.IsAvailable() ) {
         *( medium() ) = *( parent.medium() );
      } else {
         medium()->clear();
      }
      if( parent.mediumIso.IsAvailable() ) {
         *( mediumIso() ) = *( parent.mediumIso() );
      } else {
         mediumIso()->clear();
      }
      if( parent.mediumIsoWithoutTrack.IsAvailable() ) {
         *( mediumIsoWithoutTrack() ) = *( parent.mediumIsoWithoutTrack() );
      } else {
         mediumIsoWithoutTrack()->clear();
      }
      if( parent.mediumPP.IsAvailable() ) {
         *( mediumPP() ) = *( parent.mediumPP() );
      } else {
         mediumPP()->clear();
      }
      if( parent.mediumPPIso.IsAvailable() ) {
         *( mediumPPIso() ) = *( parent.mediumPPIso() );
      } else {
         mediumPPIso()->clear();
      }
      if( parent.mediumWithoutTrack.IsAvailable() ) {
         *( mediumWithoutTrack() ) = *( parent.mediumWithoutTrack() );
      } else {
         mediumWithoutTrack()->clear();
      }
      if( parent.mvaptcone20.IsAvailable() ) {
         *( mvaptcone20() ) = *( parent.mvaptcone20() );
      } else {
         mvaptcone20()->clear();
      }
      if( parent.mvaptcone30.IsAvailable() ) {
         *( mvaptcone30() ) = *( parent.mvaptcone30() );
      } else {
         mvaptcone30()->clear();
      }
      if( parent.mvaptcone40.IsAvailable() ) {
         *( mvaptcone40() ) = *( parent.mvaptcone40() );
      } else {
         mvaptcone40()->clear();
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
      if( parent.nBLayerOutliers.IsAvailable() ) {
         *( nBLayerOutliers() ) = *( parent.nBLayerOutliers() );
      } else {
         nBLayerOutliers()->clear();
      }
      if( parent.nBLayerSplitHits.IsAvailable() ) {
         *( nBLayerSplitHits() ) = *( parent.nBLayerSplitHits() );
      } else {
         nBLayerSplitHits()->clear();
      }
      if( parent.nContribPixelLayers.IsAvailable() ) {
         *( nContribPixelLayers() ) = *( parent.nContribPixelLayers() );
      } else {
         nContribPixelLayers()->clear();
      }
      if( parent.nConv.IsAvailable() ) {
         *( nConv() ) = *( parent.nConv() );
      } else {
         nConv()->clear();
      }
      if( parent.nDoubleTrackConv.IsAvailable() ) {
         *( nDoubleTrackConv() ) = *( parent.nDoubleTrackConv() );
      } else {
         nDoubleTrackConv()->clear();
      }
      if( parent.nGangedFlaggedFakes.IsAvailable() ) {
         *( nGangedFlaggedFakes() ) = *( parent.nGangedFlaggedFakes() );
      } else {
         nGangedFlaggedFakes()->clear();
      }
      if( parent.nGangedPixels.IsAvailable() ) {
         *( nGangedPixels() ) = *( parent.nGangedPixels() );
      } else {
         nGangedPixels()->clear();
      }
      if( parent.nGoodHitsPixeldEdx.IsAvailable() ) {
         *( nGoodHitsPixeldEdx() ) = *( parent.nGoodHitsPixeldEdx() );
      } else {
         nGoodHitsPixeldEdx()->clear();
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
      if( parent.nPixSplitHits.IsAvailable() ) {
         *( nPixSplitHits() ) = *( parent.nPixSplitHits() );
      } else {
         nPixSplitHits()->clear();
      }
      if( parent.nPixelDeadSensors.IsAvailable() ) {
         *( nPixelDeadSensors() ) = *( parent.nPixelDeadSensors() );
      } else {
         nPixelDeadSensors()->clear();
      }
      if( parent.nPixelOutliers.IsAvailable() ) {
         *( nPixelOutliers() ) = *( parent.nPixelOutliers() );
      } else {
         nPixelOutliers()->clear();
      }
      if( parent.nPixelSpoiltHits.IsAvailable() ) {
         *( nPixelSpoiltHits() ) = *( parent.nPixelSpoiltHits() );
      } else {
         nPixelSpoiltHits()->clear();
      }
      if( parent.nSCTDeadSensors.IsAvailable() ) {
         *( nSCTDeadSensors() ) = *( parent.nSCTDeadSensors() );
      } else {
         nSCTDeadSensors()->clear();
      }
      if( parent.nSCTDoubleHoles.IsAvailable() ) {
         *( nSCTDoubleHoles() ) = *( parent.nSCTDoubleHoles() );
      } else {
         nSCTDoubleHoles()->clear();
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
      if( parent.nSCTOutliers.IsAvailable() ) {
         *( nSCTOutliers() ) = *( parent.nSCTOutliers() );
      } else {
         nSCTOutliers()->clear();
      }
      if( parent.nSCTSharedHits.IsAvailable() ) {
         *( nSCTSharedHits() ) = *( parent.nSCTSharedHits() );
      } else {
         nSCTSharedHits()->clear();
      }
      if( parent.nSCTSpoiltHits.IsAvailable() ) {
         *( nSCTSpoiltHits() ) = *( parent.nSCTSpoiltHits() );
      } else {
         nSCTSpoiltHits()->clear();
      }
      if( parent.nSiHits.IsAvailable() ) {
         *( nSiHits() ) = *( parent.nSiHits() );
      } else {
         nSiHits()->clear();
      }
      if( parent.nSingleTrackConv.IsAvailable() ) {
         *( nSingleTrackConv() ) = *( parent.nSingleTrackConv() );
      } else {
         nSingleTrackConv()->clear();
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
      if( parent.nTRTHoles.IsAvailable() ) {
         *( nTRTHoles() ) = *( parent.nTRTHoles() );
      } else {
         nTRTHoles()->clear();
      }
      if( parent.nTRTOutliers.IsAvailable() ) {
         *( nTRTOutliers() ) = *( parent.nTRTOutliers() );
      } else {
         nTRTOutliers()->clear();
      }
      if( parent.neuralnet.IsAvailable() ) {
         *( neuralnet() ) = *( parent.neuralnet() );
      } else {
         neuralnet()->clear();
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
      if( parent.originbkg.IsAvailable() ) {
         *( originbkg() ) = *( parent.originbkg() );
      } else {
         originbkg()->clear();
      }
      if( parent.phi.IsAvailable() ) {
         *( phi() ) = *( parent.phi() );
      } else {
         phi()->clear();
      }
      if( parent.phis0.IsAvailable() ) {
         *( phis0() ) = *( parent.phis0() );
      } else {
         phis0()->clear();
      }
      if( parent.phis1.IsAvailable() ) {
         *( phis1() ) = *( parent.phis1() );
      } else {
         phis1()->clear();
      }
      if( parent.phis2.IsAvailable() ) {
         *( phis2() ) = *( parent.phis2() );
      } else {
         phis2()->clear();
      }
      if( parent.phis3.IsAvailable() ) {
         *( phis3() ) = *( parent.phis3() );
      } else {
         phis3()->clear();
      }
      if( parent.pixeldEdx.IsAvailable() ) {
         *( pixeldEdx() ) = *( parent.pixeldEdx() );
      } else {
         pixeldEdx()->clear();
      }
      if( parent.pos7.IsAvailable() ) {
         *( pos7() ) = *( parent.pos7() );
      } else {
         pos7()->clear();
      }
      if( parent.pt.IsAvailable() ) {
         *( pt() ) = *( parent.pt() );
      } else {
         pt()->clear();
      }
      if( parent.pt1conv.IsAvailable() ) {
         *( pt1conv() ) = *( parent.pt1conv() );
      } else {
         pt1conv()->clear();
      }
      if( parent.pt2conv.IsAvailable() ) {
         *( pt2conv() ) = *( parent.pt2conv() );
      } else {
         pt2conv()->clear();
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
      if( parent.ptconv.IsAvailable() ) {
         *( ptconv() ) = *( parent.ptconv() );
      } else {
         ptconv()->clear();
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
      if( parent.pzconv.IsAvailable() ) {
         *( pzconv() ) = *( parent.pzconv() );
      } else {
         pzconv()->clear();
      }
      if( parent.rawcl_E.IsAvailable() ) {
         *( rawcl_E() ) = *( parent.rawcl_E() );
      } else {
         rawcl_E()->clear();
      }
      if( parent.rawcl_Es0.IsAvailable() ) {
         *( rawcl_Es0() ) = *( parent.rawcl_Es0() );
      } else {
         rawcl_Es0()->clear();
      }
      if( parent.rawcl_Es1.IsAvailable() ) {
         *( rawcl_Es1() ) = *( parent.rawcl_Es1() );
      } else {
         rawcl_Es1()->clear();
      }
      if( parent.rawcl_Es2.IsAvailable() ) {
         *( rawcl_Es2() ) = *( parent.rawcl_Es2() );
      } else {
         rawcl_Es2()->clear();
      }
      if( parent.rawcl_Es3.IsAvailable() ) {
         *( rawcl_Es3() ) = *( parent.rawcl_Es3() );
      } else {
         rawcl_Es3()->clear();
      }
      if( parent.rawcl_eta.IsAvailable() ) {
         *( rawcl_eta() ) = *( parent.rawcl_eta() );
      } else {
         rawcl_eta()->clear();
      }
      if( parent.rawcl_etas0.IsAvailable() ) {
         *( rawcl_etas0() ) = *( parent.rawcl_etas0() );
      } else {
         rawcl_etas0()->clear();
      }
      if( parent.rawcl_etas1.IsAvailable() ) {
         *( rawcl_etas1() ) = *( parent.rawcl_etas1() );
      } else {
         rawcl_etas1()->clear();
      }
      if( parent.rawcl_etas2.IsAvailable() ) {
         *( rawcl_etas2() ) = *( parent.rawcl_etas2() );
      } else {
         rawcl_etas2()->clear();
      }
      if( parent.rawcl_etas3.IsAvailable() ) {
         *( rawcl_etas3() ) = *( parent.rawcl_etas3() );
      } else {
         rawcl_etas3()->clear();
      }
      if( parent.rawcl_phi.IsAvailable() ) {
         *( rawcl_phi() ) = *( parent.rawcl_phi() );
      } else {
         rawcl_phi()->clear();
      }
      if( parent.rawcl_phis0.IsAvailable() ) {
         *( rawcl_phis0() ) = *( parent.rawcl_phis0() );
      } else {
         rawcl_phis0()->clear();
      }
      if( parent.rawcl_phis1.IsAvailable() ) {
         *( rawcl_phis1() ) = *( parent.rawcl_phis1() );
      } else {
         rawcl_phis1()->clear();
      }
      if( parent.rawcl_phis2.IsAvailable() ) {
         *( rawcl_phis2() ) = *( parent.rawcl_phis2() );
      } else {
         rawcl_phis2()->clear();
      }
      if( parent.rawcl_phis3.IsAvailable() ) {
         *( rawcl_phis3() ) = *( parent.rawcl_phis3() );
      } else {
         rawcl_phis3()->clear();
      }
      if( parent.rawcl_pt.IsAvailable() ) {
         *( rawcl_pt() ) = *( parent.rawcl_pt() );
      } else {
         rawcl_pt()->clear();
      }
      if( parent.cl_etaCalo.IsAvailable() ) {
         *( cl_etaCalo() ) = *( parent.cl_etaCalo() );
      } else {
         cl_etaCalo()->clear();
      }
      if( parent.cl_etaCalo.IsAvailable() ) {
         *( cl_etaCalo() ) = *( parent.cl_etaCalo() );
      } else {
         cl_etaCalo()->clear();
      }
      if( parent.refittedTrack_LMqoverp.IsAvailable() ) {
         *( refittedTrack_LMqoverp() ) = *( parent.refittedTrack_LMqoverp() );
      } else {
         refittedTrack_LMqoverp()->clear();
      }
      if( parent.refittedTrack_author.IsAvailable() ) {
         *( refittedTrack_author() ) = *( parent.refittedTrack_author() );
      } else {
         refittedTrack_author()->clear();
      }
      if( parent.refittedTrack_bremFitStatus.IsAvailable() ) {
         *( refittedTrack_bremFitStatus() ) = *( parent.refittedTrack_bremFitStatus() );
      } else {
         refittedTrack_bremFitStatus()->clear();
      }
      if( parent.refittedTrack_bremRadius.IsAvailable() ) {
         *( refittedTrack_bremRadius() ) = *( parent.refittedTrack_bremRadius() );
      } else {
         refittedTrack_bremRadius()->clear();
      }
      if( parent.refittedTrack_bremRadiusErr.IsAvailable() ) {
         *( refittedTrack_bremRadiusErr() ) = *( parent.refittedTrack_bremRadiusErr() );
      } else {
         refittedTrack_bremRadiusErr()->clear();
      }
      if( parent.refittedTrack_bremZ.IsAvailable() ) {
         *( refittedTrack_bremZ() ) = *( parent.refittedTrack_bremZ() );
      } else {
         refittedTrack_bremZ()->clear();
      }
      if( parent.refittedTrack_bremZErr.IsAvailable() ) {
         *( refittedTrack_bremZErr() ) = *( parent.refittedTrack_bremZErr() );
      } else {
         refittedTrack_bremZErr()->clear();
      }
      if( parent.refittedTrack_chi2.IsAvailable() ) {
         *( refittedTrack_chi2() ) = *( parent.refittedTrack_chi2() );
      } else {
         refittedTrack_chi2()->clear();
      }
      if( parent.refittedTrack_covd0.IsAvailable() ) {
         *( refittedTrack_covd0() ) = *( parent.refittedTrack_covd0() );
      } else {
         refittedTrack_covd0()->clear();
      }
      if( parent.refittedTrack_covd0phi.IsAvailable() ) {
         *( refittedTrack_covd0phi() ) = *( parent.refittedTrack_covd0phi() );
      } else {
         refittedTrack_covd0phi()->clear();
      }
      if( parent.refittedTrack_covd0qoverp.IsAvailable() ) {
         *( refittedTrack_covd0qoverp() ) = *( parent.refittedTrack_covd0qoverp() );
      } else {
         refittedTrack_covd0qoverp()->clear();
      }
      if( parent.refittedTrack_covd0theta.IsAvailable() ) {
         *( refittedTrack_covd0theta() ) = *( parent.refittedTrack_covd0theta() );
      } else {
         refittedTrack_covd0theta()->clear();
      }
      if( parent.refittedTrack_covd0z0.IsAvailable() ) {
         *( refittedTrack_covd0z0() ) = *( parent.refittedTrack_covd0z0() );
      } else {
         refittedTrack_covd0z0()->clear();
      }
      if( parent.refittedTrack_covphi.IsAvailable() ) {
         *( refittedTrack_covphi() ) = *( parent.refittedTrack_covphi() );
      } else {
         refittedTrack_covphi()->clear();
      }
      if( parent.refittedTrack_covphiqoverp.IsAvailable() ) {
         *( refittedTrack_covphiqoverp() ) = *( parent.refittedTrack_covphiqoverp() );
      } else {
         refittedTrack_covphiqoverp()->clear();
      }
      if( parent.refittedTrack_covphitheta.IsAvailable() ) {
         *( refittedTrack_covphitheta() ) = *( parent.refittedTrack_covphitheta() );
      } else {
         refittedTrack_covphitheta()->clear();
      }
      if( parent.refittedTrack_covqoverp.IsAvailable() ) {
         *( refittedTrack_covqoverp() ) = *( parent.refittedTrack_covqoverp() );
      } else {
         refittedTrack_covqoverp()->clear();
      }
      if( parent.refittedTrack_covtheta.IsAvailable() ) {
         *( refittedTrack_covtheta() ) = *( parent.refittedTrack_covtheta() );
      } else {
         refittedTrack_covtheta()->clear();
      }
      if( parent.refittedTrack_covthetaqoverp.IsAvailable() ) {
         *( refittedTrack_covthetaqoverp() ) = *( parent.refittedTrack_covthetaqoverp() );
      } else {
         refittedTrack_covthetaqoverp()->clear();
      }
      if( parent.refittedTrack_covz0.IsAvailable() ) {
         *( refittedTrack_covz0() ) = *( parent.refittedTrack_covz0() );
      } else {
         refittedTrack_covz0()->clear();
      }
      if( parent.refittedTrack_covz0phi.IsAvailable() ) {
         *( refittedTrack_covz0phi() ) = *( parent.refittedTrack_covz0phi() );
      } else {
         refittedTrack_covz0phi()->clear();
      }
      if( parent.refittedTrack_covz0qoverp.IsAvailable() ) {
         *( refittedTrack_covz0qoverp() ) = *( parent.refittedTrack_covz0qoverp() );
      } else {
         refittedTrack_covz0qoverp()->clear();
      }
      if( parent.refittedTrack_covz0theta.IsAvailable() ) {
         *( refittedTrack_covz0theta() ) = *( parent.refittedTrack_covz0theta() );
      } else {
         refittedTrack_covz0theta()->clear();
      }
      if( parent.refittedTrack_d0.IsAvailable() ) {
         *( refittedTrack_d0() ) = *( parent.refittedTrack_d0() );
      } else {
         refittedTrack_d0()->clear();
      }
      if( parent.refittedTrack_hasBrem.IsAvailable() ) {
         *( refittedTrack_hasBrem() ) = *( parent.refittedTrack_hasBrem() );
      } else {
         refittedTrack_hasBrem()->clear();
      }
      if( parent.refittedTrack_n.IsAvailable() ) {
         *( refittedTrack_n() ) = *( parent.refittedTrack_n() );
      } else {
         refittedTrack_n()->clear();
      }
      if( parent.refittedTrack_phi.IsAvailable() ) {
         *( refittedTrack_phi() ) = *( parent.refittedTrack_phi() );
      } else {
         refittedTrack_phi()->clear();
      }
      if( parent.refittedTrack_qoverp.IsAvailable() ) {
         *( refittedTrack_qoverp() ) = *( parent.refittedTrack_qoverp() );
      } else {
         refittedTrack_qoverp()->clear();
      }
      if( parent.refittedTrack_theta.IsAvailable() ) {
         *( refittedTrack_theta() ) = *( parent.refittedTrack_theta() );
      } else {
         refittedTrack_theta()->clear();
      }
      if( parent.refittedTrack_z0.IsAvailable() ) {
         *( refittedTrack_z0() ) = *( parent.refittedTrack_z0() );
      } else {
         refittedTrack_z0()->clear();
      }
      if( parent.reta.IsAvailable() ) {
         *( reta() ) = *( parent.reta() );
      } else {
         reta()->clear();
      }
      if( parent.ringernn.IsAvailable() ) {
         *( ringernn() ) = *( parent.ringernn() );
      } else {
         ringernn()->clear();
      }
      if( parent.rings_E.IsAvailable() ) {
         *( rings_E() ) = *( parent.rings_E() );
      } else {
         rings_E()->clear();
      }
      if( parent.rphi.IsAvailable() ) {
         *( rphi() ) = *( parent.rphi() );
      } else {
         rphi()->clear();
      }
      if( parent.rphiallcalo.IsAvailable() ) {
         *( rphiallcalo() ) = *( parent.rphiallcalo() );
      } else {
         rphiallcalo()->clear();
      }
      if( parent.secondR.IsAvailable() ) {
         *( secondR() ) = *( parent.secondR() );
      } else {
         secondR()->clear();
      }
      if( parent.secondlambda.IsAvailable() ) {
         *( secondlambda() ) = *( parent.secondlambda() );
      } else {
         secondlambda()->clear();
      }
      if( parent.softebgweight.IsAvailable() ) {
         *( softebgweight() ) = *( parent.softebgweight() );
      } else {
         softebgweight()->clear();
      }
      if( parent.softeneuralnet.IsAvailable() ) {
         *( softeneuralnet() ) = *( parent.softeneuralnet() );
      } else {
         softeneuralnet()->clear();
      }
      if( parent.softeweight.IsAvailable() ) {
         *( softeweight() ) = *( parent.softeweight() );
      } else {
         softeweight()->clear();
      }
      if( parent.tight.IsAvailable() ) {
         *( tight() ) = *( parent.tight() );
      } else {
         tight()->clear();
      }
      if( parent.tightIso.IsAvailable() ) {
         *( tightIso() ) = *( parent.tightIso() );
      } else {
         tightIso()->clear();
      }
      if( parent.tightIsoWithoutTrack.IsAvailable() ) {
         *( tightIsoWithoutTrack() ) = *( parent.tightIsoWithoutTrack() );
      } else {
         tightIsoWithoutTrack()->clear();
      }
      if( parent.tightPP.IsAvailable() ) {
         *( tightPP() ) = *( parent.tightPP() );
      } else {
         tightPP()->clear();
      }
      if( parent.tightPPIso.IsAvailable() ) {
         *( tightPPIso() ) = *( parent.tightPPIso() );
      } else {
         tightPPIso()->clear();
      }
      if( parent.tightWithoutTrack.IsAvailable() ) {
         *( tightWithoutTrack() ) = *( parent.tightWithoutTrack() );
      } else {
         tightWithoutTrack()->clear();
      }
      if( parent.topoEtcone20.IsAvailable() ) {
         *( topoEtcone20() ) = *( parent.topoEtcone20() );
      } else {
         topoEtcone20()->clear();
      }
      if( parent.topoEtcone20_corrected.IsAvailable() ) {
         *( topoEtcone20_corrected() ) = *( parent.topoEtcone20_corrected() );
      } else {
         topoEtcone20_corrected()->clear();
      }
      if( parent.topoEtcone30.IsAvailable() ) {
         *( topoEtcone30() ) = *( parent.topoEtcone30() );
      } else {
         topoEtcone30()->clear();
      }
      if( parent.topoEtcone30_corrected.IsAvailable() ) {
         *( topoEtcone30_corrected() ) = *( parent.topoEtcone30_corrected() );
      } else {
         topoEtcone30_corrected()->clear();
      }
      if( parent.topoEtcone40.IsAvailable() ) {
         *( topoEtcone40() ) = *( parent.topoEtcone40() );
      } else {
         topoEtcone40()->clear();
      }
      if( parent.topoEtcone40_corrected.IsAvailable() ) {
         *( topoEtcone40_corrected() ) = *( parent.topoEtcone40_corrected() );
      } else {
         topoEtcone40_corrected()->clear();
      }
      if( parent.topoEtcone60.IsAvailable() ) {
         *( topoEtcone60() ) = *( parent.topoEtcone60() );
      } else {
         topoEtcone60()->clear();
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
      if( parent.trackd0_physics.IsAvailable() ) {
         *( trackd0_physics() ) = *( parent.trackd0_physics() );
      } else {
         trackd0_physics()->clear();
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
      if( parent.tracketa.IsAvailable() ) {
         *( tracketa() ) = *( parent.tracketa() );
      } else {
         tracketa()->clear();
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
      if( parent.trackpt.IsAvailable() ) {
         *( trackpt() ) = *( parent.trackpt() );
      } else {
         trackpt()->clear();
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
      if( parent.truth_bremLoc.IsAvailable() ) {
         *( truth_bremLoc() ) = *( parent.truth_bremLoc() );
      } else {
         truth_bremLoc()->clear();
      }
      if( parent.truth_bremSi.IsAvailable() ) {
         *( truth_bremSi() ) = *( parent.truth_bremSi() );
      } else {
         truth_bremSi()->clear();
      }
      if( parent.truth_eta.IsAvailable() ) {
         *( truth_eta() ) = *( parent.truth_eta() );
      } else {
         truth_eta()->clear();
      }
      if( parent.truth_hasHardBrem.IsAvailable() ) {
         *( truth_hasHardBrem() ) = *( parent.truth_hasHardBrem() );
      } else {
         truth_hasHardBrem()->clear();
      }
      if( parent.truth_index.IsAvailable() ) {
         *( truth_index() ) = *( parent.truth_index() );
      } else {
         truth_index()->clear();
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
      if( parent.truth_sumbrem.IsAvailable() ) {
         *( truth_sumbrem() ) = *( parent.truth_sumbrem() );
      } else {
         truth_sumbrem()->clear();
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
      if( parent.typebkg.IsAvailable() ) {
         *( typebkg() ) = *( parent.typebkg() );
      } else {
         typebkg()->clear();
      }
      if( parent.vertweight.IsAvailable() ) {
         *( vertweight() ) = *( parent.vertweight() );
      } else {
         vertweight()->clear();
      }
      if( parent.vertx.IsAvailable() ) {
         *( vertx() ) = *( parent.vertx() );
      } else {
         vertx()->clear();
      }
      if( parent.verty.IsAvailable() ) {
         *( verty() ) = *( parent.verty() );
      } else {
         verty()->clear();
      }
      if( parent.vertz.IsAvailable() ) {
         *( vertz() ) = *( parent.vertz() );
      } else {
         vertz()->clear();
      }
      if( parent.weta2.IsAvailable() ) {
         *( weta2() ) = *( parent.weta2() );
      } else {
         weta2()->clear();
      }
      if( parent.ws3.IsAvailable() ) {
         *( ws3() ) = *( parent.ws3() );
      } else {
         ws3()->clear();
      }
      if( parent.wstot.IsAvailable() ) {
         *( wstot() ) = *( parent.wstot() );
      } else {
         wstot()->clear();
      }
      if( parent.zconv.IsAvailable() ) {
         *( zconv() ) = *( parent.zconv() );
      } else {
         zconv()->clear();
      }
      if( parent.zvertex.IsAvailable() ) {
         *( zvertex() ) = *( parent.zvertex() );
      } else {
         zvertex()->clear();
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
   void ElectronD3PDObject::Clear( Option_t* ) {

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
   ElectronD3PDObject& ElectronD3PDObject::Add( const ElectronD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( el.CaloPointing_eta.IsAvailable() ) {
         CaloPointing_eta()->push_back( el.CaloPointing_eta() );
      } else {
         CaloPointing_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.CaloPointing_sigma_eta.IsAvailable() ) {
         CaloPointing_sigma_eta()->push_back( el.CaloPointing_sigma_eta() );
      } else {
         CaloPointing_sigma_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.CaloPointing_sigma_zvertex.IsAvailable() ) {
         CaloPointing_sigma_zvertex()->push_back( el.CaloPointing_sigma_zvertex() );
      } else {
         CaloPointing_sigma_zvertex()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.CaloPointing_zvertex.IsAvailable() ) {
         CaloPointing_zvertex()->push_back( el.CaloPointing_zvertex() );
      } else {
         CaloPointing_zvertex()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E.IsAvailable() ) {
         E()->push_back( el.E() );
      } else {
         E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E233.IsAvailable() ) {
         E233()->push_back( el.E233() );
      } else {
         E233()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E237.IsAvailable() ) {
         E237()->push_back( el.E237() );
      } else {
         E237()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E277.IsAvailable() ) {
         E277()->push_back( el.E277() );
      } else {
         E277()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ED_Njets.IsAvailable() ) {
         ED_Njets()->push_back( el.ED_Njets() );
      } else {
         ED_Njets()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ED_median.IsAvailable() ) {
         ED_median()->push_back( el.ED_median() );
      } else {
         ED_median()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ED_sigma.IsAvailable() ) {
         ED_sigma()->push_back( el.ED_sigma() );
      } else {
         ED_sigma()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_dr.IsAvailable() ) {
         EF_dr()->push_back( el.EF_dr() );
      } else {
         EF_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_index.IsAvailable() ) {
         EF_index()->push_back( el.EF_index() );
      } else {
         EF_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ES0_real.IsAvailable() ) {
         ES0_real()->push_back( el.ES0_real() );
      } else {
         ES0_real()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ES1_real.IsAvailable() ) {
         ES1_real()->push_back( el.ES1_real() );
      } else {
         ES1_real()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ES2_real.IsAvailable() ) {
         ES2_real()->push_back( el.ES2_real() );
      } else {
         ES2_real()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ES3_real.IsAvailable() ) {
         ES3_real()->push_back( el.ES3_real() );
      } else {
         ES3_real()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_EMB1.IsAvailable() ) {
         E_EMB1()->push_back( el.E_EMB1() );
      } else {
         E_EMB1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_EMB2.IsAvailable() ) {
         E_EMB2()->push_back( el.E_EMB2() );
      } else {
         E_EMB2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_EMB3.IsAvailable() ) {
         E_EMB3()->push_back( el.E_EMB3() );
      } else {
         E_EMB3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_EME1.IsAvailable() ) {
         E_EME1()->push_back( el.E_EME1() );
      } else {
         E_EME1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_EME2.IsAvailable() ) {
         E_EME2()->push_back( el.E_EME2() );
      } else {
         E_EME2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_EME3.IsAvailable() ) {
         E_EME3()->push_back( el.E_EME3() );
      } else {
         E_EME3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_FCAL0.IsAvailable() ) {
         E_FCAL0()->push_back( el.E_FCAL0() );
      } else {
         E_FCAL0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_FCAL1.IsAvailable() ) {
         E_FCAL1()->push_back( el.E_FCAL1() );
      } else {
         E_FCAL1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_FCAL2.IsAvailable() ) {
         E_FCAL2()->push_back( el.E_FCAL2() );
      } else {
         E_FCAL2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_HEC0.IsAvailable() ) {
         E_HEC0()->push_back( el.E_HEC0() );
      } else {
         E_HEC0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_HEC1.IsAvailable() ) {
         E_HEC1()->push_back( el.E_HEC1() );
      } else {
         E_HEC1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_HEC2.IsAvailable() ) {
         E_HEC2()->push_back( el.E_HEC2() );
      } else {
         E_HEC2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_HEC3.IsAvailable() ) {
         E_HEC3()->push_back( el.E_HEC3() );
      } else {
         E_HEC3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_PreSamplerB.IsAvailable() ) {
         E_PreSamplerB()->push_back( el.E_PreSamplerB() );
      } else {
         E_PreSamplerB()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_PreSamplerE.IsAvailable() ) {
         E_PreSamplerE()->push_back( el.E_PreSamplerE() );
      } else {
         E_PreSamplerE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_TileBar0.IsAvailable() ) {
         E_TileBar0()->push_back( el.E_TileBar0() );
      } else {
         E_TileBar0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_TileBar1.IsAvailable() ) {
         E_TileBar1()->push_back( el.E_TileBar1() );
      } else {
         E_TileBar1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_TileBar2.IsAvailable() ) {
         E_TileBar2()->push_back( el.E_TileBar2() );
      } else {
         E_TileBar2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_TileExt0.IsAvailable() ) {
         E_TileExt0()->push_back( el.E_TileExt0() );
      } else {
         E_TileExt0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_TileExt1.IsAvailable() ) {
         E_TileExt1()->push_back( el.E_TileExt1() );
      } else {
         E_TileExt1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_TileExt2.IsAvailable() ) {
         E_TileExt2()->push_back( el.E_TileExt2() );
      } else {
         E_TileExt2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_TileGap1.IsAvailable() ) {
         E_TileGap1()->push_back( el.E_TileGap1() );
      } else {
         E_TileGap1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_TileGap2.IsAvailable() ) {
         E_TileGap2()->push_back( el.E_TileGap2() );
      } else {
         E_TileGap2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E_TileGap3.IsAvailable() ) {
         E_TileGap3()->push_back( el.E_TileGap3() );
      } else {
         E_TileGap3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EcellS0.IsAvailable() ) {
         EcellS0()->push_back( el.EcellS0() );
      } else {
         EcellS0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Emax2.IsAvailable() ) {
         Emax2()->push_back( el.Emax2() );
      } else {
         Emax2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Emins1.IsAvailable() ) {
         Emins1()->push_back( el.Emins1() );
      } else {
         Emins1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Es0.IsAvailable() ) {
         Es0()->push_back( el.Es0() );
      } else {
         Es0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Es1.IsAvailable() ) {
         Es1()->push_back( el.Es1() );
      } else {
         Es1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Es2.IsAvailable() ) {
         Es2()->push_back( el.Es2() );
      } else {
         Es2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Es3.IsAvailable() ) {
         Es3()->push_back( el.Es3() );
      } else {
         Es3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Et.IsAvailable() ) {
         Et()->push_back( el.Et() );
      } else {
         Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone15.IsAvailable() ) {
         Etcone15()->push_back( el.Etcone15() );
      } else {
         Etcone15()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone15_pt_corrected.IsAvailable() ) {
         Etcone15_pt_corrected()->push_back( el.Etcone15_pt_corrected() );
      } else {
         Etcone15_pt_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone20.IsAvailable() ) {
         Etcone20()->push_back( el.Etcone20() );
      } else {
         Etcone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone20_pt_corrected.IsAvailable() ) {
         Etcone20_pt_corrected()->push_back( el.Etcone20_pt_corrected() );
      } else {
         Etcone20_pt_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone25.IsAvailable() ) {
         Etcone25()->push_back( el.Etcone25() );
      } else {
         Etcone25()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone25_pt_corrected.IsAvailable() ) {
         Etcone25_pt_corrected()->push_back( el.Etcone25_pt_corrected() );
      } else {
         Etcone25_pt_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone30.IsAvailable() ) {
         Etcone30()->push_back( el.Etcone30() );
      } else {
         Etcone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone30_pt_corrected.IsAvailable() ) {
         Etcone30_pt_corrected()->push_back( el.Etcone30_pt_corrected() );
      } else {
         Etcone30_pt_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone35.IsAvailable() ) {
         Etcone35()->push_back( el.Etcone35() );
      } else {
         Etcone35()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone35_pt_corrected.IsAvailable() ) {
         Etcone35_pt_corrected()->push_back( el.Etcone35_pt_corrected() );
      } else {
         Etcone35_pt_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone40.IsAvailable() ) {
         Etcone40()->push_back( el.Etcone40() );
      } else {
         Etcone40()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone40_ED_corrected.IsAvailable() ) {
         Etcone40_ED_corrected()->push_back( el.Etcone40_ED_corrected() );
      } else {
         Etcone40_ED_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone40_corrected.IsAvailable() ) {
         Etcone40_corrected()->push_back( el.Etcone40_corrected() );
      } else {
         Etcone40_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone40_pt_corrected.IsAvailable() ) {
         Etcone40_pt_corrected()->push_back( el.Etcone40_pt_corrected() );
      } else {
         Etcone40_pt_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone45.IsAvailable() ) {
         Etcone45()->push_back( el.Etcone45() );
      } else {
         Etcone45()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Ethad.IsAvailable() ) {
         Ethad()->push_back( el.Ethad() );
      } else {
         Ethad()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Ethad1.IsAvailable() ) {
         Ethad1()->push_back( el.Ethad1() );
      } else {
         Ethad1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EtringnoisedR03sig2.IsAvailable() ) {
         EtringnoisedR03sig2()->push_back( el.EtringnoisedR03sig2() );
      } else {
         EtringnoisedR03sig2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EtringnoisedR03sig3.IsAvailable() ) {
         EtringnoisedR03sig3()->push_back( el.EtringnoisedR03sig3() );
      } else {
         EtringnoisedR03sig3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EtringnoisedR03sig4.IsAvailable() ) {
         EtringnoisedR03sig4()->push_back( el.EtringnoisedR03sig4() );
      } else {
         EtringnoisedR03sig4()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.HPV_eta.IsAvailable() ) {
         HPV_eta()->push_back( el.HPV_eta() );
      } else {
         HPV_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.HPV_sigma_eta.IsAvailable() ) {
         HPV_sigma_eta()->push_back( el.HPV_sigma_eta() );
      } else {
         HPV_sigma_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.HPV_sigma_zvertex.IsAvailable() ) {
         HPV_sigma_zvertex()->push_back( el.HPV_sigma_zvertex() );
      } else {
         HPV_sigma_zvertex()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.HPV_zvertex.IsAvailable() ) {
         HPV_zvertex()->push_back( el.HPV_zvertex() );
      } else {
         HPV_zvertex()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Hmatrix.IsAvailable() ) {
         Hmatrix()->push_back( el.Hmatrix() );
      } else {
         Hmatrix()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.Hmatrix5.IsAvailable() ) {
         Hmatrix5()->push_back( el.Hmatrix5() );
      } else {
         Hmatrix5()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.OQ.IsAvailable() ) {
         OQ()->push_back( el.OQ() );
      } else {
         OQ()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.Rconv.IsAvailable() ) {
         Rconv()->push_back( el.Rconv() );
      } else {
         Rconv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.TRTHighTHitsRatio.IsAvailable() ) {
         TRTHighTHitsRatio()->push_back( el.TRTHighTHitsRatio() );
      } else {
         TRTHighTHitsRatio()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.TRTHighTOutliersRatio.IsAvailable() ) {
         TRTHighTOutliersRatio()->push_back( el.TRTHighTOutliersRatio() );
      } else {
         TRTHighTOutliersRatio()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Unrefittedtrack_d0.IsAvailable() ) {
         Unrefittedtrack_d0()->push_back( el.Unrefittedtrack_d0() );
      } else {
         Unrefittedtrack_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Unrefittedtrack_eta.IsAvailable() ) {
         Unrefittedtrack_eta()->push_back( el.Unrefittedtrack_eta() );
      } else {
         Unrefittedtrack_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Unrefittedtrack_phi.IsAvailable() ) {
         Unrefittedtrack_phi()->push_back( el.Unrefittedtrack_phi() );
      } else {
         Unrefittedtrack_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Unrefittedtrack_pt.IsAvailable() ) {
         Unrefittedtrack_pt()->push_back( el.Unrefittedtrack_pt() );
      } else {
         Unrefittedtrack_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Unrefittedtrack_qoverp.IsAvailable() ) {
         Unrefittedtrack_qoverp()->push_back( el.Unrefittedtrack_qoverp() );
      } else {
         Unrefittedtrack_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Unrefittedtrack_theta.IsAvailable() ) {
         Unrefittedtrack_theta()->push_back( el.Unrefittedtrack_theta() );
      } else {
         Unrefittedtrack_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Unrefittedtrack_z0.IsAvailable() ) {
         Unrefittedtrack_z0()->push_back( el.Unrefittedtrack_z0() );
      } else {
         Unrefittedtrack_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.adaboost.IsAvailable() ) {
         adaboost()->push_back( el.adaboost() );
      } else {
         adaboost()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.author.IsAvailable() ) {
         author()->push_back( el.author() );
      } else {
         author()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.calibHitsShowerDepth.IsAvailable() ) {
         calibHitsShowerDepth()->push_back( el.calibHitsShowerDepth() );
      } else {
         calibHitsShowerDepth()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellmaxfrac.IsAvailable() ) {
         cellmaxfrac()->push_back( el.cellmaxfrac() );
      } else {
         cellmaxfrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.centerlambda.IsAvailable() ) {
         centerlambda()->push_back( el.centerlambda() );
      } else {
         centerlambda()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.charge.IsAvailable() ) {
         charge()->push_back( el.charge() );
      } else {
         charge()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cl_E.IsAvailable() ) {
         cl_E()->push_back( el.cl_E() );
      } else {
         cl_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cl_eta.IsAvailable() ) {
         cl_eta()->push_back( el.cl_eta() );
      } else {
         cl_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cl_phi.IsAvailable() ) {
         cl_phi()->push_back( el.cl_phi() );
      } else {
         cl_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cl_pt.IsAvailable() ) {
         cl_pt()->push_back( el.cl_pt() );
      } else {
         cl_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convFlag.IsAvailable() ) {
         convFlag()->push_back( el.convFlag() );
      } else {
         convFlag()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convanglematch.IsAvailable() ) {
         convanglematch()->push_back( el.convanglematch() );
      } else {
         convanglematch()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convtrackmatch.IsAvailable() ) {
         convtrackmatch()->push_back( el.convtrackmatch() );
      } else {
         convtrackmatch()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convtrk1nBLHits.IsAvailable() ) {
         convtrk1nBLHits()->push_back( el.convtrk1nBLHits() );
      } else {
         convtrk1nBLHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk1nPixHits.IsAvailable() ) {
         convtrk1nPixHits()->push_back( el.convtrk1nPixHits() );
      } else {
         convtrk1nPixHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk1nSCTHits.IsAvailable() ) {
         convtrk1nSCTHits()->push_back( el.convtrk1nSCTHits() );
      } else {
         convtrk1nSCTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk1nTRTHits.IsAvailable() ) {
         convtrk1nTRTHits()->push_back( el.convtrk1nTRTHits() );
      } else {
         convtrk1nTRTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk2nBLHits.IsAvailable() ) {
         convtrk2nBLHits()->push_back( el.convtrk2nBLHits() );
      } else {
         convtrk2nBLHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk2nPixHits.IsAvailable() ) {
         convtrk2nPixHits()->push_back( el.convtrk2nPixHits() );
      } else {
         convtrk2nPixHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk2nSCTHits.IsAvailable() ) {
         convtrk2nSCTHits()->push_back( el.convtrk2nSCTHits() );
      } else {
         convtrk2nSCTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk2nTRTHits.IsAvailable() ) {
         convtrk2nTRTHits()->push_back( el.convtrk2nTRTHits() );
      } else {
         convtrk2nTRTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convvtxchi2.IsAvailable() ) {
         convvtxchi2()->push_back( el.convvtxchi2() );
      } else {
         convvtxchi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convvtxx.IsAvailable() ) {
         convvtxx()->push_back( el.convvtxx() );
      } else {
         convvtxx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convvtxy.IsAvailable() ) {
         convvtxy()->push_back( el.convvtxy() );
      } else {
         convvtxy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convvtxz.IsAvailable() ) {
         convvtxz()->push_back( el.convvtxz() );
      } else {
         convvtxz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaEmax2.IsAvailable() ) {
         deltaEmax2()->push_back( el.deltaEmax2() );
      } else {
         deltaEmax2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaEs.IsAvailable() ) {
         deltaEs()->push_back( el.deltaEs() );
      } else {
         deltaEs()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaPhiFromLast.IsAvailable() ) {
         deltaPhiFromLast()->push_back( el.deltaPhiFromLast() );
      } else {
         deltaPhiFromLast()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaPhiRot.IsAvailable() ) {
         deltaPhiRot()->push_back( el.deltaPhiRot() );
      } else {
         deltaPhiRot()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaeta1.IsAvailable() ) {
         deltaeta1()->push_back( el.deltaeta1() );
      } else {
         deltaeta1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaeta2.IsAvailable() ) {
         deltaeta2()->push_back( el.deltaeta2() );
      } else {
         deltaeta2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaphi2.IsAvailable() ) {
         deltaphi2()->push_back( el.deltaphi2() );
      } else {
         deltaphi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaphiRescaled.IsAvailable() ) {
         deltaphiRescaled()->push_back( el.deltaphiRescaled() );
      } else {
         deltaphiRescaled()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.depth.IsAvailable() ) {
         depth()->push_back( el.depth() );
      } else {
         depth()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eProbabilityBrem.IsAvailable() ) {
         eProbabilityBrem()->push_back( el.eProbabilityBrem() );
      } else {
         eProbabilityBrem()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eProbabilityComb.IsAvailable() ) {
         eProbabilityComb()->push_back( el.eProbabilityComb() );
      } else {
         eProbabilityComb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eProbabilityHT.IsAvailable() ) {
         eProbabilityHT()->push_back( el.eProbabilityHT() );
      } else {
         eProbabilityHT()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eProbabilityToT.IsAvailable() ) {
         eProbabilityToT()->push_back( el.eProbabilityToT() );
      } else {
         eProbabilityToT()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.electronbgweight.IsAvailable() ) {
         electronbgweight()->push_back( el.electronbgweight() );
      } else {
         electronbgweight()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.electronweight.IsAvailable() ) {
         electronweight()->push_back( el.electronweight() );
      } else {
         electronweight()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.emaxs1.IsAvailable() ) {
         emaxs1()->push_back( el.emaxs1() );
      } else {
         emaxs1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.errz.IsAvailable() ) {
         errz()->push_back( el.errz() );
      } else {
         errz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eta.IsAvailable() ) {
         eta()->push_back( el.eta() );
      } else {
         eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etaSampling1.IsAvailable() ) {
         etaSampling1()->push_back( el.etaSampling1() );
      } else {
         etaSampling1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etacellS0.IsAvailable() ) {
         etacellS0()->push_back( el.etacellS0() );
      } else {
         etacellS0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etacorrmag.IsAvailable() ) {
         etacorrmag()->push_back( el.etacorrmag() );
      } else {
         etacorrmag()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etap.IsAvailable() ) {
         etap()->push_back( el.etap() );
      } else {
         etap()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas0.IsAvailable() ) {
         etas0()->push_back( el.etas0() );
      } else {
         etas0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas1.IsAvailable() ) {
         etas1()->push_back( el.etas1() );
      } else {
         etas1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas2.IsAvailable() ) {
         etas2()->push_back( el.etas2() );
      } else {
         etas2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas3.IsAvailable() ) {
         etas3()->push_back( el.etas3() );
      } else {
         etas3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.expectBLayerHit.IsAvailable() ) {
         expectBLayerHit()->push_back( el.expectBLayerHit() );
      } else {
         expectBLayerHit()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.expectHitInBLayer.IsAvailable() ) {
         expectHitInBLayer()->push_back( el.expectHitInBLayer() );
      } else {
         expectHitInBLayer()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.f1.IsAvailable() ) {
         f1()->push_back( el.f1() );
      } else {
         f1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.f1core.IsAvailable() ) {
         f1core()->push_back( el.f1core() );
      } else {
         f1core()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.f3.IsAvailable() ) {
         f3()->push_back( el.f3() );
      } else {
         f3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.f3core.IsAvailable() ) {
         f3core()->push_back( el.f3core() );
      } else {
         f3core()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.firstEdens.IsAvailable() ) {
         firstEdens()->push_back( el.firstEdens() );
      } else {
         firstEdens()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.fside.IsAvailable() ) {
         fside()->push_back( el.fside() );
      } else {
         fside()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.goodOQ.IsAvailable() ) {
         goodOQ()->push_back( el.goodOQ() );
      } else {
         goodOQ()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.hasconv.IsAvailable() ) {
         hasconv()->push_back( el.hasconv() );
      } else {
         hasconv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.hastrack.IsAvailable() ) {
         hastrack()->push_back( el.hastrack() );
      } else {
         hastrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isConv.IsAvailable() ) {
         isConv()->push_back( el.isConv() );
      } else {
         isConv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isEM.IsAvailable() ) {
         isEM()->push_back( el.isEM() );
      } else {
         isEM()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.isEMLoose.IsAvailable() ) {
         isEMLoose()->push_back( el.isEMLoose() );
      } else {
         isEMLoose()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.isEMMedium.IsAvailable() ) {
         isEMMedium()->push_back( el.isEMMedium() );
      } else {
         isEMMedium()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.isEMTight.IsAvailable() ) {
         isEMTight()->push_back( el.isEMTight() );
      } else {
         isEMTight()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.isIso.IsAvailable() ) {
         isIso()->push_back( el.isIso() );
      } else {
         isIso()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.isolationlikelihoodhqelectrons.IsAvailable() ) {
         isolationlikelihoodhqelectrons()->push_back( el.isolationlikelihoodhqelectrons() );
      } else {
         isolationlikelihoodhqelectrons()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.isolationlikelihoodjets.IsAvailable() ) {
         isolationlikelihoodjets()->push_back( el.isolationlikelihoodjets() );
      } else {
         isolationlikelihoodjets()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_E.IsAvailable() ) {
         jet_E()->push_back( el.jet_E() );
      } else {
         jet_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_dr.IsAvailable() ) {
         jet_dr()->push_back( el.jet_dr() );
      } else {
         jet_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_eta.IsAvailable() ) {
         jet_eta()->push_back( el.jet_eta() );
      } else {
         jet_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_m.IsAvailable() ) {
         jet_m()->push_back( el.jet_m() );
      } else {
         jet_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_matched.IsAvailable() ) {
         jet_matched()->push_back( el.jet_matched() );
      } else {
         jet_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.jet_phi.IsAvailable() ) {
         jet_phi()->push_back( el.jet_phi() );
      } else {
         jet_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_pt.IsAvailable() ) {
         jet_pt()->push_back( el.jet_pt() );
      } else {
         jet_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_truth_E.IsAvailable() ) {
         jet_truth_E()->push_back( el.jet_truth_E() );
      } else {
         jet_truth_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_truth_dr.IsAvailable() ) {
         jet_truth_dr()->push_back( el.jet_truth_dr() );
      } else {
         jet_truth_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_truth_eta.IsAvailable() ) {
         jet_truth_eta()->push_back( el.jet_truth_eta() );
      } else {
         jet_truth_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_truth_m.IsAvailable() ) {
         jet_truth_m()->push_back( el.jet_truth_m() );
      } else {
         jet_truth_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_truth_matched.IsAvailable() ) {
         jet_truth_matched()->push_back( el.jet_truth_matched() );
      } else {
         jet_truth_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.jet_truth_phi.IsAvailable() ) {
         jet_truth_phi()->push_back( el.jet_truth_phi() );
      } else {
         jet_truth_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_truth_pt.IsAvailable() ) {
         jet_truth_pt()->push_back( el.jet_truth_pt() );
      } else {
         jet_truth_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.lateral.IsAvailable() ) {
         lateral()->push_back( el.lateral() );
      } else {
         lateral()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.likelihoodsPixeldEdx.IsAvailable() ) {
         likelihoodsPixeldEdx()->push_back( el.likelihoodsPixeldEdx() );
      } else {
         likelihoodsPixeldEdx()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.longitudinal.IsAvailable() ) {
         longitudinal()->push_back( el.longitudinal() );
      } else {
         longitudinal()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.loose.IsAvailable() ) {
         loose()->push_back( el.loose() );
      } else {
         loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.looseIso.IsAvailable() ) {
         looseIso()->push_back( el.looseIso() );
      } else {
         looseIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.loosePP.IsAvailable() ) {
         loosePP()->push_back( el.loosePP() );
      } else {
         loosePP()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.loosePPIso.IsAvailable() ) {
         loosePPIso()->push_back( el.loosePPIso() );
      } else {
         loosePPIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.massPixeldEdx.IsAvailable() ) {
         massPixeldEdx()->push_back( el.massPixeldEdx() );
      } else {
         massPixeldEdx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.medium.IsAvailable() ) {
         medium()->push_back( el.medium() );
      } else {
         medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mediumIso.IsAvailable() ) {
         mediumIso()->push_back( el.mediumIso() );
      } else {
         mediumIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mediumIsoWithoutTrack.IsAvailable() ) {
         mediumIsoWithoutTrack()->push_back( el.mediumIsoWithoutTrack() );
      } else {
         mediumIsoWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mediumPP.IsAvailable() ) {
         mediumPP()->push_back( el.mediumPP() );
      } else {
         mediumPP()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mediumPPIso.IsAvailable() ) {
         mediumPPIso()->push_back( el.mediumPPIso() );
      } else {
         mediumPPIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mediumWithoutTrack.IsAvailable() ) {
         mediumWithoutTrack()->push_back( el.mediumWithoutTrack() );
      } else {
         mediumWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mvaptcone20.IsAvailable() ) {
         mvaptcone20()->push_back( el.mvaptcone20() );
      } else {
         mvaptcone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.mvaptcone30.IsAvailable() ) {
         mvaptcone30()->push_back( el.mvaptcone30() );
      } else {
         mvaptcone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.mvaptcone40.IsAvailable() ) {
         mvaptcone40()->push_back( el.mvaptcone40() );
      } else {
         mvaptcone40()->push_back( std::numeric_limits< float >::min() );
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
      if( el.nBLayerOutliers.IsAvailable() ) {
         nBLayerOutliers()->push_back( el.nBLayerOutliers() );
      } else {
         nBLayerOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nBLayerSplitHits.IsAvailable() ) {
         nBLayerSplitHits()->push_back( el.nBLayerSplitHits() );
      } else {
         nBLayerSplitHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nContribPixelLayers.IsAvailable() ) {
         nContribPixelLayers()->push_back( el.nContribPixelLayers() );
      } else {
         nContribPixelLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nConv.IsAvailable() ) {
         nConv()->push_back( el.nConv() );
      } else {
         nConv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nDoubleTrackConv.IsAvailable() ) {
         nDoubleTrackConv()->push_back( el.nDoubleTrackConv() );
      } else {
         nDoubleTrackConv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nGangedFlaggedFakes.IsAvailable() ) {
         nGangedFlaggedFakes()->push_back( el.nGangedFlaggedFakes() );
      } else {
         nGangedFlaggedFakes()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nGangedPixels.IsAvailable() ) {
         nGangedPixels()->push_back( el.nGangedPixels() );
      } else {
         nGangedPixels()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nGoodHitsPixeldEdx.IsAvailable() ) {
         nGoodHitsPixeldEdx()->push_back( el.nGoodHitsPixeldEdx() );
      } else {
         nGoodHitsPixeldEdx()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nPixSplitHits.IsAvailable() ) {
         nPixSplitHits()->push_back( el.nPixSplitHits() );
      } else {
         nPixSplitHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixelDeadSensors.IsAvailable() ) {
         nPixelDeadSensors()->push_back( el.nPixelDeadSensors() );
      } else {
         nPixelDeadSensors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixelOutliers.IsAvailable() ) {
         nPixelOutliers()->push_back( el.nPixelOutliers() );
      } else {
         nPixelOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixelSpoiltHits.IsAvailable() ) {
         nPixelSpoiltHits()->push_back( el.nPixelSpoiltHits() );
      } else {
         nPixelSpoiltHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTDeadSensors.IsAvailable() ) {
         nSCTDeadSensors()->push_back( el.nSCTDeadSensors() );
      } else {
         nSCTDeadSensors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTDoubleHoles.IsAvailable() ) {
         nSCTDoubleHoles()->push_back( el.nSCTDoubleHoles() );
      } else {
         nSCTDoubleHoles()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nSCTOutliers.IsAvailable() ) {
         nSCTOutliers()->push_back( el.nSCTOutliers() );
      } else {
         nSCTOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTSharedHits.IsAvailable() ) {
         nSCTSharedHits()->push_back( el.nSCTSharedHits() );
      } else {
         nSCTSharedHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTSpoiltHits.IsAvailable() ) {
         nSCTSpoiltHits()->push_back( el.nSCTSpoiltHits() );
      } else {
         nSCTSpoiltHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSiHits.IsAvailable() ) {
         nSiHits()->push_back( el.nSiHits() );
      } else {
         nSiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSingleTrackConv.IsAvailable() ) {
         nSingleTrackConv()->push_back( el.nSingleTrackConv() );
      } else {
         nSingleTrackConv()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nTRTHoles.IsAvailable() ) {
         nTRTHoles()->push_back( el.nTRTHoles() );
      } else {
         nTRTHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTOutliers.IsAvailable() ) {
         nTRTOutliers()->push_back( el.nTRTOutliers() );
      } else {
         nTRTOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.neuralnet.IsAvailable() ) {
         neuralnet()->push_back( el.neuralnet() );
      } else {
         neuralnet()->push_back( std::numeric_limits< double >::min() );
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
      if( el.originbkg.IsAvailable() ) {
         originbkg()->push_back( el.originbkg() );
      } else {
         originbkg()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.phi.IsAvailable() ) {
         phi()->push_back( el.phi() );
      } else {
         phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phis0.IsAvailable() ) {
         phis0()->push_back( el.phis0() );
      } else {
         phis0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phis1.IsAvailable() ) {
         phis1()->push_back( el.phis1() );
      } else {
         phis1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phis2.IsAvailable() ) {
         phis2()->push_back( el.phis2() );
      } else {
         phis2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phis3.IsAvailable() ) {
         phis3()->push_back( el.phis3() );
      } else {
         phis3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pixeldEdx.IsAvailable() ) {
         pixeldEdx()->push_back( el.pixeldEdx() );
      } else {
         pixeldEdx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pos7.IsAvailable() ) {
         pos7()->push_back( el.pos7() );
      } else {
         pos7()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pt.IsAvailable() ) {
         pt()->push_back( el.pt() );
      } else {
         pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pt1conv.IsAvailable() ) {
         pt1conv()->push_back( el.pt1conv() );
      } else {
         pt1conv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pt2conv.IsAvailable() ) {
         pt2conv()->push_back( el.pt2conv() );
      } else {
         pt2conv()->push_back( std::numeric_limits< float >::min() );
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
      if( el.ptconv.IsAvailable() ) {
         ptconv()->push_back( el.ptconv() );
      } else {
         ptconv()->push_back( std::numeric_limits< float >::min() );
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
      if( el.pzconv.IsAvailable() ) {
         pzconv()->push_back( el.pzconv() );
      } else {
         pzconv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_E.IsAvailable() ) {
         rawcl_E()->push_back( el.rawcl_E() );
      } else {
         rawcl_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_Es0.IsAvailable() ) {
         rawcl_Es0()->push_back( el.rawcl_Es0() );
      } else {
         rawcl_Es0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_Es1.IsAvailable() ) {
         rawcl_Es1()->push_back( el.rawcl_Es1() );
      } else {
         rawcl_Es1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_Es2.IsAvailable() ) {
         rawcl_Es2()->push_back( el.rawcl_Es2() );
      } else {
         rawcl_Es2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_Es3.IsAvailable() ) {
         rawcl_Es3()->push_back( el.rawcl_Es3() );
      } else {
         rawcl_Es3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_eta.IsAvailable() ) {
         rawcl_eta()->push_back( el.rawcl_eta() );
      } else {
         rawcl_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_etas0.IsAvailable() ) {
         rawcl_etas0()->push_back( el.rawcl_etas0() );
      } else {
         rawcl_etas0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_etas1.IsAvailable() ) {
         rawcl_etas1()->push_back( el.rawcl_etas1() );
      } else {
         rawcl_etas1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_etas2.IsAvailable() ) {
         rawcl_etas2()->push_back( el.rawcl_etas2() );
      } else {
         rawcl_etas2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_etas3.IsAvailable() ) {
         rawcl_etas3()->push_back( el.rawcl_etas3() );
      } else {
         rawcl_etas3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_phi.IsAvailable() ) {
         rawcl_phi()->push_back( el.rawcl_phi() );
      } else {
         rawcl_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_phis0.IsAvailable() ) {
         rawcl_phis0()->push_back( el.rawcl_phis0() );
      } else {
         rawcl_phis0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_phis1.IsAvailable() ) {
         rawcl_phis1()->push_back( el.rawcl_phis1() );
      } else {
         rawcl_phis1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_phis2.IsAvailable() ) {
         rawcl_phis2()->push_back( el.rawcl_phis2() );
      } else {
         rawcl_phis2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_phis3.IsAvailable() ) {
         rawcl_phis3()->push_back( el.rawcl_phis3() );
      } else {
         rawcl_phis3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rawcl_pt.IsAvailable() ) {
         rawcl_pt()->push_back( el.rawcl_pt() );
      } else {
         rawcl_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.refittedTrack_LMqoverp.IsAvailable() ) {
         refittedTrack_LMqoverp()->push_back( el.refittedTrack_LMqoverp() );
      } else {
         refittedTrack_LMqoverp()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_author.IsAvailable() ) {
         refittedTrack_author()->push_back( el.refittedTrack_author() );
      } else {
         refittedTrack_author()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.refittedTrack_bremFitStatus.IsAvailable() ) {
         refittedTrack_bremFitStatus()->push_back( el.refittedTrack_bremFitStatus() );
      } else {
         refittedTrack_bremFitStatus()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.refittedTrack_bremRadius.IsAvailable() ) {
         refittedTrack_bremRadius()->push_back( el.refittedTrack_bremRadius() );
      } else {
         refittedTrack_bremRadius()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_bremRadiusErr.IsAvailable() ) {
         refittedTrack_bremRadiusErr()->push_back( el.refittedTrack_bremRadiusErr() );
      } else {
         refittedTrack_bremRadiusErr()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_bremZ.IsAvailable() ) {
         refittedTrack_bremZ()->push_back( el.refittedTrack_bremZ() );
      } else {
         refittedTrack_bremZ()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_bremZErr.IsAvailable() ) {
         refittedTrack_bremZErr()->push_back( el.refittedTrack_bremZErr() );
      } else {
         refittedTrack_bremZErr()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_chi2.IsAvailable() ) {
         refittedTrack_chi2()->push_back( el.refittedTrack_chi2() );
      } else {
         refittedTrack_chi2()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covd0.IsAvailable() ) {
         refittedTrack_covd0()->push_back( el.refittedTrack_covd0() );
      } else {
         refittedTrack_covd0()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covd0phi.IsAvailable() ) {
         refittedTrack_covd0phi()->push_back( el.refittedTrack_covd0phi() );
      } else {
         refittedTrack_covd0phi()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covd0qoverp.IsAvailable() ) {
         refittedTrack_covd0qoverp()->push_back( el.refittedTrack_covd0qoverp() );
      } else {
         refittedTrack_covd0qoverp()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covd0theta.IsAvailable() ) {
         refittedTrack_covd0theta()->push_back( el.refittedTrack_covd0theta() );
      } else {
         refittedTrack_covd0theta()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covd0z0.IsAvailable() ) {
         refittedTrack_covd0z0()->push_back( el.refittedTrack_covd0z0() );
      } else {
         refittedTrack_covd0z0()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covphi.IsAvailable() ) {
         refittedTrack_covphi()->push_back( el.refittedTrack_covphi() );
      } else {
         refittedTrack_covphi()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covphiqoverp.IsAvailable() ) {
         refittedTrack_covphiqoverp()->push_back( el.refittedTrack_covphiqoverp() );
      } else {
         refittedTrack_covphiqoverp()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covphitheta.IsAvailable() ) {
         refittedTrack_covphitheta()->push_back( el.refittedTrack_covphitheta() );
      } else {
         refittedTrack_covphitheta()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covqoverp.IsAvailable() ) {
         refittedTrack_covqoverp()->push_back( el.refittedTrack_covqoverp() );
      } else {
         refittedTrack_covqoverp()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covtheta.IsAvailable() ) {
         refittedTrack_covtheta()->push_back( el.refittedTrack_covtheta() );
      } else {
         refittedTrack_covtheta()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covthetaqoverp.IsAvailable() ) {
         refittedTrack_covthetaqoverp()->push_back( el.refittedTrack_covthetaqoverp() );
      } else {
         refittedTrack_covthetaqoverp()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covz0.IsAvailable() ) {
         refittedTrack_covz0()->push_back( el.refittedTrack_covz0() );
      } else {
         refittedTrack_covz0()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covz0phi.IsAvailable() ) {
         refittedTrack_covz0phi()->push_back( el.refittedTrack_covz0phi() );
      } else {
         refittedTrack_covz0phi()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covz0qoverp.IsAvailable() ) {
         refittedTrack_covz0qoverp()->push_back( el.refittedTrack_covz0qoverp() );
      } else {
         refittedTrack_covz0qoverp()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_covz0theta.IsAvailable() ) {
         refittedTrack_covz0theta()->push_back( el.refittedTrack_covz0theta() );
      } else {
         refittedTrack_covz0theta()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_d0.IsAvailable() ) {
         refittedTrack_d0()->push_back( el.refittedTrack_d0() );
      } else {
         refittedTrack_d0()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_hasBrem.IsAvailable() ) {
         refittedTrack_hasBrem()->push_back( el.refittedTrack_hasBrem() );
      } else {
         refittedTrack_hasBrem()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.refittedTrack_n.IsAvailable() ) {
         refittedTrack_n()->push_back( el.refittedTrack_n() );
      } else {
         refittedTrack_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.refittedTrack_phi.IsAvailable() ) {
         refittedTrack_phi()->push_back( el.refittedTrack_phi() );
      } else {
         refittedTrack_phi()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_qoverp.IsAvailable() ) {
         refittedTrack_qoverp()->push_back( el.refittedTrack_qoverp() );
      } else {
         refittedTrack_qoverp()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_theta.IsAvailable() ) {
         refittedTrack_theta()->push_back( el.refittedTrack_theta() );
      } else {
         refittedTrack_theta()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.refittedTrack_z0.IsAvailable() ) {
         refittedTrack_z0()->push_back( el.refittedTrack_z0() );
      } else {
         refittedTrack_z0()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.reta.IsAvailable() ) {
         reta()->push_back( el.reta() );
      } else {
         reta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ringernn.IsAvailable() ) {
         ringernn()->push_back( el.ringernn() );
      } else {
         ringernn()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.rings_E.IsAvailable() ) {
         rings_E()->push_back( el.rings_E() );
      } else {
         rings_E()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.rphi.IsAvailable() ) {
         rphi()->push_back( el.rphi() );
      } else {
         rphi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rphiallcalo.IsAvailable() ) {
         rphiallcalo()->push_back( el.rphiallcalo() );
      } else {
         rphiallcalo()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secondR.IsAvailable() ) {
         secondR()->push_back( el.secondR() );
      } else {
         secondR()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secondlambda.IsAvailable() ) {
         secondlambda()->push_back( el.secondlambda() );
      } else {
         secondlambda()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.softebgweight.IsAvailable() ) {
         softebgweight()->push_back( el.softebgweight() );
      } else {
         softebgweight()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.softeneuralnet.IsAvailable() ) {
         softeneuralnet()->push_back( el.softeneuralnet() );
      } else {
         softeneuralnet()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.softeweight.IsAvailable() ) {
         softeweight()->push_back( el.softeweight() );
      } else {
         softeweight()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.tight.IsAvailable() ) {
         tight()->push_back( el.tight() );
      } else {
         tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightIso.IsAvailable() ) {
         tightIso()->push_back( el.tightIso() );
      } else {
         tightIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightIsoWithoutTrack.IsAvailable() ) {
         tightIsoWithoutTrack()->push_back( el.tightIsoWithoutTrack() );
      } else {
         tightIsoWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightPP.IsAvailable() ) {
         tightPP()->push_back( el.tightPP() );
      } else {
         tightPP()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightPPIso.IsAvailable() ) {
         tightPPIso()->push_back( el.tightPPIso() );
      } else {
         tightPPIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightWithoutTrack.IsAvailable() ) {
         tightWithoutTrack()->push_back( el.tightWithoutTrack() );
      } else {
         tightWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.topoEtcone20.IsAvailable() ) {
         topoEtcone20()->push_back( el.topoEtcone20() );
      } else {
         topoEtcone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone20_corrected.IsAvailable() ) {
         topoEtcone20_corrected()->push_back( el.topoEtcone20_corrected() );
      } else {
         topoEtcone20_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone30.IsAvailable() ) {
         topoEtcone30()->push_back( el.topoEtcone30() );
      } else {
         topoEtcone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone30_corrected.IsAvailable() ) {
         topoEtcone30_corrected()->push_back( el.topoEtcone30_corrected() );
      } else {
         topoEtcone30_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone40.IsAvailable() ) {
         topoEtcone40()->push_back( el.topoEtcone40() );
      } else {
         topoEtcone40()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone40_corrected.IsAvailable() ) {
         topoEtcone40_corrected()->push_back( el.topoEtcone40_corrected() );
      } else {
         topoEtcone40_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone60.IsAvailable() ) {
         topoEtcone60()->push_back( el.topoEtcone60() );
      } else {
         topoEtcone60()->push_back( std::numeric_limits< float >::min() );
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
      if( el.trackd0_physics.IsAvailable() ) {
         trackd0_physics()->push_back( el.trackd0_physics() );
      } else {
         trackd0_physics()->push_back( std::numeric_limits< float >::min() );
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
      if( el.tracketa.IsAvailable() ) {
         tracketa()->push_back( el.tracketa() );
      } else {
         tracketa()->push_back( std::numeric_limits< float >::min() );
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
      if( el.trackpt.IsAvailable() ) {
         trackpt()->push_back( el.trackpt() );
      } else {
         trackpt()->push_back( std::numeric_limits< float >::min() );
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
      if( el.truth_bremLoc.IsAvailable() ) {
         truth_bremLoc()->push_back( el.truth_bremLoc() );
      } else {
         truth_bremLoc()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_bremSi.IsAvailable() ) {
         truth_bremSi()->push_back( el.truth_bremSi() );
      } else {
         truth_bremSi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_eta.IsAvailable() ) {
         truth_eta()->push_back( el.truth_eta() );
      } else {
         truth_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_hasHardBrem.IsAvailable() ) {
         truth_hasHardBrem()->push_back( el.truth_hasHardBrem() );
      } else {
         truth_hasHardBrem()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_index.IsAvailable() ) {
         truth_index()->push_back( el.truth_index() );
      } else {
         truth_index()->push_back( std::numeric_limits< int >::min() );
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
      if( el.truth_sumbrem.IsAvailable() ) {
         truth_sumbrem()->push_back( el.truth_sumbrem() );
      } else {
         truth_sumbrem()->push_back( std::numeric_limits< float >::min() );
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
      if( el.typebkg.IsAvailable() ) {
         typebkg()->push_back( el.typebkg() );
      } else {
         typebkg()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.vertweight.IsAvailable() ) {
         vertweight()->push_back( el.vertweight() );
      } else {
         vertweight()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.vertx.IsAvailable() ) {
         vertx()->push_back( el.vertx() );
      } else {
         vertx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.verty.IsAvailable() ) {
         verty()->push_back( el.verty() );
      } else {
         verty()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.vertz.IsAvailable() ) {
         vertz()->push_back( el.vertz() );
      } else {
         vertz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.weta2.IsAvailable() ) {
         weta2()->push_back( el.weta2() );
      } else {
         weta2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ws3.IsAvailable() ) {
         ws3()->push_back( el.ws3() );
      } else {
         ws3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.wstot.IsAvailable() ) {
         wstot()->push_back( el.wstot() );
      } else {
         wstot()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.zconv.IsAvailable() ) {
         zconv()->push_back( el.zconv() );
      } else {
         zconv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.zvertex.IsAvailable() ) {
         zvertex()->push_back( el.zvertex() );
      } else {
         zvertex()->push_back( std::numeric_limits< float >::min() );
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
   ElectronD3PDObjectElement& ElectronD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new ElectronD3PDObjectElement( fProxies.size(), *this ) );
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
   const ElectronD3PDObjectElement& ElectronD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new ElectronD3PDObjectElement( fProxies.size(), *this ) );
      }
      return *fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   ElectronD3PDObject& ElectronD3PDObject::operator+=( const ElectronD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
