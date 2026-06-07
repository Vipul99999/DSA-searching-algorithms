/*
    ExtendibleHashing.java
    Java 17+

    Features:
    - Global Depth
    - Local Depth
    - Directory
    - Bucket Splitting
    - Directory Doubling
    - Insert
    - Search
    - Delete
    - Display

    Compile:
    javac ExtendibleHashing.java

    Run:
    java ExtendibleHashing
*/

import java.util.ArrayList;
import java.util.List;

public class ExtendibleHashing {

    private static final int BUCKET_SIZE = 4;

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
    }

    static class ExtendibleHash {

        private int globalDepth;
        private List<Bucket> directory;

        public ExtendibleHash() {
            globalDepth = 1;
            directory = new ArrayList<>();

            directory.add(new Bucket(1));
            directory.add(new Bucket(1));
        }

        private int hashKey(int key) {
            return key;
        }

        private int getIndex(int key) {
            int mask = (1 << globalDepth) - 1;
            return hashKey(key) & mask;
        }

        private void doubleDirectory() {

            int oldSize = directory.size();

            for (int i = 0; i < oldSize; i++) {
                directory.add(directory.get(i));
            }

            globalDepth++;
        }

        private void splitBucket(int bucketIndex) {

            Bucket oldBucket =
                directory.get(bucketIndex);

            if (oldBucket.localDepth ==
                globalDepth) {

                doubleDirectory();
            }

            Bucket newBucket =
                new Bucket(
                    oldBucket.localDepth + 1
                );

            oldBucket.localDepth++;

            int splitBit =
                1 << (oldBucket.localDepth - 1);

            for (int i = 0;
                 i < directory.size();
                 i++) {

                if (directory.get(i) ==
                    oldBucket) {

                    if ((i & splitBit) != 0) {

                        directory.set(
                            i,
                            newBucket
                        );
                    }
                }
            }

            List<Integer> oldKeys =
                new ArrayList<>(
                    oldBucket.keys
                );

            oldBucket.keys.clear();

            for (int key : oldKeys) {

                int index =
                    getIndex(key);

                directory
                    .get(index)
                    .keys
                    .add(key);
            }
        }

        public void insert(int key) {

            while (true) {

                int index =
                    getIndex(key);

                Bucket bucket =
                    directory.get(index);

                if (!bucket.isFull()) {

                    bucket.keys.add(key);

                    return;
                }

                splitBucket(index);
            }
        }

        public boolean search(int key) {

            int index =
                getIndex(key);

            Bucket bucket =
                directory.get(index);

            for (int value :
                bucket.keys) {

                if (value == key) {
                    return true;
                }
            }

            return false;
        }

        public boolean delete(int key) {

            int index =
                getIndex(key);

            Bucket bucket =
                directory.get(index);

            return bucket.keys.remove(
                Integer.valueOf(key)
            );
        }

        public void display() {

            System.out.println(
                "\nGlobal Depth: "
                + globalDepth
            );

            System.out.println(
                "Directory Size: "
                + directory.size()
            );

            System.out.println();

            for (int i = 0;
                 i < directory.size();
                 i++) {

                Bucket bucket =
                    directory.get(i);

                System.out.print(
                    "Dir[" + i +
                    "] -> LD=" +
                    bucket.localDepth +
                    " : "
                );

                for (int key :
                    bucket.keys) {

                    System.out.print(
                        key + " "
                    );
                }

                System.out.println();
            }
        }
    }

    public static void main(String[] args) {

        ExtendibleHash hash =
            new ExtendibleHash();

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
            + (hash.search(29)
                ? "Found"
                : "Not Found")
        );

        System.out.println(
            "Search 100: "
            + (hash.search(100)
                ? "Found"
                : "Not Found")
        );

        hash.delete(29);

        System.out.println(
            "\nAfter deleting 29:"
        );

        hash.display();
    }
}
