#include "ShallowPit.h"
#include <iostream>

using namespace std;

//constructor
ShallowPit::ShallowPit(int x, int y, string lb) : Trap(x,y){
    label = lb;
}

// overloaded display that also displays the label of the trap 
void ShallowPit::display(){

    cout << '(' << label << ')'; 
    Trap::display();
}