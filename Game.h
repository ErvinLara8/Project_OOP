#ifndef GAME_H
#define GAME_H

#include <string>
#include <stack> 
#include <vector>
#include "../../../../../Documents/GitHub/Project_OOP/Headers/Player.h"   // DONT KNOW WHY IT FORCED ME TO INCLUDE THIS WAY.
#include "../../../../../Documents/GitHub/Project_OOP/Headers/Square.h"


using namespace std;

class Game {

private:

	Square board[9][6];
	int id;
	int nPlayers;
	vector<Player> Ranking;

public:

	Game(int nPlayers);

	virtual void show();

};

#endif

