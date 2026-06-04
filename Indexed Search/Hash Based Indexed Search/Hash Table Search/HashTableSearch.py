class HashTable:

    TABLE_SIZE = 10

    def __init__(self):

        self.table = [
            []
            for _ in range(
                self.TABLE_SIZE
            )
        ]

    # h(key)=key%TABLE_SIZE
    def hash(self, key):

        return (
            key %
            self.TABLE_SIZE
        )

    def insert(self, key):

        index = self.hash(key)

        self.table[index].append(key)

    def search(self, key):

        index = self.hash(key)

        return (
            key
            in
            self.table[index]
        )

    def delete(self, key):

        index = self.hash(key)

        if (
            key
            in
            self.table[index]
        ):
            self.table[index].remove(key)

    def display(self):

        for (
            index,
            bucket
        ) in enumerate(
            self.table
        ):

            print(
                f"[{index}] "
                +
                " -> ".join(
                    map(
                        str,
                        bucket
                    )
                )
            )


ht = HashTable()

ht.insert(10)
ht.insert(20)
ht.insert(35)

ht.display()

print(
    "\nSearch:",
    ht.search(20)
)

ht.delete(20)

ht.display()
