#include <iostream>
#include "charlist.h"

using namespace std;

inline bool isOperation(char c)
{
    return c == '-' || c == '+' || c == '*' || c == '/';
}

inline bool isLessPriority(char op1, char op2)
{
    return op1 == '-' || op1 == '+' || op2 == '*' || op2 == '/';
}

int main()
{
    clog << "The program converts an expression "
         << "from infix to postfix notation\n"
         << "Enter an expression" << endl;

    ListNode * stack = createNode(0);
    ListNode * out = createNode(0);

    char c = 0;
    while (cin.get(c))
    {
        if (!isspace(c))
            if (isOperation(c))
            {
                while (!isEmpty(stack) && isOperation(top(stack)) 
                        && isLessPriority(c, top(stack)))
                    append(out, pop(stack));
                push(stack, c);
            }
            else if (c == '(')
            {
                push(stack, c);
            }
            else if (c == ')')
            {
                while (!isEmpty(stack) && top(stack) != '(')
                    append(out, pop(stack));
                if (isEmpty(stack))
                {
                    cerr << "Brackets disbalance" << endl;
                    return 1;
                }
                pop(stack);
            }
            else
                append(out, c);
    }      

    while (!isEmpty(stack))
    {
        if (top(stack) == '(')
        {
            cerr << "Brackets disbalance" << endl;
            return 1;
        }
        append(out, pop(stack));
    }

    clog << "The expression in postfix notaion" << endl;
    outList(out); 

    deleteList(stack);
    deleteList(out);

    return 0;
}

