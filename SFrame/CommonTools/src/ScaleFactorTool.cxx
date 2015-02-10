//Root include(s):
#include "TLorentzVector.h"

#include "../include/ScaleFactorTool.h"

//ClassImp( ScaleFactorTool )

//____________________________________________________________________________         
ScaleFactorTool::ScaleFactorTool(SCycleBase* parent, const char* name)
    : ToolBase(parent, name)
{
 
}

//____________________________________________________________________________         
void ScaleFactorTool::BeginInputData( const SInputData& )
{

  m_logger << DEBUG << "Initializing Tile Trip Reader" << SLogger::endmsg;
  
  tiletrip_tool = new Root::TTileTripReader("myTripReader");

  m_logger << DEBUG << "Initializing BCH cleaning tool" << SLogger::endmsg;
 
  std::string path_BCH = "$ROOTCOREBIN/data/BCHCleaningTool/FractionsRejectedJetsMC.root";

  BCHcleaning_tool = new BCHTool::BCHCleaningToolRoot("myCleaningTool");
  BCHcleaning_tool->InitializeTool(is_data(), tiletrip_tool, path_BCH);
      
  if(is_data()) return;

  m_logger << DEBUG << "Initializing Lepton Trigger SF" << SLogger::endmsg;

  std::string trig_file = "";
  std::string eg_file   = "";
  if (get_mctype() == AtlasSFrame::MC12a || get_mctype() == AtlasSFrame::MC12b) {
    trig_file = "muon_trigger_sf_2012_AtoL.p1328.root";
    eg_file   = "rel17p2.v07";
  } else if (get_mctype() == AtlasSFrame::MC12c) {
    trig_file = "muon_trigger_sf_2012_AtoL.p1328.root";
    eg_file   = "rel17p2.GEO21.v01";
  } else {
    m_logger << WARNING << "Unrecognized MC type:"<< get_mctype() << SLogger::endmsg;  
  }  
  m_TriggerSF = new LeptonTriggerSF(2012, "$ROOTCOREBIN/data/TrigMuonEfficiency/", trig_file, "$ROOTCOREBIN/data/ElectronEfficiencyCorrection/",eg_file);
    

  m_logger << DEBUG << "Initializing Electron SF" << SLogger::endmsg;
  
  egammaRecoSFTool = new Root::TElectronEfficiencyCorrectionTool();
  if (get_mctype() == AtlasSFrame::MC12a || get_mctype() == AtlasSFrame::MC12b) {
    egammaRecoSFTool->addFileName("$ROOTCOREBIN/data/ElectronEfficiencyCorrection/efficiencySF.offline.RecoTrk.2012.8TeV.rel17p2.GEO20.v08.root");
  } else if (get_mctype() == AtlasSFrame::MC12c) {
    egammaRecoSFTool->addFileName("$ROOTCOREBIN/data/ElectronEfficiencyCorrection/efficiencySF.offline.RecoTrk.2012.8TeV.rel17p2.GEO21.v01.root");  
  } else {
    m_logger << WARNING << "Unrecognized MC type:"<< get_mctype() << SLogger::endmsg;  
  }
  egammaRecoSFTool->initialize();

  egammaIDSFTool = new Root::TElectronEfficiencyCorrectionTool();
  if (get_mctype() == AtlasSFrame::MC12a || get_mctype() == AtlasSFrame::MC12b) {
    egammaIDSFTool->addFileName("$ROOTCOREDIR/data/ElectronEfficiencyCorrection/efficiencySF.offline.LooseLLH.2012.8TeV.rel17p2.v07.root");
  } else if(get_mctype() == AtlasSFrame::MC12c) {
    egammaIDSFTool->addFileName("$ROOTCOREDIR/data/ElectronEfficiencyCorrection/efficiencySF.offline.LooseLLH.2012.8TeV.rel17p2.GEO21.v01.root");  
  } else {
    m_logger << WARNING << "Unrecognized MC type:"<< get_mctype() << SLogger::endmsg;  
  }
  egammaIDSFTool->initialize();

  m_logger << DEBUG << "Initializing Pileup SF" << SLogger::endmsg;

  //pileup reweighting tool
  pileup_tool = new Root::TPileupReweighting( "PileupReweightingTool" );
  pileup_tool->SetUnrepresentedDataAction(2);
  if (get_mctype() == AtlasSFrame::MC12a) {
    pileup_tool->AddConfigFile(  sframe_dir()+"/config/lumi/MC12a.prw.root"); //SH: no afs on GRID, need to be in top level dir to run it...
    pileup_tool->SetDefaultChannel(160156);
  }
  if (get_mctype() == AtlasSFrame::MC12b || get_mctype() == AtlasSFrame::MC12c) {
    pileup_tool->AddConfigFile(  sframe_dir()+"/config/lumi/MC12b.prw.root"); //SH: no afs on GRID, need to be in top level dir to run it...
    pileup_tool->SetDefaultChannel(181341);
  }
  pileup_tool->AddLumiCalcFile(sframe_dir()+"/config/lumi/ilumicalc_2012_AllYear_All_Good.root"); //SH: no afs on GRID, need to be in top level dir to run it...
  pileup_tool->Initialize();   

  double period2012A=pileup_tool->GetIntegratedLumi(200804,201556);
  double period2012B=pileup_tool->GetIntegratedLumi(202660,205113);
  double period2012C=pileup_tool->GetIntegratedLumi(206248,207397);
  double period2012D=pileup_tool->GetIntegratedLumi(207447,209025);
  double period2012E=pileup_tool->GetIntegratedLumi(209074,210308);
  //double period2012F=0.0;
  double period2012G=pileup_tool->GetIntegratedLumi(211522,212272);
  double period2012H=pileup_tool->GetIntegratedLumi(212619,213359);
  double period2012I=pileup_tool->GetIntegratedLumi(213431,213819);
  double period2012J=pileup_tool->GetIntegratedLumi(213900,215091);
  //double period2012K=0.0;
  double period2012L=pileup_tool->GetIntegratedLumi(215414,215643);
  double period2012M=pileup_tool->GetIntegratedLumi(216399,216432);

  m_logger << DEBUG << "Period A: " << period2012A << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period B: " << period2012B << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period C: " << period2012C << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period D: " << period2012D << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period E: " << period2012E << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period G: " << period2012G << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period H: " << period2012H << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period I: " << period2012I << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period J: " << period2012J << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period L: " << period2012L << " pb-1 " << SLogger::endmsg;
  m_logger << DEBUG << "Period M: " << period2012M << " pb-1 " << SLogger::endmsg;
  m_logger << INFO << "Integrated Lumi: " << pileup_tool->GetIntegratedLumi() << " pb-1 " << SLogger::endmsg;

  m_logger << DEBUG << "Initializing Muon SF" << SLogger::endmsg;

  std::string directoryNoRootCore = sframe_dir()+"/RootCore/MuonEfficiencyCorrections/share/";  
  std::string muon_type_staco ("STACO_CB_plus_ST_2012_SF.txt.gz"); 
  std::string muon_type_staco_sa("STACO_CB_plus_ST_2012_SFms.txt.gz"); 
  std::string muon_type_calo_mu ("CaloTag_2012_SF.txt.gz");    
  //std::string muon_type_muid ("Muid_CB_plus_ST_2012_SF.txt.gz");
  //std::string muon_type_muid_sa ("Muid_CB_plus_ST_2012_SFms.txt.gz");
  std::string unit = "MeV"; 

  /// NEEDED TO PREVENT CRASH!
  TH1::AddDirectory(kFALSE);
     
  //MuidSCF=new Analysis::AnalysisMuonConfigurableScaleFactors (directoryNoRootCore,muon_type_muid,unit,Analysis::AnalysisMuonConfigurableScaleFactors::AverageOverPeriods);
  //MuidSCF->Initialise();

  //MuidSASCF=new Analysis::AnalysisMuonConfigurableScaleFactors (directoryNoRootCore,muon_type_muid_sa,unit,Analysis::AnalysisMuonConfigurableScaleFactors::AverageOverPeriods);
  //MuidSASCF->Initialise();   

  StacoSCF = new Analysis::AnalysisMuonConfigurableScaleFactors (directoryNoRootCore,muon_type_staco,unit,Analysis::AnalysisMuonConfigurableScaleFactors::AverageOverPeriods); 
  StacoSCF->addPeriod("A",period2012A);
  StacoSCF->addPeriod("B",period2012B);
  StacoSCF->addPeriod("C",period2012C);
  StacoSCF->addPeriod("D",period2012D);
  StacoSCF->addPeriod("E",period2012E);
  StacoSCF->addPeriod("G",period2012G);
  StacoSCF->addPeriod("H",period2012H);
  StacoSCF->addPeriod("I",period2012I);
  StacoSCF->addPeriod("J",period2012J);
  StacoSCF->addPeriod("L",period2012L);
  StacoSCF->Initialise(); 
  
  StacoSASCF = new Analysis::AnalysisMuonConfigurableScaleFactors (directoryNoRootCore,muon_type_staco_sa,unit,Analysis::AnalysisMuonConfigurableScaleFactors::AverageOverPeriods); 
  StacoSASCF->addPeriod("A",period2012A);
  StacoSASCF->addPeriod("B",period2012B);
  StacoSASCF->addPeriod("C",period2012C);
  StacoSASCF->addPeriod("D",period2012D);
  StacoSASCF->addPeriod("E",period2012E);
  StacoSASCF->addPeriod("G",period2012G);
  StacoSASCF->addPeriod("H",period2012H);
  StacoSASCF->addPeriod("I",period2012I);
  StacoSASCF->addPeriod("J",period2012J);
  StacoSASCF->addPeriod("L",period2012L);
  StacoSASCF->Initialise(); 
  
  CaloMuSCF = new Analysis::AnalysisMuonConfigurableScaleFactors (directoryNoRootCore,muon_type_calo_mu,unit,Analysis::AnalysisMuonConfigurableScaleFactors::AverageOverPeriods); 
  CaloMuSCF->addPeriod("A",period2012A);
  CaloMuSCF->addPeriod("B",period2012B);
  CaloMuSCF->addPeriod("C",period2012C);
  CaloMuSCF->addPeriod("D",period2012D);
  CaloMuSCF->addPeriod("E",period2012E);
  CaloMuSCF->addPeriod("G",period2012G);
  CaloMuSCF->addPeriod("H",period2012H);
  CaloMuSCF->addPeriod("I",period2012I);
  CaloMuSCF->addPeriod("J",period2012J);
  CaloMuSCF->addPeriod("L",period2012L);
  CaloMuSCF->Initialise(); 

  /// NEEDED TO PREVENT CRASH!
  TH1::AddDirectory(kTRUE);
    
  m_logger << DEBUG << "Initializing vertex SF" << SLogger::endmsg;
  
  std::string path3NoRootCore = sframe_dir()+"/RootCore/egammaAnalysisUtils/share/zvtx_weights_2011_2012.root";
  if(get_mctype() == AtlasSFrame::MC11){ 
    if ( true ) { //physicsObject->mc_channel_number==105200){ 
      //// 2011 data and MC11 with wide z-beam spot 
      vertex_tool= new VertexPositionReweightingTool(std::string("s1272"),path3NoRootCore); 
    }else{ 
      //// 2011 data and MC11 with narrow z-beam spot 
      vertex_tool= new VertexPositionReweightingTool(std::string("s1310"),path3NoRootCore); 
    } 
  } else {
    //// 2012 data and MC12a/b/c 
    vertex_tool= new VertexPositionReweightingTool(VertexPositionReweightingTool::MC12a,path3NoRootCore);
  }
  
  m_logger << DEBUG << "Initializing Higgs Pt Reweighting SF" << SLogger::endmsg;
 
  ggf_reweight_tool = new ggFReweighting("PowHeg", 125, "Mean", sframe_dir()+"/RootCore/ggFReweighting/share/", "mc11");

  m_logger << DEBUG << "Initializing QCD Scale Reweighting SF" << SLogger::endmsg;

  //TODO Is mc11 the correct option for mc12 also?
  char option [10];
  for (int i = 1; i < 14; i++){  
    sprintf(option, "Scale%i",i);    
    ggf_qcd_tool.push_back(new ggFReweighting("PowHeg", 120, option, sframe_dir()+"/RootCore/ggFReweighting/share/", "mc11"));
  }

  for (int i = 1; i < 41; i++){  
    sprintf(option, "Pdfset%i",i);    
    ggf_pdf_tool.push_back(new ggFReweighting("PowHeg", 120, option, sframe_dir()+"/RootCore/ggFReweighting/share/", "mc11"));
  }
  
  return;

}

