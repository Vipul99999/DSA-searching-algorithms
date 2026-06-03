import math


def jump_search(arr, target):

    n = len(arr)

    step = int(math.sqrt(n))

    prev = 0

    while prev < n and arr[min(step, n)-1] < target:
        prev = step
        step += int(math.sqrt(n))

        if prev >= n:
            return -1

    while prev < n and arr[prev] < target:
        prev += 1

    if prev < n and arr[prev] == target:
        return prev

    return -1


arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]

target = 23

result = jump_search(arr, target)

if result != -1:
    print(
        f"Element found at index {result}"
    )
else:
    print("Element not found")
