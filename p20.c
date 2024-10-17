#include <stdio.h>

long long karatsuba(long long x, long long y)
{

    long long x1 = x / 100;
    long long x0 = x % 100;

    long long y1 = y / 100;
    long long y0 = y % 100;

    long long z0 = x0 * y0;
    long long z2 = x1 * y1;
    long long z1 = (x0 + x1) * (y0 + y1) - z0 - z2;

    return z2 * 10000 + z1 * 100 + z0;
}

int main()
{
    long long x = 12347;
    long long y = 56787;
    long long result = karatsuba(x, y);

    printf("Karatsuba multiplication of %lld and %lld is %lld\n", x, y, result);
    return 0;
}
