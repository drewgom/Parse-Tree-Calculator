// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#include "BinaryOp.hpp"
#include <cmath>

BinaryOp::BinaryOp(char opAsChar)   {
    //Here, we will take the users input and cast it to
    // an integer. From there, we can tell what operator it is supposed to be
    int ASCIIofInputOp = (int) opAsChar;
    switch(ASCIIofInputOp)  {
        case 43:
            this->typeOfOperation = ADDITION;
            break;
        case 45:
            this->typeOfOperation = SUBTRACTION;
            break;
        case 42:
            this->typeOfOperation = MULTIPLICATION;
            break;
        case 47:
            this->typeOfOperation = DIVISION;
            break;
        case 94:
            this->typeOfOperation = EXPONENTIATION;
            break;
    }
}

    
int BinaryOp::callOperation(int firstValue, int secondValue)  {
    // This calls the operation on the two values, in order
    switch(this->typeOfOperation)  {
        case ADDITION:
            return firstValue + secondValue;
        case SUBTRACTION:
            return firstValue - secondValue;
        case MULTIPLICATION:
            return firstValue * secondValue;
        case DIVISION:
            return firstValue / secondValue;
        case EXPONENTIATION:
            return pow(firstValue, secondValue);
    }
    
}

string BinaryOp::getValue()    {
    // This calls the operation on the two values, in order
    switch(this->typeOfOperation)  {
        case ADDITION:
            return "ADDITION";
        case SUBTRACTION:
            return "SUBTRACTION";
        case MULTIPLICATION:
            return "MULTIPLICATION";
        case DIVISION:
            return "DIVISION";
        case EXPONENTIATION:
            return "EXPONENTIATION";
    }
}

