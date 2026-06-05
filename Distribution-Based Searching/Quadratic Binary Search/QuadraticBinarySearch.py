def quadratic_binary_search(
    arr,
    target
):

    low = 0
    high = len(arr) - 1

    while low <= high:

        range_size = (
            high - low
        )

        pos = (
            low +
            (
                range_size
                *
                range_size
            )
            //
            (
                2
                *
                (
                    range_size
                    + 1
                )
            )
        )

        if pos > high:
            pos = (
                low +
                range_size // 2
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
    70,
    80,
    90
]

print(
    quadratic_binary_search(
        arr,
        70
    )
)
