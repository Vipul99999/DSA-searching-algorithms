class CuckooHash {

    constructor() {

        this.SIZE = 11;

        this.EMPTY = null;

        this.table1 =
            Array(
                this.SIZE
            )
            .fill(
                null
            );

        this.table2 =
            Array(
                this.SIZE
            )
            .fill(
                null
            );
    }

    hash1(key) {
        return key % this.SIZE;
    }

    hash2(key) {
        return Math.floor(
            key /
            this.SIZE
        ) % this.SIZE;
    }

    insert(key) {

        const i =
            this.hash1(key);

        if (
            this.table1[i]
            ===
            null
        )
            this.table1[i] = key;

        else
            this.table2[
                this.hash2(key)
            ] = key;
    }

    search(key) {

        return (
            this.table1[
                this.hash1(key)
            ] === key
        )
        ||
        (
            this.table2[
                this.hash2(key)
            ] === key
        );
    }
}

const h =
new CuckooHash();

h.insert(10);

console.log(
h.search(10)
);
