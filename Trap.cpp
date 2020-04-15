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

// method to check if this is a trap 
bool Trap::isTrap(){
	return true;
}

// method to push token in trap
void  Trap::pushToken(Token & t){
	trapped = true; 
	Square::pushToken(t);
}

// method to check if we can pop item 
bool Trap::trapPop(int x, int playerNum ){
	return true;
}
