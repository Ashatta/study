#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int locate(string word, char c)
{
    for (int i = 0; i < word.size(); ++i)
        if (word[i] == c)
            return i;
    return -1;
}

int main()
{
    ifstream text("input");
    if (!text)
    {
        cerr << "Error reading a file" << endl;
        return 1;
    } 
    while (!text.eof())
    {
        char c = text.get();
        while ((isspace(c) || ispunct(c)) && !text.eof())
            c = text.get();
        string word;
        while (!(isspace(c) || ispunct(c) || text.eof()))
        {
            if (locate(word, c) < 0)
                word += c;
            c = text.get();
        }
        cout << word << endl;
    }
    text.close();
    return 0;
}
            
