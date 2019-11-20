// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#include "Operand.hpp"
#include <string>

Operand::Operand(string operandAsString)    {   value = stoi(operandAsString);  }
string Operand::getValue()                  {   return to_string(value);        }
