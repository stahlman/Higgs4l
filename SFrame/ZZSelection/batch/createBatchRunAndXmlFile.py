import os,sys

if not len(sys.argv) >= 3:  raise(Exception, "Must specify input directory and file name as argument!")

input_dir = sys.argv[1]
input_config = sys.argv[2]
sframe_dir = os.getenv('SFRAME_DIR')

xml_fileFullPath = input_dir + input_config +'_autogen.xml'
xml_fileLocal    = xml_fileFullPath.split('/')[-1]
sh_fileFullPath  = input_dir + input_config +'_autogen.sh'

xmlTemplate = \
"""<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" ?>
<!DOCTYPE JobConfiguration PUBLIC \"\" \"JobConfig.dtd\"[
    <!ENTITY libs_config SYSTEM \"%s/../ZZSelection/config/common_libs.xml\"> 
    <!ENTITY data SYSTEM \"input_batch.xml\"> 
]>

<!--OutputLevel: Possibilities: VERBOSE, DEBUG, INFO, WARNING, ERROR, FATAL, ALWAYS -->
<JobConfiguration JobName=\"ZZCutFlowJob\" OutputLevel=\"INFO\">

  &libs_config;

  <Cycle Name=\"ZZCutFlow\" TargetLumi=\"1.\" RunMode=\"LOCAL\" ProofServer=\"lite\"
         ProofWorkDir=\"\" OutputDirectory=\"./\" ProofNodes=\"2\" PostFix=\"\" >

    <InputData Type=\"data\" Version=\"batch\" Lumi=\"0.\" NEventsMax=\"-1\" NEventsSkip=\"0\" Cacheable=\"False\" >
      &data;
      <!-- &trees_ff_config; -->
    <InputTree Name=\"physics\" />
    <OutputTree Name=\"output\" />
    </InputData>

    <UserConfig>
      <!-- &options_ZZCutFlow_batch_config; -->
      <Item Name=\"SFrame_dir\" Value=\"%s/../\"/>
      <Item Name=\"TrigTreeString\" Value=\"\"/>

      <Item Name=\"DoGRL\" Value=\"False\"/>

      <!-- Tool Configuration -->
      <Item Name=\"QuadSelector_DoFourMuon\" Value=\"True\" />
      <Item Name=\"QuadSelector_DoFourElectron\" Value=\"True\" />
      <Item Name=\"QuadSelector_DoTwoMuonTwoElectron\" Value=\"True\" />
      <Item Name=\"QuadSelector_DoTwoElectronTwoMuon\" Value=\"True\" />

      <Item Name=\"MuonSelector_DoSmear\" Value=\"True\"/>
      <Item Name=\"ElectronSelector_DoSmear\" Value=\"True\"/>
      <Item Name=\"ElectronSelector_DoCalibration\" Value=\"True\"/>

    </UserConfig>

  </Cycle>

</JobConfiguration>
"""

shTemplate = \
"""#!/bin/bash
# first argument is \"--files\", thrown away
echo \"argument was:\"
echo $2
ARGS=\"\"
if [[ $2 == *:/* ]]; then
  ARGS=\"-r\"
fi
sframe_input.py - $ARGS -d -o input_batch.xml -t physics $2
# check that input xml exists
if [ -e input_batch.xml ]
then
  cat input_batch.xml
else
  echo \"ERROR: problem with input files\"
  exit 1
fi
pwd
cp %s/../ZZSelection/batch/../config/*.dtd %s .
ls -arlt
echo \"\"
echo \"--> Before running SFrame\"
echo \"\"
# run SFrame
sframe_main %s
echo \"\"
echo \"--> SFrame finished\"
echo \"\"
"""

with open(xml_fileFullPath,'w') as xml :
    xml.write(xmlTemplate % (sframe_dir,sframe_dir))

with open(sh_fileFullPath,'w') as sh :
    sh.write(shTemplate % (sframe_dir,xml_fileFullPath,xml_fileLocal))
