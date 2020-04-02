#ifndef GOODSQUARE_H
#define GOODSQUARE_H

#include "Square.h"
#include <string>

class GoodSquare : public Square {

private:

// Variables 
string name; 

public:

	GoodSquare(int x = 0, int y=0, string n="");
	virtual void display();

};

#endif