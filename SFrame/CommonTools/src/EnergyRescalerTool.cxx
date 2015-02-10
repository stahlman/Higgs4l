//RootCore
#include "egammaAnalysisUtils/CaloIsoCorrection.h"

#include "../include/EnergyRescalerTool.h"


const float GeV = 1000.0;

//____________________________________________________________________________         
EnergyRescalerTool::EnergyRescalerTool(SCycleBase* parent, const char* name)
    :
        ToolBase(parent, name)
{
   DeclareProperty( "doSystematic", doSystematic = "" );
}

//____________________________________________________________________________         
void EnergyRescalerTool::BeginInputData( const SInputData& )
{

    m_logger<<::DEBUG<< "Initializing egamma energy correction tool"  << SLogger::endmsg;
   
    m_eRescaler = new AtlasRoot::egammaEnergyCorrectionTool();
    m_eRescaler->setFileName("$ROOTCOREBIN/data/ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionData.root");

    if (is_data()){
      m_eRescaler->setESModel(egEnergyCorr::es2012c);
    } else {
      if (get_mctype() == AtlasSFrame::MC12a) 	   m_eRescaler->setESModel(egEnergyCorr::es2012a);
      else if (get_mctype() == AtlasSFrame::MC12b) m_eRescaler->setESModel(egEnergyCorr::es2012a);
      else if (get_mctype() == AtlasSFrame::MC12c) m_eRescaler->setESModel(egEnergyCorr::es2012c);
      //else if(get_mctype() == AtlasSFrame::MC11c)	 m_eRescaler->setESModel(egEnergyCorr::es2011c);
    }
    
    m_eRescaler->initialize();
    
    m_logger<<::DEBUG<< "Initializing calo iso corrections"  << SLogger::endmsg;
    
    CaloIsoCorrection::SetPtLeakageCorrectionsFile(sframe_dir()+"/RootCore/egammaAnalysisUtils/share/isolation_leakage_corrections.root");
        
    m_logger<<::DEBUG<< "Initializing muon smearing tool"  << SLogger::endmsg;
    
    std::string pathNoRootCore = sframe_dir()+"/RootCore/MuonMomentumCorrections/share/";
    m_muRescaler = new MuonSmear::SmearingClass("Data12","staco","q_pT","Rel17.2Sum13",pathNoRootCore);

    m_muRescaler->UseScale(1);
    m_muRescaler->UseImprovedCombine();

    m_logger<<::DEBUG<< "Initializing muon scale factor tool"  << SLogger::endmsg;

    if( is_data()){
      //if(isYear==2012){
      mu_resolSF=new Analysis::MuonResolutionAndMomentumScaleFactors(pathNoRootCore+"final_scale_factors_data2012.txt");
      //}
      //if(isYear==2011){
      //mu_resolSF=new Analysis::MuonResolutionAndMomentumScaleFactors("MuonMomentumCorrections/share/final_scale_factors_data2011.txt");
      //}
    } else {
      if(get_mctype() == AtlasSFrame::MC12a || get_mctype() == AtlasSFrame::MC12b || get_mctype() == AtlasSFrame::MC12c){
        mu_resolSF=new Analysis::MuonResolutionAndMomentumScaleFactors(pathNoRootCore+"final_scale_factors_MC12_smearing.txt");
      }
      //if(get_mctype() == AtlasSFrame::MC11c){
      //mu_resolSF=new Analysis::MuonResolutionAndMomentumScaleFactors("MuonMomentumCorrections/share/final_scale_factors_MC11_smeared.txt");
      //}
    }

    m_logger<<::DEBUG<< "Initializing jet calibration tool"  << SLogger::endmsg;

    
    std::string jetPath = ""; 
    if (is_data()){
       jetPath= sframe_dir()+"/RootCore/ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_Jan13.config";
    
    } else {    
       if(get_mctype() == AtlasSFrame::MC12a) {
	 jetPath= sframe_dir()+"/RootCore/ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_Jan13.config";
       }
       if(get_mctype() == AtlasSFrame::MC12b || get_mctype() == AtlasSFrame::MC12c) {
	 jetPath= sframe_dir()+"/RootCore/ApplyJetCalibration/data/CalibrationConfigs/JES_Full2012dataset_Preliminary_MC12b_Sep23.config";
       }
    }
    m_JetRescaler = new JetAnalysisCalib::JetCalibrationTool("AntiKt4TopoEM",jetPath, is_data());

    m_logger<<::DEBUG<< "Initializing jet uncertainty tools"  << SLogger::endmsg;

    std::string jetUncPath = sframe_dir()+"/RootCore/JetUncertainties/share/";
    m_JetUncertainties = new MultijetJESUncertaintyProvider("JES_2012/Moriond2013/MultijetJES_2012.config", "JES_2012/Moriond2013/InsituJES2012_20NP_ByCategory.config", "AntiKt4TopoEM", "MC12a", jetUncPath); 

    std::string jerUncPath = sframe_dir()+"/RootCore/JetResolution/share/";
    m_JERTool = new JetSmearingTool("AntiKt4TopoEM" , jerUncPath+"JERProviderPlots_2012.root");
    m_JERTool->init();
     
    m_logger<<::DEBUG<< "Initializing IP smearing tool"  << SLogger::endmsg;
    //IP smearing 'tools'
    std::string smearingPath = sframe_dir()+"/config/other/impact_parameter_smearing.root";

    ip_smear = new TFile(smearingPath.c_str());
    smearD0[0] = (TH2F*)ip_smear->Get("smearD0_0");
    smearD0[1] = (TH2F*)ip_smear->Get("smearD0_1");
    smearD0[2] = (TH2F*)ip_smear->Get("smearD0_2");

    smearZ0[0] = (TH2F*)ip_smear->Get("smearZ0_0");
    smearZ0[1] = (TH2F*)ip_smear->Get("smearZ0_1");
    smearZ0[2] = (TH2F*)ip_smear->Get("smearZ0_2");

    smear_X = smearD0[0]->GetXaxis(); // axis is needed only to get binning, the same for all histograms
    smear_Y = smearD0[0]->GetYaxis();

    //// E-p combination
    
    if (is_data()){
      m_EPcombination= new egammaFourMomentumError("2012,likelihood,MC12c");
      
    } else {  
      //if( get_mctype() == AtlasSFrame::MC11c ) m_EPcombination= new egammaFourMomentumError("2011,likelihood,MC11c");
      //if( get_mctype() == AtlasSFrame::MC11d ) m_EPcombination= new egammaFourMomentumError("2011,likelihood,MC11d");
      if( get_mctype() == AtlasSFrame::MC12a )      m_EPcombination= new egammaFourMomentumError("2012,likelihood,MC12a");
      else if( get_mctype() == AtlasSFrame::MC12b ) m_EPcombination= new egammaFourMomentumError("2012,likelihood,MC12a");
      else if( get_mctype() == AtlasSFrame::MC12c ) m_EPcombination= new egammaFourMomentumError("2012,likelihood,MC12c");
    }
    
    return;
}

//____________________________________________________________________________
void EnergyRescalerTool::ApplyEnergyRescaler(std::vector<Electron>& vec, const int EventNumber,const int RunNumber)
{

    for(std::vector<Electron>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        ApplyEnergyRescaler(*itr, EventNumber, RunNumber);
    }
}


