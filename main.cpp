#include <iostream>
#include "Game.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>

using namespace std;

int main(){

    int numOfPlayers = 0;

    cout << "Enter Number of Players: ";

    while (true)
    {
        cin >> numOfPlayers;

        if(numOfPlayers >1 || numOfPlayers < 7){
            break;
        }else{
            cout << "Please enter a number between 2 and 6: ";
        }
    }
    
    Game game1(numOfPlayers, 123);

    game1.show();

    game1.setInitialPos();

    game1.showProgress();

    game1.playGame();
}