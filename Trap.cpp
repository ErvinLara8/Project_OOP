#include "Trap.h"
#include <string>

using namespace std;

// Constructor
Trap::Trap(int x, int y) :Square(x, y) {
}

// overloaded display for trap
void Trap::display() {

	cout << NAME;

	Square::display();
}


