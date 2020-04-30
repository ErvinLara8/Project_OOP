#ifndef ARCADE_H
#define ARCADE_H

#include "GameTable.h"
#include "TimingWheel.h"

// arcade class
class Arcade {

	private:
        // output file were going to write in 
        ofstream& output;

        // timing wheel 
		TimingWheel * TW;

        // all the Game Tables 
		GameTable * gt1;
		GameTable * gt2;
		GameTable * gt3;
		GameTable * gt4;
		GameTable * gt5;
		GameTable * gt6;

        // all the simulation times 
		int end_of_simulation_time;
		int simulation_time;
		int curr_time_slot;
        int maxSlots;


	public:

        // constructor 
		Arcade(ofstream& x);

        // methdod to initialize the arcade
		void Initialize(int time);

        // method to print current status 
		void print_status();

        // method to begin the loop that will run the arcade 
		void runArcade();

        // destructor 
        ~Arcade();
};

#endif