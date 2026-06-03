#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Index {

int maxValue;

int start;

};

int searchISS(
vector<int>& arr,
int target
){

int n=
arr.size();

int block=
sqrt(n);

vector<Index>
index;

for(
int i=0;
i<n;
i+=block
){

int end=
min(
i
+
block
-
1,
n-1
);

index.push_back(
{
arr[end],
i
}
);

}

int selected=-1;

for(
int i=0;
i<
index.size();
i++
){

if(
target
<=
index[i]
.maxValue
){

selected=i;

break;

}

}

if(
selected==-1
)
return -1;

int start=
index[selected]
.start;

int end=
min(
start
+
block
-
1,
n-1
);

for(
int i=start;
i<=end;
i++
)
if(
arr[i]
==
target
)
return i;

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

int result=
searchISS(
arr,
24
);

if(result!=-1)
cout
<<"Found at "
<<result;

else
cout
<<"Not Found";

}
