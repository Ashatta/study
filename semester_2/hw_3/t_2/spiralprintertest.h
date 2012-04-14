#pragma once

#include <QtTest/QtTest>
#include "spiralprinter.h"
#include <sstream>
#include <string>

class SpiralPrinterTest: public QObject
{
    Q_OBJECT
private slots:
    void testPrint()
    {
        int ** matrix = new int*[5];
        for (int i = 0; i < 5; i++)
        {
            matrix[i] = new int[5];
            for (int j = 0; j < 5; j++)
                matrix[i][j] = i * 5 + j;
        }

        std::stringstream out;
        SpiralPrinter printer(out);
        printer.print(matrix, 5);
        std::string answer("12 13 18 17 16 11 6 7 8 9 14 19 24 23 22 21 20 15 10 5 0 1 2 3 4 \n");
        QCOMPARE(out.str(), answer);

        for (int i = 0; i < 5; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};
