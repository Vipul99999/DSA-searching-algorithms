/*
    LinearHashing.java
    Java 17+

    Features:
    - Dynamic Bucket Growth
    - Split Pointer (nextSplit)
    - Level-Based Hashing
    - Bucket Splitting
    - Overflow Buckets
    - Insert
    - Search
    - Display

    Compile:
    javac LinearHashing.java

    Run:
    java LinearHashing
*/

import java.util.ArrayList;
import java.util.List;

public class LinearHashing {

    private static final int INITIAL_BUCKETS = 2;
    private static final int BUCKET_SIZE = 4;

    static class Bucket {

        List<Integer> keys;
        Bucket overflow;

        Bucket() {
            keys = new ArrayList<>();
            overflow = null;
        }

        boolean isFull() {
            return keys.size() >= BUCKET_SIZE;
        }
    }

    private final List<Bucket> buckets;

    private int level;
    private int nextSplit;

    public LinearHashing() {

        buckets = new ArrayList<>();

        level = 0;
        nextSplit = 0;

        for (int i = 0;
             i < INITIAL_BUCKETS;
             i++) {

            buckets.add(
                new Bucket()
            );
        }
    }

    /* ---------- Hash Functions ---------- */

    private int hashLevel(int key) {

        return key %
            (INITIAL_BUCKETS
                << level);
    }

    private int hashNextLevel(int key) {

        return key %
            (INITIAL_BUCKETS
                << (level + 1));
    }

    private int bucketIndex(int key) {

        int idx =
            hashLevel(key);

        if (idx < nextSplit) {

            idx =
                hashNextLevel(key);
        }

        return idx;
    }

    /* ---------- Insert Into Bucket ---------- */

    private void insertIntoBucket(
        Bucket bucket,
        int key
    ) {

        Bucket current =
            bucket;

        while (true) {

            if (!current.isFull()) {

                current.keys.add(key);

                return;
            }

            if (
                current.overflow
                == null
            ) {

                current.overflow =
                    new Bucket();
            }

            current =
                current.overflow;
        }
    }

    /* ---------- Split Bucket ---------- */

    private void splitBucket() {

        int splitIndex =
            nextSplit;

        buckets.add(
            new Bucket()
        );

        List<Integer> values =
            new ArrayList<>();

        Bucket current =
            buckets.get(
                splitIndex
            );

        while (current != null) {

            values.addAll(
                current.keys
            );

            current =
                current.overflow;
        }

        buckets.set(
            splitIndex,
            new Bucket()
        );

        for (int value :
            values) {

            int idx =
                hashNextLevel(
                    value
                );

            insertIntoBucket(
                buckets.get(idx),
                value
            );
        }

        nextSplit++;

        int roundSize =
            INITIAL_BUCKETS
                << level;

        if (
            nextSplit
            == roundSize
        ) {

            nextSplit = 0;
            level++;
        }
    }

    /* ---------- Insert ---------- */

    public void insert(int key) {

        int idx =
            bucketIndex(key);

        insertIntoBucket(
            buckets.get(idx),
            key
        );

        splitBucket();
    }

    /* ---------- Search ---------- */

    public boolean search(int key) {

        int idx =
            bucketIndex(key);

        Bucket current =
            buckets.get(idx);

        while (current != null) {

            for (int value :
                current.keys) {

                if (
                    value == key
                ) {

                    return true;
                }
            }

            current =
                current.overflow;
        }

        return false;
    }

    /* ---------- Display ---------- */

    public void display() {

        System.out.println(
            "\nLevel: "
            + level
        );

        System.out.println(
            "Next Split: "
            + nextSplit
        );

        System.out.println(
            "Bucket Count: "
            + buckets.size()
        );

        System.out.println();

        for (int i = 0;
             i < buckets.size();
             i++) {

            System.out.print(
                "Bucket[" + i
                + "] : "
            );

            Bucket current =
                buckets.get(i);

            while (current != null) {

                for (int value :
                    current.keys) {

                    System.out.print(
                        value + " "
                    );
                }

                if (
                    current.overflow
                    != null
                ) {

                    System.out.print(
                        "-> "
                    );
                }

                current =
                    current.overflow;
            }

            System.out.println();
        }
    }

    /* ---------- Driver ---------- */

    public static void main(
        String[] args
    ) {

        LinearHashing hash =
            new LinearHashing();

        int[] values = {
            5, 12, 25, 33,
            41, 18, 29, 37,
            49, 52, 61, 73
        };

        for (int value :
            values) {

            hash.insert(value);
        }

        hash.display();

        System.out.println(
            "\nSearch 29: "
            + (
                hash.search(29)
                ? "Found"
                : "Not Found"
            )
        );

        System.out.println(
            "Search 100: "
            + (
                hash.search(100)
                ? "Found"
                : "Not Found"
            )
        );
    }
}
