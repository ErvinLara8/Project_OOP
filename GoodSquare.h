#ifndef GOODSQUARE_H
#define GOODSQUARE_H

#include "Square.h"
#include <string>

// inherates square
class GoodSquare : public Square {

private:

// name of square
string name;

public:

	//constructor 
	GoodSquare(int x = 0, int y=0, string n="");

	// overwritten display method 
	virtual void display();

	// just returns boolean - to tell type 
	virtual bool isTrap();

};

#endif