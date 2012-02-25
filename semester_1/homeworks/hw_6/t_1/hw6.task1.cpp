#include <iostream>
#include <string>
#include "binary_search_tree.h"

using namespace std;

const int commandsNum = 7;
const char commands[] = { 'a', 'r', '<', '>', '?', 'q', 'h' };

char correctCommand(string command) 
{                                  
    if (command.size() == 1)        
        for (int i = 0; i < commandsNum; ++i)
            if (command[0] == commands[i])
                return command[0];
    return 0;
}

void manage(Tree set)
{
    char ch = 0;
    string command;
    int value = 0;
    for (;;)
    {
        cin >> command;
        if (ch = correctCommand(command))
            switch (ch)
            {
                case 'a' :
                    cin >> value;
                    if (!set.hasKey(value))
                        set.insert(value);
                    break;
                case 'r' :
                    cin >> value;
                    if (set.hasKey(value))
                        set.remove(value);
                    else
                        clog << "There is no such value" << endl;
                    break;
                case '>' :
                    if (set.isEmpty())
                        clog << "The set is empty" << endl;
                    else
                        set.decPrint();
                    break;
                case '<' :
                    if (set.isEmpty())
                        clog << "The set is empty" << endl;
                    else
                        set.incPrint();
                    break;
                case '?' :
                    cin >> value;
                    if (set.hasKey(value))
                        cout << "Yes" << endl;
                    else
                        cout << "No" << endl;
                    break;
                case 'q' :
                    clog << "Bye!" << endl;
                    return;
                case 'h' :
                    clog << "You can use this commands:\n"
                         << "'a' [value] - add value to the set\n"
                         << "'r' [value] - remove value from the set\n"
                         << "'?' [value] - check if the set has key 'value'\n"
                         << "'<' - print the set in increasing order\n"
                         << "'>' - print the set in decreasing order\n"
                         << "'q' - quit\n"
                         << "'h' - print this help" << endl;
            }
        else
            cerr << "Wrong command. Try again" << endl;
    }
}

int main()
{
    clog << "Manage a set. Type 'h' for help" << endl;
    Tree set;
    manage(set);
    return 0;
}
