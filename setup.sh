echo "Setting up compilation environment"
source $AFS_HOME/scripts/setupRoot.sh

# setup SFrame
cd SFrame
source RootCore/RootCore/scripts/setup.sh
cd SFrame
source setup.sh
cd ../..

# setup PyRoot
export LD_LIBRARY_PATH=$ROOTSYS/lib:$PYTHONDIR/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH
export PYTHONPATH=$HOME/testarea/Higgs4lDev/python/modules:$PYTHONPATH
