#include "stringhashers.h"

int StringHasher1::hash(std::string const &str)
{
    if (str.length() == 0)
        return 0;
    else
        return str[0] * str[str.length() - 1] + str.length();
}

int StringHasher2::hash(std::string const &str)
{
    const int mod = 1433;
    const int base = 13;
    
    int h = 0;
    for (unsigned int i = 0; i < str.length(); i++)
        h = (str[i] * base + h) % mod;
    return h;
}

