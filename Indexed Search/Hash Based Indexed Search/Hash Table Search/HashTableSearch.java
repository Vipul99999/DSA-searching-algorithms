import java.util.LinkedList;

public class HashTableSearch {

    private static final int SIZE = 10;

    private LinkedList<Integer>[] table;

    public HashTableSearch() {

        table =
            new LinkedList[SIZE];

        for (int i = 0; i < SIZE; i++)
            table[i] =
                new LinkedList<>();
    }

    /*
        h(key)=key%SIZE
    */
    private int hash(int key) {
        return key % SIZE;
    }

    public void insert(int key) {

        table[
            hash(key)
        ].add(key);
    }

    public boolean search(int key) {

        return table[
            hash(key)
        ].contains(key);
    }

    public void delete(int key) {

        table[
            hash(key)
        ]
        .remove(
            Integer.valueOf(key)
        );
    }

    public void display() {

        for (
            int i=0;
            i<SIZE;
            i++
        ) {

            System.out.print(
                "[" + i + "] "
            );

            for (
                int value :
                table[i]
            ) {

                System.out.print(
                    value
                    +
                    " -> "
                );
            }

            System.out.println(
                "NULL"
            );
        }
    }

    public static void main(
        String[] args
    ) {

        HashTableSearch h =
            new HashTableSearch();

        h.insert(10);

        h.insert(20);

        h.insert(35);

        h.display();
    }
}
