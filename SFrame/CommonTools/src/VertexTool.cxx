
// Local include(s):
#include "../include/VertexTool.h"
#include "../include/VertexType.h"

#include <cmath> //std::min

//Root Includes
#include <TKey.h>
#include <TFile.h>


const float GeV = 1000.0;

//____________________________________________________________________________
VertexTool::VertexTool( SCycleBase* parent, const char* name )
:   ToolBase( parent, name ),
    m_h_vertex_weight(0)
{
    SetLogName( name );

    DeclareProperty("min_num_track", c_min_num_track = 0 );
    DeclareProperty("max_z", c_max_z = 9e9 );
    DeclareProperty("require_vertex_type", c_require_vertex_type = false );
    DeclareProperty("do_vertex_reweight", c_do_vertex_reweight = false);
    DeclareProperty("vertex_weight_file", c_vertex_weight_file = "");
}


//____________________________________________________________________________
void VertexTool::BeginCycle() throw(SError)
{
    if(!c_vertex_weight_file.empty())
    { 
        TFile* f = TFile::Open(c_vertex_weight_file.c_str(), "READ");
        TList* l = new TList();
        l->SetName("l_vertex_weights");
        TIter itr(f->GetListOfKeys());
        while( TKey* key = dynamic_cast<TKey*> (itr()) )
        {
            TH1F* h = dynamic_cast<TH1F*> (key->ReadObj());
            h->SetDirectory(0);
            l->Add(h);
        }
        f->Close();
        delete f;
        AddConfigObject(l);
    }
}   


//____________________________________________________________________________
void VertexTool::BeginInputData( const SInputData& id) throw( SError )
{
    if(!c_vertex_weight_file.empty())
    {
        TList* l = dynamic_cast<TList*> (GetConfigObject("l_vertex_weights"));
        m_h_vertex_weight = dynamic_cast<TH1F*> (l->FindObject("vertex_weights"));
        // this is for backwards compatibility w/ the old weights for period A-F
        if(!m_h_vertex_weight) m_h_vertex_weight = dynamic_cast<TH1F*> (l->FindObject("h_PythiaZtautau_vxp_weight_mu_channel"));
    }  
}


//____________________________________________________________________________
int VertexTool::Select(const D3PDReader::PrimaryVertexD3PDObject& p)
{
    int passed_vertex_cut = 0;
    for(int i_vxp=0; i_vxp < p.n(); ++i_vxp)

    {
        if ( !IsPassedNTracks(p[i_vxp]) ) continue;
        if ( !IsPassedZ(p[i_vxp]) ) continue;
        if ( !IsPassedType(p[i_vxp]) ) continue;
        ++passed_vertex_cut;
    }
    return passed_vertex_cut;
}


//____________________________________________________________________________
float VertexTool::GetPileupSumTrackPt(const D3PDReader::PrimaryVertexD3PDObject& p)
{
    float sumTrkPt = 0.;
    // skip first vertex (highest sumPt^2, assumed to be hard scatter)
    for(int i_vxp=1; i_vxp < p.n(); ++i_vxp)

    {
        if ( !IsPassedNTracks(p[i_vxp]) ) continue;
        if ( !IsPassedZ(p[i_vxp]) ) continue;
        if ( !IsPassedType(p[i_vxp]) ) continue;
        sumTrkPt += p[i_vxp].sumPt();
    }
    return sumTrkPt;
}


//____________________________________________________________________________
float VertexTool::GetPileupNTracks(const D3PDReader::PrimaryVertexD3PDObject& p)
{
    int nTracks = 0;
    // skip first vertex (highest sumPt^2, assumed to be hard scatter)
    for(int i_vxp=1; i_vxp < p.n(); ++i_vxp)

    {
        if ( !IsPassedNTracks(p[i_vxp]) ) continue;
        if ( !IsPassedZ(p[i_vxp]) ) continue;
        if ( !IsPassedType(p[i_vxp]) ) continue;
        nTracks += p[i_vxp].nTracks();
    }
    return nTracks;
}


//____________________________________________________________________________
float VertexTool::vertex_weight(const  D3PDReader::PrimaryVertexD3PDObject& p)
{
  return vertex_weight(Select(p)); 
}

//____________________________________________________________________________
float VertexTool::vertex_weight(const int nVtx)
{
  if( !is_data()  && m_h_vertex_weight && c_do_vertex_reweight){
    return m_h_vertex_weight->At( std::min(nVtx, 11)) ;
  }
  else if( !is_data() && c_do_vertex_reweight) {
    m_logger << FATAL << "Cant get handle on vertex weights" << SLogger::endmsg;
    throw SError( SError::StopExecution );
  }
  else
    return 1.0;
}


//____________________________________________________________________________
void VertexTool::PlotVertexInfo(const D3PDReader::PrimaryVertexD3PDObject& p, float weight/*=1.0*/, const std::string& dir/*=""*/)
{
    Book( "h_vxp_n", ";N(vertices);Events", 10, -0.5, 9.5, dir )->Fill( p.n(), weight );
    Book( "h_vxp_n_selected", ";N(vertices selected);Events", 20, -0.5, 19.5, dir )->Fill( Select(p), weight );
    Book( "h_vxp_n_selected_raw", ";N(vertices selected);Events", 20, -0.5, 19.5, dir )->Fill( Select(p), 1.0 ); 
    for(int i_vxp=0; i_vxp < p.n(); i_vxp++)
    {
        Book( "h_vxp_nTracks", ";N_{tracks}(vertex);Vertices", 50, 0.0, 200.0, dir )->Fill( p[i_vxp].nTracks(), weight );
        Book( "h_vxp_z", ";Vertex z  [cm] ;Vertices / (0.5 cm)", 60, -15., 15., dir)->Fill( p[i_vxp].z()/10.0, weight);
    }
}

//____________________________________________________________________________
bool VertexTool::IsPassedNTracks(const D3PDReader::PrimaryVertexD3PDObjectElement& p)
{
    if (p.nTracks() < c_min_num_track) return false;
    return true;
}

//____________________________________________________________________________
bool VertexTool::IsPassedZ(const D3PDReader::PrimaryVertexD3PDObjectElement& p)
{
    if (fabs(p.z()) > c_max_z) return false;
    return true;
}

//____________________________________________________________________________
bool VertexTool::IsPassedType(const D3PDReader::PrimaryVertexD3PDObjectElement& p)
{
    if (!c_require_vertex_type || (p.type() == Trk::PriVtx) || (p.type() == Trk::PileUp)) return true;
    return false;
}


