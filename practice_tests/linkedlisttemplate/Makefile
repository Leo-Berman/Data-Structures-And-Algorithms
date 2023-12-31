# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: 2022fall.exe

# define a target to link the application
#
2022fall.exe: 2022fall.o
	g++ -g -lm 2022fall.o -o 2022fall.exe

# define targets to compile the source code
#
2022fall.o: 2022fall.cpp Makefile
	g++ -g -c 2022fall.cpp -o 2022fall.o


# define a target to clean the directory
#
clean:
	rm -f 2022fall.o 2022fall.exe

#
# end of file
