''' circ_buffer.py

    Circular Buffer Class
    
    @Author:    Iyad Obeid
    @Contact:   iobeid@temple.edu
    @Date:      September 15, 2023

    Public Methods:
    * insert(val)
    * get_buff_size()
    * get_element(j)
    
'''

class circ_buffer:

    def __init__(self , buffsize:int):
        ''' circular buffer constructor
        
        Args:
            buffsize [int]:     size of circular buffer
        Returns:
            none
        '''
        self._buffsize = buffsize
        self._buffer = [0 for _ in range(buffsize)]
        self._ind_to_insert = 0

    def _increment_ind(self):
        '''[private] increment insertion index

        Args:
            none
        Returns:
            none'''
        self._ind_to_insert = ( self._ind_to_insert + 1 ) % self._buffsize

    def insert(self,x:float):
        '''insert number into buffer
        
        Args:
            x [numeric]:    input value
        Returns:
            none
        '''

        self._buffer[self._ind_to_insert] = x
        self._increment_ind()

    def get_buff_size(self) -> int:
        '''get buffer size
        
        Args:
            none
        Returns:
            int:    buffer size
        '''
        return self._buffsize

    def get_element(self,j:int) -> float:
        '''get element from buffer
        
        Args:
            j [int]:  index of value to return
        Returns:
            numeric:    value from buffer
        '''
        ind = (self._buffsize + self._ind_to_insert - 1 - j) % self._buffsize
        return self._buffer[ind]
