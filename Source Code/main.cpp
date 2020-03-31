#include <iostream>
#include 

int main(){ 

	int nPlayers;

	cout << "Enter the number of players!";
	cin >> nPlayers;
	for (int i; i < nPlayers; i++) {

		cout << "Enter the color for Player" << i << endl;
	}

	Square* pointer;
	Game g(nPlayers);
	pointer = g.board; // pointer to the first square in the 2D array of Squares called board.







}