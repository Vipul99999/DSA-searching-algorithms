const TABLE_SIZE = 16;
const HOP_RANGE = 4;

class Bucket {

    constructor() {

        this.key = -1;
        this.occupied = false;
        this.hopInfo = 0;
    }
}

class HopscotchHashingSearch {

    constructor() {

        this.table = Array.from(
            {
                length:
                TABLE_SIZE
            },
            () => new Bucket()
        );
    }

    hashFunction(key) {

        return (
            key %
            TABLE_SIZE
        );
    }

    insert(key) {

        const home =
            this.hashFunction(key);

        let freePos = -1;

        for (
            let i = home;
            i < TABLE_SIZE;
            i++
        ) {

            if (
                !this.table[i]
                .occupied
            ) {

                freePos = i;
                break;
            }
        }

        if (freePos === -1)
            return false;

        if (
            freePos - home
            >= HOP_RANGE
        ) {
            return false;
        }

        this.table[
            freePos
        ].key = key;

        this.table[
            freePos
        ].occupied = true;

        this.table[
            home
        ].hopInfo |= (
            1 <<
            (
                freePos
                - home
            )
        );

        return true;
    }

    search(key) {

        const home =
            this.hashFunction(key);

        const hop =
            this.table[
                home
            ].hopInfo;

        for (
            let i = 0;
            i < HOP_RANGE;
            i++
        ) {

            if (
                hop &
                (1 << i)
            ) {

                const pos =
                    home + i;

                if (
                    pos <
                    TABLE_SIZE &&
                    this.table[pos]
                    .occupied &&
                    this.table[pos]
                    .key === key
                ) {

                    return true;
                }
            }
        }

        return false;
    }

    display() {

        console.log(
            "\nHopscotch Hash Table"
        );

        for (
            let i = 0;
            i < TABLE_SIZE;
            i++
        ) {

            const value =
                this.table[i]
                .occupied
                    ? this.table[i]
                      .key
                    : "EMPTY";

            console.log(
                `[${i}] = `
                + `${value} `
                + `(hop=`
                + `${this.table[i]
                        .hopInfo})`
            );
        }
    }
}

/* Driver */

const ht =
    new HopscotchHashingSearch();

ht.insert(5);
ht.insert(21);
ht.insert(37);
ht.insert(53);

ht.display();

console.log(
    "\nSearch 37:",
    ht.search(37)
        ? "Found"
        : "Not Found"
);

console.log(
    "Search 100:",
    ht.search(100)
        ? "Found"
        : "Not Found"
);
