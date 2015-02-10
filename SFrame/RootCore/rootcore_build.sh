#!/bin/bash

cd RootCore
./configure
source scripts/setup.sh
cd ..

$ROOTCOREDIR/scripts/find_packages.sh
$ROOTCOREDIR/scripts/compile.sh
$ROOTCOREDIR/scripts/make_par.sh

echo "RootCore compilation done.  Now making symlinks:"

# link .so and .par files to SFrame/lib dir
cwd=`pwd`
cp -p ${cwd}/RootCore.par ../SFrame/lib/RootCore.par
for i in `find ${cwd}/RootCore/lib/ -name "*.so"`; do cp -p ${i} ../SFrame/lib/; done
ls -alrt ../SFrame/lib
