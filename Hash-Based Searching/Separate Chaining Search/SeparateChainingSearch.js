class Node {
    constructor(key) {
        this.key = key;
        this.next = null;
    }
}

class SeparateChainingHashTable {

    static TABLE_SIZE = 10;

    constructor() {
        this.buckets = Array(
            SeparateChainingHashTable
                .TABLE_SIZE
        ).fill(null);
    }

    hashFunction(key) {
        return (
            key %
            SeparateChainingHashTable
                .TABLE_SIZE
        );
    }

    insert(key) {

        const index =
            this.hashFunction(key);

        const node =
            new Node(key);

        node.next =
            this.buckets[index];

        this.buckets[index] =
            node;
    }

    search(key) {

        const index =
            this.hashFunction(key);

        let current =
            this.buckets[index];

        while (current) {

            if (
                current.key === key
            ) {
                return true;
            }

            current =
                current.next;
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
            SeparateChainingHashTable
                .TABLE_SIZE;
            i++
        ) {

            let output =
                `[${i}] -> `;

            let current =
                this.buckets[i];

            while (current) {

                output +=
                    current.key +
                    " -> ";

                current =
                    current.next;
            }

            output += "NULL";

            console.log(output);
        }
    }
}

const ht =
    new SeparateChainingHashTable();

ht.insert(15);
ht.insert(25);
ht.insert(35);
ht.insert(42);

ht.display();

console.log(
    "\nSearch 35:",
    ht.search(35)
        ? "Found"
        : "Not Found"
);
