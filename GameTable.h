#ifndef GAMETABLE_H
#define GAMETABLE_H

#include "Game.h"

class GameTable{

    private:

        Game ourGame;

        int numPlayers;

        int gameTableNum;

    public:

        GameTable(int id);

        void setNumPlayers(int x);

        void tablePlay();

		void resetTable(); // deletes players from previous game

};

#endif