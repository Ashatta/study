#include <iostream>
#include "stackmachine.h"

int StackMachine::calculate(int operand1, int operand2, char operation)
{
    switch (operation)
    {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        default: return operand1 / operand2;
    }
}

int StackMachine::calculate(std::istream &source)
try
{
    int num = 0;
    source >> num;
    stack.push(num);

    source.get();
    char ch = source.peek();
    while (ch != '\n' && !source.eof())
    {
        if (isdigit(ch))
        {
            source >> num;
            stack.push(num);
        }
        else if (!isspace(ch))
            stack.push(calculate(stack.pop(), stack.pop(), ch));
        source.get();
        ch = source.peek();
    }
    return stack.top();
}
catch (EmptyStack e)
{
    std::cerr << "Incorrect input" << std::endl;
    throw; 
}

