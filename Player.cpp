
#include "Player.h"
#include <string>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>


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

Player::Player(const Player & p){
	tokens = p.tokens;

	color = p.color;

	playerNum = p.playerNum;
}

int Player::placeHog( Square *** & board){

	srand(time(NULL));

	// array that will hold the avaliable spaces 
	bool avaliablePos [6];

	int position;

	bool filledUp;

	int level = board[0][0]->getSize(); 


	// getting lowest level in the board
	for(int i =1; i < 6; i++){
		if(board[0][i]->getSize() < level){
			level = board[0][i]->getSize();
		}
	}

	// checking avialbe positions
	for(int i =1; i < 6; i++){
		if(board[0][i]->getSize() > level){
			avaliablePos[i] = false;
		}else{
			avaliablePos[i] = true;
		}
	}

	// checking if level is filled up 
	for(int i = 0; i < 6; i++){
		if(avaliablePos[i]){
			filledUp = false;
			break;
		}else{
			filledUp = true;
		}
		
	}
	
	// if we have a filled level go here or we are in level 0 and this is the first fill 
	if(filledUp){

		// if the level is greater than zero step here 
		if(level > 0){


			// making the avaliabble spaces true if the color below them is not the same color 
			Token currTop;
			for(int i = 0; i<6 ; i++){
				currTop = board[0][i]->getTopToken();

				if(currTop.getColor() == color){
					avaliablePos[i] = false;
				}else{
					avaliablePos[i] = true;
				}
			}

			// getting and returning our possition 
			while(true){
		
				position = (rand() % 6);

				if(avaliablePos[position]){
					break;
				}
			}

			return position;
		}
		// else if in the case where this is the first fill go here 
		else{
			
			// get and return random position 
			position = (rand() % 6);
			return position;
		}
		
	}
	// step here if not all levels are filled up and there is still a space to put a piece
	else{


		if(level > 0){
			
			Token currTop;
			for(int i = 0; i<6 ; i++){
				currTop = board[0][i]->getTopToken();

				if(currTop.getColor() == color){
					avaliablePos[i] = false;
				}else{
					avaliablePos[i] = true;
				}
			}

			// getting and returning our possition 
			while(true){
		
				position = (rand() % 6);

				if(avaliablePos[position]){
					break;
				}
			}

			return position;

		}
		
		else{
		
			// getting and returning our posstion
			while(true){
		
				position = (rand() % 6);

				if(avaliablePos[position]){
					break;
				}
			}
			return position;
		}
	}
	
}

Token Player::getToken(int x){
	return tokens[x];
}

vector<Token> Player::getAllTokens(){
	return tokens;
}

string Player::getColor(){
	return color;
}

int Player::getPlayerNum(){
	return playerNum;
}

Player Player::operator=(const Player & p){

	tokens = p.tokens;

	color = p.color;

	playerNum = p.playerNum;

	return (*this);

}

void Player::display() {

	// Display location of tokens and ranking below the board.
}