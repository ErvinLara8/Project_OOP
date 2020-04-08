#include <iostream>
#include "Game.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>

using namespace std;

int main(){

    Game game1(2, 123);

    game1.show();

    game1.setInitialPos();

    game1.showProgress();
    
    game1.~Game();
}