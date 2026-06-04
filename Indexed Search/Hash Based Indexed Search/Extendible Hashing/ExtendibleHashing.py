class Bucket:
    """
    Bucket used in Extendible Hashing

    local_depth:
    Number of directory bits
    this bucket recognizes
    """

    def __init__(self, local_depth, capacity):

        self.local_depth = local_depth
        self.capacity = capacity
        self.keys = []

    def is_full(self):
        return len(self.keys) >= self.capacity

    def contains(self, key):
        return key in self.keys

    def insert(self, key):
        self.keys.append(key)

    def delete(self, key):

        if key in self.keys:
            self.keys.remove(key)


class DynamicHashing:
    """
    Dynamic Hashing
    (Extendible Hashing)
    """

    BUCKET_SIZE = 3

    def __init__(self):

        self.global_depth = 1

        self.directory = [
            Bucket(1, self.BUCKET_SIZE),
            Bucket(1, self.BUCKET_SIZE)
        ]

    """
    Hash Formula

    index =
    key &
    ((1 << global_depth)-1)
    """

    def get_index(self, key):

        return (
            key
            &
            (
                (1 << self.global_depth)
                - 1
            )
        )

    """
    Double directory
    """

    def expand_directory(self):

        old_size = len(self.directory)

        for i in range(old_size):

            self.directory.append(
                self.directory[i]
            )

        self.global_depth += 1

    """
    Split bucket
    """

    def split_bucket(self, index):

        old_bucket = self.directory[index]

        if (
            old_bucket.local_depth
            ==
            self.global_depth
        ):

            self.expand_directory()

        new_bucket = Bucket(
            old_bucket.local_depth + 1,
            self.BUCKET_SIZE
        )

        old_bucket.local_depth += 1

        split_bit = (
            1
            <<
            (
                old_bucket.local_depth
                - 1
            )
        )

        for i in range(
            len(self.directory)
        ):

            if (
                self.directory[i]
                is old_bucket
                and
                (
                    i & split_bit
                )
            ):

                self.directory[i] = new_bucket

        old_values = list(
            old_bucket.keys
        )

        old_bucket.keys.clear()

        for value in old_values:

            new_index = (
                self.get_index(
                    value
                )
            )

            self.directory[
                new_index
            ].insert(
                value
            )

    """
    Insert key
    """

    def insert(self, key):

        while True:

            index = (
                self.get_index(
                    key
                )
            )

            bucket = (
                self.directory[
                    index
                ]
            )

            if (
                bucket.contains(
                    key
                )
            ):

                return

            if (
                not
                bucket.is_full()
            ):

                bucket.insert(
                    key
                )

                return

            self.split_bucket(
                index
            )

    """
    Search key
    """

    def search(self, key):

        index = (
            self.get_index(
                key
            )
        )

        return (
            self.directory[
                index
            ]
            .contains(
                key
            )
        )

    """
    Delete key
    """

    def delete(self, key):

        index = (
            self.get_index(
                key
            )
        )

        self.directory[
            index
        ].delete(
            key
        )

    """
    Display table
    """

    def display(self):

        print(
            "\nGlobal Depth:",
            self.global_depth
        )

        print()

        for i, bucket in enumerate(
            self.directory
        ):

            print(
                f"Dir[{i}] ->",
                bucket.keys
            )


# ------------------------
# Driver
# ------------------------

if __name__ == "__main__":

    table = DynamicHashing()

    values = [
        10,
        22,
        14,
        30,
        42,
        54,
        66
    ]

    for value in values:
        table.insert(
            value
        )

    table.display()

    print(
        "\nSearch 42:",
        table.search(
            42
        )
    )

    table.delete(
        42
    )

    print(
        "\nAfter Delete:"
    )

    table.display()
