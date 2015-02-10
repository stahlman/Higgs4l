/////////////////////////////////////////////////////////////////////////
//
// 'Number Counting Example' RooStats tutorial macro #100
// author: Kyle Cranmer
// date Nov. 2008 
//
// This tutorial shows an example of a combination of 
// two searches using number counting with background uncertainty.
//
// The macro uses a RooStats "factory" to construct a PDF
// that represents the two number counting analyses with background 
// uncertainties.  The uncertainties are taken into account by 
// considering a sideband measurement of a size that corresponds to the
// background uncertainty.  The problem has been studied in these references:
//   http://arxiv.org/abs/physics/0511028
//   http://arxiv.org/abs/physics/0702156
//   http://cdsweb.cern.ch/record/1099969?ln=en
//
// After using the factory to make the model, we use a RooStats 
// ProfileLikelihoodCalculator for a Hypothesis test and a confidence interval.
// The calculator takes into account systematics by eliminating nuisance parameters
// with the profile likelihood.  This is equivalent to the method of MINOS.
//
/////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooStats/ProfileLikelihoodCalculator.h"
#include "RooStats/NumberCountingPdfFactory.h"
#include "RooStats/ConfInterval.h"
#include "RooStats/HypoTestResult.h"
#include "RooStats/LikelihoodIntervalPlot.h"
#include "RooRealVar.h"

#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "TFile.h"
#include "TRandom3.h"

// use this order for safety on library loading
using namespace ROOT ;
using namespace RooFit ;
using namespace RooStats ;


// declare three variations on the same tutorial
void throw_toys(const char * tag, Double_t *s, Double_t *b, Double_t *db, Double_t *toy_data, int n_chan, int n_toys=10);

////////////////////////////////////////////
// main driver to choose one
void throwToys(int flag=1)
{  
  TFile* fin = new TFile("/disk/userdata00/atlas_data2/stahlman/output/Fall2013/Plots/DifferentialMeasurement.pt.test.root", "READ");
  cout<<flag<<endl;  
  int n_toys = 1000;
  int n_chan = 4;

  std::vector<string> channels;
  channels.push_back("4mu");    
  channels.push_back("4e");
  channels.push_back("2mu2e");
  channels.push_back("2e2mu");

  TH1*  h_signal_yield = (TH1*)fin->Get("h_signal_yield");
  TH1*  h_background_yield = (TH1*)fin->Get("h_background_yield");
  TH1*  h_background_yield_syst = (TH1*)fin->Get("h_background_yield_syst");    
  
  std::vector<TH1*> h_signal_yield_;
  std::vector<TH1*> h_background_yield_;
  std::vector<TH1*> h_background_yield_syst_;

  for (int i = 0; i < 4; ++i){
    h_signal_yield_.push_back((TH1*)fin->Get(Form("h_signal_yield_%s", channels[i].c_str())));
    h_background_yield_.push_back((TH1*)fin->Get(Form("h_background_yield_%s", channels[i].c_str())));
    h_background_yield_syst_.push_back((TH1*)fin->Get(Form("h_background_yield_syst_%s", channels[i].c_str())));    
  }

  TFile* fout = new TFile("/disk/userdata00/atlas_data2/stahlman/output/test/DifferentialMeasurement.pt.Toys.test.root", "RECREATE");
  
  Double_t toy_data[4] = {0,0,0,0};
  Double_t s[4]  = {0,0,0,0};
  Double_t b[4]  = {0,0,0,0};
  Double_t db[4] = {0,0,0,0};
  
  Double_t toy_incl[1] = {0};
  Double_t s_incl[1] = {0};
  Double_t b_incl[1] = {0};
  Double_t db_incl[1] = {0};

  for (int bin = 0; bin < 4; ++bin){  
    //load s/b estimates from histograms
    s_incl[0] =  h_signal_yield->GetBinContent(bin+1);// expected signal
    b_incl[0] =  h_background_yield->GetBinContent(bin+1);// expected background
    db_incl[0] = h_background_yield_syst->GetBinContent(bin+1) / 100.0;// fractional background uncertainty		 

    throw_toys(Form("pt_inclusive_bin%i",bin),s_incl,b_incl,db_incl,toy_incl,1, n_toys);

    for (int chan = 0; chan < n_chan; ++chan){
       s[chan] =  h_signal_yield_[chan]->GetBinContent(bin+1);// expected signal
       b[chan] =  h_background_yield_[chan]->GetBinContent(bin+1);// expected background
       db[chan] = h_background_yield_syst_[chan]->GetBinContent(bin+1) / 100.0;// fractional background uncertainty                
    }
       
    throw_toys(Form("pt_separate_bin%i",bin),s,b,db,toy_data,n_chan, n_toys);
    
    
  }

  cout<< "Closing output file: " << endl;
  cout<< fout->GetPath() <<endl;    
  fout->Close();  
}

