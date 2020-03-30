#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>


using namespace std;
class Token{

private: 

string color;
int number;

public:

Token(string, int);

int getNumber();
string getColor();

};

#endif