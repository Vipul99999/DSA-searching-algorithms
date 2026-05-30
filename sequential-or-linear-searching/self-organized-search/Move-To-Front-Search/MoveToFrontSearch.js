function moveToFrontSearch(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) {
            const foundElement = arr[i];

            while (i > 0) {
                arr[i] = arr[i - 1];
                i--;
            }

            arr[0] = foundElement;
            return 0;
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

    const result = moveToFrontSearch(arr, target);

    if (result !== -1) {
        console.log("Element found and moved to front.");
    } else {
        console.log("Element not found.");
    }

    console.log("After Search:");
    printArray(arr);
}

main();
