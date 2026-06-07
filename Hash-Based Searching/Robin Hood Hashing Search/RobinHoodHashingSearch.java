public class RobinHoodHashingSearch {

    private static final int TABLE_SIZE = 11;
    private static final int EMPTY = -1;

    private final int[] table;

    public RobinHoodHashingSearch() {

        table =
            new int[TABLE_SIZE];

        for (
            int i = 0;
            i < TABLE_SIZE;
            i++
        ) {

            table[i] = EMPTY;
        }
    }

    private int hashFunction(
        int key
    ) {

        return key % TABLE_SIZE;
    }

    private int probeDistance(
        int key,
        int pos
    ) {

        int home =
            hashFunction(key);

        return (
            pos - home +
            TABLE_SIZE
        ) % TABLE_SIZE;
    }

    public boolean insert(
        int key
    ) {

        int current = key;

        int pos =
            hashFunction(
                current
            );

        while (true) {

            if (
                table[pos]
                == EMPTY
            ) {

                table[pos] =
                    current;

                return true;
            }

            int resident =
                table[pos];

            int currentDist =
                probeDistance(
                    current,
                    pos
                );

            int residentDist =
                probeDistance(
                    resident,
                    pos
                );

            if (
                currentDist >
                residentDist
            ) {

                int temp =
                    table[pos];

                table[pos] =
                    current;

                current = temp;
            }

            pos =
                (pos + 1)
                % TABLE_SIZE;
        }
    }

    public boolean search(
        int key
    ) {

        int pos =
            hashFunction(
                key
            );

        int dist = 0;

        while (
            table[pos]
            != EMPTY
        ) {

            if (
                table[pos]
                == key
            ) {
                return true;
            }

            int residentDist =
                probeDistance(
                    table[pos],
                    pos
                );

            if (
                residentDist <
                dist
            ) {
                return false;
            }

            pos =
                (pos + 1)
                % TABLE_SIZE;

            dist++;
        }

        return false;
    }

    public void display() {

        System.out.println(
            "\nHash Table"
        );

        for (
            int i = 0;
            i < TABLE_SIZE;
            i++
        ) {

            System.out.print(
                "[" + i + "] = "
            );

            if (
                table[i]
                == EMPTY
            )
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

        RobinHoodHashingSearch ht =
            new RobinHoodHashingSearch();

        ht.insert(22);
        ht.insert(33);
        ht.insert(44);
        ht.insert(55);
        ht.insert(66);

        ht.display();

        System.out.println(
            "\nSearch 44: "
            + (
                ht.search(44)
                ? "Found"
                : "Not Found"
            )
        );
    }
}
