#include <stdio.h>

int searchInsertPosition(int arr[], int size, int target)
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

    return left;
}

int main()
{
    int arr[] = {1, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int position = searchInsertPosition(arr, size, target);

    printf("Position: %d\n", position);

    return 0;
}
