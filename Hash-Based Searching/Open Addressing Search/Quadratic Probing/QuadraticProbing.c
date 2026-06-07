#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 11
#define EMPTY -1

typedef struct {
    int table[TABLE_SIZE];
} QuadraticProbingHashTable;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void init(QuadraticProbingHashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = EMPTY;
    }
}

bool insert(QuadraticProbingHashTable *ht, int key) {

    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) {

        int pos =
            (index + i * i)
            % TABLE_SIZE;

        if (ht->table[pos] == EMPTY) {

            ht->table[pos] = key;

            return true;
        }
    }

    return false;
}

bool search(
    QuadraticProbingHashTable *ht,
    int key
) {

    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++) {

        int pos =
            (index + i * i)
            % TABLE_SIZE;

        if (ht->table[pos] == EMPTY)
            return false;

        if (ht->table[pos] == key)
            return true;
    }

    return false;
}

void display(
    QuadraticProbingHashTable *ht
) {

    printf("\nHash Table\n");

    for (int i = 0; i < TABLE_SIZE; i++) {

        printf("[%d] = ", i);

        if (ht->table[i] == EMPTY)
            printf("EMPTY\n");
        else
            printf("%d\n",
                   ht->table[i]);
    }
}

int main() {

    QuadraticProbingHashTable ht;

    init(&ht);

    insert(&ht, 22);
    insert(&ht, 33);
    insert(&ht, 44);
    insert(&ht, 55);

    display(&ht);

    printf(
        "\nSearch 44: %s\n",
        search(&ht, 44)
        ? "Found"
        : "Not Found"
    );

    return 0;
}
