#include "Square.h"
#include "GoodSquare.h"
#include "Trap.h"
#include <iostream>
#include "Game.h"
#include <stdio.h>           
#include <time.h>
#include <algorithm>    
#include "NormalTrap.h"
#include "BlackHole.h"
#include "DeepPit.h"
#include "ShallowPit.h"
#include "WormHole.h"
#include "Player.h"
#include <thread>
#include <chrono>

using namespace std;

Game::Game(int numOfPlayer ,int gameid) {

	id_of_game = gameid;

	nPlayers = numOfPlayer;

	gameWon = false;

	string color;

	// First, create the instances of players and push them to the queue
	for (int i = 0; i < nPlayers; i++) {

		if(i == 0){
			color = "Red";
		}else if(i == 1){
			color = "Green";
		}else if(i == 2){
			color = "Blue";
		}else if(i == 3){
			color = "Purple";
		}else if(i == 4){
			color = "Yellow";
		}else{
			color = "White";
		}

		Player p(i +1 ,color);
		playerTurns.push(p);
	}

	// creating the board
	board = new Square **[9];

	for(int i = 0; i < 9; i++){
		board[i] = new Square*[6];
	}

	// calling to create the trap courdinates
	createTrapCourdinates();

	// assigning the the board what squares will be lanes and which ones will be traps 
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 6; j++){
			//creates an obstacle square at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)
			if(i == trap_x_coordinate[0] && j == trap_y_coordinate[0]){
				board[i][j] = new NormalTrap(i,j, "Nt");
			}else if(i == trap_x_coordinate[1] && j == trap_y_coordinate[1]){
				board[i][j] = new WormHole(i,j, "Wh");
			}else if(i == trap_x_coordinate[2] && j == trap_y_coordinate[2]){
				board[i][j] = new ShallowPit(i,j, "Sp");
			}else if(i == trap_x_coordinate[3] && j == trap_y_coordinate[3]){
				board[i][j] = new DeepPit(i,j, "Dp");
			}else if(i == trap_x_coordinate[4] && j == trap_y_coordinate[4]){
				board[i][j] = new WormHole(i,j, "Wh");
			}else if(i == trap_x_coordinate[5] && j == trap_y_coordinate[5]){
				board[i][j] = new NormalTrap(i,j, "Nt");
			}else{
				board[i][j] = new GoodSquare(i, j, "Square"); 
			}
		}
	}
}

// method that displays the game 
void Game::show(){

	// top letter that will be displayed 
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
			//if were at the first top left corner display a space 
			if(i == 0 && j == 0){
				std::cout << "         "; 
			}
			// if were at the 0 colum display the number of that column 
			else if(j == 0){
				std::cout << (i-1) << "     ";
			}
			//if were at the 0 row display the letter designated to that row 
			else if(i == 0){
				std::cout <<alphabet << "             ";
			}
			//else display the square
			else{
				board[j-1][i-1]->display();
				std::cout << "     "; 			
			}
		}
		//print new line 
		std::cout << "\n" << endl;
	}
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

// class destructor that destroys all the allocated memory 
Game::~Game(){
for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 6; j++) {
        delete board[i][j]; // delete stored pointer
    }
    delete[] board[i]; // delete sub array
}
delete [] board; //delete outer array
board = NULL;
}


void Game::setInitialPos(){

	srand(time(NULL));

	// array that will hold the avaliable spaces in general  
	bool avaliablePos [6] = {true,true,true,true,true,true};

	//array that will hold the avaliable spaces for each individual player 
	bool playerAvaliablePos [6] = {true,true,true,true,true,true};

	// int that will hold the total number of turns
	int totalTurns = nPlayers * 4;

	// Player object that will rotate
	Player  currPlayer;

	// token object that will be the top of the current square 
	Token currTopOfSquare;

	// position that will rotate 
	int position;

	// current token positioning 
	int currTokenNum = -1;

	// variable to check if we need to increase the leve
	bool filledUp = false;;

	// level variable that decides if we have to stack up or not
	int level = 0;

	// choosing the possitions 
	for(int i = 0; i < totalTurns; i++){

		// getting the next player and taking them off the queue 
		currPlayer = playerTurns.front();

		// if we roll over on players, we switch to the next token  
		if(i % nPlayers == 0){
			currTokenNum++;
		}

		// loop to check if all avaliable spots in general are filled up 
		for(int j = 0; j < 6; j ++){
			if(avaliablePos[j]){
				filledUp = false;
				break;
			}else{
				filledUp = true;
			}
		}

		// if they are filled up step here 
		if(filledUp){
			
			// clear spots 
			for(int j = 0; j < 6; j++){
				avaliablePos[j] = true;
			}
			// increase level and set filled up to false
			level++;
			filledUp = false;
		}


		// we arlready have one level 
		if(level > 0){
			
			// copy the avaliable spots to the individual player spots array 
			for(int j = 0; j < 6; j++){
				playerAvaliablePos[j] = avaliablePos[j];
			}

			// making the each unquie players array spot false if the previous color is theirs 
			for(int j = 0; j<6 ; j++){

				if(board[0][j]->getTopColor() == currPlayer.getColor()){
					playerAvaliablePos[j] = false;
				}
			}
			// getting position based on the current players avaliable spots
			position = currPlayer.placeHog(playerAvaliablePos);

		}
		// there is no need to stack yet 
		else{
			// get the position based on all the avaliable spots in general 
			position = currPlayer.placeHog(avaliablePos);
		}

		
		// push the current token of the current player in the choosen position 
		board[0][position]->pushToken( currPlayer.getToken(currTokenNum));

		// set that position to false 
		avaliablePos[position] = false;

		// push player to the back of the queue 
		playerTurns.pop();
		playerTurns.push(currPlayer);

	}
}