//____________________________________________________________________________         
double ScaleFactorTool::LeptonSF(Quadruplet* quad, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, Systematic syst){
    
  std::vector<double> lepton_sf;

  return LeptonSF(quad, m_event_d3pdobject, lepton_sf, syst);
}  
      
//____________________________________________________________________________         
double ScaleFactorTool::LeptonSF(Quadruplet* quad, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject,std::vector<double> &lepton_sf, Systematic syst){
  
  if(is_data()) return 1.0;
  
  double sf = 1.0;

  //pileup_tool->SetRandomSeed(314159+m_event_d3pdobject->mc_channel_number()*2718+m_event_d3pdobject->EventNumber());
  double run_number_sf = pileup_tool->GetRandomRunNumber(m_event_d3pdobject->RunNumber());

  //muons first
  std::vector<Muon*> q_muons;
  quad->GetMuons( q_muons );
  for (unsigned int i = 0; i < q_muons.size(); i++){    
    
    double SF = 1.0;
    double SF_err = 0.;
    if (q_muons.at(i)->isStandAloneMuon()){
      SF     = StacoSASCF->scaleFactor(q_muons.at(i)->charge(), *q_muons.at(i)->TLV());
      SF_err = StacoSASCF->scaleFactorUncertainty(q_muons.at(i)->charge(), *q_muons.at(i)->TLV()) + StacoSASCF->scaleFactorSystematicUncertainty(q_muons.at(i)->charge(), *q_muons.at(i)->TLV());
    
    } else if (q_muons.at(i)->isCaloMuon()){
      SF     = CaloMuSCF->scaleFactor(q_muons.at(i)->charge(), *q_muons.at(i)->TLV());
      SF_err = CaloMuSCF->scaleFactorUncertainty(q_muons.at(i)->charge(), *q_muons.at(i)->TLV()) + CaloMuSCF->scaleFactorSystematicUncertainty(q_muons.at(i)->charge(), *q_muons.at(i)->TLV());
    
    } else {
      SF     = StacoSCF->scaleFactor(q_muons.at(i)->charge(), *q_muons.at(i)->TLV());    
      SF_err = StacoSCF->scaleFactorUncertainty(q_muons.at(i)->charge(), *q_muons.at(i)->TLV()) + StacoSCF->scaleFactorSystematicUncertainty(q_muons.at(i)->charge(), *q_muons.at(i)->TLV());
   }
    
    if (syst == MuonIDReco) SF += SF_err;
    lepton_sf.push_back(SF);
    sf *= SF;
  }

  //electrons second
  std::vector<Electron*>  q_electrons;
  quad->GetElectrons( q_electrons );
    
  for (unsigned int i = 0; i < q_electrons.size(); i++){
   
    double calibrated_et = q_electrons[i]->calibrated_E()/cosh(q_electrons[i]->tracketa());
   
    //ID Efficiency
    const Root::TResult &result_id = egammaIDSFTool->calculate(PATCore::ParticleDataType::Full, run_number_sf, q_electrons.at(i)->cl_eta(), calibrated_et);
    if ( result_id.getScaleFactor() == 0) m_logger << WARNING << "Electron ID SF == 0! eta=" << q_electrons.at(i)->cl_eta()<< " Et=" << calibrated_et << SLogger::endmsg;
    
    //Reco Efficiency
    const Root::TResult &result_reco = egammaRecoSFTool->calculate(PATCore::ParticleDataType::Full, run_number_sf, q_electrons.at(i)->cl_eta(), calibrated_et);
    if ( result_reco.getScaleFactor() == 0) m_logger << WARNING << "Electron Reco SF == 0! eta=" << q_electrons.at(i)->cl_eta()<< " Et=" << calibrated_et << SLogger::endmsg;
    
    double SF_Reco 		= result_reco.getScaleFactor(); 
    double SF_Reco_total 	= result_reco.getTotalUncertainty(); 
    double SF_Reco_stat 	= result_reco.getResult(4); 
    double SF_Reco_stat_rel	= SF_Reco_stat/SF_Reco; 
    double SF_Reco_syst 	= sqrt(SF_Reco_total*SF_Reco_total-SF_Reco_stat*SF_Reco_stat); 
    double SF_Reco_syst_rel	= SF_Reco_syst/SF_Reco; 

    double SF_ID 		= result_id.getScaleFactor(); 
    double SF_ID_total 		= result_id.getTotalUncertainty(); 
    double SF_ID_stat 		= result_id.getResult(4); 
    double SF_ID_stat_rel	= SF_ID_stat/SF_ID; 
    double SF_ID_syst 		= sqrt(SF_ID_total*SF_ID_total-SF_ID_stat*SF_ID_stat); 
    double SF_ID_syst_rel	= SF_ID_syst/SF_ID; 

    double SF_stat_rel 	= sqrt(SF_Reco_stat_rel*SF_Reco_stat_rel+SF_ID_stat_rel*SF_ID_stat_rel); 
    
    double rel_err = 0;
    
    if (syst == ElectronRecoLow    && q_electrons[i]->cl_Et() < 15000) rel_err = SF_Reco_syst_rel;
    if (syst == ElectronRecoHigh   && q_electrons[i]->cl_Et() > 15000) rel_err = SF_Reco_syst_rel;
    if (syst == ElectronIDLow      && q_electrons[i]->cl_Et() < 20000) rel_err = SF_ID_syst_rel;
    if (syst == ElectronStat15     && q_electrons[i]->cl_Et() > 15000 && q_electrons[i]->cl_Et() < 20000) rel_err = SF_stat_rel;
    if (syst == ElectronStat10     && q_electrons[i]->cl_Et() > 10000 && q_electrons[i]->cl_Et() < 15000) rel_err = SF_stat_rel;
    if (syst == ElectronStat7      && q_electrons[i]->cl_Et() > 7000  && q_electrons[i]->cl_Et() < 10000) rel_err = SF_stat_rel;
    if (syst == ElectronIDStatHigh && q_electrons[i]->cl_Et() > 20000) rel_err = sqrt(SF_ID_syst_rel*SF_ID_syst_rel+SF_stat_rel*SF_stat_rel);
	 
    double SF = fabs(SF_ID*SF_Reco)*(1+rel_err);
        
    m_logger << DEBUG << "Electron SF: eta=" << q_electrons.at(i)->cl_eta()<< " et=" << calibrated_et<< " run=" <<run_number_sf << " SF="<<SF<< SLogger::endmsg;

    lepton_sf.push_back(SF);
    sf *= SF;

  }
  
  return sf;
}


