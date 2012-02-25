#include <iostream>

using namespace std;

int main()
{
    clog << "The program checks if a string "
         << "is an anagram of another one" << endl;

    int letters[256];
    for (int i = 0; i < 256; ++i)
        letters[i] = 0;

    clog << "Enter the first string" << endl; 
    char c = 0;
    while ((c = cin.get()) != '\n')
        ++letters[c];
    clog << "Enter the second string" << endl; 
    while (cin.get(c) && c != '\n')
        --letters[c];

    for (int i = 0; i < 256; ++i)
        if (letters[i])
        {
            cout << "No" << endl;
            return 1;
        }

    cout << "Yes" << endl;
    return 0;
}

