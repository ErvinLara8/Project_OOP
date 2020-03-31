#ifndef PLAYER_H
#define PLAYER_H

#include "Token.h"

#include <vector>
#include <string>

using namespace std;

class Player {

private:

	vector<Token> tokens;
	int nTokens;
	string color;

public:

	Player(int n=4);

	virtual void display();

};

#endif