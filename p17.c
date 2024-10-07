// 17. Compute the **TransiƟve Closure** of the given directed graph using **Warshall’s Algorithm**. 
#include <stdio.h>
#include <stdbool.h>

void main()
{
    int size;
    printf("Enter the number of nodes: ");
    scanf("%d", &size);

    bool cost[size][size];
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nBefore MST:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }

    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (cost[i][j] != 0 || (cost[i][k] == 1 && cost[k][j] == 1))
                    cost[i][j] = 1;
            }
        }
    }

    printf("\nAfter MST:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}