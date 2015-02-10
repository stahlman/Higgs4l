#!/bin/bash

echo "argument was:"
echo $1

# setup SFrame
source RootCore/RootCore/scripts/setup.sh

echo "printing ROOTCOREDIR"
echo $ROOTCOREDIR

echo "resetting ROOTCOREDIR"
export ROOTCOREDIR=$PWD/RootCore/RootCore
echo $ROOTCOREDIR

cd SFrame
source setup.sh
cd ..

ARGS=""
if [[ $1 == *:/* ]]; then
  ARGS="-r"
fi

# create and print input XML file
sframe_input.py - $ARGS -d -o ZZMassResolution/config/input_grid.xml -t physics $1
if [ -e ZZMassResolution/config/input_grid.xml ]
then
  cat ZZMassResolution/config/input_grid.xml
else
  echo "ERROR: problem with input files"
  exit 1
fi

# run SFrame
cd ZZMassResolution/config
sframe_main ZMassStudy_grid_data_config.xml

echo ""
echo "--> SFrame finished, moving output file"
echo ""
#move output fileback to base directory
mv *.root ../..
cd ../..
