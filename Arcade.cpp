#include "Arcade.h"
#include "TimingWheel.h"
#include "GameTable.h"
#include <unordered_map> 
#include <fstream>
#include <stdlib.h> 
#include <iostream>

using namespace std;

// constructor 
Arcade::Arcade(ofstream& x):output(x){}

// methld to initialize the arcade
void Arcade::Initialize(int t){

    // openig output file 
	output.open("stats.txt");

    // setting the max time to be whatever the user whants 
	end_of_simulation_time = t;

    // simulation begins at time zero 
	simulation_time = 0;

    // current slot is also zero 
	curr_time_slot = 0;

    // maxSlot is six cause six is the maximum number of player 
    maxSlots = 6;

    // initializing the timing wheel 
	TW = new TimingWheel();

    // initilizing the Game tables 
	gt1 = new GameTable(1);
	gt2 = new GameTable(2);
	gt3 = new GameTable(3);
	gt4 = new GameTable(4);
	gt5 = new GameTable(5);
	gt6 = new GameTable(6);

    // int that will hold the random number of players generated 
    int numOfPlayers = 0;

    srand(time(NULL));

    // loop that sets the umber of people in each game table 
    for(int i = 0; i < 6 ; i++){
        
        // picking a random number between 2 and 6
        numOfPlayers = (rand() % 4)+2;

        // initilaizing each game table to their appropriate number of people and putting it in the timing wheel 
        if(i == 0){
            gt1->setNumPlayers(numOfPlayers);
            TW->updateInitialPlayers(numOfPlayers);
            TW->insert(numOfPlayers, gt1);
        }else if(i == 1){
            gt2->setNumPlayers(numOfPlayers);
            TW->updateInitialPlayers(numOfPlayers);
            TW->insert(numOfPlayers, gt2);
        }else if(i ==2){
            gt3->setNumPlayers(numOfPlayers);
            TW->updateInitialPlayers(numOfPlayers);
            TW->insert(numOfPlayers, gt3);
        }else if(i == 3){
            gt4->setNumPlayers(numOfPlayers);
            TW->updateInitialPlayers(numOfPlayers);
            TW->insert(numOfPlayers, gt4);
        }else if(i == 4){
            gt5->setNumPlayers(numOfPlayers);
            TW->updateInitialPlayers(numOfPlayers);
            TW->insert(numOfPlayers, gt5);
        }else{
            gt6->setNumPlayers(numOfPlayers);
            TW->updateInitialPlayers(numOfPlayers);
            TW->insert(numOfPlayers, gt6);
        }
    }
}

// method that will print the stats fo the current game 
void Arcade::print_status() {
    cout << endl;
    output << endl;
    
    // printing number of tables 
	cout << "Number of Game Tables: 6" << endl;
    output << "Number of Game Tables: 6" << endl;

    // printing the current number of players in the arcade 
	cout << "Number of Players: " << TW->getTotalPlayers() << endl;
    output << "Number of Players: " << TW->getTotalPlayers() << endl;

    // printing the total number of games that have been played 
	cout << "Number of Games: " << TW->getTotalGames() << endl;
    output << "Number of Games: " << TW->getTotalGames() << endl;

    // prinintg if there were any winners in the current time 
    cout << "Current Game Winners: " << TW->getFinishingGames() << endl;
    output << "Current Game Winners: " << TW->getFinishingGames() << endl;

    // getting the map of the color wins 
	unordered_map<string, int> stats = TW->getWinStats();

	//print hashmap
	cout << "Winning Results:" << endl;
	for (auto x : stats) {
        cout << x.first << " " << x.second << endl;
        output << x.first << " " << x.second << endl;        
        }

    cout << endl;
    output << endl;

}

// method that begins the loop the runs the arcade 
void Arcade::runArcade() {

    // initial timeslot is zero 
    int time_slot =0; 

	while(simulation_time <= end_of_simulation_time)  {

        // prinitng current time 
        cout << "Current Time: " << simulation_time << endl;
        output << "Current Time: " << simulation_time << endl;

        // setting the time slot 
        TW->setCurrSlot(time_slot);

        // printing 
		print_status();

        // scheduling 
		TW->schedule();

        // clearing the current time slot 
		TW->clear_curr_slot();

        // getting the nect time slot 
		time_slot = (time_slot+1) % maxSlots;

        // incrementing the time 
        simulation_time++;

    }

    // closing the output file 
    output.close();

}

// destructor 
Arcade::~Arcade(){
    delete TW;
    delete gt1;
    delete gt2;
    delete gt3;
    delete gt4;
    delete gt5;
    delete gt6;
}