//____________________________________________________________________________
void EnergyRescalerTool::ApplyEnergyRescaler(Electron& p, const int EventNumber, const int RunNumber)
{
  const int seed = EventNumber+100*p.GetIndex();

  //original energy
  const float E_uncorrected = p.cl_E();
  
  //corrected energy
  float  E_corrected(p.cl_E());  
  double E_error(0.);
  
  //PATCore::ParticleType::Type ptype = PATCore::ParticleType::Electron;;
  egEnergyCorr::Scale::Variation scaleVar = egEnergyCorr::Scale::Nominal;
  if (doSystematic != ""){
    if (doSystematic == "ElectronScaleZeeAllUp")   		scaleVar = egEnergyCorr::Scale::ZeeAllUp;
    else if (doSystematic == "ElectronScaleZeeAllDn") 		scaleVar = egEnergyCorr::Scale::ZeeAllDown;
    else if (doSystematic == "ElectronScaleZeeStatUp")   	scaleVar = egEnergyCorr::Scale::ZeeStatUp;
    else if (doSystematic == "ElectronScaleZeeStatDn") 		scaleVar = egEnergyCorr::Scale::ZeeStatDown;
    else if (doSystematic == "ElectronScaleZeeSystUp")   	scaleVar = egEnergyCorr::Scale::ZeeSystUp;
    else if (doSystematic == "ElectronScaleZeeSystDn") 		scaleVar = egEnergyCorr::Scale::ZeeSystDown;
    else if (doSystematic == "ElectronScaleZeeAllUp")   	scaleVar = egEnergyCorr::Scale::ZeeAllUp;
    else if (doSystematic == "ElectronScaleZeeAllDn") 		scaleVar = egEnergyCorr::Scale::ZeeAllDown;
    else if (doSystematic == "ElectronScalePSBarrelUp" && fabs(p.cl_eta()) < 1.4 )		 scaleVar = egEnergyCorr::Scale::PSUp;
    else if (doSystematic == "ElectronScalePSBarrelDn" && fabs(p.cl_eta()) < 1.4 )		 scaleVar = egEnergyCorr::Scale::PSDown;
    else if (doSystematic == "ElectronScalePSEndcapUp" && fabs(p.cl_eta()) >= 1.4 )		 scaleVar = egEnergyCorr::Scale::PSUp;
    else if (doSystematic == "ElectronScalePSEndcapDn" && fabs(p.cl_eta()) >= 1.4 )		 scaleVar = egEnergyCorr::Scale::PSDown;
    else if (doSystematic == "ElectronScaleS12BarrelUp" && fabs(p.cl_eta()) < 1.4 )		 scaleVar = egEnergyCorr::Scale::S12Up;
    else if (doSystematic == "ElectronScaleS12BarrelDn" && fabs(p.cl_eta()) < 1.4 )		 scaleVar = egEnergyCorr::Scale::S12Down;
    else if (doSystematic == "ElectronScaleS12EndcapUp" && fabs(p.cl_eta()) >= 1.4 )		 scaleVar = egEnergyCorr::Scale::S12Up;
    else if (doSystematic == "ElectronScaleS12EndcapDn" && fabs(p.cl_eta()) >= 1.4 )		 scaleVar = egEnergyCorr::Scale::S12Down;
    else if (doSystematic == "ElectronScaleMatID1Up" && fabs(p.cl_eta()) < 1.1 )		 scaleVar = egEnergyCorr::Scale::MatIDUp;
    else if (doSystematic == "ElectronScaleMatID1Dn" && fabs(p.cl_eta()) < 1.1 )		 scaleVar = egEnergyCorr::Scale::MatIDDown;
    else if (doSystematic == "ElectronScaleMatID2Up" && fabs(p.cl_eta()) >= 1.1 && fabs(p.cl_eta()) < 1.5 )		  scaleVar = egEnergyCorr::Scale::MatIDUp;
    else if (doSystematic == "ElectronScaleMatID2Dn" && fabs(p.cl_eta()) >= 1.1 && fabs(p.cl_eta()) < 1.5 )		  scaleVar = egEnergyCorr::Scale::MatIDDown;
    else if (doSystematic == "ElectronScaleMatID3Up" && fabs(p.cl_eta()) >= 1.5 && fabs(p.cl_eta()) < 2.1 )		  scaleVar = egEnergyCorr::Scale::MatIDUp;
    else if (doSystematic == "ElectronScaleMatID3Dn" && fabs(p.cl_eta()) >= 1.5 && fabs(p.cl_eta()) < 2.1 )		  scaleVar = egEnergyCorr::Scale::MatIDDown;
    else if (doSystematic == "ElectronScaleMatID4Up" && fabs(p.cl_eta()) >= 2.1 )		 scaleVar = egEnergyCorr::Scale::MatIDUp;
    else if (doSystematic == "ElectronScaleMatID4Dn" && fabs(p.cl_eta()) >= 2.1 )		 scaleVar = egEnergyCorr::Scale::MatIDDown;
    else if (doSystematic == "ElectronScaleMatCryoBarrelUp" && fabs(p.cl_eta()) < 1.6 ) 	 scaleVar = egEnergyCorr::Scale::MatCryoUp;
    else if (doSystematic == "ElectronScaleMatCryoBarrelDn" && fabs(p.cl_eta()) < 1.6 ) 	 scaleVar = egEnergyCorr::Scale::MatCryoDown;
    else if (doSystematic == "ElectronScaleMatCryoEndcapUp" && fabs(p.cl_eta()) >= 1.6 ) 	 scaleVar = egEnergyCorr::Scale::MatCryoUp;
    else if (doSystematic == "ElectronScaleMatCryoEndcapDn" && fabs(p.cl_eta()) >= 1.6 ) 	 scaleVar = egEnergyCorr::Scale::MatCryoDown;
    else if (doSystematic == "ElectronScaleMatCaloBarrelUp" && fabs(p.cl_eta()) < 1.4 ) 	 scaleVar = egEnergyCorr::Scale::MatCaloUp;
    else if (doSystematic == "ElectronScaleMatCaloBarrelDn" && fabs(p.cl_eta()) < 1.4 ) 	 scaleVar = egEnergyCorr::Scale::MatCaloDown;
    else if (doSystematic == "ElectronScaleMatCaloEndcapUp" && fabs(p.cl_eta()) >= 1.4 ) 	 scaleVar = egEnergyCorr::Scale::MatCaloUp;
    else if (doSystematic == "ElectronScaleMatCaloEndcapDn" && fabs(p.cl_eta()) >= 1.4 ) 	 scaleVar = egEnergyCorr::Scale::MatCaloDown;
    else if (doSystematic == "ElectronScaleLArCalibBarrelUp" && fabs(p.cl_eta()) < 1.4 )   	 scaleVar = egEnergyCorr::Scale::LArCalibUp;
    else if (doSystematic == "ElectronScaleLArCalibBarrelDn" && fabs(p.cl_eta()) < 1.4 ) 	 scaleVar = egEnergyCorr::Scale::LArCalibDown;
    else if (doSystematic == "ElectronScaleLArCalibEndcapUp" && fabs(p.cl_eta()) >= 1.4)      	 scaleVar = egEnergyCorr::Scale::LArCalibUp;
    else if (doSystematic == "ElectronScaleLArCalibEndcapDn" && fabs(p.cl_eta()) >= 1.4)      	 scaleVar = egEnergyCorr::Scale::LArCalibDown;
    else if (doSystematic == "ElectronScaleLArUnconvCalibBarrelUp" && fabs(p.cl_eta()) < 1.4 )   scaleVar = egEnergyCorr::Scale::LArUnconvCalibUp;
    else if (doSystematic == "ElectronScaleLArUnconvCalibBarrelDn" && fabs(p.cl_eta()) < 1.4 )   scaleVar = egEnergyCorr::Scale::LArUnconvCalibDown;
    else if (doSystematic == "ElectronScaleLArUnconvCalibEndcapUp" && fabs(p.cl_eta()) >= 1.4 && fabs(p.cl_eta()) < 1.8 )   scaleVar = egEnergyCorr::Scale::LArUnconvCalibUp;
    else if (doSystematic == "ElectronScaleLArUnconvCalibEndcapDn" && fabs(p.cl_eta()) >= 1.4 && fabs(p.cl_eta()) < 1.8 )   scaleVar = egEnergyCorr::Scale::LArUnconvCalibDown;
    else if (doSystematic == "ElectronScaleLArElecUnconvBarrelUp" && fabs(p.cl_eta()) < 1.4 )	 scaleVar = egEnergyCorr::Scale::LArElecUnconvUp;
    else if (doSystematic == "ElectronScaleLArElecUnconvBarrelDn" && fabs(p.cl_eta()) < 1.4 )	 scaleVar = egEnergyCorr::Scale::LArElecUnconvDown;
    else if (doSystematic == "ElectronScaleLArElecUnconvEndcapUp" && fabs(p.cl_eta()) >= 1.4 && fabs(p.cl_eta()) < 1.8 )	 scaleVar = egEnergyCorr::Scale::LArElecUnconvUp;
    else if (doSystematic == "ElectronScaleLArElecUnconvEndcapDn" && fabs(p.cl_eta()) >= 1.4 && fabs(p.cl_eta()) < 1.8 )	 scaleVar = egEnergyCorr::Scale::LArElecUnconvDown;
    else if (doSystematic == "ElectronScaleLArElecCalibUp" && fabs(p.cl_eta()) >= 1.8 )        scaleVar = egEnergyCorr::Scale::LArElecCalibUp;
    else if (doSystematic == "ElectronScaleLArElecCalibDn" && fabs(p.cl_eta()) >= 1.8 )        scaleVar = egEnergyCorr::Scale::LArElecCalibDown;
    else if (doSystematic == "ElectronScaleL1GainUp")   	scaleVar = egEnergyCorr::Scale::L1GainUp;
    else if (doSystematic == "ElectronScaleL1GainDn") 		scaleVar = egEnergyCorr::Scale::L1GainDown;
    else if (doSystematic == "ElectronScaleL2GainUp")   	scaleVar = egEnergyCorr::Scale::L2GainUp;
    else if (doSystematic == "ElectronScaleL2GainDn") 		scaleVar = egEnergyCorr::Scale::L2GainDown;
    else if (doSystematic == "ElectronScaleG4Up")   		scaleVar = egEnergyCorr::Scale::G4Up;
    else if (doSystematic == "ElectronScaleG4Dn") 		scaleVar = egEnergyCorr::Scale::G4Down;
    else if (doSystematic == "ElectronScalePedestalUp")   	scaleVar = egEnergyCorr::Scale::PedestalUp;
    else if (doSystematic == "ElectronScalePedestalDn") 	scaleVar = egEnergyCorr::Scale::PedestalDown;
  }
  
  egEnergyCorr::Resolution::Variation res = egEnergyCorr::Resolution::Nominal;
  if (doSystematic != ""){
    if (doSystematic == "ElectronResolutionZSmearingUp")   		res = egEnergyCorr::Resolution::ZSmearingUp;
    else if (doSystematic == "ElectronResolutionZSmearingDn") 		res = egEnergyCorr::Resolution::ZSmearingDown;
    else if (doSystematic == "ElectronResolutionSamplingTermUp")   	res = egEnergyCorr::Resolution::SamplingTermUp;
    else if (doSystematic == "ElectronResolutionSamplingTermDn") 	res = egEnergyCorr::Resolution::SamplingTermDown;
    else if (doSystematic == "ElectronResolutionMaterialIDUp")   	res = egEnergyCorr::Resolution::MaterialIDUp;
    else if (doSystematic == "ElectronResolutionMaterialIDDn") 		res = egEnergyCorr::Resolution::MaterialIDDown;
    else if (doSystematic == "ElectronResolutionMaterialCaloUp")   	res = egEnergyCorr::Resolution::MaterialCaloUp;
    else if (doSystematic == "ElectronResolutionMaterialCaloDn") 	res = egEnergyCorr::Resolution::MaterialCaloDown;
    else if (doSystematic == "ElectronResolutionMaterialGapUp")   	res = egEnergyCorr::Resolution::MaterialGapUp;
    else if (doSystematic == "ElectronResolutionMaterialGapDn") 	res = egEnergyCorr::Resolution::MaterialGapDown;
    else if (doSystematic == "ElectronResolutionMaterialCryoUp")   	res = egEnergyCorr::Resolution::MaterialCryoUp;
    else if (doSystematic == "ElectronResolutionMaterialCryoDn") 	res = egEnergyCorr::Resolution::MaterialCryoDown;
    else if (doSystematic == "ElectronResolutionPileUpUp")   		res = egEnergyCorr::Resolution::PileUpUp;
    else if (doSystematic == "ElectronResolutionPileUpDn") 		res = egEnergyCorr::Resolution::PileUpDown;
  }
  
  PATCore::ParticleDataType::DataType dataType;
  if(is_data()){
    m_logger<<::DEBUG<< "Applying energy scale corrections to electron in data"  << SLogger::endmsg;
    dataType=PATCore::ParticleDataType::Data;
  }else{
    m_logger<<::DEBUG<< "Applying energy smearing to electron in MC "  << SLogger::endmsg;
    dataType=PATCore::ParticleDataType::Full;
  }
  m_eRescaler->setRandomSeed(EventNumber+100*p.GetIndex());
  if ( (p.author() == 1) || (p.author() == 3) ){// (Author==1) OR (Author==3)
     //m_logger << INFO << "p.rawcl_Es0(),  " << p.rawcl_Es0()  << SLogger::endmsg;
     //m_logger << INFO << "p.rawcl_Es1(),  " << p.rawcl_Es1()  << SLogger::endmsg;
     //m_logger << INFO << "p.rawcl_Es2(),  " << p.rawcl_Es2()  << SLogger::endmsg;
     //m_logger << INFO << "p.rawcl_Es3(),  " << p.rawcl_Es3()  << SLogger::endmsg;
     //m_logger << INFO << "p.cl_eta(),     " << p.cl_eta()	<< SLogger::endmsg;
     //m_logger << INFO << "p.cl_phi(),     " << p.cl_phi()	<< SLogger::endmsg;
     //m_logger << INFO << "p.tracketa(),   " << p.tracketa()	<< SLogger::endmsg;
     //m_logger << INFO << "p.cl_E(),	    " << p.cl_E()	<< SLogger::endmsg;
     //m_logger << INFO << "p.cl_etaCalo(), " << p.cl_etaCalo() << SLogger::endmsg;
     //m_logger << INFO << "p.cl_phiCalo())," << p.cl_phiCalo() << SLogger::endmsg;
     E_corrected = m_eRescaler->getCorrectedEnergy(RunNumber,
						  dataType,
						  AtlasRoot::egammaEnergyCorrectionTool::ParticleInformation(p.rawcl_Es0(),
													     p.rawcl_Es1(),
													     p.rawcl_Es2(),
													     p.rawcl_Es3(),
													     p.cl_eta(),
													     p.cl_phi(),
													     p.tracketa(),
													     p.cl_E(),
													     p.cl_etaCalo(),
													     p.cl_phiCalo()),
						  scaleVar,
						  res);//,
						  //egEnergyCorr::Resolution::SigmaEff90,
						  //1.0 );
  
     p.Set_calibrated_E(E_corrected);
  } else {
    m_logger << ::DEBUG << "Author was weird!" << SLogger::endmsg;
  }
  
  //// EP COMBINATION
  if ((p.author()==1) || (p.author()==3)){
    TLorentzVector track, cluster, combined;

    egEnergyCorr::Scale::Variation scaleVar_mom = egEnergyCorr::Scale::Nominal;
    if (doSystematic != ""){
      if (doSystematic == "ElectronScaleMomentumUp")      scaleVar_mom = egEnergyCorr::Scale::MomentumUp;
      else if (doSystematic == "ElectronScaleMomentumDn") scaleVar_mom = egEnergyCorr::Scale::MomentumDown;
    }
    double track_momentum = m_eRescaler->getCorrectedMomentum( dataType,
		                                	       PATCore::ParticleType::Electron,
		                 			       fabs(1./p.trackqoverp()),
		                 			       p.tracketa(),
		                 			       scaleVar_mom,
		                 			       1.0 );				 
				     
    //Set track, cluster four momenta
    track.SetPtEtaPhiE(track_momentum*sin(p.tracktheta()),
                       p.tracketa(),
		       p.trackphi(),
                       track_momentum);
    
    cluster.SetPtEtaPhiE(E_corrected/cosh(p.cl_eta()),
                         p.cl_eta(),
                         p.cl_phi(), 
                         E_corrected);
    
    
    double el_qoverp_LM=p.trackqoverp();
    for (unsigned int j= 0; j<p.refittedTrack_LMqoverp().size();++j){
      if( p.refittedTrack_author().at(j)==4){
        el_qoverp_LM=p.refittedTrack_LMqoverp().at(j);
      }
    }

    Double_t cluster_error = m_eRescaler->resolution(E_corrected, p.cl_eta(), PATCore::ParticleType::Electron, true)*E_corrected; 
    E_error = cluster_error;
    
    //Perform four momentum combination.
//     m_logger << ::INFO << "track,               " << track                << SLogger::endmsg;
//     m_logger << ::DEBUG << "cluster,             " << cluster              << SLogger::endmsg;
//     m_logger << ::INFO << "el_qoverp_LM,        " << el_qoverp_LM         << SLogger::endmsg;
//     m_logger << ::INFO << "p.trackcov_qoverp(), " << p.trackcov_qoverp()  << SLogger::endmsg;
//     m_logger << ::INFO << "p.charge(),          " << p.charge()           << SLogger::endmsg;
//     m_logger << ::INFO << "cluster_error,       " << cluster_error        << SLogger::endmsg;
//     m_logger << ::INFO << "combined,            " << combined             << SLogger::endmsg;
    double e_error = cluster_error;
    bool success = m_EPcombination->buildfourmom(track, 
				  cluster,
				  //p.qoverp_LM(), 
				  el_qoverp_LM,
				  p.trackcov_qoverp(), 
				  p.charge(),
				  cluster_error,
				  combined,
				  e_error);
    E_corrected  = combined.E();
    //E_error = e_error;
    if (success) E_error = e_error;
    m_logger<<::DEBUG<< "ep success: " <<  success << " corrected E:" << E_corrected << " e_error: " << e_error << "E_error: " << E_error<< SLogger::endmsg;     
  }
  
  m_logger<<::DEBUG<< "Original energy: " << E_uncorrected << " corrected energy: "<< E_corrected << SLogger::endmsg;    
  p.Set_cl_E(E_corrected);      

  //calculate energy resolution
  //p.Set_E_resolution( m_eRescaler->resolution(p.cl_E_cal(), p.cl_eta(),PATCore::ParticleType::Electron,true)*p.cl_E_cal() );  
  p.Set_E_resolution(E_error);

  m_logger<<::DEBUG<< "Electron Energy: " << p.cl_E_cal() << " resolution: "<< p.E_resolution() << SLogger::endmsg;      


  m_logger<<::DEBUG<< "Applying IP smearing to electron in MC "  << SLogger::endmsg;
  
  if (!is_data()){
    double d0 = p.D0();
    //bias + smearing in mc12    
    d0 -= 2.e-3; 
    d0 += GetD0Z0SmearSigma(p.nBLHits(), p.trackpt(), p.tracketa(), seed, "D0");    
    p.Set_D0(d0);
    
    double z0 = p.Z0();
    //smearing in mc12    
    z0 += GetD0Z0SmearSigma(p.nBLHits(), p.trackpt(), p.tracketa(), seed, "Z0");    
    p.Set_Z0(z0);
    
  }
  
  return;
}

