public class IndexedSequentialSearch {

static class Index {

int max;

int start;

Index(
int m,
int s
){

max=m;

start=s;

}

}

static int search(
int[] arr,
int target
){

int n=
arr.length;

int block=
(int)
Math.sqrt(n);

Index[] idx=
new Index[
(n+block-1)
/block
];

int p=0;

for(
int i=0;
i<n;
i+=block
){

int end=
Math.min(
i
+
block
-
1,
n-1
);

idx[p++]=
new Index(
arr[end],
i
);

}

int selected=-1;

for(
int i=0;
i<p;
i++
){

if(
target
<=
idx[i]
.max
){

selected=i;

break;

}

}

if(selected==-1)
return -1;

int start=
idx[selected]
.start;

int end=
Math.min(
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

public static void main(
String[] args
){

int[] arr=
{
2,5,8,12,
16,20,24,
28,32,40
};

int result=
search(
arr,
24
);

if(result!=-1)
System.out.println(
"Found at "
+
result
);

else
System.out.println(
"Not Found"
);

}

}
