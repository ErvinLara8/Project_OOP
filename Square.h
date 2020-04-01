#ifndef SQUARE_H
#define SQUARE_H

#include "Token.h"

#include <string>
#include <stack> 

class Square {

private:

// Class Variables
	int x_location;

	int y_location;

	stack<Token> currTokens;
	
public:



// Constructor
	Square(int x=0, int y=0);

// Virtual display
	virtual void display();

};

#endif

