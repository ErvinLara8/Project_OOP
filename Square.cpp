#include "Square.h"
#include <iostream>

using namespace std;

// main constructor 
Square::Square(int x, int y) {
	x_location = x;
	y_location = y;
}

// display function for square alone
void Square::display() {

	char alphabet; 

	// choosing the char that belong to the x axis 
	switch(x_location){
		case 1: alphabet = 'a';
		case 2: alphabet = 'b';
		case 3: alphabet = 'c';
		case 4: alphabet = 'd';
		case 5: alphabet = 'e';
		case 6: alphabet = 'f';
		case 7: alphabet = 'g';
		case 8: alphabet = 'h';
		case 9: alphabet = 'i';
	}

	cout << y_location << "" << alphabet << " "; 
}
