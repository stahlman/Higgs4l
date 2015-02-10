#from argparse import ArgumentParser
import os, sys
from optparse import OptionParser
import subprocess
from ROOT import TXNetFile, TTree
from pyAMI.query import get_dataset_info
from pyAMI.client import AMIClient

def ParseOptions() :

    parser = OptionParser()

    parser.add_option("--in",dest="in_dataset")
    parser.add_option("--out",dest="out_dataset")

    (options, args) = parser.parse_args()

    return options

def main(options) :


    if 'DQ2_HOME' not in os.environ:
      print 'ERROR: Setup DQ2 client'
      return

    in_dataset  = vars(options).get('in_dataset',None)
    out_dataset = vars(options).get('out_dataset',None)

    print in_dataset

    if not isinstance(in_dataset, list) :
        in_dataset = [in_dataset]
        
    matched_files = []
        
    for each_path in in_dataset :

        client = AMIClient()
        infos = get_dataset_info(client, each_path)
        #print infos.info['totalEvents']
        nevents = int(infos.info['totalEvents'])
        #info = infos[0]
        #print info.extra['crossSection_mean']
        #nevents = int(info.info['totalEvents'])
        #print "AMI nEvents:",nevents
        #print (str(xsec))                                                                                                        

        print 'searching dq2 for %s' %out_dataset

        worker_path = 'root://hn.at3f'

        dq2cmd = "dq2-ls " + "-fpL " + "UPENN_LOCALGROUPDISK " + out_dataset

        dq2process = subprocess.Popen(dq2cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        out,err = dq2process.communicate()

        dq2lines = out.split('\n')

        
        for dq2line in dq2lines:
            if dq2line.find('root') != -1:
                if dq2line.find('srm:') != -1:
                    matched_files.append(dq2line.replace('srm://srm.hep.upenn.edu:8443/srm/v2/server?SFN=/disk/space00/','root://hn.at3f//'))


    matched_files = list(set(matched_files))

    #print matched_files

    totalEntries = 0

    for matched_file in matched_files:
        file = TXNetFile(matched_file)
        tree = file.Get("physics")
        #print matched_file," contains:",tree.GetEntries()
        n_tree = tree.GetEntries()
	if (n_tree == 0):
	  print "WARNING: Empty file: ",matched_file
	totalEntries += n_tree
        file.Close()

    print 'AMI total:',nevents,'\t','Calculated Total:',totalEntries,'\t','Discrepancy:',int(nevents-totalEntries)

if __name__ == '__main__' :
    main(ParseOptions())
