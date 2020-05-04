#include "TimingWheel.h"
#include "GameTable.h"
#include <unordered_map> 
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h> 
#include <algorithm>    // std::random_shuffle
#include <chrono>       // std::chrono::system_clock
#include <random>       // std::default_random_engine

using namespace std;

// constructor 
TimingWheel::TimingWheel() {

    // setting initila values to the variables 
    curr_slot = 0;
    totalPlayers = 0;
    totalGames = 0;

    stats["Red"] =  0;
    stats["Green"] =  0;
    stats["Blue"] =  0;
    stats["Purple"] =  0;
    stats["Yellow"] =  0;
    stats["White"] =  0;

    finishingGamesStats = "";

    for (int i=2; i<7; ++i) ranNumbers.push_back(i);

}

// method to insert a GameTable in a specific slot in the timing wheel 
void TimingWheel::insert(int play_time, GameTable *p1) { 
    TW[play_time].push_back(p1);
}

// method that takes all the games in a current slot, updates the stats, and then generates new games and puts them in their respected slot 
void TimingWheel::schedule() {

    srand(time(NULL));

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    auto rng = std::default_random_engine (seed);

    // hold the time slot relevant to the current time slot 
    int updatedTimeSlot = 0;

    // reseting the finishing stats string 
    finishingGamesStats = "";

    // random number of players generated 
    int commingPlayers = 0;

    // id of gametable that will rotate 
    int currentID = 0;

    // winning color 
    string winningColor;

    // GameTable pointer that will rotate 
    GameTable * currentGame; 


    for(int i = 0; i < TW[curr_slot].size(); i++){

        // getting the game 
        currentGame = TW[curr_slot][i];

        // setting the initial positions of the tokens
        currentGame->setTokens();

        // playing the game 
        currentGame->tablePlay();



        // at this point i have a game played

        // updating # of games played 
        totalGames++;

        // updating winning stats
        winningColor = currentGame->getWinningColor();
        stats[winningColor] = stats[winningColor] +1;

        // prinitng out the wtable and the winning color 
        currentID = currentGame->getId();
        finishingGamesStats = finishingGamesStats + "Game Table " + to_string(currentID) + " (" + winningColor + ")       ";

        // reducing the numer of players 
        totalPlayers -= currentGame->getNumOfPlayers();

        // resetting the games
        currentGame->resetTable();


        // creatign new game 

        shuffle (ranNumbers.begin(), ranNumbers.end(), rng);

        // creating new number of players 
        commingPlayers = ranNumbers[0];

        // updating the spot where the Gametable will go based on the new number of players 
        updatedTimeSlot = (curr_slot + commingPlayers) % 6;

        // seetin the new number of player 
        currentGame->setNumPlayers(commingPlayers);
        totalPlayers += commingPlayers;

        // insertign the new game in a designated time slot 
        insert(updatedTimeSlot, currentGame);
    }

}

// method to clear the slots in the current time of the timing wheel 
void TimingWheel::clear_curr_slot() { 
    while (!TW[curr_slot].empty())
    {
       TW[curr_slot].pop_back();
    }
}

// method to update the initial number of player in the arcade 
void TimingWheel::updateInitialPlayers(int x){
    totalPlayers += x;
}

// getting string of games that finished 
string TimingWheel::getFinishingGames(){
    return finishingGamesStats;
}

// method to get the total players 
int TimingWheel::getTotalPlayers(){
    return totalPlayers;
}

// metho to get the total games 
int TimingWheel::getTotalGames(){
    return totalGames;
}

// method to get the winning stats 
unordered_map<string, int> TimingWheel::getWinStats(){
    return stats;
}

// method to update the current slot 
void TimingWheel::setCurrSlot(int x){
    curr_slot = x;
}