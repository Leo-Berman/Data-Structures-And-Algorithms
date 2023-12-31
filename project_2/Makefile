CXX = g++
CXXFLAGS = -std=c++11
INCL = /data/courses/ece_3822/current/include

all: clean
all: proj_2

debug: CXXFLAGS += -g
debug: proj_2

names_LL: names_LL.cpp
	$(CXX) $(CXXFLAGS) -I$(INCL) names_LL.cpp -o names_LL

proj_2: proj_2.cpp
	$(CXX) $(CXXFLAGS) -I$(INCL) proj_2.cpp -o proj_2

clean:
	rm -rf *.o proj_2 names_LL a.out
