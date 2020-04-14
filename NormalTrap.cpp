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

bool NormalTrap::trapPop(int x , int playerNum ){
	// check if all tokens are past this letter.
	// get sum of all tokens_past of this letter.

    if( x < (4*playerNum - currTokens.size())){return false;}
	else{return true;}
}