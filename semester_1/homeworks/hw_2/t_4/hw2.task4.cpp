#include <iostream>

using namespace std;

struct Frac {
    int num;
    int denom;
};

struct FracNode {
    Frac value;
    FracNode * next;
};

FracNode * createNode(int num, int denom)
{
    FracNode * newNode = new FracNode;

    newNode->value.num = num;
    newNode->value.denom = denom;
    newNode->next = NULL;

    return newNode;
}

void insertFraction(FracNode * list, int pos, int num, int denom)
{
    FracNode * tmp = list;

    int i = 0;
    while (i < pos && tmp)
    {
        ++i;
        tmp = tmp->next;
    }

    FracNode * newNode = createNode(num, denom);
    newNode->next = tmp->next;
    tmp->next = newNode;
}

FracNode * makeFractionsList(int denom)
{
    FracNode * list = createNode(0, 0);
    insertFraction(list, 0, 0, 1);
    insertFraction(list, 1, 1, 1);

    for (int i = 1; i < denom; ++i)
    {
        FracNode * tmp = list->next;
        int j = 1;
        while (tmp->next)
        {
            int newNum = tmp->value.num + tmp->next->value.num;
            int newDenom = tmp->value.denom + tmp->next->value.denom;
            if (newDenom <= denom)
            {
                insertFraction(list, j, newNum, newDenom);
                tmp = tmp->next;
                ++j;
            }
            ++j;
            tmp = tmp->next;
        }
    }

    return list;
}    

void deleteList(FracNode * list)
{
    if (list->next)
        deleteList(list->next);
    delete list;
}

void outFractions(FracNode * list)
{
    FracNode * tmp = list;
    while (tmp->next)
    {
        tmp = tmp->next;
        if (tmp->value.denom == 1)
            cout << tmp->value.num << " ";
        else
            cout << tmp->value.num << "/" << tmp->value.denom << " ";
    }
    cout << endl;
}

int main()
{
    int denominator = 0;
    clog << "The program writes all the fractions between 0 and 1 "
         << "with denominator less or equal N\nN = ";
    cin >> denominator;
    
    if (denominator <= 0)
    {
        cerr << "Invalid denominator value" << endl;
        return 1;
    }
    
    FracNode * list = makeFractionsList(denominator);

    clog << "The fractions sequence" << endl;
    outFractions(list);

    deleteList(list);

    return 0;
} 

