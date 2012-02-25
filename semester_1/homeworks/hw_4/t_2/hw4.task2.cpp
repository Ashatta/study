#include <iostream>

using namespace std;

void outLevel(int **matrix, int n, int level)
{
    int center = n / 2;

    for (int i = center - level + 1; i < center + level; ++i)
        cout << matrix[i][center + level] << " ";  // вниз
    for (int i = center + level; i > center - level; --i)
        cout << matrix[center + level][i] << " ";  // влево
    for (int i = center + level; i > center - level; --i)
        cout << matrix[i][center - level] << " ";  // вверх
    for (int i = center - level; i <= center + level; ++i)
        cout << matrix[center - level][i] << " ";  // вправо
}

int main()
{
    clog << "The program prints elements of matrix N x N"
         << " in a spiral beginning from the central element\n"
         << "Enter N (N is odd) = ";
    int n = 0;
    cin >> n;

    if (!(n % 2))
    {
        cerr << "N is even" << endl;
        return 1;
    }
    
    int **matrix = new int*[n]; 
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[n];

    clog << "Elements" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    clog << "Spiral" << endl;
    for (int level = 0; level < n / 2 + 1; ++level)
        outLevel(matrix, n, level);
    cout << endl;

    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}

