#ifndef TIMINGWHEEL_H
#define TIMINGWHEEL_H

#include "GameTable.h"
#include <vector>
#include <unordered_map> 
#include <string>

using namespace std; 

class TimingWheel {

	private:
		vector <GameTable*> TW [7];// Timing Wheel with Circular Queue behavior. 
        int curr_slot; //current time
		int totalPlayers; // Total Number of Players in the Arcade
		int totalGames; // Total Number of Games Played
		unordered_map<string, int> stats; // (key,value) -> (color, wins)
		string finishingGamesStats; //string thaty hold the current winners

		vector <int> ranNumbers;


	public:
		// constructor 
		TimingWheel();

		// method to insert a GameTable pointer in a certain slot 
        void insert(int play_time, GameTable *p1);

		// method to playe the current 
		void schedule();

		// methdo to clear the current slots in the current time 
        void clear_curr_slot();

		// methdo to set the number of initial players in the arcade to update them as the come and go 
		void updateInitialPlayers(int x);

		// method to get the string of the finishing games 
		string getFinishingGames();

		// method to get the total players in arcade
		int getTotalPlayers();

		// methdo to get the total games played 
		int getTotalGames();

		// map that hold the wins for each color 
		unordered_map<string, int> getWinStats();

		// method that updates the current slot time 
		void setCurrSlot(int x);

		
};

#endif