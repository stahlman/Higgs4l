#ifndef CommonTools_CleaningTool_H
#define CommonTools_CleaningTool_H

#include "Jet.h"
#include "Tau.h"
#include "ToolBase.h"
#include "JetID_v2.0.h"

#include <vector>


class CleaningTool : public ToolBase
{
    public:
        CleaningTool( SCycleBase* parent, const char* name = "Cleaning" );
 	void BeginInputData(const SInputData& ) throw( SError );
        
        // configurable function for Bad cut
        bool IsPassedBad( const Jet& p );
        
        inline void SetLoose() {m_tightness = JetID::LooseBad;}
        inline void SetMedium() {m_tightness = JetID::MediumBad;}
        inline void SetTight() {m_tightness = JetID::TightBad;}
        
        // LarError event level checking
        bool IsPassedLarError( const unsigned int& larError );
        
        // check whether tool is configured to do cleaning
        inline bool IsOnJetCleaning() {return c_do_jet_cleaning;}

    private:

        // configurables
        //--------------------------
        double c_min_pt; // GeV
        bool c_do_jet_cleaning;
        std::string c_tightness_str;
        bool c_do_lar_error_cleaning;
        
        JetID::BadJetCategory m_tightness;
        
}; // class CleaningTool

#endif // CommonTools_CleaningTool_H
