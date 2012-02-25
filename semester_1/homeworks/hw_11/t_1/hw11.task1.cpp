#include <iostream>
#include "number.h"
#include "expression.h"

int main()
{
    std::clog << "The program checks whether an input string is a correct\n"
         << "expression containing real numbers and operations +, -, *, /\n"
         << "Enter an expression" << std::endl;
    try
    {
        expression();
    }
    catch (int error)
    {
        std::cerr << "Error: ";
        switch (error)
        {
            case 1: std::cerr << "incorrect number" << std::endl;
                    break;
            case 2: std::cerr << "incorrect operation" << std::endl;
                    break;
            case 4: std::cerr << "unexpected end of expression" << std::endl;
        }
        return error;
    }
    std::clog << "Correct" << std::endl;
    return 0;
}

