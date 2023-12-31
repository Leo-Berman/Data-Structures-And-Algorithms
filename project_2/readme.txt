**Goal:** 
The goal of Project 2 is to practice using objects and re-using pre-written linked-list code.
I have already written a generic linked list class which you can read at $SHARE/include. You will
*not* copy this code to your local directory.

**Acquire Code:**

rsync -rv $SHARE/proj_2 .

**Inheritance:**
STOP! Before reading the project details, start by looking at the sample code 
called names_LL.cpp. It creates a linked list of "name" data. Note how it re-uses
the pre-written linked list. I can amend it by adding my own "find" functions. 
You can make and run this program with:
make names_LL
./names_LL

**Problem: **
You work for an online video streaming service, and you have to manage data on your customers. Each 
customer has an ID number and a list of movies they watched last month. The data is stored in a text 
file in the following format:
    customer ID number
    number of movies watched last month
    ID numbers of the movies watched last month

For example: suppose a file has data on two customers, it might look like this:

724
3
225
502
109
449
2
109
305

Customer #1 has ID number 724 and watched 3 movies whose ID numbers are 225, 502, and 109.
Customer #2 has ID number 449 and watched 2 movies whose ID numbers are 109 and 305

As you can see, both customers watched the movie whose ID number is 109

Your goals is to get the following functions to work:

clients.print_all() - prints all the customer information in this format:

Customer 724 watched 225, 502, 109
Customer 449 watched 109, 305

clients.print_customer(customerID) - prints the information for a specific customer

Customer 724 watched 225, 502, 109

clients.print_views(movieID) - prints the number of customers who watched a movie

Movie 109 was watched 2 time(s)

**What/Where to Code:**

I've written some code to get  you started. Fill in code everywhere
that I've indicated. You should also feel free to add more code,
class method functions, etc, as necessary to make your job easier.
You can write all your code directly in proj_2.cpp. If you really want you
can split code into multiple files (.h and .cpp) and the submit script should
grab them.


**Data Files:**
There are three data files for you to test your algorithm, the first 
one is pretty short, the last one is pretty long.

dataFile1.txt  
dataFile2.txt
dataFile3.txt 

**Makefile**
Use the Makefile!
make proj_2
./proj_2
