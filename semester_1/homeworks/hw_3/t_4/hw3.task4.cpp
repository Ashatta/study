#include <iostream>
#include "list.h"

using namespace std;

Node * merge(Node * first, Node * second)
{
    Node * res = create();
    while (!isEmpty(first) || !isEmpty(second))
    {
        while (!isEmpty(first) && 
                (isEmpty(second) ||
                  first->next->value <= second->next->value))
            pushBack(res, popFront(first));
        while (!isEmpty(second) && 
                (isEmpty(first) || 
                  second->next->value <= first->next->value))
            pushBack(res, popFront(second));
    } 

    remove(first);
    remove(second);
    return res;
}

Node * mergeSort(Node * list, int len)
{
    if (len > 1)
    {
        int odd = len % 2;
        len /= 2;
        
        Node * leftHalf = create();
        for (int i = 0; i < len; ++i)
            pushBack(leftHalf, popFront(list));

        leftHalf = mergeSort(leftHalf, len);
        list = mergeSort(list, len + odd);

        return merge(leftHalf, list);
    }
    return list;
}

int main()
{
    clog << "The program sorts a list\n"
         << "Enter the elements" << endl;

    Node * list = create();

    int x = 0;
    cin >> x;
    while (!cin.eof())
    {
        pushBack(list, x);
        cin >> x;
    }

    int len = length(list);
    list = mergeSort(list, len);

    clog << "The sorted list" << endl;
    print(list);

    remove(list);

    return 0;
}

