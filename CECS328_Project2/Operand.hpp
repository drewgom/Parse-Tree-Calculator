// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#ifndef Operand_hpp
#define Operand_hpp
#include "Symbol.hpp"
#include <stdio.h>

class Operand : public Symbol   {
public:
    Operand(string operandAsString);
    string getValue();
private:
    int value;
};
#endif