// method that shows where the tokens are placed 
void Game::showProgress(){

	std::cout<< endl << endl;

	// dummy player variable 
	Player currPlayer;

	// printing out each players number and color 
	for(int i =0; i < nPlayers; i++){

		currPlayer = playerTurns.front();

		std::cout << "Player: " << currPlayer.getPlayerNum() << " (" << currPlayer.getColor() << ")	";

		playerTurns.pop();
		playerTurns.push(currPlayer);
	}

	// space
	std::cout << endl << endl;

	// loop through the entier board and if there are tokens in the current square display them, else display a blank 
	for(int i = 0 ; i < 6 ; i++){
		for(int j = 0; j < 9 ; j++){

			if(!board[j][i]->isEmpty()){
				board[j][i]->showTokens();
				std::cout << "     ";
			}else{
				std::cout << "     ";
			}
		}
		std::cout << endl;
	}

	// display the ranks of the players from winner to loser
	std::cout << "Current Ranks:\n";
	for(vector<Player>::reverse_iterator it = ranking.rbegin(); it != ranking.rend(); it++){
		std::cout << "Player: " << it->getPlayerNum() << " (" << it->getColor() << ") Score: " << it->getTotalScore() << endl;
	}
}


// method to play the game 
void Game::playGame(){

	srand(time(NULL));

	// dice 
	int dice = 0;

	// current players turn 
	Player currentPlayer;

// `looping till game finishes 
	while(!gameWon){

		// dice is random number between 0 and 5
		dice = (rand() % 6);

		std::cout << "Rolled Dice Number: " << dice << endl;

	// getting the current players turn
		currentPlayer = playerTurns.front();

	// moving token with current dice roll 
		currentPlayer.moveToken(board, dice, nPlayers);

	// pushing the player to the back of the queue
		playerTurns.pop();
		playerTurns.push(currentPlayer);

	// updating the scores 
		updatePlayerScores(dice);

	// updating the ranks 
		setRanks();

	// showing the board again 
		show();

	// showing progress
		showProgress();

		this_thread::sleep_for(chrono::milliseconds(150));

	}

	// getting winner
	winner = ranking[ranking.size()-1];

	// printing out winner 
	std::cout<< "Winner is: Player" << winner.getPlayerNum() << " (" << winner.getColor() << ") !!!!" << endl << endl;


}


void Game::updatePlayerScores(int ln ){
	// vector used to update the tokens for each player
	vector<Player> dummyPlayerVector;

		// token being passed
	Token dummyToken;

		// player being passed
	Player tempPlayer;

	// passing all the players in the queue to the vector 
	while(!playerTurns.empty()){
		tempPlayer = playerTurns.front();

		dummyPlayerVector.push_back(tempPlayer);

		playerTurns.pop();
	}

	for(int i = 8; i >= 0; i--){
		if(!board[i][ln]->isEmpty()){
			dummyToken = board[i][ln]->getTopToken();
			break;
		}
	}

	for(int i = 0; i < dummyPlayerVector.size(); i++){

		if(dummyToken.getColor() == dummyPlayerVector[i].getColor()){
			dummyPlayerVector[i].updateToken(dummyToken);
			dummyPlayerVector[i].updateScore();
			break;
		}
	}
	

	// putting all players back in the queue
	while (!dummyPlayerVector.empty())
	{
		playerTurns.push(dummyPlayerVector.front());
		dummyPlayerVector.erase(dummyPlayerVector.begin());
	}
}

// method to set ranks 
void Game::setRanks(){

	// quete to access each player in the playerturns queue
	queue<Player> dummyQueue;

	// player that will iterate 
	Player dummyPlayer;

	// clearing all the ranks 
	ranking.clear();

	// pushing all the players from one queue to the other and updating their scores and puttin ghtme in ranking 
	while(!playerTurns.empty()){
		dummyPlayer = playerTurns.front();
		dummyPlayer.updateScore();
		ranking.push_back(dummyPlayer);
		playerTurns.pop();
		dummyQueue.push(dummyPlayer);
	}

	// putting all players back tot he normal queue 
	while(!dummyQueue.empty()){
		dummyPlayer = dummyQueue.front();
		dummyQueue.pop();
		playerTurns.push(dummyPlayer);
	}

	// sort algorithm that sorts the player in ranking and sorts them from least to greates based on their score
	sort(ranking.begin(), ranking.end(), sortRanks);

	// if the last player hasd a score od 1500 or greater they win and game ends
	if(ranking[ranking.size() -1].getTotalScore() >= 1500){
		gameWon = true;
	}
}

// method that sorts the players based on their score 
bool Game::sortRanks( Player & left, Player & right ){
	return left.getTotalScore() < right.getTotalScore();
}

