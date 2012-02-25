#include <stdio.h>

typedef unsigned long long ullong;

const int offset = 1023;
const ullong one = 1;
const ullong maxMant = 1e19;

union Number
{
    double dn;
    ullong in;
};

int getExp(Number n)
{
    n.in <<= 1;
    n.in >>= 53;
    int exp = n.in - offset;
    return exp;
}

ullong getMant(Number n)
{
    n.in <<= 12; 
    ullong mant = n.in >> 12;

    ullong mantDec = 0;

    if (mant)
    {
        ullong left = 0;
        ullong right = maxMant;

        int i = 51; // мантиссу ищем с помощью 
        for (; i >= 0; --i) // подобия метода дихотомии 
            if (mant & (one << i)) 
                left = left / 2 + right / 2;
            else
                right = left / 2 + right / 2;
        mantDec = left / 2 + right / 2;
    }

    return mantDec;
}

ullong round(ullong mant)
{
    const int excessDigits = 10000; // точность double - 
    mant /= excessDigits; // 15 знаков после запятой,
                          // а mant - 19 знаков
    while (!(mant % 10))
        mant /= 10;

    return mant;
}

int main()
{
    printf("The program interprets a piece of memory %s", \
           "as double precision number (d)\nEnter d = ");
    Number n;
    scanf("%lf", &n.dn);

    bool sign = n.in & (one << 63);
    if (n.dn == 0)
        printf("d = %c0.0*2^(0)\n", sign ? '-' : '+');
    else
    {
        ullong mantDec = getMant(n);
        if (mantDec)
            mantDec = round(mantDec);
        int exp = getExp(n);
        
        printf("d = %c1.%llu*2^(%d)\n", 
                sign ? '-' : '+', mantDec, exp);
    }

    return 0;
}

