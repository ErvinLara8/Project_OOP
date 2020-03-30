#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Square.h"

class Obstacle: public Square{

    private: 

    public: 

    Obstacle(int x, int y, string name);

    virtual void trap();

};

#endif