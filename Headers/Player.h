#ifndef PLAYER_H
#define PLAYER_H

#include "Token.h"

#include <vector>
#include <string>

using namespace std;

class Player{

private:

vector<Token> tokens; 

public:

Player(string, int);

virtual void display(); 

};

#endif