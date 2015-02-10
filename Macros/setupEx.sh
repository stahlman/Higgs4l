
#check out external packages
svn co svn+ssh://svn.cern.ch/reps/atlasoff/PhysicsAnalysis/HiggsPhys/HSG2/HiggsZZ4lUtils/tags/HiggsZZ4lUtils-00-02-19 externals/HiggsZZ4lUtils 
svn co svn+ssh://svn.cern.ch/reps/atlasoff/DataQuality/GoodRunsLists/tags/GoodRunsLists-00-01-09 externals/GoodRunsLists

cd externals/HiggsZZ4lUtils/cmt
make -f Makefile.Standalone
cd -

cd externals/GoodRunsLists/cmt
make -f Makefile.Standalone
cd -


MiCROPATH=$PWD
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$MACROPATH/externals/HiggsZZ4lUtils/StandAlone/:$MACROPATH/externals/GoodRunsLists/StandAlone/