//____________________________________________________________________________
void EnergyRescalerTool::ApplyEnergyRescaler(std::vector<Muon>& vec, const int EventNumber)
{

    for(std::vector<Muon>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        ApplyEnergyRescaler(*itr, EventNumber);
    }
}


//____________________________________________________________________________
void EnergyRescalerTool::ApplyEnergyRescaler(Muon& p, const int EventNumber)
{

  if (is_data()) {
    
    //do nothing
        
  } else {

    m_logger<<::DEBUG<< "Applying pT smearing to muon "<< p.GetIndex() << SLogger::endmsg;

    //calibrate pT
    m_muRescaler->SetSeed(EventNumber, p.GetIndex());

    if (p.isSegmentTaggedMuon() || p.isCaloMuon()){ 

       m_logger<<::DEBUG<< "Smearing ST/Calo muon "<<SLogger::endmsg;
       double ptSmeared = p.Pt();
       
       if (fabs(p.eta()) < 2.7){ 
            m_muRescaler->Event(p.Pt(),p.eta(), "ID", p.charge(), p.phi());

	    ptSmeared = m_muRescaler->pTID();
       }
       
       //Systematic variations
       if (doSystematic == "MuonResolutionIDUp") m_muRescaler->PTVar(ptSmeared, "IDUP");
       if (doSystematic == "MuonResolutionIDDn") m_muRescaler->PTVar(ptSmeared, "IDLOW");
       if (doSystematic == "MuonScaleUp")	 m_muRescaler->PTVar(ptSmeared, "SCALEUP");
       if (doSystematic == "MuonScaleDn")	 m_muRescaler->PTVar(ptSmeared, "SCALELOW");

       p.Set_Pt(ptSmeared);
       p.Set_id_Pt(ptSmeared);
    
    } else if (p.isStandAloneMuon()){ 

       m_logger<<::DEBUG<< "Smearing Standalone muon "<<SLogger::endmsg;
       double ptSmeared = p.Pt();
       
       if (fabs(p.eta()) < 2.7){ 
            m_muRescaler->Event(p.Pt(),p.eta(), "MS", p.charge(), p.phi());

	    ptSmeared = m_muRescaler->pTMS();
       }

       //Systematic variations       
       if (doSystematic == "MuonResolutionMSUp") m_muRescaler->PTVar(ptSmeared, "MSUP");
       if (doSystematic == "MuonResolutionMSDn") m_muRescaler->PTVar(ptSmeared, "MSLOW");
       if (doSystematic == "MuonScaleUp")        m_muRescaler->PTVar(ptSmeared, "SCALEUP");
       if (doSystematic == "MuonScaleDn")        m_muRescaler->PTVar(ptSmeared, "SCALELOW");

       p.Set_Pt(ptSmeared);

    } else if (p.isCombinedMuon()){ 

       m_logger<<::DEBUG<< "Smearing Combined muon in event " << EventNumber << " ( Eta: " << p.eta() << "  Phi: " << p.phi() << ")"<<SLogger::endmsg;
       m_logger<<::DEBUG<< "Before: MS pT: "<<p.me_Pt()<< " ID pT: "<< p.id_Pt()<< " CB pT: "<< p.Pt()  << SLogger::endmsg;

       double ptms = p.me_Pt();
       double ptid = p.id_Pt();
       double ptcb = p.Pt();

       if (fabs(p.eta()) < 2.7){ 
          m_muRescaler->Event(ptms,ptid,ptcb,p.eta(), p.charge(), p.phi());
       
          ptms = m_muRescaler->pTMS();
          ptid = m_muRescaler->pTID();
          ptcb = m_muRescaler->pTCB();
       }
       
       //Systematic variations
       if (doSystematic == "MuonResolutionIDUp") m_muRescaler->PTVar(ptms, ptid, ptcb, "IDUP");
       if (doSystematic == "MuonResolutionIDDn") m_muRescaler->PTVar(ptms, ptid, ptcb, "IDLOW");
       if (doSystematic == "MuonResolutionMSUp") m_muRescaler->PTVar(ptms, ptid, ptcb, "MSUP");
       if (doSystematic == "MuonResolutionMSDn") m_muRescaler->PTVar(ptms, ptid, ptcb, "MSLOW");
       if (doSystematic == "MuonScaleUp")	 m_muRescaler->PTVar(ptms, ptid, ptcb, "SCALEUP");
       if (doSystematic == "MuonScaleDn")	 m_muRescaler->PTVar(ptms, ptid, ptcb, "SCALELOW");             
       
       p.Set_Pt(ptcb);
       p.Set_id_Pt(ptid);
       p.Set_me_Pt(ptms);

       m_logger<<::DEBUG<< "After : MS pT: "<<p.me_Pt()<< " ID pT: "<< p.id_Pt()<< " CB pT: "<< p.Pt()   << SLogger::endmsg;

    }
  
    //calibrate IP

    m_logger<<::DEBUG<< "Applying IP smearing to muon in MC "  << SLogger::endmsg;

    double d0 = p.D0();    
    double sig_d0 = p.sigma_D0();
    double z0 = p.Z0();

    if (p.isStandAloneMuon()) {
      //do nothing
    } else {
       const int seed = EventNumber+100*p.GetIndex();
 
       //bias + smearing in mc12    
       d0 -= 2.e-3; 
       d0 += GetD0Z0SmearSigma(p.nBLHits(),  p.id_pt(), p.id_eta(), seed, "D0");    

       //smearing in mc12    
       z0 += GetD0Z0SmearSigma(p.nBLHits(), p.id_pt(), p.id_eta(), seed, "Z0");    
    }
    
    p.Set_D0(d0);
    p.Set_Z0(z0);
  }
  
  m_logger<<::DEBUG<< "Applying momentum uncertainty scaling to muon"  << SLogger::endmsg;

  // muon type, =1 for combined muons, =2 for calorimeter and segment tagged muons, =3 for stand-alone muons 
  int type = (p.isCombinedMuon())*1 + (p.isSegmentTaggedMuon() || p.isCaloMuon())*2 + (p.isStandAloneMuon())*3;       
      
  TLorentzVector mu;
  mu.SetPtEtaPhiM(p.Pt(),p.eta(),p.phi(),p.m());

  double MuonErrSF = mu_resolSF->getResolutionScaleFactor(mu,type);

  m_logger<<::DEBUG<< "type:  " << type<<" MuonErrSF: " << MuonErrSF<<" mu_cov_qoverp_exPV = "<< p.cov_qoverp_exPV() << SLogger::endmsg;

  p.Set_cov_qoverp_exPV(p.cov_qoverp_exPV()*MuonErrSF*MuonErrSF);
  p.Set_cov_d0_qoverp_exPV(p.cov_d0_qoverp_exPV()*MuonErrSF);
  p.Set_cov_z0_qoverp_exPV(p.cov_z0_qoverp_exPV()*MuonErrSF);    
  p.Set_cov_phi_qoverp_exPV(p.cov_phi_qoverp_exPV()*MuonErrSF);
  p.Set_cov_theta_qoverp_exPV(p.cov_theta_qoverp_exPV()*MuonErrSF);
         
  return;
}

