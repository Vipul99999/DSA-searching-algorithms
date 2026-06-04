import java.util.ArrayList;
import java.util.List;

public class DynamicHashing {

    /*
     * Maximum number of keys
     * allowed inside one bucket
     */
    private static final int BUCKET_SIZE = 3;

    /*
     * -------------------------
     * Bucket Structure
     * -------------------------
     *
     * localDepth:
     * Number of bits used
     * by this bucket
     */
    static class Bucket {

        int localDepth;

        List<Integer> keys;

        Bucket(int depth) {
            this.localDepth = depth;
            this.keys = new ArrayList<>();
        }

        boolean isFull() {
            return keys.size() >= BUCKET_SIZE;
        }

        boolean contains(int key) {
            return keys.contains(key);
        }

        void insert(int key) {
            keys.add(key);
        }

        void remove(int key) {
            keys.remove(Integer.valueOf(key));
        }
    }


    /*
     * -------------------------
     * Directory
     * -------------------------
     */

    private int globalDepth;

    private List<Bucket> directory;


    public DynamicHashing() {

        globalDepth = 1;

        directory = new ArrayList<>();

        directory.add(
            new Bucket(1)
        );

        directory.add(
            new Bucket(1)
        );
    }


    /*
     * Hash Function
     *
     * Formula:
     *
     * index =
     * key &
     * ((1 << globalDepth)-1)
     */
    private int getIndex(
        int key
    ) {

        return key &
               (
                   (1 << globalDepth)
                   - 1
               );
    }


    /*
     * Double directory
     *
     * Size:
     * 2^globalDepth
     */
    private void expandDirectory() {

        int oldSize =
            directory.size();

        for (
            int i = 0;
            i < oldSize;
            i++
        ) {

            directory.add(
                directory.get(i)
            );
        }

        globalDepth++;
    }


    /*
     * Split overflowing bucket
     */
    private void splitBucket(
        int index
    ) {

        Bucket old =
            directory.get(
                index
            );

        /*
         * If local depth reached
         * global depth,
         * expand directory
         */
        if (
            old.localDepth
            ==
            globalDepth
        ) {

            expandDirectory();
        }

        Bucket fresh =
            new Bucket(
                old.localDepth + 1
            );

        old.localDepth++;

        /*
         * Determine which
         * directory entries
         * point to new bucket
         */
        int mask =
            1
            <<
            (
                old.localDepth
                - 1
            );

        for (
            int i = 0;
            i < directory.size();
            i++
        ) {

            if (
                directory.get(i)
                ==
                old
                &&
                (
                    (i & mask)
                    !=
                    0
                )
            ) {

                directory.set(
                    i,
                    fresh
                );
            }
        }


        /*
         * Reinsert existing keys
         */
        List<Integer> oldKeys =
            new ArrayList<>(
                old.keys
            );

        old.keys.clear();

        for (
            int value :
            oldKeys
        ) {

            int newIndex =
                getIndex(
                    value
                );

            directory
                .get(newIndex)
                .insert(
                    value
                );
        }
    }


    /*
     * Insert
     */
    public void insert(
        int key
    ) {

        while (true) {

            int index =
                getIndex(
                    key
                );

            Bucket bucket =
                directory.get(
                    index
                );

            if (
                bucket.contains(
                    key
                )
            ) {

                return;
            }

            if (
                !bucket.isFull()
            ) {

                bucket.insert(
                    key
                );

                return;
            }

            splitBucket(
                index
            );
        }
    }


    /*
     * Search
     */
    public boolean search(
        int key
    ) {

        int index =
            getIndex(
                key
            );

        return
            directory
            .get(index)
            .contains(
                key
            );
    }


    /*
     * Delete
     */
    public void delete(
        int key
    ) {

        int index =
            getIndex(
                key
            );

        directory
            .get(index)
            .remove(
                key
            );
    }


    /*
     * Display
     */
    public void display() {

        System.out.println(
            "\nGlobal Depth: "
            +
            globalDepth
        );

        for (
            int i = 0;
            i < directory.size();
            i++
        ) {

            System.out.print(
                "Dir["
                +
                i
                +
                "] -> "
            );

            Bucket bucket =
                directory.get(
                    i
                );

            for (
                int value :
                bucket.keys
            ) {

                System.out.print(
                    value
                    +
                    " "
                );
            }

            System.out.println();
        }
    }


    /*
     * Driver
     */
    public static void main(
        String[] args
    ) {

        DynamicHashing hash =
            new DynamicHashing();

        hash.insert(10);

        hash.insert(22);

        hash.insert(14);

        hash.insert(30);

        hash.insert(42);

        hash.insert(54);

        hash.display();

        System.out.println(
            "\nSearch 42: "
            +
            hash.search(
                42
            )
        );

        hash.delete(
            42
        );

        System.out.println(
            "\nAfter Delete:"
        );

        hash.display();
    }
}
