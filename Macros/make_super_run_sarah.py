###############################################################################
# This python script takes an input directory with files,
# created listfiles with a requested number of files; 
# for every listfile it makes a cmd, and two bash files for condor submission
# and it submits it!
#
# It needs 7 arguments (plus the macro name)
#
# example for submission:
# python make_super_run_sarah.py makeHistograms_CatX.py /disk/userdata00/atlas_data2/sheim/output/02262013_X Zjets mc 10
#
# Author: Sarah Heim, 2013
###############################################################################

# Import modules
import sys
import os
import glob
import string

###############################################################################
# Check command line parameters
###############################################################################
if len(sys.argv) != 6:
    print "Usage: python make_super_run_sarah.py <executable> <inputdir> <keyword> <data/mc> <number files per job>"
    sys.exit()
    
###########################################################################
# Define joinstr method- joins strings together without spaces
# Takes a list of strings as an argument such as ["ab","cd"]
###########################################################################
def joinstr(str_list):
    return ''.join(str_list)

###############################################################################
# Set Additional Parameters
###############################################################################

#Location 
homeDir = "//home/sheim/SFrame/Higgs4lDev/Macros/"

###############################################################################
# Set Parameters from input
###############################################################################

executable = sys.argv[1]
inputdir = sys.argv[2]
keyword = sys.argv[3]
type = sys.argv[4]
numberfiles = int(sys.argv[5])
outputdir = inputdir+'/out_'+keyword

####################

# Output directories, create only if they don't exists yet
homeOut = joinstr([outputdir,"/rootfiles/"])
homeLog = joinstr([outputdir,"/logfiles/"])

if not os.path.isdir(homeOut):
    os.makedirs(homeOut)
if not os.path.isdir(homeLog):
    os.makedirs(homeLog)
  

#script dir
scriptDir = joinstr([homeDir,"/scripts/"])
if not os.path.isdir(scriptDir):
    os.makedirs(scriptDir)


###############################################################################
# make list files
###############################################################################

#os.chdir(inputdir)
data = glob.glob(inputdir + '/*'+keyword+'*/Job*/*.root')
data.sort()
numDataFiles = len(data)
print "There are",  numDataFiles, " data files to include in list file\n"

#os.chdir(homeDir)

#listarray = []

for ilist in range(0,numDataFiles,numberfiles):
    
    listfile = joinstr([scriptDir,"/listfile_",keyword,"_",str(ilist)])
    fileOutputList    = file(listfile,"w")
    print "\nOpened output file", listfile, "for writing\n"
    #listarray.append(fileOutputList)
    
    for k in range (ilist, ilist+numberfiles):
        if k >= numDataFiles:
            break
        DataFile = data[k]
        #DataFile = "/".join(DataFile)
        print >>fileOutputList, DataFile

###############################################################################
    # Write output files for running on the cluster
    # Add newest file submission request to submission script
###############################################################################
    
    #Form the output filename     
    
    hfile = joinstr([keyword,"_passed_",str(ilist),".root"])
     
    outcmd = joinstr([scriptDir,"RunAnalysis.",keyword,"_",str(ilist),".cmd"])
    outcmdf = file(outcmd, "w")
    outsh = joinstr([scriptDir,"RunShell.",keyword,"_",str(ilist), ".sh"])
    outshf = file(outsh, "w")
    outch = joinstr([scriptDir,"RunExec.",keyword,"_",str(ilist), ".sh"])
    outchf = file(outch, "w")
    print "\nOpened output files for writing\n"

    outsub = joinstr([scriptDir,"RunSubmit.",keyword,"_",str(ilist),".sh"])
    outsubf = file(outsub, "w")
    os.system(joinstr(["chmod a+rwx ", outsub]))
    print >>outsubf, "#!/usr/bin/env bash"
   
    print >>outsubf, "condor_submit", outcmd 
    
    print >>outcmdf, "universe = vanilla"
    print >>outcmdf, "getenv = true"
    print >>outcmdf, "executable = ", outsh
    print >>outcmdf, "output = ", joinstr([homeLog, "/log.",keyword,"_",str(ilist), ".stdout"])
    print >>outcmdf, "error = ", joinstr([homeLog, "/log.",keyword,"_",str(ilist), ".stderr"])
    print >>outcmdf, "log = ", joinstr([homeLog, "/log.",keyword,"_",str(ilist), ".log"])
    print >>outcmdf, "queue 1"

    print >>outshf, "#!/usr/bin/env bash"
    print >>outshf, "cd $_CONDOR_SCRATCH_DIR"
    print >>outshf, "#symbolic links to all the necessary stuff"
    print >>outshf, "ln -s", joinstr([homeDir, "/externals"]), "externals"
    print >>outshf, "ln -s", joinstr([homeDir, "/Categorization_class.py"]), "Categorization_class.py"
    print >>outshf, "ln -s", joinstr([homeDir, "/Histmaker_class.py"]), "Histmaker_class.py"
    print >>outshf, "ln -s", joinstr([homeDir, "/Histfiller_class.py"]), "Histfiller_class.py"
    print >>outshf, "ln -s", joinstr([homeDir, "/",executable]), executable
    print >>outshf, "ln -s", joinstr([outch, " run_link.sh"])
    print >>outshf, "./run_link.sh"
    print >>outshf, "mv", hfile, joinstr([homeOut, "/", hfile])
    
    print >>outchf, "#!/bin/sh"
    print >>outchf, "python", executable, inputdir, keyword, type, listfile, hfile   

        
    os.system(joinstr(["chmod a+rwx ", outch]))
    os.system(joinstr(["chmod a+rwx ", outsh]))
 

###### close files
    
    fileOutputList.close()
    outcmdf.close()
    outchf.close()
    outshf.close()
    outsubf.close()

###### submit!!!

    
    os.system(outsub)




