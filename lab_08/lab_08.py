from argparse import ArgumentParser
import os


            


def load_graph(opt:int) -> list :
    '''Loads the graph from file. The first <size> values
    in the array show all the nodes that the first node (A) can
    connect to. The second <size> values show all the nodes that the
    second node (B) can connect to, etc.
    Assume that Connections are unidirectional and unweighted.

    @params: opt    select graph number to load from file
    '''

    #  pick the file
    if opt==0:
        size , fname = 3 , "file_0.txt"
    elif opt==1:
        size , fname = 6 , "file_1.txt"
    elif opt==2:
        size , fname = 10 , "file_2.txt"

    # prepend directory
    fullfilename = os.path.join(os.environ['SHARE'],'lab_08',fname)
    #fullfilename = fname
    # init the graph with zeros
    graph = [[0 for _ in range(size)] for _ in range(size)]

    # read the values from the file into the graph
    with open(fullfilename) as f:
        for i in range(size):
            for j in range(size):
                graph[i][j] = int(f.readline())

    # return the graph
    return graph
# first implementation using parent first formatting
'''
def ispath(graph,start,mydict,target,firstflag=False):

    # initialize the boolean
    mybool = False

    # check if target was found
    if (start == target) & ((firstflag==False) | (graph[start][0]==1)):
        return True
    
    # remove the first element flag
    firstflag = False

    # check if node was visited before
    if start not in mydict:
        mydict.update({start:1})
    
    # if node was visited before return False
    else:
        return False
    
    # create a list of nodes to visit
    startlist = []

    # make the 1 indexed list that is 1 shorter than the length of the graph
    for i in range(len(graph)-1):
        startlist.append(i+1)
    
    # for every index above 0 start is, start replacing the 1 indexed list with a zero indexed list
    for i in range(start):
        startlist[i] = i
    
    # for every node that the start can access check if its 1 and call the corresponding node ispath
    for i in range(len(startlist)):
        if graph[start][i+1] == 1:
            mybool = ispath(graph,startlist[i],mydict,target,firstflag)
        if mybool == True:
            return True
    return False
'''
# recursive checking for path function
def ispath(graph,start,mydict,target,firstflag = True):

    # initialize the boolean
    mybool = False

    # check if target was found and deal with node not being able to access itsself
    if (start == target):
        if(firstflag == True):
            if(graph[start][target]==1):
                return True
        else:
            return True
    firstflag = False
    
    # check if node was visited before
    if start not in mydict:
        mydict.update({start:1})
    
    # if node was visited before return False
    else:
        return False
    
    # create a list of nodes to visit
    startlist = []

    # load in the connections
    for i in range(len(graph)):
        if graph[start][i] == 1:
            startlist.append(i)
    
    # print("start = ",start,"startlist ",startlist)

    # for every node that the can be accessed check recursive node ispath
    for i in startlist:
        mybool = ispath(graph,i,mydict,target,firstflag)
        if mybool == True:
            return True
    return False

def are_connected(graph:list, src:int , dst:int , disp:bool=False) ->bool:
    '''Determine whether there is a pathway from node <src> to
    node <dst>. Edge weights are either 0 (no connection) or 1 (connection).
    Optional input variable <disp> prints the result if True.
    Returns True if there is a pathway from src to dst.
    '''
    
    # init return value
    connected = False

    # YOUR CODE HERE

    # create a dictionary to keep track of where is visited
    rundict = {}
    
    # function call to recursive find path function above as ispath
    connected = ispath(graph,src,rundict,dst)

    if disp:
        print(f"Node {src} {'is' if connected else 'isn''t'} connected to Node {dst}")

    #  return connection status (true/false)
    return connected

def display(graph:list) -> None:
    '''Displays the graph as a matrix. Column 0 shows all the places that 
    the 0th node (A) can connect to. Column 1 shows all the places that the 1th
    node (B) can connect to (etc).
    
    You don't need this function to solve the lab but you might find it helpful
    to visualize the matrix.
    '''

    s = len(graph)
    for j in range(s):
        for i in range(s):
            print(graph[i][j],end=" ")
        print("")

def get_opts() -> int:
    '''Retrieve commandline argument -> specify either 0, 1, or 2
    to determine which matrix gets loaded from file
    '''
    sizes = [3,6,10]

    # set up parser
    parser = ArgumentParser()
    parser.add_argument("opt",help="Matrix Number")
    parser.add_argument("src",help="Source Node")
    parser.add_argument("dst",help="Destination Node")

    # retrieve commandline arguments
    opts = parser.parse_args()
    opt = int(opts.opt)
    src = int(opts.src)
    dst = int(opts.dst)

    # check that commandline arguements are in appropriate ranges
    if not opt in [0,1,2]:
        raise ValueError("Specify matrix 0, 1, or 2")
    if not src in list(range(sizes[opt])):
        raise ValueError(f"Source node must be an integer between 0 and {sizes[opt]-1}")    
    if not dst in list(range(sizes[opt])):
        raise ValueError(f"Destination node must be an integer between 0 and {sizes[opt]-1}")    

    # return commandline arguements
    return opt , src , dst

def main():
    '''Main Function'''

    opt , src , dst = get_opts()
    graph = load_graph(opt)
    display(graph)
    are_connected(graph,src,dst,True)


main()
