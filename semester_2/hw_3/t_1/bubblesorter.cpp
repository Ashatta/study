#include "bubblesorter.h"

void BubbleSorter::sort(int a[], int n)
{
    bool f = true;
    while (f)
    {
        f = false;
        for (int i = 0; i < n - 1; ++i)
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                f = true;
            }
    }
}
