#!/usr/bin/env python

import os,sys

# sys.path.insert(0,'%s/../../Skimming'%os.getenv('SFRAME_DIR'))
# from dataSets import mc12_hsg2_background as datasets

# preFix  = "user.stahlman."
# tag     = ".v3"
# postFix = ".skim/"

# OUTPUT_DIR  = '03102013_test'

# OUTPUT_BASE = '/disk/userdata00/atlas_data2/stahlman/output/'
# SCRIPT_BASE = '/home/stahlman/testarea/Higgs4lDev.Fall2013/SFrame/ZZSelection/batch'

# CONFIG = 'batch_mc_ZZCutFlow_config'
# TYPE = 'Reco'

# files_per_job = 5
# submit = '--submit'
# #submit = ''

def main(options,args) :    

    datasets = []
    for i in options.datasets.split(',') :
        exec 'from dataSets import %s'%i
        exec 'datasets += %s'%i

    #print datasets
        
    #create run file
    os.system( 'python createBatchRunAndXmlFile.py '+options.SCRIPT_BASE+'/ '+options.CONFIG )
        
    for dataset in datasets:
       
       #derive dataset name (taken from skimming script)
       dsName = dataset.rstrip("/")
       dsNameLength = 131 - len(options.preFix+options.tag+options.postFix) #max allowed dataset name size 
       dsName = options.preFix+dsName[:dsNameLength]+options.tag+options.postFix

       #get number/period for data/mc
       out_name = ''
#        if 'data12' in dataset:
#          out_name = 'data12'
       if True :
         names    = dataset.split('.')	  
         if len(names) >= 3:
	   out_name = names[1] + '.' +names[2]
	 else:
	   print "WARNING: unable to determine MC number and name"  

#        print 'name is',out_name
	  
       cmd  = 'python %s/submit_jobs_penn.py'%options.SCRIPT_BASE
       cmd += ' --dataset DS%s'%dsName
       #cmd += ' --key %d'%number
       cmd += ' --output %s/%s/%s.%s'%(options.OUTPUT_BASE,options.OUTPUT_DIR,out_name, options.TYPE)
       cmd += ' --nFilesPerJob %d'%options.files_per_job
       cmd += ' --script %s/%s'%(options.SCRIPT_BASE,options.CONFIG+'_autogen.sh')
       cmd += ' --overwrite'
       cmd += ' --transfer-input-files'
       if options.submit :
           cmd += ' --submit'
       print cmd
       os.system(cmd)

    return

if __name__ == "__main__":

    if 'Higgs4lDev' not in os.getenv('PYTHONPATH') :
        print 'Error! Set up your environment!'
        sys.exit()

    if not os.getenv('SFRAME_DIR') :
        print 'Error! Set up SFRAME!'
        sys.exit()

    if not os.getenv('ATLAS_LOCAL_DQ2CLIENT_PATH') :
        print 'Error! localSetupDQ2Client and voms-proxy-init!'
        sys.exit()

    sys.path.insert(0,'%s/../../Skimming'%os.getenv('SFRAME_DIR'))
        
    from optparse import OptionParser
    p = OptionParser()
    p.add_option('-d','--dset'    ,type='string' ,default='data12_all_4l_lhfilter'     ,dest='datasets'     ,help='Dataset string from dataSets.py in Skimming directory')
    #p.add_option('-d','--dset'    ,type='string' ,default='newest_data_test'     ,dest='datasets'     ,help='Dataset string from dataSets.py in Skimming directory')
    p.add_option('--prefix'       ,type='string' ,default='user.brendlin.'             ,dest='preFix'       ,help='Dataset prefix')
    p.add_option('--tag'          ,type='string' ,default='.v1'                        ,dest='tag'          ,help='Dataset tag')
    p.add_option('--postfix'      ,type='string' ,default='.skim/'                     ,dest='postFix'      ,help='Dataset postfix')
    p.add_option('-o','--outdir'  ,type='string' ,default='',dest='OUTPUT_DIR'   ,help='Output dir')
    p.add_option('--outbase'      ,type='string' ,default='/disk/userdata00/atlas_data2/kurb/HZZ/'                           ,dest='OUTPUT_BASE'  ,help='Output base')
    p.add_option('-c','--config'  ,type='string' ,default='batch_data_ZZCutFlow_config',dest='CONFIG'       ,help='Config')
    p.add_option('--type'         ,type='string' ,default='Kurt'                       ,dest='TYPE'         ,help='Type (Reco?)')
    p.add_option('--submit'       ,action='store_true',default=False                   ,dest='submit'       ,help='Submit?')
    p.add_option('--files_per_job',type='int'    ,default=5                            ,dest='files_per_job',help='Number of files per job')
    (options,args) = p.parse_args()

    # data12_electrons_hsg2_4l
    # data12_muons_hsg2_4l

    # --outbase /disk/userdata00/atlas_data2/kurb/HZZ/
    # -o (outdir) DataChallenge14
    # -d data12_all_4l_lhfilter
    # prefix user.brendlin.
    # batch_run.data.ZZCutFlow.sh    
    proceed = True

    if not options.OUTPUT_BASE :
        print 'Error! no --outbase specified.'
        proceed = False

    if not options.OUTPUT_DIR :
        print 'Error! no --outdir specified.'
        proceed = False

    if not options.OUTPUT_BASE :
        print 'Error! no --outbase specified.'
        proceed = False

    if not options.CONFIG :
        print 'Error! no --config specified.'
        proceed = False

    if not options.TYPE :
        print 'Error! no --type specified.'
        proceed = False

    if not proceed :
        sys.exit()

    options.SCRIPT_BASE = '%s/../ZZSelection/batch'%os.getenv('SFRAME_DIR')

    main(options,args)

