
#include "GameTable.h"
#include "Game.h"

// constructor that initializes the game table id and the game 
GameTable::GameTable(int id) {
	
	gameTableNum = id;
	//ourGame.show();
    //ourGame.setInitialPos();
    //ourGame.showProgress();
}

// method that sets the new set of players 
void GameTable::setNumPlayers(int x) {
    numPlayers = x;

    // setting the players in the game 
    ourGame.setPlayers(numPlayers);
    }

// playing the game 
void GameTable::tablePlay(){
	ourGame.playGame();
}

// resetting the game 
void GameTable::resetTable(){
	ourGame.resetTable();
}

// getting num of current players 
int GameTable::getNumOfPlayers(){
    return numPlayers;
}

// setting the initial positions of the tokens 
void GameTable::setTokens(){
    ourGame.setInitialPos();
}

// getting winning color 
string GameTable::getWinningColor(){
    return ourGame.getWinningPlayerColor();
}

// getting id 
int GameTable::getId(){
    return gameTableNum;
}