#include "Trap.h"
#include <string>

using namespace std;

// Constructor
Trap::Trap(int x, int y, string n ) :Square(x, y) {
	name = n;
}

void Trap::display() {

	cout << name;

	Square::display();
}


