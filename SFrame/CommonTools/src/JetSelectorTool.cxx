#include "../include/JetSelectorTool.h"
#include "StringHelper.h"
#include <sstream>

const float GeV = 1000.0;

//____________________________________________________________________________         
JetSelectorTool::JetSelectorTool(SCycleBase* parent, const char* name)
    :
        ToolBase(parent, name)
{
    DeclareProperty( "min_pt", c_min_pt = 0.0 );
    DeclareProperty( "max_pt", c_max_pt = 9e9 );
    DeclareProperty( "min_et", c_min_et = 0.0 );
    DeclareProperty( "max_abs_eta", c_max_abs_eta = 9e9 );
    DeclareProperty( "excluded_abs_eta_regions", c_excluded_abs_eta_regions );
    DeclareProperty( "multiplicity_pt_cutoffs", c_multiplicity_pt_cutoffs );
}


//____________________________________________________________________________         
int JetSelectorTool::Select(std::vector<Jet>& vec)
{
    std::vector<Jet> passed;
    std::vector<Jet> failed;
    int n_passed  = Select(vec, passed, failed);
    vec = passed;
    return n_passed;
}


//____________________________________________________________________________         
int JetSelectorTool::Select(const std::vector<Jet>& vec, std::vector<Jet>& passed)
{
    std::vector<Jet> failed;
    return Select(vec, passed, failed);
}

//____________________________________________________________________________         
int JetSelectorTool::Select(const std::vector<Jet>& vec, std::vector<Jet>& passed, std::vector<Jet>& failed)
{
    int n_passed = 0;
    for(std::vector<Jet>::const_iterator itr = vec.begin(); itr != vec.end(); ++itr)
    {
        if( Select(*itr) )
        {
            passed.push_back(*itr);
            n_passed++;
        }
        else
        {
            failed.push_back(*itr);
        }
    }
    return n_passed;
}

//____________________________________________________________________________         
bool JetSelectorTool::Select(const Jet& p)
{
    // min_pt
    if(!(p.tlv.Pt() > c_min_pt)) return false;

    // max_pt
    if(!(p.tlv.Pt() < c_max_pt) ) return false;

    // min_et
    if(!(p.tlv.Et() > c_min_et) ) return false;

    // max_abs_eta
    float abs_eta = fabs( p.tlv.Eta() );
    if(!( abs_eta < c_max_abs_eta )) return false;

    // excluded_abs_eta_regions
    for(unsigned int i_eta=0; i_eta < c_excluded_abs_eta_regions.size()/2; i_eta++)
    {
        if( ( c_excluded_abs_eta_regions[2*i_eta] < abs_eta )&&( abs_eta < c_excluded_abs_eta_regions[2*i_eta+1] ) )
            return false;
    }

    return true;
}

//____________________________________________________________________________         
void JetSelectorTool::PlotKinematics(const Jet& p, float weight/*=1.0*/, const std::string& dir/*=""*/)
{
    Book( "h_jet_pt", ";p_{T}(jet)  [GeV];Jets / 2.5 GeV", 60, 0.0, 150.0, dir)
        ->Fill( p.tlv.Pt() / GeV, weight );
    Book( "h_jet_eta", ";#eta(jet);Jets / 0.1", 60, -3.0, 3.0, dir)
        ->Fill( p.tlv.Eta(), weight );
    Book( "h_jet_phi", ";#phi(jet);Jets / (#pi/30)", 60, -3.1416, 3.1416, dir)
        ->Fill( p.tlv.Phi(), weight );
    Book( "h_jet_m", ";m(jet)  [GeV];Jets / 0.2 GeV", 60, 0.0, 12.0, dir)
        ->Fill( p.tlv.M() / GeV, weight );
}

//____________________________________________________________________________         
void JetSelectorTool::PlotKinematics(const std::vector<Jet>& vec, float weight/*=1.0*/, const std::string& dir/*=""*/)
{
    for(std::vector<Jet>::const_iterator itr = vec.begin(); itr != vec.end(); ++itr)
        PlotKinematics(*itr, weight, dir);
}

//____________________________________________________________________________         
void JetSelectorTool::PlotIdentification(const Jet& p, float weight/*=1.0*/, const std::string& dir/*=""*/)
{
    /*
    Book( TH1F( "h_jet_matchchi2", "#chi^{2}_{match}(jet);Jets / 5", 50, 0.0, 250.0 ) )
        ->Fill( p.matchchi2(), weight );
    Book( TH1F( "h_jet_matchchi2pdof", "#chi^{2}_{match}(jet)/DOF;Jets / 0.2", 50, 0.0, 10.0 ) )
        ->Fill( p.matchchi2() / p.matchndof(), weight );
    */
}

//____________________________________________________________________________         
void JetSelectorTool::PlotIdentification(const std::vector<Jet>& vec, float weight/*=1.0*/, const std::string& dir/*=""*/)
{
    for(std::vector<Jet>::const_iterator itr = vec.begin(); itr != vec.end(); ++itr)
        PlotIdentification(*itr, weight, dir);
}

//____________________________________________________________________________
void JetSelectorTool::PlotMultiplicity(const std::vector<Jet>& vec, float weight/*=1.0*/, const std::string& dir/*=""*/)
{
    if(!c_multiplicity_pt_cutoffs.empty())
    {
	    int n_pt_cutoffs = (int)c_multiplicity_pt_cutoffs.size();
	    std::vector<int> n_jets(n_pt_cutoffs, 0);
	    
	    // Count the number of jets passing each provided cutoffs 
	    for(std::vector<Jet>::const_iterator itr = vec.begin(); itr != vec.end(); ++itr)
	    {
	        float jet_pt = (*itr).tlv.Pt();
	        
	        for(int i = 0; i < n_pt_cutoffs; ++i)
	    	if( jet_pt > c_multiplicity_pt_cutoffs[i] ) n_jets[i]++;
	    }
	    
	    // Book and/or fill the histograms
	    for(int i = 0; i < n_pt_cutoffs; ++i)
	    {
	        Book( c_multiplicity_pt_cutoffs_hist_names[i].first.c_str(), 
		      c_multiplicity_pt_cutoffs_hist_names[i].second.c_str(), 20, -0.5, 19.5, dir )->Fill(n_jets[i]);
	    }
    }
}

void JetSelectorTool::BeginInputData( const SInputData& id) throw (SError)
{
  int n_pt_cutoffs = c_multiplicity_pt_cutoffs.size();
  for(int i = 0; i < n_pt_cutoffs; ++i)
    {
      std::stringstream hname_ss;
      hname_ss << "h_jet_n_pt" << c_multiplicity_pt_cutoffs[i]/GeV;
      std::string hname = hname_ss.str();
	        
      std::stringstream htitle_ss;
      htitle_ss << ";N(jet, p_{T} > " << c_multiplicity_pt_cutoffs[i]/GeV << ");Events";
      std::string htitle = htitle_ss.str();
      c_multiplicity_pt_cutoffs_hist_names.push_back( std::make_pair(hname, htitle) );
    }
}
