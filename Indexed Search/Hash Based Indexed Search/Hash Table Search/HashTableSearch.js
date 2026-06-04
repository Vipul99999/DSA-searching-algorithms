class HashTable {

    constructor() {

        this.SIZE = 10;

        this.table =
            Array
                .from(
                    {
                        length:
                        this.SIZE
                    },
                    () => []
                );
    }

    /*
        h(key)=key%SIZE
    */
    hash(key) {

        return (
            key %
            this.SIZE
        );
    }

    insert(key) {

        const index =
            this.hash(key);

        this.table[index]
            .push(key);
    }

    search(key) {

        return this.table[
            this.hash(key)
        ]
        .includes(key);
    }

    delete(key) {

        const index =
            this.hash(key);

        this.table[index] =
            this.table[index]
            .filter(
                x =>
                x !== key
            );
    }

    display() {

        this.table
            .forEach(
                (
                    bucket,
                    index
                ) => {

                    console.log(
                        `[${index}] `
                        +
                        bucket.join(
                            " -> "
                        )
                    );
                }
            );
    }
}

const ht =
    new HashTable();

ht.insert(10);
ht.insert(20);
ht.insert(35);

ht.display();

console.log(
    ht.search(20)
);

ht.delete(20);

ht.display();
