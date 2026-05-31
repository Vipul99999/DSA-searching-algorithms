#include <stdio.h>

int lastOccurrenceSearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int answer = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            answer = mid;
            left = mid + 1;
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

    return answer;
}

int main()
{
    int arr[] = {1, 3, 3, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int index = lastOccurrenceSearch(
        arr,
        size,
        target
    );

    if (index != -1)
    {
        printf(
            "Last occurrence of %d found at index %d\n",
            target,
            index
        );
    }
    else
    {
        printf(
            "%d not found in array\n",
            target
        );
    }

    return 0;
}
