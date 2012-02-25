#include <cstdio>
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

    clog << "The program checks if a text is correct.\n"
         << "Write the text: " << endl; 
    char c = 0;
    while (cin.get(c) && c != '\n')
        if (isBracket(opening, c))
            s.push(c);
        else
            if (isBracket(closing, c))
                if (!s.empty() && haveOneType(s.top(), c))
                    s.pop();
                else
                {
                    cout << "Incorrect" << endl;
                    return 1;
                } 

    if (!s.empty())
    {
        cout << "Incorrect" << endl;
        return 1;
    }

    cout << "Correct" << endl;
    return 0;
}

