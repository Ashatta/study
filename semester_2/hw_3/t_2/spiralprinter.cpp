#include "spiralprinter.h"
#include <iostream>

void SpiralPrinter::outLevel(int **matrix, int n, int level)
{
    int center = n / 2;
    /** Level printing starts with 
     * the element below the right-up corner
     */
    for (int i = center - level + 1; i < center + level; ++i)
        out << matrix[i][center + level] << " "; // down
    for (int i = center + level; i > center - level; --i)
        out << matrix[center + level][i] << " "; // left
    for (int i = center + level; i > center - level; --i)
        out << matrix[i][center - level] << " "; // up
    for (int i = center - level; i <= center + level; ++i)
        out << matrix[center - level][i] << " "; // right

    return;
}

void SpiralPrinter::print(int ** matrix, int n)
{
    if (!(n % 2))
        throw EvenMatrixSizeException();

    /** Printing matrix by "levels": "level" is a number of
     *  elements between central one and the one that must
     *  be printed at the moment
     *  For example, matrix 5x5 has three levels: 0, 1 and 2
     */
    for (int level = 0; level < n / 2 + 1; level++)
        outLevel(matrix, n, level);
    out << std::endl;
    return;
}

