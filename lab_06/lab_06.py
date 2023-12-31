''' lab_06.py

    YOUR NAME HERE
    YOUR EMAIL ADDRESS
    DATE

    Description:
    This file creates a hash table of <student>s and tests performance
    with some simple inserts and lookups in <main>.

    Usage:
    python lab_06.py
    
'''

#################################################################
class student:

    def __init__(self,last,first,zip,gpa):

        # addeda standardized name format
        self.last  = last.lower().capitalize()
        self.first = first.lower().capitalize()
        self.zip   = zip
        self.gpa   = gpa

    def display(self):
        print(self.last, " ", self.first , " " , self.gpa , " " , self.zip)

    def stdtotal_name(self):
        return(self.last+self.first)
    def changelast(self,newname):
        self.last = newname

#################################################################
class hash_table:

    # constructor
    def __init__(self,buff_len=10):
        self.buff_len = buff_len
        self.buffer = [None]*self.buff_len

    # all-important hash-function
    def hash_function(self , std=None , last=None , first=None):

        # if a student is provided as input, use names in student
        # for the hash function. otherwise use the provided first
        # and last names
        if std: last,first = std.last, std.first
        
        # concatenate the names and compensate for capitalization
        total_name = last.lower().capitalize()+first.lower().capitalize()
    
        s = 0 # keeps track of the value of the name
        for c in total_name:
            s += ord(c)         # ord(c) converts c into ascii value
           
        index = s % self.buff_len #gets the index
        
   
        # if the index is not empty check to see if they are the same or 
        # different names
        if(self.buffer[index]!=None): 
            
            # check if the names are the same and if they aren't index +1 
            if (self.buffer[index].stdtotal_name()!=total_name):
                index = index+1
        
        


        return index
    
    # insert student into buffer
    def insert(self,std):
        index = self.hash_function(std=std)
        count = 0;
        
        # Collision compensation
        while(self.buffer[index]!=None):
            count+=1
            index+=1
            
        # adding a new version of student with label on last name and printing that back
        if(count>0):
            std.changelast(std.last+'('+str(count)+')')
            print(std.stdtotal_name()+" Is version " + str(count))
        
        self.buffer[index] = std

    # look up a student in the hash table by, 'student' or 'first' and 'last'
    def lookup(self,last,first,ver=0,display=False):
        
        # Setting a default name to test against
        testname = last.lower().capitalize()+first.lower().capitalize()
        target_student = None
        
        # Finding the index of the student using has_function
        lookupnum = self.hash_function(None,last,first)

        # setting the target student if the self.buffer exists
        if self.buffer[lookupnum]:

            # set the target student
            target_student = self.buffer[lookupnum]
        else: 

            # If not found return none and tell the user
            print("Student not found\n")
            return None
        
        # Compensating for the version of the student that was inserted due to collision
        if ver!=0:
            target_student = self.buffer[lookupnum+ver]
            testname=last.lower().capitalize()+"("+str(ver)+")"+first.lower().capitalize()
        
        # last check in case of coincidental same values (ran into this so randomly because Jimmy Neutron 
        # = Timmy Obeid in ascii.  Wild!))
        if (testname!=target_student.stdtotal_name()):
            print("Student not found\n")
            return None
        
        # Display if user requested
        if display: 
            print("\n")
            print("Search result:" ,end=" ")
            if target_student: target_student.display()
            else: print(last,first, "not found")
            print("\n")

        return target_student

    # display contents of the buffer
    def display(self):
        print("\n")
        print("Displaying complete contents of hash table:")
        for i,s in enumerate(self.buffer):
            print(i,end=" ")
            if s:
                s.display()
            else:
                print("")            
        print("\n")

def main():

    # create the hash table
    my_table = hash_table(buff_len = 15)

    # create two new students and insert them into the hash table
    my_table.insert( student( "Obeid" , "Iyad" , 19143 , 3.99) )
    my_table.insert( student( "Obeid" , "Timmy", 19147 , 3.14) )
    my_table.insert( student( "deibo", "iyad", 19002, 2.4 ))
    my_table.insert( student( "obEId" , "TiMmY", 19069 , 3.28) )
    
    # look up a student and display results
    my_table.lookup("obeiD","TiMMy",display=True)
    my_table.lookup("obEId","TiMmy",ver = 1, display=True)
    my_table.lookup("Obeid","iyad",display = True)
    my_table.lookup("DEIBO","iyad",display = True)
    my_table.lookup("BODIE","IYAd",display = True)
    my_table.lookup("Neutron","Jimmy", display = True)

    # display contents of hash table
    my_table.display()

if __name__=="__main__":
    main()
