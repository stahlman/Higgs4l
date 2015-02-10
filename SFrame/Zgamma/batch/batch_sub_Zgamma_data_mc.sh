# options
INPUT_VERSION_DATA=blah
INPUT_VERSION_MC=4.121
OUTPUT_DIR=11102012_5b
FILES_PER_JOB=5
SUBMIT="--submit"
#SUBMIT=""

# directories
SRM_BASE=/xrootd/atlasC/local/sheim/mc_v4/
OUTPUT_BASE=/disk/userdata00/atlas_data2/sheim/output/
SCRIPT_BASE=/home/sheim/SFrame/Higgs4lDev/SFrame/Zgamma/batch/

# run command for 2leptonphoton
#python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_BASE/ --subsets user.sheim.mc12_8TeV.129250 --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/TwoLeptonPhoton --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.data.Zgamma_egamma.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

# run command for zee
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_BASE/ --key 147806 --output $OUTPUT_BASE/$OUTPUT_DIR/Zee --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.Zgamma.sh $SUBMIT --overwrite --transfer-input-files

# --nJobs 1

