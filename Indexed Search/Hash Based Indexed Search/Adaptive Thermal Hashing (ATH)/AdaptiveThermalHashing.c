#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUCKETS 8
#define THRESHOLD 3

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int temperature;
    int size;
} Bucket;

typedef struct {
    Bucket* buckets;
    int bucketCount;
} ATH;

int hash(int key, int size) {
    return abs(key) % size;
}

ATH* createATH() {
    ATH* h = malloc(sizeof(ATH));
    h->bucketCount = INITIAL_BUCKETS;
    h->buckets = calloc(INITIAL_BUCKETS, sizeof(Bucket));
    return h;
}

void split(ATH* h) {
    int old = h->bucketCount;

    Bucket* nb = calloc(old * 2, sizeof(Bucket));

    for (int i=0;i<old;i++) {
        Node* cur = h->buckets[i].head;

        while(cur){
            Node* nxt = cur->next;

            int idx = hash(cur->key, old * 2);

            cur->next = nb[idx].head;
            nb[idx].head = cur;
            nb[idx].size++;

            cur = nxt;
        }
    }

    free(h->buckets);

    h->buckets = nb;
    h->bucketCount *= 2;
}

void insert(ATH* h,int key,int value){

    int idx = hash(key,h->bucketCount);

    Node* n = malloc(sizeof(Node));

    n->key=key;
    n->value=value;

    n->next=h->buckets[idx].head;

    h->buckets[idx].head=n;

    h->buckets[idx].size++;

    if(h->buckets[idx].size>THRESHOLD)
        split(h);
}

int search(ATH* h,int key){

    int idx=hash(key,h->bucketCount);

    h->buckets[idx].temperature++;

    Node* cur=h->buckets[idx].head;

    while(cur){

        if(cur->key==key)
            return cur->value;

        cur=cur->next;
    }

    return -1;
}

int main(){

    ATH* h=createATH();

    insert(h,10,100);
    insert(h,20,200);

    printf("%d\n",search(h,20));

    return 0;
}
