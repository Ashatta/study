#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
    int n = 0;
    clog << "The program sorts an array\nEnter the length of an array n = ";
    cin >> n;
    int * a = new int[n];
    clog << "Enter the elements" << endl;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    qSort(a, 0, n - 1);

    clog << "The sorted array" << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    delete[] a;

    return 0;
}

