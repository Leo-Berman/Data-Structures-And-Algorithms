#ifndef PLAYER_H
#define PLAYER_H

/* this include gives you access to 
    int generate_score(int)
which takes ability (0,1,2) as input and returns a valid 
score according to the project instructions */
#include "ece_3822.h"
#include <random>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class player{
  private:
    int abilitylevel;
    string name;
    int status;
    int score;
  
  public:
    player(string nameinput,int abilityinput);
    void set_ability(int ability);
    void reset_score();
    int play_turn();
    int get_score();
    void display();
    void set_status(int statusinput);
    int get_status();
    ~player();
};

// Default Constructor
player::player(string nameinput="no name",int abilityinput=0){
  abilitylevel=abilityinput;
  name=nameinput;
  score=0;
  status=0;
}
// Default Destructor
player::~player(){
}
void player::set_status(int statusinput){
  status=statusinput;
}

void player::set_ability(int ability){
  abilitylevel=ability;
}

void player::reset_score(){
  score=0;
}

int player::play_turn(){
  score=score+generate_score(abilitylevel);
  return score;
}

int player::get_status(){
  return(status);
}

int player::get_score(){
  return(score);
}

void player::display(){
  cout << name << ":" << score;
}

#endif
