#include "Square.h"

using namespace std;


Square::Square(int x, int y) {
	x_location = x;
	y_location = y;
}

void Square::display() {

	char alphabet; 

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

	cout << y_location << alphabet << " ";


}
