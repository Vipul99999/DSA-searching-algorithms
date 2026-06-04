#include <iostream>
#include <vector>
#include <list>

using namespace std;

class LinearHash {

int level=0;

int split=0;

int count=0;

const int N=4;

vector<
list<int>
> buckets;

public:

LinearHash(){

buckets.resize(
N
);

}

/*
h(k)=k mod (N×2^L)
*/
int hash(
int k
){

return
k%
(
N
<<
level
);

}

/*
h'(k)=k mod (N×2^(L+1))
*/
int splitHash(
int k
){

return
k%
(
N
<<
(
level+1
)
);

}

void insert(
int key
){

int idx=
hash(
key
);

if(
idx
<
split
)
idx=
splitHash(
key
);

if(
idx
>=
buckets.size()
)
buckets.resize(
idx+1
);

buckets[
idx
]
.push_back(
key
);

count++;

if(
(double)
count
/
buckets.size()
>
2
)
splitBucket();

}

void splitBucket(){

buckets.push_back(
{}
);

split++;

if(
split
==
(
N
<<
level
)
){

level++;

split=0;

}

}

bool search(
int key
){

int idx=
hash(
key
);

if(
idx
<
split
)
idx=
splitHash(
key
);

for(
auto x:
buckets[idx]
)
if(
x
==
key
)
return true;

return false;

}

};

int main(){

LinearHash h;

h.insert(
15
);

h.insert(
25
);

cout
<<
h.search(
25
);

}
