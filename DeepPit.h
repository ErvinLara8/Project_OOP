#ifndef DEEPPIT_H
#define DEEPPIT_H

#include "Trap.h"
#include <string>

class DeepPit : public Trap {

private:

// Fuctionalitie and variables are still to detemrine
string label;

public:

    //contructor
	DeepPit(int x = 0, int y = 0 , string lb = "");

    // polymorphic method to display
	virtual void display();

    // overwritten pop method
    virtual Token popToken();

    // overwritten trap pop 
    virtual bool trapPop(int x , int playerNum );

    // overwritten verticalPop
    virtual Token verticalPop();

};

#endif