def recursive_ternary_search(arr, left, right, target):
    if left > right:
        return -1

    mid1 = left + (right - left) // 3
    mid2 = right - (right - left) // 3

    if arr[mid1] == target:
        return mid1

    if arr[mid2] == target:
        return mid2

    if target < arr[mid1]:
        return recursive_ternary_search(arr, left, mid1 - 1, target)

    if target > arr[mid2]:
        return recursive_ternary_search(arr, mid2 + 1, right, target)

    return recursive_ternary_search(arr, mid1 + 1, mid2 - 1, target)


arr = [5, 10, 15, 20, 25, 30, 35, 40, 45]
target = 30

index = recursive_ternary_search(arr, 0, len(arr) - 1, target)

if index != -1:
    print(f"Element found at index {index}")
else:
    print("Element not found")
