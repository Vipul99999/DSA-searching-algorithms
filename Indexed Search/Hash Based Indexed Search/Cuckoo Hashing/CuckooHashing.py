TABLE_SIZE = 11
EMPTY = None
MAX_KICKS = 20


class CuckooHash:

    def __init__(self):

        self.table1 = [
            EMPTY
        ] * TABLE_SIZE

        self.table2 = [
            EMPTY
        ] * TABLE_SIZE

    def hash1(self, key):
        return key % TABLE_SIZE

    def hash2(self, key):
        return (
            key //
            TABLE_SIZE
        ) % TABLE_SIZE

    def search(self, key):

        return (
            self.table1[
                self.hash1(key)
            ] == key
            or
            self.table2[
                self.hash2(key)
            ] == key
        )

    def insert(self, key):

        current = key
        first = True

        for _ in range(MAX_KICKS):

            if first:

                idx = self.hash1(
                    current
                )

                if (
                    self.table1[idx]
                    is None
                ):
                    self.table1[idx] = current
                    return

                (
                    self.table1[idx],
                    current
                ) = (
                    current,
                    self.table1[idx]
                )

                first = False

            else:

                idx = self.hash2(
                    current
                )

                if (
                    self.table2[idx]
                    is None
                ):
                    self.table2[idx] = current
                    return

                (
                    self.table2[idx],
                    current
                ) = (
                    current,
                    self.table2[idx]
                )

                first = True


h = CuckooHash()

h.insert(20)

print(
    h.search(20)
)
