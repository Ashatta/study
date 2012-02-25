#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "tree.h"

const int size = 4999;
const int wordSize = 50;

using namespace std;

int hash(char word[])
{
    const int base = 13;
    const int len = strlen(word);

    int h = 0;
    for (int i = 0; i < len; ++i)
        h = (h * base + word[i]) % size;
    return h;
}

void getWord(char word[], ifstream &in)
{
    char ch = in.get();
    while (!in.eof() && !isalpha(ch))
        ch = in.get();
    int len = 0;
    while (!in.eof() && isalpha(ch))
    {
        word[len++] = tolower(ch);
        ch = in.get();
    }
    word[len] = '\0';
}

int main(void)
{
    Tree * table = new Tree[size];

    string input;
    clog << "The program counts words in a file\n"
         << "Enter a name of the input file: ";
    cin >> input;
    ifstream in(input.c_str());
    if (!in)
    {
        cerr << "File not found" << endl;
        return 1;
    }

    char word[wordSize];
    getWord(word, in);
    while (!in.eof())
    {
        int h = hash(word);
        table[h].add(word);
        getWord(word, in);
    }

    for (int i = 0; i < size; ++i)
        table[i].print();

    delete[] table;
    in.close();
    return 0;
}

