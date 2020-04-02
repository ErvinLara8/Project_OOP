
#include "Game.h"
#include "Square.h"


Game::Game(int n) {

	nPlayers = n;
	// First, create the instances of players
	for (int i = 0; i < nPlayers; i++) {

		Player p(); // always 4 tokens each player
	}

	// Secondly, create the instances of the squares with the board

	for (int l = 0; l < 9; l++) { // length of board
		for (int w = 0; w < 6; w++) { // width of board
			Square s = Square(l, w);
			board[l][w] = s;
			s.display();
		}
	}
}

void Game::show() {


}
