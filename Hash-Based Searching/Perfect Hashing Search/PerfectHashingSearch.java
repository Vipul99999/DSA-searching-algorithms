public class PerfectHashingSearch {

    private final int[] table;

    public PerfectHashingSearch() {

        table = new int[10];

        table[0] = 11;
        table[1] = 22;
        table[2] = 33;
        table[3] = 44;
        table[4] = 55;
    }

    private int perfectHash(
        int key
    ) {

        return switch(key) {

            case 11 -> 0;
            case 22 -> 1;
            case 33 -> 2;
            case 44 -> 3;
            case 55 -> 4;

            default -> -1;
        };
    }

    public boolean search(
        int key
    ) {

        int idx =
            perfectHash(key);

        if (idx == -1)
            return false;

        return table[idx] == key;
    }

    public static void main(
        String[] args
    ) {

        PerfectHashingSearch ht =
            new PerfectHashingSearch();

        System.out.println(
            "Search 33: "
            + (
                ht.search(33)
                ? "Found"
                : "Not Found"
            )
        );
    }
}
