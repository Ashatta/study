#include <cstdio>

int fib(int n)
{
    int f1 = 1;
    int f2 = 1;

    for (int i = 3; i <= n; ++i)
    {
        int tmp = f2;
        f2 += f1;
        f1 = tmp;
    }

    return f2;
}

int main()
{
    int n = 0;
    printf("The program calculates n-th Fibonacci number\nn = ");
    scanf("%d", &n);
    
    printf("The %d-th Fibonacci number is %d ", n, fib(n));
    putchar('\n');

    return 0;
}

