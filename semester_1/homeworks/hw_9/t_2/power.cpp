#include <cstdlib>
#include "power.h"

double power(double a, int n)
{
    if (!a)
        return 0;

    bool positiveN = n >= 0;
    n = abs(n);

    double pow = 1;
    while (n)
    {
        if (n & 1)
            pow *= a;
        a *= a;
        n >>= 1;
    }

    if (positiveN)
        return pow;
    return 1. / pow;
}


