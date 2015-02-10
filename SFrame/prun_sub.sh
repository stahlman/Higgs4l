#!/bin/bash

prun --bexec grid_build.sh --exec "grid_run.sh %IN" --inDS  --outDS user.jdegenha.data11_7TeV. --extFile ElectronPreselCycle/config/ObjectQualityMaps_run152166.root,ElectronPreselCycle/config/ObjectQualityMaps_run155118.root --athenaTag=17.4.0 --outputs ElectronSkim.data.test.root