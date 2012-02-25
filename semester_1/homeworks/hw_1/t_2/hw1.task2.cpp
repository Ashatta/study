#include <cstdio>
#include <cstdlib>

int quotient(int a, int b)
{
    int q = 0;

    bool difSign = false; 
    if (a < 0)
    {
        a *= -1;
        difSign = !difSign;
    }
    if (b < 0)
    {
        b *= -1;
        difSign = !difSign;
    }

    for (q = 0; a - b >= 0; q++)
        a -= b;

    if (difSign)
        q *= -1; 

    return q;
}
   
int main()
{
    int a = 0;
    int b = 0;
    printf("Integer division a / b\na = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    if (!b)
    {
        printf("Division by zero error\n");
        return 1;
    }

    int q = quotient(a, b);
    printf("a / b = %d\n", q);

    return 0;
}

