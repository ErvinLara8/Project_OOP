#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>


using namespace std;
class Token {

private:

	string color;
	int number;
	int location [2] = {0,0};
	int currentScore;

public:

	// constructor
	Token(string col = "blank", int num = 0);

	// method to get number of token
	int getNumber();

	// methdo to get color of token 
	string getColor();

	// method to get location of token 
	int * getLocation();

	// method to set location of token 
	bool setLocation(int x, int y);

	// method to set score of token 
	void setScore(int x);

	// method to get score 
	int getScore();

	// overloading = operator 
	Token & operator=(const Token &);
};

#endif
