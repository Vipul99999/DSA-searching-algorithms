"""
    ExtendibleHashing.py
    Python 3.x

    Features:
    - Global Depth
    - Local Depth
    - Directory
    - Bucket Splitting
    - Directory Doubling
    - Insert
    - Search
    - Delete
    - Display

    Run:
    python ExtendibleHashing.py
"""

from typing import List

BUCKET_SIZE = 4


class Bucket:
    def __init__(self, local_depth: int):
        self.local_depth = local_depth
        self.keys: List[int] = []

    def is_full(self) -> bool:
        return len(self.keys) >= BUCKET_SIZE


class ExtendibleHash:
    def __init__(self):
        self.global_depth = 1

        self.directory: List[Bucket] = [
            Bucket(1),
            Bucket(1)
        ]

    def _hash(self, key: int) -> int:
        return key

    def _get_index(self, key: int) -> int:
        mask = (1 << self.global_depth) - 1
        return self._hash(key) & mask

    def _double_directory(self) -> None:
        old_size = len(self.directory)

        for i in range(old_size):
            self.directory.append(
                self.directory[i]
            )

        self.global_depth += 1

    def _split_bucket(self, bucket_index: int) -> None:

        old_bucket = self.directory[bucket_index]

        if old_bucket.local_depth == self.global_depth:
            self._double_directory()

        new_bucket = Bucket(
            old_bucket.local_depth + 1
        )

        old_bucket.local_depth += 1

        split_bit = (
            1 << (old_bucket.local_depth - 1)
        )

        for i in range(len(self.directory)):

            if self.directory[i] is old_bucket:

                if i & split_bit:
                    self.directory[i] = new_bucket

        old_keys = old_bucket.keys[:]

        old_bucket.keys.clear()

        for key in old_keys:

            index = self._get_index(key)

            self.directory[index].keys.append(
                key
            )

    def insert(self, key: int) -> None:

        while True:

            index = self._get_index(key)

            bucket = self.directory[index]

            if not bucket.is_full():

                bucket.keys.append(key)
                return

            self._split_bucket(index)

    def search(self, key: int) -> bool:

        index = self._get_index(key)

        bucket = self.directory[index]

        return key in bucket.keys

    def delete(self, key: int) -> bool:

        index = self._get_index(key)

        bucket = self.directory[index]

        try:
            bucket.keys.remove(key)
            return True
        except ValueError:
            return False

    def display(self) -> None:

        print(
            f"\nGlobal Depth: "
            f"{self.global_depth}"
        )

        print(
            f"Directory Size: "
            f"{len(self.directory)}\n"
        )

        for i, bucket in enumerate(
            self.directory
        ):

            print(
                f"Dir[{i}] -> "
                f"LD={bucket.local_depth} : ",
                end=""
            )

            for key in bucket.keys:
                print(key, end=" ")

            print()


def main():

    h = ExtendibleHash()

    values = [
        5, 12, 25, 33,
        41, 18, 29, 37,
        49, 52, 61, 73
    ]

    for value in values:
        h.insert(value)

    h.display()

    print(
        "\nSearch 29:",
        "Found"
        if h.search(29)
        else "Not Found"
    )

    print(
        "Search 100:",
        "Found"
        if h.search(100)
        else "Not Found"
    )

    h.delete(29)

    print(
        "\nAfter deleting 29:"
    )

    h.display()


if __name__ == "__main__":
    main()
