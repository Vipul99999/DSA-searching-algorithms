#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 3
#define INITIAL_DEPTH 1

/* ------------------------------
   Bucket Structure
--------------------------------*/
typedef struct Bucket {

    int localDepth;

    int count;

    int values[BUCKET_SIZE];

} Bucket;


/* ------------------------------
   Dynamic Hash Table
--------------------------------*/
typedef struct {

    int globalDepth;

    int directorySize;

    Bucket** directory;

} DynamicHash;


/*
    Hash Function

    Formula:
    h(key)=key

    Directory Index:
    index =
    h(key)
    &
    ((1<<globalDepth)-1)
*/
int getIndex(
    DynamicHash* table,
    int key
) {

    return key &
           (
               (1 << table->globalDepth)
               - 1
           );
}


/* Create empty bucket */
Bucket* createBucket(
    int depth
) {

    Bucket* bucket =
        malloc(
            sizeof(Bucket)
        );

    bucket->localDepth =
        depth;

    bucket->count = 0;

    return bucket;
}


/* Create table */
DynamicHash* createTable() {

    DynamicHash* table =
        malloc(
            sizeof(
                DynamicHash
            )
        );

    table->globalDepth =
        INITIAL_DEPTH;

    table->directorySize =
        1
        <<
        INITIAL_DEPTH;

    table->directory =
        malloc(
            table->directorySize
            *
            sizeof(Bucket*)
        );

    for (
        int i = 0;
        i < table->directorySize;
        i++
    ) {

        table->directory[i] =
            createBucket(
                INITIAL_DEPTH
            );
    }

    return table;
}


/* Double directory */
void expandDirectory(
    DynamicHash* table
) {

    int oldSize =
        table->directorySize;

    table->directorySize *= 2;

    table->directory =
        realloc(
            table->directory,
            table->directorySize
            *
            sizeof(Bucket*)
        );

    for (
        int i = 0;
        i < oldSize;
        i++
    ) {

        table->directory[
            i + oldSize
        ]
        =
        table->directory[i];
    }

    table->globalDepth++;
}


/* Split bucket */
void splitBucket(
    DynamicHash* table,
    int index
) {

    Bucket* old =
        table->directory[index];

    if (
        old->localDepth
        ==
        table->globalDepth
    ) {

        expandDirectory(
            table
        );
    }

    Bucket* fresh =
        createBucket(
            old->localDepth
            + 1
        );

    old->localDepth++;

    int mask =
        1
        <<
        (
            old->localDepth
            - 1
        );

    for (
        int i = 0;
        i < table->directorySize;
        i++
    ) {

        if (
            table->directory[i]
            ==
            old
            &&
            (
                i & mask
            )
        ) {

            table->directory[i]
            =
            fresh;
        }
    }

    int temp[BUCKET_SIZE];

    int count =
        old->count;

    for (
        int i=0;
        i<count;
        i++
    ) {

        temp[i] =
            old->values[i];
    }

    old->count = 0;

    for (
        int i=0;
        i<count;
        i++
    ) {

        int newIndex =
            getIndex(
                table,
                temp[i]
            );

        Bucket* target =
            table->directory[
                newIndex
            ];

        target->values[
            target->count++
        ]
        =
        temp[i];
    }
}


/* Insert key */
void insert(
    DynamicHash* table,
    int key
) {

    while (1) {

        int index =
            getIndex(
                table,
                key
            );

        Bucket* bucket =
            table->directory[
                index
            ];

        if (
            bucket->count
            <
            BUCKET_SIZE
        ) {

            bucket->values[
                bucket->count++
            ]
            =
            key;

            return;
        }

        splitBucket(
            table,
            index
        );
    }
}


/* Search */
int search(
    DynamicHash* table,
    int key
) {

    int index =
        getIndex(
            table,
            key
        );

    Bucket* bucket =
        table->directory[
            index
        ];

    for (
        int i=0;
        i<bucket->count;
        i++
    ) {

        if (
            bucket->values[i]
            ==
            key
        )
            return 1;
    }

    return 0;
}


/* Display */
void display(
    DynamicHash* table
) {

    printf(
        "\nGlobal Depth: %d\n",
        table->globalDepth
    );

    for (
        int i=0;
        i<table->directorySize;
        i++
    ) {

        printf(
            "Dir[%d]: ",
            i
        );

        Bucket* bucket =
            table->directory[i];

        for (
            int j=0;
            j<bucket->count;
            j++
        ) {

            printf(
                "%d ",
                bucket->values[j]
            );
        }

        printf("\n");
    }
}


int main() {

    DynamicHash* hash =
        createTable();

    insert(hash, 10);
    insert(hash, 22);
    insert(hash, 14);
    insert(hash, 30);
    insert(hash, 42);
    insert(hash, 54);

    display(hash);

    printf(
        "\nSearch 42: %s\n",
        search(
            hash,
            42
        )
        ?
        "Found"
        :
        "Not Found"
    );

    return 0;
}
