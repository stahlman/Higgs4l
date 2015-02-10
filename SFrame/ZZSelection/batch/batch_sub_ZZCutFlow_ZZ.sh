# options
INPUT_VERSION_DATA=blah
INPUT_VERSION_MC=.10.
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

#CONFIG=batch_mc_ZZCutFlow_config
#TYPE=NoIso

#generate batch run script
python createBatchRunFile.py $SCRIPT_BASE $CONFIG
SCRIPT=batch_run.$CONFIG.sh



#run command for ZZ
NUMBER=167165
python $SCRIPT_BASE/submit_jobs_penn.py  --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files


NUMBER=167163
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=167162
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

#NUMBER=161988
#python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=126942
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=126941
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=126940
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=126939
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=126938
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=126937
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=116603
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=116602
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=116601
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files






