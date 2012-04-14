#include <iostream>
#include "stackmachine.h"

double StackMachine::calculate(double operand1, double operand2, char operation)
{
    switch (operation)
    {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        default: if (operand2 == 0.0)
                     throw DivisionByZeroException();
                 return operand1 / operand2;
    }
}

double StackMachine::calculate(std::istream &source)
try
{
    double num = 0;
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
        {
            double op2 = stack.pop();
            stack.push(calculate(stack.pop(), op2, ch));
        }
        source.get();
        ch = source.peek();
    }
    double result = stack.pop();
    if (!stack.isEmpty())
        throw IncorrectInputException();
    return result;
}
catch (EmptyStack)
{
    throw IncorrectInputException(); 
}

