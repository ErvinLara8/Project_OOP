#include "GoodSquare.h"
#include <string>

using namespace std;

// Constructor
GoodSquare::GoodSquare(int x, int y, string n): Square(x, y){
    name = n;
}

void GoodSquare::display(){

    cout << name;
    Square::display();
}