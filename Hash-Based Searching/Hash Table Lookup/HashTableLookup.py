TABLE_SIZE = 101
EMPTY = -1


class HashTableLookup:
    def __init__(self):
        self.table = [EMPTY] * TABLE_SIZE

    def hash_function(self, key):
        return key % TABLE_SIZE

    def insert(self, key):
        index = self.hash_function(key)

        if self.table[index] != EMPTY:
            return False

        self.table[index] = key
        return True

    def lookup(self, key):
        return (
            self.table[
                self.hash_function(key)
            ]
            == key
        )


if __name__ == "__main__":
    ht = HashTableLookup()

    ht.insert(15)
    ht.insert(42)
    ht.insert(99)

    print(
        "Found"
        if ht.lookup(42)
        else "Not Found"
    )
