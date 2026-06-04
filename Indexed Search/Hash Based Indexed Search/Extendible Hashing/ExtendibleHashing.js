/*
====================================
Bucket Structure
------------------------------------
localDepth:
Number of directory bits
used by this bucket
====================================
*/

class Bucket {

    constructor(
        localDepth,
        capacity
    ) {

        this.localDepth =
            localDepth;

        this.capacity =
            capacity;

        this.keys = [];
    }

    isFull() {

        return (
            this.keys.length
            >=
            this.capacity
        );
    }

    contains(
        key
    ) {

        return (
            this.keys.includes(
                key
            )
        );
    }

    insert(
        key
    ) {

        this.keys.push(
            key
        );
    }

    delete(
        key
    ) {

        const index =
            this.keys.indexOf(
                key
            );

        if (
            index
            !==
            -1
        ) {

            this.keys.splice(
                index,
                1
            );
        }
    }
}



/*
====================================
Dynamic Hashing
(Extendible Hashing)
====================================
*/

class DynamicHashing {

    static BUCKET_SIZE = 3;

    constructor() {

        this.globalDepth =
            1;

        this.directory =
            [
                new Bucket(
                    1,
                    DynamicHashing.BUCKET_SIZE
                ),

                new Bucket(
                    1,
                    DynamicHashing.BUCKET_SIZE
                )
            ];
    }



    /*
    Hash Formula

    index =
    key &
    ((1<<globalDepth)-1)
    */

    getIndex(
        key
    ) {

        return (
            key
            &
            (
                (
                    1
                    <<
                    this.globalDepth
                )
                -
                1
            )
        );
    }



    /*
    Expand directory

    New Size:

    2^globalDepth
    */

    expandDirectory() {

        const oldSize =
            this.directory
            .length;

        for (
            let i = 0;
            i < oldSize;
            i++
        ) {

            this.directory
                .push(
                    this.directory[i]
                );
        }

        this.globalDepth++;
    }



    /*
    Split overflowing bucket
    */

    splitBucket(
        index
    ) {

        const oldBucket =
            this.directory[
                index
            ];

        if (
            oldBucket.localDepth
            ===
            this.globalDepth
        ) {

            this.expandDirectory();
        }


        const newBucket =
            new Bucket(
                oldBucket.localDepth + 1,
                DynamicHashing.BUCKET_SIZE
            );


        oldBucket.localDepth++;


        const splitBit =
            (
                1
                <<
                (
                    oldBucket.localDepth
                    -
                    1
                )
            );


        for (
            let i = 0;
            i < this.directory.length;
            i++
        ) {

            if (
                this.directory[i]
                ===
                oldBucket
                &&
                (
                    i
                    &
                    splitBit
                )
            ) {

                this.directory[i] =
                    newBucket;
            }
        }


        const oldValues =
            [
                ...oldBucket.keys
            ];


        oldBucket.keys = [];


        for (
            const value
            of
            oldValues
        ) {

            const newIndex =
                this.getIndex(
                    value
                );

            this.directory[
                newIndex
            ]
            .insert(
                value
            );
        }
    }



    /*
    Insert key
    */

    insert(
        key
    ) {

        while (
            true
        ) {

            const index =
                this.getIndex(
                    key
                );

            const bucket =
                this.directory[
                    index
                ];

            if (
                bucket.contains(
                    key
                )
            ) {

                return;
            }

            if (
                !bucket.isFull()
            ) {

                bucket.insert(
                    key
                );

                return;
            }

            this.splitBucket(
                index
            );
        }
    }



    /*
    Search
    */

    search(
        key
    ) {

        const index =
            this.getIndex(
                key
            );

        return (
            this.directory[
                index
            ]
            .contains(
                key
            )
        );
    }



    /*
    Delete
    */

    delete(
        key
    ) {

        const index =
            this.getIndex(
                key
            );

        this.directory[
            index
        ]
        .delete(
            key
        );
    }



    /*
    Display
    */

    display() {

        console.log(
            "\nGlobal Depth:",
            this.globalDepth
        );

        console.log();

        for (
            let i = 0;
            i < this.directory.length;
            i++
        ) {

            console.log(
                `Dir[${i}] ->`,
                [
                    ...this.directory[i].keys
                ]
            );
        }
    }
}



/*
====================================
Driver
====================================
*/

const table =
    new DynamicHashing();


[
    10,
    22,
    14,
    30,
    42,
    54,
    66
]
.forEach(
    value =>
    table.insert(
        value
    )
);


table.display();


console.log(
    "\nSearch 42:",
    table.search(
        42
    )
);


table.delete(
    42
);


console.log(
    "\nAfter Delete:"
);


table.display();
