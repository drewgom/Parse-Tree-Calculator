// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#ifndef Symbol_hpp
#define Symbol_hpp

#include <stdio.h>
#include <string>

using namespace std;


// This class represents a character in a mathematical expression that is entered.
// In the assignment, This was called an "operator". However, since that is
// a reserve word in C++, I did not use that. Made it so that operands(like
// numbers) and mathematical operations (like addition, subtraction, etc.)
// are both children of symbol so that they can be stored together.
class Symbol    {
public:
    virtual string getValue() = 0;
};
#endif
