#ifndef TIMINGWHEEL_H
#define TIMINGWHEEL_H

#include "GameTable.h"
#include <vector>

class TimingWheel {

	private:
		vector <GameTable*> TW [7];// Timing Wheel with Circular Queue behavior. 
        int curr_slot; //current time 

	public:
		TimingWheel();

        void insert(int play_time, GameTable *p1);

		void schedule();

        void clear_curr_slot();

        void incrementTime();

};

#endif