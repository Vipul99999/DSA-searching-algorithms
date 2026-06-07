#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 16
#define HOP_RANGE 4
#define EMPTY -1

typedef struct {
    int key;
    bool occupied;
    unsigned int hopInfo;
} Bucket;

typedef struct {
    Bucket table[TABLE_SIZE];
} HopscotchHashTable;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void init(HopscotchHashTable *ht) {

    for (int i = 0; i < TABLE_SIZE; i++) {

        ht->table[i].key = EMPTY;
        ht->table[i].occupied = false;
        ht->table[i].hopInfo = 0;
    }
}

bool insert(
    HopscotchHashTable *ht,
    int key
) {

    int home =
        hashFunction(key);

    int freePos = -1;

    for (
        int i = home;
        i < TABLE_SIZE;
        i++
    ) {

        if (
            !ht->table[i].occupied
        ) {

            freePos = i;
            break;
        }
    }

    if (freePos == -1)
        return false;

    while (
        freePos - home >= HOP_RANGE
    ) {

        bool moved = false;

        for (
            int i =
                freePos -
                (HOP_RANGE - 1);

            i < freePos;

            i++
        ) {

            unsigned int hop =
                ht->table[i]
                .hopInfo;

            for (
                int j =
                    HOP_RANGE - 1;

                j > 0;

                j--
            ) {

                if (
                    hop &
                    (1U << j)
                ) {

                    int neighbor =
                        i + j;

                    ht->table[
                        freePos
                    ] =
                    ht->table[
                        neighbor
                    ];

                    ht->table[i]
                    .hopInfo ^= (
                        1U << j
                    );

                    ht->table[i]
                    .hopInfo |= (
                        1U <<
                        (
                            freePos
                            - i
                        )
                    );

                    freePos =
                        neighbor;

                    moved = true;

                    break;
                }
            }

            if (moved)
                break;
        }

        if (!moved)
            return false;
    }

    ht->table[
        freePos
    ].key = key;

    ht->table[
        freePos
    ].occupied = true;

    ht->table[
        home
    ].hopInfo |=
        (
            1U <<
            (
                freePos
                - home
            )
        );

    return true;
}

bool search(
    HopscotchHashTable *ht,
    int key
) {

    int home =
        hashFunction(key);

    unsigned int hop =
        ht->table[home]
        .hopInfo;

    for (
        int i = 0;
        i < HOP_RANGE;
        i++
    ) {

        if (
            hop &
            (1U << i)
        ) {

            int pos =
                home + i;

            if (
                pos < TABLE_SIZE &&
                ht->table[pos]
                .occupied &&
                ht->table[pos]
                .key == key
            ) {

                return true;
            }
        }
    }

    return false;
}

void display(
    HopscotchHashTable *ht
) {

    printf(
        "\nHopscotch Hash Table\n"
    );

    for (
        int i = 0;
        i < TABLE_SIZE;
        i++
    ) {

        printf(
            "[%d] = ",
            i
        );

        if (
            ht->table[i]
            .occupied
        ) {

            printf(
                "%d",
                ht->table[i]
                .key
            );
        }
        else {

            printf("EMPTY");
        }

        printf(
            " (hop=%u)\n",
            ht->table[i]
            .hopInfo
        );
    }
}

int main() {

    HopscotchHashTable ht;

    init(&ht);

    insert(&ht, 5);
    insert(&ht, 21);
    insert(&ht, 37);
    insert(&ht, 53);

    display(&ht);

    printf(
        "\nSearch 37: %s\n",
        search(&ht, 37)
        ? "Found"
        : "Not Found"
    );

    return 0;
}
