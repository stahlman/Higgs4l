#ifndef AtlasSframeUtils_Quadruplet_h
#define AtlasSframeUtils_Quadruplet_h

#include <vector>

//Root include(s):
#include "TLorentzVector.h"
#include "TObject.h"

//RootCore
#include "HiggsZZ4lUtils/GetElicityAngles.h"

//Local include(s):
#include "Muon.h"
#include "Electron.h"
#include "Jet.h"

class Quadruplet : public TObject {

 public:
  //default constructor
  Quadruplet();  

  // constructors
  Quadruplet(Muon* l1, Muon* l2, Muon* l3, Muon* l4);  
  Quadruplet(Electron* l1, Electron* l2, Electron* l3, Electron* l4);
  Quadruplet(Muon* l1, Muon* l2, Electron* l3, Electron* l4);
  Quadruplet(Electron* l1, Electron* l2, Muon* l3, Muon* l4);
  
  enum QuadType {

   FourMuon           ,  
   FourElectron       ,  
   TwoMuonTwoElectron ,
   TwoElectronTwoMuon ,
   
  };
  
  QuadType Type() { return quadtype;};
    
  double M4l() { return    TLV().M();};
  double M12() { return Z1_TLV().M();};
  double M34() { return Z2_TLV().M();};

  double M4l_fsr() { return (   TLV()+tlv_Z1_FSR+tlv_Z2_FSR).M();};
  double M12_fsr() { return (Z1_TLV()+tlv_Z1_FSR).M();};
  double M34_fsr() { return (Z2_TLV()+tlv_Z2_FSR).M();};  
  
  double M4l_constrained() { return    TLV_constrained().M();};
  double M12_constrained() { return Z1_TLV_constrained().M();};
  double M34_constrained() { return Z2_TLV_constrained().M();};

  double Pt4l() { return TLV().Pt();};
  double PtZ1() { return Z1_TLV().Pt();};
  double PtZ2() { return Z2_TLV().Pt();};

  double Pt4l_fsr() { return    (TLV()+tlv_Z1_FSR+tlv_Z2_FSR).Pt();};
  double PtZ1_fsr() { return (Z1_TLV()+tlv_Z1_FSR).Pt();};
  double PtZ2_fsr() { return (Z2_TLV()+tlv_Z2_FSR).Pt();};

  double Pt4l_constrained() { return    TLV_constrained().Pt();};
  double PtZ1_constrained() { return Z1_TLV_constrained().Pt();};
  double PtZ2_constrained() { return Z2_TLV_constrained().Pt();};

  double Y4l_unconstrained() { return    TLV().Rapidity();};
  double Y4l_constrained()   { return    TLV_constrained().Rapidity();};
  double Y4l_fsr()           { return   (TLV()+tlv_Z1_FSR+tlv_Z2_FSR).Rapidity();};

  double Eta4l_unconstrained() { return    TLV().Eta();};
  double Eta4l_constrained()   { return    TLV_constrained().Eta();};
  double Eta4l_fsr()           { return   (TLV()+tlv_Z1_FSR+tlv_Z2_FSR).Eta();};

  double M14();
  double M23();  
  double M4l_ID();
 
  int n_StandAloneMuons();
  int n_CaloTagMuons(); 

  void LeptonType(std::vector<int> &types);
  void LeptonIndex(std::vector<int> &index);
  void LeptonPt(std::vector<double> &pt);
  void LeptonEta(std::vector<double> &eta);
  void LeptonPhi(std::vector<double> &phi);
  void LeptonM(std::vector<double> &m);
  void LeptonCovMom(std::vector<double> &m);
  void LeptonIDPt(std::vector<double> &pt);
  void LeptonIDEta(std::vector<double> &eta);
  void LeptonIDPhi(std::vector<double> &phi);
  void LeptonTrkIsolation(std::vector<double> &trk_iso, int muon_cone_size=20, int electron_cone_size=20);  
  void LeptonCaloIsolation(std::vector<double> &calo_iso, bool isMC, int muon_cone_size=20, int electron_cone_size=20, int sub_electron_cone_size=18);  
  void LeptonD0Significance(std::vector<double> &d0_sig, bool isMC);
  void LeptondRJet(std::vector<double> &dr_jet, std::vector<Jet*> jets);
  
