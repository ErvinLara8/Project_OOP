
#include "Player.h"
#include <string>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <iterator>
#include "Trap.h"
#include "WormHole.h"


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
Player Player::operator=( const Player & p){

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

// returning the total score
int Player::getTotalScore(){
	return totalScore;
}

// method that sums up all the tokens scores
void Player::updateScore(){
	totalScore = 0;
	for(vector<Token>::iterator it = tokens.begin(); it != tokens.end(); it++){
		totalScore += it->getScore();
	}
}

// method to update the value of a token
void Player::updateToken(Token & t){
	tokens[t.getNumber()] = t;
}


// method that will move a token given the board, the lane and the player numbesr 
bool Player::moveToken(Square *** & board, int ln, int playerNum){

	bool moved_opponent = false;

	bool initialVertical = false;
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
						moved_opponent = false;
						return moved_opponent;
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

				// if I have a token on a trap i have to check if i can move it 
				else{
					bool allowed = checkTrapType(board, ln, i, playerNum);
					if(allowed){
						myToken = board[i][ln]->popToken();
						board[i+1][ln]->pushToken(myToken);
						tokens[myToken.getNumber()] = myToken;
						moved_opponent = false;
						return moved_opponent;
					}
				}	
			}
		}
	}

	// chekcing if there were any tokens behind that i could move forward after my vertical move
	for(int i = 7; i >= 0; i--){
		if(!board[i][ln]->isEmpty() && (board[i][ln]->getTopToken().getColor() == color)){
			
			// if the token of mine that i can move forward is not on a trap move it forward
			if(!board[i][ln]->isTrap()){
				if(!board[i+1][ln]->isTrap()){
					myToken = board[i][ln]->popToken();
					board[i+1][ln]->pushToken(myToken);
					tokens[myToken.getNumber()] = myToken;
					moved_opponent = false;
					return moved_opponent;
				}

			// else if the token of mine is in a trap i have to check if i can move it 
			}else{
				bool allowed = checkTrapType(board, ln, i, playerNum);
				if(allowed){
					myToken = board[i][ln]->popToken();
					board[i+1][ln]->pushToken(myToken);
					tokens[myToken.getNumber()] = myToken;
					moved_opponent = false;
					return moved_opponent;
				}
			}
		}
	}

	// if we get here there were no tokens we could possibly move forward 

	
	// boolen that checks if i still move one of my pieces forward 
	bool myPiece = false;

	// if we have moved vertically already and there are no tokens of mine to move forward move opponents token 
	if(initialVertical){
		myPiece = moveOpponentsToken(board,ln, playerNum);
		if(myPiece){
			moved_opponent = false;
		}else{
			moved_opponent = true;
		}
		return moved_opponent;
	}
	
	// else check lanes above or below 
	bool moveMyOwn = false; 

	// here we check if we can move a token down or up
	moveMyOwn = checkingTopBottom(board, ln, playerNum);

	// if we have moved a new token down then we move that token forward else we moved an opponents token
	if(moveMyOwn){

		for(int i = 7; i >= 0; i--){

			// looking for my token
			if(!board[i][ln]->isEmpty() && (board[i][ln]->getTopToken().getColor() == color)){

				// if the token is not on a trap move it forward 
				if(!board[i][ln]->isTrap()){
				myToken = board[i][ln]->popToken();
				board[i+1][ln]->pushToken(myToken);
				moved_opponent = false;
				return moved_opponent;

				// else check if you can move it forward
				}else{
					bool allowed = checkTrapType(board, ln, i, playerNum);
					if(allowed){
						myToken = board[i][ln]->popToken();
						board[i+1][ln]->pushToken(myToken);
						tokens[myToken.getNumber()] = myToken;
						moved_opponent = false;
						return moved_opponent;
					}
				}
			}
		}
		// not matter what return the moved_opponent
		return moved_opponent;

	// else if i couldnt move a piece down i move an opponent piece 
	}else{
		myPiece = moveOpponentsToken(board,ln, playerNum);
		if(myPiece){
			moved_opponent = false;
		}else{
			moved_opponent = true;
		}
		return moved_opponent;
	}
	// return moved_opponent 
	return moved_opponent;
}


