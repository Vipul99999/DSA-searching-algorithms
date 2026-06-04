import java.util.*;

public class LinearHashing {

static int level=0;

static int split=0;

static final int N=4;

static List<
List<Integer>
>
table=
new ArrayList<>();

static{

for(
int i=0;
i<N;
i++
)
table.add(
new ArrayList<>()
);

}

// h(k)=k mod (N×2^L)

static int hash(
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

static void insert(
int key
){

int idx=
hash(
key
);

while(
idx
>=
table.size()
)
table.add(
new ArrayList<>()
);

table
.get(
idx
)
.add(
key
);

}

static boolean search(
int key
){

int idx=
hash(
key
);

return
table
.get(
idx
)
.contains(
key
);

}

public static void main(
String[] args
){

insert(
100
);

insert(
200
);

System.out.println(
search(
200
)
);

}

}
