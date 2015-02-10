#!/bin/bash

svn co https://svn.code.sf.net/p/sframe/code/SFrame/tags/SFrame-03-06-22 SFrame
svn co svn+ssh://svn.cern.ch/reps/atlasgrp/Misc/sframe/MetadataTools/trunk MetadataTools

# check out RootCore and packages
svn co svn+ssh://svn.cern.ch/reps/atlasoff/PhysicsAnalysis/D3PDTools/RootCore/tags/RootCore-00-02-99 RootCore/RootCore
cd RootCore/RootCore
./configure
source scripts/setup.sh
cd ..
./RootCore/scripts/checkout.sh my_packages

cd ../..

svn co svn+ssh://svn.cern.ch/reps/atlasphys/Physics/Higgs/HSG2/Code/H4lMVDiscriminants/BDTWeights/trunk BDTWeights 
svn co svn+ssh://svn.cern.ch/reps/atlasphys/Physics/Higgs/HSG2/Code/H4lMVDiscriminants/MadGraphME/trunk MadGraphME
svn co https://svnsrv.desy.de/public/unfolding/RooUnfold/tags/V01-01-01 RooUnfold
