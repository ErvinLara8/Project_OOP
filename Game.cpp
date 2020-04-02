#include "Square.h"
#include "GoodSquare.h"
#include "Trap.h"
#include <iostream>
#include "Game.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <algorithm>       

using namespace std;

Game::Game(int nPlayers ,int gameid) {

	id_of_game = gameid;

	nPlayers = nPlayers;
	// First, create the instances of players
	for (int i = 0; i < nPlayers; i++) {

		Player p(); // always 4 tokens each player
	}


	// creating the board
	board = new Square **[9];

	for(int i = 0; i < 9; i++){
		board[i] = new Square*[6];
	}

	// calling to create the trap courdinates
	createTrapCourdinates();

	// assigning the courdinates to the board
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 6; j++){
			//creates an obstacle square at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)
			if(i == trap_x_coordinate[0] && j == trap_y_coordinate[0]){
				board[i][j] = new Trap(i,j, "t");
			}else if(i == trap_x_coordinate[1] && j == trap_y_coordinate[1]){
				board[i][j] = new Trap(i,j, "t");
			}else if(i == trap_x_coordinate[2] && j == trap_y_coordinate[2]){
				board[i][j] = new Trap(i,j, "t");
			}else if(i == trap_x_coordinate[3] && j == trap_y_coordinate[3]){
				board[i][j] = new Trap(i,j, "t");
			}else if(i == trap_x_coordinate[4] && j == trap_y_coordinate[4]){
				board[i][j] = new Trap(i,j, "t");
			}else if(i == trap_x_coordinate[5] && j == trap_y_coordinate[5]){
				board[i][j] = new Trap(i,j, "t");
			}else{
				board[i][j] = new GoodSquare(i, j, "g"); 
			}
		}
	}
}

void Game::show(){

	char alphabet; 
	for(int i = 0 ; i < 7 ; i++){

		for(int j = 0; j < 10 ; j++) {

				// choosing the char that belong to the x axis 
		switch(j){
			case 1: alphabet = 'S';
					break;
			case 2: alphabet = 'A';
					break;
			case 3: alphabet = 'B';
					break;
			case 4: alphabet = 'C';
					break;
			case 5: alphabet = 'D';
					break;
			case 6: alphabet = 'E';
					break;
			case 7: alphabet = 'F';
					break;
			case 8: alphabet = 'G';
					break;
			case 9: alphabet = 'Z';
					break;
		}
			
			if(i == 0 && j == 0){
				cout << "  "; 
			}else if(j == 0){
				cout << (i-1) << "  ";
			}else if(i == 0){
				cout << "  "<<alphabet << "  ";
			}else{
				board[j-1][i-1]->display(); 			
			}
		}
		cout << "\n" << endl;
	}

	// for testing purposes

	for(int i = 0; i < 6; i++){
		delete []board[i];
	}
	delete []board;
}


// method that creates the trap courdinates
void Game::createTrapCourdinates(){

// this makes sure we generate random number in different sequences each time we re-run the program
	srand(time(NULL));

// variable random holds the random number and position the current position
	int random;
	int position = 0; 

// loop that inserts the random sequence from 2 to 7 in the x courdinate 
	while(position < 6){

		random = (rand() % 6) + 2;

		// if the random number is not in the array put it there
		if( find( begin(trap_x_coordinate), end(trap_x_coordinate), random) == end(trap_x_coordinate) ){
			trap_x_coordinate[position] = random;

			// increment position
			position++;

		// else random number is already there so we loop again to gain new random number 
		}else{
			continue;
		}
	}

	//resseting possition to 0
	position = 0;

	// loop that inserts the random sequence from 0 to 5 in the y courdinate 
	while(position < 6){

		random = (rand() % 6);

		if( find(begin(trap_y_coordinate), end(trap_y_coordinate), random) == end(trap_y_coordinate)){
			trap_y_coordinate[position] = random;
			position++;
		}else{
			continue;
		}
	}

}

Game::~Game(){
	for(int i = 0; i < 6; i++){
		delete []board[i];
	}
	delete []board;
}