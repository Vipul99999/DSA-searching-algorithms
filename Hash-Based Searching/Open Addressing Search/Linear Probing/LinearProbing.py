TABLE_SIZE = 11
EMPTY = -1


class LinearProbingHashTable:

    def __init__(self):
        self.table = [EMPTY] * TABLE_SIZE

    def hash_function(self, key):
        return key % TABLE_SIZE

    def insert(self, key):

        index = self.hash_function(key)

        for i in range(TABLE_SIZE):

            pos = (index + i) % TABLE_SIZE

            if self.table[pos] == EMPTY:
                self.table[pos] = key
                return True

        return False

    def search(self, key):

        index = self.hash_function(key)

        for i in range(TABLE_SIZE):

            pos = (index + i) % TABLE_SIZE

            if self.table[pos] == EMPTY:
                return False

            if self.table[pos] == key:
                return True

        return False

    def display(self):

        print("\nHash Table")

        for i in range(TABLE_SIZE):

            if self.table[i] == EMPTY:
                print(f"[{i}] = EMPTY")
            else:
                print(
                    f"[{i}] = {self.table[i]}"
                )


if __name__ == "__main__":

    ht = LinearProbingHashTable()

    ht.insert(22)
    ht.insert(33)
    ht.insert(44)
    ht.insert(55)

    ht.display()

    print(
        "\nSearch 44:",
        "Found"
        if ht.search(44)
        else "Not Found"
    )
