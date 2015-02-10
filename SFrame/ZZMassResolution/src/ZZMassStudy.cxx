// $Id: ZZMassStudy.cxx 19791 2012-11-14 13:01:11Z stahlman $

#include <math.h>

// AtlasSFrameUtils
#include "CycleMacros.h"
#include "Muon.h"
#include "Electron.h"
#include "Quadruplet.h"
#include "ParticleElementBuilder.h"

//Common Tools
#include "EnergyRescalerTool.h"

//local
#include "../include/ZZMassStudy.h"


const float M_MU = 105.658367;
const float GeV = 1000.0;

ClassImp( ZZMassStudy );

ZZMassStudy::ZZMassStudy()
  : CycleBase()

{

   SetLogName( GetName() );
   DeclareProperty( "RecoTreeString", m_recoTreeName );
   DeclareProperty( "TrigTreeString", m_trigTreeName );
   DeclareProperty( "OutputTreeString", c_output_tree_name = "output");   
   
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
   
   DECLARE_TOOL(EnergyRescalerTool, "EnergyRescalerTool");

   mass_tool = new InvMassTool();

}

ZZMassStudy::~ZZMassStudy() {

}

void ZZMassStudy::BeginCycleImp() throw( SError ) {  
  

  return;

}

void ZZMassStudy::EndCycleImp() throw( SError ) {

   return;

}

