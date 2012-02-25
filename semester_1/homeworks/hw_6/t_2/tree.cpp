#include <iostream>
#include <fstream>
#include <cctype>
#include "tree.h"

class invalidArgument {};
class invalidOperation {};

const int operNum = 4;
const char operations[] = {'+', '-', '*', '/'};

int Expression::calculate()
{
    switch (operation)
    {
        case '+' :
            return left->calculate() + right->calculate(); 
        case '-' :
            return left->calculate() - right->calculate(); 
        case '*' :
            return left->calculate() * right->calculate(); 
        case '/' :
            return left->calculate() / right->calculate(); 
    }
}

void Expression::print()
{
    std::cout << '(' << operation << ' ';
    left->print();
    std::cout << ' ';
    right->print();
    std::cout << ')';
}

bool Expression::isInvalidOperation(char oper)
{
    for (int i = 0; i < operNum; ++i)
        if (oper == operations[i])
            return 0;
    return 1;
}

Node * Expression::getNode(std::ifstream &in)
{
    while (isspace(in.peek()))
        in.get();
    
    if (in.peek() == '(')
        return new Expression(in);
    
    if (in.peek() >= '0' && in.peek() <= '9')
        return new Number(in); 

    throw invalidArgument(); 
}

Expression::Expression(std::ifstream &in)
{
    in.get(); 
    in >> operation;

    while (isspace(operation))
        in >> operation;
    if (isInvalidOperation(operation))
        throw invalidOperation();

    left = getNode(in);
    right = getNode(in);

    in.get();
}

Expression::~Expression()
{
    delete left;
    delete right;
}


