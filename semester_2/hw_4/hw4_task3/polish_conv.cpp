#include <iostream>
#include <sstream>
#include "polish_conv.h"

const char operations[] = {'+', '-', '*', '/'};
const int operNum = 4;

bool PolishConverter::isOperation(char ch)
{
    for (int i = 0; i < operNum; ++i)
        if (ch == operations[i])
            return true;
    return false;
}

void PolishConverter::convert(std::istream &source, std::stringstream &dest)
{
    double num = 0;

    char ch = source.peek();
    while (!source.eof())
    {
        if (ch == ' ')
            source.get();
        else if (ch == '(')
        {
            stack.push(ch);
            source.get();
        }
        else if (isOperation(ch))
        {
            while (!stack.isEmpty() && stack.top() != '(' 
                    && isLessPriority(ch, stack.top()))
                dest << stack.pop() << ' ';
            stack.push(ch);
            source.get();
        }
        else if (ch == ')')
        {
            while (!stack.isEmpty() && stack.top() != '(')
                dest << stack.pop() << ' ';
            if (stack.isEmpty())
                throw BracketsDisbalance();
            stack.pop();
            source.get();
        }
        else if (isdigit(ch))
        {
            source >> num;
            dest << num << ' ';
        }
        ch = source.peek();
    }

    while (!stack.isEmpty())
    {
        if (stack.top() == '(')
            throw BracketsDisbalance();
        dest << stack.pop() << ' ';
    }
}
