# options
INPUT_VERSION_DATA=blah
INPUT_VERSION_MC=
OUTPUT_DIR=19032013
FILES_PER_JOB=5
N_JOBS=1
SUBMIT="--submit"
#SUBMIT=""

# directories
SRM_MC_BASE=/atlasC/local/sheim/mc_v11/
OUTPUT_BASE=/disk/userdata00/atlas_data2/stahlman/output/
SCRIPT_BASE=/home/stahlman/testarea/Higgs4lDev.trunk/SFrame/ZZTruthStudies/batch/

CONFIG=batch_mc_FiducialCutflow_config
TYPE=Fiducial

#generate batch run script
python createBatchRunFile.py $SCRIPT_BASE $CONFIG
SCRIPT=batch_run.$CONFIG.sh

###H125 Samples
NUMBER=160155
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH125_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160205
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH125_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160305
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH125_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160255
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH125_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files


SRM_MC_BASE=/atlasC/local/stahlman/signal_v1/

###ggH
NUMBER=160152
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH110_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160153
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH115_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160154
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH120_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160156
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH130_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160157
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH135_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160158
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH140_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160159
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH145_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160160
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH150_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160161
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH155_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160162
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH160_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167220
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH123_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167222
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH124_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167225
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH126_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167227
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH127_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files


###ggH125 Systematics
NUMBER=160353
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH125_SRenFacUp$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160354
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH125_SRenFacDown_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160351
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ggH125_AU2NNPDF21NLO_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files



###VBF
NUMBER=160202
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH110_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160203
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH115_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160204
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH120_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160206
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH130_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160207
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH135_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160208
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH140_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160209
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH145_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160210
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH150_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160211
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH155_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160212
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH160_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167230
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH123_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167232
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH124_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167235
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH126_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167237
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/VBFH127_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files


###WH
NUMBER=160252
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH110_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160253
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH115_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160254
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH120_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160256
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH130_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160257
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH135_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160258
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH140_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160259
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH145_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160260
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH150_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160261
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH155_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160262
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH160_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167240
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH123_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167242
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH124_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167245
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH126_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167247
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/WH127_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

###ZH
NUMBER=160302
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH110_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160303
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH115_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160304
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH120_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160306
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH130_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160307
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH135_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160308
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH140_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160309
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH145_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160310
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH150_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160311
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH155_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=160312
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH160_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167250
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH123_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167252
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH124_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167255
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH126_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167257
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ZH127_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

###ttH
NUMBER=167560
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH110_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167561
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH120_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167562
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH125_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167563
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH130_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167564
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH140_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167565
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH150_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167566
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH123_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167567
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH124_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167568
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH126_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

NUMBER=167569
python $SCRIPT_BASE/submit_jobs_penn.py --dataset $SRM_MC_BASE --key $NUMBER --output $OUTPUT_BASE/$OUTPUT_DIR/ttH127_$TYPE\_$NUMBER --nJobs $N_JOBS --script $SCRIPT_BASE/$SCRIPT  $SUBMIT --overwrite --transfer-input-files

