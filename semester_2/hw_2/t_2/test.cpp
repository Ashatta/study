#include <iostream>
#include "linkedlist.h"
#include "arraylist.h"

using namespace std;

int main()
{
    List* list[2];
    list[0] = new LinkedList();
    list[1] = new ArrayList();

    for (int j = 0; j < 2; j++)
    {
        cout << "Check of list " << j + 1 << endl;
        if (list[j]->isEmpty())
            cout << "Empty. ";
        else
            cout << "Not empty. ";
        cout << "Length = " << list[j]->length() << '\n' << endl;

        for (int i = 0; i < 10; ++i)
            list[j]->insert(i, list[j]->length());

        list[j]->print();

        if (list[j]->isEmpty())
            cout << "Empty. ";
        else
            cout << "Not empty. ";
        cout << "Length = " << list[j]->length() << endl;

        if (list[j]->hasValue(8))
            cout << "The 8 is here" << endl;
        else
            cout << "The 8 is missing" << endl;

        cout << "The position of 9 is " << list[j]->find(9) << '\n' << endl;

        list[j]->removeAt(7);
        cout << "7-th element is removed" << endl;
        cout << "Length = " << list[j]->length() << endl;
        list[j]->print();
        cout << endl;
        list[j]->remove(8);
        cout << "8 is removed" << endl;
        cout << "Length = " << list[j]->length() << endl;
        list[j]->print();

        if (list[j]->hasValue(8))
            cout << "The 8 is here" << endl;
        else
            cout << "The 8 is missing" << endl;

        cout << "The position of 9 is " << list[j]->find(9) << '\n' << endl;

        
        list[j]->insert(200, 5);
        cout << "200 inserted into pos 5. Length = " << list[j]->length() << endl;
        list[j]->print();
        cout << endl;

        list[j]->removeAt(10);
        cout << "10-th element is removed. Length = " << list[j]->length() << endl;
        list[j]->print();
        cout << endl;

        list[j]->remove(10);
        cout << "10 is removed. Length = " << list[j]->length() << endl;

        list[j]->print();
        cout << endl;

        list[j]->insert(30, 20);
        cout << "30 inserted into pos 20. Length = " << list[j]->length() << endl;
        list[j]->print();
        cout << endl;

    }

    delete list[0];
    delete list[1];
    return 0;
}

