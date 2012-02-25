#include <iostream>
#include <cstring>

using namespace std;

int substringNum(char sub[], char str[])
{
    int len = strlen(str);
    int len1 = strlen(sub);
    int n = 0;
    
    for (int i = 0; i < len - len1 + 1; ++i)
    {
        int j = 0;
        while (j < len1 && str[i + j] == sub[j])
            ++j;
        if (j == len1)
            ++n;
    }

    return n;
}

int main()
{
    const int maxLen = 200;
    char s[maxLen]; 
    char s1[maxLen];

    cin.getline(s, maxLen);
    cin.getline(s1, maxLen);

    int n = substringNum(s1, s);

    cout << n << endl;

    return 0;
}

