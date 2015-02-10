#!/usr/bin/env python
import os
import sys
import time
import errno
import uuid
import re

from argparse import ArgumentParser
parser = ArgumentParser()
parser.add_argument('--script',            dest='script',            default=None,      help='path to script')
parser.add_argument('--files',             dest='files',             default='',        help='comma separated list of files to transfer')
parser.add_argument('--output',            dest='output',            default=None,      help='location of output - only give if on /xrootd')
parser.add_argument('--input-command',     dest='input_command',     default='--files', help='Name of input command')
parser.add_argument('--module-args',       dest='module_args',       default=None,      help='Arguments supplied to script')
parser.add_argument('--file-queue-dir',    dest='file_queue_dir',    default=None,      help='')
parser.add_argument('--no-transfer-input', dest='no_transfer_input', default=False, action='store_true',       help='Do not transfer input')
parser.add_argument('--additional-input', dest='additional_input',   default=None,  help='Comma separated list of files to copy locally')
options = parser.parse_args()

def main() :

    # basic checks
    if options.script is None :
        print 'Use --script to provide the full path to the script'
        sys.exit(-1)

    # these will always be defined, but only
    # used with the file transfer queueing
    my_uuid = str(uuid.uuid4())
    queue_name = '%s/queue.txt' %options.file_queue_dir

    #copy the script locally
    os.system('cp %s .' %options.script)
    script_name = options.script.split('/')[-1]
    
    #copy additional files locally
    if options.additional_input is not None :
        for file in options.additional_input.split(',') :
            os.system('cp %s .' %file)


    print 'Output is %s' %options.output
    os.system('mkdir %s' %options.output)

    # get list of files to transfer
    script_files = []
    script_file_map = None
    script_file_map = collect_unique_file_names(options.files.split(','))
    script_files = script_file_map.values()

    if options.no_transfer_input :
        # read files directly
        script_files = options.files.split(',')
    else :
        #wait until file transfer is allowed
        queue_success = False
        if options.file_queue_dir is not None :
            print 'Subscribed to queue %s' %options.file_queue_dir
            print 'My ID is %s' %my_uuid
            sys.stdout.flush()
            queue_success = enter_queue(queue_name, my_uuid)
        else :
            queue_success = True

        if queue_success :
            transfer_files( script_file_map )

    if options.file_queue_dir is not None :
        exit_queue( queue_name, my_uuid)

    
    if options.input_command.count('_ATHENA_') :
    
        python_call = 'athena.py %s -c " InputFiles=[%s] %s " ' %(script_name, ','.join(['\'%s\''%f for f in script_files]), options.module_args)
    else :
        python_call = 'bash %s %s %s %s' %(script_name, options.input_command, ','.join(script_files), options.module_args)
    print python_call
    sys.stdout.flush()
    os.system(python_call)
    if script_file_map is not None :
        for nfile in script_file_map.values() :
            print('rm %s' %nfile)
            sys.stdout.flush()
            os.system('rm %s' %nfile)
    if options.output is not None :
        mod_output = options.output
        res = re.match('/xrootd(.*)', options.output)
        if res is not None :
            mod_output = res.group(1)

        for file in os.listdir('.') :
            #ignore hidden files
            if file[0] == '.' :
                continue
            print('xrdcp %s root://hn.at3f/%s/' %(file, mod_output))
            sys.stdout.flush()
            sys.stderr.write('xrdcp %s root://hn.at3f/%s/' %(file, mod_output))
            sys.stderr.flush()
            os.system('xrdcp %s root://hn.at3f/%s/' %(file, mod_output))
            sys.stderr.write('done')
            sys.stderr.flush()

    # if input files were transferred, remove them
    if not options.no_transfer_input :
        for file in script_files :
            print( 'rm %s' %file )
            sys.stdout.flush()
            os.system('rm %s' %file)
        
def collect_unique_file_names(file_paths) :
    """ make unique file names from their directory location.
        Often input files have the same name.  To avoid over-writing
        the files, give them a unique name based on its directory
        path
    """

    file_names = {}
    uniq_names = set()
    back_depth = 1 #number of preceding directores to add to the file name

    while len(file_names) == 0 or len(uniq_names) < len(file_names) :

        for file in file_paths :
            fname = os.path.basename(file)
            #join together N(=back_depth) higher directories
            prefix = '_'.join(file.split('/')[-2 - back_depth : -1])
            file_names[file] = '%s_%s' %(prefix, fname)

        uniq_names = set(file_names.values())
        back_depth += 1

        if back_depth == len(file.split('/')) :
            print 'Cannot make a unique set of file names'
            file_names = {}
            break

    return file_names

