#ifndef GAME_H
#define GAME_H

#include <string>
#include <stack> 
#include <vector>
#include "Player.h"   
#include "Square.h"


using namespace std;

class Game {

private:

	Square *** board;
	int id_of_game;
	int nPlayers;
	vector<Player> Ranking;

	// arrays that will hold the courdinates of the traps 
	int trap_x_coordinate [6] = {-1,-1,-1,-1,-1,-1};
	int trap_y_coordinate [6] = {-1,-1,-1,-1,-1,-1};

public:

	Game(int nPlayers, int idGame);
	~Game();

	void createTrapCourdinates();
	virtual void show();

};

#endif

