public class HashTableLookup {

    private static final int TABLE_SIZE = 101;
    private static final int EMPTY = -1;

    private final int[] table;

    public HashTableLookup() {
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

        if (table[index] != EMPTY)
            return false;

        table[index] = key;
        return true;
    }

    public boolean lookup(int key) {
        return table[hashFunction(key)] == key;
    }

    public static void main(String[] args) {
        HashTableLookup ht =
            new HashTableLookup();

        ht.insert(15);
        ht.insert(42);
        ht.insert(99);

        System.out.println(
            ht.lookup(42)
                ? "Found"
                : "Not Found"
        );
    }
}
