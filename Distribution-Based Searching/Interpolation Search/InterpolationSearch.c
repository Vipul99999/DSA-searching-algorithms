#include <stdio.h>

int interpolationSearch(
    int arr[],
    int n,
    int target
) {
    int low = 0;
    int high = n - 1;

    while (
        low <= high &&
        target >= arr[low] &&
        target <= arr[high]
    ) {

        if (arr[low] == arr[high]) {
            return (
                arr[low] == target
            )
                ? low
                : -1;
        }

        int pos =
            low +
            (
                (double)
                (target - arr[low])
                *
                (high - low)
            )
            /
            (
                arr[high]
                - arr[low]
            );

        if (
            arr[pos]
            == target
        )
            return pos;

        if (
            arr[pos]
            < target
        )
            low =
                pos + 1;
        else
            high =
                pos - 1;
    }

    return -1;
}

int main() {

    int arr[] =
    {
        10,
        20,
        30,
        40,
        50,
        60,
        70
    };

    int n =
        sizeof(arr)
        /
        sizeof(arr[0]);

    int target =
        50;

    int result =
        interpolationSearch(
            arr,
            n,
            target
        );

    if (
        result != -1
    )
        printf(
            "Found at index %d\n",
            result
        );
    else
        printf(
            "Not Found\n"
        );

    return 0;
}
