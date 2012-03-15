#pragma once
#include <iostream>

class Matrix
{
public:
    Matrix(int size); // initializing with random numbers
    ~Matrix();
    void print(std::ostream &out);
    int * operator[](int i) { return matrix[i]; }
    int size() { return mSize; }

private:
    int mSize;
    int ** matrix;

friend class SpiralPrinter;
};
