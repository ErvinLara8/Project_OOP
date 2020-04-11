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
	stack<Token> currTokens;

	char alphabet;

	int score;

public:

	// constructor 
	Square(int x, int y);

	// display method that can be overwritten 
	virtual void display();

	virtual Token popToken();

	int getSize();

	Token getTopToken();

	void pushToken(Token t);

	void showTokens();

	bool isEmpty();

	virtual bool isTrap() = 0;

};

#endif

