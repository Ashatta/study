#include <iostream>

int main()
{
    const int numSums = 28;

    int a[numSums];
    for (int i = 0; i < numSums; ++i)
        a[i] = 0;

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 10; ++k)
                ++a[i + j + k];

    int tickets = 0;
    for (int i = 0; i < numSums; ++i)
        tickets += a[i] * a[i];
    
    std::cout << "The number of lucky tickets is " 
              << tickets << std::endl;

    return 0;
}

