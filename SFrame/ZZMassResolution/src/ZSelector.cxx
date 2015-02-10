// $Id: ZSelector.cxx 19791 2012-11-14 13:01:11Z stahlman $

#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Muon.h"
#include "Electron.h"
#include "Quadruplet.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "EnergyRescalerTool.h"

//ZZSelection
#include "MuonSelector.h"

//local
#include "../include/ZSelector.h"


const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( ZSelector );

ZSelector::ZSelector()
  : CycleBase()

{

   SetLogName( GetName() );
   DeclareProperty( "RecoTreeString", m_recoTreeName );
   DeclareProperty( "TrigTreeString", m_trigTreeName );
   DeclareProperty( "OutputTreeString", c_output_tree_name = "ModCombStacoParams");   
   
   DeclareProperty("output_event_branches_regex", c_output_event_branches_regex = ".*");
   DeclareProperty("output_mcevt_branches_regex", c_output_mcevt_branches_regex = ".*");
   DeclareProperty("output_electron_trigger_branches_regex", c_output_electron_trigger_branches_regex = ".*");
   DeclareProperty("output_muon_trigger_branches_regex", c_output_muon_trigger_branches_regex = ".*");
   DeclareProperty("output_trigger_branches_regex", c_output_trigger_branches_regex = ".*");
   DeclareProperty("output_vxp_branchegs_regex", c_output_vxp_branches_regex = ".*");
   DeclareProperty("output_electron_branches_regex", c_output_electron_branches_regex = ".*");
   DeclareProperty("output_muon_branches_regex", c_output_muon_branches_regex = ".*");
   DeclareProperty("output_jet_branches_regex", c_output_jet_branches_regex = ".*");
   DeclareProperty("output_met_branches_regex", c_output_met_branches_regex = ".*");
   DeclareProperty("output_truth_branches_regex", c_output_truth_branches_regex = ".*");
   //DeclareProperty("output_photon_branches_regex", c_output_photon_branches_regex = ".*");

    DECLARE_TOOL(MuonSelector,       "MuonSelector");

//    
//    DECLARE_TOOL(EnergyRescalerTool, "EnergyRescalerTool");
// 
//    //mass_tool = new InvMassTool();
// 
//    gRand = new TRandom3();
//    gRand->SetSeed(0);
// 
//    char *m_path = "/../MuonMomentumCorrections/share/";
//    char *rc_path = getenv ("ROOTCOREDIR");
//    char *path = new char[strlen(rc_path)+strlen(m_path)];
//    sprintf(path,"%s%s",rc_path, m_path);
// 
//    m_muResolution = new MuonSmear::SmearingClass("Data12","staco","pT","Rel17.2_preliminary",path);
//    m_muResolution->UseScale(1);
//    m_muResolution->UseImprovedCombine();
//    delete path;

}

ZSelector::~ZSelector() {

  //gRand->Delete();
  //delete m_muResolution;
}

void ZSelector::BeginCycleImp() throw( SError ) {  
  

  return;

}

void ZSelector::EndCycleImp() throw( SError ) {

   return;

}

void ZSelector::BeginInputDataImp( const SInputData& ) throw( SError ) {


  //Declare output variables:  
  DeclareVariable( m_runNumber,   "runNumber"  );
  DeclareVariable( m_evtNumber,   "eventNumber");
  DeclareVariable( m_lumi_block,  "lumi_block" );

  DeclareVariable( m_negative_px, "Negative_Px");
  DeclareVariable( m_negative_py, "Negative_Py");
  DeclareVariable( m_negative_pz, "Negative_Pz");
  DeclareVariable( m_negative_z0, "Negative_z0");
  DeclareVariable( m_negative_d0, "Negative_d0");

  DeclareVariable( m_positive_px, "Positive_Px");
  DeclareVariable( m_positive_py, "Positive_Py");
  DeclareVariable( m_positive_pz, "Positive_Pz");
  DeclareVariable( m_positive_z0, "Positive_z0");
  DeclareVariable( m_positive_d0, "Positive_d0");

  // -----------------------------------------------------------------
  // ---------------- D3PD Reader constuctors ------------------------
  
  // inputs/outputs
  m_event_d3pdobject = new D3PDReader::EventInfoD3PDObject( m_entry_number );
  m_trigger_d3pdobject = new D3PDReader::TriggerD3PDObject( m_entry_number );
  m_vxp_d3pdobject = new D3PDReader::PrimaryVertexD3PDObject( m_entry_number );

  m_electron_d3pdobject = new D3PDReader::ElectronD3PDObject( m_entry_number, "el_" );
  m_muon_staco_d3pdobject = new D3PDReader::MuonD3PDObject( m_entry_number, "mu_staco_" );
  m_muon_calo_d3pdobject = new D3PDReader::MuonD3PDObject( m_entry_number, "mu_calo_" );

  m_truth_d3pdobject = new D3PDReader::TruthParticleD3PDObject( m_entry_number );
   
  // -------------------------------------------------------------
  // ---------------- Activating branches ------------------------

  // control what is read out by setting those branches Active
  // - all branches are Not Active by default
  m_event_d3pdobject->SetActive(kTRUE,c_output_event_branches_regex);
  m_trigger_d3pdobject->SetActive(kTRUE,c_output_trigger_branches_regex);
  m_vxp_d3pdobject->SetActive(kTRUE,c_output_vxp_branches_regex);

  m_electron_d3pdobject->SetActive(kTRUE,c_output_electron_branches_regex);
  m_muon_staco_d3pdobject->SetActive(kTRUE,c_output_muon_branches_regex);
  m_muon_calo_d3pdobject->SetActive(kTRUE,c_output_muon_branches_regex);

  m_truth_d3pdobject->SetActive(kTRUE,c_output_truth_branches_regex);

   return;

}

