TABLE_SIZE = 10


class Node:
    def __init__(self, key):
        self.key = key
        self.next = None


class SeparateChainingHashTable:

    def __init__(self):
        self.buckets = (
            [None] * TABLE_SIZE
        )

    def hash_function(self, key):
        return key % TABLE_SIZE

    def insert(self, key):

        index = (
            self.hash_function(key)
        )

        node = Node(key)

        node.next = (
            self.buckets[index]
        )

        self.buckets[index] = node

    def search(self, key):

        index = (
            self.hash_function(key)
        )

        current = (
            self.buckets[index]
        )

        while current:

            if current.key == key:
                return True

            current = current.next

        return False

    def display(self):

        print("\nHash Table")

        for i in range(TABLE_SIZE):

            print(
                f"[{i}] -> ",
                end=""
            )

            current = (
                self.buckets[i]
            )

            while current:

                print(
                    f"{current.key} -> ",
                    end=""
                )

                current = current.next

            print("NULL")


if __name__ == "__main__":

    ht =
        SeparateChainingHashTable()

    ht.insert(15)
    ht.insert(25)
    ht.insert(35)
    ht.insert(42)

    ht.display()

    print(
        "\nSearch 35:",
        "Found"
        if ht.search(35)
        else "Not Found"
    )