//____________________________________________________________________________
float EnergyRescalerTool::GetD0Z0SmearSigma(int nBL, float pt, float eta, int seed, std::string opt) {
  
   m_logger<<::DEBUG<< "Entering GetD0Z0SmearSigma()"  << SLogger::endmsg;
   m_logger<<::DEBUG<< nBL<< " "<<pt<< " "<<eta<< " "<< seed  << SLogger::endmsg;

  if(nBL>=2) nBL = 2;

  float sinTheta = 1./cosh(eta);
  float p = pt*cosh(eta);
  float p_quant = 1./sqrt(pt*pt*sinTheta)/1000.; // 1./sqrt(p*p*sinTheta*sinTheta*sinTheta)

  int Xbin = smear_X->FindFixBin(eta);
  int Ybin = smear_Y->FindFixBin(p_quant);
  float sigma = 0;
  
  if ( opt.compare("D0")  == 0) sigma = smearD0[nBL]->GetBinContent(Xbin, Ybin);
  else if ( opt.compare("Z0")  == 0) sigma = smearZ0[nBL]->GetBinContent(Xbin, Ybin);
  else m_logger<<::WARNING<< "GetD0Z0SmearSigma: Invalid option: "<< opt  << SLogger::endmsg;    
  
   m_logger<<::DEBUG<< "Throwing random"  << SLogger::endmsg;  

  random3.SetSeed(seed);
  return random3.Gaus(0,sigma);

}

