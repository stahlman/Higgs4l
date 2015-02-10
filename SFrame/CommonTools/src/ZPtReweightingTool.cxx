#include "../include/ZPtReweightingTool.h"

// AtlasSFrameUtils
#include "ParticleElementBuilder.h"

//D3PD objects
#include "TruthParticleD3PDObject.h"

#include <cmath> //std::min


const float GeV = 1000.0;

//____________________________________________________________________________
ZPtReweightingTool::ZPtReweightingTool( SCycleBase* parent, const char* name/*=ZPtReweighting*/ )
    : ToolBase( parent, name )
{
    DeclareProperty("do_zpt_reweighting", c_do_zpt_reweighting = false );
    DeclareProperty("config_file", c_file = "PythiaMC11" );

    m_toolname = name;
    m_toolname.append("_ZPtReweighting");
}


//____________________________________________________________________________
void ZPtReweightingTool::BeginCycle() throw(SError)
{
    if (c_do_zpt_reweighting ) {
        m_zpt_reweighting = new BosonPtReweightingTool(c_file,true);
        
	//AddConfigObject(m_zpt_reweighting);
    } 
}

//____________________________________________________________________________
void ZPtReweightingTool::BeginInputData( const SInputData& id) throw( SError )
{
     //Will crash if run in proof mode!  Need to update reweighting tool to inherit from TObject....
     //if (c_do_zpt_reweighting) {
     //    m_zpt_reweighting = dynamic_cast<BosonPtReweightingTool*>(GetConfigObject(m_toolname.c_str()));
     //}
}


//____________________________________________________________________________
float ZPtReweightingTool::GetZPtWeight(const D3PDReader::TruthParticleD3PDObject& m_truth_d3pdobject)
{
    float zPtEventWeight = 1.0;
    if ((c_do_zpt_reweighting) && !is_data()) {
  		
       std::vector<TruthParticle> tparts;
       ParticleElementBuilder::build(tparts, m_truth_d3pdobject);
       int index_z = 0;
       int n_z = 0;
       
       for (unsigned int i = 0; i < tparts.size(); i++) {
	 if (tparts[i].pdgId() == PDG::Z0 && (tparts[i].status() == 1 || tparts[i].status() == 2 )) {
	   index_z = i;
	   n_z++;
	 }
       }
       
       if (n_z == 0) {
         m_logger << WARNING  << "No Z boson truth particle found" << SLogger::endmsg;
	 return 1.0;
       }
		
       if (n_z > 1) {
         m_logger << WARNING  << "More than one Z boson found (!?)" << SLogger::endmsg;
	 return 0;
       }
       
       zPtEventWeight = m_zpt_reweighting->GetWeightZee(tparts[index_z].pt(), tparts[index_z].m());
	
       if (zPtEventWeight < 0) zPtEventWeight = 0.0;
    }
    
    return zPtEventWeight;
}

//____________________________________________________________________________
void ZPtReweightingTool::EndCycle()
{
    
    if (c_do_zpt_reweighting) {
          delete m_zpt_reweighting;
    }
}

