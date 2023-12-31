CXX=g++
CXXFLAGS=-std=c++11

debug: clean
debug: CXXFLAGS+= -g
debug: proj_4

all: proj_4

proj_4: proj_4.cpp
	$(CXX) $(CXXFLAGS) proj_4.cpp -o proj_4

clean:
	rm -f *.o proj_4
