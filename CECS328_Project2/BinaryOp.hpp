// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#ifndef BinaryOp_hpp
#define BinaryOp_hpp
#include "Op.hpp"
#include <stdio.h>

class BinaryOp  : public Op  {
public:
    BinaryOp(char opAsChar);
    string getValue();
    int callOperation(int firstValue, int secondValue);
private:
    BinaryOpName typeOfOperation;
    
};

#endif
