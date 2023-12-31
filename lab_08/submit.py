#! /usr/bin/env python

import os
import json
import argparse

SHARE           = os.environ['SHARE']
assignment_name = "lab_08"
global EXEC_TYPE
EXEC_TYPE = 'RSYNC'

def main():

    # parse arguements
    parse_args()

    # get student username
    username  = get_username()

    # load student list from file
    studentlist = get_student_list()

    # augment the username
    username_augmented = studentlist[username]  + "_" + username

    # name and create the target directory
    target_dir = os.path.join(SHARE,
                            'submissions',
                            assignment_name,
                            username_augmented)

    if EXEC_TYPE == 'RSYNC':
        if not os.path.isdir(target_dir):
            os.system("mkdir " + target_dir)

        # rsync files to destination
        rsync_files(target_dir)

    else:
        list_files(target_dir)

def parse_args():
    global EXEC_TYPE
    parser = argparse.ArgumentParser(
        prog = 'submit.py',
        description='Submits student ECE 3822 work')
    parser.add_argument('-l' , '--list' , action='store_true' , help='show list of submitted files')
    args = parser.parse_args()

    if args.list is True:
        EXEC_TYPE = 'LIST'
    
def get_username():
    full      = os.path.expanduser('~')
    username  = full.split("/")[2]
    return username

def get_student_list():
    filename = os.path.join(SHARE , 
                        'submissions' , 
                        'student_dictionary.json')

    with open(filename,'r') as fid:
        studentlist = json.load(fid)

    return studentlist

def rsync_files(target_dir):
    src_files = "*"

    # build the rsync command
    cmd_rsync  = "rsync -rv --chmod=D755,F744 --chown=:ece_3822"  + " "       # basic command, force grp to ece_3822

                                                            # include only these files explicitly
    cmd_rsync += "--include=""lab_08.py"""      + " "
    cmd_rsync += "--exclude=""*"""              + " "       # ignore everything else

    cmd_rsync += src_files                      + " "       # specify files to copy
    cmd_rsync += target_dir + "/."                          # specify destination folder

    os.system( cmd_rsync )

def list_files(target_dir):
    cmd = 'ls -l ' + target_dir
    os.system( cmd )

if __name__ == "__main__":
    main()