void ZSelector::EndInputDataImp( const SInputData& ) throw( SError ) {

   // inputs/outputs
    delete m_event_d3pdobject;
    delete m_trigger_d3pdobject;
    delete m_vxp_d3pdobject;

    delete m_electron_d3pdobject;
    delete m_muon_staco_d3pdobject;
    delete m_muon_calo_d3pdobject;

    delete m_truth_d3pdobject;

   return;

}

void ZSelector::BeginInputFileImp( const SInputData& ) throw( SError ) {

    m_logger << DEBUG  << "BeginInputFileImp " << SLogger::endmsg;

    m_event_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_trigger_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_vxp_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_electron_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_staco_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_calo_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_truth_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

   return;

}

void ZSelector::BeginMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZSelector::EndMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZSelector::ExecuteEventImp( const SInputData&, Double_t ) throw( SError ) {
  
  //clear out memory
  for (unsigned int i = 0; i <sel_muons.size(); i++)delete sel_muons.at(i);
  sel_muons.clear();

  //build muon collections
  std::vector<Muon> all_muons;
  ParticleElementBuilder::build( all_muons, (*m_muon_staco_d3pdobject) );

  std::vector<Muon> all_calo_muons;
  ParticleElementBuilder::build( all_calo_muons, (*m_muon_calo_d3pdobject) );
  
  m_logger << DEBUG  << "Lepton collections built" << SLogger::endmsg;

  //select Muons
  GET_TOOL(mu_select, MuonSelector, "MuonSelector");
  mu_select->SelectMuons(sel_muons, m_muon_staco_d3pdobject, m_muon_calo_d3pdobject, m_event_d3pdobject->EventNumber()); 

  //select candidate Z
  std::vector<Muon*> sel_muons_pos;
  std::vector<Muon*> sel_muons_neg;
  
  for (unsigned int i = 0; i < sel_muons.size(); i++){
    if (sel_muons.at(i)->charge() == +1){
      sel_muons_pos.push_back(sel_muons.at(i));
    } else if (sel_muons.at(i)->charge() == -1){
      sel_muons_neg.push_back(sel_muons.at(i));
    }
  }
  
  double mass_diff = -1;
  int index_pos = -1;
  int index_neg = -1;
  
  for (unsigned int i =0; i < sel_muons_pos.size(); i++) {
      for (unsigned int j =0; j < sel_muons_neg.size(); j++) {
	  TLorentzVector tlv_pos; tlv_pos.SetPtEtaPhiM(sel_muons_pos[i]->Pt(), sel_muons_pos[i]->eta(), sel_muons_pos[i]->phi(), sel_muons_pos[i]->m());
	  TLorentzVector tlv_neg; tlv_neg.SetPtEtaPhiM(sel_muons_neg[j]->Pt(), sel_muons_neg[j]->eta(), sel_muons_neg[j]->phi(), sel_muons_neg[j]->m());
	  double m_diff = fabs(91187.6 - (tlv_pos + tlv_neg).M());
	  if (mass_diff == -1 || m_diff < mass_diff) {
	     mass_diff = m_diff;
	     index_pos = i;
	     index_neg = j;
	  }
     }   
  }

  if (index_pos == -1 || index_neg == -1) {
    //m_logger << DEBUG  << "No reconstructed Z candidate found - Skipping event" << SLogger::endmsg;
    throw SError( SError::SkipEvent );  
  }
  
  
  Muon* mu_pos = sel_muons_pos[index_pos];
  Muon* mu_neg = sel_muons_neg[index_neg];

  TLorentzVector tlv_pos; tlv_pos.SetPtEtaPhiM(mu_pos->Pt(), mu_pos->eta(), mu_pos->phi(), mu_pos->m());
  TLorentzVector tlv_neg; tlv_neg.SetPtEtaPhiM(mu_neg->Pt(), mu_neg->eta(), mu_neg->phi(), mu_neg->m());
  
  
  m_logger << DEBUG << "Found Z event! Mass: " << (tlv_pos+tlv_neg).M() << SLogger::endmsg;


  //calculate modified momentum
  double qoverp_cb_new_pos = 0;
  double qoverp_cb_new_neg = 0;
  
  //assume for now only combined muons 
  qoverp_cb_new_pos = ( (mu_pos->id_qoverp_exPV()/mu_pos->id_cov_qoverp_exPV()) +  (mu_pos->me_qoverp_exPV()/mu_pos->me_cov_qoverp_exPV()))/ ((1/mu_pos->id_cov_qoverp_exPV())+(1/mu_pos->me_cov_qoverp_exPV()));  
  qoverp_cb_new_neg = ( (mu_neg->id_qoverp_exPV()/mu_neg->id_cov_qoverp_exPV()) +  (mu_neg->me_qoverp_exPV()/mu_neg->me_cov_qoverp_exPV()))/ ((1/mu_neg->id_cov_qoverp_exPV())+(1/mu_neg->me_cov_qoverp_exPV()));
  
  //tlv_pos.SetPtEtaPhiM(fabs(1/qoverp_cb_new_pos)*sin(tlv_pos.Theta()), mu_pos->eta(), mu_pos->phi(), mu_pos->m());
  //tlv_neg.SetPtEtaPhiM(fabs(1/qoverp_cb_new_neg)*sin(tlv_neg.Theta()), mu_neg->eta(), mu_neg->phi(), mu_neg->m());
  
  //fill parameters for output
  m_runNumber  =  m_event_d3pdobject->RunNumber();
  m_evtNumber  =  m_event_d3pdobject->EventNumber();
  m_lumi_block =  m_event_d3pdobject->lbn();

  m_logger << DEBUG << "Saving params: " << tlv_neg.Px()<< " " << tlv_neg.Py()<< " " <<tlv_neg.Pz() << SLogger::endmsg;

  m_negative_px = tlv_neg.Px();
  m_negative_py = tlv_neg.Py();
  m_negative_pz = tlv_neg.Pz();
  m_negative_z0 = 0;
  m_negative_d0 = 0;

  m_positive_px = tlv_pos.Px();
  m_positive_py = tlv_pos.Py();
  m_positive_pz = tlv_pos.Pz();
  m_positive_z0 = 0;
  m_positive_d0 = 0;
  
   

//   //find truth particles
//   vector<TruthParticle> truth_Z;
//   vector<TruthParticle> truth_leptons;
// 
//   std::vector<TruthParticle> tparts;
//   ParticleElementBuilder::build(tparts, (*m_truth_d3pdobject));
// 
//   m_logger << DEBUG  << "Number of Truth Particles: "<< tparts.size() << SLogger::endmsg;
// 
//   for (unsigned int i = 0; i < tparts.size(); i++) {
//      if (tparts[i].pdgId() == PDG::Z0 && tparts[i].status() == 62) {
// 	m_logger << DEBUG << "Found Z boson Truth Particle"<<tparts[i].status() << SLogger::endmsg;  
// 	truth_Z.push_back( tparts[i] );
// 
//         for (unsigned int j = 0; j < tparts[i].child_index().size(); j++) {
//            int l_index = tparts[i].child_index()[j];	                	        
// 	   //Only look for muons.... 
// 	   if (( tparts[l_index].pdgId() == PDG::mu_minus || tparts[l_index].pdgId() == PDG::mu_plus )) {
//    	       m_logger << DEBUG << "Found lepton from Z->ll decay! " << tparts[l_index].pdgId() << " "<< tparts[l_index].status() << SLogger::endmsg;  
//    	       if(tparts[l_index].status() == 1) truth_leptons.push_back( tparts[l_index] );			 
// 	   }
// 	}
//      }
//   }
// 
//   if (truth_Z.size() != 1)       { 
//     m_logger << WARNING << "Found "<< truth_Z.size() << " Z boson truth particles! Skipping event" << SLogger::endmsg;  
//     throw SError( SError::SkipEvent ); 
//   }
//   if (truth_leptons.size() != 2) { 
//     m_logger << WARNING << "Found "<< truth_leptons.size() << " lepton truth particles! Skipping event" << SLogger::endmsg;  
//     throw SError( SError::SkipEvent ); 
//   }
//       
//   //assign l1 positive and l2 negative
//   int index_l1 = truth_leptons[0].charge() > 0 ? 0 : 1;
//   int index_l2 = truth_leptons[0].charge() > 0 ? 1 : 0;
//   
//   //truth 4-vectors
//   TLorentzVector tlv_truth_pos; tlv_truth_pos.SetPtEtaPhiM(truth_leptons[index_l1].pt(), truth_leptons[index_l1].eta(), truth_leptons[index_l1].phi(), truth_leptons[index_l1].m());
//   TLorentzVector tlv_truth_neg; tlv_truth_neg.SetPtEtaPhiM(truth_leptons[index_l2].pt(), truth_leptons[index_l2].eta(), truth_leptons[index_l2].phi(), truth_leptons[index_l2].m());
  

 return;

}



