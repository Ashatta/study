#include <cstdio>

int main()
{
    int n = 0;
    printf("This program calculates n! using iterations\nn = ");
    scanf("%d", &n);

    int fact = 1;
    for (int i = n; i > 0; --i)
        fact *= i;

    printf("%d! = %d\n", n, fact);

    return 0;
}
