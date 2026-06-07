TABLE_SIZE = 13
EMPTY = -1


class DoubleHashing:

    def __init__(self):
        self.table = (
            [EMPTY] * TABLE_SIZE
        )

    def hash1(self, key):
        return key % TABLE_SIZE

    def hash2(self, key):
        return 7 - (key % 7)

    def insert(self, key):

        h1 = self.hash1(key)
        h2 = self.hash2(key)

        for i in range(TABLE_SIZE):

            pos = (
                h1 + i * h2
            ) % TABLE_SIZE

            if self.table[pos] == EMPTY:

                self.table[pos] = key

                return True

        return False

    def search(self, key):

        h1 = self.hash1(key)
        h2 = self.hash2(key)

        for i in range(TABLE_SIZE):

            pos = (
                h1 + i * h2
            ) % TABLE_SIZE

            if self.table[pos] == EMPTY:
                return False

            if self.table[pos] == key:
                return True

        return False

    def display(self):

        print("\nHash Table")

        for i in range(TABLE_SIZE):

            if self.table[i] == EMPTY:
                print(
                    f"[{i}] = EMPTY"
                )
            else:
                print(
                    f"[{i}] = "
                    f"{self.table[i]}"
                )


if __name__ == "__main__":

    ht = DoubleHashing()

    ht.insert(25)
    ht.insert(38)
    ht.insert(51)
    ht.insert(64)

    ht.display()

    print(
        "\nSearch 51:",
        "Found"
        if ht.search(51)
        else "Not Found"
    )
