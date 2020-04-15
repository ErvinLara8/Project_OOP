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
	
	// overloading equals operator
	Player operator=( Player &);

	// method to access the total score of the player
	int getTotalScore();

	// method to update the scores of the player based on their 
	void updateScore();

	// method to update the value of a token 
	void updateToken(Token & t);

	// method to move tokens 
	bool moveToken(Square *** & board, int ln, int playerNum);

	// method to cehck if i can move a token from the bottom lane or the top lane of the moving lane 
	bool checkingTopBottom(Square *** & board, int ln, int playerNum);

	// method that could move my opponents token 
	bool moveOpponentsToken(Square *** & board, int ln, int playerNum);

	// method to check trap type 
	bool checkTrapType(Square *** & board, int ln, int x, int playerNum);
};

#endif