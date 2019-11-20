// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#include "GroupingOp.hpp"

GroupingOp::GroupingOp(char opAsChar)   {
    //Here, we will take the users input and cast it to
    // an integer. From there, we can tell what operator it is supposed to be
    int ASCIIofInputOp = (int) opAsChar;
    switch(ASCIIofInputOp)  {
        case 40:
            this->typeOfOperation = LEFT_PARENTHESIS;
            break;
        case 41:
            this->typeOfOperation = RIGHT_PARENTHESIS;
            break;
    }
}

string GroupingOp::getValue() {
    switch(this->typeOfOperation)  {
        case LEFT_PARENTHESIS:
            return "LEFT_PARENTHESIS";
        case RIGHT_PARENTHESIS:
            return "RIGHT_PARENTHESIS";
    }
}
