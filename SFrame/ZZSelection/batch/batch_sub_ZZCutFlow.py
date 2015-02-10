#!/usr/bin/env python

import os,sys

sys.path.insert(0,'/home/stahlman/testarea/Higgs4lDev.Fall2013/SFrame/config/datasets/')
#from dataSets import mc12_hsg2_ttbar as datasets
#from dataSets import mc12_hsg2_zjets as datasets
#from dataSets import mc12_hsg2_zll as datasets
#from dataSets import mc12_hsg2_zbb as datasets
#from dataSets import mc12_hsg2_WZ as datasets
#from dataSets import mc12_hsg2_ZZ as datasets
from datasets_t3 import mc12c_hsg2_signal_sr as datasets
#from datasets_t3 import data12_hsg2_4l as datasets
#from datasets_t3 import mc12_hsg2_zz as datasets
#from datasets_t3 import mc12_hsg2_signal_h125 as datasets
#from datasets_t3 import mc12c_hsg2_signal_sr_notau as datasets
#from datasets_t3 import mc12c_hsg2_signal_prophecy as datasets
#from dataSets import test as datasets

sys.path.insert(0,'/home/stahlman/testarea/Higgs4lDev.Fall2013/Macros/')
from systematics import systematics_all_scale_resolution as systematics
#from systematics import systematics_temp as systematics


OUTPUT_DIR  = '15062014'

OUTPUT_BASE = '/disk/userdata00/atlas_data2/stahlman/output/'
#OUTPUT_BASE = '/xrootd/atlasC/local/stahlman/output/'
SCRIPT_BASE = '/home/stahlman/testarea/Higgs4lDev.Fall2013/SFrame/ZZSelection/batch/'

CONFIG = 'batch_mc12c_ZZCutFlow_config'
TYPE = 'Nominal'

#CONFIG = 'batch_data_ZZCutFlow_config'
#TYPE = 'Nominal'

DOSYSTEMATICS = False

files_per_job = 1
submit = '--submit'
#submit = ''

def main(options,args) :    
               
    if 'DQ2_HOME' not in os.environ:
      print 'ERROR: Setup DQ2 client'
      return
    
    configs = []
    types = []
    
    if DOSYSTEMATICS:
      for systematic,np_name in systematics:
        config = CONFIG+'_'+systematic
	
	#generate systematic config file if it doesn't already exist
	if not os.path.exists(config+'.xml'):	
	  line = '<Item Name=\"EnergyRescalerTool_doSystematic\" Value=\"'+systematic+'\"/>'
	  cmd = 'sed -e\'/.*<UserConfig>.*/a\      '+line+'\' '+CONFIG+'.xml > '+config+'.xml'	
	  os.system(cmd)
	  print "Created config file: " + config + '.xml'

        configs.append(config)
	types.append(systematic)
	
	os.system( 'python createBatchRunFile.py '+SCRIPT_BASE+'/ '+config )

    else:
      #create run file
      os.system( 'python createBatchRunFile.py '+SCRIPT_BASE+'/ '+CONFIG )
      configs.append(CONFIG)
      types.append(TYPE)
        
    for i in range(len(configs)):    
      for dataset in datasets:
         
	 #dataset_name = preFix+dataset.rstrip('/')+postFix+'/'
         dataset_name = dataset
	 
	 out_name = OutputName(dataset, types[i])

	 cmd  = 'python %s/submit_jobs_penn.py'%SCRIPT_BASE
	 cmd += ' --dataset DS%s'%dataset_name
	 #cmd += ' --key %d'%number
	 cmd += ' --output %s/%s/%s'%(OUTPUT_BASE,OUTPUT_DIR,out_name)
	 cmd += ' --nFilesPerJob %d'%files_per_job
	 cmd += ' --script %s/%s'%(SCRIPT_BASE,'batch_run.'+configs[i]+'.sh')
	 cmd += ' --overwrite'
	 cmd += ' --transfer-input-files'
	 cmd += ' %s'%submit
	 print cmd
	 os.system(cmd)

    return

def OutputName(dataset, job_type):

    tokens  = dataset.split('.')	  
    if len(tokens) >= 3:
      if tokens[0] == 'user':
        return tokens[2]+'.' + tokens[3] + '.' +tokens[4] + '.' + job_type
      else:
        return tokens[0]+'.' + tokens[1] + '.' +tokens[2] + '.' + job_type
    else:
      print "WARNING: unable to determine sample name" 
      return dataset + '.' + job_type


if __name__ == "__main__":

    if 'Higgs4lDev' not in os.getenv('PYTHONPATH') :
        print 'Error! Set up your environment!'
        sys.exit()
    
    from optparse import OptionParser
    p = OptionParser()
    #p.add_option('--something',type='string' ,default='test',dest='something',help='Something' )
    (options,args) = p.parse_args()

    main(options,args)

