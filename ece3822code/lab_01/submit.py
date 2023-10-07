#! /usr/bin/env python

import os
assignment_name = "lab_01"

# get student username
full      = os.path.expanduser('~')
username  = full.split("/")[2]

# augment the username
studentlist = {}
studentlist["tug80737"]="ahmed"
studentlist["tuo69407"]="badawika"
studentlist["tuk59682"]="bady"
studentlist["tuq56433"]="bakum"
studentlist["tuo54571"]="berman"
studentlist["tuk35965"]="bulik"
studentlist["tup32168"]="caiozzo"
studentlist["tuf97069"]="cavallaro"
studentlist["tuf99772"]="chandavong"
studentlist["tun38664"]="chau"
studentlist["tuj60238"]="cowen"
studentlist["tul69453"]="dewees"
studentlist["tul13528"]="grinshpun"
studentlist["tul60393"]="guan"
studentlist["tuj15180"]="herrin"
studentlist["tuo52028"]="ibrahim"
studentlist["tuf91237"]="isely"
studentlist["tug68812"]="juarez"
studentlist["tup76130"]="leap"
studentlist["tuo56392"]="levin"
studentlist["tuo61219"]="lopez-morel"
studentlist["tud21266"]="luka"
studentlist["tuo72868"]="mcnicholas"
studentlist["tul16619"]="nghiem"
studentlist["tuj97730"]="nori"
studentlist["tuk10978"]="patel"
studentlist["tuo56709"]="prunes"
studentlist["tuo73004"]="raab"

username_augmented = studentlist[username]  + "_" + username

# name and create the target directory
target_dir = "/data/courses/ece_3822/current/submissions/" + assignment_name + "/" + username_augmented

if not os.path.isdir(target_dir):
    os.system("mkdir " + target_dir)

src_files = "*"

# build the rsync command
cmd_rsync  = "rsync -av --chown=:ece_3822"  + " "       # basic command, force grp to ece_3822
cmd_rsync += "--exclude="".*"""             + " "       # ignore hidden files
cmd_rsync += "--exclude=""*.o"""            + " "       # ignore object files
cmd_rsync += "--exclude=""songlist.txt"""   + " "       # ignore text files
cmd_rsync += "--exclude=""readme.txt"""     + " "       # ignore text files
cmd_rsync += "--exclude=""submit.py"""      + " "       # ignore submit.py file
cmd_rsync += "--exclude=" + assignment_name + " "       # ignore executable with same name as folder
cmd_rsync += src_files                      + " "       # specify files to copy
cmd_rsync += target_dir + "/."                          # specify destination folder

os.system( cmd_rsync )
