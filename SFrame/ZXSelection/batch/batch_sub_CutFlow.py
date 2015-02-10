#!/usr/bin/env python

import os,sys

# options
INPUT_VERSION_DATA = 'blah'
INPUT_VERSION_MC = 'idk'
output_dir = '121113_ML'
files_per_job = 5
submit = '--submit'

srm_mc_base = '/xrootd/atlasC/local/sheim/mc_v6/'
output_base = '/disk/userdata00/atlas_data2/kurb/HZZ/output/'
script_base = '/home/kurb/testarea/17.2.2.2/Higgs4lDev/SFrame/ZZSelection/batch'
script      = 'batch_run.mc.ZZCutFlow.SoverB.sh'
TYPE = 'ML'

def main(options,args) :
    print 'Zee+jets'
    numbers_zee = [107650,107651,107652,107653,107654,107655]
    print numbers_zee
    print 'Zee+jets mll 10-60'
    numbers_zee_10_60 = [146830,146831,146832,146833,146834]
    print numbers_zee_10_60
    #
    print 'Zmumu+jets'
    numbers_zmumu = [107660,107661,107662,107663,107664,107665]
    print numbers_zmumu
    print 'Zmumu+jets mll 10-60'
    numbers_zmumu_10_60 = [146840,146841,146842,146843,146844]
    print numbers_zmumu_10_60
    #
    print 'Ztautau+jets'
    numbers_ztautau = range(107670,107675+1)
    print numbers_ztautau
    print 'Ztautau+jets mll 10-60'
    numbers_ztautau_10_60 = range(146850,146854+1)
    print numbers_ztautau_10_60
    #
    numbers  = numbers_zee
    numbers += numbers_zee_10_60
    numbers += numbers_zmumu
    numbers += numbers_zmumu_10_60
    numbers += numbers_ztautau
    numbers += numbers_ztautau_10_60
    #
    for number in numbers :
        cmd  = 'python %s/submit_jobs_penn.py'%script_base
        cmd += ' --dataset %s'%srm_mc_base
        cmd += ' --key %d'%number
        cmd += ' --output %s/%s/Zjets_%s_%d'%(output_base,output_dir,TYPE,number)
        cmd += ' --nFilesPerJob %d'%files_per_job
        cmd += ' --script %s/%s'%(script_base,script)
        cmd += ' --overwrite'
        cmd += ' --transfer-input-files'
        cmd += ' %s'%submit
        print cmd
        os.system(cmd)

    return

if __name__ == "__main__":

    if 'Higgs4lDev' not in os.getenv('PYTHONPATH') :
        print 'Error! Set up your environment!'
        sys.exit()
    
    from optparse import OptionParser
    p = OptionParser()
    #p.add_option('--something',type='string' ,default='test',dest='something',help='Something' )
    (options,args) = p.parse_args()

    main(options,args)

