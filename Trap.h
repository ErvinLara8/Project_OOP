#ifndef TRAP_H
#define TRAP_H

#include "Square.h"
#include <string>


class Trap : public Square {

private:

// name of trap 
const string NAME = "Tr";

public:

	Trap(int x = 0, int y = 0);

	// polymorphic method to display
	virtual void display();

	//virtual void hole();

	virtual bool isTrap();

};

#endif