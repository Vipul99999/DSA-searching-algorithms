#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Sparse {

int key;

int pos;

};

int sparseSearch(
vector<int>& arr,
int target
){

int n=
arr.size();

int step=
sqrt(n);

vector<Sparse>
index;

for(
int i=0;
i<n;
i+=step
){

index.push_back(
{
arr[i],
i
}
);

}

int start=0;

for(
auto&
x:
index
){

if(
x.key
>
target
)
break;

start=
x.pos;

}

int end=
min(
start
+
step
-
1,
n-1
);

for(
int i=start;
i<=end;
i++
){

if(
arr[i]
==
target
)
return i;

}

return -1;

}

int main(){

vector<int>
arr=
{
2,5,8,12,
16,20,24,
28,32,40
};

cout
<<
sparseSearch(
arr,
24
);

}
