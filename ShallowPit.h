#ifndef SHALLOWPIT_H
#define SHALLOWPIT_H

#include "Trap.h"
#include <string>

class ShallowPit : public Trap {

private:

// Fuctionalitie and variables are still to detemrine
string label;

public:

    //constructor 
	ShallowPit(int x = 0, int y = 0 , string lb = "");

    // polymorphic method to display
	virtual void display();

};

#endif