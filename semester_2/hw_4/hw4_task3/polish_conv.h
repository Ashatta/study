#pragma once
#include "arraystack.h"

class BracketsDisbalance {};

// PolishConverter converts an expression from infix notation to the postfix one
// receives an expression from stream source
// expression in postfix notation will be written in stream dest
class PolishConverter
{
public:
    void convert(std::istream &source, std::stringstream &dest);
private:
    bool isOperation(char ch);
    bool isLessPriority(char op1, char op2)
    {
        return op1 == '+' || op1 == '-' || op2 == '*' || op2 == '/';
    }
    ArrayStack<char> stack;
};
