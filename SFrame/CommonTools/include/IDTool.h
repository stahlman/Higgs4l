#ifndef EgammaTools_IDTool_h
#define EgammaTools_IDTool_h


// AtlasSFrameUtils
#include "ToolBase.h"
#include "Electron.h"
#include "Photon.h"
#include "Quadruplet.h"

//RootCore
#include "ElectronPhotonSelectorTools/TElectronLikelihoodTool.h"
#include "ElectronPhotonSelectorTools/TElectronMultiLeptonSelector.h" 
#include "egammaAnalysisUtils/IsEMPlusPlusDefs.h"
#include "egammaEvent/egammaPIDdefs.h"
#include "egammaAnalysisUtils/PhotonIDTool.h"

//#include "HiggsZZ4lUtils/ElectronLikelihoodToolHSG2Helper.h"

//CommonTools
#include "MultiLeptonDefsHCP.h"

class IDTool : public ToolBase {

   public:
  
       IDTool(SCycleBase* parent, const char* name);
   
       void BeginInputData( const SInputData& id );

       // Electrons
       bool passLikelihood(Electron& p, std::string OP, int n_vertices);
       bool passLikelihood(Electron& p, LikeEnum::Menu menu, int n_vertices);
       bool passML(Electron& p, std::string OP="");
       bool passML_HCP(Electron& p, std::string OP=""){return passML(p,"HCP");};
       bool passPlusPlus(Electron& p, std::string OP);

       //Photons
       bool passPID(Photon& p, std::string OP);
 
       //Quadruplets
       bool passLikelihood(vector<int> &dec, Quadruplet * q, std::string OP, int n_vertices);
       bool passLikelihood(vector<int> &dec, Quadruplet * q, LikeEnum::Menu menu, int n_vertices);
       bool passML(vector<int> &dec, Quadruplet * q, std::string OP="");
       bool passML_HCP(vector<int> &dec, Quadruplet * q, std::string OP=""){return passML(dec,q,"HCP");};

    private:
     
       Root::TElectronMultiLeptonSelector * m_multileptonmenu;
       std::vector<unsigned int> m_MaskForZXX;

       Root::TElectronLikelihoodTool * m_likelihoodtool;


};

#endif // EgammaTools_IDTool_h
