#include <stdio.h>

int main() {
    int z[2][2]; // Resultant matrix
    int i, j;
    
    // Declare matrices
    int x[2][2]; // First matrix
    int y[2][2]; // Second matrix

    // Input for the first matrix
    printf("Enter elements for the first matrix (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &x[i][j]);
        }
    }

    // Input for the second matrix
    printf("\nEnter elements for the second matrix (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &y[i][j]);
        }
    }

    // Display the first matrix
    printf("\nThe first matrix is:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }

    // Display the second matrix
    printf("\nThe second matrix is:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", y[i][j]);
        }
        printf("\n");
    }

    // Applying Strassen's algorithm
    int m1, m2, m3, m4, m5, m6, m7;
    
    m1 = (x[0][0] + x[1][1]) * (y[0][0] + y[1][1]);
    m2 = (x[1][0] + x[1][1]) * y[0][0];
    m3 = x[0][0] * (y[0][1] - y[1][1]);
    m4 = x[1][1] * (y[1][0] - y[0][0]);
    m5 = (x[0][0] + x[0][1]) * y[1][1];
    m6 = (x[1][0] - x[0][0]) * (y[0][0] + y[0][1]);
    m7 = (x[0][1] - x[1][1]) * (y[1][0] + y[1][1]);

    // Calculating the product matrix
    z[0][0] = m1 + m4 - m5 + m7;
    z[0][1] = m3 + m5;
    z[1][0] = m2 + m4;
    z[1][1] = m1 - m2 + m3 + m6;

    // Display the product matrix
    printf("\nProduct achieved using Strassen's algorithm:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", z[i][j]);
        }
        printf("\n");
    }

    return 0;
}
