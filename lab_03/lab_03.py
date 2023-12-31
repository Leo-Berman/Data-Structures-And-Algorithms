"""
    Lab 03 Main Code

    @Author: I. Obeid
    @Contact: iyad.obeid@temple.edu
    @Date: September 15, 2023

    Usage:
        python lab_03.py [option]
        where option is 0, 1, 2, 3, or 4 as follows: 
        0 - run the circular buffer demo code
        1 - run the moving average buffer code
        2 - apply filter 0 to the noisy data
        3 - apply filter 1 to the noisy data
        4 - apply filter 2 to the noisy data    
"""

from circ_buffer import circ_buffer
import argparse

#----------------------------------------------------------------------
#-- Define the filter taps. These are the values that define each
#-- filter. Do not modify these
#----------------------------------------------------------------------
global taps
taps = []
taps.append([
    -0.03492494582331887,
    -0.03706418919272338,
    0.020923611741374595,
    0.13680553474169418,
    0.2562279031324723,
    0.3071029997932011,
    0.2562279031324723,
    0.13680553474169418,
    0.020923611741374595,
    -0.03706418919272338,
    -0.03492494582331887])

taps.append([
    0.262019575646593,
    0.3257451656963069,
    0.262019575646593])

taps.append([
    0.03492494582331887,
    0.03706418919272341,
    -0.020923611741374557,
    -0.13680553474169416,
    -0.2562279031324723,
    0.692897000206799,
    -0.2562279031324723,
    -0.13680553474169416,
    -0.020923611741374557,
    0.03706418919272341,
    0.03492494582331887])

#----------------------------------------------------------------------
class moving_average_filter(circ_buffer):
    '''moving average filter class
    
    This class implements a moving average filter.
    It inherits circ_buffer and adds the <get_average>
    method
    '''
    def get_average(self) -> float:
        '''get buffer average value
        
        Args:
            none
        Returns:
            float:  buffer average value
        '''

        sum = 0
        for i in range(self.get_buff_size()):
            sum += self.get_element(i)
        return sum / self.get_buff_size()
#----------------------------------------------------------------------
# FIR class declaration
class FIR(circ_buffer):
    # Declaring a taps matrix
    taps
    
    # Default constructor to declare a circular buffer and set the internal taps to the input taps
    def __init__(self,input_taps):
        self.taps = input_taps
        super().__init__(len(input_taps))
    
    # Using the algorithm to return the proper filtered number
    def get_filtered(self)-> float:
        sum=0
        for i in range(self.get_buff_size()):
            sum+=self.get_element(i)*self.taps[i]
            #print(sum)
        return sum
#----------------------------------------------------------------------
def apply_filter(taps:list , filename_out:str) -> None:
    '''Apply FIR filter to <data_noisy.txt>

    ### Params
    * taps: filter taps
    * filename_out: output file name
    
    ### Returns
    * none
    '''
        
    filter = FIR(taps)
    
    file_in  = open("/data/courses/ece_3822/current/lab_03/data_noisy.txt",'r')
    file_out = open(filename_out,'w')

    for line in file_in:
        filter.insert( float(line) )
        y = filter.get_filtered()
        file_out.write(f"{y:0.2f}\n")
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def demonstrate_moving_average():
    '''Demonstrate moving average filter
    
    This function creates a filter from the moving_average_filter
    class (which inherits circ_buffer) and uses it to filter noisy 
    data. This is nearly identical to what we did in class on Friday 
    Sept 15 (week 3)

    ### Params
    * none

    ### Returns
    *none
    '''

    filter = moving_average_filter(5)
    
    file_in  = open("data_noisy.txt",'r')
    file_out = open("data_moving_avg.txt",'w')

    for line in file_in:
        filter.insert( float(line) )
        y = filter.get_average()
        file_out.write(f"{y:0.2f}\n")
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def demonstrate_circular_buffer():
    '''Demonstrates use of circular buffer base class

    This is similar to what we did in C++ during week 3
    
    ### Params
    * none

    ### Returns
    * none
    '''

    myBuff = circ_buffer(5)
    myBuff.insert(8)
    myBuff.insert(6)
    myBuff.insert(7)
    myBuff.insert(5)
    myBuff.insert(3)
    myBuff.insert(0)
    myBuff.insert(9)
    
    print( myBuff.get_element(0) )
    print( myBuff.get_element(1) )
    print( myBuff.get_element(2) )
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def parse_inputs():
    '''parse command line inputs

    Do not edit this function

    ### Params
    * none

    ### Returns
    * parsed arguments
    '''
    
    parser = argparse.ArgumentParser(
    prog='Lab 3',
    description='Lab 3 main function')
    
    parser.add_argument('option' , help='0,1,2,3')

    args = parser.parse_args()
    return args
#----------------------------------------------------------------------

#----------------------------------------------------------------------
def main():
    ''' main function for running Lab 3
    '''
    global taps

    args = parse_inputs()

    if args.option == '0':
        demonstrate_circular_buffer()

    elif args.option == '1':
        demonstrate_moving_average()

    elif args.option == '2':
        apply_filter(taps[0] , "data_filter_0.txt")

    elif args.option == '3':
        apply_filter(taps[1] , "data_filter_1.txt")

    elif args.option == '4':
        apply_filter(taps[2] , "data_filter_2.txt")

    else:
        print("error: select option 0, 1, 2, 3, or 4")
        exit
#----------------------------------------------------------------------

main()