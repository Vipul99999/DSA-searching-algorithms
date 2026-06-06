def binary_search(
        arr,
        left,
        right,
        target
):

    while left <= right:

        mid = (
            left +
            (right - left) // 2
        )

        if arr[mid] == target:
            return mid

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


def galloping_search(
        arr,
        target
):

    if not arr:
        return -1

    if arr[0] == target:
        return 0

    bound = 1

    while (
        bound < len(arr)
        and
        arr[bound] < target
    ):
        bound *= 2

    return binary_search(
        arr,
        bound // 2,
        min(
            bound,
            len(arr) - 1
        ),
        target
    )


arr = [
    5,10,15,20,
    25,30,35,
    40,45,50
]

target = 35

result = galloping_search(
    arr,
    target
)

if result != -1:
    print(
        "Found at index",
        result
    )
else:
    print(
        "Not Found"
    )
