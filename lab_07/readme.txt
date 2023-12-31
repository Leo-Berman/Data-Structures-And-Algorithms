There are several purposes to this week's lab. It mirrors
much of what we did in class last week. The first purpose
is to get you used to looking through a big set of code,
understand its structure, and amend it properly. The second
purpose is to implement a database class, taking advantage
of inheritance.

[1] Skim through the code. There is a linked_list class
which does exactly what you would expect. You don't
need to make any edits to this class

[2] There is a "base" hash_table class which is designed
specifically for other classes to inherit. For example,
the hash_table_firstname class inherits the base class
and adds overrides for the hash_function and lookup 
function.

[3] Write code to complete hash_table_lastname and
hash_table_id, using hash_table_firstname to guide
you.

[4] Run test_case_1() to make sure your solutions to
item [3] work as expected. 

[5] As you can see in test_case_1(), every student
has to be explicitly inserted into three different hash tables.
Its a painful process. Create a db class whose member variables
are the three hash tables. When a user calls db.insert(),
it will automatically insert the new student into all
three hash_tables. Likewise, when the user calls a lookup
function, the db class should call lookup() on the appropriate
hash table.

[6] Check to make sure [5] works by running test_case_2()

Good luck!