function recursiveTernarySearch(arr, left, right, target) {
    if (left > right)
        return -1;

    const mid1 = left + Math.floor((right - left) / 3);
    const mid2 = right - Math.floor((right - left) / 3);

    if (arr[mid1] === target)
        return mid1;

    if (arr[mid2] === target)
        return mid2;

    if (target < arr[mid1])
        return recursiveTernarySearch(arr, left, mid1 - 1, target);

    if (target > arr[mid2])
        return recursiveTernarySearch(arr, mid2 + 1, right, target);

    return recursiveTernarySearch(arr, mid1 + 1, mid2 - 1, target);
}

const arr = [5, 10, 15, 20, 25, 30, 35, 40, 45];
const target = 30;

const index = recursiveTernarySearch(arr, 0, arr.length - 1, target);

if (index !== -1)
    console.log(`Element found at index ${index}`);
else
    console.log("Element not found");