//____________________________________________________________________________
void EnergyRescalerTool::ApplyEnergyRescaler(std::vector<Photon>& vec, const int EventNumber,const int RunNumber)
{

    for(std::vector<Photon>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        ApplyEnergyRescaler(*itr, EventNumber, RunNumber);
    }
    
    return;
}


//____________________________________________________________________________
void EnergyRescalerTool::ApplyEnergyRescaler(Photon& p, const int EventNumber, const int RunNumber)
{

  //original energy
  const float E_uncorrected = p.cl_E();

  //corrected energy
  float E_corrected = p.cl_E();

  PATCore::ParticleDataType::DataType dataType;
  //PATCore::ParticleType::Type ptype=PATCore::ParticleType::Photon;
  egEnergyCorr::Scale::Variation scaleVar = egEnergyCorr::Scale::Nominal;
  if (doSystematic != ""){
    if (doSystematic == "ElectronScaleZeeAllUp")   		scaleVar = egEnergyCorr::Scale::ZeeAllUp;
    else if (doSystematic == "ElectronScaleZeeAllDn") 		scaleVar = egEnergyCorr::Scale::ZeeAllDown;
    else if (doSystematic == "ElectronScaleZeeStatUp")   	scaleVar = egEnergyCorr::Scale::ZeeStatUp;
    else if (doSystematic == "ElectronScaleZeeStatDn") 		scaleVar = egEnergyCorr::Scale::ZeeStatDown;
    else if (doSystematic == "ElectronScaleZeeSystUp")   	scaleVar = egEnergyCorr::Scale::ZeeSystUp;
    else if (doSystematic == "ElectronScaleZeeSystDn") 		scaleVar = egEnergyCorr::Scale::ZeeSystDown;
    else if (doSystematic == "ElectronScaleZeeAllUp")   	scaleVar = egEnergyCorr::Scale::ZeeAllUp;
    else if (doSystematic == "ElectronScaleZeeAllDn") 		scaleVar = egEnergyCorr::Scale::ZeeAllDown;
    else if (doSystematic == "ElectronScalePSBarrelUp" && fabs(p.cl_eta()) < 1.4 )		 scaleVar = egEnergyCorr::Scale::PSUp;
    else if (doSystematic == "ElectronScalePSBarrelDn" && fabs(p.cl_eta()) < 1.4 )		 scaleVar = egEnergyCorr::Scale::PSDown;
    else if (doSystematic == "ElectronScalePSEndcapUp" && fabs(p.cl_eta()) >= 1.4 )		 scaleVar = egEnergyCorr::Scale::PSUp;
    else if (doSystematic == "ElectronScalePSEndcapDn" && fabs(p.cl_eta()) >= 1.4 )		 scaleVar = egEnergyCorr::Scale::PSDown;
    else if (doSystematic == "ElectronScaleS12BarrelUp" && fabs(p.cl_eta()) < 1.4 )		 scaleVar = egEnergyCorr::Scale::S12Up;
    else if (doSystematic == "ElectronScaleS12BarrelDn" && fabs(p.cl_eta()) < 1.4 )		 scaleVar = egEnergyCorr::Scale::S12Down;
    else if (doSystematic == "ElectronScaleS12EndcapUp" && fabs(p.cl_eta()) >= 1.4 )		 scaleVar = egEnergyCorr::Scale::S12Up;
    else if (doSystematic == "ElectronScaleS12EndcapDn" && fabs(p.cl_eta()) >= 1.4 )		 scaleVar = egEnergyCorr::Scale::S12Down;
    else if (doSystematic == "ElectronScaleMatID1Up" && fabs(p.cl_eta()) < 1.1 )		 scaleVar = egEnergyCorr::Scale::MatIDUp;
    else if (doSystematic == "ElectronScaleMatID1Dn" && fabs(p.cl_eta()) < 1.1 )		 scaleVar = egEnergyCorr::Scale::MatIDDown;
    else if (doSystematic == "ElectronScaleMatID2Up" && fabs(p.cl_eta()) >= 1.1 && fabs(p.cl_eta()) < 1.5 )		  scaleVar = egEnergyCorr::Scale::MatIDUp;
    else if (doSystematic == "ElectronScaleMatID2Dn" && fabs(p.cl_eta()) >= 1.1 && fabs(p.cl_eta()) < 1.5 )		  scaleVar = egEnergyCorr::Scale::MatIDDown;
    else if (doSystematic == "ElectronScaleMatID3Up" && fabs(p.cl_eta()) >= 1.5 && fabs(p.cl_eta()) < 2.1 )		  scaleVar = egEnergyCorr::Scale::MatIDUp;
    else if (doSystematic == "ElectronScaleMatID3Dn" && fabs(p.cl_eta()) >= 1.5 && fabs(p.cl_eta()) < 2.1 )		  scaleVar = egEnergyCorr::Scale::MatIDDown;
    else if (doSystematic == "ElectronScaleMatID4Up" && fabs(p.cl_eta()) >= 2.1 )		 scaleVar = egEnergyCorr::Scale::MatIDUp;
    else if (doSystematic == "ElectronScaleMatID4Dn" && fabs(p.cl_eta()) >= 2.1 )		 scaleVar = egEnergyCorr::Scale::MatIDDown;
    else if (doSystematic == "ElectronScaleMatCryoBarrelUp" && fabs(p.cl_eta()) < 1.6 ) 	 scaleVar = egEnergyCorr::Scale::MatCryoUp;
    else if (doSystematic == "ElectronScaleMatCryoBarrelDn" && fabs(p.cl_eta()) < 1.6 ) 	 scaleVar = egEnergyCorr::Scale::MatCryoDown;
    else if (doSystematic == "ElectronScaleMatCryoEndcapUp" && fabs(p.cl_eta()) >= 1.6 ) 	 scaleVar = egEnergyCorr::Scale::MatCryoUp;
    else if (doSystematic == "ElectronScaleMatCryoEndcapDn" && fabs(p.cl_eta()) >= 1.6 ) 	 scaleVar = egEnergyCorr::Scale::MatCryoDown;
    else if (doSystematic == "ElectronScaleMatCaloBarrelUp" && fabs(p.cl_eta()) < 1.4 ) 	 scaleVar = egEnergyCorr::Scale::MatCaloUp;
    else if (doSystematic == "ElectronScaleMatCaloBarrelDn" && fabs(p.cl_eta()) < 1.4 ) 	 scaleVar = egEnergyCorr::Scale::MatCaloDown;
    else if (doSystematic == "ElectronScaleMatCaloEndcapUp" && fabs(p.cl_eta()) >= 1.4 ) 	 scaleVar = egEnergyCorr::Scale::MatCaloUp;
    else if (doSystematic == "ElectronScaleMatCaloEndcapDn" && fabs(p.cl_eta()) >= 1.4 ) 	 scaleVar = egEnergyCorr::Scale::MatCaloDown;
    else if (doSystematic == "ElectronScaleLArCalibBarrelUp" && fabs(p.cl_eta()) < 1.4 )   	 scaleVar = egEnergyCorr::Scale::LArCalibUp;
    else if (doSystematic == "ElectronScaleLArCalibBarrelDn" && fabs(p.cl_eta()) < 1.4 ) 	 scaleVar = egEnergyCorr::Scale::LArCalibDown;
    else if (doSystematic == "ElectronScaleLArCalibEndcapUp" && fabs(p.cl_eta()) >= 1.4 )      scaleVar = egEnergyCorr::Scale::LArCalibUp;
    else if (doSystematic == "ElectronScaleLArCalibEndcapDn" && fabs(p.cl_eta()) >= 1.4 )      scaleVar = egEnergyCorr::Scale::LArCalibDown;
    else if (doSystematic == "ElectronScaleLArUnconvCalibBarrelUp" && fabs(p.cl_eta()) < 1.4 )   scaleVar = egEnergyCorr::Scale::LArUnconvCalibUp;
    else if (doSystematic == "ElectronScaleLArUnconvCalibBarrelDn" && fabs(p.cl_eta()) < 1.4 )   scaleVar = egEnergyCorr::Scale::LArUnconvCalibDown;
    else if (doSystematic == "ElectronScaleLArUnconvCalibEndcapUp" && fabs(p.cl_eta()) >= 1.4 && fabs(p.cl_eta()) < 1.8 )   scaleVar = egEnergyCorr::Scale::LArUnconvCalibUp;
    else if (doSystematic == "ElectronScaleLArUnconvCalibEndcapDn" && fabs(p.cl_eta()) >= 1.4 && fabs(p.cl_eta()) < 1.8 )   scaleVar = egEnergyCorr::Scale::LArUnconvCalibDown;
    else if (doSystematic == "ElectronScaleLArElecUnconvBarrelUp" && fabs(p.cl_eta()) < 1.4 )	 scaleVar = egEnergyCorr::Scale::LArElecUnconvUp;
    else if (doSystematic == "ElectronScaleLArElecUnconvBarrelDn" && fabs(p.cl_eta()) < 1.4 )	 scaleVar = egEnergyCorr::Scale::LArElecUnconvDown;
    else if (doSystematic == "ElectronScaleLArElecUnconvEndcapUp" && fabs(p.cl_eta()) >= 1.4 && fabs(p.cl_eta()) < 1.8 )	 scaleVar = egEnergyCorr::Scale::LArElecUnconvUp;
    else if (doSystematic == "ElectronScaleLArElecUnconvEndcapDn" && fabs(p.cl_eta()) >= 1.4 && fabs(p.cl_eta()) < 1.8 )	 scaleVar = egEnergyCorr::Scale::LArElecUnconvDown;
    else if (doSystematic == "ElectronScaleLArElecCalibUp" && fabs(p.cl_eta()) >= 1.8 )        scaleVar = egEnergyCorr::Scale::LArElecCalibUp;
    else if (doSystematic == "ElectronScaleLArElecCalibDn" && fabs(p.cl_eta()) >= 1.8 )        scaleVar = egEnergyCorr::Scale::LArElecCalibDown;
    else if (doSystematic == "ElectronScaleL1GainUp")   	scaleVar = egEnergyCorr::Scale::L1GainUp;
    else if (doSystematic == "ElectronScaleL1GainDn") 		scaleVar = egEnergyCorr::Scale::L1GainDown;
    else if (doSystematic == "ElectronScaleL2GainUp")   	scaleVar = egEnergyCorr::Scale::L2GainUp;
    else if (doSystematic == "ElectronScaleL2GainDn") 		scaleVar = egEnergyCorr::Scale::L2GainDown;
    else if (doSystematic == "ElectronScaleG4Up")   		scaleVar = egEnergyCorr::Scale::G4Up;
    else if (doSystematic == "ElectronScaleG4Dn") 		scaleVar = egEnergyCorr::Scale::G4Down;
    else if (doSystematic == "ElectronScalePedestalUp")   	scaleVar = egEnergyCorr::Scale::PedestalUp;
    else if (doSystematic == "ElectronScalePedestalDn") 	scaleVar = egEnergyCorr::Scale::PedestalDown;  
  }
  
  egEnergyCorr::Resolution::Variation res = egEnergyCorr::Resolution::Nominal;
  if (doSystematic != ""){
    if (doSystematic == "ElectronResolutionZSmearingUp")   		res = egEnergyCorr::Resolution::ZSmearingUp;
    else if (doSystematic == "ElectronResolutionZSmearingDn") 		res = egEnergyCorr::Resolution::ZSmearingDown;
    else if (doSystematic == "ElectronResolutionSamplingTermUp")   	res = egEnergyCorr::Resolution::SamplingTermUp;
    else if (doSystematic == "ElectronResolutionSamplingTermDn") 	res = egEnergyCorr::Resolution::SamplingTermDown;
    else if (doSystematic == "ElectronResolutionMaterialIDUp")   	res = egEnergyCorr::Resolution::MaterialIDUp;
    else if (doSystematic == "ElectronResolutionMaterialIDDn") 		res = egEnergyCorr::Resolution::MaterialIDDown;
    else if (doSystematic == "ElectronResolutionMaterialCaloUp")   	res = egEnergyCorr::Resolution::MaterialCaloUp;
    else if (doSystematic == "ElectronResolutionMaterialCaloDn") 	res = egEnergyCorr::Resolution::MaterialCaloDown;
    else if (doSystematic == "ElectronResolutionMaterialGapUp")   	res = egEnergyCorr::Resolution::MaterialGapUp;
    else if (doSystematic == "ElectronResolutionMaterialGapDn") 	res = egEnergyCorr::Resolution::MaterialGapDown;
    else if (doSystematic == "ElectronResolutionMaterialCryoUp")   	res = egEnergyCorr::Resolution::MaterialCryoUp;
    else if (doSystematic == "ElectronResolutionMaterialCryoDn") 	res = egEnergyCorr::Resolution::MaterialCryoDown;
    else if (doSystematic == "ElectronResolutionPileUpUp")   		res = egEnergyCorr::Resolution::PileUpUp;
    else if (doSystematic == "ElectronResolutionPileUpDn") 		res = egEnergyCorr::Resolution::PileUpDown;
  }
  
  if(is_data()){
    m_logger<<::DEBUG<< "Applying energy scale corrections to photon in data"  << SLogger::endmsg;
    dataType=PATCore::ParticleDataType::Data;
  }else{
    m_logger<<::DEBUG<< "Applying energy smearing to photon in MC "  << SLogger::endmsg;
    dataType=PATCore::ParticleDataType::Full;
  }
  m_eRescaler->setRandomSeed(EventNumber+100*p.GetIndex());
  
  if ( p.author() == 4 || p.author() == 16 ) {
    
    /* 
    m_logger<<::DEBUG<< "p.rawcl_Es0():       " <<    p.rawcl_Es0()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.rawcl_Es1():	      " <<   p.rawcl_Es1()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.rawcl_Es2():	      " <<   p.rawcl_Es2()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.rawcl_Es3():	      " <<   p.rawcl_Es3()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.cl_eta():	      " <<   p.cl_eta()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.cl_phi():	      " <<   p.cl_phi()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.cl_E():	      " <<   p.cl_E()		    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.cl_etaCalo():      " <<    p.cl_etaCalo()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.cl_phiCalo():      " <<    p.cl_phiCalo()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.ptconv():	      " <<   p.ptconv()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.pt1conv():	      " <<   p.pt1conv()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.pt2conv():	      " <<   p.pt2conv()	    << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.convtrk1nPixHits():" <<    p.convtrk1nPixHits() << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.convtrk1nSCTHits():" <<    p.convtrk1nSCTHits() << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.convtrk2nPixHits():" <<    p.convtrk2nPixHits() << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.convtrk2nSCTHits():" <<    p.convtrk2nSCTHits() << SLogger::endmsg;
    m_logger<<::DEBUG<< "p.Rconv():	      " <<   p.Rconv()		    << SLogger::endmsg;
    */
    E_corrected = m_eRescaler->getCorrectedEnergy((unsigned int)RunNumber,
						dataType,
						AtlasRoot::egammaEnergyCorrectionTool::ParticleInformation(p.rawcl_Es0(),
													   p.rawcl_Es1(),
													   p.rawcl_Es2(),
													   p.rawcl_Es3(),
													   p.cl_eta(),
													   p.cl_phi(),
													   p.cl_E(),
													   p.cl_etaCalo(),
													   p.cl_phiCalo(),
													   p.ptconv(),
													   p.pt1conv(),
													   p.pt2conv(),
													   p.convtrk1nPixHits(),
													   p.convtrk1nSCTHits(),
													   p.convtrk2nPixHits(),
													   p.convtrk2nSCTHits(),
													   p.Rconv()),
						scaleVar,
						res);//,
						//egEnergyCorr::Resolution::SigmaEff90,
						//1.0 );
  }						
  
  m_logger<<::DEBUG<< "Original energy: " << E_uncorrected << " corrected energy: "<< E_corrected << SLogger::endmsg;
  
  p.Set_cl_E(E_corrected);
  
  return;
}
                                                                                                                                                       
