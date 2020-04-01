#include "Game.h"
#include "Square.h"
#include "GoodSquare.h"
#include "Obstacle.h"
#include <iostream>

using namespace std;

Game::Game(int n ,int gameid) {

	id_of_game = gameid;

	nPlayers = n;
	// First, create the instances of players
	for (int i = 0; i < nPlayers; i++) {

		Player p(); // always 4 tokens each player
	}

	// creating the board
	board = new Square *[9];

	for(int i = 0; i < 9; i++){
		board[i] = new Square[6];
	}

	// assigning the courdinates to the board
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 6; j++){
			board[i][j] = GoodSquare(i,j, "GoodSqr");
		}
	}
}

void Game::show(){

	char alphabet; 
	for(int i = 0 ; i < 10 ; i++){

	// choosing the char that belong to the x axis 
		switch(i){
			case 1: alphabet = 'a';
			case 2: alphabet = 'b';
			case 3: alphabet = 'c';
			case 4: alphabet = 'd';
			case 5: alphabet = 'e';
			case 6: alphabet = 'f';
			case 7: alphabet = 'g';
			case 8: alphabet = 'h';
			case 9: alphabet = 'i';
		}

		for(int j = 0; j < 7 ; j++){
			
			if(i == 0 && j == 0){
				cout << "\n"; 
			}else if(i == 0){
				cout << j << "\n";
			}else if(j == 0){
				cout << alphabet << "\n";
			}else{
				board[i-1][j-1].display();
				cout << endl; 
			}
		}
	}

	// for testing purposes

	for(int i = 0; i < 6; i++){
		delete []board[i];
	}
	delete []board;
}

Game::~Game(){
	for(int i = 0; i < 6; i++){
		delete []board[i];
	}
	delete []board;
}
