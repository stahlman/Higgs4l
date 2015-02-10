#ifndef CommonTools_JetSelectorTool_h
#define CommonTools_JetSelectorTool_h

#include <vector>
#include <string>

#include "ToolBase.h"
#include "Jet.h"


class JetSelectorTool : public ToolBase {

    public:
        JetSelectorTool(SCycleBase* parent, const char* name);

	void BeginInputData( const SInputData& id) throw (SError);
        int Select(std::vector<Jet>& vec);
        int Select(const std::vector<Jet>& vec, std::vector<Jet>& passed);
        int Select(const std::vector<Jet>& vec, std::vector<Jet>& passed, std::vector<Jet>& failed);
        bool Select( const Jet& p );

	//	void BeginInputData(const SInputData&);

        void PlotKinematics(const Jet& p, float weight=1.0, const std::string& dir="");
        void PlotKinematics(const std::vector<Jet>& vec, float weight=1.0, const std::string& dir="");
        void PlotIdentification(const Jet& p, float weight=1.0, const std::string& dir="");
        void PlotIdentification(const std::vector<Jet>& vec, float weight=1.0, const std::string& dir="");
        void PlotMultiplicity(const std::vector<Jet>& vec, float weight=1.0, const std::string& dir="");

    private:

        // configurables
        double c_min_pt;
	double c_max_pt;
	double c_min_et;
        double c_max_abs_eta;
        std::vector<double> c_excluded_abs_eta_regions;
	std::vector<double> c_multiplicity_pt_cutoffs;
	std::vector<std::pair<std::string,std::string> > c_multiplicity_pt_cutoffs_hist_names;
};

#endif // CommonTools_JetSelectorTool_h
