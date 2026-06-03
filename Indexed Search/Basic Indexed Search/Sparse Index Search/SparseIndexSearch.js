function sparseIndexSearch(
arr,
target
){

let n=
arr.length;

let step=
Math.floor(
Math.sqrt(
n
)
);

let index=[];

for(
let i=0;
i<n;
i+=step
){

index.push(
{
key:
arr[i],
pos:i
}
);

}

let start=0;

for(
let x
of
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

let end=
Math.min(
start
+
step
-
1,
n-1
);

for(
let i=
start;
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
sparseIndexSearch(
arr,
24
)
);
