// Dear emacs, this is -*- c++ -*-
// $Id: QuadSelector.h 26117 2014-02-04 21:06:31Z stahlman $
#ifndef QuadSelector_H
#define QuadSelector_H

// AtlasSFrameUtils
#include "ToolBase.h"
#include "Electron.h"
#include "Muon.h"
#include "Quadruplet.h"

/**
 *   @short Class to make and select quadruplets
 *
 *          Put a longer description over here...
 *
 *  @author Jonathan Stahlman
 * @version $Revision: 26117 $
 */
class QuadSelector : public ToolBase {

public:
   /// Default constructor
   QuadSelector(SCycleBase* parent, const char* name);
   /// Default destructor
   ~QuadSelector();

   virtual void EndMasterInputData( const SInputData& ) throw( SError );

   void MakeQuadruplets( std::vector<Electron*> sel_electrons, std::vector<Muon*> sel_muons, std::vector<Quadruplet*> &all_quads );
   void SelectQuadruplets( std::vector<Quadruplet*> &all_quads, std::vector<Quadruplet*> &sel_quads, int n_vertices );
  Quadruplet* SelectFinalQuadruplet( std::vector<Quadruplet*> &sel_quads , Quadruplet::QuadType quad_type);
  bool FinalQuadCuts( Quadruplet* quad, bool count=true);

  void ResetFinalQuadCuts();

  bool IsBlinded( Quadruplet* quad );

   bool TrkIsolationCut(Quadruplet* quad);
   bool CaloIsolationCut(Quadruplet* quad);

  bool GetDoFourMuon()    { return m_doFourMuon;};
  bool GetDoFourElectron(){ return m_doFourElectron;};
  bool GetDoTwoMuonTwoElectron(){return m_doTwoMuonTwoElectron;};
  bool GetDoTwoElectronTwoMuon(){return m_doTwoElectronTwoMuon;};

  bool GetEvent_SFOS      (void){return b_SFOS      ;};
  bool GetEvent_trigger   (void){return b_trigger   ;};
  bool GetEvent_kinematics(void){return b_kinematics;};
  bool GetEvent_z1_mass   (void){return b_fq_z1_mass   ;};
  bool GetEvent_z2_mass   (void){return b_fq_z2_mass   ;};
  bool GetEvent_deltaR    (void){return b_fq_deltaR    ;};
  bool GetEvent_jpsi      (void){return b_fq_jpsi      ;};
  bool GetEvent_track_iso (void){return b_fq_track_iso ;};
  bool GetEvent_calo_iso  (void){return b_fq_calo_iso  ;};
  bool GetEvent_d0_sig    (void){return b_fq_d0_sig    ;};
  bool GetEvent_outside_blind(void){return b_fq_outside_blind;};

private:
   //
   // Put all your private variables here
   //
   vector<double> v_m34cut_m34;
   vector<double> v_m34cut_m34_relaxed;
   vector<double> v_m34cut_m4l;

   bool D0SignificanceCut(Quadruplet* quad);

   double interpolate(const std::vector<double>& x,  const std::vector<double>& y, double mass);
   double DeltaR(double eta1, double phi1, double eta2, double phi2); 

   bool m_doFourMuon;
   bool m_doFourElectron;
   bool m_doTwoMuonTwoElectron;
   bool m_doTwoElectronTwoMuon;

   bool m_doTrkIsoCut;
   bool m_doCaloIsoCut;
   bool m_doD0SigCut;
   bool m_doBlindSignalRegion;

   bool m_doSecondPairSS;
   bool m_doSecondPairIso;
   bool m_doSecondPairDzero;
   bool m_doFirstPairPassLikelihood;
   std::string m_FirstPairLikelihood_OP;
   bool m_doSecondPairPassLikelihood;
   bool m_doOneOfSecondPairPassLikelihood;
   std::string m_SecondPairLikelihood_OP;
   bool m_doSecondPairPassML;
   bool m_doOneOfSecondPairPassML;
   std::string m_SecondPairML_OP;
   bool m_doOneOfSecondPairPassLikelihoodLoose;
   bool m_doOneOfSecondPairPassLikelihoodLoose_BL_Pix;
   bool m_doOneOfSecondPairPassLikelihoodLoose_BL_PixLow;
   bool m_doOneOfSecondPairPassLikelihoodLoose_BL_PixMed;
   bool m_doOneOfSecondPairPassLikelihoodLoose_BL_PixHigh;

   bool m_doFirstPairPassID;
   bool m_doFirstPairPassML; 
   bool m_doFirstPairPassML_HCP;
   bool m_doFirstPairPassLikelihoodMedium;
   bool m_doFirstPairPassLikelihoodLoose;
   bool m_doFirstPairPassLikelihoodLoose_BL_Pix; 
   bool m_doFirstPairPassLikelihoodLoose_BL_PixLow;
   bool m_doFirstPairPassLikelihoodLoose_BL_PixMed;
   bool m_doFirstPairPassLikelihoodLoose_BL_PixHigh;

   bool m_doBestBefore;
   double m_pt3Cut;
   double m_M34Cut;
   double m_M12Cut;

   int m_muonTrkIsoConeSize;
   int m_electronTrkIsoConeSize;
   double m_muonTrkIsoCut;
   double m_electronTrkIsoCut;
 
   int m_muonCaloIsoConeSize;
   int m_electronCaloIsoConeSize;
   int m_electronCaloIsoSubConeSize;
   double m_muonCaloIsoCut;
   double m_standaloneMuonCaloIsoCut;
   double m_electronCaloIsoCut;

   int cf_preselect;
   int cf_SFOS;
   int cf_kinematics;
   int cf_trigger;
   int cf_z1_mass;
   int cf_z2_mass;
   int cf_deltaR;
   int cf_jpsi;
   int cf_track_iso;
   int cf_calo_iso;
   int cf_d0_sig;
   int cf_outside_blind;

  bool b_SFOS;
  bool b_trigger;
  bool b_kinematics;
  bool b_fq_z1_mass;
  bool b_fq_z2_mass;
  bool b_fq_deltaR;
  bool b_fq_jpsi;
  bool b_fq_track_iso;
  bool b_fq_calo_iso;
  bool b_fq_d0_sig;
  bool b_fq_outside_blind;
      
   // Macro adding the functions for dictionary generation
   ClassDef( QuadSelector, 0 );

}; // class QuadSelector

#endif // QuadSelector_H
