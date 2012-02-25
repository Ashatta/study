#pragma once

template<class T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
void bubbleSort(T a[], int n)
{
    bool f = 1;
    while (f)
    {
        f = 0;
        for (int i = 0; i < n - 1; ++i)
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                f = 1;
            }
    }
}

