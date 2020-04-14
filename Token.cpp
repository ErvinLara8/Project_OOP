#include "Token.h"

Token::Token(string col, int num){

    color = col;
    moved = false;
    currentScore = 0;
    number = num;
}

string Token::getColor(){
    return color;
}

int Token::getNumber(){
    return number;
}

Token Token::operator=(const Token & t){

    color = t.color;
    number = t.number;
    currentScore = t.currentScore;
    moved = t.moved;
    location[0] = t.location[0];
    location[1]= t.location[1];
    return (*this);
}

int * Token::getLocation() {
	return location;
}

bool Token::setLocation(int x, int y) {
	location[0] = x;
	location[1] = y;
	return true;
}

void Token::setScore(int x){
    currentScore = x;
}

int Token::getScore(){
    return currentScore;
}

void Token::setMoved(bool x){
    moved = x;
}

bool Token::iMoved(){
    return moved;
}