class CuckooHash {
    static TABLE_SIZE = 11;
    static EMPTY = -1;
    static MAX_KICKS = 20;

    constructor() {
        this.table1 = Array(
            CuckooHash.TABLE_SIZE
        ).fill(CuckooHash.EMPTY);

        this.table2 = Array(
            CuckooHash.TABLE_SIZE
        ).fill(CuckooHash.EMPTY);
    }

    hash1(key) {
        return key % CuckooHash.TABLE_SIZE;
    }

    hash2(key) {
        return Math.floor(
            key / CuckooHash.TABLE_SIZE
        ) % CuckooHash.TABLE_SIZE;
    }

    search(key) {
        return (
            this.table1[this.hash1(key)] === key ||
            this.table2[this.hash2(key)] === key
        );
    }

    insert(key) {
        let current = key;
        let table = 1;

        for (
            let i = 0;
            i < CuckooHash.MAX_KICKS;
            i++
        ) {
            if (table === 1) {
                const pos = this.hash1(current);

                if (
                    this.table1[pos] ===
                    CuckooHash.EMPTY
                ) {
                    this.table1[pos] = current;
                    return true;
                }

                [this.table1[pos], current] = [
                    current,
                    this.table1[pos],
                ];

                table = 2;
            } else {
                const pos = this.hash2(current);

                if (
                    this.table2[pos] ===
                    CuckooHash.EMPTY
                ) {
                    this.table2[pos] = current;
                    return true;
                }

                [this.table2[pos], current] = [
                    current,
                    this.table2[pos],
                ];

                table = 1;
            }
        }

        return false;
    }
}

const hash = new CuckooHash();

hash.insert(20);
hash.insert(50);
hash.insert(53);

console.log(
    hash.search(53)
        ? "Found"
        : "Not Found"
);
