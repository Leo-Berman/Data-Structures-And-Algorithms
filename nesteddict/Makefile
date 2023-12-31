# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: test.exe

# define a target to link the application
#
test.exe: test.o
	g++ -g -lm test.o -o test.exe

# define targets to compile the source code
#
test.o: test.cpp Makefile
	g++ -g -c test.cpp -o test.o


# define a target to clean the directory
#
clean:
	rm -f test.o test.exe

#
# end of file
