import math


def sparse_index_search(
        arr,
        target):

    n = len(arr)

    step = int(
        math.sqrt(n)
    )

    index = []

    for i in range(
            0,
            n,
            step):

        index.append(
            (
                arr[i],
                i
            )
        )

    start = 0

    for key, pos in index:

        if key > target:
            break

        start = pos

    end = min(
        start
        +
        step
        -
        1,
        n - 1
    )

    for i in range(
            start,
            end + 1):

        if arr[i] == target:
            return i

    return -1


arr = [
2,5,8,12,
16,20,24,
28,32,40
]

print(
sparse_index_search(
arr,
24
)
)
