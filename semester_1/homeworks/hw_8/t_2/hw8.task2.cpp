#include <iostream>
#include <fstream>
#include <string>
#include "qsort.h"

const int infinity = 2e9;

using namespace std;

struct City
{
    int number;
    int distance;
};

int ** getMap(int n, int m, ifstream &in)
{
    int ** map = new int*[n];
    for (int i = 0; i < n; ++i)
        map[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            map[i][j] = infinity;
    int i = 0;
    int j = 0;
    int len = 0;
    for (int k = 0; k < m; ++k)
    {
        in >> i >> j >> len;
        map[i - 1][j - 1] = len;
        map[j - 1][i - 1] = len;
    } 
    return map;
}

inline bool operator <=(City first, City second)
{
    return first.distance <= second.distance;
}

void init(bool * seen, City * dst, int n)
{
    for (int i = 1; i < n; ++i)
    {
        seen[i] = false;
        dst[i].distance = infinity;
        dst[i].number = i + 1;
    }
    seen[0] = false;
    dst[0].distance = 0;
    dst[0].number = 1;
}

int nearest(City * dst, bool * seen, int n)
{
    int min = 0;
    for (int i = 1; i < n; ++i)
        if (!seen[i] && (seen[min] || dst[i].distance < dst[min].distance))
            min = i;
    return min;
}    

void shortestPaths(int ** map, City * dst, bool * seen, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int w = nearest(dst, seen, n);
        seen[w] = true;
        for (int j = 1; j < n; ++j)
            if (!seen[j])
                if (dst[j].distance > dst[w].distance + map[w][j])
                    dst[j].distance = dst[w].distance + map[w][j];
    }
}

void del(int ** map, bool * seen, City * dst, int n)
{
    delete[] seen;
    delete[] dst;
    for (int i = 0; i < n; ++i)
        delete[] map[i];
    delete[] map;
}
    
int main()
{
    string input;
    clog << "The name of the input file: ";
    cin >> input;
    ifstream in(input.c_str());
    if (!in)
    {
        cerr << "Error reading from file" << endl;
        return 1;
    }

    int n = 0;
    int m = 0;
    in >> n >> m;
    int ** map = getMap(n, m, in);
    bool * seen = new bool[n];
    City * dst = new City[n];
    init(seen, dst, n);

    shortestPaths(map, dst, seen, n);

    qSort(dst, 0, n - 1);

    clog << "These are the numbers of cities in order of capture "
         << "and the distances from them\nto the city 1" << endl;
    for (int i = 0; i < n; ++i)
        cout << dst[i].number << ' ' << dst[i].distance << endl;

    del(map, seen, dst, n);
    in.close();
    return 0;
}

