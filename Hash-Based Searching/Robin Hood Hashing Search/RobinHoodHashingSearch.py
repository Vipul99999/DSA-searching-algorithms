TABLE_SIZE = 11
EMPTY = -1


class RobinHoodHashing:

    def __init__(self):
        self.table = [EMPTY] * TABLE_SIZE

    def hash_function(self, key):
        return key % TABLE_SIZE

    def probe_distance(self, key, pos):
        home = self.hash_function(key)

        return (
            pos - home + TABLE_SIZE
        ) % TABLE_SIZE

    def insert(self, key):

        current = key

        pos = self.hash_function(current)

        while True:

            if self.table[pos] == EMPTY:

                self.table[pos] = current

                return True

            resident = self.table[pos]

            current_dist = (
                self.probe_distance(
                    current,
                    pos
                )
            )

            resident_dist = (
                self.probe_distance(
                    resident,
                    pos
                )
            )

            if (
                current_dist >
                resident_dist
            ):

                (
                    self.table[pos],
                    current
                ) = (
                    current,
                    self.table[pos]
                )

            pos = (
                pos + 1
            ) % TABLE_SIZE

    def search(self, key):

        pos = self.hash_function(key)

        dist = 0

        while (
            self.table[pos]
            != EMPTY
        ):

            if (
                self.table[pos]
                == key
            ):
                return True

            resident_dist = (
                self.probe_distance(
                    self.table[pos],
                    pos
                )
            )

            if (
                resident_dist <
                dist
            ):
                return False

            pos = (
                pos + 1
            ) % TABLE_SIZE

            dist += 1

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

    ht = RobinHoodHashing()

    ht.insert(22)
    ht.insert(33)
    ht.insert(44)
    ht.insert(55)
    ht.insert(66)

    ht.display()

    print(
        "\nSearch 44:",
        "Found"
        if ht.search(44)
        else "Not Found"
    )

    print(
        "Search 100:",
        "Found"
        if ht.search(100)
        else "Not Found"
    )
