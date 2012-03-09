#include <iostream>
#include <cstdlib>
#include "matrixsorter.h"

const int n = 10;
const int m = 10;

using namespace std;

int ** createMatrix()
{
    int ** a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 90 + 10;
    }
    return a;
}

void printMatrix(int ** a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

void deleteMatrix(int ** a)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

int main()
{
    int ** a = createMatrix();
    printMatrix(a);
    cout << endl;
    MatrixSorter::sort(a, n, m);
    printMatrix(a);
    deleteMatrix(a);
    return 0;
}

