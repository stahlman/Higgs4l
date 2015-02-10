// Dear emacs, this is -*- c++ -*-
// $Id: CycleCreators.py 173 2010-05-12 15:49:33Z krasznaa $
#ifndef ZgammaTruth_H
#define ZgammaTruth_H

// SFrame include(s):
//#include "core/include/SCycleBase.h"
#include "plug-ins/include/SSummedVar.h"

// AtlasSFrameUtils
#include "CycleBase.h"

//D3PDObjects
#include "EventInfoD3PDObject.h"
#include "PrimaryVertexD3PDObject.h"
#include "TriggerD3PDObject.h"
#include "ElectronD3PDObject.h"
#include "PhotonD3PDObject.h"
#include "TruthParticleD3PDObject.h"
#include "METD3PDObject.h"


/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Put your name here
 * @version $Revision: 173 $
 */
class ZgammaTruth : public CycleBase {

public:
   /// Default constructor
   ZgammaTruth();
   /// Default destructor
   ~ZgammaTruth();

   /// Function called at the beginning of the cycle
   virtual void BeginCycleImp() throw( SError );
   /// Function called at the end of the cycle
   virtual void EndCycleImp() throw( SError );

   /// Function called at the beginning of a new input data
  virtual void BeginInputDataImp( const SInputData& ) throw( SError );
   /// Function called after finishing to process an input data
   virtual void EndInputDataImp  ( const SInputData& ) throw( SError );

  virtual void BeginMasterInputDataImp( const SInputData& ) throw( SError );
  virtual void EndMasterInputDataImp( const SInputData& ) throw( SError );

   /// Function called after opening each new input file
   virtual void BeginInputFileImp( const SInputData& ) throw( SError );

   /// Function called for every event
   virtual void ExecuteEventImp( const SInputData&, Double_t ) throw( SError );

private:
   //
   // Put all your private variables here
   //
  bool m_doGRL;
  bool m_doLarError;
  bool m_doTrig;
  bool m_doVert;
  bool DoPileupSF;
  bool DoVertexSF;



  SSummedVar< Int_t > cf_preselect;
  SSummedVar< Int_t > cf_grl;
  SSummedVar< Int_t > cf_larerror;
  SSummedVar< Int_t > cf_vertex;
  SSummedVar< Int_t > cf_trigger;
  SSummedVar< Int_t > cf_tag;
  SSummedVar< Int_t > cf_photon;
  SSummedVar< Int_t > cf_probe;


  std::string m_recoTreeName;

  D3PDReader::EventInfoD3PDObject* m_event_d3pdobject;
  D3PDReader::ElectronD3PDObject* m_electron_d3pdobject;
  D3PDReader::TriggerD3PDObject* m_trigger_d3pdobject;
  D3PDReader::PhotonD3PDObject* m_photon_d3pdobject;
  D3PDReader::PrimaryVertexD3PDObject* m_vxp_d3pdobject;
  D3PDReader::TruthParticleD3PDObject* m_truth_d3pdobject;
  D3PDReader::METD3PDObject* m_met_d3pdobject;

  std::string c_output_event_branches_regex;
  std::string c_output_electron_branches_regex;
  std::string c_output_trigger_branches_regex;
  std::string c_output_photon_branches_regex;
  std::string c_output_vxp_branches_regex;
  std::string c_output_truth_branches_regex;
  std::string c_output_met_branches_regex;


  std::string c_output_tree_name;

  std::vector<Electron*> sel_tags;
  std::vector<ProbeElectron*> sel_probes;
  std::vector<Photon*> sel_photons;

  //Variables to store
  //event
  unsigned int RunNumber;
  unsigned int EventNumber;
  unsigned int lbn;
  unsigned int mc_channel_number;
  int n_vertices3;  

  int tag_n;
  int probe_n;
  int photon_n;

  //probe
  vector<double> probe_E;
  vector<double> probe_Et;
  vector<double> probe_eta;
  vector<double> probe_phi;
 
  vector<int> probe_type;
  vector<int> probe_origin;
  vector<int> probe_originbkg;
  vector<int> probe_truth_matched;
  
  vector<int> probe_index;
  vector<int> probe_tag_index;
  vector<int> probe_tag_vecindex;  
  vector<int> probe_photon_index;
  vector<int> probe_photon_vecindex;
 
  vector<double> probe_tag_mass;
  vector<double> probe_tag_photon_mass;
  vector<double> probe_tag_dR;
  vector<double> probe_photon_dR;

  vector<double> p_tag_photon_mass;
  vector<double> p_tag_photon_dR;

  //OS?
  vector<int> probe_tag_OS;

  //conditions
  vector<int> probe_passML;
  vector<int> probe_passTight;
  //tag conditions
  vector<int> probe_tag_passTight;

  //photon
  vector<double> photon_E;
  vector<double> photon_Et;
  vector<double> photon_eta;
  vector<double> photon_phi;
  vector<double> photon_topoiso20;
  vector<double> photon_topoiso40;
  vector<int> photon_truth_type;
  vector<int> photon_type;
  vector<int> photon_origin;
  vector<int> photon_isConv;

  //tag
  vector<double> tag_E;
  vector<double> tag_Et;
  vector<double> tag_eta;
  vector<double> tag_phi;
  vector<int> tag_index;
  vector<int> tag_type;
  vector<int> tag_origin;
  vector<int> tag_originbkg;
  vector<int> tag_truth_matched;

  //weights
  double evt_weight;
  double pileup_sf;
  double vertex_sf;

   // Macro adding the functions for dictionary generation
   ClassDef( ZgammaTruth, 0 );

}; // class ZgammaTruth

#endif // ZgammaTruth_H