/////////////////////////////////////////////
void throw_toys(const char * tag, Double_t *s, Double_t *b, Double_t *db, Double_t *toy_data, int n_chan, int n_toys )
{
 
  TTree* toy_tree = new TTree(Form("toys_%s", tag), "toys");

  int toy_signal       = 0;
  int toy_background   = 0;
  double central_value = 0;
  double lower_limit   = 0;
  double upper_limit   = 0;
  double p0_value      = 0;
  double significance  = 0;

  toy_tree->Branch("toy_signal", &toy_signal, "toy_signal/I");
  toy_tree->Branch("toy_background", &toy_background, "toy_background/I");

  toy_tree->Branch("central_value", &central_value, "central_value/D");
  toy_tree->Branch("lower_limit", &lower_limit, "lower_limit/D");
  toy_tree->Branch("upper_limit", &upper_limit, "upper_limit/D");
  toy_tree->Branch("p0_value", &p0_value, "p0_value/D");
  toy_tree->Branch("significance", &significance, "significance/D");

  /////////////////////////////////////////
  // The Model building stage
  /////////////////////////////////////////

  // Step 1, define arrays with signal & bkg expectations and background uncertainties
  
  cout << "Signal\tBackground\tBackground Unc."<<endl;
  for( int i = 0; i<n_chan;i++){
    cout<< s[i] << "\t"<< b[i] << "\t" << db[i] << endl; 
  }
  //return;

  // Step 2, use a RooStats factory to build a PDF for a 
  // number counting combination and add it to the workspace.
  // We need to give the signal expectation to relate the masterSignal
  // to the signal contribution in the individual channels.
  // The model neglects correlations in background uncertainty, 
  // but they could be added without much change to the example.
  NumberCountingPdfFactory f;
  RooWorkspace* wspace = new RooWorkspace();
  f.AddModel(s,n_chan,wspace,"TopLevelPdf", "masterSignal"); 

  // Step 3, use a RooStats factory to add datasets to the workspace.
  // Step 3a.
  // Add the expected data to the workspace
  f.AddExpData(s, b, db, n_chan, wspace, "ExpectedNumberCountingData");

  // see below for a printout of the workspace
  //  wspace->Print();  //uncomment to see structure of workspace

  /////////////////////////////////////////
  // The Hypothesis testing stage:
  /////////////////////////////////////////
  // Step 4, Define the null hypothesis for the calculator
  // Here you need to know the name of the variables corresponding to hypothesis.
  RooRealVar* mu = wspace->var("masterSignal"); 
  mu->setRange(-10,10);
  RooArgSet* poi = new RooArgSet(*mu); 
  RooArgSet* nullParams = new RooArgSet("nullParams");
  nullParams->addClone(*mu);

  TRandom3* rand = new TRandom3(0);

  for (int i = 0; i < n_toys; ++i){ 

     cout<< "*****************************" << endl;
     cout<< "Toy #" << i << " for " <<tag<< endl;
     cout<< "*****************************" << endl;

    // here we explicitly set the value of the parameters for the null
    nullParams->setRealValue("masterSignal",0); 
    
    //generate toy data
    cout<<"# EVENTS OBSERVED"<<endl;
    int total_observed = 0;
    toy_signal     = 0;
    toy_background = 0;
    for (int j = 0; j < n_chan; ++j){
       int toy_s = rand->Poisson(s[j]);
       int toy_b = rand->Poisson(b[j]);
        
       toy_data[j] = toy_s + toy_b;
       cout << toy_data[j] << "\t";

       toy_signal     += toy_s;
       toy_background += toy_b;
       total_observed += toy_data[j];
    }
    cout<< endl << "*****************************" << endl;
    
    if (total_observed ==0) continue;


    f.AddData( toy_data, b, db, n_chan, wspace, Form("Toy_%i",i));
    
    // Step 5, Create a calculator for doing the hypothesis test.
    // because this is a 
    ProfileLikelihoodCalculator plc( *wspace->data(Form("Toy_%i",i)),
				     *wspace->pdf("TopLevelPdf"), *poi, 0.05, nullParams);
				  

     // Step 6, Use the Calculator to get a HypoTestResult
     HypoTestResult* htr = plc.GetHypoTest();     
     assert(htr != 0);
     //cout << "-------------------------------------------------" << endl;
     //cout << "The p-value for the null is " << htr->NullPValue() << endl;
     //cout << "Corresponding to a signifcance of " << htr->Significance() << endl;
     //cout << "-------------------------------------------------\n\n" << endl;
     p0_value      = htr->NullPValue();
     significance  = htr->Significance();

     //////////////////////////////////////////
     // Confidence Interval Stage

     // Step 8, Here we re-use the ProfileLikelihoodCalculator to return a confidence interval.
     // We need to specify what are our parameters of interest
     RooArgSet* paramsOfInterest = nullParams; // they are the same as before in this case
     plc.SetParameters(*paramsOfInterest);
     LikelihoodInterval* lrint = (LikelihoodInterval*) plc.GetInterval();  // that was easy.
     lrint->SetConfidenceLevel(0.68);

     // Step 9, make a plot of the likelihood ratio and the interval obtained
     // find limits
     central_value = lrint->GetBestFitParameters()->getRealValue("masterSignal");
     lower_limit = lrint->LowerLimit(*mu);
     upper_limit = lrint->UpperLimit(*mu);

     //LikelihoodIntervalPlot lrPlot(lrint);
     //lrPlot.SetMaximum(3.);
     //lrPlot.Draw();

     // Step 10a. Get upper and lower limits
     //cout << "best fit point is = " <<  bestfit << endl;
     //cout << "lower limit on master signal = " <<  lower << endl;
     //cout << "upper limit on master signal = " <<  upper << endl;
     toy_tree->Fill();
  
     delete htr;
     delete lrint;
  }
 
  //write output
  toy_tree->Write();
    
  delete wspace;
  delete poi; 
  delete nullParams;
  //delete toy_tree;
  //delete fout;
  
}



