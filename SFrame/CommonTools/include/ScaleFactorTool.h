#ifndef CommonTools_ScaleFactorTool_H
#define CommonTools_ScaleFactorTool_H

//RootCore includes(s):
#include "egammaAnalysisUtils/VertexPositionReweightingTool.h"
#include "MuonEfficiencyCorrections/AnalysisMuonConfigurableScaleFactors.h"
#include "TrigMuonEfficiency/LeptonTriggerSF.h"
#include "PileupReweighting/TPileupReweighting.h"
#include "ElectronEfficiencyCorrection/TElectronEfficiencyCorrectionTool.h"
#include "ggFReweighting/ggFReweighting.h"
#include "TileTripReader/TTileTripReader.h" 
#include "BCHCleaningTool/BCHCleaningToolRoot.h" 

// D3PDObjects
#include "EventInfoD3PDObject.h"
#include "MCEvtD3PDObject.h"
#include "TruthParticleD3PDObject.h"

//AtlasSFrameUtils
#include "Quadruplet.h"

//SFrame include(s):
#include "ToolBase.h"

using namespace std;

class ScaleFactorTool : public ToolBase {

  public:

      enum Systematic {
         None,
	 ElectronIDReco,
	 ElectronRecoLow,  
	 ElectronRecoHigh,
	 ElectronIDStatHigh,
	 ElectronIDLow,
	 ElectronStat15,
	 ElectronStat10,
	 ElectronStat7,  
	 ElectronTrigger,
         MuonIDReco,
         MuonTrigger,
          
      };

      //default constructor
      ScaleFactorTool(SCycleBase* parent, const char* name);
      //destructor
      //~ScaleFactorTool();
      void BeginInputData( const SInputData& id );

       
      double LeptonSF(Quadruplet* quad,  const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, Systematic syst=ScaleFactorTool::None); 
      double LeptonSF(Quadruplet* quad,  const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, std::vector<double> &lepton_sf, Systematic syst=ScaleFactorTool::None); 
      double TriggerSF(Quadruplet* quad, const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject, Systematic syst=ScaleFactorTool::None); 
      double PileupSF(const D3PDReader::EventInfoD3PDObject* m_event_d3pdobject);
      double VertexSF(double vx_z);
      double MCReweightSF(const D3PDReader::MCEvtD3PDObject* m_mcevt_d3pdobject, const D3PDReader::TruthParticleD3PDObject* truthparticle_d3pdobject );
      double IsolationIPSF(Quadruplet* quad);
      void QCDWeights(std::vector<double> &weights, const D3PDReader::MCEvtD3PDObject* m_mcevt_d3pdobject, const D3PDReader::TruthParticleD3PDObject* truthparticle_d3pdobject );
      void PDFWeights(std::vector<double> &weights, const D3PDReader::MCEvtD3PDObject* m_mcevt_d3pdobject, const D3PDReader::TruthParticleD3PDObject* truthparticle_d3pdobject );

      bool PassTileError(const D3PDReader::EventInfoD3PDObject* event_d3pdobject);
      bool PassLArError(const D3PDReader::EventInfoD3PDObject* event_d3pdobject);
      bool PassBCHCleaning(const D3PDReader::EventInfoD3PDObject* event_d3pdobject, std::vector<Jet*> jets);

  private:
      // configurables
      //--------------------------
      bool isData;
      
      // tools
      //--------------------------
      //egammaSFclass* m_egammaSF;
      Root::TElectronEfficiencyCorrectionTool* egammaRecoSFTool;
      Root::TElectronEfficiencyCorrectionTool* egammaIDSFTool;
      
      Analysis::AnalysisMuonConfigurableScaleFactors* MuidSCF;
      Analysis::AnalysisMuonConfigurableScaleFactors* MuidSASCF;
      Analysis::AnalysisMuonConfigurableScaleFactors* StacoSCF;
      Analysis::AnalysisMuonConfigurableScaleFactors* StacoSASCF;
      Analysis::AnalysisMuonConfigurableScaleFactors* CaloMuSCF;
      
      LeptonTriggerSF* m_TriggerSF;

      Root::TPileupReweighting* pileup_tool;
 
      VertexPositionReweightingTool* vertex_tool;
      
      ggFReweighting* ggf_reweight_tool;

      Root::TTileTripReader* tiletrip_tool;
      
      BCHTool::BCHCleaningToolRoot* BCHcleaning_tool;

      std::vector<ggFReweighting*> ggf_qcd_tool; 

      std::vector<ggFReweighting*> ggf_pdf_tool; 
      
      // methods
      //--------------------------

      // private data
      //---------------------------

      //ClassDef( ScaleFactorTool, 0 )
        
}; // class ScaleFactorTool

#endif // CommonTools_ScaleFactorTool_H
