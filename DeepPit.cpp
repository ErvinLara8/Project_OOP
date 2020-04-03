#include "DeepPit.h"
#include <iostream>

using namespace std;

// constructor 
DeepPit::DeepPit(int x, int y, string lb): Trap(x,y){
    label = lb;
}

// overloaded display that also displays the label of the trap 
void DeepPit::display(){

    cout << '(' << label << ')'; 
    Trap::display();
}