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

// get size of stack 
int Square::getSize(){
	return currTokens.size();
}

// get the top token 
Token Square::getTopToken(){
	return currTokens.top();
}

// push a token to the stack 
void Square::pushToken(Token t){
	currTokens.push(t);
}

// check if the stack is empty 
bool Square::isEmpty(){
	return currTokens.empty();
}

// show the tokens in the square  
void Square::showTokens(){

	// dummy stack 
	stack<Token> tempStack;

	// dummy token 
	Token tempToken;

	// getting actual size
	int currSize = currTokens.size();

	// passing all the token to the dummy stack to display them in order 
	for(int i = 0; i < currSize; i++){

		tempToken = currTokens.top();

		currTokens.pop();

		tempStack.push(tempToken);
	}

	// displaying courdinates 
	cout << alphabet << y_location << ": ";

	// passing the tokens back to the actual stack and displaying it
	for(int i =0; i < currSize; i++){

		tempToken = tempStack.top();

		tempStack.pop();

		 cout << tempToken.getColor()[0];

		currTokens.push(tempToken);
	}
}