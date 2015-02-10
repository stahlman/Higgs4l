# options
INPUT_VERSION_DATA=blah
INPUT_VERSION_MC=
OUTPUT_DIR=23072013
FILES_PER_JOB=100
SUBMIT="--submit"
#SUBMIT=""

# directories
SRM_MC_BASE=/xrootd/atlasC/local/sheim/mc_v11/
OUTPUT_BASE=/disk/userdata00/atlas_data2/stahlman/output/
SCRIPT_BASE=/home/stahlman/testarea/Higgs4lDev.trunk/SFrame/ZZSelection/batch/

#base config
CONFIG=batch_mc_ZZCutFlow_config


for SYSTEMATIC in MuonResolutionMSUp MuonResolutionMSDn MuonResolutionIDUp MuonResolutionIDDn MuonScaleUp MuonScaleDn ElectronScaleZeeUp ElectronScaleZeeDn ElectronScaleR12Up ElectronScaleR12Dn ElectronScalePSUp ElectronScalePSDn ElectronScaleLowPtUp ElectronScaleLowPtDn ElectronResolutionUp ElectronResolutionDn 
do

   #generate config file
   LINE="<Item Name=\"EnergyRescalerTool_doSystematic\" Value=\"$SYSTEMATIC\"/>"
   sed -e"/.*<UserConfig>.*/a\      $LINE" $CONFIG.xml > $CONFIG\_$SYSTEMATIC.xml

   #generate batch run script
   python createBatchRunFile.py $SCRIPT_BASE $CONFIG\_$SYSTEMATIC
   SCRIPT=batch_run.$CONFIG\_$SYSTEMATIC.sh

   ###ggH125
   NUMBER=160155
   python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH125_$SYSTEMATIC\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

   ###WH125
   NUMBER=160255
   python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH125_$SYSTEMATIC\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

   ###ZH125
   NUMBER=160305
   python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH125_$SYSTEMATIC\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

   ###VBFH125
   NUMBER=160205
   python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH125_$SYSTEMATIC\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

   ###ttH125
   NUMBER=167562
   python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH125_$SYSTEMATIC\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

done

