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
					score = 10;
					break;
			case 1: alphabet = 'A';
					score = 10;
					break;
			case 2: alphabet = 'B';
					score = 20;
					break;
			case 3: alphabet = 'C';
					score = 30;
					break;
			case 4: alphabet = 'D';
					score = 40;
					break;
			case 5: alphabet = 'E';
					score = 50;
					break;
			case 6: alphabet = 'F';
					score = 60;
					break;
			case 7: alphabet = 'G';
					score = 70;
					break;
			case 8: alphabet = 'Z';
					score = 200;
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

	t.setScore(score);
	t.setLocation(x_location, y_location);
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

		tempToken =  currTokens.top();

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

Token Square::popToken(){
	Token dummy = currTokens.top();

	currTokens.pop();

	return dummy;
}