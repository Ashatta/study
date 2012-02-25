#include <iostream>
#include <sstream>
#include "polish_calc.h"
#include "stack.h"

int calculate(int operand1, int operand2, char operation)
{
    switch (operation)
    {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
    }
}

int calculate(std::stringstream &source)
try
{
    Stack<int> stack;
    int num = 0;
    source >> num;
    stack.pushBack(num);

    source.get();
    char ch = source.peek();
    while (!source.eof())
    {
        if (isdigit(ch))
        {
            source >> num;
            stack.pushBack(num);
        }
        else if (!isspace(ch))
            stack.pushBack(calculate(stack.popBack(), stack.popBack(), ch));
        source.get();
        ch = source.peek();
    }
    return stack.top();
}
catch (emptyList e)
{
    std::cerr << "Incorrect input" << std::endl;
    throw;
}

