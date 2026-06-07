#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 13
#define EMPTY -1

typedef struct {
    int table[TABLE_SIZE];
} DoubleHashTable;

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void init(DoubleHashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = EMPTY;
    }
}

bool insert(DoubleHashTable *ht, int key) {
    int h1 = hash1(key);
    int h2 = hash2(key);

    for (int i = 0; i < TABLE_SIZE; i++) {

        int pos =
            (h1 + i * h2)
            % TABLE_SIZE;

        if (ht->table[pos] == EMPTY) {

            ht->table[pos] = key;

            return true;
        }
    }

    return false;
}

bool search(DoubleHashTable *ht, int key) {

    int h1 = hash1(key);
    int h2 = hash2(key);

    for (int i = 0; i < TABLE_SIZE; i++) {

        int pos =
            (h1 + i * h2)
            % TABLE_SIZE;

        if (ht->table[pos] == EMPTY)
            return false;

        if (ht->table[pos] == key)
            return true;
    }

    return false;
}

void display(DoubleHashTable *ht) {

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

    DoubleHashTable ht;

    init(&ht);

    insert(&ht, 25);
    insert(&ht, 38);
    insert(&ht, 51);
    insert(&ht, 64);

    display(&ht);

    printf(
        "\nSearch 51: %s\n",
        search(&ht, 51)
        ? "Found"
        : "Not Found"
    );

    return 0;
}
