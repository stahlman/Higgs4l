#!/bin/bash

echo "argument was:"
echo $1

# setup SFrame
source RootCore/RootCore/scripts/setup.sh
cd SFrame
source setup.sh
cd ..

ARGS=""
if [[ $1 == *:/* ]]; then
  ARGS="-r"
fi

# create and print input XML file
sframe_input.py - $ARGS -d -o ZZSelection/config/input_grid.xml -t physics $1
if [ -e ZZSelection/config/input_grid.xml ]
then
  cat ZZSelection/config/input_grid.xml
else
  echo "ERROR: problem with input files"
  exit 1
fi

# run SFrame
cd ZZSelection/config
sframe_main ZZ_Selection_grid_mc_config.xml

echo ""
echo "--> SFrame finished, moving output file"
echo ""
#move output fileback to base directory
mv *.root ../..
cd ../..
