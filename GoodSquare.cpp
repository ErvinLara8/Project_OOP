#include "GoodSquare.h"
#include <string>

using namespace std;

// Constructor
GoodSquare::GoodSquare(int x, int y, string n): Square(x, y){
    name = n;
}

// overwritting the display method to display the proper name of the square then calling the actual square display 
void GoodSquare::display(){
    
    cout << name;
    Square::display();
}