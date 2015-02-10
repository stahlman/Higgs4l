#ifndef CommonTools_InvMassTool_H
#define CommonTools_InvMassTool_H

//Root include(s):
#include "TLorentzVector.h"

//RootCore includes(s):
#include "egammaAnalysisUtils/EnergyRescaler.h"
#include "MuonMomentumCorrections/SmearingClass.h"

// AtlasSFrameUtils
//#include "../../AtlasSFrameUtils/include/ToolBase.h"

using namespace std;

class InvMassTool
{
  public:
      //default constructor
      InvMassTool();
      //destructor
      ~InvMassTool();
      
      double M();
      double SigmaM();
      void Reset(); 

      enum Particle {
        MUON,
	ELECTRON,
	TAU,
	STACOMUON,
	MUIDMUON, //etc. etc.
	NUMTYPES      
      };
      
      bool AddParticle(TLorentzVector part, enum InvMassTool::Particle type);
      bool AddMuon(double PtCB, double PtMS, double PtID, double Eta, double Phi);

  private:
      // configurables
      //--------------------------
      bool isData;
      
      // tools
      //--------------------------
      eg2011::EnergyRescaler* energy_rescaler;
      MuonSmear::SmearingClass* mcp_res;

      // methods
      //--------------------------
      double GetResolution(TLorentzVector particle, enum InvMassTool::Particle type); 

      // private data
      //---------------------------
      std::vector< std::vector<TLorentzVector> > m_objects;
      std::vector< std::vector<double> > m_resolutions;
        
}; // class InvMassTool

#endif // CommonTools_InvMassTool_H
