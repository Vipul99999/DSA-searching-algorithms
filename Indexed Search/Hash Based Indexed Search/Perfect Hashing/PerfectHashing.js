class PerfectHashing {

    constructor() {

        this.table =
            new Set();
    }

    build(
        keys
    ) {

        keys.forEach(
            key =>
            this.table
            .add(
                key
            )
        );
    }

    search(
        key
    ) {

        return (
            this.table
            .has(
                key
            )
        );
    }
}

const hash =
new PerfectHashing();

hash.build(
[
10,
25,
42
]
);

console.log(
hash.search(
42
)
);
