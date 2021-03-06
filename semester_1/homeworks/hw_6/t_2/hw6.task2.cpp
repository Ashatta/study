#include <iostream>
#include <fstream>
#include <string>
#include "tree.h"

using namespace std;

int main()
{
    string inpName;
    clog << "The program prints and calculates an expression\n"
         << "in prefix notation\n"
         << "Enter a name of an input file: ";
    cin >> inpName;

    ifstream in(inpName.c_str());
    if (!in)
    {
        cerr << "Error reading from file" << endl;
        return 1;
    }

    Expression expression(in);

    clog << "Expression: ";
    expression.print();
    cout << endl;

    clog << "Result = ";
    cout << expression.calculate() << endl;

    return 0;
}

