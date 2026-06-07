/*
    ExtendibleHashing.c
    ANSI C / C17

    Educational implementation of Extendible Hashing.

    Features:
    - Global Depth
    - Local Depth
    - Directory Doubling
    - Bucket Splitting
    - Insert
    - Search
    - Delete
    - Display

    Compile:
    gcc -std=c17 ExtendibleHashing.c -o ExtendibleHashing

    Run:
    ./ExtendibleHashing
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 4

typedef struct Bucket {
    int localDepth;
    int count;
    int keys[BUCKET_SIZE];
} Bucket;

typedef struct {
    int globalDepth;
    int directorySize;
    Bucket **directory;
} ExtendibleHash;

static int hashKey(int key) {
    return key;
}

Bucket* createBucket(int depth) {
    Bucket *bucket = (Bucket*)malloc(sizeof(Bucket));

    bucket->localDepth = depth;
    bucket->count = 0;

    memset(bucket->keys, 0, sizeof(bucket->keys));

    return bucket;
}

ExtendibleHash* createHashTable() {
    ExtendibleHash *hash =
        (ExtendibleHash*)malloc(sizeof(ExtendibleHash));

    hash->globalDepth = 1;
    hash->directorySize = 2;

    hash->directory =
        (Bucket**)malloc(sizeof(Bucket*) * 2);

    hash->directory[0] = createBucket(1);
    hash->directory[1] = createBucket(1);

    return hash;
}

int getDirectoryIndex(
    ExtendibleHash *hash,
    int key
) {
    int mask = (1 << hash->globalDepth) - 1;
    return hashKey(key) & mask;
}

void doubleDirectory(ExtendibleHash *hash) {
    int oldSize = hash->directorySize;
    int newSize = oldSize * 2;

    Bucket **newDirectory =
        (Bucket**)malloc(sizeof(Bucket*) * newSize);

    for (int i = 0; i < oldSize; i++) {
        newDirectory[i] = hash->directory[i];
        newDirectory[i + oldSize] =
            hash->directory[i];
    }

    free(hash->directory);

    hash->directory = newDirectory;
    hash->directorySize = newSize;
    hash->globalDepth++;
}

void splitBucket(
    ExtendibleHash *hash,
    int bucketIndex
);

void insertKey(
    ExtendibleHash *hash,
    int key
) {
    while (1) {

        int index =
            getDirectoryIndex(hash, key);

        Bucket *bucket =
            hash->directory[index];

        if (bucket->count < BUCKET_SIZE) {

            bucket->keys[bucket->count++] =
                key;

            return;
        }

        splitBucket(hash, index);
    }
}

void redistributeKeys(
    ExtendibleHash *hash,
    Bucket *oldBucket,
    Bucket *newBucket
) {
    int temp[BUCKET_SIZE];
    int count = oldBucket->count;

    for (int i = 0; i < count; i++) {
        temp[i] = oldBucket->keys[i];
    }

    oldBucket->count = 0;

    for (int i = 0; i < count; i++) {

        int index =
            getDirectoryIndex(hash, temp[i]);

        Bucket *target =
            hash->directory[index];

        target->keys[target->count++] =
            temp[i];
    }
}

void splitBucket(
    ExtendibleHash *hash,
    int bucketIndex
) {
    Bucket *oldBucket =
        hash->directory[bucketIndex];

    int oldDepth =
        oldBucket->localDepth;

    if (oldDepth == hash->globalDepth) {
        doubleDirectory(hash);
    }

    Bucket *newBucket =
        createBucket(oldDepth + 1);

    oldBucket->localDepth++;

    int pattern =
        1 << (oldBucket->localDepth - 1);

    for (int i = 0;
         i < hash->directorySize;
         i++) {

        if (hash->directory[i] ==
            oldBucket) {

            if (i & pattern) {
                hash->directory[i] =
                    newBucket;
            }
        }
    }

    redistributeKeys(
        hash,
        oldBucket,
        newBucket
    );
}

int searchKey(
    ExtendibleHash *hash,
    int key
) {
    int index =
        getDirectoryIndex(hash, key);

    Bucket *bucket =
        hash->directory[index];

    for (int i = 0;
         i < bucket->count;
         i++) {

        if (bucket->keys[i] == key) {
            return 1;
        }
    }

    return 0;
}

int deleteKey(
    ExtendibleHash *hash,
    int key
) {
    int index =
        getDirectoryIndex(hash, key);

    Bucket *bucket =
        hash->directory[index];

    for (int i = 0;
         i < bucket->count;
         i++) {

        if (bucket->keys[i] == key) {

            bucket->keys[i] =
                bucket->keys[
                    bucket->count - 1
                ];

            bucket->count--;

            return 1;
        }
    }

    return 0;
}

void displayHash(
    ExtendibleHash *hash
) {
    printf("\n");
    printf(
        "Global Depth: %d\n",
        hash->globalDepth
    );

    printf(
        "Directory Size: %d\n\n",
        hash->directorySize
    );

    for (int i = 0;
         i < hash->directorySize;
         i++) {

        Bucket *bucket =
            hash->directory[i];

        printf(
            "Dir[%d] -> "
            "LD=%d : ",
            i,
            bucket->localDepth
        );

        for (int j = 0;
             j < bucket->count;
             j++) {

            printf(
                "%d ",
                bucket->keys[j]
            );
        }

        printf("\n");
    }
}

void freeHashTable(
    ExtendibleHash *hash
) {
    Bucket **visited =
        (Bucket**)malloc(
            sizeof(Bucket*)
            * hash->directorySize
        );

    int visitedCount = 0;

    for (int i = 0;
         i < hash->directorySize;
         i++) {

        Bucket *bucket =
            hash->directory[i];

        int already = 0;

        for (int j = 0;
             j < visitedCount;
             j++) {

            if (visited[j] == bucket) {
                already = 1;
                break;
            }
        }

        if (!already) {
            visited[
                visitedCount++
            ] = bucket;

            free(bucket);
        }
    }

    free(visited);
    free(hash->directory);
    free(hash);
}

int main() {

    ExtendibleHash *hash =
        createHashTable();

    int values[] = {
        5, 12, 25, 33,
        41, 18, 29, 37,
        49, 52, 61, 73
    };

    int n =
        sizeof(values)
        / sizeof(values[0]);

    for (int i = 0;
         i < n;
         i++) {

        insertKey(
            hash,
            values[i]
        );
    }

    displayHash(hash);

    printf(
        "\nSearch 29: %s\n",
        searchKey(hash, 29)
        ? "Found"
        : "Not Found"
    );

    printf(
        "Search 100: %s\n",
        searchKey(hash, 100)
        ? "Found"
        : "Not Found"
    );

    deleteKey(hash, 29);

    printf(
        "\nAfter deleting 29:\n"
    );

    displayHash(hash);

    freeHashTable(hash);

    return 0;
}
