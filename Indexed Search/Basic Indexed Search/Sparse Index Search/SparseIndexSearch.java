import java.util.*;

public class SparseIndexSearch {

static class Index {

int key;

int pos;

Index(
int k,
int p
){

key=k;

pos=p;

}

}

static int search(
int[] arr,
int target
){

int n=
arr.length;

int step=
(int)
Math.sqrt(
n
);

List<Index>
idx=
new ArrayList<>();

for(
int i=0;
i<n;
i+=step
){

idx.add(
new Index(
arr[i],
i
)
);

}

int start=0;

for(
Index x:
idx
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
Math.min(
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

public static void main(
String[] args
){

int[] arr=
{
2,5,8,12,
16,20,24,
28,32,40
};

System.out.println(
search(
arr,
24
)
);

}

}