// method that moves a token either to the moving lane 
bool Player::checkingTopBottom(Square *** & board, int ln, int playerNum){

	Token myToken; 

	// checking the top lane 
	if(ln > 0){

		int lnTop = ln - 1;

		// loop that checks top lane 
		for(int i = 7; i >= 0; i--){

			// if the square is not empty and the token on top is my color step here 
			if(!board[i][lnTop]->isEmpty() && (board[i][lnTop]->getTopToken().getColor() == color)){

				// if the square that the token is in is not a trap check if moving down is a good option 
				if(!board[i][ln]->isTrap()){

					// if the square where im moving to is a not a trap move the token down 
					if(!board[i+1][ln]->isTrap()){

						myToken = board[i][lnTop]->verticalPop();

						board[i][ln]->pushToken(myToken);

						return true;
					}

				// else also check if you can move at all 
				}else{
					bool allowed = checkTrapType(board, ln, i, playerNum);

					if(allowed && !board[i+1][ln]->isTrap()){

						myToken = board[i][lnTop]->verticalPop();

						board[i][ln]->pushToken(myToken);

						return true;
					
					}
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

				// check if the token is in a trap 
				if(!board[i][ln]->isTrap()){

					// if the square where im moving to is a not a trap move the token up
					if(!board[i+1][ln]->isTrap()){
						myToken = board[i][lnBot]->verticalPop();
						board[i][ln]->pushToken(myToken);
						return true;

					// check if it even can move
				}else{
					bool allowed = checkTrapType(board, ln, i, playerNum);

					if(allowed && !board[i+1][ln]->isTrap()){
						myToken = board[i][ln]->popToken();
						board[i+1][ln]->pushToken(myToken);
						tokens[myToken.getNumber()] = myToken;
						return true;

					}
				}
			}			
		}
	}
	}
	return false;
}

// method to move opponents token from the back to the front 
bool Player::moveOpponentsToken(Square *** & board, int ln, int playerNum){

	// opponents token 
	Token oppToken;

	// checking if i moved my own token 
	bool movedMyOwn = false;

	// looping from start to end 
	for(int i = 0; i < 8; i++){

		// if its empty fone even consider it 
		if(!board[i][ln]->isEmpty()){

			// if the current square is not a trap just move it 
			if(!board[i][ln]->isTrap()){
				oppToken = board[i][ln]->popToken();

				board[i+1][ln]->pushToken(oppToken);

				// if the square im stepping into is a wrom hole, call worm hole method 
				if((string) typeid(*board[i+1][ln]).name() == "class WormHole"){
					WormHole * tp;
					tp = (WormHole *) board[i+1][ln];
					tp->wormHoleMove(board, i+1, ln, color);
				}

				// returned that my own was false 
				movedMyOwn = false;
				return movedMyOwn;

			// else check if you can even move it accroding to the trap 
			}else{

				// schecking if allowed 
				bool allowed = checkTrapType(board, ln, i, playerNum);

				// if allowed move it 
				if(allowed){
					oppToken = board[i][ln]->popToken();
					board[i+1][ln]->pushToken(oppToken);
					if(oppToken.getColor() == color){
						tokens[oppToken.getNumber()] = oppToken;
						movedMyOwn = true;
					}else{
					movedMyOwn = false;
					}

					return movedMyOwn;
				}
			}
		}
	}

	return movedMyOwn;
}

// methdo to check the trap type 
bool Player::checkTrapType(Square *** & board, int ln, int x, int playerNum){

	// returning if movable 
	bool allowed = false;

	// lane = ln 
	int lane = ln;

	// chekcing type of square based on given position 
	if((string) typeid(*board[x][lane]).name() == "class NormalTrap" ||
 		(string) typeid(*board[x][lane]).name() == "class ShallowPit" || 
		(string) typeid(*board[x][lane]).name() == "class DeepPit") {
			
			// setting sum to zero 
			int sum = 0;

			// loop that check if all tokens have passed that colum 
			for(int j = 0; j < 6 ; j++){ sum += board[x][j]->getTokensPast();}

			// calling the trap pop method 
			Trap * tp;
			tp =  (Trap *) board[x][lane];

			// allowed will be set based on the method trap poped 
			allowed = tp->trapPop(sum , playerNum);

	}
	// returning allowed 
	return allowed;
}
