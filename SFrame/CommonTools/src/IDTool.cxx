#include <string>
#include "../include/IDTool.h"



//____________________________________________________________________________         
IDTool::IDTool(SCycleBase* parent, const char* name)
    :
        ToolBase(parent, name)
{

}

//____________________________________________________________________________         
void IDTool::BeginInputData( const SInputData& )
{
    //TODO make this configurable for 2011/2012
 
    m_logger<<DEBUG<< "Initializing ID tool"  << SLogger::endmsg;
    m_likelihoodtool = new Root::TElectronLikelihoodTool();
    m_likelihoodtool->setPDFFileName(sframe_dir()+"/RootCore/ElectronPhotonSelectorTools/data/ElectronLikelihoodPdfs.root"); // use this root file!
    m_likelihoodtool->setOperatingPoint(LikeEnum::Loose);
    m_likelihoodtool->initialize();

    m_multileptonmenu = new Root::TElectronMultiLeptonSelector();
    m_multileptonmenu->initialize();
    //m_multileptonmenu->setDoDebug(1);

    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("Coverage"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("NSilicon"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("NPixel"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("NBLayer"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("RHad"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("F3"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("Reta"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("W2"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("Wstot"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("DeltaPhiRes"));
    m_MaskForZXX.push_back(m_multileptonmenu->getTAccept().getCutPosition("TR"));
    // "TightDeltaPhi" has to do with cases where there is no bl hit
}

//____________________________________________________________________________
bool IDTool::passML(Electron& p, std::string OP)
{
  bool passed = 0;
  
  Electron * ele = &p;

  double dpOverp =0;
  double el_qoverp_LM = (*ele).trackqoverp();
  for (unsigned int i = 0; i < (*ele).refittedTrack_LMqoverp().size();++i) {
    if(((*ele).refittedTrack_author().at(i))==4) {
      el_qoverp_LM = (*ele).refittedTrack_LMqoverp().at(i);
    }
  }
  dpOverp = 1-(*ele).trackqoverp()/el_qoverp_LM;

  double rTRT = 0.;
  int nTRTTotal = (*ele).nTRTHits()+(*ele).nTRTOutliers();
  rTRT = nTRTTotal > 0 ?  ((double) ((*ele).nTRTHighTHits()+(*ele).nTRTHighTOutliers())/(nTRTTotal) ) : 0.;

  //uncalibrated energy for ML
  double Et_help_ML = (*ele).cl_E()/cosh((*ele).etas2());

  double deltaeta = (*ele).deltaeta1();
  double eratio = ((*ele).emaxs1()-(*ele).Emax2())/((*ele).emaxs1()+(*ele).Emax2());


  if (OP == "HCP"){
    if(passMultiLeptonHCP((*ele).etas2(),Et_help_ML ,
      			  (*ele).Ethad()/Et_help_ML, (*ele).Ethad1()/Et_help_ML,
			  (*ele).reta(), (*ele).weta2() ,(*ele).f1(), (*ele).f3(),
			  (*ele).wstot(),
			  eratio,
			  deltaeta, (*ele).nSiHits(),
			  (*ele).nSCTDeadSensors()+(*ele).nPixelDeadSensors(),
			  (*ele).nPixHits(),(*ele).nPixelDeadSensors(),
			  (*ele).deltaphiRescaled(),dpOverp,
			  rTRT,nTRTTotal,(*ele).nBLHits(),
			  (*ele).expectBLayerHit())) passed = true;
  } else {
    Root::TAccept taccept; 
    taccept = m_multileptonmenu->accept((*ele).etas2(),Et_help_ML ,
					(*ele).Ethad()/Et_help_ML, (*ele).Ethad1()/Et_help_ML,
					(*ele).reta(), (*ele).weta2() ,(*ele).f1(), (*ele).f3(),
					(*ele).wstot(),
					eratio,
					deltaeta, (*ele).nSiHits(),
					(*ele).nSCTDeadSensors()+(*ele).nPixelDeadSensors(),
					(*ele).nPixHits(),(*ele).nPixelDeadSensors(),
					(*ele).deltaphiRescaled(),dpOverp,
					rTRT,nTRTTotal,(*ele).nBLHits(),
					(*ele).expectBLayerHit(),false);
    passed = (bool)taccept;
  
    if(OP == "Relaxed"){
      bool passed_relaxed = true;
      for (unsigned int j=0;j<m_MaskForZXX.size();j++) {
	passed_relaxed = passed_relaxed & (bool)taccept.getCutResult(m_MaskForZXX[j]);
      }
      passed = passed_relaxed;
    }
  }
  
  return passed;
}

//____________________________________________________________________________
bool IDTool::passLikelihood(Electron& p, std::string OP, int n_vertices)
{
  bool passed = 0;
  
  LikeEnum::Menu menu = LikeEnum::Loose;
  if (OP.find("VeryLoose") != std::string::npos)        menu = LikeEnum::VeryLoose;
  else if (OP.find("LooseRelaxed") != std::string::npos)   menu = LikeEnum::LooseRelaxed;
  else if (OP.find("Loose") != std::string::npos)       menu = LikeEnum::Loose;
  else if (OP.find("Medium") != std::string::npos)      menu = LikeEnum::Medium;
  else if (OP.find("VeryTight") != std::string::npos)   menu = LikeEnum::VeryTight;
  else if (OP.find("Tight") != std::string::npos)       menu = LikeEnum::Tight;

  passed = passLikelihood(p, menu, n_vertices);

  return passed;

}

//____________________________________________________________________________
bool IDTool::passLikelihood(Electron& p, LikeEnum::Menu menu, int n_vertices)
{
  bool passed = 0;

  Electron * ele = &p;
  double dpOverp =0;
  double el_qoverp_LM = (*ele).trackqoverp();
  for (unsigned int i = 0; i < (*ele).refittedTrack_LMqoverp().size();++i) {
     if(((*ele).refittedTrack_author().at(i))==4) {
       el_qoverp_LM = (*ele).refittedTrack_LMqoverp().at(i);
     }
  }
  dpOverp = 1-(*ele).trackqoverp()/el_qoverp_LM;

  double Et_help_likelihood = (*ele).cl_E()/cosh((*ele).etas2());

  m_likelihoodtool->setOperatingPoint(menu);

  double emax = (*ele).emaxs1();
  double emax2 = (*ele).Emax2();
  double eratio = (emax+emax2 == 0 ? 0 : (emax-emax2)/(emax+emax2));

  double discriminant = m_likelihoodtool->calculate(
                                      (double)(*ele).etas2(), 
                                      (double)Et_help_likelihood,
                                      (double)(*ele).f3(),
                                      (double)(*ele).Ethad()/Et_help_likelihood,
                                      (double)(*ele).Ethad1()/Et_help_likelihood,
                                      (double)(*ele).reta(), 
                                      (double)(*ele).weta2(), 
                                      (double)(*ele).f1(), 
				      eratio, //(double)(*ele).DEmaxs1(), //equivalent to twiki? No.
                                      (double)(*ele).deltaeta1(),
                                      (double)(*ele).trackd0pvunbiased(), 
                                      (double)(*ele).TRTHighTOutliersRatio(),
                                      (double)(*ele).tracksigd0pvunbiased(),
                                      (double)(*ele).rphi(),
                                      (double)dpOverp,
                                      (double)(*ele).deltaphiRescaled(),
                                      (double)n_vertices);

  passed = (bool)m_likelihoodtool->accept(
                                 (double)discriminant,
                                 (double)(*ele).etas2(), 
                                 (double)Et_help_likelihood,
                                 (int)(*ele).nSiHits(),
                                 (int)(*ele).nPixelDeadSensors() + (*ele).nSCTDeadSensors(),
                                 (int)(*ele).nPixHits(), 
                                 (int)(*ele).nPixelDeadSensors(),
                                 (int)(*ele).nBLHits(), 
                                 (int)(*ele).nBLayerOutliers(), 
                                 (bool)((*ele).expectHitInBLayer() != 0),
                                 (int)(*ele).isEM() & (0x1 << egammaPID::ConversionMatch_Electron), 
                                 (double)n_vertices);


  return passed;
}

//____________________________________________________________________________
bool IDTool::passPlusPlus(Electron& p, std::string OP)
{
  bool passed = 0;

  Electron * ele = &p;

    double Et_help = (*ele).cl_E()/cosh((*ele).etas2());
    m_logger << DEBUG << "MultiLepton" << SLogger::endmsg;

    //Do electron ID before calibration etc. //tag should be tight! //can be made configurable later: in ProbeSelector, define probe_tag_tight
    if(OP == "tight" && isTightPlusPlus((*ele).etas2(),Et_help ,
                        (*ele).f3(),(*ele).Ethad()/Et_help, (*ele).Ethad1()/Et_help,
                        (*ele).reta(), (*ele).weta2() ,(*ele).f1(), (*ele).wstot(),
                        ((*ele).emaxs1()-(*ele).Emax2())/((*ele).emaxs1()+(*ele).Emax2()),
                        (*ele).deltaeta1(),(*ele).trackd0pv(), //should be replaced by trackd0_physics 
                        (*ele).TRTHighTOutliersRatio(),(*ele).nTRTHits(),(*ele).nTRTOutliers(),
                        (*ele).nSiHits(),(*ele).nSCTOutliers() + (*ele).nPixelOutliers(),
                        (*ele).nPixHits(),(*ele).nPixelOutliers(),
                        (*ele).nBLHits(),(*ele).nBLayerOutliers(),
                        (*ele).expectHitInBLayer(),
                        (*ele).cl_E() * fabs((*ele).trackqoverp()),
                        (*ele).deltaphi2(),
                        (*ele).isEM() & (0x1 << egammaPID::ConversionMatch_Electron),
                        egammaMenu::eg2012, false, false)) passed = true;


 return passed;
}
//____________________________________________________________________________
bool IDTool::passPID(Photon& p, std::string OP)
{
  bool passed = 0;

  Photon * ph = &p;

   //calculate variables...
   //rhad
   double rhad = 0;
    if (0.8 < fabs((*ph).etas2()) && fabs((*ph).etas2()) < 1.37) {
            rhad = (*ph).Ethad()/(*ph).cl_Et();
          } else {
            rhad = (*ph).Ethad1()/(*ph).cl_Et(); // i.e., still the right combination
          }
    double rhad1 = (*ph).Ethad1()/(*ph).cl_Et();
    //eratio
    double eratio = 0;
    if ((*ph).emaxs1() != - (*ph).Emax2())
        eratio = ((*ph).emaxs1() - (*ph).Emax2())/((*ph).emaxs1() + (*ph).Emax2());

    PhotonIDTool::PhotonIDTool ph_pid = PhotonIDTool::PhotonIDTool((*ph).cl_Et(), (*ph).etas2(),
                                  rhad, rhad, (*ph).E277(), (*ph).reta(), (*ph).rphi(), (*ph).weta2(), (*ph).f1(), (*ph).fside(), (*ph).wstot(), (*ph).ws3(),
                                  (*ph).deltaEs(), eratio, (*ph).isConv());
    if(OP == "tight" && ph_pid.PhotonCutsTight(2012)) passed = true;

  return passed;
}

//____________________________________________________________________________
bool IDTool::passML(vector<int> &dec,Quadruplet * quad, std::string OP)
{
  std::vector<int> el_dec;
  std::vector<Electron*>  q_electrons;
  quad->GetElectrons( q_electrons );
  for (unsigned int i = 0; i < q_electrons.size(); i++){
     el_dec.push_back(passML(*(q_electrons.at(i)),OP));    
  }
  
  bool quad_passML = true; 
  for (unsigned int i = 0; i < el_dec.size(); i++){
    if (!el_dec.at(i)) quad_passML = false;
  }
  
  std::vector<int> mu_dec;
  std::vector<Muon*>  q_muons;
  quad->GetMuons( q_muons );
  for (unsigned int i = 0; i < q_muons.size(); i++){
     mu_dec.push_back(-1);
  }

  //preserve 1-1 mapping between lepton type vector and lepton pt vector
  if (quad->Type() == Quadruplet::TwoElectronTwoMuon) {
    dec.insert(dec.end(), el_dec.begin(), el_dec.end() );
    dec.insert(dec.end(), mu_dec.begin(), mu_dec.end() );
  }  else {
    dec.insert(dec.end(), mu_dec.begin(), mu_dec.end() );
    dec.insert(dec.end(), el_dec.begin(), el_dec.end() );
  }
   
  return quad_passML;
}


//____________________________________________________________________________
bool IDTool::passLikelihood(vector<int> &dec,Quadruplet * quad, std::string OP, int n_vertices)
{
  std::vector<int> el_dec;
  std::vector<Electron*>  q_electrons;
  quad->GetElectrons( q_electrons );
  for (unsigned int i = 0; i < q_electrons.size(); i++){
     el_dec.push_back(passLikelihood(*(q_electrons.at(i)),OP,n_vertices));
  }

  bool quad_passLikelihood = true; 
  for (unsigned int i = 0; i < el_dec.size(); i++){
    if (!el_dec.at(i)) quad_passLikelihood = false;
  }

  std::vector<int> mu_dec;
  std::vector<Muon*>  q_muons;
  quad->GetMuons( q_muons );
  for (unsigned int i = 0; i < q_muons.size(); i++){
     mu_dec.push_back(-1);
  }

  //preserve 1-1 mapping between lepton type vector and lepton pt vector
  if (quad->Type() == Quadruplet::TwoElectronTwoMuon) {
    dec.insert(dec.end(), el_dec.begin(), el_dec.end() );
    dec.insert(dec.end(), mu_dec.begin(), mu_dec.end() );
  }  else {
    dec.insert(dec.end(), mu_dec.begin(), mu_dec.end() );
    dec.insert(dec.end(), el_dec.begin(), el_dec.end() );
  }
  
  return quad_passLikelihood;
}

//____________________________________________________________________________
bool IDTool::passLikelihood(vector<int> &dec,Quadruplet * quad, LikeEnum::Menu menu, int n_vertices)
{
  std::vector<int> el_dec;
  std::vector<Electron*>  q_electrons;
  quad->GetElectrons( q_electrons );
  for (unsigned int i = 0; i < q_electrons.size(); i++){
     el_dec.push_back(passLikelihood(*(q_electrons.at(i)),menu,n_vertices));
  }

  bool quad_passLikelihood = true; 
  for (unsigned int i = 0; i < el_dec.size(); i++){
    if (!el_dec.at(i)) quad_passLikelihood = false;
  }

  std::vector<int> mu_dec;
  std::vector<Muon*>  q_muons;
  quad->GetMuons( q_muons );
  for (unsigned int i = 0; i < q_muons.size(); i++){
     mu_dec.push_back(-1);
  }

  //preserve 1-1 mapping between lepton type vector and lepton pt vector
  if (quad->Type() == Quadruplet::TwoElectronTwoMuon) {
    dec.insert(dec.end(), el_dec.begin(), el_dec.end() );
    dec.insert(dec.end(), mu_dec.begin(), mu_dec.end() );
  }  else {
    dec.insert(dec.end(), mu_dec.begin(), mu_dec.end() );
    dec.insert(dec.end(), el_dec.begin(), el_dec.end() );
  }
  
  return quad_passLikelihood;
}