//____________________________________________________________________________         
double ScaleFactorTool::TriggerSF(Quadruplet* quad, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, Systematic syst){
  
  if(is_data()) return 1.0;
  
  double sf = 1.0;
  
  pileup_tool->SetRandomSeed(314159+m_event_d3pdobject->mc_channel_number()*2718+m_event_d3pdobject->EventNumber());
  double run_number_sf = pileup_tool->GetRandomRunNumber(m_event_d3pdobject->RunNumber());

  std::vector<Muon*> muons;  
  quad->GetMuons( muons );

  std::vector<TLorentzVector> tlv_muons;
  std::vector<MuonQuality> muonquality;
  for (unsigned int i = 0; i < muons.size(); i++){    
    tlv_muons.push_back(*(muons[i]->TLV()));
    if (muons[i]->isCaloMuon()){
      muonquality.push_back(CaloMuon);
    } else {
      muonquality.push_back(loose);    
    }
  }

  std::vector<Electron*> electrons;
  quad->GetElectrons( electrons );

  std::vector<TLorentzVector> tlv_electrons;
  std::vector<ElectronQuality> electronquality;
  for (unsigned int i = 0; i < electrons.size(); i++) {
    tlv_electrons.push_back( TLorentzVector() );
    tlv_electrons[i].SetPtEtaPhiE(electrons[i]->calibrated_E()/cosh(electrons[i]->tracketa()), electrons[i]->cl_eta(), electrons[i]->cl_phi(), electrons[i]->calibrated_E());
    electronquality.push_back(LooseLLH);
  }

  int option = 0;
  if (syst == ElectronTrigger) option = 3;
  if (syst == MuonTrigger)     option = 5;

  pair<double,double> SF = m_TriggerSF->GetTriggerSF(run_number_sf,false, tlv_muons, muonquality, tlv_electrons, electronquality, option);
  sf = sf*SF.first;	
  
  if (sf != sf){
     m_logger << WARNING << "NAN returned from trigger SF tool with option "<< option << " and run number "<< run_number_sf<< SLogger::endmsg;

     m_logger << WARNING << "Electrons Pt Eta Phi M:"<< SLogger::endmsg;
     for (unsigned int i = 0; i < tlv_electrons.size(); i++) {
       m_logger << WARNING << tlv_electrons[i].Pt() <<" "<<tlv_electrons[i].Eta() <<" "<<tlv_electrons[i].Phi() <<" "<<tlv_electrons[i].M() << SLogger::endmsg;
     }
     m_logger << WARNING << "Muons Pt Eta Phi M:"<< SLogger::endmsg;
     for (unsigned int i = 0; i < tlv_muons.size(); i++) {
       m_logger << WARNING << tlv_muons[i].Pt() <<" "<<tlv_muons[i].Eta() <<" "<<tlv_muons[i].Phi() <<" "<<tlv_muons[i].M() << SLogger::endmsg;
     }
  }
  
  return sf;
}


