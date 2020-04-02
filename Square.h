#ifndef SQUARE_H
#define SQUARE_H

#include "Token.h"

#include <string>
#include <stack> 

class Square {

private:

	int x_location;

	int y_location;

	string name;

	stack<Token> currTokens;

public:

	Square(int x, int y);

	virtual void display();

};

#endif

