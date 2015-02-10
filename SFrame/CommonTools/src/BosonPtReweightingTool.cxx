#include "../include/BosonPtReweightingTool.h"

#include <TString.h>

#include <iostream>
#include <string>

//===============================================================================================================
BosonPtReweightingTool::BosonPtReweightingTool(std::string source, bool usefit)
{
  std::string weightsFileName = source;
  //std::string weightsFileName = "WeightsBosonPt_"+source+"_to_Pythia.root";
  m_weightsFile = TFile::Open(weightsFileName.c_str());
  
  if ( !m_weightsFile ) {
    std::cout << "ERROR: could not open file with weights: "<<weightsFileName << std::endl;
  } else {
    std::cout << "Successfully opened file with weights: "<<weightsFileName << std::endl;
  }

  m_h_weights_Wplus  = (TH1F*) m_weightsFile->Get("weights_Wplus");
  m_h_weights_Wminus = (TH1F*) m_weightsFile->Get("weights_Wminus");
  m_h_weights_Zee    = (TH1F*) m_weightsFile->Get("weights_Zee");

  m_f_weights_Zee = 0;
  m_param_weights_Zee.clear();

  if (usefit) {
    m_f_weights_Zee = (TF1*) m_weightsFile->Get(("weightfit/"+source+"_to_Pythia_ptz").c_str());
    int i = 0;
    while (m_weightsFile->Get(TString::Format("weightfit/%s_to_Pythia_p%i", source.c_str(), i)) != 0) {
      m_param_weights_Zee.push_back((TF1*) m_weightsFile->Get(TString::Format("weightfit/%s_to_Pythia_p%i", source.c_str(), i)));
      i++;
    }
    if (m_f_weights_Zee == 0 || m_param_weights_Zee.size() == 0)
      std::cout << "ERROR: could not get the functions for Z Pt weights" << std::endl;
  } else {
    if ( !m_h_weights_Wplus )
      std::cout << "ERROR: could not get weights for W+" << std::endl;
    if ( !m_h_weights_Wminus )
      std::cout << "ERROR: could not get weights for W-" << std::endl;
    if ( !m_h_weights_Zee )
      std::cout << "ERROR: could not get weights for Z" << std::endl;
  }
}


//===============================================================================================================
BosonPtReweightingTool::~BosonPtReweightingTool()
{
  
}


//===============================================================================================================  
float BosonPtReweightingTool::GetWeightWplus ( float ptWGen )
{
  int bin = m_h_weights_Wplus->FindBin( ptWGen/1000 ); // weight histo is in GeV
  float weight = m_h_weights_Wplus->GetBinContent(bin);
  return weight;
}


//===============================================================================================================
float BosonPtReweightingTool::GetWeightWminus( float ptWGen )
{
  int bin = m_h_weights_Wminus->FindBin( ptWGen/1000 ); // weight histo is in GeV
  float weight = m_h_weights_Wminus->GetBinContent(bin);
  return weight;
}


//===============================================================================================================
float BosonPtReweightingTool::GetWeightZee( float ptZGen, float mZGen )
{
  float weight = 1.;
  if (m_f_weights_Zee == 0) {
    int bin = m_h_weights_Zee->FindBin( ptZGen/1000. ); // weight histo is in GeV
    weight = m_h_weights_Zee->GetBinContent(bin);
  } else {
    // setup parameters for function
    for (unsigned int i = 0; i < m_param_weights_Zee.size(); i++)
      m_f_weights_Zee->SetParameter(i, m_param_weights_Zee[i]->Eval(mZGen/1000.));
    // get weight
    weight = m_f_weights_Zee->Eval(ptZGen/1000.);
  }
  return weight;
}
