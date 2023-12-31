''' lab_07.py

    Leo Berman
    leo.berman@temple.edu
    10/31/2023

    Description:
    Implement a database that contains hash tables of students organized by first name, last name,
    and id.
    
    The following classes already exist:
        <linked_list>
        <student>
        <hash_table_base>
        <hash_table_firstname>

    The following classes have to be completed:
        <hash_table_lastname>
        <hash_table_id>
        <db>

    Usage:
    python lab_07.py TESTCASE
        where TESTCASE is either 1 or 2
    
    What to submit:
    The submit script will only submit lab_07.py   

'''

import argparse

class linked_list:
    '''standard linked list class'''

    class node:
        def __init__(self,data=None,next=None):
            self.data = data
            self.next = next
    
    def __init__(self):
        self.head = None

    def insert(self,value):
        new_node = self.node(data=value,next=self.head)
        self.head = new_node

    def lookup(self,target=None,field=None,disp=False):
        curr_ptr = self.head
        ret_val = []

        while (curr_ptr is not None):
            if hasattr(curr_ptr.data,field) and \
                getattr(curr_ptr.data,field) == target:
                    ret_val.append(curr_ptr.data)
            curr_ptr = curr_ptr.next

        if disp and ret_val:
            for r in ret_val:
                r.display()
        elif disp and not ret_val:
            print(field, "=" , target, " not found")

        return ret_val

class student:
    '''class of <student>'''

    def __init__(self,firstname="",lastname="",id=0,major=""):
        self.firstname = firstname
        self.lastname  = lastname
        self.id = id
        self.major = major
    def display(self):
        print(self.firstname , self.lastname , self.id , self.major)

class hash_table_base:
    '''basic hash table designed to be inherited'''

    def __init__(self , array_len = 50):
        self.buffer = [linked_list() for i in range(array_len)]
        self.array_len = array_len
    def insert(self,item):
        key = self.hash_function(item)
        self.buffer[key].insert(item)
    def hash_function(self,item=None,hash_item=None):
        return 0
    def lookup(self,item=None,disp=False):
        return None

class hash_table_firstname (hash_table_base):
    '''
    hash table of students organized by first name
    inherits <hash_table_base>
    '''
    
    def hash_function(self, item=None, hash_item=None):
        # YOUR CODE HERE
        if hash_item is None: # Check to see if their is an item assigned to the function
            hash_item = item.firstname # Set the hash item from student if not
        s = 0 # initialize an integer to use
        for ch in hash_item: # calculate hash number
            s += ord(ch) 
        return s%self.array_len # return index

    def lookup(self, target=None, disp=False):
        key = self.hash_function(hash_item=target) # call the hash function
        return self.buffer[key].lookup(target,"firstname",disp) # return the student

class hash_table_lastname (hash_table_base):
    '''hash table of students organized by last name'''

    def hash_function(self, item=None, hash_item=None):
        # YOUR CODE HERE
        if hash_item is None: # Check to see if their is an item assigned to the function
            hash_item = item.lastname # Set the hash item from student if not
        s = 0 # initialize an integer to use
        for ch in hash_item: # calculate hash number
            s += ord(ch) 
        return s%self.array_len # return index

    def lookup(self, target=None, disp=False):
        # YOUR CODE HERE
        key = self.hash_function(hash_item=target) # Call the hash function 
        return self.buffer[key].lookup(target,"lastname",disp) # Return the student

class hash_table_id (hash_table_base):
    '''hash table of students organized by id number'''
    
    def hash_function(self, item=None, hash_item=None):
        # YOUR CODE HERE
        if hash_item is None: # Check to see if their is an item assigned to the function
            hash_item = item.id # Set the hash item from student if not
        s = 0 # initialize an integer to use
        s=int((hash_item/100)*5) # calculate hash number
        return s%self.array_len # return index
        return

    def lookup(self, target=None, disp=False):
        # YOUR CODE HERE
        key = self.hash_function(hash_item=target) # Call the hash function
        return self.buffer[key].lookup(target,"id",disp) # return the student

