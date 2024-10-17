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




// #include <stdio.h>
// #include <math.h>

// // Function to get the number of digits in a number
// int numDigits(long long num) {
//     int digits = 0;
//     while (num != 0) {
//         digits++;
//         num /= 10;
//     }
//     return digits;
// }

// // Karatsuba multiplication function for large numbers
// long long karatsuba(long long x, long long y) {
//     // Base case for small numbers
//     if (x < 10 || y < 10) {
//         return x * y;
//     }

//     // Calculate the number of digits of the smaller number
//     int n = fmin(numDigits(x), numDigits(y));
//     int m = n / 2;  // Split size

//     // Calculate the power of 10 for splitting
//     long long pow10m = pow(10, m);

//     // Split x into two halves
//     long long x1 = x / pow10m;
//     long long x0 = x % pow10m;

//     // Split y into two halves
//     long long y1 = y / pow10m;
//     long long y0 = y % pow10m;

//     // Recursive calls to compute three products
//     long long z0 = karatsuba(x0, y0);                // Low parts
//     long long z2 = karatsuba(x1, y1);                // High parts
//     long long z1 = karatsuba(x0 + x1, y0 + y1) - z0 - z2;  // Cross terms

//     // Combine the results using the Karatsuba formula
//     return z2 * pow(10, 2 * m) + z1 * pow10m + z0;
// }

// int main() {
//     long long x = 100092320;
//     long long y = 100092320;
//     long long result = karatsuba(x, y);

//     printf("Karatsuba multiplication of %lld and %lld is %lld\n", x, y, result);
//     return 0;
// }
