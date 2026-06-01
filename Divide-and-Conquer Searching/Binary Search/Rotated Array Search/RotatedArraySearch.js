function rotatedArraySearch(
    nums,
    target
) {
    let left = 0;
    let right = nums.length - 1;

    while (left <= right) {
        const mid =
            Math.floor(
                left +
                (right - left) / 2
            );

        if (nums[mid] === target) {
            return mid;
        }

        if (nums[left] <= nums[mid]) {

            if (
                target >= nums[left] &&
                target < nums[mid]
            ) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        } else {

            if (
                target > nums[mid] &&
                target <= nums[right]
            ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

const nums =
[
    4, 5, 6, 7, 0, 1, 2
];

const target = 0;

console.log(
    "Index:",
    rotatedArraySearch(
        nums,
        target
    )
);
