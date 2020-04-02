#ifndef TRAP_H
#define TRAP_H

#include "Square.h"
#include <string>


class Trap : public Square {

private:

string name;

public:

	Trap(int x = 0, int y = 0 , string name = "");

	virtual void display();

	virtual void hole();

};

#endif