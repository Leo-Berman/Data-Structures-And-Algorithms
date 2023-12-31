''' lab_05.cpp

   Leo Berman
   Leo.berman@temple.edu
   10/9/2023
   
   Lab 5 Binary Tree With Balance Counter

   Usage:
   python lab_05.py [test case # betweee 0-2]

instructions
    One way of determining if a tree is well balanced is to count how many of the nodes
    have zero children, one child, or two children. Well-balanced trees will have very few
    nodes with just one child. A degenerate tree will have all nodes with one child, except the
    very last node which will have zero children.

    Write the function count() which will count the occurrences of nodes with zero, one, or two
    children. You may only edit the count() function. No other edits are permissable.

    There are three test cases. The first two are simple enough that you can manually validate
    your results. The third cases reads 1000 randomly generated ints out of a file and puts them
    in the tree. My results are:

        Nodes with 0 children: 345
        Nodes with 1 children: 311
        Nodes with 2 children: 344

    Your code should return the same. 

Is this a well-balanced tree? No

If the tree was _perfectly_ balanced, what would the node counts be? See Totals Below

    
Nodes in Row    | Total Nodes | Level | 2 Children Nodes | 1 Child Nodes | 0 Child Nodes 
1               | 1           | 1     | 1                | 0             | 0              
2               | 3           | 2     | 2                | 0             | 0
4               | 7           | 3     | 4                | 0             | 0
8               | 15          | 4     | 8                | 0             | 0
16              | 31          | 5     | 16               | 0             | 0 
32              | 63          | 6     | 32               | 0             | 0
64              | 127         | 7     | 64               | 0             | 0  
128             | 255         | 8     | 128              | 0             | 0   
256             | 511         | 9     | 244              | 1             | 11 
489             | 1000        | 10    | 0                | 0             | 489 

|                  | Totals    |
| 2 Children Nodes | 499       |
| 1 Child Nodes    | 1         |
| 0 Child Nodes    | 500       |


'''

import sys

class node:

    def __init__(self,val):
        self.payload = val
        self.left  = None
        self.right = None
    
    def set_left(self, ptr):
        self.left = ptr
    
    def set_right(self,ptr):
       self.right = ptr

    def get_val(self):      return self.payload
    def get_left(self):     return self.left
    def get_right(self):    return self.right
    

class tree:

    def __init__(self):
        self.root = None
        self.cnt_0 , self.cnt_1 , self.cnt_2 = 0 , 0 , 0
    
    def insert(self,val):
        new_node = node(val)
        curr_node = self.root

        if curr_node is None:
            self.root = new_node
            return
        
        while True:
            
            if val < curr_node.get_val():
                if curr_node.get_left() is None:
                    curr_node.set_left(new_node)
                    return
                else:
                    curr_node = curr_node.get_left()
            else:
                if curr_node.get_right() is None:
                    curr_node.set_right(new_node)
                    return
                else:
                    curr_node = curr_node.get_right()

    def count(self,curr_node = None):
        

        if (curr_node == None):
            # if count is called without an input var, curr_node will be None
            # which means count is being called directly from testcase (not recursively).
            # in this case, init curr_node to root and set the count values = 0
            curr_node = self.root
            self.cnt_0 , self.cnt_1 , self.cnt_2 = 0 , 0 , 0

        if (curr_node == None):
            return

        # YOUR CODE HERE
        
        # checks if both sides have a node
        if((curr_node.get_left()!=None) & (curr_node.get_right()!=None)):
            
            # increments the count keeping track of nodes with two children
            self.cnt_2 +=1

            # calls the count pointer on both of the children
            self.count(curr_node.get_left())
            self.count(curr_node.get_right())

        # checks for single children node with a child on the left    
        elif(curr_node.get_left()!=None):

            # increments the single child count
            self.cnt_1+=1

            # calls the count function on the child
            self.count(curr_node.get_left())

        # checks for single children node with a child on the right
        elif(curr_node.get_right()!=None):
            
            # increments the single child count
            self.cnt_1+=1

            # calls the count function on the child
            self.count(curr_node.get_right())
        
        # checks if it is a zero child node
        else:

            # adds the to the zero child count
            self.cnt_0+=1
            return
        return
          

    def print_count(self):
        print("Nodes with 0 children: " , self.cnt_0)
        print("Nodes with 1 children: " , self.cnt_1)
        print("Nodes with 2 children: " , self.cnt_2)
        print("")


def testcase_0():
    print("\nTestcase 0")
    print("---------------")
    x = tree()
    x.insert(8)
    x.insert(6)
    x.insert(7)
    x.insert(9)
    x.count()
    x.print_count()

def testcase_1():
    print("\nTestcase 1")
    print("---------------")
    x = tree()
    x.insert(9)
    x.insert(8)
    x.insert(7)
    x.insert(6)
    x.count()
    x.print_count()

def testcase_2():
    print("\nTestcase 2")
    print("---------------")
    x = tree()

    with open("/data/courses/ece_3822/current/lab_05/data.txt") as f:
        for str in f.readlines():
            x.insert( int(str) )

    x.count()
    x.print_count()


def main(argv):
    if(int(argv[1])==0):
        testcase_0()
    elif(int(argv[1])==1):
        testcase_1()
    elif(int(argv[1])==2):
        testcase_2()
    else:
        print("No argument given, exiting\n")
    
    

if __name__ == "__main__":
    main(sys.argv)
