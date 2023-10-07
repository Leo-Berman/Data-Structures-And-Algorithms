Lab 03
Due Sunday September 24th before midnight
Submit on ece-000 using the "submit.py" script

This week's lab will implement and expand on the circular buffer code
we wrote during Week 3. You are supplied with `lab_03.py`. This file 
includes an example of how to create a moving average filter by inheriting 
a circular buffer class, just how we did in class in C++. The circular 
buffer class is also provided for you. Do not edit that file.

Your goal is to implement a class for a Finite Impulse Response (FIR) filter.
The FIR filter works very similarly to the moving average filter. The FIR
filter is provided with a list of numbers called taps. For each point in the
input signal, the N filter taps are multiplied against the N most recent input
values and then summed. For example, if your filter taps are
taps = [0.1 , 0.3 , 0.2]
and your input signal is
x = [1,2,3,4,5,6,7]
Then the output signal y is computed as:
y[0] = 0.1*1 + 0.3*0 + 0.2*0 = 0.1
y[1] = 0.1*2 + 0.3*1 + 0.2*0 = 0.5
y[2] = 0.1*3 + 0.3*2 + 0.2*1 = 1.1
y[3] = 0.1*4 + 0.3*3 + 0.2*2 = 1.7
y[4] = 0.1*5 + 0.3*4 + 0.2*3 = 2.3
etc

The <apply_filter> function is already written and you should not edit it.

The *only* thing you should do is add a new class called <FIR> that inherits
<circ_buffer>. That class should have a constructor and a <get_filtered> method.
Note that <FIR> must explicitly call the <circ_buffer> constructor and pass
it the appropriate buffer size value. The syntax for calling a base class
constructor is detailed nicely here:
https://stackoverflow.com/questions/2399307/how-to-invoke-the-super-constructor-in-python

Plot your filtered data using Excel and try to determine what the three filters do.
Include a comment block at the top of lab_03.py that gives your understanding of
the difference between the type of filtering you get for each of the three filters.

What to turn in:
The submit script will only submit <lab_03.py>. The only thing you should add to that
file is the <FIR> class implementation and the comment block with your observations on
the filter types.

Let me know if you have questions. Good luck!