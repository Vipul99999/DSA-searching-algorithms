function sentinelLinearSearch(arr, target) {
    const n = arr.length;

    if (n === 0) {
        return -1;
    }

    const last = arr[n - 1];

    arr[n - 1] = target;

    let i = 0;
    while (arr[i] !== target) {
        i++;
    }

    arr[n - 1] = last;

    if (i < n - 1 || last === target) {
        return i;
    }

    return -1;
}

function main() {
    const arr = [10, 25, 7, 14, 30];
    const target = 14;

    const index = sentinelLinearSearch(arr, target);

    if (index !== -1) {
        console.log(`Element found at index: ${index}`);
    } else {
        console.log("Element not found");
    }
}

main();
