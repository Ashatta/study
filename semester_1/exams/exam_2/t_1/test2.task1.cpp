#include <iostream>

using namespace std;

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
    clog << "The program calculates n-th Fibonacci number\nn = ";
    cin >> n;
    
    clog << "The " << n << "-th Fibonacci number is " << fib(n) << endl;

    return 0;
}

