#include <stdio.h>

int iterativeBinarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {5, 12, 18, 25, 31, 42, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 31;

    int index = iterativeBinarySearch(arr, size, target);

    if (index != -1)
    {
        printf("Element %d found at index %d\n", target, index);
    }
    else
    {
        printf("Element %d not found\n", target);
    }

    return 0;
}
