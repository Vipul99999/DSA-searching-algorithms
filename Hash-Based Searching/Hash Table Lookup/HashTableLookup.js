class HashTableLookup {
    static TABLE_SIZE = 101;
    static EMPTY = -1;

    constructor() {
        this.table = Array(
            HashTableLookup.TABLE_SIZE
        ).fill(HashTableLookup.EMPTY);
    }

    hashFunction(key) {
        return (
            key %
            HashTableLookup.TABLE_SIZE
        );
    }

    insert(key) {
        const index =
            this.hashFunction(key);

        if (
            this.table[index] !==
            HashTableLookup.EMPTY
        ) {
            return false;
        }

        this.table[index] = key;
        return true;
    }

    lookup(key) {
        return (
            this.table[
                this.hashFunction(key)
            ] === key
        );
    }
}

const ht =
    new HashTableLookup();

ht.insert(15);
ht.insert(42);
ht.insert(99);

console.log(
    ht.lookup(42)
        ? "Found"
        : "Not Found"
);
