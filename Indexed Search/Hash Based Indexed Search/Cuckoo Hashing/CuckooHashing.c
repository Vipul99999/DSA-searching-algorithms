#include <stdio.h>

#define TABLE_SIZE 11
#define EMPTY -1
#define MAX_KICKS 20

typedef struct {
    int table1[TABLE_SIZE];
    int table2[TABLE_SIZE];
} CuckooHash;

/* Hash Function 1
   h1(k)=k mod TABLE_SIZE
*/
int hash1(int key) {
    return key % TABLE_SIZE;
}

/* Hash Function 2
   h2(k)=floor(k/TABLE_SIZE) mod TABLE_SIZE
*/
int hash2(int key) {
    return (key / TABLE_SIZE) % TABLE_SIZE;
}

void initialize(CuckooHash* hash) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash->table1[i] = EMPTY;
        hash->table2[i] = EMPTY;
    }
}

int search(CuckooHash* hash, int key) {
    return (
        hash->table1[hash1(key)] == key ||
        hash->table2[hash2(key)] == key
    );
}

int insert(CuckooHash* hash, int key) {

    if (search(hash, key))
        return 1;

    int current = key;
    int table = 1;

    for (int kick = 0; kick < MAX_KICKS; kick++) {

        if (table == 1) {

            int index = hash1(current);

            if (hash->table1[index] == EMPTY) {
                hash->table1[index] = current;
                return 1;
            }

            int temp = hash->table1[index];
            hash->table1[index] = current;

            current = temp;
            table = 2;

        } else {

            int index = hash2(current);

            if (hash->table2[index] == EMPTY) {
                hash->table2[index] = current;
                return 1;
            }

            int temp = hash->table2[index];
            hash->table2[index] = current;

            current = temp;
            table = 1;
        }
    }

    printf("Cycle detected. Rehash required.\n");
    return 0;
}

void removeKey(CuckooHash* hash, int key) {

    int i1 = hash1(key);
    int i2 = hash2(key);

    if (hash->table1[i1] == key)
        hash->table1[i1] = EMPTY;

    if (hash->table2[i2] == key)
        hash->table2[i2] = EMPTY;
}

void display(CuckooHash* hash) {

    printf("\nTable 1\n");

    for (int i = 0; i < TABLE_SIZE; i++)
        printf("[%d] %d\n", i, hash->table1[i]);

    printf("\nTable 2\n");

    for (int i = 0; i < TABLE_SIZE; i++)
        printf("[%d] %d\n", i, hash->table2[i]);
}

int main() {

    CuckooHash hash;

    initialize(&hash);

    insert(&hash, 20);
    insert(&hash, 50);
    insert(&hash, 53);
    insert(&hash, 75);

    display(&hash);

    printf(
        "\nSearch 53: %s\n",
        search(&hash, 53)
            ? "Found"
            : "Not Found"
    );

    removeKey(&hash, 53);

    return 0;
}
