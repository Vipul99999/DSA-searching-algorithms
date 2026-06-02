function iterativeTernarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        const mid1 = left + Math.floor((right - left) / 3);
        const mid2 = right - Math.floor((right - left) / 3);

        if (arr[mid1] === target)
            return mid1;

        if (arr[mid2] === target)
            return mid2;

        if (target < arr[mid1]) {
            right = mid1 - 1;
        } else if (target > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1;
}

const arr = [5, 10, 15, 20, 25, 30, 35, 40, 45];
const target = 30;

const index = iterativeTernarySearch(arr, target);

if (index !== -1)
    console.log(`Element found at index ${index}`);
else
    console.log("Element not found");
