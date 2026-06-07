/*
    LinearHashing.c
    ANSI C / C17

    Features:
    - Dynamic Bucket Growth
    - Split Pointer
    - Level-Based Hashing
    - Bucket Splitting
    - Insert
    - Search
    - Display

    Compile:
    gcc -std=c17 LinearHashing.c -o LinearHashing

    Run:
    ./LinearHashing
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUCKET_SIZE 4
#define INITIAL_BUCKETS 2

typedef struct Bucket {
    int keys[BUCKET_SIZE];
    int count;

    struct Bucket* overflow;
} Bucket;

typedef struct {
    Bucket** buckets;

    int bucketCount;
    int level;
    int next;
} LinearHashTable;

/* ---------- Bucket Utilities ---------- */

Bucket* createBucket() {

    Bucket* bucket =
        (Bucket*)malloc(
            sizeof(Bucket)
        );

    bucket->count = 0;
    bucket->overflow = NULL;

    return bucket;
}

void freeBucketChain(
    Bucket* bucket
) {
    while (bucket) {

        Bucket* temp =
            bucket;

        bucket =
            bucket->overflow;

        free(temp);
    }
}

/* ---------- Hash Functions ---------- */

int hashLevel(
    LinearHashTable* ht,
    int key
) {
    return key %
           (INITIAL_BUCKETS
            << ht->level);
}

int hashNextLevel(
    LinearHashTable* ht,
    int key
) {
    return key %
           (INITIAL_BUCKETS
            << (ht->level + 1));
}

int bucketIndex(
    LinearHashTable* ht,
    int key
) {
    int idx =
        hashLevel(ht, key);

    if (idx < ht->next) {
        idx =
            hashNextLevel(
                ht,
                key
            );
    }

    return idx;
}

/* ---------- Create Hash Table ---------- */

LinearHashTable*
createHashTable() {

    LinearHashTable* ht =
        (LinearHashTable*)
        malloc(
            sizeof(
                LinearHashTable
            )
        );

    ht->bucketCount =
        INITIAL_BUCKETS;

    ht->level = 0;
    ht->next = 0;

    ht->buckets =
        (Bucket**)malloc(
            sizeof(Bucket*)
            * ht->bucketCount
        );

    for (int i = 0;
         i < ht->bucketCount;
         i++) {

        ht->buckets[i] =
            createBucket();
    }

    return ht;
}

/* ---------- Insert Into Bucket ---------- */

void insertIntoBucket(
    Bucket* bucket,
    int key
) {

    Bucket* current =
        bucket;

    while (1) {

        if (
            current->count <
            BUCKET_SIZE
        ) {

            current->keys[
                current->count++
            ] = key;

            return;
        }

        if (
            current->overflow ==
            NULL
        ) {

            current->overflow =
                createBucket();
        }

        current =
            current->overflow;
    }
}

/* ---------- Split Bucket ---------- */

void splitBucket(
    LinearHashTable* ht
) {

    int splitIndex =
        ht->next;

    ht->bucketCount++;

    ht->buckets =
        (Bucket**)realloc(
            ht->buckets,
            sizeof(Bucket*)
            * ht->bucketCount
        );

    ht->buckets[
        ht->bucketCount - 1
    ] = createBucket();

    Bucket* oldBucket =
        ht->buckets[
            splitIndex
        ];

    int temp[1024];
    int total = 0;

    Bucket* current =
        oldBucket;

    while (current) {

        for (
            int i = 0;
            i < current->count;
            i++
        ) {
            temp[total++] =
                current->keys[i];
        }

        current =
            current->overflow;
    }

    freeBucketChain(
        oldBucket
    );

    ht->buckets[
        splitIndex
    ] = createBucket();

    for (
        int i = 0;
        i < total;
        i++
    ) {

        int idx =
            hashNextLevel(
                ht,
                temp[i]
            );

        insertIntoBucket(
            ht->buckets[idx],
            temp[i]
        );
    }

    ht->next++;

    int roundSize =
        INITIAL_BUCKETS
        << ht->level;

    if (
        ht->next ==
        roundSize
    ) {

        ht->next = 0;
        ht->level++;
    }
}

/* ---------- Insert ---------- */

void insert(
    LinearHashTable* ht,
    int key
) {

    int idx =
        bucketIndex(
            ht,
            key
        );

    insertIntoBucket(
        ht->buckets[idx],
        key
    );

    splitBucket(ht);
}

/* ---------- Search ---------- */

bool search(
    LinearHashTable* ht,
    int key
) {

    int idx =
        bucketIndex(
            ht,
            key
        );

    Bucket* current =
        ht->buckets[idx];

    while (current) {

        for (
            int i = 0;
            i < current->count;
            i++
        ) {

            if (
                current->keys[i]
                == key
            ) {
                return true;
            }
        }

        current =
            current->overflow;
    }

    return false;
}

/* ---------- Display ---------- */

void display(
    LinearHashTable* ht
) {

    printf(
        "\nLevel: %d\n",
        ht->level
    );

    printf(
        "Next Split: %d\n",
        ht->next
    );

    printf(
        "Bucket Count: %d\n\n",
        ht->bucketCount
    );

    for (
        int i = 0;
        i < ht->bucketCount;
        i++
    ) {

        printf(
            "Bucket[%d] : ",
            i
        );

        Bucket* current =
            ht->buckets[i];

        while (current) {

            for (
                int j = 0;
                j < current->count;
                j++
            ) {

                printf(
                    "%d ",
                    current->keys[j]
                );
            }

            if (
                current->overflow
            ) {
                printf(
                    "-> "
                );
            }

            current =
                current->overflow;
        }

        printf("\n");
    }
}

/* ---------- Free ---------- */

void freeHashTable(
    LinearHashTable* ht
) {

    for (
        int i = 0;
        i < ht->bucketCount;
        i++
    ) {

        freeBucketChain(
            ht->buckets[i]
        );
    }

    free(
        ht->buckets
    );

    free(ht);
}

/* ---------- Driver ---------- */

int main() {

    LinearHashTable* ht =
        createHashTable();

    int values[] = {
        5, 12, 25, 33,
        41, 18, 29, 37,
        49, 52, 61, 73
    };

    int n =
        sizeof(values)
        / sizeof(values[0]);

    for (
        int i = 0;
        i < n;
        i++
    ) {

        insert(
            ht,
            values[i]
        );
    }

    display(ht);

    printf(
        "\nSearch 29: %s\n",
        search(ht, 29)
        ? "Found"
        : "Not Found"
    );

    printf(
        "Search 100: %s\n",
        search(ht, 100)
        ? "Found"
        : "Not Found"
    );

    freeHashTable(ht);

    return 0;
}
