#include <iostream>
#include <cstdlib>

using namespace std;

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

int error(double a, int n)
{
    if (!a)
    {
        if (!n)
        {
            cerr << "Indeterminacy 0^0" << endl;
            return 1;
        }
        if (n < 0)
        {
            cerr << "Division by zero" << endl;
            return 2;
        }
    }
    return 0;
}
int main()
{
    double a = 0;
    int n = 0;

    clog << "The program calculates a^n\na = ";
    cin >> a;
    clog << "n = ";
    cin >> n;

    int err = error(a, n);
    if (!err)
    {
        clog << a << "^" << n << " = ";
        cout << power(a, n) << endl;
    }
    
    return err;
}

