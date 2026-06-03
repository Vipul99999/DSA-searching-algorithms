function blockSearch(
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

let start=0;

while(
start<n
){

let end=
Math.min(
start
+
block
-
1,
n-1
);

if(
target
<=
arr[end]
){

for(
let i=start;
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

start+=block;

}

return -1;

}

const arr=
[
2,5,8,12,
16,20,24,
28,32,40
];

const result=
blockSearch(
arr,
24
);

if(
result!==-1
)
console.log(
"Found at",
result
);

else
console.log(
"Not Found"
);
