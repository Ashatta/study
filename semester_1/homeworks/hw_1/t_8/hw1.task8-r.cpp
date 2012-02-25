#include <cstdio>

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    int n = 0;
    printf("This program recursively calculates n!\nn = ");
    scanf("%d", &n);

    printf("%d! = %d\n", n, fact(n));

    return 0;
}