void ZZMassStudy::BeginInputDataImp( const SInputData& ) throw( SError ) {


  //Declare output variables:  
  DeclareVariable( m_4l, "m_4l");
  DeclareVariable( m_12, "m_12");
  DeclareVariable( m_34, "m_34");

  DeclareVariable( m4l_sigma, "m4l_sigma");
  DeclareVariable( m4l_pull,  "m4l_pull");
  
  DeclareVariable( truth_m_H,  "truth_m_H");
  DeclareVariable( truth_m_Z1, "truth_m_Z1");
  DeclareVariable( truth_m_Z2, "truth_m_Z2");

  DeclareVariable( truth_m_4l, "truth_m_4l");
  DeclareVariable( truth_m_4l_gamma, "truth_m_4l_gamma");
  DeclareVariable( truth_m_12, "truth_m_12");
  DeclareVariable( truth_m_34, "truth_m_34");

  DeclareVariable( delta_m_4l_truth_m_4l,       "delta_m_4l_truth_m_4l" );
  DeclareVariable( delta_m_4l_truth_m_4l_gamma, "delta_m_4l_truth_m_4l_gamma" );
  DeclareVariable( delta_m_4l_truth_m_H,        "delta_m_4l_truth_m_H" );
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

void ZZMassStudy::EndInputDataImp( const SInputData& ) throw( SError ) {

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

void ZZMassStudy::BeginInputFileImp( const SInputData& ) throw( SError ) {

    m_logger << DEBUG  << "BeginInputFileImp " << SLogger::endmsg;

    m_event_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_trigger_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_vxp_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_electron_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_staco_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );
    m_muon_calo_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    m_truth_d3pdobject->ReadFrom( GetInputTree(m_recoTreeName.c_str()) );

    ConnectVariable( m_recoTreeName.c_str(), "quad_type", quad_type );
    ConnectVariable( m_recoTreeName.c_str(), "lepton_type", lepton_type);
    ConnectVariable( m_recoTreeName.c_str(), "lepton_index",lepton_index );

    ConnectVariable( m_recoTreeName.c_str(), "m_4l",m_4l );
    ConnectVariable( m_recoTreeName.c_str(), "m_12",m_12 );
    ConnectVariable( m_recoTreeName.c_str(), "m_34",m_34 );

   return;

}

void ZZMassStudy::BeginMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZZMassStudy::EndMasterInputDataImp( const SInputData& ) throw( SError ){


  return;

}

void ZZMassStudy::ExecuteEventImp( const SInputData&, Double_t ) throw( SError ) {

  //Retrieve selected quadruplet 
  
  //TODO This does not take into account calibration/smearing - very bad!!!!  Need to fix this....
  GET_TOOL(energy_rescaler, EnergyRescalerTool, "EnergyRescalerTool");
  
  std::vector<Electron> all_eles;
  ParticleElementBuilder::build( all_eles, (*m_electron_d3pdobject) );
  //energy_rescaler->ApplyEnergyRescaler( all_eles, m_event_d3pdobject->EventNumber());
  
  std::vector<Muon> all_muons;
  ParticleElementBuilder::build( all_muons, (*m_muon_staco_d3pdobject) );
  //energy_rescaler->ApplyEnergyRescaler( all_muons, m_event_d3pdobject->EventNumber());

  std::vector<Muon> all_calo_muons;
  ParticleElementBuilder::build( all_calo_muons, (*m_muon_calo_d3pdobject) );
  //energy_rescaler->ApplyEnergyRescaler( all_muons, m_event_d3pdobject->EventNumber());
  
  m_logger << DEBUG  << "Lepton collections built" << SLogger::endmsg;

  Quadruplet* quad = 0;
  
  if (quad_type == Quadruplet::FourElectron) {
    Electron* l1 = new Electron( all_eles.at(lepton_index->at(0)) );
    Electron* l2 = new Electron( all_eles.at(lepton_index->at(1)) );
    Electron* l3 = new Electron( all_eles.at(lepton_index->at(2)) );
    Electron* l4 = new Electron( all_eles.at(lepton_index->at(3)) );
    quad = new Quadruplet(l1,l2,l3,l4);  

  } else if (quad_type == Quadruplet::FourMuon) {
    //m_logger << DEBUG  << "Making Muons: "<< lepton_index->at(0) << " type "<< lepton_type->at(0) <<  " of " << all_muons.size() << " "<<all_calo_muons.size()  << SLogger::endmsg;
    //m_logger << DEBUG  << "Making Muons: "<< lepton_index->at(1) << " type "<< lepton_type->at(1) <<  " of " << all_muons.size() << " "<<all_calo_muons.size()  << SLogger::endmsg;
    //m_logger << DEBUG  << "Making Muons: "<< lepton_index->at(2) << " type "<< lepton_type->at(2) <<  " of " << all_muons.size() << " "<<all_calo_muons.size()  << SLogger::endmsg;
    //m_logger << DEBUG  << "Making Muons: "<< lepton_index->at(3) << " type "<< lepton_type->at(3) <<  " of " << all_muons.size() << " "<<all_calo_muons.size()  << SLogger::endmsg;
    Muon* l1 = new Muon( fabs(lepton_type->at(0)) == 2 ? all_muons.at(lepton_index->at(0)) : all_calo_muons.at(lepton_index->at(0)));
    Muon* l2 = new Muon( fabs(lepton_type->at(1)) == 2 ? all_muons.at(lepton_index->at(1)) : all_calo_muons.at(lepton_index->at(1)));
    Muon* l3 = new Muon( fabs(lepton_type->at(2)) == 2 ? all_muons.at(lepton_index->at(2)) : all_calo_muons.at(lepton_index->at(2)));
    Muon* l4 = new Muon( fabs(lepton_type->at(3)) == 2 ? all_muons.at(lepton_index->at(3)) : all_calo_muons.at(lepton_index->at(3)));
    m_logger << DEBUG  << "Making Quad" << SLogger::endmsg;
    quad = new Quadruplet(l1,l2,l3,l4);  

  } else if (quad_type == Quadruplet::TwoMuonTwoElectron) {  
    Muon* l1 = new Muon( fabs(lepton_type->at(0)) == 2 ? all_muons.at(lepton_index->at(0)) : all_calo_muons.at(lepton_index->at(0)));
    Muon* l2 = new Muon( fabs(lepton_type->at(1)) == 2 ? all_muons.at(lepton_index->at(1)) : all_calo_muons.at(lepton_index->at(1)));
    Electron* l3 = new Electron( all_eles.at(lepton_index->at(2)) );
    Electron* l4 = new Electron( all_eles.at(lepton_index->at(3)) );
    quad = new Quadruplet(l1,l2,l3,l4);    

  } else if (quad_type == Quadruplet::TwoElectronTwoMuon) {  
    Electron* l1 = new Electron( all_eles.at(lepton_index->at(0)) );
    Electron* l2 = new Electron( all_eles.at(lepton_index->at(1)) );
    Muon* l3 = new Muon( fabs(lepton_type->at(2)) == 2 ? all_muons.at(lepton_index->at(2)) : all_calo_muons.at(lepton_index->at(2)));
    Muon* l4 = new Muon( fabs(lepton_type->at(3)) == 2 ? all_muons.at(lepton_index->at(3)) : all_calo_muons.at(lepton_index->at(3)));
    quad = new Quadruplet(l1,l2,l3,l4);    
  }

  if (!quad) { 
     m_logger << WARNING  << "Quad type incorrect!" << SLogger::endmsg; 
     return;
  }
  
  if ((quad->M4l() != m_4l) ||(quad->M12() != m_12) || (quad->M34() != m_34)) {

    m_logger << WARNING  << "Rebuilt Quad is not the same as the saved quad " << SLogger::endmsg;
    
  }

  //find truth masses
  vector<TruthParticle> truth_higgs;
  vector<TruthParticle> truth_Zs;
  vector<TruthParticle> truth_leptons;
  //Truth Studies

  std::vector<TruthParticle> tparts;
  ParticleElementBuilder::build(tparts, (*m_truth_d3pdobject));

  double n_higgs = 0;

  m_logger << DEBUG  << "Number of Truth Particles: "<< tparts.size() << SLogger::endmsg;

  for (unsigned int i = 0; i < tparts.size(); i++) {
     if (tparts[i].pdgId() == PDG::Higgs0 && (tparts[i].status() == 62 )) {
	m_logger << DEBUG << "Found Higgs Truth Particle"<<tparts[i].status() << SLogger::endmsg;  
	truth_higgs.push_back( tparts[i] );
        n_higgs++;

        for (unsigned int j = 0; j < tparts[i].child_index().size(); j++) {
           int z_index = tparts[i].child_index()[j];	              
	   if (tparts[z_index].pdgId() == PDG::Z0) {
	      
	      truth_Zs.push_back( tparts[z_index]);
	     
	      //std::vector<TruthParticle> children;  
              //tparts[z_index].GetChildren(children);
              int n_leptons =0;
              for (unsigned int k = 0; k < tparts[z_index].child_index().size(); k++) {
	        int l_index = tparts[z_index].child_index()[k];
  	        
		//Only look for electron and muons.... 
		if ((tparts[l_index].pdgId() == PDG::e_minus  ||
  	             tparts[l_index].pdgId() == PDG::e_plus   ||
  	             tparts[l_index].pdgId() == PDG::mu_minus ||
  	             tparts[l_index].pdgId() == PDG::mu_plus )) {
		    n_leptons++;
   	            m_logger << DEBUG << "Found lepton from H->ZZ->4l decay! " << tparts[l_index].pdgId() << " "<< tparts[l_index].status() << SLogger::endmsg;  
   	            if(tparts[l_index].status() == 1) truth_leptons.push_back( tparts[l_index] );			 
		}
	      }
 	   }
	}
     }
  }

  if (truth_higgs.size() != 1)   { m_logger << WARNING << "Found "<< truth_higgs.size() << " Higgs truth particles! Skipping event" << SLogger::endmsg; throw SError( SError::SkipEvent ); }
  if (truth_Zs.size() != 2)      { m_logger << WARNING << "Found "<< truth_Zs.size() << " Z boson truth particles! Skipping event" << SLogger::endmsg;  throw SError( SError::SkipEvent ); }
  if (truth_leptons.size() != 4) { m_logger << WARNING << "Found "<< truth_leptons.size() << " lepton truth particles! Skipping event" << SLogger::endmsg;  throw SError( SError::SkipEvent ); }
  
  m_logger << DEBUG << "Filling truth m12 and m34: "<<truth_Zs[0].m()<< " " << truth_Zs[1].m() << SLogger::endmsg;  
  
  //determine indices of Z1, Z2
  int index_Z12 = fabs(truth_Zs[0].m() - 91187.6) > fabs(truth_Zs[1].m() - 91187.6) ? 1 : 0;
  int index_Z34 = fabs(truth_Zs[0].m() - 91187.6) > fabs(truth_Zs[1].m() - 91187.6) ? 0 : 1;
  
  //assign l1, l3 positive and l2,l4 negative
  int index_l1 = 2*index_Z12 + ( tparts[2*index_Z12].pdgId() > 0 ? 0 : 1);
  int index_l2 = 2*index_Z12 + ( tparts[2*index_Z12].pdgId() > 0 ? 1 : 0);
  int index_l3 = 2*index_Z34 + ( tparts[2*index_Z34].pdgId() > 0 ? 0 : 1);
  int index_l4 = 2*index_Z34 + ( tparts[2*index_Z34].pdgId() > 0 ? 1 : 0);

  TLorentzVector v_l1; v_l1.SetPtEtaPhiM(truth_leptons[index_l1].pt(), truth_leptons[index_l1].eta(), truth_leptons[index_l1].phi(), truth_leptons[index_l1].m());
  TLorentzVector v_l2; v_l2.SetPtEtaPhiM(truth_leptons[index_l2].pt(), truth_leptons[index_l2].eta(), truth_leptons[index_l2].phi(), truth_leptons[index_l2].m());
  TLorentzVector v_l3; v_l3.SetPtEtaPhiM(truth_leptons[index_l3].pt(), truth_leptons[index_l3].eta(), truth_leptons[index_l3].phi(), truth_leptons[index_l3].m());
  TLorentzVector v_l4; v_l4.SetPtEtaPhiM(truth_leptons[index_l4].pt(), truth_leptons[index_l4].eta(), truth_leptons[index_l4].phi(), truth_leptons[index_l4].m());
  
  //find nearby photons
  vector<TruthParticle> truth_photons_nearby;

  for (unsigned int i = 0; i < tparts.size(); i++) {
        
    if (!(tparts[i].status() == 1 && tparts[i].pdgId() == PDG::gamma && tparts[i].barcode() < 200000)) continue;   //only consider final state photons 
    m_logger << DEBUG << "Found truth photon with status: "<< tparts[i].status() << SLogger::endmsg;  
    
    //check parent object (cross check)
    std::vector<int> p_index = tparts[i].parent_index(); 

    if (tparts[i].parent_index().size() == 0 ) continue;    
    //if (p_index.size() !=0 ) m_logger << DEBUG << "Particle (" << tparts[i].pdgId()<< ") has "<< p_index.size()<< " parent(s)"<<  SLogger::endmsg;       
    
    for (unsigned int j = 0; j < p_index.size(); j++){
      m_logger << DEBUG << "Parent ID: "<< tparts[p_index[j]].pdgId() << SLogger::endmsg;	
    }
    //if ( tparts[p_index].charge() == 0) {
    //  m_logger << INFO << "Removing Photon becase parent has charge 0"<< SLogger::endmsg;       
    //  continue;
    //}
    
    
    for (unsigned int j = 0; j < truth_leptons.size(); j++){
      
      //if (i==truth_leptons[j].GetIndex()) continue; //don't double count truth leptons!
      
      double delta_eta = tparts[i].eta() - truth_leptons[j].eta();
      double delta_phi = tparts[i].phi() - truth_leptons[j].phi();
      double deltaR = sqrt(delta_eta*delta_eta + delta_phi*delta_phi);

      if (deltaR < 0.1){
        m_logger << DEBUG << "Found photon (" << tparts[i].pdgId()<< ") with Delta R: "<< deltaR << " and pT: " <<tparts[i].pt()<< SLogger::endmsg;  
	truth_photons_nearby.push_back(tparts[i]);
	break;
      }
    }
  }


/*
  for (unsigned int i = 0; i < truth_leptons.size(); i++){
    
    vector<int> i_children = truth_leptons[i].children();
    m_logger << INFO << "Found " <<i_children.size()<< " children " << SLogger::endmsg;  
      
    for (unsigned int j = 0; j < truth_leptons[i].child_index().size(); j++){
      int child_index = truth_leptons[i].child_index()[j];
      m_logger << INFO << "Found child: " <<tparts[j].pdgId() << SLogger::endmsg;  
      double delta_eta = tparts[child_index].eta() - truth_leptons[i].eta();
      double delta_phi = tparts[child_index].phi() - truth_leptons[i].phi();
      double deltaR = sqrt(delta_eta*delta_eta + delta_phi*delta_phi);

      if (deltaR < 0.05){
	m_logger << INFO << "Found photon with Delta R: "<< deltaR << " and pT: " <<tparts[child_index].pt()<< SLogger::endmsg;  
	truth_photons_nearby.push_back(tparts[child_index]);
	break;
      }
    }
  }
*/

  m_logger << DEBUG << "Found " <<truth_photons_nearby.size()<< " nearby photons " << SLogger::endmsg;  
  TLorentzVector v_photons;
  for (unsigned int i = 0; i < truth_photons_nearby.size(); i++) {
    TLorentzVector t_photon; t_photon.SetPtEtaPhiM(truth_photons_nearby[i].pt(),truth_photons_nearby[i].eta(),truth_photons_nearby[i].phi(),truth_photons_nearby[i].m());
    v_photons += t_photon;
  }
  
  //save quantities
  truth_m_H  = truth_higgs[0].m();
  truth_m_Z1 = truth_Zs[index_Z12].m();
  truth_m_Z2 = truth_Zs[index_Z34].m();
  
  truth_m_4l = (v_l1+v_l2+v_l3+v_l4).M();
  truth_m_4l_gamma = (v_l1+v_l2+v_l3+v_l4+v_photons).M();
  truth_m_12 = (v_l1+v_l2).M();
  truth_m_34 = (v_l3+v_l4).M();
  
    
  m_4l = quad->M4l();
  m_12 = quad->M12();
  m_34 = quad->M34();    
  
  delta_m_4l_truth_m_4l = truth_m_H - truth_m_4l_gamma;
  delta_m_4l_truth_m_4l_gamma = m_4l - truth_m_4l_gamma;
  delta_m_4l_truth_m_H = m_4l - truth_m_H;
  
  m4l_sigma = quad->CalculateSigmaM(mass_tool);
  
  //m4l_pull = (m_4l - truth_m_H)/m4l_sigma;
  m4l_pull = (m_4l - truth_m_4l_gamma)/m4l_sigma;
  //m4l_pull = (m_4l - truth_m4l) / m4l_sigma;  

 return;

}
