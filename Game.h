#ifndef GAME_H
#define GAME_H

#include <string>
#include <stack> 
#include <vector>
#include "Player.h"   
#include "Square.h"
#include <queue>


using namespace std;

class Game {

private:

	//board class that will be the game board 
	Square *** board;

	// id of unique game 
	int id_of_game;

	// number of players and an array to determine which player they are (as in first player is in )
	int nPlayers;

	// queue that determines which players turn it is. 
	queue<Player> playerTurns; 

	// rannking of players 
	vector<Player> Ranking;

	// arrays that will hold the courdinates of the traps 
	int trap_x_coordinate [6] = {-1,-1,-1,-1,-1,-1};
	int trap_y_coordinate [6] = {-1,-1,-1,-1,-1,-1};

public:

	// main class constructor 
	Game(int nPlayers, int idGame);

	// class destructor 
	~Game();

	// method used to created the trap courdinates 
	void createTrapCourdinates();

	// method to display the game 
	void show();

};

#endif

