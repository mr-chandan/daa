// 5. Perform **InserƟon Sort** to reorder **n** numbers in ascending order
#include <stdio.h>

void insertionSort(int array[], int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = temp;
    }
}

int main()
{
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    insertionSort(array, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}