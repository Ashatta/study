#include <cstdio>

int main()
{
    double x = 0;
    
    printf("This program calculates x^4 + x^3 + x^2 + x + 1%s",
           " with just two multiplication operations\nx = ");
    scanf("%lf", &x);

    double sqrx = x * x;
    printf("x^4 + x^3 + x^2 + x + 1 =  %.2lf\n",
           (x + sqrx) * (sqrx + 1) + 1);

    return 0;
}

