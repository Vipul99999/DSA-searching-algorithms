import math


def block_search(
        arr,
        target):

    n = len(arr)

    block = int(
        math.sqrt(n)
    )

    start = 0

    while start < n:

        end = min(
            start
            +
            block
            -
            1,
            n - 1
        )

        if target <= arr[end]:

            for i in range(
                    start,
                    end + 1
            ):

                if arr[i] == target:
                    return i

            return -1

        start += block

    return -1


arr = [
2,5,8,12,
16,20,24,
28,32,40
]

result =
block_search(
arr,
24
)

if result != -1:
    print(
        "Found at",
        result
    )

else:
    print(
        "Not Found"
    )
