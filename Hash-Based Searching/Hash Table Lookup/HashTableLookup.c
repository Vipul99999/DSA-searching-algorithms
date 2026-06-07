#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 101
#define EMPTY -1

typedef struct {
    int table[TABLE_SIZE];
} HashTable;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void init(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = EMPTY;
    }
}

bool insert(HashTable *ht, int key) {
    int index = hashFunction(key);

    if (ht->table[index] != EMPTY)
        return false;

    ht->table[index] = key;
    return true;
}

bool lookup(HashTable *ht, int key) {
    int index = hashFunction(key);
    return ht->table[index] == key;
}

int main() {
    HashTable ht;
    init(&ht);

    insert(&ht, 15);
    insert(&ht, 42);
    insert(&ht, 99);

    printf("%s\n",
           lookup(&ht, 42)
           ? "Found"
           : "Not Found");

    return 0;
}
