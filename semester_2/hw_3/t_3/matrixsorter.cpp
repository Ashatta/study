#include "matrixsorter.h"

void MatrixSorter::qSort(int ** a, int n, int left, int right)
{
    if (left < right)
    {
        int i = left - 1;
        for (int j = left; j < right; j++)
            if (a[0][j] <= a[0][right])
            {
                ++i;
                for (int k = 0; k < n; k++)
                    swap(a[k][i], a[k][j]);
            }
        ++i;
        for (int k = 0; k < n; k++)
            swap(a[k][i], a[k][right]);
        qSort(a, n, left, i - 1);
        qSort(a, n, i + 1, right);
    }
}
    
