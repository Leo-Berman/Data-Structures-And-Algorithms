# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: lab_02.exe

# define a target to link the application
#
lab_02.exe: lab_02.o student.o
	g++ -g -lm lab_02.o student.o -o lab_02.exe

# define targets to compile the source code
#
lab_02.o: lab_02.cpp student.h Makefile
	g++ -g -c lab_02.cpp -o lab_02.o

student.o: student.cpp student.h Makefile
	g++ -g -c student.cpp -o student.o

# define a target to clean the directory
#
clean:
	rm -f lab_02.o lab_02.exe

#
# end of file


