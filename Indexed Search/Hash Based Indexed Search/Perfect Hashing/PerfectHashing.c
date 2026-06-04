#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1
#define PRIME 10000019

typedef struct {
    int size;
    int a;
    int b;
    int* table;
} SecondaryTable;

typedef struct {
    int bucketCount;
    SecondaryTable* buckets;
} PerfectHash;


/* Primary Hash */
int hash1(int key, int bucketCount) {
    return key % bucketCount;
}


/* Secondary Hash */
int hash2(
    int key,
    int a,
    int b,
    int size
) {

    return (
        (
            a * key + b
        )
        %
        PRIME
    )
    %
    size;
}


void build(
    PerfectHash* ph,
    int keys[],
    int n
) {

    ph->bucketCount = n;

    ph->buckets =
        calloc(
            n,
            sizeof(
                SecondaryTable
            )
        );

    int counts[n];

    for (
        int i = 0;
        i < n;
        i++
    )
        counts[i] = 0;


    for (
        int i = 0;
        i < n;
        i++
    ) {

        counts[
            hash1(
                keys[i],
                n
            )
        ]++;
    }


    for (
        int i = 0;
        i < n;
        i++
    ) {

        int s =
            counts[i];

        if (s == 0)
            continue;

        ph
        ->
        buckets[i]
        .size =
        s * s;

        ph
        ->
        buckets[i]
        .a =
        7;

        ph
        ->
        buckets[i]
        .b =
        13;

        ph
        ->
        buckets[i]
        .table =
        malloc(
            s
            *
            s
            *
            sizeof(int)
        );

        for (
            int j = 0;
            j < s * s;
            j++
        )
            ph
            ->
            buckets[i]
            .table[j]
            =
            EMPTY;
    }


    for (
        int i = 0;
        i < n;
        i++
    ) {

        int bucket =
            hash1(
                keys[i],
                n
            );

        SecondaryTable* st =
            &
            ph
            ->
            buckets[
                bucket
            ];

        int pos =
            hash2(
                keys[i],
                st->a,
                st->b,
                st->size
            );

        st
        ->
        table[pos]
        =
        keys[i];
    }
}


int search(
    PerfectHash* ph,
    int key
) {

    int bucket =
        hash1(
            key,
            ph
            ->
            bucketCount
        );

    SecondaryTable* st =
        &
        ph
        ->
        buckets[
            bucket
        ];

    if (
        st
        ->
        size
        ==
        0
    )
        return 0;

    int pos =
        hash2(
            key,
            st->a,
            st->b,
            st->size
        );

    return
        st
        ->
        table[pos]
        ==
        key;
}


int main() {

    int keys[] =
    {
        10,
        25,
        42,
        50,
        67
    };

    PerfectHash ph;

    build(
        &ph,
        keys,
        5
    );

    printf(
        "%s\n",
        search(
            &ph,
            42
        )
        ?
        "Found"
        :
        "Not Found"
    );
}
