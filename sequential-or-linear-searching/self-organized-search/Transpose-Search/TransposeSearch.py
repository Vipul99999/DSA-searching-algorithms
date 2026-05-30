def transpose_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:

            if i > 0:
                arr[i], arr[i - 1] = arr[i - 1], arr[i]
                return i - 1

            return i

    return -1


def print_array(arr):
    print(*arr)


def main():
    arr = [10, 20, 30, 40, 50]
    target = 40

    print("Before Search:")
    print_array(arr)

    index = transpose_search(arr, target)

    if index != -1:
        print("Element found.")
    else:
        print("Element not found.")

    print("After Search:")
    print_array(arr)


if __name__ == "__main__":
    main()
