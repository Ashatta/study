#include <iostream>
#include "list.h"

using namespace std;

Node * sortedInsert(Node * list, Node * target, int value)
{
    if (isEmpty(list))
    {
        pushFront(list, value);
        return target->next;
    }
    
    if (value > target->value) 
    {
        while (list != target && value > target->value)
            target = target->next;
        target = target->prev;
    }
    while (list != target && value < target->value)
        target = target->prev;
    Node * newNode = new Node(target, target->next, value);
    return newNode;
}

void removeValue(Node * list, int value)
{
    Node * tmp = list->next;

    while (tmp != list && tmp->value != value)
        tmp = tmp->next;

    if (tmp == list)
        cerr << "This value doesn't exist" << endl;
    else
    {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;
    }
}

void manageList()
{
    Node * list = create();
    Node * target = list; 
    int command = 0;
    int value = 0;

    while (1)
    {
        cin >> command;
        switch (command) {
            case 0: 
                clog << "Goodbye!" << endl;
                remove(list);
                return;
            case 1:
                clog << "Enter a value to add ";
                cin >> value;
                target = sortedInsert(list, target, value);
                break;
            case 2:
                if (isEmpty(list))
                    cerr << "List is already empty" << endl;
                else
                {
                    clog << "Enter a value to remove ";
                    cin >> value;
                    removeValue(list, value);
                }
                break;
            case 3: 
                if (isEmpty(list))
                    cout << "Empty" << endl;
                else
                    print(list);
                break;
            default:
                cerr << "Incorrect command. Try again" << endl;
        }
    }
}

int main()
{
    clog << "You can manage the sorted list. "
         << "Use this commands:\n"
         << "0 - exit\n"
         << "1 - add value to the list\n"
         << "2 - remove value from the list\n"
         << "3 - print list" << endl;

    manageList();

    return 0;
}
