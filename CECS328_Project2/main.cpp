// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#include <iostream>
#include <string>
#include <vector>
#include "main.hpp"
#include "Symbol.hpp"
#include "Op.hpp"
#include "BinaryOp.hpp"
#include "GroupingOp.hpp"
#include "Operand.hpp"

using namespace std;

int main() {
    // Gets the user’s input and saves it as a string
    //string inputstring = getUserInput();
    
    vector<Symbol*> syms;
    syms.push_back(new Operand("50"));
    syms.push_back(new BinaryOp('^'));
    syms.push_back(new Operand("4"));
    
    cout << syms.at(0)->getValue() + " " + syms.at(1)->getValue() + " " + syms.at(2)->getValue() + " is ";
    cout << dynamic_cast<BinaryOp*>(syms.at(1))->callOperation(stoi(syms.at(0)->getValue()), stoi(syms.at(2)->getValue())) << endl;
    
    for (auto iterat = syms.begin(); iterat != syms.end(); iterat++)    {
        delete *iterat;
    }
    return 0;
}





// Methods

string getUserInput()   {
    string userInput;
    cout << "Please enter your equation as a single line: " << endl;
    getline(cin, userInput);
    return userInput;
}

bool validInput()   {
    return true;
}
