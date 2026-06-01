#include <stdio.h>

int rotatedArraySearch(int arr[], int size, int target)
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

        if (arr[left] <= arr[mid])
        {
            if (target >= arr[left] &&
                target < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (target > arr[mid] &&
                target <= arr[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    int index =
        rotatedArraySearch(
            arr,
            size,
            target
        );

    printf("Index: %d\n", index);

    return 0;
}
