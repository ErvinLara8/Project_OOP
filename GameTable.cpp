
#include "GameTable.h"
#include "Game.h"

GameTable::GameTable(int id) {
	
	gameTableNum = id;
	//ourGame.show();
    ourGame.setInitialPos();
    //ourGame.showProgress();
}

void GameTable::setNumPlayers(int x) {
    numPlayers = x;
    ourGame.setPlayers(numPlayers);
    }

void GameTable::tablePlay(){

	cout << "Enter Number of Players: ";

    while (true)
    {
        cin >> numPlayers;

        if(numPlayers >1 || numPlayers < 7){
            break;
        }else{
            cout << "Please enter a number between 2 and 6: ";
        }
    }

	ourGame.playGame();

}

void GameTable::resetTable(){

	ourGame.resetTable();
}