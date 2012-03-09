#pragma once
#include "sorter.h"

class QSorter : public Sorter
{
    public:
        void sort(int a[], int n) 
        { 
            qSort(a, 0, n - 1); 
            return; 
        }
    protected:
        void swap(int &a, int &b);
    private:
        void qSort(int a[], int left, int right);
};
