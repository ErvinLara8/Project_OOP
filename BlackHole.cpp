#include "BlackHole.h"
#include <iostream>

using namespace std;

// constructor 
BlackHole::BlackHole(int x, int y, string lb): Trap(x,y){
    label = lb;
}

// overloaded display that also displays the label of the trap 
void BlackHole::display(){

    cout << '(' << label << ')'; 
    Trap::display();

}