#ifndef TRAP_H
#define TRAP_H

#include "Square.h"
#include <string>


class Trap : public Square {

private:

// name of trap 
const string NAME = "Tr";
bool trapped = false;

public:

	Trap(int x = 0, int y = 0);

	// polymorphic method to display
	virtual void display();

	// method to check if it is trap 
	virtual bool isTrap();

	// method to push token
	virtual void pushToken(Token & t);

	// method to check is if we can pop the token 
	virtual bool trapPop(int x = 0, int playerNum = 0);

};

#endif