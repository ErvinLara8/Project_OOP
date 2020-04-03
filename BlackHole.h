#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include "Trap.h"
#include <string>

class BlackHole : public Trap {

private:

// Fuctionalitie and variables are still to detemrine

// label of type of trap
string label; 

public:

    // constructor 
	BlackHole(int x = 0, int y = 0 , string lb = "");

    // polymorphic method to display
	virtual void display();

};

#endif