
#include "Player.h"
#include <string>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <iterator>


using namespace std;

// constructor of the Player
Player::Player(int pN, string col) {
	playerNum = pN;
	color = col;

	for(int i = 0; i < NUM_OF_TOKENS; i++){
		Token headHog(color, i); 
		tokens.push_back(headHog);
	}

}

// method that chooses a random place to put the a token based on a given array 
int Player::placeHog( bool * avaliablePos){

	srand(time(NULL));

	int position;

	// getting and returning our posstion
	while(true){
		
		// getting random num 
		position = (rand() % 6);

		// if the random num is avaliable break the loop 
		if(avaliablePos[position]){
			break;
		}
	}

	// return possition 
	return position;
}

// method to get a certain token based on the tokens number 
Token Player::getToken(int x){
	return tokens[x];
}


// method to get the players color
string Player::getColor(){
	return color;
}

// method to get the players num
int Player::getPlayerNum(){
	return playerNum;
}

// overloaded = operator;
Player Player::operator=( Player & p){

	// setting all the tokens to be the same 
	for(vector<Token>::iterator i = p.tokens.begin(); i != p.tokens.end() ; i++){
		tokens.push_back(*i);
	}
	// setting the colors to be the same 
	color = p.color;

	// settign the player number to be the same 
	playerNum = p.playerNum;

	// returning this object 
	return (*this);
}

void Player::display() {

	// Display location of tokens and ranking below the board.
}