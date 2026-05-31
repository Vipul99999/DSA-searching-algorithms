#include <stdio.h>

int upperBoundSearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int answer = size;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}

int main()
{
    int arr[] = {1, 3, 3, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int index = upperBoundSearch(arr, size, target);

    if (index < size)
    {
        printf(
            "Upper Bound of %d is at index %d\n",
            target,
            index
        );
    }
    else
    {
        printf(
            "Upper Bound position is at end of array (%d)\n",
            index
        );
    }

    return 0;
}
