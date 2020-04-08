#ifndef PLAYER_H
#define PLAYER_H

#include "Token.h"
#include <vector>
#include <string>
#include "Square.h"

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
	Player(int pN = 0, string col = "Blank");

	Player(const Player &);

	// display method 
	void display();

	// gets initial possition where player places token 
	int placeHog( Square *** & board);

	Token getToken(int x);

	vector<Token> getAllTokens();

	string getColor();

	int getPlayerNum();

	Player operator=(const Player &);

};

#endif