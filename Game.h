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

	Square **board;
	int id_of_game;
	int nPlayers;
	vector<Player> Ranking;

public:

	Game(int nPlayers, int gameid);
	~Game();
	void show();

};

#endif