//____________________________________________________________________________
void EnergyRescalerTool::ApplyEnergyRescaler(std::vector<Jet>& jets, double mu, unsigned int npv, double Eventshape)
{

    for (unsigned int i = 0; i < jets. size(); ++i){
        ApplyEnergyRescaler(jets[i], mu, npv, Eventshape);
    }
    
    //calculate drmin/fcloseby for all jets

    for (unsigned int i = 0; i < jets. size(); ++i){
      double fcloseby = 0;

      for (unsigned int j = 0; j < jets. size(); ++j){
	 if (i==j) continue;
	 if (jets[j].Pt() < 12000) continue;
	 if (jets[j].TLV().DeltaR(jets[i].TLV()) > 1.1) continue;
	 fcloseby += jets[i].TLV().Vect().Dot(jets[j].TLV().Vect()) / pow(jets[i].TLV().P(),2) ; // close-by fraction
      }
      if (fcloseby >= 1.5) fcloseby = 1.4999999; //FIX - ask about this!
      //m_logger<<::WARNING<< "fcloseby: " << fcloseby << SLogger::endmsg;

      jets[i].SetfCloseby( fcloseby );  
    }
}


//____________________________________________________________________________
void EnergyRescalerTool::ApplyEnergyRescaler(Jet& j,double mu, unsigned int npv, double Eventshape)
{

  //double mu=averageIntPerXing = (lbn==1 && int(averageIntPerXing+0.5)==1) ? 0. : averageIntPerXing
    
  double Eraw    = j.emscale_E();
  double eta     = j.emscale_eta();
  double phi     = j.emscale_phi();
  double m       = j.emscale_m();
  double Ax      = j.ActiveAreaPx();
  double Ay      = j.ActiveAreaPy();
  double Az      = j.ActiveAreaPz();
  double Ae      = j.ActiveAreaE();

  TLorentzVector cal_jet = m_JetRescaler->ApplyJetAreaOffsetEtaJES(Eraw,eta,phi,m,Ax,Ay,Az,Ae,Eventshape,mu,npv);  
     
  j.SetVector(cal_jet);  

  return;
}

