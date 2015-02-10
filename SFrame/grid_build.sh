#!/bin/bash
pwd
ls -altr RootCore/RootCore/lib
ls -altr SFrame/lib
echo 'ROOTSYS is: '
echo $ROOTSYS
cd SFrame
pwd
source setup.sh
cd ../RootCore/RootCore
pwd
ls -altr scripts
./configure
source scripts/setup.sh
echo 'root core directory is: '
echo $ROOTCOREDIR
cd ..
pwd
source rootcore_build.sh
cd ..
make distclean
make
ls -altr RootCore/RootCore/lib
ls -altr SFrame/lib
