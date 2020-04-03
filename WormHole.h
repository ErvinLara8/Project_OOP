#ifndef WORMHOLE_H
#define WORMHOLE_H

#include "Trap.h"
#include <string>

class WormHole : public Trap {

private:

// Fuctionalitie and variables are still to detemrine

// label of worm hole
string label;

public:

    // constructor 
	WormHole(int x = 0, int y = 0 , string label = "");

    // polymorphic method to display
	virtual void display();

};

#endif