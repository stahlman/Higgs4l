// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/JetD3PDObject.h"

ClassImp( D3PDReader::JetD3PDObjectElement )
ClassImp( D3PDReader::JetD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class JetD3PDObject.
    */
   JetD3PDObjectElement::JetD3PDObjectElement( size_t index, const JetD3PDObject& parent )
      : ActiveArea( parent.ActiveArea, index, this ),
        ActiveAreaE( parent.ActiveAreaE, index, this ),
        ActiveAreaPx( parent.ActiveAreaPx, index, this ),
        ActiveAreaPy( parent.ActiveAreaPy, index, this ),
        ActiveAreaPz( parent.ActiveAreaPz, index, this ),
        AverageLArQF( parent.AverageLArQF, index, this ),
        BAD_CELLS_CORR_E( parent.BAD_CELLS_CORR_E, index, this ),
        BCH_CORR_CELL( parent.BCH_CORR_CELL, index, this ),
        BCH_CORR_DOTX( parent.BCH_CORR_DOTX, index, this ),
        BCH_CORR_JET( parent.BCH_CORR_JET, index, this ),
        BCH_CORR_JET_FORCELL( parent.BCH_CORR_JET_FORCELL, index, this ),
        E( parent.E, index, this ),
        EF_dr( parent.EF_dr, index, this ),
        EF_matched( parent.EF_matched, index, this ),
        EMJES( parent.EMJES, index, this ),
        EMJES_EtaCorr( parent.EMJES_EtaCorr, index, this ),
        EMJESnooffset( parent.EMJESnooffset, index, this ),
        ENG_BAD_CELLS( parent.ENG_BAD_CELLS, index, this ),
        EtaOrigin( parent.EtaOrigin, index, this ),
        GSCFactorF( parent.GSCFactorF, index, this ),
        HECQuality( parent.HECQuality, index, this ),
        L1_dr( parent.L1_dr, index, this ),
        L1_matched( parent.L1_matched, index, this ),
        L2_dr( parent.L2_dr, index, this ),
        L2_matched( parent.L2_matched, index, this ),
        LArQuality( parent.LArQuality, index, this ),
        LCJES( parent.LCJES, index, this ),
        LCJES_EtaCorr( parent.LCJES_EtaCorr, index, this ),
        MOrigin( parent.MOrigin, index, this ),
        N_BAD_CELLS( parent.N_BAD_CELLS, index, this ),
        N_BAD_CELLS_CORR( parent.N_BAD_CELLS_CORR, index, this ),
        Nconst( parent.Nconst, index, this ),
        NegativeE( parent.NegativeE, index, this ),
        NumTowers( parent.NumTowers, index, this ),
        Offset( parent.Offset, index, this ),
        OriginIndex( parent.OriginIndex, index, this ),
        PhiOrigin( parent.PhiOrigin, index, this ),
        SamplingMax( parent.SamplingMax, index, this ),
        Timing( parent.Timing, index, this ),
        TruthMF( parent.TruthMF, index, this ),
        TruthMFindex( parent.TruthMFindex, index, this ),
        WIDTH( parent.WIDTH, index, this ),
        WidthFraction( parent.WidthFraction, index, this ),
        constscale_E( parent.constscale_E, index, this ),
        constscale_eta( parent.constscale_eta, index, this ),
        constscale_m( parent.constscale_m, index, this ),
        constscale_phi( parent.constscale_phi, index, this ),
        constscale_pt( parent.constscale_pt, index, this ),
        e_EMB1( parent.e_EMB1, index, this ),
        e_EMB2( parent.e_EMB2, index, this ),
        e_EMB3( parent.e_EMB3, index, this ),
        e_EME1( parent.e_EME1, index, this ),
        e_EME2( parent.e_EME2, index, this ),
        e_EME3( parent.e_EME3, index, this ),
        e_FCAL0( parent.e_FCAL0, index, this ),
        e_FCAL1( parent.e_FCAL1, index, this ),
        e_FCAL2( parent.e_FCAL2, index, this ),
        e_HEC0( parent.e_HEC0, index, this ),
        e_HEC1( parent.e_HEC1, index, this ),
        e_HEC2( parent.e_HEC2, index, this ),
        e_HEC3( parent.e_HEC3, index, this ),
        e_PreSamplerB( parent.e_PreSamplerB, index, this ),
        e_PreSamplerE( parent.e_PreSamplerE, index, this ),
        e_TileBar0( parent.e_TileBar0, index, this ),
        e_TileBar1( parent.e_TileBar1, index, this ),
        e_TileBar2( parent.e_TileBar2, index, this ),
        e_TileExt0( parent.e_TileExt0, index, this ),
        e_TileExt1( parent.e_TileExt1, index, this ),
        e_TileExt2( parent.e_TileExt2, index, this ),
        e_TileGap1( parent.e_TileGap1, index, this ),
        e_TileGap2( parent.e_TileGap2, index, this ),
        e_TileGap3( parent.e_TileGap3, index, this ),
        econst_default( parent.econst_default, index, this ),
        el_dr( parent.el_dr, index, this ),
        el_matched( parent.el_matched, index, this ),
        emfrac( parent.emfrac, index, this ),
        emscale_E( parent.emscale_E, index, this ),
        emscale_eta( parent.emscale_eta, index, this ),
        emscale_m( parent.emscale_m, index, this ),
        emscale_phi( parent.emscale_phi, index, this ),
        emscale_pt( parent.emscale_pt, index, this ),
        eta( parent.eta, index, this ),
        etaconst_default( parent.etaconst_default, index, this ),
        flavor_component_jfitc_doublePropName( parent.flavor_component_jfitc_doublePropName, index, this ),
        flavor_component_jfitc_doublePropValue( parent.flavor_component_jfitc_doublePropValue, index, this ),
        flavor_component_jfitc_intPropName( parent.flavor_component_jfitc_intPropName, index, this ),
        flavor_component_jfitc_intPropValue( parent.flavor_component_jfitc_intPropValue, index, this ),
        flavor_component_jfitc_isValid( parent.flavor_component_jfitc_isValid, index, this ),
        flavor_component_jfitc_pb( parent.flavor_component_jfitc_pb, index, this ),
        flavor_component_jfitc_pc( parent.flavor_component_jfitc_pc, index, this ),
        flavor_component_jfitc_pu( parent.flavor_component_jfitc_pu, index, this ),
        flavor_truth_BHadronpdg( parent.flavor_truth_BHadronpdg, index, this ),
        flavor_truth_dRminToB( parent.flavor_truth_dRminToB, index, this ),
        flavor_truth_dRminToC( parent.flavor_truth_dRminToC, index, this ),
        flavor_truth_dRminToT( parent.flavor_truth_dRminToT, index, this ),
        flavor_truth_label( parent.flavor_truth_label, index, this ),
        flavor_truth_vx_x( parent.flavor_truth_vx_x, index, this ),
        flavor_truth_vx_y( parent.flavor_truth_vx_y, index, this ),
        flavor_truth_vx_z( parent.flavor_truth_vx_z, index, this ),
        flavor_weight_Comb( parent.flavor_weight_Comb, index, this ),
        flavor_weight_GbbNN( parent.flavor_weight_GbbNN, index, this ),
        flavor_weight_IP2D( parent.flavor_weight_IP2D, index, this ),
        flavor_weight_IP3D( parent.flavor_weight_IP3D, index, this ),
        flavor_weight_JetFitterCOMBNN( parent.flavor_weight_JetFitterCOMBNN, index, this ),
        flavor_weight_JetFitterCharm( parent.flavor_weight_JetFitterCharm, index, this ),
        flavor_weight_JetFitterTagNN( parent.flavor_weight_JetFitterTagNN, index, this ),
        flavor_weight_MV1( parent.flavor_weight_MV1, index, this ),
        flavor_weight_MV2( parent.flavor_weight_MV2, index, this ),
        flavor_weight_MV3_bVSc( parent.flavor_weight_MV3_bVSc, index, this ),
        flavor_weight_MV3_bVSu( parent.flavor_weight_MV3_bVSu, index, this ),
        flavor_weight_MV3_cVSu( parent.flavor_weight_MV3_cVSu, index, this ),
        flavor_weight_SV0( parent.flavor_weight_SV0, index, this ),
        flavor_weight_SV1( parent.flavor_weight_SV1, index, this ),
        flavor_weight_SV2( parent.flavor_weight_SV2, index, this ),
        flavor_weight_SecondSoftMuonTagChi2( parent.flavor_weight_SecondSoftMuonTagChi2, index, this ),
        flavor_weight_SoftMuonTagChi2( parent.flavor_weight_SoftMuonTagChi2, index, this ),
        fracSamplingMax( parent.fracSamplingMax, index, this ),
        hecf( parent.hecf, index, this ),
        isBadLoose( parent.isBadLoose, index, this ),
        isBadLooseMinus( parent.isBadLooseMinus, index, this ),
        isBadMedium( parent.isBadMedium, index, this ),
        isBadTight( parent.isBadTight, index, this ),
        isUgly( parent.isUgly, index, this ),
        jvtx_x( parent.jvtx_x, index, this ),
        jvtx_y( parent.jvtx_y, index, this ),
        jvtx_z( parent.jvtx_z, index, this ),
        jvtxf( parent.jvtxf, index, this ),
        jvtxfFull( parent.jvtxfFull, index, this ),
        m( parent.m, index, this ),
        mu_dr( parent.mu_dr, index, this ),
        mu_matched( parent.mu_matched, index, this ),
        n90( parent.n90, index, this ),
        nTrk( parent.nTrk, index, this ),
        nTrk_allpv_1GeV( parent.nTrk_allpv_1GeV, index, this ),
        nTrk_pv0_1GeV( parent.nTrk_pv0_1GeV, index, this ),
        nTrk_pv0_500MeV( parent.nTrk_pv0_500MeV, index, this ),
        ootFracCells10( parent.ootFracCells10, index, this ),
        ootFracCells5( parent.ootFracCells5, index, this ),
        ootFracClusters10( parent.ootFracClusters10, index, this ),
        ootFracClusters5( parent.ootFracClusters5, index, this ),
        phi( parent.phi, index, this ),
        phiconst_default( parent.phiconst_default, index, this ),
        pt( parent.pt, index, this ),
        ptconst_default( parent.ptconst_default, index, this ),
        sumPtTrk( parent.sumPtTrk, index, this ),
        sumPtTrk_allpv_1GeV( parent.sumPtTrk_allpv_1GeV, index, this ),
        sumPtTrk_pv0_1GeV( parent.sumPtTrk_pv0_1GeV, index, this ),
        sumPtTrk_pv0_500MeV( parent.sumPtTrk_pv0_500MeV, index, this ),
        tgap3f( parent.tgap3f, index, this ),
        trackWIDTH_allpv_1GeV( parent.trackWIDTH_allpv_1GeV, index, this ),
        trackWIDTH_pv0_1GeV( parent.trackWIDTH_pv0_1GeV, index, this ),
        weightconst_default( parent.weightconst_default, index, this ),
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
   JetD3PDObjectElement::JetD3PDObjectElement( const JetD3PDObjectElement& parent )
      : TObject( parent ),
        ActiveArea( parent.ActiveArea ),
        ActiveAreaE( parent.ActiveAreaE ),
        ActiveAreaPx( parent.ActiveAreaPx ),
        ActiveAreaPy( parent.ActiveAreaPy ),
        ActiveAreaPz( parent.ActiveAreaPz ),
        AverageLArQF( parent.AverageLArQF ),
        BAD_CELLS_CORR_E( parent.BAD_CELLS_CORR_E ),
        BCH_CORR_CELL( parent.BCH_CORR_CELL ),
        BCH_CORR_DOTX( parent.BCH_CORR_DOTX ),
        BCH_CORR_JET( parent.BCH_CORR_JET ),
        BCH_CORR_JET_FORCELL( parent.BCH_CORR_JET_FORCELL ),
        E( parent.E ),
        EF_dr( parent.EF_dr ),
        EF_matched( parent.EF_matched ),
        EMJES( parent.EMJES ),
        EMJES_EtaCorr( parent.EMJES_EtaCorr ),
        EMJESnooffset( parent.EMJESnooffset ),
        ENG_BAD_CELLS( parent.ENG_BAD_CELLS ),
        EtaOrigin( parent.EtaOrigin ),
        GSCFactorF( parent.GSCFactorF ),
        HECQuality( parent.HECQuality ),
        L1_dr( parent.L1_dr ),
        L1_matched( parent.L1_matched ),
        L2_dr( parent.L2_dr ),
        L2_matched( parent.L2_matched ),
        LArQuality( parent.LArQuality ),
        LCJES( parent.LCJES ),
        LCJES_EtaCorr( parent.LCJES_EtaCorr ),
        MOrigin( parent.MOrigin ),
        N_BAD_CELLS( parent.N_BAD_CELLS ),
        N_BAD_CELLS_CORR( parent.N_BAD_CELLS_CORR ),
        Nconst( parent.Nconst ),
        NegativeE( parent.NegativeE ),
        NumTowers( parent.NumTowers ),
        Offset( parent.Offset ),
        OriginIndex( parent.OriginIndex ),
        PhiOrigin( parent.PhiOrigin ),
        SamplingMax( parent.SamplingMax ),
        Timing( parent.Timing ),
        TruthMF( parent.TruthMF ),
        TruthMFindex( parent.TruthMFindex ),
        WIDTH( parent.WIDTH ),
        WidthFraction( parent.WidthFraction ),
        constscale_E( parent.constscale_E ),
        constscale_eta( parent.constscale_eta ),
        constscale_m( parent.constscale_m ),
        constscale_phi( parent.constscale_phi ),
        constscale_pt( parent.constscale_pt ),
        e_EMB1( parent.e_EMB1 ),
        e_EMB2( parent.e_EMB2 ),
        e_EMB3( parent.e_EMB3 ),
        e_EME1( parent.e_EME1 ),
        e_EME2( parent.e_EME2 ),
        e_EME3( parent.e_EME3 ),
        e_FCAL0( parent.e_FCAL0 ),
        e_FCAL1( parent.e_FCAL1 ),
        e_FCAL2( parent.e_FCAL2 ),
        e_HEC0( parent.e_HEC0 ),
        e_HEC1( parent.e_HEC1 ),
        e_HEC2( parent.e_HEC2 ),
        e_HEC3( parent.e_HEC3 ),
        e_PreSamplerB( parent.e_PreSamplerB ),
        e_PreSamplerE( parent.e_PreSamplerE ),
        e_TileBar0( parent.e_TileBar0 ),
        e_TileBar1( parent.e_TileBar1 ),
        e_TileBar2( parent.e_TileBar2 ),
        e_TileExt0( parent.e_TileExt0 ),
        e_TileExt1( parent.e_TileExt1 ),
        e_TileExt2( parent.e_TileExt2 ),
        e_TileGap1( parent.e_TileGap1 ),
        e_TileGap2( parent.e_TileGap2 ),
        e_TileGap3( parent.e_TileGap3 ),
        econst_default( parent.econst_default ),
        el_dr( parent.el_dr ),
        el_matched( parent.el_matched ),
        emfrac( parent.emfrac ),
        emscale_E( parent.emscale_E ),
        emscale_eta( parent.emscale_eta ),
        emscale_m( parent.emscale_m ),
        emscale_phi( parent.emscale_phi ),
        emscale_pt( parent.emscale_pt ),
        eta( parent.eta ),
        etaconst_default( parent.etaconst_default ),
        flavor_component_jfitc_doublePropName( parent.flavor_component_jfitc_doublePropName ),
        flavor_component_jfitc_doublePropValue( parent.flavor_component_jfitc_doublePropValue ),
        flavor_component_jfitc_intPropName( parent.flavor_component_jfitc_intPropName ),
        flavor_component_jfitc_intPropValue( parent.flavor_component_jfitc_intPropValue ),
        flavor_component_jfitc_isValid( parent.flavor_component_jfitc_isValid ),
        flavor_component_jfitc_pb( parent.flavor_component_jfitc_pb ),
        flavor_component_jfitc_pc( parent.flavor_component_jfitc_pc ),
        flavor_component_jfitc_pu( parent.flavor_component_jfitc_pu ),
        flavor_truth_BHadronpdg( parent.flavor_truth_BHadronpdg ),
        flavor_truth_dRminToB( parent.flavor_truth_dRminToB ),
        flavor_truth_dRminToC( parent.flavor_truth_dRminToC ),
        flavor_truth_dRminToT( parent.flavor_truth_dRminToT ),
        flavor_truth_label( parent.flavor_truth_label ),
        flavor_truth_vx_x( parent.flavor_truth_vx_x ),
        flavor_truth_vx_y( parent.flavor_truth_vx_y ),
        flavor_truth_vx_z( parent.flavor_truth_vx_z ),
        flavor_weight_Comb( parent.flavor_weight_Comb ),
        flavor_weight_GbbNN( parent.flavor_weight_GbbNN ),
        flavor_weight_IP2D( parent.flavor_weight_IP2D ),
        flavor_weight_IP3D( parent.flavor_weight_IP3D ),
        flavor_weight_JetFitterCOMBNN( parent.flavor_weight_JetFitterCOMBNN ),
        flavor_weight_JetFitterCharm( parent.flavor_weight_JetFitterCharm ),
        flavor_weight_JetFitterTagNN( parent.flavor_weight_JetFitterTagNN ),
        flavor_weight_MV1( parent.flavor_weight_MV1 ),
        flavor_weight_MV2( parent.flavor_weight_MV2 ),
        flavor_weight_MV3_bVSc( parent.flavor_weight_MV3_bVSc ),
        flavor_weight_MV3_bVSu( parent.flavor_weight_MV3_bVSu ),
        flavor_weight_MV3_cVSu( parent.flavor_weight_MV3_cVSu ),
        flavor_weight_SV0( parent.flavor_weight_SV0 ),
        flavor_weight_SV1( parent.flavor_weight_SV1 ),
        flavor_weight_SV2( parent.flavor_weight_SV2 ),
        flavor_weight_SecondSoftMuonTagChi2( parent.flavor_weight_SecondSoftMuonTagChi2 ),
        flavor_weight_SoftMuonTagChi2( parent.flavor_weight_SoftMuonTagChi2 ),
        fracSamplingMax( parent.fracSamplingMax ),
        hecf( parent.hecf ),
        isBadLoose( parent.isBadLoose ),
        isBadLooseMinus( parent.isBadLooseMinus ),
        isBadMedium( parent.isBadMedium ),
        isBadTight( parent.isBadTight ),
        isUgly( parent.isUgly ),
        jvtx_x( parent.jvtx_x ),
        jvtx_y( parent.jvtx_y ),
        jvtx_z( parent.jvtx_z ),
        jvtxf( parent.jvtxf ),
        jvtxfFull( parent.jvtxfFull ),
        m( parent.m ),
        mu_dr( parent.mu_dr ),
        mu_matched( parent.mu_matched ),
        n90( parent.n90 ),
        nTrk( parent.nTrk ),
        nTrk_allpv_1GeV( parent.nTrk_allpv_1GeV ),
        nTrk_pv0_1GeV( parent.nTrk_pv0_1GeV ),
        nTrk_pv0_500MeV( parent.nTrk_pv0_500MeV ),
        ootFracCells10( parent.ootFracCells10 ),
        ootFracCells5( parent.ootFracCells5 ),
        ootFracClusters10( parent.ootFracClusters10 ),
        ootFracClusters5( parent.ootFracClusters5 ),
        phi( parent.phi ),
        phiconst_default( parent.phiconst_default ),
        pt( parent.pt ),
        ptconst_default( parent.ptconst_default ),
        sumPtTrk( parent.sumPtTrk ),
        sumPtTrk_allpv_1GeV( parent.sumPtTrk_allpv_1GeV ),
        sumPtTrk_pv0_1GeV( parent.sumPtTrk_pv0_1GeV ),
        sumPtTrk_pv0_500MeV( parent.sumPtTrk_pv0_500MeV ),
        tgap3f( parent.tgap3f ),
        trackWIDTH_allpv_1GeV( parent.trackWIDTH_allpv_1GeV ),
        trackWIDTH_pv0_1GeV( parent.trackWIDTH_pv0_1GeV ),
        weightconst_default( parent.weightconst_default ),
        fParent( parent.fParent ), fIndex( parent.fIndex ) {

   }

   /**
    * This function can be used to access the parent object of this
    * proxy object. It can come in handy when optimizing an analysis code.
    *
    * @returns A reference to this object's parent
    */
   const JetD3PDObject* JetD3PDObjectElement::GetParent() const {

      return fParent;
   }

   /**
    * This function can be used to access the index of this proxy object
    * inside the parent container. It can come in handy when optimizing an
    * analysis code.
    *
    * @returns The index of the proxy in the object's parent
    */
   size_t JetD3PDObjectElement::GetIndex() const {

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
   JetD3PDObject::JetD3PDObject( const ::Long64_t& master, const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "ActiveArea" ] = &ActiveArea;
      fHandles[ "ActiveAreaE" ] = &ActiveAreaE;
      fHandles[ "ActiveAreaPx" ] = &ActiveAreaPx;
      fHandles[ "ActiveAreaPy" ] = &ActiveAreaPy;
      fHandles[ "ActiveAreaPz" ] = &ActiveAreaPz;
      fHandles[ "AverageLArQF" ] = &AverageLArQF;
      fHandles[ "BAD_CELLS_CORR_E" ] = &BAD_CELLS_CORR_E;
      fHandles[ "BCH_CORR_CELL" ] = &BCH_CORR_CELL;
      fHandles[ "BCH_CORR_DOTX" ] = &BCH_CORR_DOTX;
      fHandles[ "BCH_CORR_JET" ] = &BCH_CORR_JET;
      fHandles[ "BCH_CORR_JET_FORCELL" ] = &BCH_CORR_JET_FORCELL;
      fHandles[ "E" ] = &E;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_matched" ] = &EF_matched;
      fHandles[ "EMJES" ] = &EMJES;
      fHandles[ "EMJES_EtaCorr" ] = &EMJES_EtaCorr;
      fHandles[ "EMJESnooffset" ] = &EMJESnooffset;
      fHandles[ "ENG_BAD_CELLS" ] = &ENG_BAD_CELLS;
      fHandles[ "EtaOrigin" ] = &EtaOrigin;
      fHandles[ "GSCFactorF" ] = &GSCFactorF;
      fHandles[ "HECQuality" ] = &HECQuality;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_matched" ] = &L1_matched;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_matched" ] = &L2_matched;
      fHandles[ "LArQuality" ] = &LArQuality;
      fHandles[ "LCJES" ] = &LCJES;
      fHandles[ "LCJES_EtaCorr" ] = &LCJES_EtaCorr;
      fHandles[ "MOrigin" ] = &MOrigin;
      fHandles[ "N_BAD_CELLS" ] = &N_BAD_CELLS;
      fHandles[ "N_BAD_CELLS_CORR" ] = &N_BAD_CELLS_CORR;
      fHandles[ "Nconst" ] = &Nconst;
      fHandles[ "NegativeE" ] = &NegativeE;
      fHandles[ "NumTowers" ] = &NumTowers;
      fHandles[ "Offset" ] = &Offset;
      fHandles[ "OriginIndex" ] = &OriginIndex;
      fHandles[ "PhiOrigin" ] = &PhiOrigin;
      fHandles[ "SamplingMax" ] = &SamplingMax;
      fHandles[ "Timing" ] = &Timing;
      fHandles[ "TruthMF" ] = &TruthMF;
      fHandles[ "TruthMFindex" ] = &TruthMFindex;
      fHandles[ "WIDTH" ] = &WIDTH;
      fHandles[ "WidthFraction" ] = &WidthFraction;
      fHandles[ "constscale_E" ] = &constscale_E;
      fHandles[ "constscale_eta" ] = &constscale_eta;
      fHandles[ "constscale_m" ] = &constscale_m;
      fHandles[ "constscale_phi" ] = &constscale_phi;
      fHandles[ "constscale_pt" ] = &constscale_pt;
      fHandles[ "e_EMB1" ] = &e_EMB1;
      fHandles[ "e_EMB2" ] = &e_EMB2;
      fHandles[ "e_EMB3" ] = &e_EMB3;
      fHandles[ "e_EME1" ] = &e_EME1;
      fHandles[ "e_EME2" ] = &e_EME2;
      fHandles[ "e_EME3" ] = &e_EME3;
      fHandles[ "e_FCAL0" ] = &e_FCAL0;
      fHandles[ "e_FCAL1" ] = &e_FCAL1;
      fHandles[ "e_FCAL2" ] = &e_FCAL2;
      fHandles[ "e_HEC0" ] = &e_HEC0;
      fHandles[ "e_HEC1" ] = &e_HEC1;
      fHandles[ "e_HEC2" ] = &e_HEC2;
      fHandles[ "e_HEC3" ] = &e_HEC3;
      fHandles[ "e_PreSamplerB" ] = &e_PreSamplerB;
      fHandles[ "e_PreSamplerE" ] = &e_PreSamplerE;
      fHandles[ "e_TileBar0" ] = &e_TileBar0;
      fHandles[ "e_TileBar1" ] = &e_TileBar1;
      fHandles[ "e_TileBar2" ] = &e_TileBar2;
      fHandles[ "e_TileExt0" ] = &e_TileExt0;
      fHandles[ "e_TileExt1" ] = &e_TileExt1;
      fHandles[ "e_TileExt2" ] = &e_TileExt2;
      fHandles[ "e_TileGap1" ] = &e_TileGap1;
      fHandles[ "e_TileGap2" ] = &e_TileGap2;
      fHandles[ "e_TileGap3" ] = &e_TileGap3;
      fHandles[ "econst_default" ] = &econst_default;
      fHandles[ "el_dr" ] = &el_dr;
      fHandles[ "el_matched" ] = &el_matched;
      fHandles[ "emfrac" ] = &emfrac;
      fHandles[ "emscale_E" ] = &emscale_E;
      fHandles[ "emscale_eta" ] = &emscale_eta;
      fHandles[ "emscale_m" ] = &emscale_m;
      fHandles[ "emscale_phi" ] = &emscale_phi;
      fHandles[ "emscale_pt" ] = &emscale_pt;
      fHandles[ "eta" ] = &eta;
      fHandles[ "etaconst_default" ] = &etaconst_default;
      fHandles[ "flavor_component_jfitc_doublePropName" ] = &flavor_component_jfitc_doublePropName;
      fHandles[ "flavor_component_jfitc_doublePropValue" ] = &flavor_component_jfitc_doublePropValue;
      fHandles[ "flavor_component_jfitc_intPropName" ] = &flavor_component_jfitc_intPropName;
      fHandles[ "flavor_component_jfitc_intPropValue" ] = &flavor_component_jfitc_intPropValue;
      fHandles[ "flavor_component_jfitc_isValid" ] = &flavor_component_jfitc_isValid;
      fHandles[ "flavor_component_jfitc_pb" ] = &flavor_component_jfitc_pb;
      fHandles[ "flavor_component_jfitc_pc" ] = &flavor_component_jfitc_pc;
      fHandles[ "flavor_component_jfitc_pu" ] = &flavor_component_jfitc_pu;
      fHandles[ "flavor_truth_BHadronpdg" ] = &flavor_truth_BHadronpdg;
      fHandles[ "flavor_truth_dRminToB" ] = &flavor_truth_dRminToB;
      fHandles[ "flavor_truth_dRminToC" ] = &flavor_truth_dRminToC;
      fHandles[ "flavor_truth_dRminToT" ] = &flavor_truth_dRminToT;
      fHandles[ "flavor_truth_label" ] = &flavor_truth_label;
      fHandles[ "flavor_truth_vx_x" ] = &flavor_truth_vx_x;
      fHandles[ "flavor_truth_vx_y" ] = &flavor_truth_vx_y;
      fHandles[ "flavor_truth_vx_z" ] = &flavor_truth_vx_z;
      fHandles[ "flavor_weight_Comb" ] = &flavor_weight_Comb;
      fHandles[ "flavor_weight_GbbNN" ] = &flavor_weight_GbbNN;
      fHandles[ "flavor_weight_IP2D" ] = &flavor_weight_IP2D;
      fHandles[ "flavor_weight_IP3D" ] = &flavor_weight_IP3D;
      fHandles[ "flavor_weight_JetFitterCOMBNN" ] = &flavor_weight_JetFitterCOMBNN;
      fHandles[ "flavor_weight_JetFitterCharm" ] = &flavor_weight_JetFitterCharm;
      fHandles[ "flavor_weight_JetFitterTagNN" ] = &flavor_weight_JetFitterTagNN;
      fHandles[ "flavor_weight_MV1" ] = &flavor_weight_MV1;
      fHandles[ "flavor_weight_MV2" ] = &flavor_weight_MV2;
      fHandles[ "flavor_weight_MV3_bVSc" ] = &flavor_weight_MV3_bVSc;
      fHandles[ "flavor_weight_MV3_bVSu" ] = &flavor_weight_MV3_bVSu;
      fHandles[ "flavor_weight_MV3_cVSu" ] = &flavor_weight_MV3_cVSu;
      fHandles[ "flavor_weight_SV0" ] = &flavor_weight_SV0;
      fHandles[ "flavor_weight_SV1" ] = &flavor_weight_SV1;
      fHandles[ "flavor_weight_SV2" ] = &flavor_weight_SV2;
      fHandles[ "flavor_weight_SecondSoftMuonTagChi2" ] = &flavor_weight_SecondSoftMuonTagChi2;
      fHandles[ "flavor_weight_SoftMuonTagChi2" ] = &flavor_weight_SoftMuonTagChi2;
      fHandles[ "fracSamplingMax" ] = &fracSamplingMax;
      fHandles[ "hecf" ] = &hecf;
      fHandles[ "isBadLoose" ] = &isBadLoose;
      fHandles[ "isBadLooseMinus" ] = &isBadLooseMinus;
      fHandles[ "isBadMedium" ] = &isBadMedium;
      fHandles[ "isBadTight" ] = &isBadTight;
      fHandles[ "isUgly" ] = &isUgly;
      fHandles[ "jvtx_x" ] = &jvtx_x;
      fHandles[ "jvtx_y" ] = &jvtx_y;
      fHandles[ "jvtx_z" ] = &jvtx_z;
      fHandles[ "jvtxf" ] = &jvtxf;
      fHandles[ "jvtxfFull" ] = &jvtxfFull;
      fHandles[ "m" ] = &m;
      fHandles[ "mu_dr" ] = &mu_dr;
      fHandles[ "mu_matched" ] = &mu_matched;
      fHandles[ "n" ] = &n;
      fHandles[ "n90" ] = &n90;
      fHandles[ "nTrk" ] = &nTrk;
      fHandles[ "nTrk_allpv_1GeV" ] = &nTrk_allpv_1GeV;
      fHandles[ "nTrk_pv0_1GeV" ] = &nTrk_pv0_1GeV;
      fHandles[ "nTrk_pv0_500MeV" ] = &nTrk_pv0_500MeV;
      fHandles[ "ootFracCells10" ] = &ootFracCells10;
      fHandles[ "ootFracCells5" ] = &ootFracCells5;
      fHandles[ "ootFracClusters10" ] = &ootFracClusters10;
      fHandles[ "ootFracClusters5" ] = &ootFracClusters5;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phiconst_default" ] = &phiconst_default;
      fHandles[ "pt" ] = &pt;
      fHandles[ "ptconst_default" ] = &ptconst_default;
      fHandles[ "sumPtTrk" ] = &sumPtTrk;
      fHandles[ "sumPtTrk_allpv_1GeV" ] = &sumPtTrk_allpv_1GeV;
      fHandles[ "sumPtTrk_pv0_1GeV" ] = &sumPtTrk_pv0_1GeV;
      fHandles[ "sumPtTrk_pv0_500MeV" ] = &sumPtTrk_pv0_500MeV;
      fHandles[ "tgap3f" ] = &tgap3f;
      fHandles[ "trackWIDTH_allpv_1GeV" ] = &trackWIDTH_allpv_1GeV;
      fHandles[ "trackWIDTH_pv0_1GeV" ] = &trackWIDTH_pv0_1GeV;
      fHandles[ "weightconst_default" ] = &weightconst_default;

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
   JetD3PDObject::JetD3PDObject( const char* prefix )
      : D3PDObjectBase(),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "ActiveArea" ] = &ActiveArea;
      fHandles[ "ActiveAreaE" ] = &ActiveAreaE;
      fHandles[ "ActiveAreaPx" ] = &ActiveAreaPx;
      fHandles[ "ActiveAreaPy" ] = &ActiveAreaPy;
      fHandles[ "ActiveAreaPz" ] = &ActiveAreaPz;
      fHandles[ "AverageLArQF" ] = &AverageLArQF;
      fHandles[ "BAD_CELLS_CORR_E" ] = &BAD_CELLS_CORR_E;
      fHandles[ "BCH_CORR_CELL" ] = &BCH_CORR_CELL;
      fHandles[ "BCH_CORR_DOTX" ] = &BCH_CORR_DOTX;
      fHandles[ "BCH_CORR_JET" ] = &BCH_CORR_JET;
      fHandles[ "BCH_CORR_JET_FORCELL" ] = &BCH_CORR_JET_FORCELL;
      fHandles[ "E" ] = &E;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_matched" ] = &EF_matched;
      fHandles[ "EMJES" ] = &EMJES;
      fHandles[ "EMJES_EtaCorr" ] = &EMJES_EtaCorr;
      fHandles[ "EMJESnooffset" ] = &EMJESnooffset;
      fHandles[ "ENG_BAD_CELLS" ] = &ENG_BAD_CELLS;
      fHandles[ "EtaOrigin" ] = &EtaOrigin;
      fHandles[ "GSCFactorF" ] = &GSCFactorF;
      fHandles[ "HECQuality" ] = &HECQuality;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_matched" ] = &L1_matched;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_matched" ] = &L2_matched;
      fHandles[ "LArQuality" ] = &LArQuality;
      fHandles[ "LCJES" ] = &LCJES;
      fHandles[ "LCJES_EtaCorr" ] = &LCJES_EtaCorr;
      fHandles[ "MOrigin" ] = &MOrigin;
      fHandles[ "N_BAD_CELLS" ] = &N_BAD_CELLS;
      fHandles[ "N_BAD_CELLS_CORR" ] = &N_BAD_CELLS_CORR;
      fHandles[ "Nconst" ] = &Nconst;
      fHandles[ "NegativeE" ] = &NegativeE;
      fHandles[ "NumTowers" ] = &NumTowers;
      fHandles[ "Offset" ] = &Offset;
      fHandles[ "OriginIndex" ] = &OriginIndex;
      fHandles[ "PhiOrigin" ] = &PhiOrigin;
      fHandles[ "SamplingMax" ] = &SamplingMax;
      fHandles[ "Timing" ] = &Timing;
      fHandles[ "TruthMF" ] = &TruthMF;
      fHandles[ "TruthMFindex" ] = &TruthMFindex;
      fHandles[ "WIDTH" ] = &WIDTH;
      fHandles[ "WidthFraction" ] = &WidthFraction;
      fHandles[ "constscale_E" ] = &constscale_E;
      fHandles[ "constscale_eta" ] = &constscale_eta;
      fHandles[ "constscale_m" ] = &constscale_m;
      fHandles[ "constscale_phi" ] = &constscale_phi;
      fHandles[ "constscale_pt" ] = &constscale_pt;
      fHandles[ "e_EMB1" ] = &e_EMB1;
      fHandles[ "e_EMB2" ] = &e_EMB2;
      fHandles[ "e_EMB3" ] = &e_EMB3;
      fHandles[ "e_EME1" ] = &e_EME1;
      fHandles[ "e_EME2" ] = &e_EME2;
      fHandles[ "e_EME3" ] = &e_EME3;
      fHandles[ "e_FCAL0" ] = &e_FCAL0;
      fHandles[ "e_FCAL1" ] = &e_FCAL1;
      fHandles[ "e_FCAL2" ] = &e_FCAL2;
      fHandles[ "e_HEC0" ] = &e_HEC0;
      fHandles[ "e_HEC1" ] = &e_HEC1;
      fHandles[ "e_HEC2" ] = &e_HEC2;
      fHandles[ "e_HEC3" ] = &e_HEC3;
      fHandles[ "e_PreSamplerB" ] = &e_PreSamplerB;
      fHandles[ "e_PreSamplerE" ] = &e_PreSamplerE;
      fHandles[ "e_TileBar0" ] = &e_TileBar0;
      fHandles[ "e_TileBar1" ] = &e_TileBar1;
      fHandles[ "e_TileBar2" ] = &e_TileBar2;
      fHandles[ "e_TileExt0" ] = &e_TileExt0;
      fHandles[ "e_TileExt1" ] = &e_TileExt1;
      fHandles[ "e_TileExt2" ] = &e_TileExt2;
      fHandles[ "e_TileGap1" ] = &e_TileGap1;
      fHandles[ "e_TileGap2" ] = &e_TileGap2;
      fHandles[ "e_TileGap3" ] = &e_TileGap3;
      fHandles[ "econst_default" ] = &econst_default;
      fHandles[ "el_dr" ] = &el_dr;
      fHandles[ "el_matched" ] = &el_matched;
      fHandles[ "emfrac" ] = &emfrac;
      fHandles[ "emscale_E" ] = &emscale_E;
      fHandles[ "emscale_eta" ] = &emscale_eta;
      fHandles[ "emscale_m" ] = &emscale_m;
      fHandles[ "emscale_phi" ] = &emscale_phi;
      fHandles[ "emscale_pt" ] = &emscale_pt;
      fHandles[ "eta" ] = &eta;
      fHandles[ "etaconst_default" ] = &etaconst_default;
      fHandles[ "flavor_component_jfitc_doublePropName" ] = &flavor_component_jfitc_doublePropName;
      fHandles[ "flavor_component_jfitc_doublePropValue" ] = &flavor_component_jfitc_doublePropValue;
      fHandles[ "flavor_component_jfitc_intPropName" ] = &flavor_component_jfitc_intPropName;
      fHandles[ "flavor_component_jfitc_intPropValue" ] = &flavor_component_jfitc_intPropValue;
      fHandles[ "flavor_component_jfitc_isValid" ] = &flavor_component_jfitc_isValid;
      fHandles[ "flavor_component_jfitc_pb" ] = &flavor_component_jfitc_pb;
      fHandles[ "flavor_component_jfitc_pc" ] = &flavor_component_jfitc_pc;
      fHandles[ "flavor_component_jfitc_pu" ] = &flavor_component_jfitc_pu;
      fHandles[ "flavor_truth_BHadronpdg" ] = &flavor_truth_BHadronpdg;
      fHandles[ "flavor_truth_dRminToB" ] = &flavor_truth_dRminToB;
      fHandles[ "flavor_truth_dRminToC" ] = &flavor_truth_dRminToC;
      fHandles[ "flavor_truth_dRminToT" ] = &flavor_truth_dRminToT;
      fHandles[ "flavor_truth_label" ] = &flavor_truth_label;
      fHandles[ "flavor_truth_vx_x" ] = &flavor_truth_vx_x;
      fHandles[ "flavor_truth_vx_y" ] = &flavor_truth_vx_y;
      fHandles[ "flavor_truth_vx_z" ] = &flavor_truth_vx_z;
      fHandles[ "flavor_weight_Comb" ] = &flavor_weight_Comb;
      fHandles[ "flavor_weight_GbbNN" ] = &flavor_weight_GbbNN;
      fHandles[ "flavor_weight_IP2D" ] = &flavor_weight_IP2D;
      fHandles[ "flavor_weight_IP3D" ] = &flavor_weight_IP3D;
      fHandles[ "flavor_weight_JetFitterCOMBNN" ] = &flavor_weight_JetFitterCOMBNN;
      fHandles[ "flavor_weight_JetFitterCharm" ] = &flavor_weight_JetFitterCharm;
      fHandles[ "flavor_weight_JetFitterTagNN" ] = &flavor_weight_JetFitterTagNN;
      fHandles[ "flavor_weight_MV1" ] = &flavor_weight_MV1;
      fHandles[ "flavor_weight_MV2" ] = &flavor_weight_MV2;
      fHandles[ "flavor_weight_MV3_bVSc" ] = &flavor_weight_MV3_bVSc;
      fHandles[ "flavor_weight_MV3_bVSu" ] = &flavor_weight_MV3_bVSu;
      fHandles[ "flavor_weight_MV3_cVSu" ] = &flavor_weight_MV3_cVSu;
      fHandles[ "flavor_weight_SV0" ] = &flavor_weight_SV0;
      fHandles[ "flavor_weight_SV1" ] = &flavor_weight_SV1;
      fHandles[ "flavor_weight_SV2" ] = &flavor_weight_SV2;
      fHandles[ "flavor_weight_SecondSoftMuonTagChi2" ] = &flavor_weight_SecondSoftMuonTagChi2;
      fHandles[ "flavor_weight_SoftMuonTagChi2" ] = &flavor_weight_SoftMuonTagChi2;
      fHandles[ "fracSamplingMax" ] = &fracSamplingMax;
      fHandles[ "hecf" ] = &hecf;
      fHandles[ "isBadLoose" ] = &isBadLoose;
      fHandles[ "isBadLooseMinus" ] = &isBadLooseMinus;
      fHandles[ "isBadMedium" ] = &isBadMedium;
      fHandles[ "isBadTight" ] = &isBadTight;
      fHandles[ "isUgly" ] = &isUgly;
      fHandles[ "jvtx_x" ] = &jvtx_x;
      fHandles[ "jvtx_y" ] = &jvtx_y;
      fHandles[ "jvtx_z" ] = &jvtx_z;
      fHandles[ "jvtxf" ] = &jvtxf;
      fHandles[ "jvtxfFull" ] = &jvtxfFull;
      fHandles[ "m" ] = &m;
      fHandles[ "mu_dr" ] = &mu_dr;
      fHandles[ "mu_matched" ] = &mu_matched;
      fHandles[ "n" ] = &n;
      fHandles[ "n90" ] = &n90;
      fHandles[ "nTrk" ] = &nTrk;
      fHandles[ "nTrk_allpv_1GeV" ] = &nTrk_allpv_1GeV;
      fHandles[ "nTrk_pv0_1GeV" ] = &nTrk_pv0_1GeV;
      fHandles[ "nTrk_pv0_500MeV" ] = &nTrk_pv0_500MeV;
      fHandles[ "ootFracCells10" ] = &ootFracCells10;
      fHandles[ "ootFracCells5" ] = &ootFracCells5;
      fHandles[ "ootFracClusters10" ] = &ootFracClusters10;
      fHandles[ "ootFracClusters5" ] = &ootFracClusters5;
      fHandles[ "phi" ] = &phi;
      fHandles[ "phiconst_default" ] = &phiconst_default;
      fHandles[ "pt" ] = &pt;
      fHandles[ "ptconst_default" ] = &ptconst_default;
      fHandles[ "sumPtTrk" ] = &sumPtTrk;
      fHandles[ "sumPtTrk_allpv_1GeV" ] = &sumPtTrk_allpv_1GeV;
      fHandles[ "sumPtTrk_pv0_1GeV" ] = &sumPtTrk_pv0_1GeV;
      fHandles[ "sumPtTrk_pv0_500MeV" ] = &sumPtTrk_pv0_500MeV;
      fHandles[ "tgap3f" ] = &tgap3f;
      fHandles[ "trackWIDTH_allpv_1GeV" ] = &trackWIDTH_allpv_1GeV;
      fHandles[ "trackWIDTH_pv0_1GeV" ] = &trackWIDTH_pv0_1GeV;
      fHandles[ "weightconst_default" ] = &weightconst_default;

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
   JetD3PDObject::~JetD3PDObject() {

      for( size_t i = 0; i < fProxies.size(); ++i ) {
         delete fProxies[ i ];
      }
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* JetD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void JetD3PDObject::SetPrefix( const char* prefix ) {

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
   void JetD3PDObject::ReadFrom( TTree* tree ) {

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
   void JetD3PDObject::WriteTo( TTree* tree ) {

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
   void JetD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void JetD3PDObject::ReadAllActive() {

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

   D3PDReadStats JetD3PDObject::GetStatistics() const {

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
    * This function makes it easier to clear out the object completely.
    * It cleares all the vector variables, and sets the element number
    * variable to 0. Very useful when performing object selection.
    * The option argument is not used at the moment for anything.
    * It's only there because the <code>Clear</code> function defined in
    * TObject has this parameter as well.
    *
    * @param option Ignored at the moment
    */
   void JetD3PDObject::Clear( Option_t* ) {

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
   JetD3PDObject& JetD3PDObject::Add( const JetD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( el.ActiveArea.IsAvailable() ) {
         ActiveArea()->push_back( el.ActiveArea() );
      } else {
         ActiveArea()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ActiveAreaE.IsAvailable() ) {
         ActiveAreaE()->push_back( el.ActiveAreaE() );
      } else {
         ActiveAreaE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ActiveAreaPx.IsAvailable() ) {
         ActiveAreaPx()->push_back( el.ActiveAreaPx() );
      } else {
         ActiveAreaPx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ActiveAreaPy.IsAvailable() ) {
         ActiveAreaPy()->push_back( el.ActiveAreaPy() );
      } else {
         ActiveAreaPy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ActiveAreaPz.IsAvailable() ) {
         ActiveAreaPz()->push_back( el.ActiveAreaPz() );
      } else {
         ActiveAreaPz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.AverageLArQF.IsAvailable() ) {
         AverageLArQF()->push_back( el.AverageLArQF() );
      } else {
         AverageLArQF()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BAD_CELLS_CORR_E.IsAvailable() ) {
         BAD_CELLS_CORR_E()->push_back( el.BAD_CELLS_CORR_E() );
      } else {
         BAD_CELLS_CORR_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BCH_CORR_CELL.IsAvailable() ) {
         BCH_CORR_CELL()->push_back( el.BCH_CORR_CELL() );
      } else {
         BCH_CORR_CELL()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BCH_CORR_DOTX.IsAvailable() ) {
         BCH_CORR_DOTX()->push_back( el.BCH_CORR_DOTX() );
      } else {
         BCH_CORR_DOTX()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BCH_CORR_JET.IsAvailable() ) {
         BCH_CORR_JET()->push_back( el.BCH_CORR_JET() );
      } else {
         BCH_CORR_JET()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BCH_CORR_JET_FORCELL.IsAvailable() ) {
         BCH_CORR_JET_FORCELL()->push_back( el.BCH_CORR_JET_FORCELL() );
      } else {
         BCH_CORR_JET_FORCELL()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E.IsAvailable() ) {
         E()->push_back( el.E() );
      } else {
         E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_dr.IsAvailable() ) {
         EF_dr()->push_back( el.EF_dr() );
      } else {
         EF_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_matched.IsAvailable() ) {
         EF_matched()->push_back( el.EF_matched() );
      } else {
         EF_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EMJES.IsAvailable() ) {
         EMJES()->push_back( el.EMJES() );
      } else {
         EMJES()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EMJES_EtaCorr.IsAvailable() ) {
         EMJES_EtaCorr()->push_back( el.EMJES_EtaCorr() );
      } else {
         EMJES_EtaCorr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EMJESnooffset.IsAvailable() ) {
         EMJESnooffset()->push_back( el.EMJESnooffset() );
      } else {
         EMJESnooffset()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ENG_BAD_CELLS.IsAvailable() ) {
         ENG_BAD_CELLS()->push_back( el.ENG_BAD_CELLS() );
      } else {
         ENG_BAD_CELLS()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EtaOrigin.IsAvailable() ) {
         EtaOrigin()->push_back( el.EtaOrigin() );
      } else {
         EtaOrigin()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.GSCFactorF.IsAvailable() ) {
         GSCFactorF()->push_back( el.GSCFactorF() );
      } else {
         GSCFactorF()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.HECQuality.IsAvailable() ) {
         HECQuality()->push_back( el.HECQuality() );
      } else {
         HECQuality()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_dr.IsAvailable() ) {
         L1_dr()->push_back( el.L1_dr() );
      } else {
         L1_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_matched.IsAvailable() ) {
         L1_matched()->push_back( el.L1_matched() );
      } else {
         L1_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L2_dr.IsAvailable() ) {
         L2_dr()->push_back( el.L2_dr() );
      } else {
         L2_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_matched.IsAvailable() ) {
         L2_matched()->push_back( el.L2_matched() );
      } else {
         L2_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.LArQuality.IsAvailable() ) {
         LArQuality()->push_back( el.LArQuality() );
      } else {
         LArQuality()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.LCJES.IsAvailable() ) {
         LCJES()->push_back( el.LCJES() );
      } else {
         LCJES()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.LCJES_EtaCorr.IsAvailable() ) {
         LCJES_EtaCorr()->push_back( el.LCJES_EtaCorr() );
      } else {
         LCJES_EtaCorr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.MOrigin.IsAvailable() ) {
         MOrigin()->push_back( el.MOrigin() );
      } else {
         MOrigin()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.N_BAD_CELLS.IsAvailable() ) {
         N_BAD_CELLS()->push_back( el.N_BAD_CELLS() );
      } else {
         N_BAD_CELLS()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.N_BAD_CELLS_CORR.IsAvailable() ) {
         N_BAD_CELLS_CORR()->push_back( el.N_BAD_CELLS_CORR() );
      } else {
         N_BAD_CELLS_CORR()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Nconst.IsAvailable() ) {
         Nconst()->push_back( el.Nconst() );
      } else {
         Nconst()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.NegativeE.IsAvailable() ) {
         NegativeE()->push_back( el.NegativeE() );
      } else {
         NegativeE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.NumTowers.IsAvailable() ) {
         NumTowers()->push_back( el.NumTowers() );
      } else {
         NumTowers()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Offset.IsAvailable() ) {
         Offset()->push_back( el.Offset() );
      } else {
         Offset()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.OriginIndex.IsAvailable() ) {
         OriginIndex()->push_back( el.OriginIndex() );
      } else {
         OriginIndex()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.PhiOrigin.IsAvailable() ) {
         PhiOrigin()->push_back( el.PhiOrigin() );
      } else {
         PhiOrigin()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.SamplingMax.IsAvailable() ) {
         SamplingMax()->push_back( el.SamplingMax() );
      } else {
         SamplingMax()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.Timing.IsAvailable() ) {
         Timing()->push_back( el.Timing() );
      } else {
         Timing()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.TruthMF.IsAvailable() ) {
         TruthMF()->push_back( el.TruthMF() );
      } else {
         TruthMF()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.TruthMFindex.IsAvailable() ) {
         TruthMFindex()->push_back( el.TruthMFindex() );
      } else {
         TruthMFindex()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.WIDTH.IsAvailable() ) {
         WIDTH()->push_back( el.WIDTH() );
      } else {
         WIDTH()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.WidthFraction.IsAvailable() ) {
         WidthFraction()->push_back( el.WidthFraction() );
      } else {
         WidthFraction()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.constscale_E.IsAvailable() ) {
         constscale_E()->push_back( el.constscale_E() );
      } else {
         constscale_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.constscale_eta.IsAvailable() ) {
         constscale_eta()->push_back( el.constscale_eta() );
      } else {
         constscale_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.constscale_m.IsAvailable() ) {
         constscale_m()->push_back( el.constscale_m() );
      } else {
         constscale_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.constscale_phi.IsAvailable() ) {
         constscale_phi()->push_back( el.constscale_phi() );
      } else {
         constscale_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.constscale_pt.IsAvailable() ) {
         constscale_pt()->push_back( el.constscale_pt() );
      } else {
         constscale_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EMB1.IsAvailable() ) {
         e_EMB1()->push_back( el.e_EMB1() );
      } else {
         e_EMB1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EMB2.IsAvailable() ) {
         e_EMB2()->push_back( el.e_EMB2() );
      } else {
         e_EMB2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EMB3.IsAvailable() ) {
         e_EMB3()->push_back( el.e_EMB3() );
      } else {
         e_EMB3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EME1.IsAvailable() ) {
         e_EME1()->push_back( el.e_EME1() );
      } else {
         e_EME1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EME2.IsAvailable() ) {
         e_EME2()->push_back( el.e_EME2() );
      } else {
         e_EME2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EME3.IsAvailable() ) {
         e_EME3()->push_back( el.e_EME3() );
      } else {
         e_EME3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_FCAL0.IsAvailable() ) {
         e_FCAL0()->push_back( el.e_FCAL0() );
      } else {
         e_FCAL0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_FCAL1.IsAvailable() ) {
         e_FCAL1()->push_back( el.e_FCAL1() );
      } else {
         e_FCAL1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_FCAL2.IsAvailable() ) {
         e_FCAL2()->push_back( el.e_FCAL2() );
      } else {
         e_FCAL2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_HEC0.IsAvailable() ) {
         e_HEC0()->push_back( el.e_HEC0() );
      } else {
         e_HEC0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_HEC1.IsAvailable() ) {
         e_HEC1()->push_back( el.e_HEC1() );
      } else {
         e_HEC1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_HEC2.IsAvailable() ) {
         e_HEC2()->push_back( el.e_HEC2() );
      } else {
         e_HEC2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_HEC3.IsAvailable() ) {
         e_HEC3()->push_back( el.e_HEC3() );
      } else {
         e_HEC3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_PreSamplerB.IsAvailable() ) {
         e_PreSamplerB()->push_back( el.e_PreSamplerB() );
      } else {
         e_PreSamplerB()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_PreSamplerE.IsAvailable() ) {
         e_PreSamplerE()->push_back( el.e_PreSamplerE() );
      } else {
         e_PreSamplerE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileBar0.IsAvailable() ) {
         e_TileBar0()->push_back( el.e_TileBar0() );
      } else {
         e_TileBar0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileBar1.IsAvailable() ) {
         e_TileBar1()->push_back( el.e_TileBar1() );
      } else {
         e_TileBar1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileBar2.IsAvailable() ) {
         e_TileBar2()->push_back( el.e_TileBar2() );
      } else {
         e_TileBar2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileExt0.IsAvailable() ) {
         e_TileExt0()->push_back( el.e_TileExt0() );
      } else {
         e_TileExt0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileExt1.IsAvailable() ) {
         e_TileExt1()->push_back( el.e_TileExt1() );
      } else {
         e_TileExt1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileExt2.IsAvailable() ) {
         e_TileExt2()->push_back( el.e_TileExt2() );
      } else {
         e_TileExt2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileGap1.IsAvailable() ) {
         e_TileGap1()->push_back( el.e_TileGap1() );
      } else {
         e_TileGap1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileGap2.IsAvailable() ) {
         e_TileGap2()->push_back( el.e_TileGap2() );
      } else {
         e_TileGap2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileGap3.IsAvailable() ) {
         e_TileGap3()->push_back( el.e_TileGap3() );
      } else {
         e_TileGap3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.econst_default.IsAvailable() ) {
         econst_default()->push_back( el.econst_default() );
      } else {
         econst_default()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.el_dr.IsAvailable() ) {
         el_dr()->push_back( el.el_dr() );
      } else {
         el_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.el_matched.IsAvailable() ) {
         el_matched()->push_back( el.el_matched() );
      } else {
         el_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.emfrac.IsAvailable() ) {
         emfrac()->push_back( el.emfrac() );
      } else {
         emfrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_E.IsAvailable() ) {
         emscale_E()->push_back( el.emscale_E() );
      } else {
         emscale_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_eta.IsAvailable() ) {
         emscale_eta()->push_back( el.emscale_eta() );
      } else {
         emscale_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_m.IsAvailable() ) {
         emscale_m()->push_back( el.emscale_m() );
      } else {
         emscale_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_phi.IsAvailable() ) {
         emscale_phi()->push_back( el.emscale_phi() );
      } else {
         emscale_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_pt.IsAvailable() ) {
         emscale_pt()->push_back( el.emscale_pt() );
      } else {
         emscale_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eta.IsAvailable() ) {
         eta()->push_back( el.eta() );
      } else {
         eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etaconst_default.IsAvailable() ) {
         etaconst_default()->push_back( el.etaconst_default() );
      } else {
         etaconst_default()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.flavor_component_jfitc_doublePropName.IsAvailable() ) {
         flavor_component_jfitc_doublePropName()->push_back( el.flavor_component_jfitc_doublePropName() );
      } else {
         flavor_component_jfitc_doublePropName()->push_back( std::vector<std::string,std::allocator<std::string> >() );
      }
      if( el.flavor_component_jfitc_doublePropValue.IsAvailable() ) {
         flavor_component_jfitc_doublePropValue()->push_back( el.flavor_component_jfitc_doublePropValue() );
      } else {
         flavor_component_jfitc_doublePropValue()->push_back( std::vector<double,std::allocator<double> >() );
      }
      if( el.flavor_component_jfitc_intPropName.IsAvailable() ) {
         flavor_component_jfitc_intPropName()->push_back( el.flavor_component_jfitc_intPropName() );
      } else {
         flavor_component_jfitc_intPropName()->push_back( std::vector<std::string,std::allocator<std::string> >() );
      }
      if( el.flavor_component_jfitc_intPropValue.IsAvailable() ) {
         flavor_component_jfitc_intPropValue()->push_back( el.flavor_component_jfitc_intPropValue() );
      } else {
         flavor_component_jfitc_intPropValue()->push_back( std::vector<int,std::allocator<int> >() );
      }
      if( el.flavor_component_jfitc_isValid.IsAvailable() ) {
         flavor_component_jfitc_isValid()->push_back( el.flavor_component_jfitc_isValid() );
      } else {
         flavor_component_jfitc_isValid()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_jfitc_pb.IsAvailable() ) {
         flavor_component_jfitc_pb()->push_back( el.flavor_component_jfitc_pb() );
      } else {
         flavor_component_jfitc_pb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfitc_pc.IsAvailable() ) {
         flavor_component_jfitc_pc()->push_back( el.flavor_component_jfitc_pc() );
      } else {
         flavor_component_jfitc_pc()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfitc_pu.IsAvailable() ) {
         flavor_component_jfitc_pu()->push_back( el.flavor_component_jfitc_pu() );
      } else {
         flavor_component_jfitc_pu()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_BHadronpdg.IsAvailable() ) {
         flavor_truth_BHadronpdg()->push_back( el.flavor_truth_BHadronpdg() );
      } else {
         flavor_truth_BHadronpdg()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_truth_dRminToB.IsAvailable() ) {
         flavor_truth_dRminToB()->push_back( el.flavor_truth_dRminToB() );
      } else {
         flavor_truth_dRminToB()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_dRminToC.IsAvailable() ) {
         flavor_truth_dRminToC()->push_back( el.flavor_truth_dRminToC() );
      } else {
         flavor_truth_dRminToC()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_dRminToT.IsAvailable() ) {
         flavor_truth_dRminToT()->push_back( el.flavor_truth_dRminToT() );
      } else {
         flavor_truth_dRminToT()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_label.IsAvailable() ) {
         flavor_truth_label()->push_back( el.flavor_truth_label() );
      } else {
         flavor_truth_label()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_truth_vx_x.IsAvailable() ) {
         flavor_truth_vx_x()->push_back( el.flavor_truth_vx_x() );
      } else {
         flavor_truth_vx_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_vx_y.IsAvailable() ) {
         flavor_truth_vx_y()->push_back( el.flavor_truth_vx_y() );
      } else {
         flavor_truth_vx_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_vx_z.IsAvailable() ) {
         flavor_truth_vx_z()->push_back( el.flavor_truth_vx_z() );
      } else {
         flavor_truth_vx_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_Comb.IsAvailable() ) {
         flavor_weight_Comb()->push_back( el.flavor_weight_Comb() );
      } else {
         flavor_weight_Comb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_GbbNN.IsAvailable() ) {
         flavor_weight_GbbNN()->push_back( el.flavor_weight_GbbNN() );
      } else {
         flavor_weight_GbbNN()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_IP2D.IsAvailable() ) {
         flavor_weight_IP2D()->push_back( el.flavor_weight_IP2D() );
      } else {
         flavor_weight_IP2D()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_IP3D.IsAvailable() ) {
         flavor_weight_IP3D()->push_back( el.flavor_weight_IP3D() );
      } else {
         flavor_weight_IP3D()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_JetFitterCOMBNN.IsAvailable() ) {
         flavor_weight_JetFitterCOMBNN()->push_back( el.flavor_weight_JetFitterCOMBNN() );
      } else {
         flavor_weight_JetFitterCOMBNN()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_JetFitterCharm.IsAvailable() ) {
         flavor_weight_JetFitterCharm()->push_back( el.flavor_weight_JetFitterCharm() );
      } else {
         flavor_weight_JetFitterCharm()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_JetFitterTagNN.IsAvailable() ) {
         flavor_weight_JetFitterTagNN()->push_back( el.flavor_weight_JetFitterTagNN() );
      } else {
         flavor_weight_JetFitterTagNN()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_MV1.IsAvailable() ) {
         flavor_weight_MV1()->push_back( el.flavor_weight_MV1() );
      } else {
         flavor_weight_MV1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_MV2.IsAvailable() ) {
         flavor_weight_MV2()->push_back( el.flavor_weight_MV2() );
      } else {
         flavor_weight_MV2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_MV3_bVSc.IsAvailable() ) {
         flavor_weight_MV3_bVSc()->push_back( el.flavor_weight_MV3_bVSc() );
      } else {
         flavor_weight_MV3_bVSc()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_MV3_bVSu.IsAvailable() ) {
         flavor_weight_MV3_bVSu()->push_back( el.flavor_weight_MV3_bVSu() );
      } else {
         flavor_weight_MV3_bVSu()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_MV3_cVSu.IsAvailable() ) {
         flavor_weight_MV3_cVSu()->push_back( el.flavor_weight_MV3_cVSu() );
      } else {
         flavor_weight_MV3_cVSu()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SV0.IsAvailable() ) {
         flavor_weight_SV0()->push_back( el.flavor_weight_SV0() );
      } else {
         flavor_weight_SV0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SV1.IsAvailable() ) {
         flavor_weight_SV1()->push_back( el.flavor_weight_SV1() );
      } else {
         flavor_weight_SV1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SV2.IsAvailable() ) {
         flavor_weight_SV2()->push_back( el.flavor_weight_SV2() );
      } else {
         flavor_weight_SV2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SecondSoftMuonTagChi2.IsAvailable() ) {
         flavor_weight_SecondSoftMuonTagChi2()->push_back( el.flavor_weight_SecondSoftMuonTagChi2() );
      } else {
         flavor_weight_SecondSoftMuonTagChi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SoftMuonTagChi2.IsAvailable() ) {
         flavor_weight_SoftMuonTagChi2()->push_back( el.flavor_weight_SoftMuonTagChi2() );
      } else {
         flavor_weight_SoftMuonTagChi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.fracSamplingMax.IsAvailable() ) {
         fracSamplingMax()->push_back( el.fracSamplingMax() );
      } else {
         fracSamplingMax()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.hecf.IsAvailable() ) {
         hecf()->push_back( el.hecf() );
      } else {
         hecf()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.isBadLoose.IsAvailable() ) {
         isBadLoose()->push_back( el.isBadLoose() );
      } else {
         isBadLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isBadLooseMinus.IsAvailable() ) {
         isBadLooseMinus()->push_back( el.isBadLooseMinus() );
      } else {
         isBadLooseMinus()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isBadMedium.IsAvailable() ) {
         isBadMedium()->push_back( el.isBadMedium() );
      } else {
         isBadMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isBadTight.IsAvailable() ) {
         isBadTight()->push_back( el.isBadTight() );
      } else {
         isBadTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isUgly.IsAvailable() ) {
         isUgly()->push_back( el.isUgly() );
      } else {
         isUgly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.jvtx_x.IsAvailable() ) {
         jvtx_x()->push_back( el.jvtx_x() );
      } else {
         jvtx_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtx_y.IsAvailable() ) {
         jvtx_y()->push_back( el.jvtx_y() );
      } else {
         jvtx_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtx_z.IsAvailable() ) {
         jvtx_z()->push_back( el.jvtx_z() );
      } else {
         jvtx_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtxf.IsAvailable() ) {
         jvtxf()->push_back( el.jvtxf() );
      } else {
         jvtxf()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtxfFull.IsAvailable() ) {
         jvtxfFull()->push_back( el.jvtxfFull() );
      } else {
         jvtxfFull()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.mu_dr.IsAvailable() ) {
         mu_dr()->push_back( el.mu_dr() );
      } else {
         mu_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.mu_matched.IsAvailable() ) {
         mu_matched()->push_back( el.mu_matched() );
      } else {
         mu_matched()->push_back( std::numeric_limits< int >::min() );
      }
      ++( n() );
      if( el.n90.IsAvailable() ) {
         n90()->push_back( el.n90() );
      } else {
         n90()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nTrk.IsAvailable() ) {
         nTrk()->push_back( el.nTrk() );
      } else {
         nTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nTrk_allpv_1GeV.IsAvailable() ) {
         nTrk_allpv_1GeV()->push_back( el.nTrk_allpv_1GeV() );
      } else {
         nTrk_allpv_1GeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nTrk_pv0_1GeV.IsAvailable() ) {
         nTrk_pv0_1GeV()->push_back( el.nTrk_pv0_1GeV() );
      } else {
         nTrk_pv0_1GeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nTrk_pv0_500MeV.IsAvailable() ) {
         nTrk_pv0_500MeV()->push_back( el.nTrk_pv0_500MeV() );
      } else {
         nTrk_pv0_500MeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ootFracCells10.IsAvailable() ) {
         ootFracCells10()->push_back( el.ootFracCells10() );
      } else {
         ootFracCells10()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ootFracCells5.IsAvailable() ) {
         ootFracCells5()->push_back( el.ootFracCells5() );
      } else {
         ootFracCells5()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ootFracClusters10.IsAvailable() ) {
         ootFracClusters10()->push_back( el.ootFracClusters10() );
      } else {
         ootFracClusters10()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ootFracClusters5.IsAvailable() ) {
         ootFracClusters5()->push_back( el.ootFracClusters5() );
      } else {
         ootFracClusters5()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phi.IsAvailable() ) {
         phi()->push_back( el.phi() );
      } else {
         phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phiconst_default.IsAvailable() ) {
         phiconst_default()->push_back( el.phiconst_default() );
      } else {
         phiconst_default()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.pt.IsAvailable() ) {
         pt()->push_back( el.pt() );
      } else {
         pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptconst_default.IsAvailable() ) {
         ptconst_default()->push_back( el.ptconst_default() );
      } else {
         ptconst_default()->push_back( std::vector<float,std::allocator<float> >() );
      }
      if( el.sumPtTrk.IsAvailable() ) {
         sumPtTrk()->push_back( el.sumPtTrk() );
      } else {
         sumPtTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.sumPtTrk_allpv_1GeV.IsAvailable() ) {
         sumPtTrk_allpv_1GeV()->push_back( el.sumPtTrk_allpv_1GeV() );
      } else {
         sumPtTrk_allpv_1GeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.sumPtTrk_pv0_1GeV.IsAvailable() ) {
         sumPtTrk_pv0_1GeV()->push_back( el.sumPtTrk_pv0_1GeV() );
      } else {
         sumPtTrk_pv0_1GeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.sumPtTrk_pv0_500MeV.IsAvailable() ) {
         sumPtTrk_pv0_500MeV()->push_back( el.sumPtTrk_pv0_500MeV() );
      } else {
         sumPtTrk_pv0_500MeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tgap3f.IsAvailable() ) {
         tgap3f()->push_back( el.tgap3f() );
      } else {
         tgap3f()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackWIDTH_allpv_1GeV.IsAvailable() ) {
         trackWIDTH_allpv_1GeV()->push_back( el.trackWIDTH_allpv_1GeV() );
      } else {
         trackWIDTH_allpv_1GeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackWIDTH_pv0_1GeV.IsAvailable() ) {
         trackWIDTH_pv0_1GeV()->push_back( el.trackWIDTH_pv0_1GeV() );
      } else {
         trackWIDTH_pv0_1GeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.weightconst_default.IsAvailable() ) {
         weightconst_default()->push_back( el.weightconst_default() );
      } else {
         weightconst_default()->push_back( std::vector<float,std::allocator<float> >() );
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
   JetD3PDObjectElement& JetD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new JetD3PDObjectElement( fProxies.size(), *this ) );
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
   const JetD3PDObjectElement& JetD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( new JetD3PDObjectElement( fProxies.size(), *this ) );
      }
      return *fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   JetD3PDObject& JetD3PDObject::operator+=( const JetD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
