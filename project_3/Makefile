CXX=g++
CXXFLAGS=-std=c++11 -pthread

debug: CXXFLAGS += -g
debug: all

all: proj_3

proj_3: proj_3.cpp
	$(CXX) $(CXXFLAGS) proj_3.cpp proj_4functs.cpp -o proj_3

clean:
	rm -rf proj_3 *.o
