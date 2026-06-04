import java.util.Arrays;

public class CuckooHashing {

    private static final int SIZE = 11;

    private static final int EMPTY = -1;

    private int[] table1;

    private int[] table2;

    public CuckooHashing() {

        table1 =
            new int[SIZE];

        table2 =
            new int[SIZE];

        Arrays.fill(
            table1,
            EMPTY
        );

        Arrays.fill(
            table2,
            EMPTY
        );
    }

    private int hash1(int key) {
        return key % SIZE;
    }

    private int hash2(int key) {
        return (key / SIZE) % SIZE;
    }

    public void insert(int key) {

        int i =
            hash1(key);

        if (
            table1[i]
            ==
            EMPTY
        )
            table1[i] = key;

        else
            table2[
                hash2(key)
            ] = key;
    }

    public boolean search(int key) {

        return (
            table1[
                hash1(key)
            ]
            ==
            key
        )
        ||
        (
            table2[
                hash2(key)
            ]
            ==
            key
        );
    }

    public static void main(
        String[] args
    ) {

        CuckooHashing h =
            new CuckooHashing();

        h.insert(25);

        System.out.println(
            h.search(25)
        );
    }
}
