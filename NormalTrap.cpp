#include "NormalTrap.h"
#include <iostream>

using namespace std;

// constructor 
NormalTrap::NormalTrap(int x, int y, string lb): Trap(x,y){

    label = lb;

}

// overloaded display that also displays the label of the trap 
void NormalTrap::display(){


    cout << '(' << label << ')'; 
    Trap::display();

}