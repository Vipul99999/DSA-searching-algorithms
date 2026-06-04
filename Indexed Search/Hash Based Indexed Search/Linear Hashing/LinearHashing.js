class LinearHash {

constructor(){

this.level=0;

this.N=4;

this.table=
Array(
4
)
.fill()
.map(
()=>[]
);

}

// h(k)=k mod (N×2^L)

hash(
k
){

return (
k %
(
this.N
<<
this.level
)
);

}

insert(
key
){

let idx=
this.hash(
key
);

while(
idx
>=
this.table.length
)
this.table.push(
[]
);

this.table[
idx
]
.push(
key
);

}

search(
key
){

let idx=
this.hash(
key
);

return (
this.table[
idx
]
.includes(
key
)
);

}

}

const h=
new LinearHash();

h.insert(
11
);

h.insert(
44
);

console.log(
h.search(
44
)
);
