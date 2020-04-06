// ITP 365 Spring 2019
// HW2 – itpPhone
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac
//
// Calculator.cpp
// Implements Calculator class
//

#include "Calculator.h"

// Function: Constructor
// Purpose: Does nothing
Calculator::Calculator()
{
	
}

// Function: pushNum
// Purpose: Pushes number onto the stack
// Input: number to push
// Output: None
void Calculator::pushNum(int number)
{
	// TODO: Implement
    //adds it to the stack
    myStack.push(number);
}

// Function: peekTop
// Purpose: Returns the number on top of the stack
//          (provided the stack is not empty)
// Input: None
// Output: Number on top of the stack
int Calculator::peekTop()
{
	// TODO: Implement
    //checks if the stack is empty and then shows top item
    if (!myStack.isEmpty()){
        return myStack.peek();
    }
    else {
        return 0;
    }
	
	return 0; // FIX TO RETURN CORRECT VALUE
}

// Function: doCalc
// Purpose: Performs the requested arithmetic,
//          provided there are two numbers on the stack.
//          Then pushes the result onto the stack.
//          Silently fails if the stack has less than two
//          numbers on it.
// Input: Type of arithmetic to perform
// Output: None
void Calculator::doCalc(CalcType type)
{
	// TODO: Implement
    if (myStack.size() < 2){
        //nothing
    }
    if (myStack.size()>= 2){
        int value1;
        int value2;
        int calculated;
        value1 = myStack.pop();
        value2 = myStack.pop();
        
        //checks calc type
        if (type == ADD){
            calculated = value1 + value2;
        }
        else if (type == SUB){
            calculated = value1 - value2;
        }
        else if (type == MUL){
            calculated = value1 * value2;
        }
        else if (type == DIV){
            calculated = value1/value2;
        }
        
        myStack.push(calculated);
    }
}
