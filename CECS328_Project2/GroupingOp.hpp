// Name: Andrew Gomez
// Class: CECS328
// Project: Project 2

#ifndef GroupingOp_hpp
#define GroupingOp_hpp

#include "Op.hpp"

class GroupingOp : public Op    {
public:
    GroupingOp(char opAsChar);
    string getValue();
private:
    GroupingOpName typeOfOperation;
};

#endif 
