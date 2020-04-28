#ifndef SQUARE_H
#define SQUARE_H

#include "Token.h"

#include <string>
#include <stack> 

// main square class
class Square {

protected:
	// x location 
	int x_location;

	// y location
	int y_location;

	// stack of tokens in location
	stack<Token > currTokens;

	int tokens_past;

	char alphabet;

	int score;

public:

	// constructor 
	Square(int x, int y);

	// display method that can be overwritten 
	virtual void display();

	// method to pop token and increment tokens passed 
	virtual Token popToken();

	// method to pop token and not increment tokens passed 
	virtual Token verticalPop();

	// method to get sthe size of the stack ing the square
	int getSize();

	// metho to get tokens passed 
	int getTokensPast();

	// method to acess top token 
	Token getTopToken();

	// method to get top color 
	string getTopColor();

	// methdo to push token 
	virtual void pushToken(Token & t);

	// method to show tokens in the squre 
	void showTokens();

	// method to check is square is empty 
	bool isEmpty();

	// method to check if square is a trap
	virtual bool isTrap() = 0;

	void deleteTokens();

	stack<Token> getAllTokens();

};

#endif

