#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11
#define EMPTY -1
#define MAX_KICKS 20

typedef struct {
    int table1[TABLE_SIZE];
    int table2[TABLE_SIZE];
} CuckooHash;

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return (key / TABLE_SIZE) % TABLE_SIZE;
}

void init(CuckooHash *h) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        h->table1[i] = EMPTY;
        h->table2[i] = EMPTY;
    }
}

int search(CuckooHash *h, int key) {
    int pos1 = hash1(key);
    int pos2 = hash2(key);

    return h->table1[pos1] == key ||
           h->table2[pos2] == key;
}

int insert(CuckooHash *h, int key) {
    int current = key;
    int table = 1;

    for (int i = 0; i < MAX_KICKS; i++) {
        if (table == 1) {
            int pos = hash1(current);

            if (h->table1[pos] == EMPTY) {
                h->table1[pos] = current;
                return 1;
            }

            int temp = h->table1[pos];
            h->table1[pos] = current;
            current = temp;
            table = 2;
        } else {
            int pos = hash2(current);

            if (h->table2[pos] == EMPTY) {
                h->table2[pos] = current;
                return 1;
            }

            int temp = h->table2[pos];
            h->table2[pos] = current;
            current = temp;
            table = 1;
        }
    }

    return 0;
}

int main() {
    CuckooHash h;
    init(&h);

    insert(&h, 20);
    insert(&h, 50);
    insert(&h, 53);
    insert(&h, 75);

    printf("%s\n",
           search(&h, 53) ? "Found" : "Not Found");

    return 0;
}
