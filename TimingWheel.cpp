#include "TimingWheel.h"
#include "GameTable.h"
#include <vector>
using namespace std;


TimingWheel::TimingWheel() {
    curr_slot = 0; 
}

void TimingWheel::insert(int play_time, GameTable *p1) { 

    TW[play_time].push_back(p1);
	
}

void TimingWheel::schedule() {

}

void TimingWheel::clear_curr_slot() { 

    while (!TW[curr_slot].empty())
    {
       TW[curr_slot].pop_back();
    }

}


/*
	for(vector<vector<GameTable>>::iterator it = TW.begin(); it != TW.end(); it++){

		for (vector<GameTable>::iterator itt = TW.begin(); itt != TW.end(); itt++) {



		}
    }
*/