//____________________________________________________________________________         
double ScaleFactorTool::PileupSF(const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject){

  if(is_data()) return 1.0;

  double weight = 1.0;
  
  double mu = m_event_d3pdobject->averageIntPerXing();
  if (get_mctype() == AtlasSFrame::MC12a)
    mu = (m_event_d3pdobject->lbn()==1 && int(m_event_d3pdobject->averageIntPerXing()+0.5)==1) ? 0. : m_event_d3pdobject->averageIntPerXing();

  weight = pileup_tool->GetCombinedWeight(m_event_d3pdobject->RunNumber(),m_event_d3pdobject->mc_channel_number(),mu);
  
  return weight;
}

//____________________________________________________________________________         
double ScaleFactorTool::VertexSF(double vx_z){

  if(is_data()) return 1.0;

  double weight = 1.0;

  weight = vertex_tool->GetWeight(vx_z);
  
  return weight;
}

//____________________________________________________________________________         
double ScaleFactorTool::MCReweightSF(const D3PDReader::MCEvtD3PDObject* mcevt_d3pdobject, const D3PDReader::TruthParticleD3PDObject* truthparticle_d3pdobject ){

  if(is_data()) return 1.0;

  double weight = 1.0;

  //only apply to ggH samples
  if (    (mcevt_d3pdobject->mc_channel_number() >= 160152 && mcevt_d3pdobject->mc_channel_number() <= 160179) 
       || (mcevt_d3pdobject->mc_channel_number() == 167220)
       || (mcevt_d3pdobject->mc_channel_number() == 167222)
       || (mcevt_d3pdobject->mc_channel_number() == 167225)
       || (mcevt_d3pdobject->mc_channel_number() == 167227)  ){
       
     double higgsPt = -99;

     for(unsigned int i = 0; i < truthparticle_d3pdobject->pdgId()->size(); i++) {
       if(abs(truthparticle_d3pdobject->pdgId()->at(i)) == 25) {
           higgsPt = truthparticle_d3pdobject->pt()->at(i)/1000.0;
	   break;
       }
     }
     
     if (higgsPt == -99)  {
       m_logger << WARNING << "No Higgs truth particle found for Pt reweight!" << SLogger::endmsg;

     } else { 
       pair<double, double> result = ggf_reweight_tool->getWeightAndStatError(higgsPt);

       weight *= result.first;       
     }
  }
  
  return weight;
}

