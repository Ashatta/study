#pragma once
#include "linkedstack.h"

class StackMachine
{
    public:
        int calculate(std::istream &source);

    private:
        int mCalculate(int operand1, int operand2, char operation);
        LinkedStack stack;
};

