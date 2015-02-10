// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/PhotonD3PDObject.h"

ClassImp( D3PDReader::PhotonD3PDObjectElement )
ClassImp( D3PDReader::PhotonD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class PhotonD3PDObject.
    */
   PhotonD3PDObjectElement::PhotonD3PDObjectElement( size_t index, const PhotonD3PDObject& parent )
      : CaloPointing_eta( parent.CaloPointing_eta, index, this ),
        CaloPointing_sigma_eta( parent.CaloPointing_sigma_eta, index, this ),
        CaloPointing_sigma_zvertex( parent.CaloPointing_sigma_zvertex, index, this ),
        CaloPointing_zvertex( parent.CaloPointing_zvertex, index, this ),
        E( parent.E, index, this ),
        E033( parent.E033, index, this ),
        E1152( parent.E1152, index, this ),
        E132( parent.E132, index, this ),
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
        L1_dr( parent.L1_dr, index, this ),
        L1_index( parent.L1_index, index, this ),
        L2_dr( parent.L2_dr, index, this ),
        L2_index( parent.L2_index, index, this ),
        NN_discriminant( parent.NN_discriminant, index, this ),
        NN_passes( parent.NN_passes, index, this ),
        OQ( parent.OQ, index, this ),
        Rconv( parent.Rconv, index, this ),
        adaboost( parent.adaboost, index, this ),
        author( parent.author, index, this ),
        calibHitsShowerDepth( parent.calibHitsShowerDepth, index, this ),
        cl_E( parent.cl_E, index, this ),
        cl_eta( parent.cl_eta, index, this ),
        cl_phi( parent.cl_phi, index, this ),
        cl_pt( parent.cl_pt, index, this ),
        convFlag( parent.convFlag, index, this ),
        convIP( parent.convIP, index, this ),
        convIPRev( parent.convIPRev, index, this ),
        convMatchDeltaEta1( parent.convMatchDeltaEta1, index, this ),
        convMatchDeltaEta2( parent.convMatchDeltaEta2, index, this ),
        convMatchDeltaPhi1( parent.convMatchDeltaPhi1, index, this ),
        convMatchDeltaPhi2( parent.convMatchDeltaPhi2, index, this ),
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
        depth( parent.depth, index, this ),
        el_index( parent.el_index, index, this ),
        emaxs1( parent.emaxs1, index, this ),
        errz( parent.errz, index, this ),
        eta( parent.eta, index, this ),
        etacellS0( parent.etacellS0, index, this ),
        etap( parent.etap, index, this ),
        etas0( parent.etas0, index, this ),
        etas1( parent.etas1, index, this ),
        etas2( parent.etas2, index, this ),
        etas3( parent.etas3, index, this ),
        f1( parent.f1, index, this ),
        f1core( parent.f1core, index, this ),
        f3( parent.f3, index, this ),
        f3core( parent.f3core, index, this ),
        fside( parent.fside, index, this ),
        goodOQ( parent.goodOQ, index, this ),
        hasconv( parent.hasconv, index, this ),
        isConv( parent.isConv, index, this ),
        isEM( parent.isEM, index, this ),
        isEMLoose( parent.isEMLoose, index, this ),
        isEMMedium( parent.isEMMedium, index, this ),
        isEMTight( parent.isEMTight, index, this ),
        isIso( parent.isIso, index, this ),
        isRecovered( parent.isRecovered, index, this ),
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
        loglikelihood( parent.loglikelihood, index, this ),
        loose( parent.loose, index, this ),
        looseAR( parent.looseAR, index, this ),
        looseARIso( parent.looseARIso, index, this ),
        looseIso( parent.looseIso, index, this ),
        m( parent.m, index, this ),
        mvaptcone20( parent.mvaptcone20, index, this ),
        mvaptcone30( parent.mvaptcone30, index, this ),
        mvaptcone40( parent.mvaptcone40, index, this ),
        nConv( parent.nConv, index, this ),
        nDoubleTrackConv( parent.nDoubleTrackConv, index, this ),
        nSingleTrackConv( parent.nSingleTrackConv, index, this ),
        neuralnet( parent.neuralnet, index, this ),
        nucone20( parent.nucone20, index, this ),
        nucone30( parent.nucone30, index, this ),
        nucone40( parent.nucone40, index, this ),
        origin( parent.origin, index, this ),
        phi( parent.phi, index, this ),
        phis0( parent.phis0, index, this ),
        phis1( parent.phis1, index, this ),
        phis2( parent.phis2, index, this ),
        phis3( parent.phis3, index, this ),
        photonbgweight( parent.photonbgweight, index, this ),
        photonweight( parent.photonweight, index, this ),
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
	cl_etaCalo( parent.cl_etaCalo, index, this ),
	cl_phiCalo( parent.cl_phiCalo, index, this ),
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
        reta( parent.reta, index, this ),
        ringernn( parent.ringernn, index, this ),
        rings_E( parent.rings_E, index, this ),
        rphi( parent.rphi, index, this ),
        rphiallcalo( parent.rphiallcalo, index, this ),
        tight( parent.tight, index, this ),
        tightAR( parent.tightAR, index, this ),
        tightARIso( parent.tightARIso, index, this ),
        tightIso( parent.tightIso, index, this ),
        topoEMdr( parent.topoEMdr, index, this ),
        topoEMeta( parent.topoEMeta, index, this ),
        topoEMmatched( parent.topoEMmatched, index, this ),
        topoEMphi( parent.topoEMphi, index, this ),
        topoEMpt( parent.topoEMpt, index, this ),
        topoEtcone20( parent.topoEtcone20, index, this ),
        topoEtcone20_corrected( parent.topoEtcone20_corrected, index, this ),
        topoEtcone30( parent.topoEtcone30, index, this ),
        topoEtcone30_corrected( parent.topoEtcone30_corrected, index, this ),
        topoEtcone40( parent.topoEtcone40, index, this ),
        topoEtcone40_corrected( parent.topoEtcone40_corrected, index, this ),
        topoEtcone60( parent.topoEtcone60, index, this ),
        topodr( parent.topodr, index, this ),
        topoeta( parent.topoeta, index, this ),
        topomatched( parent.topomatched, index, this ),
        topophi( parent.topophi, index, this ),
        topopt( parent.topopt, index, this ),
        truth_E( parent.truth_E, index, this ),
        truth_Rconv( parent.truth_Rconv, index, this ),
        truth_barcode( parent.truth_barcode, index, this ),
        truth_deltaRRecPhoton( parent.truth_deltaRRecPhoton, index, this ),
        truth_eta( parent.truth_eta, index, this ),
        truth_index( parent.truth_index, index, this ),
        truth_isBrem( parent.truth_isBrem, index, this ),
        truth_isConv( parent.truth_isConv, index, this ),
        truth_isFromHardProc( parent.truth_isFromHardProc, index, this ),
        truth_isPhotonFromHardProc( parent.truth_isPhotonFromHardProc, index, this ),
        truth_matched( parent.truth_matched, index, this ),
        truth_motherbarcode( parent.truth_motherbarcode, index, this ),
        truth_mothertype( parent.truth_mothertype, index, this ),
        truth_phi( parent.truth_phi, index, this ),
        truth_pt( parent.truth_pt, index, this ),
        truth_status( parent.truth_status, index, this ),
        truth_type( parent.truth_type, index, this ),
        truth_zconv( parent.truth_zconv, index, this ),
        type( parent.type, index, this ),
        vx_Chi2( parent.vx_Chi2, index, this ),
        vx_DR1R2( parent.vx_DR1R2, index, this ),
        vx_Dcottheta( parent.vx_Dcottheta, index, this ),
        vx_Dist( parent.vx_Dist, index, this ),
        vx_Dphi( parent.vx_Dphi, index, this ),
        vx_E( parent.vx_E, index, this ),
        vx_convTrk_TRTHighTHitsRatio( parent.vx_convTrk_TRTHighTHitsRatio, index, this ),
        vx_convTrk_TRTHighTOutliersRatio( parent.vx_convTrk_TRTHighTOutliersRatio, index, this ),
        vx_convTrk_chi2( parent.vx_convTrk_chi2, index, this ),
        vx_convTrk_eProbabilityBrem( parent.vx_convTrk_eProbabilityBrem, index, this ),
        vx_convTrk_eProbabilityComb( parent.vx_convTrk_eProbabilityComb, index, this ),
        vx_convTrk_eProbabilityHT( parent.vx_convTrk_eProbabilityHT, index, this ),
        vx_convTrk_eProbabilityToT( parent.vx_convTrk_eProbabilityToT, index, this ),
        vx_convTrk_expectBLayerHit( parent.vx_convTrk_expectBLayerHit, index, this ),
        vx_convTrk_fitter( parent.vx_convTrk_fitter, index, this ),
        vx_convTrk_hitPattern( parent.vx_convTrk_hitPattern, index, this ),
        vx_convTrk_n( parent.vx_convTrk_n, index, this ),
        vx_convTrk_nBLHits( parent.vx_convTrk_nBLHits, index, this ),
        vx_convTrk_nBLSharedHits( parent.vx_convTrk_nBLSharedHits, index, this ),
        vx_convTrk_nBLayerOutliers( parent.vx_convTrk_nBLayerOutliers, index, this ),
        vx_convTrk_nBLayerSplitHits( parent.vx_convTrk_nBLayerSplitHits, index, this ),
        vx_convTrk_nCSCEtaHits( parent.vx_convTrk_nCSCEtaHits, index, this ),
        vx_convTrk_nCSCPhiHits( parent.vx_convTrk_nCSCPhiHits, index, this ),
        vx_convTrk_nContribPixelLayers( parent.vx_convTrk_nContribPixelLayers, index, this ),
        vx_convTrk_nCscEtaHoles( parent.vx_convTrk_nCscEtaHoles, index, this ),
        vx_convTrk_nCscPhiHoles( parent.vx_convTrk_nCscPhiHoles, index, this ),
        vx_convTrk_nGangedFlaggedFakes( parent.vx_convTrk_nGangedFlaggedFakes, index, this ),
        vx_convTrk_nGangedPixels( parent.vx_convTrk_nGangedPixels, index, this ),
        vx_convTrk_nHits( parent.vx_convTrk_nHits, index, this ),
        vx_convTrk_nHoles( parent.vx_convTrk_nHoles, index, this ),
        vx_convTrk_nMDTHits( parent.vx_convTrk_nMDTHits, index, this ),
        vx_convTrk_nMdtHoles( parent.vx_convTrk_nMdtHoles, index, this ),
        vx_convTrk_nOutliersOnTrack( parent.vx_convTrk_nOutliersOnTrack, index, this ),
        vx_convTrk_nPixHits( parent.vx_convTrk_nPixHits, index, this ),
        vx_convTrk_nPixHoles( parent.vx_convTrk_nPixHoles, index, this ),
        vx_convTrk_nPixSharedHits( parent.vx_convTrk_nPixSharedHits, index, this ),
        vx_convTrk_nPixSplitHits( parent.vx_convTrk_nPixSplitHits, index, this ),
        vx_convTrk_nPixelDeadSensors( parent.vx_convTrk_nPixelDeadSensors, index, this ),
        vx_convTrk_nPixelOutliers( parent.vx_convTrk_nPixelOutliers, index, this ),
        vx_convTrk_nPixelSpoiltHits( parent.vx_convTrk_nPixelSpoiltHits, index, this ),
        vx_convTrk_nRPCEtaHits( parent.vx_convTrk_nRPCEtaHits, index, this ),
        vx_convTrk_nRPCPhiHits( parent.vx_convTrk_nRPCPhiHits, index, this ),
        vx_convTrk_nRpcEtaHoles( parent.vx_convTrk_nRpcEtaHoles, index, this ),
        vx_convTrk_nRpcPhiHoles( parent.vx_convTrk_nRpcPhiHoles, index, this ),
        vx_convTrk_nSCTDeadSensors( parent.vx_convTrk_nSCTDeadSensors, index, this ),
        vx_convTrk_nSCTDoubleHoles( parent.vx_convTrk_nSCTDoubleHoles, index, this ),
        vx_convTrk_nSCTHits( parent.vx_convTrk_nSCTHits, index, this ),
        vx_convTrk_nSCTHoles( parent.vx_convTrk_nSCTHoles, index, this ),
        vx_convTrk_nSCTOutliers( parent.vx_convTrk_nSCTOutliers, index, this ),
        vx_convTrk_nSCTSharedHits( parent.vx_convTrk_nSCTSharedHits, index, this ),
        vx_convTrk_nSCTSpoiltHits( parent.vx_convTrk_nSCTSpoiltHits, index, this ),
        vx_convTrk_nSiHits( parent.vx_convTrk_nSiHits, index, this ),
        vx_convTrk_nTGCEtaHits( parent.vx_convTrk_nTGCEtaHits, index, this ),
        vx_convTrk_nTGCPhiHits( parent.vx_convTrk_nTGCPhiHits, index, this ),
        vx_convTrk_nTRTDeadStraws( parent.vx_convTrk_nTRTDeadStraws, index, this ),
        vx_convTrk_nTRTHighTHits( parent.vx_convTrk_nTRTHighTHits, index, this ),
        vx_convTrk_nTRTHighTOutliers( parent.vx_convTrk_nTRTHighTOutliers, index, this ),
        vx_convTrk_nTRTHits( parent.vx_convTrk_nTRTHits, index, this ),
        vx_convTrk_nTRTHoles( parent.vx_convTrk_nTRTHoles, index, this ),
        vx_convTrk_nTRTOutliers( parent.vx_convTrk_nTRTOutliers, index, this ),
        vx_convTrk_nTRTTubeHits( parent.vx_convTrk_nTRTTubeHits, index, this ),
        vx_convTrk_nTgcEtaHoles( parent.vx_convTrk_nTgcEtaHoles, index, this ),
        vx_convTrk_nTgcPhiHoles( parent.vx_convTrk_nTgcPhiHoles, index, this ),
        vx_convTrk_ndof( parent.vx_convTrk_ndof, index, this ),
        vx_convTrk_particleHypothesis( parent.vx_convTrk_particleHypothesis, index, this ),
        vx_convTrk_patternReco1( parent.vx_convTrk_patternReco1, index, this ),
        vx_convTrk_patternReco2( parent.vx_convTrk_patternReco2, index, this ),
        vx_convTrk_standardDeviationOfChi2OS( parent.vx_convTrk_standardDeviationOfChi2OS, index, this ),
        vx_convTrk_trackProperties( parent.vx_convTrk_trackProperties, index, this ),
        vx_convTrk_weight( parent.vx_convTrk_weight, index, this ),
        vx_m( parent.vx_m, index, this ),
        vx_n( parent.vx_n, index, this ),
        vx_nTracks( parent.vx_nTracks, index, this ),
        vx_px( parent.vx_px, index, this ),
        vx_py( parent.vx_py, index, this ),
        vx_pz( parent.vx_pz, index, this ),
        vx_sumPt( parent.vx_sumPt, index, this ),
        vx_x( parent.vx_x, index, this ),
        vx_y( parent.vx_y, index, this ),
        vx_z( parent.vx_z, index, this ),
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
   PhotonD3PDObjectElement::PhotonD3PDObjectElement( const PhotonD3PDObjectElement& parent )
      : TObject( parent ),
        CaloPointing_eta( parent.CaloPointing_eta ),
        CaloPointing_sigma_eta( parent.CaloPointing_sigma_eta ),
        CaloPointing_sigma_zvertex( parent.CaloPointing_sigma_zvertex ),
        CaloPointing_zvertex( parent.CaloPointing_zvertex ),
        E( parent.E ),
        E033( parent.E033 ),
        E1152( parent.E1152 ),
        E132( parent.E132 ),
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
        L1_dr( parent.L1_dr ),
        L1_index( parent.L1_index ),
        L2_dr( parent.L2_dr ),
        L2_index( parent.L2_index ),
        NN_discriminant( parent.NN_discriminant ),
        NN_passes( parent.NN_passes ),
        OQ( parent.OQ ),
        Rconv( parent.Rconv ),
        adaboost( parent.adaboost ),
        author( parent.author ),
        calibHitsShowerDepth( parent.calibHitsShowerDepth ),
        cl_E( parent.cl_E ),
        cl_eta( parent.cl_eta ),
        cl_phi( parent.cl_phi ),
        cl_pt( parent.cl_pt ),
        convFlag( parent.convFlag ),
        convIP( parent.convIP ),
        convIPRev( parent.convIPRev ),
        convMatchDeltaEta1( parent.convMatchDeltaEta1 ),
        convMatchDeltaEta2( parent.convMatchDeltaEta2 ),
        convMatchDeltaPhi1( parent.convMatchDeltaPhi1 ),
        convMatchDeltaPhi2( parent.convMatchDeltaPhi2 ),
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
        depth( parent.depth ),
        el_index( parent.el_index ),
        emaxs1( parent.emaxs1 ),
        errz( parent.errz ),
        eta( parent.eta ),
        etacellS0( parent.etacellS0 ),
        etap( parent.etap ),
        etas0( parent.etas0 ),
        etas1( parent.etas1 ),
        etas2( parent.etas2 ),
        etas3( parent.etas3 ),
        f1( parent.f1 ),
        f1core( parent.f1core ),
        f3( parent.f3 ),
        f3core( parent.f3core ),
        fside( parent.fside ),
        goodOQ( parent.goodOQ ),
        hasconv( parent.hasconv ),
        isConv( parent.isConv ),
        isEM( parent.isEM ),
        isEMLoose( parent.isEMLoose ),
        isEMMedium( parent.isEMMedium ),
        isEMTight( parent.isEMTight ),
        isIso( parent.isIso ),
        isRecovered( parent.isRecovered ),
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
        loglikelihood( parent.loglikelihood ),
        loose( parent.loose ),
        looseAR( parent.looseAR ),
        looseARIso( parent.looseARIso ),
        looseIso( parent.looseIso ),
        m( parent.m ),
        mvaptcone20( parent.mvaptcone20 ),
        mvaptcone30( parent.mvaptcone30 ),
        mvaptcone40( parent.mvaptcone40 ),
        nConv( parent.nConv ),
        nDoubleTrackConv( parent.nDoubleTrackConv ),
        nSingleTrackConv( parent.nSingleTrackConv ),
        neuralnet( parent.neuralnet ),
        nucone20( parent.nucone20 ),
        nucone30( parent.nucone30 ),
        nucone40( parent.nucone40 ),
        origin( parent.origin ),
        phi( parent.phi ),
        phis0( parent.phis0 ),
        phis1( parent.phis1 ),
        phis2( parent.phis2 ),
        phis3( parent.phis3 ),
        photonbgweight( parent.photonbgweight ),
        photonweight( parent.photonweight ),
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
        cl_etaCalo( parent.cl_etaCalo ),
        cl_phiCalo( parent.cl_phiCalo ),
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
        reta( parent.reta ),
        ringernn( parent.ringernn ),
        rings_E( parent.rings_E ),
        rphi( parent.rphi ),
        rphiallcalo( parent.rphiallcalo ),
        tight( parent.tight ),
        tightAR( parent.tightAR ),
        tightARIso( parent.tightARIso ),
        tightIso( parent.tightIso ),
        topoEMdr( parent.topoEMdr ),
        topoEMeta( parent.topoEMeta ),
        topoEMmatched( parent.topoEMmatched ),
        topoEMphi( parent.topoEMphi ),
        topoEMpt( parent.topoEMpt ),
        topoEtcone20( parent.topoEtcone20 ),
        topoEtcone20_corrected( parent.topoEtcone20_corrected ),
        topoEtcone30( parent.topoEtcone30 ),
        topoEtcone30_corrected( parent.topoEtcone30_corrected ),
        topoEtcone40( parent.topoEtcone40 ),
        topoEtcone40_corrected( parent.topoEtcone40_corrected ),
        topoEtcone60( parent.topoEtcone60 ),
        topodr( parent.topodr ),
        topoeta( parent.topoeta ),
        topomatched( parent.topomatched ),
        topophi( parent.topophi ),
        topopt( parent.topopt ),
        truth_E( parent.truth_E ),
        truth_Rconv( parent.truth_Rconv ),
        truth_barcode( parent.truth_barcode ),
        truth_deltaRRecPhoton( parent.truth_deltaRRecPhoton ),
        truth_eta( parent.truth_eta ),
        truth_index( parent.truth_index ),
        truth_isBrem( parent.truth_isBrem ),
        truth_isConv( parent.truth_isConv ),
        truth_isFromHardProc( parent.truth_isFromHardProc ),
        truth_isPhotonFromHardProc( parent.truth_isPhotonFromHardProc ),
        truth_matched( parent.truth_matched ),
        truth_motherbarcode( parent.truth_motherbarcode ),
        truth_mothertype( parent.truth_mothertype ),
        truth_phi( parent.truth_phi ),
        truth_pt( parent.truth_pt ),
        truth_status( parent.truth_status ),
        truth_type( parent.truth_type ),
        truth_zconv( parent.truth_zconv ),
        type( parent.type ),
        vx_Chi2( parent.vx_Chi2 ),
        vx_DR1R2( parent.vx_DR1R2 ),
        vx_Dcottheta( parent.vx_Dcottheta ),
        vx_Dist( parent.vx_Dist ),
        vx_Dphi( parent.vx_Dphi ),
        vx_E( parent.vx_E ),
        vx_convTrk_TRTHighTHitsRatio( parent.vx_convTrk_TRTHighTHitsRatio ),
        vx_convTrk_TRTHighTOutliersRatio( parent.vx_convTrk_TRTHighTOutliersRatio ),
        vx_convTrk_chi2( parent.vx_convTrk_chi2 ),
        vx_convTrk_eProbabilityBrem( parent.vx_convTrk_eProbabilityBrem ),
        vx_convTrk_eProbabilityComb( parent.vx_convTrk_eProbabilityComb ),
        vx_convTrk_eProbabilityHT( parent.vx_convTrk_eProbabilityHT ),
        vx_convTrk_eProbabilityToT( parent.vx_convTrk_eProbabilityToT ),
        vx_convTrk_expectBLayerHit( parent.vx_convTrk_expectBLayerHit ),
        vx_convTrk_fitter( parent.vx_convTrk_fitter ),
        vx_convTrk_hitPattern( parent.vx_convTrk_hitPattern ),
        vx_convTrk_n( parent.vx_convTrk_n ),
        vx_convTrk_nBLHits( parent.vx_convTrk_nBLHits ),
        vx_convTrk_nBLSharedHits( parent.vx_convTrk_nBLSharedHits ),
        vx_convTrk_nBLayerOutliers( parent.vx_convTrk_nBLayerOutliers ),
        vx_convTrk_nBLayerSplitHits( parent.vx_convTrk_nBLayerSplitHits ),
        vx_convTrk_nCSCEtaHits( parent.vx_convTrk_nCSCEtaHits ),
        vx_convTrk_nCSCPhiHits( parent.vx_convTrk_nCSCPhiHits ),
        vx_convTrk_nContribPixelLayers( parent.vx_convTrk_nContribPixelLayers ),
        vx_convTrk_nCscEtaHoles( parent.vx_convTrk_nCscEtaHoles ),
        vx_convTrk_nCscPhiHoles( parent.vx_convTrk_nCscPhiHoles ),
        vx_convTrk_nGangedFlaggedFakes( parent.vx_convTrk_nGangedFlaggedFakes ),
        vx_convTrk_nGangedPixels( parent.vx_convTrk_nGangedPixels ),
        vx_convTrk_nHits( parent.vx_convTrk_nHits ),
        vx_convTrk_nHoles( parent.vx_convTrk_nHoles ),
        vx_convTrk_nMDTHits( parent.vx_convTrk_nMDTHits ),
        vx_convTrk_nMdtHoles( parent.vx_convTrk_nMdtHoles ),
        vx_convTrk_nOutliersOnTrack( parent.vx_convTrk_nOutliersOnTrack ),
        vx_convTrk_nPixHits( parent.vx_convTrk_nPixHits ),
        vx_convTrk_nPixHoles( parent.vx_convTrk_nPixHoles ),
        vx_convTrk_nPixSharedHits( parent.vx_convTrk_nPixSharedHits ),
        vx_convTrk_nPixSplitHits( parent.vx_convTrk_nPixSplitHits ),
        vx_convTrk_nPixelDeadSensors( parent.vx_convTrk_nPixelDeadSensors ),
        vx_convTrk_nPixelOutliers( parent.vx_convTrk_nPixelOutliers ),
        vx_convTrk_nPixelSpoiltHits( parent.vx_convTrk_nPixelSpoiltHits ),
        vx_convTrk_nRPCEtaHits( parent.vx_convTrk_nRPCEtaHits ),
        vx_convTrk_nRPCPhiHits( parent.vx_convTrk_nRPCPhiHits ),
        vx_convTrk_nRpcEtaHoles( parent.vx_convTrk_nRpcEtaHoles ),
        vx_convTrk_nRpcPhiHoles( parent.vx_convTrk_nRpcPhiHoles ),
        vx_convTrk_nSCTDeadSensors( parent.vx_convTrk_nSCTDeadSensors ),
        vx_convTrk_nSCTDoubleHoles( parent.vx_convTrk_nSCTDoubleHoles ),
        vx_convTrk_nSCTHits( parent.vx_convTrk_nSCTHits ),
        vx_convTrk_nSCTHoles( parent.vx_convTrk_nSCTHoles ),
        vx_convTrk_nSCTOutliers( parent.vx_convTrk_nSCTOutliers ),
        vx_convTrk_nSCTSharedHits( parent.vx_convTrk_nSCTSharedHits ),
        vx_convTrk_nSCTSpoiltHits( parent.vx_convTrk_nSCTSpoiltHits ),
        vx_convTrk_nSiHits( parent.vx_convTrk_nSiHits ),
        vx_convTrk_nTGCEtaHits( parent.vx_convTrk_nTGCEtaHits ),
        vx_convTrk_nTGCPhiHits( parent.vx_convTrk_nTGCPhiHits ),
        vx_convTrk_nTRTDeadStraws( parent.vx_convTrk_nTRTDeadStraws ),
        vx_convTrk_nTRTHighTHits( parent.vx_convTrk_nTRTHighTHits ),
        vx_convTrk_nTRTHighTOutliers( parent.vx_convTrk_nTRTHighTOutliers ),
        vx_convTrk_nTRTHits( parent.vx_convTrk_nTRTHits ),
        vx_convTrk_nTRTHoles( parent.vx_convTrk_nTRTHoles ),
        vx_convTrk_nTRTOutliers( parent.vx_convTrk_nTRTOutliers ),
        vx_convTrk_nTRTTubeHits( parent.vx_convTrk_nTRTTubeHits ),
        vx_convTrk_nTgcEtaHoles( parent.vx_convTrk_nTgcEtaHoles ),
        vx_convTrk_nTgcPhiHoles( parent.vx_convTrk_nTgcPhiHoles ),
        vx_convTrk_ndof( parent.vx_convTrk_ndof ),
        vx_convTrk_particleHypothesis( parent.vx_convTrk_particleHypothesis ),
        vx_convTrk_patternReco1( parent.vx_convTrk_patternReco1 ),
        vx_convTrk_patternReco2( parent.vx_convTrk_patternReco2 ),
        vx_convTrk_standardDeviationOfChi2OS( parent.vx_convTrk_standardDeviationOfChi2OS ),
        vx_convTrk_trackProperties( parent.vx_convTrk_trackProperties ),
        vx_convTrk_weight( parent.vx_convTrk_weight ),
        vx_m( parent.vx_m ),
        vx_n( parent.vx_n ),
        vx_nTracks( parent.vx_nTracks ),
        vx_px( parent.vx_px ),
        vx_py( parent.vx_py ),
        vx_pz( parent.vx_pz ),
        vx_sumPt( parent.vx_sumPt ),
        vx_x( parent.vx_x ),
        vx_y( parent.vx_y ),
        vx_z( parent.vx_z ),
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
   const PhotonD3PDObject* PhotonD3PDObjectElement::GetParent() const {

      return fParent;
   }

   /**
    * This function can be used to access the index of this proxy object
    * inside the parent container. It can come in handy when optimizing an
    * analysis code.
    *
    * @returns The index of the proxy in the object's parent
    */
   size_t PhotonD3PDObjectElement::GetIndex() const {

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
   PhotonD3PDObject::PhotonD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "CaloPointing_eta" ] = &CaloPointing_eta;
      fHandles[ "CaloPointing_sigma_eta" ] = &CaloPointing_sigma_eta;
      fHandles[ "CaloPointing_sigma_zvertex" ] = &CaloPointing_sigma_zvertex;
      fHandles[ "CaloPointing_zvertex" ] = &CaloPointing_zvertex;
      fHandles[ "E" ] = &E;
      fHandles[ "E033" ] = &E033;
      fHandles[ "E1152" ] = &E1152;
      fHandles[ "E132" ] = &E132;
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
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_index" ] = &L1_index;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_index" ] = &L2_index;
      fHandles[ "NN_discriminant" ] = &NN_discriminant;
      fHandles[ "NN_passes" ] = &NN_passes;
      fHandles[ "OQ" ] = &OQ;
      fHandles[ "Rconv" ] = &Rconv;
      fHandles[ "adaboost" ] = &adaboost;
      fHandles[ "author" ] = &author;
      fHandles[ "calibHitsShowerDepth" ] = &calibHitsShowerDepth;
      fHandles[ "cl_E" ] = &cl_E;
      fHandles[ "cl_eta" ] = &cl_eta;
      fHandles[ "cl_phi" ] = &cl_phi;
      fHandles[ "cl_pt" ] = &cl_pt;
      fHandles[ "convFlag" ] = &convFlag;
      fHandles[ "convIP" ] = &convIP;
      fHandles[ "convIPRev" ] = &convIPRev;
      fHandles[ "convMatchDeltaEta1" ] = &convMatchDeltaEta1;
      fHandles[ "convMatchDeltaEta2" ] = &convMatchDeltaEta2;
      fHandles[ "convMatchDeltaPhi1" ] = &convMatchDeltaPhi1;
      fHandles[ "convMatchDeltaPhi2" ] = &convMatchDeltaPhi2;
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
      fHandles[ "depth" ] = &depth;
      fHandles[ "el_index" ] = &el_index;
      fHandles[ "emaxs1" ] = &emaxs1;
      fHandles[ "errz" ] = &errz;
      fHandles[ "eta" ] = &eta;
      fHandles[ "etacellS0" ] = &etacellS0;
      fHandles[ "etap" ] = &etap;
      fHandles[ "etas0" ] = &etas0;
      fHandles[ "etas1" ] = &etas1;
      fHandles[ "etas2" ] = &etas2;
      fHandles[ "etas3" ] = &etas3;
      fHandles[ "f1" ] = &f1;
      fHandles[ "f1core" ] = &f1core;
      fHandles[ "f3" ] = &f3;
      fHandles[ "f3core" ] = &f3core;
      fHandles[ "fside" ] = &fside;
      fHandles[ "goodOQ" ] = &goodOQ;
      fHandles[ "hasconv" ] = &hasconv;
      fHandles[ "isConv" ] = &isConv;
      fHandles[ "isEM" ] = &isEM;
      fHandles[ "isEMLoose" ] = &isEMLoose;
      fHandles[ "isEMMedium" ] = &isEMMedium;
      fHandles[ "isEMTight" ] = &isEMTight;
      fHandles[ "isIso" ] = &isIso;
      fHandles[ "isRecovered" ] = &isRecovered;
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
      fHandles[ "loglikelihood" ] = &loglikelihood;
      fHandles[ "loose" ] = &loose;
      fHandles[ "looseAR" ] = &looseAR;
      fHandles[ "looseARIso" ] = &looseARIso;
      fHandles[ "looseIso" ] = &looseIso;
      fHandles[ "m" ] = &m;
      fHandles[ "mvaptcone20" ] = &mvaptcone20;
      fHandles[ "mvaptcone30" ] = &mvaptcone30;
      fHandles[ "mvaptcone40" ] = &mvaptcone40;
      fHandles[ "n" ] = &n;
      fHandles[ "nConv" ] = &nConv;
      fHandles[ "nDoubleTrackConv" ] = &nDoubleTrackConv;
      fHandles[ "nSingleTrackConv" ] = &nSingleTrackConv;
      fHandles[ "neuralnet" ] = &neuralnet;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "origin" ] = &origin;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phis0" ] = &phis0;
      fHandles[ "phis1" ] = &phis1;
      fHandles[ "phis2" ] = &phis2;
      fHandles[ "phis3" ] = &phis3;
      fHandles[ "photonbgweight" ] = &photonbgweight;
      fHandles[ "photonweight" ] = &photonweight;
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
      fHandles[ "cl_etaCalo" ] = &cl_etaCalo;
      fHandles[ "cl_phiCalo" ] = &cl_phiCalo;
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
      fHandles[ "reta" ] = &reta;
      fHandles[ "ringernn" ] = &ringernn;
      fHandles[ "rings_E" ] = &rings_E;
      fHandles[ "rphi" ] = &rphi;
      fHandles[ "rphiallcalo" ] = &rphiallcalo;
      fHandles[ "tight" ] = &tight;
      fHandles[ "tightAR" ] = &tightAR;
      fHandles[ "tightARIso" ] = &tightARIso;
      fHandles[ "tightIso" ] = &tightIso;
      fHandles[ "topoEMdr" ] = &topoEMdr;
      fHandles[ "topoEMeta" ] = &topoEMeta;
      fHandles[ "topoEMmatched" ] = &topoEMmatched;
      fHandles[ "topoEMphi" ] = &topoEMphi;
      fHandles[ "topoEMpt" ] = &topoEMpt;
      fHandles[ "topoEtcone20" ] = &topoEtcone20;
      fHandles[ "topoEtcone20_corrected" ] = &topoEtcone20_corrected;
      fHandles[ "topoEtcone30" ] = &topoEtcone30;
      fHandles[ "topoEtcone30_corrected" ] = &topoEtcone30_corrected;
      fHandles[ "topoEtcone40" ] = &topoEtcone40;
      fHandles[ "topoEtcone40_corrected" ] = &topoEtcone40_corrected;
      fHandles[ "topoEtcone60" ] = &topoEtcone60;
      fHandles[ "topodr" ] = &topodr;
      fHandles[ "topoeta" ] = &topoeta;
      fHandles[ "topomatched" ] = &topomatched;
      fHandles[ "topophi" ] = &topophi;
      fHandles[ "topopt" ] = &topopt;
      fHandles[ "truth_E" ] = &truth_E;
      fHandles[ "truth_Rconv" ] = &truth_Rconv;
      fHandles[ "truth_barcode" ] = &truth_barcode;
      fHandles[ "truth_deltaRRecPhoton" ] = &truth_deltaRRecPhoton;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_index" ] = &truth_index;
      fHandles[ "truth_isBrem" ] = &truth_isBrem;
      fHandles[ "truth_isConv" ] = &truth_isConv;
      fHandles[ "truth_isFromHardProc" ] = &truth_isFromHardProc;
      fHandles[ "truth_isPhotonFromHardProc" ] = &truth_isPhotonFromHardProc;
      fHandles[ "truth_matched" ] = &truth_matched;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "truth_zconv" ] = &truth_zconv;
      fHandles[ "type" ] = &type;
      fHandles[ "vx_Chi2" ] = &vx_Chi2;
      fHandles[ "vx_DR1R2" ] = &vx_DR1R2;
      fHandles[ "vx_Dcottheta" ] = &vx_Dcottheta;
      fHandles[ "vx_Dist" ] = &vx_Dist;
      fHandles[ "vx_Dphi" ] = &vx_Dphi;
      fHandles[ "vx_E" ] = &vx_E;
      fHandles[ "vx_convTrk_TRTHighTHitsRatio" ] = &vx_convTrk_TRTHighTHitsRatio;
      fHandles[ "vx_convTrk_TRTHighTOutliersRatio" ] = &vx_convTrk_TRTHighTOutliersRatio;
      fHandles[ "vx_convTrk_chi2" ] = &vx_convTrk_chi2;
      fHandles[ "vx_convTrk_eProbabilityBrem" ] = &vx_convTrk_eProbabilityBrem;
      fHandles[ "vx_convTrk_eProbabilityComb" ] = &vx_convTrk_eProbabilityComb;
      fHandles[ "vx_convTrk_eProbabilityHT" ] = &vx_convTrk_eProbabilityHT;
      fHandles[ "vx_convTrk_eProbabilityToT" ] = &vx_convTrk_eProbabilityToT;
      fHandles[ "vx_convTrk_expectBLayerHit" ] = &vx_convTrk_expectBLayerHit;
      fHandles[ "vx_convTrk_fitter" ] = &vx_convTrk_fitter;
      fHandles[ "vx_convTrk_hitPattern" ] = &vx_convTrk_hitPattern;
      fHandles[ "vx_convTrk_n" ] = &vx_convTrk_n;
      fHandles[ "vx_convTrk_nBLHits" ] = &vx_convTrk_nBLHits;
      fHandles[ "vx_convTrk_nBLSharedHits" ] = &vx_convTrk_nBLSharedHits;
      fHandles[ "vx_convTrk_nBLayerOutliers" ] = &vx_convTrk_nBLayerOutliers;
      fHandles[ "vx_convTrk_nBLayerSplitHits" ] = &vx_convTrk_nBLayerSplitHits;
      fHandles[ "vx_convTrk_nCSCEtaHits" ] = &vx_convTrk_nCSCEtaHits;
      fHandles[ "vx_convTrk_nCSCPhiHits" ] = &vx_convTrk_nCSCPhiHits;
      fHandles[ "vx_convTrk_nContribPixelLayers" ] = &vx_convTrk_nContribPixelLayers;
      fHandles[ "vx_convTrk_nCscEtaHoles" ] = &vx_convTrk_nCscEtaHoles;
      fHandles[ "vx_convTrk_nCscPhiHoles" ] = &vx_convTrk_nCscPhiHoles;
      fHandles[ "vx_convTrk_nGangedFlaggedFakes" ] = &vx_convTrk_nGangedFlaggedFakes;
      fHandles[ "vx_convTrk_nGangedPixels" ] = &vx_convTrk_nGangedPixels;
      fHandles[ "vx_convTrk_nHits" ] = &vx_convTrk_nHits;
      fHandles[ "vx_convTrk_nHoles" ] = &vx_convTrk_nHoles;
      fHandles[ "vx_convTrk_nMDTHits" ] = &vx_convTrk_nMDTHits;
      fHandles[ "vx_convTrk_nMdtHoles" ] = &vx_convTrk_nMdtHoles;
      fHandles[ "vx_convTrk_nOutliersOnTrack" ] = &vx_convTrk_nOutliersOnTrack;
      fHandles[ "vx_convTrk_nPixHits" ] = &vx_convTrk_nPixHits;
      fHandles[ "vx_convTrk_nPixHoles" ] = &vx_convTrk_nPixHoles;
      fHandles[ "vx_convTrk_nPixSharedHits" ] = &vx_convTrk_nPixSharedHits;
      fHandles[ "vx_convTrk_nPixSplitHits" ] = &vx_convTrk_nPixSplitHits;
      fHandles[ "vx_convTrk_nPixelDeadSensors" ] = &vx_convTrk_nPixelDeadSensors;
      fHandles[ "vx_convTrk_nPixelOutliers" ] = &vx_convTrk_nPixelOutliers;
      fHandles[ "vx_convTrk_nPixelSpoiltHits" ] = &vx_convTrk_nPixelSpoiltHits;
      fHandles[ "vx_convTrk_nRPCEtaHits" ] = &vx_convTrk_nRPCEtaHits;
      fHandles[ "vx_convTrk_nRPCPhiHits" ] = &vx_convTrk_nRPCPhiHits;
      fHandles[ "vx_convTrk_nRpcEtaHoles" ] = &vx_convTrk_nRpcEtaHoles;
      fHandles[ "vx_convTrk_nRpcPhiHoles" ] = &vx_convTrk_nRpcPhiHoles;
      fHandles[ "vx_convTrk_nSCTDeadSensors" ] = &vx_convTrk_nSCTDeadSensors;
      fHandles[ "vx_convTrk_nSCTDoubleHoles" ] = &vx_convTrk_nSCTDoubleHoles;
      fHandles[ "vx_convTrk_nSCTHits" ] = &vx_convTrk_nSCTHits;
      fHandles[ "vx_convTrk_nSCTHoles" ] = &vx_convTrk_nSCTHoles;
      fHandles[ "vx_convTrk_nSCTOutliers" ] = &vx_convTrk_nSCTOutliers;
      fHandles[ "vx_convTrk_nSCTSharedHits" ] = &vx_convTrk_nSCTSharedHits;
      fHandles[ "vx_convTrk_nSCTSpoiltHits" ] = &vx_convTrk_nSCTSpoiltHits;
      fHandles[ "vx_convTrk_nSiHits" ] = &vx_convTrk_nSiHits;
      fHandles[ "vx_convTrk_nTGCEtaHits" ] = &vx_convTrk_nTGCEtaHits;
      fHandles[ "vx_convTrk_nTGCPhiHits" ] = &vx_convTrk_nTGCPhiHits;
      fHandles[ "vx_convTrk_nTRTDeadStraws" ] = &vx_convTrk_nTRTDeadStraws;
      fHandles[ "vx_convTrk_nTRTHighTHits" ] = &vx_convTrk_nTRTHighTHits;
      fHandles[ "vx_convTrk_nTRTHighTOutliers" ] = &vx_convTrk_nTRTHighTOutliers;
      fHandles[ "vx_convTrk_nTRTHits" ] = &vx_convTrk_nTRTHits;
      fHandles[ "vx_convTrk_nTRTHoles" ] = &vx_convTrk_nTRTHoles;
      fHandles[ "vx_convTrk_nTRTOutliers" ] = &vx_convTrk_nTRTOutliers;
      fHandles[ "vx_convTrk_nTRTTubeHits" ] = &vx_convTrk_nTRTTubeHits;
      fHandles[ "vx_convTrk_nTgcEtaHoles" ] = &vx_convTrk_nTgcEtaHoles;
      fHandles[ "vx_convTrk_nTgcPhiHoles" ] = &vx_convTrk_nTgcPhiHoles;
      fHandles[ "vx_convTrk_ndof" ] = &vx_convTrk_ndof;
      fHandles[ "vx_convTrk_particleHypothesis" ] = &vx_convTrk_particleHypothesis;
      fHandles[ "vx_convTrk_patternReco1" ] = &vx_convTrk_patternReco1;
      fHandles[ "vx_convTrk_patternReco2" ] = &vx_convTrk_patternReco2;
      fHandles[ "vx_convTrk_standardDeviationOfChi2OS" ] = &vx_convTrk_standardDeviationOfChi2OS;
      fHandles[ "vx_convTrk_trackProperties" ] = &vx_convTrk_trackProperties;
      fHandles[ "vx_convTrk_weight" ] = &vx_convTrk_weight;
      fHandles[ "vx_m" ] = &vx_m;
      fHandles[ "vx_n" ] = &vx_n;
      fHandles[ "vx_nTracks" ] = &vx_nTracks;
      fHandles[ "vx_px" ] = &vx_px;
      fHandles[ "vx_py" ] = &vx_py;
      fHandles[ "vx_pz" ] = &vx_pz;
      fHandles[ "vx_sumPt" ] = &vx_sumPt;
      fHandles[ "vx_x" ] = &vx_x;
      fHandles[ "vx_y" ] = &vx_y;
      fHandles[ "vx_z" ] = &vx_z;
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
   PhotonD3PDObject::PhotonD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "CaloPointing_eta" ] = &CaloPointing_eta;
      fHandles[ "CaloPointing_sigma_eta" ] = &CaloPointing_sigma_eta;
      fHandles[ "CaloPointing_sigma_zvertex" ] = &CaloPointing_sigma_zvertex;
      fHandles[ "CaloPointing_zvertex" ] = &CaloPointing_zvertex;
      fHandles[ "E" ] = &E;
      fHandles[ "E033" ] = &E033;
      fHandles[ "E1152" ] = &E1152;
      fHandles[ "E132" ] = &E132;
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
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_index" ] = &L1_index;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_index" ] = &L2_index;
      fHandles[ "NN_discriminant" ] = &NN_discriminant;
      fHandles[ "NN_passes" ] = &NN_passes;
      fHandles[ "OQ" ] = &OQ;
      fHandles[ "Rconv" ] = &Rconv;
      fHandles[ "adaboost" ] = &adaboost;
      fHandles[ "author" ] = &author;
      fHandles[ "calibHitsShowerDepth" ] = &calibHitsShowerDepth;
      fHandles[ "cl_E" ] = &cl_E;
      fHandles[ "cl_eta" ] = &cl_eta;
      fHandles[ "cl_phi" ] = &cl_phi;
      fHandles[ "cl_pt" ] = &cl_pt;
      fHandles[ "convFlag" ] = &convFlag;
      fHandles[ "convIP" ] = &convIP;
      fHandles[ "convIPRev" ] = &convIPRev;
      fHandles[ "convMatchDeltaEta1" ] = &convMatchDeltaEta1;
      fHandles[ "convMatchDeltaEta2" ] = &convMatchDeltaEta2;
      fHandles[ "convMatchDeltaPhi1" ] = &convMatchDeltaPhi1;
      fHandles[ "convMatchDeltaPhi2" ] = &convMatchDeltaPhi2;
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
      fHandles[ "depth" ] = &depth;
      fHandles[ "el_index" ] = &el_index;
      fHandles[ "emaxs1" ] = &emaxs1;
      fHandles[ "errz" ] = &errz;
      fHandles[ "eta" ] = &eta;
      fHandles[ "etacellS0" ] = &etacellS0;
      fHandles[ "etap" ] = &etap;
      fHandles[ "etas0" ] = &etas0;
      fHandles[ "etas1" ] = &etas1;
      fHandles[ "etas2" ] = &etas2;
      fHandles[ "etas3" ] = &etas3;
      fHandles[ "f1" ] = &f1;
      fHandles[ "f1core" ] = &f1core;
      fHandles[ "f3" ] = &f3;
      fHandles[ "f3core" ] = &f3core;
      fHandles[ "fside" ] = &fside;
      fHandles[ "goodOQ" ] = &goodOQ;
      fHandles[ "hasconv" ] = &hasconv;
      fHandles[ "isConv" ] = &isConv;
      fHandles[ "isEM" ] = &isEM;
      fHandles[ "isEMLoose" ] = &isEMLoose;
      fHandles[ "isEMMedium" ] = &isEMMedium;
      fHandles[ "isEMTight" ] = &isEMTight;
      fHandles[ "isIso" ] = &isIso;
      fHandles[ "isRecovered" ] = &isRecovered;
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
      fHandles[ "loglikelihood" ] = &loglikelihood;
      fHandles[ "loose" ] = &loose;
      fHandles[ "looseAR" ] = &looseAR;
      fHandles[ "looseARIso" ] = &looseARIso;
      fHandles[ "looseIso" ] = &looseIso;
      fHandles[ "m" ] = &m;
      fHandles[ "mvaptcone20" ] = &mvaptcone20;
      fHandles[ "mvaptcone30" ] = &mvaptcone30;
      fHandles[ "mvaptcone40" ] = &mvaptcone40;
      fHandles[ "n" ] = &n;
      fHandles[ "nConv" ] = &nConv;
      fHandles[ "nDoubleTrackConv" ] = &nDoubleTrackConv;
      fHandles[ "nSingleTrackConv" ] = &nSingleTrackConv;
      fHandles[ "neuralnet" ] = &neuralnet;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "origin" ] = &origin;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phis0" ] = &phis0;
      fHandles[ "phis1" ] = &phis1;
      fHandles[ "phis2" ] = &phis2;
      fHandles[ "phis3" ] = &phis3;
      fHandles[ "photonbgweight" ] = &photonbgweight;
      fHandles[ "photonweight" ] = &photonweight;
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
      fHandles[ "cl_etaCalo" ] = &cl_etaCalo;
      fHandles[ "cl_phiCalo" ] = &cl_phiCalo;
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
      fHandles[ "reta" ] = &reta;
      fHandles[ "ringernn" ] = &ringernn;
      fHandles[ "rings_E" ] = &rings_E;
      fHandles[ "rphi" ] = &rphi;
      fHandles[ "rphiallcalo" ] = &rphiallcalo;
      fHandles[ "tight" ] = &tight;
      fHandles[ "tightAR" ] = &tightAR;
      fHandles[ "tightARIso" ] = &tightARIso;
      fHandles[ "tightIso" ] = &tightIso;
      fHandles[ "topoEMdr" ] = &topoEMdr;
      fHandles[ "topoEMeta" ] = &topoEMeta;
      fHandles[ "topoEMmatched" ] = &topoEMmatched;
      fHandles[ "topoEMphi" ] = &topoEMphi;
      fHandles[ "topoEMpt" ] = &topoEMpt;
      fHandles[ "topoEtcone20" ] = &topoEtcone20;
      fHandles[ "topoEtcone20_corrected" ] = &topoEtcone20_corrected;
      fHandles[ "topoEtcone30" ] = &topoEtcone30;
      fHandles[ "topoEtcone30_corrected" ] = &topoEtcone30_corrected;
      fHandles[ "topoEtcone40" ] = &topoEtcone40;
      fHandles[ "topoEtcone40_corrected" ] = &topoEtcone40_corrected;
      fHandles[ "topoEtcone60" ] = &topoEtcone60;
      fHandles[ "topodr" ] = &topodr;
      fHandles[ "topoeta" ] = &topoeta;
      fHandles[ "topomatched" ] = &topomatched;
      fHandles[ "topophi" ] = &topophi;
      fHandles[ "topopt" ] = &topopt;
      fHandles[ "truth_E" ] = &truth_E;
      fHandles[ "truth_Rconv" ] = &truth_Rconv;
      fHandles[ "truth_barcode" ] = &truth_barcode;
      fHandles[ "truth_deltaRRecPhoton" ] = &truth_deltaRRecPhoton;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_index" ] = &truth_index;
      fHandles[ "truth_isBrem" ] = &truth_isBrem;
      fHandles[ "truth_isConv" ] = &truth_isConv;
      fHandles[ "truth_isFromHardProc" ] = &truth_isFromHardProc;
      fHandles[ "truth_isPhotonFromHardProc" ] = &truth_isPhotonFromHardProc;
      fHandles[ "truth_matched" ] = &truth_matched;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "truth_zconv" ] = &truth_zconv;
      fHandles[ "type" ] = &type;
      fHandles[ "vx_Chi2" ] = &vx_Chi2;
      fHandles[ "vx_DR1R2" ] = &vx_DR1R2;
      fHandles[ "vx_Dcottheta" ] = &vx_Dcottheta;
      fHandles[ "vx_Dist" ] = &vx_Dist;
      fHandles[ "vx_Dphi" ] = &vx_Dphi;
      fHandles[ "vx_E" ] = &vx_E;
      fHandles[ "vx_convTrk_TRTHighTHitsRatio" ] = &vx_convTrk_TRTHighTHitsRatio;
      fHandles[ "vx_convTrk_TRTHighTOutliersRatio" ] = &vx_convTrk_TRTHighTOutliersRatio;
      fHandles[ "vx_convTrk_chi2" ] = &vx_convTrk_chi2;
      fHandles[ "vx_convTrk_eProbabilityBrem" ] = &vx_convTrk_eProbabilityBrem;
      fHandles[ "vx_convTrk_eProbabilityComb" ] = &vx_convTrk_eProbabilityComb;
      fHandles[ "vx_convTrk_eProbabilityHT" ] = &vx_convTrk_eProbabilityHT;
      fHandles[ "vx_convTrk_eProbabilityToT" ] = &vx_convTrk_eProbabilityToT;
      fHandles[ "vx_convTrk_expectBLayerHit" ] = &vx_convTrk_expectBLayerHit;
      fHandles[ "vx_convTrk_fitter" ] = &vx_convTrk_fitter;
      fHandles[ "vx_convTrk_hitPattern" ] = &vx_convTrk_hitPattern;
      fHandles[ "vx_convTrk_n" ] = &vx_convTrk_n;
      fHandles[ "vx_convTrk_nBLHits" ] = &vx_convTrk_nBLHits;
      fHandles[ "vx_convTrk_nBLSharedHits" ] = &vx_convTrk_nBLSharedHits;
      fHandles[ "vx_convTrk_nBLayerOutliers" ] = &vx_convTrk_nBLayerOutliers;
      fHandles[ "vx_convTrk_nBLayerSplitHits" ] = &vx_convTrk_nBLayerSplitHits;
      fHandles[ "vx_convTrk_nCSCEtaHits" ] = &vx_convTrk_nCSCEtaHits;
      fHandles[ "vx_convTrk_nCSCPhiHits" ] = &vx_convTrk_nCSCPhiHits;
      fHandles[ "vx_convTrk_nContribPixelLayers" ] = &vx_convTrk_nContribPixelLayers;
      fHandles[ "vx_convTrk_nCscEtaHoles" ] = &vx_convTrk_nCscEtaHoles;
      fHandles[ "vx_convTrk_nCscPhiHoles" ] = &vx_convTrk_nCscPhiHoles;
      fHandles[ "vx_convTrk_nGangedFlaggedFakes" ] = &vx_convTrk_nGangedFlaggedFakes;
      fHandles[ "vx_convTrk_nGangedPixels" ] = &vx_convTrk_nGangedPixels;
      fHandles[ "vx_convTrk_nHits" ] = &vx_convTrk_nHits;
      fHandles[ "vx_convTrk_nHoles" ] = &vx_convTrk_nHoles;
      fHandles[ "vx_convTrk_nMDTHits" ] = &vx_convTrk_nMDTHits;
      fHandles[ "vx_convTrk_nMdtHoles" ] = &vx_convTrk_nMdtHoles;
      fHandles[ "vx_convTrk_nOutliersOnTrack" ] = &vx_convTrk_nOutliersOnTrack;
      fHandles[ "vx_convTrk_nPixHits" ] = &vx_convTrk_nPixHits;
      fHandles[ "vx_convTrk_nPixHoles" ] = &vx_convTrk_nPixHoles;
      fHandles[ "vx_convTrk_nPixSharedHits" ] = &vx_convTrk_nPixSharedHits;
      fHandles[ "vx_convTrk_nPixSplitHits" ] = &vx_convTrk_nPixSplitHits;
      fHandles[ "vx_convTrk_nPixelDeadSensors" ] = &vx_convTrk_nPixelDeadSensors;
      fHandles[ "vx_convTrk_nPixelOutliers" ] = &vx_convTrk_nPixelOutliers;
      fHandles[ "vx_convTrk_nPixelSpoiltHits" ] = &vx_convTrk_nPixelSpoiltHits;
      fHandles[ "vx_convTrk_nRPCEtaHits" ] = &vx_convTrk_nRPCEtaHits;
      fHandles[ "vx_convTrk_nRPCPhiHits" ] = &vx_convTrk_nRPCPhiHits;
      fHandles[ "vx_convTrk_nRpcEtaHoles" ] = &vx_convTrk_nRpcEtaHoles;
      fHandles[ "vx_convTrk_nRpcPhiHoles" ] = &vx_convTrk_nRpcPhiHoles;
      fHandles[ "vx_convTrk_nSCTDeadSensors" ] = &vx_convTrk_nSCTDeadSensors;
      fHandles[ "vx_convTrk_nSCTDoubleHoles" ] = &vx_convTrk_nSCTDoubleHoles;
      fHandles[ "vx_convTrk_nSCTHits" ] = &vx_convTrk_nSCTHits;
      fHandles[ "vx_convTrk_nSCTHoles" ] = &vx_convTrk_nSCTHoles;
      fHandles[ "vx_convTrk_nSCTOutliers" ] = &vx_convTrk_nSCTOutliers;
      fHandles[ "vx_convTrk_nSCTSharedHits" ] = &vx_convTrk_nSCTSharedHits;
      fHandles[ "vx_convTrk_nSCTSpoiltHits" ] = &vx_convTrk_nSCTSpoiltHits;
      fHandles[ "vx_convTrk_nSiHits" ] = &vx_convTrk_nSiHits;
      fHandles[ "vx_convTrk_nTGCEtaHits" ] = &vx_convTrk_nTGCEtaHits;
      fHandles[ "vx_convTrk_nTGCPhiHits" ] = &vx_convTrk_nTGCPhiHits;
      fHandles[ "vx_convTrk_nTRTDeadStraws" ] = &vx_convTrk_nTRTDeadStraws;
      fHandles[ "vx_convTrk_nTRTHighTHits" ] = &vx_convTrk_nTRTHighTHits;
      fHandles[ "vx_convTrk_nTRTHighTOutliers" ] = &vx_convTrk_nTRTHighTOutliers;
      fHandles[ "vx_convTrk_nTRTHits" ] = &vx_convTrk_nTRTHits;
      fHandles[ "vx_convTrk_nTRTHoles" ] = &vx_convTrk_nTRTHoles;
      fHandles[ "vx_convTrk_nTRTOutliers" ] = &vx_convTrk_nTRTOutliers;
      fHandles[ "vx_convTrk_nTRTTubeHits" ] = &vx_convTrk_nTRTTubeHits;
      fHandles[ "vx_convTrk_nTgcEtaHoles" ] = &vx_convTrk_nTgcEtaHoles;
      fHandles[ "vx_convTrk_nTgcPhiHoles" ] = &vx_convTrk_nTgcPhiHoles;
      fHandles[ "vx_convTrk_ndof" ] = &vx_convTrk_ndof;
      fHandles[ "vx_convTrk_particleHypothesis" ] = &vx_convTrk_particleHypothesis;
      fHandles[ "vx_convTrk_patternReco1" ] = &vx_convTrk_patternReco1;
      fHandles[ "vx_convTrk_patternReco2" ] = &vx_convTrk_patternReco2;
      fHandles[ "vx_convTrk_standardDeviationOfChi2OS" ] = &vx_convTrk_standardDeviationOfChi2OS;
      fHandles[ "vx_convTrk_trackProperties" ] = &vx_convTrk_trackProperties;
      fHandles[ "vx_convTrk_weight" ] = &vx_convTrk_weight;
      fHandles[ "vx_m" ] = &vx_m;
      fHandles[ "vx_n" ] = &vx_n;
      fHandles[ "vx_nTracks" ] = &vx_nTracks;
      fHandles[ "vx_px" ] = &vx_px;
      fHandles[ "vx_py" ] = &vx_py;
      fHandles[ "vx_pz" ] = &vx_pz;
      fHandles[ "vx_sumPt" ] = &vx_sumPt;
      fHandles[ "vx_x" ] = &vx_x;
      fHandles[ "vx_y" ] = &vx_y;
      fHandles[ "vx_z" ] = &vx_z;
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
   PhotonD3PDObject::~PhotonD3PDObject() {

      for( size_t i = 0; i < fProxies.size(); ++i ) {
         delete fProxies[ i ];
      }
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* PhotonD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void PhotonD3PDObject::SetPrefix( const char* prefix ) {

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
   void PhotonD3PDObject::ReadFrom( TTree* tree ) {

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
   void PhotonD3PDObject::WriteTo( TTree* tree ) {

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
   void PhotonD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void PhotonD3PDObject::ReadAllActive() {

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

   D3PDReadStats PhotonD3PDObject::GetStatistics() const {

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
   PhotonD3PDObject& PhotonD3PDObject::Set( const PhotonD3PDObject& parent ) {

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
      if( parent.E033.IsAvailable() ) {
         *( E033() ) = *( parent.E033() );
      } else {
         E033()->clear();
      }
      if( parent.E1152.IsAvailable() ) {
         *( E1152() ) = *( parent.E1152() );
      } else {
         E1152()->clear();
      }
      if( parent.E132.IsAvailable() ) {
         *( E132() ) = *( parent.E132() );
      } else {
         E132()->clear();
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
      if( parent.L1_dr.IsAvailable() ) {
         *( L1_dr() ) = *( parent.L1_dr() );
      } else {
         L1_dr()->clear();
      }
      if( parent.L1_index.IsAvailable() ) {
         *( L1_index() ) = *( parent.L1_index() );
      } else {
         L1_index()->clear();
      }
      if( parent.L2_dr.IsAvailable() ) {
         *( L2_dr() ) = *( parent.L2_dr() );
      } else {
         L2_dr()->clear();
      }
      if( parent.L2_index.IsAvailable() ) {
         *( L2_index() ) = *( parent.L2_index() );
      } else {
         L2_index()->clear();
      }
      if( parent.NN_discriminant.IsAvailable() ) {
         *( NN_discriminant() ) = *( parent.NN_discriminant() );
      } else {
         NN_discriminant()->clear();
      }
      if( parent.NN_passes.IsAvailable() ) {
         *( NN_passes() ) = *( parent.NN_passes() );
      } else {
         NN_passes()->clear();
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
      if( parent.convIP.IsAvailable() ) {
         *( convIP() ) = *( parent.convIP() );
      } else {
         convIP()->clear();
      }
      if( parent.convIPRev.IsAvailable() ) {
         *( convIPRev() ) = *( parent.convIPRev() );
      } else {
         convIPRev()->clear();
      }
      if( parent.convMatchDeltaEta1.IsAvailable() ) {
         *( convMatchDeltaEta1() ) = *( parent.convMatchDeltaEta1() );
      } else {
         convMatchDeltaEta1()->clear();
      }
      if( parent.convMatchDeltaEta2.IsAvailable() ) {
         *( convMatchDeltaEta2() ) = *( parent.convMatchDeltaEta2() );
      } else {
         convMatchDeltaEta2()->clear();
      }
      if( parent.convMatchDeltaPhi1.IsAvailable() ) {
         *( convMatchDeltaPhi1() ) = *( parent.convMatchDeltaPhi1() );
      } else {
         convMatchDeltaPhi1()->clear();
      }
      if( parent.convMatchDeltaPhi2.IsAvailable() ) {
         *( convMatchDeltaPhi2() ) = *( parent.convMatchDeltaPhi2() );
      } else {
         convMatchDeltaPhi2()->clear();
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
      if( parent.depth.IsAvailable() ) {
         *( depth() ) = *( parent.depth() );
      } else {
         depth()->clear();
      }
      if( parent.el_index.IsAvailable() ) {
         *( el_index() ) = *( parent.el_index() );
      } else {
         el_index()->clear();
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
      if( parent.etacellS0.IsAvailable() ) {
         *( etacellS0() ) = *( parent.etacellS0() );
      } else {
         etacellS0()->clear();
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
      if( parent.isRecovered.IsAvailable() ) {
         *( isRecovered() ) = *( parent.isRecovered() );
      } else {
         isRecovered()->clear();
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
      if( parent.loglikelihood.IsAvailable() ) {
         *( loglikelihood() ) = *( parent.loglikelihood() );
      } else {
         loglikelihood()->clear();
      }
      if( parent.loose.IsAvailable() ) {
         *( loose() ) = *( parent.loose() );
      } else {
         loose()->clear();
      }
      if( parent.looseAR.IsAvailable() ) {
         *( looseAR() ) = *( parent.looseAR() );
      } else {
         looseAR()->clear();
      }
      if( parent.looseARIso.IsAvailable() ) {
         *( looseARIso() ) = *( parent.looseARIso() );
      } else {
         looseARIso()->clear();
      }
      if( parent.looseIso.IsAvailable() ) {
         *( looseIso() ) = *( parent.looseIso() );
      } else {
         looseIso()->clear();
      }
      if( parent.m.IsAvailable() ) {
         *( m() ) = *( parent.m() );
      } else {
         m()->clear();
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
      if( parent.nSingleTrackConv.IsAvailable() ) {
         *( nSingleTrackConv() ) = *( parent.nSingleTrackConv() );
      } else {
         nSingleTrackConv()->clear();
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
      if( parent.photonbgweight.IsAvailable() ) {
         *( photonbgweight() ) = *( parent.photonbgweight() );
      } else {
         photonbgweight()->clear();
      }
      if( parent.photonweight.IsAvailable() ) {
         *( photonweight() ) = *( parent.photonweight() );
      } else {
         photonweight()->clear();
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
      if( parent.cl_etaCalo.IsAvailable() ) {
         *( cl_etaCalo() ) = *( parent.cl_etaCalo() );
      } else {
         cl_etaCalo()->clear();
      }
      if( parent.cl_phiCalo.IsAvailable() ) {
         *( cl_phiCalo() ) = *( parent.cl_phiCalo() );
      } else {
         cl_phiCalo()->clear();
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
      if( parent.tight.IsAvailable() ) {
         *( tight() ) = *( parent.tight() );
      } else {
         tight()->clear();
      }
      if( parent.tightAR.IsAvailable() ) {
         *( tightAR() ) = *( parent.tightAR() );
      } else {
         tightAR()->clear();
      }
      if( parent.tightARIso.IsAvailable() ) {
         *( tightARIso() ) = *( parent.tightARIso() );
      } else {
         tightARIso()->clear();
      }
      if( parent.tightIso.IsAvailable() ) {
         *( tightIso() ) = *( parent.tightIso() );
      } else {
         tightIso()->clear();
      }
      if( parent.topoEMdr.IsAvailable() ) {
         *( topoEMdr() ) = *( parent.topoEMdr() );
      } else {
         topoEMdr()->clear();
      }
      if( parent.topoEMeta.IsAvailable() ) {
         *( topoEMeta() ) = *( parent.topoEMeta() );
      } else {
         topoEMeta()->clear();
      }
      if( parent.topoEMmatched.IsAvailable() ) {
         *( topoEMmatched() ) = *( parent.topoEMmatched() );
      } else {
         topoEMmatched()->clear();
      }
      if( parent.topoEMphi.IsAvailable() ) {
         *( topoEMphi() ) = *( parent.topoEMphi() );
      } else {
         topoEMphi()->clear();
      }
      if( parent.topoEMpt.IsAvailable() ) {
         *( topoEMpt() ) = *( parent.topoEMpt() );
      } else {
         topoEMpt()->clear();
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
      if( parent.topodr.IsAvailable() ) {
         *( topodr() ) = *( parent.topodr() );
      } else {
         topodr()->clear();
      }
      if( parent.topoeta.IsAvailable() ) {
         *( topoeta() ) = *( parent.topoeta() );
      } else {
         topoeta()->clear();
      }
      if( parent.topomatched.IsAvailable() ) {
         *( topomatched() ) = *( parent.topomatched() );
      } else {
         topomatched()->clear();
      }
      if( parent.topophi.IsAvailable() ) {
         *( topophi() ) = *( parent.topophi() );
      } else {
         topophi()->clear();
      }
      if( parent.topopt.IsAvailable() ) {
         *( topopt() ) = *( parent.topopt() );
      } else {
         topopt()->clear();
      }
      if( parent.truth_E.IsAvailable() ) {
         *( truth_E() ) = *( parent.truth_E() );
      } else {
         truth_E()->clear();
      }
      if( parent.truth_Rconv.IsAvailable() ) {
         *( truth_Rconv() ) = *( parent.truth_Rconv() );
      } else {
         truth_Rconv()->clear();
      }
      if( parent.truth_barcode.IsAvailable() ) {
         *( truth_barcode() ) = *( parent.truth_barcode() );
      } else {
         truth_barcode()->clear();
      }
      if( parent.truth_deltaRRecPhoton.IsAvailable() ) {
         *( truth_deltaRRecPhoton() ) = *( parent.truth_deltaRRecPhoton() );
      } else {
         truth_deltaRRecPhoton()->clear();
      }
      if( parent.truth_eta.IsAvailable() ) {
         *( truth_eta() ) = *( parent.truth_eta() );
      } else {
         truth_eta()->clear();
      }
      if( parent.truth_index.IsAvailable() ) {
         *( truth_index() ) = *( parent.truth_index() );
      } else {
         truth_index()->clear();
      }
      if( parent.truth_isBrem.IsAvailable() ) {
         *( truth_isBrem() ) = *( parent.truth_isBrem() );
      } else {
         truth_isBrem()->clear();
      }
      if( parent.truth_isConv.IsAvailable() ) {
         *( truth_isConv() ) = *( parent.truth_isConv() );
      } else {
         truth_isConv()->clear();
      }
      if( parent.truth_isFromHardProc.IsAvailable() ) {
         *( truth_isFromHardProc() ) = *( parent.truth_isFromHardProc() );
      } else {
         truth_isFromHardProc()->clear();
      }
      if( parent.truth_isPhotonFromHardProc.IsAvailable() ) {
         *( truth_isPhotonFromHardProc() ) = *( parent.truth_isPhotonFromHardProc() );
      } else {
         truth_isPhotonFromHardProc()->clear();
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
      if( parent.truth_zconv.IsAvailable() ) {
         *( truth_zconv() ) = *( parent.truth_zconv() );
      } else {
         truth_zconv()->clear();
      }
      if( parent.type.IsAvailable() ) {
         *( type() ) = *( parent.type() );
      } else {
         type()->clear();
      }
      if( parent.vx_Chi2.IsAvailable() ) {
         *( vx_Chi2() ) = *( parent.vx_Chi2() );
      } else {
         vx_Chi2()->clear();
      }
      if( parent.vx_DR1R2.IsAvailable() ) {
         *( vx_DR1R2() ) = *( parent.vx_DR1R2() );
      } else {
         vx_DR1R2()->clear();
      }
      if( parent.vx_Dcottheta.IsAvailable() ) {
         *( vx_Dcottheta() ) = *( parent.vx_Dcottheta() );
      } else {
         vx_Dcottheta()->clear();
      }
      if( parent.vx_Dist.IsAvailable() ) {
         *( vx_Dist() ) = *( parent.vx_Dist() );
      } else {
         vx_Dist()->clear();
      }
      if( parent.vx_Dphi.IsAvailable() ) {
         *( vx_Dphi() ) = *( parent.vx_Dphi() );
      } else {
         vx_Dphi()->clear();
      }
      if( parent.vx_E.IsAvailable() ) {
         *( vx_E() ) = *( parent.vx_E() );
      } else {
         vx_E()->clear();
      }
      if( parent.vx_convTrk_TRTHighTHitsRatio.IsAvailable() ) {
         *( vx_convTrk_TRTHighTHitsRatio() ) = *( parent.vx_convTrk_TRTHighTHitsRatio() );
      } else {
         vx_convTrk_TRTHighTHitsRatio()->clear();
      }
      if( parent.vx_convTrk_TRTHighTOutliersRatio.IsAvailable() ) {
         *( vx_convTrk_TRTHighTOutliersRatio() ) = *( parent.vx_convTrk_TRTHighTOutliersRatio() );
      } else {
         vx_convTrk_TRTHighTOutliersRatio()->clear();
      }
      if( parent.vx_convTrk_chi2.IsAvailable() ) {
         *( vx_convTrk_chi2() ) = *( parent.vx_convTrk_chi2() );
      } else {
         vx_convTrk_chi2()->clear();
      }
      if( parent.vx_convTrk_eProbabilityBrem.IsAvailable() ) {
         *( vx_convTrk_eProbabilityBrem() ) = *( parent.vx_convTrk_eProbabilityBrem() );
      } else {
         vx_convTrk_eProbabilityBrem()->clear();
      }
      if( parent.vx_convTrk_eProbabilityComb.IsAvailable() ) {
         *( vx_convTrk_eProbabilityComb() ) = *( parent.vx_convTrk_eProbabilityComb() );
      } else {
         vx_convTrk_eProbabilityComb()->clear();
      }
      if( parent.vx_convTrk_eProbabilityHT.IsAvailable() ) {
         *( vx_convTrk_eProbabilityHT() ) = *( parent.vx_convTrk_eProbabilityHT() );
      } else {
         vx_convTrk_eProbabilityHT()->clear();
      }
      if( parent.vx_convTrk_eProbabilityToT.IsAvailable() ) {
         *( vx_convTrk_eProbabilityToT() ) = *( parent.vx_convTrk_eProbabilityToT() );
      } else {
         vx_convTrk_eProbabilityToT()->clear();
      }
      if( parent.vx_convTrk_expectBLayerHit.IsAvailable() ) {
         *( vx_convTrk_expectBLayerHit() ) = *( parent.vx_convTrk_expectBLayerHit() );
      } else {
         vx_convTrk_expectBLayerHit()->clear();
      }
      if( parent.vx_convTrk_fitter.IsAvailable() ) {
         *( vx_convTrk_fitter() ) = *( parent.vx_convTrk_fitter() );
      } else {
         vx_convTrk_fitter()->clear();
      }
      if( parent.vx_convTrk_hitPattern.IsAvailable() ) {
         *( vx_convTrk_hitPattern() ) = *( parent.vx_convTrk_hitPattern() );
      } else {
         vx_convTrk_hitPattern()->clear();
      }
      if( parent.vx_convTrk_n.IsAvailable() ) {
         *( vx_convTrk_n() ) = *( parent.vx_convTrk_n() );
      } else {
         vx_convTrk_n()->clear();
      }
      if( parent.vx_convTrk_nBLHits.IsAvailable() ) {
         *( vx_convTrk_nBLHits() ) = *( parent.vx_convTrk_nBLHits() );
      } else {
         vx_convTrk_nBLHits()->clear();
      }
      if( parent.vx_convTrk_nBLSharedHits.IsAvailable() ) {
         *( vx_convTrk_nBLSharedHits() ) = *( parent.vx_convTrk_nBLSharedHits() );
      } else {
         vx_convTrk_nBLSharedHits()->clear();
      }
      if( parent.vx_convTrk_nBLayerOutliers.IsAvailable() ) {
         *( vx_convTrk_nBLayerOutliers() ) = *( parent.vx_convTrk_nBLayerOutliers() );
      } else {
         vx_convTrk_nBLayerOutliers()->clear();
      }
      if( parent.vx_convTrk_nBLayerSplitHits.IsAvailable() ) {
         *( vx_convTrk_nBLayerSplitHits() ) = *( parent.vx_convTrk_nBLayerSplitHits() );
      } else {
         vx_convTrk_nBLayerSplitHits()->clear();
      }
      if( parent.vx_convTrk_nCSCEtaHits.IsAvailable() ) {
         *( vx_convTrk_nCSCEtaHits() ) = *( parent.vx_convTrk_nCSCEtaHits() );
      } else {
         vx_convTrk_nCSCEtaHits()->clear();
      }
      if( parent.vx_convTrk_nCSCPhiHits.IsAvailable() ) {
         *( vx_convTrk_nCSCPhiHits() ) = *( parent.vx_convTrk_nCSCPhiHits() );
      } else {
         vx_convTrk_nCSCPhiHits()->clear();
      }
      if( parent.vx_convTrk_nContribPixelLayers.IsAvailable() ) {
         *( vx_convTrk_nContribPixelLayers() ) = *( parent.vx_convTrk_nContribPixelLayers() );
      } else {
         vx_convTrk_nContribPixelLayers()->clear();
      }
      if( parent.vx_convTrk_nCscEtaHoles.IsAvailable() ) {
         *( vx_convTrk_nCscEtaHoles() ) = *( parent.vx_convTrk_nCscEtaHoles() );
      } else {
         vx_convTrk_nCscEtaHoles()->clear();
      }
      if( parent.vx_convTrk_nCscPhiHoles.IsAvailable() ) {
         *( vx_convTrk_nCscPhiHoles() ) = *( parent.vx_convTrk_nCscPhiHoles() );
      } else {
         vx_convTrk_nCscPhiHoles()->clear();
      }
      if( parent.vx_convTrk_nGangedFlaggedFakes.IsAvailable() ) {
         *( vx_convTrk_nGangedFlaggedFakes() ) = *( parent.vx_convTrk_nGangedFlaggedFakes() );
      } else {
         vx_convTrk_nGangedFlaggedFakes()->clear();
      }
      if( parent.vx_convTrk_nGangedPixels.IsAvailable() ) {
         *( vx_convTrk_nGangedPixels() ) = *( parent.vx_convTrk_nGangedPixels() );
      } else {
         vx_convTrk_nGangedPixels()->clear();
      }
      if( parent.vx_convTrk_nHits.IsAvailable() ) {
         *( vx_convTrk_nHits() ) = *( parent.vx_convTrk_nHits() );
      } else {
         vx_convTrk_nHits()->clear();
      }
      if( parent.vx_convTrk_nHoles.IsAvailable() ) {
         *( vx_convTrk_nHoles() ) = *( parent.vx_convTrk_nHoles() );
      } else {
         vx_convTrk_nHoles()->clear();
      }
      if( parent.vx_convTrk_nMDTHits.IsAvailable() ) {
         *( vx_convTrk_nMDTHits() ) = *( parent.vx_convTrk_nMDTHits() );
      } else {
         vx_convTrk_nMDTHits()->clear();
      }
      if( parent.vx_convTrk_nMdtHoles.IsAvailable() ) {
         *( vx_convTrk_nMdtHoles() ) = *( parent.vx_convTrk_nMdtHoles() );
      } else {
         vx_convTrk_nMdtHoles()->clear();
      }
      if( parent.vx_convTrk_nOutliersOnTrack.IsAvailable() ) {
         *( vx_convTrk_nOutliersOnTrack() ) = *( parent.vx_convTrk_nOutliersOnTrack() );
      } else {
         vx_convTrk_nOutliersOnTrack()->clear();
      }
      if( parent.vx_convTrk_nPixHits.IsAvailable() ) {
         *( vx_convTrk_nPixHits() ) = *( parent.vx_convTrk_nPixHits() );
      } else {
         vx_convTrk_nPixHits()->clear();
      }
      if( parent.vx_convTrk_nPixHoles.IsAvailable() ) {
         *( vx_convTrk_nPixHoles() ) = *( parent.vx_convTrk_nPixHoles() );
      } else {
         vx_convTrk_nPixHoles()->clear();
      }
      if( parent.vx_convTrk_nPixSharedHits.IsAvailable() ) {
         *( vx_convTrk_nPixSharedHits() ) = *( parent.vx_convTrk_nPixSharedHits() );
      } else {
         vx_convTrk_nPixSharedHits()->clear();
      }
      if( parent.vx_convTrk_nPixSplitHits.IsAvailable() ) {
         *( vx_convTrk_nPixSplitHits() ) = *( parent.vx_convTrk_nPixSplitHits() );
      } else {
         vx_convTrk_nPixSplitHits()->clear();
      }
      if( parent.vx_convTrk_nPixelDeadSensors.IsAvailable() ) {
         *( vx_convTrk_nPixelDeadSensors() ) = *( parent.vx_convTrk_nPixelDeadSensors() );
      } else {
         vx_convTrk_nPixelDeadSensors()->clear();
      }
      if( parent.vx_convTrk_nPixelOutliers.IsAvailable() ) {
         *( vx_convTrk_nPixelOutliers() ) = *( parent.vx_convTrk_nPixelOutliers() );
      } else {
         vx_convTrk_nPixelOutliers()->clear();
      }
      if( parent.vx_convTrk_nPixelSpoiltHits.IsAvailable() ) {
         *( vx_convTrk_nPixelSpoiltHits() ) = *( parent.vx_convTrk_nPixelSpoiltHits() );
      } else {
         vx_convTrk_nPixelSpoiltHits()->clear();
      }
      if( parent.vx_convTrk_nRPCEtaHits.IsAvailable() ) {
         *( vx_convTrk_nRPCEtaHits() ) = *( parent.vx_convTrk_nRPCEtaHits() );
      } else {
         vx_convTrk_nRPCEtaHits()->clear();
      }
      if( parent.vx_convTrk_nRPCPhiHits.IsAvailable() ) {
         *( vx_convTrk_nRPCPhiHits() ) = *( parent.vx_convTrk_nRPCPhiHits() );
      } else {
         vx_convTrk_nRPCPhiHits()->clear();
      }
      if( parent.vx_convTrk_nRpcEtaHoles.IsAvailable() ) {
         *( vx_convTrk_nRpcEtaHoles() ) = *( parent.vx_convTrk_nRpcEtaHoles() );
      } else {
         vx_convTrk_nRpcEtaHoles()->clear();
      }
      if( parent.vx_convTrk_nRpcPhiHoles.IsAvailable() ) {
         *( vx_convTrk_nRpcPhiHoles() ) = *( parent.vx_convTrk_nRpcPhiHoles() );
      } else {
         vx_convTrk_nRpcPhiHoles()->clear();
      }
      if( parent.vx_convTrk_nSCTDeadSensors.IsAvailable() ) {
         *( vx_convTrk_nSCTDeadSensors() ) = *( parent.vx_convTrk_nSCTDeadSensors() );
      } else {
         vx_convTrk_nSCTDeadSensors()->clear();
      }
      if( parent.vx_convTrk_nSCTDoubleHoles.IsAvailable() ) {
         *( vx_convTrk_nSCTDoubleHoles() ) = *( parent.vx_convTrk_nSCTDoubleHoles() );
      } else {
         vx_convTrk_nSCTDoubleHoles()->clear();
      }
      if( parent.vx_convTrk_nSCTHits.IsAvailable() ) {
         *( vx_convTrk_nSCTHits() ) = *( parent.vx_convTrk_nSCTHits() );
      } else {
         vx_convTrk_nSCTHits()->clear();
      }
      if( parent.vx_convTrk_nSCTHoles.IsAvailable() ) {
         *( vx_convTrk_nSCTHoles() ) = *( parent.vx_convTrk_nSCTHoles() );
      } else {
         vx_convTrk_nSCTHoles()->clear();
      }
      if( parent.vx_convTrk_nSCTOutliers.IsAvailable() ) {
         *( vx_convTrk_nSCTOutliers() ) = *( parent.vx_convTrk_nSCTOutliers() );
      } else {
         vx_convTrk_nSCTOutliers()->clear();
      }
      if( parent.vx_convTrk_nSCTSharedHits.IsAvailable() ) {
         *( vx_convTrk_nSCTSharedHits() ) = *( parent.vx_convTrk_nSCTSharedHits() );
      } else {
         vx_convTrk_nSCTSharedHits()->clear();
      }
      if( parent.vx_convTrk_nSCTSpoiltHits.IsAvailable() ) {
         *( vx_convTrk_nSCTSpoiltHits() ) = *( parent.vx_convTrk_nSCTSpoiltHits() );
      } else {
         vx_convTrk_nSCTSpoiltHits()->clear();
      }
      if( parent.vx_convTrk_nSiHits.IsAvailable() ) {
         *( vx_convTrk_nSiHits() ) = *( parent.vx_convTrk_nSiHits() );
      } else {
         vx_convTrk_nSiHits()->clear();
      }
      if( parent.vx_convTrk_nTGCEtaHits.IsAvailable() ) {
         *( vx_convTrk_nTGCEtaHits() ) = *( parent.vx_convTrk_nTGCEtaHits() );
      } else {
         vx_convTrk_nTGCEtaHits()->clear();
      }
      if( parent.vx_convTrk_nTGCPhiHits.IsAvailable() ) {
         *( vx_convTrk_nTGCPhiHits() ) = *( parent.vx_convTrk_nTGCPhiHits() );
      } else {
         vx_convTrk_nTGCPhiHits()->clear();
      }
      if( parent.vx_convTrk_nTRTDeadStraws.IsAvailable() ) {
         *( vx_convTrk_nTRTDeadStraws() ) = *( parent.vx_convTrk_nTRTDeadStraws() );
      } else {
         vx_convTrk_nTRTDeadStraws()->clear();
      }
      if( parent.vx_convTrk_nTRTHighTHits.IsAvailable() ) {
         *( vx_convTrk_nTRTHighTHits() ) = *( parent.vx_convTrk_nTRTHighTHits() );
      } else {
         vx_convTrk_nTRTHighTHits()->clear();
      }
      if( parent.vx_convTrk_nTRTHighTOutliers.IsAvailable() ) {
         *( vx_convTrk_nTRTHighTOutliers() ) = *( parent.vx_convTrk_nTRTHighTOutliers() );
      } else {
         vx_convTrk_nTRTHighTOutliers()->clear();
      }
      if( parent.vx_convTrk_nTRTHits.IsAvailable() ) {
         *( vx_convTrk_nTRTHits() ) = *( parent.vx_convTrk_nTRTHits() );
      } else {
         vx_convTrk_nTRTHits()->clear();
      }
      if( parent.vx_convTrk_nTRTHoles.IsAvailable() ) {
         *( vx_convTrk_nTRTHoles() ) = *( parent.vx_convTrk_nTRTHoles() );
      } else {
         vx_convTrk_nTRTHoles()->clear();
      }
      if( parent.vx_convTrk_nTRTOutliers.IsAvailable() ) {
         *( vx_convTrk_nTRTOutliers() ) = *( parent.vx_convTrk_nTRTOutliers() );
      } else {
         vx_convTrk_nTRTOutliers()->clear();
      }
      if( parent.vx_convTrk_nTRTTubeHits.IsAvailable() ) {
         *( vx_convTrk_nTRTTubeHits() ) = *( parent.vx_convTrk_nTRTTubeHits() );
      } else {
         vx_convTrk_nTRTTubeHits()->clear();
      }
      if( parent.vx_convTrk_nTgcEtaHoles.IsAvailable() ) {
         *( vx_convTrk_nTgcEtaHoles() ) = *( parent.vx_convTrk_nTgcEtaHoles() );
      } else {
         vx_convTrk_nTgcEtaHoles()->clear();
      }
      if( parent.vx_convTrk_nTgcPhiHoles.IsAvailable() ) {
         *( vx_convTrk_nTgcPhiHoles() ) = *( parent.vx_convTrk_nTgcPhiHoles() );
      } else {
         vx_convTrk_nTgcPhiHoles()->clear();
      }
      if( parent.vx_convTrk_ndof.IsAvailable() ) {
         *( vx_convTrk_ndof() ) = *( parent.vx_convTrk_ndof() );
      } else {
         vx_convTrk_ndof()->clear();
      }
      if( parent.vx_convTrk_particleHypothesis.IsAvailable() ) {
         *( vx_convTrk_particleHypothesis() ) = *( parent.vx_convTrk_particleHypothesis() );
      } else {
         vx_convTrk_particleHypothesis()->clear();
      }
      if( parent.vx_convTrk_patternReco1.IsAvailable() ) {
         *( vx_convTrk_patternReco1() ) = *( parent.vx_convTrk_patternReco1() );
      } else {
         vx_convTrk_patternReco1()->clear();
      }
      if( parent.vx_convTrk_patternReco2.IsAvailable() ) {
         *( vx_convTrk_patternReco2() ) = *( parent.vx_convTrk_patternReco2() );
      } else {
         vx_convTrk_patternReco2()->clear();
      }
      if( parent.vx_convTrk_standardDeviationOfChi2OS.IsAvailable() ) {
         *( vx_convTrk_standardDeviationOfChi2OS() ) = *( parent.vx_convTrk_standardDeviationOfChi2OS() );
      } else {
         vx_convTrk_standardDeviationOfChi2OS()->clear();
      }
      if( parent.vx_convTrk_trackProperties.IsAvailable() ) {
         *( vx_convTrk_trackProperties() ) = *( parent.vx_convTrk_trackProperties() );
      } else {
         vx_convTrk_trackProperties()->clear();
      }
      if( parent.vx_convTrk_weight.IsAvailable() ) {
         *( vx_convTrk_weight() ) = *( parent.vx_convTrk_weight() );
      } else {
         vx_convTrk_weight()->clear();
      }
      if( parent.vx_m.IsAvailable() ) {
         *( vx_m() ) = *( parent.vx_m() );
      } else {
         vx_m()->clear();
      }
      if( parent.vx_n.IsAvailable() ) {
         *( vx_n() ) = *( parent.vx_n() );
      } else {
         vx_n()->clear();
      }
      if( parent.vx_nTracks.IsAvailable() ) {
         *( vx_nTracks() ) = *( parent.vx_nTracks() );
      } else {
         vx_nTracks()->clear();
      }
      if( parent.vx_px.IsAvailable() ) {
         *( vx_px() ) = *( parent.vx_px() );
      } else {
         vx_px()->clear();
      }
      if( parent.vx_py.IsAvailable() ) {
         *( vx_py() ) = *( parent.vx_py() );
      } else {
         vx_py()->clear();
      }
      if( parent.vx_pz.IsAvailable() ) {
         *( vx_pz() ) = *( parent.vx_pz() );
      } else {
         vx_pz()->clear();
      }
      if( parent.vx_sumPt.IsAvailable() ) {
         *( vx_sumPt() ) = *( parent.vx_sumPt() );
      } else {
         vx_sumPt()->clear();
      }
      if( parent.vx_x.IsAvailable() ) {
         *( vx_x() ) = *( parent.vx_x() );
      } else {
         vx_x()->clear();
      }
      if( parent.vx_y.IsAvailable() ) {
         *( vx_y() ) = *( parent.vx_y() );
      } else {
         vx_y()->clear();
      }
      if( parent.vx_z.IsAvailable() ) {
         *( vx_z() ) = *( parent.vx_z() );
      } else {
         vx_z()->clear();
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
   void PhotonD3PDObject::Clear( Option_t* ) {

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
   PhotonD3PDObject& PhotonD3PDObject::Add( const PhotonD3PDObjectElement& el ) {

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
      if( el.E033.IsAvailable() ) {
         E033()->push_back( el.E033() );
      } else {
         E033()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E1152.IsAvailable() ) {
         E1152()->push_back( el.E1152() );
      } else {
         E1152()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E132.IsAvailable() ) {
         E132()->push_back( el.E132() );
      } else {
         E132()->push_back( std::numeric_limits< float >::min() );
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
      if( el.L1_dr.IsAvailable() ) {
         L1_dr()->push_back( el.L1_dr() );
      } else {
         L1_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_index.IsAvailable() ) {
         L1_index()->push_back( el.L1_index() );
      } else {
         L1_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L2_dr.IsAvailable() ) {
         L2_dr()->push_back( el.L2_dr() );
      } else {
         L2_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_index.IsAvailable() ) {
         L2_index()->push_back( el.L2_index() );
      } else {
         L2_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.NN_discriminant.IsAvailable() ) {
         NN_discriminant()->push_back( el.NN_discriminant() );
      } else {
         NN_discriminant()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.NN_passes.IsAvailable() ) {
         NN_passes()->push_back( el.NN_passes() );
      } else {
         NN_passes()->push_back( std::numeric_limits< int >::min() );
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
      if( el.convIP.IsAvailable() ) {
         convIP()->push_back( el.convIP() );
      } else {
         convIP()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convIPRev.IsAvailable() ) {
         convIPRev()->push_back( el.convIPRev() );
      } else {
         convIPRev()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convMatchDeltaEta1.IsAvailable() ) {
         convMatchDeltaEta1()->push_back( el.convMatchDeltaEta1() );
      } else {
         convMatchDeltaEta1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convMatchDeltaEta2.IsAvailable() ) {
         convMatchDeltaEta2()->push_back( el.convMatchDeltaEta2() );
      } else {
         convMatchDeltaEta2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convMatchDeltaPhi1.IsAvailable() ) {
         convMatchDeltaPhi1()->push_back( el.convMatchDeltaPhi1() );
      } else {
         convMatchDeltaPhi1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convMatchDeltaPhi2.IsAvailable() ) {
         convMatchDeltaPhi2()->push_back( el.convMatchDeltaPhi2() );
      } else {
         convMatchDeltaPhi2()->push_back( std::numeric_limits< float >::min() );
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
      if( el.depth.IsAvailable() ) {
         depth()->push_back( el.depth() );
      } else {
         depth()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.el_index.IsAvailable() ) {
         el_index()->push_back( el.el_index() );
      } else {
         el_index()->push_back( std::numeric_limits< int >::min() );
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
      if( el.etacellS0.IsAvailable() ) {
         etacellS0()->push_back( el.etacellS0() );
      } else {
         etacellS0()->push_back( std::numeric_limits< float >::min() );
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
      if( el.isRecovered.IsAvailable() ) {
         isRecovered()->push_back( el.isRecovered() );
      } else {
         isRecovered()->push_back( std::numeric_limits< int >::min() );
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
      if( el.loglikelihood.IsAvailable() ) {
         loglikelihood()->push_back( el.loglikelihood() );
      } else {
         loglikelihood()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.loose.IsAvailable() ) {
         loose()->push_back( el.loose() );
      } else {
         loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.looseAR.IsAvailable() ) {
         looseAR()->push_back( el.looseAR() );
      } else {
         looseAR()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.looseARIso.IsAvailable() ) {
         looseARIso()->push_back( el.looseARIso() );
      } else {
         looseARIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.looseIso.IsAvailable() ) {
         looseIso()->push_back( el.looseIso() );
      } else {
         looseIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
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
      if( el.nSingleTrackConv.IsAvailable() ) {
         nSingleTrackConv()->push_back( el.nSingleTrackConv() );
      } else {
         nSingleTrackConv()->push_back( std::numeric_limits< int >::min() );
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
      if( el.photonbgweight.IsAvailable() ) {
         photonbgweight()->push_back( el.photonbgweight() );
      } else {
         photonbgweight()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.photonweight.IsAvailable() ) {
         photonweight()->push_back( el.photonweight() );
      } else {
         photonweight()->push_back( std::numeric_limits< double >::min() );
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
      if( el.cl_etaCalo.IsAvailable() ) {
         cl_etaCalo()->push_back( el.cl_etaCalo() );
      } else {
         cl_etaCalo()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.cl_phiCalo.IsAvailable() ) {
         cl_phiCalo()->push_back( el.cl_phiCalo() );
      } else {
         cl_phiCalo()->push_back( std::numeric_limits< double >::min() );
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
      if( el.tight.IsAvailable() ) {
         tight()->push_back( el.tight() );
      } else {
         tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightAR.IsAvailable() ) {
         tightAR()->push_back( el.tightAR() );
      } else {
         tightAR()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightARIso.IsAvailable() ) {
         tightARIso()->push_back( el.tightARIso() );
      } else {
         tightARIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightIso.IsAvailable() ) {
         tightIso()->push_back( el.tightIso() );
      } else {
         tightIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.topoEMdr.IsAvailable() ) {
         topoEMdr()->push_back( el.topoEMdr() );
      } else {
         topoEMdr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEMeta.IsAvailable() ) {
         topoEMeta()->push_back( el.topoEMeta() );
      } else {
         topoEMeta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEMmatched.IsAvailable() ) {
         topoEMmatched()->push_back( el.topoEMmatched() );
      } else {
         topoEMmatched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.topoEMphi.IsAvailable() ) {
         topoEMphi()->push_back( el.topoEMphi() );
      } else {
         topoEMphi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEMpt.IsAvailable() ) {
         topoEMpt()->push_back( el.topoEMpt() );
      } else {
         topoEMpt()->push_back( std::numeric_limits< float >::min() );
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
      if( el.topodr.IsAvailable() ) {
         topodr()->push_back( el.topodr() );
      } else {
         topodr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoeta.IsAvailable() ) {
         topoeta()->push_back( el.topoeta() );
      } else {
         topoeta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topomatched.IsAvailable() ) {
         topomatched()->push_back( el.topomatched() );
      } else {
         topomatched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.topophi.IsAvailable() ) {
         topophi()->push_back( el.topophi() );
      } else {
         topophi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topopt.IsAvailable() ) {
         topopt()->push_back( el.topopt() );
      } else {
         topopt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_E.IsAvailable() ) {
         truth_E()->push_back( el.truth_E() );
      } else {
         truth_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_Rconv.IsAvailable() ) {
         truth_Rconv()->push_back( el.truth_Rconv() );
      } else {
         truth_Rconv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_barcode.IsAvailable() ) {
         truth_barcode()->push_back( el.truth_barcode() );
      } else {
         truth_barcode()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_deltaRRecPhoton.IsAvailable() ) {
         truth_deltaRRecPhoton()->push_back( el.truth_deltaRRecPhoton() );
      } else {
         truth_deltaRRecPhoton()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_eta.IsAvailable() ) {
         truth_eta()->push_back( el.truth_eta() );
      } else {
         truth_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_index.IsAvailable() ) {
         truth_index()->push_back( el.truth_index() );
      } else {
         truth_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_isBrem.IsAvailable() ) {
         truth_isBrem()->push_back( el.truth_isBrem() );
      } else {
         truth_isBrem()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_isConv.IsAvailable() ) {
         truth_isConv()->push_back( el.truth_isConv() );
      } else {
         truth_isConv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_isFromHardProc.IsAvailable() ) {
         truth_isFromHardProc()->push_back( el.truth_isFromHardProc() );
      } else {
         truth_isFromHardProc()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_isPhotonFromHardProc.IsAvailable() ) {
         truth_isPhotonFromHardProc()->push_back( el.truth_isPhotonFromHardProc() );
      } else {
         truth_isPhotonFromHardProc()->push_back( std::numeric_limits< int >::min() );
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
      if( el.truth_zconv.IsAvailable() ) {
         truth_zconv()->push_back( el.truth_zconv() );
      } else {
         truth_zconv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.type.IsAvailable() ) {
         type()->push_back( el.type() );
      } else {
         type()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.vx_Chi2.IsAvailable() ) {
         vx_Chi2()->push_back( el.vx_Chi2() );
      } else {
         vx_Chi2()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_DR1R2.IsAvailable() ) {
         vx_DR1R2()->push_back( el.vx_DR1R2() );
      } else {
         vx_DR1R2()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_Dcottheta.IsAvailable() ) {
         vx_Dcottheta()->push_back( el.vx_Dcottheta() );
      } else {
         vx_Dcottheta()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_Dist.IsAvailable() ) {
         vx_Dist()->push_back( el.vx_Dist() );
      } else {
         vx_Dist()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_Dphi.IsAvailable() ) {
         vx_Dphi()->push_back( el.vx_Dphi() );
      } else {
         vx_Dphi()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_E.IsAvailable() ) {
         vx_E()->push_back( el.vx_E() );
      } else {
         vx_E()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_convTrk_TRTHighTHitsRatio.IsAvailable() ) {
         vx_convTrk_TRTHighTHitsRatio()->push_back( el.vx_convTrk_TRTHighTHitsRatio() );
      } else {
         vx_convTrk_TRTHighTHitsRatio()->push_back( std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >() );
      }
      if( el.vx_convTrk_TRTHighTOutliersRatio.IsAvailable() ) {
         vx_convTrk_TRTHighTOutliersRatio()->push_back( el.vx_convTrk_TRTHighTOutliersRatio() );
      } else {
         vx_convTrk_TRTHighTOutliersRatio()->push_back( std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >() );
      }
      if( el.vx_convTrk_chi2.IsAvailable() ) {
         vx_convTrk_chi2()->push_back( el.vx_convTrk_chi2() );
      } else {
         vx_convTrk_chi2()->push_back( std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >() );
      }
      if( el.vx_convTrk_eProbabilityBrem.IsAvailable() ) {
         vx_convTrk_eProbabilityBrem()->push_back( el.vx_convTrk_eProbabilityBrem() );
      } else {
         vx_convTrk_eProbabilityBrem()->push_back( std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >() );
      }
      if( el.vx_convTrk_eProbabilityComb.IsAvailable() ) {
         vx_convTrk_eProbabilityComb()->push_back( el.vx_convTrk_eProbabilityComb() );
      } else {
         vx_convTrk_eProbabilityComb()->push_back( std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >() );
      }
      if( el.vx_convTrk_eProbabilityHT.IsAvailable() ) {
         vx_convTrk_eProbabilityHT()->push_back( el.vx_convTrk_eProbabilityHT() );
      } else {
         vx_convTrk_eProbabilityHT()->push_back( std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >() );
      }
      if( el.vx_convTrk_eProbabilityToT.IsAvailable() ) {
         vx_convTrk_eProbabilityToT()->push_back( el.vx_convTrk_eProbabilityToT() );
      } else {
         vx_convTrk_eProbabilityToT()->push_back( std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >() );
      }
      if( el.vx_convTrk_expectBLayerHit.IsAvailable() ) {
         vx_convTrk_expectBLayerHit()->push_back( el.vx_convTrk_expectBLayerHit() );
      } else {
         vx_convTrk_expectBLayerHit()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_fitter.IsAvailable() ) {
         vx_convTrk_fitter()->push_back( el.vx_convTrk_fitter() );
      } else {
         vx_convTrk_fitter()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_hitPattern.IsAvailable() ) {
         vx_convTrk_hitPattern()->push_back( el.vx_convTrk_hitPattern() );
      } else {
         vx_convTrk_hitPattern()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_n.IsAvailable() ) {
         vx_convTrk_n()->push_back( el.vx_convTrk_n() );
      } else {
         vx_convTrk_n()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.vx_convTrk_nBLHits.IsAvailable() ) {
         vx_convTrk_nBLHits()->push_back( el.vx_convTrk_nBLHits() );
      } else {
         vx_convTrk_nBLHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nBLSharedHits.IsAvailable() ) {
         vx_convTrk_nBLSharedHits()->push_back( el.vx_convTrk_nBLSharedHits() );
      } else {
         vx_convTrk_nBLSharedHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nBLayerOutliers.IsAvailable() ) {
         vx_convTrk_nBLayerOutliers()->push_back( el.vx_convTrk_nBLayerOutliers() );
      } else {
         vx_convTrk_nBLayerOutliers()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nBLayerSplitHits.IsAvailable() ) {
         vx_convTrk_nBLayerSplitHits()->push_back( el.vx_convTrk_nBLayerSplitHits() );
      } else {
         vx_convTrk_nBLayerSplitHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nCSCEtaHits.IsAvailable() ) {
         vx_convTrk_nCSCEtaHits()->push_back( el.vx_convTrk_nCSCEtaHits() );
      } else {
         vx_convTrk_nCSCEtaHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nCSCPhiHits.IsAvailable() ) {
         vx_convTrk_nCSCPhiHits()->push_back( el.vx_convTrk_nCSCPhiHits() );
      } else {
         vx_convTrk_nCSCPhiHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nContribPixelLayers.IsAvailable() ) {
         vx_convTrk_nContribPixelLayers()->push_back( el.vx_convTrk_nContribPixelLayers() );
      } else {
         vx_convTrk_nContribPixelLayers()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nCscEtaHoles.IsAvailable() ) {
         vx_convTrk_nCscEtaHoles()->push_back( el.vx_convTrk_nCscEtaHoles() );
      } else {
         vx_convTrk_nCscEtaHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nCscPhiHoles.IsAvailable() ) {
         vx_convTrk_nCscPhiHoles()->push_back( el.vx_convTrk_nCscPhiHoles() );
      } else {
         vx_convTrk_nCscPhiHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nGangedFlaggedFakes.IsAvailable() ) {
         vx_convTrk_nGangedFlaggedFakes()->push_back( el.vx_convTrk_nGangedFlaggedFakes() );
      } else {
         vx_convTrk_nGangedFlaggedFakes()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nGangedPixels.IsAvailable() ) {
         vx_convTrk_nGangedPixels()->push_back( el.vx_convTrk_nGangedPixels() );
      } else {
         vx_convTrk_nGangedPixels()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nHits.IsAvailable() ) {
         vx_convTrk_nHits()->push_back( el.vx_convTrk_nHits() );
      } else {
         vx_convTrk_nHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nHoles.IsAvailable() ) {
         vx_convTrk_nHoles()->push_back( el.vx_convTrk_nHoles() );
      } else {
         vx_convTrk_nHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nMDTHits.IsAvailable() ) {
         vx_convTrk_nMDTHits()->push_back( el.vx_convTrk_nMDTHits() );
      } else {
         vx_convTrk_nMDTHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nMdtHoles.IsAvailable() ) {
         vx_convTrk_nMdtHoles()->push_back( el.vx_convTrk_nMdtHoles() );
      } else {
         vx_convTrk_nMdtHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nOutliersOnTrack.IsAvailable() ) {
         vx_convTrk_nOutliersOnTrack()->push_back( el.vx_convTrk_nOutliersOnTrack() );
      } else {
         vx_convTrk_nOutliersOnTrack()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nPixHits.IsAvailable() ) {
         vx_convTrk_nPixHits()->push_back( el.vx_convTrk_nPixHits() );
      } else {
         vx_convTrk_nPixHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nPixHoles.IsAvailable() ) {
         vx_convTrk_nPixHoles()->push_back( el.vx_convTrk_nPixHoles() );
      } else {
         vx_convTrk_nPixHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nPixSharedHits.IsAvailable() ) {
         vx_convTrk_nPixSharedHits()->push_back( el.vx_convTrk_nPixSharedHits() );
      } else {
         vx_convTrk_nPixSharedHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nPixSplitHits.IsAvailable() ) {
         vx_convTrk_nPixSplitHits()->push_back( el.vx_convTrk_nPixSplitHits() );
      } else {
         vx_convTrk_nPixSplitHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nPixelDeadSensors.IsAvailable() ) {
         vx_convTrk_nPixelDeadSensors()->push_back( el.vx_convTrk_nPixelDeadSensors() );
      } else {
         vx_convTrk_nPixelDeadSensors()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nPixelOutliers.IsAvailable() ) {
         vx_convTrk_nPixelOutliers()->push_back( el.vx_convTrk_nPixelOutliers() );
      } else {
         vx_convTrk_nPixelOutliers()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nPixelSpoiltHits.IsAvailable() ) {
         vx_convTrk_nPixelSpoiltHits()->push_back( el.vx_convTrk_nPixelSpoiltHits() );
      } else {
         vx_convTrk_nPixelSpoiltHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nRPCEtaHits.IsAvailable() ) {
         vx_convTrk_nRPCEtaHits()->push_back( el.vx_convTrk_nRPCEtaHits() );
      } else {
         vx_convTrk_nRPCEtaHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nRPCPhiHits.IsAvailable() ) {
         vx_convTrk_nRPCPhiHits()->push_back( el.vx_convTrk_nRPCPhiHits() );
      } else {
         vx_convTrk_nRPCPhiHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nRpcEtaHoles.IsAvailable() ) {
         vx_convTrk_nRpcEtaHoles()->push_back( el.vx_convTrk_nRpcEtaHoles() );
      } else {
         vx_convTrk_nRpcEtaHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nRpcPhiHoles.IsAvailable() ) {
         vx_convTrk_nRpcPhiHoles()->push_back( el.vx_convTrk_nRpcPhiHoles() );
      } else {
         vx_convTrk_nRpcPhiHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nSCTDeadSensors.IsAvailable() ) {
         vx_convTrk_nSCTDeadSensors()->push_back( el.vx_convTrk_nSCTDeadSensors() );
      } else {
         vx_convTrk_nSCTDeadSensors()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nSCTDoubleHoles.IsAvailable() ) {
         vx_convTrk_nSCTDoubleHoles()->push_back( el.vx_convTrk_nSCTDoubleHoles() );
      } else {
         vx_convTrk_nSCTDoubleHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nSCTHits.IsAvailable() ) {
         vx_convTrk_nSCTHits()->push_back( el.vx_convTrk_nSCTHits() );
      } else {
         vx_convTrk_nSCTHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nSCTHoles.IsAvailable() ) {
         vx_convTrk_nSCTHoles()->push_back( el.vx_convTrk_nSCTHoles() );
      } else {
         vx_convTrk_nSCTHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nSCTOutliers.IsAvailable() ) {
         vx_convTrk_nSCTOutliers()->push_back( el.vx_convTrk_nSCTOutliers() );
      } else {
         vx_convTrk_nSCTOutliers()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nSCTSharedHits.IsAvailable() ) {
         vx_convTrk_nSCTSharedHits()->push_back( el.vx_convTrk_nSCTSharedHits() );
      } else {
         vx_convTrk_nSCTSharedHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nSCTSpoiltHits.IsAvailable() ) {
         vx_convTrk_nSCTSpoiltHits()->push_back( el.vx_convTrk_nSCTSpoiltHits() );
      } else {
         vx_convTrk_nSCTSpoiltHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nSiHits.IsAvailable() ) {
         vx_convTrk_nSiHits()->push_back( el.vx_convTrk_nSiHits() );
      } else {
         vx_convTrk_nSiHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTGCEtaHits.IsAvailable() ) {
         vx_convTrk_nTGCEtaHits()->push_back( el.vx_convTrk_nTGCEtaHits() );
      } else {
         vx_convTrk_nTGCEtaHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTGCPhiHits.IsAvailable() ) {
         vx_convTrk_nTGCPhiHits()->push_back( el.vx_convTrk_nTGCPhiHits() );
      } else {
         vx_convTrk_nTGCPhiHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTRTDeadStraws.IsAvailable() ) {
         vx_convTrk_nTRTDeadStraws()->push_back( el.vx_convTrk_nTRTDeadStraws() );
      } else {
         vx_convTrk_nTRTDeadStraws()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTRTHighTHits.IsAvailable() ) {
         vx_convTrk_nTRTHighTHits()->push_back( el.vx_convTrk_nTRTHighTHits() );
      } else {
         vx_convTrk_nTRTHighTHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTRTHighTOutliers.IsAvailable() ) {
         vx_convTrk_nTRTHighTOutliers()->push_back( el.vx_convTrk_nTRTHighTOutliers() );
      } else {
         vx_convTrk_nTRTHighTOutliers()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTRTHits.IsAvailable() ) {
         vx_convTrk_nTRTHits()->push_back( el.vx_convTrk_nTRTHits() );
      } else {
         vx_convTrk_nTRTHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTRTHoles.IsAvailable() ) {
         vx_convTrk_nTRTHoles()->push_back( el.vx_convTrk_nTRTHoles() );
      } else {
         vx_convTrk_nTRTHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTRTOutliers.IsAvailable() ) {
         vx_convTrk_nTRTOutliers()->push_back( el.vx_convTrk_nTRTOutliers() );
      } else {
         vx_convTrk_nTRTOutliers()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTRTTubeHits.IsAvailable() ) {
         vx_convTrk_nTRTTubeHits()->push_back( el.vx_convTrk_nTRTTubeHits() );
      } else {
         vx_convTrk_nTRTTubeHits()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTgcEtaHoles.IsAvailable() ) {
         vx_convTrk_nTgcEtaHoles()->push_back( el.vx_convTrk_nTgcEtaHoles() );
      } else {
         vx_convTrk_nTgcEtaHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_nTgcPhiHoles.IsAvailable() ) {
         vx_convTrk_nTgcPhiHoles()->push_back( el.vx_convTrk_nTgcPhiHoles() );
      } else {
         vx_convTrk_nTgcPhiHoles()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_ndof.IsAvailable() ) {
         vx_convTrk_ndof()->push_back( el.vx_convTrk_ndof() );
      } else {
         vx_convTrk_ndof()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_particleHypothesis.IsAvailable() ) {
         vx_convTrk_particleHypothesis()->push_back( el.vx_convTrk_particleHypothesis() );
      } else {
         vx_convTrk_particleHypothesis()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_patternReco1.IsAvailable() ) {
         vx_convTrk_patternReco1()->push_back( el.vx_convTrk_patternReco1() );
      } else {
         vx_convTrk_patternReco1()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_patternReco2.IsAvailable() ) {
         vx_convTrk_patternReco2()->push_back( el.vx_convTrk_patternReco2() );
      } else {
         vx_convTrk_patternReco2()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_standardDeviationOfChi2OS.IsAvailable() ) {
         vx_convTrk_standardDeviationOfChi2OS()->push_back( el.vx_convTrk_standardDeviationOfChi2OS() );
      } else {
         vx_convTrk_standardDeviationOfChi2OS()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_trackProperties.IsAvailable() ) {
         vx_convTrk_trackProperties()->push_back( el.vx_convTrk_trackProperties() );
      } else {
         vx_convTrk_trackProperties()->push_back( std::vector<std::vector<int,std::allocator<int> >,std::allocator<std::vector<int,std::allocator<int> > > >() );
      }
      if( el.vx_convTrk_weight.IsAvailable() ) {
         vx_convTrk_weight()->push_back( el.vx_convTrk_weight() );
      } else {
         vx_convTrk_weight()->push_back( std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >() );
      }
      if( el.vx_m.IsAvailable() ) {
         vx_m()->push_back( el.vx_m() );
      } else {
         vx_m()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_n.IsAvailable() ) {
         vx_n()->push_back( el.vx_n() );
      } else {
         vx_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.vx_nTracks.IsAvailable() ) {
         vx_nTracks()->push_back( el.vx_nTracks() );
      } else {
         vx_nTracks()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.vx_px.IsAvailable() ) {
         vx_px()->push_back( el.vx_px() );
      } else {
         vx_px()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_py.IsAvailable() ) {
         vx_py()->push_back( el.vx_py() );
      } else {
         vx_py()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_pz.IsAvailable() ) {
         vx_pz()->push_back( el.vx_pz() );
      } else {
         vx_pz()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_sumPt.IsAvailable() ) {
         vx_sumPt()->push_back( el.vx_sumPt() );
      } else {
         vx_sumPt()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_x.IsAvailable() ) {
         vx_x()->push_back( el.vx_x() );
      } else {
         vx_x()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_y.IsAvailable() ) {
         vx_y()->push_back( el.vx_y() );
      } else {
         vx_y()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.vx_z.IsAvailable() ) {
         vx_z()->push_back( el.vx_z() );
      } else {
         vx_z()->push_back( std::vector<float,std::allocator<float> >() );
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
   PhotonD3PDObjectElement& PhotonD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new PhotonD3PDObjectElement( fProxies.size(), *this ) );
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
   const PhotonD3PDObjectElement& PhotonD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new PhotonD3PDObjectElement( fProxies.size(), *this ) );
      }
      return *fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   PhotonD3PDObject& PhotonD3PDObject::operator+=( const PhotonD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
