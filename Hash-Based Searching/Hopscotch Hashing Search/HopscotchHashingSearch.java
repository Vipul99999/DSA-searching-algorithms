public class HopscotchHashingSearch {

    private static final int TABLE_SIZE = 16;
    private static final int HOP_RANGE = 4;

    static class Bucket {

        int key = -1;
        boolean occupied = false;
        int hopInfo = 0;
    }

    private final Bucket[] table;

    public HopscotchHashingSearch() {

        table =
            new Bucket[TABLE_SIZE];

        for (
            int i = 0;
            i < TABLE_SIZE;
            i++
        ) {

            table[i] =
                new Bucket();
        }
    }

    private int hashFunction(
        int key
    ) {

        return key % TABLE_SIZE;
    }

    public boolean insert(
        int key
    ) {

        int home =
            hashFunction(key);

        int freePos = -1;

        for (
            int i = home;
            i < TABLE_SIZE;
            i++
        ) {

            if (
                !table[i]
                .occupied
            ) {

                freePos = i;
                break;
            }
        }

        if (freePos == -1)
            return false;

        if (
            freePos - home >=
            HOP_RANGE
        )
            return false;

        table[
            freePos
        ].key = key;

        table[
            freePos
        ].occupied = true;

        table[
            home
        ].hopInfo |=
            (
                1 <<
                (
                    freePos
                    - home
                )
            );

        return true;
    }

    public boolean search(
        int key
    ) {

        int home =
            hashFunction(key);

        int hop =
            table[home]
            .hopInfo;

        for (
            int i = 0;
            i < HOP_RANGE;
            i++
        ) {

            if (
                (hop &
                (1 << i))
                != 0
            ) {

                int pos =
                    home + i;

                if (
                    pos <
                    TABLE_SIZE &&
                    table[pos]
                    .occupied &&
                    table[pos]
                    .key == key
                ) {

                    return true;
                }
            }
        }

        return false;
    }

    public void display() {

        System.out.println(
            "\nHopscotch "
            + "Hash Table"
        );

        for (
            int i = 0;
            i < TABLE_SIZE;
            i++
        ) {

            System.out.print(
                "[" + i +
                "] = "
            );

            if (
                table[i]
                .occupied
            ) {

                System.out.print(
                    table[i].key
                );
            }
            else {

                System.out.print(
                    "EMPTY"
                );
            }

            System.out.println(
                " (hop="
                + table[i]
                .hopInfo
                + ")"
            );
        }
    }

    public static void main(
        String[] args
    ) {

        HopscotchHashingSearch ht =
            new HopscotchHashingSearch();

        ht.insert(5);
        ht.insert(21);
        ht.insert(37);
        ht.insert(53);

        ht.display();

        System.out.println(
            "\nSearch 37: "
            + (
                ht.search(37)
                ? "Found"
                : "Not Found"
            )
        );
    }
}
