TABLE_SIZE = 11
EMPTY = -1
MAX_KICKS = 20


class CuckooHash:
    def __init__(self):
        self.table1 = [EMPTY] * TABLE_SIZE
        self.table2 = [EMPTY] * TABLE_SIZE

    def hash1(self, key):
        return key % TABLE_SIZE

    def hash2(self, key):
        return (key // TABLE_SIZE) % TABLE_SIZE

    def search(self, key):
        return (
            self.table1[self.hash1(key)] == key
            or self.table2[self.hash2(key)] == key
        )

    def insert(self, key):
        current = key
        table = 1

        for _ in range(MAX_KICKS):
            if table == 1:
                pos = self.hash1(current)

                if self.table1[pos] == EMPTY:
                    self.table1[pos] = current
                    return True

                self.table1[pos], current = (
                    current,
                    self.table1[pos],
                )
                table = 2

            else:
                pos = self.hash2(current)

                if self.table2[pos] == EMPTY:
                    self.table2[pos] = current
                    return True

                self.table2[pos], current = (
                    current,
                    self.table2[pos],
                )
                table = 1

        return False


if __name__ == "__main__":
    h = CuckooHash()

    h.insert(20)
    h.insert(50)
    h.insert(53)

    print("Found" if h.search(53) else "Not Found")
