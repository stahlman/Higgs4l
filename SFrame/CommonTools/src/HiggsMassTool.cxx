
#ifndef Z_pdg_mass
#define Z_pdg_mass 91187.6
#endif
#ifndef Z_pdg_width
#define Z_pdg_width 2495.2
#endif

// AtlasSFrameUtils
#include "Quadruplet.h"
#include "Muon.h"
#include "Electron.h"

//RootCore
#include "egammaFourMomentumError/egammaFourMomentumError.h" 

#include "../include/HiggsMassTool.h"


HiggsMassTool::HiggsMassTool(SCycleBase* parent, const char* name)
    :
        ToolBase(parent, name)
{

}


void HiggsMassTool::BeginInputData( const SInputData& )
{
 
   //m_logger<<::DEBUG<< "Initializing Higgs Mass tool"  << SLogger::endmsg;

    m_logger<<::DEBUG<< "Initializing egamma energy correction tool"  << SLogger::endmsg;
   
    m_eRescaler = new AtlasRoot::egammaEnergyCorrectionTool();
    m_eRescaler->setFileName(sframe_dir()+"/RootCore/ElectronPhotonFourMomentumCorrection/data/egammaEnergyCorrectionData.root");
    
    if (is_data()){
      m_eRescaler->setESModel(egEnergyCorr::es2012c);
    } else {
      if (get_mctype() == AtlasSFrame::MC12a)      m_eRescaler->setESModel(egEnergyCorr::es2012a);
      else if (get_mctype() == AtlasSFrame::MC12b) m_eRescaler->setESModel(egEnergyCorr::es2012a);
      else if (get_mctype() == AtlasSFrame::MC12c) m_eRescaler->setESModel(egEnergyCorr::es2012c);
      //else if(get_mctype() == AtlasSFrame::MC11c)      m_eRescaler->setESModel(egEnergyCorr::es2011c);
    }
    
    m_eRescaler->initialize();
   
   return;
}


