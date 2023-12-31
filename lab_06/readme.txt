In lab_06.py you will find hash table code that is nearly identical
to what we have been working on in class. Take a minute to familiarize
yourself with the implementation differences between C++ and Python.

You have the following goals.

[1] Complete the lookup() function. You should be able
to look up a student that is in the hash table AND properly
return a None if that student is not in the hash table

[2] Improve the hash_function() in two ways. First, make it
case insensitive, so if someone searches for "Obeid" or "obeid"
it won't make a difference. Secondly, make the hash-function
sensitive to the order of the characters, so that "obeid" and "deibo"
don't map to the same array location

[3] During the insert function, if there is already data in the
buffer (eg a collision), try inserting at the next index location
until you find an empty spot.

Make sure to include enough test code in main() to demonstrate
that items [1]-[3] are working properly