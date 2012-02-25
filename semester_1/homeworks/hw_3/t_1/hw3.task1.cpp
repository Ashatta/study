#include <iostream>
#include "sort.h"

using namespace std;

int maxTwiceSeen(int a[], int size)
{
    qSort(a, 0, size - 1);

    for (int i = size - 1; i > 0; --i)
        if (a[i] == a[i - 1])
            return i;
    return -1;
}

int main()
{
    int size = 0;
    clog << "The program looks for the max element "
         << "that appears in the input array more than once\n"
         << "Enter an array's size" << endl;
    cin >> size;
    int * array = new int[size];
    clog << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; ++i)
        cin >> array[i];
    
    int elemNum = maxTwiceSeen(array, size);
    
    if (elemNum < 0)
    {
        cerr << "There is no wanted element" << endl;
        return 1;
    }
    clog << "Wanted element is ";
    cout << array[elemNum] << endl;

    delete[] array;

    return 0;
}

