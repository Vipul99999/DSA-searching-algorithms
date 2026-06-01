#include <stdio.h>

int canComplete(int target, int hours[], int size, int maxHours)
{
    int totalHours = 0;

    for (int i = 0; i < size; i++)
    {
        totalHours += (hours[i] + target - 1) / target;

        if (totalHours > maxHours)
        {
            return 0;
        }
    }

    return 1;
}

int binarySearchOnAnswer(int hours[], int size, int maxHours)
{
    int left = 1;
    int right = hours[0];

    for (int i = 1; i < size; i++)
    {
        if (hours[i] > right)
        {
            right = hours[i];
        }
    }

    int answer = right;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (canComplete(mid, hours, size, maxHours))
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
    int piles[] = {3, 6, 7, 11};
    int size = sizeof(piles) / sizeof(piles[0]);
    int h = 8;

    printf("Minimum Speed: %d\n",
           binarySearchOnAnswer(piles, size, h));

    return 0;
}
