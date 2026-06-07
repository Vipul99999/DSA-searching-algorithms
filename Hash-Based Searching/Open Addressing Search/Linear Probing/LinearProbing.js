class LinearProbingHashTable {

    static TABLE_SIZE = 11;
    static EMPTY = -1;

    constructor() {
        this.table = Array(
            LinearProbingHashTable.TABLE_SIZE
        ).fill(
            LinearProbingHashTable.EMPTY
        );
    }

    hashFunction(key) {
        return (
            key %
            LinearProbingHashTable.TABLE_SIZE
        );
    }

    insert(key) {

        const index =
            this.hashFunction(key);

        for (
            let i = 0;
            i <
            LinearProbingHashTable.TABLE_SIZE;
            i++
        ) {

            const pos =
                (index + i) %
                LinearProbingHashTable.TABLE_SIZE;

            if (
                this.table[pos] ===
                LinearProbingHashTable.EMPTY
            ) {
                this.table[pos] = key;
                return true;
            }
        }

        return false;
    }

    search(key) {

        const index =
            this.hashFunction(key);

        for (
            let i = 0;
            i <
            LinearProbingHashTable.TABLE_SIZE;
            i++
        ) {

            const pos =
                (index + i) %
                LinearProbingHashTable.TABLE_SIZE;

            if (
                this.table[pos] ===
                LinearProbingHashTable.EMPTY
            )
                return false;

            if (
                this.table[pos] === key
            )
                return true;
        }

        return false;
    }

    display() {

        console.log("\nHash Table");

        for (
            let i = 0;
            i <
            LinearProbingHashTable.TABLE_SIZE;
            i++
        ) {

            console.log(
                `[${i}] = ${
                    this.table[i] ===
                    LinearProbingHashTable.EMPTY
                        ? "EMPTY"
                        : this.table[i]
                }`
            );
        }
    }
}

const ht =
    new LinearProbingHashTable();

ht.insert(22);
ht.insert(33);
ht.insert(44);
ht.insert(55);

ht.display();

console.log(
    "\nSearch 44:",
    ht.search(44)
        ? "Found"
        : "Not Found"
);
