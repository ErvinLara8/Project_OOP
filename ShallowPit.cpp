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

// overloaded trapPop method that checks if we can pop a token 
bool ShallowPit::trapPop(int x , int playerNum ){

    if(currTokens.size() > 1){
        return true;
    }else{
        if( x < (4*playerNum - currTokens.size())){return false;}
	    else{return true;}
    }
}