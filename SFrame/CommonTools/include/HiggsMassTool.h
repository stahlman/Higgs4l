#ifndef HiggsMassTool_h
#define HiggsMassTool_h


// AtlasSFrameUtils
#include "ToolBase.h"
#include "Electron.h"
#include "Muon.h"
#include "Quadruplet.h"

//RootCore
#include "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h"
#include "ZMassConstraint/ZMassConstraint.h"
#include "ZMassConstraint/ConstraintFit.h"
#include "CLHEP/Matrix/Matrix.h"

class HiggsMassTool : public ToolBase {

   public:
  
       HiggsMassTool(SCycleBase* parent, const char* name);
   
       void BeginInputData( const SInputData& id );

       void calculateConstrainedMass(Quadruplet* higgs);
        
   private:

       TMatrixD CLHEPtoROOT(const CLHEP::HepMatrix & oldM);
       
       AtlasRoot::egammaEnergyCorrectionTool* m_eRescaler;       

};

#endif // HiggsMassTool_h
