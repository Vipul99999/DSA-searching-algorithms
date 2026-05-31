def lower_bound_search(arr, target):
    left = 0
    right = len(arr) - 1
    answer = len(arr)

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] >= target:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1

    return answer


def main():
    arr = [1, 3, 3, 3, 5, 7, 9]
    target = 3

    index = lower_bound_search(arr, target)

    if index < len(arr):
        print(
            f"Lower Bound of {target} "
            f"is at index {index}"
        )
    else:
        print(
            f"Lower Bound position is at "
            f"end of array ({index})"
        )


if __name__ == "__main__":
    main()
