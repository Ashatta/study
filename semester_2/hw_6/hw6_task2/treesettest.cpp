#include "treetest.h"
#include "settest.h"
#include <iostream>

int main()
{
    TreeTest treetest;
    SetTest settest;
    std::cout << std::endl;
    QTest::qExec(&treetest);
    std::cout << std::endl;
    QTest::qExec(&settest);
    std::cout << std::endl;
    return 0;
}
