def iterative_binary_search(arr, target):
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


def main():
    arr = [5, 12, 18, 25, 31, 42, 56]
    target = 31

    index = iterative_binary_search(arr, target)

    if index != -1:
        print(f"Element {target} found at index {index}")
    else:
        print(f"Element {target} not found")


if __name__ == "__main__":
    main()
