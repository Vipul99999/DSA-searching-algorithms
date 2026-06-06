def binary_search(arr, left, right, target):

    while left <= right:

        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


def unbounded_binary_search(arr, target):

    if not arr:
        return -1

    if arr[0] == target:
        return 0

    index = 1

    while index < len(arr) and arr[index] < target:
        index *= 2

    left = index // 2
    right = min(index, len(arr) - 1)

    return binary_search(
        arr,
        left,
        right,
        target
    )


arr = [5,10,15,20,25,30,35,40,45,50]
target = 35

result = unbounded_binary_search(
    arr,
    target
)

if result != -1:
    print("Found at index", result)
else:
    print("Not Found")
