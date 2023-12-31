Lab 08

The purpose of this lab is to complete the <are_connected> function that
returns "True" if there is a path from src to dst and "False" otherwise.
This includes indirect paths! If there is no direct connection between
Nodes 0 and 3, but you can get from 0 to 3 by passing through Nodes 1 and 2
then your code should return True.

There are three graphs provided in text files. I have already written the
code for loading the graphs from file into a matrix (a list of lists). The
graph is unidirectional and unweighted.

To run the program you must provide three commandline arguements:
    opt     [0,1,2]             specifies which graph file to use
    src     [0,1,...,(size-1)]  specifies the identity of the src node
    dst     [0,1,...,(size-1)]  specifies the identity of the dst node

You should test your code extensively! 

Submit using ./submit.py which will only turn in lab_08.py

Good luck!