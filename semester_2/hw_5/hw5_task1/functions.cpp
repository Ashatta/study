#include "functions.h"

int hFunc1(const std::string &str)
{
    return str[0] * str[str.length() - 1] + str.length();
}

int hFunc2(const std::string &str)
{
    const int mod = 1433;
    const int base = 13;
    
    int hash = 0;
    for (unsigned int i = 0; i < str.length(); i++)
        hash = (str[i] * base + hash) % mod;
    return hash;
}

