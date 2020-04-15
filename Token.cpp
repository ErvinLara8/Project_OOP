#include "Token.h"

// contructor
Token::Token(string col, int num){
    color = col;
    currentScore = 0;
    number = num;
}

// method to get token color 
string Token::getColor(){
    return color;
}

// method to get token number 
int Token::getNumber(){
    return number;
}

// overloading the = operator 
Token & Token::operator=(const Token & t){

    color = t.color;
    number = t.number;
    currentScore = t.currentScore;
    location[0] = t.location[0];
    location[1]= t.location[1];
    return (*this);
}

// method to get location 
int * Token::getLocation() {
	return location;
}

// method to set location
bool Token::setLocation(int x, int y) {
	location[0] = x;
	location[1] = y;
	return true;
}

// method to change score 
void Token::setScore(int x){
    currentScore = x;
}

// method to get score
int Token::getScore(){
    return currentScore;
}