# options
INPUT_VERSION_DATA=blah
INPUT_VERSION_MC=
OUTPUT_DIR=21022013
FILES_PER_JOB=5
SUBMIT="--submit"
#SUBMIT=""

# directories
SRM_MC_BASE=/xrootd/atlasC/local/sheim/mc_v11/
OUTPUT_BASE=/disk/userdata00/atlas_data2/stahlman/output/
SCRIPT_BASE=/home/stahlman/testarea/Higgs4lDev.trunk/SFrame/ZZSelection/batch/

#CONFIG=batch_mc_ZZCutFlow_MLCR_config
#TYPE=OS_bkg

#CONFIG=batch_mc_ZZCutFlow_CR_config
#TYPE=CR

#CONFIG=batch_mc_ZZCutFlow_TightCR_config
#TYPE=TightCR

#CONFIG=batch_mc_ZZCutFlow_SS_CR_config
#TYPE=SS_CR

CONFIG=batch_mc_ZZCutFlow_config
TYPE=Reco

#generate batch run script
python createBatchRunFile.py $SCRIPT_BASE $CONFIG
SCRIPT=batch_run.$CONFIG.sh


###ggH125
NUMBER=160155
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/signal_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

###WH125
NUMBER=160255
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/signal_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

###ZH125
NUMBER=160305
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/signal_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

###VBFH125
NUMBER=160205
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/signal_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

###ttH125
NUMBER=167562
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/signal_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files



