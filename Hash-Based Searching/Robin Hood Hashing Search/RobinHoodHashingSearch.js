const TABLE_SIZE = 11;
const EMPTY = -1;

class RobinHoodHashing {

    constructor() {

        this.table = Array(
            TABLE_SIZE
        ).fill(EMPTY);
    }

    hashFunction(key) {

        return key % TABLE_SIZE;
    }

    probeDistance(key, pos) {

        const home =
            this.hashFunction(key);

        return (
            pos -
            home +
            TABLE_SIZE
        ) % TABLE_SIZE;
    }

    insert(key) {

        let current = key;

        let pos =
            this.hashFunction(
                current
            );

        while (true) {

            if (
                this.table[pos]
                === EMPTY
            ) {

                this.table[pos] =
                    current;

                return true;
            }

            const resident =
                this.table[pos];

            const currentDist =
                this.probeDistance(
                    current,
                    pos
                );

            const residentDist =
                this.probeDistance(
                    resident,
                    pos
                );

            if (
                currentDist >
                residentDist
            ) {

                [
                    this.table[pos],
                    current
                ] = [
                    current,
                    this.table[pos]
                ];
            }

            pos =
                (pos + 1)
                % TABLE_SIZE;
        }
    }

    search(key) {

        let pos =
            this.hashFunction(key);

        let dist = 0;

        while (
            this.table[pos]
            !== EMPTY
        ) {

            if (
                this.table[pos]
                === key
            ) {
                return true;
            }

            const residentDist =
                this.probeDistance(
                    this.table[pos],
                    pos
                );

            if (
                residentDist <
                dist
            ) {
                return false;
            }

            pos =
                (pos + 1)
                % TABLE_SIZE;

            dist++;
        }

        return false;
    }

    display() {

        console.log(
            "\nHash Table"
        );

        for (
            let i = 0;
            i < TABLE_SIZE;
            i++
        ) {

            console.log(
                `[${i}] = ${
                    this.table[i]
                    === EMPTY
                        ? "EMPTY"
                        : this.table[i]
                }`
            );
        }
    }
}

/* Driver */

const ht =
    new RobinHoodHashing();

ht.insert(22);
ht.insert(33);
ht.insert(44);
ht.insert(55);
ht.insert(66);

ht.display();

console.log(
    "\nSearch 44:",
    ht.search(44)
        ? "Found"
        : "Not Found"
);

console.log(
    "Search 100:",
    ht.search(100)
        ? "Found"
        : "Not Found"
);
