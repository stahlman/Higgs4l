# options
#INPUT_VERSION_DATA=NTUP_HSG2.grp13_v01
INPUT_VERSION_DATA=HSG
OUTPUT_DIR=06022013
FILES_PER_JOB=5
SUBMIT="--submit"
#SUBMIT=""

# directories
SRM_BASE=/xrootd/atlasC/local/sheim/
OUTPUT_BASE=/disk/userdata00/atlas_data2/stahlman/output/
SCRIPT_BASE=/home/stahlman/testarea/Higgs4lDev.trunk/SFrame/ZZSelection/batch/
#CONFIG=batch_data_ZZCutFlow_CR_config
#TYPE=CR

#CONFIG=batch_data_ZZCutFlow_SS_CR_config
#TYPE=SS_CR

CONFIG=batch_data_ZZCutFlow_TightCR_config
TYPE=TightCR

#CONFIG=batch_data_ZZCutFlow_debug_config
#TYPE=DEBUG_14517045

#generate batch run script
python createBatchRunFile.py $SCRIPT_BASE $CONFIG
SCRIPT=batch_run.$CONFIG.sh


python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_BASE/egamma_v10b,$SRM_BASE/muon_v11 --key $INPUT_VERSION_DATA  --output $OUTPUT_BASE/$OUTPUT_DIR/Data_$TYPE --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT --overwrite --transfer-input-files $SUBMIT #--nJobs 1
