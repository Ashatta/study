#include <iostream>
#include <sstream>
#include "polish_conv.h"
#include "polish_calc.h"

using namespace std;

int main()
{
    clog << "The programs calculates an expression\n"
         << "Enter an expression (Ctrl+D to end an input):" << endl;   
    stringstream buf;

    try
    {
        convertToPolish(cin, buf);
    }
    catch (incorrectInput e)
    {
        cerr << e.what() << endl;
        return 1;
    } 

    int result = calculate(buf);
    cout << "Result = " << result << endl;

    return 0;
}

