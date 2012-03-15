#pragma once
#include "matrix.h"
#include <iostream>

class EvenMatrixSizeException {};

class SpiralPrinter
{
public:
    SpiralPrinter(std::ostream &os)
        : out(os)
    {}

    void print(int ** matrix, int n);
    void print(Matrix &matrix)
    {
        print(matrix.matrix, matrix.mSize);
        return;
    }

private:
    void outLevel(int ** matrix, int n, int level);
    std::ostream &out;
};

