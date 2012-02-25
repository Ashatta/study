#include <iostream>
#include "expression.h"
#include "number.h"

void operation()
{
    char ch = std::cin.peek();
    if (!(ch == '+' || ch == '-' || ch == '*' || ch == '/'))
        throw 2;
    std::cin.get();
    ch = std::cin.peek();
    while (ch == ' ' || ch == '\t')
    {
        std::cin.get();
        ch = std::cin.peek();
    }
}

void expression()
{
    number();
    while (std::cin.peek() != '\n' && !std::cin.eof())
    {
        operation();
        if (std::cin.peek() != '\n' && !std::cin.eof())
            number();
        else
            throw 4;
    }
}