def enter_queue(queue_name, id) :

    queue_attempt = 0
    while True :
        queue_attempt += 1
        entered_queue = False
        # Get a lock on the file.  If there is space
        # in the queue, then add self to the queue
        # otherwise, wait 30 seconds and check again
        with FileLock(queue_name, timeout=1000000, delay=5) :
            print 'Acquired lock file for queue'
            sys.stdout.flush()

            #open queue file, get its entries and 
            #check if a slot is available
            qfile = open(queue_name, 'r') 
            lines = [x.rstrip('\n') for x in qfile.readlines()]
            try :
                lines.remove('')
            except ValueError :
                pass
            qfile.close()
            qfile = open(queue_name, 'a')
            if len(lines) < 2 :
                qfile.write(id +'\n')
                entered_queue = True
            qfile.close()

        if entered_queue :
            print 'Entered queue on attempt %d' %queue_attempt
            sys.stdout.flush()
            return True

        print 'Waiting to enter queue...attempt %d' %queue_attempt
        sys.stdout.flush()

        time.sleep(60)

def exit_queue( queue_name, id ) :

    #finished copying files.  Remove self from the copy queue
    #get all entries from current queue file,
    #write all but self's id to a tmp file and
    #copy over
    with FileLock(queue_name, timeout=1000000, delay=5) :
        print 'Acquired lock file for queue exit'
        sys.stdout.flush()
        qfile = open(queue_name, 'r') 
        lines = [x.rstrip('\n') for x in qfile.readlines()]
        qfile.close()
        try :
            lines.remove('')
        except ValueError :
            pass
        tmpqfile = open(queue_name+'.tmp', 'w')
        for line in lines :
            if line.count(id) :
                continue
            tmpqfile.write(line+'\n')
        tmpqfile.close()
        os.system('mv %s.tmp %s' %(queue_name, queue_name))

    return True

 
def transfer_files( script_file_map ) :

    for orig_file, new_file in script_file_map.iteritems() :
        if orig_file.count('root://') :
            print 'xrdcp %s %s' %(orig_file, new_file)
            sys.stdout.flush()
            os.system('xrdcp %s %s' %(orig_file, new_file))
        else :
            print 'cp %s %s' %(orig_file, new_file)
            sys.stdout.flush()
            os.system('cp %s %s' %(orig_file, new_file))

    break_counter = 0
    while True :
        break_counter += 1
        copied_files = []
        for file in os.listdir('.') :
            if file in script_file_map.values() :
                copied_files.append(file)
    
        redo_files = set(script_file_map.values()) - set(copied_files)
        if redo_files :
            print 'WARNING - At least one file did not transfer.  Retrying'
            print redo_files
            sys.stdout.flush()
            for orig_file, new_file in script_file_map.iteritems() :
                if new_file in redo_files :
                    if orig_file.count('root://') :
                        print 'xrdcp %s %s' %(orig_file, new_file)
                        sys.stdout.flush()
                        os.system('xrdcp %s %s' %(orig_file, new_file))
                    else :
                        print 'cp %s %s' %(orig_file, new_file)
                        sys.stdout.flush()
                        os.system('cp %s %s' %(orig_file, new_file))
        else :
            break

        if break_counter > 5 :
            print 'ERROR - Failed to copy all files!!'
            sys.stdout.flush()
            break

class FileLockException(Exception):
        pass
 
class FileLock(object):
    """ A file locking mechanism that has context-manager support so 
        you can use it in a with statement. This should be relatively cross
        compatible as it doesn't rely on msvcrt or fcntl for the locking.
    """
                             
    def __init__(self, file_name, timeout=10, delay=.05):
        """ Prepare the file locker. Specify the file to lock and optionally
            the maximum timeout and the delay between each attempt to lock.
        """
        self.is_locked = False
        self.lockfile = os.path.join(os.getcwd(), "%s.lock" % file_name)
        self.file_name = file_name
        self.timeout = timeout
        self.delay = delay
                                                                             
 
    def acquire(self):
        """ Acquire the lock, if possible. If the lock is in use, it check again
            every `wait` seconds. It does this until it either gets the lock or
            exceeds `timeout` number of seconds, in which case it throws 
            an exception.
        """
        start_time = time.time()
        while True:
            try:
                self.fd = os.open(self.lockfile, os.O_CREAT|os.O_EXCL|os.O_RDWR)
                break;
            except OSError as e:
                if e.errno != errno.EEXIST:
                    raise 
                if (time.time() - start_time) >= self.timeout:
                    raise FileLockException("Timeout occured.")
                time.sleep(self.delay)
        self.is_locked = True
                         
 
    def release(self):
        """ Get rid of the lock by deleting the lockfile. 
            When working in a `with` statement, this gets automatically 
            called at the end.
        """
        if self.is_locked:
            os.close(self.fd)
            os.unlink(self.lockfile)
            self.is_locked = False
                                                                                                 
 
    def __enter__(self):
        """ Activated when used in the with statement. 
            Should automatically acquire a lock to be used in the with block.
        """
        if not self.is_locked:
            self.acquire()
            return self
 
 
    def __exit__(self, type, value, traceback):
        """ Activated at the end of the with statement.
            It automatically releases the lock if it isn't locked.
        """
        if self.is_locked:
            self.release()
                                                             
 
    def __del__(self):
        """ Make sure that the FileLock instance doesn't leave a lockfile
            lying around.
        """
        self.release()

main()
