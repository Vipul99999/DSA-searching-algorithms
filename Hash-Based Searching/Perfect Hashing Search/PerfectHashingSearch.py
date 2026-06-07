class PerfectHashingSearch:

    def __init__(self):

        self.table = [None] * 10

        self.table[0] = 11
        self.table[1] = 22
        self.table[2] = 33
        self.table[3] = 44
        self.table[4] = 55

    def perfect_hash(
        self,
        key
    ):

        mapping = {
            11: 0,
            22: 1,
            33: 2,
            44: 3,
            55: 4
        }

        return mapping.get(
            key,
            -1
        )

    def search(
        self,
        key
    ):

        idx =
            self.perfect_hash(key)

        if idx == -1:
            return False

        return (
            self.table[idx]
            == key
        )


if __name__ == "__main__":

    ht =
        PerfectHashingSearch()

    print(
        "Search 33:",
        "Found"
        if ht.search(33)
        else "Not Found"
    )
