#include <cstdio>
#include <iostream>

using namespace std;

const int numBrackets = 4;
const char opening[] = {'(', '[', '<', '{'};
const char closing[] = {')', ']', '>', '}'};

bool isBracket(const char brackets[], char c)
{
    for (int i = 0; i < numBrackets; ++i)
        if (c == brackets[i])
            return 1;
    return 0;
}

bool haveOneType(char open, char close)
{
    int iOpen = 0;
    while (opening[iOpen] != open)
        ++iOpen;
    int iClose = 0;
    while (closing[iClose] != close)
        ++iClose;
    return iOpen == iClose;
}

int main()
{
    const int maxStackLength = 1000;
    int stack[maxStackLength + 1];
    stack[0] = 0;

    clog << "The program checks input for a bracket balance" << endl;
    char c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        if (isBracket(opening, c))
            stack[++stack[0]] = c;
        else
            if (isBracket(closing, c))
                if (!stack[0] && haveOneType(stack[stack[0]], c))
                    --stack[0];
                else
                {
                    cout << "Imbalance" << endl;
                    return 1;
                } 

    if (!stack[0])
    {
        cout << "Imbalance" << endl;
        return 1;
    }

    cout << "Balance" << endl;
    return 0;
}

