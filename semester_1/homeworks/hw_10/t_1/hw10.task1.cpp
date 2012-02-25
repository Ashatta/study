#include <iostream>
#include <string>
#include "polynomial.h"

using namespace std;

const unsigned int size = 100;

unsigned int hash(string name)
{
    const int base = 0;
    unsigned int h = 0;
    for (int i = 0; i < name.size(); ++i)
        h = (h * base + name[i]) % size;
    return h;
}

unsigned int search(Polynomial * table, string name)
{
    unsigned int h = hash(name);
    for (int counter = 0; table[h].name() != name; ++counter)
    {
        if (counter == size)
            return size;
        h = ++h % size;
    }
    return h;
}

unsigned int freePos(Polynomial * table, string name)
{
    unsigned int h = hash(name);
    int counter = 0;
    while (table[h].name() != " ")
    {
        if (table[h].name() == name)
            return size;
        h = ++h % size;
        if (++counter == size)
            return size + 1;
    }
    return h;
}

int main(void)
{
    clog << "Work with polinoms. Type 'help' for help" << endl;

    Polynomial * table = new Polynomial[size];
    string command;
    string name1, name2, name3;
    unsigned int h = 0;
    unsigned int h1 = 0;
    unsigned int h2 = 0;
    double x = 0;

    while (true)
    {
        cout << "> ";
        cin >> command;
        if (command == "new")
        {
            cin >> name1;
            h = freePos(table, name1);
            int num = 1;
            if (h == size)
            {
                cerr << name1 << " already exists" << endl;
                while (num)
                    cin >> num;
            }
            else if (h == size + 1)
            {
                cerr << "There is no place for a new polynomial" << endl;
                while (num)
                    cin >> num;
            }
            else
            {
                table[h].setName(name1);
                cin >> table[h];
            }
        }
        else if (command == "delete")
        {
           cin >> name1;
           if ((h = search(table, name1)) < size) 
              table[h].remove();
        }
        else if (command == "equal")
        {
            cin >> name1 >> name2;
            if ((h1 = search(table, name1)) < size)
                if ((h2 = search(table, name2)) < size)
                    if (table[h1] == table[h2])
                        cout << "Equal" << endl;
                    else
                        cout << "Not equal" << endl;
                else
                    cerr << "There is no polynomial " << name2 << endl;
            else
                cerr << "There is no polynomial " << name1 << endl;
        } 
        else if (command == "value")
        {
            cin >> name1 >> x;
            if ((h = search(table, name1)) < size)
                cout << name1 << '(' << x << ") = " << table[h].calculate(x) << endl;
            else
                cerr << "There is no polynomial " << name1 << endl;
        }
        else if (command == "add")
        {
            cin >> name1 >> name2 >> name3;
            if ((h1 = search(table, name1)) < size)
                if ((h2 = search(table, name2)) < size)
                {
                    if ((h = freePos(table, name3)) < size)
                    {
                        table[h] = table[h1] + table[h2];
                        table[h].setName(name3);
                    }
                    else if (h == size)
                        cerr << "There already is polynomial " << name3 << endl;
                    else 
                        cerr << "There is no place for a new polynomial " << endl;
                }
                else
                    cerr << "There is no polynomial " << name2 << endl;
            else 
                cerr << "There is no polynomial " << name1 << endl;
        }
        else if (command == "print")
        {
            cin >> name1;
            if ((h = search(table, name1)) == size)
                cerr << "There is no polynomial " << name1 << endl;
            else
                table[h].print();
        }
        else if (command == "printall")
        {
            for (int i = 0; i < size; ++i)
                if (table[i].name() != " ")
                    table[i].print();
        }
        else if (command == "exit")
        {
            clog << "Goodbye!" << endl;
            delete[] table;
            return 0;
        }
        else if (command == "help")
            clog << "Commands:\n" 
                 << "new name [coeff1 power1 ..] 0 - add a new polynomial named 'name'\n"
                 << "delete name - delete a polynomial\n"
                 << "equal name1 name2 - check whether polynomials name1 and name2 are equal\n"
                 << "add name1 name2 name3 - add name1 to name2, result is name3\n"
                 << "value name x - calculate value of polynomial name at x\n"
                 << "print name - print a polynomial name in format name [coeff1 power1 ..]\n"
                 << "printall - print all polynomials\n"
                 << "help - display this help\n"
                 << "exit" << endl;
        else
            cerr << "Wrong command. Try again" << endl;
    }
}

