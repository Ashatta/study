#include <QtGui/QApplication>
#include "simplecalculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleCalculator w;
    w.show();
    
    return a.exec();
}
