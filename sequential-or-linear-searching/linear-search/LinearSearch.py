def linear_search(arr, target):
    for index, value in enumerate(arr):
        if value == target:
            return index
    return -1


def main():
    arr = [12, 7, 15, 9, 21]
    target = 9

    index = linear_search(arr, target)

    if index != -1:
        print(f"Element found at index: {index}")
    else:
        print("Element not found")


if __name__ == "__main__":
    main()
