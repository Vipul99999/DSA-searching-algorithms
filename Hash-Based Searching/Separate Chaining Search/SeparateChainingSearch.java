public class SeparateChainingSearch {

    private static final int TABLE_SIZE = 10;

    static class Node {

        int key;
        Node next;

        Node(int key) {
            this.key = key;
        }
    }

    private final Node[] buckets;

    public SeparateChainingSearch() {
        buckets =
            new Node[TABLE_SIZE];
    }

    private int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    public void insert(int key) {

        int index =
            hashFunction(key);

        Node node =
            new Node(key);

        node.next =
            buckets[index];

        buckets[index] = node;
    }

    public boolean search(int key) {

        int index =
            hashFunction(key);

        Node current =
            buckets[index];

        while (current != null) {

            if (current.key == key)
                return true;

            current =
                current.next;
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
                "[" + i + "] -> "
            );

            Node current =
                buckets[i];

            while (current != null) {

                System.out.print(
                    current.key +
                    " -> "
                );

                current =
                    current.next;
            }

            System.out.println(
                "NULL"
            );
        }
    }

    public static void main(
        String[] args
    ) {

        SeparateChainingSearch ht =
            new SeparateChainingSearch();

        ht.insert(15);
        ht.insert(25);
        ht.insert(35);
        ht.insert(42);

        ht.display();

        System.out.println(
            "\nSearch 35: "
            + (ht.search(35)
                ? "Found"
                : "Not Found")
        );
    }
}
