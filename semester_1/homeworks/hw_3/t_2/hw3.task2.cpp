#include <iostream>
#include "list.h"

using namespace std;

bool isK(int k, int len, int last)
{
    Node * list = create();
    for (int i = 0; i < len; ++i)
        pushBack(list, i + 1);

    int del = k - 1;
    while (len > 1)
    {
        erase(list, del);
        del = (del + k - 1) % --len;
    }
    
    int lastValue = list->next->value;
    remove(list);
    
    return lastValue == last;
}

int main()
{
    clog << "\"Counting-out\": on each step "
         << "the K-th element of circularly list\n"
         << "is removed until only one element (i-th) left.\n"
         << "The program restores K by given i and the number\n"
         << "of elements of list.\n"
         << "Number of elements = ";
    
    int n = 0;
    cin >> n;
    int last = 0;
    clog << "Number of the last element = ";
    cin >> last;

    Node * listOfK = create();
    for (int i = 1; i <= n; ++i)
    {
        if (isK(i, n, last))
            pushBack(listOfK,i);
    }

    if (isEmpty(listOfK))
    {
        cerr << "There is no such K" << endl;
        remove(listOfK);
        return 1;
    }

    clog << "All possible K's" << endl;
    print(listOfK);
    remove(listOfK);

    return 0;
}
