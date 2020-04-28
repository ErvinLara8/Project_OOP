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

bool WormHole::trapPop(int x, int playerNum ){
	return true;
}

// Worm Hole pop that bring a token to the begining 
bool WormHole::wormHoleMove(Square *** & board,  int x, int y, string color){

	srand(time(NULL));

	Token dummyToken = board[x][y]->popToken();

	int random = (rand() % 6);

	board[0][random]->pushToken(dummyToken);

	if(dummyToken.getColor() == color){
		return true;
	}else{
		return false;
	}
}
