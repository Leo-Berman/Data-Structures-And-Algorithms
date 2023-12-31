Lab 09

The purpose of this lab is to modify the Dijkstra's algorithm code we wrote in
class to implement a variant known as A*. A* is almost identical to Dijkstra's
except that when you're deciding which node to select next you use a sum of 
best-distance and best_guess and pick whichever node has the minimum of those two.

Dijkstra:
    next node is the <incomplete> node with the minimum best-distance
A*:
    next node is the <incomplete> node with the minimum (best-distance + best_guess)

There are many acceptable ways of determining "best_guess". An easy one to implement
is called the Manhattan Distance, which is just the delta_x plus delta_y between a 
given node and the target node. For example, if some node has coordinates (12,82) and
the target (end) node is at (100,25) then the Manhattan distance is |100-12| + |25-82|
which equals 145.

The reason we do this is that we might be able to get to the target node faster
if we prioritize nodes that are closer to the target, even if their best-score is
a bit higher.

I have provided you a copy of the Dijkstra code from class, renamed <lab_09.py>.

Modify this code in two ways:

[1] Have it count the number of times the main loop executes. When I ran Dijkstra
on aoc_2.txt I got 7297 passes through the main loop.

[2] Modify the main loop to incorporate the A* algorithm. If you're careful, this only
requires a couple of extra lines of code. In implementation I modified one existing
line of code and added a function with about 5 lines of code. If you feel like you are
working too hard, you probably are. The implementation doesn't have to be complicated.

Run your code on aoc_2.txt with and without A*. Do you get the same 'shortest path' using
both methods? Does A* reduce the number of passes through the main loop? Put your answers
in a comment block at the top of your program.

To run lab_09.py you may provide zero or one command line arguements:
    python lab_09.py        -> runs on aoc_1.txt 
    python lab_09.py 1      -> runs on aoc_1.txt 
    python lab_09.py 2      -> runs on aoc_2.txt 

Submit using ./submit.py which will only turn in lab_09.py

Good luck!