#include <iostream> 
#include <fstream>
#include "tree.h"

using namespace std;
    
const int maxLen = 1000;
const int size = 1499;

int hash(char * string)
{
    const int base = 13;
    const int len = strlen(string);

    unsigned int h = 0;
    for (int i = 0; i < len; ++i)
        h = (h * base + string[i]) % size;
    return h;
}

int main(int argc, char * argv[])
{
    if (argc < 3)
    {
        cerr << "Use: ./hw9.task1 inputfile1 inputfile2 [outputfile]" << endl;
        return 1;
    }

    ifstream inFirst(argv[1]);
    ifstream inSecond(argv[2]);
    if (!inFirst || !inSecond)
    {
        cerr << "Error reading from file" << endl;
        return 2;
    }

    string output;
    if (argc > 3)
        output = argv[3];
    else
        output = "output";
    ofstream out(output.c_str());
    
    Tree * table = new Tree[size];
    char string[maxLen];
    inFirst.getline(string, maxLen);
    int h = 0;
    while (!inFirst.eof())
    {
        if (string[0] != '\0')
        {
            h = hash(string);
            table[h].add(string);
        }
        inFirst.getline(string, maxLen);
    }

    inSecond.getline(string, maxLen);
    while (!inSecond.eof())
    {
        if (string[0] != '\0')
        {
            h = hash(string);
            if (table[h].hasString(string))
                out << string << endl;
        }
        inSecond.getline(string, maxLen);
    }

    delete[] table;
    inFirst.close();
    inSecond.close();
    out.close();
    clog << "Done! See the result in " << output << endl;
    return 0;
}

