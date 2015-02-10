#ifndef BOSONPTREWEIGHTINGTOOL_H
#define BOSONPTREWEIGHTINGTOOL_H

/*
  Tool to obtain truth level W,Z boson weights to reweight the boson pt distribution
  Input is taken from external ROOT file:
  * WeightsBosonPt_McAtNlo_to_Pythia.root
  * WeightsBosonPt_PowhegPythia_to_Pythia.root
  * WeightsBosonPt_PowhegHerwig_to_Pythia.root
  * WeightsBosonPt_PythiaMC11_to_Pythia.root

  Currently all weighting is done to MC10 Pythia, which describes ATLAS (2010) data nearly perfectly

  New option to use empirically fitted weights and boson mass dependence e.g. for Z':
     initialise with:
     BosonPtReweightingTool *bosonpt = new BosonPtReweightingTool("PythiaMC11", true);
     use with:
     float weight = bosonpt->GetWeightZee(true_boson_pt[MeV], true_boson_mass[MeV]);

  Written by Jochen Hartert, extensions by Jan Kretzschmar
*/

#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"

#include <string>
#include <vector>

class BosonPtReweightingTool
{

 public:
  BosonPtReweightingTool(std::string source, bool usefit = true);
  ~BosonPtReweightingTool();
  
  float GetWeightWplus ( float ptWGen ); // use truth boson pt in MeV
  float GetWeightWminus( float ptWGen ); // use truth boson pt in MeV
  float GetWeightZee   ( float ptZGen, float mZGen = 91000 ); // use truth boson pt and mass in MeV

 private:

  TFile* m_weightsFile;
  
  TH1F* m_h_weights_Wplus;
  TH1F* m_h_weights_Wminus;
  TH1F* m_h_weights_Zee;

  TF1* m_f_weights_Zee;
  std::vector<TF1*> m_param_weights_Zee;

};

#endif // BOSONPTREWEIGHTINGTOOL_H
