class PerfectHashingSearch {

    constructor() {

        this.table =
            Array(10).fill(null);

        this.table[0] = 11;
        this.table[1] = 22;
        this.table[2] = 33;
        this.table[3] = 44;
        this.table[4] = 55;
    }

    perfectHash(key) {

        const mapping = {

            11: 0,
            22: 1,
            33: 2,
            44: 3,
            55: 4
        };

        return (
            mapping[key]
            ?? -1
        );
    }

    search(key) {

        const idx =
            this.perfectHash(key);

        if (idx === -1)
            return false;

        return (
            this.table[idx]
            === key
        );
    }
}

const ht =
    new PerfectHashingSearch();

console.log(
    "Search 33:",
    ht.search(33)
        ? "Found"
        : "Not Found"
);
