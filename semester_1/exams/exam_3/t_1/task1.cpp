#include <iostream>
#include "binary_search_tree.h"

using namespace std;

int main()
{
    clog << "The program counts numbers in the input sequence "
         << "and prints numbers and number of appearing for each one\n"
         << "Type the numbers:" << endl;
    int number = 0;
    Tree t;
    cin >> number;
    while (number)
    {
        t.insert(number);
        cin >> number;
    }
    clog << "The second number is a number of appearing" << endl;
    t.incPrint();
    return 0;
}

