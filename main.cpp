#include <iostream>
#include "Game.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include "TimingWheel.h"
#include "GameTable.h"
#include "Arcade.h"
#include <fstream>

using namespace std;

int main(){

    // int numOfPlayers = 3;

    // // cout << "Enter Number of Players: ";

    // // while (true)
    // // {
    // //     cin >> numOfPlayers;

    // //     if(numOfPlayers >1 || numOfPlayers < 7){
    // //         break;
    // //     }else{
    // //         cout << "Please enter a number between 2 and 6: ";
    // //     }
    // // }
    
    // Game game1;

    // game1.setPlayers(numOfPlayers);

    // game1.show();

    // game1.setInitialPos();

    // game1.showProgress();

    // game1.playGame();

    // GameTable * game1 = new GameTable(1);

    // game1->setNumPlayers(2);

    // GameTable * game2 = new GameTable(2);

    // game2->setNumPlayers(4);

    // GameTable * game3 = new GameTable(3);

    // game3->setNumPlayers(3);

    //  GameTable * game4 = new GameTable(4);

    // game4->setNumPlayers(6);

    // TimingWheel Tw;

    // Tw.insert(2,game1);
    // Tw.insert(4,game2);
    // Tw.insert(3,game3);
    // Tw.insert(6,game4);


    // int timeSlot = 0;

    // while (timeSlot < 30)
    // {
    //    Tw.schedule();
    //    cout << timeSlot << endl;
    //    cout << "Finishing Games: " << Tw.getFinishingGames() << endl << endl;

    //    timeSlot ++;
    // }

    // delete game1;
    // delete game2;
    // delete game3;
    // delete game4;

	int end_of_simulation_time = 10;

    // cout << "Enter Total length of time: ";

    // cin >> end_of_simulation_time;

    ofstream outputFile;

	Arcade arcade1(outputFile);

    arcade1.Initialize(end_of_simulation_time);

    arcade1.runArcade();

    arcade1.~Arcade();
}