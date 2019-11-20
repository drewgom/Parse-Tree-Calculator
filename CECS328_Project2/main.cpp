// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#include <iostream>
#include <string>
#include "main.hpp"

using namespace std;

int main() {
    
    string i = getUserInput();
    cout << "The user input was " << i << endl;
    return 0;
}





// Methods

string getUserInput()   {
    string userInput;
    cout << "Please enter your equation as a single line: " << endl;
    getline(cin, userInput);
    return userInput;
}
