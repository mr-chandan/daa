// 7. Perform **Merge Sort** using the **Divide and Conquer** technique to arrange **n** numbers. 
#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[10];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int t = low; t <= high; t++)
    {
        arr[t] = temp[t];
    }
}

void partition(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void main()
{
    int arr[10], size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the array elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    partition(arr, 0, size - 1);

    printf("Sorted array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

}