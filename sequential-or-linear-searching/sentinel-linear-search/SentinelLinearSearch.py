def sentinel_linear_search(arr, target):
    n = len(arr)

    if n == 0:
        return -1

    last = arr[-1]

    arr[-1] = target

    i = 0
    while arr[i] != target:
        i += 1

    arr[-1] = last

    if i < n - 1 or last == target:
        return i

    return -1


def main():
    arr = [10, 25, 7, 14, 30]
    target = 14

    index = sentinel_linear_search(arr, target)

    if index != -1:
        print(f"Element found at index: {index}")
    else:
        print("Element not found")


if __name__ == "__main__":
    main()
