#include "Square.h"
#include "Token.h"
#include <stack>

using namespace std;

// constructor 
Square::Square(int x, int y) {
	x_location = x;
	y_location = y;


	// choosinf the appropriate letter for the x axis
	switch(x_location){
			case 0: alphabet = 'S';
					break;
			case 1: alphabet = 'A';
					break;
			case 2: alphabet = 'B';
					break;
			case 3: alphabet = 'C';
					break;
			case 4: alphabet = 'D';
					break;
			case 5: alphabet = 'E';
					break;
			case 6: alphabet = 'F';
					break;
			case 7: alphabet = 'G';
					break;
			case 8: alphabet = 'Z';
					break;
		}
}

// display method of the square
void Square::display() {

	// displaying the courdinates of the square 
	cout << y_location << alphabet << " ";
}

int Square::getSize(){
	return currTokens.size();
}

Token Square::getTopToken(){
	return currTokens.top();
}

void Square::pushToken(Token t){
	currTokens.push(t);
}

bool Square::isEmpty(){
	return currTokens.empty();
}

void Square::showTokens(){

	stack<Token> tempStack;

	Token tempToken;

	for(int i = 0; i < currTokens.size(); i++){

		tempToken = currTokens.top();

		currTokens.pop();

		tempStack.push(tempToken);
	}

	for(int i =0; i < tempStack.size(); i++){

		tempToken = tempStack.top();

		tempStack.pop();

		cout << alphabet << y_location << ": " << tempToken.getColor();

		currTokens.push(tempToken);
	}
}