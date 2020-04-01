// Good Saure is just like swaure but has the attribute of the name 

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Square.h"
#include <string>

class GoodSquare : public Square {

private:

// Variables 
string name; 

public:

	GoodSquare(int x, int y, string name);
	virtual void display();

};

#endif
