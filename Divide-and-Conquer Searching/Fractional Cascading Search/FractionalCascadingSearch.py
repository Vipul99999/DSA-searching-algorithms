def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


catalogs = [
    [1, 4, 7, 10, 13],
    [2, 5, 8, 11, 14],
    [3, 6, 9, 12, 15]
]

target = 11

for i, catalog in enumerate(catalogs, start=1):
    print(
        f"Catalog {i}: "
        f"{binary_search(catalog, target)}"
    )
