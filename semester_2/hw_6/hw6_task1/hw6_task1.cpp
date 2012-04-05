#include <iostream>
#include <fstream>
#include <string>
#include "expression.h"

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

    cout << "Expression: ";
    expression.print(cout);
    cout << endl;

    cout << "Result = " << expression.calculate() << endl;

    return 0;
}

