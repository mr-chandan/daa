#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n;
    int W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Enter values and weights of items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &val[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &wt[i]);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    int max_value = knapsack(W, wt, val, n);

    printf("Maximum value that can be obtained: %d\n", max_value);

    return 0;
}
