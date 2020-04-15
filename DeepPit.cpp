#include "DeepPit.h"
#include <iostream>
#include <stack>

using namespace std;

// constructor 
DeepPit::DeepPit(int x, int y, string lb): Trap(x,y){
    label = lb;
}

// overloaded display that also displays the label of the trap 
void DeepPit::display(){

    cout << '(' << label << ')'; 
    Trap::display();
}

// overwritten pop method 
Token DeepPit::popToken(){

    // creating dummy stack to get bottom element 
    stack<Token> dummyStack;
    // token that will rotate 
    Token tempToken;

    // loop that pushes everthign in reverse order to dummyStack
    while(!currTokens.empty()){
        tempToken = currTokens.top();
        dummyStack.push(tempToken);
        currTokens.pop();
    }

    // holding bottom token 
    Token bottomToken = dummyStack.top();

    // poping that token off the stack 
    dummyStack.pop();

    // putting everything back in the stack in order
    while (!dummyStack.empty())
    {
        tempToken = dummyStack.top();
        currTokens.push(tempToken);
        dummyStack.pop();
    }

    // incrementing tokens that have passed by 
    tokens_past ++;

    // returning the bottom token
    return bottomToken;
    
}

// overwritten pop method 
Token DeepPit::verticalPop(){

    // creating dummy stack to get bottom element 
    stack<Token> dummyStack;
    // token that will rotate 
    Token tempToken;

    // loop that pushes everthign in reverse order to dummyStack
    while(!currTokens.empty()){
        tempToken = currTokens.top();
        dummyStack.push(tempToken);
        currTokens.pop();
    }

    // holding bottom token 
    Token bottomToken = dummyStack.top();

    // poping that token off the stack 
    dummyStack.pop();

    // putting everything back in the stack in order
    while (!dummyStack.empty())
    {
        tempToken = dummyStack.top();
        currTokens.push(tempToken);
        dummyStack.pop();
    }

    // returning the bottom token
    return bottomToken;
    
}

// overwritten trapPop that checks if we can pop a token
bool DeepPit::trapPop(int x , int playerNum ){

    // if the amount of token in the stack is more than one do the pop 
    if(currTokens.size() > 1){
        return true;
    }else{
        // else check if you can pop out of the trap 
        if( x < (4*playerNum - currTokens.size())){return false;}
	    else{return true;}
    }
}