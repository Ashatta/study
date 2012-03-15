#include <iostream>
#include <ctime>
#include <cstdlib>
#include "matrix.h"

Matrix::Matrix(int size)
    : mSize(size)
{
    srand(time(NULL));
    matrix = new int*[mSize];
    for (int i = 0; i < mSize; i++)
    {
        matrix[i] = new int[mSize];
        for (int j = 0; j < mSize; j++)
            matrix[i][j] = rand() % 90 + 10;
    }
}

void Matrix::print(std::ostream &out)
{
    for (int i = 0; i < mSize; i++)
    {
        for (int j = 0; j < mSize; j++)
            out << matrix[i][j] << ' ';
        out << std::endl;
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < mSize; i ++)
        delete[] matrix[i];
    delete[] matrix;
}

