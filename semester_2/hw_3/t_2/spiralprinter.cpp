#include "spiralprinter.h"
#include <iostream>

void SpiralPrinter::outLevel(int **matrix, int n, int level)
{
        int center = n / 2;

        for (int i = center - level + 1; i < center + level; ++i)
            out << matrix[i][center + level] << " "; // вниз
        for (int i = center + level; i > center - level; --i)
            out << matrix[center + level][i] << " "; // влево
        for (int i = center + level; i > center - level; --i)
            out << matrix[i][center - level] << " "; // вверх
        for (int i = center - level; i <= center + level; ++i)
            out << matrix[center - level][i] << " "; // вправо

        return;
}

void SpiralPrinter::print(int ** matrix, int n)
{
    if (!(n % 2))
        throw EvenMatrixSizeException();
                    
    for (int level = 0; level < n / 2 + 1; ++level)
        outLevel(matrix, n, level);
    out << std::endl;
    return;
}

