def iterative_ternary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3

        if arr[mid1] == target:
            return mid1

        if arr[mid2] == target:
            return mid2

        if target < arr[mid1]:
            right = mid1 - 1
        elif target > arr[mid2]:
            left = mid2 + 1
        else:
            left = mid1 + 1
            right = mid2 - 1

    return -1


arr = [5, 10, 15, 20, 25, 30, 35, 40, 45]
target = 30

index = iterative_ternary_search(arr, target)

if index != -1:
    print(f"Element found at index {index}")
else:
    print("Element not found")
