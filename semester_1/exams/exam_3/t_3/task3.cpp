#include <iostream>

const int start = 0;
const int str = 1;

using namespace std;

bool isCorrect()
{
    clog << "A finite-state machine for regexp "
         << "[A-Za-z] ([A-Za-z] | [0-9] | _)*\n"
         << "Type a string: " << endl;
    char ch = cin.get();
    int state = start;

    while (!cin.eof() && ch != '\n')
    {
        switch (state)
        {
            case start: if (isalpha(ch))
                        {
                            state = str;
                            break;
                        }
                        else
                            return false;
            case str: 
                        if (!(isalpha(ch) || isdigit(ch) || ch == '_'))
                            return false;
        }
        ch = cin.get();
    }
    if (state == str)
        return true;
}

int main()
{
    clog << "Type a string" << endl;
    if (isCorrect())
        cout << "The string is correct" << endl;
    else
        cout << "The string is incorrect" << endl;
    return 0;
}

