class DoubleHashing {

    static TABLE_SIZE = 13;
    static EMPTY = -1;

    constructor() {

        this.table = Array(
            DoubleHashing.TABLE_SIZE
        ).fill(
            DoubleHashing.EMPTY
        );
    }

    hash1(key) {
        return (
            key %
            DoubleHashing.TABLE_SIZE
        );
    }

    hash2(key) {
        return 7 - (key % 7);
    }

    insert(key) {

        const h1 =
            this.hash1(key);

        const h2 =
            this.hash2(key);

        for (
            let i = 0;
            i <
            DoubleHashing.TABLE_SIZE;
            i++
        ) {

            const pos =
                (h1 + i * h2)
                % DoubleHashing.TABLE_SIZE;

            if (
                this.table[pos] ===
                DoubleHashing.EMPTY
            ) {

                this.table[pos] = key;

                return true;
            }
        }

        return false;
    }

    search(key) {

        const h1 =
            this.hash1(key);

        const h2 =
            this.hash2(key);

        for (
            let i = 0;
            i <
            DoubleHashing.TABLE_SIZE;
            i++
        ) {

            const pos =
                (h1 + i * h2)
                % DoubleHashing.TABLE_SIZE;

            if (
                this.table[pos] ===
                DoubleHashing.EMPTY
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

        console.log(
            "\nHash Table"
        );

        for (
            let i = 0;
            i <
            DoubleHashing.TABLE_SIZE;
            i++
        ) {

            console.log(
                `[${i}] = ${
                    this.table[i] ===
                    DoubleHashing.EMPTY
                        ? "EMPTY"
                        : this.table[i]
                }`
            );
        }
    }
}

const ht =
    new DoubleHashing();

ht.insert(25);
ht.insert(38);
ht.insert(51);
ht.insert(64);

ht.display();

console.log(
    "\nSearch 51:",
    ht.search(51)
        ? "Found"
        : "Not Found"
);
