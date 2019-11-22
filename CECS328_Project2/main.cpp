// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include "main.hpp"
#include "Symbol.hpp"
#include "Op.hpp"
#include "BinaryOp.hpp"
#include "GroupingOp.hpp"
#include "Operand.hpp"

using namespace std;

int main() {
    // Gets the user’s input and saves it as a string
    string inputstring = getUserInput();
    
    // Turns the user's input in to a deque of symbols
    deque<Symbol*> infixSyms = stringToSymbols(inputstring);
    
    // Turns the infix symbols in to a postfix list of the same symbols
    deque<Symbol*> postfixSyms = infixToPostfix(infixSyms);
    
    
    for (auto iter = postfixSyms.begin(); iter != postfixSyms.end(); iter++)    {
        cout << (*iter)->getValue() << endl;
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

deque<Symbol*> stringToSymbols(string stringToTransform)    {
    deque<Symbol*> listOfSymbols;
    map<char, typeOfSymbol> charSymbolMappings = getCharToSymbolMappings();
    
    // For each character in the string, I save see if it is an Operand,
    // Grouping Operator, or Binary Operator. This gets tricky becuase a number can span
    // over multiple places in the string. However, all the symbols that are not numbers will
    // always just be themselves.
    
    // So, if it is not a number, then just create the symbol. Otherwise, we need to check to see
    // if it is the last number in a sequence. We know it will be the last number in the sequence if
    // the next character in the string is not a number.
    // If the next character is the number, then if the startOfNextNumber is set to NULL, then we need to set it
    int indexOfFirstSpotInDigit = -1;
    
    for (int i = 0; i < stringToTransform.length(); i++)    {
        if (charSymbolMappings[stringToTransform[i]] == GROUPING_OPERATOR)  {
            listOfSymbols.push_back(new GroupingOp(stringToTransform[i]));
        }
        else if (charSymbolMappings[stringToTransform[i]] == BINARY_OPERATOR) {
            listOfSymbols.push_back(new BinaryOp(stringToTransform[i]));
        }
        // If we reach this case, we have a number
        else    {
            if (indexOfFirstSpotInDigit == -1)    {
                indexOfFirstSpotInDigit = i;
            }
            
            // We'll check to see if the next value is not a number. If it is not, then we add the number,
            // and set the index of the first spot of the digit to -1. Otherwise, we do nothing.
            if (charSymbolMappings[stringToTransform[i+1]] != OPERAND)    {
                string substringToAdd = stringToTransform.substr(indexOfFirstSpotInDigit, i - indexOfFirstSpotInDigit + 1);
                listOfSymbols.push_back(new Operand(substringToAdd));
                indexOfFirstSpotInDigit = -1;
            }
        }
    }
    
    return listOfSymbols;
}


deque<Symbol*> infixToPostfix(deque<Symbol*> infixDeque) {
    deque<Symbol*> postfixDeque;
    stack<BinaryOp*> stackOfOperators;
    
    map<string, int> OrderOfOperations = getOrderOfOperations();
    // While there is still elements in our queue, we are going to take the first element off the front
    // Every time we encounter an element, we want to do one of two things -
    //      1. If it is an operator, then we want to push it on to the stack of operators
    //      2. If it is a number, we want to add it to the postfixDeque
    
    while(!infixDeque.empty())  {
        
        // Gets the next symbol in the queue
        Symbol* currentSymbol = infixDeque.front();
        infixDeque.pop_front();
        cout << "Current Symbol is " << currentSymbol->getValue() << endl;
        
        if (dynamic_cast<Operand*>(currentSymbol))    {
            postfixDeque.push_back(currentSymbol);
        }
        
        // If that condition is not met, it is some sort of operand
        else    {
            BinaryOp* currentOperator = dynamic_cast<BinaryOp*>(currentSymbol);
            // If the stack is empty, we just add the element
            if (stackOfOperators.empty())   {
                stackOfOperators.push(currentOperator);
                cout << "Stack of operators is empty - pushing to stack " << currentSymbol->getValue() << endl;
            }
            // If the stack is not empty, we need to compare its precedence to the next element on the stack
            // If the top element on the stack is of higher precedence than the current element, then we need to
            // pop off that value, add it to the return list, and push on the current value
            else    {
                
                cout << "Stack size is " << stackOfOperators.size() << endl;
                while (OrderOfOperations[stackOfOperators.top()->getValue()] >= OrderOfOperations[currentOperator->getValue()] && !stackOfOperators.empty())   {
                    cout << "Top of stack is of higher precedence than current - " << stackOfOperators.top()->getValue() << " is higher than " << currentOperator->getValue() << endl;
                    postfixDeque.push_back(stackOfOperators.top());
                    cout << "size of stack is : " << stackOfOperators.size() << endl;
                    stackOfOperators.pop();
                    
                    if (stackOfOperators.empty()) {
                        break;
                    }
                }
                cout << "Pushing " << currentOperator->getValue() << " to stack" << endl;
                stackOfOperators.push(currentOperator);
            }
        }
        
        cout << endl;
    }
    
    // If we have gone through the whole input and there is still something in the stack,
    // we need to offload all of those symbols
    
    if (!stackOfOperators.empty())   {
        while (!stackOfOperators.empty())   {
            postfixDeque.push_back(stackOfOperators.top());
            stackOfOperators.pop();
        }
    }
    
    return postfixDeque;
}






map<char, typeOfSymbol> getCharToSymbolMappings()  {
    return {
        {'(', GROUPING_OPERATOR},
        {')', GROUPING_OPERATOR},
        {'+', BINARY_OPERATOR},
        {'-', BINARY_OPERATOR},
        {'*', BINARY_OPERATOR},
        {'/', BINARY_OPERATOR},
        {'^', BINARY_OPERATOR},
        {'0', OPERAND},
        {'1', OPERAND},
        {'2', OPERAND},
        {'3', OPERAND},
        {'4', OPERAND},
        {'5', OPERAND},
        {'6', OPERAND},
        {'7', OPERAND},
        {'8', OPERAND},
        {'9', OPERAND}
    };
}


map<string, int> getOrderOfOperations()  {
    return  {
        {"ADDITION", 1},
        {"SUBTRACTION", 1},
        {"MULTIPLICATION", 2},
        {"DIVISION", 2},
        {"EXPONENTIATION", 3},
    };
}
