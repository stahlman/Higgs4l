# include "../include/InvMassTool.h"

#include <iostream>


//____________________________________________________________________________
InvMassTool::InvMassTool()
:  isData(false)
{
  //std::cout<< "InvMassTool::InvMassTool(): start" << std::endl;

  //initialize vectors
  for (unsigned int i = 0; i < InvMassTool::NUMTYPES; ++i){
    m_objects.push_back( std::vector<TLorentzVector>() );
    m_resolutions.push_back( std::vector<double>() );
  }
  //std::cout<< "InvMassTool::InvMassTool(): Found "<< m_objects.size() <<" types."<< std::endl;

  //std::cout<< "InvMassTool::InvMassTool(): electron tool" << std::endl;
  
  //initialize electron tool
  energy_rescaler = new eg2011::EnergyRescaler();
  energy_rescaler->useDefaultCalibConstants("2012");
  
  //std::cout<< "InvMassTool::InvMassTool(): muon tool" << std::endl;

  //initialize muon resolution vectors
  char *m_path = "/../MuonMomentumCorrections/share/";
  char *rc_path = getenv ("ROOTCOREDIR");
  char *path = new char[strlen(rc_path)+strlen(m_path)];
  sprintf(path,"%s%s",rc_path, m_path);

  std::string pathNoRootCore = "RootCore/MuonMomentumCorrections/share/";

  //mcp_res = new MuonSmear::SmearingClass("Data12","staco","pT","Rel17.2_preliminary",path);
  mcp_res = new MuonSmear::SmearingClass("Data12","staco","pT","Rel17.2_preliminary",pathNoRootCore);

  mcp_res->UseScale(1);
  mcp_res->UseImprovedCombine();
  
  delete path; 

  //std::cout<< "InvMassTool::InvMassTool(): end" << std::endl;
  
  return;
}

//____________________________________________________________________________
InvMassTool::~InvMassTool()
{
  
  Reset();
  m_objects.clear();
  
  delete mcp_res;
  delete energy_rescaler;
  
  return;
}


//____________________________________________________________________________
bool InvMassTool::AddParticle(TLorentzVector part, enum InvMassTool::Particle type)
{
  
  if (type > InvMassTool::NUMTYPES - 1 ) {
   std::cout<< "Unkonwn particle type!"<<std::endl;
   return false; 
  }

  //std::cout<< "InvMassTool::AddParticle(): add particle with index " << type << std::endl;
  //std::cout<< "InvMassTool::AddParticle(): objects has size " << m_objects.size() << std::endl;
  int i_type = type; 
  //std::cout<< "InvMassTool::AddParticle(): add particle with index " << i_type << std::endl;
  //std::cout<< "InvMassTool::AddParticle(): add particle with index " << m_objects.at(i_type).size() << std::endl;
  m_objects.at(i_type).push_back(part);
  //std::cout<< "InvMassTool::AddParticle(): DONE "  << std::endl;
     
  return true;
}


//____________________________________________________________________________
bool InvMassTool::AddMuon(double PtCB, double PtMS, double PtID, double Eta, double Phi)
{
  //std::cout<< "InvMassTool::AddParticle(): add muon" << std::endl;

  if ((PtCB > 0) && (PtID > 0) && (PtMS > 0)) { //combined muon
    TLorentzVector muon(0,0,0,0);
    muon.SetPtEtaPhiM(PtCB,Eta,Phi,105.658367);//Assuming MeV
    AddParticle(muon, InvMassTool::MUON);
    
    mcp_res->Event(PtMS, PtID, PtCB, Eta); 
    double res = muon.P()*mcp_res->ExpectedResolution("CB",!isData);
    
    std::cout<< "InvMassTool::AddMuon(): CB Muon: "<<PtCB<<" "<<Eta<<" "<<Phi << std::endl;
    std::cout<< "InvMassTool::AddMuon(): CB resolution: "<<res << std::endl;

    m_resolutions.at(InvMassTool::MUON).push_back(res);
    
    return true;
    
  } else if (PtID > 0) { //ID track only
    TLorentzVector muon(0,0,0,0);
    muon.SetPtEtaPhiM(PtID,Eta,Phi,105.658367);//Assuming MeV
    AddParticle(muon, InvMassTool::MUON);
    
    mcp_res->Event(PtID, Eta, "ID"); 
    double res = muon.P()*mcp_res->ExpectedResolution("ID",!isData);
    
    std::cout<< "InvMassTool::AddMuon(): ID Muon: "<<PtID<<" "<<Eta<<" "<<Phi << std::endl;
    std::cout<< "InvMassTool::AddMuon(): ID resolution: "<<res << std::endl;
    
    m_resolutions.at(InvMassTool::MUON).push_back(res);
    return true;
    
  } else if (PtMS > 0) { //standalone
    TLorentzVector muon(0,0,0,0);
    muon.SetPtEtaPhiM(PtMS,Eta,Phi,105.658367);//Assuming MeV
    AddParticle(muon, InvMassTool::MUON);
    
    mcp_res->Event(PtMS, Eta, "MS"); 
    double res = muon.P()*mcp_res->ExpectedResolution("MS",!isData);

    std::cout<< "InvMassTool::AddMuon(): MS Muon: "<<PtMS<<" "<<Eta<<" "<<Phi << std::endl;
    std::cout<< "InvMassTool::AddMuon(): MS resolution: "<<res << std::endl;
    
    m_resolutions.at(InvMassTool::MUON).push_back(res);
    return true;
  }
      
  std::cout<< "InvMassTool::AddMuon(): No non-zero momentum given!" << std::endl;
  return false;  
}

