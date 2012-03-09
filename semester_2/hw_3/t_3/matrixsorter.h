#pragma once

class MatrixSorter
{
    public:
        static void sort(int ** matrix, int n, int m)
        {
            qSort(matrix, n, 0, m - 1);
            return;
        }
    private:
        static void qSort(int ** matrix, int n, int left, int right);
        static void swap(int &a, int &b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        } 
};