class db:
    # YOUR CODE HERE
    
    # Initializing with all the hash tables
    def __init__(self):
        self.table_f_name = hash_table_firstname() # First name hashtable
        self.table_l_name = hash_table_lastname() # Last name hashtable
        self.table_id     = hash_table_id() # Student ID hashtable
    
    # insert student into all hash tables
    def insert(self,item):
        self.table_f_name.insert(item) # Insert into first name hashtable
        self.table_l_name.insert(item) # Insert into last name hashtable
        self.table_id.insert(item) # Insert into id hashtable
    
    # All purpose lookup function that can take First,last,id, and whether or not to disp
    def lookup(self, last = None,first = None, id = None,isdisp = True):
        
        # Check if last is set
        if(last != None):
            return self.table_l_name.lookup(last,isdisp) # Call lastname hashtable lookup

        # Check if first is set
        elif(first != None):
            return self.table_f_name.lookup(first,isdisp) # Call firstname hashtable lookup

        # Check if id is set
        elif(id != None):
            return self.table_id.lookup(id,isdisp) # Call id hashtable lookup

        # If none were set print error because not used correctly
        else:
            print("Please use datatbase lookupfunction as lookup(last = lastname/first = firstname/id = studentid)")
    
    # Look up by first name
    def lookup_first(self, first = None,isdisp = True):
        return self.table_f_name.lookup(first,isdisp) # Call firstname hashtable lookup
        
    
    # Lookup by last name
    def lookup_last(self,last = None,isdisp = True):
        return self.table_l_name.lookup(last,isdisp) # Call lastname hashtable lookup
        
    
    # Lookup by id num
    def lookup_id(self,id = None,isdisp = True):
        return self.table_id.lookup(id,isdisp) # Call id hashtable lookup
        
        

def test_case_1():
    '''Test Case 1: test individual hash tables'''

    table_f_name = hash_table_firstname()
    table_l_name = hash_table_lastname()
    table_id     = hash_table_id()

    st1 = student( "Bob"  , "Smith" , 123 , "ECE"     )
    st2 = student( "Jeff" , "Smith" , 456 , "ME"      )
    st3 = student( "Jeff" , "Bezos" , 492 , "CompSci" )

    table_f_name.insert(st1)
    table_f_name.insert(st2)
    table_f_name.insert(st3)

    table_l_name.insert(st1)
    table_l_name.insert(st2)
    table_l_name.insert(st3)

    table_id.insert(st1)
    table_id.insert(st2)
    table_id.insert(st3)

    print("\nLookup ID = 123")
    table_id.lookup(123,disp=True)    

    print("\nLookup firstname = Jeff")
    table_f_name.lookup("Jeff",disp=True)

    print("\nLookup lastname = Bezos")
    table_l_name.lookup("Bezos",disp=True)

    print("\nLookup lastname = Smith")
    table_l_name.lookup("Smith",disp=True)

    print("\nLookup ID = 987")
    table_id.lookup(987,disp=True)

    print("")


    return

def test_case_2():
    '''Test Case 2: test database'''

    my_db = db()

    my_db.insert( student( "Bob"  , "Smith" , 123 , "ECE"     ) )
    my_db.insert( student( "Jeff" , "Smith" , 456 , "ME"      ) )
    my_db.insert( student( "Jeff" , "Bezos" , 492 , "CompSci" ) )

    my_db.lookup(last="Smith")
    my_db.lookup_first(first="Bob")
    my_db.lookup_id(id=989)

    return

def parse_inputs():
    '''parse command line inputs

    Do not edit this function

    ### Params
    * none

    ### Returns
    * parsed arguments
    '''
    
    parser = argparse.ArgumentParser(
    prog='Lab 7',
    description='Lab 7 Main Code')
    
    parser.add_argument('test_case' , help='1,2')

    args = parser.parse_args()
    return args

def main():

    args = parse_inputs()
    if args.test_case == '1':
        test_case_1()
        return

    if args.test_case == '2':
        test_case_2()
        return

    print("\n>>>>> Invalid test case specified at commandline <<<<< \n")
    raise SystemError


if __name__=="__main__":
    main()