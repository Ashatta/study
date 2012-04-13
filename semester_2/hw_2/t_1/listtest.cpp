#include "listtest.h"
#include <iostream>

int const numOfLists = 2;

int main()
{
    std::cout << '\n' << std::endl;

    ListTest* listtests[numOfLists];

    listtests[0] = new ArrayListTest();
    listtests[1] = new LinkedListTest();

    for (int i = 0; i < numOfLists; i++)
    {
        QTest::qExec(listtests[i]);
        std::cout << '\n' << std::endl;
    }

    return 0;
}
