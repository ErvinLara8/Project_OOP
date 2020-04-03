#include "Square.h"

using namespace std;

// constructor 
Square::Square(int x, int y) {
	x_location = x;
	y_location = y;
}

// display method of the square
void Square::display() {

	// letter that will determine the x axis 
	char alphabet; 

	// choosinf the appropriate letter for the x axis
	switch(x_location){
			case 0: alphabet = 'S';
					break;
			case 1: alphabet = 'A';
					break;
			case 2: alphabet = 'B';
					break;
			case 3: alphabet = 'C';
					break;
			case 4: alphabet = 'D';
					break;
			case 5: alphabet = 'E';
					break;
			case 6: alphabet = 'F';
					break;
			case 7: alphabet = 'G';
					break;
			case 8: alphabet = 'Z';
					break;
		}

	// displaying the courdinates of the square 
	cout << y_location << alphabet << " ";


}
