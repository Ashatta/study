#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    Node * list1 = create();
    Node * list2 = create();
    
    int current = 0;
    clog << "Enter the first pile (0 is end):" << endl;
    cin >> current;
    while (current)
    {
        pushBack(list1, current);
        cin >> current;
    }
    clog << "Enter the second pile (0 is end):" << endl;
    cin >> current;
    while (current)
    {
        pushBack(list2, current);
        cin >> current;
    }

    Node * tmp = list1->next;
    while (tmp != list1)
    {
        while (list2->next->value >= tmp->value)
        {
            tmp->prev->next = list2->next;
            list2->next->next->prev = list2;
            list2->next = list2->next->next;
            tmp->prev->next->next = tmp;
            tmp->prev->next->prev = tmp->prev;
            tmp->prev = tmp->prev->next;
        }
        tmp = tmp->next;
    }
    while (!isEmpty(list2))
    {
        pushBack(list1, front(list2));
        popFront(list2);
    }

    clog << "The common pile:" << endl;
    print(list1);

    remove(list1);
    remove(list2);
    
    return 0;
}

