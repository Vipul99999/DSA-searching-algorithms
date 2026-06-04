class LinearHash:

    def __init__(
            self):

        self.level = 0
        self.split = 0
        self.N = 4

        self.table = [
            []
            for _
            in range(
                self.N
            )
        ]

    # h(k)=k mod (N×2^L)

    def hash(
            self,
            k):

        return (
            k %
            (
                self.N
                <<
                self.level
            )
        )

    def insert(
            self,
            key):

        idx = self.hash(
            key
        )

        while (
                idx
                >=
                len(
                    self.table
                )
        ):
            self.table.append(
                []
            )

        self.table[
            idx
        ].append(
            key
        )

    def search(
            self,
            key):

        idx = self.hash(
            key
        )

        return (
            key
            in
            self.table[
                idx
            ]
        )


h = LinearHash()

h.insert(
10
)

h.insert(
20
)

print(
h.search(
20
)
)
