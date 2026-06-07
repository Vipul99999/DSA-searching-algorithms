"""
    LinearHashing.py
    Python 3.x

    Features:
    - Dynamic Bucket Growth
    - Split Pointer (next_split)
    - Level-Based Hashing
    - Bucket Splitting
    - Overflow Buckets
    - Insert
    - Search
    - Display

    Run:
    python LinearHashing.py
"""

INITIAL_BUCKETS = 2
BUCKET_SIZE = 4


class Bucket:
    def __init__(self):
        self.keys = []
        self.overflow = None

    def is_full(self):
        return len(self.keys) >= BUCKET_SIZE


class LinearHashing:

    def __init__(self):

        self.level = 0
        self.next_split = 0

        self.buckets = [
            Bucket()
            for _ in range(INITIAL_BUCKETS)
        ]

    # ---------- Hash Functions ----------

    def hash_level(self, key):

        return (
            key %
            (INITIAL_BUCKETS << self.level)
        )

    def hash_next_level(self, key):

        return (
            key %
            (
                INITIAL_BUCKETS
                << (self.level + 1)
            )
        )

    def bucket_index(self, key):

        idx = self.hash_level(key)

        if idx < self.next_split:
            idx = self.hash_next_level(key)

        return idx

    # ---------- Insert Into Bucket ----------

    def insert_into_bucket(
        self,
        bucket,
        key
    ):

        current = bucket

        while True:

            if not current.is_full():

                current.keys.append(key)
                return

            if current.overflow is None:
                current.overflow = Bucket()

            current = current.overflow

    # ---------- Split Bucket ----------

    def split_bucket(self):

        split_index = self.next_split

        self.buckets.append(Bucket())

        values = []

        current = self.buckets[split_index]

        while current:

            values.extend(current.keys)

            current = current.overflow

        self.buckets[split_index] = Bucket()

        for value in values:

            idx = self.hash_next_level(
                value
            )

            self.insert_into_bucket(
                self.buckets[idx],
                value
            )

        self.next_split += 1

        round_size = (
            INITIAL_BUCKETS
            << self.level
        )

        if self.next_split == round_size:

            self.next_split = 0
            self.level += 1

    # ---------- Insert ----------

    def insert(self, key):

        idx = self.bucket_index(key)

        self.insert_into_bucket(
            self.buckets[idx],
            key
        )

        self.split_bucket()

    # ---------- Search ----------

    def search(self, key):

        idx = self.bucket_index(key)

        current = self.buckets[idx]

        while current:

            if key in current.keys:
                return True

            current = current.overflow

        return False

    # ---------- Display ----------

    def display(self):

        print(
            f"\nLevel: {self.level}"
        )

        print(
            f"Next Split: "
            f"{self.next_split}"
        )

        print(
            f"Bucket Count: "
            f"{len(self.buckets)}\n"
        )

        for i, bucket in enumerate(
            self.buckets
        ):

            print(
                f"Bucket[{i}] : ",
                end=""
            )

            current = bucket

            while current:

                for value in current.keys:
                    print(
                        value,
                        end=" "
                    )

                if current.overflow:
                    print(
                        "-> ",
                        end=""
                    )

                current = current.overflow

            print()


# ---------- Driver ----------

if __name__ == "__main__":

    hash_table = LinearHashing()

    values = [
        5, 12, 25, 33,
        41, 18, 29, 37,
        49, 52, 61, 73
    ]

    for value in values:
        hash_table.insert(value)

    hash_table.display()

    print(
        "\nSearch 29:",
        "Found"
        if hash_table.search(29)
        else "Not Found"
    )

    print(
        "Search 100:",
        "Found"
        if hash_table.search(100)
        else "Not Found"
    )
