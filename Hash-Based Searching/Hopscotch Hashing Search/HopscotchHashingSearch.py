TABLE_SIZE = 16
HOP_RANGE = 4


class Bucket:

    def __init__(self):

        self.key = -1
        self.occupied = False
        self.hop_info = 0


class HopscotchHashingSearch:

    def __init__(self):

        self.table = [
            Bucket()
            for _ in range(TABLE_SIZE)
        ]

    def hash_function(self, key):

        return key % TABLE_SIZE

    def insert(self, key):

        home = self.hash_function(key)

        free_pos = -1

        for i in range(
            home,
            TABLE_SIZE
        ):

            if not self.table[i].occupied:

                free_pos = i
                break

        if free_pos == -1:
            return False

        if (
            free_pos - home
            >= HOP_RANGE
        ):
            return False

        self.table[
            free_pos
        ].key = key

        self.table[
            free_pos
        ].occupied = True

        self.table[
            home
        ].hop_info |= (
            1
            << (free_pos - home)
        )

        return True

    def search(self, key):

        home = self.hash_function(key)

        hop = self.table[
            home
        ].hop_info

        for i in range(HOP_RANGE):

            if hop & (1 << i):

                pos = home + i

                if (
                    pos < TABLE_SIZE
                    and
                    self.table[pos]
                    .occupied
                    and
                    self.table[pos]
                    .key == key
                ):

                    return True

        return False

    def display(self):

        print(
            "\nHopscotch Hash Table"
        )

        for i in range(TABLE_SIZE):

            if (
                self.table[i]
                .occupied
            ):

                value = (
                    self.table[i]
                    .key
                )

            else:

                value = "EMPTY"

            print(
                f"[{i}] = "
                f"{value} "
                f"(hop="
                f"{self.table[i].hop_info})"
            )


if __name__ == "__main__":

    ht =
        HopscotchHashingSearch()

    ht.insert(5)
    ht.insert(21)
    ht.insert(37)
    ht.insert(53)

    ht.display()

    print(
        "\nSearch 37:",
        "Found"
        if ht.search(37)
        else "Not Found"
    )

    print(
        "Search 100:",
        "Found"
        if ht.search(100)
        else "Not Found"
    )
