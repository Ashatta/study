#pragma once

template<class T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
void qSort(T a[], int left, int right)
{
    if (left < right)
    {
        int i = left - 1;
        for (int j = left; j < right; ++j)
            if (a[j] <= a[right])
            {
                ++i;
                swap(a[i], a[j]);
            }
        ++i;
        swap(a[i], a[right]);
        qSort(a, left, i - 1);
        qSort(a, i + 1, right);
    }
}

