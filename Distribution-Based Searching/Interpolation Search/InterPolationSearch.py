def interpolation_search(
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
                -
                arr[low]
            )
        )

        if arr[pos] == target:
            return pos

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
    60,
    70
]

print(
    interpolation_search(
        arr,
        50
    )
)
