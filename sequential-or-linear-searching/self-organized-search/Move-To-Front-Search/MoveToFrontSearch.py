def move_to_front_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            found_element = arr[i]

            while i > 0:
                arr[i] = arr[i - 1]
                i -= 1

            arr[0] = found_element
            return 0

    return -1


def print_array(arr):
    print(*arr)


def main():
    arr = [10, 20, 30, 40, 50]
    target = 40

    print("Before Search:")
    print_array(arr)

    result = move_to_front_search(arr, target)

    if result != -1:
        print("Element found and moved to front.")
    else:
        print("Element not found.")

    print("After Search:")
    print_array(arr)


if __name__ == "__main__":
    main()
