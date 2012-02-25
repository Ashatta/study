#include <cstdio>

int main()
{
    int n = 0;
    printf("The program calculates all prime numbers that are%s ",
           "lesser or equal n\nn = ");
    scanf("%d", &n);
    bool * a = new bool[n + 1];
    for (int i = 0; i <= n; ++i)
        a[i] = true;
    
    for (int p = 2; p <= n; ++p)
        for (int i = 2 * p; i <= n; i += p)
            a[i] = false;

    for (int i = 2; i <= n; ++i)
        if (a[i])
            printf("%d ", i);
    putchar('\n');

    delete[] a;

    return 0;
} 

