// 1. Implement **Linear Search** in a set of given elements.

#include <stdio.h>

void main()
{
    int size, target, found = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Element not found in the array\n");
    }
}
