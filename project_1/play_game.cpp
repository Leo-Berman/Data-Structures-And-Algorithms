#include<iostream>
#include <time.h>
#include<cstring>
//#include "player.cpp"
#include "team.cpp"

using namespace std;

void test_case_1();
void test_case_2();
void test_case_3();

int main(int argc, char **argv){

    // randomize the random number generator
    srand(time(NULL));

    // pick a test case to run, or modify to create your own
    if (argc == 1){
        cout << "error - specify test case 1, 2, or 3 at the command line" << endl;
        exit(EXIT_FAILURE);
    }
   
    if ( strcmp(argv[1] , "1") == 0 )
        test_case_1();
    
    else if ( strcmp(argv[1] , "2") == 0)
        test_case_2();
    
    else if ( strcmp(argv[1] , "3") == 0)
        test_case_3();
    
    else{
        cout << "error - invalid command line option" << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Test ability to create players
void test_case_1(){

    cout << "********** Test Case 1 **********" << endl;

    // create a player
    player alice("Alice Adams");

    // reset player's score to zero
    alice.reset_score();

    // set player's ability (0, 1, or 2)
    alice.set_ability(0);

    // player gets a single turn (score is incremented by a random number)
    alice.play_turn();

    // return the player's score
    int score = alice.get_score();

    // display the player's name and total score
    alice.display();

    cout << endl;
}

// Test ability to create teams
void test_case_2(){

    cout << "********** Test Case 2 **********" << endl;

    // create players by specifying name and skill level
    player* alice = new player("Alice Adams"  , 0);
    player* brett = new player("Brett Booth"  , 2);
    player* cecil = new player("Cecil Cinder" , 1);

    // create team
    team team_1("The Dragons");

    // assign players to teams, set Brett as the captain
    //team_1.add_player(alice , 0);
    //team_1.add_player(brett , 1);
    team_1.add_player(cecil , 0);

    // play five turns
    for (int i = 0 ; i<5 ; i++)
        team_1.play_turn();
    
    // display total result
    cout << team_1.get_name() << " scored " << team_1.get_score() << endl;
    
    // destroy the players!
    delete alice;
    delete brett;
    delete cecil;
    
    cout << endl;
}

// Play a sample game
void test_case_3(){

    cout << "********** Test Case 3 **********" << endl;

    // step 1 create players
    // this time I'll use a loop to make it easier. We'll make 20 players.
    // to make things easier we'll assign them all the same ability level
    player* player_list[20];
    for (int i = 0 ; i<20 ; i++)
        player_list[i] = new player("Generic Name" , 2);
    
    // step 2 create teams
    team team_1("The Dragons");
    team team_2("The Knights");


    // step 3 pick teams (the draft)
    team_1.add_player(player_list[0] , 1);     // team 1 gets a captain
    for (int i = 1 ; i < 10 ; i++)
        team_1.add_player(player_list[i],0);   // team 1 gets nine normal players

    team_2.add_player(player_list[10] , 1);    // team 2 gets a captain
    for (int i = 11 ; i < 20 ; i++)
        team_2.add_player(player_list[i],0);   // team 2 gets nine normal players

    // step 4 - play the game! 5 rounds:
    for (int i = 0 ; i < 5 ; i++){
        team_1.play_turn();
        team_2.play_turn();
    }

    // step 5 - pick the winner
    cout << team_1.get_name() << " scored " << team_1.get_score() << endl;
    cout << team_2.get_name() << " scored " << team_2.get_score() << endl;
    if (team_1.get_score() > team_2.get_score() )
        cout << team_1.get_name() << " win!" << endl;
    else if (team_2.get_score() > team_1.get_score() )
        cout << team_2.get_name() << " win!" << endl;
    else
        cout << "its a tie!" << endl;

    cout << endl;

     for (int i = 0 ; i<20 ; i++)
        delete player_list[i];

}
