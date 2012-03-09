#pragma once
#include "sorter.h"

class BubbleSorter : public Sorter
{
    public:
        void sort(int a[], int n);
    protected:
        void swap(int &a, int &b);
};