  double MinDeltaRSF();
  double MinDeltaROF();

  void GetMuons(std::vector<Muon*> &leptons);
  void GetElectrons(std::vector<Electron*> &leptons);

  void GetMuonTLVs(std::vector<TLorentzVector*> &leptons);
  void GetElectronTLVs(std::vector<TLorentzVector*> &leptons);
  void GetLeptonTLVs(std::vector<TLorentzVector*> &leptons);

  TLorentzVector TLV();
  TLorentzVector Z1_TLV();
  TLorentzVector Z2_TLV();  
  
  TLorentzVector TLV_constrained()    { return tlv_4l_constrained;};
  TLorentzVector Z1_TLV_constrained() { return tlv_z1_constrained;};
  TLorentzVector Z2_TLV_constrained() { return tlv_z2_constrained;};
  
  void SetTLV_constrained(TLorentzVector t)    { tlv_4l_constrained = t; };
  void SetZ1_TLV_constrained(TLorentzVector t) { tlv_z1_constrained = t; };
  void SetZ2_TLV_constrained(TLorentzVector t) { tlv_z2_constrained = t; };
  
  void SetM4lErr( double err) { m4lerr = err; };
  double M4lErr() { return m4lerr; };
  void SetM4lErr_fsr( double err) { m4lerr_fsr = err; };
  double M4lErr_fsr() { return m4lerr_fsr; };
  void SetM4lErr_constrained( double err) { m4lerr_constrained = err; };
  double M4lErr_constrained() { return m4lerr_constrained; };
  
  double DeltaR(double eta1, double phi1, double eta2, double phi2); 
    
  void CalculateTrkIso(int muon_cone_size, int electron_cone_size);
  double CalculateTrkIso(Muon* muon, int cone_size);
  double CalculateTrkIso(Electron* electron, int cone_size);
  
  void CalculateCaloIso(int muon_cone_size, int electron_cone_size, int sub_electron_cone_size, bool isMC);
  double CalculateCaloIso(Muon* muon, int muon_cone_size, int sub_electron_cone_size);
  double CalculateCaloIso(Electron* electron, int electron_cone_size, int sub_electron_cone_size, bool isMC);
  
  void CalculateD0Significance(bool isMC);
  
  void getElicityAngles( float* cthstr, float* phi1, float* cth1, float* cth2, float* phi );
  
  void addFSR( TLorentzVector fsr, int index, int type);
  bool hasFSR()  { return (m_index_FSR != -1);};
  int index_FSR()  { return m_index_FSR;};
  int type_FSR()   { return m_type_FSR;};
  TLorentzVector getFSR_TLV() { return tlv_Z1_FSR+tlv_Z2_FSR;};

  void setPassedTrigger(bool b){passed_trigger = b;};
  bool getPassedTrigger(void) {return passed_trigger;};

 private:

  QuadType quadtype;
  std::vector<int> lepton_type;
  std::vector<int> lepton_index;
  
  std::vector<Electron*> v_electrons;
  std::vector<Muon*> v_muons;
    
  unsigned int n_muons;
  unsigned int n_electrons;
  
  std::vector<double> lepton_trk_iso;
  std::vector<double> lepton_calo_iso;
  std::vector<double> lepton_d0_sig;

  int m_index_FSR; //associate fsr with Z1 (0) or Z2 (1)
  int m_type_FSR;  //0 for electron, 1 for converted photon, 2 for unconverted photon
  bool passed_trigger;
  TLorentzVector tlv_Z1_FSR; 
  TLorentzVector tlv_Z2_FSR; 

  TLorentzVector tlv_4l_constrained; 
  TLorentzVector tlv_z1_constrained; 
  TLorentzVector tlv_z2_constrained; 

  double m4lerr;
  double m4lerr_fsr;
  double m4lerr_constrained;

    
  ClassDef(Quadruplet, 1)

};


#endif
