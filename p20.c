#include <stdio.h>
#include <math.h>

int get_size(long value) {
    int count = 0;
    while (value > 0) {
        count++;
        value /= 10;
    }
    return count;
}


long karatsuba(long X, long Y) {

    if (X < 10 || Y < 10)
        return X * Y;

    int size = fmax(get_size(X), get_size(Y));
    if (size < 10)
        return X * Y;

    size = (size / 2) + (size % 2);
    long multiplier = pow(10, size);
    long b = X / multiplier;
    long a = X - (b * multiplier);
    long d = Y / multiplier;
    long c = Y - (d * multiplier);
    
    long u = karatsuba(a, c);
    long z = karatsuba(a + b, c + d);
    long v = karatsuba(b, d);

    return u + ((z - u - v) * multiplier) + (v * (long)(pow(10, 2 * size)));
}

int main() {
    long x, y;
    printf("Enter the first number: ");
    scanf("%ld", &x);
    printf("Enter the second number: ");
    scanf("%ld", &y);

    printf("The final product is: %ld\n", karatsuba(x, y));
    return 0;
}
