#ifndef NORMALTRAP_H
#define NORMALTRAP_H

#include "Trap.h"
#include <string>

class NormalTrap : public Trap {

private:

// Fuctionalitie and variables are still to detemrine

// label of trap
string label; 

public:

    // constructor
	NormalTrap(int x = 0, int y = 0 , string lb = "");

    // polymorphic method to display
	virtual void display();

    virtual bool trapPop(int x = 0, int playerNum = 0);

};

#endif