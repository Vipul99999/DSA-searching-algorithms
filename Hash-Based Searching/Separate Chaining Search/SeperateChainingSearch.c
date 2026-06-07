#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[TABLE_SIZE];
} HashTable;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void init(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->buckets[i] = NULL;
    }
}

void insert(HashTable* ht, int key) {
    int index = hashFunction(key);

    Node* newNode =
        (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->next = ht->buckets[index];

    ht->buckets[index] = newNode;
}

bool search(HashTable* ht, int key) {
    int index = hashFunction(key);

    Node* current =
        ht->buckets[index];

    while (current != NULL) {

        if (current->key == key)
            return true;

        current = current->next;
    }

    return false;
}

void display(HashTable* ht) {

    printf("\nHash Table\n");

    for (int i = 0; i < TABLE_SIZE; i++) {

        printf("[%d] -> ", i);

        Node* current =
            ht->buckets[i];

        while (current) {
            printf("%d -> ",
                   current->key);

            current = current->next;
        }

        printf("NULL\n");
    }
}

int main() {

    HashTable ht;

    init(&ht);

    insert(&ht, 15);
    insert(&ht, 25);
    insert(&ht, 35);
    insert(&ht, 42);

    display(&ht);

    printf(
        "\nSearch 35: %s\n",
        search(&ht, 35)
        ? "Found"
        : "Not Found"
    );

    return 0;
}
