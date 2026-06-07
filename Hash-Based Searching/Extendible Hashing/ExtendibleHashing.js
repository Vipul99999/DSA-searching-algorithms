/*
    ExtendibleHashing.js
    ES2020+

    Features:
    - Global Depth
    - Local Depth
    - Directory
    - Bucket Splitting
    - Directory Doubling
    - Insert
    - Search
    - Delete
    - Display

    Run:
    node ExtendibleHashing.js
*/

const BUCKET_SIZE = 4;

class Bucket {
    constructor(localDepth) {
        this.localDepth = localDepth;
        this.keys = [];
    }

    isFull() {
        return this.keys.length >= BUCKET_SIZE;
    }
}

class ExtendibleHash {
    constructor() {
        this.globalDepth = 1;

        this.directory = [
            new Bucket(1),
            new Bucket(1)
        ];
    }

    hash(key) {
        return key;
    }

    getIndex(key) {
        const mask =
            (1 << this.globalDepth) - 1;

        return this.hash(key) & mask;
    }

    doubleDirectory() {
        const oldSize =
            this.directory.length;

        for (let i = 0;
             i < oldSize;
             i++) {

            this.directory.push(
                this.directory[i]
            );
        }

        this.globalDepth++;
    }

    splitBucket(bucketIndex) {

        const oldBucket =
            this.directory[bucketIndex];

        if (
            oldBucket.localDepth ===
            this.globalDepth
        ) {
            this.doubleDirectory();
        }

        const newBucket =
            new Bucket(
                oldBucket.localDepth + 1
            );

        oldBucket.localDepth++;

        const splitBit =
            1 <<
            (oldBucket.localDepth - 1);

        for (
            let i = 0;
            i < this.directory.length;
            i++
        ) {
            if (
                this.directory[i] ===
                oldBucket
            ) {
                if (i & splitBit) {
                    this.directory[i] =
                        newBucket;
                }
            }
        }

        const oldKeys =
            [...oldBucket.keys];

        oldBucket.keys = [];

        for (const key of oldKeys) {

            const index =
                this.getIndex(key);

            this.directory[index]
                .keys
                .push(key);
        }
    }

    insert(key) {

        while (true) {

            const index =
                this.getIndex(key);

            const bucket =
                this.directory[index];

            if (!bucket.isFull()) {

                bucket.keys.push(key);

                return;
            }

            this.splitBucket(index);
        }
    }

    search(key) {

        const index =
            this.getIndex(key);

        const bucket =
            this.directory[index];

        return bucket.keys.includes(key);
    }

    delete(key) {

        const index =
            this.getIndex(key);

        const bucket =
            this.directory[index];

        const position =
            bucket.keys.indexOf(key);

        if (position === -1) {
            return false;
        }

        bucket.keys.splice(
            position,
            1
        );

        return true;
    }

    display() {

        console.log(
            "\nGlobal Depth:",
            this.globalDepth
        );

        console.log(
            "Directory Size:",
            this.directory.length,
            "\n"
        );

        for (
            let i = 0;
            i < this.directory.length;
            i++
        ) {
            const bucket =
                this.directory[i];

            let output =
                `Dir[${i}] -> ` +
                `LD=${bucket.localDepth} : `;

            for (
                const key of bucket.keys
            ) {
                output += key + " ";
            }

            console.log(output);
        }
    }
}

/* Demo */

const hash =
    new ExtendibleHash();

const values = [
    5, 12, 25, 33,
    41, 18, 29, 37,
    49, 52, 61, 73
];

for (const value of values) {
    hash.insert(value);
}

hash.display();

console.log(
    "\nSearch 29:",
    hash.search(29)
        ? "Found"
        : "Not Found"
);

console.log(
    "Search 100:",
    hash.search(100)
        ? "Found"
        : "Not Found"
);

hash.delete(29);

console.log(
    "\nAfter deleting 29:"
);

hash.display();