//____________________________________________________________________________         
double ScaleFactorTool::IsolationIPSF(Quadruplet* quad){

  if(is_data()) return 1.0;

  double sf = 1.0;
  
  std::vector<Electron*> electrons;
  quad->GetElectrons( electrons );

  for (unsigned int i = 0; i < electrons.size(); i++) {
     if(electrons[i]->cl_Et()<15000.) {
        if(fabs(electrons[i]->tracketa())<1.52) {
            sf *= 1.04;
	} else {              
            sf *= 1.02;
        }
     }
  }

  return sf;
}


//____________________________________________________________________________         
void ScaleFactorTool::QCDWeights(std::vector<double> &weights, const D3PDReader::MCEvtD3PDObject* mcevt_d3pdobject, const D3PDReader::TruthParticleD3PDObject* truthparticle_d3pdobject ){

  if(is_data()){
    for (int i = 0; i < 13; i++) weights.push_back(1);     
    return;
  }
  
  //only apply to ggH samples
  if (!((mcevt_d3pdobject->mc_channel_number() >= 160152 && mcevt_d3pdobject->mc_channel_number() <= 160179) 
	 || (mcevt_d3pdobject->mc_channel_number() == 167220)
	 || (mcevt_d3pdobject->mc_channel_number() == 167222)
	 || (mcevt_d3pdobject->mc_channel_number() == 167225)
	 || (mcevt_d3pdobject->mc_channel_number() == 167227)  )){
  
    for (int i = 0; i < 13; i++) weights.push_back(1);     
    return;
  }

  double higgsPt = -99;

  //TODO is this the correct higgs pT?
  for(unsigned int i = 0; i < truthparticle_d3pdobject->pdgId()->size(); i++) {
    if(abs(truthparticle_d3pdobject->pdgId()->at(i)) == 25) {
        higgsPt = truthparticle_d3pdobject->pt()->at(i)/1000.0;
	break;
    }
  }

  if (higgsPt == -99)  {
     m_logger << WARNING << "No Higgs truth particle found for Pt reweight!" << SLogger::endmsg;
     for (int i = 0; i < 13; i++) weights.push_back(1);
     return;     
  }
  
  for (int i = 0; i < 13; i++) weights.push_back(ggf_qcd_tool.at(i)->getWeight(higgsPt));
     
  return;
}