//____________________________________________________________________________
void EnergyRescalerTool::ApplyJetSystematic( std::vector<Jet> &jets, double mu, unsigned int npv, const int event_number, int syst)
{
  for (unsigned int i = 0; i< jets.size(); ++i){
    TLorentzVector cal_jet = jets[i].TLV(); 
  
    //systematic variations
    if (!(cal_jet.Pt() > 15000 && abs(cal_jet.Eta())<4 )) continue;
    
    double eta = jets[i].emscale_eta();
    
    double jes_rel_unc = 0.0;

    bool vary_up = (syst%2 == 0); 

    if(syst/2 == 1)      jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Statistical1",cal_jet.Pt(),eta);
    else if(syst/2 == 2) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Statistical2",cal_jet.Pt(),eta);
    else if(syst/2 == 3) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Statistical3",cal_jet.Pt(),eta);

    else if(syst/2 == 4) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Modelling1",cal_jet.Pt(),eta);
    else if(syst/2 == 5) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Modelling2",cal_jet.Pt(),eta);
    else if(syst/2 == 6) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Modelling3",cal_jet.Pt(),eta);
    else if(syst/2 == 7) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Modelling4",cal_jet.Pt(),eta);

    else if(syst/2 == 8) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Detector1",cal_jet.Pt(),eta);
    else if(syst/2 == 9) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Detector2",cal_jet.Pt(),eta);
    else if(syst/2 == 10) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Detector3",cal_jet.Pt(),eta);

    else if(syst/2 == 11) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Mixed1",cal_jet.Pt(),eta);
    else if(syst/2 == 12) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EffectiveNP_Mixed2",cal_jet.Pt(),eta);

    else if(syst/2 == 13) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EtaIntercalibration_Modelling",cal_jet.Pt(),cal_jet.Eta());
    else if(syst/2 == 14) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("EtaIntercalibration_StatAndMethod",cal_jet.Pt(),eta);

    else if(syst/2 == 15) jes_rel_unc = m_JetUncertainties->getRelUncertComponent("SingleParticle_HighPt",cal_jet.Pt(),eta);

    else if(syst/2 == 16) jes_rel_unc = m_JetUncertainties->getRelNPVOffsetTerm(cal_jet.Pt(),cal_jet.Eta(),npv);
    else if(syst/2 == 17) jes_rel_unc = m_JetUncertainties->getRelMuOffsetTerm(cal_jet.Pt(),cal_jet.Eta(),mu);
    else if(syst/2 == 18) jes_rel_unc = m_JetUncertainties->getRelPileupPtTerm(cal_jet.Pt(),cal_jet.Eta(),npv,mu);
    else if(syst/2 == 19) jes_rel_unc = m_JetUncertainties->getRelPileupRhoTopology(cal_jet.Pt(),eta);
    else if(syst/2 == 20) jes_rel_unc = m_JetUncertainties->getRelClosebyUncert(cal_jet.Pt(),jets[i].fCloseby());
    else if(syst/2 == 21) jes_rel_unc = m_JetUncertainties->getRelFlavorCompUncert(cal_jet.Pt(),eta, vary_up);
    else if(syst/2 == 22) jes_rel_unc = m_JetUncertainties->getRelFlavorResponseUncert(cal_jet.Pt(),eta); 
    else if(syst == 46){
      m_JERTool->SetSeed(event_number);
      m_JERTool->SmearJet_Syst(cal_jet);
    } else {
      m_logger<<::WARNING << "Uknown Jet systematic #: "<< syst << SLogger::endmsg;   
    }

    //m_logger<< ::DEBUG << "JES systematic: "<< syst << " jet pT: " << cal_jet.Pt()<< " eta: "<< eta << " uncertainty: " << jes_rel_unc << SLogger::endmsg;   

    if(vary_up) cal_jet *= (1+jes_rel_unc);
    else	cal_jet *= (1-jes_rel_unc);

    jets[i].SetVector(cal_jet);  
  }
  
  return;  
}
