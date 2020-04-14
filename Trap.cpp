#include "Trap.h"
#include <string>

using namespace std;

// Constructor
Trap::Trap(int x, int y) :Square(x, y) {
	trapped =false;
}

// overloaded display for trap
void Trap::display() {

	cout << NAME;

	Square::display();
}

bool Trap::isTrap(){
	return true;
}

void  Trap::pushToken(Token & t){
	trapped = true; 
	Square::pushToken(t);
}

bool Trap::trapPop(int x, int playerNum ){
	return true;
}
