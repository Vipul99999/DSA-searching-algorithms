def fibonacci_search(
        arr,
        target
):

    fib_mm2 = 0
    fib_mm1 = 1

    fib_m = (
        fib_mm1 +
        fib_mm2
    )

    while fib_m < len(arr):

        fib_mm2 = fib_mm1

        fib_mm1 = fib_m

        fib_m = (
            fib_mm1 +
            fib_mm2
        )

    offset = -1

    while fib_m > 1:

        i = min(
            offset +
            fib_mm2,
            len(arr) - 1
        )

        if arr[i] < target:

            fib_m = fib_mm1

            fib_mm1 = fib_mm2

            fib_mm2 = (
                fib_m -
                fib_mm1
            )

            offset = i

        elif arr[i] > target:

            fib_m = fib_mm2

            fib_mm1 = (
                fib_mm1 -
                fib_mm2
            )

            fib_mm2 = (
                fib_m -
                fib_mm1
            )

        else:
            return i

    if (
        fib_mm1 and
        offset + 1 < len(arr)
        and
        arr[offset + 1]
        == target
    ):
        return offset + 1

    return -1


arr = [
    10,20,30,
    40,50,60,
    70,80,90
]

target = 50

result = (
    fibonacci_search(
        arr,
        target
    )
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