//____________________________________________________________________________         
void ScaleFactorTool::PDFWeights(std::vector<double> &weights, const D3PDReader::MCEvtD3PDObject* mcevt_d3pdobject, const D3PDReader::TruthParticleD3PDObject* truthparticle_d3pdobject ){

  if(is_data()){
    for (int i = 0; i < 40; i++) weights.push_back(1);     
    return;
  }

  //only apply to ggH samples
  if (!((mcevt_d3pdobject->mc_channel_number() >= 160152 && mcevt_d3pdobject->mc_channel_number() <= 160179) 
	 || (mcevt_d3pdobject->mc_channel_number() == 167220)
	 || (mcevt_d3pdobject->mc_channel_number() == 167222)
	 || (mcevt_d3pdobject->mc_channel_number() == 167225)
	 || (mcevt_d3pdobject->mc_channel_number() == 167227)  )){
  
    for (int i = 0; i < 40; i++) weights.push_back(1);     
    return;
  }

  double higgsPt = -99;

  //TODO is this the correct higgs pT?
  for(unsigned int i = 0; i < truthparticle_d3pdobject->pdgId()->size(); i++) {
    if(abs(truthparticle_d3pdobject->pdgId()->at(i)) == 25) {
        higgsPt = truthparticle_d3pdobject->pt()->at(i)/1000.0;
	break;
    }
  }

  if (higgsPt == -99)  {
     m_logger << WARNING << "No Higgs truth particle found for Pt reweight!" << SLogger::endmsg;
     for (int i = 0; i < 40; i++) weights.push_back(1);
     return;     
  }
  
  for (int i = 0; i < 40; i++) weights.push_back(ggf_pdf_tool.at(i)->getWeight(higgsPt));
     
  return;
}



