#include <cstdio>

int fib(int n)
{
    if ((n == 1) || (n == 2))
        return 1;
    return (fib(n - 1) + fib(n - 2));
}

int main()
{
    int n = 0;
    printf("The program calculates the n-th Fibonacci number\nn = ");
    scanf("%d", &n);
    
    printf("The %d-th Fibonacci number is %d\n", n, fib(n));

    return 0;
}

