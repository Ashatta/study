#include <iostream>
#include <stack>

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
    stack<char> s;

    clog << "The program checks input for a bracket balance" << endl;
    char c = 0;
    while ((c = cin.get()) != '\n' && !cin.eof())
        if (isBracket(opening, c))
            s.push(c);
        else
            if (isBracket(closing, c))
                if (!s.empty() && haveOneType(s.top(), c))
                    s.pop();
                else
                {
                    cout << "Disbalance" << endl;
                    return 1;
                } 

    if (!s.empty())
    {
        cout << "Disbalance" << endl;
        return 1;
    }

    cout << "Balance" << endl;
    return 0;
}

