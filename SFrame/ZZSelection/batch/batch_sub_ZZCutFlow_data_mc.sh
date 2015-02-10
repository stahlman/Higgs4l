# options
INPUT_VERSION_DATA=blah
INPUT_VERSION_MC=.6.
OUTPUT_DIR=10252012
FILES_PER_JOB=5
SUBMIT="--submit"
#SUBMIT=""

# directories
SRM_MC_BASE=/xrootd/atlasC/local/sheim/mc_v6/
OUTPUT_BASE=/disk/userdata00/atlas_data2/sheim/output/
SCRIPT_BASE=/home/sheim/SFrame/Higgs4lDev/SFrame/ZZSelection/batch/



#run command for ZZ
NUMBER=167165
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=167163
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=167162
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

#NUMBER=161988
#python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=126942
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=126941
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=126940
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=126939
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=126938
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=126937
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=116603
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=116602
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files

NUMBER=116601
python $SCRIPT_BASE/submit_jobs_penn.optparse.py --dataset $SRM_MC_BASE/ --subsets user.sheim.mc12_8TeV.$NUMBER --key $INPUT_VERSION_MC  --output $OUTPUT_BASE/$OUTPUT_DIR/ZZ_$NUMBER --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.mc.ZZCutFlow.sh --use-subdirs $SUBMIT --overwrite --transfer-input-files






# run command for data
#python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_BASE/data12_8TeV --subsets data12_8TeV.periodD --key $INPUT_VERSION_DATA  --output $OUTPUT_BASE/$OUTPUT_DIR/Data --nFilesPerJob $FILES_PER_JOB --script $SCRIPT_BASE/batch_run.data.ZZCutFlow.sh_blah --use-subdirs $SUBMIT --overwrite