//____________________________________________________________________________
double InvMassTool::M() 
{

  TLorentzVector comp(0,0,0,0);
  
  for (unsigned int i = 0; i < m_objects.size(); ++i) {
    for (unsigned int j = 0; j < m_objects.at(i).size(); ++j) {
      comp += m_objects.at(i).at(j);
    }
  }
  
  return comp.M();
}


//____________________________________________________________________________
double InvMassTool::SigmaM() 
{
  //std::cout<< "InvMassTool::SigmaM(): start" << std::endl;

  double sigma = 0;   
  
  for (unsigned int i = 0; i < m_objects.size(); ++i) {
    for (unsigned int j = 0; j < m_objects.at(i).size(); ++j) {
            
      double d_term = 0;

      for (unsigned int k = 0; k < m_objects.size(); ++k) {
	for (unsigned int l = 0; l < m_objects.at(k).size(); ++l) {
	  if (i==k && j==l) continue;
	  d_term += m_objects.at(k).at(l).P() * ( 1 - cos( m_objects.at(i).at(j).Angle( m_objects.at(k).at(l).Vect())));
        }
      }
      
      double resolution;
      
      if (i == InvMassTool::MUON){
        resolution = m_resolutions.at(i).at(j);
        //std::cout<< "InvMassTool::SigmaM(): Muon Resolution: "<< resolution <<" MeV"<< std::endl;
      } else {
	resolution = GetResolution(m_objects.at(i).at(j), (InvMassTool::Particle)i );
        //std::cout<< "InvMassTool::SigmaM(): Electron Resolution: "<< resolution <<" MeV"<<  std::endl;
      }
      
      //std::cout<< "InvMassTool::SigmaM(): Resolution: "<< resolution <<" MeV"<<  std::endl;
      
      sigma += d_term*d_term*resolution*resolution;    
    }
  }
  
  double mass = M();
  if (mass != 0) {
    //std::cout<< "Total sigma: " << sqrt(sigma)/mass<< std::endl;
    return ( sqrt(sigma)/mass );
  }

  std::cout<< "InvMassTool::SigmaM(): Mass = 0!  returning sigma = 0" << std::endl;
  return 0;
}

//____________________________________________________________________________
double InvMassTool::GetResolution(TLorentzVector particle, enum InvMassTool::Particle type) 
{

  if (type == InvMassTool::ELECTRON){
    double res_E = energy_rescaler->resolution(particle.E()/1000.0, particle.Eta(),true);
    //std::cout<< "InvMassTool::GetResolution():Electron sigmaE/E: "<< res_E << std::endl;
    return particle.E()*res_E;
  }
    
  std::cout<< "InvMassTool::GetResolution(): Type not found.  Returning bogus value!" << std::endl;
  return 1.0;
}

//____________________________________________________________________________
void InvMassTool::Reset() 
{
  //std::cout<< "InvMassTool::Reset()" << std::endl;

  for (unsigned int i = 0; i < m_objects.size(); ++i) m_objects.at(i).clear();
  for (unsigned int i = 0; i < m_resolutions.size(); ++i) m_resolutions.at(i).clear();
    
  return;
}
