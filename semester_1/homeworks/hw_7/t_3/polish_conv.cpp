#include <iostream>
#include <sstream>
#include "polish_conv.h"
#include "stack.h"

using namespace std;

const char operations[] = {'+', '-', '*', '/'};
const int operNum = 4;

bool isOperation(char ch)
{
    for (int i = 0; i < operNum; ++i)
        if (ch == operations[i])
            return true;
    return false;
}

inline bool isLessPriority(char op1, char op2)
{
    return op1 == '+' || op1 == '-' || op2 == '*' || op2 == '/';
}

void convertToPolish(istream &source, stringstream &dest)
{
    Stack<char> stack;
    int num = 0;

    char ch = source.peek();
    while (!source.eof())
    {
        while (!source.eof() && isspace(ch))
        {
            source.get();
            ch = source.peek();
        }
        if (source.eof())
            break;

        if (ch == '(')
        {
            stack.pushBack(ch);
            source.get();
        }
        else if (isOperation(ch))
        {
            while (!stack.isEmpty() && stack.top() != '(' 
                    && isLessPriority(ch, stack.top()))
                dest << stack.popBack() << ' ';
            stack.pushBack(ch);
            source.get();
        }
        else if (ch == ')')
        {
            while (!stack.isEmpty() && stack.top() != '(')
                dest << stack.popBack() << ' ';
            if (stack.isEmpty())
                throw incorrectInput("Bracket disbalance");
            stack.popBack();
            source.get();
        }
        else if (isdigit(ch))
        {
            source >> num;
            dest << num << ' ';
        }
        else
            throw incorrectInput("Invalid argument");
        ch = source.peek();
    }

    while (!stack.isEmpty())
    {
        if (stack.top() == '(')
            throw incorrectInput("Brackets disbalance");
        dest << stack.popBack() << ' ';
    }
}

