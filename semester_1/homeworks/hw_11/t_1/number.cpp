#include <iostream>
#include "number.h"

void number()
{
    const int start = 0;
    const int sign = 1;
    const int floor = 2;
    const int point = 3;
    const int fracPart = 4;
    const int e = 5;
    const int expSign = 6;
    const int exp = 7;
    const int firstPoint = 8;

    int state = start;
    char ch = std::cin.peek();
    bool f = true;
    while (ch != '\n' && !std::cin.eof() && f)
    {
        switch (state)
        {
            case start: 
                if (ch == '+' || ch == '-')
                    state = sign;
                else if (isdigit(ch))
                    state = floor;
                else if (ch == '.')
                    state = firstPoint;
                else
                    f = false;
                break;
            case sign:
                if (isdigit(ch))
                    state = floor;
                else if (ch == '.')
                    state = point;
                else
                    f = false;
                break;
            case floor: 
                if (isdigit(ch))
                    break;
                else if (ch == '.')
                    state = point;
                else if (ch == 'e' || ch == 'E')
                    state = e;
                else
                    f = false;
                break;
            case point: 
                if (isdigit(ch))
                    state = fracPart;
                else if (ch == 'e' || ch == 'E')
                    state = e;
                else
                    f = false;
                break;
            case fracPart: 
                if (isdigit(ch))
                    break;
                else if (ch == 'e' || ch == 'E')
                    state = e;
                else
                    f = false;
                break;
            case e: 
                if (isdigit(ch))
                    state = exp;
                else if (ch == '-' || ch == '+')
                    state = expSign;
                else
                    f = false;
                break;
            case expSign: 
                if (isdigit(ch))
                    state = exp;
                else
                    f = false;
                break;
            case exp: 
                if (!isdigit(ch))
                    f = false;
                break;
            case firstPoint: 
                if (isdigit(ch))
                    state = fracPart;
                else
                    f = false;
        }
        if (f)
        {
            std::cin.get();
            ch = std::cin.peek();
        }
    }
    if (state == e || state == firstPoint || 
            state == sign || state == expSign || state == start)
        throw 1;
    while (ch == ' ' || ch == '\t')
    {
        std::cin.get();
        ch = std::cin.peek();
    }
}

