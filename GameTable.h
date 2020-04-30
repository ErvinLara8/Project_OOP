#ifndef GAMETABLE_H
#define GAMETABLE_H

#include "Game.h"

// GameTable class that is sort of a wrapper around Game class 
class GameTable{

    private:

        // our game 
        Game ourGame;

        // current number of players in this game table 
        int numPlayers;
        
        // number of game table 
        int gameTableNum;

    public:

        // constructor 
        GameTable(int id);

        // set number of players 
        void setNumPlayers(int x);

        // method that starts a game to be played 
        void tablePlay();

        // getting number of players 
        int getNumOfPlayers();

		void resetTable(); // deletes players from previous game

        // getting the color of the winnig player 
        string getWinningColor();

        // method for the players to set their initial tokens 
        void setTokens();

        // getting table number 
        int getId();

};

#endif