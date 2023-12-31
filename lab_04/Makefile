CXX = g++
CXXFLAGS = -std=c++11

all: lab_04

debug: CXXFLAGS += -g
debug: lab_04

lab_04: lab_04.cpp linked_list.h
	$(CXX) $(CXXFLAGS) lab_04.cpp -o lab_04

clean:
	rm -f *.o lab_04