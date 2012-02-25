#include <iostream>
#include "bubble.h"

using namespace std;

int main()
{
    clog << "The program sorts an array\n"
         << "Enter a number of elements\nn = ";
    int n = 0;
    cin >> n;
    int * array = new int[n];
    clog << "Enter elements" << endl;
    for (int i = 0; i < n; ++i)
        cin >> array[i];

    bubbleSort(array, n);

    clog << "Sorted array" << endl;
    for (int i = 0; i < n; ++i)
        cout << array[i] << ' ';
    cout << endl;

    delete[] array;
    return 0;
}

