#include <iostream>
#include <cstring>
#include "power.h"

using namespace std;

const int base = 2;

void hash(char str1[], char str2[], int len, unsigned int &h1, unsigned int &h2)
{
    h1 = 0;
    h2 = 0;
    for (int i = 0; i < len; ++i)
    {
        h1 = (h1 * base + str1[i]);
        h2 = (h2 * base + str2[i]);
    }
}

inline int rehash(int old, int subt, int add, int d)
{
    return ((old - subt * d) * base + add);
}

int substringSearch(char str[], char substr[])
{
    const int strLen = strlen(str);
    const int substrLen = strlen(substr);
    const unsigned int d = power(base, substrLen - 1);

    unsigned int p = 0;
    unsigned int t = 0;
    hash(substr, str, substrLen, p, t);

    for (int i = 0; i <= strLen - substrLen; ++i)
    {
        if (p == t)
        {
            bool f = true;
            for (int j = 0; j < substrLen; ++j)
                if (substr[j] != str[i + j])
                {
                    f = false;
                    break;
                }
            if (f)
                return i;
        }
        if (i < strLen - substrLen)
            t = rehash(t, str[i], str[i + substrLen], d);
    }
    return -1;
}

int main()
{
    const int maxLen = 200;
    char str[maxLen];
    char substr[maxLen];

    clog << "A program for search for a substring in a string\n"
         << "Enter string: " << endl;
    cin.getline(str, maxLen);
    clog << "Enter substring: " << endl;
    cin.getline(substr, maxLen);
    
    int offset = substringSearch(str, substr);

    if (offset >= 0)
        cout << "Offset = " << offset << endl;
    else
        cout << "There is no substring" << endl;

    return 0;
}

