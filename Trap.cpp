#include "Trap.h"
#include <string>

using namespace std;

// Constructor
Trap::Trap(int x = 0, int y = 0, string n = "") :Square(x, y) {
	name = n;
}

void Trap::display() {

	cout << name << " ";

	Trap::display();
}


