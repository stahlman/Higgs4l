#!/bin/bash

cd CLHEP_1_9_4_7
./bootstrap
#echo $PWD/../RootCoreCLHEP/CLHEP
./configure --prefix=$PWD/../RootCoreCLHEP/CLHEP 
make
make check
make install

cd ..
