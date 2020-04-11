
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
	totalScore = 0;

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
Token & Player::getToken(int x){
	return  tokens[x];
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

	// copying the tokens vector
	tokens = p.tokens;

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

void Player::verticalMove(Square *** & board, int ln){

	Token myToken; 

	// this case checking if there are tokens in the moving lane
	for(int i = 7; i >= 0; i--){

		if(!board[i][ln]->isEmpty()){

			myToken = board[i][ln]->getTopToken();

			if(myToken.getColor() == color){
				
				if(!board[(i+1)][ln]->isTrap()){
					continue;
				}else{
					if(ln == 0){

						if(board[(i)][ln + 1]->isTrap()){
							continue;
						}else{

							board[i][ln]->popToken();

							board[i][(ln+1)]->pushToken(myToken);
						}

					}else{

						if(ln == 5 && board[(i)][ln - 1]->isTrap()){
							continue;
						}{
						board[i][ln]->popToken();

						board[i][(ln-1)]->pushToken(myToken);
						}
					}
				}
			}
		}
	}

	// checking the lane above the lane moving 
	if(ln > 0){

		int lnTop = ln - 1;

		for(int i = 7; i >= 0; i--){

			if(!board[i][lnTop]->isEmpty()){

				myToken = board[i][lnTop]->getTopToken();

				if(myToken.getColor() == color && !board[i+1][ln]->isTrap() ){

					if(!board[i][ln]->isEmpty()){

						if( board[i][ln]->getTopToken().getColor() == color ){
								continue;
							}else{
								board[i][lnTop]->popToken();
								board[i][ln]->pushToken(myToken);
							}
					}else{
						board[i][lnTop]->popToken();
						board[i][ln]->pushToken(myToken);
					}
				}
			}
		}
	}

	if(ln < 5){
		
		int lnBot = ln + 1;

		for(int i = 7; i >= 0; i--){

			if(!board[i][lnBot]->isEmpty()){

				myToken = board[i][lnBot]->getTopToken();

				if(myToken.getColor() == color &&  !board[i+1][ln]->isTrap() ){ 

					if(!board[i][ln]->isEmpty()){

						if( board[i][ln]->getTopToken().getColor() == color){
								continue;
							}else{
								board[i][lnBot]->popToken();
								board[i][ln]->pushToken(myToken);
							}
					}else{
						board[i][lnBot]->popToken();
						board[i][ln]->pushToken(myToken);
					}
					
				}
			}
		}
	}
}

int Player::getTotalScore(){
	return totalScore;
}

void Player::updateScore(){

	totalScore = 0;
	for(vector<Token>::iterator it = tokens.begin(); it != tokens.end(); it++){

		totalScore += it->getScore();

	}
}