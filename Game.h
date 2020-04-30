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

	// number of players and an array to determine which player they are (as in first player is in )
	int nPlayers;

	// queue that determines which players turn it is. 
	queue<Player> playerTurns; 

	// rannking of players 
	vector<Player > ranking;

	Player winner;

	// arrays that will hold the coordinates of the traps 
	int trap_x_coordinate [6] = {-1,-1,-1,-1,-1,-1};
	int trap_y_coordinate [6] = {-1,-1,-1,-1,-1,-1};

	bool gameWon;

public:

	// main class constructor 
	Game();

	// class destructor 
	~Game();

	// method used to created the trap coordinates 
	void createTrapCourdinates();

	// method to display the game 
	void show();

	// method that will make the players place the initial hogs
	void setInitialPos();

	// method to show how the pieces are moving 
	void showProgress();

	// method to play the game 
	void playGame(); 

	// method used by sort algorithm to sort the ranks
	static bool sortRanks( Player & left, Player & right );

	// method used to update the ranks 
	void setRanks();

	// method to update the players scores 
	void updatePlayerScores(int ln);

	void setPlayers(int numOfPlayers);

	// method to seter the items and players in a table
	void resetTable();

	string getWinningPlayerColor();

	Game operator=(Game &);

};

#endif
