def find_peak_element(nums):
    left = 0
    right = len(nums) - 1

    while left < right:
        mid = left + (right - left) // 2

        if nums[mid] < nums[mid + 1]:
            left = mid + 1
        else:
            right = mid

    return left


if __name__ == "__main__":
    nums = [1, 2, 3, 1]

    peak_index = find_peak_element(nums)

    print("Peak Element Index:", peak_index)
    print("Peak Element Value:", nums[peak_index])
