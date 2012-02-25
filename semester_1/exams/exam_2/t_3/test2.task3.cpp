#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

int main()
{
    ifstream in("input");
    if (!in)
    {
        cerr << "Error reading from file" << endl;
        return 1;
    }

    ofstream out("output");
    clog << "The program reads integers from file and "
         << "breaks them to three groups:\nlesser than a, "
         << "between a and b, bigger than b\n"
         << "Enter a and b:" << endl;
    int a = 0;
    int b = 0;
    cin >> a >> b;

    Node * lesser = create();
    Node * bigger = create();
    Node * between = create();

    int current = 0;
    in >> current;
    while (!in.eof())
    {
        if (current < a)
            pushBack(lesser, current);
        else if (current > b)
            pushBack(bigger, current);
        else
            pushBack(between, current);
        in >> current;
    }

    print(lesser, out);
    print(between, out);
    print(bigger, out);

    remove(lesser);
    remove(between);
    remove(bigger);

    clog << "Done. See the result in \"output\"" << endl;

    in.close();
    out.close();

    return 0;
}

