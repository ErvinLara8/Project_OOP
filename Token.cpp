#include "Token.h"

Token::Token(string col, int num){

    color = col;

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