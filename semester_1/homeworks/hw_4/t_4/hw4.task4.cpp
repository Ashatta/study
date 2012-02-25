#include <iostream>
#include <cctype>
#include "sort.h"

int main()
{
    std::clog << "Enter a number n = ";
    char number[20];
    int len = 0;
    char digit = 0;
    while (!std::cin.eof() && (digit = std::cin.get()) != '\n')
    {
        if (!isdigit(digit))
        {
            std::cerr << "Incorrect input" << std::endl;
            return 1;
        }
        number[len++] = digit;
    }
    qSort(number, 0, len - 1);
    int i = 0;
    while (number[i] == '0')
        ++i;
    swap(number[0], number[i]);
    for (int i = 0; i < len; ++i)
        std::cout << number[i];
    std::cout << std::endl;
    return 0;
}

