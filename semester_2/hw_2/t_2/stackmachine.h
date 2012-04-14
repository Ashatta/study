#pragma once
#include "arraystack.h"

class DivisionByZeroException {};
class IncorrectInputException {};

class StackMachine
{
public:
    double calculate(std::istream &source);

private:
    double calculate(double operand1, double operand2, char operation);
    ArrayStack<double> stack;
};

