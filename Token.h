#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>


using namespace std;
class Token {

private:

	string color;
	int number;

public:

	Token(string col = "blank", int num = 0);

	int getNumber();
	string getColor();

	Token operator=(const Token &);

};

#endif
