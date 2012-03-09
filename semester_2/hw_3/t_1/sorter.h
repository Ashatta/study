#pragma once

class Sorter
{
    public:
        virtual void sort(int a[], int n) = 0;
    protected:
        void swap(int &a, int &b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
};

