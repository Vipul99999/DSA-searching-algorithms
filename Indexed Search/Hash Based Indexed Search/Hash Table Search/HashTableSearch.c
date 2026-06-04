// Hash Function:
// index = key % tableSize

// Example:
// key = 27
// tableSize = 10

// index = 27 % 10 = 7
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

/* Node for linked list chaining */
typedef struct Node {
    int key;
    struct Node* next;
} Node;

/* Hash table */
Node* hashTable[TABLE_SIZE] = {NULL};

/*
    Hash Function

    Formula:
    h(key) = key % TABLE_SIZE
*/
int hash(int key) {
    return key % TABLE_SIZE;
}

/* Insert key */
void insert(int key) {

    int index = hash(key);

    Node* newNode =
        (Node*)malloc(sizeof(Node));

    newNode->key = key;

    newNode->next =
        hashTable[index];

    hashTable[index] =
        newNode;
}

/* Search key */
int search(int key) {

    int index = hash(key);

    Node* current =
        hashTable[index];

    while (current != NULL) {

        if (current->key == key)
            return 1;

        current =
            current->next;
    }

    return 0;
}

/* Delete key */
void deleteKey(int key) {

    int index = hash(key);

    Node* current =
        hashTable[index];

    Node* previous = NULL;

    while (current) {

        if (current->key == key) {

            if (previous)
                previous->next =
                    current->next;
            else
                hashTable[index] =
                    current->next;

            free(current);

            return;
        }

        previous = current;

        current = current->next;
    }
}

/* Display table */
void display() {

    for (int i = 0; i < TABLE_SIZE; i++) {

        printf("[%d]: ", i);

        Node* current =
            hashTable[i];

        while (current) {

            printf(
                "%d -> ",
                current->key
            );

            current =
                current->next;
        }

        printf("NULL\n");
    }
}

int main() {

    insert(10);
    insert(20);
    insert(35);
    insert(25);

    display();

    printf(
        "\nSearch 20: %s\n",
        search(20)
        ? "Found"
        : "Not Found"
    );

    deleteKey(20);

    display();

    return 0;
}
