#include "WormHole.h"
#include <iostream>

using namespace std;

// constructor 
WormHole::WormHole(int x, int y, string lb):Trap(x,y){

    label = lb;

}

// overloaded display that also displays the label of the trap 
void WormHole::display(){

    cout << '(' << label << ')'; 

    Trap::display();

}