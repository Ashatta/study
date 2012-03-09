#include <iostream>
#include "stackmachine.h"

using namespace std;

int main()
{
    clog << "Console calculator: type an expression in postfix notation"
         << endl;
    StackMachine calculator;
    int result = calculator.calculate(cin);
    clog << "Result = ";
    cout << result << endl;
    return 0;
}

