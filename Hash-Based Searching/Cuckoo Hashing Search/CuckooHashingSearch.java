public class CuckooHashingSearch {

    private static final int TABLE_SIZE = 11;
    private static final int EMPTY = -1;
    private static final int MAX_KICKS = 20;

    private final int[] table1;
    private final int[] table2;

    public CuckooHashingSearch() {
        table1 = new int[TABLE_SIZE];
        table2 = new int[TABLE_SIZE];

        for (int i = 0; i < TABLE_SIZE; i++) {
            table1[i] = EMPTY;
            table2[i] = EMPTY;
        }
    }

    private int hash1(int key) {
        return key % TABLE_SIZE;
    }

    private int hash2(int key) {
        return (key / TABLE_SIZE) % TABLE_SIZE;
    }

    public boolean search(int key) {
        return table1[hash1(key)] == key ||
               table2[hash2(key)] == key;
    }

    public boolean insert(int key) {
        int current = key;
        int table = 1;

        for (int i = 0; i < MAX_KICKS; i++) {
            if (table == 1) {
                int pos = hash1(current);

                if (table1[pos] == EMPTY) {
                    table1[pos] = current;
                    return true;
                }

                int temp = table1[pos];
                table1[pos] = current;
                current = temp;
                table = 2;
            } else {
                int pos = hash2(current);

                if (table2[pos] == EMPTY) {
                    table2[pos] = current;
                    return true;
                }

                int temp = table2[pos];
                table2[pos] = current;
                current = temp;
                table = 1;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        CuckooHashingSearch hash =
            new CuckooHashingSearch();

        hash.insert(20);
        hash.insert(50);
        hash.insert(53);

        System.out.println(
            hash.search(53)
                ? "Found"
                : "Not Found"
        );
    }
}
