/*
    LinearHashing.js
    ES2020+

    Features:
    - Dynamic Bucket Growth
    - Split Pointer (nextSplit)
    - Level-Based Hashing
    - Bucket Splitting
    - Overflow Buckets
    - Insert
    - Search
    - Display

    Run:
    node LinearHashing.js
*/

const INITIAL_BUCKETS = 2;
const BUCKET_SIZE = 4;

/* ---------- Bucket ---------- */

class Bucket {
    constructor() {
        this.keys = [];
        this.overflow = null;
    }

    isFull() {
        return this.keys.length >= BUCKET_SIZE;
    }
}

/* ---------- Linear Hashing ---------- */

class LinearHashing {

    constructor() {

        this.level = 0;
        this.nextSplit = 0;

        this.buckets = [];

        for (
            let i = 0;
            i < INITIAL_BUCKETS;
            i++
        ) {
            this.buckets.push(
                new Bucket()
            );
        }
    }

    /* ---------- Hash Functions ---------- */

    hashLevel(key) {

        return (
            key %
            (INITIAL_BUCKETS << this.level)
        );
    }

    hashNextLevel(key) {

        return (
            key %
            (
                INITIAL_BUCKETS
                << (this.level + 1)
            )
        );
    }

    bucketIndex(key) {

        let idx =
            this.hashLevel(key);

        if (idx < this.nextSplit) {

            idx =
                this.hashNextLevel(key);
        }

        return idx;
    }

    /* ---------- Insert Into Bucket ---------- */

    insertIntoBucket(bucket, key) {

        let current = bucket;

        while (true) {

            if (!current.isFull()) {

                current.keys.push(key);
                return;
            }

            if (
                current.overflow === null
            ) {
                current.overflow =
                    new Bucket();
            }

            current =
                current.overflow;
        }
    }

    /* ---------- Split Bucket ---------- */

    splitBucket() {

        const splitIndex =
            this.nextSplit;

        this.buckets.push(
            new Bucket()
        );

        const values = [];

        let current =
            this.buckets[splitIndex];

        while (current) {

            values.push(
                ...current.keys
            );

            current =
                current.overflow;
        }

        this.buckets[
            splitIndex
        ] = new Bucket();

        for (const value of values) {

            const idx =
                this.hashNextLevel(
                    value
                );

            this.insertIntoBucket(
                this.buckets[idx],
                value
            );
        }

        this.nextSplit++;

        const roundSize =
            INITIAL_BUCKETS
            << this.level;

        if (
            this.nextSplit ===
            roundSize
        ) {

            this.nextSplit = 0;
            this.level++;
        }
    }

    /* ---------- Insert ---------- */

    insert(key) {

        const idx =
            this.bucketIndex(key);

        this.insertIntoBucket(
            this.buckets[idx],
            key
        );

        this.splitBucket();
    }

    /* ---------- Search ---------- */

    search(key) {

        const idx =
            this.bucketIndex(key);

        let current =
            this.buckets[idx];

        while (current) {

            if (
                current.keys.includes(
                    key
                )
            ) {
                return true;
            }

            current =
                current.overflow;
        }

        return false;
    }

    /* ---------- Display ---------- */

    display() {

        console.log(
            `\nLevel: ${this.level}`
        );

        console.log(
            `Next Split: ${this.nextSplit}`
        );

        console.log(
            `Bucket Count: ${this.buckets.length}\n`
        );

        for (
            let i = 0;
            i < this.buckets.length;
            i++
        ) {

            let output =
                `Bucket[${i}] : `;

            let current =
                this.buckets[i];

            while (current) {

                for (
                    const value
                    of current.keys
                ) {
                    output +=
                        value + " ";
                }

                if (
                    current.overflow
                ) {
                    output += "-> ";
                }

                current =
                    current.overflow;
            }

            console.log(output);
        }
    }
}

/* ---------- Driver ---------- */

const hashTable =
    new LinearHashing();

const values = [
    5, 12, 25, 33,
    41, 18, 29, 37,
    49, 52, 61, 73
];

for (const value of values) {
    hashTable.insert(value);
}

hashTable.display();

console.log(
    "\nSearch 29:",
    hashTable.search(29)
        ? "Found"
        : "Not Found"
);

console.log(
    "Search 100:",
    hashTable.search(100)
        ? "Found"
        : "Not Found"
);
