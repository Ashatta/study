#include <iostream>

using namespace std;

int main()
{
    int m = 0;
    int n = 0;
    clog << "Search for a saddle point in matrix m x n"
         << " (one for a row)\nm = ";
    cin >> m;
    clog << "n = ";
    cin >> n;

    int ** array = new int*[m];
    bool ** result = new bool*[m];
    for (int i = 0; i < m; ++i)
    {
        array[i] = new int[n];
        result[i] = new bool[n];
        for (int j = 0; j < n; ++j)
        {
            array[i][j] = 0;
            result[i][j] = false;
        }
    }
            
    clog << "Elements: " << endl;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> array[i][j];

    int jtarg = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
            if (array[i][j] <= array[i][jtarg])
                jtarg = j;
        for (int j = 1; j < m; ++j)
        {
            if (array[j][jtarg] >= array[i][jtarg])
                continue;
            result[i][jtarg] = true;
        }
        jtarg = 0;
    }

    clog << "The first number is number of row, the second one " 
         << "is the number of column,\n"
         << "The third number is a value of saddle point" << endl;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (result[i][j])
                cout << i + 1 << ' ' << j + 1 << ' ' << array[i][j] << endl;

    for (int i = 0; i < m; ++i)
    {
        delete[] array[i];
        delete[] result[i];
    }
    delete[] array;
    delete[] result;

    return 0;
}

