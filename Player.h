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

	int totalScore;

public:

	//constructor 
	Player(int pN= 0, string col = "Blank");

	// display method 
	void display();

	// gets initial possition where player places token 
	int placeHog( bool * avaliablePos);

	// get a certain token based on the tokens number 
	Token & getToken(int x);

	// get players color 
	string getColor();

	// get players number
	int getPlayerNum();

	bool checkingTopBottom(Square *** & board, int ln);

	// overloading equals operator
	Player operator=( Player &);

	int getTotalScore();

	void updateScore();

	void updateToken(Token t);

	bool moveToken(Square *** & board, int ln, int playerNum);

	bool moveOpponentsToken(Square *** & board, int ln);

	bool checkTrapType(Square *** & board, int ln, int x, int playerNum);

};

#endif