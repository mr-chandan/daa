// 18. Implement the **All-Pairs Shortest Path Problem** using **Floyd’s Algorithm**. 
#include <stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void main()
{
    int size;
    printf("Enter the number of nodes: ");
    scanf("%d", &size);

    int cost[size][size];
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
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
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