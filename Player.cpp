
#include "Player.h"
#include <string>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <iterator>
#include "Trap.h"


using namespace std;

// constructor of the Player
Player::Player( int pN, string col) {
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

	totalScore = p.totalScore;

	// returning this object 
	return (*this);
}

void Player::display() {

	// Display location of tokens and ranking below the board.
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

void Player::updateToken(Token t){
	tokens[t.getNumber()] = t;
}


bool Player::moveToken(Square *** & board, int ln, int playerNum){

	bool movedOponentsToken = false;

	bool initialVertical;
	Token myToken;

	// loop checking lane choosen, main priority is to move a token forward or get a token out of the path of a trap
	for(int i = 7; i >= 0; i--){

		//if square is empty dont even consider it  
		if(!board[i][ln]->isEmpty()){

			// if the current top token matches my color step here
			if(board[i][ln]->getTopToken().getColor() == color){

				if(!board[i][ln]->isTrap()){

					// if the next square is not a trap move that token forward
					if(!board[i+1][ln]->isTrap()){

						myToken = board[i][ln]->popToken();

						board[i+1][ln]->pushToken(myToken);

						tokens[myToken.getNumber()] = myToken;

						movedOponentsToken = false;

						return movedOponentsToken;

					}
					// else if it is a trap consider these scenarios 
					else{
						
						// if im on the 0 lane or the square above me is a trap i want to move down 
						if(ln == 0 || board[(i)][ln-1]->isTrap()){

							// if my path down is not a trap and im not trapped in both ends i move down
							if(!board[(i)][ln + 1]->isTrap()){

								myToken = board[i][ln]->verticalPop();

								board[i][(ln+1)]->pushToken(myToken);

								initialVertical = true;

								break;
								
							}

						}
						// else if the square above us is not a trap move up
						else{

							if(!board[(i)][ln - 1]->isTrap()){
								
								myToken = board[i][ln]->verticalPop();

								board[i][(ln-1)]->pushToken(myToken);

								initialVertical = true;

								break;
							}
						}
					}
				}
				// if I have a token on a trap
				else{

					bool allowed = checkTrapType(board, ln, i, playerNum);

					if(allowed){

						myToken = board[i][ln]->popToken();

						board[i+1][ln]->pushToken(myToken);

						tokens[myToken.getNumber()] = myToken;

						movedOponentsToken = false;

						return movedOponentsToken;

					}

				}	
				
			}
		}
	}

	// chekcing if there were any tokens behind that i could move forward after my vertical move
	for(int i = 7; i >= 0; i--){
		if(!board[i][ln]->isEmpty() && (board[i][ln]->getTopToken().getColor() == color)){

			if(!board[i+1][ln]->isTrap()){
				myToken = board[i][ln]->popToken();
				board[i+1][ln]->pushToken(myToken);
				tokens[myToken.getNumber()] = myToken;

				movedOponentsToken = false;

				return movedOponentsToken;
			}
		}
	}

	// if we get here there were no tokens we could possibly move forward 


	// if we have moved vertically already and there are no tokens of mine to move forward move opponents token 
	if(initialVertical){
		moveOpponentsToken(board,ln);
		movedOponentsToken = true;

		return movedOponentsToken;
	}
	
	// else check lanes above or below 
	bool moveMyOwn; 

	// here we check if we can move a token down or up
	moveMyOwn = checkingTopBottom(board, ln);

	// if we have moved a new token down then we move that token forward else we moved an opponents token
	if(moveMyOwn){

		for(int i = 7; i >= 0; i--){
			if(!board[i][ln]->isEmpty() && (board[i][ln]->getTopToken().getColor() == color)){
				myToken = board[i][ln]->popToken();
				board[i+1][ln]->pushToken(myToken);
				movedOponentsToken = false;

				return movedOponentsToken;
			}
		}
	}else{
		moveOpponentsToken(board,ln);
		movedOponentsToken = true;

		return movedOponentsToken;
	}

	return movedOponentsToken;
}


// method that moves a token either to the moving lane 
bool Player::checkingTopBottom(Square *** & board, int ln){

	Token myToken; 

	// checking the top lane 
	if(ln > 0){

		int lnTop = ln - 1;

		// loop that checks top lane 
		for(int i = 7; i >= 0; i--){

			// if the square is not empty and the token on top is my color step here 
			if(!board[i][lnTop]->isEmpty() && (board[i][lnTop]->getTopToken().getColor() == color)){

				// if the square where im moving to is a not a trap move the token down 
				if(!board[i+1][ln]->isTrap()){

					myToken = board[i][lnTop]->verticalPop();

					board[i][ln]->pushToken(myToken);

					return true;
				}
			}			
		}
	}

	// checking bottom lane 
	if(ln < 5){

	int lnBot = ln + 1;

	// loop that checks bottom lane 
	for(int i = 7; i >= 0; i--){

		// if the square is not empty and the token on top is my color step here 
		if(!board[i][lnBot]->isEmpty() && (board[i][lnBot]->getTopToken().getColor() == color)){

				// if the square where im moving to is a not a trap move the token up
				if(!board[i+1][ln]->isTrap()){

					myToken = board[i][lnBot]->verticalPop();

					board[i][ln]->pushToken(myToken);

					return true;
				}
			}			
		}
	}
	return false;
}

// method to move opponents token from the back to the front 
void Player::moveOpponentsToken(Square *** & board, int ln){

	Token oppToken;

	for(int i = 0; i < 8; i++){

		if(!board[i][ln]->isEmpty()){
			oppToken = board[i][ln]->popToken();

			board[i+1][ln]->pushToken(oppToken);

			return;
		}
	}
}

bool Player::checkTrapType(Square *** & board, int ln, int x, int playerNum){

	bool allowed;

	int lane = ln;

	if((string) typeid(*board[x][lane]).name() == "10NormalTrap" ||
 		(string) typeid(*board[x][lane]).name() == "class ShallowPit" || 
		(string) typeid(*board[x][lane]).name() == "class WormHole" ||
		(string) typeid(*board[x][lane]).name() == "class DeepPit") {

			int sum = 0;
			for(int j = 0; j < 6 ; j++){ sum += board[x][j]->getTokensPast();}

			Trap * tp;

			tp =  (Trap *) board[x][lane];

			allowed = tp->trapPop(sum , playerNum);

		}

	return allowed;
}