// 6. Perform **Quick Sort** using the **Divide and Conquer** technique to arrange n numbers
#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int start = low;
    int end = high;

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;

    return end;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void main()
{
    int arr[10], i;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the array elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}