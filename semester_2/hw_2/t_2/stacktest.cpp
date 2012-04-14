#include "stacktest.h"
#include "stackmachinetest.h"
#include <iostream>

int const numOfStacks = 2;

int main()
{
    StackTest* stacktests[numOfStacks];

    stacktests[0] = new ArrayStackTest();
    stacktests[1] = new LinkedStackTest();
    for (int i = 0; i < numOfStacks; i++)
    {
        std::cout << std::endl;
        QTest::qExec(stacktests[i]);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    StackMachineTest machineTest;
    QTest::qExec(&machineTest);

    std::cout << std::endl;
    return 0;
}
