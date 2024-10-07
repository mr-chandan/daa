// 10. Find the **Maximum** and **Minimum** element of an array using the **Divide and Conquer** technique. 
#include <stdio.h>

void findMinAndMax(int array[], int low, int high, int *min, int *max)
{
    if (low == high)
    {
        *max = *min = array[low];
    }
    else if (low == high - 1)
    {
        if (array[low] < array[high])
        {
            *max = array[high];
            *min = array[low];
        }
        else
        {
            *max = array[low];
            *min = array[high];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        int leftMin, leftMax, rightMin, rightMax;

        findMinAndMax(array, low, mid, &leftMin, &leftMax);
        findMinAndMax(array, mid + 1, high, &rightMin, &rightMax);

        if (leftMin < rightMin)
            *min = leftMin;
        else
            *min = rightMin;

        if (leftMax > rightMax)
            *max = leftMax;
        else
            *max = rightMax;
    }
}

int main()
{
    int array[] = {64, 25, 12, 22, 11, 34, 100, 99, 44};
    int n = sizeof(array) / sizeof(array[0]);

    int max, min;

    findMinAndMax(array, 0, n - 1, &min, &max);

    printf("The minimum array element is %d\n", min);
    printf("The maximum array element is %d\n", max);

    return 0;
}