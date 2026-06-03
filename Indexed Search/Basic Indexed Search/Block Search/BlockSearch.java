public class BlockSearch {

    public static int blockSearch(
        int[] arr,
        int target
    ){

        int n =
            arr.length;

        int block =
            (int)Math.sqrt(n);

        int start=0;

        while(start<n){

            int end =
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

            start+=block;

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

int result=
blockSearch(
arr,
24
);

if(result!=-1)
System.out.println(
"Found at index "
+result
);

else
System.out.println(
"Not Found"
);

}

}
