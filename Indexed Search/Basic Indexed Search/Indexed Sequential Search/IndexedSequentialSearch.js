function indexedSequentialSearch(
arr,
target
){

let n=
arr.length;

let block=
Math.floor(
Math.sqrt(
n
)
);

let index=[];

for(
let i=0;
i<n;
i+=block
){

let end=
Math.min(
i
+
block
-
1,
n-1
);

index.push(
{
max:
arr[end],
start:i
}
);

}

let chosen=-1;

for(
let b
of
index
){

if(
target
<=
b.max
){

chosen=
b.start;

break;

}

}

if(
chosen===-1
)
return -1;

let end=
Math.min(
chosen
+
block
-
1,
n-1
);

for(
let i=
chosen;
i<=end;
i++
){

if(
arr[i]
===
target
)
return i;

}

return -1;

}

const arr=
[
2,5,8,12,
16,20,24,
28,32,40
];

console.log(
indexedSequentialSearch(
arr,
24
)
);
