function linearSearch(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) {
            return i;
        }
    }
    return -1;
}

function main() {
    const arr = [12, 7, 15, 9, 21];
    const target = 9;

    const index = linearSearch(arr, target);

    if (index !== -1) {
        console.log(`Element found at index: ${index}`);
    } else {
        console.log("Element not found");
    }
}

main();
