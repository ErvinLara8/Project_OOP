#ifndef PLAYER_H
#define PLAYER_H

#include "Token.h"
#include <vector>
#include <string>

using namespace std;

class Player {

private:

	// constant of 4 tokens
	const int NUM_OF_TOKENS = 4;

	// the tokens of the players
	vector<Token> tokens;
	
	// the color of the player 
	string color;

	// the number of the player
	int playerNum;

public:

	//constructor 
	Player(int pN = 0);

	// display method 
	void display();

};

#endif