//____________________________________________________________________________         
bool ScaleFactorTool::PassTileError(const D3PDReader::EventInfoD3PDObject* event_d3pdobject){

  bool passTileError = true;
  if(is_data()){
    if (event_d3pdobject->tileError() == 2) passTileError = false;    
    if (tiletrip_tool->checkEvent(event_d3pdobject->RunNumber(),event_d3pdobject->lbn(),event_d3pdobject->EventNumber()) == 0) passTileError = false;
  }
  
  return passTileError;
}  
   
//____________________________________________________________________________         
bool ScaleFactorTool::PassLArError(const D3PDReader::EventInfoD3PDObject* event_d3pdobject){

  bool passLarError = true;
  if(is_data()){
    if (event_d3pdobject->larError() == 2) passLarError = false;
  }
  
  return passLarError;
}  

//____________________________________________________________________________         
bool ScaleFactorTool::PassBCHCleaning(const D3PDReader::EventInfoD3PDObject* event_d3pdobject, std::vector<Jet*> jets){

  bool passBCH = true;
  if(is_data()){

  } else {
    int randomRunNumber = pileup_tool->GetRandomRunNumber(event_d3pdobject->RunNumber(),event_d3pdobject->averageIntPerXing());
    int randomLumiBlockNumber = randomRunNumber > 0 ? pileup_tool->GetRandomLumiBlockNumber(randomRunNumber) : 0; 
    for (unsigned int i=0; i<jets.size(); ++i) {
      if ( randomRunNumber <= 0 ) break;
      if ( BCHcleaning_tool->IsInMaskedRegion(randomRunNumber,randomLumiBlockNumber, jets[i]->eta(), jets[i]->phi()) ) {
        passBCH = false;
	break;
      }
    }
  }
  
  return passBCH;
}  
