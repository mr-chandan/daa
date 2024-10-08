#include <stdio.h>

void displayDegrees(int n, int adjMatrix[n][n]) {
    int degree;

    for (int i = 0; i < n; i++) {
        degree = 0;
        
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] != 0) {
                degree++;
            }
        }

        printf("Degree of vertex %d: %d\n", i + 1, degree);
    }
}

int main() {
    int n;


    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adjMatrix[n][n];

    printf("Enter the Cost Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    displayDegrees(n, adjMatrix);

    return 0;
}
