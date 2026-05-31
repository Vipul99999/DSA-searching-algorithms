def last_occurrence_search(arr, target):
    left = 0
    right = len(arr) - 1
    answer = -1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            answer = mid
            left = mid + 1
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return answer


def main():
    arr = [1, 3, 3, 3, 5, 7, 9]
    target = 3

    index = last_occurrence_search(
        arr,
        target
    )

    if index != -1:
        print(
            f"Last occurrence of {target} "
            f"found at index {index}"
        )
    else:
        print(
            f"{target} not found in array"
        )


if __name__ == "__main__":
    main()
