def search_insert_position(arr, target):
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

    return left


if __name__ == "__main__":
    arr = [1, 3, 5, 6]
    target = 5

    position = search_insert_position(
        arr,
        target
    )

    print("Position:", position)
