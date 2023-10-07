'''
Lab 01

Description

@Leo Berman: 
@leo.berman@temple.edu:
@8/30/2023:

Example:
    This file can be run by typing
    python lab_01.py [filename].txt
'''

import sys

# Gets the mean function from statistics library
from statistics import mean
from math import sqrt

def main(argv):
    '''
    # don't mess with this part
    filename = "/data/courses/ece_3822/current/lab_01/data.txt"
    if len(argv) > 1:
        filename = argv[1]
    '''
    err ="please use format python lab_01.py [filename].txt"
    if len(argv) == 2:
        filename = argv[1]
    if len(argv)>2 :
        print("Too many arguments",err)
        exit()
    if len(argv)<2 :
        print("Not enough arguments",err)
        exit()
    
    # This is some demo code to show you how to read an integer out of a text
    # file. There are other ways to do this and those are fine too if you prefer
    x = []
    with open(filename) as f:
        for line in f:
            x.append(int(line))
   
    # Takes the integers in list x and takes the mean and converts the mean from float to integer
    y=int(mean(x))

    # Prints desired statement with mean
    print("The average value is",y)

    # Sorts list from greatest to least
    x.sort(reverse=True)

    # Fomds the square root of the sum
    z=int(sqrt(x[0]*x[1]))
    
    #prints the two highest numbers sum of squares
    print("The sum of squares is",z)
    
if __name__=="__main__":
    main(sys.argv)
