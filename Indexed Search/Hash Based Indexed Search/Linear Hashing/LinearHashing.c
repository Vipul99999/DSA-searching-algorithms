#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUCKETS 4
#define LOAD_FACTOR 2.0

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} Bucket;

typedef struct {

    Bucket* buckets;

    int level;

    int split;

    int size;

    int count;

} LinearHash;

/*
Primary Hash:
h(k)=k mod (N×2^L)
*/
int hash(int key,int level){

    return key %
    (
        INITIAL_BUCKETS
        <<
        level
    );
}

/*
Split Hash:
h'(k)=k mod (N×2^(L+1))
*/
int splitHash(
int key,
int level
){

return key%
(
INITIAL_BUCKETS
<<
(level+1)
);

}

LinearHash* create(){

LinearHash* h=
malloc(
sizeof(
LinearHash
)
);

h->level=0;

h->split=0;

h->count=0;

h->size=
INITIAL_BUCKETS;

h->buckets=
calloc(
INITIAL_BUCKETS,
sizeof(
Bucket
)
);

return h;

}

void expand(
LinearHash* h
){

h->size++;

h->buckets=
realloc(
h->buckets,
h->size
*
sizeof(
Bucket
)
);

h->buckets[
h->size-1
].head=NULL;

}

void insertNode(
Bucket* b,
int key
){

Node* n=
malloc(
sizeof(Node)
);

n->key=
key;

n->next=
b->head;

b->head=n;

}

void split(
LinearHash* h
){

expand(h);

Node* cur=
h->buckets[
h->split
]
.head;

h->buckets[
h->split
]
.head=NULL;

while(cur){

Node* next=
cur->next;

int idx=
splitHash(
cur->key,
h->level
);

if(
idx
!=
h->split
){

cur->next=
h->buckets[
idx
]
.head;

h->buckets[
idx
]
.head=
cur;

}
else{

cur->next=
h->buckets[
h->split
]
.head;

h->buckets[
h->split
]
.head=
cur;

}

cur=next;

}

h->split++;

if(
h->split
==
(
INITIAL_BUCKETS
<<
h->level
)
){

h->level++;

h->split=0;

}

}

void insert(
LinearHash* h,
int key
){

int idx=
hash(
key,
h->level
);

if(
idx
<
h->split
)
idx=
splitHash(
key,
h->level
);

insertNode(
&h->buckets[
idx
],
key
);

h->count++;

double load=
(
double)
h->count
/
h->size;

if(
load
>
LOAD_FACTOR
)
split(h);

}

int search(
LinearHash* h,
int key
){

int idx=
hash(
key,
h->level
);

if(
idx
<
h->split
)
idx=
splitHash(
key,
h->level
);

Node* cur=
h->buckets[
idx
]
.head;

while(cur){

if(
cur->key
==
key
)
return 1;

cur=
cur->next;

}

return 0;

}

int main(){

LinearHash* h=
create();

insert(h,10);

insert(h,20);

insert(h,30);

insert(h,40);

printf(
"%d\n",
search(
h,
20
)
);

}
