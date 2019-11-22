// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#ifndef main_h
#define main_h

#include <string>
#include <map>
#include "Symbol.hpp"
#include "Op.hpp"

using namespace std;

string getUserInput();
deque<Symbol*> stringToSymbols(string stringToTransform);
map<char, typeOfSymbol> getCharToSymbolMappings();
deque<Symbol*> infixToPostfix(deque<Symbol*> infixDeque);
map<string, int> getOrderOfOperations();

#endif
