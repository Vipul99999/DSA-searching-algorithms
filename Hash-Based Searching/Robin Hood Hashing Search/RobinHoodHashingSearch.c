#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 11
#define EMPTY -1

typedef struct {
    int table[TABLE_SIZE];
} RobinHoodHash;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void init(RobinHoodHash *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = EMPTY;
    }
}

int probeDistance(int key, int pos) {
    int home = hashFunction(key);

    return (pos - home + TABLE_SIZE)
           % TABLE_SIZE;
}

bool insert(RobinHoodHash *ht, int key) {

    int current = key;
    int pos = hashFunction(current);

    while (1) {

        if (ht->table[pos] == EMPTY) {

            ht->table[pos] = current;

            return true;
        }

        int resident =
            ht->table[pos];

        int currentDist =
            probeDistance(
                current,
                pos
            );

        int residentDist =
            probeDistance(
                resident,
                pos
            );

        if (
            currentDist >
            residentDist
        ) {

            int temp =
                ht->table[pos];

            ht->table[pos] =
                current;

            current = temp;
        }

        pos =
            (pos + 1)
            % TABLE_SIZE;
    }
}

bool search(
    RobinHoodHash *ht,
    int key
) {

    int pos =
        hashFunction(key);

    int dist = 0;

    while (
        ht->table[pos]
        != EMPTY
    ) {

        if (
            ht->table[pos]
            == key
        ) {
            return true;
        }

        int residentDist =
            probeDistance(
                ht->table[pos],
                pos
            );

        if (
            residentDist < dist
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

void display(
    RobinHoodHash *ht
) {

    printf("\nHash Table\n");

    for (
        int i = 0;
        i < TABLE_SIZE;
        i++
    ) {

        printf("[%d] = ", i);

        if (
            ht->table[i]
            == EMPTY
        ) {
            printf("EMPTY\n");
        }
        else {
            printf(
                "%d\n",
                ht->table[i]
            );
        }
    }
}

int main() {

    RobinHoodHash ht;

    init(&ht);

    insert(&ht, 22);
    insert(&ht, 33);
    insert(&ht, 44);
    insert(&ht, 55);
    insert(&ht, 66);

    display(&ht);

    printf(
        "\nSearch 44: %s\n",
        search(&ht, 44)
        ? "Found"
        : "Not Found"
    );

    return 0;
}
