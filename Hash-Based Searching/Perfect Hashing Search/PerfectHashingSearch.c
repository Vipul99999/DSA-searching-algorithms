#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10
#define EMPTY -1

typedef struct {
    int table[TABLE_SIZE];
} PerfectHashTable;

int perfectHash(int key) {
    switch (key) {
        case 11: return 0;
        case 22: return 1;
        case 33: return 2;
        case 44: return 3;
        case 55: return 4;
        default: return -1;
    }
}

void init(PerfectHashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++)
        ht->table[i] = EMPTY;

    ht->table[0] = 11;
    ht->table[1] = 22;
    ht->table[2] = 33;
    ht->table[3] = 44;
    ht->table[4] = 55;
}

bool search(
    PerfectHashTable *ht,
    int key
) {
    int idx = perfectHash(key);

    if (idx == -1)
        return false;

    return ht->table[idx] == key;
}

int main() {

    PerfectHashTable ht;

    init(&ht);

    printf(
        "Search 33: %s\n",
        search(&ht,33)
        ? "Found"
        : "Not Found"
    );

    return 0;
}
