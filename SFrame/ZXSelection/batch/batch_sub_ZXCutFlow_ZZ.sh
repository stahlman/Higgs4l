# options
INPUT_VERSION_DATA=blah
INPUT_VERSION_MC=.6.
OUTPUT_DIR=11162012
FILES_PER_JOB=5
SUBMIT="--submit"
#SUBMIT=""

# directories
SRM_BASE=/xrootd/atlasC/local/sheim/
OUTPUT_BASE=/disk/userdata00/atlas_data2/stahlman/output/
SCRIPT_BASE=/home/stahlman/testarea/Higgs4lDev.trunk/SFrame/ZZSelection/batch/

CONFIG=batch_mc_ZXCutflow_config


#generate batch run script
python createBatchRunFile.py $SCRIPT_BASE $CONFIG
SCRIPT=batch_run.$CONFIG.sh


#run command for ZZ
NUMBER=167165
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=167163
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=167162
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

#NUMBER=161988
#python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=126942
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=126941
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=126940
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=126939
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=126938
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=126937
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=116603
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=116602
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=116601
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/MC_ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files
