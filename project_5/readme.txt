Movies!

The Internet Movie Database is a popular website containing information on
every movie ever made. They also make a lot of their data publically 
available.

I went to this site:
https://datasets.imdbws.com/

and downloaded the names-basic, titles-basic, and titles-principal databases.

Explanations of the files can be found here:
https://www.imdb.com/interfaces/

The sheer amount of data was too much for our project, so I thinned it
out by limiting us to movies (not tv episodes or documentaries) created
after 2015.

Here's how the data is structured:

In the "movies.tsv" file, you'll find the names of all the movies
along with a unique movie identifier. For example, if I type the
following unix command, I can find Top Gun: Maverick

grep "Top Gun: Maverick" movies.tsv 

The result is

tt1745960       movie   Top Gun: Maverick       Top Gun: Maverick       0   2022     \N      130     Action,Drama

This shows me that the movie's unique identifier is tt1745960, and that the 
movie came out in 2022.

I can then look up movie tt1745960 in the starring_roles.tsv file to see
who the main cast is:

grep tt1745960 staring_roles.tsv

tt1745960       1       nm0000129       actor   \N      ["Capt. Pete 'Maverick' Mitchell"]
tt1745960       2       nm0000124       actress \N      ["Penny Benjamin"]
tt1745960       3       nm1886602       actor   \N      ["Lt. Bradley 'Rooster' Bradshaw"]
tt1745960       4       nm0000174       actor   \N      ["Adm. Tom 'Iceman' Kazansky"]

So there are four lead roles in the movie. The first is an actor with unique 
identifier nm0000129 who plays the role of Capt. Pete Maverick Mitchell. If 
I want to know the name of the actor with that identifier, I can check the 
third database:

grep nm0000129 names.tsv

nm0000129       Tom Cruise      1962    \N      actor,producer,soundtrack   tt0325710,tt0259711,tt0092099,tt0116695

That actor is Tom Cruise, born 1962.

Your goal is to make a data structure that can store and search this
information efficiently.

Step 1: Create a data structure that can store all the movies. I should
be able to search this database for a movie name. If found, it will print the name of the movie and the year, otherwise it will say not found.

Step 2: Create a data structure that can store all the actors. I should
be able to search this datbase for an actor/actress name. If found, it will
print the name of the actor/actress and their year of birth (and death, if applicable).

Step 3: Create a data structure that lets me search for an actor/actress
and then print out all the movies they play a starring role in. For example,
using the unix grep command, I can discover that Tom Cruise stars in:

tt1745960       1       nm0000129       actor   \N      ["Capt. Pete 'Maverick' Mitchell"]
tt2345759       1       nm0000129       actor   \N      ["Nick Morton"]
tt3393786       1       nm0000129       actor   \N      ["Jack Reacher"]
tt3532216       1       nm0000129       actor   \N      ["Barry Seal"]
tt4912910       1       nm0000129       actor   \N      ["Ethan Hunt"]
tt9603208       1       nm0000129       actor   \N      ["Ethan Hunt"]
tt9603212       1       nm0000129       actor   \N      ["Ethan Hunt"]

(remember this is just starring roles after 2015; Tom's been busy)

Of course I would want to print the names and years of the movies, not their unique id numbers.

Use whatever data structures make sense to you. We have enough sample code
floating around to handle every case. I expect you to design "intentionally"
meaning that you make design choices that make sense for what you are
trying to accomplish.

Remember we have tons of sample code from previous labs and projects, including how to read data from a text file. The "tsv" file format is "tab separated". If you are using the "split" command, you can specify a tab with "\t".

Feel free to code in C++ or Python.

Don't be discouraged if you can't get it all to work. I am not expecting
that everyone will successfully get this project working (but I'm keeping
my fingers crossed!).

Finally, each data file has a header row. Obviously that doesn't contain any useful data.

What to turn in:

All your code. Don't be afraid to split your code into multiple files.

A Makefile (if coding in C++)

A file named <design.txt> in which you explain the data structure(s) 
you've created and why. You can't just stuff everything into a vector and
say "it was easy". That's a lousy and inefficient design! Explain your
choices. In terms of length, I would expect this file would take 2-3 
minutes for me to read. Any longer and its too detailed (I want a
top-level explanation). Any shorter and its not detailed enough to be
useful.

Questions? I expect there will be many. I haven't done this assignment before so there are probably a lot of kinks to work out.
