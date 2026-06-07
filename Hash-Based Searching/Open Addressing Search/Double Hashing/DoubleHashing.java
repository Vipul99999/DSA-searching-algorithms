public class DoubleHashing {

    private static final int TABLE_SIZE = 13;
    private static final int EMPTY = -1;

    private final int[] table;

    public DoubleHashing() {

        table =
            new int[TABLE_SIZE];

        for (int i = 0;
             i < TABLE_SIZE;
             i++) {

            table[i] = EMPTY;
        }
    }

    private int hash1(int key) {
        return key % TABLE_SIZE;
    }

    private int hash2(int key) {
        return 7 - (key % 7);
    }

    public boolean insert(int key) {

        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0;
             i < TABLE_SIZE;
             i++) {

            int pos =
                (h1 + i * h2)
                % TABLE_SIZE;

            if (table[pos] == EMPTY) {

                table[pos] = key;

                return true;
            }
        }

        return false;
    }

    public boolean search(int key) {

        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0;
             i < TABLE_SIZE;
             i++) {

            int pos =
                (h1 + i * h2)
                % TABLE_SIZE;

            if (table[pos] == EMPTY)
                return false;

            if (table[pos] == key)
                return true;
        }

        return false;
    }

    public void display() {

        System.out.println(
            "\nHash Table"
        );

        for (int i = 0;
             i < TABLE_SIZE;
             i++) {

            System.out.print(
                "[" + i + "] = "
            );

            if (table[i] == EMPTY)
                System.out.println(
                    "EMPTY"
                );
            else
                System.out.println(
                    table[i]
                );
        }
    }

    public static void main(
        String[] args
    ) {

        DoubleHashing ht =
            new DoubleHashing();

        ht.insert(25);
        ht.insert(38);
        ht.insert(51);
        ht.insert(64);

        ht.display();

        System.out.println(
            "\nSearch 51: "
            + (ht.search(51)
                ? "Found"
                : "Not Found")
        );
    }
}
