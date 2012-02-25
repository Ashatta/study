#include <iostream>

using namespace std;

void outPartition(int a[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void partition(int n, int max, int a[], int size)
{
    if (n)
    {
        if (max > n)
            max = n;
        for (int i = max; i > 0; --i)
        {
            a[size] = i;
            partition(n - i, i, a, size + 1);
        }
    }
    else
        outPartition(a, size);
}

int main()
{
    clog << "The program prints all partitions of N\n"
         << "N = ";
    int n = 0;
    cin >> n;
    
    int * parts = new int[n];

    clog << "Partitions:" << endl;
    partition(n, n, parts, 0);

    delete[] parts;

    return 0;
}

