#!/bin/bash

### To be called on batch worker node

# first argument is "--files", thrown away
echo "argument was:"
echo $2

# shouldn't be necessary to set up environment on batch
#source RootCore/RootCore/scripts/setup.sh
#cd SFrame
#source setup.sh
#cd ..

ARGS=""
if [[ $2 == *:/* ]]; then
  ARGS="-r"
fi
sframe_input.py - $ARGS -d -o input_batch.xml -t physics $2

# check that input xml exists
if [ -e input_batch.xml ]
then
  cat input_batch.xml
else
  echo "ERROR: problem with input files"
  exit 1
fi

pwd

# copy config files from SFrame dir
cp $HOME/SFrame/Higgs4lDev/SFrame/ZZSelection/config/*.dtd $HOME/SFrame/Higgs4lDev/SFrame/ZZSelection/batch/batch_data_ZZCutFlow_config.xml .
ls -arlt

echo ""
echo "--> Before running SFrame"
echo ""

# run SFrame
sframe_main batch_data_ZZCutFlow_config.xml
#sframe_main 

echo ""
echo "--> SFrame finished"
echo ""
