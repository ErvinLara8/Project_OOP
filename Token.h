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
	bool moved;

public:

	Token(string col = "blank", int num = 0);

	int getNumber();
	string getColor();
	int * getLocation();
	bool setLocation(int x, int y);
	void setScore(int x);
	int getScore();

	void setMoved(bool x);
	bool iMoved();

	Token operator=(const Token &);
};

#endif
