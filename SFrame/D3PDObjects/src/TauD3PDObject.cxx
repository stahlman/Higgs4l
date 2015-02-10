// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/TauD3PDObject.h"

ClassImp( D3PDReader::TauD3PDObjectElement )
ClassImp( D3PDReader::TauD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class TauD3PDObject.
    */
   TauD3PDObjectElement::TauD3PDObjectElement( size_t index, const TauD3PDObject& parent )
      : BDTEleScore( parent.BDTEleScore, index, this ),
        BDTJetScore( parent.BDTJetScore, index, this ),
        EF_E( parent.EF_E, index, this ),
        EF_Et( parent.EF_Et, index, this ),
        EF_dr( parent.EF_dr, index, this ),
        EF_eta( parent.EF_eta, index, this ),
        EF_matched( parent.EF_matched, index, this ),
        EF_phi( parent.EF_phi, index, this ),
        EF_pt( parent.EF_pt, index, this ),
        EM_TES_scale( parent.EM_TES_scale, index, this ),
        EleBDTLoose( parent.EleBDTLoose, index, this ),
        EleBDTMedium( parent.EleBDTMedium, index, this ),
        EleBDTTight( parent.EleBDTTight, index, this ),
        Et( parent.Et, index, this ),
        JetBDTSigLoose( parent.JetBDTSigLoose, index, this ),
        JetBDTSigMedium( parent.JetBDTSigMedium, index, this ),
        JetBDTSigTight( parent.JetBDTSigTight, index, this ),
        L1_Et( parent.L1_Et, index, this ),
        L1_dr( parent.L1_dr, index, this ),
        L1_eta( parent.L1_eta, index, this ),
        L1_matched( parent.L1_matched, index, this ),
        L1_phi( parent.L1_phi, index, this ),
        L1_pt( parent.L1_pt, index, this ),
        L2_E( parent.L2_E, index, this ),
        L2_Et( parent.L2_Et, index, this ),
        L2_dr( parent.L2_dr, index, this ),
        L2_eta( parent.L2_eta, index, this ),
        L2_matched( parent.L2_matched, index, this ),
        L2_phi( parent.L2_phi, index, this ),
        L2_pt( parent.L2_pt, index, this ),
        LC_TES_precalib( parent.LC_TES_precalib, index, this ),
        RoIWord( parent.RoIWord, index, this ),
        SafeLikelihood( parent.SafeLikelihood, index, this ),
        TRTHTOverLT_LeadTrk( parent.TRTHTOverLT_LeadTrk, index, this ),
        author( parent.author, index, this ),
        calcVars_ChPiEMEOverCaloEME( parent.calcVars_ChPiEMEOverCaloEME, index, this ),
        calcVars_EMFractionAtEMScale( parent.calcVars_EMFractionAtEMScale, index, this ),
        calcVars_EMPOverTrkSysP( parent.calcVars_EMPOverTrkSysP, index, this ),
        calcVars_PSSFraction( parent.calcVars_PSSFraction, index, this ),
        calcVars_calRadius( parent.calcVars_calRadius, index, this ),
        calcVars_corrCentFrac( parent.calcVars_corrCentFrac, index, this ),
        calcVars_corrFTrk( parent.calcVars_corrFTrk, index, this ),
        calcVars_drMin( parent.calcVars_drMin, index, this ),
        calcVars_etEM_EMScale_Pt3Trks( parent.calcVars_etEM_EMScale_Pt3Trks, index, this ),
        calcVars_etHad_EMScale_Pt3Trks( parent.calcVars_etHad_EMScale_Pt3Trks, index, this ),
        calcVars_interAxis_eta( parent.calcVars_interAxis_eta, index, this ),
        calcVars_interAxis_phi( parent.calcVars_interAxis_phi, index, this ),
        calcVars_ipSigLeadLooseTrk( parent.calcVars_ipSigLeadLooseTrk, index, this ),
        calcVars_pi0BDTPrimaryScore( parent.calcVars_pi0BDTPrimaryScore, index, this ),
        calcVars_pi0BDTSecondaryScore( parent.calcVars_pi0BDTSecondaryScore, index, this ),
        calcVars_trackIso( parent.calcVars_trackIso, index, this ),
        cellBasedEnergyRing1( parent.cellBasedEnergyRing1, index, this ),
        cellBasedEnergyRing2( parent.cellBasedEnergyRing2, index, this ),
        cellBasedEnergyRing3( parent.cellBasedEnergyRing3, index, this ),
        cellBasedEnergyRing4( parent.cellBasedEnergyRing4, index, this ),
        cellBasedEnergyRing5( parent.cellBasedEnergyRing5, index, this ),
        cellBasedEnergyRing6( parent.cellBasedEnergyRing6, index, this ),
        cellBasedEnergyRing7( parent.cellBasedEnergyRing7, index, this ),
        charge( parent.charge, index, this ),
        chrgLooseTrk( parent.chrgLooseTrk, index, this ),
        effTopoInvMass( parent.effTopoInvMass, index, this ),
        effTopoMeanDeltaR( parent.effTopoMeanDeltaR, index, this ),
        ele_E237E277( parent.ele_E237E277, index, this ),
        ele_ECALFirstFraction( parent.ele_ECALFirstFraction, index, this ),
        ele_PresamplerFraction( parent.ele_PresamplerFraction, index, this ),
        electronVetoLoose( parent.electronVetoLoose, index, this ),
        electronVetoMedium( parent.electronVetoMedium, index, this ),
        electronVetoTight( parent.electronVetoTight, index, this ),
        etEflow( parent.etEflow, index, this ),
        etOverPtLeadLooseTrk( parent.etOverPtLeadLooseTrk, index, this ),
        etOverPtLeadTrk( parent.etOverPtLeadTrk, index, this ),
        eta( parent.eta, index, this ),
        ipSigLeadLooseTrk( parent.ipSigLeadLooseTrk, index, this ),
        ipSigLeadTrk( parent.ipSigLeadTrk, index, this ),
        ipZ0SinThetaSigLeadTrk( parent.ipZ0SinThetaSigLeadTrk, index, this ),
        leadLooseTrkPt( parent.leadLooseTrkPt, index, this ),
        leadTrack_eta( parent.leadTrack_eta, index, this ),
        leadTrack_phi( parent.leadTrack_phi, index, this ),
        leadTrkPt( parent.leadTrkPt, index, this ),
        likelihood( parent.likelihood, index, this ),
        m( parent.m, index, this ),
        mEflow( parent.mEflow, index, this ),
        massTrkSys( parent.massTrkSys, index, this ),
        muonVeto( parent.muonVeto, index, this ),
        nLooseConvTrk( parent.nLooseConvTrk, index, this ),
        nLooseTrk( parent.nLooseTrk, index, this ),
        nOtherTrk( parent.nOtherTrk, index, this ),
        nPi0( parent.nPi0, index, this ),
        nProng( parent.nProng, index, this ),
        nProngLoose( parent.nProngLoose, index, this ),
        numCells( parent.numCells, index, this ),
        numEffTopoClusters( parent.numEffTopoClusters, index, this ),
        numTopoClusters( parent.numTopoClusters, index, this ),
        numTrack( parent.numTrack, index, this ),
        otherTrk_atTJVA_n( parent.otherTrk_atTJVA_n, index, this ),
        otherTrk_n( parent.otherTrk_n, index, this ),
        phi( parent.phi, index, this ),
        pt( parent.pt, index, this ),
        seedCalo_EMRadius( parent.seedCalo_EMRadius, index, this ),
        seedCalo_caloIso( parent.seedCalo_caloIso, index, this ),
        seedCalo_caloIsoCorrected( parent.seedCalo_caloIsoCorrected, index, this ),
        seedCalo_centFrac( parent.seedCalo_centFrac, index, this ),
        seedCalo_dRmax( parent.seedCalo_dRmax, index, this ),
        seedCalo_etEMAtEMScale( parent.seedCalo_etEMAtEMScale, index, this ),
        seedCalo_etEMCalib( parent.seedCalo_etEMCalib, index, this ),
        seedCalo_etHadAtEMScale( parent.seedCalo_etHadAtEMScale, index, this ),
        seedCalo_etHadCalib( parent.seedCalo_etHadCalib, index, this ),
        seedCalo_eta( parent.seedCalo_eta, index, this ),
        seedCalo_hadRadius( parent.seedCalo_hadRadius, index, this ),
        seedCalo_isolFrac( parent.seedCalo_isolFrac, index, this ),
        seedCalo_lead2ClusterEOverAllClusterE( parent.seedCalo_lead2ClusterEOverAllClusterE, index, this ),
        seedCalo_lead3ClusterEOverAllClusterE( parent.seedCalo_lead3ClusterEOverAllClusterE, index, this ),
        seedCalo_nIsolLooseTrk( parent.seedCalo_nIsolLooseTrk, index, this ),
        seedCalo_nStrip( parent.seedCalo_nStrip, index, this ),
        seedCalo_nWideTrk( parent.seedCalo_nWideTrk, index, this ),
        seedCalo_numTrack( parent.seedCalo_numTrack, index, this ),
        seedCalo_phi( parent.seedCalo_phi, index, this ),
        seedCalo_stripWidth2( parent.seedCalo_stripWidth2, index, this ),
        seedCalo_track_n( parent.seedCalo_track_n, index, this ),
        seedCalo_trkAvgDist( parent.seedCalo_trkAvgDist, index, this ),
        seedCalo_trkRmsDist( parent.seedCalo_trkRmsDist, index, this ),
        seedCalo_wideTrk_atTJVA_n( parent.seedCalo_wideTrk_atTJVA_n, index, this ),
        seedCalo_wideTrk_n( parent.seedCalo_wideTrk_n, index, this ),
        seedTrk_EMRadius( parent.seedTrk_EMRadius, index, this ),
        seedTrk_etChrgEM( parent.seedTrk_etChrgEM, index, this ),
        seedTrk_etChrgHad( parent.seedTrk_etChrgHad, index, this ),
        seedTrk_etChrgHadOverSumTrkPt( parent.seedTrk_etChrgHadOverSumTrkPt, index, this ),
        seedTrk_etEMAtEMScale( parent.seedTrk_etEMAtEMScale, index, this ),
        seedTrk_etEMCL( parent.seedTrk_etEMCL, index, this ),
        seedTrk_etHadAtEMScale( parent.seedTrk_etHadAtEMScale, index, this ),
        seedTrk_etIsolEM( parent.seedTrk_etIsolEM, index, this ),
        seedTrk_etIsolHad( parent.seedTrk_etIsolHad, index, this ),
        seedTrk_etNeuEM( parent.seedTrk_etNeuEM, index, this ),
        seedTrk_etResNeuEM( parent.seedTrk_etResNeuEM, index, this ),
        seedTrk_hadLeakEt( parent.seedTrk_hadLeakEt, index, this ),
        seedTrk_isolFrac( parent.seedTrk_isolFrac, index, this ),
        seedTrk_isolFracWide( parent.seedTrk_isolFracWide, index, this ),
        seedTrk_nIsolTrk( parent.seedTrk_nIsolTrk, index, this ),
        seedTrk_nOtherCoreTrk( parent.seedTrk_nOtherCoreTrk, index, this ),
        seedTrk_nStrip( parent.seedTrk_nStrip, index, this ),
        seedTrk_secMaxStripEt( parent.seedTrk_secMaxStripEt, index, this ),
        seedTrk_stripWidth2( parent.seedTrk_stripWidth2, index, this ),
        seedTrk_sumEMCellEtOverLeadTrkPt( parent.seedTrk_sumEMCellEtOverLeadTrkPt, index, this ),
        tauLlhLoose( parent.tauLlhLoose, index, this ),
        tauLlhMedium( parent.tauLlhMedium, index, this ),
        tauLlhTight( parent.tauLlhTight, index, this ),
        topoInvMass( parent.topoInvMass, index, this ),
        topoMeanDeltaR( parent.topoMeanDeltaR, index, this ),
        trFlightPathSig( parent.trFlightPathSig, index, this ),
        track_atTJVA_n( parent.track_atTJVA_n, index, this ),
        track_n( parent.track_n, index, this ),
        trkWidth2( parent.trkWidth2, index, this ),
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
   TauD3PDObjectElement::TauD3PDObjectElement( const TauD3PDObjectElement& parent )
      : TObject( parent ),
        BDTEleScore( parent.BDTEleScore ),
        BDTJetScore( parent.BDTJetScore ),
        EF_E( parent.EF_E ),
        EF_Et( parent.EF_Et ),
        EF_dr( parent.EF_dr ),
        EF_eta( parent.EF_eta ),
        EF_matched( parent.EF_matched ),
        EF_phi( parent.EF_phi ),
        EF_pt( parent.EF_pt ),
        EM_TES_scale( parent.EM_TES_scale ),
        EleBDTLoose( parent.EleBDTLoose ),
        EleBDTMedium( parent.EleBDTMedium ),
        EleBDTTight( parent.EleBDTTight ),
        Et( parent.Et ),
        JetBDTSigLoose( parent.JetBDTSigLoose ),
        JetBDTSigMedium( parent.JetBDTSigMedium ),
        JetBDTSigTight( parent.JetBDTSigTight ),
        L1_Et( parent.L1_Et ),
        L1_dr( parent.L1_dr ),
        L1_eta( parent.L1_eta ),
        L1_matched( parent.L1_matched ),
        L1_phi( parent.L1_phi ),
        L1_pt( parent.L1_pt ),
        L2_E( parent.L2_E ),
        L2_Et( parent.L2_Et ),
        L2_dr( parent.L2_dr ),
        L2_eta( parent.L2_eta ),
        L2_matched( parent.L2_matched ),
        L2_phi( parent.L2_phi ),
        L2_pt( parent.L2_pt ),
        LC_TES_precalib( parent.LC_TES_precalib ),
        RoIWord( parent.RoIWord ),
        SafeLikelihood( parent.SafeLikelihood ),
        TRTHTOverLT_LeadTrk( parent.TRTHTOverLT_LeadTrk ),
        author( parent.author ),
        calcVars_ChPiEMEOverCaloEME( parent.calcVars_ChPiEMEOverCaloEME ),
        calcVars_EMFractionAtEMScale( parent.calcVars_EMFractionAtEMScale ),
        calcVars_EMPOverTrkSysP( parent.calcVars_EMPOverTrkSysP ),
        calcVars_PSSFraction( parent.calcVars_PSSFraction ),
        calcVars_calRadius( parent.calcVars_calRadius ),
        calcVars_corrCentFrac( parent.calcVars_corrCentFrac ),
        calcVars_corrFTrk( parent.calcVars_corrFTrk ),
        calcVars_drMin( parent.calcVars_drMin ),
        calcVars_etEM_EMScale_Pt3Trks( parent.calcVars_etEM_EMScale_Pt3Trks ),
        calcVars_etHad_EMScale_Pt3Trks( parent.calcVars_etHad_EMScale_Pt3Trks ),
        calcVars_interAxis_eta( parent.calcVars_interAxis_eta ),
        calcVars_interAxis_phi( parent.calcVars_interAxis_phi ),
        calcVars_ipSigLeadLooseTrk( parent.calcVars_ipSigLeadLooseTrk ),
        calcVars_pi0BDTPrimaryScore( parent.calcVars_pi0BDTPrimaryScore ),
        calcVars_pi0BDTSecondaryScore( parent.calcVars_pi0BDTSecondaryScore ),
        calcVars_trackIso( parent.calcVars_trackIso ),
        cellBasedEnergyRing1( parent.cellBasedEnergyRing1 ),
        cellBasedEnergyRing2( parent.cellBasedEnergyRing2 ),
        cellBasedEnergyRing3( parent.cellBasedEnergyRing3 ),
        cellBasedEnergyRing4( parent.cellBasedEnergyRing4 ),
        cellBasedEnergyRing5( parent.cellBasedEnergyRing5 ),
        cellBasedEnergyRing6( parent.cellBasedEnergyRing6 ),
        cellBasedEnergyRing7( parent.cellBasedEnergyRing7 ),
        charge( parent.charge ),
        chrgLooseTrk( parent.chrgLooseTrk ),
        effTopoInvMass( parent.effTopoInvMass ),
        effTopoMeanDeltaR( parent.effTopoMeanDeltaR ),
        ele_E237E277( parent.ele_E237E277 ),
        ele_ECALFirstFraction( parent.ele_ECALFirstFraction ),
        ele_PresamplerFraction( parent.ele_PresamplerFraction ),
        electronVetoLoose( parent.electronVetoLoose ),
        electronVetoMedium( parent.electronVetoMedium ),
        electronVetoTight( parent.electronVetoTight ),
        etEflow( parent.etEflow ),
        etOverPtLeadLooseTrk( parent.etOverPtLeadLooseTrk ),
        etOverPtLeadTrk( parent.etOverPtLeadTrk ),
        eta( parent.eta ),
        ipSigLeadLooseTrk( parent.ipSigLeadLooseTrk ),
        ipSigLeadTrk( parent.ipSigLeadTrk ),
        ipZ0SinThetaSigLeadTrk( parent.ipZ0SinThetaSigLeadTrk ),
        leadLooseTrkPt( parent.leadLooseTrkPt ),
        leadTrack_eta( parent.leadTrack_eta ),
        leadTrack_phi( parent.leadTrack_phi ),
        leadTrkPt( parent.leadTrkPt ),
        likelihood( parent.likelihood ),
        m( parent.m ),
        mEflow( parent.mEflow ),
        massTrkSys( parent.massTrkSys ),
        muonVeto( parent.muonVeto ),
        nLooseConvTrk( parent.nLooseConvTrk ),
        nLooseTrk( parent.nLooseTrk ),
        nOtherTrk( parent.nOtherTrk ),
        nPi0( parent.nPi0 ),
        nProng( parent.nProng ),
        nProngLoose( parent.nProngLoose ),
        numCells( parent.numCells ),
        numEffTopoClusters( parent.numEffTopoClusters ),
        numTopoClusters( parent.numTopoClusters ),
        numTrack( parent.numTrack ),
        otherTrk_atTJVA_n( parent.otherTrk_atTJVA_n ),
        otherTrk_n( parent.otherTrk_n ),
        phi( parent.phi ),
        pt( parent.pt ),
        seedCalo_EMRadius( parent.seedCalo_EMRadius ),
        seedCalo_caloIso( parent.seedCalo_caloIso ),
        seedCalo_caloIsoCorrected( parent.seedCalo_caloIsoCorrected ),
        seedCalo_centFrac( parent.seedCalo_centFrac ),
        seedCalo_dRmax( parent.seedCalo_dRmax ),
        seedCalo_etEMAtEMScale( parent.seedCalo_etEMAtEMScale ),
        seedCalo_etEMCalib( parent.seedCalo_etEMCalib ),
        seedCalo_etHadAtEMScale( parent.seedCalo_etHadAtEMScale ),
        seedCalo_etHadCalib( parent.seedCalo_etHadCalib ),
        seedCalo_eta( parent.seedCalo_eta ),
        seedCalo_hadRadius( parent.seedCalo_hadRadius ),
        seedCalo_isolFrac( parent.seedCalo_isolFrac ),
        seedCalo_lead2ClusterEOverAllClusterE( parent.seedCalo_lead2ClusterEOverAllClusterE ),
        seedCalo_lead3ClusterEOverAllClusterE( parent.seedCalo_lead3ClusterEOverAllClusterE ),
        seedCalo_nIsolLooseTrk( parent.seedCalo_nIsolLooseTrk ),
        seedCalo_nStrip( parent.seedCalo_nStrip ),
        seedCalo_nWideTrk( parent.seedCalo_nWideTrk ),
        seedCalo_numTrack( parent.seedCalo_numTrack ),
        seedCalo_phi( parent.seedCalo_phi ),
        seedCalo_stripWidth2( parent.seedCalo_stripWidth2 ),
        seedCalo_track_n( parent.seedCalo_track_n ),
        seedCalo_trkAvgDist( parent.seedCalo_trkAvgDist ),
        seedCalo_trkRmsDist( parent.seedCalo_trkRmsDist ),
        seedCalo_wideTrk_atTJVA_n( parent.seedCalo_wideTrk_atTJVA_n ),
        seedCalo_wideTrk_n( parent.seedCalo_wideTrk_n ),
        seedTrk_EMRadius( parent.seedTrk_EMRadius ),
        seedTrk_etChrgEM( parent.seedTrk_etChrgEM ),
        seedTrk_etChrgHad( parent.seedTrk_etChrgHad ),
        seedTrk_etChrgHadOverSumTrkPt( parent.seedTrk_etChrgHadOverSumTrkPt ),
        seedTrk_etEMAtEMScale( parent.seedTrk_etEMAtEMScale ),
        seedTrk_etEMCL( parent.seedTrk_etEMCL ),
        seedTrk_etHadAtEMScale( parent.seedTrk_etHadAtEMScale ),
        seedTrk_etIsolEM( parent.seedTrk_etIsolEM ),
        seedTrk_etIsolHad( parent.seedTrk_etIsolHad ),
        seedTrk_etNeuEM( parent.seedTrk_etNeuEM ),
        seedTrk_etResNeuEM( parent.seedTrk_etResNeuEM ),
        seedTrk_hadLeakEt( parent.seedTrk_hadLeakEt ),
        seedTrk_isolFrac( parent.seedTrk_isolFrac ),
        seedTrk_isolFracWide( parent.seedTrk_isolFracWide ),
        seedTrk_nIsolTrk( parent.seedTrk_nIsolTrk ),
        seedTrk_nOtherCoreTrk( parent.seedTrk_nOtherCoreTrk ),
        seedTrk_nStrip( parent.seedTrk_nStrip ),
        seedTrk_secMaxStripEt( parent.seedTrk_secMaxStripEt ),
        seedTrk_stripWidth2( parent.seedTrk_stripWidth2 ),
        seedTrk_sumEMCellEtOverLeadTrkPt( parent.seedTrk_sumEMCellEtOverLeadTrkPt ),
        tauLlhLoose( parent.tauLlhLoose ),
        tauLlhMedium( parent.tauLlhMedium ),
        tauLlhTight( parent.tauLlhTight ),
        topoInvMass( parent.topoInvMass ),
        topoMeanDeltaR( parent.topoMeanDeltaR ),
        trFlightPathSig( parent.trFlightPathSig ),
        track_atTJVA_n( parent.track_atTJVA_n ),
        track_n( parent.track_n ),
        trkWidth2( parent.trkWidth2 ),
        fParent( parent.fParent ), fIndex( parent.fIndex ) {

   }

   /**
    * This function can be used to access the parent object of this
    * proxy object. It can come in handy when optimizing an analysis code.
    *
    * @returns A reference to this object's parent
    */
   const TauD3PDObject* TauD3PDObjectElement::GetParent() const {

      return fParent;
   }

   /**
    * This function can be used to access the index of this proxy object
    * inside the parent container. It can come in handy when optimizing an
    * analysis code.
    *
    * @returns The index of the proxy in the object's parent
    */
   size_t TauD3PDObjectElement::GetIndex() const {

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
   TauD3PDObject::TauD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "BDTEleScore" ] = &BDTEleScore;
      fHandles[ "BDTJetScore" ] = &BDTJetScore;
      fHandles[ "EF_E" ] = &EF_E;
      fHandles[ "EF_Et" ] = &EF_Et;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_eta" ] = &EF_eta;
      fHandles[ "EF_matched" ] = &EF_matched;
      fHandles[ "EF_phi" ] = &EF_phi;
      fHandles[ "EF_pt" ] = &EF_pt;
      fHandles[ "EM_TES_scale" ] = &EM_TES_scale;
      fHandles[ "EleBDTLoose" ] = &EleBDTLoose;
      fHandles[ "EleBDTMedium" ] = &EleBDTMedium;
      fHandles[ "EleBDTTight" ] = &EleBDTTight;
      fHandles[ "Et" ] = &Et;
      fHandles[ "JetBDTSigLoose" ] = &JetBDTSigLoose;
      fHandles[ "JetBDTSigMedium" ] = &JetBDTSigMedium;
      fHandles[ "JetBDTSigTight" ] = &JetBDTSigTight;
      fHandles[ "L1_Et" ] = &L1_Et;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_eta" ] = &L1_eta;
      fHandles[ "L1_matched" ] = &L1_matched;
      fHandles[ "L1_phi" ] = &L1_phi;
      fHandles[ "L1_pt" ] = &L1_pt;
      fHandles[ "L2_E" ] = &L2_E;
      fHandles[ "L2_Et" ] = &L2_Et;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_eta" ] = &L2_eta;
      fHandles[ "L2_matched" ] = &L2_matched;
      fHandles[ "L2_phi" ] = &L2_phi;
      fHandles[ "L2_pt" ] = &L2_pt;
      fHandles[ "LC_TES_precalib" ] = &LC_TES_precalib;
      fHandles[ "RoIWord" ] = &RoIWord;
      fHandles[ "SafeLikelihood" ] = &SafeLikelihood;
      fHandles[ "TRTHTOverLT_LeadTrk" ] = &TRTHTOverLT_LeadTrk;
      fHandles[ "author" ] = &author;
      fHandles[ "calcVars_ChPiEMEOverCaloEME" ] = &calcVars_ChPiEMEOverCaloEME;
      fHandles[ "calcVars_EMFractionAtEMScale" ] = &calcVars_EMFractionAtEMScale;
      fHandles[ "calcVars_EMPOverTrkSysP" ] = &calcVars_EMPOverTrkSysP;
      fHandles[ "calcVars_PSSFraction" ] = &calcVars_PSSFraction;
      fHandles[ "calcVars_calRadius" ] = &calcVars_calRadius;
      fHandles[ "calcVars_corrCentFrac" ] = &calcVars_corrCentFrac;
      fHandles[ "calcVars_corrFTrk" ] = &calcVars_corrFTrk;
      fHandles[ "calcVars_drMin" ] = &calcVars_drMin;
      fHandles[ "calcVars_etEM_EMScale_Pt3Trks" ] = &calcVars_etEM_EMScale_Pt3Trks;
      fHandles[ "calcVars_etHad_EMScale_Pt3Trks" ] = &calcVars_etHad_EMScale_Pt3Trks;
      fHandles[ "calcVars_interAxis_eta" ] = &calcVars_interAxis_eta;
      fHandles[ "calcVars_interAxis_phi" ] = &calcVars_interAxis_phi;
      fHandles[ "calcVars_ipSigLeadLooseTrk" ] = &calcVars_ipSigLeadLooseTrk;
      fHandles[ "calcVars_pi0BDTPrimaryScore" ] = &calcVars_pi0BDTPrimaryScore;
      fHandles[ "calcVars_pi0BDTSecondaryScore" ] = &calcVars_pi0BDTSecondaryScore;
      fHandles[ "calcVars_trackIso" ] = &calcVars_trackIso;
      fHandles[ "cellBasedEnergyRing1" ] = &cellBasedEnergyRing1;
      fHandles[ "cellBasedEnergyRing2" ] = &cellBasedEnergyRing2;
      fHandles[ "cellBasedEnergyRing3" ] = &cellBasedEnergyRing3;
      fHandles[ "cellBasedEnergyRing4" ] = &cellBasedEnergyRing4;
      fHandles[ "cellBasedEnergyRing5" ] = &cellBasedEnergyRing5;
      fHandles[ "cellBasedEnergyRing6" ] = &cellBasedEnergyRing6;
      fHandles[ "cellBasedEnergyRing7" ] = &cellBasedEnergyRing7;
      fHandles[ "charge" ] = &charge;
      fHandles[ "chrgLooseTrk" ] = &chrgLooseTrk;
      fHandles[ "effTopoInvMass" ] = &effTopoInvMass;
      fHandles[ "effTopoMeanDeltaR" ] = &effTopoMeanDeltaR;
      fHandles[ "ele_E237E277" ] = &ele_E237E277;
      fHandles[ "ele_ECALFirstFraction" ] = &ele_ECALFirstFraction;
      fHandles[ "ele_PresamplerFraction" ] = &ele_PresamplerFraction;
      fHandles[ "electronVetoLoose" ] = &electronVetoLoose;
      fHandles[ "electronVetoMedium" ] = &electronVetoMedium;
      fHandles[ "electronVetoTight" ] = &electronVetoTight;
      fHandles[ "etEflow" ] = &etEflow;
      fHandles[ "etOverPtLeadLooseTrk" ] = &etOverPtLeadLooseTrk;
      fHandles[ "etOverPtLeadTrk" ] = &etOverPtLeadTrk;
      fHandles[ "eta" ] = &eta;
      fHandles[ "ipSigLeadLooseTrk" ] = &ipSigLeadLooseTrk;
      fHandles[ "ipSigLeadTrk" ] = &ipSigLeadTrk;
      fHandles[ "ipZ0SinThetaSigLeadTrk" ] = &ipZ0SinThetaSigLeadTrk;
      fHandles[ "leadLooseTrkPt" ] = &leadLooseTrkPt;
      fHandles[ "leadTrack_eta" ] = &leadTrack_eta;
      fHandles[ "leadTrack_phi" ] = &leadTrack_phi;
      fHandles[ "leadTrkPt" ] = &leadTrkPt;
      fHandles[ "likelihood" ] = &likelihood;
      fHandles[ "m" ] = &m;
      fHandles[ "mEflow" ] = &mEflow;
      fHandles[ "massTrkSys" ] = &massTrkSys;
      fHandles[ "muonVeto" ] = &muonVeto;
      fHandles[ "n" ] = &n;
      fHandles[ "nLooseConvTrk" ] = &nLooseConvTrk;
      fHandles[ "nLooseTrk" ] = &nLooseTrk;
      fHandles[ "nOtherTrk" ] = &nOtherTrk;
      fHandles[ "nPi0" ] = &nPi0;
      fHandles[ "nProng" ] = &nProng;
      fHandles[ "nProngLoose" ] = &nProngLoose;
      fHandles[ "numCells" ] = &numCells;
      fHandles[ "numEffTopoClusters" ] = &numEffTopoClusters;
      fHandles[ "numTopoClusters" ] = &numTopoClusters;
      fHandles[ "numTrack" ] = &numTrack;
      fHandles[ "otherTrk_atTJVA_n" ] = &otherTrk_atTJVA_n;
      fHandles[ "otherTrk_n" ] = &otherTrk_n;
      fHandles[ "phi" ] = &phi;
      fHandles[ "pt" ] = &pt;
      fHandles[ "seedCalo_EMRadius" ] = &seedCalo_EMRadius;
      fHandles[ "seedCalo_caloIso" ] = &seedCalo_caloIso;
      fHandles[ "seedCalo_caloIsoCorrected" ] = &seedCalo_caloIsoCorrected;
      fHandles[ "seedCalo_centFrac" ] = &seedCalo_centFrac;
      fHandles[ "seedCalo_dRmax" ] = &seedCalo_dRmax;
      fHandles[ "seedCalo_etEMAtEMScale" ] = &seedCalo_etEMAtEMScale;
      fHandles[ "seedCalo_etEMCalib" ] = &seedCalo_etEMCalib;
      fHandles[ "seedCalo_etHadAtEMScale" ] = &seedCalo_etHadAtEMScale;
      fHandles[ "seedCalo_etHadCalib" ] = &seedCalo_etHadCalib;
      fHandles[ "seedCalo_eta" ] = &seedCalo_eta;
      fHandles[ "seedCalo_hadRadius" ] = &seedCalo_hadRadius;
      fHandles[ "seedCalo_isolFrac" ] = &seedCalo_isolFrac;
      fHandles[ "seedCalo_lead2ClusterEOverAllClusterE" ] = &seedCalo_lead2ClusterEOverAllClusterE;
      fHandles[ "seedCalo_lead3ClusterEOverAllClusterE" ] = &seedCalo_lead3ClusterEOverAllClusterE;
      fHandles[ "seedCalo_nIsolLooseTrk" ] = &seedCalo_nIsolLooseTrk;
      fHandles[ "seedCalo_nStrip" ] = &seedCalo_nStrip;
      fHandles[ "seedCalo_nWideTrk" ] = &seedCalo_nWideTrk;
      fHandles[ "seedCalo_numTrack" ] = &seedCalo_numTrack;
      fHandles[ "seedCalo_phi" ] = &seedCalo_phi;
      fHandles[ "seedCalo_stripWidth2" ] = &seedCalo_stripWidth2;
      fHandles[ "seedCalo_track_n" ] = &seedCalo_track_n;
      fHandles[ "seedCalo_trkAvgDist" ] = &seedCalo_trkAvgDist;
      fHandles[ "seedCalo_trkRmsDist" ] = &seedCalo_trkRmsDist;
      fHandles[ "seedCalo_wideTrk_atTJVA_n" ] = &seedCalo_wideTrk_atTJVA_n;
      fHandles[ "seedCalo_wideTrk_n" ] = &seedCalo_wideTrk_n;
      fHandles[ "seedTrk_EMRadius" ] = &seedTrk_EMRadius;
      fHandles[ "seedTrk_etChrgEM" ] = &seedTrk_etChrgEM;
      fHandles[ "seedTrk_etChrgHad" ] = &seedTrk_etChrgHad;
      fHandles[ "seedTrk_etChrgHadOverSumTrkPt" ] = &seedTrk_etChrgHadOverSumTrkPt;
      fHandles[ "seedTrk_etEMAtEMScale" ] = &seedTrk_etEMAtEMScale;
      fHandles[ "seedTrk_etEMCL" ] = &seedTrk_etEMCL;
      fHandles[ "seedTrk_etHadAtEMScale" ] = &seedTrk_etHadAtEMScale;
      fHandles[ "seedTrk_etIsolEM" ] = &seedTrk_etIsolEM;
      fHandles[ "seedTrk_etIsolHad" ] = &seedTrk_etIsolHad;
      fHandles[ "seedTrk_etNeuEM" ] = &seedTrk_etNeuEM;
      fHandles[ "seedTrk_etResNeuEM" ] = &seedTrk_etResNeuEM;
      fHandles[ "seedTrk_hadLeakEt" ] = &seedTrk_hadLeakEt;
      fHandles[ "seedTrk_isolFrac" ] = &seedTrk_isolFrac;
      fHandles[ "seedTrk_isolFracWide" ] = &seedTrk_isolFracWide;
      fHandles[ "seedTrk_nIsolTrk" ] = &seedTrk_nIsolTrk;
      fHandles[ "seedTrk_nOtherCoreTrk" ] = &seedTrk_nOtherCoreTrk;
      fHandles[ "seedTrk_nStrip" ] = &seedTrk_nStrip;
      fHandles[ "seedTrk_secMaxStripEt" ] = &seedTrk_secMaxStripEt;
      fHandles[ "seedTrk_stripWidth2" ] = &seedTrk_stripWidth2;
      fHandles[ "seedTrk_sumEMCellEtOverLeadTrkPt" ] = &seedTrk_sumEMCellEtOverLeadTrkPt;
      fHandles[ "tauLlhLoose" ] = &tauLlhLoose;
      fHandles[ "tauLlhMedium" ] = &tauLlhMedium;
      fHandles[ "tauLlhTight" ] = &tauLlhTight;
      fHandles[ "topoInvMass" ] = &topoInvMass;
      fHandles[ "topoMeanDeltaR" ] = &topoMeanDeltaR;
      fHandles[ "trFlightPathSig" ] = &trFlightPathSig;
      fHandles[ "track_atTJVA_n" ] = &track_atTJVA_n;
      fHandles[ "track_n" ] = &track_n;
      fHandles[ "trkWidth2" ] = &trkWidth2;

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
   TauD3PDObject::TauD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "BDTEleScore" ] = &BDTEleScore;
      fHandles[ "BDTJetScore" ] = &BDTJetScore;
      fHandles[ "EF_E" ] = &EF_E;
      fHandles[ "EF_Et" ] = &EF_Et;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_eta" ] = &EF_eta;
      fHandles[ "EF_matched" ] = &EF_matched;
      fHandles[ "EF_phi" ] = &EF_phi;
      fHandles[ "EF_pt" ] = &EF_pt;
      fHandles[ "EM_TES_scale" ] = &EM_TES_scale;
      fHandles[ "EleBDTLoose" ] = &EleBDTLoose;
      fHandles[ "EleBDTMedium" ] = &EleBDTMedium;
      fHandles[ "EleBDTTight" ] = &EleBDTTight;
      fHandles[ "Et" ] = &Et;
      fHandles[ "JetBDTSigLoose" ] = &JetBDTSigLoose;
      fHandles[ "JetBDTSigMedium" ] = &JetBDTSigMedium;
      fHandles[ "JetBDTSigTight" ] = &JetBDTSigTight;
      fHandles[ "L1_Et" ] = &L1_Et;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_eta" ] = &L1_eta;
      fHandles[ "L1_matched" ] = &L1_matched;
      fHandles[ "L1_phi" ] = &L1_phi;
      fHandles[ "L1_pt" ] = &L1_pt;
      fHandles[ "L2_E" ] = &L2_E;
      fHandles[ "L2_Et" ] = &L2_Et;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_eta" ] = &L2_eta;
      fHandles[ "L2_matched" ] = &L2_matched;
      fHandles[ "L2_phi" ] = &L2_phi;
      fHandles[ "L2_pt" ] = &L2_pt;
      fHandles[ "LC_TES_precalib" ] = &LC_TES_precalib;
      fHandles[ "RoIWord" ] = &RoIWord;
      fHandles[ "SafeLikelihood" ] = &SafeLikelihood;
      fHandles[ "TRTHTOverLT_LeadTrk" ] = &TRTHTOverLT_LeadTrk;
      fHandles[ "author" ] = &author;
      fHandles[ "calcVars_ChPiEMEOverCaloEME" ] = &calcVars_ChPiEMEOverCaloEME;
      fHandles[ "calcVars_EMFractionAtEMScale" ] = &calcVars_EMFractionAtEMScale;
      fHandles[ "calcVars_EMPOverTrkSysP" ] = &calcVars_EMPOverTrkSysP;
      fHandles[ "calcVars_PSSFraction" ] = &calcVars_PSSFraction;
      fHandles[ "calcVars_calRadius" ] = &calcVars_calRadius;
      fHandles[ "calcVars_corrCentFrac" ] = &calcVars_corrCentFrac;
      fHandles[ "calcVars_corrFTrk" ] = &calcVars_corrFTrk;
      fHandles[ "calcVars_drMin" ] = &calcVars_drMin;
      fHandles[ "calcVars_etEM_EMScale_Pt3Trks" ] = &calcVars_etEM_EMScale_Pt3Trks;
      fHandles[ "calcVars_etHad_EMScale_Pt3Trks" ] = &calcVars_etHad_EMScale_Pt3Trks;
      fHandles[ "calcVars_interAxis_eta" ] = &calcVars_interAxis_eta;
      fHandles[ "calcVars_interAxis_phi" ] = &calcVars_interAxis_phi;
      fHandles[ "calcVars_ipSigLeadLooseTrk" ] = &calcVars_ipSigLeadLooseTrk;
      fHandles[ "calcVars_pi0BDTPrimaryScore" ] = &calcVars_pi0BDTPrimaryScore;
      fHandles[ "calcVars_pi0BDTSecondaryScore" ] = &calcVars_pi0BDTSecondaryScore;
      fHandles[ "calcVars_trackIso" ] = &calcVars_trackIso;
      fHandles[ "cellBasedEnergyRing1" ] = &cellBasedEnergyRing1;
      fHandles[ "cellBasedEnergyRing2" ] = &cellBasedEnergyRing2;
      fHandles[ "cellBasedEnergyRing3" ] = &cellBasedEnergyRing3;
      fHandles[ "cellBasedEnergyRing4" ] = &cellBasedEnergyRing4;
      fHandles[ "cellBasedEnergyRing5" ] = &cellBasedEnergyRing5;
      fHandles[ "cellBasedEnergyRing6" ] = &cellBasedEnergyRing6;
      fHandles[ "cellBasedEnergyRing7" ] = &cellBasedEnergyRing7;
      fHandles[ "charge" ] = &charge;
      fHandles[ "chrgLooseTrk" ] = &chrgLooseTrk;
      fHandles[ "effTopoInvMass" ] = &effTopoInvMass;
      fHandles[ "effTopoMeanDeltaR" ] = &effTopoMeanDeltaR;
      fHandles[ "ele_E237E277" ] = &ele_E237E277;
      fHandles[ "ele_ECALFirstFraction" ] = &ele_ECALFirstFraction;
      fHandles[ "ele_PresamplerFraction" ] = &ele_PresamplerFraction;
      fHandles[ "electronVetoLoose" ] = &electronVetoLoose;
      fHandles[ "electronVetoMedium" ] = &electronVetoMedium;
      fHandles[ "electronVetoTight" ] = &electronVetoTight;
      fHandles[ "etEflow" ] = &etEflow;
      fHandles[ "etOverPtLeadLooseTrk" ] = &etOverPtLeadLooseTrk;
      fHandles[ "etOverPtLeadTrk" ] = &etOverPtLeadTrk;
      fHandles[ "eta" ] = &eta;
      fHandles[ "ipSigLeadLooseTrk" ] = &ipSigLeadLooseTrk;
      fHandles[ "ipSigLeadTrk" ] = &ipSigLeadTrk;
      fHandles[ "ipZ0SinThetaSigLeadTrk" ] = &ipZ0SinThetaSigLeadTrk;
      fHandles[ "leadLooseTrkPt" ] = &leadLooseTrkPt;
      fHandles[ "leadTrack_eta" ] = &leadTrack_eta;
      fHandles[ "leadTrack_phi" ] = &leadTrack_phi;
      fHandles[ "leadTrkPt" ] = &leadTrkPt;
      fHandles[ "likelihood" ] = &likelihood;
      fHandles[ "m" ] = &m;
      fHandles[ "mEflow" ] = &mEflow;
      fHandles[ "massTrkSys" ] = &massTrkSys;
      fHandles[ "muonVeto" ] = &muonVeto;
      fHandles[ "n" ] = &n;
      fHandles[ "nLooseConvTrk" ] = &nLooseConvTrk;
      fHandles[ "nLooseTrk" ] = &nLooseTrk;
      fHandles[ "nOtherTrk" ] = &nOtherTrk;
      fHandles[ "nPi0" ] = &nPi0;
      fHandles[ "nProng" ] = &nProng;
      fHandles[ "nProngLoose" ] = &nProngLoose;
      fHandles[ "numCells" ] = &numCells;
      fHandles[ "numEffTopoClusters" ] = &numEffTopoClusters;
      fHandles[ "numTopoClusters" ] = &numTopoClusters;
      fHandles[ "numTrack" ] = &numTrack;
      fHandles[ "otherTrk_atTJVA_n" ] = &otherTrk_atTJVA_n;
      fHandles[ "otherTrk_n" ] = &otherTrk_n;
      fHandles[ "phi" ] = &phi;
      fHandles[ "pt" ] = &pt;
      fHandles[ "seedCalo_EMRadius" ] = &seedCalo_EMRadius;
      fHandles[ "seedCalo_caloIso" ] = &seedCalo_caloIso;
      fHandles[ "seedCalo_caloIsoCorrected" ] = &seedCalo_caloIsoCorrected;
      fHandles[ "seedCalo_centFrac" ] = &seedCalo_centFrac;
      fHandles[ "seedCalo_dRmax" ] = &seedCalo_dRmax;
      fHandles[ "seedCalo_etEMAtEMScale" ] = &seedCalo_etEMAtEMScale;
      fHandles[ "seedCalo_etEMCalib" ] = &seedCalo_etEMCalib;
      fHandles[ "seedCalo_etHadAtEMScale" ] = &seedCalo_etHadAtEMScale;
      fHandles[ "seedCalo_etHadCalib" ] = &seedCalo_etHadCalib;
      fHandles[ "seedCalo_eta" ] = &seedCalo_eta;
      fHandles[ "seedCalo_hadRadius" ] = &seedCalo_hadRadius;
      fHandles[ "seedCalo_isolFrac" ] = &seedCalo_isolFrac;
      fHandles[ "seedCalo_lead2ClusterEOverAllClusterE" ] = &seedCalo_lead2ClusterEOverAllClusterE;
      fHandles[ "seedCalo_lead3ClusterEOverAllClusterE" ] = &seedCalo_lead3ClusterEOverAllClusterE;
      fHandles[ "seedCalo_nIsolLooseTrk" ] = &seedCalo_nIsolLooseTrk;
      fHandles[ "seedCalo_nStrip" ] = &seedCalo_nStrip;
      fHandles[ "seedCalo_nWideTrk" ] = &seedCalo_nWideTrk;
      fHandles[ "seedCalo_numTrack" ] = &seedCalo_numTrack;
      fHandles[ "seedCalo_phi" ] = &seedCalo_phi;
      fHandles[ "seedCalo_stripWidth2" ] = &seedCalo_stripWidth2;
      fHandles[ "seedCalo_track_n" ] = &seedCalo_track_n;
      fHandles[ "seedCalo_trkAvgDist" ] = &seedCalo_trkAvgDist;
      fHandles[ "seedCalo_trkRmsDist" ] = &seedCalo_trkRmsDist;
      fHandles[ "seedCalo_wideTrk_atTJVA_n" ] = &seedCalo_wideTrk_atTJVA_n;
      fHandles[ "seedCalo_wideTrk_n" ] = &seedCalo_wideTrk_n;
      fHandles[ "seedTrk_EMRadius" ] = &seedTrk_EMRadius;
      fHandles[ "seedTrk_etChrgEM" ] = &seedTrk_etChrgEM;
      fHandles[ "seedTrk_etChrgHad" ] = &seedTrk_etChrgHad;
      fHandles[ "seedTrk_etChrgHadOverSumTrkPt" ] = &seedTrk_etChrgHadOverSumTrkPt;
      fHandles[ "seedTrk_etEMAtEMScale" ] = &seedTrk_etEMAtEMScale;
      fHandles[ "seedTrk_etEMCL" ] = &seedTrk_etEMCL;
      fHandles[ "seedTrk_etHadAtEMScale" ] = &seedTrk_etHadAtEMScale;
      fHandles[ "seedTrk_etIsolEM" ] = &seedTrk_etIsolEM;
      fHandles[ "seedTrk_etIsolHad" ] = &seedTrk_etIsolHad;
      fHandles[ "seedTrk_etNeuEM" ] = &seedTrk_etNeuEM;
      fHandles[ "seedTrk_etResNeuEM" ] = &seedTrk_etResNeuEM;
      fHandles[ "seedTrk_hadLeakEt" ] = &seedTrk_hadLeakEt;
      fHandles[ "seedTrk_isolFrac" ] = &seedTrk_isolFrac;
      fHandles[ "seedTrk_isolFracWide" ] = &seedTrk_isolFracWide;
      fHandles[ "seedTrk_nIsolTrk" ] = &seedTrk_nIsolTrk;
      fHandles[ "seedTrk_nOtherCoreTrk" ] = &seedTrk_nOtherCoreTrk;
      fHandles[ "seedTrk_nStrip" ] = &seedTrk_nStrip;
      fHandles[ "seedTrk_secMaxStripEt" ] = &seedTrk_secMaxStripEt;
      fHandles[ "seedTrk_stripWidth2" ] = &seedTrk_stripWidth2;
      fHandles[ "seedTrk_sumEMCellEtOverLeadTrkPt" ] = &seedTrk_sumEMCellEtOverLeadTrkPt;
      fHandles[ "tauLlhLoose" ] = &tauLlhLoose;
      fHandles[ "tauLlhMedium" ] = &tauLlhMedium;
      fHandles[ "tauLlhTight" ] = &tauLlhTight;
      fHandles[ "topoInvMass" ] = &topoInvMass;
      fHandles[ "topoMeanDeltaR" ] = &topoMeanDeltaR;
      fHandles[ "trFlightPathSig" ] = &trFlightPathSig;
      fHandles[ "track_atTJVA_n" ] = &track_atTJVA_n;
      fHandles[ "track_n" ] = &track_n;
      fHandles[ "trkWidth2" ] = &trkWidth2;

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
   TauD3PDObject::~TauD3PDObject() {

      for( size_t i = 0; i < fProxies.size(); ++i ) {
         delete fProxies[ i ];
      }
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TauD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TauD3PDObject::SetPrefix( const char* prefix ) {

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
   void TauD3PDObject::ReadFrom( TTree* tree ) {

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
   void TauD3PDObject::WriteTo( TTree* tree ) {

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
   void TauD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void TauD3PDObject::ReadAllActive() {

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

   D3PDReadStats TauD3PDObject::GetStatistics() const {

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
   TauD3PDObject& TauD3PDObject::Set( const TauD3PDObject& parent ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Set", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( parent.BDTEleScore.IsAvailable() ) {
         *( BDTEleScore() ) = *( parent.BDTEleScore() );
      } else {
         BDTEleScore()->clear();
      }
      if( parent.BDTJetScore.IsAvailable() ) {
         *( BDTJetScore() ) = *( parent.BDTJetScore() );
      } else {
         BDTJetScore()->clear();
      }
      if( parent.EF_E.IsAvailable() ) {
         *( EF_E() ) = *( parent.EF_E() );
      } else {
         EF_E()->clear();
      }
      if( parent.EF_Et.IsAvailable() ) {
         *( EF_Et() ) = *( parent.EF_Et() );
      } else {
         EF_Et()->clear();
      }
      if( parent.EF_dr.IsAvailable() ) {
         *( EF_dr() ) = *( parent.EF_dr() );
      } else {
         EF_dr()->clear();
      }
      if( parent.EF_eta.IsAvailable() ) {
         *( EF_eta() ) = *( parent.EF_eta() );
      } else {
         EF_eta()->clear();
      }
      if( parent.EF_matched.IsAvailable() ) {
         *( EF_matched() ) = *( parent.EF_matched() );
      } else {
         EF_matched()->clear();
      }
      if( parent.EF_phi.IsAvailable() ) {
         *( EF_phi() ) = *( parent.EF_phi() );
      } else {
         EF_phi()->clear();
      }
      if( parent.EF_pt.IsAvailable() ) {
         *( EF_pt() ) = *( parent.EF_pt() );
      } else {
         EF_pt()->clear();
      }
      if( parent.EM_TES_scale.IsAvailable() ) {
         *( EM_TES_scale() ) = *( parent.EM_TES_scale() );
      } else {
         EM_TES_scale()->clear();
      }
      if( parent.EleBDTLoose.IsAvailable() ) {
         *( EleBDTLoose() ) = *( parent.EleBDTLoose() );
      } else {
         EleBDTLoose()->clear();
      }
      if( parent.EleBDTMedium.IsAvailable() ) {
         *( EleBDTMedium() ) = *( parent.EleBDTMedium() );
      } else {
         EleBDTMedium()->clear();
      }
      if( parent.EleBDTTight.IsAvailable() ) {
         *( EleBDTTight() ) = *( parent.EleBDTTight() );
      } else {
         EleBDTTight()->clear();
      }
      if( parent.Et.IsAvailable() ) {
         *( Et() ) = *( parent.Et() );
      } else {
         Et()->clear();
      }
      if( parent.JetBDTSigLoose.IsAvailable() ) {
         *( JetBDTSigLoose() ) = *( parent.JetBDTSigLoose() );
      } else {
         JetBDTSigLoose()->clear();
      }
      if( parent.JetBDTSigMedium.IsAvailable() ) {
         *( JetBDTSigMedium() ) = *( parent.JetBDTSigMedium() );
      } else {
         JetBDTSigMedium()->clear();
      }
      if( parent.JetBDTSigTight.IsAvailable() ) {
         *( JetBDTSigTight() ) = *( parent.JetBDTSigTight() );
      } else {
         JetBDTSigTight()->clear();
      }
      if( parent.L1_Et.IsAvailable() ) {
         *( L1_Et() ) = *( parent.L1_Et() );
      } else {
         L1_Et()->clear();
      }
      if( parent.L1_dr.IsAvailable() ) {
         *( L1_dr() ) = *( parent.L1_dr() );
      } else {
         L1_dr()->clear();
      }
      if( parent.L1_eta.IsAvailable() ) {
         *( L1_eta() ) = *( parent.L1_eta() );
      } else {
         L1_eta()->clear();
      }
      if( parent.L1_matched.IsAvailable() ) {
         *( L1_matched() ) = *( parent.L1_matched() );
      } else {
         L1_matched()->clear();
      }
      if( parent.L1_phi.IsAvailable() ) {
         *( L1_phi() ) = *( parent.L1_phi() );
      } else {
         L1_phi()->clear();
      }
      if( parent.L1_pt.IsAvailable() ) {
         *( L1_pt() ) = *( parent.L1_pt() );
      } else {
         L1_pt()->clear();
      }
      if( parent.L2_E.IsAvailable() ) {
         *( L2_E() ) = *( parent.L2_E() );
      } else {
         L2_E()->clear();
      }
      if( parent.L2_Et.IsAvailable() ) {
         *( L2_Et() ) = *( parent.L2_Et() );
      } else {
         L2_Et()->clear();
      }
      if( parent.L2_dr.IsAvailable() ) {
         *( L2_dr() ) = *( parent.L2_dr() );
      } else {
         L2_dr()->clear();
      }
      if( parent.L2_eta.IsAvailable() ) {
         *( L2_eta() ) = *( parent.L2_eta() );
      } else {
         L2_eta()->clear();
      }
      if( parent.L2_matched.IsAvailable() ) {
         *( L2_matched() ) = *( parent.L2_matched() );
      } else {
         L2_matched()->clear();
      }
      if( parent.L2_phi.IsAvailable() ) {
         *( L2_phi() ) = *( parent.L2_phi() );
      } else {
         L2_phi()->clear();
      }
      if( parent.L2_pt.IsAvailable() ) {
         *( L2_pt() ) = *( parent.L2_pt() );
      } else {
         L2_pt()->clear();
      }
      if( parent.LC_TES_precalib.IsAvailable() ) {
         *( LC_TES_precalib() ) = *( parent.LC_TES_precalib() );
      } else {
         LC_TES_precalib()->clear();
      }
      if( parent.RoIWord.IsAvailable() ) {
         *( RoIWord() ) = *( parent.RoIWord() );
      } else {
         RoIWord()->clear();
      }
      if( parent.SafeLikelihood.IsAvailable() ) {
         *( SafeLikelihood() ) = *( parent.SafeLikelihood() );
      } else {
         SafeLikelihood()->clear();
      }
      if( parent.TRTHTOverLT_LeadTrk.IsAvailable() ) {
         *( TRTHTOverLT_LeadTrk() ) = *( parent.TRTHTOverLT_LeadTrk() );
      } else {
         TRTHTOverLT_LeadTrk()->clear();
      }
      if( parent.author.IsAvailable() ) {
         *( author() ) = *( parent.author() );
      } else {
         author()->clear();
      }
      if( parent.calcVars_ChPiEMEOverCaloEME.IsAvailable() ) {
         *( calcVars_ChPiEMEOverCaloEME() ) = *( parent.calcVars_ChPiEMEOverCaloEME() );
      } else {
         calcVars_ChPiEMEOverCaloEME()->clear();
      }
      if( parent.calcVars_EMFractionAtEMScale.IsAvailable() ) {
         *( calcVars_EMFractionAtEMScale() ) = *( parent.calcVars_EMFractionAtEMScale() );
      } else {
         calcVars_EMFractionAtEMScale()->clear();
      }
      if( parent.calcVars_EMPOverTrkSysP.IsAvailable() ) {
         *( calcVars_EMPOverTrkSysP() ) = *( parent.calcVars_EMPOverTrkSysP() );
      } else {
         calcVars_EMPOverTrkSysP()->clear();
      }
      if( parent.calcVars_PSSFraction.IsAvailable() ) {
         *( calcVars_PSSFraction() ) = *( parent.calcVars_PSSFraction() );
      } else {
         calcVars_PSSFraction()->clear();
      }
      if( parent.calcVars_calRadius.IsAvailable() ) {
         *( calcVars_calRadius() ) = *( parent.calcVars_calRadius() );
      } else {
         calcVars_calRadius()->clear();
      }
      if( parent.calcVars_corrCentFrac.IsAvailable() ) {
         *( calcVars_corrCentFrac() ) = *( parent.calcVars_corrCentFrac() );
      } else {
         calcVars_corrCentFrac()->clear();
      }
      if( parent.calcVars_corrFTrk.IsAvailable() ) {
         *( calcVars_corrFTrk() ) = *( parent.calcVars_corrFTrk() );
      } else {
         calcVars_corrFTrk()->clear();
      }
      if( parent.calcVars_drMin.IsAvailable() ) {
         *( calcVars_drMin() ) = *( parent.calcVars_drMin() );
      } else {
         calcVars_drMin()->clear();
      }
      if( parent.calcVars_etEM_EMScale_Pt3Trks.IsAvailable() ) {
         *( calcVars_etEM_EMScale_Pt3Trks() ) = *( parent.calcVars_etEM_EMScale_Pt3Trks() );
      } else {
         calcVars_etEM_EMScale_Pt3Trks()->clear();
      }
      if( parent.calcVars_etHad_EMScale_Pt3Trks.IsAvailable() ) {
         *( calcVars_etHad_EMScale_Pt3Trks() ) = *( parent.calcVars_etHad_EMScale_Pt3Trks() );
      } else {
         calcVars_etHad_EMScale_Pt3Trks()->clear();
      }
      if( parent.calcVars_interAxis_eta.IsAvailable() ) {
         *( calcVars_interAxis_eta() ) = *( parent.calcVars_interAxis_eta() );
      } else {
         calcVars_interAxis_eta()->clear();
      }
      if( parent.calcVars_interAxis_phi.IsAvailable() ) {
         *( calcVars_interAxis_phi() ) = *( parent.calcVars_interAxis_phi() );
      } else {
         calcVars_interAxis_phi()->clear();
      }
      if( parent.calcVars_ipSigLeadLooseTrk.IsAvailable() ) {
         *( calcVars_ipSigLeadLooseTrk() ) = *( parent.calcVars_ipSigLeadLooseTrk() );
      } else {
         calcVars_ipSigLeadLooseTrk()->clear();
      }
      if( parent.calcVars_pi0BDTPrimaryScore.IsAvailable() ) {
         *( calcVars_pi0BDTPrimaryScore() ) = *( parent.calcVars_pi0BDTPrimaryScore() );
      } else {
         calcVars_pi0BDTPrimaryScore()->clear();
      }
      if( parent.calcVars_pi0BDTSecondaryScore.IsAvailable() ) {
         *( calcVars_pi0BDTSecondaryScore() ) = *( parent.calcVars_pi0BDTSecondaryScore() );
      } else {
         calcVars_pi0BDTSecondaryScore()->clear();
      }
      if( parent.calcVars_trackIso.IsAvailable() ) {
         *( calcVars_trackIso() ) = *( parent.calcVars_trackIso() );
      } else {
         calcVars_trackIso()->clear();
      }
      if( parent.cellBasedEnergyRing1.IsAvailable() ) {
         *( cellBasedEnergyRing1() ) = *( parent.cellBasedEnergyRing1() );
      } else {
         cellBasedEnergyRing1()->clear();
      }
      if( parent.cellBasedEnergyRing2.IsAvailable() ) {
         *( cellBasedEnergyRing2() ) = *( parent.cellBasedEnergyRing2() );
      } else {
         cellBasedEnergyRing2()->clear();
      }
      if( parent.cellBasedEnergyRing3.IsAvailable() ) {
         *( cellBasedEnergyRing3() ) = *( parent.cellBasedEnergyRing3() );
      } else {
         cellBasedEnergyRing3()->clear();
      }
      if( parent.cellBasedEnergyRing4.IsAvailable() ) {
         *( cellBasedEnergyRing4() ) = *( parent.cellBasedEnergyRing4() );
      } else {
         cellBasedEnergyRing4()->clear();
      }
      if( parent.cellBasedEnergyRing5.IsAvailable() ) {
         *( cellBasedEnergyRing5() ) = *( parent.cellBasedEnergyRing5() );
      } else {
         cellBasedEnergyRing5()->clear();
      }
      if( parent.cellBasedEnergyRing6.IsAvailable() ) {
         *( cellBasedEnergyRing6() ) = *( parent.cellBasedEnergyRing6() );
      } else {
         cellBasedEnergyRing6()->clear();
      }
      if( parent.cellBasedEnergyRing7.IsAvailable() ) {
         *( cellBasedEnergyRing7() ) = *( parent.cellBasedEnergyRing7() );
      } else {
         cellBasedEnergyRing7()->clear();
      }
      if( parent.charge.IsAvailable() ) {
         *( charge() ) = *( parent.charge() );
      } else {
         charge()->clear();
      }
      if( parent.chrgLooseTrk.IsAvailable() ) {
         *( chrgLooseTrk() ) = *( parent.chrgLooseTrk() );
      } else {
         chrgLooseTrk()->clear();
      }
      if( parent.effTopoInvMass.IsAvailable() ) {
         *( effTopoInvMass() ) = *( parent.effTopoInvMass() );
      } else {
         effTopoInvMass()->clear();
      }
      if( parent.effTopoMeanDeltaR.IsAvailable() ) {
         *( effTopoMeanDeltaR() ) = *( parent.effTopoMeanDeltaR() );
      } else {
         effTopoMeanDeltaR()->clear();
      }
      if( parent.ele_E237E277.IsAvailable() ) {
         *( ele_E237E277() ) = *( parent.ele_E237E277() );
      } else {
         ele_E237E277()->clear();
      }
      if( parent.ele_ECALFirstFraction.IsAvailable() ) {
         *( ele_ECALFirstFraction() ) = *( parent.ele_ECALFirstFraction() );
      } else {
         ele_ECALFirstFraction()->clear();
      }
      if( parent.ele_PresamplerFraction.IsAvailable() ) {
         *( ele_PresamplerFraction() ) = *( parent.ele_PresamplerFraction() );
      } else {
         ele_PresamplerFraction()->clear();
      }
      if( parent.electronVetoLoose.IsAvailable() ) {
         *( electronVetoLoose() ) = *( parent.electronVetoLoose() );
      } else {
         electronVetoLoose()->clear();
      }
      if( parent.electronVetoMedium.IsAvailable() ) {
         *( electronVetoMedium() ) = *( parent.electronVetoMedium() );
      } else {
         electronVetoMedium()->clear();
      }
      if( parent.electronVetoTight.IsAvailable() ) {
         *( electronVetoTight() ) = *( parent.electronVetoTight() );
      } else {
         electronVetoTight()->clear();
      }
      if( parent.etEflow.IsAvailable() ) {
         *( etEflow() ) = *( parent.etEflow() );
      } else {
         etEflow()->clear();
      }
      if( parent.etOverPtLeadLooseTrk.IsAvailable() ) {
         *( etOverPtLeadLooseTrk() ) = *( parent.etOverPtLeadLooseTrk() );
      } else {
         etOverPtLeadLooseTrk()->clear();
      }
      if( parent.etOverPtLeadTrk.IsAvailable() ) {
         *( etOverPtLeadTrk() ) = *( parent.etOverPtLeadTrk() );
      } else {
         etOverPtLeadTrk()->clear();
      }
      if( parent.eta.IsAvailable() ) {
         *( eta() ) = *( parent.eta() );
      } else {
         eta()->clear();
      }
      if( parent.ipSigLeadLooseTrk.IsAvailable() ) {
         *( ipSigLeadLooseTrk() ) = *( parent.ipSigLeadLooseTrk() );
      } else {
         ipSigLeadLooseTrk()->clear();
      }
      if( parent.ipSigLeadTrk.IsAvailable() ) {
         *( ipSigLeadTrk() ) = *( parent.ipSigLeadTrk() );
      } else {
         ipSigLeadTrk()->clear();
      }
      if( parent.ipZ0SinThetaSigLeadTrk.IsAvailable() ) {
         *( ipZ0SinThetaSigLeadTrk() ) = *( parent.ipZ0SinThetaSigLeadTrk() );
      } else {
         ipZ0SinThetaSigLeadTrk()->clear();
      }
      if( parent.leadLooseTrkPt.IsAvailable() ) {
         *( leadLooseTrkPt() ) = *( parent.leadLooseTrkPt() );
      } else {
         leadLooseTrkPt()->clear();
      }
      if( parent.leadTrack_eta.IsAvailable() ) {
         *( leadTrack_eta() ) = *( parent.leadTrack_eta() );
      } else {
         leadTrack_eta()->clear();
      }
      if( parent.leadTrack_phi.IsAvailable() ) {
         *( leadTrack_phi() ) = *( parent.leadTrack_phi() );
      } else {
         leadTrack_phi()->clear();
      }
      if( parent.leadTrkPt.IsAvailable() ) {
         *( leadTrkPt() ) = *( parent.leadTrkPt() );
      } else {
         leadTrkPt()->clear();
      }
      if( parent.likelihood.IsAvailable() ) {
         *( likelihood() ) = *( parent.likelihood() );
      } else {
         likelihood()->clear();
      }
      if( parent.m.IsAvailable() ) {
         *( m() ) = *( parent.m() );
      } else {
         m()->clear();
      }
      if( parent.mEflow.IsAvailable() ) {
         *( mEflow() ) = *( parent.mEflow() );
      } else {
         mEflow()->clear();
      }
      if( parent.massTrkSys.IsAvailable() ) {
         *( massTrkSys() ) = *( parent.massTrkSys() );
      } else {
         massTrkSys()->clear();
      }
      if( parent.muonVeto.IsAvailable() ) {
         *( muonVeto() ) = *( parent.muonVeto() );
      } else {
         muonVeto()->clear();
      }
      if( parent.n.IsAvailable() ) {
         n() = parent.n();
      } else {
         n() = 0;
      }
      if( parent.nLooseConvTrk.IsAvailable() ) {
         *( nLooseConvTrk() ) = *( parent.nLooseConvTrk() );
      } else {
         nLooseConvTrk()->clear();
      }
      if( parent.nLooseTrk.IsAvailable() ) {
         *( nLooseTrk() ) = *( parent.nLooseTrk() );
      } else {
         nLooseTrk()->clear();
      }
      if( parent.nOtherTrk.IsAvailable() ) {
         *( nOtherTrk() ) = *( parent.nOtherTrk() );
      } else {
         nOtherTrk()->clear();
      }
      if( parent.nPi0.IsAvailable() ) {
         *( nPi0() ) = *( parent.nPi0() );
      } else {
         nPi0()->clear();
      }
      if( parent.nProng.IsAvailable() ) {
         *( nProng() ) = *( parent.nProng() );
      } else {
         nProng()->clear();
      }
      if( parent.nProngLoose.IsAvailable() ) {
         *( nProngLoose() ) = *( parent.nProngLoose() );
      } else {
         nProngLoose()->clear();
      }
      if( parent.numCells.IsAvailable() ) {
         *( numCells() ) = *( parent.numCells() );
      } else {
         numCells()->clear();
      }
      if( parent.numEffTopoClusters.IsAvailable() ) {
         *( numEffTopoClusters() ) = *( parent.numEffTopoClusters() );
      } else {
         numEffTopoClusters()->clear();
      }
      if( parent.numTopoClusters.IsAvailable() ) {
         *( numTopoClusters() ) = *( parent.numTopoClusters() );
      } else {
         numTopoClusters()->clear();
      }
      if( parent.numTrack.IsAvailable() ) {
         *( numTrack() ) = *( parent.numTrack() );
      } else {
         numTrack()->clear();
      }
      if( parent.otherTrk_atTJVA_n.IsAvailable() ) {
         *( otherTrk_atTJVA_n() ) = *( parent.otherTrk_atTJVA_n() );
      } else {
         otherTrk_atTJVA_n()->clear();
      }
      if( parent.otherTrk_n.IsAvailable() ) {
         *( otherTrk_n() ) = *( parent.otherTrk_n() );
      } else {
         otherTrk_n()->clear();
      }
      if( parent.phi.IsAvailable() ) {
         *( phi() ) = *( parent.phi() );
      } else {
         phi()->clear();
      }
      if( parent.pt.IsAvailable() ) {
         *( pt() ) = *( parent.pt() );
      } else {
         pt()->clear();
      }
      if( parent.seedCalo_EMRadius.IsAvailable() ) {
         *( seedCalo_EMRadius() ) = *( parent.seedCalo_EMRadius() );
      } else {
         seedCalo_EMRadius()->clear();
      }
      if( parent.seedCalo_caloIso.IsAvailable() ) {
         *( seedCalo_caloIso() ) = *( parent.seedCalo_caloIso() );
      } else {
         seedCalo_caloIso()->clear();
      }
      if( parent.seedCalo_caloIsoCorrected.IsAvailable() ) {
         *( seedCalo_caloIsoCorrected() ) = *( parent.seedCalo_caloIsoCorrected() );
      } else {
         seedCalo_caloIsoCorrected()->clear();
      }
      if( parent.seedCalo_centFrac.IsAvailable() ) {
         *( seedCalo_centFrac() ) = *( parent.seedCalo_centFrac() );
      } else {
         seedCalo_centFrac()->clear();
      }
      if( parent.seedCalo_dRmax.IsAvailable() ) {
         *( seedCalo_dRmax() ) = *( parent.seedCalo_dRmax() );
      } else {
         seedCalo_dRmax()->clear();
      }
      if( parent.seedCalo_etEMAtEMScale.IsAvailable() ) {
         *( seedCalo_etEMAtEMScale() ) = *( parent.seedCalo_etEMAtEMScale() );
      } else {
         seedCalo_etEMAtEMScale()->clear();
      }
      if( parent.seedCalo_etEMCalib.IsAvailable() ) {
         *( seedCalo_etEMCalib() ) = *( parent.seedCalo_etEMCalib() );
      } else {
         seedCalo_etEMCalib()->clear();
      }
      if( parent.seedCalo_etHadAtEMScale.IsAvailable() ) {
         *( seedCalo_etHadAtEMScale() ) = *( parent.seedCalo_etHadAtEMScale() );
      } else {
         seedCalo_etHadAtEMScale()->clear();
      }
      if( parent.seedCalo_etHadCalib.IsAvailable() ) {
         *( seedCalo_etHadCalib() ) = *( parent.seedCalo_etHadCalib() );
      } else {
         seedCalo_etHadCalib()->clear();
      }
      if( parent.seedCalo_eta.IsAvailable() ) {
         *( seedCalo_eta() ) = *( parent.seedCalo_eta() );
      } else {
         seedCalo_eta()->clear();
      }
      if( parent.seedCalo_hadRadius.IsAvailable() ) {
         *( seedCalo_hadRadius() ) = *( parent.seedCalo_hadRadius() );
      } else {
         seedCalo_hadRadius()->clear();
      }
      if( parent.seedCalo_isolFrac.IsAvailable() ) {
         *( seedCalo_isolFrac() ) = *( parent.seedCalo_isolFrac() );
      } else {
         seedCalo_isolFrac()->clear();
      }
      if( parent.seedCalo_lead2ClusterEOverAllClusterE.IsAvailable() ) {
         *( seedCalo_lead2ClusterEOverAllClusterE() ) = *( parent.seedCalo_lead2ClusterEOverAllClusterE() );
      } else {
         seedCalo_lead2ClusterEOverAllClusterE()->clear();
      }
      if( parent.seedCalo_lead3ClusterEOverAllClusterE.IsAvailable() ) {
         *( seedCalo_lead3ClusterEOverAllClusterE() ) = *( parent.seedCalo_lead3ClusterEOverAllClusterE() );
      } else {
         seedCalo_lead3ClusterEOverAllClusterE()->clear();
      }
      if( parent.seedCalo_nIsolLooseTrk.IsAvailable() ) {
         *( seedCalo_nIsolLooseTrk() ) = *( parent.seedCalo_nIsolLooseTrk() );
      } else {
         seedCalo_nIsolLooseTrk()->clear();
      }
      if( parent.seedCalo_nStrip.IsAvailable() ) {
         *( seedCalo_nStrip() ) = *( parent.seedCalo_nStrip() );
      } else {
         seedCalo_nStrip()->clear();
      }
      if( parent.seedCalo_nWideTrk.IsAvailable() ) {
         *( seedCalo_nWideTrk() ) = *( parent.seedCalo_nWideTrk() );
      } else {
         seedCalo_nWideTrk()->clear();
      }
      if( parent.seedCalo_numTrack.IsAvailable() ) {
         *( seedCalo_numTrack() ) = *( parent.seedCalo_numTrack() );
      } else {
         seedCalo_numTrack()->clear();
      }
      if( parent.seedCalo_phi.IsAvailable() ) {
         *( seedCalo_phi() ) = *( parent.seedCalo_phi() );
      } else {
         seedCalo_phi()->clear();
      }
      if( parent.seedCalo_stripWidth2.IsAvailable() ) {
         *( seedCalo_stripWidth2() ) = *( parent.seedCalo_stripWidth2() );
      } else {
         seedCalo_stripWidth2()->clear();
      }
      if( parent.seedCalo_track_n.IsAvailable() ) {
         *( seedCalo_track_n() ) = *( parent.seedCalo_track_n() );
      } else {
         seedCalo_track_n()->clear();
      }
      if( parent.seedCalo_trkAvgDist.IsAvailable() ) {
         *( seedCalo_trkAvgDist() ) = *( parent.seedCalo_trkAvgDist() );
      } else {
         seedCalo_trkAvgDist()->clear();
      }
      if( parent.seedCalo_trkRmsDist.IsAvailable() ) {
         *( seedCalo_trkRmsDist() ) = *( parent.seedCalo_trkRmsDist() );
      } else {
         seedCalo_trkRmsDist()->clear();
      }
      if( parent.seedCalo_wideTrk_atTJVA_n.IsAvailable() ) {
         *( seedCalo_wideTrk_atTJVA_n() ) = *( parent.seedCalo_wideTrk_atTJVA_n() );
      } else {
         seedCalo_wideTrk_atTJVA_n()->clear();
      }
      if( parent.seedCalo_wideTrk_n.IsAvailable() ) {
         *( seedCalo_wideTrk_n() ) = *( parent.seedCalo_wideTrk_n() );
      } else {
         seedCalo_wideTrk_n()->clear();
      }
      if( parent.seedTrk_EMRadius.IsAvailable() ) {
         *( seedTrk_EMRadius() ) = *( parent.seedTrk_EMRadius() );
      } else {
         seedTrk_EMRadius()->clear();
      }
      if( parent.seedTrk_etChrgEM.IsAvailable() ) {
         *( seedTrk_etChrgEM() ) = *( parent.seedTrk_etChrgEM() );
      } else {
         seedTrk_etChrgEM()->clear();
      }
      if( parent.seedTrk_etChrgHad.IsAvailable() ) {
         *( seedTrk_etChrgHad() ) = *( parent.seedTrk_etChrgHad() );
      } else {
         seedTrk_etChrgHad()->clear();
      }
      if( parent.seedTrk_etChrgHadOverSumTrkPt.IsAvailable() ) {
         *( seedTrk_etChrgHadOverSumTrkPt() ) = *( parent.seedTrk_etChrgHadOverSumTrkPt() );
      } else {
         seedTrk_etChrgHadOverSumTrkPt()->clear();
      }
      if( parent.seedTrk_etEMAtEMScale.IsAvailable() ) {
         *( seedTrk_etEMAtEMScale() ) = *( parent.seedTrk_etEMAtEMScale() );
      } else {
         seedTrk_etEMAtEMScale()->clear();
      }
      if( parent.seedTrk_etEMCL.IsAvailable() ) {
         *( seedTrk_etEMCL() ) = *( parent.seedTrk_etEMCL() );
      } else {
         seedTrk_etEMCL()->clear();
      }
      if( parent.seedTrk_etHadAtEMScale.IsAvailable() ) {
         *( seedTrk_etHadAtEMScale() ) = *( parent.seedTrk_etHadAtEMScale() );
      } else {
         seedTrk_etHadAtEMScale()->clear();
      }
      if( parent.seedTrk_etIsolEM.IsAvailable() ) {
         *( seedTrk_etIsolEM() ) = *( parent.seedTrk_etIsolEM() );
      } else {
         seedTrk_etIsolEM()->clear();
      }
      if( parent.seedTrk_etIsolHad.IsAvailable() ) {
         *( seedTrk_etIsolHad() ) = *( parent.seedTrk_etIsolHad() );
      } else {
         seedTrk_etIsolHad()->clear();
      }
      if( parent.seedTrk_etNeuEM.IsAvailable() ) {
         *( seedTrk_etNeuEM() ) = *( parent.seedTrk_etNeuEM() );
      } else {
         seedTrk_etNeuEM()->clear();
      }
      if( parent.seedTrk_etResNeuEM.IsAvailable() ) {
         *( seedTrk_etResNeuEM() ) = *( parent.seedTrk_etResNeuEM() );
      } else {
         seedTrk_etResNeuEM()->clear();
      }
      if( parent.seedTrk_hadLeakEt.IsAvailable() ) {
         *( seedTrk_hadLeakEt() ) = *( parent.seedTrk_hadLeakEt() );
      } else {
         seedTrk_hadLeakEt()->clear();
      }
      if( parent.seedTrk_isolFrac.IsAvailable() ) {
         *( seedTrk_isolFrac() ) = *( parent.seedTrk_isolFrac() );
      } else {
         seedTrk_isolFrac()->clear();
      }
      if( parent.seedTrk_isolFracWide.IsAvailable() ) {
         *( seedTrk_isolFracWide() ) = *( parent.seedTrk_isolFracWide() );
      } else {
         seedTrk_isolFracWide()->clear();
      }
      if( parent.seedTrk_nIsolTrk.IsAvailable() ) {
         *( seedTrk_nIsolTrk() ) = *( parent.seedTrk_nIsolTrk() );
      } else {
         seedTrk_nIsolTrk()->clear();
      }
      if( parent.seedTrk_nOtherCoreTrk.IsAvailable() ) {
         *( seedTrk_nOtherCoreTrk() ) = *( parent.seedTrk_nOtherCoreTrk() );
      } else {
         seedTrk_nOtherCoreTrk()->clear();
      }
      if( parent.seedTrk_nStrip.IsAvailable() ) {
         *( seedTrk_nStrip() ) = *( parent.seedTrk_nStrip() );
      } else {
         seedTrk_nStrip()->clear();
      }
      if( parent.seedTrk_secMaxStripEt.IsAvailable() ) {
         *( seedTrk_secMaxStripEt() ) = *( parent.seedTrk_secMaxStripEt() );
      } else {
         seedTrk_secMaxStripEt()->clear();
      }
      if( parent.seedTrk_stripWidth2.IsAvailable() ) {
         *( seedTrk_stripWidth2() ) = *( parent.seedTrk_stripWidth2() );
      } else {
         seedTrk_stripWidth2()->clear();
      }
      if( parent.seedTrk_sumEMCellEtOverLeadTrkPt.IsAvailable() ) {
         *( seedTrk_sumEMCellEtOverLeadTrkPt() ) = *( parent.seedTrk_sumEMCellEtOverLeadTrkPt() );
      } else {
         seedTrk_sumEMCellEtOverLeadTrkPt()->clear();
      }
      if( parent.tauLlhLoose.IsAvailable() ) {
         *( tauLlhLoose() ) = *( parent.tauLlhLoose() );
      } else {
         tauLlhLoose()->clear();
      }
      if( parent.tauLlhMedium.IsAvailable() ) {
         *( tauLlhMedium() ) = *( parent.tauLlhMedium() );
      } else {
         tauLlhMedium()->clear();
      }
      if( parent.tauLlhTight.IsAvailable() ) {
         *( tauLlhTight() ) = *( parent.tauLlhTight() );
      } else {
         tauLlhTight()->clear();
      }
      if( parent.topoInvMass.IsAvailable() ) {
         *( topoInvMass() ) = *( parent.topoInvMass() );
      } else {
         topoInvMass()->clear();
      }
      if( parent.topoMeanDeltaR.IsAvailable() ) {
         *( topoMeanDeltaR() ) = *( parent.topoMeanDeltaR() );
      } else {
         topoMeanDeltaR()->clear();
      }
      if( parent.trFlightPathSig.IsAvailable() ) {
         *( trFlightPathSig() ) = *( parent.trFlightPathSig() );
      } else {
         trFlightPathSig()->clear();
      }
      if( parent.track_atTJVA_n.IsAvailable() ) {
         *( track_atTJVA_n() ) = *( parent.track_atTJVA_n() );
      } else {
         track_atTJVA_n()->clear();
      }
      if( parent.track_n.IsAvailable() ) {
         *( track_n() ) = *( parent.track_n() );
      } else {
         track_n()->clear();
      }
      if( parent.trkWidth2.IsAvailable() ) {
         *( trkWidth2() ) = *( parent.trkWidth2() );
      } else {
         trkWidth2()->clear();
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
   void TauD3PDObject::Clear( Option_t* ) {

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
   TauD3PDObject& TauD3PDObject::Add( const TauD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( el.BDTEleScore.IsAvailable() ) {
         BDTEleScore()->push_back( el.BDTEleScore() );
      } else {
         BDTEleScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BDTJetScore.IsAvailable() ) {
         BDTJetScore()->push_back( el.BDTJetScore() );
      } else {
         BDTJetScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_E.IsAvailable() ) {
         EF_E()->push_back( el.EF_E() );
      } else {
         EF_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_Et.IsAvailable() ) {
         EF_Et()->push_back( el.EF_Et() );
      } else {
         EF_Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_dr.IsAvailable() ) {
         EF_dr()->push_back( el.EF_dr() );
      } else {
         EF_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_eta.IsAvailable() ) {
         EF_eta()->push_back( el.EF_eta() );
      } else {
         EF_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_matched.IsAvailable() ) {
         EF_matched()->push_back( el.EF_matched() );
      } else {
         EF_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EF_phi.IsAvailable() ) {
         EF_phi()->push_back( el.EF_phi() );
      } else {
         EF_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_pt.IsAvailable() ) {
         EF_pt()->push_back( el.EF_pt() );
      } else {
         EF_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EM_TES_scale.IsAvailable() ) {
         EM_TES_scale()->push_back( el.EM_TES_scale() );
      } else {
         EM_TES_scale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EleBDTLoose.IsAvailable() ) {
         EleBDTLoose()->push_back( el.EleBDTLoose() );
      } else {
         EleBDTLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EleBDTMedium.IsAvailable() ) {
         EleBDTMedium()->push_back( el.EleBDTMedium() );
      } else {
         EleBDTMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EleBDTTight.IsAvailable() ) {
         EleBDTTight()->push_back( el.EleBDTTight() );
      } else {
         EleBDTTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.Et.IsAvailable() ) {
         Et()->push_back( el.Et() );
      } else {
         Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.JetBDTSigLoose.IsAvailable() ) {
         JetBDTSigLoose()->push_back( el.JetBDTSigLoose() );
      } else {
         JetBDTSigLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.JetBDTSigMedium.IsAvailable() ) {
         JetBDTSigMedium()->push_back( el.JetBDTSigMedium() );
      } else {
         JetBDTSigMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.JetBDTSigTight.IsAvailable() ) {
         JetBDTSigTight()->push_back( el.JetBDTSigTight() );
      } else {
         JetBDTSigTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L1_Et.IsAvailable() ) {
         L1_Et()->push_back( el.L1_Et() );
      } else {
         L1_Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_dr.IsAvailable() ) {
         L1_dr()->push_back( el.L1_dr() );
      } else {
         L1_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_eta.IsAvailable() ) {
         L1_eta()->push_back( el.L1_eta() );
      } else {
         L1_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_matched.IsAvailable() ) {
         L1_matched()->push_back( el.L1_matched() );
      } else {
         L1_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L1_phi.IsAvailable() ) {
         L1_phi()->push_back( el.L1_phi() );
      } else {
         L1_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_pt.IsAvailable() ) {
         L1_pt()->push_back( el.L1_pt() );
      } else {
         L1_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_E.IsAvailable() ) {
         L2_E()->push_back( el.L2_E() );
      } else {
         L2_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_Et.IsAvailable() ) {
         L2_Et()->push_back( el.L2_Et() );
      } else {
         L2_Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_dr.IsAvailable() ) {
         L2_dr()->push_back( el.L2_dr() );
      } else {
         L2_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_eta.IsAvailable() ) {
         L2_eta()->push_back( el.L2_eta() );
      } else {
         L2_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_matched.IsAvailable() ) {
         L2_matched()->push_back( el.L2_matched() );
      } else {
         L2_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L2_phi.IsAvailable() ) {
         L2_phi()->push_back( el.L2_phi() );
      } else {
         L2_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_pt.IsAvailable() ) {
         L2_pt()->push_back( el.L2_pt() );
      } else {
         L2_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.LC_TES_precalib.IsAvailable() ) {
         LC_TES_precalib()->push_back( el.LC_TES_precalib() );
      } else {
         LC_TES_precalib()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.RoIWord.IsAvailable() ) {
         RoIWord()->push_back( el.RoIWord() );
      } else {
         RoIWord()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.SafeLikelihood.IsAvailable() ) {
         SafeLikelihood()->push_back( el.SafeLikelihood() );
      } else {
         SafeLikelihood()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.TRTHTOverLT_LeadTrk.IsAvailable() ) {
         TRTHTOverLT_LeadTrk()->push_back( el.TRTHTOverLT_LeadTrk() );
      } else {
         TRTHTOverLT_LeadTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.author.IsAvailable() ) {
         author()->push_back( el.author() );
      } else {
         author()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.calcVars_ChPiEMEOverCaloEME.IsAvailable() ) {
         calcVars_ChPiEMEOverCaloEME()->push_back( el.calcVars_ChPiEMEOverCaloEME() );
      } else {
         calcVars_ChPiEMEOverCaloEME()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_EMFractionAtEMScale.IsAvailable() ) {
         calcVars_EMFractionAtEMScale()->push_back( el.calcVars_EMFractionAtEMScale() );
      } else {
         calcVars_EMFractionAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_EMPOverTrkSysP.IsAvailable() ) {
         calcVars_EMPOverTrkSysP()->push_back( el.calcVars_EMPOverTrkSysP() );
      } else {
         calcVars_EMPOverTrkSysP()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_PSSFraction.IsAvailable() ) {
         calcVars_PSSFraction()->push_back( el.calcVars_PSSFraction() );
      } else {
         calcVars_PSSFraction()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_calRadius.IsAvailable() ) {
         calcVars_calRadius()->push_back( el.calcVars_calRadius() );
      } else {
         calcVars_calRadius()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_corrCentFrac.IsAvailable() ) {
         calcVars_corrCentFrac()->push_back( el.calcVars_corrCentFrac() );
      } else {
         calcVars_corrCentFrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_corrFTrk.IsAvailable() ) {
         calcVars_corrFTrk()->push_back( el.calcVars_corrFTrk() );
      } else {
         calcVars_corrFTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_drMin.IsAvailable() ) {
         calcVars_drMin()->push_back( el.calcVars_drMin() );
      } else {
         calcVars_drMin()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_etEM_EMScale_Pt3Trks.IsAvailable() ) {
         calcVars_etEM_EMScale_Pt3Trks()->push_back( el.calcVars_etEM_EMScale_Pt3Trks() );
      } else {
         calcVars_etEM_EMScale_Pt3Trks()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_etHad_EMScale_Pt3Trks.IsAvailable() ) {
         calcVars_etHad_EMScale_Pt3Trks()->push_back( el.calcVars_etHad_EMScale_Pt3Trks() );
      } else {
         calcVars_etHad_EMScale_Pt3Trks()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_interAxis_eta.IsAvailable() ) {
         calcVars_interAxis_eta()->push_back( el.calcVars_interAxis_eta() );
      } else {
         calcVars_interAxis_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_interAxis_phi.IsAvailable() ) {
         calcVars_interAxis_phi()->push_back( el.calcVars_interAxis_phi() );
      } else {
         calcVars_interAxis_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_ipSigLeadLooseTrk.IsAvailable() ) {
         calcVars_ipSigLeadLooseTrk()->push_back( el.calcVars_ipSigLeadLooseTrk() );
      } else {
         calcVars_ipSigLeadLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_pi0BDTPrimaryScore.IsAvailable() ) {
         calcVars_pi0BDTPrimaryScore()->push_back( el.calcVars_pi0BDTPrimaryScore() );
      } else {
         calcVars_pi0BDTPrimaryScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_pi0BDTSecondaryScore.IsAvailable() ) {
         calcVars_pi0BDTSecondaryScore()->push_back( el.calcVars_pi0BDTSecondaryScore() );
      } else {
         calcVars_pi0BDTSecondaryScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_trackIso.IsAvailable() ) {
         calcVars_trackIso()->push_back( el.calcVars_trackIso() );
      } else {
         calcVars_trackIso()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing1.IsAvailable() ) {
         cellBasedEnergyRing1()->push_back( el.cellBasedEnergyRing1() );
      } else {
         cellBasedEnergyRing1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing2.IsAvailable() ) {
         cellBasedEnergyRing2()->push_back( el.cellBasedEnergyRing2() );
      } else {
         cellBasedEnergyRing2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing3.IsAvailable() ) {
         cellBasedEnergyRing3()->push_back( el.cellBasedEnergyRing3() );
      } else {
         cellBasedEnergyRing3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing4.IsAvailable() ) {
         cellBasedEnergyRing4()->push_back( el.cellBasedEnergyRing4() );
      } else {
         cellBasedEnergyRing4()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing5.IsAvailable() ) {
         cellBasedEnergyRing5()->push_back( el.cellBasedEnergyRing5() );
      } else {
         cellBasedEnergyRing5()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing6.IsAvailable() ) {
         cellBasedEnergyRing6()->push_back( el.cellBasedEnergyRing6() );
      } else {
         cellBasedEnergyRing6()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing7.IsAvailable() ) {
         cellBasedEnergyRing7()->push_back( el.cellBasedEnergyRing7() );
      } else {
         cellBasedEnergyRing7()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.charge.IsAvailable() ) {
         charge()->push_back( el.charge() );
      } else {
         charge()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.chrgLooseTrk.IsAvailable() ) {
         chrgLooseTrk()->push_back( el.chrgLooseTrk() );
      } else {
         chrgLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.effTopoInvMass.IsAvailable() ) {
         effTopoInvMass()->push_back( el.effTopoInvMass() );
      } else {
         effTopoInvMass()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.effTopoMeanDeltaR.IsAvailable() ) {
         effTopoMeanDeltaR()->push_back( el.effTopoMeanDeltaR() );
      } else {
         effTopoMeanDeltaR()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ele_E237E277.IsAvailable() ) {
         ele_E237E277()->push_back( el.ele_E237E277() );
      } else {
         ele_E237E277()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ele_ECALFirstFraction.IsAvailable() ) {
         ele_ECALFirstFraction()->push_back( el.ele_ECALFirstFraction() );
      } else {
         ele_ECALFirstFraction()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ele_PresamplerFraction.IsAvailable() ) {
         ele_PresamplerFraction()->push_back( el.ele_PresamplerFraction() );
      } else {
         ele_PresamplerFraction()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.electronVetoLoose.IsAvailable() ) {
         electronVetoLoose()->push_back( el.electronVetoLoose() );
      } else {
         electronVetoLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.electronVetoMedium.IsAvailable() ) {
         electronVetoMedium()->push_back( el.electronVetoMedium() );
      } else {
         electronVetoMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.electronVetoTight.IsAvailable() ) {
         electronVetoTight()->push_back( el.electronVetoTight() );
      } else {
         electronVetoTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.etEflow.IsAvailable() ) {
         etEflow()->push_back( el.etEflow() );
      } else {
         etEflow()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etOverPtLeadLooseTrk.IsAvailable() ) {
         etOverPtLeadLooseTrk()->push_back( el.etOverPtLeadLooseTrk() );
      } else {
         etOverPtLeadLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etOverPtLeadTrk.IsAvailable() ) {
         etOverPtLeadTrk()->push_back( el.etOverPtLeadTrk() );
      } else {
         etOverPtLeadTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eta.IsAvailable() ) {
         eta()->push_back( el.eta() );
      } else {
         eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ipSigLeadLooseTrk.IsAvailable() ) {
         ipSigLeadLooseTrk()->push_back( el.ipSigLeadLooseTrk() );
      } else {
         ipSigLeadLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ipSigLeadTrk.IsAvailable() ) {
         ipSigLeadTrk()->push_back( el.ipSigLeadTrk() );
      } else {
         ipSigLeadTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ipZ0SinThetaSigLeadTrk.IsAvailable() ) {
         ipZ0SinThetaSigLeadTrk()->push_back( el.ipZ0SinThetaSigLeadTrk() );
      } else {
         ipZ0SinThetaSigLeadTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.leadLooseTrkPt.IsAvailable() ) {
         leadLooseTrkPt()->push_back( el.leadLooseTrkPt() );
      } else {
         leadLooseTrkPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.leadTrack_eta.IsAvailable() ) {
         leadTrack_eta()->push_back( el.leadTrack_eta() );
      } else {
         leadTrack_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.leadTrack_phi.IsAvailable() ) {
         leadTrack_phi()->push_back( el.leadTrack_phi() );
      } else {
         leadTrack_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.leadTrkPt.IsAvailable() ) {
         leadTrkPt()->push_back( el.leadTrkPt() );
      } else {
         leadTrkPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.likelihood.IsAvailable() ) {
         likelihood()->push_back( el.likelihood() );
      } else {
         likelihood()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.mEflow.IsAvailable() ) {
         mEflow()->push_back( el.mEflow() );
      } else {
         mEflow()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.massTrkSys.IsAvailable() ) {
         massTrkSys()->push_back( el.massTrkSys() );
      } else {
         massTrkSys()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.muonVeto.IsAvailable() ) {
         muonVeto()->push_back( el.muonVeto() );
      } else {
         muonVeto()->push_back( std::numeric_limits< int >::min() );
      }
      ++( n() );
      if( el.nLooseConvTrk.IsAvailable() ) {
         nLooseConvTrk()->push_back( el.nLooseConvTrk() );
      } else {
         nLooseConvTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nLooseTrk.IsAvailable() ) {
         nLooseTrk()->push_back( el.nLooseTrk() );
      } else {
         nLooseTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nOtherTrk.IsAvailable() ) {
         nOtherTrk()->push_back( el.nOtherTrk() );
      } else {
         nOtherTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPi0.IsAvailable() ) {
         nPi0()->push_back( el.nPi0() );
      } else {
         nPi0()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nProng.IsAvailable() ) {
         nProng()->push_back( el.nProng() );
      } else {
         nProng()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nProngLoose.IsAvailable() ) {
         nProngLoose()->push_back( el.nProngLoose() );
      } else {
         nProngLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.numCells.IsAvailable() ) {
         numCells()->push_back( el.numCells() );
      } else {
         numCells()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.numEffTopoClusters.IsAvailable() ) {
         numEffTopoClusters()->push_back( el.numEffTopoClusters() );
      } else {
         numEffTopoClusters()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.numTopoClusters.IsAvailable() ) {
         numTopoClusters()->push_back( el.numTopoClusters() );
      } else {
         numTopoClusters()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.numTrack.IsAvailable() ) {
         numTrack()->push_back( el.numTrack() );
      } else {
         numTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.otherTrk_atTJVA_n.IsAvailable() ) {
         otherTrk_atTJVA_n()->push_back( el.otherTrk_atTJVA_n() );
      } else {
         otherTrk_atTJVA_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.otherTrk_n.IsAvailable() ) {
         otherTrk_n()->push_back( el.otherTrk_n() );
      } else {
         otherTrk_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.phi.IsAvailable() ) {
         phi()->push_back( el.phi() );
      } else {
         phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pt.IsAvailable() ) {
         pt()->push_back( el.pt() );
      } else {
         pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_EMRadius.IsAvailable() ) {
         seedCalo_EMRadius()->push_back( el.seedCalo_EMRadius() );
      } else {
         seedCalo_EMRadius()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_caloIso.IsAvailable() ) {
         seedCalo_caloIso()->push_back( el.seedCalo_caloIso() );
      } else {
         seedCalo_caloIso()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_caloIsoCorrected.IsAvailable() ) {
         seedCalo_caloIsoCorrected()->push_back( el.seedCalo_caloIsoCorrected() );
      } else {
         seedCalo_caloIsoCorrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_centFrac.IsAvailable() ) {
         seedCalo_centFrac()->push_back( el.seedCalo_centFrac() );
      } else {
         seedCalo_centFrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_dRmax.IsAvailable() ) {
         seedCalo_dRmax()->push_back( el.seedCalo_dRmax() );
      } else {
         seedCalo_dRmax()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_etEMAtEMScale.IsAvailable() ) {
         seedCalo_etEMAtEMScale()->push_back( el.seedCalo_etEMAtEMScale() );
      } else {
         seedCalo_etEMAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_etEMCalib.IsAvailable() ) {
         seedCalo_etEMCalib()->push_back( el.seedCalo_etEMCalib() );
      } else {
         seedCalo_etEMCalib()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_etHadAtEMScale.IsAvailable() ) {
         seedCalo_etHadAtEMScale()->push_back( el.seedCalo_etHadAtEMScale() );
      } else {
         seedCalo_etHadAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_etHadCalib.IsAvailable() ) {
         seedCalo_etHadCalib()->push_back( el.seedCalo_etHadCalib() );
      } else {
         seedCalo_etHadCalib()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_eta.IsAvailable() ) {
         seedCalo_eta()->push_back( el.seedCalo_eta() );
      } else {
         seedCalo_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_hadRadius.IsAvailable() ) {
         seedCalo_hadRadius()->push_back( el.seedCalo_hadRadius() );
      } else {
         seedCalo_hadRadius()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_isolFrac.IsAvailable() ) {
         seedCalo_isolFrac()->push_back( el.seedCalo_isolFrac() );
      } else {
         seedCalo_isolFrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_lead2ClusterEOverAllClusterE.IsAvailable() ) {
         seedCalo_lead2ClusterEOverAllClusterE()->push_back( el.seedCalo_lead2ClusterEOverAllClusterE() );
      } else {
         seedCalo_lead2ClusterEOverAllClusterE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_lead3ClusterEOverAllClusterE.IsAvailable() ) {
         seedCalo_lead3ClusterEOverAllClusterE()->push_back( el.seedCalo_lead3ClusterEOverAllClusterE() );
      } else {
         seedCalo_lead3ClusterEOverAllClusterE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_nIsolLooseTrk.IsAvailable() ) {
         seedCalo_nIsolLooseTrk()->push_back( el.seedCalo_nIsolLooseTrk() );
      } else {
         seedCalo_nIsolLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_nStrip.IsAvailable() ) {
         seedCalo_nStrip()->push_back( el.seedCalo_nStrip() );
      } else {
         seedCalo_nStrip()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_nWideTrk.IsAvailable() ) {
         seedCalo_nWideTrk()->push_back( el.seedCalo_nWideTrk() );
      } else {
         seedCalo_nWideTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_numTrack.IsAvailable() ) {
         seedCalo_numTrack()->push_back( el.seedCalo_numTrack() );
      } else {
         seedCalo_numTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_phi.IsAvailable() ) {
         seedCalo_phi()->push_back( el.seedCalo_phi() );
      } else {
         seedCalo_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_stripWidth2.IsAvailable() ) {
         seedCalo_stripWidth2()->push_back( el.seedCalo_stripWidth2() );
      } else {
         seedCalo_stripWidth2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_track_n.IsAvailable() ) {
         seedCalo_track_n()->push_back( el.seedCalo_track_n() );
      } else {
         seedCalo_track_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_trkAvgDist.IsAvailable() ) {
         seedCalo_trkAvgDist()->push_back( el.seedCalo_trkAvgDist() );
      } else {
         seedCalo_trkAvgDist()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_trkRmsDist.IsAvailable() ) {
         seedCalo_trkRmsDist()->push_back( el.seedCalo_trkRmsDist() );
      } else {
         seedCalo_trkRmsDist()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_wideTrk_atTJVA_n.IsAvailable() ) {
         seedCalo_wideTrk_atTJVA_n()->push_back( el.seedCalo_wideTrk_atTJVA_n() );
      } else {
         seedCalo_wideTrk_atTJVA_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_wideTrk_n.IsAvailable() ) {
         seedCalo_wideTrk_n()->push_back( el.seedCalo_wideTrk_n() );
      } else {
         seedCalo_wideTrk_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedTrk_EMRadius.IsAvailable() ) {
         seedTrk_EMRadius()->push_back( el.seedTrk_EMRadius() );
      } else {
         seedTrk_EMRadius()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etChrgEM.IsAvailable() ) {
         seedTrk_etChrgEM()->push_back( el.seedTrk_etChrgEM() );
      } else {
         seedTrk_etChrgEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etChrgHad.IsAvailable() ) {
         seedTrk_etChrgHad()->push_back( el.seedTrk_etChrgHad() );
      } else {
         seedTrk_etChrgHad()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etChrgHadOverSumTrkPt.IsAvailable() ) {
         seedTrk_etChrgHadOverSumTrkPt()->push_back( el.seedTrk_etChrgHadOverSumTrkPt() );
      } else {
         seedTrk_etChrgHadOverSumTrkPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etEMAtEMScale.IsAvailable() ) {
         seedTrk_etEMAtEMScale()->push_back( el.seedTrk_etEMAtEMScale() );
      } else {
         seedTrk_etEMAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etEMCL.IsAvailable() ) {
         seedTrk_etEMCL()->push_back( el.seedTrk_etEMCL() );
      } else {
         seedTrk_etEMCL()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etHadAtEMScale.IsAvailable() ) {
         seedTrk_etHadAtEMScale()->push_back( el.seedTrk_etHadAtEMScale() );
      } else {
         seedTrk_etHadAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etIsolEM.IsAvailable() ) {
         seedTrk_etIsolEM()->push_back( el.seedTrk_etIsolEM() );
      } else {
         seedTrk_etIsolEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etIsolHad.IsAvailable() ) {
         seedTrk_etIsolHad()->push_back( el.seedTrk_etIsolHad() );
      } else {
         seedTrk_etIsolHad()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etNeuEM.IsAvailable() ) {
         seedTrk_etNeuEM()->push_back( el.seedTrk_etNeuEM() );
      } else {
         seedTrk_etNeuEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etResNeuEM.IsAvailable() ) {
         seedTrk_etResNeuEM()->push_back( el.seedTrk_etResNeuEM() );
      } else {
         seedTrk_etResNeuEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_hadLeakEt.IsAvailable() ) {
         seedTrk_hadLeakEt()->push_back( el.seedTrk_hadLeakEt() );
      } else {
         seedTrk_hadLeakEt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_isolFrac.IsAvailable() ) {
         seedTrk_isolFrac()->push_back( el.seedTrk_isolFrac() );
      } else {
         seedTrk_isolFrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_isolFracWide.IsAvailable() ) {
         seedTrk_isolFracWide()->push_back( el.seedTrk_isolFracWide() );
      } else {
         seedTrk_isolFracWide()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_nIsolTrk.IsAvailable() ) {
         seedTrk_nIsolTrk()->push_back( el.seedTrk_nIsolTrk() );
      } else {
         seedTrk_nIsolTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedTrk_nOtherCoreTrk.IsAvailable() ) {
         seedTrk_nOtherCoreTrk()->push_back( el.seedTrk_nOtherCoreTrk() );
      } else {
         seedTrk_nOtherCoreTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedTrk_nStrip.IsAvailable() ) {
         seedTrk_nStrip()->push_back( el.seedTrk_nStrip() );
      } else {
         seedTrk_nStrip()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedTrk_secMaxStripEt.IsAvailable() ) {
         seedTrk_secMaxStripEt()->push_back( el.seedTrk_secMaxStripEt() );
      } else {
         seedTrk_secMaxStripEt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_stripWidth2.IsAvailable() ) {
         seedTrk_stripWidth2()->push_back( el.seedTrk_stripWidth2() );
      } else {
         seedTrk_stripWidth2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_sumEMCellEtOverLeadTrkPt.IsAvailable() ) {
         seedTrk_sumEMCellEtOverLeadTrkPt()->push_back( el.seedTrk_sumEMCellEtOverLeadTrkPt() );
      } else {
         seedTrk_sumEMCellEtOverLeadTrkPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tauLlhLoose.IsAvailable() ) {
         tauLlhLoose()->push_back( el.tauLlhLoose() );
      } else {
         tauLlhLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tauLlhMedium.IsAvailable() ) {
         tauLlhMedium()->push_back( el.tauLlhMedium() );
      } else {
         tauLlhMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tauLlhTight.IsAvailable() ) {
         tauLlhTight()->push_back( el.tauLlhTight() );
      } else {
         tauLlhTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.topoInvMass.IsAvailable() ) {
         topoInvMass()->push_back( el.topoInvMass() );
      } else {
         topoInvMass()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoMeanDeltaR.IsAvailable() ) {
         topoMeanDeltaR()->push_back( el.topoMeanDeltaR() );
      } else {
         topoMeanDeltaR()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trFlightPathSig.IsAvailable() ) {
         trFlightPathSig()->push_back( el.trFlightPathSig() );
      } else {
         trFlightPathSig()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.track_atTJVA_n.IsAvailable() ) {
         track_atTJVA_n()->push_back( el.track_atTJVA_n() );
      } else {
         track_atTJVA_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.track_n.IsAvailable() ) {
         track_n()->push_back( el.track_n() );
      } else {
         track_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trkWidth2.IsAvailable() ) {
         trkWidth2()->push_back( el.trkWidth2() );
      } else {
         trkWidth2()->push_back( std::numeric_limits< float >::min() );
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
   TauD3PDObjectElement& TauD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new TauD3PDObjectElement( fProxies.size(), *this ) );
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
   const TauD3PDObjectElement& TauD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new TauD3PDObjectElement( fProxies.size(), *this ) );
      }
      return *fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   TauD3PDObject& TauD3PDObject::operator+=( const TauD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
