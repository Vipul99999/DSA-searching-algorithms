function transposeSearch(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) {

            if (i > 0) {
                [arr[i], arr[i - 1]] = [arr[i - 1], arr[i]];
                return i - 1;
            }

            return i;
        }
    }

    return -1;
}

function printArray(arr) {
    console.log(arr.join(" "));
}

function main() {
    const arr = [10, 20, 30, 40, 50];
    const target = 40;

    console.log("Before Search:");
    printArray(arr);

    const index = transposeSearch(arr, target);

    if (index !== -1) {
        console.log("Element found.");
    } else {
        console.log("Element not found.");
    }

    console.log("After Search:");
    printArray(arr);
}

main();
