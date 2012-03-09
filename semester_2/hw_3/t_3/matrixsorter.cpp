#include "matrixsorter.h"

void MatrixSorter::qSort(int ** a, int n, int left, int right)
{
    if (left >= right)
        return;

    int i = left - 1;
    for (int j = left; j <= right; j++)
        if (*(a[j]) <= *(a[right]))
            swap(a[++i], a[j]);

    qSort(a, n, left, i - 1);
    qSort(a, n, i + 1, right);
}
    