void HiggsMassTool::calculateConstrainedMass(Quadruplet* quad)
{

   m_logger<<::DEBUG<< "Retrieving electrons and muons" << SLogger::endmsg;
   std::vector<Electron*> electrons;
   quad->GetElectrons(electrons);
  
   std::vector<Muon*> muons;
   quad->GetMuons(muons);
   
   std::vector<CLHEP::HepMatrix> hep_matrices_el;
   std::vector<CLHEP::HepMatrix> hep_matrices_mu;
         
   // fill track parameters and covariance matrix
   m_logger<<::DEBUG<< "Creating matrices for "<< muons.size()<< " muons" << SLogger::endmsg;
   for (unsigned int j = 0; j < muons.size(); j++) {

      CLHEP::HepMatrix matrix = ZMassConstraint::getCovarianceMatrixd0z0PhiThetaPMuon(muons[j]->TLV()->P(), 
                                                                               muons[j]->cov_d0_exPV(),  
                                                                               muons[j]->cov_z0_exPV(),  
                                                                               muons[j]->cov_phi_exPV(),  
                                                                               muons[j]->cov_theta_exPV(),  
                                                                               muons[j]->cov_qoverp_exPV_cal(), 
                                                                               muons[j]->cov_d0_z0_exPV(),  
                                                                               muons[j]->cov_d0_phi_exPV(),  
                                                                               muons[j]->cov_d0_theta_exPV(),  
                                                                               muons[j]->cov_d0_qoverp_exPV_cal(),  
                                                                               muons[j]->cov_z0_phi_exPV(),
                                                                               muons[j]->cov_z0_theta_exPV(),  
                                                                               muons[j]->cov_z0_qoverp_exPV_cal(),  
                                                                               muons[j]->cov_phi_theta_exPV(),  
                                                                               muons[j]->cov_phi_qoverp_exPV_cal(), 
                                                                               muons[j]->cov_theta_qoverp_exPV_cal());
     
      m_logger<<::DEBUG<< "muon isStandAlone(): " << muons[j]->isStandAloneMuon() << SLogger::endmsg;     
      m_logger<<::DEBUG<< "muon isCaloMuon(): " << muons[j]->isCaloMuon() << SLogger::endmsg;     
      m_logger<<::DEBUG<< "muon matrix:" << matrix << SLogger::endmsg;     
     
         
      hep_matrices_mu.push_back(matrix);
      
   }

   m_logger<<::DEBUG<< "Creating matrices for "<< electrons.size()<< " electrons" << SLogger::endmsg;
   for (unsigned int j = 0; j < electrons.size(); j++) {

     CLHEP::HepMatrix matrix = ZMassConstraint::getCovarianceMatrixd0z0PhiThetaPElectron(electrons[j]->E_resolution(),               
                                                                        	  electrons[j]->trackcov_d0(),  
                                                                        	  electrons[j]->trackcov_z0(),  
                                                                        	  electrons[j]->trackcov_phi(),  
                                                                        	  electrons[j]->trackcov_theta(),  
                                                                        	  electrons[j]->trackcov_d0_z0(),  
                                                                        	  electrons[j]->trackcov_d0_phi(),  
                                                                        	  electrons[j]->trackcov_d0_theta(),
                                                                        	  electrons[j]->trackcov_z0_phi(),
                                                                        	  electrons[j]->trackcov_z0_theta(),  
                                                                        	  electrons[j]->trackcov_phi_theta());

     m_logger<<::DEBUG<< "electron matrix:" << matrix << SLogger::endmsg;     
     
     hep_matrices_el.push_back(matrix); 
   }

   std::vector<TLorentzVector*> tlv_leptons;
   quad->GetLeptonTLVs(tlv_leptons);

   std::vector<CLHEP::HepMatrix> hep_matrices_final;

   if (quad->Type() == Quadruplet::TwoElectronTwoMuon) {
     hep_matrices_final.insert(hep_matrices_final.end(), hep_matrices_el.begin(), hep_matrices_el.end() );
     hep_matrices_final.insert(hep_matrices_final.end(), hep_matrices_mu.begin(), hep_matrices_mu.end() );
   }  else {
     hep_matrices_final.insert(hep_matrices_final.end(), hep_matrices_mu.begin(), hep_matrices_mu.end() );
     hep_matrices_final.insert(hep_matrices_final.end(), hep_matrices_el.begin(), hep_matrices_el.end() );
   }

   if (tlv_leptons.size() != 4)        m_logger<<::ERROR<< "Only found TLVs for "<<tlv_leptons.size()<<" leptons" << SLogger::endmsg;
   if (hep_matrices_final.size() != 4) m_logger<<::ERROR<< "Only found covariance matrices for "<<tlv_leptons.size()<<" leptons" << SLogger::endmsg;


   // perform the actual Z1 refit
   ZMassConstraint::ConstraintFitInput theInput;
   theInput.addConstituent_FourVector_d0z0PhiThetaP(*tlv_leptons[0], hep_matrices_final[0]);
   theInput.addConstituent_FourVector_d0z0PhiThetaP(*tlv_leptons[1], hep_matrices_final[1]);


   CLHEP::HepMatrix photonCovarianceMatrix;
   TLorentzVector quad_fsr;
   int fsr_index = quad->index_FSR();
   if (quad->hasFSR()){
       
       PATCore::ParticleType::Type phType = PATCore::ParticleType::Electron;
       if (quad->type_FSR() == 0) phType = PATCore::ParticleType::Electron;
       if (quad->type_FSR() == 1) phType = PATCore::ParticleType::ConvertedPhoton;
       if (quad->type_FSR() == 2) phType = PATCore::ParticleType::UnconvertedPhoton;
       
       quad_fsr = quad->getFSR_TLV();
       double energyResolution = m_eRescaler->resolution(quad_fsr.E(),quad_fsr.Eta(),phType,true)*quad_fsr.E();
       photonCovarianceMatrix=ZMassConstraint::getCovarianceMatrixd0z0PhiThetaPElectron(energyResolution,           
                                                                                                0.000001,  
                                                                                                0.000001,  
                                                                                                0.000001,  
                                                                                                0.000001,  
                                                                                                0.0,  
                                                                                                0.0,  
                                                                                                0.0,
                                                                                                0.0,
                                                                                                0.0,  
                                                                                                0.0);   
   }

   if (fsr_index == 0){
     m_logger<<::DEBUG<< "Adding FSR photon to Z1" << SLogger::endmsg;
     theInput.addConstituent_FourVector_d0z0PhiThetaP(quad_fsr, photonCovarianceMatrix);   
   } 
   
     
   ZMassConstraint::ConstraintFit MassFit(Z_pdg_mass, true, Z_pdg_width);
   MassFit.massFitInterface(theInput);
   ZMassConstraint::ConstraintFitOutput result = MassFit.massFitRun(-1.);

   TLorentzVector Z1new = result.getCompositeFourVector();
   TLorentzVector Z2new = *tlv_leptons[2] + *tlv_leptons[3];

   std::vector<TLorentzVector> tlv_constrained_leptons;
   std::vector<TMatrixD> cov_constrained_leptons;
      
   tlv_constrained_leptons.push_back(result.getConstituentFourVector(0));
   tlv_constrained_leptons.push_back(result.getConstituentFourVector(1));
   cov_constrained_leptons.push_back(result.getConstituentCovarianced0z0PhiThetaP_TMatrix(0));
   cov_constrained_leptons.push_back(result.getConstituentCovarianced0z0PhiThetaP_TMatrix(1));
   
   if (fsr_index == 0){
     tlv_constrained_leptons.push_back(result.getConstituentFourVector(2));
     cov_constrained_leptons.push_back(result.getConstituentCovarianced0z0PhiThetaP_TMatrix(2));   
   }
   
   if (quad->M4l() > 190.e3) {   // repeat for Z2
      m_logger<<::DEBUG<< "Applying constraint to second pair" << SLogger::endmsg;

     ZMassConstraint::ConstraintFitInput theInput2;
     theInput2.addConstituent_FourVector_d0z0PhiThetaP(*tlv_leptons[2], hep_matrices_final[2]);
     theInput2.addConstituent_FourVector_d0z0PhiThetaP(*tlv_leptons[3], hep_matrices_final[3]);
     
     if (fsr_index == 1){
       m_logger<<::DEBUG<< "Adding FSR photon for Z2" << SLogger::endmsg;
       theInput2.addConstituent_FourVector_d0z0PhiThetaP(quad_fsr, photonCovarianceMatrix);   
     } 
     
     ZMassConstraint::ConstraintFit MassFit2(Z_pdg_mass, true, Z_pdg_width);
     MassFit2.massFitInterface(theInput2);
     ZMassConstraint::ConstraintFitOutput result2 = MassFit2.massFitRun(-1.);
     
     Z2new = result2.getCompositeFourVector();
     tlv_constrained_leptons.push_back(result2.getConstituentFourVector(0));
     tlv_constrained_leptons.push_back(result2.getConstituentFourVector(1));
     cov_constrained_leptons.push_back(result2.getConstituentCovarianced0z0PhiThetaP_TMatrix(0));
     cov_constrained_leptons.push_back(result2.getConstituentCovarianced0z0PhiThetaP_TMatrix(1));
    
     if (fsr_index == 1){
       tlv_constrained_leptons.push_back(result2.getConstituentFourVector(2));
       cov_constrained_leptons.push_back(result2.getConstituentCovarianced0z0PhiThetaP_TMatrix(2));   
     }
   
   } else {

     tlv_constrained_leptons.push_back(*tlv_leptons[2]);
     tlv_constrained_leptons.push_back(*tlv_leptons[3]);
     cov_constrained_leptons.push_back(CLHEPtoROOT(hep_matrices_final[2]));
     cov_constrained_leptons.push_back(CLHEPtoROOT(hep_matrices_final[3]));   

     if (fsr_index == 1){
       tlv_constrained_leptons.push_back(quad->getFSR_TLV());
       cov_constrained_leptons.push_back(CLHEPtoROOT(photonCovarianceMatrix));   
     }
   }

   std::vector<TLorentzVector> tmp_leptons;
   for (unsigned int i = 0; i < tlv_leptons.size(); i++) tmp_leptons.push_back(*tlv_leptons[i]);
   std::vector<TMatrixD> cov_leptons;
   for (unsigned int i = 0; i < hep_matrices_final.size(); i++) cov_leptons.push_back(CLHEPtoROOT(hep_matrices_final[i]));

   quad->SetM4lErr( MassError::sigmaMassCalc_d0z0PhiThetaP(tmp_leptons,cov_leptons));

   if (quad->hasFSR()){
      tmp_leptons.push_back(quad->getFSR_TLV());
      cov_leptons.push_back(CLHEPtoROOT(photonCovarianceMatrix));    
   }
   
   quad->SetM4lErr_fsr( MassError::sigmaMassCalc_d0z0PhiThetaP(tmp_leptons,cov_leptons));
   
   quad->SetTLV_constrained(Z1new + Z2new);
   quad->SetZ1_TLV_constrained(Z1new);
   quad->SetZ2_TLV_constrained(Z2new);
   quad->SetM4lErr_constrained( MassError::sigmaMassCalc_d0z0PhiThetaP(tlv_constrained_leptons,cov_constrained_leptons));
         
   m_logger<<::DEBUG<< "Initial M4l: " << quad->M4l()  << " Constrained M4l: " << quad->M4l_constrained() << SLogger::endmsg;
   m_logger<<::DEBUG<< "Initial M12: " << quad->M12()  << " Constrained M12: " << quad->M12_constrained() << SLogger::endmsg;
   m_logger<<::DEBUG<< "Initial M34: " << quad->M34()  << " Constrained M34: " << quad->M34_constrained() << SLogger::endmsg;
   m_logger<<::DEBUG<< "M4l error: " << quad->M4lErr() << " M4l constrained error: " << quad->M4lErr_constrained() << SLogger::endmsg;
   
   return;
}


/** \brief Convert a CLHEP HepMatrix to ROOT TMatrixD. */
TMatrixD HiggsMassTool::CLHEPtoROOT(const CLHEP::HepMatrix & oldM) {
  TMatrixD newM;
  newM.ResizeTo(oldM.num_row(), oldM.num_col());
  for (int i = 0; i < oldM.num_row(); i++) {
    for (int j = 0; j < oldM.num_col(); j++) {
      newM[i][j] = oldM[i][j];
    }
  }
  return newM;
}
