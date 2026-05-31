def recursive_binary_search(arr, left, right, target):
    if left > right:
        return -1

    mid = left + (right - left) // 2

    if arr[mid] == target:
        return mid

    if arr[mid] < target:
        return recursive_binary_search(
            arr,
            mid + 1,
            right,
            target
        )

    return recursive_binary_search(
        arr,
        left,
        mid - 1,
        target
    )


def main():
    arr = [5, 12, 18, 25, 31, 42, 56]
    target = 42

    index = recursive_binary_search(
        arr,
        0,
        len(arr) - 1,
        target
    )

    if index != -1:
        print(
            f"Element {target} found at index {index}"
        )
    else:
        print(
            f"Element {target} not found"
        )


if __name__ == "__main__":
    main()
