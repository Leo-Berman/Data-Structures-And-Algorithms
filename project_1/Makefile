CXX = g++
CFLAGS = -std=c++11
INCL = ${SHARE}/include
LIBS = ${SHARE}/include

all: play_game

debug: CFLAGS += -g
debug: play_game

player.o: player.cpp
	$(CXX) $(CFLAGS) -I$(INCL) -c player.cpp

team.o: team.cpp
	$(CXX) $(CFLAGS)  -I$(INCL) -c team.cpp

play_game.o: play_game.cpp
	$(CXX) $(CFLAGS) -I$(INCL) -c play_game.cpp

play_game: play_game.cpp 
	$(CXX) $(CFLAGS) -I$(INCL) -L$(LIBS) play_game.cpp -lece_3822 -o play_game

clean:
	rm -f *.o play_game
