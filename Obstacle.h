// Obstacles are like squares but instead trap the tokens

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Square.h"

class Obstacle : public Square {

private:

string name;

public:

	Obstacle(int x, int y, string name);

	virtual void trap();

	virtual void display();

};

#endif

