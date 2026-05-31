#include <stdio.h>

int recursiveBinarySearch(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }

    if (arr[mid] < target)
    {
        return recursiveBinarySearch(
            arr,
            mid + 1,
            right,
            target
        );
    }

    return recursiveBinarySearch(
        arr,
        left,
        mid - 1,
        target
    );
}

int main()
{
    int arr[] = {5, 12, 18, 25, 31, 42, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 42;

    int index = recursiveBinarySearch(
        arr,
        0,
        size - 1,
        target
    );

    if (index != -1)
    {
        printf(
            "Element %d found at index %d\n",
            target,
            index
        );
    }
    else
    {
        printf(
            "Element %d not found\n",
            target
        );
    }

    return 0;
}
