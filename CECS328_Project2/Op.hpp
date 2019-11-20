// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#ifndef Op_hpp
#define Op_hpp
#include "Symbol.hpp"
#include <stdio.h>

enum BinaryOpName {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    EXPONENTIATION
};

enum GroupingOpName {
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS
};

class Op  : public Symbol  {
public:
    virtual string getValue() = 0;
};

#endif 
