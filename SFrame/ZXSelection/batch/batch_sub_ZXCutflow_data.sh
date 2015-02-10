# options
#INPUT_VERSION_DATA=NTUP_HSG2.grp13_v01
INPUT_VERSION_DATA=HSG
OUTPUT_DIR=12062012
FILES_PER_JOB=5
SUBMIT="--submit"
#SUBMIT=""

# directories
SRM_BASE=/xrootd/atlasC/local/sheim/
OUTPUT_BASE=/disk/userdata00/atlas_data2/stahlman/output/
SCRIPT_BASE=/home/stahlman/testarea/Higgs4lDev.trunk/SFrame/ZZSelection/batch/

CONFIG=batch_data_ZXCutflow_config

#generate batch run script
python createBatchRunFile.py $SCRIPT_BASE $CONFIG
SCRIPT=batch_run.$CONFIG.sh

python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_BASE/egamma_v3,$SRM_BASE/muon_v3 --key $INPUT_VERSION_DATA  --output $OUTPUT_BASE/$OUTPUT_DIR/Data_$TYPE --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/$SCRIPT --overwrite --transfer-input-files $SUBMIT 

#--nJobs 1

# run command for data
#python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_BASE/egamma_v3,$SRM_BASE/muon_v3 --subsets data12_8TeV --key $INPUT_VERSION_DATA  --output $OUTPUT_BASE/$OUTPUT_DIR/Data_L --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.data.ZZCutFlow_bkg_L.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files 
#--nJobs 1




#for test:
#--nJobs 1 
