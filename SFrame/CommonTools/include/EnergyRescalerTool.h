#ifndef EgammaTools_EnergyRescalerTool_h
#define EgammaTools_EnergyRescalerTool_h

#include <vector>
#include <string>

//Root
#include "TH2F.h"
#include <TRandom3.h>

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Electron.h"
#include "Muon.h"
#include "Photon.h"
#include "Jet.h"

//RootCore
#include "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h"
#include "MuonMomentumCorrections/SmearingClass.h"
#include "MuonMomentumCorrections/MuonResolutionAndMomentumScaleFactors.h"
#include "ApplyJetCalibration/ApplyJetCalibration.h"
#include "JetUncertainties/MultijetJESUncertaintyProvider.h"
#include "ApplyJetResolutionSmearing/ApplyJetSmearing.h"
#include "egammaFourMomentumError/egammaFourMomentumError.h"

class EnergyRescalerTool : public ToolBase {

   public:
  
       EnergyRescalerTool(SCycleBase* parent, const char* name);
   
       virtual void BeginInputData( const SInputData& id );

       // Electrons
       void ApplyEnergyRescaler(std::vector<Electron>& vec, const int EventNumber, const int RunNumber);
       void ApplyEnergyRescaler(Electron& p, const int EventNumber, const int RunNumber);

       // Muons
       void ApplyEnergyRescaler(std::vector<Muon>& vec, const int EventNumber);
       void ApplyEnergyRescaler(Muon& p, const int EventNumber);

       //Photons 
       void ApplyEnergyRescaler(std::vector<Photon>& vec, const int EventNumber, const int RunNumber);
       void ApplyEnergyRescaler(Photon& p, const int EventNumber, const int RunNumber);

       // Jets
       void ApplyEnergyRescaler(std::vector<Jet>& vec, double mu, unsigned int npv, double Eventshape);
       void ApplyEnergyRescaler(Jet& j, double mu, unsigned int npv, double Eventshape);
       void ApplyJetSystematic(std::vector<Jet>& vec, double mu, unsigned int npv, const int EventNumber, int syst=0);

    private:
     
       float GetD0Z0SmearSigma(int nBL, float pt, float eta, int seed, std::string opt="D0");
       
       AtlasRoot::egammaEnergyCorrectionTool* m_eRescaler;
       MuonSmear::SmearingClass* m_muRescaler;
       Analysis::MuonResolutionAndMomentumScaleFactors *mu_resolSF;
       JetAnalysisCalib::JetCalibrationTool *m_JetRescaler;
       MultijetJESUncertaintyProvider *m_JetUncertainties;
       JetSmearingTool *m_JERTool;
       
       mutable TRandom3 random3;
       TFile* ip_smear;
       TH2F* smearD0[3];
       TH2F* smearZ0[3];
       TAxis* smear_X; 
       TAxis* smear_Y;

       std::string doSystematic;       

       egammaFourMomentumError *m_EPcombination;
      
};

#endif // EgammaTools_EnergyRescalerTool_h
