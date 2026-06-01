function canComplete(
    speed,
    piles,
    hours
) {
    let totalHours = 0;

    for (const pile of piles) {
        totalHours += Math.ceil(
            pile / speed
        );

        if (totalHours > hours) {
            return false;
        }
    }

    return true;
}

function binarySearchOnAnswer(
    piles,
    hours
) {
    let left = 1;

    let right =
        Math.max(...piles);

    let answer = right;

    while (left <= right) {
        const mid =
            Math.floor(
                left + (right - left) / 2
            );

        if (
            canComplete(
                mid,
                piles,
                hours
            )
        ) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

const piles =
[
    3,
    6,
    7,
    11
];

const hours = 8;

console.log(
    "Minimum Speed:",
    binarySearchOnAnswer(
        piles,
        hours
    )
);
