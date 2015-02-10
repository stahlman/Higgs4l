import sys

if not len(sys.argv) >= 3:  raise(Exception, "Must specify input directory and file name as argument!")

input_dir = sys.argv[1]
input_config = sys.argv[2]

fout = open(input_dir + 'batch_run.' + input_config +'.sh','w')

fout.write('#!/bin/bash\n')

fout.write('# first argument is "--files", thrown away\n')
fout.write('echo "argument was:"\n')
fout.write('echo $2\n')

fout.write('ARGS=""\n')
fout.write('if [[ $2 == *:/* ]]; then\n')
fout.write('  ARGS="-r"\n')
fout.write('fi\n')

fout.write('sframe_input.py - $ARGS -d -o input_batch.xml -t physics $2\n')

fout.write('# check that input xml exists\n')
fout.write('if [ -e input_batch.xml ]\n')
fout.write('then\n')
fout.write('  cat input_batch.xml\n')
fout.write('else\n')
fout.write('  echo "ERROR: problem with input files"\n')
fout.write('  exit 1\n')
fout.write('fi\n')

fout.write('pwd\n')

fout.write('cp '+input_dir+'../config/*.dtd '+input_dir+input_config+'.xml .\n')
fout.write('ls -arlt\n')

fout.write('echo ""\n')
fout.write('echo "--> Before running SFrame"\n')
fout.write('echo ""\n')

fout.write('# run SFrame\n')
fout.write('sframe_main '+input_config+'.xml\n')

fout.write('echo ""\n')
fout.write('echo "--> SFrame finished"\n')
fout.write('echo ""\n')

fout.close()
