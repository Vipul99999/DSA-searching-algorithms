class QuadraticProbing {

    static TABLE_SIZE = 11;
    static EMPTY = -1;

    constructor() {

        this.table = Array(
            QuadraticProbing.TABLE_SIZE
        ).fill(
            QuadraticProbing.EMPTY
        );
    }

    hashFunction(key) {
        return (
            key %
            QuadraticProbing.TABLE_SIZE
        );
    }

    insert(key) {

        const index =
            this.hashFunction(key);

        for (
            let i = 0;
            i <
            QuadraticProbing.TABLE_SIZE;
            i++
        ) {

            const pos =
                (index + i * i)
                %
                QuadraticProbing.TABLE_SIZE;

            if (
                this.table[pos] ===
                QuadraticProbing.EMPTY
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
            QuadraticProbing.TABLE_SIZE;
            i++
        ) {

            const pos =
                (index + i * i)
                %
                QuadraticProbing.TABLE_SIZE;

            if (
                this.table[pos] ===
                QuadraticProbing.EMPTY
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
            QuadraticProbing.TABLE_SIZE;
            i++
        ) {

            console.log(
                `[${i}] = ${
                    this.table[i] ===
                    QuadraticProbing.EMPTY
                        ? "EMPTY"
                        : this.table[i]
                }`
            );
        }
    }
}

const ht =
    new QuadraticProbing();

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
