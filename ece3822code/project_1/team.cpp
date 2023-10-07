#ifndef TEAM_H
#define TEAM_H

#include "player.cpp"

using namespace std;

class team{
  private:
    string name;
    vector<player*> players;
    int score;
  
  public:
    team(string namein="no name");
    void add_player(player* name,int statusnum);
    void play_turn();
    int get_score();
    string get_name();
    ~team();
};

// Default constructor
team::team(string namein){
  name=namein;
}

// Default destructor
team::~team(){
}

// Add Player to Team
void team::add_player(player* name,int statusnum){
  players.push_back(name);
  name->set_status(statusnum);
}

// Play a teams turn
void team::play_turn(){
  int track = 0;
  for(int i = 0; i<players.size();i++){
    players[i]->play_turn();
    if(players[i]->get_status()==1) {
      players[i]->play_turn();
    }  
    track+=players[i]->get_score();
  }
  score=track;
}

// Return team's current score
int team::get_score(){
    return(score);
}

// Return Team's Name
string team::get_name(){
    return(name);
}
#endif
