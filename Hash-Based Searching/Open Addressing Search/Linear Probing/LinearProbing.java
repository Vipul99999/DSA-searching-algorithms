public class LinearProbing {

    private static final int TABLE_SIZE = 11;
    private static final int EMPTY = -1;

    private final int[] table;

    public LinearProbing() {
        table = new int[TABLE_SIZE];

        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = EMPTY;
        }
    }

    private int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    public boolean insert(int key) {

        int index = hashFunction(key);

        for (int i = 0; i < TABLE_SIZE; i++) {

            int pos =
                (index + i) % TABLE_SIZE;

            if (table[pos] == EMPTY) {
                table[pos] = key;
                return true;
            }
        }

        return false;
    }

    public boolean search(int key) {

        int index = hashFunction(key);

        for (int i = 0; i < TABLE_SIZE; i++) {

            int pos =
                (index + i) % TABLE_SIZE;

            if (table[pos] == EMPTY)
                return false;

            if (table[pos] == key)
                return true;
        }

        return false;
    }

    public void display() {

        System.out.println(
            "\nHash Table:"
        );

        for (int i = 0; i < TABLE_SIZE; i++) {

            System.out.print(
                "[" + i + "] = "
            );

            if (table[i] == EMPTY)
                System.out.println("EMPTY");
            else
                System.out.println(table[i]);
        }
    }

    public static void main(String[] args) {

        LinearProbing ht =
            new LinearProbing();

        ht.insert(22);
        ht.insert(33);
        ht.insert(44);
        ht.insert(55);

        ht.display();

        System.out.println(
            "\nSearch 44: "
            + (ht.search(44)
                ? "Found"
                : "Not Found")
        );
    }
}
