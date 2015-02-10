// Dear emacs, this is -*- c++ -*-
// $Id: JetSelector.h 25152 2013-10-28 15:27:37Z stahlman $
#ifndef JetSelector_H
#define JetSelector_H

// SFrame include(s):
//#include "plug-ins/include/SSummedVar.h"

// D3PDObjects
#include "JetD3PDObject.h"

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Jet.h"
#include "Electron.h"

//RootCore
#include "egammaAnalysisUtils/EnergyRescaler.h"
#include "JVFUncertaintyTool/JVFUncertaintyTool.h"

/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 25152 $
 */
class JetSelector : public ToolBase {

public:
   /// Default constructor
   JetSelector(SCycleBase* parent, const char* name);
   /// Default destructor
   ~JetSelector();
   
   enum JetType { DEFAULT, HSG1, LOWPT };

   virtual void BeginMasterInputData( const SInputData& ) throw( SError );
   virtual void EndMasterInputData( const SInputData& ) throw( SError );
   virtual void BeginInputFile( const SInputData& ) throw( SError );

   void SelectJets( std::vector<Jet*> &sel_jets, const D3PDReader::JetD3PDObject* m_jet_d3pdobject, double mu, unsigned int npv, JetType type=DEFAULT, bool cutflow=false );
   void SelectJets( std::vector<Jet> &all_jets, std::vector<Jet*> &sel_jets, double mu, unsigned int npv, JetType type=DEFAULT, bool cutflow=false, int syst=0 );

   void RemoveElectronJetOverlap( std::vector<Electron*> &sel_electrons, std::vector<Jet*> &sel_jets, JetType type=DEFAULT, bool cutflow=false);
   
   void JetSystematics( std::vector< unsigned int > &n_jets, std::vector<double> &leading_jet_pt, const D3PDReader::JetD3PDObject* m_jet_d3pdobject, std::vector<Electron*> &sel_electrons, double mu, unsigned int npv,const int EventNumber, JetType jet_type=DEFAULT);

   double Mjj( std::vector<Jet*> &sel_jets);
   double LeadingJetPt( std::vector<Jet*> &sel_jets);
   
   bool VBFCuts( std::vector<Jet*> &sel_jets);
   bool GGFCuts( std::vector<Jet*> &sel_jets);
   bool VHCuts( std::vector<Jet*> &sel_jets);

private:
   //
   // Put all your private variables here
   //
   JVFUncertaintyTool* m_JVFTool;

   int cf_preselect;
   int cf_jetcleaning;    
   int cf_pt;	    
   int cf_eta;
   int cf_jvf;
   int cf_overlap;
   int cf_hottilecellveto;
   
   float m_Eventshape_rhoKt4EM;

   std::string m_recoTreeName;
   bool m_doLowPt;
   bool m_doJetCalibration;
   	       
   double DeltaR(double eta1, double phi1, double eta2, double phi2);
  
  // Macro adding the functions for dictionary generation
   ClassDef( JetSelector, 0 );

  
  

}; // class JetSelector


struct compareJets {
  bool operator()(Jet* left, Jet * right) {
    return left->Pt() > right->Pt();
  }
};

#endif // JetSelector_H
