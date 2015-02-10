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

#CONFIG=batch_mc_ZZCutFlow_CR_config
#TYPE=CR

CONFIG=batch_mc_ZZCutFlow_TightCR_config
TYPE=TightCR

#CONFIG=batch_mc_ZZCutFlow_SS_CR_config
#TYPE=SS_CR

#generate batch run script
python createBatchRunFile.py $SCRIPT_BASE $CONFIG
SCRIPT=batch_run.$CONFIG.sh


#run command for ttbar

###ttbar
NUMBER=105200
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttbar_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146369
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttbar_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files


###Zbb
NUMBER=146995
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146996
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files


###WZ
NUMBER=161961
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files


###Zbb
NUMBER=146980
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146981
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146982
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146985
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146986
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146987
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146990
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146991
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146992
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=146997
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zbb_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

# --nJobs 1
#exit

