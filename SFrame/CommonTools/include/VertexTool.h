#ifndef CommonTools_VertexTool_H
#define CommonTools_VertexTool_H

#include "PrimaryVertexD3PDObject.h"

//ROOT
#include "TH1F.h"

//LocalIncludes
#include "ToolBase.h"

class VertexTool : public ToolBase
{
    public:
        VertexTool( SCycleBase* parent, const char* name = "Vertex" );

        void BeginCycle() throw( SError );
        void BeginInputData( const SInputData& id ) throw( SError );
	float vertex_weight(const  D3PDReader::PrimaryVertexD3PDObject& p);
        float vertex_weight( const int nVtx );
        int  Select( const D3PDReader::PrimaryVertexD3PDObject& p);
        void PlotVertexInfo(const D3PDReader::PrimaryVertexD3PDObject& p, float weight=1.0, const std::string& dir="");
        float GetPileupSumTrackPt( const D3PDReader::PrimaryVertexD3PDObject& p);
        float GetPileupNTracks( const D3PDReader::PrimaryVertexD3PDObject& p);


    private:
        // configurables
        //--------------------------
        int  c_min_num_track;
        double  c_max_z;
        bool  c_require_vertex_type;
        std::string c_vertex_weight_file;
        bool c_do_vertex_reweight;
        
        // private selection methods
        bool IsPassedNTracks( const D3PDReader::PrimaryVertexD3PDObjectElement& p );
        bool IsPassedZ( const D3PDReader::PrimaryVertexD3PDObjectElement& p );
        bool IsPassedType( const D3PDReader::PrimaryVertexD3PDObjectElement& p );

        // private data
        //---------------------------
        TH1F* m_h_vertex_weight;

}; // class VertexTool

#endif // CommonTools_VertexTool_H
