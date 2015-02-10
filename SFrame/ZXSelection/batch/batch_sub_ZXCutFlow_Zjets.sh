# options
INPUT_VERSION_DATA=blah
INPUT_VERSION_MC=
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

#run command for Zjets

###Zee
NUMBER=107650
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

# --nJobs 1
#exit

NUMBER=107651
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files 

NUMBER=107652
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files 

NUMBER=107653
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files 

NUMBER=107654
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files 

NUMBER=107655
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files 

###Zmumu

NUMBER=107660
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files 

NUMBER=107661
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files 

NUMBER=107662
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files 

NUMBER=107663
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=107664
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=107665
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files 

#Ztautau

NUMBER=107670
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=107671
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=107672
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files 

NUMBER=107673
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=107674
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=107675
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

###Zee 10-60
NUMBER=146830
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146831
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146832
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146833
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146834
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

###Zmumu 10-60

NUMBER=146840
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146841
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146842
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146843
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146844
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

###Ztautau 10-60

NUMBER=146850
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146851
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146852
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146853
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files

NUMBER=146854
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER  --output $OUTPUT_BASE/$OUTPUT_DIR/Zjets_$TYPE\_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT $SUBMIT --overwrite --transfer-input-files





