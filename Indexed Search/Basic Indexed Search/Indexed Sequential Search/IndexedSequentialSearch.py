import math


def indexed_sequential_search(
        arr,
        target):

    n = len(arr)

    block = int(
        math.sqrt(n)
    )

    index = []

    for i in range(
            0,
            n,
            block):

        end = min(
            i
            +
            block
            -
            1,
            n - 1
        )

        index.append(
            (
                arr[end],
                i
            )
        )

    selected = -1

    for mx, st in index:

        if target <= mx:

            selected = st

            break

    if selected == -1:
        return -1

    end = min(
        selected
        +
        block
        -
        1,
        n - 1
    )

    for i in range(
            selected,
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
indexed_sequential_search(
arr,
24
)
)
