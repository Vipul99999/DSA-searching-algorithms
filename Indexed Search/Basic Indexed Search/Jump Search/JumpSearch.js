function jumpSearch(arr, target) {

    const n = arr.length;

    let step =
        Math.floor(Math.sqrt(n));

    let prev = 0;

    while (
        prev < n &&
        arr[Math.min(step, n)-1]
            < target
    ) {

        prev = step;

        step +=
            Math.floor(
                Math.sqrt(n)
            );

        if (prev >= n)
            return -1;
    }

    while (
        prev < n &&
        arr[prev] < target
    ) {
        prev++;
    }

    if (
        prev < n &&
        arr[prev] === target
    )
        return prev;

    return -1;
}

const arr =
[
2,5,8,12,16,
23,38,56,72,91
];

const target = 23;

const result =
    jumpSearch(
        arr,
        target
    );

if(result!==-1)
    console.log(
        `Element found at index ${result}`
    );
else
    console.log(
        "Element not found"
    );
