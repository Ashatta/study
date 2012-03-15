#include "spiralprinter.h"
#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char ** argv)
{
    int n = 0;
    clog << "Printing matrix as a spiral starting with\n"
         << "central element. Use './hw3.task2 filename\n'"
         << "to put a result in a file.\n"
         << "Type the size of the matrix (odd) n = ";
    cin >> n;
    if (!(n % 2))
    {
        cerr << "Cannot find the central element in a matrix of even size" << endl;
        return 1;
    }
    
    Matrix matrix(n);

    if (argc > 1) // if a user gave a name of an output file
    {
        ofstream out(argv[1]);

        matrix.print(out);
        SpiralPrinter printer(out);
        printer.print(matrix);

        out.close();
    }
    else
    {
        matrix.print(cout);
        SpiralPrinter printer(cout);
        printer.print(matrix);
    }
        
    return 0;
} 

