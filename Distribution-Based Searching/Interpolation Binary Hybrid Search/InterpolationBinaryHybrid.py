def interpolation_binary_hybrid(
    arr,
    target
):

    low = 0
    high = len(arr) - 1

    while (
        low <= high
        and target >= arr[low]
        and target <= arr[high]
    ):

        if arr[low] == arr[high]:
            return (
                low
                if arr[low] == target
                else -1
            )

        pos = low + int(
            (
                (target - arr[low])
                *
                (high - low)
            )
            /
            (
                arr[high]
                - arr[low]
            )
        )

        if (
            pos < low
            or pos > high
        ):
            pos = (
                low + high
            ) // 2

        if arr[pos] == target:
            return pos

        if (
            high - low < 6
        ):

            mid = (
                low + high
            ) // 2

            if arr[mid] == target:
                return mid

            if arr[mid] < target:
                low = mid + 1
            else:
                high = mid - 1

            continue

        if arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1

    return -1


arr = [
    10,
    20,
    30,
    40,
    50,
    1000,
    5000
]

print(
    interpolation_binary_hybrid(
        arr,
        1000
    )
)
